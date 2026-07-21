// SmoothMeshShape (render) — cube. 32 functions. Bodies = Ghidra pseudo-C.
#include "SmoothMeshShape.h"

/* [AUDIT] proposed: math::mat3_transform_point2d  (confidence: med)
 * purpose: 2D projective transform of point by 3x3-ish matrix (game math)
 * vars: in_ECX=matrix;param_2=pt
 */
/* Global::math_mat3_transform_point2d @ 00411be0 */

float * math_mat3_transform_point2d(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *in_ECX;
  float fVar6;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = in_ECX[1];
  fVar6 = 1.0 / (in_ECX[3] * fVar1 + in_ECX[7] * fVar2 + in_ECX[0xf]);
  fVar4 = in_ECX[5];
  fVar5 = in_ECX[0xd];
  *param_1 = fVar6 * (in_ECX[4] * fVar2 + fVar1 * *in_ECX + in_ECX[0xc]);
  param_1[1] = fVar6 * (fVar3 * fVar1 + fVar4 * fVar2 + fVar5);
  return param_1;
}




/* [AUDIT] proposed: vectorReserve8  (confidence: high)
 * purpose: std::vector reallocate to param_1 capacity, 8-byte elements: new/copy/free
 * vars: stride 8; copyVec2Array=copy
 */
/* Global::vectorReserve8 @ 00428ac0 */

