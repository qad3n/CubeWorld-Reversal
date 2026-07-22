// Region (world) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "Region.h"

/* cube::Region::ctor_0 @ 005c3ac0 */

void cube::Region::ctor_0(void)

{
  undefined4 uVar1;
  undefined4 *self;
  int count;
  int cursor;
  undefined4 *puVar4;
  
  *self = vftable;
  *(undefined1 *)(self + 2) = 1;
  self[3] = 1;
  self[4] = 0;
  self[5] = 0;
  count = 0xfff;
  cursor = (int)self + 0x1a;
  do {
    count = count + -1;
    *(undefined4 *)(cursor + -2) = 0;
    *(undefined4 *)(cursor + 2) = 0;
    *(undefined4 *)(cursor + 6) = 1;
    *(undefined1 *)(cursor + 10) = 0;
    cursor = cursor + 0x10;
  } while (-1 < count);
  cursor = 0x3f;
  do {
    Region_ctor();
    cursor = cursor + -1;
  } while (-1 < cursor);
  *(undefined1 *)(self + 0x5686) = 0;
  self[0x5687] = 0;
  self[0x5688] = 0;
  uVar1 = rbtree_allocHeaderNode_1c();
  self[0x5687] = uVar1;
  puVar4 = self + 0x4006;
  for (cursor = 0x1000; cursor != 0; cursor = cursor + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  return;
}




/* cube::Region::ctor_1 @ 005c3cc0 */

void cube::Region::ctor_1(void)

{
  uint uVar1;
  undefined4 *self;
  int row;
  int *slot;
  int col;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f3d4e;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  slot = self + 0x4006;
  row = 0x40;
  local_14 = self;
  do {
    col = 0x40;
    do {
      if ((undefined4 *)*slot != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*slot)(1,uVar1);
      }
      slot = slot + 1;
      col = col + -1;
    } while (col != 0);
    row = row + -1;
  } while (row != 0);
  local_8 = 0xffffffff;
  std_Tree_eraseRange(&local_14,*(undefined4 *)local_14[0x5687],(undefined4 *)local_14[0x5687]);
  operator_delete((void *)local_14[0x5687]);
}




/* cube::Region::vfunc_0 @ 005c3fb0 */

void cube::Region::vfunc_0(byte flags)

{
  void *self;
  
  ctor_1();
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return;
}




