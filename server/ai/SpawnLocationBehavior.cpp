// SpawnLocationBehavior (ai) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "SpawnLocationBehavior.h"

/* cube::SpawnLocationBehavior::ctor_0 @ 00428920 */

undefined4 * __fastcall cube::SpawnLocationBehavior::ctor_0(undefined4 *self)

{
  *self = vftable;
  return self;
}




/* cube::SpawnLocationBehavior::vfunc_0 @ 00428940 */

void cube::SpawnLocationBehavior::vfunc_0(void *creature,void *world)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int best_index;
  int count;
  float fVar14;
  float fVar15;
  ulonglong uVar16;
  int local_7c;
  int local_74 [3];
  int local_68 [3];
  undefined8 local_5c;
  uint rnd [8];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  count = *(int *)((int)creature + 0x1490);
  if (*(int *)((int)creature + 0x148c) == count) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  best_index = 0;
  iVar10 = 0;
  if (0 < (int)(count - *(int *)((int)creature + 0x148c) & 0xffffffe0U)) {
    piVar8 = (int *)(*(int *)((int)creature + 0x148c) + 0x18);
    do {
      iVar2 = *piVar8;
      piVar8 = piVar8 + 8;
      if (iVar2 <= *(int *)((int)world + 0x80015c)) {
        best_index = iVar10;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < count - *(int *)((int)creature + 0x148c) >> 5);
  }
  if (best_index != *(int *)((int)creature + 0x1488)) {
    World_clearContainers((int)creature);
    *(int *)((int)creature + 0x1488) = best_index;
    rnd[6] = 0;
    rnd[7] = 0;
    count = 0;
    local_30 = 0.5 - *(float *)((int)creature + 0x88) * 0.5;
    do {
      uVar16 = ftol2();
      rnd[count * 2] = (uint)uVar16;
      rnd[count * 2 + 1] = (uint)(uVar16 >> 0x20);
      count = count + 1;
    } while (count < 3);
    *(uint *)((int)creature + 0x1428) = *(uint *)((int)creature + 0x10) + rnd[0];
    *(uint *)((int)creature + 0x1434) =
         *(int *)((int)creature + 0x1c) + rnd[3] +
         (uint)CARRY4(*(uint *)((int)creature + 0x18),rnd[2]);
    *(uint *)((int)creature + 0x142c) =
         *(int *)((int)creature + 0x14) + rnd[1] +
         (uint)CARRY4(*(uint *)((int)creature + 0x10),rnd[0]);
    *(uint *)((int)creature + 0x1438) = *(uint *)((int)creature + 0x20) + rnd[4];
    *(uint *)((int)creature + 0x143c) =
         *(int *)((int)creature + 0x24) + rnd[5] +
         (uint)CARRY4(*(uint *)((int)creature + 0x20),rnd[4]);
    *(uint *)((int)creature + 0x1430) = *(uint *)((int)creature + 0x18) + rnd[2];
    puVar11 = (undefined4 *)
              (*(int *)((int)creature + 0x1488) * 0x20 + *(int *)((int)creature + 0x148c));
    count = 0;
    *(undefined4 *)((int)creature + 0x1440) = *puVar11;
    *(undefined4 *)((int)creature + 0x1444) = puVar11[1];
    *(undefined4 *)((int)creature + 0x1448) = puVar11[2];
    *(undefined4 *)((int)creature + 0x144c) = puVar11[3];
    *(undefined4 *)((int)creature + 0x1450) = puVar11[4];
    *(undefined4 *)((int)creature + 0x1454) = puVar11[5];
    do {
      best_index = World_getBlockFloat(world,*(uint *)((int)creature + 0x1440),
                            *(uint *)((int)creature + 0x1444),*(uint *)((int)creature + 0x1448),
                            *(uint *)((int)creature + 0x144c),*(uint *)((int)creature + 0x1450),
                            *(uint *)((int)creature + 0x1454),0);
      if (((*(byte *)(best_index + 3) & 0x1f) == 0) || ((*(byte *)(best_index + 3) & 0x1f) == 2)) {
        count = 0;
        do {
          best_index = World_getBlockFloat(world,*(uint *)((int)creature + 0x1440),
                                *(uint *)((int)creature + 0x1444),*(uint *)((int)creature + 0x1448),
                                *(uint *)((int)creature + 0x144c),
                                *(uint *)((int)creature + 0x1450) - 0x10000,
                                *(int *)((int)creature + 0x1454) -
                                (uint)(*(uint *)((int)creature + 0x1450) < 0x10000),0);
          if (((*(byte *)(best_index + 3) & 0x1f) != 0) && ((*(byte *)(best_index + 3) & 0x1f) != 2)) {
            NavGraph_expandNeighbors(world,creature);
            *(undefined4 *)((int)creature + 0x1458) = 0x40800000;
            NavGraph_findPath(world,creature);
            NavGraph_reconstructPath(creature);
            *(undefined4 *)((int)creature + 0x40) = 0;
            *(undefined4 *)((int)creature + 0x44) = 0;
            *(undefined4 *)((int)creature + 0x48) = 0;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          puVar1 = (uint *)((int)creature + 0x1450);
          uVar3 = *puVar1;
          *puVar1 = *puVar1 - 0x10000;
          *(int *)((int)creature + 0x1454) =
               *(int *)((int)creature + 0x1454) + -1 + (uint)(0xffff < uVar3);
          count = count + 1;
        } while (count < 0xb);
        break;
      }
      puVar1 = (uint *)((int)creature + 0x1450);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + 0x10000;
      *(int *)((int)creature + 0x1454) = *(int *)((int)creature + 0x1454) + (uint)(0xfffeffff < uVar3)
      ;
      count = count + 1;
    } while (count < 0xb);
LAB_00428b24:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)((int)creature + 0x1484) == *(int *)((int)creature + 0x1488)) goto LAB_00428b24;
  piVar8 = *(int **)((int)world + 4);
  fVar15 = 40000.0;
  piVar9 = (int *)*piVar8;
  if (piVar9 != piVar8) {
    do {
      count = piVar9[6];
      if ((count != 0) && (*(char *)(count + 0x60) == '\0')) {
        local_20._0_4_ = (uint)*(undefined8 *)(count + 0x10);
        local_20._4_4_ = (int)((ulonglong)*(undefined8 *)(count + 0x10) >> 0x20);
        local_20 = CONCAT44((local_20._4_4_ - *(int *)((int)creature + 0x14)) -
                            (uint)((uint)local_20 < *(uint *)((int)creature + 0x10)),
                            (uint)local_20 - *(uint *)((int)creature + 0x10));
        local_18._0_4_ = (uint)*(undefined8 *)(count + 0x18);
        local_18._4_4_ = (int)((ulonglong)*(undefined8 *)(count + 0x18) >> 0x20);
        local_18 = CONCAT44((local_18._4_4_ - *(int *)((int)creature + 0x1c)) -
                            (uint)((uint)local_18 < *(uint *)((int)creature + 0x18)),
                            (uint)local_18 - *(uint *)((int)creature + 0x18));
        local_10._0_4_ = (uint)*(undefined8 *)(count + 0x20);
        local_10._4_4_ = (int)((ulonglong)*(undefined8 *)(count + 0x20) >> 0x20);
        local_10 = CONCAT44((local_10._4_4_ - *(int *)((int)creature + 0x24)) -
                            (uint)((uint)local_10 < *(uint *)((int)creature + 0x20)),
                            (uint)local_10 - *(uint *)((int)creature + 0x20));
        local_2c = (float)local_20 * 1.5258789e-05;
        local_28 = (float)local_18 * 1.5258789e-05;
        local_24 = (float)local_10 * 1.5258789e-05;
        fVar14 = local_28 * local_28 + local_2c * local_2c + local_24 * local_24;
        if (fVar14 < fVar15) {
          fVar15 = fVar14;
        }
      }
      if (*(char *)((int)piVar9 + 0xd) == '\0') {
        piVar6 = (int *)piVar9[2];
        if (*(char *)((int)piVar6 + 0xd) == '\0') {
          cVar5 = *(char *)(*piVar6 + 0xd);
          piVar9 = piVar6;
          piVar6 = (int *)*piVar6;
          while (cVar5 == '\0') {
            cVar5 = *(char *)(*piVar6 + 0xd);
            piVar9 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar5 = *(char *)(piVar9[1] + 0xd);
          piVar7 = (int *)piVar9[1];
          piVar6 = piVar9;
          while ((piVar9 = piVar7, cVar5 == '\0' && (piVar6 == (int *)piVar9[2]))) {
            cVar5 = *(char *)(piVar9[1] + 0xd);
            piVar7 = (int *)piVar9[1];
            piVar6 = piVar9;
          }
        }
      }
    } while (piVar9 != piVar8);
    if (65536.0 <= fVar15) goto LAB_00428e9f;
  }
  if (*(int *)((int)creature + 0x1410) != 0) {
    local_7c = 0;
    do {
      if (0x32 < *(int *)((int)creature + 0x1464)) break;
      if (*(int *)((int)creature + 0x1464) != 0) {
        count = *(int *)(*(int *)((int)creature + 0x1460) + 4);
        piVar8 = (int *)Vec3i64_toBlockCoords(local_68,(uint *)((int)creature + 0x1440));
        uVar4 = *(undefined8 *)(count + 8);
        iVar10 = *(int *)(count + 0x10) - piVar8[2];
        local_5c._4_4_ = (int)((ulonglong)uVar4 >> 0x20);
        count = local_5c._4_4_ - piVar8[1];
        local_5c._0_4_ = (int)uVar4;
        best_index = (int)local_5c - *piVar8;
        local_5c = uVar4;
        if ((float)(iVar10 * iVar10 + count * count + best_index * best_index) <
            *(float *)((int)creature + 0x1458) * *(float *)((int)creature + 0x1458)) break;
      }
      NavGraph_findPath(world,creature);
      NavGraph_reconstructPath(creature);
      local_7c = local_7c + 1;
    } while (local_7c < 10);
  }
  uVar3 = *(uint *)((int)creature + 0x1464);
  if (uVar3 != 0) {
    count = *(int *)(*(int *)((int)creature + 0x1460) + 4);
    piVar8 = (int *)Vec3i64_toBlockCoords(local_74,(uint *)((int)creature + 0x1440));
    best_index = 0;
    count = (count + 8) - (int)piVar8;
    do {
      if (*piVar8 != *(int *)(count + (int)piVar8)) goto LAB_00428e35;
      best_index = best_index + 1;
      piVar8 = piVar8 + 1;
    } while (best_index < 3);
    if (2 < uVar3) {
LAB_00428e35:
      if (uVar3 != 0) goto LAB_00428e9f;
    }
  }
  World_clearContainers((int)creature);
  *(undefined4 *)((int)creature + 0x40) = 0;
  *(undefined4 *)((int)creature + 0x44) = 0;
  *(undefined4 *)((int)creature + 0x48) = 0;
  *(int *)((int)creature + 0x1484) = *(int *)((int)creature + 0x1488);
  puVar11 = (undefined4 *)(*(int *)((int)creature + 0x1488) * 0x20 + *(int *)((int)creature + 0x148c))
  ;
  *(undefined4 *)((int)creature + 0x1c0) = *puVar11;
  *(undefined4 *)((int)creature + 0x1c4) = puVar11[1];
  *(undefined4 *)((int)creature + 0x1c8) = puVar11[2];
  *(undefined4 *)((int)creature + 0x1cc) = puVar11[3];
  *(undefined4 *)((int)creature + 0x1d0) = puVar11[4];
  *(undefined4 *)((int)creature + 0x1d4) = puVar11[5];
LAB_00428e9f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::SpawnLocationBehavior::vfunc_1 @ 00428ec0 */

undefined4 * cube::SpawnLocationBehavior::vfunc_1(void)

{
  undefined4 *new_obj;
  
  new_obj = operator_new(4);
  if (new_obj != (undefined4 *)0x0) {
    *new_obj = vftable;
    return new_obj;
  }
  return (undefined4 *)0x0;
}




