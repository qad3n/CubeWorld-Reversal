// SpawnLocationBehavior (ai) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "SpawnLocationBehavior.h"

/* cube::SpawnLocationBehavior::ctor_0 @ 004dfab0 */

void cube::SpawnLocationBehavior::ctor_0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  return;
}




/* cube::SpawnLocationBehavior::vfunc_0 @ 004dfad0 */

void cube::SpawnLocationBehavior::vfunc_0(int self,int region)

{
  uint *puVar1;
  int spawnTime;
  uint uVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int *spawnPtr;
  int *piVar8;
  int index;
  undefined4 *spawnEntry;
  int bestIndex;
  int spawnEnd;
  float fVar13;
  float fVar14;
  undefined8 uVar15;
  int local_7c;
  undefined1 local_74 [12];
  undefined1 local_68 [12];
  undefined8 local_5c;
  uint randOffset [8];
  float halfSize;
  float local_2c;
  float local_28;
  float local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  spawnEnd = *(int *)(self + 0x1490);
  if (*(int *)(self + 0x148c) == spawnEnd) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  bestIndex = 0;
  index = 0;
  if (0 < (int)(spawnEnd - *(int *)(self + 0x148c) & 0xffffffe0U)) {
    spawnPtr = (int *)(*(int *)(self + 0x148c) + 0x18);
    do {
      spawnTime = *spawnPtr;
      spawnPtr = spawnPtr + 8;
      if (spawnTime <= *(int *)(region + 0x80015c)) {
        bestIndex = index;
      }
      index = index + 1;
    } while (index < spawnEnd - *(int *)(self + 0x148c) >> 5);
  }
  if (bestIndex != *(int *)(self + 0x1488)) {
    GameController_clearContainers();
    *(int *)(self + 0x1488) = bestIndex;
    randOffset[6] = 0;
    randOffset[7] = 0;
    spawnEnd = 0;
    halfSize = 0.5 - *(float *)(self + 0x88) * 0.5;
    do {
      uVar15 = float_to_uint64_round();
      randOffset[spawnEnd * 2] = (uint)uVar15;
      randOffset[spawnEnd * 2 + 1] = (uint)((ulonglong)uVar15 >> 0x20);
      spawnEnd = spawnEnd + 1;
    } while (spawnEnd < 3);
    *(uint *)(self + 0x1428) = *(uint *)(self + 0x10) + randOffset[0];
    *(uint *)(self + 0x1434) =
         *(int *)(self + 0x1c) + randOffset[3] +
         (uint)CARRY4(*(uint *)(self + 0x18),randOffset[2]);
    *(uint *)(self + 0x142c) =
         *(int *)(self + 0x14) + randOffset[1] +
         (uint)CARRY4(*(uint *)(self + 0x10),randOffset[0]);
    *(uint *)(self + 0x1438) = *(uint *)(self + 0x20) + randOffset[4];
    *(uint *)(self + 0x143c) =
         *(int *)(self + 0x24) + randOffset[5] +
         (uint)CARRY4(*(uint *)(self + 0x20),randOffset[4]);
    *(uint *)(self + 0x1430) = *(uint *)(self + 0x18) + randOffset[2];
    spawnEntry = (undefined4 *)(*(int *)(self + 0x1488) * 0x20 + *(int *)(self + 0x148c));
    spawnEnd = 0;
    *(undefined4 *)(self + 0x1440) = *spawnEntry;
    *(undefined4 *)(self + 0x1444) = spawnEntry[1];
    *(undefined4 *)(self + 0x1448) = spawnEntry[2];
    *(undefined4 *)(self + 0x144c) = spawnEntry[3];
    *(undefined4 *)(self + 0x1450) = spawnEntry[4];
    *(undefined4 *)(self + 0x1454) = spawnEntry[5];
    do {
      bestIndex = world_getColumnAtFixedPos(*(undefined4 *)(self + 0x1440),*(undefined4 *)(self + 0x1444),
                            *(undefined4 *)(self + 0x1448),*(undefined4 *)(self + 0x144c),
                            *(undefined4 *)(self + 0x1450),*(undefined4 *)(self + 0x1454),0);
      if (((*(byte *)(bestIndex + 3) & 0x1f) == 0) || ((*(byte *)(bestIndex + 3) & 0x1f) == 2)) {
        spawnEnd = 0;
        do {
          bestIndex = world_getColumnAtFixedPos(*(undefined4 *)(self + 0x1440),*(undefined4 *)(self + 0x1444),
                                *(undefined4 *)(self + 0x1448),*(undefined4 *)(self + 0x144c),
                                *(uint *)(self + 0x1450) - 0x10000,
                                *(int *)(self + 0x1454) -
                                (uint)(*(uint *)(self + 0x1450) < 0x10000),0);
          if (((*(byte *)(bestIndex + 3) & 0x1f) != 0) && ((*(byte *)(bestIndex + 3) & 0x1f) != 2)) {
            Creature_expandNeighbors(self);
            *(undefined4 *)(self + 0x1458) = 0x40800000;
            Creature_runPathfindingLoop(self);
            Pathfinding_reconstructPath(self);
            *(undefined4 *)(self + 0x40) = 0;
            *(undefined4 *)(self + 0x44) = 0;
            *(undefined4 *)(self + 0x48) = 0;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          puVar1 = (uint *)(self + 0x1450);
          uVar3 = *puVar1;
          *puVar1 = *puVar1 - 0x10000;
          *(int *)(self + 0x1454) = *(int *)(self + 0x1454) + -1 + (uint)(0xffff < uVar3);
          spawnEnd = spawnEnd + 1;
        } while (spawnEnd < 0xb);
        break;
      }
      puVar1 = (uint *)(self + 0x1450);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + 0x10000;
      *(int *)(self + 0x1454) = *(int *)(self + 0x1454) + (uint)(0xfffeffff < uVar3);
      spawnEnd = spawnEnd + 1;
    } while (spawnEnd < 0xb);
LAB_004dfcb4:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)(self + 0x1484) == *(int *)(self + 0x1488)) goto LAB_004dfcb4;
  spawnPtr = *(int **)(region + 4);
  fVar14 = 40000.0;
  piVar8 = (int *)*spawnPtr;
  if (piVar8 != spawnPtr) {
    do {
      spawnEnd = piVar8[6];
      if ((spawnEnd != 0) && (*(char *)(spawnEnd + 0x60) == '\0')) {
        local_20._0_4_ = (uint)*(undefined8 *)(spawnEnd + 0x10);
        local_20._4_4_ = (int)((ulonglong)*(undefined8 *)(spawnEnd + 0x10) >> 0x20);
        local_20 = CONCAT44((local_20._4_4_ - *(int *)(self + 0x14)) -
                            (uint)((uint)local_20 < *(uint *)(self + 0x10)),
                            (uint)local_20 - *(uint *)(self + 0x10));
        local_18._0_4_ = (uint)*(undefined8 *)(spawnEnd + 0x18);
        local_18._4_4_ = (int)((ulonglong)*(undefined8 *)(spawnEnd + 0x18) >> 0x20);
        local_18 = CONCAT44((local_18._4_4_ - *(int *)(self + 0x1c)) -
                            (uint)((uint)local_18 < *(uint *)(self + 0x18)),
                            (uint)local_18 - *(uint *)(self + 0x18));
        local_10._0_4_ = (uint)*(undefined8 *)(spawnEnd + 0x20);
        local_10._4_4_ = (int)((ulonglong)*(undefined8 *)(spawnEnd + 0x20) >> 0x20);
        local_10 = CONCAT44((local_10._4_4_ - *(int *)(self + 0x24)) -
                            (uint)((uint)local_10 < *(uint *)(self + 0x20)),
                            (uint)local_10 - *(uint *)(self + 0x20));
        local_2c = (float)local_20 * 1.5258789e-05;
        local_28 = (float)local_18 * 1.5258789e-05;
        local_24 = (float)local_10 * 1.5258789e-05;
        fVar13 = local_28 * local_28 + local_2c * local_2c + local_24 * local_24;
        if (fVar13 < fVar14) {
          fVar14 = fVar13;
        }
      }
      if (*(char *)((int)piVar8 + 0xd) == '\0') {
        piVar5 = (int *)piVar8[2];
        if (*(char *)((int)piVar5 + 0xd) == '\0') {
          cVar4 = *(char *)(*piVar5 + 0xd);
          piVar8 = piVar5;
          piVar5 = (int *)*piVar5;
          while (cVar4 == '\0') {
            cVar4 = *(char *)(*piVar5 + 0xd);
            piVar8 = piVar5;
            piVar5 = (int *)*piVar5;
          }
        }
        else {
          cVar4 = *(char *)(piVar8[1] + 0xd);
          piVar6 = (int *)piVar8[1];
          piVar5 = piVar8;
          while ((piVar8 = piVar6, cVar4 == '\0' && (piVar5 == (int *)piVar8[2]))) {
            cVar4 = *(char *)(piVar8[1] + 0xd);
            piVar6 = (int *)piVar8[1];
            piVar5 = piVar8;
          }
        }
      }
    } while (piVar8 != spawnPtr);
    if (65536.0 <= fVar14) goto LAB_004e002f;
  }
  if (*(int *)(self + 0x1410) != 0) {
    local_7c = 0;
    do {
      if (0x32 < *(int *)(self + 0x1464)) break;
      if (*(int *)(self + 0x1464) != 0) {
        spawnEnd = *(int *)(*(int *)(self + 0x1460) + 4);
        spawnPtr = (int *)vec3i64_toIntFloor(local_68,self + 0x1440);
        uVar15 = *(undefined8 *)(spawnEnd + 8);
        index = *(int *)(spawnEnd + 0x10) - spawnPtr[2];
        local_5c._4_4_ = (int)((ulonglong)uVar15 >> 0x20);
        spawnEnd = local_5c._4_4_ - spawnPtr[1];
        local_5c._0_4_ = (int)uVar15;
        bestIndex = (int)local_5c - *spawnPtr;
        local_5c = uVar15;
        if ((float)(index * index + spawnEnd * spawnEnd + bestIndex * bestIndex) <
            *(float *)(self + 0x1458) * *(float *)(self + 0x1458)) break;
      }
      Creature_runPathfindingLoop(self);
      Pathfinding_reconstructPath(self);
      local_7c = local_7c + 1;
    } while (local_7c < 10);
  }
  uVar3 = *(uint *)(self + 0x1464);
  if (uVar3 != 0) {
    spawnEnd = *(int *)(*(int *)(self + 0x1460) + 4);
    spawnPtr = (int *)vec3i64_toIntFloor(local_74,self + 0x1440);
    bestIndex = 0;
    spawnEnd = (spawnEnd + 8) - (int)spawnPtr;
    do {
      if (*spawnPtr != *(int *)(spawnEnd + (int)spawnPtr)) goto LAB_004dffc5;
      bestIndex = bestIndex + 1;
      spawnPtr = spawnPtr + 1;
    } while (bestIndex < 3);
    if (2 < uVar3) {
LAB_004dffc5:
      if (uVar3 != 0) goto LAB_004e002f;
    }
  }
  GameController_clearContainers();
  *(undefined4 *)(self + 0x40) = 0;
  *(undefined4 *)(self + 0x44) = 0;
  *(undefined4 *)(self + 0x48) = 0;
  *(int *)(self + 0x1484) = *(int *)(self + 0x1488);
  spawnEntry = (undefined4 *)(*(int *)(self + 0x1488) * 0x20 + *(int *)(self + 0x148c));
  *(undefined4 *)(self + 0x1c0) = *spawnEntry;
  *(undefined4 *)(self + 0x1c4) = spawnEntry[1];
  *(undefined4 *)(self + 0x1c8) = spawnEntry[2];
  *(undefined4 *)(self + 0x1cc) = spawnEntry[3];
  *(undefined4 *)(self + 0x1d0) = spawnEntry[4];
  *(undefined4 *)(self + 0x1d4) = spawnEntry[5];
LAB_004e002f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::SpawnLocationBehavior::vfunc_1 @ 004e0050 */

undefined4 * cube::SpawnLocationBehavior::vfunc_1(void)

{
  undefined4 *obj;
  
  obj = operator_new(4);
  if (obj != (undefined4 *)0x0) {
    *obj = vftable;
    return obj;
  }
  return (undefined4 *)0x0;
}