void vectorReserve8(uint param_1)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *pvVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1f20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar3 = (void *)0x0;
  if (param_1 != 0) {
    if (param_1 < 0x20000000) {
      pvVar3 = operator_new(param_1 * 8);
      if (pvVar3 != (void *)0x0) goto LAB_00428b20;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_00428b20:
  local_8 = 0;
  copyVec2Array(*in_ECX,in_ECX[1],pvVar3,(int)&param_1 + 3,0,param_1);
  pvVar1 = (void *)*in_ECX;
  param_1 = in_ECX[1] - (int)pvVar1 >> 3;
  if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  in_ECX[2] = (void *)((int)pvVar3 + uVar2 * 8);
  *in_ECX = pvVar3;
  in_ECX[1] = (void *)((int)pvVar3 + param_1 * 8);
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: vectorReserve16  (confidence: high)
 * purpose: std::vector reallocate to param_1 capacity, 16-byte elements: new/copy/free
 * vars: stride 16; copyVec4Array2=copy
 */
/* Global::vectorReserve16 @ 00428ba0 */

void vectorReserve16(uint param_1)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *pvVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1f40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar3 = (void *)0x0;
  if (param_1 != 0) {
    if (param_1 < 0x10000000) {
      pvVar3 = operator_new(param_1 << 4);
      if (pvVar3 != (void *)0x0) goto LAB_00428c01;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_00428c01:
  local_8 = 0;
  copyVec4Array2(*in_ECX,in_ECX[1],pvVar3,(int)&param_1 + 3,0,param_1);
  pvVar1 = (void *)*in_ECX;
  if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  in_ECX[2] = (void *)(uVar2 * 0x10 + (int)pvVar3);
  in_ECX[1] = (in_ECX[1] - (int)pvVar1 & 0xfffffff0U) + (int)pvVar3;
  *in_ECX = pvVar3;
  ExceptionList = local_10;
  return;
}




/* Global::FUN_0062de10 @ 0062de10 */

void FUN_0062de10(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x2d) = param_1;
  return;
}




/* Global::FUN_0063a980 @ 0063a980 */

void FUN_0063a980(int *param_1,int *param_2,uint param_3,int param_4,char param_5,float param_6,
                 int param_7)

{
  float *pfVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  int local_18;
  uint local_8;
  
  if (0 < param_4) {
    local_8 = 0;
    local_18 = param_4;
    uVar7 = param_3;
    fVar12 = DAT_0076de94;
    do {
      fVar11 = 0.5;
      uVar5 = ((int)param_3 / 2 - param_3) + uVar7;
      iVar4 = *param_1;
      uVar8 = param_1[1] - iVar4 >> 2;
      *(float *)(iVar4 + (uVar5 % uVar8) * 4) =
           (*(float *)(iVar4 + (uVar7 % uVar8) * 4) + *(float *)(iVar4 + (local_8 % uVar8) * 4)) *
           0.5;
      if (param_7 == 0) {
        if ((DAT_0076de98 & 1) == 0) {
          dVar10 = 0.7853981852531433;
          DAT_0076de98 = DAT_0076de98 | 1;
          libm_sse2_cos_precise();
          fVar12 = 1.0 / ((float)dVar10 * 2.0 + 1.0);
          DAT_0076de94 = fVar12;
        }
        iVar4 = *param_2;
        uVar6 = param_2[1] - iVar4 >> 2;
        uVar8 = *(uint *)(iVar4 + (local_8 % uVar6) * 4);
        uVar9 = uVar8 & 0xffff;
        fVar11 = 0.5;
        if ((uVar9 == 3) && (*(short *)(iVar4 + (uVar7 % uVar6) * 4) != (short)uVar8)) {
          fVar11 = fVar12;
        }
        if ((*(short *)(iVar4 + (uVar7 % uVar6) * 4) == 3) && (uVar9 != 3)) {
          fVar11 = 1.0 - fVar12;
        }
      }
      iVar4 = *param_1;
      uVar8 = param_1[1] - iVar4 >> 2;
      *(float *)(iVar4 + (uVar5 % uVar8) * 4) =
           (1.0 - fVar11) * *(float *)(iVar4 + (uVar7 % uVar8) * 4) +
           *(float *)(iVar4 + (local_8 % uVar8) * 4) * fVar11;
      uVar6 = param_2[1] - *param_2 >> 2;
      uVar8 = *(uint *)(*param_2 + (local_8 % uVar6) * 4) & 0xffff;
      if (((uVar8 == 2) || (uVar9 = *(uint *)(*param_2 + (uVar7 % uVar6) * 4) & 0xffff, uVar9 == 2))
         || ((param_7 == 0 && ((uVar8 == 3 || (uVar9 == 3)))))) {
        *(undefined4 *)(*param_2 + (uVar5 % uVar6) * 4) = 2;
      }
      else {
        *(undefined4 *)(*param_2 + (uVar5 % uVar6) * 4) = 0;
      }
      local_8 = local_8 + param_3;
      uVar7 = uVar7 + param_3;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  if (param_5 != '\0') {
    param_4 = param_4 + 1;
  }
  if (1 < param_4) {
    local_18 = param_4 + -1;
    uVar7 = param_3;
    do {
      sVar2 = *(short *)(*param_2 + (uVar7 % (uint)(param_2[1] - *param_2 >> 2)) * 4);
      if (sVar2 != 1) {
        if (sVar2 == 3) {
          if (param_7 == 0) {
LAB_0063abde:
            iVar4 = *param_1;
            uVar5 = param_1[1] - iVar4 >> 2;
            *(float *)(iVar4 + (uVar7 % uVar5) * 4) =
                 (*(float *)(iVar4 + ((uVar7 - (int)param_3 / 2) % uVar5) * 4) +
                 *(float *)(iVar4 + ((uVar7 + (int)param_3 / 2) % uVar5) * 4)) * 0.5;
          }
        }
        else {
          if (sVar2 != 0) goto LAB_0063abde;
          uVar5 = param_1[1] - *param_1 >> 2;
          pfVar1 = (float *)(*param_1 + (uVar7 % uVar5) * 4);
          *pfVar1 = ((*(float *)(*param_1 + ((uVar7 - (int)param_3 / 2) % uVar5) * 4) +
                     *(float *)(*param_1 + ((uVar7 + (int)param_3 / 2) % uVar5) * 4)) * 0.5 -
                    *pfVar1) * param_6 + *pfVar1;
        }
      }
      uVar7 = uVar7 + param_3;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  if (0 < param_4) {
    _param_5 = 0;
    do {
      iVar4 = *param_2;
      uVar5 = param_2[1] - iVar4 >> 2;
      sVar2 = *(short *)(iVar4 + (_param_5 % uVar5) * 4);
      uVar7 = _param_5 + param_3;
      sVar3 = *(short *)(iVar4 + (uVar7 % uVar5) * 4);
      if (((sVar2 == 2) || ((param_7 == 0 && (sVar2 == 3)))) &&
         ((sVar3 == 2 || ((param_7 == 0 && (sVar3 == 3)))))) {
        iVar4 = *param_1;
        uVar8 = _param_5 + (int)param_3 / 2;
        uVar5 = param_1[1] - iVar4 >> 2;
        *(float *)(iVar4 + (uVar8 % uVar5) * 4) =
             (*(float *)(iVar4 + (uVar7 % uVar5) * 4) + *(float *)(iVar4 + (_param_5 % uVar5) * 4))
             * 0.5;
        *(undefined4 *)(*param_2 + (uVar8 % (uint)(param_2[1] - *param_2 >> 2)) * 4) = 1;
      }
      param_4 = param_4 + -1;
      _param_5 = uVar7;
    } while (param_4 != 0);
  }
  return;
}




/* Global::FUN_0063ad70 @ 0063ad70 */

void FUN_0063ad70(int *param_1,int *param_2,uint param_3,int param_4,char param_5,float param_6,
                 int param_7)

{
  float *pfVar1;
  float *pfVar2;
  undefined8 uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  double dVar13;
  float fVar14;
  float fVar15;
  int local_40;
  uint local_3c;
  float local_38;
  float fStack_34;
  undefined8 local_30;
  float local_28;
  float fStack_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar7 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (0 < param_4) {
    iVar8 = (int)param_3 / 2 - param_3;
    local_3c = 0;
    local_40 = param_4;
    uVar10 = param_3;
    fVar14 = DAT_0076de84;
    do {
      fVar15 = 0.5;
      iVar6 = *param_1;
      uVar11 = param_1[1] - iVar6 >> 3;
      pfVar1 = (float *)(iVar6 + (uVar10 % uVar11) * 8);
      uVar3 = *(undefined8 *)(iVar6 + (local_3c % uVar11) * 8);
      local_28 = (float)uVar3;
      fStack_24 = (float)((ulonglong)uVar3 >> 0x20);
      local_30 = CONCAT44((pfVar1[1] + fStack_24) * 0.5,(*pfVar1 + local_28) * 0.5);
      *(undefined8 *)(iVar6 + ((iVar8 + uVar10) % uVar11) * 8) = local_30;
      if (param_7 == 0) {
        if ((DAT_0076de88 & 1) == 0) {
          dVar13 = 0.7853981852531433;
          DAT_0076de88 = DAT_0076de88 | 1;
          libm_sse2_cos_precise();
          fVar14 = 1.0 / ((float)dVar13 * 2.0 + 1.0);
          DAT_0076de84 = fVar14;
        }
        uVar9 = param_2[1] - *param_2 >> 2;
        uVar11 = *(uint *)(*param_2 + (local_3c % uVar9) * 4);
        uVar12 = uVar11 & 0xffff;
        fVar15 = 0.5;
        if ((uVar12 == 3) && (*(short *)(*param_2 + (uVar10 % uVar9) * 4) != (short)uVar11)) {
          fVar15 = fVar14;
        }
        if ((*(short *)(*param_2 + (uVar10 % uVar9) * 4) == 3) && (uVar12 != 3)) {
          fVar15 = 1.0 - fVar14;
        }
      }
      iVar6 = *param_1;
      uVar11 = param_1[1] - iVar6 >> 3;
      uVar3 = *(undefined8 *)(iVar6 + (uVar10 % uVar11) * 8);
      local_38 = (float)uVar3;
      fStack_34 = (float)((ulonglong)uVar3 >> 0x20);
      uVar3 = *(undefined8 *)(iVar6 + (local_3c % uVar11) * 8);
      local_10._0_4_ = (float)uVar3;
      local_10._4_4_ = (float)((ulonglong)uVar3 >> 0x20);
      local_18 = CONCAT44(local_10._4_4_ * fVar15 + (1.0 - fVar15) * fStack_34,
                          (float)local_10 * fVar15 + (1.0 - fVar15) * local_38);
      *(undefined8 *)(iVar6 + ((iVar8 + uVar10) % uVar11) * 8) = local_18;
      uVar9 = param_2[1] - *param_2 >> 2;
      uVar11 = *(uint *)(*param_2 + (local_3c % uVar9) * 4) & 0xffff;
      if (((uVar11 == 2) ||
          (uVar12 = *(uint *)(*param_2 + (uVar10 % uVar9) * 4) & 0xffff, uVar12 == 2)) ||
         ((param_7 == 0 && ((uVar11 == 3 || (uVar12 == 3)))))) {
        *(undefined4 *)(*param_2 + ((iVar8 + uVar10) % uVar9) * 4) = 2;
      }
      else {
        *(undefined4 *)(*param_2 + ((iVar8 + uVar10) % uVar9) * 4) = 0;
      }
      local_3c = local_3c + param_3;
      uVar10 = uVar10 + param_3;
      local_40 = local_40 + -1;
    } while (local_40 != 0);
  }
  if (param_5 != '\0') {
    param_4 = param_4 + 1;
  }
  if (1 < param_4) {
    local_40 = param_4 + -1;
    uVar10 = param_3;
    do {
      sVar4 = *(short *)(*param_2 + (uVar10 % (uint)(param_2[1] - *param_2 >> 2)) * 4);
      if (sVar4 != 1) {
        if (sVar4 == 3) {
          if (param_7 == 0) {
LAB_0063b084:
            iVar8 = *param_1;
            uVar11 = param_1[1] - iVar8 >> 3;
            pfVar1 = (float *)(iVar8 + ((uVar10 + (int)param_3 / 2) % uVar11) * 8);
            uVar3 = *(undefined8 *)(iVar8 + ((uVar10 - (int)param_3 / 2) % uVar11) * 8);
            local_28 = (float)uVar3;
            fStack_24 = (float)((ulonglong)uVar3 >> 0x20);
            local_20 = CONCAT44((pfVar1[1] + fStack_24) * 0.5,(*pfVar1 + local_28) * 0.5);
            *(undefined8 *)(iVar8 + (uVar10 % uVar11) * 8) = local_20;
          }
        }
        else {
          if (sVar4 != 0) goto LAB_0063b084;
          iVar8 = *param_1;
          uVar11 = param_1[1] - iVar8 >> 3;
          pfVar1 = (float *)(iVar8 + (uVar10 % uVar11) * 8);
          pfVar2 = (float *)(iVar8 + ((uVar10 + (int)param_3 / 2) % uVar11) * 8);
          uVar3 = *(undefined8 *)(iVar8 + ((uVar10 - (int)param_3 / 2) % uVar11) * 8);
          local_18._0_4_ = (float)uVar3;
          local_18._4_4_ = (float)((ulonglong)uVar3 >> 0x20);
          fVar14 = pfVar2[1];
          *pfVar1 = *pfVar1 + ((*pfVar2 + (float)local_18) * 0.5 - *pfVar1) * param_6;
          pfVar1[1] = ((fVar14 + local_18._4_4_) * 0.5 - pfVar1[1]) * param_6 + pfVar1[1];
        }
      }
      uVar10 = uVar10 + param_3;
      local_40 = local_40 + -1;
    } while (local_40 != 0);
  }
  if (0 < param_4) {
    uVar10 = 0;
    do {
      iVar8 = *param_2;
      uVar9 = param_2[1] - iVar8 >> 2;
      sVar4 = *(short *)(iVar8 + (uVar10 % uVar9) * 4);
      uVar11 = uVar10 + param_3;
      sVar5 = *(short *)(iVar8 + (uVar11 % uVar9) * 4);
      if (((sVar4 == 2) || ((param_7 == 0 && (sVar4 == 3)))) &&
         ((sVar5 == 2 || ((param_7 == 0 && (sVar5 == 3)))))) {
        iVar8 = *param_1;
        uVar9 = param_1[1] - iVar8 >> 3;
        pfVar1 = (float *)(iVar8 + (uVar11 % uVar9) * 8);
        uVar3 = *(undefined8 *)(iVar8 + (uVar10 % uVar9) * 8);
        local_18._0_4_ = (float)uVar3;
        local_18._4_4_ = (float)((ulonglong)uVar3 >> 0x20);
        uVar10 = uVar10 + (int)param_3 / 2;
        local_10 = CONCAT44((pfVar1[1] + local_18._4_4_) * 0.5,(*pfVar1 + (float)local_18) * 0.5);
        *(undefined8 *)(iVar8 + (uVar10 % uVar9) * 8) = local_10;
        *(undefined4 *)(*param_2 + (uVar10 % (uint)(param_2[1] - *param_2 >> 2)) * 4) = 1;
      }
      param_4 = param_4 + -1;
      uVar10 = uVar11;
    } while (param_4 != 0);
  }
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_0063b360 @ 0063b360 */

void FUN_0063b360(int *param_1,int *param_2,uint param_3,int param_4,char param_5,float param_6,
                 int param_7)

{
  undefined8 uVar1;
  undefined8 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  float *pfVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  float fVar13;
  double dVar14;
  float fVar15;
  float fVar16;
  int local_78;
  int local_74;
  uint local_70;
  undefined8 local_58;
  undefined8 local_50;
  float local_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float local_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar6 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (0 < param_4) {
    local_70 = 0;
    local_74 = param_4;
    uVar10 = param_3;
    fVar15 = DAT_0076de8c;
    do {
      iVar5 = *param_1;
      uVar11 = param_1[1] - iVar5 >> 4;
      fVar16 = 0.5;
      uVar7 = uVar10 + ((int)param_3 / 2 - param_3);
      pfVar8 = (float *)((uVar10 % uVar11) * 0x10 + iVar5);
      uVar1 = *(undefined8 *)(iVar5 + (local_70 % uVar11) * 0x10);
      uVar2 = *(undefined8 *)(iVar5 + 8 + (local_70 % uVar11) * 0x10);
      local_38 = (float)uVar1;
      fStack_34 = (float)((ulonglong)uVar1 >> 0x20);
      local_30 = (float)uVar2;
      fStack_2c = (float)((ulonglong)uVar2 >> 0x20);
      local_58 = CONCAT44((pfVar8[1] + fStack_34) * 0.5,(*pfVar8 + local_38) * 0.5);
      local_50 = CONCAT44((pfVar8[3] + fStack_2c) * 0.5,(pfVar8[2] + local_30) * 0.5);
      *(undefined8 *)(iVar5 + (uVar7 % uVar11) * 0x10) = local_58;
      *(undefined8 *)(iVar5 + 8 + (uVar7 % uVar11) * 0x10) = local_50;
      if (param_7 == 0) {
        if ((DAT_0076de90 & 1) == 0) {
          dVar14 = 0.7853981852531433;
          DAT_0076de90 = DAT_0076de90 | 1;
          libm_sse2_cos_precise();
          fVar15 = 1.0 / ((float)dVar14 * 2.0 + 1.0);
          DAT_0076de8c = fVar15;
        }
        iVar5 = *param_2;
        uVar9 = param_2[1] - iVar5 >> 2;
        uVar11 = *(uint *)(iVar5 + (local_70 % uVar9) * 4);
        uVar12 = uVar11 & 0xffff;
        fVar16 = 0.5;
        if ((uVar12 == 3) && (*(short *)(iVar5 + (uVar10 % uVar9) * 4) != (short)uVar11)) {
          fVar16 = fVar15;
        }
        if ((*(short *)(iVar5 + (uVar10 % uVar9) * 4) == 3) && (uVar12 != 3)) {
          fVar16 = 1.0 - fVar15;
        }
      }
      iVar5 = *param_1;
      uVar11 = param_1[1] - iVar5 >> 4;
      uVar1 = *(undefined8 *)(iVar5 + (uVar10 % uVar11) * 0x10);
      uVar2 = *(undefined8 *)(iVar5 + 8 + (uVar10 % uVar11) * 0x10);
      local_28._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
      local_20._0_4_ = (float)uVar2;
      local_20._4_4_ = (float)((ulonglong)uVar2 >> 0x20);
      local_28._0_4_ = (float)uVar1;
      fVar13 = 1.0 - fVar16;
      uVar1 = *(undefined8 *)(iVar5 + (local_70 % uVar11) * 0x10);
      uVar2 = *(undefined8 *)(iVar5 + 8 + (local_70 % uVar11) * 0x10);
      local_48 = (float)uVar1;
      fStack_44 = (float)((ulonglong)uVar1 >> 0x20);
      local_40 = (float)uVar2;
      fStack_3c = (float)((ulonglong)uVar2 >> 0x20);
      local_18 = CONCAT44(fStack_44 * fVar16 + local_28._4_4_ * fVar13,
                          local_48 * fVar16 + (float)local_28 * fVar13);
      local_10 = CONCAT44(fStack_3c * fVar16 + local_20._4_4_ * fVar13,
                          local_40 * fVar16 + (float)local_20 * fVar13);
      *(undefined8 *)(iVar5 + (uVar7 % uVar11) * 0x10) = local_18;
      *(undefined8 *)(iVar5 + 8 + (uVar7 % uVar11) * 0x10) = local_10;
      uVar9 = param_2[1] - *param_2 >> 2;
      uVar11 = *(uint *)(*param_2 + (local_70 % uVar9) * 4) & 0xffff;
      if (((uVar11 == 2) ||
          (uVar12 = *(uint *)(*param_2 + (uVar10 % uVar9) * 4) & 0xffff, uVar12 == 2)) ||
         ((param_7 == 0 && ((uVar11 == 3 || (uVar12 == 3)))))) {
        *(undefined4 *)(*param_2 + (uVar7 % uVar9) * 4) = 2;
      }
      else {
        *(undefined4 *)(*param_2 + (uVar7 % uVar9) * 4) = 0;
      }
      local_70 = local_70 + param_3;
      uVar10 = uVar10 + param_3;
      local_74 = local_74 + -1;
    } while (local_74 != 0);
  }
  if (param_5 != '\0') {
    param_4 = param_4 + 1;
  }
  if (1 < param_4) {
    local_78 = param_4 + -1;
    uVar10 = param_3;
    do {
      sVar3 = *(short *)(*param_2 + (uVar10 % (uint)(param_2[1] - *param_2 >> 2)) * 4);
      if (sVar3 != 1) {
        if (sVar3 == 3) {
          if (param_7 == 0) {
LAB_0063b762:
            iVar5 = *param_1;
            uVar11 = param_1[1] - iVar5 >> 4;
            uVar7 = (uVar10 - (int)param_3 / 2) % uVar11;
            pfVar8 = (float *)(((uVar10 + (int)param_3 / 2) % uVar11) * 0x10 + iVar5);
            uVar1 = *(undefined8 *)(iVar5 + uVar7 * 0x10);
            uVar2 = *(undefined8 *)(iVar5 + 8 + uVar7 * 0x10);
            local_38 = (float)uVar1;
            fStack_34 = (float)((ulonglong)uVar1 >> 0x20);
            local_30 = (float)uVar2;
            fStack_2c = (float)((ulonglong)uVar2 >> 0x20);
            local_28 = CONCAT44((pfVar8[1] + fStack_34) * 0.5,(local_38 + *pfVar8) * 0.5);
            local_20 = CONCAT44((pfVar8[3] + fStack_2c) * 0.5,(pfVar8[2] + local_30) * 0.5);
            *(undefined8 *)(iVar5 + (uVar10 % uVar11) * 0x10) = local_28;
            *(undefined8 *)(iVar5 + 8 + (uVar10 % uVar11) * 0x10) = local_20;
          }
        }
        else {
          if (sVar3 != 0) goto LAB_0063b762;
          iVar5 = *param_1;
          uVar9 = param_1[1] - iVar5 >> 4;
          uVar7 = uVar10 % uVar9;
          uVar11 = (uVar10 - (int)param_3 / 2) % uVar9;
          pfVar8 = (float *)(((uVar10 + (int)param_3 / 2) % uVar9) * 0x10 + iVar5);
          uVar1 = *(undefined8 *)(iVar5 + uVar11 * 0x10);
          uVar2 = *(undefined8 *)(iVar5 + 8 + uVar11 * 0x10);
          local_18._0_4_ = (float)uVar1;
          local_18._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
          fVar15 = pfVar8[1];
          fVar16 = pfVar8[2];
          local_10._0_4_ = (float)uVar2;
          local_10._4_4_ = (float)((ulonglong)uVar2 >> 0x20);
          fVar13 = pfVar8[3];
          *(float *)(iVar5 + uVar7 * 0x10) =
               (((float)local_18 + *pfVar8) * 0.5 - *(float *)(iVar5 + uVar7 * 0x10)) * param_6 +
               *(float *)(iVar5 + uVar7 * 0x10);
          *(float *)(iVar5 + 4 + uVar7 * 0x10) =
               ((fVar15 + local_18._4_4_) * 0.5 - *(float *)(iVar5 + 4 + uVar7 * 0x10)) * param_6 +
               *(float *)(iVar5 + 4 + uVar7 * 0x10);
          *(float *)(iVar5 + 8 + uVar7 * 0x10) =
               ((fVar16 + (float)local_10) * 0.5 - *(float *)(iVar5 + 8 + uVar7 * 0x10)) * param_6 +
               *(float *)(iVar5 + 8 + uVar7 * 0x10);
          *(float *)(iVar5 + 0xc + uVar7 * 0x10) =
               ((fVar13 + local_10._4_4_) * 0.5 - *(float *)(iVar5 + 0xc + uVar7 * 0x10)) * param_6
               + *(float *)(iVar5 + 0xc + uVar7 * 0x10);
        }
      }
      uVar10 = uVar10 + param_3;
      local_78 = local_78 + -1;
    } while (local_78 != 0);
  }
  if (0 < param_4) {
    local_70 = 0;
    do {
      iVar5 = *param_2;
      uVar7 = param_2[1] - iVar5 >> 2;
      sVar3 = *(short *)(iVar5 + (local_70 % uVar7) * 4);
      uVar10 = local_70 + param_3;
      sVar4 = *(short *)(iVar5 + (uVar10 % uVar7) * 4);
      if (((sVar3 == 2) || ((param_7 == 0 && (sVar3 == 3)))) &&
         ((sVar4 == 2 || ((param_7 == 0 && (sVar4 == 3)))))) {
        iVar5 = *param_1;
        uVar7 = param_1[1] - iVar5 >> 4;
        pfVar8 = (float *)((uVar10 % uVar7) * 0x10 + iVar5);
        uVar1 = *(undefined8 *)(iVar5 + (local_70 % uVar7) * 0x10);
        uVar2 = *(undefined8 *)(iVar5 + 8 + (local_70 % uVar7) * 0x10);
        local_28._0_4_ = (float)uVar1;
        local_28._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
        local_70 = local_70 + (int)param_3 / 2;
        uVar7 = local_70 % uVar7;
        local_20._0_4_ = (float)uVar2;
        local_20._4_4_ = (float)((ulonglong)uVar2 >> 0x20);
        local_18 = CONCAT44((pfVar8[1] + local_28._4_4_) * 0.5,(*pfVar8 + (float)local_28) * 0.5);
        local_10 = CONCAT44((pfVar8[3] + local_20._4_4_) * 0.5,(pfVar8[2] + (float)local_20) * 0.5);
        *(undefined8 *)(iVar5 + uVar7 * 0x10) = local_18;
        *(undefined8 *)(iVar5 + 8 + uVar7 * 0x10) = local_10;
        *(undefined4 *)(*param_2 + (local_70 % (uint)(param_2[1] - *param_2 >> 2)) * 4) = 1;
      }
      param_4 = param_4 + -1;
      local_70 = uVar10;
    } while (param_4 != 0);
  }
  __security_check_cookie(uVar6 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_0063bba0 @ 0063bba0 */

void FUN_0063bba0(int *param_1,uint param_2,int param_3,char param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float *pfVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint local_54;
  int local_50;
  uint local_4c;
  float local_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float local_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar7 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (0 < param_3) {
    uVar8 = (int)param_2 / 2;
    iVar10 = param_2 - uVar8;
    local_54 = 0;
    local_50 = param_3;
    do {
      iVar6 = *param_1;
      uVar12 = param_1[1] - iVar6 >> 4;
      pfVar9 = (float *)(((uVar8 + iVar10) % uVar12) * 0x10 + iVar6);
      uVar4 = *(undefined8 *)(iVar6 + (local_54 % uVar12) * 0x10);
      uVar5 = *(undefined8 *)(iVar6 + 8 + (local_54 % uVar12) * 0x10);
      local_38 = (float)uVar4;
      uVar12 = uVar8 % uVar12;
      fStack_34 = (float)((ulonglong)uVar4 >> 0x20);
      uVar8 = uVar8 + param_2;
      local_30 = (float)uVar5;
      fStack_2c = (float)((ulonglong)uVar5 >> 0x20);
      local_50 = local_50 + -1;
      local_18 = CONCAT44((pfVar9[1] + fStack_34) * 0.5,(*pfVar9 + local_38) * 0.5);
      local_10 = CONCAT44((pfVar9[3] + fStack_2c) * 0.5,(pfVar9[2] + local_30) * 0.5);
      *(undefined8 *)(iVar6 + uVar12 * 0x10) = local_18;
      *(undefined8 *)(iVar6 + 8 + uVar12 * 0x10) = local_10;
      local_54 = local_54 + param_2;
    } while (local_50 != 0);
  }
  if (param_4 != '\0') {
    param_3 = param_3 + 1;
  }
  if (1 < param_3) {
    local_54 = -((int)param_2 / 2);
    local_50 = param_3 + -1;
    uVar8 = param_2;
    do {
      local_54 = param_2 + local_54;
      iVar10 = *param_1;
      uVar12 = param_1[1] - iVar10 >> 4;
      uVar11 = uVar8 % uVar12;
      pfVar9 = (float *)((((int)param_2 / 2 + uVar8) % uVar12) * 0x10 + iVar10);
      uVar4 = *(undefined8 *)(iVar10 + (local_54 % uVar12) * 0x10);
      uVar5 = *(undefined8 *)(iVar10 + 8 + (local_54 % uVar12) * 0x10);
      local_18._0_4_ = (float)uVar4;
      local_18._4_4_ = (float)((ulonglong)uVar4 >> 0x20);
      fVar1 = pfVar9[1];
      fVar2 = pfVar9[2];
      local_10._0_4_ = (float)uVar5;
      local_10._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
      fVar3 = pfVar9[3];
      *(float *)(iVar10 + uVar11 * 0x10) =
           *(float *)(iVar10 + uVar11 * 0x10) +
           ((*pfVar9 + (float)local_18) * 0.5 - *(float *)(iVar10 + uVar11 * 0x10)) * param_5;
      *(float *)(iVar10 + 4 + uVar11 * 0x10) =
           *(float *)(iVar10 + 4 + uVar11 * 0x10) +
           ((fVar1 + local_18._4_4_) * 0.5 - *(float *)(iVar10 + 4 + uVar11 * 0x10)) * param_5;
      *(float *)(iVar10 + 8 + uVar11 * 0x10) =
           *(float *)(iVar10 + 8 + uVar11 * 0x10) +
           ((fVar2 + (float)local_10) * 0.5 - *(float *)(iVar10 + 8 + uVar11 * 0x10)) * param_5;
      *(float *)(iVar10 + 0xc + uVar11 * 0x10) =
           *(float *)(iVar10 + 0xc + uVar11 * 0x10) +
           ((fVar3 + local_10._4_4_) * 0.5 - *(float *)(iVar10 + 0xc + uVar11 * 0x10)) * param_5;
      uVar8 = uVar8 + param_2;
      local_50 = local_50 + -1;
    } while (local_50 != 0);
  }
  if (0 < param_3) {
    uVar8 = (int)param_2 / 2;
    iVar10 = param_2 - uVar8;
    local_4c = 0;
    do {
      iVar6 = *param_1;
      uVar12 = param_1[1] - iVar6 >> 4;
      pfVar9 = (float *)(((uVar8 + iVar10) % uVar12) * 0x10 + iVar6);
      uVar4 = *(undefined8 *)(iVar6 + (local_4c % uVar12) * 0x10);
      uVar5 = *(undefined8 *)(iVar6 + 8 + (local_4c % uVar12) * 0x10);
      local_28 = (float)uVar4;
      fStack_24 = (float)((ulonglong)uVar4 >> 0x20);
      local_20 = (float)uVar5;
      fStack_1c = (float)((ulonglong)uVar5 >> 0x20);
      uVar12 = uVar8 % uVar12;
      uVar8 = uVar8 + param_2;
      local_18 = CONCAT44((pfVar9[1] + fStack_24) * 0.5,(local_28 + *pfVar9) * 0.5);
      param_3 = param_3 + -1;
      local_10 = CONCAT44((pfVar9[3] + fStack_1c) * 0.5,(pfVar9[2] + local_20) * 0.5);
      *(undefined8 *)(iVar6 + uVar12 * 0x10) = local_18;
      *(undefined8 *)(iVar6 + 8 + uVar12 * 0x10) = local_10;
      local_4c = local_4c + param_2;
    } while (param_3 != 0);
  }
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}




/* plasma::SmoothMeshShape::destroyLevelBuffers @ 0063c700 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::SmoothMeshShape::destroyLevelBuffers.
 * Body fully tears down one 0x60B mesh level: 3x _Internal_clear + buffer-free(63d9c0) + ~_Concurrent_vector(+4/+0x24/+0x44). Registered as per-elem dtor of plasma::SmoothMeshShape+0x239 [6x0x60] via eh_vector_destructor_iterator; not a template.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::SmoothMeshShape::destroyLevelBuffers(void)

{
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_006f5d07;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(undefined4 *)(in_ECX + 0x5c);
  uVar3 = *(undefined4 *)(in_ECX + 0x54);
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_clear
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 0x44),cube::AdaptionWidget::vfunc_6);
  FUN_0063d9c0(uVar1,uVar2,uVar3);
  local_8._0_1_ = 1;
  Concurrency::details::_Concurrent_vector_base_v4::~_Concurrent_vector_base_v4
            ((_Concurrent_vector_base_v4 *)(in_ECX + 0x44));
  uVar1 = *(undefined4 *)(in_ECX + 0x3c);
  uVar3 = *(undefined4 *)(in_ECX + 0x34);
  local_8._0_1_ = 3;
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_clear
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 0x24),cube::AdaptionWidget::vfunc_6);
  FUN_0063d9c0(uVar1,uVar2,uVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  Concurrency::details::_Concurrent_vector_base_v4::~_Concurrent_vector_base_v4
            ((_Concurrent_vector_base_v4 *)(in_ECX + 0x24));
  uVar1 = *(undefined4 *)(in_ECX + 0x1c);
  uVar3 = *(undefined4 *)(in_ECX + 0x14);
  local_8 = 4;
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_clear
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 4),cube::AdaptionWidget::vfunc_6);
  FUN_0063d9c0(uVar1,uVar2,uVar3);
  local_8 = 0xffffffff;
  Concurrency::details::_Concurrent_vector_base_v4::~_Concurrent_vector_base_v4
            ((_Concurrent_vector_base_v4 *)(in_ECX + 4));
  ExceptionList = local_10;
  return;
}




/* Global::FUN_0063d6f0 @ 0063d6f0 */

int FUN_0063d6f0(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of(param_1);
  return (param_1 - (1 << ((byte)uVar1 & 0x1f) & 0xfffffffeU)) * 0x4c +
         *(int *)(*(int *)(in_ECX + 0x1c) + uVar1 * 4);
}




/* Global::FUN_0063d9c0 @ 0063d9c0 */

void FUN_0063d9c0(undefined4 *param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  
  while (param_3 < param_2) {
    pvVar1 = (void *)param_1[param_2 - 1];
    param_2 = param_2 - 1;
    param_1[param_2] = 0;
    if ((void *)0x3f < pvVar1) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  pvVar1 = (void *)*param_1;
  if ((void *)0x3f < pvVar1) {
    while (param_2 != 0) {
      param_2 = param_2 - 1;
      param_1[param_2] = 0;
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  return;
}




/* Global::FUN_0063deb0 @ 0063deb0 */

int FUN_0063deb0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  
  if ((*(char *)(in_ECX + 0xb2c) != '\0') && (2 < *(int *)(in_ECX + 0xb24))) {
    piVar4 = *(int **)(in_ECX + 0x86c);
    iVar3 = (*(int *)(in_ECX + 0x870) - (int)piVar4) / 0xc;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        piVar1 = piVar4 + 1;
        iVar2 = *piVar4;
        piVar4 = piVar4 + 3;
        iVar5 = iVar5 + (*piVar1 - iVar2 >> 2);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    dVar6 = (double)(2560.0 / (float)iVar5);
    libm_sse2_log_precise();
    dVar7 = 4.0;
    libm_sse2_log_precise();
    iVar3 = (int)((float)dVar6 / (float)dVar7) + 1;
    if (iVar3 < *(int *)(in_ECX + 0xb24)) {
      return iVar3;
    }
  }
  return *(int *)(in_ECX + 0xb24);
}




/* plasma::SmoothMeshShape::clear @ 00641660 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::SmoothMeshShape::clear.
 * Clears ~15 member vectors at fixed offsets 0xb34-0xbe8 (12B triples, operator_delete each, end=begin) after 6x sub-reset, resets list@0x8d0, dispatches cube::AdaptionWidget::vfunc_6 to children@0xc10-0xc18. RTTI AVSmoothMeshShape@plasma@@. Engine object method, not generic STL.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::SmoothMeshShape::clear(void)

{
  int *piVar1;
  void *pvVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 6;
  do {
    plasma::SmoothMeshShape::clearLevelBuffers();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(in_ECX + 0xb34) = *(undefined4 *)(in_ECX + 0xb30);
  *(undefined4 *)(in_ECX + 0xb40) = *(undefined4 *)(in_ECX + 0xb3c);
  *(undefined4 *)(in_ECX + 0xb4c) = *(undefined4 *)(in_ECX + 0xb48);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xb54); puVar4 != *(undefined4 **)(in_ECX + 0xb58);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xb58) = *(undefined4 *)(in_ECX + 0xb54);
  *(undefined4 *)(in_ECX + 0xb64) = *(undefined4 *)(in_ECX + 0xb60);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xb6c); puVar4 != *(undefined4 **)(in_ECX + 0xb70);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xb70) = *(undefined4 *)(in_ECX + 0xb6c);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xb78); puVar4 != *(undefined4 **)(in_ECX + 0xb7c);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xb7c) = *(undefined4 *)(in_ECX + 0xb78);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xb84); puVar4 != *(undefined4 **)(in_ECX + 0xb88);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xb88) = *(undefined4 *)(in_ECX + 0xb84);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xb90); puVar4 != *(undefined4 **)(in_ECX + 0xb94);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xb94) = *(undefined4 *)(in_ECX + 0xb90);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xb9c); puVar4 != *(undefined4 **)(in_ECX + 0xba0);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xba0) = *(undefined4 *)(in_ECX + 0xb9c);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xba8); puVar4 != *(undefined4 **)(in_ECX + 0xbac);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xbac) = *(undefined4 *)(in_ECX + 0xba8);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xbb4); puVar4 != *(undefined4 **)(in_ECX + 3000);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 3000) = *(undefined4 *)(in_ECX + 0xbb4);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xbc0); puVar4 != *(undefined4 **)(in_ECX + 0xbc4);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xbc4) = *(undefined4 *)(in_ECX + 0xbc0);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xbcc); puVar4 != *(undefined4 **)(in_ECX + 0xbd0);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xbd0) = *(undefined4 *)(in_ECX + 0xbcc);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xbd8); puVar4 != *(undefined4 **)(in_ECX + 0xbdc);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xbdc) = *(undefined4 *)(in_ECX + 0xbd8);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xbe4); puVar4 != *(undefined4 **)(in_ECX + 0xbe8);
      puVar4 = puVar4 + 3) {
    if ((void *)*puVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar4);
    }
  }
  *(undefined4 *)(in_ECX + 0xbe8) = *(undefined4 *)(in_ECX + 0xbe4);
  piVar1 = (int *)(in_ECX + 0x8d0);
  pvVar2 = *(void **)(*(int *)(in_ECX + 0x8d0) + 4);
  if (*(char *)((int)pvVar2 + 0xd) != '\0') {
    *(int *)(*piVar1 + 4) = *piVar1;
    *(int *)*piVar1 = *piVar1;
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(in_ECX + 0x8d4) = 0;
    if (*(int *)(in_ECX + 0xc10) != 0) {
      cube::AdaptionWidget::vfunc_6();
    }
    if (*(int *)(in_ECX + 0xc14) != 0) {
      cube::AdaptionWidget::vfunc_6();
    }
    if (*(int *)(in_ECX + 0xc18) != 0) {
      cube::AdaptionWidget::vfunc_6();
    }
    return;
  }
  rbtree_destroyRec_simple(*(undefined4 *)((int)pvVar2 + 8));
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}




/* Global::FUN_00641b60 @ 00641b60 */

uint FUN_00641b60(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0x85c) >> 1 & 1;
}




/* Global::FUN_006423f0 @ 006423f0 */

uint FUN_006423f0(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0x85c) & 1;
}




/* Global::FUN_00642400 @ 00642400 */

uint FUN_00642400(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0x85c) >> 4 & 1;
}




/* Global::FUN_00642570 @ 00642570 */

void FUN_00642570(void)

{
  int in_ECX;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xc1c));
  return;
}




/* Global::FUN_00642590 @ 00642590 */

void FUN_00642590(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint *in_ECX;
  int iVar3;
  
  puVar1 = (undefined4 *)in_ECX[1];
  if ((param_1 < puVar1) && ((undefined4 *)*in_ECX <= param_1)) {
    iVar3 = (int)param_1 - (int)*in_ECX >> 3;
    if (puVar1 == (undefined4 *)in_ECX[2]) {
      vectorReserveCheck8(1);
    }
    puVar1 = (undefined4 *)in_ECX[1];
    uVar2 = *in_ECX;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *(undefined4 *)(uVar2 + iVar3 * 8);
      puVar1[1] = *(undefined4 *)(uVar2 + 4 + iVar3 * 8);
      in_ECX[1] = in_ECX[1] + 8;
      return;
    }
  }
  else {
    if (puVar1 == (undefined4 *)in_ECX[2]) {
      vectorReserveCheck8(1);
    }
    puVar1 = (undefined4 *)in_ECX[1];
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
      puVar1[1] = param_1[1];
    }
  }
  in_ECX[1] = in_ECX[1] + 8;
  return;
}




/* Global::FUN_006426d0 @ 006426d0 */

float10 FUN_006426d0(float param_1,float param_2,float param_3)

{
  return (float10)((param_1 * 2.0) / (param_2 + param_3));
}




/* Global::FUN_00642a90 @ 00642a90 */

uint FUN_00642a90(void)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = *(uint *)(in_ECX + 0x18);
  uVar1 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 4));
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  return uVar2;
}




/* Global::FUN_00642ad0 @ 00642ad0 */

void FUN_00642ad0(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  float *pfVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  float *pfVar17;
  int in_ECX;
  int *piVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  int iVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  int local_358;
  int local_354;
  uint local_350;
  int local_34c;
  float local_308;
  float fStack_304;
  float local_300;
  float fStack_2fc;
  float local_2e0;
  float fStack_2dc;
  float local_2d8;
  float fStack_2d4;
  float local_278;
  float fStack_274;
  float local_258;
  float fStack_254;
  float local_248;
  float fStack_244;
  float local_238;
  float fStack_234;
  float local_218;
  float fStack_214;
  float local_210;
  float fStack_20c;
  float local_208;
  float fStack_204;
  float local_200;
  float fStack_1fc;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e0;
  undefined8 local_1d8;
  float local_1d0;
  float fStack_1cc;
  float local_1c8;
  float fStack_1c4;
  float local_1c0;
  float fStack_1bc;
  undefined8 local_1b0;
  undefined8 local_1a8;
  float local_1a0;
  float fStack_19c;
  float local_198;
  float fStack_194;
  float local_190;
  float fStack_18c;
  float local_180;
  float fStack_17c;
  float local_178;
  float fStack_174;
  float local_170;
  float fStack_16c;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  float local_150;
  float fStack_14c;
  float local_148;
  float fStack_144;
  undefined8 local_138;
  undefined8 local_130;
  float local_110;
  float fStack_10c;
  float local_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float local_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float local_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float local_c8;
  float fStack_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  float local_b0;
  float fStack_ac;
  float local_a0;
  float fStack_9c;
  float local_98;
  float fStack_94;
  undefined8 local_88;
  float local_80;
  float fStack_7c;
  float local_78;
  float fStack_74;
  undefined8 local_70;
  float local_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  float local_28;
  float fStack_24;
  int iStack_1c;
  int iStack_14;
  float local_10;
  float fStack_c;
  
  uVar9 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  iVar10 = FUN_0063deb0();
  iVar11 = *(int *)(in_ECX + 0xc10);
  if (iVar11 != 0) {
    if (((iVar10 + -1 < 0) || (*(int *)(in_ECX + 0x86c) == *(int *)(in_ECX + 0x870))) ||
       (*(int *)(in_ECX + 0xb30) == *(int *)(in_ECX + 0xb34))) {
      *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(iVar11 + 4);
      *(undefined4 *)(*(int *)(in_ECX + 0xc10) + 0x20) =
           *(undefined4 *)(*(int *)(in_ECX + 0xc10) + 0x1c);
      *(undefined4 *)(*(int *)(in_ECX + 0xc10) + 0x14) =
           *(undefined4 *)(*(int *)(in_ECX + 0xc10) + 0x10);
      *(undefined4 *)(*(int *)(in_ECX + 0xc10) + 0x38) =
           *(undefined4 *)(*(int *)(in_ECX + 0xc10) + 0x34);
      __security_check_cookie(uVar9 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (((*(byte *)(in_ECX + 0x85c) & 1) == 0) &&
       ((~(byte)(*(uint *)(in_ECX + 0x85c) >> 2) & 1) != 0)) {
      iVar10 = (iVar10 + -1) * 0x60;
      iVar11 = in_ECX + 0x924 + iVar10;
      uVar12 = FUN_00642a90();
      std_vector_resize(uVar12);
      std_vector_resize_42bf80(*(int *)(*(int *)(in_ECX + 0xc10) + 8) - *(int *)(*(int *)(in_ECX + 0xc10) + 4)
                   >> 3);
      std_vector_resize(*(int *)(*(int *)(in_ECX + 0xc10) + 8) - *(int *)(*(int *)(in_ECX + 0xc10) + 4)
                   >> 3);
      iVar10 = in_ECX + 0x8e4 + iVar10;
      iVar13 = FUN_00642a90();
      vectorInt_resize(iVar13 * 6);
      iVar13 = 0;
      if (0 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34) {
        iVar22 = 0;
        do {
          iVar13 = iVar13 + 1;
          *(undefined4 *)(iVar22 + *(int *)(in_ECX + 0xb30)) = 0;
          *(undefined4 *)(iVar22 + 8 + *(int *)(in_ECX + 0xb30)) = 0;
          *(undefined4 *)(iVar22 + 4 + *(int *)(in_ECX + 0xb30)) = 0;
          iVar22 = iVar22 + 0x34;
        } while (iVar13 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34);
      }
      piVar18 = (int *)(*(int *)(in_ECX + 0xc10) + 4);
      local_350 = 0;
      if (0 < (int)(*(int *)(*(int *)(in_ECX + 0xc10) + 8) - *piVar18 & 0xfffffff8U)) {
        local_358 = 0;
        do {
          iVar13 = *piVar18;
          uVar14 = Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of(local_350);
          **(int **)(*(int *)(*(int *)(iVar11 + 0x1c) + uVar14 * 4) +
                    (local_350 - (1 << ((byte)uVar14 & 0x1f) & 0xfffffffeU)) * 4) =
               iVar13 + local_350 * 8;
          iVar13 = *(int *)(*(int *)(in_ECX + 0xc10) + 0x10);
          uVar14 = Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of(local_350);
          *(uint *)(*(int *)(*(int *)(*(int *)(iVar11 + 0x1c) + uVar14 * 4) +
                            (local_350 - (1 << ((byte)uVar14 & 0x1f) & 0xfffffffeU)) * 4) + 8) =
               iVar13 + local_350 * 8;
          iVar22 = *(int *)(*(int *)(in_ECX + 0xc10) + 0x1c) + local_358;
          uVar14 = Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of(local_350);
          local_358 = local_358 + 0x10;
          iVar13 = local_350 - (1 << ((byte)uVar14 & 0x1f) & 0xfffffffeU);
          local_350 = local_350 + 1;
          *(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0x1c) + uVar14 * 4) + iVar13 * 4) + 4) =
               iVar22;
          piVar18 = (int *)(*(int *)(in_ECX + 0xc10) + 4);
        } while ((int)local_350 < *(int *)(*(int *)(in_ECX + 0xc10) + 8) - *piVar18 >> 3);
      }
      uVar14 = *(uint *)(iVar10 + 0x18);
      local_350 = 0;
      uVar15 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                         ((_Concurrent_vector_base_v4 *)(iVar10 + 4));
      if (uVar15 < uVar14) {
        uVar14 = uVar15;
      }
      if (0 < (int)uVar14) {
        iVar11 = 0;
        do {
          uVar15 = Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of(local_350);
          uVar14 = local_350 + 1;
          iVar13 = (local_350 - (1 << ((byte)uVar15 & 0x1f) & 0xfffffffeU)) * 0x7c +
                   *(int *)(*(int *)(iVar10 + 0x1c) + uVar15 * 4);
          *(undefined4 *)(iVar11 + *(int *)(*(int *)(in_ECX + 0xc10) + 0x34)) =
               *(undefined4 *)(iVar13 + 100);
          *(undefined4 *)(iVar11 + 4 + *(int *)(*(int *)(in_ECX + 0xc10) + 0x34)) =
               *(undefined4 *)(iVar13 + 0x68);
          *(undefined4 *)(iVar11 + 8 + *(int *)(*(int *)(in_ECX + 0xc10) + 0x34)) =
               *(undefined4 *)(iVar13 + 0x6c);
          *(undefined4 *)(iVar11 + 0xc + *(int *)(*(int *)(in_ECX + 0xc10) + 0x34)) =
               *(undefined4 *)(iVar13 + 0x6c);
          *(undefined4 *)(iVar11 + 0x10 + *(int *)(*(int *)(in_ECX + 0xc10) + 0x34)) =
               *(undefined4 *)(iVar13 + 0x70);
          *(undefined4 *)(iVar11 + 0x14 + *(int *)(*(int *)(in_ECX + 0xc10) + 0x34)) =
               *(undefined4 *)(iVar13 + 100);
          uVar15 = *(uint *)(iVar10 + 0x18);
          uVar16 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                             ((_Concurrent_vector_base_v4 *)(iVar10 + 4));
          if (uVar16 < uVar15) {
            uVar15 = uVar16;
          }
          iVar11 = iVar11 + 0x18;
          local_350 = uVar14;
        } while ((int)uVar14 < (int)uVar15);
      }
      if (0 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34) {
        iVar10 = 0;
        iVar11 = 0;
        do {
          iVar13 = *(int *)(in_ECX + 0xb30) + iVar10;
          iVar11 = iVar11 + 1;
          *(undefined4 *)(iVar13 + 0xc) = 0;
          *(undefined4 *)(iVar13 + 0x10) = 0;
          *(undefined4 *)(iVar13 + 0x14) = 0;
          *(undefined4 *)(iVar13 + 0x18) = 0;
          *(undefined4 *)(iVar13 + 0x1c) = 0;
          *(undefined4 *)(iVar13 + 0x20) = 0;
          *(undefined4 *)(iVar13 + 0x24) = 0;
          *(undefined4 *)(iVar13 + 0x28) = 0;
          *(undefined4 *)(iVar13 + 0x2c) = 0;
          *(undefined1 *)(iVar13 + 0x30) = 0;
          iVar10 = iVar10 + 0x34;
        } while (iVar11 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34);
      }
      local_354 = 0;
      if (0 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc) {
        local_34c = 0;
        do {
          piVar18 = (int *)(*(int *)(in_ECX + 0x86c) + local_34c);
          iVar10 = 0;
          iVar11 = *piVar18;
          if (0 < (int)(piVar18[1] - iVar11 & 0xfffffffcU)) {
            do {
              if (*(int *)(*(int *)(local_34c + *(int *)(in_ECX + 0xb54)) + iVar10 * 4) < 0) {
                pbVar1 = (byte *)(*(int *)(iVar11 + iVar10 * 4) * 0x34 + 0x30 +
                                 *(int *)(in_ECX + 0xb30));
                *pbVar1 = *pbVar1 | 1;
                pbVar1 = (byte *)(*(int *)(*piVar18 +
                                          ((iVar10 + 1U) % (uint)(piVar18[1] - *piVar18 >> 2)) * 4)
                                  * 0x34 + 0x30 + *(int *)(in_ECX + 0xb30));
                *pbVar1 = *pbVar1 | 1;
              }
              iVar11 = *piVar18;
              iVar10 = iVar10 + 1;
            } while (iVar10 < piVar18[1] - iVar11 >> 2);
          }
          local_354 = local_354 + 1;
          local_34c = local_34c + 0xc;
        } while (local_354 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc);
      }
      local_354 = 0;
      if (0 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34) {
        local_34c = 0;
        local_350 = 0;
        do {
          piVar18 = (int *)(*(int *)(in_ECX + 0xb30) + local_350);
          puVar19 = (undefined4 *)*piVar18;
          if (puVar19 != (undefined4 *)0x0) {
            iVar11 = **(int **)(*(int *)(in_ECX + 0xa8) + param_1 * 4);
            *puVar19 = *(undefined4 *)(iVar11 + local_354 * 8);
            puVar19[1] = *(undefined4 *)(iVar11 + 4 + local_354 * 8);
            puVar19 = (undefined4 *)piVar18[1];
            puVar21 = (undefined4 *)(**(int **)(*(int *)(in_ECX + 0x158) + param_2 * 4) + local_34c)
            ;
            *puVar19 = *puVar21;
            puVar19[1] = puVar21[1];
            puVar19[2] = puVar21[2];
            puVar19[3] = puVar21[3];
            puVar19 = (undefined4 *)piVar18[2];
            iVar11 = **(int **)(*(int *)(in_ECX + 0x100) + param_3 * 4);
            *puVar19 = *(undefined4 *)(iVar11 + local_354 * 8);
            puVar19[1] = *(undefined4 *)(iVar11 + 4 + local_354 * 8);
            if (local_354 < *(int *)(in_ECX + 0x2c8) - *(int *)(in_ECX + 0x2c4) >> 2) {
              if (*(short *)(*(int *)(in_ECX + 0x2c4) + local_354 * 4) == 1) {
                *(byte *)(piVar18 + 0xc) = *(byte *)(piVar18 + 0xc) | 2;
              }
              if (*(short *)(*(int *)(in_ECX + 0x2c4) + local_354 * 4) == 2) {
                *(byte *)(piVar18 + 0xc) = *(byte *)(piVar18 + 0xc) | 4;
              }
              if (*(short *)(*(int *)(in_ECX + 0x2c4) + local_354 * 4) == 3) {
                *(byte *)(piVar18 + 0xc) = *(byte *)(piVar18 + 0xc) | 0xc;
              }
            }
          }
          local_350 = local_350 + 0x34;
          local_34c = local_34c + 0x10;
          local_354 = local_354 + 1;
        } while (local_354 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34);
      }
      local_354 = 0;
      if (0 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc) {
        local_350 = 0;
        local_34c = 0;
        do {
          piVar18 = *(int **)(*(int *)(in_ECX + 0x86c) + local_34c);
          uVar14 = *(int *)(*(int *)(in_ECX + 0x86c) + 4 + local_34c) - (int)piVar18 >> 2;
          if (2 < uVar14) {
            fVar34 = 0.0;
            fVar30 = 0.0;
            fVar31 = 0.0;
            fVar32 = 0.0;
            local_10 = 0.0;
            fStack_c = 0.0;
            local_218 = 0.0;
            fStack_214 = 0.0;
            local_210 = 0.0;
            fStack_20c = 0.0;
            local_28 = 0.0;
            fStack_24 = 0.0;
            uVar15 = 0;
            if (0 < (int)uVar14) {
              iVar11 = *(int *)(in_ECX + 0xb30);
              uVar16 = uVar14;
              local_210 = fVar34;
              local_28 = fVar34;
              fStack_20c = fVar34;
              do {
                iVar10 = *piVar18 * 0x34;
                piVar18 = piVar18 + 1;
                fVar30 = fVar30 + **(float **)(iVar10 + iVar11);
                fVar31 = fVar31 + (*(float **)(iVar10 + iVar11))[1];
                pfVar17 = *(float **)(iVar10 + 4 + iVar11);
                fVar32 = fVar32 + *pfVar17;
                fVar34 = fVar34 + pfVar17[1];
                local_210 = local_210 + pfVar17[2];
                fStack_20c = fStack_20c + pfVar17[3];
                pfVar17 = *(float **)(iVar10 + 8 + iVar11);
                fStack_24 = pfVar17[1] + fStack_24;
                local_28 = local_28 + *pfVar17;
                uVar16 = uVar16 - 1;
                uVar15 = uVar14;
                local_218 = fVar32;
                fStack_214 = fVar34;
                local_10 = fVar30;
                fStack_c = fVar31;
              } while (uVar16 != 0);
            }
            fVar34 = 1.0 / (float)(int)uVar15;
            puVar19 = (undefined4 *)(*(int *)(in_ECX + 0xb48) + local_350);
            local_38 = CONCAT44(fStack_c * fVar34,local_10 * fVar34);
            *(undefined8 *)*puVar19 = local_38;
            puVar6 = (undefined8 *)puVar19[1];
            local_c0 = CONCAT44(fStack_214 * fVar34,local_218 * fVar34);
            local_b8 = CONCAT44(fStack_20c * fVar34,local_210 * fVar34);
            *puVar6 = local_c0;
            puVar6[1] = local_b8;
            pfVar17 = (float *)puVar19[2];
            *pfVar17 = local_28 * fVar34;
            pfVar17[1] = fStack_24 * fVar34;
          }
          local_350 = local_350 + 0x34;
          local_354 = local_354 + 1;
          local_34c = local_34c + 0xc;
        } while (local_354 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc);
      }
      fVar34 = *(float *)(in_ECX + 0xc08);
      fVar30 = 1.0 - fVar34;
      iStack_1c = 0;
      if (0 < (*(int *)(in_ECX + 0xb64) - *(int *)(in_ECX + 0xb60)) / 0xc) {
        fStack_c = DAT_0076de74;
        do {
          iVar11 = *(int *)(in_ECX + 0xb60);
          iVar10 = *(int *)(iVar11 + iStack_1c * 0xc);
          iVar13 = *(int *)(iVar11 + 4 + iStack_1c * 0xc);
          puVar19 = (undefined4 *)
                    (*(int *)(iVar11 + 8 + iStack_1c * 0xc) * 0x34 + *(int *)(in_ECX + 0xb3c));
          iVar11 = *(int *)(in_ECX + 0x86c);
          *(byte *)(puVar19 + 0xc) = *(byte *)(puVar19 + 0xc) & 0xf1;
          iVar22 = *(int *)(*(int *)(in_ECX + 0x86c) + iVar10 * 0xc);
          uVar14 = iVar13 + 1;
          puVar21 = (undefined4 *)
                    (*(int *)(iVar22 + -4 + uVar14 * 4) * 0x34 + *(int *)(in_ECX + 0xb30));
          iVar13 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb54) + iVar10 * 0xc) + iVar13 * 4);
          puVar20 = (undefined4 *)
                    (*(int *)(iVar22 + (uVar14 % (uint)(*(int *)(iVar11 + 4 + iVar10 * 0xc) -
                                                        *(int *)(iVar11 + iVar10 * 0xc) >> 2)) * 4)
                     * 0x34 + *(int *)(in_ECX + 0xb30));
          if (((iVar13 < 0) || ((*(byte *)(puVar21 + 0xc) & 2) != 0)) ||
             ((*(byte *)(puVar20 + 0xc) & 2) != 0)) {
            if ((DAT_0076de78 & 1) == 0) {
              DAT_0076de78 = DAT_0076de78 | 1;
              auVar28._0_12_ = ZEXT812(0x3fe921fb60000000);
              auVar28._12_4_ = 0;
              libm_sse2_cos_precise();
              DAT_0076de74 = 1.0 / ((float)auVar28._0_8_ * 2.0 + 1.0);
              fStack_c = DAT_0076de74;
            }
            if ((*(byte *)(puVar21 + 0xc) & 8) == 0) {
              if ((*(byte *)(puVar20 + 0xc) & 8) != 0) goto LAB_00643ad6;
LAB_00643ae3:
              fVar31 = 0.5;
            }
            else {
              fVar31 = fStack_c;
              if ((*(byte *)(puVar20 + 0xc) & 8) != 0) {
LAB_00643ad6:
                if ((*(byte *)(puVar21 + 0xc) & 8) != 0) goto LAB_00643ae3;
                fVar31 = 1.0 - fStack_c;
              }
            }
            local_a0 = (float)*(undefined8 *)*puVar21;
            local_238 = (float)*(undefined8 *)*puVar20;
            fStack_234 = (float)((ulonglong)*(undefined8 *)*puVar20 >> 0x20);
            fStack_9c = (float)((ulonglong)*(undefined8 *)*puVar21 >> 0x20);
            fVar32 = 1.0 - fVar31;
            local_158 = CONCAT44(fStack_9c * fVar31 + fStack_234 * fVar32,
                                 local_a0 * fVar31 + local_238 * fVar32);
            *(undefined8 *)*puVar19 = local_158;
            uVar2 = *(undefined8 *)puVar20[1];
            uVar3 = ((undefined8 *)puVar20[1])[1];
            uVar4 = *(undefined8 *)puVar21[1];
            uVar5 = ((undefined8 *)puVar21[1])[1];
            local_150 = (float)uVar4;
            local_2e0 = (float)uVar2;
            fStack_2dc = (float)((ulonglong)uVar2 >> 0x20);
            fStack_14c = (float)((ulonglong)uVar4 >> 0x20);
            local_2d8 = (float)uVar3;
            fStack_2d4 = (float)((ulonglong)uVar3 >> 0x20);
            local_148 = (float)uVar5;
            fStack_144 = (float)((ulonglong)uVar5 >> 0x20);
            puVar6 = (undefined8 *)puVar19[1];
            local_168 = CONCAT44(fStack_14c * fVar31 + fStack_2dc * fVar32,
                                 local_150 * fVar31 + local_2e0 * fVar32);
            local_160 = CONCAT44(fStack_144 * fVar31 + fStack_2d4 * fVar32,
                                 local_148 * fVar31 + local_2d8 * fVar32);
            *puVar6 = local_168;
            puVar6[1] = local_160;
            local_248 = (float)*(undefined8 *)puVar20[2];
            local_b0 = (float)*(undefined8 *)puVar21[2];
            fStack_244 = (float)((ulonglong)*(undefined8 *)puVar20[2] >> 0x20);
            pfVar17 = (float *)puVar19[2];
            fStack_ac = (float)((ulonglong)*(undefined8 *)puVar21[2] >> 0x20);
            *pfVar17 = local_b0 * fVar31 + local_248 * fVar32;
            pfVar17[1] = fStack_ac * fVar31 + fStack_244 * fVar32;
            if (((*(byte *)(puVar21 + 0xc) & 4) != 0) || ((*(byte *)(puVar20 + 0xc) & 4) != 0)) {
              *(byte *)(puVar19 + 0xc) = *(byte *)(puVar19 + 0xc) | 4;
            }
          }
          else {
            iVar13 = iVar13 * 0x34;
            pfVar17 = *(float **)(iVar13 + *(int *)(in_ECX + 0xb48));
            iVar10 = iVar10 * 0x34;
            uVar2 = **(undefined8 **)(iVar10 + *(int *)(in_ECX + 0xb48));
            local_50 = (float)uVar2;
            fStack_4c = (float)((ulonglong)uVar2 >> 0x20);
            local_1d0 = (float)*(undefined8 *)*puVar21;
            fStack_1cc = (float)((ulonglong)*(undefined8 *)*puVar21 >> 0x20);
            local_70 = CONCAT44(((((float *)*puVar20)[1] + fStack_1cc) * fVar30 +
                                (pfVar17[1] + fStack_4c) * fVar34) * 0.5,
                                ((local_1d0 + *(float *)*puVar20) * fVar30 +
                                (local_50 + *pfVar17) * fVar34) * 0.5);
            *(undefined8 *)*puVar19 = local_70;
            pfVar17 = *(float **)(*(int *)(in_ECX + 0xb48) + 4 + iVar13);
            puVar6 = *(undefined8 **)(*(int *)(in_ECX + 0xb48) + 4 + iVar10);
            uVar2 = *puVar6;
            uVar3 = puVar6[1];
            local_d8 = (float)uVar2;
            fStack_d4 = (float)((ulonglong)uVar2 >> 0x20);
            local_d0 = (float)uVar3;
            fStack_cc = (float)((ulonglong)uVar3 >> 0x20);
            pfVar7 = (float *)puVar20[1];
            uVar2 = *(undefined8 *)puVar21[1];
            uVar3 = ((undefined8 *)puVar21[1])[1];
            local_f0 = (float)uVar2;
            fStack_ec = (float)((ulonglong)uVar2 >> 0x20);
            local_e8 = (float)uVar3;
            puVar6 = (undefined8 *)puVar19[1];
            fStack_e4 = (float)((ulonglong)uVar3 >> 0x20);
            local_138 = CONCAT44(((pfVar7[1] + fStack_ec) * fVar30 +
                                 (pfVar17[1] + fStack_d4) * fVar34) * 0.5,
                                 ((local_f0 + *pfVar7) * fVar30 + (local_d8 + *pfVar17) * fVar34) *
                                 0.5);
            local_130 = CONCAT44(((pfVar7[3] + fStack_e4) * fVar30 +
                                 (pfVar17[3] + fStack_cc) * fVar34) * 0.5,
                                 ((pfVar7[2] + local_e8) * fVar30 + (pfVar17[2] + local_d0) * fVar34
                                 ) * 0.5);
            *puVar6 = local_138;
            puVar6[1] = local_130;
            pfVar17 = *(float **)(*(int *)(in_ECX + 0xb48) + 8 + iVar13);
            uVar2 = **(undefined8 **)(*(int *)(in_ECX + 0xb48) + 8 + iVar10);
            local_1a0 = (float)uVar2;
            fStack_19c = (float)((ulonglong)uVar2 >> 0x20);
            fVar31 = pfVar17[1];
            local_80 = (float)*(undefined8 *)puVar21[2];
            fStack_7c = (float)((ulonglong)*(undefined8 *)puVar21[2] >> 0x20);
            fVar32 = ((float *)puVar20[2])[1];
            pfVar7 = (float *)puVar19[2];
            *pfVar7 = ((local_80 + *(float *)puVar20[2]) * fVar30 + (local_1a0 + *pfVar17) * fVar34)
                      * 0.5;
            pfVar7[1] = ((fVar32 + fStack_7c) * fVar30 + (fVar31 + fStack_19c) * fVar34) * 0.5;
          }
          iStack_1c = iStack_1c + 1;
        } while (iStack_1c < (*(int *)(in_ECX + 0xb64) - *(int *)(in_ECX + 0xb60)) / 0xc);
      }
      iStack_14 = 0;
      if (0 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc) {
        local_34c = 0;
        fVar31 = DAT_0076de7c;
        do {
          piVar18 = (int *)(*(int *)(in_ECX + 0x86c) + local_34c);
          fStack_c = (float)(piVar18[1] - *piVar18 >> 2);
          if ((2 < (uint)fStack_c) && (uVar14 = 0, 0 < (int)fStack_c)) {
            do {
              iVar10 = *(int *)(local_34c + *(int *)(in_ECX + 0x86c));
              iVar11 = uVar14 * 4;
              uVar14 = uVar14 + 1;
              puVar19 = (undefined4 *)(*(int *)(iVar10 + iVar11) * 0x34 + *(int *)(in_ECX + 0xb30));
              puVar21 = (undefined4 *)
                        (*(int *)(iVar10 + (uVar14 % (uint)fStack_c) * 4) * 0x34 +
                        *(int *)(in_ECX + 0xb30));
              if ((DAT_0076de78 & 2) == 0) {
                DAT_0076de78 = DAT_0076de78 | 2;
                auVar29._0_12_ = ZEXT812(0x3fe921fb60000000);
                auVar29._12_4_ = 0;
                libm_sse2_cos_precise();
                fVar31 = 1.0 / ((float)auVar29._0_8_ * 2.0 + 1.0);
                DAT_0076de7c = fVar31;
              }
              bVar8 = *(byte *)(puVar19 + 0xc) & 8;
              if (bVar8 == 0) {
                if ((*(byte *)(puVar21 + 0xc) & 8) != 0) goto LAB_00643edb;
LAB_00643ee8:
                fVar32 = 0.5;
              }
              else {
                fVar32 = fVar31;
                if ((*(byte *)(puVar21 + 0xc) & 8) != 0) {
LAB_00643edb:
                  if (bVar8 != 0) goto LAB_00643ee8;
                  fVar32 = 1.0 - fVar31;
                }
              }
              local_c8 = (float)*(undefined8 *)*puVar19;
              local_258 = (float)*(undefined8 *)*puVar21;
              fStack_254 = (float)((ulonglong)*(undefined8 *)*puVar21 >> 0x20);
              fStack_c4 = (float)((ulonglong)*(undefined8 *)*puVar19 >> 0x20);
              fVar33 = 1.0 - fVar32;
              fVar23 = local_c8 * fVar32 + local_258 * fVar33;
              fVar24 = fStack_c4 * fVar32 + fStack_254 * fVar33;
              uVar2 = *(undefined8 *)puVar21[1];
              uVar3 = ((undefined8 *)puVar21[1])[1];
              uVar4 = *(undefined8 *)puVar19[1];
              uVar5 = ((undefined8 *)puVar19[1])[1];
              local_180 = (float)uVar4;
              local_308 = (float)uVar2;
              fStack_304 = (float)((ulonglong)uVar2 >> 0x20);
              fStack_17c = (float)((ulonglong)uVar4 >> 0x20);
              local_300 = (float)uVar3;
              local_178 = (float)uVar5;
              fStack_2fc = (float)((ulonglong)uVar3 >> 0x20);
              fStack_174 = (float)((ulonglong)uVar5 >> 0x20);
              fVar25 = local_180 * fVar32 + local_308 * fVar33;
              fVar35 = local_300 * fVar33 + local_178 * fVar32;
              fVar36 = fStack_2fc * fVar33 + fStack_174 * fVar32;
              fVar26 = fStack_17c * fVar32 + fStack_304 * fVar33;
              local_278 = (float)*(undefined8 *)puVar21[2];
              fStack_274 = (float)((ulonglong)*(undefined8 *)puVar21[2] >> 0x20);
              local_170 = (float)*(undefined8 *)puVar19[2];
              fStack_16c = (float)((ulonglong)*(undefined8 *)puVar19[2] >> 0x20);
              fVar27 = fVar32 * local_170 + fVar33 * local_278;
              fVar32 = fVar32 * fStack_16c + fVar33 * fStack_274;
              if ((*(int *)(iVar11 + *(int *)(local_34c + *(int *)(in_ECX + 0xb54))) < 0) ||
                 ((*(byte *)(puVar19 + 0xc) & 1) == 0)) {
                puVar19[3] = fVar23 + (float)puVar19[3];
                puVar19[4] = fVar24 + (float)puVar19[4];
                puVar19[5] = fVar25 + (float)puVar19[5];
                puVar19[6] = fVar26 + (float)puVar19[6];
                puVar19[7] = fVar35 + (float)puVar19[7];
                puVar19[8] = fVar36 + (float)puVar19[8];
                puVar19[9] = (float)puVar19[9] + fVar27;
                puVar19[10] = fVar32 + (float)puVar19[10];
                puVar19[0xb] = puVar19[0xb] + 1;
              }
              if ((*(int *)(iVar11 + *(int *)(local_34c + *(int *)(in_ECX + 0xb54))) < 0) ||
                 ((*(byte *)(puVar21 + 0xc) & 1) == 0)) {
                puVar21[3] = fVar23 + (float)puVar21[3];
                puVar21[4] = fVar24 + (float)puVar21[4];
                puVar21[5] = fVar25 + (float)puVar21[5];
                puVar21[6] = fVar26 + (float)puVar21[6];
                puVar21[7] = fVar35 + (float)puVar21[7];
                puVar21[8] = fVar36 + (float)puVar21[8];
                puVar21[9] = (float)puVar21[9] + fVar27;
                puVar21[10] = fVar32 + (float)puVar21[10];
                puVar21[0xb] = puVar21[0xb] + 1;
              }
              fStack_c = (float)(piVar18[1] - *piVar18 >> 2);
            } while ((int)uVar14 < (int)fStack_c);
          }
          iStack_14 = iStack_14 + 1;
          local_34c = local_34c + 0xc;
        } while (iStack_14 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc);
      }
      iStack_14 = 0;
      if (0 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc) {
        local_34c = 0;
        fStack_c = 0.0;
        do {
          piVar18 = (int *)(*(int *)(in_ECX + 0x86c) + (int)fStack_c);
          iVar10 = 0;
          iVar11 = *piVar18;
          if (0 < (int)(piVar18[1] - iVar11 & 0xfffffffcU)) {
            do {
              iVar11 = *(int *)(iVar11 + iVar10 * 4) * 0x34 + *(int *)(in_ECX + 0xb30);
              if ((*(byte *)(iVar11 + 0x30) & 1) == 0) {
                puVar19 = (undefined4 *)(*(int *)(in_ECX + 0xb48) + local_34c);
                pfVar17 = (float *)*puVar19;
                *(float *)(iVar11 + 0xc) = *(float *)(iVar11 + 0xc) + *pfVar17;
                pfVar7 = (float *)puVar19[1];
                *(float *)(iVar11 + 0x10) = pfVar17[1] + *(float *)(iVar11 + 0x10);
                *(float *)(iVar11 + 0x14) = *(float *)(iVar11 + 0x14) + *pfVar7;
                *(float *)(iVar11 + 0x18) = pfVar7[1] + *(float *)(iVar11 + 0x18);
                *(float *)(iVar11 + 0x1c) = pfVar7[2] + *(float *)(iVar11 + 0x1c);
                pfVar17 = (float *)puVar19[2];
                *(float *)(iVar11 + 0x20) = pfVar7[3] + *(float *)(iVar11 + 0x20);
                *(float *)(iVar11 + 0x24) = *(float *)(iVar11 + 0x24) + *pfVar17;
                *(float *)(iVar11 + 0x28) = pfVar17[1] + *(float *)(iVar11 + 0x28);
                *(int *)(iVar11 + 0x2c) = *(int *)(iVar11 + 0x2c) + 1;
              }
              iVar11 = *piVar18;
              iVar10 = iVar10 + 1;
            } while (iVar10 < piVar18[1] - iVar11 >> 2);
          }
          local_34c = local_34c + 0x34;
          iStack_14 = iStack_14 + 1;
          fStack_c = (float)((int)fStack_c + 0xc);
        } while (iStack_14 < (*(int *)(in_ECX + 0x870) - *(int *)(in_ECX + 0x86c)) / 0xc);
      }
      iVar11 = 0;
      if (0 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34) {
        do {
          puVar19 = (undefined4 *)(iVar11 * 0x34 + *(int *)(in_ECX + 0xb30));
          bVar8 = *(byte *)(puVar19 + 0xc);
          if (((bVar8 & 2) == 0) && (iVar10 = puVar19[0xb], iVar10 != 0)) {
            if ((bVar8 & 1) == 0) {
              if ((DAT_0076de78 & 4) == 0) {
                DAT_0076de80 = 0.75;
                DAT_0076de78 = DAT_0076de78 | 4;
              }
              fVar31 = 1.0 / (float)iVar10;
              uVar2 = *(undefined8 *)*puVar19;
              local_110 = (float)uVar2;
              fStack_10c = (float)((ulonglong)uVar2 >> 0x20);
              local_48 = CONCAT44(fStack_10c * 0.25 + fVar31 * (float)puVar19[4] * DAT_0076de80,
                                  local_110 * 0.25 + fVar31 * (float)puVar19[3] * DAT_0076de80);
              *(undefined8 *)*puVar19 = local_48;
              puVar6 = (undefined8 *)puVar19[1];
              local_1c8 = (float)*puVar6;
              fStack_1c4 = (float)((ulonglong)*puVar6 >> 0x20);
              local_1c0 = (float)puVar6[1];
              fStack_1bc = (float)((ulonglong)puVar6[1] >> 0x20);
              local_1e0 = CONCAT44(fStack_1c4 * 0.25 + fVar31 * (float)puVar19[6] * DAT_0076de80,
                                   local_1c8 * 0.25 + fVar31 * (float)puVar19[5] * DAT_0076de80);
              local_1d8 = CONCAT44(fStack_1bc * 0.25 + fVar31 * (float)puVar19[8] * DAT_0076de80,
                                   local_1c0 * 0.25 + fVar31 * (float)puVar19[7] * DAT_0076de80);
              *puVar6 = local_1e0;
              puVar6[1] = local_1d8;
              pfVar17 = (float *)puVar19[2];
              local_58 = (float)*(undefined8 *)pfVar17;
              fStack_54 = (float)((ulonglong)*(undefined8 *)pfVar17 >> 0x20);
              fVar32 = local_58 * 0.25 + fVar31 * (float)puVar19[9] * DAT_0076de80;
              fVar31 = fStack_54 * 0.25 + fVar31 * (float)puVar19[10] * DAT_0076de80;
            }
            else {
              puVar6 = (undefined8 *)*puVar19;
              if ((bVar8 & 4) == 0) {
                fVar31 = 1.0 / (float)iVar10;
                local_e0 = (float)*puVar6;
                fStack_dc = (float)((ulonglong)*puVar6 >> 0x20);
                local_40 = CONCAT44(fVar30 * fStack_dc + fVar31 * fVar34 * (float)puVar19[4],
                                    fVar30 * local_e0 + fVar31 * fVar34 * (float)puVar19[3]);
                *puVar6 = local_40;
                puVar6 = (undefined8 *)puVar19[1];
                local_198 = (float)*puVar6;
                fStack_194 = (float)((ulonglong)*puVar6 >> 0x20);
                local_190 = (float)puVar6[1];
                fStack_18c = (float)((ulonglong)puVar6[1] >> 0x20);
                local_1b0 = CONCAT44(fStack_194 * fVar30 + fVar31 * fVar34 * (float)puVar19[6],
                                     local_198 * fVar30 + fVar31 * fVar34 * (float)puVar19[5]);
                local_1a8 = CONCAT44(fStack_18c * fVar30 + fVar31 * fVar34 * (float)puVar19[8],
                                     local_190 * fVar30 + fVar31 * fVar34 * (float)puVar19[7]);
                *puVar6 = local_1b0;
                puVar6[1] = local_1a8;
                pfVar17 = (float *)puVar19[2];
                local_f8 = (float)*(undefined8 *)pfVar17;
                fStack_f4 = (float)((ulonglong)*(undefined8 *)pfVar17 >> 0x20);
                fVar32 = local_f8 * fVar30 + fVar31 * (float)puVar19[9] * fVar34;
                fVar31 = fStack_f4 * fVar30 + fVar31 * (float)puVar19[10] * fVar34;
              }
              else {
                fVar31 = 1.0 / (float)iVar10;
                *puVar6 = CONCAT44(fVar31 * (float)puVar19[4],fVar31 * (float)puVar19[3]);
                puVar6 = (undefined8 *)puVar19[1];
                fVar32 = (float)puVar19[7];
                fVar23 = (float)puVar19[8];
                *puVar6 = CONCAT44(fVar31 * (float)puVar19[6],fVar31 * (float)puVar19[5]);
                puVar6[1] = CONCAT44(fVar31 * fVar23,fVar31 * fVar32);
                pfVar17 = (float *)puVar19[2];
                fVar32 = fVar31 * (float)puVar19[9];
                fVar31 = fVar31 * (float)puVar19[10];
              }
            }
            *pfVar17 = fVar32;
            pfVar17[1] = fVar31;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34);
      }
      iStack_14 = 0;
      if (0 < (*(int *)(in_ECX + 0xb64) - *(int *)(in_ECX + 0xb60)) / 0xc) {
        fStack_c = 0.0;
        do {
          iVar11 = *(int *)(in_ECX + 0xb60);
          iVar10 = *(int *)(iVar11 + 4 + (int)fStack_c);
          iVar13 = *(int *)(iVar11 + (int)fStack_c);
          puVar19 = (undefined4 *)
                    (*(int *)(iVar11 + 8 + (int)fStack_c) * 0x34 + *(int *)(in_ECX + 0xb3c));
          iVar11 = *(int *)(*(int *)(in_ECX + 0x86c) + iVar13 * 0xc);
          puVar21 = (undefined4 *)(*(int *)(iVar11 + iVar10 * 4) * 0x34 + *(int *)(in_ECX + 0xb30));
          puVar20 = (undefined4 *)
                    (*(int *)(iVar11 + ((iVar10 + 1U) %
                                       (uint)(*(int *)(*(int *)(in_ECX + 0x86c) + 4 + iVar13 * 0xc)
                                              - iVar11 >> 2)) * 4) * 0x34 + *(int *)(in_ECX + 0xb30)
                    );
          if (((*(int *)(*(int *)(*(int *)(in_ECX + 0xb54) + iVar13 * 0xc) + iVar10 * 4) < 0) &&
              ((*(byte *)(puVar21 + 0xc) & 4) != 0)) && ((*(byte *)(puVar20 + 0xc) & 4) != 0)) {
            local_78 = (float)*(undefined8 *)*puVar21;
            fStack_74 = (float)((ulonglong)*(undefined8 *)*puVar21 >> 0x20);
            local_88 = CONCAT44((((float *)*puVar20)[1] + fStack_74) * 0.5,
                                (local_78 + *(float *)*puVar20) * 0.5);
            *(undefined8 *)*puVar19 = local_88;
            pfVar17 = (float *)puVar20[1];
            uVar2 = *(undefined8 *)puVar21[1];
            uVar3 = ((undefined8 *)puVar21[1])[1];
            local_208 = (float)uVar2;
            puVar6 = (undefined8 *)puVar19[1];
            fStack_204 = (float)((ulonglong)uVar2 >> 0x20);
            local_200 = (float)uVar3;
            fStack_1fc = (float)((ulonglong)uVar3 >> 0x20);
            local_1f8 = CONCAT44((pfVar17[1] + fStack_204) * 0.5,(local_208 + *pfVar17) * 0.5);
            local_1f0 = CONCAT44((pfVar17[3] + fStack_1fc) * 0.5,(pfVar17[2] + local_200) * 0.5);
            *puVar6 = local_1f8;
            puVar6[1] = local_1f0;
            local_98 = (float)*(undefined8 *)puVar21[2];
            fStack_94 = (float)((ulonglong)*(undefined8 *)puVar21[2] >> 0x20);
            fVar34 = ((float *)puVar20[2])[1];
            pfVar17 = (float *)puVar19[2];
            *pfVar17 = (*(float *)puVar20[2] + local_98) * 0.5;
            pfVar17[1] = (fVar34 + fStack_94) * 0.5;
            *(byte *)(puVar19 + 0xc) = *(byte *)(puVar19 + 0xc) & 0xfb | 2;
          }
          iStack_14 = iStack_14 + 1;
          fStack_c = (float)((int)fStack_c + 0xc);
        } while (iStack_14 < (*(int *)(in_ECX + 0xb64) - *(int *)(in_ECX + 0xb60)) / 0xc);
      }
      if (0 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34) {
        iVar10 = 0;
        iVar11 = 0;
        do {
          bVar8 = *(byte *)(*(int *)(in_ECX + 0xb30) + 0x30 + iVar10);
          if ((bVar8 & 8) != 0) {
            *(byte *)(*(int *)(in_ECX + 0xb30) + 0x30 + iVar10) = bVar8 & 0xf3 | 2;
          }
          iVar11 = iVar11 + 1;
          iVar10 = iVar10 + 0x34;
        } while (iVar11 < (*(int *)(in_ECX + 0xb34) - *(int *)(in_ECX + 0xb30)) / 0x34);
      }
      iVar11 = FUN_0063deb0();
      iVar11 = iVar11 + -1;
      if (0 < iVar11) {
        do {
          FUN_00671f80(*(undefined4 *)(in_ECX + 0xc08));
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
  __security_check_cookie(uVar9 ^ (uint)&stack0xfffffffc);
  return;
}




/* plasma::SmoothMeshShape::rebuild @ 00644fa0 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::SmoothMeshShape::rebuild.
 * RTTI AVSmoothMeshShape@plasma@@. Vfunc EnterCriticalSection(this+0xc1c), flag-gated on bits this+0x85c rebuilds GPU child objects this+0xc10/0xc14/0xc18 via Object_release+alloc; 233 float refs (vertex/normal geometry); callees are engine other/lib+gamemisc, no cube:: game. Substantial mesh work, not glue.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::SmoothMeshShape::rebuild(char param_1)

{
  void *_Dst;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  float *pfVar4;
  byte bVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  float **ppfVar11;
  int iVar12;
  int in_ECX;
  int *piVar13;
  undefined4 *puVar14;
  float *pfVar15;
  undefined4 *puVar16;
  float *pfVar17;
  uint *puVar18;
  float *pfVar19;
  float10 fVar20;
  float fVar21;
  double dVar22;
  float fVar23;
  double dVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined8 *puVar27;
  undefined4 uVar28;
  void *pvVar29;
  undefined1 auStack_3e0 [7];
  bool bStack_3d9;
  int *piStack_3d8;
  undefined4 *puStack_3d4;
  uint *puStack_3d0;
  float *pfStack_3cc;
  int *piStack_3c8;
  uint uStack_3c4;
  int *piStack_3c0;
  float *pfStack_3bc;
  float *pfStack_3b8;
  void *pvStack_3b4;
  float fStack_3b0;
  float fStack_3ac;
  int *piStack_3a8;
  int *piStack_3a4;
  int *piStack_3a0;
  int iStack_39c;
  undefined4 *puStack_398;
  float *pfStack_394;
  int *piStack_390;
  int *piStack_38c;
  int local_388;
  uint uStack_384;
  uint *puStack_380;
  uint uStack_37c;
  uint uStack_378;
  int *piStack_374;
  float *pfStack_370;
  float fStack_36c;
  float *pfStack_368;
  float *pfStack_364;
  float fStack_360;
  float fStack_35c;
  int *piStack_358;
  uint uStack_354;
  float *pfStack_350;
  float fStack_34c;
  float fStack_348;
  float fStack_344;
  float fStack_340;
  float fStack_33c;
  float fStack_338;
  float fStack_334;
  undefined8 uStack_330;
  uint *puStack_328;
  int *piStack_324;
  undefined8 uStack_320;
  undefined8 uStack_318;
  undefined1 auStack_310 [8];
  float fStack_308;
  float fStack_304;
  undefined8 uStack_300;
  undefined8 uStack_2f8;
  float fStack_2f0;
  float fStack_2ec;
  float fStack_2e8;
  float fStack_2e4;
  float fStack_2e0;
  float fStack_2dc;
  float fStack_2d8;
  float fStack_2d4;
  float fStack_2d0;
  float fStack_2cc;
  float fStack_2c8;
  float fStack_2c4;
  float fStack_2c0;
  float fStack_2bc;
  float fStack_2b8;
  float fStack_2b4;
  undefined8 uStack_2b0;
  float fStack_2a8;
  float fStack_2a4;
  undefined8 uStack_2a0;
  float fStack_298;
  float fStack_294;
  float fStack_290;
  float fStack_28c;
  float fStack_288;
  float fStack_284;
  float fStack_280;
  float fStack_27c;
  float fStack_278;
  float fStack_274;
  float fStack_270;
  float fStack_26c;
  undefined8 uStack_268;
  undefined8 uStack_260;
  float fStack_258;
  float fStack_254;
  undefined8 uStack_250;
  undefined8 uStack_248;
  float fStack_240;
  float fStack_23c;
  float fStack_238;
  float fStack_234;
  float fStack_230;
  float fStack_22c;
  float fStack_228;
  float fStack_224;
  undefined8 uStack_220;
  float fStack_218;
  float fStack_214;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  float fStack_204;
  undefined8 uStack_200;
  float fStack_1f8;
  float fStack_1f4;
  undefined8 uStack_1f0;
  float fStack_1e8;
  float fStack_1e4;
  float fStack_1e0;
  float fStack_1dc;
  undefined8 uStack_1d8;
  float fStack_1d0;
  float fStack_1cc;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  float fStack_1b8;
  float fStack_1b4;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  int *piStack_190;
  undefined4 *puStack_18c;
  float fStack_188;
  float fStack_184;
  float afStack_180 [2];
  undefined8 uStack_178;
  float fStack_170;
  float fStack_16c;
  undefined8 uStack_168;
  float afStack_160 [3];
  undefined4 uStack_154;
  float afStack_150 [3];
  undefined4 uStack_144;
  float afStack_140 [2];
  undefined4 *puStack_138;
  int *piStack_134;
  float afStack_130 [5];
  undefined4 uStack_11c;
  float afStack_118 [3];
  undefined4 uStack_10c;
  float afStack_108 [3];
  undefined4 uStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_dc;
  float fStack_c8;
  float fStack_c4;
  float fStack_bc;
  undefined1 auStack_ac [16];
  undefined1 auStack_9c [16];
  undefined1 auStack_8c [8];
  undefined1 auStack_84 [16];
  undefined1 auStack_74 [8];
  undefined1 auStack_6c [8];
  undefined1 auStack_64 [8];
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [24];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [16];
  undefined1 auStack_1c [8];
  undefined1 auStack_14 [8];
  uint local_c;
  
  local_c = DAT_0076aa78 ^ (uint)auStack_3e0;
  local_388 = in_ECX;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xc1c));
  bVar5 = ~(byte)(*(uint *)(in_ECX + 0x85c) >> 2) & 1;
  if ((bVar5 == 0) || (*(int *)(in_ECX + 0xc10) != 0)) {
    if ((bVar5 == 0) && (*(int *)(in_ECX + 0xc10) != 0)) {
      Object_release_if_nonnull(*(int *)(in_ECX + 0xc10));
      *(undefined4 *)(in_ECX + 0xc10) = 0;
    }
  }
  else {
    uVar7 = (**(code **)(**(int **)(in_ECX + 4) + 0x30))();
    *(undefined4 *)(in_ECX + 0xc10) = uVar7;
  }
  uVar8 = *(uint *)(in_ECX + 0x85c) >> 1;
  if (((uVar8 & 1) == 0) || (*(int *)(in_ECX + 0xc14) != 0)) {
    if (((uVar8 & 1) == 0) && (*(int *)(in_ECX + 0xc14) != 0)) {
      Object_release_if_nonnull(*(int *)(in_ECX + 0xc14));
      *(undefined4 *)(in_ECX + 0xc14) = 0;
    }
  }
  else {
    uVar7 = (**(code **)(**(int **)(in_ECX + 4) + 0x30))();
    *(undefined4 *)(in_ECX + 0xc14) = uVar7;
  }
  uVar8 = *(uint *)(in_ECX + 0x85c) >> 4;
  if (((uVar8 & 1) == 0) || (*(int *)(in_ECX + 0xc18) != 0)) {
    if (((uVar8 & 1) == 0) && (*(int *)(in_ECX + 0xc18) != 0)) {
      Object_release_if_nonnull(*(int *)(in_ECX + 0xc18));
      *(undefined4 *)(in_ECX + 0xc18) = 0;
    }
  }
  else {
    uVar7 = (**(code **)(**(int **)(in_ECX + 4) + 0x30))();
    *(undefined4 *)(in_ECX + 0xc18) = uVar7;
  }
  if (param_1 == '\0') {
    if (*(char *)(in_ECX + 0xa4) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 1;
      *(undefined1 *)(in_ECX + 0xa4) = 0;
    }
    if (*(char *)(in_ECX + 0x154) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 4;
      *(undefined1 *)(in_ECX + 0x154) = 0;
    }
    if (*(char *)(in_ECX + 0xfc) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 2;
      *(undefined1 *)(in_ECX + 0xfc) = 0;
    }
    if (*(char *)(in_ECX + 0x2b4) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 1;
      *(undefined1 *)(in_ECX + 0x2b4) = 0;
    }
    if (*(char *)(in_ECX + 0x1ac) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 4;
      *(undefined1 *)(in_ECX + 0x1ac) = 0;
    }
    if (*(char *)(in_ECX + 0x25c) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 4;
      *(undefined1 *)(in_ECX + 0x25c) = 0;
    }
    if (*(char *)(in_ECX + 0x204) != '\0') {
      *(uint *)(in_ECX + 0xc0c) = *(uint *)(in_ECX + 0xc0c) | 4;
      *(undefined1 *)(in_ECX + 0x204) = 0;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0xc0c) = 0xf;
  }
  piVar13 = (int *)**(int **)(in_ECX + 0xa8);
  if (((((int *)**(int **)(in_ECX + 0x260))[1] - *(int *)**(int **)(in_ECX + 0x260) >> 1 ^
       piVar13[1] - *piVar13) & 0xfffffff8U) != 0) {
    resizeChildBuffers_type16(piVar13[1] - *piVar13 >> 3);
  }
  piVar13 = (int *)**(int **)(in_ECX + 0xa8);
  if (((((int *)**(int **)(in_ECX + 0x208))[1] - *(int *)**(int **)(in_ECX + 0x208) >> 1 ^
       piVar13[1] - *piVar13) & 0xfffffff8U) != 0) {
    resizeChildBuffers_type16(piVar13[1] - *piVar13 >> 3);
  }
  iVar9 = FUN_0063deb0();
  puVar18 = (uint *)(in_ECX + 0xc0c);
  *puVar18 = *puVar18 | 1;
  pfVar19 = (float *)(iVar9 + -1);
  pfStack_3b8 = pfVar19;
  if (*puVar18 != 0) {
    FUN_0066b9c0();
  }
  if ((int)pfVar19 < 0) {
    vfunc_19();
  }
  else {
    FUN_0066c050();
    if (*(int *)(*(int *)(in_ECX + 0x7f8) + *(int *)(in_ECX + 0x7cc) * 4) == -1) {
      *(undefined4 *)(in_ECX + 0x888) = 0;
    }
    else if ((*(int *)(in_ECX + 0x888) == 0) ||
            (*(int *)(*(int *)(in_ECX + 0x888) + 0x4c) !=
             *(int *)(*(int *)(in_ECX + 0x7f8) + *(int *)(in_ECX + 0x7cc) * 4))) {
      uVar7 = std_map_findValue(*(undefined4 *)(*(int *)(in_ECX + 0x7f8) + *(int *)(in_ECX + 0x7cc) * 4))
      ;
      *(undefined4 *)(in_ECX + 0x888) = uVar7;
    }
    if (*(int *)(*(int *)(in_ECX + 0x850) + *(int *)(in_ECX + 0x824) * 4) == -1) {
      *(undefined4 *)(in_ECX + 0x88c) = 0;
    }
    else if ((*(int *)(in_ECX + 0x88c) == 0) ||
            (*(int *)(*(int *)(in_ECX + 0x88c) + 0x4c) !=
             *(int *)(*(int *)(in_ECX + 0x850) + *(int *)(in_ECX + 0x824) * 4))) {
      uVar7 = std_map_findValue(*(undefined4 *)(*(int *)(in_ECX + 0x850) + *(int *)(in_ECX + 0x824) * 4))
      ;
      *(undefined4 *)(in_ECX + 0x88c) = uVar7;
    }
    if (((~(byte)(*(uint *)(in_ECX + 0x85c) >> 2) & 1) != 0) &&
       ((*(byte *)(in_ECX + 0x85c) & 1) == 0)) {
      FUN_00642ad0(*(undefined4 *)(in_ECX + 0x7c),*(undefined4 *)(in_ECX + 300),
                   *(undefined4 *)(in_ECX + 0xd4));
    }
  }
  piStack_38c = (int *)(in_ECX + 0xba8);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  piStack_3a4 = (int *)(in_ECX + 0xb78);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  piStack_390 = (int *)(in_ECX + 0xb9c);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  pfStack_364 = (float *)(in_ECX + 0xbb4);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  piStack_358 = (int *)(in_ECX + 0xbfc);
  std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  piStack_3a0 = (int *)(in_ECX + 0xbcc);
  if ((*(uint *)(in_ECX + 0x85c) >> 1 & 1) == 0) {
    std_vector_destroy_ptr_elems_stride3(*piStack_3a0,*(undefined4 *)(in_ECX + 0xbd0),&bStack_3d9,pfStack_3b8);
    *(undefined4 *)(in_ECX + 0xbd0) = *(undefined4 *)(in_ECX + 0xbcc);
    piStack_3a8 = (int *)(in_ECX + 0xbd8);
    std_vector_destroy_ptr_elems_stride3(*piStack_3a8,*(undefined4 *)(in_ECX + 0xbdc),&bStack_3d9,pfStack_3b8);
    *(undefined4 *)(in_ECX + 0xbdc) = *(undefined4 *)(in_ECX + 0xbd8);
    puStack_398 = (undefined4 *)(in_ECX + 0xbe4);
    std_vector_destroy_ptr_elems_stride3(*puStack_398,*(undefined4 *)(in_ECX + 0xbe8),&bStack_3d9,pfStack_3b8);
    *(undefined4 *)(in_ECX + 0xbe8) = *(undefined4 *)(in_ECX + 0xbe4);
    std_vector_destroy_ptr_elems_stride3(*(undefined4 *)(in_ECX + 0xbc0),*(undefined4 *)(in_ECX + 0xbc4),&bStack_3d9,
                 pfStack_3b8);
    *(undefined4 *)(in_ECX + 0xbc4) = *(undefined4 *)(in_ECX + 0xbc0);
  }
  else {
    std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
    piStack_3a8 = (int *)(in_ECX + 0xbd8);
    std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
    puStack_398 = (undefined4 *)(in_ECX + 0xbe4);
    std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
    std_vector_resize_12((*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  }
  uStack_37c = CONCAT31(uStack_37c._1_3_,~(byte)(*(uint *)(in_ECX + 0x85c) >> 3)) & 0xffffff01;
  uStack_354 = FUN_0063deb0();
  dVar24 = 2.0;
  uVar8 = uStack_354;
  if ((int)uStack_354 < 0) {
    uVar8 = -uStack_354;
  }
  dVar22 = 1.0;
  while( true ) {
    if ((uVar8 & 1) != 0) {
      dVar22 = dVar22 * dVar24;
    }
    uVar8 = uVar8 >> 1;
    if (uVar8 == 0) break;
    dVar24 = dVar24 * dVar24;
  }
  if ((int)uStack_354 < 0) {
    dVar22 = 1.0 / dVar22;
  }
  uStack_378 = (uint)dVar22;
  puStack_3d0 = (uint *)0x0;
  if (0 < (*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc) {
    pfStack_3cc = (float *)0x0;
    uStack_3c4 = 0;
    do {
      piVar13 = (int *)(*(int *)(in_ECX + 0x8d8) + uStack_3c4);
      if ((~(byte)(*(uint *)(in_ECX + 0x85c) >> 3) & 1) == 0) {
        piStack_3c0 = (int *)(((piVar13[1] - *piVar13 >> 2) + -1) * uStack_378 + 1);
      }
      else {
        piStack_3c0 = (int *)((piVar13[1] - *piVar13 >> 2) * uStack_378);
      }
      std_vector_resize(piStack_3c0);
      std_vector_resize_42bf80(piStack_3c0);
      std_vector_resize_42bf80(piStack_3c0);
      std_vector_resize_42bf80(piStack_3c0);
      std_vector_resize_42bf80(piStack_3c0);
      vectorInt_resize(piStack_3c0);
      std_vector_resize(piStack_3c0);
      if ((*(uint *)(in_ECX + 0x85c) >> 1 & 1) != 0) {
        piVar13 = piStack_3c0;
        if ((~(byte)(*(uint *)(in_ECX + 0x85c) >> 3) & 1) != 0) {
          piVar13 = (int *)((int)piStack_3c0 + 1);
        }
        vectorInt_resize(piVar13);
        *(undefined4 *)(*(int *)(in_ECX + 0xbcc) + 4 + uStack_3c4) =
             *(undefined4 *)(*(int *)(in_ECX + 0xbcc) + uStack_3c4);
        *(undefined4 *)(*(int *)(in_ECX + 0xbd8) + 4 + uStack_3c4) =
             *(undefined4 *)(*(int *)(in_ECX + 0xbd8) + uStack_3c4);
        *(undefined4 *)(*(int *)(in_ECX + 0xbe4) + 4 + uStack_3c4) =
             *(undefined4 *)(*(int *)(in_ECX + 0xbe4) + uStack_3c4);
      }
      puStack_3d4 = (undefined4 *)(*(int *)(in_ECX + 0xbfc) + uStack_3c4);
      pvVar29 = (void *)puStack_3d4[1];
      pvStack_3b4 = (void *)*puStack_3d4;
      piStack_3d8 = (int *)((int)pvVar29 - (int)pvStack_3b4 >> 2);
      if (piStack_3c0 < piStack_3d8) {
        _Dst = (void *)((int)pvStack_3b4 + (int)piStack_3c0 * 4);
        in_ECX = local_388;
        if (_Dst == pvStack_3b4) {
          puStack_3d4[1] = *puStack_3d4;
        }
        else if (_Dst != pvVar29) {
          memmove(_Dst,pvVar29,0);
          puStack_3d4[1] = _Dst;
          in_ECX = local_388;
        }
      }
      else if (piStack_3d8 < piStack_3c0) {
        vector_insertN_stride4(&pfStack_394,pvVar29,(int)piStack_3c0 - (int)piStack_3d8,&pfStack_3cc);
      }
      puStack_3d0 = (uint *)((int)puStack_3d0 + 1);
      uStack_3c4 = uStack_3c4 + 0xc;
    } while ((int)puStack_3d0 < (*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  }
  iStack_39c = 0;
  if (0 < (*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc) {
    do {
      pfVar19 = (float *)(iStack_39c * 0xc);
      puStack_3d0 = (uint *)(*(int *)(in_ECX + 0x8d8) + (int)pfVar19);
      uStack_384 = *puStack_3d0;
      piStack_3c8 = (int *)0x0;
      if (0 < (int)(puStack_3d0[1] - uStack_384 & 0xfffffffc)) {
        fStack_36c = (float)(uStack_378 * 0x10);
        pfStack_3bc = (float *)(uStack_378 * 4);
        pfStack_3cc = (float *)(uStack_378 * 8);
        puStack_3d4 = (undefined4 *)0x0;
        piStack_3c0 = (int *)0x0;
        piStack_3d8 = (int *)0x0;
        do {
          iVar9 = *(int *)(uStack_384 + (int)piStack_3c8 * 4);
          iVar12 = **(int **)(*(int *)(in_ECX + 0xa8) + *(int *)(in_ECX + 0x7c) * 4);
          puVar14 = (undefined4 *)(*(int *)((int)pfVar19 + *piStack_38c) + (int)piStack_3d8);
          *puVar14 = *(undefined4 *)(iVar12 + iVar9 * 8);
          puVar14[1] = *(undefined4 *)(iVar12 + 4 + iVar9 * 8);
          puVar16 = (undefined4 *)
                    (*(int *)(*puStack_3d0 + (int)piStack_3c8 * 4) * 0x10 +
                    **(int **)(*(int *)(local_388 + 0x158) + *(int *)(local_388 + 300) * 4));
          puVar14 = (undefined4 *)
                    (*(int *)((int)pfVar19 + *(int *)(local_388 + 0xb6c)) + (int)puStack_3d4);
          *puVar14 = *puVar16;
          puVar14[1] = puVar16[1];
          puVar14[2] = puVar16[2];
          puVar14[3] = puVar16[3];
          iVar9 = *(int *)(*puStack_3d0 + (int)piStack_3c8 * 4);
          iVar12 = **(int **)(*(int *)(local_388 + 0x100) + *(int *)(local_388 + 0xd4) * 4);
          puVar14 = (undefined4 *)(*(int *)((int)pfVar19 + (int)*pfStack_364) + (int)piStack_3d8);
          *puVar14 = *(undefined4 *)(iVar12 + iVar9 * 8);
          puVar14[1] = *(undefined4 *)(iVar12 + 4 + iVar9 * 8);
          *(undefined4 *)((int)piStack_3c0 + *(int *)((int)pfVar19 + *piStack_358)) =
               *(undefined4 *)
                (*(int *)(local_388 + 0x2c4) + *(int *)(*puStack_3d0 + (int)piStack_3c8 * 4) * 4);
          if ((*(uint *)(local_388 + 0x85c) >> 1 & 1) != 0) {
            puVar16 = (undefined4 *)
                      (*(int *)(*puStack_3d0 + (int)piStack_3c8 * 4) * 0x10 +
                      **(int **)(*(int *)(local_388 + 0x1b0) + *(int *)(local_388 + 0x184) * 4));
            puVar14 = (undefined4 *)
                      (*(int *)((int)pfVar19 + *(int *)(local_388 + 0xb78)) + (int)puStack_3d4);
            *puVar14 = *puVar16;
            puVar14[1] = puVar16[1];
            puVar14[2] = puVar16[2];
            puVar14[3] = puVar16[3];
            *(undefined4 *)((int)piStack_3c0 + *(int *)((int)pfVar19 + *piStack_390)) =
                 *(undefined4 *)
                  (**(int **)(*(int *)(local_388 + 0x2b8) + *(int *)(local_388 + 0x28c) * 4) +
                  *(int *)(*puStack_3d0 + (int)piStack_3c8 * 4) * 4);
            pfVar17 = (float *)(*(int *)((int)pfVar19 + *piStack_390) + (int)piStack_3c0);
            if (*pfVar17 <= 0.1 && *pfVar17 != 0.1) {
              *(undefined4 *)(*(int *)((int)pfVar19 + *piStack_390) + (int)piStack_3c0) = 0x3dcccccd
              ;
            }
          }
          if ((*(uint *)(local_388 + 0x85c) >> 4 & 1) != 0) {
            puVar16 = (undefined4 *)
                      (*(int *)(*puStack_3d0 + (int)piStack_3c8 * 4) * 0x10 +
                      **(int **)(*(int *)(local_388 + 0x260) + *(int *)(local_388 + 0x234) * 4));
            puVar14 = (undefined4 *)
                      (*(int *)((int)pfVar19 + *(int *)(local_388 + 0xb84)) + (int)puStack_3d4);
            *puVar14 = *puVar16;
            puVar14[1] = puVar16[1];
            puVar14[2] = puVar16[2];
            puVar14[3] = puVar16[3];
            puVar16 = (undefined4 *)
                      (*(int *)(*puStack_3d0 + (int)piStack_3c8 * 4) * 0x10 +
                      **(int **)(*(int *)(local_388 + 0x208) + *(int *)(local_388 + 0x1dc) * 4));
            puVar14 = (undefined4 *)
                      (*(int *)((int)pfVar19 + *(int *)(local_388 + 0xb90)) + (int)puStack_3d4);
            *puVar14 = *puVar16;
            puVar14[1] = puVar16[1];
            puVar14[2] = puVar16[2];
            puVar14[3] = puVar16[3];
          }
          piStack_3d8 = piStack_3d8 + uStack_378 * 2;
          piStack_3c0 = piStack_3c0 + uStack_378;
          puStack_3d4 = (undefined4 *)((int)puStack_3d4 + (int)fStack_36c);
          uStack_384 = *puStack_3d0;
          piStack_3c8 = (int *)((int)piStack_3c8 + 1);
          in_ECX = local_388;
        } while ((int)piStack_3c8 < (int)(puStack_3d0[1] - uStack_384) >> 2);
      }
      puStack_3d4 = (undefined4 *)0x0;
      uVar8 = uStack_354;
      pfStack_394 = pfVar19;
      if (0 < (int)uStack_354) {
        do {
          dVar24 = 2.0;
          uVar10 = uVar8;
          if ((int)uVar8 < 0) {
            uVar10 = -uVar8;
          }
          dVar22 = 1.0;
          while( true ) {
            if ((uVar10 & 1) != 0) {
              dVar22 = dVar22 * dVar24;
            }
            uVar10 = uVar10 >> 1;
            if (uVar10 == 0) break;
            dVar24 = dVar24 * dVar24;
          }
          if ((int)uVar8 < 0) {
            dVar22 = 1.0 / dVar22;
          }
          piStack_3c8 = (int *)(int)dVar22;
          iVar9 = *piStack_38c;
          puStack_3d0 = (uint *)((uint)(*(int *)(iVar9 + 4 + (int)pfVar19) -
                                        *(int *)(iVar9 + (int)pfVar19) >> 3) / (uint)piStack_3c8);
          uStack_384 = uVar8;
          FUN_0063ad70(iVar9 + (int)pfVar19,*piStack_358 + (int)pfVar19,piStack_3c8,puStack_3d0,
                       uStack_37c,*(undefined4 *)(local_388 + 0xc08),puStack_3d4);
          in_ECX = local_388;
          FUN_0063ad70(*(int *)(local_388 + 0xbb4) + (int)pfVar19,
                       *(int *)(local_388 + 0xbfc) + (int)pfVar19,piStack_3c8,puStack_3d0,uStack_37c
                       ,*(undefined4 *)(local_388 + 0xc08),puStack_3d4);
          FUN_0063b360(*(int *)(in_ECX + 0xb6c) + (int)pfVar19,
                       *(int *)(in_ECX + 0xbfc) + (int)pfVar19,piStack_3c8,puStack_3d0,uStack_37c,
                       *(undefined4 *)(in_ECX + 0xc08),puStack_3d4);
          if ((*(uint *)(in_ECX + 0x85c) >> 1 & 1) != 0) {
            FUN_0063b360(*(int *)(in_ECX + 0xb78) + (int)pfVar19,
                         *(int *)(in_ECX + 0xbfc) + (int)pfVar19,piStack_3c8,puStack_3d0,uStack_37c,
                         *(undefined4 *)(in_ECX + 0xc08),puStack_3d4);
            FUN_0063a980(*(int *)(in_ECX + 0xb9c) + (int)pfVar19,
                         *(int *)(in_ECX + 0xbfc) + (int)pfVar19,piStack_3c8,puStack_3d0,uStack_37c,
                         *(undefined4 *)(in_ECX + 0xc08),puStack_3d4);
          }
          if ((*(uint *)(in_ECX + 0x85c) >> 4 & 1) != 0) {
            FUN_0063bba0(*(int *)(in_ECX + 0xb84) + (int)pfVar19,piStack_3c8,puStack_3d0,uStack_37c,
                         *(undefined4 *)(in_ECX + 0xc08));
            FUN_0063bba0(*(int *)(in_ECX + 0xb90) + (int)pfVar19,piStack_3c8,puStack_3d0,uStack_37c,
                         *(undefined4 *)(in_ECX + 0xc08));
          }
          puStack_3d4 = (undefined4 *)((int)puStack_3d4 + 1);
          uStack_384 = uStack_384 - 1;
          uVar8 = uStack_384;
        } while ((int)puStack_3d4 < (int)uStack_354);
      }
      if ((*(uint *)(in_ECX + 0x85c) >> 1 & 1) != 0) {
        piStack_3d8 = *(int **)(in_ECX + 0xba8);
        pvStack_3b4 = (void *)(*(int *)((int)(pfVar19 + 1) + (int)piStack_3d8) -
                               *(int *)((int)pfVar19 + (int)piStack_3d8) >> 3);
        fStack_3b0 = 0.0;
        if ((~(byte)(*(uint *)(in_ECX + 0x85c) >> 3) & 1) != 0) {
          pvStack_3b4 = (void *)((int)pvStack_3b4 + 1);
        }
        iVar9 = 0;
        if (0 < (int)(*(int *)((int)(pfVar19 + 1) + (int)piStack_3d8) -
                      *(int *)((int)pfVar19 + (int)piStack_3d8) & 0xfffffff8U)) {
          do {
            iVar9 = iVar9 + 1;
          } while (iVar9 < *(int *)((int)(pfVar19 + 1) + (int)piStack_3d8) -
                           *(int *)((int)pfVar19 + (int)piStack_3d8) >> 3);
        }
        fStack_35c = (float)*(int *)(local_388 + 0x868);
        uStack_384 = 0;
        in_ECX = local_388;
        if (0 < (int)pvStack_3b4) {
          do {
            iVar9 = local_388;
            uStack_3c4 = uStack_384 %
                         (uint)(*(int *)(*(int *)(local_388 + 0xba8) + 4 + (int)pfVar19) -
                                *(int *)(*(int *)(local_388 + 0xba8) + (int)pfVar19) >> 3);
            *(int *)(*(int *)((int)pfVar19 + *(int *)(local_388 + 0xbc0)) + uStack_384 * 4) =
                 *(int *)(*(int *)(local_388 + 0xbcc) + 4 + (int)pfVar19) -
                 *(int *)(*(int *)(local_388 + 0xbcc) + (int)pfVar19) >> 3;
            bVar5 = ~(byte)(*(uint *)(local_388 + 0x85c) >> 3) & 1;
            if ((bVar5 == 0) && (uStack_3c4 == 0)) {
              pfStack_3cc = (float *)*piStack_38c;
              puVar27 = *(undefined8 **)((int)pfVar19 + (int)pfStack_3cc);
              uVar1 = *puVar27;
              uStack_1d8._0_4_ = (float)uVar1;
              puStack_3d4 = (undefined4 *)((float)uStack_1d8 - *(float *)(puVar27 + 1));
              uStack_1d8._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
              fVar23 = uStack_1d8._4_4_ - *(float *)((int)puVar27 + 0xc);
              uStack_1d8 = uVar1;
              if (fVar23 * fVar23 + (float)puStack_3d4 * (float)puStack_3d4 == 0.0) {
                uStack_260._0_4_ = (float)*puVar27;
                uVar8 = (((int)(uStack_378 + 1) / (int)uStack_378) * uStack_378) %
                        (uint)(*(int *)((int)(pfVar19 + 1) + (int)pfStack_3cc) -
                               *(int *)((int)pfVar19 + (int)pfStack_3cc) >> 3);
                puStack_3d4 = (undefined4 *)((float)uStack_260 - *(float *)(puVar27 + uVar8));
                uStack_260._4_4_ = (float)((ulonglong)*puVar27 >> 0x20);
                fVar23 = uStack_260._4_4_ - *(float *)((int)puVar27 + uVar8 * 8 + 4);
                uStack_260 = CONCAT44(fVar23,puStack_3d4);
                uStack_1d8 = uStack_260;
              }
              piStack_3d8 = (int *)-fVar23;
              dVar24 = (double)((float)piStack_3d8 * (float)piStack_3d8 +
                               (float)puStack_3d4 * (float)puStack_3d4);
              libm_sse2_sqrt_precise();
              fVar23 = **(float **)((int)pfVar19 + *piStack_390) * 0.5;
              piStack_3d8 = (int *)((float)piStack_3d8 * (1.0 / (float)dVar24) * fVar23);
              puStack_3d4 = (undefined4 *)((float)puStack_3d4 * (1.0 / (float)dVar24) * fVar23);
              uStack_178 = CONCAT44(puStack_3d4,piStack_3d8);
              fStack_3ac = (float)piStack_3d8 * fStack_35c;
              fStack_2e8 = (float)*puVar27;
              piStack_3c8 = (int *)((float)puStack_3d4 * fStack_35c);
              fStack_2e8 = fStack_2e8 + (float)piStack_3d8;
              puVar18 = (uint *)(*piStack_3a0 + (int)pfVar19);
              puVar3 = (undefined8 *)puVar18[1];
              fStack_2e4 = (float)((ulonglong)*puVar27 >> 0x20);
              fStack_2e4 = fStack_2e4 + (float)puStack_3d4;
              uStack_318 = CONCAT44(fStack_2e4 + (float)piStack_3c8,fStack_2e8 + fStack_3ac);
              piStack_190 = piStack_3d8;
              puStack_18c = puStack_3d4;
              if ((&uStack_318 < puVar3) && ((undefined8 *)*puVar18 <= &uStack_318)) {
                puVar27 = (undefined8 *)puVar18[2];
                puStack_3d0 = (uint *)((int)&uStack_318 - (int)*puVar18 >> 3);
                if ((puVar3 == puVar27) && ((int)puVar27 - (int)puVar3 >> 3 == 0)) {
                  iVar9 = (int)((int)puVar3 - *puVar18) >> 3;
                  if (iVar9 == 0x1fffffff) goto LAB_006485b3;
                  pfStack_3cc = (float *)(iVar9 + 1);
                  uVar8 = (int)((int)puVar27 - *puVar18) >> 3;
                  if (0x1fffffff - (uVar8 >> 1) < uVar8) {
                    pfVar17 = (float *)0x0;
                  }
                  else {
                    pfVar17 = (float *)(uVar8 + (uVar8 >> 1));
                  }
                  if (pfVar17 < pfStack_3cc) {
                    pfVar17 = pfStack_3cc;
                  }
                  vectorReserve8(pfVar17);
                }
                puVar14 = (undefined4 *)puVar18[1];
                uVar8 = *puVar18;
                if (puVar14 != (undefined4 *)0x0) {
                  *puVar14 = *(undefined4 *)(uVar8 + (int)puStack_3d0 * 8);
                  puVar14[1] = *(undefined4 *)(uVar8 + 4 + (int)puStack_3d0 * 8);
                }
              }
              else {
                puVar27 = (undefined8 *)puVar18[2];
                if ((puVar3 == puVar27) && ((int)puVar27 - (int)puVar3 >> 3 == 0)) {
                  iVar9 = (int)((int)puVar3 - *puVar18) >> 3;
                  if (iVar9 == 0x1fffffff) goto LAB_006485b3;
                  pfStack_3cc = (float *)(iVar9 + 1);
                  uVar8 = (int)((int)puVar27 - *puVar18) >> 3;
                  if (0x1fffffff - (uVar8 >> 1) < uVar8) {
                    pfVar17 = (float *)0x0;
                  }
                  else {
                    pfVar17 = (float *)(uVar8 + (uVar8 >> 1));
                  }
                  if (pfVar17 < pfStack_3cc) {
                    pfVar17 = pfStack_3cc;
                  }
                  vectorReserve8(pfVar17);
                }
                if ((undefined8 *)puVar18[1] != (undefined8 *)0x0) {
                  *(undefined8 *)puVar18[1] = uStack_318;
                }
              }
              puVar18[1] = puVar18[1] + 8;
              fStack_1b8 = (float)**(undefined8 **)((int)pfVar19 + *piStack_38c);
              fStack_1b8 = fStack_1b8 - (float)piStack_3d8;
              puVar18 = (uint *)(*piStack_3a0 + (int)pfVar19);
              puVar27 = (undefined8 *)puVar18[1];
              fStack_1b4 = (float)((ulonglong)**(undefined8 **)((int)pfVar19 + *piStack_38c) >> 0x20
                                  );
              fStack_1b4 = fStack_1b4 - (float)puStack_3d4;
              uStack_320 = CONCAT44(fStack_1b4 + (float)piStack_3c8,fStack_1b8 + fStack_3ac);
              if ((&uStack_320 < puVar27) && ((undefined8 *)*puVar18 <= &uStack_320)) {
                puVar3 = (undefined8 *)puVar18[2];
                piStack_3d8 = (int *)((int)&uStack_320 - (int)*puVar18 >> 3);
                if ((puVar27 == puVar3) && ((int)puVar3 - (int)puVar27 >> 3 == 0)) {
                  iVar9 = (int)((int)puVar27 - *puVar18) >> 3;
                  if (iVar9 == 0x1fffffff) goto LAB_006485b3;
                  pfStack_3cc = (float *)(iVar9 + 1);
                  uVar8 = (int)((int)puVar3 - *puVar18) >> 3;
                  if (0x1fffffff - (uVar8 >> 1) < uVar8) {
                    pfVar17 = (float *)0x0;
                  }
                  else {
                    pfVar17 = (float *)(uVar8 + (uVar8 >> 1));
                  }
                  if (pfVar17 < pfStack_3cc) {
                    pfVar17 = pfStack_3cc;
                  }
                  vectorReserve8(pfVar17);
                }
                puVar14 = (undefined4 *)puVar18[1];
                uVar8 = *puVar18;
                if (puVar14 != (undefined4 *)0x0) {
                  *puVar14 = *(undefined4 *)(uVar8 + (int)piStack_3d8 * 8);
                  puVar14[1] = *(undefined4 *)(uVar8 + 4 + (int)piStack_3d8 * 8);
                }
              }
              else {
                puVar3 = (undefined8 *)puVar18[2];
                if ((puVar27 == puVar3) && ((int)puVar3 - (int)puVar27 >> 3 == 0)) {
                  iVar9 = (int)((int)puVar27 - *puVar18) >> 3;
                  if (iVar9 == 0x1fffffff) goto LAB_006485b3;
                  pfStack_3cc = (float *)(iVar9 + 1);
                  uVar8 = (int)((int)puVar3 - *puVar18) >> 3;
                  if (0x1fffffff - (uVar8 >> 1) < uVar8) {
                    pfVar17 = (float *)0x0;
                  }
                  else {
                    pfVar17 = (float *)(uVar8 + (uVar8 >> 1));
                  }
                  if (pfVar17 < pfStack_3cc) {
                    pfVar17 = pfStack_3cc;
                  }
                  vectorReserve8(pfVar17);
                }
                if ((undefined8 *)puVar18[1] != (undefined8 *)0x0) {
                  *(undefined8 *)puVar18[1] = uStack_320;
                }
              }
              puVar18[1] = puVar18[1] + 8;
              pfVar17 = *(float **)((int)pfVar19 + *piStack_3a4);
              piStack_3d8 = (int *)(*piStack_3a8 + (int)pfVar19);
              pfVar15 = (float *)piStack_3d8[1];
              if ((pfVar17 < pfVar15) && (pfVar4 = (float *)*piStack_3d8, pfVar4 <= pfVar17)) {
                pfStack_3cc = (float *)piStack_3d8[2];
                if ((pfVar15 == pfStack_3cc) && ((int)pfStack_3cc - (int)pfVar15 >> 4 == 0)) {
                  iVar9 = (int)pfVar15 - *piStack_3d8 >> 4;
                  if (iVar9 == 0xfffffff) goto LAB_006485b3;
                  pfStack_3bc = (float *)(iVar9 + 1);
                  uVar8 = (int)pfStack_3cc - *piStack_3d8 >> 4;
                  fStack_3ac = (float)(uVar8 >> 1);
                  if (0xfffffffU - (int)fStack_3ac < uVar8) {
                    pfVar15 = (float *)0x0;
                  }
                  else {
                    pfVar15 = (float *)(uVar8 + (int)fStack_3ac);
                  }
                  if (pfVar15 < pfStack_3bc) {
                    pfVar15 = pfStack_3bc;
                  }
                  vectorReserve16(pfVar15);
                }
                pfVar17 = (float *)(((int)pfVar17 - (int)pfVar4 & 0xfffffff0U) + *piStack_3d8);
              }
              else {
                pfStack_3cc = (float *)piStack_3d8[2];
                if ((pfVar15 == pfStack_3cc) && ((int)pfStack_3cc - (int)pfVar15 >> 4 == 0)) {
                  iVar9 = (int)pfVar15 - *piStack_3d8 >> 4;
                  if (iVar9 == 0xfffffff) goto LAB_006485b3;
                  pfStack_3bc = (float *)(iVar9 + 1);
                  uVar8 = (int)pfStack_3cc - *piStack_3d8 >> 4;
                  fStack_3ac = (float)(uVar8 >> 1);
                  if (0xfffffffU - (int)fStack_3ac < uVar8) {
                    pfVar15 = (float *)0x0;
                  }
                  else {
                    pfVar15 = (float *)(uVar8 + (int)fStack_3ac);
                  }
                  if (pfVar15 < pfStack_3bc) {
                    pfVar15 = pfStack_3bc;
                  }
                  vectorReserve16(pfVar15);
                }
              }
              pfVar15 = (float *)piStack_3d8[1];
              if (pfVar15 != (float *)0x0) {
                *pfVar15 = *pfVar17;
                pfVar15[1] = pfVar17[1];
                pfVar15[2] = pfVar17[2];
                pfVar15[3] = pfVar17[3];
              }
              piStack_3d8[1] = piStack_3d8[1] + 0x10;
              pfVar17 = *(float **)((int)pfVar19 + *piStack_3a4);
              piStack_3d8 = (int *)(*piStack_3a8 + (int)pfVar19);
              pfVar19 = (float *)piStack_3d8[1];
              if ((pfVar17 < pfVar19) && (pfVar15 = (float *)*piStack_3d8, pfVar15 <= pfVar17)) {
                pfStack_3cc = (float *)piStack_3d8[2];
                if ((pfVar19 == pfStack_3cc) && ((int)pfStack_3cc - (int)pfVar19 >> 4 == 0)) {
                  iVar9 = (int)pfVar19 - *piStack_3d8 >> 4;
                  if (iVar9 == 0xfffffff) {
LAB_006485b3:
                    /* WARNING: Subroutine does not return */
                    std::_Xlength_error("vector<T> too long");
                  }
                  pfStack_3bc = (float *)(iVar9 + 1);
                  uVar8 = (int)pfStack_3cc - *piStack_3d8 >> 4;
                  fStack_3ac = (float)(uVar8 >> 1);
                  if (0xfffffffU - (int)fStack_3ac < uVar8) {
                    pfVar19 = (float *)0x0;
                  }
                  else {
                    pfVar19 = (float *)(uVar8 + (int)fStack_3ac);
                  }
                  if (pfVar19 < pfStack_3bc) {
                    pfVar19 = pfStack_3bc;
                  }
                  vectorReserve16(pfVar19);
                }
                pfVar17 = (float *)(((int)pfVar17 - (int)pfVar15 & 0xfffffff0U) + *piStack_3d8);
              }
              else {
                pfStack_3cc = (float *)piStack_3d8[2];
                if ((pfVar19 == pfStack_3cc) && ((int)pfStack_3cc - (int)pfVar19 >> 4 == 0)) {
                  iVar9 = (int)pfVar19 - *piStack_3d8 >> 4;
                  if (iVar9 == 0xfffffff) goto LAB_006485b3;
                  pfStack_3bc = (float *)(iVar9 + 1);
                  uVar8 = (int)pfStack_3cc - *piStack_3d8 >> 4;
                  fStack_3ac = (float)(uVar8 >> 1);
                  if (0xfffffffU - (int)fStack_3ac < uVar8) {
                    pfVar19 = (float *)0x0;
                  }
                  else {
                    pfVar19 = (float *)(uVar8 + (int)fStack_3ac);
                  }
                  if (pfVar19 < pfStack_3bc) {
                    pfVar19 = pfStack_3bc;
                  }
                  vectorReserve16(pfVar19);
                }
              }
              pfVar19 = (float *)piStack_3d8[1];
              if (pfVar19 != (float *)0x0) {
                *pfVar19 = *pfVar17;
                pfVar19[1] = pfVar17[1];
                pfVar19[2] = pfVar17[2];
                pfVar19[3] = pfVar17[3];
              }
              piStack_3d8[1] = piStack_3d8[1] + 0x10;
              afStack_108[2] = fStack_3b0;
              uStack_fc = 0;
              FUN_00642590(afStack_108 + 2);
              afStack_180[0] = fStack_3b0;
              afStack_180[1] = 1.0;
              FUN_00642590(afStack_180);
              uVar8 = uStack_3c4;
            }
            else if ((bVar5 == 0) &&
                    (pfStack_3cc = *(float **)(local_388 + 0xba8),
                    uStack_3c4 ==
                    (*(int *)((int)(pfVar19 + 1) + (int)pfStack_3cc) -
                     *(int *)((int)pfVar19 + (int)pfStack_3cc) >> 3) - 1U)) {
              fStack_36c = *(float *)((int)pfVar19 + (int)pfStack_3cc);
              pfStack_3bc = (float *)(uStack_3c4 * 8);
              uVar1 = *(undefined8 *)((int)pfStack_3bc + -8 + (int)fStack_36c);
              uStack_1c0._0_4_ = (float)uVar1;
              piStack_3d8 = (int *)((float)uStack_1c0 -
                                   *(float *)((int)pfStack_3bc + (int)fStack_36c));
              uStack_1c0._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
              fVar23 = uStack_1c0._4_4_ - *(float *)((int)pfStack_3bc + 4 + (int)fStack_36c);
              uStack_1c0 = uVar1;
              if (fVar23 * fVar23 + (float)piStack_3d8 * (float)piStack_3d8 == 0.0) {
                uVar1 = *(undefined8 *)
                         ((int)fStack_36c +
                         ((((((*(int *)((int)(pfVar19 + 1) + (int)pfStack_3cc) - (int)fStack_36c >>
                              3) - uStack_378) + -1 + uStack_3c4) / uStack_378) * uStack_378) %
                         (uint)(*(int *)((int)(pfVar19 + 1) + (int)pfStack_3cc) -
                                *(int *)((int)pfVar19 + (int)pfStack_3cc) >> 3)) * 8);
                uStack_1a8._0_4_ = (float)uVar1;
                piStack_3d8 = (int *)((float)uStack_1a8 -
                                     *(float *)((int)pfStack_3bc + (int)fStack_36c));
                uStack_1a8._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
                fVar23 = uStack_1a8._4_4_ - *(float *)((int)pfStack_3bc + 4 + (int)fStack_36c);
                uStack_1a8 = CONCAT44(fVar23,piStack_3d8);
                uStack_1c0 = uStack_1a8;
              }
              puStack_3d4 = (undefined4 *)-fVar23;
              dVar24 = (double)((float)puStack_3d4 * (float)puStack_3d4 +
                               (float)piStack_3d8 * (float)piStack_3d8);
              libm_sse2_sqrt_precise();
              uVar8 = uStack_3c4;
              fVar23 = *(float *)(*(int *)((int)pfVar19 + *piStack_390) + uStack_3c4 * 4) * 0.5;
              puStack_3d4 = (undefined4 *)((float)puStack_3d4 * (1.0 / (float)dVar24) * fVar23);
              piStack_3d8 = (int *)((float)piStack_3d8 * (1.0 / (float)dVar24) * fVar23);
              uStack_168 = CONCAT44(piStack_3d8,puStack_3d4);
              uVar1 = *(undefined8 *)((int)fStack_36c + uStack_3c4 * 8);
              pfStack_3cc = (float *)((float)puStack_3d4 * fStack_35c);
              fStack_2d0 = (float)uVar1;
              pfStack_3bc = (float *)((float)piStack_3d8 * fStack_35c);
              fStack_2d0 = fStack_2d0 + (float)puStack_3d4;
              fStack_2cc = (float)((ulonglong)uVar1 >> 0x20);
              fStack_2cc = fStack_2cc + (float)piStack_3d8;
              _fStack_230 = CONCAT44(fStack_2cc + (float)pfStack_3bc,fStack_2d0 + (float)pfStack_3cc
                                    );
              puStack_138 = puStack_3d4;
              piStack_134 = piStack_3d8;
              FUN_00642590(&fStack_230);
              uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piStack_38c) + uVar8 * 8);
              fStack_2c0 = (float)uVar1;
              fStack_2c0 = fStack_2c0 - (float)puStack_3d4;
              fStack_2bc = (float)((ulonglong)uVar1 >> 0x20);
              fStack_2bc = fStack_2bc - (float)piStack_3d8;
              _fStack_1e0 = CONCAT44((float)pfStack_3bc + fStack_2bc,(float)pfStack_3cc + fStack_2c0
                                    );
              FUN_00642590(&fStack_1e0);
              iVar9 = uVar8 * 0x10;
              std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + iVar9);
              std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + iVar9);
              afStack_118[0] = fStack_3b0;
              afStack_118[1] = 0.0;
              FUN_00642590(afStack_118);
              afStack_160[2] = fStack_3b0;
              uStack_154 = 0x3f800000;
              FUN_00642590(afStack_160 + 2);
              uVar8 = uStack_3c4;
            }
            else {
              iVar12 = *(int *)(local_388 + 0xba8);
              puStack_3d4 = *(undefined4 **)((int)pfVar19 + iVar12);
              piStack_3c0 = (int *)(uStack_3c4 * 8);
              uVar1 = *(undefined8 *)
                       (puStack_3d4 +
                       (((*(int *)((int)pfVar19 + iVar12 + 4) - *(int *)((int)pfVar19 + iVar12) >> 3
                         ) + (uStack_3c4 - 1)) %
                       (uint)(*(int *)((int)pfVar19 + iVar12 + 4) -
                              *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >> 3)) * 2);
              uStack_220._0_4_ = (float)uVar1;
              uStack_220._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
              piStack_3c8 = (int *)((float)uStack_220 -
                                   *(float *)((int)piStack_3c0 + (int)puStack_3d4));
              fVar23 = uStack_220._4_4_ - *(float *)((int)(piStack_3c0 + 1) + (int)puStack_3d4);
              uVar2 = *(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4);
              uStack_1b0._0_4_ = (float)uVar2;
              uStack_1b0._4_4_ = (float)((ulonglong)uVar2 >> 0x20);
              piStack_3d8 = (int *)((float)uStack_1b0 -
                                   (float)puStack_3d4
                                          [((uStack_3c4 + 1) %
                                           (uint)(*(int *)((int)pfVar19 +
                                                          *(int *)(local_388 + 0xba8) + 4) -
                                                  *(int *)((int)pfVar19 +
                                                          *(int *)(local_388 + 0xba8)) >> 3)) * 2]);
              fStack_3ac = uStack_1b0._4_4_ -
                           (float)(puStack_3d4 +
                                  ((uStack_3c4 + 1) %
                                  (uint)(*(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8) + 4) -
                                         *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >> 3))
                                  * 2)[1];
              uStack_220 = uVar1;
              if (fVar23 * fVar23 + (float)piStack_3c8 * (float)piStack_3c8 == 0.0) {
                uStack_2b0._0_4_ =
                     (float)*(undefined8 *)
                             (puStack_3d4 +
                             ((((((*(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8) + 4) -
                                   *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >> 3) -
                                 uStack_378) + (uStack_3c4 - 1)) / uStack_378) * uStack_378) %
                             (uint)(*(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8) + 4) -
                                    *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >> 3)) * 2)
                ;
                piStack_3c8 = (int *)((float)uStack_2b0 -
                                     *(float *)((int)piStack_3c0 + (int)puStack_3d4));
                uStack_2b0._4_4_ =
                     (float)((ulonglong)
                             *(undefined8 *)
                              (puStack_3d4 +
                              ((((((*(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8) + 4) -
                                    *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >> 3) -
                                  uStack_378) + (uStack_3c4 - 1)) / uStack_378) * uStack_378) %
                              (uint)(*(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8) + 4) -
                                     *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >> 3)) * 2
                              ) >> 0x20);
                fVar23 = uStack_2b0._4_4_ - *(float *)((int)(piStack_3c0 + 1) + (int)puStack_3d4);
                uStack_2b0 = CONCAT44(fVar23,piStack_3c8);
                uStack_220 = uStack_2b0;
              }
              uStack_1b0 = uVar2;
              if (fStack_3ac * fStack_3ac + (float)piStack_3d8 * (float)piStack_3d8 == 0.0) {
                uStack_2a0._0_4_ = (float)*(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4);
                piStack_3d8 = (int *)((float)uStack_2a0 -
                                     (float)puStack_3d4
                                            [((((int)(uStack_3c4 + 1 + uStack_378) / (int)uStack_378
                                               ) * uStack_378) %
                                             (uint)(*(int *)((int)pfVar19 +
                                                            *(int *)(local_388 + 0xba8) + 4) -
                                                    *(int *)((int)pfVar19 +
                                                            *(int *)(local_388 + 0xba8)) >> 3)) * 2]
                                     );
                uStack_2a0._4_4_ =
                     (float)((ulonglong)*(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4) >> 0x20
                            );
                fStack_3ac = uStack_2a0._4_4_ -
                             (float)(puStack_3d4 +
                                    ((((int)(uStack_3c4 + 1 + uStack_378) / (int)uStack_378) *
                                     uStack_378) %
                                    (uint)(*(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8) + 4)
                                           - *(int *)((int)pfVar19 + *(int *)(local_388 + 0xba8)) >>
                                          3)) * 2)[1];
                uStack_2a0 = CONCAT44(fStack_3ac,piStack_3d8);
                uStack_1b0 = uStack_2a0;
              }
              puStack_3d0 = (uint *)-fVar23;
              puStack_380 = (uint *)((uint)fStack_3ac ^ 0x80000000);
              fVar23 = (float)puStack_3d0 * (float)puStack_3d0 +
                       (float)piStack_3c8 * (float)piStack_3c8;
              bStack_3d9 = true;
              piStack_374 = piStack_3d8;
              puStack_328 = puStack_3d0;
              if (0.0 < fVar23) {
                dVar24 = (double)fVar23;
                piStack_324 = piStack_3c8;
                libm_sse2_sqrt_precise();
                puStack_328 = (uint *)((float)puStack_3d0 * (1.0 / (float)dVar24));
                piStack_3c8 = (int *)((float)piStack_3c8 * (1.0 / (float)dVar24));
              }
              bStack_3d9 = 0.0 >= fVar23;
              fVar23 = (float)puStack_380 * (float)puStack_380 +
                       (float)piStack_3d8 * (float)piStack_3d8;
              puStack_3d0 = puStack_328;
              piStack_324 = piStack_3c8;
              if (0.0 < fVar23) {
                dVar24 = (double)fVar23;
                libm_sse2_sqrt_precise();
                puStack_380 = (uint *)((float)puStack_380 * (1.0 / (float)dVar24));
                piStack_374 = (int *)((float)piStack_3d8 * (1.0 / (float)dVar24));
              }
              uStack_330 = CONCAT44(piStack_324,puStack_328);
              pfStack_3bc = (float *)((float)piStack_374 + (float)piStack_324);
              pfStack_3cc = (float *)((float)puStack_380 + (float)puStack_328);
              fVar23 = (float)pfStack_3bc * (float)pfStack_3bc +
                       (float)pfStack_3cc * (float)pfStack_3cc;
              if (fVar23 <= 0.0) {
                afStack_130[2] = 0.0;
                afStack_130[3] = 0.0;
                uStack_330._4_4_ = 0.0;
                uStack_330._0_4_ = 0.0;
              }
              else {
                dVar24 = (double)fVar23;
                libm_sse2_sqrt_precise();
                uStack_330._0_4_ = (float)pfStack_3cc * (1.0 / (float)dVar24);
                uStack_330._4_4_ = (float)pfStack_3bc * (1.0 / (float)dVar24);
                if (((int)uStack_3c4 % (int)uStack_378 == 0) &&
                   (*(short *)(*(int *)((int)pfVar19 + *(int *)(iVar9 + 0xbfc)) + uStack_3c4 * 4) ==
                    1)) {
                  piVar13 = piStack_3c8;
                  puVar18 = puStack_3d0;
                  if (bStack_3d9 != false) {
                    piVar13 = piStack_374;
                    puVar18 = puStack_380;
                  }
                  pfStack_350 = (float *)((float)piVar13 * uStack_330._4_4_ +
                                         (float)puVar18 * (float)uStack_330);
                  pfStack_368 = (float *)0x3e99999a;
                  ppfVar11 = &pfStack_350;
                  if ((float)pfStack_350 <= 0.3) {
                    ppfVar11 = &pfStack_368;
                  }
                  uStack_330._0_4_ = (float)uStack_330 / (float)*ppfVar11;
                  uStack_330._4_4_ = uStack_330._4_4_ / (float)*ppfVar11;
                }
              }
              piVar13 = piStack_3c0;
              uVar8 = uStack_3c4;
              pfStack_3cc = (float *)(*(float *)(*(int *)((int)pfVar19 + *(int *)(iVar9 + 0xb9c)) +
                                                uStack_3c4 * 4) * 0.5);
              fStack_36c = (float)pfStack_3cc * uStack_330._4_4_;
              pfStack_3bc = (float *)((float)pfStack_3cc * (float)uStack_330);
              uStack_330 = CONCAT44(fStack_36c,pfStack_3bc);
              _fStack_340 = CONCAT44(fStack_36c * fStack_35c,(float)pfStack_3bc * fStack_35c);
              if (((int)uStack_3c4 % (int)uStack_378 == 0) &&
                 (*(short *)(*(int *)((int)pfVar19 + *(int *)(iVar9 + 0xbfc)) + uStack_3c4 * 4) == 1
                 )) {
                fStack_360 = (float)puStack_380 * (float)puStack_3d0;
                if (0.95 <= (float)piStack_374 * (float)piStack_3c8 + fStack_360) {
                  pfVar19 = &fStack_340;
                  puVar26 = auStack_2c;
                  puVar27 = &uStack_330;
                  puVar25 = auStack_6c;
                  uVar10 = uStack_3c4;
                  vector_at_12(iStack_39c);
                  vector_at_stride8(uVar10);
                  vec2_add(puVar25,puVar27);
                  uVar7 = vec2_add(puVar26,pfVar19);
                  vector_at_12(iStack_39c);
                  FUN_00642590(uVar7);
                  pfVar19 = &fStack_340;
                  puVar26 = auStack_3c;
                  puVar27 = &uStack_330;
                  puVar25 = auStack_ac;
                  uVar10 = uVar8;
                  vector_at_12(iStack_39c);
                  vector_at_stride8(uVar10);
                  vec2_sub(puVar25,puVar27);
                  uVar7 = vec2_add(puVar26,pfVar19);
                  iVar9 = iStack_39c;
                  vector_at_12(iStack_39c);
                  FUN_00642590(uVar7);
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  uVar7 = arrayElem_stride16(uVar10);
                  vector_at_12(iVar9);
                  std_vector_push_back_16(uVar7);
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  uVar7 = arrayElem_stride16(uVar10);
                  vector_at_12(iVar9);
                  std_vector_push_back_16(uVar7);
                  uVar7 = setPair_b(fStack_3b0,0);
                  vector_at_12(iVar9);
                  FUN_00642590(uVar7);
                  goto LAB_00648432;
                }
                if (*(int *)(iVar9 + 0x860) != 1) {
                  puStack_3d0 = (uint *)((float)puStack_3d0 * (float)pfStack_3cc);
                  piStack_3c8 = (int *)((float)piStack_3c8 * (float)pfStack_3cc);
                  fStack_308 = (float)puStack_380 * (float)pfStack_3cc;
                  fStack_304 = (float)piStack_374 * (float)pfStack_3cc;
                  if (0.0 <= fStack_3ac * fStack_36c + (float)piStack_3d8 * (float)pfStack_3bc) {
                    uStack_1a0 = uStack_330;
                    _fStack_258 = CONCAT44(fStack_304 + (float)piStack_3c8,
                                           fStack_308 + (float)puStack_3d0);
                    uStack_248 = CONCAT44((fStack_304 + (float)piStack_3c8) * 0.5,
                                          (fStack_308 + (float)puStack_3d0) * 0.5);
                    uStack_198 = uStack_248;
                  }
                  else {
                    _fStack_278 = CONCAT44(fStack_304 + (float)piStack_3c8,
                                           fStack_308 + (float)puStack_3d0);
                    uStack_268 = CONCAT44((fStack_304 + (float)piStack_3c8) * 0.5,
                                          (fStack_308 + (float)puStack_3d0) * 0.5);
                    uStack_1a0 = uStack_268;
                    uStack_198 = uStack_330;
                  }
                  fStack_238 = (float)*(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4);
                  fStack_238 = (float)puStack_3d0 + fStack_238;
                  fStack_234 = (float)((ulonglong)
                                       *(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4) >> 0x20)
                  ;
                  fStack_234 = (float)piStack_3c8 + fStack_234;
                  _fStack_228 = CONCAT44(fStack_234 + fStack_36c * fStack_35c,
                                         fStack_238 + (float)pfStack_3bc * fStack_35c);
                  puStack_328 = puStack_3d0;
                  piStack_324 = piStack_3c8;
                  FUN_00642590(&fStack_228);
                  uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piStack_38c) + (int)piVar13);
                  fStack_218 = (float)uVar1;
                  fStack_218 = fStack_218 - (float)puStack_3d0;
                  fStack_214 = (float)((ulonglong)uVar1 >> 0x20);
                  fStack_214 = fStack_214 - (float)piStack_3c8;
                  _fStack_208 = CONCAT44(fStack_214 + fStack_33c,fStack_218 + fStack_340);
                  FUN_00642590(&fStack_208);
                  iVar9 = uStack_3c4 * 0x10;
                  std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + iVar9);
                  std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + iVar9);
                  afStack_130[4] = fStack_3b0;
                  uStack_11c = 0;
                  FUN_00642590(afStack_130 + 4);
                  afStack_118[2] = fStack_3b0;
                  uStack_10c = 0x3f800000;
                  FUN_00642590(afStack_118 + 2);
                  piVar13 = piStack_38c;
                  uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piStack_38c) + (int)piStack_3c0);
                  fStack_1f8 = (float)uVar1;
                  fStack_1f8 = (float)uStack_1a0 + fStack_1f8;
                  fStack_1f4 = (float)((ulonglong)uVar1 >> 0x20);
                  fStack_1f4 = fStack_1f4 + uStack_1a0._4_4_;
                  _fStack_1e8 = CONCAT44(fStack_1f4 + fStack_33c,fStack_1f8 + fStack_340);
                  FUN_00642590(&fStack_1e8);
                  uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piVar13) + (int)piStack_3c0);
                  fStack_338 = (float)uVar1;
                  fStack_334 = (float)((ulonglong)uVar1 >> 0x20);
                  _fStack_338 = CONCAT44(fStack_334 - uStack_198._4_4_,
                                         fStack_338 - (float)uStack_198);
                  uVar7 = vec2_add(auStack_14,&fStack_340);
                  iVar9 = iStack_39c;
                  vector_at_12(iStack_39c);
                  FUN_00642590(uVar7);
                  uVar8 = uStack_3c4;
                  uVar10 = uStack_3c4;
                  vector_at_12(iVar9);
                  uVar7 = arrayElem_stride16(uVar10);
                  vector_at_12(iVar9);
                  std_vector_push_back_16(uVar7);
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  uVar7 = arrayElem_stride16(uVar10);
                  vector_at_12(iVar9);
                  std_vector_push_back_16(uVar7);
                  uVar7 = setPair_b(fStack_3b0,0);
                  vector_at_12(iVar9);
                  FUN_00642590(uVar7);
                  uVar7 = setPair_b(fStack_3b0,0x3f800000);
                  vector_at_12(iVar9);
                  FUN_00642590(uVar7);
                  pfVar19 = &fStack_340;
                  puVar26 = auStack_5c;
                  pfVar17 = &fStack_308;
                  puVar25 = auStack_9c;
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  vector_at_stride8(uVar10);
                  vec2_add(puVar25,pfVar17);
                  uVar7 = vec2_add(puVar26,pfVar19);
                  vector_at_12(iVar9);
                  FUN_00642590(uVar7);
                  pfVar19 = &fStack_340;
                  puVar26 = auStack_1c;
                  pfVar17 = &fStack_308;
                  puVar25 = auStack_8c;
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  vector_at_stride8(uVar10);
                  vec2_sub(puVar25,pfVar17);
                  uVar7 = vec2_add(puVar26,pfVar19);
                  vector_at_12(iVar9);
                  FUN_00642590(uVar7);
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  uVar7 = arrayElem_stride16(uVar10);
                  vector_at_12(iVar9);
                  std_vector_push_back_16(uVar7);
                  uVar10 = uVar8;
                  vector_at_12(iVar9);
                  uVar7 = arrayElem_stride16(uVar10);
                  vector_at_12(iVar9);
                  std_vector_push_back_16(uVar7);
                  uVar7 = setPair_b(fStack_3b0,0);
                  vector_at_12(iVar9);
                  FUN_00642590(uVar7);
                  goto LAB_00648432;
                }
                dVar24 = (double)((float)piStack_374 * (float)piStack_3c8 + fStack_360);
                libm_sse2_acos_precise();
                fVar23 = (float)dVar24 * 57.29578;
                pfStack_370 = (float *)(int)((ABS(fVar23) / 180.0) * 20.0);
                fVar21 = fStack_3ac * fStack_36c + (float)piStack_3d8 * (float)pfStack_3bc;
                bStack_3d9 = fVar21 < 0.0;
                if (fVar21 < 0.0) {
                  fVar23 = -fVar23;
                }
                piStack_3d8 = (int *)(fVar23 / (float)(int)pfStack_370);
                puStack_380 = (uint *)((float)puStack_380 * (float)pfStack_3cc);
                puStack_3d0 = (uint *)((float)puStack_3d0 * (float)pfStack_3cc);
                piStack_374 = (int *)((float)piStack_374 * (float)pfStack_3cc);
                fStack_290 = (float)*(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4);
                fStack_290 = (float)puStack_3d0 + fStack_290;
                piStack_3c8 = (int *)((float)piStack_3c8 * (float)pfStack_3cc);
                fStack_28c = (float)((ulonglong)*(undefined8 *)((int)piStack_3c0 + (int)puStack_3d4)
                                    >> 0x20);
                fStack_28c = (float)piStack_3c8 + fStack_28c;
                _fStack_210 = CONCAT44(fStack_28c + fStack_33c,fStack_290 + fStack_340);
                puStack_328 = puStack_3d0;
                piStack_324 = piStack_3c8;
                FUN_00642590(&fStack_210);
                uVar1 = *(undefined8 *)
                         (*(int *)((int)pfVar19 + *(int *)(iVar9 + 0xba8)) + (int)piStack_3c0);
                fStack_280 = (float)uVar1;
                fStack_280 = fStack_280 - (float)puStack_3d0;
                fStack_27c = (float)((ulonglong)uVar1 >> 0x20);
                fStack_27c = fStack_27c - (float)piStack_3c8;
                _fStack_1d0 = CONCAT44(fStack_27c + fStack_33c,fStack_280 + fStack_340);
                FUN_00642590(&fStack_1d0);
                uVar8 = uStack_3c4;
                puStack_3d4 = (undefined4 *)(uStack_3c4 * 0x10);
                std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + (int)puStack_3d4);
                std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + (int)puStack_3d4);
                afStack_150[2] = fStack_3b0;
                uStack_144 = 0;
                FUN_00642590(afStack_150 + 2);
                afStack_108[0] = fStack_3b0;
                afStack_108[1] = 1.0;
                FUN_00642590(afStack_108);
                mat4_identity();
                piStack_3d8 = (int *)((float)piStack_3d8 * 0.017453292);
                dVar24 = (double)(float)piStack_3d8;
                libm_sse2_cos_precise();
                piStack_3c8 = (int *)(float)dVar24;
                dVar24 = (double)(float)piStack_3d8;
                libm_sse2_sin_precise();
                piVar13 = piStack_38c;
                fVar23 = (float)dVar24;
                fStack_348 = fVar23 * fStack_e8 + (float)piStack_3c8 * fStack_f8;
                fStack_3ac = (float)piStack_3c8 * fStack_e8 - fVar23 * fStack_f8;
                fStack_344 = fVar23 * fStack_e4 + (float)piStack_3c8 * fStack_f4;
                fStack_34c = (float)piStack_3c8 * fStack_e4 - fVar23 * fStack_f4;
                fStack_360 = fVar23 * fStack_dc + (float)piStack_3c8 * fStack_ec;
                piStack_3c8 = (int *)((float)piStack_3c8 * fStack_dc - fVar23 * fStack_ec);
                if (bStack_3d9 == false) {
                  _fStack_2f0 = CONCAT44((float)piStack_374 + (float)piStack_324,
                                         (float)puStack_380 + (float)puStack_328);
                  uStack_1c8 = CONCAT44(((float)piStack_374 + (float)piStack_324) * 0.5,
                                        ((float)puStack_380 + (float)puStack_328) * 0.5);
                  uStack_2f8 = uStack_1c8;
                  uStack_300 = CONCAT44(piStack_324,puStack_328);
                }
                else {
                  _fStack_270 = CONCAT44((float)piStack_374 + (float)piStack_324,
                                         (float)puStack_380 + (float)puStack_328);
                  uStack_200 = CONCAT44(((float)piStack_374 + (float)piStack_324) * 0.5,
                                        ((float)puStack_380 + (float)puStack_328) * 0.5);
                  uStack_300 = uStack_200;
                  uStack_2f8 = CONCAT44(piStack_324,puStack_328);
                }
                if (1 < (int)pfStack_370) {
                  fStack_36c = (float)((int)pfStack_370 + -1);
                  pfStack_3bc = uStack_300._4_4_;
                  pfStack_3cc = (float *)uStack_300;
                  piStack_3d8 = uStack_2f8._4_4_;
                  puStack_3d0 = (uint *)uStack_2f8;
                  do {
                    if (bStack_3d9 == false) {
                      fStack_170 = (float)pfStack_3bc * fStack_3ac + (float)pfStack_3cc * fStack_348
                                   + fStack_c8;
                      fStack_16c = (float)pfStack_3bc * fStack_34c + (float)pfStack_3cc * fStack_344
                                   + fStack_c4;
                      fVar23 = 1.0 / ((float)pfStack_3bc * (float)piStack_3c8 +
                                      (float)pfStack_3cc * fStack_360 + fStack_bc);
                      pfStack_3cc = (float *)(fStack_170 * fVar23);
                      pfStack_3bc = (float *)(fStack_16c * fVar23);
                      uStack_1f0 = CONCAT44(pfStack_3bc,pfStack_3cc);
                      uStack_300 = uStack_1f0;
                    }
                    else {
                      fStack_188 = (float)piStack_3d8 * fStack_3ac + (float)puStack_3d0 * fStack_348
                                   + fStack_c8;
                      fStack_184 = (float)piStack_3d8 * fStack_34c + (float)puStack_3d0 * fStack_344
                                   + fStack_c4;
                      fVar23 = 1.0 / ((float)piStack_3d8 * (float)piStack_3c8 +
                                      (float)puStack_3d0 * fStack_360 + fStack_bc);
                      puStack_3d0 = (uint *)(fStack_188 * fVar23);
                      piStack_3d8 = (int *)(fStack_184 * fVar23);
                      uStack_250 = CONCAT44(piStack_3d8,puStack_3d0);
                      uStack_2f8 = uStack_250;
                    }
                    uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piVar13) + (int)piStack_3c0);
                    fStack_240 = (float)uVar1;
                    fStack_240 = fStack_240 + (float)pfStack_3cc;
                    fStack_23c = (float)((ulonglong)uVar1 >> 0x20);
                    fStack_23c = fStack_23c + (float)pfStack_3bc;
                    _fStack_2e0 = CONCAT44(fStack_23c + fStack_33c,fStack_240 + fStack_340);
                    FUN_00642590(&fStack_2e0);
                    uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piVar13) + (int)piStack_3c0);
                    fStack_2d8 = (float)uVar1;
                    fStack_2d8 = fStack_2d8 - (float)puStack_3d0;
                    fStack_2d4 = (float)((ulonglong)uVar1 >> 0x20);
                    fStack_2d4 = fStack_2d4 - (float)piStack_3d8;
                    _fStack_2c8 = CONCAT44(fStack_2d4 + fStack_33c,fStack_2d8 + fStack_340);
                    FUN_00642590(&fStack_2c8);
                    std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + (int)puStack_3d4);
                    std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + (int)puStack_3d4);
                    afStack_160[0] = fStack_3b0;
                    afStack_160[1] = 0.0;
                    FUN_00642590(afStack_160);
                    afStack_150[0] = fStack_3b0;
                    afStack_150[1] = 1.0;
                    FUN_00642590(afStack_150);
                    fStack_36c = (float)((int)fStack_36c + -1);
                  } while (fStack_36c != 0.0);
                  fStack_36c = 0.0;
                  uVar8 = uStack_3c4;
                }
                uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piStack_38c) + uVar8 * 8);
                fStack_2b8 = (float)uVar1;
                fStack_2b8 = (float)puStack_380 + fStack_2b8;
                fStack_2b4 = (float)((ulonglong)uVar1 >> 0x20);
                fStack_2b4 = (float)piStack_374 + fStack_2b4;
                _fStack_2a8 = CONCAT44(fStack_2b4 + fStack_33c,fStack_2b8 + fStack_340);
                FUN_00642590(&fStack_2a8);
                uVar1 = *(undefined8 *)(*(int *)((int)pfVar19 + *piStack_38c) + uVar8 * 8);
                fStack_298 = (float)uVar1;
                fStack_298 = fStack_298 - (float)puStack_380;
                fStack_294 = (float)((ulonglong)uVar1 >> 0x20);
                fStack_294 = fStack_294 - (float)piStack_374;
                _fStack_288 = CONCAT44(fStack_294 + fStack_33c,fStack_298 + fStack_340);
                FUN_00642590(&fStack_288);
                std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + (int)puStack_3d4);
                std_vector_push_back_16(*(int *)((int)pfVar19 + *piStack_3a4) + (int)puStack_3d4);
                afStack_140[0] = fStack_3b0;
                afStack_140[1] = 0.0;
                FUN_00642590(afStack_140);
                afStack_130[0] = fStack_3b0;
                pfVar19 = afStack_130;
                afStack_130[1] = 1.0;
              }
              else {
                pfVar19 = &fStack_340;
                puVar26 = auStack_84;
                puVar27 = &uStack_330;
                puVar25 = auStack_74;
                uVar10 = uStack_3c4;
                vector_at_12(iStack_39c);
                vector_at_stride8(uVar10);
                vec2_add(puVar25,puVar27);
                uVar7 = vec2_add(puVar26,pfVar19);
                vector_at_12(iStack_39c);
                FUN_00642590(uVar7);
                pfVar19 = &fStack_340;
                puVar26 = auStack_64;
                puVar27 = &uStack_330;
                puVar25 = auStack_54;
                uVar10 = uVar8;
                vector_at_12(iStack_39c);
                vector_at_stride8(uVar10);
                vec2_sub(puVar25,puVar27);
                uVar7 = vec2_add(puVar26,pfVar19);
                iVar9 = iStack_39c;
                vector_at_12(iStack_39c);
                FUN_00642590(uVar7);
                uVar10 = uVar8;
                vector_at_12(iVar9);
                uVar7 = arrayElem_stride16(uVar10);
                vector_at_12(iVar9);
                std_vector_push_back_16(uVar7);
                uVar10 = uVar8;
                vector_at_12(iVar9);
                uVar7 = arrayElem_stride16(uVar10);
                vector_at_12(iVar9);
                std_vector_push_back_16(uVar7);
                uVar7 = setPair_b(fStack_3b0,0);
                vector_at_12(iVar9);
                FUN_00642590(uVar7);
LAB_00648432:
                pfVar19 = (float *)setPair_b(fStack_3b0,0x3f800000);
                vector_at_12(iVar9);
              }
              FUN_00642590(pfVar19);
            }
            iVar9 = iStack_39c;
            vector_at_12(iStack_39c);
            uVar10 = std_vector_size_4();
            uVar10 = (uVar8 + 1) % uVar10;
            vector_at_12(iVar9);
            puVar14 = (undefined4 *)vector_at_stride4(uVar10);
            uVar10 = uStack_3c4;
            vector_at_12(iStack_39c);
            puVar16 = (undefined4 *)vector_at_stride4(uVar10);
            uVar7 = *puVar14;
            uVar28 = *puVar16;
            vector_at_12(iStack_39c);
            uVar10 = std_vector_size_8(uVar28,uVar7);
            iVar9 = iStack_39c;
            uVar10 = (uVar8 + 1) % uVar10;
            vector_at_12(iStack_39c);
            uVar7 = vector_at_stride8(uVar10);
            puVar26 = auStack_310;
            uVar8 = uStack_3c4;
            vector_at_12(iVar9);
            vector_at_stride8(uVar8);
            vec2_sub(puVar26,uVar7);
            fVar20 = (float10)vec2_length();
            fVar20 = (float10)FUN_006426d0((float)fVar20);
            pfStack_370 = (float *)(float)fVar20;
            fStack_3b0 = (float)pfStack_370 + fStack_3b0;
            uStack_384 = uStack_384 + 1;
            in_ECX = local_388;
            pfVar19 = pfStack_394;
          } while ((int)uStack_384 < (int)pvStack_3b4);
        }
      }
      iStack_39c = iStack_39c + 1;
    } while (iStack_39c < (*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc);
  }
  cVar6 = FUN_00641b60();
  if (cVar6 == '\0') {
    cVar6 = FUN_006423f0();
    if ((cVar6 == '\0') && (-1 < (int)pfStack_3b8)) {
      pvStack_3b4 = (void *)((int)pfStack_3b8 * 0x60 + 0x904 + in_ECX);
      iVar9 = FUN_00642a90();
      uVar8 = in_ECX + 0x878;
      if (iVar9 == 0) {
        uVar7 = setPair_b(0,0);
        vec2_copy(uVar7);
        uVar7 = setPair_b(0,0);
        vec2_copy(uVar7);
        goto LAB_006487d2;
      }
      iVar9 = FUN_0063d6f0(0);
      vec2_copy(**(undefined4 **)(iVar9 + 8));
      vec2_copy(uVar8);
      uStack_384 = 0;
      iVar9 = FUN_00642a90();
      if (iVar9 < 1) goto LAB_006487d2;
      pfStack_3b8 = (float *)arrayElem_stride4(0);
      pfStack_370 = (float *)arrayElem_stride4(1);
      pfStack_364 = (float *)arrayElem_stride4(0);
      pfVar19 = (float *)arrayElem_stride4(1);
      do {
        iVar9 = 8;
        do {
          iVar12 = FUN_0063d6f0(uStack_384);
          pfStack_394 = (float *)**(undefined4 **)(iVar12 + iVar9);
          pfStack_368 = (float *)arrayElem_stride4(0);
          if (*pfStack_368 < *pfStack_3b8) {
            *pfStack_3b8 = *pfStack_368;
          }
          pfVar17 = (float *)arrayElem_stride4(1);
          if (*pfVar17 < *pfStack_370) {
            *pfStack_370 = *pfVar17;
          }
          fVar23 = *pfStack_368;
          if (*pfStack_364 <= fVar23 && fVar23 != *pfStack_364) {
            *pfStack_364 = fVar23;
          }
          fVar23 = *pfVar17;
          if (*pfVar19 <= fVar23 && fVar23 != *pfVar19) {
            *pfVar19 = fVar23;
          }
          iVar9 = iVar9 + 4;
        } while (iVar9 < 0x10);
        uVar8 = uStack_384 + 1;
        uStack_384 = uVar8;
        iVar9 = FUN_00642a90();
        in_ECX = local_388;
      } while ((int)uVar8 < iVar9);
    }
    else {
      uStack_37c = in_ECX + 0x878;
      uVar7 = setPair_b(0,0);
      vec2_copy(uVar7);
      piStack_390 = (int *)(in_ECX + 0x880);
      uVar7 = setPair_b(0,0);
      vec2_copy(uVar7);
      bStack_3d9 = true;
      piStack_3d8 = (int *)0x0;
      iVar9 = std_vector_size_stride0xc();
      if (0 < iVar9) {
        piVar13 = (int *)0x0;
        do {
          pvStack_3b4 = (void *)0x0;
          vector_at_12(piVar13);
          iVar9 = std_vector_size_8();
          if (0 < iVar9) {
            do {
              pvVar29 = pvStack_3b4;
              vector_at_12(piStack_3d8);
              uVar7 = vector_at_stride8(pvVar29);
              vec2_copy(uVar7);
              if (bStack_3d9 == false) {
                pfStack_394 = (float *)arrayElem_stride4(0);
                pfStack_3b8 = (float *)*pfStack_394;
                pfVar19 = (float *)arrayElem_stride4(0);
                if ((float)pfStack_3b8 < *pfVar19) {
                  *pfVar19 = (float)pfStack_3b8;
                }
                pfStack_370 = (float *)arrayElem_stride4(1);
                pfStack_3b8 = (float *)*pfStack_370;
                pfVar19 = (float *)arrayElem_stride4(1);
                if ((float)pfStack_3b8 < *pfVar19) {
                  *pfVar19 = (float)pfStack_3b8;
                }
                pfStack_3b8 = (float *)*pfStack_394;
                pfVar19 = (float *)arrayElem_stride4(0);
                if (*pfVar19 <= (float)pfStack_3b8 && (float)pfStack_3b8 != *pfVar19) {
                  *pfVar19 = (float)pfStack_3b8;
                }
                pfStack_3b8 = (float *)*pfStack_370;
                pfVar19 = (float *)arrayElem_stride4(1);
                if (*pfVar19 <= (float)pfStack_3b8 && (float)pfStack_3b8 != *pfVar19) {
                  *pfVar19 = (float)pfStack_3b8;
                }
              }
              else {
                vec2_copy(&fStack_338);
                vec2_copy(&fStack_338);
                bStack_3d9 = false;
              }
              pvStack_3b4 = (void *)((int)pvStack_3b4 + 1);
              vector_at_12(piStack_3d8);
              iVar9 = std_vector_size_8();
            } while ((int)pvStack_3b4 < iVar9);
          }
          piStack_3d8 = (int *)((int)piStack_3d8 + 1);
          iVar9 = std_vector_size_stride0xc();
          piVar13 = piStack_3d8;
          in_ECX = local_388;
          uVar8 = uStack_37c;
        } while ((int)piStack_3d8 < iVar9);
        goto LAB_006487d2;
      }
    }
  }
  else {
    uStack_37c = in_ECX + 0x878;
    uVar7 = setPair_b(0,0);
    vec2_copy(uVar7);
    piStack_390 = (int *)(in_ECX + 0x880);
    uVar7 = setPair_b(0,0);
    vec2_copy(uVar7);
    bStack_3d9 = true;
    piStack_3d8 = (int *)0x0;
    iVar9 = std_vector_size_stride0xc();
    if (0 < iVar9) {
      piVar13 = (int *)0x0;
      do {
        pvStack_3b4 = (void *)0x0;
        vector_at_12(piVar13);
        iVar9 = std_vector_size_8();
        if (0 < iVar9) {
          do {
            pvVar29 = pvStack_3b4;
            vector_at_12(piStack_3d8);
            uVar7 = vector_at_stride8(pvVar29);
            vec2_copy(uVar7);
            if (bStack_3d9 == false) {
              pfStack_370 = (float *)arrayElem_stride4(0);
              pfStack_394 = (float *)*pfStack_370;
              pfVar19 = (float *)arrayElem_stride4(0);
              if ((float)pfStack_394 < *pfVar19) {
                *pfVar19 = (float)pfStack_394;
              }
              pfStack_368 = (float *)arrayElem_stride4(1);
              pfStack_394 = (float *)*pfStack_368;
              pfVar19 = (float *)arrayElem_stride4(1);
              if ((float)pfStack_394 < *pfVar19) {
                *pfVar19 = (float)pfStack_394;
              }
              pfStack_394 = (float *)*pfStack_370;
              pfVar19 = (float *)arrayElem_stride4(0);
              if (*pfVar19 <= (float)pfStack_394 && (float)pfStack_394 != *pfVar19) {
                *pfVar19 = (float)pfStack_394;
              }
              pfStack_394 = (float *)*pfStack_368;
              pfVar19 = (float *)arrayElem_stride4(1);
              if (*pfVar19 <= (float)pfStack_394 && (float)pfStack_394 != *pfVar19) {
                *pfVar19 = (float)pfStack_394;
              }
            }
            else {
              vec2_copy(&fStack_338);
              vec2_copy(&fStack_338);
              bStack_3d9 = false;
            }
            pvStack_3b4 = (void *)((int)pvStack_3b4 + 1);
            vector_at_12(piStack_3d8);
            iVar9 = std_vector_size_8();
          } while ((int)pvStack_3b4 < iVar9);
        }
        piStack_3d8 = (int *)((int)piStack_3d8 + 1);
        iVar9 = std_vector_size_stride0xc();
        piVar13 = piStack_3d8;
        in_ECX = local_388;
      } while ((int)piStack_3d8 < iVar9);
    }
  }
  uVar8 = in_ECX + 0x878;
