// WorldMap (world) — cube. 4 functions. Bodies = Ghidra pseudo-C.
#include "WorldMap.h"

/* cube::WorldMap::ctor_1 @ 005fae40 */

void cube::WorldMap::ctor_1(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *self;
  int col;
  uint uVar10;
  int row;
  uint uVar12;
  void *pvVar13;
  undefined2 *puVar14;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  void *local_48;
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 local_3c [2];
  undefined1 local_31;
  uint *local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4999;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[0x24] = 0xffffffff;
  self[0x25] = 0xffffffff;
  self[0x26] = 0xffffffff;
  self[0x27] = 0xffffffff;
  self[0x2a] = param_3;
  local_3c[1] = param_1;
  *(undefined1 *)(self + 0x28) = 0;
  self[0x29] = param_1;
  self[0x2b] = param_2;
  self[0x20002e] = 0;
  self[0x20002f] = 0;
  local_44 = self;
  Database::ctor_1(local_14);
  self[0x20003e] = 1;
  local_30 = self + 0x20003f;
  *local_30 = 0;
  self[0x200040] = 0;
  self[0x200041] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_48 = operator_new(0x60);
  local_8._0_1_ = 2;
  if (local_48 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Sprite::ctor_0(param_1,0);
  }
  puVar7 = local_44;
  local_8._0_1_ = 1;
  local_44[0x20002c] = uVar6;
  VoxelModel_allocate(4,4,4);
  row = 0;
  do {
    col = 0;
    do {
      if ((((row < 1) || (col < 1)) || (2 < row)) || (2 < col)) {
        iVar1 = puVar7[0x20002c];
        local_48 = (void *)CONCAT22(local_48._2_2_,0xa0a);
        pvVar13 = local_48;
        local_31 = 10;
        if (((row < 0) || (col < 0)) ||
           ((*(int *)(iVar1 + 0x44) <= row ||
            ((*(int *)(iVar1 + 0x48) <= col || (*(int *)(iVar1 + 0x4c) < 1)))))) {
          puVar14 = (undefined2 *)&DAT_0076b340;
        }
        else {
          puVar14 = (undefined2 *)
                    ((*(int *)(iVar1 + 0x44) * col + row) * 3 + *(int *)(iVar1 + 0x30));
        }
        local_48._0_2_ = 0xa0a;
        uVar5 = local_48._0_2_;
        local_48 = pvVar13;
      }
      else {
        iVar1 = puVar7[0x20002c];
        local_4c = 0xffff;
        local_31 = 0xff;
        if ((((row < 0) || (col < 0)) || (*(int *)(iVar1 + 0x44) <= row)) ||
           ((*(int *)(iVar1 + 0x48) <= col || (*(int *)(iVar1 + 0x4c) < 1)))) {
          puVar14 = (undefined2 *)&DAT_0076b340;
          uVar5 = 0xffff;
        }
        else {
          puVar14 = (undefined2 *)
                    ((*(int *)(iVar1 + 0x44) * col + row) * 3 + *(int *)(iVar1 + 0x30));
          uVar5 = 0xffff;
        }
      }
      *puVar14 = uVar5;
      col = col + 1;
      *(undefined1 *)(puVar14 + 1) = local_31;
    } while (col < 4);
    row = row + 1;
  } while (row < 4);
  VoxelModel_build_mesh();
  puVar4 = local_30;
  puVar7 = puVar7 + 0x10002c;
  row = 0x400;
  do {
    col = 0x400;
    do {
      puVar7[-0x100000] = 0;
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
      col = col + -1;
    } while (col != 0);
    row = row + -1;
  } while (row != 0);
  local_30 = operator_new(0x60);
  uVar6 = local_3c[1];
  local_8._0_1_ = 3;
  if (local_30 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = Sprite::ctor_0(local_3c[1],0);
  }
  local_8._0_1_ = 1;
  local_44[0x20002d] = uVar8;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen("skull.cub",9);
  local_8._0_1_ = 4;
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 1;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_30 = operator_new(0x60);
  local_8._0_1_ = 5;
  if (local_30 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Sprite::ctor_0(uVar6,0);
  }
  puVar7 = (undefined4 *)puVar4[1];
  local_8 = CONCAT31(local_8._1_3_,1);
  local_54 = uVar6;
  if (&local_54 < puVar7) {
    puVar2 = (undefined4 *)*puVar4;
    if (&local_54 < puVar2) goto LAB_005fb18a;
    puVar3 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar3) && ((int)puVar3 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar3 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = *(undefined4 *)(*puVar4 + ((int)&local_54 - (int)puVar2 >> 2) * 4);
    }
  }
  else {
LAB_005fb18a:
    puVar2 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar2) && ((int)puVar2 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar2 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = uVar6;
    }
  }
  puVar4[1] = puVar4[1] + 4;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen("map-tile-plains.cub",0x13);
  local_8._0_1_ = 6;
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 1;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_30 = operator_new(0x60);
  local_8._0_1_ = 7;
  if (local_30 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Sprite::ctor_0(local_3c[1],0);
  }
  puVar7 = (undefined4 *)puVar4[1];
  local_8 = CONCAT31(local_8._1_3_,1);
  local_50 = uVar6;
  if (&local_50 < puVar7) {
    puVar2 = (undefined4 *)*puVar4;
    if (&local_50 < puVar2) goto LAB_005fb2eb;
    puVar3 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar3) && ((int)puVar3 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar3 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = *(undefined4 *)(*puVar4 + ((int)&local_50 - (int)puVar2 >> 2) * 4);
    }
  }
  else {
LAB_005fb2eb:
    puVar2 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar2) && ((int)puVar2 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar2 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = uVar6;
    }
  }
  puVar4[1] = puVar4[1] + 4;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen("map-tile-village.cub",0x14);
  local_8._0_1_ = 8;
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 1;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_30 = operator_new(0x60);
  local_8._0_1_ = 9;
  if (local_30 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Sprite::ctor_0(local_3c[1],0);
  }
  puVar7 = (undefined4 *)puVar4[1];
  local_8 = CONCAT31(local_8._1_3_,1);
  local_3c[0] = uVar6;
  if (local_3c < puVar7) {
    puVar2 = (undefined4 *)*puVar4;
    if (local_3c < puVar2) goto LAB_005fb448;
    puVar3 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar3) && ((int)puVar3 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar3 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = *(undefined4 *)(*puVar4 + ((int)local_3c - (int)puVar2 >> 2) * 4);
    }
  }
  else {
LAB_005fb448:
    puVar2 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar2) && ((int)puVar2 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar2 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = uVar6;
    }
  }
  puVar4[1] = puVar4[1] + 4;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen("map-tile-forest.cub",0x13);
  local_8._0_1_ = 10;
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 1;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_30 = operator_new(0x60);
  local_8._0_1_ = 0xb;
  if (local_30 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Sprite::ctor_0(local_3c[1],0);
  }
  puVar7 = (undefined4 *)puVar4[1];
  local_8 = CONCAT31(local_8._1_3_,1);
  local_58 = uVar6;
  if (&local_58 < puVar7) {
    puVar2 = (undefined4 *)*puVar4;
    if (&local_58 < puVar2) goto LAB_005fb5a5;
    puVar3 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar3) && ((int)puVar3 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar3 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = *(undefined4 *)(*puVar4 + ((int)&local_58 - (int)puVar2 >> 2) * 4);
    }
  }
  else {
LAB_005fb5a5:
    puVar2 = (undefined4 *)puVar4[2];
    if ((puVar7 == puVar2) && ((int)puVar2 - (int)puVar7 >> 2 == 0)) {
      row = (int)((int)puVar7 - *puVar4) >> 2;
      if (row == 0x3fffffff) {
        std::_Xlength_error("vector<T> too long");
      }
      local_30 = (uint *)(row + 1);
      uVar12 = (int)((int)puVar2 - *puVar4) >> 2;
      if (0x3fffffff - (uVar12 >> 1) < uVar12) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uVar12 + (uVar12 >> 1));
      }
      if (pvVar13 < local_30) {
        pvVar13 = local_30;
      }
      std_vector_grow_realloc_stride4(pvVar13);
    }
    if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar4[1] = uVar6;
    }
  }
  puVar4[1] = puVar4[1] + 4;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen("map-tile-mountains.cub",0x16);
  local_8._0_1_ = 0xc;
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  local_8._0_1_ = 1;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_30 = operator_new(0x60);
  local_8._0_1_ = 0xd;
  if (local_30 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Sprite::ctor_0(local_3c[1],0);
  }
  puVar7 = (undefined4 *)puVar4[1];
  local_8 = CONCAT31(local_8._1_3_,1);
  local_40 = uVar6;
  if (&local_40 < puVar7) {
    puVar2 = (undefined4 *)*puVar4;
    if (puVar2 <= &local_40) {
      puVar3 = (undefined4 *)puVar4[2];
      if ((puVar7 == puVar3) && ((int)puVar3 - (int)puVar7 >> 2 == 0)) {
        row = (int)((int)puVar7 - *puVar4) >> 2;
        if (row == 0x3fffffff) {
          std::_Xlength_error("vector<T> too long");
        }
        uVar10 = row + 1;
        uVar12 = (int)((int)puVar3 - *puVar4) >> 2;
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar10) {
          uVar12 = uVar10;
        }
        std_vector_grow_realloc_stride4(uVar12);
      }
      if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar4[1] =
             *(undefined4 *)(*puVar4 + ((int)&local_40 - (int)puVar2 >> 2) * 4);
      }
      goto LAB_005fb753;
    }
  }
  puVar2 = (undefined4 *)puVar4[2];
  if ((puVar7 == puVar2) && ((int)puVar2 - (int)puVar7 >> 2 == 0)) {
    row = (int)((int)puVar7 - *puVar4) >> 2;
    if (row == 0x3fffffff) {
      std::_Xlength_error("vector<T> too long");
    }
    uVar10 = row + 1;
    uVar12 = (int)((int)puVar2 - *puVar4) >> 2;
    if (0x3fffffff - (uVar12 >> 1) < uVar12) {
      uVar12 = 0;
    }
    else {
      uVar12 = uVar12 + (uVar12 >> 1);
    }
    if (uVar12 < uVar10) {
      uVar12 = uVar10;
    }
    std_vector_grow_realloc_stride4(uVar12);
  }
  if ((undefined4 *)puVar4[1] != (undefined4 *)0x0) {
    *(undefined4 *)puVar4[1] = uVar6;
  }
