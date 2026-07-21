// WalkPathBehavior (ai) — server. 4 functions. Bodies = Ghidra pseudo-C.
#include "WalkPathBehavior.h"

/* cube::WalkPathBehavior::ctor_1 @ 004c5d10 */

undefined4 * __thiscall cube::WalkPathBehavior::ctor_1(WalkPathBehavior *this,int src)

{
  *(undefined ***)this = vftable;
  std_vector_copy_ctor(this + 4,(int *)(src + 4));
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(src + 0x10);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(src + 0x18);
  return (undefined4 *)this;
}




/* cube::WalkPathBehavior::ctor_0 @ 004c5d50 */

undefined4 * __thiscall cube::WalkPathBehavior::ctor_0(WalkPathBehavior *this,undefined4 owner)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x18) = owner;
  return (undefined4 *)this;
}




/* cube::WalkPathBehavior::vfunc_0 @ 004c5e00 */

void __thiscall
cube::WalkPathBehavior::vfunc_0(WalkPathBehavior *this,void *creature,void *world,int dt)

{
  WalkPathBehavior *pWVar1;
  char blocked;
  int axis;
  uint *this_00;
  uint *puVar4;
  float *pfVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  uint *puVar14;
  int local_9c;
  uint local_98;
  int attempt;
  uint local_8c [6];
  uint local_74 [6];
  uint wp_x;
  int iStack_58;
  uint wp_y;
  int iStack_50;
  uint wp_z;
  int iStack_48;
  uint rand_offset [7];
  int iStack_28;
  int local_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  undefined8 local_14;
  float half_height;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
    return;
  }
  pWVar1 = this + 0x14;
  *(int *)pWVar1 = *(int *)pWVar1 - dt;
  axis = *(int *)(this + 0x14);
  if (*(int *)pWVar1 < 0) {
    axis = 0;
  }
  *(int *)(this + 0x14) = axis;
  if (axis != 0) {
    __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)(this + 0x10) < 0) {
    *(undefined4 *)(this + 0x10) = 0;
  }
  attempt = 0;
  local_14 = 0;
  *(uint *)(this + 0x10) =
       *(uint *)(this + 0x10) % (uint)((*(int *)(this + 8) - *(int *)(this + 4)) / 0x18);
  *(undefined4 *)((int)creature + 0x40) = 0;
  *(undefined4 *)((int)creature + 0x44) = 0;
  *(undefined4 *)((int)creature + 0x48) = 0;
  axis = *(int *)(this + 4);
  iVar8 = *(int *)(this + 0x10);
  wp_x = *(uint *)(axis + iVar8 * 0x18);
  iStack_58 = *(int *)(axis + 4 + iVar8 * 0x18);
  wp_y = *(uint *)(axis + 8 + iVar8 * 0x18);
  iStack_50 = *(int *)(axis + 0xc + iVar8 * 0x18);
  wp_z = *(uint *)(axis + 0x10 + iVar8 * 0x18);
  iStack_48 = *(int *)(axis + 0x14 + iVar8 * 0x18);
  do {
    local_9c = iStack_48;
    local_98 = wp_z;
    axis = 0;
    half_height = *(float *)((int)creature + 0x88) * 0.5;
    do {
      uVar12 = ftol2();
      rand_offset[axis * 2] = (uint)uVar12;
      rand_offset[axis * 2 + 1] = (uint)(uVar12 >> 0x20);
      axis = axis + 1;
    } while (axis < 3);
    stack0xffffffd4 =
         CONCAT44(iStack_58 + rand_offset[1] + (uint)CARRY4(wp_x,rand_offset[0]),
                  wp_x + rand_offset[0]);
    _local_24 = CONCAT44(iStack_50 + rand_offset[3] + (uint)CARRY4(wp_y,rand_offset[2]),
                         wp_y + rand_offset[2]);
    _local_1c = CONCAT44(iStack_48 + rand_offset[5] + (uint)CARRY4(wp_z,rand_offset[4]),
                         wp_z + rand_offset[4]);
    blocked = WalkPathBehavior_checkPathClear(world,rand_offset + 6,(float *)((int)creature + 0x80),'\0');
    if (blocked != '\0') {
      attempt = 0;
      local_14 = 0;
      goto LAB_004c6010;
    }
    wp_z = local_98 - 0x10000;
    iStack_48 = local_9c + -1 + (uint)(0xffff < local_98);
    attempt = attempt + 1;
  } while (attempt < 0x15);
  goto LAB_004c61c5;
  while( true ) {
    if (*(int *)((int)creature + 0x1464) != 0) {
      iVar8 = *(int *)(*(int *)((int)creature + 0x1460) + 4);
      piVar7 = (int *)Vec3i64_toBlockCoords(&iStack_20,(uint *)((int)creature + 0x1440));
      uVar13 = *(undefined8 *)(iVar8 + 8);
      iVar10 = *(int *)(iVar8 + 0x10) - piVar7[2];
      local_14._4_4_ = (int)((ulonglong)uVar13 >> 0x20);
      iVar8 = local_14._4_4_ - piVar7[1];
      local_14._0_4_ = (int)uVar13;
      iVar9 = (int)local_14 - *piVar7;
      local_14 = uVar13;
      if ((float)(iVar10 * iVar10 + iVar8 * iVar8 + iVar9 * iVar9) <
          *(float *)((int)creature + 0x1458) * *(float *)((int)creature + 0x1458)) break;
    }
    NavGraph_findPath(world,creature);
    NavGraph_reconstructPath(creature);
    axis = axis + 1;
    if (9 < axis) break;
LAB_004c6320:
    if (0x32 < *(int *)((int)creature + 0x1464)) break;
  }
