// Zone (world) — cube. 5 functions. Bodies = Ghidra pseudo-C.
#include "Zone.h"

/* [AUDIT] proposed: Zone_DestroyObjectRange  (confidence: med)
 * purpose: Game/STL: destroys a range of Zone objects (stride 0x188 bytes = 0x62 dwords), freeing nested container storage
 * vars: stride 0x62 dwords; operator_delete
 */
/* Global::Zone_DestroyObjectRange @ 0058d970 */

void Zone_DestroyObjectRange(int *begin,int *end)

{
  int *zoneEnd;
  undefined4 *objList;
  int *zonePtr;
  
  if (begin != end) {
    zonePtr = begin + 0x12;
    do {
      objList = (undefined4 *)*zonePtr;
      if (objList != (undefined4 *)0x0) {
        while( true ) {
          if (objList == (undefined4 *)zonePtr[1]) {
                    /* WARNING: Subroutine does not return */
            operator_delete((void *)*zonePtr);
          }
          if ((void *)*objList != (void *)0x0) break;
          objList = objList + 3;
        }
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)*objList);
      }
      zoneEnd = zonePtr + 0x50;
      zonePtr = zonePtr + 0x62;
    } while (zoneEnd != end);
  }
  return;
}




/* cube::Zone::constructTileGrid @ 005fae00 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::Zone::constructTileGrid.
 * Composite ctor: eh_vector_constructor_iterator builds ZoneTile[4096]@0x34 (cube::ZoneTile::ctor) then a hardcoded 64x cube::Region_ctor loop. Caller operator_new(0x35a00 = 4096*0x34 + 64*0x68). Type-specific game aggregate ctor, not a template/thunk.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void cube::Zone::constructTileGrid(void)

{
  void *in_ECX;
  int iVar1;
  
  _eh_vector_constructor_iterator_(in_ECX,0x34,0x1000,cube::ZoneTile::ctor_1,cube::ZoneTile::ctor_0)
  ;
  iVar1 = 0x3f;
  do {
    Region_ctor();
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  return;
}




/* cube::Zone::ctor_0 @ 006240f0 */

void cube::Zone::ctor_0(void)

{
  uint security_cookie;
  undefined4 uVar2;
  undefined4 *alloc;
  undefined4 *self;
  undefined4 *field_array;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f54a5;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  uVar2 = list_allocNode(0,0);
  self[1] = uVar2;
  self[3] = 0;
  self[4] = 0;
  self[5] = 0;
  self[6] = 0;
  self[7] = 0;
  self[8] = 0;
  self[9] = 0;
  self[10] = 0;
  self[0xb] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0;
  self[0xf] = 0;
  self[0x10] = 0;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  self[0x1a] = 0;
  self[0x1b] = 0;
  self[0x1c] = 0;
  *(undefined2 *)(self + 0x1d) = 1;
  *(undefined1 *)((int)self + 0x76) = 0;
  self[0x1e] = 0;
  self[0x1f] = 0;
  self[0x20] = 1;
  *(undefined1 *)(self + 0x21) = 0;
  self[0x22] = 0;
  self[0x23] = 0;
  self[0x24] = 0;
  self[0x25] = 0;
  self[0x26] = 0;
  self[0x27] = 0;
  local_8._0_1_ = 10;
  local_8._1_3_ = 0;
  self[0x28] = 0;
  self[0x29] = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(self + 0x2c),0x80000400);
  alloc = (undefined4 *)operator_new_wrapper(0x200004,security_cookie);
  local_8._0_1_ = 0xb;
  if (alloc == (undefined4 *)0x0) {
    field_array = (undefined4 *)0x0;
  }
  else {
    field_array = alloc + 1;
    *alloc = 0x10000;
    _eh_vector_constructor_iterator_
              (field_array,0x20,0x10000,(_func_void_void_ptr *)&LAB_00450bf0,Field::ctor_0);
  }
  local_8._0_1_ = 10;
  self[0x2a] = field_array;
  alloc = (undefined4 *)operator_new_wrapper(0x2004,security_cookie);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  if (alloc != (undefined4 *)0x0) {
    *alloc = 0x400;
    _eh_vector_constructor_iterator_(alloc + 1,8,0x400,lib_fn_6240d0,std_list_clear_4da480);
    self[0x2b] = alloc + 1;
    ExceptionList = local_10;
    return;
  }
  self[0x2b] = 0;
  ExceptionList = local_10;
  return;
}




/* cube::Zone::ctor_1 @ 00624390 */

void cube::Zone::ctor_1(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint security_cookie;
  undefined4 *self;
  int *iter;
  undefined4 local_24;
  undefined1 local_20 [8];
  int item;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f553f;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  puVar1 = (undefined4 *)self[0x2a];
  local_8 = 10;
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1[-1] == 0) {
      operator_delete__(puVar1 + -1);
    }
    else {
      (**(code **)*puVar1)(3,security_cookie);
    }
  }
  pvVar2 = (void *)self[0x2b];
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar2,8,*(int *)((int)pvVar2 + -4),std_list_clear_4da480);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  iter = (int *)self[6];
  if (iter != (int *)self[7]) {
    do {
      if ((undefined4 *)*iter != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*iter)(1);
      }
      iter = iter + 1;
    } while (iter != (int *)self[7]);
  }
  iter = (int *)self[9];
  if (iter != (int *)self[10]) {
    do {
      item = *iter;
      if (item != 0) {
        puVar1 = (undefined4 *)(item + 0x78);
        puVar3 = (undefined4 *)*puVar1;
        std_Tree_eraseRange(local_20,*puVar3,puVar3);
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)*puVar1);
      }
      iter = iter + 1;
      item = 0;
    } while (iter != (int *)self[10]);
  }
  iter = (int *)self[0x22];
  if (iter != (int *)self[0x23]) {
    do {
      if ((undefined4 *)*iter != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*iter)(1);
      }
      iter = iter + 1;
    } while (iter != (int *)self[0x23]);
  }
  iter = (int *)self[0x25];
  if (iter != (int *)self[0x26]) {
    do {
      item = *iter;
      if (item != 0) {
        puVar1 = (undefined4 *)(item + 8);
        puVar3 = (undefined4 *)*puVar1;
        Zone_rbtree_eraseRange(local_20,*puVar3,puVar3);
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)*puVar1);
      }
      iter = iter + 1;
      item = 0;
    } while (iter != (int *)self[0x26]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(self + 0x2c));
  if ((void *)self[0x25] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x25]);
  }
  if ((void *)self[0x22] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x22]);
  }
  if ((void *)self[0x1a] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x1a]);
  }
  if ((void *)self[0x15] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x15]);
  }
  if ((void *)self[0x12] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x12]);
  }
  if ((void *)self[0xf] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0xf]);
  }
  if ((void *)self[0xc] == (void *)0x0) {
    if ((void *)self[9] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)self[9]);
    }
    if ((void *)self[6] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)self[6]);
    }
    if (self[3] != 0) {
      Zone_DestroyObjectRange(self[3],self[4],&local_11,local_24);
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)self[3]);
    }
    puVar1 = (undefined4 *)self[1];
    pvVar2 = (void *)*puVar1;
    *puVar1 = puVar1;
    *(undefined4 *)(self[1] + 4) = self[1];
    self[2] = 0;
    if (pvVar2 == (void *)self[1]) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)self[1]);
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)self[0xc]);
}




/* cube::Zone::vfunc_0 @ 00624760 */

void cube::Zone::vfunc_0(byte delete_flag)

{
  void *self;
  
  ctor_1();
  if ((delete_flag & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(self);
  }
  return;
}




