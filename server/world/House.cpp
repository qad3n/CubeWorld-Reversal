// House (world) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "House.h"

/* cube::House::ctor_0 @ 004e1f80 */

undefined4 * __thiscall cube::House::ctor_0(House *this,int size_x,int size_y,int size_z)

{
  longlong lVar1;
  int buffer;
  int cell_ptr;
  int remaining;
  uint volume;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 state;
  
  puStack_c = &LAB_00554f57;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  this[8] = (House)0x0;
  *(undefined4 *)(this + 0x18) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(int *)(this + 100) = size_x;
  volume = size_x * size_y * size_z;
  *(int *)(this + 0x6c) = size_z;
  *(int *)(this + 0x68) = size_y;
  lVar1 = (ulonglong)volume * 0xc;
  state = 4;
  *(undefined4 *)(this + 0x60) = 0;
  buffer = operator_new_wrapper(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  if (buffer == 0) {
    *(undefined4 *)(this + 0x70) = 0;
  }
  else {
    remaining = volume - 1;
    if (-1 < remaining) {
      cell_ptr = buffer + 2;
      do {
        remaining = remaining + -1;
        *(undefined4 *)(cell_ptr + -2) = 0;
        *(undefined4 *)(cell_ptr + 2) = 0;
        *(undefined1 *)(cell_ptr + 6) = 0;
        cell_ptr = cell_ptr + 0xc;
      } while (-1 < remaining);
    }
    *(int *)(this + 0x70) = buffer;
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}




/* cube::House::ctor_1 @ 004e2250 */

void __fastcall cube::House::ctor_1(undefined4 *self)

{
  *self = vftable;
  operator_delete__((void *)self[0x1c]);
  if ((void *)self[0x15] != (void *)0x0) {
    operator_delete((void *)self[0x15]);
    self[0x15] = 0;
    self[0x16] = 0;
    self[0x17] = 0;
  }
  if ((void *)self[0x12] != (void *)0x0) {
    operator_delete((void *)self[0x12]);
    self[0x12] = 0;
    self[0x13] = 0;
    self[0x14] = 0;
  }
  if ((void *)self[0xf] != (void *)0x0) {
    operator_delete((void *)self[0xf]);
    self[0xf] = 0;
    self[0x10] = 0;
    self[0x11] = 0;
  }
  if ((void *)self[0xc] != (void *)0x0) {
    operator_delete((void *)self[0xc]);
    self[0xc] = 0;
    self[0xd] = 0;
    self[0xe] = 0;
  }
  if ((void *)self[9] != (void *)0x0) {
    operator_delete((void *)self[9]);
    self[9] = 0;
    self[10] = 0;
    self[0xb] = 0;
  }
  return;
}




/* cube::House::vfunc_0 @ 004e2380 */

undefined4 * __thiscall cube::House::vfunc_0(House *this,byte delete_flag)

{
  ctor_1((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




