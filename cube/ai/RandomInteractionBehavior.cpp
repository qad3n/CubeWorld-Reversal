// RandomInteractionBehavior (ai) — cube. 4 functions. Bodies = Ghidra pseudo-C.
#include "RandomInteractionBehavior.h"

/* cube::RandomInteractionBehavior::ctor_0 @ 004db100 */

void cube::RandomInteractionBehavior::ctor_0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  in_ECX[1] = 0;
  return;
}




/* cube::RandomInteractionBehavior::vfunc_0 @ 004db130 */


void cube::RandomInteractionBehavior::vfunc_0(int self,int param_2,int dt)

{
  uint *puVar1;
  undefined8 uVar2;
  int iVar3;
  bool found;
  char cVar5;
  int timer;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint chunkX;
  int chunk;
  int *objNode;
  int *timerPtr;
  int in_ECX;
  int chunkY;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  int *selfPos;
  uint y;
  int *objPos;
  float fVar21;
  uint chunkYMin;
  undefined1 local_20c [280];
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 local_e4;
  undefined1 local_e0 [48];
  undefined1 local_b0 [24];
  undefined1 local_98 [36];
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  float local_5c;
  float local_58;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  int local_38;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int local_28;
  int iStack_24;
  undefined8 local_20;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e903b;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  timerPtr = (int *)(in_ECX + 4);
  *timerPtr = *timerPtr - dt;
  timer = *(int *)(in_ECX + 4);
  if (*timerPtr < 0) {
    timer = 0;
  }
  *(int *)(in_ECX + 4) = timer;
  if (timer == 0) {
    if ((*(char *)(self + 0x68) == 'S') || (*(char *)(self + 0x68) == 'T')) {
      GameController_clearContainers(local_14);
      *(undefined4 *)(self + 0x1478) = 0xffffffff;
      *(undefined4 *)(self + 0x147c) = 0xffffffff;
      *(undefined4 *)(self + 0x1480) = 0;
      *(undefined1 *)(self + 0x68) = 0;
      *(undefined4 *)(self + 0x40) = 0;
      *(undefined4 *)(self + 0x44) = 0;
      *(undefined4 *)(self + 0x48) = 0x3f800000;
      *(undefined4 *)(in_ECX + 4) = 20000;
      goto LAB_004dbec3;
    }
    *(undefined1 *)(self + 0x68) = 0;
  }
  if ((*(char *)(self + 0x68) == 'S') || (*(char *)(self + 0x68) == 'T')) goto LAB_004dbec3;
  uVar7 = __alldiv(*(undefined4 *)(self + 0x20),*(undefined4 *)(self + 0x24),0x10000,0);
  uVar8 = __alldiv(*(undefined4 *)(self + 0x18),*(undefined4 *)(self + 0x1c),0x10000,0);
  puVar1 = (uint *)(self + 0x10);
  uVar9 = __alldiv(*puVar1,*(undefined4 *)(self + 0x14),0x10000,0);
  timer = RandomInteractionBehavior_pickObjectAt(uVar9,uVar8,uVar7);
  found = false;
  if (timer == 0) {
    timer = __alldiv(*(undefined4 *)(self + 0x10),*(undefined4 *)(self + 0x14),0x10000,0);
    chunkY = (int)((timer >> 0x1f & 7U) + timer) >> 3;
    timer = __alldiv(*(undefined4 *)(self + 0x18),*(undefined4 *)(self + 0x1c),0x10000,0);
    chunkYMin = chunkY - 1;
    chunkY = chunkY + 1;
    timer = (int)((timer >> 0x1f & 7U) + timer) >> 3;
    if ((int)chunkYMin < chunkY) {
      chunkX = timer - 1U;
      y = chunkYMin;
      do {
        for (; (int)chunkX < timer + 1; chunkX = chunkX + 1) {
          if ((((-1 < (int)y) && (-1 < (int)chunkX)) && ((int)y < 0x200000)) &&
             (((int)chunkX < 0x200000 &&
              (chunk = world_getRegionCell64((int)(y + ((int)y >> 0x1f & 0x1fU)) >> 5,
                                     (int)(chunkX + ((int)chunkX >> 0x1f & 0x1fU)) >> 5),
              chunk != 0)))) {
            uVar16 = chunkX & 0x8000001f;
            if ((int)uVar16 < 0) {
              uVar16 = (uVar16 - 1 | 0xffffffe0) + 1;
            }
            uVar15 = y & 0x8000001f;
            if ((int)uVar15 < 0) {
              uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
            }
            timerPtr = (int *)(*(int *)(chunk + 0xac) + (uVar16 * 0x20 + uVar15) * 8);
            if (timerPtr != (int *)0x0) {
              timerPtr = (int *)*timerPtr;
              objNode = (int *)*timerPtr;
              if (objNode != timerPtr) {
                do {
                  chunk = 0;
                  objPos = objNode + 3;
                  selfPos = (int *)(self + 0x1478);
                  do {
                    if (*objPos != *selfPos) goto LAB_004db6cb;
                    chunk = chunk + 1;
                    objPos = objPos + 1;
                    selfPos = selfPos + 1;
                  } while (chunk < 3);
                  if (*(int *)(objNode[2] + 0x40) == 0 && *(int *)(objNode[2] + 0x44) == 0) {
                    found = true;
                  }
LAB_004db6cb:
                  objNode = (int *)*objNode;
                } while (objNode != timerPtr);
              }
            }
          }
        }
        y = y + 1;
        chunkX = timer - 1U;
      } while ((int)y < chunkY);
      if (found) goto LAB_004dbb48;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      local_8 = 0;
      if ((int)chunkYMin < chunkY) {
        chunkX = timer - 1U;
        do {
          for (; (int)chunkX < timer + 1; chunkX = chunkX + 1) {
            if (((-1 < (int)chunkYMin) && (-1 < (int)chunkX)) &&
               (((int)chunkYMin < 0x200000 &&
                (((int)chunkX < 0x200000 &&
                 (chunk = world_getRegionCell64((int)(chunkYMin + ((int)chunkYMin >> 0x1f & 0x1fU)) >> 5,
                                        (int)(chunkX + ((int)chunkX >> 0x1f & 0x1fU)) >> 5),
                 chunk != 0)))))) {
              y = chunkX & 0x8000001f;
              if ((int)y < 0) {
                y = (y - 1 | 0xffffffe0) + 1;
              }
              uVar16 = chunkYMin & 0x8000001f;
              if ((int)uVar16 < 0) {
                uVar16 = (uVar16 - 1 | 0xffffffe0) + 1;
              }
              timerPtr = (int *)(*(int *)(chunk + 0xac) + (y * 0x20 + uVar16) * 8);
              if ((timerPtr != (int *)0x0) &&
                 (objNode = *(int **)*timerPtr, objNode != (int *)*timerPtr)) {
                do {
                  chunk = *(int *)objNode[2];
                  if (((chunk == 0x12) || ((chunk == 0x10 || (chunk == 0x44)))) &&
                     (cVar5 = Entity_stepToward(puVar1,objNode[2] + 8,1,0x43480000), cVar5 != '\0')) {
                    std_vector_push_back_0xc(objNode + 3);
                  }
                  objNode = (int *)*objNode;
                } while (objNode != (int *)*timerPtr);
              }
            }
          }
          chunkYMin = chunkYMin + 1;
          chunkX = timer - 1U;
        } while ((int)chunkYMin < chunkY);
      }
      local_8 = 0xffffffff;
    }
  }
  else {
    puVar17 = *(undefined4 **)(timer + 0x48);
    if (puVar17 != *(undefined4 **)(timer + 0x4c)) {
      do {
        chunkY = 0;
        timerPtr = (int *)(self + 0x1478);
        do {
          if (puVar17[chunkY] != *timerPtr) goto LAB_004db311;
          chunkY = chunkY + 1;
          timerPtr = timerPtr + 1;
        } while (chunkY < 3);
        chunkY = world_getRegionCell64(*puVar17,puVar17[1]);
        if ((((chunkY != 0) && (chunk = puVar17[2], -1 < chunk)) &&
            (iVar3 = *(int *)(chunkY + 0xc), chunk < (*(int *)(chunkY + 0x10) - iVar3) / 0x188)) &&
           (*(int *)(chunk * 0x188 + 0x40 + iVar3) == 0 &&
            *(int *)(chunk * 0x188 + 0x44 + iVar3) == 0)) {
          found = true;
        }
LAB_004db311:
        puVar17 = puVar17 + 3;
      } while (puVar17 != *(undefined4 **)(timer + 0x4c));
    }
    puVar17 = *(undefined4 **)(timer + 0x54);
    if (puVar17 != *(undefined4 **)(timer + 0x58)) {
      do {
        chunkY = 0;
        timerPtr = (int *)(self + 0x1478);
        do {
          if (puVar17[chunkY] != *timerPtr) goto LAB_004db3bb;
          chunkY = chunkY + 1;
          timerPtr = timerPtr + 1;
        } while (chunkY < 3);
        chunkY = world_getRegionCell64(*puVar17,puVar17[1]);
        if (((chunkY != 0) && (chunk = puVar17[2], -1 < chunk)) &&
           ((iVar3 = *(int *)(chunkY + 0xc), chunk < (*(int *)(chunkY + 0x10) - iVar3) / 0x188 &&
            (*(int *)(chunk * 0x188 + 0x40 + iVar3) == 0 &&
             *(int *)(chunk * 0x188 + 0x44 + iVar3) == 0)))) {
          found = true;
        }
LAB_004db3bb:
        puVar17 = puVar17 + 3;
      } while (puVar17 != *(undefined4 **)(timer + 0x58));
    }
    if (found) {
LAB_004dbb48:
      if (*(int *)(self + 0x1410) != 0) {
        timer = 0;
        do {
          if (0x32 < *(int *)(self + 0x1464)) break;
          if (*(int *)(self + 0x1464) != 0) {
            chunkY = *(int *)(*(int *)(self + 0x1460) + 4);
            timerPtr = (int *)vec3i64_toIntFloor(local_98,self + 0x1440);
            uVar2 = *(undefined8 *)(chunkY + 8);
            local_18 = *(int *)(chunkY + 0x10) - timerPtr[2];
            local_20._4_4_ = (int)((ulonglong)uVar2 >> 0x20);
            local_20._4_4_ = local_20._4_4_ - timerPtr[1];
            local_20._0_4_ = (int)uVar2;
            local_20._0_4_ = (int)local_20 - *timerPtr;
            if ((float)(local_18 * local_18 + local_20._4_4_ * local_20._4_4_ +
                       (int)local_20 * (int)local_20) <
                *(float *)(self + 0x1458) * *(float *)(self + 0x1458)) break;
          }
          Creature_runPathfindingLoop(self);
          Pathfinding_reconstructPath(self);
          timer = timer + 1;
        } while (timer < 10);
      }
      chunkX = *(uint *)(self + 0x1478);
      y = *(uint *)(self + 0x147c);
      if (((-1 < (int)chunkX) && (-1 < (int)y)) &&
         (((int)chunkX < 0x10000 && ((int)y < 0x10000)))) {
        timer = (int)(chunkX + ((int)chunkX >> 0x1f & 0x3fU)) >> 6;
        chunkY = (int)(((int)y >> 0x1f & 0x3fU) + y) >> 6;
        if (((-1 < timer) && (-1 < chunkY)) &&
           ((timer < 0x400 &&
            ((chunkY < 0x400 &&
             (timer = *(int *)(param_2 + 0xbc + (timer * 0x400 + chunkY) * 4), timer != 0)))))) {
          chunkX = chunkX & 0x8000003f;
          if ((int)chunkX < 0) {
            chunkX = (chunkX - 1 | 0xffffffc0) + 1;
          }
          y = y & 0x8000003f;
          if ((int)y < 0) {
            y = (y - 1 | 0xffffffc0) + 1;
          }
          timer = *(int *)(timer + 0x10018 + (chunkX * 0x40 + y) * 4);
          if (((timer != 0) && (chunkY = *(int *)(self + 0x1480), -1 < chunkY)) &&
             (chunk = *(int *)(timer + 0xc), chunkY < (*(int *)(timer + 0x10) - chunk) / 0x188)) {
            chunkY = chunkY * 0x188;
            chunkX = *(uint *)(chunkY + 8 + chunk);
            y = *(uint *)(chunkY + 0x10 + chunk);
            uVar16 = *(uint *)(chunkY + 0x18 + chunk);
            local_38 = chunkX - *puVar1;
            iStack_34 = (*(int *)(chunkY + 0xc + chunk) - *(int *)(self + 0x14)) -
                        (uint)(chunkX < *puVar1);
            local_30 = y - *(uint *)(self + 0x18);
            iStack_2c = (*(int *)(chunkY + chunk + 0x14) - *(int *)(self + 0x1c)) -
                        (uint)(y < *(uint *)(self + 0x18));
            local_28 = uVar16 - *(uint *)(self + 0x20);
            iStack_24 = (*(int *)(chunkY + chunk + 0x1c) - *(int *)(self + 0x24)) -
                        (uint)(uVar16 < *(uint *)(self + 0x20));
            local_5c = (float)CONCAT44(iStack_34,local_38) * 1.5258789e-05;
            local_58 = (float)CONCAT44(iStack_2c,local_30) * 1.5258789e-05;
            fVar21 = (float)CONCAT44(iStack_24,local_28) * 1.5258789e-05;
            if (local_58 * local_58 + local_5c * local_5c + fVar21 * fVar21 < 9.0) {
              Struct_reset_with256buf();
              local_f4 = *(undefined4 *)(self + 0x1478);
              timer = *(int *)(self + 0x130c);
              local_f0 = *(undefined4 *)(self + 0x147c);
              local_ec = *(undefined4 *)(self + 0x1480);
              local_e4 = 3;
              chunkY = map_insertVal_4594c0(timer,*(undefined4 *)(timer + 4),local_20c);
              if (*(int *)(self + 0x1310) == 0xd4c77a) {
                std::_Xlength_error("list<T> too long");
              }
              *(int *)(self + 0x1310) = *(int *)(self + 0x1310) + 1;
              *(int *)(timer + 4) = chunkY;
              **(int **)(chunkY + 4) = chunkY;
              GameController_clearContainers();
              *(undefined4 *)(self + 0x1478) = 0xffffffff;
              *(undefined4 *)(self + 0x147c) = 0xffffffff;
              *(undefined4 *)(self + 0x1480) = 0;
              *(undefined4 *)(self + 0x40) = 0;
              *(undefined4 *)(self + 0x44) = 0;
              *(undefined4 *)(self + 0x48) = 0;
              *(undefined4 *)(self + 0x34) = 0;
              *(undefined4 *)(self + 0x38) = 0;
              *(undefined4 *)(self + 0x3c) = 0;
              *(undefined4 *)(in_ECX + 4) = 20000;
            }
          }
        }
      }
      goto LAB_004dbec3;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      if ((*(int *)(param_2 + 0x80015c) < 21600000) ||
         (timerPtr = (int *)(timer + 0x48), 82799999 < *(int *)(param_2 + 0x80015c))) {
        timerPtr = (int *)(timer + 0x54);
      }
      timer = timerPtr[1];
      chunkY = *timerPtr;
      if (chunkY != timer) {
        chunkX = rand();
        chunkX = chunkX % (uint)((timer - chunkY) / 0xc);
        timer = *timerPtr;
        uVar7 = *(undefined4 *)(timer + 4 + chunkX * 0xc);
        uVar8 = *(undefined4 *)(timer + chunkX * 0xc);
        timer = *(int *)(timer + 8 + chunkX * 0xc);
        local_74 = uVar8;
        local_70 = uVar7;
        local_6c = timer;
        chunkY = world_getRegionCell64(uVar8,uVar7);
        if ((((chunkY != 0) && (-1 < timer)) &&
            (timer < (*(int *)(chunkY + 0x10) - *(int *)(chunkY + 0xc)) / 0x188)) &&
           (chunkY = timer * 0x188 + *(int *)(chunkY + 0xc),
           *(int *)(chunkY + 0x40) == 0 && *(int *)(chunkY + 0x44) == 0)) {
          *(undefined4 *)(in_ECX + 4) = 20000;
          local_3c = 0.5 - *(float *)(self + 0x88) * 0.5;
          local_44 = 0;
          local_40 = 0;
          vec3i64_setFromGen(&local_44);
          uVar9 = vec3i64_copyAdd(local_e0,local_b0);
          vec6_copy(uVar9);
          vec6_copy(chunkY + 8);
          *(undefined4 *)(self + 0x1478) = uVar8;
          *(undefined4 *)(self + 0x147c) = uVar7;
          *(int *)(self + 0x1480) = timer;
          *(undefined4 *)(self + 0x1458) = 0x40000000;
          Creature_expandNeighbors(self);
          goto LAB_004dbb48;
        }
      }
    }
  }
  GameController_clearContainers();
  *(undefined4 *)(self + 0x1478) = 0xffffffff;
  *(undefined4 *)(self + 0x147c) = 0xffffffff;
  *(undefined4 *)(self + 0x1480) = 0;
LAB_004dbec3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::RandomInteractionBehavior::vfunc_1 @ 004dbef0 */

undefined4 * cube::RandomInteractionBehavior::vfunc_1(void)

{
  undefined4 *obj;
  
  obj = operator_new(8);
  if (obj != (undefined4 *)0x0) {
    *obj = vftable;
    obj[1] = 0;
    return obj;
  }
  return (undefined4 *)0x0;
}




/* [AUDIT] proposed: RandomInteractionBehavior::pickObjectAt  (confidence: med)
 * purpose: Scans a chunk's object list for one whose voxel cell at (param_1,2,3) is solid and AABB contains the point
 * vars: iVar1=chunk; +0x88/0x8c=object list; +0xc/0x10/0x14=obj origin; 0x598930=cellAt
 */
/* Global::RandomInteractionBehavior_pickObjectAt @ 0059ed30 */

int RandomInteractionBehavior_pickObjectAt(int x,int y,int z)

{
  int chunk;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int colY;
  int obj;
  int oy;
  int iVar8;
  int *objPtr;
  int ox;
  int oz;
  bool bVar12;
  int colZ;
  int colX;
  
  chunk = world_getRegionCell64((int)(x + (x >> 0x1f & 0xffU)) >> 8,
                       (int)(y + (y >> 0x1f & 0xffU)) >> 8);
  if ((chunk == 0) || (objPtr = *(int **)(chunk + 0x88), objPtr == *(int **)(chunk + 0x8c))) {
    return 0;
  }
  do {
    ox = 0;
    colX = 0;
    while( true ) {
      obj = *objPtr;
      uVar3 = *(uint *)(obj + 4) & 0x80000001;
      bVar12 = uVar3 == 0;
      if ((int)uVar3 < 0) {
        bVar12 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar12) {
        colY = *(int *)(obj + 100);
      }
      else {
        colY = *(int *)(obj + 0x68);
      }
      if (colY <= ox) break;
      oy = 0;
      colY = 0;
      while( true ) {
        uVar3 = *(uint *)(obj + 4) & 0x80000001;
        bVar12 = uVar3 == 0;
        if ((int)uVar3 < 0) {
          bVar12 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (bVar12) {
          oz = *(int *)(obj + 0x68);
        }
        else {
          oz = *(int *)(obj + 100);
        }
        if (oz <= oy) break;
        oz = 0;
        if (0 < *(int *)(obj + 0x6c)) {
          colZ = 0;
          do {
            pcVar2 = (char *)VoxelChunk_cellAt(ox,oy,oz);
            if (*pcVar2 == '\x01') {
              obj = *objPtr;
              iVar8 = *(int *)(obj + 0xc) + colX;
              iVar4 = *(int *)(obj + 0x10) + colY;
              obj = *(int *)(obj + 0x14) + colZ;
              if ((((iVar8 <= x) && (iVar4 <= y)) && (obj <= z)) &&
                 (((x <= iVar8 + 0xd && (y <= iVar4 + 0xd)) && (z <= obj + 6))))
              {
                return *objPtr;
              }
            }
            obj = *objPtr;
            colZ = colZ + 7;
            oz = oz + 1;
          } while (oz < *(int *)(obj + 0x6c));
        }
        oy = oy + 1;
        colY = colY + 0xd;
      }
      ox = ox + 1;
      colX = colX + 0xd;
    }
    objPtr = objPtr + 1;
    if (objPtr == *(int **)(chunk + 0x8c)) {
      return 0;
    }
  } while( true );
}




