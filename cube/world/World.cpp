// World (world) — cube. 25 functions. Bodies = Ghidra pseudo-C.
#include "World.h"

/* [AUDIT] proposed: std::_Sort<0x10>  (confidence: high)
 * purpose: Introsort for 16-byte elements, int key
 * vars: param_3=depth limit
 */
/* Global::std_Sort @ 00455d80 */

void std_Sort(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_c [8];
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 >> 4;
    if (iVar1 < 0x21) {
LAB_00455e17:
      if (1 < iVar1) {
        std_Insertion_sort(param_1,param_2,param_4,0);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (0x10 < (int)(param_2 - param_1 & 0xfffffff0U)) {
          std_Make_heap(param_1,param_2,param_4,0,0);
        }
        std_Sort_heap(param_1,param_2,param_4);
        return;
      }
      goto LAB_00455e17;
    }
    piVar2 = (int *)std_Unguarded_partition(local_c,param_1,param_2,param_4);
    iVar3 = *piVar2;
    iVar1 = piVar2[1];
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((int)(iVar3 - param_1 & 0xfffffff0U) < (int)(param_2 - iVar1 & 0xfffffff0U)) {
      std_Sort(param_1,iVar3,param_3,param_4);
      iVar3 = param_2;
      param_1 = iVar1;
    }
    else {
      std_Sort(iVar1,param_2,param_3,param_4);
    }
    iVar1 = iVar3 - param_1;
    param_2 = iVar3;
  } while( true );
}




/* [AUDIT] proposed: std::_Sort_heap<0x10>  (confidence: high)
 * purpose: Heapsort finalize for 16-byte elements (via _Adjust_heap)
 * vars: -
 */
/* Global::std_Sort_heap @ 00456010 */

void std_Sort_heap(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (0x10 < (int)(param_2 - (int)param_1 & 0xfffffff0U)) {
    puVar1 = (undefined4 *)(param_2 + -0xc);
    do {
      local_18 = puVar1[-1];
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      puVar1[-1] = *param_1;
      *puVar1 = param_1[1];
      puVar1[1] = param_1[2];
      puVar1[2] = param_1[3];
      heap_sift_down_16(param_1,0,(-4 - (int)param_1) + (int)puVar1 >> 4,&local_18,param_3);
      puVar1 = puVar1 + -4;
    } while (0x10 < (int)((0xc - (int)param_1) + (int)puVar1 & 0xfffffff0U));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::_Unguarded_partition<0x10>  (confidence: high)
 * purpose: Hoare partition, 16-byte elements, int key
 * vars: -
 */
/* Global::std_Unguarded_partition @ 004563d0 */

void std_Unguarded_partition(undefined4 *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *local_88;
  int *local_80;
  int *local_7c;
  
  uVar4 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_80 = param_2 + (((int)param_3 - (int)param_2 >> 4) - ((int)param_3 - (int)param_2 >> 0x1f)
                       >> 1) * 4;
  std_Guess_median(param_2,local_80,param_3 + -4,param_4);
  piVar5 = local_80 + 4;
  for (; param_2 < local_80; local_80 = local_80 + -4) {
    if ((local_80[-3] < local_80[1]) || (local_80[1] < local_80[-3])) break;
  }
  local_88 = piVar5;
  piVar7 = piVar5;
  local_7c = piVar5;
  piVar8 = local_80;
  if (piVar5 < param_3) {
    do {
      local_88 = piVar5;
      piVar7 = piVar5;
      local_7c = piVar5;
      if ((piVar5[1] < local_80[1]) || (local_80[1] < piVar5[1])) break;
      piVar5 = piVar5 + 4;
      local_88 = piVar5;
      piVar7 = piVar5;
      local_7c = piVar5;
    } while (piVar5 < param_3);
  }
joined_r0x00456474:
  do {
    if (param_3 <= piVar5) {
LAB_004564d6:
      if (param_2 < local_80) {
        piVar7 = local_80 + -3;
        piVar6 = piVar8;
        do {
          piVar8 = piVar6;
          piVar5 = local_88;
          if (piVar6[1] <= *piVar7) {
            if (piVar6[1] < *piVar7) break;
            iVar1 = piVar6[-4];
            iVar2 = piVar6[-3];
            piVar8 = piVar6 + -4;
            uVar3 = *(undefined8 *)(piVar6 + -2);
            *piVar8 = piVar7[-1];
            piVar6[-3] = *piVar7;
            piVar6[-2] = piVar7[1];
            piVar6[-1] = piVar7[2];
            piVar7[-1] = iVar1;
            *piVar7 = iVar2;
            *(undefined8 *)(piVar7 + 1) = uVar3;
          }
          local_80 = local_80 + -4;
          piVar7 = piVar7 + -4;
          piVar6 = piVar8;
        } while (param_2 < local_80);
      }
      if (local_80 == param_2) {
        if (piVar5 == param_3) {
          param_1[1] = local_7c;
          *param_1 = piVar8;
          __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
          return;
        }
        if (local_7c != piVar5) {
          iVar1 = *piVar8;
          iVar2 = piVar8[1];
          uVar3 = *(undefined8 *)(piVar8 + 2);
          *piVar8 = *local_7c;
          piVar8[1] = local_7c[1];
          piVar8[2] = local_7c[2];
          piVar8[3] = local_7c[3];
          *local_7c = iVar1;
          local_7c[1] = iVar2;
          *(undefined8 *)(local_7c + 2) = uVar3;
        }
        iVar1 = *piVar8;
        iVar2 = piVar8[1];
        uVar3 = *(undefined8 *)(piVar8 + 2);
        *piVar8 = *piVar5;
        piVar8[1] = piVar5[1];
        piVar8[2] = piVar5[2];
        piVar8[3] = piVar5[3];
        piVar5[1] = iVar2;
        *piVar5 = iVar1;
        *(undefined8 *)(piVar5 + 2) = uVar3;
        piVar5 = local_88 + 4;
        local_88 = local_88 + 4;
        piVar7 = local_7c + 4;
        local_7c = local_7c + 4;
        piVar8 = piVar8 + 4;
      }
      else {
        piVar6 = local_80 + -4;
        if (piVar5 == param_3) {
          piVar9 = piVar8 + -4;
          if (piVar6 != piVar9) {
            iVar1 = *piVar6;
            iVar2 = local_80[-3];
            uVar3 = *(undefined8 *)(local_80 + -2);
            *piVar6 = *piVar9;
            local_80[-3] = piVar8[-3];
            local_80[-2] = piVar8[-2];
            local_80[-1] = piVar8[-1];
            *piVar9 = iVar1;
            piVar8[-3] = iVar2;
            *(undefined8 *)(piVar8 + -2) = uVar3;
          }
          piVar7 = local_7c + -4;
          iVar1 = *piVar9;
          iVar2 = piVar8[-3];
          uVar3 = *(undefined8 *)(piVar8 + -2);
          *piVar9 = *piVar7;
          piVar8[-3] = local_7c[-3];
          piVar8[-2] = local_7c[-2];
          piVar8[-1] = local_7c[-1];
          local_7c[-3] = iVar2;
          *piVar7 = iVar1;
          *(undefined8 *)(local_7c + -2) = uVar3;
          local_7c = piVar7;
          local_80 = piVar6;
          piVar8 = piVar9;
        }
        else {
          iVar1 = *piVar5;
          iVar2 = piVar5[1];
          uVar3 = *(undefined8 *)(piVar5 + 2);
          *piVar5 = *piVar6;
          piVar5[1] = local_80[-3];
          piVar5[2] = local_80[-2];
          piVar5[3] = local_80[-1];
          local_80[-3] = iVar2;
          *piVar6 = iVar1;
          *(undefined8 *)(local_80 + -2) = uVar3;
          piVar5 = piVar5 + 4;
          local_88 = piVar5;
          piVar7 = local_7c;
          local_80 = piVar6;
        }
      }
      goto joined_r0x00456474;
    }
    piVar6 = piVar7;
    if (piVar5[1] <= piVar8[1]) {
      local_88 = piVar5;
      if (piVar5[1] < piVar8[1]) goto LAB_004564d6;
      piVar6 = piVar7 + 4;
      iVar1 = *piVar7;
      iVar2 = piVar7[1];
      uVar3 = *(undefined8 *)(piVar7 + 2);
      *piVar7 = *piVar5;
      piVar7[1] = piVar5[1];
      piVar7[2] = piVar5[2];
      piVar7[3] = piVar5[3];
      *piVar5 = iVar1;
      piVar5[1] = iVar2;
      *(undefined8 *)(piVar5 + 2) = uVar3;
      local_7c = piVar6;
    }
    piVar5 = piVar5 + 4;
    local_88 = piVar5;
    piVar7 = piVar6;
  } while( true );
}




/* [AUDIT] proposed: std::list<T>::list(const&)  (confidence: med)
 * purpose: list copy-ctor: buy head (node 0x30) then _Insert_range list_assignRange_00451c70
 * vars: in_ECX=dest list
 */
/* Global::std_list_list_const_458df0 @ 00458df0 */

void std_list_list_const_458df0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e3938;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = 0;
  in_ECX[1] = 0;
  puVar1 = (undefined4 *)list_buyNode_30(0,0);
  *in_ECX = puVar1;
  local_8 = 1;
  list_assignRange_00451c70(*puVar1,*(undefined4 *)*param_1,(undefined4 *)*param_1,param_1);
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::list<T>::list(const&)  (confidence: med)
 * purpose: list copy-ctor: buy head (node 0x78) then _Insert_range list_assignRange_00451da0
 * vars: in_ECX=dest list
 */
/* Global::std_list_list_const_458f30 @ 00458f30 */

void std_list_list_const_458f30(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e3998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = 0;
  in_ECX[1] = 0;
  puVar1 = (undefined4 *)list_buyNode_78(0,0);
  *in_ECX = puVar1;
  local_8 = 1;
  list_assignRange_00451da0(*puVar1,*(undefined4 *)*param_1,(undefined4 *)*param_1,param_1);
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::list<T>::list(const&)  (confidence: med)
 * purpose: list copy-ctor: buy head (node 0x50) then _Insert_range list_assignRange_00451ee0
 * vars: in_ECX=dest list
 */
/* Global::std_list_list_const_458fd0 @ 00458fd0 */

void std_list_list_const_458fd0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e39c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = 0;
  in_ECX[1] = 0;
  puVar1 = (undefined4 *)list_buyNode_50(0,0);
  *in_ECX = puVar1;
  local_8 = 1;
  list_assignRange_00451ee0(*puVar1,*(undefined4 *)*param_1,(undefined4 *)*param_1,param_1);
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: World::updateNearbyEntities  (confidence: low)
 * purpose: GAME (mislabeled lib): spatial scan of chunk grid under lock, sort candidates, dispatch; timeGetTime/CriticalSection
 * vars: in_ECX=world/controller
 */
/* cube::World::updateNearbyEntities @ 004690a0 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::World::updateNearbyEntities.
 * Loops nearby entities: EnterCriticalSection(GC+0x8005d0), seed check GC+0x800a50==+0x800448, cube::ChunkBuffer::ctor_0, sort by distance, WorldInfo_clearUnderLock, then calls saveEntityBlob@0x487520 (edge confirmed). in_ECX holds GC* at +0. Persistence loop.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */


void cube::World::updateNearbyEntities(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  DWORD DVar7;
  int *in_ECX;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int *piVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  uint *puVar16;
  bool bVar17;
  undefined8 uVar18;
  longlong lVar19;
  uint local_68;
  uint *local_54;
  int local_48;
  uint local_44;
  undefined4 uStack_40;
  uint local_3c;
  uint local_38;
  undefined8 local_34;
  int local_2c;
  int local_24;
  int iStack_20;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uStack_40 = (uint)(uint3)uStack_40;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e5418;
  local_10 = ExceptionList;
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  timeGetTime();
  cVar2 = *(char *)(*in_ECX + 0x800584);
  do {
    uVar10 = uStack_40;
    if (cVar2 == '\0') {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
    iVar15 = *in_ECX;
    local_1c = *(undefined8 *)(iVar15 + 0x2ac);
    if (*(int *)(iVar15 + 0x800a50) == *(int *)(iVar15 + 0x800448)) {
      uVar6 = *(uint *)(iVar15 + 0x388);
      piVar8 = (int *)(iVar15 + 0x378);
      piVar12 = (int *)(iVar15 + 0x800a54);
      if (0xf < *(uint *)(iVar15 + 0x38c)) {
        piVar8 = (int *)*piVar8;
      }
      uVar1 = *(uint *)(iVar15 + 0x800a64);
      if (0xf < *(uint *)(iVar15 + 0x800a68)) {
        piVar12 = (int *)*piVar12;
      }
      uVar4 = uVar6;
      if (uVar1 < uVar6) {
        uVar4 = uVar1;
      }
      iVar5 = memcmp_traits(piVar12,piVar8,uVar4,uVar3);
      bVar17 = false;
      if (iVar5 == 0) {
        if (uVar1 < uVar6) {
          uVar6 = 0xffffffff;
        }
        else {
          uVar6 = (uint)(uVar1 != uVar6);
        }
        bVar17 = uVar6 == 0;
      }
      uStack_40 = uStack_40 & 0xffffff;
      if (!bVar17) goto LAB_00469175;
    }
    else {
LAB_00469175:
      uStack_40 = CONCAT13(1,(int3)uVar10);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar15 + 0x8005d0));
    if (uStack_40._3_1_ == '\0') {
      puVar14 = (uint *)0x0;
      local_54 = (uint *)0x0;
      iVar15 = *(int *)(*in_ECX + 0x2dc);
      local_8 = 0;
      local_44 = (int)local_1c;
      if ((int)local_1c < (int)local_1c + iVar15) {
        do {
          iVar5 = local_1c._4_4_;
          if (local_1c._4_4_ < local_1c._4_4_ + iVar15) {
            do {
              if ((((-1 < (int)local_44) && (-1 < iVar5)) && ((int)local_44 < 0x80000)) &&
                 (iVar5 < 0x80000)) {
                local_2c = (local_44 - iVar15 / 2) - (int)local_1c;
                iVar9 = (iVar5 - iVar15 / 2) - local_1c._4_4_;
                uVar6 = local_2c * local_2c + iVar9 * iVar9;
                uVar18 = CONCAT44(iVar5,local_44);
                uVar10 = ((iVar5 % iVar15) * iVar15 + (int)local_44 % iVar15) * 0x268 +
                         *(int *)(*in_ECX + 0x2e0);
                local_3c = uVar10;
                local_38 = uVar6;
                local_34 = uVar18;
                local_24 = local_44;
                iStack_20 = iVar5;
                if (&local_3c < puVar14) {
                  if (puVar14 == (uint *)0x0) {
                    std_vector_reserve(1);
                    puVar14 = local_54;
                  }
                  if (puVar14 != (uint *)0x0) {
                    *puVar14 = uStack_40;
                    puVar14[1] = local_3c;
                    puVar14[2] = local_38;
                    puVar14[3] = (uint)local_34;
                  }
                }
                else {
                  if (puVar14 == (uint *)0x0) {
                    std_vector_reserve(1);
                    uVar18 = CONCAT44(iStack_20,local_24);
                    puVar14 = local_54;
                  }
                  if (puVar14 != (uint *)0x0) {
                    *puVar14 = uVar10;
                    puVar14[1] = uVar6;
                    *(undefined8 *)(puVar14 + 2) = uVar18;
                  }
                }
                puVar14 = puVar14 + 4;
                local_54 = puVar14;
              }
              iVar5 = iVar5 + 1;
              iVar15 = *(int *)(*in_ECX + 0x2dc);
            } while (iVar5 < local_1c._4_4_ + iVar15);
          }
          local_44 = local_44 + 1;
          iVar15 = *(int *)(*in_ECX + 0x2dc);
        } while ((int)local_44 < (int)local_1c + iVar15);
      }
      local_68 = local_68 & 0xffffff00;
      std_Sort(0,puVar14,(int)puVar14 >> 4,local_68);
      enter_critical_section();
      lVar19 = ftol2();
      leave_critical_section();
      uStack_40 = CONCAT13(1,(uint3)uStack_40);
      EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x800600));
      puVar14 = (uint *)0x0;
      if (local_54 != (uint *)0x0) {
        local_48 = 0;
        local_44 = 0;
        do {
          if (lVar19 < CONCAT44(local_48,local_44)) {
            WorldInfo_clearUnderLock();
          }
          else {
            iVar15 = 0;
            puVar13 = (uint *)(*puVar14 + 0x18);
            puVar11 = puVar14 + 2;
            puVar16 = puVar13;
            do {
              if (*puVar16 != *puVar11) goto LAB_00469533;
              iVar15 = iVar15 + 1;
              puVar16 = puVar16 + 1;
              puVar11 = puVar11 + 1;
            } while (iVar15 < 2);
            if (*(char *)(*puVar14 + 0x74) != '\0') {
LAB_00469533:
              iVar15 = 0;
              puVar11 = puVar14 + 2;
              do {
                if (*puVar13 != *puVar11) {
                  WorldInfo_clearUnderLock();
                  break;
                }
                iVar15 = iVar15 + 1;
                puVar13 = puVar13 + 1;
                puVar11 = puVar11 + 1;
              } while (iVar15 < 2);
              if (uStack_40._3_1_ != '\0') {
                uVar10 = puVar14[3];
                cVar2 = GameController_check_tile_walkable(puVar14[2],uVar10);
                if (cVar2 != '\0') {
                  uStack_40 = uStack_40 & 0xffffff;
                  cube::ChunkBuffer::ctor_0(puVar14[2],uVar10);
                }
              }
            }
            uVar10 = *(uint *)(*puVar14 + 0x23c);
            bVar17 = CARRY4(local_44,uVar10);
            local_44 = local_44 + uVar10;
            local_48 = local_48 + ((int)uVar10 >> 0x1f) + (uint)bVar17;
          }
          puVar14 = puVar14 + 4;
        } while (puVar14 != local_54);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x800600));
      local_8 = 0xffffffff;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x800600));
      if (0 < *(int *)(*in_ECX + 0x2dc) * *(int *)(*in_ECX + 0x2dc)) {
        iVar15 = 0;
        do {
          WorldInfo_clearUnderLock();
          iVar15 = iVar15 + 1;
        } while (iVar15 < *(int *)(*in_ECX + 0x2dc) * *(int *)(*in_ECX + 0x2dc));
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x800600));
    }
    DVar7 = timeGetTime();
    if (((60000 < (int)(DVar7 - _DAT_0076b078)) && (*(int *)(*in_ECX + 0x388) != 0)) &&
       (*(char *)(*in_ECX + 0x800584) != '\0')) {
      cube::GameController::saveEntityBlob
                (*(undefined4 *)(*in_ECX + 0x800a0c),*(undefined4 *)(*in_ECX + 0x8006d0));
      _DAT_0076b078 = DVar7;
    }
    Sleep(5);
    cVar2 = *(char *)(*in_ECX + 0x800584);
  } while( true );
}