LAB_005fb753:
  puVar4[1] = puVar4[1] + 4;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen("map-tile-hills.cub",0x12);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  VoxelModel_load_from_file_or_buffer(local_2c,0,1);
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(local_44 + 0x200036),0x80000400);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(local_44 + 0x200030),0x80000400);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::WorldMap::ctor_0 @ 005fb890 */

void cube::WorldMap::ctor_0(void)

{
  uint uVar1;
  undefined4 *self;
  int *node;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f49dc;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  node = (int *)self[0x20003f];
  local_8 = 1;
  if (node != (int *)self[0x200040]) {
    do {
      if ((undefined4 *)*node != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*node)(1,uVar1);
      }
      node = node + 1;
    } while (node != (int *)self[0x200040]);
  }
  WorldMap_ctor();
  DeleteCriticalSection((LPCRITICAL_SECTION)(self + 0x200036));
  DeleteCriticalSection((LPCRITICAL_SECTION)(self + 0x200030));
  if ((void *)self[0x20003f] != (void *)0x0) {
    operator_delete((void *)self[0x20003f]);
  }
  local_8 = 0xffffffff;
  Database::ctor_0();
  ExceptionList = local_10;
  return;
}




/* cube::WorldMap::vfunc_0 @ 005fbad0 */

void cube::WorldMap::vfunc_0(byte flags)

