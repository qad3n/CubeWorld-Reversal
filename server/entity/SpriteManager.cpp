// SpriteManager (entity) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "SpriteManager.h"

/* cube::SpriteManager::ctor_0 @ 00430e90 */

undefined4 * __thiscall cube::SpriteManager::ctor_0(SpriteManager *this,undefined4 owner)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = owner;
  return (undefined4 *)this;
}




/* cube::SpriteManager::ctor_1 @ 00430f00 */

void __fastcall cube::SpriteManager::ctor_1(undefined4 *self)

{
  undefined4 *sprite;
  uint security_cookie;
  int index;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054d46b;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  index = 0;
  local_8 = 0;
  if (0 < (int)(self[2] - self[1] & 0xfffffffc)) {
    do {
      sprite = *(undefined4 **)(self[1] + index * 4);
      if (sprite != (undefined4 *)0x0) {
        (**(code **)*sprite)(1,security_cookie);
      }
      index = index + 1;
    } while (index < (int)(self[2] - self[1]) >> 2);
  }
  if ((void *)self[1] != (void *)0x0) {
    operator_delete((void *)self[1]);
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
  }
  ExceptionList = local_10;
  return;
}




/* cube::SpriteManager::vfunc_0 @ 00431170 */

undefined4 * __thiscall cube::SpriteManager::vfunc_0(SpriteManager *this,byte delete_flag)

{
  ctor_1((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




