// ==== 0x501130 FUN_00501130

uint FUN_00501130(int *param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar3 = param_1[1];
  piVar5 = (int *)(iVar3 + 8);
  iVar1 = *piVar5;
  do {
    if (iVar1 == 0x5262694c) {
LAB_00501163:
      uVar2 = (ulonglong)(uint)piVar5[1] / 0xc;
      iVar3 = (int)uVar2;
      if ((uint)piVar5[1] % 0xc != 0) {
        return (uint)(uint3)(uVar2 >> 8) << 8;
      }
      piVar5 = piVar5 + 2;
      FUN_00500570(*param_1,iVar3);
      piVar4 = *(int **)(*param_1 + 0x7c);
      if (iVar3 != 0) {
        piVar4 = piVar4 + 2;
        do {
          piVar4[-2] = *piVar5;
          piVar4[-1] = piVar5[1];
          *piVar4 = piVar5[2];
          piVar5 = piVar5 + 3;
          piVar4 = piVar4 + 3;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      return CONCAT31((int3)((uint)piVar4 >> 8),1);
    }
    if (piVar5 == (int *)(*(int *)(iVar3 + 4) + 8 + iVar3)) {
      if (*piVar5 != 0x5262694c) {
        return (uint)(*(int *)(*param_1 + 0x6c) == 0);
      }
      goto LAB_00501163;
    }
    piVar5 = (int *)((int)piVar5 + piVar5[1] + 8);
    iVar1 = *piVar5;
  } while( true );
}


// ==== 0x5011e0 FEPackage::ReadResourceRequests

/* [canon] assets med (ghidra-canon) docs/re/runtime.md */

uint FEPackage__ReadResourceRequests(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  
  puVar3 = param_1;
  uVar6 = param_1[1];
  puVar11 = (uint *)(uVar6 + 8);
  puVar12 = (uint *)(*(int *)(uVar6 + 4) + 8 + uVar6);
  uVar8 = *puVar11;
  do {
    if (uVar8 == 0xcc736552) {
LAB_00501220:
      if (puVar11[2] == 0x6d4e7352) {
        uVar6 = puVar11[3];
        piVar10 = (int *)((int)puVar11 + uVar6 + 0x10);
        if (*piVar10 != 0x71527352) {
          return uVar6 & 0xffffff00;
        }
        iVar9 = piVar10[2];
        piVar10 = piVar10 + 3;
        *(int *)(*param_1 + 0x58) = iVar9;
        if (iVar9 != 0) {
          pvVar4 = _malloc(iVar9 * 0x18);
          *(void **)(*param_1 + 0x5c) = pvVar4;
          pvVar4 = _malloc(puVar11[3]);
          *(void **)(*param_1 + 0x8c) = pvVar4;
          if (iVar9 != 0) {
            iVar5 = 0;
            param_1 = (uint *)iVar9;
            do {
              *(int *)(iVar5 + *(int *)(*puVar3 + 0x5c)) = *piVar10;
              *(int *)(*(int *)(*puVar3 + 0x5c) + 4 + iVar5) = piVar10[1];
              *(int *)(*(int *)(*puVar3 + 0x5c) + 8 + iVar5) = piVar10[2];
              *(int *)(*(int *)(*puVar3 + 0x5c) + 0xc + iVar5) = piVar10[3];
              *(int *)(*(int *)(*puVar3 + 0x5c) + 0x10 + iVar5) = piVar10[4];
              *(int *)(*(int *)(*puVar3 + 0x5c) + 0x14 + iVar5) = piVar10[5];
              piVar10 = piVar10 + 6;
              iVar5 = iVar5 + 0x18;
              param_1 = (uint *)((int)param_1 + -1);
            } while (param_1 != (uint *)0x0);
          }
          uVar8 = puVar11[3];
          uVar6 = *puVar3;
          puVar11 = puVar11 + 4;
          puVar12 = *(uint **)(uVar6 + 0x8c);
          for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(char *)puVar12 = (char)*puVar11;
            puVar11 = (uint *)((int)puVar11 + 1);
            puVar12 = (uint *)((int)puVar12 + 1);
          }
          if (iVar9 != 0) {
            iVar5 = 0;
            do {
              iVar2 = *(int *)(*puVar3 + 0x5c);
              uVar6 = *(uint *)(*puVar3 + 0x8c);
              piVar10 = (int *)(iVar2 + 4 + iVar5);
              piVar1 = (int *)(iVar2 + 4 + iVar5);
              iVar5 = iVar5 + 0x18;
              iVar9 = iVar9 + -1;
              *piVar1 = *piVar10 + uVar6;
            } while (iVar9 != 0);
          }
        }
        return CONCAT31((int3)(uVar6 >> 8),1);
      }
LAB_00501229:
      return uVar6 & 0xffffff00;
    }
    if (puVar11 == puVar12) {
      if (*puVar11 != 0xcc736552) goto LAB_00501229;
      goto LAB_00501220;
    }
    uVar6 = *(uint *)((int)puVar11 + puVar11[1] + 8);
    puVar11 = (uint *)((int)puVar11 + puVar11[1] + 8);
    uVar8 = uVar6;
  } while( true );
}


// ==== 0x501340 FUN_00501340

undefined4 __fastcall FUN_00501340(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  piVar2 = (int *)(iVar1 + 8);
  if (*piVar2 != 0x52676b50) {
    while (piVar2 != (int *)(*(int *)(iVar1 + 4) + 8 + iVar1)) {
      piVar2 = (int *)((int)piVar2 + piVar2[1] + 8);
      if (*piVar2 == 0x52676b50) {
        FUN_005024b0(param_2,piVar2 + 2,1);
        return 1;
      }
    }
    if (*piVar2 != 0x52676b50) {
      return 1;
    }
  }
  FUN_005024b0(param_2,piVar2 + 2,1);
  return 1;
}


// ==== 0x5013a0 FUN_005013a0

uint FUN_005013a0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  byte bVar8;
  int *piVar9;
  
  iVar4 = param_1[1];
  piVar6 = (int *)(iVar4 + 8);
  iVar5 = *(int *)(iVar4 + 8);
  while (iVar5 != -0x33959db1) {
    if (piVar6 == (int *)(*(int *)(iVar4 + 4) + 8 + iVar4)) {
      if (*piVar6 != -0x33959db1) {
        return (uint)piVar6 & 0xffffff00;
      }
      break;
    }
    piVar6 = (int *)((int)piVar6 + piVar6[1] + 8);
    iVar5 = *piVar6;
  }
  piVar2 = piVar6 + 2;
  piVar1 = (int *)(piVar6[1] + 8 + (int)piVar6);
  if ((piVar2 == (int *)0x0) || (piVar1 == (int *)0x0)) {
LAB_005015fd:
    return (uint)piVar6 & 0xffffff00;
  }
  piVar6 = (int *)*piVar2;
  while (piVar6 != (int *)0xea624f46) {
    if (piVar1 <= piVar2) goto LAB_005015f3;
    if (piVar6 == (int *)0x6e747542) {
      iVar4 = *param_1;
      iVar5 = piVar2[2];
      param_1[0x12] = iVar5;
      _free(*(void **)(iVar4 + 0x84));
      *(undefined4 *)(iVar4 + 0x84) = 0;
      if (iVar5 != 0) {
        pvVar7 = _malloc(iVar5 * 4);
        *(undefined4 *)(iVar4 + 0x84) = pvVar7;
      }
      *(int *)(iVar4 + 0x88) = iVar5;
    }
    piVar2 = (int *)((int)piVar2 + piVar2[1] + 8);
    piVar6 = (int *)*piVar2;
  }
  while (piVar2 < piVar1) {
    piVar9 = piVar2 + 2;
    piVar3 = (int *)((int)piVar2 + piVar2[1] + 8);
    param_1[3] = 0;
    param_1[5] = 0;
    if (piVar9 < piVar3) {
      do {
        iVar4 = *piVar9;
        if (iVar4 == 0x446a624f) {
          piVar6 = (int *)FUN_005017d0(param_1,piVar9 + 2,piVar9[1]);
          if ((char)piVar6 == '\0') goto LAB_005015fd;
        }
        else if (iVar4 == 0x5267734d) {
          FUN_005024b0(param_1,piVar9 + 2,0);
        }
        else if (iVar4 == 0x70726353) {
          FUN_00501ea0(param_1,piVar9 + 2,piVar9[1]);
        }
        piVar9 = (int *)((int)piVar9 + piVar9[1] + 8);
      } while (piVar9 < piVar3);
      if (param_1[3] != 0) {
        iVar4 = *(int *)(param_1[3] + 0x18);
        if (iVar4 == 4) {
          FEListBox__RecalculateCummulative();
        }
        else if (iVar4 == 6) {
          FEGrid_ForEachCellInRect();
        }
        for (iVar4 = *(int *)(param_1[3] + 0x4c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
          if (*(int *)(iVar4 + 0x18) != 0) {
            for (iVar5 = *(int *)(param_1[3] + 0x4c);
                (iVar5 != 0 && (*(int *)(iVar5 + 0x30) != *(int *)(iVar4 + 0x18)));
                iVar5 = *(int *)(iVar5 + 4)) {
            }
            *(int *)(iVar4 + 0x18) = iVar5;
          }
        }
        iVar4 = param_1[3];
        for (iVar5 = *(int *)(iVar4 + 0x4c); (iVar5 != 0 && (*(int *)(iVar5 + 0x30) != 0x1744b3));
            iVar5 = *(int *)(iVar5 + 4)) {
        }
        *(int *)(iVar4 + 0x54) = iVar5;
        if (iVar5 != 0) {
          FUN_004ff030(iVar4);
        }
        *(undefined4 *)(iVar5 + 0x10) = 0;
        if (((char)param_1[2] == '\0') && (bVar8 = 0, *(int *)(iVar5 + 0x1c) != 0)) {
          do {
            FUN_004fbf10();
            bVar8 = bVar8 + 1;
          } while ((uint)bVar8 < *(uint *)(iVar5 + 0x1c));
        }
        if (param_1[5] == 0) {
          FEPackage__AddObject();
        }
        else {
          FEGroup__AddChild();
        }
      }
    }
    piVar2 = (int *)((int)piVar2 + piVar2[1] + 8);
    piVar6 = piVar2;
  }
LAB_005015f3:
  return CONCAT31((int3)((uint)piVar6 >> 8),1);
}


// ==== 0x501610 FUN_00501610

int FUN_00501610(int param_1)

{
  int in_EAX;
  void *pvVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  switch(param_1) {
  case 0:
    return 0;
  case 1:
    pvVar1 = _malloc(0x5c);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500af0();
      goto LAB_00501736;
    }
    break;
  case 2:
    pvVar1 = _malloc(0x74);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500940();
      goto LAB_00501736;
    }
    break;
  default:
    pvVar1 = _malloc(0x58);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FEObject__FEObject();
      goto LAB_00501736;
    }
    break;
  case 4:
    pvVar1 = _malloc(0xa8);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_004fd2c0();
      goto LAB_00501736;
    }
    break;
  case 5:
    pvVar1 = _malloc(0x68);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500910();
      goto LAB_00501736;
    }
    break;
  case 6:
    pvVar1 = _malloc(0xc4);
    if (pvVar1 == (void *)0x0) {
      uRam00000058 = *(undefined4 *)(in_EAX + 0x38);
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004fa4a0();
      *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(in_EAX + 0x38);
    }
    goto LAB_00501736;
  case 7:
    pvVar1 = _malloc(0x5c);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500a30();
      goto LAB_00501736;
    }
    break;
  case 9:
    pvVar1 = _malloc(0x5c);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500b90();
      goto LAB_00501736;
    }
    break;
  case 10:
    pvVar1 = _malloc(0x5c);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500c20();
      goto LAB_00501736;
    }
    break;
  case 0xb:
    pvVar1 = _malloc(0x58);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00500cd0();
      goto LAB_00501736;
    }
  }
  iVar2 = 0;
LAB_00501736:
  *(int *)(iVar2 + 0x18) = param_1;
  uVar3 = 0;
  if (*(uint *)(in_EAX + 0x30) != 0) {
    piVar5 = *(int **)(in_EAX + 0x34);
    do {
      if (*piVar5 == param_1) {
        iVar6 = (*(int **)(in_EAX + 0x34))[uVar3 * 2 + 1];
        goto LAB_0050175e;
      }
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 2;
    } while (uVar3 < *(uint *)(in_EAX + 0x30));
  }
  iVar6 = 0;
LAB_0050175e:
  FUN_005033d0(&DAT_007460c8);
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  uVar4 = FUN_00503330(&DAT_007460c8);
  *(undefined4 *)(iVar2 + 0x2c) = uVar4;
  *(int *)(iVar2 + 0x30) = iVar6;
  return iVar2;
}


// ==== 0x5017d0 FUN_005017d0

uint FUN_005017d0(int *param_1,ushort *param_2,int param_3)

{
  int *piVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  ushort *puVar7;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685feb;
  ExceptionList = &local_c;
  puVar3 = (ushort *)(param_3 + (int)param_2);
  *(undefined1 *)(param_1 + 6) = 0;
  puVar7 = puVar3;
  do {
    if (puVar3 <= param_2) {
      ExceptionList = local_c;
      return CONCAT31((int3)((uint)puVar7 >> 8),1);
    }
    uVar2 = *param_2;
    if (uVar2 < 0x5050) {
      if (uVar2 == 0x504f) {
        *(undefined4 *)(param_1[3] + 0xc) = *(undefined4 *)(param_2 + 2);
        *(undefined4 *)(param_1[3] + 0x10) = *(undefined4 *)(param_2 + 4);
        *(undefined4 *)(param_1[3] + 0x1c) = *(undefined4 *)(param_2 + 6);
        *(short *)(param_1[3] + 0x22) = (short)*(undefined4 *)(param_2 + 8);
        if ((*(uint *)(param_1[3] + 0x1c) & 0x100000) != 0) {
          piVar1 = param_1 + 7;
          uVar4 = FUN_00502840(param_1,piVar1,param_1 + 8);
          if ((char)uVar4 == '\0') {
            if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
              uVar4 = (*(code *)**(undefined4 **)param_1[3])(1);
            }
            param_1[3] = 0;
            ExceptionList = local_c;
            return uVar4 & 0xffffff00;
          }
          *(undefined1 *)(param_1 + 6) = 1;
          *(uint *)(param_1[3] + 0x1c) = *(uint *)(param_1[3] + 0x1c) | *(uint *)(*piVar1 + 0x1c);
          if (*(short *)(param_1[3] + 0x22) == -1) {
            *(undefined4 *)(param_1[3] + 0x24) = *(undefined4 *)(*piVar1 + 0x24);
            *(undefined4 *)(param_1[3] + 0x28) = *(undefined4 *)(*piVar1 + 0x28);
          }
          if (((int *)*piVar1)[6] == 5) {
            pvVar6 = _malloc(0x68);
            local_4 = 0;
            if (pvVar6 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_004fbd00(pvVar6,0,1);
            }
            local_4 = 0xffffffff;
          }
          else {
            iVar5 = (**(code **)(*(int *)*piVar1 + 4))(1);
          }
          FEObject__SetName();
          *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(param_1[3] + 0xc);
          *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(param_1[3] + 0x10);
          *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(param_1[3] + 0x1c);
          *(undefined2 *)(iVar5 + 0x22) = *(undefined2 *)(param_1[3] + 0x22);
          *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(param_1[3] + 0x24);
          *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(param_1[3] + 0x28);
          if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)param_1[3])(1);
          }
          param_1[3] = iVar5;
          for (iVar5 = *(int *)(iVar5 + 0x4c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
            if (*(int *)(iVar5 + 0x18) != 0) {
              *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(*(int *)(iVar5 + 0x18) + 0x30);
            }
          }
        }
        if ((*(uint *)(param_1[3] + 0x1c) & 0x10000000) != 0) {
          *(int *)(*(int *)(*param_1 + 0x84) + param_1[0x13] * 4) = param_1[3];
          param_1[0x13] = param_1[0x13] + 1;
        }
      }
      else if (uVar2 == 0x4150) {
        if ((param_1[4] == 0) || (*(int *)(param_1[4] + 0xc) != *(int *)(param_2 + 2))) {
          iVar5 = FUN_004ffbe0();
          param_1[4] = iVar5;
        }
        param_1[5] = param_1[4];
      }
      else {
        if (uVar2 != 0x4153) goto LAB_005019e7;
        uVar2 = param_2[1];
        uVar4 = 0;
        puVar7 = param_2;
        if (uVar2 >> 2 != 0) {
          do {
            *(undefined4 *)(*(int *)(param_1[3] + 0x2c) + uVar4 * 4) = *(undefined4 *)(puVar7 + 2);
            uVar4 = uVar4 + 1;
            puVar7 = puVar7 + 2;
          } while (uVar4 < uVar2 >> 2);
        }
      }
    }
    else if (uVar2 == 0x6e4f) {
      if (*(char *)((int)param_1 + 9) != '\0') {
        FEObject__SetName();
      }
    }
    else if (uVar2 == 0x744f) {
      iVar5 = FUN_00501610(*(undefined4 *)(param_2 + 2));
      param_1[3] = iVar5;
    }
    else {
LAB_005019e7:
      iVar5 = param_1[3];
      if (iVar5 != 0) {
        switch(*(undefined4 *)(iVar5 + 0x18)) {
        case 1:
        case 9:
        case 10:
          if (uVar2 == 0x6649) {
            *(undefined4 *)(iVar5 + 0x58) = *(undefined4 *)(param_2 + 2);
          }
          break;
        case 2:
          FUN_00501ac0();
          break;
        case 4:
          FUN_00501b80(param_1);
          break;
        case 6:
          FUN_00501da0();
        }
      }
    }
    puVar7 = (ushort *)(uint)param_2[1];
    param_2 = (ushort *)((int)(param_2 + 2) + (int)puVar7);
  } while( true );
}


// ==== 0x501ac0 FUN_00501ac0

void __fastcall FUN_00501ac0(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_EAX;
  bool bVar5;
  
  puVar4 = DAT_00735710;
  uVar1 = *param_2;
  iVar2 = *(int *)(in_EAX + 0xc);
  if (uVar1 < 0x6a54) {
    if (uVar1 == 0x6a53) {
      *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(param_2 + 2);
      return;
    }
    if (uVar1 == 0x4853) {
      uVar3 = *(undefined4 *)(param_2 + 2);
      bVar5 = DAT_00735710 != (undefined4 *)0x0;
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
      *(undefined4 *)(iVar2 + 0x5c) = uVar3;
      if (bVar5) {
        (**(code **)*puVar4)(iVar2);
        return;
      }
    }
    else if (uVar1 == 0x4c53) {
      if (*(char *)(in_EAX + 9) != '\0') {
        FUN_00514410();
        return;
      }
    }
    else if (uVar1 == 0x6253) {
      WString_Grow();
      return;
    }
  }
  else if (uVar1 == 0x6c53) {
    *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(param_2 + 2);
  }
  else {
    if (uVar1 == 0x7453) {
      WString_Assign();
      return;
    }
    if (uVar1 == 0x7753) {
      *(undefined4 *)(iVar2 + 0x70) = *(undefined4 *)(param_2 + 2);
      return;
    }
  }
  return;
}


// ==== 0x501b80 FUN_00501b80

void FUN_00501b80(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  ushort *in_EAX;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0xc);
  uVar4 = *in_EAX;
  if (uVar4 < 0x724d) {
    if (uVar4 == 0x724c) {
      iVar6 = *(int *)(param_1 + 0x28) + 1;
      *(int *)(param_1 + 0x28) = iVar6;
      puVar2 = (undefined4 *)(*(int *)(iVar5 + 0x78) + iVar6 * 0xc);
      *puVar2 = *(undefined4 *)(in_EAX + 2);
      puVar2[2] = *(undefined4 *)(in_EAX + 4);
      return;
    }
    if (uVar4 < 0x644d) {
      if (uVar4 == 0x644c) {
        FUN_004fd3d0(iVar5,*(undefined4 *)(in_EAX + 2));
        FUN_004fd5e0(iVar5,*(undefined4 *)(in_EAX + 4));
        *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
        FEListBox__SetCurrentColumn();
        FEListBox__SetCurrentRow();
        return;
      }
      if (uVar4 == 0x5443) {
        FEListBox__SetCellType();
        return;
      }
      if (uVar4 == 0x6343) {
        piVar1 = (int *)(param_1 + 0x2c);
        *piVar1 = *piVar1 + 1;
        if (*piVar1 != 0) {
          FEListBox__IncrementCellByColumn();
        }
        FEColor__FEColor(*(undefined4 *)(in_EAX + 2));
        FUN_00500870();
        return;
      }
      if (uVar4 == 0x634c) {
        iVar6 = *(int *)(param_1 + 0x24) + 1;
        *(int *)(param_1 + 0x24) = iVar6;
        puVar2 = (undefined4 *)(*(int *)(iVar5 + 0x74) + iVar6 * 0xc);
        *puVar2 = *(undefined4 *)(in_EAX + 2);
        puVar2[2] = *(undefined4 *)(in_EAX + 4);
        return;
      }
    }
    else {
      if (uVar4 == 0x6943) {
        FEListBox__SetCellImageUV();
        return;
      }
      if (uVar4 == 0x7243) {
        FEListBox__SetCellResource(0,0,*(undefined4 *)(in_EAX + 2));
        return;
      }
    }
  }
  else if (uVar4 < 0x7444) {
    if (uVar4 == 0x7443) {
      FEListBox__SetCellString();
      return;
    }
    if (uVar4 == 0x7343) {
      FEListBox__SetCurrentCellScale();
      return;
    }
    if (uVar4 == 0x734c) {
      uVar3 = *(undefined4 *)(in_EAX + 4);
      *(undefined4 *)(iVar5 + 0x7c) = *(undefined4 *)(in_EAX + 2);
      *(undefined4 *)(iVar5 + 0x80) = uVar3;
      return;
    }
  }
  else if (uVar4 == 0x764c) {
    uVar3 = *(undefined4 *)(in_EAX + 4);
    *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(in_EAX + 2);
    *(undefined4 *)(iVar5 + 0x68) = uVar3;
  }
  else if (uVar4 == 0x774c) {
    if (*(int *)(in_EAX + 2) != 0) {
      *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffb;
      return;
    }
    *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) | 4;
    return;
  }
  return;
}


// ==== 0x501da0 FUN_00501da0

void __fastcall FUN_00501da0(undefined4 param_1,ushort *param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  int in_EAX;
  uint uVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = *param_2;
  iVar3 = *(int *)(in_EAX + 0xc);
  if (uVar2 < 0x6a4d) {
    if (uVar2 == 0x6a4c) {
      FECodeListBox__SetCellJustification
                (0,0,*(undefined4 *)(param_2 + 2),*(undefined4 *)(iVar3 + 0x5c),
                 *(undefined4 *)(iVar3 + 0x60));
      return;
    }
    if (uVar2 == 0x444c) {
      FUN_004fa8c0(iVar3);
      return;
    }
    if (uVar2 == 0x4953) {
      FEGrid_AllocStringBuffers(*(undefined4 *)(param_2 + 2),*(undefined4 *)(param_2 + 4));
      return;
    }
    if (uVar2 == 0x6343) {
      FECodeListBox__SetCellColor
                (0,0,*(undefined4 *)(param_2 + 2),*(undefined4 *)(iVar3 + 0x5c),
                 *(undefined4 *)(iVar3 + 0x60));
      return;
    }
  }
  else if (uVar2 == 0x7343) {
    local_8 = *(undefined4 *)(param_2 + 2);
    local_4 = *(undefined4 *)(param_2 + 4);
    FECodeListBox__SetCellScale
              (0,0,&local_8,*(undefined4 *)(iVar3 + 0x5c),*(undefined4 *)(iVar3 + 0x60));
  }
  else {
    if (uVar2 == 0x744c) {
      uVar4 = *(uint *)(iVar3 + 100) & 1;
      *(uint *)(iVar3 + 100) = uVar4;
      *(uint *)(iVar3 + 100) = *(uint *)(param_2 + 2) & 0xfffffffe | uVar4;
      return;
    }
    if (uVar2 == 0x764c) {
      uVar1 = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(param_2 + 2);
      *(undefined4 *)(iVar3 + 0x84) = uVar1;
      return;
    }
  }
  return;
}


// ==== 0x501ea0 FUN_00501ea0

undefined4 FUN_00501ea0(int param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  char cVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  ushort *puVar16;
  undefined1 *puVar17;
  uint local_2c;
  uint local_28;
  int *local_24;
  int local_20;
  uint local_18;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684f18;
  puVar7 = (ushort *)((int)param_3 + (int)param_2);
  puVar14 = (undefined1 *)0x0;
  param_3 = (undefined4 *)0x0;
  local_20 = -1;
  cVar6 = '\0';
  ppvVar5 = &local_c;
  local_c = ExceptionList;
  for (; ExceptionList = ppvVar5, param_2 < puVar7;
      param_2 = (ushort *)((int)param_2 + param_2[1] + 4)) {
    uVar1 = *param_2;
    if (uVar1 < 0x6654) {
      if (uVar1 == 0x6653) {
        if (param_3 != (undefined4 *)0x0) {
          param_3[5] = *(undefined4 *)(param_2 + 2);
        }
      }
      else if (uVar1 < 0x6155) {
        if (uVar1 == 0x6154) {
          if (param_3 != (undefined4 *)0x0) {
            puVar14[3] = (char)param_2[2];
          }
        }
        else if (uVar1 == 0x4946) {
          local_20 = local_20 + 1;
          puVar14 = (undefined1 *)(local_20 * 0x38 + param_3[8]);
          *puVar14 = (char)param_2[2];
          puVar14[1] = *(undefined1 *)((int)param_2 + 5);
          puVar14[2] = (char)param_2[3];
          puVar14[3] = *(undefined1 *)((int)param_2 + 7);
          *(uint *)(puVar14 + 4) =
               *(uint *)(puVar14 + 4) ^ (*(uint *)(param_2 + 4) ^ *(uint *)(puVar14 + 4)) & 0xffffff
          ;
          puVar14[7] = cVar6;
          cVar6 = cVar6 + ((byte)puVar14[1] >> 2);
        }
        else if (uVar1 == 0x4953) {
          param_3 = (undefined4 *)FEObject__FindScript();
          puVar14 = (undefined1 *)0x0;
        }
        else if (uVar1 == 0x5645) {
          uVar15 = param_2[1] / 0xc;
          FEListEntryArray__SetCount(param_3 + 9,uVar15);
          puVar8 = (undefined4 *)param_3[10];
          puVar16 = param_2 + 2;
          do {
            *puVar8 = *(undefined4 *)puVar16;
            puVar8[1] = *(undefined4 *)(puVar16 + 2);
            puVar8[2] = *(undefined4 *)(puVar16 + 4);
            puVar8 = puVar8 + 3;
            puVar16 = puVar16 + 6;
            uVar15 = uVar15 - 1;
          } while (uVar15 != 0);
        }
      }
      else if (uVar1 == 0x6254) {
        uVar15 = (uint)((byte)puVar14[1] >> 2);
        *(undefined4 *)(puVar14 + 0x14) = *(undefined4 *)(param_2 + 2);
        if (uVar15 != 0) {
          puVar8 = (undefined4 *)(puVar14 + 0x18);
          puVar16 = param_2 + 4;
          do {
            *puVar8 = *(undefined4 *)puVar16;
            puVar16 = puVar16 + 2;
            puVar8 = puVar8 + 1;
            uVar15 = uVar15 - 1;
          } while (uVar15 != 0);
        }
      }
      else if (uVar1 == 0x6353) {
        param_3[6] = *(undefined4 *)(param_2 + 2);
      }
      else if (uVar1 == 0x644b) {
        uVar1 = param_2[1];
        uVar15 = (byte)puVar14[1] + 4;
        puVar16 = param_2 + 2;
        local_2c = 0;
        if (puVar14[0x2c] != '\0') {
          *(undefined4 *)(puVar14 + 0x30) = 0;
          *(undefined4 *)(puVar14 + 0x34) = 0;
          puVar14[0x2c] = 0;
        }
        do {
          if (local_2c == 0) {
            puVar8 = (undefined4 *)(puVar14 + 8);
          }
          else {
            puVar8 = (undefined4 *)FUN_004fccf0();
            if (puVar8 == (undefined4 *)0x0) {
              puVar8 = (undefined4 *)0x0;
            }
            else {
              puVar8[1] = 0xabadcafe;
              puVar8[2] = 0xabadcafe;
              *puVar8 = &PTR_FUN_006c1830;
            }
          }
          puVar8[3] = *(undefined4 *)puVar16;
          uVar9 = 0;
          if (uVar15 >> 2 != 1) {
            puVar13 = puVar8 + 4;
            do {
              *puVar13 = *(undefined4 *)(puVar16 + uVar9 * 2 + 2);
              uVar9 = uVar9 + 1;
              puVar13 = puVar13 + 1;
            } while (uVar9 < (uVar15 >> 2) - 1);
          }
          if (local_2c != 0) {
            iVar12 = *(int *)(puVar14 + 0x34);
            if (iVar12 == 0) {
              iVar11 = *(int *)(puVar14 + 0x30);
              puVar8[1] = iVar11;
              if (iVar11 != 0) {
                *(undefined4 **)(iVar11 + 8) = puVar8;
              }
              puVar8[2] = 0;
              *(undefined4 **)(puVar14 + 0x30) = puVar8;
            }
            else {
              iVar11 = *(int *)(iVar12 + 4);
              puVar8[1] = iVar11;
              if (iVar11 != 0) {
                *(undefined4 **)(iVar11 + 8) = puVar8;
              }
              puVar8[2] = iVar12;
              *(undefined4 **)(iVar12 + 4) = puVar8;
            }
            if (*(int *)(puVar14 + 0x34) == iVar12) {
              *(undefined4 **)(puVar14 + 0x34) = puVar8;
            }
          }
          puVar16 = (ushort *)((int)puVar16 + uVar15);
          local_2c = local_2c + 1;
        } while (local_2c < uVar1 / uVar15);
      }
    }
    else if (uVar1 < 0x6e54) {
      if (uVar1 == 0x6e53) {
        param_3 = (undefined4 *)FUN_00502cd0();
        param_3[1] = 0xabadcafe;
        param_3[2] = 0xabadcafe;
        *param_3 = &PTR_FUN_006c17f0;
        param_3[9] = 0;
        param_3[10] = 0;
        param_3[0xb] = 0;
        param_3[0xc] = 0;
        param_3[3] = 0;
        param_3[5] = 0;
        param_3[6] = 0;
        param_3[7] = 0;
        param_3[8] = 0;
        param_3[4] = 0;
        if (*(char *)(param_1 + 10) != '\0') {
          FEScript__SetName();
        }
        local_20 = -1;
        cVar6 = '\0';
      }
      else if (uVar1 == 0x6853) {
        param_3[0xc] = *(undefined4 *)(param_2 + 2);
        param_3[3] = *(undefined4 *)(param_2 + 4);
        param_3[5] = *(undefined4 *)(param_2 + 6);
        FEScript__SetTrackCount(param_3);
      }
      else if (uVar1 == 0x6954) {
        if ((param_3 != (undefined4 *)0x0) &&
           (puVar14 = (undefined1 *)FEScript__FindTrack(), puVar14 == (undefined1 *)0x0)) {
          iVar12 = param_3[7] + 1;
          piVar10 = _malloc(iVar12 * 0x38 + 4);
          local_4 = 0;
          if (piVar10 == (int *)0x0) {
            local_24 = (int *)0x0;
          }
          else {
            local_24 = piVar10 + 1;
            *piVar10 = iVar12;
            eh_vector_constructor_iterator(local_24,0x38,iVar12,FEKeyTrack__FEKeyTrack,FUN_00502450)
            ;
          }
          local_4 = 0xffffffff;
          FETypeLib__FindType();
          iVar11 = FETypeNode__GetFieldAt();
          iVar12 = param_3[8];
          local_28 = 0;
          local_18 = 0;
          puVar17 = (undefined1 *)((int)local_24 + 1);
          local_2c = iVar12;
          do {
            if (((iVar12 == 0) || ((uint)param_3[7] <= local_28)) ||
               ((iVar11 != 0 &&
                ((int)(*(int *)(iVar11 + 0x1c) + (*(int *)(iVar11 + 0x1c) >> 0x1f & 3U)) >> 2 <=
                 (int)*(char *)(local_2c + 7))))) {
              puVar17[-1] = *(undefined1 *)(iVar11 + 0x14);
              puVar14 = puVar17 + -1;
              *puVar17 = *(undefined1 *)(iVar11 + 0x18);
              puVar17[1] = 1;
              puVar17[2] = 0;
              *(uint *)(puVar17 + 3) =
                   *(uint *)(puVar17 + 3) ^ (param_3[3] ^ *(uint *)(puVar17 + 3)) & 0xffffff;
              puVar17[6] = (char)(*(uint *)(iVar11 + 0x1c) >> 2);
              iVar11 = 0;
            }
            else {
              FUN_004fcb20(puVar17 + -1);
              local_28 = local_28 + 1;
              local_2c = local_2c + 0x38;
            }
            local_18 = local_18 + 1;
            puVar17 = puVar17 + 0x38;
          } while (local_18 <= (uint)param_3[7]);
          pvVar2 = (void *)param_3[8];
          if (pvVar2 != (void *)0x0) {
            eh_vector_destructor_iterator(pvVar2,0x38,*(int *)((int)pvVar2 + -4),FUN_00502450);
            _free((void *)((int)pvVar2 + -4));
          }
          param_3[8] = local_24;
          param_3[7] = param_3[7] + 1;
        }
      }
      else if (uVar1 == 0x6c53) {
        param_3[3] = *(undefined4 *)(param_2 + 2);
      }
    }
    else if (uVar1 == 0x6f54) {
      puVar14[7] = (char)param_2[2];
    }
    else if ((uVar1 == 0x7454) && (param_3 != (undefined4 *)0x0)) {
      puVar14[2] = (char)param_2[2];
    }
    ppvVar5 = ExceptionList;
  }
  iVar12 = CONCAT31((int3)((uint)puVar7 >> 8),*(char *)(param_1 + 0x18));
  if (*(char *)(param_1 + 0x18) == '\0') {
    iVar11 = *(int *)(param_1 + 0xc);
    iVar3 = *(int *)(iVar11 + 0x50);
    iVar12 = iVar11 + 0x44;
    if (param_3 != (undefined4 *)0x0) {
      if (iVar3 == 0) {
        iVar4 = *(int *)(iVar11 + 0x4c);
        param_3[1] = iVar4;
        if (iVar4 != 0) {
          *(undefined4 **)(iVar4 + 8) = param_3;
        }
        param_3[2] = 0;
        *(undefined4 **)(iVar11 + 0x4c) = param_3;
      }
      else {
        iVar4 = *(int *)(iVar3 + 4);
        param_3[1] = iVar4;
        if (iVar4 != 0) {
          *(undefined4 **)(iVar4 + 8) = param_3;
        }
        param_3[2] = iVar3;
        *(undefined4 **)(iVar3 + 4) = param_3;
      }
      if (*(int *)(iVar11 + 0x50) == iVar3) {
        *(undefined4 **)(iVar11 + 0x50) = param_3;
      }
      *(int *)(iVar11 + 0x48) = *(int *)(iVar11 + 0x48) + 1;
    }
  }
  if (param_3[0xc] == 0x1744b3) {
    *(undefined4 **)(*(int *)(param_1 + 0xc) + 0x54) = param_3;
  }
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)iVar12 >> 8),1);
}


// ==== 0x502450 FUN_00502450

void __fastcall FUN_00502450(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068537b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_006c17bc;
  if (*(char *)(param_1 + 0x2c) == '\0') {
    FUN_004fca20();
  }
  *(undefined ***)(param_1 + 8) = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x5024b0 FUN_005024b0

undefined4 FUN_005024b0(int param_1,ushort *param_2,char param_3)

{
  ushort *puVar1;
  ushort uVar2;
  void *pvVar3;
  int in_EAX;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar1 = param_2;
  puVar4 = (ushort *)(in_EAX + (int)param_2);
  puVar7 = (undefined4 *)0x0;
  iVar6 = -1;
  param_2 = (ushort *)0x0;
  puVar5 = puVar4;
  do {
    if (puVar4 <= puVar1) {
      return CONCAT31((int3)((uint)puVar5 >> 8),1);
    }
    uVar2 = *puVar1;
    if (uVar2 < 0x7353) {
      if (uVar2 == 0x7352) {
        Variant_SetString(param_2);
      }
      else if (uVar2 == 0x434d) {
        FUN_004fe3d0(puVar7,*(undefined4 *)(puVar1 + 2));
      }
      else if (uVar2 == 0x694d) {
        iVar6 = *(int *)(puVar1 + 2);
        if ((param_3 == '\0') && (*(char *)(param_1 + 0x18) != '\0')) {
          for (puVar7 = *(undefined4 **)(*(int *)(param_1 + 0xc) + 0x3c);
              (puVar7 != (undefined4 *)0x0 && (puVar7[3] != iVar6));
              puVar7 = (undefined4 *)puVar7[1]) {
          }
          if (puVar7 != (undefined4 *)0x0) {
            pvVar3 = (void *)puVar7[5];
            if (pvVar3 != (void *)0x0) {
              eh_vector_destructor_iterator
                        (pvVar3,0xc,*(int *)((int)pvVar3 + -4),FEResponse__ReleaseParam);
              _free((void *)((int)pvVar3 + -4));
            }
            puVar7[5] = 0;
            puVar7[4] = 0;
            iVar6 = -1;
            goto LAB_00502628;
          }
        }
        puVar7 = (undefined4 *)FUN_004fe570();
        puVar7[1] = 0xabadcafe;
        puVar7[2] = 0xabadcafe;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7[5] = 0;
        *puVar7 = &PTR_FUN_006c181c;
        puVar7[3] = iVar6;
        if (param_3 == '\0') {
          FUN_004ee590();
          iVar6 = -1;
        }
        else {
          FEPackage__AddResponse();
          iVar6 = -1;
        }
      }
      else if (uVar2 == 0x6952) {
        iVar6 = iVar6 + 1;
        param_2 = (ushort *)(puVar7[5] + iVar6 * 0xc);
        *(undefined4 *)param_2 = *(undefined4 *)(puVar1 + 2);
      }
    }
    else if (uVar2 == 0x7452) {
      *(undefined4 *)((int)param_2 + 8) = *(undefined4 *)(puVar1 + 2);
    }
    else if (uVar2 == 0x7552) {
      *(undefined4 *)((int)param_2 + 4) = *(undefined4 *)(puVar1 + 2);
    }
LAB_00502628:
    puVar5 = (ushort *)(uint)puVar1[1];
    puVar1 = (ushort *)((int)(puVar1 + 2) + (int)puVar5);
  } while( true );
}


// ==== 0x502650 FUN_00502650

undefined4 FUN_00502650(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint local_28;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  piVar4 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685a80;
  local_c = ExceptionList;
  iVar2 = param_1[1];
  iVar3 = *(int *)(iVar2 + 8);
  piVar5 = (int *)(iVar2 + 8);
  while ((iVar3 != 0x67726154 && (piVar5 != (int *)(*(int *)(iVar2 + 4) + 8 + iVar2)))) {
    piVar5 = (int *)((int)piVar5 + piVar5[1] + 8);
    iVar3 = *piVar5;
  }
  if (*piVar5 == 0x67726154) {
    piVar10 = piVar5 + 2;
    piVar6 = (int *)(piVar5[1] + (int)piVar10);
    piVar5 = piVar6;
    if (piVar10 < piVar6) {
      param_1 = (int *)0x0;
      ExceptionList = &local_c;
      do {
        if ((short)*piVar10 == 0x6354) {
          iVar2 = piVar10[1];
          *(int *)(*piVar4 + 0x60) = iVar2;
          piVar7 = _malloc(iVar2 * 0x10 + 4);
          piVar5 = (int *)0x0;
          local_4 = 0;
          if (piVar7 != (int *)0x0) {
            piVar5 = piVar7 + 1;
            *piVar7 = iVar2;
            eh_vector_constructor_iterator(piVar5,0x10,iVar2,FEEventList__FEEventList,FUN_004fe970);
          }
          local_4 = 0xffffffff;
          *(int **)(*piVar4 + 100) = piVar5;
        }
        else if ((short)*piVar10 == 0x744d) {
          uVar1 = *(ushort *)((int)piVar10 + 2);
          *(int *)(*(int *)(*piVar4 + 100) + (int)param_1) = piVar10[1];
          uVar8 = (uVar1 >> 2) - 1;
          FEEventList__SetCount(*(int *)(*piVar4 + 100) + (int)param_1,uVar8);
          local_28 = 0;
          if (uVar8 != 0) {
            do {
              local_4 = 1;
              FUN_004ffb00(*piVar4);
              iVar2 = *(int *)(*piVar4 + 100);
              iVar3 = *(int *)(iVar2 + 4 + (int)param_1);
              iVar9 = iVar2 + (int)param_1;
              local_4 = 0xffffffff;
              if (*(int *)(iVar2 + 8 + (int)param_1) == iVar3) {
                FEEventList__SetCount(iVar9,iVar3 + 1);
              }
              *(undefined4 *)(*(int *)(iVar9 + 0xc) + *(int *)(iVar9 + 8) * 4) = 0;
              local_28 = local_28 + 1;
              *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + 1;
            } while (local_28 < uVar8);
          }
          param_1 = (int *)((int)param_1 + 0x10);
        }
        piVar5 = (int *)(uint)*(ushort *)((int)piVar10 + 2);
        piVar10 = (int *)((int)(piVar10 + 1) + (int)piVar5);
      } while (piVar10 < piVar6);
    }
  }
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)piVar5 >> 8),1);
}


// ==== 0x502840 FUN_00502840

bool FUN_00502840(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  int in_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  *param_2 = 0;
  *param_3 = 0;
  uVar1 = *(uint *)(*param_1 + 0x78);
  uVar3 = 0;
  if (uVar1 != 0) {
    piVar2 = *(int **)(*param_1 + 0x7c);
    piVar5 = piVar2;
    while (*piVar5 != in_EAX) {
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 3;
      if (uVar1 <= uVar3) {
        return false;
      }
    }
    if (piVar2 + uVar3 * 3 != (int *)0x0) {
      iVar4 = UIList__FindNodeByNameHash();
      *param_3 = iVar4;
      if (iVar4 != 0) {
        iVar4 = FUN_004ffbe0();
        *param_2 = iVar4;
        return iVar4 != 0;
      }
    }
  }
  return false;
}


// ==== 0x5028d0 FEScript::_FEScript

/* [canon] hud high (ghidra-canon+mw) docs/re/hud.md */

void __fastcall FEScript___FEScript(undefined4 *param_1)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006858a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c17f0;
  pvVar1 = (void *)param_1[8];
  local_4 = 1;
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0x38,*(int *)((int)pvVar1 + -4),FUN_00502450);
    _free((void *)((int)pvVar1 + -4));
  }
  param_1[8] = 0;
  if ((void *)param_1[0xb] != (void *)0x0) {
    _free((void *)param_1[0xb]);
  }
  param_1[0xb] = 0;
  _free((void *)param_1[10]);
  param_1[10] = 0;
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x502970 FUN_00502970

undefined4 * FUN_00502970(undefined4 *param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685883;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  *param_1 = &PTR_FUN_006c17f0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  local_4 = 1;
  FEScript__SetName();
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  FEScript__SetTrackCount(param_1);
  if (param_3 == '\0') {
    if (param_1[7] != 0) {
      iVar4 = 0;
      uVar3 = 0;
      do {
        FUN_004fcb20(param_1[8] + iVar4);
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x38;
      } while (uVar3 < (uint)param_1[7]);
    }
  }
  else {
    _param_3 = 0;
    if (param_1[7] != 0) {
      iVar4 = 0;
      do {
        *(undefined1 *)(iVar4 + param_1[8]) = *(undefined1 *)(iVar4 + *(int *)(param_2 + 0x20));
        *(undefined1 *)(iVar4 + 1 + param_1[8]) =
             *(undefined1 *)(iVar4 + 1 + *(int *)(param_2 + 0x20));
        *(undefined1 *)(iVar4 + 2 + param_1[8]) =
             *(undefined1 *)(iVar4 + 2 + *(int *)(param_2 + 0x20));
        *(undefined1 *)(iVar4 + 3 + param_1[8]) =
             *(undefined1 *)(iVar4 + 3 + *(int *)(param_2 + 0x20));
        uVar3 = *(uint *)(iVar4 + 4 + param_1[8]);
        *(uint *)(iVar4 + 4 + param_1[8]) =
             uVar3 ^ ((*(int *)(iVar4 + 4 + *(int *)(param_2 + 0x20)) << 8) >> 8 ^ uVar3) & 0xffffff
        ;
        *(undefined1 *)(iVar4 + 7 + param_1[8]) =
             *(undefined1 *)(iVar4 + 7 + *(int *)(param_2 + 0x20));
        iVar1 = iVar4 + 8 + *(int *)(param_2 + 0x20);
        iVar2 = param_1[8];
        *(undefined4 *)(iVar4 + 0xc + iVar2) =
             *(undefined4 *)(iVar4 + 0xc + *(int *)(param_2 + 0x20));
        iVar2 = iVar4 + 8 + iVar2;
        *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
        *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
        iVar1 = iVar4 + 0x28 + *(int *)(param_2 + 0x20);
        iVar2 = iVar4 + 0x28 + param_1[8];
        if (iVar1 == 0) {
          *(undefined4 *)(iVar2 + 8) = 0;
          *(undefined4 *)(iVar2 + 0xc) = 0;
          *(undefined1 *)(iVar2 + 4) = 0;
        }
        else {
          if (*(char *)(iVar2 + 4) == '\0') {
            FUN_004fca20();
          }
          *(int *)(iVar2 + 8) = iVar1;
          *(undefined1 *)(iVar2 + 4) = 1;
        }
        _param_3 = _param_3 + 1;
        iVar4 = iVar4 + 0x38;
      } while (_param_3 < (uint)param_1[7]);
    }
  }
  FEListEntryArray__SetCount(param_1 + 9,*(undefined4 *)(param_2 + 0x24));
  puVar5 = *(undefined4 **)(param_2 + 0x28);
  puVar6 = (undefined4 *)param_1[10];
  for (uVar3 = param_1[9] * 3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x502b70 FUN_00502b70

void FUN_00502b70(void)

{
  undefined4 *unaff_ESI;
  
  (**(code **)*unaff_ESI)(0);
  FUN_00502d80();
  return;
}


// ==== 0x502b90 FEScript::SetName

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEScript__SetName(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int unaff_ESI;
  char *unaff_EDI;
  
  if (*(void **)(unaff_ESI + 0x2c) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x2c));
    *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x30) = 0xffffffff;
  if (unaff_EDI != (char *)0x0) {
    pcVar2 = unaff_EDI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = _malloc((size_t)(pcVar2 + (1 - (int)(unaff_EDI + 1))));
    *(char **)(unaff_ESI + 0x2c) = pcVar2;
    do {
      cVar1 = *unaff_EDI;
      unaff_EDI = unaff_EDI + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar3 = FEng__HashName();
    *(undefined4 *)(unaff_ESI + 0x30) = uVar3;
  }
  return;
}


// ==== 0x502bf0 FEScript::SetTrackCount

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEScript__SetTrackCount(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int unaff_ESI;
  int *piVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b68;
  local_c = ExceptionList;
  pvVar1 = *(void **)(param_1 + 0x20);
  ExceptionList = &local_c;
  if (pvVar1 != (void *)0x0) {
    ExceptionList = &local_c;
    eh_vector_destructor_iterator(pvVar1,0x38,*(int *)((int)pvVar1 + -4),FUN_00502450);
    _free((void *)((int)pvVar1 + -4));
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(int *)(param_1 + 0x1c) = unaff_ESI;
  if (unaff_ESI != 0) {
    piVar2 = _malloc(unaff_ESI * 0x38 + 4);
    local_4 = 0;
    if (piVar2 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = piVar2 + 1;
      *piVar2 = unaff_ESI;
      eh_vector_constructor_iterator(piVar3,0x38,unaff_ESI,FEKeyTrack__FEKeyTrack,FUN_00502450);
    }
    *(int **)(param_1 + 0x20) = piVar3;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x502c90 FEScript::FindTrack

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

int __fastcall FEScript__FindTrack(undefined4 param_1,int param_2)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(uint *)(param_2 + 0x1c) != 0) {
    iVar2 = *(int *)(param_2 + 0x20) + 4;
    do {
      if ((int)*(char *)(iVar2 + 3) == *(int *)(&DAT_006b66e4 + in_EAX * 4)) {
        return uVar1 * 0x38 + *(int *)(param_2 + 0x20);
      }
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (uVar1 < *(uint *)(param_2 + 0x1c));
  }
  return 0;
}


// ==== 0x502cd0 FUN_00502cd0

void FUN_00502cd0(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  for (iVar3 = *(int *)(unaff_EDI + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    ExceptionList = &local_c;
    if (*(int *)(iVar3 + 0x690) != 0) goto LAB_00502d52;
  }
  ExceptionList = &local_c;
  pvVar2 = _malloc(0x6a0);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FEScript__StaticPoolInit(pvVar2);
  }
  if (iVar3 != 0) {
    iVar1 = *(int *)(unaff_EDI + 8);
    *(int *)(iVar3 + 4) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(unaff_EDI + 8) = iVar3;
    if (*(int *)(unaff_EDI + 0xc) == 0) {
      *(int *)(unaff_EDI + 0xc) = iVar3;
    }
    *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + 1;
  }
LAB_00502d52:
  if (*(int *)(iVar3 + 0x694) != 0) {
    FUN_004ee670();
  }
  *(int *)(iVar3 + 0x69c) = *(int *)(iVar3 + 0x69c) + 1;
  ExceptionList = local_c;
  return;
}


// ==== 0x502d80 FUN_00502d80

void FUN_00502d80(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar2 = *(undefined4 **)(unaff_EDI + 8);
  if (puVar2 != (undefined4 *)0x0) {
    while ((in_EAX < puVar2 + 3 || (puVar2 + 0x1a3 <= in_EAX))) {
      puVar2 = (undefined4 *)puVar2[1];
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
    }
    FUN_004ee590();
    piVar1 = puVar2 + 0x1a7;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_004ee670();
      (**(code **)*puVar2)(1);
    }
  }
  return;
}


// ==== 0x502dd0 FEScript::StaticPoolInit

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

undefined4 * FEScript__StaticPoolInit(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c17b8;
  eh_vector_constructor_iterator(param_1 + 3,0x34,0x20,FEScript__FEScript,FEScript___FEScript);
  param_1[0x1a3] = &PTR_FUN_006c2c4c;
  param_1[0x1a5] = 0;
  param_1[0x1a6] = 0;
  param_1[0x1a4] = 0;
  param_1[0x1a7] = 0;
  piVar4 = param_1 + 5;
  iVar5 = 8;
  do {
    iVar2 = param_1[0x1a6];
    if (piVar4 != (int *)0x8) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x1a5];
        piVar4[-1] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar4 + -2;
        }
        *piVar4 = 0;
        param_1[0x1a5] = piVar4 + -2;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[-1] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar4 + -2;
        }
        *piVar4 = iVar2;
        *(int **)(iVar2 + 4) = piVar4 + -2;
      }
      if (param_1[0x1a6] == iVar2) {
        param_1[0x1a6] = piVar4 + -2;
      }
      param_1[0x1a4] = param_1[0x1a4] + 1;
    }
    iVar2 = param_1[0x1a6];
    piVar1 = piVar4 + 0xb;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x1a5];
        piVar4[0xc] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0xd] = 0;
        param_1[0x1a5] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0xc] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0xd] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x1a6] == iVar2) {
        param_1[0x1a6] = piVar1;
      }
      param_1[0x1a4] = param_1[0x1a4] + 1;
    }
    iVar2 = param_1[0x1a6];
    piVar1 = piVar4 + 0x18;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x1a5];
        piVar4[0x19] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x1a] = 0;
        param_1[0x1a5] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0x19] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x1a] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x1a6] == iVar2) {
        param_1[0x1a6] = piVar1;
      }
      param_1[0x1a4] = param_1[0x1a4] + 1;
    }
    iVar2 = param_1[0x1a6];
    piVar1 = piVar4 + 0x25;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x1a5];
        piVar4[0x26] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x27] = 0;
        param_1[0x1a5] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0x26] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x27] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x1a6] == iVar2) {
        param_1[0x1a6] = piVar1;
      }
      param_1[0x1a4] = param_1[0x1a4] + 1;
    }
    piVar4 = piVar4 + 0x34;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x502fd0 FUN_00502fd0

void FUN_00502fd0(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00685a5e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c17b8;
  iVar1 = param_1[0x1a4];
  local_4 = 1;
  while (iVar1 != 0) {
    iVar1 = param_1[0x1a5];
    if (iVar1 != 0) {
      param_1[0x1a5] = *(undefined4 *)(iVar1 + 4);
      if (iVar1 == param_1[0x1a6]) {
        param_1[0x1a6] = *(undefined4 *)(iVar1 + 8);
      }
      if (*(int *)(iVar1 + 8) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 8) + 4) = *(undefined4 *)(iVar1 + 4);
      }
      if (*(int *)(iVar1 + 4) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 4) + 8) = *(undefined4 *)(iVar1 + 8);
      }
      *(undefined4 *)(iVar1 + 4) = 0xabadcafe;
      *(undefined4 *)(iVar1 + 8) = 0xabadcafe;
      param_1[0x1a4] = param_1[0x1a4] + -1;
    }
    iVar1 = param_1[0x1a4];
  }
  param_1[0x1a3] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = local_4 & 0xffffff00;
  eh_vector_destructor_iterator(param_1 + 3,0x34,0x20,FEScript___FEScript);
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x5030b0 FUN_005030b0

void * __thiscall FUN_005030b0(void *param_1,byte param_2)

{
  FUN_00502fd0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5030d0 FESlotNode::FESlotNode

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FESlotNode__FESlotNode(void)

{
  ushort in_AX;
  void *pvVar1;
  undefined4 *unaff_ESI;
  
  *(ushort *)(unaff_ESI + 3) = in_AX;
  unaff_ESI[1] = 0xabadcafe;
  unaff_ESI[2] = 0xabadcafe;
  *unaff_ESI = &PTR_FUN_006c17b4;
  *(undefined2 *)((int)unaff_ESI + 0xe) = 0;
  unaff_ESI[5] = 0;
  pvVar1 = _malloc((uint)in_AX << 5);
  unaff_ESI[5] = pvVar1;
  unaff_ESI[4] = 0;
  return;
}


// ==== 0x503110 FESlotNode::_FESlotNode

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FESlotNode___FESlotNode(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c17b4;
  _free((void *)unaff_ESI[5]);
  *unaff_ESI = &PTR_FUN_006c2c50;
  return;
}


// ==== 0x503130 FUN_00503130

void * __thiscall FUN_00503130(void *param_1,byte param_2)

{
  FESlotNode___FESlotNode();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x503150 FUN_00503150

void * __thiscall FUN_00503150(void *param_1,byte param_2)

{
  FUN_00503170(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x503170 FUN_00503170

void FUN_00503170(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684ef8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  param_1[3] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x5031c0 FESlotNode::AllocBlock

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

int FESlotNode__AllocBlock(void)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int unaff_ESI;
  
  if (*(short *)(unaff_ESI + 0xe) != 0x20) {
    uVar5 = 0;
    cVar3 = *(char *)(unaff_ESI + 0x10);
    while (cVar3 == -1) {
      pcVar1 = (char *)(unaff_ESI + 0x11 + uVar5);
      uVar5 = uVar5 + 1;
      cVar3 = *pcVar1;
    }
    uVar6 = uVar5 << 3;
    bVar4 = *(byte *)((uVar5 & 0x1fffffff) + 0x10 + unaff_ESI) & 1;
    while (bVar4 != 0) {
      uVar6 = uVar6 + 1;
      bVar4 = *(byte *)((uVar6 >> 3) + 0x10 + unaff_ESI) & (byte)(1 << ((byte)uVar6 & 7));
    }
    *(short *)(unaff_ESI + 0xe) = *(short *)(unaff_ESI + 0xe) + 1;
    pbVar2 = (byte *)((uVar6 >> 3) + 0x10 + unaff_ESI);
    *pbVar2 = *pbVar2 | '\x01' << ((byte)uVar6 & 7);
    return *(ushort *)(unaff_ESI + 0xc) * uVar6 + *(int *)(unaff_ESI + 0x14);
  }
  return 0;
}


// ==== 0x503250 FUN_00503250

void FUN_00503250(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int unaff_EDI;
  
  for (iVar3 = *(int *)(unaff_EDI + 0x14); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    if (*(short *)(iVar3 + 0xe) != 0x20) goto LAB_005032b4;
  }
  pvVar2 = _malloc(0x18);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FESlotNode__FESlotNode();
  }
  if (iVar3 != 0) {
    iVar1 = *(int *)(unaff_EDI + 0x14);
    *(int *)(iVar3 + 4) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(unaff_EDI + 0x14) = iVar3;
    if (*(int *)(unaff_EDI + 0x18) == 0) {
      *(int *)(unaff_EDI + 0x18) = iVar3;
    }
    *(int *)(unaff_EDI + 0x10) = *(int *)(unaff_EDI + 0x10) + 1;
  }
LAB_005032b4:
  FESlotNode__AllocBlock();
  return;
}


// ==== 0x5032c0 FUN_005032c0

uint FUN_005032c0(void)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  uint in_EAX;
  undefined3 uVar3;
  undefined3 extraout_var;
  uint uVar4;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x14);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return in_EAX & 0xffffff00;
    }
    if (((uint)puVar1[5] <= in_EAX) && (in_EAX < (uint)*(ushort *)(puVar1 + 3) * 0x20 + puVar1[5]))
    break;
    puVar1 = (undefined4 *)puVar1[1];
  }
  uVar2 = (ulonglong)(in_EAX - puVar1[5]) / (ulonglong)*(ushort *)(puVar1 + 3);
  *(short *)((int)puVar1 + 0xe) = *(short *)((int)puVar1 + 0xe) + -1;
  uVar3 = (undefined3)(uVar2 >> 8);
  uVar4 = (uint)uVar2 >> 3;
  *(byte *)(uVar4 + 0x10 + (int)puVar1) =
       *(byte *)(uVar4 + 0x10 + (int)puVar1) & ~('\x01' << ((byte)uVar2 & 7));
  if (*(short *)((int)puVar1 + 0xe) == 0) {
    FUN_004ee670();
    (**(code **)*puVar1)(1);
    uVar3 = extraout_var;
  }
  return CONCAT31(uVar3,1);
}


// ==== 0x503330 FUN_00503330

undefined4 FUN_00503330(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    return 0;
  }
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    if (*(int *)(iVar1 + 0x1c) == unaff_ESI) goto LAB_005033b6;
  }
  puVar2 = _malloc(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 0xabadcafe;
    puVar2[2] = 0xabadcafe;
    *puVar2 = &PTR_FUN_006c17b0;
    puVar2[3] = &PTR_FUN_006c2c4c;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[4] = 0;
    puVar2[7] = unaff_ESI;
  }
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = *(int *)(param_1 + 8);
    puVar2[1] = iVar1;
    if (iVar1 != 0) {
      *(undefined4 **)(iVar1 + 8) = puVar2;
    }
    puVar2[2] = 0;
    *(undefined4 **)(param_1 + 8) = puVar2;
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 **)(param_1 + 0xc) = puVar2;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
LAB_005033b6:
  uVar3 = FUN_00503250();
  return uVar3;
}


// ==== 0x5033d0 FUN_005033d0

void FUN_005033d0(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    puVar1 = *(undefined4 **)(param_1 + 8);
    while ((puVar1 != (undefined4 *)0x0 && (cVar2 = FUN_005032c0(), cVar2 == '\0'))) {
      puVar1 = (undefined4 *)puVar1[1];
    }
    if (puVar1[4] == 0) {
      FUN_004ee670();
      (**(code **)*puVar1)(1);
    }
  }
  return;
}


// ==== 0x503410 FUN_00503410

undefined4 * FUN_00503410(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_38 [14];
  
  puVar2 = _malloc(0x28);
  puVar6 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[1] = 0xabadcafe;
    puVar2[2] = 0xabadcafe;
    *puVar2 = &PTR_FUN_006c16b4;
    puVar2[7] = 0;
    puVar2[8] = 0;
    puVar2[6] = 0;
    puVar2[5] = &PTR_FUN_006c2c4c;
    puVar6 = puVar2;
  }
  FENode__SetName();
  FUN_00503ed0(puVar6);
  FUN_00503ed0(puVar6);
  FUN_00503ed0(puVar6);
  FUN_00503ed0(puVar6);
  FUN_00503ed0(puVar6);
  iVar1 = puVar6[7];
  local_38[9] = 0xff;
  local_38[8] = 0xff;
  local_38[7] = 0xff;
  local_38[6] = 0xff;
  local_38[2] = 0;
  local_38[1] = 0;
  local_38[0] = 0;
  local_38[0xc] = 0;
  local_38[0xb] = 0;
  local_38[10] = 0;
  local_38[0xd] = 0x3f800000;
  local_38[5] = 0x3f800000;
  local_38[4] = 0x3f800000;
  local_38[3] = 0x3f800000;
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar3 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar5 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar3;
    puVar2 = local_38 + 6;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  iVar1 = *(int *)(iVar1 + 4);
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar3 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar5 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar3;
    puVar2 = local_38;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  iVar1 = *(int *)(iVar1 + 4);
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar3 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar5 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar3;
    puVar2 = local_38;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  iVar1 = *(int *)(iVar1 + 4);
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar3 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar5 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar3;
    puVar2 = local_38 + 10;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  iVar1 = *(int *)(iVar1 + 4);
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar3 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar5 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar3;
    puVar2 = local_38 + 3;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return puVar6;
}


// ==== 0x503660 FUN_00503660

void * __thiscall FUN_00503660(void *param_1,byte param_2)

{
  FUN_00503680(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x503680 FUN_00503680

void FUN_00503680(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684ed8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  param_1[5] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  *param_1 = &PTR_FUN_006c1828;
  if ((void *)param_1[3] != (void *)0x0) {
    _free((void *)param_1[3]);
  }
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x5036e0 FUN_005036e0

int __fastcall FUN_005036e0(undefined4 param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_8 [2];
  
  iVar2 = FUN_00503410(param_1,in_EAX);
  FUN_00503ed0(iVar2);
  FUN_00503ed0(iVar2);
  iVar1 = *(int *)(iVar2 + 0x1c);
  local_8[0] = 0;
  local_8[1] = 0;
  while ((iVar1 != 0 && (iVar3 = __stricmp(*(char **)(iVar1 + 0xc),"Upper Left"), iVar3 != 0))) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar4 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar6 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar4;
    puVar7 = local_8;
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  iVar1 = *(int *)(iVar1 + 4);
  local_8[0] = 0x3f800000;
  local_8[1] = 0x3f800000;
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar4 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar6 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar4;
    puVar7 = local_8;
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  return iVar2;
}


// ==== 0x5037e0 FUN_005037e0

undefined4 FUN_005037e0(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_14 [5];
  
  iVar3 = FUN_005036e0();
  *(undefined4 *)(iVar3 + 0x24) = 1;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_005036e0();
  FUN_00503ed0(iVar3);
  FUN_00503ed0(iVar3);
  FUN_00503ed0(iVar3);
  FUN_00503ed0(iVar3);
  puVar2 = PTR_s_Top_Left_006f89d8;
  iVar1 = *(int *)(iVar3 + 0x1c);
  local_14[4] = 0xff;
  local_14[3] = 0xff;
  local_14[2] = 0xff;
  local_14[1] = 0xff;
  while ((iVar1 != 0 && (iVar4 = __stricmp(*(char **)(iVar1 + 0xc),puVar2), iVar4 != 0))) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar5 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar7 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar5;
    puVar8 = local_14;
    for (uVar6 = uVar7 >> 2; puVar8 = puVar8 + 1, uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar5 = *puVar8;
      puVar5 = puVar5 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  puVar2 = PTR_s_Top_Right_006f89dc;
  iVar1 = *(int *)(iVar3 + 0x1c);
  while ((iVar1 != 0 && (iVar4 = __stricmp(*(char **)(iVar1 + 0xc),puVar2), iVar4 != 0))) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar5 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar7 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar5;
    puVar8 = local_14;
    for (uVar6 = uVar7 >> 2; puVar8 = puVar8 + 1, uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar5 = *puVar8;
      puVar5 = puVar5 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  puVar2 = PTR_s_Bottom_Right_006f89e0;
  iVar1 = *(int *)(iVar3 + 0x1c);
  while ((iVar1 != 0 && (iVar4 = __stricmp(*(char **)(iVar1 + 0xc),puVar2), iVar4 != 0))) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar5 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar7 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar5;
    puVar8 = local_14;
    for (uVar6 = uVar7 >> 2; puVar8 = puVar8 + 1, uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar5 = *puVar8;
      puVar5 = puVar5 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  puVar2 = PTR_s_Bottom_Left_006f89e4;
  iVar1 = *(int *)(iVar3 + 0x1c);
  while ((iVar1 != 0 && (iVar4 = __stricmp(*(char **)(iVar1 + 0xc),puVar2), iVar4 != 0))) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar5 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar7 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar5;
    puVar8 = local_14;
    for (uVar6 = uVar7 >> 2; puVar8 = puVar8 + 1, uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar5 = *puVar8;
      puVar5 = puVar5 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  *(undefined4 *)(iVar3 + 0x24) = 9;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_005036e0();
  FUN_00503ed0(iVar3);
  puVar2 = PTR_s_Frame_Number_006f89e8;
  iVar1 = *(int *)(iVar3 + 0x1c);
  local_14[0] = 0;
  while ((iVar1 != 0 && (iVar4 = __stricmp(*(char **)(iVar1 + 0xc),puVar2), iVar4 != 0))) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  _free(*(void **)(iVar1 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (*(size_t *)(iVar1 + 0x18) != 0) {
    puVar5 = _malloc(*(size_t *)(iVar1 + 0x18));
    uVar7 = *(uint *)(iVar1 + 0x18);
    *(undefined4 **)(iVar1 + 0x20) = puVar5;
    puVar8 = local_14;
    for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar5 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  *(undefined4 *)(iVar3 + 0x24) = 10;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"Simple Image");
  *(undefined4 *)(iVar3 + 0x24) = 0xb;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"String");
  *(undefined4 *)(iVar3 + 0x24) = 2;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"Model");
  *(undefined4 *)(iVar3 + 0x24) = 3;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"Movie");
  *(undefined4 *)(iVar3 + 0x24) = 7;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"Effect");
  *(undefined4 *)(iVar3 + 0x24) = 8;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,&DAT_006c16cc);
  *(undefined4 *)(iVar3 + 0x24) = 4;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"Group");
  *(undefined4 *)(iVar3 + 0x24) = 5;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = FUN_00503410(param_1,"Code List");
  *(undefined4 *)(iVar3 + 0x24) = 6;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(int *)(iVar3 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = iVar3;
    }
    *(int *)(iVar3 + 8) = iVar1;
    *(int *)(iVar1 + 4) = iVar3;
  }
  if (*(int *)(param_1 + 0xc) == iVar1) {
    *(int *)(param_1 + 0xc) = iVar3;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return 1;
}


// ==== 0x503df0 FETypeLib::FindType

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FETypeLib__FindType(int param_1)

{
  int iVar1;
  int in_EAX;
  
  for (iVar1 = *(int *)(in_EAX + 8); (iVar1 != 0 && (*(int *)(iVar1 + 0x24) != param_1));
      iVar1 = *(int *)(iVar1 + 4)) {
  }
  return;
}


// ==== 0x503e10 FEFieldNode::_FEFieldNode

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEFieldNode___FEFieldNode(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c16b0;
  _free((void *)unaff_ESI[8]);
  *unaff_ESI = &PTR_FUN_006c1828;
  if ((void *)unaff_ESI[3] != (void *)0x0) {
    _free((void *)unaff_ESI[3]);
  }
  *unaff_ESI = &PTR_FUN_006c2c50;
  return;
}


// ==== 0x503e40 FUN_00503e40

void * __thiscall FUN_00503e40(void *param_1,byte param_2)

{
  FEFieldNode___FEFieldNode();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x503e60 FETypeNode::AddField

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FETypeNode__AddField(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x20);
  if (in_EAX != 0) {
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_2 + 0x1c);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(undefined4 *)(in_EAX + 8) = 0;
      *(int *)(param_2 + 0x1c) = in_EAX;
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(int *)(in_EAX + 8) = iVar1;
      *(int *)(iVar1 + 4) = in_EAX;
    }
    if (*(int *)(param_2 + 0x20) == iVar1) {
      *(int *)(param_2 + 0x20) = in_EAX;
    }
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
  }
  iVar2 = 0;
  for (iVar1 = *(int *)(param_2 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    *(int *)(iVar1 + 0x1c) = iVar2;
    iVar2 = iVar2 + *(int *)(iVar1 + 0x18);
  }
  return;
}


// ==== 0x503ed0 FUN_00503ed0

void FUN_00503ed0(void)

{
  undefined4 *puVar1;
  int unaff_EBX;
  undefined4 *puVar2;
  
  puVar1 = _malloc(0x24);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[1] = 0xabadcafe;
    puVar1[2] = 0xabadcafe;
    *puVar1 = &PTR_FUN_006c16b0;
    puVar2 = puVar1;
  }
  FENode__SetName();
  puVar2[5] = unaff_EBX;
  puVar2[6] = *(undefined4 *)(&DAT_006b6718 + unaff_EBX * 4);
  FETypeNode__AddField();
  return;
}


// ==== 0x503f30 FEColor::FEColor

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEColor__FEColor(uint param_1)

{
  uint *in_EAX;
  
  in_EAX[3] = param_1 >> 0x18;
  in_EAX[2] = param_1 >> 0x10 & 0xff;
  in_EAX[1] = param_1 >> 8 & 0xff;
  *in_EAX = param_1 & 0xff;
  return;
}


// ==== 0x503f60 FEColor::operator_unsigned_long

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

uint FEColor__operator_unsigned_long(void)

{
  byte *in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(in_EAX + 8) < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xff;
    if (*(int *)(in_EAX + 8) < 0x100) {
      uVar3 = (uint)in_EAX[8];
    }
  }
  if (*(int *)(in_EAX + 4) < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xff;
    if (*(int *)(in_EAX + 4) < 0x100) {
      uVar2 = (uint)in_EAX[4];
    }
  }
  if (*(int *)in_EAX < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xff;
    if (*(int *)in_EAX < 0x100) {
      uVar1 = (uint)*in_EAX;
    }
  }
  if (*(int *)(in_EAX + 0xc) < 0) {
    return (uVar3 << 8 | uVar2) << 8 | uVar1;
  }
  if (0xff < *(int *)(in_EAX + 0xc)) {
    return ((uVar3 | 0xff00) << 8 | uVar2) << 8 | uVar1;
  }
  return (((uint)in_EAX[0xc] << 8 | uVar3) << 8 | uVar2) << 8 | uVar1;
}


// ==== 0x504010 WString_Free

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

void __fastcall WString_Free(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    _free((void *)*param_1);
  }
  return;
}


// ==== 0x504020 FUN_00504020

void FUN_00504020(void)

{
  short sVar1;
  undefined4 *in_EAX;
  int iVar2;
  short *psVar3;
  short *psVar4;
  undefined4 *unaff_ESI;
  
  psVar4 = (short *)*unaff_ESI;
  if (psVar4 != (short *)0x0) {
    iVar2 = 0;
    sVar1 = *psVar4;
    while (sVar1 != 0) {
      iVar2 = iVar2 + 1;
      sVar1 = psVar4[iVar2];
    }
    if ((uint)in_EAX[1] < iVar2 + 1U) {
      WString_Grow();
    }
    psVar4 = (short *)*in_EAX;
    psVar3 = (short *)*unaff_ESI;
    if (psVar4 != (short *)0x0) {
      if (psVar3 != (short *)0x0) {
        sVar1 = *psVar3;
        while (sVar1 != 0) {
          *psVar4 = sVar1;
          psVar3 = psVar3 + 1;
          psVar4 = psVar4 + 1;
          sVar1 = *psVar3;
        }
      }
      *psVar4 = 0;
    }
  }
  return;
}


// ==== 0x504080 WString_Assign

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

undefined4 * WString_Assign(void)

{
  short sVar1;
  undefined4 *in_EAX;
  int iVar2;
  short *psVar3;
  short *unaff_ESI;
  
  if (unaff_ESI != (short *)0x0) {
    iVar2 = 0;
    sVar1 = *unaff_ESI;
    while (sVar1 != 0) {
      iVar2 = iVar2 + 1;
      sVar1 = unaff_ESI[iVar2];
    }
    if ((uint)in_EAX[1] < iVar2 + 1U) {
      WString_Grow();
    }
    psVar3 = (short *)*in_EAX;
    if (psVar3 != (short *)0x0) {
      sVar1 = *unaff_ESI;
      while (sVar1 != 0) {
        *psVar3 = sVar1;
        unaff_ESI = unaff_ESI + 1;
        psVar3 = psVar3 + 1;
        sVar1 = *unaff_ESI;
      }
      *psVar3 = 0;
    }
  }
  return in_EAX;
}


// ==== 0x5040e0 WString_Grow

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

void __fastcall WString_Grow(undefined4 param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  undefined4 *unaff_EDI;
  
  psVar4 = (short *)*unaff_EDI;
  uVar2 = 0;
  if (psVar4 != (short *)0x0) {
    sVar1 = *psVar4;
    while (sVar1 != 0) {
      uVar2 = uVar2 + 1;
      sVar1 = psVar4[uVar2];
    }
  }
  if (uVar2 < param_2) {
    unaff_EDI[1] = param_2;
    psVar3 = _malloc(param_2 * 2 + 2);
    psVar4 = (short *)*unaff_EDI;
    if (psVar3 != (short *)0x0) {
      psVar5 = psVar3;
      if (psVar4 != (short *)0x0) {
        sVar1 = *psVar4;
        while (sVar1 != 0) {
          *psVar5 = sVar1;
          psVar4 = psVar4 + 1;
          psVar5 = psVar5 + 1;
          sVar1 = *psVar4;
        }
      }
      *psVar5 = 0;
    }
    _free((void *)*unaff_EDI);
    *unaff_EDI = psVar3;
  }
  return;
}


// ==== 0x50414c FUN_0050414c

uint __fastcall FUN_0050414c(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  
  return in_EAX | param_2;
}


// ==== 0x50414d FUN_0050414d

void FUN_0050414d(void)

{
  return;
}


// ==== 0x504150 FUN_00504150

void __fastcall FUN_00504150(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0x2e4 + iVar1 * 4) = 0;
    *(undefined4 *)(param_1 + 0x310 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


// ==== 0x504180 FUN_00504180

undefined4 FUN_00504180(uint param_1)

{
  int in_EAX;
  
  param_1 = *(uint *)(in_EAX + 4) & param_1;
  if (param_1 != 0) {
    return CONCAT31((int3)(param_1 >> 8),1);
  }
  return 0;
}


// ==== 0x5041a0 FUN_005041a0

void __fastcall FUN_005041a0(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 0xf;
  *param_1 = &PTR_StatBarSlider__scalar_deleting_destructor_006c01fc;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  ListSlider___ListSlider();
  return;
}


// ==== 0x5041e0 FUN_005041e0

float10 __fastcall FUN_005041e0(int param_1)

{
  return (float10)*(float *)(param_1 + 0x58);
}


// ==== 0x5041f0 StatBarSlider::GetByte4C

/* [canon] car low (ghidra-canon) docs/re/canon_db.md */

float10 __fastcall StatBarSlider__GetByte4C(int param_1)

{
  return (float10)*(byte *)(param_1 + 0x4c);
}


// ==== 0x504200 StatBarSlider::scalar_deleting_destructor

/* [canon] car low (ghidra-canon) docs/re/canon_db.md */

void * __thiscall StatBarSlider__scalar_deleting_destructor(void *param_1,byte param_2)

{
  FUN_005041a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x504220 GarageManager::GarageManager

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageManager__GarageManager(void)

{
  int unaff_ESI;
  
  *(int *)unaff_ESI = unaff_ESI;
  *(int *)(unaff_ESI + 4) = unaff_ESI;
  RideInfo__Init();
  RideInfo__Init();
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0xe50) = 0;
  *(undefined4 *)(unaff_ESI + 0xe54) = 0;
  *(undefined4 *)(unaff_ESI + 0xe5c) = 0;
  return;
}


// ==== 0x504260 GarageManager::GetMsgForNumScreensInList

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 __fastcall
GarageManager__GetMsgForNumScreensInList(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = (undefined4 *)*param_2;
      (puVar1 != param_2 && (iVar2 = iVar2 + 1, puVar1 != (undefined4 *)0x0));
      puVar1 = (undefined4 *)*puVar1) {
  }
  switch(iVar2) {
  case 0:
    return 0x1c2d8258;
  case 1:
    return 0x1c2d8259;
  case 2:
    return 0x1c2d825a;
  case 3:
    return 0x1c2d825b;
  case 4:
    return 0x1c2d825c;
  case 5:
    return 0x1c2d825d;
  case 6:
    return 0x1c2d825e;
  default:
    return 0;
  }
}


// ==== 0x5042d0 GarageManager::GetMsgForUpgradeLevel

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 GarageManager__GetMsgForUpgradeLevel(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0x2cbd3c8d;
  case 1:
    return 0x2cbd3c6b;
  case 2:
    return 0x2cbd3c6c;
  case 3:
    return 0x2cbd3c6d;
  case 4:
    return 0x2cbd3c8f;
  default:
    return 0x50fe8c15;
  }
}


// ==== 0x504320 GarageManager::PushScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageManager__PushScreen(int param_1)

{
  int *in_EAX;
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = _malloc(0xc);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[2] = param_1;
  }
  iVar3 = *in_EAX;
  *in_EAX = (int)piVar1;
  *(int **)(iVar3 + 4) = piVar1;
  piVar1[1] = (int)in_EAX;
  *piVar1 = iVar3;
  uVar2 = GarageManager__GetMsgForNumScreensInList();
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int *)(iVar3 + 0x14) != 0)) {
    FUN_004f7c00(uVar2,0,0,*(int *)(iVar3 + 0x18));
  }
  return;
}


// ==== 0x504390 GarageManager::PopScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GarageManager__PopScreen(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int *in_EAX;
  undefined4 uVar3;
  int iVar4;
  
  _Memory = (int *)*in_EAX;
  if (_Memory != in_EAX) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    iVar1 = _Memory[2];
    _free(_Memory);
    uVar3 = GarageManager__GetMsgForNumScreensInList();
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int *)(iVar4 + 0x14) != 0)) {
      FUN_004f7c00(uVar3,0,0,*(int *)(iVar4 + 0x18));
    }
    return iVar1;
  }
  return 0;
}


// ==== 0x5043f0 GarageManager::PopAllScreensOfCertainName

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageManager__PopAllScreensOfCertainName(int param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *_Memory;
  int *in_EAX;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  
  piVar3 = (int *)*in_EAX;
  if (piVar3 != in_EAX) {
    piVar5 = (int *)NullUpdate_ret();
    while (_Memory = piVar3, _Memory != piVar5) {
      pcVar6 = (char *)_Memory[2];
      piVar3 = (int *)*_Memory;
      iVar7 = param_1 - (int)pcVar6;
      do {
        cVar1 = pcVar6[iVar7];
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if (cVar1 == cVar2) {
        piVar4 = (int *)_Memory[1];
        *piVar4 = (int)piVar3;
        piVar3[1] = (int)piVar4;
        _free(_Memory);
      }
    }
  }
  return;
}


// ==== 0x504450 GarageManager::PreviewPart

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageManager__PreviewPart(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x72c) = param_1;
  *(undefined4 *)(param_2 + 0x45c + in_EAX * 4) = param_1;
  *(char *)(param_2 + 0x63c + in_EAX) = *(char *)(param_2 + 0x63c + in_EAX) + '\x01';
  RideInfo__UpdatePartsEnabled(param_2 + 0x10);
  iVar1 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,param_2 + 0x10);
  _DAT_0072cc80 = 2;
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
  }
  return;
}


// ==== 0x5044b0 GarageManager::InstallPart

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageManager__InstallPart(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  
  iVar1 = in_EAX + 0x730;
  *(undefined4 *)(in_EAX + 0x72c) = 0;
  FECarConfig__BuildRide(*(undefined4 *)(in_EAX + 8),0,iVar1);
  *(undefined4 *)(in_EAX + 0xb7c + unaff_EBX * 4) = param_1;
  *(char *)(in_EAX + 0xd5c + unaff_EBX) = *(char *)(in_EAX + 0xd5c + unaff_EBX) + '\x01';
  RideInfo__UpdatePartsEnabled(iVar1);
  FECarConfig__FillFromRide(*(undefined4 *)(in_EAX + 8),iVar1);
  RideInfo__operator_(in_EAX + 0x10,iVar1);
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,iVar1);
  _DAT_0072cc80 = 2;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
  }
  FUN_0051b060();
  return;
}


// ==== 0x504550 GetBrakeForPerfUpgrade

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GetBrakeForPerfUpgrade(char param_1)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  
  piVar5 = DAT_0073ad40;
  pcVar4 = "BRAKES";
  iVar6 = -1;
  uVar3 = 0x42;
  do {
    iVar6 = iVar6 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  piVar2 = (int *)NullUpdate_ret();
  if (piVar5 != piVar2) {
    while( true ) {
      uVar3 = piVar5[3];
      uVar7 = piVar5[4] * 0x30 + uVar3;
      if ((iVar6 != 0) && (uVar3 = BinarySearch_Hash(iVar6,uVar3,4), uVar3 == 0)) break;
      for (; uVar3 < uVar7; uVar3 = uVar3 + 0x30) {
        if ((iVar6 != 0) && (*(int *)(uVar3 + 4) != iVar6)) goto LAB_005045dd;
        if (*(char *)(uVar3 + 0x10) == '\x10') goto LAB_005045e0;
      }
      piVar5 = (int *)*piVar5;
      if (piVar5 == piVar2) break;
    }
  }
LAB_005045dd:
  uVar3 = 0;
LAB_005045e0:
  for (; (uVar3 != 0 && (*(char *)(uVar3 + 0x11) != param_1));
      uVar3 = CarPartDatabase__GetCarPart(iVar6,0x10,0,uVar3,0xffffffff)) {
    pcVar4 = "BRAKES";
    iVar6 = -1;
    uVar7 = 0x42;
    do {
      iVar6 = iVar6 * 0x21 + uVar7;
      pbVar1 = (byte *)(pcVar4 + 1);
      uVar7 = (uint)*pbVar1;
      pcVar4 = pcVar4 + 1;
    } while (*pbVar1 != 0);
  }
  return;
}


// ==== 0x504630 FindPartWithLevel

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int FindPartWithLevel(undefined4 param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int unaff_EDI;
  
  iVar3 = DAT_00734588;
  uVar4 = 0;
  if (unaff_EDI != 0x23) {
    if (unaff_EDI * 0xc90 + DAT_00734588 == 0) {
      return 0;
    }
    uVar4 = bStringHash();
  }
  iVar5 = CarPartDatabase__GetCarPart(uVar4,param_1,0,0,0xffffffff);
  while( true ) {
    if (iVar5 == 0) {
      return 0;
    }
    if (*(byte *)(iVar5 + 0x11) == param_2) break;
    iVar6 = 0;
    if (unaff_EDI != 0x23) {
      iVar6 = unaff_EDI * 0xc90 + iVar3;
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        pbVar7 = (byte *)(iVar6 + 0x20);
        iVar6 = -1;
        bVar2 = *pbVar7;
        while (bVar2 != 0) {
          iVar6 = iVar6 * 0x21 + (uint)bVar2;
          pbVar1 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
      }
    }
    iVar5 = CarPartDatabase__GetCarPart(iVar6,param_1,0,iVar5,0xffffffff);
  }
  return iVar5;
}


// ==== 0x5046d0 GarageManager::PreviewPhysicsUpgrade

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageManager__PreviewPhysicsUpgrade(int param_1,int param_2)

{
  uint in_EAX;
  int iVar1;
  
  *(uint *)(param_2 + 0x18 + param_1 * 4) = in_EAX;
  if (param_1 == 8) {
    GetBrakeForPerfUpgrade();
    GarageManager__PreviewPart();
    iVar1 = FUN_004b2330();
  }
  else {
    if (param_1 != 2) goto LAB_00504753;
    if (0 < (int)in_EAX) {
      FECarConfig__GetCarType(0xc,in_EAX & 0xff);
      FindPartWithLevel();
    }
    GarageManager__PreviewPart();
    iVar1 = FUN_004b2330();
  }
  if (iVar1 != 0) {
    FUN_004b0150();
  }
LAB_00504753:
  iVar1 = FindPartWithLevel(0xc,*(undefined4 *)(param_2 + 0x20));
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x48c) = iVar1;
    *(char *)(param_2 + 0x648) = *(char *)(param_2 + 0x648) + '\x01';
    RideInfo__UpdatePartsEnabled(param_2 + 0x10);
  }
  RideInfo__RebuildPhysicsInfo(1);
  iVar1 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,param_2 + 0x10);
  _DAT_0072cc80 = 2;
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
  }
  return;
}


// ==== 0x5047d0 GarageManager::InstallPhysicsUpgrade

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageManager__InstallPhysicsUpgrade(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(*(int *)(param_2 + 8) + 0x2e0 + in_EAX * 4) = param_1;
  if (in_EAX == 8) {
    uVar4 = 0;
    uVar2 = GetBrakeForPerfUpgrade(param_1,0);
    GarageManager__InstallPart(uVar2,uVar4);
  }
  iVar1 = param_2 + 0x730;
  FECarConfig__BuildRide(*(undefined4 *)(param_2 + 8),0,iVar1);
  iVar3 = FindPartWithLevel(0xc,*(undefined4 *)(param_2 + 0x740));
  if (iVar3 != 0) {
    *(int *)(param_2 + 0xbac) = iVar3;
    *(char *)(param_2 + 0xd68) = *(char *)(param_2 + 0xd68) + '\x01';
    RideInfo__UpdatePartsEnabled(iVar1);
  }
  RideInfo__RebuildPhysicsInfo(1);
  RideInfo__operator_(param_2 + 0x10,iVar1);
  iVar3 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,iVar1);
  _DAT_0072cc80 = 2;
  if (iVar3 != 0) {
    GarageMainScreen__SetRideInfo(iVar3,&DAT_00748850,2);
  }
  FUN_0051aed0();
  return;
}


// ==== 0x504890 GarageManager::SyncActualToEditing

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageManager__SyncActualToEditing(void)

{
  int in_EAX;
  int iVar1;
  
  RideInfo__operator_(in_EAX + 0x10,in_EAX + 0x730);
  iVar1 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,in_EAX + 0x730);
  _DAT_0072cc80 = 2;
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
  }
  return;
}


// ==== 0x5048e0 ShowHideNewlyUnlockedMarker_int_

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void ShowHideNewlyUnlockedMarker_int_(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (in_EAX == 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_00504977;
    }
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0xf9095d3c);
      FEObject__SetInvisible(uVar2);
      return;
    }
    iVar1 = 0;
LAB_00504977:
    FEObject__SetInvisible(iVar1);
    return;
  }
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    iVar1 = FUN_004ffb70();
    if (iVar1 != 0) goto LAB_0050492b;
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xf9095d3c);
    FEObject__SetVisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_0050492b:
  FEObject__SetVisible(iVar1);
  return;
}


// ==== 0x504990 LaunchPartsBrowser

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void LaunchPartsBrowser(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 unaff_EBX;
  
  FUN_004b2480();
  DAT_00744ff8 = in_EAX;
  FECarConfig__BuildRide(in_EAX,0,&DAT_00745000);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  GarageManager__PushScreen(unaff_EBX);
  iVar1 = DAT_0073578c;
  DAT_00745e40 = param_1;
  if (param_3 != '\0') {
    FEManager__ShowPackage();
    return;
  }
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return;
}


// ==== 0x504a20 LaunchPartsBrowserNoShowFlag

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void LaunchPartsBrowserNoShowFlag
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  
  FUN_004b2480();
  DAT_00744ff8 = in_EAX;
  FECarConfig__BuildRide(in_EAX,0,&DAT_00745000);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  GarageManager__PushScreen(param_4);
  iVar1 = DAT_0073578c;
  DAT_00745e40 = param_1;
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return;
}


// ==== 0x504ab0 GarageScreen::_GarageScreen

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall GarageScreen___GarageScreen(undefined4 *param_1)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068731e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_GarageScreen__scalar_deleting_destructor_006c0264;
  local_4 = 2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0xa1f0e37d,0,0,*(int *)(iVar2 + 0x18));
  }
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar2 = *_Memory;
    piVar1 = (int *)_Memory[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x504b60 GarageScreen::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageScreen__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageScreen___GarageScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x504b80 CreateGarageScreen

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 CreateGarageScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689093;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageScreen__GarageScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x504be0 GarageScreen::GarageScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageScreen__GarageScreen(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GarageScreen__scalar_deleting_destructor_006c0264;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined1 *)(param_1 + 0x22) = 0;
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar5 == 0) || (*(int *)(iVar5 + 0x18) == 0)) {
    FEngPushGarageMainPackage();
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 == 0) || (*(int *)(iVar5 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar2 = *(int *)(DAT_0073578c + 8);
    iVar5 = iVar2 + 0xdc;
    if ((iVar5 == 0) || (iVar5 = FUN_004fd1e0(iVar5), iVar5 == 0)) {
      cFEng__PushPackage(iVar2,"MU_HorizontalBrowserBack.fng",0x10,0);
    }
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int **)(iVar5 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar5 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar5 + 0x18));
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int **)(iVar5 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar5 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar5 + 0x18));
  }
  if (((DAT_00760288 == 0) && (DAT_0076028c == 0)) &&
     (((DAT_00760290 == 0 && ((DAT_00760294 == 0 && (DAT_00760298 == 0)))) &&
      ((DAT_00760284 & 0x1000) == 0)))) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (((DAT_00745e40 == 1) && (((byte)DAT_00760284 >> 1 & 1) != 0)) || (param_2 = 0, bVar4)) {
    param_2 = 1;
  }
  if ((DAT_00745e40 != 1) || (local_14 = 1, (DAT_00760284 & 1) == 0)) {
    local_14 = 0;
  }
  pcVar7 = "BROWSER_VISUAL";
  do {
    pcVar1 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar1 != '\0');
  GarageScreen__AddCategory(0x80f95bd3,"MU_GaragePartsChooseVisual.fng",param_2);
  pcVar7 = "BROWSER_PERFORMANCE";
  do {
    pcVar1 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar1 != '\0');
  GarageScreen__AddCategory(0x2d0e7f1,"MU_GaragePerformanceCategory.fng",local_14);
  if (DAT_00745e40 != 1) {
    pcVar7 = "BROWSER_PRESETS";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageScreen__AddCategory(0xd730ca44,"MU_GaragePresets.fng",0);
    pcVar7 = "BROWSER_PRESETS";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageScreen__AddCategory(0xac20c713,"MU_GaragePresets.fng",0);
    if (DAT_00745e40 != 1) goto LAB_00504ebb;
  }
  pcVar7 = "BROWSER_TRADE_IN";
  do {
    pcVar1 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar1 != '\0');
  GarageScreen__AddCategory(0x55da25c5,"MU_UG_TradeCareerCar.fng",0);
LAB_00504ebb:
  puVar3 = (undefined4 *)param_1[0x11];
  do {
    if (puVar3 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_00504ee3:
      FUN_004f8960();
      FUN_00495f00(*(undefined4 *)(param_1[0x10] + 0xc));
      ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
      *(undefined1 *)(param_1 + 8) = 1;
      iVar5 = FUN_004b2330();
      if (iVar5 != 0) {
        DAT_0074810c = DAT_0073ad3c;
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        SelectCarCameraMover__ResetAfterMagazine();
      }
      if (DAT_00735e38 == 0) {
        DAT_00735e38 = FUN_00565b60(0xf660,0,0,0);
        Ugd__PackBlock(&DAT_007588c4,0xf660);
      }
      if (DAT_00745e40 == 1) {
        if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
           (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
          if (DAT_0073578c == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(0x2c7d911e);
          }
        }
        FEObject__SetInvisible(iVar5);
        if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
           (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            uVar6 = FUN_004ef050(0xa936c3a2);
            FEObject__SetInvisible(uVar6);
            ExceptionList = local_10;
            return param_1;
          }
          iVar5 = 0;
        }
        FEObject__SetInvisible(iVar5);
      }
      else {
        if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
           (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
          if (DAT_0073578c == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(0x2c7d911e);
          }
        }
        FEObject__SetVisible(iVar5);
        if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
           (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
          if (DAT_0073578c == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(0xa936c3a2);
          }
        }
        FEObject__SetVisible(iVar5);
      }
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar3[2] == DAT_0073571c) {
      param_1[0x10] = puVar3;
      goto LAB_00504ee3;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x5050d0 GarageScreen::AddCategory

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageScreen__AddCategory(int param_1,int param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = FUN_004f8730(unaff_EDI + 0x4c,unaff_ESI,0,1);
  if (((unaff_EBX != 0) && (iVar2 != 0)) && (*(int *)(iVar2 + 0x24) != unaff_EBX)) {
    *(int *)(iVar2 + 0x24) = unaff_EBX;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  piVar3 = _malloc(0x18);
  piVar3[3] = param_1;
  *(undefined1 *)(piVar3 + 4) = param_3;
  piVar3[2] = unaff_ESI;
  piVar3[5] = param_2;
  puVar1 = *(undefined4 **)(unaff_EDI + 0x48);
  *puVar1 = piVar3;
  *(int **)(unaff_EDI + 0x48) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = unaff_EDI + 0x44;
  return;
}


// ==== 0x505130 GarageScreen::ScrollPartsCategory

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageScreen__ScrollPartsCategory(int param_1)

{
  int iVar1;
  int unaff_EBX;
  
  iVar1 = *(int *)(unaff_EBX + 0x40);
  if (param_1 == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EBX + 0x44)) && (*(int *)(unaff_EBX + 0x44) != unaff_EBX + 0x44)) {
      *(undefined4 *)(unaff_EBX + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((param_1 == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EBX + 0x40) != *(undefined4 **)(unaff_EBX + 0x48))) &&
          (*(int *)(unaff_EBX + 0x44) != unaff_EBX + 0x44)) {
    *(undefined4 *)(unaff_EBX + 0x40) = **(undefined4 **)(unaff_EBX + 0x40);
  }
  if (*(int *)(unaff_EBX + 0x40) != iVar1) {
    FUN_004f8910();
    FUN_00495f00(*(undefined4 *)(*(int *)(unaff_EBX + 0x40) + 0xc));
    ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
  }
  return;
}


// ==== 0x505200 GarageScreen::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageScreen__MoveForwardPackage(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  DAT_0073571c = *(int *)(*(int *)(in_EAX + 0x40) + 8);
  uVar3 = 0;
  if (*(int *)(*(int *)(in_EAX + 0x40) + 0x14) != 0) {
    GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
    iVar1 = DAT_0073578c;
    if (DAT_0073571c == 3) {
      DAT_00735dd4 = 0;
    }
    else if (DAT_0073571c == 2) {
      DAT_00735dd4 = 1;
    }
    uVar3 = *(undefined4 *)(in_EAX + 0xc);
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      uVar3 = 0;
      if (iVar2 != 0) {
        uVar3 = 0;
        if (*(int *)(iVar2 + 0x18) != 0) {
          uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
        }
      }
    }
  }
  return uVar3;
}


// ==== 0x505290 GarageScreen::MoveBackPackage

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageScreen__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FEngFindPackage();
  if ((iVar1 == 0) || (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xf9095d3c);
    }
  }
  FEObject__SetInvisible(iVar1);
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  DAT_00745e40 = 0;
  return uVar3;
}


// ==== 0x505330 GarageScreen::NotificationMessage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __thiscall GarageScreen__NotificationMessage(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_3c;
  int local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = DAT_00744ff8;
  if (*(char *)(param_1 + 0x88) == '\0') {
    if (param_2 < 0xaabbccde) {
      if (param_2 == 0xaabbccdd) {
        FECarConfig__GetCarType();
        FUN_004acb90();
        DAT_00744ff8 = uVar1;
        FECarConfig__BuildRide(uVar1,0,&DAT_00745000);
        FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
        GarageManager__SyncActualToEditing(0);
        return;
      }
      if (param_2 < 0x12342221) {
        if (param_2 != 0x12342220) {
          if (param_2 == 0xc407210) {
            GarageScreen__MoveForwardPackage();
            return;
          }
          if (param_2 != 0x12341110) {
            return;
          }
        }
      }
      else {
        if (param_2 != 0x911ab364) {
          if (param_2 != 0x9120409e) {
            return;
          }
          goto LAB_005053e5;
        }
        cVar2 = FUN_004c9570();
        if (cVar2 != '\0') {
          FUN_004c96f0(0x12341110,1);
          return;
        }
      }
      *(undefined1 *)(param_1 + 0x88) = 1;
      return;
    }
    if (param_2 < 0xc519bfc4) {
      if (param_2 == 0xc519bfc3) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        GenericDialogData__GenericDialogData();
        if (DAT_00777b4c == 1) {
          local_38 = -0x45ad421f;
        }
        else {
          iVar3 = bStrICmp();
          local_38 = (-(uint)(iVar3 != 0) & 0xe5c4c152) + 0x73a2dbf9;
        }
        local_18 = 1;
        local_3c = 0x169268;
        local_10 = 0;
        local_c = 0;
        local_14 = 0x639;
        FUN_004dcfd0(&local_3c,*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0xb5971bf1) {
LAB_005053e5:
        GarageScreen__ScrollPartsCategory(param_2,param_3);
        return;
      }
      if ((param_2 == 0xc519bfc0) && (DAT_00745e40 != 1)) {
        local_c = 0;
        local_8 = 0;
        local_28 = 0x76f0458f;
        local_24 = 0xf770;
        local_20 = 0xaabbccdd;
        local_1c = 0x61c;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0xb8a7c6cd;
        FUN_004dc6e0(&local_28,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else if (param_2 == 0xc98356ba) {
      FUN_004f89d0();
      FUN_004f7d30();
      if (DAT_00745e40 == 1) {
        FUN_004c96c0(0xd0687426);
      }
    }
  }
  else if ((param_2 == 0xc98356ba) &&
          ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0 ||
           (*(int *)(iVar3 + 0x18) == 0)))) {
    GarageScreen__MoveBackPackage(param_1);
    *(undefined1 *)(param_1 + 0x88) = 0;
    return;
  }
  return;
}


// ==== 0x5055c0 GarageChooseVisualCategoryScreen::_GarageChooseVisualCategoryScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall
GarageChooseVisualCategoryScreen___GarageChooseVisualCategoryScreen(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageChooseVisualCategoryScreen__scalar_deleting_destructor_006c0278;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x505610 GarageChooseVisualCategoryScreen::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall
GarageChooseVisualCategoryScreen__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageChooseVisualCategoryScreen___GarageChooseVisualCategoryScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x505630 FindPartListForCategory

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 * __fastcall FindPartListForCategory(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_00706530;
  do {
    if (*piVar2 == param_2) {
      return &DAT_00706530 + iVar1 * 7;
    }
    piVar2 = piVar2 + 7;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x70669c);
  return (undefined4 *)0x0;
}


// ==== 0x505660 CreateGarageVisualCategoryScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageVisualCategoryScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageChooseVisualCategoryScreen__GarageChooseVisualCategoryScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5056c0 AnyPartOwnedInCategory

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 AnyPartOwnedInCategory(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if (DAT_00735ec1 != '\0') {
    return 1;
  }
  iVar4 = CarPartDatabase__GetCarPart(0,param_1,0,0,0xffffffff);
  uVar2 = DAT_0073766c;
  do {
    if (iVar4 == 0) {
      return 0;
    }
    bVar1 = *(byte *)(iVar4 + 0x11);
    if ((bVar1 != 0) && (cVar3 = PartStore__HasPart(&DAT_0075f344), cVar3 != '\0')) {
      return 1;
    }
    if ((DAT_00745e40 == 2) && (uVar5 = 0, uVar2 != 0)) {
      puVar6 = (uint *)(DAT_00737668 + 0x24);
      do {
        if ((puVar6[-1] == 1) && (*puVar6 == (uint)bVar1)) {
          if (*(char *)(uVar5 * 0x34 + 0x30 + DAT_00737668) != '\0') {
            return 1;
          }
          break;
        }
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + 0xd;
      } while (uVar5 < uVar2);
    }
    iVar4 = CarPartDatabase__GetCarPart(0,param_1,0,iVar4,0xffffffff);
  } while( true );
}


// ==== 0x505780 GarageChooseVisualCategoryScreen::GarageChooseVisualCategoryScreen

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 *
GarageChooseVisualCategoryScreen__GarageChooseVisualCategoryScreen
          (undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  char *pcVar7;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GarageChooseVisualCategoryScreen__scalar_deleting_destructor_006c0278;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  if (DAT_00745e40 == 2) {
    cVar4 = FUN_004e3f40(0);
    *(char *)(param_1 + 0x22) = '\x01' - (cVar4 != '\0');
  }
  else {
    *(undefined1 *)(param_1 + 0x22) = 0;
  }
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 == 0) || (*(int *)(iVar6 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar2 = *(int *)(DAT_0073578c + 8);
    iVar6 = iVar2 + 0xdc;
    if ((iVar6 == 0) || (iVar6 = FUN_004fd1e0(iVar6), iVar6 == 0)) {
      cFEng__PushPackage(iVar2,"MU_HorizontalBrowserBack.fng",0x10,0);
    }
  }
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (*(int **)(iVar6 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar6 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar6 + 0x18));
  }
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (*(int **)(iVar6 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar6 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar6 + 0x18));
  }
  *(undefined1 *)((int)param_1 + 0x89) = 0;
  *(undefined1 *)((int)param_1 + 0x8a) = 0;
  *(undefined1 *)((int)param_1 + 0x8b) = 0;
  if (((DAT_00760288 != 0) || (DAT_0076028c != 0)) ||
     (((DAT_00760290 != 0 || ((DAT_00760294 != 0 || (DAT_00760298 != 0)))) ||
      (param_2 = 0, (DAT_00760284 & 0x1000) != 0)))) {
    param_2 = 1;
  }
  pcVar7 = "VISUAL_PART_BODY";
  if (DAT_00745e40 == 1) {
    bVar5 = (byte)DAT_00760284;
    local_14 = CONCAT31(local_14._1_3_,bVar5 >> 3) & 0xffffff01;
    local_18 = CONCAT31(local_18._1_3_,(char)(DAT_00760284 >> 8)) & 0xffffff01;
    local_1c = CONCAT31(local_1c._1_3_,bVar5 >> 4) & 0xffffff01;
    local_20 = CONCAT31(local_20._1_3_,bVar5 >> 5) & 0xffffff01;
    local_24 = CONCAT31(local_24._1_3_,bVar5 >> 6) & 0xffffff01;
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory
              (0x1371ad,"MU_GaragePartsCategoryVisual.fng",local_14);
    pcVar7 = "VISUAL_PART_RIMS";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory(0x1c1f5a,"MU_GarageRimsBrandBrowser.fng",local_18)
    ;
    pcVar7 = "VISUAL_PART_ACCESSORIES";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory
              (0xa12c3d13,"MU_GarageAccessoriesCategory.fng",local_1c);
    pcVar7 = "VISUAL_PART_PAINT";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory(0x377653b,"MU_GaragePaintMod.fng",local_20);
    pcVar7 = "VISUAL_PART_DECALS";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory(0x56ab04cb,"MU_GarageDecals_Zone.fng",local_24);
    pcVar7 = "VISUAL_PART_VINYL";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
  }
  else {
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory(0x1371ad,"MU_GaragePartsCategoryVisual.fng",0);
    if (*(char *)((int)param_1 + 0x8b) == '\0') {
      pcVar7 = "VISUAL_PART_RIMS";
      do {
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar1 != '\0');
      GarageChooseVisualCategoryScreen__AddCategory(0x1c1f5a,"MU_GarageRimsBrandBrowser.fng",0);
    }
    if (*(char *)((int)param_1 + 0x8a) == '\0') {
      pcVar7 = "VISUAL_PART_ACCESSORIES";
      do {
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar1 != '\0');
      GarageChooseVisualCategoryScreen__AddCategory(0xa12c3d13,"MU_GarageAccessoriesCategory.fng",0)
      ;
    }
    pcVar7 = "VISUAL_PART_PAINT";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory(0x377653b,"MU_GaragePaintMod.fng",0);
    pcVar7 = "VISUAL_PART_DECALS";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    GarageChooseVisualCategoryScreen__AddCategory(0x56ab04cb,"MU_GarageDecals_Zone.fng",0);
    if (*(char *)(param_1 + 0x22) != '\0') goto LAB_00505bf3;
    pcVar7 = "VISUAL_PART_VINYL";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
  }
  GarageChooseVisualCategoryScreen__AddCategory(0x3e871f1,"MU_GarageVinylLayerV2.fng",param_2);
LAB_00505bf3:
  puVar3 = (undefined4 *)param_1[0x11];
  do {
    if (puVar3 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_00505c14:
      FUN_004f8960();
      GarageChooseVisualCategoryScreen__RedrawHeader();
      _DAT_00746de0 = 0x41a00000;
      GarageManager__PopAllScreensOfCertainName("MU_GarageVinylLayerV2.fng");
      GarageManager__PopAllScreensOfCertainName("MU_GaragePartsChooseVisual.fng");
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar3[2] == DAT_00735718) {
      param_1[0x10] = puVar3;
      goto LAB_00505c14;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x505c70 GarageChooseVisualCategoryScreen::AddCategory

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageChooseVisualCategoryScreen__AddCategory(int param_1,int param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = FUN_004f8730(unaff_EDI + 0x4c,unaff_ESI,0,1);
  if (((unaff_EBX != 0) && (iVar2 != 0)) && (*(int *)(iVar2 + 0x24) != unaff_EBX)) {
    *(int *)(iVar2 + 0x24) = unaff_EBX;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  piVar3 = _malloc(0x18);
  piVar3[3] = param_1;
  piVar3[4] = param_2;
  piVar3[2] = unaff_ESI;
  *(undefined1 *)(piVar3 + 5) = param_3;
  puVar1 = *(undefined4 **)(unaff_EDI + 0x48);
  *puVar1 = piVar3;
  *(int **)(unaff_EDI + 0x48) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = unaff_EDI + 0x44;
  return;
}


// ==== 0x505cd0 GarageChooseVisualCategoryScreen::ScrollPartsCategory

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageChooseVisualCategoryScreen__ScrollPartsCategory(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (unaff_EBX == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EDI + 0x44)) && (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EBX == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48))) &&
          (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
  }
  if (*(int *)(unaff_EDI + 0x40) != iVar1) {
    FUN_004f8910();
    GarageChooseVisualCategoryScreen__RedrawHeader();
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x505d70 GarageChooseVisualCategoryScreen::RedrawHeader

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageChooseVisualCategoryScreen__RedrawHeader(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(in_EAX + 0x40);
  FUN_00495f00(*(undefined4 *)(iVar1 + 0xc));
  iVar1 = *(int *)(iVar1 + 8);
  if (((((iVar1 != 5) || (*(char *)(in_EAX + 0x88) == '\0')) &&
       ((iVar1 != 2 || (*(char *)(in_EAX + 0x8a) == '\0')))) &&
      ((iVar1 != 1 || (*(char *)(in_EAX + 0x8b) == '\0')))) &&
     ((iVar1 != 0 || (*(char *)(in_EAX + 0x89) == '\0')))) {
    FUN_00495f70();
    ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
    return;
  }
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_00505e21;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xa8a3681a);
    FEObject__SetVisible(uVar2);
    ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
    return;
  }
  iVar1 = 0;
LAB_00505e21:
  FEObject__SetVisible(iVar1);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  return;
}


// ==== 0x505e60 GarageChooseVisualCategoryScreen::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageChooseVisualCategoryScreen__MoveForwardPackage(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  DAT_00735718 = *(int *)(iVar1 + 8);
  if (((((DAT_00735718 == 5) && (*(char *)(param_1 + 0x88) != '\0')) ||
       ((DAT_00735718 == 2 && (*(char *)(param_1 + 0x8a) != '\0')))) ||
      ((DAT_00735718 == 0 && (*(char *)(param_1 + 0x89) != '\0')))) ||
     ((DAT_00735718 == 1 && (*(char *)(param_1 + 0x8b) != '\0')))) {
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
      return;
    }
  }
  else {
    if (DAT_00735718 == 0) {
      DAT_00735714 = 0;
    }
    else if (DAT_00735718 == 1) {
      FindPartListForCategory();
      iVar2 = FUN_004b2330();
      if (iVar2 != 0) {
        FUN_004b0150();
      }
    }
    if (*(int *)(iVar1 + 0x10) != 0) {
      switch(DAT_00735718) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
      }
      EAXSound__PlayUISoundFX();
      GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x505fb0 GarageChooseVisualCategoryScreen::MoveBackPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageChooseVisualCategoryScreen__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x506000 GarageChooseVisualCategoryScreen::NotificationMessage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __thiscall
GarageChooseVisualCategoryScreen__NotificationMessage(int param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        DAT_00735718 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
        GarageChooseVisualCategoryScreen__MoveForwardPackage(param_1);
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageChooseVisualCategoryScreen__MoveBackPackage(param_1);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004f89d0();
    FUN_004f7d30();
    GarageChooseVisualCategoryScreen__RedrawHeader();
    return;
  }
  GarageChooseVisualCategoryScreen__ScrollPartsCategory(param_3);
  return;
}


// ==== 0x506090 GarageCategoryVisual::_GarageCategoryVisual

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageCategoryVisual___GarageCategoryVisual(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageCategoryVisual__scalar_deleting_destructor_006c0298;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x5060e0 GarageCategoryVisual::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageCategoryVisual__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageCategoryVisual___GarageCategoryVisual();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x506100 CreateGarageCategoryVisual

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageCategoryVisual(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689023;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageCategoryVisual__GarageCategoryVisual(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x506160 GarageCategoryVisual::IsWidebodyInstalled

/* [canon] car med (ghidra-canon) docs/re/tuning.md */

uint GarageCategoryVisual__IsWidebodyInstalled(void)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = 0;
  piVar2 = &DAT_00706530;
  do {
    if (*piVar2 == 0xc) {
      puVar5 = &DAT_00706530 + iVar4 * 7;
      goto LAB_00506179;
    }
    piVar2 = piVar2 + 7;
    iVar4 = iVar4 + 1;
  } while ((int)piVar2 < 0x70669c);
  puVar5 = (undefined4 *)0x0;
LAB_00506179:
  pcVar7 = "VAPOR";
  iVar4 = -1;
  uVar3 = 0x56;
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar6 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar6;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar6 != 0);
  pcVar7 = "MANTIS";
  iVar9 = -1;
  uVar3 = 0x4d;
  do {
    iVar9 = iVar9 * 0x21 + uVar3;
    pbVar6 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar6;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar6 != 0);
  puVar5 = (undefined4 *)(&DAT_00745b6c)[puVar5[4]];
  if (puVar5 == (undefined4 *)0x0) {
    return 0;
  }
  pbVar6 = (byte *)*puVar5;
  bVar1 = *pbVar6;
  uVar3 = CONCAT31((int3)((uint)puVar5 >> 8),bVar1);
  iVar8 = -1;
  while (bVar1 != 0) {
    iVar8 = iVar8 * 0x21 + (uVar3 & 0xff);
    bVar1 = pbVar6[1];
    uVar3 = (uint)bVar1;
    pbVar6 = pbVar6 + 1;
  }
  if (iVar8 == iVar4) {
    return CONCAT31((int3)(uVar3 >> 8),1);
  }
  return (byte)((iVar8 != iVar9) - 1) & 2;
}


// ==== 0x506210 GarageCategoryVisual::GarageCategoryVisual

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageCategoryVisual__GarageCategoryVisual(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined4 *puVar20;
  bool bVar21;
  bool bVar22;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GarageCategoryVisual__scalar_deleting_destructor_006c0298;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  puVar3 = param_1 + 0x13;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(puVar3,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 != 0) && (*(int *)(iVar9 + 0x18) != 0)) && (*(int **)(iVar9 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar9 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar9 + 0x18));
  }
  iVar9 = FECarConfig__GetCarType();
  pbVar10 = (byte *)(iVar9 * 0xc90 + DAT_00734588);
  iVar9 = -1;
  bVar2 = *pbVar10;
  while (bVar2 != 0) {
    iVar9 = iVar9 * 0x21 + (uint)bVar2;
    pbVar1 = pbVar10 + 1;
    pbVar10 = pbVar10 + 1;
    bVar2 = *pbVar1;
  }
  param_1[0x22] = iVar9;
  bVar21 = DAT_007677ac != 0;
  if (DAT_00745e40 != 1) {
    bVar22 = DAT_00745e40 == 2;
    if (((bVar21) || (bVar22)) || (cVar8 = AnyPartOwnedInCategory(1), cVar8 != '\0')) {
      iVar9 = FUN_004f8730(puVar3,0,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x739c4a1b)) {
        *(undefined4 *)(iVar9 + 0x24) = 0x739c4a1b;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      puVar12 = _malloc(0x18);
      puVar12[2] = 0;
      puVar12[3] = 0x3ea45dd2;
      *(undefined1 *)(puVar12 + 5) = 0;
      puVar12[4] = "MU_GaragePartsBrowser.fng";
      *(undefined1 *)((int)puVar12 + 0x15) = 0;
      puVar13 = (undefined4 *)param_1[0x12];
      *puVar13 = puVar12;
      param_1[0x12] = puVar12;
      puVar12[1] = puVar13;
      *puVar12 = param_1 + 0x11;
      if ((!bVar21) && (!bVar22)) goto LAB_005069d4;
LAB_005069e4:
      iVar9 = FUN_004f8730(puVar3,1,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x15c767c)) {
        *(undefined4 *)(iVar9 + 0x24) = 0x15c767c;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      piVar14 = _malloc(0x18);
      piVar14[2] = 1;
      piVar14[3] = 0xf456f53;
      *(undefined1 *)(piVar14 + 5) = 0;
      piVar14[4] = (int)"MU_GaragePartsBrowser.fng";
      *(undefined1 *)((int)piVar14 + 0x15) = 0;
      puVar13 = (undefined4 *)param_1[0x12];
      *puVar13 = piVar14;
      param_1[0x12] = piVar14;
      piVar14[1] = (int)puVar13;
      *piVar14 = (int)(param_1 + 0x11);
      if ((!bVar21) && (!bVar22)) goto LAB_00506a55;
LAB_00506a63:
      iVar9 = FUN_004f8730(puVar3,2,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x4e6c2af9)) {
        *(undefined4 *)(iVar9 + 0x24) = 0x4e6c2af9;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      piVar14 = _malloc(0x18);
      piVar14[2] = 2;
      piVar14[3] = 0x661de4f0;
      *(undefined1 *)(piVar14 + 5) = 0;
      piVar14[4] = (int)"MU_GaragePartsBrowser.fng";
      *(undefined1 *)((int)piVar14 + 0x15) = 0;
      puVar13 = (undefined4 *)param_1[0x12];
      *puVar13 = piVar14;
      param_1[0x12] = piVar14;
      piVar14[1] = (int)puVar13;
      *piVar14 = (int)(param_1 + 0x11);
      if ((!bVar21) && (!bVar22)) goto LAB_00506acd;
LAB_00506adb:
      iVar9 = FUN_004f8730(puVar3,3,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != -0x44fcb15a)) {
        *(undefined4 *)(iVar9 + 0x24) = 0xbb034ea6;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      piVar14 = _malloc(0x18);
      piVar14[2] = 3;
      piVar14[3] = -0x36c48c03;
      *(undefined1 *)(piVar14 + 5) = 0;
      piVar14[4] = (int)"MU_GaragePartsBrowser.fng";
      *(undefined1 *)((int)piVar14 + 0x15) = 0;
      puVar13 = (undefined4 *)param_1[0x12];
      *puVar13 = piVar14;
      param_1[0x12] = piVar14;
      piVar14[1] = (int)puVar13;
      *piVar14 = (int)(param_1 + 0x11);
      if ((!bVar21) && (!bVar22)) goto LAB_00506b45;
LAB_00506b53:
      iVar9 = FUN_004f8730(puVar3,4,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x28f7092)) {
        *(undefined4 *)(iVar9 + 0x24) = 0x28f7092;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      piVar14 = _malloc(0x18);
      piVar14[2] = 4;
      piVar14[3] = 0x16bd49;
      *(undefined1 *)(piVar14 + 5) = 0;
      piVar14[4] = (int)"MU_GaragePartsBrowser.fng";
      *(undefined1 *)((int)piVar14 + 0x15) = 0;
      puVar13 = (undefined4 *)param_1[0x12];
      *puVar13 = piVar14;
      param_1[0x12] = piVar14;
      piVar14[1] = (int)puVar13;
      *piVar14 = (int)(param_1 + 0x11);
      if (!bVar21) goto LAB_00506bb6;
LAB_00506bc4:
      iVar9 = FUN_004f8730(puVar3,8,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x79165861)) {
        *(undefined4 *)(iVar9 + 0x24) = 0x79165861;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      piVar14 = _malloc(0x18);
      *(undefined1 *)(piVar14 + 5) = 0;
      *(undefined1 *)((int)piVar14 + 0x15) = 0;
      piVar14[2] = 8;
      piVar14[3] = -0x6f37eda8;
      piVar14[4] = (int)"MU_GaragePartsBrowser.fng";
      puVar13 = (undefined4 *)param_1[0x12];
      *puVar13 = piVar14;
      param_1[0x12] = piVar14;
      piVar14[1] = (int)puVar13;
      *piVar14 = (int)(param_1 + 0x11);
    }
    else {
LAB_005069d4:
      cVar8 = AnyPartOwnedInCategory(2);
      if (cVar8 != '\0') goto LAB_005069e4;
LAB_00506a55:
      cVar8 = AnyPartOwnedInCategory(10);
      if (cVar8 != '\0') goto LAB_00506a63;
LAB_00506acd:
      cVar8 = AnyPartOwnedInCategory(0xb);
      if (cVar8 != '\0') goto LAB_00506adb;
LAB_00506b45:
      cVar8 = AnyPartOwnedInCategory(8);
      if (cVar8 != '\0') goto LAB_00506b53;
LAB_00506bb6:
      cVar8 = AnyPartOwnedInCategory(7);
      if (cVar8 != '\0') goto LAB_00506bc4;
    }
    cVar8 = AnyPartOwnedInCategory(6);
    if (cVar8 != '\0') {
      iVar9 = FUN_004f8730(puVar3,0xc,0,1);
      if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != -0x6ba1643b)) {
        *(undefined4 *)(iVar9 + 0x24) = 0x945e9bc5;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      piVar14 = _malloc(0x18);
      *(undefined1 *)(piVar14 + 5) = 0;
      *(undefined1 *)((int)piVar14 + 0x15) = 0;
      piVar14[2] = 0xc;
      piVar14[3] = 0xb4e4315;
      piVar14[4] = (int)"MU_GaragePartsBrowser.fng";
      puVar3 = (undefined4 *)param_1[0x12];
      *puVar3 = piVar14;
      param_1[0x12] = piVar14;
      piVar14[1] = (int)puVar3;
      *piVar14 = (int)(param_1 + 0x11);
    }
    goto LAB_005068ee;
  }
  uVar15 = DAT_00760284 >> 0xe;
  uVar7 = DAT_00760284 >> 0x10;
  uVar16 = DAT_00760284 >> 10;
  uVar17 = DAT_00760284 >> 0xd;
  uVar18 = DAT_00760284 >> 0x11;
  uVar11 = DAT_00760284 >> 0x14;
  uVar19 = DAT_00760284 >> 0x12;
  if (((((DAT_00735ec1 != '\0') || (bVar21)) ||
       (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
      ((cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,9), cVar8 != '\0' ||
       (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')))) ||
     ((cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,9), cVar8 != '\0' ||
      ((cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0' ||
       (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,9), cVar8 != '\0')))))) {
    bVar22 = true;
    if ((DAT_00735ec1 == '\0') && (!bVar21)) goto LAB_005063d8;
LAB_0050644f:
    bVar4 = true;
    if ((DAT_00735ec1 == '\0') && (!bVar21)) goto LAB_00506468;
LAB_00506508:
    bVar6 = true;
    if ((DAT_00735ec1 == '\0') && (!bVar21)) goto LAB_00506521;
LAB_005065c1:
    bVar5 = true;
    if ((DAT_00735ec1 == '\0') && (!bVar21)) goto LAB_005065d2;
LAB_00506633:
    bVar21 = true;
  }
  else {
    bVar22 = false;
LAB_005063d8:
    cVar8 = EasterEggs__IsPartUnlocked();
    if ((((cVar8 != '\0') || (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0xb), cVar8 != '\0'))
        || (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
       (((cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0xb), cVar8 != '\0' ||
         (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
        (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0xb), cVar8 != '\0')))) goto LAB_0050644f;
    bVar4 = false;
LAB_00506468:
    cVar8 = EasterEggs__IsPartUnlocked();
    if ((((cVar8 != '\0') || (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0')) ||
        (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
       (((cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0' ||
         (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
        ((cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0' ||
         ((cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0' ||
          (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0'))))))))
    goto LAB_00506508;
    bVar6 = false;
LAB_00506521:
    cVar8 = EasterEggs__IsPartUnlocked();
    if ((((((cVar8 != '\0') || (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,5), cVar8 != '\0'))
          || (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
         ((cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0' ||
          (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')))) ||
        (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0')) ||
       ((cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0' ||
        (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,8), cVar8 != '\0')))) goto LAB_005065c1;
    bVar5 = false;
LAB_005065d2:
    cVar8 = EasterEggs__IsPartUnlocked();
    if ((((cVar8 != '\0') || (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0xd), cVar8 != '\0'))
        || (cVar8 = EasterEggs__IsPartUnlocked(), cVar8 != '\0')) ||
       (cVar8 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0xd), cVar8 != '\0')) goto LAB_00506633;
    cVar8 = EasterEggs__IsPartUnlocked();
    bVar21 = false;
    if (cVar8 != '\0') goto LAB_00506633;
  }
  iVar9 = FUN_004f8730(puVar3,0,0,1);
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x739c4a1b)) {
    *(undefined4 *)(iVar9 + 0x24) = 0x739c4a1b;
    *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
  }
  puVar12 = _malloc(0x18);
  *(byte *)(puVar12 + 5) = (byte)uVar15 & 1;
  puVar12[2] = 0;
  puVar12[3] = 0x3ea45dd2;
  *(bool *)((int)puVar12 + 0x15) = !bVar22;
  puVar20 = param_1 + 0x11;
  puVar12[4] = "MU_GaragePartsBrowser.fng";
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = puVar12;
  param_1[0x12] = puVar12;
  puVar12[1] = puVar13;
  *puVar12 = puVar20;
  iVar9 = FUN_004f8730(puVar3,1,0,1);
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x15c767c)) {
    *(undefined4 *)(iVar9 + 0x24) = 0x15c767c;
    *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
  }
  puVar12 = _malloc(0x18);
  *(byte *)(puVar12 + 5) = (byte)uVar7 & 1;
  puVar12[2] = 1;
  puVar12[3] = 0xf456f53;
  puVar12[4] = "MU_GaragePartsBrowser.fng";
  *(bool *)((int)puVar12 + 0x15) = !bVar4;
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = puVar12;
  param_1[0x12] = puVar12;
  puVar12[1] = puVar13;
  *puVar12 = puVar20;
  iVar9 = FUN_004f8730(puVar3,2,0,1);
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x4e6c2af9)) {
    *(undefined4 *)(iVar9 + 0x24) = 0x4e6c2af9;
    *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
  }
  puVar12 = _malloc(0x18);
  *(byte *)(puVar12 + 5) = (byte)uVar16 & 1;
  puVar12[2] = 2;
  puVar12[3] = 0x661de4f0;
  puVar12[4] = "MU_GaragePartsBrowser.fng";
  *(bool *)((int)puVar12 + 0x15) = !bVar5;
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = puVar12;
  param_1[0x12] = puVar12;
  puVar12[1] = puVar13;
  *puVar12 = puVar20;
  iVar9 = FUN_004f8730(puVar3,3,0,1);
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != -0x44fcb15a)) {
    *(undefined4 *)(iVar9 + 0x24) = 0xbb034ea6;
    *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
  }
  puVar12 = _malloc(0x18);
  *(byte *)(puVar12 + 5) = (byte)uVar17 & 1;
  puVar12[2] = 3;
  puVar12[3] = 0xc93b73fd;
  puVar12[4] = "MU_GaragePartsBrowser.fng";
  *(bool *)((int)puVar12 + 0x15) = !bVar6;
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = puVar12;
  param_1[0x12] = puVar12;
  puVar12[1] = puVar13;
  *puVar12 = puVar20;
  iVar9 = FUN_004f8730(puVar3,4,0,1);
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x28f7092)) {
    *(undefined4 *)(iVar9 + 0x24) = 0x28f7092;
    *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
  }
  puVar12 = _malloc(0x18);
  puVar12[2] = 4;
  puVar12[3] = 0x16bd49;
  *(byte *)(puVar12 + 5) = (byte)uVar18 & 1;
  puVar12[4] = "MU_GaragePartsBrowser.fng";
  *(undefined1 *)((int)puVar12 + 0x15) = 0;
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = puVar12;
  param_1[0x12] = puVar12;
  puVar12[1] = puVar13;
  *puVar12 = puVar20;
  iVar9 = FUN_004f8730(puVar3,8,0,1);
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != 0x79165861)) {
    *(undefined4 *)(iVar9 + 0x24) = 0x79165861;
    *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
  }
  puVar12 = _malloc(0x18);
  *(byte *)(puVar12 + 5) = (byte)uVar19 & 1;
  puVar12[2] = 8;
  puVar12[3] = 0x90c81258;
  puVar12[4] = "MU_GaragePartsBrowser.fng";
  *(bool *)((int)puVar12 + 0x15) = !bVar21;
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = puVar12;
  param_1[0x12] = puVar12;
  puVar12[1] = puVar13;
  *puVar12 = puVar20;
  cVar8 = AnyPartOwnedInCategory(6);
  if (cVar8 != '\0') {
    iVar9 = FUN_004f8730(puVar3,0xc,0,1);
    if ((iVar9 != 0) && (*(int *)(iVar9 + 0x24) != -0x6ba1643b)) {
      *(undefined4 *)(iVar9 + 0x24) = 0x945e9bc5;
      *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
    }
    puVar13 = _malloc(0x18);
    puVar13[2] = 0xc;
    puVar13[3] = 0xb4e4315;
    *(byte *)(puVar13 + 5) = (byte)uVar11 & 1;
    puVar13[4] = "MU_GaragePartsBrowser.fng";
    *(undefined1 *)((int)puVar13 + 0x15) = 0;
    puVar3 = (undefined4 *)param_1[0x12];
    *puVar3 = puVar13;
    param_1[0x12] = puVar13;
    puVar13[1] = puVar3;
    *puVar13 = puVar20;
  }
LAB_005068ee:
  puVar3 = (undefined4 *)param_1[0x11];
  do {
    if (puVar3 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_00506912:
      GarageCategoryVisual__RefreshGrayedThumbsForWidebodyConflict();
      FUN_004f8960();
      GarageCategoryVisual__RedrawHeading();
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar3[2] == DAT_00735714) {
      param_1[0x10] = puVar3;
      goto LAB_00506912;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x506ca0 GarageCategoryVisual::RedrawHeading

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageCategoryVisual__RedrawHeading(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = *(int *)(in_EAX + 0x40);
  iVar2 = GarageCategoryVisual__GetNumPartsAvailable(in_EAX);
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0xc);
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0xc);
  }
  FUN_00495f00(uVar3);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_00506d71:
      if (DAT_0073578c == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004ef050(0xa8a3681a);
      }
    }
    else {
      iVar1 = FEngFindPackage();
      if (iVar1 == 0) goto LAB_00506d71;
      iVar1 = FUN_004ffb70();
      if (iVar1 == 0) goto LAB_00506d71;
    }
    FEObject__SetInvisible(iVar1);
    goto LAB_00506d93;
  }
  if (*(int *)(in_EAX + 0xc) == 0) {
LAB_00506d28:
    if (DAT_0073578c != 0) {
      uVar3 = FUN_004ef050(0xa8a3681a);
      FEObject__SetVisible(uVar3);
      goto LAB_00506d93;
    }
    iVar1 = 0;
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_00506d28;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_00506d28;
  }
  FEObject__SetVisible(iVar1);
LAB_00506d93:
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  return;
}


// ==== 0x506db0 GarageCategoryVisual::RefreshGrayedThumbsForWidebodyConflict

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageCategoryVisual__RefreshGrayedThumbsForWidebodyConflict(void)

{
  undefined4 *puVar1;
  char cVar2;
  int in_EAX;
  int *piVar3;
  
  cVar2 = GarageCategoryVisual__IsWidebodyInstalled();
  puVar1 = *(undefined4 **)(in_EAX + 0x44);
  piVar3 = *(int **)(in_EAX + 0x50);
  if (piVar3 != (int *)(in_EAX + 0x50)) {
    do {
      if (puVar1[2] == piVar3[2]) goto joined_r0x00506de1;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)(in_EAX + 0x50));
  }
  piVar3 = (int *)0x0;
joined_r0x00506de1:
  for (; puVar1 != (undefined4 *)(in_EAX + 0x44); puVar1 = (undefined4 *)*puVar1) {
    if ((-1 < (int)puVar1[2]) && ((int)puVar1[2] < 3)) {
      *(bool *)(piVar3 + 6) = cVar2 != '\0';
    }
    piVar3 = (int *)*piVar3;
  }
  return;
}


// ==== 0x506e10 GarageCategoryVisual::ScrollPickables

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageCategoryVisual__ScrollPickables(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (unaff_EBX == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EDI + 0x44)) && (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EBX == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48))) &&
          (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    FUN_004f8910();
    GarageCategoryVisual__RedrawHeading();
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x506eb0 GarageCategoryVisual::GetNumPartsAvailable

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

int __fastcall
GarageCategoryVisual__GetNumPartsAvailable(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = 0;
  piVar4 = &DAT_00706530;
  while (*piVar4 != param_2) {
    piVar4 = piVar4 + 7;
    iVar2 = iVar2 + 1;
    if (0x70669b < (int)piVar4) {
      return 0;
    }
  }
  if (iVar2 * 0x1c == -0x706530) {
    return 0;
  }
  iVar1 = (&DAT_00706540)[iVar2 * 7];
  if (iVar1 == -1) {
    return 0;
  }
  iVar3 = FUN_0057cf20(&DAT_0073ad40,*(undefined4 *)(param_3 + 0x88),iVar1,0);
  iVar2 = *(int *)(iVar2 * 0x1c + 0x706548);
  if (iVar2 != 0) {
    iVar2 = FUN_0057cf20(&DAT_0073ad40,iVar2,iVar1,0);
    iVar3 = iVar3 + iVar2;
  }
  return iVar3;
}


// ==== 0x506f30 GarageCategoryVisual::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageCategoryVisual__MoveForwardPackage(void)

{
  undefined4 uVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(in_EAX + 0x40);
  cVar2 = GarageCategoryVisual__IsWidebodyInstalled();
  if (((cVar2 == '\0') || (*(int *)(iVar3 + 8) < 0)) || (2 < *(int *)(iVar3 + 8))) {
    if (*(int *)(iVar3 + 0x10) != 0) {
      uVar1 = *(undefined4 *)(iVar3 + 8);
      iVar3 = GarageCategoryVisual__GetNumPartsAvailable(in_EAX);
      if (iVar3 < 1) {
        if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
          (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
        }
      }
      else {
        DAT_00735720 = *(undefined4 *)(in_EAX + 0x88);
        DAT_00735714 = uVar1;
        DAT_00735724 = uVar1;
        GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
        iVar3 = DAT_0073578c;
        if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0))
           && (*(int *)(iVar4 + 0x18) != 0)) {
          FUN_004f0800(*(undefined4 *)(iVar3 + 8),*(int *)(iVar4 + 0x18));
          return;
        }
      }
    }
  }
  else if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
    (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
    return;
  }
  return;
}


// ==== 0x507020 GarageCategoryVisual::MoveBackPackage

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageCategoryVisual__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x507070 GarageCategoryVisual::NotificationMessage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __thiscall GarageCategoryVisual__NotificationMessage(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  local_8 = param_1;
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 != 0xc407210) {
        if (param_2 != 0x911ab364) {
          return;
        }
        GarageCategoryVisual__MoveBackPackage(param_1);
        return;
      }
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x15) != '\0') {
        return;
      }
      iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 8);
      FindPartListForCategory();
      iVar2 = GarageCategoryVisual__GetNumPartsAvailable(param_1);
      if (iVar2 < 1) {
        return;
      }
      cVar1 = GarageCategoryVisual__IsWidebodyInstalled();
      if (((cVar1 != '\0') && (-1 < iVar3)) && (iVar3 < 3)) {
        GenericDialogData__GenericDialogData();
        local_14 = 0;
        local_10 = 0;
        local_3c = 0x16a674de;
        local_1c = 1;
        local_40 = 0xdd070611;
        local_18 = 0x639;
        FUN_004dcfd0(&local_40,*(undefined4 *)(param_1 + 0xc));
        GarageCategoryVisual__MoveForwardPackage();
        return;
      }
      iVar3 = FUN_004b2330();
      if (iVar3 != 0) {
        FUN_004b0150();
      }
      GarageCategoryVisual__MoveForwardPackage();
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004f89d0();
    FUN_004f7d30();
    return;
  }
  GarageCategoryVisual__ScrollPickables();
  return;
}


// ==== 0x5071b0 GaragePartsBrowser::_GaragePartsBrowser

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall GaragePartsBrowser___GaragePartsBrowser(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GaragePartsBrowser__scalar_deleting_destructor_006c0234;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x507200 GaragePartsBrowser::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GaragePartsBrowser__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GaragePartsBrowser___GaragePartsBrowser();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x507220 CreateGaragePartsBrowser

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 CreateGaragePartsBrowser(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689003;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GaragePartsBrowser__GaragePartsBrowser(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x507280 GaragePartsBrowser::AddPickable

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GaragePartsBrowser__AddPickable(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 unaff_BL;
  
  piVar3 = _malloc(0x1c);
  piVar3[3] = param_1;
  piVar3[2] = (int)piVar3;
  piVar3[4] = 0;
  piVar3[5] = param_3;
  puVar2 = *(undefined4 **)(in_EAX + 0x48);
  *puVar2 = piVar3;
  *(int **)(in_EAX + 0x48) = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = in_EAX + 0x44;
  iVar4 = FUN_004f8730(in_EAX + 0x4c,piVar3[2],0,1);
  iVar5 = Texture_FindByHash(param_2,0,0);
  if (iVar5 == 0) {
    pcVar7 = "GENERICPLACEHOLDER";
    iVar5 = -1;
    uVar6 = 0x47;
    do {
      iVar5 = iVar5 * 0x21 + uVar6;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar6 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != iVar5)) {
      *(int *)(iVar4 + 0x24) = iVar5;
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    }
  }
  else if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != param_2)) {
    *(int *)(iVar4 + 0x24) = param_2;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    *(undefined1 *)(piVar3 + 6) = unaff_BL;
    return;
  }
  *(undefined1 *)(piVar3 + 6) = unaff_BL;
  return;
}


// ==== 0x507340 IsMagicSpoilerSpecialCase

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsMagicSpoilerSpecialCase(void)

{
  char *pcVar1;
  byte *pbVar2;
  char *pcVar3;
  byte bVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  iVar7 = FECarConfig__GetCarType();
  if (((iVar7 == 0) || (iVar7 == 1)) || (iVar7 == 5)) {
    return 0;
  }
  iVar10 = 0;
  if (iVar7 != 0x23) {
    if (iVar7 * 0xc90 + DAT_00734588 == 0) {
      uVar11 = 0;
      goto LAB_00507405;
    }
    iVar10 = bStringHash();
  }
  puVar5 = DAT_0073ad40;
  puVar8 = (undefined4 *)NullUpdate_ret();
  for (; puVar5 != puVar8; puVar5 = (undefined4 *)*puVar5) {
    uVar11 = puVar5[3];
    uVar12 = puVar5[4] * 0x30 + uVar11;
    if ((iVar10 != 0) && (uVar11 = BinarySearch_Hash(iVar10,uVar11,4), uVar11 == 0)) break;
    for (; uVar11 < uVar12; uVar11 = uVar11 + 0x30) {
      if ((iVar10 != 0) && (*(int *)(uVar11 + 4) != iVar10)) goto LAB_00507401;
      if (*(char *)(uVar11 + 0x10) == '\v') goto LAB_00507405;
    }
  }
LAB_00507401:
  uVar11 = 0;
LAB_00507405:
  pcVar3 = (char *)(iVar7 * 0xc90 + DAT_00734588);
  cVar6 = *pcVar3;
  pcVar9 = pcVar3;
  while (cVar6 != '\0') {
    pcVar1 = pcVar9 + 1;
    pcVar9 = pcVar9 + 1;
    cVar6 = *pcVar1;
  }
  pcVar9 = "_STYLE03_SPOILER";
  do {
    pcVar1 = pcVar9 + 1;
    pcVar9 = pcVar9 + 1;
  } while (*pcVar1 != '\0');
  do {
    if (uVar11 == 0) {
      return 0;
    }
    if (*(char *)(uVar11 + 0x11) == '\x04') {
      pcVar9 = "NOHATCHBACK";
      iVar10 = -1;
      uVar12 = 0x4e;
      do {
        iVar10 = iVar10 * 0x21 + uVar12;
        pbVar2 = (byte *)(pcVar9 + 1);
        uVar12 = (uint)*pbVar2;
        pcVar9 = pcVar9 + 1;
      } while (*pbVar2 != 0);
      if ((*(int *)(uVar11 + 0xc) == iVar10) &&
         (cVar6 = PartStore__HasPart(&DAT_0075f344), cVar6 != '\0')) {
        return 1;
      }
    }
    iVar10 = 0;
    if (iVar7 != 0x23) {
      if (pcVar3 == (char *)0x0) {
        iVar10 = 0;
      }
      else {
        pcVar9 = pcVar3 + 0x20;
        iVar10 = -1;
        bVar4 = pcVar3[0x20];
        while (bVar4 != 0) {
          iVar10 = iVar10 * 0x21 + (uint)bVar4;
          pbVar2 = (byte *)(pcVar9 + 1);
          pcVar9 = pcVar9 + 1;
          bVar4 = *pbVar2;
        }
      }
    }
    uVar11 = CarPartDatabase__GetCarPart(iVar10,0xb,0,uVar11,0xffffffff);
  } while( true );
}


// ==== 0x5074d0 IsMagicSpoilerToHide

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

uint IsMagicSpoilerToHide(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  
  uVar3 = IsMagicSpoilerSpecialCase();
  if ((char)uVar3 == '\0') {
    return uVar3;
  }
  iVar4 = FECarConfig__GetCarType();
  pbVar5 = (byte *)(iVar4 * 0xc90 + DAT_00734588);
  iVar4 = -1;
  bVar2 = *pbVar5;
  while (bVar2 != 0) {
    iVar4 = iVar4 * 0x21 + (uint)bVar2;
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar6 = "_STYLE03_SPOILER";
  uVar3 = 0x5f;
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar5 = (byte *)(pcVar6 + 1);
    uVar3 = (uint)*pbVar5;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar5 != 0);
  return (uint)(*(int *)(param_1 + 8) == iVar4);
}


// ==== 0x507540 GaragePartsBrowser::GaragePartsBrowser

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GaragePartsBrowser__GaragePartsBrowser(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 extraout_ECX;
  char extraout_DL;
  char *pcVar16;
  uint uVar17;
  uint *puVar18;
  bool bVar19;
  undefined4 *local_1c;
  uint local_18;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar14 = param_1 + 0x11;
  *param_1 = &PTR_GaragePartsBrowser__scalar_deleting_destructor_006c0234;
  *puVar14 = puVar14;
  param_1[0x12] = puVar14;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined1 *)(param_1 + 0x27) = 0;
  FEngSetAllObjectsInPackageVisibility("MU_HorizontalBrowserBack.fng",1);
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 != 0) && (*(int *)(iVar9 + 0x18) != 0)) && (*(int **)(iVar9 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar9 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar9 + 0x18));
  }
  iVar9 = DAT_00735724;
  switch(DAT_00735724) {
  case 0:
    param_1[0xf] = 0xa913299a;
    break;
  case 1:
    param_1[0xf] = 0xada5e21b;
    break;
  case 2:
    param_1[0xf] = 0xc83af60b;
    break;
  case 3:
    param_1[0xf] = 0x6301c2c5;
    break;
  case 4:
    param_1[0xf] = 0x87a4111;
    break;
  case 5:
    param_1[0xf] = 0xe0283464;
    break;
  case 6:
    param_1[0xf] = 0x895cafc;
    break;
  case 8:
    param_1[0xf] = 0x48014c20;
    break;
  case 9:
    param_1[0xf] = 0xb96901dd;
    break;
  case 10:
    param_1[0xf] = 0x87d60d7;
    break;
  case 0xb:
    param_1[0xf] = 0xba209b97;
    break;
  case 0xc:
    param_1[0xf] = 0x78b16b24;
  }
  puVar14 = DAT_0073ad40;
  iVar15 = 0;
  piVar10 = &DAT_00706530;
  do {
    if (*piVar10 == iVar9) {
      local_1c = &DAT_00706530 + iVar15 * 7;
      goto LAB_0050768a;
    }
    piVar10 = piVar10 + 7;
    iVar15 = iVar15 + 1;
  } while ((int)piVar10 < 0x70669c);
  local_1c = (undefined4 *)0x0;
LAB_0050768a:
  uVar3 = local_1c[4];
  if (iVar9 == 0xc) {
    cVar6 = GarageCategoryVisual__IsWidebodyInstalled();
    puVar14 = DAT_0073ad40;
    if (cVar6 == '\0') {
LAB_005077db:
      local_18 = CarPartDatabase__GetCarPart(DAT_00735720,uVar3,0,0,0xffffffff);
    }
    else {
      puVar11 = (undefined4 *)NullUpdate_ret();
      for (; puVar14 != puVar11; puVar14 = (undefined4 *)*puVar14) {
        local_18 = puVar14[3];
        uVar17 = puVar14[4] * 0x30 + local_18;
        if ((DAT_00735720 != 0) &&
           (local_18 = BinarySearch_Hash(DAT_00735720,local_18,4), local_18 == 0)) break;
        for (; local_18 < uVar17; local_18 = local_18 + 0x30) {
          if ((DAT_00735720 != 0) && (*(int *)(local_18 + 4) != DAT_00735720)) goto LAB_00507727;
          if (*(char *)(local_18 + 0x10) == '\x05') goto LAB_005077f6;
        }
      }
LAB_00507727:
      local_18 = 0;
    }
  }
  else if (iVar9 == 10) {
    puVar11 = (undefined4 *)NullUpdate_ret();
    for (; puVar14 != puVar11; puVar14 = (undefined4 *)*puVar14) {
      local_18 = puVar14[3];
      uVar17 = puVar14[4] * 0x30 + local_18;
      for (; local_18 < uVar17; local_18 = local_18 + 0x30) {
        if (*(char *)(local_18 + 0x10) == 't') goto LAB_005077f6;
      }
    }
    local_18 = 0;
  }
  else {
    if (iVar9 != 9) goto LAB_005077db;
    puVar11 = (undefined4 *)NullUpdate_ret();
    for (; puVar14 != puVar11; puVar14 = (undefined4 *)*puVar14) {
      local_18 = puVar14[3];
      uVar17 = puVar14[4] * 0x30 + local_18;
      for (; local_18 < uVar17; local_18 = local_18 + 0x30) {
        if (*(char *)(local_18 + 0x10) == 's') goto LAB_005077f6;
      }
    }
    local_18 = 0;
  }
LAB_005077f6:
  bVar19 = DAT_007677ac != 0;
  uVar12 = MapCarPartIDToCareerUpgrade();
  bVar4 = false;
  switch(extraout_ECX) {
  case 1:
  case 2:
  case 10:
    bVar5 = false;
    break;
  case 0xd:
  case 0xe:
    bVar4 = true;
  default:
    bVar5 = true;
  }
  if ((((DAT_00735ec1 == '\0') && (extraout_DL == '\0')) &&
      (cVar6 = EasterEggs__IsPartUnlocked(), cVar6 == '\0')) &&
     (cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar12), cVar6 == '\0')) {
    uVar13 = 0;
  }
  else {
    uVar13 = 1;
  }
  param_1[0x22] = uVar13;
  if (((DAT_00735ec1 != '\0') || (bVar19)) ||
     ((cVar6 = EasterEggs__IsPartUnlocked(), cVar6 != '\0' ||
      ((cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar12), cVar6 != '\0' || (bVar5)))))) {
    uVar13 = 1;
  }
  else {
    uVar13 = 0;
  }
  param_1[0x23] = uVar13;
  if ((((DAT_00735ec1 != '\0') || (bVar19)) || (cVar6 = EasterEggs__IsPartUnlocked(), cVar6 != '\0')
      ) || ((cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar12), cVar6 != '\0' || (bVar4)))) {
    uVar13 = 1;
  }
  else {
    uVar13 = 0;
  }
  param_1[0x24] = uVar13;
  if (((DAT_00735ec1 != '\0') || (bVar19)) ||
     ((cVar6 = EasterEggs__IsPartUnlocked(), cVar6 != '\0' ||
      (cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar12), cVar6 != '\0')))) {
    uVar13 = 1;
  }
  else {
    uVar13 = 0;
  }
  param_1[0x25] = uVar13;
  if ((((DAT_00735ec1 != '\0') || (bVar19)) || (cVar6 = EasterEggs__IsPartUnlocked(), cVar6 != '\0')
      ) || (cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar12), cVar6 != '\0')) {
    uVar13 = 1;
  }
  else {
    uVar13 = 0;
  }
  param_1[0x26] = uVar13;
  if ((DAT_00735724 != 10) && (DAT_00735724 != 9)) {
    do {
      bVar2 = *(byte *)(local_18 + 0x11);
      cVar6 = '\x01';
      if ((bVar2 == 4) &&
         ((cVar7 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar12), cVar7 == '\0' ||
          (cVar7 = PartStore__HasPart(&DAT_0075f344), cVar7 == '\0')))) {
        cVar6 = '\0';
      }
      cVar7 = *(char *)(local_18 + 0x10);
      if (((cVar7 == '\v') && (iVar9 = FECarConfig__GetCarType(), -1 < iVar9)) &&
         ((iVar9 < 2 || (iVar9 == 5)))) {
        pcVar16 = "NOHATCHBACK";
        iVar9 = -1;
        uVar17 = 0x4e;
        do {
          iVar9 = iVar9 * 0x21 + uVar17;
          pbVar1 = (byte *)(pcVar16 + 1);
          uVar17 = (uint)*pbVar1;
          pcVar16 = pcVar16 + 1;
        } while (*pbVar1 != 0);
        if (*(int *)(local_18 + 0xc) == iVar9) {
          cVar6 = '\0';
        }
      }
      if ((DAT_00745e40 == 2) && (uVar17 = 0, DAT_0073766c != 0)) {
        puVar18 = (uint *)(DAT_00737668 + 0x24);
        do {
          if ((puVar18[-1] == 1) && (*puVar18 == (uint)bVar2)) {
            if (*(char *)(uVar17 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_00507ab1;
            break;
          }
          uVar17 = uVar17 + 1;
          puVar18 = puVar18 + 0xd;
        } while (uVar17 < DAT_0073766c);
      }
      if (((bVar2 == 0) || (cVar8 = PartStore__HasPart(&DAT_0075f344), cVar8 != '\0')) ||
         ((bVar19 && (bVar2 < 4)))) {
LAB_00507ab1:
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      iVar9 = DAT_00745e40;
      if (((DAT_00745e40 != 1) && (!bVar4)) && (1 < bVar2)) {
        cVar6 = '\0';
      }
      if (cVar7 == '\v') {
        if (cVar6 != '\0') {
          if (bVar2 == 4) {
            cVar6 = IsMagicSpoilerToHide(local_18);
            cVar6 = '\x01' - (cVar6 != '\0');
          }
          goto LAB_00507af1;
        }
      }
      else {
LAB_00507af1:
        if (cVar6 != '\0') {
          if (iVar9 == 1) {
            UnlockTeller__GetNewlyUnlockedPartLevel();
          }
          GaragePartsBrowser__AddPickable(local_18,local_1c[1],param_1[bVar2 + 0x22]);
        }
      }
      local_18 = CarPartDatabase__GetCarPart(DAT_00735720,local_1c[4],0,local_18,0xffffffff);
    } while (local_18 != 0);
  }
  if (local_1c[6] != 0) {
    for (iVar9 = CarPartDatabase__GetCarPart(local_1c[6],uVar3,0,0,0xffffffff); iVar9 != 0;
        iVar9 = CarPartDatabase__GetCarPart(local_1c[6],uVar3,0,iVar9,0xffffffff)) {
      if (DAT_00745e40 == 2) {
        uVar17 = 0;
        if (DAT_0073766c != 0) {
          puVar18 = (uint *)(DAT_00737668 + 0x24);
          do {
            if ((puVar18[-1] == 1) && (*puVar18 == (uint)*(byte *)(iVar9 + 0x11))) {
              if (*(char *)(uVar17 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_00507bff;
              break;
            }
            uVar17 = uVar17 + 1;
            puVar18 = puVar18 + 0xd;
          } while (uVar17 < DAT_0073766c);
        }
LAB_00507cd5:
        if ((*(byte *)(iVar9 + 0x11) < 2) ||
           ((cVar6 = GaragePartsBrowser__IsPartLocked(param_1), cVar6 == '\0' &&
            (((DAT_00735ec1 != '\0' || (DAT_007677ac != 0)) ||
             (cVar6 = PartStore__HasPart(&DAT_0075f344), cVar6 != '\0')))))) goto LAB_00507bff;
      }
      else {
        if (DAT_00745e40 != 1) goto LAB_00507cd5;
        UnlockTeller__GetNewlyUnlockedPartLevel();
LAB_00507bff:
        GaragePartsBrowser__AddPickable(iVar9,local_1c[1],param_1[*(byte *)(iVar9 + 0x11) + 0x22]);
      }
    }
  }
  if (DAT_00735724 == 0xc) {
    for (puVar14 = (undefined4 *)param_1[0x11]; puVar14 != param_1 + 0x11;
        puVar14 = (undefined4 *)*puVar14) {
      if (puVar14[3] == DAT_00745b80) goto LAB_00507d80;
    }
  }
  else {
    for (puVar14 = (undefined4 *)param_1[0x11]; puVar14 != param_1 + 0x11;
        puVar14 = (undefined4 *)*puVar14) {
      if (puVar14[3] == (&DAT_00745b6c)[local_1c[4]]) goto LAB_00507d80;
    }
  }
LAB_00507c6f:
  param_1[0x10] = param_1[0x11];
LAB_00507c75:
  FUN_004f8960();
  GaragePartsBrowser__RedrawHeading(param_1);
  GarageManager__PreviewPart();
  FUN_004ad7b0(local_1c[1]);
  *(undefined1 *)(param_1 + 8) = 1;
  ExceptionList = local_10;
  return;
LAB_00507d80:
  if (puVar14 != (undefined4 *)0x0) {
    for (puVar11 = (undefined4 *)param_1[0x11]; puVar11 != param_1 + 0x11;
        puVar11 = (undefined4 *)*puVar11) {
      if ((undefined4 *)puVar11[2] == puVar14) {
        param_1[0x10] = puVar11;
        goto LAB_00507c75;
      }
    }
    param_1[0x10] = (undefined4 *)param_1[0x11];
    goto LAB_00507c75;
  }
  goto LAB_00507c6f;
}


// ==== 0x507e10 GaragePartsBrowser::IsPartLocked

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

bool GaragePartsBrowser__IsPartLocked(int param_1)

{
  byte bVar1;
  char cVar2;
  int in_EAX;
  
  if (((DAT_00735ec1 != '\0') || (DAT_00735728 != 0)) || (in_EAX == 0)) {
    return false;
  }
  bVar1 = *(byte *)(in_EAX + 0x11);
  cVar2 = EasterEggs__IsPartUnlocked();
  if ((cVar2 == '\0') && ((DAT_00745e40 != 2 || (DAT_007677ac == 0)))) {
    return *(int *)(param_1 + 0x88 + (uint)bVar1 * 4) == 0;
  }
  return false;
}


// ==== 0x507e80 GaragePartsBrowser::LookupDescHashCat9

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 __fastcall GaragePartsBrowser__LookupDescHashCat9(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00745e50)[iVar1 * 2] == param_1) {
      return *(undefined4 *)(&DAT_00745e54 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x13);
  return 0;
}


// ==== 0x507ea0 GaragePartsBrowser::LookupDescHashCat10

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 __fastcall GaragePartsBrowser__LookupDescHashCat10(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00745fc0)[iVar1 * 2] == param_1) {
      return *(undefined4 *)(&DAT_00745fc4 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x19);
  return 0;
}


// ==== 0x507ec0 GaragePartsBrowser::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GaragePartsBrowser__RedrawHeading(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  bool bVar9;
  char local_ac [32];
  char local_8c [32];
  undefined4 local_6c [8];
  char local_4c [64];
  int local_c;
  bool local_6;
  bool local_5;
  
  local_c = *(int *)(param_1 + 0x40);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar8 = 0x20;
  pcVar6 = local_ac;
  do {
    cVar2 = pcVar6[iVar3 - (int)local_ac];
    iVar8 = iVar8 + -1;
    *pcVar6 = cVar2;
    if (cVar2 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar8 != 0);
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar8 = 0x20;
  pcVar6 = local_8c;
  do {
    cVar2 = pcVar6[iVar3 - (int)local_8c];
    iVar8 = iVar8 + -1;
    *pcVar6 = cVar2;
    if (cVar2 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar8 != 0);
  puVar7 = local_6c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar7 = (undefined4 *)(&DAT_00745b6c)[*(int *)(&DAT_006f8868 + DAT_00735724 * 4)];
  if (puVar7 == (undefined4 *)0x0) {
    bVar9 = true;
  }
  else {
    bVar9 = *(char *)((int)puVar7 + 0x11) == '\0';
  }
  puVar1 = *(undefined4 **)(local_c + 0xc);
  if (puVar1 == (undefined4 *)0x0) {
    local_6 = true;
LAB_00507fb2:
    if (!bVar9) {
LAB_00508078:
      local_5 = false;
      goto LAB_00507ffb;
    }
    local_5 = true;
  }
  else {
    local_6 = *(char *)((int)puVar1 + 0x11) == '\0';
    if (local_6) goto LAB_00507fb2;
    if (bVar9) goto LAB_00508078;
    local_5 = puVar1 == puVar7;
    if (puVar1 != puVar7) goto LAB_00507ffb;
  }
  FUN_00565da0(" (%s)",local_ac);
LAB_00507ffb:
  iVar3 = local_c;
  pcVar6 = local_4c;
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  if (*(int *)(iVar3 + 0xc) != 0) {
    if (DAT_00735724 == 9) {
      iVar3 = 0;
      do {
        if ((&DAT_00745e50)[iVar3 * 2] == puVar1[2]) {
          if (*(int *)(&DAT_00745e54 + iVar3 * 8) != 0) {
            GaragePartsBrowser__LookupDescHashCat9();
          }
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x13);
      iVar3 = LanguageStrings__FindByHash();
      if (iVar3 == 0) {
        iVar3 = LanguageStrings__FindByHash();
      }
      iVar8 = 0x40;
      pcVar6 = local_4c;
      do {
        cVar2 = pcVar6[iVar3 - (int)local_4c];
        iVar8 = iVar8 + -1;
        *pcVar6 = cVar2;
        if (cVar2 == '\0') break;
        pcVar6 = pcVar6 + 1;
      } while (iVar8 != 0);
    }
    else if (DAT_00735724 == 10) {
      iVar3 = GaragePartsBrowser__LookupDescHashCat10();
      if (iVar3 != 0) {
        GaragePartsBrowser__LookupDescHashCat10();
      }
      iVar3 = LanguageStrings__FindByHash();
      if (iVar3 == 0) {
        iVar3 = LanguageStrings__FindByHash();
      }
      iVar8 = 0x40;
      pcVar6 = local_4c;
      do {
        cVar2 = pcVar6[iVar3 - (int)local_4c];
        iVar8 = iVar8 + -1;
        *pcVar6 = cVar2;
        if (cVar2 == '\0') break;
        pcVar6 = pcVar6 + 1;
      } while (iVar8 != 0);
    }
    else {
      pcVar6 = (char *)*puVar1;
      local_4c[0] = *pcVar6;
      if (local_4c[0] != '\0') {
        pcVar4 = local_4c;
        do {
          cVar2 = pcVar4[(int)(pcVar6 + (1 - (int)local_4c))];
          pcVar4 = pcVar4 + 1;
          *pcVar4 = cVar2;
        } while (cVar2 != '\0');
      }
    }
  }
  if (*(int *)(local_c + 0xc) == 0) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar3 + 0x18));
    }
    puVar7 = local_6c;
    if (local_5 == false) {
      puVar7 = (undefined4 *)&DAT_006b9172;
    }
    pcVar6 = local_8c;
    if (local_6 == false) {
      pcVar6 = local_4c;
    }
    FEngPrintf(&DAT_006cc578,pcVar6,puVar7);
  }
  else {
    if ((DAT_00735724 == 0xc) && (*(char *)(*(int *)(local_c + 0xc) + 0x11) == '\0')) {
      FUN_00495f00(0x44798138);
    }
    else {
      puVar7 = local_6c;
      if (local_5 == false) {
        puVar7 = (undefined4 *)&DAT_006b9172;
      }
      pcVar6 = local_8c;
      if (local_6 == false) {
        pcVar6 = local_4c;
      }
      FEngPrintf(&DAT_006cc578,pcVar6,puVar7);
    }
    uVar5 = GarageManager__GetMsgForUpgradeLevel(&DAT_00744ff0);
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int *)(iVar3 + 0x14) != 0)) {
      FUN_004f7c00(uVar5,0,0,*(int *)(iVar3 + 0x18));
    }
  }
  iVar3 = GetCarPartCost();
  local_5 = DAT_007677ac != 0;
  if (((((iVar3 == 0) || (DAT_00777b4c != 1)) || (DAT_00735ec1 != '\0')) ||
      ((DAT_007677ac != 0 || (cVar2 = PartStore__HasPart(&DAT_0075f344), cVar2 != '\0')))) ||
     (local_5 != false)) {
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x7c5a7469);
      }
    }
    FEObject__SetInvisible(iVar3);
  }
  else {
    FUN_00495fc0();
    FEngPrintf(&DAT_006ca778,iVar3);
  }
  cVar2 = GaragePartsBrowser__IsPartLocked(param_1);
  if (cVar2 != '\0') {
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c != 0) {
        uVar5 = FUN_004ef050(0xa8a3681a);
        FEObject__SetVisible(uVar5);
        return;
      }
      iVar3 = 0;
    }
    FEObject__SetVisible(iVar3);
    return;
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c != 0) {
      uVar5 = FUN_004ef050(0xa8a3681a);
      FEObject__SetInvisible(uVar5);
      return;
    }
    iVar3 = 0;
  }
  FEObject__SetInvisible(iVar3);
  return;
}


// ==== 0x5083c0 GaragePartsBrowser::ScrollPickables

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GaragePartsBrowser__ScrollPickables(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  FUN_004af5d0();
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (param_1 == -0x6edfbf62) {
    if ((((iVar1 != *(int *)(unaff_EDI + 0x44)) &&
         (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
        (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
      (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x50fe5db4,0,0,*(int *)(iVar2 + 0x18));
    }
    if ((*(int *)(unaff_EDI + 0x40) != *(int *)(unaff_EDI + 0x44)) &&
       (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(*(int *)(unaff_EDI + 0x40) + 4);
    }
  }
  else if (param_1 == -0x4a68e40f) {
    if (iVar1 != *(int *)(unaff_EDI + 0x48)) {
      FUN_004c96c0(0x50fe5db4);
    }
    if ((*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48)) &&
       (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
    }
  }
  iVar2 = *(int *)(unaff_EDI + 0x40);
  if (iVar1 != iVar2) {
    FUN_004f8910();
    GaragePartsBrowser__RedrawHeading(unaff_EDI);
    if (*(char *)(*(int *)(iVar2 + 0xc) + 0x10) == '\x05') {
      GarageManager__PreviewPart();
    }
    if (DAT_00745e40 == 1) {
      GaragePartsBrowser__IsPartLocked(unaff_EDI);
    }
    GarageManager__PreviewPart();
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x508510 GaragePartsBrowser::CanPlayerPurchasePart

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 GaragePartsBrowser__CanPlayerPurchasePart(undefined4 param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  if (DAT_00745e40 == 1) {
    cVar1 = GaragePartsBrowser__IsPartLocked(param_1);
    if (cVar1 != '\0') {
      return 0;
    }
    if (DAT_0073440c == '\0') {
      Career__GetCash(&DAT_0075eef8);
      uVar2 = GetCarPartCost();
      if ((int)((ulonglong)uVar2 >> 0x20) < (int)uVar2) {
        return 0;
      }
    }
  }
  return 1;
}


// ==== 0x508560 GaragePartsBrowser::IsInstallingPart

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

uint GaragePartsBrowser__IsInstallingPart(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar2 = GaragePartsBrowser__IsPartLocked(unaff_EDI);
  if ((char)uVar2 != '\0') {
    return uVar2 & 0xffffff00;
  }
  if (DAT_00745e40 == 1) {
    cVar1 = *(char *)(unaff_ESI + 0x10);
    iVar3 = 0;
    if ((cVar1 != '\x06') && (cVar1 != '\x05')) {
      uVar2 = PartStore__HasPart(&DAT_0075f344);
      if ((char)uVar2 == '\0') goto LAB_00508616;
      iVar3 = (int)cVar1;
      if ((&DAT_00745b6c)[iVar3] == unaff_ESI) {
        uVar2 = FUN_004eba00(0,0);
        return uVar2 & 0xffffff00;
      }
    }
LAB_005085ac:
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  uVar2 = DAT_00745e40;
  if (DAT_00745e40 == 2) {
    cVar1 = *(char *)(unaff_ESI + 0x10);
    iVar3 = 0;
    if (((cVar1 == '\x06') || (cVar1 == '\x05')) || ((&DAT_00745b6c)[cVar1] != unaff_ESI))
    goto LAB_005085ac;
    local_10 = 0x639;
    local_14 = 0x368294c0;
    local_c = 0;
    uVar2 = FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(unaff_EDI + 0xc));
  }
LAB_00508616:
  return uVar2 & 0xffffff00;
}


// ==== 0x508620 GaragePartsBrowser::IsBuyingPart

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 GaragePartsBrowser__IsBuyingPart(void)

{
  char cVar1;
  int in_EAX;
  int unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  cVar1 = GaragePartsBrowser__IsPartLocked(unaff_EDI);
  if (((cVar1 == '\0') && (DAT_00745e40 == 1)) && (*(char *)(in_EAX + 0x10) != '\x06')) {
    cVar1 = PartStore__HasPart(&DAT_0075f344);
    if (cVar1 == '\0') {
      cVar1 = GaragePartsBrowser__CanPlayerPurchasePart(unaff_EDI);
      if (cVar1 != '\0') {
        return 1;
      }
      local_10 = 0x639;
      local_14 = 0x2c0344a3;
      local_c = 0;
      FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(unaff_EDI + 0xc));
    }
  }
  return 0;
}


// ==== 0x5086a0 GaragePartsBrowser::UninstallPartSlots16

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void GaragePartsBrowser__UninstallPartSlots16(void)

{
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  return;
}


// ==== 0x5087e0 HypotheticalRide_AnyPartSlotSet16

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 HypotheticalRide_AnyPartSlotSet16(void)

{
  int iVar1;
  
  iVar1 = DAT_00745cb8;
  if (((((DAT_00745cb8 == 0) && (iVar1 = DAT_00745cbc, DAT_00745cbc == 0)) &&
       (iVar1 = DAT_00745cc0, DAT_00745cc0 == 0)) &&
      (((iVar1 = DAT_00745cc4, DAT_00745cc4 == 0 && (iVar1 = DAT_00745cc8, DAT_00745cc8 == 0)) &&
       ((iVar1 = DAT_00745ccc, DAT_00745ccc == 0 &&
        ((iVar1 = DAT_00745cd8, DAT_00745cd8 == 0 && (iVar1 = DAT_00745cdc, DAT_00745cdc == 0)))))))
      ) && ((iVar1 = DAT_00745ce0, DAT_00745ce0 == 0 &&
            (((((iVar1 = DAT_00745ce4, DAT_00745ce4 == 0 &&
                (iVar1 = DAT_00745ce8, DAT_00745ce8 == 0)) &&
               (iVar1 = DAT_00745cec, DAT_00745cec == 0)) &&
              ((iVar1 = DAT_00745cf8, DAT_00745cf8 == 0 && (iVar1 = DAT_00745cfc, DAT_00745cfc == 0)
               ))) && (iVar1 = DAT_00745d18, DAT_00745d18 == 0)))))) {
    return CONCAT31((int3)((uint)DAT_00745d1c >> 8),DAT_00745d1c != 0);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x508880 HypotheticalRide_AnyPartSlotSet_cf8

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 HypotheticalRide_AnyPartSlotSet_cf8(void)

{
  if (DAT_00745cf8 != 0) {
    return CONCAT31((int3)((uint)DAT_00745cf8 >> 8),1);
  }
  return CONCAT31((int3)((uint)DAT_00745cfc >> 8),DAT_00745cfc != 0);
}


// ==== 0x5088a0 HypotheticalRide_AnyPartSlotSet_d18

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 HypotheticalRide_AnyPartSlotSet_d18(void)

{
  if (DAT_00745d18 != 0) {
    return CONCAT31((int3)((uint)DAT_00745d18 >> 8),1);
  }
  return CONCAT31((int3)((uint)DAT_00745d1c >> 8),DAT_00745d1c != 0);
}


// ==== 0x5088c0 HypotheticalRide_AnyPartSlotSet_c58

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 HypotheticalRide_AnyPartSlotSet_c58(void)

{
  int iVar1;
  
  iVar1 = DAT_00745c58;
  if ((((DAT_00745c58 == 0) && (iVar1 = DAT_00745c5c, DAT_00745c5c == 0)) &&
      (iVar1 = DAT_00745c60, DAT_00745c60 == 0)) &&
     (((iVar1 = DAT_00745c64, DAT_00745c64 == 0 && (iVar1 = DAT_00745c68, DAT_00745c68 == 0)) &&
      ((iVar1 = DAT_00745c6c, DAT_00745c6c == 0 && (iVar1 = DAT_00745c70, DAT_00745c70 == 0)))))) {
    return CONCAT31((int3)((uint)DAT_00745c74 >> 8),DAT_00745c74 != 0);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x508910 GaragePartsBrowser::UninstallPartSlots8

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void GaragePartsBrowser__UninstallPartSlots8(void)

{
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  GarageManager__InstallPart(0,0);
  return;
}


// ==== 0x5089b0 GaragePartsBrowser::NotificationMessage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __thiscall GaragePartsBrowser__NotificationMessage(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  char extraout_CL;
  bool bVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int aiStack_30 [10];
  char cStack_5;
  
  iVar1 = DAT_00745bf4;
  iVar6 = DAT_00745bf0;
  iVar5 = DAT_00745bec;
  aiStack_30[9] = param_1;
  if (0x9120409e < param_2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 == 0xc98356ba) {
        if (*(char *)(param_1 + 0x9c) != '\0') {
          GarageCategoryVisual__MoveBackPackage(param_1);
        }
        FUN_004f89d0();
        FUN_004f7d30();
        return;
      }
      if (param_2 != 0xf0aadebb) {
        return;
      }
      iVar5 = *(int *)(*(int *)(param_1 + 0x40) + 0xc);
      cVar2 = *(char *)(iVar5 + 0x10);
      if (cVar2 == '\x05') {
        GarageManager__InstallPart(0,0);
        GarageManager__InstallPart(0,0);
        GarageManager__InstallPart(0,0);
        GarageManager__InstallPart(0,0);
        GarageManager__InstallPart(0,0);
        GaragePartsBrowser__UninstallPartSlots16();
      }
      else if (cVar2 == '\x06') {
        iVar6 = FECarConfig__GetCarType();
        uVar7 = FUN_004f42f0("%s_DECAL_LEFT_QUARTER_RECT_MEDIUM",iVar6 * 0xc90 + DAT_00734588);
        iVar6 = FECarConfig__GetCarType();
        uVar8 = FUN_004f42f0("%s_DECAL_RIGHT_QUARTER_RECT_MEDIUM",iVar6 * 0xc90 + DAT_00734588);
        uVar14 = 0;
        uVar13 = 0xffffffff;
        uVar12 = 0;
        uVar11 = 0x18;
        FECarConfig__GetCarType(0x18,uVar7,0,0xffffffff,0);
        uVar7 = FUN_0057ced0(&DAT_0073ad40,uVar11,uVar7,uVar12,uVar13);
        GarageManager__InstallPart(uVar7,uVar14);
        uVar13 = 0;
        uVar12 = 0xffffffff;
        uVar11 = 0;
        uVar7 = 0x19;
        FECarConfig__GetCarType(0x19,uVar8,0,0xffffffff,0);
        uVar7 = FUN_0057ced0(&DAT_0073ad40,uVar7,uVar8,uVar11,uVar12);
        GarageManager__InstallPart(uVar7,uVar13);
        GaragePartsBrowser__UninstallPartSlots16();
      }
      else if (cVar2 == '\b') {
        GaragePartsBrowser__UninstallPartSlots8();
      }
      GarageManager__InstallPart(iVar5,0);
      *(undefined1 *)(aiStack_30[9] + 0x9c) = 1;
      return;
    }
LAB_00508fa3:
    GaragePartsBrowser__ScrollPickables(param_2);
    return;
  }
  if (param_2 == 0x9120409e) goto LAB_00508fa3;
  if (0x8084effa < param_2) {
    if (param_2 != 0x911ab364) {
      return;
    }
    GarageManager__SyncActualToEditing(0);
    GarageCategoryVisual__MoveBackPackage(param_1);
    return;
  }
  if (param_2 == 0x8084effa) {
    if ((DAT_00745be8 != 0) &&
       (((((cVar2 = *(char *)(DAT_00745be8 + 0x12), cVar2 == '\x01' || (cVar2 == '\x03')) ||
          (cVar2 == '\x06')) || ((cVar2 == '\b' || (cVar2 == '\n')))) || (cVar2 == '\r')))) {
      GarageManager__InstallPart(0,0);
    }
    if ((iVar5 != 0) &&
       (((cVar2 = *(char *)(iVar5 + 0x12), cVar2 == '\x01' || (cVar2 == '\x03')) ||
        ((cVar2 == '\x06' || (((cVar2 == '\b' || (cVar2 == '\n')) || (cVar2 == '\r')))))))) {
      GarageManager__InstallPart(0,0);
    }
    if ((iVar6 != 0) &&
       (((cVar2 = *(char *)(iVar6 + 0x12), cVar2 == '\x01' || (cVar2 == '\x03')) ||
        (((cVar2 == '\x06' || ((cVar2 == '\b' || (cVar2 == '\n')))) || (cVar2 == '\r')))))) {
      GarageManager__InstallPart(0,0);
    }
    if (iVar1 == 0) {
      return;
    }
    cVar2 = *(char *)(iVar1 + 0x12);
    if ((((cVar2 != '\x01') && (cVar2 != '\x03')) && (cVar2 != '\x06')) &&
       (((cVar2 != '\b' && (cVar2 != '\n')) && (cVar2 != '\r')))) {
      return;
    }
    GarageManager__InstallPart(0,0);
    return;
  }
  if (param_2 != 0xc407210) {
    if (param_2 != 0x2f6484d0) {
      return;
    }
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xc);
    if (DAT_00745e40 == 1) {
      FUN_005a2620();
    }
    GarageManager__InstallPart(uVar7,0);
    iVar5 = aiStack_30[9];
    GaragePartsBrowser__RedrawHeading(aiStack_30[9]);
    *(undefined1 *)(iVar5 + 0x9c) = 1;
    return;
  }
  FUN_004af5d0();
  cVar2 = GaragePartsBrowser__IsPartLocked(param_1);
  if (cVar2 != '\0') {
    if (DAT_006f1dd8 == 0) {
      return;
    }
    if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
    return;
  }
  if ((DAT_00735724 == 4) && (DAT_0074546c != 0)) {
    iVar5 = bStringHash();
    iVar6 = bStringHash();
    if (iVar5 == iVar6) goto LAB_00508bb7;
    if (DAT_00745be8 == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = *(char *)(DAT_00745be8 + 0x12);
    }
    if (DAT_00745bec == 0) {
      cVar4 = '\0';
    }
    else {
      cVar4 = *(char *)(DAT_00745bec + 0x12);
    }
    if (DAT_00745bf0 == 0) {
      cVar9 = '\0';
    }
    else {
      cVar9 = *(char *)(DAT_00745bf0 + 0x12);
    }
    if (DAT_00745bf4 == 0) {
      cVar3 = '\0';
    }
    else {
      cVar3 = *(char *)(DAT_00745bf4 + 0x12);
    }
    if (((((((cVar2 == '\x01') || (cVar4 == '\x01')) || (cVar9 == '\x01')) ||
          ((cVar3 == '\x01' || (cVar2 == '\x03')))) ||
         ((cVar4 == '\x03' || ((cVar9 == '\x03' || (cVar3 == '\x03')))))) ||
        (((cVar2 == '\x06' ||
          (((((cVar4 == '\x06' || (cVar9 == '\x06')) || (cVar3 == '\x06')) ||
            ((cVar2 == '\b' || (cVar4 == '\b')))) ||
           ((cVar9 == '\b' || ((cVar3 == '\b' || (cVar2 == '\n')))))))) || (cVar4 == '\n')))) ||
       ((((cVar9 == '\n' || (cVar3 == '\n')) || (cVar2 == '\r')) ||
        (((cVar4 == '\r' || (cVar9 == '\r')) || (cVar3 == '\r')))))) {
      aiStack_30[0] = 0x784216c7;
      aiStack_30[2] = 0x8084effa;
      aiStack_30[1] = 0xf770;
      aiStack_30[3] = 0x61c;
      goto LAB_00508c4c;
    }
    cVar2 = HypotheticalRide_AnyPartSlotSet_c58();
    if (cVar2 == '\0') goto LAB_00508bb7;
    aiStack_30[0] = 0x169b8024;
LAB_00508c37:
    aiStack_30[2] = 0xf0aadebb;
  }
  else {
LAB_00508bb7:
    cVar2 = GaragePartsBrowser__IsInstallingPart();
    cStack_5 = GaragePartsBrowser__IsBuyingPart();
    iVar5 = bStringHash();
    iVar6 = bStringHash();
    bVar10 = iVar5 == iVar6;
    iVar5 = bStringHash();
    iVar6 = bStringHash();
    if (iVar5 != iVar6) {
      bStringHash();
      bStringHash();
    }
    cVar4 = HypotheticalRide_AnyPartSlotSet16();
    if ((cVar4 != '\0') && ((extraout_CL != '\0' || (bVar10)))) {
      aiStack_30[0] = -0xdd18d41;
      goto LAB_00508c37;
    }
    if ((cVar2 != '\0') || (bVar10)) {
      aiStack_30[0] = (-(uint)bVar10 & 0x253bb8a1) + 0x76d94941;
      goto LAB_00508c37;
    }
    if (cStack_5 == '\0') {
      return;
    }
    aiStack_30[0] = 0x39223856;
    aiStack_30[2] = 0x2f6484d0;
  }
  aiStack_30[1] = 0x639;
  aiStack_30[3] = 0x541389e5;
LAB_00508c4c:
  aiStack_30[7] = 0;
  aiStack_30[8] = 0;
  aiStack_30[4] = 0;
  aiStack_30[5] = 0;
  aiStack_30[6] = 0xb8a7c6cc;
  FUN_004dc6e0(aiStack_30,"GenericDialog.fng",*(undefined4 *)(aiStack_30[9] + 0xc));
  return;
}


// ==== 0x508fb4 FUN_00508fb4

/* WARNING: Control flow encountered bad instruction data */

void FUN_00508fb4(void)

{
  func_0xfa3c78c5();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x508fc0 PerfStatsScreen::MapInputCode

/* [canon] car med (ghidra-canon+hopper) docs/re/canon_db.md */

int PerfStatsScreen__MapInputCode(void)

{
  int in_stack_00000014;
  
  if ((DAT_00745e4c == 0) && (in_stack_00000014 == 5)) {
switchD_00508fdc_default:
    return 0;
  }
  switch(in_stack_00000014) {
  case 1:
  case 2:
  case 3:
  case 4:
    goto switchD_00508fdc_default;
  default:
    return in_stack_00000014;
  }
}


// ==== 0x509000 CreatePerfStatsScreen

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 CreatePerfStatsScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688fe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x158);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = PerfStatsScreen__PerfStatsScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x509060 PerfStatsScreen::PerfStatsScreen

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 * PerfStatsScreen__PerfStatsScreen(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_44;
  char *local_40;
  char *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688fbf;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_PerfStatsScreen__scalar_deleting_destructor_006c0224;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  puVar1 = param_1 + 0x1d;
  param_1[0x12] = &DAT_006b9172;
  *puVar1 = puVar1;
  param_1[0x1e] = puVar1;
  puVar1 = param_1 + 0x20;
  param_1[0x1f] = 0;
  param_1[0x11] = &PTR_StatBarSlider__scalar_deleting_destructor_006c01fc;
  *puVar1 = puVar1;
  param_1[0x21] = puVar1;
  param_1[0x23] = 0;
  *(undefined1 *)(param_1 + 0x24) = 0;
  param_1[0x27] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x29] = &DAT_006b9172;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  puVar1 = param_1 + 0x34;
  *puVar1 = puVar1;
  param_1[0x35] = puVar1;
  puVar1 = param_1 + 0x37;
  param_1[0x36] = 0;
  param_1[0x28] = &PTR_StatBarSlider__scalar_deleting_destructor_006c01fc;
  *puVar1 = puVar1;
  param_1[0x38] = puVar1;
  param_1[0x3a] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  param_1[0x3e] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x40] = &DAT_006b9172;
  puVar1 = param_1 + 0x4b;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  *puVar1 = puVar1;
  param_1[0x4c] = puVar1;
  param_1[0x4d] = 0;
  param_1[0x3f] = &PTR_StatBarSlider__scalar_deleting_destructor_006c01fc;
  puVar1 = param_1 + 0x4e;
  *puVar1 = puVar1;
  param_1[0x4f] = puVar1;
  param_1[0x51] = 0;
  *(undefined1 *)(param_1 + 0x52) = 0;
  param_1[0x55] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  local_8 = 3;
  FUN_00495f00(0x87ad2b6c);
  FUN_00495f00(0x371711c);
  FUN_00495f00(0xab0a1361);
  local_44 = param_1[3];
  local_38 = &DAT_006b9172;
  local_34 = &DAT_006b9172;
  local_40 = "Bar1_Bottom_b";
  local_3c = "Bar1_Top_b";
  local_30 = 0xc;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_24 = 0x3f55c28f;
  local_20 = 0;
  local_1c = 0;
  (**(code **)(param_1[0x11] + 0x18))(&local_44);
  local_40 = "Bar2_Bottom_b";
  local_3c = "Bar2_Top_b";
  (**(code **)(param_1[0x28] + 0x18))(&local_44);
  local_40 = "Bar3_Bottom_b";
  local_3c = "Bar3_Top_b";
  (**(code **)(param_1[0x3f] + 0x18))(&local_44);
  param_1[0x10] = 0;
  if (DAT_00745e4c == 0) {
    param_1[0x10] = &DAT_00745720;
    uVar3 = 0x38eb5d03;
  }
  else if (DAT_00745e4c == 1) {
    param_1[0x10] = DAT_00735e6c;
    uVar3 = 0x8bc92e99;
  }
  else {
    if (DAT_00745e4c != 2) goto LAB_005092fe;
    param_1[0x10] = DAT_00735e6c + 0x720;
    uVar3 = 0x6bd4fb68;
  }
  FUN_00495f00(uVar3);
LAB_005092fe:
  PerfStatsScreen__SetupUpgrades(param_1);
  PerfStatsScreen__SetupStats();
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar2 + 0x18));
  }
  if (((DAT_00745e4c == 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     ((*(int *)(iVar2 + 0x18) != 0 && (*(int **)(iVar2 + 0x14) != (int *)0x0)))) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x1122aacc,0,0,*(int *)(iVar2 + 0x18));
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x509390 PerfStatsScreen::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall PerfStatsScreen__scalar_deleting_destructor(void *param_1,byte param_2)

{
  PerfStatsScreen___PerfStatsScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5093b0 PerfStatsScreen::_PerfStatsScreen

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall PerfStatsScreen___PerfStatsScreen(undefined4 *param_1)

{
  int iVar1;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688f7f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_PerfStatsScreen__scalar_deleting_destructor_006c0224;
  local_4 = 3;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar1 + 0x18));
  }
  FUN_005041a0();
  FUN_005041a0();
  FUN_005041a0();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x509450 PerfStatsScreen::NotificationMessage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __thiscall PerfStatsScreen__NotificationMessage(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0xc407210) {
    if (DAT_00745e4c == 1) {
      DAT_00745e4c = 2;
      *(int *)(param_1 + 0x40) = DAT_00735e6c + 0x720;
      uVar2 = 0x6bd4fb68;
LAB_0050949e:
      FUN_00495f00(uVar2);
      PerfStatsScreen__SetupUpgrades(param_1);
      PerfStatsScreen__SetupStats();
      return;
    }
    if (DAT_00745e4c == 2) {
      GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
    }
  }
  else if (param_2 == -0x6ee54c9c) {
    if ((DAT_00745e4c == 0) || (DAT_00745e4c == 1)) {
      iVar1 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar1 != 0) && ((*(int *)(iVar1 + 0x18) != 0 && (*(int **)(iVar1 + 0x14) != (int *)0x0)))
         ) {
        (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x1122aabb,0,0,*(int *)(iVar1 + 0x18));
      }
      GarageManager__PopScreen();
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (DAT_00745e4c == 2) {
      DAT_00745e4c = 1;
      *(int *)(param_1 + 0x40) = DAT_00735e6c;
      uVar2 = 0x8bc92e99;
      goto LAB_0050949e;
    }
  }
  return;
}


// ==== 0x509570 PerfStatsScreen::SetupUpgrades

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void PerfStatsScreen__SetupUpgrades(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int local_84;
  int local_80;
  int local_44 [9];
  byte local_20;
  byte local_1f [31];
  
  iVar2 = *(int *)(param_1 + 0x40);
  local_44[0] = 2;
  local_44[1] = 6;
  local_44[2] = 7;
  local_44[3] = 5;
  local_44[4] = 3;
  local_44[5] = 8;
  local_44[6] = 0;
  local_44[7] = 1;
  local_44[8] = 4;
  local_80 = 0;
  do {
    local_84 = 0;
    do {
      iVar6 = local_84 + 1;
      bSPrintf_regdst(0x20,"Upgrade_%d_%d",local_80,iVar6);
      iVar12 = -1;
      pbVar9 = &local_20;
      bVar4 = local_20;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        iVar12 = iVar12 * 0x21 + (uint)bVar4;
        pbVar1 = pbVar9 + 1;
        pbVar9 = pbVar9 + 1;
        bVar4 = *pbVar1;
      }
      iVar13 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_005096b8:
        if (iVar13 == 0) {
LAB_005096cb:
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_004ef050(iVar12);
        }
      }
      else {
        iVar7 = FEPackageList__FindByName(&DAT_00746104);
        iVar13 = DAT_0073578c;
        if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
          if (DAT_0073578c != 0) {
            iVar8 = *(int *)(DAT_0073578c + 8);
            if ((iVar8 == 0) ||
               ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
                (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_005096b8;
            goto LAB_0050969d;
          }
          goto LAB_005096cb;
        }
LAB_0050969d:
        if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar13 = DAT_0073578c, iVar7 == 0))
        goto LAB_005096b8;
      }
      iVar12 = *(int *)(iVar2 + 8 + local_44[local_84] * 4);
      iVar13 = *(int *)(iVar2 + 0x34 + local_44[local_84] * 4);
      iVar8 = FUN_005a0350();
      if (((iVar8 == 8) || (iVar8 == 5)) || (iVar8 == -1)) {
LAB_00509733:
        if ((iVar7 != 0) && (*(int *)(iVar7 + 0x18) < 0x100)) {
          cVar5 = FEColor_NearlyEqual();
          if (cVar5 == '\0') {
            *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
          }
LAB_00509774:
          FUN_004ff2f0(iVar7,0,0);
        }
      }
      else {
        if ((local_80 != 0) && (DAT_00735ec1 == '\0')) {
          if ((-1 < iVar8) && (iVar8 < 0x19)) {
            iVar10 = 0;
            do {
              if (*(int *)(&DAT_0075f348 + iVar10 * 4 + iVar8 * 0x90) == local_80)
              goto LAB_00509951;
              iVar10 = iVar10 + 1;
            } while (iVar10 < 0x24);
          }
          goto LAB_00509733;
        }
LAB_00509951:
        if ((iVar7 != 0) && (*(int *)(iVar7 + 0x18) < 0x100)) {
          cVar5 = FEColor_NearlyEqual();
          if (cVar5 == '\0') {
            *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
          }
          goto LAB_00509774;
        }
      }
      if ((((local_80 == iVar12) || ((local_80 == 4 && (iVar13 != 0)))) && (iVar7 != 0)) &&
         (*(int *)(iVar7 + 0x18) < 0x100)) {
        piVar3 = *(int **)(iVar7 + 0x2c);
        if (((((0x8b < piVar3[2]) || (piVar3[2] < 0x89)) || (0x70 < piVar3[1])) ||
            ((piVar3[1] < 0x6e || (3 < *piVar3)))) ||
           ((*piVar3 < 1 || ((0x100 < piVar3[3] || (piVar3[3] < 0xfe)))))) {
          *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
        }
        FUN_004ff2f0(iVar7,0,0);
      }
      if (DAT_006ee6f0 == 2) {
        if (local_80 != 0) goto LAB_00509ab6;
        pcVar11 = "Upgrade_Level_Stock_F";
        iVar12 = -1;
        bVar4 = 0x55;
        do {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          iVar12 = iVar12 * 0x21 + (uint)bVar4;
          bVar4 = pcVar11[1];
          pcVar11 = pcVar11 + 1;
        } while (bVar4 != 0);
        iVar13 = -1;
        pbVar9 = &local_20;
        bVar4 = local_20;
        while (bVar4 != 0) {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          pbVar1 = pbVar9 + 1;
          iVar13 = iVar13 * 0x21 + (uint)bVar4;
          pbVar9 = pbVar9 + 1;
          bVar4 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) goto LAB_00509a81;
        iVar7 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) goto LAB_00509a70;
        if (DAT_0073578c == 0) goto LAB_00509ab6;
        iVar8 = *(int *)(DAT_0073578c + 8);
        if (iVar8 == 0) {
LAB_00509a81:
          if ((DAT_0073578c == 0) || (iVar7 = FUN_004ef050(iVar13), iVar7 == 0)) goto LAB_00509ab6;
        }
        else {
          FUN_004ee660();
          iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
          if (iVar7 == 0) {
            FUN_004ee660();
            iVar7 = FUN_004fd1e0(iVar8 + 0xec);
            if (iVar7 == 0) goto LAB_00509a81;
          }
LAB_00509a70:
          if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar7 == 0)) goto LAB_00509a81;
        }
        if ((*(int *)(iVar7 + 0x18) != 1) || (*(int *)(iVar7 + 0x24) == iVar12)) goto LAB_00509ab6;
        *(int *)(iVar7 + 0x24) = iVar12;
LAB_00509aaf:
        *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
      }
      else if ((DAT_006ee6f0 == 4) && (local_80 == 4)) {
        pcVar11 = "Upgrade_Level_Unique_E";
        iVar12 = -1;
        bVar4 = 0x55;
        do {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          iVar12 = iVar12 * 0x21 + (uint)bVar4;
          bVar4 = pcVar11[1];
          pcVar11 = pcVar11 + 1;
        } while (bVar4 != 0);
        iVar13 = -1;
        pbVar9 = &local_20;
        bVar4 = local_20;
        while (bVar4 != 0) {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          pbVar1 = pbVar9 + 1;
          iVar13 = iVar13 * 0x21 + (uint)bVar4;
          pbVar9 = pbVar9 + 1;
          bVar4 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) goto LAB_00509912;
        iVar7 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) goto LAB_00509901;
        if (DAT_0073578c == 0) goto LAB_00509ab6;
        iVar8 = *(int *)(DAT_0073578c + 8);
        if (iVar8 == 0) {
LAB_00509912:
          if ((DAT_0073578c == 0) || (iVar7 = FUN_004ef050(iVar13), iVar7 == 0)) goto LAB_00509ab6;
        }
        else {
          FUN_004ee660();
          iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
          if (iVar7 == 0) {
            FUN_004ee660();
            iVar7 = FUN_004fd1e0(iVar8 + 0xec);
            if (iVar7 == 0) goto LAB_00509912;
          }
LAB_00509901:
          if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar7 == 0)) goto LAB_00509912;
        }
        if ((*(int *)(iVar7 + 0x18) == 1) && (*(int *)(iVar7 + 0x24) != iVar12)) {
          *(int *)(iVar7 + 0x24) = iVar12;
          goto LAB_00509aaf;
        }
      }
LAB_00509ab6:
      local_84 = iVar6;
    } while (iVar6 < 9);
    local_80 = local_80 + 1;
    if (4 < local_80) {
      return;
    }
  } while( true );
}


// ==== 0x509af0 PerfStatsScreen::SetupStats

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void PerfStatsScreen__SetupStats(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int unaff_EDI;
  float10 fVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar4;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  undefined8 uVar5;
  
  fVar3 = (float10)RideInfo__GetAccelRating();
  *(float *)(unaff_EDI + 0x60) = (float)fVar3;
  if ((float10)*(float *)(unaff_EDI + 0x58) < fVar3) {
    *(undefined4 *)(unaff_EDI + 0x60) = *(undefined4 *)(unaff_EDI + 0x58);
  }
  if (*(float *)(unaff_EDI + 0x60) < *(float *)(unaff_EDI + 0x5c)) {
    *(undefined4 *)(unaff_EDI + 0x60) = *(undefined4 *)(unaff_EDI + 0x5c);
  }
  uVar5 = CONCAT44(unaff_EBX,unaff_ESI);
  fVar3 = (float10)RideInfo__GetTopSpeedRating();
  *(float *)(unaff_EDI + 0xbc) = (float)fVar3;
  if ((float10)*(float *)(unaff_EDI + 0xb4) < fVar3) {
    *(undefined4 *)(unaff_EDI + 0xbc) = *(undefined4 *)(unaff_EDI + 0xb4);
  }
  if (*(float *)(unaff_EDI + 0xbc) < *(float *)(unaff_EDI + 0xb8)) {
    *(undefined4 *)(unaff_EDI + 0xbc) = *(undefined4 *)(unaff_EDI + 0xb8);
  }
  fVar3 = (float10)RideInfo__GetHandlingRating(uVar5);
  *(float *)(unaff_EDI + 0x118) = (float)fVar3;
  if ((float10)*(float *)(unaff_EDI + 0x110) < fVar3) {
    *(undefined4 *)(unaff_EDI + 0x118) = *(undefined4 *)(unaff_EDI + 0x110);
  }
  if (*(float *)(unaff_EDI + 0x118) < *(float *)(unaff_EDI + 0x114)) {
    *(undefined4 *)(unaff_EDI + 0x118) = *(undefined4 *)(unaff_EDI + 0x114);
  }
  (**(code **)(*(int *)(unaff_EDI + 0x44) + 0x10))();
  (**(code **)(*(int *)(unaff_EDI + 0xa0) + 0x10))();
  (**(code **)(*(int *)(unaff_EDI + 0xfc) + 0x10))();
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  _ftol_nocw();
  uVar2 = _ftol_nocw();
  FEngPrintf("%s %d @ %d RPM",iVar1,uVar2);
  iVar1 = LanguageStrings__FindByHash();
  fVar3 = extraout_ST0;
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
    fVar3 = extraout_ST0_00;
  }
  FEngPrintf("%s %2.1f",iVar1,(double)fVar3);
  if (DAT_007588f0 == 0) {
    iVar1 = LanguageStrings__FindByHash();
    fVar3 = extraout_ST0_01;
    fVar4 = extraout_ST1;
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
      fVar3 = extraout_ST0_02;
      fVar4 = extraout_ST1_00;
    }
    fVar3 = fVar3 * (float10)2.237;
  }
  else {
    iVar1 = LanguageStrings__FindByHash();
    fVar3 = extraout_ST0_03;
    fVar4 = extraout_ST1_01;
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
      fVar3 = extraout_ST0_04;
      fVar4 = extraout_ST1_02;
    }
    fVar3 = fVar3 * (float10)3.6;
  }
  FEngPrintf("%s %2.1f @ 3.1f",iVar1,(double)fVar4,(double)fVar3);
  return;
}


// ==== 0x509ca0 ChooseGaragePerfPath::_ChooseGaragePerfPath

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall ChooseGaragePerfPath___ChooseGaragePerfPath(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_ChooseGaragePerfPath__scalar_deleting_destructor_006c0244;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x509cf0 ChooseGaragePerfPath::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall ChooseGaragePerfPath__scalar_deleting_destructor(void *param_1,byte param_2)

{
  ChooseGaragePerfPath___ChooseGaragePerfPath();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x509d10 CreateGaragePerfCategory

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGaragePerfCategory(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = ChooseGaragePerfPath__ChooseGaragePerfPath(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x509d70 IsPerformanceUpgradeLocked

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

uint IsPerformanceUpgradeLocked(void)

{
  char cVar1;
  undefined4 in_EAX;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = CONCAT31((int3)((uint)in_EAX >> 8),DAT_00735ec1);
  if ((DAT_00735ec1 == '\0') && ((DAT_00745e40 != 2 || (uVar2 = DAT_007677ac, DAT_007677ac == 0))))
  {
    uVar2 = FUN_0059e5f0();
    if ((char)uVar2 == '\0') {
      uVar3 = FUN_005a0350();
      cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,uVar3);
      return (uint)(cVar1 == '\0');
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x509dd0 ChooseGaragePerfPath::ChooseGaragePerfPath

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * ChooseGaragePerfPath__ChooseGaragePerfPath(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688f1e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar2 = param_1 + 0x11;
  *param_1 = &PTR_ChooseGaragePerfPath__scalar_deleting_destructor_006c0244;
  *puVar2 = puVar2;
  param_1[0x12] = puVar2;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_4 = CONCAT31(local_4._1_3_,2);
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar3 + 0x18));
  }
  pcVar4 = "PERFORMANCE_ENGINE";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(2,0xbce3a657,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_TRANSMISSION";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(6,0xa4f13384,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_TIRES";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(7,0x88243aa3,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_ECU";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(5,0xd3f2cf84,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_TURBO";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(3,0xdb62de8,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_BRAKES";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(8,0x549c1021,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_WEIGHT_REDUCTION";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(0,0x658c4f84,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_SUSPENSION";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(1,0x674389a7,"MU_GaragePerformanceTuner.fng");
  pcVar4 = "PERFORMANCE_NITROUS";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  ChooseGaragePerfPath__AddCategory(4,0x49cb9b30,"MU_GaragePerformanceTuner.fng");
  puVar2 = (undefined4 *)param_1[0x11];
  do {
    if (puVar2 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_0050a033:
      FUN_004f8960();
      ChooseGaragePerfPath__RedrawHeading();
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = pvStack_c;
      return param_1;
    }
    if (puVar2[2] == DAT_006f8864) {
      param_1[0x10] = puVar2;
      goto LAB_0050a033;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


// ==== 0x50a070 ChooseGaragePerfPath::AddCategory

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void ChooseGaragePerfPath__AddCategory(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  int in_EAX;
  int *piVar4;
  int iVar5;
  int unaff_EBX;
  
  piVar4 = _malloc(0x18);
  piVar4[2] = param_1;
  piVar4[3] = param_2;
  piVar4[4] = param_3;
  if (DAT_00745e40 == 1) {
    cVar2 = FUN_005a4370();
    if (cVar2 != '\0') {
      uVar3 = 1;
      goto LAB_0050a0b6;
    }
  }
  uVar3 = 0;
LAB_0050a0b6:
  *(undefined1 *)(piVar4 + 5) = uVar3;
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  *puVar1 = piVar4;
  *(int **)(in_EAX + 0x48) = piVar4;
  *piVar4 = in_EAX + 0x44;
  piVar4[1] = (int)puVar1;
  iVar5 = FUN_004f8730(in_EAX + 0x4c,piVar4[2],0,1);
  if (((unaff_EBX != 0) && (iVar5 != 0)) && (*(int *)(iVar5 + 0x24) != unaff_EBX)) {
    *(int *)(iVar5 + 0x24) = unaff_EBX;
    *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x50a100 ChooseGaragePerfPath::ScrollPickables

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void ChooseGaragePerfPath__ScrollPickables(void)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0x40);
  if (unaff_EDI == -0x6edfbf62) {
    if ((iVar1 != *(int *)(in_EAX + 0x44)) && (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EDI == -0x4a68e40f) &&
           (*(undefined4 **)(in_EAX + 0x40) != *(undefined4 **)(in_EAX + 0x48))) &&
          (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x40) = **(undefined4 **)(in_EAX + 0x40);
  }
  if (iVar1 != *(int *)(in_EAX + 0x40)) {
    FUN_004f8910();
    ChooseGaragePerfPath__RedrawHeading();
    if (unaff_EDI == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
  }
  return;
}


// ==== 0x50a1a0 ChooseGaragePerfPath::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void ChooseGaragePerfPath__RedrawHeading(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar2 + 0x18));
  }
  iVar2 = *(int *)(unaff_EBX + 0x40);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  FUN_00495f00(*(undefined4 *)(iVar2 + 0xc));
  uVar3 = *(undefined4 *)(iVar2 + 8);
  cVar1 = IsPerformanceUpgradeLocked(uVar3);
  if (cVar1 != '\0') {
    cVar1 = IsPerformanceUpgradeLocked(uVar3);
    if (cVar1 != '\0') {
      cVar1 = IsPerformanceUpgradeLocked(uVar3);
      if ((cVar1 != '\0') && (DAT_0073572c == '\0')) {
        FUN_00495fc0();
        return;
      }
    }
  }
  if (*(int *)(unaff_EBX + 0xc) != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_0050a28e;
    }
  }
  if (DAT_0073578c != 0) {
    uVar3 = FUN_004ef050(0xa8a3681a);
    FEObject__SetInvisible(uVar3);
    return;
  }
  iVar2 = 0;
LAB_0050a28e:
  FEObject__SetInvisible(iVar2);
  return;
}


// ==== 0x50a2a0 ChooseGaragePerfPath::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 ChooseGaragePerfPath__MoveForwardPackage(void)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar1 = *(int *)(in_EAX + 0x40);
  if (*(int *)(iVar1 + 0x10) == 0) {
    return 0;
  }
  uVar2 = 0;
  switch(*(undefined4 *)(iVar1 + 8)) {
  case 0:
    uVar2 = 0x41;
    break;
  case 1:
    uVar2 = 0x49;
    break;
  case 2:
    uVar2 = 0x42;
    break;
  case 3:
    uVar2 = 0x43;
    break;
  case 4:
    uVar2 = 0x44;
    break;
  case 5:
    uVar2 = 0x48;
    break;
  case 6:
    uVar2 = 0x45;
    break;
  case 7:
    uVar2 = 0x46;
    break;
  case 8:
    uVar2 = 0x47;
  }
  if (DAT_006f1dd8 != 0) {
    if (uVar2 < 0x12) {
      piVar5 = *(int **)(DAT_007356a8 + 0xc0);
      if (piVar5 == (int *)0x0) goto LAB_0050a33f;
    }
    else {
      if ((0x52 < uVar2) || (piVar5 = *(int **)(DAT_007356a8 + 0xbc), piVar5 == (int *)0x0))
      goto LAB_0050a33f;
      uVar2 = uVar2 - 0x12;
    }
    (**(code **)(*piVar5 + 0x14))(uVar2);
  }
LAB_0050a33f:
  DAT_006f8864 = *(undefined4 *)(iVar1 + 8);
  DAT_00735730 = *(undefined4 *)(iVar1 + 0xc);
  DAT_006f889c = DAT_006f8864;
  GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
  iVar1 = DAT_0073578c;
  uVar4 = *(undefined4 *)(in_EAX + 0xc);
  if (DAT_0073578c != 0) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    uVar4 = 0;
    if (iVar3 != 0) {
      uVar4 = 0;
      if (*(int *)(iVar3 + 0x18) != 0) {
        uVar4 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
      }
    }
  }
  return uVar4;
}


// ==== 0x50a3c0 ChooseGaragePerfPath::NotificationMessage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall ChooseGaragePerfPath__NotificationMessage(int param_1,uint param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0073578c;
  if (0xb5971bf1 < param_2) {
    if (param_2 == 0xc519bfc0) {
      if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) &&
         (*(int *)(iVar3 + 0x18) != 0)) {
        cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar3 + 0x18));
      }
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar4 + 0x18));
      }
      GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
      iVar4 = DAT_0073578c;
      DAT_00745e4c = 0;
      if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) &&
         (*(int *)(iVar3 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar4 + 8),*(int *)(iVar3 + 0x18));
      }
    }
    else if (param_2 == 0xc98356ba) {
      FUN_004f89d0();
      FUN_004f7d30();
      return;
    }
    return;
  }
  if (param_2 != 0xb5971bf1) {
    if (param_2 == 0xc407210) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
      cVar2 = IsPerformanceUpgradeLocked(uVar1);
      if ((((cVar2 == '\0') || (cVar2 = IsPerformanceUpgradeLocked(uVar1), cVar2 == '\0')) ||
          (cVar2 = IsPerformanceUpgradeLocked(uVar1), cVar2 == '\0')) || (DAT_0073572c != '\0')) {
        ChooseGaragePerfPath__MoveForwardPackage();
        return;
      }
      if (DAT_006f1dd8 == 0) {
        return;
      }
      if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
        return;
      }
      (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
      return;
    }
    if (param_2 == 0x911ab364) {
      GarageCategoryVisual__MoveBackPackage(param_1);
      return;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  ChooseGaragePerfPath__ScrollPickables();
  return;
}


// ==== 0x50a570 CreateGaragePerfTuner

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGaragePerfTuner(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688ef3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x98);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GaragePerfTuner__GaragePerfTuner(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50a5d0 GaragePerfTuner::GaragePerfTuner

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GaragePerfTuner__GaragePerfTuner(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x11;
  *param_1 = &PTR_GaragePerfTuner__scalar_deleting_destructor_006c01cc;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  uVar4 = (uint)DAT_0073572c;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x25] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  param_1[0x24] = uVar4;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar3 + 0x18));
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0xb7fc3e,0,0,*(int *)(iVar3 + 0x18));
  }
  switch(DAT_006f889c) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  default:
    goto switchD_0050a6bd_default;
  }
  bStringHash();
switchD_0050a6bd_default:
  bVar5 = DAT_007677ac == 0;
  if (DAT_00745e40 == 1) {
    iVar3 = FUN_005a4480();
    GaragePerfTuner__AddLevel(0,0x77f92738,iVar3 == 0);
    GaragePerfTuner__AddLevel(1,0x9a08dd84,iVar3 == 1);
    GaragePerfTuner__AddLevel(2,0x9a08dd85,iVar3 == 2);
    bVar5 = iVar3 == 3;
  }
  else {
    GaragePerfTuner__AddLevel(0,0x77f92738,0);
    if ((((((bVar5) &&
           (cVar2 = GaragePerfTuner__IsUpgradeUnlockedForCareer(param_1,DAT_006f889c), cVar2 == '\0'
           )) || (GaragePerfTuner__AddLevel(1,0x9a08dd84,0), bVar5)) &&
         (cVar2 = GaragePerfTuner__IsUpgradeUnlockedForCareer(param_1,DAT_006f889c), cVar2 == '\0'))
        || (GaragePerfTuner__AddLevel(2,0x9a08dd85,0), bVar5)) &&
       (cVar2 = GaragePerfTuner__IsUpgradeUnlockedForCareer(param_1,DAT_006f889c), cVar2 == '\0'))
    goto LAB_0050a814;
    bVar5 = false;
  }
  GaragePerfTuner__AddLevel(3,0x9a08dd86,bVar5);
LAB_0050a814:
  iVar3 = DAT_006f889c;
  param_1[0x22] = 0;
  puVar1 = (undefined4 *)param_1[0x11];
  do {
    if (puVar1 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_0050a84e:
      FUN_004f8960();
      GaragePerfTuner__RedrawHeading(param_1);
      GarageManager__PreviewPhysicsUpgrade();
      iVar3 = DAT_006f889c;
      *(undefined1 *)(param_1 + 8) = 1;
      uVar4 = 0;
      param_1[0x23] = DAT_0073ad3c;
      switch(iVar3) {
      case 0:
        uVar4 = 0x4000;
        break;
      case 1:
        uVar4 = 0x400;
        break;
      case 2:
        uVar4 = 0x100;
        break;
      case 3:
        uVar4 = 0x2000;
        break;
      case 4:
        uVar4 = 0x200;
        break;
      case 5:
        uVar4 = 0x80;
        break;
      case 6:
        uVar4 = 0x1000;
        break;
      case 7:
        uVar4 = 0x800;
        break;
      case 8:
        uVar4 = 0x40;
      }
      if ((((DAT_00745e40 == 1) && (uVar4 != 0)) && ((DAT_0076029c & uVar4) == 0)) &&
         (iVar3 = FUN_004cd440(), iVar3 != -1)) {
        EAXSound__PlaySpeechStream(0xffffffff);
        DAT_0076029c = DAT_0076029c | uVar4;
      }
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar1[2] == *(int *)(&DAT_00745728 + iVar3 * 4)) {
      param_1[0x10] = puVar1;
      goto LAB_0050a84e;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x50a980 GaragePerfTuner::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GaragePerfTuner__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GaragePerfTuner___GaragePerfTuner();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50a9a0 GaragePerfTuner::_GaragePerfTuner

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GaragePerfTuner___GaragePerfTuner(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068731e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_GaragePerfTuner__scalar_deleting_destructor_006c01cc;
  local_4 = 2;
  GarageManager__PreviewPart();
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar3 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar3 != 0) {
    GarageMainScreen__SetRideInfo(iVar3,&DAT_00748850,2);
  }
  if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
     (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0xa0))();
  }
  FUN_004f84d0();
  piVar1 = (int *)param_1[0x11];
  while (piVar1 != param_1 + 0x11) {
    iVar3 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    _free(piVar1);
    piVar1 = (int *)param_1[0x11];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x50aa90 GaragePerfTuner::IsUpgradeLocked

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

uint GaragePerfTuner__IsUpgradeLocked(uint param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  uint uVar1;
  
  uVar1 = CONCAT31((int3)((uint)in_EAX >> 8),DAT_00735ec1);
  if ((DAT_00735ec1 == '\0') && (uVar1 = param_1, *(int *)(param_1 + 0x90) == 0)) {
    uVar1 = IsPerformanceUpgradeLocked(param_2);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x50aac0 GaragePerfTuner::IsNextUpgradeLevel

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 GaragePerfTuner__IsNextUpgradeLevel(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((DAT_007677ac != 0) || (DAT_00735ec1 != '\0')) || (*(int *)(param_1 + 0x90) != 0)) ||
     (uVar1 = 0, *(int *)(&DAT_00745728 + param_2 * 4) + 1 == param_3)) {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== 0x50ab00 GaragePerfTuner::IsUpgradeUnlockedForCareer

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 __fastcall
GaragePerfTuner__IsUpgradeUnlockedForCareer(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((DAT_00745e40 == 2) && (uVar1 = 0, DAT_0073766c != 0)) {
    piVar3 = (int *)(DAT_00737668 + 0x24);
    do {
      if ((piVar3[-1] == 2) && (*piVar3 == param_2)) {
        if (*(char *)(uVar1 * 0x34 + 0x30 + DAT_00737668) != '\0') {
          return 1;
        }
        break;
      }
      uVar1 = uVar1 + 1;
      piVar3 = piVar3 + 0xd;
    } while (uVar1 < DAT_0073766c);
  }
  if (((DAT_007677ac == 0) && (DAT_00735ec1 == '\0')) && (*(int *)(param_3 + 0x90) == 0)) {
    uVar2 = FUN_005a3670();
    return uVar2;
  }
  return 1;
}


// ==== 0x50ab90 GaragePerfTuner::CanPlayerPurchaseUpgradeLevel

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined1 GaragePerfTuner__CanPlayerPurchaseUpgradeLevel(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int extraout_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  if ((DAT_00735ec1 == '\0') && (*(int *)(in_EAX + 0x90) == 0)) {
    if (DAT_00745e40 == 1) {
      cVar1 = GaragePerfTuner__IsUpgradeLocked(in_EAX,unaff_EDI,unaff_ESI);
      if (cVar1 != '\0') {
        return 0;
      }
      if (DAT_0073440c == '\0') {
        FUN_005a0350();
        FUN_005a08b0();
        iVar2 = Career__GetCash(&DAT_0075eef8);
        if (iVar2 < extraout_ECX) {
          return 0;
        }
      }
    }
    return 1;
  }
  return 1;
}


// ==== 0x50abf0 GaragePerfTuner::AddLevel

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GaragePerfTuner__AddLevel(int param_1,int param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar2 = _malloc(0x18);
  piVar2[2] = param_1;
  *(undefined1 *)(piVar2 + 5) = param_3;
  piVar2[3] = param_2;
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  *puVar1 = piVar2;
  *(int **)(in_EAX + 0x48) = piVar2;
  piVar2[1] = (int)puVar1;
  *piVar2 = in_EAX + 0x44;
  iVar3 = FUN_004f8730(in_EAX + 0x4c,piVar2[2],0,1);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x24) != unaff_EDI)) {
    *(int *)(iVar3 + 0x24) = unaff_EDI;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x50ac50 GaragePerfTuner::ScrollPickables

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GaragePerfTuner__ScrollPickables(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  FUN_004af5d0();
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (param_1 == -0x6edfbf62) {
    if ((((iVar1 != *(int *)(unaff_EDI + 0x44)) &&
         (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
        (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
      (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x50fe5db4,0,0,*(int *)(iVar2 + 0x18));
    }
    if ((*(int *)(unaff_EDI + 0x40) != *(int *)(unaff_EDI + 0x44)) &&
       (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(*(int *)(unaff_EDI + 0x40) + 4);
    }
  }
  else if (param_1 == -0x4a68e40f) {
    if (iVar1 != *(int *)(unaff_EDI + 0x48)) {
      FUN_004c96c0(0x50fe5db4);
    }
    if ((*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48)) &&
       (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
    }
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    FUN_004f8910();
    IsPerformanceUpgradeLocked(DAT_006f889c);
    GarageManager__PreviewPhysicsUpgrade();
    *(undefined4 *)(unaff_EDI + 0x88) = DAT_0073ad3c;
    GaragePerfTuner__RedrawHeading(unaff_EDI);
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x50ada0 GaragePerfTuner::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GaragePerfTuner__RedrawHeading(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_4c [8];
  char local_2c [32];
  int local_c;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x40);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  FUN_00495f00(DAT_00735730);
  local_c = *(int *)(&DAT_00745728 + DAT_006f889c * 4);
  uVar2 = GarageManager__GetMsgForUpgradeLevel(&DAT_00744ff0);
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int *)(iVar3 + 0x14) != 0)) {
    FUN_004f7c00(uVar2,0,0,*(int *)(iVar3 + 0x18));
  }
  iVar3 = *(int *)(local_8 + 8);
  uVar2 = 0;
  if (iVar3 == 0) {
    uVar2 = FUN_004f42f0("MOD_DESC_STOCK");
  }
  else {
    switch(DAT_006f889c) {
    case 0:
      uVar2 = FUN_004f42f0("MOD_DESC_WEIGHT_%d",iVar3);
      break;
    case 1:
      uVar2 = FUN_004f42f0("MOD_DESC_SUSP_%d",iVar3);
      break;
    case 2:
      uVar2 = FUN_004f42f0("MOD_DESC_ENG_EXHAUST_%d",iVar3);
      break;
    case 3:
      uVar2 = FUN_004f42f0("MOD_DESC_TURBO_%d",iVar3);
      break;
    case 4:
      uVar2 = FUN_004f42f0("MOD_DESC_NITROUS_%d",iVar3);
      break;
    case 5:
      uVar2 = FUN_004f42f0("MOD_DESC_ECU_FUEL_%d",iVar3);
      break;
    case 6:
      uVar2 = FUN_004f42f0("MOD_DESC_TRANS_%d",iVar3);
      break;
    case 7:
      uVar2 = FUN_004f42f0("MOD_DESC_TIRES_%d",iVar3);
      break;
    case 8:
      uVar2 = FUN_004f42f0("MOD_DESC_BRAKE_%d",iVar3);
    }
  }
  if ((*(int *)(param_1 + 0x88) == 0) || (*(int *)(param_1 + 0x88) == 0x7fffffff)) {
    FUN_00416bb0(uVar2);
  }
  else {
    FEngPrintf(&DAT_006b9172);
  }
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar5 = 0x20;
  pcVar4 = local_2c;
  do {
    cVar1 = pcVar4[iVar3 - (int)local_2c];
    iVar5 = iVar5 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    pcVar4 = pcVar4 + 1;
  } while (iVar5 != 0);
  puVar6 = local_4c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (*(int *)(local_8 + 8) == local_c) {
    FUN_00565da0(" (%s)",local_2c);
    puVar6 = local_4c;
  }
  else {
    puVar6 = (undefined4 *)&DAT_006b9172;
  }
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FEngPrintf(&DAT_006cc578,iVar3,puVar6);
  FUN_00495f00(DAT_00735730);
  FEngPrintf(&DAT_006ca778,local_c);
  if (((DAT_00735ec1 == '\0') && (*(int *)(param_1 + 0x90) == 0)) &&
     (cVar1 = IsPerformanceUpgradeLocked(DAT_006f889c), cVar1 != '\0')) {
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c != 0) {
        uVar2 = FUN_004ef050(0xa8a3681a);
        FEObject__SetVisible(uVar2);
        goto LAB_0050b0a2;
      }
      iVar3 = 0;
    }
    FEObject__SetVisible(iVar3);
  }
  else {
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0xa8a3681a);
      }
    }
    FEObject__SetInvisible(iVar3);
  }
LAB_0050b0a2:
  switch(DAT_006f889c) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
  }
  if ((DAT_00777b4c == 1) &&
     (cVar1 = GaragePerfTuner__IsUpgradeUnlockedForCareer(param_1,DAT_006f889c), cVar1 == '\0')) {
    uVar2 = FUN_005a08b0();
    FUN_00495fc0();
    FEngPrintf(&DAT_006ca778,uVar2);
    return;
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0x7c5a7469);
      FEObject__SetInvisible(uVar2);
      return;
    }
    iVar3 = 0;
  }
  FEObject__SetInvisible(iVar3);
  return;
}


// ==== 0x50b200 GaragePerfTuner::MoveBackPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GaragePerfTuner__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x8efaa777,0,0,*(int *)(iVar1 + 0x18));
  }
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x50b280 GaragePerfTuner::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GaragePerfTuner__MoveForwardPackage(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return uVar3;
}


// ==== 0x50b2d0 GaragePerfTuner::NotificationMessage

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __thiscall GaragePerfTuner__NotificationMessage(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
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
  undefined4 local_10;
  undefined4 local_c;
  
  iVar3 = DAT_0073578c;
  if (0xb5971bf1 < param_2) {
    if (param_2 == 0xc519bfc0) {
      if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
         (*(int *)(iVar2 + 0x18) != 0)) {
        cFEng__PopPackage(*(undefined4 *)(iVar3 + 8),*(int *)(iVar2 + 0x18));
      }
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar3 + 0x18));
      }
      GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
      iVar3 = DAT_0073578c;
      DAT_00745e4c = 0;
      if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
         (*(int *)(iVar2 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar3 + 8),*(int *)(iVar2 + 0x18));
      }
    }
    else {
      if (param_2 == 0xc98356ba) {
        if (((*(int *)(param_1 + 0x88) != 0) && (*(int *)(param_1 + 0x88) != 0x7fffffff)) &&
           (_K_ONE < (float)(DAT_0073ad3c - *(int *)(param_1 + 0x88)) * 0.00025)) {
          *(undefined4 *)(param_1 + 0x88) = 0;
          GaragePerfTuner__RedrawHeading(param_1);
        }
        FUN_004f89d0();
        FUN_004f7d30();
        return;
      }
      if (param_2 == 0xf0aadebb) {
        GarageManager__InstallPhysicsUpgrade();
        GaragePerfTuner__RedrawHeading(param_1);
        return;
      }
    }
    return;
  }
  if (param_2 != 0xb5971bf1) {
    if (param_2 == 0xc407210) {
      FUN_004af5d0();
      iVar2 = DAT_006f889c;
      iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 8);
      *(int *)(param_1 + 0x94) = iVar3;
      if ((iVar3 == 0) && (*(int *)(&DAT_00745728 + iVar2 * 4) != 0)) {
        local_1c = 0;
        local_18 = 0;
        local_38 = 0x76d94941;
        local_30 = 0xf0aadebb;
        local_34 = 0x639;
        local_28 = 0;
        local_2c = 0x541389e5;
        local_24 = 0;
        local_20 = 0xb8a7c6cc;
        FUN_004dc6e0(&local_38,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      DAT_006f88a0 = iVar3;
      if ((((DAT_00745e40 != 1) || (iVar3 == 0)) ||
          (cVar1 = GaragePerfTuner__IsUpgradeUnlockedForCareer(param_1,iVar2), cVar1 == '\0')) ||
         (*(int *)(&DAT_00745728 + iVar2 * 4) == iVar3)) {
        cVar1 = GaragePerfTuner__IsUpgradeLocked(param_1,iVar2,iVar3);
        if (cVar1 != '\0') {
          return;
        }
        if (*(int *)(&DAT_00745728 + iVar2 * 4) == iVar3) {
          local_10 = 0x639;
          local_14 = 0x368294c0;
          local_c = 0;
          FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        cVar1 = GaragePerfTuner__CanPlayerPurchaseUpgradeLevel();
        if (cVar1 == '\0') {
          local_10 = 0x639;
          local_14 = 0x2c0344a3;
          local_c = 0;
          FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        cVar1 = GaragePerfTuner__IsNextUpgradeLevel(param_1,iVar2,iVar3);
        if (cVar1 == '\0') {
          local_14 = 0xe82e5ffb;
          if ((iVar3 != 2) && (iVar3 == 3)) {
            local_14 = 0xe82e5ffc;
          }
          local_10 = 0x639;
          local_c = 0;
          FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
      }
      GaragePerfTuner__MoveForwardPackage();
      return;
    }
    if (param_2 == 0x911ab364) {
      GarageManager__SyncActualToEditing(0);
      GaragePerfTuner__MoveBackPackage(param_1);
      return;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  GaragePerfTuner__ScrollPickables(param_2);
  return;
}


// ==== 0x50b610 GaragePerfBrandPackage::_GaragePerfBrandPackage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GaragePerfBrandPackage___GaragePerfBrandPackage(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GaragePerfBrandPackage__scalar_deleting_destructor_006c0288;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x50b660 GaragePerfBrandPackage::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GaragePerfBrandPackage__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GaragePerfBrandPackage___GaragePerfBrandPackage();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50b680 CreateGaragePerfBrand

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGaragePerfBrand(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688ed3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GaragePerfBrandPackage__GaragePerfBrandPackage(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50b6e0 GaragePerfBrandPackage::GaragePerfBrandPackage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GaragePerfBrandPackage__GaragePerfBrandPackage(undefined4 *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  int iVar8;
  byte local_40;
  byte local_3f [31];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GaragePerfBrandPackage__scalar_deleting_destructor_006c0288;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  local_18 = param_1 + 0x13;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(local_18,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  param_1[0x22] = 0;
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar4 + 0x18));
  }
  local_1c = (undefined4 *)(DAT_006f889c * 0x10 + DAT_00734400);
  if (local_1c != (undefined4 *)0x0) {
    iVar4 = 0;
    if (DAT_006f88a0 == 1) {
      iVar4 = local_1c[1];
    }
    else if (DAT_006f88a0 == 2) {
      iVar4 = local_1c[2];
    }
    else if (DAT_006f88a0 == 3) {
      iVar4 = local_1c[3];
    }
    if (0 < iVar4) {
      local_20 = param_1 + 0x11;
      param_2 = 1;
      local_14 = iVar4;
      do {
        uVar5 = Table34A0A__Find(*local_1c);
        bSPrintf_regdst(0x20,"GENERIC_LEVEL%d",param_2);
        iVar4 = -1;
        pbVar6 = &local_40;
        bVar2 = local_40;
        while (bVar2 != 0) {
          pbVar1 = pbVar6 + 1;
          iVar4 = iVar4 * 0x21 + (uint)bVar2;
          pbVar6 = pbVar6 + 1;
          bVar2 = *pbVar1;
        }
        puVar7 = _malloc(0x10);
        puVar7[3] = uVar5;
        puVar7[2] = iVar4;
        puVar3 = (undefined4 *)local_20[1];
        *puVar3 = puVar7;
        local_20[1] = puVar7;
        puVar7[1] = puVar3;
        *puVar7 = local_20;
        iVar8 = FUN_004f8730(local_18,puVar7[2],0,1);
        if ((iVar8 != 0) && (*(int *)(iVar8 + 0x24) != iVar4)) {
          *(int *)(iVar8 + 0x24) = iVar4;
          *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | 0x400000;
        }
        param_2 = param_2 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
      local_14 = 0;
    }
    param_1[0x22] = 0;
    GarageManager__PreviewPhysicsUpgrade();
    for (puVar3 = (undefined4 *)param_1[0x11]; puVar3 != param_1 + 0x11;
        puVar3 = (undefined4 *)*puVar3) {
      if (puVar3[2] == 0) {
        param_1[0x10] = puVar3;
        goto LAB_0050b8b2;
      }
    }
    param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_0050b8b2:
    FUN_004f8960();
    GaragePerfBrandPackage__RedrawHeading(param_1);
    *(undefined1 *)(param_1 + 8) = 1;
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x50b8f0 GaragePerfBrandPackage::ScrollPickables

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GaragePerfBrandPackage__ScrollPickables(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  FUN_004af5d0();
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (unaff_EBX == -0x6edfbf62) {
    if (iVar1 != *(int *)(unaff_EDI + 0x44)) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x50fe5db4,0,0,*(int *)(iVar2 + 0x18));
      }
    }
    if ((*(int *)(unaff_EDI + 0x40) != *(int *)(unaff_EDI + 0x44)) &&
       (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(*(int *)(unaff_EDI + 0x40) + 4);
    }
  }
  else if (unaff_EBX == -0x4a68e40f) {
    if (iVar1 != *(int *)(unaff_EDI + 0x48)) {
      FUN_004c96c0(0x50fe5db4);
    }
    if ((*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48)) &&
       (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
    }
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    FUN_004f8910();
    *(undefined4 *)(unaff_EDI + 0x88) = DAT_0073ad3c;
    GaragePerfBrandPackage__RedrawHeading(unaff_EDI);
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x50b9e0 GaragePerfBrandPackage::RedrawHeading

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GaragePerfBrandPackage__RedrawHeading(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char cStack_170;
  char acStack_16f [47];
  char cStack_140;
  char acStack_13f [31];
  char local_120 [288];
  
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar3 + 0x18));
  }
  iVar3 = *(int *)(param_1 + 0x40);
  local_120[0] = '\0';
  iVar4 = *(int *)(iVar3 + 0xc);
  iVar8 = 0;
  if (*(char *)(iVar4 + 6) != '\0') {
    do {
      bSPrintf_regdst(0x20,"BRAND_%d",*(undefined1 *)(iVar4 + 7 + iVar8));
      pcVar6 = &cStack_140;
      cVar1 = cStack_140;
      while (cVar1 != '\0') {
        pcVar7 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar7;
      }
      iVar4 = LanguageStrings__FindByHash();
      if (iVar4 == 0) {
        iVar4 = LanguageStrings__FindByHash();
      }
      bSPrintf_regdst(0x20,&DAT_006cc580,iVar4);
      iVar4 = 0;
      cVar1 = cStack_170;
      pcVar6 = &cStack_170;
      if (local_120[0] != '\0') {
        pcVar7 = local_120;
        iVar5 = iVar4;
        do {
          local_120[iVar5] = *pcVar7;
          iVar4 = iVar5 + 1;
          iVar2 = iVar5 + 1;
          pcVar7 = local_120 + iVar5 + 1;
          iVar5 = iVar4;
        } while (local_120[iVar2] != '\0');
      }
      while (cVar1 != '\0') {
        local_120[iVar4] = cVar1;
        iVar4 = iVar4 + 1;
        cVar1 = pcVar6[1];
        pcVar6 = pcVar6 + 1;
      }
      local_120[iVar4] = '\0';
      iVar4 = *(int *)(iVar3 + 0xc);
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)*(byte *)(iVar4 + 6));
  }
  FEngPrintf(local_120);
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  bSPrintf_regdst(0x30,"%s %d",iVar4,*(undefined2 *)(*(int *)(iVar3 + 0xc) + 4));
  FEngPrintf(&cStack_170);
  return;
}


// ==== 0x50bb70 GaragePerfBrandPackage::IsInstallingUpgrade

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

bool GaragePerfBrandPackage__IsInstallingUpgrade(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (DAT_00745e40 != 1) {
    return DAT_00745e40 == 2;
  }
  uVar3 = FUN_005a0350();
  iVar2 = (int)uVar3;
  if (((iVar2 != 8) && (iVar2 != 5)) && (iVar2 != -1)) {
    if (((int)((ulonglong)uVar3 >> 0x20) != 0) &&
       (cVar1 = PartStore__Has(&DAT_0075f344), cVar1 == '\0')) {
      return false;
    }
    return true;
  }
  return false;
}


// ==== 0x50bbc0 GaragePerfBrandPackage::IsBuyingUpgrade

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GaragePerfBrandPackage__IsBuyingUpgrade(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (DAT_00745e40 == 1) {
    uVar3 = FUN_005a0350();
    iVar2 = (int)uVar3;
    if (((iVar2 == 8) || (iVar2 == 5)) || (iVar2 == -1)) {
      return 1;
    }
    if (((int)((ulonglong)uVar3 >> 0x20) != 0) &&
       (cVar1 = PartStore__Has(&DAT_0075f344), cVar1 == '\0')) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x50bc10 GaragePerfBrandPackage::NotificationMessage

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall GaragePerfBrandPackage__NotificationMessage(int param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  iVar6 = DAT_006f889c;
  local_8 = param_1;
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        cVar2 = GaragePerfBrandPackage__IsBuyingUpgrade(param_1,DAT_006f889c);
        cVar3 = GaragePerfBrandPackage__IsInstallingUpgrade(param_1,iVar6);
        if (cVar3 != '\0') {
          local_10 = 0;
          local_c = 0;
          local_2c = 0x76d94941;
          local_24 = 0xf0aadebb;
          local_28 = 0x639;
          local_1c = 0;
          local_20 = 0x541389e5;
          local_18 = 0;
          local_14 = 0xb8a7c6cc;
          FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (cVar2 == '\0') {
          return;
        }
        local_10 = 0;
        local_c = 0;
        local_1c = 0;
        local_18 = 0;
        local_2c = 0x39223856;
        local_24 = 0x2f6484d0;
        local_28 = 0x639;
        local_20 = 0x541389e5;
        local_14 = 0xb8a7c6cc;
        FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x2f6484d0) {
        iVar6 = *(int *)(param_1 + 0x40);
        if (DAT_00745e40 == 1) {
          FUN_005a25a0();
        }
        GarageManager__InstallPhysicsUpgrade();
        iVar8 = DAT_006f889c;
        iVar5 = *(int *)(iVar6 + 0xc);
        if (*(char *)(iVar5 + 6) != '\0') {
          iVar7 = 0;
          do {
            uVar4 = (uint)*(byte *)(iVar5 + 7 + iVar7);
            uVar1 = *(uint *)(&DAT_00760158 + uVar4 * 4);
            *(uint *)(&DAT_00760158 + uVar4 * 4) = uVar1 | 1;
            *(uint *)(&DAT_00760158 + uVar4 * 4) = uVar1 | 3;
            if (iVar8 == 3) {
              switch(uVar4) {
              case 6:
                *(undefined1 *)(DAT_00744ff8 + 0xc) = 0;
                break;
              default:
                *(undefined1 *)(DAT_00744ff8 + 0xc) = 0xff;
                break;
              case 0x14:
                *(undefined1 *)(DAT_00744ff8 + 0xc) = 1;
                break;
              case 0x16:
                *(undefined1 *)(DAT_00744ff8 + 0xc) = 2;
                break;
              case 0x2e:
                *(undefined1 *)(DAT_00744ff8 + 0xc) = 3;
                break;
              case 0x32:
                *(undefined1 *)(DAT_00744ff8 + 0xc) = 4;
              }
            }
            iVar5 = *(int *)(iVar6 + 0xc);
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)(uint)*(byte *)(iVar5 + 6));
        }
        GarageManager__SyncActualToEditing(0);
        iVar6 = local_8;
        iVar5 = FEngFindPackage();
        if (iVar5 != 0) {
          *(undefined4 *)(iVar5 + 0x1c) = 0xff;
        }
        GarageCategoryVisual__MoveBackPackage(iVar6);
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageManager__SyncActualToEditing(0);
      GarageCategoryVisual__MoveBackPackage(param_1);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 == 0xc98356ba) {
      iVar6 = *(int *)(param_1 + 0x88);
      if (((iVar6 != 0) && (iVar6 != 0x7fffffff)) &&
         (_K_ONE < (float)(DAT_0073ad3c - iVar6) * 0.00025)) {
        *(undefined4 *)(param_1 + 0x88) = 0;
        GaragePerfBrandPackage__RedrawHeading(param_1);
      }
      FUN_004f89d0();
      FUN_004f7d30();
      return;
    }
    if (param_2 != 0xf0aadebb) {
      return;
    }
    GarageManager__InstallPhysicsUpgrade();
    if (DAT_006f889c == 3) {
      iVar6 = *(int *)(param_1 + 0x40);
      iVar5 = *(int *)(iVar6 + 0xc);
      iVar8 = 0;
      if (*(char *)(iVar5 + 6) != '\0') {
        do {
          switch(*(undefined1 *)(iVar5 + 7 + iVar8)) {
          case 6:
            *(undefined1 *)(DAT_00744ff8 + 0xc) = 0;
            break;
          default:
            *(undefined1 *)(DAT_00744ff8 + 0xc) = 0xff;
            break;
          case 0x14:
            *(undefined1 *)(DAT_00744ff8 + 0xc) = 1;
            break;
          case 0x16:
            *(undefined1 *)(DAT_00744ff8 + 0xc) = 2;
            break;
          case 0x2e:
            *(undefined1 *)(DAT_00744ff8 + 0xc) = 3;
            break;
          case 0x32:
            *(undefined1 *)(DAT_00744ff8 + 0xc) = 4;
          }
          iVar5 = *(int *)(iVar6 + 0xc);
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)*(byte *)(iVar5 + 6));
      }
    }
    GarageManager__SyncActualToEditing(0);
    iVar6 = FEngFindPackage();
    if (iVar6 != 0) {
      *(undefined4 *)(iVar6 + 0x1c) = 0xff;
    }
    GarageCategoryVisual__MoveBackPackage(param_1);
    return;
  }
  GaragePerfBrandPackage__ScrollPickables();
  return;
}


// ==== 0x50c020 GaragePaintModScreen::_GaragePaintModScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GaragePaintModScreen___GaragePaintModScreen(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GaragePaintModScreen__scalar_deleting_destructor_006c016c;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x50c070 GaragePaintModScreen::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GaragePaintModScreen__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GaragePaintModScreen___GaragePaintModScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50c090 CreateGaragePaintModScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGaragePaintModScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688eb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GaragePaintModScreen__GaragePaintModScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50c0f0 GaragePaintModScreen::GaragePaintModScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GaragePaintModScreen__GaragePaintModScreen(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688f1e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GaragePaintModScreen__scalar_deleting_destructor_006c016c;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_4 = CONCAT31(local_4._1_3_,2);
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 == 0) || (*(int *)(iVar5 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar2 = *(int *)(DAT_0073578c + 8);
    iVar5 = iVar2 + 0xdc;
    if ((iVar5 == 0) || (iVar5 = FUN_004fd1e0(iVar5), iVar5 == 0)) {
      cFEng__PushPackage(iVar2,"MU_HorizontalBrowserBack.fng",0x10,0);
    }
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int **)(iVar5 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar5 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar5 + 0x18));
  }
  bVar7 = DAT_007677ac != 0;
  pcVar6 = "PAINT_MOD_BASE";
  do {
    pcVar1 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  GaragePaintModScreen__AddCategory(0,0xa3b76154,"PC_ColorPicker.fng",0);
  pcVar6 = "PAINT_MOD_PART_RIMS";
  do {
    pcVar1 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  GaragePaintModScreen__AddCategory(4,0xd223f84a,"PC_ColorPicker.fng",0);
  pcVar6 = "PAINT_MOD_PART_SPOILER";
  do {
    pcVar1 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  GaragePaintModScreen__AddCategory(2,0xa8d7e6ed,"PC_ColorPicker.fng",0);
  if ((bVar7) || (cVar4 = IsPerformanceUpgradeLocked(2), cVar4 == '\0')) {
    pcVar6 = "PAINT_MOD_PART_ENGINE_ACCENT";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    GaragePaintModScreen__AddCategory(8,0x4e875a92,"PC_ColorPicker.fng",0);
    if (!bVar7) goto LAB_0050c2bf;
LAB_0050c2d2:
    pcVar6 = "PAINT_MOD_PART_BRAKE_CALIPERS";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    GaragePaintModScreen__AddCategory(0xb,0x87b7eb73,"PC_ColorPicker.fng",0);
    if (!bVar7) goto LAB_0050c309;
  }
  else {
LAB_0050c2bf:
    cVar4 = IsPerformanceUpgradeLocked(8);
    if (cVar4 == '\0') goto LAB_0050c2d2;
LAB_0050c309:
    cVar4 = Career__IsUpgradeUnlocked(&DAT_0075eef8,2);
    if ((cVar4 == '\0') && (cVar4 = EasterEggs__IsPartUnlocked(), cVar4 == '\0')) goto LAB_0050c365;
  }
  pcVar6 = "PAINT_MOD_PART_MUFFLER_TIP";
  do {
    pcVar1 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  GaragePaintModScreen__AddCategory(5,0xa6343aec,"PC_ColorPicker.fng",0);
LAB_0050c365:
  puVar3 = (undefined4 *)param_1[0x11];
  do {
    if (puVar3 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_0050c385:
      FUN_004f8960();
      GaragePaintModScreen__RedrawHeading();
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = pvStack_c;
      return param_1;
    }
    if (puVar3[2] == DAT_00735738) {
      param_1[0x10] = puVar3;
      goto LAB_0050c385;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x50c3c0 GaragePaintModScreen::AddCategory

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GaragePaintModScreen__AddCategory(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar2 = _malloc(0x14);
  piVar2[2] = param_1;
  piVar2[4] = param_3;
  piVar2[3] = param_2;
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  *puVar1 = piVar2;
  *(int **)(in_EAX + 0x48) = piVar2;
  piVar2[1] = (int)puVar1;
  *piVar2 = in_EAX + 0x44;
  iVar3 = FUN_004f8730(in_EAX + 0x4c,piVar2[2],param_4,1);
  if (((unaff_EDI != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) != unaff_EDI)) {
    *(int *)(iVar3 + 0x24) = unaff_EDI;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x50c430 GaragePaintModScreen::ScrollPickables

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GaragePaintModScreen__ScrollPickables(void)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0x40);
  if (unaff_EDI == -0x6edfbf62) {
    if ((iVar1 != *(int *)(in_EAX + 0x44)) && (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EDI == -0x4a68e40f) &&
           (*(undefined4 **)(in_EAX + 0x40) != *(undefined4 **)(in_EAX + 0x48))) &&
          (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x40) = **(undefined4 **)(in_EAX + 0x40);
  }
  if (iVar1 != *(int *)(in_EAX + 0x40)) {
    FUN_004f8910();
    GaragePaintModScreen__RedrawHeading();
    if (unaff_EDI == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
  }
  return;
}


// ==== 0x50c4d0 GaragePaintModScreen::RedrawHeading

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GaragePaintModScreen__RedrawHeading(void)

{
  int iVar1;
  int unaff_EBX;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = *(int *)(unaff_EBX + 0x40);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  if (iVar1 != 0) {
    FUN_00495f00(*(undefined4 *)(iVar1 + 0xc));
  }
  return;
}


// ==== 0x50c530 GaragePaintModScreen::MoveBackPackage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 GaragePaintModScreen__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  DAT_00735738 = 0;
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x50c590 GaragePaintModScreen::MoveForwardPackage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 GaragePaintModScreen__MoveForwardPackage(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(int *)(*(int *)(in_EAX + 0x40) + 0x10) != 0) {
    DAT_00735738 = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 8);
    GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
    iVar1 = DAT_0073578c;
    uVar3 = *(undefined4 *)(in_EAX + 0xc);
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      uVar3 = 0;
      if (iVar2 != 0) {
        uVar3 = 0;
        if (*(int *)(iVar2 + 0x18) != 0) {
          uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
        }
      }
    }
  }
  return uVar3;
}


// ==== 0x50c5f0 GaragePaintModScreen::NotificationMessage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall GaragePaintModScreen__NotificationMessage(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  local_8 = param_1;
  if (0x9120409e < param_2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xc98356ba) {
        return;
      }
      FUN_004f89d0();
      FUN_004f7d30();
      return;
    }
LAB_0050c7c8:
    GaragePaintModScreen__ScrollPickables();
    return;
  }
  if (param_2 == 0x9120409e) goto LAB_0050c7c8;
  if (param_2 != 0xc407210) {
    if (param_2 != 0x911ab364) {
      return;
    }
    GaragePaintModScreen__MoveBackPackage(param_1);
    return;
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    DAT_006f88a4 = 0;
  }
  else {
    DAT_006f88a4 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
  }
  switch(DAT_006f88a4) {
  case 2:
    iVar2 = 0xb;
    break;
  default:
    goto switchD_0050c657_caseD_3;
  case 4:
    iVar2 = 0x11;
    break;
  case 5:
    iVar2 = 0xf;
    break;
  case 8:
    bVar1 = 0 < DAT_00745730;
    iVar2 = DAT_00745b9c;
    if (DAT_00745b9c == 0) {
      FECarConfig__GetCarType(0xc,DAT_00745730);
      iVar2 = FindPartWithLevel();
      if ((iVar2 == 0) || (*(char *)(iVar2 + 0x11) == '\0')) goto LAB_0050c73b;
LAB_0050c6e2:
      GarageManager__PreviewPart();
    }
LAB_0050c6ee:
    if (*(char *)(iVar2 + 0x11) != '\0') goto LAB_0050c6f5;
    goto LAB_0050c73b;
  case 0xb:
    bVar1 = 0 < DAT_00745748;
    iVar2 = DAT_00745bac;
    if (DAT_00745bac != 0) goto LAB_0050c6ee;
    FECarConfig__GetCarType(0x10,DAT_00745748);
    iVar2 = FindPartWithLevel();
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0x11) != '\0')) goto LAB_0050c6e2;
LAB_0050c73b:
    if (!bVar1) {
      local_14 = 0x639;
      local_18 = 0x1fe3a85a;
      local_10 = 0;
      FUN_004dcbe0(&local_18,"GenericOKDialog.fng",*(undefined4 *)(local_8 + 0xc));
      return;
    }
LAB_0050c6f5:
    GaragePaintModScreen__MoveForwardPackage();
    return;
  }
  if (((&DAT_00745b6c)[iVar2] == 0) || (*(char *)((&DAT_00745b6c)[iVar2] + 0x11) == '\0')) {
    local_14 = 0x639;
    local_18 = 0x1fe3a85a;
    local_10 = 0;
    FUN_004dcbe0(&local_18,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
switchD_0050c657_caseD_3:
  GaragePaintModScreen__MoveForwardPackage();
  return;
}


// ==== 0x50c800 GarageRimsBrandBrowser::_GarageRimsBrandBrowser

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall GarageRimsBrandBrowser___GarageRimsBrandBrowser(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageRimsBrandBrowser__scalar_deleting_destructor_006c01ec;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x50c850 GarageRimsBrandBrowser::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageRimsBrandBrowser__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageRimsBrandBrowser___GarageRimsBrandBrowser();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50c870 HackHackHack_GetRimsBrandHash

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

int HackHackHack_GetRimsBrandHash(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  int unaff_ESI;
  
  pcVar4 = "AUTOSTRADA";
  iVar3 = -1;
  uVar2 = 0x41;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  if (unaff_ESI != iVar3) {
    puVar5 = &DAT_006c0ca0;
    iVar3 = -1;
    uVar2 = 0x50;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = puVar5 + 1;
      uVar2 = (uint)*pbVar1;
      puVar5 = puVar5 + 1;
    } while (*pbVar1 != 0);
    if (unaff_ESI != iVar3) {
      pcVar4 = "SPARCO";
      iVar3 = -1;
      uVar2 = 0x53;
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar4 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar4 = pcVar4 + 1;
      } while (*pbVar1 != 0);
      if (unaff_ESI != iVar3) {
        iVar3 = bStringHash();
        if (unaff_ESI != iVar3) {
          iVar3 = bStringHash();
          if (unaff_ESI != iVar3) {
            iVar3 = bStringHash();
            if (unaff_ESI != iVar3) {
              return unaff_ESI;
            }
          }
        }
      }
    }
  }
  puVar5 = &DAT_006c0c74;
  iVar3 = -1;
  uVar2 = 0x4e;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  return iVar3;
}


// ==== 0x50c930 IsNFSUBrand

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 IsNFSUBrand(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  int unaff_ESI;
  
  pcVar4 = "AUTOSTRADA";
  iVar3 = -1;
  uVar2 = 0x41;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  if (unaff_ESI != iVar3) {
    puVar5 = &DAT_006c0ca0;
    iVar3 = -1;
    uVar2 = 0x50;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = puVar5 + 1;
      uVar2 = (uint)*pbVar1;
      puVar5 = puVar5 + 1;
    } while (*pbVar1 != 0);
    if (unaff_ESI != iVar3) {
      pcVar4 = "SPARCO";
      iVar3 = -1;
      uVar2 = 0x53;
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar4 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar4 = pcVar4 + 1;
      } while (*pbVar1 != 0);
      if (unaff_ESI != iVar3) {
        iVar3 = bStringHash();
        if (unaff_ESI != iVar3) {
          iVar3 = bStringHash();
          if (unaff_ESI != iVar3) {
            iVar3 = bStringHash();
            if (unaff_ESI != iVar3) {
              iVar3 = bStringHash();
              if (unaff_ESI != iVar3) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 1;
}


// ==== 0x50c9e0 GarageRimsBrandBrowser::GarageRimsBrandBrowser

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageRimsBrandBrowser__GarageRimsBrandBrowser(undefined4 *param_1,int ******param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  int *****_Memory;
  char cVar4;
  int iVar5;
  int ******ppppppiVar6;
  int *****pppppiVar7;
  int ******ppppppiVar8;
  int *****pppppiVar9;
  int *piVar10;
  uint uVar11;
  char *pcVar12;
  undefined *puVar13;
  int ****ppppiVar14;
  int local_41c [255];
  undefined4 *local_20;
  int *****local_1c;
  int *****local_18;
  int *****local_14;
  void *local_10;
  code *local_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  local_c = FUN_00688e96;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GarageRimsBrandBrowser__scalar_deleting_destructor_006c01ec;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  local_20 = param_1 + 0x13;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(local_20,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int **)(iVar5 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar5 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar5 + 0x18));
  }
  GarageManager__PopAllScreensOfCertainName("MU_GarageRimsBrowser.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageRimsStyleBrowser.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageRimsBrandBrowser.fng");
  ppppppiVar8 = DAT_0073ad40;
  local_18 = (int *****)&local_18;
  local_14 = (int *****)&local_18;
  local_8 = CONCAT31(local_8._1_3_,3);
  ppppiVar14 = (int ****)0xffffffff;
  pcVar12 = "WHEEL_MANUFACTURERS";
  uVar11 = 0x57;
  do {
    pbVar1 = (byte *)(pcVar12 + 1);
    ppppiVar14 = (int ****)((int)ppppiVar14 * 0x21 + uVar11);
    pcVar12 = pcVar12 + 1;
    uVar11 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  param_2 = DAT_0073ad40;
  ppppppiVar6 = (int ******)NullUpdate_ret();
  local_1c = (int *****)ppppppiVar6;
  if (ppppppiVar8 != ppppppiVar6) {
    do {
      pppppiVar7 = param_2[3];
      pppppiVar9 = pppppiVar7 + (int)param_2[4] * 0xc;
      if ((ppppiVar14 != (int ****)0x0) &&
         (pppppiVar7 = (int *****)BinarySearch_Hash(ppppiVar14,pppppiVar7,4),
         ppppppiVar6 = (int ******)local_1c, pppppiVar7 == (int *****)0x0)) break;
      if (pppppiVar7 < pppppiVar9) {
        if ((ppppiVar14 == (int ****)0x0) || (pppppiVar7[1] == ppppiVar14)) goto LAB_0050cb36;
        break;
      }
      param_2 = (int ******)*param_2;
    } while (param_2 != ppppppiVar6);
  }
  pppppiVar7 = (int *****)0x0;
LAB_0050cb36:
  if (pppppiVar7 != (int *****)0x0) {
    ppppppiVar8 = (int ******)NullUpdate_ret();
    param_2 = (int ******)local_41c;
    local_1c = (int *****)ppppppiVar8;
    do {
      pppppiVar9 = (int *****)HackHackHack_GetRimsBrandHash();
      for (ppppppiVar6 = (int ******)local_18; ppppppiVar6 != ppppppiVar8;
          ppppppiVar6 = (int ******)*ppppppiVar6) {
        if (ppppppiVar6[2] == pppppiVar9) goto LAB_0050cc61;
      }
      ppppppiVar8 = _malloc(0x10);
      pppppiVar9 = (int *****)HackHackHack_GetRimsBrandHash();
      ppppppiVar8[2] = pppppiVar9;
      ppppppiVar8[3] = pppppiVar7;
      *local_14 = (int ****)ppppppiVar8;
      ppppppiVar8[1] = local_14;
      *ppppppiVar8 = (int *****)&local_18;
      ppppiVar14 = pppppiVar7[2];
      local_14 = (int *****)ppppppiVar8;
      cVar4 = IsNFSUBrand();
      if (cVar4 == '\0') {
        pcVar12 = "VISUAL_RIMS_BRAND_";
        iVar5 = -1;
        uVar11 = 0x56;
        do {
          iVar5 = iVar5 * 0x21 + uVar11;
          pbVar1 = (byte *)(pcVar12 + 1);
          uVar11 = (uint)*pbVar1;
          pcVar12 = pcVar12 + 1;
        } while (*pbVar1 != 0);
        ppppiVar14 = *pppppiVar7;
        bVar2 = *(byte *)ppppiVar14;
        while (bVar2 != 0) {
          iVar5 = iVar5 * 0x21 + (uint)bVar2;
          pbVar1 = (byte *)((int)ppppiVar14 + 1);
          ppppiVar14 = (int ****)((int)ppppiVar14 + 1);
          bVar2 = *pbVar1;
        }
        *param_2 = (int *****)iVar5;
      }
      else {
        piVar10 = &DAT_00744368;
        do {
          if ((((int ****)piVar10[-1] == ppppiVar14) || ((int ****)*piVar10 == ppppiVar14)) ||
             ((int ****)piVar10[1] == ppppiVar14)) break;
          piVar10 = piVar10 + 6;
        } while ((int)piVar10 < 0x7449c8);
        pcVar12 = "VISUAL_RIMS_BRAND_";
        iVar5 = -1;
        uVar11 = 0x56;
        do {
          iVar5 = iVar5 * 0x21 + uVar11;
          pbVar1 = (byte *)(pcVar12 + 1);
          uVar11 = (uint)*pbVar1;
          pcVar12 = pcVar12 + 1;
        } while (*pbVar1 != 0);
        puVar13 = &DAT_006c0c74;
        uVar11 = 0x4e;
        do {
          iVar5 = iVar5 * 0x21 + uVar11;
          pbVar1 = puVar13 + 1;
          uVar11 = (uint)*pbVar1;
          puVar13 = puVar13 + 1;
        } while (*pbVar1 != 0);
        *param_2 = (int *****)iVar5;
      }
      param_2 = param_2 + 1;
      ppppppiVar8 = (int ******)local_1c;
LAB_0050cc61:
      pcVar12 = "WHEEL_MANUFACTURERS";
      iVar5 = -1;
      uVar11 = 0x57;
      do {
        iVar5 = iVar5 * 0x21 + uVar11;
        pbVar1 = (byte *)(pcVar12 + 1);
        uVar11 = (uint)*pbVar1;
        pcVar12 = pcVar12 + 1;
      } while (*pbVar1 != 0);
      pppppiVar7 = (int *****)CarPartDatabase__GetCarPart(iVar5,0xffffffff,0,pppppiVar7,0xffffffff);
    } while (pppppiVar7 != (int *****)0x0);
  }
  if ((int ******)local_18 != &local_18) {
    do {
      _Memory = local_18;
      pppppiVar7 = (int *****)*local_18;
      pppppiVar9 = (int *****)local_18[1];
      *pppppiVar9 = (int ****)pppppiVar7;
      pppppiVar7[1] = (int ****)pppppiVar9;
      GarageRimsBrandBrowser__AddPickable("MU_GarageRimsStyleBrowser.fng",local_18[2]);
      _free(_Memory);
    } while ((int ******)local_18 != &local_18);
  }
  if (DAT_00735740 == 0) {
    param_1[0x10] = param_1[0x11];
  }
  else {
    for (puVar3 = (undefined4 *)param_1[0x11]; puVar3 != param_1 + 0x11;
        puVar3 = (undefined4 *)*puVar3) {
      if (puVar3[2] == DAT_00735740) {
        param_1[0x10] = puVar3;
        goto LAB_0050cd1e;
      }
    }
    param_1[0x10] = (undefined4 *)param_1[0x11];
  }
LAB_0050cd1e:
  FUN_004f8960();
  GarageRimsBrandBrowser__RedrawHeading();
  _DAT_00746de0 = 0x3f800000;
  *(undefined1 *)(param_1 + 8) = 1;
  if ((int ******)local_18 != &local_18) {
    do {
      pppppiVar7 = (int *****)*local_18;
      pppppiVar9 = (int *****)local_18[1];
      *pppppiVar9 = (int ****)pppppiVar7;
      pppppiVar7[1] = (int ****)pppppiVar9;
      _free(local_18);
    } while ((int ******)local_18 != &local_18);
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x50cd90 GarageRimsBrandBrowser::ScrollPickables

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageRimsBrandBrowser__ScrollPickables(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (unaff_EBX == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EDI + 0x44)) && (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EBX == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48))) &&
          (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    FUN_004f8910();
    GarageRimsBrandBrowser__RedrawHeading();
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x50ce30 GarageRimsBrandBrowser::AddPickable

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall GarageRimsBrandBrowser__AddPickable(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int unaff_EBX;
  char *pcVar7;
  
  piVar3 = _malloc(0x18);
  piVar3[4] = param_2;
  piVar3[2] = in_EAX;
  piVar3[3] = in_EAX;
  piVar3[5] = param_3;
  puVar2 = *(undefined4 **)(param_1 + 0x48);
  *puVar2 = piVar3;
  *(int **)(param_1 + 0x48) = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = param_1 + 0x44;
  iVar4 = FUN_004f8730(param_1 + 0x4c,piVar3[2],0,1);
  if (unaff_EBX == 0) {
    pcVar7 = "VISUAL_PART_RIMS";
    iVar6 = -1;
    uVar5 = 0x56;
    do {
      iVar6 = iVar6 * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != iVar6)) {
      *(int *)(iVar4 + 0x24) = iVar6;
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    }
  }
  else if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != unaff_EBX)) {
    *(int *)(iVar4 + 0x24) = unaff_EBX;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    return;
  }
  return;
}


// ==== 0x50ced0 GarageRimsBrandBrowser::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsBrandBrowser__MoveForwardPackage(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
  iVar1 = DAT_0073578c;
  DAT_00745e44 = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0xc);
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return uVar3;
}


// ==== 0x50cf30 GarageRimsBrandBrowser::MoveBackPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsBrandBrowser__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  DAT_00735740 = 0;
  DAT_00745e44 = 0;
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x50cf90 GarageRimsBrandBrowser::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageRimsBrandBrowser__RedrawHeading(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int unaff_ESI;
  
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar2 + 0x18));
  }
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  iVar2 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x40) + 0xc) + 8);
  pcVar4 = "_BRAND_NAME";
  uVar3 = 0x5f;
  do {
    iVar2 = iVar2 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  FUN_00495f00(iVar2);
  return;
}


// ==== 0x50d010 GarageRimsBrandBrowser::NotificationMessage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __thiscall GarageRimsBrandBrowser__NotificationMessage(int param_1,uint param_2)

{
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        DAT_0073573c = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x14);
        DAT_00735740 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
        GarageRimsBrandBrowser__MoveForwardPackage();
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageRimsBrandBrowser__MoveBackPackage(param_1);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004f89d0();
    FUN_004f7d30();
    return;
  }
  GarageRimsBrandBrowser__ScrollPickables();
  return;
}


// ==== 0x50d0a0 CreateGarageRimsBrandScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageRimsBrandScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006893f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageRimsBrandBrowser__GarageRimsBrandBrowser(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50d100 GarageScreen::NotifySoundMessage

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageScreen__NotifySoundMessage(void)

{
  undefined4 in_stack_00000014;
  
  switch(in_stack_00000014) {
  case 1:
  case 2:
  case 3:
  case 4:
    in_stack_00000014 = 0;
  }
  return in_stack_00000014;
}


// ==== 0x50d130 GarageRimsStyleBrowser::SendLevelMessage

/* [canon] car low (ghidra-canon) docs/re/canon_db.md */

void GarageRimsStyleBrowser__SendLevelMessage(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  cVar1 = *(char *)(in_EAX + 0x11);
  if (cVar1 == '\0') {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x2cbd3c8d,0,0,*(int *)(iVar2 + 0x18));
      return;
    }
  }
  else if (cVar1 == '\x01') {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x2cbd3c6b,0,0,*(int *)(iVar2 + 0x18));
      return;
    }
  }
  else {
    if (cVar1 == '\x02') {
      FUN_004c96c0(0x2cbd3c6c);
      return;
    }
    if (cVar1 == '\x03') {
      FUN_004c96c0(0x2cbd3c6d);
      return;
    }
    if (cVar1 == '\x04') {
      FUN_004c96c0(0x2cbd3c8f);
    }
  }
  return;
}


// ==== 0x50d1f0 GarageRimsStyleBrowser::IsPartLocked

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

uint GarageRimsStyleBrowser__IsPartLocked(void)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  
  if (DAT_007677ac != 0) {
    return DAT_007677ac & 0xffffff00;
  }
  uVar2 = 0;
  if (DAT_0073766c != 0) {
    puVar3 = (uint *)(DAT_00737668 + 0x24);
    do {
      if ((puVar3[-1] == 1) && (*puVar3 == (uint)*(byte *)(in_EAX + 0x11))) {
        cVar4 = *(char *)(uVar2 * 0x34 + 0x30 + DAT_00737668);
        goto LAB_0050d238;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0xd;
    } while (uVar2 < DAT_0073766c);
  }
  cVar4 = '\0';
LAB_0050d238:
  if (*(byte *)(in_EAX + 0x11) < 2) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,3);
  }
  if (((cVar4 == '\0') && (cVar1 == '\0')) && (DAT_00735ec1 == '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x50d2b0 GarageRimsStyleBrowser::_GarageRimsStyleBrowser

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageRimsStyleBrowser___GarageRimsStyleBrowser(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068731e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_GarageRimsStyleBrowser__scalar_deleting_destructor_006c01bc;
  local_4 = 2;
  GarageManager__PreviewPart();
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x50d340 GarageRimsStyleBrowser::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageRimsStyleBrowser__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageRimsStyleBrowser___GarageRimsStyleBrowser();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50d360 FindStockRimsPart

/* WARNING: Type propagation algorithm not settling */
/* [canon] car low (ghidra-canon) docs/re/canon_db.md */

uint FindStockRimsPart(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = FECarConfig__GetCarType();
  iVar5 = 0;
  if (iVar2 != 0x23) {
    if (iVar2 * 0xc90 + DAT_00734588 == 0) {
      return 0;
    }
    iVar5 = bStringHash();
  }
  puVar1 = DAT_0073ad40;
  puVar3 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar3) {
      return 0;
    }
    uVar4 = puVar1[3];
    uVar6 = puVar1[4] * 0x30 + uVar4;
    if ((iVar5 != 0) && (uVar4 = BinarySearch_Hash(iVar5,uVar4,4), uVar4 == 0)) break;
    for (; uVar4 < uVar6; uVar4 = uVar4 + 0x30) {
      if ((iVar5 != 0) && (*(int *)(uVar4 + 4) != iVar5)) {
        return 0;
      }
      if (*(char *)(uVar4 + 0x10) == '\x11') {
        return uVar4;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  }
  return 0;
}


// ==== 0x50d420 GarageRimsStyleBrowser::GarageRimsStyleBrowser

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageRimsStyleBrowser__GarageRimsStyleBrowser(undefined4 *param_1,int *param_2)

{
  byte *pbVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  char *pcVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  char *pcVar15;
  bool bVar16;
  char local_54 [32];
  undefined4 *local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  undefined4 *local_18;
  byte local_12;
  char local_11;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar14 = param_1 + 0x11;
  *param_1 = &PTR_GarageRimsStyleBrowser__scalar_deleting_destructor_006c01bc;
  *puVar14 = puVar14;
  param_1[0x12] = puVar14;
  local_34 = param_1 + 0x13;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(local_34,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar4 + 0x18));
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0xf7fbf050,0,0,*(int *)(iVar4 + 0x18));
  }
  *(undefined1 *)(param_1 + 0x22) = 0;
  local_2c = DAT_00745e44;
  iVar4 = FECarConfig__GetCarType();
  piVar11 = DAT_0073ad40;
  local_1c = (int)*(char *)(iVar4 * 0xc90 + 0xdc + DAT_00734588);
  pcVar10 = "WHEELS";
  uVar8 = 0x57;
  puVar14 = (undefined4 *)0xffffffff;
  do {
    puVar14 = (undefined4 *)((int)puVar14 * 0x21 + uVar8);
    pbVar1 = (byte *)(pcVar10 + 1);
    uVar8 = (uint)*pbVar1;
    pcVar10 = pcVar10 + 1;
  } while (*pbVar1 != 0);
  param_2 = DAT_0073ad40;
  local_18 = puVar14;
  local_30 = (int *)NullUpdate_ret();
  if (piVar11 != local_30) {
    do {
      puVar5 = (undefined4 *)param_2[3];
      puVar13 = puVar5 + param_2[4] * 0xc;
      if ((puVar14 != (undefined4 *)0x0) &&
         (puVar5 = (undefined4 *)BinarySearch_Hash(local_18,puVar5,4), puVar5 == (undefined4 *)0x0))
      break;
      if (puVar5 < puVar13) {
        iVar4 = DAT_00745e40;
        if ((local_18 == (undefined4 *)0x0) || ((undefined4 *)puVar5[1] == local_18))
        goto joined_r0x0050d5bb;
        break;
      }
      param_2 = (int *)*param_2;
      puVar14 = local_18;
    } while (param_2 != local_30);
  }
LAB_0050db00:
  if (DAT_00735744 == 0) {
    param_1[0x10] = param_1[0x11];
  }
  else {
    for (puVar14 = (undefined4 *)param_1[0x11]; puVar14 != param_1 + 0x11;
        puVar14 = (undefined4 *)*puVar14) {
      if (puVar14[2] == DAT_00735744) {
        param_1[0x10] = puVar14;
        goto LAB_0050db32;
      }
    }
    param_1[0x10] = (undefined4 *)param_1[0x11];
  }
LAB_0050db32:
  iVar4 = param_1[0x10];
  FUN_004f8960();
  GarageRimsStyleBrowser__SendLevelMessage();
  uVar9 = *(undefined4 *)(iVar4 + 0x34);
  cVar3 = GarageRimsStyleBrowser__IsPartLocked(param_1);
  if (cVar3 != '\0') {
    uVar9 = FindStockRimsPart();
  }
  _DAT_0074571c = uVar9;
  DAT_0074563d = DAT_0074563d + '\x01';
  _DAT_00745490 = _DAT_0074571c;
  RideInfo__UpdatePartsEnabled(&DAT_00745000);
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x18) == 0)) {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 == 0) ||
       (((*(int *)(iVar4 + 0x18) == 0 ||
         (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 == 0)) ||
        (*(int *)(iVar4 + 0x14) == 0)))) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(iVar4 + 0x14) + 0x40);
    }
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x14);
    }
  }
  RideInfo__operator_(&DAT_00748850,&DAT_00745000);
  _DAT_0072cc80 = 2;
  if (iVar4 != 0) {
    GarageMainScreen__SetRideInfo(iVar4,&DAT_00748850,2);
  }
  GarageRimsStyleBrowser__RedrawHeading(param_1);
  *(undefined1 *)(param_1 + 8) = 1;
  ExceptionList = local_10;
  return param_1;
joined_r0x0050d5bb:
  local_18 = puVar5;
  DAT_00745e40 = iVar4;
  if (local_18 != (undefined4 *)0x0) {
    local_12 = *(byte *)((int)local_18 + 0x11);
    local_20 = (uint)local_12;
    if (local_20 == 4) {
      local_24 = local_1c + -6;
    }
    else {
      local_24 = (local_20 - 9) + local_1c;
    }
    piVar6 = *(int **)(DAT_00745bb0 + 0x14);
    piVar11 = piVar6 + *(short *)(DAT_00745bb0 + 0x1c) * 2;
    if (piVar6 != (int *)0x0) {
      for (; piVar6 < piVar11; piVar6 = piVar6 + 2) {
        if (*piVar6 == -0x14fefe1e) {
          if (piVar6 != (int *)0x0) {
            cVar3 = (char)piVar6[1];
            goto LAB_0050d615;
          }
          break;
        }
      }
    }
    cVar3 = '\0';
LAB_0050d615:
    local_30 = (int *)(int)cVar3;
    if ((iVar4 != 2) || (bVar2 = true, 1 < local_12)) {
      bVar2 = false;
    }
    local_11 = PartStore__HasPart(&DAT_0075f344);
    uVar8 = local_20;
    if ((((DAT_006f88a8 == '\0') || (bVar2)) || (iVar4 == 1)) || (bVar2 = false, local_11 != '\0'))
    {
      bVar2 = true;
    }
    if ((local_20 == 4) && (local_11 == '\0')) {
      bVar2 = false;
    }
    if (DAT_00735ec1 != '\0') {
      bVar2 = true;
    }
    if (iVar4 == 1) {
      uVar7 = UnlockTeller__GetNewlyUnlockedPartLevel();
      local_28 = CONCAT31(local_28._1_3_,1);
      if (uVar7 != uVar8) goto LAB_0050d6a0;
    }
    else {
LAB_0050d6a0:
      local_28 = local_28 & 0xffffff00;
    }
    if ((DAT_007677ac != 0) && (((int)uVar8 < 4 || ((uVar8 == 4 && (local_11 != '\0')))))) {
      bVar2 = true;
    }
    if (iVar4 == 2) {
      uVar8 = 0;
      if (DAT_0073766c != 0) {
        piVar11 = (int *)(DAT_00737668 + 0x24);
        do {
          if ((piVar11[-1] == 1) && (*piVar11 == 2)) {
            if ((*(char *)(uVar8 * 0x34 + 0x30 + DAT_00737668) != '\0') && (local_12 == 1))
            goto LAB_0050d81f;
            break;
          }
          uVar8 = uVar8 + 1;
          piVar11 = piVar11 + 0xd;
        } while (uVar8 < DAT_0073766c);
      }
      uVar8 = 0;
      if (DAT_0073766c != 0) {
        puVar12 = (uint *)(DAT_00737668 + 0x24);
        do {
          if ((puVar12[-1] == 1) && (*puVar12 == local_20)) {
            if (*(char *)(uVar8 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_0050d81f;
            break;
          }
          uVar8 = uVar8 + 1;
          puVar12 = puVar12 + 0xd;
        } while (uVar8 < DAT_0073766c);
      }
    }
    bVar16 = false;
    goto LAB_0050d73e;
  }
  goto LAB_0050db00;
LAB_0050d81f:
  bVar16 = true;
LAB_0050d73e:
  if ((bVar2) || (bVar2 = false, bVar16)) {
    bVar2 = true;
  }
  iVar4 = local_18[3];
  cVar3 = IsNFSUBrand();
  if ((cVar3 == '\0') || (cVar3 = IsNFSUBrand(), cVar3 == '\0')) {
    puVar14 = local_18;
    if (iVar4 != *(int *)(local_2c + 8)) goto LAB_0050dac1;
    iVar4 = (int)*(short *)(local_18 + 7);
    piVar11 = (int *)local_18[5];
    piVar6 = piVar11;
    if (piVar11 != (int *)0x0) {
      for (; piVar6 < piVar11 + iVar4 * 2; piVar6 = piVar6 + 2) {
        if (*piVar6 == 0x10c98090) {
          if (piVar6 != (int *)0x0) {
            local_20 = piVar6[1];
            goto LAB_0050d946;
          }
          break;
        }
      }
    }
    local_20 = 0;
LAB_0050d946:
    if (DAT_006f88a8 == '\0') {
      piVar6 = piVar11;
      if (piVar11 != (int *)0x0) {
        for (; piVar6 < piVar11 + iVar4 * 2; piVar6 = piVar6 + 2) {
          if (*piVar6 == -0x14fefe1e) {
            if (piVar6 != (int *)0x0) {
              cVar3 = (char)piVar6[1];
              goto LAB_0050d9e4;
            }
            break;
          }
        }
      }
      cVar3 = '\0';
LAB_0050d9e4:
      if (local_30 == (int *)(int)cVar3) {
        piVar6 = piVar11 + iVar4 * 2;
        if (piVar11 != (int *)0x0) {
          for (; piVar11 < piVar6; piVar11 = piVar11 + 2) {
            if (*piVar11 == -0x3182724b) {
              if (piVar11 != (int *)0x0) {
                cVar3 = (char)piVar11[1];
                goto LAB_0050da11;
              }
              break;
            }
          }
        }
        cVar3 = '\0';
LAB_0050da11:
        bVar16 = local_1c == cVar3;
        goto LAB_0050da17;
      }
LAB_0050da2f:
      bVar16 = false;
    }
    else {
      piVar6 = piVar11;
      if (piVar11 != (int *)0x0) {
        for (; piVar6 < piVar11 + iVar4 * 2; piVar6 = piVar6 + 2) {
          if (*piVar6 == -0x14fefe1e) {
            if (piVar6 != (int *)0x0) {
              cVar3 = (char)piVar6[1];
              goto LAB_0050d971;
            }
            break;
          }
        }
      }
      cVar3 = '\0';
LAB_0050d971:
      if (local_24 != cVar3) goto LAB_0050da2f;
      piVar6 = piVar11 + iVar4 * 2;
      if (piVar11 != (int *)0x0) {
        for (; piVar11 < piVar6; piVar11 = piVar11 + 2) {
          if (*piVar11 == -0x3182724b) {
            if (piVar11 != (int *)0x0) {
              bVar16 = local_1c == (char)piVar11[1];
              goto LAB_0050da17;
            }
            break;
          }
        }
      }
      bVar16 = local_1c == 0;
LAB_0050da17:
      if (!bVar16) goto LAB_0050da2f;
      bVar16 = true;
    }
    for (puVar5 = (undefined4 *)param_1[0x11]; puVar5 != param_1 + 0x11;
        puVar5 = (undefined4 *)*puVar5) {
      if (puVar5[2] == local_20) goto LAB_0050dac1;
    }
    if ((!bVar16) || (!bVar2)) goto LAB_0050dac1;
    pcVar10 = (char *)*local_18;
    uVar8 = 0;
    pcVar15 = local_54;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar15[0] = '\0';
      pcVar15[1] = '\0';
      pcVar15[2] = '\0';
      pcVar15[3] = '\0';
      pcVar15 = pcVar15 + 4;
    }
    if (pcVar10 != (char *)0x0) {
      cVar3 = *pcVar10;
      while (cVar3 != '\0') {
        iVar4 = uVar8 + 1;
        uVar8 = uVar8 + 1;
        cVar3 = pcVar10[iVar4];
      }
    }
    uVar7 = 0xffffffff;
    do {
      uVar8 = uVar8 - 1;
      if ((int)uVar8 < 0) break;
      if (pcVar10[uVar8] == ' ') {
        uVar7 = uVar8;
      }
    } while ((int)uVar7 < 0);
    if (0 < (int)uVar7) {
      pcVar15 = local_54;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar15 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar15 = pcVar15 + 1;
      }
    }
  }
  else {
    iVar4 = (int)*(short *)(local_18 + 7);
    piVar11 = (int *)local_18[5];
    piVar6 = piVar11;
    if (piVar11 != (int *)0x0) {
      for (; piVar6 < piVar11 + iVar4 * 2; piVar6 = piVar6 + 2) {
        if (*piVar6 == 0x10c98090) {
          if (piVar6 != (int *)0x0) {
            local_20 = piVar6[1];
            goto LAB_0050d7ad;
          }
          break;
        }
      }
    }
    local_20 = 0;
LAB_0050d7ad:
    if (DAT_006f88a8 == '\0') {
      piVar6 = piVar11;
      if (piVar11 != (int *)0x0) {
        for (; piVar6 < piVar11 + iVar4 * 2; piVar6 = piVar6 + 2) {
          if (*piVar6 == -0x14fefe1e) {
            if (piVar6 != (int *)0x0) {
              cVar3 = (char)piVar6[1];
              goto LAB_0050d871;
            }
            break;
          }
        }
      }
      cVar3 = '\0';
LAB_0050d871:
      if (local_30 == (int *)(int)cVar3) {
        piVar6 = piVar11 + iVar4 * 2;
        if (piVar11 != (int *)0x0) {
          for (; piVar11 < piVar6; piVar11 = piVar11 + 2) {
            if (*piVar11 == -0x3182724b) {
              if (piVar11 != (int *)0x0) {
                cVar3 = (char)piVar11[1];
                goto LAB_0050d895;
              }
              break;
            }
          }
        }
        cVar3 = '\0';
LAB_0050d895:
        bVar16 = local_1c == cVar3;
        goto LAB_0050d89b;
      }
LAB_0050d8b3:
      bVar16 = false;
    }
    else {
      piVar6 = piVar11;
      if (piVar11 != (int *)0x0) {
        for (; piVar6 < piVar11 + iVar4 * 2; piVar6 = piVar6 + 2) {
          if (*piVar6 == -0x14fefe1e) {
            if (piVar6 != (int *)0x0) {
              cVar3 = (char)piVar6[1];
              goto LAB_0050d7d9;
            }
            break;
          }
        }
      }
      cVar3 = '\0';
LAB_0050d7d9:
      if (local_24 != cVar3) goto LAB_0050d8b3;
      piVar6 = piVar11 + iVar4 * 2;
      if (piVar11 != (int *)0x0) {
        for (; piVar11 < piVar6; piVar11 = piVar11 + 2) {
          if (*piVar11 == -0x3182724b) {
            if (piVar11 != (int *)0x0) {
              bVar16 = local_1c == (char)piVar11[1];
              goto LAB_0050d89b;
            }
            break;
          }
        }
      }
      bVar16 = local_1c == 0;
LAB_0050d89b:
      if (!bVar16) goto LAB_0050d8b3;
      bVar16 = true;
    }
    for (puVar14 = (undefined4 *)param_1[0x11]; puVar14 != param_1 + 0x11;
        puVar14 = (undefined4 *)*puVar14) {
      if (puVar14[2] == local_20) goto LAB_0050dac1;
    }
    if ((!bVar16) || (puVar14 = local_18, !bVar2)) goto LAB_0050dac1;
  }
  GarageRimsStyleBrowser__AddPickable(puVar14,"MU_GarageRimsBrowser.fng",local_20,local_28);
LAB_0050dac1:
  pcVar10 = "WHEELS";
  iVar4 = -1;
  uVar8 = 0x57;
  do {
    iVar4 = iVar4 * 0x21 + uVar8;
    pbVar1 = (byte *)(pcVar10 + 1);
    uVar8 = (uint)*pbVar1;
    pcVar10 = pcVar10 + 1;
  } while (*pbVar1 != 0);
  puVar5 = (undefined4 *)CarPartDatabase__GetCarPart(iVar4,0xffffffff,0,local_18,0xffffffff);
  iVar4 = DAT_00745e40;
  goto joined_r0x0050d5bb;
}


// ==== 0x50dc60 GarageRimsStyleBrowser::ScrollPickables

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageRimsStyleBrowser__ScrollPickables(int param_1)

{
  int iVar1;
  char cVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (param_1 == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EDI + 0x44)) && (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((param_1 == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48))) &&
          (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    GarageRimsStyleBrowser__SendLevelMessage();
    cVar2 = GarageRimsStyleBrowser__IsPartLocked(unaff_EDI);
    if (cVar2 != '\0') {
      FindStockRimsPart();
    }
    GarageManager__PreviewPart();
    FUN_004f8910();
    GarageRimsStyleBrowser__RedrawHeading(unaff_EDI);
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x50dd40 GarageRimsStyleBrowser::AddPickable

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall
GarageRimsStyleBrowser__AddPickable
          (int param_1,int param_2,int param_3,int param_4,int param_5,undefined1 param_6)

{
  byte *pbVar1;
  char cVar2;
  undefined4 *puVar3;
  char *in_EAX;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  
  piVar4 = _malloc(0x3c);
  piVar4[4] = param_4;
  piVar4[2] = param_1;
  piVar4[3] = param_1;
  piVar4[0xd] = param_3;
  *(undefined1 *)(piVar4 + 0xe) = param_6;
  if (in_EAX == (char *)0x0) {
    piVar10 = piVar4 + 5;
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    }
  }
  else {
    cVar2 = *in_EAX;
    piVar10 = piVar4 + 5;
    *(char *)piVar10 = cVar2;
    if (cVar2 != '\0') {
      piVar5 = piVar10;
      do {
        cVar2 = (in_EAX + (1 - (int)piVar10))[(int)piVar5];
        piVar5 = (int *)((int)piVar5 + 1);
        *(char *)piVar5 = cVar2;
      } while (cVar2 != '\0');
    }
  }
  puVar3 = *(undefined4 **)(param_2 + 0x48);
  *puVar3 = piVar4;
  *(int **)(param_2 + 0x48) = piVar4;
  piVar4[1] = (int)puVar3;
  *piVar4 = param_2 + 0x44;
  iVar6 = FUN_004f8730(param_2 + 0x4c,piVar4[2],0,1);
  if (param_5 == 0) {
    pcVar9 = "VISUAL_PART_RIMS";
    iVar8 = -1;
    uVar7 = 0x56;
    do {
      iVar8 = iVar8 * 0x21 + uVar7;
      pbVar1 = (byte *)(pcVar9 + 1);
      uVar7 = (uint)*pbVar1;
      pcVar9 = pcVar9 + 1;
    } while (*pbVar1 != 0);
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) != iVar8)) {
      *(int *)(iVar6 + 0x24) = iVar8;
      *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
    }
  }
  else if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) != param_5)) {
    *(int *)(iVar6 + 0x24) = param_5;
    *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
    return;
  }
  return;
}


// ==== 0x50de20 GarageRimsStyleBrowser::MoveForwardPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsStyleBrowser__MoveForwardPackage(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PushScreen(*(undefined4 *)(in_EAX + 0xc));
  iVar1 = DAT_0073578c;
  DAT_00745e48 = *(undefined4 *)(*(int *)(in_EAX + 0x40) + 0xc);
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return uVar3;
}


// ==== 0x50de80 GarageRimsStyleBrowser::MoveBackPackage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsStyleBrowser__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  DAT_00745e48 = 0xffffffff;
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x50dee0 GetRimSizeHash

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 GetRimSizeHash(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  
  switch(in_EAX) {
  case 0xf:
    uVar1 = bStringHash();
    return uVar1;
  case 0x10:
    uVar1 = bStringHash();
    return uVar1;
  case 0x11:
    uVar1 = bStringHash();
    return uVar1;
  case 0x12:
    uVar1 = bStringHash();
    return uVar1;
  case 0x13:
    uVar1 = bStringHash();
    return uVar1;
  case 0x14:
    uVar1 = bStringHash();
    return uVar1;
  case 0x15:
    uVar1 = bStringHash();
    return uVar1;
  default:
    return 0;
  }
}


// ==== 0x50df60 GarageRimsStyleBrowser::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageRimsStyleBrowser__RedrawHeading(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  bool bVar10;
  undefined4 local_30 [8];
  int local_10;
  int local_c;
  char local_5;
  
  iVar4 = *(int *)(param_1 + 0x40);
  local_5 = DAT_007677ac != 0;
  local_c = iVar4;
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  local_10 = LanguageStrings__FindByHash();
  if (local_10 == 0) {
    local_10 = LanguageStrings__FindByHash();
  }
  puVar5 = local_30;
  for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar4 = *(int *)(iVar4 + 0x34);
  cVar2 = IsNFSUBrand();
  if (cVar2 == '\0') {
    piVar3 = *(int **)(iVar4 + 0x14);
    piVar1 = piVar3 + *(short *)(iVar4 + 0x1c) * 2;
    if (piVar3 != (int *)0x0) {
      for (; piVar3 < piVar1; piVar3 = piVar3 + 2) {
        if (*piVar3 == 0x10c98090) {
          if (piVar3 != (int *)0x0) {
            iVar4 = piVar3[1];
            goto LAB_0050e015;
          }
          break;
        }
      }
    }
    iVar4 = 0;
LAB_0050e015:
    piVar3 = *(int **)(DAT_00745bb0 + 0x14);
    piVar1 = piVar3 + *(short *)(DAT_00745bb0 + 0x1c) * 2;
    if (piVar3 != (int *)0x0) {
      for (; piVar3 < piVar1; piVar3 = piVar3 + 2) {
        if (*piVar3 == 0x10c98090) {
          if (piVar3 != (int *)0x0) {
            iVar8 = piVar3[1];
            goto LAB_0050e041;
          }
          break;
        }
      }
    }
    iVar8 = 0;
LAB_0050e041:
    bVar10 = iVar4 == iVar8;
  }
  else {
    bVar10 = *(int *)(iVar4 + 8) == *(int *)(DAT_00745bb0 + 8);
  }
  if (bVar10) {
    FUN_00565da0(" (%s)",local_10);
  }
  pcVar6 = (char *)(local_c + 0x14);
  iVar4 = 0;
  if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
LAB_0050e0a2:
    puVar9 = &DAT_006c0bc4;
    do {
      pcVar6 = puVar9 + 1;
      puVar9 = puVar9 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = (char *)LanguageStrings__FindByHash();
    if (pcVar6 == (char *)0x0) {
      pcVar6 = (char *)LanguageStrings__FindByHash();
    }
    puVar5 = local_30;
    if (!bVar10) {
      puVar5 = (undefined4 *)&DAT_006b9172;
    }
  }
  else {
    do {
      iVar8 = iVar4 + 1;
      iVar4 = iVar4 + 1;
    } while (pcVar6[iVar8] != '\0');
    if (iVar4 < 1) goto LAB_0050e0a2;
    puVar5 = local_30;
    if (!bVar10) {
      puVar5 = (undefined4 *)&DAT_006b9172;
    }
  }
  FEngPrintf(&DAT_006cc578,pcVar6,puVar5);
  if (DAT_006f88a8 == '\0') {
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x7c5a7469);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FEngFindPackage(), iVar4 != 0)) &&
       (iVar4 = FUN_004ffb70(), iVar4 != 0)) goto LAB_0050e329;
    if (DAT_0073578c != 0) {
      uVar7 = FUN_004ef050(0xc53843de);
      FEObject__SetInvisible(uVar7);
      return;
    }
  }
  else {
    cVar2 = GarageRimsStyleBrowser__IsPartLocked(param_1);
    if (cVar2 == '\0') {
      FUN_00495f70();
    }
    else {
      FUN_00495fc0();
    }
    piVar3 = *(int **)(*(int *)(local_c + 0x34) + 0x14);
    piVar1 = piVar3 + *(short *)(*(int *)(local_c + 0x34) + 0x1c) * 2;
    if (piVar3 != (int *)0x0) {
      for (; (piVar3 < piVar1 && (*piVar3 != -0x14fefe1e)); piVar3 = piVar3 + 2) {
      }
    }
    iVar4 = GetRimSizeHash();
    if (iVar4 == 0) {
      FUN_00495f70();
    }
    else {
      FUN_00495fc0();
      FUN_004ad7b0(iVar4);
    }
    uVar7 = GarageManager__GetMsgForUpgradeLevel(&DAT_00744ff0);
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int *)(iVar4 + 0x14) != 0)) {
      FUN_004f7c00(uVar7,0,0,*(int *)(iVar4 + 0x18));
    }
    if (((local_5 == '\0') && (DAT_00745e40 != 2)) &&
       (cVar2 = PartStore__HasPart(&DAT_0075f344), cVar2 == '\0')) {
      FUN_00495fc0();
      uVar7 = GetCarPartCost();
      FEngPrintf(&DAT_006ca778,uVar7);
      return;
    }
    if (((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FEngFindPackage(), iVar4 != 0)) &&
       (iVar4 = FUN_004ffb70(), iVar4 != 0)) goto LAB_0050e329;
    if (DAT_0073578c != 0) {
      uVar7 = FUN_004ef050(0x7c5a7469);
      FEObject__SetInvisible(uVar7);
      return;
    }
  }
  iVar4 = 0;
LAB_0050e329:
  FEObject__SetInvisible(iVar4);
  return;
}


// ==== 0x50e340 GarageRimsStyleBrowser::NotificationMessage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __thiscall GarageRimsStyleBrowser__NotificationMessage(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  iStack_8 = param_1;
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 != 0xc407210) {
        if (param_2 == 0x2f6484d0) {
          GarageManager__InstallPart(*(undefined4 *)(*(int *)(param_1 + 0x40) + 0x34),0);
          if (DAT_00745e40 == 1) {
            FUN_005a2620();
          }
          iVar4 = GarageRimsBrandBrowser___GarageRimsBrandBrowser();
          iVar1 = iStack_8;
          if (iVar4 != -1) {
            *(uint *)(&DAT_00760158 + iVar4 * 4) = *(uint *)(&DAT_00760158 + iVar4 * 4) | 3;
          }
          GarageRimsStyleBrowser__RedrawHeading(iStack_8);
          *(undefined1 *)(iVar1 + 0x88) = 1;
          return;
        }
        if (param_2 != 0x911ab364) {
          return;
        }
        GarageRimsStyleBrowser__MoveBackPackage(param_1);
        return;
      }
      iVar1 = *(int *)(param_1 + 0x40);
      if (DAT_006f88a8 == '\0') {
        cVar2 = GarageRimsStyleBrowser__IsPartLocked(param_1);
        if (cVar2 == '\0') {
          DAT_00735744 = *(undefined4 *)(iVar1 + 8);
          GarageRimsStyleBrowser__MoveForwardPackage();
          return;
        }
      }
      else {
        cVar2 = GarageRimsStyleBrowser__IsPartLocked(param_1);
        if (cVar2 == '\0') {
          cVar2 = GarageRimsStyleBrowser__IsInstallingPart();
          cVar3 = GarageRimsStyleBrowser__IsBuyingPart();
          if (cVar2 != '\0') {
            uStack_10 = 0;
            uStack_c = 0;
            uStack_1c = 0;
            uStack_18 = 0;
            uStack_2c = 0x76d94941;
            uStack_24 = 0xf0aadebb;
            uStack_28 = 0x639;
            uStack_20 = 0x541389e5;
            uStack_14 = 0xb8a7c6cc;
            FUN_004dc6e0(&uStack_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if (cVar3 == '\0') {
            return;
          }
          uStack_10 = 0;
          uStack_c = 0;
          uStack_1c = 0;
          uStack_18 = 0;
          uStack_2c = 0x39223856;
          uStack_24 = 0x2f6484d0;
          uStack_28 = 0x639;
          uStack_20 = 0x541389e5;
          uStack_14 = 0xb8a7c6cc;
          FUN_004dc6e0(&uStack_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
      }
      if (DAT_006f1dd8 == 0) {
        return;
      }
      if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
        return;
      }
      (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 == 0xc98356ba) {
      FUN_004f89d0();
      FUN_004f7d30();
      if (*(char *)(param_1 + 0x88) == '\0') {
        return;
      }
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0xf0aadebb) {
      return;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x40) + 0x34);
    if (*(char *)(iVar1 + 0x10) == '\x05') {
      GarageManager__InstallPart(iVar1,0);
    }
    GarageManager__InstallPart(iVar1,0);
    *(undefined1 *)(iStack_8 + 0x88) = 1;
    return;
  }
  GarageRimsStyleBrowser__ScrollPickables(param_2);
  return;
}


// ==== 0x50e5c0 GarageRimsStyleBrowser::CanPlayerPurchasePart

/* [canon] car low (ghidra-canon) docs/re/canon_db.md */

bool GarageRimsStyleBrowser__CanPlayerPurchasePart(void)

{
  bool bVar1;
  undefined8 uVar2;
  
  bVar1 = true;
  if ((DAT_00745e40 == 1) && (DAT_0073440c == '\0')) {
    Career__GetCash(&DAT_0075eef8);
    uVar2 = GetCarPartCost();
    bVar1 = (int)uVar2 <= (int)((ulonglong)uVar2 >> 0x20);
  }
  return bVar1;
}


// ==== 0x50e600 GarageRimsStyleBrowser::IsInstallingPart

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

uint GarageRimsStyleBrowser__IsInstallingPart(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00745e40 == 1) {
    cVar1 = *(char *)(unaff_ESI + 0x10);
    iVar3 = 0;
    if (cVar1 == '\x06') goto LAB_0050e640;
    uVar2 = PartStore__HasPart(&DAT_0075f344);
    if ((char)uVar2 == '\0') goto LAB_0050e671;
  }
  else {
    uVar2 = DAT_00745e40;
    if (DAT_00745e40 != 2) goto LAB_0050e671;
    cVar1 = *(char *)(unaff_ESI + 0x10);
  }
  iVar3 = (int)cVar1;
  if ((&DAT_00745b6c)[iVar3] == unaff_ESI) {
    local_c = 0;
    local_14 = 0x368294c0;
    local_10 = 0x639;
    uVar2 = FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(unaff_EDI + 0xc));
LAB_0050e671:
    return uVar2 & 0xffffff00;
  }
LAB_0050e640:
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


// ==== 0x50e680 GarageRimsStyleBrowser::IsBuyingPart

/* [canon] car med (ghidra-canon) docs/re/canon_db.md */

undefined4 GarageRimsStyleBrowser__IsBuyingPart(void)

{
  char cVar1;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00745e40 == 1) {
    cVar1 = PartStore__HasPart(&DAT_0075f344);
    if (cVar1 == '\0') {
      cVar1 = GarageRimsStyleBrowser__CanPlayerPurchasePart(unaff_EDI,unaff_ESI);
      if (cVar1 != '\0') {
        return 1;
      }
      local_10 = 0x639;
      local_14 = 0x2c0344a3;
      local_c = 0;
      FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(unaff_EDI + 0xc));
    }
  }
  return 0;
}


// ==== 0x50e6f0 CreateGarageRimsStyleScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageRimsStyleScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689573;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageRimsStyleBrowser__GarageRimsStyleBrowser(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50e750 GarageRimsBrowser::_GarageRimsBrowser

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageRimsBrowser___GarageRimsBrowser(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageRimsBrowser__scalar_deleting_destructor_006c015c;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x50e7a0 GarageRimsBrowser::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageRimsBrowser__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageRimsBrowser___GarageRimsBrowser();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50e7c0 GarageRimsBrowser::GarageRimsBrowser

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageRimsBrowser__GarageRimsBrowser(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688f1e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x11;
  *param_1 = &PTR_GarageRimsBrowser__scalar_deleting_destructor_006c015c;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_4 = CONCAT31(local_4._1_3_,2);
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar2 + 0x18));
  }
  param_1[0x22] = 1;
  *(undefined1 *)(param_1 + 0x23) = 0;
  param_1[0x24] = 0;
  GarageRimsBrowser__BuildPickablesList(param_1);
  *(undefined1 *)(param_1 + 8) = 1;
  GarageRimsBrowser__RedrawHeading(param_1);
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x50e890 GarageRimsBrowser::BuildPickablesList

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageRimsBrowser__BuildPickablesList(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  int *piVar16;
  int local_218 [64];
  int local_118 [64];
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  byte local_5;
  
  local_18 = DAT_00745e48;
  iVar6 = FECarConfig__GetCarType();
  piVar16 = DAT_0073ad40;
  local_14 = iVar6 * 0xc90 + DAT_00734588;
  pcVar10 = "WHEELS";
  iVar6 = -1;
  uVar11 = 0x57;
  do {
    pbVar15 = (byte *)(pcVar10 + 1);
    iVar6 = iVar6 * 0x21 + uVar11;
    pcVar10 = pcVar10 + 1;
    uVar11 = (uint)*pbVar15;
  } while (*pbVar15 != 0);
  local_c = DAT_0073ad40;
  piVar7 = (int *)NullUpdate_ret();
  local_10 = piVar7;
  if (piVar16 != piVar7) {
    do {
      puVar8 = (undefined4 *)piVar16[3];
      puVar14 = puVar8 + piVar16[4] * 0xc;
      if ((iVar6 != 0) &&
         (puVar8 = (undefined4 *)BinarySearch_Hash(iVar6,puVar8,4), piVar7 = local_10,
         piVar16 = local_c, puVar8 == (undefined4 *)0x0)) break;
      if (puVar8 < puVar14) {
        local_c = puVar8;
        if ((iVar6 == 0) || (puVar8[1] == iVar6)) goto LAB_0050e93a;
        break;
      }
      piVar16 = (int *)*piVar16;
      local_c = piVar16;
    } while (piVar16 != piVar7);
  }
  local_c = (undefined4 *)0x0;
LAB_0050e93a:
  piVar16 = local_118;
  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar16 = 0;
    piVar16 = piVar16 + 1;
  }
  piVar16 = local_218;
  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar16 = 0;
    piVar16 = piVar16 + 1;
  }
  local_5 = 0;
  iVar6 = DAT_0073573c;
  do {
    DAT_0073573c = iVar6;
    if (local_c == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x44);
      FUN_004f8960();
      GarageRimsBrowser__RedrawHeading(param_1);
      GarageManager__PreviewPart();
      return;
    }
    iVar13 = (int)*(short *)(local_c + 7);
    piVar16 = (int *)local_c[5];
    piVar7 = piVar16;
    if (piVar16 != (int *)0x0) {
      for (; piVar7 < piVar16 + iVar13 * 2; piVar7 = piVar7 + 2) {
        if (*piVar7 == 0x10c98090) {
          if (piVar7 != (int *)0x0) {
            iVar9 = piVar7[1];
            goto LAB_0050e995;
          }
          break;
        }
      }
    }
    iVar9 = 0;
LAB_0050e995:
    if (iVar9 == local_18) {
      cVar5 = IsNFSUBrand();
      if (cVar5 == '\0') {
        if (local_c[3] == iVar6) {
          if (*(int *)(param_1 + 0x88) == 0) {
            piVar7 = piVar16;
            if (piVar16 != (int *)0x0) {
              for (; piVar7 < piVar16 + iVar13 * 2; piVar7 = piVar7 + 2) {
                if (*piVar7 == -0x3182724b) {
                  if (piVar7 != (int *)0x0) {
                    cVar5 = (char)piVar7[1];
                    goto LAB_0050eb55;
                  }
                  break;
                }
              }
            }
            cVar5 = '\0';
LAB_0050eb55:
            if (cVar5 != *(char *)(local_14 + 0xdc)) goto LAB_0050ec81;
          }
          piVar7 = piVar16;
          if (piVar16 != (int *)0x0) {
            for (; (piVar7 < piVar16 + iVar13 * 2 && (*piVar7 != -0x14fefe1e)); piVar7 = piVar7 + 2)
            {
            }
          }
          piVar7 = piVar16;
          if (piVar16 != (int *)0x0) {
            for (; (piVar7 < piVar16 + iVar13 * 2 && (*piVar7 != -0x3182724b)); piVar7 = piVar7 + 2)
            {
            }
          }
          piVar7 = piVar16 + iVar13 * 2;
          if (piVar16 != (int *)0x0) {
            for (; piVar16 < piVar7; piVar16 = piVar16 + 2) {
              if (*piVar16 == 0x10c98090) {
                if (piVar16 != (int *)0x0) {
                  local_10 = (int *)piVar16[1];
                  goto LAB_0050ebca;
                }
                break;
              }
            }
          }
          local_10 = (int *)0x0;
LAB_0050ebca:
          pbVar15 = (byte *)*local_c;
          iVar6 = -1;
          bVar2 = *pbVar15;
          pbVar12 = pbVar15;
          while (bVar2 != 0) {
            pbVar1 = pbVar12 + 1;
            iVar6 = iVar6 * 0x21 + (uint)bVar2;
            pbVar12 = pbVar12 + 1;
            bVar2 = *pbVar1;
          }
          uVar11 = (uint)local_5;
          iVar13 = 0;
          if (uVar11 != 0) {
            do {
              if (local_118[iVar13] == iVar6) {
                bVar3 = true;
                goto LAB_0050ec14;
              }
              iVar13 = iVar13 + 1;
            } while (iVar13 < (int)uVar11);
          }
          bVar3 = false;
LAB_0050ec14:
          iVar6 = 0;
          if (uVar11 != 0) {
            do {
              if (local_218[iVar6] == local_c[2]) {
                bVar4 = true;
                goto LAB_0050ec34;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < (int)uVar11);
          }
          bVar4 = false;
LAB_0050ec34:
          if ((!bVar3) || (!bVar4)) {
            iVar6 = -1;
            bVar2 = *pbVar15;
            while (bVar2 != 0) {
              iVar6 = iVar6 * 0x21 + (uint)bVar2;
              pbVar12 = pbVar15 + 1;
              pbVar15 = pbVar15 + 1;
              bVar2 = *pbVar12;
            }
            local_118[uVar11] = iVar6;
            local_218[uVar11] = local_c[2];
            goto LAB_0050ec6e;
          }
        }
      }
      else {
        cVar5 = IsNFSUBrand();
        if (cVar5 != '\0') {
          if (*(int *)(param_1 + 0x88) == 0) {
            piVar7 = piVar16;
            if (piVar16 != (int *)0x0) {
              for (; piVar7 < piVar16 + iVar13 * 2; piVar7 = piVar7 + 2) {
                if (*piVar7 == -0x3182724b) {
                  if (piVar7 != (int *)0x0) {
                    cVar5 = (char)piVar7[1];
                    goto LAB_0050e9f5;
                  }
                  break;
                }
              }
            }
            cVar5 = '\0';
LAB_0050e9f5:
            if (cVar5 != *(char *)(local_14 + 0xdc)) goto LAB_0050ec81;
          }
          piVar7 = piVar16;
          if (piVar16 != (int *)0x0) {
            for (; (piVar7 < piVar16 + iVar13 * 2 && (*piVar7 != -0x14fefe1e)); piVar7 = piVar7 + 2)
            {
            }
          }
          piVar7 = piVar16;
          if (piVar16 != (int *)0x0) {
            for (; (piVar7 < piVar16 + iVar13 * 2 && (*piVar7 != -0x3182724b)); piVar7 = piVar7 + 2)
            {
            }
          }
          piVar7 = piVar16 + iVar13 * 2;
          if (piVar16 != (int *)0x0) {
            for (; (piVar16 < piVar7 && (*piVar16 != 0x10c98090)); piVar16 = piVar16 + 2) {
            }
          }
          pbVar15 = (byte *)*local_c;
          iVar6 = -1;
          bVar2 = *pbVar15;
          pbVar12 = pbVar15;
          while (bVar2 != 0) {
            pbVar1 = pbVar12 + 1;
            iVar6 = iVar6 * 0x21 + (uint)bVar2;
            pbVar12 = pbVar12 + 1;
            bVar2 = *pbVar1;
          }
          uVar11 = (uint)local_5;
          iVar13 = 0;
          if (uVar11 != 0) {
            do {
              if (local_118[iVar13] == iVar6) goto LAB_0050ec81;
              iVar13 = iVar13 + 1;
            } while (iVar13 < (int)uVar11);
          }
          iVar6 = -1;
          bVar2 = *pbVar15;
          while (bVar2 != 0) {
            iVar6 = iVar6 * 0x21 + (uint)bVar2;
            pbVar12 = pbVar15 + 1;
            pbVar15 = pbVar15 + 1;
            bVar2 = *pbVar12;
          }
          local_118[uVar11] = iVar6;
LAB_0050ec6e:
          local_5 = local_5 + 1;
          GarageRimsBrowser__AddPickable();
        }
      }
    }
LAB_0050ec81:
    pcVar10 = "WHEELS";
    iVar6 = -1;
    uVar11 = 0x57;
    do {
      iVar6 = iVar6 * 0x21 + uVar11;
      pbVar15 = (byte *)(pcVar10 + 1);
      uVar11 = (uint)*pbVar15;
      pcVar10 = pcVar10 + 1;
    } while (*pbVar15 != 0);
    local_c = (int *)CarPartDatabase__GetCarPart(iVar6,0xffffffff,0,local_c,0xffffffff);
    iVar6 = DAT_0073573c;
  } while( true );
}


// ==== 0x50ed30 GarageRimsBrowser::CanPlayerPurchasePart

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsBrowser__CanPlayerPurchasePart(undefined4 param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  if ((DAT_00745e40 == 1) && (DAT_0073440c == '\0')) {
    cVar1 = GarageRimsBrowser__IsPartLocked(param_1);
    if ((cVar1 == '\0') || (DAT_00735ec1 != '\0')) {
      Career__GetCash(&DAT_0075eef8);
      uVar2 = GetCarPartCost();
      if ((int)uVar2 <= (int)((ulonglong)uVar2 >> 0x20)) {
        return 1;
      }
    }
    return 0;
  }
  return 1;
}


// ==== 0x50ed90 GarageRimsBrowser::IsInstallingPart

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

uint GarageRimsBrowser__IsInstallingPart(int param_1)

{
  char cVar1;
  uint uVar2;
  int unaff_ESI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar2 = DAT_00745e40;
  if (DAT_00745e40 == 1) {
    cVar1 = *(char *)(unaff_ESI + 0x10);
    if (cVar1 != '\x06') {
      uVar2 = PartStore__HasPart(&DAT_0075f344);
      if ((char)uVar2 != '\0') {
        uVar2 = (int)cVar1;
        if ((&DAT_00745b6c)[cVar1] != unaff_ESI) goto LAB_0050ee00;
        local_10 = 0x639;
        local_14 = 0x368294c0;
        local_c = 0;
        uVar2 = FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
      }
LAB_0050edf2:
      return uVar2 & 0xffffff00;
    }
  }
  else if (DAT_00745e40 != 2) goto LAB_0050edf2;
LAB_0050ee00:
  return CONCAT31((int3)(uVar2 >> 8),1);
}


// ==== 0x50ee10 GarageRimsBrowser::IsBuyingPart

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsBrowser__IsBuyingPart(void)

{
  char cVar1;
  int unaff_ESI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  cVar1 = GarageRimsBrowser__IsPartLocked(unaff_ESI);
  if ((cVar1 == '\0') && (DAT_00745e40 == 1)) {
    cVar1 = PartStore__HasPart(&DAT_0075f344);
    if (cVar1 == '\0') {
      cVar1 = GarageRimsBrowser__CanPlayerPurchasePart(unaff_ESI);
      if (cVar1 != '\0') {
        return 1;
      }
      local_10 = 0x639;
      local_14 = 0x2c0344a3;
      local_c = 0;
      FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(unaff_ESI + 0xc));
    }
  }
  return 0;
}


// ==== 0x50ee90 GarageRimsBrowser::IsPartLocked

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon_db.md */

uint GarageRimsBrowser__IsPartLocked(void)

{
  uint in_EAX;
  uint *puVar1;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (in_EAX = 0, DAT_0073766c != 0)) {
    puVar1 = (uint *)(DAT_00737668 + 0x24);
    while ((puVar1[-1] != 1 || (*puVar1 != (uint)*(byte *)(unaff_EDI + 0x11)))) {
      in_EAX = in_EAX + 1;
      puVar1 = puVar1 + 0xd;
      if (DAT_0073766c <= in_EAX) {
        return in_EAX & 0xffffff00;
      }
    }
    in_EAX = in_EAX * 0x34;
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x50eee0 GarageRimsBrowser::ScrollPickables

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void GarageRimsBrowser__ScrollPickables(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBX;
  
  iVar2 = *(int *)(unaff_EBX + 0x40);
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xc53843de);
    }
  }
  FEObject__SetInvisible(iVar3);
  if (param_1 == -0x6edfbf62) {
    if ((*(int *)(unaff_EBX + 0x40) != *(int *)(unaff_EBX + 0x44)) &&
       (*(int *)(unaff_EBX + 0x44) != unaff_EBX + 0x44)) {
      *(undefined4 *)(unaff_EBX + 0x40) = *(undefined4 *)(*(int *)(unaff_EBX + 0x40) + 4);
    }
  }
  else if (((param_1 == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EBX + 0x40) != *(undefined4 **)(unaff_EBX + 0x48))) &&
          (*(int *)(unaff_EBX + 0x44) != unaff_EBX + 0x44)) {
    *(undefined4 *)(unaff_EBX + 0x40) = **(undefined4 **)(unaff_EBX + 0x40);
  }
  iVar3 = *(int *)(unaff_EBX + 0x40);
  iVar5 = *(int *)(iVar3 + 0xc);
  piVar4 = *(int **)(iVar5 + 0x14);
  piVar1 = piVar4 + *(short *)(iVar5 + 0x1c) * 2;
  if (piVar4 != (int *)0x0) {
    for (; (piVar4 < piVar1 && (*piVar4 != -0x14fefe1e)); piVar4 = piVar4 + 2) {
    }
  }
  iVar5 = GetRimSizeHash();
  *(int *)(unaff_EBX + 0x90) = iVar5;
  if (iVar5 == 0) {
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
      if (DAT_0073578c == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(0xc53843de);
      }
    }
    FEObject__SetInvisible(iVar5);
  }
  else {
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
      if (DAT_0073578c == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(0xc53843de);
      }
    }
    FEObject__SetVisible(iVar5);
    FUN_004ad7b0(*(undefined4 *)(unaff_EBX + 0x90));
  }
  if (iVar2 != iVar3) {
    FUN_004f8910();
    GarageRimsBrowser__RedrawHeading(unaff_EBX);
    GarageManager__PreviewPart();
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
  }
  return;
}


// ==== 0x50f0e0 GarageRimsBrowser::AddPickable

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall GarageRimsBrowser__AddPickable(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int unaff_EBX;
  char *pcVar7;
  
  piVar3 = _malloc(0x10);
  piVar3[2] = in_EAX;
  piVar3[3] = in_EAX;
  puVar2 = *(undefined4 **)(param_1 + 0x48);
  *puVar2 = piVar3;
  *(int **)(param_1 + 0x48) = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = param_1 + 0x44;
  iVar4 = FUN_004f8730(param_1 + 0x4c,piVar3[2],0,1);
  if (unaff_EBX == 0) {
    pcVar7 = "VISUAL_PART_RIMS";
    iVar6 = -1;
    uVar5 = 0x56;
    do {
      iVar6 = iVar6 * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != iVar6)) {
      *(int *)(iVar4 + 0x24) = iVar6;
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    }
  }
  else if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != unaff_EBX)) {
    *(int *)(iVar4 + 0x24) = unaff_EBX;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    return;
  }
  return;
}


// ==== 0x50f170 GarageRimsBrowser::MoveBackPackage

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 GarageRimsBrowser__MoveBackPackage(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar1 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
  }
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return uVar3;
}


// ==== 0x50f200 GarageRimsBrowser::RedrawHeading

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageRimsBrowser__RedrawHeading(int param_1)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int extraout_ECX;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 local_28 [8];
  int local_8;
  
  iVar5 = *(int *)(param_1 + 0x40);
  iVar4 = 0;
  puVar10 = local_28;
  for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  pcVar2 = (char *)**(undefined4 **)(iVar5 + 0xc);
  if (pcVar2 != (char *)0x0) {
    cVar3 = *pcVar2;
    while (cVar3 != '\0') {
      iVar8 = iVar4 + 1;
      iVar4 = iVar4 + 1;
      cVar3 = pcVar2[iVar8];
    }
  }
  iVar8 = -1;
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) break;
    if (pcVar2[iVar4] == ' ') {
      iVar8 = iVar4;
    }
  } while (iVar8 < 0);
  iVar4 = 0;
  local_8 = iVar5;
  if (0 < iVar8) {
    do {
      *(undefined1 *)((int)local_28 + iVar4) = *(undefined1 *)(iVar4 + **(int **)(iVar5 + 0xc));
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar8);
  }
  FEngPrintf(&DAT_006cc568,local_28);
  switch(*(undefined1 *)(*(int *)(iVar5 + 0xc) + 0x11)) {
  case 0:
    uVar9 = 0x2cbd3c8d;
    break;
  case 1:
    uVar9 = 0x2cbd3c6b;
    break;
  case 2:
    uVar9 = 0x2cbd3c6c;
    break;
  case 3:
    uVar9 = 0x2cbd3c6d;
    break;
  case 4:
    uVar9 = 0x2cbd3c8f;
    break;
  default:
    uVar9 = 0x50fe8c15;
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int *)(iVar5 + 0x14) != 0)) {
    FUN_004f7c00(uVar9,0,0,*(int *)(iVar5 + 0x18));
  }
  if (((DAT_00745e40 == 2) || (DAT_00735ec1 != '\0')) ||
     (cVar3 = PartStore__HasPart(&DAT_0075f344), cVar3 != '\0')) {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0050f4ae:
      if (DAT_0073578c == 0) {
LAB_0050f4c8:
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(0x7c5a7469);
      }
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar4 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar4 + 0xec), iVar5 == 0)))) goto LAB_0050f4ae;
          goto LAB_0050f49a;
        }
        goto LAB_0050f4c8;
      }
LAB_0050f49a:
      if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_0050f4ae;
    }
    FEObject__SetInvisible(iVar5);
  }
  else {
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0050f392:
      if ((iVar5 != 0) && (iVar4 = FUN_004ef050(0x7c5a7469), iVar4 != 0)) {
LAB_0050f3a9:
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000;
        if (*(int *)(iVar4 + 0x18) == 5) {
          uVar9 = *(undefined4 *)(iVar4 + 0x60);
          iVar5 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar5) {
            do {
              FEObject__SetVisible(uVar9);
              uVar9 = *(undefined4 *)(extraout_EDX + 4);
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
        }
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0050f378:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 == 0))
        goto LAB_0050f392;
        goto LAB_0050f3a9;
      }
      if (DAT_0073578c != 0) {
        iVar8 = *(int *)(DAT_0073578c + 8);
        if ((iVar8 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar8 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar8 + 0xec), iVar4 == 0)))) goto LAB_0050f392;
        goto LAB_0050f378;
      }
    }
    if (((*(int *)(local_8 + 0xc) == 0) || (uVar6 = MapCarPartIDToCareerUpgrade(), 0x1f < uVar6)) ||
       (iVar5 = (&DAT_00733f78)[uVar6], iVar5 == 0)) {
switchD_0050f40b_caseD_0:
      uVar9 = 0;
    }
    else {
      switch(*(undefined1 *)(extraout_ECX + 0x11)) {
      default:
        goto switchD_0050f40b_caseD_0;
      case 1:
        uVar9 = *(undefined4 *)(iVar5 + 4);
        break;
      case 2:
        uVar9 = *(undefined4 *)(iVar5 + 8);
        break;
      case 3:
        uVar9 = *(undefined4 *)(iVar5 + 0xc);
      }
    }
    FEngPrintf(&DAT_006ca778,uVar9);
  }
  iVar5 = DAT_0073578c;
  piVar7 = *(int **)(*(int *)(local_8 + 0xc) + 0x14);
  piVar1 = piVar7 + *(short *)(*(int *)(local_8 + 0xc) + 0x1c) * 2;
  if (piVar7 != (int *)0x0) {
    for (; (piVar7 < piVar1 && (*piVar7 != -0x14fefe1e)); piVar7 = piVar7 + 2) {
    }
  }
  iVar4 = GetRimSizeHash();
  *(int *)(param_1 + 0x90) = iVar4;
  if (iVar4 != 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0050f592:
      if ((iVar5 != 0) && (iVar4 = FUN_004ef050(0xc53843de), iVar4 != 0)) {
LAB_0050f5a9:
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000;
        if (*(int *)(iVar4 + 0x18) == 5) {
          uVar9 = *(undefined4 *)(iVar4 + 0x60);
          iVar5 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar5) {
            do {
              FEObject__SetVisible(uVar9);
              uVar9 = *(undefined4 *)(extraout_EDX_00 + 4);
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
        }
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0050f578:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 == 0))
        goto LAB_0050f592;
        goto LAB_0050f5a9;
      }
      if (DAT_0073578c != 0) {
        iVar8 = *(int *)(DAT_0073578c + 8);
        if ((iVar8 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar8 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar8 + 0xec), iVar4 == 0)))) goto LAB_0050f592;
        goto LAB_0050f578;
      }
    }
    iVar5 = *(int *)(param_1 + 0x90);
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          return;
        }
        iVar8 = *(int *)(DAT_0073578c + 8);
        if ((iVar8 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar8 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar8 + 0xec), iVar4 == 0)))) goto LAB_0050f654;
      }
      if ((iVar4 != 0) && (iVar4 = FUN_004ffb70(), iVar4 != 0)) goto LAB_0050f678;
    }
LAB_0050f654:
    if (DAT_0073578c == 0) {
      return;
    }
    iVar4 = FUN_004ef050(0xc53843de);
    if (iVar4 == 0) {
      return;
    }
LAB_0050f678:
    if ((*(int *)(iVar4 + 0x18) == 1) && (*(int *)(iVar4 + 0x24) != iVar5)) {
      *(int *)(iVar4 + 0x24) = iVar5;
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      return;
    }
    return;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_0050f71f:
    if (iVar5 != 0) {
      uVar9 = FUN_004ef050(0xc53843de);
      FEObject__SetInvisible(uVar9);
      return;
    }
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0050f705:
      if ((iVar4 != 0) && (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 != 0))
      goto LAB_0050f746;
      goto LAB_0050f71f;
    }
    if (DAT_0073578c != 0) {
      iVar8 = *(int *)(DAT_0073578c + 8);
      if ((iVar8 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar8 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar8 + 0xec), iVar4 == 0)))) goto LAB_0050f71f;
      goto LAB_0050f705;
    }
  }
  iVar4 = 0;
LAB_0050f746:
  FEObject__SetInvisible(iVar4);
  return;
}


// ==== 0x50f780 GarageRimsBrowser::NotificationMessage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall GarageRimsBrowser__NotificationMessage(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = param_1;
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        cVar1 = GarageRimsBrowser__IsInstallingPart(param_1);
        cVar2 = GarageRimsBrowser__IsBuyingPart();
        if (cVar1 != '\0') {
          local_10 = 0;
          local_c = 0;
          local_2c = 0x76d94941;
          local_24 = 0xf0aadebb;
          local_28 = 0x639;
          local_1c = 0;
          local_20 = 0x541389e5;
          local_18 = 0;
          local_14 = 0xb8a7c6cc;
          FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (cVar2 == '\0') {
          return;
        }
        local_10 = 0;
        local_c = 0;
        local_1c = 0;
        local_18 = 0;
        local_2c = 0x39223856;
        local_24 = 0x2f6484d0;
        local_28 = 0x639;
        local_20 = 0x541389e5;
        local_14 = 0xb8a7c6cc;
        FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x2f6484d0) {
        GarageManager__InstallPart(*(undefined4 *)(*(int *)(param_1 + 0x40) + 0xc),0);
        if (DAT_00745e40 == 1) {
          FUN_005a2620();
        }
        iVar3 = GarageRimsBrandBrowser___GarageRimsBrandBrowser();
        if (iVar3 != -1) {
          *(uint *)(&DAT_00760158 + iVar3 * 4) = *(uint *)(&DAT_00760158 + iVar3 * 4) | 3;
        }
        GarageRimsBrowser__RedrawHeading(param_1);
        *(undefined1 *)(param_1 + 0x8c) = 1;
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageRimsBrowser__MoveBackPackage(param_1);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 == 0xc98356ba) {
      FUN_004f89d0();
      iVar3 = local_8;
      FUN_004f7d30();
      if (*(char *)(iVar3 + 0x8c) == '\0') {
        return;
      }
      FEngSwitchPackages(*(undefined4 *)(iVar3 + 0xc));
      return;
    }
    if (param_2 != 0xf0aadebb) {
      return;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 0xc);
    if (*(char *)(iVar3 + 0x10) == '\x05') {
      GarageManager__InstallPart(iVar3,0);
    }
    GarageManager__InstallPart(iVar3,0);
    *(undefined1 *)(param_1 + 0x8c) = 1;
    return;
  }
  GarageRimsBrowser__ScrollPickables(param_2);
  return;
}


// ==== 0x50f990 CreateGarageRimsBrowserScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageRimsBrowserScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006893d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x94);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageRimsBrowser__GarageRimsBrowser(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50f9f0 IsEnginePainting

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 IsEnginePainting(void)

{
  if ((DAT_00735718 == 3) && (DAT_006f88a4 == 8)) {
    return 1;
  }
  return 0;
}


// ==== 0x50fa10 IsCaliperPainting

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

undefined4 IsCaliperPainting(void)

{
  if ((DAT_00735718 == 3) && (DAT_006f88a4 == 0xb)) {
    return 1;
  }
  return 0;
}


// ==== 0x50fa30 GarageDecalsZone::_GarageDecalsZone

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall GarageDecalsZone___GarageDecalsZone(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageDecalsZone__scalar_deleting_destructor_006c02a8;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x50fa80 GarageDecalsZone::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageDecalsZone__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageDecalsZone___GarageDecalsZone();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x50faa0 CreateDecalZoneChooseScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateDecalZoneChooseScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688e63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageDecalsZone__GarageDecalsZone(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x50fb00 GarageDecalsZone::GarageDecalsZone

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageDecalsZone__GarageDecalsZone(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  bool bVar12;
  undefined4 local_19;
  undefined4 local_15;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar2 = param_1 + 0x11;
  *param_1 = &PTR_GarageDecalsZone__scalar_deleting_destructor_006c02a8;
  *puVar2 = puVar2;
  param_1[0x12] = puVar2;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar7 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar7 != 0) && (*(int *)(iVar7 + 0x18) != 0)) && (*(int **)(iVar7 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar7 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar7 + 0x18));
  }
  cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,1);
  uVar5 = DAT_0073766c;
  if (cVar6 == '\0') {
    uVar8 = 0;
    if (DAT_0073766c == 0) {
LAB_0050fbe4:
      bVar4 = false;
    }
    else {
      piVar10 = (int *)(DAT_00737668 + 0x24);
      do {
        if ((piVar10[-1] == 1) && (*piVar10 == 2)) {
          if (*(char *)(uVar8 * 0x34 + 0x30 + DAT_00737668) == '\0') goto LAB_0050fbe4;
          goto LAB_0050fbea;
        }
        uVar8 = uVar8 + 1;
        piVar10 = piVar10 + 0xd;
      } while (uVar8 < DAT_0073766c);
      bVar4 = false;
    }
  }
  else {
LAB_0050fbea:
    bVar4 = true;
  }
  cVar6 = Career__IsUpgradeUnlocked(&DAT_0075eef8,1);
  iVar7 = DAT_00745e40;
  if (cVar6 == '\0') {
    uVar8 = 0;
    if (uVar5 == 0) {
LAB_0050fc34:
      bVar3 = false;
    }
    else {
      piVar10 = (int *)(DAT_00737668 + 0x24);
      do {
        if ((piVar10[-1] == 1) && (*piVar10 == 3)) {
          if (*(char *)(uVar8 * 0x34 + 0x30 + DAT_00737668) == '\0') goto LAB_0050fc34;
          goto LAB_0050fc38;
        }
        uVar8 = uVar8 + 1;
        piVar10 = piVar10 + 0xd;
      } while (uVar8 < uVar5);
      bVar3 = false;
    }
  }
  else {
LAB_0050fc38:
    bVar3 = true;
  }
  if ((bVar4) || (DAT_00735ec1 != '\0')) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if ((bVar3) || (bVar3 = false, DAT_00735ec1 != '\0')) {
    bVar3 = true;
  }
  bVar12 = DAT_00745e40 == 1;
  iVar9 = UnlockTeller__GetNewlyUnlockedPartLevel();
  if ((iVar7 == 1) && (iVar9 == 2)) {
    local_15 = 1;
  }
  else {
    local_15 = 0;
    if ((iVar7 == 1) && (local_19 = 1, iVar9 == 3)) goto LAB_0050fcb0;
  }
  local_19 = 0;
LAB_0050fcb0:
  pcVar11 = "DECAL_ZONE_WINDSHIELD";
  do {
    pcVar1 = pcVar11 + 1;
    pcVar11 = pcVar11 + 1;
  } while (*pcVar1 != '\0');
  GarageDecalsZone__AddPickable(0,0x46a798ac,0,0);
  pcVar11 = "DECAL_ZONE_REARWINDOW";
  do {
    pcVar1 = pcVar11 + 1;
    pcVar11 = pcVar11 + 1;
  } while (*pcVar1 != '\0');
  GarageDecalsZone__AddPickable(1,0x4b5a083a,0,0);
  if (bVar12 || bVar4) {
    pcVar11 = "DECAL_ZONE_LEFTDOOR";
    do {
      pcVar1 = pcVar11 + 1;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    GarageDecalsZone__AddPickable(2,0x542f8a37,local_15,0);
    pcVar11 = "DECAL_ZONE_RIGHTDOOR";
    do {
      pcVar1 = pcVar11 + 1;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    GarageDecalsZone__AddPickable(3,0xfd12c62a,local_15,0);
    pcVar11 = "DECAL_ZONE_LEFTPANEL";
    do {
      pcVar1 = pcVar11 + 1;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    GarageDecalsZone__AddPickable(4,0xdaf24433,local_15,0);
    pcVar11 = "DECAL_ZONE_RIGHTPANEL";
    do {
      pcVar1 = pcVar11 + 1;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    GarageDecalsZone__AddPickable(5,0xa03cfe86,local_15,0);
  }
  if (bVar12 || bVar3) {
    pcVar11 = "DECAL_ZONE_HOOD";
    do {
      pcVar1 = pcVar11 + 1;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    GarageDecalsZone__AddPickable(6,0xf2b1f5a3,local_19,0);
  }
  puVar2 = (undefined4 *)param_1[0x11];
  do {
    if (puVar2 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_0050fe2e:
      FUN_004f8960();
      GarageDecalsZone__RedrawHeading(param_1);
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar2[2] == DAT_00735748) {
      param_1[0x10] = puVar2;
      goto LAB_0050fe2e;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


// ==== 0x50fe70 GarageDecalsZone::AddPickable

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageDecalsZone__AddPickable(int param_1,int param_2,undefined1 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar2 = _malloc(0x18);
  piVar2[2] = param_1;
  *(undefined1 *)(piVar2 + 5) = param_3;
  piVar2[4] = param_2;
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  *puVar1 = piVar2;
  *(int **)(in_EAX + 0x48) = piVar2;
  piVar2[1] = (int)puVar1;
  *piVar2 = in_EAX + 0x44;
  iVar3 = FUN_004f8730(in_EAX + 0x4c,piVar2[2],param_4,1);
  if (((unaff_EDI != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) != unaff_EDI)) {
    *(int *)(iVar3 + 0x24) = unaff_EDI;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x50fee0 GarageDecalsZone::ScrollPickables

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageDecalsZone__ScrollPickables(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (unaff_EBX == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EDI + 0x44)) && (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EBX == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48))) &&
          (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    FUN_004f8910();
    GarageDecalsZone__RedrawHeading(unaff_EDI);
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x50ff80 GarageDecalsZone::RedrawHeading

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageDecalsZone__RedrawHeading(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  
  iVar7 = *(int *)(param_1 + 0x40);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  FUN_00495f00(*(undefined4 *)(iVar7 + 0x10));
  cVar5 = Career__IsUpgradeUnlocked(&DAT_0075eef8,1);
  uVar4 = DAT_0073766c;
  iVar12 = DAT_00737668;
  if (cVar5 == '\0') {
    uVar6 = 0;
    if (DAT_0073766c == 0) {
LAB_00510024:
      bVar3 = false;
    }
    else {
      piVar9 = (int *)(DAT_00737668 + 0x24);
      do {
        if ((piVar9[-1] == 1) && (*piVar9 == 2)) {
          if (*(char *)(uVar6 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_0051002a;
          goto LAB_00510024;
        }
        uVar6 = uVar6 + 1;
        piVar9 = piVar9 + 0xd;
      } while (uVar6 < DAT_0073766c);
      bVar3 = false;
    }
  }
  else {
LAB_0051002a:
    bVar3 = true;
  }
  cVar5 = Career__IsUpgradeUnlocked(&DAT_0075eef8,1);
  if (cVar5 == '\0') {
    uVar6 = 0;
    if (uVar4 == 0) {
LAB_00510071:
      bVar1 = false;
    }
    else {
      piVar9 = (int *)(iVar12 + 0x24);
      do {
        if ((piVar9[-1] == 1) && (*piVar9 == 3)) {
          if (*(char *)(uVar6 * 0x34 + 0x30 + iVar12) != '\0') goto LAB_00510075;
          goto LAB_00510071;
        }
        uVar6 = uVar6 + 1;
        piVar9 = piVar9 + 0xd;
      } while (uVar6 < uVar4);
      bVar1 = false;
    }
  }
  else {
LAB_00510075:
    bVar1 = true;
  }
  if ((bVar3) || (DAT_00735ec1 != '\0')) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((bVar1) || (bVar1 = false, DAT_00735ec1 != '\0')) {
    bVar1 = true;
  }
  bVar2 = false;
  switch(*(undefined4 *)(iVar7 + 8)) {
  case 0:
  case 1:
    goto switchD_005100a5_default;
  case 2:
  case 3:
  case 4:
  case 5:
    break;
  case 6:
    bVar3 = bVar1;
    break;
  default:
    goto switchD_005100a5_default;
  }
  bVar2 = !bVar3;
switchD_005100a5_default:
  iVar7 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar7 != 0) && (iVar12 = *(int *)(iVar7 + 0x18), iVar12 != 0)) &&
     (*(int *)(iVar7 + 0x14) != 0)) {
    uVar11 = 0;
    uVar10 = 0;
    uVar8 = GarageManager__GetMsgForUpgradeLevel(&DAT_00744ff0);
    FUN_004f7c00(uVar8,uVar10,uVar11,iVar12);
  }
  if (bVar2) {
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
       (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
      if (DAT_0073578c != 0) {
        uVar8 = FUN_004ef050(0xa8a3681a);
        FEObject__SetVisible(uVar8);
        return;
      }
      iVar7 = 0;
    }
    FEObject__SetVisible(iVar7);
    return;
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c != 0) {
      uVar8 = FUN_004ef050(0xa8a3681a);
      FEObject__SetInvisible(uVar8);
      return;
    }
    iVar7 = 0;
  }
  FEObject__SetInvisible(iVar7);
  return;
}


// ==== 0x5101f0 GarageDecalsZone::NotificationMessage

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __thiscall GarageDecalsZone__NotificationMessage(int param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  char local_5;
  
  local_c = param_1;
  if (0x9120409e < param_2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xc98356ba) {
        return;
      }
      FUN_004f89d0();
      FUN_004f7d30();
      return;
    }
LAB_005105b3:
    GarageDecalsZone__ScrollPickables();
    return;
  }
  if (param_2 == 0x9120409e) goto LAB_005105b3;
  if (param_2 != 0xc407210) {
    if (param_2 != 0x780885f9) {
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageCategoryVisual__MoveBackPackage(param_1);
      return;
    }
    uVar11 = 0xffffffff;
    uVar10 = 0;
    uVar9 = 0;
    uVar8 = 8;
    FECarConfig__GetCarType(8,0,0,0xffffffff);
    piVar4 = (int *)FUN_0057ced0(&DAT_0073ad40,uVar8,uVar9,uVar10,uVar11);
    if (piVar4 == (int *)0x0) {
      return;
    }
    bVar2 = true;
    do {
      if (!bVar2) break;
      pcVar5 = "STOCK";
      do {
        cVar3 = pcVar5[*piVar4 + -0x6c3200];
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        if ((cVar3 == '\0') || (cVar1 == '\0')) break;
      } while (cVar3 == cVar1);
      if (cVar3 == cVar1) {
        bVar2 = false;
      }
      else {
        uVar10 = 0xffffffff;
        uVar9 = 0;
        uVar8 = 8;
        FECarConfig__GetCarType(8,0,0xffffffff);
        piVar4 = (int *)FUN_004b3940(&DAT_0073ad40,piVar4,uVar8,uVar9,uVar10);
      }
    } while (piVar4 != (int *)0x0);
    GarageManager__InstallPart(piVar4,0);
    return;
  }
  local_10 = *(int *)(param_1 + 0x40);
  if (*(char *)(*(int *)(param_1 + 0x58) + 0x18) != '\0') {
    return;
  }
  cVar3 = Career__IsUpgradeUnlocked(&DAT_0075eef8,1);
  if (cVar3 == '\0') {
    cVar3 = EasterEggs__IsPartUnlocked();
    bVar2 = false;
    if (cVar3 != '\0') goto LAB_0051031b;
  }
  else {
LAB_0051031b:
    bVar2 = true;
  }
  cVar3 = Career__IsUpgradeUnlocked(&DAT_0075eef8,1);
  if (cVar3 == '\0') {
    cVar3 = EasterEggs__IsPartUnlocked();
    bVar7 = false;
    if (cVar3 != '\0') goto LAB_00510344;
  }
  else {
LAB_00510344:
    bVar7 = true;
  }
  if ((bVar2) || (DAT_00735ec1 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar7) || (bVar7 = false, DAT_00735ec1 != '\0')) {
    bVar7 = true;
  }
  uVar8 = *(undefined4 *)(local_10 + 8);
  switch(uVar8) {
  default:
    goto switchD_00510372_caseD_0;
  case 2:
  case 3:
  case 4:
  case 5:
    break;
  case 6:
    bVar2 = bVar7;
  }
  if (!bVar2) {
    if (DAT_006f1dd8 == 0) {
      return;
    }
    if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
    return;
  }
switchD_00510372_caseD_0:
  local_5 = '\x01';
  bVar2 = false;
  DAT_00735748 = uVar8;
  cVar3 = GarageCategoryVisual__IsWidebodyInstalled();
  bVar7 = cVar3 != '\0';
  switch(uVar8) {
  case 0:
    DAT_00735750 = 0;
    DAT_0073574c = 0;
    bVar2 = true;
    break;
  case 1:
    DAT_00735750 = 0;
    DAT_0073574c = 0;
    bVar2 = true;
    break;
  case 2:
    DAT_0073574c = 0;
    break;
  case 3:
    DAT_0073574c = 0;
    break;
  case 4:
    local_5 = bVar7;
    bVar2 = bVar7;
    if (bVar7) {
      DAT_0073574c = 0;
      DAT_00735750 = 0;
    }
    break;
  case 5:
    local_5 = bVar7;
    bVar2 = bVar7;
    if (bVar7) {
      DAT_0073574c = 0;
      DAT_00735750 = 0;
    }
    break;
  case 6:
    local_5 = '\0';
    if (DAT_0074546c != 0) {
      local_10 = bStringHash();
      iVar6 = bStringHash();
      if (iVar6 != local_10) {
        local_24 = 0xed716986;
        local_20 = 0xed716986;
        local_18 = 0;
        local_14 = 0;
        local_34 = 0x8c5249b2;
        local_2c = 0x780885f9;
        local_30 = 0x639;
        local_28 = 0x541389e5;
        local_1c = 0xb8a7c6cc;
        FUN_004dc6e0(&local_34,"GenericDialog.fng",*(undefined4 *)(local_c + 0xc));
        return;
      }
    }
  }
  iVar6 = FUN_004b2330();
  if (iVar6 != 0) {
    FUN_004b0150();
  }
  iVar6 = local_c;
  GarageManager__PushScreen(*(undefined4 *)(local_c + 0xc));
  if (local_5 == '\0') {
    FEngSwitchPackages(*(undefined4 *)(iVar6 + 0xc));
    return;
  }
  if (!bVar2) {
    FEngSwitchPackages(*(undefined4 *)(iVar6 + 0xc));
    return;
  }
  FEngSwitchPackages(*(undefined4 *)(iVar6 + 0xc));
  return;
}


// ==== 0x510600 GarageDecalLayout::_GarageDecalLayout

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageDecalLayout___GarageDecalLayout(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageDecalLayout__scalar_deleting_destructor_006c0254;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x510650 GarageDecalLayout::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageDecalLayout__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageDecalLayout___GarageDecalLayout();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x510670 CreateDecalSizeChooseScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateDecalSizeChooseScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688e43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageDecalLayout__GarageDecalLayout(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5106d0 GarageDecalLayout::GarageDecalLayout

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageDecalLayout__GarageDecalLayout(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688f1e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x11;
  *param_1 = &PTR_GarageDecalLayout__scalar_deleting_destructor_006c0254;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_4 = CONCAT31(local_4._1_3_,2);
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar2 + 0x18));
  }
  uVar3 = DAT_00735748;
  *(undefined1 *)(param_1 + 0x22) = 0;
  *(undefined1 *)((int)param_1 + 0x89) = 0;
  switch(uVar3) {
  default:
    goto switchD_00510773_caseD_0;
  case 4:
    uVar4 = 0;
    uVar3 = 0x8c1ed0ae;
    bStringHash(0x8c1ed0ae,0);
    GarageDecalsSlot__AddPickable(0,uVar3,uVar4);
    break;
  case 5:
    uVar4 = 0;
    uVar3 = 0x8c1ed0ae;
    bStringHash(0x8c1ed0ae,0);
    GarageDecalsSlot__AddPickable(0,uVar3,uVar4);
    break;
  case 6:
    uVar4 = 0;
    uVar3 = 0x8c1ed0ae;
    bStringHash(0x8c1ed0ae,0);
    GarageDecalsSlot__AddPickable(0,uVar3,uVar4);
  }
  uVar4 = 0;
  uVar3 = 0x8c1ed0af;
  bStringHash(0x8c1ed0af,0);
  GarageDecalsSlot__AddPickable(1,uVar3,uVar4);
switchD_00510773_caseD_0:
  puVar1 = (undefined4 *)param_1[0x11];
  do {
    if (puVar1 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_00510811:
      FUN_004f8960();
      GarageDecalLayout__RedrawHeading();
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = pvStack_c;
      return param_1;
    }
    if (puVar1[2] == DAT_0073574c) {
      param_1[0x10] = puVar1;
      goto LAB_00510811;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x510860 GarageDecalLayout::ScrollPickables

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageDecalLayout__ScrollPickables(void)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0x40);
  if (unaff_EDI == -0x6edfbf62) {
    if ((iVar1 != *(int *)(in_EAX + 0x44)) && (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EDI == -0x4a68e40f) &&
           (*(undefined4 **)(in_EAX + 0x40) != *(undefined4 **)(in_EAX + 0x48))) &&
          (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x40) = **(undefined4 **)(in_EAX + 0x40);
  }
  if (iVar1 != *(int *)(in_EAX + 0x40)) {
    FUN_004f8910();
    GarageDecalLayout__RedrawHeading();
    if (unaff_EDI == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
  }
  return;
}


// ==== 0x510900 GarageDecalLayout::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageDecalLayout__RedrawHeading(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = *(int *)(unaff_EBX + 0x40);
  uVar2 = 0;
  if (DAT_00735748 == 4) {
    uVar2 = 0xdaf24433;
  }
  else if (DAT_00735748 == 5) {
    uVar2 = 0xa03cfe86;
  }
  else if (DAT_00735748 == 6) {
    uVar2 = 0xf2b1f5a3;
  }
  FUN_00495f00(uVar2);
  FUN_00495f00(*(undefined4 *)(iVar1 + 0x10));
  return;
}


// ==== 0x510980 GarageDecalLayout::NotificationMessage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall GarageDecalLayout__NotificationMessage(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  char local_5;
  
  local_5 = '\x01';
  if (0x928374ab < param_2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xc98356ba) {
        return;
      }
      FUN_004af5d0();
      FUN_004f89d0();
      FUN_004f7d30();
      if (*(char *)(param_1 + 0x88) == '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x89) == '\0') {
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      DAT_00735750 = 0;
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
LAB_005109bc:
    GarageDecalLayout__ScrollPickables();
    return;
  }
  if (param_2 == 0x928374ab) {
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    *(undefined1 *)(param_1 + 0x89) = 1;
    *(undefined1 *)(param_1 + 0x88) = 1;
    return;
  }
  if (param_2 != 0xc407210) {
    if (param_2 == 0x911ab364) {
      GarageCategoryVisual__MoveBackPackage(param_1);
      return;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
    goto LAB_005109bc;
  }
  if (*(char *)(*(int *)(param_1 + 0x58) + 0x18) != '\0') {
    return;
  }
  DAT_0073574c = *(int *)(*(int *)(param_1 + 0x40) + 8);
  GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
  iVar4 = DAT_00735748;
  switch(DAT_00735748) {
  case 2:
  case 3:
  case 6:
    local_5 = '\0';
    break;
  case 4:
  case 5:
    local_5 = DAT_0073574c == 0;
  }
  iVar2 = FECarConfig__GetCarType();
  iVar2 = iVar2 * 0xc90 + DAT_00734588;
  if (iVar4 == 6) {
    cVar1 = HypotheticalRide_AnyPartSlotSet_c58();
    if (cVar1 == '\0') goto LAB_00510b51;
    iVar3 = FUN_004f42f0(PTR_s__s_DECAL_HOOD_RECT_MEDIUM_006f88ec,iVar2);
    iVar2 = FUN_004f42f0(PTR_s__s_DECAL_HOOD_RECT_SMALL_006f88f0,iVar2);
    iVar4 = DAT_00745bb8;
  }
  else if (iVar4 == 4) {
    cVar1 = HypotheticalRide_AnyPartSlotSet_cf8();
    if (cVar1 == '\0') goto LAB_00510b51;
    iVar3 = FUN_004f42f0(PTR_s__s_DECAL_LEFT_QUARTER_RECT_MEDIU_006f88bc,iVar2);
    iVar2 = FUN_004f42f0(PTR_s__s_DECAL_LEFT_QUARTER_RECT_SMALL_006f88c0,iVar2);
    iVar4 = DAT_00745bcc;
  }
  else {
    if ((iVar4 != 5) || (cVar1 = HypotheticalRide_AnyPartSlotSet_d18(), cVar1 == '\0'))
    goto LAB_00510b51;
    iVar3 = FUN_004f42f0(PTR_s__s_DECAL_RIGHT_QUARTER_RECT_MEDI_006f88c4,iVar2);
    iVar2 = FUN_004f42f0(PTR_s__s_DECAL_RIGHT_QUARTER_RECT_SMAL_006f88c8,iVar2);
    iVar4 = DAT_00745bd0;
  }
  if (iVar4 != 0) {
    iVar5 = 0;
    if ((*(int *)(iVar4 + 8) != iVar3) && (*(int *)(iVar4 + 8) == iVar2)) {
      iVar5 = 1;
    }
    if (DAT_0073574c != iVar5) {
      local_10 = 0;
      local_c = 0;
      local_2c = 0x571dddc6;
      local_24 = 0x928374ab;
      local_28 = 0x639;
      local_1c = 0;
      local_20 = 0x541389e5;
      local_18 = 0;
      local_14 = 0xb8a7c6cc;
      FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
LAB_00510b51:
  if (local_5 == '\0') {
    FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  DAT_00735750 = 0;
  FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x510cf0 GarageDecalsSlot::_GarageDecalsSlot

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

void __fastcall GarageDecalsSlot___GarageDecalsSlot(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_GarageDecalsSlot__scalar_deleting_destructor_006c017c;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x510d40 GarageDecalsSlot::scalar_deleting_destructor

/* [canon] car high (ghidra-canon) docs/re/canon_db.md */

void * __thiscall GarageDecalsSlot__scalar_deleting_destructor(void *param_1,byte param_2)

{
  GarageDecalsSlot___GarageDecalsSlot();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x510d60 CreateDecalSlotChooseScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateDecalSlotChooseScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006893b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageDecalsSlot__GarageDecalsSlot(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x510dc0 GetNumDecalsForCategory

/* [canon] car low (ghidra-canon) docs/re/canon_db.md */

uint GetNumDecalsForCategory(int param_1)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined3 uVar7;
  uint uVar6;
  int unaff_ESI;
  
  piVar3 = &DAT_00706530;
  do {
    if (*piVar3 == 0xc) break;
    piVar3 = piVar3 + 7;
  } while ((int)piVar3 < 0x70669c);
  iVar4 = FECarConfig__GetCarType();
  pcVar5 = (char *)(iVar4 * 0xc90 + DAT_00734588);
  if (pcVar5 == (char *)0x0) {
    return 0xffffffff;
  }
  cVar2 = *pcVar5;
  while (cVar2 != '\0') {
    pcVar1 = pcVar5 + 1;
    pcVar5 = pcVar5 + 1;
    cVar2 = *pcVar1;
  }
  uVar7 = (undefined3)((uint)(param_1 + -2) >> 8);
  switch(param_1 + -2) {
  case 0:
  case 1:
    uVar6 = FUN_0051be00(CONCAT31(uVar7,unaff_ESI == 1));
    return uVar6 & 0xff;
  case 2:
  case 3:
    uVar6 = FUN_0051be40(CONCAT31(uVar7,unaff_ESI == 1));
    return uVar6 & 0xff;
  default:
    return 0xffffffff;
  }
}


// ==== 0x510e70 GetNumSlotsForWidebodySituation

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon_db.md */

int GetNumSlotsForWidebodySituation(void)

{
  char in_AL;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EBX;
  undefined4 *puVar4;
  
  if (in_AL == '\0') {
    iVar1 = FECarConfig__GetCarType();
    iVar3 = 0;
    if (iVar1 != 0x23) {
      if (iVar1 * 0xc90 + DAT_00734588 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = bStringHash();
      }
    }
    puVar4 = DAT_007449c0;
    if (((-1 < unaff_EBX) && (unaff_EBX < 6)) &&
       (puVar2 = (undefined4 *)NullUpdate_ret(), puVar4 != puVar2)) {
      do {
        if (puVar4[2] == iVar3) {
          return *(byte *)((int)puVar4 + unaff_EBX + 0x16) - 1;
        }
        puVar4 = (undefined4 *)*puVar4;
      } while (puVar4 != puVar2);
      return 0xfe;
    }
  }
  else {
    iVar1 = FECarConfig__GetCarType();
    iVar3 = 0;
    if (iVar1 != 0x23) {
      if (iVar1 * 0xc90 + DAT_00734588 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = bStringHash();
      }
    }
    puVar4 = DAT_007449c0;
    if ((-1 < unaff_EBX) && (unaff_EBX < 6)) {
      puVar2 = (undefined4 *)NullUpdate_ret();
      for (; puVar4 != puVar2; puVar4 = (undefined4 *)*puVar4) {
        if (puVar4[2] == iVar3) {
          return *(byte *)((int)puVar4 + unaff_EBX + 0x10) - 1;
        }
      }
    }
  }
  return 0xfe;
}


// ==== 0x510f50 GarageDecalsSlot::GarageDecalsSlot

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageDecalsSlot__GarageDecalsSlot(undefined4 *param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar3 = param_1 + 0x11;
  *param_1 = &PTR_GarageDecalsSlot__scalar_deleting_destructor_006c017c;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int **)(iVar5 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar5 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar5 + 0x18));
  }
  cVar4 = GarageCategoryVisual__IsWidebodyInstalled();
  switch(DAT_00735748) {
  default:
    goto switchD_00510ffa_caseD_0;
  case 2:
    if (cVar4 == '\0') {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf1;
      bStringHash(0x6bc2ecf1,0);
      GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf2;
      bStringHash(0x6bc2ecf2,0);
      GarageDecalsSlot__AddPickable(2,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf3;
      bStringHash(0x6bc2ecf3,0);
      GarageDecalsSlot__AddPickable(3,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf4;
      bStringHash(0x6bc2ecf4,0);
      GarageDecalsSlot__AddPickable(4,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf5;
      bStringHash(0x6bc2ecf5,0);
      GarageDecalsSlot__AddPickable(5,uVar8,uVar10);
      goto switchD_00510ffa_caseD_0;
    }
    iVar5 = GetNumDecalsForCategory(2);
    if (iVar5 < 1) {
      GarageCategoryVisual__MoveBackPackage(param_1);
    }
    else {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      GetNumSlotsForWidebodySituation(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
    }
    if (1 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf1;
      GetNumSlotsForWidebodySituation(0x6bc2ecf1,0);
      GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
    }
    if (2 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf2;
      GetNumSlotsForWidebodySituation(0x6bc2ecf2,0);
      GarageDecalsSlot__AddPickable(2,uVar8,uVar10);
    }
    if (3 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf3;
      GetNumSlotsForWidebodySituation(0x6bc2ecf3,0);
      GarageDecalsSlot__AddPickable(3,uVar8,uVar10);
    }
    if (4 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf4;
      GetNumSlotsForWidebodySituation(0x6bc2ecf4,0);
      GarageDecalsSlot__AddPickable(4,uVar8,uVar10);
    }
    if (iVar5 < 6) goto switchD_00510ffa_caseD_0;
    uVar9 = 0;
    uVar10 = 0x6bc2ecf5;
    GetNumSlotsForWidebodySituation(0x6bc2ecf5,0);
    uVar8 = 5;
    break;
  case 3:
    if (cVar4 == '\0') {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf1;
      bStringHash(0x6bc2ecf1,0);
      GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf2;
      bStringHash(0x6bc2ecf2,0);
      GarageDecalsSlot__AddPickable(2,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf3;
      bStringHash(0x6bc2ecf3,0);
      GarageDecalsSlot__AddPickable(3,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf4;
      bStringHash(0x6bc2ecf4,0);
      GarageDecalsSlot__AddPickable(4,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf5;
      bStringHash(0x6bc2ecf5,0);
      GarageDecalsSlot__AddPickable(5,uVar8,uVar10);
      goto switchD_00510ffa_caseD_0;
    }
    iVar5 = GetNumDecalsForCategory(3);
    if (iVar5 < 1) {
      GarageCategoryVisual__MoveBackPackage(param_1);
    }
    else {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      GetNumSlotsForWidebodySituation(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
    }
    if (1 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf1;
      GetNumSlotsForWidebodySituation(0x6bc2ecf1,0);
      GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
    }
    if (2 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf2;
      GetNumSlotsForWidebodySituation(0x6bc2ecf2,0);
      GarageDecalsSlot__AddPickable(2,uVar8,uVar10);
    }
    if (3 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf3;
      GetNumSlotsForWidebodySituation(0x6bc2ecf3,0);
      GarageDecalsSlot__AddPickable(3,uVar8,uVar10);
    }
    if (4 < iVar5) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf4;
      GetNumSlotsForWidebodySituation(0x6bc2ecf4,0);
      GarageDecalsSlot__AddPickable(4,uVar8,uVar10);
    }
    if (iVar5 < 6) goto switchD_00510ffa_caseD_0;
    uVar9 = 0;
    uVar10 = 0x6bc2ecf5;
    GetNumSlotsForWidebodySituation(0x6bc2ecf5,0);
    uVar8 = 5;
    break;
  case 4:
    if (cVar4 == '\0') {
      if (DAT_0073574c == 0) {
        uVar10 = 0;
        uVar8 = 0x6bc2ecf0;
        bStringHash(0x6bc2ecf0,0);
        GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
        goto switchD_00510ffa_caseD_0;
      }
      if (DAT_0073574c != 1) goto switchD_00510ffa_caseD_0;
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
      goto LAB_005115d2;
    }
    iVar5 = GetNumDecalsForCategory(4);
    if (iVar5 < 1) {
      GarageCategoryVisual__MoveBackPackage(param_1);
    }
    else {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
    }
    if (iVar5 < 2) goto switchD_00510ffa_caseD_0;
    uVar9 = 0;
    uVar10 = 0x6bc2ecf1;
    bStringHash(0x6bc2ecf1,0);
    uVar8 = 1;
    break;
  case 5:
    if (cVar4 == '\0') {
      if (DAT_0073574c == 0) {
        uVar10 = 0;
        uVar8 = 0x6bc2ecf0;
        bStringHash(0x6bc2ecf0,0);
        GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
        goto switchD_00510ffa_caseD_0;
      }
      if (DAT_0073574c != 1) goto switchD_00510ffa_caseD_0;
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
    }
    else {
      piVar6 = &DAT_00706530;
      do {
        if (*piVar6 == 0xc) break;
        piVar6 = piVar6 + 7;
      } while ((int)piVar6 < 0x70669c);
      iVar5 = FECarConfig__GetCarType();
      pcVar7 = (char *)(iVar5 * 0xc90 + DAT_00734588);
      if (pcVar7 == (char *)0x0) {
        param_2 = 0xffffffff;
        GarageCategoryVisual__MoveBackPackage(param_1);
      }
      else {
        cVar2 = *pcVar7;
        while (cVar2 != '\0') {
          pcVar1 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
          cVar2 = *pcVar1;
        }
        param_2 = FUN_0051be40(cVar4 == '\x01');
        param_2 = param_2 & 0xff;
        if (param_2 == 0) {
          GarageCategoryVisual__MoveBackPackage(param_1);
        }
        else {
          uVar10 = 0;
          uVar8 = 0x6bc2ecf0;
          bStringHash(0x6bc2ecf0,0);
          GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
        }
      }
      if ((int)param_2 < 2) goto switchD_00510ffa_caseD_0;
    }
LAB_005115d2:
    uVar10 = 0;
    uVar8 = 0x6bc2ecf1;
    bStringHash(0x6bc2ecf1,0);
    GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
    goto switchD_00510ffa_caseD_0;
  case 6:
    if (DAT_0073574c == 0) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf1;
      bStringHash(0x6bc2ecf1,0);
      GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf2;
      bStringHash(0x6bc2ecf2,0);
      GarageDecalsSlot__AddPickable(2,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf3;
      bStringHash(0x6bc2ecf3,0);
      GarageDecalsSlot__AddPickable(3,uVar8,uVar10);
    }
    else if (DAT_0073574c == 1) {
      uVar10 = 0;
      uVar8 = 0x6bc2ecf0;
      bStringHash(0x6bc2ecf0,0);
      GarageDecalsSlot__AddPickable(0,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf1;
      bStringHash(0x6bc2ecf1,0);
      GarageDecalsSlot__AddPickable(1,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf2;
      bStringHash(0x6bc2ecf2,0);
      GarageDecalsSlot__AddPickable(2,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf3;
      bStringHash(0x6bc2ecf3,0);
      GarageDecalsSlot__AddPickable(3,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf4;
      bStringHash(0x6bc2ecf4,0);
      GarageDecalsSlot__AddPickable(4,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf5;
      bStringHash(0x6bc2ecf5,0);
      GarageDecalsSlot__AddPickable(5,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf6;
      bStringHash(0x6bc2ecf6,0);
      GarageDecalsSlot__AddPickable(6,uVar8,uVar10);
      uVar10 = 0;
      uVar8 = 0x6bc2ecf7;
      bStringHash(0x6bc2ecf7,0);
      GarageDecalsSlot__AddPickable(7,uVar8,uVar10);
    }
    goto switchD_00510ffa_caseD_0;
  }
  GarageDecalsSlot__AddPickable(uVar8,uVar10,uVar9);
switchD_00510ffa_caseD_0:
  puVar3 = (undefined4 *)param_1[0x11];
  do {
    if (puVar3 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_00511165:
      FUN_004f8960();
      GarageDecalsSlot__RedrawHeading();
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar3[2] == DAT_00735750) {
      param_1[0x10] = puVar3;
      goto LAB_00511165;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


