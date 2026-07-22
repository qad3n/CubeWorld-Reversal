// CompanionBehavior (ai) — server. 5 functions. Bodies = Ghidra pseudo-C.
#include "CompanionBehavior.h"

/* cube::CompanionBehavior::ctor_0 @ 004055d0 */

undefined4 * __fastcall cube::CompanionBehavior::ctor_0(undefined4 *self)

{
  *self = vftable;
  self[2] = 0;
  self[3] = 0;
  return self;
}




/* cube::CompanionBehavior::ctor_1 @ 004055f0 */

undefined4 * __thiscall
cube::CompanionBehavior::ctor_1(CompanionBehavior *this,undefined4 target_lo,undefined4 target_hi)

{
  *(undefined4 *)(this + 8) = target_lo;
  *(undefined4 *)(this + 0xc) = target_hi;
  *(undefined ***)this = vftable;
  return (undefined4 *)this;
}




/* [AUDIT] proposed: Vec3_fixedMatMulAcc  (confidence: med)
 * purpose: Fixed-point multiply of vec by 3 this-components, /0x10000, accumulated; dot/transform
 * vars: this=3x int64 coeffs; target_hi=vec 3x int64
 */
/* Global::Vec3_fixedMatMulAcc @ 004056c0 */

uint * __thiscall Vec3_fixedMatMulAcc(void *this,uint *dst,uint *vec)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar5 = __allmul(*vec,vec[1],*(uint *)this,*(int *)((int)this + 4));
  uVar6 = __alldiv((uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20),0x10000,0);
  uVar1 = vec[3];
  uVar2 = vec[2];
  iVar3 = *(int *)((int)this + 0xc);
  *(undefined8 *)dst = uVar6;
  lVar5 = __allmul(*(uint *)((int)this + 8),iVar3,uVar2,uVar1);
  uVar6 = __alldiv((uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20),0x10000,0);
  uVar2 = vec[5];
  uVar1 = *dst;
  *dst = *dst + (uint)uVar6;
  uVar4 = vec[4];
  iVar3 = *(int *)((int)this + 0x14);
  dst[1] = dst[1] + (int)((ulonglong)uVar6 >> 0x20) + (uint)CARRY4(uVar1,(uint)uVar6);
  lVar5 = __allmul(*(uint *)((int)this + 0x10),iVar3,uVar4,uVar2);
  uVar6 = __alldiv((uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20),0x10000,0);
  uVar1 = *dst;
  *dst = *dst + (uint)uVar6;
  dst[1] = dst[1] + (int)((ulonglong)uVar6 >> 0x20) + (uint)CARRY4(uVar1,(uint)uVar6);
  return dst;
}




/* cube::CompanionBehavior::vfunc_0 @ 00405780 */

void __thiscall
cube::CompanionBehavior::vfunc_0(CompanionBehavior *this,void *creature,void *world,int dt)

