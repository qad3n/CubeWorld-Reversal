// House (world) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "House.h"

/* cube::House::ctor_0 @ 005aeb40 */

void cube::House::ctor_0(int size_x,int size_y,int size_z)

{
  longlong lVar1;
  uint uVar2;
  int buffer;
  undefined4 *self;
  int iVar4;
  int iVar5;
  uint cell_count;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f36d7;
  local_10 = ExceptionList;
  uVar2 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  *(undefined1 *)(self + 2) = 0;
  self[6] = 0xffffffff;
  self[7] = 0xffffffff;
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
  self[0x19] = size_x;
  cell_count = size_x * size_y * size_z;
  self[0x1b] = size_z;
  self[0x1a] = size_y;
  lVar1 = (ulonglong)cell_count * 0xc;
  local_8 = 4;
  self[0x18] = 0;
  buffer = operator_new_wrapper(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1,uVar2);
  if (buffer == 0) {
    self[0x1c] = 0;
  }
  else {
    iVar5 = cell_count - 1;
    if (-1 < iVar5) {
      iVar4 = buffer + 2;
      do {
        iVar5 = iVar5 + -1;
        *(undefined4 *)(iVar4 + -2) = 0;
        *(undefined4 *)(iVar4 + 2) = 0;
        *(undefined1 *)(iVar4 + 6) = 0;
        iVar4 = iVar4 + 0xc;
      } while (-1 < iVar5);
    }
    self[0x1c] = buffer;
  }
  ExceptionList = local_10;
  return;
}




/* cube::House::ctor_1 @ 005aed20 */

void cube::House::ctor_1(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  operator_delete__((void *)in_ECX[0x1c]);
  if ((void *)in_ECX[0x15] != (void *)0x0) {
    operator_delete((void *)in_ECX[0x15]);
  }
  if ((void *)in_ECX[0x12] != (void *)0x0) {
    operator_delete((void *)in_ECX[0x12]);
  }
  if ((void *)in_ECX[0xf] != (void *)0x0) {
    operator_delete((void *)in_ECX[0xf]);
  }
  if ((void *)in_ECX[0xc] != (void *)0x0) {
    operator_delete((void *)in_ECX[0xc]);
  }
  if ((void *)in_ECX[9] != (void *)0x0) {
    operator_delete((void *)in_ECX[9]);
  }
  return;
}




/* cube::House::vfunc_0 @ 005aee10 */

void cube::House::vfunc_0(byte flags)

{
  void *self;
  
  ctor_1();
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return;
}