{
  void *self;
  
  ctor_0();
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return;
}




/* [AUDIT] proposed: WorldMap_ctor  (confidence: med)
 * purpose: Constructs/initializes WorldMap: allocates discovered-flags arrays and sub-objects ('discovered')
 * vars: ctor_14/16 sub-ctors; eh_vector_destructor; 'discovered'
 */
/* Global::WorldMap_ctor @ 00601f80 */

void WorldMap_ctor(void)

{
  void *pvVar1;
  char cVar2;
  int self;
  undefined4 *puVar3;
  int *piVar4;
  int col;
  int iVar6;
  void *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int row;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4b20;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = self;
  cVar2 = handle_isOpen(local_14);
  if (cVar2 != '\0') {
    local_44 = (void *)0x0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_8 = 0;
    Vector_Resize(4);
    *(undefined4 *)(local_38 + (int)local_44) = *(undefined4 *)(self + 0x8000bc);
    local_38 = local_38 + 4;
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
    string_assignPtrLen("discovered",10);
    local_8 = CONCAT31(local_8._1_3_,1);
    db_storeBlobVec(local_2c,&local_44);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    local_8 = 0xffffffff;
    if (local_44 != (void *)0x0) {
      operator_delete(local_44);
    }
  }
  *(undefined4 *)(local_34 + 0x8000bc) = 0;
  row = 0;
  puVar3 = (undefined4 *)(local_34 + 0xb0);
  do {
    col = 0;
    do {
      pvVar1 = (void *)*puVar3;
      if (pvVar1 != (void *)0x0) {
        std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_16
                  (row,col);
        _eh_vector_destructor_iterator_(pvVar1,0x34,0x1000,cube::ZoneTile::ctor_0);
        operator_delete(pvVar1);
      }
      col = col + 1;
      puVar3 = puVar3 + 1;
    } while (col < 0x400);
    row = row + 1;
  } while (row < 0x400);
  row = 0;
  piVar4 = (int *)(&UNK_00400080.field_0x30 + local_34);
  do {
    iVar6 = 0;
    col = row;
    do {
      puVar3 = (undefined4 *)*piVar4;
      if (puVar3 != (undefined4 *)0x0) {
        std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_14
                  (col,iVar6);
        (**(code **)*puVar3)(1);
        *piVar4 = 0;
        col = row;
      }
      iVar6 = iVar6 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar6 < 0x400);
    row = col + 1;
  } while (row < 0x400);
  cVar2 = handle_isOpen();
  if (cVar2 != '\0') {
    handle_freeMember4();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




