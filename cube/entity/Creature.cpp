// Creature (entity) — cube. 10 functions. Bodies = Ghidra pseudo-C.
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




/* cube::Creature::ctor_1 @ 0043c410 */

void cube::Creature::ctor_1(void)

{
  void *node;
  undefined4 *listHead;
  undefined4 *self;
  
  *self = vftable;
  if ((void *)self[0x4f9] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x4f9]);
  }
  node = (void *)self[0x74a];
  if (node != (void *)0x0) {
    Creature_partialDtor();
                    /* WARNING: Subroutine does not return */
    operator_delete(node);
  }
  if ((void *)self[0x523] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)self[0x523]);
  }
  listHead = (undefined4 *)self[0x51c];
  node = (void *)*listHead;
  *listHead = listHead;
  *(undefined4 *)(self[0x51c] + 4) = self[0x51c];
  self[0x51d] = 0;
  if (node != (void *)self[0x51c]) {
                    /* WARNING: Subroutine does not return */
    operator_delete(node);
  }
                    /* WARNING: Subroutine does not return */
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
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(self + 0x28));
  }
  *(undefined4 *)(self + 0x3c) = 0xf;
  *(undefined4 *)(self + 0x38) = 0;
  *(undefined1 *)(self + 0x28) = 0;
  rbtree_eraseRange_str(tmp,**(undefined4 **)(self + 0x1c),*(undefined4 **)(self + 0x1c));
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(self + 0x1c));
}




/* cube::Creature::vfunc_0 @ 0043c840 */

void cube::Creature::vfunc_0(byte deleteFlag)

