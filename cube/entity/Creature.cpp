// Creature (entity) — cube. 7 functions. Bodies = Ghidra pseudo-C.
#include "Creature.h"

/* [AUDIT] proposed: Creature_init  (confidence: med)
 * purpose: Zeroes a large Creature/entity struct (fields up to +0x223*4), sets base ptr at [0]
 * vars: param_1=owner ptr; ~0x224 dword slots
 */
/* Global::Creature_init @ 00411e50 */

void Creature_init(undefined4 owner)

{
  undefined4 *self;
  
  self[1] = 0;
  self[2] = 0;
  *self = owner;
  self[3] = 0;
  self[4] = 0;
  self[5] = 0;
  self[6] = 0;
  self[7] = 0;
  self[8] = 0;
  self[9] = 0;
  self[10] = 0;
  self[0xb] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0;
  self[0xf] = 0;
  self[0x10] = 0;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  self[0x1a] = 0;
  self[0x1b] = 0;
  self[0x1c] = 0;
  self[0x1d] = 0;
  self[0x1e] = 0;
  self[0x1f] = 0;
  self[0x20] = 0;
  self[0x21] = 0;
  self[0x22] = 0;
  self[0x23] = 0;
  self[0x24] = 0;
  self[0x25] = 0;
  self[0x26] = 0;
  self[0x27] = 0;
  self[0x28] = 0;
  self[0x29] = 0;
  self[0x2a] = 0;
  self[0x2b] = 0;
  self[0x2c] = 0;
  self[0x2d] = 0;
  self[0x2e] = 0;
  self[0x2f] = 0;
  self[0x31] = 0;
  self[0x32] = 0;
  self[0x33] = 0;
  self[0x34] = 0;
  self[0x35] = 0;
  self[0x36] = 0;
  self[0x37] = 0;
  self[0x39] = 0;
  self[0x3a] = 0;
  self[0x21b] = 0;
  self[0x21c] = 0;
  self[0x21d] = 0;
  *(undefined1 *)(self + 0x21e) = 0;
  self[0x220] = 0;
  self[0x221] = 0;
  self[0x222] = 0;
  self[0x223] = 0;
  return;
}




/* cube::Creature::ctor_0 @ 0043b690 */

void cube::Creature::ctor_0(undefined4 *entityId)