/* [AUDIT] proposed: World::updateActiveChunks  (confidence: low)
 * purpose: GAME (mislabeled lib): large per-frame chunk/entity update (alloca, timeGetTime, sort)
 * vars: in_ECX=world/controller
 */
/* cube::World::updateActiveChunks @ 00469c10 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::World::updateActiveChunks.
 * Body: timeBeginPeriod/timeGetTime; enter/leave critical section; clears GC active-chunk std::lists 0x8006ec/f4/fc; reads Creature GC+0x8006d0 (+0x130c/0x1310); EntityState_serializeToBuffer then winsock Ordinal_19 sends on socket GC+0x8006cc. World/net chunk sync.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */


void cube::World::updateActiveChunks(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  DWORD DVar5;
  int *in_ECX;
  int *piVar6;
  bool bVar7;
  undefined1 local_2490 [4];
  undefined4 local_248c;
  undefined4 uStack_2488;
  undefined4 local_2484;
  undefined4 local_2480;
  uint local_247c;
  DWORD local_2478;
  int local_2474;
  int local_2470;
  int *local_246c;
  int *local_2464;
  undefined4 local_2460;
  char local_2459;
  void *local_2458;
  void *local_2454;
  undefined4 local_2450;
  int local_244c;
  undefined4 local_2448;
  int *local_2444;
  int *local_243c;
  int *local_2434;
  undefined4 local_2430;
  undefined1 local_2429;
  undefined1 local_2428 [4456];
  undefined1 local_12c0 [4456];
  undefined1 local_158 [280];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e547f;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_247c = CONCAT31(local_247c._1_3_,1);
  Creature_init_43c100(local_14);
  local_2429 = 0;
  timeBeginPeriod(1);
  local_2478 = timeGetTime();
  if (*(char *)(*in_ECX + 0x800585) == '\0') goto LAB_0046a870;
  local_2448 = 0;
  iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2448,4,0);
  if (iVar2 != -1) {
    local_2458 = (void *)0x0;
    local_2454 = (void *)0x0;
    local_2450 = 0;
    local_244c = 0;
    local_8 = 0;
    enter_critical_section();
    std_list_list_const_458fd0(*in_ECX + 0x8006ec);
    local_8._0_1_ = 1;
    std_list_list_const_458df0(*in_ECX + 0x8006f4);
    local_8._0_1_ = 2;
    std_list_list_const_458f30(*in_ECX + 0x8006fc);
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c._2_2_ << 0x10);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (*(int *)(*in_ECX + 0x1000e64) != 0) {
      puVar3 = (undefined4 *)(**(int **)(*in_ECX + 0x1000e60) + 8);
      if (&local_2c != puVar3) {
        u16string_replaceRange(puVar3,0,0xffffffff);
      }
      std_list_Erase_node(local_2490,**(undefined4 **)(*in_ECX + 0x1000e60));
    }
    bVar7 = *(int *)(*(int *)(*in_ECX + 0x8006d0) + 0x1310) != 0;
    local_2459 = bVar7;
    Struct_reset_with256buf();
    if (bVar7) {
      iVar2 = **(int **)(*(int *)(*in_ECX + 0x8006d0) + 0x130c);
      Item_copyStruct(iVar2 + 8);
      local_40 = *(undefined4 *)(iVar2 + 0x120);
      local_3c = *(undefined4 *)(iVar2 + 0x124);
      local_38 = *(undefined4 *)(iVar2 + 0x128);
      local_34 = *(undefined4 *)(iVar2 + 300);
      local_30 = *(undefined1 *)(iVar2 + 0x130);
      local_2e = *(undefined2 *)(iVar2 + 0x132);
      piVar6 = *(int **)(*(int *)(*in_ECX + 0x8006d0) + 0x130c);
      piVar1 = (int *)*piVar6;
      if (piVar1 != piVar6) {
        *(int *)piVar1[1] = *piVar1;
        *(int *)(*piVar1 + 4) = piVar1[1];
        operator_delete(piVar1);
      }
    }
    iVar2 = *in_ECX;
    puVar3 = *(undefined4 **)(iVar2 + 0x8006ec);
    pvVar4 = (void *)*puVar3;
    *puVar3 = puVar3;
    *(int *)(*(int *)(iVar2 + 0x8006ec) + 4) = *(int *)(iVar2 + 0x8006ec);
    *(undefined4 *)(iVar2 + 0x8006f0) = 0;
    if (pvVar4 != *(void **)(iVar2 + 0x8006ec)) {
      operator_delete(pvVar4);
    }
    iVar2 = *in_ECX;
    puVar3 = *(undefined4 **)(iVar2 + 0x8006f4);
    pvVar4 = (void *)*puVar3;
    *puVar3 = puVar3;
    *(int *)(*(int *)(iVar2 + 0x8006f4) + 4) = *(int *)(iVar2 + 0x8006f4);
    *(undefined4 *)(iVar2 + 0x8006f8) = 0;
    if (pvVar4 != *(void **)(iVar2 + 0x8006f4)) {
      operator_delete(pvVar4);
    }
    iVar2 = *in_ECX;
    puVar3 = *(undefined4 **)(iVar2 + 0x8006fc);
    pvVar4 = (void *)*puVar3;
    *puVar3 = puVar3;
    *(int *)(*(int *)(iVar2 + 0x8006fc) + 4) = *(int *)(iVar2 + 0x8006fc);
    *(undefined4 *)(iVar2 + 0x800700) = 0;
    if (pvVar4 != *(void **)(iVar2 + 0x8006fc)) {
      operator_delete(pvVar4);
    }
    iVar2 = *(int *)(*in_ECX + 0x8006d0);
    local_248c = *(undefined4 *)(iVar2 + 8);
    uStack_2488 = *(undefined4 *)(iVar2 + 0xc);
    T_T_const_T_466050(iVar2 + 0x10);
    leave_critical_section();
    Vector_Resize((int)local_2454 + (8 - (int)local_2458));
    *(ulonglong *)((int)local_2458 + local_244c) = CONCAT44(uStack_2488,local_248c);
    local_244c = local_244c + 8;
    EntityState_serializeToBuffer(&local_2458,local_12c0,local_2428,local_247c);
    obj_init_and_load_a();
    local_2474 = (int)local_2454 - (int)local_2458;
    iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2474,4,0);
    if (iVar2 == -1) {
      if (7 < local_18) {
        operator_delete(local_2c);
      }
      local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
      local_18 = 7;
      local_1c = 0;
      piVar6 = (int *)*local_2434;
      *local_2434 = (int)local_2434;
      local_2434[1] = (int)local_2434;
      local_2430 = 0;
      if (piVar6 != local_2434) {
        operator_delete(piVar6);
      }
      operator_delete(local_2434);
    }
    pvVar4 = local_2458;
    if (local_2458 == local_2454) {
      pvVar4 = (void *)0x0;
    }
    iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),pvVar4,local_2474,0);
    if (iVar2 == -1) {
LAB_0046a5a2:
      if (7 < local_18) {
        operator_delete(local_2c);
      }
      local_18 = 7;
      local_1c = 0;
      local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
      std_list_clear_4da480();
      std_list_clear_4da480();
      std_list_clear_4da480();
      if (local_2458 != (void *)0x0) {
        operator_delete(local_2458);
      }
    }
    else {
      local_247c = local_247c & 0xffffff00;
      copyCtor_EntityLike(local_2428);
      if (local_1c == 0) {
LAB_0046a095:
        if (local_2459 == '\0') {
LAB_0046a0ed:
          piVar6 = (int *)*local_2444;
          if (piVar6 != local_2444) {
            do {
              local_2448 = 7;
              iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2448,4,0);
              if ((iVar2 == -1) ||
                 (iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),piVar6 + 2,0x48,0),
                 iVar2 == -1)) goto LAB_0046a5a2;
              piVar6 = (int *)*piVar6;
            } while (piVar6 != local_2444);
          }
          piVar6 = (int *)*local_243c;
          if (piVar6 != local_243c) {
            do {
              local_2448 = 8;
              iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2448,4,0);
              if ((iVar2 == -1) ||
                 (iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),piVar6 + 2,0x28,0),
                 iVar2 == -1)) goto LAB_0046a5a2;
              piVar6 = (int *)*piVar6;
            } while (piVar6 != local_243c);
          }
          piVar6 = (int *)*local_2434;
          if (piVar6 != local_2434) {
            do {
              local_2448 = 9;
              iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2448,4,0);
              if ((iVar2 == -1) ||
                 (iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),piVar6 + 2,0x70,0),
                 iVar2 == -1)) {
                if (7 < local_18) {
                  operator_delete(local_2c);
                }
                local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
                local_18 = 7;
                local_1c = 0;
                piVar6 = (int *)*local_2434;
                *local_2434 = (int)local_2434;
                local_2434[1] = (int)local_2434;
                local_2430 = 0;
                if (piVar6 != local_2434) {
                  operator_delete(piVar6);
                }
                operator_delete(local_2434);
              }
              piVar6 = (int *)*piVar6;
            } while (piVar6 != local_2434);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
          std_list_copyConstruct_nodeSz_ccbf0(*in_ECX + 0x2cc);
          local_8 = CONCAT31(local_8._1_3_,5);
          std_list_copyConstruct_nodeSz_ccbf0(*in_ECX + 0x2d4);
          LeaveCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
          DVar5 = timeGetTime();
          if (1000 < (int)(DVar5 - local_2478)) {
            piVar6 = (int *)*local_246c;
            local_2478 = DVar5;
            if (piVar6 != local_246c) {
              do {
                local_2480 = 0xb;
                iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2480,4,0);
                if ((iVar2 == -1) ||
                   (iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),piVar6 + 2,8,0),
                   iVar2 == -1)) {
                  local_2429 = 1;
                  break;
                }
                piVar6 = (int *)*piVar6;
              } while (piVar6 != local_246c);
            }
            piVar6 = (int *)*local_2464;
            if (piVar6 != local_2464) {
              do {
                local_2484 = 0xc;
                iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2484,4,0);
                if (iVar2 == -1) {
                  local_2429 = 1;
                  break;
                }
                iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),piVar6 + 2,8,0);
                if (iVar2 == -1) {
                  local_2429 = 1;
                  break;
                }
                piVar6 = (int *)*piVar6;
              } while (piVar6 != local_2464);
            }
          }
          if ((int)(DVar5 - DAT_0076b07c) < 0x14) {
            Sleep((DAT_0076b07c - DVar5) + 0x14);
          }
          piVar6 = (int *)*local_2464;
          *local_2464 = (int)local_2464;
          DAT_0076b07c = DVar5;
          local_2464[1] = (int)local_2464;
          local_2460 = 0;
          if (piVar6 != local_2464) {
            operator_delete(piVar6);
          }
          operator_delete(local_2464);
        }
        local_2448 = 6;
        iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2448,4,0);
        if ((iVar2 != -1) &&
           (iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),local_158,300,0), iVar2 != -1))
        goto LAB_0046a0ed;
      }
      else {
        local_2470 = local_1c;
        local_2448 = 10;
        iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2448,4,0);
        if (iVar2 == -1) goto LAB_0046a5a2;
        iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),&local_2470,4,0);
        if (iVar2 != -1) {
          puVar3 = &local_2c;
          if (7 < local_18) {
            puVar3 = local_2c;
          }
          iVar2 = Ordinal_19(*(undefined4 *)(*in_ECX + 0x8006cc),puVar3,local_2470 * 2,0);
          if (iVar2 != -1) goto LAB_0046a095;
        }
      }
      std_string_FreeMember();
      std_list_clear_4da480();
      std_list_clear_4da480();
      std_list_clear_4da480();
      unwind_free_object();
    }
  }
  if (*(char *)(*in_ECX + 0x800585) != '\0') {
    Ordinal_3(*(undefined4 *)(*in_ECX + 0x8006cc));
    *(undefined4 *)(*in_ECX + 0x8006cc) = 0;
    *(undefined1 *)(*in_ECX + 0x398) = 0;
  }
LAB_0046a870:
  timeEndPeriod(1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::vector<T16>::reserve  (confidence: high)
 * purpose: Grow 16-byte-element vector capacity if below requested
 * vars: param_1=requested
 */
/* Global::std_vector_reserve @ 0046e780 */

void std_vector_reserve(uint param_1)

{
  int *in_ECX;
  uint uVar1;
  
  if (param_1 <= (uint)(in_ECX[2] - in_ECX[1] >> 4)) {
    return;
  }
  if (0xfffffffU - (in_ECX[1] - *in_ECX >> 4) < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
  uVar1 = in_ECX[2] - *in_ECX >> 4;
  if (0xfffffff - (uVar1 >> 1) < uVar1) {
    std_vector_Reallocate();
    return;
  }
  std_vector_Reallocate();
  return;
}




/* [AUDIT] proposed: GameController::check_tile_walkable  (confidence: low)
 * purpose: Grid adjacency/walkability test via world_getRegionCell64 (game logic)
 * vars: param_1/param_2=tile coords
 */
/* Global::GameController_check_tile_walkable @ 0046f490 */

undefined4 GameController_check_tile_walkable(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  if ((((-1 < param_1) && (-1 < param_2)) && (uVar7 = param_1 * 0x20, (int)uVar7 < 0x1000000)) &&
     (uVar8 = param_2 * 0x20, (int)uVar8 < 0x1000000)) {
    iVar4 = (int)(((int)uVar8 >> 0x1f & 0xffU) + uVar8) >> 8;
    iVar1 = (int)(uVar7 + ((int)uVar7 >> 0x1f & 0xffU)) >> 8;
    iVar2 = world_getRegionCell64(iVar1,iVar4);
    if (iVar2 != 0) {
      iVar2 = 0;
      iVar6 = 0;
      uVar7 = uVar7 & 0x800000ff;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xffffff00) + 1;
      }
      if (uVar7 == 0) {
        iVar2 = -1;
      }
      uVar8 = uVar8 & 0x800000ff;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xffffff00) + 1;
      }
      if (uVar8 == 0) {
        iVar6 = -1;
      }
      if (uVar7 == 0xe0) {
        iVar2 = 1;
      }
      if (uVar8 == 0xe0) {
        iVar6 = 1;
      }
      if ((iVar2 == 0) && (iVar6 == 0)) {
        return 1;
      }
      iVar3 = (param_1 + iVar2) * 0x20;
      iVar5 = (param_2 + iVar6) * 0x20;
      iVar3 = world_getRegionCell64((int)((iVar3 >> 0x1f & 0xffU) + iVar3) >> 8,
                           (int)(iVar5 + (iVar5 >> 0x1f & 0xffU)) >> 8);
      if (iVar3 != 0) {
        if (iVar2 == 0) {
          return 1;
        }
        if (iVar6 == 0) {
          return 1;
        }
        iVar2 = (param_1 + iVar2) * 0x20;
        iVar2 = world_getRegionCell64((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8,iVar4);
        if ((iVar2 != 0) &&
           (iVar2 = (param_2 + iVar6) * 0x20,
           iVar1 = world_getRegionCell64(iVar1,(int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8), iVar1 != 0)) {
          return 1;
        }
      }
    }
  }
  return 0;
}