LAB_006487d2:
  cVar6 = FUN_00642400();
  if (cVar6 != '\0') {
    pfVar19 = &fStack_308;
    computeCellOffset(pfVar19,uVar8);
    math_mat3_transform_point2d(pfVar19,uVar8);
    pfStack_3cc = (float *)arrayElem_stride4(0);
    pfStack_3b8 = (float *)*pfStack_3cc;
    pfStack_394 = (float *)arrayElem_stride4(0);
    if ((float)pfStack_3b8 < *pfStack_394) {
      *pfStack_394 = (float)pfStack_3b8;
    }
    pfStack_3bc = (float *)arrayElem_stride4(1);
    pfStack_3b8 = (float *)*pfStack_3bc;
    pfStack_370 = (float *)arrayElem_stride4(1);
    if ((float)pfStack_3b8 < *pfStack_370) {
      *pfStack_370 = (float)pfStack_3b8;
    }
    iVar9 = in_ECX + 0x880;
    pfStack_3b8 = (float *)*pfStack_3cc;
    pfStack_368 = (float *)arrayElem_stride4(0);
    if (*pfStack_368 <= (float)pfStack_3b8 && (float)pfStack_3b8 != *pfStack_368) {
      *pfStack_368 = (float)pfStack_3b8;
    }
    pfStack_3b8 = (float *)*pfStack_3bc;
    pfStack_364 = (float *)arrayElem_stride4(1);
    if (*pfStack_364 <= (float)pfStack_3b8 && (float)pfStack_3b8 != *pfStack_364) {
      *pfStack_364 = (float)pfStack_3b8;
    }
    puVar26 = auStack_310;
    computeCellOffset(puVar26,iVar9);
    uVar7 = math_mat3_transform_point2d(puVar26,iVar9);
    vec2_copy(uVar7);
    if (*pfStack_3cc < *pfStack_394) {
      *pfStack_394 = *pfStack_3cc;
    }
    if (*pfStack_3bc < *pfStack_370) {
      *pfStack_370 = *pfStack_3bc;
    }
    fVar23 = *pfStack_3cc;
    if (*pfStack_368 <= fVar23 && fVar23 != *pfStack_368) {
      *pfStack_368 = fVar23;
    }
    fVar23 = *pfStack_3bc;
    if (*pfStack_364 <= fVar23 && fVar23 != *pfStack_364) {
      *pfStack_364 = fVar23;
    }
  }
  FUN_00642570();
  FUN_0062de10(1);
  FUN_00648d60();
  __security_check_cookie(local_c ^ (uint)auStack_3e0);
  return;
}




