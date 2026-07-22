// ZoneTile (world) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "ZoneTile.h"

/* cube::ZoneTile::ctor_1 @ 005fb7f0 */

void cube::ZoneTile::ctor_1(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 1;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  uVar1 = list_allocNode20(0,0);
  in_ECX[8] = uVar1;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  return;
}




/* cube::ZoneTile::ctor_0 @ 005fb960 */

void cube::ZoneTile::ctor_0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  undefined4 *self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f4a0b;
  local_10 = ExceptionList;
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  if ((undefined4 *)self[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[2])(1,uVar3);
  }
  puVar1 = (undefined4 *)self[8];
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(self[8] + 4) = self[8];
  self[9] = 0;
  if (pvVar2 != (void *)self[8]) {
    operator_delete(pvVar2);
  }
  operator_delete((void *)self[8]);
}




/* cube::ZoneTile::vfunc_0 @ 005fbb00 */

void cube::ZoneTile::vfunc_0(byte flags)

{
  void *self;
  
  ctor_0();
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return;
}