{
  void *self;
  
  ctor_1();
  if ((deleteFlag & 1) != 0) {
                    /* WARNING: Subroutine does not return */
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
                    /* WARNING: Subroutine does not return */
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: Player::resetFull  (confidence: med)
 * purpose: Full player/controller reset: destroys/reinits all containers, timers, transforms, buffers
 * vars: many +0x11xx/+0x13xx members
 */
/* Global::Player_resetFull @ 00446330 */

void Player_resetFull(void)

{
  undefined4 *listHead;
  void *node;
  int self;
  undefined4 local_9;
  undefined1 local_5;
  
  Player_resetState();
  if (*(void **)(self + 0x13e4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(self + 0x13e4));
  }
  *(undefined4 *)(self + 0x1d40) = 0;
  *(undefined4 *)(self + 0x1d3c) = 1;
  *(undefined4 *)(self + 0x11c0) = 0;
  *(undefined4 *)(self + 0x11c4) = 0;
  *(undefined4 *)(self + 0x11d0) = 0;
  *(undefined4 *)(self + 0x11d4) = 0;
  *(undefined4 *)(self + 0x11c8) = 0;
  *(undefined4 *)(self + 0x11cc) = 0;
  *(undefined4 *)(self + 0x1314) = 0;
  *(undefined4 *)(self + 0x1318) = 0;
  listHead = *(undefined4 **)(self + 0x130c);
  node = (void *)*listHead;
  *listHead = listHead;
  *(int *)(*(int *)(self + 0x130c) + 4) = *(int *)(self + 0x130c);
  *(undefined4 *)(self + 0x1310) = 0;
  if (node != *(void **)(self + 0x130c)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(node);
  }
  std_list_clear_67e480();
  std_list_clear_67e480();
  std_list_clear_67e480();
  *(undefined4 *)(self + 0x13cc) = 0;
  *(undefined4 *)(self + 0x13c8) = 0;
  *(undefined4 *)(self + 0x13d0) = 0;
  *(undefined4 *)(self + 0x13e0) = 0;
  *(undefined4 *)(self + 0x1184) = 0;
  *(undefined4 *)(self + 0x1190) = 0;
  *(undefined4 *)(self + 0x1194) = 0x3f800000;
  *(undefined4 *)(self + 0x1398) = 0;
  *(undefined4 *)(self + 0x118c) = 0;
  *(undefined4 *)(self + 0x1188) = 0;
  *(undefined4 *)(self + 0x13bc) = 0;
  *(undefined4 *)(self + 0x11d8) = 0;
  *(undefined4 *)(self + 0x13b4) = 0;
  *(undefined1 *)(self + 0x13c0) = 0;
  *(undefined4 *)(self + 0x1404) = 0;
  std_vector_destroy_ptr_elems_stride3(*(undefined4 *)(self + 0x11dc),*(undefined4 *)(self + 0x11e0),&local_5,local_9);
  *(undefined4 *)(self + 0x11e0) = *(undefined4 *)(self + 0x11dc);
  GameController_clearContainers();
  *(undefined4 *)(self + 0x1478) = 0xffffffff;
  *(undefined4 *)(self + 0x147c) = 0xffffffff;
  *(undefined4 *)(self + 0x1480) = 0;
  listHead = *(undefined4 **)(self + 0x1470);
  node = (void *)*listHead;
  *listHead = listHead;
  *(int *)(*(int *)(self + 0x1470) + 4) = *(int *)(self + 0x1470);
  *(undefined4 *)(self + 0x1474) = 0;
  if (node != *(void **)(self + 0x1470)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(node);
  }
  *(undefined4 *)(self + 0x1484) = 0;
  *(undefined4 *)(self + 0x1488) = 0;
  *(undefined4 *)(self + 0x141c) = 0xffffffff;
  *(undefined4 *)(self + 0x1420) = 0xffffffff;
  *(undefined4 *)(self + 0x1424) = 0xffffffff;
  *(undefined4 *)(self + 0x1458) = 0;
  *(undefined4 *)(self + 0x1490) = *(undefined4 *)(self + 0x148c);
  listHead = *(undefined4 **)(self + 0x1178);
  node = (void *)*listHead;
  *listHead = listHead;
  *(int *)(*(int *)(self + 0x1178) + 4) = *(int *)(self + 0x1178);
  *(undefined4 *)(self + 0x117c) = 0;
  if (node != *(void **)(self + 0x1178)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(node);
  }
  return;
}




/* [AUDIT] proposed: Player::resetState  (confidence: med)
 * purpose: Resets player physics/stat members and memsets large regions (+0x2f0 0xe38, +0x1128)
 * vars: memset 0xe38; +0x180 base
 */
/* Global::Player_resetState @ 004465c0 */

void Player_resetState(void)

{
  uint cookie;
  undefined4 hpTable;
  int self;
  
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(self + 0x180) = 1;
  *(undefined4 *)(self + 0x184) = 0;
  *(undefined4 *)(self + 0x24) = 0;
  *(undefined4 *)(self + 0x28) = 0;
  *(undefined4 *)(self + 0x2c) = 0;
  *(undefined4 *)(self + 0x30) = 0;
  *(undefined4 *)(self + 0x34) = 0;
  *(undefined4 *)(self + 0x38) = 0;
  *(undefined4 *)(self + 0x3c) = 0;
  *(undefined4 *)(self + 0x40) = 0;
  *(undefined4 *)(self + 0x44) = 0;
  *(undefined4 *)(self + 0x168) = 0x42c80000;
  *(undefined4 *)(self + 0x170) = 0x3f800000;
  *(undefined4 *)(self + 0x16c) = 0x3f800000;
  *(undefined1 *)(self + 0x58) = 0;
  *(undefined4 *)(self + 0x5c) = 0;
  *(undefined4 *)(self + 0x11c) = 0xfffff448;
  *(undefined4 *)(self + 0x120) = 0;
  *(undefined4 *)(self + 0x124) = 0;
  *(undefined4 *)(self + 0x128) = 0;
  *(undefined4 *)(self + 300) = 0;
  memset((void *)(self + 0x2f0),0,0xe38);
  *(undefined2 *)(self + 0x114) = 0;
  *(undefined2 *)(self + 0x17c) = 0;
  *(undefined4 *)(self + 0x60) = 0;
  *(undefined4 *)(self + 100) = 0;
  *(undefined4 *)(self + 0x134) = 0;
  *(undefined4 *)(self + 0x160) = 0;
  *(undefined4 *)(self + 0x164) = 0;
  *(undefined4 *)(self + 0x188) = 0;
  *(undefined4 *)(self + 0x18c) = 0;
  *(undefined4 *)(self + 400) = 0;
  *(undefined4 *)(self + 0x194) = 0;
  *(undefined1 *)(self + 0x198) = 0;
  *(undefined4 *)(self + 0x138) = 0;
  *(undefined4 *)(self + 0x13c) = 0;
  *(undefined4 *)(self + 0x140) = 0;
  *(undefined4 *)(self + 0x144) = 0;
  *(undefined4 *)(self + 0x148) = 0;
  *(undefined4 *)(self + 0x14c) = 0;
  *(undefined4 *)(self + 0x1a0) = 0xffffffff;
  *(undefined4 *)(self + 0x1a4) = 0xffffffff;
  *(undefined4 *)(self + 0x1a8) = 0;
  *(undefined4 *)(self + 0x1cc) = 0xffffffff;
  *(undefined4 *)(self + 0x1d0) = 0xffffffff;
  *(undefined4 *)(self + 0x1d4) = 0;
  *(undefined1 *)(self + 0x1c8) = 0;
  *(undefined2 *)(self + 0x130) = 0;
  hpTable = Spawn_initDefaults();
  Struct_copy_acBytes(hpTable);
  *(undefined8 *)(self + 0x1158) = 0;
  *(undefined8 *)(self + 0x1160) = 0;
  memset((void *)(self + 0x1128),0,0x2c);
  *(undefined4 *)(self + 0x1154) = 0;
  __security_check_cookie(cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: list::makeNodeWrapper  (confidence: low)
 * purpose: Creates list node via 0044b770 then inits payload 0040ee70 unless error (-8)
 * vars: -
 */
/* Global::list_makeNodeWrapper @ 00449b70 */

int list_makeNodeWrapper(undefined4 list,undefined4 head,undefined4 extra)

{
  int result;
  
  result = allocNode_0x120(list,head);
  if (result != -8) {
    entityState_copy(extra);
  }
  return result;
}




/* [AUDIT] proposed: GameWorld::deserialize_state  (confidence: low)
 * purpose: deserialize world/entity state from packet buffer (game, big)
 * vars: list=world
 */
/* cube::Creature::deserializeState @ 0044be40 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::Creature::deserializeState.
 * Player_resetFull(this); rebuilds this+0x1d28 ObjWithListMap; reads stream cursor in_ECX (ptr[1]-ptr[0] bounds, ptr[3] pos) into pos +0x10/+0x18/+0x20, kind +0x60=0, level +0x190, +0x16c/+0x194; callees Creature 43c100/43c790, Spawn 43bc00, GameController 44a7e0/44b040, WorldInfo 44b460. Body deserializes game state.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void cube::Creature::deserializeState(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 *puVar7;
  int ***pppiVar8;
  undefined4 *puVar9;
  int *in_ECX;
  int *piVar10;
  int iVar11;
  size_t sVar12;
  undefined1 local_1325;
  int *local_1324;
  int local_1320;
  int *local_131c;
  int ***local_1318;
  size_t local_1314;
  void *local_1a8;
  undefined4 local_1a4;
  undefined2 local_190 [2];
  undefined4 local_18c;
  undefined4 local_188;
  undefined2 local_184;
  undefined1 local_182;
  undefined2 local_180;
  undefined1 local_17c [256];
  undefined4 local_7c;
  undefined1 local_78 [4];
  void *local_74;
  uint local_60;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  int ***local_44 [4];
  undefined4 local_34;
  uint local_30;
  undefined4 ***local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e2e1f;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1320 = param_1;
  Player_resetFull(local_14);
  pvVar1 = *(void **)(param_1 + 0x1d28);
  if (pvVar1 != (void *)0x0) {
    Creature_partialDtor();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  local_1318 = operator_new(0x40);
  local_8 = 0;
  if (local_1318 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = ctor_ObjWithListMap();
  }
  *(undefined4 *)(param_1 + 0x1d28) = uVar5;
  uVar5 = Spawn_initNameArrays();
  dtor_13Strings_0x118(uVar5);
  iVar6 = struct_initWithBuf();
  local_1324 = (int *)(param_1 + 0x11dc);
  local_8 = 1;
  vector_assignFrom_0xc(iVar6);
  *(undefined4 *)(param_1 + 0x11e8) = *(undefined4 *)(iVar6 + 0xc);
  Item_copyStruct(iVar6 + 0x10);
  local_8 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1304) = *(undefined4 *)(iVar6 + 0x128);
  *(undefined4 *)(param_1 + 0x1308) = *(undefined4 *)(iVar6 + 300);
  if (local_1a8 == (void *)0x0) {
    std_vector_resize_12(4);
    uVar5 = Creature_init_43c100();
    copyCtor_EntityLike(uVar5);
    *(undefined1 *)(param_1 + 0x60) = 0;
    piVar2 = (int *)*in_ECX;
    if (piVar2[1] - *piVar2 < piVar2[3] + 4) {
      piVar2[3] = piVar2[1] - *piVar2;
    }
    else {
      in_ECX[2] = *(int *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    if (piVar2[1] - *piVar2 < piVar2[3] + 0x18) {
      piVar2[3] = piVar2[1] - *piVar2;
    }
    else {
      iVar6 = *piVar2;
      iVar11 = piVar2[3];
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(iVar11 + iVar6);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(iVar11 + 8 + iVar6);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(iVar11 + 0x10 + iVar6);
      piVar2[3] = piVar2[3] + 0x18;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = *piVar2;
    if (piVar2[1] - iVar6 < piVar2[3] + 0xc) {
      piVar2[3] = piVar2[1] - iVar6;
    }
    else {
      iVar11 = piVar2[3];
      *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(iVar11 + iVar6);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar11 + 8 + iVar6);
      piVar2[3] = piVar2[3] + 0xc;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(param_1 + 400) = *(undefined4 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 1) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined1 *)(param_1 + 0x140) = *(undefined1 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 1;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 1) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined1 *)(param_1 + 0x141) = *(undefined1 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 1;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(param_1 + 0x1198) = *(undefined4 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(param_1 + 0x119c) = *(undefined4 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x300),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x418),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x530),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x648),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x760),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x878),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x990),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0xaa8),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0xbc0),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0xcd8),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0xdf0),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0xf08),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 0x118) {
      piVar2[3] = iVar6;
    }
    else {
      memcpy((void *)(param_1 + 0x1020),(void *)(piVar2[3] + *piVar2),0x118);
      piVar2[3] = piVar2[3] + 0x118;
    }
    iVar6 = local_1320;
    piVar2 = (int *)*in_ECX;
    iVar11 = piVar2[1] - *piVar2;
    local_1314 = 0;
    if (iVar11 < piVar2[3] + 4) {
      piVar2[3] = iVar11;
    }
    else {
      local_1314 = *(size_t *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    if (piVar2[1] - *piVar2 < (int)(piVar2[3] + local_1314)) {
      piVar2[3] = piVar2[1] - *piVar2;
    }
    else {
      memcpy((void *)(local_1320 + 0x1168),(void *)(*piVar2 + piVar2[3]),local_1314);
      piVar2[3] = piVar2[3] + local_1314;
    }
    *(undefined1 *)(iVar6 + 0x1168 + local_1314) = 0;
    pvVar1 = *(void **)(iVar6 + 0x1d28);
    if (pvVar1 != (void *)0x0) {
      Creature_partialDtor();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    local_1318 = operator_new(0x40);
    local_8 = 2;
    if ((int ****)local_1318 == (int ****)0x0) {
      puVar7 = (undefined8 *)0x0;
    }
    else {
      puVar7 = (undefined8 *)ctor_ObjWithListMap();
    }
    *(undefined8 **)(iVar6 + 0x1d28) = puVar7;
    piVar2 = (int *)*in_ECX;
    local_8 = 0xffffffff;
    if (piVar2[1] - *piVar2 < piVar2[3] + 0x14) {
      piVar2[3] = piVar2[1] - *piVar2;
    }
    else {
      iVar11 = *piVar2;
      iVar3 = piVar2[3];
      *puVar7 = *(undefined8 *)(iVar3 + iVar11);
      puVar7[1] = *(undefined8 *)(iVar3 + 8 + iVar11);
      *(undefined4 *)(puVar7 + 2) = *(undefined4 *)(iVar3 + 0x10 + iVar11);
      piVar2[3] = piVar2[3] + 0x14;
    }
    creature_generateAppearance(iVar6 + 100,iVar6 + 0x78,*(undefined4 *)(iVar6 + 0x1d28));
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    local_1314 = 0;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      local_1314 = *(int *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    sVar12 = local_1314;
    std_vector_resize_12(local_1314);
    if (0 < (int)sVar12) {
      iVar6 = 0;
      do {
        piVar2 = (int *)*in_ECX;
        iVar11 = 0;
        local_131c = (int *)(piVar2[3] + 4);
        piVar10 = (int *)(piVar2[1] - *piVar2);
        if ((int)local_131c <= piVar2[1] - *piVar2) {
          iVar11 = *(int *)(*piVar2 + piVar2[3]);
          piVar10 = local_131c;
        }
        piVar2[3] = (int)piVar10;
        vector_resize_0x11c(iVar11);
        if (iVar11 != 0) {
          local_1318 = (int ***)*in_ECX;
          local_131c = *(int **)(iVar6 + *local_1324);
          if ((int)local_1318[1] - (int)*local_1318 < (int)(local_1318[3] + iVar11 * 0x47)) {
            local_1318[3] = (int **)((int)local_1318[1] - (int)*local_1318);
          }
          else {
            memcpy(local_131c,(void *)((int)*local_1318 + (int)local_1318[3]),iVar11 * 0x11c);
            local_1318[3] = local_1318[3] + iVar11 * 0x47;
          }
        }
        iVar6 = iVar6 + 0xc;
        local_1314 = local_1314 + -1;
      } while (local_1314 != 0);
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(local_1320 + 0x1304) = *(undefined4 *)(*piVar2 + piVar2[3]);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)(local_1320 + 0x1308) = *(undefined4 *)(*piVar2 + piVar2[3]);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    local_1324 = (int *)0x0;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      local_1324 = *(int **)(*piVar2 + piVar2[3]);
      piVar2[3] = piVar2[3] + 4;
    }
    local_1314 = 0;
    if (0 < (int)local_1324) {
      do {
        local_180 = 1;
        local_190[0] = 0;
        local_18c = 0;
        local_188 = 0;
        local_184 = 0;
        local_182 = 0;
        local_7c = 0;
        memset(local_17c,0,0x100);
        iVar11 = local_1320;
        piVar2 = (int *)*in_ECX;
        iVar6 = piVar2[3] + 0x118;
        local_1318 = (int ***)(piVar2[1] - *piVar2);
        if (iVar6 <= (int)local_1318) {
          local_1318 = (int ***)iVar6;
          memcpy(local_190,(void *)(*piVar2 + piVar2[3]),0x118);
        }
        piVar2[3] = (int)local_1318;
        iVar6 = *(int *)(iVar11 + 0x1d28);
        local_1318 = *(int ****)(iVar6 + 0x14);
        pppiVar8 = (int ***)list_makeNodeWrapper(local_1318,local_1318[1],local_190);
        if (*(int *)(iVar6 + 0x18) == 0xe38e37) {
                    /* WARNING: Subroutine does not return */
          std::_Xlength_error("list<T> too long");
        }
        *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + 1;
        local_1318[1] = (int **)pppiVar8;
        *pppiVar8[1] = (int *)pppiVar8;
        local_1314 = local_1314 + 1;
      } while ((int)local_1314 < (int)local_1324);
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[1] - *piVar2;
    local_1314 = 0;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      local_1314 = *(int *)(*piVar2 + piVar2[3]);
      piVar2[3] = piVar2[3] + 4;
    }
    iVar6 = local_1320;
    if (0 < (int)local_1314) {
      do {
        piVar2 = (int *)*in_ECX;
        iVar11 = piVar2[3];
        iVar6 = piVar2[1] - *piVar2;
        if (iVar11 + 4 <= iVar6) {
          local_1324 = *(int **)(*piVar2 + iVar11);
          iVar6 = iVar11 + 4;
        }
        piVar2[3] = iVar6;
        piVar2 = (int *)*in_ECX;
        sVar12 = 0;
        iVar11 = piVar2[3];
        iVar6 = piVar2[1] - *piVar2;
        if (iVar11 + 4 <= iVar6) {
          sVar12 = *(size_t *)(*piVar2 + iVar11);
          iVar6 = iVar11 + 4;
        }
        piVar2[3] = iVar6;
        local_30 = 0xf;
        local_34 = 0;
        local_44[0] = (int ***)((uint)local_44[0] & 0xffffff00);
        local_8 = 3;
        if (sVar12 == 0) {
                    /* WARNING: Ignoring partial resolution of indirect */
          local_44[0]._0_1_ = 0;
          local_34 = 0;
        }
        else {
          string_appendFill(sVar12,0);
        }
        local_131c = (int *)*in_ECX;
        local_1318 = (int ***)local_44;
        if (0xf < local_30) {
          local_1318 = local_44[0];
        }
        iVar6 = local_131c[1] - *local_131c;
        if (iVar6 < (int)(local_131c[3] + sVar12)) {
          local_131c[3] = iVar6;
        }
        else {
          memcpy(local_1318,(void *)(local_131c[3] + *local_131c),sVar12);
          local_131c[3] = local_131c[3] + sVar12;
        }
        piVar2 = (int *)*in_ECX;
        iVar6 = piVar2[3];
        iVar11 = *piVar2;
        if (piVar2[1] - iVar11 < iVar6 + 0x18) {
          piVar2[3] = piVar2[1] - iVar11;
        }
        else {
          local_5c = *(undefined8 *)(iVar11 + iVar6);
          local_54 = *(undefined8 *)(iVar11 + 8 + iVar6);
          local_4c = *(undefined8 *)(iVar11 + 0x10 + iVar6);
          piVar2[3] = iVar6 + 0x18;
        }
        uVar5 = string_assignSwapTmp(local_78,&local_1324,local_44);
        iVar6 = local_1320;
        local_8 = CONCAT31(local_8._1_3_,4);
        puVar9 = (undefined4 *)WorldInfo_mapInsertUnique(uVar5);
        *puVar9 = (undefined4)local_5c;
        puVar9[1] = local_5c._4_4_;
        puVar9[2] = (undefined4)local_54;
        puVar9[4] = (undefined4)local_4c;
        puVar9[3] = local_54._4_4_;
        puVar9[5] = local_4c._4_4_;
        if (0xf < local_60) {
                    /* WARNING: Subroutine does not return */
          operator_delete(local_74);
        }
        if (0xf < local_30) {
                    /* WARNING: Subroutine does not return */
          operator_delete(local_44[0]);
        }
        local_1314 = local_1314 + -1;
      } while (local_1314 != 0);
    }
    piVar2 = (int *)*in_ECX;
    local_1318 = *(int ****)(iVar6 + 0x1d28);
    iVar6 = piVar2[1] - *piVar2;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
    }
    else {
      *(undefined4 *)((int)local_1318 + 0x24) = *(undefined4 *)(*piVar2 + piVar2[3]);
      piVar2[3] = piVar2[3] + 4;
    }
    local_18 = 0xf;
    local_1c = 0;
    uVar4 = (uint)local_2c[0] >> 8;
    local_2c[0] = (undefined4 ***)(uVar4 << 8);
    piVar2 = (int *)*in_ECX;
    sVar12 = 0;
    iVar6 = piVar2[1] - *piVar2;
    local_8 = 5;
    if (iVar6 < piVar2[3] + 4) {
      piVar2[3] = iVar6;
      local_1c = 0;
      local_2c[0] = (undefined4 ***)(uVar4 << 8);
    }
    else {
      sVar12 = *(size_t *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
      if (sVar12 == 0) {
                    /* WARNING: Ignoring partial resolution of indirect */
        local_2c[0]._0_1_ = 0;
        local_1c = 0;
      }
      else {
        string_appendFill(sVar12,0);
      }
    }
    local_131c = (int *)*in_ECX;
    local_1318 = (int ***)local_2c;
    if (0xf < local_18) {
      local_1318 = local_2c[0];
    }
    iVar6 = local_131c[1] - *local_131c;
    if (iVar6 < (int)(local_131c[3] + sVar12)) {
      local_131c[3] = iVar6;
    }
    else {
      memcpy(local_1318,(void *)(local_131c[3] + *local_131c),sVar12);
      local_131c[3] = local_131c[3] + sVar12;
    }
    iVar6 = local_1320;
    if ((undefined4 ****)(*(int *)(local_1320 + 0x1d28) + 0x28) != local_2c) {
      string_assignSubstr(local_2c,0,0xffffffff);
    }
    piVar2 = (int *)*in_ECX;
    iVar11 = piVar2[1] - *piVar2;
    if (iVar11 < piVar2[3] + 4) {
      piVar2[3] = iVar11;
    }
    else {
      *(undefined4 *)(iVar6 + 0x1164) = *(undefined4 *)(piVar2[3] + *piVar2);
      piVar2[3] = piVar2[3] + 4;
    }
    piVar2 = (int *)*in_ECX;
    iVar6 = piVar2[3];
    iVar11 = piVar2[1] - *piVar2;
    if (iVar11 < iVar6 + 4) {
      piVar2[3] = iVar11;
    }
    else {
      iVar11 = *(int *)(iVar6 + *piVar2);
      piVar2[3] = iVar6 + 4;
      if (iVar11 == 0xb) {
        piVar2 = (int *)*in_ECX;
        iVar6 = piVar2[1] - *piVar2;
        if (iVar6 < piVar2[3] + 0x2c) {
          piVar2[3] = iVar6;
        }
        else {
          memcpy((void *)(local_1320 + 0x1138),(void *)(piVar2[3] + *piVar2),0x2c);
          piVar2[3] = piVar2[3] + 0x2c;
        }
      }
    }
    if (local_18 < 0x10) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  std_vector_destroy_ptr_elems_stride3(local_1a8,local_1a4,&local_1325,local_1318);
                    /* WARNING: Subroutine does not return */
  operator_delete(local_1a8);
}




