// VoxelWidget (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "VoxelWidget.h"

/* cube::VoxelWidget::ctor_0 @ 00587f70 */

void cube::VoxelWidget::ctor_0(undefined4 param_1,undefined4 param_2,int owner)

{
  undefined4 *self;
  undefined2 *voxelPtr;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f143c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,local_2c);
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  self[0x59] = 0xc2b40000;
  self[0x5a] = 0;
  self[0x5b] = 0x42b40000;
  self[0x5c] = 0;
  self[0x5d] = 0;
  self[0x5e] = 0;
  self[0x5f] = 0xffffffff;
  local_8._0_1_ = 3;
  *(undefined2 *)(self + 0x60) = 0;
  self[0x61] = 0;
  self[0x62] = 0;
  *(undefined2 *)(self + 99) = 0;
  *(undefined1 *)((int)self + 0x18e) = 0;
  *(undefined2 *)(self + 100) = 1;
  self[0xa5] = 0;
  memset(self + 0x65,0,0x100);
  self[0xa6] = owner;
  self[0xa7] = 0;
  self[0xa8] = 0;
  self[0xa9] = 0;
  *(undefined1 *)(self + 0xaa) = 0;
  self[0xab] = 0xffffffff;
  *(undefined2 *)(self + 0xac) = 0;
  self[0xad] = 0;
  self[0xae] = 0;
  *(undefined2 *)(self + 0xaf) = 0;
  *(undefined1 *)((int)self + 0x2be) = 0;
  *(undefined2 *)(self + 0xb0) = 1;
  self[0xf1] = 0;
  memset(self + 0xb1,0,0x100);
  *(undefined1 *)(self + 0xf2) = 0;
  self[0xf7] = 0;
  Sprite::ctor_0(*(undefined4 *)(owner + 0x134),0);
  local_8 = CONCAT31(local_8._1_3_,4);
  VoxelModel_allocate(1,1,1);
  if ((((int)self[0x109] < 1) || ((int)self[0x10a] < 1)) || ((int)self[0x10b] < 1)) {
    voxelPtr = (undefined2 *)&DAT_0076b340;
  }
  else {
    voxelPtr = (undefined2 *)self[0x104];
  }
  *voxelPtr = 0xffff;
  *(undefined1 *)(voxelPtr + 1) = 0xff;
  VoxelModel_build_mesh();
  ExceptionList = local_10;
  return;
}




/* cube::VoxelWidget::vfunc_0 @ 005881b0 */

void cube::VoxelWidget::vfunc_0(byte param_1)

{
  void *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f1476;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  Sprite::ctor_1(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  if (*(void **)((int)in_ECX + 0x170) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)((int)in_ECX + 0x170));
  }
  local_8 = 0xffffffff;
  plasma::Widget::ctor_0();
  if ((param_1 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(in_ECX);
  }
  ExceptionList = local_10;
  return;
}




