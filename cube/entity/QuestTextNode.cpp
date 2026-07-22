// QuestTextNode (entity) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "QuestTextNode.h"

/* cube::QuestTextNode::ctor_0 @ 004da3b0 */

void cube::QuestTextNode::ctor_0(void)

{
  uint uVar1;
  undefined4 list;
  undefined4 *self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8ebc;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  list = rbtree_allocHeaderNode_28(uVar1);
  self[1] = list;
  local_8 = 0;
  self[3] = 0;
  self[4] = 0;
  list = rbtree_allocHeaderNode_28();
  self[3] = list;
  local_8._0_1_ = 1;
  self[5] = 0;
  self[6] = 0;
  list = rbtree_allocHeaderNode_28();
  self[5] = list;
  self[0xc] = 7;
  self[0xb] = 0;
  *(undefined2 *)(self + 7) = 0;
  self[0xd] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  self[0xe] = 0;
  self[0xf] = 0;
  list = list_buyNode_0c(0,0);
  self[0xe] = list;
  self[0x10] = 0;
  ExceptionList = local_10;
  return;
}




/* cube::QuestTextNode::ctor_1 @ 004da540 */

void cube::QuestTextNode::ctor_1(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint cookie;
  undefined4 *self;
  int *node;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e8f47;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 4;
  node = *(int **)self[0xe];
  if (node != (int *)self[0xe]) {
    do {
      if ((undefined4 *)node[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)node[2])(1,cookie);
      }
      node = (int *)*node;
    } while (node != (int *)self[0xe]);
  }
  puVar1 = (undefined4 *)self[0xe];
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(self[0xe] + 4) = self[0xe];
  self[0xf] = 0;
  if (pvVar2 != (void *)self[0xe]) {
    operator_delete(pvVar2);
  }
  operator_delete((void *)self[0xe]);
}




/* cube::QuestTextNode::vfunc_0 @ 004da700 */

void cube::QuestTextNode::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  ctor_1();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