/* Global::FUN_00648d60 @ 00648d60 */

void FUN_00648d60(void)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  float *pfVar11;
  undefined8 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  int *in_ECX;
  int iVar15;
  float *pfVar16;
  int iVar17;
  undefined4 *puVar18;
  uint uVar19;
  float fVar20;
  undefined8 *puVar21;
  int iVar22;
  int *piVar23;
  undefined4 *puVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float local_164;
  float local_160 [2];
  float local_158 [5];
  int local_144;
  float local_140;
  undefined1 local_139;
  float local_138;
  int *local_134;
  int *local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  undefined1 local_110 [64];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  float local_b0;
  float fStack_ac;
  float local_a8;
  float fStack_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  float local_78;
  float fStack_74;
  float local_70 [4];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  float local_48 [4];
  undefined8 local_38;
  float local_30;
  float fStack_2c;
  float local_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float local_18;
  float fStack_14;
  float local_10;
  float fStack_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_130 = in_ECX;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x307));
  *(undefined1 *)((int)in_ECX + 0xb2d) = 1;
  if (in_ECX[0x304] != 0) {
    *(int *)(in_ECX[0x304] + 0xbc) = in_ECX[0x303];
  }
  if (in_ECX[0x305] != 0) {
    *(int *)(in_ECX[0x305] + 0xbc) = in_ECX[0x303];
  }
  if (in_ECX[0x306] != 0) {
    *(int *)(in_ECX[0x306] + 0xbc) = in_ECX[0x303];
  }
  if (((*(byte *)(in_ECX + 0x217) & 1) != 0) && ((*(byte *)(in_ECX + 0x303) & 1) != 0)) {
    if (in_ECX[0x304] != 0) {
      puVar2 = (uint *)(in_ECX[0x304] + 0xbc);
      *puVar2 = *puVar2 | 8;
    }
    if (in_ECX[0x305] != 0) {
      puVar2 = (uint *)(in_ECX[0x305] + 0xbc);
      *puVar2 = *puVar2 | 8;
    }
    if (in_ECX[0x306] != 0) {
      puVar2 = (uint *)(in_ECX[0x306] + 0xbc);
      *puVar2 = *puVar2 | 8;
    }
  }
  in_ECX[0x303] = 0;
  GameController_update_render_targets();
  if (in_ECX[0x304] != 0) {
    if (((*(byte *)(in_ECX + 0x217) & 1) == 0) || ((~(byte)((uint)in_ECX[0x217] >> 2) & 1) == 0)) {
      uVar10 = 0;
    }
    else {
      uVar10 = 1;
    }
    *(undefined1 *)(in_ECX[0x304] + 100) = uVar10;
    iVar22 = in_ECX[0x2c9];
    if (iVar22 != 0) goto LAB_0064942b;
    if ((*(byte *)(in_ECX + 0x217) & 1) == 0) {
      std_vector_resize((*(int **)in_ECX[0x2a])[1] - **(int **)in_ECX[0x2a] >> 3);
      std_vector_resize_42bf80((*(int **)in_ECX[0x2a])[1] - **(int **)in_ECX[0x2a] >> 3);
      std_vector_resize((*(int **)in_ECX[0x2a])[1] - **(int **)in_ECX[0x2a] >> 3);
      *(undefined4 *)(in_ECX[0x304] + 0x38) = *(undefined4 *)(in_ECX[0x304] + 0x34);
      local_118 = 0.0;
      if (0 < (int)((*(int **)in_ECX[0x2a])[1] - **(int **)in_ECX[0x2a] & 0xfffffff8U)) {
        iVar22 = 0;
        do {
          iVar17 = (int)local_118 * 8;
          iVar15 = **(int **)(in_ECX[0x2a] + in_ECX[0x1f] * 4);
          iVar4 = *(int *)(in_ECX[0x304] + 4);
          *(undefined4 *)(iVar4 + iVar17) = *(undefined4 *)(iVar15 + iVar17);
          *(undefined4 *)(iVar4 + 4 + iVar17) = *(undefined4 *)(iVar15 + 4 + iVar17);
          puVar18 = (undefined4 *)(**(int **)(in_ECX[0x56] + in_ECX[0x4b] * 4) + iVar22);
          iVar15 = *(int *)(in_ECX[0x304] + 0x1c);
          *(undefined4 *)(iVar15 + iVar22) = *puVar18;
          iVar15 = iVar15 + iVar22;
          iVar22 = iVar22 + 0x10;
          *(undefined4 *)(iVar15 + 4) = puVar18[1];
          *(undefined4 *)(iVar15 + 8) = puVar18[2];
          *(undefined4 *)(iVar15 + 0xc) = puVar18[3];
          iVar15 = **(int **)(in_ECX[0x40] + in_ECX[0x35] * 4);
          iVar4 = *(int *)(in_ECX[0x304] + 0x10);
          *(undefined4 *)(iVar4 + iVar17) = *(undefined4 *)(iVar15 + iVar17);
          *(undefined4 *)(iVar4 + 4 + iVar17) = *(undefined4 *)(iVar15 + 4 + iVar17);
          local_118 = (float)((int)local_118 + 1);
        } while ((int)local_118 < (*(int **)in_ECX[0x2a])[1] - **(int **)in_ECX[0x2a] >> 3);
      }
      local_118 = 0.0;
      if (0 < (in_ECX[0x21c] - in_ECX[0x21b]) / 0xc) {
        local_138 = 0.0;
        do {
          piVar23 = (int *)(in_ECX[0x21b] + (int)local_138);
          pfVar16 = (float *)*piVar23;
          local_128 = 1.4013e-45;
          local_134 = piVar23;
          if (1 < (piVar23[1] - (int)pfVar16 >> 2) + -1) {
            do {
              local_164 = *pfVar16;
              iVar22 = in_ECX[0x304];
              pfVar16 = *(float **)(iVar22 + 0x38);
              local_120 = local_164;
              if (&local_164 < pfVar16) {
                pfVar11 = *(float **)(iVar22 + 0x34);
                if (&local_164 < pfVar11) goto LAB_006490e1;
                pfVar5 = *(float **)(iVar22 + 0x3c);
                if ((pfVar16 == pfVar5) && ((int)pfVar5 - (int)pfVar16 >> 2 == 0)) {
                  iVar17 = (int)pfVar16 - *(int *)(iVar22 + 0x34) >> 2;
                  if (iVar17 == 0x3fffffff) goto LAB_00649419;
                  local_114 = (float)(iVar17 + 1);
                  uVar19 = (int)pfVar5 - *(int *)(iVar22 + 0x34) >> 2;
                  if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_114) {
                    fVar20 = local_114;
                  }
                  std_vector_grow_realloc_stride4(fVar20);
                }
                piVar23 = local_134;
                if (*(undefined4 **)(iVar22 + 0x38) != (undefined4 *)0x0) {
                  **(undefined4 **)(iVar22 + 0x38) =
                       *(undefined4 *)
                        (*(int *)(iVar22 + 0x34) + ((int)&local_164 - (int)pfVar11 >> 2) * 4);
                }
              }
              else {
LAB_006490e1:
                pfVar11 = *(float **)(iVar22 + 0x3c);
                if ((pfVar16 == pfVar11) && ((int)pfVar11 - (int)pfVar16 >> 2 == 0)) {
                  iVar17 = (int)pfVar16 - *(int *)(iVar22 + 0x34) >> 2;
                  if (iVar17 == 0x3fffffff) goto LAB_00649419;
                  local_114 = (float)(iVar17 + 1);
                  uVar19 = (int)pfVar11 - *(int *)(iVar22 + 0x34) >> 2;
                  if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_114) {
                    fVar20 = local_114;
                  }
                  std_vector_grow_realloc_stride4(fVar20);
                }
                if (*(float **)(iVar22 + 0x38) != (float *)0x0) {
                  **(float **)(iVar22 + 0x38) = local_120;
                }
              }
              *(int *)(iVar22 + 0x38) = *(int *)(iVar22 + 0x38) + 4;
              iVar22 = in_ECX[0x304];
              local_158[0] = *(float *)(*piVar23 + (int)local_128 * 4);
              pfVar16 = *(float **)(iVar22 + 0x38);
              local_120 = local_158[0];
              if (local_158 < pfVar16) {
                pfVar11 = *(float **)(iVar22 + 0x34);
                if (local_158 < pfVar11) goto LAB_0064920f;
                pfVar5 = *(float **)(iVar22 + 0x3c);
                if ((pfVar16 == pfVar5) && ((int)pfVar5 - (int)pfVar16 >> 2 == 0)) {
                  iVar17 = (int)pfVar16 - *(int *)(iVar22 + 0x34) >> 2;
                  if (iVar17 == 0x3fffffff) goto LAB_00649419;
                  local_114 = (float)(iVar17 + 1);
                  uVar19 = (int)pfVar5 - *(int *)(iVar22 + 0x34) >> 2;
                  if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_114) {
                    fVar20 = local_114;
                  }
                  std_vector_grow_realloc_stride4(fVar20);
                }
                piVar23 = local_134;
                if (*(undefined4 **)(iVar22 + 0x38) != (undefined4 *)0x0) {
                  **(undefined4 **)(iVar22 + 0x38) =
                       *(undefined4 *)
                        (*(int *)(iVar22 + 0x34) + ((int)local_158 - (int)pfVar11 >> 2) * 4);
                }
              }
              else {
LAB_0064920f:
                pfVar11 = *(float **)(iVar22 + 0x3c);
                if ((pfVar16 == pfVar11) && ((int)pfVar11 - (int)pfVar16 >> 2 == 0)) {
                  iVar17 = (int)pfVar16 - *(int *)(iVar22 + 0x34) >> 2;
                  if (iVar17 == 0x3fffffff) goto LAB_00649419;
                  local_114 = (float)(iVar17 + 1);
                  uVar19 = (int)pfVar11 - *(int *)(iVar22 + 0x34) >> 2;
                  if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_114) {
                    fVar20 = local_114;
                  }
                  std_vector_grow_realloc_stride4(fVar20);
                }
                if (*(float **)(iVar22 + 0x38) != (float *)0x0) {
                  **(float **)(iVar22 + 0x38) = local_120;
                }
              }
              *(int *)(iVar22 + 0x38) = *(int *)(iVar22 + 0x38) + 4;
              iVar22 = in_ECX[0x304];
              local_160[0] = *(float *)(*piVar23 + 4 + (int)local_128 * 4);
              pfVar16 = *(float **)(iVar22 + 0x38);
              local_120 = local_160[0];
              if (local_160 < pfVar16) {
                pfVar11 = *(float **)(iVar22 + 0x34);
                if (local_160 < pfVar11) goto LAB_0064933e;
                pfVar5 = *(float **)(iVar22 + 0x3c);
                if ((pfVar16 == pfVar5) && ((int)pfVar5 - (int)pfVar16 >> 2 == 0)) {
                  iVar17 = (int)pfVar16 - *(int *)(iVar22 + 0x34) >> 2;
                  if (iVar17 == 0x3fffffff) goto LAB_00649419;
                  local_114 = (float)(iVar17 + 1);
                  uVar19 = (int)pfVar5 - *(int *)(iVar22 + 0x34) >> 2;
                  if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_114) {
                    fVar20 = local_114;
                  }
                  std_vector_grow_realloc_stride4(fVar20);
                }
                piVar23 = local_134;
                if (*(undefined4 **)(iVar22 + 0x38) != (undefined4 *)0x0) {
                  **(undefined4 **)(iVar22 + 0x38) =
                       *(undefined4 *)
                        (*(int *)(iVar22 + 0x34) + ((int)local_160 - (int)pfVar11 >> 2) * 4);
                }
              }
              else {
LAB_0064933e:
                pfVar11 = *(float **)(iVar22 + 0x3c);
                if ((pfVar16 == pfVar11) && ((int)pfVar11 - (int)pfVar16 >> 2 == 0)) {
                  iVar17 = (int)pfVar16 - *(int *)(iVar22 + 0x34) >> 2;
                  if (iVar17 == 0x3fffffff) goto LAB_00649419;
                  local_114 = (float)(iVar17 + 1);
                  uVar19 = (int)pfVar11 - *(int *)(iVar22 + 0x34) >> 2;
                  if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_114) {
                    fVar20 = local_114;
                  }
                  std_vector_grow_realloc_stride4(fVar20);
                }
                if (*(float **)(iVar22 + 0x38) != (float *)0x0) {
                  **(float **)(iVar22 + 0x38) = local_120;
                }
              }
              *(int *)(iVar22 + 0x38) = *(int *)(iVar22 + 0x38) + 4;
              pfVar16 = (float *)*piVar23;
              local_128 = (float)((int)local_128 + 1);
            } while ((int)local_128 < (piVar23[1] - (int)pfVar16 >> 2) + -1);
          }
          local_138 = (float)((int)local_138 + 0xc);
          local_118 = (float)((int)local_118 + 1);
        } while ((int)local_118 < (in_ECX[0x21c] - in_ECX[0x21b]) / 0xc);
      }
    }
  }
  iVar22 = in_ECX[0x2c9];