/* [AUDIT] proposed: std::list<std::string>::_Erase_node  (confidence: med)
 * purpose: Unlink node, free embedded string(+0x8), delete
 * vars: param_2=node
 */
/* Global::std_list_Erase_node @ 00477d20 */

int * std_list_Erase_node(int *param_1,int *param_2)

{
  int *in_ECX;
  
  if (param_2 == (int *)*in_ECX) {
    *param_1 = *param_2;
    return param_1;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  if (7 < (uint)param_2[7]) {
    operator_delete((void *)param_2[2]);
  }
  param_2[7] = 7;
  param_2[6] = 0;
  *(undefined2 *)(param_2 + 2) = 0;
  operator_delete(param_2);
}




/* cube::World::updateObjectLabels @ 004c9680 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::World::updateObjectLabels.
 * Body: World_enterCriticalSection; this+0x160=GC; reads Creature GC+0x8006d0 pos+0x10/+0x18, /0x10000 chunk math; resets+writes GC+0x800dd4/dd8 hover sentinels; camera-projects objects, AdaptionWidget_draw_text. Not a stringbuf ctor.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void cube::World::updateObjectLabels(void)

{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 **ppuVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int in_ECX;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  undefined8 uVar21;
  int iStack_498;
  undefined **local_494 [4];
  undefined *local_484;
  undefined **local_47c [14];
  undefined4 local_444;
  undefined4 local_440;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_42c [72];
  undefined1 local_3e4 [8];
  uint local_3dc;
  uint local_3d8;
  undefined1 local_3d4 [4];
  uint local_3d0;
  uint local_3cc;
  undefined8 local_3c8;
  int local_3c0;
  int iStack_3bc;
  int local_3b8;
  uint local_3b4;
  int local_3b0;
  int iStack_3ac;
  int local_3a8;
  int iStack_3a4;
  int local_3a0;
  uint local_39c;
  int local_398;
  undefined4 *local_394;
  int local_390;
  undefined4 *local_38c;
  uint local_388;
  int local_384;
  char *local_380;
  float local_37c;
  float local_378;
  undefined4 *local_374;
  undefined4 local_370;
  uint *local_36c;
  uint local_368;
  int local_364;
  int local_360;
  float local_35c;
  uint *local_358;
  float local_354;
  uint local_350;
  float local_34c;
  float local_348;
  uint local_344;
  float local_33c;
  float local_334;
  float local_328;
  float local_318;
  undefined1 local_310 [24];
  undefined1 local_2f8 [24];
  undefined1 local_2e0 [24];
  undefined1 local_2c8 [24];
  undefined1 local_2b0 [24];
  undefined1 local_298 [24];
  uint local_280;
  int local_27c;
  uint local_278;
  int local_274;
  uint *local_270;
  int local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  float local_1c8 [3];
  uint local_1bc [4];
  uint *local_1ac;
  int local_1a8;
  undefined4 local_1a4;
  undefined4 uStack_1a0;
  undefined4 local_19c;
  undefined4 uStack_198;
  int local_194;
  int iStack_190;
  int local_18c;
  int iStack_188;
  int local_184;
  int iStack_180;
  uint local_17c;
  float local_178;
  undefined4 local_174;
  undefined4 uStack_170;
  undefined4 local_16c;
  undefined4 uStack_168;
  undefined4 local_164;
  undefined4 uStack_160;
  undefined4 local_15c;
  undefined4 uStack_158;
  uint local_154;
  float fStack_150;
  undefined4 local_14c;
  undefined4 uStack_148;
  undefined4 local_144;
  undefined4 uStack_140;
  undefined4 local_13c;
  undefined4 uStack_138;
  undefined4 local_134;
  undefined4 uStack_130;
  undefined4 local_12c;
  undefined4 uStack_128;
  undefined4 local_124;
  undefined4 uStack_120;
  undefined4 local_11c;
  undefined4 uStack_118;
  undefined4 local_114;
  undefined4 uStack_110;
  float local_10c;
  float fStack_108;
  float local_104;
  float local_100;
  float fStack_fc;
  float local_f8;
  float local_f4;
  float fStack_f0;
  undefined4 local_ec;
  float local_e8;
  float fStack_e4;
  undefined4 local_e0;
  float local_dc;
  float fStack_d8;
  float local_d4;
  float local_d0;
  float fStack_cc;
  undefined4 local_c8;
  float local_c4;
  float fStack_c0;
  float local_bc;
  float local_b8;
  float fStack_b4;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined8 local_a4;
  float local_9c;
  float fStack_98;
  undefined4 local_94;
  float local_90;
  float fStack_8c;
  undefined4 local_88;
  float local_84;
  float fStack_80;
  undefined4 local_7c;
  float local_78;
  float fStack_74;
  undefined4 local_70;
  undefined8 local_6c;
  float local_64;
  float local_60;
  float fStack_5c;
  float local_58;
  undefined8 local_54;
  float local_4c;
  undefined8 local_48;
  float local_40;
  undefined8 local_3c;
  float local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e84f3;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_388 = 0;
  local_364 = in_ECX;
  World_enterCriticalSection(local_14);
  iVar6 = *(int *)(in_ECX + 0x160);
  *(undefined4 *)(iVar6 + 0x800dd4) = 0xffffffff;
  *(undefined4 *)(iVar6 + 0x800dd8) = 0xffffffff;
  iVar6 = *(int *)(in_ECX + 0x160);
  local_334 = *(float *)(iVar6 + 0x1000e4c);
  iVar5 = *(int *)(iVar6 + 0x8006d0);
  local_354 = local_334 * 65536.0f;
  uVar21 = ftol2();
  iVar4 = __alldiv((uint)uVar21 + *(uint *)(iVar5 + 0x10),
                   (int)((ulonglong)uVar21 >> 0x20) + *(int *)(iVar5 + 0x14) +
                   (uint)CARRY4((uint)uVar21,*(uint *)(iVar5 + 0x10)),0x10000,0);
  local_33c = *(float *)(iVar6 + 0x1000e50);
  local_354 = local_33c * 65536.0f;
  local_360 = (int)(iVar4 + (iVar4 >> 0x1f & 0xffU)) >> 8;
  uVar21 = ftol2();
  iVar5 = __alldiv((uint)uVar21 + *(uint *)(iVar5 + 0x18),
                   (int)((ulonglong)uVar21 >> 0x20) + *(int *)(iVar5 + 0x1c) +
                   (uint)CARRY4((uint)uVar21,*(uint *)(iVar5 + 0x18)),0x10000,0);
  local_384 = (int)((iVar5 >> 0x1f & 0xffU) + iVar5) >> 8;
  uVar21 = CONCAT44(local_3c8._4_4_,(undefined4)local_3c8);
  if ((2.0f < *(float *)(iVar6 + 0x1c4)) &&
     (uVar14 = local_360 - 0x20, local_350 = uVar14,
     uVar21 = CONCAT44(local_3c8._4_4_,(undefined4)local_3c8), (int)uVar14 < local_360 + 0x20)) {
    local_34c = (float)(local_384 + -0x20);
    iVar5 = local_384 + 0x20;
    uVar15 = uVar14 * 0x100 + 0x80;
    iVar6 = local_360;
    do {
      local_35c = local_34c;
      if ((int)local_34c < iVar5) {
        local_368 = (int)local_34c * 0x100 + 0x80;
        local_350 = uVar14;
        local_344 = uVar15;
        do {
          local_3c8 = uVar21;
          local_378 = (float)hash_or_index_compute(uVar14,local_35c);
          uVar21 = local_3c8;
          if (((local_378 != 0.0f) &&
              (local_380 = (char *)((int)local_378 + 0x10), *(char *)((int)local_378 + 0x10) != '\0'
              )) && ((*(byte *)((int)local_378 + 0x30) & 1) != 0)) {
            iVar6 = *(int *)(in_ECX + 0x160);
            iVar5 = 0;
            local_1c8[0] = *(float *)(iVar6 + 0x1000e4c);
            local_1c8[1] = (float)*(undefined4 *)(iVar6 + 0x1000e50);
            local_1c8[2] = (float)*(undefined4 *)(iVar6 + 0x1000e54);
            do {
              local_354 = local_1c8[iVar5] * 65536.0f;
              uVar21 = ftol2();
              uVar14 = local_368;
              local_1bc[iVar5 * 2] = (uint)uVar21;
              local_1bc[iVar5 * 2 + 1] = (uint)((ulonglong)uVar21 >> 0x20);
              iVar5 = iVar5 + 1;
            } while (iVar5 < 3);
            iVar6 = *(int *)(iVar6 + 0x8006d0);
            fVar17 = (float)terrain_generateColumnColor(local_344,local_368,0);
            local_348 = (float)fVar17;
            local_37c = local_348 * 65536.0f;
            uVar21 = ftol2();
            in_ECX = local_364;
            local_3d8 = ((int)local_344 >> 0x1f) << 0x10 | local_344 >> 0x10;
            local_3cc = ((int)uVar14 >> 0x1f) << 0x10 | uVar14 >> 0x10;
            local_3dc = local_344 * 0x10000;
            local_3d0 = uVar14 * 0x10000;
            local_280 = local_3dc - *(uint *)(iVar6 + 0x10);
            local_27c = (local_3d8 - *(int *)(iVar6 + 0x14)) -
                        (uint)(local_3dc < *(uint *)(iVar6 + 0x10));
            local_278 = local_3d0 - *(uint *)(iVar6 + 0x18);
            local_274 = (local_3cc - *(int *)(iVar6 + 0x1c)) -
                        (uint)(local_3d0 < *(uint *)(iVar6 + 0x18));
            local_270 = (uint *)((uint)uVar21 - *(uint *)(iVar6 + 0x20));
            local_26c = ((int)((ulonglong)uVar21 >> 0x20) - *(int *)(iVar6 + 0x24)) -
                        (uint)((uint)uVar21 < *(uint *)(iVar6 + 0x20));
            local_194 = local_280 - local_1bc[0];
            iStack_190 = (local_27c - local_1bc[1]) - (uint)(local_280 < local_1bc[0]);
            local_18c = local_278 - local_1bc[2];
            iStack_188 = (local_274 - local_1bc[3]) - (uint)(local_278 < local_1bc[2]);
            local_184 = (int)local_270 - (int)local_1ac;
            iStack_180 = (local_26c - local_1a8) - (uint)(local_270 < local_1ac);
            fVar18 = (float)CONCAT44(iStack_190,local_194) * 1.5258789e-05f;
            local_348 = (float)CONCAT44(iStack_180,local_184);
            fVar19 = (float)CONCAT44(iStack_188,local_18c) * 1.5258789e-05f;
            fVar20 = local_348 * 1.5258789e-05f;
            iVar6 = *(int *)(local_364 + 0x160);
            local_100 = fVar19 * *(float *)(iVar6 + 0x800d98) +
                        fVar18 * *(float *)(iVar6 + 0x800d88) +
                        fVar20 * *(float *)(iVar6 + 0x800da8) + *(float *)(iVar6 + 0x800db8);
            fStack_fc = fVar19 * *(float *)(iVar6 + 0x800d9c) +
                        fVar18 * *(float *)(iVar6 + 0x800d8c) +
                        fVar20 * *(float *)(iVar6 + 0x800dac) + *(float *)(iVar6 + 0x800dbc);
            local_40 = 1.0f / (fVar19 * *(float *)(iVar6 + 0x800da4) +
                              fVar18 * *(float *)(iVar6 + 0x800d94) +
                              fVar20 * *(float *)(iVar6 + 0x800db4) + *(float *)(iVar6 + 0x800dc4));
            local_f8 = fVar19 * *(float *)(iVar6 + 0x800da0) + fVar18 * *(float *)(iVar6 + 0x800d90)
                       + fVar20 * *(float *)(iVar6 + 0x800db0) + *(float *)(iVar6 + 0x800dc0);
            fVar18 = local_100 * local_40;
            fVar19 = fStack_fc * local_40;
            local_48 = CONCAT44(fVar19,fVar18);
            local_40 = local_f8 * local_40;
            local_20 = local_48;
            uVar14 = local_350;
            uVar15 = local_344;
            local_358 = local_270;
            local_18 = local_40;
            if (0.0f < local_40) {
              local_348 = *(float *)(iVar6 + 0x800d54) * fVar18 +
                          *(float *)(iVar6 + 0x800d64) * fVar19 +
                          *(float *)(iVar6 + 0x800d74) * local_40 + *(float *)(iVar6 + 0x800d84);
              local_d4 = *(float *)(iVar6 + 0x800d60) * fVar19 +
                         *(float *)(iVar6 + 0x800d50) * fVar18 +
                         *(float *)(iVar6 + 0x800d70) * local_40 + *(float *)(iVar6 + 0x800d80);
              local_dc = *(float *)(iVar6 + 0x800d58) * fVar19 +
                         *(float *)(iVar6 + 0x800d48) * fVar18 +
                         *(float *)(iVar6 + 0x800d68) * local_40 + *(float *)(iVar6 + 0x800d78);
              fStack_d8 = *(float *)(iVar6 + 0x800d5c) * fVar19 +
                          *(float *)(iVar6 + 0x800d4c) * fVar18 +
                          *(float *)(iVar6 + 0x800d6c) * local_40 + *(float *)(iVar6 + 0x800d7c);
              local_58 = 1.0f / local_348;
              fVar18 = local_dc * local_58;
              fVar19 = fStack_d8 * local_58;
              _local_60 = CONCAT44(fVar19,fVar18);
              local_58 = local_d4 * local_58;
              local_20 = CONCAT44(fVar19,fVar18);
              local_18 = local_58;
              if (((-1.0f <= fVar18) && (fVar18 <= 1.0f)) && ((-1.0f <= fVar19 && (fVar19 <= 1.0f)))) {
                iVar6 = *(int *)(*(int *)(local_364 + 4) + 0x10c);
                iVar5 = *(int *)(*(int *)(local_364 + 4) + 0x110);
                local_f4 = (float)iVar6;
                fStack_f0 = (float)-iVar5;
                local_ec = 0x3f800000;
                local_7c = 0x3f000000;
                local_b8 = (float)iVar6;
                fStack_b4 = (float)iVar5;
                _local_84 = CONCAT44(fStack_f0 * 0.5f,local_f4 * 0.5f);
                local_b0 = 0;
                local_348 = local_f4 * 0.5f * fVar18 + local_b8 * 0.5f;
                local_358 = (uint *)(fVar19 * fStack_f0 * 0.5f + fStack_b4 * 0.5f);
                local_88 = 0;
                _local_90 = CONCAT44(fStack_b4 * 0.5f,local_b8 * 0.5f);
                local_20 = CONCAT44(local_358,local_348);
                local_494[0] = &PTR_006fcd00;
                local_484 = &DAT_006fcd08;
                local_3c8 = uVar21;
                std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
                basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_42c);
                local_388 = local_388 | 1;
                local_8 = 0;
                std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
                basic_iostream<wchar_t,std::char_traits<wchar_t>_>
                          ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_494,
                           (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_47c);
                local_8 = 1;
                *(undefined ***)((int)local_494 + (int)local_494[0][1]) =
                     basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                     ::vftable;
                *(undefined **)((int)&iStack_498 + (int)local_494[0][1]) = local_494[0][1] + -0x68;
                std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
                basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                          ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_47c);
                uVar15 = local_344;
                pcVar2 = local_380;
                local_47c[0] = vftable;
                local_444 = 0;
                local_440 = 0;
                local_8 = 3;
                format_object_singular_name(local_2b0,*(int *)(in_ECX + 0x160) + 0x2e4,local_380,local_344,
                             local_368);
                fVar18 = local_35c;
                cVar3 = *pcVar2;
                local_8._0_1_ = 4;
                local_30 = 0x3f8000003f800000;
                local_28 = 0x3f8000003f800000;
                if (cVar3 == '\x01') {
LAB_004ca036:
                  if (cVar3 == '\x04') goto LAB_004ca03f;
                }
                else {
                  if (cVar3 != '\x04') {
                    iVar6 = *(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0);
                    if (*(int *)(iVar6 + 400) + -2 <= *(int *)((int)local_378 + 0x18)) {
                      if (*(int *)(iVar6 + 400) + 2 < *(int *)((int)local_378 + 0x18)) {
                        local_11c = 0x3f800000;
                        uStack_118 = 0x3e4ccccd;
                        local_30 = 0x3e4ccccd3f800000;
                        local_114 = 0x3e4ccccd;
                        uStack_110 = 0x3f800000;
                      }
                      else {
                        local_174 = 0x3e4ccccd;
                        uStack_170 = 0x3f800000;
                        local_30 = 0x3f8000003e4ccccd;
                        local_16c = 0x3e4ccccd;
                        uStack_168 = 0x3f800000;
                      }
                      local_28 = 0x3f8000003e4ccccd;
                    }
                    goto LAB_004ca036;
                  }
LAB_004ca03f:
                  iVar6 = *(int *)(in_ECX + 0x160);
                  uVar15 = local_344;
                  if (*(char *)(iVar6 + 0x800de4) != '\0') {
                    local_14c = 0x3f19999a;
                    uStack_148 = 0x3e800000;
                    local_30 = 0x3e8000003f19999a;
                    local_17c = local_350;
                    local_144 = 0x3f800000;
                    uStack_140 = 0x3f800000;
                    local_28 = 0x3f8000003f800000;
                    local_178 = local_35c;
                    cVar3 = operator_eq_2ints(iVar6 + 0x800ddc);
                    if (cVar3 != '\0') {
                      local_164 = 0x3f800000;
                      uStack_160 = 0x3e800000;
                      local_30 = 0x3e8000003f800000;
                      local_15c = 0x3f800000;
                      uStack_158 = 0x3f800000;
                      local_28 = 0x3f8000003f800000;
                    }
                    fVar19 = *(float *)(*(int *)(in_ECX + 4) + 0xd4);
                    uVar15 = local_344;
                    if (((local_348 - 100.0f <= fVar19) && (fVar19 < local_348 + 100.0f)) &&
                       ((fVar19 = *(float *)(*(int *)(in_ECX + 4) + 0xd8),
                        (float)local_358 - 20.0f <= fVar19 && (fVar19 < (float)local_358 + 10.0f)))) {
                      local_154 = local_350;
                      fStack_150 = fVar18;
                      *(ulonglong *)(iVar6 + 0x800dd4) = CONCAT44(fVar18,local_350);
                      local_12c = 0x3e4ccccd;
                      uStack_128 = 0x3f800000;
                      local_30 = 0x3f8000003e4ccccd;
                      local_124 = 0x3f800000;
                      uStack_120 = 0x3f800000;
                      local_28 = 0x3f8000003f800000;
                    }
                  }
                }
                u16string_assignCStr(L"resource1.dat");
                local_1d8 = 0;
                local_1d4 = 0;
                local_1d0 = 0;
                local_1cc = 0;
                local_248 = 0;
                local_244 = 0;
                local_240 = 0;
                local_23c = 0x3f800000;
                local_268 = 0x3f800000;
                local_264 = 0x3f800000;
                local_260 = 0x3f800000;
                local_25c = 0x3f800000;
                local_8._0_1_ = 5;
                AdaptionWidget_draw_text_locked(local_2f8,local_2b0,0,0x40000000,local_348,local_358,0x41200000,
                             0x40400000,&local_268,&local_248,&local_1d8,1,0xbf800000,1);
                local_8._0_1_ = 4;
                std_string_FreeMember();
                u16string_assignCStr(L"resource1.dat");
                local_8 = CONCAT31(local_8._1_3_,6);
                local_228 = 0;
                local_224 = 0;
                local_220 = 0;
                local_21c = 0;
                local_208 = 0;
                local_204 = 0;
                local_200 = 0;
                local_1fc = 0;
                AdaptionWidget_draw_text_locked(local_2e0,local_2b0,0,0x40000000,local_348,local_358,0x41200000,0,
                             &local_30,&local_208,&local_228,1,0xbf800000,1);
                std_string_FreeMember();
                std_string_FreeMember();
                local_8 = 0xffffffff;
                ctor_18();
                uVar14 = local_350;
                uVar21 = local_3c8;
              }
            }
          }
          local_368 = local_368 + 0x100;
          local_35c = (float)((int)local_35c + 1);
          iVar5 = local_384 + 0x20;
          iVar6 = local_360;
        } while ((int)local_35c < iVar5);
      }
      uVar14 = uVar14 + 1;
      uVar15 = uVar15 + 0x100;
      local_350 = uVar14;
      local_344 = uVar15;
    } while ((int)uVar14 < iVar6 + 0x20);
  }
  local_374 = (undefined4 *)0x0;
  local_370 = 0;
  local_3c8 = uVar21;
  local_374 = (undefined4 *)std_Tree_allocHeadSentinel();
  local_8 = 7;
  uVar14 = local_360 + -0x20;
  local_398 = local_360 + 0x20;
  local_344 = uVar14;
  if ((int)uVar14 < local_398) {
    local_390 = local_384 + -0x20;
    uVar15 = uVar14 * 0x100 + 0x80;
    iVar6 = local_384 + 0x20;
    iVar5 = local_390;
    do {
      iVar4 = iVar5;
      local_360 = iVar5;
      if (iVar5 < iVar6) {
        local_368 = iVar5 * 0x100 + 0x80;
        local_350 = uVar15;
        local_344 = uVar14;
        do {
          local_360 = iVar5;
          iVar6 = hash_or_index_compute(uVar14,iVar5);
          if ((iVar6 != 0) && ((*(byte *)(iVar6 + 0x30) & 1) != 0)) {
            puVar7 = (uint *)FUN_006023b0((int)(uVar14 + ((int)uVar14 >> 0x1f & 7U)) >> 3,
                                          (int)(local_360 + (local_360 >> 0x1f & 7U)) >> 3);
            uVar14 = local_344;
            local_36c = puVar7;
            local_358 = puVar7;
            if ((puVar7 != (uint *)0x0) && ((puVar7[6] != 0 && (puVar7[6] != 10)))) {
              puVar8 = (undefined4 *)local_374[1];
              puVar13 = local_374;
              if (*(char *)((int)puVar8 + 0xd) == '\0') {
                do {
                  if ((uint *)puVar8[4] < puVar7) {
                    puVar9 = (undefined4 *)puVar8[2];
                  }
                  else {
                    puVar9 = (undefined4 *)*puVar8;
                    puVar13 = puVar8;
                  }
                  puVar8 = puVar9;
                } while (*(char *)((int)puVar9 + 0xd) == '\0');
                if ((puVar13 == local_374) || (puVar7 < (uint *)puVar13[4])) goto LAB_004ca59b;
                local_394 = puVar13;
                ppuVar10 = &local_394;
              }
              else {
LAB_004ca59b:
                local_38c = local_374;
                ppuVar10 = &local_38c;
              }
              if (*ppuVar10 == local_374) {
                local_3b4 = ((int)local_368 >> 0x1f) << 0x10 | local_368 >> 0x10;
                local_3b8 = local_368 << 0x10;
                local_39c = ((int)uVar15 >> 0x1f) << 0x10 | uVar15 >> 0x10;
                local_3a0 = uVar15 << 0x10;
                fVar17 = (float)GameController_entityDistanceSq(&local_3a0,&local_3b8);
                local_34c = (float)fVar17;
                uVar14 = local_344;
                if (0.0f < local_34c) {
                  RBTree_LowerBoundInsertUint(local_3e4,0,&local_36c,DAT_0076b248);
                  iVar6 = *(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0);
                  uVar11 = __alldiv(puVar7[2],puVar7[3],0x10000,0);
                  uVar12 = __alldiv(*local_358,local_358[1],0x10000,0);
                  fVar17 = (float)terrain_generateColumnColor(uVar12,uVar11,0);
                  local_34c = (float)fVar17;
                  local_378 = local_34c * 65536.0f;
                  uVar21 = ftol2();
                  puVar7 = (uint *)(iVar6 + 0x20);
                  local_3c0 = (uint)uVar21 - *puVar7;
                  iStack_3bc = ((int)((ulonglong)uVar21 >> 0x20) - *(int *)(iVar6 + 0x24)) -
                               (uint)((uint)uVar21 < *puVar7);
                  local_34c = (float)CONCAT44(iStack_3bc,local_3c0);
                  local_354 = *(float *)(local_364 + 0x160);
                  local_348 = local_34c * 1.5258789e-05f;
                  iVar6 = *(int *)((int)local_354 + 0x8006d0);
                  local_318 = *(float *)((int)local_354 + 0x1000e50);
                  local_380 = (char *)(local_318 * 65536.0f);
                  uVar14 = local_358[2];
                  uVar15 = *(uint *)(iVar6 + 0x18);
                  uVar16 = uVar14 - *(uint *)(iVar6 + 0x18);
                  uVar1 = local_358[3];
                  iVar5 = *(int *)(iVar6 + 0x1c);
                  uVar21 = ftol2();
                  local_3a8 = uVar16 - (uint)uVar21;
                  iStack_3a4 = (((uVar1 - iVar5) - (uint)(uVar14 < uVar15)) -
                               (int)((ulonglong)uVar21 >> 0x20)) - (uint)(uVar16 < (uint)uVar21);
                  local_34c = (float)CONCAT44(iStack_3a4,local_3a8);
                  local_35c = local_34c * 1.5258789e-05f;
                  local_328 = *(float *)((int)local_354 + 0x1000e4c);
                  uVar14 = *local_36c;
                  local_37c = local_328 * 65536.0f;
                  uVar15 = *(uint *)(iVar6 + 0x10);
                  uVar16 = uVar14 - *(uint *)(iVar6 + 0x10);
                  uVar1 = local_36c[1];
                  iVar6 = *(int *)(iVar6 + 0x14);
                  uVar21 = ftol2();
                  in_ECX = local_364;
                  puVar7 = local_36c;
                  local_3b0 = uVar16 - (uint)uVar21;
                  iStack_3ac = (((uVar1 - iVar6) - (uint)(uVar14 < uVar15)) -
                               (int)((ulonglong)uVar21 >> 0x20)) - (uint)(uVar16 < (uint)uVar21);
                  fVar18 = (float)CONCAT44(iStack_3ac,local_3b0) * 1.5258789e-05f;
                  local_34c = *(float *)((int)local_354 + 0x800da4) * local_35c +
                              fVar18 * *(float *)((int)local_354 + 0x800d94) +
                              *(float *)((int)local_354 + 0x800db4) * local_348 +
                              *(float *)((int)local_354 + 0x800dc4);
                  local_10c = *(float *)((int)local_354 + 0x800d98) * local_35c +
                              fVar18 * *(float *)((int)local_354 + 0x800d88) +
                              *(float *)((int)local_354 + 0x800da8) * local_348 +
                              *(float *)((int)local_354 + 0x800db8);
                  local_104 = *(float *)((int)local_354 + 0x800da0) * local_35c +
                              fVar18 * *(float *)((int)local_354 + 0x800d90) +
                              *(float *)((int)local_354 + 0x800db0) * local_348 +
                              *(float *)((int)local_354 + 0x800dc0);
                  fStack_108 = *(float *)((int)local_354 + 0x800d9c) * local_35c +
                               fVar18 * *(float *)((int)local_354 + 0x800d8c) +
                               *(float *)((int)local_354 + 0x800dac) * local_348 +
                               *(float *)((int)local_354 + 0x800dbc);
                  local_4c = 1.0f / local_34c;
                  fVar18 = local_4c * local_10c;
                  fVar19 = local_4c * fStack_108;
                  local_4c = local_4c * local_104;
                  local_54 = CONCAT44(fVar19,fVar18);
                  local_3c = local_54;
                  uVar14 = local_344;
                  uVar15 = local_350;
                  local_34 = local_4c;
                  if (0.0f < local_4c) {
                    local_c4 = fVar19 * *(float *)((int)local_354 + 0x800d58) +
                               fVar18 * *(float *)((int)local_354 + 0x800d48) +
                               local_4c * *(float *)((int)local_354 + 0x800d68) +
                               *(float *)((int)local_354 + 0x800d78);
                    fStack_c0 = fVar19 * *(float *)((int)local_354 + 0x800d5c) +
                                fVar18 * *(float *)((int)local_354 + 0x800d4c) +
                                local_4c * *(float *)((int)local_354 + 0x800d6c) +
                                *(float *)((int)local_354 + 0x800d7c);
                    local_64 = 1.0f / (fVar19 * *(float *)((int)local_354 + 0x800d64) +
                                      fVar18 * *(float *)((int)local_354 + 0x800d54) +
                                      local_4c * *(float *)((int)local_354 + 0x800d74) +
                                     *(float *)((int)local_354 + 0x800d84));
                    local_bc = fVar19 * *(float *)((int)local_354 + 0x800d60) +
                               fVar18 * *(float *)((int)local_354 + 0x800d50) +
                               local_4c * *(float *)((int)local_354 + 0x800d70) +
                               *(float *)((int)local_354 + 0x800d80);
                    fVar18 = local_64 * local_c4;
                    fVar19 = local_64 * fStack_c0;
                    local_64 = local_64 * local_bc;
                    local_6c = CONCAT44(fVar19,fVar18);
                    local_3c = local_6c;
                    local_34 = local_64;
                    if ((((-1.0f <= fVar18) && (fVar18 <= 1.0f)) && (-1.0f <= fVar19)) &&
                       (fVar19 <= 1.0f)) {
                      iVar6 = *(int *)(*(int *)(local_364 + 4) + 0x10c);
                      iVar5 = *(int *)(*(int *)(local_364 + 4) + 0x110);
                      local_d0 = (float)iVar6;
                      fStack_cc = (float)-iVar5;
                      local_c8 = 0x3f800000;
                      local_94 = 0x3f000000;
                      local_e8 = (float)iVar6;
                      fStack_e4 = (float)iVar5;
                      _local_9c = CONCAT44(fStack_cc * 0.5f,local_d0 * 0.5f);
                      local_e0 = 0;
                      local_35c = fVar18 * local_d0 * 0.5f + local_e8 * 0.5f;
                      fVar18 = fVar19 * fStack_cc * 0.5f + fStack_e4 * 0.5f;
                      local_70 = 0;
                      iVar6 = (int)local_354 + 0x2e4;
                      _local_78 = CONCAT44(fStack_e4 * 0.5f,local_e8 * 0.5f);
                      local_3c = CONCAT44(fVar18,local_35c);
                      local_354 = fVar18;
                      GameController_format_region_singular(local_298,iVar6,local_36c);
                      local_ac = 0x3f8000003f800000;
                      local_a4 = 0x3f8000003f800000;
                      local_8._0_1_ = 8;
                      if ((local_358[6] != 1) && (local_358[6] != 10)) {
                        iVar6 = *(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0);
                        fVar17 = (float)curve_level05((float)(int)puVar7[9]);
                        local_36c = (uint *)(float)fVar17;
                        fVar17 = (float)curve_level05((float)*(int *)(iVar6 + 400));
                        local_34c = (float)fVar17;
                        if (local_34c - 0.1f < (float)local_36c) {
                          iVar6 = *(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0);
                          fVar17 = (float)curve_level05((float)(int)puVar7[9]);
                          local_36c = (uint *)(float)fVar17;
                          fVar17 = (float)curve_level05((float)*(int *)(iVar6 + 400));
                          local_34c = (float)fVar17;
                          if (local_34c + 0.1f < (float)local_36c) {
                            local_1a4 = 0x3f800000;
                            uStack_1a0 = 0x3e4ccccd;
                            local_ac = 0x3e4ccccd3f800000;
                            local_19c = 0x3e4ccccd;
                            uStack_198 = 0x3f800000;
                            local_a4 = 0x3f8000003e4ccccd;
                          }
                          else {
                            local_13c = 0;
                            uStack_138 = 0x3f800000;
                            local_ac = 0x3f80000000000000;
                            local_134 = 0x3f800000;
                            uStack_130 = 0x3f800000;
                            local_a4 = 0x3f8000003f800000;
                          }
                        }
                      }
                      u16string_assignCStr(L"resource1.dat");
                      local_1e8 = 0;
                      local_1e4 = 0;
                      local_1e0 = 0;
                      local_1dc = 0;
                      local_1f8 = 0;
                      local_1f4 = 0;
                      local_1f0 = 0;
                      local_1ec = 0x3f800000;
                      local_218 = 0x3f800000;
                      local_214 = 0x3f800000;
                      local_210 = 0x3f800000;
                      local_20c = 0x3f800000;
                      local_8._0_1_ = 9;
                      AdaptionWidget_draw_text_locked(local_310,local_298,0,0x40000000,local_35c,local_354,0x41400000,
                                   0x40400000,&local_218,&local_1f8,&local_1e8,1,0xbf800000,1);
                      local_8._0_1_ = 8;
                      std_string_FreeMember();
                      u16string_assignCStr(L"resource1.dat");
                      local_8._0_1_ = 10;
                      local_238 = 0;
                      local_234 = 0;
                      local_230 = 0;
                      local_22c = 0;
                      local_258 = 0;
                      local_254 = 0;
                      local_250 = 0;
                      local_24c = 0;
                      AdaptionWidget_draw_text_locked(local_2c8,local_298,0,0x40000000,local_35c,local_354,0x41400000,0
                                   ,&local_ac,&local_258,&local_238,1,0xbf800000,1);
                      std_string_FreeMember();
                      local_8 = CONCAT31(local_8._1_3_,7);
                      std_string_FreeMember();
                      uVar14 = local_344;
                      uVar15 = local_350;
                    }
                  }
                }
              }
            }
          }
          local_368 = local_368 + 0x100;
          iVar5 = local_360 + 1;
          iVar6 = local_384 + 0x20;
          iVar4 = local_390;
          local_360 = iVar5;
        } while (iVar5 < iVar6);
      }
      uVar14 = uVar14 + 1;
      uVar15 = uVar15 + 0x100;
      iVar5 = iVar4;
      local_350 = uVar15;
      local_344 = uVar14;
    } while ((int)uVar14 < local_398);
  }
  leave_critical_section_b();
  local_8 = 0xffffffff;
  std_Tree_eraseRange(local_3d4,*local_374,local_374);
  operator_delete(local_374);
}




/* [AUDIT] proposed: EntityState_serializeToBuffer  (confidence: med)
 * purpose: Master: serialize changed entity fields into a chunk list then flatten to output buffer
 * vars: param_2,param_3=cur/base;param_4=mask
 */
/* Global::EntityState_serializeToBuffer @ 004cdaa0 */

void EntityState_serializeToBuffer(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  size_t _Size;
  void *_Src;
  uint uVar1;
  int *piVar2;
  undefined8 local_24;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8568;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_1c = (int *)rbtree_allocNode_10(0,0);
  local_8 = 0;
  local_24 = 0;
  local_14 = 0;
  net_Connection_write_delta_vec6i(&local_1c,&local_24,&local_14,param_2,param_3,param_4,uVar1);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x18,param_3 + 0x18,param_4);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x24,param_3 + 0x24,param_4);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x30,param_3 + 0x30,param_4);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x3c,param_3 + 0x3c,param_4);
  net_Connection_write_delta_f32(&local_1c,&local_24,&local_14,param_2 + 0x48,param_3 + 0x48,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x4c,param_3 + 0x4c,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x50,param_3 + 0x50,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x54,param_3 + 0x54,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x58,param_3 + 0x58,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x5c,param_3 + 0x5c,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x60,param_3 + 0x60,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 100,param_3 + 100,param_4);
  net_Connection_write_delta_struct_ac(&local_1c,&local_24,&local_14,param_2 + 0x68,param_3 + 0x68,param_4);
  net_Connection_write_delta_i16(&local_1c,&local_24,&local_14,param_2 + 0x114,param_3 + 0x114,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x118,param_3 + 0x118,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x11c,param_3 + 0x11c,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x120,param_3 + 0x120,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x124,param_3 + 0x124,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x128,param_3 + 0x128,param_4);
  net_Connection_write_delta_f32(&local_1c,&local_24,&local_14,param_2 + 300,param_3 + 300,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x130,param_3 + 0x130,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x131,param_3 + 0x131,param_4);
  net_Connection_write_delta_f32(&local_1c,&local_24,&local_14,param_2 + 0x134,param_3 + 0x134,param_4);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x138,param_3 + 0x138,param_4);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x144,param_3 + 0x144,param_4);
  net_Connection_write_delta_vec3f(&local_1c,&local_24,&local_14,param_2 + 0x150,param_3 + 0x150,param_4);
  net_Connection_write_delta_f32(&local_1c,&local_24,&local_14,param_2 + 0x15c,param_3 + 0x15c,param_4);
  net_Connection_write_delta_f32(&local_1c,&local_24,&local_14,param_2 + 0x160,param_3 + 0x160,param_4);
  net_Connection_write_delta_f32(&local_1c,&local_24,&local_14,param_2 + 0x164,param_3 + 0x164,param_4);
  net_Connection_write_delta_vec5f(&local_1c,&local_24,&local_14,param_2 + 0x168,param_3 + 0x168,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x17c,param_3 + 0x17c,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x17d,param_3 + 0x17d,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x180,param_3 + 0x180,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x184,param_3 + 0x184,param_4);
  net_Connection_write_delta_i64(&local_1c,&local_24,&local_14,param_2 + 0x188,param_3 + 0x188,param_4);
  net_Connection_write_delta_i64(&local_1c,&local_24,&local_14,param_2 + 400,param_3 + 400,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x198,param_3 + 0x198,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x19c,param_3 + 0x19c,param_4);
  net_Connection_write_delta_vec3i(&local_1c,&local_24,&local_14,param_2 + 0x1a0,param_3 + 0x1a0,param_4);
  net_Connection_write_delta_vec6i(&local_1c,&local_24,&local_14,param_2 + 0x1b0,param_3 + 0x1b0,param_4);
  net_Connection_write_delta_vec3i(&local_1c,&local_24,&local_14,param_2 + 0x1cc,param_3 + 0x1cc,param_4);
  net_Connection_write_delta_i8(&local_1c,&local_24,&local_14,param_2 + 0x1c8,param_3 + 0x1c8,param_4);
  net_Connection_write_delta_creature(&local_1c,&local_24,&local_14,param_2 + 0x1d8,param_3 + 0x1d8,param_4);
  net_Connection_write_delta_struct_e38(&local_1c,&local_24,&local_14,param_2 + 0x2f0,param_3 + 0x2f0,param_4);
  std_list_push_serializeField_string(&local_1c,&local_24,&local_14,param_2 + 0x1158,param_3 + 0x1158,param_4);
  std_list_push_serializeField_0x2C(&local_1c,&local_24,&local_14,param_2 + 0x1128,param_3 + 0x1128,param_4);
  net_Connection_write_delta_i32(&local_1c,&local_24,&local_14,param_2 + 0x1154,param_3 + 0x1154,param_4);
  Vector_Resize((param_1[1] - *param_1) + 8);
  *(undefined8 *)(*param_1 + param_1[3]) = local_24;
  param_1[3] = param_1[3] + 8;
  piVar2 = (int *)*local_1c;
  if (piVar2 != local_1c) {
    do {
      _Size = piVar2[3];
      _Src = (void *)piVar2[2];
      Vector_Resize((param_1[1] - *param_1) + _Size);
      memcpy((void *)(*param_1 + param_1[3]),_Src,_Size);
      param_1[3] = param_1[3] + _Size;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != local_1c);
  }
  piVar2 = (int *)*local_1c;
  *local_1c = (int)local_1c;
  local_1c[1] = (int)local_1c;
  if (piVar2 != local_1c) {
    operator_delete(piVar2);
  }
  operator_delete(local_1c);
}




