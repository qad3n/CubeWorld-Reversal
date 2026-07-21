// Field (world) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "Field.h"

/* cube::Field::ctor_0 @ 00450c30 */

void cube::Field::ctor_0(void)

{
  undefined4 *self;
  
  *self = vftable;
  if ((void *)self[6] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[6]);
  }
  return;
}




/* cube::Field::vfunc_0 @ 00624700 */

void * cube::Field::vfunc_0(uint flags)

{
  void *self;
  
  if ((flags & 2) != 0) {
    _eh_vector_destructor_iterator_(self,0x20,*(int *)((int)self + -4),ctor_0);
    if ((flags & 1) != 0) {
      operator_delete__((void *)((int)self + -4));
    }
    return (void *)((int)self + -4);
  }
  ctor_0();
  if ((flags & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(self);
  }
  return self;
}