LAB_0064942b:
  if (-1 < iVar22) {
    if ((((~(byte)((uint)in_ECX[0x217] >> 2) & 1) != 0) && ((*(byte *)(in_ECX + 0x217) & 1) != 0))
       && (iVar22 = in_ECX[0x304], iVar22 != 0)) {
      *(undefined4 *)(iVar22 + 8) = *(undefined4 *)(iVar22 + 4);
      *(undefined4 *)(in_ECX[0x304] + 0x20) = *(undefined4 *)(in_ECX[0x304] + 0x1c);
      *(undefined4 *)(in_ECX[0x304] + 0x14) = *(undefined4 *)(in_ECX[0x304] + 0x10);
      *(undefined4 *)(in_ECX[0x304] + 0x38) = *(undefined4 *)(in_ECX[0x304] + 0x34);
      std_vector_resize_12((in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      iVar22 = 0;
      local_a8 = 0.0;
      local_160[1] = 0.0;
      fStack_a4 = 0.0;
      fVar27 = 0.0;
      local_118 = 0.0;
      fVar20 = local_a8;
      local_b0 = local_a8;
      if (0 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc) {
        piVar23 = in_ECX + 0x2db;
        local_128 = 0.0;
        iVar17 = *piVar23;
        do {
          iVar15 = 0;
          iVar17 = *(int *)((int)local_128 + 4 + iVar17) - *(int *)((int)local_128 + iVar17) >> 4;
          if (0 < iVar17) {
            pfVar16 = *(float **)((int)local_128 + in_ECX[0x2ea]);
            pfVar11 = *(float **)((int)local_128 + *piVar23);
            do {
              local_b0 = local_b0 + *pfVar11;
              local_160[1] = local_160[1] + pfVar11[1];
              local_a8 = local_a8 + pfVar11[2];
              fStack_a4 = fStack_a4 + pfVar11[3];
              fVar27 = fVar27 + *pfVar16;
              fVar20 = fVar20 + pfVar16[1];
              iVar15 = iVar15 + 1;
              iVar22 = iVar22 + 1;
              pfVar11 = pfVar11 + 4;
              pfVar16 = pfVar16 + 2;
              in_ECX = local_130;
            } while (iVar15 < iVar17);
          }
          local_128 = (float)((int)local_128 + 0xc);
          local_118 = (float)((int)local_118 + 1);
          iVar17 = in_ECX[0x2db];
        } while ((int)local_118 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      }
      fVar28 = 1.0 / (float)iVar22;
      local_144 = 0;
      local_160[1] = local_160[1] * fVar28;
      local_118 = fVar20 * fVar28;
      local_130 = (int *)(fVar27 * fVar28);
      local_a8 = local_a8 * fVar28;
      fStack_a4 = fStack_a4 * fVar28;
      local_b0 = local_b0 * fVar28;
      fVar20 = 0.0;
      fVar27 = 0.0;
      local_134 = (int *)0x0;
      local_128 = 0.0;
      local_140 = 0.0;
      local_158[4] = 0.0;
      local_158[3] = 0.0;
      local_158[2] = 0.0;
      local_158[1] = 0.0;
      local_12c = 0.0;
      local_11c = 0.0;
      local_124 = 0.0;
      local_138 = 0.0;
      if (0 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc) {
        iVar22 = in_ECX[0x2db];
        iVar17 = 0;
        do {
          iVar15 = *(int *)(iVar17 + 4 + iVar22) - *(int *)(iVar17 + iVar22) >> 4;
          if (0 < iVar15) {
            puVar21 = *(undefined8 **)(iVar17 + iVar22);
            puVar12 = *(undefined8 **)(iVar17 + in_ECX[0x2ea]);
            do {
              uVar3 = *puVar12;
              puVar7 = puVar21 + 1;
              local_38._0_4_ = (float)*puVar21;
              local_38._0_4_ = (float)local_38 - local_b0;
              local_60._0_4_ = (float)uVar3;
              local_60._0_4_ = (float)local_60 - (float)local_130;
              local_60._4_4_ = (float)((ulonglong)uVar3 >> 0x20);
              local_60._4_4_ = local_60._4_4_ - local_118;
              local_38._4_4_ = (float)((ulonglong)*puVar21 >> 0x20);
              local_38._4_4_ = local_38._4_4_ - local_160[1];
              puVar12 = puVar12 + 1;
              puVar21 = puVar21 + 2;
              local_30 = (float)*puVar7;
              local_30 = local_30 - local_a8;
              fStack_2c = (float)((ulonglong)*puVar7 >> 0x20);
              fStack_2c = fStack_2c - fStack_a4;
              local_128 = (float)local_60 * (float)local_60 + local_128;
              local_140 = local_60._4_4_ * local_60._4_4_ + local_140;
              local_158[4] = local_60._4_4_ * (float)local_60 + local_158[4];
              local_158[3] = local_158[3] + (float)local_60 * (float)local_38;
              local_158[2] = local_158[2] + (float)local_60 * local_38._4_4_;
              local_158[1] = local_158[1] + (float)local_60 * local_30;
              local_12c = local_12c + (float)local_60 * fStack_2c;
              fVar20 = local_11c + local_60._4_4_ * (float)local_38;
              local_138 = local_138 + local_60._4_4_ * local_30;
              fVar27 = local_124 + local_60._4_4_ * local_38._4_4_;
              local_134 = (int *)((float)local_134 + local_60._4_4_ * fStack_2c);
              iVar15 = iVar15 + -1;
              local_124 = fVar27;
              local_11c = fVar20;
              local_60 = uVar3;
            } while (iVar15 != 0);
          }
          local_144 = local_144 + 1;
          iVar17 = iVar17 + 0xc;
        } while (local_144 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      }
      fStack_c = local_140 * local_128 - local_158[4] * local_158[4];
      fStack_24 = (local_158[2] * local_140 - fVar27 * local_158[4]) / fStack_c;
      local_28 = (local_158[3] * local_140 - fVar20 * local_158[4]) / fStack_c;
      local_20 = (local_158[1] * local_140 - local_138 * local_158[4]) / fStack_c;
      fStack_1c = (local_12c * local_140 - (float)local_134 * local_158[4]) / fStack_c;
      local_12c = local_12c * local_158[4];
      local_18 = (local_11c * local_128 - local_158[3] * local_158[4]) / fStack_c;
      fStack_14 = (local_124 * local_128 - local_158[2] * local_158[4]) / fStack_c;
      local_10 = (local_138 * local_128 - local_158[1] * local_158[4]) / fStack_c;
      fStack_c = ((float)local_134 * local_128 - local_12c) / fStack_c;
      local_70[0] = 0.0;
      local_70[1] = 0.0;
      local_70[2] = 0.0;
      local_70[3] = 0.0;
      local_90 = 0x3f8000003f800000;
      local_88 = 0x3f8000003f800000;
      local_114 = 0.0;
      local_120 = local_a8;
      if (0 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc) {
        piVar23 = (int *)in_ECX[0x2ea];
        do {
          iVar22 = 0;
          iVar17 = piVar23[1] - *piVar23 >> 3;
          if (0 < iVar17) {
            puVar21 = (undefined8 *)*piVar23;
            do {
              uVar3 = *puVar21;
              local_58 = CONCAT44(fStack_14,local_18);
              local_60._4_4_ = (float)((ulonglong)uVar3 >> 0x20);
              local_60._4_4_ = local_60._4_4_ - local_118;
              local_60._0_4_ = (float)uVar3;
              local_60._0_4_ = (float)local_60 - (float)local_130;
              local_50 = CONCAT44(fStack_c,local_10);
              local_120 = local_60._4_4_ * fStack_c;
              local_a0 = CONCAT44(fStack_24,local_28);
              local_98 = CONCAT44(fStack_1c,local_20);
              fVar20 = local_b0 + (float)local_60 * local_28;
              fVar27 = local_160[1] + (float)local_60 * fStack_24;
              local_38 = CONCAT44(fVar27,fVar20);
              fVar28 = local_a8 + (float)local_60 * local_20;
              iVar15 = 0;
              fVar25 = fStack_a4 + (float)local_60 * fStack_1c;
              _local_30 = CONCAT44(fVar25,fVar28);
              local_48[1] = fVar27 + local_60._4_4_ * fStack_14;
              local_48[0] = fVar20 + local_60._4_4_ * local_18;
              local_48[3] = fVar25 + local_120;
              local_48[2] = fVar28 + local_60._4_4_ * local_10;
              do {
                fVar20 = *(float *)((int)local_48 + iVar15);
                if (fVar20 < *(float *)((int)local_70 + iVar15)) {
                  *(float *)((int)local_70 + iVar15) = fVar20;
                }
                if (*(float *)((int)&local_90 + iVar15) <= fVar20 &&
                    fVar20 != *(float *)((int)&local_90 + iVar15)) {
                  *(float *)((int)&local_90 + iVar15) = fVar20;
                }
                iVar15 = iVar15 + 4;
              } while (iVar15 < 0x10);
              iVar22 = iVar22 + 1;
              puVar21 = puVar21 + 1;
              local_60 = uVar3;
            } while (iVar22 < iVar17);
          }
          local_114 = (float)((int)local_114 + 1);
          piVar23 = piVar23 + 3;
        } while ((int)local_114 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      }
      local_124 = 0.0;
      fStack_ac = local_160[1];
      if (0 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc) {
        do {
          fVar20 = (float)((int)local_124 * 0xc);
          local_120 = fVar20;
          vectorInt_resize(*(int *)(in_ECX[0x2ea] + 4 + (int)fVar20) -
                       *(int *)(in_ECX[0x2ea] + (int)fVar20) >> 3);
          local_114 = 0.0;
          if (0 < (int)(*(int *)(in_ECX[0x2ea] + 4 + (int)fVar20) -
                        *(int *)(in_ECX[0x2ea] + (int)fVar20) & 0xfffffff8U)) {
            do {
              local_a0 = CONCAT44(fStack_14,local_18);
              local_144 = (int)local_114 * 8;
              uVar3 = *(undefined8 *)(*(int *)((int)fVar20 + in_ECX[0x2ea]) + local_144);
              local_60._4_4_ = (float)((ulonglong)uVar3 >> 0x20);
              local_60._4_4_ = local_60._4_4_ - local_118;
              local_98 = CONCAT44(fStack_c,local_10);
              local_60._0_4_ = (float)uVar3;
              local_60._0_4_ = (float)local_60 - (float)local_130;
              local_11c = local_60._4_4_ * fStack_c;
              local_c0 = CONCAT44(fStack_24,local_28);
              local_b8 = CONCAT44(fStack_1c,local_20);
              fVar27 = local_b0 + (float)local_60 * local_28;
              fVar28 = fStack_ac + (float)local_60 * fStack_24;
              local_58 = CONCAT44(fVar28,fVar27);
              fVar25 = local_a8 + (float)local_60 * local_20;
              fVar26 = fStack_a4 + (float)local_60 * fStack_1c;
              local_50 = CONCAT44(fVar26,fVar25);
              local_d0 = local_90;
              uVar8 = local_d0;
              local_d0._0_4_ = (float)local_90;
              local_d0._4_4_ = (float)((ulonglong)local_90 >> 0x20);
              local_c8 = local_88;
              uVar9 = local_c8;
              local_c8._0_4_ = (float)local_88;
              local_c8._4_4_ = (float)((ulonglong)local_88 >> 0x20);
              local_48[0] = (fVar27 + local_60._4_4_ * local_18) - local_70[0];
              iVar22 = in_ECX[0x304];
              local_48[1] = (fVar28 + local_60._4_4_ * fStack_14) - local_70[1];
              local_48[2] = (fVar25 + local_60._4_4_ * local_10) - local_70[2];
              *(int *)(*(int *)(*(int *)(iVar22 + 0x40) + (int)fVar20) + (int)local_114 * 4) =
                   *(int *)(iVar22 + 8) - *(int *)(iVar22 + 4) >> 3;
              local_48[3] = (fVar26 + local_11c) - local_70[3];
              puVar24 = (undefined4 *)(*(int *)((int)fVar20 + in_ECX[0x2ea]) + local_144);
              iVar22 = in_ECX[0x304];
              puVar18 = *(undefined4 **)(iVar22 + 8);
              local_38 = CONCAT44(local_48[1] / (local_d0._4_4_ - local_70[1]),
                                  local_48[0] / ((float)local_d0 - local_70[0]));
              fVar20 = local_48[2] / ((float)local_c8 - local_70[2]);
              fVar27 = local_48[3] / (local_c8._4_4_ - local_70[3]);
              _local_30 = CONCAT44(fVar27,fVar20);
              local_80 = local_38;
              _local_78 = CONCAT44(fVar27,fVar20);
              local_d0 = uVar8;
              local_c8 = uVar9;
              local_60 = uVar3;
              if ((puVar24 < puVar18) && (*(undefined4 **)(iVar22 + 4) <= puVar24)) {
                puVar6 = *(undefined4 **)(iVar22 + 0xc);
                iVar17 = (int)puVar24 - (int)*(undefined4 **)(iVar22 + 4) >> 3;
                if ((puVar18 == puVar6) && ((int)puVar6 - (int)puVar18 >> 3 == 0)) {
                  iVar15 = (int)puVar18 - *(int *)(iVar22 + 4) >> 3;
                  if (iVar15 == 0x1fffffff) goto LAB_00649419;
                  local_11c = (float)(iVar15 + 1);
                  uVar19 = (int)puVar6 - *(int *)(iVar22 + 4) >> 3;
                  if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_11c) {
                    fVar20 = local_11c;
                  }
                  vectorReserve8(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 8);
                iVar15 = *(int *)(iVar22 + 4);
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *(undefined4 *)(iVar15 + iVar17 * 8);
                  uVar13 = *(undefined4 *)(iVar15 + 4 + iVar17 * 8);
LAB_0064a0f3:
                  puVar18[1] = uVar13;
                }
              }
              else {
                puVar6 = *(undefined4 **)(iVar22 + 0xc);
                if ((puVar18 == puVar6) && ((int)puVar6 - (int)puVar18 >> 3 == 0)) {
                  iVar17 = (int)puVar18 - *(int *)(iVar22 + 4) >> 3;
                  if (iVar17 == 0x1fffffff) goto LAB_00649419;
                  local_11c = (float)(iVar17 + 1);
                  uVar19 = (int)puVar6 - *(int *)(iVar22 + 4) >> 3;
                  if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_11c) {
                    fVar20 = local_11c;
                  }
                  vectorReserve8(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 8);
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *puVar24;
                  uVar13 = puVar24[1];
                  goto LAB_0064a0f3;
                }
              }
              *(int *)(iVar22 + 8) = *(int *)(iVar22 + 8) + 8;
              iVar22 = in_ECX[0x304];
              puVar21 = *(undefined8 **)(iVar22 + 0x20);
              if (&local_80 < puVar21) {
                puVar12 = *(undefined8 **)(iVar22 + 0x1c);
                if (&local_80 < puVar12) goto LAB_0064a1aa;
                puVar7 = *(undefined8 **)(iVar22 + 0x24);
                if ((puVar21 == puVar7) && ((int)puVar7 - (int)puVar21 >> 4 == 0)) {
                  iVar17 = (int)puVar21 - *(int *)(iVar22 + 0x1c) >> 4;
                  if (iVar17 == 0xfffffff) goto LAB_00649419;
                  local_11c = (float)(iVar17 + 1);
                  uVar19 = (int)puVar7 - *(int *)(iVar22 + 0x1c) >> 4;
                  if (0xfffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_11c) {
                    fVar20 = local_11c;
                  }
                  vectorReserve16(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 0x20);
                puVar24 = (undefined4 *)
                          (((int)&local_80 - (int)puVar12 & 0xfffffff0U) + *(int *)(iVar22 + 0x1c));
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *puVar24;
                  puVar18[1] = puVar24[1];
                  puVar18[2] = puVar24[2];
                  puVar18[3] = puVar24[3];
                }
              }
              else {
LAB_0064a1aa:
                puVar12 = *(undefined8 **)(iVar22 + 0x24);
                if ((puVar21 == puVar12) && ((int)puVar12 - (int)puVar21 >> 4 == 0)) {
                  iVar17 = (int)puVar21 - *(int *)(iVar22 + 0x1c) >> 4;
                  if (iVar17 == 0xfffffff) goto LAB_00649419;
                  local_11c = (float)(iVar17 + 1);
                  uVar19 = (int)puVar12 - *(int *)(iVar22 + 0x1c) >> 4;
                  if (0xfffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_11c) {
                    fVar20 = local_11c;
                  }
                  vectorReserve16(fVar20);
                }
                puVar21 = *(undefined8 **)(iVar22 + 0x20);
                if (puVar21 != (undefined8 *)0x0) {
                  *puVar21 = local_38;
                  *(float *)(puVar21 + 1) = local_30;
                  *(float *)((int)puVar21 + 0xc) = fStack_2c;
                }
              }
              *(int *)(iVar22 + 0x20) = *(int *)(iVar22 + 0x20) + 0x10;
              iVar22 = in_ECX[0x304];
              puVar24 = (undefined4 *)(*(int *)(in_ECX[0x2ed] + (int)local_120) + local_144);
              puVar18 = *(undefined4 **)(iVar22 + 0x14);
              if ((puVar24 < puVar18) && (*(undefined4 **)(iVar22 + 0x10) <= puVar24)) {
                puVar6 = *(undefined4 **)(iVar22 + 0x18);
                iVar17 = (int)puVar24 - (int)*(undefined4 **)(iVar22 + 0x10) >> 3;
                if ((puVar18 == puVar6) && ((int)puVar6 - (int)puVar18 >> 3 == 0)) {
                  iVar15 = (int)puVar18 - *(int *)(iVar22 + 0x10) >> 3;
                  if (iVar15 == 0x1fffffff) goto LAB_00649419;
                  local_11c = (float)(iVar15 + 1);
                  uVar19 = (int)puVar6 - *(int *)(iVar22 + 0x10) >> 3;
                  if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_11c) {
                    fVar20 = local_11c;
                  }
                  vectorReserve8(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 0x14);
                iVar15 = *(int *)(iVar22 + 0x10);
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *(undefined4 *)(iVar15 + iVar17 * 8);
                  uVar13 = *(undefined4 *)(iVar15 + 4 + iVar17 * 8);
LAB_0064a341:
                  puVar18[1] = uVar13;
                }
              }
              else {
                puVar6 = *(undefined4 **)(iVar22 + 0x18);
                if ((puVar18 == puVar6) && ((int)puVar6 - (int)puVar18 >> 3 == 0)) {
                  iVar17 = (int)puVar18 - *(int *)(iVar22 + 0x10) >> 3;
                  if (iVar17 == 0x1fffffff) goto LAB_00649419;
                  local_11c = (float)(iVar17 + 1);
                  uVar19 = (int)puVar6 - *(int *)(iVar22 + 0x10) >> 3;
                  if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_11c) {
                    fVar20 = local_11c;
                  }
                  vectorReserve8(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 0x14);
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *puVar24;
                  uVar13 = puVar24[1];
                  goto LAB_0064a341;
                }
              }
              *(int *)(iVar22 + 0x14) = *(int *)(iVar22 + 0x14) + 8;
              local_114 = (float)((int)local_114 + 1);
              fVar20 = local_120;
            } while ((int)local_114 <
                     *(int *)(in_ECX[0x2ea] + 4 + (int)local_120) -
                     *(int *)(in_ECX[0x2ea] + (int)local_120) >> 3);
          }
          local_124 = (float)((int)local_124 + 1);
        } while ((int)local_124 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      }
      FUN_00675690();
    }
    if ((((uint)in_ECX[0x217] >> 4 & 1) != 0) && (iVar22 = in_ECX[0x306], iVar22 != 0)) {
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 4));
      *(undefined4 *)(iVar22 + 8) = *(undefined4 *)(iVar22 + 4);
      iVar22 = in_ECX[0x306];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x1c));
      *(undefined4 *)(iVar22 + 0x20) = *(undefined4 *)(iVar22 + 0x1c);
      iVar22 = in_ECX[0x306];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x28));
      *(undefined4 *)(iVar22 + 0x2c) = *(undefined4 *)(iVar22 + 0x28);
      iVar22 = in_ECX[0x306];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x10));
      *(undefined4 *)(iVar22 + 0x14) = *(undefined4 *)(iVar22 + 0x10);
      iVar22 = in_ECX[0x306];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x34));
      *(undefined4 *)(iVar22 + 0x38) = *(undefined4 *)(iVar22 + 0x34);
      std_vector_resize_12((in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      local_118 = 0.0;
      if (0 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc) {
        local_130 = (int *)0x0;
        do {
          fVar20 = local_118;
          piVar23 = local_130;
          vectorInt_resize(*(int *)(in_ECX[0x2ea] + 4 + (int)local_130) -
                       *(int *)(in_ECX[0x2ea] + (int)local_130) >> 3);
          local_114 = 0.0;
          if (0 < (int)(*(int *)(in_ECX[0x2ea] + 4 + (int)piVar23) -
                        *(int *)(in_ECX[0x2ea] + (int)piVar23) & 0xfffffff8U)) {
            local_120 = 0.0;
            do {
              iVar22 = in_ECX[0x306];
              *(int *)(*(int *)(*(int *)(iVar22 + 0x40) + (int)piVar23) + (int)local_114 * 4) =
                   *(int *)(iVar22 + 8) - *(int *)(iVar22 + 4) >> 3;
              iVar22 = in_ECX[0x306];
              local_11c = (float)((int)local_114 * 8);
              puVar24 = (undefined4 *)(*(int *)((int)piVar23 + in_ECX[0x2ea]) + (int)local_11c);
              puVar18 = *(undefined4 **)(iVar22 + 8);
              if ((puVar24 < puVar18) && (*(undefined4 **)(iVar22 + 4) <= puVar24)) {
                puVar6 = *(undefined4 **)(iVar22 + 0xc);
                iVar17 = (int)puVar24 - (int)*(undefined4 **)(iVar22 + 4) >> 3;
                if ((puVar18 == puVar6) && ((int)puVar6 - (int)puVar18 >> 3 == 0)) {
                  iVar15 = (int)puVar18 - *(int *)(iVar22 + 4) >> 3;
                  if (iVar15 == 0x1fffffff) goto LAB_00649419;
                  local_124 = (float)(iVar15 + 1);
                  uVar19 = (int)puVar6 - *(int *)(iVar22 + 4) >> 3;
                  if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_124) {
                    fVar20 = local_124;
                  }
                  vectorReserve8(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 8);
                iVar15 = *(int *)(iVar22 + 4);
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *(undefined4 *)(iVar15 + iVar17 * 8);
                  uVar13 = *(undefined4 *)(iVar15 + 4 + iVar17 * 8);
LAB_0064a616:
                  puVar18[1] = uVar13;
                }
              }
              else {
                puVar6 = *(undefined4 **)(iVar22 + 0xc);
                if ((puVar18 == puVar6) && ((int)puVar6 - (int)puVar18 >> 3 == 0)) {
                  iVar17 = (int)puVar18 - *(int *)(iVar22 + 4) >> 3;
                  if (iVar17 == 0x1fffffff) {
LAB_00649419:
                    /* WARNING: Subroutine does not return */
                    std::_Xlength_error("vector<T> too long");
                  }
                  local_124 = (float)(iVar17 + 1);
                  uVar19 = (int)puVar6 - *(int *)(iVar22 + 4) >> 3;
                  if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                    fVar20 = 0.0;
                  }
                  else {
                    fVar20 = (float)(uVar19 + (uVar19 >> 1));
                  }
                  if ((uint)fVar20 < (uint)local_124) {
                    fVar20 = local_124;
                  }
                  vectorReserve8(fVar20);
                }
                puVar18 = *(undefined4 **)(iVar22 + 8);
                if (puVar18 != (undefined4 *)0x0) {
                  *puVar18 = *puVar24;
                  uVar13 = puVar24[1];
                  goto LAB_0064a616;
                }
              }
              fVar20 = local_120;
              piVar23 = local_130;
              *(int *)(iVar22 + 8) = *(int *)(iVar22 + 8) + 8;
              std_vector_push_back_16(*(int *)(in_ECX[0x2e1] + (int)local_130) + (int)local_120);
              std_vector_push_back_16(*(int *)(in_ECX[0x2e4] + (int)piVar23) + (int)fVar20);
              FUN_00642590(*(int *)(in_ECX[0x2ed] + (int)piVar23) + (int)local_11c);
              local_114 = (float)((int)local_114 + 1);
              local_120 = (float)((int)fVar20 + 0x10);
              fVar20 = local_118;
            } while ((int)local_114 <
                     *(int *)(in_ECX[0x2ea] + 4 + (int)piVar23) -
                     *(int *)(in_ECX[0x2ea] + (int)piVar23) >> 3);
          }
          local_118 = (float)((int)fVar20 + 1);
          local_130 = piVar23 + 3;
        } while ((int)local_118 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
      }
      FUN_00673090(in_ECX[0x1dd] * 0x40 + in_ECX[0x1e8]);
      *(undefined4 *)(in_ECX[0x306] + 0xbc) = 0xf;
    }
    if ((((uint)in_ECX[0x217] >> 1 & 1) != 0) && (iVar22 = in_ECX[0x305], iVar22 != 0)) {
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 4));
      *(undefined4 *)(iVar22 + 8) = *(undefined4 *)(iVar22 + 4);
      iVar22 = in_ECX[0x305];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x1c));
      *(undefined4 *)(iVar22 + 0x20) = *(undefined4 *)(iVar22 + 0x1c);
      iVar22 = in_ECX[0x305];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x10));
      *(undefined4 *)(iVar22 + 0x14) = *(undefined4 *)(iVar22 + 0x10);
      iVar22 = in_ECX[0x305];
      std::_Container_base0::_Orphan_all((_Container_base0 *)(iVar22 + 0x34));
      *(undefined4 *)(iVar22 + 0x38) = *(undefined4 *)(iVar22 + 0x34);
      if ((in_ECX[0x2fe] == 0) || ((float)in_ECX[0x2fd] == 0.0)) {
        local_12c = 0.0;
        if (0 < (in_ECX[0x2f4] - in_ECX[0x2f3]) / 0xc) {
          local_120 = 0.0;
          do {
            fVar20 = local_120;
            piVar23 = (int *)(*(int *)(in_ECX[0x305] + 8) - *(int *)(in_ECX[0x305] + 4) >> 3);
            local_130 = piVar23;
            if ((~(byte)((uint)in_ECX[0x217] >> 3) & 1) == 0) {
              if (in_ECX[0x219] == 1) {
                FUN_0063e020(local_12c,0,0,0,in_ECX[0x2ca]);
              }
              else if (in_ECX[0x219] == 2) {
                FUN_0063ea00(local_12c,0,0,0);
              }
            }
            local_114 = 0.0;
            if (0 < (int)(*(int *)(in_ECX[0x2f3] + 4 + (int)fVar20) -
                          *(int *)(in_ECX[0x2f3] + (int)fVar20) & 0xfffffff8U)) {
              local_118 = 0.0;
              do {
                iVar22 = (int)local_114 * 8;
                FUN_00642590(*(int *)((int)fVar20 + in_ECX[0x2f9]) + iVar22);
                std_vector_push_back_16(*(int *)((int)fVar20 + in_ECX[0x2f6]) + (int)local_118);
                FUN_00642590(*(int *)((int)fVar20 + in_ECX[0x2f3]) + iVar22);
                local_118 = (float)((int)local_118 + 0x10);
                local_114 = (float)((int)local_114 + 1);
                piVar23 = local_130;
              } while ((int)local_114 <
                       *(int *)(in_ECX[0x2f3] + 4 + (int)fVar20) -
                       *(int *)(in_ECX[0x2f3] + (int)fVar20) >> 3);
            }
            if ((~(byte)((uint)in_ECX[0x217] >> 3) & 1) == 0) {
              if (in_ECX[0x219] == 1) {
                FUN_0063e020(local_12c,
                             (*(int *)(in_ECX[0x2f3] + 4 + (int)fVar20) -
                              *(int *)(in_ECX[0x2f3] + (int)fVar20) >> 3) + -4,0x3f800000,1,
                             in_ECX[0x2ca]);
              }
              else if (in_ECX[0x219] == 2) {
                FUN_0063ea00(local_12c,
                             (((int *)(in_ECX[0x2f3] + (int)fVar20))[1] -
                              *(int *)(in_ECX[0x2f3] + (int)fVar20) >> 3) + -4,0x3f800000,1);
              }
            }
            local_118 = (float)((*(int *)(in_ECX[0x305] + 8) - *(int *)(in_ECX[0x305] + 4) >> 3) -
                               (int)piVar23);
            local_114 = local_118;
            if ((~(byte)((uint)in_ECX[0x217] >> 3) & 1) == 0) {
              local_114 = (float)((int)local_118 - 2);
            }
            uVar19 = 0;
            if (0 < (int)local_114) {
              do {
                local_124 = (float)((int)uVar19 % (int)local_118 + (int)piVar23);
                std_vector_push_back_4byte(&local_124);
                local_124 = (float)((int)((uVar19 & 1) + 1 + uVar19) % (int)local_118 + (int)piVar23
                                   );
                std_vector_push_back_4byte(&local_124);
                uVar1 = uVar19 + 1;
                uVar14 = uVar1 & 0x80000001;
                if ((int)uVar14 < 0) {
                  uVar14 = (uVar14 - 1 | 0xfffffffe) + 1;
                }
                local_124 = (float)((int)(uVar14 + uVar19 + 1) % (int)local_118 + (int)local_130);
                std_vector_push_back_4byte(&local_124);
                uVar19 = uVar1;
                piVar23 = local_130;
              } while ((int)uVar1 < (int)local_114);
            }
            local_12c = (float)((int)local_12c + 1);
            local_120 = (float)((int)local_120 + 0xc);
          } while ((int)local_12c < (in_ECX[0x2f4] - in_ECX[0x2f3]) / 0xc);
        }
      }
      else {
        iVar22 = 0;
        if (0 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc) {
          do {
            FUN_0063f3b0(iVar22,in_ECX[0x2fc],in_ECX[0x2fd]);
            iVar22 = iVar22 + 1;
          } while (iVar22 < (in_ECX[0x2eb] - in_ECX[0x2ea]) / 0xc);
        }
      }
      *(undefined4 *)(in_ECX[0x305] + 0xbc) = 0xf;
    }
  }
  if (in_ECX[0x304] != 0) {
    if ((*(byte *)(in_ECX[0x304] + 0xbc) & 8) != 0) {
      FUN_00674160();
    }
    (**(code **)(*(int *)in_ECX[0x304] + 4))();
  }
  if (in_ECX[0x305] != 0) {
    if ((*(byte *)(in_ECX[0x305] + 0xbc) & 8) != 0) {
      FUN_00674160();
    }
    (**(code **)(*(int *)in_ECX[0x305] + 4))();
  }
  if (in_ECX[0x306] != 0) {
    if ((*(byte *)(in_ECX[0x306] + 0xbc) & 8) != 0) {
      FUN_00674160();
    }
    (**(code **)(*(int *)in_ECX[0x306] + 4))();
  }
  local_139 = 1;
  mat4_identity();
  (**(code **)(*in_ECX + 0x20))(in_ECX + 0x21e,in_ECX + 0x220,local_110,&local_139);
  *(undefined1 *)((int)in_ECX + 0xb2d) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x307));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: Object::release_if_nonnull  (confidence: high)
 * purpose: Call virtual release/destructor (vtbl[0]) on object if pointer non-null
 * vars: indirect vtbl call
 */
