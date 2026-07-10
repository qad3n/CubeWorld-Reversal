// Field (world) — server. 2 functions. Bodies = Ghidra pseudo-C.
#include "Field.h"

/* cube::Field::ctor_0 @ 00413400 */

void __fastcall cube::Field::ctor_0(undefined4 *self)

{
  *self = vftable;
  if ((void *)self[6] != (void *)0x0) {
    operator_delete((void *)self[6]);
  }
  return;
}




/* cube::Field::vfunc_0 @ 00549170 */

undefined4 * __thiscall cube::Field::vfunc_0(Field *this,uint delete_flag)

{
  if ((delete_flag & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0x20,*(int *)(this + -4),ctor_0);
    if ((delete_flag & 1) != 0) {
      operator_delete__(this + -4);
    }
    return (undefined4 *)(this + -4);
  }
  ctor_0((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