{
  uint cookie;
  undefined4 alloc;
  undefined4 *self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e2bb0;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[2] = *entityId;
  self[3] = entityId[1];
  Creature_init_43c100(cookie);
  self[0x45e] = 0;
  self[0x45f] = 0;
  alloc = list_allocNode32(0,0);
  self[0x45e] = alloc;
  self[0x460] = 0;
  self[0x461] = 0;
  self[0x462] = 0;
  self[0x463] = 0;
  self[0x464] = 0;
  self[0x465] = 0x3f800000;
  self[0x466] = 0x3f800000;
  self[0x467] = 0;
  local_8 = 0;
  self[0x46b] = 0;
  self[0x46c] = 0;
  alloc = rbtree_allocHead24();
  self[0x46b] = alloc;
  local_8._0_1_ = 1;
  self[0x46d] = 0;
  self[0x46e] = 0;
  alloc = rbtree_allocHead24();
  self[0x46d] = alloc;
  self[0x470] = 0;
  self[0x471] = 0;
  self[0x472] = 0;
  self[0x473] = 0;
  self[0x474] = 0;
  self[0x475] = 0;
  self[0x476] = 0;
  struct_initWithBuf();
  local_8._0_1_ = 3;
  self[0x4c3] = 0;
  self[0x4c4] = 0;
  alloc = list_allocNode0x134(0,0);
  self[0x4c3] = alloc;
  self[0x4c5] = 0;
  self[0x4c6] = 0;
  self[0x4d4] = 0;
  self[0x4d5] = 0;
  self[0x4d6] = 0;
  self[0x4d7] = 0;
  self[0x4d8] = 0;
  self[0x4d9] = 0;
  self[0x4dd] = 0;
  self[0x4de] = 0;
  self[0x4df] = 0;
  self[0x4e6] = 0;
  local_8._0_1_ = 4;
  self[0x4e7] = 0;
  self[0x4e8] = 0;
  alloc = rbtree_allocHead24();
  self[0x4e7] = alloc;
  local_8._0_1_ = 5;
  self[0x4e9] = 0;
  self[0x4ea] = 0;
  alloc = RBTree_allocSentinelNode();
  self[0x4e9] = alloc;
  local_8._0_1_ = 6;
  self[0x4eb] = 0;
  self[0x4ec] = 0;
  alloc = RBTree_allocSentinelNode();
  self[0x4eb] = alloc;
  self[0x4ed] = 0;
  *(undefined1 *)(self + 0x4ee) = 0;
  self[0x4ef] = 0;
  *(undefined1 *)(self + 0x4f0) = 0;
  self[0x4f1] = 0;
  self[0x4f2] = 0;
  self[0x4f3] = 0;
  self[0x4f4] = 0;
  self[0x4f5] = 0;
  self[0x4f6] = 0x3f800000;
  self[0x4f7] = 0;
  self[0x4f8] = 0;
  self[0x4f9] = 0;
  self[0x4fa] = 0;
  self[0x4fb] = 0;
  self[0x4fc] = 0;
  self[0x4fd] = 1;
  self[0x4fe] = 0;
  self[0x4ff] = 0;
  self[0x500] = 0;
  self[0x501] = 0;
  self[0x502] = 0;
  local_8._0_1_ = 9;
  self[0x503] = 0;
  self[0x504] = 0;
  alloc = std_list_alloc_sentinel_0x34();
  self[0x503] = alloc;
  local_8._0_1_ = 10;
  self[0x505] = 0;
  self[0x506] = 0;
  alloc = rbtree_allocHeaderNode_1c();
  self[0x505] = alloc;
  self[0x507] = 0xffffffff;
  self[0x508] = 0xffffffff;
  self[0x509] = 0xffffffff;
  self[0x516] = 0;
  self[0x517] = 0;
  local_8._0_1_ = 0xb;
  self[0x518] = 0;
  self[0x519] = 0;
  alloc = list_allocNode20(0,0);
  self[0x518] = alloc;
  local_8._0_1_ = 0xc;
  self[0x51a] = 0;
  self[0x51b] = 0;
  alloc = std_Tree_allocHeadSentinel();
  self[0x51a] = alloc;
  local_8._0_1_ = 0xd;
  self[0x51c] = 0;
  self[0x51d] = 0;
  alloc = list_allocNode20(0,0);
  self[0x51c] = alloc;
  self[0x51e] = 0xffffffff;
  self[0x51f] = 0xffffffff;
  self[0x520] = 0;
  self[0x521] = 0;
  self[0x522] = 0;
  self[0x523] = 0;
  self[0x524] = 0;
  self[0x525] = 0;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  Creature_init(self);
  self[0x74a] = 0;
  self[0x74b] = 0x43480000;
  *(undefined1 *)(self + 0x74e) = 0;
  self[0x74f] = 1;
  self[0x750] = 0;
  self[0x751] = 0;
  *(undefined2 *)(self + 0x756) = 1;
  *(undefined2 *)(self + 0x752) = 0;
  self[0x753] = 0;
  self[0x754] = 0;
  *(undefined2 *)(self + 0x755) = 0;
  *(undefined1 *)((int)self + 0x1d56) = 0;
  self[0x797] = 0;
  memset(self + 0x757,0,0x100);
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: Creature::init  (confidence: med)
 * purpose: Zero-inits large Creature struct with float defaults (0x43fa0000,0x42c80000,1.0 scales); calls 0043bc00 sub-init
 * vars: floats at +0x57,0x5a-0x5e; memset blocks
 */
/* Global::Creature_init_43c100 @ 0043c100 */

void Creature_init_43c100(void)

{
  undefined4 *self;
  
  *self = 0;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
  self[5] = 0;
  self[6] = 0;
  self[7] = 0;
  self[8] = 0;
  self[9] = 0;
  self[10] = 0;
  self[0xb] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0;
  self[0xf] = 0;
  self[0x10] = 0;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  *(undefined1 *)(self + 0x14) = 3;
  self[0x15] = 0;
  *(undefined1 *)(self + 0x16) = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  Spawn_initDefaults();
  *(undefined2 *)(self + 0x45) = 0;
  self[0x46] = 0;
  self[0x48] = 0;
  self[0x49] = 0;
  self[0x4a] = 0;
  self[0x4b] = 0;
  *(undefined2 *)(self + 0x4c) = 0;
  self[0x4d] = 0;
  self[0x47] = 0xfffff448;
  self[0x4e] = 0;
  self[0x4f] = 0;
  self[0x50] = 0;
  self[0x51] = 0;
  self[0x52] = 0;
  self[0x53] = 0;
  self[0x54] = 0;
  self[0x55] = 0;
  self[0x56] = 0;
  self[0x58] = 0;
  self[0x59] = 0;
  self[0x57] = 0x43fa0000;
  self[0x5a] = 0x42c80000;
  self[0x5b] = 0x3f800000;
  self[0x5c] = 0x3f800000;
  self[0x5d] = 0x3f800000;
  self[0x5e] = 0x3f800000;
  *(undefined2 *)(self + 0x5f) = 0;
  self[0x61] = 0;
  self[0x62] = 0;
  self[99] = 0;
  self[100] = 0;
  self[0x65] = 0;
  *(undefined1 *)(self + 0x66) = 0;
  self[0x60] = 1;
  self[0x67] = 0xffffffff;
  self[0x6a] = 0;
  self[0x68] = 0xffffffff;
  self[0x69] = 0xffffffff;
  *(undefined1 *)(self + 0x72) = 0;
  self[0x75] = 0;
  self[0x73] = 0xffffffff;
  self[0x74] = 0xffffffff;
  *(undefined2 *)(self + 0x76) = 0;
  self[0x77] = 0;
  self[0x78] = 0;
  *(undefined2 *)(self + 0x79) = 0;
  *(undefined1 *)((int)self + 0x1e6) = 0;
  *(undefined2 *)(self + 0x7a) = 1;
  self[0xbb] = 0;
  memset(self + 0x7b,0,0x100);
  Spawn_initNameArrays();
  self[0x455] = 0;
  *(undefined8 *)(self + 0x456) = 0;
  *(undefined8 *)(self + 0x458) = 0;
  memset(self + 0x44a,0,0x2c);
  return;
}




/* cube::Creature::ctor_1 @ 0043c410 */

void cube::Creature::ctor_1(void)

{
  void *node;
  undefined4 *listHead;
  undefined4 *self;
  
  *self = vftable;
  if ((void *)self[0x4f9] != (void *)0x0) {
    operator_delete((void *)self[0x4f9]);
  }
  node = (void *)self[0x74a];
  if (node != (void *)0x0) {
    Creature_partialDtor();
    operator_delete(node);
  }
  if ((void *)self[0x523] != (void *)0x0) {
    operator_delete((void *)self[0x523]);
  }
  listHead = (undefined4 *)self[0x51c];
  node = (void *)*listHead;
  *listHead = listHead;
  *(undefined4 *)(self[0x51c] + 4) = self[0x51c];
  self[0x51d] = 0;
  if (node != (void *)self[0x51c]) {
    operator_delete(node);
  }
  operator_delete((void *)self[0x51c]);
}




/* [AUDIT] proposed: Creature::partialDtor  (confidence: med)
 * purpose: Frees SSO string at +0x28 (cap>0xf) then RB-tree range 0043f040 at +0x1c, deletes buffer
 * vars: +0x3c cap; +0x1c tree
 */
/* Global::Creature_partialDtor @ 0043c790 */

void Creature_partialDtor(void)

{
  int self;
  undefined1 tmp [4];
  
  if (0xf < *(uint *)(self + 0x3c)) {
    operator_delete(*(void **)(self + 0x28));
  }
  *(undefined4 *)(self + 0x3c) = 0xf;
  *(undefined4 *)(self + 0x38) = 0;
  *(undefined1 *)(self + 0x28) = 0;
  rbtree_eraseRange_str(tmp,**(undefined4 **)(self + 0x1c),*(undefined4 **)(self + 0x1c));
  operator_delete(*(void **)(self + 0x1c));
}




/* cube::Creature::vfunc_0 @ 0043c840 */

void cube::Creature::vfunc_0(byte deleteFlag)

{
  void *self;
  
  ctor_1();
  if ((deleteFlag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




/* [AUDIT] proposed: list::allocNode0x134  (confidence: high)
 * purpose: operator_new(0x134) self-linked node (Creature-sized list node); _Xbad_alloc on fail
 * vars: 0x134 node
 */
/* Global::list_allocNode0x134 @ 0043c8a0 */

void list_allocNode0x134(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x134);
  if (node != (void *)0x0) {
    if (prev == (void *)0x0) {
      prev = node;
      next = node;
    }
    *node = prev;
    if (node + 1 != (undefined4 *)0x0) {
      node[1] = next;
    }
    return;
  }
  std::_Xbad_alloc();
}