/* [AUDIT] proposed: format_object_singular_name  (confidence: med)
 * purpose: Formats singular localized name for creature/object from record ('singular'); handles name-vs-generic
 * vars: param_3=record; +4 name ptr; NameGen_generateRegionName fallback
 */
/* Global::format_object_singular_name @ 004e5a20 */

void format_object_singular_name(undefined4 param_1,undefined4 param_2,char *item,undefined4 idA,
                 undefined4 idB)

{
  undefined4 text;
  int fileHandle;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  void **nameBuf;
  undefined4 uVar4;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  void *local_74 [5];
  uint local_60;
  void *local_5c [4];
  undefined4 local_4c;
  uint local_48;
  void *local_44 [4];
  int local_34;
  uint local_30;
  undefined4 local_2c;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9dc8;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_7c = idA;
  local_80 = idB;
  local_78 = param_2;
  uVar4 = 0;
  Terrain_sampleBlockAt_fwd(local_44,item);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (local_34 == 0) {
    u16string_assignCStr(&PTR_006fccac);
    text = extraout_EDX;
  }
  else {
    u16string_assignCStr(L"singular");
    nameBuf = local_5c;
    local_8._0_1_ = 1;
    map_insert_string_key2(local_44);
    text = rbtree_eraseByStringKey(nameBuf);
    local_2c = (void *)((uint)local_2c._2_2_ << 0x10);
    local_18 = 7;
    local_1c = 0;
    u16string_replaceRange(text,0,0xffffffff);
    local_8._0_1_ = 3;
    if (7 < local_48) {
      operator_delete(local_5c[0]);
    }
    local_48 = 7;
    local_4c = 0;
    local_5c[0] = (void *)((uint)local_5c[0] & 0xffff0000);
    if (local_1c == 0) {
      u16string_assignCStr(&PTR_006fccac);
      text = extraout_EDX_00;
    }
    else {
      local_84 = 0x40;
      fileHandle = std_wstring_findSubstr(&local_84,0,1);
      if (fileHandle != -1) {
        if ((*(int *)(item + 4) == 0) || (*item == '\0')) {
          text = NameGen_generateRegionName(local_74,local_7c,local_80);
          local_8._0_1_ = 5;
          std_wstring_replace(fileHandle,1,text,0,0xffffffff);
          if (7 < local_60) {
            operator_delete(local_74[0]);
          }
        }
        else {
          text = NameGen_initFirstNameTables(local_74,*(int *)(item + 4),0xffffffff);
          local_8._0_1_ = 4;
          std_wstring_replace(fileHandle,1,text,0,0xffffffff);
          std_string_FreeMember();
        }
      }
      u16string_moveConstruct(&local_2c);
      text = extraout_EDX_01;
    }
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_2c = (void *)((uint)local_2c & 0xffff0000);
    local_1c = 0;
    local_18 = 7;
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,text,uVar4);
  return;
}




