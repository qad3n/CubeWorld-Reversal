// Dungeon (world) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "Dungeon.h"

/* cube::Dungeon::ctor_0 @ 004f7370 */

undefined4 * __thiscall cube::Dungeon::ctor_0(Dungeon *this,int size_x,int size_y,int size_z)

{
  undefined2 *fill_ptr;
  undefined2 *buffer;
  uint volume;
  
  *(int *)(this + 0xc) = size_x;
  volume = size_x * size_y * size_z;
  *(int *)(this + 0x10) = size_y;
  *(int *)(this + 0x14) = size_z;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  this[8] = (Dungeon)0x0;
  buffer = (undefined2 *)
           operator_new_wrapper(-(uint)((int)((ulonglong)volume * 2 >> 0x20) != 0) |
                        (uint)((ulonglong)volume * 2));
  fill_ptr = buffer;
  if (buffer == (undefined2 *)0x0) {
    *(undefined4 *)(this + 0x18) = 0;
    return (undefined4 *)this;
  }
  while (volume = volume - 1, -1 < (int)volume) {
    *fill_ptr = 0;
    fill_ptr = fill_ptr + 1;
  }
  *(undefined2 **)(this + 0x18) = buffer;
  return (undefined4 *)this;
}




/* cube::Dungeon::ctor_1 @ 004f7790 */

void __fastcall cube::Dungeon::ctor_1(undefined4 *self)

{
  *self = vftable;
  operator_delete__((void *)self[6]);
  return;
}




/* cube::Dungeon::vfunc_0 @ 004f7b00 */

undefined4 * __thiscall cube::Dungeon::vfunc_0(Dungeon *this,byte delete_flag)

{
  *(undefined ***)this = vftable;
  operator_delete__(*(void **)(this + 0x18));
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