LAB_004c63af:
  *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) & 0xffbf;
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
  while( true ) {
    bVar11 = 0xfffeffff < local_98;
    local_98 = local_98 + 0x10000;
    local_9c = local_9c + (uint)bVar11;
    attempt = attempt + 1;
    wp_z = local_98;
    iStack_48 = local_9c;
    if (0x14 < attempt) break;
LAB_004c6010:
    axis = 0;
    half_height = *(float *)((int)creature + 0x88) * 0.5;
    do {
      uVar12 = ftol2();
      rand_offset[axis * 2] = (uint)uVar12;
      rand_offset[axis * 2 + 1] = (uint)(uVar12 >> 0x20);
      axis = axis + 1;
    } while (axis < 3);
    stack0xffffffd4 =
         CONCAT44(iStack_58 + rand_offset[1] + (uint)CARRY4(wp_x,rand_offset[0]),
                  wp_x + rand_offset[0]);
    _local_24 = CONCAT44(iStack_50 + rand_offset[3] + (uint)CARRY4(wp_y,rand_offset[2]),
                         wp_y + rand_offset[2]);
    _local_1c = CONCAT44(iStack_48 + rand_offset[5] + (uint)CARRY4(wp_z,rand_offset[4]),
                         wp_z + rand_offset[4]);
    blocked = WalkPathBehavior_checkPathClear(world,rand_offset + 6,(float *)((int)creature + 0x80),'\0');
    if (blocked == '\0') {
      half_height = *(float *)((int)creature + 0x88) * 0.5;
      local_14 = 0;
      Vec3i64_randomize((int)rand_offset);
      puVar4 = &wp_x;
      puVar14 = local_8c;
      this_00 = Vec3i64_subtract((void *)((int)creature + 0x10),local_74,rand_offset);
      puVar4 = Vec3i64_subtract(this_00,puVar14,puVar4);
      pfVar5 = Vec3i64_toFloatScaled(&iStack_20,(longlong *)puVar4);
      if (*(float *)(this + 0x18) * *(float *)(this + 0x18) <=
          *pfVar5 * *pfVar5 + pfVar5[1] * pfVar5[1] + pfVar5[2] * pfVar5[2]) {
        if (*(int *)((int)creature + 0x1464) == 0) {
          World_clearContainers((int)creature);
          half_height = 0.1 - *(float *)((int)creature + 0x88) * 0.5;
          local_14 = 0;
          Vec3i64_randomize((int)rand_offset);
          puVar4 = Vec3i64_add((void *)((int)creature + 0x10),local_74,rand_offset);
          Copy24Bytes((void *)((int)creature + 0x1428),puVar4);
          Copy24Bytes((void *)((int)creature + 0x1440),&wp_x);
          uVar13 = __alldiv(*(uint *)((int)creature + 0x1448),*(uint *)((int)creature + 0x144c),
                            0x10000,0);
          uVar6 = (int)((int)uVar13 + ((int)uVar13 >> 0x1f & 0xffU)) >> 8;
          uVar13 = __alldiv(*(uint *)((int)creature + 0x1440),*(uint *)((int)creature + 0x1444),
                            0x10000,0);
          axis = Region_getChunkCell(world,(int)((int)uVar13 + ((int)uVar13 >> 0x1f & 0xffU)) >> 8,uVar6
                              );
          if (axis == 0) goto LAB_004c61e9;
          NavGraph_expandNeighbors(world,creature);
          *(undefined4 *)((int)creature + 0x1458) = *(undefined4 *)(this + 0x18);
          NavGraph_findPath(world,creature);
          NavGraph_reconstructPath(creature);
          *(undefined4 *)((int)creature + 0x40) = 0;
          *(undefined4 *)((int)creature + 0x44) = 0;
          *(undefined4 *)((int)creature + 0x48) = 0;
        }
        if (*(int *)((int)creature + 0x1410) == 0) goto LAB_004c63af;
        axis = 0;
        goto LAB_004c6320;
      }
      World_clearContainers((int)creature);
      *(undefined4 *)((int)creature + 0x40) = 0;
      *(undefined4 *)((int)creature + 0x44) = 0;
      *(undefined4 *)((int)creature + 0x48) = 0;
      axis = rand();
      *(int *)(this + 0x14) = axis % 4000 + 2000;
      break;
    }
  }
LAB_004c61c5:
  *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
  *(uint *)(this + 0x10) =
       *(uint *)(this + 0x10) % (uint)((*(int *)(this + 8) - *(int *)(this + 4)) / 0x18);
LAB_004c61e9:
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::WalkPathBehavior::vfunc_1 @ 004c63e0 */

undefined4 * __fastcall cube::WalkPathBehavior::vfunc_1(int src)

{
  undefined4 *clone;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055431b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  clone = operator_new(0x1c);
  local_8 = 0;
  if (clone != (undefined4 *)0x0) {
    *clone = vftable;
    std_vector_copy_ctor(clone + 1,(int *)(src + 4));
    clone[4] = *(undefined4 *)(src + 0x10);
    clone[5] = 0;
    clone[6] = *(undefined4 *)(src + 0x18);
    ExceptionList = local_10;
    return clone;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}