/* Global::Object_release_if_nonnull @ 006504c0 */

void Object_release_if_nonnull(undefined4 *object)

{
  if (object != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006504d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)*object)();
    return;
  }
  return;
}




/* Global::FUN_0066b9c0 @ 0066b9c0 */

void FUN_0066b9c0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  float fVar9;
  undefined1 auStack_84 [4];
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int *local_68;
  int local_64;
  int *local_60;
  int local_5c;
  int *local_58;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  float local_34;
  float fStack_30;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  undefined8 local_14;
  uint local_c;
  
  local_c = DAT_0076aa78 ^ (uint)auStack_84;
  local_64 = 0;
  if (0 < (*(int *)(in_ECX + 0x8dc) - *(int *)(in_ECX + 0x8d8)) / 0xc) {
    local_68 = *(int **)(in_ECX + 0x8d8);
    local_80 = in_ECX;
    local_58 = local_68;
    do {
      iVar7 = local_68[1] - *local_68 >> 2;
      local_78 = 0;
      if (0 < iVar7) {
        iVar5 = *(int *)(local_80 + 0x2c4);
        piVar3 = (int *)*local_68;
        local_74 = iVar5;
        do {
          local_7c = piVar3[local_78];
          if ((*(uint *)(iVar5 + local_7c * 4) & 0xffff0000) == 0x10000) {
            local_6c = local_78 + 2;
            iVar6 = piVar3[(local_78 + 3) % iVar7];
            if ((*(uint *)(iVar5 + iVar6 * 4) & 0xffff0000) != 0x10000) {
              iVar6 = piVar3[(local_78 + 2) % iVar7];
            }
            local_70 = **(int **)(*(int *)(local_80 + 0xa8) + *(int *)(local_80 + 0x7c) * 4);
            uVar1 = *(undefined8 *)(local_70 + iVar6 * 8);
            local_54._0_4_ = (float)uVar1;
            local_54._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
            local_54._4_4_ = local_54._4_4_ - *(float *)(local_70 + 4 + local_7c * 8);
            local_54._0_4_ = (float)local_54 - *(float *)(local_70 + local_7c * 8);
            fVar9 = local_54._4_4_ * local_54._4_4_ + (float)local_54 * (float)local_54;
            if (0.0 < fVar9) {
              dVar8 = (double)fVar9;
              iVar5 = *(int *)(local_80 + 0x2d0);
              libm_sse2_sqrt_precise();
              fVar9 = *(float *)(iVar5 + local_7c * 4) / (float)dVar8;
              local_24 = local_54;
              uVar2 = local_24;
              uVar1 = *(undefined8 *)(local_70 + local_7c * 8);
              local_24._0_4_ = (float)local_54;
              local_24._4_4_ = (float)((ulonglong)local_54 >> 0x20);
              local_44._0_4_ = (float)uVar1;
              local_44._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
              local_44 = CONCAT44(local_44._4_4_ + local_24._4_4_ * fVar9,
                                  (float)local_44 + (float)local_24 * fVar9);
              *(undefined8 *)(local_70 + piVar3[(local_6c + -1) % iVar7] * 8) = local_44;
              local_24 = uVar2;
            }
            iVar5 = piVar3[(iVar7 + -3 + local_78) % iVar7];
            if ((*(uint *)(local_74 + iVar5 * 4) & 0xffff0000) != 0x10000) {
              iVar5 = piVar3[(iVar7 + -2 + local_78) % iVar7];
            }
            local_70 = **(int **)(*(int *)(local_80 + 0xa8) + *(int *)(local_80 + 0x7c) * 4);
            uVar1 = *(undefined8 *)(local_70 + iVar5 * 8);
            local_4c._0_4_ = (float)uVar1;
            local_4c._0_4_ = (float)local_4c - *(float *)(local_70 + local_7c * 8);
            local_4c._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
            local_4c._4_4_ = local_4c._4_4_ - *(float *)(local_70 + 4 + local_7c * 8);
            local_54 = local_4c;
            fVar9 = local_4c._4_4_ * local_4c._4_4_ + (float)local_4c * (float)local_4c;
            iVar5 = local_74;
            if (0.0 < fVar9) {
              dVar8 = (double)fVar9;
              iVar5 = *(int *)(local_80 + 0x2d0);
              libm_sse2_sqrt_precise();
              fVar9 = *(float *)(iVar5 + local_7c * 4) / (float)dVar8;
              local_1c = local_4c;
              uVar2 = local_1c;
              uVar1 = *(undefined8 *)(local_70 + local_7c * 8);
              local_1c._0_4_ = (float)local_4c;
              local_1c._4_4_ = (float)((ulonglong)local_4c >> 0x20);
              local_2c._0_4_ = (float)uVar1;
              local_2c._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
              local_2c = CONCAT44(local_2c._4_4_ + local_1c._4_4_ * fVar9,
                                  (float)local_2c + (float)local_1c * fVar9);
              *(undefined8 *)(local_70 + piVar3[(local_78 + -1 + iVar7) % iVar7] * 8) = local_2c;
              iVar5 = local_74;
              local_1c = uVar2;
            }
          }
          local_78 = local_78 + 1;
        } while (local_78 < iVar7);
        local_6c = 1;
        local_60 = piVar3;
        iVar6 = iVar7;
        do {
          local_5c = *local_60;
          if ((*(uint *)(iVar5 + local_5c * 4) & 0xffff0000) == 0x20000) {
            local_78 = iVar7 + -1 + local_6c;
            local_7c = 0;
            iVar5 = local_6c;
            while ((iVar5 < local_78 &&
                   (local_7c = piVar3[iVar5 % iVar7],
                   (*(uint *)(local_74 + local_7c * 4) & 0xffff0000) == 0x20000))) {
              iVar5 = iVar5 + 1;
            }
            iVar5 = 0;
            iVar4 = local_78;
            do {
              iVar4 = iVar4 + -1;
              if (iVar4 < local_6c) break;
              iVar5 = piVar3[iVar4 % iVar7];
            } while ((*(uint *)(local_74 + iVar5 * 4) & 0xffff0000) == 0x20000);
            fVar9 = *(float *)(*(int *)(local_80 + 0x2d0) + local_5c * 4);
            iVar4 = **(int **)(*(int *)(local_80 + 0xa8) + *(int *)(local_80 + 0x7c) * 4);
            uVar1 = *(undefined8 *)(iVar4 + iVar5 * 8);
            uVar2 = *(undefined8 *)(iVar4 + local_7c * 8);
            local_14._0_4_ = (float)uVar1;
            local_14._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
            local_34 = (float)uVar2;
            local_34 = (1.0 - fVar9) * local_34;
            fStack_30 = (float)((ulonglong)uVar2 >> 0x20);
            fStack_30 = (1.0 - fVar9) * fStack_30;
            local_3c = CONCAT44(fStack_30 + local_14._4_4_ * fVar9,
                                (float)local_14 * fVar9 + local_34);
            *(undefined8 *)(iVar4 + local_5c * 8) = local_3c;
            iVar5 = local_74;
            local_14 = uVar1;
          }
          local_60 = local_60 + 1;
          local_6c = local_6c + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        local_70 = 0;
      }
      local_68 = local_68 + 3;
      local_64 = local_64 + 1;
    } while (local_64 < (*(int *)(local_80 + 0x8dc) - (int)local_58) / 0xc);
  }
  __security_check_cookie(local_c ^ (uint)auStack_84);
  return;
}




