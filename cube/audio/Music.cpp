// Music (audio) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "Music.h"

/* cube::Music::ctor_0 @ 00622d60 */

void cube::Music::ctor_0(undefined4 param_1)

{
  undefined4 *self;
  
  self[0x78002] = param_1;
  *self = vftable;
  self[0x78003] = 0;
  self[0x78004] = 0;
  self[0x78005] = 0;
  self[0x78006] = 0x3f800000;
  return;
}




/* cube::Music::vfunc_0 @ 00623060 */

void cube::Music::vfunc_0(byte delete_flag)

{
  int *sub_obj;
  undefined4 *self;
  
  sub_obj = (int *)self[0x78003];
  *self = vftable;
  if (sub_obj != (int *)0x0) {
    (**(code **)(*sub_obj + 0x48))(sub_obj);
  }
  if ((delete_flag & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(self);
  }
  return;
}




