// SpriteManager (entity) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "SpriteManager.h"

/* cube::SpriteManager::ctor_0 @ 004ec0a0 */

void cube::SpriteManager::ctor_0(undefined4 world)

{
  undefined4 *self;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = world;
  return;
}




/* cube::SpriteManager::ctor_1 @ 004ec110 */

void cube::SpriteManager::ctor_1(void)

{
  undefined4 *sprite;
  uint cookie;
  undefined4 *self;
  int i;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006ea05b;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  i = 0;
  local_8 = 0;
  if (0 < (int)(self[2] - self[1] & 0xfffffffc)) {
    do {
      sprite = *(undefined4 **)(self[1] + i * 4);
      if (sprite != (undefined4 *)0x0) {
        (**(code **)*sprite)(1,cookie);
      }
      i = i + 1;
    } while (i < (int)(self[2] - self[1]) >> 2);
  }
  if ((void *)self[1] != (void *)0x0) {
    operator_delete((void *)self[1]);
  }
  ExceptionList = local_10;
  return;
}




/* cube::SpriteManager::vfunc_0 @ 004ec340 */

void cube::SpriteManager::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  ctor_1();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




