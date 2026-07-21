// Controller (control) — cube. 8 functions. Bodies = Ghidra pseudo-C.
#include "Controller.h"

/* cube::Controller::ctor_0 @ 0043b4c0 */

void cube::Controller::ctor_0(undefined4 owner)

{
  undefined4 *self;
  
  *self = vftable;
  self[0x49] = 0;
  self[0x4a] = 0;
  self[0x4b] = 0;
  self[0x4c] = 0;
  self[0x4d] = owner;
  memset((void *)((int)self + 0x19),0,0x100);
  *(undefined2 *)((int)self + 0x119) = 0;
  *(undefined1 *)((int)self + 0x11b) = 0;
  *(undefined8 *)(self + 1) = 0;
  *(undefined8 *)(self + 3) = 0;
  self[5] = 0;
  *(undefined1 *)(self + 6) = 0;
  return;
}




/* cube::Controller::ctor_1 @ 0043b540 */

void cube::Controller::ctor_1(void)

{
  undefined4 *self;
  
  *self = vftable;
  return;
}




/* cube::Controller::vfunc_0 @ 0043b550 */

void cube::Controller::vfunc_0(byte deleteFlag)

{
  undefined4 *self;
  
  *self = vftable;
  if ((deleteFlag & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(self);
  }
  return;
}




/* cube::Controller::vfunc_7 @ 0043b580 */

void cube::Controller::vfunc_7(int slot)

{
  int self;
  
  *(undefined1 *)(slot + 0x119 + self) = 1;
  return;
}




/* cube::Controller::vfunc_8 @ 0043b5a0 */

void cube::Controller::vfunc_8(int slot)

{
  int self;
  
  *(undefined1 *)(slot + 0x119 + self) = 0;
  return;
}




/* cube::Controller::vfunc_2 @ 0043b5c0 */

void cube::Controller::vfunc_2(byte slot)

{
  int self;
  
  *(undefined1 *)(slot + 0x19 + self) = 1;
  return;
}




/* cube::Controller::vfunc_3 @ 0043b5d0 */

void cube::Controller::vfunc_3(byte slot)

{
  int self;
  
  *(undefined1 *)(slot + 0x19 + self) = 0;
  return;
}




/* cube::Controller::vfunc_4 @ 00663b50 */

void cube::Controller::vfunc_4(void)

{
  return;
}




