// Dungeon (world) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "Dungeon.h"

/* cube::Dungeon::ctor_0 @ 005c38c0 */

void cube::Dungeon::ctor_0(int size_x,int size_y,int size_z)

{
  undefined2 *puVar1;
  undefined2 *buffer;
  undefined4 *self;
  uint cell_count;
  
  self[3] = size_x;
  cell_count = size_x * size_y * size_z;
  self[4] = size_y;
  self[5] = size_z;
  *self = vftable;
  self[1] = 0;
  *(undefined1 *)(self + 2) = 0;
  buffer = (undefined2 *)
           operator_new_wrapper(-(uint)((int)((ulonglong)cell_count * 2 >> 0x20) != 0) |
                        (uint)((ulonglong)cell_count * 2));
  puVar1 = buffer;
  if (buffer == (undefined2 *)0x0) {
    self[6] = 0;
    return;
  }
  while (cell_count = cell_count - 1, -1 < (int)cell_count) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  self[6] = buffer;
  return;
}




/* cube::Dungeon::ctor_1 @ 005c3c60 */

void cube::Dungeon::ctor_1(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  operator_delete__((void *)in_ECX[6]);
  return;
}




/* cube::Dungeon::vfunc_0 @ 005c3f80 */

void cube::Dungeon::vfunc_0(byte flags)

{
  undefined4 *self;
  
  *self = vftable;
  operator_delete__((void *)self[6]);
  if ((flags & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(self);
  }
  return;
}