{
  void *pvVar1;
  char cVar2;
  int iVar3;
  uint *this_00;
  uint *puVar4;
  float *pfVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  void *this_01;
  uint uVar9;
  int iVar10;
  bool bVar11;
  float fVar12;
  double dVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined8 uVar18;
  undefined1 auStack_14c [4];
  uint *local_148;
  float local_144;
  float local_140;
  void *creature_p;
  int target;
  uint *local_134;
  void *world_p;
  float local_12c;
  uint local_128;
  int local_124;
  float local_11c;
  float local_118;
  float local_110;
  float local_10c;
  void *local_108;
  uint *local_104;
  uint local_100;
  uint local_fc;
  int local_f8;
  int iStack_f4;
  int local_f0;
  int iStack_ec;
  int local_e8;
  int iStack_e4;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  float fStack_d4;
  uint local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float local_b0;
  undefined8 uStack_ac;
  uint local_a0 [6];
  uint auStack_88 [6];
  int aiStack_70 [3];
  undefined1 local_64 [12];
  uint local_58 [6];
  uint local_40 [6];
  uint auStack_28 [7];
  uint local_c;
  
  local_c = DAT_00583cc8 ^ (uint)auStack_14c;
  creature_p = creature;
  world_p = world;
  std_map_lower_bound_yx((float *)((int)world + 4),(int *)&local_144,(uint *)(this + 8));
  pvVar1 = creature_p;
  if ((local_144 != *(float *)((int)world + 4)) &&
     (target = *(int *)((int)local_144 + 0x18), target != 0)) {
    local_148 = (uint *)(target + 0x10);
    local_140 = *(float *)(target + 0x24);
    local_134 = (uint *)((int)creature_p + 0x10);
    local_d0 = *(uint *)(target + 0x10) - *local_134;
    local_cc = (*(int *)(target + 0x14) - *(int *)((int)creature_p + 0x14)) -
               (uint)(*(uint *)(target + 0x10) < *local_134);
    local_c8 = *(uint *)(target + 0x18) - *(uint *)((int)creature_p + 0x18);
    local_c4 = (*(int *)(target + 0x1c) - *(int *)((int)creature_p + 0x1c)) -
               (uint)(*(uint *)(target + 0x18) < *(uint *)((int)creature_p + 0x18));
    local_c0 = *(uint *)(target + 0x20) - *(uint *)((int)creature_p + 0x20);
    local_bc = ((int)local_140 - *(int *)((int)creature_p + 0x24)) -
               (uint)(*(uint *)(target + 0x20) < *(uint *)((int)creature_p + 0x20));
    Vec3_fixedMatMulAcc(&local_d0,&local_128,&local_d0);
    if ((local_124 < 0) || ((local_124 < 1 && (local_128 < 0x400001)))) {
      bVar11 = false;
    }
    else {
      bVar11 = true;
    }
    if (bVar11) {
      *(ushort *)((int)pvVar1 + 0x124) = *(ushort *)((int)pvVar1 + 0x124) | 0x40;
    }
    else {
      *(ushort *)((int)pvVar1 + 0x124) = *(ushort *)((int)pvVar1 + 0x124) & 0xffbf;
    }
    if (*(char *)((int)pvVar1 + 0x60) == '\x05') {
      fVar12 = Combat_computeMaxHealth((int)pvVar1);
      local_140 = (float)fVar12 * (float)dt * 0.001 * 0.1 + *(float *)((int)pvVar1 + 0x16c);
      *(float *)((int)pvVar1 + 0x16c) = local_140;
      fVar12 = Combat_computeMaxHealth((int)pvVar1);
      local_12c = (float)fVar12;
      if (local_12c < local_140) {
        fVar12 = Combat_computeMaxHealth((int)pvVar1);
        *(float *)((int)pvVar1 + 0x16c) = (float)fVar12;
      }
    }
    iVar3 = target;
    pvVar1 = creature_p;
    local_f8 = *local_148 - *local_134;
    iStack_f4 = (local_148[1] - local_134[1]) - (uint)(*local_148 < *local_134);
    local_f0 = *(uint *)(target + 0x18) - *(uint *)((int)creature_p + 0x18);
    iStack_ec = (*(int *)(target + 0x1c) - *(int *)((int)creature_p + 0x1c)) -
                (uint)(*(uint *)(target + 0x18) < *(uint *)((int)creature_p + 0x18));
    local_e8 = *(uint *)(target + 0x20) - *(uint *)((int)creature_p + 0x20);
    iStack_e4 = (*(int *)(target + 0x24) - *(int *)((int)creature_p + 0x24)) -
                (uint)(*(uint *)(target + 0x20) < *(uint *)((int)creature_p + 0x20));
    local_11c = (float)CONCAT44(iStack_f4,local_f8) * 1.5258789e-05;
    local_148 = (uint *)(float)CONCAT44(iStack_e4,local_e8);
    local_118 = (float)CONCAT44(iStack_ec,local_f0) * 1.5258789e-05;
    *(undefined4 *)((int)creature_p + 0x40) = 0;
    *(undefined4 *)((int)creature_p + 0x44) = 0;
    *(undefined4 *)((int)creature_p + 0x48) = 0;
    if (16.0 <= local_118 * local_118 + local_11c * local_11c +
                (float)local_148 * 1.5258789e-05 * (float)local_148 * 1.5258789e-05) {
      pfVar5 = (float *)(target + 0x10);
      cVar2 = Creature_resolveSeparation(world_p,(int)creature_p,(uint *)((int)creature_p + 0x10),(uint *)pfVar5,
                           *(float *)((int)creature_p + 0x80) + *(float *)(target + 0x80));
      if (cVar2 != '\0') {
        World_clearContainers((int)pvVar1);
        fVar16 = local_11c * 5.0;
        fVar17 = local_118 * 5.0;
        fVar15 = 0.0;
        local_144 = 0.0;
        fVar14 = fVar17 * fVar17 + fVar16 * fVar16 + 0.0;
        local_148 = (uint *)fVar16;
        local_12c = fVar17;
        if (900.0 < fVar14) {
          dVar13 = libm_sse2_sqrt_precise((double)fVar14);
          fVar14 = 1.0 / (float)dVar13;
          fVar16 = (float)local_148 * fVar14 * 30.0;
          fVar17 = local_12c * fVar14 * 30.0;
          fVar15 = local_144 * fVar14 * 30.0;
        }
        *(float *)((int)pvVar1 + 0x40) = fVar16;
        *(float *)((int)pvVar1 + 0x44) = fVar17;
        *(float *)((int)pvVar1 + 0x48) = fVar15;
        __security_check_cookie(local_c ^ (uint)auStack_14c);
        return;
      }
      local_144 = *pfVar5;
      local_140 = *(float *)(iVar3 + 0x14);
      local_134 = *(uint **)(iVar3 + 0x1c);
      creature_p = *(void **)(iVar3 + 0x18);
      uVar9 = *(uint *)(iVar3 + 0x20);
      uVar8 = *(uint *)(iVar3 + 0x24);
      target = 0;
      local_110 = local_144;
      local_10c = local_140;
      local_108 = creature_p;
      local_104 = local_134;
      do {
        local_100 = uVar9;
        local_fc = uVar8;
        iVar3 = World_getBlockFloat(world_p,(uint)local_144,(uint)local_140,(uint)creature_p,
                             (uint)local_134,uVar9,uVar8,0);
        if (((*(byte *)(iVar3 + 3) & 0x1f) != 0) && ((*(byte *)(iVar3 + 3) & 0x1f) != 2)) {
          target = 0;
          goto LAB_00405bb0;
        }
        bVar11 = 0xffff < uVar9;
        uVar9 = uVar9 - 0x10000;
        uVar8 = (uVar8 - 1) + (uint)bVar11;
        target = target + 1;
        local_100 = uVar9;
        local_fc = uVar8;
      } while (target < 0x15);
    }
  }
  goto LAB_00405bfc;
  while( true ) {
    if (*(int *)((int)pvVar1 + 0x1464) != 0) {
      iVar3 = *(int *)(*(int *)((int)pvVar1 + 0x1460) + 4);
      piVar6 = (int *)Vec3i64_toBlockCoords(aiStack_70,(uint *)((int)pvVar1 + 0x1440));
      uVar18 = *(undefined8 *)(iVar3 + 8);
      iVar10 = *(int *)(iVar3 + 0x10) - piVar6[2];
      uStack_ac._4_4_ = (int)((ulonglong)uVar18 >> 0x20);
      iVar3 = uStack_ac._4_4_ - piVar6[1];
      uStack_ac._0_4_ = (int)uVar18;
      iVar7 = (int)uStack_ac - *piVar6;
      uStack_ac = uVar18;
      if ((float)(iVar10 * iVar10 + iVar3 * iVar3 + iVar7 * iVar7) <
          *(float *)((int)pvVar1 + 0x1458) * *(float *)((int)pvVar1 + 0x1458)) break;
    }
    NavGraph_findPath(this_01,pvVar1);
    NavGraph_reconstructPath(pvVar1);
    local_144 = (float)((int)local_144 + 1);
    if (9 < (int)local_144) break;
LAB_00405e30:
    if (0x32 < *(int *)((int)pvVar1 + 0x1464)) break;
  }
LAB_00405ed1:
  __security_check_cookie(local_c ^ (uint)auStack_14c);
  return;
  while( true ) {
    bVar11 = 0xfffeffff < uVar9;
    uVar9 = uVar9 + 0x10000;
    uVar8 = uVar8 + bVar11;
    target = target + 1;
    local_100 = uVar9;
    local_fc = uVar8;
    if (0x14 < target) break;
LAB_00405bb0:
    iVar3 = World_getBlockFloat(world_p,(uint)local_144,(uint)local_140,(uint)creature_p,(uint)local_134,
                         uVar9,uVar8,0);
    if (((*(byte *)(iVar3 + 3) & 0x1f) == 0) || ((*(byte *)(iVar3 + 3) & 0x1f) == 2)) {
      local_b0 = *(float *)((int)pvVar1 + 0x88) * 0.5;
      local_b8 = 0;
      local_b4 = 0;
      Vec3i64_randomize((int)local_a0);
      pfVar5 = &local_110;
      puVar4 = local_58;
      this_00 = Vec3i64_subtract((void *)((int)pvVar1 + 0x10),local_40,local_a0);
      puVar4 = Vec3i64_subtract(this_00,puVar4,(uint *)pfVar5);
      pfVar5 = Vec3i64_toFloatScaled(local_64,(longlong *)puVar4);
      if (*pfVar5 * *pfVar5 + pfVar5[1] * pfVar5[1] + pfVar5[2] * pfVar5[2] < 16.0) {
        World_clearContainers((int)pvVar1);
        *(undefined4 *)((int)pvVar1 + 0x40) = 0;
        *(undefined4 *)((int)pvVar1 + 0x44) = 0;
        *(undefined4 *)((int)pvVar1 + 0x48) = 0;
        break;
      }
      this_01 = world_p;
      if (*(int *)((int)pvVar1 + 0x1464) == 0) {
        World_clearContainers((int)pvVar1);
        fStack_d4 = 0.1 - *(float *)((int)pvVar1 + 0x88) * 0.5;
        uStack_dc = 0;
        uStack_d8 = 0;
        Vec3i64_randomize((int)auStack_88);
        puVar4 = Vec3i64_add((void *)((int)pvVar1 + 0x10),auStack_28,auStack_88);
        Copy24Bytes((void *)((int)pvVar1 + 0x1428),puVar4);
        Copy24Bytes((void *)((int)pvVar1 + 0x1440),&local_110);
        uVar18 = __alldiv(*(uint *)((int)pvVar1 + 0x1448),*(uint *)((int)pvVar1 + 0x144c),0x10000,0)
        ;
        uVar9 = (int)((int)uVar18 + ((int)uVar18 >> 0x1f & 0xffU)) >> 8;
        uVar18 = __alldiv(*(uint *)((int)pvVar1 + 0x1440),*(uint *)((int)pvVar1 + 0x1444),0x10000,0)
        ;
        this_01 = world_p;
        iVar3 = Region_getChunkCell(world_p,(int)((int)uVar18 + ((int)uVar18 >> 0x1f & 0xffU)) >> 8,uVar9
                            );
        if (iVar3 == 0) break;
        NavGraph_expandNeighbors(this_01,pvVar1);
        *(undefined4 *)((int)pvVar1 + 0x1458) = 0x40000000;
        NavGraph_findPath(this_01,pvVar1);
        NavGraph_reconstructPath(pvVar1);
        *(undefined4 *)((int)pvVar1 + 0x40) = 0;
        *(undefined4 *)((int)pvVar1 + 0x44) = 0;
        *(undefined4 *)((int)pvVar1 + 0x48) = 0;
      }
      if (*(int *)((int)pvVar1 + 0x1410) == 0) goto LAB_00405ed1;
      local_144 = 0.0;
      goto LAB_00405e30;
    }
  }
LAB_00405bfc:
  __security_check_cookie(local_c ^ (uint)auStack_14c);
  return;
}




/* cube::CompanionBehavior::vfunc_1 @ 00405ef0 */

undefined4 * __fastcall cube::CompanionBehavior::vfunc_1(int src)

{
  undefined4 *new_obj;
  
  new_obj = operator_new(0x10);
  if (new_obj != (undefined4 *)0x0) {
    *new_obj = vftable;
    new_obj[2] = *(undefined4 *)(src + 8);
    new_obj[3] = *(undefined4 *)(src + 0xc);
    return new_obj;
  }
  return (undefined4 *)0x0;
}




