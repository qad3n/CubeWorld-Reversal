// Spawn (world) — cube. 5 functions. Bodies = Ghidra pseudo-C.
#include "Spawn.h"

/* [AUDIT] proposed: Spawn_initDefaults  (confidence: med)
 * purpose: Initializes a Spawn/creature-appearance struct with default color/scale/offset float constants
 * vars: many 0x3f8/color float consts
 */
/* Global::Spawn_initDefaults @ 00428750 */

void Spawn_initDefaults(void)

{
  undefined4 *self;
  
  *self = 0xffff0000;
  *(undefined1 *)(self + 1) = 0xff;
  *(undefined2 *)((int)self + 6) = 0;
  self[2] = 0x3f800000;
  self[3] = 0x3f800000;
  self[4] = 0x3f800000;
  self[9] = 0x3f8147ae;
  self[10] = 0x3f800000;
  self[0xb] = 0x3f800000;
  self[0xc] = 0x3f7ae148;
  self[0xd] = 0x3f800000;
  self[0xe] = 0x3f733333;
  self[0xf] = 0x3f4ccccd;
  self[0x10] = 0x3f800000;
  self[0x11] = 0x3f800000;
  self[0x12] = 0;
  *(undefined2 *)(self + 5) = 0xffff;
  *(undefined2 *)((int)self + 0x16) = 0xffff;
  *(undefined2 *)(self + 6) = 0xffff;
  *(undefined2 *)((int)self + 0x1a) = 0xffff;
  *(undefined2 *)(self + 7) = 0xffff;
  *(undefined2 *)((int)self + 0x1e) = 0xffff;
  *(undefined2 *)(self + 8) = 0xffff;
  *(undefined2 *)((int)self + 0x22) = 0xffff;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  self[0x1a] = 0;
  self[0x1b] = 0xc0a00000;
  self[0x1c] = 0;
  self[0x1d] = 0x3f000000;
  self[0x1e] = 0x40a00000;
  self[0x1f] = 0x40c00000;
  self[0x20] = 0;
  self[0x21] = 0;
  self[0x22] = 0x40400000;
  self[0x23] = 0x3f800000;
  self[0x24] = 0xc1280000;
  self[0x25] = 0;
  self[0x26] = 0xc1000000;
  self[0x27] = 0x40000000;
  self[0x28] = 0;
  self[0x29] = 0;
  self[0x2a] = 0;
  return;
}




/* [AUDIT] proposed: Spawn::initNameArrays  (confidence: med)
 * purpose: Zero-inits Spawn struct with ~14 repeated 0x100 memset blocks + string-slot headers (NPC name/attr arrays)
 * vars: repeated 0x100 memset, cap short=1
 */
/* Global::Spawn_initNameArrays @ 0043bc00 */

void Spawn_initNameArrays(void)