/* plasma::SmoothMeshShape::vfunc_19 @ 0066be90 */

void plasma::SmoothMeshShape::vfunc_19(void)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  
  FUN_0066c050();
  iVar5 = *(int *)(*(int *)(in_ECX + 0x7f8) + *(int *)(in_ECX + 0x7cc) * 4);
  if (iVar5 == -1) {
    *(undefined4 *)(in_ECX + 0x888) = 0;
  }
  else if ((*(int *)(in_ECX + 0x888) == 0) || (*(int *)(*(int *)(in_ECX + 0x888) + 0x4c) != iVar5))
  {
    uVar4 = std_map_findValue(iVar5);
    *(undefined4 *)(in_ECX + 0x888) = uVar4;
  }
  iVar5 = *(int *)(*(int *)(in_ECX + 0x850) + *(int *)(in_ECX + 0x824) * 4);
  if (iVar5 == -1) {
    *(undefined4 *)(in_ECX + 0x88c) = 0;
  }
  else if ((*(int *)(in_ECX + 0x88c) == 0) || (*(int *)(*(int *)(in_ECX + 0x88c) + 0x4c) != iVar5))
  {
    uVar4 = std_map_findValue(iVar5);
    *(undefined4 *)(in_ECX + 0x88c) = uVar4;
  }
  if ((((int *)**(int **)(in_ECX + 0xa8))[1] - *(int *)**(int **)(in_ECX + 0xa8) & 0xfffffff8U) != 0
     ) {
    iVar5 = 1;
    puVar2 = (undefined4 *)**(int **)(*(int *)(in_ECX + 0xa8) + *(int *)(in_ECX + 0x7c) * 4);
    *(undefined4 *)(in_ECX + 0x878) = *puVar2;
    *(undefined4 *)(in_ECX + 0x87c) = puVar2[1];
    *(undefined4 *)(in_ECX + 0x880) = *(undefined4 *)(in_ECX + 0x878);
    *(undefined4 *)(in_ECX + 0x884) = *(undefined4 *)(in_ECX + 0x87c);
    if ((int)(((int *)**(int **)(in_ECX + 0xa8))[1] - *(int *)**(int **)(in_ECX + 0xa8) &
             0xfffffff8U) < 9) {
      *(undefined1 *)(in_ECX + 0x2d) = 1;
      return;
    }
    do {
      iVar3 = **(int **)(*(int *)(in_ECX + 0xa8) + *(int *)(in_ECX + 0x7c) * 4);
      fVar1 = *(float *)(iVar3 + iVar5 * 8);
      if (fVar1 < *(float *)(in_ECX + 0x878)) {
        *(float *)(in_ECX + 0x878) = fVar1;
      }
      fVar1 = *(float *)(iVar3 + 4 + iVar5 * 8);
      if (fVar1 < *(float *)(in_ECX + 0x87c)) {
        *(float *)(in_ECX + 0x87c) = fVar1;
      }
      fVar1 = *(float *)(iVar3 + iVar5 * 8);
      if (*(float *)(in_ECX + 0x880) <= fVar1 && fVar1 != *(float *)(in_ECX + 0x880)) {
        *(float *)(in_ECX + 0x880) = fVar1;
      }
      fVar1 = *(float *)(iVar3 + 4 + iVar5 * 8);
      if (*(float *)(in_ECX + 0x884) <= fVar1 && fVar1 != *(float *)(in_ECX + 0x884)) {
        *(float *)(in_ECX + 0x884) = fVar1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < ((int *)**(int **)(in_ECX + 0xa8))[1] - *(int *)**(int **)(in_ECX + 0xa8) >> 3)
    ;
    *(undefined1 *)(in_ECX + 0x2d) = 1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x878) = 0;
  *(undefined4 *)(in_ECX + 0x87c) = 0;
  *(undefined4 *)(in_ECX + 0x880) = 0;
  *(undefined4 *)(in_ECX + 0x884) = 0;
  *(undefined1 *)(in_ECX + 0x2d) = 1;
  return;
}




/* Global::FUN_0066c050 @ 0066c050 */

void FUN_0066c050(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int in_ECX;
  float fVar5;
  float fVar6;
  double dVar7;
  float fVar8;
  
  pfVar1 = (float *)(in_ECX + 0x890);
  mat4_identity();
  fVar5 = *(float *)(*(int *)(in_ECX + 0x328) + *(int *)(in_ECX + 0x2fc) * 8);
  fVar6 = *(float *)(*(int *)(in_ECX + 0x328) + 4 + *(int *)(in_ECX + 0x2fc) * 8);
  *(float *)(in_ECX + 0x8c0) =
       fVar5 * *pfVar1 + fVar6 * *(float *)(in_ECX + 0x8a0) + *(float *)(in_ECX + 0x8c0);
  *(float *)(in_ECX + 0x8c4) =
       *(float *)(in_ECX + 0x8a4) * fVar6 + fVar5 * *(float *)(in_ECX + 0x894) +
       *(float *)(in_ECX + 0x8c4);
  *(float *)(in_ECX + 0x8c8) =
       *(float *)(in_ECX + 0x8a8) * fVar6 + fVar5 * *(float *)(in_ECX + 0x898) +
       *(float *)(in_ECX + 0x8c8);
  *(float *)(in_ECX + 0x8cc) =
       *(float *)(in_ECX + 0x8ac) * fVar6 + fVar5 * *(float *)(in_ECX + 0x89c) +
       *(float *)(in_ECX + 0x8cc);
  fVar5 = *(float *)(*(int *)(in_ECX + 0x380) + *(int *)(in_ECX + 0x354) * 8);
  fVar6 = *(float *)(*(int *)(in_ECX + 0x380) + 4 + *(int *)(in_ECX + 0x354) * 8);
  *(float *)(in_ECX + 0x8c0) =
       fVar5 * *pfVar1 + fVar6 * *(float *)(in_ECX + 0x8a0) + *(float *)(in_ECX + 0x8c0);
  *(float *)(in_ECX + 0x8c4) =
       *(float *)(in_ECX + 0x8a4) * fVar6 + fVar5 * *(float *)(in_ECX + 0x894) +
       *(float *)(in_ECX + 0x8c4);
  *(float *)(in_ECX + 0x8c8) =
       *(float *)(in_ECX + 0x8a8) * fVar6 + fVar5 * *(float *)(in_ECX + 0x898) +
       *(float *)(in_ECX + 0x8c8);
  *(float *)(in_ECX + 0x8cc) =
       *(float *)(in_ECX + 0x8ac) * fVar6 + fVar5 * *(float *)(in_ECX + 0x89c) +
       *(float *)(in_ECX + 0x8cc);
  fVar5 = *(float *)(*(int *)(in_ECX + 0x3d8) + *(int *)(in_ECX + 0x3ac) * 0xc) * 0.017453292;
  dVar7 = (double)fVar5;
  libm_sse2_cos_precise();
  fVar6 = (float)dVar7;
  dVar7 = (double)fVar5;
  libm_sse2_sin_precise();
  fVar5 = *(float *)(in_ECX + 0x8a0);
  fVar8 = (float)dVar7;
  *(float *)(in_ECX + 0x8a0) = *(float *)(in_ECX + 0x8b0) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8b0) = *(float *)(in_ECX + 0x8b0) * fVar6 - fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x8a4);
  *(float *)(in_ECX + 0x8a4) = *(float *)(in_ECX + 0x8b4) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8b4) = *(float *)(in_ECX + 0x8b4) * fVar6 - fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x8a8);
  *(float *)(in_ECX + 0x8a8) = *(float *)(in_ECX + 0x8b8) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8b8) = *(float *)(in_ECX + 0x8b8) * fVar6 - fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x8ac);
  *(float *)(in_ECX + 0x8ac) = *(float *)(in_ECX + 0x8bc) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8bc) = *(float *)(in_ECX + 0x8bc) * fVar6 - fVar5 * fVar8;
  fVar5 = *(float *)(*(int *)(in_ECX + 0x3d8) + 4 + *(int *)(in_ECX + 0x3ac) * 0xc) * 0.017453292;
  dVar7 = (double)fVar5;
  libm_sse2_cos_precise();
  fVar6 = (float)dVar7;
  dVar7 = (double)fVar5;
  libm_sse2_sin_precise();
  fVar5 = *pfVar1;
  fVar8 = (float)dVar7;
  *pfVar1 = fVar5 * fVar6 - *(float *)(in_ECX + 0x8b0) * fVar8;
  *(float *)(in_ECX + 0x8b0) = *(float *)(in_ECX + 0x8b0) * fVar6 + fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x894);
  *(float *)(in_ECX + 0x894) = fVar5 * fVar6 - *(float *)(in_ECX + 0x8b4) * fVar8;
  *(float *)(in_ECX + 0x8b4) = *(float *)(in_ECX + 0x8b4) * fVar6 + fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x898);
  *(float *)(in_ECX + 0x898) = fVar5 * fVar6 - *(float *)(in_ECX + 0x8b8) * fVar8;
  *(float *)(in_ECX + 0x8b8) = *(float *)(in_ECX + 0x8b8) * fVar6 + fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x89c);
  *(float *)(in_ECX + 0x89c) = fVar5 * fVar6 - *(float *)(in_ECX + 0x8bc) * fVar8;
  *(float *)(in_ECX + 0x8bc) = *(float *)(in_ECX + 0x8bc) * fVar6 + fVar5 * fVar8;
  fVar5 = *(float *)(*(int *)(in_ECX + 0x3d8) + 8 + *(int *)(in_ECX + 0x3ac) * 0xc) * 0.017453292;
  dVar7 = (double)fVar5;
  libm_sse2_cos_precise();
  fVar6 = (float)dVar7;
  dVar7 = (double)fVar5;
  libm_sse2_sin_precise();
  fVar5 = *pfVar1;
  fVar8 = (float)dVar7;
  *pfVar1 = fVar5 * fVar6 + fVar8 * *(float *)(in_ECX + 0x8a0);
  *(float *)(in_ECX + 0x8a0) = fVar6 * *(float *)(in_ECX + 0x8a0) - fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x894);
  *(float *)(in_ECX + 0x894) = *(float *)(in_ECX + 0x8a4) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8a4) = *(float *)(in_ECX + 0x8a4) * fVar6 - fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x898);
  *(float *)(in_ECX + 0x898) = *(float *)(in_ECX + 0x8a8) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8a8) = *(float *)(in_ECX + 0x8a8) * fVar6 - fVar5 * fVar8;
  fVar5 = *(float *)(in_ECX + 0x89c);
  *(float *)(in_ECX + 0x89c) = *(float *)(in_ECX + 0x8ac) * fVar8 + fVar5 * fVar6;
  *(float *)(in_ECX + 0x8ac) = *(float *)(in_ECX + 0x8ac) * fVar6 - fVar5 * fVar8;
  fVar5 = *pfVar1;
  fVar6 = *(float *)(in_ECX + 0x8a0);
  fVar8 = *(float *)(in_ECX + 0x8b0);
  fVar2 = *(float *)(in_ECX + 0x8c0);
  pfVar4 = (float *)(*(int *)(in_ECX + 0x404) * 0x40 + *(int *)(in_ECX + 0x430));
  *pfVar1 = fVar6 * pfVar4[1] + fVar5 * *pfVar4 + fVar8 * pfVar4[2] + pfVar4[3] * fVar2;
  *(float *)(in_ECX + 0x8a0) =
       pfVar4[5] * fVar6 + pfVar4[4] * fVar5 + fVar8 * pfVar4[6] + fVar2 * pfVar4[7];
  *(float *)(in_ECX + 0x8b0) =
       pfVar4[9] * fVar6 + pfVar4[8] * fVar5 + pfVar4[10] * fVar8 + fVar2 * pfVar4[0xb];
  fVar3 = *(float *)(in_ECX + 0x8c4);
  *(float *)(in_ECX + 0x8c0) =
       fVar6 * pfVar4[0xd] + fVar5 * pfVar4[0xc] + pfVar4[0xe] * fVar8 + pfVar4[0xf] * fVar2;
  fVar5 = *(float *)(in_ECX + 0x894);
  fVar6 = *(float *)(in_ECX + 0x8a4);
  fVar8 = *(float *)(in_ECX + 0x8b4);
  *(float *)(in_ECX + 0x894) =
       fVar6 * pfVar4[1] + fVar5 * *pfVar4 + fVar8 * pfVar4[2] + pfVar4[3] * fVar3;
  *(float *)(in_ECX + 0x8a4) =
       pfVar4[5] * fVar6 + pfVar4[4] * fVar5 + fVar8 * pfVar4[6] + fVar3 * pfVar4[7];
  *(float *)(in_ECX + 0x8b4) =
       pfVar4[9] * fVar6 + pfVar4[8] * fVar5 + pfVar4[10] * fVar8 + fVar3 * pfVar4[0xb];
  fVar2 = *(float *)(in_ECX + 0x8c8);
  *(float *)(in_ECX + 0x8c4) =
       fVar6 * pfVar4[0xd] + fVar5 * pfVar4[0xc] + pfVar4[0xe] * fVar8 + pfVar4[0xf] * fVar3;
  fVar5 = *(float *)(in_ECX + 0x898);
  fVar6 = *(float *)(in_ECX + 0x8a8);
  fVar8 = *(float *)(in_ECX + 0x8b8);
  *(float *)(in_ECX + 0x898) =
       fVar6 * pfVar4[1] + fVar5 * *pfVar4 + fVar8 * pfVar4[2] + pfVar4[3] * fVar2;
  *(float *)(in_ECX + 0x8a8) =
       pfVar4[5] * fVar6 + pfVar4[4] * fVar5 + fVar8 * pfVar4[6] + fVar2 * pfVar4[7];
  *(float *)(in_ECX + 0x8b8) =
       pfVar4[9] * fVar6 + pfVar4[8] * fVar5 + pfVar4[10] * fVar8 + fVar2 * pfVar4[0xb];
  fVar3 = *(float *)(in_ECX + 0x8cc);
  *(float *)(in_ECX + 0x8c8) =
       fVar6 * pfVar4[0xd] + fVar5 * pfVar4[0xc] + pfVar4[0xe] * fVar8 + pfVar4[0xf] * fVar2;
  fVar5 = *(float *)(in_ECX + 0x89c);
  fVar6 = *(float *)(in_ECX + 0x8ac);
  fVar8 = *(float *)(in_ECX + 0x8bc);
  *(float *)(in_ECX + 0x89c) =
       fVar6 * pfVar4[1] + fVar5 * *pfVar4 + fVar8 * pfVar4[2] + pfVar4[3] * fVar3;
  *(float *)(in_ECX + 0x8ac) =
       pfVar4[5] * fVar6 + pfVar4[4] * fVar5 + fVar8 * pfVar4[6] + fVar3 * pfVar4[7];
  *(float *)(in_ECX + 0x8bc) =
       pfVar4[9] * fVar6 + pfVar4[8] * fVar5 + pfVar4[10] * fVar8 + fVar3 * pfVar4[0xb];
  *(float *)(in_ECX + 0x8cc) =
       fVar6 * pfVar4[0xd] + fVar5 * pfVar4[0xc] + pfVar4[0xe] * fVar8 + pfVar4[0xf] * fVar3;
  fVar6 = *(float *)(*(int *)(in_ECX + 0x380) + *(int *)(in_ECX + 0x354) * 8) * -1.0;
  fVar5 = *(float *)(*(int *)(in_ECX + 0x380) + 4 + *(int *)(in_ECX + 0x354) * 8) * -1.0;
  *(float *)(in_ECX + 0x8c0) =
       fVar5 * *(float *)(in_ECX + 0x8a0) + fVar6 * *pfVar1 + *(float *)(in_ECX + 0x8c0);
  *(float *)(in_ECX + 0x8c4) =
       *(float *)(in_ECX + 0x8a4) * fVar5 + fVar6 * *(float *)(in_ECX + 0x894) +
       *(float *)(in_ECX + 0x8c4);
  *(float *)(in_ECX + 0x8c8) =
       *(float *)(in_ECX + 0x8a8) * fVar5 + fVar6 * *(float *)(in_ECX + 0x898) +
       *(float *)(in_ECX + 0x8c8);
  *(float *)(in_ECX + 0x8cc) =
       *(float *)(in_ECX + 0x8ac) * fVar5 + fVar6 * *(float *)(in_ECX + 0x89c) +
       *(float *)(in_ECX + 0x8cc);
  return;
}




/* plasma::SmoothMeshShape::clearLevelBuffers @ 00671420 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::SmoothMeshShape::clearLevelBuffers.
 * Clears the SAME 3 concurrent_vectors(+4/+0x24/+0x44) of one 0x60B mesh level (same layout as dtor 63c700). Sole caller plasma::SmoothMeshShape::vfunc_16 loops it 6x, once per level. Type-specific member, not a generic 1-container lib clear.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::SmoothMeshShape::clearLevelBuffers(void)

{
  int in_ECX;
  
  Concurrency::details::_Concurrent_vector_base_v4::_Internal_clear
            ((_Concurrent_vector_base_v4 *)(in_ECX + 4),cube::AdaptionWidget::vfunc_6);
  Concurrency::details::_Concurrent_vector_base_v4::_Internal_clear
            ((_Concurrent_vector_base_v4 *)(in_ECX + 0x24),cube::AdaptionWidget::vfunc_6);
  Concurrency::details::_Concurrent_vector_base_v4::_Internal_clear
            ((_Concurrent_vector_base_v4 *)(in_ECX + 0x44),cube::AdaptionWidget::vfunc_6);
  return;
}




/* Global::FUN_00671f80 @ 00671f80 */

void FUN_00671f80(float param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  undefined1 *puVar4;
  float **ppfVar5;
  float *local_30;
  float *local_2c;
  float *local_28;
  float *local_24;
  int local_20;
  float local_1c;
  float local_18;
  int local_14;
  undefined1 local_c [5];
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  puVar4 = &local_5;
  uVar3 = *(uint *)(in_ECX + 0x58);
  local_20 = in_ECX + 0x40;
  local_5 = 0;
  local_14 = in_ECX;
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 0x44));
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  FUN_0066df80(in_ECX + 0x40,0,0,in_ECX + 0x40,uVar3,0,puVar4);
  local_1c = 1.0 - param_1;
  local_18 = param_1;
  local_6 = 0;
  Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
            ((_Concurrent_vector_base_v4 *)(in_ECX + 4));
  FUN_0066e140();
  local_28 = &local_1c;
  local_24 = &local_18;
  ppfVar5 = &local_28;
  uVar3 = *(uint *)(in_ECX + 0x38);
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 0x24));
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  iVar1 = in_ECX + 0x20;
  FUN_0066e060(iVar1,0,0,in_ECX + 0x20,uVar3,0,ppfVar5);
  uVar3 = *(uint *)(in_ECX + 0x38);
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                    ((_Concurrent_vector_base_v4 *)(in_ECX + 0x24));
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  FUN_0066cc10(iVar1,0,0,iVar1,uVar3,0,local_c);
  Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
            ((_Concurrent_vector_base_v4 *)(in_ECX + 4));
  FUN_0066cc90();
  iVar1 = local_20;
  local_30 = &local_18;
  uVar3 = *(uint *)(local_20 + 0x18);
  local_2c = &local_1c;
  ppfVar5 = &local_30;
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                    ((_Concurrent_vector_base_v4 *)(local_20 + 4));
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  FUN_0066dff0(iVar1,0,0,iVar1,uVar3,0,ppfVar5);
  uVar3 = *(uint *)(local_14 + 0x38);
  puVar4 = &local_7;
  local_7 = 0;
  uVar2 = Concurrency::details::_Concurrent_vector_base_v4::_Internal_capacity
                    ((_Concurrent_vector_base_v4 *)(local_14 + 0x24));
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  FUN_0066e0d0(local_14 + 0x20,0,0,local_14 + 0x20,uVar3,0,puVar4);
  return;
}




/* Global::FUN_00673090 @ 00673090 */

