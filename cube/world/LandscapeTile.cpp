// LandscapeTile (world) — cube. 1 functions. Bodies = Ghidra pseudo-C.
#include "LandscapeTile.h"

/* cube::LandscapeTile::vfunc_0 @ 005fbaa0 */

void cube::LandscapeTile::vfunc_0(byte flags)

{
  undefined4 *self;
  
  *self = vftable;
  if ((undefined4 *)self[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[0xb])(1);
  }
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return;
}