{
  undefined2 *self;
  
  *self = 0;
  *(undefined4 *)(self + 2) = 0;
  *(undefined4 *)(self + 4) = 0;
  self[6] = 0;
  *(undefined1 *)(self + 7) = 0;
  self[8] = 1;
  *(undefined4 *)(self + 0x8a) = 0;
  memset(self + 10,0,0x100);
  self[0x8c] = 0;
  *(undefined4 *)(self + 0x8e) = 0;
  *(undefined4 *)(self + 0x90) = 0;
  self[0x92] = 0;
  *(undefined1 *)(self + 0x93) = 0;
  self[0x94] = 1;
  *(undefined4 *)(self + 0x116) = 0;
  memset(self + 0x96,0,0x100);
  self[0x118] = 0;
  *(undefined4 *)(self + 0x11a) = 0;
  *(undefined4 *)(self + 0x11c) = 0;
  self[0x11e] = 0;
  *(undefined1 *)(self + 0x11f) = 0;
  self[0x120] = 1;
  *(undefined4 *)(self + 0x1a2) = 0;
  memset(self + 0x122,0,0x100);
  self[0x1a4] = 0;
  *(undefined4 *)(self + 0x1a6) = 0;
  *(undefined4 *)(self + 0x1a8) = 0;
  self[0x1aa] = 0;
  *(undefined1 *)(self + 0x1ab) = 0;
  self[0x1ac] = 1;
  *(undefined4 *)(self + 0x22e) = 0;
  memset(self + 0x1ae,0,0x100);
  self[0x230] = 0;
  *(undefined4 *)(self + 0x232) = 0;
  *(undefined4 *)(self + 0x234) = 0;
  self[0x236] = 0;
  *(undefined1 *)(self + 0x237) = 0;
  self[0x238] = 1;
  *(undefined4 *)(self + 0x2ba) = 0;
  memset(self + 0x23a,0,0x100);
  self[700] = 0;
  *(undefined4 *)(self + 0x2be) = 0;
  *(undefined4 *)(self + 0x2c0) = 0;
  self[0x2c2] = 0;
  *(undefined1 *)(self + 0x2c3) = 0;
  self[0x2c4] = 1;
  *(undefined4 *)(self + 0x346) = 0;
  memset(self + 0x2c6,0,0x100);
  self[0x348] = 0;
  *(undefined4 *)(self + 0x34a) = 0;
  *(undefined4 *)(self + 0x34c) = 0;
  self[0x34e] = 0;
  *(undefined1 *)(self + 0x34f) = 0;
  self[0x350] = 1;
  *(undefined4 *)(self + 0x3d2) = 0;
  memset(self + 0x352,0,0x100);
  self[0x3d4] = 0;
  *(undefined4 *)(self + 0x3d6) = 0;
  *(undefined4 *)(self + 0x3d8) = 0;
  self[0x3da] = 0;
  *(undefined1 *)(self + 0x3db) = 0;
  self[0x3dc] = 1;
  *(undefined4 *)(self + 0x45e) = 0;
  memset(self + 0x3de,0,0x100);
  self[0x460] = 0;
  *(undefined4 *)(self + 0x462) = 0;
  *(undefined4 *)(self + 0x464) = 0;
  self[0x466] = 0;
  *(undefined1 *)(self + 0x467) = 0;
  self[0x468] = 1;
  *(undefined4 *)(self + 0x4ea) = 0;
  memset(self + 0x46a,0,0x100);
  self[0x4ec] = 0;
  *(undefined4 *)(self + 0x4ee) = 0;
  *(undefined4 *)(self + 0x4f0) = 0;
  self[0x4f2] = 0;
  *(undefined1 *)(self + 0x4f3) = 0;
  self[0x4f4] = 1;
  *(undefined4 *)(self + 0x576) = 0;
  memset(self + 0x4f6,0,0x100);
  self[0x578] = 0;
  *(undefined4 *)(self + 0x57a) = 0;
  *(undefined4 *)(self + 0x57c) = 0;
  self[0x57e] = 0;
  *(undefined1 *)(self + 0x57f) = 0;
  self[0x580] = 1;
  *(undefined4 *)(self + 0x602) = 0;
  memset(self + 0x582,0,0x100);
  self[0x604] = 0;
  *(undefined4 *)(self + 0x606) = 0;
  *(undefined4 *)(self + 0x608) = 0;
  self[0x60a] = 0;
  *(undefined1 *)(self + 0x60b) = 0;
  self[0x60c] = 1;
  *(undefined4 *)(self + 0x68e) = 0;
  memset(self + 0x60e,0,0x100);
  self[0x690] = 0;
  *(undefined4 *)(self + 0x692) = 0;
  *(undefined4 *)(self + 0x694) = 0;
  self[0x696] = 0;
  *(undefined1 *)(self + 0x697) = 0;
  self[0x698] = 1;
  *(undefined4 *)(self + 0x71a) = 0;
  memset(self + 0x69a,0,0x100);
  return;
}




/* cube::Spawn::ctor_0 @ 005adb20 */

void cube::Spawn::ctor_0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  in_ECX[2] = 0x43480000;
  in_ECX[10] = 1;
  in_ECX[0xb] = 4;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  in_ECX[0xd] = 1;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x16) = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0xffffffff;
  in_ECX[0x19] = 0xffffffff;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0xffffffff;
  in_ECX[0x1c] = 0;
  Spawn_initDefaults();
  Spawn_initNameArrays();
  in_ECX[0x3d6] = 0x42c80000;
  in_ECX[0x3d7] = 0x3f800000;
  in_ECX[0x3d8] = 0x3f800000;
  in_ECX[0x3d9] = 0x3f800000;
  in_ECX[0x3da] = 0x3f800000;
  struct_initWithBuf();
  in_ECX[0x427] = 0;
  in_ECX[0x428] = 0;
  in_ECX[0x429] = 0;
  in_ECX[0x42a] = 0;
  in_ECX[0x42b] = 0;
  in_ECX[0x42c] = 0;
  in_ECX[0x42d] = 0;
  in_ECX[0x42e] = 0;
  in_ECX[0x42f] = 0;
  in_ECX[0x430] = 0;
  in_ECX[0x431] = 0;
  in_ECX[0x432] = 0xffffffff;
  in_ECX[0x438] = 0;
  in_ECX[0x439] = 0;
  *(undefined1 *)(in_ECX + 0x43a) = 0;
  *(undefined1 *)(in_ECX + 0x433) = 0;
  return;
}




/* cube::Spawn::ctor_1 @ 005adca0 */

void cube::Spawn::ctor_1(void)

{
  undefined4 *in_ECX;
  undefined1 local_5;
  
  *in_ECX = vftable;
  if ((void *)in_ECX[0x427] != (void *)0x0) {
    operator_delete((void *)in_ECX[0x427]);
  }
  if ((void *)in_ECX[0x42f] != (void *)0x0) {
    operator_delete((void *)in_ECX[0x42f]);
  }
  if ((void *)in_ECX[0x42b] != (void *)0x0) {
    operator_delete((void *)in_ECX[0x42b]);
  }
  if ((void *)in_ECX[0x428] != (void *)0x0) {
    operator_delete((void *)in_ECX[0x428]);
  }
  if (in_ECX[0x3db] != 0) {
    std_vector_destroy_ptr_elems_stride3(in_ECX[0x3db],in_ECX[0x3dc],&local_5);
    operator_delete((void *)in_ECX[0x3db]);
  }
  return;
}




/* cube::Spawn::vfunc_0 @ 005addb0 */

void cube::Spawn::vfunc_0(byte flags)

{
  void *self;
  
  ctor_1();
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return;
}