void FUN_00673090(float *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float *pfVar8;
  uint **ppuVar9;
  uint **ppuVar10;
  uint **ppuVar11;
  int *piVar12;
  int *piVar13;
  int in_ECX;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  uint uVar19;
  uint *puVar20;
  float *pfVar21;
  uint *puVar22;
  undefined4 *puVar23;
  float *pfVar24;
  undefined4 *puVar25;
  uint *puVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  int local_e8;
  int local_e4;
  uint **local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0;
  uint *local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  undefined4 *local_bc;
  undefined4 *local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_ac;
  int local_a8;
  int local_a4;
  uint *local_a0;
  undefined4 *local_9c;
  int local_98;
  undefined4 *local_94;
  int local_90;
  uint local_8c;
  uint *local_88;
  float local_84 [16];
  float local_44 [2];
  undefined8 local_3c;
  undefined8 local_34;
  undefined4 local_2c [2];
  float local_24 [2];
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f82ab;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_98 = in_ECX;
  FUN_00675690(local_14);
  FUN_00674160();
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x34);
  local_94 = (undefined4 *)0x0;
  local_bc = (undefined4 *)0x0;
  local_9c = (undefined4 *)0x0;
  local_b8 = (undefined4 *)0x0;
  local_b4 = 0;
  local_8 = 0;
  puVar20 = (uint *)(in_ECX + 4);
  pfVar21 = param_1;
  pfVar24 = local_84;
  for (iVar14 = 0x10; iVar14 != 0; iVar14 = iVar14 + -1) {
    *pfVar24 = *pfVar21;
    pfVar21 = pfVar21 + 1;
    pfVar24 = pfVar24 + 1;
  }
  local_ac = 0.0;
  local_a8 = 0;
  local_a0 = puVar20;
  local_88 = puVar20;
  if (0 < (*(int *)(local_98 + 0x104) - *(int *)(local_98 + 0x100)) / 0xc) {
    do {
      local_d0 = (int)(puVar20[1] - *puVar20) >> 3;
      iVar14 = *(int *)(local_98 + 0x100);
      local_90 = local_a8 * 0xc;
      if (2 < (uint)(*(int *)(local_90 + 4 + iVar14) - *(int *)(local_90 + iVar14) >> 2)) {
        uVar19 = 0;
        if (0 < (int)(*(int *)(local_90 + 4 + iVar14) - *(int *)(local_90 + iVar14) & 0xfffffffcU))
        {
          do {
            iVar14 = *(int *)(local_98 + 0x100);
            local_8c = uVar19 + 1;
            uVar16 = *puVar20;
            local_9c = *(undefined4 **)(*(int *)(local_90 + iVar14) + uVar19 * 4);
            iVar14 = *(int *)(*(int *)(local_90 + iVar14) +
                             ((int)local_8c %
                             (*(int *)(local_90 + 4 + iVar14) - *(int *)(local_90 + iVar14) >> 2)) *
                             4);
            local_34 = *(undefined8 *)(uVar16 + (int)local_9c * 8);
            puVar3 = (undefined8 *)puVar20[1];
            local_ac = (*(float *)(uVar16 + (int)local_9c * 8) * *(float *)(uVar16 + 4 + iVar14 * 8)
                       - *(float *)(uVar16 + 4 + (int)local_9c * 8) *
                         *(float *)(uVar16 + iVar14 * 8)) + local_ac;
            local_1c = local_34;
            if ((&local_34 < puVar3) && (puVar4 = (undefined8 *)*puVar20, puVar4 <= &local_34)) {
              puVar5 = (undefined8 *)puVar20[2];
              iVar14 = (int)&local_34 - (int)puVar4 >> 3;
              if ((puVar3 == puVar5) && ((int)puVar5 - (int)puVar3 >> 3 == 0)) {
                iVar15 = (int)puVar3 - (int)puVar4 >> 3;
                uVar2 = local_34;
                if (iVar15 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = iVar15 + 1;
                uVar19 = (int)puVar5 - (int)puVar4 >> 3;
                local_1c._0_4_ = (float)local_34;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve8(uVar19);
              }
              puVar23 = (undefined4 *)puVar20[1];
              uVar19 = *puVar20;
              if (puVar23 != (undefined4 *)0x0) {
                *puVar23 = *(undefined4 *)(uVar19 + iVar14 * 8);
                puVar23[1] = *(undefined4 *)(uVar19 + 4 + iVar14 * 8);
              }
            }
            else {
              puVar4 = (undefined8 *)puVar20[2];
              if ((puVar3 == puVar4) && ((int)puVar4 - (int)puVar3 >> 3 == 0)) {
                iVar14 = (int)((int)puVar3 - *puVar20) >> 3;
                uVar2 = local_34;
                if (iVar14 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = (int)((int)puVar4 - *puVar20) >> 3;
                uVar19 = iVar14 + 1;
                if (0x1fffffff - (uVar16 >> 1) < uVar16) {
                  uVar16 = 0;
                }
                else {
                  uVar16 = uVar16 + (uVar16 >> 1);
                }
                if (uVar16 < uVar19) {
                  uVar16 = uVar19;
                }
                vectorReserve8(uVar16);
              }
              if ((undefined8 *)puVar20[1] != (undefined8 *)0x0) {
                *(undefined8 *)puVar20[1] = local_1c;
              }
            }
            iVar14 = local_98;
            puVar20[1] = puVar20[1] + 8;
            puVar23 = *(undefined4 **)(local_98 + 0x20);
            puVar22 = (uint *)(local_98 + 0x1c);
            local_9c = (undefined4 *)((int)local_9c * 0x10);
            puVar25 = (undefined4 *)(*(int *)(local_98 + 0x1c) + (int)local_9c);
            uVar2 = local_1c;
            if ((puVar25 < puVar23) && (puVar6 = (undefined4 *)*puVar22, puVar6 <= puVar25)) {
              puVar7 = *(undefined4 **)(local_98 + 0x24);
              if ((puVar23 == puVar7) && ((int)puVar7 - (int)puVar23 >> 4 == 0)) {
                iVar15 = (int)((int)puVar23 - *puVar22) >> 4;
                if (iVar15 == 0xfffffff) goto LAB_00673a69;
                uVar16 = iVar15 + 1;
                uVar19 = (int)((int)puVar7 - *puVar22) >> 4;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0xfffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve16(uVar19);
              }
              puVar25 = (undefined4 *)(((int)puVar25 - (int)puVar6 & 0xfffffff0U) + *puVar22);
            }
            else {
              puVar6 = *(undefined4 **)(local_98 + 0x24);
              if ((puVar23 == puVar6) && ((int)puVar6 - (int)puVar23 >> 4 == 0)) {
                iVar15 = (int)((int)puVar23 - *puVar22) >> 4;
                if (iVar15 == 0xfffffff) goto LAB_00673a69;
                uVar16 = iVar15 + 1;
                uVar19 = (int)((int)puVar6 - *puVar22) >> 4;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0xfffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve16(uVar19);
              }
            }
            iVar15 = local_98;
            puVar23 = *(undefined4 **)(iVar14 + 0x20);
            if (puVar23 != (undefined4 *)0x0) {
              *puVar23 = *puVar25;
              puVar23[1] = puVar25[1];
              puVar23[2] = puVar25[2];
              puVar23[3] = puVar25[3];
            }
            *(int *)(iVar14 + 0x20) = *(int *)(iVar14 + 0x20) + 0x10;
            puVar23 = *(undefined4 **)(local_98 + 0x14);
            puVar26 = (uint *)(local_98 + 0x10);
            local_2c[0] = 0;
            local_2c[1] = 0;
            uVar2 = local_1c;
            if ((local_2c < puVar23) && ((undefined4 *)*puVar26 <= local_2c)) {
              puVar25 = *(undefined4 **)(local_98 + 0x18);
              local_94 = (undefined4 *)((int)local_2c - (int)*puVar26 >> 3);
              if ((puVar23 == puVar25) && ((int)puVar25 - (int)puVar23 >> 3 == 0)) {
                iVar17 = (int)((int)puVar23 - *puVar26) >> 3;
                if (iVar17 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)((int)puVar25 - *puVar26) >> 3;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve8(uVar19);
              }
              puVar23 = *(undefined4 **)(iVar15 + 0x14);
              uVar19 = *puVar26;
              if (puVar23 != (undefined4 *)0x0) {
                *puVar23 = *(undefined4 *)(uVar19 + (int)local_94 * 8);
                puVar23[1] = *(undefined4 *)(uVar19 + 4 + (int)local_94 * 8);
              }
            }
            else {
              puVar25 = *(undefined4 **)(local_98 + 0x18);
              if ((puVar23 == puVar25) && ((int)puVar25 - (int)puVar23 >> 3 == 0)) {
                iVar17 = (int)((int)puVar23 - *puVar26) >> 3;
                if (iVar17 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)((int)puVar25 - *puVar26) >> 3;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve8(uVar19);
              }
              if (*(undefined8 **)(iVar15 + 0x14) != (undefined8 *)0x0) {
                **(undefined8 **)(iVar15 + 0x14) = CONCAT44(local_2c[1],local_2c[0]);
              }
            }
            *(int *)(iVar15 + 0x14) = *(int *)(iVar15 + 0x14) + 8;
            pfVar21 = (float *)puVar20[1];
            fVar27 = param_1[4] * local_34._4_4_ + *param_1 * (float)local_34 + param_1[0xc];
            fVar30 = param_1[5] * local_34._4_4_ + param_1[1] * (float)local_34 + param_1[0xd];
            fVar28 = 1.0 / (param_1[3] * (float)local_34 + param_1[7] * local_34._4_4_ +
                           param_1[0xf]);
            local_3c = CONCAT44(fVar30,fVar27);
            local_24[1] = fVar30 * fVar28;
            local_24[0] = fVar27 * fVar28;
            uVar2 = local_1c;
            if ((local_24 < pfVar21) && ((float *)*puVar20 <= local_24)) {
              pfVar24 = (float *)puVar20[2];
              local_94 = (undefined4 *)((int)local_24 - (int)*puVar20 >> 3);
              if ((pfVar21 == pfVar24) && ((int)pfVar24 - (int)pfVar21 >> 3 == 0)) {
                iVar17 = (int)((int)pfVar21 - *puVar20) >> 3;
                if (iVar17 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)((int)pfVar24 - *puVar20) >> 3;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve8(uVar19);
              }
              puVar23 = (undefined4 *)puVar20[1];
              uVar19 = *puVar20;
              if (puVar23 != (undefined4 *)0x0) {
                *puVar23 = *(undefined4 *)(uVar19 + (int)local_94 * 8);
                puVar23[1] = *(undefined4 *)(uVar19 + 4 + (int)local_94 * 8);
              }
            }
            else {
              pfVar24 = (float *)puVar20[2];
              if ((pfVar21 == pfVar24) && ((int)pfVar24 - (int)pfVar21 >> 3 == 0)) {
                iVar17 = (int)((int)pfVar21 - *puVar20) >> 3;
                if (iVar17 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)((int)pfVar24 - *puVar20) >> 3;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve8(uVar19);
              }
              pfVar21 = (float *)puVar20[1];
              if (pfVar21 != (float *)0x0) {
                *pfVar21 = local_24[0];
                pfVar21[1] = local_24[1];
              }
            }
            puVar20[1] = puVar20[1] + 8;
            puVar23 = *(undefined4 **)(iVar14 + 0x20);
            puVar25 = (undefined4 *)(*(int *)(local_98 + 0x28) + (int)local_9c);
            uVar2 = local_1c;
            if ((puVar25 < puVar23) && (puVar6 = (undefined4 *)*puVar22, puVar6 <= puVar25)) {
              puVar7 = *(undefined4 **)(iVar14 + 0x24);
              if ((puVar23 == puVar7) && ((int)puVar7 - (int)puVar23 >> 4 == 0)) {
                iVar17 = (int)((int)puVar23 - *puVar22) >> 4;
                if (iVar17 == 0xfffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)((int)puVar7 - *puVar22) >> 4;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0xfffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve16(uVar19);
              }
              puVar25 = (undefined4 *)(((int)puVar25 - (int)puVar6 & 0xfffffff0U) + *puVar22);
            }
            else {
              puVar6 = *(undefined4 **)(iVar14 + 0x24);
              if ((puVar23 == puVar6) && ((int)puVar6 - (int)puVar23 >> 4 == 0)) {
                iVar17 = (int)((int)puVar23 - *puVar22) >> 4;
                if (iVar17 == 0xfffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)((int)puVar6 - *puVar22) >> 4;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0xfffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve16(uVar19);
              }
            }
            puVar23 = *(undefined4 **)(iVar14 + 0x20);
            if (puVar23 != (undefined4 *)0x0) {
              *puVar23 = *puVar25;
              puVar23[1] = puVar25[1];
              puVar23[2] = puVar25[2];
              puVar23[3] = puVar25[3];
            }
            *(int *)(iVar14 + 0x20) = *(int *)(iVar14 + 0x20) + 0x10;
            pfVar21 = *(float **)(iVar15 + 0x14);
            local_44[0] = 0.0;
            local_44[1] = 0.0;
            uVar2 = local_1c;
            if ((local_44 < pfVar21) && (pfVar24 = (float *)*puVar26, pfVar24 <= local_44)) {
              pfVar8 = *(float **)(iVar15 + 0x18);
              iVar14 = (int)local_44 - (int)pfVar24 >> 3;
              if ((pfVar21 == pfVar8) && ((int)pfVar8 - (int)pfVar21 >> 3 == 0)) {
                iVar17 = (int)pfVar21 - (int)pfVar24 >> 3;
                if (iVar17 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = iVar17 + 1;
                uVar19 = (int)pfVar8 - (int)pfVar24 >> 3;
                local_1c = CONCAT44(uVar16,(float)local_1c);
                if (0x1fffffff - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar16) {
                  uVar19 = uVar16;
                }
                vectorReserve8(uVar19);
              }
              puVar23 = *(undefined4 **)(iVar15 + 0x14);
              uVar19 = *puVar26;
              if (puVar23 != (undefined4 *)0x0) {
                *puVar23 = *(undefined4 *)(uVar19 + iVar14 * 8);
                puVar23[1] = *(undefined4 *)(uVar19 + 4 + iVar14 * 8);
              }
            }
            else {
              pfVar24 = *(float **)(iVar15 + 0x18);
              if ((pfVar21 == pfVar24) && ((int)pfVar24 - (int)pfVar21 >> 3 == 0)) {
                iVar14 = (int)((int)pfVar21 - *puVar26) >> 3;
                if (iVar14 == 0x1fffffff) goto LAB_00673a69;
                uVar16 = (int)((int)pfVar24 - *puVar26) >> 3;
                uVar19 = iVar14 + 1;
                if (0x1fffffff - (uVar16 >> 1) < uVar16) {
                  uVar16 = 0;
                }
                else {
                  uVar16 = uVar16 + (uVar16 >> 1);
                }
                if (uVar16 < uVar19) {
                  uVar16 = uVar19;
                }
                vectorReserve8(uVar16);
              }
              pfVar21 = *(float **)(iVar15 + 0x14);
              if (pfVar21 != (float *)0x0) {
                *pfVar21 = local_44[0];
                pfVar21[1] = local_44[1];
              }
            }
            *(int *)(iVar15 + 0x14) = *(int *)(iVar15 + 0x14) + 8;
            piVar18 = (int *)(*(int *)(local_98 + 0x100) + local_90);
            puVar20 = local_a0;
            uVar19 = local_8c;
          } while ((int)local_8c < piVar18[1] - *piVar18 >> 2);
          local_9c = local_b8;
          local_94 = local_bc;
        }
        piVar18 = (int *)(*(int *)(local_98 + 0x100) + local_90);
        iVar14 = 0;
        if (0 < (int)(piVar18[1] - *piVar18 & 0xfffffffcU)) {
          local_1c = CONCAT44(local_d0,(float)local_1c);
          iVar15 = local_d0;
          iVar17 = local_d0;
          do {
            iVar14 = iVar14 + 1;
            local_e4 = iVar17 + (iVar14 % (piVar18[1] - *piVar18 >> 2)) * 2;
            local_e0 = &local_88;
            local_e8 = iVar15;
            std_vector_push_back_0xc(&local_e8);
            local_94 = local_bc;
            local_9c = local_b8;
            if (local_bc != local_b8) {
              iVar15 = ((int)(local_b8 + -3) - (int)local_bc) / 0xc;
              iVar17 = local_d0;
              if (0 < iVar15) {
                local_dc = local_b8[-3];
                local_d8 = local_b8[-2];
                local_d4 = local_b8[-1];
                FUN_00672600(local_bc,iVar15,0,&local_dc,local_b0);
                iVar17 = local_d0;
                local_9c = local_b8;
                local_94 = local_bc;
              }
            }
            piVar18 = (int *)(local_90 + *(int *)(local_98 + 0x100));
            iVar15 = (int)local_1c._4_4_ + 2;
            local_1c = CONCAT44(iVar15,(float)local_1c);
            puVar20 = local_a0;
            local_bc = local_94;
            local_b8 = local_9c;
          } while (iVar14 < piVar18[1] - *piVar18 >> 2);
        }
      }
      local_a8 = local_a8 + 1;
    } while (local_a8 < (*(int *)(local_98 + 0x104) - *(int *)(local_98 + 0x100)) / 0xc);
    puVar23 = local_9c;
    puVar25 = local_94;
    if (local_94 != local_9c) {
      do {
        iVar14 = local_98;
        local_a0 = (uint *)*puVar25;
        uVar19 = *puVar20;
        local_90 = puVar25[1];
        uVar1 = *(undefined8 *)(uVar19 + 8 + (int)local_a0 * 8);
        uVar2 = *(undefined8 *)(uVar19 + local_90 * 8);
        local_3c._0_4_ = (float)uVar1;
        local_3c._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
        fVar29 = (float)local_3c - *(float *)(uVar19 + (int)local_a0 * 8);
        fVar28 = local_3c._4_4_ - *(float *)(uVar19 + 4 + (int)local_a0 * 8);
        local_1c._4_4_ = (float)((ulonglong)uVar2 >> 0x20);
        local_1c._0_4_ = (float)uVar2;
        fVar30 = (float)local_1c - *(float *)(uVar19 + (int)local_a0 * 8);
        fVar27 = local_1c._4_4_ - *(float *)(uVar19 + 4 + (int)local_a0 * 8);
        local_3c = uVar1;
        local_1c = uVar2;
        if ((fVar30 * fVar28 - fVar27 * fVar29) * local_ac < 0.0) {
          puVar22 = (uint *)(local_98 + 0x34);
          ppuVar9 = *(uint ***)(local_98 + 0x38);
          local_cc = local_a0;
          if (&local_cc < ppuVar9) {
            ppuVar10 = (uint **)*puVar22;
            if (&local_cc < ppuVar10) goto LAB_00673c2e;
            ppuVar11 = *(uint ***)(local_98 + 0x3c);
            if ((ppuVar9 == ppuVar11) && ((int)ppuVar11 - (int)ppuVar9 >> 2 == 0)) {
              iVar15 = (int)((int)ppuVar9 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)ppuVar11 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(undefined4 **)(iVar14 + 0x38) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar14 + 0x38) =
                   *(undefined4 *)(*puVar22 + ((int)&local_cc - (int)ppuVar10 >> 2) * 4);
            }
          }
          else {
LAB_00673c2e:
            ppuVar10 = *(uint ***)(local_98 + 0x3c);
            if ((ppuVar9 == ppuVar10) && ((int)ppuVar10 - (int)ppuVar9 >> 2 == 0)) {
              iVar15 = (int)((int)ppuVar9 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) {
LAB_00673a69:
                local_1c = uVar2;
                    /* WARNING: Subroutine does not return */
                std::_Xlength_error("vector<T> too long");
              }
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)ppuVar10 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(undefined4 **)(iVar14 + 0x38) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar14 + 0x38) = local_a0;
            }
          }
          *(int *)(iVar14 + 0x38) = *(int *)(iVar14 + 0x38) + 4;
          piVar18 = *(int **)(iVar14 + 0x38);
          local_a4 = (int)local_a0 + 1;
          uVar2 = local_1c;
          if (&local_a4 < piVar18) {
            piVar12 = (int *)*puVar22;
            if (&local_a4 < piVar12) goto LAB_00673cd4;
            piVar13 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar13) && ((int)piVar13 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar13 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(undefined4 **)(iVar14 + 0x38) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar14 + 0x38) =
                   *(undefined4 *)(*puVar22 + ((int)&local_a4 - (int)piVar12 >> 2) * 4);
            }
          }
          else {
LAB_00673cd4:
            piVar12 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar12) && ((int)piVar12 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar12 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(int **)(iVar14 + 0x38) != (int *)0x0) {
              **(int **)(iVar14 + 0x38) = local_a4;
            }
          }
          *(int *)(iVar14 + 0x38) = *(int *)(iVar14 + 0x38) + 4;
          piVar18 = *(int **)(iVar14 + 0x38);
          local_c8 = local_90;
          uVar2 = local_1c;
          if (&local_c8 < piVar18) {
            piVar12 = (int *)*puVar22;
            if (&local_c8 < piVar12) goto LAB_00673df0;
            piVar13 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar13) && ((int)piVar13 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar13 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(undefined4 **)(iVar14 + 0x38) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar14 + 0x38) =
                   *(undefined4 *)(*puVar22 + ((int)&local_c8 - (int)piVar12 >> 2) * 4);
            }
          }
          else {
LAB_00673df0:
            piVar12 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar12) && ((int)piVar12 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar12 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(int **)(iVar14 + 0x38) != (int *)0x0) {
              **(int **)(iVar14 + 0x38) = local_90;
            }
          }
          *(int *)(iVar14 + 0x38) = *(int *)(iVar14 + 0x38) + 4;
          piVar18 = *(int **)(iVar14 + 0x38);
          local_c4 = local_90;
          uVar2 = local_1c;
          if (&local_c4 < piVar18) {
            piVar12 = (int *)*puVar22;
            if (&local_c4 < piVar12) goto LAB_00673f0c;
            piVar13 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar13) && ((int)piVar13 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar13 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(undefined4 **)(iVar14 + 0x38) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar14 + 0x38) =
                   *(undefined4 *)(*puVar22 + ((int)&local_c4 - (int)piVar12 >> 2) * 4);
            }
          }
          else {
LAB_00673f0c:
            piVar12 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar12) && ((int)piVar12 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar12 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(int **)(iVar14 + 0x38) != (int *)0x0) {
              **(int **)(iVar14 + 0x38) = local_90;
            }
          }
          iVar15 = local_a4;
          *(int *)(iVar14 + 0x38) = *(int *)(iVar14 + 0x38) + 4;
          piVar18 = *(int **)(iVar14 + 0x38);
          local_c0 = local_a4;
          if (&local_c0 < piVar18) {
            piVar12 = (int *)*puVar22;
            if (&local_c0 < piVar12) goto LAB_00674021;
            piVar13 = *(int **)(iVar14 + 0x3c);
            if ((piVar18 == piVar13) && ((int)piVar13 - (int)piVar18 >> 2 == 0)) {
              iVar15 = (int)((int)piVar18 - *puVar22) >> 2;
              uVar2 = local_1c;
              if (iVar15 == 0x3fffffff) goto LAB_00673a69;
              local_8c = iVar15 + 1;
              uVar19 = (int)((int)piVar13 - *puVar22) >> 2;
              if (0x3fffffff - (uVar19 >> 1) < uVar19) {
                uVar19 = 0;
              }
              else {
                uVar19 = uVar19 + (uVar19 >> 1);
              }
              if (uVar19 < local_8c) {
                uVar19 = local_8c;
              }
              std_vector_grow_realloc_stride4(uVar19);
            }
            if (*(undefined4 **)(iVar14 + 0x38) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar14 + 0x38) =
                   *(undefined4 *)(*puVar22 + ((int)&local_c0 - (int)piVar12 >> 2) * 4);
            }
          }
          else {
LAB_00674021:
            if (piVar18 == *(int **)(iVar14 + 0x3c)) {
              std_vector_reserve_stride4(1);
            }
            if (*(int **)(iVar14 + 0x38) != (int *)0x0) {
              **(int **)(iVar14 + 0x38) = iVar15;
            }
          }
          *(int *)(iVar14 + 0x38) = *(int *)(iVar14 + 0x38) + 4;
          local_8c = local_90 + 1;
          std_vector_push_back_4byte(&local_8c);
          puVar23 = local_b8;
          puVar25 = local_bc;
        }
        local_a8 = CONCAT31(local_a8._1_3_,(undefined1)local_b0);
        if (1 < ((int)puVar23 - (int)puVar25) / 0xc) {
          local_dc = puVar23[-3];
          local_d8 = puVar23[-2];
          local_d4 = puVar23[-1];
          puVar23[-3] = *puVar25;
          puVar23[-2] = puVar25[1];
          puVar23[-1] = puVar25[2];
          FUN_006721d0(puVar25,0,((int)puVar23 + (-0xc - (int)puVar25)) / 0xc,&local_dc,local_a8);
          puVar23 = local_b8;
          puVar25 = local_bc;
        }
      } while ((puVar25 != puVar23) &&
              (puVar23 = puVar23 + -3, local_b8 = puVar23, puVar25 != puVar23));
    }
  }
  FUN_00674160();
  local_8 = 0xffffffff;
  if (local_bc == (undefined4 *)0x0) {
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  std::_Container_base0::_Orphan_all((_Container_base0 *)&local_bc);
                    /* WARNING: Subroutine does not return */
  operator_delete(local_bc);
}




/* Global::FUN_00674160 @ 00674160 */

void FUN_00674160(void)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int **ppiVar10;
  int *piVar11;
  undefined4 *puVar12;
  int in_ECX;
  uint uVar13;
  undefined4 *puVar14;
  void *local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c [8];
  undefined4 *local_54;
  undefined4 local_50;
  int *local_4c;
  int local_48;
  undefined4 *local_44;
  int *local_40;
  int local_3c;
  int *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f82f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar14 = (undefined4 *)(in_ECX + 0x100);
  local_44 = puVar14;
  local_18 = in_ECX;
  std_vector_destroy_ptr_elems_stride3(*puVar14,*(undefined4 *)(in_ECX + 0x104),&local_11,puVar14,
               DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  *(undefined4 *)(in_ECX + 0x104) = *puVar14;
  local_54 = (undefined4 *)0x0;
  local_50 = 0;
  local_54 = (undefined4 *)rbtree_allocHead24();
  local_8 = 0;
  local_20 = 0;
  local_28 = 3;
  if (0 < (int)(*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) & 0xfffffffcU)) {
    do {
      local_24 = local_20 * 4;
      local_34 = (undefined4 *)0x0;
      do {
        local_34 = (undefined4 *)((int)local_34 + 1);
        iVar1 = *(int *)(local_24 + *(int *)(in_ECX + 0x34));
        piVar7 = *(int **)(*(int *)(in_ECX + 0x34) + ((int)local_34 % local_28 + local_20) * 4);
        puVar14 = (undefined4 *)local_54[1];
        puVar12 = local_54;
        if (*(char *)((int)local_54[1] + 0xd) == '\0') {
          do {
            if (((int)puVar14[4] < (int)piVar7) ||
               (((int)puVar14[4] <= (int)piVar7 && ((int)puVar14[5] < iVar1)))) {
              puVar4 = (undefined4 *)puVar14[2];
            }
            else {
              puVar4 = (undefined4 *)*puVar14;
              puVar12 = puVar14;
            }
            puVar14 = puVar4;
          } while (*(char *)((int)puVar4 + 0xd) == '\0');
          if (((puVar12 == local_54) || ((int)piVar7 < (int)puVar12[4])) ||
             (((int)piVar7 <= (int)puVar12[4] && (iVar1 < (int)puVar12[5])))) goto LAB_0067425b;
          local_2c = puVar12;
          ppuVar6 = &local_2c;
        }
        else {
LAB_0067425b:
          local_30 = local_54;
          ppuVar6 = &local_30;
        }
        if (*ppuVar6 == local_54) {
          local_3c = iVar1;
          local_38 = piVar7;
          std_map_Insert_hint(local_5c,0,&local_3c,DAT_0076ded5);
        }
        else {
          rbtree_eraseNode(&local_40,*ppuVar6);
        }
        local_24 = local_24 + 4;
        in_ECX = local_18;
      } while ((int)local_34 < 3);
      local_20 = local_20 + 3;
    } while (local_20 < *(int *)(local_18 + 0x38) - *(int *)(local_18 + 0x34) >> 2);
  }
  local_4c = (int *)0x0;
  local_48 = 0;
  local_4c = (int *)rbtree_allocHeaderNode_1c();
  local_8._0_1_ = 1;
  local_20 = 0;
  puVar14 = local_54;
  if (0 < (int)(*(int *)(local_18 + 0x38) - *(int *)(local_18 + 0x34) & 0xfffffffcU)) {
    do {
      local_24 = local_20 * 4;
      local_40 = (int *)0x0;
      do {
        local_40 = (int *)((int)local_40 + 1);
        local_2c = *(undefined4 **)(local_24 + *(int *)(local_18 + 0x34));
        local_38 = *(int **)(*(int *)(local_18 + 0x34) + ((int)local_40 % local_28 + local_20) * 4);
        puVar12 = (undefined4 *)puVar14[1];
        puVar4 = puVar14;
        if (*(char *)((int)puVar14[1] + 0xd) == '\0') {
          do {
            if (((int)puVar12[4] < (int)local_2c) ||
               (((int)puVar12[4] <= (int)local_2c && ((int)puVar12[5] < (int)local_38)))) {
              puVar5 = (undefined4 *)puVar12[2];
            }
            else {
              puVar5 = (undefined4 *)*puVar12;
              puVar4 = puVar12;
            }
            puVar12 = puVar5;
          } while (*(char *)((int)puVar5 + 0xd) == '\0');
          if (((puVar4 == puVar14) || ((int)local_2c < (int)puVar4[4])) ||
             (((int)local_2c <= (int)puVar4[4] && ((int)local_38 < (int)puVar4[5]))))
          goto LAB_00674381;
          local_34 = puVar4;
          ppuVar6 = &local_34;
        }
        else {
LAB_00674381:
          local_30 = puVar14;
          ppuVar6 = &local_30;
        }
        if (*ppuVar6 != puVar14) {
          piVar7 = (int *)std_map_operator_667a90(&local_2c);
          iVar1 = *piVar7;
          iVar8 = IntMap_SetScalar(iVar1,*(undefined4 *)(iVar1 + 4),&local_38);
          if (piVar7[1] == 0x15555554) {
                    /* WARNING: Subroutine does not return */
            std::_Xlength_error("list<T> too long");
          }
          piVar7[1] = piVar7[1] + 1;
          *(int *)(iVar1 + 4) = iVar8;
          **(int **)(iVar8 + 4) = iVar8;
          puVar14 = local_54;
        }
        local_24 = local_24 + 4;
      } while ((int)local_40 < 3);
      local_20 = local_20 + 3;
    } while (local_20 < *(int *)(local_18 + 0x38) - *(int *)(local_18 + 0x34) >> 2);
  }
  do {
    if (local_48 == 0) {
      local_8._0_1_ = 0;
      Sprite_map_erase_range(&local_44,*local_4c,local_4c);
                    /* WARNING: Subroutine does not return */
      operator_delete(local_4c);
    }
    local_68 = (void *)0x0;
    local_64 = 0;
    local_60 = 0;
    local_8._0_1_ = 2;
    std_vector_push_back_move_0xc(&local_68);
    local_8._0_1_ = 1;
    if (local_68 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(local_68);
    }
    local_1c = *(undefined4 **)(*local_4c + 0x10);
    local_2c = local_1c;
    do {
      puVar14 = local_1c;
      piVar7 = (int *)local_4c[1];
      piVar11 = local_4c;
      if (*(char *)((int)piVar7 + 0xd) == '\0') {
        do {
          if (piVar7[4] < (int)local_1c) {
            piVar9 = (int *)piVar7[2];
          }
          else {
            piVar9 = (int *)*piVar7;
            piVar11 = piVar7;
          }
          piVar7 = piVar9;
        } while (*(char *)((int)piVar9 + 0xd) == '\0');
        if ((piVar11 == local_4c) || ((int)local_1c < piVar11[4])) goto LAB_006744b0;
        local_40 = piVar11;
        ppiVar10 = &local_40;
      }
      else {
LAB_006744b0:
        local_38 = local_4c;
        ppiVar10 = &local_38;
      }
      if (*ppiVar10 == local_4c) break;
      piVar11 = (int *)std_map_operator_667a90(&local_1c);
      piVar7 = *(int **)*piVar11;
      local_30 = (undefined4 *)piVar7[2];
      if (piVar7 != (int *)*piVar11) {
        *(int *)piVar7[1] = *piVar7;
        *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
        operator_delete(piVar7);
      }
      if (piVar11[1] == 0) {
        puVar12 = (undefined4 *)std_map_equal_range(local_5c,&local_1c);
        Sprite_map_erase_range(&local_28,*puVar12,puVar12[1]);
      }
      iVar1 = *(int *)(local_18 + 0x104);
      ppuVar6 = *(undefined4 ***)(iVar1 + -8);
      if ((&local_1c < ppuVar6) && (ppuVar2 = *(undefined4 ***)(iVar1 + -0xc), ppuVar2 <= &local_1c)
         ) {
        ppuVar3 = *(undefined4 ***)(iVar1 + -4);
        if ((ppuVar6 == ppuVar3) && ((int)ppuVar3 - (int)ppuVar6 >> 2 == 0)) {
          iVar8 = (int)ppuVar6 - (int)ppuVar2 >> 2;
          if (iVar8 == 0x3fffffff) {
LAB_0067467c:
                    /* WARNING: Subroutine does not return */
            std::_Xlength_error("vector<T> too long");
          }
          local_34 = (undefined4 *)(iVar8 + 1);
          uVar13 = (int)ppuVar3 - (int)ppuVar2 >> 2;
          if (0x3fffffff - (uVar13 >> 1) < uVar13) {
            puVar14 = (undefined4 *)0x0;
          }
          else {
            puVar14 = (undefined4 *)(uVar13 + (uVar13 >> 1));
          }
          if (puVar14 < local_34) {
            puVar14 = local_34;
          }
          std_vector_grow_realloc_stride4(puVar14);
        }
        if (*(undefined4 **)(iVar1 + -8) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar1 + -8) =
               *(undefined4 *)(*(int *)(iVar1 + -0xc) + ((int)&local_1c - (int)ppuVar2 >> 2) * 4);
        }
      }
      else {
        ppuVar2 = *(undefined4 ***)(iVar1 + -4);
        if ((ppuVar6 == ppuVar2) && ((int)ppuVar2 - (int)ppuVar6 >> 2 == 0)) {
          iVar8 = (int)ppuVar6 - *(int *)(iVar1 + -0xc) >> 2;
          if (iVar8 == 0x3fffffff) goto LAB_0067467c;
          local_34 = (undefined4 *)(iVar8 + 1);
          uVar13 = (int)ppuVar2 - *(int *)(iVar1 + -0xc) >> 2;
          if (0x3fffffff - (uVar13 >> 1) < uVar13) {
            puVar12 = (undefined4 *)0x0;
          }
          else {
            puVar12 = (undefined4 *)(uVar13 + (uVar13 >> 1));
          }
          if (puVar12 < local_34) {
            puVar12 = local_34;
          }
          std_vector_grow_realloc_stride4(puVar12);
        }
        if (*(undefined4 **)(iVar1 + -8) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar1 + -8) = puVar14;
        }
      }
      *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 4;
      local_1c = local_30;
    } while (local_30 != local_2c);
  } while( true );
}




/* Global::FUN_00675690 @ 00675690 */

void FUN_00675690(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  int local_28;
  int local_24;
  double local_20;
  double local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  uVar2 = gluNewTess();
  gluTessCallback(uVar2,0x1870b,lib_fn_675670);
  gluTessCallback(uVar2,0x1870f,lib_fn_6751d0);
  gluTessCallback(uVar2,0x18708,cube::AdaptionWidget::vfunc_24);
  gluTessProperty(uVar2,0x1872c,0x40f8723000000000);
  if (*(int *)(in_ECX + 0x40) != *(int *)(in_ECX + 0x44)) {
    *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x34);
    gluTessBeginPolygon(uVar2);
    local_28 = 0;
    if (0 < (*(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40)) / 0xc) {
      local_24 = 0;
      do {
        gluTessBeginContour(uVar2);
        piVar3 = (int *)(local_24 + *(int *)(in_ECX + 0x40));
        if (0 < (int)(piVar3[1] - *piVar3 & 0xfffffffcU)) {
          iVar4 = 0;
          do {
            iVar1 = *(int *)(*piVar3 + iVar4 * 4);
            local_18 = (double)*(float *)(*(int *)(in_ECX + 4) + 4 + iVar1 * 8);
            local_20 = (double)*(float *)(*(int *)(in_ECX + 4) + iVar1 * 8);
            local_10 = 0;
            gluTessVertex(uVar2,&local_20,iVar1);
            piVar3 = (int *)(*(int *)(in_ECX + 0x40) + local_24);
            iVar4 = iVar4 + 1;
          } while (iVar4 < piVar3[1] - *piVar3 >> 2);
        }
        gluTessEndContour(uVar2);
        local_24 = local_24 + 0xc;
        local_28 = local_28 + 1;
      } while (local_28 < (*(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40)) / 0xc);
    }
    gluTessEndPolygon(uVar2);
    gluDeleteTess(uVar2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




