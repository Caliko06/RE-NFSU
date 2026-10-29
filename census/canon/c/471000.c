// ==== 0x471d60 FUN_00471d60

undefined4 __fastcall FUN_00471d60(float *param_1,float *param_2)

{
  if (((ABS(*param_2 - *param_1) <= 0.001) && (ABS(param_2[1] - param_1[1]) <= 0.001)) &&
     (ABS(param_2[2] - param_1[2]) <= 0.001)) {
    return 1;
  }
  return 0;
}


// ==== 0x471db0 FUN_00471db0

undefined4 * __thiscall FUN_00471db0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c84d4;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x471dd0 FUN_00471dd0

void __fastcall FUN_00471dd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c84d4;
  return;
}


// ==== 0x471de0 FUN_00471de0

float10 FUN_00471de0(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  float10 fVar6;
  undefined4 *local_198;
  undefined4 *local_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  float local_180;
  undefined1 auStack_17c [8];
  short sStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 auStack_168 [4];
  float fStack_158;
  float fStack_154;
  float local_150 [3];
  short sStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_f8;
  
  Struct_ClearHeader();
  Struct_ClearHeader();
  if (*(int *)(unaff_EDI + 0x138) == 0) {
    iVar3 = (**(code **)(*(int *)(unaff_EDI + 0x244) + 0xc))
                      (*(int *)(unaff_EDI + 0x244),0,local_150);
    D3DXVec3Transform(&uStack_140,iVar3 + 0x10,unaff_EDI + 0x140);
    iVar3 = (**(code **)(*(int *)(unaff_EDI + 0x248) + 0xc))
                      (*(int *)(unaff_EDI + 0x248),0,&fStack_18c);
    D3DXVec3Transform(auStack_17c,iVar3 + 0x10,unaff_EDI + 0x1c0);
    fStack_128 = fStack_188 - fStack_158;
    fStack_124 = fStack_184 - fStack_154;
    fStack_120 = local_180 - local_150[0];
    fStack_138 = -fStack_128;
    fStack_134 = -fStack_124;
    fStack_130 = -fStack_120;
    fStack_110 = fStack_130;
    (**(code **)(*(int *)(unaff_EDI + 0x244) + 8))
              (*(int *)(unaff_EDI + 0x244),&fStack_128,auStack_168,&fStack_188,unaff_EDI + 0x140,
               unaff_EDI + 0x180,auStack_168);
    (**(code **)(*(int *)(unaff_EDI + 0x248) + 8))
              (*(int *)(unaff_EDI + 0x248),&fStack_138,&local_198,&fStack_158,unaff_EDI + 0x1c0,
               unaff_EDI + 0x200,&local_198);
    *(undefined4 *)(unaff_EDI + 0x60) = uStack_140;
    *(float *)(unaff_EDI + 0x68) = fStack_138;
    *(undefined4 *)(unaff_EDI + 100) = uStack_13c;
    *(undefined4 *)(unaff_EDI + 0xa0) = uStack_170;
    *(undefined4 *)(unaff_EDI + 0xa8) = auStack_168[0];
    *(undefined4 *)(unaff_EDI + 0xa4) = uStack_16c;
    *(int *)(unaff_EDI + 0x110) = (int)sStack_144;
    *(int *)(unaff_EDI + 0x124) = (int)sStack_174;
    *(undefined4 *)(unaff_EDI + 0x134) = 1;
    *(undefined4 *)(unaff_EDI + 0x120) = 1;
    *(undefined4 *)(unaff_EDI + 0xe0) = *(undefined4 *)(unaff_EDI + 0x60);
    *(undefined4 *)(unaff_EDI + 0xe4) = *(undefined4 *)(unaff_EDI + 100);
    *(undefined4 *)(unaff_EDI + 0xe8) = *(undefined4 *)(unaff_EDI + 0x68);
    *(undefined4 *)(unaff_EDI + 0xf0) = *(undefined4 *)(unaff_EDI + 0xa0);
    *(undefined4 *)(unaff_EDI + 0xf4) = *(undefined4 *)(unaff_EDI + 0xa4);
    *(undefined4 *)(unaff_EDI + 0xf8) = *(undefined4 *)(unaff_EDI + 0xa8);
    fStack_190 = *(float *)(unaff_EDI + 0xf0) - *(float *)(unaff_EDI + 0xe0);
    fStack_18c = *(float *)(unaff_EDI + 0xf4) - *(float *)(unaff_EDI + 0xe4);
    fStack_188 = *(float *)(unaff_EDI + 0xf8) - *(float *)(unaff_EDI + 0xe8);
    local_198 = (undefined4 *)
                (fStack_190 * fStack_190 + fStack_18c * fStack_18c + fStack_188 * fStack_188);
    if ((float)local_198 < 0.001 == ((float)local_198 == 0.001)) {
      *(undefined4 *)(unaff_EDI + 0x138) = 1;
      fStack_f8 = fStack_188;
LAB_00472175:
      local_194 = local_198;
      SCEA_GJKsimplexPair__SCEA_GJKsimplexPair_copy_();
      do {
        fStack_120 = -fStack_190;
        fStack_11c = -fStack_18c;
        fStack_118 = -fStack_188;
        fStack_f8 = fStack_118;
        (**(code **)(*(int *)(unaff_EDI + 0x244) + 8))
                  (*(int *)(unaff_EDI + 0x244),&fStack_190,local_150,&uStack_170,unaff_EDI + 0x140,
                   unaff_EDI + 0x180,local_150);
        (**(code **)(*(int *)(unaff_EDI + 0x248) + 8))
                  (*(int *)(unaff_EDI + 0x248),&fStack_120,&local_180,&uStack_140,unaff_EDI + 0x1c0,
                   unaff_EDI + 0x200,&local_180);
        iVar3 = 0;
        if (0 < *(int *)(unaff_EDI + 0x120)) {
          do {
            if (*(int *)(unaff_EDI + 0x110 + iVar3 * 4) == (int)sStack_144) {
              bVar2 = false;
              goto LAB_00472295;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(unaff_EDI + 0x120));
        }
        *(int *)(unaff_EDI + 0x110 + *(int *)(unaff_EDI + 0x120) * 4) = (int)sStack_144;
        puVar4 = (undefined4 *)((*(int *)(unaff_EDI + 0x120) + 6) * 0x10 + unaff_EDI);
        puVar4[1] = uStack_13c;
        *puVar4 = uStack_140;
        bVar2 = true;
        puVar4[2] = fStack_138;
        *(int *)(unaff_EDI + 0x120) = *(int *)(unaff_EDI + 0x120) + 1;
LAB_00472295:
        iVar3 = 0;
        if (0 < *(int *)(unaff_EDI + 0x134)) {
          do {
            if (*(int *)(unaff_EDI + 0x124 + iVar3 * 4) == (int)sStack_174) {
              bVar1 = false;
              goto LAB_00472303;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(unaff_EDI + 0x134));
        }
        *(int *)(unaff_EDI + 0x124 + *(int *)(unaff_EDI + 0x134) * 4) = (int)sStack_174;
        puVar4 = (undefined4 *)((*(int *)(unaff_EDI + 0x134) + 10) * 0x10 + unaff_EDI);
        puVar4[1] = uStack_16c;
        *puVar4 = uStack_170;
        puVar4[2] = auStack_168[0];
        *(int *)(unaff_EDI + 0x134) = *(int *)(unaff_EDI + 0x134) + 1;
        bVar1 = true;
LAB_00472303:
        if (!bVar1 && !bVar2) goto LAB_00472378;
        fVar6 = (float10)SCEA_GJKsimplexPair__DistanceSqr();
        local_198 = (undefined4 *)(float)fVar6;
        if (fVar6 == (float10)0.0) break;
        if ((float)local_194 <= (float)local_198) {
          local_198 = local_194;
          SCEA_GJKsimplexPair__operator_();
LAB_00472378:
          bNormalize3();
          return SQRT((float10)(float)local_198);
        }
        local_194 = local_198;
        SCEA_GJKsimplexPair__operator_();
      } while( true );
    }
  }
  else {
    iVar3 = 0;
    if (0 < *(int *)(unaff_EDI + 0x120)) {
      local_198 = (undefined4 *)(unaff_EDI + 0x110);
      puVar4 = (undefined4 *)(unaff_EDI + 0x60);
      do {
        (**(code **)(*(int *)(unaff_EDI + 0x244) + 0xc))
                  (*(int *)(unaff_EDI + 0x244),*local_198,local_150);
        if (*(int *)(*(int *)(unaff_EDI + 0x244) + 0x10) == 2) {
          *puVar4 = uStack_140;
          puVar4[1] = uStack_13c;
          puVar4[2] = fStack_138;
        }
        else {
          D3DXVec3Transform(puVar4,&uStack_140,unaff_EDI + 0x140);
        }
        iVar3 = iVar3 + 1;
        local_198 = local_198 + 1;
        puVar4 = puVar4 + 4;
      } while (iVar3 < *(int *)(unaff_EDI + 0x120));
    }
    local_194 = (undefined4 *)0x0;
    if (0 < *(int *)(unaff_EDI + 0x134)) {
      puVar4 = (undefined4 *)(unaff_EDI + 0xa0);
      puVar5 = (undefined4 *)(unaff_EDI + 0x124);
      do {
        (**(code **)(*(int *)(unaff_EDI + 0x248) + 0xc))
                  (*(int *)(unaff_EDI + 0x248),*puVar5,&local_180);
        if (*(int *)(*(int *)(unaff_EDI + 0x248) + 0x10) == 2) {
          *puVar4 = uStack_170;
          puVar4[1] = uStack_16c;
          puVar4[2] = auStack_168[0];
        }
        else {
          D3DXVec3Transform(puVar4,&uStack_170,unaff_EDI + 0x1c0);
        }
        local_194 = (undefined4 *)((int)local_194 + 1);
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 4;
      } while ((int)local_194 < *(int *)(unaff_EDI + 0x134));
    }
    fVar6 = (float10)SCEA_GJKsimplexPair__DistanceSqr();
    local_198 = (undefined4 *)(float)fVar6;
    if (fVar6 < (float10)0.001 == (fVar6 == (float10)0.001)) goto LAB_00472175;
  }
  return (float10)0.0;
}


// ==== 0x4723a0 SCEA_GJKsimplexPair::SCEA_GJKsimplexPair_copy_

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall SCEA_GJKsimplexPair__SCEA_GJKsimplexPair_copy_(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 4;
  puVar3 = (undefined4 *)(param_2 + 8);
  puVar5 = in_EAX;
  do {
    uVar1 = puVar3[-1];
    uVar2 = *puVar3;
    iVar4 = iVar4 + -1;
    *puVar5 = puVar3[-2];
    puVar5[1] = uVar1;
    *(undefined4 *)(((int)in_EAX - param_2) + -0x10 + (int)(puVar3 + 4)) = uVar2;
    puVar3 = puVar3 + 4;
    puVar5 = puVar5 + 4;
  } while (iVar4 != 0);
  iVar4 = 4;
  puVar3 = (undefined4 *)((int)(in_EAX + 0x10) + param_2 + (8 - (int)in_EAX));
  puVar5 = in_EAX + 0x10;
  do {
    uVar1 = puVar3[-1];
    uVar2 = *puVar3;
    iVar4 = iVar4 + -1;
    *puVar5 = puVar3[-2];
    puVar5[1] = uVar1;
    *(undefined4 *)((int)puVar3 + ((int)in_EAX - param_2)) = uVar2;
    puVar3 = puVar3 + 4;
    puVar5 = puVar5 + 4;
  } while (iVar4 != 0);
  uVar1 = *(undefined4 *)(param_2 + 0x84);
  uVar2 = *(undefined4 *)(param_2 + 0x88);
  in_EAX[0x20] = *(undefined4 *)(param_2 + 0x80);
  in_EAX[0x21] = uVar1;
  in_EAX[0x22] = uVar2;
  uVar1 = *(undefined4 *)(param_2 + 0x94);
  uVar2 = *(undefined4 *)(param_2 + 0x98);
  in_EAX[0x24] = *(undefined4 *)(param_2 + 0x90);
  in_EAX[0x25] = uVar1;
  in_EAX[0x26] = uVar2;
  uVar1 = *(undefined4 *)(param_2 + 0xa4);
  uVar2 = *(undefined4 *)(param_2 + 0xa8);
  in_EAX[0x28] = *(undefined4 *)(param_2 + 0xa0);
  in_EAX[0x29] = uVar1;
  in_EAX[0x2a] = uVar2;
  puVar3 = (undefined4 *)(param_2 + 0xb0);
  puVar5 = in_EAX + 0x2c;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar3 = (undefined4 *)(param_2 + 0xc4);
  puVar5 = in_EAX + 0x31;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  in_EAX[0x36] = *(undefined4 *)(param_2 + 0xd8);
  return;
}


// ==== 0x4724b0 SCEA_GJKsimplexPair::operator_

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall SCEA_GJKsimplexPair__operator_(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *in_EAX = *param_2;
  in_EAX[1] = uVar1;
  in_EAX[2] = uVar2;
  uVar1 = param_2[5];
  uVar2 = param_2[6];
  in_EAX[4] = param_2[4];
  in_EAX[5] = uVar1;
  in_EAX[6] = uVar2;
  uVar1 = param_2[9];
  uVar2 = param_2[10];
  in_EAX[8] = param_2[8];
  in_EAX[9] = uVar1;
  in_EAX[10] = uVar2;
  uVar1 = param_2[0xd];
  uVar2 = param_2[0xe];
  in_EAX[0xc] = param_2[0xc];
  in_EAX[0xd] = uVar1;
  in_EAX[0xe] = uVar2;
  uVar1 = param_2[0x11];
  uVar2 = param_2[0x12];
  in_EAX[0x10] = param_2[0x10];
  in_EAX[0x11] = uVar1;
  in_EAX[0x12] = uVar2;
  uVar1 = param_2[0x15];
  uVar2 = param_2[0x16];
  in_EAX[0x14] = param_2[0x14];
  in_EAX[0x15] = uVar1;
  in_EAX[0x16] = uVar2;
  uVar1 = param_2[0x19];
  uVar2 = param_2[0x1a];
  in_EAX[0x18] = param_2[0x18];
  in_EAX[0x19] = uVar1;
  in_EAX[0x1a] = uVar2;
  uVar1 = param_2[0x1d];
  uVar2 = param_2[0x1e];
  in_EAX[0x1c] = param_2[0x1c];
  in_EAX[0x1d] = uVar1;
  in_EAX[0x1e] = uVar2;
  uVar1 = param_2[0x21];
  uVar2 = param_2[0x22];
  in_EAX[0x20] = param_2[0x20];
  in_EAX[0x21] = uVar1;
  in_EAX[0x22] = uVar2;
  uVar1 = param_2[0x25];
  uVar2 = param_2[0x26];
  in_EAX[0x24] = param_2[0x24];
  in_EAX[0x25] = uVar1;
  in_EAX[0x26] = uVar2;
  uVar1 = param_2[0x29];
  uVar2 = param_2[0x2a];
  in_EAX[0x28] = param_2[0x28];
  in_EAX[0x29] = uVar1;
  in_EAX[0x2a] = uVar2;
  puVar4 = param_2 + 0x2c;
  puVar5 = in_EAX + 0x2c;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = param_2 + 0x31;
  puVar5 = in_EAX + 0x31;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  in_EAX[0x36] = param_2[0x36];
  return;
}


// ==== 0x472600 FUN_00472600

void FUN_00472600(void)

{
  int in_EAX;
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int local_4;
  
  FUN_00571ea0(unaff_ESI,"GJKWitness");
  FUN_00571c20(in_EAX,unaff_ESI + 0x10,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x14,1,1,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x15,1,1,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x20,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x30,0xc,0xffffffff,0);
  iVar3 = unaff_ESI + 0x124;
  iVar2 = unaff_ESI + 0xa0;
  local_4 = 4;
  do {
    FUN_00571c20(in_EAX,iVar2 + -0x40,0xc,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar2,0xc,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3 + -0x14,4,4,1);
    FUN_00571c20(in_EAX,iVar3,4,4,1);
    iVar2 = iVar2 + 0x10;
    iVar3 = iVar3 + 4;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x100,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0xe0,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0xf0,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x138,4,4,1);
  FUN_00571c20(in_EAX,unaff_ESI + 0x120,4,4,1);
  FUN_00571c20(in_EAX,unaff_ESI + 0x134,4,4,1);
  FUN_00571c20(in_EAX,unaff_ESI + 0x40,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x50,0xc,0xffffffff,0);
  FUN_00571d90();
  FUN_00571d90();
  FUN_00571d90();
  FUN_00571d90();
  iVar3 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar3 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar3 + 0x58 + in_EAX);
  cVar1 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4727c0 GJKWitness::Initialize

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GJKWitness__Initialize(int param_1,int param_2)

{
  float fVar1;
  int in_EAX;
  
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)(param_1 + 0x240) = 1;
  *(int *)(param_1 + 0x244) = in_EAX;
  *(int *)(param_1 + 0x248) = param_2;
  if (*(int *)(in_EAX + 0x10) == 2) {
    if (*(char *)(in_EAX + 0x1d0) == '\0') goto LAB_00472822;
    fVar1 = *(float *)(in_EAX + 0x1d4);
  }
  else {
    if (*(int *)(param_2 + 0x10) != 2) {
      return;
    }
    if (*(char *)(param_2 + 0x1d0) == '\0') goto LAB_00472822;
    fVar1 = *(float *)(param_2 + 0x1d4);
  }
  if (0.0 < fVar1) {
    *(undefined1 *)(param_1 + 0x241) = 1;
    return;
  }
LAB_00472822:
  *(undefined1 *)(param_1 + 0x241) = 0;
  return;
}


// ==== 0x472830 FUN_00472830

void FUN_00472830(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_ESI;
  float *unaff_EDI;
  
  if (((ABS(*unaff_EDI - *(float *)(unaff_ESI + 0x40)) <= 0.001) &&
      (ABS(unaff_EDI[1] - *(float *)(unaff_ESI + 0x44)) <= 0.001)) &&
     (ABS(unaff_EDI[2] - *(float *)(unaff_ESI + 0x48)) <= 0.001)) {
    iVar5 = FUN_00471d60();
    if (iVar5 != 0) goto LAB_0047288d;
  }
  *(undefined1 *)(unaff_ESI + 0x240) = 1;
LAB_0047288d:
  if (*(char *)(unaff_ESI + 0x240) != '\0') {
    bMatrixCopy_b();
    bMatrixCopy();
    fVar1 = unaff_EDI[1];
    fVar2 = unaff_EDI[2];
    *(float *)(unaff_ESI + 0x170) = *unaff_EDI;
    *(float *)(unaff_ESI + 0x174) = fVar1;
    *(float *)(unaff_ESI + 0x178) = fVar2;
    *(undefined4 *)(unaff_ESI + 0x17c) = 0x3f800000;
    bMatrixCopy_b();
    bMatrixCopy();
    uVar3 = param_3[1];
    uVar4 = param_3[2];
    *(undefined4 *)(unaff_ESI + 0x1f0) = *param_3;
    *(undefined4 *)(unaff_ESI + 500) = uVar3;
    *(undefined4 *)(unaff_ESI + 0x1f8) = uVar4;
    *(undefined4 *)(unaff_ESI + 0x1fc) = 0x3f800000;
    fVar1 = unaff_EDI[1];
    fVar2 = unaff_EDI[2];
    *(float *)(unaff_ESI + 0x40) = *unaff_EDI;
    *(float *)(unaff_ESI + 0x44) = fVar1;
    *(float *)(unaff_ESI + 0x48) = fVar2;
    uVar3 = param_3[1];
    uVar4 = param_3[2];
    *(undefined4 *)(unaff_ESI + 0x50) = *param_3;
    *(undefined4 *)(unaff_ESI + 0x54) = uVar3;
    *(undefined4 *)(unaff_ESI + 0x58) = uVar4;
  }
  return;
}


// ==== 0x472950 FUN_00472950

float10 FUN_00472950(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int in_EAX;
  float10 fVar4;
  
  if (*(char *)(in_EAX + 0x240) == '\0') goto LAB_00472a7e;
  iVar1 = *(int *)(in_EAX + 0x244);
  if (*(int *)(iVar1 + 0x10) == 2) {
    if ((*(char *)(iVar1 + 0x1d0) == '\0') || (*(float *)(iVar1 + 0x1d4) <= 0.0)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if (cVar2 == *(char *)(in_EAX + 0x241)) goto LAB_004729a1;
LAB_004729da:
    uVar3 = CarState__IsTimedFlagActive();
    *(undefined1 *)(in_EAX + 0x241) = uVar3;
    *(undefined4 *)(in_EAX + 0x138) = 0;
  }
  else {
LAB_004729a1:
    iVar1 = *(int *)(in_EAX + 0x248);
    if (*(int *)(iVar1 + 0x10) == 2) {
      if ((*(char *)(iVar1 + 0x1d0) == '\0') || (*(float *)(iVar1 + 0x1d4) <= 0.0)) {
        cVar2 = '\0';
      }
      else {
        cVar2 = '\x01';
      }
      if (cVar2 != *(char *)(in_EAX + 0x241)) goto LAB_004729da;
    }
  }
  fVar4 = (float10)FUN_00471de0();
  *(float *)(in_EAX + 0x10) = (float)fVar4;
  *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_EAX + 0xe0);
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(in_EAX + 0xe4);
  *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(in_EAX + 0xe8);
  *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(in_EAX + 0xf0);
  *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(in_EAX + 0xf4);
  *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_EAX + 0xf8);
  *(bool *)(in_EAX + 0x15) =
       *(float *)(in_EAX + 0x10) < 0.0001 != (*(float *)(in_EAX + 0x10) == 0.0001);
  if (*(float *)(in_EAX + 0x10) < 0.005 != (*(float *)(in_EAX + 0x10) == 0.005)) {
    *(undefined1 *)(in_EAX + 0x14) = 1;
    *(undefined1 *)(in_EAX + 0x240) = 0;
    return (float10)*(float *)(in_EAX + 0x10);
  }
  *(undefined1 *)(in_EAX + 0x14) = 0;
  *(undefined1 *)(in_EAX + 0x240) = 0;
LAB_00472a7e:
  return (float10)*(float *)(in_EAX + 0x10);
}


// ==== 0x472a90 FUN_00472a90

void FUN_00472a90(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  return;
}


// ==== 0x472aa0 FUN_00472aa0

void __fastcall FUN_00472aa0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  
  fVar1 = *(float *)(in_EAX + 0x24);
  fVar2 = *(float *)(in_EAX + 0x34);
  fVar3 = *(float *)(in_EAX + 0x28);
  fVar4 = *(float *)(in_EAX + 0x38);
  *param_2 = *(float *)(in_EAX + 0x20) - *(float *)(in_EAX + 0x30);
  param_2[2] = fVar3 - fVar4;
  param_2[1] = fVar1 - fVar2;
  fVar1 = *(float *)(in_EAX + 0x34);
  fVar2 = *(float *)(in_EAX + 0x24);
  fVar3 = *(float *)(in_EAX + 0x38);
  fVar4 = *(float *)(in_EAX + 0x28);
  *param_1 = *(float *)(in_EAX + 0x30) + *(float *)(in_EAX + 0x20);
  param_1[2] = fVar3 + fVar4;
  param_1[1] = fVar1 + fVar2;
  return;
}


// ==== 0x472b00 CarShape_Load

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export block; live
   Ghidra decompile + capstone) docs/re/assets.md */

undefined4 CarShape_Load(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  if (*param_1 != -0x7ffcbfe0) {
    return 0;
  }
  iVar4 = param_1[1];
  piVar3 = param_1 + 2;
  puVar9 = DAT_00779bdc;
  while (piVar3 < (int *)(iVar4 + 8 + (int)param_1)) {
    if ((*piVar3 != 0x34021) && (*piVar3 == 0x39200)) {
      iVar5 = piVar3[1];
      iVar6 = *(int *)((int)piVar3 + iVar5 + 0xc);
      iVar8 = iVar6 + 8 + iVar5 + 8;
      uVar1 = (int)piVar3 + iVar5 + 0x1f;
      iVar7 = *(int *)((int)piVar3 + iVar8 + 4);
      uVar2 = (int)piVar3 + iVar8 + 0x17;
      puVar10 = (undefined4 *)((int)piVar3 + 0x17U & 0xfffffff0);
      *puVar9 = puVar10;
      DAT_00779bdc = puVar10;
      *(short *)(puVar10 + 0xf) =
           (short)((int)piVar3 + iVar7 + (iVar8 - (uVar2 & 0xfffffff0)) + 8 >> 1);
      puVar10[5] = (int)(short)(((int)piVar3 + (iVar6 - (uVar1 & 0xfffffff0)) + 8 + iVar5 + 8) /
                               0x30);
      puVar10[1] = puVar9;
      *puVar10 = &DAT_00779bd8;
      puVar10[0x15] = uVar1 & 0xfffffff0;
      puVar10[0x14] = uVar2 & 0xfffffff0;
      puVar10[2] = FUN_00472f30;
      puVar10[3] = FUN_00472ee0;
      puVar10[4] = 1;
      piVar3 = (int *)((int)piVar3 + *(int *)((int)piVar3 + iVar8 + 4) + iVar8 + 8);
      puVar9 = DAT_00779bdc;
    }
  }
  DAT_00779bdc = puVar9;
  return 1;
}


// ==== 0x472c00 CarShape_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 CarShape_Unload(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_1 == -0x7ffcbfe0) {
    iVar2 = param_1[1];
    for (piVar1 = param_1 + 2; piVar1 < (int *)(iVar2 + 8 + (int)param_1);
        piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
      if ((*piVar1 != 0x34021) && (*piVar1 == 0x39200)) {
        piVar4 = (int *)((int)piVar1 + 0x17U & 0xfffffff0);
        iVar3 = *piVar4;
        piVar4 = (int *)piVar4[1];
        *piVar4 = iVar3;
        *(int **)(iVar3 + 4) = piVar4;
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x472c60 CarShape_Find

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 * CarShape_Find(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = DAT_00779bd8;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return (undefined4 *)0x0;
    }
    if (puVar1[6] == unaff_EDI) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if ((param_1 != 0) && (*(char *)((int)puVar1 + 0x3e) == '\0')) {
    FUN_00472e40();
  }
  return puVar1;
}


// ==== 0x472cb0 FUN_00472cb0

void FUN_00472cb0(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 *puVar2;
  
  FUN_00472a90();
  puVar2 = (undefined4 *)(unaff_ESI + 0x1c);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(code **)(unaff_ESI + 8) = FUN_00472f30;
  *(code **)(unaff_ESI + 0xc) = FUN_00472ee0;
  *(undefined4 *)(unaff_ESI + 0x10) = 1;
  return;
}


// ==== 0x472cf0 FUN_00472cf0

void FUN_00472cf0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  int *piVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined2 *)(param_1 + 0x3c) = *(undefined2 *)(param_2 + 0x3c);
  iVar7 = *(int *)(param_2 + 0x14);
  *(int *)(param_1 + 0x14) = iVar7;
  piVar4 = _malloc(iVar7 * 0x30 + 0x10);
  local_4 = 0;
  if (piVar4 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = piVar4 + 4;
    *piVar4 = iVar7;
    eh_vector_constructor_iterator(piVar5,0x30,iVar7,Struct_ClearHeader,NullUpdate_ret);
  }
  *(int **)(param_1 + 0x54) = piVar5;
  pvVar6 = _malloc((int)*(short *)(param_1 + 0x3c) << 1);
  *(void **)(param_1 + 0x50) = pvVar6;
  puVar9 = *(undefined4 **)(param_2 + 0x54);
  puVar10 = *(undefined4 **)(param_1 + 0x54);
  for (iVar7 = (*(int *)(param_1 + 0x14) * 3 & 0xfffffffU) << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  sVar3 = *(short *)(param_1 + 0x3c);
  puVar9 = *(undefined4 **)(param_2 + 0x50);
  puVar10 = *(undefined4 **)(param_1 + 0x50);
  for (uVar8 = ((int)sVar3 & 0x7fffffffU) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  for (iVar7 = ((int)sVar3 & 1U) << 1; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  puVar9 = (undefined4 *)(param_2 + 0x1c);
  puVar10 = (undefined4 *)(param_1 + 0x1c);
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  uVar1 = *(undefined4 *)(param_2 + 0x44);
  uVar2 = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  *(undefined1 *)(param_1 + 0x3e) = *(undefined1 *)(param_2 + 0x3e);
  ExceptionList = local_c;
  return;
}


// ==== 0x472df0 FUN_00472df0

void FUN_00472df0(void)

{
  void *pvVar1;
  int unaff_ESI;
  
  pvVar1 = *(void **)(unaff_ESI + 0x54);
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0x30,*(int *)((int)pvVar1 + -0x10),NullUpdate_ret);
    _free((void *)((int)pvVar1 + -0x10));
  }
  _free(*(void **)(unaff_ESI + 0x50));
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined2 *)(unaff_ESI + 0x3c) = 0;
  return;
}


// ==== 0x472e40 FUN_00472e40

void __fastcall FUN_00472e40(float *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(param_2 + 0x14)) {
    iVar5 = 0;
    do {
      fVar2 = param_1[1];
      fVar3 = param_1[2];
      pfVar1 = (float *)(iVar5 + 0x10 + *(int *)(param_2 + 0x54));
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x30;
      *pfVar1 = *pfVar1 - *param_1;
      pfVar1[1] = pfVar1[1] - fVar2;
      pfVar1[2] = pfVar1[2] - fVar3;
    } while (iVar4 < *(int *)(param_2 + 0x14));
  }
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  *(float *)(param_2 + 0x40) = *param_1;
  *(float *)(param_2 + 0x44) = fVar2;
  *(float *)(param_2 + 0x48) = fVar3;
  *(undefined1 *)(param_2 + 0x3e) = 1;
  return;
}


// ==== 0x472ea0 FUN_00472ea0

void __fastcall FUN_00472ea0(undefined4 param_1,int param_2)

{
  int extraout_EDX;
  
  *(float *)(param_2 + 0x48) = -*(float *)(param_2 + 0x48);
  *(float *)(param_2 + 0x40) = -*(float *)(param_2 + 0x40);
  *(float *)(param_2 + 0x44) = -*(float *)(param_2 + 0x44);
  *(undefined1 *)(param_2 + 0x3e) = 0;
  FUN_00472e40();
  *(undefined1 *)(extraout_EDX + 0x3e) = 0;
  return;
}


// ==== 0x472ee0 FUN_00472ee0

void FUN_00472ee0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2 * 0x30 + *(int *)(param_1 + 0x54);
  *(undefined2 *)(param_3 + 8) = *(undefined2 *)(iVar3 + 8);
  *(undefined2 *)(param_3 + 10) = *(undefined2 *)(iVar3 + 10);
  *(undefined2 *)(param_3 + 0xc) = *(undefined2 *)(iVar3 + 0xc);
  *(undefined2 *)(param_3 + 0xe) = *(undefined2 *)(iVar3 + 0xe);
  uVar1 = *(undefined4 *)(iVar3 + 0x14);
  uVar2 = *(undefined4 *)(iVar3 + 0x18);
  *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
  *(undefined4 *)(param_3 + 0x14) = uVar1;
  *(undefined4 *)(param_3 + 0x18) = uVar2;
  return;
}


// ==== 0x472f30 FUN_00472f30

/* WARNING: Type propagation algorithm not settling */

int FUN_00472f30(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,int param_7)

{
  int ******ppppppiVar1;
  int ******ppppppiVar2;
  ulonglong uVar3;
  short sVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *******pppppppiVar9;
  int *******unaff_ESI;
  int iVar10;
  int ******local_40;
  int iStack_3c;
  int *******pppppppiStack_34;
  LARGE_INTEGER local_30;
  float local_28;
  float fStack_24;
  undefined1 local_20 [28];
  
  bList__bList();
  uVar3 = (ulonglong)DAT_006f227c;
  uVar8 = DAT_006f227c ^ 0x1d872b41;
  uVar5 = uVar8 >> 5 ^ uVar8;
  DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar8;
  QueryPerformanceCounter(&local_30);
  sVar4 = __allshr();
  sVar4 = sVar4 + (short)(uVar3 % 0xffff);
  D3DXVec3Transform(local_20,param_2,param_6);
  iVar10 = *(int *)(param_1 + 0x14);
  piVar6 = (int *)(*(short *)(param_3 + 0xc) * 0x30 + *(int *)(param_1 + 0x54));
  *(int **)local_30.s.LowPart = piVar6;
  piVar6[1] = local_30.s.LowPart;
  *piVar6 = (int)&pppppppiStack_34;
  uVar5 = (uint)(0x10 < iVar10);
  local_30.s.LowPart = (DWORD)piVar6;
  do {
    while( true ) {
      iVar10 = 0;
      if ((int ********)pppppppiStack_34 == &pppppppiStack_34) {
        if (unaff_ESI == (int *******)0x0) {
          local_40 = (int ******)0xfcdc84dc;
          if (*(int *)(param_1 + 0x14) < 1) {
            return param_7;
          }
          iVar7 = 0;
          do {
            pppppppiVar9 = (int *******)(*(int *)(param_1 + 0x54) + iVar7);
            if (*(short *)((int)pppppppiVar9 + 0xe) != sVar4) {
              *(short *)((int)pppppppiVar9 + 0xe) = sVar4;
              pppppppiVar9[8] =
                   (int ******)
                   ((float)local_30.s.HighPart * (float)pppppppiVar9[4] +
                   local_28 * (float)pppppppiVar9[5] + fStack_24 * (float)pppppppiVar9[6]);
            }
            if (((float)local_40 < (float)pppppppiVar9[8]) || ((float)local_40 == -9.16e+36)) {
              local_40 = pppppppiVar9[8];
              unaff_ESI = pppppppiVar9;
            }
            iVar10 = iVar10 + 1;
            iVar7 = iVar7 + 0x30;
          } while (iVar10 < *(int *)(param_1 + 0x14));
          if (unaff_ESI == (int *******)0x0) {
            return param_7;
          }
        }
        goto LAB_0047336a;
      }
      ppppppiVar1 = *pppppppiStack_34;
      ppppppiVar2 = pppppppiStack_34[1];
      *ppppppiVar2 = (int *****)ppppppiVar1;
      ppppppiVar1[1] = (int *****)ppppppiVar2;
      if (*(short *)((int)pppppppiStack_34 + 0xe) != sVar4) {
        *(short *)((int)pppppppiStack_34 + 0xe) = sVar4;
        pppppppiStack_34[8] =
             (int ******)
             ((float)local_30.s.HighPart * (float)pppppppiStack_34[4] +
             local_28 * (float)pppppppiStack_34[5] + fStack_24 * (float)pppppppiStack_34[6]);
      }
      ppppppiVar1 = pppppppiStack_34[8];
      if (*(short *)(pppppppiStack_34 + 2) != 0) break;
      unaff_ESI = (int *******)0x0;
    }
    iVar10 = (int)*(short *)((int)pppppppiStack_34 + 10);
    iVar7 = *(short *)(pppppppiStack_34 + 2) + iVar10;
    unaff_ESI = pppppppiStack_34;
    if (3 < iVar7 - iVar10) {
      iStack_3c = iVar10 + 3;
      do {
        piVar6 = (int *)(*(short *)(*(int *)(param_1 + 0x50) + iVar10 * 2) * 0x30 +
                        *(int *)(param_1 + 0x54));
        if (*(short *)((int)piVar6 + 0xe) != sVar4) {
          piVar6[8] = (int)((float)local_30.s.HighPart * (float)piVar6[4] +
                           local_28 * (float)piVar6[5] + fStack_24 * (float)piVar6[6]);
        }
        if ((((float)ppppppiVar1 < (float)piVar6[8]) && (unaff_ESI = (int *******)0x0, uVar5 != 0))
           && (*(short *)((int)piVar6 + 0xe) != sVar4)) {
          *(int **)local_30.s.LowPart = piVar6;
          piVar6[1] = local_30.s.LowPart;
          *piVar6 = (int)&pppppppiStack_34;
          local_30._0_4_ = piVar6;
        }
        *(short *)((int)piVar6 + 0xe) = sVar4;
        piVar6 = (int *)(*(short *)(*(int *)(param_1 + 0x50) + 2 + iVar10 * 2) * 0x30 +
                        *(int *)(param_1 + 0x54));
        if (*(short *)((int)piVar6 + 0xe) != sVar4) {
          piVar6[8] = (int)((float)local_30.s.HighPart * (float)piVar6[4] +
                           local_28 * (float)piVar6[5] + fStack_24 * (float)piVar6[6]);
        }
        if ((((float)ppppppiVar1 < (float)piVar6[8]) && (unaff_ESI = (int *******)0x0, uVar5 != 0))
           && (*(short *)((int)piVar6 + 0xe) != sVar4)) {
          *(int **)local_30.s.LowPart = piVar6;
          piVar6[1] = local_30.s.LowPart;
          *piVar6 = (int)&pppppppiStack_34;
          local_30._0_4_ = piVar6;
        }
        *(short *)((int)piVar6 + 0xe) = sVar4;
        piVar6 = (int *)(*(short *)(*(int *)(param_1 + 0x50) + 4 + iVar10 * 2) * 0x30 +
                        *(int *)(param_1 + 0x54));
        if (*(short *)((int)piVar6 + 0xe) != sVar4) {
          piVar6[8] = (int)((float)local_30.s.HighPart * (float)piVar6[4] +
                           local_28 * (float)piVar6[5] + fStack_24 * (float)piVar6[6]);
        }
        if ((((float)ppppppiVar1 < (float)piVar6[8]) && (unaff_ESI = (int *******)0x0, uVar5 != 0))
           && (*(short *)((int)piVar6 + 0xe) != sVar4)) {
          *(int **)local_30.s.LowPart = piVar6;
          piVar6[1] = local_30.s.LowPart;
          *piVar6 = (int)&pppppppiStack_34;
          local_30._0_4_ = piVar6;
        }
        *(short *)((int)piVar6 + 0xe) = sVar4;
        piVar6 = (int *)(*(short *)(*(int *)(param_1 + 0x50) + 6 + iVar10 * 2) * 0x30 +
                        *(int *)(param_1 + 0x54));
        if (*(short *)((int)piVar6 + 0xe) != sVar4) {
          piVar6[8] = (int)((float)local_30.s.HighPart * (float)piVar6[4] +
                           local_28 * (float)piVar6[5] + fStack_24 * (float)piVar6[6]);
        }
        if ((((float)ppppppiVar1 < (float)piVar6[8]) && (unaff_ESI = (int *******)0x0, uVar5 != 0))
           && (*(short *)((int)piVar6 + 0xe) != sVar4)) {
          *(int **)local_30.s.LowPart = piVar6;
          piVar6[1] = local_30.s.LowPart;
          *piVar6 = (int)&pppppppiStack_34;
          local_30._0_4_ = piVar6;
        }
        *(short *)((int)piVar6 + 0xe) = sVar4;
        iStack_3c = iStack_3c + 4;
        iVar10 = iVar10 + 4;
      } while (iStack_3c < iVar7);
    }
    for (; iVar10 < iVar7; iVar10 = iVar10 + 1) {
      piVar6 = (int *)(*(short *)(*(int *)(param_1 + 0x50) + iVar10 * 2) * 0x30 +
                      *(int *)(param_1 + 0x54));
      if (*(short *)((int)piVar6 + 0xe) != sVar4) {
        piVar6[8] = (int)((float)local_30.s.HighPart * (float)piVar6[4] +
                         local_28 * (float)piVar6[5] + fStack_24 * (float)piVar6[6]);
      }
      if ((((float)ppppppiVar1 < (float)piVar6[8]) && (unaff_ESI = (int *******)0x0, uVar5 != 0)) &&
         (*(short *)((int)piVar6 + 0xe) != sVar4)) {
        *(int **)local_30.s.LowPart = piVar6;
        piVar6[1] = local_30.s.LowPart;
        *piVar6 = (int)&pppppppiStack_34;
        local_30._0_4_ = piVar6;
      }
      *(short *)((int)piVar6 + 0xe) = sVar4;
    }
    uVar5 = DAT_00735fd4;
  } while (unaff_ESI == (int *******)0x0);
LAB_0047336a:
  D3DXVec3Transform(param_7 + 0x10,unaff_ESI + 4,param_5);
  *(undefined2 *)(param_7 + 0xc) = *(undefined2 *)(unaff_ESI + 3);
  return param_7;
}


// ==== 0x4733a0 FUN_004733a0

void __fastcall FUN_004733a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar4 = *(int *)(unaff_ESI + 0x54);
  uVar1 = *(undefined4 *)(iVar4 + 0x10);
  uVar2 = *(undefined4 *)(iVar4 + 0x14);
  uVar3 = *(undefined4 *)(iVar4 + 0x18);
  *param_3 = uVar1;
  iVar4 = 1;
  param_3[1] = uVar2;
  param_3[2] = uVar3;
  param_2[2] = uVar3;
  *param_2 = uVar1;
  param_2[1] = uVar2;
  if (1 < *(int *)(unaff_ESI + 0x14)) {
    do {
      FUN_00567740();
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0x14));
  }
  return;
}


// ==== 0x473410 FUN_00473410

void FUN_00473410(void)

{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  eh_vector_constructor_iterator
            ((void *)(unaff_ESI + 0x20),0x30,9,Struct_ClearHeader,NullUpdate_ret);
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x1d4) = 0;
  *(undefined1 *)(unaff_ESI + 0x1d0) = 0;
  *(code **)(unaff_ESI + 8) = FUN_00473a90;
  *(code **)(unaff_ESI + 0xc) = FUN_00473a40;
  *(undefined4 *)(unaff_ESI + 0x10) = 2;
  return;
}


// ==== 0x473460 FUN_00473460

void FUN_00473460(void)

{
  int in_EAX;
  
  eh_vector_destructor_iterator((void *)(in_EAX + 0x20),0x30,9,NullUpdate_ret);
  return;
}


// ==== 0x473480 FUN_00473480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00473480(int param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  float *in_EAX;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  float local_70;
  float local_6c;
  float local_68;
  
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = param_3;
  if (ABS(*(float *)(param_2 + 0x50) - *(float *)(param_2 + 0x60)) <= 0.001) {
    if (ABS(*(float *)(param_2 + 0x54) - *(float *)(param_2 + 100)) <= 0.001) {
      if (ABS(*(float *)(param_2 + 0x58) - *(float *)(param_2 + 0x68)) <= 0.001) {
        bVar8 = 1;
      }
      else {
        bVar8 = 0;
      }
    }
    else {
      bVar8 = 0;
    }
  }
  else {
    bVar8 = 0;
  }
  iVar13 = 0;
  *(uint *)(param_1 + 0x14) = 4 - (uint)bVar8;
  if (0 < (int)(4 - (uint)bVar8)) {
    pfVar10 = (float *)(param_1 + 0x38);
    pfVar9 = (float *)(param_2 + 0x38);
    do {
      fVar1 = pfVar9[-2];
      fVar2 = *in_EAX;
      fVar3 = pfVar9[-1];
      fVar4 = in_EAX[1];
      fVar5 = *pfVar9;
      fVar6 = in_EAX[2];
      pfVar10[1] = 0.0;
      pfVar10[-2] = fVar1 - fVar2;
      pfVar10[-1] = fVar3 - fVar4;
      *pfVar10 = fVar5 - fVar6;
      *(short *)(pfVar10 + -3) = (short)iVar13;
      iVar13 = iVar13 + 1;
      *(float *)(param_1 + 0x1e0) = (fVar1 - fVar2) + *(float *)(param_1 + 0x1e0);
      *(float *)(param_1 + 0x1e4) = (fVar3 - fVar4) + *(float *)(param_1 + 0x1e4);
      *(float *)(param_1 + 0x1e8) = (fVar5 - fVar6) + *(float *)(param_1 + 0x1e8);
      pfVar10 = pfVar10 + 0xc;
      pfVar9 = pfVar9 + 4;
    } while (iVar13 < *(int *)(param_1 + 0x14));
  }
  iVar13 = 0;
  *(undefined4 *)(param_1 + 0x1f0) = *(undefined4 *)(param_1 + 0x1e0);
  *(undefined4 *)(param_1 + 500) = *(undefined4 *)(param_1 + 0x1e4);
  *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(param_1 + 0x1e8);
  fVar1 = _K_ONE / (float)*(int *)(param_1 + 0x14);
  *(float *)(param_1 + 0x1e0) = fVar1 * *(float *)(param_1 + 0x1e0);
  *(float *)(param_1 + 0x1e4) = fVar1 * *(float *)(param_1 + 0x1e4);
  *(float *)(param_1 + 0x1e8) = fVar1 * *(float *)(param_1 + 0x1e8);
  if (0.0 < *(float *)(param_1 + 0x1d4)) {
    fVar4 = -*(float *)(param_1 + 0x1d4);
    *(undefined1 *)(param_1 + 0x1d0) = 1;
    fVar1 = *(float *)(param_2 + 0x70);
    DAT_00735fd8 = 0;
    fVar2 = *(float *)(param_2 + 0x74);
    fVar3 = *(float *)(param_2 + 0x78);
    if (0 < *(int *)(param_1 + 0x14)) {
      pfVar10 = (float *)(param_1 + 0x38);
      do {
        fVar5 = pfVar10[-2] + fVar4 * fVar1;
        fVar6 = pfVar10[-1] + fVar2 * fVar4;
        fVar7 = fVar3 * fVar4 + *pfVar10;
        pfVar9 = (float *)((iVar13 + 1 + *(int *)(param_1 + 0x14)) * 0x30 + param_1);
        pfVar9[3] = 0.0;
        pfVar10 = pfVar10 + 0xc;
        *pfVar9 = fVar5;
        pfVar9[1] = fVar6;
        pfVar9[2] = fVar7;
        *(short *)((*(int *)(param_1 + 0x14) + iVar13) * 0x30 + 0x2c + param_1) =
             *(short *)(param_1 + 0x14) + (short)iVar13;
        iVar13 = iVar13 + 1;
        *(float *)(param_1 + 0x1f0) = fVar5 + *(float *)(param_1 + 0x1f0);
        *(float *)(param_1 + 500) = fVar6 + *(float *)(param_1 + 500);
        *(float *)(param_1 + 0x1f8) = fVar7 + *(float *)(param_1 + 0x1f8);
      } while (iVar13 < *(int *)(param_1 + 0x14));
    }
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) << 1;
  }
  iVar13 = 0;
  bVar14 = DAT_00735fd8 != 0;
  fVar1 = _K_ONE / (float)*(int *)(param_1 + 0x14);
  *(float *)(param_1 + 0x1f0) = fVar1 * *(float *)(param_1 + 0x1f0);
  *(float *)(param_1 + 500) = fVar1 * *(float *)(param_1 + 500);
  *(float *)(param_1 + 0x1f8) = fVar1 * *(float *)(param_1 + 0x1f8);
  if (bVar14) {
    if (*(int *)(param_1 + 0x14) == 3) {
      local_70 = *(float *)(param_2 + 0x40) * 0.33 + *(float *)(param_2 + 0x30) * 0.33;
      local_6c = *(float *)(param_2 + 0x44) * 0.33 + *(float *)(param_2 + 0x34) * 0.33;
      local_68 = *(float *)(param_2 + 0x48) * 0.33 + *(float *)(param_2 + 0x38) * 0.33;
      fVar1 = *(float *)(param_2 + 0x50) * 0.34;
      fVar2 = *(float *)(param_2 + 0x54) * 0.34;
      fVar3 = *(float *)(param_2 + 0x58) * 0.34;
    }
    else {
      local_70 = *(float *)(param_2 + 0x50) * 0.25 +
                 *(float *)(param_2 + 0x40) * 0.25 + *(float *)(param_2 + 0x30) * 0.25;
      local_6c = *(float *)(param_2 + 0x54) * 0.25 +
                 *(float *)(param_2 + 0x44) * 0.25 + *(float *)(param_2 + 0x34) * 0.25;
      local_68 = *(float *)(param_2 + 0x58) * 0.25 +
                 *(float *)(param_2 + 0x38) * 0.25 + *(float *)(param_2 + 0x48) * 0.25;
      fVar1 = *(float *)(param_2 + 0x60) * 0.25;
      fVar2 = *(float *)(param_2 + 100) * 0.25;
      fVar3 = *(float *)(param_2 + 0x68) * 0.25;
    }
    pfVar10 = (float *)((*(int *)(param_1 + 0x14) * 3 + 3) * 0x10 + param_1);
    pfVar10[3] = 0.0;
    pfVar10[2] = fVar3 + local_68;
    *pfVar10 = fVar1 + local_70;
    pfVar10[1] = fVar2 + local_6c;
    *(undefined2 *)(*(int *)(param_1 + 0x14) * 0x30 + 0x2c + param_1) =
         *(undefined2 *)(param_1 + 0x14);
    if (0 < *(int *)(param_1 + 0x14)) {
      pfVar10 = (float *)(param_1 + 0x38);
      do {
        iVar11 = (*(int *)(param_1 + 0x14) * 3 + 3) * 0x10;
        iVar12 = iVar11 + param_1;
        fVar1 = *(float *)(iVar11 + param_1) * _K_HALF;
        fVar2 = *(float *)(iVar12 + 4) * _K_HALF;
        fVar3 = *(float *)(iVar12 + 8) * _K_HALF;
        fVar4 = pfVar10[-2] * _K_HALF;
        fVar5 = pfVar10[-1] * _K_HALF;
        fVar6 = *pfVar10 * _K_HALF;
        pfVar9 = (float *)((*(int *)(param_1 + 0x14) + 2 + iVar13) * 0x30 + param_1);
        pfVar9[3] = 0.0;
        pfVar9[2] = fVar6 + fVar3;
        *pfVar9 = fVar4 + fVar1;
        pfVar9[1] = fVar5 + fVar2;
        *(short *)((*(int *)(param_1 + 0x14) + iVar13) * 0x30 + 0x5c + param_1) =
             *(short *)(param_1 + 0x14) + (short)iVar13 + 1;
        iVar13 = iVar13 + 1;
        pfVar10 = pfVar10 + 0xc;
      } while (iVar13 < *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x14) = (uint)(*(int *)(param_1 + 0x14) != 3) * 2 + 7;
  }
  return;
}


// ==== 0x473a40 FUN_00473a40

void FUN_00473a40(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_2 * 0x30 + 0x20 + param_1;
  *(undefined2 *)(param_3 + 8) = *(undefined2 *)(param_2 * 0x30 + 0x28 + param_1);
  *(undefined2 *)(param_3 + 10) = *(undefined2 *)(iVar1 + 10);
  *(undefined2 *)(param_3 + 0xc) = *(undefined2 *)(iVar1 + 0xc);
  *(undefined2 *)(param_3 + 0xe) = *(undefined2 *)(iVar1 + 0xe);
  uVar2 = *(undefined4 *)(iVar1 + 0x14);
  uVar3 = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(param_3 + 0x14) = uVar2;
  *(undefined4 *)(param_3 + 0x18) = uVar3;
  return;
}


// ==== 0x473a90 FUN_00473a90

void FUN_00473a90(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int in_stack_0000001c;
  float local_18;
  float *local_14;
  
  iVar3 = *(int *)(param_1 + 0x14);
  local_18 = -9.16e+36;
  local_14 = (float *)0x0;
  if ((0.0 < *(float *)(param_1 + 0x1d4)) && (*(char *)(param_1 + 0x1d0) == '\0')) {
    iVar3 = iVar3 / 2;
  }
  iVar7 = 0;
  pfVar6 = (float *)0x0;
  if (3 < iVar3) {
    iVar5 = 3;
    pfVar4 = (float *)(param_1 + 0x34);
    do {
      fVar1 = param_2[1] * *pfVar4 + pfVar4[1] * param_2[2] + pfVar4[-1] * *param_2;
      if ((local_18 < fVar1) || (local_18 == -9.16e+36)) {
        local_14 = pfVar4 + -5;
        local_18 = fVar1;
      }
      fVar1 = pfVar4[0xb] * *param_2 + pfVar4[0xd] * param_2[2] + pfVar4[0xc] * param_2[1];
      if ((local_18 < fVar1) || (local_18 == -9.16e+36)) {
        local_14 = pfVar4 + 7;
        local_18 = fVar1;
      }
      fVar1 = pfVar4[0x17] * *param_2 + pfVar4[0x19] * param_2[2] + pfVar4[0x18] * param_2[1];
      if ((local_18 < fVar1) || (local_18 == -9.16e+36)) {
        local_14 = pfVar4 + 0x13;
        local_18 = fVar1;
      }
      fVar1 = pfVar4[0x23] * *param_2 + pfVar4[0x25] * param_2[2] + pfVar4[0x24] * param_2[1];
      if ((local_18 < fVar1) || (local_18 == -9.16e+36)) {
        local_14 = pfVar4 + 0x1f;
        local_18 = fVar1;
      }
      iVar5 = iVar5 + 4;
      iVar7 = iVar7 + 4;
      pfVar4 = pfVar4 + 0x30;
      pfVar6 = local_14;
    } while (iVar5 < iVar3);
  }
  if (iVar7 < iVar3) {
    pfVar4 = (float *)(iVar7 * 0x30 + 0x34 + param_1);
    iVar3 = iVar3 - iVar7;
    do {
      fVar1 = *pfVar4 * param_2[1] + pfVar4[1] * param_2[2] + pfVar4[-1] * *param_2;
      if ((local_18 < fVar1) || (local_18 == -9.16e+36)) {
        pfVar6 = pfVar4 + -5;
        local_18 = fVar1;
      }
      pfVar4 = pfVar4 + 0xc;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (pfVar6 != (float *)0x0) {
    fVar1 = pfVar6[5];
    fVar2 = pfVar6[6];
    *(float *)(in_stack_0000001c + 0x10) = pfVar6[4];
    *(undefined4 *)(in_stack_0000001c + 0x1c) = 0;
    *(float *)(in_stack_0000001c + 0x14) = fVar1;
    *(float *)(in_stack_0000001c + 0x18) = fVar2;
    *(undefined2 *)(in_stack_0000001c + 0xc) = *(undefined2 *)(pfVar6 + 3);
  }
  return;
}


// ==== 0x473ca0 FUN_00473ca0

void FUN_00473ca0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int unaff_ESI;
  
  FUN_00472a90();
  *(code **)(unaff_ESI + 8) = FUN_00473dd0;
  *(code **)(unaff_ESI + 0xc) = FUN_00473d60;
  *(undefined4 *)(unaff_ESI + 0x10) = 3;
  *(undefined4 *)(unaff_ESI + 0x14) = 8;
  CollisionShapes__DefaultBox(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x473cf0 CollisionShapes::DefaultBox

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props med (hopper+ghidra) docs/re/props.md */

void CollisionShapes__DefaultBox
               (float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x14) = 8;
  *(float *)(in_EAX + 0x20) = (param_1 + param_4) * _K_HALF;
  *(float *)(in_EAX + 0x24) = (param_2 + param_5) * _K_HALF;
  *(float *)(in_EAX + 0x28) = (param_3 + param_6) * _K_HALF;
  *(float *)(in_EAX + 0x30) = (param_4 - param_1) * _K_HALF;
  *(float *)(in_EAX + 0x34) = (param_5 - param_2) * _K_HALF;
  *(float *)(in_EAX + 0x38) = (param_6 - param_3) * _K_HALF;
  return;
}


// ==== 0x473d60 FUN_00473d60

void FUN_00473d60(int param_1,ushort param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_3 + 0x14) = uVar1;
  *(undefined4 *)(param_3 + 0x18) = uVar2;
  *(ushort *)(param_3 + 0xc) = param_2;
  if ((param_2 & 1) != 0) {
    *(float *)(param_3 + 0x10) = -*(float *)(param_1 + 0x30);
  }
  if ((param_2 & 2) != 0) {
    *(float *)(param_3 + 0x14) = -*(float *)(param_1 + 0x34);
  }
  if ((param_2 & 4) != 0) {
    *(float *)(param_3 + 0x18) = -*(float *)(param_1 + 0x38);
  }
  fVar3 = *(float *)(param_1 + 0x24);
  fVar4 = *(float *)(param_1 + 0x28);
  *(float *)(param_3 + 0x10) = *(float *)(param_3 + 0x10) + *(float *)(param_1 + 0x20);
  *(float *)(param_3 + 0x14) = fVar3 + *(float *)(param_3 + 0x14);
  *(float *)(param_3 + 0x18) = fVar4 + *(float *)(param_3 + 0x18);
  return;
}


// ==== 0x473dd0 FUN_00473dd0

void FUN_00473dd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  ushort uVar1;
  undefined4 unaff_ESI;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  undefined1 auStack_20 [28];
  
  D3DXVec3Transform(auStack_20);
  fStack_3c = *(float *)(param_1 + 0x30);
  fStack_38 = *(float *)(param_1 + 0x34);
  fStack_34 = *(float *)(param_1 + 0x38);
  if (fStack_2c < 0.0) {
    fStack_3c = -fStack_3c;
  }
  uVar1 = (ushort)(fStack_2c < 0.0);
  if (fStack_28 < 0.0) {
    uVar1 = uVar1 | 2;
    fStack_38 = -fStack_38;
  }
  if (fStack_24 < 0.0) {
    uVar1 = uVar1 | 4;
    fStack_34 = -fStack_34;
  }
  fStack_3c = fStack_3c + *(float *)(param_1 + 0x20);
  fStack_38 = *(float *)(param_1 + 0x24) + fStack_38;
  fStack_34 = *(float *)(param_1 + 0x28) + fStack_34;
  D3DXVec3Transform(&fStack_3c,&fStack_3c,param_5);
  *(undefined4 *)(param_7 + 0x10) = param_2;
  *(undefined4 *)(param_7 + 0x14) = param_6;
  *(undefined4 *)(param_7 + 0x18) = unaff_ESI;
  *(undefined4 *)(param_7 + 0x1c) = 0;
  *(ushort *)(param_7 + 0xc) = uVar1;
  return;
}


// ==== 0x473ea0 FUN_00473ea0

void FUN_00473ea0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  FUN_00472a90();
  Struct_ClearHeader();
  *(code **)(unaff_ESI + 8) = FUN_00473f20;
  *(code **)(unaff_ESI + 0xc) = FUN_00473ef0;
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  *(undefined4 *)(unaff_ESI + 0x30) = *unaff_EDI;
  *(undefined4 *)(unaff_ESI + 0x34) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined4 *)(unaff_ESI + 0x38) = uVar2;
  *(undefined2 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 1;
  *(undefined4 *)(unaff_ESI + 0x10) = 4;
  return;
}


// ==== 0x473ef0 FUN_00473ef0

void FUN_00473ef0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_3 + 0x14) = uVar1;
  *(undefined4 *)(param_3 + 0x1c) = 0;
  *(undefined4 *)(param_3 + 0x18) = uVar2;
  *(undefined2 *)(param_3 + 0xc) = *(undefined2 *)(param_1 + 0x2c);
  return;
}


// ==== 0x473f20 FUN_00473f20

void FUN_00473f20(int param_1)

{
  undefined4 in_stack_00000014;
  int in_stack_0000001c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = *(undefined4 *)(param_1 + 0x34);
  local_20 = *(undefined4 *)(param_1 + 0x30);
  local_18 = *(undefined4 *)(param_1 + 0x38);
  D3DXVec3Transform(&local_20,&local_20,in_stack_00000014);
  *(undefined4 *)(in_stack_0000001c + 0x10) = uStack_2c;
  *(undefined4 *)(in_stack_0000001c + 0x14) = uStack_28;
  *(undefined4 *)(in_stack_0000001c + 0x18) = uStack_24;
  *(undefined4 *)(in_stack_0000001c + 0x1c) = 0;
  *(undefined2 *)(in_stack_0000001c + 0xc) = *(undefined2 *)(param_1 + 0x2c);
  return;
}


// ==== 0x473f90 FUN_00473f90

void FUN_00473f90(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *_Memory;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  while (piVar1 != unaff_ESI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _Memory = (void *)EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(piVar1);
    _free(_Memory);
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x473fc0 SelectDriveClassTuningRow__not_GetUpgradeLevel_

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined * __fastcall
SelectDriveClassTuningRow__not_GetUpgradeLevel_(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(0.2 <= *(float *)(param_2 + 0x1c0));
  if (0.8 < *(float *)(param_2 + 0x1c0)) {
    uVar1 = 2;
  }
  return &DAT_006f0fc0 + uVar1 * 0x6c;
}


// ==== 0x474010 FUN_00474010

undefined4 FUN_00474010(void)

{
  return 4;
}


// ==== 0x474020 Mellovator::GetState

/* [canon] car low (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall Mellovator__GetState(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x24);
  param_2[1] = *(undefined4 *)(param_1 + 0x28);
  param_2[2] = *(undefined4 *)(param_1 + 0x2c);
  param_2[3] = *(undefined4 *)(param_1 + 0x30);
  return;
}


// ==== 0x474040 Mellovator::SetState

/* [canon] car low (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall Mellovator__SetState(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x24) = *param_2;
  *(undefined4 *)(param_1 + 0x28) = param_2[1];
  *(undefined4 *)(param_1 + 0x2c) = param_2[2];
  *(undefined4 *)(param_1 + 0x30) = param_2[3];
  return;
}


// ==== 0x474060 FUN_00474060

void __fastcall FUN_00474060(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00735f88;
  iVar1 = *(int *)(DAT_00735f88 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00735f88 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x474080 FUN_00474080

undefined4 * __thiscall FUN_00474080(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00584950();
  iVar2 = DAT_00735f88;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f88 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f88 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x4740b0 FUN_004740b0

undefined4 __fastcall FUN_004740b0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}


// ==== 0x4740c0 FUN_004740c0

undefined4 __fastcall FUN_004740c0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4c);
}


// ==== 0x4740d0 MellowMover::MellowMover

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * __fastcall
MellowMover__MellowMover(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,int param_5)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  float fVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puStack_14;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068649b;
  pvStack_c = ExceptionList;
  puVar4 = param_3 + 5;
  ExceptionList = &pvStack_c;
  *puVar4 = puVar4;
  param_3[6] = puVar4;
  param_3[7] = 0;
  param_3[2] = &PTR_FUN_006c84a0;
  *param_3 = &PTR_FUN_006c8468;
  param_3[2] = &PTR_FUN_006c845c;
  param_3[0x12] = 0;
  param_3[0xb] = param_5;
  param_3[0xd] = param_4;
  pcVar1 = (char *)(param_3 + 3);
  param_3[1] = param_2;
  param_3[0xc] = param_1;
  local_4 = 1;
  *pcVar1 = 'M';
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)("MeloMvr" + (1 - (int)pcVar1))];
    pcVar6 = pcVar6 + 1;
    *pcVar6 = cVar2;
  } while (cVar2 != '\0');
  iVar7 = FUN_00567160();
  if (iVar7 == 0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)FUN_00584800();
  }
  param_3[8] = piVar8;
  if (piVar8 == (int *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = piVar8 + 1;
  }
  puVar4 = (undefined4 *)param_3[6];
  _DAT_00735fd0 = piVar8;
  *puVar4 = piVar10;
  param_3[6] = piVar10;
  piVar10[1] = (int)puVar4;
  *piVar10 = (int)(param_3 + 5);
  iVar7 = (**(code **)(*piVar8 + 4))();
  param_3[7] = param_3[7] + iVar7;
  _DAT_006f0738 = 0;
  param_3[0x13] = 0;
  iVar7 = FUN_00567160();
  local_4._0_1_ = 2;
  if (iVar7 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = Mellovator__Mellovator
                      (iVar7,param_3[0xb],param_3[8],*(undefined4 *)(param_1 + 4),
                       *(undefined4 *)(param_1 + 8));
  }
  param_3[9] = uVar9;
  iVar7 = *(int *)(param_4 + 0x10);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (*(char *)(iVar7 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar5 = ((*(float *)(iVar7 + 0x428) - _DAT_006f0d58) * 10.0) / (_DAT_006f0d5c - _DAT_006f0d58);
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  else if (10.0 < fVar5) {
    fVar5 = 10.0;
  }
  *(float *)(param_3[9] + 0x140) = fVar5 * 0.25 * 0.1 + 0.25;
  piVar8 = (int *)param_3[9];
  if (piVar8 == (int *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = piVar8 + 1;
  }
  puVar4 = (undefined4 *)param_3[6];
  *puVar4 = piVar10;
  param_3[6] = piVar10;
  piVar10[1] = (int)puVar4;
  *piVar10 = (int)(param_3 + 5);
  iVar7 = (**(code **)(*piVar8 + 4))();
  param_3[7] = param_3[7] + iVar7;
  piVar8 = (int *)FUN_00567160();
  if (piVar8 == (int *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    iVar7 = param_3[8];
    *piVar8 = param_3[0xb] + 0x260;
    piVar8[1] = iVar7;
    piVar8[2] = 0x3f800000;
    piVar8[3] = 0x3f800000;
    piVar8[4] = 0;
    piVar8[5] = 0;
    *(undefined1 *)(piVar8 + 0xc) = 1;
  }
  param_3[10] = piVar8;
  *(undefined4 *)(param_3[8] + 0x1e4) = *(undefined4 *)(param_3[0xb] + 0x290);
  FUN_004745b0();
  puStack_14 = param_3 + 0xe;
  param_4 = 0;
  param_5 = 0;
  do {
    iVar7 = DAT_00735f74;
    puVar4 = (undefined4 *)(DAT_00735f74 + 0x10);
    if ((*(int *)(DAT_00735f74 + 0x10) == 0) && ((*(byte *)(DAT_00735f74 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    puVar12 = (undefined4 *)*puVar4;
    iVar11 = *(int *)(iVar7 + 0x18) + 1;
    if (puVar12 == (undefined4 *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = *puVar12;
      if (*(int *)(iVar7 + 0x1c) < iVar11) {
        *(int *)(iVar7 + 0x1c) = iVar11;
      }
      *(int *)(iVar7 + 0x18) = iVar11;
      bVar3 = *(byte *)(iVar7 + 0x14);
      *puVar4 = uVar9;
      if (((bVar3 & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, 0 < iVar7)) {
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar12 = 0;
          puVar12 = puVar12 + 1;
        }
      }
      iVar7 = param_3[0xb];
      uVar9 = FUN_005868e0(param_5 + 0x10 + iVar7,(param_4 / 2) * 0x20 + 0xd0 + iVar7,iVar7 + 0x270)
      ;
    }
    *puStack_14 = uVar9;
    param_5 = param_5 + 0x30;
    param_4 = param_4 + 1;
    puStack_14 = puStack_14 + 1;
  } while (param_5 < 0xc0);
  FUN_00474640();
  FUN_00474ca0();
  ExceptionList = pvStack_c;
  return param_3;
}


// ==== 0x474400 FUN_00474400

undefined4 * __thiscall FUN_00474400(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00474460(param_1);
  iVar2 = DAT_00735f8c;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f8c + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f8c + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x474430 FUN_00474430

void __fastcall FUN_00474430(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pvStack_c = ExceptionList;
  pcStack_8 = FUN_006854db;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c85a8;
  piVar2 = (int *)param_1[3];
  piVar1 = param_1 + 3;
  uStack_4 = 0;
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    if (piVar2 + -1 != (int *)0x0) {
      (**(code **)piVar2[-1])(1);
    }
    piVar2 = (int *)*piVar1;
  }
  piVar2 = (int *)*piVar1;
  uStack_4 = 0xffffffff;
  while (piVar2 != piVar1) {
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    if (piVar2 + -1 != (int *)0x0) {
      (**(code **)piVar2[-1])(1);
    }
    piVar2 = (int *)*piVar1;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x474440 FUN_00474440

void * __thiscall FUN_00474440(void *param_1,byte param_2)

{
  FUN_00474430();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x474460 FUN_00474460

void FUN_00474460(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00685c3f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c8468;
  param_1[2] = &PTR_FUN_006c845c;
  *(undefined1 *)(*(int *)(param_1[0xd] + 0x3c) + 0x1d) = 1;
  *(undefined4 *)(param_1[8] + 0x140) = 1;
  iVar2 = DAT_00735f80;
  iVar3 = *(int *)(DAT_00735f80 + 0x18);
  local_4 = 1;
  puVar1 = (undefined4 *)param_1[10];
  *puVar1 = *(undefined4 *)(DAT_00735f80 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar3 + -1;
  *(undefined4 **)(iVar2 + 0x10) = puVar1;
  piVar4 = param_1 + 0xe;
  iVar3 = 4;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_4 = local_4 & 0xffffff00;
  PhysicsSystem___PhysicsSystem();
  *param_1 = &PTR_PsychoDriverDerived__scalar_deleting_dtor_006caadc;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x474500 FUN_00474500

void __thiscall FUN_00474500(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int local_14;
  
  FUN_00571ea0(param_1,"MellowMover");
  FUN_00584960();
  FUN_00475240();
  iVar1 = *(int *)(param_1 + 0x28);
  if (*(char *)(param_2 + 0x3d) != '\0' || *(char *)(param_2 + 0x3c) != '\0') {
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(undefined1 *)(iVar1 + 0x30) = 1;
  }
  local_14 = 4;
  do {
    FUN_005869c0();
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4745b0 FUN_004745b0

void FUN_004745b0(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_EDI;
  
  puVar3 = *(undefined4 **)(unaff_EDI + 0x2c);
  if (puVar3 != (undefined4 *)0x0) {
    iVar4 = *(int *)(unaff_EDI + 0x20);
    uVar1 = puVar3[2];
    uVar5 = *puVar3;
    *(undefined4 *)(iVar4 + 0x1d4) = puVar3[1];
    *(undefined4 *)(iVar4 + 0x1d0) = uVar5;
    *(undefined4 *)(iVar4 + 0x1d8) = uVar1;
  }
  RigidBody__SetMassInertia();
  fVar2 = *(float *)(*(int *)(unaff_EDI + 0x34) + 0x3d0);
  if ((char)(*(int **)(unaff_EDI + 0x28))[0xc] != '\0') {
    if (fVar2 < 0.0) {
      fVar2 = 0.0;
    }
    iVar4 = **(int **)(unaff_EDI + 0x28);
    FUN_00475460((*(float *)(iVar4 + 8) + *(float *)(iVar4 + 4)) * fVar2);
    return;
  }
  FUN_00475460(0);
  return;
}


// ==== 0x474640 FUN_00474640

void FUN_00474640(void)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  undefined4 uVar4;
  int unaff_ESI;
  
  *(undefined2 *)(*(int *)(unaff_ESI + 0x24) + 0x130) =
       *(undefined2 *)(*(int *)(unaff_ESI + 4) + 0x1d0);
  *(undefined4 *)(*(int *)(unaff_ESI + 0x24) + 0x128) =
       *(undefined4 *)(*(int *)(unaff_ESI + 4) + 0x1dc);
  uVar4 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x24))();
  *(undefined4 *)(*(int *)(unaff_ESI + 0x24) + 0x134) = uVar4;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x24) + 300) =
       *(undefined4 *)(*(int *)(unaff_ESI + 4) + 0x1e4);
  FUN_00584b80(*(int *)(unaff_ESI + 0x30) + 0x30,*(int *)(unaff_ESI + 0x30) + 0x90);
  iVar1 = *(int *)(unaff_ESI + 0x30);
  FUN_004754e0(*(undefined4 *)(iVar1 + 0x2b0),*(undefined4 *)(iVar1 + 0x2b4),
               *(undefined4 *)(iVar1 + 0x2b8),*(undefined4 *)(iVar1 + 700));
  bVar2 = DAT_007000e4 == 100.0;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x24) + 0x124) =
       *(undefined4 *)(*(int *)(unaff_ESI + 0x30) + 0x398);
  fVar3 = DAT_007000e4;
  if (bVar2) {
    fVar3 = *(float *)(*(int *)(unaff_ESI + 0x30) + 0x3a0);
  }
  *(float *)(*(int *)(unaff_ESI + 0x24) + 0x120) = fVar3;
                    /* WARNING: Could not recover jumptable at 0x0047471f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(unaff_ESI + 8) + 4))();
  return;
}


// ==== 0x474730 FUN_00474730

void FUN_00474730(float param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int iVar7;
  undefined2 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  char cVar11;
  int iVar12;
  int unaff_EBX;
  undefined4 *local_18;
  int local_14;
  float local_10;
  int *local_8;
  
  iVar7 = *(int *)(unaff_EBX + 0x30);
  if (DAT_007798e0 == 0) {
    iVar12 = *(int *)(unaff_EBX + 0x20);
    uVar10 = *(undefined4 *)(iVar12 + 0x24);
    uVar2 = *(undefined4 *)(iVar12 + 0x28);
    *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(iVar12 + 0x20);
    *(undefined4 *)(iVar7 + 0x24) = uVar10;
    *(undefined4 *)(iVar7 + 0x28) = uVar2;
    bMatrixCopy_b();
    FUN_00465390();
    iVar12 = *(int *)(unaff_EBX + 0x20);
    uVar10 = *(undefined4 *)(iVar12 + 0xa4);
    uVar2 = *(undefined4 *)(iVar12 + 0xa8);
    *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(iVar12 + 0xa0);
    *(undefined4 *)(iVar7 + 0x34) = uVar10;
    *(undefined4 *)(iVar7 + 0x38) = uVar2;
    fVar3 = *(float *)(iVar12 + 0xa8);
    fVar4 = *(float *)(iVar12 + 0xa4);
    fVar5 = *(float *)(iVar12 + 0xa0);
    *(undefined1 *)(iVar7 + 0x420) = 0;
    *(float *)(iVar7 + 0x394) = SQRT(fVar4 * fVar4 + fVar3 * fVar3 + fVar5 * fVar5);
    iVar12 = *(int *)(unaff_EBX + 0x20);
    uVar10 = *(undefined4 *)(iVar12 + 0xc4);
    uVar2 = *(undefined4 *)(iVar12 + 200);
    *(undefined4 *)(iVar7 + 0x90) = *(undefined4 *)(iVar12 + 0xc0);
    *(undefined4 *)(iVar7 + 0x94) = uVar10;
    *(undefined4 *)(iVar7 + 0x98) = uVar2;
    uVar8 = Atan2ToAngle16(*(undefined4 *)(*(int *)(unaff_EBX + 0x20) + 0x30),
                           *(undefined4 *)(*(int *)(unaff_EBX + 0x20) + 0x34));
    *(undefined2 *)(iVar7 + 0x374) = uVar8;
    iVar12 = *(int *)(unaff_EBX + 0x20);
    fVar3 = *(float *)(iVar12 + 0x38);
    fVar4 = *(float *)(iVar12 + 0x34);
    local_18 = (undefined4 *)(iVar7 + 0x334);
    local_14 = 0;
    fVar5 = *(float *)(iVar12 + 0x30);
    local_8 = (int *)(unaff_EBX + 0x38);
    puVar9 = (undefined4 *)(iVar7 + 0x354);
    *(undefined4 *)(iVar7 + 0x3a8) = 1;
    *(undefined4 *)(iVar7 + 900) = 0;
    *(undefined4 *)(iVar7 + 0x388) = 0;
    *(float *)(iVar7 + 0x390) =
         *(float *)(iVar7 + 0x30) * fVar5 +
         *(float *)(iVar7 + 0x34) * fVar4 + *(float *)(iVar7 + 0x38) * fVar3;
    do {
      fVar3 = *(float *)((-0x330 - iVar7) + *(int *)(unaff_EBX + 0x24) + (int)puVar9);
      fVar4 = (float)puVar9[-0x25];
      local_10 = *(float *)(*(int *)(unaff_EBX + 0x24) + (-800 - iVar7) + (int)puVar9);
      fVar5 = *(float *)((local_14 / 2) * 0x20 + 0x18c + *(int *)(unaff_EBX + 0x2c));
      if (fVar5 < local_10) {
        local_10 = fVar5;
      }
      uVar10 = _ftol_nocw(local_10);
      FUN_00586bb0(fVar3 * param_1 + fVar4,fVar3,uVar10,local_10);
      cVar6 = *(char *)(iVar7 + 0x310 + local_14);
      cVar11 = (char)*(undefined4 *)((int)puVar9 + *(int *)(unaff_EBX + 0x24) + (-0x2f0 - iVar7));
      *(char *)(iVar7 + 0x310 + local_14) = cVar11;
      if (cVar6 == '\0') {
        if (cVar11 != '\0') {
          iVar12 = *(int *)(iVar7 + 0x38c) + 1;
LAB_0047495c:
          *(int *)(iVar7 + 0x38c) = iVar12;
        }
      }
      else if (cVar11 == '\0') {
        iVar12 = *(int *)(iVar7 + 0x38c) + -1;
        goto LAB_0047495c;
      }
      uVar10 = *(undefined4 *)(*(int *)(unaff_EBX + 0x24) + 0x98 + local_14 * 8);
      *local_18 = *(undefined4 *)(*(int *)(unaff_EBX + 0x24) + 0x94 + local_14 * 8);
      local_18[1] = uVar10;
      *puVar9 = 0;
      puVar9[-0x21] = *(undefined4 *)(*(int *)(unaff_EBX + 0x24) + (-0x300 - iVar7) + (int)puVar9);
      if (*(char *)(*local_8 + 0x155) == '\0') {
        uVar10 = 0;
      }
      else {
        uVar10 = *(undefined4 *)(*local_8 + 0x15c);
      }
      puVar9[-0x1d] = uVar10;
      *(undefined1 *)(*local_8 + 0x155) =
           *(undefined1 *)((int)puVar9 + *(int *)(unaff_EBX + 0x24) + (-0x2f0 - iVar7));
      puVar1 = (undefined4 *)(*(int *)(unaff_EBX + 0x24) + 0x94 + local_14 * 8);
      iVar12 = *local_8;
      uVar10 = *puVar1;
      *(undefined4 *)(iVar12 + 0x104) =
           *(undefined4 *)(*(int *)(unaff_EBX + 0x24) + 0x98 + local_14 * 8);
      *(undefined4 *)(iVar12 + 0x100) = uVar10;
      *(undefined4 *)(iVar12 + 0x160) = *puVar1;
      *(undefined1 *)(*local_8 + 0x154) =
           *(undefined1 *)(*(int *)(unaff_EBX + 0x24) + 0xb4 + local_14);
      iVar12 = *(int *)(unaff_EBX + 0x34);
      if (((*(int *)(*(int *)(iVar12 + 0x14) + 4) != 3) && (*(char *)(iVar12 + 0x8a8) == '\0')) &&
         (*(char *)(iVar12 + 0x4d0) != '\0')) {
        FUN_00587e90(param_1,iVar12);
      }
      puVar9 = puVar9 + 1;
      local_14 = local_14 + 1;
      local_8 = local_8 + 1;
      local_18 = local_18 + 2;
    } while (local_14 < 4);
  }
  *(undefined4 *)(iVar7 + 0x3a0) = *(undefined4 *)(*(int *)(unaff_EBX + 0x24) + 0x120);
  *(undefined4 *)(iVar7 + 0x398) = *(undefined4 *)(*(int *)(unaff_EBX + 0x24) + 0x124);
  return;
}


// ==== 0x474a90 FUN_00474a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00474a90(int param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  LARGE_INTEGER local_20;
  LARGE_INTEGER LStack_18;
  LARGE_INTEGER LStack_10;
  
  QueryPerformanceCounter(&local_20);
  iVar3 = *(int *)(*(int *)(param_1 + 0x34) + 0x38);
  if (iVar3 != 0) {
    if (iVar3 == 1) {
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x130) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x134) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x138) = 0;
      uVar2 = DAT_006ffde8;
      *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x30) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x24) + 400) = uVar2;
      goto LAB_00474af2;
    }
    if (iVar3 != 2) goto LAB_00474af2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x130) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x134) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x138) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x30) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 400) = 0x411ccccd;
LAB_00474af2:
  if (*(int *)(*(int *)(param_1 + 0x34) + 0x3cc) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x138) = 0;
  }
  FUN_004745b0();
  *(undefined2 *)(*(int *)(param_1 + 0x24) + 0x130) = *(undefined2 *)(*(int *)(param_1 + 4) + 0x1d0)
  ;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc)
  ;
  uVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x24))();
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x134) = uVar2;
  fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x1e4);
  local_20.s.LowPart = (DWORD)(*(float *)(*(int *)(param_1 + 4) + 0x1e0) * _K_HALF);
  if (fVar1 <= (float)local_20.s.LowPart) {
    fVar1 = (float)local_20.s.LowPart;
  }
  *(float *)(*(int *)(param_1 + 0x24) + 300) = fVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x10) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc);
  *(float *)(*(int *)(param_1 + 0x28) + 0x14) =
       (float)*(int *)(*(int *)(param_1 + 0x30) + 0x38c) * 0.25;
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x34) + 0x14) + 0x734) != '\0') {
    iVar3 = FUN_00438aa0();
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x1e0) = *(undefined4 *)(iVar3 + 0x23c);
  }
  iVar3 = *(int *)(param_1 + 0x30);
  *(undefined4 *)(iVar3 + 0x2f0) = 0;
  *(undefined4 *)(iVar3 + 0x2f4) = 0;
  *(undefined4 *)(iVar3 + 0x2f8) = 0;
  *(undefined4 *)(iVar3 + 0x2fc) = 0;
  FUN_00474d40(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x404));
  iVar3 = _ftol_nocw();
  iVar3 = iVar3 + 1;
  local_20.s.LowPart = (DWORD)(param_2 / (float)iVar3);
  if (0 < iVar3) {
    do {
      _DAT_006f0738 = (float)local_20.s.LowPart;
      QueryPerformanceCounter(&LStack_18);
      FUN_0046aa40(param_1 + 8,local_20.s.LowPart);
      eOrthonormalizeMatrix();
      QueryPerformanceCounter(&LStack_10);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_00474730(param_2);
  return (float10)param_2;
}


// ==== 0x474ca0 FUN_00474ca0

void __fastcall FUN_00474ca0(int *param_1)

{
  int iVar1;
  float10 fVar2;
  
  PhysicsSystem__ComputeAuxiliaries();
  iVar1 = FUN_0047ac00(param_1[0xb],param_1 + 0x10,param_1 + 0x11);
  fVar2 = (float10)FUN_00476240(param_1[7]);
  if ((iVar1 != 0) || ((float10)0.0 < fVar2)) {
    PhysicsSystem__ComputeAuxiliaries();
  }
  if (param_1[0x11] == 2) {
    *(undefined4 *)(param_1[7] + 300) = 0x3f800000;
  }
                    /* WARNING: Could not recover jumptable at 0x00474d06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// ==== 0x474d10 FUN_00474d10

void __fastcall FUN_00474d10(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))();
  FUN_00462f90(0);
  FUN_00474dd0();
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_0042a860();
  }
  return;
}


// ==== 0x474d40 FUN_00474d40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00474d40(int param_1,float param_2)

{
  float fVar1;
  
  if (DAT_006ffe54 == 0) {
    param_2 = _K_ONE;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x28) + 8) = *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x404);
  *(float *)(*(int *)(param_1 + 0x28) + 0xc) = _K_ONE - *(float *)(*(int *)(param_1 + 0x34) + 0x47c)
  ;
  *(float *)(*(int *)(param_1 + 0x20) + 0x1e8) = param_2;
  fVar1 = param_2;
  if ((30.0 < *(float *)(*(int *)(param_1 + 0x34) + 0x3d0) * 2.237) &&
     (*(int *)(*(int *)(param_1 + 0x34) + 0x400) == 1)) {
    fVar1 = param_2 * 1.0;
  }
  *(float *)(*(int *)(param_1 + 0x24) + 0x13c) = fVar1;
  *(float *)(*(int *)(param_1 + 0x24) + 0x138) = param_2;
  return;
}


// ==== 0x474dd0 FUN_00474dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00474dd0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  float *extraout_ECX;
  float *extraout_ECX_00;
  float10 fVar7;
  
  if (*(int *)(*(int *)(in_EAX + 0x34) + 0x38) != 1) {
    iVar3 = *(int *)(*(int *)(in_EAX + 0x34) + 0x3cc);
    if (iVar3 < 2) {
      iVar4 = *(int *)(in_EAX + 0x20);
      fVar7 = (float10)LinearTable__Lookup11
                                 (&PTR_DAT_00705e98,
                                  SQRT(*(float *)(iVar4 + 200) * *(float *)(iVar4 + 200) +
                                       *(float *)(iVar4 + 0xc4) * *(float *)(iVar4 + 0xc4) +
                                       *(float *)(iVar4 + 0xc0) * *(float *)(iVar4 + 0xc0)));
      fVar7 = -(fVar7 * (float10)*(float *)(iVar4 + 0x144));
      *(float *)(iVar4 + 0x120) =
           (float)(fVar7 * (float10)*(float *)(iVar4 + 0xc0) + (float10)*(float *)(iVar4 + 0x120));
      *(float *)(iVar4 + 0x124) =
           (float)((float10)*(float *)(iVar4 + 0xc4) * fVar7) + *(float *)(iVar4 + 0x124);
      *(float *)(iVar4 + 0x128) =
           (float)((float10)*(float *)(iVar4 + 200) * fVar7) + *(float *)(iVar4 + 0x128);
    }
    if ((iVar3 == 0) && (iVar3 = *(int *)(in_EAX + 0x34), 0.1 < *(float *)(iVar3 + 0xb8))) {
      fVar1 = *(float *)(iVar3 + 0x70);
      fVar2 = *(float *)(iVar3 + 0x74);
      fVar5 = SQRT(fVar1 * fVar1 + fVar2 * fVar2);
      if (_K_EPS_SPEED < fVar5) {
        fVar5 = _K_ONE / fVar5;
        FUN_00567540();
        fVar6 = ((fVar1 * fVar5 * *extraout_ECX +
                 fVar5 * 0.0 * extraout_ECX[2] + fVar2 * fVar5 * extraout_ECX[1]) - _K_ONE) *
                *(float *)(*(int *)(in_EAX + 0x20) + 0x144) * 100.0;
        if (_K_EPS_SPEED <= fVar6) {
          FUN_005673e0(fVar6);
        }
        FUN_00584e00();
        FUN_00567540();
        bNormalize3();
        FUN_00567540();
        fVar1 = ((fVar1 * fVar5 * *extraout_ECX_00 +
                 fVar5 * 0.0 * extraout_ECX_00[2] + fVar2 * fVar5 * extraout_ECX_00[1]) - _K_ONE) *
                *(float *)(*(int *)(in_EAX + 0x20) + 0x144) * 100.0;
        if (_K_EPS_SPEED <= fVar1) {
          FUN_005673e0(fVar1);
          FUN_00584e00();
          return;
        }
        FUN_00584e00();
        return;
      }
    }
  }
  return;
}


// ==== 0x475070 Mellovator::Mellovator

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 *
Mellovator__Mellovator
          (undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  char *pcVar5;
  uint uVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006854b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c847c;
  fVar2 = *(float *)(param_2 + 0x1f8);
  fVar3 = *(float *)(param_2 + 0x1f0);
  param_1[0x56] = fVar3;
  param_1[0x55] = 9;
  param_1[0x57] = fVar2;
  param_1[0x59] = param_2 + 0x200;
  local_4 = 0;
  param_1[0x58] = K_ONE / (fVar2 - fVar3);
  fVar2 = *(float *)(param_2 + 0x1f8);
  fVar3 = *(float *)(param_2 + 0x1f0);
  param_1[0x5e] = param_2 + 0x248;
  param_1[0x5b] = fVar3;
  param_1[0x5a] = 3;
  param_1[0x5c] = fVar2;
  param_1[0x5d] = 2.0 / (fVar2 - fVar3);
  fVar2 = *(float *)(param_2 + 500);
  fVar3 = *(float *)(param_2 + 0x1f0);
  param_1[0x5f] = 9;
  param_1[0x60] = fVar3;
  param_1[99] = &DAT_006fff34;
  param_1[0x61] = fVar2;
  param_1[0x62] = K_ONE / (fVar2 - fVar3);
  param_1[0x78] = 0;
  param_1[6] = param_2;
  FUN_0046d1c0(param_2 + 0x1b0,param_1 + 0x66);
  uVar6 = (uint)(0.2 <= *(float *)(param_2 + 0x1c0));
  if (0.8 < *(float *)(param_2 + 0x1c0)) {
    uVar6 = 2;
  }
  fVar2 = *(float *)(&DAT_006f101c + uVar6 * 0x6c);
  param_1[8] = param_5;
  param_1[7] = param_4;
  pcVar1 = (char *)(param_1 + 3);
  param_1[0x67] = fVar2 * (float)param_1[0x67];
  param_1[5] = param_3;
  param_1[0x49] = 2;
  param_1[0x4e] = 0x3f800000;
  param_1[100] = 0x411ccccd;
  param_1[0x65] = 0;
  *pcVar1 = 'M';
  pcVar5 = pcVar1;
  do {
    cVar4 = pcVar5[(int)("Melov8r" + (1 - (int)pcVar1))];
    pcVar5 = pcVar5 + 1;
    *pcVar5 = cVar4;
  } while (cVar4 != '\0');
  param_1[0x78] = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x475240 FUN_00475240

void FUN_00475240(void)

{
  int in_EAX;
  char cVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  int local_8;
  int local_4;
  
  FUN_00571ea0(0,"Mellovator");
  FUN_00571c20(unaff_ESI,in_EAX + 0x24,0x10,0xffffffff,0);
  local_4 = in_EAX + 0xe0;
  local_8 = in_EAX + 0x94;
  iVar2 = 0;
  iVar3 = in_EAX + 0x44;
  do {
    FUN_00571c20(unaff_ESI,iVar3 + -0x10,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,iVar3,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,iVar3 + 0x10,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,iVar3 + 0x20,1,4,0);
    FUN_00571c20(unaff_ESI,local_8 + -0x20,8,0xffffffff,0);
    FUN_00571c20(unaff_ESI,local_8,8,0xffffffff,0);
    FUN_00571c20(unaff_ESI,in_EAX + 0xb4 + iVar2,1,1,0);
    FUN_00571c20(unaff_ESI,iVar3 + 0x74,1,4,0);
    FUN_00571c20(unaff_ESI,iVar3 + 0x84,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,local_4,0xc,0xffffffff,0);
    iVar2 = iVar2 + 1;
    local_4 = local_4 + 0x10;
    local_8 = local_8 + 8;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 4);
  FUN_00571c20(unaff_ESI,in_EAX + 0x120,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x124,1,4,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0x128,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 300,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x130,2,2,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x134,1,4,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0x138,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x13c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x140,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 400,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x194,4,4,0);
  iVar3 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar3 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar3 + 0xc);
  cVar1 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x475460 FUN_00475460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475460(float param_1)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  
  pfVar2 = *(float **)(in_EAX + 0x18);
  fVar1 = *pfVar2;
  if (DAT_006ffde4 == 0) {
    fVar1 = 0.0;
  }
  fVar1 = ((pfVar2[4] - fVar1) / ((pfVar2[4] - fVar1) - (pfVar2[0x28] - fVar1))) * _K_HALF;
  fVar4 = param_1 * pfVar2[0x9b] +
          *(float *)(*(int *)(in_EAX + 0x14) + 0x144) * *(float *)(in_EAX + 400);
  fVar3 = fVar4 * (_K_HALF - fVar1);
  *(float *)(in_EAX + 0x144) = fVar3;
  *(float *)(in_EAX + 0x148) = fVar3;
  fVar1 = fVar1 * fVar4;
  *(float *)(in_EAX + 0x14c) = fVar1;
  *(float *)(in_EAX + 0x150) = fVar1;
  return;
}


// ==== 0x4754e0 FUN_004754e0

void FUN_004754e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  *(undefined4 *)(in_EAX + 0x24) = param_1;
  *(undefined4 *)(in_EAX + 0x28) = param_2;
  *(undefined4 *)(in_EAX + 0x2c) = param_3;
  *(undefined4 *)(in_EAX + 0x30) = param_4;
  puVar1 = (undefined4 *)(in_EAX + 0x34);
  iVar2 = 4;
  do {
    puVar1[0x21] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x475530 FUN_00475530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00475530(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float local_20;
  float *local_1c;
  float local_14;
  float *local_10;
  float local_c;
  
  local_10 = (float *)(param_1 + 0x74);
  local_1c = (float *)(param_1 + 0x24);
  iVar7 = 0;
  do {
    fVar8 = (float10)0.0;
    local_20 = *(float *)(*(int *)(param_1 + 0x18) + 0x1c0);
    if (iVar7 < 2) {
      local_20 = _K_ONE - local_20;
    }
    if (local_1c[0x25] == 0.0) {
      fVar2 = *(float *)(param_1 + 0x120) / *(float *)(param_1 + 0x138);
      fVar8 = (float10)FUN_00583ea0(fVar2);
      fVar1 = *(float *)(param_1 + 0x128);
      fVar9 = (float10)FUN_00583ea0(fVar2);
      fVar8 = (float10)(float)(fVar8 * (float10)fVar1) -
              ((float10)_K_ONE - (float10)*(float *)(param_1 + 0x128)) * fVar9;
      if (*(int *)(param_1 + 0x194) != 0) {
        fVar9 = (float10)FUN_00583ea0(fVar2);
        fVar8 = fVar9 * (float10)*(float *)(*(int *)(param_1 + 0x18) + 0x2ac) +
                (float10)(float)fVar8;
      }
      if ((*(float *)(param_1 + 0x128) < 0.05) &&
         (*(float *)(param_1 + 0x120) == *(float *)(*(int *)(param_1 + 0x18) + 0x1f0))) {
        fVar8 = (float10)0.0;
      }
      fVar1 = *(float *)(*(int *)(param_1 + 0x18) + 0x1b8 + (uint)(iVar7 < 2) * 4);
      fVar2 = *(float *)(*(int *)(param_1 + 0x18) + 0x1d0 + *(int *)(param_1 + 0x124) * 4);
      fVar4 = *local_1c;
      fVar9 = (float10)_K_HALF;
      if (fVar4 <= K_BLUR_W_MUL) {
        fVar4 = -20.0;
      }
      else if (20.0 < fVar4) {
        fVar4 = 20.0;
      }
      fVar3 = *(float *)(param_1 + 300);
      local_c = 1.25;
      local_14 = 1.0;
      if (_K_ONE < *(float *)(param_1 + 0x138)) {
        fVar6 = *(float *)(param_1 + 0x138) - _K_ONE;
        local_14 = (fVar6 * 3.0 + _K_ONE) * 1.0;
        local_c = (fVar6 * 2.5 + _K_ONE) * 1.25;
      }
      iVar5 = *(int *)(param_1 + 0x14);
      fVar10 = (float10)LinearTable__Lookup11
                                  (&PTR_DAT_00705e78,
                                   SQRT(*(float *)(iVar5 + 0xa8) * *(float *)(iVar5 + 0xa8) +
                                        *(float *)(iVar5 + 0xa4) * *(float *)(iVar5 + 0xa4) +
                                        *(float *)(iVar5 + 0xa0) * *(float *)(iVar5 + 0xa0)));
      if (0.0 < local_20) {
        fVar10 = (fVar10 / ((float10)local_c * (float10)local_14)) * (float10)local_20;
      }
      fVar8 = ((float10)local_14 *
               (float10)(float)((float10)fVar1 * (float10)fVar2 * fVar8 * (float10)local_20 * fVar9)
              + (float10)(fVar3 * 2.5 * fVar4 * -0.2)) - fVar10 * (float10)*local_10;
    }
    iVar7 = iVar7 + 1;
    local_1c = local_1c + 1;
    *(float *)(param_2 + -4 + iVar7 * 4) = (float)(fVar8 / (float10)0.008);
    local_10 = local_10 + 2;
  } while (iVar7 < 4);
  return param_2;
}


// ==== 0x4757d0 FUN_004757d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004757d0(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  FUN_00475a00(param_1);
  puVar5 = (undefined4 *)(param_1 + 0xb8);
  iVar6 = 4;
  do {
    if ((0.95 < *(float *)(param_1 + 300)) && (ABS((float)puVar5[-0x25]) < 30.0)) {
      *puVar5 = 1;
      puVar5[-0x25] = 0;
    }
    if (*(float *)(param_1 + 300) < 0.2) {
      *puVar5 = 0;
    }
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = *(int *)(param_1 + 0x18);
  if (0.2 <= *(float *)(iVar6 + 0x1c0)) {
    if (*(float *)(iVar6 + 0x1c0) <= 0.8) {
      fVar3 = ((*(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x2c)) * *(float *)(iVar6 + 0x1bc)
               * _K_HALF * 9.549304 +
              (*(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x24)) * *(float *)(iVar6 + 0x1b8)
              * _K_HALF * 9.549304) * _K_HALF;
    }
    else {
      fVar3 = (*(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x2c)) * *(float *)(iVar6 + 0x1bc)
              * _K_HALF * 9.549304;
    }
  }
  else {
    fVar3 = (*(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x24)) * *(float *)(iVar6 + 0x1b8) *
            _K_HALF * 9.549304;
  }
  fVar2 = fVar3 * *(float *)(iVar6 + 0x1d0 + *(int *)(param_1 + 0x124) * 4);
  if (*(int *)(param_1 + 0x134) == -1) {
    if (*(int *)(param_1 + 0x124) < 2) {
      *(undefined4 *)(param_1 + 0x124) = 2;
    }
    if (*(int *)(param_1 + 0x124) + -1 < *(int *)(iVar6 + 0x1c8)) {
      do {
        iVar4 = *(int *)(param_1 + 0x124);
        if (fVar2 <= *(float *)(param_1 + 0x198 + iVar4 * 4)) break;
        *(int *)(param_1 + 0x124) = iVar4 + 1;
        fVar2 = fVar3 * *(float *)(iVar6 + 0x1d0 + (iVar4 + 1) * 4);
      } while (iVar4 < *(int *)(iVar6 + 0x1c8));
    }
    iVar4 = *(int *)(param_1 + 0x124) + -1;
    while ((1 < iVar4 &&
           (iVar1 = *(int *)(param_1 + 0x124), fVar2 < *(float *)(param_1 + 0x1bc + iVar1 * 4)))) {
      iVar4 = iVar1 + -2;
      *(int *)(param_1 + 0x124) = iVar1 + -1;
      fVar2 = fVar3 * *(float *)(iVar6 + 0x1d0 + (iVar1 + -1) * 4);
    }
  }
  else if (*(int *)(param_1 + 0x134) == 0) {
    *(undefined4 *)(param_1 + 0x124) = 0;
    fVar2 = fVar3 * *(float *)(iVar6 + 0x1d0);
  }
  if (fVar2 < *(float *)(iVar6 + 0x1f0)) {
    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(iVar6 + 0x1f0);
    return;
  }
  if (*(float *)(iVar6 + 0x1f8) < fVar2) {
    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(iVar6 + 0x1f8);
    return;
  }
  *(float *)(param_1 + 0x120) = fVar2;
  return;
}


// ==== 0x475a00 FUN_00475a00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475a00(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float *local_6c;
  float local_60 [6];
  float local_48 [17];
  
  FUN_00475bf0(param_1);
  local_6c = local_48;
  pfVar7 = (float *)(param_1 + 0xe4);
  iVar9 = 0;
  iVar8 = 0;
  pfVar6 = (float *)(param_1 + 0x34);
  do {
    iVar2 = *(int *)(param_1 + 0x14);
    fVar5 = pfVar7[-1] * *(float *)(iVar2 + 0x50) +
            *(float *)(iVar2 + 0x54) * *pfVar7 + pfVar7[1] * *(float *)(iVar2 + 0x58);
    if (0.001 <= fVar5) {
      fVar5 = (local_60[iVar9] - *local_6c) / fVar5;
    }
    else {
      fVar5 = -100.0;
    }
    fVar3 = *pfVar6;
    fVar5 = fVar5 + *(float *)(iVar8 + 0x20 + *(int *)(param_1 + 0x18));
    pfVar1 = (float *)((iVar9 / 2) * 0x20 + 0x170 + *(int *)(param_1 + 0x18));
    if (pfVar1[6] <= fVar5) {
      if (fVar5 <= pfVar1[5]) {
        *pfVar6 = fVar5;
        pfVar6[0x25] = 0.0;
      }
      else {
        *pfVar6 = pfVar1[5];
        pfVar6[0x25] = fVar5 - *pfVar6;
      }
      pfVar6[0xc] = 1.4013e-45;
    }
    else {
      *pfVar6 = pfVar1[6];
      pfVar6[0xc] = 0.0;
      pfVar6[0x25] = 0.0;
    }
    fVar5 = _DAT_006f0738;
    if (_DAT_006f0738 <= 0.0001) {
      fVar5 = 0.0001;
    }
    fVar4 = *pfVar6;
    fVar5 = (*pfVar6 - fVar3) / fVar5;
    pfVar6[4] = fVar5;
    fVar3 = 0.0;
    if (pfVar6[0xc] != 0.0) {
      fVar3 = fVar4;
      if (fVar4 <= 0.0) {
        fVar3 = 0.0;
      }
      fVar3 = (fVar4 - *(float *)(param_1 + 0x34 + (&DAT_006fff14)[iVar9] * 4)) * pfVar1[4] +
              (fVar3 * *pfVar1 + _K_ONE) * pfVar1[1] * fVar4 + fVar5 * pfVar1[(fVar5 <= 0.0) + 2] +
              pfVar6[0x44];
      if (fVar3 < 0.0) {
        fVar3 = 0.0;
      }
    }
    pfVar6[8] = fVar3;
    pfVar7 = pfVar7 + 4;
    local_6c = local_6c + 4;
    iVar8 = iVar8 + 0x30;
    iVar9 = iVar9 + 1;
    pfVar6 = pfVar6 + 1;
  } while (iVar8 < 0xc0);
  return;
}


// ==== 0x475bf0 FUN_00475bf0

void __fastcall FUN_00475bf0(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  int local_54;
  float *local_4c;
  float local_30;
  float local_2c;
  float local_28;
  float local_18;
  
  uVar3 = *(undefined4 *)(param_3 + 0x1c);
  iVar4 = *(int *)(param_3 + 0x14);
  local_54 = param_3 + 0xe0;
  iVar6 = 0;
  local_4c = param_1;
  do {
    pfVar5 = *(float **)(param_3 + 0x18);
    local_30 = -*pfVar5 + *(float *)(iVar6 + 0x10 + (int)pfVar5);
    local_2c = *(float *)(iVar6 + 0x14 + (int)pfVar5) + -pfVar5[1];
    local_28 = *(float *)(iVar6 + 0x18 + (int)pfVar5) + -pfVar5[2];
    local_18 = local_28;
    D3DXVec3Transform(param_2,&local_30,*(int *)(param_3 + 0x14) + 0x30);
    fVar1 = *(float *)(iVar4 + 0x24);
    fVar2 = *(float *)(iVar4 + 0x28);
    *param_2 = *(float *)(iVar4 + 0x20) + *param_2;
    param_2[1] = fVar1 + param_2[1];
    param_2[2] = fVar2 + param_2[2];
    fVar7 = (float10)GroundQuery__FindSurfaceBelow(uVar3,param_2,0,local_54,0);
    fVar7 = (float10)FUN_00577060(*(undefined4 *)(param_3 + 0x20),uVar3,(float)fVar7,param_2,0,
                                  local_54,0);
    *local_4c = (float)fVar7;
    iVar6 = iVar6 + 0x30;
    local_54 = local_54 + 0x10;
    local_4c = local_4c + 1;
    param_2 = param_2 + 4;
  } while (iVar6 < 0xc0);
  return;
}


// ==== 0x475d00 FUN_00475d00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00475d00(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float10 fVar9;
  float *pfStack_e0;
  undefined1 *puStack_dc;
  float *pfStack_d8;
  float *local_d4;
  int local_cc;
  float *local_c8;
  float *local_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  undefined4 uStack_b0;
  float fStack_ac;
  float fStack_a8;
  int local_a4;
  float fStack_a0;
  float local_8c;
  float local_88;
  undefined1 local_80 [16];
  float local_70;
  float local_6c;
  float local_68;
  float local_58;
  float local_50 [19];
  
  iVar6 = 0;
  local_d4 = local_50;
  pfVar7 = (float *)(param_1 + 0x54);
  local_cc = param_1 + 0xe8;
  local_c8 = (float *)(param_1 + 0x78);
  local_a4 = 0;
  do {
    pfVar3 = *(float **)(param_1 + 0x18);
    local_8c = -pfVar3[1];
    local_88 = -pfVar3[2];
    local_70 = -*pfVar3 + *(float *)((int)pfVar3 + iVar6 + 0x10);
    local_6c = *(float *)((int)pfVar3 + iVar6 + 0x14) + local_8c;
    local_68 = *(float *)((int)pfVar3 + iVar6 + 0x18) + local_88;
    local_c4 = pfVar7;
    local_58 = local_68;
    D3DXVec3Transform(local_80,&local_70,*(int *)(param_1 + 0x14) + 0x30);
    *puStack_dc = 0;
    if (pfVar7[4] == 0.0) {
      *pfStack_e0 = 0.0;
      pfStack_e0[1] = 0.0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x14);
      fStack_b8 = *(float *)(iVar4 + 0xa0) - local_88 * *(float *)(iVar4 + 200);
      fStack_b4 = local_8c * *(float *)(iVar4 + 200) + *(float *)(iVar4 + 0xa4);
      Atan2ToAngle16(*(undefined4 *)(iVar4 + 0x30),*(undefined4 *)(iVar4 + 0x34));
      _ftol_nocw();
      fVar8 = (float10)FUN_00564b10();
      _ftol_nocw();
      fVar9 = (float10)FUN_00564b10();
      fStack_a0 = (float)((float10)(float)fVar8 * (float10)fStack_b4 - fVar9 * (float10)fStack_b8);
      fVar1 = *(float *)(iVar6 + 0x20 + *(int *)(param_1 + 0x18));
      fVar2 = pfVar7[-0xc];
      local_d4[8] = fStack_a0;
      fVar9 = ((float10)(float)fVar8 * (float10)fStack_b8 + fVar9 * (float10)fStack_b4) -
              (float10)fVar1 * (float10)fVar2;
      local_d4[7] = (float)fVar9;
      fVar8 = (float10)_K_ONE;
      fVar1 = (float)SQRT((float10)fStack_a0 * (float10)fStack_a0 + fVar9 * fVar9);
      if (*(float *)(param_1 + 0x13c) * 0.05 < fVar1) {
        fVar8 = (float10)*(float *)(param_1 + 0x140) * (float10)*(float *)(param_1 + 0x13c);
      }
      if (*pfStack_d8 < 0.5) {
        fVar8 = fVar8 * (float10)1.0;
      }
      fVar2 = (float)(*(int *)(param_1 + 0x1e0) - DAT_0073ad34) * 0.00025;
      fVar5 = _K_ONE;
      if ((_K_ONE < fVar2) || (fVar5 = fVar2, 0.0 < fVar2)) {
        uStack_b0 = 1;
        fVar8 = ((float10)fVar5 * (float10)-0.6 + (float10)_K_ONE) * fVar8;
      }
      if (6.0 < fVar1) {
        *puStack_dc = 1;
      }
      fStack_ac = (float)-((float10)1.25 * fVar8 * (float10)*pfVar7 * fVar9);
      fStack_a8 = (float)-(fVar8 * (float10)*pfVar7 * (float10)1.25 * (float10)fStack_a0);
      _ftol_nocw();
      fVar8 = (float10)FUN_00564b10();
      _ftol_nocw();
      fVar9 = (float10)FUN_00564b10();
      *pfStack_e0 = (float)((float10)fStack_ac * (float10)(float)fVar8 - (float10)fStack_a8 * fVar9)
      ;
      pfStack_e0[1] =
           (float)((float10)fStack_a8 * (float10)(float)fVar8 + (float10)fStack_ac * fVar9);
    }
    iVar4 = *(int *)(param_1 + 0x14);
    pfStack_e0[2] = *pfVar7;
    D3DXVec3Transform(&local_cc,pfStack_e0,iVar4 + 0x30);
    if (pfVar7[4] != 0.0) {
      puStack_dc = (undefined1 *)SQRT(fStack_c0 * fStack_c0 + fStack_bc * fStack_bc);
      pfStack_d8 = (float *)(*pfVar7 * 4.0 * *(float *)(param_1 + 0x13c));
      if ((float)pfStack_d8 < (float)puStack_dc) {
        fStack_c0 = ((float)pfStack_d8 / (float)puStack_dc) * fStack_c0;
        fStack_bc = ((float)pfStack_d8 / (float)puStack_dc) * fStack_bc;
      }
      fVar2 = *(float *)(param_1 + 0x138) - _K_ONE;
      fVar1 = _K_ONE;
      if (0.0 < fVar2) {
        fVar1 = fVar2 * 2.5 + _K_ONE;
      }
      fStack_c0 = fStack_c0 * fVar1;
      fStack_bc = fStack_bc * fVar1;
      if ((pfVar7[0x19] != 0.0) ||
         ((0.4 < *(float *)(param_1 + 300) &&
          (iVar4 = *(int *)(param_1 + 0x14),
          SQRT(*(float *)(iVar4 + 0xa8) * *(float *)(iVar4 + 0xa8) +
               *(float *)(iVar4 + 0xa4) * *(float *)(iVar4 + 0xa4) +
               *(float *)(iVar4 + 0xa0) * *(float *)(iVar4 + 0xa0)) < 0.1)))) {
        iVar4 = *(int *)(param_1 + 0x14);
        fVar1 = *pfVar7 / *(float *)(iVar4 + 0x58);
        fStack_c0 = -(fVar1 * *(float *)(iVar4 + 0x50)) + fStack_c0;
        fStack_bc = -(fVar1 * *(float *)(iVar4 + 0x54)) + fStack_bc;
      }
      else if ((float)puStack_dc < (float)pfStack_d8) {
        iVar4 = *(int *)(param_1 + 0x14);
        fVar1 = *pfVar7 / *(float *)(iVar4 + 0x58);
        fStack_c0 = -(ABS(*(float *)(iVar4 + 0x40)) * *(float *)(iVar4 + 0x50) * fVar1) + fStack_c0;
        fStack_bc = -(ABS(*(float *)(iVar4 + 0x44)) * *(float *)(iVar4 + 0x54) * fVar1) + fStack_bc;
      }
    }
    if (local_a4 != 0) {
      fStack_c0 = 0.0;
      fStack_bc = 0.0;
    }
    FUN_00584cd0();
    local_c8[-1] = *local_d4;
    *local_c8 = local_d4[1];
    fVar1 = SQRT(local_c8[-1] * local_c8[-1] + *local_c8 * *local_c8);
    if (50.0 < fVar1) {
      fVar1 = 50.0 / fVar1;
      local_c8[-1] = fVar1 * local_c8[-1];
      *local_c8 = *local_c8 * fVar1;
    }
    pfVar7 = local_c4 + 1;
    iVar6 = iVar6 + 0x30;
    local_cc = local_cc + 0x10;
    local_d4 = local_d4 + 4;
    local_c8 = local_c8 + 2;
  } while (iVar6 < 0xc0);
  return;
}


// ==== 0x476240 FUN_00476240

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00476240(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int in_EAX;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  float local_ac;
  float *local_a8;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float local_7c;
  float local_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_5c;
  float fStack_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_38;
  float fStack_28;
  float fStack_20;
  
  iVar5 = 0;
  local_a8 = (float *)(in_EAX + 0x2f0);
  pfVar4 = (float *)(param_1 + 0x34);
  local_ac = 0.0;
  pfVar6 = (float *)(param_1 + 0xe8);
  do {
    if (0.0 < pfVar4[0x25]) {
      pfVar1 = *(float **)(param_1 + 0x18);
      local_7c = -pfVar1[1];
      local_78 = -pfVar1[2];
      local_50 = -*pfVar1 + *(float *)(iVar5 + 0x10 + (int)pfVar1);
      local_4c = *(float *)(iVar5 + 0x14 + (int)pfVar1) + local_7c;
      local_38 = *(float *)(iVar5 + 0x18 + (int)pfVar1) + local_78;
      local_48 = local_38 + *pfVar4;
      D3DXVec3Transform(&local_90,&local_50,*(int *)(param_1 + 0x14) + 0x30);
      iVar2 = *(int *)(param_1 + 0x14);
      fStack_5c = local_90 * *(float *)(iVar2 + 200) - fStack_88 * *(float *)(iVar2 + 0xc0);
      fStack_58 = fStack_8c * *(float *)(iVar2 + 0xc0) - local_90 * *(float *)(iVar2 + 0xc4);
      fStack_20 = (fStack_88 * *(float *)(iVar2 + 0xc4) - fStack_8c * *(float *)(iVar2 + 200)) +
                  *(float *)(iVar2 + 0xa0);
      fStack_28 = *(float *)(iVar2 + 0xa8) + fStack_58;
      fVar3 = -(pfVar6[-2] * fStack_20 +
               pfVar6[-1] * (*(float *)(iVar2 + 0xa4) + fStack_5c) + *pfVar6 * fStack_28);
      if (0.0 < fVar3) {
        fVar3 = _DAT_006f073c * fVar3 * *(float *)(iVar2 + 0x144);
        fStack_70 = pfVar6[-2] * fVar3;
        fStack_6c = pfVar6[-1] * fVar3;
        fStack_68 = *pfVar6 * fVar3;
        FUN_00584e30();
        *local_a8 = fVar3 + *local_a8;
        local_ac = fVar3 + local_ac;
      }
    }
    pfVar4 = pfVar4 + 1;
    local_a8 = local_a8 + 1;
    iVar5 = iVar5 + 0x30;
    pfVar6 = pfVar6 + 4;
  } while (iVar5 < 0xc0);
  return (float10)local_ac;
}


// ==== 0x476450 FUN_00476450

void FUN_00476450(void)

{
  FUN_00474400();
  return;
}


// ==== 0x476460 FUN_00476460

undefined4 __fastcall FUN_00476460(int param_1)

{
  return *(undefined4 *)(param_1 + 0x74);
}


// ==== 0x476470 FUN_00476470

undefined4 * __thiscall FUN_00476470(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c8338;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x476490 FUN_00476490

void FUN_00476490(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c8338;
  return;
}


// ==== 0x4764a0 FUN_004764a0

undefined2 __fastcall FUN_004764a0(int param_1)

{
  return *(undefined2 *)(param_1 + 0x90);
}


// ==== 0x4764b0 FUN_004764b0

undefined4 * __thiscall FUN_004764b0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00476490();
  iVar2 = DAT_00735f70;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f70 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f70 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x4764e0 FUN_004764e0

void FUN_004764e0(void)

{
  undefined4 *puVar1;
  
  DAT_00735f6c = (undefined4 *)FUN_00566dc0(0x1f0,"RigidBodySlotPool",0);
  if ((DAT_00735f6c != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f6c;
    puVar1 = DAT_00735f6c;
    DAT_00735f6c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f6c = &DAT_0073d818;
  }
  DAT_00735f70 = (undefined4 *)FUN_00566dc0(0xa0,"TwoWheelAckermanSteeringSlotPool",0);
  if ((DAT_00735f70 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f70;
    puVar1 = DAT_00735f70;
    DAT_00735f70[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f70 = &DAT_0073d818;
  }
  DAT_00735f74 = (undefined4 *)FUN_00566dc0(400,"WheelSlotPool",0);
  if ((DAT_00735f74 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f74;
    puVar1 = DAT_00735f74;
    DAT_00735f74[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f74 = &DAT_0073d818;
  }
  DAT_00735f78 = (undefined4 *)FUN_00566dc0(0xc0,"EngineSlotPool",0);
  if ((DAT_00735f78 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f78;
    puVar1 = DAT_00735f78;
    DAT_00735f78[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f78 = &DAT_0073d818;
  }
  DAT_00735f7c = (undefined4 *)FUN_00566dc0(0xe8,"DriveTrainSlotPool",0);
  if ((DAT_00735f7c != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f7c;
    puVar1 = DAT_00735f7c;
    DAT_00735f7c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f7c = &DAT_0073d818;
  }
  DAT_00735f80 = (undefined4 *)FUN_00566dc0(0x40,"AerodynamicsSlotPool",0);
  if ((DAT_00735f80 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f80;
    puVar1 = DAT_00735f80;
    DAT_00735f80[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f80 = &DAT_0073d818;
  }
  DAT_00735f84 = (undefined4 *)FUN_00566dc0(0xc0,"SuspensionSlotPool",0);
  if ((DAT_00735f84 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f84;
    puVar1 = DAT_00735f84;
    DAT_00735f84[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f84 = &DAT_0073d818;
  }
  DAT_00735f88 = (undefined4 *)FUN_00566dc0(0x1f0,"MellovatorSlotPool",0);
  if ((DAT_00735f88 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f88;
    puVar1 = DAT_00735f88;
    DAT_00735f88[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f88 = &DAT_0073d818;
  }
  DAT_00735f8c = (undefined4 *)FUN_00566dc0(0x50,"MellowMoverSlotPool",0);
  if ((DAT_00735f8c != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735f8c;
    puVar1 = DAT_00735f8c;
    DAT_00735f8c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f8c = &DAT_0073d818;
  }
  DAT_00735f90 = (undefined4 *)FUN_00566dc0(0xc,"NullMoverSlotPool",0);
  if (DAT_00735f90 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_00735f90;
    puVar1 = DAT_00735f90;
    DAT_00735f90[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735f90 = &DAT_0073d818;
  }
  return;
}


// ==== 0x476760 FUN_00476760

void FUN_00476760(void)

{
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  DAT_00735f6c = 0;
  DAT_00735f70 = 0;
  DAT_00735f74 = 0;
  DAT_00735f78 = 0;
  DAT_00735f7c = 0;
  DAT_00735f80 = 0;
  DAT_00735f84 = 0;
  DAT_00735f88 = 0;
  DAT_00735f8c = 0;
  DAT_00735f90 = 0;
  return;
}


// ==== 0x476840 PhysicsMover::PhysicsMover

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * __fastcall
PhysicsMover__PhysicsMover
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4,int param_5,
          int param_6)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iStack_18;
  int iStack_14;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068646b;
  pvStack_c = ExceptionList;
  piVar1 = param_3 + 2;
  puVar9 = param_3 + 5;
  ExceptionList = &pvStack_c;
  *puVar9 = puVar9;
  param_3[6] = puVar9;
  param_3[7] = 0;
  *piVar1 = (int)&PTR_FUN_006c84a0;
  *param_3 = &PTR_LAB_006c8364;
  *piVar1 = (int)&PTR_FUN_006c8358;
  param_3[0x18] = 0;
  param_3[0x19] = 0;
  param_3[0x1c] = 0;
  param_3[0x17] = param_6;
  param_3[0x15] = param_4;
  pcVar2 = (char *)(param_3 + 3);
  param_3[1] = param_2;
  param_3[0x16] = param_6 + 0x40;
  param_3[0x1e] = 0x3f800000;
  local_4 = 1;
  *pcVar2 = 'P';
  pcVar6 = pcVar2;
  do {
    cVar3 = pcVar6[(int)("PhysMov" + (1 - (int)pcVar2))];
    pcVar6 = pcVar6 + 1;
    *pcVar6 = cVar3;
  } while (cVar3 != '\0');
  iVar7 = FUN_00567160();
  if (iVar7 == 0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)FUN_00584800();
  }
  param_3[8] = piVar8;
  if (piVar8 == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = piVar8 + 1;
  }
  puVar9 = (undefined4 *)param_3[6];
  *puVar9 = piVar11;
  param_3[6] = piVar11;
  piVar11[1] = (int)puVar9;
  *piVar11 = (int)(param_3 + 5);
  iVar7 = (**(code **)(*piVar8 + 4))();
  param_3[7] = param_3[7] + iVar7;
  *(undefined4 *)(param_3[8] + 0x1e4) = *(undefined4 *)(param_3[0x15] + 0x290);
  *(int *)(param_3[8] + 0x13c) = (int)*(char *)(param_5 + 0xd8);
  puVar9 = (undefined4 *)FUN_00567160();
  if (puVar9 == (undefined4 *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    puVar9[1] = param_3[0x15];
    *puVar9 = &PTR_FUN_006c8348;
    puVar9[2] = puVar9 + 4;
  }
  param_3[9] = puVar9;
  param_4 = param_3 + 0xe;
  iStack_18 = 0;
  iStack_14 = 0;
  do {
    iVar7 = DAT_00735f74;
    puVar9 = (undefined4 *)(DAT_00735f74 + 0x10);
    if ((*(int *)(DAT_00735f74 + 0x10) == 0) && ((*(byte *)(DAT_00735f74 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    puVar13 = (undefined4 *)*puVar9;
    iVar10 = *(int *)(iVar7 + 0x18) + 1;
    if (puVar13 == (undefined4 *)0x0) {
      iVar7 = 0;
    }
    else {
      uVar12 = *puVar13;
      if (*(int *)(iVar7 + 0x1c) < iVar10) {
        *(int *)(iVar7 + 0x1c) = iVar10;
      }
      *(int *)(iVar7 + 0x18) = iVar10;
      *puVar9 = uVar12;
      if (((*(byte *)(iVar7 + 0x14) & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, 0 < iVar7))
      {
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
      }
      iVar7 = param_3[0x15];
      iVar7 = FUN_005868e0(iStack_14 + 0x10 + iVar7,(iStack_18 / 2) * 0x20 + 0xd0 + iVar7,
                           iVar7 + 0x270);
    }
    iVar10 = DAT_00735f84;
    *param_4 = iVar7;
    if ((*(int *)(iVar10 + 0x10) == 0) && ((*(byte *)(iVar10 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    puVar9 = *(undefined4 **)(iVar10 + 0x10);
    iVar7 = *(int *)(iVar10 + 0x18) + 1;
    if (puVar9 == (undefined4 *)0x0) {
      iVar7 = 0;
    }
    else {
      uVar12 = *puVar9;
      if (*(int *)(iVar10 + 0x1c) < iVar7) {
        *(int *)(iVar10 + 0x1c) = iVar7;
      }
      *(int *)(iVar10 + 0x18) = iVar7;
      *(undefined4 *)(iVar10 + 0x10) = uVar12;
      if (((*(byte *)(iVar10 + 0x14) & 2) != 0) && (iVar7 = *(int *)(iVar10 + 0x28) >> 2, 0 < iVar7)
         ) {
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
      }
      if (iStack_14 < 0x60) {
        uVar12 = param_3[9];
      }
      else {
        uVar12 = 0;
      }
      iVar7 = FUN_005883e0(*param_4,uVar12,(iStack_18 / 2) * 0x20 + 0x170 + param_3[0x15]);
    }
    param_4[-4] = iVar7;
    piVar8 = (int *)*param_4;
    if (piVar8 == (int *)0x0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = piVar8 + 1;
    }
    puVar9 = (undefined4 *)param_3[6];
    *puVar9 = piVar11;
    param_3[6] = piVar11;
    piVar11[1] = (int)puVar9;
    *piVar11 = (int)(param_3 + 5);
    iVar7 = (**(code **)(*piVar8 + 4))();
    param_3[7] = param_3[7] + iVar7;
    piVar8 = (int *)param_4[-4];
    if (piVar8 == (int *)0x0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = piVar8 + 1;
    }
    puVar9 = (undefined4 *)param_3[6];
    *puVar9 = piVar11;
    param_3[6] = piVar11;
    piVar11[1] = (int)puVar9;
    *piVar11 = (int)(param_3 + 5);
    iVar7 = (**(code **)(*piVar8 + 4))();
    iStack_14 = iStack_14 + 0x30;
    iStack_18 = iStack_18 + 1;
    param_4 = param_4 + 1;
    param_3[7] = param_3[7] + iVar7;
    iVar7 = DAT_00735f78;
  } while (iStack_14 < 0xc0);
  *(undefined4 *)(param_3[10] + 0x18) = param_3[0xb];
  *(undefined4 *)(param_3[0xb] + 0x18) = param_3[10];
  *(undefined4 *)(param_3[0xc] + 0x18) = param_3[0xd];
  *(undefined4 *)(param_3[0xd] + 0x18) = param_3[0xc];
  if ((*(int *)(iVar7 + 0x10) == 0) && ((*(byte *)(iVar7 + 0x14) & 1) != 0)) {
    FUN_00566e60();
  }
  puVar9 = *(undefined4 **)(iVar7 + 0x10);
  iVar10 = *(int *)(iVar7 + 0x18) + 1;
  if (puVar9 == (undefined4 *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    uVar12 = *puVar9;
    if (*(int *)(iVar7 + 0x1c) < iVar10) {
      *(int *)(iVar7 + 0x1c) = iVar10;
    }
    *(int *)(iVar7 + 0x18) = iVar10;
    *(undefined4 *)(iVar7 + 0x10) = uVar12;
    if (((*(byte *)(iVar7 + 0x14) & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, 0 < iVar7)) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
    piVar8 = (int *)FUN_0046c7c0(param_3[0x16]);
  }
  param_3[0x12] = piVar8;
  if (piVar8 == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = piVar8 + 1;
  }
  puVar9 = (undefined4 *)param_3[6];
  *puVar9 = piVar11;
  param_3[6] = piVar11;
  piVar11[1] = (int)puVar9;
  *piVar11 = (int)(param_3 + 5);
  iVar10 = (**(code **)(*piVar8 + 4))();
  iVar7 = DAT_00735f7c;
  param_3[7] = param_3[7] + iVar10;
  *(int *)(param_3[0x12] + 0x74) = (int)*(char *)(param_5 + 0xd8);
  if ((*(int *)(iVar7 + 0x10) == 0) && ((*(byte *)(iVar7 + 0x14) & 1) != 0)) {
    FUN_00566e60();
  }
  puVar9 = *(undefined4 **)(iVar7 + 0x10);
  iVar10 = *(int *)(iVar7 + 0x18) + 1;
  if (puVar9 != (undefined4 *)0x0) {
    uVar12 = *puVar9;
    if (*(int *)(iVar7 + 0x1c) < iVar10) {
      *(int *)(iVar7 + 0x1c) = iVar10;
    }
    *(int *)(iVar7 + 0x18) = iVar10;
    *(undefined4 *)(iVar7 + 0x10) = uVar12;
    if (((*(byte *)(iVar7 + 0x14) & 2) != 0) &&
       (iVar7 = *(int *)(iVar7 + 0x28) >> 2, puVar13 = puVar9, 0 < iVar7)) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
    }
  }
  local_4._0_1_ = 2;
  if (puVar9 == (undefined4 *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)DriveTrain__DriveTrain(puVar9,param_3[0x15] + 0x1b0,param_3 + 0xe,param_3[0x16])
    ;
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  param_3[0x13] = piVar8;
  if (piVar8 == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = piVar8 + 1;
  }
  puVar9 = (undefined4 *)param_3[6];
  *puVar9 = piVar11;
  param_3[6] = piVar11;
  *piVar11 = (int)(param_3 + 5);
  piVar11[1] = (int)puVar9;
  iVar7 = (**(code **)(*piVar8 + 4))();
  param_3[7] = param_3[7] + iVar7;
  iVar7 = *(int *)(param_6 + 0x10);
  if (*(char *)(iVar7 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  *(int *)(param_3[0x13] + 0xe0) = (int)*(char *)(iVar7 + 0x424);
  *(undefined4 *)(param_3[0x12] + 0x20) = param_3[0x13];
  iVar7 = DAT_007361a8;
  if ((*(int *)(*(int *)(param_6 + 0x14) + 4) == 1) &&
     (((DAT_0078a344 != '\0' || (DAT_007361a8 != 0)) && (DAT_00777b4c != 1)))) {
    *(undefined4 *)(param_3[0x13] + 0xd8) = *(undefined4 *)(&DAT_006b70e0 + DAT_0078a3fc * 4);
  }
  if ((*(int *)(*(int *)(param_6 + 0x14) + 4) == 2) && ((DAT_0078a344 != '\0' || (iVar7 != 0)))) {
    if (DAT_00777b4c != 1) {
      *(undefined4 *)(param_3[0x13] + 0xdc) = *(undefined4 *)(&DAT_006b70ec + DAT_0078a3fc * 4);
    }
    iVar7 = (**(code **)(**(int **)(param_6 + 0x2c) + 0x58))();
    if (iVar7 < 1) {
      iVar10 = 0;
    }
    else {
      iVar10 = iVar7;
      if (9 < iVar7) {
        iVar10 = 9;
      }
    }
    if (iVar7 == iVar10) {
      iVar10 = param_3[0x13];
      iVar7 = iVar7 * 0x54;
      uVar12 = *(undefined4 *)(&DAT_0077a028 + iVar7);
      *(undefined4 *)(iVar10 + 200) = *(undefined4 *)(&DAT_0077a024 + iVar7);
      *(undefined4 *)(iVar10 + 0xcc) = uVar12;
      iVar10 = param_3[0x13];
      uVar12 = *(undefined4 *)(&DAT_0077a020 + iVar7);
      *(undefined4 *)(iVar10 + 0xd0) = *(undefined4 *)(&DAT_0077a01c + iVar7);
      *(undefined4 *)(iVar10 + 0xd4) = uVar12;
    }
  }
  iVar7 = DAT_00735f80;
  piVar8 = (int *)(DAT_00735f80 + 0x10);
  if ((*(int *)(DAT_00735f80 + 0x10) == 0) && ((*(byte *)(DAT_00735f80 + 0x14) & 1) != 0)) {
    FUN_00566e60();
  }
  piVar11 = (int *)*piVar8;
  iVar10 = *(int *)(iVar7 + 0x18) + 1;
  if (piVar11 == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    iVar5 = *piVar11;
    if (*(int *)(iVar7 + 0x1c) < iVar10) {
      *(int *)(iVar7 + 0x1c) = iVar10;
    }
    *(int *)(iVar7 + 0x18) = iVar10;
    bVar4 = *(byte *)(iVar7 + 0x14);
    *piVar8 = iVar5;
    if (((bVar4 & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar8 = piVar11, 0 < iVar7)) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = 0;
        piVar8 = piVar8 + 1;
      }
    }
    iVar7 = param_3[8];
    *piVar11 = param_3[0x15] + 0x260;
    piVar11[2] = 0x3f800000;
    piVar11[3] = 0x3f800000;
    piVar11[1] = iVar7;
    piVar11[4] = 0;
    piVar11[5] = 0;
    *(undefined1 *)(piVar11 + 0xc) = 1;
  }
  param_3[0x14] = piVar11;
  _DAT_006f0738 = 0;
  param_3[0x1d] = 0;
  FUN_00477100();
  FUN_004782c0();
  if (param_3[5] == 0) goto LAB_00476efa;
  piVar8 = (int *)(param_3[5] + -4);
  while( true ) {
    if (param_3 == (undefined4 *)0xffffffec) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = param_3 + 4;
    }
    if (piVar8 == piVar11) break;
    (**(code **)(*piVar8 + 0x1c))();
    if (piVar8[1] == 0) {
LAB_00476efa:
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)(piVar8[1] + -4);
    }
  }
  FUN_00477300(param_3);
  (**(code **)(*piVar1 + 8))();
  param_3[0x22] = 0;
  param_3[0x23] = 0;
  param_3[0x20] = 0;
  param_3[0x21] = 0;
  param_3[0x1f] = 0x3f800000;
  *(undefined1 *)(param_3 + 0x1a) = 1;
  *(undefined1 *)((int)param_3 + 0x69) = 1;
  param_3[0x1b] = 2;
  ExceptionList = pvStack_c;
  return param_3;
}


// ==== 0x476fa0 FUN_00476fa0

void __thiscall FUN_00476fa0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iStack_1c;
  int local_18;
  
  FUN_00571ea0(0,"PhysicsMover");
  FUN_00571c20(param_2,param_1 + 0x78,4,0xffffffff,0);
  FUN_00584960();
  (**(code **)(**(int **)(param_1 + 0x24) + 0xc))(param_2);
  local_18 = 4;
  do {
    FUN_005869c0();
    FUN_00588470();
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  FUN_0046c950();
  FUN_0046d510();
  iVar1 = *(int *)(iStack_1c + 0x50);
  if (*(char *)(param_2 + 0x3d) != '\0' || *(char *)(param_2 + 0x3c) != '\0') {
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(undefined1 *)(iVar1 + 0x30) = 1;
  }
  FUN_00571c20(param_2,iStack_1c + 0x7c,4,0xffffffff,0);
  FUN_00571c20(param_2,iStack_1c + 0x60,4,0xffffffff,0);
  FUN_00571c20(param_2,iStack_1c + 100,4,0xffffffff,0);
  FUN_00571c20(param_2,iStack_1c + 0x68,1,1,0);
  FUN_00571c20(param_2,iStack_1c + 0x69,1,1,0);
  FUN_00571c20(param_2,iStack_1c + 0x6c,4,4,1);
  FUN_00571c20(param_2,iStack_1c + 0x70,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x477100 FUN_00477100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477100(void)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  float *pfVar7;
  float fVar8;
  int unaff_EDI;
  
  puVar4 = *(undefined4 **)(unaff_EDI + 0x54);
  if (puVar4 != (undefined4 *)0x0) {
    iVar5 = *(int *)(unaff_EDI + 0x20);
    uVar1 = puVar4[2];
    uVar6 = *puVar4;
    *(undefined4 *)(iVar5 + 0x1d4) = puVar4[1];
    *(undefined4 *)(iVar5 + 0x1d0) = uVar6;
    *(undefined4 *)(iVar5 + 0x1d8) = uVar1;
  }
  RigidBody__SetMassInertia();
  pfVar7 = *(float **)(unaff_EDI + 0x54);
  fVar2 = *pfVar7;
  if (DAT_006ffde4 == 0) {
    fVar2 = 0.0;
  }
  fVar2 = ((pfVar7[4] - fVar2) / ((pfVar7[4] - fVar2) - (pfVar7[0x28] - fVar2))) * _K_HALF;
  fVar8 = DAT_006ffde8;
  if (*(int *)(*(int *)(unaff_EDI + 0x5c) + 0x38) != 1) {
    fVar8 = 9.8;
  }
  fVar3 = *(float *)(*(int *)(unaff_EDI + 0x5c) + 0x3d0);
  if ((char)(*(int **)(unaff_EDI + 0x50))[0xc] == '\0') {
    fVar3 = 0.0;
  }
  else {
    if (fVar3 < 0.0) {
      fVar3 = 0.0;
    }
    iVar5 = **(int **)(unaff_EDI + 0x50);
    fVar3 = (*(float *)(iVar5 + 8) + *(float *)(iVar5 + 4)) * fVar3;
  }
  fVar8 = fVar3 * pfVar7[0x9b] + fVar8 * *(float *)(*(int *)(unaff_EDI + 0x20) + 0x144);
  fVar3 = fVar8 * (_K_HALF - fVar2);
  FUN_00588520(fVar3);
  FUN_00588520(fVar3);
  fVar8 = fVar8 * fVar2;
  FUN_00588520(fVar8);
  FUN_00588520(fVar8);
  uVar1 = DAT_006f076c;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x38) + 0x2c) = DAT_006f076c;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x3c) + 0x2c) = uVar1;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x40) + 0x2c) = uVar1;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x44) + 0x2c) = uVar1;
  return;
}


// ==== 0x477250 FUN_00477250

void FUN_00477250(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00685bff;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_006c8364;
  param_1[2] = &PTR_FUN_006c8358;
  *(undefined1 *)(*(int *)(param_1[0x17] + 0x3c) + 0x1d) = 1;
  *(undefined4 *)(param_1[8] + 0x140) = 1;
  local_4 = 1;
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1);
  }
  iVar3 = DAT_00735f80;
  puVar1 = (undefined4 *)param_1[0x14];
  iVar2 = *(int *)(DAT_00735f80 + 0x18);
  *puVar1 = *(undefined4 *)(DAT_00735f80 + 0x10);
  *(undefined4 **)(iVar3 + 0x10) = puVar1;
  *(int *)(iVar3 + 0x18) = iVar2 + -1;
  local_4 = local_4 & 0xffffff00;
  PhysicsSystem___PhysicsSystem();
  *param_1 = &PTR_PsychoDriverDerived__scalar_deleting_dtor_006caadc;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4772e0 FUN_004772e0

void __fastcall FUN_004772e0(int *param_1)

{
  PhysicsSystem__ComputeAuxiliaries();
  FUN_00477300(param_1 + -2);
                    /* WARNING: Could not recover jumptable at 0x004772f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// ==== 0x477300 FUN_00477300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477300(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar2 = FUN_0047ac00(*(undefined4 *)(param_1 + 0x5c),param_1 + 0x70,param_1 + 0x74);
  if (iVar2 == 0) {
    iVar3 = 0x2f0;
    do {
      iVar1 = *(int *)(param_1 + -0x2c8 + iVar3);
      if (*(float *)(iVar1 + 0x1c) == *(float *)(*(int *)(iVar1 + 0x14) + 0x14)) {
        fVar4 = (float10)FUN_00588ab0();
        iVar2 = 1;
        *(float *)(iVar3 + *(int *)(param_1 + 0x58)) =
             (float)(fVar4 + (float10)*(float *)(iVar3 + *(int *)(param_1 + 0x58)));
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x300);
  }
  if ((DAT_00735fac == 0) || (*(int *)(*(int *)(param_1 + 0x5c) + 0x24) != 1)) {
    if (iVar2 == 0) {
      return;
    }
  }
  else {
    DAT_00735fac = 0;
    FUN_00584e30();
  }
  _DAT_006f0738 = 0;
  PhysicsSystem__ComputeAuxiliaries();
  return;
}


// ==== 0x4773f0 FUN_004773f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004773f0(float param_1,float param_2,float param_3,float param_4,float param_5,
                    int param_6,float param_7)

{
  float fVar1;
  float *in_EAX;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = *in_EAX;
  *in_EAX = (float)ABS((float10)fVar1);
  fVar2 = ABS((float10)fVar1) + (float10)_K_ONE;
  if (param_6 == 0) {
    fVar3 = (float10)param_4 + (float10)param_5;
  }
  else {
    fVar3 = (float10)param_5 * (float10)param_7 + (float10)param_4;
  }
  if ((_DAT_006ffddc < param_2) &&
     (ABS((float10)param_1) < (float10)_DAT_006ffde0 * (float10)0.017453292)) {
    return fVar2;
  }
  fVar3 = fVar3 * (((float10)_DAT_006ffdcc - (float10)_DAT_00735fa4) *
                   (((float10)param_3 - (float10)_DAT_00735fa8) /
                   ((float10)_DAT_006ffdd0 - (float10)_DAT_00735fa8)) + (float10)_DAT_00735fa4) *
                  ABS((float10)param_1);
  if ((float10)_DAT_006ffdd4 < fVar3) {
    fVar3 = (float10)_DAT_006ffdd4;
  }
  return fVar3 + fVar2;
}


// ==== 0x4774a0 FUN_004774a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004774a0(int param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  byte bVar12;
  int iVar13;
  int *piVar14;
  float10 fVar15;
  int iStack_50;
  int iStack_4c;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  LARGE_INTEGER LStack_20;
  LARGE_INTEGER local_18 [2];
  
  if ((((DAT_00735fb0 == 0) ||
       (iVar13 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14), *(int *)(iVar13 + 4) != 1)) ||
      (*(char *)(iVar13 + 0x734) != '\0')) || (*DAT_0073619c != 4)) {
    if (DAT_00735fb8 != 0) {
      DAT_00735fb8 = 99;
      goto LAB_00477500;
    }
  }
  else {
    DAT_00735fbc = 1;
LAB_00477500:
    FUN_0047a090(param_1,param_2);
  }
  QueryPerformanceCounter(local_18);
  if (DAT_00736200 != 0) goto LAB_00477d56;
  FUN_00479160(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x404));
  FUN_00477100();
  if (*(int *)(*(int *)(param_1 + 0x5c) + 0x3d8) != 1) {
    iVar13 = *(int *)(param_1 + 4);
    if ((*(float *)(iVar13 + 0x1dc) <= *(float *)(iVar13 + 0x1e4)) ||
       (*(float *)(iVar13 + 0x1dc) <= *(float *)(iVar13 + 0x1e0))) {
      if (*(float *)(iVar13 + 0x1dc) < _K_HALF) {
        *(undefined4 *)(iVar13 + 0x1dc) = 0;
      }
    }
    else {
      if (*(float *)(iVar13 + 0x1e4) < _K_HALF) {
        *(undefined4 *)(iVar13 + 0x1e4) = 0;
      }
      if (*(float *)(*(int *)(param_1 + 4) + 0x1e0) < _K_HALF) {
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x1e0) = 0;
      }
    }
  }
  (**(code **)(**(int **)(param_1 + 0x24) + 4))(*(undefined2 *)(*(int *)(param_1 + 4) + 0x1d0));
  *(undefined4 *)(*(int *)(iStack_4c + 0x48) + 0x78) =
       *(undefined4 *)(*(int *)(iStack_4c + 4) + 0x1dc);
  iVar9 = (**(code **)(**(int **)(iStack_4c + 4) + 0x28))();
  iVar13 = *(int *)(iStack_4c + 0x4c);
  if ((1 < iVar9) && (iVar9 <= *(int *)(*(int *)(iVar13 + 0x18) + 0x18) + 1)) {
    if (*(int *)(iVar13 + 0x54) == 1) {
      *(undefined4 *)(iVar13 + 0x50) = 0;
    }
    *(int *)(iVar13 + 0x54) = iVar9;
  }
  cVar8 = CarState__IsNitrousOn();
  if ((cVar8 != '\0') && (*(int *)(*(int *)(iStack_4c + 0x48) + 0x84) == 0)) {
    *(float *)(*(int *)(iStack_4c + 0x48) + 0x88) = (float)DAT_0073ad34 * 0.00025;
  }
  uVar10 = CarState__IsNitrousOn();
  *(uint *)(*(int *)(iStack_4c + 0x48) + 0x84) = uVar10 & 0xff;
  iVar13 = **(int **)(iStack_4c + 4);
  uVar11 = (**(code **)(iVar13 + 0x24))();
  uVar11 = FUN_0046e5b0(uVar11);
  (**(code **)(iVar13 + 0x2c))(uVar11);
  (**(code **)(**(int **)(iStack_50 + 4) + 0x30))
            (*(undefined4 *)(*(int *)(iStack_50 + 0x4c) + 0x54));
  iVar13 = *(int *)(*(int *)(param_1 + 0x5c) + 0x38);
  if (iVar13 == 0) {
LAB_004776da:
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x130) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x134) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x138) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x30) = 1;
  }
  else if (iVar13 == 1) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x130) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x134) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x138) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x30) = 0;
  }
  else if (iVar13 == 2) goto LAB_004776da;
  if (*(int *)(*(int *)(param_1 + 0x5c) + 0x3cc) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x138) = 0;
  }
  if ((*DAT_0073619c == 4) &&
     ((0.3 < *(float *)(*(int *)(param_1 + 4) + 0x1dc) ||
      ((*(int *)(*(int *)(param_1 + 0x58) + 0x38c) == 4 &&
       (0.15 < ABS(*(float *)(*(int *)(param_1 + 0x58) + 0x58)))))))) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x130) = 0;
  }
  fStack_40 = *(float *)(param_1 + 0x78);
  iVar13 = *(int *)(param_1 + 0x58);
  if ((*(int *)(iVar13 + 0x3c0) == 0) &&
     (((DAT_0078a344 != '\0' || (DAT_007361a8 != 0)) ||
      ((DAT_00735fa0 == 0 && ((DAT_0078a345 == '\0' && (DAT_007361a4 == 0)))))))) {
    fStack_40 = _DAT_006ffdd8 * fStack_40;
  }
  *(undefined4 *)(iVar13 + 0x2f0) = 0;
  *(undefined4 *)(iVar13 + 0x2f4) = 0;
  *(undefined4 *)(iVar13 + 0x2f8) = 0;
  *(undefined4 *)(iVar13 + 0x2fc) = 0;
  fVar5 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
  if (*(float *)(*(int *)(param_1 + 4) + 0x1e0) < _K_HALF) {
    fStack_44 = param_2 * 1.0 + *(float *)(param_1 + 0x7c);
    if (1.0 < fStack_44) {
      fStack_44 = 1.0;
    }
  }
  else {
    fStack_44 = *(float *)(param_1 + 0x7c) - param_2 * 20.0;
    if (fStack_44 < 0.5) {
      fStack_44 = 0.5;
    }
  }
  iVar13 = 0x38;
  uVar11 = &DAT_006ffdf0;
  *(float *)(param_1 + 0x7c) = fStack_44;
  bVar12 = 0;
  local_18[0].s.LowPart = &DAT_006ffdf0;
  do {
    if ((*DAT_0073619c == 4) || ((*(char *)(param_1 + 0x68) != '\0' && (iVar13 < 0x40)))) {
      iVar9 = *(int *)(param_1 + 4);
      if ((*(float *)(iVar9 + 0x1dc) <= 0.8) ||
         (((*(float *)(iVar9 + 0x1e4) <= _K_HALF || (10.0 <= fVar5)) || (iVar13 < 0x40)))) {
        fVar1 = *(float *)(*(int *)(param_1 + 0x54) + 0x27c);
        if (iVar13 < 0x40) {
          fVar1 = 1.0 - fVar1;
        }
        *(float *)(*(int *)(iVar13 + param_1) + 0x170) = (fVar1 + fVar1) * *(float *)(iVar9 + 0x1e4)
        ;
      }
      else {
        *(float *)(*(int *)(iVar13 + param_1) + 0x170) = fVar5 * 0.05;
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar13 + param_1) + 0x170) = 0;
    }
    fVar1 = *(float *)(uVar11 + iVar13) * *(float *)(*(int *)(param_1 + 4) + 0x1e0);
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x3c0) == 0) {
      if (0.2 < fVar1) {
        fVar1 = fVar1 + _K_HALF;
      }
      *(float *)(*(int *)(iVar13 + param_1) + 0x174) = fVar1;
    }
    else {
      if (0.2 < fVar1) {
        if (1.0 <= *(float *)(*(int *)(param_1 + 0x58) + 0x390)) {
          fVar15 = (float10)CarState__GetYaw();
          fVar4 = (float)fVar15;
        }
        else {
          fVar4 = 0.0;
        }
        if ((0.3 < ABS(fVar4)) && (fVar5 < 80.0)) {
          fVar1 = fVar1 + _K_HALF;
        }
      }
      *(float *)(*(int *)(iVar13 + param_1) + 0x174) = fVar1;
    }
    if ((((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) ||
        ((DAT_00735fa0 == 0 && ((DAT_0078a345 == '\0' && (DAT_007361a4 == 0)))))) && (0x3f < iVar13)
       ) {
      LStack_20.s.LowPart = *(DWORD *)(*(int *)(param_1 + 0x20) + 0x38);
      iVar9 = *(int *)(param_1 + 0x58);
      uVar11 = *(undefined4 *)(iVar9 + 0x3c0);
      uVar2 = *(undefined4 *)(iVar9 + 0x394);
      uVar3 = *(undefined4 *)(*(int *)(iVar13 + param_1) + 0x174);
      if (1.0 <= *(float *)(iVar9 + 0x390)) {
        fVar15 = (float10)CarState__GetYaw();
        fStack_34 = (float)fVar15;
      }
      else {
        fStack_34 = 0.0;
      }
      iVar9 = *(int *)(param_1 + 0x54);
      fVar15 = (float10)Car_StampCurveFactor();
      fVar15 = (float10)FUN_004773f0(fStack_34,uVar3,uVar2,*(undefined4 *)(iVar9 + 0x280),
                                     *(undefined4 *)(iVar9 + 0x284),uVar11,(float)fVar15);
      fStack_40 = (float)(((fVar15 - (float10)_K_ONE) * (float10)fStack_44 + (float10)_K_ONE) *
                         (float10)fStack_40);
      uVar11 = local_18[0].s.LowPart;
    }
    *(float *)(*(int *)(iVar13 + param_1) + 0x178) = fStack_40;
    if ((1 << (bVar12 & 0x1f) & (int)*(char *)(*(int *)(param_1 + 0x5c) + 0x86c)) == 0) {
      *(undefined4 *)(*(int *)(iVar13 + param_1) + 0x16c) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(iVar13 + param_1) + 0x16c) = 0x3f800000;
    }
    if ((((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) &&
        (*(int *)(*(int *)(param_1 + 0x48) + 0x84) != 0)) &&
       (fVar1 = *(float *)(*(int *)(param_1 + 0x48) + 0x88) + _DAT_0070002c,
       (float)DAT_0073ad34 * 0.00025 < fVar1 != ((float)DAT_0073ad34 * 0.00025 == fVar1))) {
      *(float *)(*(int *)(iVar13 + param_1) + 0x178) =
           *(float *)(*(int *)(iVar13 + param_1) + 0x178) * 0.6;
    }
    bVar12 = bVar12 + 1;
    iVar13 = iVar13 + 4;
  } while (iVar13 < 0x48);
  FUN_00479640(param_1);
  local_18[0]._0_4_ = *(float *)(*(int *)(param_1 + 0x5c) + 0x484);
  if (((float)local_18[0]._0_4_ != 0.0) && (*(char *)(*(int *)(param_1 + 0x5c) + 0x86c) == '\0')) {
    FUN_00479160(local_18[0]._0_4_);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc);
  *(float *)(*(int *)(param_1 + 0x50) + 0x14) =
       (float)*(int *)(*(int *)(param_1 + 0x58) + 0x38c) * 0.25;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x3c0) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1e0) =
         *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x288);
  }
  else {
    fStack_38 = *(float *)(*(int *)(param_1 + 0x54) + 0x28c);
    if (fStack_38 == 0.0) {
      iVar13 = *(int *)(param_1 + 0x20);
      if (1.0 <= *(float *)(*(int *)(param_1 + 0x58) + 0x390)) {
        fVar15 = (float10)CarState__GetYaw();
      }
      else {
        fVar15 = (float10)0.0;
      }
      if ((fVar15 * (float10)*(float *)(iVar13 + 0x88) < (float10)0.0) &&
         ((float10)0.1 < ABS(fVar15))) {
        fStack_38 = 20.0;
      }
    }
    *(float *)(*(int *)(param_1 + 0x20) + 0x1e0) = fStack_38;
  }
  iVar13 = *(int *)(param_1 + 0x5c);
  fVar5 = _K_ONE;
  if ((iVar13 != 0) && (*(int *)(iVar13 + 0x868) != 0)) {
    if (DAT_0078a336 == '\0') {
      fVar5 = 0.0;
    }
    else {
      local_18[0]._0_4_ = ZEXT24(*(ushort *)(*(int *)(iVar13 + 0x868) + 0x34));
      fVar5 = (float)local_18[0]._0_4_ * 0.00024414062;
    }
    fVar5 = 1.0 - fVar5 * 0.03;
  }
  if (*(int *)(*(int *)(param_1 + 0x48) + 0x84) == 0) {
    if (*(char *)(iVar13 + 0x86c) == '\0') {
      *(float *)(*(int *)(param_1 + 0x20) + 0x1e4) =
           fVar5 * *(float *)(*(int *)(param_1 + 0x54) + 0x290);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1e4) = 0x42700000;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1e4) = 0;
  }
LAB_00477d56:
  iVar13 = _ftol_nocw();
  fStack_38 = (float)(iVar13 + 1);
  fVar5 = (float)(int)fStack_38;
  piVar14 = DAT_0073619c;
  local_18[0]._0_4_ = fStack_38;
  if (0 < (int)fStack_38) {
    do {
      if ((DAT_00735fbc != 0) || (*piVar14 != 4)) {
        iVar13 = *(int *)(param_1 + 0x20);
        _DAT_00779ae4 = *(float *)(iVar13 + 0x24);
        _DAT_00779ae8 = *(float *)(iVar13 + 0x28);
        DAT_00779ae0 = *(float *)(iVar13 + 0x20);
        bMatrixCopy_b();
      }
      _DAT_006f0738 = param_2 / fVar5;
      QueryPerformanceCounter(&LStack_20);
      FUN_0046aa40(param_1 + 8,param_2 / fVar5);
      eOrthonormalizeMatrix();
      fVar1 = DAT_00779ae0;
      piVar14 = DAT_0073619c;
      if (*DAT_0073619c == 4) {
        if (((DAT_00735fbc == 0) ||
            (iVar13 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14), *(int *)(iVar13 + 4) != 1)) ||
           (*(char *)(iVar13 + 0x734) != '\0')) {
          DAT_0072cc58 = 1.0;
          DAT_0072cc0c = 1.0;
          DAT_0072cc44 = 1.0;
          _DAT_0072cc48 = (float)DAT_0073ad34 * 0.00025;
          DAT_0072cc70 = 1.0;
          _DAT_0072cc54 = 0.0;
          _DAT_0072cc6c = 0.0;
          _DAT_0072cc5c = 0.0;
        }
        else {
          fVar4 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
          if (0.8 <= fVar4) {
            iVar13 = *(int *)(param_1 + 0x20);
            fVar6 = DAT_00779ae0 - *(float *)(iVar13 + 0x20);
            fVar7 = _DAT_00779ae4 - *(float *)(iVar13 + 0x24);
            _DAT_00779ae8 = _DAT_00779ae8 - *(float *)(iVar13 + 0x28);
            _DAT_0072cc74 =
                 SQRT(fVar6 * fVar6 + fVar7 * fVar7 + _DAT_00779ae8 * _DAT_00779ae8) + _DAT_0072cc74
            ;
            if (DAT_0072cc58 < 0.0) goto LAB_00478023;
          }
          else {
            DAT_0072cc58 = -1.0;
            DAT_0072cc0c = -1.0;
            DAT_0072cc44 = -1.0;
            _DAT_0072cc48 = (float)DAT_0073ad34 * 0.00025;
            DAT_0072cc70 = -1.0;
            _DAT_0072cc54 = 0.0;
            _DAT_0072cc6c = 0.0;
            _DAT_0072cc5c = 0.0;
            _DAT_0072cc74 = 0.0;
LAB_00478023:
            if (60.0 < fVar4) {
              _DAT_0072cc5c = 30.0;
              DAT_0072cc58 = (float)DAT_0073ad34 * 0.00025 - _DAT_0072cc48;
            }
          }
          if ((DAT_0072cc0c < 0.0) && (100.0 < fVar4)) {
            _DAT_0072cc6c = 30.0;
            DAT_0072cc0c = (float)DAT_0073ad34 * 0.00025 - _DAT_0072cc48;
          }
          if ((DAT_0072cc44 < 0.0) && (400.5 < _DAT_0072cc74)) {
            _DAT_0072cc54 = 30.0;
            DAT_0072cc44 = (float)DAT_0073ad34 * 0.00025 - _DAT_0072cc48;
            DAT_0072cc78 = fVar4;
          }
          if ((DAT_0072cc70 < 0.0) && (1602.0 < _DAT_0072cc74)) {
            DAT_0072cc70 = (float)DAT_0073ad34 * 0.00025 - _DAT_0072cc48;
            DAT_0072cc64 = fVar4;
          }
          fVar4 = *(float *)(*(int *)(param_1 + 0x20) + 0x28);
          iVar13 = *(int *)(param_1 + 0x20);
          _DAT_00779ae8 = fVar4;
          *(float *)(iVar13 + 0x24) = _DAT_00779ae4;
          *(float *)(iVar13 + 0x20) = fVar1;
          *(float *)(iVar13 + 0x28) = fVar4;
        }
      }
      else {
        if (1 < *DAT_0073619c) {
          local_18[0]._0_4_ = DAT_0073ad34 - *(int *)(param_1 + 100);
          if ((float)*(int *)(param_1 + 0x60) * 0.00025 < (float)(int)local_18[0]._0_4_ * 0.00025) {
            *(undefined1 *)(param_1 + 0x68) = 1;
          }
          if (*(float *)(*(int *)(param_1 + 4) + 0x1dc) <= _K_HALF) {
            *(undefined1 *)(param_1 + 0x69) = 1;
            *(undefined1 *)(param_1 + 0x68) = 1;
          }
          else if ((*(char *)(param_1 + 0x69) != '\0') && (*(int *)(param_1 + 0x6c) != 0)) {
            FUN_00564a80(0x3e19999a);
            uVar11 = _ftol_nocw();
            *(undefined4 *)(param_1 + 0x60) = uVar11;
            uVar11 = _ftol_nocw();
            *(undefined4 *)(param_1 + 100) = uVar11;
            *(undefined1 *)(param_1 + 0x68) = 0;
            *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
            *(undefined1 *)(param_1 + 0x69) = 0;
          }
        }
        if (*(char *)(param_1 + 0x68) != '\0') {
          iVar13 = *(int *)(param_1 + 0x20);
          *(undefined4 *)(iVar13 + 0x70) = 0;
          *(undefined4 *)(iVar13 + 0x74) = 0;
          *(undefined4 *)(iVar13 + 0x78) = 0;
        }
      }
      fStack_38 = (float)((int)fStack_38 - 1);
    } while (fStack_38 != 0.0);
  }
  if (((DAT_00735fbc != 0) &&
      (iVar13 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14), *(int *)(iVar13 + 4) == 1)) &&
     (*(char *)(iVar13 + 0x734) == '\0')) {
    if (0.0 < _DAT_0072cc5c) {
      _DAT_0072cc5c = _DAT_0072cc5c - DAT_0073457c;
    }
    if (0.0 < _DAT_0072cc6c) {
      _DAT_0072cc6c = _DAT_0072cc6c - DAT_0073457c;
    }
    if (0.0 < _DAT_0072cc54) {
      _DAT_0072cc54 = _DAT_0072cc54 - DAT_0073457c;
    }
  }
  FUN_004789d0(param_2);
  iVar13 = *(int *)(param_1 + 0x5c);
  if (((*(int *)(*(int *)(iVar13 + 0x14) + 4) != 3) && (*(char *)(iVar13 + 0x8a8) == '\0')) &&
     (*(char *)(iVar13 + 0x4d0) != '\0')) {
    iVar13 = 0x38;
    do {
      FUN_00587e90(param_2,*(undefined4 *)(param_1 + 0x5c));
      iVar13 = iVar13 + 4;
    } while (iVar13 < 0x48);
  }
  FUN_00479e20(param_2);
  return (float10)param_2;
}


// ==== 0x4782c0 FUN_004782c0

void FUN_004782c0(void)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  int in_EAX;
  
  FUN_00584b80(*(int *)(in_EAX + 0x58) + 0x30,*(int *)(in_EAX + 0x58) + 0x90);
  iVar2 = *(int *)(in_EAX + 0x28);
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2b0);
  iVar2 = *(int *)(in_EAX + 0x38);
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2c0);
  *(undefined4 *)(iVar2 + 0x28) = uVar1;
  iVar2 = *(int *)(in_EAX + 0x2c);
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2b4);
  iVar2 = *(int *)(in_EAX + 0x3c);
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2c4);
  *(undefined4 *)(iVar2 + 0x28) = uVar1;
  iVar2 = *(int *)(in_EAX + 0x30);
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2b8);
  iVar2 = *(int *)(in_EAX + 0x40);
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2c8);
  *(undefined4 *)(iVar2 + 0x28) = uVar1;
  iVar2 = *(int *)(in_EAX + 0x34);
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 700);
  iVar2 = *(int *)(in_EAX + 0x44);
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2cc);
  *(undefined4 *)(iVar2 + 0x28) = uVar1;
  fVar3 = DAT_007000e4;
  if (DAT_007000e4 == 100.0) {
    fVar3 = *(float *)(*(int *)(in_EAX + 0x58) + 0x3a0);
  }
  *(float *)(*(int *)(in_EAX + 0x48) + 0x14) = fVar3 * 0.10471967;
  iVar2 = *(int *)(in_EAX + 0x4c);
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x398);
  *(undefined4 *)(iVar2 + 0x3c) = uVar1;
  *(undefined4 *)(iVar2 + 0x38) = uVar1;
  *(undefined4 *)(iVar2 + 0x44) = 3;
  *(undefined4 *)(iVar2 + 0x14) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x58) = 0;
  return;
}


// ==== 0x4783c0 FUN_004783c0

void __fastcall FUN_004783c0(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  int *piVar3;
  int *piVar4;
  int iVar5;
  float10 fVar6;
  float fStack_2c;
  int local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  DAT_0078eb4c = DAT_0078eb4c + 1;
  local_28 = param_1;
  (**(code **)(**(int **)(param_1 + 0x18) + 0x14))();
  FUN_00462f90(&fStack_2c);
  if (DAT_00735fc4 == 0) {
    fStack_2c = 0.0;
  }
  else {
    fStack_2c = fStack_2c * 0.25;
  }
  piVar3 = (int *)(param_1 + 0x20);
  iVar5 = 4;
  piVar4 = piVar3;
  do {
    fStack_24 = fStack_2c;
    if (*(int *)(*piVar4 + 0x80) == 0) {
      fStack_24 = 0.0;
    }
    fStack_24 = fStack_24 + *(float *)(*piVar4 + 0x24);
    fVar6 = (float10)FUN_00586f10(fStack_24);
    *(float *)(extraout_EDX + 0xb0) = (float)fVar6;
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_00478570();
  iVar5 = DAT_00734540;
  fStack_2c = 5.60519e-45;
  do {
    iVar1 = *piVar3;
    if (*(int *)(iVar1 + 0x80) != 0) {
      iVar2 = *(int *)(iVar1 + 0xa0);
      iVar1 = *(int *)(iVar1 + 0xa4);
      fStack_20 = *(float *)(iVar2 + 0x130) - *(float *)(iVar1 + 0x20);
      fStack_1c = *(float *)(iVar2 + 0x134) - *(float *)(iVar1 + 0x24);
      fStack_18 = *(float *)(iVar2 + 0x138) - *(float *)(iVar1 + 0x28);
      if (iVar5 == 0) {
        FUN_00584cd0();
      }
    }
    piVar3 = piVar3 + 1;
    fStack_2c = (float)((int)fStack_2c + -1);
  } while (fStack_2c != 0.0);
  FUN_00479c30();
  FUN_004791f0();
  if (*(int *)(local_28 + 0x54) != 0) {
    FUN_0042a860();
  }
  iVar5 = DAT_007361a8;
  if ((((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) ||
      ((FUN_00479290(), DAT_0078a344 == '\0' && (iVar5 == 0)))) &&
     (((DAT_00735fa0 != 0 || (DAT_0078a345 != '\0')) || (DAT_007361a4 != 0)))) {
    FUN_00479350();
  }
  if ((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) {
    FUN_00479510();
  }
  return;
}


// ==== 0x478570 FUN_00478570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478570(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
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
  int iVar15;
  int unaff_EDI;
  int local_8c;
  float fStack_6c;
  float fStack_68;
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  FUN_0046e270();
  cVar1 = *(char *)(*(int *)(*(int *)(unaff_EDI + 0x5c) + 0x3c) + 0x1c);
  local_8c = 4;
  do {
    FUN_00587330(0,(int)cVar1);
    local_8c = local_8c + -1;
  } while (local_8c != 0);
  iVar15 = *(int *)(unaff_EDI + 0x20);
  bMatrixCopy();
  D3DXVec3Transform(local_60,iVar15 + 0x110,local_50);
  iVar15 = 5;
  do {
    iVar2 = *(int *)(unaff_EDI + 0x38);
    iVar3 = *(int *)(unaff_EDI + 0x28);
    iVar4 = *(int *)(unaff_EDI + 0x3c);
    fVar5 = *(float *)(iVar2 + 0x118) * *(float *)(iVar2 + 0xb0) +
            *(float *)(iVar2 + 0xc0) * *(float *)(iVar2 + 0x11c);
    fVar6 = *(float *)(iVar2 + 0xc4) * *(float *)(iVar2 + 0x11c) +
            *(float *)(iVar2 + 0xb4) * *(float *)(iVar2 + 0x118);
    fVar11 = *(float *)(iVar4 + 0x118) * *(float *)(iVar4 + 0xb0) +
             *(float *)(iVar4 + 0xc0) * *(float *)(iVar4 + 0x11c);
    fVar12 = *(float *)(iVar4 + 0xc4) * *(float *)(iVar4 + 0x11c) +
             *(float *)(iVar4 + 0xb4) * *(float *)(iVar4 + 0x118);
    iVar4 = *(int *)(unaff_EDI + 0x40);
    fVar9 = *(float *)(iVar4 + 0x118) * *(float *)(iVar4 + 0xb0) +
            *(float *)(iVar4 + 0xc0) * *(float *)(iVar4 + 0x11c);
    fVar10 = *(float *)(iVar4 + 0xc4) * *(float *)(iVar4 + 0x11c) +
             *(float *)(iVar4 + 0xb4) * *(float *)(iVar4 + 0x118);
    iVar4 = *(int *)(unaff_EDI + 0x44);
    fVar7 = *(float *)(iVar4 + 0x118) * *(float *)(iVar4 + 0xb0) +
            *(float *)(iVar4 + 0xc0) * *(float *)(iVar4 + 0x11c);
    fVar8 = *(float *)(iVar4 + 0xc4) * *(float *)(iVar4 + 0x11c) +
            *(float *)(iVar4 + 0xb4) * *(float *)(iVar4 + 0x118);
    fVar13 = _K_ONE / *(float *)(*(int *)(unaff_EDI + 0x20) + 0x144);
    fVar14 = (fStack_6c + fVar5 + fVar11 + fVar9 + fVar7) * fVar13;
    fVar13 = fVar13 * (fStack_68 + fVar6 + fVar12 + fVar10 + fVar8);
    fVar5 = ((fVar8 * *(float *)(*(int *)(unaff_EDI + 0x34) + 0x90) +
             ((fVar10 * *(float *)(*(int *)(unaff_EDI + 0x30) + 0x90) +
              ((fVar12 * *(float *)(*(int *)(unaff_EDI + 0x2c) + 0x90) +
               (fVar6 * *(float *)(iVar3 + 0x90) - fVar5 * *(float *)(iVar3 + 0x94))) -
              fVar11 * *(float *)(*(int *)(unaff_EDI + 0x2c) + 0x94))) -
             fVar9 * *(float *)(*(int *)(unaff_EDI + 0x30) + 0x94))) -
            fVar7 * *(float *)(*(int *)(unaff_EDI + 0x34) + 0x94)) /
            (_K_ONE / *(float *)(*(int *)(unaff_EDI + 0x20) + 0x178));
    if ((*(char *)(iVar2 + 0x154) == '\0') && (*(int *)(iVar2 + 0x10c) == 0)) {
      iVar4 = *(int *)(iVar2 + 0x14);
      *(float *)(iVar2 + 0x118) =
           ((((*(float *)(iVar2 + 0x108) - *(float *)(iVar4 + 0x10) * *(float *)(iVar2 + 0x118)) /
             *(float *)(iVar2 + 0x2c)) * *(float *)(iVar4 + 0x10) -
            ((fVar14 - fVar5 * *(float *)(iVar3 + 0x94)) * *(float *)(iVar2 + 0xb0) +
            (fVar5 * *(float *)(iVar3 + 0x90) + fVar13) * *(float *)(iVar2 + 0xc0))) /
           *(float *)(iVar4 + 0x10)) * *(float *)(iVar2 + 0x2c) + *(float *)(iVar2 + 0x118);
    }
    iVar2 = *(int *)(unaff_EDI + 0x3c);
    if ((*(char *)(iVar2 + 0x154) == '\0') && (*(int *)(iVar2 + 0x10c) == 0)) {
      iVar3 = *(int *)(iVar2 + 0x14);
      *(float *)(iVar2 + 0x118) =
           ((((*(float *)(iVar2 + 0x108) - *(float *)(iVar3 + 0x10) * *(float *)(iVar2 + 0x118)) /
             *(float *)(iVar2 + 0x2c)) * *(float *)(iVar3 + 0x10) -
            ((fVar14 - fVar5 * *(float *)(*(int *)(unaff_EDI + 0x2c) + 0x94)) *
             *(float *)(iVar2 + 0xb0) +
            (fVar5 * *(float *)(*(int *)(unaff_EDI + 0x2c) + 0x90) + fVar13) *
            *(float *)(iVar2 + 0xc0))) / *(float *)(iVar3 + 0x10)) * *(float *)(iVar2 + 0x2c) +
           *(float *)(iVar2 + 0x118);
    }
    iVar2 = *(int *)(unaff_EDI + 0x40);
    if ((*(char *)(iVar2 + 0x154) == '\0') && (*(int *)(iVar2 + 0x10c) == 0)) {
      iVar3 = *(int *)(iVar2 + 0x14);
      *(float *)(iVar2 + 0x118) =
           ((((*(float *)(iVar2 + 0x108) - *(float *)(iVar3 + 0x10) * *(float *)(iVar2 + 0x118)) /
             *(float *)(iVar2 + 0x2c)) * *(float *)(iVar3 + 0x10) -
            ((fVar14 - fVar5 * *(float *)(*(int *)(unaff_EDI + 0x30) + 0x94)) *
             *(float *)(iVar2 + 0xb0) +
            (fVar5 * *(float *)(*(int *)(unaff_EDI + 0x30) + 0x90) + fVar13) *
            *(float *)(iVar2 + 0xc0))) / *(float *)(iVar3 + 0x10)) * *(float *)(iVar2 + 0x2c) +
           *(float *)(iVar2 + 0x118);
    }
    iVar2 = *(int *)(unaff_EDI + 0x44);
    if ((*(char *)(iVar2 + 0x154) == '\0') && (*(int *)(iVar2 + 0x10c) == 0)) {
      iVar3 = *(int *)(iVar2 + 0x14);
      *(float *)(iVar2 + 0x118) =
           ((((*(float *)(iVar2 + 0x108) - *(float *)(iVar3 + 0x10) * *(float *)(iVar2 + 0x118)) /
             *(float *)(iVar2 + 0x2c)) * *(float *)(iVar3 + 0x10) -
            ((fVar14 - fVar5 * *(float *)(*(int *)(unaff_EDI + 0x34) + 0x94)) *
             *(float *)(iVar2 + 0xb0) +
            (fVar5 * *(float *)(*(int *)(unaff_EDI + 0x34) + 0x90) + fVar13) *
            *(float *)(iVar2 + 0xc0))) / *(float *)(iVar3 + 0x10)) * *(float *)(iVar2 + 0x2c) +
           *(float *)(iVar2 + 0x118);
    }
    FUN_0046e360();
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  iVar15 = 0;
  do {
    FUN_00587830(iVar15);
    iVar15 = iVar15 + 1;
  } while (iVar15 < 4);
  FUN_0046e440();
  return;
}


// ==== 0x4789d0 FUN_004789d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004789d0(float param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  char cVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  int in_EAX;
  int iVar9;
  int iVar10;
  
  if (DAT_007798e0 != 0) goto LAB_00478f53;
  iVar10 = *(int *)(in_EAX + 0x20);
  iVar9 = *(int *)(in_EAX + 0x58);
  uVar1 = *(undefined4 *)(iVar10 + 0x28);
  uVar7 = *(undefined4 *)(iVar10 + 0x20);
  *(undefined4 *)(iVar9 + 0x24) = *(undefined4 *)(iVar10 + 0x24);
  *(undefined4 *)(iVar9 + 0x20) = uVar7;
  *(undefined4 *)(iVar9 + 0x28) = uVar1;
  bMatrixCopy_b();
  FUN_00465390();
  iVar10 = *(int *)(in_EAX + 0x20);
  uVar7 = *(undefined4 *)(iVar10 + 0xa0);
  uVar1 = *(undefined4 *)(iVar10 + 0xa8);
  iVar9 = *(int *)(in_EAX + 0x58);
  *(undefined4 *)(iVar9 + 0x34) = *(undefined4 *)(iVar10 + 0xa4);
  *(undefined4 *)(iVar9 + 0x30) = uVar7;
  *(undefined4 *)(iVar9 + 0x38) = uVar1;
  fVar2 = *(float *)(iVar10 + 0xa8);
  fVar3 = *(float *)(iVar10 + 0xa4);
  fVar4 = *(float *)(iVar10 + 0xa0);
  *(undefined1 *)(iVar9 + 0x420) = 0;
  *(float *)(iVar9 + 0x394) = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4);
  iVar10 = *(int *)(in_EAX + 0x20);
  iVar9 = *(int *)(in_EAX + 0x58);
  uVar1 = *(undefined4 *)(iVar10 + 200);
  uVar7 = *(undefined4 *)(iVar10 + 0xc0);
  *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(iVar10 + 0xc4);
  *(undefined4 *)(iVar9 + 0x90) = uVar7;
  *(undefined4 *)(iVar9 + 0x98) = uVar1;
  iVar10 = *(int *)(in_EAX + 0x58);
  _ftol_nocw();
  _ftol_nocw();
  uVar8 = FUN_00564fa0();
  *(undefined2 *)(iVar10 + 0x374) = uVar8;
  iVar10 = *(int *)(in_EAX + 0x58);
  *(float *)(iVar10 + 0x390) =
       *(float *)(iVar10 + 0x50) * *(float *)(iVar10 + 0x30) +
       *(float *)(iVar10 + 0x34) * *(float *)(iVar10 + 0x54) +
       *(float *)(iVar10 + 0x38) * *(float *)(iVar10 + 0x58);
  *(undefined2 *)(*(int *)(in_EAX + 0x58) + 0x376) = *(undefined2 *)(*(int *)(in_EAX + 4) + 0x1d0);
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2b0) = *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x28)
  ;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2c0) = *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x24)
  ;
  iVar10 = *(int *)(in_EAX + 0x28);
  if (*(float *)(*(int *)(iVar10 + 0x14) + 0x1c) <= *(float *)(iVar10 + 0x1c)) {
    fVar2 = *(float *)(*(int *)(iVar10 + 0x14) + 0x1c) - *(float *)(iVar10 + 0x1c);
  }
  else {
    fVar2 = 0.0;
  }
  *(float *)(*(int *)(in_EAX + 0x58) + 0x300) = *(float *)(iVar10 + 0x1c) + fVar2;
  cVar5 = *(char *)(*(int *)(in_EAX + 0x38) + 0x155);
  iVar10 = *(int *)(in_EAX + 0x58);
  cVar6 = *(char *)(iVar10 + 0x310);
  *(char *)(iVar10 + 0x310) = cVar5;
  if (cVar6 == '\0') {
    if (cVar5 != '\0') {
      iVar9 = *(int *)(iVar10 + 0x38c) + 1;
LAB_00478b86:
      *(int *)(iVar10 + 0x38c) = iVar9;
    }
  }
  else if (cVar5 == '\0') {
    iVar9 = *(int *)(iVar10 + 0x38c) + -1;
    goto LAB_00478b86;
  }
  iVar10 = *(int *)(*(int *)(in_EAX + 0x38) + 0x150);
  iVar9 = *(int *)(in_EAX + 0x58);
  *(int *)(iVar9 + 0x314) = iVar10;
  if (*(int *)(iVar9 + 0x324) < iVar10) {
    *(int *)(iVar9 + 0x324) = iVar10;
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x354) =
       *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x168);
  iVar10 = *(int *)(in_EAX + 0x58);
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x100);
  *(undefined4 *)(iVar10 + 0x338) = *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x104);
  *(undefined4 *)(iVar10 + 0x334) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2d0) =
       *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x158);
  if (*(char *)(*(int *)(in_EAX + 0x38) + 0x155) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x15c);
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2e0) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2b4) = *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x28)
  ;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2c4) = *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x24)
  ;
  iVar10 = *(int *)(in_EAX + 0x2c);
  if (*(float *)(*(int *)(iVar10 + 0x14) + 0x1c) <= *(float *)(iVar10 + 0x1c)) {
    fVar2 = *(float *)(*(int *)(iVar10 + 0x14) + 0x1c) - *(float *)(iVar10 + 0x1c);
  }
  else {
    fVar2 = 0.0;
  }
  *(float *)(*(int *)(in_EAX + 0x58) + 0x304) = *(float *)(iVar10 + 0x1c) + fVar2;
  iVar10 = *(int *)(in_EAX + 0x58);
  cVar5 = *(char *)(*(int *)(in_EAX + 0x3c) + 0x155);
  cVar6 = *(char *)(iVar10 + 0x311);
  *(char *)(iVar10 + 0x311) = cVar5;
  if (cVar6 == '\0') {
    if (cVar5 != '\0') {
      iVar9 = *(int *)(iVar10 + 0x38c) + 1;
LAB_00478c9c:
      *(int *)(iVar10 + 0x38c) = iVar9;
    }
  }
  else if (cVar5 == '\0') {
    iVar9 = *(int *)(iVar10 + 0x38c) + -1;
    goto LAB_00478c9c;
  }
  iVar10 = *(int *)(in_EAX + 0x58);
  iVar9 = *(int *)(*(int *)(in_EAX + 0x3c) + 0x150);
  *(int *)(iVar10 + 0x318) = iVar9;
  if (*(int *)(iVar10 + 0x328) < iVar9) {
    *(int *)(iVar10 + 0x328) = iVar9;
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x358) =
       *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x168);
  iVar10 = *(int *)(in_EAX + 0x58);
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x100);
  *(undefined4 *)(iVar10 + 0x340) = *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x104);
  *(undefined4 *)(iVar10 + 0x33c) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2d4) =
       *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x158);
  if (*(char *)(*(int *)(in_EAX + 0x3c) + 0x155) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x15c);
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2e4) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2b8) = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x28)
  ;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2c8) = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x24)
  ;
  iVar10 = *(int *)(in_EAX + 0x30);
  if (*(float *)(*(int *)(iVar10 + 0x14) + 0x1c) <= *(float *)(iVar10 + 0x1c)) {
    fVar2 = *(float *)(*(int *)(iVar10 + 0x14) + 0x1c) - *(float *)(iVar10 + 0x1c);
  }
  else {
    fVar2 = 0.0;
  }
  *(float *)(*(int *)(in_EAX + 0x58) + 0x308) = *(float *)(iVar10 + 0x1c) + fVar2;
  cVar5 = *(char *)(*(int *)(in_EAX + 0x40) + 0x155);
  iVar10 = *(int *)(in_EAX + 0x58);
  cVar6 = *(char *)(iVar10 + 0x312);
  *(char *)(iVar10 + 0x312) = cVar5;
  if (cVar6 == '\0') {
    if (cVar5 != '\0') {
      iVar9 = *(int *)(iVar10 + 0x38c) + 1;
LAB_00478dae:
      *(int *)(iVar10 + 0x38c) = iVar9;
    }
  }
  else if (cVar5 == '\0') {
    iVar9 = *(int *)(iVar10 + 0x38c) + -1;
    goto LAB_00478dae;
  }
  iVar10 = *(int *)(*(int *)(in_EAX + 0x40) + 0x150);
  iVar9 = *(int *)(in_EAX + 0x58);
  *(int *)(iVar9 + 0x31c) = iVar10;
  if (*(int *)(iVar9 + 0x32c) < iVar10) {
    *(int *)(iVar9 + 0x32c) = iVar10;
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x35c) =
       *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x168);
  iVar10 = *(int *)(in_EAX + 0x58);
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x100);
  *(undefined4 *)(iVar10 + 0x348) = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x104);
  *(undefined4 *)(iVar10 + 0x344) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2d8) =
       *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x158);
  if (*(char *)(*(int *)(in_EAX + 0x40) + 0x155) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x15c);
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2e8) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 700) = *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x28);
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2cc) = *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x24)
  ;
  iVar10 = *(int *)(in_EAX + 0x34);
  if (*(float *)(*(int *)(iVar10 + 0x14) + 0x1c) <= *(float *)(iVar10 + 0x1c)) {
    fVar2 = *(float *)(*(int *)(iVar10 + 0x14) + 0x1c) - *(float *)(iVar10 + 0x1c);
  }
  else {
    fVar2 = 0.0;
  }
  *(float *)(*(int *)(in_EAX + 0x58) + 0x30c) = *(float *)(iVar10 + 0x1c) + fVar2;
  iVar10 = *(int *)(in_EAX + 0x58);
  cVar5 = *(char *)(*(int *)(in_EAX + 0x44) + 0x155);
  cVar6 = *(char *)(iVar10 + 0x313);
  *(char *)(iVar10 + 0x313) = cVar5;
  if (cVar6 == '\0') {
    if (cVar5 != '\0') {
      iVar9 = *(int *)(iVar10 + 0x38c) + 1;
LAB_00478ec4:
      *(int *)(iVar10 + 0x38c) = iVar9;
    }
  }
  else if (cVar5 == '\0') {
    iVar9 = *(int *)(iVar10 + 0x38c) + -1;
    goto LAB_00478ec4;
  }
  iVar10 = *(int *)(in_EAX + 0x58);
  iVar9 = *(int *)(*(int *)(in_EAX + 0x44) + 0x150);
  *(int *)(iVar10 + 800) = iVar9;
  if (*(int *)(iVar10 + 0x330) < iVar9) {
    *(int *)(iVar10 + 0x330) = iVar9;
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x360) =
       *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x168);
  iVar10 = *(int *)(in_EAX + 0x58);
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x100);
  *(undefined4 *)(iVar10 + 0x350) = *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x104);
  *(undefined4 *)(iVar10 + 0x34c) = uVar1;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2dc) =
       *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x158);
  if (*(char *)(*(int *)(in_EAX + 0x44) + 0x155) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x15c);
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x2ec) = uVar1;
LAB_00478f53:
  iVar10 = *(int *)(in_EAX + 0x48);
  if (*(float *)(iVar10 + 0x9c) == 0.0) {
    fVar2 = *(float *)(iVar10 + 0x80) * *(float *)(iVar10 + 0x78);
  }
  else {
    fVar2 = 0.0;
  }
  *(float *)(*(int *)(in_EAX + 0x58) + 0x39c) = fVar2;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x398) = *(undefined4 *)(*(int *)(in_EAX + 0x4c) + 0x3c)
  ;
  *(uint *)(*(int *)(in_EAX + 0x58) + 0x3a8) = (uint)(*(int *)(*(int *)(in_EAX + 0x4c) + 0x44) == 3)
  ;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x3ac) = *(undefined4 *)(*(int *)(in_EAX + 0x4c) + 0x70)
  ;
  fVar2 = *(float *)(*(int *)(in_EAX + 0x48) + 0x14) * 9.549304;
  fVar3 = -2.5 / *(float *)(*(int *)(*(int *)(in_EAX + 0x48) + 0x18) + 0xc);
  fVar4 = DAT_007000e4;
  if (DAT_007000e4 == 100.0) {
    fVar4 = *(float *)(*(int *)(in_EAX + 0x58) + 0x3a0);
  }
  if ((fVar2 - fVar4) / param_1 < fVar3) {
    fVar4 = DAT_007000e4;
    if (DAT_007000e4 == 100.0) {
      fVar4 = *(float *)(*(int *)(in_EAX + 0x58) + 0x3a0);
    }
    fVar4 = fVar3 * param_1 + fVar4;
    if (fVar2 <= fVar4) {
      fVar2 = fVar4;
    }
  }
  *(float *)(*(int *)(in_EAX + 0x58) + 0x3a0) = fVar2;
  if (DAT_007798e0 == 0) {
    param_1 = ABS(*(float *)(*(int *)(in_EAX + 0x38) + 0x160));
    fVar3 = ABS(*(float *)(*(int *)(in_EAX + 0x3c) + 0x160));
    fVar2 = ABS(*(float *)(*(int *)(in_EAX + 0x40) + 0x160));
    fVar4 = ABS(*(float *)(*(int *)(in_EAX + 0x44) + 0x160));
    if (param_1 <= fVar4) {
      param_1 = fVar4;
    }
    if (fVar2 < fVar3) {
      fVar2 = fVar3;
    }
    param_1 = (_K_ONE / _DAT_006ffe50) * param_1;
    fVar2 = (_K_ONE / _DAT_006ffe50) * fVar2;
    if (_K_ONE < param_1) {
      param_1 = 1.0;
    }
    if (_K_ONE < fVar2) {
      fVar2 = _K_ONE;
    }
    iVar10 = *(int *)(in_EAX + 0x58);
    *(float *)(iVar10 + 0x388) = fVar2;
    *(float *)(iVar10 + 900) = param_1;
    iVar10 = 0;
    *(float *)(*(int *)(in_EAX + 0x58) + 0x380) =
         (*(float *)(*(int *)(in_EAX + 0x44) + 0x168) + *(float *)(*(int *)(in_EAX + 0x38) + 0x168)
          + *(float *)(*(int *)(in_EAX + 0x3c) + 0x168) +
         *(float *)(*(int *)(in_EAX + 0x40) + 0x168)) * 0.25;
    uVar1 = *(undefined4 *)(in_EAX + 0x58);
    do {
      FUN_00465150(uVar1);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 4);
  }
  return;
}


// ==== 0x479160 FUN_00479160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479160(float param_1)

{
  float fVar1;
  int in_EAX;
  
  if (DAT_006ffe54 == 0) {
    param_1 = _K_ONE;
  }
  fVar1 = param_1;
  if ((*(char *)(*(int *)(in_EAX + 0x5c) + 0x86c) != '\0') &&
     (*(char *)(*(int *)(*(int *)(in_EAX + 0x5c) + 0x3c) + 0x1c) != '\0')) {
    fVar1 = param_1 * 0.4;
  }
  *(float *)(*(int *)(in_EAX + 0x48) + 0xa0) = fVar1;
  *(float *)(*(int *)(in_EAX + 0x20) + 0x1e8) = param_1;
  *(float *)(*(int *)(in_EAX + 0x50) + 8) = param_1;
  *(float *)(*(int *)(in_EAX + 0x50) + 0xc) = _K_ONE - *(float *)(*(int *)(in_EAX + 0x5c) + 0x47c);
  *(float *)(*(int *)(in_EAX + 0x38) + 0x17c) = param_1;
  *(float *)(*(int *)(in_EAX + 0x3c) + 0x17c) = param_1;
  *(float *)(*(int *)(in_EAX + 0x40) + 0x17c) = param_1;
  *(float *)(*(int *)(in_EAX + 0x44) + 0x17c) = param_1;
  return;
}


// ==== 0x4791f0 FUN_004791f0

void __fastcall FUN_004791f0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x5c) + 0x38);
  if (((iVar1 != 1) && (iVar1 != 2)) && (*(int *)(*(int *)(param_2 + 0x5c) + 0x3cc) < 2)) {
    iVar1 = *(int *)(param_2 + 0x20);
    LinearTable__Lookup11
              (&PTR_DAT_00705e14,
               SQRT(*(float *)(iVar1 + 0xc4) * *(float *)(iVar1 + 0xc4) +
                    *(float *)(iVar1 + 0xc0) * *(float *)(iVar1 + 0xc0) +
                    *(float *)(iVar1 + 200) * *(float *)(iVar1 + 200)));
    FUN_00584e00();
  }
  return;
}


// ==== 0x479290 FUN_00479290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479290(void)

{
  int unaff_EDI;
  float10 fVar1;
  
  if (((3 < *(int *)(*(int *)(unaff_EDI + 0x5c) + 0x3cc)) &&
      (*(int *)(*(int *)(unaff_EDI + 0x5c) + 0x38) == 0)) &&
     (fVar1 = (float10)CarState__GetYaw(), ABS(fVar1 * (float10)57.295776) < (float10)5.0)) {
    Car__GetForwardAcceleration();
    FUN_00584e00();
  }
  return;
}


// ==== 0x479350 FUN_00479350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479350(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  short sVar5;
  uint uVar6;
  int unaff_EDI;
  float10 fVar7;
  float local_2c;
  float local_24 [2];
  float local_1c;
  float local_18;
  
  iVar1 = *(int *)(unaff_EDI + 0x58);
  sVar5 = Atan2ToAngle16(*(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34));
  local_24[0] = (float)(uint)(ushort)(*(short *)(iVar1 + 0x374) - sVar5);
  local_2c = (float)(int)local_24[0] * 9.58738e-05;
  if (3.14159 < local_2c) {
    local_2c = local_2c - 6.28318;
  }
  fVar2 = *(float *)(*(int *)(unaff_EDI + 0x58) + 0x98);
  uVar6 = (uint)(0.2 <= *(float *)(*(int *)(unaff_EDI + 0x54) + 0x1c0));
  if (0.8 < *(float *)(*(int *)(unaff_EDI + 0x54) + 0x1c0)) {
    uVar6 = 2;
  }
  if (0.0 < local_2c * fVar2) {
    Curve_Evaluate(local_24,ABS(local_2c));
    iVar1 = *(int *)(unaff_EDI + 0x5c);
    fVar4 = *(float *)(&DAT_006f0fc0 + (uVar6 * 0x1b + DAT_0078a3fc) * 4) * local_24[0] * fVar2;
    local_1c = *(float *)(iVar1 + 0xb4) * fVar4;
    iVar3 = *(int *)(unaff_EDI + 0x20);
    local_18 = *(float *)(iVar1 + 0xb8) * fVar4;
    *(float *)(iVar3 + 0x120) = fVar4 * *(float *)(iVar1 + 0xb0) + *(float *)(iVar3 + 0x120);
    *(float *)(iVar3 + 0x124) = local_1c + *(float *)(iVar3 + 0x124);
    *(float *)(iVar3 + 0x128) = local_18 + *(float *)(iVar3 + 0x128);
  }
  uVar6 = (uint)(0.2 <= *(float *)(*(int *)(unaff_EDI + 0x54) + 0x1c0));
  if (0.8 < *(float *)(*(int *)(unaff_EDI + 0x54) + 0x1c0)) {
    uVar6 = 2;
  }
  local_24[0] = *(float *)(&DAT_006f0fcc + uVar6 * 0x6c);
  fVar7 = (float10)FUN_00583ea0(ABS(fVar2) * local_24[0] + (_K_ONE - local_24[0]) * ABS(local_2c));
  *(float *)(*(int *)(unaff_EDI + 0x40) + 0x180) = (float)fVar7;
  *(float *)(*(int *)(unaff_EDI + 0x44) + 0x180) = (float)fVar7;
  return;
}


// ==== 0x479510 FUN_00479510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479510(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  short sVar5;
  int unaff_EDI;
  float10 fVar6;
  float local_2c;
  float local_24 [2];
  float local_1c;
  float local_18;
  
  iVar1 = *(int *)(unaff_EDI + 0x58);
  sVar5 = Atan2ToAngle16(*(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34));
  local_2c = (float)(ushort)(*(short *)(iVar1 + 0x374) - sVar5) * 9.58738e-05;
  if (3.14159 < local_2c) {
    local_2c = local_2c - 6.28318;
  }
  fVar2 = *(float *)(*(int *)(unaff_EDI + 0x58) + 0x98);
  if (0.0 < local_2c * fVar2) {
    Curve_Evaluate(local_24,ABS(local_2c));
    iVar1 = *(int *)(unaff_EDI + 0x5c);
    fVar4 = local_24[0] * -25.0 * fVar2;
    local_1c = *(float *)(iVar1 + 0xb4) * fVar4;
    iVar3 = *(int *)(unaff_EDI + 0x20);
    local_18 = *(float *)(iVar1 + 0xb8) * fVar4;
    *(float *)(iVar3 + 0x120) = fVar4 * *(float *)(iVar1 + 0xb0) + *(float *)(iVar3 + 0x120);
    *(float *)(iVar3 + 0x124) = local_1c + *(float *)(iVar3 + 0x124);
    *(float *)(iVar3 + 0x128) = local_18 + *(float *)(iVar3 + 0x128);
  }
  local_24[0] = ABS(fVar2) * 0.275 + (_K_ONE - 0.275) * ABS(local_2c);
  fVar6 = (float10)FUN_00583ea0(local_24[0]);
  *(float *)(*(int *)(unaff_EDI + 0x40) + 0x180) = (float)fVar6;
  *(float *)(*(int *)(unaff_EDI + 0x44) + 0x180) = (float)fVar6;
  return;
}


// ==== 0x479640 FUN_00479640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479640(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  char cVar9;
  undefined4 uVar10;
  uint uVar11;
  bool bVar12;
  float10 fVar13;
  float local_c;
  
  iVar7 = (int)param_1;
  iVar2 = *(int *)((int)param_1 + 0x5c);
  iVar3 = *(int *)(iVar2 + 0x24);
  if ((((iVar3 != 1) && (iVar3 != 2)) && (iVar3 != 3)) ||
     ((cVar9 = Car__IsResetGraceActive(), cVar9 != '\0' ||
      (param_1 = 1.4013e-45, *(float *)(iVar2 + 0x3d0) <= 0.0)))) {
    param_1 = 0.0;
  }
  uVar11 = (uint)(0.2 <= *(float *)(*(int *)(iVar7 + 0x54) + 0x1c0));
  if (0.8 < *(float *)(*(int *)(iVar7 + 0x54) + 0x1c0)) {
    uVar11 = 2;
  }
  iVar2 = *(int *)(iVar2 + 0x10);
  if (*(char *)(iVar2 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar1 = *(float *)(&DAT_006f100c + (uVar11 * 0x1b + (int)*(char *)(iVar2 + 0x424)) * 4);
  if (0.0 < *(float *)(*(int *)(iVar7 + 0x4c) + 0x68)) {
    fVar4 = _K_ONE / fVar1;
    fVar5 = fVar4 * *(float *)(*(int *)(iVar7 + 0x4c) + 0x68);
    if (_K_ONE < fVar5) {
      fVar5 = _K_ONE;
    }
    *(float *)(*(int *)(iVar7 + 0x38) + 0x178) =
         (fVar5 + _K_ONE) * *(float *)(*(int *)(iVar7 + 0x38) + 0x178);
    fVar5 = *(float *)(*(int *)(iVar7 + 0x4c) + 0x68) * fVar4;
    if (_K_ONE < fVar5) {
      fVar5 = _K_ONE;
    }
    *(float *)(*(int *)(iVar7 + 0x3c) + 0x178) =
         (fVar5 + _K_ONE) * *(float *)(*(int *)(iVar7 + 0x3c) + 0x178);
    fVar5 = *(float *)(*(int *)(iVar7 + 0x4c) + 0x68) * fVar4;
    if (_K_ONE < fVar5) {
      fVar5 = _K_ONE;
    }
    *(float *)(*(int *)(iVar7 + 0x40) + 0x178) =
         (fVar5 + _K_ONE) * *(float *)(*(int *)(iVar7 + 0x40) + 0x178);
    fVar4 = fVar4 * *(float *)(*(int *)(iVar7 + 0x4c) + 0x68);
    if (_K_ONE < fVar4) {
      fVar4 = _K_ONE;
    }
    *(float *)(*(int *)(iVar7 + 0x44) + 0x178) =
         (fVar4 + _K_ONE) * *(float *)(*(int *)(iVar7 + 0x44) + 0x178);
  }
  if (param_1 != 0.0) {
    iVar2 = *(int *)(iVar7 + 0x58);
    if (*(int *)(iVar2 + 0x3c8) == 0) {
      if ((*DAT_0073619c == 4) && (*(float *)(iVar2 + 0x390) * 2.237 < _DAT_006fff00)) {
        iVar3 = *(int *)(iVar7 + 0x38);
        fVar6 = _K_ONE / _DAT_006ffefc;
        local_c = 0.0;
        fVar5 = *(float *)(iVar3 + 0x158) * fVar6 * *(float *)(iVar3 + 0x160);
        fVar4 = *(float *)(iVar3 + 0x160);
        if (fVar5 <= *(float *)(iVar3 + 0x160)) {
          fVar4 = fVar5;
        }
        if (0.0 < fVar4) {
          local_c = fVar4;
        }
        fVar8 = local_c;
        iVar3 = *(int *)(iVar7 + 0x3c);
        fVar5 = *(float *)(iVar3 + 0x158) * fVar6 * *(float *)(iVar3 + 0x160);
        fVar4 = *(float *)(iVar3 + 0x160);
        if (fVar5 <= *(float *)(iVar3 + 0x160)) {
          fVar4 = fVar5;
        }
        if (local_c < fVar4) {
          local_c = fVar4;
        }
        uVar11 = (uint)(fVar8 < fVar4);
        iVar3 = *(int *)(iVar7 + 0x40);
        fVar5 = *(float *)(iVar3 + 0x158) * fVar6 * *(float *)(iVar3 + 0x160);
        fVar4 = *(float *)(iVar3 + 0x160);
        if (fVar5 <= *(float *)(iVar3 + 0x160)) {
          fVar4 = fVar5;
        }
        if (local_c < fVar4) {
          uVar11 = 0;
          local_c = fVar4;
        }
        iVar3 = *(int *)(iVar7 + 0x44);
        param_1 = *(float *)(iVar3 + 0x158) * fVar6 * *(float *)(iVar3 + 0x160);
        fVar4 = *(float *)(iVar3 + 0x160);
        if (param_1 <= *(float *)(iVar3 + 0x160)) {
          fVar4 = param_1;
        }
        if (local_c < fVar4) {
          uVar11 = 3;
          local_c = fVar4;
        }
        if (_K_HALF < local_c) {
          Curve_Evaluate(&param_1,local_c);
          *(float *)(iVar2 + 0x3d0) = (_K_ONE / fVar1) * param_1;
          param_1 = (float)(uVar11 & 1);
          uVar10 = _ftol_nocw();
          *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3c8) = uVar10;
          *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3cc) = DAT_006fff04;
          *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3d4) = 0;
        }
      }
    }
    else {
      if (1.0 <= *(float *)(iVar2 + 0x390)) {
        fVar13 = (float10)CarState__GetYaw();
      }
      else {
        fVar13 = (float10)0.0;
      }
      if (ABS(fVar13) <= (float10)_DAT_006ffef4) {
        if ((((_DAT_006ffef0 <= *(float *)(*(int *)(iVar7 + 0x38) + 0x160)) ||
             (_DAT_006ffef0 <= *(float *)(*(int *)(iVar7 + 0x3c) + 0x160))) ||
            (_DAT_006ffef0 <= *(float *)(*(int *)(iVar7 + 0x40) + 0x160))) ||
           (_DAT_006ffef0 <= *(float *)(*(int *)(iVar7 + 0x44) + 0x160))) {
          *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3d4) = 0;
          fVar1 = *(float *)(*(int *)(iVar7 + 0x58) + 0x3cc) - DAT_0073457c;
          *(float *)(*(int *)(iVar7 + 0x58) + 0x3cc) = fVar1;
          uVar10 = DAT_006fff04;
          if (fVar1 < 0.0) {
            *(int *)(*(int *)(iVar7 + 0x58) + 0x3c8) = *(int *)(*(int *)(iVar7 + 0x58) + 0x3c8) + -1
            ;
            *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3cc) = uVar10;
          }
        }
        else {
          fVar1 = DAT_0073457c + *(float *)(*(int *)(iVar7 + 0x58) + 0x3d4);
          *(float *)(*(int *)(iVar7 + 0x58) + 0x3d4) = fVar1;
          if (_DAT_006ffef8 < fVar1) {
            *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3c8) = 0;
          }
        }
      }
      else {
        *(undefined4 *)(*(int *)(iVar7 + 0x58) + 0x3c8) = 0;
      }
    }
    if (*(int *)(*(int *)(iVar7 + 0x58) + 0x3c8) != 0) {
      *(float *)(*(int *)(iVar7 + 0x38) + 0x178) =
           _DAT_006ffeec * *(float *)(*(int *)(iVar7 + 0x38) + 0x178);
      uVar11 = *(uint *)(*(int *)(iVar7 + 0x58) + 0x3c8) & 0x80000001;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
      }
      if (uVar11 == 1) {
        *(float *)(*(int *)(iVar7 + 0x38) + 0x178) =
             *(float *)(*(int *)(iVar7 + 0x58) + 0x3d0) * *(float *)(*(int *)(iVar7 + 0x38) + 0x178)
        ;
      }
      *(float *)(*(int *)(iVar7 + 0x3c) + 0x178) =
           _DAT_006ffeec * *(float *)(*(int *)(iVar7 + 0x3c) + 0x178);
      uVar11 = *(uint *)(*(int *)(iVar7 + 0x58) + 0x3c8) & 0x80000001;
      bVar12 = uVar11 == 0;
      if ((int)uVar11 < 0) {
        bVar12 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar12) {
        *(float *)(*(int *)(iVar7 + 0x3c) + 0x178) =
             *(float *)(*(int *)(iVar7 + 0x58) + 0x3d0) * *(float *)(*(int *)(iVar7 + 0x3c) + 0x178)
        ;
      }
      *(float *)(*(int *)(iVar7 + 0x40) + 0x178) =
           _DAT_006ffeec * *(float *)(*(int *)(iVar7 + 0x40) + 0x178);
      uVar11 = *(uint *)(*(int *)(iVar7 + 0x58) + 0x3c8) & 0x80000001;
      bVar12 = uVar11 == 0;
      if ((int)uVar11 < 0) {
        bVar12 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar12) {
        *(float *)(*(int *)(iVar7 + 0x40) + 0x178) =
             *(float *)(*(int *)(iVar7 + 0x58) + 0x3d0) * *(float *)(*(int *)(iVar7 + 0x40) + 0x178)
        ;
      }
      *(float *)(*(int *)(iVar7 + 0x44) + 0x178) =
           _DAT_006ffeec * *(float *)(*(int *)(iVar7 + 0x44) + 0x178);
      uVar11 = *(uint *)(*(int *)(iVar7 + 0x58) + 0x3c8) & 0x80000001;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
      }
      if (uVar11 == 1) {
        *(float *)(*(int *)(iVar7 + 0x44) + 0x178) =
             *(float *)(*(int *)(iVar7 + 0x58) + 0x3d0) * *(float *)(*(int *)(iVar7 + 0x44) + 0x178)
        ;
      }
    }
  }
  return;
}


// ==== 0x479c30 FUN_00479c30

/* WARNING: Type propagation algorithm not settling */

void FUN_00479c30(void)

{
  int iVar1;
  int unaff_ESI;
  float local_60 [5];
  undefined4 local_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  
  if (((((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) ||
       ((DAT_00735fa0 == 0 && ((DAT_0078a345 == '\0' && (DAT_007361a4 == 0)))))) &&
      (*(float *)(*(int *)(*(int *)(unaff_ESI + 0x4c) + 0x18) + 0x10) < 0.2)) &&
     ((iVar1 = *(int *)(unaff_ESI + 0x5c), *(int *)(iVar1 + 0x3cc) == 4 &&
      (SQRT(*(float *)(iVar1 + 0x78) * *(float *)(iVar1 + 0x78) +
            *(float *)(iVar1 + 0x74) * *(float *)(iVar1 + 0x74) +
            *(float *)(iVar1 + 0x70) * *(float *)(iVar1 + 0x70)) < 44.7)))) {
    FUN_00587de0();
    FUN_00587de0();
    if ((0.0 < local_60[0]) && (0.0 < local_60[4])) {
      local_60[2] = 0.0;
      local_60[1] = 0.0;
      local_48 = 0.0;
      local_4c = 0;
      D3DXVec3Transform(local_60,local_60,*(int *)(unaff_ESI + 0x5c) + 0x90);
      D3DXVec3Transform(local_60 + 1,local_60 + 1,*(int *)(unaff_ESI + 0x5c) + 0x90);
      local_60[4] = -*(float *)(*(int *)(*(int *)(unaff_ESI + 0x5c) + 0x20) + 8);
      local_60[2] = 0.0;
      local_60[3] = 0.0;
      FUN_00567540();
      FUN_00567540();
      fStack_30 = fStack_40 + fStack_30;
      local_60[2] = (local_48 + fStack_38) * -1.75;
      local_60[3] = (fStack_44 + fStack_34) * -1.75;
      local_60[4] = fStack_30 * -1.75;
      FUN_00584e00();
    }
  }
  return;
}


// ==== 0x479e20 FUN_00479e20

void FUN_00479e20(float param_1)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int unaff_EDI;
  float10 fVar10;
  undefined4 local_8;
  
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x5c) + 0x14);
  if ((*(int *)(iVar2 + 4) == 1) && (*(char *)(iVar2 + 0x734) == '\0')) {
    cVar4 = FUN_0043a2e0();
    if (cVar4 != '\0') {
      if (*(int *)(unaff_EDI + 0x88) == 0) {
        uVar9 = DAT_006f227c % 0x2ac;
        uVar8 = DAT_006f227c ^ 0x1d872b41;
        uVar5 = uVar8 >> 5 ^ uVar8;
        DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar8;
        iVar2 = *(int *)(unaff_EDI + 0x5c);
        puVar1 = (uint *)(uVar9 + *(int *)(*(int *)(unaff_EDI + 0x5c) + 0x20));
        *(uint **)(unaff_EDI + 0x88) = puVar1;
        iVar6 = _ftol_nocw();
        iVar7 = _ftol_nocw();
        *(int *)(unaff_EDI + 0x8c) = iVar7 - iVar6;
        *(uint *)(unaff_EDI + 0x84) =
             *puVar1 ^ (uint)(*(float *)(iVar2 + 0x3d0) + (float)(iVar7 - iVar6));
        if (*(float *)(unaff_EDI + 0x80) == 0.0) {
          iVar2 = *(int *)(iVar2 + 0x20);
          fVar10 = (float10)CarState__GetNitrousStoredSeconds();
          *(uint *)(unaff_EDI + 0x80) =
               *puVar1 ^ (uint)(float)(((float10)*(float *)(iVar2 + 0x2a0) - fVar10) +
                                      (float10)*(int *)(unaff_EDI + 0x8c));
        }
      }
      local_8 = (float)(**(uint **)(unaff_EDI + 0x88) ^ *(uint *)(unaff_EDI + 0x80)) -
                (float)*(int *)(unaff_EDI + 0x8c);
      cVar4 = CarState__IsNitrousOn();
      if (cVar4 != '\0') {
        local_8 = local_8 + param_1;
      }
      iVar2 = *(int *)(*(int *)(unaff_EDI + 0x5c) + 0x20);
      if (*(float *)(iVar2 + 0x2a0) + 0.1 < local_8) {
        local_8 = *(float *)(iVar2 + 0x2a0);
        *(undefined4 *)(*(int *)(unaff_EDI + 0x58) + 0x3b8) = 0;
        CarState__StopNitrous();
      }
      fVar3 = *(float *)(*(int *)(unaff_EDI + 0x5c) + 0x3d0);
      fVar10 = (float10)RideInfo__GetTheoreticalTopSpeed();
      if ((fVar10 * (float10)1.15 < (float10)fVar3) &&
         (*(int *)(*(int *)(unaff_EDI + 0x5c) + 0x18) != 0)) {
        *(undefined4 *)(unaff_EDI + 0x88) = 0;
        FUN_00428080();
        return;
      }
      uVar9 = DAT_006f227c % 0x2ac;
      uVar8 = DAT_006f227c ^ 0x1d872b41;
      uVar5 = uVar8 >> 5 ^ uVar8;
      DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar8;
      puVar1 = (uint *)(uVar9 + *(int *)(*(int *)(unaff_EDI + 0x5c) + 0x20));
      iVar2 = *(int *)(unaff_EDI + 0x5c);
      *(uint **)(unaff_EDI + 0x88) = puVar1;
      iVar6 = _ftol_nocw();
      iVar7 = _ftol_nocw();
      *(int *)(unaff_EDI + 0x8c) = iVar7 - iVar6;
      *(uint *)(unaff_EDI + 0x84) =
           *puVar1 ^ (uint)(*(float *)(iVar2 + 0x3d0) + (float)(iVar7 - iVar6));
      *(uint *)(unaff_EDI + 0x80) = *puVar1 ^ (uint)((float)*(int *)(unaff_EDI + 0x8c) + local_8);
    }
  }
  return;
}


// ==== 0x47a090 FUN_0047a090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047a090(int param_1,undefined4 param_2)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  int iVar8;
  float *pfVar9;
  char *pcVar10;
  int iVar11;
  undefined4 *puVar12;
  bool bVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  
  *(undefined1 *)(param_1 + 0x69) = 0;
  uVar2 = DAT_0078f1cc & 1;
  *(undefined1 *)(param_1 + 0x68) = 0;
  if (uVar2 == 0) {
    DAT_0078f1cc = DAT_0078f1cc | 1;
    DAT_0078f1a8 = 4;
    DAT_0078f1a9 = 0x20;
    DAT_0078f1aa = 0;
    DAT_0078f1ab = 0;
    _DAT_0078f1a4 = &PTR_FUN_006b9694;
    _DAT_0078f1ac = 0;
    _DAT_0078f1b0 = 0.0;
    _DAT_0078f1b4 = (undefined4 *)&DAT_0078f1b8;
    _DAT_0078f1b4 = _malloc(0x80);
    puVar12 = _DAT_0078f1b4;
    for (iVar8 = 0x20; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    _atexit(FUN_00696410);
  }
  uVar6 = DAT_00700520;
  uVar5 = DAT_0070051c;
  if ((DAT_0078f1cc & 2) == 0) {
    DAT_0078f1cc = DAT_0078f1cc | 2;
    FUN_00584180(DAT_0070051c);
    FUN_00584180(uVar5);
    FUN_00584180(uVar6);
    _DAT_0078f198 = 0x41f00000;
    _DAT_0078f19c = 0.0;
    _DAT_0078f1a0 = 0;
    _atexit(FUN_00696400);
  }
  uVar6 = _DAT_007372a8;
  uVar5 = DAT_007372a0;
  iVar8 = DAT_00735fb8;
  iVar11 = 0;
  if (DAT_00735fb8 == 0) {
    _DAT_0072cc10 = **(undefined4 **)(*(int *)(param_1 + 0x5c) + 0x10);
    _DAT_0078eb48 = (float)DAT_0073ad34 * 0.00025;
    _DAT_0073453c = 1;
    _DAT_0072cc20 = 0;
    _DAT_0072cc1c = 0.0;
    _DAT_0072cc28 = 0;
    _DAT_0072cc24 = 0.0;
    _DAT_0072cc2c = 0.0;
    _DAT_0072cc30 = 0.0;
    _DAT_0072cc34 = -1.0;
    _DAT_0072cc38 = 0.0;
    _DAT_0072cc3c = 0.0;
    _DAT_0078f118 = 0.0;
    _DAT_0078eb44 = 0;
    DAT_0078f110 = 0.0;
    DAT_0078f114 = 0.0;
    DAT_0078f10c = 0;
    _DAT_0078f108 = 0;
    _DAT_0078f19c = 0.0;
    _DAT_0078f1a0 = 0;
    FUN_005842d0(0);
    _DAT_0078f19c = 0.0;
    _DAT_0078f1a0 = 0;
    FUN_005842d0(0);
    FUN_005842d0(0);
    _DAT_0078f104 = 50.0;
    DAT_00735fb8 = 999;
    return;
  }
  if (DAT_00735fb8 == 999) {
    iVar8 = *(int *)(param_1 + 0x20);
    if ((SQRT(*(float *)(iVar8 + 200) * *(float *)(iVar8 + 200) +
              *(float *)(iVar8 + 0xc4) * *(float *)(iVar8 + 0xc4) +
              *(float *)(iVar8 + 0xc0) * *(float *)(iVar8 + 0xc0)) == 0.0) &&
       (SQRT(*(float *)(iVar8 + 0xa8) * *(float *)(iVar8 + 0xa8) +
             *(float *)(iVar8 + 0xa4) * *(float *)(iVar8 + 0xa4) +
             *(float *)(iVar8 + 0xa0) * *(float *)(iVar8 + 0xa0)) == 0.0)) {
      DAT_00735fb8 = 1;
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x1e4) = 0x3f800000;
    return;
  }
  if (DAT_00735fb8 == 1) {
    if ((DAT_00735fb4 != 0) && (DAT_00735fb4 != 1)) {
      DAT_00735fb8 = 2;
      return;
    }
    bVar13 = DAT_0078f10c == '\0';
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x1e4) = 0;
    if (bVar13) {
      (**(code **)(**(int **)(param_1 + 4) + 0x2c))(1);
      FUN_0046e5b0(1);
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = 0x3f400000;
      iVar8 = DAT_00735fb8;
      if (0.0 <= *(float *)(*(int *)(param_1 + 0x48) + 0x14) * 9.549304) {
        DAT_0078f10c = '\x01';
        (**(code **)(**(int **)(param_1 + 4) + 0x2c))(0xffffffff);
        FUN_0046e5b0(0xffffffff);
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = 0x3f800000;
        iVar8 = DAT_00735fb8;
      }
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = 0x3f800000;
    }
    if (0.0 < DAT_0072cc58) {
      _DAT_0072cc14 = DAT_0072cc58;
    }
    cVar7 = 0.0 < DAT_0072cc58;
    if (0.0 < DAT_0072cc0c) {
      _DAT_0072cc18 = DAT_0072cc0c;
      cVar7 = cVar7 + '\x01';
    }
    if (0.0 < DAT_0072cc44) {
      _DAT_0072cc1c = DAT_0072cc44;
      _DAT_0072cc20 = DAT_0072cc78;
      cVar7 = cVar7 + '\x01';
    }
    if (0.0 < DAT_0072cc70) {
      _DAT_0072cc24 = DAT_0072cc70;
      _DAT_0072cc28 = DAT_0072cc64;
      cVar7 = cVar7 + '\x01';
    }
    if (cVar7 == '\x04') {
      DAT_00735fb8 = iVar8 + 1;
      return;
    }
  }
  else {
    if (DAT_00735fb8 == 2) {
      if ((DAT_00735fb4 == 0) || (DAT_00735fb4 == 2)) {
        bVar13 = _DAT_0078eb48 == -1.0;
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x1e4) = 0;
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = 0x3f800000;
        if (bVar13) {
          _DAT_0078eb48 = (float)DAT_0073ad34 * 0.00025;
        }
        fVar1 = (float)DAT_0073ad34 * 0.00025;
        DAT_0072cc60 = fVar1 - _DAT_0072cc48;
        fVar3 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
        fVar4 = fVar3 - _DAT_0072cc2c;
        if (fVar4 < 1.0 == (fVar4 == 1.0)) {
          _DAT_0078eb48 = fVar1;
          _DAT_0072cc2c = fVar3;
          _DAT_0072cc30 = DAT_0072cc60;
          return;
        }
        if (fVar1 - _DAT_0078eb48 < 2.0) {
          return;
        }
        _DAT_0078eb48 = -1.0;
      }
      DAT_00735fb8 = 3;
      return;
    }
    if (DAT_00735fb8 == 3) {
      if ((DAT_00735fb4 != 0) && (DAT_00735fb4 != 3)) {
                    /* WARNING: Read-only address (ram,0x006cc7bc) is written */
        DAT_00735fb8 = 4;
        return;
      }
      if (_DAT_0072cc34 == -1.0) {
        if (80.0 <= *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237) {
          _DAT_0072cc34 = (float)DAT_0073ad34 * 0.00025;
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = 0x3f800000;
        }
      }
      if (-1.0 < _DAT_0072cc34) {
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = 0;
        fVar1 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
        if (fVar1 < 80.0 == (fVar1 == 80.0)) {
          *(undefined4 *)(*(int *)(param_1 + 4) + 0x1e4) = 0x3dcccccd;
          _DAT_0072cc34 = (float)DAT_0073ad34 * 0.00025;
          return;
        }
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x1e4) = 0x3f800000;
        fVar1 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
        if (fVar1 < _K_ONE != (fVar1 == _K_ONE)) {
          _DAT_0072cc34 = ((float)DAT_0073ad34 * 0.00025 - _DAT_0072cc34) * 80.0 * 0.73333335;
          DAT_00735fb8 = 4;
          return;
        }
      }
    }
    else if (DAT_00735fb8 == 4) {
      DAT_00735fbc = 0;
      if ((DAT_00735fb4 != 0) && (DAT_00735fb4 != 4)) {
        DAT_00735fb8 = 5;
        return;
      }
      FUN_00584610(_DAT_0078f104 * 0.44702727 - *(float *)(*(int *)(param_1 + 0x5c) + 0x3d4),param_2
                   ,0,0);
      fVar14 = (float10)bClampF(DAT_0078f17c,-DAT_00700524,DAT_00700524);
      fVar15 = (float10)PsychoDriver_ScaledRatioTerm();
      fVar16 = (float10)_DAT_0078f19c;
      fVar17 = (float10)FUN_00583ea0(ABS(*(float *)(*(int *)(param_1 + 0x5c) + 0x3d4)));
      iVar8 = *(int *)(param_1 + 4);
      fVar14 = (float10)bClampF((float)(fVar16 * (float10)0.1 +
                                       (fVar15 + (float10)(float)fVar14) * (float10)0.02),
                                -(float)fVar17,(float)fVar17,-_DAT_007003f8,0x3f800000);
      fVar14 = (float10)bClampF((float)(((float10)_DAT_0078f118 - (float10)*(float *)(iVar8 + 0x1e4)
                                        ) + fVar14));
      if (fVar14 <= (float10)0.0) {
        fVar14 = (float10)0.0;
      }
      _DAT_0078f118 = (float)fVar14;
      *(float *)(iVar8 + 0x1dc) = (float)fVar14;
      fVar1 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
      fVar3 = ABS(fVar1 - _DAT_0078f104);
      if (fVar3 < 1.0 == (fVar3 == 1.0)) {
        _DAT_0078eb48 = (float)DAT_0073ad34 * 0.00025;
        _DAT_0072cc38 = fVar1;
      }
      else if (2.0 <= (float)DAT_0073ad34 * 0.00025 - _DAT_0078eb48) {
        _DAT_0078f104 = _DAT_0078f104 + 1.0;
        _DAT_0078eb48 = (float)DAT_0073ad34 * 0.00025;
      }
      fVar1 = *(float *)(*(int *)(param_1 + 0x58) + 0x390);
      fVar1 = (fVar1 / 45.72) * fVar1 * 0.10204081;
      if (DAT_0078f114 < fVar1) {
        DAT_0078f110 = *(float *)(*(int *)(param_1 + 0x58) + 0x390) * 2.237;
        _DAT_0072cc3c = fVar1;
        DAT_0078f114 = fVar1;
      }
      fVar14 = (float10)FUN_0044ca20();
      FUN_00584270((float)fVar14);
      iVar8 = *(int *)(param_1 + 0x58);
      if (50.0 <= *(float *)(iVar8 + 0x390) * 2.237) {
        pcVar10 = (char *)(iVar8 + 0x310);
        pfVar9 = (float *)(iVar8 + 0x338);
        iVar8 = 4;
        do {
          if ((*pcVar10 == '\0') || (5.0 < ABS(*pfVar9))) {
            iVar11 = iVar11 + 1;
          }
          pfVar9 = pfVar9 + 2;
          pcVar10 = pcVar10 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if ((0 < iVar11) || (3.5 < _DAT_0078f1b0)) {
          _DAT_0072cc38 = DAT_0078f110;
          DAT_0072cc40 = (char)iVar11;
          _DAT_0072cc3c = DAT_0078f114;
          DAT_0078f110 = 0.0;
          DAT_0078f114 = 0.0;
          _DAT_0078eb48 = -1.0;
          DAT_00735fb8 = DAT_00735fb8 + 1;
          return;
        }
      }
    }
    else {
      iVar8 = *(int *)(param_1 + 0x20);
      *(undefined4 *)(iVar8 + 0x74) = _DAT_007372a4;
      *(undefined4 *)(iVar8 + 0x70) = uVar5;
      *(undefined4 *)(iVar8 + 0x78) = uVar6;
      uVar6 = _DAT_007372a8;
      uVar5 = DAT_007372a0;
      iVar8 = *(int *)(param_1 + 0x20);
      *(undefined4 *)(iVar8 + 0x84) = _DAT_007372a4;
      *(undefined4 *)(iVar8 + 0x80) = uVar5;
      *(undefined4 *)(iVar8 + 0x88) = uVar6;
      FUN_0046e5b0(2);
      DAT_00735fb8 = 0;
      DAT_00735fb0 = 0;
      DAT_00735fbc = 0;
      _DAT_0073453c = 0;
    }
  }
                    /* WARNING: Read-only address (ram,0x006cc7bc) is written */
  return;
}


// ==== 0x47aa40 FUN_0047aa40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0047aa40(undefined4 param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (((*(float *)(*(int *)(param_3 + 0x30) + 0x1dc) <= 0.3) || (*(int *)(param_3 + 0x3d8) == 1)) ||
     (*(int *)(param_3 + 0x3cc) < 1)) {
    fVar1 = SQRT(*(float *)(param_2 + 0xa8) * *(float *)(param_2 + 0xa8) +
                 *(float *)(param_2 + 0xa4) * *(float *)(param_2 + 0xa4) +
                 *(float *)(param_2 + 0xa0) * *(float *)(param_2 + 0xa0));
    fVar2 = SQRT(*(float *)(param_2 + 200) * *(float *)(param_2 + 200) +
                 *(float *)(param_2 + 0xc4) * *(float *)(param_2 + 0xc4) +
                 *(float *)(param_2 + 0xc0) * *(float *)(param_2 + 0xc0));
    if (((fVar1 <= 0.7) && (fVar2 <= 0.7)) &&
       (((ABS(*(float *)(param_2 + 0x38)) <= 0.15 && (ABS(*(float *)(param_2 + 0x48)) <= 0.15)) ||
        (*(int *)(param_3 + 0x3cc) < 1)))) {
      cVar4 = Car__IsResetGraceActive();
      if (cVar4 == '\0') {
        iVar5 = FUN_0042aa70();
        if ((iVar5 != 0) || (param_4 == 2)) {
          iVar5 = 0;
          if (DAT_00735fcc == 0) {
LAB_0047abb7:
            if ((fVar1 <= 0.25) && (fVar2 <= 0.25)) {
              return 2;
            }
            return 1;
          }
          iVar6 = (int)*(char *)(*(int *)(param_3 + 0x3c) + 0x1c);
          bVar3 = false;
          if (0 < iVar6) {
            do {
              iVar7 = FUN_00468820(iVar5);
              cVar4 = Collision_IsFlatSurfaceInvolved();
              if (cVar4 != '\0') {
                iVar8 = FUN_0041f5e0();
                if (_DAT_006fff0c < *(float *)(iVar8 + 8) - *(float *)(iVar7 + 0x38)) {
                  bVar3 = true;
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar6);
            if (bVar3) goto LAB_0047abb7;
          }
        }
      }
    }
  }
  return 0;
}


// ==== 0x47ac00 FUN_0047ac00

undefined4 FUN_0047ac00(int param_1,int *param_2,int *param_3)

{
  int in_EAX;
  int iVar1;
  int extraout_EDX;
  int unaff_ESI;
  undefined8 uVar2;
  
  iVar1 = FUN_0047aa40(param_1,*param_3);
  *param_3 = iVar1;
  if (iVar1 == 0) {
    if (0.8 < SQRT(*(float *)(unaff_ESI + 0xa8) * *(float *)(unaff_ESI + 0xa8) +
                   *(float *)(unaff_ESI + 0xa4) * *(float *)(unaff_ESI + 0xa4) +
                   *(float *)(unaff_ESI + 0xa0) * *(float *)(unaff_ESI + 0xa0))) {
      *param_2 = 0;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x3c) + 0x1d) = 1;
    *(undefined4 *)(unaff_ESI + 0x140) = 1;
    return 0;
  }
  if (iVar1 == 1) {
    *(float *)(unaff_ESI + 0x78) = *(float *)(unaff_ESI + 0x78) * 0.95;
    *(float *)(unaff_ESI + 0x70) = *(float *)(unaff_ESI + 0x70) * 0.95;
    *(float *)(unaff_ESI + 0x74) = *(float *)(unaff_ESI + 0x74) * 0.95;
    *(float *)(unaff_ESI + 0x88) = *(float *)(unaff_ESI + 0x88) * 0.95;
    *(float *)(unaff_ESI + 0x80) = *(float *)(unaff_ESI + 0x80) * 0.95;
    *(float *)(unaff_ESI + 0x84) = *(float *)(unaff_ESI + 0x84) * 0.95;
    if (in_EAX != 0) {
      *(float *)(*(int *)(in_EAX + 0x38) + 0x28) = *(float *)(*(int *)(in_EAX + 0x38) + 0x28) * 0.95
      ;
      *(float *)(*(int *)(in_EAX + 0x3c) + 0x28) = *(float *)(*(int *)(in_EAX + 0x3c) + 0x28) * 0.95
      ;
      *(float *)(*(int *)(in_EAX + 0x40) + 0x28) = *(float *)(*(int *)(in_EAX + 0x40) + 0x28) * 0.95
      ;
      *(float *)(*(int *)(in_EAX + 0x44) + 0x28) = *(float *)(*(int *)(in_EAX + 0x44) + 0x28) * 0.95
      ;
    }
    if (0.8 < SQRT(*(float *)(unaff_ESI + 0xa8) * *(float *)(unaff_ESI + 0xa8) +
                   *(float *)(unaff_ESI + 0xa4) * *(float *)(unaff_ESI + 0xa4) +
                   *(float *)(unaff_ESI + 0xa0) * *(float *)(unaff_ESI + 0xa0))) {
      *param_2 = 0;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x3c) + 0x1d) = 1;
    *(undefined4 *)(unaff_ESI + 0x140) = 1;
    return 1;
  }
  if (iVar1 != 2) {
    return 0;
  }
  *(undefined4 *)(unaff_ESI + 0x70) = 0;
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  *(undefined4 *)(unaff_ESI + 0x80) = 0;
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  if ((in_EAX != 0) && (0 < *(int *)(param_1 + 0x3cc))) {
    *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x28) = 0;
    *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x28) = 0;
    *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0x28) = 0;
    *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x28) = 0;
  }
  if (*(float *)(unaff_ESI + 0x58) < 0.1) {
LAB_0047aca6:
    iVar1 = *param_2;
    if ((iVar1 == 0) || (iVar1 == 0x7fffffff)) {
      *param_2 = DAT_0073ad34;
    }
    else if (((in_EAX != 0) && (1.0 < (float)(DAT_0073ad34 - iVar1) * 0.00025)) &&
            (*(short *)(*(int *)(param_1 + 0x1c) + 0x10) == 0)) {
      FUN_00428080();
      param_1 = extraout_EDX;
    }
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x14) + 4) == 1) {
      uVar2 = Car__WheelFlagsAllowSteer();
      param_1 = (int)((ulonglong)uVar2 >> 0x20);
      if ((int)uVar2 != 0) goto LAB_0047aca6;
    }
    *param_2 = 0;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3c) + 0x1d) = 0;
  *(undefined4 *)(unaff_ESI + 0x140) = 0;
  return 1;
}


// ==== 0x47ae70 FUN_0047ae70

void * __thiscall FUN_0047ae70(int param_1,byte param_2)

{
  void *_Memory;
  
  _Memory = (void *)(param_1 + -8);
  FUN_00477250(_Memory);
  if ((param_2 & 1) != 0) {
    _free(_Memory);
  }
  return _Memory;
}


// ==== 0x47ae80 FUN_0047ae80

undefined4 __fastcall FUN_0047ae80(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 4) + 4);
}


// ==== 0x47ae90 CAnimBank::GetAnimByIndex

/* [canon] assets med (ghidra-canon+nfsug) docs/re/assets.md */

undefined4 __thiscall CAnimBank__GetAnimByIndex(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + param_2 * 4);
}


// ==== 0x47aea0 CAnimBank::GetAnimByIndex_Table2

/* [canon] assets med (ghidra-canon+hopper) docs/re/assets.md */

undefined4 __thiscall CAnimBank__GetAnimByIndex_Table2(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + param_2 * 4);
}


// ==== 0x47aeb0 FUN_0047aeb0

undefined4 __thiscall FUN_0047aeb0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = FUN_00627c50(param_2);
  if (iVar2 == -1) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(iVar1 + 0xc) + iVar2 * 4);
}


// ==== 0x47aee0 FUN_0047aee0

void FUN_0047aee0(void)

{
  FUN_00627c50();
  return;
}


// ==== 0x47aef0 FUN_0047aef0

undefined4 __fastcall FUN_0047aef0(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 4) + 8);
}


// ==== 0x47af00 CAnimBank_Loader::scalar_deleting_destructor

/* [canon] assets med (ghidra-canon+nfsug) docs/re/assets.md */

undefined4 * __thiscall
CAnimBank_Loader__scalar_deleting_destructor(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c82f8;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x47af20 AnimBank_DynamicLoad

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 AnimBank_DynamicLoad(undefined4 param_1)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int unaff_ESI;
  uint uStack_4;
  
  iVar2 = (*(code *)PTR_FUN_006dfa9c)(0x2c,"EAGL::DynamicLoader CAnimBank");
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061eee0(param_1,in_EAX,0);
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x20) = in_EAX;
  *(undefined4 *)(unaff_ESI + 8) = 1;
  puVar4 = _malloc(8);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_006c82f8;
    puVar4[1] = 0;
  }
  *(undefined4 **)(unaff_ESI + 0x10) = puVar4;
  param_1 = 0;
  cVar1 = GetFirstAnimBank("AnimationBank",&param_1,&uStack_4);
  uStack_4 = -(uint)(cVar1 != '\0') & uStack_4;
  *(uint *)(unaff_ESI + 0x14) = uStack_4;
  (**(code **)**(undefined4 **)(unaff_ESI + 0x10))(uStack_4);
  return 0;
}


// ==== 0x47afc0 FUN_0047afc0

void FUN_0047afc0(void)

{
  int iVar1;
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined1 *)(in_EAX + 0x30) = 0;
  if (*(int **)(in_EAX + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x10) + 0x1c))(1);
  }
  if (*(void **)(in_EAX + 0x14) != (void *)0x0) {
    _free(*(void **)(in_EAX + 0x14));
  }
  iVar1 = *(int *)(in_EAX + 0x1c);
  if (iVar1 != 0) {
    FUN_0061ef30();
    (*(code *)PTR_FUN_006dfaa0)(iVar1,0x2c);
  }
  return;
}


// ==== 0x47b020 EAGLAnim::Pool_Free

/* [canon] assets med (ghidra-canon+nfsug) docs/re/assets.md */

void EAGLAnim__Pool_Free(undefined4 param_1)

{
  (**(code **)(*DAT_0070d364 + 0x2c))(param_1);
  return;
}


// ==== 0x47b040 CAnimCtrl::InitFields

/* [canon] assets med (ghidra-canon+nfsug) docs/re/assets.md */

void CAnimCtrl__InitFields(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x30) = 0xbf800000;
  *(undefined4 *)(in_EAX + 0x24) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x28) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x38) = 0;
  *(undefined4 *)(in_EAX + 0x3c) = 0;
  *(undefined4 *)(in_EAX + 0x40) = 0;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  *(undefined4 *)(in_EAX + 0x34) = 0;
  *(undefined4 *)(in_EAX + 0x48) = 0;
  *(undefined4 *)(in_EAX + 0x4c) = 0;
  *(undefined4 *)(in_EAX + 0x50) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x58) = 0;
  *(undefined4 *)(in_EAX + 0x5c) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  *(undefined4 *)(in_EAX + 0x70) = 0;
  *(undefined4 *)(in_EAX + 0x74) = 0;
  *(undefined4 *)(in_EAX + 100) = 0;
  *(undefined4 *)(in_EAX + 0x68) = 0;
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  *(undefined4 *)(in_EAX + 0x78) = 0;
  return;
}


// ==== 0x47b0b0 FUN_0047b0b0

void FUN_0047b0b0(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684fab;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0047b1c0();
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(*(int *)(param_1 + 0x1c),0x40);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  ExceptionList = local_c;
  return;
}


// ==== 0x47b170 FUN_0047b170

void FUN_0047b170(void)

{
  int unaff_ESI;
  
  FUN_0047b1c0();
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  *(undefined4 *)(unaff_ESI + 0x58) = 0;
  *(undefined4 *)(unaff_ESI + 0x5c) = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0x60) = 0;
  *(undefined4 *)(unaff_ESI + 0x70) = 0;
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  *(undefined4 *)(unaff_ESI + 100) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  return;
}


// ==== 0x47b1c0 FUN_0047b1c0

void FUN_0047b1c0(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)(in_EAX + 0xc) = 0;
  if (*(void **)(in_EAX + 0x14) != (void *)0x0) {
    _free(*(void **)(in_EAX + 0x14));
    *(undefined4 *)(in_EAX + 0x14) = 0;
  }
  *(undefined4 *)(in_EAX + 0x18) = 0;
  if (*(int *)(in_EAX + 0x1c) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(*(int *)(in_EAX + 0x1c),0x40);
    *(undefined4 *)(in_EAX + 0x1c) = 0;
  }
  *(undefined4 *)(in_EAX + 0x20) = 0;
  piVar2 = (int *)(in_EAX + 0x38);
  iVar1 = 4;
  do {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_0070d364 + 0x2c))(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== 0x47b220 FUN_0047b220

undefined4 __fastcall FUN_0047b220(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  iVar1 = FUN_0047cda0(param_2,&local_4,&local_8);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_00627d60(local_8);
    *(int **)(unaff_ESI + 0x38 + unaff_EDI * 4) = piVar2;
    (**(code **)(*piVar2 + 0x10))(unaff_ESI + 0x60);
    if (*(int *)(unaff_ESI + 0x38 + unaff_EDI * 4) != 0) {
      *(undefined4 *)(unaff_ESI + 0x78) = 1;
    }
    *(undefined4 *)(unaff_ESI + 0x78) = 1;
    return 1;
  }
  return 0;
}


// ==== 0x47b290 CAnimCtrl::AdvanceAnimTime

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (ghidra-canon+nfsug) docs/re/assets.md */

undefined4 __thiscall CAnimCtrl__AdvanceAnimTime(int param_1,float param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  fVar3 = DAT_006ffdbc * param_2 * *(float *)(param_1 + 0x5c);
  if ((char)uVar1 < '\0') {
    return 0x80;
  }
  if ((uVar1 & 0x10) != 0) {
    fVar2 = fVar3 + *(float *)(param_1 + 100);
    *(float *)(param_1 + 100) = fVar2;
    if (fVar2 <= *(float *)(param_1 + 0x60)) {
      if (fVar2 < 0.0) {
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x60);
      }
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0;
    }
  }
  if ((uVar1 & 0x20) != 0) {
    fVar2 = fVar3 + *(float *)(param_1 + 100);
    if (*(float *)(param_1 + 0x60) < fVar2) {
      return 0x20;
    }
    *(float *)(param_1 + 100) = fVar2;
    if (fVar2 <= *(float *)(param_1 + 0x60)) {
      if (fVar2 < 0.0) {
        *(undefined4 *)(param_1 + 100) = 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x60);
    }
  }
  if ((uVar1 & 0x40) != 0) {
    fVar2 = fVar3 + *(float *)(param_1 + 100);
    *(float *)(param_1 + 100) = fVar2;
    if (fVar2 <= *(float *)(param_1 + 0x60)) {
      if (fVar2 < 0.0) {
        *(undefined4 *)(param_1 + 100) = 0;
        *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) * -1.0;
      }
    }
    else {
      if (*(float *)(param_1 + 0x68) <= 0.0) {
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x60);
        *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) * -1.0;
        return 0;
      }
      fVar3 = fVar3 + *(float *)(param_1 + 0x6c);
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x60);
      *(float *)(param_1 + 0x6c) = fVar3;
      if (_DAT_00735f68 + *(float *)(param_1 + 0x68) < fVar3) {
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) * -1.0;
        return 0;
      }
    }
  }
  return 0;
}


// ==== 0x47b3d0 FUN_0047b3d0

undefined4 FUN_0047b3d0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  
  if (*(int *)(in_EAX + 0x74) == DAT_007364dc) {
    return 1;
  }
  *(int *)(in_EAX + 0x74) = DAT_007364dc;
  *(undefined4 *)(in_EAX + 0x70) = *(undefined4 *)(in_EAX + 100);
  uVar1 = *(undefined4 *)(in_EAX + 0x1c);
  uVar2 = *(undefined4 *)(in_EAX + 0x14);
  if ((*(int **)(in_EAX + 0x3c) != (int *)0x0) && (DAT_006ffdc4 != 0)) {
    (**(code **)(**(int **)(in_EAX + 0x3c) + 0x18))(*(undefined4 *)(in_EAX + 100),uVar2,0);
  }
  if ((*(int **)(in_EAX + 0x40) != (int *)0x0) && (DAT_006ffdc8 != 0)) {
    (**(code **)(**(int **)(in_EAX + 0x40) + 0x18))(*(undefined4 *)(in_EAX + 100),uVar2,0);
  }
  if ((*(int **)(in_EAX + 0x38) != (int *)0x0) && (DAT_006ffdc0 != 0)) {
    (**(code **)(**(int **)(in_EAX + 0x38) + 0x18))(*(undefined4 *)(in_EAX + 100),uVar2,0);
  }
  FUN_00628b30(uVar2,uVar1,0);
  if ((*(byte *)(in_EAX + 0x34) & 1) == 0) {
    return 0;
  }
  iVar4 = *(int *)(*(int *)(*(int *)(in_EAX + 0xc) + 0x20) + 8);
  iVar5 = *(int *)(*(int *)(in_EAX + 0xc) + 0x10);
  iVar3 = *(int *)(in_EAX + 0x1c);
  if (iVar5 != DAT_00779a60) {
    if (iVar5 == DAT_00779a58) {
      puVar6 = &DAT_006fceb8;
      goto LAB_0047b4d9;
    }
    if (iVar5 == DAT_00779a88) {
      puVar6 = &DAT_006fd4b8;
      goto LAB_0047b4d9;
    }
    if (iVar5 == DAT_00779a5c) {
      puVar6 = &DAT_006fdab8;
      goto LAB_0047b4d9;
    }
    if (iVar5 == DAT_00779a64) {
      puVar6 = &DAT_006fe378;
      goto LAB_0047b4d9;
    }
    if (iVar5 == DAT_00779a84) {
      puVar6 = &DAT_006fec38;
      goto LAB_0047b4d9;
    }
    puVar6 = &DAT_006ff4f8;
    if (iVar5 == DAT_00779a80) goto LAB_0047b4d9;
  }
  puVar6 = &DAT_006fc5f8;
LAB_0047b4d9:
  if (0 < iVar4) {
    iVar5 = iVar3;
    do {
      D3DXMatrixMultiply(iVar5,puVar6 + (iVar5 - iVar3),iVar5);
      iVar5 = iVar5 + 0x40;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 0;
}


// ==== 0x47b500 FUN_0047b500

void FUN_0047b500(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *unaff_ESI;
  
  if (*(int *)(in_EAX + 0xc) == 0) {
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
    return;
  }
  uVar1 = *(undefined4 *)(in_EAX + 0x1c);
  uVar2 = *(undefined4 *)(in_EAX + 0x14);
  if (*(int **)(in_EAX + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x3c) + 0x18))(param_1,uVar2,0);
  }
  if (*(int **)(in_EAX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x40) + 0x18))(param_1,uVar2,0);
  }
  if (*(int **)(in_EAX + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x38) + 0x18))(param_1,uVar2,0);
  }
  FUN_00628b30(uVar2,uVar1,0);
  bMatrixCopy_b();
  return;
}


// ==== 0x47b5c0 FUN_0047b5c0

void FUN_0047b5c0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 0;
  if ((void *)unaff_ESI[2] != (void *)0x0) {
    _free((void *)unaff_ESI[2]);
    unaff_ESI[2] = 0;
  }
  unaff_ESI[3] = 0;
  if (unaff_ESI[4] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(unaff_ESI[4],0x40);
    unaff_ESI[4] = 0;
  }
  unaff_ESI[5] = 0;
  return;
}


// ==== 0x47b600 FUN_0047b600

undefined4 FUN_0047b600(undefined4 param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = 0;
  if ((void *)unaff_ESI[2] != (void *)0x0) {
    _free((void *)unaff_ESI[2]);
    unaff_ESI[2] = 0;
  }
  unaff_ESI[3] = 0;
  if (unaff_ESI[4] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(unaff_ESI[4],0x40);
    unaff_ESI[4] = 0;
  }
  unaff_ESI[8] = param_2;
  unaff_ESI[5] = 0;
  *unaff_ESI = unaff_EDI;
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x20) + 8);
  unaff_ESI[3] = iVar2 * 0xc;
  pvVar1 = _malloc(iVar2 * 0x30);
  unaff_ESI[2] = (int)pvVar1;
  if (pvVar1 != (void *)0x0) {
    iVar2 = *(int *)(*(int *)(unaff_EDI + 0x20) + 8);
    unaff_ESI[5] = iVar2;
    iVar2 = (*(code *)PTR_FUN_006dfa9c)(iVar2 << 6,"EAGL::Transform GlobalPoseBuffer CAnimPart");
    unaff_ESI[4] = iVar2;
    if (iVar2 != 0) {
      FUN_00628c90(unaff_ESI[2],0);
      return 1;
    }
  }
  *unaff_ESI = 0;
  if ((void *)unaff_ESI[2] != (void *)0x0) {
    _free((void *)unaff_ESI[2]);
    unaff_ESI[2] = 0;
  }
  unaff_ESI[3] = 0;
  if (unaff_ESI[4] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(unaff_ESI[4],0x40);
    unaff_ESI[4] = 0;
  }
  unaff_ESI[5] = 0;
  return 0;
}


// ==== 0x47b6d0 FUN_0047b6d0

void FUN_0047b6d0(void)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 local_14;
  undefined4 local_10 [2];
  int local_8;
  
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    local_10[0] = 0;
    local_8 = 0;
    local_14 = 0;
    cVar1 = FUN_0061e6d0("Skeleton",&local_14,local_10);
    if (cVar1 != '\0') {
      *(undefined4 *)(unaff_ESI + 0xc) = local_10[0];
      uVar2 = bStringHash();
      *(undefined4 *)(unaff_ESI + 0x10) = uVar2;
      *(int *)(unaff_ESI + 0x20) = local_8;
      *(uint *)(unaff_ESI + 8) = (uint)(local_8 != 0);
      return;
    }
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
  }
  return;
}


// ==== 0x47b730 PostRaceScene_ShuffleList

/* [canon] assets high (ghidra-canon+nfsug) docs/re/assets.md */

void PostRaceScene_ShuffleList(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2 < 0xc) {
    uVar5 = *(uint *)(param_1 + param_2 * 4);
    iVar6 = 0;
    if (0 < (int)uVar5) {
      do {
        uVar5 = *(uint *)(DAT_007361f8 + 0x2d0) % uVar5;
        uVar4 = *(uint *)(DAT_007361f8 + 0x2d0) ^ 0x1d872b41;
        uVar3 = uVar4 >> 5 ^ uVar4;
        *(uint *)(DAT_007361f8 + 0x2d0) = uVar3 << 0x1b ^ uVar3 ^ uVar4;
        iVar1 = *(int *)(param_1 + 0x30 + param_2 * 4);
        uVar2 = *(undefined4 *)(iVar1 + iVar6 * 4);
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar1 + -4 + iVar6 * 4) = *(undefined4 *)(iVar1 + uVar5 * 4);
        *(undefined4 *)(*(int *)(param_1 + 0x30 + param_2 * 4) + uVar5 * 4) = uVar2;
        uVar5 = *(uint *)(param_1 + param_2 * 4);
      } while (iVar6 < (int)uVar5);
    }
  }
  return;
}


// ==== 0x47b7b0 PostRaceScene_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 PostRaceScene_Load(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 == 0x34036) {
    DAT_00735f64 = param_1 + 2;
    piVar1 = param_1 + 0xe;
    *piVar1 = (int)(param_1 + 0x1a);
    iVar2 = 0xb;
    do {
      piVar1[1] = *piVar1 + piVar1[-0xc] * 4;
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    return 1;
  }
  return 0;
}


// ==== 0x47b7f0 PostRaceScene_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 PostRaceScene_Unload(int *param_1)

{
  if (*param_1 == 0x34036) {
    DAT_00735f64 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x47b810 FUN_0047b810

void FUN_0047b810(void)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *in_EAX;
  int *piVar4;
  
  _Memory = (int *)*in_EAX;
  piVar4 = (int *)NullUpdate_ret();
  while (_Memory != piVar4) {
    piVar1 = (int *)*_Memory;
    _Memory[3] = 0;
    if ((void *)_Memory[5] != (void *)0x0) {
      _free((void *)_Memory[5]);
      _Memory[5] = 0;
    }
    _Memory[6] = 0;
    if (_Memory[7] != 0) {
      (*(code *)PTR_FUN_006dfaa0)(_Memory[7],0x40);
      _Memory[7] = 0;
    }
    _Memory[8] = 0;
    FUN_0047b1c0();
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_0047b0b0(_Memory);
    _free(_Memory);
    _Memory = piVar1;
  }
  return;
}


// ==== 0x47b890 NisScene_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 NisScene_Load(int *param_1)

{
  if (*param_1 == 0x34035) {
    DAT_00779810 = param_1 + 2;
    *DAT_00779810 = (int)(param_1 + 0x21);
    DAT_0077981c = DAT_00779810[1];
    return 1;
  }
  return 0;
}


// ==== 0x47b8d0 NisScene_Unload

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

bool NisScene_Unload(int *param_1)

{
  if (*param_1 == 0x34035) {
    DAT_00779810 = 0;
    DAT_0077981c = 0;
  }
  return *param_1 == 0x34035;
}


// ==== 0x47b900 FUN_0047b900

void FUN_0047b900(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c81ac;
  in_EAX[4] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[0x38] = 0;
  in_EAX[5] = 0xffffffff;
  in_EAX[0x39] = 0xffffffff;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0xf] = 0;
  in_EAX[0x10] = 0;
  in_EAX[0x11] = 0;
  in_EAX[0x13] = 0;
  in_EAX[0x14] = 0;
  in_EAX[0x15] = 0;
  in_EAX[0x16] = 0;
  in_EAX[8] = 0x3f800000;
  in_EAX[0xd] = 0x3f800000;
  in_EAX[0x12] = 0x3f800000;
  in_EAX[0x17] = 0x3f800000;
  in_EAX[0x18] = 0x3f800000;
  in_EAX[0x19] = 0;
  in_EAX[0x1a] = 0;
  in_EAX[0x1b] = 0;
  in_EAX[0x1c] = 0;
  in_EAX[0x1d] = 0x3f800000;
  in_EAX[0x1e] = 0;
  in_EAX[0x1f] = 0;
  in_EAX[0x20] = 0;
  in_EAX[0x21] = 0;
  in_EAX[0x22] = 0x3f800000;
  in_EAX[0x23] = 0;
  in_EAX[0x24] = 0;
  in_EAX[0x25] = 0;
  in_EAX[0x26] = 0;
  in_EAX[0x27] = 0x3f800000;
  in_EAX[0x28] = 0x3f800000;
  in_EAX[0x29] = 0;
  in_EAX[0x2a] = 0;
  in_EAX[0x2b] = 0;
  in_EAX[0x2c] = 0;
  in_EAX[0x2d] = 0x3f800000;
  in_EAX[0x2e] = 0;
  in_EAX[0x2f] = 0;
  in_EAX[0x30] = 0;
  in_EAX[0x31] = 0;
  in_EAX[0x32] = 0x3f800000;
  in_EAX[0x33] = 0;
  in_EAX[0x34] = 0;
  in_EAX[0x35] = 0;
  in_EAX[0x36] = 0;
  in_EAX[0x37] = 0x3f800000;
  return;
}


// ==== 0x47ba10 FUN_0047ba10

undefined4 * __thiscall FUN_0047ba10(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c81ac;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x47ba30 FUN_0047ba30

uint FUN_0047ba30(uint param_1)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = *(uint *)(unaff_ESI + 0x1c);
  if (uVar1 == param_1) {
    TrackStreamer__AddSpecialSection();
    TrackStreamer__AddSpecialSection();
    uVar1 = 0xffffffff;
    DAT_0077aaf9 = 1;
    DAT_0077aa6c = 0xffffffff;
    DAT_0077aab0 = 0xffffffff;
  }
  else if (param_1 != 0) {
    if (uVar1 != 0) {
      TrackStreamer__RemoveSpecialSection();
      TrackStreamer__RemoveSpecialSection();
      TrackStreamer__ForceSectionToUnload(*(undefined4 *)(unaff_ESI + 0x1c));
    }
    TrackStreamer__AddSpecialSection();
    TrackStreamer__AddSpecialSection();
    DAT_0077aa6c = 0xffffffff;
    DAT_0077aab0 = 0xffffffff;
    DAT_0077aaf9 = 1;
    return 0xffffff01;
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x47bae0 FUN_0047bae0

void FUN_0047bae0(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  if (iVar1 == 0) {
    TrackStreamer__RemoveAllSpecialSections();
    return;
  }
  if (*(int *)(in_EAX + 0x18) != 0) {
    *(undefined4 *)(in_EAX + 0x18) = 0;
  }
  *(int *)(in_EAX + 0x18) = iVar1;
  FUN_0047ba30(iVar1);
  return;
}


// ==== 0x47bb10 FUN_0047bb10

void FUN_0047bb10(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_8;
  
  local_8 = DAT_007797f4;
  *(undefined4 *)(param_1 + 0xe4) = 0xffffffff;
  if ((DAT_00777ccc == 0) || (*(int *)(DAT_00777ccc + 0x58a0) != 0)) {
    cVar4 = FUN_0043a2e0();
    iVar11 = DAT_00735f64;
    if (cVar4 == '\0') {
      if (((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) || (DAT_007361c4 != 2)) {
        if (DAT_00735f64 != 0) {
          if (DAT_007361c4 == 1) {
            iVar6 = *(int *)(*(int *)(DAT_007361b4 + 4) + 0x14);
            iVar7 = *(int *)(DAT_0073619c + 0x24);
            if (iVar7 == 1) {
              iVar8 = 9;
            }
            else {
              iVar8 = 1;
              if (iVar7 == 2) {
                if (*(char *)(iVar6 + 3) == '\x01') {
                  iVar8 = 7;
                }
                else if (*(char *)(iVar6 + 3) == '\x02') {
                  iVar8 = 8;
                }
              }
              else if (iVar7 == 3) {
                cVar4 = *(char *)(iVar6 + 3);
                if (cVar4 == '\x03') {
                  iVar8 = 4;
                }
                else if (cVar4 == '\x01') {
                  iVar8 = 5;
                }
                else if (cVar4 == '\x02') {
                  iVar8 = 6;
                }
              }
              else if (iVar7 == 4) {
                cVar4 = *(char *)(iVar6 + 3);
                if (cVar4 == '\x03') {
                  iVar8 = 0;
                }
                else if (cVar4 == '\x01') {
                  iVar8 = 1;
                }
                else if (cVar4 == '\x02') {
                  iVar8 = 2;
                }
                else if (cVar4 == '\x04') {
                  iVar8 = 3;
                }
              }
            }
            iVar6 = *(int *)(DAT_00735f64 + iVar8 * 4);
            if (0 < iVar6) {
              iVar6 = FUN_004216b0(iVar6);
              local_8 = *(int *)(*(int *)(iVar11 + 0x30 + iVar8 * 4) + iVar6 * 4);
            }
          }
          else if (DAT_007361c4 == 2) {
            iVar6 = *(int *)(*(int *)(DAT_007361b8 + 4) + 0x14);
            iVar7 = *(int *)(DAT_0073619c + 0x24);
            iVar8 = *(int *)(*(int *)(DAT_007361b4 + 4) + 0x14);
            iVar10 = 7;
            iVar9 = 8;
            if (iVar7 != 1) {
              if (iVar7 == 2) {
                if ((*(char *)(iVar8 + 3) != '\x01') && (*(char *)(iVar8 + 3) == '\x02')) {
                  iVar10 = 8;
                }
                if (*(char *)(iVar6 + 3) == '\x01') {
                  iVar9 = 7;
                }
                else if (*(char *)(iVar6 + 3) == '\x02') {
                  iVar9 = 8;
                }
              }
              else if (iVar7 == 3) {
                cVar4 = *(char *)(iVar8 + 3);
                if (cVar4 == '\x03') {
                  iVar10 = 4;
                }
                else if (cVar4 == '\x01') {
                  iVar10 = 5;
                }
                else if (cVar4 == '\x02') {
                  iVar10 = 6;
                }
                cVar4 = *(char *)(iVar6 + 3);
                if (cVar4 == '\x03') {
                  iVar9 = 4;
                }
                else if (cVar4 == '\x01') {
                  iVar9 = 5;
                }
                else if (cVar4 == '\x02') {
                  iVar9 = 6;
                }
              }
              else if (iVar7 == 4) {
                cVar4 = *(char *)(iVar8 + 3);
                if (cVar4 == '\x03') {
                  iVar10 = 0;
                }
                else if (cVar4 == '\x01') {
                  iVar10 = 1;
                }
                else if (cVar4 == '\x02') {
                  iVar10 = 2;
                }
                else if (cVar4 == '\x04') {
                  iVar10 = 3;
                }
                cVar4 = *(char *)(iVar6 + 3);
                if (cVar4 == '\x03') {
                  iVar9 = 0;
                }
                else if (cVar4 == '\x01') {
                  iVar9 = 1;
                }
                else if (cVar4 == '\x02') {
                  iVar9 = 2;
                }
                else if (cVar4 == '\x04') {
                  iVar9 = 3;
                }
              }
            }
            bVar3 = false;
            PostRaceScene_ShuffleList(DAT_00735f64,iVar10);
            PostRaceScene_ShuffleList(iVar11,iVar9);
            piVar1 = (int *)(iVar11 + iVar10 * 4);
            iVar6 = 0;
            do {
              if (*piVar1 <= iVar6) break;
              iVar7 = 0;
              if (!bVar3) {
                piVar2 = (int *)(iVar11 + iVar9 * 4);
                do {
                  if (*piVar2 <= iVar7) break;
                  iVar8 = *(int *)(*(int *)(iVar11 + 0x30 + iVar10 * 4) + iVar6 * 4);
                  if (iVar8 == *(int *)(*(int *)(iVar11 + 0x30 + iVar9 * 4) + iVar7 * 4)) {
                    bVar3 = true;
                    local_8 = iVar8;
                  }
                  iVar7 = iVar7 + 1;
                  iVar11 = DAT_00735f64;
                } while (!bVar3);
              }
              iVar6 = iVar6 + 1;
            } while (!bVar3);
          }
        }
      }
      else {
        switch(param_2) {
        case 0x515:
        case 0x516:
        case 0x51b:
          local_8 = DAT_007797f0;
          break;
        case 0x517:
        case 0x518:
        case 0x519:
        case 0x51a:
        case 0x51c:
          local_8 = DAT_007797d4;
        }
      }
    }
    else if (((*(int *)(DAT_007361b4 + 4) != 0) &&
             (iVar11 = *(int *)(*(int *)(DAT_007361b4 + 4) + 0x14), iVar11 != 0)) &&
            ((cVar4 = *(char *)(iVar11 + 3), '\0' < cVar4 && (cVar4 < '\x05')))) {
      cVar5 = IsDriftMode();
      iVar11 = *(int *)(param_1 + 0x14);
      if (cVar5 == '\0') {
        if ((-1 < iVar11) && (iVar11 < 2)) {
          local_8 = *(int *)(&DAT_007799ac + ((int)cVar4 + iVar11 * 4) * 4);
        }
      }
      else if ((-1 < iVar11) && (iVar11 < 2)) {
        local_8 = *(int *)(&DAT_0077997c + ((int)cVar4 + iVar11 * 4) * 4);
      }
    }
  }
  else {
    local_8 = DAT_00779958;
  }
  FUN_0047ba30(local_8);
  return;
}


// ==== 0x47bed0 FUN_0047bed0

void FUN_0047bed0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = DAT_00779950;
  *(undefined4 *)(in_EAX + 0xe4) = 0xffffffff;
  iVar1 = DAT_00735f64;
  iVar2 = *(int *)(*(int *)(DAT_007361b4 + 4) + 0x1c);
  if (DAT_007361c4 == 2) {
    FUN_0047ba30(DAT_0077995c);
    return;
  }
  if (*(int *)(DAT_0073619c + 0x24) == 1) {
    if (DAT_00777cd0 == 1) {
      FUN_0047ba30(DAT_007797c8);
      return;
    }
    FUN_0047ba30(DAT_00779954);
    return;
  }
  if (param_1 != 0x450) {
    if (DAT_00735f64 != 0) {
      iVar4 = 0xb;
      if (*(char *)(iVar2 + 0xc) == '\x01') {
        iVar4 = 10;
      }
      iVar2 = *(int *)(DAT_00735f64 + iVar4 * 4);
      if (0 < iVar2) {
        iVar2 = FUN_004216b0(iVar2);
        uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x30 + iVar4 * 4) + iVar2 * 4);
      }
    }
    FUN_0047ba30(uVar3);
    return;
  }
  if (*(char *)(iVar2 + 0xc) == '\x01') {
    FUN_0047ba30(DAT_007797cc);
    return;
  }
  FUN_0047ba30(DAT_007797d0);
  return;
}


// ==== 0x47bfc0 FUN_0047bfc0

void FUN_0047bfc0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    TrackStreamer__RemoveSpecialSection();
    TrackStreamer__RemoveSpecialSection();
    DAT_0077aa6c = 0xffffffff;
    DAT_0077aab0 = 0xffffffff;
    DAT_0077aaf9 = 1;
    FUN_0047b810();
    FUN_0047c4d0(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
  }
  return;
}


// ==== 0x47c010 FUN_0047c010

undefined4 FUN_0047c010(void)

{
  return 2;
}


// ==== 0x47c020 FUN_0047c020

undefined4 FUN_0047c020(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_14;
  
  FUN_0047b810();
  iVar6 = *(int *)(param_1 + 0x10);
  if ((iVar6 != 0) && ((*(int *)(iVar6 + 0x60) != 0 || (*(int *)(iVar6 + 0x6c) != 0)))) {
    local_14 = 0;
    if (0 < *(int *)(iVar6 + 8)) {
      iVar7 = 0x20;
      do {
        uVar1 = *(undefined4 *)(iVar6 + -0x14 + iVar7);
        pvVar4 = _malloc(0x7c);
        if (pvVar4 == (void *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = (undefined4 *)CAnimCtrl__InitFields();
        }
        uVar2 = DAT_007797c4;
        puVar5[2] = uVar1;
        puVar5[0x17] = 0x3f800000;
        iVar6 = FUN_005a4d80(uVar2);
        if (iVar6 != 0) {
          FUN_0047b600(0,0);
          puVar5[0xd] = puVar5[0xd] | 0x24;
        }
        FUN_0047b220();
        FUN_0047b220();
        FUN_0047b220();
        if ((puVar5[0x1e] != 0) && (iVar6 != 0)) {
          *DAT_007797fc = puVar5;
          puVar3 = puVar5;
          puVar5[1] = DAT_007797fc;
          DAT_007797fc = puVar3;
          *puVar5 = &DAT_007797f8;
        }
        iVar6 = *(int *)(param_1 + 0x10);
        local_14 = local_14 + 1;
        iVar7 = iVar7 + 4;
      } while (local_14 < *(int *)(iVar6 + 8));
    }
    return 1;
  }
  return 0;
}


// ==== 0x47c160 FUN_0047c160

void FUN_0047c160(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = 0;
  piVar2 = &DAT_00779904;
  do {
    iVar8 = DAT_0073619c;
    if (iVar3 < *(int *)(DAT_0073619c + 0x24)) {
      *piVar2 = iVar3;
    }
    else {
      *piVar2 = -1;
    }
    piVar2 = piVar2 + 6;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x779964);
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x60) == 1) {
    iVar3 = *(int *)(iVar8 + 0x24);
    iVar7 = 0;
    if (0 < iVar3) {
      piVar2 = (int *)(DAT_007361f8 + 0x28);
      do {
        iVar4 = 0;
        if (0 < iVar3) {
          piVar6 = (int *)(iVar8 + 0x520);
          do {
            if (*(int *)(*piVar2 + 0x1c) == *piVar6) {
              iVar4 = iVar4 + 1;
              if ((iVar4 < 1) || (4 < iVar4)) goto LAB_0047c1ee;
              goto LAB_0047c1e4;
            }
            iVar4 = iVar4 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar4 < iVar3);
        }
        iVar4 = 1;
LAB_0047c1e4:
        *(int *)(&DAT_007798ec + iVar4 * 0x18) = iVar7;
LAB_0047c1ee:
        iVar3 = *(int *)(iVar8 + 0x24);
        iVar7 = iVar7 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar7 < iVar3);
    }
    if (DAT_007361c4 == 1) {
      iVar3 = *(int *)(DAT_007361b4 + 4);
      iVar7 = *(int *)(iVar8 + 0x24);
      iVar4 = 0;
      if (0 < iVar7) {
        piVar2 = (int *)(iVar8 + 0x520);
        while (*(int *)(iVar3 + 0x1c) != *piVar2) {
          iVar4 = iVar4 + 1;
          piVar2 = piVar2 + 1;
          if (iVar7 <= iVar4) {
            return;
          }
        }
        if (iVar4 + 1 != 1) {
          iVar8 = 0;
          piVar2 = (int *)(DAT_007361f8 + 0x28);
          do {
            iVar5 = iVar8;
            if (*piVar2 != iVar3) {
              iVar5 = 0;
              if (0 < iVar7) {
                piVar6 = (int *)(DAT_0073619c + 0x520);
                do {
                  if (*(int *)(*piVar2 + 0x1c) == *piVar6) {
                    iVar5 = iVar5 + 1;
                    goto LAB_0047c297;
                  }
                  iVar5 = iVar5 + 1;
                  piVar6 = piVar6 + 1;
                } while (iVar5 < iVar7);
              }
              iVar5 = 1;
LAB_0047c297:
              if (iVar5 < iVar4 + 1) {
                (&DAT_00779904)[iVar5 * 6] = iVar8;
                iVar5 = DAT_00779904;
              }
              else {
                *(int *)(&DAT_007798ec + iVar5 * 0x18) = iVar8;
                iVar5 = DAT_00779904;
              }
            }
            DAT_00779904 = iVar5;
            iVar7 = *(int *)(DAT_0073619c + 0x24);
            iVar8 = iVar8 + 1;
            piVar2 = piVar2 + 1;
            if (iVar7 <= iVar8) {
              return;
            }
          } while( true );
        }
      }
    }
  }
  else {
    iVar3 = 0;
    if (0 < *(int *)(iVar8 + 0x24)) {
      piVar2 = (int *)(DAT_007361f8 + 0x28);
      do {
        cVar1 = *(char *)(*(int *)(*piVar2 + 0x14) + 3);
        if (('\0' < cVar1) && (cVar1 < '\x05')) {
          *(int *)(&DAT_007798ec + cVar1 * 0x18) = iVar3;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar3 < *(int *)(iVar8 + 0x24));
    }
  }
  return;
}


// ==== 0x47c310 FUN_0047c310

undefined4 FUN_0047c310(int param_1)

{
  int iVar1;
  void *pvVar2;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((*(int *)(*(int *)(param_1 + 0x10) + 0x5c) == 0) ||
     (iVar1 = FUN_005a4d80(DAT_007797c4), iVar1 == 0)) {
    return 0;
  }
  local_14 = 0;
  if (0 < *(int *)(DAT_0073619c + 0x24)) {
    local_10 = 0;
    local_1c = &DAT_007798f4;
    do {
      if (0x779953 < (int)local_1c) break;
      iVar1 = (&DAT_007799d0)[local_14];
      if ((((iVar1 != 0) && ((&DAT_00779960)[local_14] != 0)) && ((&DAT_007799a0)[local_14] != 0))
         && ((&DAT_00779970)[local_14] != 0)) {
        local_18 = 0;
        do {
          pvVar2 = _malloc(0x7c);
          if (pvVar2 == (void *)0x0) {
            pvVar2 = (void *)0x0;
          }
          else {
            pvVar2 = (void *)CAnimCtrl__InitFields();
          }
          *(uint *)((int)pvVar2 + 0x34) = *(uint *)((int)pvVar2 + 0x34) | 0x20;
          *(int *)((int)pvVar2 + 8) = iVar1;
          *(undefined4 *)((int)pvVar2 + 0x5c) = 0x3f000000;
          FUN_0047b600(0,0);
          FUN_0047b220();
          FUN_0047b220();
          if (*(int *)((int)pvVar2 + 0x78) == 0) {
            FUN_0047b170();
            FUN_0047b1c0();
            FUN_0047b0b0(pvVar2);
            _free(pvVar2);
          }
          else {
            (&DAT_007798f0)[local_10 + local_18] = pvVar2;
          }
          local_18 = local_18 + 1;
        } while (local_18 < 2);
        if (*local_1c != 0) {
          CAnimCtrl__AdvanceAnimTime(0x3f800000);
        }
      }
      local_14 = local_14 + 1;
      local_10 = local_10 + 6;
      local_1c = local_1c + 6;
    } while (local_14 < *(int *)(DAT_0073619c + 0x24));
  }
  *(undefined4 *)(param_1 + 0xe0) = 1;
  return 1;
}


// ==== 0x47c4d0 FUN_0047c4d0

void FUN_0047c4d0(void)

{
  int iVar1;
  void *_Memory;
  undefined4 *puVar2;
  int *piVar3;
  int local_4;
  
  puVar2 = &DAT_007798f8;
  do {
    piVar3 = puVar2 + -2;
    local_4 = 2;
    do {
      iVar1 = *piVar3;
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
        _Memory = (void *)*piVar3;
        if (_Memory != (void *)0x0) {
          FUN_0047b0b0(_Memory);
          _free(_Memory);
        }
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0xffffffff;
    puVar2 = puVar2 + 6;
  } while ((int)puVar2 < 0x779958);
  return;
}


// ==== 0x47c580 FUN_0047c580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047c580(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  float fVar7;
  ushort uVar8;
  int iVar9;
  float *pfVar10;
  undefined4 *puVar11;
  char *pcVar12;
  float *pfStack_118;
  undefined1 *puVar13;
  float *pfVar14;
  uint uVar15;
  float fStack_f4;
  int *local_d4;
  int iStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  int iStack_ac;
  float afStack_94 [4];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 auStack_78 [3];
  undefined1 auStack_6c [4];
  float fStack_68;
  float afStack_4c [18];
  
  if (*(int *)(param_1 + 0xe0) != 0) {
    local_d4 = &DAT_007798f0;
    do {
      iVar6 = *local_d4;
      iVar9 = local_d4[1];
      if (((iVar6 != 0) && (iVar9 != 0)) && (-1 < local_d4[5])) {
        fVar7 = _K_ONE / DAT_006ffdbc;
        fVar1 = *(float *)(iVar9 + 0x60);
        fVar2 = *(float *)(iVar9 + 0x5c);
        fVar3 = *(float *)(iVar9 + 100);
        fVar4 = *(float *)(iVar9 + 0x5c);
        if (fVar7 * *(float *)(iVar6 + 100) * *(float *)(iVar6 + 0x5c) + param_2 <=
            fVar7 * *(float *)(iVar6 + 0x60) * *(float *)(iVar6 + 0x5c)) {
          fStack_f4 = param_2;
          CAnimCtrl__AdvanceAnimTime();
          fStack_f4 = 6.591446e-39;
          FUN_0047b3d0();
        }
        else {
          *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar6 + 0x60);
          fStack_f4 = 6.591407e-39;
          FUN_0047b3d0();
        }
        if (fVar7 * fVar3 * fVar4 + param_2 <= fVar7 * fVar1 * fVar2) {
          fStack_f4 = param_2;
          CAnimCtrl__AdvanceAnimTime();
        }
        else {
          *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(iVar9 + 0x60);
        }
        fStack_f4 = 6.591508e-39;
        FUN_0047b3d0();
        fStack_f4 = 6.591529e-39;
        bMatrixCopy_b();
        fStack_f4 = (float)(param_1 + 0x60);
        D3DXMatrixMultiply(&local_b0,&local_b0);
        D3DXMatrixMultiply();
        iVar6 = *(int *)(DAT_007361f8 + 0x28 + local_d4[5] * 4);
        Car_SetMode();
        iVar9 = 0;
        puVar11 = (undefined4 *)(iVar6 + 0x300);
        do {
          auStack_78[iVar9] = *puVar11;
          iVar9 = iVar9 + 1;
          puVar11 = puVar11 + 1;
        } while (iVar9 < 4);
        fStack_f4 = (float)Atan2ToAngle16(uStack_c8,uStack_c4);
        FUN_00427c50(&stack0xffffff18,0,fStack_f4);
        TrackPath__UpdateCursor(&DAT_007372b0,iVar6 + 0x60);
        (**(code **)(**(int **)(iVar6 + 0x2c) + 0x2c))(1);
        (**(code **)(**(int **)(iVar6 + 0x2c) + 0x30))();
        *(undefined4 *)(iVar6 + 0x884) = 0;
        bMatrixCopy_b();
        uVar15 = param_1 + 0x60;
        puVar13 = auStack_6c;
        D3DXMatrixMultiply();
        D3DXMatrixMultiply(auStack_78,auStack_78,param_1 + 0xa0);
        uVar8 = Atan2ToAngle16(uStack_84,uStack_80);
        for (fVar1 = ((float)uVar8 * 0.005493164 - (float)(uVar15 & 0xffff) * 0.005493164) * 1.0;
            360.0 < fVar1; fVar1 = fVar1 - 360.0) {
        }
        for (; fVar1 < 0.0; fVar1 = fVar1 + 360.0) {
        }
        iVar9 = _ftol_nocw();
        fVar1 = 0.0;
        *(short *)(iVar6 + 0x3b6) =
             (short)((ulonglong)((longlong)iVar9 * 0xb60b60b7) >> 0x28) -
             ((short)(char)((char)(iVar9 / 0x1680000) + (char)(iVar9 >> 0x1f)) >> 0xf);
        if (((iStack_ac != 0) && (puVar13 == (undefined1 *)0x0)) && (fVar1 = 0.0, 0.0 < param_2)) {
          fVar1 = local_b0 - (float)(param_1 + 0xa0);
          fVar1 = SQRT((fStack_b4 - (float)&fStack_bc) * (fStack_b4 - (float)&fStack_bc) +
                       fVar1 * fVar1);
        }
        pfVar14 = afStack_94;
        pfStack_118 = afStack_4c;
        pcVar12 = (char *)(iVar6 + 0x350);
        puVar11 = (undefined4 *)(iVar6 + 0x374);
        pfVar10 = (float *)(iVar6 + 0x300);
        iVar9 = 4;
        do {
          fVar2 = *pfStack_118;
          pfVar10[-4] = 0.0;
          pfVar10[0x10] = 0.0;
          *pfVar10 = (fVar1 / (fVar2 * 6.28318)) * 6.28318 + *pfVar14;
          cVar5 = *pcVar12;
          *pcVar12 = '\x01';
          if (cVar5 == '\0') {
            *(int *)(iVar6 + 0x3cc) = *(int *)(iVar6 + 0x3cc) + 1;
          }
          pfVar10[0x15] = 1.4013e-45;
          if ((int)pfVar10[0x19] < 1) {
            pfVar10[0x19] = 1.4013e-45;
          }
          *puVar11 = 0;
          puVar11[1] = 0;
          pfVar10[0x25] = 0.0;
          pfVar10[4] = 0.0;
          *(undefined4 *)(iVar6 + 0x330) = 0;
          *(undefined4 *)(iVar6 + 0x334) = 0;
          *(undefined4 *)(iVar6 + 0x338) = 0;
          *(undefined4 *)(iVar6 + 0x33c) = 0;
          pfVar14 = pfVar14 + 1;
          pfStack_118 = pfStack_118 + 0xc;
          pfVar10 = pfVar10 + 1;
          pcVar12 = pcVar12 + 1;
          puVar11 = puVar11 + 2;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        iVar9 = 0;
        do {
          FUN_00465150((undefined4 *)(iVar6 + 0x40));
          iVar9 = iVar9 + 1;
        } while (iVar9 < 4);
        D3DXVec3Transform(&fStack_f4,*(undefined4 *)(iVar6 + 0x40),iVar6 + 0x90);
        fStack_68 = *(float *)(iVar6 + 0x68) - fStack_b8;
        *(float *)(iVar6 + 0x50) = *(float *)(iVar6 + 0x60) - fStack_c0;
        *(float *)(iVar6 + 0x58) = fStack_68;
        *(float *)(iVar6 + 0x54) = *(float *)(iVar6 + 100) - fStack_bc;
        local_d4[2] = iStack_d0;
        local_d4[3] = iStack_cc;
        local_d4[4] = 1;
      }
      local_d4 = local_d4 + 6;
    } while ((int)local_d4 < 0x779950);
  }
  return;
}


// ==== 0x47c9e0 FUN_0047c9e0

void FUN_0047c9e0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0xe0) != 0) {
    piVar3 = &DAT_00779904;
    do {
      if (-1 < *piVar3) {
        iVar1 = *(int *)(DAT_007361f8 + 0x28 + *piVar3 * 4);
        iVar2 = *(int *)(iVar1 + 0x28);
        if (iVar2 == 1) {
          FUN_004782c0();
        }
        else if (iVar2 == 3) {
          FUN_00474640();
        }
        (**(code **)(**(int **)(iVar1 + 0x30) + 0x1c))();
        Car_SetMode();
      }
      piVar3 = piVar3 + 6;
    } while ((int)piVar3 < 0x779964);
    FUN_00435d30(DAT_0073619c);
    *(undefined4 *)(param_1 + 0xe0) = 0;
  }
  return;
}


// ==== 0x47cac0 NisSceneManager::FindNisSceneOriginPosition

/* [canon] camera med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 NisSceneManager__FindNisSceneOriginPosition(undefined4 param_1,short *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  undefined4 *unaff_EDI;
  
  if (DAT_0078a2fc == 0) {
    pcVar4 = "ForwardStartLine";
    if ((in_EAX == 0) && (DAT_0078a318 != 0)) {
      pcVar4 = "ForwardFinishLine";
    }
  }
  else {
    pcVar4 = "BackwardStartLine";
    if ((in_EAX == 0) && (DAT_0078a318 != 0)) {
      pcVar4 = "BackwardFinishLine";
    }
  }
  iVar3 = -1;
  bVar2 = *pcVar4;
  while (bVar2 != 0) {
    iVar3 = iVar3 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  iVar3 = TrackMarker_Get(iVar3,0);
  if (iVar3 == 0) {
    return 0;
  }
  *unaff_EDI = *(undefined4 *)(iVar3 + 0x10);
  unaff_EDI[1] = *(undefined4 *)(iVar3 + 0x14);
  *param_2 = *(short *)(iVar3 + 0x20) + 0x4000;
  return 1;
}


// ==== 0x47cb50 FUN_0047cb50

void FUN_0047cb50(int param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_37c;
  undefined4 uStack_378;
  undefined4 uStack_374;
  undefined4 local_370;
  undefined4 local_36c;
  float local_368;
  undefined4 *local_358;
  int local_354;
  undefined1 auStack_350 [96];
  undefined4 uStack_2f0;
  undefined4 uStack_2ec;
  undefined1 local_2e0 [708];
  void *local_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_0068600b;
  local_1c = ExceptionList;
  local_358 = (undefined4 *)(param_1 + 0x20);
  ExceptionList = &local_1c;
  *local_358 = 0x3f800000;
  *(undefined4 *)(param_1 + 0x34) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x48) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x88) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x9c) = 0x3f800000;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  local_354 = param_1 + 0x60;
  *(undefined4 *)(param_1 + 0xa0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb4) = 0x3f800000;
  *(undefined4 *)(param_1 + 200) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xdc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  local_370 = 0;
  local_36c = 0;
  local_368 = 0.0;
  local_37c = 0;
  iVar1 = NisSceneManager__FindNisSceneOriginPosition(param_1,&local_37c);
  if (iVar1 != 0) {
    FUN_004406d0();
    uStack_14 = 0;
    fVar2 = (float10)GroundQuery__FindSurfaceBelow(local_2e0,&local_370,0,0,0);
    local_368 = (float)fVar2;
    TrackPathCoordinate__TrackPathCoordinate(&local_370);
    uStack_378 = uStack_2f0;
    uStack_374 = uStack_2ec;
    Atan2ToAngle16(uStack_2f0,uStack_2ec);
    eCreateTranslationMatrix();
    eIdentity();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0x60) == 0) {
      bDegreesToAngle16(0x42b40000);
    }
    else {
      bDegreesToAngle16(0x42b40000);
    }
    FUN_0040baf0(auStack_350,auStack_350);
    bMatrixCopy_b();
    D3DXMatrixMultiply(local_358,auStack_350,(undefined4 *)(param_1 + 0xa0));
    RefArray_DecrementAll();
  }
  ExceptionList = local_1c;
  return;
}


// ==== 0x47cd70 FUN_0047cd70

void FUN_0047cd70(void)

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
    FUN_0047b0b0(_Memory);
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x47cda0 FUN_0047cda0

undefined4 FUN_0047cda0(int param_1,int *param_2,int *param_3)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *local_8;
  
  piVar4 = DAT_00779798;
  local_8 = DAT_00779798;
  piVar5 = (int *)NullUpdate_ret();
  if (piVar4 == piVar5) {
    return 0;
  }
  do {
    iVar3 = local_8[5];
    if (iVar3 != 0) {
      iVar7 = 0;
      if (0 < *(int *)(iVar3 + 4)) {
        puVar9 = *(undefined4 **)(iVar3 + 0x10);
        do {
          pbVar6 = (byte *)*puVar9;
          iVar8 = -1;
          bVar2 = *pbVar6;
          while (bVar2 != 0) {
            iVar8 = iVar8 * 0x21 + (uint)bVar2;
            pbVar1 = pbVar6 + 1;
            pbVar6 = pbVar6 + 1;
            bVar2 = *pbVar1;
          }
          if (param_1 == iVar8) {
            *param_2 = iVar3;
            *param_3 = iVar7;
            return 1;
          }
          iVar7 = iVar7 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar7 < *(int *)(iVar3 + 4));
      }
    }
    local_8 = (int *)*local_8;
    if (local_8 == piVar5) {
      return 0;
    }
  } while( true );
}


// ==== 0x47ce50 AnimBank_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 AnimBank_Load(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (*param_1 == 0xe34010) {
    puVar2 = _malloc(0x38);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[2] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[3] = 0;
      puVar2[6] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      *(undefined1 *)(puVar2 + 0xc) = 0;
      puVar2[0xd] = param_1;
    }
    AnimBank_DynamicLoad((int)param_1 + 0x17U & 0xfffffff0);
    *DAT_0077979c = puVar2;
    puVar1 = puVar2;
    puVar2[1] = DAT_0077979c;
    DAT_0077979c = puVar1;
    *puVar2 = &DAT_00779798;
    return 1;
  }
  return 0;
}


// ==== 0x47ced0 AnimBank_Unload

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 AnimBank_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  _Memory = DAT_00779798;
  if (*param_1 != 0xe34010) {
    return 0;
  }
  piVar2 = (int *)NullUpdate_ret();
  if (_Memory != piVar2) {
    while ((int *)_Memory[0xd] != param_1) {
      _Memory = (int *)*_Memory;
      if (_Memory == piVar2) {
        return 1;
      }
    }
    FUN_0047afc0();
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
  }
  return 1;
}


// ==== 0x47cf30 FUN_0047cf30

int __fastcall FUN_0047cf30(int param_1)

{
  undefined4 uVar1;
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
  
  uVar1 = DAT_006f0888;
  *(undefined1 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x278) = 0x80000000;
  *(undefined4 *)(param_1 + 0x27c) = uVar1;
  *(undefined4 *)(param_1 + 0x280) = 0;
  *(undefined4 *)(param_1 + 0x284) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0x41200000;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined2 *)(param_1 + 0xc4) = 0x36fb;
  *(undefined4 *)(param_1 + 0xbc) = 0x3f000000;
  *(undefined4 *)(param_1 + 0xc0) = 0x461c4000;
  *(undefined4 *)(param_1 + 0x274) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x70) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x78) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x7c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x94) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x98) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x9c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  local_50 = 0x3f800000;
  local_40 = 0;
  local_30 = 0;
  local_20 = 0;
  local_4c = 0;
  local_3c = 0xbf800000;
  local_2c = 0;
  local_1c = 0;
  local_48 = 0;
  local_38 = 0;
  local_28 = 0xbf800000;
  local_18 = 0x44960000;
  local_44 = 0;
  local_34 = 0;
  local_24 = 0x42c80000;
  local_14 = 0x3f800000;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  Camera__SetCameraMatrix(param_1,&local_50,0x3f800000);
  Camera__SetCameraMatrix(param_1,&local_50,0x3f800000);
  return param_1;
}


// ==== 0x47d070 Camera::SetCameraMatrix

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (C+M) docs/re/blur.md */

void Camera__SetCameraMatrix(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  float *pfVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float10 extraout_ST0;
  undefined4 local_90 [12];
  float local_60;
  float local_5c;
  float local_58 [2];
  undefined1 local_50 [4];
  undefined4 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  
  if (DAT_00735f5c == 0) {
    puVar5 = param_1;
    puVar6 = param_1 + 0x34;
    for (iVar4 = 0x34; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    param_1[0x9d] = param_3;
    if ((DAT_00779730 == 0) || (DAT_00734958 != 0)) {
      if (DAT_0078eb40 != 0) {
        DAT_0078eb40 = 0;
      }
    }
    else {
      if (DAT_0078eb40 == 0) {
        DAT_0078eb40 = 1;
      }
      puVar5 = &DAT_00779734;
      puVar6 = local_90;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      local_60 = local_60 * 0.01;
      local_5c = local_5c * 0.01;
      local_58[0] = local_58[0] * 0.01;
      local_58[1] = 1.0;
    }
    bMatrixCopy_b();
    D3DXMatrixTranspose(local_50,param_1);
    pfVar1 = (float *)(param_1 + 0x10);
    uStack_4c = 0;
    uStack_3c = 0;
    uStack_2c = 0;
    D3DXVec3Transform(pfVar1,param_1 + 0xc,local_58);
    *pfVar1 = -*pfVar1;
    param_1[0x11] = -(float)param_1[0x11];
    param_1[0x12] = -(float)param_1[0x12];
    bNormalize3();
    fVar2 = (float)param_1[0x2c];
    param_1[0x18] = fVar2 * (float)param_1[0x14];
    param_1[0x19] = (float)param_1[0x15] * fVar2;
    param_1[0x1a] = (float)param_1[0x16] * fVar2;
    param_1[0x18] = *pfVar1 + (float)param_1[0x18];
    param_1[0x19] = (float)param_1[0x11] + (float)param_1[0x19];
    param_1[0x1a] = (float)param_1[0x12] + (float)param_1[0x1a];
    if (*(char *)(param_1 + 0x9c) != '\0') {
      *(undefined1 *)(param_1 + 0x9c) = 0;
      puVar5 = param_1;
      puVar6 = param_1 + 0x34;
      for (iVar4 = 0x34; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      param_1[0x9d] = 0x3f800000;
    }
    if (0.0 < (float)param_1[0x9d]) {
      fVar2 = _K_ONE / (float)param_1[0x9d];
      param_1[0x7b] = 0;
      param_1[0x78] = (float)param_1[0x10] - (float)param_1[0x44];
      param_1[0x7a] = (float)param_1[0x12] - (float)param_1[0x46];
      param_1[0x79] = (float)param_1[0x11] - (float)param_1[0x45];
      param_1[0x78] = fVar2 * (float)param_1[0x78];
      param_1[0x79] = fVar2 * (float)param_1[0x79];
      param_1[0x7a] = fVar2 * (float)param_1[0x7a];
      param_1[0x7f] = 0;
      param_1[0x7c] = (float)param_1[0x14] - (float)param_1[0x48];
      param_1[0x7e] = (float)param_1[0x16] - (float)param_1[0x4a];
      param_1[0x7d] = (float)param_1[0x15] - (float)param_1[0x49];
      param_1[0x7c] = fVar2 * (float)param_1[0x7c];
      param_1[0x7d] = fVar2 * (float)param_1[0x7d];
      param_1[0x7e] = fVar2 * (float)param_1[0x7e];
      param_1[0x80] = (float)param_1[0x18] - (float)param_1[0x4c];
      param_1[0x82] = (float)param_1[0x1a] - (float)param_1[0x4e];
      param_1[0x83] = 0;
      param_1[0x81] = (float)param_1[0x19] - (float)param_1[0x4d];
      param_1[0x80] = fVar2 * (float)param_1[0x80];
      param_1[0x81] = fVar2 * (float)param_1[0x81];
      param_1[0x82] = fVar2 * (float)param_1[0x82];
      param_1[0x94] = ((float)param_1[0x2c] - (float)param_1[0x60]) * fVar2;
      param_1[0x95] = ((float)param_1[0x2d] - (float)param_1[0x61]) * fVar2;
      param_1[0x96] = ((float)param_1[0x2e] - (float)param_1[0x62]) * fVar2;
      param_1[0x97] = ((float)param_1[0x2f] - (float)param_1[99]) * fVar2;
      param_1[0x98] = ((float)param_1[0x30] - (float)param_1[100]) * fVar2;
      uVar3 = _ftol_nocw();
      *(undefined2 *)(param_1 + 0x99) = uVar3;
      param_1[0x86] = (float)param_1[0x1e] - (float)param_1[0x52];
      param_1[0x84] = (float)param_1[0x1c] - (float)param_1[0x50];
      param_1[0x87] = (float)param_1[0x1f] - (float)param_1[0x53];
      param_1[0x85] = (float)param_1[0x1d] - (float)param_1[0x51];
      param_1[0x84] = (float)(extraout_ST0 * (float10)(float)param_1[0x84]);
      param_1[0x85] = (float)(extraout_ST0 * (float10)(float)param_1[0x85]);
      param_1[0x86] = (float)(extraout_ST0 * (float10)(float)param_1[0x86]);
      param_1[0x87] = (float)(extraout_ST0 * (float10)(float)param_1[0x87]);
      param_1[0x8e] = (float)param_1[0x26] - (float)param_1[0x5a];
      param_1[0x8c] = (float)param_1[0x24] - (float)param_1[0x58];
      param_1[0x8f] = (float)param_1[0x27] - (float)param_1[0x5b];
      param_1[0x8d] = (float)param_1[0x25] - (float)param_1[0x59];
      param_1[0x8c] = (float)(extraout_ST0 * (float10)(float)param_1[0x8c]);
      param_1[0x8d] = (float)(extraout_ST0 * (float10)(float)param_1[0x8d]);
      param_1[0x8e] = (float)(extraout_ST0 * (float10)(float)param_1[0x8e]);
      param_1[0x8f] = (float)(extraout_ST0 * (float10)(float)param_1[0x8f]);
      param_1[0x8a] = (float)param_1[0x22] - (float)param_1[0x56];
      param_1[0x88] = (float)param_1[0x20] - (float)param_1[0x54];
      param_1[0x8b] = (float)param_1[0x23] - (float)param_1[0x57];
      param_1[0x89] = (float)param_1[0x21] - (float)param_1[0x55];
      param_1[0x88] = (float)(extraout_ST0 * (float10)(float)param_1[0x88]);
      param_1[0x89] = (float)(extraout_ST0 * (float10)(float)param_1[0x89]);
      param_1[0x8a] = (float)(extraout_ST0 * (float10)(float)param_1[0x8a]);
      param_1[0x8b] = (float)(extraout_ST0 * (float10)(float)param_1[0x8b]);
      param_1[0x92] = (float)param_1[0x2a] - (float)param_1[0x5e];
      param_1[0x90] = (float)param_1[0x28] - (float)param_1[0x5c];
      param_1[0x93] = (float)param_1[0x2b] - (float)param_1[0x5f];
      param_1[0x91] = (float)param_1[0x29] - (float)param_1[0x5d];
      param_1[0x90] = (float)(extraout_ST0 * (float10)(float)param_1[0x90]);
      param_1[0x91] = (float)(extraout_ST0 * (float10)(float)param_1[0x91]);
      param_1[0x92] = (float)(extraout_ST0 * (float10)(float)param_1[0x92]);
      param_1[0x93] = (float)(extraout_ST0 * (float10)(float)param_1[0x93]);
    }
  }
  return;
}


// ==== 0x47d630 FUN_0047d630

void FUN_0047d630(void)

{
  char cVar1;
  char *pcVar2;
  char *unaff_ESI;
  char local_68;
  char local_67 [99];
  
  if (DAT_00734958 == 0) {
    bMatrixCopy_b(&DAT_00779730,0);
    if (*unaff_ESI != '\0') {
      pcVar2 = &local_68;
      do {
        cVar1 = pcVar2[(int)(unaff_ESI + (1 - (int)&local_68))];
        pcVar2 = pcVar2 + 1;
        *pcVar2 = cVar1;
      } while (cVar1 != '\0');
    }
  }
  return;
}


// ==== 0x47d680 FindCameraRow

/* [canon] camera V (G+H+C) docs/re/camera.md */

int * FindCameraRow(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  
  if (DAT_007364a0 == 3) {
    iVar3 = in_EAX[1];
    piVar4 = in_EAX + 0x18;
  }
  else {
    iVar3 = *in_EAX;
    piVar4 = in_EAX + 4;
  }
  iVar1 = 0;
  piVar2 = piVar4;
  if (0 < iVar3) {
    do {
      if (unaff_EDI == (short)*piVar2) {
        return piVar4 + iVar1 * 4;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar1 < iVar3);
  }
  return (int *)0x0;
}


// ==== 0x47d6c0 FUN_0047d6c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0047d6c0(undefined4 param_1,float param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_004387e0(param_2,param_1);
  uVar1 = _ftol_nocw();
  uVar3 = uVar1 << 0xd ^ uVar1;
  uVar2 = uVar1 + 1 ^ (uVar1 + 1) * 0x2000;
  return ((float10)_K_ONE -
         (float10)((uVar2 * uVar2 * 0x3d73 + 0xc0ae5) * uVar2 + 0xd208dd0d & 0x7fffffff) *
         (float10)9.313226e-10) * ((float10)param_2 - (float10)(int)uVar1) +
         ((float10)_K_ONE - ((float10)param_2 - (float10)(int)uVar1)) *
         ((float10)_K_ONE -
         (float10)((uVar3 * uVar3 * 0x3d73 + 0xc0ae5) * uVar3 + 0xd208dd0d & 0x7fffffff) *
         (float10)9.313226e-10);
}


// ==== 0x47d780 FUN_0047d780

float10 FUN_0047d780(float param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0.0;
  local_c = 1.0;
  local_8 = 1.0;
  iVar1 = 6;
  do {
    fVar2 = (float10)FUN_0047d6c0(local_c * param_1);
    iVar1 = iVar1 + -1;
    local_4 = (float)(fVar2 * (float10)local_8 + (float10)local_4);
    local_c = local_c + local_c;
    local_8 = local_8 * 0.5;
  } while (iVar1 != 0);
  return (float10)local_4;
}


// ==== 0x47d7f0 FUN_0047d7f0

void __fastcall FUN_0047d7f0(undefined4 param_1)

{
  float10 fVar1;
  float10 fVar2;
  float fVar3;
  
  fVar1 = (float10)FUN_00564b10(param_1);
  fVar3 = (float)fVar1;
  fVar1 = (float10)FUN_00564b10(fVar3);
  fVar2 = (float10)FUN_00564b10();
  FUN_00564cd0((float)((float10)(float)(fVar1 * (float10)fVar3) / fVar2));
  return;
}


// ==== 0x47d840 Camera_SetShakeBasisFromMatrix

/* [canon] camera low (ghidra-canon) docs/re/camera.md */

void __fastcall Camera_SetShakeBasisFromMatrix(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 *in_EAX;
  
  uVar1 = *in_EAX;
  uVar2 = in_EAX[1];
  uVar3 = in_EAX[3];
  *(undefined4 *)(param_1 + 0x78) = in_EAX[2];
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  *(undefined4 *)(param_1 + 0x7c) = uVar3;
  *(undefined4 *)(param_1 + 0x74) = uVar2;
  uVar1 = in_EAX[4];
  uVar2 = in_EAX[5];
  uVar3 = in_EAX[7];
  *(undefined4 *)(param_1 + 0x98) = in_EAX[6];
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  *(undefined4 *)(param_1 + 0x9c) = uVar3;
  *(undefined4 *)(param_1 + 0x94) = uVar2;
  fVar8 = (float)in_EAX[0x10] * (float)in_EAX[0x11];
  fVar7 = (float)in_EAX[0x10] * (float)in_EAX[0x12];
  fVar4 = (float)in_EAX[8];
  fVar5 = (float)in_EAX[9];
  fVar6 = (float)in_EAX[0xb];
  *(float *)(param_1 + 0x88) = fVar7 * (float)in_EAX[10];
  *(float *)(param_1 + 0x80) = fVar8 * fVar4;
  *(float *)(param_1 + 0x8c) = fVar8 * fVar6;
  *(float *)(param_1 + 0x84) = fVar7 * fVar5;
  fVar4 = (float)in_EAX[0xc];
  fVar5 = (float)in_EAX[0xd];
  fVar6 = (float)in_EAX[0xf];
  *(float *)(param_1 + 0xa8) = fVar7 * (float)in_EAX[0xe];
  *(float *)(param_1 + 0xa0) = fVar8 * fVar4;
  *(float *)(param_1 + 0xac) = fVar8 * fVar6;
  *(float *)(param_1 + 0xa4) = fVar7 * fVar5;
  return;
}


// ==== 0x47d940 FUN_0047d940

void FUN_0047d940(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int unaff_ESI;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
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
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  fVar1 = *(float *)(unaff_ESI + 0x70);
  fVar2 = *(float *)(unaff_ESI + 0x74);
  fVar3 = *(float *)(unaff_ESI + 0x78);
  FUN_0047d780(*(float *)(unaff_ESI + 0x7c) * param_1);
  FUN_0047d780(fVar3 * param_1);
  fVar7 = (float10)FUN_0047d780(fVar2 * param_1);
  fVar8 = (float10)FUN_0047d780(fVar1 * param_1);
  fVar1 = *(float *)(unaff_ESI + 0x80);
  fVar2 = *(float *)(unaff_ESI + 0x84);
  fVar3 = *(float *)(unaff_ESI + 0x90);
  fVar4 = *(float *)(unaff_ESI + 0x94);
  fVar5 = *(float *)(unaff_ESI + 0x98);
  FUN_0047d780(*(float *)(unaff_ESI + 0x9c) * param_1);
  FUN_0047d780(fVar5 * param_1);
  fVar9 = (float10)FUN_0047d780(fVar4 * param_1);
  fVar10 = (float10)FUN_0047d780(fVar3 * param_1);
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
  local_18 = 0;
  local_14 = 0x3f800000;
  local_20 = (float)(fVar10 * (float10)*(float *)(unaff_ESI + 0xa0) +
                    (float10)(float)(fVar8 * (float10)fVar1)) * param_2;
  local_1c = ((float)fVar9 * *(float *)(unaff_ESI + 0xa4) + (float)fVar7 * fVar2) * param_2;
  iVar6 = _ftol_nocw();
  FUN_0047d7f0(iVar6 / 0x168);
  FUN_0040b990(&local_50,&local_50);
  iVar6 = _ftol_nocw();
  FUN_0047d7f0(iVar6 / 0x168);
  FUN_0040ba40(&local_50,&local_50);
  D3DXMatrixMultiply();
  return;
}


// ==== 0x47dbf0 FUN_0047dbf0

void * __thiscall FUN_0047dbf0(void *param_1,byte param_2)

{
  BaseCameraCoordinator___BaseCameraCoordinator();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x47dc10 BaseCameraCoordinator::_BaseCameraCoordinator

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall BaseCameraCoordinator___BaseCameraCoordinator(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c8118;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  iVar1 = param_1[1];
  piVar2 = (int *)param_1[2];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return;
}


// ==== 0x47dc40 UpdateCameraCoordinators

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void UpdateCameraCoordinators(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (DAT_007796fc == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(DAT_007796fc + -4);
  }
  piVar1 = (int *)Ptr_BaseAdjustMinus4();
  while (piVar2 != piVar1) {
    if (piVar2[4] == 0) {
      (**(code **)(*piVar2 + 4))(param_1);
    }
    if (piVar2[1] == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[1] + -4);
    }
  }
  return;
}


// ==== 0x47dc90 MarkCameraDataAsNeedingToBeReloaded

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void MarkCameraDataAsNeedingToBeReloaded(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_007796fc == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_007796fc + -4;
  }
  iVar1 = Ptr_BaseAdjustMinus4();
  while (iVar2 != iVar1) {
    *(undefined4 *)(iVar2 + 0x18) = 1;
    if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  return;
}


// ==== 0x47dcd0 CameraTables_LoadChunk

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 __fastcall CameraTables_LoadChunk(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *unaff_ESI;
  
  iVar3 = *param_1;
  if (iVar3 == -0x7ffcbbfb) {
    *unaff_ESI = 0;
    piVar1 = (int *)(param_1[1] + 8 + (int)param_1);
    param_1 = param_1 + 2;
    if (param_1 < piVar1) {
      do {
        if (*param_1 == 0x34440) {
          piVar4 = (int *)((int)param_1 + 0x17U & 0xfffffff0);
          iVar3 = piVar4[1];
          iVar2 = piVar4[2];
          unaff_ESI[0x284] = *piVar4;
          unaff_ESI[0x285] = iVar3;
          unaff_ESI[0x286] = iVar2;
          unaff_ESI[0x288] = piVar4[4];
        }
        else if (*param_1 == 0x34450) {
          unaff_ESI[*unaff_ESI + 1] = (int)param_1 + 0x17U & 0xfffffff0;
          *unaff_ESI = *unaff_ESI + 1;
        }
        param_1 = (int *)((int)param_1 + param_1[1] + 8);
      } while (param_1 < piVar1);
      MarkCameraDataAsNeedingToBeReloaded();
      return 1;
    }
  }
  else if (iVar3 == -0x7ffcbbdb) {
    unaff_ESI[0x201] = 0;
    piVar1 = (int *)(param_1[1] + 8 + (int)param_1);
    param_1 = param_1 + 2;
    if (param_1 < piVar1) {
      do {
        if (*param_1 == 0x34490) {
          unaff_ESI[unaff_ESI[0x201] + 0x202] = (int)param_1 + 0x17U & 0xfffffff0;
          unaff_ESI[0x201] = unaff_ESI[0x201] + 1;
        }
        param_1 = (int *)((int)param_1 + param_1[1] + 8);
      } while (param_1 < piVar1);
      MarkCameraDataAsNeedingToBeReloaded();
      return 1;
    }
  }
  else if (iVar3 == -0x7ffcbbf0) {
    unaff_ESI[0x222] = 0;
    piVar1 = (int *)(param_1[1] + 8 + (int)param_1);
    param_1 = param_1 + 2;
    if (param_1 < piVar1) {
      do {
        if (*param_1 == 0x34460) {
          unaff_ESI[unaff_ESI[0x222] + 0x223] = (int)param_1 + 0x17U & 0xfffffff0;
          unaff_ESI[0x222] = unaff_ESI[0x222] + 1;
        }
        param_1 = (int *)((int)param_1 + param_1[1] + 8);
      } while (param_1 < piVar1);
      MarkCameraDataAsNeedingToBeReloaded();
      return 1;
    }
  }
  else if (iVar3 == -0x7ffcbbeb) {
    unaff_ESI[0x243] = 0;
    piVar1 = (int *)(param_1[1] + 8 + (int)param_1);
    param_1 = param_1 + 2;
    if (param_1 < piVar1) {
      do {
        if (*param_1 == 0x34470) {
          unaff_ESI[unaff_ESI[0x243] + 0x244] = (int)param_1 + 0x17U & 0xfffffff0;
          unaff_ESI[0x243] = unaff_ESI[0x243] + 1;
        }
        param_1 = (int *)((int)param_1 + param_1[1] + 8);
      } while (param_1 < piVar1);
      MarkCameraDataAsNeedingToBeReloaded();
      return 1;
    }
  }
  else if (iVar3 == -0x7ffcbbe0) {
    piVar1 = (int *)(param_1[1] + 8 + (int)param_1);
    param_1 = param_1 + 2;
    if (param_1 < piVar1) {
      do {
        if (*param_1 == 0x34480) {
          unaff_ESI[unaff_ESI[0x264] + 0x265] = (int)param_1 + 0x17U & 0xfffffff0;
          unaff_ESI[0x264] = unaff_ESI[0x264] + 1;
        }
        param_1 = (int *)((int)param_1 + param_1[1] + 8);
      } while (param_1 < piVar1);
      MarkCameraDataAsNeedingToBeReloaded();
      return 1;
    }
  }
  else {
    if (iVar3 != 0x34492) {
      return 0;
    }
    unaff_ESI[0x27f] = (uint)param_1[1] / 0x230;
    unaff_ESI[0x280] = (int)param_1 + 0x17U & 0xfffffff0;
  }
  MarkCameraDataAsNeedingToBeReloaded();
  return 1;
}


// ==== 0x47df00 CameraTables_Unload_Impl

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 CameraTables_Unload_Impl(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int local_c;
  int local_8;
  
  iVar2 = *param_2;
  if (iVar2 == -0x7ffcbbfb) {
    *param_1 = 0;
    return 1;
  }
  if (iVar2 == -0x7ffcbbdb) {
    param_1[0x201] = 0;
    return 1;
  }
  if (iVar2 == -0x7ffcbbf0) {
    param_1[0x222] = 0;
    return 1;
  }
  if (iVar2 != -0x7ffcbbeb) {
    if (iVar2 == -0x7ffcbbe0) {
      piVar1 = (int *)(param_2[1] + 8 + (int)param_2);
      param_2 = param_2 + 2;
      local_8 = -1;
      local_c = 0;
      if (param_2 < piVar1) {
        do {
          if (*param_2 == 0x34480) {
            iVar2 = 0;
            puVar6 = param_1 + 0x26f;
            piVar5 = param_1 + 0x26d;
            do {
              iVar4 = *piVar5;
              puVar3 = puVar6;
              if (0 < iVar4) {
                do {
                  if (*puVar3 == ((int)param_2 + 0x17U & 0xfffffff0)) {
                    local_c = local_c + 1;
                    local_8 = iVar2;
                  }
                  iVar4 = iVar4 + -1;
                  puVar3 = puVar3 + 1;
                } while (iVar4 != 0);
              }
              iVar2 = iVar2 + 1;
              piVar5 = piVar5 + 1;
              puVar6 = puVar6 + 8;
            } while (iVar2 < 2);
          }
          param_2 = (int *)(param_2[1] + 8 + (int)param_2);
        } while (param_2 < piVar1);
        if (0 < local_c) {
          param_1[local_8 + 0x26d] = param_1[local_8 + 0x26d] - local_c;
          return 1;
        }
      }
    }
    else {
      if (iVar2 != 0x34492) {
        return 0;
      }
      param_1[0x27f] = 0;
    }
    return 1;
  }
  param_1[0x243] = 0;
  return 1;
}


// ==== 0x47e080 CameraLoader::FindRandomCameraShake

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

int CameraLoader__FindRandomCameraShake(int param_1)

{
  int in_EAX;
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = *(int *)(in_EAX + 0x9fc);
  uVar5 = 0;
  if (0 < iVar3) {
    piVar1 = (int *)(*(int *)(in_EAX + 0xa00) + 0x20);
    do {
      if (*piVar1 == param_1) {
        uVar5 = uVar5 + 1;
      }
      piVar1 = piVar1 + 0x8c;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (uVar5 != 0) {
      uVar4 = DAT_006f227c ^ 0x1d872b41;
      uVar5 = DAT_006f227c % uVar5;
      uVar2 = uVar4 >> 5 ^ uVar4;
      DAT_006f227c = uVar2 << 0x1b ^ uVar2 ^ uVar4;
      iVar3 = 0;
      if (0 < *(int *)(in_EAX + 0x9fc)) {
        piVar1 = (int *)(*(int *)(in_EAX + 0xa00) + 0x20);
        do {
          if (*piVar1 == param_1) {
            if (uVar5 == 0) {
              return iVar3 * 0x230 + *(int *)(in_EAX + 0xa00);
            }
            uVar5 = uVar5 - 1;
          }
          iVar3 = iVar3 + 1;
          piVar1 = piVar1 + 0x8c;
        } while (iVar3 < *(int *)(in_EAX + 0x9fc));
      }
    }
  }
  return 0;
}


// ==== 0x47e130 FUN_0047e130

int FUN_0047e130(int *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int local_a8;
  byte *local_a0;
  
  local_a8 = 0;
  do {
    iVar5 = 0;
    piVar4 = (int *)0x0;
    if (local_a8 == 0) {
      iVar5 = *param_1;
      piVar4 = param_1 + 1;
    }
    else if (local_a8 == 1) {
      iVar5 = param_1[0x201];
      piVar4 = param_1 + 0x202;
    }
    else if (local_a8 == 2) {
      iVar5 = param_1[0x222];
      piVar4 = param_1 + 0x223;
    }
    else if (local_a8 == 3) {
      iVar5 = param_1[0x243];
      piVar4 = param_1 + 0x244;
    }
    iVar7 = 0;
    if (0 < iVar5) {
      do {
        CameraDataItems__CameraDataItems();
        pbVar3 = param_2;
        pbVar6 = local_a0;
        do {
          bVar2 = *pbVar6;
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 & 0x5f;
          }
          bVar1 = *pbVar3;
          pbVar6 = pbVar6 + 1;
          if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
            bVar1 = bVar1 & 0x5f;
          }
          pbVar3 = pbVar3 + 1;
        } while (((bVar2 != 0) && (bVar1 != 0)) && (bVar2 == bVar1));
        if (bVar2 == bVar1) {
          return piVar4[iVar7];
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
    }
    local_a8 = local_a8 + 1;
    if (4 < local_a8) {
      return 0;
    }
  } while( true );
}


// ==== 0x47e230 CameraTables_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void CameraTables_Load(void)

{
  CameraTables_LoadChunk();
  return;
}


// ==== 0x47e250 CameraTables_Unload

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void CameraTables_Unload(undefined4 param_1)

{
  CameraTables_Unload_Impl(&DAT_00736870,param_1);
  return;
}


// ==== 0x47e270 DemoCameraCoordinator::DemoCameraCoordinator

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __thiscall DemoCameraCoordinator__DemoCameraCoordinator(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c8118;
  in_EAX[5] = param_1;
  in_EAX[3] = 0;
  in_EAX[6] = 0;
  in_EAX[4] = 0;
  puVar1 = in_EAX + 1;
  *DAT_00779700 = puVar1;
  puVar3 = puVar1;
  in_EAX[2] = DAT_00779700;
  DAT_00779700 = puVar3;
  *puVar1 = &DAT_007796fc;
  *in_EAX = &PTR_FUN_006c8130;
  in_EAX[7] = param_2;
  uVar2 = DAT_00737290;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[0xc] = uVar2;
  in_EAX[0xb] = 0xffffffff;
  return;
}


// ==== 0x47e2d0 DemoCameraCoordinator::_DemoCameraCoordinator

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void DemoCameraCoordinator___DemoCameraCoordinator(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c8118;
  if ((undefined4 *)in_EAX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_EAX[3])(1);
  }
  iVar1 = in_EAX[1];
  piVar2 = (int *)in_EAX[2];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return;
}


// ==== 0x47e300 FUN_0047e300

void __fastcall FUN_0047e300(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  void *pvVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  float10 fVar17;
  int local_334;
  int local_2f8 [40];
  undefined4 uStack_258;
  undefined4 auStack_250 [10];
  undefined4 uStack_228;
  void *pvStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_00686d16;
  local_1c = ExceptionList;
  iVar13 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 0x1c);
  ExceptionList = &local_1c;
  *(undefined4 *)(param_1 + 0x18) = 0;
  bVar6 = false;
  local_334 = -1;
  if ((*(int *)(param_1 + 0xc) == 0) || (iVar13 != 0)) {
    bVar6 = true;
    local_334 = FUN_0047e8c0(param_1);
  }
  else if ((0x37 < DAT_006f08a0 - *(int *)(param_1 + 0x28)) &&
          ((*(int *)(param_1 + 0x2c) == -1 || (iVar7 = FUN_0047e7e0(param_1,iVar1), iVar7 == 0)))) {
    bVar6 = true;
    local_334 = FUN_0047e8c0(param_1);
    if ((*(int *)(param_1 + 0x2c) == -1) && (local_334 == -1)) {
      bVar6 = false;
    }
  }
  bVar5 = false;
  if (((*(int *)(param_1 + 0x2c) != -1) && (*(int *)(param_1 + 0xc) != 0)) &&
     (0x37 < DAT_006f08a0 - *(int *)(param_1 + 0x28))) {
    iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 0x1c);
    for (puVar16 = (undefined4 *)*DAT_007361f8; puVar16 != DAT_007361f8;
        puVar16 = (undefined4 *)*puVar16) {
      fVar2 = *(float *)(iVar7 + 0x40) - (float)puVar16[0x18];
      fVar4 = *(float *)(iVar7 + 0x44) - (float)puVar16[0x19];
      fVar3 = *(float *)(iVar7 + 0x48) - (float)puVar16[0x1a];
      if (SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) < 2.0) {
        bVar5 = true;
        break;
      }
    }
  }
  piVar10 = (int *)0x0;
  if ((!bVar6) && (!bVar5)) {
    ExceptionList = local_1c;
    return;
  }
  if (((*DAT_007361f0 == 9) && (DAT_00737290 != 0)) &&
     ((*(int *)(param_1 + 0x30) == DAT_00737290 || (iVar13 != 0)))) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    TrackPath__UpdateCursor(&DAT_007372b0,&DAT_00737280);
    uVar8 = Atan2ToAngle16(0x3f800000,0);
    fVar17 = (float10)Car_GetLaneSpeedCapFraction(uVar8);
    FUN_00427c50(&DAT_00737280,(float)fVar17,uVar8);
    TrackPath__UpdateCursor(&DAT_007372b0,iVar1 + 0x60);
    (**(code **)(**(int **)(iVar1 + 0x2c) + 0x2c))(1);
    (**(code **)(**(int **)(iVar1 + 0x2c) + 0x30))();
    *(undefined4 *)(iVar1 + 0x884) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    ExceptionList = pvStack_20;
    return;
  }
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if ((local_334 != -1) && (!bVar5)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    CameraDataItems__CameraDataItems();
    if (local_2f8[0] == 0) {
      CameraLoader__FindRandomCameraShake(uStack_258);
      puVar16 = auStack_250;
      for (iVar13 = 0x8c; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar16 = 0;
        puVar16 = puVar16 + 1;
      }
      uStack_228 = 2;
      pvVar9 = _malloc(0x470);
      if (pvVar9 == (void *)0x0) {
LAB_0047e63a:
        piVar10 = (int *)0x0;
      }
      else {
        piVar10 = (int *)TrackCarCameraMover__ctor(pvVar9,iVar1,local_2f8,auStack_250,1);
      }
    }
    else if (local_2f8[0] == 1) {
      pvVar9 = _malloc(0x45c);
      if (pvVar9 == (void *)0x0) goto LAB_0047e63a;
      piVar10 = (int *)FUN_004848f0(pvVar9,iVar1,local_2f8);
    }
    else if (local_2f8[0] == 2) {
      pvVar9 = _malloc(0x19c);
      if (pvVar9 == (void *)0x0) goto LAB_0047e63a;
      piVar10 = (int *)FUN_004864e0(pvVar9,local_2f8,iVar1);
    }
    (**(code **)(*piVar10 + 0x3c))();
    (**(code **)(*piVar10 + 4))();
    iVar13 = piVar10[7];
    for (puVar16 = (undefined4 *)*DAT_007361f8; puVar16 != DAT_007361f8;
        puVar16 = (undefined4 *)*puVar16) {
      fVar2 = *(float *)(iVar13 + 0x40) - (float)puVar16[0x18];
      fVar4 = *(float *)(iVar13 + 0x44) - (float)puVar16[0x19];
      fVar3 = *(float *)(iVar13 + 0x48) - (float)puVar16[0x1a];
      if (SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) < 5.0) {
        (**(code **)*piVar10)(1);
        goto LAB_0047e6b7;
      }
    }
    *(int **)(param_1 + 0xc) = piVar10;
    (**(code **)(*piVar10 + 0x38))();
    goto LAB_0047e7ab;
  }
LAB_0047e6b7:
  local_334 = -1;
  if (DAT_007364a0 == 3) {
    uVar15 = *(uint *)(*(int *)(iVar1 + 0xc) + 0xb54);
  }
  else {
    uVar15 = *(uint *)(*(int *)(iVar1 + 0xc) + 0xb50);
  }
  uVar11 = 0;
  if (0 < (int)uVar15) {
    uVar11 = DAT_006f227c % uVar15;
    uVar14 = DAT_006f227c ^ 0x1d872b41;
    uVar12 = uVar14 >> 5 ^ uVar14;
    DAT_006f227c = uVar12 << 0x1b ^ uVar12 ^ uVar14;
  }
  if ((uVar11 == *(uint *)(param_1 + 0x24)) && (0 < (int)uVar15)) {
    *(int *)(param_1 + 0x24) = (int)(*(uint *)(param_1 + 0x24) + 1) % (int)uVar15;
  }
  else {
    *(uint *)(param_1 + 0x24) = uVar11;
  }
  *(uint *)(param_1 + 0x20) = (uint)(*(int *)(param_1 + 0x20) == 0);
  if (DAT_00700aa4 == 0) {
    pvVar9 = _malloc(0x3a0);
    if (pvVar9 == (void *)0x0) goto LAB_0047e7a6;
    uVar8 = DriveCameraMover__ctor
                      (iVar1,*(undefined4 *)(param_1 + 0x24),0x43960000,1,
                       *(undefined4 *)(param_1 + 0x20),0);
  }
  else {
    pvVar9 = _malloc(0x54);
    uStack_14 = 0;
    if (pvVar9 == (void *)0x0) {
LAB_0047e7a6:
      uVar8 = 0;
    }
    else {
      uVar8 = CubicCameraMover__ctor
                        (pvVar9,*(undefined4 *)(param_1 + 0x14),iVar1,
                         *(undefined4 *)(param_1 + 0x24),1,
                         CONCAT31((int3)((uint)*(int *)(param_1 + 0x20) >> 8),
                                  *(int *)(param_1 + 0x20) != 0),0);
    }
  }
  *(undefined4 *)(param_1 + 0xc) = uVar8;
LAB_0047e7ab:
  *(int *)(param_1 + 0x28) = DAT_006f08a0;
  *(int *)(param_1 + 0x2c) = local_334;
  ExceptionList = local_1c;
  return;
}


// ==== 0x47e7e0 FUN_0047e7e0

void FUN_0047e7e0(undefined4 param_1,undefined4 param_2)

{
  CameraDataItems__CameraDataItems();
  DemoCameraCoordinator__WillLookGood(param_1,param_2);
  return;
}


// ==== 0x47e820 DemoCameraCoordinator::WillLookGood

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

undefined4 DemoCameraCoordinator__WillLookGood(void)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  int *piVar5;
  int iStack00000008;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iStack00000008 = *(int *)(in_EAX + 0x48);
  iVar4 = 0;
  if (0 < iStack00000008) {
    iVar2 = *(int *)(in_EAX + 0x44);
    piVar5 = *(int **)(in_EAX + 0x4c);
    do {
      local_14 = *(undefined4 *)(iVar2 + 4 + *piVar5 * 8);
      local_18 = *(undefined4 *)(iVar2 + *piVar5 * 8);
      puVar1 = (undefined4 *)(iVar2 + piVar5[1] * 8);
      local_10 = *puVar1;
      local_c = puVar1[1];
      puVar1 = (undefined4 *)(iVar2 + piVar5[2] * 8);
      local_4 = puVar1[1];
      local_8 = *puVar1;
      cVar3 = PointInPolygon2D(&local_18,3);
      if (cVar3 != '\0') {
        return 1;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 4;
    } while (iVar4 < iStack00000008);
  }
  return 0;
}


// ==== 0x47e8c0 FUN_0047e8c0

int FUN_0047e8c0(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int unaff_ESI;
  bool bVar3;
  undefined4 local_74;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < DAT_00736870) {
    do {
      CameraDataItems__CameraDataItems();
      bVar3 = DAT_0078a2fc == 1;
      bVar1 = false;
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x2c) + 0x18))(0);
      if (((iVar2 == 0) ||
          (0.0 < *(float *)(iVar2 + 0xc) * *(float *)(unaff_ESI + 0x90) +
                 *(float *)(iVar2 + 0x10) * *(float *)(unaff_ESI + 0x94))) && (bVar3)) {
        bVar1 = true;
      }
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x2c) + 0x18))(0);
      if (((iVar2 != 0) &&
          (*(float *)(iVar2 + 0xc) * *(float *)(unaff_ESI + 0x90) +
           *(float *)(iVar2 + 0x10) * *(float *)(unaff_ESI + 0x94) <= 0.0)) && (!bVar3)) {
        bVar1 = true;
      }
      if (!bVar1 == (local_74 == 0)) {
        iVar2 = DemoCameraCoordinator__WillLookGood(param_1,unaff_ESI);
        if (iVar2 != 0) {
          return local_8;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < DAT_00736870);
  }
  return -1;
}


// ==== 0x47e9d0 FlyByCameraCoordinator::FlyByCameraCoordinator

/* [canon] camera med (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall FlyByCameraCoordinator__FlyByCameraCoordinator(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c8118;
  in_EAX[5] = param_1;
  in_EAX[3] = 0;
  in_EAX[6] = 0;
  in_EAX[4] = 0;
  puVar1 = in_EAX + 1;
  *DAT_00779700 = puVar1;
  puVar3 = puVar1;
  in_EAX[2] = DAT_00779700;
  DAT_00779700 = puVar3;
  *puVar1 = &DAT_007796fc;
  *in_EAX = &PTR_FUN_006c8148;
  uVar2 = DAT_00737290;
  in_EAX[8] = 0;
  in_EAX[9] = uVar2;
  in_EAX[7] = 0xffffffff;
  return;
}


// ==== 0x47ea20 FUN_0047ea20

void __fastcall FUN_0047ea20(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 auStack_a4 [164];
  
  if ((*(int *)(param_1 + 0x1c) == -1) || (*(int *)(param_1 + 0x18) != 0)) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if (((*(int *)(param_1 + 0xc) != 0) && (*(int *)(*(int *)(param_1 + 0xc) + 0xc) == 9)) &&
          (iVar1 = FUN_00486c00(), iVar1 == 0)) {
    return;
  }
  if (DAT_00737074 <= *(int *)(param_1 + 0x20)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  CameraDataItems__CameraDataItems();
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  pvVar2 = _malloc(0x19c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004864e0(pvVar2,auStack_a4,0);
  }
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}


// ==== 0x47eae0 FUN_0047eae0

undefined4 * __fastcall FUN_0047eae0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_1[5] = in_EAX;
  *param_1 = &PTR_FUN_006c8118;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  puVar3 = param_1 + 1;
  *DAT_00779700 = puVar3;
  puVar1 = puVar3;
  param_1[2] = DAT_00779700;
  DAT_00779700 = puVar1;
  *puVar3 = &DAT_007796fc;
  *param_1 = &PTR_FUN_006c8140;
  param_1[0x2d] = 0;
  param_1[0xb] = 0xffffffff;
  param_1[8] = DAT_00737290;
  param_1[7] = 0xffffffff;
  param_1[10] = 0;
  param_1[0x2e] = 0;
  iVar4 = DAT_0073619c;
  if (DAT_0078a368 == 0) {
    if (DAT_007361c4 == 2) {
      if (*(int *)(DAT_0073619c + 0x24) < 1) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = *(undefined4 **)(DAT_0073619c + 0x520);
      }
      param_1[0xd] = *puVar3;
      param_1[0xe] = *(undefined4 *)(DAT_007361b4 + 4);
      param_1[0xf] = *(undefined4 *)(DAT_007361b8 + 4);
      iVar4 = DAT_007361b4;
    }
    else {
      param_1[0xd] = *(undefined4 *)(DAT_007361bc + 4);
      param_1[0xe] = *(undefined4 *)(DAT_007361bc + 4);
      param_1[0xf] = *(undefined4 *)(DAT_007361bc + 4);
      iVar4 = DAT_007361bc;
    }
    param_1[0x10] = *(undefined4 *)(iVar4 + 4);
    param_1[9] = 4;
    param_1[0xc] = 4;
    return param_1;
  }
  if (DAT_007361c4 == 2) {
    param_1[0xd] = *(undefined4 *)(DAT_007361b4 + 4);
    param_1[0xe] = *(undefined4 *)(DAT_007361b8 + 4);
    param_1[9] = 2;
    param_1[0xc] = 2;
    return param_1;
  }
  if (*(int *)(DAT_0073619c + 0x24) < 1) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(DAT_0073619c + 0x520);
  }
  param_1[0xd] = *puVar3;
  iVar2 = (int)(1 % (longlong)*(int *)(iVar4 + 0x24)) + 1;
  if (*(int *)(iVar4 + 0x24) < iVar2) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(iVar4 + 0x51c + iVar2 * 4);
  }
  param_1[0xe] = *puVar3;
  iVar2 = (int)(2 % (longlong)*(int *)(iVar4 + 0x24)) + 1;
  if (*(int *)(iVar4 + 0x24) < iVar2) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(iVar4 + 0x51c + iVar2 * 4);
  }
  param_1[0xf] = *puVar3;
  iVar2 = (int)(3 % (longlong)*(int *)(iVar4 + 0x24)) + 1;
  if (iVar2 <= *(int *)(iVar4 + 0x24)) {
    param_1[0x10] = **(undefined4 **)(iVar4 + 0x51c + iVar2 * 4);
    param_1[9] = 4;
    param_1[0xc] = 4;
    return param_1;
  }
  param_1[0x10] = uRam00000000;
  param_1[9] = 4;
  param_1[0xc] = 4;
  return param_1;
}


// ==== 0x47eca0 FUN_0047eca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047eca0(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 auStack_a4 [164];
  
  uVar3 = *(undefined4 *)(param_1 + 0x34 + *(int *)(param_1 + 0xb4) * 4);
  if ((*(int *)(param_1 + 0x1c) == -1) || (*(int *)(param_1 + 0x18) != 0)) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if ((*(int *)(param_1 + 0xc) != 0) && (iVar1 = BumperCameraMover__IsFinished(), iVar1 == 0))
  {
    return;
  }
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if ((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x30)) && (DAT_00734690 == 0)) {
    *(undefined4 *)(param_1 + 0xb8) = 1;
    return;
  }
  iVar1 = *(int *)(param_1 + 0xb4) + 1;
  *(int *)(param_1 + 0xb4) = iVar1;
  if (iVar1 == *(int *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x2c) + 1;
  *(int *)(param_1 + 0x2c) = iVar1;
  if (_DAT_007370f8 <= iVar1) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  CameraDataItems__CameraDataItems();
  pvVar2 = _malloc(0x45c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004848f0(pvVar2,uVar3,auStack_a4);
  }
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  return;
}


// ==== 0x47edb0 CountdownCameraCoordinator::ctor

/* [canon] camera I (M+C) docs/re/camera.md */

undefined4 *
CountdownCameraCoordinator__ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685bb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[5] = param_2;
  *param_1 = &PTR_FUN_006c8118;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  puVar1 = param_1 + 1;
  *DAT_00779700 = puVar1;
  puVar2 = puVar1;
  param_1[2] = DAT_00779700;
  DAT_00779700 = puVar2;
  *puVar1 = &DAT_007796fc;
  param_1[7] = param_3;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c8138;
  param_1[8] = 0xffffffff;
  FUN_0047ee50(0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x47ee30 FUN_0047ee30

void * __thiscall FUN_0047ee30(void *param_1,byte param_2)

{
  DemoCameraCoordinator___DemoCameraCoordinator();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x47ee50 FUN_0047ee50

void __fastcall FUN_0047ee50(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined1 local_c4 [32];
  undefined1 auStack_a4 [164];
  
  iVar1 = TimedMessage__GetPhase();
  if (iVar1 != *(int *)(param_1 + 0x20)) {
    if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    FUN_00565da0("COUNTDOWN_%d",iVar1);
    iVar2 = FUN_0047e130(&DAT_00736870,local_c4);
    if (iVar2 != 0) {
      CameraDataItems__CameraDataItems();
      pvVar3 = _malloc(0x45c);
      if (pvVar3 != (void *)0x0) {
        uVar4 = FUN_004848f0(pvVar3,*(undefined4 *)(*(int *)(param_1 + 0x1c) + 4),auStack_a4);
        *(int *)(param_1 + 0x20) = iVar1;
        *(undefined4 *)(param_1 + 0xc) = uVar4;
        return;
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    *(int *)(param_1 + 0x20) = iVar1;
  }
  return;
}


// ==== 0x47ef00 IntroNisCoordinator

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (M+C) docs/re/camera.md */

undefined4 * IntroNisCoordinator(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  bool bVar9;
  undefined4 uVar10;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00687428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = param_2;
  *param_1 = &PTR_FUN_006c8118;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  puVar1 = param_1 + 1;
  *DAT_00779700 = puVar1;
  puVar7 = puVar1;
  param_1[2] = DAT_00779700;
  DAT_00779700 = puVar7;
  *puVar1 = &DAT_007796fc;
  *param_1 = &PTR_FUN_006c8128;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0x41000000;
  param_1[10] = 0x41400000;
  param_1[0xb] = 0;
  local_8 = 0;
  if (DAT_007301d4 != 0) {
    bMemoryPool_TotalAllocated();
  }
  iVar6 = DAT_00779818;
  if (DAT_00779818 != 0) {
    if (DAT_00779810 == 0) {
      iVar8 = 0;
    }
    else {
      FUN_0047cb50(&DAT_00779800);
      FUN_0047c160(&DAT_00779800);
      iVar8 = FUN_0047c020(&DAT_00779800);
      FUN_0047c310(&DAT_00779800);
    }
    param_1[8] = iVar8;
    param_1[8] = (uint)(iVar8 != 0);
    if ((iVar8 != 0) == 0) {
      param_2 = 0;
      if (0 < DAT_007361c4) {
        do {
          iVar8 = (&DAT_007361bc)[param_2];
          iVar2 = *(int *)(DAT_007361f0 + 0x3c);
          if ((((iVar2 == 0) || (*(int *)(iVar2 + 0x20) == 0)) || (*(int *)(iVar2 + 0x1c) == 0)) &&
             ((*(int *)(DAT_007361f0 + 0x40) == 0 ||
              (*(int *)(*(int *)(DAT_007361f0 + 0x40) + 0x1c) == 0)))) {
            Player__ChangeCameraMover(iVar8,(-(DAT_00700aa4 != 0) & 0x10U) + 1,0);
            piVar3 = *(int **)(iVar8 + 0x27c);
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 0x34))();
            }
          }
          param_2 = param_2 + 1;
        } while (param_2 < DAT_007361c4);
      }
    }
    else {
      param_2 = 0;
      if (0 < DAT_007361c4) {
        do {
          if (param_2 == 0) {
            uVar10 = 0x16;
          }
          else {
            uVar10 = 0;
          }
          Player__ChangeCameraMover((&DAT_007361bc)[param_2],uVar10,0);
          param_2 = param_2 + 1;
        } while (param_2 < DAT_007361c4);
      }
    }
    if (*(int *)(DAT_007361f8 + 0x2f0) != 0) {
      Teleporter_Disable();
    }
    iVar8 = DAT_0073619c;
    if (DAT_00779810 != 0) {
      fVar4 = _K_ONE / DAT_006ffdbc;
      bVar9 = DAT_0073619c != 0;
      param_1[10] = (float)*(int *)(DAT_00779810 + 100) * fVar4;
      fVar5 = (float)*(int *)(DAT_00779810 + 0x6c) * fVar4;
      param_1[9] = fVar5;
      if (bVar9) {
        *(float *)(iVar8 + 0xc) =
             ((float)*(int *)(DAT_00779810 + 0x68) * fVar4 - fVar5) * 0.33333334;
      }
      param_1[7] = 1;
    }
    WorldObjectCohort__Launch(iVar6,0);
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x47f130 FUN_0047f130

void * __thiscall FUN_0047f130(void *param_1,byte param_2)

{
  FUN_0047f150(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x47f150 FUN_0047f150

void FUN_0047f150(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00687428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_006c8128;
  iVar6 = 0;
  local_8 = 0;
  if (*(int *)(DAT_007361f8 + 0x2f0) != 0) {
    Teleporter_Enable();
  }
  iVar1 = DAT_007361c4;
  if ((param_1[8] != 0) && (param_1[8] = 0, 0 < iVar1)) {
    do {
      iVar1 = *(int *)(DAT_007361f0 + 0x3c);
      iVar2 = (&DAT_007361bc)[iVar6];
      if (((iVar1 == 0) || ((*(int *)(iVar1 + 0x20) == 0 || (*(int *)(iVar1 + 0x1c) == 0)))) &&
         ((*(int *)(DAT_007361f0 + 0x40) == 0 ||
          (*(int *)(*(int *)(DAT_007361f0 + 0x40) + 0x1c) == 0)))) {
        Player__ChangeCameraMover(iVar2,(-(DAT_00700aa4 != 0) & 0x10U) + 1,0);
        piVar4 = *(int **)(iVar2 + 0x27c);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x34))();
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_007361c4);
  }
  if ((DAT_00779818 != 0) && (FUN_00578b10(DAT_00779818), DAT_00779818 != 0)) {
    piVar4 = DAT_0077af10;
    if ((int **)DAT_0077af10 != &DAT_0077af10) {
      do {
        if ((short)piVar4[2] == 0x8fc) {
          iVar6 = *piVar4;
          piVar3 = (int *)piVar4[1];
          *piVar3 = iVar6;
          *(int **)(iVar6 + 4) = piVar3;
          _free(piVar4);
          break;
        }
        piVar4 = (int *)*piVar4;
      } while ((int **)piVar4 != &DAT_0077af10);
    }
    piVar4 = DAT_0077af10;
    if ((int **)DAT_0077af10 != &DAT_0077af10) {
      do {
        if (DAT_00779818 == (short)piVar4[2]) {
          iVar6 = *piVar4;
          piVar3 = (int *)piVar4[1];
          *piVar3 = iVar6;
          *(int **)(iVar6 + 4) = piVar3;
          _free(piVar4);
          break;
        }
        piVar4 = (int *)*piVar4;
      } while ((int **)piVar4 != &DAT_0077af10);
    }
    DAT_0077aaf9 = 1;
    puVar5 = &DAT_0077aa6c;
    do {
      *puVar5 = 0xffffffff;
      puVar5 = puVar5 + 0x11;
    } while ((int)puVar5 < 0x77aaf4);
    FUN_0047b810();
    FUN_0047c4d0(&DAT_00779800);
    DAT_00779818 = 0;
  }
  local_8 = 0xffffffff;
  *param_1 = &PTR_FUN_006c8118;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  piVar4 = (int *)param_1[2];
  iVar6 = param_1[1];
  *piVar4 = iVar6;
  *(int **)(iVar6 + 4) = piVar4;
  ExceptionList = local_10;
  return;
}


// ==== 0x47f310 FUN_0047f310

void FUN_0047f310(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  undefined *puVar8;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined8 uVar12;
  
  uVar5 = DAT_006ffdbc;
  DAT_006ffdbc = 0x41f00000;
  if (*(float *)(param_1 + 0x24) <= *(float *)(param_1 + 0x2c)) {
    DAT_006ffdbc = uVar5;
    return;
  }
  fVar3 = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x2c);
  pcVar7 = "NISFlagGirl";
  iVar9 = -1;
  uVar6 = 0x4e;
  do {
    pbVar1 = (byte *)(pcVar7 + 1);
    iVar9 = iVar9 * 0x21 + uVar6;
    pcVar7 = pcVar7 + 1;
    uVar6 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  puVar11 = (undefined *)0x0;
  do {
    puVar4 = DAT_0073b138;
    if (iVar9 == DAT_0073b128) {
      puVar10 = &DAT_0073b118;
    }
    else {
      while( true ) {
        if ((undefined4 **)puVar4 == &DAT_0073b138) goto LAB_0047f39e;
        uVar12 = FUN_00577d10(iVar9);
        puVar10 = (undefined *)uVar12;
        if (puVar10 != (undefined *)0x0) break;
        puVar4 = (undefined4 *)*(undefined4 *)((ulonglong)uVar12 >> 0x20);
      }
    }
    if (puVar11 == (undefined *)0x0) {
      puVar11 = *(undefined **)(puVar10 + 0x2c);
      if (puVar11 == puVar10 + 0x2c) {
        puVar11 = (undefined *)FUN_00577e60(0);
      }
      else if (puVar11 == (undefined *)0x0) {
LAB_0047f463:
        puVar11 = (undefined *)0x0;
      }
      else {
        puVar11 = puVar11 + -4;
      }
    }
    else {
      piVar2 = (int *)(puVar11 + 0x18);
      if (*(int *)(puVar11 + 4) == 0) {
        puVar11 = (undefined *)0x0;
      }
      else {
        puVar11 = (undefined *)(*(int *)(puVar11 + 4) + -4);
      }
      if (*piVar2 == -0x2c) {
        puVar8 = (undefined *)0x0;
      }
      else {
        puVar8 = (undefined *)(*piVar2 + 0x28);
      }
      if (puVar11 == puVar8) {
        uVar12 = FUN_00577e60(0);
        puVar11 = (undefined *)uVar12;
        if (puVar11 == (undefined *)0x0) {
          if ((undefined *)((ulonglong)uVar12 >> 0x20) == puVar10) goto LAB_0047f463;
          puVar11 = (undefined *)FUN_00577ed0();
        }
      }
    }
    if (puVar11 == (undefined *)0x0) {
LAB_0047f39e:
      if ((*(int *)(param_1 + 0x20) != 0) && (iVar9 = 0, 0 < DAT_007361c4)) {
        do {
          if ((*(int *)((&DAT_007361bc)[iVar9] + 0x27c) != 0) &&
             (*(int *)(*(int *)((&DAT_007361bc)[iVar9] + 0x27c) + 0xc) == 0x16)) {
            FUN_0048e7b0(fVar3,1);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < DAT_007361c4);
      }
      if (DAT_006fc5f0 != 0) {
        FUN_0047c580(&DAT_00779800,fVar3);
      }
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
      DAT_006ffdbc = uVar5;
      return;
    }
    piVar2 = *(int **)(puVar11 + 0x20);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(fVar3);
      *(undefined1 *)((int)piVar2 + 0x72) = 0;
    }
  } while( true );
}


// ==== 0x47f4c0 IntroNisCoordinator::IsFinished

/* [canon] camera med (ghidra-canon) docs/re/canon.md */

undefined4 IntroNisCoordinator__IsFinished(void)

{
  int in_EAX;
  
  if ((DAT_00735f54 == 0) && (*(float *)(in_EAX + 0x28) <= *(float *)(in_EAX + 0x2c))) {
    return 1;
  }
  return 0;
}


// ==== 0x47f4e0 FUN_0047f4e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0047f4e0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = DAT_007361c4;
  iVar4 = 0;
  if ((*(int *)(param_1 + 0x20) == 0) || (DAT_00735f54 == 0)) {
    if (DAT_006ffdbc != 0.0) {
      *(float *)(param_1 + 0x2c) = DAT_0073457c + *(float *)(param_1 + 0x2c);
    }
    if (*(float *)(param_1 + 0x24) <= *(float *)(param_1 + 0x2c)) {
      FUN_0047c9e0(&DAT_00779800);
    }
    else if (DAT_006fc5f0 != 0) {
      FUN_0047c580(&DAT_00779800,param_2);
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar5 = *(int *)(DAT_007361bc + 0x27c);
      if (((iVar5 != 0) && (*(int *)(iVar5 + 0xc) == 0x16)) &&
         (((DAT_00735f54 == 0 && (*(float *)(param_1 + 0x28) <= *(float *)(param_1 + 0x2c))) ||
          (*(int *)(iVar5 + 0x2c) == 0)))) {
        *(undefined4 *)(param_1 + 0x20) = 0;
      }
      if ((*(int *)(param_1 + 0x20) == 0) && (iVar5 = 0, 0 < DAT_007361c4)) {
        do {
          iVar4 = *(int *)(DAT_007361f0 + 0x3c);
          iVar2 = (&DAT_007361bc)[iVar5];
          if (((iVar4 == 0) || ((*(int *)(iVar4 + 0x20) == 0 || (*(int *)(iVar4 + 0x1c) == 0)))) &&
             ((*(int *)(DAT_007361f0 + 0x40) == 0 ||
              (*(int *)(*(int *)(DAT_007361f0 + 0x40) + 0x1c) == 0)))) {
            Player__ChangeCameraMover(iVar2,(-(DAT_00700aa4 != 0) & 0x10U) + 1,0);
            piVar3 = *(int **)(iVar2 + 0x27c);
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 0x34))();
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_007361c4);
      }
    }
  }
  else if ((DAT_006ffdbc * *(float *)(param_1 + 0x2c) != _DAT_00735f58) &&
          (*(float *)(param_1 + 0x2c) = _DAT_00735f58 / DAT_006ffdbc, 0 < iVar5)) {
    do {
      if ((*(int *)((&DAT_007361bc)[iVar4] + 0x27c) != 0) &&
         (*(int *)(*(int *)((&DAT_007361bc)[iVar4] + 0x27c) + 0xc) == 0x16)) {
        uVar1 = *(undefined4 *)(param_1 + 0x2c);
        FUN_0048e760();
        FUN_0048e7b0(uVar1,0);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_007361c4);
    return;
  }
  return;
}


// ==== 0x47f680 FUN_0047f680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0047f680(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00687428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = param_2;
  *param_1 = &PTR_FUN_006c8118;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  puVar1 = param_1 + 1;
  *DAT_00779700 = puVar1;
  puVar4 = puVar1;
  param_1[2] = DAT_00779700;
  DAT_00779700 = puVar4;
  *puVar1 = &DAT_007796fc;
  *param_1 = &PTR_FUN_006c8120;
  param_1[7] = 0;
  param_1[8] = 0x40800000;
  param_1[9] = 0x41000000;
  param_1[10] = 0;
  local_8 = 0;
  if (DAT_007301d4 != 0) {
    bMemoryPool_TotalAllocated();
  }
  if (DAT_00779810 == 0) {
    iVar5 = 0;
  }
  else {
    FUN_0047cb50(&DAT_00779800);
    FUN_0047c160(&DAT_00779800);
    iVar5 = FUN_0047c020(&DAT_00779800);
    FUN_0047c310(&DAT_00779800);
  }
  iVar7 = 0;
  param_1[7] = iVar5;
  param_1[7] = (uint)(iVar5 != 0);
  if (DAT_00779810 == 0) {
    param_1[7] = 0;
  }
  else {
    fVar3 = _K_ONE / DAT_006ffdbc;
    param_1[9] = (float)*(int *)(DAT_00779810 + 0x74) * fVar3;
    param_1[8] = (float)*(int *)(DAT_00779810 + 0x78) * fVar3;
  }
  if (param_1[7] != 0) {
    if (0 < DAT_007361c4) {
      do {
        if (iVar7 == 0) {
          uVar8 = 0x16;
        }
        else {
          uVar8 = 0;
        }
        Player__ChangeCameraMover((&DAT_007361bc)[iVar7],uVar8,0);
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_007361c4);
    }
    if (*(int *)(DAT_007361f8 + 0x2f0) != 0) {
      Teleporter_Disable();
    }
    if (DAT_0078a2fc == 0) {
      pcVar6 = "ForwardStartingPosition";
      do {
        pcVar2 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar2 != '\0');
    }
    else {
      pcVar6 = "BackwardStartingPosition";
      do {
        pcVar2 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar2 != '\0');
    }
    WorldObjectCohort__Launch(DAT_00779818,0);
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x47f810 FUN_0047f810

void * __thiscall FUN_0047f810(void *param_1,byte param_2)

{
  FUN_0047f830(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x47f830 FUN_0047f830

void FUN_0047f830(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00687428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_006c8120;
  local_8 = 0;
  if (*(int *)(DAT_007361f8 + 0x2f0) != 0) {
    Teleporter_Enable();
  }
  FUN_00578b10(DAT_00779818);
  FUN_0047bfc0();
  local_8 = 0xffffffff;
  *param_1 = &PTR_FUN_006c8118;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  iVar1 = param_1[1];
  piVar2 = (int *)param_1[2];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  ExceptionList = local_10;
  return;
}


// ==== 0x47f8c0 FUN_0047f8c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0047f8c0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_007361c4;
  if ((*(int *)(param_1 + 0x1c) == 0) || (DAT_00735f54 == 0)) {
    *(float *)(param_1 + 0x28) = DAT_0073457c + *(float *)(param_1 + 0x28);
    if ((*(int *)(param_1 + 0x1c) != 0) && (iVar3 = 0, 0 < DAT_007361c4)) {
      do {
        iVar2 = *(int *)((&DAT_007361bc)[iVar3] + 0x27c);
        if (((iVar2 != 0) && (*(int *)(iVar2 + 0xc) == 0x16)) && (*(int *)(iVar2 + 0x2c) == 0)) {
          FUN_0048e760();
          FUN_0048e7b0(*(undefined4 *)(param_1 + 0x20),1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_007361c4);
    }
    if (DAT_006fc5f0 != 0) {
      FUN_0047c580(&DAT_00779800,param_2);
    }
  }
  else if (DAT_006ffdbc * *(float *)(param_1 + 0x28) != _DAT_00735f58) {
    iVar2 = 0;
    *(float *)(param_1 + 0x28) = _DAT_00735f58 / DAT_006ffdbc;
    if (0 < iVar3) {
      do {
        if ((*(int *)((&DAT_007361bc)[iVar2] + 0x27c) != 0) &&
           (*(int *)(*(int *)((&DAT_007361bc)[iVar2] + 0x27c) + 0xc) == 0x16)) {
          uVar1 = *(undefined4 *)(param_1 + 0x28);
          FUN_0048e760();
          FUN_0048e7b0(uVar1,0);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_007361c4);
      return;
    }
  }
  return;
}


// ==== 0x47f9e0 CameraDataItems::CameraDataItems

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall CameraDataItems__CameraDataItems(int *param_1)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *in_EAX = iVar2;
  in_EAX[1] = (int)(param_1 + 1);
  piVar1 = param_1 + 9;
  if (iVar2 == 0) {
    in_EAX[0x19] = *piVar1;
    in_EAX[0x1a] = param_1[10];
    in_EAX[0x1b] = param_1[0xb];
    in_EAX[0x1c] = param_1[0xc];
    in_EAX[0x1d] = param_1[0xd];
    in_EAX[0x1e] = param_1[0xe];
    in_EAX[0x1f] = param_1[0xf];
    in_EAX[0x20] = param_1[0x10];
    in_EAX[0x21] = param_1[0x11];
    in_EAX[0x22] = param_1[0x12];
    in_EAX[0x23] = param_1[0x13];
    in_EAX[0x24] = param_1[0x14];
    in_EAX[0x25] = param_1[0x15];
    in_EAX[5] = param_1[0x16];
    in_EAX[8] = param_1[0x17];
    in_EAX[10] = param_1[0x18];
    in_EAX[0xb] = param_1[0x19];
    in_EAX[2] = param_1[0x1a];
    in_EAX[3] = param_1[0x1b];
    in_EAX[4] = param_1[0x1c];
    in_EAX[0x10] = param_1[0x1d];
    in_EAX[0x12] = param_1[0x1e];
    in_EAX[0x14] = param_1[0x1f];
    in_EAX[0x26] = param_1[0x20];
    in_EAX[0x27] = param_1[0x21];
    in_EAX[0xc] = param_1[0x22];
    in_EAX[0xd] = param_1[0x23];
    in_EAX[0xe] = param_1[0x24];
    in_EAX[0x28] = param_1[0x25];
    in_EAX[0xf] = (int)(param_1 + 0x28);
    param_1 = param_1 + 0xa8;
    in_EAX[0x15] = (int)param_1;
    param_1 = param_1 + in_EAX[0x14] * 4;
    in_EAX[0x16] = (int)param_1;
    in_EAX[0x11] = (int)(param_1 + in_EAX[0x14] * 4 + in_EAX[0x12] * 4);
    in_EAX[6] = 0;
    in_EAX[0x17] = 0;
    in_EAX[9] = 0;
    in_EAX[0x18] = 0;
    in_EAX[0x13] = (int)(param_1 + in_EAX[0x14] * 4);
    return;
  }
  if (iVar2 == 1) {
    in_EAX[5] = *piVar1;
    in_EAX[6] = param_1[10];
    in_EAX[8] = param_1[0xb];
    in_EAX[9] = param_1[0xc];
    in_EAX[10] = param_1[0xd];
    in_EAX[0xb] = param_1[0xe];
    in_EAX[2] = param_1[0xf];
    in_EAX[3] = param_1[0x10];
    in_EAX[4] = param_1[0x11];
    in_EAX[0x10] = param_1[0x12];
    in_EAX[0x12] = param_1[0x13];
    in_EAX[0x14] = param_1[0x14];
    in_EAX[0x17] = param_1[0x15];
    in_EAX[0xc] = param_1[0x16];
    in_EAX[0xd] = param_1[0x17];
    iVar2 = param_1[0x18];
  }
  else {
    if (iVar2 != 2) {
      return;
    }
    in_EAX[5] = *piVar1;
    in_EAX[6] = param_1[10];
    in_EAX[7] = param_1[0xb];
    in_EAX[8] = param_1[0xc];
    in_EAX[9] = param_1[0xd];
    in_EAX[10] = param_1[0xe];
    in_EAX[0xb] = param_1[0xf];
    in_EAX[2] = param_1[0x10];
    in_EAX[3] = param_1[0x11];
    in_EAX[4] = param_1[0x12];
    in_EAX[0x10] = param_1[0x13];
    in_EAX[0x12] = param_1[0x14];
    in_EAX[0x14] = param_1[0x15];
    in_EAX[0x17] = param_1[0x16];
    in_EAX[0xc] = param_1[0x17];
    in_EAX[0xd] = param_1[0x18];
    iVar2 = param_1[0x19];
  }
  in_EAX[0x28] = 0;
  in_EAX[0x1d] = 0;
  in_EAX[0x1c] = 0;
  in_EAX[0x1b] = 0;
  in_EAX[0x1a] = 0;
  in_EAX[0x19] = 0;
  in_EAX[0xf] = (int)(param_1 + 0x1c);
  param_1 = param_1 + 0x9c;
  in_EAX[0x15] = (int)param_1;
  param_1 = param_1 + in_EAX[0x14] * 4;
  in_EAX[0x16] = (int)param_1;
  param_1 = param_1 + in_EAX[0x14] * 4;
  in_EAX[0x18] = (int)param_1;
  in_EAX[0xe] = iVar2;
  in_EAX[0x11] = (int)(param_1 + in_EAX[0x17] * 4 + in_EAX[0x12] * 4);
  in_EAX[0x13] = (int)(param_1 + in_EAX[0x17] * 4);
  return;
}


// ==== 0x47fca0 FUN_0047fca0

void FUN_0047fca0(void)

{
  DragCameraManager__AddUndo(&stack0x00000008,4);
  return;
}


// ==== 0x47fcc0 DragCameraData::LoadFromVersion

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall DragCameraData__LoadFromVersion(uint *param_1,uint *param_2)

{
  undefined4 in_EAX;
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  uint *puVar6;
  int local_4;
  
  switch(in_EAX) {
  case 0:
    *(char *)param_2 = (char)*param_1;
    param_2[2] = param_1[1];
    puVar6 = param_1 + 0xe;
    param_1 = param_1 + 8;
    puVar5 = param_2 + 0x11;
    puVar2 = param_2 + 9;
    iVar3 = 2;
    do {
      puVar5[-2] = *puVar6;
      *puVar5 = 0x3f000000;
      puVar2[-6] = param_1[-6];
      *puVar2 = *param_1;
      puVar2[-5] = param_1[-5];
      puVar2[1] = param_1[1];
      puVar2[-4] = param_1[-4];
      puVar2[2] = param_1[2];
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      param_1 = param_1 + 3;
      puVar2 = puVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined1 *)((int)param_2 + 1) = 0;
    *(undefined1 *)(param_2 + 1) = 1;
    *(undefined1 *)((int)param_2 + 5) = 1;
    *(undefined1 *)((int)param_2 + 6) = 0;
    *(undefined1 *)((int)param_2 + 7) = 0;
    *(undefined1 *)((int)param_2 + 2) = 1;
    *(undefined1 *)((int)param_2 + 3) = 1;
    return;
  case 1:
    *(char *)param_2 = (char)*param_1;
    param_2[2] = param_1[1];
    puVar6 = param_2 + 0x11;
    puVar5 = param_1 + 0xe;
    puVar2 = param_2 + 9;
    puVar1 = param_1 + 8;
    local_4 = 2;
    do {
      puVar6[-2] = *puVar5;
      *puVar6 = 0x3f000000;
      puVar2[-6] = puVar1[-6];
      *puVar2 = *puVar1;
      puVar2[-5] = puVar1[-5];
      puVar2[1] = puVar1[1];
      puVar2[-4] = puVar1[-4];
      puVar2[2] = puVar1[2];
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      puVar1 = puVar1 + 3;
      puVar2 = puVar2 + 3;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    *(byte *)((int)param_2 + 1) = (byte)(*param_1 >> 10) & 1;
    bVar4 = (byte)(*param_1 >> 8) & 1;
    *(byte *)(param_2 + 1) = bVar4;
    *(byte *)((int)param_2 + 5) = (byte)(*param_1 >> 9) & 1;
    *(undefined1 *)((int)param_2 + 6) = 0;
    *(undefined1 *)((int)param_2 + 7) = 0;
    *(byte *)((int)param_2 + 2) = bVar4;
    *(undefined1 *)((int)param_2 + 3) = *(undefined1 *)((int)param_2 + 5);
    return;
  case 2:
    *(char *)param_2 = (char)*param_1;
    param_2[2] = param_1[1];
    puVar6 = param_2 + 0x11;
    puVar5 = param_1 + 0xe;
    puVar2 = param_2 + 9;
    puVar1 = param_1 + 8;
    local_4 = 2;
    do {
      puVar6[-2] = *puVar5;
      *puVar6 = 0x3f000000;
      puVar2[-6] = puVar1[-6];
      *puVar2 = *puVar1;
      puVar2[-5] = puVar1[-5];
      puVar2[1] = puVar1[1];
      puVar2[-4] = puVar1[-4];
      puVar2[2] = puVar1[2];
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      puVar1 = puVar1 + 3;
      puVar2 = puVar2 + 3;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    break;
  case 3:
    *(char *)param_2 = (char)*param_1;
    param_2[2] = param_1[1];
    puVar6 = param_2 + 0x11;
    puVar5 = param_1 + 0xe;
    puVar2 = param_2 + 9;
    puVar1 = param_1 + 8;
    local_4 = 2;
    do {
      puVar6[-2] = *puVar5;
      *puVar6 = 0x3f000000;
      puVar2[-6] = puVar1[-6];
      *puVar2 = *puVar1;
      puVar2[-5] = puVar1[-5];
      puVar2[1] = puVar1[1];
      puVar2[-4] = puVar1[-4];
      puVar2[2] = puVar1[2];
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      puVar1 = puVar1 + 3;
      puVar2 = puVar2 + 3;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    break;
  case 4:
    for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  default:
    return;
  }
  *(byte *)((int)param_2 + 1) = (byte)(*param_1 >> 8) & 1;
  *(byte *)(param_2 + 1) = (byte)(*param_1 >> 9) & 1;
  *(byte *)((int)param_2 + 5) = (byte)(*param_1 >> 10) & 1;
  *(byte *)((int)param_2 + 6) = (byte)(*param_1 >> 0xb) & 1;
  *(byte *)((int)param_2 + 7) = (byte)(*param_1 >> 0xc) & 1;
  *(char *)((int)param_2 + 2) = (char)param_2[1];
  *(undefined1 *)((int)param_2 + 3) = *(undefined1 *)((int)param_2 + 5);
  return;
}


// ==== 0x47ff30 DragCameraManager::DragCameraManager

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void DragCameraManager__DragCameraManager(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xcb0) = 0;
  *(undefined4 *)(in_EAX + 0xcb4) = 0;
  *(undefined4 *)(in_EAX + 0xcc0) = 0;
  *(undefined4 *)(in_EAX + 0xcc4) = 0;
  *(undefined4 *)(in_EAX + 0xcc8) = 0;
  *(undefined4 *)(in_EAX + 0xccc) = 0;
  *(undefined4 *)(in_EAX + 0xcd0) = 0;
  *(undefined2 *)(in_EAX + 0xcd4) = 0;
  *(undefined2 *)(in_EAX + 0xcd6) = 0;
  *(undefined4 *)(in_EAX + 0xcd8) = 0;
  *(undefined4 *)(in_EAX + 0xcf0) = 0;
  *(undefined4 *)(in_EAX + 0xcf4) = 0;
  *(undefined4 *)(in_EAX + 0xcf8) = 0;
  *(undefined4 *)(in_EAX + 0xcb8) = 0;
  *(undefined4 *)(in_EAX + 0xcbc) = 0;
  *(undefined4 *)(in_EAX + 0x4c) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x58) = 0;
  *(undefined4 *)(in_EAX + 0x5c) = 0;
  *(undefined4 *)(in_EAX + 0xcfc) = 0;
  *(undefined4 *)(in_EAX + 0xd00) = 0;
  *(undefined4 *)(in_EAX + 0xd04) = 0;
  *(undefined1 *)(in_EAX + 0xd08) = 0;
  *(undefined4 *)(in_EAX + 0xcdc) = 0;
  *(undefined4 *)(in_EAX + 0xce0) = 0;
  *(undefined4 *)(in_EAX + 0xce4) = 0;
  *(undefined4 *)(in_EAX + 0xce8) = 0;
  *(undefined4 *)(in_EAX + 0xcec) = 0;
  return;
}


// ==== 0x47ffe0 FUN_0047ffe0

void __fastcall FUN_0047ffe0(int param_1)

{
  if (*(int *)(param_1 + 0xcb8) < 1) {
    FUN_00481ab0(1);
    DAT_00735f50 = 1;
  }
  return;
}


// ==== 0x47ffff FUN_0047ffff

void __fastcall FUN_0047ffff(int param_1)

{
  if (0 < *(int *)(param_1 + 0xcb8)) {
    FUN_00481ab0(0);
    DAT_00735f50 = 0;
  }
  return;
}


// ==== 0x480000 FUN_00480000

void __fastcall FUN_00480000(int param_1)

{
  if (0 < *(int *)(param_1 + 0xcb8)) {
    FUN_00481ab0(0);
    DAT_00735f50 = 0;
  }
  return;
}


// ==== 0x480020 FUN_00480020

void FUN_00480020(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = DAT_0073619c;
  *(float *)(param_1 + 0xccc) =
       *(float *)(DAT_0073619c + 0x540 + *(char *)(DAT_0073619c + 0x53e) * 4) * 0.01 * DAT_007372b0;
  fVar1 = *(float *)(iVar3 + 0x540 + *(char *)(iVar3 + 0x53f) * 4) * 0.01 * DAT_007372b0;
  *(float *)(param_1 + 0xcd0) = fVar1;
  fVar1 = ABS(fVar1 - *(float *)(param_1 + 0xccc));
  if (fVar1 < 0.001 != (fVar1 == 0.001)) {
    *(undefined4 *)(param_1 + 0xccc) = 0x41c80000;
    *(float *)(param_1 + 0xcd0) = DAT_007372b0 - 100.0;
  }
  if (*(int *)(param_1 + 0xcb0) == 0) {
    *(undefined4 *)(param_1 + 0xcb0) = 3;
    puVar4 = &DAT_006fc4b0;
    puVar5 = (undefined4 *)(param_1 + 0xd0);
    for (iVar3 = 0x39; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(float *)(param_1 + 0x124) = *(float *)(param_1 + 0x124) + *(float *)(param_1 + 0xccc);
    *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0xcd0);
  }
  uVar2 = Texture_FindByHash(0x32283a11,1,0);
  *(undefined4 *)(param_1 + 0xcf0) = uVar2;
  uVar2 = Texture_FindByHash(0x317ec0f4,1,0);
  *(undefined4 *)(param_1 + 0xcf4) = uVar2;
  return;
}


// ==== 0x480120 DragCameraManager::ClearVelocities

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void DragCameraManager__ClearVelocities(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xcdc) = 0;
  *(undefined4 *)(in_EAX + 0xce0) = 0;
  *(undefined4 *)(in_EAX + 0xce4) = 0;
  *(undefined4 *)(in_EAX + 0xce8) = 0;
  *(undefined4 *)(in_EAX + 0xcec) = 0;
  return;
}


// ==== 0x480150 DragCameraManager::GetDragIndex

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

int DragCameraManager__GetDragIndex(float param_1)

{
  int in_EAX;
  int iVar1;
  float *pfVar2;
  
  iVar1 = *(int *)(in_EAX + 0xcb0) + -1;
  if (0 < iVar1) {
    pfVar2 = (float *)(iVar1 * 0x4c + 0xd8 + in_EAX);
    do {
      if (*pfVar2 < param_1 != (*pfVar2 == param_1)) {
        return iVar1;
      }
      iVar1 = iVar1 + -1;
      pfVar2 = pfVar2 + -0x13;
    } while (0 < iVar1);
  }
  return iVar1;
}


// ==== 0x480190 DragCameraManager::GetDistance

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

float10 DragCameraManager__GetDistance(void)

{
  uint uVar1;
  uint in_EAX;
  uint uVar2;
  uint uVar3;
  int unaff_ESI;
  
  uVar1 = *(uint *)(unaff_ESI + 0xcb0);
  uVar2 = in_EAX & ((int)in_EAX < 1) - 1;
  uVar3 = uVar2;
  if ((int)uVar2 > (int)uVar1) {
    uVar3 = uVar1;
  }
  if (SBORROW4(uVar3,uVar1) != ((int)uVar2 <= (int)uVar1 && (int)(uVar2 - uVar1) < 0)) {
    return (float10)*(float *)(uVar3 * 0x4c + 0xd8 + unaff_ESI);
  }
  return (float10)DAT_007372b0;
}


// ==== 0x4801c0 FUN_004801c0

float10 FUN_004801c0(void)

{
  uint uVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_EDI + 0xcb0);
  uVar3 = unaff_ESI + 1 & ((int)(unaff_ESI + 1) < 1) - 1;
  uVar4 = uVar3;
  if ((int)uVar3 > (int)uVar1) {
    uVar4 = uVar1;
  }
  fVar2 = DAT_007372b0;
  if (SBORROW4(uVar4,uVar1) != ((int)uVar3 <= (int)uVar1 && (int)(uVar3 - uVar1) < 0)) {
    fVar2 = *(float *)(uVar4 * 0x4c + 0xd8 + unaff_EDI);
  }
  uVar3 = ((int)unaff_ESI < 1) - 1 & unaff_ESI;
  uVar4 = uVar3;
  if ((int)uVar3 > (int)uVar1) {
    uVar4 = uVar1;
  }
  if (SBORROW4(uVar4,uVar1) == ((int)uVar3 <= (int)uVar1 && (int)(uVar3 - uVar1) < 0)) {
    return (float10)fVar2 - (float10)DAT_007372b0;
  }
  return (float10)fVar2 - (float10)*(float *)(uVar4 * 0x4c + 0xd8 + unaff_EDI);
}


// ==== 0x480230 KeyframeTrack_FindSegment

/* [canon] camera med (ghidra-canon+hopper) docs/re/runtime.md */

int KeyframeTrack_FindSegment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float *pfVar7;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xcb8) < 1) {
    fVar1 = *(float *)(param_1 + 0x814);
  }
  else {
    fVar1 = *(float *)(unaff_EDI + 0xcc0);
  }
  uVar2 = *(uint *)(unaff_EDI + 0xcb0);
  uVar6 = uVar2 - 1;
  if (0 < (int)uVar6) {
    pfVar7 = (float *)(uVar6 * 0x4c + 0xd8 + unaff_EDI);
    do {
      if (*pfVar7 <= fVar1) break;
      uVar6 = uVar6 - 1;
      pfVar7 = pfVar7 + -0x13;
    } while (0 < (int)uVar6);
  }
  if (param_2 != (undefined4 *)0x0) {
    uVar4 = ((int)uVar6 < 1) - 1 & uVar6;
    uVar5 = uVar4;
    if ((int)uVar4 > (int)uVar2) {
      uVar5 = uVar2;
    }
    uVar3 = DAT_007372b0;
    if (SBORROW4(uVar5,uVar2) != ((int)uVar4 <= (int)uVar2 && (int)(uVar4 - uVar2) < 0)) {
      uVar3 = *(undefined4 *)(uVar5 * 0x4c + 0xd8 + unaff_EDI);
    }
    *param_2 = uVar3;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar2 = *(uint *)(unaff_EDI + 0xcb0);
    uVar4 = uVar6 + 1 & ((int)(uVar6 + 1) < 1) - 1;
    uVar5 = uVar4;
    if ((int)uVar4 > (int)uVar2) {
      uVar5 = uVar2;
    }
    if (SBORROW4(uVar5,uVar2) != ((int)uVar4 <= (int)uVar2 && (int)(uVar4 - uVar2) < 0)) {
      *param_3 = *(undefined4 *)(uVar5 * 0x4c + 0xd8 + unaff_EDI);
      return uVar6 * 0x4c + 0xd0 + unaff_EDI;
    }
    *param_3 = DAT_007372b0;
  }
  return uVar6 * 0x4c + 0xd0 + unaff_EDI;
}


// ==== 0x480310 FUN_00480310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00480310(int param_1,float *param_2,float *param_3,float *param_4,char *param_5,int param_6
                 )

{
  int iVar1;
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
  char cVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  float10 fVar30;
  float10 fVar31;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  
  fVar30 = (float10)0.0;
  local_80 = 0.0;
  local_7c = 0.0;
  local_78 = 0.0;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  if (*param_5 == '\x14') {
    uVar28 = (uint)(param_6 != 0) * 2 + -1 + (int)(param_5 + (-0xd0 - param_1)) / 0x4c;
    uVar27 = *(int *)(param_1 + 0xcb0) - 1;
    uVar29 = ((int)uVar28 < 1) - 1 & uVar28;
    if ((int)uVar29 <= (int)uVar27) {
      uVar27 = uVar29;
    }
    if (uVar28 == uVar27) {
      iVar1 = uVar28 * 0x4c + 0xd0 + param_1;
      if (*(char *)(uVar28 * 0x4c + 0xd0 + param_1) == '\x14') {
        cVar26 = FUN_00481790(param_1,param_5,iVar1);
        if (cVar26 == '\0') {
          fVar30 = (float10)(float)fVar30;
        }
        else {
          fVar10 = *(float *)(iVar1 + 0x10);
          fVar2 = *(float *)(iVar1 + 0xc);
          fVar3 = *(float *)(iVar1 + 0x18);
          fVar11 = *(float *)(iVar1 + 0x14);
          fVar12 = *(float *)(iVar1 + 0x1c);
          fVar13 = *(float *)(iVar1 + 0x20);
          fVar14 = *(float *)(iVar1 + 0x28);
          fVar15 = *(float *)(iVar1 + 0x34);
          fVar16 = *(float *)(param_5 + 0x10);
          fVar17 = *(float *)(iVar1 + 0x2c);
          fVar4 = *(float *)(iVar1 + 0x24);
          fVar18 = *(float *)(iVar1 + 0x38);
          fVar5 = *(float *)(iVar1 + 0x30);
          fVar19 = *(float *)(param_5 + 0x14);
          fVar20 = *(float *)(param_5 + 0x20);
          fVar21 = *(float *)(param_5 + 0x2c);
          fVar22 = *(float *)(param_5 + 0x1c);
          fVar6 = *(float *)(param_5 + 0xc);
          fVar23 = *(float *)(param_5 + 0x28);
          fVar7 = *(float *)(param_5 + 0x18);
          fVar24 = *(float *)(param_5 + 0x38);
          fVar25 = *(float *)(param_5 + 0x34);
          fVar8 = *(float *)(param_5 + 0x24);
          fVar9 = *(float *)(param_5 + 0x30);
          fVar30 = (float10)FUN_004801c0();
          fVar31 = (float10)FUN_004801c0();
          fVar30 = (float10)(float)fVar30 / (fVar31 + (float10)(float)fVar30);
          fVar31 = (float10)_K_ONE - fVar30;
          local_80 = (float)((float10)(fVar7 - fVar6) * fVar31 + (float10)(fVar3 - fVar2) * fVar30);
          local_7c = (float)((float10)(fVar22 - fVar16) * fVar31 +
                            (float10)(fVar12 - fVar10) * fVar30);
          local_78 = (float)((float10)(fVar20 - fVar19) * fVar31 +
                            (float10)(float)((float10)(fVar13 - fVar11) * fVar30));
          local_70 = (float)((float10)(fVar9 - fVar8) * fVar31 + (float10)(fVar5 - fVar4) * fVar30);
          local_6c = (float)((float10)(fVar25 - fVar23) * fVar31 +
                            (float10)(fVar15 - fVar14) * fVar30);
          local_68 = (float)((float10)(fVar24 - fVar21) * fVar31 +
                            (float10)(float)((float10)(fVar18 - fVar17) * fVar30));
          fVar30 = ((float10)*(float *)(param_5 + 0x40) - (float10)*(float *)(param_5 + 0x3c)) *
                   fVar31 + ((float10)*(float *)(iVar1 + 0x40) - (float10)*(float *)(iVar1 + 0x3c))
                            * fVar30;
        }
      }
    }
  }
  *param_2 = local_80;
  param_2[1] = local_7c;
  param_2[2] = local_78;
  *param_3 = local_70;
  param_3[1] = local_6c;
  param_3[2] = local_68;
  *param_4 = (float)fVar30;
  return;
}


// ==== 0x480660 FUN_00480660

void FUN_00480660(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar3 = param_2;
  if (2 < *(int *)(param_1 + 0xcb0)) {
    iVar2 = *(int *)(param_1 + 0xcb0) + -2;
    iVar1 = param_2;
    if (param_2 < 2) {
      iVar1 = 1;
    }
    if (iVar2 < iVar1) {
      iVar1 = iVar2;
    }
    if (param_2 == iVar1) {
      bVar5 = (byte)param_2;
      param_2 = CONCAT22(0x50,(ushort)bVar5 << 8);
      DragCameraManager__AddUndo(&param_2,4);
      iVar2 = iVar3 * 0x4c + param_1;
      puVar7 = (undefined4 *)(iVar2 + 0xd0);
      DragCameraManager__AddUndo(puVar7,0x4c);
      iVar3 = (*(int *)(param_1 + 0xcb0) - iVar3) + -1;
      if (iVar3 != 0) {
        puVar6 = (undefined4 *)(iVar2 + 0x11c);
        for (uVar4 = (uint)(iVar3 * 0x4c) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
      }
      iVar3 = *(int *)(param_1 + 0xcb0);
      *(int *)(param_1 + 0xcb0) = iVar3 + -1;
      iVar2 = DragCameraManager__GetDragIndex(*(undefined4 *)(param_1 + 0xcc0));
      *(int *)(param_1 + 0xcb4) = iVar2;
      if ((iVar2 == 0) && (*(int *)(param_1 + 0xcb8) == 3)) {
        *(undefined4 *)(param_1 + 0xcb8) = 1;
      }
      if ((iVar2 == iVar3 + -2) && (*(int *)(param_1 + 0xcb8) == 4)) {
        *(undefined4 *)(param_1 + 0xcb8) = 1;
      }
    }
  }
  return;
}


// ==== 0x480750 FUN_00480750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00480750(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  short sVar4;
  float fVar5;
  bool bVar6;
  float fVar7;
  int iVar8;
  short *psVar9;
  short *extraout_EDX;
  int unaff_ESI;
  float10 fVar10;
  float10 fVar11;
  
  iVar8 = param_2 * 0x4c;
  *(bool *)(unaff_ESI + 0x60) = *(char *)(iVar8 + 0xd4 + unaff_ESI) != '\0';
  *(bool *)(unaff_ESI + 0x61) = *(char *)(iVar8 + 0xd5 + unaff_ESI) != '\0';
  iVar1 = param_2 * 0x13 + param_1;
  *(undefined4 *)(unaff_ESI + 0x7c) = *(undefined4 *)(unaff_ESI + 0x114 + iVar1 * 4);
  *(undefined4 *)(unaff_ESI + 0x80) = *(undefined4 *)(unaff_ESI + 0x10c + iVar1 * 4);
  iVar1 = param_1 * 0xc + iVar8;
  *(undefined4 *)(unaff_ESI + 100) = *(undefined4 *)(iVar1 + 0xdc + unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x68) = *(undefined4 *)(iVar1 + 0xe0 + unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x6c) =
       *(undefined4 *)((param_2 + 3) * 0x4c + param_1 * 0xc + unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x70) = *(undefined4 *)(iVar1 + unaff_ESI + 0xf4);
  *(undefined4 *)(unaff_ESI + 0x74) = *(undefined4 *)(iVar1 + unaff_ESI + 0xf8);
  *(undefined4 *)(unaff_ESI + 0x78) = *(undefined4 *)(iVar8 + (param_1 * 3 + 0x3f) * 4 + unaff_ESI);
  if ((*(char *)(iVar8 + 0xd0 + unaff_ESI) == '\0') &&
     ((psVar9 = (short *)FindCameraRow(), psVar9 != (short *)0x0 ||
      (psVar9 = (short *)FindCameraRow(), psVar9 != (short *)0x0)))) {
    *(undefined1 *)(unaff_ESI + 0x60) = 1;
    *(undefined1 *)(unaff_ESI + 0x61) = 1;
    uVar2 = _K_HALF;
    if (*psVar9 == 3) {
      uVar2 = DAT_006fbf1c;
    }
    *(undefined4 *)(unaff_ESI + 0x7c) = uVar2;
    fVar10 = (float10)FUN_00564b10();
    fVar11 = (float10)FUN_00564b10();
    *(float *)(unaff_ESI + 0x80) =
         (float)(((float10)CamWallPushOut / ((float10)(float)fVar10 / fVar11)) * (float10)12.0);
    fVar10 = (float10)FUN_00564b10();
    fVar11 = (float10)FUN_00564b10();
    sVar4 = *extraout_EDX;
    if (((sVar4 == 1) || (sVar4 == 0)) || (sVar4 == 4)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
    uVar2 = *(undefined4 *)(extraout_EDX + 6);
    fVar5 = *(float *)(extraout_EDX + 2);
    fVar3 = *(float *)(extraout_EDX + 4);
    if (bVar6) {
      fVar10 = ((float10)(float)fVar10 / fVar11) * (float10)fVar5 + (float10)fVar3;
      fVar7 = 0.0;
    }
    else {
      fVar10 = (float10)fVar3 - (float10)(float)fVar10 / fVar11;
      fVar7 = fVar5 + _K_ONE;
    }
    *(float *)(unaff_ESI + 0x70) = fVar7;
    *(float *)(unaff_ESI + 0x78) = (float)fVar10;
    *(float *)(unaff_ESI + 100) = fVar5;
    *(undefined4 *)(unaff_ESI + 0x68) = uVar2;
    *(float *)(unaff_ESI + 0x6c) = fVar3;
    *(undefined4 *)(unaff_ESI + 0x74) = 0;
  }
  return;
}


// ==== 0x480930 FUN_00480930

void FUN_00480930(int param_1,int param_2)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  iVar2 = param_1 * 0x4c;
  bVar3 = *(char *)(iVar2 + 0xd4 + unaff_ESI) != *(char *)(unaff_ESI + 0x60);
  if (bVar3) {
    FUN_004812b0(unaff_ESI,param_1,1);
  }
  bVar4 = *(char *)(iVar2 + 0xd5 + unaff_ESI) != *(char *)(unaff_ESI + 0x61);
  if (bVar4) {
    FUN_004812b0(unaff_ESI,param_1,0);
  }
  iVar1 = param_1 * 0x13 + param_2;
  *(undefined4 *)(unaff_ESI + 0x10c + iVar1 * 4) = *(undefined4 *)(unaff_ESI + 0x80);
  *(undefined4 *)(unaff_ESI + 0x114 + iVar1 * 4) = *(undefined4 *)(unaff_ESI + 0x7c);
  iVar1 = param_2 * 0xc + iVar2;
  *(undefined4 *)(iVar1 + 0xdc + unaff_ESI) = *(undefined4 *)(unaff_ESI + 100);
  iVar1 = iVar1 + unaff_ESI;
  *(undefined4 *)(iVar1 + 0xe0) = *(undefined4 *)(unaff_ESI + 0x68);
  *(undefined4 *)((param_1 + 3) * 0x4c + param_2 * 0xc + unaff_ESI) =
       *(undefined4 *)(unaff_ESI + 0x6c);
  *(undefined4 *)(iVar1 + 0xf4) = *(undefined4 *)(unaff_ESI + 0x70);
  *(undefined4 *)(iVar1 + 0xf8) = *(undefined4 *)(unaff_ESI + 0x74);
  *(undefined4 *)(iVar2 + (param_2 * 3 + 0x3f) * 4 + unaff_ESI) = *(undefined4 *)(unaff_ESI + 0x78);
  if (bVar3) {
    FUN_004812b0(unaff_ESI,param_1,1);
  }
  if (bVar4) {
    FUN_004812b0(unaff_ESI,param_1,0);
  }
  return;
}


// ==== 0x480a20 DragCameraManager::Paste

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall DragCameraManager__Paste(int param_1)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = *(undefined4 *)(in_EAX * 0x4c + 0xd8 + param_1);
  iVar2 = in_EAX * 0x4c + param_1;
  puVar4 = (undefined4 *)(param_1 + 0x84);
  puVar5 = (undefined4 *)(iVar2 + 0xd0);
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(iVar2 + 0xd8) = uVar1;
  return;
}


// ==== 0x480a50 FUN_00480a50

void __fastcall FUN_00480a50(undefined4 param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char cStack00000009;
  undefined2 uStack0000000a;
  
  if (*(int *)(param_3 + 0xcb0) < 0x28) {
    iVar1 = *(int *)(param_3 + 0xcb0) - param_2;
    iVar2 = iVar1 + -1;
    if ((iVar1 != 1) && (iVar1 = 0, 0 < iVar2)) {
      do {
        iVar3 = (*(int *)(param_3 + 0xcb0) - iVar1) * 0x4c + param_3;
        iVar1 = iVar1 + 1;
        puVar6 = (undefined4 *)(iVar3 + 0x84);
        puVar7 = (undefined4 *)(iVar3 + 0xd0);
        for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
      } while (iVar1 < iVar2);
    }
    iVar1 = param_2 * 0x4c + param_3;
    puVar6 = (undefined4 *)(iVar1 + 0xd0);
    puVar7 = (undefined4 *)(iVar1 + 0x11c);
    for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 *)(iVar1 + 0x124) = *(undefined4 *)(param_3 + 0xcc0);
    *(int *)(param_3 + 0xcb0) = *(int *)(param_3 + 0xcb0) + 1;
    if (param_4 != '\0') {
      cStack00000009 = (char)param_2 + '\x01';
      param_4 = 1;
      uStack0000000a = 4;
      DragCameraManager__AddUndo(&param_4,4);
    }
    iVar1 = *(int *)(param_3 + 0xcb0) + -1;
    if (0 < iVar1) {
      pfVar5 = (float *)(iVar1 * 0x4c + 0xd8 + param_3);
      do {
        if (*pfVar5 < *(float *)(param_3 + 0xcc0) != (*pfVar5 == *(float *)(param_3 + 0xcc0)))
        break;
        iVar1 = iVar1 + -1;
        pfVar5 = pfVar5 + -0x13;
      } while (0 < iVar1);
    }
    *(int *)(param_3 + 0xcb4) = iVar1;
  }
  return;
}


// ==== 0x480b40 DragCameraManager::EnforceSpacing

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void DragCameraManager__EnforceSpacing(float param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_ESI;
  float *pfVar7;
  
  uVar3 = (uint)param_1;
  uVar2 = *(uint *)(unaff_ESI + 0xcb0);
  if ((int)param_1 < (int)(uVar2 - 1)) {
    pfVar7 = (float *)((int)param_1 * 0x4c + 0x124 + unaff_ESI);
    uVar4 = (uint)param_1;
    do {
      uVar5 = ((int)uVar4 < 1) - 1 & uVar4;
      uVar6 = uVar5;
      if ((int)uVar5 > (int)uVar2) {
        uVar6 = uVar2;
      }
      if (SBORROW4(uVar6,uVar2) == ((int)uVar5 <= (int)uVar2 && (int)(uVar5 - uVar2) < 0)) {
        param_1 = DAT_007372b0;
      }
      else {
        param_1 = *(float *)(uVar6 * 0x4c + 0xd8 + unaff_ESI);
      }
      uVar4 = uVar4 + 1;
      uVar5 = ((int)uVar4 < 1) - 1 & uVar4;
      uVar6 = uVar5;
      if ((int)uVar5 > (int)uVar2) {
        uVar6 = uVar2;
      }
      fVar1 = DAT_007372b0;
      if (SBORROW4(uVar6,uVar2) != ((int)uVar5 <= (int)uVar2 && (int)(uVar5 - uVar2) < 0)) {
        fVar1 = *(float *)(uVar6 * 0x4c + 0xd8 + unaff_ESI);
      }
      if (fVar1 <= param_1 + 10.0) {
        fVar1 = param_1 + 10.0;
      }
      *pfVar7 = fVar1;
      uVar2 = *(uint *)(unaff_ESI + 0xcb0);
      pfVar7 = pfVar7 + 0x13;
    } while ((int)uVar4 < (int)(uVar2 - 1));
  }
  if (0 < (int)uVar3) {
    pfVar7 = (float *)(unaff_ESI + 0x8c + uVar3 * 0x4c);
    do {
      uVar2 = *(uint *)(unaff_ESI + 0xcb0);
      uVar6 = ((int)uVar3 < 1) - 1 & uVar3;
      uVar4 = uVar6;
      if ((int)uVar6 > (int)uVar2) {
        uVar4 = uVar2;
      }
      if (SBORROW4(uVar4,uVar2) == ((int)uVar6 <= (int)uVar2 && (int)(uVar6 - uVar2) < 0)) {
        param_1 = DAT_007372b0;
      }
      else {
        param_1 = *(float *)(uVar4 * 0x4c + 0xd8 + unaff_ESI);
      }
      uVar3 = uVar3 - 1;
      uVar6 = ((int)uVar3 < 1) - 1 & uVar3;
      uVar4 = uVar6;
      if ((int)uVar6 > (int)uVar2) {
        uVar4 = uVar2;
      }
      fVar1 = DAT_007372b0;
      if (SBORROW4(uVar4,uVar2) != ((int)uVar6 <= (int)uVar2 && (int)(uVar6 - uVar2) < 0)) {
        fVar1 = *(float *)(uVar4 * 0x4c + 0xd8 + unaff_ESI);
      }
      if (param_1 - 10.0 <= fVar1) {
        fVar1 = param_1 - 10.0;
      }
      *pfVar7 = fVar1;
      pfVar7 = pfVar7 + -0x13;
    } while (0 < (int)uVar3);
  }
  return;
}


// ==== 0x480ca0 FUN_00480ca0

void __thiscall FUN_00480ca0(int param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  
  if (param_1 == 0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = (float)(param_1 + -1) * 10.0 + *(float *)(in_EAX + 0xccc) + -25.0;
  }
  fVar3 = (*(float *)(in_EAX + 0xcd0) + 100.0) -
          (float)((*(int *)(in_EAX + 0xcb0) - param_1) + -1) * 10.0;
  pfVar1 = (float *)(param_1 * 0x4c + 0xd8 + in_EAX);
  param_2 = param_2 + *pfVar1;
  if (fVar2 < param_2) {
    fVar2 = param_2;
  }
  if (fVar3 < fVar2) {
    fVar2 = fVar3;
  }
  *pfVar1 = fVar2;
  DragCameraManager__EnforceSpacing(param_1);
  return;
}


// ==== 0x480d40 FUN_00480d40

void __fastcall FUN_00480d40(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *unaff_EDI;
  undefined4 local_64;
  
  iVar3 = param_2 * 0x4c + in_EAX;
  if (*(char *)(param_2 * 0x4c + 0xd4 + in_EAX) != '\0') {
    uVar2 = *(uint *)(in_EAX + 0xcb0);
    uVar4 = param_2 + param_1 & (param_2 + param_1 < 1) - 1;
    uVar5 = uVar4;
    if ((int)uVar4 > (int)uVar2) {
      uVar5 = uVar2;
    }
    if (SBORROW4(uVar5,uVar2) == ((int)uVar4 <= (int)uVar2 && (int)(uVar4 - uVar2) < 0)) {
      local_64 = DAT_007372b0;
    }
    else {
      local_64 = *(undefined4 *)(uVar5 * 0x4c + 0xd8 + in_EAX);
    }
    FUN_00481160(in_EAX,local_64);
    bMatrix4_SetRotationAndTranslation();
    D3DXVec3Transform();
    return;
  }
  iVar1 = iVar3 + 0xd0 + param_1 * 0xc;
  *unaff_EDI = *(undefined4 *)(iVar3 + 0xdc + param_1 * 0xc);
  unaff_EDI[1] = *(undefined4 *)(iVar1 + 0x10);
  unaff_EDI[2] = *(undefined4 *)(iVar1 + 0x14);
  return;
}


// ==== 0x480e20 FUN_00480e20

void __fastcall FUN_00480e20(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_EAX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *unaff_EDI;
  undefined4 local_64;
  
  iVar5 = param_2 * 0x4c + param_1;
  if (*(char *)(param_2 * 0x4c + 0xd5 + param_1) != '\0') {
    uVar2 = *(uint *)(param_1 + 0xcb0);
    uVar3 = in_EAX + param_2 & (in_EAX + param_2 < 1) - 1;
    uVar4 = uVar3;
    if ((int)uVar3 > (int)uVar2) {
      uVar4 = uVar2;
    }
    if (SBORROW4(uVar4,uVar2) == ((int)uVar3 <= (int)uVar2 && (int)(uVar3 - uVar2) < 0)) {
      local_64 = DAT_007372b0;
    }
    else {
      local_64 = *(undefined4 *)(uVar4 * 0x4c + 0xd8 + param_1);
    }
    FUN_00481160(param_1,local_64);
    bMatrix4_SetRotationAndTranslation();
    D3DXVec3Transform();
    return;
  }
  iVar1 = iVar5 + 0xd0 + in_EAX * 0xc;
  *unaff_EDI = *(undefined4 *)(iVar5 + 0xd0 + (in_EAX * 3 + 9) * 4);
  unaff_EDI[1] = *(undefined4 *)(iVar1 + 0x28);
  unaff_EDI[2] = *(undefined4 *)(iVar1 + 0x2c);
  return;
}


// ==== 0x480f10 FUN_00480f10

void FUN_00480f10(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined2 uVar4;
  int unaff_ESI;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  FUN_00480d40();
  FUN_00480e20();
  fVar1 = local_30 - local_20;
  fVar2 = local_2c - local_1c;
  fVar3 = local_28 - local_18;
  uVar4 = Atan2ToAngle16(fVar1,fVar2);
  *(undefined2 *)(unaff_ESI + 0xcd4) = uVar4;
  uVar4 = Atan2ToAngle16(SQRT(fVar2 * fVar2 + fVar1 * fVar1),fVar3);
  *(undefined2 *)(unaff_ESI + 0xcd6) = uVar4;
  *(float *)(unaff_ESI + 0xcd8) = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
  return;
}


// ==== 0x480ff0 FUN_00480ff0

void FUN_00480ff0(int param_1)

{
  int iVar1;
  int local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_9c;
  float local_98;
  undefined1 local_50 [76];
  
  Angle16SinCos();
  Angle16SinCos();
  if ((*(int *)(param_1 + 0xcb8) == 4) || (*(int *)(param_1 + 0xcb8) == 6)) {
    local_d8 = 1;
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
    local_d8 = 0;
  }
  FUN_00480e20();
  local_bc = local_bc * *(float *)(param_1 + 0xcd8);
  local_9c = local_bc * local_b8;
  local_98 = local_d4 * *(float *)(param_1 + 0xcd8);
  local_d0 = local_b0 + local_b4 * local_bc;
  local_cc = local_ac + local_9c;
  local_c8 = local_a8 + local_98;
  if (*(char *)(*(int *)(param_1 + 0xcb4) * 0x4c + 0xd4 + param_1) != '\0') {
    bMatrix4_SetRotationAndTranslation();
    Matrix_InvertRigid();
    D3DXVec3Transform(&local_d0,&local_d0,local_50);
    iVar1 = local_d8;
  }
  iVar1 = iVar1 * 0xc;
  *(float *)(*(int *)(param_1 + 0xcb4) * 0x4c + iVar1 + 0xdc + param_1) = local_d0;
  *(float *)(*(int *)(param_1 + 0xcb4) * 0x4c + iVar1 + 0xe0 + param_1) = local_cc;
  *(float *)((*(int *)(param_1 + 0xcb4) + 3) * 0x4c + iVar1 + param_1) = local_c8;
  return;
}


