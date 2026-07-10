// Sprite (entity) — server. 2 functions. Bodies = Ghidra pseudo-C.
#include "Sprite.h"

/* cube::Sprite::ctor_0 @ 0042ebb0 */

undefined4 * __thiscall cube::Sprite::ctor_0(Sprite *this,undefined4 owner)

{
  undefined4 str_obj;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d226;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  _eh_vector_constructor_iterator_(this + 4,0xc,3,lib_fn_4e1eb0,std_vector_free);
  local_8 = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  str_obj = std_map_makeHeader_0x1c();
  *(undefined4 *)(this + 0x28) = str_obj;
  *(undefined4 *)(this + 0x58) = owner;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined2 *)(this + 0x54) = 0x100;
  *(undefined2 *)(this + 0x5c) = 0;
  this[0x5e] = (Sprite)0x0;
  this[0x56] = (Sprite)0x0;
  ExceptionList = local_10;
  return (undefined4 *)this;
}




/* cube::Sprite::vfunc_0 @ 0042ef80 */

undefined4 * __thiscall cube::Sprite::vfunc_0(Sprite *this,byte delete_flag)

{
  undefined4 tmp;
  Sprite *self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054d266;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  local_8 = 0;
  self = this;
  if (*(void **)(this + 0x30) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x30));
  }
  std_map_eraseRange_SpriteNode(this + 0x28,&tmp,(int *)**(int **)(this + 0x28),*(int **)(this + 0x28));
  operator_delete(*(void **)(this + 0x28));
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(this + 4,0xc,3,std_vector_free);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}




