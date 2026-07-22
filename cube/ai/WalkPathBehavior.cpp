// WalkPathBehavior (ai) — cube. 4 functions. Bodies = Ghidra pseudo-C.
#include "WalkPathBehavior.h"

/* cube::WalkPathBehavior::ctor_0 @ 0058cf60 */

void cube::WalkPathBehavior::ctor_0(int source)

{
  undefined4 *self;
  
  *self = vftable;
  WalkPath_CopyConstructVector(source + 4);
  self[4] = *(undefined4 *)(source + 0x10);
  self[5] = 0;
  self[6] = *(undefined4 *)(source + 0x18);
  return;
}




/* cube::WalkPathBehavior::ctor_1 @ 0058cfa0 */

void cube::WalkPathBehavior::ctor_1(undefined4 owner)

{
  undefined4 *self;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
  self[6] = owner;
  return;
}




/* cube::WalkPathBehavior::vfunc_0 @ 0058d050 */

void cube::WalkPathBehavior::vfunc_0(int self,undefined4 param_2,int dt)

{
  char blocked;
  int timer;
  undefined4 uVar3;
  float *pfVar4;
  int iVar5;
  int *timerPtr;
  int in_ECX;
  undefined4 in_EDX;
  uint uVar7;
  int waypointIdx;
  int iVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  uint *puVar13;
  uint local_98;
  int attempt;
  undefined1 local_8c [24];
  undefined1 local_74 [24];
  uint waypoint;
  int iStack_58;
  uint local_54;
  int iStack_50;
  uint local_4c;
  int iStack_48;
  uint randOffset [7];
  int iStack_28;
  int local_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  undefined8 local_14;
  float local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 4) == *(int *)(in_ECX + 8)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,in_EDX,param_2);
    return;
  }
  timerPtr = (int *)(in_ECX + 0x14);
  *timerPtr = *timerPtr - dt;
  timer = *(int *)(in_ECX + 0x14);
  if (*timerPtr < 0) {
    timer = 0;
  }
  *(int *)(in_ECX + 0x14) = timer;
  if (timer != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,in_EDX,param_2);
    return;
  }
  if (*(int *)(in_ECX + 0x10) < 0) {
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  attempt = 0;
  local_14 = 0;
  *(uint *)(in_ECX + 0x10) =
       *(uint *)(in_ECX + 0x10) % (uint)((*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x18);
  *(undefined4 *)(self + 0x40) = 0;
  *(undefined4 *)(self + 0x44) = 0;
  *(undefined4 *)(self + 0x48) = 0;
  timer = *(int *)(in_ECX + 4);
  waypointIdx = *(int *)(in_ECX + 0x10);
  waypoint = *(uint *)(timer + waypointIdx * 0x18);
  iStack_58 = *(int *)(timer + 4 + waypointIdx * 0x18);
  local_54 = *(uint *)(timer + 8 + waypointIdx * 0x18);
  iStack_50 = *(int *)(timer + 0xc + waypointIdx * 0x18);
  local_4c = *(uint *)(timer + 0x10 + waypointIdx * 0x18);
  iStack_48 = *(int *)(timer + 0x14 + waypointIdx * 0x18);
  do {
    local_98 = local_4c;
    waypointIdx = 0;
    local_c = *(float *)(self + 0x88) * 0.5f;
    timer = iStack_48;
    do {
      uVar11 = ftol2();
      randOffset[waypointIdx * 2] = (uint)uVar11;
      randOffset[waypointIdx * 2 + 1] = (uint)((ulonglong)uVar11 >> 0x20);
      waypointIdx = waypointIdx + 1;
    } while (waypointIdx < 3);
    stack0xffffffd4 =
         CONCAT44(iStack_58 + randOffset[1] + (uint)CARRY4(waypoint,randOffset[0]),
                  waypoint + randOffset[0]);
    _local_24 = CONCAT44(iStack_50 + randOffset[3] + (uint)CARRY4(local_54,randOffset[2]),
                         local_54 + randOffset[2]);
    _local_1c = CONCAT44(iStack_48 + randOffset[5] + (uint)CARRY4(local_4c,randOffset[4]),
                         local_4c + randOffset[4]);
    blocked = WalkPathBehavior_isAreaWalkable(randOffset + 6,self + 0x80,0);
    if (blocked != '\0') {
      attempt = 0;
      local_14 = 0;
      goto LAB_0058d260;
    }
    local_4c = local_98 - 0x10000;
    timer = timer + -1 + (uint)(0xffff < local_98);
    attempt = attempt + 1;
    iStack_48 = timer;
  } while (attempt < 0x15);
  goto LAB_0058d415;
  while( true ) {
    if (*(int *)(self + 0x1464) != 0) {
      waypointIdx = *(int *)(*(int *)(self + 0x1460) + 4);
      timerPtr = (int *)vec3i64_toIntFloor(&iStack_20,self + 0x1440);
      uVar11 = *(undefined8 *)(waypointIdx + 8);
      iVar9 = *(int *)(waypointIdx + 0x10) - timerPtr[2];
      local_14._4_4_ = (int)((ulonglong)uVar11 >> 0x20);
      waypointIdx = local_14._4_4_ - timerPtr[1];
      local_14._0_4_ = (int)uVar11;
      iVar5 = (int)local_14 - *timerPtr;
      local_14 = uVar11;
      if ((float)(iVar9 * iVar9 + waypointIdx * waypointIdx + iVar5 * iVar5) <
          *(float *)(self + 0x1458) * *(float *)(self + 0x1458)) break;
    }
    Creature_runPathfindingLoop(self);
    Pathfinding_reconstructPath(self);
    timer = timer + 1;
    if (9 < timer) break;
LAB_0058d570:
    if (0x32 < *(int *)(self + 0x1464)) break;
  }
LAB_0058d5ff:
  *(ushort *)(self + 0x124) = *(ushort *)(self + 0x124) & 0xffbf;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
  while( true ) {
    bVar10 = 0xfffeffff < local_98;
    local_98 = local_98 + 0x10000;
    timer = timer + (uint)bVar10;
    attempt = attempt + 1;
    local_4c = local_98;
    iStack_48 = timer;
    if (0x14 < attempt) break;
LAB_0058d260:
    waypointIdx = 0;
    local_c = *(float *)(self + 0x88) * 0.5f;
    do {
      uVar11 = ftol2();
      randOffset[waypointIdx * 2] = (uint)uVar11;
      randOffset[waypointIdx * 2 + 1] = (uint)((ulonglong)uVar11 >> 0x20);
      waypointIdx = waypointIdx + 1;
    } while (waypointIdx < 3);
    stack0xffffffd4 =
         CONCAT44(iStack_58 + randOffset[1] + (uint)CARRY4(waypoint,randOffset[0]),
                  waypoint + randOffset[0]);
    _local_24 = CONCAT44(iStack_50 + randOffset[3] + (uint)CARRY4(local_54,randOffset[2]),
                         local_54 + randOffset[2]);
    _local_1c = CONCAT44(iStack_48 + randOffset[5] + (uint)CARRY4(local_4c,randOffset[4]),
                         local_4c + randOffset[4]);
    blocked = WalkPathBehavior_isAreaWalkable(randOffset + 6,self + 0x80,0);
    if (blocked == '\0') {
      local_c = *(float *)(self + 0x88) * 0.5f;
      local_14 = 0;
      vec3i64_setFromGen(&local_14);
      puVar13 = &waypoint;
      puVar12 = local_8c;
      vec3i64_copySub(local_74,randOffset);
      uVar3 = vec3i64_copySub(puVar12,puVar13);
      pfVar4 = (float *)vec3i64_toFloat(uVar3);
      if (*(float *)(in_ECX + 0x18) * *(float *)(in_ECX + 0x18) <=
          *pfVar4 * *pfVar4 + pfVar4[1] * pfVar4[1] + pfVar4[2] * pfVar4[2]) {
        if (*(int *)(self + 0x1464) == 0) {
          GameController_clearContainers();
          local_c = 0.1f - *(float *)(self + 0x88) * 0.5f;
          local_14 = 0;
          vec3i64_setFromGen(&local_14);
          uVar3 = vec3i64_copyAdd(local_74,randOffset);
          vec6_copy(uVar3);
          vec6_copy(&waypoint);
          waypointIdx = __alldiv(*(undefined4 *)(self + 0x1448),*(undefined4 *)(self + 0x144c),
                           0x10000,0);
          waypointIdx = (int)(waypointIdx + (waypointIdx >> 0x1f & 0xffU)) >> 8;
          iVar5 = __alldiv(*(undefined4 *)(self + 0x1440),*(undefined4 *)(self + 0x1444),
                           0x10000,0);
          uVar11 = world_getRegionCell64((int)(iVar5 + (iVar5 >> 0x1f & 0xffU)) >> 8,waypointIdx);
          uVar7 = (uint)((ulonglong)uVar11 >> 0x20);
          if ((int)uVar11 == 0) goto LAB_0058d439;
          Creature_expandNeighbors(self);
          *(undefined4 *)(self + 0x1458) = *(undefined4 *)(in_ECX + 0x18);
          Creature_runPathfindingLoop(self);
          Pathfinding_reconstructPath(self);
          *(undefined4 *)(self + 0x40) = 0;
          *(undefined4 *)(self + 0x44) = 0;
          *(undefined4 *)(self + 0x48) = 0;
        }
        if (*(int *)(self + 0x1410) == 0) goto LAB_0058d5ff;
        timer = 0;
        goto LAB_0058d570;
      }
      GameController_clearContainers();
      *(undefined4 *)(self + 0x40) = 0;
      *(undefined4 *)(self + 0x44) = 0;
      *(undefined4 *)(self + 0x48) = 0;
      waypointIdx = rand();
      *(int *)(in_ECX + 0x14) = waypointIdx % 4000 + 2000;
      break;
    }
  }
LAB_0058d415:
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  uVar7 = *(uint *)(in_ECX + 0x10) % (uint)((*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x18);
  *(uint *)(in_ECX + 0x10) = uVar7;
LAB_0058d439:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,uVar7,param_2,timer);
  return;
}




/* cube::WalkPathBehavior::vfunc_1 @ 0058d630 */

undefined4 * cube::WalkPathBehavior::vfunc_1(void)

{
  undefined4 *obj;
  int self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7dcb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  obj = operator_new(0x1c);
  local_8 = 0;
  if (obj != (undefined4 *)0x0) {
    *obj = vftable;
    WalkPath_CopyConstructVector(self + 4);
    obj[4] = *(undefined4 *)(self + 0x10);
    obj[5] = 0;
    obj[6] = *(undefined4 *)(self + 0x18);
    ExceptionList = local_10;
    return obj;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}