/* [AUDIT] proposed: Pair_CopyFromRefs  (confidence: high)
 * purpose: Game: copies two dword values dereferenced from param_1/param_2 into a 2-field pair at in_ECX
 * vars: in_ECX=pair out
 */
/* Global::Pair_CopyFromRefs @ 0058d6f0 */

void Pair_CopyFromRefs(undefined4 *srcA,undefined4 *srcB)

{
  undefined4 *dst;
  
  *dst = *srcA;
  dst[1] = *srcB;
  return;
}




/* [AUDIT] proposed: Identity_ReturnArg  (confidence: high)
 * purpose: Game: identity accessor returning its argument unchanged
 * vars: -
 */
/* Global::Identity_ReturnArg @ 0058e9e0 */

undefined4 Identity_ReturnArg(undefined4 param_1)

{
  return param_1;
}




/* cube::World::ctor_1 @ 0058eb00 */

void cube::World::ctor_1(undefined4 world,undefined1 isServer)

{
  char cVar1;
  undefined4 obj;
  undefined4 *selfBase;
  undefined4 *puVar4;
  float *pfVar5;
  undefined4 *self;
  int iVar6;
  int iVar7;
  float fVar8;
  wchar_t *pwVar9;
  undefined4 uVar10;
  undefined *puVar11;
  undefined1 local_138 [8];
  undefined1 local_130 [8];
  undefined1 local_128 [8];
  undefined1 local_120 [8];
  undefined1 local_118 [8];
  undefined1 local_110 [8];
  undefined1 local_108 [8];
  undefined1 local_100 [8];
  undefined1 local_f8 [8];
  undefined1 local_f0 [8];
  undefined1 local_e8 [8];
  undefined1 local_e0 [12];
  undefined1 local_d4 [8];
  undefined1 local_cc [8];
  undefined1 local_c4 [8];
  undefined1 local_bc [8];
  undefined1 local_b4 [8];
  undefined1 local_ac [8];
  undefined1 local_a4 [8];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [4];
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 *local_7c;
  undefined4 *local_78;
  undefined4 *local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 local_68;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 *local_5c;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined1 local_50 [8];
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 *local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 *local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f1930;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_68 = world;
  self[1] = 0;
  self[2] = 0;
  local_6c = self;
  obj = RBTree_allocSentinelNode(local_14);
  self[1] = obj;
  local_8 = 0;
  self[3] = 0;
  self[4] = 0;
  obj = RBTree_allocSentinelNode();
  self[3] = obj;
  local_8._0_1_ = 1;
  self[5] = 0;
  self[6] = 0;
  obj = list_buyNode_78(0,0);
  self[5] = obj;
  local_8._0_1_ = 2;
  SpriteManager::ctor_0(world);
  local_8._0_1_ = 3;
  cube::Speech::ctor_1();
  local_70 = self + 0x22;
  self[0x21] = 0;
  *local_70 = 0;
  self[0x23] = 0;
  self[0x24] = 0;
  self[0x2a] = 0xf;
  self[0x29] = 0;
  *(undefined1 *)(self + 0x25) = 0;
  local_8._0_1_ = 6;
  Database::ctor_1();
  *(undefined1 *)(self + 0x2d) = isServer;
  self[0x2e] = 0;
  self[0x20002f] = 0;
  puVar4 = self + 0x200041;
  local_8._0_1_ = 7;
  *puVar4 = 0;
  self[0x200042] = 0;
  local_40 = puVar4;
  obj = std_list_alloc_sentinel_0x2c();
  selfBase = local_6c;
  *puVar4 = obj;
  local_8._0_1_ = 8;
  local_7c = local_6c + 0x200043;
  *local_7c = 0;
  local_6c[0x200044] = 0;
  obj = std_list_alloc_sentinel_0x2c();
  selfBase[0x200043] = obj;
  local_5c = selfBase + 0x200045;
  local_8._0_1_ = 9;
  *local_5c = 0;
  selfBase[0x200046] = 0;
  obj = std_list_alloc_sentinel_0x2c();
  selfBase[0x200045] = obj;
  local_58 = selfBase + 0x200047;
  local_8._0_1_ = 10;
  *local_58 = 0;
  selfBase[0x200048] = 0;
  obj = std_list_alloc_sentinel_0x2c();
  selfBase[0x200047] = obj;
  puVar4 = selfBase + 0x200049;
  local_8._0_1_ = 0xb;
  *puVar4 = 0;
  selfBase[0x20004a] = 0;
  local_84 = puVar4;
  obj = Map_AllocSentinelNode();
  *puVar4 = obj;
  local_80 = local_6c + 0x20004b;
  local_8._0_1_ = 0xc;
  *local_80 = 0;
  local_6c[0x20004c] = 0;
  obj = Map_AllocSentinelNode();
  *local_80 = obj;
  local_48 = local_6c + 0x20004d;
  local_8._0_1_ = 0xd;
  *local_48 = 0;
  local_6c[0x20004e] = 0;
  obj = Map_AllocSentinelNode();
  *local_48 = obj;
  local_78 = local_6c + 0x20004f;
  local_8._0_1_ = 0xe;
  *local_78 = 0;
  local_6c[0x200050] = 0;
  obj = std_list_alloc_sentinel_0x2c();
  *local_78 = obj;
  local_74 = local_6c + 0x200051;
  local_8._0_1_ = 0xf;
  *local_74 = 0;
  local_6c[0x200052] = 0;
  obj = std_list_alloc_sentinel_0x2c();
  *local_74 = obj;
  local_54 = local_6c + 0x200053;
  local_8._0_1_ = 0x10;
  *local_54 = 0;
  local_6c[0x200054] = 0;
  obj = Map_AllocSentinelNode();
  *local_54 = obj;
  local_30 = local_6c + 0x200055;
  local_8._0_1_ = 0x11;
  *local_30 = 0;
  local_6c[0x200056] = 0;
  obj = rbtree_allocHead24();
  *local_30 = obj;
  local_8._0_1_ = 0x12;
  local_6c[0x200057] = 43200000;
  local_6c[0x200058] = 0;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen(&DAT_006fc918,0);
  local_8._0_1_ = 0x13;
  std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_15(0x7b,local_2c);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_30 = (undefined4 *)0x0;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"ElfMale",7);
  local_30 = (undefined4 *)0x1;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"ElfFemale",9);
  local_30 = (undefined4 *)0x2;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"HumanMale",9);
  local_30 = (undefined4 *)0x3;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"HumanFemale",0xb);
  local_30 = (undefined4 *)0x4;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"GoblinMale",10);
  local_30 = (undefined4 *)0x5;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"GoblinFemale",0xc);
  local_30 = (undefined4 *)0x6;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Bullterrier",0xb);
  local_30 = (undefined4 *)0x7;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"LizardmanMale",0xd);
  local_30 = (undefined4 *)0x8;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"LizardmanFemale",0xf);
  local_30 = (undefined4 *)0xd;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"FrogmanMale",0xb);
  local_30 = (undefined4 *)0xe;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"FrogmanFemale",0xd);
  local_30 = (undefined4 *)0x60;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Zombie",6);
  local_30 = (undefined4 *)0x2c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Bandit",6);
  local_30 = (undefined4 *)0x12;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"OldMan",6);
  local_30 = (undefined4 *)0x2b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Wizard",6);
  local_30 = (undefined4 *)0x6c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Troll",5);
  local_30 = (undefined4 *)0x6e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"HellDemon",9);
  local_30 = (undefined4 *)0x6f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Golem",5);
  local_30 = (undefined4 *)0x70;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"EmberGolem",10);
  local_30 = (undefined4 *)0x71;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SnowGolem",9);
  local_30 = (undefined4 *)0x5e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Werewolf",8);
  local_30 = (undefined4 *)0x6d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"DarkTroll",9);
  local_30 = (undefined4 *)0x72;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Yeti",4);
  local_30 = (undefined4 *)0x2e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Ogre",4);
  local_30 = (undefined4 *)0x2f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Rockling",8);
  local_30 = (undefined4 *)0x61;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Vampire",7);
  local_30 = (undefined4 *)0x56;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Spitter",7);
  local_30 = (undefined4 *)0x4c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SpikeCreature",0xd);
  local_30 = (undefined4 *)0x4d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Anubis",6);
  local_30 = (undefined4 *)0x4e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Horus",5);
  local_30 = (undefined4 *)0x4f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Jester",6);
  local_30 = (undefined4 *)0x50;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Spectrino",9);
  local_30 = (undefined4 *)0x51;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Djinn",5);
  local_30 = (undefined4 *)0x52;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Minotaur",8);
  local_30 = (undefined4 *)0x55;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071aa44,3);
  local_30 = (undefined4 *)0x65;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Dragon",6);
  local_30 = (undefined4 *)0x75;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Lich",4);
  local_30 = (undefined4 *)0x9;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"DwarfMale",9);
  local_30 = (undefined4 *)0xa;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"DwarfFemale",0xb);
  local_30 = (undefined4 *)0x35;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Hornet",6);
  local_30 = (undefined4 *)0x36;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"InsectGuard",0xb);
  local_30 = (undefined4 *)0x7f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Ginseng",7);
  local_30 = (undefined4 *)0x3c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071aacc,3);
  local_30 = (undefined4 *)0x3d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Midge",5);
  local_30 = (undefined4 *)0x3e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Mosquito",8);
  local_30 = (undefined4 *)0x39;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Seagull",7);
  local_30 = (undefined4 *)0x46;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"RadishCreature",0xe);
  local_30 = (undefined4 *)0x45;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"PlantCreature",0xd);
  local_30 = (undefined4 *)0x47;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Onionling",9);
  local_30 = (undefined4 *)0x48;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"DesertOnionling",0xf);
  local_30 = (undefined4 *)0x49;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Devourer",8);
  local_30 = (undefined4 *)0x6a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Crab",4);
  local_30 = (undefined4 *)0x6b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SeaCrab",7);
  local_30 = (undefined4 *)0x66;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"BarkBeetle",10);
  local_30 = (undefined4 *)0x67;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"FireBeetle",10);
  local_30 = (undefined4 *)0x68;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SnoutBeetle",0xb);
  local_30 = (undefined4 *)0x69;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"LemonBeetle",0xb);
  local_30 = (undefined4 *)0x92;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"LemonFish",9);
  local_30 = (undefined4 *)0x91;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SapphireFish",0xc);
  local_30 = (undefined4 *)0x96;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Shark",5);
  local_30 = (undefined4 *)0x98;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"LanternFish",0xb);
  local_30 = (undefined4 *)0x99;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"MawFish",7);
  local_30 = (undefined4 *)0x9a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Piranha",7);
  local_30 = (undefined4 *)0x9b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Blowfish",8);
  local_30 = (undefined4 *)0x93;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Seahorse",8);
  local_30 = (undefined4 *)0x44;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Frog",4);
  local_30 = (undefined4 *)0x57;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Mole",4);
  local_30 = (undefined4 *)0x58;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Biter",5);
  local_30 = (undefined4 *)0x5a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Squirrel",8);
  local_30 = (undefined4 *)0x5b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Raccoon",7);
  local_30 = (undefined4 *)0x4a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Duckbill",8);
  local_30 = (undefined4 *)0x4b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Crocodile",9);
  local_30 = (undefined4 *)0x5c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071ad10,3);
  local_30 = (undefined4 *)0x5d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Penguin",7);
  local_30 = (undefined4 *)0x37;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Crow",4);
  local_30 = (undefined4 *)0x3a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Parrot",6);
  local_30 = (undefined4 *)0x77;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Saurian",7);
  local_30 = (undefined4 *)0x76;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"RuneGiant",9);
  local_30 = (undefined4 *)0x73;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Cyclops",7);
  local_30 = (undefined4 *)0x74;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Mammoth",7);
  local_30 = (undefined4 *)0x2d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Witch",5);
  local_30 = (undefined4 *)0x33;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Gnobold",7);
  local_30 = (undefined4 *)0x34;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Insectoid",9);
  local_30 = (undefined4 *)0x30;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Gnoll",5);
  local_30 = (undefined4 *)0x31;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"PolarGnoll",10);
  local_30 = (undefined4 *)0x94;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Mermaid",7);
  local_30 = (undefined4 *)0x95;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Merman",6);
  local_30 = (undefined4 *)0x3b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071adfc,3);
  local_30 = (undefined4 *)0xb;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"OrcMale",7);
  local_30 = (undefined4 *)0xc;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"OrcFemale",9);
  local_30 = (undefined4 *)0x25;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"GreenSlime",10);
  local_30 = (undefined4 *)0x26;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"PinkSlime",9);
  local_30 = (undefined4 *)0x27;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"YellowSlime",0xb);
  local_30 = (undefined4 *)0x28;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"BlueSlime",9);
  local_30 = (undefined4 *)0x29;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Frightener",10);
  local_30 = (undefined4 *)0x2a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SandHorror",10);
  local_30 = (undefined4 *)0x78;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Bush",4);
  local_30 = (undefined4 *)0x79;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SnowBush",8);
  local_30 = (undefined4 *)0x7a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SnowBerryBush",0xd);
  local_30 = (undefined4 *)0x82;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"ThornTree",9);
  local_30 = (undefined4 *)0x80;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Cactus",6);
  local_30 = (undefined4 *)0x8e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Dummy",5);
  local_30 = (undefined4 *)0x8d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071af1c,3);
  local_30 = (undefined4 *)0x7b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"CottonPlant",0xb);
  local_30 = (undefined4 *)0x7c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Scrub",5);
  local_30 = (undefined4 *)0x7d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"CobwebScrub",0xb);
  local_30 = (undefined4 *)0x7e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"FireScrub",9);
  local_30 = (undefined4 *)0x90;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Bomb",4);
  local_30 = (undefined4 *)0xf;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"UndeadMale",10);
  local_30 = (undefined4 *)0x10;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"UndeadFemale",0xc);
  local_30 = (undefined4 *)0x11;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Skeleton",8);
  local_30 = (undefined4 *)0x3f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"PlainRunner",0xb);
  local_30 = (undefined4 *)0x40;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"LeafRunner",10);
  local_30 = (undefined4 *)0x41;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SnowRunner",10);
  local_30 = (undefined4 *)0x42;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"DesertRunner",0xc);
  local_30 = (undefined4 *)0x43;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Peacock",7);
  local_30 = (undefined4 *)0x23;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Bunny",5);
  local_30 = (undefined4 *)0x24;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Porcupine",9);
  local_30 = (undefined4 *)0x13;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Collie",6);
  local_30 = (undefined4 *)0x14;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"ShepherdDog",0xb);
  local_30 = (undefined4 *)0x16;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Alpaca",6);
  local_30 = (undefined4 *)0x17;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"BrownAlpaca",0xb);
  local_30 = (undefined4 *)0x15;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SkullBull",9);
  local_30 = (undefined4 *)0x18;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071b0c0,3);
  local_30 = (undefined4 *)0x19;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Turtle",6);
  local_30 = (undefined4 *)0x1a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Terrier",7);
  local_30 = (undefined4 *)0x1b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"ScottishTerrier",0xf);
  local_30 = (undefined4 *)0x1d;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Panther",7);
  local_30 = (undefined4 *)0x1e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071b118,3);
  local_30 = (undefined4 *)0x1f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"BrownCat",8);
  local_30 = (undefined4 *)0x20;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"WhiteCat",8);
  local_30 = (undefined4 *)0x1c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Wolf",4);
  local_30 = (undefined4 *)0x21;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071b154,3);
  local_30 = (undefined4 *)0x22;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Sheep",5);
  local_30 = (undefined4 *)0x62;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Horse",5);
  local_30 = (undefined4 *)0x64;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(&DAT_0071b174,3);
  local_30 = (undefined4 *)0x63;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Camel",5);
  local_30 = (undefined4 *)0x32;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Monkey",6);
  local_30 = (undefined4 *)0x38;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Chicken",7);
  local_30 = (undefined4 *)0x3e;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Mosquito",8);
  local_30 = (undefined4 *)0x24;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Porcupine",9);
  local_30 = (undefined4 *)0x8f;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Vase",4);
  local_30 = (undefined4 *)0x84;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"IronDeposit",0xb);
  local_30 = (undefined4 *)0x83;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"GoldDeposit",0xb);
  local_30 = (undefined4 *)0x87;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"EmeraldDeposit",0xe);
  local_30 = (undefined4 *)0x88;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SapphireDeposit",0xf);
  local_30 = (undefined4 *)0x89;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"RubyDeposit",0xb);
  local_30 = (undefined4 *)0x8a;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"DiamondDeposit",0xe);
  local_30 = (undefined4 *)0x85;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SilverDeposit",0xd);
  local_30 = (undefined4 *)0x86;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"SandstoneDeposit",0x10);
  local_30 = (undefined4 *)0x8b;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"IceCrystalDeposit",0x11);
  local_30 = (undefined4 *)0x8c;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Scarecrow",9);
  local_30 = (undefined4 *)0x53;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"NomadMale",9);
  local_30 = (undefined4 *)0x54;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"NomadFemale",0xb);
  local_30 = (undefined4 *)0x97;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Bumblebee",9);
  local_30 = (undefined4 *)0x59;
  World_map_find_or_insert_int(&local_30);
  u16string_assignPtrLen(L"Koala",5);
  local_3c = 6;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Boots",5);
  local_3c = 5;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Gloves",6);
  local_3c = 4;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"ChestArmor",10);
  local_3c = 7;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"ShoulderArmor",0xd);
  local_3c = 0x13;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(&DAT_00700a30,3);
  local_3c = 8;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Amulet",6);
  local_3c = 9;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Ring",4);
  local_3c = 2;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Formula",7);
  local_3c = 3;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Sword",5);
  local_3c = 3;
  local_38 = 3;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Dagger",6);
  local_3c = 3;
  local_38 = 4;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Fist",4);
  local_3c = 3;
  local_38 = 2;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Mace",4);
  local_3c = 3;
  local_38 = 1;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(&DAT_0071b3d0,3);
  local_3c = 3;
  local_38 = 6;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(&DAT_0071b3d8,3);
  local_3c = 3;
  local_38 = 7;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Crossbow",8);
  local_3c = 3;
  local_38 = 8;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Boomerang",9);
  local_3c = 3;
  local_38 = 0xe;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Arrows",6);
  pwVar9 = L"Arrow";
  local_3c = 3;
  local_38 = 9;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Torch";
  local_3c = 3;
  local_38 = 0x14;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Staff";
  local_3c = 3;
  local_38 = 10;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Wand";
  local_3c = 3;
  local_38 = 0xb;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Bracelet";
  local_3c = 3;
  local_38 = 0xc;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Shield";
  local_3c = 3;
  local_38 = 0xd;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Greatsword";
  local_3c = 3;
  local_38 = 0xf;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Greataxe";
  local_3c = 3;
  local_38 = 0x10;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Greatmace";
  local_3c = 3;
  local_38 = 0x11;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Longsword";
  local_3c = 3;
  local_38 = 5;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Coin";
  local_3c = 0xc;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"PlatinumCoin";
  local_3c = 0xd;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Candle";
  local_3c = 0x12;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Candle";
  local_3c = 0x12;
  local_38 = 1;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"HangGlider";
  local_3c = 0x17;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Boat";
  local_3c = 0x17;
  local_38 = 1;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Lamp";
  local_3c = 0x18;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"ManaCube";
  local_3c = 0x19;
  local_38 = 0;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  iVar7 = 0;
  local_3c = 0x14;
  do {
    local_38 = iVar7;
    World_MapInsertChunk(&local_3c);
    u16string_assignPtrLen(L"Bait",4);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x9c);
  local_3c = 0x14;
  local_38 = 0x28;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"BlueJelly",9);
  local_3c = 0x14;
  local_38 = 0x25;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"GreenJelly",10);
  local_3c = 0x14;
  local_38 = 0x26;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"PinkJelly",9);
  local_3c = 0x14;
  local_38 = 0x27;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"YellowJelly",0xb);
  local_3c = 0x14;
  local_38 = 0x23;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Carrot",6);
  local_3c = 0x14;
  local_38 = 0x21;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"PumpkinMash",0xb);
  local_3c = 0x14;
  local_38 = 0x1e;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Candy",5);
  local_3c = 0x14;
  local_38 = 0x5c;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Lollipop",8);
  local_3c = 0x14;
  local_38 = 0x5d;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Softice",7);
  local_3c = 0x14;
  local_38 = 0x57;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"ChocolateDonut",0xe);
  local_3c = 0x14;
  local_38 = 0x22;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"CottonCandy",0xb);
  local_3c = 0x14;
  local_38 = 0x35;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Popcorn",7);
  local_3c = 0x14;
  local_38 = 0x38;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"CerealBar",9);
  local_3c = 0x14;
  local_38 = 0x5a;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"StrawberryCake",0xe);
  local_3c = 0x14;
  local_38 = 0x5b;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"ChocolateCake",0xd);
  local_3c = 0x14;
  local_38 = 0x17;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"ChocolateCupcake",0x10);
  local_3c = 0x14;
  local_38 = 0x16;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"VanillaCupcake",0xe);
  local_3c = 0x14;
  local_38 = 0x32;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"BananaSplit",0xb);
  local_3c = 0x14;
  local_38 = 0x1b;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Croissant",9);
  local_3c = 0x14;
  local_38 = 0x66;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Bread",5);
  local_3c = 0x14;
  local_38 = 0x68;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"Lolly",5);
  local_3c = 0x14;
  local_38 = 0x69;
  World_MapInsertChunk(&local_3c);
  u16string_assignPtrLen(L"LemonTart",9);
  local_30 = (undefined4 *)0x14;
  local_44 = 0x43;
  selfBase = (undefined4 *)Identity_ReturnArg(&local_30);
  local_34 = *selfBase;
  uVar10 = 0;
  obj = Pair_CopyFromRefs(&local_34,&local_44,0);
  Pair_Copy2(obj,uVar10);
  Pair_Copy2(&local_3c,0);
  pwVar9 = L"ChocolateCookie";
  World_MapInsertChunk(local_64);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x13;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"BubbleGum";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x37;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"LicoriceCandy";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x19;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"CinnamonRole";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x4b;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"AppleRing";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x1a;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Waffle";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x56;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"WaterIce";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 99;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"DateCookie";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x62;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"CandiedApple";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x6a;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"StrawberryCocktail";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x3f;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"MilkChocolateBar";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x42;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"CaramelChocolateBar";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  local_34 = 0x40;
  local_44 = 0x14;
  uVar10 = 0;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"MintChocolateBar";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x41;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"WhiteChocolateBar";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x4a;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"SugarCandy";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x24;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"BlackberryMarmelade";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  local_34 = 0x39;
  uVar10 = 0;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"SaltedCaramel";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x3a;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"GingerTartlet";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x3b;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"MangoJuice";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x3c;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"FruitBasket";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x3d;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"MelonIceCream";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x3e;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"BloodOrangeJuice";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x58;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Pancakes";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x67;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Curry";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x97;
  local_44 = 0x14;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"BiscuitRole";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 1;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"LifePotion";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 2;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"CactusPotion";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 3;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"ManaPotion";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 4;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"GinsengSoup";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 5;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"SnowBerryMash";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 6;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"MushroomSpit";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 8;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"PineappleSlice";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 9;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"PumpkinMuffin";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Cookie";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 7;
  local_44 = 1;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Bomb";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Nugget";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 1;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  puVar11 = &DAT_0071bad8;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(puVar11);
  uVar10 = 0;
  local_34 = 2;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Feather";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 3;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Horn";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  local_34 = 4;
  local_44 = 0xb;
  uVar10 = 0;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Claw";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 5;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Fiber";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 7;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Hair";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 8;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Crystal";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  local_34 = 9;
  uVar10 = 0;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Yarn";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 6;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Cobweb";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 10;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Cube";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0xb;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Capsule";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0xd;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  puVar11 = &DAT_0071bb5c;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(puVar11);
  uVar10 = 0;
  local_34 = 0xc;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Flask";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0xe;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Spirit";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0xf;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Mushroom";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x13;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"ShimmerMushroom";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x14;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"GinsengRoot";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x10;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Pumpkin";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x11;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Pineapple";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x16;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Heartflower";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x17;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"PricklyPear";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x18;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"FrozenHeartflower";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x19;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Soulflower";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x12;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"RadishSlice";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x15;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"OnionSlice";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x1a;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"WaterFlask";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0x1b;
  local_44 = 0xb;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"SnowBerry";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0;
  local_44 = 0xf;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Beak";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Amulet1";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 1;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Amulet2";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  local_34 = 2;
  local_44 = 0x15;
  uVar10 = 0;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"JewelCase";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 3;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  puVar11 = &DAT_0071bcf8;
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(puVar11);
  uVar10 = 0;
  local_34 = 4;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Medicine";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 5;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Antivenom";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  local_34 = 6;
  uVar10 = 0;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"BandAid";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 7;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Crutch";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 8;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Bandage";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 9;
  local_44 = 0x15;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Salve";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0;
  local_44 = 0xe;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Leftovers";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_34 = 0;
  local_44 = 0x10;
  obj = pair_assign_2dword(local_50,&local_44,&local_34);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Painting";
  World_MapInsertChunk(&local_3c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Statue";
  local_34 = 0;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Door";
  local_34 = 1;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"BigDoor";
  local_34 = 2;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Window";
  local_34 = 3;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"CastleWindow";
  local_34 = 4;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Gate";
  local_34 = 5;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"FireTrap";
  local_34 = 6;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SpikeTrap";
  local_34 = 7;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"StompTrap";
  local_34 = 8;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Lever";
  local_34 = 9;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Chest";
  local_34 = 10;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Table";
  local_34 = 0xc;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Table";
  local_34 = 0xe;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Table";
  local_34 = 0xd;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Stool";
  local_34 = 0x10;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Stool";
  local_34 = 0xf;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Stool";
  local_34 = 0x11;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Bench";
  local_34 = 0x12;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  puVar11 = &DAT_0071be5c;
  local_34 = 0x13;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(puVar11);
  pwVar9 = L"BedTable";
  local_34 = 0x14;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"MarketStand1";
  local_34 = 0x15;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"MarketStand2";
  local_34 = 0x16;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"MarketStand3";
  local_34 = 0x17;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Barrel";
  local_34 = 0x18;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Crate";
  local_34 = 0x19;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"OpenCrate";
  local_34 = 0x1a;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Sack";
  local_34 = 0x1b;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Shelter";
  local_34 = 0x1c;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Cupboard";
  local_34 = 0x1d;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Desktop";
  local_34 = 0x1e;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Counter";
  local_34 = 0x1f;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Shelf1";
  local_34 = 0x20;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Shelf2";
  local_34 = 0x21;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Shelf3";
  local_34 = 0x22;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Corpse";
  local_34 = 0x2c;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"RuneStone";
  local_34 = 0x2d;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Artifact";
  local_34 = 0x2e;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"FlowerBox1";
  local_34 = 0x2f;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"FlowerBox2";
  local_34 = 0x30;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"FlowerBox3";
  local_34 = 0x31;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"StreetLight";
  local_34 = 0x32;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"FireStreetLight";
  local_34 = 0x33;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Fence1";
  local_34 = 0x34;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Fence2";
  local_34 = 0x35;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Fence3";
  local_34 = 0x36;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Fence4";
  local_34 = 0x37;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase1";
  local_34 = 0x38;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase2";
  local_34 = 0x39;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase3";
  local_34 = 0x3a;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase4";
  local_34 = 0x3b;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase5";
  local_34 = 0x3c;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase6";
  local_34 = 0x3d;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase7";
  local_34 = 0x3e;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase8";
  local_34 = 0x3f;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Vase9";
  local_34 = 0x40;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  local_34 = 0x41;
  pwVar9 = L"Campfire";
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Tent";
  local_34 = 0x42;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"BeachUmbrella";
  local_34 = 0x43;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"BeachTowel";
  local_34 = 0x44;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SleepingMat";
  local_34 = 0x45;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Furnace";
  local_34 = 0x47;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Anvil";
  local_34 = 0x48;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SpinningWheel";
  local_34 = 0x49;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"Loom";
  local_34 = 0x4a;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SawBench";
  local_34 = 0x4b;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  local_34 = 0x4c;
  pwVar9 = L"Workbench";
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"CustomizationBench";
  local_34 = 0x4d;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillAbility1";
  local_34 = 6;
  World_map_find_or_insert_int(&local_34);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillAbility2";
  local_5c = (undefined4 *)0x7;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillAbility3";
  local_5c = (undefined4 *)0x8;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillAbility4";
  local_5c = (undefined4 *)0x9;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillAbility5";
  local_5c = (undefined4 *)0xa;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillPetTaming";
  local_5c = (undefined4 *)0x0;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillPetRiding";
  local_5c = (undefined4 *)0x1;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillClimbing";
  local_5c = (undefined4 *)0x2;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  local_5c = (undefined4 *)0x3;
  pwVar9 = L"SkillHangGliding";
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillSwimming";
  local_5c = (undefined4 *)0x4;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"SkillBoatDriving";
  local_5c = (undefined4 *)0x5;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilitySmash";
  local_5c = (undefined4 *)0x36;
  World_map_find_or_insert_int(&local_5c);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityCyclone";
  local_58 = (undefined4 *)0x56;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityBulwark";
  local_58 = (undefined4 *)0x65;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityWarFrenzy";
  local_58 = (undefined4 *)0x66;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityRangerKick";
  local_58 = (undefined4 *)0x15;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityRetreat";
  local_58 = (undefined4 *)0x32;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityAim";
  local_58 = (undefined4 *)0x63;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  local_58 = (undefined4 *)0x64;
  pwVar9 = L"AbilitySwiftness";
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityFireExplosion";
  local_58 = (undefined4 *)0x58;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityManaShield";
  local_58 = (undefined4 *)0x67;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityTeleport";
  local_58 = (undefined4 *)0x31;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityHealingStream";
  local_58 = (undefined4 *)0x22;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityIntercept";
  local_58 = (undefined4 *)0x30;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityShuriken";
  local_58 = (undefined4 *)0x60;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilityCamouflage";
  local_58 = (undefined4 *)0x61;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  pwVar9 = L"AbilitySneak";
  local_58 = (undefined4 *)0x4f;
  World_map_find_or_insert_int(&local_58);
  u16string_assignFromWide(pwVar9);
  local_30 = (undefined4 *)0x0;
  local_58 = (undefined4 *)0x1;
  local_5c = (undefined4 *)0x2;
  local_34 = 3;
  local_44 = 4;
  local_90 = 6;
  local_98 = 0xb;
  local_8c = 0xc;
  local_94 = 7;
  local_9c = 8;
  local_60 = 0xd;
  local_38 = 0xf;
  do {
    selfBase = local_30;
    uVar10 = 0;
    obj = pair_assign_2dword(local_138,&local_58,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Village";
    World_MapInsertChunk(local_88);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_f0,&local_5c,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Mountain";
    World_MapInsertChunk(local_a4);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_100,&local_34,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Forest";
    World_MapInsertChunk(local_b4);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_120,&local_44,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Lake";
    World_MapInsertChunk(local_e8);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_110,&local_90,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Canyon";
    World_MapInsertChunk(local_d4);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_130,&local_98,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Rock";
    World_MapInsertChunk(local_c4);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_f8,&local_8c,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Tree";
    World_MapInsertChunk(local_e0);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_108,&local_94,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Valley";
    World_MapInsertChunk(local_ac);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_118,&local_9c,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Crater";
    World_MapInsertChunk(local_bc);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(local_128,&local_60,&local_30,0);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Peak";
    World_MapInsertChunk(local_cc);
    u16string_assignFromWide(pwVar9);
    uVar10 = 0;
    obj = pair_assign_2dword(&local_1c,&local_38,&local_30);
    Pair_Copy2(obj,uVar10);
    pwVar9 = L"Island";
    World_MapInsertChunk(local_50);
    u16string_assignFromWide(pwVar9);
    local_30 = (undefined4 *)((int)selfBase + 1);
  } while ((int)local_30 < 10);
  uVar10 = 0;
  local_38 = 0;
  local_60 = 5;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Ruins";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 1;
  local_60 = 5;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Ruins";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 2;
  local_60 = 5;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Ruins";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 3;
  local_60 = 5;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Ruins";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 4;
  local_60 = 5;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Gravesite";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 0;
  local_60 = 0xe;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Castle";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 1;
  local_60 = 0xe;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Ruins";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 2;
  local_60 = 0xe;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Catacombs";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 3;
  local_60 = 0xe;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Palace";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 4;
  local_60 = 0xe;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Temple";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 5;
  local_60 = 0xe;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Pyramid";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 0;
  local_60 = 9;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Cave";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 0;
  local_60 = 10;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Portal";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 1;
  local_60 = 1;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Trade Quarter";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 2;
  local_60 = 1;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Crafting Quarter";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 3;
  local_60 = 1;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Class Quarter";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 4;
  local_60 = 1;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Pet Quarter";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 0;
  local_60 = 4;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Portal";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  uVar10 = 0;
  local_38 = 0;
  local_60 = 5;
  obj = pair_assign_2dword(&local_1c,&local_60,&local_38,0);
  Pair_Copy2(obj,uVar10);
  pwVar9 = L"Palace";
  World_MapInsertChunk(local_50);
  u16string_assignFromWide(pwVar9);
  deref_frontValue(&local_30);
  obj = store_object_ref(&local_40);
  cVar1 = operator_ne_int(obj);
  while (cVar1 != '\0') {
    selfBase = (undefined4 *)iterator_at_0x10();
    puVar4 = (undefined4 *)std_map_getOrInsertByKey(selfBase + 1);
    *puVar4 = *selfBase;
    iterator_deref_advance(&local_38,0);
    obj = store_object_ref(&local_40);
    cVar1 = operator_ne_int(obj);
  }
  deref_frontValue(&local_30);
  obj = store_object_ref(&local_40);
  cVar1 = operator_ne_int(obj);
  while (cVar1 != '\0') {
    selfBase = (undefined4 *)iterator_at_0x10();
    puVar4 = (undefined4 *)std_map_getOrInsertByKey(selfBase + 1);
    *puVar4 = *selfBase;
    iterator_deref_advance(&local_38,0);
    obj = store_object_ref(&local_40);
    cVar1 = operator_ne_int(obj);
  }
  deref_frontValue(&local_30);
  obj = store_object_ref(&local_40);
  cVar1 = operator_ne_int(obj);
  selfBase = local_6c;
  while (cVar1 != '\0') {
    local_6c = selfBase;
    iVar7 = iterator_at_0x10();
    World_MapInsertKeyed(iVar7 + 8);
    vec2_copy(iVar7);
    iterator_deref_advance(&local_38,0);
    obj = store_object_ref(&local_40);
    cVar1 = operator_ne_int(obj);
    selfBase = local_6c;
  }
  iVar7 = 0x400;
  puVar4 = selfBase + 0x10002f;
  do {
    iVar6 = 0x400;
    do {
      puVar4[-0x100000] = 0;
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(selfBase + 0x200030),0x80000400);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(selfBase + 0x200036),0x80000400);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x14;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x0;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-floor-wood.cub");
  local_8._0_1_ = 0x15;
  local_40 = (undefined4 *)0x0;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x16;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x1;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-wall-window.cub");
  local_8._0_1_ = 0x17;
  local_40 = (undefined4 *)0x1;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x18;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x2;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-wall-door.cub");
  local_8._0_1_ = 0x19;
  local_40 = (undefined4 *)0x2;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x1a;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x3;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-roof1.cub");
  local_8._0_1_ = 0x1b;
  local_40 = (undefined4 *)0x3;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x1c;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x4;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-entrance.cub");
  local_8._0_1_ = 0x1d;
  local_40 = (undefined4 *)0x4;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x1e;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x5;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-wall.cub");
  local_8._0_1_ = 0x1f;
  local_40 = (undefined4 *)0x5;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x20;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x6;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-roof2.cub");
  local_8._0_1_ = 0x21;
  local_40 = (undefined4 *)0x6;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x22;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x7;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-roof3.cub");
  local_8._0_1_ = 0x23;
  local_40 = (undefined4 *)0x7;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x24;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x8;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-wall-balcony.cub");
  local_8._0_1_ = 0x25;
  local_40 = (undefined4 *)0x8;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x26;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0x9;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("framework-roof-wall2.cub");
  local_8._0_1_ = 0x27;
  local_40 = (undefined4 *)0x9;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x28;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0xa;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("building-stone-well.cub");
  local_8._0_1_ = 0x29;
  local_40 = (undefined4 *)0xa;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 0x12;
  string_dtor();
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x2a;
  if (local_40 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_54 = (undefined4 *)Sprite::ctor_0(local_68,0);
  }
  local_8._0_1_ = 0x12;
  local_40 = (undefined4 *)0xb;
  puVar4 = (undefined4 *)rbtree_findOrInsert_intKey(&local_40);
  *puVar4 = local_54;
  string_assignCStr("building-stone-stairs2.cub");
  local_8._0_1_ = 0x2b;
  local_40 = (undefined4 *)0xb;
  rbtree_findOrInsert_intKey(&local_40);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  string_dtor();
  obj = setVec3(0x4b002080,0x4b002080,0x42c80000);
  vec3_copy(obj);
  obj = 0;
  pfVar5 = (float *)arrayElem_stride4(1);
  iVar7 = (int)*pfVar5;
  pfVar5 = (float *)arrayElem_stride4(0);
  fVar8 = (float)terrain_generateColumnColor((int)*pfVar5,iVar7,obj);
  local_40 = (undefined4 *)(float)fVar8;
  pfVar5 = (float *)arrayElem_stride4(2);
  *pfVar5 = (float)local_40;
  obj = setPair_a(0x8000,0x8000);
  vec2_copy(obj);
  selfBase[0x2e] = 0;
  local_40 = (undefined4 *)0x23;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x57;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x3c;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x37;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x22;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x17;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x16;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x1e;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x21;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x62;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x19;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x35;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x43;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x66;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x68;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x69;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x13;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x28;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x25;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x26;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x27;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x5c;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x5d;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x38;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x5a;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x5b;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x32;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x1b;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x4b;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x1a;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x56;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x63;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x6a;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x3f;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x42;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x40;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x41;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x4a;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x24;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x39;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x3a;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x3b;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x3d;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x3e;
  std_vector_push_back_4byte(&local_40);
  local_40 = (undefined4 *)0x58;
  std_vector_push_back_4byte(&local_40);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::World::ctor_0 @ 00593ed0 */

void cube::World::ctor_0(void)

{
  undefined4 *puVar1;
  char isLeaf;
  int *node;
  undefined4 *puVar4;
  int *parent;
  uint uVar6;
  undefined4 *self;
  int *chunkCol;
  int iVar8;
  int iVar9;
  int chunkX;
  int iVar11;
  int colY;
  int colX;
  undefined4 *selfBase;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f1a5b;
  local_10 = ExceptionList;
  uVar6 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  chunkX = 0;
  local_8 = 0x12;
  colY = 0;
  chunkCol = self + 0x2f;
  colX = 0;
  selfBase = self;
  while( true ) {
    iVar9 = colX;
    if (*chunkCol != 0) {
      if (*(char *)(selfBase + 0x2d) == '\0') {
        iVar8 = 0x10018;
        do {
          iVar11 = 0x40;
          do {
            std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_13
                      (*(undefined4 *)(*chunkCol + iVar8));
            iVar9 = colX;
            chunkX = colY;
            iVar8 = iVar8 + 4;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        } while (iVar8 < 0x14018);
        std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_17
                  (colY,colX);
      }
      if ((undefined4 *)*chunkCol != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*chunkCol)(1,uVar6);
      }
    }
    if ((void *)chunkCol[0x100000] != (void *)0x0) break;
    colX = iVar9 + 1;
    chunkCol = chunkCol + 1;
    if (0x3ff < colX) {
      chunkX = chunkX + 1;
      colY = chunkX;
      if (0x3ff < chunkX) {
        chunkCol = *(int **)selfBase[1];
        if (chunkCol != (int *)selfBase[1]) {
          do {
            if ((undefined4 *)chunkCol[6] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)chunkCol[6])(1);
            }
            if (*(char *)((int)chunkCol + 0xd) == '\0') {
              node = (int *)chunkCol[2];
              if (*(char *)((int)node + 0xd) == '\0') {
                isLeaf = *(char *)(*node + 0xd);
                chunkCol = node;
                node = (int *)*node;
                while (isLeaf == '\0') {
                  isLeaf = *(char *)(*node + 0xd);
                  chunkCol = node;
                  node = (int *)*node;
                }
              }
              else {
                isLeaf = *(char *)(chunkCol[1] + 0xd);
                parent = (int *)chunkCol[1];
                node = chunkCol;
                while ((chunkCol = parent, isLeaf == '\0' && (node == (int *)chunkCol[2]))) {
                  isLeaf = *(char *)(chunkCol[1] + 0xd);
                  parent = (int *)chunkCol[1];
                  node = chunkCol;
                }
              }
            }
          } while (chunkCol != (int *)selfBase[1]);
        }
        chunkCol = *(int **)selfBase[3];
        if (chunkCol != (int *)selfBase[3]) {
          do {
            colY = chunkCol[6];
            if (colY != 0) {
              puVar1 = (undefined4 *)(colY + 0x78);
              puVar4 = (undefined4 *)*puVar1;
              std_Tree_eraseRange(&colX,*puVar4,puVar4);
              operator_delete((void *)*puVar1);
            }
            if (*(char *)((int)chunkCol + 0xd) == '\0') {
              node = (int *)chunkCol[2];
              if (*(char *)((int)node + 0xd) == '\0') {
                isLeaf = *(char *)(*node + 0xd);
                chunkCol = node;
                node = (int *)*node;
                while (isLeaf == '\0') {
                  isLeaf = *(char *)(*node + 0xd);
                  chunkCol = node;
                  node = (int *)*node;
                }
              }
              else {
                isLeaf = *(char *)(chunkCol[1] + 0xd);
                parent = (int *)chunkCol[1];
                node = chunkCol;
                while ((chunkCol = parent, isLeaf == '\0' && (node == (int *)chunkCol[2]))) {
                  isLeaf = *(char *)(chunkCol[1] + 0xd);
                  parent = (int *)chunkCol[1];
                  node = chunkCol;
                }
              }
            }
            colY = 0;
          } while (chunkCol != (int *)selfBase[3]);
        }
        DeleteCriticalSection((LPCRITICAL_SECTION)(selfBase + 0x200030));
        DeleteCriticalSection((LPCRITICAL_SECTION)(selfBase + 0x200036));
        local_8 = CONCAT31(local_8._1_3_,0x11);
        std_Tree_eraseRange(&colY,*(undefined4 *)selfBase[0x200055],(undefined4 *)selfBase[0x200055]);
        operator_delete((void *)selfBase[0x200055]);
      }
      colX = 0;
    }
  }
  operator_delete((void *)chunkCol[0x100000]);
}




