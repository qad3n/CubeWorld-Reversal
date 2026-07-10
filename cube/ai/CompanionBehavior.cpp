// CompanionBehavior (ai) — cube. 4 functions. Bodies = Ghidra pseudo-C.
#include "CompanionBehavior.h"

/* cube::CompanionBehavior::ctor_0 @ 0043ab80 */

void cube::CompanionBehavior::ctor_0(void)

{
  undefined4 *self;
  
  *self = vftable;
  self[2] = 0;
  self[3] = 0;
  return;
}




/* cube::CompanionBehavior::ctor_1 @ 0043aba0 */

void cube::CompanionBehavior::ctor_1(undefined4 targetLo,undefined4 targetHi)

{
  undefined4 *self;
  
  self[2] = targetLo;
  self[3] = targetHi;
  *self = vftable;
  return;
}




/* cube::CompanionBehavior::vfunc_0 @ 0043ace0 */

void cube::CompanionBehavior::vfunc_0(int creature,int target,int deltaMs)

{
  undefined8 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  float *pfVar6;
  int *piVar7;
  int self;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool inRange;
  float10 fVar12;
  double dist2;
  float invLen;
  float velY;
  float velX;
  float velZ;
  undefined1 *puVar18;
  undefined1 auStack_14c [4];
  uint *targetPos;
  float local_144;
  float dist;
  int local_13c;
  int targetEnt;
  uint *selfPos;
  int local_130;
  float local_12c;
  uint distLo;
  int distHi;
  float dirX;
  float dirZ;
  float local_110;
  float local_10c;
  int local_108;
  uint *local_104;
  uint local_100;
  int local_fc;
  int local_f8;
  int iStack_f4;
  int local_f0;
  int iStack_ec;
  int local_e8;
  int iStack_e4;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  float fStack_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float local_b0;
  undefined8 uStack_ac;
  undefined1 local_a0 [24];
  undefined1 auStack_88 [24];
  undefined1 auStack_70 [24];
  undefined1 local_58 [24];
  undefined1 local_40 [24];
  undefined1 auStack_28 [28];
  uint cookie;
  
  cookie = DAT_0076aa78 ^ (uint)auStack_14c;
  local_13c = creature;
  local_130 = target;
  rbtree_lowerBound_pairKey(&local_144,self + 8);
  iVar2 = local_13c;
  if ((local_144 != *(float *)(target + 4)) &&
     (targetEnt = *(int *)((int)local_144 + 0x18), targetEnt != 0)) {
    targetPos = (uint *)(targetEnt + 0x10);
    dist = *(float *)(targetEnt + 0x24);
    selfPos = (uint *)(local_13c + 0x10);
    local_d0 = *(uint *)(targetEnt + 0x10) - *selfPos;
    local_cc = (*(int *)(targetEnt + 0x14) - *(int *)(local_13c + 0x14)) -
               (uint)(*(uint *)(targetEnt + 0x10) < *selfPos);
    local_c8 = *(uint *)(targetEnt + 0x18) - *(uint *)(local_13c + 0x18);
    local_c4 = (*(int *)(targetEnt + 0x1c) - *(int *)(local_13c + 0x1c)) -
               (uint)(*(uint *)(targetEnt + 0x18) < *(uint *)(local_13c + 0x18));
    local_c0 = *(uint *)(targetEnt + 0x20) - *(uint *)(local_13c + 0x20);
    local_bc = ((int)dist - *(int *)(local_13c + 0x24)) -
               (uint)(*(uint *)(targetEnt + 0x20) < *(uint *)(local_13c + 0x20));
    vec3i64_dotFixed(&distLo,&local_d0);
    if ((distHi < 0) || ((distHi < 1 && (distLo < 0x400001)))) {
      inRange = false;
    }
    else {
      inRange = true;
    }
    if (inRange) {
      *(ushort *)(iVar2 + 0x124) = *(ushort *)(iVar2 + 0x124) | 0x40;
    }
    else {
      *(ushort *)(iVar2 + 0x124) = *(ushort *)(iVar2 + 0x124) & 0xffbf;
    }
    if (*(char *)(iVar2 + 0x60) == '\x05') {
      fVar12 = (float10)stat_calcAttackDamage();
      dist = (float)fVar12 * (float)deltaMs * 0.001 * 0.1 + *(float *)(iVar2 + 0x16c);
      *(float *)(iVar2 + 0x16c) = dist;
      fVar12 = (float10)stat_calcAttackDamage();
      local_12c = (float)fVar12;
      if (local_12c < dist) {
        fVar12 = (float10)stat_calcAttackDamage();
        *(float *)(iVar2 + 0x16c) = (float)fVar12;
      }
    }
    iVar8 = targetEnt;
    iVar2 = local_13c;
    local_f8 = *targetPos - *selfPos;
    iStack_f4 = (targetPos[1] - selfPos[1]) - (uint)(*targetPos < *selfPos);
    local_f0 = *(uint *)(targetEnt + 0x18) - *(uint *)(local_13c + 0x18);
    iStack_ec = (*(int *)(targetEnt + 0x1c) - *(int *)(local_13c + 0x1c)) -
                (uint)(*(uint *)(targetEnt + 0x18) < *(uint *)(local_13c + 0x18));
    local_e8 = *(uint *)(targetEnt + 0x20) - *(uint *)(local_13c + 0x20);
    iStack_e4 = (*(int *)(targetEnt + 0x24) - *(int *)(local_13c + 0x24)) -
                (uint)(*(uint *)(targetEnt + 0x20) < *(uint *)(local_13c + 0x20));
    dirX = (float)CONCAT44(iStack_f4,local_f8) * 1.5258789e-05;
    targetPos = (uint *)(float)CONCAT44(iStack_e4,local_e8);
    dirZ = (float)CONCAT44(iStack_ec,local_f0) * 1.5258789e-05;
    *(undefined4 *)(local_13c + 0x40) = 0;
    *(undefined4 *)(local_13c + 0x44) = 0;
    *(undefined4 *)(local_13c + 0x48) = 0;
    if (16.0 <= dirZ * dirZ + dirX * dirX +
                (float)targetPos * 1.5258789e-05 * (float)targetPos * 1.5258789e-05) {
      pfVar6 = (float *)(targetEnt + 0x10);
      cVar3 = vec_normalize_or_distance(local_13c,local_13c + 0x10,pfVar6,
                           *(float *)(local_13c + 0x80) + *(float *)(targetEnt + 0x80));
      if (cVar3 != '\0') {
        GameController_clearContainers();
        velX = dirX * 5.0;
        velZ = dirZ * 5.0;
        velY = 0.0;
        local_144 = 0.0;
        invLen = velZ * velZ + velX * velX + 0.0;
        targetPos = (uint *)velX;
        local_12c = velZ;
        if (900.0 < invLen) {
          dist2 = (double)invLen;
          libm_sse2_sqrt_precise();
          invLen = 1.0 / (float)dist2;
          velX = (float)targetPos * invLen * 30.0;
          velZ = local_12c * invLen * 30.0;
          velY = local_144 * invLen * 30.0;
        }
        *(float *)(iVar2 + 0x40) = velX;
        *(float *)(iVar2 + 0x44) = velZ;
        *(float *)(iVar2 + 0x48) = velY;
        __security_check_cookie(cookie ^ (uint)auStack_14c);
        return;
      }
      local_144 = *pfVar6;
      dist = *(float *)(iVar8 + 0x14);
      selfPos = *(uint **)(iVar8 + 0x1c);
      local_13c = *(int *)(iVar8 + 0x18);
      uVar9 = *(uint *)(iVar8 + 0x20);
      iVar8 = *(int *)(iVar8 + 0x24);
      targetEnt = 0;
      local_110 = local_144;
      local_10c = dist;
      local_108 = local_13c;
      local_104 = selfPos;
      do {
        local_100 = uVar9;
        local_fc = iVar8;
        iVar4 = world_getColumnAtFixedPos(local_144,dist,local_13c,selfPos,uVar9,iVar8,0);
        if (((*(byte *)(iVar4 + 3) & 0x1f) != 0) && ((*(byte *)(iVar4 + 3) & 0x1f) != 2)) {
          targetEnt = 0;
          goto LAB_0043b110;
        }
        inRange = 0xffff < uVar9;
        uVar9 = uVar9 - 0x10000;
        iVar8 = iVar8 + -1 + (uint)inRange;
        targetEnt = targetEnt + 1;
        local_100 = uVar9;
        local_fc = iVar8;
      } while (targetEnt < 0x15);
    }
  }
  goto LAB_0043b15c;
  while( true ) {
    if (*(int *)(iVar2 + 0x1464) != 0) {
      iVar8 = *(int *)(*(int *)(iVar2 + 0x1460) + 4);
      piVar7 = (int *)vec3i64_toIntFloor(auStack_70,iVar2 + 0x1440);
      uVar1 = *(undefined8 *)(iVar8 + 8);
      iVar10 = *(int *)(iVar8 + 0x10) - piVar7[2];
      uStack_ac._4_4_ = (int)((ulonglong)uVar1 >> 0x20);
      iVar8 = uStack_ac._4_4_ - piVar7[1];
      uStack_ac._0_4_ = (int)uVar1;
      iVar4 = (int)uStack_ac - *piVar7;
      uStack_ac = uVar1;
      if ((float)(iVar10 * iVar10 + iVar8 * iVar8 + iVar4 * iVar4) <
          *(float *)(iVar2 + 0x1458) * *(float *)(iVar2 + 0x1458)) break;
    }
    Creature_runPathfindingLoop(iVar2);
    Pathfinding_reconstructPath(iVar2);
    local_144 = (float)((int)local_144 + 1);
    if (9 < (int)local_144) break;
LAB_0043b390:
    if (0x32 < *(int *)(iVar2 + 0x1464)) break;
  }
LAB_0043b431:
  __security_check_cookie(cookie ^ (uint)auStack_14c);
  return;
  while( true ) {
    inRange = 0xfffeffff < uVar9;
    uVar9 = uVar9 + 0x10000;
    iVar8 = iVar8 + (uint)inRange;
    targetEnt = targetEnt + 1;
    local_100 = uVar9;
    local_fc = iVar8;
    if (0x14 < targetEnt) break;
LAB_0043b110:
    iVar4 = world_getColumnAtFixedPos(local_144,dist,local_13c,selfPos,uVar9,iVar8,0);
    if (((*(byte *)(iVar4 + 3) & 0x1f) == 0) || ((*(byte *)(iVar4 + 3) & 0x1f) == 2)) {
      local_b0 = *(float *)(iVar2 + 0x88) * 0.5;
      local_b8 = 0;
      local_b4 = 0;
      vec3i64_setFromGen(&local_b8);
      pfVar6 = &local_110;
      puVar18 = local_58;
      vec3i64_copySub(local_40,local_a0);
      uVar5 = vec3i64_copySub(puVar18,pfVar6);
      pfVar6 = (float *)vec3i64_toFloat(uVar5);
      if (*pfVar6 * *pfVar6 + pfVar6[1] * pfVar6[1] + pfVar6[2] * pfVar6[2] < 16.0) {
        GameController_clearContainers();
        *(undefined4 *)(iVar2 + 0x40) = 0;
        *(undefined4 *)(iVar2 + 0x44) = 0;
        *(undefined4 *)(iVar2 + 0x48) = 0;
        break;
      }
      if (*(int *)(iVar2 + 0x1464) == 0) {
        GameController_clearContainers();
        fStack_d4 = 0.1 - *(float *)(iVar2 + 0x88) * 0.5;
        uStack_dc = 0;
        uStack_d8 = 0;
        vec3i64_setFromGen(&uStack_dc);
        uVar5 = vec3i64_copyAdd(auStack_28,auStack_88);
        vec6_copy(uVar5);
        vec6_copy(&local_110);
        iVar8 = __alldiv(*(undefined4 *)(iVar2 + 0x1448),*(undefined4 *)(iVar2 + 0x144c),0x10000,0);
        iVar8 = (int)(iVar8 + (iVar8 >> 0x1f & 0xffU)) >> 8;
        iVar4 = __alldiv(*(undefined4 *)(iVar2 + 0x1440),*(undefined4 *)(iVar2 + 0x1444),0x10000,0);
        iVar8 = world_getRegionCell64((int)(iVar4 + (iVar4 >> 0x1f & 0xffU)) >> 8,iVar8);
        if (iVar8 == 0) break;
        Creature_expandNeighbors(iVar2);
        *(undefined4 *)(iVar2 + 0x1458) = 0x40000000;
        Creature_runPathfindingLoop(iVar2);
        Pathfinding_reconstructPath(iVar2);
        *(undefined4 *)(iVar2 + 0x40) = 0;
        *(undefined4 *)(iVar2 + 0x44) = 0;
        *(undefined4 *)(iVar2 + 0x48) = 0;
      }
      if (*(int *)(iVar2 + 0x1410) == 0) goto LAB_0043b431;
      local_144 = 0.0;
      goto LAB_0043b390;
    }
  }
LAB_0043b15c:
  __security_check_cookie(cookie ^ (uint)auStack_14c);
  return;
}




/* cube::CompanionBehavior::vfunc_1 @ 0043b450 */

undefined4 * cube::CompanionBehavior::vfunc_1(void)

{
  undefined4 *clone;
  int self;
  
  clone = operator_new(0x10);
  if (clone != (undefined4 *)0x0) {
    *clone = vftable;
    clone[2] = *(undefined4 *)(self + 8);
    clone[3] = *(undefined4 *)(self + 0xc);
    return clone;
  }
  return (undefined4 *)0x0;
}




