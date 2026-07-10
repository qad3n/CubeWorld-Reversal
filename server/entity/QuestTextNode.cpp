// QuestTextNode (entity) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "QuestTextNode.h"

/* cube::QuestTextNode::ctor_0 @ 0041abc0 */

undefined4 * __fastcall cube::QuestTextNode::ctor_0(undefined4 *self)

{
  undefined4 obj;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bcac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  obj = MapNode_allocSentinel40();
  self[1] = obj;
  local_8 = 0;
  self[3] = 0;
  self[4] = 0;
  obj = MapNode_allocSentinel40();
  self[3] = obj;
  local_8._0_1_ = 1;
  self[5] = 0;
  self[6] = 0;
  obj = MapNode_allocSentinel40();
  self[5] = obj;
  self[0xc] = 7;
  self[0xb] = 0;
  *(undefined2 *)(self + 7) = 0;
  self[0xd] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  self[0xe] = 0;
  self[0xf] = 0;
  obj = std_List_node_alloc_0xc((undefined4 *)0x0,(undefined4 *)0x0);
  self[0xe] = obj;
  self[0x10] = 0;
  ExceptionList = local_10;
  return self;
}




/* cube::QuestTextNode::ctor_1 @ 0041ad10 */

void __fastcall cube::QuestTextNode::ctor_1(undefined4 *self)

{
  uint uVar1;
  int *next;
  int *node;
  undefined4 local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0054bd37;
  local_10 = ExceptionList;
  uVar1 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 4;
  node = *(int **)self[0xe];
  local_14 = self;
  if (node != (int *)self[0xe]) {
    do {
      if ((undefined4 *)node[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)node[2])(1,uVar1);
      }
      node = (int *)*node;
    } while (node != (int *)self[0xe]);
  }
  node = (int *)self[0xe];
  next = (int *)*node;
  *node = (int)node;
  *(undefined4 *)(self[0xe] + 4) = self[0xe];
  self[0xf] = 0;
  if (next != (int *)self[0xe]) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)self[0xe]);
  }
  operator_delete((void *)self[0xe]);
  if (7 < (uint)self[0xc]) {
    operator_delete((void *)self[7]);
  }
  self[0xc] = 7;
  self[0xb] = 0;
  *(undefined2 *)(self + 7) = 0;
  local_8._0_1_ = 1;
  Tree_eraseRange_variant(self + 5,&local_18,*(int **)self[5],(int *)self[5]);
  operator_delete((void *)self[5]);
  local_8 = (uint)local_8._1_3_ << 8;
  Tree_eraseRange_variant(self + 3,&local_18,*(int **)self[3],(int *)self[3]);
  operator_delete((void *)self[3]);
  local_8 = 0xffffffff;
  Tree_eraseRange_variant(self + 1,&local_18,*(int **)self[1],(int *)self[1]);
  operator_delete((void *)self[1]);
  ExceptionList = local_10;
  return;
}




/* cube::QuestTextNode::vfunc_0 @ 0041af00 */

undefined4 * __thiscall cube::QuestTextNode::vfunc_0(QuestTextNode *this,byte delete_flag)

{
  ctor_1((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