/* [AUDIT] proposed: World_MapInsertChunk  (confidence: low)
 * purpose: Game/STL: inserts a chunk record into a World map keyed by (x,y), building the node and rebalancing (SEH)
 * vars: self=map; local key x/y
 */
/* Global::World_MapInsertChunk @ 005943b0 */

void World_MapInsertChunk(int *coords)

{
  int existing;
  int node;
  int *in_ECX;
  undefined1 local_50 [4];
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  int x;
  int y;
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f1a90;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  existing = std_Tree_lower_bound_xy(coords);
  if (existing != *in_ECX) {
    if ((*(int *)(existing + 0x10) <= *coords) &&
       ((*(int *)(existing + 0x10) < *coords || (*(int *)(existing + 0x14) <= coords[1]))))
    goto LAB_00594490;
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_8 = 0;
  x = *coords;
  y = coords[1];
  u16string_moveConstruct(local_4c);
  local_8 = CONCAT31(local_8._1_3_,1);
  node = MapNode_CreateXY(&x);
  RBTree_InsertHintXY(local_50,existing,node + 0x10,node);
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffff0000);
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
LAB_00594490:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World_MapInsertKeyed  (confidence: low)
 * purpose: Game/STL: inserts a keyed record into a World map using string/blob comparison (u16string_compare)
 * vars: in_ECX=map; coords=key src
 */
/* Global::World_MapInsertKeyed @ 005944c0 */

void World_MapInsertKeyed(int key)

{
  int existing;
  int *keyPtr;
  int cmp;
  int *in_ECX;
  undefined1 local_38 [4];
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f1ac8;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  existing = map_lower_bound_string(key);
  if (existing != *in_ECX) {
    keyPtr = (int *)(existing + 0x10);
    if (7 < *(uint *)(existing + 0x24)) {
      keyPtr = (int *)*keyPtr;
    }
    cmp = u16string_compare(0,*(undefined4 *)(key + 0x10),keyPtr,*(undefined4 *)(existing + 0x20));
    if (-1 < cmp) goto LAB_00594581;
  }
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
  u16string_replaceRange(key,0,0xffffffff);
  local_1c = 0;
  local_18 = 0;
  local_8 = 0;
  cmp = MapNode_CreateB(local_34);
  RBTree_InsertHintKeyed(local_38,existing,cmp + 0x10,cmp);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
LAB_00594581:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::World::vfunc_0 @ 005946c0 */

void cube::World::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  ctor_0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* [AUDIT] proposed: Terrain::sampleBlockAt_fwd  (confidence: high)
 * purpose: Thin wrapper forwarding first two fields of param_2 to WorldMap_lookupTileValue2
 * vars: param_2=coord pair; returns param_1
 */
/* Global::Terrain_sampleBlockAt_fwd @ 0059fe70 */

undefined4 Terrain_sampleBlockAt_fwd(undefined4 out,undefined1 *coord_pair)

{
  WorldMap_lookupTileValue2(out,*coord_pair,coord_pair[1]);
  return out;
}




/* [AUDIT] proposed: WorldMap::lookupTileValue2  (confidence: med)
 * purpose: Map lower_bound by (x,y) vs end at +0x80012c; return value struct {0,0,7} from node +0x18 or raise error; twin of 5a5240
 * vars: +0x80012c=map end (different map than 5a5240); result offsets +8/+0x10/+0x14
 */
/* Global::WorldMap_lookupTileValue2 @ 005a64b0 */

undefined2 * WorldMap_lookupTileValue2(undefined2 *out,int x,int z)

{
  int end;
  int result;
  int found;
  int world;
  int key_x;
  int key_z;
  undefined4 local_8;
  
  local_8 = 0;
  key_x = x;
  key_z = z;
  found = std_Tree_lower_bound_xy(&key_x);
  end = *(int *)(world + 0x80012c);
  result = end;
  if (((found != end) && (*(int *)(found + 0x10) <= x)) &&
     ((*(int *)(found + 0x10) < x || (*(int *)(found + 0x14) <= z)))) {
    result = found;
  }
  x = result;
  if (x != end) {
    *(undefined4 *)(out + 10) = 7;
    *(undefined4 *)(out + 8) = 0;
    *out = 0;
    u16string_replaceRange(x + 0x18,0,0xffffffff);
    return out;
  }
  u16string_assignCStr(&PTR_006fccac);
  return out;
}




/* [AUDIT] proposed: NameGen::generateRegionName  (confidence: med)
 * purpose: Lazily init syllable tables (reon/mala/rion...) guarded by DAT_0076dbb8, then build random region/place name indexing tables at +0x80028c/+0x800290
 * vars: DAT_0076dbb8=init guard; %0x14=table slot; inputs bounded <0x1000000; SEH frame
 */
/* Global::NameGen_generateRegionName @ 005a6550 */

void NameGen_generateRegionName(undefined2 *param_1,uint x,int z)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined1 local_44 [16];
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 name_index;
  
  name_index = 0xffffffff;
  puStack_c = &LAB_006f33d0;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = 0;
  if ((x < 0x1000000) && (z < 0x1000000)) {
    if ((DAT_0076dbb8 & 1) == 0) {
      DAT_0076dbb8 = DAT_0076dbb8 | 1;
      name_index = 0;
      u16string_assignCStr(&DAT_0071d15c);
      name_index._0_1_ = 1;
      u16string_assignCStr(&DAT_0071d164);
      name_index._0_1_ = 2;
      u16string_assignCStr(&DAT_0071d16c);
      name_index._0_1_ = 3;
      u16string_assignCStr(&DAT_0071c794);
      name_index._0_1_ = 4;
      u16string_assignCStr(&DAT_0071cb8c);
      name_index._0_1_ = 5;
      u16string_assignCStr(&DAT_0071cad0);
      name_index._0_1_ = 6;
      u16string_assignCStr(&DAT_0071d174);
      name_index._0_1_ = 7;
      u16string_assignCStr(&DAT_0071d17c);
      name_index._0_1_ = 8;
      u16string_assignCStr(&DAT_0071d184);
      name_index._0_1_ = 9;
      u16string_assignCStr(&DAT_0071d18c);
      name_index._0_1_ = 10;
      u16string_assignCStr(&DAT_0071cbf0);
      name_index._0_1_ = 0xb;
      u16string_assignCStr(&DAT_0071d194);
      name_index._0_1_ = 0xc;
      u16string_assignCStr(&DAT_0071d19c);
      name_index._0_1_ = 0xd;
      u16string_assignCStr(&DAT_0071d18c);
      name_index._0_1_ = 0xe;
      u16string_assignCStr(&DAT_0071c970);
      name_index._0_1_ = 0xf;
      u16string_assignCStr(&DAT_0071ce10);
      name_index._0_1_ = 0x10;
      u16string_assignCStr(&DAT_0071d1a4);
      name_index._0_1_ = 0x11;
      u16string_assignCStr(&DAT_0071cf6c);
      name_index._0_1_ = 0x12;
      u16string_assignCStr(&DAT_0071d1ac);
      name_index = CONCAT31(name_index._1_3_,0x13);
      u16string_assignCStr(&DAT_0071d1b4);
      _atexit((_func_4879 *)&LAB_006fb6b0);
    }
    if ((DAT_0076dbb8 & 2) == 0) {
      DAT_0076dbb8 = DAT_0076dbb8 | 2;
      name_index = 0x14;
      u16string_assignCStr(&DAT_0071cc2c);
      name_index._0_1_ = 0x15;
      u16string_assignCStr(L"mala");
      name_index._0_1_ = 0x16;
      u16string_assignCStr(&DAT_0071d1c8);
      name_index._0_1_ = 0x17;
      u16string_assignCStr(&DAT_0071d1d0);
      name_index._0_1_ = 0x18;
      u16string_assignCStr(&DAT_0071d1d8);
      name_index._0_1_ = 0x19;
      u16string_assignCStr(&DAT_0071d1e0);
      name_index._0_1_ = 0x1a;
      u16string_assignCStr(&DAT_0071ca64);
      name_index._0_1_ = 0x1b;
      u16string_assignCStr(&DAT_0071c7e8);
      name_index._0_1_ = 0x1c;
      u16string_assignCStr(&DAT_0071d1e8);
      name_index._0_1_ = 0x1d;
      u16string_assignCStr(&DAT_0071d1f0);
      name_index._0_1_ = 0x1e;
      u16string_assignCStr(&DAT_0071c7e8);
      name_index._0_1_ = 0x1f;
      u16string_assignCStr(&DAT_0071cce8);
      name_index._0_1_ = 0x20;
      u16string_assignCStr(&DAT_0071c7f0);
      name_index._0_1_ = 0x21;
      u16string_assignCStr(L"rion");
      name_index._0_1_ = 0x22;
      u16string_assignCStr(L"remo");
      name_index._0_1_ = 0x23;
      u16string_assignCStr(L"antis");
      name_index._0_1_ = 0x24;
      u16string_assignCStr(&DAT_0071d21c);
      name_index._0_1_ = 0x25;
      u16string_assignCStr(&DAT_0071d224);
      name_index._0_1_ = 0x26;
      u16string_assignCStr(L"reon");
      name_index = CONCAT31(name_index._1_3_,0x27);
      u16string_assignCStr(L"tuma");
      _atexit((_func_4879 *)&LAB_006fb950);
    }
    name_index = 0xffffffff;
    uVar2 = Terrain_sampleHeightNoise(local_44,x,z);
    Vec2_DoubleToInt(uVar2);
    iVar1 = *(int *)(in_ECX + 0x800290);
    local_34[0] = 0;
    local_20 = 7;
    local_24 = 0;
    u16string_replaceRange(&DAT_0076d9d8 +
                 ((local_18 * 3 + *(int *)(in_ECX + 0x80028c) + local_1c) % 0x14) * 0x18,0,
                 0xffffffff);
    name_index = 0x28;
    std_u16string_replace(&DAT_0076dbc0 + ((local_1c * 3 + iVar1 + local_18) % 0x14) * 0x18,0,0xffffffff);
    u16string_moveConstruct(local_34);
    std_string_FreeMember();
    uVar2 = extraout_EDX;
  }
  else {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    u16string_assignPtrLen(&PTR_006fccac,0);
    uVar2 = extraout_EDX_00;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar2,uVar3);
  return;
}




/* Global::FUN_006023b0 @ 006023b0 */

int FUN_006023b0(uint param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  
  if ((((-1 < (int)param_1) && (-1 < (int)param_2)) && ((int)param_1 < 0x2000)) &&
     (((int)param_2 < 0x2000 &&
      (iVar1 = *(int *)(in_ECX + 0xb0 +
                       (((int)(((int)(param_1 * 8) >> 0x1f & 0x3fU) + param_1 * 8) >> 6) * 0x400 +
                       ((int)(param_2 * 8 + ((int)(param_2 * 8) >> 0x1f & 0x3fU)) >> 6)) * 4),
      iVar1 != 0)))) {
    param_1 = param_1 & 0x80000007;
    if ((int)param_1 < 0) {
      param_1 = (param_1 - 1 | 0xfffffff8) + 1;
    }
    param_2 = param_2 & 0x80000007;
    if ((int)param_2 < 0) {
      param_2 = (param_2 - 1 | 0xfffffff8) + 1;
    }
    return (param_2 + (param_1 + 0x100) * 8) * 0x68 + iVar1;
  }
  return 0;
}




