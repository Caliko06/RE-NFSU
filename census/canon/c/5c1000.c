// ==== 0x5c1052 FUN_005c1052

undefined4 FUN_005c1052(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  pvVar1 = _malloc(0x14);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d78db(param_2,0,&PTR_DAT_0069fa78);
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005c0e94(param_1,puVar2);
    puVar2[2] = 0;
    (**(code **)*puVar2)(1);
  }
  return uVar3;
}


// ==== 0x5c10a3 FUN_005c10a3

undefined4 __thiscall FUN_005c10a3(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  
  uVar1 = param_2;
  if (param_2 != 0) {
    iVar2 = FUN_005c0e2d(param_3,&param_2);
    if (iVar2 < 0) {
      FUN_005ba1d9(param_1,param_1 + 0x20,0xbf4,
                   "vector dimension must be a literal scalar expression");
    }
    else if ((param_2 == 0) || (4 < param_2)) {
      FUN_005ba1d9(param_1,param_1 + 0x20,0xbec,"vector dimension must be between 1 and %u",4);
    }
    else {
      pvVar3 = _malloc(0x24);
      if (pvVar3 != (void *)0x0) {
        uVar4 = FUN_005d814c(1,*(undefined4 *)(uVar1 + 0x14),1,param_2,0);
        return uVar4;
      }
    }
  }
  return 0;
}


// ==== 0x5c1128 FUN_005c1128

undefined4 __thiscall FUN_005c1128(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  
  uVar1 = param_2;
  if (param_2 != 0) {
    iVar2 = FUN_005c0e2d(param_3,&param_3);
    if ((iVar2 < 0) || (iVar2 = FUN_005c0e2d(param_4,&param_2), iVar2 < 0)) {
      FUN_005ba1d9(param_1,param_1 + 0x20,0xbf5,
                   "matrix dimensions must be literal scalar expressions");
    }
    else if ((param_3 == 0) || (((4 < param_3 || (param_2 == 0)) || (4 < param_2)))) {
      FUN_005ba1d9(param_1,param_1 + 0x20,0xbed,"matrix dimensions must be between 1 and %u",4);
    }
    else {
      pvVar3 = _malloc(0x24);
      if (pvVar3 != (void *)0x0) {
        uVar4 = FUN_005d814c(2,*(undefined4 *)(uVar1 + 0x14),param_3,param_2,0);
        return uVar4;
      }
    }
  }
  return 0;
}


// ==== 0x5c11d0 FUN_005c11d0

int __thiscall FUN_005c11d0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = FUN_005c0e2d(param_3,&param_3);
  if (iVar3 < 0) {
    FUN_005ba1d9(param_1,0,0xbf2,"array dimensions must be literal scalar expressions");
  }
  else {
    pvVar4 = _malloc(0x18);
    if (pvVar4 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005d8062(0,param_3);
    }
    if (iVar3 != 0) {
      piVar1 = &param_2;
      iVar2 = param_2;
      while ((iVar2 != 0 && (*(int *)(*piVar1 + 4) == 7))) {
        piVar1 = (int *)(*piVar1 + 0x10);
        iVar2 = *piVar1;
      }
      *(int *)(iVar3 + 0x10) = *piVar1;
      *piVar1 = iVar3;
      return param_2;
    }
  }
  return 0;
}


// ==== 0x5c1248 FUN_005c1248

undefined4 * __thiscall FUN_005c1248(undefined4 param_1,int *param_2,int param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  char *pcVar8;
  
  iVar5 = param_3;
  if (param_2 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_2[1] != 0xc) {
    return (undefined4 *)0x0;
  }
  if (param_3 == 0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)(param_3 + 4) != 0xc) {
    return (undefined4 *)0x0;
  }
  iVar4 = param_3 + 0x30;
  param_3 = iVar4;
  pvVar1 = _malloc(0x50);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8831(0,0x16,0,0,1,iVar4);
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar4 = param_2[4];
  uVar7 = *(undefined4 *)(iVar5 + 0x10);
  if (iVar4 == 0) {
LAB_005c144a:
    pcVar8 = "array expected";
    uVar7 = 0xbcd;
  }
  else {
    if (*(int *)(iVar4 + 4) == 7) {
      if (*(int **)(iVar4 + 0x10) != (int *)0x0) {
        iVar3 = (**(code **)(**(int **)(iVar4 + 0x10) + 8))();
        puVar2[4] = iVar3;
        if (iVar3 == 0) goto LAB_005c1462;
      }
      piVar6 = *(int **)(iVar4 + 0x14);
    }
    else {
      if (*(int *)(iVar4 + 4) != 8) goto LAB_005c144a;
      if (*(int *)(iVar4 + 0x10) == 1) {
        pvVar1 = _malloc(0x24);
        if (pvVar1 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_005d814c(0,*(undefined4 *)(iVar4 + 0x14),1,1,*(uint *)(iVar4 + 0x20) & 0x200);
        }
        puVar2[4] = iVar3;
        if (iVar3 == 0) goto LAB_005c1462;
        piVar6 = *(int **)(iVar4 + 0x1c);
      }
      else {
        if (*(int *)(iVar4 + 0x10) != 2) goto LAB_005c144a;
        pvVar1 = _malloc(0x24);
        if (pvVar1 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_005d814c(1,*(undefined4 *)(iVar4 + 0x14),1,*(undefined4 *)(iVar4 + 0x1c),
                               *(uint *)(iVar4 + 0x20) & 0x200);
        }
        puVar2[4] = iVar3;
        if (iVar3 == 0) goto LAB_005c1462;
        piVar6 = *(int **)(iVar4 + 0x18);
      }
    }
    iVar4 = FUN_005ba77a(uVar7);
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*param_2 + 8))();
      puVar2[8] = iVar4;
      if (iVar4 != 0) {
        iVar4 = FUN_005bb0d5(iVar5);
        if (iVar4 == 0) {
          iVar5 = FUN_005d7885(iVar5);
          puVar2[9] = iVar5;
          if (iVar5 != 0) {
LAB_005c143d:
            FUN_005bb1eb(puVar2);
            return puVar2;
          }
        }
        else {
          iVar5 = FUN_005c0e2d(iVar5,&param_2);
          if (-1 < iVar5) {
            if (piVar6 <= param_2) {
              FUN_005ba1d9(param_1,param_3,0xbd6,"array index out of bounds");
              param_2 = (int *)0x0;
            }
            iVar5 = FUN_005ba80b(puVar2[4]);
            pvVar1 = _malloc(0x40);
            if (pvVar1 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_005d8a65(2,iVar5 * (int)param_2,param_3);
            }
            puVar2[9] = iVar5;
            if (iVar5 != 0) {
              puVar2[7] = 0x17;
              goto LAB_005c143d;
            }
          }
        }
      }
      goto LAB_005c1462;
    }
    pcVar8 = "scalar expected";
    uVar7 = 0xbeb;
  }
  FUN_005ba1d9(param_1,param_3,uVar7,pcVar8);
LAB_005c1462:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5c1473 FUN_005c1473

undefined4 * __thiscall
FUN_005c1473(int param_1,int param_2,int *param_3,int *param_4,undefined4 param_5)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  piVar1 = param_3;
  local_8 = (int *)0x0;
  local_14 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = (int *)0x0;
  if ((param_3 != (int *)0x0) && (param_3[1] != 0xc)) {
    return (undefined4 *)0x0;
  }
  if (param_4 == (int *)0x0) {
    if (param_3 != (int *)0x0) goto LAB_005c14b0;
    param_3 = (int *)(param_1 + 0x20);
  }
  else {
    param_3 = param_4;
    if (param_4[1] != 0xc) {
      return (undefined4 *)0x0;
    }
LAB_005c14b0:
    param_3 = param_3 + 0xc;
  }
  pvVar2 = _malloc(0x50);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005d8831(0,param_2,0,0,param_5,param_3);
  }
  if (puVar3 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (piVar1 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar1 + 8))();
    puVar3[8] = iVar4;
    if (iVar4 != 0) goto LAB_005c150e;
    goto LAB_005c18b2;
  }
LAB_005c150e:
  iVar4 = 0x15;
  if ((((param_2 == 0x1c) || (param_2 == 0x1d)) || (param_2 == 0x1e)) ||
     (((param_2 == 0x1f || (param_2 == 0x20)) || ((param_2 == 0x21 || (param_2 == 0x22)))))) {
    if (param_2 == 0x1c) {
      piVar5 = (int *)0x7;
      param_2 = iVar4;
    }
    else if (param_2 == 0x1d) {
      piVar5 = (int *)0x8;
      param_2 = iVar4;
    }
    else if (param_2 == 0x1e) {
      piVar5 = (int *)0x9;
      param_2 = iVar4;
    }
    else if (param_2 == 0x1f) {
      piVar5 = (int *)0xa;
      param_2 = iVar4;
    }
    else if (param_2 == 0x20) {
      piVar5 = (int *)0xb;
      param_2 = iVar4;
    }
    else if (param_2 == 0x21) {
      piVar5 = (int *)0x2;
      param_2 = 1;
    }
    else {
      piVar5 = param_4;
      if (param_2 == 0x22) {
        piVar5 = (int *)0x3;
        param_2 = 1;
      }
    }
    iVar4 = FUN_005c1473(piVar5,piVar1,param_4,0);
    puVar3[9] = iVar4;
    if (iVar4 == 0) goto LAB_005c18b2;
    puVar3[7] = param_2;
  }
  else if (param_4 != (int *)0x0) {
    iVar4 = (**(code **)(*param_4 + 8))();
    puVar3[9] = iVar4;
    if (iVar4 == 0) goto LAB_005c18b2;
  }
  if (puVar3[8] != 0) {
    local_14 = *(int **)(puVar3[8] + 0x10);
    local_8 = local_14;
  }
  if (((param_2 == 0) || (param_2 == 1)) ||
     (((param_2 == 0x14 || (((param_2 == 0x15 || (param_2 == 0x10)) || (param_2 == 0x11)))) ||
      (((local_8 != (int *)0x0 && (local_8[1] == 8)) && (iVar4 = FUN_005ba799(local_8), iVar4 != 0))
      )))) {
    if (((param_2 == 2) || (param_2 == 3)) || ((param_2 == 0x14 || (param_2 == 0x15)))) {
      iVar4 = FUN_005ba70c(local_8);
      if ((iVar4 == 0) && (iVar4 = FUN_005bb05e(puVar3[8]), iVar4 == 0)) {
        iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 0x10);
        if (((iVar4 != 3) && (iVar4 != 4)) || (iVar4 = FUN_005ba799(local_8), iVar4 != 0))
        goto LAB_005c1678;
        pcVar9 = "object assignments are not allowed inside functions";
        uVar8 = 0xbf9;
      }
      else {
        pcVar9 = "l-value specifies const object";
        uVar8 = 0xbd1;
      }
      goto LAB_005c18aa;
    }
LAB_005c1678:
    piVar1 = local_8;
    if (puVar3[9] != 0) {
      local_10 = *(int **)(puVar3[9] + 0x10);
      local_c = local_10;
    }
    if ((param_2 != 0x14) && (param_2 != 0x15)) {
      if (((param_2 == 0) || ((param_2 == 1 || (param_2 == 2)))) || (param_2 == 3)) {
        if (local_8 != (int *)0x0) {
          iVar4 = (**(code **)(*local_8 + 8))();
          puVar3[4] = iVar4;
          if (iVar4 == 0) goto LAB_005c18b2;
        }
      }
      else if (((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) {
        if (local_8 != (int *)0x0) {
          iVar4 = (**(code **)(*local_8 + 8))();
          puVar3[4] = iVar4;
          if (iVar4 == 0) goto LAB_005c18b2;
        }
        FUN_005ba5ee(puVar3[4],1);
      }
      else if ((((param_2 == 0xc) || (param_2 == 0xd)) ||
               ((param_2 == 0xe || ((param_2 == 0xf || (param_2 == 0x10)))))) ||
              ((param_2 == 0x11 || ((param_2 == 0x12 || (param_2 == 0x13)))))) {
        iVar4 = FUN_005bc254(local_8,local_c,&local_14,&local_10,puVar3 + 4);
        if (iVar4 < 0) goto LAB_005c1740;
        *(undefined4 *)(puVar3[4] + 0x14) = 0;
      }
      else {
        iVar4 = FUN_005bc254(local_8,local_c,&local_14,&local_10,puVar3 + 4);
        if (iVar4 < 0) {
LAB_005c1740:
          pcVar9 = "type mismatch";
          uVar8 = 0xbcc;
          goto LAB_005c18aa;
        }
      }
LAB_005c17de:
      if ((puVar3[8] != 0) && (local_8 != local_14)) {
        uVar7 = FUN_005ba894(local_8,local_14);
        if ((int)uVar7 == 0) {
          iVar4 = FUN_005beee7(local_14,(int)((ulonglong)uVar7 >> 0x20),0,0);
          if (iVar4 == 0) goto LAB_005c18b2;
          if ((undefined4 *)puVar3[8] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)puVar3[8])(1);
          }
          puVar3[8] = iVar4;
        }
      }
      if ((puVar3[9] != 0) && (local_c != local_10)) {
        uVar7 = FUN_005ba894(local_c,local_10);
        if ((int)uVar7 == 0) {
          iVar4 = FUN_005beee7(local_10,(int)((ulonglong)uVar7 >> 0x20),0,0);
          if (iVar4 == 0) goto LAB_005c18b2;
          if ((undefined4 *)puVar3[9] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)puVar3[9])(1);
          }
          puVar3[9] = iVar4;
        }
      }
      if (puVar3[4] == 0) {
        puVar3[4] = 0;
      }
      FUN_005bb1eb(puVar3);
      iVar4 = FUN_005bb0d5(puVar3);
      if ((iVar4 != 0) && (puVar6 = (undefined4 *)FUN_005c0cfc(puVar3), puVar6 != (undefined4 *)0x0)
         ) {
        (**(code **)*puVar3)(1);
        puVar3 = puVar6;
      }
      goto LAB_005c18bc;
    }
    iVar4 = FUN_005bbe7f(local_8,local_c,0);
    if (iVar4 != 0) {
      if (piVar1 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar1 + 8))();
        puVar3[4] = iVar4;
        if (iVar4 == 0) goto LAB_005c18b2;
      }
      local_10 = piVar1;
      goto LAB_005c17de;
    }
    FUN_005bc1ad(param_3,0,piVar1,local_c,0);
  }
  else {
    pcVar9 = "scalar, vector, or matrix expected";
    uVar8 = 0xbce;
LAB_005c18aa:
    FUN_005ba1d9(param_1,param_3,uVar8,pcVar9);
  }
LAB_005c18b2:
  (**(code **)*puVar3)(1);
  puVar3 = (undefined4 *)0x0;
LAB_005c18bc:
  piVar1 = local_14;
  if (((local_14 != local_8) && (local_14 != local_c)) && (local_14 != (int *)0x0)) {
    (**(code **)*local_14)(1);
  }
  if (((local_10 != local_8) && (local_10 != local_c)) &&
     ((local_10 != piVar1 && (local_10 != (int *)0x0)))) {
    (**(code **)*local_10)(1);
  }
  return puVar3;
}


// ==== 0x5c18f9 FUN_005c18f9

int __thiscall FUN_005c18f9(int param_1,int param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0;
  }
  pvVar1 = _malloc(0x28);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8670();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  puVar2[4] = 1;
  iVar4 = *(int *)(param_1 + 0x14);
  if (param_2 == 0) {
    if (*(int *)(iVar4 + 0x20) == 0) goto LAB_005c198d;
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    pcVar6 = "\'%s\': function must return a value";
    uVar5 = 0xc08;
  }
  else {
    if (*(int *)(iVar4 + 0x20) != 0) {
      uVar3 = FUN_005c1473(0x15,*(undefined4 *)(iVar4 + 0x2c),param_2,1);
      puVar2[5] = uVar3;
      goto LAB_005c198d;
    }
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    pcVar6 = "\'%s\': void functions cannot return a value";
    uVar5 = 0xc07;
  }
  FUN_005ba1d9(param_1,param_1 + 0x20,uVar5,pcVar6,uVar3);
LAB_005c198d:
  pvVar1 = _malloc(0x14);
  if (pvVar1 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_005d78db(puVar2,0,"Stmts");
  }
  if (iVar4 == 0) {
    (**(code **)*puVar2)(1);
    return 0;
  }
  return iVar4;
}


// ==== 0x5c19bf FUN_005c19bf

undefined4 * FUN_005c19bf(int param_1,uint *param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int extraout_ECX;
  char *pcVar12;
  undefined8 uVar13;
  char *pcVar14;
  char *local_50 [4];
  char *local_40;
  char *local_3c;
  char *local_38 [4];
  char *local_28;
  char *local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  int local_8;
  
  local_38[0] = "global variables";
  local_38[1] = "structure members";
  local_38[2] = "function parameters";
  local_38[3] = "local variables";
  local_28 = "loop control variables";
  local_24 = "annotation members";
  local_50[0] = "initial value";
  local_50[1] = "initializer";
  local_50[2] = "default value";
  local_50[3] = "initial value";
  local_40 = "initial value";
  local_3c = "value";
  local_20 = FUN_005ba5e2();
  if (local_20 == 0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)(extraout_ECX + 0xc) == 0) {
    return (undefined4 *)0x0;
  }
  if (param_1 == 0) {
    return (undefined4 *)0x0;
  }
  local_1c = *(undefined4 **)(local_20 + 0x18);
  pvVar4 = _malloc(0x14);
  if (pvVar4 == (void *)0x0) {
    local_c = (undefined4 *)0x0;
  }
  else {
    local_c = (undefined4 *)FUN_005d78db(0,0,"Stmts");
  }
  if (local_c == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  pvVar4 = _malloc(0x30);
  if (pvVar4 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_005d7db0(1,0,0,0);
  }
  if (local_8 == 0) goto LAB_005c237b;
  local_c[2] = local_8;
  pvVar4 = _malloc(0x3c);
  if (pvVar4 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_005d844d();
  }
  iVar7 = local_8;
  if (iVar5 == 0) goto LAB_005c237b;
  *(int *)(local_8 + 0x18) = iVar5;
  if (param_3 != 0) {
    iVar6 = FUN_005d7885(param_3);
    *(int *)(iVar7 + 0x1c) = iVar6;
    if (iVar6 == 0) goto LAB_005c237b;
  }
  if (param_2 != (uint *)0x0) {
    iVar7 = FUN_005d7885(param_2);
    *(int *)(iVar5 + 0x30) = iVar7;
    if (iVar7 == 0) goto LAB_005c237b;
    do {
      iVar7 = *(int *)((int)param_2 + 8);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 4) == 2)) {
        iVar7 = FUN_005d7885(iVar7);
        *(int *)(iVar5 + 0x2c) = iVar7;
        if (iVar7 == 0) goto LAB_005c237b;
      }
      param_2 = *(uint **)((int)param_2 + 0xc);
    } while (param_2 != (uint *)0x0);
  }
  if ((param_4 != 0) && (*(int *)(param_4 + 4) != 0xc)) {
    uVar8 = FUN_005bc645();
    *(undefined4 *)(iVar5 + 0x24) = uVar8;
  }
  local_10 = 1;
  param_2 = (uint *)0x0;
  local_18 = (undefined4 *)0x0;
  if (local_1c != (undefined4 *)0x0) {
    iVar7 = FUN_005d7885(local_1c);
    *(int *)(iVar5 + 0x20) = iVar7;
    if (iVar7 == 0) goto LAB_005c237b;
  }
  for (; *(int *)(param_1 + 4) != 2; param_1 = *(int *)(param_1 + 8)) {
    pvVar4 = _malloc(0x18);
    if (pvVar4 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005d8044();
    }
    if (iVar7 == 0) goto LAB_005c237b;
    if (param_2 != (uint *)0x0) {
      local_18 = (undefined4 *)0xc01;
    }
    *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(iVar5 + 0x20);
    puVar1 = (uint *)(iVar7 + 0x14);
    puVar3 = puVar1;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_005c1bbf:
      param_2 = puVar3;
      *puVar1 = 1;
    }
    else {
      iVar6 = FUN_005c0e2d();
      if (iVar6 < 0) {
        local_18 = (undefined4 *)0xbf2;
        puVar3 = param_2;
        goto LAB_005c1bbf;
      }
    }
    local_10 = *puVar1 * local_10;
    *(int *)(iVar5 + 0x20) = iVar7;
  }
  iVar7 = FUN_005d7885(param_1);
  *(int *)(local_8 + 0x14) = iVar7;
  if (iVar7 == 0) goto LAB_005c237b;
  iVar7 = *(int *)(*(int *)(local_14 + 0xc) + 0x10);
  iVar6 = param_1 + 0x10;
  if (local_18 == (undefined4 *)0xbf2) {
    uVar8 = *(undefined4 *)(param_1 + 0x18);
    uVar13 = 0x69f9d800000bf2;
  }
  else {
    if (local_18 != (undefined4 *)0xc01) {
      uVar10 = local_10;
      if (param_2 != (uint *)0x0) {
        if ((((iVar7 == 0) || (iVar7 == 3)) || (iVar7 == 4)) || (iVar7 == 5)) {
          iVar9 = FUN_005ba80b(local_1c);
          local_1c = (undefined4 *)(iVar9 * local_10);
          if ((undefined4 *)(iVar9 * local_10) == (undefined4 *)0x0) {
            *param_2 = 0;
            uVar10 = 0;
            goto LAB_005c1cd8;
          }
          iVar9 = *(int *)(iVar5 + 0x24);
          if ((iVar9 == 0) || (*(int *)(iVar9 + 4) != 0xc)) {
            pcVar12 = local_50[iVar7];
            uVar13 = CONCAT44(*(undefined4 *)(param_1 + 0x18),"\'%s\': implicit array missing %s");
            uVar8 = 0xc02;
          }
          else {
            uVar10 = FUN_005ba80b(*(undefined4 *)(iVar9 + 0x10));
            if (uVar10 % (uint)local_1c == 0) {
              *param_2 = uVar10 / (uint)local_1c;
              uVar10 = (uVar10 / (uint)local_1c) * local_10;
              goto LAB_005c1cd8;
            }
            pcVar12 = local_50[iVar7];
            uVar13 = CONCAT44(*(undefined4 *)(param_1 + 0x18),
                              "\'%s\': implicit array type does not match %s");
            uVar8 = 0xc03;
          }
        }
        else {
          pcVar12 = local_38[iVar7];
          uVar13 = CONCAT44(*(undefined4 *)(param_1 + 0x18),
                            "\'%s\': array dimensions of %s must be explicit");
          uVar8 = 0xc00;
        }
        FUN_005ba1d9(local_14,iVar6,uVar8,uVar13,pcVar12);
        goto LAB_005c237b;
      }
LAB_005c1cd8:
      if ((uVar10 == 0) || (0x10000 < uVar10)) {
        uVar8 = *(undefined4 *)(param_1 + 0x18);
        uVar13 = 0x69fa4400000bf3;
        goto LAB_005c2371;
      }
      iVar9 = FUN_005ba80b(*(undefined4 *)(iVar5 + 0x20));
      *(int *)(iVar5 + 0x14) = iVar9;
      *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(*(int *)(local_14 + 0xc) + 0x10);
      if (*(int *)(*(int *)(local_14 + 0xc) + 0x10) == 1) {
        *(undefined4 *)(iVar5 + 0x10) = 0xffffffff;
      }
      else {
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(local_14 + 0x58);
        *(int *)(local_14 + 0x58) = *(int *)(local_14 + 0x58) + iVar9;
      }
      param_2 = *(uint **)(local_20 + 0x10);
      if (*(int *)(local_20 + 0x14) != 0) {
        FUN_005ba1d9(local_14,iVar6,0xbdf,"\'%s\': %s cannot be target specific",
                     *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
      }
      if (((uint)param_2 & 0x100) != 0) {
        FUN_005ba1d9(local_14,iVar6,0xbef,"\'%s\': %s cannot be declared \'inline\'",
                     *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
      }
      if (iVar7 == 1) {
        iVar9 = FUN_005ba70c(*(undefined4 *)(iVar5 + 0x20));
        if (iVar9 != 0) {
          FUN_005ba1d9(local_14,iVar6,0xbdb,"\'%s\': %s cannot be declared \'const\'",
                       *(undefined4 *)(param_1 + 0x18),"structure members");
          goto LAB_005c1d9f;
        }
LAB_005c1e81:
        if (((((uint)param_2 & 2) != 0) && (iVar7 != 3)) && (iVar7 != 4)) {
          FUN_005ba1d9(local_14,iVar6,0xbbf,"\'%s\': %s cannot be declared \'static\'",
                       *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
          param_2 = (uint *)((uint)param_2 & 0xfffffffd);
        }
        if (((uint)param_2 & 0x40) != 0) {
          if (iVar7 != 2) {
            FUN_005ba1d9(local_14,iVar6,0xbe7,"\'%s\': %s cannot be declared \'uniform\'",
                         *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
            param_2 = (uint *)((uint)param_2 & 0xffffffbf);
          }
          if ((((uint)param_2 & 0x40) != 0) && (((uint)param_2 & 0x20) != 0)) {
            FUN_005ba1d9(local_14,iVar6,0xbf6,"\'%s\': %s cannot be declared \'uniform out\'",
                         *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
            param_2 = (uint *)((uint)param_2 & 0xffffffbf);
          }
        }
        if (((uint)param_2 & 1) != 0) {
          FUN_005ba1d9(local_14,iVar6,0xbbe,"\'%s\': %s cannot be declared \'extern\'",
                       *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
          param_2 = (uint *)((uint)param_2 & 0xfffffffe);
        }
        if ((((((uint)param_2 & 4) != 0) && (iVar7 != 3)) && (iVar7 != 4)) && (iVar7 != 2)) {
          FUN_005ba1d9(local_14,iVar6,0xbc0,"\'%s\': %s cannot be declared \'volatile\'",
                       *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
          param_2 = (uint *)((uint)param_2 & 0xfffffffb);
        }
        if (((uint)param_2 & 8) != 0) {
          FUN_005ba1d9(local_14,iVar6,0xbee,"\'%s\': %s cannot be declared \'shared\'",
                       *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
          param_2 = (uint *)((uint)param_2 & 0xfffffff7);
        }
        if (iVar7 == 5) {
          FUN_005ba5ee();
          param_2 = (uint *)((uint)param_2 | 0x40);
        }
      }
      else {
LAB_005c1d9f:
        if (iVar7 == 2) {
          if ((((uint)param_2 & 0x10) != 0) ||
             (iVar9 = FUN_005ba70c(*(undefined4 *)(iVar5 + 0x20)), iVar9 == 0)) goto LAB_005c1e81;
          FUN_005ba1d9(local_14,iVar6,0xbe6,"\'%s\': output paramaters cannot be declared \'const\'"
                       ,*(undefined4 *)(param_1 + 0x18));
        }
        if (((iVar7 == 3) || (iVar7 == 4)) &&
           (iVar9 = FUN_005ba799(*(undefined4 *)(iVar5 + 0x20)), iVar9 == 0)) {
          FUN_005ba1d9(local_14,iVar6,0xbde,"\'%s\': %s must be numeric",
                       *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
        }
        if (iVar7 != 0) goto LAB_005c1e81;
        if (((uint)param_2 & 2) == 0) {
LAB_005c1e78:
          param_2 = (uint *)((uint)param_2 | 0x41);
        }
        else {
          if (((uint)param_2 & 1) != 0) {
            FUN_005ba1d9(local_14,iVar6,0xbbf,"\'%s\': extern %s cannot be declared \'static\'",
                         *(undefined4 *)(param_1 + 0x18),"global variables");
            param_2 = (uint *)((uint)param_2 & 0xfffffffd);
          }
          if (((uint)param_2 & 2) == 0) goto LAB_005c1e78;
          if (((uint)param_2 & 0x40) != 0) {
            FUN_005ba1d9(local_14,iVar6,0xbbf,"\'%s\': uniform %s cannot be declared \'static\'",
                         *(undefined4 *)(param_1 + 0x18),"global variables");
            param_2 = (uint *)((uint)param_2 & 0xfffffffd);
          }
          if (((uint)param_2 & 2) == 0) goto LAB_005c1e78;
        }
      }
      local_18 = (undefined4 *)0x0;
      *(uint **)(iVar5 + 0x1c) = param_2;
      if (param_4 == 0) {
        if (((iVar7 == 3) || (iVar7 == 4)) && (((uint)param_2 & 2) != 0)) {
          uVar8 = FUN_005bc356(5,0,0,iVar6);
          goto LAB_005c205f;
        }
      }
      else if (*(int *)(param_4 + 4) == 0xc) {
        uVar8 = FUN_005beee7(*(undefined4 *)(iVar5 + 0x20),param_4,0,0);
LAB_005c205f:
        *(undefined4 *)(iVar5 + 0x24) = uVar8;
      }
      else {
        local_1c = *(undefined4 **)(iVar5 + 0x24);
        if (local_1c == (undefined4 *)0x0) {
          param_4 = 0;
        }
        else {
          param_4 = local_1c[4];
        }
        iVar9 = FUN_005ba80b(param_4);
        if (*(int *)(iVar5 + 0x14) == iVar9) {
          uVar8 = FUN_005beee7(*(undefined4 *)(iVar5 + 0x20),local_1c,0,1);
          *(undefined4 *)(iVar5 + 0x24) = uVar8;
        }
        else {
          FUN_005bc1ad(iVar6,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(iVar5 + 0x20),param_4,1
                      );
          *(undefined4 *)(iVar5 + 0x24) = 0;
        }
        if (local_1c != (undefined4 *)0x0) {
          (**(code **)*local_1c)(1);
        }
      }
      if (*(int *)(iVar5 + 0x24) == 0) {
        if (iVar7 == 0) {
          iVar9 = FUN_005ba70c(*(undefined4 *)(iVar5 + 0x20));
          if (iVar9 != 0) {
            if (((uint)param_2 & 2) == 0) goto LAB_005c2238;
            goto LAB_005c2258;
          }
        }
        else {
LAB_005c2238:
          if ((((iVar7 != 3) && (iVar7 != 4)) ||
              (iVar9 = FUN_005ba70c(*(undefined4 *)(iVar5 + 0x20)), iVar9 == 0)) && (iVar7 != 5))
          goto LAB_005c2276;
LAB_005c2258:
          FUN_005ba1d9(local_14,iVar6,0xbc4,"\'%s\': missing %s",*(undefined4 *)(param_1 + 0x18),
                       local_50[iVar7]);
LAB_005c2276:
          if ((((iVar7 != 0) && (iVar7 != 1)) && (iVar7 != 2)) && (*(int *)(iVar5 + 0x2c) != 0)) {
            FUN_005ba1d9(local_14,iVar6,0xbe3,"\'%s\': %s cannot have semantics",
                         *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
            goto LAB_005c22ac;
          }
        }
      }
      else {
        if (iVar7 == 1) {
          pcVar14 = "initializer";
          uVar13 = CONCAT44("structure members",*(undefined4 *)(param_1 + 0x18));
          pcVar12 = "\'%s\': %s cannot have %ss";
        }
        else {
          if ((iVar7 != 2) || (iVar9 = FUN_005ba799(*(undefined4 *)(iVar5 + 0x20)), iVar9 != 0)) {
            local_1c = (undefined4 *)((uint)param_2 & 0x10);
            if (((undefined4 *)((uint)param_2 & 0x10) == (undefined4 *)0x0) &&
               (((uint)param_2 & 0x20) != 0)) {
              FUN_005ba1d9(local_14,iVar6,0xbe5,"\'%s\': output only %s cannot have %ss",
                           *(undefined4 *)(param_1 + 0x18),local_38[iVar7],local_50[iVar7]);
            }
            else if ((((uint)param_2 & 0x50) == 0) ||
                    (iVar9 = FUN_005bb0d5(*(undefined4 *)(iVar5 + 0x24)), iVar9 != 0)) {
              iVar9 = FUN_005bbe7f(*(undefined4 *)(iVar5 + 0x20),
                                   *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x10),0);
              if (iVar9 != 0) {
                if (((uint)param_2 & 0x40) != 0) {
                  uVar8 = FUN_005c0cfc(*(undefined4 *)(iVar5 + 0x24));
                  *(undefined4 *)(iVar5 + 0x28) = uVar8;
                }
                if ((((uint)param_2 & 0x50) == 0) &&
                   (iVar9 = FUN_005ba70c(*(undefined4 *)(iVar5 + 0x20)), iVar9 != 0)) {
                  uVar8 = FUN_005c0cfc(*(undefined4 *)(iVar5 + 0x24));
                  if (*(undefined4 **)(iVar5 + 0x24) != (undefined4 *)0x0) {
                    (**(code **)**(undefined4 **)(iVar5 + 0x24))(1);
                  }
                  *(undefined4 *)(iVar5 + 0x24) = uVar8;
                }
                else {
                  if ((local_1c == (undefined4 *)0x0) && (((uint)param_2 & 0x40) != 0))
                  goto LAB_005c20f5;
                  puVar2 = *(undefined4 **)(iVar5 + 0x24);
                  *(undefined4 *)(iVar5 + 0x24) = 0;
                  puVar11 = (undefined4 *)FUN_005bedc7();
                  local_18 = (undefined4 *)FUN_005c1473(0x14,puVar11,puVar2,1);
                  if (puVar11 != (undefined4 *)0x0) {
                    (**(code **)*puVar11)(1);
                  }
                  if (puVar2 != (undefined4 *)0x0) {
                    (**(code **)*puVar2)(1);
                  }
                }
                goto LAB_005c2276;
              }
              FUN_005bc1ad(iVar6,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(iVar5 + 0x20),
                           *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x10),0);
            }
            else {
              FUN_005ba1d9(local_14,iVar6,0xbc3,"\'%s\': %s must be a literal expression",
                           *(undefined4 *)(param_1 + 0x18),local_50[iVar7]);
            }
LAB_005c20f5:
            if (*(undefined4 **)(iVar5 + 0x24) != (undefined4 *)0x0) {
              (**(code **)**(undefined4 **)(iVar5 + 0x24))(1);
            }
            *(undefined4 *)(iVar5 + 0x24) = 0;
            goto LAB_005c2276;
          }
          pcVar14 = "default value";
          uVar13 = CONCAT44("function parameters",*(undefined4 *)(param_1 + 0x18));
          pcVar12 = "\'%s\': non-numeric uniform %s cannot have %ss";
        }
        FUN_005ba1d9(local_14,iVar6,0xbc1,pcVar12,uVar13,pcVar14);
LAB_005c22ac:
        if (*(undefined4 **)(iVar5 + 0x24) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(iVar5 + 0x24))(1);
        }
        *(undefined4 *)(iVar5 + 0x24) = 0;
      }
      iVar5 = local_8;
      if (((*(int *)(local_8 + 0x1c) != 0) && (iVar7 != 0)) && (iVar7 != 2)) {
        FUN_005ba1d9(local_14,iVar6,0xbe0,"\'%s\': %s cannot have annotations",
                     *(undefined4 *)(param_1 + 0x18),local_38[iVar7]);
        puVar2 = *(undefined4 **)(iVar5 + 0x1c);
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
        *(undefined4 *)(iVar5 + 0x1c) = 0;
      }
      iVar5 = FUN_005ba3df();
      puVar2 = local_18;
      if (iVar5 < 0) {
        if (local_18 != (undefined4 *)0x0) {
          (**(code **)*local_18)(1);
        }
      }
      else {
        if (local_18 == (undefined4 *)0x0) {
          return local_c;
        }
        uVar8 = FUN_005bb22e(local_18);
        puVar11 = local_c;
        local_c[3] = uVar8;
        (**(code **)*puVar2)(1);
        if (puVar11[3] != 0) {
          return puVar11;
        }
      }
      goto LAB_005c237b;
    }
    uVar8 = *(undefined4 *)(param_1 + 0x18);
    uVar13 = 0x69fc7000000c01;
  }
LAB_005c2371:
  FUN_005ba1d9(local_14,iVar6,uVar13,uVar8);
LAB_005c237b:
  (**(code **)*local_c)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5c238d FUN_005c238d

undefined4 * __thiscall FUN_005c238d(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 uVar13;
  undefined4 *local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 **local_20;
  undefined4 **local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_18 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_8 = (undefined4 *)0x0;
  local_30 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 2)) {
    return (undefined4 *)0x0;
  }
  iVar8 = param_2 + 0x10;
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x1c);
  }
  uVar5 = 6;
  if (param_4 != 0) {
    uVar5 = 0x16;
  }
  local_14 = iVar8;
  local_10 = param_1;
  iVar4 = FUN_005be628(2,iVar8,uVar3,param_3,*(undefined4 *)(param_1 + 0xc),uVar5,&local_18,&local_8
                      );
  bVar12 = iVar4 == 0;
  if (-1 < iVar4) {
    if (param_4 == 0) {
      if (bVar12) {
LAB_005c24c9:
        local_1c = &local_30;
        local_20 = &local_24;
        iVar4 = param_3;
        for (local_2c = local_18[9]; local_2c != 0; local_2c = *(int *)(local_2c + 0xc)) {
          iVar1 = *(int *)(local_2c + 0xc);
          iVar2 = *(int *)(local_2c + 8);
          bVar12 = false;
          if ((iVar1 != 0) && (iVar8 = local_14, *(int *)(*(int *)(iVar1 + 8) + 4) == 0xb)) {
            bVar12 = true;
            local_2c = iVar1;
          }
          if ((param_4 == 0) || ((*(byte *)(*(int *)(iVar2 + 0x18) + 0x1c) & 0x40) != 0)) {
            if (iVar4 == 0) {
              if (!bVar12) goto LAB_005c26ae;
            }
            else {
              local_28 = *(int *)(iVar2 + 0x18);
              uVar3 = *(undefined4 *)(local_28 + 0x20);
              if (*(int *)(iVar4 + 8) == 0) {
                param_2 = 0;
              }
              else {
                param_2 = *(undefined4 *)(*(int *)(iVar4 + 8) + 0x10);
              }
              pvVar6 = _malloc(0x14);
              if (pvVar6 == (void *)0x0) {
                puVar7 = (undefined4 *)0x0;
              }
              else {
                puVar7 = (undefined4 *)FUN_005d78db(0,0,"Inputs");
              }
              *local_1c = puVar7;
              if (puVar7 == (undefined4 *)0x0) goto LAB_005c2813;
              pvVar6 = _malloc(0x14);
              if (pvVar6 == (void *)0x0) {
                puVar7 = (undefined4 *)0x0;
              }
              else {
                puVar7 = (undefined4 *)FUN_005d78db(0,0,"Outputs");
              }
              *local_20 = puVar7;
              param_1 = local_10;
              if (puVar7 == (undefined4 *)0x0) goto LAB_005c2813;
              if ((*(byte *)(local_28 + 0x1c) & 0x10) != 0) {
                iVar8 = FUN_005bbe7f(uVar3,param_2,0);
                uVar5 = uVar3;
                uVar13 = param_2;
                if (iVar8 != 0) {
                  uVar5 = FUN_005beee7(uVar3,*(undefined4 *)(iVar4 + 8),0,0);
                  (*local_1c)[2] = uVar5;
                  goto LAB_005c25d5;
                }
LAB_005c26ef:
                FUN_005bc1ad(local_14,*(undefined4 *)(local_14 + 8),uVar5,uVar13,0);
                goto LAB_005c2813;
              }
LAB_005c25d5:
              if ((*(byte *)(local_28 + 0x1c) & 0x20) != 0) {
                iVar8 = FUN_005ba70c(param_2);
                uVar5 = param_2;
                uVar13 = uVar3;
                if ((iVar8 != 0) || (iVar8 = FUN_005bbe7f(param_2,uVar3,0), iVar8 == 0))
                goto LAB_005c26ef;
                puVar7 = (undefined4 *)FUN_005bedc7(*(undefined4 *)(iVar2 + 0x14),local_28);
                if (puVar7 == (undefined4 *)0x0) goto LAB_005c2813;
                puVar11 = (undefined4 *)FUN_005beee7(param_2,puVar7,0,0);
                (**(code **)*puVar7)(1);
                if (puVar11 == (undefined4 *)0x0) goto LAB_005c2813;
                iVar8 = FUN_005c1473(0x15,*(undefined4 *)(iVar4 + 8),puVar11,1);
                (**(code **)*puVar11)(1);
                if (iVar8 == 0) goto LAB_005c2813;
                (*local_20)[2] = iVar8;
                param_1 = local_10;
              }
              iVar4 = *(int *)(iVar4 + 0xc);
              local_1c = (undefined4 **)(*local_1c + 3);
              local_20 = (undefined4 **)(*local_20 + 3);
              iVar8 = local_14;
            }
          }
        }
        if (iVar4 == 0) {
LAB_005c26ae:
          if (local_2c != 0) goto LAB_005c27a0;
          pvVar6 = _malloc(0x50);
          if (pvVar6 == (void *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            puVar7 = (undefined4 *)
                     FUN_005d8831(0,(local_c != (undefined4 *)0x0) + '\x19',0,0,1,iVar8);
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_005c2813;
          if ((int *)local_18[8] == (int *)0x0) {
LAB_005c2724:
            puVar7[8] = local_8;
            local_8 = (undefined4 *)0x0;
            pvVar6 = _malloc(0x14);
            if (pvVar6 == (void *)0x0) {
              iVar8 = 0;
            }
            else {
              iVar8 = FUN_005d78db(0,0,"Parameters");
            }
            puVar7[9] = iVar8;
            if (iVar8 != 0) {
              *(undefined4 **)(iVar8 + 8) = local_30;
              *(undefined4 **)(puVar7[9] + 0xc) = local_24;
              puVar11 = (undefined4 *)0x0;
              local_24 = (undefined4 *)0x0;
              FUN_005bb1eb(puVar7);
              iVar8 = FUN_005bb0d5(puVar7);
              if ((iVar8 != 0) &&
                 (puVar9 = (undefined4 *)FUN_005c0cfc(puVar7), puVar9 != (undefined4 *)0x0)) {
                (**(code **)*puVar7)(1);
                puVar7 = puVar9;
              }
              goto LAB_005c2818;
            }
          }
          else {
            iVar8 = (**(code **)(*(int *)local_18[8] + 8))();
            puVar7[4] = iVar8;
            if (iVar8 != 0) goto LAB_005c2724;
          }
        }
        else {
LAB_005c27a0:
          iVar4 = 0;
          for (; param_3 != 0; param_3 = *(int *)(param_3 + 0xc)) {
            iVar4 = iVar4 + 1;
          }
          puVar10 = &DAT_0069ed7c;
          if (local_c == (undefined4 *)0x0) {
            if (iVar4 == 1) {
              puVar10 = &DAT_006b9172;
            }
            FUN_005ba1d9(param_1,iVar8,0xbc5,"\'%s\': function does not take %u parameter%s",
                         *(undefined4 *)(iVar8 + 8),iVar4,puVar10);
            goto LAB_005c2813;
          }
          if (iVar4 == 1) {
            puVar10 = &DAT_006b9172;
          }
          FUN_005ba1d9(param_1,iVar8,0xbc5,"\'%s\': intrinsic function does not take %u parameter%s"
                       ,*(undefined4 *)(iVar8 + 8),iVar4,puVar10);
          puVar7 = (undefined4 *)0x0;
        }
        if (puVar7 != (undefined4 *)0x0) {
          (**(code **)*puVar7)(1);
        }
      }
      else {
        iVar4 = FUN_005bb534(iVar8,param_3,&local_c,&local_8);
        if (-1 < iVar4) {
          if (iVar4 == 0) {
            bVar12 = true;
            goto LAB_005c2443;
          }
          goto LAB_005c2448;
        }
      }
    }
    else {
LAB_005c2443:
      if (!bVar12) {
LAB_005c2448:
        iVar4 = FUN_005be628(2,iVar8,0,0,*(undefined4 *)(param_1 + 0xc),2,&local_18,&local_8);
        if (iVar4 < 0) goto LAB_005c2813;
        if (iVar4 == 0) {
          bVar12 = true;
        }
      }
      if (param_4 == 0) {
        if (bVar12) goto LAB_005c24bf;
        iVar4 = FUN_005bb534(iVar8,0,&local_c,&local_8);
        if (iVar4 < 0) goto LAB_005c2813;
        if (iVar4 == 0) {
          bVar12 = true;
          goto LAB_005c249e;
        }
      }
      else {
LAB_005c249e:
        if (bVar12) {
LAB_005c24bf:
          if (local_c != (undefined4 *)0x0) {
            local_18 = local_c;
          }
          goto LAB_005c24c9;
        }
      }
      FUN_005ba1d9(param_1,iVar8,0xbbc,"undeclared identifier \'%s\'",
                   *(undefined4 *)(param_2 + 0x18));
    }
  }
LAB_005c2813:
  puVar11 = local_30;
  puVar7 = (undefined4 *)0x0;
LAB_005c2818:
  if (local_c != (undefined4 *)0x0) {
    (**(code **)*local_c)(1);
  }
  if (puVar11 != (undefined4 *)0x0) {
    (**(code **)*puVar11)(1);
  }
  if (local_24 != (undefined4 *)0x0) {
    (**(code **)*local_24)(1);
  }
  if (local_8 != (undefined4 *)0x0) {
    (**(code **)*local_8)(1);
  }
  return puVar7;
}


// ==== 0x5c2858 FUN_005c2858

undefined4 * FUN_005c2858(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_1c [4];
  uint local_18;
  int local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar4 = param_1 + 0x10;
    local_10 = iVar4;
    iVar1 = FUN_005d7700(*(undefined4 *)(param_1 + 0x18),2,local_1c);
    if (iVar1 < 0) {
      FUN_005ba1d9(local_c,iVar4,0xbe1,"unsupported compiler target \'%s\'",
                   *(undefined4 *)(param_1 + 0x18));
    }
    else {
      if ((local_18 & 0xffff0000) == 0xfffe0000) {
        param_4 = (uint)(param_4 != 0) * 2 + 0x1a;
      }
      else if ((local_18 & 0xffff0000) == 0xffff0000) {
        param_4 = (uint)(param_4 != 0) * 2 + 0x19;
      }
      pvVar2 = _malloc(0x50);
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)FUN_005d8831(0,0x1b,0,0,1,iVar4);
      }
      if (puVar3 != (undefined4 *)0x0) {
        pvVar2 = _malloc(0x24);
        if (pvVar2 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005d814c(3,param_4,1,1,0x200);
        }
        puVar3[4] = iVar4;
        if (iVar4 != 0) {
          iVar4 = FUN_005d7885(param_1);
          puVar3[8] = iVar4;
          if (iVar4 != 0) {
            iVar4 = FUN_005c238d(param_2,param_3,1);
            puVar3[9] = iVar4;
            if (iVar4 != 0) {
              pvVar2 = _malloc(0x50);
              if (pvVar2 == (void *)0x0) {
                local_8 = (undefined4 *)0x0;
              }
              else {
                local_8 = (undefined4 *)FUN_005d8831(0,0,0,0,1,local_10);
              }
              if (local_8 != (undefined4 *)0x0) {
                pvVar2 = _malloc(0x24);
                if (pvVar2 == (void *)0x0) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = FUN_005d814c(3,param_4,1,1,0x200);
                }
                local_8[4] = iVar4;
                if (iVar4 != 0) {
                  pvVar2 = _malloc(0x14);
                  if (pvVar2 == (void *)0x0) {
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = FUN_005d78db(0,0,"Value");
                  }
                  local_8[8] = iVar4;
                  if (iVar4 != 0) {
                    pvVar2 = _malloc(0x40);
                    if (pvVar2 == (void *)0x0) {
                      iVar4 = 0;
                    }
                    else {
                      iVar4 = FUN_005d8a65(4,puVar3,local_10);
                    }
                    *(int *)(local_8[8] + 8) = iVar4;
                    if (iVar4 != 0) {
                      FUN_005bb1eb(local_8);
                      return local_8;
                    }
                  }
                }
              }
            }
          }
        }
        (**(code **)*puVar3)(1);
        if (local_8 != (undefined4 *)0x0) {
          (**(code **)*local_8)(1);
        }
      }
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x5c2a3c FUN_005c2a3c

void __thiscall FUN_005c2a3c(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *pcVar14;
  undefined4 *local_68 [16];
  undefined1 local_28 [24];
  undefined4 local_10;
  uint local_c;
  undefined4 *local_8;
  
  puVar7 = (undefined4 *)0x0;
  local_8 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0x44) != 0) {
    return;
  }
  local_c = param_3;
  puVar3 = local_68[1];
  puVar2 = local_68[0];
  while (local_68[0] = puVar2, local_68[1] = puVar3, local_c != 0) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    local_c = local_c - 1;
    if (puVar2 == (undefined4 *)0x0) {
      pcVar14 = "internal error: stack underflow";
      goto LAB_005c39d6;
    }
    local_68[local_c] = (undefined4 *)puVar2[2];
    *(undefined4 *)(param_1 + 8) = puVar2[3];
    puVar2[2] = 0;
    puVar2[3] = 0;
    (**(code **)*puVar2)(1);
    puVar3 = local_68[1];
    puVar2 = local_68[0];
  }
  switch(param_2) {
  case 0:
    pvVar5 = _malloc(0x20);
    if (pvVar5 == (void *)0x0) break;
    puVar7 = (undefined4 *)FUN_005d7b61(0,0,0,0);
    goto LAB_005c396f;
  case 1:
    pvVar5 = _malloc(0x20);
    if (pvVar5 == (void *)0x0) goto LAB_005c38a8;
    puVar2 = (undefined4 *)
             FUN_005d7b61(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                          *(undefined4 *)(param_1 + 0x58),local_68[0]);
    goto LAB_005c2e05;
  case 2:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0x11:
  case 0x13:
  case 0x20:
  case 0x23:
  case 0x24:
  case 0x27:
  case 0x29:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x4c:
  case 0x4f:
  case 0x54:
  case 0x57:
  case 0x5d:
  case 0x5f:
  case 0x62:
  case 99:
  case 100:
  case 0x66:
  case 0x69:
  case 0x6c:
  case 0x77:
  case 0x7e:
  case 0x84:
  case 0x8a:
  case 0x91:
  case 0x95:
  case 0x9c:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa8:
  case 0xab:
  case 0xb3:
  case 0xb5:
  case 0xb7:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xc5:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd8:
  case 0xde:
  case 0xe0:
  case 0xe4:
  case 0xe7:
  case 0xec:
  case 0xef:
  case 0xf1:
  case 0xf3:
  case 0xfa:
  case 0xff:
  case 0x101:
  case 0x102:
  case 0x103:
  case 0x105:
  case 0x106:
  case 0x108:
  case 0x10a:
  case 0x10c:
  case 0x10e:
  case 0x115:
  case 0x116:
    goto LAB_005c3949;
  case 3:
  case 0x50:
  case 0x60:
  case 0x6a:
  case 0x78:
  case 0x8b:
  case 0x92:
  case 0x9d:
  case 0x104:
    goto LAB_005c38b2;
  case 10:
  case 0x14:
  case 0x7f:
    FUN_005ba681();
    goto LAB_005c3949;
  case 0xb:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 == (void *)0x0) break;
    uVar9 = 2;
LAB_005c332c:
    puVar7 = (undefined4 *)FUN_005d7f48(uVar9,0);
    goto LAB_005c396f;
  case 0xc:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x40;
      goto LAB_005c332c;
    }
    break;
  case 0xd:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 1;
      goto LAB_005c332c;
    }
    break;
  case 0xe:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 4;
      goto LAB_005c332c;
    }
    break;
  case 0xf:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x100;
      goto LAB_005c332c;
    }
    break;
  case 0x10:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 8;
      goto LAB_005c332c;
    }
    break;
  case 0x12:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 == (void *)0x0) goto LAB_005c38a8;
    puVar2 = (undefined4 *)FUN_005d7f48(0,local_68[0],0);
    goto LAB_005c2e05;
  case 0x15:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x200;
      goto LAB_005c332c;
    }
    break;
  case 0x16:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x400;
      goto LAB_005c332c;
    }
    break;
  case 0x17:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x800;
      goto LAB_005c332c;
    }
    break;
  case 0x18:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0;
      goto LAB_005c329f;
    }
LAB_005c2c2c:
    puVar2 = (undefined4 *)0x0;
    goto LAB_005c2c2e;
  case 0x19:
    puVar2[6] = puVar3;
    local_68[1] = (undefined4 *)0x0;
    goto LAB_005c2c3e;
  default:
    FUN_005ba278(param_1,0,0,"internal error: unhandled production");
    goto LAB_005c2d53;
  case 0x1c:
    FUN_005d7f48(0,0,*(undefined4 *)(puVar2[2] + 0x18));
    FUN_005bd1b1(local_28);
    local_10 = 0;
    local_68[0] = (undefined4 *)0x0;
    FUN_005d7f77();
    puVar7 = puVar2;
    goto LAB_005c2d53;
  case 0x1d:
    puVar2[6] = *(undefined4 *)(puVar3[2] + 0x18);
    FUN_005bd1b1(puVar2);
    puVar2[6] = 0;
    goto switchD_005c2a9a_caseD_49;
  case 0x1e:
    puVar7 = (undefined4 *)FUN_005c0e94();
    goto LAB_005c396f;
  case 0x1f:
    local_8 = (undefined4 *)FUN_005c0e94();
    FUN_005ba2ce(local_8);
    puVar2 = (undefined4 *)FUN_005d7899();
    goto LAB_005c3949;
  case 0x21:
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) goto LAB_005c38a8;
    pcVar14 = "TypeDefs";
LAB_005c2cfc:
    puVar2 = (undefined4 *)FUN_005d78db(local_68[0],0,pcVar14);
    goto LAB_005c2e05;
  case 0x22:
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) goto LAB_005c2d22;
    pcVar14 = "TypeDefs";
LAB_005c35ab:
    puVar7 = (undefined4 *)FUN_005d78db(local_68[0],local_68[1],pcVar14);
    goto LAB_005c2d24;
  case 0x25:
    FUN_005be628(0,puVar2 + 4,0,0,*(undefined4 *)(param_1 + 0xc),1,&local_8,0);
    puVar7 = local_8;
    goto LAB_005c2d53;
  case 0x26:
    iVar6 = FUN_005be628(0,puVar2 + 4,0,0,*(undefined4 *)(param_1 + 0xc),1,&local_8,0);
    puVar7 = local_8;
    if (((iVar6 == 0) && (local_8 != (undefined4 *)0x0)) && (local_8[1] != 1)) {
      FUN_005ba1d9(param_1,puVar2 + 4,0xbbd,"invalid use of \'%s\'",puVar2[6]);
    }
    goto LAB_005c2d53;
  case 0x28:
    FUN_005bbdd0();
    goto LAB_005c38bf;
  case 0x2a:
    puVar2 = (undefined4 *)FUN_005c11d0();
    goto LAB_005c2e05;
  case 0x2b:
  case 0x48:
  case 0x56:
  case 0x5a:
  case 0x5c:
  case 0x65:
  case 0x72:
  case 0x73:
  case 0x76:
  case 0x86:
  case 0x8d:
  case 0x94:
  case 0x98:
  case 0xa2:
  case 0xb1:
  case 0xb4:
  case 0xb6:
  case 0xca:
  case 0xfe:
  case 0x114:
    goto switchD_005c2a9a_caseD_2b;
  case 0x30:
    pvVar5 = _malloc(0x24);
    if (pvVar5 == (void *)0x0) break;
    uVar13 = 0;
LAB_005c2e30:
    uVar9 = 0x100000001;
    uVar12 = 0;
LAB_005c308f:
    puVar7 = (undefined4 *)FUN_005d814c(uVar12,uVar13,uVar9,0);
    goto LAB_005c396f;
  case 0x31:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 4;
      goto LAB_005c2e30;
    }
    break;
  case 0x32:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 10;
      goto LAB_005c2e30;
    }
    break;
  case 0x33:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0xb;
      goto LAB_005c2e30;
    }
    break;
  case 0x34:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0xc;
      goto LAB_005c2e30;
    }
    break;
  case 0x35:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x400000001;
      uVar13 = 0xb;
      uVar12 = 1;
      goto LAB_005c308f;
    }
    break;
  case 0x36:
    puVar7 = (undefined4 *)FUN_005c10a3();
    goto LAB_005c396f;
  case 0x37:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x400000004;
      uVar13 = 0xb;
      uVar12 = 2;
      goto LAB_005c308f;
    }
    break;
  case 0x38:
    puVar7 = (undefined4 *)FUN_005c1128(puVar2,puVar3,local_68[2]);
    goto LAB_005c396f;
  case 0x39:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0xe;
LAB_005c308d:
      uVar9 = 0x100000001;
      uVar12 = 3;
      goto LAB_005c308f;
    }
    break;
  case 0x3a:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0xf;
      goto LAB_005c308d;
    }
    break;
  case 0x3b:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x10;
      goto LAB_005c308d;
    }
    break;
  case 0x3c:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x11;
      goto LAB_005c308d;
    }
    break;
  case 0x3d:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x12;
      goto LAB_005c308d;
    }
    break;
  case 0x3e:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x13;
      goto LAB_005c308d;
    }
    break;
  case 0x3f:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x14;
      goto LAB_005c308d;
    }
    break;
  case 0x40:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x15;
      goto LAB_005c308d;
    }
    break;
  case 0x41:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x16;
      goto LAB_005c308d;
    }
    break;
  case 0x42:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x17;
      goto LAB_005c308d;
    }
    break;
  case 0x43:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x18;
      goto LAB_005c308d;
    }
    break;
  case 0x44:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x19;
      goto LAB_005c308d;
    }
    break;
  case 0x45:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x1a;
      goto LAB_005c308d;
    }
    break;
  case 0x46:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x1b;
      goto LAB_005c308d;
    }
    break;
  case 0x47:
    pvVar5 = _malloc(0x24);
    if (pvVar5 != (void *)0x0) {
      uVar13 = 0x1c;
      goto LAB_005c308d;
    }
    break;
  case 0x49:
  case 0x5b:
  case 0x74:
  case 0x87:
  case 0x8e:
  case 0x99:
    goto switchD_005c2a9a_caseD_49;
  case 0x4a:
    goto LAB_005c30a7;
  case 0x4b:
LAB_005c30a7:
    puVar7 = (undefined4 *)FUN_005c1052();
    goto LAB_005c396f;
  case 0x4d:
    FUN_005bbdd0();
    goto switchD_005c2a9a_caseD_49;
  case 0x4e:
    goto LAB_005c356e;
  case 0x51:
  case 0x61:
  case 0x89:
  case 0x9b:
    goto switchD_005c2a9a_caseD_51;
  case 0x52:
  case 0x53:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "Semantics";
      goto LAB_005c2cfc;
    }
    goto LAB_005c38a8;
  case 0x55:
    puVar7 = (undefined4 *)FUN_005d7899();
    goto LAB_005c2d24;
  case 0x58:
    pvVar5 = _malloc(0x18);
    if (pvVar5 == (void *)0x0) goto LAB_005c38a8;
    puVar2 = (undefined4 *)FUN_005d8eb3();
    goto LAB_005c2e05;
  case 0x59:
    pvVar5 = _malloc(0x18);
    if (pvVar5 == (void *)0x0) goto LAB_005c2d22;
    puVar7 = (undefined4 *)FUN_005d8eb3();
    goto LAB_005c2d24;
  case 0x5e:
    goto LAB_005c356e;
  case 0x67:
  case 0x79:
    goto LAB_005c327a;
  case 0x68:
    puVar3 = (undefined4 *)FUN_005d7899();
    local_68[0] = (undefined4 *)0x0;
LAB_005c327a:
    local_68[1] = (undefined4 *)0x0;
LAB_005c327d:
    FUN_005ba5c6();
    puVar7 = puVar3;
    goto LAB_005c2d53;
  case 0x6b:
    puVar7 = (undefined4 *)FUN_005c19bf(puVar2,puVar3,local_68[2],local_68[3]);
    goto LAB_005c396f;
  case 0x6d:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "VariableDim";
      goto LAB_005c2cfc;
    }
    goto LAB_005c38a8;
  case 0x6e:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "VariableDim";
      goto LAB_005c35ab;
    }
    goto LAB_005c2d22;
  case 0x6f:
    goto switchD_005c2a9a_caseD_6f;
  case 0x70:
    if ((puVar2 != (undefined4 *)0x0) && (iVar6 = puVar2[2], iVar6 != 0)) {
      iVar4 = *(int *)(iVar6 + 0x18);
      *(undefined4 **)(iVar6 + 0x1c) = puVar3;
      *(undefined4 **)(iVar4 + 0x28) = local_68[2];
      *(undefined4 *)(iVar4 + 0x3c) = 1;
      iVar4 = *(int *)(param_1 + 0xc);
      local_68[1] = (undefined4 *)0x0;
      local_68[2] = (undefined4 *)0x0;
      for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
        for (iVar8 = *(int *)(iVar4 + 0x18); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0xc)) {
          iVar1 = *(int *)(iVar8 + 8);
          if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 5)) &&
             (*(int *)(iVar1 + 0x24) == *(int *)(iVar6 + 0x24))) {
            if (*(int *)(*(int *)(*(int *)(iVar8 + 8) + 0x18) + 0x3c) != 0) {
              FUN_005ba1d9(param_1,*(int *)(iVar6 + 0x14) + 0x10,0xbfd,"\'%s\' already has a body",
                           *(undefined4 *)(*(int *)(iVar6 + 0x14) + 0x18));
            }
            *(undefined4 *)(*(int *)(*(int *)(iVar8 + 8) + 0x18) + 0x3c) = 1;
            goto switchD_005c2a9a_caseD_6f;
          }
        }
      }
    }
switchD_005c2a9a_caseD_6f:
    puVar7 = local_68[0];
    local_68[0] = (undefined4 *)0x0;
    FUN_005ba35f();
    *(undefined4 *)(param_1 + 0x14) = 0;
    goto LAB_005c2d53;
  case 0x71:
    puVar3 = (undefined4 *)FUN_005c094c(puVar3,local_68[2],local_68[3]);
    FUN_005ba2ce(puVar3);
    goto LAB_005c327d;
  case 0x75:
    goto LAB_005c356e;
  case 0x7a:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 == (void *)0x0) goto LAB_005c2c2c;
    uVar9 = 0x10;
LAB_005c329f:
    puVar2 = (undefined4 *)FUN_005d7f48(uVar9,local_68[0]);
LAB_005c2c2e:
    iVar6 = FUN_005ba2ce(puVar2);
    if (iVar6 != 0) {
LAB_005c2c3e:
      local_68[0] = (undefined4 *)0x0;
    }
LAB_005c32c9:
    FUN_005bd1b1(puVar2);
    puVar7 = puVar2;
    goto LAB_005c2d53;
  case 0x7b:
    puVar2[6] = puVar3;
    local_68[1] = (undefined4 *)0x0;
    local_68[0] = (undefined4 *)0x0;
    if ((puVar2[4] & 0x70) == 0) {
      puVar2[4] = puVar2[4] | 0x10;
    }
    goto LAB_005c32c9;
  case 0x80:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x10;
      goto LAB_005c332c;
    }
    break;
  case 0x81:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x20;
      goto LAB_005c332c;
    }
    break;
  case 0x82:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x30;
      goto LAB_005c332c;
    }
    break;
  case 0x83:
    pvVar5 = _malloc(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar9 = 0x50;
      goto LAB_005c332c;
    }
    break;
  case 0x85:
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)FUN_005d78db(0,0,"Stmts");
    }
    iVar6 = FUN_005ba2ce(puVar7);
    if (iVar6 != 0) {
      pvVar5 = _malloc(0x30);
      if (pvVar5 == (void *)0x0) {
        uVar13 = 0;
      }
      else {
        uVar13 = FUN_005d7db0(3,local_68[0],local_68[2],local_68[1]);
      }
      puVar7[2] = uVar13;
      iVar6 = FUN_005ba2ce(uVar13);
      if (iVar6 != 0) {
        local_68[0] = (undefined4 *)0x0;
        local_68[1] = (undefined4 *)0x0;
        local_68[2] = (undefined4 *)0x0;
      }
    }
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
    goto LAB_005c2d53;
  case 0x88:
    FUN_005ba2ff();
    goto switchD_005c2a9a_caseD_2b;
  case 0x8c:
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)FUN_005d78db(0,0,"Passes");
    }
    iVar6 = FUN_005ba2ce(puVar7);
    if (iVar6 != 0) {
      pvVar5 = _malloc(0x30);
      if (pvVar5 == (void *)0x0) {
        uVar13 = 0;
      }
      else {
        uVar13 = FUN_005d7db0(4,local_68[0],local_68[2],local_68[1]);
      }
      puVar7[2] = uVar13;
      iVar6 = FUN_005ba2ce(uVar13);
      if (iVar6 != 0) {
        local_68[0] = (undefined4 *)0x0;
        local_68[1] = (undefined4 *)0x0;
        local_68[2] = (undefined4 *)0x0;
      }
    }
    goto LAB_005c2d53;
  case 0x8f:
    FUN_005ba2ff();
    *(undefined4 *)(param_1 + 0x48) = 0;
switchD_005c2a9a_caseD_2b:
    puVar7 = (undefined4 *)0x0;
    goto LAB_005c2d53;
  case 0x90:
    *(undefined4 *)(param_1 + 0x48) = 1;
switchD_005c2a9a_caseD_51:
    puVar7 = (undefined4 *)0x0;
LAB_005c3547:
    FUN_005ba35f();
    goto LAB_005c2d53;
  case 0x93:
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)FUN_005d78db(0,0,"States");
    }
    iVar6 = FUN_005ba2ce(puVar7);
    if (iVar6 != 0) {
      pvVar5 = _malloc(0x1c);
      if (pvVar5 == (void *)0x0) {
        uVar13 = 0;
      }
      else {
        uVar13 = FUN_005d8c7b(local_68[0],local_68[1],local_68[3]);
      }
      puVar7[2] = uVar13;
      iVar6 = FUN_005ba2ce(uVar13);
      if (iVar6 != 0) {
        local_68[0] = (undefined4 *)0x0;
        local_68[1] = (undefined4 *)0x0;
        local_68[3] = (undefined4 *)0x0;
      }
    }
    goto LAB_005c2d53;
  case 0x96:
    *(undefined4 *)(param_1 + 0x48) = 1;
    goto LAB_005c2d53;
  case 0x97:
    *(undefined4 *)(param_1 + 0x48) = 0;
    goto LAB_005c2d53;
  case 0x9a:
    goto LAB_005c356e;
  case 0xa3:
  case 0xb2:
    puVar7 = (undefined4 *)FUN_005bb22e(puVar2);
    goto LAB_005c2d53;
  case 0xa4:
    puVar2 = (undefined4 *)0x0;
    goto LAB_005c34e7;
  case 0xa5:
LAB_005c34e7:
    puVar7 = (undefined4 *)FUN_005c18f9(puVar2);
    goto LAB_005c2d53;
  case 0xa6:
    puVar7 = puVar2;
    puVar11 = puVar2;
    puVar2 = puVar3;
    goto LAB_005c3502;
  case 0xa7:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "Stmts";
      goto LAB_005c2cfc;
    }
    goto LAB_005c38a8;
  case 0xa9:
  case 0xac:
    puVar7 = (undefined4 *)0x0;
    puVar11 = puVar3;
LAB_005c3502:
    puVar7 = (undefined4 *)FUN_005bb295(puVar7,puVar2,puVar11);
    goto LAB_005c2d53;
  case 0xaa:
  case 0xad:
    puVar7 = (undefined4 *)FUN_005bb295(puVar3,local_68[2],local_68[3],local_68[4]);
    goto LAB_005c3547;
  case 0xae:
    uVar13 = 0;
    goto LAB_005c3554;
  case 0xaf:
    uVar13 = local_68[2];
LAB_005c3554:
    puVar7 = (undefined4 *)FUN_005bfd33(puVar2,puVar3,uVar13);
    goto LAB_005c2d53;
  case 0xb0:
LAB_005c356e:
    FUN_005ba2ff();
    puVar7 = (undefined4 *)0x0;
    goto LAB_005c2d53;
  case 0xb8:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "DwordExpr";
      goto LAB_005c2cfc;
    }
    goto LAB_005c38a8;
  case 0xb9:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "DwordExpr";
      goto LAB_005c35ab;
    }
LAB_005c2d22:
    puVar7 = (undefined4 *)0x0;
LAB_005c2d24:
    iVar6 = FUN_005ba2ce(puVar7);
    if (iVar6 != 0) {
LAB_005c38bc:
      local_68[0] = (undefined4 *)0x0;
      puVar3 = puVar7;
LAB_005c38bf:
      local_68[1] = (undefined4 *)0x0;
      puVar7 = puVar3;
    }
    goto LAB_005c2d53;
  case 0xbf:
    uVar9 = 0x3ff0000000000000;
    uVar13 = 1;
    goto LAB_005c35da;
  case 0xc0:
    uVar9 = 0;
    uVar13 = 0;
LAB_005c35da:
    puVar7 = (undefined4 *)FUN_005bc356(0,uVar13,uVar9,param_1 + 0x20);
    goto LAB_005c396f;
  case 0xc1:
  case 0xc2:
    puVar7 = (undefined4 *)FUN_005bc47a(puVar2);
    goto LAB_005c396f;
  case 0xc3:
    puVar7 = (undefined4 *)FUN_005bc4f9(puVar2);
    goto LAB_005c396f;
  case 0xc4:
    puVar7 = (undefined4 *)FUN_005bedc7();
    goto LAB_005c396f;
  case 0xc6:
  case 199:
    uVar13 = 1;
    goto LAB_005c3703;
  case 200:
    puVar7 = (undefined4 *)FUN_005c238d(puVar2,puVar3,0);
    goto LAB_005c396f;
  case 0xc9:
    puVar2 = (undefined4 *)FUN_005bae82(puVar2);
    puVar3 = puVar2;
    goto LAB_005c2e0f;
  case 0xcb:
    puVar2 = puVar3;
    goto LAB_005c364c;
  case 0xcc:
  case 0xcd:
LAB_005c364c:
    puVar7 = (undefined4 *)FUN_005bcbdd(puVar2);
    goto LAB_005c396f;
  case 0xce:
    uVar13 = 0;
    goto LAB_005c3659;
  case 0xcf:
    puVar7 = (undefined4 *)FUN_005bcd15(puVar2);
    goto LAB_005c396f;
  case 0xd0:
    uVar13 = 1;
LAB_005c3659:
    puVar7 = (undefined4 *)FUN_005c2858(puVar2,puVar3,local_68[2],uVar13);
    goto LAB_005c2d53;
  case 0xd4:
    puVar7 = (undefined4 *)FUN_005c1248();
    goto LAB_005c396f;
  case 0xd5:
    puVar7 = (undefined4 *)FUN_005bc73c();
    goto LAB_005c396f;
  case 0xd6:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 0x21;
    goto LAB_005c38ff;
  case 0xd7:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 0x22;
    goto LAB_005c38ff;
  case 0xd9:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 2;
    goto LAB_005c38ff;
  case 0xda:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 3;
    goto LAB_005c38ff;
  case 0xdb:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 4;
    goto LAB_005c38ff;
  case 0xdc:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 5;
    goto LAB_005c38ff;
  case 0xdd:
    uVar12 = 1;
    uVar10 = ZEXT48(puVar2);
    uVar13 = 6;
    goto LAB_005c38ff;
  case 0xdf:
    uVar13 = 0;
LAB_005c3703:
    puVar7 = (undefined4 *)FUN_005beee7(puVar2,puVar3,uVar13,1);
    goto LAB_005c396f;
  case 0xe1:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 7;
    goto LAB_005c38ff;
  case 0xe2:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 8;
    goto LAB_005c38ff;
  case 0xe3:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 9;
    goto LAB_005c38ff;
  case 0xe5:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 10;
    goto LAB_005c38ff;
  case 0xe6:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0xb;
    goto LAB_005c38ff;
  case 0xe8:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0xc;
    goto LAB_005c38ff;
  case 0xe9:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0xd;
    goto LAB_005c38ff;
  case 0xea:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0xe;
    goto LAB_005c38ff;
  case 0xeb:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0xf;
    goto LAB_005c38ff;
  case 0xed:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x10;
    goto LAB_005c38ff;
  case 0xee:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x11;
    goto LAB_005c38ff;
  case 0xf0:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x12;
    goto LAB_005c38ff;
  case 0xf2:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x13;
    goto LAB_005c38ff;
  case 0xf4:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x15;
    goto LAB_005c38ff;
  case 0xf5:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x1c;
    goto LAB_005c38ff;
  case 0xf6:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x1d;
    goto LAB_005c38ff;
  case 0xf7:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x1e;
    goto LAB_005c38ff;
  case 0xf8:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x1f;
    goto LAB_005c38ff;
  case 0xf9:
    uVar12 = 1;
    uVar10 = CONCAT44(puVar3,puVar2);
    uVar13 = 0x20;
    goto LAB_005c38ff;
  case 0xfb:
    puVar7 = (undefined4 *)FUN_005bf135(puVar2,puVar3,local_68[2]);
    goto LAB_005c396f;
  case 0xfc:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "Arguments";
      goto LAB_005c2cfc;
    }
    goto LAB_005c38a8;
  case 0xfd:
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)FUN_005d78db(local_68[1],0,"Arguments");
    }
    iVar6 = FUN_005ba2ce(puVar7);
    if (iVar6 == 0) goto LAB_005c2d53;
LAB_005c38b2:
    puVar7 = (undefined4 *)FUN_005d7899();
    goto LAB_005c38bc;
  case 0x100:
    pvVar5 = _malloc(0x14);
    if (pvVar5 != (void *)0x0) {
      pcVar14 = "Value";
      goto LAB_005c2cfc;
    }
LAB_005c38a8:
    puVar2 = (undefined4 *)0x0;
LAB_005c2e05:
    puVar3 = (undefined4 *)FUN_005ba2ce(puVar2);
LAB_005c2e0f:
    puVar7 = puVar2;
    if (puVar3 != (undefined4 *)0x0) {
LAB_005c3949:
      local_68[0] = (undefined4 *)0x0;
      puVar7 = puVar2;
    }
    goto LAB_005c2d53;
  case 0x107:
    if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(*(int *)(param_1 + 0xc) + 0x10) == 7)) {
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = puVar2;
      }
      FUN_005ba22d(param_1,puVar3 + 0xc,0xc09,
                   "comma expression used where an initializer list may have been intended");
    }
    uVar12 = 0;
    uVar10 = CONCAT44(local_68[0],local_68[1]);
    uVar13 = 1;
LAB_005c38ff:
    puVar7 = (undefined4 *)FUN_005c1473(uVar13,uVar10,uVar12);
    goto LAB_005c396f;
  case 0x109:
    puVar2[6] = -puVar2[6];
    local_68[0] = (undefined4 *)0x0;
    puVar7 = puVar2;
    goto LAB_005c2d53;
  case 0x10b:
    local_68[0] = (undefined4 *)0x0;
    *(double *)(puVar2 + 6) = -*(double *)(puVar2 + 6);
    puVar7 = puVar2;
    goto LAB_005c2d53;
  case 0x10d:
    puVar7 = (undefined4 *)FUN_005bb43f();
    goto LAB_005c2d53;
  case 0x10f:
  case 0x110:
  case 0x111:
  case 0x117:
  case 0x118:
  case 0x119:
  case 0x11a:
  case 0x11b:
  case 0x11c:
  case 0x11d:
  case 0x11e:
  case 0x11f:
  case 0x120:
    pvVar5 = _malloc(0x30);
    if (pvVar5 == (void *)0x0) break;
    puVar7 = (undefined4 *)FUN_005d7ac2(param_1 + 0x20);
    goto LAB_005c396f;
  case 0x112:
  case 0x113:
    *(undefined4 *)(param_1 + 0x18) = puVar2[6];
    goto LAB_005c3949;
  case 0x121:
    puVar7 = (undefined4 *)FUN_005bb385();
    goto LAB_005c2d53;
  case 0x122:
    uVar13 = 0;
    goto LAB_005c398a;
  case 0x123:
    uVar13 = 1;
LAB_005c398a:
    puVar7 = (undefined4 *)FUN_005bb39e(uVar13);
    goto LAB_005c2d53;
  }
  puVar7 = (undefined4 *)0x0;
LAB_005c396f:
  FUN_005ba2ce(puVar7);
LAB_005c2d53:
  param_2 = 0;
  if (param_3 != 0) {
    do {
      if (local_68[param_2] != (undefined4 *)0x0) {
        (**(code **)*local_68[param_2])(1);
      }
      param_2 = param_2 + 1;
    } while (param_2 < param_3);
  }
  if (*(int *)(param_1 + 0x44) == 0) {
    pvVar5 = _malloc(0x14);
    if (pvVar5 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_005d78db(puVar7,*(undefined4 *)(param_1 + 8),"Stack");
    }
    if (iVar6 == 0) {
      pcVar14 = "internal error: out of memory";
LAB_005c39d6:
      FUN_005ba278(param_1,0,0,pcVar14);
    }
    else {
      *(int *)(param_1 + 8) = iVar6;
    }
  }
  else if (puVar7 != (undefined4 *)0x0) {
    (**(code **)*puVar7)(1);
  }
  return;
switchD_005c2a9a_caseD_49:
  puVar3 = local_68[1];
  goto LAB_005c38bf;
}


// ==== 0x5c3e7d FUN_005c3e7d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c3e7d(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar4 = 0;
  _DAT_00707cb0 = 0;
  DAT_00707cac = 0;
  DAT_00707ca4 = (short *)&DAT_007078b0;
  DAT_00707ca0 = (undefined4 *)&DAT_007070e0;
  _DAT_007078b0 = 0;
LAB_005c3eb7:
  DAT_00707ca8 = -1;
LAB_005c3ebc:
  iVar2 = (int)(short)(&DAT_006d6ea0)[iVar4];
  if (iVar2 == 0) {
    if ((DAT_00707ca8 < 0) && (DAT_00707ca8 = FUN_005bfe5c(), DAT_00707ca8 < 0)) {
      DAT_00707ca8 = 0;
    }
    if (((((short)(&DAT_006d7348)[iVar4] != 0) &&
         (iVar2 = (short)(&DAT_006d7348)[iVar4] + DAT_00707ca8, -1 < iVar2)) && (iVar2 < 0xd22)) &&
       (*(short *)(&DAT_006d95f8 + iVar2 * 2) == DAT_00707ca8)) {
      if (&DAT_00707c96 <= DAT_00707ca4) goto LAB_005c4c53;
      iVar4 = (int)*(short *)(&DAT_006d7bb0 + iVar2 * 2);
      DAT_00707ca4 = DAT_00707ca4 + 1;
      *DAT_00707ca4 = *(short *)(&DAT_006d7bb0 + iVar2 * 2);
      DAT_00707ca0 = DAT_00707ca0 + 1;
      *DAT_00707ca0 = DAT_00707c98;
      DAT_00707ca8 = -1;
      if (0 < DAT_00707cac) {
        DAT_00707cac = DAT_00707cac + -1;
      }
      goto LAB_005c3ebc;
    }
    if ((((short)(&DAT_006d7708)[iVar4] != 0) &&
        (iVar2 = (short)(&DAT_006d7708)[iVar4] + DAT_00707ca8, -1 < iVar2)) &&
       ((iVar2 < 0xd22 && (*(short *)(&DAT_006d95f8 + iVar2 * 2) == DAT_00707ca8)))) {
      iVar2 = (int)*(short *)(&DAT_006d7bb0 + iVar2 * 2);
      goto LAB_005c3fa0;
    }
    if (DAT_00707cac == 0) {
      FUN_005ba0ab(DAT_00707cb8,"syntax error");
      _DAT_00707cb0 = _DAT_00707cb0 + 1;
    }
    if (2 < DAT_00707cac) goto LAB_005c4c47;
    DAT_00707cac = 3;
    while ((((short)(&DAT_006d7348)[*DAT_00707ca4] == 0 ||
            (iVar4 = (short)(&DAT_006d7348)[*DAT_00707ca4] + 0x100, iVar4 < 0)) ||
           ((0xd21 < iVar4 || (*(short *)(&DAT_006d95f8 + iVar4 * 2) != 0x100))))) {
      if (DAT_00707ca4 < (short *)0x7078b1) {
        DAT_00707cac = 3;
        return 1;
      }
      DAT_00707ca4 = DAT_00707ca4 + -1;
      DAT_00707ca0 = DAT_00707ca0 + -1;
    }
    if ((short *)0x707c95 < DAT_00707ca4) goto LAB_005c4c53;
    sVar1 = *(short *)(&DAT_006d7bb0 + iVar4 * 2);
    DAT_00707ca4 = DAT_00707ca4 + 1;
    *DAT_00707ca4 = sVar1;
    uVar6 = DAT_00707c98;
  }
  else {
LAB_005c3fa0:
    iVar4 = (int)*(short *)(&DAT_006d6c58 + iVar2 * 2);
    DAT_00707c9c = DAT_00707ca0[1 - iVar4];
    switch(iVar2) {
    case 1:
      uVar7 = 0;
      uVar6 = 0;
      break;
    case 2:
      uVar7 = 1;
      uVar6 = 1;
      break;
    case 3:
      uVar7 = 1;
      uVar6 = 2;
      break;
    case 4:
      uVar7 = 2;
      uVar6 = 3;
      break;
    case 5:
      uVar7 = 1;
      uVar6 = 4;
      break;
    case 6:
      uVar7 = 1;
      uVar6 = 5;
      break;
    case 7:
      uVar7 = 1;
      uVar6 = 6;
      break;
    case 8:
      uVar7 = 1;
      uVar6 = 7;
      break;
    case 9:
      uVar7 = 1;
      uVar6 = 8;
      break;
    case 10:
      uVar7 = 1;
      uVar6 = 9;
      break;
    case 0xb:
      uVar7 = 2;
      uVar6 = 10;
      break;
    case 0xc:
      uVar7 = 0;
      uVar6 = 0xb;
      break;
    case 0xd:
      uVar7 = 0;
      uVar6 = 0xc;
      break;
    case 0xe:
      uVar7 = 0;
      uVar6 = 0xd;
      break;
    case 0xf:
      uVar7 = 0;
      uVar6 = 0xe;
      break;
    case 0x10:
      uVar7 = 0;
      uVar6 = 0xf;
      break;
    case 0x11:
      uVar7 = 0;
      uVar6 = 0x10;
      break;
    case 0x12:
      uVar7 = 1;
      uVar6 = 0x11;
      break;
    case 0x13:
      uVar7 = 1;
      uVar6 = 0x12;
      break;
    case 0x14:
      uVar7 = 1;
      uVar6 = 0x13;
      break;
    case 0x15:
      uVar7 = 2;
      uVar6 = 0x14;
      break;
    case 0x16:
      uVar7 = 0;
      uVar6 = 0x15;
      break;
    case 0x17:
      uVar7 = 0;
      uVar6 = 0x16;
      break;
    case 0x18:
      uVar7 = 0;
      uVar6 = 0x17;
      break;
    case 0x19:
      uVar7 = 1;
      uVar6 = 0x18;
      break;
    case 0x1a:
      uVar7 = 2;
      uVar6 = 0x19;
      break;
    case 0x1b:
      uVar7 = 1;
      uVar6 = 0x1c;
      break;
    case 0x1c:
      uVar7 = 2;
      uVar6 = 0x1d;
      break;
    case 0x1d:
      uVar7 = 2;
      uVar6 = 0x1e;
      break;
    case 0x1e:
      uVar7 = 2;
      uVar6 = 0x1f;
      break;
    case 0x1f:
      uVar7 = 1;
      uVar6 = 0x20;
      break;
    case 0x20:
      uVar7 = 1;
      uVar6 = 0x21;
      break;
    case 0x21:
      uVar7 = 2;
      uVar6 = 0x22;
      break;
    case 0x22:
      uVar7 = 1;
      uVar6 = 0x23;
      break;
    case 0x23:
      uVar7 = 1;
      uVar6 = 0x24;
      break;
    case 0x24:
      uVar7 = 1;
      uVar6 = 0x25;
      break;
    case 0x25:
      uVar7 = 1;
      uVar6 = 0x26;
      break;
    case 0x26:
      uVar7 = 1;
      uVar6 = 0x27;
      break;
    case 0x27:
      uVar7 = 2;
      uVar6 = 0x28;
      break;
    case 0x28:
      uVar7 = 1;
      uVar6 = 0x29;
      break;
    case 0x29:
      uVar7 = 2;
      uVar6 = 0x2a;
      break;
    case 0x2a:
      uVar7 = 0;
      uVar6 = 0x2b;
      break;
    case 0x2b:
      uVar7 = 1;
      uVar6 = 0x2c;
      break;
    case 0x2c:
      uVar7 = 1;
      uVar6 = 0x2d;
      break;
    case 0x2d:
      uVar7 = 1;
      uVar6 = 0x2e;
      break;
    case 0x2e:
      uVar7 = 1;
      uVar6 = 0x2f;
      break;
    case 0x2f:
      uVar7 = 0;
      uVar6 = 0x30;
      break;
    case 0x30:
      uVar7 = 0;
      uVar6 = 0x31;
      break;
    case 0x31:
      uVar7 = 0;
      uVar6 = 0x32;
      break;
    case 0x32:
      uVar7 = 0;
      uVar6 = 0x33;
      break;
    case 0x33:
      uVar7 = 0;
      uVar6 = 0x34;
      break;
    case 0x34:
      uVar7 = 0;
      uVar6 = 0x35;
      break;
    case 0x35:
      uVar7 = 2;
      uVar6 = 0x36;
      break;
    case 0x36:
      uVar7 = 0;
      uVar6 = 0x37;
      break;
    case 0x37:
      uVar7 = 3;
      uVar6 = 0x38;
      break;
    case 0x38:
      uVar7 = 0;
      uVar6 = 0x39;
      break;
    case 0x39:
      uVar7 = 0;
      uVar6 = 0x3a;
      break;
    case 0x3a:
      uVar7 = 0;
      uVar6 = 0x3b;
      break;
    case 0x3b:
      uVar7 = 0;
      uVar6 = 0x3c;
      break;
    case 0x3c:
      uVar7 = 0;
      uVar6 = 0x3d;
      break;
    case 0x3d:
      uVar7 = 0;
      uVar6 = 0x3e;
      break;
    case 0x3e:
      uVar7 = 0;
      uVar6 = 0x3f;
      break;
    case 0x3f:
      uVar7 = 0;
      uVar6 = 0x40;
      break;
    case 0x40:
      uVar7 = 0;
      uVar6 = 0x41;
      break;
    case 0x41:
      uVar7 = 0;
      uVar6 = 0x42;
      break;
    case 0x42:
      uVar7 = 0;
      uVar6 = 0x43;
      break;
    case 0x43:
      uVar7 = 0;
      uVar6 = 0x44;
      break;
    case 0x44:
      uVar7 = 0;
      uVar6 = 0x45;
      break;
    case 0x45:
      uVar7 = 0;
      uVar6 = 0x46;
      break;
    case 0x46:
      uVar7 = 0;
      uVar6 = 0x47;
      break;
    case 0x47:
      uVar7 = 2;
      uVar6 = 0x48;
      break;
    case 0x48:
      uVar7 = 3;
      uVar6 = 0x49;
      break;
    case 0x49:
      uVar7 = 3;
      uVar6 = 0x4a;
      break;
    case 0x4a:
      uVar7 = 4;
      uVar6 = 0x4b;
      break;
    case 0x4b:
      uVar7 = 1;
      uVar6 = 0x4c;
      break;
    case 0x4c:
      uVar7 = 2;
      uVar6 = 0x4d;
      break;
    case 0x4d:
      uVar7 = 0;
      uVar6 = 0x4e;
      break;
    case 0x4e:
      uVar7 = 1;
      uVar6 = 0x4f;
      break;
    case 0x4f:
      uVar7 = 2;
      uVar6 = 0x50;
      break;
    case 0x50:
      uVar7 = 0;
      uVar6 = 0x51;
      break;
    case 0x51:
      uVar7 = 1;
      uVar6 = 0x52;
      break;
    case 0x52:
      uVar7 = 1;
      uVar6 = 0x53;
      break;
    case 0x53:
      uVar7 = 1;
      uVar6 = 0x54;
      break;
    case 0x54:
      uVar7 = 2;
      uVar6 = 0x55;
      break;
    case 0x55:
      uVar7 = 0;
      uVar6 = 0x56;
      break;
    case 0x56:
      uVar7 = 1;
      uVar6 = 0x57;
      break;
    case 0x57:
      uVar7 = 1;
      uVar6 = 0x58;
      break;
    case 0x58:
      uVar7 = 2;
      uVar6 = 0x59;
      break;
    case 0x59:
      uVar7 = 2;
      uVar6 = 0x5a;
      break;
    case 0x5a:
      uVar7 = 3;
      uVar6 = 0x5b;
      break;
    case 0x5b:
      uVar7 = 0;
      uVar6 = 0x5c;
      break;
    case 0x5c:
      uVar7 = 1;
      uVar6 = 0x5d;
      break;
    case 0x5d:
      uVar7 = 0;
      uVar6 = 0x5e;
      break;
    case 0x5e:
      uVar7 = 1;
      uVar6 = 0x5f;
      break;
    case 0x5f:
      uVar7 = 2;
      uVar6 = 0x60;
      break;
    case 0x60:
      uVar7 = 0;
      uVar6 = 0x61;
      break;
    case 0x61:
      uVar7 = 1;
      uVar6 = 0x62;
      break;
    case 0x62:
      uVar7 = 1;
      uVar6 = 99;
      break;
    case 99:
      uVar7 = 1;
      uVar6 = 100;
      break;
    case 100:
      uVar7 = 0;
      uVar6 = 0x65;
      break;
    case 0x65:
      uVar7 = 1;
      uVar6 = 0x66;
      break;
    case 0x66:
      uVar7 = 2;
      uVar6 = 0x67;
      break;
    case 0x67:
      uVar7 = 2;
      uVar6 = 0x68;
      break;
    case 0x68:
      uVar7 = 1;
      uVar6 = 0x69;
      break;
    case 0x69:
      uVar7 = 2;
      uVar6 = 0x6a;
      break;
    case 0x6a:
      uVar7 = 4;
      uVar6 = 0x6b;
      break;
    case 0x6b:
      uVar7 = 1;
      uVar6 = 0x6c;
      break;
    case 0x6c:
      uVar7 = 1;
      uVar6 = 0x6d;
      break;
    case 0x6d:
      uVar7 = 2;
      uVar6 = 0x6e;
      break;
    case 0x6e:
      uVar7 = 1;
      uVar6 = 0x6f;
      break;
    case 0x6f:
      uVar7 = 3;
      uVar6 = 0x70;
      break;
    case 0x70:
      uVar7 = 4;
      uVar6 = 0x71;
      break;
    case 0x71:
      uVar7 = 2;
      uVar6 = 0x72;
      break;
    case 0x72:
      uVar7 = 2;
      uVar6 = 0x73;
      break;
    case 0x73:
      uVar7 = 3;
      uVar6 = 0x74;
      break;
    case 0x74:
      uVar7 = 0;
      uVar6 = 0x75;
      break;
    case 0x75:
      uVar7 = 0;
      uVar6 = 0x76;
      break;
    case 0x76:
      uVar7 = 1;
      uVar6 = 0x77;
      break;
    case 0x77:
      uVar7 = 2;
      uVar6 = 0x78;
      break;
    case 0x78:
      uVar7 = 2;
      uVar6 = 0x79;
      break;
    case 0x79:
      uVar7 = 1;
      uVar6 = 0x7a;
      break;
    case 0x7a:
      uVar7 = 2;
      uVar6 = 0x7b;
      break;
    case 0x7b:
      uVar7 = 1;
      uVar6 = 0x7e;
      break;
    case 0x7c:
      uVar7 = 2;
      uVar6 = 0x7f;
      break;
    case 0x7d:
      uVar7 = 0;
      uVar6 = 0x80;
      break;
    case 0x7e:
      uVar7 = 0;
      uVar6 = 0x81;
      break;
    case 0x7f:
      uVar7 = 0;
      uVar6 = 0x82;
      break;
    case 0x80:
      uVar7 = 0;
      uVar6 = 0x83;
      break;
    case 0x81:
      uVar7 = 1;
      uVar6 = 0x84;
      break;
    case 0x82:
      uVar7 = 3;
      uVar6 = 0x85;
      break;
    case 0x83:
      uVar7 = 2;
      uVar6 = 0x86;
      break;
    case 0x84:
      uVar7 = 3;
      uVar6 = 0x87;
      break;
    case 0x85:
      uVar7 = 0;
      uVar6 = 0x88;
      break;
    case 0x86:
      uVar7 = 0;
      uVar6 = 0x89;
      break;
    case 0x87:
      uVar7 = 1;
      uVar6 = 0x8a;
      break;
    case 0x88:
      uVar7 = 2;
      uVar6 = 0x8b;
      break;
    case 0x89:
      uVar7 = 3;
      uVar6 = 0x8c;
      break;
    case 0x8a:
      uVar7 = 2;
      uVar6 = 0x8d;
      break;
    case 0x8b:
      uVar7 = 3;
      uVar6 = 0x8e;
      break;
    case 0x8c:
      uVar7 = 0;
      uVar6 = 0x8f;
      break;
    case 0x8d:
      uVar7 = 0;
      uVar6 = 0x90;
      break;
    case 0x8e:
      uVar7 = 1;
      uVar6 = 0x91;
      break;
    case 0x8f:
      uVar7 = 2;
      uVar6 = 0x92;
      break;
    case 0x90:
      uVar7 = 5;
      uVar6 = 0x93;
      break;
    case 0x91:
      uVar7 = 0;
      uVar6 = 0x94;
      break;
    case 0x92:
      uVar7 = 1;
      uVar6 = 0x95;
      break;
    case 0x93:
      uVar7 = 0;
      uVar6 = 0x96;
      break;
    case 0x94:
      uVar7 = 0;
      uVar6 = 0x97;
      break;
    case 0x95:
      uVar7 = 2;
      uVar6 = 0x98;
      break;
    case 0x96:
      uVar7 = 3;
      uVar6 = 0x99;
      break;
    case 0x97:
      uVar7 = 0;
      uVar6 = 0x9a;
      break;
    case 0x98:
      uVar7 = 0;
      uVar6 = 0x9b;
      break;
    case 0x99:
      uVar7 = 1;
      uVar6 = 0x9c;
      break;
    case 0x9a:
      uVar7 = 2;
      uVar6 = 0x9d;
      break;
    case 0x9b:
      uVar7 = 1;
      uVar6 = 0x9e;
      break;
    case 0x9c:
      uVar7 = 1;
      uVar6 = 0x9f;
      break;
    case 0x9d:
      uVar7 = 1;
      uVar6 = 0xa0;
      break;
    case 0x9e:
      uVar7 = 1;
      uVar6 = 0xa1;
      break;
    case 0x9f:
      uVar7 = 0;
      uVar6 = 0xa2;
      break;
    case 0xa0:
      uVar7 = 1;
      uVar6 = 0xa3;
      break;
    case 0xa1:
      uVar7 = 0;
      uVar6 = 0xa4;
      break;
    case 0xa2:
      uVar7 = 1;
      uVar6 = 0xa5;
      break;
    case 0xa3:
      uVar7 = 2;
      uVar6 = 0xa6;
      break;
    case 0xa4:
      uVar7 = 1;
      uVar6 = 0xa7;
      break;
    case 0xa5:
      uVar7 = 1;
      uVar6 = 0xa8;
      break;
    case 0xa6:
      uVar7 = 2;
      uVar6 = 0xa9;
      break;
    case 0xa7:
      uVar7 = 5;
      uVar6 = 0xaa;
      break;
    case 0xa8:
      uVar7 = 1;
      uVar6 = 0xab;
      break;
    case 0xa9:
      uVar7 = 2;
      uVar6 = 0xac;
      break;
    case 0xaa:
      uVar7 = 5;
      uVar6 = 0xad;
      break;
    case 0xab:
      uVar7 = 2;
      uVar6 = 0xae;
      break;
    case 0xac:
      uVar7 = 3;
      uVar6 = 0xaf;
      break;
    case 0xad:
      uVar7 = 0;
      uVar6 = 0xb0;
      break;
    case 0xae:
      uVar7 = 0;
      uVar6 = 0xb1;
      break;
    case 0xaf:
      uVar7 = 1;
      uVar6 = 0xb2;
      break;
    case 0xb0:
      uVar7 = 1;
      uVar6 = 0xb3;
      break;
    case 0xb1:
      uVar7 = 0;
      uVar6 = 0xb4;
      break;
    case 0xb2:
      uVar7 = 1;
      uVar6 = 0xb5;
      break;
    case 0xb3:
      uVar7 = 0;
      uVar6 = 0xb6;
      break;
    case 0xb4:
      uVar7 = 1;
      uVar6 = 0xb7;
      break;
    case 0xb5:
      uVar7 = 1;
      uVar6 = 0xb8;
      break;
    case 0xb6:
      uVar7 = 2;
      uVar6 = 0xb9;
      break;
    case 0xb7:
      uVar7 = 1;
      uVar6 = 0xba;
      break;
    case 0xb8:
      uVar7 = 1;
      uVar6 = 0xbb;
      break;
    case 0xb9:
      uVar7 = 1;
      uVar6 = 0xbc;
      break;
    case 0xba:
      uVar7 = 1;
      uVar6 = 0xbd;
      break;
    case 0xbb:
      uVar7 = 1;
      uVar6 = 0xbe;
      break;
    case 0xbc:
      uVar7 = 0;
      uVar6 = 0xbf;
      break;
    case 0xbd:
      uVar7 = 0;
      uVar6 = 0xc0;
      break;
    case 0xbe:
      uVar7 = 1;
      uVar6 = 0xc1;
      break;
    case 0xbf:
      uVar7 = 1;
      uVar6 = 0xc2;
      break;
    case 0xc0:
      uVar7 = 1;
      uVar6 = 0xc3;
      break;
    case 0xc1:
      uVar7 = 1;
      uVar6 = 0xc4;
      break;
    case 0xc2:
      uVar7 = 1;
      uVar6 = 0xc5;
      break;
    case 0xc3:
      uVar7 = 2;
      uVar6 = 0xc6;
      break;
    case 0xc4:
      uVar7 = 2;
      uVar6 = 199;
      break;
    case 0xc5:
      uVar7 = 2;
      uVar6 = 200;
      break;
    case 0xc6:
      uVar7 = 1;
      uVar6 = 0xc9;
      break;
    case 199:
      uVar7 = 1;
      uVar6 = 0xca;
      break;
    case 200:
      uVar7 = 2;
      uVar6 = 0xcb;
      break;
    case 0xc9:
      uVar7 = 1;
      uVar6 = 0xcc;
      break;
    case 0xca:
      uVar7 = 1;
      uVar6 = 0xcd;
      break;
    case 0xcb:
      uVar7 = 3;
      uVar6 = 0xce;
      break;
    case 0xcc:
      uVar7 = 1;
      uVar6 = 0xcf;
      break;
    case 0xcd:
      uVar7 = 3;
      uVar6 = 0xd0;
      break;
    case 0xce:
      uVar7 = 1;
      uVar6 = 0xd1;
      break;
    case 0xcf:
      uVar7 = 1;
      uVar6 = 0xd2;
      break;
    case 0xd0:
      uVar7 = 1;
      uVar6 = 0xd3;
      break;
    case 0xd1:
      uVar7 = 2;
      uVar6 = 0xd4;
      break;
    case 0xd2:
      uVar7 = 2;
      uVar6 = 0xd5;
      break;
    case 0xd3:
      uVar7 = 1;
      uVar6 = 0xd6;
      break;
    case 0xd4:
      uVar7 = 1;
      uVar6 = 0xd7;
      break;
    case 0xd5:
      uVar7 = 1;
      uVar6 = 0xd8;
      break;
    case 0xd6:
      uVar7 = 1;
      uVar6 = 0xd9;
      break;
    case 0xd7:
      uVar7 = 1;
      uVar6 = 0xda;
      break;
    case 0xd8:
      uVar7 = 1;
      uVar6 = 0xdb;
      break;
    case 0xd9:
      uVar7 = 1;
      uVar6 = 0xdc;
      break;
    case 0xda:
      uVar7 = 1;
      uVar6 = 0xdd;
      break;
    case 0xdb:
      uVar7 = 1;
      uVar6 = 0xde;
      break;
    case 0xdc:
      uVar7 = 2;
      uVar6 = 0xdf;
      break;
    case 0xdd:
      uVar7 = 1;
      uVar6 = 0xe0;
      break;
    case 0xde:
      uVar7 = 2;
      uVar6 = 0xe1;
      break;
    case 0xdf:
      uVar7 = 2;
      uVar6 = 0xe2;
      break;
    case 0xe0:
      uVar7 = 2;
      uVar6 = 0xe3;
      break;
    case 0xe1:
      uVar7 = 1;
      uVar6 = 0xe4;
      break;
    case 0xe2:
      uVar7 = 2;
      uVar6 = 0xe5;
      break;
    case 0xe3:
      uVar7 = 2;
      uVar6 = 0xe6;
      break;
    case 0xe4:
      uVar7 = 1;
      uVar6 = 0xe7;
      break;
    case 0xe5:
      uVar7 = 2;
      uVar6 = 0xe8;
      break;
    case 0xe6:
      uVar7 = 2;
      uVar6 = 0xe9;
      break;
    case 0xe7:
      uVar7 = 2;
      uVar6 = 0xea;
      break;
    case 0xe8:
      uVar7 = 2;
      uVar6 = 0xeb;
      break;
    case 0xe9:
      uVar7 = 1;
      uVar6 = 0xec;
      break;
    case 0xea:
      uVar7 = 2;
      uVar6 = 0xed;
      break;
    case 0xeb:
      uVar7 = 2;
      uVar6 = 0xee;
      break;
    case 0xec:
      uVar7 = 1;
      uVar6 = 0xef;
      break;
    case 0xed:
      uVar7 = 2;
      uVar6 = 0xf0;
      break;
    case 0xee:
      uVar7 = 1;
      uVar6 = 0xf1;
      break;
    case 0xef:
      uVar7 = 2;
      uVar6 = 0xf2;
      break;
    case 0xf0:
      uVar7 = 1;
      uVar6 = 0xfa;
      break;
    case 0xf1:
      uVar7 = 3;
      uVar6 = 0xfb;
      break;
    case 0xf2:
      uVar7 = 1;
      uVar6 = 0xf3;
      break;
    case 0xf3:
      uVar7 = 2;
      uVar6 = 0xf4;
      break;
    case 0xf4:
      uVar7 = 2;
      uVar6 = 0xf5;
      break;
    case 0xf5:
      uVar7 = 2;
      uVar6 = 0xf6;
      break;
    case 0xf6:
      uVar7 = 2;
      uVar6 = 0xf7;
      break;
    case 0xf7:
      uVar7 = 2;
      uVar6 = 0xf8;
      break;
    case 0xf8:
      uVar7 = 2;
      uVar6 = 0xf9;
      break;
    case 0xf9:
      uVar7 = 1;
      uVar6 = 0xfc;
      break;
    case 0xfa:
      uVar7 = 2;
      uVar6 = 0xfd;
      break;
    case 0xfb:
      uVar7 = 0;
      uVar6 = 0xfe;
      break;
    case 0xfc:
      uVar7 = 1;
      uVar6 = 0xff;
      break;
    case 0xfd:
      uVar7 = 1;
      uVar6 = 0x100;
      break;
    case 0xfe:
      uVar7 = 1;
      uVar6 = 0x101;
      break;
    case 0xff:
      uVar7 = 1;
      uVar6 = 0x102;
      break;
    case 0x100:
      uVar7 = 1;
      uVar6 = 0x103;
      break;
    case 0x101:
      uVar7 = 2;
      uVar6 = 0x104;
      break;
    case 0x102:
      uVar7 = 1;
      uVar6 = 0x105;
      break;
    case 0x103:
      uVar7 = 1;
      uVar6 = 0x106;
      break;
    case 0x104:
      uVar7 = 2;
      uVar6 = 0x107;
      break;
    case 0x105:
      uVar7 = 1;
      uVar6 = 0x108;
      break;
    case 0x106:
      uVar7 = 1;
      uVar6 = 0x109;
      break;
    case 0x107:
      uVar7 = 1;
      uVar6 = 0x10a;
      break;
    case 0x108:
      uVar7 = 1;
      uVar6 = 0x10b;
      break;
    case 0x109:
      uVar7 = 1;
      uVar6 = 0x10c;
      break;
    case 0x10a:
      uVar6 = 0x10d;
      uVar7 = 2;
      break;
    case 0x10b:
      uVar6 = 0x10e;
      uVar7 = 1;
      break;
    case 0x10c:
      uVar6 = 0x10f;
      uVar7 = 0;
      break;
    case 0x10d:
      uVar6 = 0x110;
      uVar7 = 0;
      break;
    case 0x10e:
      uVar6 = 0x111;
      uVar7 = 0;
      break;
    case 0x10f:
      uVar6 = 0x112;
      uVar7 = 1;
      break;
    case 0x110:
      uVar6 = 0x113;
      uVar7 = 1;
      break;
    case 0x111:
      uVar6 = 0x114;
      uVar7 = 0;
      break;
    case 0x112:
      uVar6 = 0x115;
      uVar7 = 1;
      break;
    case 0x113:
      uVar6 = 0x116;
      uVar7 = 1;
      break;
    case 0x114:
      uVar6 = 0x117;
      uVar7 = 0;
      break;
    case 0x115:
      uVar6 = 0x118;
      uVar7 = 0;
      break;
    case 0x116:
      uVar6 = 0x119;
      uVar7 = 0;
      break;
    case 0x117:
      uVar6 = 0x11a;
      uVar7 = 0;
      break;
    case 0x118:
      uVar6 = 0x11b;
      uVar7 = 0;
      break;
    case 0x119:
      uVar6 = 0x11c;
      uVar7 = 0;
      break;
    case 0x11a:
      uVar6 = 0x11d;
      uVar7 = 0;
      break;
    case 0x11b:
      uVar6 = 0x11e;
      uVar7 = 0;
      break;
    case 0x11c:
      uVar6 = 0x11f;
      uVar7 = 0;
      break;
    case 0x11d:
      uVar6 = 0x120;
      uVar7 = 0;
      break;
    case 0x11e:
      uVar6 = 0x121;
      uVar7 = 0;
      break;
    case 0x11f:
      uVar6 = 0x122;
      uVar7 = 0;
      break;
    case 0x120:
      uVar6 = 0x123;
      uVar7 = 0;
      break;
    default:
      goto switchD_005c3fd5_default;
    }
    FUN_005c2a3c(uVar6,uVar7);
switchD_005c3fd5_default:
    DAT_00707ca4 = DAT_00707ca4 + -iVar4;
    iVar3 = (int)*DAT_00707ca4;
    DAT_00707ca0 = DAT_00707ca0 + -iVar4;
    iVar4 = (int)*(short *)(iVar2 * 2 + 0x6d6a10);
    if ((iVar3 == 0) && (iVar4 == 0)) {
      DAT_00707ca4 = DAT_00707ca4 + 1;
      iVar4 = 0x26;
      *DAT_00707ca4 = 0x26;
      DAT_00707ca0 = DAT_00707ca0 + 1;
      *DAT_00707ca0 = DAT_00707c9c;
      bVar5 = DAT_00707ca8 == 0;
      if (DAT_00707ca8 < 0) {
        DAT_00707ca8 = FUN_005bfe5c();
        bVar5 = DAT_00707ca8 == 0;
        if (DAT_00707ca8 < 0) {
          DAT_00707ca8 = 0;
          bVar5 = true;
        }
      }
      if (bVar5) {
        return 0;
      }
      goto LAB_005c3ebc;
    }
    iVar4 = iVar4 * 2;
    if ((((*(short *)(&DAT_006d7ac8 + iVar4) == 0) ||
         (iVar2 = *(short *)(&DAT_006d7ac8 + iVar4) + iVar3, iVar2 < 0)) || (0xd21 < iVar2)) ||
       (*(short *)(&DAT_006d95f8 + iVar2 * 2) != iVar3)) {
      sVar1 = *(short *)(&DAT_006d7260 + iVar4);
    }
    else {
      sVar1 = *(short *)(&DAT_006d7bb0 + iVar2 * 2);
    }
    if ((short *)0x707c95 < DAT_00707ca4) {
LAB_005c4c53:
      FUN_005ba0ab(DAT_00707cb8,"yacc stack overflow");
      return 1;
    }
    DAT_00707ca4 = DAT_00707ca4 + 1;
    *DAT_00707ca4 = sVar1;
    uVar6 = DAT_00707c9c;
  }
  iVar4 = (int)sVar1;
  DAT_00707ca0 = DAT_00707ca0 + 1;
  *DAT_00707ca0 = uVar6;
  goto LAB_005c3ebc;
LAB_005c4c47:
  if (DAT_00707ca8 == 0) {
    return 1;
  }
  goto LAB_005c3eb7;
}


// ==== 0x5c50ee FUN_005c50ee

uint __thiscall
FUN_005c50ee(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_4 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_4 = 0;
    if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[2])(1);
    }
    if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[3])(1);
    }
    *param_1 = param_3;
    param_1[1] = param_2;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 1;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    DAT_00707cb8 = param_1;
    uVar1 = FUN_005c564d(1);
    if (-1 < (int)uVar1) {
      FUN_005ba2ff(0,0);
      iVar2 = FUN_005c3e7d();
      if (iVar2 != 0) {
        param_1[0x10] = 1;
      }
      uVar1 = FUN_005c7ed5();
      if (-1 < (int)uVar1) {
        if (param_1[0x10] == 0) {
          *param_4 = *(undefined4 *)(param_1[2] + 8);
          *(undefined4 *)(param_1[2] + 8) = 0;
        }
        uVar1 = -(uint)(param_1[0x10] != 0) & 0x80004005;
      }
    }
  }
  return uVar1;
}


// ==== 0x5c51b2 FUN_005c51b2

void __fastcall FUN_005c51b2(int param_1)

{
  void *_Memory;
  
  if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 4))(1);
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 8))(1);
  }
  _Memory = *(void **)(param_1 + 0xc);
  if (_Memory != (void *)0x0) {
    FUN_005c51b2();
    _free(_Memory);
  }
  return;
}


// ==== 0x5c51e6 FUN_005c51e6

void * __thiscall FUN_005c51e6(void *param_1,byte param_2)

{
  FUN_005c51b2();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5c5202 FUN_005c5202

void __thiscall FUN_005c5202(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ==== 0x5c521c FUN_005c521c

void __fastcall FUN_005c521c(int param_1)

{
  void *_Memory;
  
  _Memory = *(void **)(param_1 + 0xc);
  if (_Memory != (void *)0x0) {
    FUN_005c521c();
    _free(_Memory);
  }
  return;
}


// ==== 0x5c5234 FUN_005c5234

void * __thiscall FUN_005c5234(void *param_1,byte param_2)

{
  FUN_005c521c();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5c5250 FUN_005c5250

int __fastcall FUN_005c5250(int param_1)

{
  FUN_005b19ea();
  FUN_005c7f2f();
  FUN_005d6613();
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  return param_1;
}


// ==== 0x5c5283 FUN_005c5283

void __fastcall FUN_005c5283(int param_1)

{
  void *_Memory;
  int *piVar1;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_005c5234(1);
  }
  _Memory = *(void **)(param_1 + 0x6c);
  if (_Memory != (void *)0x0) {
    FUN_005c5283();
    _free(_Memory);
  }
  piVar1 = *(int **)(param_1 + 0x58);
  if ((piVar1 != (int *)0x0) && (*(int *)(param_1 + 100) != 0)) {
    (**(code **)(*piVar1 + 4))(piVar1,*(int *)(param_1 + 100));
  }
  FUN_005d6620();
  FUN_005c80a3();
  FUN_005d7865();
  return;
}


// ==== 0x5c52d8 FUN_005c52d8

void * __thiscall FUN_005c52d8(void *param_1,byte param_2)

{
  FUN_005c5283();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5c52f4 FUN_005c52f4

uint __thiscall
FUN_005c52f4(int param_1,WCHAR *param_2,LPSTR param_3,undefined4 param_4,undefined4 param_5,
            uint param_6,undefined4 param_7,undefined4 param_8)

{
  char *pcVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  undefined4 *puVar4;
  DWORD nBufferLength;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  WCHAR local_108 [130];
  
  iVar5 = param_6;
  *(uint *)(param_1 + 0x58) = param_6;
  if (param_3 != (LPSTR)0x0) {
    WideCharToMultiByte(0xfde9,0,param_2,-1,(LPSTR)local_108,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
    param_2 = local_108;
  }
  if (iVar5 == 0) {
    nBufferLength = GetFullPathNameA((LPCSTR)param_2,0,(LPSTR)0x0,(LPSTR *)0x0);
    param_6 = nBufferLength + 1;
    iVar5 = FUN_005b1775(param_6);
    *(int *)(param_1 + 0x60) = iVar5;
    if (iVar5 != 0) {
      iVar5 = FUN_005b1775(param_6);
      *(int *)(param_1 + 0x5c) = iVar5;
      if (iVar5 != 0) {
        GetFullPathNameA((LPCSTR)param_2,nBufferLength,*(LPSTR *)(param_1 + 0x60),&param_3);
        *(undefined1 *)(nBufferLength + *(int *)(param_1 + 0x60)) = 0;
        puVar4 = *(undefined4 **)(param_1 + 0x60);
        puVar7 = *(undefined4 **)(param_1 + 0x5c);
        for (uVar6 = param_6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar6 = param_6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (param_3 != (LPSTR)0x0) {
          *param_3 = '\0';
        }
        uVar6 = FUN_005c7f41(*(undefined4 *)(param_1 + 0x5c),0);
        if ((int)uVar6 < 0) {
          FUN_005b1f01(param_5,0,0x5e3,"failed to open source file: \'%s\'",param_2);
          return uVar6;
        }
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x44);
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x48);
        goto LAB_005c5478;
      }
    }
  }
  else {
    pWVar3 = param_2;
    do {
      WVar2 = *pWVar3;
      pWVar3 = (WCHAR *)((int)pWVar3 + 1);
    } while ((char)WVar2 != '\0');
    pcVar1 = (char *)((int)pWVar3 + (1 - ((int)param_2 + 1)));
    puVar4 = (undefined4 *)FUN_005b1775(pcVar1);
    *(undefined4 **)(param_1 + 0x5c) = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      pWVar3 = param_2;
      for (uVar6 = (uint)pcVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar4 = *(undefined4 *)pWVar3;
        pWVar3 = pWVar3 + 2;
        puVar4 = puVar4 + 1;
      }
      for (uVar6 = (uint)pcVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)puVar4 = (char)*pWVar3;
        pWVar3 = (WCHAR *)((int)pWVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      param_6 = (**(code **)**(undefined4 **)(param_1 + 0x58))
                          (*(undefined4 **)(param_1 + 0x58),param_7,*(undefined4 *)(param_1 + 0x5c),
                           param_8,param_1 + 100,param_1 + 0x68);
      if ((int)param_6 < 0) {
        FUN_005b1f01(param_5,0,0x5e3,"failed to open source file: \'%s\'",param_2);
        return param_6;
      }
LAB_005c5478:
      uVar6 = FUN_005b1a04(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x68),
                           *(undefined4 *)(param_1 + 0x5c),1,param_4,param_5);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      return 0;
    }
  }
  return 0x8007000e;
}


// ==== 0x5c549b FUN_005c549b

int __thiscall
FUN_005c549b(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((param_3 == 0) || (param_2 != 0)) {
    *(int *)(param_1 + 100) = param_2;
    *(int *)(param_1 + 0x68) = param_3;
    iVar1 = FUN_005b1a04(param_2,param_3,0,1,param_4,param_5);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x7789f794;
  }
  return iVar1;
}


// ==== 0x5c54d4 FUN_005c54d4

void __fastcall FUN_005c54d4(int param_1)

{
  void *_Memory;
  
  _Memory = *(void **)(param_1 + 4);
  if (_Memory != (void *)0x0) {
    FUN_005c54d4();
    _free(_Memory);
  }
  return;
}


// ==== 0x5c54ec FUN_005c54ec

void * __thiscall FUN_005c54ec(void *param_1,byte param_2)

{
  FUN_005c54d4();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5c5508 FUN_005c5508

int __fastcall FUN_005c5508(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
  FUN_005b1752();
  FUN_005b1797();
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 1;
  *(undefined4 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  pcVar1 = _setlocale(4,(char *)0x0);
  pcVar1 = __strdup(pcVar1);
  *(char **)(param_1 + 0x84) = pcVar1;
  if (pcVar1 != (char *)0x0) {
    iVar3 = 2;
    bVar5 = true;
    pcVar4 = "C";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar1 == *pcVar4;
      pcVar1 = pcVar1 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) goto LAB_005c5588;
  }
  _setlocale(4,"C");
LAB_005c5588:
  uVar2 = __controlfp(0,0);
  *(uint *)(param_1 + 0x88) = uVar2;
  __controlfp(0x10000,0x30000);
  return param_1;
}


// ==== 0x5c55ad FUN_005c55ad

void __fastcall FUN_005c55ad(int param_1)

{
  char *_Locale;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if (*(undefined4 **)(param_1 + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x40))(1);
  }
  if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x44))(1);
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_005c54ec(1);
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_005c52d8(1);
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_005c51e6(1);
  }
  _Locale = *(char **)(param_1 + 0x84);
  if (_Locale != (char *)0x0) {
    iVar1 = 2;
    bVar4 = true;
    pcVar2 = _Locale;
    pcVar3 = "C";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      _setlocale(4,_Locale);
    }
  }
  if (*(void **)(param_1 + 0x84) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x84));
  }
  __controlfp(*(uint *)(param_1 + 0x88),0x30000);
  FUN_005b17b7();
  FUN_005b1758();
  return;
}


// ==== 0x5c564d FUN_005c564d

undefined4 __thiscall FUN_005c564d(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = _malloc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    *puVar1 = param_2;
    puVar1[2] = 1;
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    puVar1[1] = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 **)(param_1 + 0x48) = puVar1;
    *(undefined4 *)(param_1 + 0x80) = param_2;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5c5691 FUN_005c5691

undefined4 __thiscall FUN_005c5691(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x18);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1c);
  }
  return 0;
}


// ==== 0x5c56b6 FUN_005c56b6

undefined4 __thiscall FUN_005c56b6(int param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = *(uint **)(param_1 + 0x50);
  do {
    puVar2 = puVar1;
    puVar1 = (uint *)puVar2[0x1b];
  } while ((uint *)puVar2[0x1b] != (uint *)0x0);
  if (param_2 != (uint *)0x0) {
    *param_2 = *puVar2;
  }
  if (param_3 != (int *)0x0) {
    if (puVar2[1] < *puVar2) {
      *param_3 = 0;
    }
    else {
      *param_3 = puVar2[1] - *puVar2;
    }
  }
  return 0;
}


// ==== 0x5c56ef FUN_005c56ef

int __fastcall FUN_005c56ef(int param_1)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  int *piVar10;
  char *pcVar11;
  bool bVar12;
  
  if ((*(int *)(param_1 + 0x28) != 0) || (*(int *)(param_1 + 0x30) != 0)) {
    *(undefined4 *)(param_1 + 0x60) = 0xc;
    return -1;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x44);
  piVar1 = (int *)(param_1 + 0x60);
  if (puVar4 == (undefined4 *)0x0) {
    iVar5 = FUN_005b291b(*(uint *)(param_1 + 0x80) | 4,piVar1);
    if (iVar5 < 0) {
      return -1;
    }
  }
  else {
    piVar7 = puVar4 + 4;
    piVar10 = piVar1;
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar10 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar10 = piVar10 + 1;
    }
    *(undefined4 *)(param_1 + 0x44) = puVar4[3];
    puVar4[3] = 0;
    (**(code **)*puVar4)(1);
  }
  iVar5 = *piVar1;
  if (iVar5 == 1) {
    cVar2 = *(char *)(param_1 + 0x69);
    if (cVar2 == '\0') {
      return (int)*(char *)(param_1 + 0x68);
    }
    if (*(char *)(param_1 + 0x6a) == '\0') {
      if (cVar2 == '=') {
        cVar2 = *(char *)(param_1 + 0x68);
        if (cVar2 == '!') {
          return 0x113;
        }
        if (cVar2 == '<') {
          return 0x110;
        }
        if (cVar2 == '=') {
          return 0x112;
        }
        if (cVar2 == '>') {
          return 0x111;
        }
      }
      else {
        cVar3 = *(char *)(param_1 + 0x68);
        if (cVar3 == cVar2) {
          if (cVar3 == '&') {
            return 0x114;
          }
          if (cVar3 == '|') {
            return 0x115;
          }
        }
      }
    }
  }
  else if (1 < iVar5) {
    if (iVar5 < 5) {
      return 0x117;
    }
    if (iVar5 == 9) {
      if (*(int *)(param_1 + 0x34) == 0) {
        iVar5 = 8;
        bVar12 = true;
        pcVar9 = *(char **)(param_1 + 0x68);
        pcVar8 = "defined";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar12 = *pcVar9 == *pcVar8;
          pcVar9 = pcVar9 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar12);
        if (bVar12) {
          return 0x10f;
        }
      }
      else {
        pcVar9 = *(char **)(param_1 + 0x68);
        *(undefined4 *)(param_1 + 0x34) = 0;
        if (*(int *)(param_1 + 0x38) == 0) {
          iVar5 = 3;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "if";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10c;
          }
          iVar5 = 6;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "ifdef";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10c;
          }
          iVar5 = 7;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "ifndef";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10c;
          }
          iVar5 = 5;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "else";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10a;
          }
          iVar5 = 6;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "endif";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10b;
          }
          iVar5 = 5;
          bVar12 = true;
          pcVar8 = "elif";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar9 == *pcVar8;
            pcVar9 = pcVar9 + 1;
            pcVar8 = pcVar8 + 1;
          } while (bVar12);
          if (bVar12) {
            piVar1 = *(int **)(*(int *)(param_1 + 0x50) + 0x38);
            if (piVar1 == (int *)0x0) {
              return 0x109;
            }
            if ((piVar1[1] != 0) && (*piVar1 == 0)) {
              return 0x109;
            }
            return 0x10d;
          }
        }
        else {
          iVar5 = 7;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "define";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x101;
          }
          iVar5 = 6;
          bVar12 = true;
          iVar6 = iVar5;
          pcVar8 = pcVar9;
          pcVar11 = "undef";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x102;
          }
          iVar6 = 5;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "line";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x103;
          }
          iVar6 = 8;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "include";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x104;
          }
          bVar12 = true;
          iVar6 = iVar5;
          pcVar8 = pcVar9;
          pcVar11 = "error";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x105;
          }
          iVar6 = 3;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "if";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x106;
          }
          bVar12 = true;
          iVar6 = iVar5;
          pcVar8 = pcVar9;
          pcVar11 = "ifdef";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x107;
          }
          iVar6 = 7;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "ifndef";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x108;
          }
          iVar6 = 5;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "elif";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x109;
          }
          iVar6 = 5;
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "else";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10a;
          }
          bVar12 = true;
          pcVar8 = pcVar9;
          pcVar11 = "endif";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar8 == *pcVar11;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10b;
          }
          iVar5 = 7;
          bVar12 = true;
          pcVar8 = "pragma";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pcVar9 == *pcVar8;
            pcVar9 = pcVar9 + 1;
            pcVar8 = pcVar8 + 1;
          } while (bVar12);
          if (bVar12) {
            return 0x10e;
          }
        }
        *(undefined4 *)(param_1 + 0x34) = 1;
      }
      return 0x116;
    }
    if (iVar5 == 10) {
      return 0x118;
    }
    if ((iVar5 == 0xc) || (iVar5 == 0xd)) {
      *(undefined4 *)(param_1 + 0x28) = 1;
      return -1;
    }
  }
  return 0x119;
}


// ==== 0x5c5a21 FUN_005c5a21

void FUN_005c5a21(int param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  *(undefined4 *)(param_1 + 0x2c) = 1;
  if (*(int *)(param_1 + 0x38) != 0) {
    iVar1 = 0xd;
    bVar4 = true;
    pcVar2 = param_2;
    pcVar3 = "syntax error";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      if ((*(int *)(param_1 + 0x34) == 0) || (*(int *)(param_1 + 0x60) != 9)) {
        FUN_005b212b(0x5dc,param_1 + 0x60);
      }
      else {
        FUN_005b1f01(param_1 + 4,(int *)(param_1 + 0x60),0x5e0,"invalid preprocessor command \'%s\'"
                     ,*(undefined4 *)(param_1 + 0x68));
      }
    }
    else {
      _vsnprintf(local_104,0x100,param_2,&stack0x0000000c);
      local_5 = 0;
      FUN_005b1f01(param_1 + 4,param_1 + 0x60,0,&DAT_006cc568,local_104);
    }
  }
  return;
}


// ==== 0x5c5acd FUN_005c5acd

undefined4 __thiscall FUN_005c5acd(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1c) = param_2;
  if (*(int *)(param_1 + 0x60) != 0xc) {
    piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0x1c);
    *piVar1 = *piVar1 + -1;
  }
  if (param_3 != 0) {
    *(int *)(*(int *)(param_1 + 0x54) + 0x18) = param_3;
  }
  return 0;
}


// ==== 0x5c5af6 FUN_005c5af6

int __fastcall FUN_005c5af6(int param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  void *pvVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  undefined4 uVar9;
  char *pcVar10;
  CHAR local_21c [260];
  byte local_118 [260];
  LPSTR local_14;
  undefined4 local_10;
  int local_c;
  byte *local_8;
  
  piVar1 = (int *)(param_1 + 0x60);
  iVar3 = FUN_005b291b(*(uint *)(param_1 + 0x80) | 0xc,piVar1);
  uVar6 = 0;
  if (iVar3 < 0) {
    return iVar3;
  }
  if (*piVar1 == 10) {
    local_c = 0;
  }
  else {
    if (*piVar1 != 0xb) {
      FUN_005c5a21(param_1,"syntax error");
      return -0x7fffbffb;
    }
    local_c = 1;
  }
  local_8 = *(byte **)(param_1 + 0x68);
  if ((*(int *)(param_1 + 0x58) == 0) && (*(int *)(*(int *)(param_1 + 0x54) + 0x18) == 0)) {
    pcVar10 = "include interface required to support #include from resource or memory";
    uVar9 = 0x5e1;
LAB_005c5b8f:
    FUN_005b1f01(param_1 + 4,piVar1,uVar9,pcVar10);
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 1;
    return -0x7fffbffb;
  }
  iVar3 = *(int *)(param_1 + 0x50);
  if (iVar3 != 0) {
    do {
      iVar3 = *(int *)(iVar3 + 0x6c);
      uVar6 = uVar6 + 1;
    } while (iVar3 != 0);
    if (0x1f < uVar6) {
      pcVar10 = "too many nested #includes";
      uVar9 = 0x5e2;
      goto LAB_005c5b8f;
    }
  }
  if (*(int *)(param_1 + 0x58) == 0) {
    GetFullPathNameA((LPCSTR)local_8,0x104,(LPSTR)local_118,&local_14);
    pbVar4 = local_118;
    pbVar7 = local_8;
    do {
      bVar2 = *pbVar7;
      bVar8 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) {
LAB_005c5bf1:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_005c5bf6;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar7[1];
      bVar8 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_005c5bf1;
      pbVar7 = pbVar7 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_005c5bf6:
    if (iVar3 != 0) {
      _snprintf(local_21c,0x104,&DAT_006cc578,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x60),
                local_8);
      GetFullPathNameA(local_21c,0x104,(LPSTR)local_118,&local_14);
    }
    local_8 = local_118;
  }
  iVar3 = *(int *)(param_1 + 0x50);
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0x58) == 0)) {
    local_10 = 0;
  }
  else {
    local_10 = *(undefined4 *)(iVar3 + 100);
  }
  pvVar5 = _malloc(0x70);
  if (pvVar5 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005c5250();
  }
  if (iVar3 != 0) {
    local_c = FUN_005c52f4(local_8,0,param_1,param_1 + 4,*(undefined4 *)(param_1 + 0x58),local_c,
                           local_10);
    if (-1 < local_c) {
      *(undefined4 *)(iVar3 + 0x6c) = *(undefined4 *)(param_1 + 0x50);
      *(int *)(param_1 + 0x50) = iVar3;
      return 0;
    }
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 1;
    FUN_005c52d8(1);
    return local_c;
  }
  return -0x7ff8fff2;
}


// ==== 0x5c5cbe FUN_005c5cbe

undefined4 __fastcall FUN_005c5cbe(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_108 [256];
  uint local_8;
  
  pcVar5 = (char *)**(undefined4 **)(param_1 + 0x54);
  FUN_005b1a6c();
  if (*(int *)(param_1 + 0x38) != 0) {
    for (; (pcVar5 < (char *)**(uint **)(param_1 + 0x54) && ((*pcVar5 == ' ' || (*pcVar5 == '\t'))))
        ; pcVar5 = pcVar5 + 1) {
    }
    local_8 = 0;
    pcVar4 = pcVar5 + 2;
    pcVar3 = pcVar5 + 1;
    do {
      pcVar2 = (char *)**(undefined4 **)(param_1 + 0x54);
      if (pcVar2 <= pcVar5) break;
      cVar1 = *pcVar5;
      if (cVar1 == '\\') {
        if ((pcVar3 < pcVar2) && (*pcVar3 == '\n')) {
          pcVar5 = pcVar5 + 2;
          pcVar3 = pcVar3 + 2;
          pcVar4 = pcVar4 + 2;
        }
        else {
          if ((pcVar2 <= pcVar4) || ((*pcVar3 != '\r' || (*pcVar4 != '\n')))) goto LAB_005c5d3d;
          pcVar5 = pcVar5 + 3;
          pcVar3 = pcVar3 + 3;
          pcVar4 = pcVar4 + 3;
        }
      }
      else {
LAB_005c5d3d:
        if (cVar1 != '\r') {
          local_108[local_8] = cVar1;
          local_8 = local_8 + 1;
        }
        pcVar5 = pcVar5 + 1;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
    } while (local_8 < 0xff);
    local_108[local_8] = '\0';
    FUN_005b1f01(param_1 + 4,param_1 + 0x60,0,"error: %s",local_108);
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 1;
  }
  return 0;
}


// ==== 0x5c5d94 FUN_005c5d94

undefined4 __thiscall FUN_005c5d94(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  pvVar1 = _malloc(0x10);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005c5202(param_2,*(undefined4 *)(param_1 + 0x38));
  }
  if (iVar2 == 0) {
    uVar3 = 0x8007000e;
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38);
    *(int *)(*(int *)(param_1 + 0x50) + 0x38) = iVar2;
    if ((*(int *)(param_1 + 0x38) == 0) || (param_2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    *(undefined4 *)(param_1 + 0x3c) = uVar3;
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x5c5dec FUN_005c5dec

undefined4 __thiscall FUN_005c5dec(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x50) + 0x38);
  if (piVar1 == (int *)0x0) {
    pcVar3 = "unexpected #elif";
    uVar2 = 0x5e4;
  }
  else {
    if (piVar1[2] == 0) {
      if (((param_2 == 0) || (*piVar1 != 0)) || (piVar1[1] == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      if (param_2 != 0) {
        *piVar1 = 1;
      }
      return 0;
    }
    pcVar3 = "unexpected #elif following #else";
    uVar2 = 0x5e9;
  }
  FUN_005b1f01(param_1 + 4,param_1 + 0x60,uVar2,pcVar3);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  return 0x80004005;
}


// ==== 0x5c5e5f FUN_005c5e5f

undefined4 __fastcall FUN_005c5e5f(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x50) + 0x38);
  if (piVar1 == (int *)0x0) {
    pcVar3 = "unexpected #else";
    uVar2 = 0x5e5;
  }
  else {
    if (piVar1[2] == 0) {
      uVar2 = 0;
      if ((*piVar1 == 0) && (piVar1[1] != 0)) {
        uVar2 = 1;
      }
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      *piVar1 = 1;
      piVar1[2] = 1;
      return 0;
    }
    pcVar3 = "unexpected #else following #else";
    uVar2 = 0x5ea;
  }
  FUN_005b1f01(param_1 + 4,param_1 + 0x60,uVar2,pcVar3);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  return 0x80004005;
}


// ==== 0x5c5ec1 FUN_005c5ec1

undefined4 __fastcall FUN_005c5ec1(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0x38);
  if (iVar1 == 0) {
    FUN_005b1f01(param_1 + 4,param_1 + 0x60,0x5e6,"unexpected #endif");
    *(undefined4 *)(param_1 + 0x2c) = 1;
    return 0x80004005;
  }
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_005c5234(1);
  return 0;
}


// ==== 0x5c5f11 FUN_005c5f11

int __fastcall FUN_005c5f11(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  char *local_4;
  
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar1);
  if (iVar2 < 0) goto LAB_005c6023;
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    iVar3 = 2;
    bVar6 = true;
    pcVar4 = (char *)(param_1 + 0x68);
    pcVar5 = "(";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) goto LAB_005c600d;
    iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar1);
    if (iVar2 < 0) goto LAB_005c6023;
    if (*piVar1 == 9) {
      local_4 = *(char **)(param_1 + 0x68);
      iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar1);
      if (iVar2 < 0) goto LAB_005c6023;
    }
    else {
      local_4 = (char *)0x0;
    }
    iVar2 = *piVar1;
    if (iVar2 != 1) goto LAB_005c600d;
    iVar3 = 2;
    bVar6 = true;
    pcVar4 = (char *)(param_1 + 0x68);
    pcVar5 = ")";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) goto LAB_005c600d;
    iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar1);
    if (iVar2 < 0) goto LAB_005c6023;
    iVar2 = *piVar1;
    if ((iVar2 != 0xc) && (iVar2 != 0xd)) goto LAB_005c600d;
    if (local_4 == (char *)0x0) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    else {
      iVar3 = 10;
      bVar6 = true;
      pcVar4 = local_4;
      pcVar5 = "row_major";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        *(undefined4 *)(param_1 + 0x24) = 0x400;
      }
      else {
        iVar3 = 0xd;
        bVar6 = true;
        pcVar4 = "column_major";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *local_4 == *pcVar4;
          local_4 = local_4 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar6);
        if (!bVar6) goto LAB_005c600d;
        *(undefined4 *)(param_1 + 0x24) = 0x800;
      }
    }
  }
  else {
LAB_005c600d:
    if ((iVar2 != 0xc) && (iVar2 != 0xd)) {
      FUN_005b1a6c();
    }
  }
  iVar2 = 0;
LAB_005c6023:
  *(undefined4 *)(param_1 + 0x28) = 1;
  return iVar2;
}


// ==== 0x5c602e FUN_005c602e

int __fastcall FUN_005c602e(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  bool bVar11;
  uint local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
  if (iVar2 < 0) goto LAB_005c632d;
  if (*(int *)(param_1 + 0x60) == 1) {
    iVar2 = 2;
    bVar11 = true;
    pcVar8 = (char *)(param_1 + 0x68);
    pcVar7 = "(";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar11 = *pcVar8 == *pcVar7;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar11);
    if (bVar11) {
      iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),param_1 + 0x60);
      if (iVar2 < 0) goto LAB_005c632d;
      local_8 = 0;
      do {
        do {
          do {
            iVar2 = *(int *)(param_1 + 0x60);
            if (iVar2 == 1) {
              iVar5 = 2;
              bVar11 = true;
              pcVar8 = (char *)(param_1 + 0x68);
              pcVar7 = ")";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar11 = *pcVar8 == *pcVar7;
                pcVar8 = pcVar8 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar11);
              if (bVar11) {
                iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
                if (iVar2 < 0) goto LAB_005c632d;
                iVar2 = *(int *)(param_1 + 0x60);
                if ((iVar2 == 0xc) || (iVar2 == 0xd)) {
                  local_18 = 0;
                  if (local_8 == 0) goto LAB_005c632b;
                  puVar3 = local_10;
                  goto LAB_005c6393;
                }
                goto LAB_005c6316;
              }
            }
            if (iVar2 == 9) {
              pcVar8 = *(char **)(param_1 + 0x68);
              iVar2 = 5;
              bVar11 = true;
              pcVar7 = pcVar8;
              pcVar9 = "once";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar11 = *pcVar7 == *pcVar9;
                pcVar7 = pcVar7 + 1;
                pcVar9 = pcVar9 + 1;
              } while (bVar11);
              if (bVar11) {
                local_14 = 0x10;
              }
              else {
                iVar2 = 6;
                bVar11 = true;
                pcVar7 = pcVar8;
                pcVar9 = "error";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar11 = *pcVar7 == *pcVar9;
                  pcVar7 = pcVar7 + 1;
                  pcVar9 = pcVar9 + 1;
                } while (bVar11);
                if (bVar11) {
                  local_14 = 0xf;
                }
                else {
                  iVar2 = 8;
                  bVar11 = true;
                  pcVar7 = pcVar8;
                  pcVar9 = "disable";
                  do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar11 = *pcVar7 == *pcVar9;
                    pcVar7 = pcVar7 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar11);
                  if (bVar11) {
                    local_14 = 0;
                  }
                  else {
                    iVar2 = 8;
                    bVar11 = true;
                    pcVar7 = "default";
                    do {
                      if (iVar2 == 0) break;
                      iVar2 = iVar2 + -1;
                      bVar11 = *pcVar8 == *pcVar7;
                      pcVar8 = pcVar8 + 1;
                      pcVar7 = pcVar7 + 1;
                    } while (bVar11);
                    if (!bVar11) goto LAB_005c6316;
                    local_14 = 0xff;
                  }
                }
              }
            }
            else if ((((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) ||
                    ((local_14 = *(uint *)(param_1 + 0x68), local_14 == 0 || (4 < local_14))))
            goto LAB_005c6316;
            iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
            if (iVar2 < 0) goto LAB_005c632d;
            if (*(int *)(param_1 + 0x60) != 1) goto LAB_005c6316;
            iVar2 = 2;
            bVar11 = true;
            pcVar8 = (char *)(param_1 + 0x68);
            pcVar7 = ":";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar11 = *pcVar8 == *pcVar7;
              pcVar8 = pcVar8 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar11);
            if (!bVar11) goto LAB_005c6316;
            iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),param_1 + 0x60);
            if (iVar2 < 0) goto LAB_005c632d;
            do {
              do {
                iVar2 = *(int *)(param_1 + 0x60);
                if (((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) goto LAB_005c6316;
                uVar1 = *(undefined4 *)(param_1 + 0x68);
                if (local_8 == (~local_8 + 1 & local_8)) {
                  if (local_8 == 0) {
                    iVar2 = 1;
                  }
                  else {
                    iVar2 = local_8 * 2;
                  }
                  puVar3 = _malloc(iVar2 << 2);
                  if (puVar3 != (undefined4 *)0x0) {
                    puVar4 = local_c;
                    puVar10 = puVar3;
                    for (uVar6 = local_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                      *puVar10 = *puVar4;
                      puVar4 = puVar4 + 1;
                      puVar10 = puVar10 + 1;
                    }
                    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                      *(undefined1 *)puVar10 = *(undefined1 *)puVar4;
                      puVar4 = (undefined4 *)((int)puVar4 + 1);
                      puVar10 = (undefined4 *)((int)puVar10 + 1);
                    }
                    _free(local_c);
                    if (local_8 == 0) {
                      iVar2 = 1;
                    }
                    else {
                      iVar2 = local_8 * 2;
                    }
                    puVar4 = _malloc(iVar2 << 2);
                    local_c = puVar3;
                    if (puVar4 != (undefined4 *)0x0) {
                      puVar3 = local_10;
                      puVar10 = puVar4;
                      for (uVar6 = local_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                        *puVar10 = *puVar3;
                        puVar3 = puVar3 + 1;
                        puVar10 = puVar10 + 1;
                      }
                      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                        *(undefined1 *)puVar10 = *(undefined1 *)puVar3;
                        puVar3 = (undefined4 *)((int)puVar3 + 1);
                        puVar10 = (undefined4 *)((int)puVar10 + 1);
                      }
                      _free(local_10);
                      local_10 = puVar4;
                      goto LAB_005c6269;
                    }
                  }
                  iVar2 = -0x7ff8fff2;
                  goto LAB_005c632d;
                }
LAB_005c6269:
                local_10[local_8] = uVar1;
                local_c[local_8] = local_14;
                local_8 = local_8 + 1;
                iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
                if (iVar2 < 0) goto LAB_005c632d;
              } while (*(int *)(param_1 + 0x60) != 1);
              iVar2 = 2;
              bVar11 = true;
              pcVar8 = (char *)(param_1 + 0x68);
              pcVar7 = ";";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar11 = *pcVar8 == *pcVar7;
                pcVar8 = pcVar8 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar11);
              if (bVar11) break;
              iVar2 = 2;
              bVar11 = true;
              pcVar8 = (char *)(param_1 + 0x68);
              pcVar7 = ")";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar11 = *pcVar8 == *pcVar7;
                pcVar8 = pcVar8 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar11);
            } while (!bVar11);
            iVar2 = 2;
            bVar11 = true;
            pcVar8 = (char *)(param_1 + 0x68);
            pcVar7 = ";";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar11 = *pcVar8 == *pcVar7;
              pcVar8 = pcVar8 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar11);
          } while (!bVar11);
          iVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
          if (iVar2 < 0) goto LAB_005c632d;
        } while (*(int *)(param_1 + 0x60) != 1);
        iVar2 = 2;
        bVar11 = true;
        pcVar8 = (char *)(param_1 + 0x68);
        pcVar7 = ")";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar11 = *pcVar8 == *pcVar7;
          pcVar8 = pcVar8 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar11);
      } while (!bVar11);
    }
  }
LAB_005c6316:
  if ((*(int *)(param_1 + 0x60) != 0xc) && (*(int *)(param_1 + 0x60) != 0xd)) {
    FUN_005b1a6c();
  }
  goto LAB_005c632b;
  while( true ) {
    local_18 = local_18 + 1;
    puVar3 = puVar3 + 1;
    if (local_8 <= local_18) break;
LAB_005c6393:
    iVar2 = FUN_005b1e99(*puVar3,*(undefined4 *)(((int)local_c - (int)local_10) + (int)puVar3));
    if (iVar2 < 0) goto LAB_005c632d;
  }
LAB_005c632b:
  iVar2 = 0;
LAB_005c632d:
  _free(local_c);
  _free(local_10);
  _free((void *)0x0);
  *(undefined4 *)(param_1 + 0x28) = 1;
  return iVar2;
}


// ==== 0x5c63c3 FUN_005c63c3

undefined4 FUN_005c63c3(char *param_1)

{
  if (param_1 != (char *)0x0) {
    for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    }
  }
  return 0;
}


// ==== 0x5c63d8 FUN_005c63d8

undefined4 FUN_005c63d8(undefined4 *param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int extraout_ECX;
  byte *pbVar5;
  bool bVar6;
  
  iVar3 = FUN_005c63c3(*param_1);
  piVar1 = (int *)(extraout_ECX + 0x4c + iVar3 * 4);
  iVar3 = *piVar1;
  do {
    if (iVar3 == 0) {
LAB_005c6444:
      param_1[3] = *piVar1;
      *piVar1 = (int)param_1;
      return 0;
    }
    pbVar4 = *(byte **)*piVar1;
    pbVar5 = (byte *)*param_1;
    do {
      bVar2 = *pbVar5;
      bVar6 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) {
LAB_005c641b:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_005c6420;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar6 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_005c641b;
      pbVar5 = pbVar5 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_005c6420:
    if (iVar3 < 0) goto LAB_005c6444;
    if (iVar3 == 0) {
      iVar3 = *piVar1;
      *piVar1 = *(int *)(iVar3 + 0xc);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_005c51e6(1);
      goto LAB_005c6444;
    }
    piVar1 = (undefined4 *)*piVar1 + 3;
    iVar3 = *piVar1;
  } while( true );
}


// ==== 0x5c6455 FUN_005c6455

undefined4 FUN_005c6455(byte *param_1,undefined4 *param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  int extraout_ECX;
  byte *pbVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar2 = FUN_005c63c3(param_1);
  puVar4 = *(undefined4 **)(extraout_ECX + 0x4c + iVar2 * 4);
  do {
    if (puVar4 == (undefined4 *)0x0) {
      return 0;
    }
    pbVar3 = (byte *)*puVar4;
    pbVar5 = param_1;
    do {
      bVar1 = *pbVar5;
      bVar6 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_005c648e:
        iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_005c6493;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar6 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_005c648e;
      pbVar5 = pbVar5 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_005c6493:
    if (iVar2 < 0) {
      return 0;
    }
    if (iVar2 == 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = puVar4[1];
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = puVar4[2];
      }
      return 1;
    }
    puVar4 = (undefined4 *)puVar4[3];
  } while( true );
}


// ==== 0x5c64c6 FUN_005c64c6

void FUN_005c64c6(char *param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = false;
  bVar2 = false;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (*param_1 == '\"') {
      if (param_3 != 0) {
        *(undefined1 *)(iVar3 + param_3) = 0x5c;
      }
      iVar3 = iVar3 + 1;
      if (!bVar1) {
        bVar2 = !bVar2;
      }
    }
    bVar1 = false;
    if ((bVar2) && (*param_1 == '\\')) {
      if (param_3 != 0) {
        *(undefined1 *)(iVar3 + param_3) = 0x5c;
      }
      iVar3 = iVar3 + 1;
      bVar1 = true;
    }
    if (param_3 != 0) {
      *(char *)(iVar3 + param_3) = *param_1;
    }
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== 0x5c652b FUN_005c652b

int __thiscall FUN_005c652b(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x2c) == 0) {
      FUN_005b1f01(param_1 + 4,param_1 + 0x60,0,"internal error: production failed");
      *(undefined4 *)(param_1 + 0x2c) = 1;
    }
    param_2 = 0;
  }
  return param_2;
}


// ==== 0x5c655e FUN_005c655e

int __thiscall FUN_005c655e(int param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  int *piVar10;
  byte *pbVar11;
  char *pcVar12;
  int *piVar13;
  bool bVar14;
  
  puVar3 = _malloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    param_2 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = param_2;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    param_2 = puVar3;
  }
  if (param_2 != (undefined4 *)0x0) {
    if (((param_3 != (int *)0x0) &&
        (pcVar9 = (char *)**(undefined4 **)(param_1 + 0x54),
        pcVar9 < (char *)(*(undefined4 **)(param_1 + 0x54))[1])) && (*pcVar9 == '(')) {
      piVar6 = (int *)(param_1 + 0x60);
      iVar4 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar6);
      param_3 = param_2 + 1;
      if (iVar4 < 0) goto LAB_005c67b3;
      do {
        iVar4 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar6);
        if (iVar4 < 0) goto LAB_005c67b3;
        if (*piVar6 != 9) goto LAB_005c66ce;
        for (iVar4 = param_2[1]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
          pbVar8 = *(byte **)(iVar4 + 0x18);
          pbVar11 = *(byte **)(param_1 + 0x68);
          do {
            bVar2 = *pbVar11;
            bVar14 = bVar2 < *pbVar8;
            if (bVar2 != *pbVar8) {
LAB_005c6631:
              iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
              goto LAB_005c6636;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar11[1];
            bVar14 = bVar2 < pbVar8[1];
            if (bVar2 != pbVar8[1]) goto LAB_005c6631;
            pbVar11 = pbVar11 + 2;
            pbVar8 = pbVar8 + 2;
          } while (bVar2 != 0);
          iVar7 = 0;
LAB_005c6636:
          if (iVar7 == 0) {
            FUN_005b1f01(param_1 + 4,piVar6,0x5e7,"duplicate macro parameter \'%s\'",
                         *(undefined4 *)(param_1 + 0x68));
            break;
          }
        }
        pvVar5 = _malloc(0x30);
        if (pvVar5 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005d7ac2(piVar6);
        }
        *param_3 = iVar4;
        if (iVar4 == 0) goto LAB_005c678d;
        param_3 = (int *)(iVar4 + 0xc);
        iVar4 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar6);
        if (iVar4 < 0) goto LAB_005c67b3;
        if (*piVar6 != 1) goto LAB_005c66ce;
        iVar4 = 2;
        bVar14 = true;
        pcVar9 = ",";
        pcVar12 = (char *)(param_1 + 0x68);
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar14 = *pcVar9 == *pcVar12;
          pcVar9 = pcVar9 + 1;
          pcVar12 = pcVar12 + 1;
        } while (bVar14);
      } while (bVar14);
      iVar4 = 2;
      bVar14 = true;
      pcVar9 = ")";
      pcVar12 = (char *)(param_1 + 0x68);
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar14 = *pcVar9 == *pcVar12;
        pcVar9 = pcVar9 + 1;
        pcVar12 = pcVar12 + 1;
      } while (bVar14);
      if (!bVar14) {
LAB_005c66ce:
        if ((*piVar6 == 0xc) || (*piVar6 == 0xd)) {
          *(undefined4 *)(param_1 + 0x28) = 1;
        }
        FUN_005b212b(0x5dc,piVar6);
        *(undefined4 *)(param_1 + 0x2c) = 1;
        iVar4 = -0x7fffbffb;
        goto LAB_005c67b3;
      }
    }
    piVar6 = param_2 + 2;
    while( true ) {
      puVar3 = *(undefined4 **)(param_1 + 0x44);
      piVar1 = (int *)(param_1 + 0x60);
      if (puVar3 == (undefined4 *)0x0) {
        iVar4 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar1);
        if (iVar4 < 0) goto LAB_005c67b3;
      }
      else {
        piVar10 = puVar3 + 4;
        piVar13 = piVar1;
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar13 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar13 = piVar13 + 1;
        }
        *(undefined4 *)(param_1 + 0x44) = puVar3[3];
        puVar3[3] = 0;
        (**(code **)*puVar3)(1);
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x18);
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1c);
      }
      if ((*piVar1 == 0xc) || (*piVar1 == 0xd)) {
        *(undefined4 *)(param_1 + 0x28) = 1;
        iVar4 = FUN_005c63d8(param_2);
        if (-1 < iVar4) {
          param_2 = (undefined4 *)0x0;
          iVar4 = 0;
        }
        goto LAB_005c67b3;
      }
      pvVar5 = _malloc(0x30);
      if (pvVar5 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005d7ac2(piVar1);
      }
      *piVar6 = iVar4;
      if (iVar4 == 0) break;
      piVar6 = (int *)(iVar4 + 0xc);
    }
  }
LAB_005c678d:
  iVar4 = -0x7ff8fff2;
LAB_005c67b3:
  if (param_2 != (undefined4 *)0x0) {
    FUN_005c51e6(1);
  }
  return iVar4;
}


// ==== 0x5c67cc FUN_005c67cc

undefined4 FUN_005c67cc(byte *param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int extraout_ECX;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar3 = FUN_005c63c3(param_1);
  piVar1 = (int *)(extraout_ECX + 0x4c + iVar3 * 4);
  iVar3 = *piVar1;
  do {
    if (iVar3 == 0) {
      return 0;
    }
    pbVar4 = *(byte **)*piVar1;
    pbVar5 = param_1;
    do {
      bVar2 = *pbVar5;
      bVar6 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) {
LAB_005c680b:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_005c6810;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar6 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_005c680b;
      pbVar5 = pbVar5 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_005c6810:
    if (iVar3 < 0) {
      return 0;
    }
    if (iVar3 == 0) {
      iVar3 = *piVar1;
      *piVar1 = *(int *)(iVar3 + 0xc);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_005c51e6(1);
      return 0;
    }
    piVar1 = (undefined4 *)*piVar1 + 3;
    iVar3 = *piVar1;
  } while( true );
}


// ==== 0x5c683a FUN_005c683a

int __fastcall FUN_005c683a(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  iVar1 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_1 + 0x60);
    if (iVar1 == 9) {
      iVar2 = 0xc;
      bVar5 = true;
      pcVar3 = *(char **)(param_1 + 0x68);
      pcVar4 = "pack_matrix";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        iVar1 = FUN_005c5f11();
        return iVar1;
      }
      iVar2 = 8;
      bVar5 = true;
      pcVar3 = *(char **)(param_1 + 0x68);
      pcVar4 = "warning";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        iVar1 = FUN_005c602e();
        return iVar1;
      }
    }
    if ((iVar1 != 0xc) && (iVar1 != 0xd)) {
      FUN_005b1a6c();
    }
    iVar1 = 0;
  }
  *(undefined4 *)(param_1 + 0x28) = 1;
  return iVar1;
}


// ==== 0x5c68b4 FUN_005c68b4

undefined4 __thiscall FUN_005c68b4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = param_1;
  iVar1 = FUN_005c6455(param_2,&param_2,&local_8);
  if (iVar1 == 0) {
LAB_005c68fe:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (local_8 == 0) goto LAB_005c68fe;
      if (((*(int *)(local_8 + 0xc) == 0) && (1 < *(int *)(local_8 + 0x10))) &&
         (*(int *)(local_8 + 0x10) < 5)) {
        return *(undefined4 *)(local_8 + 0x18);
      }
    }
    else {
      FUN_005b1f01(param_1 + 4,param_1 + 0x60,0x5ed,
                   "functional defines in preprocessor expressions not yet implemented");
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ==== 0x5c691a FUN_005c691a

undefined4 __thiscall
FUN_005c691a(int param_1,undefined4 **param_2,int param_3,undefined4 **param_4)

{
  byte bVar1;
  void *pvVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  uint uVar12;
  undefined4 **ppuVar13;
  undefined4 **ppuVar14;
  byte *pbVar15;
  undefined4 *puVar16;
  int *piVar17;
  byte *pbVar18;
  undefined4 *puVar19;
  undefined4 uVar20;
  bool bVar21;
  undefined1 local_44 [32];
  undefined4 **local_24;
  undefined4 **local_20;
  undefined4 **local_1c;
  undefined4 *local_18;
  int *local_14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  local_18 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_8 = param_1;
  if (param_3 == 0) {
    ppuVar13 = &local_c;
    while( true ) {
      if (param_4 == (undefined4 **)0x0) {
        *ppuVar13 = *(undefined4 **)(param_1 + 0x44);
        *(undefined4 **)(param_1 + 0x44) = local_c;
        return 1;
      }
      pvVar2 = _malloc(0x30);
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)FUN_005d7ac2(param_4 + 4);
      }
      *ppuVar13 = puVar3;
      if (puVar3 == (undefined4 *)0x0) break;
      param_4 = (undefined4 **)param_4[3];
      ppuVar13 = (undefined4 **)(puVar3 + 3);
    }
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x44);
    if (puVar3 == (undefined4 *)0x0) {
      pcVar4 = (char *)**(undefined4 **)(param_1 + 0x54);
      if (((char *)(*(undefined4 **)(param_1 + 0x54))[1] <= pcVar4) || (*pcVar4 == '(')) {
        piVar5 = (int *)(param_1 + 0x60);
        local_14 = piVar5;
        iVar7 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),piVar5);
        if ((-1 < iVar7) && (*piVar5 == 1)) {
          local_20 = (undefined4 **)(local_8 + 0x68);
          iVar7 = 2;
          bVar21 = true;
          ppuVar13 = local_20;
          pcVar4 = "(";
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar21 = *(char *)ppuVar13 == *pcVar4;
            ppuVar13 = (undefined4 **)((int)ppuVar13 + 1);
            pcVar4 = pcVar4 + 1;
          } while (bVar21);
          if (bVar21) goto LAB_005c6a27;
        }
      }
    }
    else {
      local_14 = (int *)(param_1 + 0x60);
      piVar5 = puVar3 + 4;
      piVar17 = local_14;
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar17 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar17 = piVar17 + 1;
      }
      if (*local_14 == 1) {
        local_20 = (undefined4 **)(param_1 + 0x68);
        iVar7 = 2;
        bVar21 = true;
        ppuVar13 = local_20;
        pcVar4 = "(";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar21 = *(char *)ppuVar13 == *pcVar4;
          ppuVar13 = (undefined4 **)((int)ppuVar13 + 1);
          pcVar4 = pcVar4 + 1;
        } while (bVar21);
        if (bVar21) {
          *(undefined4 *)(param_1 + 0x44) = puVar3[3];
          puVar3[3] = 0;
          (**(code **)*puVar3)(1);
LAB_005c6a27:
          local_1c = (undefined4 **)0x0;
          local_24 = &local_18;
          local_10 = 1;
          iVar7 = local_8;
          piVar5 = local_14;
          do {
            puVar3 = *(undefined4 **)(iVar7 + 0x44);
            if (puVar3 == (undefined4 *)0x0) {
              iVar8 = FUN_005b291b(*(undefined4 *)(iVar7 + 0x80),piVar5);
              iVar7 = local_8;
              if (iVar8 < 0) goto LAB_005c6fc4;
            }
            else {
              piVar5 = puVar3 + 4;
              piVar17 = local_14;
              for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
                *piVar17 = *piVar5;
                piVar5 = piVar5 + 1;
                piVar17 = piVar17 + 1;
              }
              *(undefined4 *)(iVar7 + 0x44) = puVar3[3];
              puVar3[3] = 0;
              (**(code **)*puVar3)(1);
            }
            piVar5 = local_14;
            ppuVar13 = local_24;
            if (*local_14 == 0xd) {
              FUN_005b1f01(iVar7 + 4,param_2,0x5eb,"unexpected end of file in macro expansion");
              goto LAB_005c6fc4;
            }
            if (*local_24 == (undefined4 *)0x0) {
              pvVar2 = _malloc(0x14);
              if (pvVar2 == (void *)0x0) {
                puVar3 = (undefined4 *)0x0;
              }
              else {
                puVar3 = (undefined4 *)FUN_005d78db(0,0,&DAT_006a0548);
              }
              *ppuVar13 = puVar3;
              if (puVar3 == (undefined4 *)0x0) goto LAB_005c6fc4;
              local_1c = (undefined4 **)(puVar3 + 2);
            }
            if ((((local_10 == 1) && (*piVar5 == 1)) &&
                ((*(char *)local_20 == ',' || (*(char *)local_20 == ')')))) &&
               (*(char *)(iVar7 + 0x69) == '\0')) {
              local_24 = (undefined4 **)(*ppuVar13 + 3);
            }
            else {
              pvVar2 = _malloc(0x30);
              if (pvVar2 == (void *)0x0) {
                puVar3 = (undefined4 *)0x0;
              }
              else {
                puVar3 = (undefined4 *)FUN_005d7ac2(piVar5);
              }
              *local_1c = puVar3;
              if (puVar3 == (undefined4 *)0x0) goto LAB_005c6fc4;
              local_1c = (undefined4 **)(puVar3 + 3);
              iVar7 = local_8;
              piVar5 = local_14;
            }
            if ((*piVar5 == 1) && (*(char *)(iVar7 + 0x69) == '\0')) {
              cVar11 = *(char *)local_20;
              if (cVar11 == '(') {
LAB_005c6b4b:
                local_10 = local_10 + 1;
              }
              else {
                if (cVar11 != ')') {
                  if (cVar11 == '[') goto LAB_005c6b4b;
                  if (cVar11 != ']') {
                    if (cVar11 == '{') goto LAB_005c6b4b;
                    if (cVar11 != '}') goto LAB_005c6b4e;
                  }
                }
                local_10 = local_10 + -1;
              }
            }
LAB_005c6b4e:
            puVar3 = local_18;
            iVar8 = param_3;
          } while (local_10 != 0);
          do {
            if ((puVar3 == (undefined4 *)0x0) || (puVar3[2] == 0)) break;
            iVar8 = *(int *)(iVar8 + 0xc);
            puVar3 = (undefined4 *)puVar3[3];
          } while (iVar8 != 0);
          if ((iVar8 == 0) && (puVar3 == (undefined4 *)0x0)) {
            param_2 = &local_c;
            local_14 = (int *)0x0;
            local_10 = 0;
            local_20 = (undefined4 **)0x0;
            for (local_24 = param_4; local_24 != (undefined4 **)0x0;
                local_24 = (undefined4 **)local_24[3]) {
              ppuVar13 = local_24 + 4;
              local_1c = param_2;
              if ((local_14 == (int *)0x0) && (local_10 == 0)) {
                if (*ppuVar13 != (undefined4 *)0x1) {
LAB_005c6bfa:
                  if (*ppuVar13 == (undefined4 *)0x1) {
                    iVar7 = 3;
                    bVar21 = true;
                    ppuVar14 = local_24 + 6;
                    pcVar4 = "#@";
                    do {
                      if (iVar7 == 0) break;
                      iVar7 = iVar7 + -1;
                      bVar21 = *(char *)ppuVar14 == *pcVar4;
                      ppuVar14 = (undefined4 **)((int)ppuVar14 + 1);
                      pcVar4 = pcVar4 + 1;
                    } while (bVar21);
                    if (bVar21) {
                      local_10 = 1;
                      local_20 = ppuVar13;
                      goto LAB_005c6e23;
                    }
                  }
                  goto LAB_005c6c1a;
                }
                iVar7 = 2;
                bVar21 = true;
                ppuVar14 = local_24 + 6;
                pcVar4 = "#";
                do {
                  if (iVar7 == 0) break;
                  iVar7 = iVar7 + -1;
                  bVar21 = *(char *)ppuVar14 == *pcVar4;
                  ppuVar14 = (undefined4 **)((int)ppuVar14 + 1);
                  pcVar4 = pcVar4 + 1;
                } while (bVar21);
                if (!bVar21) goto LAB_005c6bfa;
                local_14 = (int *)0x1;
                local_20 = ppuVar13;
              }
              else {
LAB_005c6c1a:
                iVar7 = param_3;
                param_4 = (undefined4 **)local_18;
                if (*ppuVar13 == (undefined4 *)0x9) {
                  do {
                    pbVar18 = (byte *)local_24[6];
                    pbVar15 = *(byte **)(iVar7 + 0x18);
                    do {
                      bVar1 = *pbVar15;
                      bVar21 = bVar1 < *pbVar18;
                      if (bVar1 != *pbVar18) {
LAB_005c6c54:
                        iVar8 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                        goto LAB_005c6c59;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar15[1];
                      bVar21 = bVar1 < pbVar18[1];
                      if (bVar1 != pbVar18[1]) goto LAB_005c6c54;
                      pbVar15 = pbVar15 + 2;
                      pbVar18 = pbVar18 + 2;
                    } while (bVar1 != 0);
                    iVar8 = 0;
LAB_005c6c59:
                    if (iVar8 == 0) break;
                    iVar7 = *(int *)(iVar7 + 0xc);
                    param_4 = (undefined4 **)param_4[3];
                  } while (iVar7 != 0);
                  if (iVar7 == 0) goto LAB_005c6cb0;
                  for (iVar7 = (int)param_4[2]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0xc)) {
                    pvVar2 = _malloc(0x30);
                    if (pvVar2 == (void *)0x0) {
                      puVar3 = (undefined4 *)0x0;
                    }
                    else {
                      puVar3 = (undefined4 *)FUN_005d7ac2(iVar7 + 0x10);
                    }
                    *param_2 = puVar3;
                    if (puVar3 == (undefined4 *)0x0) goto LAB_005c6fc4;
                    param_2 = (undefined4 **)(puVar3 + 3);
                  }
                }
                else {
LAB_005c6cb0:
                  pvVar2 = _malloc(0x30);
                  if (pvVar2 == (void *)0x0) {
                    puVar3 = (undefined4 *)0x0;
                  }
                  else {
                    puVar3 = (undefined4 *)FUN_005d7ac2(ppuVar13);
                  }
                  *param_2 = puVar3;
                  if (puVar3 == (undefined4 *)0x0) goto LAB_005c6fc4;
                  param_2 = (undefined4 **)(puVar3 + 3);
                }
                if ((local_14 != (int *)0x0) || (local_10 != 0)) {
                  iVar7 = 0;
                  iVar8 = 1;
                  for (puVar3 = *local_1c; puVar3 != (undefined4 *)0x0;
                      puVar3 = (undefined4 *)puVar3[3]) {
                    if ((iVar7 != 0) && (iVar7 != puVar3[10])) {
                      iVar8 = iVar8 + 1;
                    }
                    iVar7 = FUN_005c64c6(puVar3[10],puVar3[0xb],0);
                    iVar8 = iVar8 + iVar7;
                    iVar7 = puVar3[10] + puVar3[0xb];
                  }
                  pcVar4 = (char *)FUN_005b1775(iVar8 + 1);
                  if (pcVar4 == (char *)0x0) goto LAB_005c6fc4;
                  iVar8 = 0;
                  param_4 = (undefined4 **)0x1;
                  cVar11 = ((local_14 == (int *)0x0) - 1U & 0xfb) + 0x27;
                  *pcVar4 = cVar11;
                  iVar7 = (int)param_4;
                  for (puVar3 = *local_1c; puVar3 != (undefined4 *)0x0;
                      puVar3 = (undefined4 *)puVar3[3]) {
                    param_4 = (undefined4 **)iVar7;
                    if ((iVar8 != 0) && (iVar8 != puVar3[10])) {
                      param_4 = (undefined4 **)(iVar7 + 1);
                      pcVar4[iVar7] = ' ';
                    }
                    iVar7 = FUN_005c64c6(puVar3[10],puVar3[0xb],pcVar4 + (int)param_4);
                    iVar7 = (int)param_4 + iVar7;
                    iVar8 = puVar3[0xb] + puVar3[10];
                  }
                  pcVar4[iVar7] = cVar11;
                  FUN_005b19ea();
                  iVar8 = local_8;
                  iVar7 = FUN_005b1a04(pcVar4,iVar7 + 1,local_20[4],local_20[5],local_8,local_8 + 4)
                  ;
                  if ((iVar7 < 0) ||
                     (iVar7 = FUN_005b291b(*(undefined4 *)(iVar8 + 0x80),local_44),
                     ppuVar13 = local_1c, iVar7 < 0)) goto LAB_005c6fa0;
                  if (*local_1c != (undefined4 *)0x0) {
                    (**(code **)**local_1c)(1);
                  }
                  pvVar2 = _malloc(0x30);
                  if (pvVar2 == (void *)0x0) {
                    puVar3 = (undefined4 *)0x0;
                  }
                  else {
                    puVar3 = (undefined4 *)FUN_005d7ac2(local_44);
                  }
                  *ppuVar13 = puVar3;
                  if (puVar3 == (undefined4 *)0x0) goto LAB_005c6fa0;
                  local_10 = 0;
                  local_14 = (int *)0x0;
                  param_2 = (undefined4 **)(puVar3 + 3);
                  FUN_005d7865();
                }
              }
LAB_005c6e23:
              iVar7 = local_8;
            }
            ppuVar13 = &local_c;
            puVar3 = local_c;
            while (puVar3 != (undefined4 *)0x0) {
              puVar3 = *ppuVar13;
              local_20 = (undefined4 **)puVar3[3];
              if (local_20 == (undefined4 **)0x0) {
                local_24 = (undefined4 **)0x0;
              }
              else {
                local_24 = (undefined4 **)local_20[3];
              }
              piVar5 = (int *)(-(uint)(local_20 != (undefined4 **)0x0) & (uint)(local_20 + 4));
              uVar12 = -(uint)(local_24 != (undefined4 **)0x0) & (uint)(local_24 + 4);
              if (((local_20 != (undefined4 **)0x0) && (local_24 != (undefined4 **)0x0)) &&
                 (*piVar5 == 1)) {
                iVar7 = 3;
                bVar21 = true;
                piVar5 = piVar5 + 2;
                pcVar4 = "##";
                do {
                  if (iVar7 == 0) break;
                  iVar7 = iVar7 + -1;
                  bVar21 = (char)*piVar5 == *pcVar4;
                  piVar5 = (int *)((int)piVar5 + 1);
                  pcVar4 = pcVar4 + 1;
                } while (bVar21);
                if (bVar21) {
                  local_1c = (undefined4 **)(puVar3[0xb] + *(int *)(uVar12 + 0x1c));
                  puVar6 = (undefined4 *)FUN_005b1775(local_1c);
                  if (puVar6 == (undefined4 *)0x0) goto LAB_005c6fc4;
                  uVar10 = puVar3[0xb];
                  puVar16 = (undefined4 *)puVar3[10];
                  puVar19 = puVar6;
                  for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *puVar19 = *puVar16;
                    puVar16 = puVar16 + 1;
                    puVar19 = puVar19 + 1;
                  }
                  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *(undefined1 *)puVar19 = *(undefined1 *)puVar16;
                    puVar16 = (undefined4 *)((int)puVar16 + 1);
                    puVar19 = (undefined4 *)((int)puVar19 + 1);
                  }
                  uVar10 = *(uint *)(uVar12 + 0x1c);
                  puVar16 = *(undefined4 **)(uVar12 + 0x18);
                  puVar19 = (undefined4 *)(puVar3[0xb] + (int)puVar6);
                  for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *puVar19 = *puVar16;
                    puVar16 = puVar16 + 1;
                    puVar19 = puVar19 + 1;
                  }
                  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *(undefined1 *)puVar19 = *(undefined1 *)puVar16;
                    puVar16 = (undefined4 *)((int)puVar16 + 1);
                    puVar19 = (undefined4 *)((int)puVar19 + 1);
                  }
                  FUN_005b19ea();
                  iVar7 = FUN_005b1a04(puVar6,local_1c,puVar3[8],puVar3[9],local_8,local_8 + 4);
                  if ((iVar7 < 0) ||
                     (iVar7 = FUN_005b291b(*(undefined4 *)(local_8 + 0x80),puVar3 + 4), iVar7 < 0))
                  goto LAB_005c6fa0;
                  puVar3[3] = local_24[3];
                  local_24[3] = (undefined4 *)0x0;
                  (*(code *)**local_20)(1);
                  FUN_005d7865();
                }
              }
              ppuVar13 = (undefined4 **)(*ppuVar13 + 3);
              iVar7 = local_8;
              puVar3 = *ppuVar13;
            }
            *ppuVar13 = *(undefined4 **)(iVar7 + 0x44);
            puVar3 = (undefined4 *)0x0;
            *(undefined4 **)(iVar7 + 0x44) = local_c;
            uVar20 = 1;
            goto LAB_005c6fc9;
          }
          FUN_005b1f01(iVar7 + 4,param_2,0x5ec,"not enough actual parameters for macro \'%s\'",
                       *(undefined4 *)((int)param_2 + 8));
        }
      }
    }
  }
  goto LAB_005c6fc4;
LAB_005c6fa0:
  FUN_005d7865();
LAB_005c6fc4:
  uVar20 = 0;
  puVar3 = local_c;
LAB_005c6fc9:
  if (local_18 != (undefined4 *)0x0) {
    (**(code **)*local_18)(1);
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return uVar20;
}


// ==== 0x5c6feb FUN_005c6feb

int __thiscall FUN_005c6feb(int param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 local_68 [56];
  undefined4 local_30 [8];
  undefined4 local_10;
  int local_c;
  undefined4 *local_8;
  
  local_10 = *(undefined4 *)(param_1 + 0x54);
  puVar6 = local_30;
  local_c = param_1;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_8 = _malloc(0x10);
  if (local_8 == (undefined4 *)0x0) {
    local_8 = (undefined4 *)0x0;
  }
  else {
    *local_8 = "DIRECT3D";
    local_8[1] = 0;
    local_8[2] = 0;
    local_8[3] = 0;
  }
  if (local_8 != (undefined4 *)0x0) {
    iVar5 = FUN_005c63d8(local_8);
    if (iVar5 < 0) goto LAB_005c7197;
    local_8 = _malloc(0x10);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      *local_8 = &DAT_006a0570;
      local_8[1] = 0;
      local_8[2] = 0;
      local_8[3] = 0;
    }
    if (local_8 != (undefined4 *)0x0) {
      iVar5 = FUN_005c63d8(local_8);
      if (iVar5 < 0) goto LAB_005c7197;
      local_30[0] = 2;
      local_30[2] = 0x900;
      local_8 = _malloc(0x10);
      if (local_8 == (undefined4 *)0x0) {
        local_8 = (undefined4 *)0x0;
      }
      else {
        *local_8 = "DIRECT3D_VERSION";
        local_8[1] = 0;
        local_8[2] = 0;
        local_8[3] = 0;
      }
      if (local_8 != (undefined4 *)0x0) {
        pvVar3 = _malloc(0x30);
        if (pvVar3 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_005d7ac2(local_30);
        }
        local_8[2] = iVar5;
        if (iVar5 != 0) {
          iVar5 = FUN_005c63d8(local_8);
          if (iVar5 < 0) goto LAB_005c7197;
          local_30[0] = 2;
          local_30[2] = 0x900;
          local_8 = _malloc(0x10);
          if (local_8 == (undefined4 *)0x0) {
            local_8 = (undefined4 *)0x0;
          }
          else {
            *local_8 = "D3DX_VERSION";
            local_8[1] = 0;
            local_8[2] = 0;
            local_8[3] = 0;
          }
          if (local_8 != (undefined4 *)0x0) {
            pvVar3 = _malloc(0x30);
            if (pvVar3 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_005d7ac2(local_30);
            }
            local_8[2] = iVar5;
            if (iVar5 != 0) {
              iVar5 = FUN_005c63d8(local_8);
              if (-1 < iVar5) {
                local_8 = (undefined4 *)0x0;
                if (param_2 != (int *)0x0) {
                  FUN_005b19ea();
                  *(undefined1 **)(local_c + 0x54) = local_68;
                  iVar5 = *param_2;
                  while (iVar5 != 0) {
                    pcVar2 = (char *)param_2[1];
                    if (pcVar2 == (char *)0x0) {
                      iVar5 = 0;
                    }
                    else {
                      pcVar4 = pcVar2;
                      do {
                        cVar1 = *pcVar4;
                        pcVar4 = pcVar4 + 1;
                      } while (cVar1 != '\0');
                      iVar5 = (int)pcVar4 - (int)(pcVar2 + 1);
                    }
                    iVar5 = FUN_005b1a04(pcVar2,iVar5,0,0,local_c,local_c + 4);
                    if ((iVar5 < 0) || (iVar5 = FUN_005c655e(*param_2,0), iVar5 < 0)) {
                      FUN_005d7865();
                      goto LAB_005c7197;
                    }
                    param_2 = param_2 + 2;
                    iVar5 = *param_2;
                  }
                  FUN_005d7865();
                }
                iVar5 = 0;
              }
              goto LAB_005c7197;
            }
          }
        }
      }
    }
  }
  iVar5 = -0x7ff8fff2;
LAB_005c7197:
  *(undefined4 *)(local_c + 0x54) = local_10;
  if (local_8 != (undefined4 *)0x0) {
    FUN_005c51e6(1);
  }
  return iVar5;
}


// ==== 0x5c7212 FUN_005c7212

void __thiscall FUN_005c7212(int param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 *local_48;
  int local_44;
  int local_40;
  uint local_8;
  
  puVar5 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0x2c) != 0) {
    return;
  }
  local_8 = param_3;
  puVar1 = local_48;
  while (local_48 = puVar1, local_8 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x40);
    local_8 = local_8 - 1;
    if (puVar1 == (undefined4 *)0x0) {
      pcVar8 = "internal error: stack underflow";
      goto LAB_005c757d;
    }
    (&local_48)[local_8] = (undefined4 *)puVar1[2];
    *(undefined4 *)(param_1 + 0x40) = puVar1[3];
    puVar1[2] = 0;
    puVar1[3] = 0;
    (**(code **)*puVar1)(1);
    puVar1 = local_48;
  }
  switch(param_2) {
  case 0:
    FUN_005c655e(puVar1[6],1);
    break;
  case 1:
    FUN_005c67cc(puVar1[6]);
    break;
  case 2:
    uVar7 = 0;
    goto LAB_005c72ab;
  case 3:
    uVar7 = *(undefined4 *)(local_44 + 0x18);
LAB_005c72ab:
    FUN_005c5acd(puVar1[6],uVar7);
    break;
  case 4:
    FUN_005c5af6();
    break;
  case 5:
    FUN_005c5cbe();
    break;
  case 6:
    uVar2 = puVar1[6];
    goto LAB_005c7303;
  case 7:
    uVar2 = FUN_005c6455(puVar1[6],0,0);
    goto LAB_005c7303;
  case 8:
    iVar4 = FUN_005c6455(puVar1[6],0,0);
    uVar2 = (uint)(iVar4 == 0);
LAB_005c7303:
    FUN_005c5d94(uVar2);
    break;
  case 9:
    FUN_005c5dec(puVar1[6]);
    break;
  case 10:
    FUN_005c5e5f();
    break;
  case 0xb:
    FUN_005c5ec1();
    break;
  case 0xc:
    FUN_005c5d94(1);
    goto LAB_005c734d;
  case 0xd:
    FUN_005c5dec(1);
LAB_005c734d:
    FUN_005b1a6c();
    break;
  case 0xe:
    FUN_005c683a();
    break;
  case 0xf:
  case 0x10:
  case 0x13:
  case 0x16:
  case 0x17:
  case 0x1a:
  case 0x1d:
  case 0x22:
  case 0x25:
  case 0x27:
  case 0x29:
  case 0x2b:
    local_48 = (undefined4 *)0x0;
    puVar5 = puVar1;
    break;
  case 0x11:
    local_48 = (undefined4 *)0x0;
    puVar1[4] = 2;
    uVar2 = FUN_005c68b4(puVar1[6]);
    goto LAB_005c73e1;
  case 0x12:
    local_48 = (undefined4 *)0x0;
    puVar1[4] = 2;
    uVar2 = FUN_005c6455(puVar1[6],0,0);
    goto LAB_005c73e1;
  case 0x14:
    local_48 = (undefined4 *)0x0;
    uVar2 = (uint)(puVar1[6] == 0);
    goto LAB_005c73e1;
  case 0x15:
    puVar1[6] = -puVar1[6];
    local_48 = (undefined4 *)0x0;
    puVar5 = puVar1;
    break;
  case 0x18:
    uVar2 = *(int *)(local_44 + 0x18) * puVar1[6];
    local_48 = (undefined4 *)0x0;
    goto LAB_005c73e1;
  case 0x19:
    local_48 = (undefined4 *)0x0;
    if (*(uint *)(local_44 + 0x18) == 0) {
      FUN_005b1f01(param_1 + 4,param_1 + 0x60,0x5df,"division by zero in preprocessor expression");
      *(undefined4 *)(param_1 + 0x2c) = 1;
      puVar5 = puVar1;
      break;
    }
    uVar2 = (uint)puVar1[6] / *(uint *)(local_44 + 0x18);
    goto LAB_005c73e1;
  case 0x1b:
    puVar1[6] = puVar1[6] + *(int *)(local_44 + 0x18);
    local_48 = (undefined4 *)0x0;
    puVar5 = puVar1;
    break;
  case 0x1c:
    puVar1[6] = puVar1[6] - *(int *)(local_44 + 0x18);
    local_48 = (undefined4 *)0x0;
    puVar5 = puVar1;
    break;
  case 0x1e:
    bVar6 = (uint)puVar1[6] < *(uint *)(local_44 + 0x18);
    goto LAB_005c7443;
  case 0x1f:
    bVar6 = *(uint *)(local_44 + 0x18) < (uint)puVar1[6];
LAB_005c7443:
    uVar2 = (uint)bVar6;
    local_48 = (undefined4 *)0x0;
    goto LAB_005c73e1;
  case 0x20:
    bVar6 = *(uint *)(local_44 + 0x18) < (uint)puVar1[6];
    goto LAB_005c7476;
  case 0x21:
    bVar6 = (uint)puVar1[6] < *(uint *)(local_44 + 0x18);
    goto LAB_005c7476;
  case 0x23:
    bVar6 = puVar1[6] != *(int *)(local_44 + 0x18);
LAB_005c7476:
    local_48 = (undefined4 *)0x0;
    uVar2 = 1 - bVar6;
    goto LAB_005c73e1;
  case 0x24:
    local_48 = (undefined4 *)0x0;
    puVar1[6] = (uint)(puVar1[6] != *(int *)(local_44 + 0x18));
    puVar5 = puVar1;
    break;
  case 0x26:
    local_48 = (undefined4 *)0x0;
    if (puVar1[6] != 0) {
LAB_005c74b5:
      if (*(int *)(local_44 + 0x18) != 0) goto LAB_005c74cf;
    }
    local_48 = (undefined4 *)0x0;
    uVar2 = 0;
    goto LAB_005c73e1;
  case 0x28:
    local_48 = (undefined4 *)0x0;
    if (puVar1[6] == 0) goto LAB_005c74b5;
LAB_005c74cf:
    local_48 = (undefined4 *)0x0;
    uVar2 = 1;
    goto LAB_005c73e1;
  case 0x2a:
    local_48 = (undefined4 *)0x0;
    if (puVar1[6] == 0) {
      local_44 = local_40;
    }
    uVar2 = *(uint *)(local_44 + 0x18);
LAB_005c73e1:
    puVar1[6] = uVar2;
    puVar5 = puVar1;
    break;
  case 0x2c:
  case 0x2d:
  case 0x2e:
    pvVar3 = _malloc(0x30);
    if (pvVar3 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d7ac2(param_1 + 0x60);
    }
    FUN_005c652b(puVar5);
  }
  param_2 = 0;
  if (param_3 != 0) {
    do {
      if ((&local_48)[param_2] != (undefined4 *)0x0) {
        (**(code **)*(&local_48)[param_2])(1);
      }
      param_2 = param_2 + 1;
    } while (param_2 < param_3);
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar3 = _malloc(0x14);
    if (pvVar3 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005d78db(puVar5,*(undefined4 *)(param_1 + 0x40),"Stack");
    }
    if (iVar4 == 0) {
      pcVar8 = "internal error: out of memory";
LAB_005c757d:
      FUN_005b1f01(param_1 + 4,param_1 + 0x60,0,pcVar8);
      *(undefined4 *)(param_1 + 0x2c) = 1;
    }
    else {
      *(int *)(param_1 + 0x40) = iVar4;
    }
  }
  else if (puVar5 != (undefined4 *)0x0) {
    (**(code **)*puVar5)(1);
  }
  return;
}


// ==== 0x5c765d FUN_005c765d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c765d(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar4 = 0;
  _DAT_00708890 = 0;
  DAT_0070888c = 0;
  DAT_00708884 = (short *)&DAT_00708490;
  DAT_00708880 = (undefined4 *)&DAT_00707cc0;
  _DAT_00708490 = 0;
LAB_005c768d:
  DAT_00708888 = -1;
LAB_005c7695:
  iVar2 = (int)(short)(&DAT_006db100)[iVar4];
  if (iVar2 == 0) {
    if ((DAT_00708888 < 0) && (DAT_00708888 = FUN_005c56ef(), DAT_00708888 < 0)) {
      DAT_00708888 = 0;
    }
    if (((((short)(&DAT_006db1c0)[iVar4] != 0) &&
         (iVar2 = (short)(&DAT_006db1c0)[iVar4] + DAT_00708888, -1 < iVar2)) && (iVar2 < 0x172)) &&
       (*(short *)(&DAT_006db608 + iVar2 * 2) == DAT_00708888)) {
      if (&DAT_00708876 <= DAT_00708884) goto LAB_005c7a9a;
      iVar4 = (int)*(short *)(&DAT_006db320 + iVar2 * 2);
      DAT_00708884 = DAT_00708884 + 1;
      *DAT_00708884 = *(short *)(&DAT_006db320 + iVar2 * 2);
      DAT_00708880 = DAT_00708880 + 1;
      *DAT_00708880 = DAT_00708878;
      DAT_00708888 = -1;
      if (0 < DAT_0070888c) {
        DAT_0070888c = DAT_0070888c + -1;
      }
      goto LAB_005c7695;
    }
    if ((((short)(&DAT_006db260)[iVar4] != 0) &&
        (iVar2 = (short)(&DAT_006db260)[iVar4] + DAT_00708888, -1 < iVar2)) &&
       ((iVar2 < 0x172 && (*(short *)(&DAT_006db608 + iVar2 * 2) == DAT_00708888)))) {
      iVar2 = (int)*(short *)(&DAT_006db320 + iVar2 * 2);
      goto LAB_005c777c;
    }
    if (DAT_0070888c == 0) {
      FUN_005c5a21(DAT_00708898,"syntax error");
      _DAT_00708890 = _DAT_00708890 + 1;
    }
    if (2 < DAT_0070888c) goto LAB_005c7a91;
    DAT_0070888c = 3;
    while ((((short)(&DAT_006db1c0)[*DAT_00708884] == 0 ||
            (iVar4 = (short)(&DAT_006db1c0)[*DAT_00708884] + 0x100, iVar4 < 0)) ||
           ((0x171 < iVar4 || (*(short *)(&DAT_006db608 + iVar4 * 2) != 0x100))))) {
      if (DAT_00708884 < (short *)0x708491) {
        DAT_0070888c = 3;
        return 1;
      }
      DAT_00708884 = DAT_00708884 + -1;
      DAT_00708880 = DAT_00708880 + -1;
    }
    if ((short *)0x708875 < DAT_00708884) goto LAB_005c7a9a;
    sVar1 = *(short *)(&DAT_006db320 + iVar4 * 2);
    DAT_00708884 = DAT_00708884 + 1;
    *DAT_00708884 = sVar1;
    uVar6 = DAT_00708878;
  }
  else {
LAB_005c777c:
    iVar4 = (int)*(short *)(&DAT_006db0a0 + iVar2 * 2);
    DAT_0070887c = DAT_00708880[1 - iVar4];
    switch(iVar2) {
    case 1:
      uVar7 = 1;
      uVar6 = 0;
      break;
    case 2:
      uVar7 = 1;
      uVar6 = 1;
      break;
    case 3:
      uVar7 = 1;
      uVar6 = 2;
      break;
    case 4:
      uVar7 = 2;
      uVar6 = 3;
      break;
    case 5:
      uVar7 = 0;
      uVar6 = 4;
      break;
    case 6:
      uVar7 = 0;
      uVar6 = 5;
      break;
    case 7:
      uVar7 = 1;
      uVar6 = 6;
      break;
    case 8:
      uVar7 = 1;
      uVar6 = 7;
      break;
    case 9:
      uVar7 = 1;
      uVar6 = 8;
      break;
    case 10:
      uVar7 = 1;
      uVar6 = 9;
      break;
    case 0xb:
      uVar7 = 0;
      uVar6 = 10;
      break;
    case 0xc:
      uVar7 = 0;
      uVar6 = 0xb;
      break;
    case 0xd:
      uVar7 = 0;
      uVar6 = 0xc;
      break;
    case 0xe:
      uVar7 = 0;
      uVar6 = 0xd;
      break;
    case 0xf:
      uVar7 = 0;
      uVar6 = 0xe;
      break;
    case 0x10:
      uVar7 = 1;
      uVar6 = 0xf;
      break;
    case 0x11:
      uVar7 = 1;
      uVar6 = 0x10;
      break;
    case 0x12:
      uVar7 = 1;
      uVar6 = 0x11;
      break;
    case 0x13:
      uVar7 = 1;
      uVar6 = 0x12;
      break;
    case 0x14:
      uVar7 = 1;
      uVar6 = 0x13;
      break;
    case 0x15:
      uVar7 = 1;
      uVar6 = 0x14;
      break;
    case 0x16:
      uVar7 = 1;
      uVar6 = 0x15;
      break;
    case 0x17:
      uVar7 = 1;
      uVar6 = 0x16;
      break;
    case 0x18:
      uVar7 = 1;
      uVar6 = 0x17;
      break;
    case 0x19:
      uVar7 = 2;
      uVar6 = 0x18;
      break;
    case 0x1a:
      uVar7 = 2;
      uVar6 = 0x19;
      break;
    case 0x1b:
      uVar7 = 1;
      uVar6 = 0x1a;
      break;
    case 0x1c:
      uVar7 = 2;
      uVar6 = 0x1b;
      break;
    case 0x1d:
      uVar7 = 2;
      uVar6 = 0x1c;
      break;
    case 0x1e:
      uVar7 = 1;
      uVar6 = 0x1d;
      break;
    case 0x1f:
      uVar7 = 2;
      uVar6 = 0x1e;
      break;
    case 0x20:
      uVar7 = 2;
      uVar6 = 0x1f;
      break;
    case 0x21:
      uVar7 = 2;
      uVar6 = 0x20;
      break;
    case 0x22:
      uVar7 = 2;
      uVar6 = 0x21;
      break;
    case 0x23:
      uVar7 = 1;
      uVar6 = 0x22;
      break;
    case 0x24:
      uVar7 = 2;
      uVar6 = 0x23;
      break;
    case 0x25:
      uVar7 = 2;
      uVar6 = 0x24;
      break;
    case 0x26:
      uVar7 = 1;
      uVar6 = 0x25;
      break;
    case 0x27:
      uVar7 = 2;
      uVar6 = 0x26;
      break;
    case 0x28:
      uVar7 = 1;
      uVar6 = 0x27;
      break;
    case 0x29:
      uVar7 = 2;
      uVar6 = 0x28;
      break;
    case 0x2a:
      uVar7 = 1;
      uVar6 = 0x29;
      break;
    case 0x2b:
      uVar7 = 3;
      uVar6 = 0x2a;
      break;
    case 0x2c:
      uVar7 = 1;
      uVar6 = 0x2b;
      break;
    case 0x2d:
      uVar7 = 0;
      uVar6 = 0x2c;
      break;
    case 0x2e:
      uVar7 = 0;
      uVar6 = 0x2d;
      break;
    case 0x2f:
      uVar7 = 0;
      uVar6 = 0x2e;
      break;
    default:
      goto switchD_005c77a6_default;
    }
    FUN_005c7212(uVar6,uVar7);
switchD_005c77a6_default:
    DAT_00708884 = DAT_00708884 + -iVar4;
    iVar3 = (int)*DAT_00708884;
    DAT_00708880 = DAT_00708880 + -iVar4;
    if ((iVar3 == 0) && (*(short *)(&DAT_006db040 + iVar2 * 2) == 0)) {
      DAT_00708884 = DAT_00708884 + 1;
      iVar4 = 0xf;
      *DAT_00708884 = 0xf;
      DAT_00708880 = DAT_00708880 + 1;
      *DAT_00708880 = DAT_0070887c;
      bVar5 = DAT_00708888 == 0;
      if (DAT_00708888 < 0) {
        DAT_00708888 = FUN_005c56ef();
        bVar5 = DAT_00708888 == 0;
        if (DAT_00708888 < 0) {
          DAT_00708888 = 0;
          bVar5 = true;
        }
      }
      if (bVar5) {
        return 0;
      }
      goto LAB_005c7695;
    }
    iVar4 = *(short *)(&DAT_006db040 + iVar2 * 2) * 2;
    if ((((*(short *)(&DAT_006db300 + iVar4) == 0) ||
         (iVar2 = *(short *)(&DAT_006db300 + iVar4) + iVar3, iVar2 < 0)) || (0x171 < iVar2)) ||
       (*(short *)(&DAT_006db608 + iVar2 * 2) != iVar3)) {
      sVar1 = *(short *)(&DAT_006db1a0 + iVar4);
    }
    else {
      sVar1 = *(short *)(&DAT_006db320 + iVar2 * 2);
    }
    if ((short *)0x708875 < DAT_00708884) {
LAB_005c7a9a:
      FUN_005c5a21(DAT_00708898,"yacc stack overflow");
      return 1;
    }
    DAT_00708884 = DAT_00708884 + 1;
    *DAT_00708884 = sVar1;
    uVar6 = DAT_0070887c;
  }
  iVar4 = (int)sVar1;
  DAT_00708880 = DAT_00708880 + 1;
  *DAT_00708880 = uVar6;
  goto LAB_005c7695;
LAB_005c7a91:
  if (DAT_00708888 == 0) {
    return 1;
  }
  goto LAB_005c768d;
}


// ==== 0x5c7b70 FUN_005c7b70

int __thiscall
FUN_005c7b70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = _malloc(0x70);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005c5250();
  }
  *(int *)(param_1 + 0x50) = iVar2;
  if (iVar2 == 0) {
    iVar2 = -0x7ff8fff2;
  }
  else {
    iVar2 = FUN_005c549b(param_2,param_3,param_1,param_1 + 4);
    if (-1 < iVar2) {
      iVar2 = FUN_005c6feb(param_4);
      if (-1 < iVar2) {
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
        *(undefined4 *)(param_1 + 0x58) = param_5;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}


// ==== 0x5c7bd2 FUN_005c7bd2

uint __thiscall FUN_005c7bd2(int param_1,int *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  bool bVar8;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
LAB_005c7e07:
  do {
    if (*(int *)(param_1 + 0x30) != 0) {
      uVar2 = 0x80004005;
LAB_005c7e1a:
      param_2[4] = *(int *)(*(int *)(param_1 + 0x54) + 0x18);
      param_2[5] = *(int *)(*(int *)(param_1 + 0x54) + 0x1c);
      *param_2 = 0xd;
      return uVar2;
    }
    if ((*(int *)(param_1 + 0x48) != 0) && (*(int *)(*(int *)(param_1 + 0x48) + 8) == 0)) {
      uVar2 = 0;
      goto LAB_005c7e1a;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x44);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),param_2);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    else {
      piVar4 = puVar1 + 4;
      piVar6 = param_2;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar6 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar6 = piVar6 + 1;
      }
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(*(int *)(param_1 + 0x44) + 0xc);
      puVar1[3] = 0;
      (**(code **)*puVar1)(1);
      param_2[4] = *(int *)(*(int *)(param_1 + 0x54) + 0x18);
      param_2[5] = *(int *)(*(int *)(param_1 + 0x54) + 0x1c);
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*param_2 != 1) {
LAB_005c7d70:
      if (*param_2 == 0xd) {
        if (*(int *)(*(int *)(param_1 + 0x50) + 0x38) != 0) {
          FUN_005b1f01(param_1 + 4,param_2,0x5de,"unexpected end of file");
        }
        iVar3 = *(int *)(param_1 + 0x50);
        if (*(int *)(iVar3 + 0x6c) == 0) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar3 + 0x6c);
        *(undefined4 *)(iVar3 + 0x6c) = 0;
        FUN_005c52d8(1);
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
        *param_2 = 0xc;
        *(undefined4 *)(param_1 + 0x28) = 1;
        return 0;
      }
      if (((*param_2 != 9) || (iVar3 = FUN_005c6455(param_2[2],&local_c,&local_8), iVar3 == 0)) ||
         (iVar3 = FUN_005c691a(param_2,local_c,local_8), iVar3 == 0)) {
        if (*param_2 == 9) {
          iVar3 = 9;
          bVar8 = true;
          pcVar5 = (char *)param_2[2];
          pcVar7 = "__FILE__";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar8 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            *param_2 = 10;
            iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x18);
          }
          else {
            iVar3 = 9;
            bVar8 = true;
            pcVar5 = (char *)param_2[2];
            pcVar7 = "__LINE__";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar8 = *pcVar5 == *pcVar7;
              pcVar5 = pcVar5 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (!bVar8) goto LAB_005c7df1;
            *param_2 = 2;
            iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x1c);
          }
          param_2[2] = iVar3;
        }
LAB_005c7df1:
        *(uint *)(param_1 + 0x28) = (uint)(*param_2 == 0xc);
        if (*(int *)(param_1 + 0x38) != 0) {
          iVar3 = *(int *)(param_1 + 0x48);
          if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
            if ((*param_2 == 1) && (*(char *)((int)param_2 + 9) == '\0')) {
              if ((char)param_2[2] == '{') {
                *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
              }
              if ((char)param_2[2] == '}') {
                iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 8);
                if (iVar3 != 0) {
                  *(int *)(*(int *)(param_1 + 0x48) + 8) = iVar3 + -1;
                }
              }
            }
            if (*(int *)(*(int *)(param_1 + 0x48) + 8) == 0) {
              *param_2 = 0xd;
            }
          }
          return 0;
        }
      }
      goto LAB_005c7e07;
    }
    iVar3 = 2;
    bVar8 = true;
    pcVar5 = "#";
    piVar4 = param_2 + 2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar8 = *pcVar5 == (char)*piVar4;
      pcVar5 = pcVar5 + 1;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (bVar8);
    if ((!bVar8) || (*(int *)(param_1 + 0x28) == 0)) goto LAB_005c7d70;
    DAT_00708898 = param_1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x34) = 1;
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
    iVar3 = FUN_005c765d();
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x2c) = 1;
    }
    if (*(undefined4 **)(param_1 + 0x40) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x40))(1);
    }
    *(undefined4 *)(param_1 + 0x40) = 0;
    if ((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x2c) == 0)) {
      uVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),(int *)(param_1 + 0x60));
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      iVar3 = *(int *)(param_1 + 0x60);
      if ((iVar3 == 0xc) || (iVar3 == 0xd)) {
        *(undefined4 *)(param_1 + 0x28) = 1;
      }
      else {
        if (*(int *)(param_1 + 0x38) != 0) {
          FUN_005b1f01(param_1 + 4,param_2,0x5dd,
                       "unexpected tokens following preprocessor directive");
        }
        *(undefined4 *)(param_1 + 0x2c) = 1;
      }
    }
    if (*(int *)(param_1 + 0x28) == 0) {
      FUN_005b1a6c();
      if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x44))(1);
      }
      *(undefined4 *)(param_1 + 0x44) = 0;
      uVar2 = FUN_005b291b(*(undefined4 *)(param_1 + 0x80),param_1 + 0x60);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      *(undefined4 *)(param_1 + 0x28) = 1;
    }
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x3c);
    if (*(int *)(param_1 + 0x3c) != 0) {
      piVar4 = (int *)(param_1 + 0x60);
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *param_2 = *piVar4;
        piVar4 = piVar4 + 1;
        param_2 = param_2 + 1;
      }
      return -(uint)(*(int *)(param_1 + 0x30) != 0) & 0x80004005;
    }
  } while( true );
}


// ==== 0x5c7ed5 FUN_005c7ed5

int __fastcall FUN_005c7ed5(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_24 [8];
  
  if (*(int *)(param_1 + 0x48) == 0) {
    iVar1 = -0x7789f794;
  }
  else {
    do {
      iVar1 = FUN_005c7bd2(local_24);
      if (iVar1 < 0) {
        return iVar1;
      }
    } while (local_24[0] != 0xd);
    iVar1 = *(int *)(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar1 + 4) = 0;
    FUN_005c54ec(1);
    if (*(undefined4 **)(param_1 + 0x48) == (undefined4 *)0x0) {
      uVar2 = 1;
    }
    else {
      uVar2 = **(undefined4 **)(param_1 + 0x48);
    }
    *(undefined4 *)(param_1 + 0x80) = uVar2;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x5c7f2f FUN_005c7f2f

void __fastcall FUN_005c7f2f(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== 0x5c7f41 FUN_005c7f41

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 __thiscall FUN_005c7f41(undefined4 *param_1,LPCWSTR param_2,int param_3)

{
  HANDLE pvVar1;
  DWORD DVar2;
  LPVOID pvVar3;
  _OSVERSIONINFOA local_9c;
  int local_8;
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0x8876086c;
  }
  if (param_3 == 0) {
LAB_005c7fe4:
    pvVar1 = CreateFileA((LPCSTR)param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,
                         (HANDLE)0x0);
  }
  else {
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    if (local_9c.dwPlatformId != 2) {
      local_8 = WideCharToMultiByte(0xfde9,0,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      WideCharToMultiByte(0xfde9,0,param_2,-1,&stack0xffffff58,local_8,(LPCSTR)0x0,(LPBOOL)0x0);
      param_3 = 0;
      param_2 = (LPCWSTR)&stack0xffffff58;
    }
    if (param_3 == 0) goto LAB_005c7fe4;
    pvVar1 = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,(HANDLE)0x0);
  }
  *param_1 = pvVar1;
  if (pvVar1 != (HANDLE)0xffffffff) {
    pvVar1 = CreateFileMappingA(pvVar1,(LPSECURITY_ATTRIBUTES)0x0,2,0,0,(LPCSTR)0x0);
    param_1[1] = pvVar1;
    if (pvVar1 != (HANDLE)0xffffffff) {
      DVar2 = GetFileSize((HANDLE)*param_1,(LPDWORD)0x0);
      param_1[3] = DVar2;
      if (DVar2 != 0xffffffff) {
        if (DVar2 == 0) {
          param_1[2] = 0;
        }
        else {
          pvVar3 = MapViewOfFile((HANDLE)param_1[1],4,0,0,0);
          param_1[2] = pvVar3;
          if (pvVar3 == (LPVOID)0x0) goto LAB_005c8043;
        }
        return 0;
      }
    }
  }
LAB_005c8043:
  GetLastError();
  return 0x88760b59;
}


// ==== 0x5c8062 FUN_005c8062

undefined4 __fastcall FUN_005c8062(undefined4 *param_1)

{
  if ((LPCVOID)param_1[2] != (LPCVOID)0x0) {
    UnmapViewOfFile((LPCVOID)param_1[2]);
    param_1[2] = 0;
    param_1[3] = 0;
  }
  if ((HANDLE)param_1[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[1]);
    param_1[1] = 0xffffffff;
  }
  if ((HANDLE)*param_1 != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0xffffffff;
  }
  return 0;
}


// ==== 0x5c80a3 FUN_005c80a3

void __fastcall FUN_005c80a3(int *param_1)

{
  if (*param_1 != -1) {
    FUN_005c8062();
    return;
  }
  return;
}


// ==== 0x5c80ae FUN_005c80ae

undefined4 __thiscall
FUN_005c80ae(int param_1,int param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6,
            int *param_7)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  ushort *puVar6;
  uint local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  if (param_2 == 0) goto LAB_005c8269;
  local_10 = 0;
  if (*(int *)(param_2 + 0xc) == 0) goto LAB_005c8269;
  puVar6 = (ushort *)(*(int *)(param_2 + 0x10) + param_2 + 6);
  do {
    uVar1 = puVar6[-1];
    uVar2 = (uint)puVar6[1] + (uint)*puVar6;
    puVar4 = param_4;
    if ((uVar1 == 0) || (puVar4 = param_5, uVar1 == 1)) {
LAB_005c811a:
      if (*puVar4 < uVar2) {
        *puVar4 = uVar2;
LAB_005c8120:
        local_8 = 1;
      }
    }
    else {
      if (uVar1 != 2) {
        if (uVar1 == 3) {
          uVar2 = *puVar6 + 1;
          puVar4 = param_6;
          goto LAB_005c811a;
        }
        goto LAB_005c827d;
      }
      if (*param_3 < uVar2) {
        *param_3 = uVar2;
        goto LAB_005c8120;
      }
    }
    local_10 = local_10 + 1;
    puVar6 = puVar6 + 10;
  } while (local_10 < *(uint *)(param_2 + 0xc));
  if (local_8 == 0) goto LAB_005c8269;
  if (*(uint *)(param_1 + 0x9c) < *param_3) {
    if (*(void **)(param_1 + 0xa8) != (void *)0x0) {
      _free(*(void **)(param_1 + 0xa8));
      *(undefined4 *)(param_1 + 0xa8) = 0;
    }
    puVar3 = _malloc(*param_3 << 4);
    *(undefined4 **)(param_1 + 0xa8) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      for (iVar5 = (*param_3 & 0xfffffff) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      *(uint *)(param_1 + 0x9c) = *param_3;
      goto LAB_005c819d;
    }
  }
  else {
LAB_005c819d:
    if (*(uint *)(param_1 + 0xa0) < *param_4) {
      if (*(void **)(param_1 + 0xac) != (void *)0x0) {
        _free(*(void **)(param_1 + 0xac));
        *(undefined4 *)(param_1 + 0xac) = 0;
      }
      puVar3 = _malloc(*param_4 << 2);
      *(undefined4 **)(param_1 + 0xac) = puVar3;
      if (puVar3 == (undefined4 *)0x0) goto LAB_005c827d;
      for (uVar2 = *param_4 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      *(uint *)(param_1 + 0xa0) = *param_4;
    }
    if (*param_5 <= *(uint *)(param_1 + 0xa4)) goto LAB_005c8269;
    if (*(void **)(param_1 + 0xb0) != (void *)0x0) {
      _free(*(void **)(param_1 + 0xb0));
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
    puVar3 = _malloc(*param_5 << 4);
    *(undefined4 **)(param_1 + 0xb0) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      for (iVar5 = (*param_5 & 0xfffffff) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      *(uint *)(param_1 + 0xa4) = *param_5;
      goto LAB_005c8269;
    }
  }
LAB_005c827d:
  local_c = 0x80004005;
LAB_005c8269:
  if (param_7 != (int *)0x0) {
    *param_7 = local_8;
  }
  return local_c;
}


// ==== 0x5c8286 FUN_005c8286

int FUN_005c8286(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *param_1;
  iVar4 = *(int *)(iVar3 + 0x10);
  iVar1 = *(int *)(iVar3 + 4);
  if (iVar4 == 0) {
    iVar4 = 1;
  }
  if (-1 < iVar1) {
    if (iVar1 < 4) {
      uVar2 = *(uint *)(iVar3 + 0x14);
      iVar1 = *(int *)(iVar3 + 0x18);
      *param_1 = iVar3 + 0x1c;
      return ((uint)(uVar2 % param_2 != 0) + uVar2 / param_2) * iVar1 * iVar4;
    }
    if ((iVar1 != 4) && (iVar1 == 5)) {
      iVar1 = *(int *)(iVar3 + 0x14);
      iVar5 = 0;
      *param_1 = iVar3 + 0x18;
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        iVar3 = FUN_005c8286(param_1,param_2);
        iVar5 = iVar5 + iVar3;
      }
      return iVar5 * iVar4;
    }
  }
  return 0;
}


// ==== 0x5c8303 FUN_005c8303

int FUN_005c8303(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar6 = param_4;
  piVar5 = param_3;
  piVar4 = param_2;
  piVar1 = (int *)*param_1;
  iVar8 = piVar1[1];
  local_c = piVar1[4];
  local_18 = 0;
  if (local_c == 0) {
    local_c = 1;
  }
  if (-1 < iVar8) {
    if (iVar8 < 4) {
      uVar2 = piVar1[5];
      uVar3 = piVar1[6];
      iVar8 = *piVar1;
      uVar9 = (uint)((uVar2 & 3) != 0) + (uVar2 >> 2);
      local_10 = uVar9;
      local_8 = uVar2;
      if (iVar8 == 1) {
        local_1c = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_2 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar10 = *param_4;
                if (uVar10 == 0) break;
                if (uVar10 < uVar9) {
                  local_8 = uVar10 << 2;
                  local_10 = uVar10;
                }
                uVar10 = 0;
                if (local_8 != 0) {
                  iVar8 = (int)param_2 << 2;
                  do {
                    *(undefined4 *)(*param_3 + uVar10 * 4) = *(undefined4 *)(iVar8 + *piVar4);
                    uVar10 = uVar10 + 1;
                    iVar8 = iVar8 + uVar3 * 4;
                  } while (uVar10 < local_8);
                }
                *param_3 = *param_3 + local_10 * 0x10;
                *param_4 = *param_4 - local_10;
                param_2 = (int *)((int)param_2 + 1);
              } while (param_2 < uVar3);
            }
            *piVar4 = *piVar4 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      else if (iVar8 == 2) {
        local_1c = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar10 = *param_4;
                if (uVar10 == 0) break;
                if (uVar10 < uVar9) {
                  local_8 = uVar10 << 2;
                  local_10 = uVar10;
                }
                uVar10 = 0;
                if (local_8 != 0) {
                  iVar8 = (int)param_3 << 2;
                  do {
                    *(undefined4 *)(*piVar5 + uVar10 * 4) = *(undefined4 *)(iVar8 + *param_2);
                    uVar10 = uVar10 + 1;
                    iVar8 = iVar8 + uVar3 * 4;
                  } while (uVar10 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x10;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      else {
        if (iVar8 != 3) {
          return -0x7fffbffb;
        }
        local_1c = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            local_14 = 0;
            if (uVar3 != 0) {
              do {
                uVar10 = *param_4;
                uVar11 = 0;
                if (uVar10 == 0) break;
                if (uVar10 < uVar9) {
                  local_8 = uVar10 << 2;
                  local_10 = uVar10;
                }
                if (local_8 != 0) {
                  do {
                    uVar7 = __ftol();
                    *(undefined4 *)(*param_3 + uVar11 * 4) = uVar7;
                    uVar11 = uVar11 + 1;
                  } while (uVar11 < local_8);
                }
                *param_3 = *param_3 + local_10 * 0x10;
                *param_4 = *param_4 - local_10;
                local_14 = local_14 + 1;
              } while (local_14 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar8 == 5) {
      local_14 = 0;
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      if (local_c == 0) {
        return 0;
      }
      do {
        if (*puVar6 == 0) {
          return local_18;
        }
        param_4 = (uint *)0x0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            if (*puVar6 == 0) break;
            local_18 = FUN_005c8303(param_1,param_2,param_3,puVar6);
            if (local_18 < 0) {
              return local_18;
            }
            param_4 = (uint *)((int)param_4 + 1);
          } while (param_4 < uVar2);
        }
        local_14 = local_14 + 1;
        if (local_c <= local_14) {
          return local_18;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5c85c1 FUN_005c85c1

int FUN_005c85c1(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar6 = param_4;
  piVar5 = param_3;
  piVar1 = (int *)*param_1;
  iVar8 = piVar1[1];
  local_c = piVar1[4];
  local_14 = 0;
  if (local_c == 0) {
    local_c = 1;
  }
  if (-1 < iVar8) {
    if (iVar8 < 4) {
      uVar2 = piVar1[5];
      uVar3 = piVar1[6];
      iVar8 = *piVar1;
      uVar7 = (uint)((uVar2 & 3) != 0) + (uVar2 >> 2);
      local_10 = uVar7;
      local_8 = uVar2;
      if (iVar8 == 1) {
        local_18 = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar7) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar8 = (int)param_3 << 2;
                  do {
                    *(float *)(*piVar5 + uVar9 * 4) = (float)*(int *)(iVar8 + *param_2);
                    uVar9 = uVar9 + 1;
                    iVar8 = iVar8 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x10;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      else if (iVar8 == 2) {
        local_18 = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar7) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar8 = (int)param_3 << 2;
                  do {
                    fVar4 = (float)*(int *)(iVar8 + *param_2);
                    if (*(int *)(iVar8 + *param_2) < 0) {
                      fVar4 = fVar4 + 4.2949673e+09;
                    }
                    *(float *)(*piVar5 + uVar9 * 4) = fVar4;
                    uVar9 = uVar9 + 1;
                    iVar8 = iVar8 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x10;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      else {
        if (iVar8 != 3) {
          return -0x7fffbffb;
        }
        local_18 = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar7) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar8 = (int)param_3 << 2;
                  do {
                    *(undefined4 *)(*piVar5 + uVar9 * 4) = *(undefined4 *)(iVar8 + *param_2);
                    uVar9 = uVar9 + 1;
                    iVar8 = iVar8 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x10;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar8 == 5) {
      local_10 = 0;
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      if (local_c == 0) {
        return 0;
      }
      do {
        if (*puVar6 == 0) {
          return local_14;
        }
        param_4 = (uint *)0x0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            if (*puVar6 == 0) break;
            local_14 = FUN_005c85c1(param_1,param_2,param_3,puVar6);
            if (local_14 < 0) {
              return local_14;
            }
            param_4 = (uint *)((int)param_4 + 1);
          } while (param_4 < uVar2);
        }
        local_10 = local_10 + 1;
        if (local_c <= local_10) {
          return local_14;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5c887d FUN_005c887d

int FUN_005c887d(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar6 = param_4;
  piVar5 = param_3;
  piVar1 = (int *)*param_1;
  iVar7 = piVar1[1];
  local_c = piVar1[4];
  local_14 = 0;
  if (local_c == 0) {
    local_c = 1;
  }
  if (-1 < iVar7) {
    if (iVar7 < 4) {
      uVar2 = piVar1[5];
      uVar3 = piVar1[6];
      iVar7 = *piVar1;
      uVar8 = (uint)((uVar2 & 3) != 0) + (uVar2 >> 2);
      local_10 = uVar8;
      local_8 = uVar2;
      if (iVar7 == 1) {
        local_18 = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar8) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar7 = (int)param_3 << 2;
                  do {
                    *(double *)(*piVar5 + uVar9 * 8) = (double)*(int *)(iVar7 + *param_2);
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x20;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      else if (iVar7 == 2) {
        local_18 = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar8) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar7 = (int)param_3 << 2;
                  do {
                    dVar4 = (double)*(int *)(iVar7 + *param_2);
                    if (*(int *)(iVar7 + *param_2) < 0) {
                      dVar4 = dVar4 + 4294967296.0;
                    }
                    *(double *)(*piVar5 + uVar9 * 8) = dVar4;
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x20;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      else {
        if (iVar7 != 3) {
          return -0x7fffbffb;
        }
        local_18 = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar8) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar7 = (int)param_3 << 2;
                  do {
                    *(double *)(*piVar5 + uVar9 * 8) = (double)*(float *)(iVar7 + *param_2);
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar5 = *piVar5 + local_10 * 0x20;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar7 == 5) {
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      local_10 = 0;
      if (local_c == 0) {
        return 0;
      }
      do {
        if (*puVar6 == 0) {
          return local_14;
        }
        param_4 = (uint *)0x0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            if (*puVar6 == 0) break;
            local_14 = FUN_005c887d(param_1,param_2,param_3,puVar6);
            if (local_14 < 0) {
              return local_14;
            }
            param_4 = (uint *)((int)param_4 + 1);
          } while (param_4 < uVar2);
        }
        local_10 = local_10 + 1;
        if (local_c <= local_10) {
          return local_14;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5c8b31 FUN_005c8b31

int FUN_005c8b31(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar5 = param_4;
  piVar4 = param_3;
  piVar1 = (int *)*param_1;
  iVar6 = piVar1[1];
  local_c = piVar1[4];
  local_18 = 0;
  if (local_c == 0) {
    local_c = 1;
  }
  if (-1 < iVar6) {
    if (iVar6 < 4) {
      uVar2 = piVar1[5];
      uVar3 = piVar1[6];
      iVar6 = *piVar1;
      uVar8 = (uint)((uVar2 & 3) != 0) + (uVar2 >> 2);
      local_10 = uVar8;
      local_8 = uVar2;
      if (iVar6 == 1) {
        local_1c = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar8) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar6 = (int)param_3 << 2;
                  do {
                    uVar7 = __ftol();
                    *(undefined4 *)(iVar6 + *param_2) = uVar7;
                    uVar9 = uVar9 + 1;
                    iVar6 = iVar6 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *piVar4 = *piVar4 + local_10 * 0x20;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      else if (iVar6 == 2) {
        local_1c = 0;
        if (local_c != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *param_4;
                if (uVar9 == 0) break;
                if (uVar9 < uVar8) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar6 = (int)param_3 << 2;
                  do {
                    uVar7 = __ftol();
                    *(undefined4 *)(iVar6 + *param_2) = uVar7;
                    iVar6 = iVar6 + uVar3 * 4;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < local_8);
                }
                *piVar4 = *piVar4 + local_10 * 0x20;
                *param_4 = *param_4 - local_10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      else {
        if (iVar6 != 3) {
          return -0x7fffbffb;
        }
        local_1c = 0;
        if (local_c != 0) {
          do {
            if (*puVar5 == 0) break;
            param_4 = (uint *)0x0;
            if (uVar3 != 0) {
              do {
                uVar9 = *puVar5;
                if (uVar9 == 0) break;
                if (uVar9 < uVar8) {
                  local_8 = uVar9 << 2;
                  local_10 = uVar9;
                }
                uVar9 = 0;
                if (local_8 != 0) {
                  iVar6 = (int)param_4 << 2;
                  do {
                    *(float *)(iVar6 + *param_2) = (float)*(double *)(*param_3 + uVar9 * 8);
                    uVar9 = uVar9 + 1;
                    iVar6 = iVar6 + uVar3 * 4;
                  } while (uVar9 < local_8);
                }
                *param_3 = *param_3 + local_10 * 0x20;
                *puVar5 = *puVar5 - local_10;
                param_4 = (uint *)((int)param_4 + 1);
              } while (param_4 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar6 == 5) {
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      local_14 = 0;
      if (local_c == 0) {
        return 0;
      }
      do {
        if (*puVar5 == 0) {
          return local_18;
        }
        param_4 = (uint *)0x0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            if (*puVar5 == 0) break;
            local_18 = FUN_005c8b31(param_1,param_2,param_3,puVar5);
            if (local_18 < 0) {
              return local_18;
            }
            param_4 = (uint *)((int)param_4 + 1);
          } while (param_4 < uVar2);
        }
        local_14 = local_14 + 1;
        if (local_c <= local_14) {
          return local_18;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5c8e04 FUN_005c8e04

undefined4 FUN_005c8e04(uint param_1,int *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int local_10;
  uint local_c;
  undefined4 local_8;
  
  *param_2 = 0;
  local_8 = 0;
  local_10 = 0;
  iVar3 = FUN_005d7113(param_1,0x42415443,&local_10,&param_1);
  if (iVar3 < 0) {
    local_8 = 0;
  }
  else if (local_10 != 0) {
    if (param_1 < 0x14) {
      local_8 = 0x80004005;
    }
    else {
      uVar2 = *(uint *)(local_10 + 0xc);
      if (param_1 < uVar2 * 4 + 0x14) {
LAB_005c8e66:
        local_8 = 0x80004005;
      }
      else {
        local_c = 0;
        if (uVar2 != 0) {
          piVar4 = (int *)(*(int *)(local_10 + 0x10) + local_10 + 0x10);
          do {
            iVar3 = 0;
            for (uVar5 = piVar4[-4]; (uVar5 < param_1 && (*(char *)(uVar5 + local_10) != '\0'));
                uVar5 = uVar5 + 1) {
              iVar3 = iVar3 + 1;
            }
            if (param_1 <= (uint)(piVar4[-4] + iVar3)) goto LAB_005c8e66;
            sVar1 = (short)piVar4[-3];
            iVar3 = 0;
            if (sVar1 == 0) {
              iVar3 = 4;
            }
            else if ((sVar1 == 1) || (sVar1 == 2)) {
              iVar3 = 0x10;
            }
            else if (sVar1 != 3) goto LAB_005c8e66;
            if (((*piVar4 != 0) && (iVar3 != 0)) &&
               (param_1 <= (uint)*(ushort *)(piVar4 + -2) * iVar3 + *piVar4)) goto LAB_005c8e66;
            local_c = local_c + 1;
            piVar4 = piVar4 + 5;
          } while (local_c < uVar2);
        }
        *param_2 = local_10;
      }
    }
  }
  return local_8;
}


// ==== 0x5c8eec FUN_005c8eec

void __fastcall FUN_005c8eec(int param_1)

{
  int iVar1;
  void *_Memory;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while (param_1 != iVar1) {
    _Memory = *(void **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)((int)_Memory + 0x10);
    *(void **)((int)_Memory + 0x10) = _Memory;
    FUN_005c8eec();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 0x10);
  }
  return;
}


// ==== 0x5c8f17 FUN_005c8f17

void __fastcall FUN_005c8f17(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== 0x5c8f26 FUN_005c8f26

void * __thiscall FUN_005c8f26(void *param_1,byte param_2)

{
  FUN_005cd1d4();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5c8f42 FUN_005c8f42

void * __thiscall FUN_005c8f42(void *param_1,byte param_2)

{
  FUN_005cd25f();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5c8f5e FUN_005c8f5e

void __fastcall FUN_005c8f5e(undefined4 *param_1)

{
  param_1[2] = 0xffffffff;
  *param_1 = 0x7fffffff;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = 1;
  return;
}


// ==== 0x5c8f80 FUN_005c8f80

void __fastcall FUN_005c8f80(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  if ((piVar1 != (int *)0x0) &&
     ((iVar2 = *param_1, iVar2 == 4 ||
      ((4 < iVar2 && (((iVar2 < 10 || (iVar2 == 0xf)) || (iVar2 == 0x10)))))))) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[1] = 0;
  }
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[4] = 0;
  }
  if (param_1[6] != 0) {
    FUN_005c8f42(1);
    param_1[6] = 0;
  }
  return;
}


// ==== 0x5c8fd2 FUN_005c8fd2

undefined4 FUN_005c8fd2(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  
  uVar2 = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    iVar1 = 4;
    bVar5 = true;
    piVar3 = param_2;
    piVar4 = &DAT_006a08b8;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *piVar3 == *piVar4;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar1 = 4;
      bVar5 = true;
      piVar3 = &DAT_006abe14;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *param_2 == *piVar3;
        param_2 = param_2 + 1;
        piVar3 = piVar3 + 1;
      } while (bVar5);
      if (!bVar5) {
        return 0x80004002;
      }
    }
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
  }
  return uVar2;
}


// ==== 0x5c9025 FUN_005c9025

undefined4 __thiscall FUN_005c9025(int param_1,int param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  
  *(undefined4 *)(param_2 + 0x20) = 4;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  if ((param_3 != (int *)0x0) &&
     (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar1)) {
    iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar2 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar1)) {
    iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar2 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) && (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), uVar1 < *param_4)
     ) {
    return 0x80004005;
  }
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
  return 0;
}


// ==== 0x5c90b3 FUN_005c90b3

uint __thiscall FUN_005c90b3(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar1 = *(int *)(param_1 + 0x28) + iVar2;
  uVar3 = -(uint)(uVar1 < (uint)(iVar2 + 4 + param_2)) & 0x80004005;
  if ((-1 < (int)uVar3) && (*(int *)(iVar2 + param_2) != 0)) {
    uVar4 = iVar2 + *(int *)(iVar2 + param_2) + param_2 + 4;
    uVar3 = -(uint)(uVar1 < uVar4) & 0x80004005;
    if ((-1 < (int)uVar3) && (*(char *)(uVar4 - 1) != '\0')) {
      uVar3 = 0x80004005;
    }
  }
  return uVar3;
}


// ==== 0x5c90f8 FUN_005c90f8

uint __thiscall FUN_005c90f8(int param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0x2c) + param_2);
  puVar4 = puVar1 + 1;
  uVar3 = -(uint)((uint *)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c)) < puVar4) &
          0x80004005;
  if (-1 < (int)uVar3) {
    if (*puVar1 < 2) {
LAB_005c914a:
      uVar3 = 0x80004005;
    }
    else {
      uVar3 = FUN_005c90b3(param_2);
      if (-1 < (int)uVar3) {
        for (; cVar2 = (char)*puVar4, cVar2 != '\0'; puVar4 = (uint *)((int)puVar4 + 1)) {
          if ((((cVar2 == '.') || (cVar2 == '@')) || (cVar2 == '[')) || (cVar2 == ']'))
          goto LAB_005c914a;
        }
      }
    }
  }
  return uVar3;
}


// ==== 0x5c9152 FUN_005c9152

int FUN_005c9152(int *param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint local_c;
  int local_8;
  
  piVar1 = param_1;
  local_c = 0;
  if ((param_1[0x21] == 3) || ((param_3 & 3) != param_3)) {
    return -0x7789f794;
  }
  param_1[0xc] = -1;
  iVar6 = param_1[0xd] * 0xac + param_1[7];
  param_1[0xf] = param_1[0xf] ^ (param_1[0xf] ^ param_3) & 1;
  uVar3 = param_1[0xf];
  if ((uVar3 & 1) == 0) {
    uVar2 = param_3 >> 1 & 1;
  }
  else {
    uVar2 = 1;
  }
  uVar3 = (uVar2 * 2 ^ uVar3) & 2 ^ uVar3;
  param_1[0xf] = uVar3;
  if ((uVar3 & 2) == 0) {
    if (*(int *)(iVar6 + 0x84) == 0) {
      iVar4 = (**(code **)(*(int *)param_1[2] + 0xf0))((int *)param_1[2]);
      if (iVar4 < 0) {
        return iVar4;
      }
      FUN_005e8fb1(1);
      local_c = 0;
      if (*(int *)(iVar6 + 0x2c) != 0) {
        local_8 = 0;
        do {
          iVar4 = *(int *)(iVar6 + 0x30) + local_8;
          param_3 = 0;
          if (*(int *)(iVar4 + 0x24) != 0) {
            param_1 = (int *)0x0;
            do {
              piVar5 = (int *)(*(int *)(iVar4 + 0x28) + (int)param_1);
              uVar3 = *(uint *)(&DAT_006dc274 + *piVar5 * 0x1c);
              if ((uVar3 & 0xff000000) != 0x6000000) goto switchD_005c925a_caseD_6000008;
              if (0x6000102 < uVar3) {
                if (uVar3 != 0x6000105) {
                  if (uVar3 == 0x6000202) goto switchD_005c925a_caseD_6000002;
                  if (uVar3 != 0x6000205) {
                    if (uVar3 == 0x6000302) goto switchD_005c925a_caseD_6000002;
                    if (uVar3 != 0x6000305) {
                      if (uVar3 == 0x6000402) goto switchD_005c925a_caseD_6000002;
                      if (uVar3 != 0x6000405) goto switchD_005c925a_default;
                    }
                  }
                }
switchD_005c925a_caseD_6000005:
                (**(code **)(*(int *)piVar1[2] + 0x1b4))
                          ((int *)piVar1[2],piVar5[1],piVar5[0x13],piVar5[0x2a]);
                goto switchD_005c925a_caseD_6000008;
              }
              if (uVar3 == 0x6000102) {
switchD_005c925a_caseD_6000002:
                (**(code **)(*(int *)piVar1[2] + 0x178))
                          ((int *)piVar1[2],piVar5[1],piVar5[0x13],piVar5[0x2a]);
              }
              else {
                switch(uVar3) {
                case 0x6000000:
                  (**(code **)(*(int *)piVar1[2] + 0x170))((int *)piVar1[2],0);
                  break;
                case 0x6000001:
                  (**(code **)(*(int *)piVar1[2] + 0x1ac))((int *)piVar1[2],0);
                  break;
                case 0x6000002:
                  goto switchD_005c925a_caseD_6000002;
                case 0x6000003:
                  (**(code **)(*(int *)piVar1[2] + 0x180))
                            ((int *)piVar1[2],piVar5[1],piVar5[0x13],piVar5[0x2a]);
                  break;
                case 0x6000004:
                  (**(code **)(*(int *)piVar1[2] + 0x188))
                            ((int *)piVar1[2],piVar5[1],piVar5[0x13],piVar5[0x2a]);
                  break;
                case 0x6000005:
                  goto switchD_005c925a_caseD_6000005;
                case 0x6000006:
                  (**(code **)(*(int *)piVar1[2] + 0x1bc))
                            ((int *)piVar1[2],piVar5[1],piVar5[0x13],piVar5[0x2a]);
                  break;
                case 0x6000007:
                  (**(code **)(*(int *)piVar1[2] + 0x1c4))
                            ((int *)piVar1[2],piVar5[1],piVar5[0x13],piVar5[0x2a]);
                  break;
                case 0x6000008:
                  break;
                default:
switchD_005c925a_default:
                  FUN_005e8fb1(0);
                  return -0x7fffbffb;
                }
              }
switchD_005c925a_caseD_6000008:
              param_3 = param_3 + 1;
              param_1 = (int *)((int)param_1 + 0xac);
            } while (param_3 < *(uint *)(iVar4 + 0x24));
          }
          local_c = local_c + 1;
          local_8 = local_8 + 0x3c;
        } while (local_c < *(uint *)(iVar6 + 0x2c));
      }
      FUN_005e8fb1(0);
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf4))((int *)piVar1[2],iVar6 + 0x84);
      if (iVar4 < 0) {
        return iVar4;
      }
    }
    iVar4 = (**(code **)(**(int **)(iVar6 + 0x84) + 0x10))(*(int **)(iVar6 + 0x84));
    if (iVar4 < 0) {
      return iVar4;
    }
    if (*(int *)(iVar6 + 0x88) == 0) {
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf0))((int *)piVar1[2]);
      if (iVar4 < 0) {
        return iVar4;
      }
      FUN_005e8fb1(1);
      if (*(int *)(iVar6 + 0x90) != 0) {
        (**(code **)(*(int *)piVar1[2] + 0x178))
                  ((int *)piVar1[2],0,piVar1[0x2a],*(int *)(iVar6 + 0x90));
      }
      if (*(int *)(iVar6 + 0x94) != 0) {
        (**(code **)(*(int *)piVar1[2] + 0x188))
                  ((int *)piVar1[2],0,piVar1[0x2b],*(int *)(iVar6 + 0x94));
      }
      if (*(int *)(iVar6 + 0x98) != 0) {
        (**(code **)(*(int *)piVar1[2] + 0x180))
                  ((int *)piVar1[2],0,piVar1[0x2c],*(int *)(iVar6 + 0x98));
      }
      if (*(int *)(iVar6 + 0x9c) != 0) {
        (**(code **)(*(int *)piVar1[2] + 0x1b4))
                  ((int *)piVar1[2],0,piVar1[0x2a],*(int *)(iVar6 + 0x9c));
      }
      if (*(int *)(iVar6 + 0xa0) != 0) {
        (**(code **)(*(int *)piVar1[2] + 0x1c4))
                  ((int *)piVar1[2],0,piVar1[0x2b],*(int *)(iVar6 + 0xa0));
      }
      if (*(int *)(iVar6 + 0xa4) != 0) {
        (**(code **)(*(int *)piVar1[2] + 0x1bc))
                  ((int *)piVar1[2],0,piVar1[0x2c],*(int *)(iVar6 + 0xa4));
      }
      FUN_005e8fb1(0);
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf4))((int *)piVar1[2],iVar6 + 0x88);
      if (iVar4 < 0) {
        return iVar4;
      }
    }
    local_c = (**(code **)(**(int **)(iVar6 + 0x88) + 0x10))(*(int **)(iVar6 + 0x88));
    if ((int)local_c < 0) {
      return local_c;
    }
  }
  if ((*(byte *)(piVar1 + 0xf) & 1) == 0) {
    if (*(int *)(iVar6 + 0x80) == 0) {
      puVar7 = (undefined4 *)(iVar6 + 0x3c);
      for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      puVar7 = *(undefined4 **)(iVar6 + 0x38);
      for (uVar3 = (uint)(*(int *)(iVar6 + 0x34) * 0x68) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar7 = 0;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      uVar3 = 0;
      if (*(int *)(iVar6 + 0x34) != 0) {
        iVar4 = 0;
        do {
          *(undefined4 *)(iVar4 + *(int *)(iVar6 + 0x38)) = 3;
          *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x48 + iVar4) = 0x3f800000;
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + 0x68;
        } while (uVar3 < *(uint *)(iVar6 + 0x34));
      }
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf0))((int *)piVar1[2]);
      if (iVar4 < 0) {
        return iVar4;
      }
      piVar1[0x21] = 1;
      FUN_005e8fb1(1);
      uVar3 = 0;
      if (*(int *)(iVar6 + 0x2c) != 0) {
        do {
          (**(code **)(*piVar1 + 0x104))(piVar1,uVar3);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(iVar6 + 0x2c));
      }
      FUN_005e8fb1(0);
      piVar1[0x21] = 0;
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf4))((int *)piVar1[2],iVar6 + 0x80);
      if (iVar4 < 0) {
        return iVar4;
      }
    }
    iVar4 = (**(code **)(**(int **)(iVar6 + 0x80) + 0x10))(*(int **)(iVar6 + 0x80));
    if (iVar4 < 0) {
      return iVar4;
    }
    if (*(int *)(iVar6 + 0x8c) == 0) {
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf0))((int *)piVar1[2]);
      if (iVar4 < 0) {
        return iVar4;
      }
      FUN_005e8fb1(1);
      param_1 = (int *)0x0;
      if (*(int *)(iVar6 + 0xa8) != 0) {
        do {
          (**(code **)(*(int *)piVar1[2] + 0x104))((int *)piVar1[2],param_1,0);
          uVar3 = 0x1c;
          do {
            piVar5 = (int *)piVar1[2];
            if (*(int *)(uVar3 + 0x6db9c0) == 0) {
              (**(code **)(*piVar5 + 0x114))
                        (piVar5,param_1,*(uint *)(uVar3 + 0x6db9bc) & 0xffffff,0);
            }
            else {
              (**(code **)(*piVar5 + 0x114))
                        (piVar5,param_1,*(uint *)(uVar3 + 0x6db9bc) & 0xffffff,
                         *(undefined4 *)(*(int *)(uVar3 + 0x6db9c0) + 4));
            }
            uVar3 = uVar3 + 0x1c;
          } while (uVar3 < 0x16c);
          param_1 = (int *)((int)param_1 + 1);
        } while (param_1 < *(uint *)(iVar6 + 0xa8));
      }
      FUN_005e8fb1(0);
      iVar4 = (**(code **)(*(int *)piVar1[2] + 0xf4))((int *)piVar1[2],iVar6 + 0x8c);
      if (iVar4 < 0) {
        return iVar4;
      }
    }
    local_c = (**(code **)(**(int **)(iVar6 + 0x8c) + 0x10))(*(int **)(iVar6 + 0x8c));
    if ((int)local_c < 0) {
      return local_c;
    }
  }
  puVar7 = (undefined4 *)(iVar6 + 0x3c);
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar7 = *(undefined4 **)(iVar6 + 0x38);
  for (uVar3 = (uint)(*(int *)(iVar6 + 0x34) * 0x68) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  iVar4 = 0;
  uVar3 = 0;
  if (*(int *)(iVar6 + 0x34) != 0) {
    do {
      *(undefined4 *)(iVar4 + *(int *)(iVar6 + 0x38)) = 3;
      *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x48 + iVar4) = 0x3f800000;
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x68;
    } while (uVar3 < *(uint *)(iVar6 + 0x34));
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(iVar6 + 0x2c);
  }
  piVar1[0x21] = 3;
  return local_c;
}


// ==== 0x5c9718 FUN_005c9718

int FUN_005c9718(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x84) == 3) {
    *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
    *(int *)(param_1 + 0x84) = 0;
    if ((*(byte *)(param_1 + 0x3c) & 2) == 0) {
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x84 + *(int *)(param_1 + 0x1c));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 < 0)) {
        return iVar2;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x88 + *(int *)(param_1 + 0x1c));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 < 0)) {
        return iVar2;
      }
    }
    if ((*(byte *)(param_1 + 0x3c) & 1) == 0) {
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x8c + *(int *)(param_1 + 0x1c));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 < 0)) {
        return iVar2;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x80 + *(int *)(param_1 + 0x1c));
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
      }
    }
  }
  else {
    iVar2 = -0x7fffbffb;
  }
  return iVar2;
}


// ==== 0x5c97cb FUN_005c97cb

int __thiscall FUN_005c97cb(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  ushort *puVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  undefined1 local_43c [4];
  undefined1 auStack_438 [516];
  undefined4 local_234;
  undefined4 local_230;
  undefined1 local_15c [61];
  byte local_11f;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_20 = (int *)0x0;
  local_10 = 0xff;
  local_c = 0x11;
  if (param_3 == -1) {
    param_3 = param_2[1];
  }
  piVar7 = param_2;
  if (*param_2 == -1) {
    piVar7 = (int *)param_2[0x19];
  }
  uVar2 = *(uint *)(&DAT_006dc274 + *piVar7 * 0x1c);
  local_8 = param_1;
  switch(uVar2 >> 0x18) {
  case 1:
    iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0xe4))
                       (*(int **)(param_1 + 8),uVar2 & 0xffffff,piVar7[0x1a]);
    break;
  case 2:
    iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x10c))
                       (*(int **)(param_1 + 8),param_3,uVar2 & 0xffffff,piVar7[0x1a]);
    break;
  case 3:
    if (uVar2 == 0x300000d) {
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0xd4))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x1a]);
      break;
    }
    piVar4 = (int *)(piVar7[0x2a] * 0x68 +
                    *(int *)(*(int *)(param_1 + 0x34) * 0xac + 0x38 + *(int *)(param_1 + 0x1c)));
    switch(uVar2) {
    case 0x3000000:
      *piVar4 = piVar7[0x1a];
      if (*(int *)(param_1 + 0x84) == 1) {
        *piVar4 = 3;
      }
      break;
    case 0x3000001:
      piVar9 = piVar4 + 1;
      goto LAB_005c98c8;
    case 0x3000002:
      piVar9 = piVar4 + 5;
      goto LAB_005c98c8;
    case 0x3000003:
      piVar9 = piVar4 + 9;
LAB_005c98c8:
      local_18 = piVar7[0x1a];
      local_14 = piVar7[0x1b];
      local_10 = piVar7[0x1c];
      local_c = piVar7[0x1d];
      piVar10 = piVar9 + 1;
      *piVar9 = local_18;
LAB_005c9944:
      *piVar10 = local_14;
      piVar10[1] = local_10;
      piVar10[2] = local_c;
      break;
    case 0x3000004:
      local_14 = piVar7[0x1a];
      local_10 = piVar7[0x1b];
      local_c = piVar7[0x1c];
      piVar10 = piVar4 + 0xd;
      goto LAB_005c9944;
    case 0x3000005:
      local_14 = piVar7[0x1a];
      local_10 = piVar7[0x1b];
      local_c = piVar7[0x1c];
      piVar10 = piVar4 + 0x10;
      *piVar10 = local_14;
      piVar4[0x11] = local_10;
      piVar4[0x12] = local_c;
      if (*(int *)(param_1 + 0x84) == 1) {
        local_14 = 0;
        local_10 = 0;
        local_c = 0x3f800000;
        goto LAB_005c9944;
      }
      break;
    case 0x3000006:
      piVar4[0x13] = piVar7[0x1a];
      break;
    case 0x3000007:
      piVar4[0x14] = piVar7[0x1a];
      break;
    case 0x3000008:
      piVar4[0x15] = piVar7[0x1a];
      break;
    case 0x3000009:
      piVar4[0x16] = piVar7[0x1a];
      break;
    case 0x300000a:
      piVar4[0x17] = piVar7[0x1a];
      break;
    case 0x300000b:
      piVar4[0x18] = piVar7[0x1a];
      break;
    case 0x300000c:
      piVar4[0x19] = piVar7[0x1a];
    }
    if ((((*(byte *)(piVar7 + 10) & 2) == 0) && (*(int *)(param_1 + 0x84) != 3)) ||
       (iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0xcc))
                           (*(int **)(param_1 + 8),param_3,piVar4), -1 < iVar11))
    goto switchD_005c982d_default;
    iVar6 = *(int *)(local_8 + 0x84);
    goto LAB_005ca0df;
  case 4:
    piVar4 = (int *)(*(int *)(param_1 + 0x34) * 0xac + 0x3c + *(int *)(param_1 + 0x1c));
    piVar10 = piVar4;
    if (uVar2 == 0x4000000) {
LAB_005c9a12:
      local_18 = piVar7[0x1a];
      local_14 = piVar7[0x1b];
      local_10 = piVar7[0x1c];
      local_c = piVar7[0x1d];
      *piVar10 = local_18;
      piVar10[1] = local_14;
      piVar10[2] = local_10;
      piVar10[3] = local_c;
    }
    else {
      if (uVar2 == 0x4000001) {
        piVar10 = piVar4 + 4;
        goto LAB_005c9a12;
      }
      if (uVar2 == 0x4000002) {
        piVar10 = piVar4 + 8;
        goto LAB_005c9a12;
      }
      if (uVar2 == 0x4000003) {
        piVar10 = piVar4 + 0xc;
        goto LAB_005c9a12;
      }
      if (uVar2 == 0x4000004) {
        piVar4[0x10] = piVar7[0x1a];
      }
    }
    if (((*(byte *)(piVar7 + 10) & 2) != 0) || (*(int *)(param_1 + 0x84) == 3)) {
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0xc4))(*(int **)(param_1 + 8),piVar4);
      break;
    }
    goto switchD_005c982d_default;
  case 5:
    if (*(int *)(param_1 + 0x84) == 2) {
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1c))(*(int **)(param_1 + 8),local_15c);
      if (iVar11 < 0) goto LAB_005ca0e3;
      iVar11 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
      if (*(int *)(iVar11 + 0x38) == 0) {
        iVar6 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar11 = *(int *)(*(int *)(iVar11 + 0x24) + piVar7[4] + iVar6);
      if (iVar11 == 8) {
        local_11f = local_11f & 0x20;
      }
      else {
        if (iVar11 != 9) goto LAB_005c9ac9;
        local_11f = local_11f & 8;
      }
      if (local_11f == 0) {
LAB_005c9ab3:
        iVar11 = -0x7fffbffb;
        goto LAB_005ca0e3;
      }
    }
LAB_005c9ac9:
    iVar11 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
    iVar6 = *(int *)(iVar11 + 0x38);
    iVar11 = *(int *)(iVar11 + 0x28) + piVar7[5];
    if (iVar6 == 0) {
      iVar11 = *(int *)(iVar11 + *(int *)(param_1 + 0x2c));
    }
    else {
      iVar11 = *(int *)(*(int *)(iVar6 + 8) +
                       *(int *)(iVar11 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
    }
    iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x104))
                       (*(int **)(param_1 + 8),param_3,
                        *(undefined4 *)(iVar11 * 0x1c + 4 + *(int *)(param_1 + 0x24)));
    break;
  case 6:
    if (uVar2 == 0x6000008) {
      iVar11 = piVar7[0x1a];
      if (*(int *)(param_1 + 0x84) == 1) {
        iVar11 = 2;
      }
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x164))(*(int **)(param_1 + 8),iVar11);
      break;
    }
    if (*(int *)(param_1 + 0x84) == 1) goto switchD_005c982d_default;
    if (0x6000102 < uVar2) {
      if (uVar2 != 0x6000105) {
        if (uVar2 == 0x6000202) goto switchD_005c9b6d_caseD_6000002;
        if (uVar2 != 0x6000205) {
          if (uVar2 == 0x6000302) goto switchD_005c9b6d_caseD_6000002;
          if (uVar2 != 0x6000305) {
            if (uVar2 == 0x6000402) goto switchD_005c9b6d_caseD_6000002;
            if (uVar2 != 0x6000405) goto switchD_005c982d_default;
          }
        }
      }
switchD_005c9b6d_caseD_6000005:
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1b4))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x13],piVar7[0x2a]);
      goto LAB_005ca00c;
    }
    if (uVar2 == 0x6000102) {
switchD_005c9b6d_caseD_6000002:
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x178))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x13],piVar7[0x2a]);
      goto LAB_005ca00c;
    }
    switch(uVar2) {
    case 0x6000000:
      iVar11 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
      iVar6 = *(int *)(iVar11 + 0x38);
      iVar11 = *(int *)(iVar11 + 0x28) + piVar7[5];
      if (iVar6 == 0) {
        iVar11 = *(int *)(iVar11 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar11 = *(int *)(*(int *)(iVar6 + 8) +
                         *(int *)(iVar11 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      iVar6 = iVar11 * 0x1c + *(int *)(param_1 + 0x24);
      if (*(int *)(iVar6 + 0xc) == 0) {
        return -0x7fffbffb;
      }
      param_3 = iVar6;
      if (*(int *)(param_1 + 0x84) == 2) {
        if (*(int *)(iVar6 + 4) == 0) {
          puVar12 = (undefined4 *)&DAT_006db8f0;
        }
        else {
          puVar12 = &param_2;
          puVar13 = local_43c;
          uVar5 = (**(code **)(**(int **)(iVar6 + 0x10) + 0xc))
                            (*(int **)(iVar6 + 0x10),puVar13,puVar12);
          iVar11 = FUN_005d71f8(uVar5,puVar13,puVar12);
          if (iVar11 < 0) goto LAB_005ca0e3;
          if ((int *)0x40 < param_2) goto LAB_005c9ab3;
          piVar7 = (int *)0x0;
          if (param_2 != (int *)0x0) {
            do {
              iVar11 = (int)piVar7 * 8;
              *(undefined2 *)(&local_234 + (int)piVar7 * 2) = 0;
              *(undefined1 *)((int)&local_230 + iVar11 + 1) = 0;
              *(short *)((int)&local_234 + iVar11 + 2) = (short)piVar7 * 0xc;
              *(undefined1 *)(&local_230 + (int)piVar7 * 2) = 2;
              *(undefined1 *)((int)&local_230 + iVar11 + 2) = local_43c[iVar11];
              piVar7 = (int *)((int)piVar7 + 1);
              *(undefined1 *)((int)&local_230 + iVar11 + 3) = auStack_438[iVar11];
            } while (piVar7 < param_2);
          }
          (&local_234)[(int)piVar7 * 2] = local_10;
          puVar12 = &local_234;
          (&local_230)[(int)piVar7 * 2] = local_c;
        }
        iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x158))
                           (*(int **)(param_1 + 8),puVar12,&local_20);
        if ((iVar11 < 0) ||
           (iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x15c))(*(int **)(param_1 + 8),local_20)
           , iVar11 < 0)) goto LAB_005ca0e3;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
          local_20 = (int *)0x0;
        }
      }
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x170))
                         (*(int **)(param_1 + 8),*(undefined4 *)(iVar6 + 4));
      if (iVar11 < 0) goto LAB_005ca0e3;
      iVar3 = *(int *)(iVar6 + 0x14);
      if (iVar3 != 0) {
        piVar7 = *(int **)(*(int *)(iVar6 + 0x18) + 0x44);
        param_2 = (int *)0x0;
        local_24 = piVar7 + 2;
        local_1c = *piVar7 + (int)piVar7;
        local_8 = piVar7[1] + (int)piVar7;
        if (*(int *)(iVar3 + 0xc) != 0) {
          puVar8 = (ushort *)(*(int *)(iVar3 + 0x10) + iVar3 + 6);
          do {
            uVar1 = puVar8[-1];
            if (uVar1 == 0) {
              iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x188))
                                 (*(int **)(param_1 + 8),(uint)*puVar8,local_8 + (uint)*puVar8 * 4,
                                  puVar8[1]);
            }
            else if (uVar1 == 1) {
              iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x180))
                                 (*(int **)(param_1 + 8),(uint)*puVar8,
                                  (uint)*puVar8 * 0x10 + local_1c,puVar8[1]);
            }
            else if (uVar1 == 2) {
              iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x178))
                                 (*(int **)(param_1 + 8),(uint)*puVar8,local_24 + (uint)*puVar8 * 4,
                                  puVar8[1]);
            }
            if (iVar11 < 0) goto LAB_005ca0e3;
            param_2 = (int *)((int)param_2 + 1);
            puVar8 = puVar8 + 10;
          } while (param_2 < *(int **)(*(int *)(param_3 + 0x14) + 0xc));
        }
      }
      goto switchD_005c982d_default;
    case 0x6000001:
      iVar11 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
      iVar6 = *(int *)(iVar11 + 0x38);
      iVar11 = *(int *)(iVar11 + 0x28) + piVar7[5];
      if (iVar6 == 0) {
        iVar11 = *(int *)(iVar11 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar11 = *(int *)(*(int *)(iVar6 + 8) +
                         *(int *)(iVar11 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      iVar6 = iVar11 * 0x1c + *(int *)(param_1 + 0x24);
      if (*(int *)(iVar6 + 0xc) == 0) {
        return -0x7fffbffb;
      }
      param_3 = iVar6;
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1ac))
                         (*(int **)(param_1 + 8),*(undefined4 *)(iVar6 + 4));
      if (iVar11 < 0) goto LAB_005ca0e3;
      iVar3 = *(int *)(iVar6 + 0x14);
      if (iVar3 != 0) {
        piVar7 = *(int **)(*(int *)(iVar6 + 0x18) + 0x44);
        param_2 = (int *)0x0;
        local_28 = piVar7 + 2;
        local_2c = *piVar7 + (int)piVar7;
        local_c = piVar7[1] + (int)piVar7;
        if (*(int *)(iVar3 + 0xc) != 0) {
          puVar8 = (ushort *)(*(int *)(iVar3 + 0x10) + iVar3 + 6);
          do {
            uVar1 = puVar8[-1];
            if (uVar1 == 0) {
              iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1c4))
                                 (*(int **)(param_1 + 8),(uint)*puVar8,local_c + (uint)*puVar8 * 4,
                                  puVar8[1]);
            }
            else if (uVar1 == 1) {
              iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1bc))
                                 (*(int **)(param_1 + 8),(uint)*puVar8,
                                  (uint)*puVar8 * 0x10 + local_2c,puVar8[1]);
            }
            else if (uVar1 == 2) {
              iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1b4))
                                 (*(int **)(param_1 + 8),(uint)*puVar8,local_28 + (uint)*puVar8 * 4,
                                  puVar8[1]);
            }
            else {
              if (uVar1 != 3) goto LAB_005c9ab3;
              iVar6 = *(int *)(*(int *)(*(int *)(param_3 + 0x18) + 0x30) + (int)param_2 * 4);
              if (iVar6 != 0) {
                local_24 = *(int **)(*(int *)(param_1 + 0x8c) +
                                    *(int *)(*(int *)(iVar6 + 4) + 4) * 4);
                local_1c = 0;
                if (local_24[0xf] != 0) {
                  local_8 = 0;
                  do {
                    iVar11 = FUN_005c97cb(local_24[0x10] + local_8,*puVar8);
                    if (iVar11 < 0) goto LAB_005ca0e3;
                    local_1c = local_1c + 1;
                    local_8 = local_8 + 0xac;
                  } while (local_1c < (uint)local_24[0xf]);
                }
              }
            }
            if (iVar11 < 0) goto LAB_005ca0e3;
            param_2 = (int *)((int)param_2 + 1);
            puVar8 = puVar8 + 10;
          } while (param_2 < *(int **)(*(int *)(param_3 + 0x14) + 0xc));
        }
      }
      goto switchD_005c982d_default;
    case 0x6000002:
      goto switchD_005c9b6d_caseD_6000002;
    case 0x6000003:
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x180))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x13],piVar7[0x2a]);
      break;
    case 0x6000004:
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x188))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x13],piVar7[0x2a]);
      break;
    case 0x6000005:
      goto switchD_005c9b6d_caseD_6000005;
    case 0x6000006:
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1bc))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x13],piVar7[0x2a]);
      break;
    case 0x6000007:
      iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x1c4))
                         (*(int **)(param_1 + 8),param_3,piVar7[0x13],piVar7[0x2a]);
      break;
    default:
      goto switchD_005c982d_default;
    }
LAB_005ca00c:
    if (iVar11 < 0) goto LAB_005ca0e3;
    goto switchD_005c982d_default;
  case 7:
    if (uVar2 == 0x7000000) {
      iVar11 = 3;
    }
    else if (uVar2 == 0x7000001) {
      iVar11 = 2;
    }
    else if (uVar2 == 0x7000002) {
      iVar11 = param_3 + 0x100;
    }
    else {
      if (uVar2 != 0x7000003) goto switchD_005c982d_default;
      iVar11 = param_3 + 0x10;
    }
    iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0xb0))
                       (*(int **)(param_1 + 8),iVar11,piVar7 + 0x1a);
    break;
  case 8:
    iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x114))
                       (*(int **)(param_1 + 8),param_3,uVar2 & 0xffffff,piVar7[0x1a]);
    break;
  case 9:
    iVar6 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
    local_1c = 0;
    if (*(int *)(iVar6 + 0x3c) != 0) {
      param_2 = (int *)0x0;
      do {
        iVar11 = FUN_005c97cb(*(int *)(iVar6 + 0x40) + (int)param_2,param_3);
        if (iVar11 < 0) goto LAB_005ca0e3;
        local_1c = local_1c + 1;
        param_2 = param_2 + 0x2b;
      } while (local_1c < *(uint *)(iVar6 + 0x3c));
    }
    goto switchD_005c982d_default;
  case 10:
    iVar11 = (**(code **)(**(int **)(param_1 + 8) + 0x13c))(*(int **)(param_1 + 8),piVar7[0x1a]);
    break;
  default:
    goto switchD_005c982d_default;
  }
  if (iVar11 < 0) {
    iVar6 = *(int *)(param_1 + 0x84);
LAB_005ca0df:
    if (iVar6 != 1) goto LAB_005ca0e3;
  }
switchD_005c982d_default:
  iVar11 = 0;
LAB_005ca0e3:
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return iVar11;
}


// ==== 0x5ca175 FUN_005ca175

uint __thiscall FUN_005ca175(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  uint local_8;
  
  if ((byte *)((uint)param_2 & 0xffff) != param_2) {
    if ((byte *)((uint)param_2 & 0x7fffffff) == param_2) {
      local_8 = 0;
      if (*(int *)(param_1 + 0x10) != 0) {
        piVar3 = (int *)(*(int *)(param_1 + 0x14) + 0x24);
        do {
          if (piVar3[5] == 0) {
            iVar4 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          piVar5 = (int *)(iVar4 + *(int *)(iVar4 + 8 + *piVar3));
          pbVar7 = param_2;
          if ((*piVar5 == 0) || (pbVar6 = (byte *)(piVar5 + 1), pbVar6 == (byte *)0x0)) {
joined_r0x005ca20e:
            if (pbVar7 == (byte *)0x0) break;
          }
          else if (param_2 != (byte *)0x0) {
            do {
              bVar1 = *pbVar6;
              bVar8 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_005ca1fe:
                pbVar7 = (byte *)((1 - (uint)bVar8) - (uint)(bVar8 != 0));
                goto joined_r0x005ca20e;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar6[1];
              bVar8 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_005ca1fe;
              pbVar6 = pbVar6 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            pbVar7 = (byte *)0x0;
            goto joined_r0x005ca20e;
          }
          local_8 = local_8 + 1;
          piVar3 = piVar3 + 0x11;
        } while (local_8 < *(uint *)(param_1 + 0x10));
      }
      if (local_8 != *(uint *)(param_1 + 0x10)) {
        return local_8 * 0x44 + *(int *)(param_1 + 0x14);
      }
    }
    else {
      piVar3 = (int *)~(uint)param_2;
      if ((((*piVar3 == 3) && ((uint)piVar3[1] < *(uint *)(param_1 + 0x88))) && (piVar3[2] == 0)) &&
         ((piVar3[3] == 0 && (piVar3[6] == -1)))) {
        uVar2 = *(uint *)(*(int *)(param_1 + 0x8c) + piVar3[1] * 4);
        return ~-(uint)((*(byte *)(uVar2 + 0x20) & 4) != 0) & uVar2;
      }
    }
  }
  return 0;
}


// ==== 0x5ca273 FUN_005ca273

int FUN_005ca273(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  piVar4 = param_3;
  iVar2 = *param_2;
  piVar1 = (int *)(iVar2 + param_1);
  iVar8 = piVar1[4];
  iVar3 = piVar1[1];
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  if (iVar3 < 0) {
LAB_005ca358:
    iVar6 = 0;
  }
  else {
    if (iVar3 < 4) {
      iVar3 = piVar1[5];
      iVar5 = piVar1[6];
      iVar6 = *piVar1;
      if (((iVar6 == 1) || (iVar6 == 2)) || (iVar6 == 3)) {
        iVar6 = 4;
        iVar7 = 4;
      }
      else {
        iVar6 = 0;
        iVar7 = 0;
      }
      *param_2 = iVar2 + 0x1c;
      *param_3 = *param_3 + iVar7 * iVar5 * iVar3 * iVar8;
      iVar6 = iVar5 * iVar3 * iVar6;
    }
    else if (iVar3 == 4) {
      if ((*piVar1 < 10) || (0xe < *piVar1)) {
        iVar6 = 4;
      }
      else {
        iVar6 = 0;
      }
      *param_2 = iVar2 + 0x14;
      *param_3 = *param_3 + iVar8 * 4;
    }
    else {
      if (iVar3 != 5) goto LAB_005ca358;
      iVar3 = piVar1[5];
      param_3 = (int *)0x0;
      *param_2 = iVar2 + 0x18;
      iVar2 = *piVar4;
      iVar6 = (int)param_3;
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        iVar5 = FUN_005ca273(param_1,param_2,piVar4);
        iVar6 = iVar6 + iVar5;
      }
      *piVar4 = (*piVar4 - iVar2) * (iVar8 + -1) + *piVar4;
    }
    iVar6 = iVar6 * iVar8;
  }
  return iVar6;
}


// ==== 0x5ca361 FUN_005ca361

uint __thiscall FUN_005ca361(int param_1,int param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_c;
  undefined4 *local_8;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar3 = FUN_005d1d40(param_2,param_4,0);
  if (iVar3 != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
    if (*(int *)(iVar2 + 0x38) == 0) {
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    param_4 = *(uint *)(*(int *)(iVar2 + 0x24) + iVar7 + 0x10 + *(int *)(iVar3 + 8));
    if (*(int *)(iVar3 + 0x18) != -1) {
      return 0;
    }
    if (param_4 == 0) {
      return 0;
    }
    if (param_4 <= param_3) {
      return 0;
    }
    local_8 = (undefined4 *)0x0;
    puVar4 = *(undefined4 **)(iVar3 + 0x14);
    if (*(undefined4 **)(iVar3 + 0x14) != (undefined4 *)0x0) {
      do {
        puVar8 = puVar4;
        puVar4 = puVar8;
        if (param_3 <= (uint)puVar8[6]) break;
        puVar4 = (undefined4 *)puVar8[5];
        local_8 = puVar8;
      } while (puVar4 != (undefined4 *)0x0);
      if ((puVar4 != (undefined4 *)0x0) && ((uint)puVar4[6] <= param_3)) goto LAB_005ca4cf;
    }
    puVar4 = _malloc(0x20);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[6] = 0xffffffff;
      puVar4[5] = 0;
      puVar4[4] = 0;
    }
    if (puVar4 != (undefined4 *)0x0) {
      piVar1 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
      local_c = *(int *)(*piVar1 + 0x24) + *(int *)(iVar3 + 8);
      param_2 = *(int *)(*piVar1 + 0x28) + *(int *)(iVar3 + 0xc);
      if (*(int *)(*piVar1 + 0x38) == 0) {
        uVar5 = *(undefined4 *)(param_1 + 0x2c);
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
      }
      uVar6 = FUN_005ca273(uVar5,&local_c,&param_2);
      *puVar4 = 3;
      puVar4[1] = *(undefined4 *)(iVar3 + 4);
      puVar4[2] = *(undefined4 *)(iVar3 + 8);
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4) + 0x28);
      iVar7 = *(int *)(iVar3 + 0xc);
      puVar4[6] = param_3;
      puVar4[3] = ((uint)((param_2 - iVar2) - iVar7) / param_4) * param_3 + iVar7;
      puVar4[7] = uVar6 / param_4;
      if (local_8 == (undefined4 *)0x0) {
        puVar4[5] = *(undefined4 *)(iVar3 + 0x14);
        *(undefined4 **)(iVar3 + 0x14) = puVar4;
      }
      else {
        puVar4[5] = local_8[5];
        local_8[5] = puVar4;
      }
LAB_005ca4cf:
      return ~(uint)puVar4;
    }
  }
  return 0;
}


// ==== 0x5ca4de FUN_005ca4de

uint FUN_005ca4de(int param_1)

{
  return ~(*(int *)(param_1 + 0x34) * 0xac + *(int *)(param_1 + 0x1c));
}


// ==== 0x5ca4f3 FUN_005ca4f3

int __thiscall FUN_005ca4f3(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)~param_2;
  if ((*piVar2 == 1) && ((uint)piVar2[1] < *(uint *)(param_1 + 0x18))) {
    iVar1 = *(int *)(param_1 + 0x1c) + piVar2[1] * 0xac;
    if ((uint)piVar2[2] < *(uint *)(iVar1 + 0x2c)) {
      return piVar2[2] * 0x3c + *(int *)(iVar1 + 0x30);
    }
  }
  return 0;
}


// ==== 0x5ca526 FUN_005ca526

int __thiscall FUN_005ca526(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  uint local_8;
  
  if ((byte *)((uint)param_2 & 0xffff) == param_2) {
LAB_005ca5e3:
    iVar2 = 0;
  }
  else {
    if ((byte *)((uint)param_2 & 0x7fffffff) == param_2) {
      local_8 = 0;
      if (*(int *)(param_1 + 0x18) != 0) {
        piVar6 = (int *)(*(int *)(param_1 + 0x1c) + 0x20);
        do {
          piVar3 = (int *)(*(int *)(param_1 + 0x2c) + *piVar6);
          pbVar5 = param_2;
          if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
joined_r0x005ca5ab:
            if (pbVar5 == (byte *)0x0) break;
          }
          else if (param_2 != (byte *)0x0) {
            do {
              bVar1 = *pbVar4;
              bVar7 = bVar1 < *pbVar5;
              if (bVar1 != *pbVar5) {
LAB_005ca59b:
                pbVar5 = (byte *)((1 - (uint)bVar7) - (uint)(bVar7 != 0));
                goto joined_r0x005ca5ab;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar7 = bVar1 < pbVar5[1];
              if (bVar1 != pbVar5[1]) goto LAB_005ca59b;
              pbVar4 = pbVar4 + 2;
              pbVar5 = pbVar5 + 2;
            } while (bVar1 != 0);
            pbVar5 = (byte *)0x0;
            goto joined_r0x005ca5ab;
          }
          local_8 = local_8 + 1;
          piVar6 = piVar6 + 0x2b;
        } while (local_8 < *(uint *)(param_1 + 0x18));
      }
      if (*(uint *)(param_1 + 0x18) == local_8) goto LAB_005ca5e3;
    }
    else if ((*(int *)~(uint)param_2 != 0) ||
            (local_8 = ((int *)~(uint)param_2)[1], *(uint *)(param_1 + 0x18) <= local_8))
    goto LAB_005ca5e3;
    iVar2 = local_8 * 0xac + *(int *)(param_1 + 0x1c);
  }
  return iVar2;
}


// ==== 0x5ca5e9 FUN_005ca5e9

uint FUN_005ca5e9(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x18)) {
    uVar1 = ~(param_2 * 0xac + *(int *)(param_1 + 0x1c));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5ca608 FUN_005ca608

uint FUN_005ca608(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    piVar6 = (int *)(*(int *)(param_1 + 0x1c) + 0x20);
    do {
      piVar3 = (int *)(*piVar6 + *(int *)(param_1 + 0x2c));
      pbVar5 = param_2;
      if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
LAB_005ca66b:
        if (pbVar5 == (byte *)0x0) break;
      }
      else if (param_2 != (byte *)0x0) {
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_005ca65e:
            pbVar5 = (byte *)((1 - (uint)bVar7) - (uint)(bVar7 != 0));
            goto LAB_005ca66b;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_005ca65e;
          pbVar4 = pbVar4 + 2;
          pbVar5 = pbVar5 + 2;
        } while (bVar1 != 0);
        pbVar5 = (byte *)0x0;
        goto LAB_005ca66b;
      }
      local_8 = local_8 + 1;
      piVar6 = piVar6 + 0x2b;
    } while (local_8 < *(uint *)(param_1 + 0x18));
  }
  if (*(uint *)(param_1 + 0x18) == local_8) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(local_8 * 0xac + *(int *)(param_1 + 0x1c));
  }
  return uVar2;
}


// ==== 0x5ca69c FUN_005ca69c

uint FUN_005ca69c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_005ca526(param_2,1);
  if ((iVar1 == 0) || (*(uint *)(iVar1 + 0x2c) <= param_3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(*(int *)(iVar1 + 0x30) + param_3 * 0x3c);
  }
  return uVar2;
}


// ==== 0x5ca6c9 FUN_005ca6c9

uint FUN_005ca6c9(undefined4 param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  int extraout_ECX;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  
  iVar2 = FUN_005ca526(param_2,1);
  if (iVar2 != 0) {
    param_2 = 0;
    if (*(int *)(iVar2 + 0x2c) != 0) {
      piVar6 = (int *)(*(int *)(iVar2 + 0x30) + 0x20);
      do {
        piVar3 = (int *)(*(int *)(extraout_ECX + 0x2c) + *piVar6);
        pbVar5 = param_3;
        if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
LAB_005ca741:
          if (pbVar5 == (byte *)0x0) break;
        }
        else if (param_3 != (byte *)0x0) {
          do {
            bVar1 = *pbVar4;
            bVar7 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_005ca734:
              pbVar5 = (byte *)((1 - (uint)bVar7) - (uint)(bVar7 != 0));
              goto LAB_005ca741;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar7 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_005ca734;
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          pbVar5 = (byte *)0x0;
          goto LAB_005ca741;
        }
        param_2 = param_2 + 1;
        piVar6 = piVar6 + 0xf;
      } while (param_2 < *(uint *)(iVar2 + 0x2c));
    }
    if (*(uint *)(iVar2 + 0x2c) != param_2) {
      return ~(param_2 * 0x3c + *(int *)(iVar2 + 0x30));
    }
  }
  return 0;
}


// ==== 0x5ca76c FUN_005ca76c

undefined4 FUN_005ca76c(uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 local_24 [12];
  int local_18;
  
  iVar2 = param_1;
  piVar3 = *(int **)(param_1 + 0x98);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(int *)(param_1 + 0x98) = 0;
  }
  piVar3 = (int *)(param_1 + 0x18);
  param_1 = 0;
  if (*piVar3 != 0) {
    iVar4 = 0;
    do {
      piVar3 = *(int **)(*(int *)(iVar2 + 0x1c) + 0x80 + iVar4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x80 + iVar4) = 0;
      }
      piVar3 = *(int **)(*(int *)(iVar2 + 0x1c) + 0x84 + iVar4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x84 + iVar4) = 0;
      }
      piVar3 = *(int **)(*(int *)(iVar2 + 0x1c) + 0x88 + iVar4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x88 + iVar4) = 0;
      }
      piVar3 = *(int **)(*(int *)(iVar2 + 0x1c) + 0x8c + iVar4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x8c + iVar4) = 0;
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 0xac;
    } while (param_1 < *(uint *)(iVar2 + 0x18));
  }
  param_1 = 0;
  if (*(int *)(iVar2 + 0x20) != 0) {
    iVar4 = 0;
    do {
      piVar3 = (int *)(*(int *)(iVar2 + 0x24) + iVar4);
      iVar1 = *piVar3;
      if (((((iVar1 == 5) || (iVar1 == 6)) || (iVar1 == 7)) || ((iVar1 == 8 || (iVar1 == 9)))) &&
         (piVar3 = (int *)piVar3[1], piVar3 != (int *)0x0)) {
        (**(code **)(*piVar3 + 0x44))(piVar3,0,local_24);
        if ((local_18 == 0) &&
           (piVar3 = *(int **)(*(int *)(iVar2 + 0x24) + 4 + iVar4), piVar3 != (int *)0x0)) {
          (**(code **)(*piVar3 + 8))(piVar3);
          *(undefined4 *)(*(int *)(iVar2 + 0x24) + 4 + iVar4) = 0;
        }
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (param_1 < *(uint *)(iVar2 + 0x20));
  }
  return 0;
}


// ==== 0x5ca899 FUN_005ca899

undefined4 FUN_005ca899(void)

{
  return 0;
}


// ==== 0x5ca89e FUN_005ca89e

undefined4 FUN_005ca89e(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    piVar1 = *(int **)(param_1 + 0xc);
    *param_2 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return uVar2;
}


// ==== 0x5ca8c9 FUN_005ca8c9

undefined4 FUN_005ca8c9(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    piVar1 = *(int **)(param_1 + 8);
    *param_2 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return uVar2;
}


// ==== 0x5ca8f4 FUN_005ca8f4

undefined4 FUN_005ca8f4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    *param_2 = PTR_s_D3DX9_Effect_Compiler_006db900;
    param_2[1] = *(undefined4 *)(param_1 + 0x10);
    param_2[2] = *(undefined4 *)(param_1 + 0x18);
    param_2[3] = 0;
  }
  return uVar1;
}


// ==== 0x5ca930 FUN_005ca930

undefined4 FUN_005ca930(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int extraout_ECX;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == (undefined4 *)0x0) {
LAB_005ca93e:
    uVar3 = 0x8876086c;
  }
  else {
    if (param_2 == 0) {
      iVar2 = *(int *)(param_1 + 0x34) * 0xac + *(int *)(param_1 + 0x1c);
    }
    else {
      iVar2 = FUN_005ca526(param_2,1);
      param_1 = extraout_ECX;
      if (iVar2 == 0) goto LAB_005ca93e;
    }
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    piVar1 = (int *)(*(int *)(iVar2 + 0x20) + *(int *)(param_1 + 0x2c));
    if (*piVar1 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = piVar1 + 1;
    }
    *param_3 = piVar1;
    param_3[1] = *(undefined4 *)(iVar2 + 0x2c);
    param_3[2] = *(undefined4 *)(iVar2 + 0x24);
  }
  return uVar3;
}


// ==== 0x5ca99e FUN_005ca99e

int FUN_005ca99e(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  local_8 = 0;
  if (param_3 == (undefined4 *)0x0) {
    local_8 = -0x7789f794;
  }
  else {
    iVar1 = FUN_005ca4f3(param_2,0);
    if (iVar1 == 0) {
      local_8 = -0x7789f794;
    }
    else {
      puVar4 = param_3;
      for (iVar6 = 0x117; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      piVar2 = (int *)(*(int *)(iVar1 + 0x20) + *(int *)(param_1 + 0x2c));
      if (*piVar2 == 0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = piVar2 + 1;
      }
      *param_3 = piVar2;
      param_3[1] = *(undefined4 *)(iVar1 + 0x2c);
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[0x85] = 0;
      param_3[0x106] = 0;
      if (*(int *)(iVar1 + 0x34) != -1) {
        iVar3 = *(int *)(iVar1 + 0x34) * 0xac + *(int *)(iVar1 + 0x28);
        iVar6 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 0xc) * 4);
        iVar5 = *(int *)(iVar6 + 0x38);
        iVar6 = *(int *)(iVar6 + 0x28) + *(int *)(iVar3 + 0x14);
        if (iVar5 == 0) {
          iVar6 = *(int *)(iVar6 + *(int *)(param_1 + 0x2c));
        }
        else {
          iVar6 = *(int *)(*(int *)(iVar5 + 8) +
                          *(int *)(iVar6 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
        }
        piVar2 = *(int **)(iVar6 * 0x1c + *(int *)(param_1 + 0x24) + 0x10);
        if (piVar2 != (int *)0x0) {
          puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0xc))(piVar2);
          param_3[2] = *puVar4;
          local_8 = FUN_005d71f8(puVar4,param_3 + 5,param_3 + 4);
          if (local_8 < 0) {
            return local_8;
          }
        }
      }
      if (*(int *)(iVar1 + 0x38) != -1) {
        iVar5 = *(int *)(iVar1 + 0x38) * 0xac + *(int *)(iVar1 + 0x28);
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar5 + 0xc) * 4);
        iVar6 = *(int *)(iVar1 + 0x38);
        iVar1 = *(int *)(iVar1 + 0x28) + *(int *)(iVar5 + 0x14);
        if (iVar6 == 0) {
          iVar1 = *(int *)(iVar1 + *(int *)(param_1 + 0x2c));
        }
        else {
          iVar1 = *(int *)(*(int *)(iVar6 + 8) +
                          *(int *)(iVar1 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
        }
        piVar2 = *(int **)(iVar1 * 0x1c + *(int *)(param_1 + 0x24) + 0x10);
        if (piVar2 != (int *)0x0) {
          puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0xc))(piVar2);
          param_3[3] = *puVar4;
          local_8 = FUN_005d71f8(puVar4,param_3 + 0x86,param_3 + 0x85);
          if (-1 < local_8) {
            local_8 = FUN_005d75b0(puVar4,param_3 + 0x107,param_3 + 0x106);
          }
        }
      }
    }
  }
  return local_8;
}


// ==== 0x5cab37 FUN_005cab37

undefined4 FUN_005cab37(void)

{
  return 0x80004005;
}


// ==== 0x5cab3f FUN_005cab3f

undefined4 __thiscall FUN_005cab3f(int param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = param_3;
  if (param_4 != (int *)0x0) {
    iVar2 = *(int *)(param_4[2] + param_3 * 4);
  }
  iVar2 = iVar2 * 0x1c + *(int *)(param_1 + 0x24);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  piVar3 = *(int **)(iVar2 + 4);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  *(int **)(iVar2 + 4) = param_2;
  if (param_4 != (int *)0x0) {
    for (piVar3 = (int *)param_4[4]; piVar3 != param_4; piVar3 = (int *)piVar3[4]) {
      if (*piVar3 != 0) {
        iVar4 = *(int *)(piVar3[2] + param_3 * 4) * 0x1c + *(int *)(*piVar3 + 0x24);
        piVar1 = *(int **)(iVar2 + 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        piVar1 = *(int **)(iVar4 + 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(iVar4 + 4) = 0;
        }
        *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
      }
    }
  }
  return 0;
}


// ==== 0x5cabd8 FUN_005cabd8

int __thiscall FUN_005cabd8(int param_1,char *param_2,int param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  iVar4 = param_3;
  if (param_4 != (int *)0x0) {
    iVar4 = *(int *)(param_4[2] + param_3 * 4);
  }
  iVar4 = iVar4 * 0x1c + *(int *)(param_1 + 0x24);
  if (param_2 != (char *)0x0) {
    pcVar5 = param_2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pcVar5 = pcVar5 + (1 - (int)(param_2 + 1));
    piVar2 = *(int **)(iVar4 + 4);
    if ((piVar2 == (int *)0x0) ||
       (pcVar6 = (char *)(**(code **)(*piVar2 + 0x10))(piVar2), pcVar6 < pcVar5)) {
      local_c = thunk_FUN_005d65b0(pcVar5,&local_8);
      if (local_c < 0) goto LAB_005cacea;
    }
    else {
      local_8 = *(int **)(iVar4 + 4);
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))(local_8);
      }
    }
    pcVar6 = (char *)(**(code **)(*local_8 + 0xc))(local_8);
    for (uVar7 = (uint)pcVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar7 = (uint)pcVar5 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar6 = *param_2;
      param_2 = param_2 + 1;
      pcVar6 = pcVar6 + 1;
    }
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
  }
  piVar2 = *(int **)(iVar4 + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(iVar4 + 4) = 0;
  }
  *(int **)(iVar4 + 4) = local_8;
  if (param_4 != (int *)0x0) {
    for (piVar2 = (int *)param_4[4]; piVar2 != param_4; piVar2 = (int *)piVar2[4]) {
      if (*piVar2 != 0) {
        iVar8 = *(int *)(piVar2[2] + param_3 * 4) * 0x1c + *(int *)(*piVar2 + 0x24);
        piVar3 = *(int **)(iVar4 + 4);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 4))(piVar3);
        }
        piVar3 = *(int **)(iVar8 + 4);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 8))(piVar3);
          *(undefined4 *)(iVar8 + 4) = 0;
        }
        *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar4 + 4);
      }
    }
  }
LAB_005cacea:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return local_c;
}


// ==== 0x5cad01 FUN_005cad01

int FUN_005cad01(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar5 = param_4;
  piVar4 = param_3;
  piVar1 = (int *)*param_1;
  iVar7 = piVar1[1];
  local_8 = piVar1[4];
  local_14 = 0;
  if (local_8 == 0) {
    local_8 = 1;
  }
  if (-1 < iVar7) {
    if (iVar7 < 4) {
      uVar2 = piVar1[5];
      uVar3 = piVar1[6];
      iVar7 = *piVar1;
      if (iVar7 == 1) {
        local_18 = 0;
        uVar10 = uVar2;
        if (local_8 != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar8 = *param_4;
                if (uVar8 == 0) break;
                if (uVar8 < uVar10) {
                  uVar10 = uVar8;
                }
                uVar8 = 0;
                if (uVar10 != 0) {
                  iVar7 = (int)param_3 << 2;
                  do {
                    *(undefined4 *)(*piVar4 + uVar8 * 4) = *(undefined4 *)(iVar7 + *param_2);
                    uVar8 = uVar8 + 1;
                    iVar7 = iVar7 + uVar3 * 4;
                  } while (uVar8 < uVar10);
                }
                *piVar4 = *piVar4 + uVar10 * 4;
                *param_4 = *param_4 - uVar10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_8);
        }
      }
      else if (iVar7 == 2) {
        local_18 = 0;
        uVar10 = uVar2;
        if (local_8 != 0) {
          do {
            if (*param_4 == 0) break;
            param_3 = (int *)0x0;
            if (uVar3 != 0) {
              do {
                uVar8 = *param_4;
                if (uVar8 == 0) break;
                if (uVar8 < uVar10) {
                  uVar10 = uVar8;
                }
                uVar8 = 0;
                if (uVar10 != 0) {
                  iVar7 = (int)param_3 << 2;
                  do {
                    *(undefined4 *)(*piVar4 + uVar8 * 4) = *(undefined4 *)(iVar7 + *param_2);
                    uVar8 = uVar8 + 1;
                    iVar7 = iVar7 + uVar3 * 4;
                  } while (uVar8 < uVar10);
                }
                *piVar4 = *piVar4 + uVar10 * 4;
                *param_4 = *param_4 - uVar10;
                param_3 = (int *)((int)param_3 + 1);
              } while (param_3 < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_8);
        }
      }
      else {
        if (iVar7 != 3) {
          return -0x7fffbffb;
        }
        local_18 = 0;
        uVar10 = uVar2;
        if (local_8 != 0) {
          do {
            if (*param_4 == 0) break;
            local_c = 0;
            if (uVar3 != 0) {
              do {
                uVar9 = 0;
                uVar8 = *param_4;
                if (uVar8 == 0) break;
                if (uVar8 < uVar10) {
                  uVar10 = uVar8;
                }
                if (uVar10 != 0) {
                  do {
                    uVar6 = __ftol();
                    *(undefined4 *)(*param_3 + uVar9 * 4) = uVar6;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < uVar10);
                }
                *param_3 = *param_3 + uVar10 * 4;
                *param_4 = *param_4 - uVar10;
                local_c = local_c + 1;
              } while (local_c < uVar3);
            }
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_8);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar7 == 5) {
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      local_10 = 0;
      if (local_8 == 0) {
        return 0;
      }
      do {
        if (*puVar5 == 0) {
          return local_14;
        }
        param_4 = (uint *)0x0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            if (*puVar5 == 0) break;
            local_14 = FUN_005c8303(param_1,param_2,param_3,puVar5);
            if (local_14 < 0) {
              return local_14;
            }
            param_4 = (uint *)((int)param_4 + 1);
          } while (param_4 < uVar2);
        }
        local_10 = local_10 + 1;
        if (local_8 <= local_10) {
          return local_14;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5caf72 FUN_005caf72

void __thiscall FUN_005caf72(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4);
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    local_8 = *(int *)(param_1 + 0x2c);
  }
  else {
    local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  local_8 = *(int *)(iVar2 + 0x24) + *(int *)(param_2 + 8) + local_8;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  param_2 = *(int *)(iVar2 + 0x28) + *(int *)(param_2 + 0xc) + iVar3;
  FUN_005c8303(&local_8,&param_2,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5cafde FUN_005cafde

void __thiscall FUN_005cafde(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4);
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    local_8 = *(int *)(param_1 + 0x2c);
  }
  else {
    local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  local_8 = *(int *)(iVar2 + 0x24) + *(int *)(param_2 + 8) + local_8;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  param_2 = *(int *)(iVar2 + 0x28) + *(int *)(param_2 + 0xc) + iVar3;
  FUN_005c85c1(&local_8,&param_2,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5cb04a FUN_005cb04a

void __thiscall FUN_005cb04a(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4);
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    local_8 = *(int *)(param_1 + 0x2c);
  }
  else {
    local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  local_8 = *(int *)(iVar2 + 0x24) + *(int *)(param_2 + 8) + local_8;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  param_2 = *(int *)(iVar2 + 0x28) + *(int *)(param_2 + 0xc) + iVar3;
  FUN_005c887d(&local_8,&param_2,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5cb0b6 FUN_005cb0b6

void __thiscall FUN_005cb0b6(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4);
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    local_8 = *(int *)(param_1 + 0x2c);
  }
  else {
    local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  local_8 = *(int *)(iVar2 + 0x24) + *(int *)(param_2 + 8) + local_8;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  param_2 = *(int *)(iVar2 + 0x28) + *(int *)(param_2 + 0xc) + iVar3;
  FUN_005c8b31(&local_8,&param_2,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5cb122 FUN_005cb122

void * __thiscall FUN_005cb122(void *param_1,byte param_2)

{
  FUN_005c8eec();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5cb13e FUN_005cb13e

undefined4 * __thiscall FUN_005cb13e(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005cd1d4();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0x20,*_Memory,FUN_005cd1d4);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5cb189 FUN_005cb189

undefined4 * __thiscall FUN_005cb189(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005c8f80();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0x1c,*_Memory,FUN_005c8f80);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5cb1d4 FUN_005cb1d4

undefined4 __thiscall FUN_005cb1d4(int param_1,uint *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar2 = param_4;
  piVar1 = param_3;
  param_2[10] = param_2[10] & 0xfffffffe;
  param_2[0xb] = 0;
  param_2[3] = 0;
  if ((param_3 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_3 + 0x10))(param_3), *puVar2 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
    *param_2 = *(uint *)(iVar4 + *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((piVar1 != (int *)0x0) &&
     (uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1), *puVar2 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
    param_2[1] = *(uint *)(iVar4 + *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((piVar1 != (int *)0x0) &&
     (uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1), *puVar2 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
    param_2[4] = *(uint *)(iVar4 + *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((piVar1 != (int *)0x0) &&
     (uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1), *puVar2 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
    param_2[5] = *(uint *)(iVar4 + *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if (((piVar1 != (int *)0x0) && (uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1), uVar3 < *puVar2))
     || (0xb2 < *param_2)) {
    return 0x80004005;
  }
  iVar4 = *param_2 * 0x1c;
  uVar3 = *(uint *)(&DAT_006dc270 + iVar4);
  if ((uVar3 != 0) && (uVar3 <= param_2[1])) {
    return 0x80004005;
  }
  if (uVar3 == 0x105) {
    uVar3 = param_2[1];
    if (((uVar3 < 0x10) || (uVar3 == 0x101)) ||
       ((uVar3 == 0x102 || ((uVar3 == 0x103 || (uVar3 == 0x104)))))) {
      if (*(int *)(&DAT_006dc274 + iVar4) == 0x800000d) {
        return 0x80004005;
      }
    }
    else if (uVar3 != 0x100) {
      return 0x80004005;
    }
  }
  param_2[0x2a] = 0;
  uVar3 = *(uint *)(&DAT_006dc274 + iVar4);
  if (uVar3 < 0x6000103) {
    if (uVar3 == 0x6000102) goto LAB_005cb40f;
    if (0x6000004 < uVar3) {
      if (uVar3 != 0x6000005) {
        if (uVar3 != 0x6000006) {
          if (uVar3 != 0x6000007) goto LAB_005cb48c;
          goto LAB_005cb3aa;
        }
LAB_005cb355:
        param_3 = (int *)(param_2[4] + *(int *)(param_1 + 0x2c));
        uVar3 = FUN_005c8286(&param_3,4);
        param_2[0x2a] = uVar3;
        uVar3 = uVar3 << 4;
        goto LAB_005cb449;
      }
      goto LAB_005cb415;
    }
    if (uVar3 != 0x6000004) {
      if (uVar3 != 0x5000000) {
        if (uVar3 < 0x6000000) goto LAB_005cb48c;
        if (0x6000001 < uVar3) {
          if (uVar3 != 0x6000002) {
            if (uVar3 != 0x6000003) goto LAB_005cb48c;
            goto LAB_005cb355;
          }
          goto LAB_005cb415;
        }
      }
      *(undefined4 *)
       (*(int *)(param_2[5] + *(int *)(param_1 + 0x2c)) * 0x1c + *(int *)(param_1 + 0x24)) =
           *(undefined4 *)(&DAT_006dc264 + iVar4);
      goto LAB_005cb48c;
    }
LAB_005cb3aa:
    param_3 = (int *)(param_2[4] + *(int *)(param_1 + 0x2c));
    uVar3 = FUN_005c8286(&param_3,1);
    param_2[0x2a] = uVar3;
    uVar3 = uVar3 << 2;
  }
  else {
    if (uVar3 != 0x6000105) {
      if ((uVar3 != 0x6000202) && (uVar3 != 0x6000205)) {
        if ((uVar3 != 0x6000302) && (uVar3 != 0x6000305)) {
          if ((uVar3 != 0x6000402) && (uVar3 != 0x6000405)) goto LAB_005cb48c;
          param_2[0x2a] = 1;
        }
        param_2[0x2a] = param_2[0x2a] + 1;
      }
      param_2[0x2a] = param_2[0x2a] + 1;
    }
LAB_005cb40f:
    param_2[0x2a] = param_2[0x2a] + 1;
LAB_005cb415:
    if ((*(int *)(&DAT_006dc274 + iVar4) == 0x6000002) ||
       (*(int *)(&DAT_006dc274 + iVar4) == 0x6000005)) {
      param_3 = (int *)(param_2[4] + *(int *)(param_1 + 0x2c));
      uVar3 = FUN_005c8286(&param_3,4);
      param_2[0x2a] = uVar3;
    }
    uVar3 = param_2[0x2a] << 4;
  }
LAB_005cb449:
  if (uVar3 != 0) {
    if ((void *)param_2[0x13] != (void *)0x0) {
      _free((void *)param_2[0x13]);
      param_2[0x13] = 0;
    }
    puVar5 = _malloc(uVar3);
    param_2[0x13] = (uint)puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    for (uVar3 = uVar3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
LAB_005cb48c:
  param_2[10] = param_2[10] | 1;
  return 0;
}


// ==== 0x5cb49a FUN_005cb49a

undefined4 __thiscall FUN_005cb49a(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_8;
  
  local_8 = 0;
  puVar3 = _malloc(0x18);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[5] = 0xffffffff;
    puVar3[3] = puVar3;
    puVar3[4] = puVar3;
  }
  if (puVar3 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3[5] = param_4;
    *puVar3 = 1;
    *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) | 1;
    puVar3[1] = param_2;
    puVar3[2] = param_3;
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4);
    iVar2 = *(int *)(iVar1 + 0x2c);
    if (iVar2 == 0) {
      *(undefined4 **)(iVar1 + 0x2c) = puVar3;
    }
    else {
      puVar3[3] = *(undefined4 *)(iVar2 + 0xc);
      puVar3[4] = *(undefined4 *)
                   (*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4) + 0x2c);
      *(undefined4 **)
       (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4) + 0x2c) +
                0xc) + 0x10) = puVar3;
      *(undefined4 **)
       (*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4) + 0x2c) + 0xc) =
           puVar3;
    }
    *(undefined4 **)(*(int *)(param_3 + 0x30) + param_4 * 4) = puVar3;
  }
  return local_8;
}


// ==== 0x5cb552 FUN_005cb552

void FUN_005cb552(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005ca361(param_2,param_3,0);
  return;
}


// ==== 0x5cb568 FUN_005cb568

undefined4 __thiscall FUN_005cb568(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int local_8;
  
  iVar1 = param_2;
  local_8 = param_1;
  if (*(int *)(param_2 + 0x10) != 0) {
    FUN_005cb13e(3);
    *(undefined4 *)(iVar1 + 0x10) = 0;
  }
  iVar4 = param_3;
  piVar2 = _malloc(param_3 * 0x20 + 4);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = iVar4;
    piVar2 = piVar2 + 1;
    CallNTimes(piVar2,0x20,param_3,FUN_005c8f17);
  }
  *(int **)(iVar1 + 0x10) = piVar2;
  if (piVar2 == (int *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    piVar2 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4);
    local_8 = *(int *)(*piVar2 + 0x24) + 0x18 + *(int *)(iVar1 + 8);
    param_2 = *(int *)(*piVar2 + 0x28) + *(int *)(iVar1 + 0xc);
    if (param_3 != 0) {
      iVar4 = 0;
      do {
        *(undefined4 *)(iVar4 + *(int *)(iVar1 + 0x10)) = 3;
        *(undefined4 *)(iVar4 + 4 + *(int *)(iVar1 + 0x10)) = *(undefined4 *)(iVar1 + 4);
        *(int *)(iVar4 + 8 + *(int *)(iVar1 + 0x10)) =
             local_8 - *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4) + 0x24)
        ;
        *(int *)(iVar4 + 0xc + *(int *)(iVar1 + 0x10)) =
             param_2 - *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4) + 0x28)
        ;
        if (*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4) + 0x38) == 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x2c);
        }
        else {
          uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
        }
        uVar3 = FUN_005ca273(uVar3,&local_8,&param_2);
        *(undefined4 *)(iVar4 + 0x1c + *(int *)(iVar1 + 0x10)) = uVar3;
        iVar4 = iVar4 + 0x20;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x5cb68d FUN_005cb68d

uint FUN_005cb68d(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_005ca175(param_2,10);
  if (iVar1 == 0) {
    iVar1 = FUN_005ca526(param_2,10);
    if (iVar1 == 0) {
      iVar1 = FUN_005ca4f3(param_2,10);
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = *(uint *)(iVar1 + 0x2c);
      uVar2 = *(uint *)(iVar1 + 0x30);
    }
    else {
      uVar3 = *(uint *)(iVar1 + 0x24);
      uVar2 = *(uint *)(iVar1 + 0x28);
    }
  }
  else {
    uVar3 = *(uint *)(iVar1 + 0x30);
    uVar2 = *(uint *)(iVar1 + 0x34);
  }
  if (uVar3 <= param_3) {
    return 0;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar2 = *(uint *)(uVar2 + 0x34);
  }
  return ~uVar2;
}


// ==== 0x5cb6f7 FUN_005cb6f7

undefined4 FUN_005cb6f7(int param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_ECX;
  
  if ((*(int *)(param_1 + 0x84) != 3) && (iVar1 = FUN_005ca526(param_2,1), iVar1 != 0)) {
    *(undefined4 *)(extraout_ECX + 0x34) = *(undefined4 *)(iVar1 + 4);
    return 0;
  }
  return 0x8876086c;
}


// ==== 0x5cb729 FUN_005cb729

int __thiscall FUN_005cb729(undefined4 param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = param_2[0xd];
  local_c = param_1;
  if (param_2[0x21] == 3) {
LAB_005cb746:
    iVar4 = -0x7789f794;
  }
  else {
    if (param_3 != 0) {
      iVar4 = FUN_005ca526(param_3,1);
      if (iVar4 == 0) goto LAB_005cb746;
      param_2[0xd] = *(int *)(iVar4 + 4);
    }
    iVar4 = (**(code **)(*(int *)param_2[2] + 0x158))((int *)param_2[2],&DAT_006db8f0,&local_8);
    if (-1 < iVar4) {
      piVar5 = param_2 + 0x26;
      if (*piVar5 == 0) {
        iVar4 = (**(code **)(*(int *)param_2[2] + 0xf0))((int *)param_2[2]);
        if (iVar4 < 0) goto LAB_005cb954;
        iVar4 = (**(code **)(*(int *)param_2[2] + 0x15c))((int *)param_2[2],local_8);
        if (((iVar4 < 0) ||
            (iVar4 = (**(code **)(*(int *)param_2[2] + 0x170))((int *)param_2[2],0), iVar4 < 0)) ||
           (iVar4 = (**(code **)(*(int *)param_2[2] + 0x1ac))((int *)param_2[2],0), iVar4 < 0)) {
          (**(code **)(*(int *)param_2[2] + 0xf4))((int *)param_2[2],piVar5);
          piVar2 = (int *)*piVar5;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
            *piVar5 = 0;
          }
          goto LAB_005cb954;
        }
        iVar4 = (**(code **)(*(int *)param_2[2] + 0xf4))((int *)param_2[2],piVar5);
        if (iVar4 < 0) goto LAB_005cb954;
      }
      iVar4 = (**(code **)(*(int *)*piVar5 + 0x10))((int *)*piVar5);
      if (-1 < iVar4) {
        iVar4 = (**(code **)(*(int *)param_2[2] + 0x15c))((int *)param_2[2],local_8);
        if (((iVar4 < 0) ||
            (iVar4 = (**(code **)(*(int *)param_2[2] + 0x170))((int *)param_2[2],0), iVar4 < 0)) ||
           ((iVar4 = (**(code **)(*(int *)param_2[2] + 0x1ac))((int *)param_2[2],0), iVar4 < 0 ||
            (iVar4 = (**(code **)(*param_2 + 0x100))(param_2,0,0), iVar4 < 0)))) {
LAB_005cb94b:
          piVar5 = (int *)*piVar5;
          iVar3 = *piVar5;
        }
        else {
          param_2[0x21] = 2;
          FUN_005e8fb1(1);
          param_3 = 0;
          if (*(int *)(param_2[0xd] * 0xac + 0x2c + param_2[7]) != 0) {
            do {
              iVar4 = (**(code **)(*param_2 + 0x104))(param_2,param_3);
              if ((iVar4 < 0) ||
                 (iVar4 = (**(code **)(*(int *)param_2[2] + 0x118))((int *)param_2[2],&local_c),
                 iVar4 < 0)) {
                FUN_005e8fb1(0);
                param_2[0x21] = 3;
                (**(code **)(*param_2 + 0x108))(param_2);
                goto LAB_005cb94b;
              }
              param_3 = param_3 + 1;
            } while (param_3 < *(uint *)(param_2[0xd] * 0xac + 0x2c + param_2[7]));
          }
          FUN_005e8fb1(0);
          param_2[0x21] = 3;
          iVar4 = (**(code **)(*param_2 + 0x108))(param_2);
          piVar5 = (int *)*piVar5;
          iVar3 = *piVar5;
          if (-1 < iVar4) {
            iVar4 = (**(code **)(iVar3 + 0x14))();
            goto LAB_005cb954;
          }
        }
        (**(code **)(iVar3 + 0x14))(piVar5);
      }
    }
  }
LAB_005cb954:
  param_2[0xd] = iVar1;
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar4;
}


// ==== 0x5cb96f FUN_005cb96f

undefined4 FUN_005cb96f(int *param_1,int param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar1 = param_1[0xd];
  local_8 = 0;
  if (param_1[0x21] == 3) {
    local_8 = 0x8876086c;
    goto LAB_005cb9e4;
  }
  if (param_3 == (uint *)0x0) {
LAB_005cb99b:
    local_8 = 0x8876086c;
  }
  else {
    if (param_2 == 0) {
      param_1[0xd] = 0;
    }
    else {
      iVar2 = FUN_005ca526(param_2,1);
      if (iVar2 == 0) goto LAB_005cb99b;
      param_1[0xd] = *(int *)(iVar2 + 4) + 1;
    }
    while ((uint)param_1[0xd] < (uint)param_1[6]) {
      iVar2 = (**(code **)(*param_1 + 0xf4))(param_1,0);
      if (-1 < iVar2) {
        *param_3 = ~(param_1[0xd] * 0xac + param_1[7]);
        goto LAB_005cb9e4;
      }
      param_1[0xd] = param_1[0xd] + 1;
    }
    *param_3 = 0;
    local_8 = 1;
  }
LAB_005cb9e4:
  param_1[0xd] = iVar1;
  return local_8;
}


// ==== 0x5cba05 FUN_005cba05

undefined4 __thiscall FUN_005cba05(int param_1,char *param_2,char *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 *puVar13;
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
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 *local_c;
  undefined1 *local_8;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)((int)param_3 + 4) * 4);
  iVar2 = *(int *)(iVar8 + 0x38);
  local_8 = (undefined1 *)0x0;
  local_c = (undefined4 *)0x0;
  if (iVar2 == 0) {
    iVar10 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  piVar4 = (int *)(*(int *)(iVar8 + 0x24) + *(int *)((int)param_3 + 8) + iVar10);
  if (iVar2 == 0) {
    iVar8 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  if (*(int *)(piVar4[2] + iVar8) == 0) {
    param_3 = (char *)0x0;
  }
  else {
    if (iVar2 == 0) {
      iVar8 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    param_3 = (char *)(piVar4[2] + 4 + iVar8);
  }
  local_10 = *piVar4;
  uVar3 = piVar4[4];
  local_14 = piVar4[1];
  if ((param_2 == (char *)0x0) || (param_3 == (char *)0x0)) goto LAB_005cbceb;
  pcVar5 = param_2;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar6 = param_3;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  local_8 = _malloc((size_t)(pcVar5 + (int)(pcVar6 + ((2 - (int)(param_3 + 1)) - (int)(param_2 + 1))
                                           )));
  if (local_8 == (undefined1 *)0x0) {
    uVar11 = 0x8007000e;
    goto LAB_005cbcff;
  }
  *local_8 = 0;
  pcVar5 = param_2;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar6 = local_8 + -1;
  do {
    pcVar12 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar12 != '\0');
  pcVar12 = param_2;
  for (uVar7 = (uint)((int)pcVar5 - (int)param_2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar6 = pcVar6 + 4;
  }
  puVar9 = (undefined2 *)(local_8 + -1);
  for (uVar7 = (int)pcVar5 - (int)param_2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar6 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar6 = pcVar6 + 1;
  }
  do {
    pcVar5 = (char *)((int)puVar9 + 1);
    puVar9 = (undefined2 *)((int)puVar9 + 1);
  } while (*pcVar5 != '\0');
  *puVar9 = 0x40;
  pcVar5 = param_3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar6 = local_8 + -1;
  do {
    pcVar12 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar12 != '\0');
  pcVar12 = param_3;
  for (uVar7 = (uint)((int)pcVar5 - (int)param_3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar7 = (int)pcVar5 - (int)param_3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar6 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (uVar3 == 0) {
LAB_005cbb6d:
    if (local_10 == 1) {
      if (uVar3 == 0) {
        uVar11 = (**(code **)(*param_4 + 0x58))(param_4,local_8,0);
      }
      else {
        uVar11 = (**(code **)(*param_4 + 0x60))(param_4,local_8,local_c,uVar3);
      }
    }
    else if (local_10 == 2) {
      if (uVar3 == 0) {
        uVar11 = (**(code **)(*param_4 + 0x68))(param_4,local_8,0);
      }
      else {
        uVar11 = (**(code **)(*param_4 + 0x70))(param_4,local_8,local_c,uVar3);
      }
    }
    else if (local_10 == 3) {
      if (local_14 == 0) {
        if (uVar3 == 0) {
          uVar11 = (**(code **)(*param_4 + 0x78))(param_4,local_8,0);
        }
        else {
          uVar11 = (**(code **)(*param_4 + 0x80))(param_4,local_8,local_c,uVar3);
        }
      }
      else if (local_14 == 1) {
        if (uVar3 == 0) {
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          uVar11 = (**(code **)(*param_4 + 0x88))(param_4,local_8,&local_24);
        }
        else {
          uVar11 = (**(code **)(*param_4 + 0x90))(param_4,local_8,local_c,uVar3);
        }
      }
      else {
        if (local_14 != 2) goto LAB_005cbceb;
        if (uVar3 == 0) {
          local_64 = 0;
          local_60 = 0;
          local_5c = 0;
          local_58 = 0;
          local_54 = 0;
          local_50 = 0;
          local_4c = 0;
          local_48 = 0;
          local_44 = 0;
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          local_2c = 0;
          local_28 = 0;
          uVar11 = (**(code **)(*param_4 + 0x98))(param_4,local_8,&local_64);
        }
        else {
          uVar11 = (**(code **)(*param_4 + 0xa0))(param_4,local_8,local_c,uVar3);
        }
      }
    }
    else if ((local_10 == 4) && (uVar3 == 0)) {
      uVar11 = (**(code **)(*param_4 + 200))(param_4,local_8,0);
    }
    else {
LAB_005cbceb:
      uVar11 = 0x80004005;
    }
  }
  else {
    local_c = _malloc(uVar3 << 6);
    if (local_c != (undefined4 *)0x0) {
      puVar13 = local_c;
      for (iVar8 = (uVar3 & 0x3ffffff) << 4; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar13 = 0;
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      goto LAB_005cbb6d;
    }
    uVar11 = 0x8007000e;
  }
  if (local_c != (undefined4 *)0x0) {
    _free(local_c);
  }
LAB_005cbcff:
  if (local_8 != (undefined1 *)0x0) {
    _free(local_8);
  }
  return uVar11;
}


// ==== 0x5cbd17 FUN_005cbd17

undefined4 FUN_005cbd17(int *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 local_20;
  uint local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint local_8;
  
  uVar1 = param_1[5];
  uVar2 = param_1[6];
  local_20 = 0;
  iVar4 = *param_1;
  local_8 = 4;
  if (uVar1 < 5) {
    local_8 = uVar1;
  }
  param_1 = (int *)0x4;
  if (uVar2 < 5) {
    param_1 = (int *)uVar2;
  }
  if (iVar4 == 1) {
    if (param_4 != (uint *)0x0) {
      local_10 = (uint)param_4;
      do {
        if (local_8 != 0) {
          param_4 = param_2;
          local_14 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              local_18 = (uint)param_1;
              puVar5 = param_4;
              do {
                iVar4 = __ftol();
                *puVar5 = (uint)(iVar4 != 0);
                puVar5 = puVar5 + 1;
                local_18 = local_18 - 1;
              } while (local_18 != 0);
            }
            param_4 = param_4 + uVar2;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
  }
  else if (iVar4 == 2) {
    if (param_4 != (uint *)0x0) {
      local_c = param_4;
      do {
        if (local_8 != 0) {
          local_10 = local_8;
          puVar5 = param_2;
          do {
            if (param_1 != (int *)0x0) {
              local_18 = (uint)param_1;
              puVar6 = puVar5;
              do {
                uVar3 = __ftol();
                *puVar6 = uVar3;
                puVar6 = puVar6 + 1;
                local_18 = local_18 - 1;
              } while (local_18 != 0);
            }
            puVar5 = puVar5 + uVar2;
            local_10 = local_10 - 1;
          } while (local_10 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        local_c = (uint *)((int)local_c + -1);
      } while (local_c != (uint *)0x0);
    }
  }
  else if (iVar4 == 3) {
    if (param_4 != (uint *)0x0) {
      local_18 = (uint)param_4;
      do {
        if (local_8 != 0) {
          local_c = param_3;
          param_4 = param_2;
          local_14 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              local_10 = (uint)param_1;
              puVar5 = local_c;
              puVar6 = param_4;
              do {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
                local_10 = local_10 - 1;
              } while (local_10 != 0);
            }
            param_4 = param_4 + uVar2;
            local_c = local_c + 4;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
  }
  else {
    local_20 = 0x8876086c;
  }
  return local_20;
}


// ==== 0x5cbec7 FUN_005cbec7

undefined4 FUN_005cbec7(int *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint *local_10;
  uint *local_c;
  uint local_8;
  
  uVar1 = param_1[5];
  uVar2 = param_1[6];
  local_24 = 0;
  iVar4 = *param_1;
  param_1 = (int *)0x4;
  if (uVar1 < 5) {
    param_1 = (int *)uVar1;
  }
  local_8 = 4;
  if (uVar2 < 5) {
    local_8 = uVar2;
  }
  if (iVar4 == 1) {
    if (param_4 != (uint *)0x0) {
      local_14 = (uint)param_4;
      do {
        if (local_8 != 0) {
          local_c = param_2;
          local_18 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              param_4 = local_c;
              local_1c = (uint)param_1;
              do {
                iVar4 = __ftol();
                local_1c = local_1c - 1;
                *param_4 = (uint)(iVar4 != 0);
                param_4 = param_4 + uVar2;
              } while (local_1c != 0);
            }
            local_c = local_c + 1;
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  else if (iVar4 == 2) {
    if (param_4 != (uint *)0x0) {
      local_1c = (uint)param_4;
      do {
        if (local_8 != 0) {
          local_10 = param_2;
          local_14 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              param_4 = local_10;
              local_18 = (uint)param_1;
              do {
                uVar3 = __ftol();
                local_18 = local_18 - 1;
                *param_4 = uVar3;
                param_4 = param_4 + uVar2;
              } while (local_18 != 0);
            }
            local_10 = local_10 + 1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
  }
  else if (iVar4 == 3) {
    if (param_4 != (uint *)0x0) {
      local_18 = (uint)param_4;
      do {
        if (local_8 != 0) {
          local_c = param_2;
          param_4 = param_3;
          local_14 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              local_10 = (uint *)param_1;
              puVar5 = param_4;
              puVar6 = local_c;
              do {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + uVar2;
                local_10 = (uint *)((int)local_10 - 1);
              } while (local_10 != (uint *)0x0);
            }
            param_4 = param_4 + 4;
            local_c = local_c + 1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
  }
  else {
    local_24 = 0x8876086c;
  }
  return local_24;
}


// ==== 0x5cc081 FUN_005cc081

undefined4 FUN_005cc081(int *param_1,float *param_2,float *param_3,float *param_4)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  float *local_c;
  uint local_8;
  
  uVar1 = param_1[5];
  iVar5 = *param_1;
  local_1c = 0;
  uVar2 = param_1[6];
  local_8 = 4;
  if (uVar1 < 5) {
    local_8 = uVar1;
  }
  param_1 = (int *)0x4;
  if (uVar2 < 5) {
    param_1 = (int *)uVar2;
  }
  if (iVar5 == 1) {
    pfVar6 = param_3;
    for (iVar5 = ((uint)param_4 & 0x3ffffff) << 4; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar6 = 0.0;
      pfVar6 = pfVar6 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)pfVar6 = 0;
      pfVar6 = (float *)((int)pfVar6 + 1);
    }
    if (param_4 != (float *)0x0) {
      local_10 = (uint)param_4;
      do {
        if (local_8 != 0) {
          param_4 = param_3;
          local_c = param_2;
          local_14 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              local_18 = (uint)param_1;
              pfVar6 = local_c;
              pfVar7 = param_4;
              do {
                fVar3 = *pfVar6;
                pfVar6 = pfVar6 + 1;
                *pfVar7 = (float)(fVar3 != 0.0);
                pfVar7 = pfVar7 + 1;
                local_18 = local_18 - 1;
              } while (local_18 != 0);
            }
            param_4 = param_4 + 4;
            local_c = local_c + uVar2;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_10 = local_10 - 1;
      } while (local_10 != 0);
    }
  }
  else if (iVar5 == 2) {
    pfVar6 = param_3;
    for (iVar5 = ((uint)param_4 & 0x3ffffff) << 4; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar6 = 0.0;
      pfVar6 = pfVar6 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)pfVar6 = 0;
      pfVar6 = (float *)((int)pfVar6 + 1);
    }
    if (param_4 != (float *)0x0) {
      local_14 = (uint)param_4;
      do {
        if (local_8 != 0) {
          param_4 = param_2;
          local_18 = local_8;
          pfVar7 = param_3;
          uVar4 = (uint)param_1;
          pfVar6 = param_2;
          pfVar8 = param_3;
          do {
            for (; uVar4 != 0; uVar4 = uVar4 - 1) {
              *pfVar7 = (float)(int)*pfVar6;
              pfVar7 = pfVar7 + 1;
              pfVar6 = pfVar6 + 1;
            }
            pfVar6 = param_4 + uVar2;
            pfVar7 = pfVar8 + 4;
            local_18 = local_18 - 1;
            uVar4 = (uint)param_1;
            param_4 = pfVar6;
            pfVar8 = pfVar7;
          } while (local_18 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
  }
  else if (iVar5 == 3) {
    pfVar6 = param_3;
    for (iVar5 = ((uint)param_4 & 0x3ffffff) << 4; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar6 = 0.0;
      pfVar6 = pfVar6 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)pfVar6 = 0;
      pfVar6 = (float *)((int)pfVar6 + 1);
    }
    if (param_4 != (float *)0x0) {
      local_18 = (uint)param_4;
      do {
        if (local_8 != 0) {
          param_4 = param_3;
          local_c = param_2;
          local_14 = local_8;
          do {
            if (param_1 != (int *)0x0) {
              local_10 = (uint)param_1;
              pfVar6 = local_c;
              pfVar7 = param_4;
              do {
                *pfVar7 = *pfVar6;
                pfVar6 = pfVar6 + 1;
                pfVar7 = pfVar7 + 1;
                local_10 = local_10 - 1;
              } while (local_10 != 0);
            }
            param_4 = param_4 + 4;
            local_c = local_c + uVar2;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_18 = local_18 - 1;
      } while (local_18 != 0);
    }
  }
  else {
    local_1c = 0x8876086c;
  }
  return local_1c;
}


// ==== 0x5cc269 FUN_005cc269

undefined4 FUN_005cc269(int *param_1,float *param_2,float *param_3,float *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  float *local_c;
  uint local_8;
  
  uVar1 = param_1[5];
  iVar4 = *param_1;
  local_1c = 0;
  uVar2 = param_1[6];
  local_8 = 4;
  if (uVar1 < 5) {
    local_8 = uVar1;
  }
  param_1 = (int *)0x4;
  if (uVar2 < 5) {
    param_1 = (int *)uVar2;
  }
  if (iVar4 == 1) {
    pfVar5 = param_3;
    for (iVar4 = ((uint)param_4 & 0x3ffffff) << 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar5 = 0.0;
      pfVar5 = pfVar5 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pfVar5 = 0;
      pfVar5 = (float *)((int)pfVar5 + 1);
    }
    if (param_4 != (float *)0x0) {
      local_14 = (uint)param_4;
      do {
        if (param_1 != (int *)0x0) {
          local_c = param_2;
          param_4 = param_3;
          local_18 = (uint)param_1;
          pfVar5 = param_3;
          pfVar6 = param_2;
          uVar3 = local_8;
          do {
            for (; uVar3 != 0; uVar3 = uVar3 - 1) {
              *pfVar5 = (float)(*pfVar6 != 0.0);
              pfVar5 = pfVar5 + 1;
              pfVar6 = pfVar6 + uVar2;
            }
            pfVar5 = param_4 + 4;
            pfVar6 = local_c + 1;
            local_18 = local_18 - 1;
            uVar3 = local_8;
            local_c = pfVar6;
            param_4 = pfVar5;
          } while (local_18 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
  }
  else if (iVar4 == 2) {
    pfVar5 = param_3;
    for (iVar4 = ((uint)param_4 & 0x3ffffff) << 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar5 = 0.0;
      pfVar5 = pfVar5 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pfVar5 = 0;
      pfVar5 = (float *)((int)pfVar5 + 1);
    }
    if (param_4 != (float *)0x0) {
      local_14 = (uint)param_4;
      do {
        if (param_1 != (int *)0x0) {
          local_c = param_2;
          param_4 = param_3;
          local_18 = (uint)param_1;
          pfVar5 = param_3;
          pfVar6 = param_2;
          uVar3 = local_8;
          do {
            for (; uVar3 != 0; uVar3 = uVar3 - 1) {
              *pfVar5 = (float)(int)*pfVar6;
              pfVar5 = pfVar5 + 1;
              pfVar6 = pfVar6 + uVar2;
            }
            pfVar5 = param_4 + 4;
            pfVar6 = local_c + 1;
            local_18 = local_18 - 1;
            uVar3 = local_8;
            local_c = pfVar6;
            param_4 = pfVar5;
          } while (local_18 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
  }
  else if (iVar4 == 3) {
    pfVar5 = param_3;
    for (iVar4 = ((uint)param_4 & 0x3ffffff) << 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar5 = 0.0;
      pfVar5 = pfVar5 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pfVar5 = 0;
      pfVar5 = (float *)((int)pfVar5 + 1);
    }
    if (param_4 != (float *)0x0) {
      local_18 = (uint)param_4;
      do {
        if (param_1 != (int *)0x0) {
          local_c = param_2;
          param_4 = param_3;
          local_14 = (uint)param_1;
          do {
            if (local_8 != 0) {
              local_10 = local_8;
              pfVar5 = param_4;
              pfVar6 = local_c;
              do {
                *pfVar5 = *pfVar6;
                pfVar5 = pfVar5 + 1;
                pfVar6 = pfVar6 + uVar2;
                local_10 = local_10 - 1;
              } while (local_10 != 0);
            }
            param_4 = param_4 + 4;
            local_c = local_c + 1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_2 = param_2 + uVar2 * uVar1;
        param_3 = param_3 + 0x10;
        local_18 = local_18 - 1;
      } while (local_18 != 0);
    }
  }
  else {
    local_1c = 0x8876086c;
  }
  return local_1c;
}


// ==== 0x5cc44f FUN_005cc44f

undefined4 FUN_005cc44f(int *param_1,uint *param_2,int *param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint *local_c;
  uint local_8;
  
  uVar2 = param_1[5];
  iVar4 = *param_1;
  uVar3 = param_1[6];
  local_20 = 0;
  local_8 = 4;
  if (uVar2 < 5) {
    local_8 = uVar2;
  }
  param_1 = (int *)0x4;
  if (uVar3 < 5) {
    param_1 = (int *)uVar3;
  }
  if (iVar4 == 1) {
    if (param_4 != 0) {
      local_18 = param_4;
      do {
        if ((*param_3 != 0) && (param_4 = 0, local_8 != 0)) {
          local_c = param_2;
          do {
            if (param_1 != (int *)0x0) {
              local_1c = (uint)param_1;
              puVar5 = local_c;
              do {
                iVar4 = __ftol();
                *puVar5 = (uint)(iVar4 != 0);
                puVar5 = puVar5 + 1;
                local_1c = local_1c - 1;
              } while (local_1c != 0);
            }
            param_4 = param_4 + 1;
            local_c = local_c + uVar3;
          } while (param_4 < local_8);
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
  }
  else if (iVar4 == 2) {
    if (param_4 != 0) {
      local_1c = param_4;
      do {
        if ((*param_3 != 0) && (param_4 = 0, puVar5 = param_2, local_8 != 0)) {
          do {
            if (param_1 != (int *)0x0) {
              local_14 = (uint)param_1;
              puVar6 = puVar5;
              do {
                uVar7 = __ftol();
                *puVar6 = uVar7;
                puVar6 = puVar6 + 1;
                local_14 = local_14 - 1;
              } while (local_14 != 0);
            }
            param_4 = param_4 + 1;
            puVar5 = puVar5 + uVar3;
          } while (param_4 < local_8);
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
  }
  else if (iVar4 == 3) {
    if (param_4 != 0) {
      local_14 = param_4;
      piVar8 = param_3;
      do {
        if ((*piVar8 != 0) && (param_3 = (int *)0x0, puVar5 = param_2, local_8 != 0)) {
          do {
            if (param_1 != (int *)0x0) {
              iVar4 = (int)param_3 << 4;
              puVar6 = puVar5;
              uVar7 = (uint)param_1;
              do {
                puVar1 = (uint *)(iVar4 + *piVar8);
                iVar4 = iVar4 + 4;
                *puVar6 = *puVar1;
                puVar6 = puVar6 + 1;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = (int *)((int)param_3 + 1);
            puVar5 = puVar5 + uVar3;
          } while (param_3 < local_8);
        }
        param_2 = param_2 + uVar3 * uVar2;
        piVar8 = piVar8 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  else {
    local_20 = 0x8876086c;
  }
  return local_20;
}


// ==== 0x5cc632 FUN_005cc632

undefined4 FUN_005cc632(int *param_1,uint *param_2,int *param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 local_1c;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint local_8;
  
  uVar2 = param_1[5];
  iVar4 = *param_1;
  uVar3 = param_1[6];
  local_1c = 0;
  local_8 = 4;
  if (uVar2 < 5) {
    local_8 = uVar2;
  }
  param_1 = (int *)0x4;
  if (uVar3 < 5) {
    param_1 = (int *)uVar3;
  }
  if (iVar4 == 1) {
    if (param_4 != 0) {
      local_10 = param_4;
      do {
        if ((*param_3 != 0) && (param_4 = 0, param_1 != (int *)0x0)) {
          local_c = param_2;
          do {
            if (local_8 != 0) {
              local_14 = local_8;
              puVar6 = local_c;
              do {
                iVar4 = __ftol();
                *puVar6 = (uint)(iVar4 != 0);
                puVar6 = puVar6 + uVar3;
                local_14 = local_14 - 1;
              } while (local_14 != 0);
            }
            param_4 = param_4 + 1;
            local_c = local_c + 1;
          } while (param_4 < param_1);
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
  }
  else if (iVar4 == 2) {
    if (param_4 != 0) {
      local_10 = param_4;
      do {
        if ((*param_3 != 0) && (param_4 = 0, param_1 != (int *)0x0)) {
          local_c = param_2;
          do {
            if (local_8 != 0) {
              local_14 = local_8;
              puVar6 = local_c;
              do {
                uVar5 = __ftol();
                *puVar6 = uVar5;
                puVar6 = puVar6 + uVar3;
                local_14 = local_14 - 1;
              } while (local_14 != 0);
            }
            param_4 = param_4 + 1;
            local_c = local_c + 1;
          } while (param_4 < param_1);
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
  }
  else if (iVar4 == 3) {
    if (param_4 != 0) {
      local_14 = param_4;
      do {
        if ((*param_3 != 0) && (param_4 = 0, param_1 != (int *)0x0)) {
          local_c = param_2;
          do {
            if (local_8 != 0) {
              iVar4 = param_4 << 4;
              local_10 = local_8;
              puVar6 = local_c;
              do {
                puVar1 = (uint *)(iVar4 + *param_3);
                iVar4 = iVar4 + 4;
                *puVar6 = *puVar1;
                puVar6 = puVar6 + uVar3;
                local_10 = local_10 - 1;
              } while (local_10 != 0);
            }
            param_4 = param_4 + 1;
            local_c = local_c + 1;
          } while (param_4 < param_1);
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  else {
    local_1c = 0x8876086c;
  }
  return local_1c;
}


// ==== 0x5cc807 FUN_005cc807

undefined4 FUN_005cc807(int *param_1,int *param_2,int *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 local_14;
  int local_10;
  uint local_8;
  
  uVar2 = param_1[5];
  iVar4 = *param_1;
  local_14 = 0;
  uVar3 = param_1[6];
  param_1 = (int *)0x4;
  if (uVar2 < 5) {
    param_1 = (int *)uVar2;
  }
  local_8 = 4;
  if (uVar3 < 5) {
    local_8 = uVar3;
  }
  if (iVar4 == 1) {
    if (param_4 != 0) {
      local_10 = param_4;
      piVar6 = param_3;
      do {
        if ((undefined4 *)*piVar6 != (undefined4 *)0x0) {
          param_4 = 0;
          puVar7 = (undefined4 *)*piVar6;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          if (param_1 != (int *)0x0) {
            param_3 = param_2;
            do {
              if (local_8 != 0) {
                iVar4 = param_4 << 4;
                piVar5 = param_3;
                uVar8 = local_8;
                do {
                  iVar1 = *piVar5;
                  piVar5 = piVar5 + 1;
                  *(float *)(iVar4 + *piVar6) = (float)(iVar1 != 0);
                  iVar4 = iVar4 + 4;
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
              param_4 = param_4 + 1;
              param_3 = param_3 + uVar3;
            } while (param_4 < param_1);
          }
        }
        param_2 = param_2 + uVar3 * uVar2;
        piVar6 = piVar6 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
  }
  else if (iVar4 == 2) {
    if (param_4 != 0) {
      local_10 = param_4;
      piVar6 = param_3;
      do {
        if ((undefined4 *)*piVar6 != (undefined4 *)0x0) {
          param_4 = 0;
          puVar7 = (undefined4 *)*piVar6;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          if (param_1 != (int *)0x0) {
            param_3 = param_2;
            do {
              if (local_8 != 0) {
                iVar4 = param_4 << 4;
                piVar5 = param_3;
                uVar8 = local_8;
                do {
                  iVar1 = *piVar5;
                  piVar5 = piVar5 + 1;
                  *(float *)(iVar4 + *piVar6) = (float)iVar1;
                  iVar4 = iVar4 + 4;
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
              param_4 = param_4 + 1;
              param_3 = param_3 + uVar3;
            } while (param_4 < param_1);
          }
        }
        param_2 = param_2 + uVar3 * uVar2;
        piVar6 = piVar6 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
  }
  else if (iVar4 == 3) {
    if (param_4 != 0) {
      local_10 = param_4;
      piVar6 = param_3;
      do {
        if ((undefined4 *)*piVar6 != (undefined4 *)0x0) {
          param_4 = 0;
          puVar7 = (undefined4 *)*piVar6;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          if (param_1 != (int *)0x0) {
            param_3 = param_2;
            do {
              if (local_8 != 0) {
                iVar4 = param_4 << 4;
                piVar5 = param_3;
                uVar8 = local_8;
                do {
                  *(int *)(iVar4 + *piVar6) = *piVar5;
                  piVar5 = piVar5 + 1;
                  iVar4 = iVar4 + 4;
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
              param_4 = param_4 + 1;
              param_3 = param_3 + uVar3;
            } while (param_4 < param_1);
          }
        }
        param_2 = param_2 + uVar3 * uVar2;
        piVar6 = piVar6 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
  }
  else {
    local_14 = 0x8876086c;
  }
  return local_14;
}


// ==== 0x5cc9cf FUN_005cc9cf

undefined4 FUN_005cc9cf(int *param_1,int *param_2,int *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 local_18;
  int local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  uVar2 = param_1[5];
  iVar4 = *param_1;
  local_18 = 0;
  uVar3 = param_1[6];
  local_8 = 4;
  if (uVar2 < 5) {
    local_8 = uVar2;
  }
  param_1 = (int *)0x4;
  if (uVar3 < 5) {
    param_1 = (int *)uVar3;
  }
  if (iVar4 == 1) {
    if (param_4 != 0) {
      local_14 = param_4;
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          param_4 = 0;
          puVar6 = (undefined4 *)*param_3;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          if (param_1 != (int *)0x0) {
            local_c = param_2;
            do {
              if (local_8 != 0) {
                iVar4 = param_4 << 4;
                piVar5 = local_c;
                uVar7 = local_8;
                do {
                  iVar1 = *piVar5;
                  piVar5 = piVar5 + uVar3;
                  *(float *)(iVar4 + *param_3) = (float)(iVar1 != 0);
                  iVar4 = iVar4 + 4;
                  uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
              }
              param_4 = param_4 + 1;
              local_c = local_c + 1;
            } while (param_4 < param_1);
          }
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  else if (iVar4 == 2) {
    if (param_4 != 0) {
      local_14 = param_4;
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          param_4 = 0;
          puVar6 = (undefined4 *)*param_3;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          if (param_1 != (int *)0x0) {
            local_c = param_2;
            do {
              if (local_8 != 0) {
                iVar4 = param_4 << 4;
                piVar5 = local_c;
                uVar7 = local_8;
                do {
                  iVar1 = *piVar5;
                  piVar5 = piVar5 + uVar3;
                  *(float *)(iVar4 + *param_3) = (float)iVar1;
                  iVar4 = iVar4 + 4;
                  uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
              }
              param_4 = param_4 + 1;
              local_c = local_c + 1;
            } while (param_4 < param_1);
          }
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  else if (iVar4 == 3) {
    if (param_4 != 0) {
      local_14 = param_4;
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          param_4 = 0;
          puVar6 = (undefined4 *)*param_3;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          if (param_1 != (int *)0x0) {
            local_c = param_2;
            do {
              if (local_8 != 0) {
                iVar4 = param_4 << 4;
                local_10 = local_8;
                piVar5 = local_c;
                do {
                  *(int *)(iVar4 + *param_3) = *piVar5;
                  iVar4 = iVar4 + 4;
                  piVar5 = piVar5 + uVar3;
                  local_10 = local_10 - 1;
                } while (local_10 != 0);
              }
              param_4 = param_4 + 1;
              local_c = local_c + 1;
            } while (param_4 < param_1);
          }
        }
        param_2 = param_2 + uVar3 * uVar2;
        param_3 = param_3 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  else {
    local_18 = 0x8876086c;
  }
  return local_18;
}


// ==== 0x5ccba6 FUN_005ccba6

int __thiscall
FUN_005ccba6(int param_1,int *param_2,int *param_3,int *param_4,uint param_5,uint param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int local_c;
  
  piVar1 = (int *)*param_2;
  iVar3 = *piVar1;
  iVar6 = piVar1[4];
  iVar2 = piVar1[1];
  local_c = 0;
  if ((param_6 != 0) || (iVar6 == 0)) {
    iVar6 = 1;
  }
  if (-1 < iVar2) {
    if (iVar2 < 4) {
      uVar5 = piVar1[6] * piVar1[5] * iVar6;
      if (iVar3 == 1) {
        param_5 = 0;
        if (uVar5 != 0) {
          do {
            iVar6 = param_5 * 4;
            param_5 = param_5 + 1;
            *(uint *)(iVar6 + *param_4) = (uint)(*(int *)(iVar6 + *param_3) != 0);
          } while (param_5 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      else {
        if (iVar3 == 2) {
          param_5 = 0;
          if (uVar5 != 0) {
            do {
              iVar6 = param_5 * 4;
              param_5 = param_5 + 1;
              *(undefined4 *)(iVar6 + *param_4) = *(undefined4 *)(iVar6 + *param_3);
            } while (param_5 < uVar5);
          }
        }
        else {
          if (iVar3 != 3) {
            return -0x7fffbffb;
          }
          param_5 = 0;
          if (uVar5 != 0) {
            do {
              iVar6 = param_5 * 4;
              param_5 = param_5 + 1;
              *(undefined4 *)(iVar6 + *param_4) = *(undefined4 *)(iVar6 + *param_3);
            } while (param_5 < uVar5);
          }
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      *param_4 = *param_4 + uVar5 * 4;
      *param_2 = *param_2 + 0x1c;
      return 0;
    }
    if (iVar2 == 4) {
      if (iVar3 == 4) {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          iVar3 = *(int *)*param_3;
          if (param_5 != 0) {
            iVar3 = *(int *)(*(int *)(param_5 + 8) + iVar3 * 4);
          }
          piVar1 = *(int **)(iVar3 * 0x1c + *(int *)(param_1 + 0x24) + 4);
          uVar4 = 0;
          if (piVar1 != (int *)0x0) {
            uVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
          }
          *(undefined4 *)*param_4 = uVar4;
          *param_3 = *param_3 + 4;
          *param_4 = *param_4 + 4;
        }
      }
      else {
        if (iVar3 < 5) {
          return -0x7fffbffb;
        }
        if (iVar3 < 10) {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            iVar3 = *(int *)*param_3;
            if (param_5 != 0) {
              iVar3 = *(int *)(*(int *)(param_5 + 8) + iVar3 * 4);
            }
            *(undefined4 *)*param_4 = *(undefined4 *)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24));
            piVar1 = *(int **)*param_4;
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
            }
            *param_3 = *param_3 + 4;
            *param_4 = *param_4 + 4;
          }
        }
        else if (iVar3 == 0xf) {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            iVar3 = *(int *)*param_3;
            if (param_5 != 0) {
              iVar3 = *(int *)(*(int *)(param_5 + 8) + iVar3 * 4);
            }
            *(undefined4 *)*param_4 = *(undefined4 *)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24));
            piVar1 = *(int **)*param_4;
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
            }
            *param_3 = *param_3 + 4;
            *param_4 = *param_4 + 4;
          }
        }
        else {
          if (iVar3 != 0x10) {
            return -0x7fffbffb;
          }
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            iVar3 = *(int *)*param_3;
            if (param_5 != 0) {
              iVar3 = *(int *)(*(int *)(param_5 + 8) + iVar3 * 4);
            }
            *(undefined4 *)*param_4 = *(undefined4 *)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24));
            piVar1 = *(int **)*param_4;
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
            }
            *param_3 = *param_3 + 4;
            *param_4 = *param_4 + 4;
          }
        }
      }
      *param_2 = *param_2 + 0x14;
      return 0;
    }
    if (iVar2 == 5) {
      uVar5 = piVar1[5];
      *param_2 = (int)(piVar1 + 6);
      do {
        if (iVar6 == 0) {
          return local_c;
        }
        param_6 = 0;
        *param_2 = (int)(piVar1 + 6);
        if (uVar5 != 0) {
          do {
            local_c = FUN_005ccba6(param_2,param_3,param_4,param_5,0);
            if (local_c < 0) {
              return local_c;
            }
            param_6 = param_6 + 1;
          } while (param_6 < uVar5);
        }
        iVar6 = iVar6 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5cce58 FUN_005cce58

void __thiscall FUN_005cce58(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4);
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    local_8 = *(int *)(param_1 + 0x2c);
  }
  else {
    local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  local_8 = *(int *)(iVar2 + 0x24) + *(int *)(param_2 + 8) + local_8;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) == 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  param_2 = *(int *)(iVar2 + 0x28) + *(int *)(param_2 + 0xc) + iVar3;
  FUN_005cad01(&local_8,&param_2,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5ccec4 FUN_005ccec4

int __thiscall FUN_005ccec4(int param_1,uint param_2,uint param_3,int param_4)

{
  int *piVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  ushort *puVar14;
  int *piVar15;
  uint local_14;
  uint local_c;
  int local_8;
  
  iVar6 = param_3;
  iVar5 = param_2;
  uVar12 = 0;
  local_8 = 0;
  if (*(int *)(param_2 + 0x2c) != 0) {
    do {
      uVar4 = *(uint *)(*(int *)(param_2 + 0x30) + uVar12 * 4);
      if (uVar4 != 0) {
        *(undefined4 *)(*(int *)(uVar4 + 0xc) + 0x10) = *(undefined4 *)(uVar4 + 0x10);
        *(undefined4 *)(*(int *)(uVar4 + 0x10) + 0xc) = *(undefined4 *)(uVar4 + 0xc);
        iVar7 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(*(int *)(uVar4 + 4) + 4) * 4);
        if (uVar4 == *(uint *)(iVar7 + 0x2c)) {
          *(uint *)(iVar7 + 0x2c) =
               -(uint)(*(uint *)(uVar4 + 0x10) != uVar4) & *(uint *)(uVar4 + 0x10);
        }
        *(uint *)(uVar4 + 0xc) = uVar4;
        *(uint *)(uVar4 + 0x10) = uVar4;
        FUN_005cb122(1);
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < *(uint *)(param_2 + 0x2c));
  }
  if (*(void **)(param_2 + 0x44) != (void *)0x0) {
    _free(*(void **)(param_2 + 0x44));
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  if (*(void **)(param_2 + 0x30) != (void *)0x0) {
    _free(*(void **)(param_2 + 0x30));
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | 1;
  *(undefined4 *)(param_2 + 0x2c) = 0;
  if (param_3 != 0) {
    iVar7 = *(int *)(param_3 + 0x10) + param_3;
    puVar8 = _malloc(*(int *)(param_3 + 0xc) << 2);
    *(undefined4 **)(param_2 + 0x30) = puVar8;
    if (puVar8 != (undefined4 *)0x0) {
      for (uVar12 = *(uint *)(param_3 + 0xc) & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_3 + 0xc);
      piVar1 = (int *)(param_3 + 0xc);
      param_3 = 0;
      local_c = 0;
      local_14 = 0;
      param_2 = 0;
      if (*piVar1 != 0) {
        puVar14 = (ushort *)(iVar7 + 8);
        do {
          uVar2 = puVar14[-2];
          if (uVar2 == 0) {
            if (local_14 <= (uint)puVar14[-1] + (uint)*puVar14) {
              local_14 = (uint)puVar14[-1] + (uint)*puVar14;
            }
          }
          else if (uVar2 == 1) {
            if (local_c <= (uint)puVar14[-1] + (uint)*puVar14) {
              local_c = (uint)puVar14[-1] + (uint)*puVar14;
            }
          }
          else if (uVar2 == 2) {
            if (param_3 <= (uint)puVar14[-1] + (uint)*puVar14) {
              param_3 = (uint)puVar14[-1] + (uint)*puVar14;
            }
          }
          else if (uVar2 != 3) {
            return -0x7fffbffb;
          }
          iVar10 = FUN_005ca175(*(int *)(puVar14 + -4) + iVar6,10);
          if ((iVar10 != 0) && (local_8 = FUN_005cb49a(iVar10,iVar5,param_2), local_8 < 0)) {
            return local_8;
          }
          param_2 = param_2 + 1;
          puVar14 = puVar14 + 10;
        } while (param_2 < *(uint *)(iVar6 + 0xc));
      }
      iVar10 = local_14 + (local_c + param_3) * 4;
      *(int *)(iVar5 + 0x3c) = iVar10;
      if (iVar10 != 0) {
        *(int *)(iVar5 + 0x3c) = iVar10 + -1;
      }
      uVar12 = *(uint *)(iVar5 + 0x3c) >> 1 | *(uint *)(iVar5 + 0x3c);
      uVar12 = uVar12 >> 2 | uVar12;
      uVar12 = uVar12 >> 4 | uVar12;
      uVar12 = uVar12 >> 8 | uVar12;
      uVar12 = uVar12 >> 0x10 | uVar12;
      *(uint *)(iVar5 + 0x3c) = uVar12;
      if (param_4 == 0) {
        uVar12 = iVar10 * 4 + 8;
        iVar10 = 4;
      }
      else {
        uVar12 = uVar12 * 8 + 0x10;
        iVar10 = 8;
      }
      puVar8 = _malloc(uVar12);
      *(undefined4 **)(iVar5 + 0x44) = puVar8;
      if (puVar8 != (undefined4 *)0x0) {
        for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
          *(undefined1 *)puVar8 = 0;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        **(int **)(iVar5 + 0x44) = iVar10 * param_3 * 4 + 8;
        (*(int **)(iVar5 + 0x44))[1] = **(int **)(iVar5 + 0x44) + iVar10 * local_c * 4;
        if (param_4 != 0) {
          return local_8;
        }
        piVar1 = *(int **)(iVar5 + 0x44);
        iVar5 = piVar1[1];
        iVar10 = *piVar1;
        param_2 = 0;
        if (*(int *)(iVar6 + 0xc) == 0) {
          return local_8;
        }
        piVar9 = (int *)(iVar7 + 0x10);
        do {
          sVar3 = (short)piVar9[-3];
          if (sVar3 == 0) {
            if (*piVar9 != 0) {
              piVar13 = (int *)(*piVar9 + iVar6);
              uVar12 = (uint)*(ushort *)(piVar9 + -2) << 2;
              piVar15 = (int *)((int)piVar1 + (uint)*(ushort *)((int)piVar9 + -10) * 4 + iVar5);
              goto LAB_005cd1ae;
            }
          }
          else if (sVar3 == 1) {
            if (*piVar9 != 0) {
              uVar12 = (uint)*(ushort *)(piVar9 + -2) << 4;
              piVar15 = (int *)((int)piVar1 + (uint)*(ushort *)((int)piVar9 + -10) * 0x10 + iVar10);
              piVar13 = (int *)(*piVar9 + iVar6);
              goto LAB_005cd1ae;
            }
          }
          else if ((sVar3 == 2) && (*piVar9 != 0)) {
            uVar12 = (uint)*(ushort *)(piVar9 + -2) << 4;
            piVar15 = piVar1 + (uint)*(ushort *)((int)piVar9 + -10) * 4 + 2;
            piVar13 = (int *)(*piVar9 + iVar6);
LAB_005cd1ae:
            for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *piVar15 = *piVar13;
              piVar13 = piVar13 + 1;
              piVar15 = piVar15 + 1;
            }
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
              *(char *)piVar15 = (char)*piVar13;
              piVar13 = (int *)((int)piVar13 + 1);
              piVar15 = (int *)((int)piVar15 + 1);
            }
          }
          param_2 = param_2 + 1;
          piVar9 = piVar9 + 5;
          if (*(uint *)(iVar6 + 0xc) <= param_2) {
            return local_8;
          }
        } while( true );
      }
    }
    local_8 = -0x7ff8fff2;
  }
  return local_8;
}


// ==== 0x5cd1d4 FUN_005cd1d4

void __fastcall FUN_005cd1d4(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_005cb13e(3);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  while (*(int *)(param_1 + 0x14) != 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar1 + 0x14) = 0;
    FUN_005c8f26(1);
  }
  return;
}


// ==== 0x5cd207 FUN_005cd207

int __fastcall FUN_005cd207(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 2;
  *(undefined4 *)(param_1 + 0x58) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 8) = 3;
  puVar2 = (undefined4 *)(param_1 + 0x68);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return param_1;
}


// ==== 0x5cd25f FUN_005cd25f

void __fastcall FUN_005cd25f(int param_1)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(int *)(param_1 + 0x60) != 0) {
    FUN_005c8f42(1);
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(void **)(param_1 + 0x44) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(void **)(param_1 + 0x48) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  if (*(void **)(param_1 + 0x4c) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x50);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  FUN_005cd1d4();
  return;
}


// ==== 0x5cd2da FUN_005cd2da

void __fastcall FUN_005cd2da(undefined4 *param_1)

{
  param_1[6] = 0xffffffff;
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = 1;
  param_1[10] = 0;
  param_1[0xc] = 0;
  return;
}


// ==== 0x5cd2f5 FUN_005cd2f5

void __fastcall FUN_005cd2f5(undefined4 *param_1)

{
  param_1[6] = 0xffffffff;
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  return;
}


// ==== 0x5cd327 FUN_005cd327

int __thiscall FUN_005cd327(int param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *_Memory;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  uint local_10;
  
  puVar2 = param_3;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    local_10 = *(uint *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    param_3 = *(uint **)(iVar4 + *param_3 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if (((param_2 != (int *)0x0) && (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), uVar3 < *puVar2)
      ) || (*(uint *)(param_1 + 0x20) <= local_10)) {
    return -0x7fffbffb;
  }
  _Memory = _malloc((size_t)param_3);
  if (_Memory == (undefined4 *)0x0) {
    param_2 = (int *)0x8007000e;
    goto LAB_005cd5a6;
  }
  if (param_3 != (uint *)0x0) {
    if ((param_2 != (int *)0x0) &&
       (uVar3 = (**(code **)(*param_2 + 0x10))(param_2),
       (uint)(((uint)param_3 & 3) != 0) + ((uint)param_3 >> 2) + *puVar2 <= uVar3)) {
      iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
      puVar7 = (undefined4 *)(iVar4 + *puVar2 * 4);
      puVar5 = _Memory;
      for (uVar3 = (uint)param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = (uint)param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
    *puVar2 = *puVar2 + (uint)(((uint)param_3 & 3) != 0) + ((uint)param_3 >> 2);
  }
  if ((param_2 == (int *)0x0) || (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *puVar2 <= uVar3)
     ) {
    piVar8 = (int *)(local_10 * 0x1c + *(int *)(param_1 + 0x24));
    piVar1 = piVar8 + 1;
    param_2 = (int *)0x0;
    if ((*piVar1 == 0) && (piVar9 = piVar8 + 4, *piVar9 == 0)) {
      if (param_3 == (uint *)0x0) goto LAB_005cd5a6;
      iVar4 = *piVar8;
      if (iVar4 == 4) {
        if (*(char *)((int)param_3 + -1 + (int)_Memory) == '\0') {
          param_2 = (int *)thunk_FUN_005d65b0(param_3,piVar1);
          if (-1 < (int)param_2) {
            puVar5 = (undefined4 *)(**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1);
            puVar7 = _Memory;
            for (uVar3 = (uint)param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar5 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar5 = puVar5 + 1;
            }
            for (uVar3 = (uint)param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined1 *)puVar5 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar5 = (undefined4 *)((int)puVar5 + 1);
            }
          }
          goto LAB_005cd5a6;
        }
      }
      else if ((0xe < iVar4) && (iVar4 < 0x11)) {
        *(undefined4 *)(piVar8[6] + 0x54) = 0xffffffff;
        *(int *)(piVar8[6] + 0x5c) = piVar8[2];
        param_2 = (int *)thunk_FUN_005d65b0(param_3,piVar9);
        if ((int)param_2 < 0) goto LAB_005cd5a6;
        piVar9 = (int *)*piVar9;
        puVar5 = (undefined4 *)(**(code **)(*piVar9 + 0xc))(piVar9);
        puVar7 = _Memory;
        for (uVar3 = (uint)param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar5 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar5 = puVar5 + 1;
        }
        for (uVar3 = (uint)param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar5 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
        uVar6 = (**(code **)(*(int *)piVar8[4] + 0xc))((int *)piVar8[4],piVar8 + 5);
        param_2 = (int *)FUN_005c8e04(uVar6,piVar9);
        if ((int)param_2 < 0) goto LAB_005cd5a6;
        FUN_005e8fb1(1);
        if (*piVar8 == 0x10) {
          iVar4 = **(int **)(param_1 + 8);
          uVar6 = (**(code **)(*(int *)piVar8[4] + 0xc))((int *)piVar8[4],piVar8 + 1);
          iVar4 = (**(code **)(iVar4 + 0x16c))(*(undefined4 *)(param_1 + 8),uVar6);
          if (iVar4 < 0) goto LAB_005cd510;
LAB_005cd535:
          FUN_005e8fb1(0);
          piVar8[3] = 1;
        }
        else {
LAB_005cd510:
          if (*piVar8 == 0xf) {
            iVar4 = **(int **)(param_1 + 8);
            uVar6 = (**(code **)(*(int *)piVar8[4] + 0xc))((int *)piVar8[4],piVar8 + 1);
            iVar4 = (**(code **)(iVar4 + 0x1a8))(*(undefined4 *)(param_1 + 8),uVar6);
            if (-1 < iVar4) goto LAB_005cd535;
          }
          FUN_005e8fb1(0);
          piVar8[1] = 0;
          piVar8[3] = 0;
        }
        param_2 = (int *)FUN_005ccec4(piVar8[6],piVar8[5],0);
        goto LAB_005cd5a6;
      }
    }
  }
  param_2 = (int *)0x80004005;
LAB_005cd5a6:
  if (_Memory != (undefined4 *)0x0) {
    _free(_Memory);
  }
  return (int)param_2;
}


// ==== 0x5cd5bf FUN_005cd5bf

int __thiscall FUN_005cd5bf(uint param_1,int *param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint local_8;
  
  if ((*(int *)(&DAT_006dc264 + *param_2 * 0x1c) != 0x10) &&
     (*(int *)(&DAT_006dc264 + *param_2 * 0x1c) != 0xf)) {
    return 0;
  }
  local_8 = param_1;
  if ((param_3 != (int *)0x0) &&
     (uVar2 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar2)) {
    iVar3 = (**(code **)(*param_3 + 0xc))(param_3);
    local_8 = *(uint *)(iVar3 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 == (int *)0x0) ||
     (uVar2 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 <= uVar2)) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + param_2[3] * 4);
    iVar1 = *(int *)(iVar3 + 0x38);
    iVar3 = *(int *)(iVar3 + 0x28) + param_2[5];
    if (iVar1 == 0) {
      iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x2c));
    }
    else {
      iVar3 = *(int *)(*(int *)(iVar1 + 8) +
                      *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
    }
    piVar5 = (int *)(iVar3 * 0x1c + *(int *)(param_1 + 0x24));
    *piVar5 = *(int *)(&DAT_006dc264 + *param_2 * 0x1c);
    *(int *)(piVar5[6] + 0x54) = param_2[0x15];
    *(int *)(piVar5[6] + 0x58) = param_2[0x16];
    *(undefined4 *)(piVar5[6] + 0x5c) = 0;
    piVar6 = param_2 + 2;
    piVar8 = (int *)(piVar5[6] + 8);
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar8 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar8 = piVar8 + 1;
    }
    if (local_8 == 0) {
      return 0;
    }
    iVar3 = thunk_FUN_005d65b0(local_8,piVar5 + 4);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar6 = (int *)piVar5[4];
    puVar4 = (undefined4 *)(**(code **)(*piVar6 + 0xc))(piVar6);
    if ((param_3 != (int *)0x0) &&
       (uVar2 = (**(code **)(*param_3 + 0x10))(param_3),
       (uint)((local_8 & 3) != 0) + (local_8 >> 2) + *param_4 <= uVar2)) {
      iVar3 = (**(code **)(*param_3 + 0xc))(param_3);
      puVar7 = (undefined4 *)(iVar3 + *param_4 * 4);
      puVar9 = puVar4;
      for (uVar2 = local_8 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar2 = local_8 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
    }
    *param_4 = *param_4 + (uint)((local_8 & 3) != 0) + (local_8 >> 2);
    if ((param_3 == (int *)0x0) ||
       (uVar2 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 <= uVar2)) {
      iVar3 = FUN_005c8e04(puVar4,piVar5 + 5);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_005e8fb1(1);
      if (((*piVar5 == 0x10) &&
          (iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x16c))
                             (*(int **)(param_1 + 8),puVar4,piVar5 + 1), -1 < iVar3)) ||
         ((*piVar5 == 0xf &&
          (iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x1a8))
                             (*(int **)(param_1 + 8),puVar4,piVar5 + 1), -1 < iVar3)))) {
        FUN_005e8fb1(0);
        piVar5[3] = 1;
      }
      else {
        FUN_005e8fb1(0);
        piVar5[1] = 0;
        piVar5[3] = 0;
      }
      iVar3 = FUN_005ccec4(piVar5[6],piVar5[5],0);
      return iVar3;
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5cd7bf FUN_005cd7bf

int __thiscall FUN_005cd7bf(int param_1,int param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint local_c;
  int local_8;
  
  puVar7 = param_4;
  if ((param_3 != (int *)0x0) &&
     (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), puVar7 = param_4, *param_4 + 1 <= uVar1)) {
    iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
    local_c = *(uint *)(iVar2 + *puVar7 * 4);
  }
  *puVar7 = *puVar7 + 1;
  if ((param_3 == (int *)0x0) || (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), *puVar7 <= uVar1)
     ) {
    local_8 = 0;
    if ((local_c != 0) && (local_8 = thunk_FUN_005d65b0(local_c,param_2 + 0x50), -1 < local_8)) {
      puVar3 = (undefined4 *)
               (**(code **)(**(int **)(param_2 + 0x50) + 0xc))(*(int **)(param_2 + 0x50));
      if ((param_3 != (int *)0x0) &&
         (uVar1 = (**(code **)(*param_3 + 0x10))(param_3),
         (uint)((local_c & 3) != 0) + (local_c >> 2) + *puVar7 <= uVar1)) {
        iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
        puVar5 = (undefined4 *)(iVar2 + *puVar7 * 4);
        puVar6 = puVar3;
        for (uVar1 = local_c >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar1 = local_c & 3; puVar7 = param_4, uVar1 != 0; uVar1 = uVar1 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
      }
      *puVar7 = *puVar7 + (uint)((local_c & 3) != 0) + (local_c >> 2);
      if ((param_3 == (int *)0x0) ||
         (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), *puVar7 <= uVar1)) {
        local_8 = FUN_005c8e04(puVar3,(undefined4 *)(param_2 + 0x34));
        if ((-1 < local_8) &&
           (local_8 = FUN_005ccec4(param_2,*(undefined4 *)(param_2 + 0x34),1), -1 < local_8)) {
          param_4 = (uint *)(*(int *)(param_2 + 0x10) + *(int *)(param_1 + 0x2c));
          iVar2 = FUN_005c8286(&param_4,4);
          *(int *)(param_2 + 0x38) = iVar2;
          iVar2 = iVar2 * 4;
          *(int *)(param_2 + 0x40) = iVar2;
          if (iVar2 != 0) {
            *(int *)(param_2 + 0x40) = iVar2 + -1;
          }
          uVar4 = *(uint *)(param_2 + 0x40) >> 1 | *(uint *)(param_2 + 0x40);
          uVar4 = uVar4 >> 2 | uVar4;
          uVar4 = uVar4 >> 4 | uVar4;
          uVar4 = uVar4 >> 8 | uVar4;
          uVar4 = uVar4 >> 0x10 | uVar4;
          uVar1 = uVar4 * 8 + 8;
          *(uint *)(param_2 + 0x40) = uVar4;
          puVar3 = _malloc(uVar1);
          *(undefined4 **)(param_2 + 0x48) = puVar3;
          if (puVar3 == (undefined4 *)0x0) {
            local_8 = -0x7ff8fff2;
          }
          else {
            for (uVar1 = uVar1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined1 *)puVar3 = 0;
              puVar3 = (undefined4 *)((int)puVar3 + 1);
            }
          }
        }
      }
      else {
        local_8 = -0x7fffbffb;
      }
    }
  }
  else {
    local_8 = -0x7fffbffb;
  }
  return local_8;
}


// ==== 0x5cd973 FUN_005cd973

uint __thiscall FUN_005cd973(int param_1,int *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  uint local_10;
  uint local_c;
  
  piVar3 = param_3;
  piVar2 = param_2;
  puVar4 = (uint *)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c));
  piVar10 = (int *)*param_2;
  puVar6 = (uint *)(piVar10 + 5);
  if (puVar4 < puVar6) {
    return 0x80004005;
  }
  iVar8 = *piVar10;
  local_c = piVar10[4];
  uVar5 = FUN_005c90f8(piVar10[2]);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  uVar5 = FUN_005c90b3(piVar10[3]);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  if (local_c == 0) {
    local_c = 1;
  }
  iVar7 = piVar10[1];
  if (iVar7 < 0) {
    return 0x80004005;
  }
  if (iVar7 < 4) {
    if (iVar8 < 1) {
      return 0x80004005;
    }
    if ((2 < iVar8) && (iVar8 != 3)) {
      return 0x80004005;
    }
    uVar5 = -(uint)(puVar4 < piVar10 + 7) & 0x80004005;
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    iVar8 = piVar10[6] * *puVar6 * local_c;
    uVar5 = -(uint)(puVar4 < piVar10 + iVar8) & 0x80004005;
    if (-1 < (int)uVar5) {
      *param_3 = *param_3 + iVar8 * 4;
      *param_2 = *param_2 + 0x1c;
      return uVar5;
    }
    return uVar5;
  }
  if (iVar7 != 4) {
    if (iVar7 != 5) {
      return 0x80004005;
    }
    if (iVar8 != 0) {
      return 0x80004005;
    }
    puVar9 = (uint *)(piVar10 + 6);
    uVar5 = -(uint)(puVar4 < puVar9) & 0x80004005;
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    uVar1 = *puVar6;
    *param_2 = (int)puVar9;
    local_10 = 0;
    if (local_c != 0) {
      do {
        *piVar2 = (int)puVar9;
        param_2 = (int *)0x0;
        if (uVar1 != 0) {
          do {
            uVar5 = FUN_005cd973(piVar2,param_3,param_4);
            if ((int)uVar5 < 0) {
              return uVar5;
            }
            param_2 = (int *)((int)param_2 + 1);
          } while (param_2 < uVar1);
        }
        local_10 = local_10 + 1;
      } while (local_10 < local_c);
      return uVar5;
    }
    return uVar5;
  }
  if (iVar8 < 4) {
    return 0x80004005;
  }
  if (9 < iVar8) {
    if (iVar8 < 0xf) {
      uVar5 = -(uint)(puVar4 < (int *)*param_3 + 1) & 0x80004005;
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      iVar8 = *(int *)(*(int *)(param_1 + 0x8c) + param_4 * 4);
      iVar7 = *(int *)*param_3;
      *(int *)(iVar8 + 0x3c) = iVar7;
      if (*(int *)(iVar8 + 0x40) != 0) {
        return 0x80004005;
      }
      piVar10 = _malloc(iVar7 * 0xac + 4);
      if (piVar10 == (int *)0x0) {
        piVar10 = (int *)0x0;
      }
      else {
        *piVar10 = iVar7;
        piVar10 = piVar10 + 1;
        CallNTimes(piVar10,0xac,iVar7,FUN_005cd207);
      }
      *(int **)(iVar8 + 0x40) = piVar10;
      if (piVar10 == (int *)0x0) {
        return 0x8007000e;
      }
      *param_3 = *param_3 + 4;
      uVar5 = -(uint)((uint)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c)) <
                     (uint)(*(int *)(iVar8 + 0x3c) * 0x10 + *param_3)) & 0x80004005;
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      local_10 = 0;
      if (*(int *)(iVar8 + 0x3c) != 0) {
        param_3 = (int *)0x0;
        do {
          puVar6 = (uint *)(*(int *)(iVar8 + 0x40) + (int)param_3);
          puVar6[0x15] = 0xffffffff;
          puVar6[10] = puVar6[10] | 1;
          puVar6[0xb] = 0;
          puVar6[0x17] = param_4;
          *puVar6 = *(uint *)*piVar3;
          *piVar3 = *piVar3 + 4;
          puVar6[1] = *(uint *)*piVar3;
          *piVar3 = *piVar3 + 4;
          puVar6[4] = *(uint *)*piVar3;
          *piVar3 = *piVar3 + 4;
          puVar6[5] = *(uint *)*piVar3;
          *piVar3 = *piVar3 + 4;
          puVar6[3] = 0;
          if (0xb2 < *puVar6) {
            return 0x80004005;
          }
          iVar7 = *puVar6 * 0x1c;
          if (*(int *)(&DAT_006dc274 + iVar7) == 0x5000000) {
            *(undefined4 *)
             (*(int *)(puVar6[5] + *(int *)(param_1 + 0x2c)) * 0x1c + *(int *)(param_1 + 0x24)) =
                 *(undefined4 *)(&DAT_006dc264 + iVar7);
          }
          local_10 = local_10 + 1;
          param_3 = (int *)((int)param_3 + 0xac);
        } while (local_10 < *(uint *)(iVar8 + 0x3c));
      }
      goto LAB_005cdc42;
    }
    if (0x10 < iVar8) {
      return 0x80004005;
    }
  }
  uVar5 = -(uint)(puVar4 < (uint *)(*param_3 + local_c * 4)) & 0x80004005;
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  param_3 = (int *)0x0;
  if (local_c != 0) {
    do {
      uVar1 = *(uint *)*piVar3;
      if (*(uint *)(param_1 + 0x20) <= uVar1) {
        return 0x80004005;
      }
      if (uVar1 != 0) {
        iVar7 = uVar1 * 0x1c;
        piVar10 = (int *)(*(int *)(param_1 + 0x24) + iVar7);
        if (*piVar10 != 0x7fffffff) {
          return 0x80004005;
        }
        *piVar10 = iVar8;
        *(uint *)(*(int *)(param_1 + 0x24) + 8 + iVar7) = param_4;
        if ((iVar8 == 0x10) || (iVar8 == 0xf)) {
          *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x18 + iVar7) + 0x5c) = param_4;
        }
      }
      param_3 = (int *)((int)param_3 + 1);
      *piVar3 = *piVar3 + 4;
    } while (param_3 < local_c);
  }
LAB_005cdc42:
  *param_2 = *param_2 + 0x14;
  return uVar5;
}


// ==== 0x5cdca7 FUN_005cdca7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005cdca7(int param_1,int *param_2)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  undefined4 uVar11;
  float fVar12;
  uint uVar13;
  int *piVar14;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  undefined2 *puVar18;
  float *pfVar19;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar20;
  float10 fVar21;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined2 uVar26;
  float local_3c [4];
  int *local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  float *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  piVar7 = param_2;
  local_8 = 0;
  local_10 = param_1;
  if ((*param_2 != -1) &&
     ((*(int *)(&DAT_006dc274 + *param_2 * 0x1c) == 0x6000000 ||
      (*(int *)(&DAT_006dc274 + *param_2 * 0x1c) == 0x6000001)))) {
    iVar8 = *(int *)(*(int *)(param_1 + 0x8c) + param_2[3] * 4);
    iVar3 = *(int *)(iVar8 + 0x38);
    iVar8 = *(int *)(iVar8 + 0x28) + param_2[5];
    if (iVar3 == 0) {
      iVar8 = *(int *)(iVar8 + *(int *)(param_1 + 0x2c));
    }
    else {
      iVar8 = *(int *)(*(int *)(iVar3 + 8) +
                      *(int *)(iVar8 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
    }
    local_1c = (float *)(iVar8 * 0x1c + *(int *)(param_1 + 0x24));
    if ((*(int *)((int)local_1c + 0xc) != 0) && (*(int *)((int)local_1c + 0x14) != 0)) {
      uVar10 = *(uint *)(*(int *)((int)local_1c + 0x18) + 0x28);
      if ((uVar10 & 1) != 0) {
        local_c = 0;
        *(uint *)(*(int *)((int)local_1c + 0x18) + 0x28) = uVar10 & 0xfffffffe;
        iVar8 = *(int *)((int)local_1c + 0x14);
        local_2c = *(int **)(*(int *)((int)local_1c + 0x18) + 0x44);
        local_24 = local_2c + 2;
        local_28 = *local_2c + (int)local_2c;
        local_2c = (int *)(local_2c[1] + (int)local_2c);
        if (*(int *)(iVar8 + 0xc) != 0) {
          param_2 = (int *)(*(int *)(iVar8 + 0x10) + iVar8 + 8);
          do {
            piVar14 = *(int **)(*(int *)(*(int *)((int)local_1c + 0x18) + 0x30) + local_c * 4);
            sVar2 = *(short *)((int)param_2 + -4);
            if (sVar2 == 0) {
              if ((piVar14 != (int *)0x0) && (*piVar14 != 0)) {
                local_8 = FUN_005cce58(piVar14[1],local_2c + *(ushort *)((int)param_2 + -2),
                                       *(undefined2 *)param_2);
              }
            }
            else if (sVar2 == 1) {
              if ((piVar14 != (int *)0x0) && (*piVar14 != 0)) {
                local_8 = FUN_005caf72(piVar14[1],
                                       (uint)*(ushort *)((int)param_2 + -2) * 0x10 + local_28,
                                       *(undefined2 *)param_2);
              }
            }
            else if (sVar2 == 2) {
              if ((piVar14 != (int *)0x0) && (*piVar14 != 0)) {
                local_8 = FUN_005cafde(piVar14[1],
                                       local_24 + (uint)*(ushort *)((int)param_2 + -2) * 4,
                                       *(undefined2 *)param_2);
              }
            }
            else {
              if (sVar2 != 3) {
                return -0x7fffbffb;
              }
              if (piVar14 != (int *)0x0) {
                local_20 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(piVar14[1] + 4) * 4);
                local_18 = 0;
                if (*(int *)(local_20 + 0x3c) != 0) {
                  local_14 = 0;
                  do {
                    local_8 = FUN_005cdca7(*(int *)(local_20 + 0x40) + local_14);
                    if (local_8 < 0) {
                      return local_8;
                    }
                    local_18 = local_18 + 1;
                    local_14 = local_14 + 0xac;
                  } while (local_18 < *(uint *)(local_20 + 0x3c));
                }
              }
            }
            if (local_8 < 0) {
              return local_8;
            }
            if (piVar14 != (int *)0x0) {
              *piVar14 = 0;
            }
            local_c = local_c + 1;
            param_2 = (int *)((int)param_2 + 0x14);
          } while (local_c < *(uint *)(*(int *)((int)local_1c + 0x14) + 0xc));
        }
        puVar1 = (uint *)(*(int *)((int)local_1c + 0x18) + 0x28);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
    }
  }
  if ((*(byte *)(piVar7 + 10) & 1) == 0) {
    return local_8;
  }
  if (piVar7[0x14] != 0) {
    iVar8 = piVar7[0xd];
    local_20 = 0;
    local_1c = (float *)piVar7[0x12];
    param_2 = (int *)0x0;
    local_18 = piVar7[0x10];
    if (iVar8 != 0) {
      local_24 = (int *)piVar7[0x11];
      param_2 = (int *)0x0;
      local_2c = local_24 + 2;
      local_28 = *local_24 + (int)local_24;
      local_24 = (int *)(local_24[1] + (int)local_24);
      if (*(int *)(iVar8 + 0xc) != 0) {
        puVar18 = (undefined2 *)(*(int *)(iVar8 + 0x10) + iVar8 + 8);
        do {
          piVar14 = *(int **)(piVar7[0xc] + (int)param_2 * 4);
          sVar2 = puVar18[-2];
          if (sVar2 == 0) {
            if ((piVar14 != (int *)0x0) && (*piVar14 != 0)) {
              uVar26 = *puVar18;
              piVar9 = local_24 + (uint)(ushort)puVar18[-1] * 2;
              goto LAB_005cdf7a;
            }
          }
          else if (sVar2 == 1) {
            if ((piVar14 != (int *)0x0) && (*piVar14 != 0)) {
              uVar26 = *puVar18;
              piVar9 = (int *)((uint)(ushort)puVar18[-1] * 0x20 + local_28);
              goto LAB_005cdf7a;
            }
          }
          else if (((sVar2 == 2) && (piVar14 != (int *)0x0)) && (*piVar14 != 0)) {
            uVar26 = *puVar18;
            piVar9 = local_2c + (uint)(ushort)puVar18[-1] * 8;
LAB_005cdf7a:
            local_8 = FUN_005cb04a(piVar14[1],piVar9,uVar26);
          }
          if (local_8 < 0) {
            return local_8;
          }
          if (piVar14 != (int *)0x0) {
            *piVar14 = 0;
          }
          param_2 = (int *)((int)param_2 + 1);
          puVar18 = puVar18 + 10;
        } while (param_2 < *(uint *)(piVar7[0xd] + 0xc));
      }
      local_20 = piVar7[0x11] + 8;
      param_2 = (int *)piVar7[0xf];
      param_1 = local_10;
    }
    pfVar17 = local_1c;
    if (*(int *)(param_1 + 0xb4) == 0) {
      uVar10 = __controlfp(0,0);
      *(uint *)(param_1 + 0xb8) = uVar10;
      __controlfp(0x10000,0x30000);
      *(undefined4 *)(param_1 + 0xb4) = 1;
    }
    uVar25 = 0;
    uVar24 = 0;
    uVar23 = 0;
    uVar22 = 0;
    uVar10 = local_20;
    pfVar15 = pfVar17;
    uVar13 = local_18;
    uVar11 = (**(code **)(*(int *)piVar7[0x14] + 0xc))
                       ((int *)piVar7[0x14],0,local_20,0,pfVar17,0,param_2,0,local_18);
    local_8 = FUN_005e98b0(uVar11,uVar22,uVar10,uVar23,pfVar15,uVar24,param_2,uVar25,uVar13);
    if (local_8 < 0) {
      return local_8;
    }
    if (*piVar7 == -1) {
      piVar7[10] = piVar7[10] & 0xfffffffe;
      iVar8 = piVar7[0x19];
      uVar10 = __ftol();
      iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar8 + 0xc) * 4);
      if (*(int *)(iVar3 + 0x38) == 0) {
        iVar16 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar16 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      if (*(uint *)(*(int *)(iVar3 + 0x24) + *(int *)(iVar8 + 0x10) + 0x10 + iVar16) <= uVar10) {
        return -0x7fffbffb;
      }
      *(uint *)(iVar8 + 0x14) = uVar10 << 2;
      return local_8;
    }
    local_8 = FUN_005cb0b6(piVar7 + 2,pfVar17,piVar7[0xe]);
    if (local_8 < 0) {
      return local_8;
    }
  }
  iVar8 = *piVar7 * 0x1c;
  uVar10 = *(uint *)(&DAT_006dc274 + iVar8);
  if (uVar10 < 0x6000103) {
    if (uVar10 == 0x6000102) goto LAB_005ce153;
    if (uVar10 < 0x6000005) {
      if (uVar10 == 0x6000004) {
LAB_005ce119:
        local_8 = FUN_005cce58(piVar7 + 2,piVar7[0x13],piVar7[0x2a]);
        goto LAB_005ce167;
      }
      if (uVar10 == 0x5000000) goto LAB_005ce16e;
      if (0x5ffffff < uVar10) {
        if (uVar10 < 0x6000002) {
          if (piVar7[0x18] == 0) goto LAB_005ce16e;
          local_8 = FUN_005cdca7(piVar7[0x18]);
          goto LAB_005ce167;
        }
        if (uVar10 == 0x6000002) goto LAB_005ce153;
        if (uVar10 == 0x6000003) goto LAB_005ce0e5;
      }
    }
    else {
      if (uVar10 == 0x6000005) goto LAB_005ce153;
      if (uVar10 == 0x6000006) {
LAB_005ce0e5:
        local_8 = FUN_005caf72(piVar7 + 2,piVar7[0x13],piVar7[0x2a]);
        goto LAB_005ce167;
      }
      if (uVar10 == 0x6000007) goto LAB_005ce119;
    }
  }
  else if (uVar10 < 0x6000306) {
    if (((uVar10 == 0x6000305) || (uVar10 == 0x6000105)) ||
       ((uVar10 == 0x6000202 || ((uVar10 == 0x6000205 || (uVar10 == 0x6000302)))))) {
LAB_005ce153:
      local_8 = FUN_005cafde(piVar7 + 2,piVar7[0x13],piVar7[0x2a]);
LAB_005ce167:
      if (local_8 < 0) {
        return local_8;
      }
      goto LAB_005ce16e;
    }
  }
  else {
    if ((uVar10 == 0x6000402) || (uVar10 == 0x6000405)) goto LAB_005ce153;
    if (uVar10 == 0x9000000) {
      iVar8 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
      local_1c = (float *)0x0;
      if (*(int *)(iVar8 + 0x3c) != 0) {
        param_2 = (int *)0x0;
        do {
          local_8 = FUN_005cdca7(*(int *)(iVar8 + 0x40) + (int)param_2);
          if (local_8 < 0) {
            return local_8;
          }
          local_1c = (float *)((int)local_1c + 1);
          param_2 = (int *)((int)param_2 + 0xac);
        } while (local_1c < *(uint *)(iVar8 + 0x3c));
      }
      goto LAB_005ce16e;
    }
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + piVar7[3] * 4);
  if (*(int *)(iVar3 + 0x38) == 0) {
    iVar16 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar16 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  piVar14 = (int *)(*(int *)(iVar3 + 0x24) + piVar7[4] + iVar16);
  if (*(int *)(iVar3 + 0x38) == 0) {
    iVar16 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar16 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  pfVar17 = (float *)(*(int *)(iVar3 + 0x28) + piVar7[5] + iVar16);
  iVar3 = *piVar14;
  if (*(int *)(&DAT_006dc264 + iVar8) == 3) {
    local_1c = pfVar17;
    if (iVar3 == 1) {
      uVar10 = piVar14[5];
      uVar13 = piVar14[6];
      if (uVar13 == 1) {
        uVar13 = 0x10;
        if (uVar10 < 0x11) {
          uVar13 = uVar10;
        }
        uVar10 = 0;
        if (uVar13 != 0) {
          pfVar15 = (float *)(piVar7 + 0x1a);
          do {
            pfVar19 = pfVar17 + uVar10;
            uVar10 = uVar10 + 1;
            *pfVar15 = (float)(int)*pfVar19;
            pfVar15 = pfVar15 + 1;
          } while (uVar10 < uVar13);
        }
      }
      else {
        local_20 = 4;
        if (uVar10 < 5) {
          local_20 = uVar10;
        }
        param_2 = (int *)0x4;
        if (uVar13 < 5) {
          param_2 = (int *)uVar13;
        }
        if (local_20 != 0) {
          pfVar15 = (float *)(piVar7 + 0x1a);
          uVar10 = (uint)param_2;
          pfVar19 = pfVar15;
          do {
            for (; uVar10 != 0; uVar10 = uVar10 - 1) {
              fVar12 = *pfVar17;
              pfVar17 = pfVar17 + 1;
              *pfVar15 = (float)(int)fVar12;
              pfVar15 = pfVar15 + 1;
            }
            pfVar17 = local_1c + uVar13;
            pfVar15 = pfVar19 + 4;
            local_20 = local_20 - 1;
            uVar10 = (uint)param_2;
            local_1c = pfVar17;
            pfVar19 = pfVar15;
          } while (local_20 != 0);
        }
      }
      goto LAB_005ce16e;
    }
    if (iVar3 != 2) {
      if (iVar3 != 3) {
        return -0x7fffbffb;
      }
      uVar10 = piVar14[5];
      uVar13 = piVar14[6];
      if (uVar13 == 1) {
        uVar13 = 0x10;
        if (uVar10 < 0x11) {
          uVar13 = uVar10;
        }
        uVar10 = 0;
        if (uVar13 != 0) {
          pfVar15 = (float *)(piVar7 + 0x1a);
          do {
            pfVar19 = pfVar17 + uVar10;
            uVar10 = uVar10 + 1;
            *pfVar15 = *pfVar19;
            pfVar15 = pfVar15 + 1;
          } while (uVar10 < uVar13);
        }
      }
      else {
        local_18 = 4;
        if (uVar10 < 5) {
          local_18 = uVar10;
        }
        param_2 = (int *)0x4;
        if (uVar13 < 5) {
          param_2 = (int *)uVar13;
        }
        if (local_18 != 0) {
          pfVar17 = (float *)(piVar7 + 0x1a);
          do {
            if (param_2 != (int *)0x0) {
              local_20 = (uint)param_2;
              pfVar15 = local_1c;
              pfVar19 = pfVar17;
              do {
                *pfVar19 = *pfVar15;
                pfVar15 = pfVar15 + 1;
                pfVar19 = pfVar19 + 1;
                local_20 = local_20 - 1;
              } while (local_20 != 0);
            }
            local_1c = local_1c + uVar13;
            pfVar17 = pfVar17 + 4;
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
      }
      goto LAB_005ce16e;
    }
    uVar10 = piVar14[5];
    uVar13 = piVar14[6];
    if (uVar13 != 1) {
      local_20 = 4;
      if (uVar10 < 5) {
        local_20 = uVar10;
      }
      param_2 = (int *)0x4;
      if (uVar13 < 5) {
        param_2 = (int *)uVar13;
      }
      if (local_20 != 0) {
        pfVar15 = (float *)(piVar7 + 0x1a);
        uVar10 = (uint)param_2;
        pfVar19 = pfVar15;
        do {
          for (; uVar10 != 0; uVar10 = uVar10 - 1) {
            fVar12 = *pfVar17;
            pfVar17 = pfVar17 + 1;
            *pfVar15 = (float)(int)fVar12;
            pfVar15 = pfVar15 + 1;
          }
          pfVar17 = local_1c + uVar13;
          pfVar15 = pfVar19 + 4;
          local_20 = local_20 - 1;
          uVar10 = (uint)param_2;
          local_1c = pfVar17;
          pfVar19 = pfVar15;
        } while (local_20 != 0);
      }
      goto LAB_005ce16e;
    }
    if (uVar10 == 1) {
      if ((*(int *)(&DAT_006dc268 + iVar8) == 1) && (*(int *)(&DAT_006dc26c + iVar8) == 4)) {
        fVar12 = *pfVar17;
        fVar4 = (float)((uint)fVar12 >> 8 & 0xff) * _K_BLUR_MIN_T;
        fVar5 = (float)((uint)fVar12 & 0xff) * _K_BLUR_MIN_T;
        fVar6 = (float)((uint)fVar12 >> 0x18) * _K_BLUR_MIN_T;
        piVar7[0x1a] = (int)((float)((uint)fVar12 >> 0x10 & 0xff) * _K_BLUR_MIN_T);
        piVar7[0x1b] = (int)fVar4;
        piVar7[0x1c] = (int)fVar5;
        piVar7[0x1d] = (int)fVar6;
        goto LAB_005ce16e;
      }
LAB_005ce501:
      uVar13 = uVar10;
    }
    else {
      uVar13 = 0x10;
      if (uVar10 < 0x11) goto LAB_005ce501;
    }
    uVar10 = 0;
    if (uVar13 != 0) {
      pfVar15 = (float *)(piVar7 + 0x1a);
      do {
        pfVar19 = pfVar17 + uVar10;
        uVar10 = uVar10 + 1;
        *pfVar15 = (float)(int)*pfVar19;
        pfVar15 = pfVar15 + 1;
      } while (uVar10 < uVar13);
    }
    goto LAB_005ce16e;
  }
  if (*(int *)(&DAT_006dc264 + iVar8) != 0xf20000) {
    return -0x7fffbffb;
  }
  local_3c[0] = 0.0;
  local_3c[1] = 0.0;
  local_3c[2] = 0.0;
  local_3c[3] = 0.0;
  if (iVar3 == 1) {
    uVar10 = piVar14[5];
    if (uVar10 != 1) {
      if (4 < uVar10) {
        uVar10 = 4;
      }
      uVar13 = 0;
      if (uVar10 != 0) {
        do {
          pfVar15 = pfVar17 + uVar13;
          uVar13 = uVar13 + 1;
          *(float *)(&stack0xffffffc0 + uVar13 * 4) = (float)(int)*pfVar15;
        } while (uVar13 < uVar10);
      }
      goto LAB_005ce2f2;
    }
LAB_005ce37b:
    fVar12 = *pfVar17;
  }
  else {
    if (iVar3 == 2) {
      uVar10 = piVar14[5];
      if (uVar10 == 1) goto LAB_005ce37b;
      if (4 < uVar10) {
        uVar10 = 4;
      }
      uVar13 = 0;
      if (uVar10 != 0) {
        do {
          pfVar15 = pfVar17 + uVar13;
          uVar13 = uVar13 + 1;
          *(float *)(&stack0xffffffc0 + uVar13 * 4) = (float)(int)*pfVar15;
        } while (uVar13 < uVar10);
      }
    }
    else {
      if (iVar3 != 3) {
        return -0x7fffbffb;
      }
      uVar10 = piVar14[5];
      if (uVar10 == 1) {
        fVar12 = (float)__ftol();
        goto LAB_005ce3d0;
      }
      if (4 < uVar10) {
        uVar10 = 4;
      }
      if (uVar10 != 0) {
        pfVar15 = local_3c;
        for (; uVar10 != 0; uVar10 = uVar10 - 1) {
          *pfVar15 = *pfVar17;
          pfVar17 = pfVar17 + 1;
          pfVar15 = pfVar15 + 1;
        }
      }
    }
LAB_005ce2f2:
    fVar20 = (float10)_K_ONE;
    uVar10 = 0xff;
    fVar21 = (float10)0.0;
    if ((float10)local_3c[0] < fVar20) {
      if ((float10)local_3c[0] < fVar21 == ((float10)local_3c[0] == fVar21)) {
        param_2 = (int *)__ftol();
        fVar21 = extraout_ST0;
        fVar20 = extraout_ST1;
      }
      else {
        param_2 = (int *)0x0;
      }
    }
    else {
      param_2 = (int *)0xff;
    }
    if ((float10)local_3c[1] < fVar20) {
      if ((float10)local_3c[1] < fVar21 == ((float10)local_3c[1] == fVar21)) {
        local_1c = (float *)__ftol();
        fVar21 = extraout_ST0_01;
        fVar20 = extraout_ST1_00;
      }
      else {
        local_1c = (float *)0x0;
      }
    }
    else {
      local_1c = (float *)0xff;
    }
    if ((float10)local_3c[2] < fVar20) {
      if ((float10)local_3c[2] < fVar21 == ((float10)local_3c[2] == fVar21)) {
        uVar10 = __ftol();
        fVar20 = extraout_ST0_00;
      }
      else {
        uVar10 = 0;
      }
    }
    if ((float10)local_3c[3] < fVar20) {
      if (local_3c[3] < 0.0 == (local_3c[3] == 0.0)) {
        iVar8 = __ftol();
      }
      else {
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 0xff;
    }
    fVar12 = (float)(((iVar8 << 8 | (uint)param_2) << 8 | (uint)local_1c) << 8 | uVar10);
  }
LAB_005ce3d0:
  piVar7[0x1a] = (int)fVar12;
LAB_005ce16e:
  piVar7[10] = piVar7[10] & 0xfffffffe;
  return local_8;
}


// ==== 0x5ce64f FUN_005ce64f

int __thiscall FUN_005ce64f(int *param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_18;
  uint local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_10 = (int *)0x0;
  local_8 = (int *)0x0;
  iVar6 = param_3;
  if (param_4 != (int *)0x0) {
    iVar6 = *(int *)(param_4[2] + param_3 * 4);
  }
  iVar6 = iVar6 * 0x1c + param_1[9];
  local_c = param_1;
  if (param_2 == (int *)0x0) {
    piVar1 = *(int **)(iVar6 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(int *)(iVar6 + 4) = 0;
    }
    piVar1 = *(int **)(iVar6 + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar6 + 0x10) = 0;
    }
    *(undefined4 *)(iVar6 + 0x14) = 0;
    goto LAB_005ce7f6;
  }
  local_18 = 0;
  iVar5 = (**(code **)(*param_2 + 0x10))(param_2,0,&local_14);
  if (iVar5 < 0) goto LAB_005ce8c4;
  piVar1 = *(int **)(iVar6 + 0x10);
  if ((piVar1 == (int *)0x0) || (uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1), uVar3 < local_14)) {
    iVar5 = thunk_FUN_005d65b0(local_14,&local_8);
    if (iVar5 < 0) goto LAB_005ce8c4;
  }
  else {
    local_8 = *(int **)(iVar6 + 0x10);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
  }
  iVar5 = *param_2;
  uVar4 = (**(code **)(*local_8 + 0xc))(local_8,&local_14);
  iVar5 = (**(code **)(iVar5 + 0x10))(param_2,uVar4);
  if (iVar5 < 0) goto LAB_005ce8c4;
  puVar7 = &local_18;
  uVar4 = (**(code **)(*local_8 + 0xc))(local_8,puVar7);
  iVar5 = FUN_005c8e04(uVar4,puVar7);
  if ((iVar5 < 0) || (iVar5 = (**(code **)(*param_2 + 0xc))(param_2,&local_10), iVar5 < 0))
  goto LAB_005ce8c4;
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 4))(local_8);
  }
  piVar1 = *(int **)(iVar6 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(iVar6 + 0x10) = 0;
  }
  *(int **)(iVar6 + 0x10) = local_8;
  *(undefined4 *)(iVar6 + 0x14) = local_18;
  if (local_10 == (int *)local_c[2]) {
    (**(code **)(*param_2 + 4))(param_2);
    piVar1 = (int *)(iVar6 + 4);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    *piVar1 = (int)param_2;
LAB_005ce7f6:
    *(undefined4 *)(iVar6 + 0xc) = 1;
  }
  else {
    piVar1 = (int *)(iVar6 + 4);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    FUN_005e8fb1(1);
    iVar5 = *(int *)local_c[2];
    uVar4 = (**(code **)(*local_8 + 0xc))(local_8,piVar1);
    iVar5 = (**(code **)(iVar5 + 0x1a8))(local_c[2],uVar4);
    if (-1 < iVar5) {
      FUN_005e8fb1(0);
      goto LAB_005ce7f6;
    }
    FUN_005e8fb1(0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
  }
  param_2 = (int *)FUN_005ccec4(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x14),0);
  iVar5 = (int)param_2;
  if ((-1 < (int)param_2) && (param_4 != (int *)0x0)) {
    for (local_c = (int *)param_4[4]; iVar5 = (int)param_2, local_c != param_4;
        local_c = (int *)local_c[4]) {
      if (*local_c != 0) {
        iVar5 = *(int *)(local_c[2] + param_3 * 4) * 0x1c + *(int *)(*local_c + 0x24);
        piVar1 = *(int **)(iVar6 + 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        piVar1 = *(int **)(iVar6 + 0x10);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        piVar1 = *(int **)(iVar5 + 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(iVar5 + 4) = 0;
        }
        piVar1 = *(int **)(iVar5 + 0x10);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(iVar5 + 0x10) = 0;
        }
        *(int *)(iVar5 + 4) = *(int *)(iVar6 + 4);
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0xc);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0x10);
        uVar4 = *(undefined4 *)(iVar6 + 0x14);
        *(undefined4 *)(iVar5 + 0x14) = uVar4;
        param_2 = (int *)FUN_005ccec4(*(undefined4 *)(iVar5 + 0x18),uVar4,0);
        iVar5 = (int)param_2;
        if ((int)param_2 < 0) break;
      }
    }
  }
LAB_005ce8c4:
  param_2 = (int *)iVar5;
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
    local_10 = (int *)0x0;
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return (int)param_2;
}


// ==== 0x5ce8ec FUN_005ce8ec

int __thiscall FUN_005ce8ec(int *param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_18;
  uint local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_10 = (int *)0x0;
  local_8 = (int *)0x0;
  iVar6 = param_3;
  if (param_4 != (int *)0x0) {
    iVar6 = *(int *)(param_4[2] + param_3 * 4);
  }
  iVar6 = iVar6 * 0x1c + param_1[9];
  local_c = param_1;
  if (param_2 == (int *)0x0) {
    piVar1 = *(int **)(iVar6 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(int *)(iVar6 + 4) = 0;
    }
    piVar1 = *(int **)(iVar6 + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar6 + 0x10) = 0;
    }
    *(undefined4 *)(iVar6 + 0x14) = 0;
    goto LAB_005cea93;
  }
  local_18 = 0;
  iVar5 = (**(code **)(*param_2 + 0x10))(param_2,0,&local_14);
  if (iVar5 < 0) goto LAB_005ceb61;
  piVar1 = *(int **)(iVar6 + 0x10);
  if ((piVar1 == (int *)0x0) || (uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1), uVar3 < local_14)) {
    iVar5 = thunk_FUN_005d65b0(local_14,&local_8);
    if (iVar5 < 0) goto LAB_005ceb61;
  }
  else {
    local_8 = *(int **)(iVar6 + 0x10);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
  }
  iVar5 = *param_2;
  uVar4 = (**(code **)(*local_8 + 0xc))(local_8,&local_14);
  iVar5 = (**(code **)(iVar5 + 0x10))(param_2,uVar4);
  if (iVar5 < 0) goto LAB_005ceb61;
  puVar7 = &local_18;
  uVar4 = (**(code **)(*local_8 + 0xc))(local_8,puVar7);
  iVar5 = FUN_005c8e04(uVar4,puVar7);
  if ((iVar5 < 0) || (iVar5 = (**(code **)(*param_2 + 0xc))(param_2,&local_10), iVar5 < 0))
  goto LAB_005ceb61;
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 4))(local_8);
  }
  piVar1 = *(int **)(iVar6 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(iVar6 + 0x10) = 0;
  }
  *(int **)(iVar6 + 0x10) = local_8;
  *(undefined4 *)(iVar6 + 0x14) = local_18;
  if (local_10 == (int *)local_c[2]) {
    (**(code **)(*param_2 + 4))(param_2);
    piVar1 = (int *)(iVar6 + 4);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    *piVar1 = (int)param_2;
LAB_005cea93:
    *(undefined4 *)(iVar6 + 0xc) = 1;
  }
  else {
    piVar1 = (int *)(iVar6 + 4);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    FUN_005e8fb1(1);
    iVar5 = *(int *)local_c[2];
    uVar4 = (**(code **)(*local_8 + 0xc))(local_8,piVar1);
    iVar5 = (**(code **)(iVar5 + 0x16c))(local_c[2],uVar4);
    if (-1 < iVar5) {
      FUN_005e8fb1(0);
      goto LAB_005cea93;
    }
    FUN_005e8fb1(0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
  }
  param_2 = (int *)FUN_005ccec4(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x14),0);
  iVar5 = (int)param_2;
  if ((-1 < (int)param_2) && (param_4 != (int *)0x0)) {
    for (local_c = (int *)param_4[4]; iVar5 = (int)param_2, local_c != param_4;
        local_c = (int *)local_c[4]) {
      if (*local_c != 0) {
        iVar5 = *(int *)(local_c[2] + param_3 * 4) * 0x1c + *(int *)(*local_c + 0x24);
        piVar1 = *(int **)(iVar6 + 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        piVar1 = *(int **)(iVar6 + 0x10);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        piVar1 = *(int **)(iVar5 + 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(iVar5 + 4) = 0;
        }
        piVar1 = *(int **)(iVar5 + 0x10);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(iVar5 + 0x10) = 0;
        }
        *(int *)(iVar5 + 4) = *(int *)(iVar6 + 4);
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0xc);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0x10);
        uVar4 = *(undefined4 *)(iVar6 + 0x14);
        *(undefined4 *)(iVar5 + 0x14) = uVar4;
        param_2 = (int *)FUN_005ccec4(*(undefined4 *)(iVar5 + 0x18),uVar4,0);
        iVar5 = (int)param_2;
        if ((int)param_2 < 0) break;
      }
    }
  }
LAB_005ceb61:
  param_2 = (int *)iVar5;
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
    local_10 = (int *)0x0;
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return (int)param_2;
}


// ==== 0x5ceb89 FUN_005ceb89

int __thiscall
FUN_005ceb89(int param_1,int *param_2,int *param_3,int *param_4,int param_5,int param_6,int param_7)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;
  int local_10;
  int local_8;
  
  piVar1 = (int *)*param_2;
  local_8 = 0;
  iVar4 = *piVar1;
  local_10 = piVar1[4];
  iVar5 = piVar1[1];
  if (local_10 == 0) {
    local_10 = 1;
  }
  if (-1 < iVar5) {
    if (iVar5 < 4) {
      uVar7 = piVar1[6] * piVar1[5] * local_10;
      if (((iVar4 != 1) && (iVar4 != 2)) && (iVar4 != 3)) {
        return -0x7fffbffb;
      }
      iVar4 = uVar7 * 4;
      puVar9 = (undefined4 *)*param_4;
      puVar10 = (undefined4 *)*param_3;
      for (uVar7 = uVar7 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      *param_3 = *param_3 + iVar4;
      *param_4 = *param_4 + iVar4;
      *param_2 = *param_2 + 0x1c;
      return 0;
    }
    if (iVar5 != 4) {
      if (iVar5 != 5) {
        return -0x7fffbffb;
      }
      uVar7 = piVar1[5];
      *param_2 = (int)(piVar1 + 6);
      do {
        if (local_10 == 0) {
          return local_8;
        }
        uVar8 = 0;
        *param_2 = (int)(piVar1 + 6);
        if (uVar7 != 0) {
          do {
            local_8 = FUN_005ceb89(param_2,param_3,param_4,param_5,param_6,param_7);
            if (local_8 < 0) {
              return local_8;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar7);
        }
        local_10 = local_10 + -1;
      } while( true );
    }
    if (iVar4 < 0x10) {
      if (iVar4 == 0xf) {
        for (; local_10 != 0; local_10 = local_10 + -1) {
          if (param_6 == 0) {
            iVar4 = *(int *)*param_4;
          }
          else {
            iVar4 = *(int *)(*(int *)(param_6 + 8) + *(int *)*param_4 * 4);
          }
          iVar4 = iVar4 * 0x1c + *(int *)(param_7 + 0x24);
          if (param_5 == 0) {
            iVar5 = *(int *)*param_3;
          }
          else {
            iVar5 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
          }
          piVar1 = *(int **)(iVar4 + 0x10);
          iVar5 = iVar5 * 0x1c + *(int *)(param_1 + 0x24);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar5 + 0x10);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar5 + 0x10) = 0;
          }
          *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
          *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar4 + 0x14);
          if ((*(int *)(param_1 + 8) == *(int *)(param_7 + 8)) || (*(int *)(iVar4 + 0x10) == 0)) {
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
            }
            piVar1 = *(int **)(iVar5 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar5 + 4) = 0;
            }
            *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
          }
          else {
            piVar1 = (int *)(iVar5 + 4);
            piVar2 = (int *)*piVar1;
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 8))(piVar2);
              *piVar1 = 0;
            }
            if (param_5 != 0) {
              return -0x7fffbffb;
            }
            FUN_005e8fb1(1);
            iVar3 = **(int **)(param_1 + 8);
            uVar6 = (**(code **)(**(int **)(iVar4 + 0x10) + 0xc))(*(int **)(iVar4 + 0x10),piVar1);
            iVar4 = (**(code **)(iVar3 + 0x1a8))(*(undefined4 *)(param_1 + 8),uVar6);
            if (iVar4 < 0) {
              FUN_005e8fb1(0);
              *(undefined4 *)(iVar5 + 0xc) = 0;
            }
            else {
              FUN_005e8fb1(0);
              *(undefined4 *)(iVar5 + 0xc) = 1;
            }
          }
          local_8 = FUN_005ccec4(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x14),0);
          if (local_8 < 0) {
            return local_8;
          }
          *param_3 = *param_3 + 4;
          *param_4 = *param_4 + 4;
        }
        goto LAB_005cf051;
      }
      if (iVar4 == 4) {
        for (; local_10 != 0; local_10 = local_10 + -1) {
          if (param_6 == 0) {
            iVar4 = *(int *)*param_4;
          }
          else {
            iVar4 = *(int *)(*(int *)(param_6 + 8) + *(int *)*param_4 * 4);
          }
          iVar4 = iVar4 * 0x1c + *(int *)(param_7 + 0x24);
          if (param_5 == 0) {
            iVar5 = *(int *)*param_3;
          }
          else {
            iVar5 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
          }
          iVar5 = iVar5 * 0x1c + *(int *)(param_1 + 0x24);
          piVar1 = *(int **)(iVar4 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar5 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar5 + 4) = 0;
          }
          *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar4 + 4);
          *param_3 = *param_3 + 4;
          *param_4 = *param_4 + 4;
        }
        goto LAB_005cf051;
      }
      if (iVar4 < 5) {
        return -0x7fffbffb;
      }
      if (iVar4 < 10) {
        for (; local_10 != 0; local_10 = local_10 + -1) {
          if (param_6 == 0) {
            iVar4 = *(int *)*param_4;
          }
          else {
            iVar4 = *(int *)(*(int *)(param_6 + 8) + *(int *)*param_4 * 4);
          }
          iVar4 = iVar4 * 0x1c + *(int *)(param_7 + 0x24);
          if (param_5 == 0) {
            iVar5 = *(int *)*param_3;
          }
          else {
            iVar5 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
          }
          iVar5 = iVar5 * 0x1c + *(int *)(param_1 + 0x24);
          if (*(int *)(param_1 + 8) == *(int *)(param_7 + 8)) {
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
            }
            piVar1 = *(int **)(iVar5 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar5 + 4) = 0;
            }
            *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar4 + 4);
          }
          else {
            piVar1 = *(int **)(iVar5 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar5 + 4) = 0;
            }
            if (param_5 != 0) {
              return -0x7fffbffb;
            }
          }
          *param_3 = *param_3 + 4;
          *param_4 = *param_4 + 4;
        }
        goto LAB_005cf051;
      }
      bVar12 = SBORROW4(iVar4,0xe);
      iVar5 = -0xe;
      bVar11 = iVar4 == 0xe;
    }
    else {
      if (iVar4 == 0x10) {
        for (; local_10 != 0; local_10 = local_10 + -1) {
          if (param_6 == 0) {
            iVar4 = *(int *)*param_4;
          }
          else {
            iVar4 = *(int *)(*(int *)(param_6 + 8) + *(int *)*param_4 * 4);
          }
          iVar4 = iVar4 * 0x1c + *(int *)(param_7 + 0x24);
          if (param_5 == 0) {
            iVar5 = *(int *)*param_3;
          }
          else {
            iVar5 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
          }
          piVar1 = *(int **)(iVar4 + 0x10);
          iVar5 = iVar5 * 0x1c + *(int *)(param_1 + 0x24);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar5 + 0x10);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar5 + 0x10) = 0;
          }
          *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
          *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar4 + 0x14);
          if ((*(int *)(param_1 + 8) == *(int *)(param_7 + 8)) || (*(int *)(iVar4 + 0x10) == 0)) {
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
            }
            piVar1 = *(int **)(iVar5 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar5 + 4) = 0;
            }
            *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
          }
          else {
            piVar1 = (int *)(iVar5 + 4);
            piVar2 = (int *)*piVar1;
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 8))(piVar2);
              *piVar1 = 0;
            }
            if (param_5 != 0) {
              return -0x7fffbffb;
            }
            FUN_005e8fb1(1);
            iVar3 = **(int **)(param_1 + 8);
            uVar6 = (**(code **)(**(int **)(iVar4 + 0x10) + 0xc))(*(int **)(iVar4 + 0x10),piVar1);
            iVar4 = (**(code **)(iVar3 + 0x16c))(*(undefined4 *)(param_1 + 8),uVar6);
            if (iVar4 < 0) {
              FUN_005e8fb1(0);
              *(undefined4 *)(iVar5 + 0xc) = 0;
            }
            else {
              FUN_005e8fb1(0);
              *(undefined4 *)(iVar5 + 0xc) = 1;
            }
          }
          local_8 = FUN_005ccec4(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x14),0);
          if (local_8 < 0) {
            return local_8;
          }
          *param_3 = *param_3 + 4;
          *param_4 = *param_4 + 4;
        }
        goto LAB_005cf051;
      }
      if (iVar4 < 0x11) {
        return -0x7fffbffb;
      }
      bVar12 = SBORROW4(iVar4,0x12);
      iVar5 = -0x12;
      bVar11 = iVar4 == 0x12;
    }
    if (bVar11 || bVar12 != iVar4 + iVar5 < 0) {
LAB_005cf051:
      *param_2 = *param_2 + 0x14;
      return local_8;
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5cf0a4 FUN_005cf0a4

int FUN_005cf0a4(int *param_1,int *param_2,int *param_3,uint param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_8;
  
  piVar1 = (int *)*param_1;
  iVar4 = piVar1[1];
  local_8 = piVar1[4];
  iVar3 = 0;
  iVar2 = *piVar1;
  if ((param_5 != 0) || (local_8 == 0)) {
    local_8 = 1;
  }
  if (-1 < iVar4) {
    if (iVar4 < 4) {
      uVar5 = piVar1[6] * piVar1[5] * local_8;
      if (iVar2 == 1) {
        param_4 = 0;
        if (uVar5 != 0) {
          do {
            iVar4 = param_4 * 4;
            param_4 = param_4 + 1;
            *(uint *)(iVar4 + *param_2) = (uint)(*(int *)(iVar4 + *param_3) != 0);
          } while (param_4 < uVar5);
        }
      }
      else if (iVar2 == 2) {
        param_4 = 0;
        if (uVar5 != 0) {
          do {
            iVar4 = param_4 * 4;
            param_4 = param_4 + 1;
            *(undefined4 *)(iVar4 + *param_2) = *(undefined4 *)(iVar4 + *param_3);
          } while (param_4 < uVar5);
        }
      }
      else {
        if (iVar2 != 3) {
          return -0x7fffbffb;
        }
        param_4 = 0;
        if (uVar5 != 0) {
          do {
            iVar4 = param_4 * 4;
            param_4 = param_4 + 1;
            *(undefined4 *)(iVar4 + *param_2) = *(undefined4 *)(iVar4 + *param_3);
          } while (param_4 < uVar5);
        }
      }
      *param_2 = *param_2 + uVar5 * 4;
      *param_3 = *param_3 + uVar5 * 4;
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar4 == 4) {
      if (iVar2 == 4) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          iVar3 = FUN_005cabd8(*(undefined4 *)*param_3,*(undefined4 *)*param_2,param_4);
          if (iVar3 < 0) {
            return iVar3;
          }
          *param_2 = *param_2 + 4;
          *param_3 = *param_3 + 4;
        }
      }
      else {
        if (iVar2 < 5) {
          return -0x7fffbffb;
        }
        if (iVar2 < 10) {
          for (; local_8 != 0; local_8 = local_8 + -1) {
            iVar3 = FUN_005cab3f(*(undefined4 *)*param_3,*(undefined4 *)*param_2,param_4);
            if (iVar3 < 0) {
              return iVar3;
            }
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
          }
        }
        else if (iVar2 == 0xf) {
          for (; local_8 != 0; local_8 = local_8 + -1) {
            iVar3 = FUN_005ce64f(*(undefined4 *)*param_3,*(undefined4 *)*param_2,param_4);
            if (iVar3 < 0) {
              return iVar3;
            }
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
          }
        }
        else {
          if (iVar2 != 0x10) {
            return -0x7fffbffb;
          }
          for (; local_8 != 0; local_8 = local_8 + -1) {
            iVar3 = FUN_005ce8ec(*(undefined4 *)*param_3,*(undefined4 *)*param_2,param_4);
            if (iVar3 < 0) {
              return iVar3;
            }
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
          }
        }
      }
      *param_1 = *param_1 + 0x14;
      return iVar3;
    }
    if (iVar4 == 5) {
      uVar5 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (local_8 == 0) {
          return iVar3;
        }
        uVar6 = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar5 != 0) {
          do {
            iVar3 = FUN_005cf0a4(param_1,param_2,param_3,param_4,0);
            if (iVar3 < 0) {
              return iVar3;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar5);
        }
        local_8 = local_8 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5cf2e6 FUN_005cf2e6

void FUN_005cf2e6(void)

{
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  
  FUN_005ccba6(&stack0x00000004,&stack0x00000008,&stack0x0000000c,in_stack_00000010,
               in_stack_00000014);
  return;
}


// ==== 0x5cf304 FUN_005cf304

int __thiscall FUN_005cf304(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  uint local_8;
  
  local_14 = (int *)0x0;
  local_10 = (int *)0x0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)((int)param_2 + 4) * 4);
  param_2 = *(undefined4 **)(iVar2 + 0x2c);
  local_8 = 0;
  if (param_2 != (undefined4 *)0x0) {
    do {
      param_2 = (undefined4 *)param_2[4];
      piVar11 = (int *)param_2[2];
      piVar11[10] = piVar11[10] | 1;
      *param_2 = 1;
      iVar4 = piVar11[0x17];
      local_c = piVar11;
      if (iVar4 == 0) {
        if ((*(int *)(param_1 + 0x84) == 3) &&
           ((*(int *)(param_1 + 0x30) == piVar11[0x16] &&
            (*(int *)(param_1 + 0x34) == piVar11[0x15])))) {
          iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + piVar11[3] * 4);
          iVar9 = *(int *)(iVar4 + 0x38);
          iVar4 = *(int *)(iVar4 + 0x28) + piVar11[5];
          if (iVar9 == 0) {
            iVar4 = *(int *)(iVar4 + *(int *)(param_1 + 0x2c));
          }
          else {
            iVar4 = *(int *)(*(int *)(iVar9 + 8) +
                            *(int *)(iVar4 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
          }
          local_1c = (int *)(iVar4 * 0x1c + *(int *)(param_1 + 0x24));
          if (((local_1c[3] != 0) && (iVar4 = local_1c[5], iVar4 != 0)) &&
             (iVar9 = local_1c[6], (*(byte *)(iVar9 + 0x28) & 1) != 0)) {
            iVar4 = *(int *)(iVar4 + 0x10) + iVar4;
            iVar10 = iVar4 + param_2[5] * 0x14;
            sVar1 = *(short *)(iVar10 + 4);
            if (sVar1 == 2) {
              iVar9 = *(int *)(iVar9 + 0x44) + 8;
              local_8 = FUN_005cafde(param_2[1],(uint)*(ushort *)(iVar10 + 6) * 0x10 + iVar9,
                                     *(undefined2 *)(iVar10 + 8));
              if ((int)local_8 < 0) break;
              if (*local_1c == 0x10) {
                iVar4 = iVar4 + param_2[5] * 0x14;
                uVar5 = (uint)*(ushort *)(iVar4 + 6);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x178))
                                    (*(int **)(param_1 + 8),uVar5,uVar5 * 0x10 + iVar9,
                                     *(undefined2 *)(iVar4 + 8));
              }
              else if (*local_1c == 0xf) {
                iVar4 = iVar4 + param_2[5] * 0x14;
                uVar5 = (uint)*(ushort *)(iVar4 + 6);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x1b4))
                                    (*(int **)(param_1 + 8),uVar5,uVar5 * 0x10 + iVar9,
                                     *(undefined2 *)(iVar4 + 8));
              }
              else {
LAB_005cf5d7:
                local_8 = -0x7fffbffb;
              }
            }
            else if (sVar1 == 1) {
              piVar11 = *(int **)(iVar9 + 0x44);
              iVar9 = *piVar11;
              local_8 = FUN_005caf72(param_2[1],
                                     (int)piVar11 + (uint)*(ushort *)(iVar10 + 6) * 0x10 + iVar9,
                                     *(undefined2 *)(iVar10 + 8));
              if ((int)local_8 < 0) break;
              if (*local_1c == 0x10) {
                iVar4 = iVar4 + param_2[5] * 0x14;
                uVar5 = (uint)*(ushort *)(iVar4 + 6);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x180))
                                    (*(int **)(param_1 + 8),uVar5,
                                     (int)piVar11 + uVar5 * 0x10 + iVar9,*(undefined2 *)(iVar4 + 8))
                ;
              }
              else {
                if (*local_1c != 0xf) goto LAB_005cf5d7;
                iVar4 = iVar4 + param_2[5] * 0x14;
                uVar5 = (uint)*(ushort *)(iVar4 + 6);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x1bc))
                                    (*(int **)(param_1 + 8),uVar5,
                                     (int)piVar11 + uVar5 * 0x10 + iVar9,*(undefined2 *)(iVar4 + 8))
                ;
              }
            }
            else if (sVar1 == 0) {
              iVar9 = *(int *)(*(int *)(iVar9 + 0x44) + 4) + *(int *)(iVar9 + 0x44);
              local_8 = FUN_005cce58(param_2[1],iVar9 + (uint)*(ushort *)(iVar10 + 6) * 4,
                                     *(undefined2 *)(iVar10 + 8));
              if ((int)local_8 < 0) break;
              if (*local_1c == 0x10) {
                iVar4 = iVar4 + param_2[5] * 0x14;
                uVar5 = (uint)*(ushort *)(iVar4 + 6);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x188))
                                    (*(int **)(param_1 + 8),uVar5,iVar9 + uVar5 * 4,
                                     *(undefined2 *)(iVar4 + 8));
              }
              else {
                if (*local_1c != 0xf) goto LAB_005cf5d7;
                iVar4 = iVar4 + param_2[5] * 0x14;
                uVar5 = (uint)*(ushort *)(iVar4 + 6);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x1c4))
                                    (*(int **)(param_1 + 8),uVar5,iVar9 + uVar5 * 4,
                                     *(undefined2 *)(iVar4 + 8));
              }
            }
            if ((int)local_8 < 0) break;
            *param_2 = 0;
            *(uint *)(local_1c[6] + 0x28) = *(uint *)(local_1c[6] + 0x28) & 0xfffffffe;
          }
        }
      }
      else if (iVar4 == -1) {
        local_1c = (int *)0x0;
        iVar4 = piVar11[0x15] * 0xac + *(int *)(param_1 + 0x1c);
        if (*piVar11 == -1) {
          local_8 = FUN_005cdca7(piVar11);
          if ((int)local_8 < 0) break;
          piVar11 = (int *)piVar11[0x19];
        }
        local_c = piVar11;
        if (*(int *)(&DAT_006dc274 + *piVar11 * 0x1c) == 0x6000000) {
          iVar9 = *(int *)(*(int *)(param_1 + 0x8c) + piVar11[3] * 4);
          iVar10 = *(int *)(iVar9 + 0x38);
          iVar9 = *(int *)(iVar9 + 0x28) + piVar11[5];
          if (iVar10 == 0) {
            iVar9 = *(int *)(iVar9 + *(int *)(param_1 + 0x2c));
          }
          else {
            iVar9 = *(int *)(*(int *)(iVar10 + 8) +
                            *(int *)(iVar9 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
          }
          iVar10 = iVar4 + 0x98;
          iVar12 = iVar4 + 0x94;
          iVar8 = iVar4 + 0x90;
LAB_005cfbc0:
          local_8 = FUN_005c80ae(*(undefined4 *)(iVar9 * 0x1c + 0x14 + *(int *)(param_1 + 0x24)),
                                 iVar8,iVar12,iVar10,iVar4 + 0xa8,&local_1c);
          if ((int)local_8 < 0) break;
        }
        else if (*(int *)(&DAT_006dc274 + *piVar11 * 0x1c) == 0x6000001) {
          iVar9 = *(int *)(*(int *)(param_1 + 0x8c) + piVar11[3] * 4);
          iVar10 = *(int *)(iVar9 + 0x38);
          iVar9 = *(int *)(iVar9 + 0x28) + piVar11[5];
          if (iVar10 == 0) {
            iVar9 = *(int *)(iVar9 + *(int *)(param_1 + 0x2c));
          }
          else {
            iVar9 = *(int *)(*(int *)(iVar10 + 8) +
                            *(int *)(iVar9 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
          }
          iVar10 = iVar4 + 0xa4;
          iVar12 = iVar4 + 0xa0;
          iVar8 = iVar4 + 0x9c;
          goto LAB_005cfbc0;
        }
        if ((*(int *)(param_1 + 0x84) == 3) && (*(int *)(param_1 + 0x34) == piVar11[0x15])) {
          if (local_1c != (int *)0x0) {
            piVar11 = *(int **)(iVar4 + 0x88);
            if (piVar11 != (int *)0x0) {
              if ((*(byte *)(param_1 + 0x3c) & 2) == 0) {
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf0))(*(int **)(param_1 + 8));
                if ((int)local_8 < 0) break;
                FUN_005e8fb1(1);
                if (*(int *)(iVar4 + 0x90) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x178))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xa8),
                             *(int *)(iVar4 + 0x90));
                }
                if (*(int *)(iVar4 + 0x94) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x188))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xac),
                             *(int *)(iVar4 + 0x94));
                }
                if (*(int *)(iVar4 + 0x98) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x180))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xb0),
                             *(int *)(iVar4 + 0x98));
                }
                if (*(int *)(iVar4 + 0x9c) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x1b4))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xa8),
                             *(int *)(iVar4 + 0x9c));
                }
                if (*(int *)(iVar4 + 0xa0) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x1c4))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xac),
                             *(int *)(iVar4 + 0xa0));
                }
                if (*(int *)(iVar4 + 0xa4) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x1bc))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xb0),
                             *(int *)(iVar4 + 0xa4));
                }
                FUN_005e8fb1(0);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf4))
                                    (*(int **)(param_1 + 8),&local_14);
                if (((int)local_8 < 0) ||
                   (local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf0))(*(int **)(param_1 + 8)),
                   (int)local_8 < 0)) break;
                FUN_005e8fb1(1);
                if (*(int *)(iVar4 + 0x90) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x178))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xa8),
                             *(int *)(iVar4 + 0x90));
                }
                if (*(int *)(iVar4 + 0x94) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x188))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xac),
                             *(int *)(iVar4 + 0x94));
                }
                if (*(int *)(iVar4 + 0x98) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x180))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xb0),
                             *(int *)(iVar4 + 0x98));
                }
                if (*(int *)(iVar4 + 0x9c) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x1b4))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xa8),
                             *(int *)(iVar4 + 0x9c));
                }
                if (*(int *)(iVar4 + 0xa0) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x1c4))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xac),
                             *(int *)(iVar4 + 0xa0));
                }
                if (*(int *)(iVar4 + 0xa4) != 0) {
                  (**(code **)(**(int **)(param_1 + 8) + 0x1bc))
                            (*(int **)(param_1 + 8),0,*(undefined4 *)(param_1 + 0xb0),
                             *(int *)(iVar4 + 0xa4));
                }
                FUN_005e8fb1(0);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf4))
                                    (*(int **)(param_1 + 8),&local_10);
                if (((((int)local_8 < 0) ||
                     (local_8 = (**(code **)(*local_10 + 0x10))(local_10), (int)local_8 < 0)) ||
                    (local_8 = (**(code **)(**(int **)(iVar4 + 0x88) + 0x14))
                                         (*(int **)(iVar4 + 0x88)), (int)local_8 < 0)) ||
                   ((local_8 = (**(code **)(*local_14 + 0x10))(local_14), (int)local_8 < 0 ||
                    (local_8 = (**(code **)(*local_10 + 0x14))(local_10), (int)local_8 < 0))))
                break;
                piVar11 = *(int **)(iVar4 + 0x88);
                if (piVar11 != (int *)0x0) {
                  (**(code **)(*piVar11 + 8))(piVar11);
                  *(undefined4 *)(iVar4 + 0x88) = 0;
                }
                *(int **)(iVar4 + 0x88) = local_14;
                local_14 = (int *)0x0;
                if (local_10 != (int *)0x0) {
                  (**(code **)(*local_10 + 8))(local_10);
                  local_10 = (int *)0x0;
                }
              }
              else {
                (**(code **)(*piVar11 + 8))(piVar11);
                *(undefined4 *)(iVar4 + 0x88) = 0;
              }
            }
            piVar11 = *(int **)(iVar4 + 0x8c);
            if (piVar11 != (int *)0x0) {
              if ((*(byte *)(param_1 + 0x3c) & 1) == 0) {
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf0))(*(int **)(param_1 + 8));
                if ((int)local_8 < 0) break;
                FUN_005e8fb1(1);
                local_8 = 0;
                if (*(int *)(iVar4 + 0xa8) != 0) {
                  do {
                    (**(code **)(**(int **)(param_1 + 8) + 0x104))(*(int **)(param_1 + 8),local_8,0)
                    ;
                    uVar5 = 0x1c;
                    do {
                      piVar11 = *(int **)(param_1 + 8);
                      if (*(int *)(uVar5 + 0x6db9c0) == 0) {
                        (**(code **)(*piVar11 + 0x114))
                                  (piVar11,local_8,*(uint *)(uVar5 + 0x6db9bc) & 0xffffff,0);
                      }
                      else {
                        (**(code **)(*piVar11 + 0x114))
                                  (piVar11,local_8,*(uint *)(uVar5 + 0x6db9bc) & 0xffffff,
                                   *(undefined4 *)(*(int *)(uVar5 + 0x6db9c0) + 4));
                      }
                      uVar5 = uVar5 + 0x1c;
                    } while (uVar5 < 0x16c);
                    local_8 = local_8 + 1;
                  } while (local_8 < *(uint *)(iVar4 + 0xa8));
                }
                FUN_005e8fb1(0);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf4))
                                    (*(int **)(param_1 + 8),&local_14);
                if (((int)local_8 < 0) ||
                   (local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf0))(*(int **)(param_1 + 8)),
                   (int)local_8 < 0)) break;
                FUN_005e8fb1(1);
                local_8 = 0;
                if (*(int *)(iVar4 + 0xa8) != 0) {
                  do {
                    (**(code **)(**(int **)(param_1 + 8) + 0x104))(*(int **)(param_1 + 8),local_8,0)
                    ;
                    uVar5 = 0x1c;
                    do {
                      piVar11 = *(int **)(param_1 + 8);
                      if (*(int *)(uVar5 + 0x6db9c0) == 0) {
                        (**(code **)(*piVar11 + 0x114))
                                  (piVar11,local_8,*(uint *)(uVar5 + 0x6db9bc) & 0xffffff,0);
                      }
                      else {
                        (**(code **)(*piVar11 + 0x114))
                                  (piVar11,local_8,*(uint *)(uVar5 + 0x6db9bc) & 0xffffff,
                                   *(undefined4 *)(*(int *)(uVar5 + 0x6db9c0) + 4));
                      }
                      uVar5 = uVar5 + 0x1c;
                    } while (uVar5 < 0x16c);
                    local_8 = local_8 + 1;
                  } while (local_8 < *(uint *)(iVar4 + 0xa8));
                }
                FUN_005e8fb1(0);
                local_8 = (**(code **)(**(int **)(param_1 + 8) + 0xf4))
                                    (*(int **)(param_1 + 8),&local_10);
                if (((((int)local_8 < 0) ||
                     (local_8 = (**(code **)(*local_10 + 0x10))(local_10), (int)local_8 < 0)) ||
                    (local_8 = (**(code **)(**(int **)(iVar4 + 0x88) + 0x14))
                                         (*(int **)(iVar4 + 0x88)), (int)local_8 < 0)) ||
                   ((local_8 = (**(code **)(*local_14 + 0x10))(local_14), (int)local_8 < 0 ||
                    (local_8 = (**(code **)(*local_10 + 0x14))(local_10), (int)local_8 < 0))))
                break;
                piVar11 = *(int **)(iVar4 + 0x8c);
                if (piVar11 != (int *)0x0) {
                  (**(code **)(*piVar11 + 8))(piVar11);
                  *(undefined4 *)(iVar4 + 0x8c) = 0;
                }
                *(int **)(iVar4 + 0x8c) = local_14;
                local_14 = (int *)0x0;
                if (local_10 != (int *)0x0) {
                  (**(code **)(*local_10 + 8))(local_10);
                  local_10 = (int *)0x0;
                }
              }
              else {
                (**(code **)(*piVar11 + 8))(piVar11);
                *(undefined4 *)(iVar4 + 0x8c) = 0;
              }
            }
          }
          piVar11 = local_c;
          if ((*(int *)(param_1 + 0x30) == local_c[0x16]) &&
             ((local_8 = FUN_005cdca7(local_c), (int)local_8 < 0 ||
              (local_8 = FUN_005c97cb(piVar11,0xffffffff), (int)local_8 < 0)))) break;
        }
        else if (local_1c != (int *)0x0) {
          piVar11 = *(int **)(iVar4 + 0x88);
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 8))(piVar11);
            *(int *)(iVar4 + 0x88) = 0;
          }
          piVar11 = *(int **)(iVar4 + 0x8c);
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 8))(piVar11);
            *(int *)(iVar4 + 0x8c) = 0;
          }
        }
      }
      else if (*(int *)(param_1 + 0x84) == 3) {
        iVar9 = *(int *)(param_1 + 0x8c);
        piVar6 = *(int **)(*(int *)(iVar9 + iVar4 * 4) + 0x2c);
        if (piVar6 != (int *)0x0) {
          do {
            local_1c = (int *)piVar6[4];
            piVar6 = (int *)local_1c[2];
            iVar4 = piVar6[0x17];
            if (iVar4 == 0) {
              if ((*(int *)(param_1 + 0x30) == piVar6[0x16]) &&
                 (*(int *)(param_1 + 0x34) == piVar6[0x15])) {
                iVar4 = *(int *)(iVar9 + piVar6[3] * 4);
                iVar9 = *(int *)(iVar4 + 0x38);
                iVar4 = *(int *)(iVar4 + 0x28) + piVar6[5];
                if (iVar9 == 0) {
                  iVar4 = *(int *)(iVar4 + *(int *)(param_1 + 0x2c));
                }
                else {
                  iVar4 = *(int *)(*(int *)(iVar9 + 8) +
                                  *(int *)(iVar4 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
                }
                piVar6 = (int *)(iVar4 * 0x1c + *(int *)(param_1 + 0x24));
                if (((*piVar6 == 0xf) && (piVar6[3] != 0)) && (iVar4 = piVar6[5], iVar4 != 0)) {
                  iVar9 = *(int *)(iVar4 + 0x10);
                  local_8 = FUN_005cdca7(piVar11);
                  if ((int)local_8 < 0) goto LAB_005d0130;
                  uVar5 = (uint)*(ushort *)(iVar9 + iVar4 + 6 + local_1c[5] * 0x14);
LAB_005cf7fe:
                  local_8 = FUN_005c97cb(piVar11,uVar5);
                  if ((int)local_8 < 0) goto LAB_005d0130;
                }
              }
            }
            else if (iVar4 == -1) {
              if ((*(int *)(param_1 + 0x30) == piVar6[0x16]) &&
                 (*(int *)(param_1 + 0x34) == piVar6[0x15])) {
                iVar4 = *(int *)(&DAT_006dc274 + *piVar6 * 0x1c);
                if (iVar4 == 0x9000000) {
                  local_8 = FUN_005cdca7(piVar11);
                  if (-1 < (int)local_8) {
                    uVar5 = piVar6[1];
                    goto LAB_005cf7fe;
                  }
                  goto LAB_005d0130;
                }
                if ((iVar4 == 0x6000000) || (iVar4 == 0x6000001)) {
                  iVar4 = *(int *)(iVar9 + piVar6[3] * 4);
                  iVar9 = *(int *)(iVar4 + 0x38);
                  iVar4 = *(int *)(iVar4 + 0x28) + piVar6[5];
                  if (iVar9 == 0) {
                    iVar4 = *(int *)(iVar4 + *(int *)(param_1 + 0x2c));
                  }
                  else {
                    iVar4 = *(int *)(*(int *)(iVar9 + 8) +
                                    *(int *)(iVar4 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
                  }
                  local_18 = (int *)(iVar4 * 0x1c + *(int *)(param_1 + 0x24));
                  if (((local_18[3] != 0) && (local_18[5] != 0)) &&
                     ((*(byte *)(local_18[6] + 0x28) & 1) != 0)) {
                    iVar9 = *(int *)(local_18[5] + 0x10) + local_18[5];
                    iVar4 = iVar9 + param_2[5] * 0x14;
                    sVar1 = *(short *)(iVar4 + 4);
                    if (sVar1 == 2) {
                      iVar10 = *(int *)(local_18[6] + 0x44) + 8;
                      local_8 = FUN_005cafde(param_2[1],(uint)*(ushort *)(iVar4 + 6) * 0x10 + iVar10
                                             ,*(undefined2 *)(iVar4 + 8));
                      if ((int)local_8 < 0) goto LAB_005d0130;
                      if (*local_18 == 0x10) {
                        iVar9 = iVar9 + param_2[5] * 0x14;
                        uVar5 = (uint)*(ushort *)(iVar9 + 6);
                        local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x178))
                                            (*(int **)(param_1 + 8),uVar5,uVar5 * 0x10 + iVar10,
                                             *(undefined2 *)(iVar9 + 8));
                        piVar11 = local_c;
                      }
                      else if (*local_18 == 0xf) {
                        iVar9 = iVar9 + param_2[5] * 0x14;
                        uVar5 = (uint)*(ushort *)(iVar9 + 6);
                        local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x1b4))
                                            (*(int **)(param_1 + 8),uVar5,uVar5 * 0x10 + iVar10,
                                             *(undefined2 *)(iVar9 + 8));
                        piVar11 = local_c;
                      }
                      else {
LAB_005cfa9b:
                        local_8 = -0x7fffbffb;
                        piVar11 = local_c;
                      }
                    }
                    else if (sVar1 == 1) {
                      piVar11 = *(int **)(local_18[6] + 0x44);
                      iVar10 = *piVar11;
                      local_8 = FUN_005caf72(param_2[1],
                                             (int)piVar11 +
                                             (uint)*(ushort *)(iVar4 + 6) * 0x10 + iVar10,
                                             *(undefined2 *)(iVar4 + 8));
                      if ((int)local_8 < 0) goto LAB_005d0130;
                      if (*local_18 == 0x10) {
                        iVar9 = iVar9 + param_2[5] * 0x14;
                        uVar5 = (uint)*(ushort *)(iVar9 + 6);
                        local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x180))
                                            (*(int **)(param_1 + 8),uVar5,
                                             (int)piVar11 + uVar5 * 0x10 + iVar10,
                                             *(undefined2 *)(iVar9 + 8));
                        piVar11 = local_c;
                      }
                      else {
                        if (*local_18 != 0xf) goto LAB_005cfa9b;
                        iVar9 = iVar9 + param_2[5] * 0x14;
                        uVar5 = (uint)*(ushort *)(iVar9 + 6);
                        local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x1bc))
                                            (*(int **)(param_1 + 8),uVar5,
                                             (int)piVar11 + uVar5 * 0x10 + iVar10,
                                             *(undefined2 *)(iVar9 + 8));
                        piVar11 = local_c;
                      }
                    }
                    else if (sVar1 == 0) {
                      iVar10 = *(int *)(*(int *)(local_18[6] + 0x44) + 4) +
                               *(int *)(local_18[6] + 0x44);
                      local_8 = FUN_005cce58(param_2[1],iVar10 + (uint)*(ushort *)(iVar4 + 6) * 4,
                                             *(undefined2 *)(iVar4 + 8));
                      if ((int)local_8 < 0) goto LAB_005d0130;
                      if (*local_18 == 0x10) {
                        iVar9 = iVar9 + param_2[5] * 0x14;
                        uVar5 = (uint)*(ushort *)(iVar9 + 6);
                        local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x188))
                                            (*(int **)(param_1 + 8),uVar5,iVar10 + uVar5 * 4,
                                             *(undefined2 *)(iVar9 + 8));
                        piVar11 = local_c;
                      }
                      else {
                        if (*local_18 != 0xf) goto LAB_005cfa9b;
                        iVar9 = iVar9 + param_2[5] * 0x14;
                        uVar5 = (uint)*(ushort *)(iVar9 + 6);
                        local_8 = (**(code **)(**(int **)(param_1 + 8) + 0x1c4))
                                            (*(int **)(param_1 + 8),uVar5,iVar10 + uVar5 * 4,
                                             *(undefined2 *)(iVar9 + 8));
                        piVar11 = local_c;
                      }
                    }
                    if ((int)local_8 < 0) goto LAB_005d0130;
                    *param_2 = 0;
                    *(uint *)(local_18[6] + 0x28) = *(uint *)(local_18[6] + 0x28) & 0xfffffffe;
                    break;
                  }
                }
              }
            }
            else {
              piVar3 = *(int **)(*(int *)(iVar9 + iVar4 * 4) + 0x2c);
              piVar7 = piVar3;
              if (piVar3 != (int *)0x0) {
                do {
                  piVar7 = (int *)piVar7[4];
                  piVar11 = (int *)piVar7[2];
                  local_18 = piVar7;
                  if (((*(int *)(param_1 + 0x30) == piVar11[0x16]) &&
                      (*(int *)(param_1 + 0x34) == piVar11[0x15])) &&
                     (*(int *)(&DAT_006dc274 + *piVar11 * 0x1c) == 0x6000001)) {
                    iVar4 = *(int *)(iVar9 + piVar11[3] * 4);
                    iVar10 = *(int *)(iVar4 + 0x38);
                    iVar4 = *(int *)(iVar4 + 0x28) + piVar11[5];
                    if (iVar10 == 0) {
                      iVar4 = *(int *)(iVar4 + *(int *)(param_1 + 0x2c));
                    }
                    else {
                      iVar4 = *(int *)(*(int *)(iVar10 + 8) +
                                      *(int *)(iVar4 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
                    }
                    iVar4 = iVar4 * 0x1c + *(int *)(param_1 + 0x24);
                    if ((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 0x14) != 0)) {
                      iVar4 = *(int *)(iVar4 + 0x14);
                      iVar9 = *(int *)(iVar4 + 0x10);
                      local_8 = FUN_005cdca7(local_c);
                      if (((int)local_8 < 0) ||
                         (local_8 = FUN_005c97cb(local_c,*(undefined2 *)
                                                          (iVar9 + iVar4 + 6 + local_1c[5] * 0x14)),
                         (int)local_8 < 0)) goto LAB_005d0130;
                      break;
                    }
                  }
                } while (piVar7 != piVar3);
                *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + piVar6[0x17] * 4) + 0x2c) = local_18[3]
                ;
                piVar11 = local_c;
              }
            }
            iVar9 = *(int *)(param_1 + 0x8c);
            piVar6 = local_1c;
          } while (local_1c != *(int **)(*(int *)(iVar9 + piVar11[0x17] * 4) + 0x2c));
          *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + piVar11[0x17] * 4) + 0x2c) = local_1c[3];
        }
      }
    } while (param_2 != *(undefined4 **)(iVar2 + 0x2c));
  }
LAB_005d0130:
  if (*(int *)(param_1 + 0xb4) != 0) {
    __controlfp(*(uint *)(param_1 + 0xb8),0x30000);
    *(int *)(param_1 + 0xb4) = 0;
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
    local_14 = (int *)0x0;
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  return local_8;
}


// ==== 0x5d0177 FUN_005d0177

void __fastcall FUN_005d0177(undefined4 *param_1)

{
  param_1[6] = 0xffffffff;
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = 3;
  param_1[0xd] = 0;
  param_1[0xb] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[8] = 0;
  param_1[0xe] = 0;
  return;
}


// ==== 0x5d019e FUN_005d019e

undefined4 * __thiscall FUN_005d019e(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005cd25f();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0xac,*_Memory,FUN_005cd25f);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5d01ec FUN_005d01ec

int FUN_005d01ec(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  iVar2 = param_1;
  local_8 = 0;
  if ((*(int *)(param_1 + 0x84) == 0) ||
     (iVar3 = *(int *)(param_1 + 0x34) * 0xac + *(int *)(param_1 + 0x1c),
     *(uint *)(iVar3 + 0x2c) <= param_2)) {
    local_8 = -0x7789f794;
  }
  else {
    *(uint *)(param_1 + 0x30) = param_2;
    iVar3 = param_2 * 0x3c + *(int *)(iVar3 + 0x30);
    param_2 = 0;
    if (*(int *)(iVar3 + 0x24) != 0) {
      param_1 = 0;
      do {
        iVar4 = *(int *)(iVar3 + 0x28) + param_1;
        local_8 = FUN_005cdca7(iVar4);
        if ((local_8 < 0) || (local_8 = FUN_005c97cb(iVar4,0xffffffff), local_8 < 0)) break;
        param_2 = param_2 + 1;
        param_1 = param_1 + 0xac;
      } while (param_2 < *(uint *)(iVar3 + 0x24));
    }
  }
  piVar1 = (int *)(iVar2 + 0xb4);
  if (*piVar1 != 0) {
    __controlfp(*(uint *)(iVar2 + 0xb8),0x30000);
    *piVar1 = 0;
  }
  return local_8;
}


// ==== 0x5d0298 FUN_005d0298

void FUN_005d0298(void)

{
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  
  FUN_005ceb89(&stack0x00000004,&stack0x00000008,&stack0x0000000c,in_stack_00000010,
               in_stack_00000014,in_stack_00000018);
  return;
}


// ==== 0x5d02b9 FUN_005d02b9

void FUN_005d02b9(void)

{
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  
  FUN_005cf0a4(&stack0x00000004,&stack0x00000008,&stack0x0000000c,in_stack_00000010,
               in_stack_00000014);
  return;
}


// ==== 0x5d02d7 FUN_005d02d7

void __thiscall FUN_005d02d7(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_005cf304(param_2);
  if ((-1 < iVar2) &&
     (piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(param_2 + 4) * 4) + 0x38),
     piVar1 != (int *)0x0)) {
    for (piVar3 = (int *)piVar1[4]; piVar3 != piVar1; piVar3 = (int *)piVar3[4]) {
      if ((*piVar3 != 0) && (iVar2 = FUN_005cf304(piVar3[1]), iVar2 < 0)) {
        return;
      }
    }
  }
  return;
}


// ==== 0x5d031f FUN_005d031f

void __fastcall FUN_005d031f(int param_1)

{
  int iVar1;
  void *_Memory;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_005d019e(3);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_005cb122(1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x34);
  while (iVar1 != 0) {
    _Memory = *(void **)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)((int)_Memory + 0x34);
    *(undefined4 *)((int)_Memory + 0x34) = 0;
    FUN_005d031f();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 0x34);
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_005b09ec(1);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  FUN_005cd1d4();
  return;
}


// ==== 0x5d0387 FUN_005d0387

void * __thiscall FUN_005d0387(void *param_1,byte param_2)

{
  FUN_005d031f();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d03a3 FUN_005d03a3

void __fastcall FUN_005d03a3(int param_1)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_005d019e(3);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_005d0387(1);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  FUN_005cd1d4();
  return;
}


// ==== 0x5d03d2 FUN_005d03d2

undefined4 * __thiscall FUN_005d03d2(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005d03a3();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0x3c,*_Memory,FUN_005d03a3);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5d041d FUN_005d041d

int __fastcall FUN_005d041d(undefined4 *param_1)

{
  int extraout_EDX;
  
  *param_1 = &PTR_FUN_006a0630;
  FUN_005d0177();
  *(undefined4 *)(extraout_EDX + 0xc) = 0;
  *(undefined4 *)(extraout_EDX + 8) = 0;
  *(undefined4 *)(extraout_EDX + 0x14) = 0;
  *(undefined4 *)(extraout_EDX + 0x1c) = 0;
  *(undefined4 *)(extraout_EDX + 0x24) = 0;
  *(undefined4 *)(extraout_EDX + 0x2c) = 0;
  *(undefined4 *)(extraout_EDX + 0x8c) = 0;
  *(undefined4 *)(extraout_EDX + 0x38) = 0;
  *(undefined4 *)(extraout_EDX + 0x90) = 0;
  *(undefined4 *)(extraout_EDX + 0x98) = 0;
  *(undefined4 *)(extraout_EDX + 0xa8) = 0;
  *(undefined4 *)(extraout_EDX + 0xac) = 0;
  *(undefined4 *)(extraout_EDX + 0xb0) = 0;
  *(undefined4 *)(extraout_EDX + 0x94) = 0;
  *(undefined4 *)(extraout_EDX + 0xb4) = 0;
  *(undefined4 *)(extraout_EDX + 100) = 0;
  *(undefined4 *)(extraout_EDX + 0x68) = 0;
  *(undefined4 *)(extraout_EDX + 0x48) = 0;
  *(undefined4 *)(extraout_EDX + 0x4c) = 0;
  *(undefined4 *)(extraout_EDX + 0x44) = 0;
  *(undefined4 *)(extraout_EDX + 4) = 1;
  *(undefined4 *)(extraout_EDX + 0xb8) = 0x10000;
  return extraout_EDX;
}


// ==== 0x5d0497 FUN_005d0497

undefined4 * __thiscall FUN_005d0497(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005d031f();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0x44,*_Memory,FUN_005d031f);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5d04e2 FUN_005d04e2

int __thiscall FUN_005d04e2(int param_1,int param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  int local_8;
  
  puVar4 = param_4;
  piVar3 = param_3;
  iVar2 = param_2;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  if ((param_3 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar6 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar6 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar6 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(iVar6 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) && (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), uVar5 < *param_4)
     ) {
    return -0x7fffbffb;
  }
  piVar1 = (int *)(param_2 + 0x30);
  param_2 = 0;
  param_4 = (uint *)iVar2;
  param_3 = (int *)0x0;
  if (*piVar1 != 0) {
    do {
      pvVar7 = _malloc(0x44);
      if (pvVar7 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_005d0177();
      }
      if (local_8 == 0) {
        return -0x7ff8fff2;
      }
      param_2 = FUN_005c9025(local_8,piVar3,puVar4);
      if (param_2 < 0) goto LAB_005d0606;
      param_3 = (int *)((int)param_3 + 1);
      *(int *)((int)param_4 + 0x34) = local_8;
      param_4 = (uint *)local_8;
    } while (param_3 < *(uint *)(iVar2 + 0x30));
  }
  local_8 = 0;
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
LAB_005d0606:
  if (local_8 != 0) {
    FUN_005d0387(1);
  }
  return param_2;
}


// ==== 0x5d0627 FUN_005d0627

int FUN_005d0627(uint param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  int local_10;
  int local_8;
  
  puVar2 = param_3;
  iVar1 = param_1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) && (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), uVar3 < *param_3)
     ) {
    return -0x7fffbffb;
  }
  iVar4 = FUN_005c90b3(*(undefined4 *)(param_1 + 0x20));
  if (-1 < iVar4) {
    piVar6 = (int *)(param_1 + 0x2c);
    local_10 = 0;
    param_1 = 0;
    if (*piVar6 != 0) {
      do {
        pvVar5 = _malloc(0x44);
        if (pvVar5 == (void *)0x0) {
          local_8 = 0;
        }
        else {
          local_8 = FUN_005d0177();
        }
        if (local_8 == 0) {
          return -0x7ff8fff2;
        }
        iVar4 = FUN_005c9025(local_8,param_2,param_3);
        if (iVar4 < 0) goto LAB_005d07dd;
        if (local_10 == 0) {
          *(int *)(iVar1 + 0x30) = local_8;
        }
        else {
          *(int *)(local_10 + 0x34) = local_8;
        }
        local_10 = local_8;
        param_1 = param_1 + 1;
      } while (param_1 < *(uint *)(iVar1 + 0x2c));
    }
    param_3 = (uint *)iVar4;
    local_8 = 0;
    iVar4 = *(int *)(iVar1 + 0x24);
    if (iVar4 != 0) {
      piVar6 = _malloc(iVar4 * 0xac + 4);
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        *piVar6 = iVar4;
        piVar6 = piVar6 + 1;
        CallNTimes(piVar6,0xac,iVar4,FUN_005cd207);
      }
      *(int **)(iVar1 + 0x28) = piVar6;
      if (piVar6 == (int *)0x0) {
        return -0x7ff8fff2;
      }
    }
    iVar7 = 0;
    param_1 = 0;
    iVar4 = (int)param_3;
    if (*(int *)(iVar1 + 0x24) != 0) {
      do {
        *(undefined4 *)(*(int *)(iVar1 + 0x28) + 0x54 + iVar7) = *(undefined4 *)(iVar1 + 4);
        *(undefined4 *)(*(int *)(iVar1 + 0x28) + 0x58 + iVar7) = *(undefined4 *)(iVar1 + 8);
        iVar4 = FUN_005cb1d4(*(int *)(iVar1 + 0x28) + iVar7,param_2,puVar2);
        if (iVar4 < 0) {
          return iVar4;
        }
        param_1 = param_1 + 1;
        iVar7 = iVar7 + 0xac;
      } while (param_1 < *(uint *)(iVar1 + 0x24));
LAB_005d07dd:
      param_3 = (uint *)iVar4;
      iVar4 = (int)param_3;
      if (local_8 != 0) {
        FUN_005d0387(1);
      }
    }
  }
  param_3 = (uint *)iVar4;
  return (int)param_3;
}


// ==== 0x5d07f5 FUN_005d07f5

uint __thiscall FUN_005d07f5(int param_1,undefined4 *param_2,char *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  undefined4 *puVar16;
  int *piVar17;
  undefined4 *puVar18;
  uint local_20;
  uint local_1c;
  uint local_10;
  undefined4 *local_c;
  int *local_8;
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    return 0;
  }
  iVar2 = FUN_005ca175(param_2,10);
  if (iVar2 == 0) {
    iVar2 = FUN_005ca526(param_2,10);
    if (iVar2 == 0) {
      iVar2 = FUN_005ca4f3(param_2,10);
      if (iVar2 == 0) {
        return 0;
      }
      piVar8 = (int *)(iVar2 + 0x2c);
      puVar3 = (uint *)(iVar2 + 0x30);
    }
    else {
      piVar8 = (int *)(iVar2 + 0x24);
      puVar3 = (uint *)(iVar2 + 0x28);
    }
  }
  else {
    piVar8 = (int *)(iVar2 + 0x30);
    puVar3 = (uint *)(iVar2 + 0x34);
  }
  local_1c = 0;
  uVar7 = *puVar3;
  while (uVar12 = uVar7, uVar12 != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(uVar12 + 4) * 4);
    iVar13 = *(int *)(iVar2 + 0x38);
    if (iVar13 == 0) {
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar4 = *(int *)(iVar2 + 0x24) + *(int *)(uVar12 + 8) + iVar4;
    if (iVar13 == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar14 = *(int *)(iVar4 + 8);
    pcVar10 = param_3;
    if (*(int *)(iVar14 + iVar2) == 0) {
      pcVar9 = (char *)0x0;
    }
    else {
      if (iVar13 == 0) {
        iVar2 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      pcVar9 = (char *)(iVar14 + 4 + iVar2);
    }
    for (; (*pcVar10 == *pcVar9 && (*pcVar10 != '\0')); pcVar10 = pcVar10 + 1) {
      pcVar9 = pcVar9 + 1;
    }
    cVar1 = *pcVar10;
    if (cVar1 == *pcVar9) {
      return ~uVar12;
    }
    if (*pcVar9 == '\0') {
      if (cVar1 == '.') {
        pcVar10 = pcVar10 + 1;
        uVar12 = ~uVar12;
        goto LAB_005d0a16;
      }
      if (cVar1 == '[') {
        pcVar10 = pcVar10 + 1;
        if (*pcVar10 < '0') {
          return 0;
        }
        if ('9' < *pcVar10) {
          return 0;
        }
        uVar7 = _atoi(pcVar10);
        if (*(uint *)(iVar4 + 0x10) <= uVar7) {
          return 0;
        }
        for (; ('/' < *pcVar10 && (*pcVar10 < ':')); pcVar10 = pcVar10 + 1) {
        }
        if (*pcVar10 != ']') {
          return 0;
        }
        uVar12 = FUN_005ca361(~uVar12,uVar7,param_4);
        if (uVar12 == 0) {
          return 0;
        }
        if (pcVar10[1] == '\0') {
          return uVar12;
        }
        if (pcVar10[1] != '.') {
          return 0;
        }
        pcVar10 = pcVar10 + 2;
LAB_005d0a16:
        uVar7 = FUN_005d19ea(uVar12,pcVar10,param_4);
        return uVar7;
      }
    }
    local_1c = uVar12;
    uVar7 = *(uint *)(uVar12 + 0x34);
  }
  param_4 = 0;
  if (*(int *)(param_1 + 0x94) == 0) {
    return 0;
  }
  local_20 = 0;
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  param_2 = (undefined4 *)0x0;
  cVar1 = *param_3;
  pcVar10 = param_3;
  do {
    if ((((cVar1 == '.') || (cVar1 == '@')) || (cVar1 == '[')) || (cVar1 == ']')) goto LAB_005d0d90;
    pcVar10 = pcVar10 + 1;
    cVar1 = *pcVar10;
  } while (cVar1 != '\0');
  pcVar10 = param_3;
  do {
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  pcVar10 = pcVar10 + (1 - (int)(param_3 + 1));
  iVar2 = ((uint)(((uint)pcVar10 & 3) != 0) + ((uint)pcVar10 >> 2)) * 4;
  puVar5 = _malloc(*(int *)(param_1 + 0x88) * 4 + 4);
  local_c = puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    pvVar6 = _malloc(0x44);
    if (pvVar6 == (void *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = FUN_005d0177();
    }
    if (uVar7 == 0) goto LAB_005d0d9d;
    *(undefined4 *)(uVar7 + 4) = *(undefined4 *)(param_1 + 0x88);
    iVar13 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(uVar7 + 0x18) = 0xffffffff;
    *(undefined4 *)(uVar7 + 8) = 0;
    *(undefined4 *)(uVar7 + 0xc) = 0;
    *(int *)(uVar7 + 0x24) = iVar2 + 4 + iVar13;
    *(undefined4 *)(uVar7 + 0x20) = 4;
    piVar15 = *(int **)(param_1 + 0x90);
    iVar13 = piVar15[4];
    iVar4 = *piVar15;
    iVar14 = piVar15[1];
    param_4 = uVar7;
    if (-1 < iVar14) {
      if (iVar14 < 4) {
        if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 3)) {
          iVar4 = piVar15[6] * piVar15[5] * 4;
          *(undefined4 *)(uVar7 + 0x1c) = 4;
          *(int *)(uVar7 + 0x1c) = iVar4;
          if (iVar13 != 0) {
            iVar14 = iVar13 * iVar4;
            iVar4 = iVar4 * iVar13;
            *(int *)(uVar7 + 0x1c) = iVar14;
          }
          local_10 = iVar4 + *(int *)(param_1 + 0x28) + 0x20 + iVar2;
          param_2 = _malloc(*(int *)(param_1 + 0x28) + local_10);
          if (param_2 != (undefined4 *)0x0) {
            uVar12 = *(uint *)(param_1 + 0x28);
            puVar16 = *(undefined4 **)(param_1 + 0x2c);
            puVar18 = param_2;
            for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + 1;
              puVar18 = puVar18 + 1;
            }
            for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *(undefined1 *)puVar18 = *(undefined1 *)puVar16;
              puVar16 = (undefined4 *)((int)puVar16 + 1);
              puVar18 = (undefined4 *)((int)puVar18 + 1);
            }
            puVar16 = (undefined4 *)(*(int *)(param_1 + 0x28) + (int)param_2);
            for (uVar12 = local_10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar16 = 0;
              puVar16 = puVar16 + 1;
            }
            for (uVar12 = local_10 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *(undefined1 *)puVar16 = 0;
              puVar16 = (undefined4 *)((int)puVar16 + 1);
            }
            puVar16 = *(undefined4 **)(param_1 + 0x90);
            puVar18 = (undefined4 *)((int)param_2 + *(int *)(param_1 + 0x28) + iVar2 + 4);
            for (iVar13 = 7; iVar13 != 0; iVar13 = iVar13 + -1) {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + 1;
              puVar18 = puVar18 + 1;
            }
            *(int *)(uVar7 + 0x28) = *(int *)(uVar7 + 0x24) + 0x1c;
LAB_005d0cb4:
            local_8 = (int *)0x0;
            *(char **)((int)param_2 + *(int *)(param_1 + 0x28)) = pcVar10;
            pcVar9 = (char *)((int)param_2 + *(int *)(param_1 + 0x28) + 4);
            for (uVar12 = (uint)pcVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *(undefined4 *)pcVar9 = *(undefined4 *)param_3;
              param_3 = param_3 + 4;
              pcVar9 = pcVar9 + 4;
            }
            for (uVar12 = (uint)pcVar10 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *pcVar9 = *param_3;
              param_3 = param_3 + 1;
              pcVar9 = pcVar9 + 1;
            }
            *(undefined4 *)(*(int *)(uVar7 + 0x24) + 8 + (int)param_2) =
                 *(undefined4 *)(param_1 + 0x28);
            *(undefined4 *)(*(int *)(uVar7 + 0x24) + 0xc + (int)param_2) = 0;
            if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
              _free(*(void **)(param_1 + 0x2c));
              *(undefined4 *)(param_1 + 0x2c) = 0;
            }
            *(undefined4 **)(param_1 + 0x2c) = param_2;
            *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_10;
            param_2 = (undefined4 *)0x0;
            puVar16 = *(undefined4 **)(param_1 + 0x8c);
            puVar18 = puVar5;
            for (uVar12 = *(uint *)(param_1 + 0x88) & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1)
            {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + 1;
              puVar18 = puVar18 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined1 *)puVar18 = *(undefined1 *)puVar16;
              puVar16 = (undefined4 *)((int)puVar16 + 1);
              puVar18 = (undefined4 *)((int)puVar18 + 1);
            }
            puVar5[*(int *)(param_1 + 0x88)] = uVar7;
            if (*(void **)(param_1 + 0x8c) != (void *)0x0) {
              _free(*(void **)(param_1 + 0x8c));
              *(undefined4 *)(param_1 + 0x8c) = 0;
            }
            local_c = (undefined4 *)0x0;
            *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
            *(undefined4 **)(param_1 + 0x8c) = puVar5;
            if (local_1c == 0) {
              *puVar3 = uVar7;
            }
            else {
              *(uint *)(local_1c + 0x34) = uVar7;
            }
            *piVar8 = *piVar8 + 1;
            param_4 = 0;
            local_20 = ~uVar7;
          }
        }
      }
      else if ((iVar14 == 4) && (iVar13 == 0)) {
        local_10 = iVar2 + 0x1c;
        param_2 = _malloc(*(int *)(param_1 + 0x28) + local_10);
        if (param_2 != (undefined4 *)0x0) {
          iVar2 = *(int *)(param_1 + 0x20) + 1;
          local_8 = _malloc(iVar2 * 0x1c + 4);
          if (local_8 == (int *)0x0) {
            local_8 = (int *)0x0;
          }
          else {
            *local_8 = iVar2;
            local_8 = local_8 + 1;
            CallNTimes(local_8,0x1c,iVar2,FUN_005c8f5e);
          }
          if (local_8 != (int *)0x0) {
            uVar12 = *(uint *)(param_1 + 0x28);
            puVar16 = *(undefined4 **)(param_1 + 0x2c);
            puVar18 = param_2;
            for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + 1;
              puVar18 = puVar18 + 1;
            }
            for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *(undefined1 *)puVar18 = *(undefined1 *)puVar16;
              puVar16 = (undefined4 *)((int)puVar16 + 1);
              puVar18 = (undefined4 *)((int)puVar18 + 1);
            }
            puVar16 = (undefined4 *)(*(int *)(param_1 + 0x28) + (int)param_2);
            for (uVar12 = local_10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar16 = 0;
              puVar16 = puVar16 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined1 *)puVar16 = 0;
              puVar16 = (undefined4 *)((int)puVar16 + 1);
            }
            piVar15 = local_8 + *(int *)(param_1 + 0x20) * 7;
            for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
              *piVar15 = 0;
              piVar15 = piVar15 + 1;
            }
            local_8[*(int *)(param_1 + 0x20) * 7] = iVar4;
            local_8[*(int *)(param_1 + 0x20) * 7 + 2] = *(int *)(uVar7 + 4);
            pvVar6 = _malloc(0xac);
            if (pvVar6 == (void *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_005cd207();
            }
            local_8[*(int *)(param_1 + 0x20) * 7 + 6] = iVar2;
            if (iVar2 != 0) {
              piVar15 = *(int **)(param_1 + 0x24);
              piVar17 = local_8;
              for (uVar12 = (uint)(*(int *)(param_1 + 0x20) * 0x1c) >> 2; uVar12 != 0;
                  uVar12 = uVar12 - 1) {
                *piVar17 = *piVar15;
                piVar15 = piVar15 + 1;
                piVar17 = piVar17 + 1;
              }
              for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *(char *)piVar17 = (char)*piVar15;
                piVar15 = (int *)((int)piVar15 + 1);
                piVar17 = (int *)((int)piVar17 + 1);
              }
              *(int *)(uVar7 + 0x28) = *(int *)(uVar7 + 0x24) + 0x14;
              *(undefined4 *)(uVar7 + 0x1c) = 4;
              puVar16 = *(undefined4 **)(param_1 + 0x90);
              puVar18 = (undefined4 *)(*(int *)(uVar7 + 0x24) + (int)param_2);
              for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar18 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar18 = puVar18 + 1;
              }
              *(undefined4 *)((int)param_2 + *(int *)(uVar7 + 0x28)) =
                   *(undefined4 *)(param_1 + 0x20);
              puVar16 = *(undefined4 **)(param_1 + 0x24);
              for (uVar12 = (uint)(*(int *)(param_1 + 0x20) * 0x1c) >> 2; uVar12 != 0;
                  uVar12 = uVar12 - 1) {
                *puVar16 = 0;
                puVar16 = puVar16 + 1;
              }
              for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *(undefined1 *)puVar16 = 0;
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              }
              if (*(int *)(param_1 + 0x24) != 0) {
                FUN_005cb189(3);
                *(undefined4 *)(param_1 + 0x24) = 0;
              }
              *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
              *(int **)(param_1 + 0x24) = local_8;
              goto LAB_005d0cb4;
            }
          }
        }
      }
    }
  }
LAB_005d0d90:
  if (param_4 != 0) {
    FUN_005d0387(1);
  }
LAB_005d0d9d:
  if (local_c != (undefined4 *)0x0) {
    _free(local_c);
  }
  if (local_8 != (int *)0x0) {
    FUN_005cb189(3);
  }
  if (param_2 != (undefined4 *)0x0) {
    _free(param_2);
    return local_20;
  }
  return local_20;
}


// ==== 0x5d0dd1 FUN_005d0dd1

int FUN_005d0dd1(int *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int *local_28;
  int *local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_c;
  int local_8;
  
  if (param_3 == (int *)0x0) {
    param_2 = -0x7789f794;
  }
  else {
    piVar13 = *(int **)((int)param_1 + 0x38);
    uVar17 = *(undefined4 *)((int)param_1 + 0xc);
    uVar16 = 0;
    uVar15 = 0;
    uVar14 = 0;
    piVar4 = piVar13;
    uVar1 = (**(code **)(*piVar13 + 0x10))(piVar13,0,0,0,uVar17,param_3,0);
    uVar2 = (**(code **)(*piVar13 + 0xc))(piVar13,uVar1);
    param_2 = FUN_005afb2f(param_2,uVar2,piVar13,uVar1,piVar4,uVar14,uVar15,uVar16,uVar17);
    if (-1 < param_2) {
      piVar13 = (int *)*param_3;
      *param_3 = 0;
      local_c = 0;
      if (*(int *)((int)param_1 + 0x10) != 0) {
        local_8 = 0;
        do {
          iVar12 = *(int *)((int)param_1 + 0x14) + local_8;
          iVar3 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar12 + 4) * 4);
          iVar11 = piVar13[5] + local_8;
          if (*(int *)(iVar3 + 0x38) == 0) {
            iVar7 = *(int *)((int)param_1 + 0x2c);
            iVar5 = *(int *)((int)param_1 + 0x2c);
          }
          else {
            iVar7 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            iVar5 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
          }
          iVar6 = *(int *)(iVar3 + 0x24) + *(int *)(iVar12 + 8);
          if (*(int *)(iVar7 + *(int *)(iVar6 + 8 + iVar5)) == 0) {
            local_1c = 0;
          }
          else {
            if (*(int *)(iVar3 + 0x38) == 0) {
              local_1c = *(int *)((int)param_1 + 0x2c);
              iVar7 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              local_1c = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
              iVar7 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            local_1c = *(int *)(iVar6 + 8 + iVar7) + 4 + local_1c;
          }
          iVar7 = iVar11;
          if ((*(uint *)(iVar3 + 0x20) & 2) != 0) goto LAB_005d1009;
          if (*(int *)(iVar3 + 0x38) == 0) {
            iVar7 = *(int *)((int)param_1 + 0x2c);
          }
          else {
            iVar7 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
          }
          iVar5 = *(int *)(piVar13[0x23] + *(int *)(iVar11 + 4) * 4);
          if (*(int *)(iVar5 + 0x38) == 0) {
            iVar8 = piVar13[0xb];
          }
          else {
            iVar8 = *(int *)(piVar13[3] + 8);
          }
          if (*(int *)(iVar3 + 0x38) == 0) {
            iVar9 = *(int *)((int)param_1 + 0x2c);
          }
          else {
            iVar9 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
          }
          param_2 = FUN_005d0298(iVar6 + iVar9,
                                 *(int *)(iVar5 + 0x28) + *(int *)(iVar11 + 0xc) + iVar8,
                                 *(int *)(iVar3 + 0x28) + *(int *)(iVar12 + 0xc) + iVar7,
                                 *(undefined4 *)(iVar11 + 0x38),*(undefined4 *)(iVar12 + 0x38),
                                 param_1);
          if (param_2 < 0) goto LAB_005d149a;
          param_2 = FUN_005d02d7(iVar11);
          while( true ) {
            iVar7 = iVar11;
            if (param_2 < 0) goto LAB_005d149a;
LAB_005d1009:
            iVar12 = *(int *)(iVar12 + 0x34);
            iVar11 = *(int *)(iVar7 + 0x34);
            if (iVar11 == 0) break;
            iVar3 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar12 + 4) * 4);
            if (*(int *)(iVar3 + 0x38) == 0) {
              iVar7 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar7 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            iVar5 = *(int *)(piVar13[0x23] + *(int *)(iVar11 + 4) * 4);
            if (*(int *)(iVar5 + 0x38) == 0) {
              iVar6 = piVar13[0xb];
            }
            else {
              iVar6 = *(int *)(piVar13[3] + 8);
            }
            if (*(int *)(iVar3 + 0x38) == 0) {
              iVar8 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar8 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            param_2 = FUN_005d0298(*(int *)(iVar3 + 0x24) + *(int *)(iVar12 + 8) + iVar8,
                                   *(int *)(iVar5 + 0x28) + *(int *)(iVar11 + 0xc) + iVar6,
                                   *(int *)(iVar3 + 0x28) + *(int *)(iVar12 + 0xc) + iVar7,
                                   *(undefined4 *)(iVar11 + 0x38),*(undefined4 *)(iVar12 + 0x38),
                                   param_1);
          }
          for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
            param_2 = FUN_005cba05(local_1c,iVar12,piVar13);
            if (param_2 < 0) goto LAB_005d149a;
            iVar3 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar12 + 4) * 4);
            iVar7 = *(int *)(iVar7 + 0x34);
            if (*(int *)(iVar3 + 0x38) == 0) {
              iVar11 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar11 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            iVar5 = *(int *)(piVar13[0x23] + *(int *)(iVar7 + 4) * 4);
            if (*(int *)(iVar5 + 0x38) == 0) {
              iVar6 = piVar13[0xb];
            }
            else {
              iVar6 = *(int *)(piVar13[3] + 8);
            }
            if (*(int *)(iVar3 + 0x38) == 0) {
              iVar8 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar8 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            param_2 = FUN_005d0298(*(int *)(iVar3 + 0x24) + *(int *)(iVar12 + 8) + iVar8,
                                   *(int *)(iVar5 + 0x28) + *(int *)(iVar7 + 0xc) + iVar6,
                                   *(int *)(iVar3 + 0x28) + *(int *)(iVar12 + 0xc) + iVar11,
                                   *(undefined4 *)(iVar7 + 0x38),*(undefined4 *)(iVar12 + 0x38),
                                   param_1);
            if (param_2 < 0) goto LAB_005d149a;
          }
          local_c = local_c + 1;
          local_8 = local_8 + 0x44;
        } while (local_c < *(uint *)((int)param_1 + 0x10));
      }
      local_18 = 0;
      if (*(int *)((int)param_1 + 0x18) != 0) {
        local_c = 0;
        do {
          iVar3 = *(int *)((int)param_1 + 0x1c) + local_c;
          iVar11 = piVar13[7] + local_c;
          local_20 = (int *)(*(int *)(iVar3 + 0x20) + *(int *)((int)param_1 + 0x2c));
          if (*local_20 == 0) {
            local_20 = (int *)0x0;
          }
          else {
            local_20 = local_20 + 1;
          }
          piVar4 = (int *)(iVar3 + 0x28);
          iVar7 = *piVar4;
          iVar12 = *(int *)(iVar11 + 0x28);
          while (iVar12 != 0) {
            iVar5 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar7 + 4) * 4);
            if (*(int *)(iVar5 + 0x38) == 0) {
              iVar6 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar6 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            iVar8 = *(int *)(piVar13[0x23] + *(int *)(iVar12 + 4) * 4);
            if (*(int *)(iVar8 + 0x38) == 0) {
              iVar9 = piVar13[0xb];
            }
            else {
              iVar9 = *(int *)(piVar13[3] + 8);
            }
            if (*(int *)(iVar5 + 0x38) == 0) {
              iVar10 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar10 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            param_2 = FUN_005d0298(*(int *)(iVar5 + 0x24) + *(int *)(iVar7 + 8) + iVar10,
                                   *(int *)(iVar8 + 0x28) + *(int *)(iVar12 + 0xc) + iVar9,
                                   *(int *)(iVar5 + 0x28) + *(int *)(iVar7 + 0xc) + iVar6,
                                   *(undefined4 *)(iVar12 + 0x38),*(undefined4 *)(iVar7 + 0x38),
                                   param_1);
            if (param_2 < 0) goto LAB_005d149a;
            iVar7 = *(int *)(iVar7 + 0x34);
            piVar4 = (int *)(iVar12 + 0x34);
            iVar12 = *piVar4;
          }
          iVar12 = *piVar4;
          for (; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x34)) {
            param_2 = FUN_005cba05(local_20,iVar7,piVar13);
            if (param_2 < 0) goto LAB_005d149a;
            iVar5 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar7 + 4) * 4);
            iVar12 = *(int *)(iVar12 + 0x34);
            if (*(int *)(iVar5 + 0x38) == 0) {
              iVar6 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar6 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            iVar8 = *(int *)(piVar13[0x23] + *(int *)(iVar12 + 4) * 4);
            if (*(int *)(iVar8 + 0x38) == 0) {
              iVar9 = piVar13[0xb];
            }
            else {
              iVar9 = *(int *)(piVar13[3] + 8);
            }
            if (*(int *)(iVar5 + 0x38) == 0) {
              iVar10 = *(int *)((int)param_1 + 0x2c);
            }
            else {
              iVar10 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
            }
            param_2 = FUN_005d0298(*(int *)(iVar5 + 0x24) + *(int *)(iVar7 + 8) + iVar10,
                                   *(int *)(iVar8 + 0x28) + *(int *)(iVar12 + 0xc) + iVar9,
                                   *(int *)(iVar5 + 0x28) + *(int *)(iVar7 + 0xc) + iVar6,
                                   *(undefined4 *)(iVar12 + 0x38),*(undefined4 *)(iVar7 + 0x38),
                                   param_1);
            if (param_2 < 0) goto LAB_005d149a;
          }
          if (*(int *)(iVar11 + 0x2c) != 0) {
            local_14 = 0;
            local_8 = 0;
            do {
              local_28 = (int *)0x0;
              iVar12 = *(int *)(iVar3 + 0x30) + local_8;
              piVar4 = (int *)(*(int *)(iVar12 + 0x20) + *(int *)((int)param_1 + 0x2c));
              if (*piVar4 != 0) {
                local_28 = piVar4 + 1;
              }
              piVar4 = (int *)(iVar12 + 0x30);
              iVar7 = *piVar4;
              iVar12 = *(int *)(*(int *)(iVar11 + 0x30) + local_8 + 0x30);
              while (iVar12 != 0) {
                iVar5 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar7 + 4) * 4);
                if (*(int *)(iVar5 + 0x38) == 0) {
                  iVar6 = *(int *)((int)param_1 + 0x2c);
                }
                else {
                  iVar6 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
                }
                iVar8 = *(int *)(piVar13[0x23] + *(int *)(iVar12 + 4) * 4);
                if (*(int *)(iVar8 + 0x38) == 0) {
                  iVar9 = piVar13[0xb];
                }
                else {
                  iVar9 = *(int *)(piVar13[3] + 8);
                }
                if (*(int *)(iVar5 + 0x38) == 0) {
                  iVar10 = *(int *)((int)param_1 + 0x2c);
                }
                else {
                  iVar10 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
                }
                param_2 = FUN_005d0298(*(int *)(iVar5 + 0x24) + *(int *)(iVar7 + 8) + iVar10,
                                       *(int *)(iVar8 + 0x28) + *(int *)(iVar12 + 0xc) + iVar9,
                                       *(int *)(iVar5 + 0x28) + *(int *)(iVar7 + 0xc) + iVar6,
                                       *(undefined4 *)(iVar12 + 0x38),*(undefined4 *)(iVar7 + 0x38),
                                       param_1);
                if (param_2 < 0) goto LAB_005d149a;
                iVar7 = *(int *)(iVar7 + 0x34);
                piVar4 = (int *)(iVar12 + 0x34);
                iVar12 = *piVar4;
              }
              iVar12 = *piVar4;
              for (; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x34)) {
                param_2 = FUN_005cba05(local_28,iVar7,piVar13);
                if (param_2 < 0) goto LAB_005d149a;
                iVar5 = *(int *)(*(int *)((int)param_1 + 0x8c) + *(int *)(iVar7 + 4) * 4);
                iVar12 = *(int *)(iVar12 + 0x34);
                if (*(int *)(iVar5 + 0x38) == 0) {
                  iVar6 = *(int *)((int)param_1 + 0x2c);
                }
                else {
                  iVar6 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
                }
                iVar8 = *(int *)(piVar13[0x23] + *(int *)(iVar12 + 4) * 4);
                if (*(int *)(iVar8 + 0x38) == 0) {
                  iVar9 = piVar13[0xb];
                }
                else {
                  iVar9 = *(int *)(piVar13[3] + 8);
                }
                if (*(int *)(iVar5 + 0x38) == 0) {
                  iVar10 = *(int *)((int)param_1 + 0x2c);
                }
                else {
                  iVar10 = *(int *)(*(int *)((int)param_1 + 0xc) + 8);
                }
                param_2 = FUN_005d0298(*(int *)(iVar5 + 0x24) + *(int *)(iVar7 + 8) + iVar10,
                                       *(int *)(iVar8 + 0x28) + *(int *)(iVar12 + 0xc) + iVar9,
                                       *(int *)(iVar5 + 0x28) + *(int *)(iVar7 + 0xc) + iVar6,
                                       *(undefined4 *)(iVar12 + 0x38),*(undefined4 *)(iVar7 + 0x38),
                                       param_1);
                if (param_2 < 0) goto LAB_005d149a;
              }
              local_14 = local_14 + 1;
              local_8 = local_8 + 0x3c;
            } while (local_14 < *(uint *)(iVar11 + 0x2c));
          }
          local_18 = local_18 + 1;
          local_c = local_c + 0xac;
        } while (local_18 < *(uint *)((int)param_1 + 0x18));
      }
      param_1 = (int *)0x0;
      *param_3 = (int)piVar13;
      piVar13 = param_1;
LAB_005d149a:
      param_1 = piVar13;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
  }
  return param_2;
}


