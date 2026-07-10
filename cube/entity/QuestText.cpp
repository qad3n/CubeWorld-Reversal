// QuestText (entity) — cube. 11 functions. Bodies = Ghidra pseudo-C.
#include "QuestText.h"

/* [AUDIT] proposed: QuestText_copyTree  (confidence: high)
 * purpose: Copies a QuestText std::map red-black tree, then fixes leftmost/rightmost pointers
 * vars: in_ECX map header
 */
/* Global::QuestText_copyTree @ 004d9b10 */

void QuestText_copyTree(int *srcRoot,undefined4 param_2)

{
  char cVar1;
  int dstNode;
  int *root;
  int *child;
  int parent;
  int *leaf;
  undefined4 uVar7;
  int *in_ECX;
  
  dstNode = *in_ECX;
  uVar7 = QuestText_copyTreeNode(*(undefined4 *)(*srcRoot + 4),dstNode,param_2);
  *(undefined4 *)(dstNode + 4) = uVar7;
  root = (int *)*in_ECX;
  in_ECX[1] = srcRoot[1];
  child = (int *)root[1];
  if (*(char *)((int)child + 0xd) != '\0') {
    *root = (int)root;
    *(int *)(*in_ECX + 8) = *in_ECX;
    return;
  }
  cVar1 = *(char *)(*child + 0xd);
  leaf = (int *)*child;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*leaf + 0xd);
    child = leaf;
    leaf = (int *)*leaf;
  }
  *root = (int)child;
  dstNode = *(int *)(*in_ECX + 4);
  parent = *(int *)(dstNode + 8);
  cVar1 = *(char *)(parent + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(parent + 8) + 0xd);
    dstNode = parent;
    parent = *(int *)(parent + 8);
  }
  *(int *)(*in_ECX + 8) = dstNode;
  return;
}




/* [AUDIT] proposed: QuestText_copyTreeNode  (confidence: high)
 * purpose: Recursively copies a red-black tree subtree (left/right) into destination map
 * vars: recursion via 004d9b90
 */
/* Global::QuestText_copyTreeNode @ 004d9b90 */

undefined4 * QuestText_copyTreeNode(undefined4 *srcNode,undefined4 parent,undefined4 param_3)

{
  undefined4 *newNode;
  undefined4 childNode;
  int *in_ECX;
  undefined4 *root;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8e30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  root = (undefined4 *)*in_ECX;
  if (*(char *)((int)srcNode + 0xd) == '\0') {
    newNode = (undefined4 *)QuestText_cloneNode(srcNode + 4);
    newNode[1] = parent;
    *(undefined1 *)(newNode + 3) = *(undefined1 *)(srcNode + 3);
    if (*(char *)((int)root + 0xd) != '\0') {
      root = newNode;
    }
    local_8 = 0;
    childNode = QuestText_copyTreeNode(*srcNode,newNode,param_3);
    *newNode = childNode;
    childNode = QuestText_copyTreeNode(srcNode[2],newNode,param_3);
    newNode[2] = childNode;
  }
  ExceptionList = local_10;
  return root;
}




/* cube::QuestText::ctor_1 @ 004da380 */

void cube::QuestText::ctor_1(void)

{
  undefined4 list;
  undefined4 *self;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  list = rbtree_allocHeaderNode_28();
  self[2] = list;
  return;
}




/* cube::QuestText::ctor_2 @ 004da4c0 */

void cube::QuestText::ctor_2(void)

{
  uint cookie;
  undefined4 *self;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e8eeb;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  if ((undefined4 *)self[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[1])(1,cookie);
  }
  local_8 = 0xffffffff;
  std_map_eraseRange_661a20(local_14,*(undefined4 *)self[2],(undefined4 *)self[2]);
  operator_delete((void *)self[2]);
}




/* cube::QuestText::vfunc_0 @ 004da670 */

void cube::QuestText::vfunc_0(void)

{
  uint cookie;
  undefined4 *self;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e8f7b;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  if ((undefined4 *)self[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[1])(1,cookie);
  }
  local_8 = 0xffffffff;
  std_map_eraseRange_661a20(local_14,*(undefined4 *)self[2],(undefined4 *)self[2]);
  operator_delete((void *)self[2]);
}




/* cube::QuestText::ctor_3 @ 004e0250 */

int cube::QuestText::ctor_3(int src)

{
  int srcSaved;
  int node;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9489;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  node = rbtree_alloc_node();
  srcSaved = src;
  *(undefined2 *)(node + 0xc) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (node != -0x10) {
    u16string_moveConstruct(src);
    *(undefined ***)(node + 0x28) = vftable;
    *(undefined4 *)(node + 0x2c) = *(undefined4 *)(srcSaved + 0x1c);
    local_8 = CONCAT31(local_8._1_3_,2);
    QuestText_member_ctor(srcSaved + 0x20,(int)&src + 3);
  }
  ExceptionList = local_10;
  return node;
}




/* [AUDIT] proposed: QuestText_insertHint_str  (confidence: high)
 * purpose: QuestText std::map insert-with-hint for string key; compares and rebalances via QuestText_insertRebalance
 * vars: param_3 key; +8 node str
 */
/* Global::QuestText_insertHint_str @ 004e0fe0 */

undefined4 * QuestText_insertHint_str(undefined4 *param_1,int *hint,undefined4 *key,undefined4 value)

{
  char cVar1;
  int cmp;
  int *root;
  undefined4 *keyPtr;
  int *in_ECX;
  undefined4 insertLeft;
  uint uStack_2c;
  undefined1 local_1c [4];
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9570;
  local_10 = ExceptionList;
  uStack_2c = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_ECX[1] == 0) {
    hint = (int *)*in_ECX;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    root = (int *)*in_ECX;
    if (hint != (int *)*root) {
      if (hint == root) {
        keyPtr = key;
        if (7 < (uint)key[5]) {
          keyPtr = (undefined4 *)*key;
        }
        local_14 = (undefined1 *)&uStack_2c;
        cmp = u16string_compare(0,*(undefined4 *)(root[2] + 0x20),keyPtr,key[4]);
        if (-1 < cmp) goto LAB_004e1181;
        hint = *(int **)(*in_ECX + 8);
        insertLeft = 0;
        goto LAB_004e1029;
      }
      root = hint + 4;
      if (7 < (uint)hint[9]) {
        root = (int *)*root;
      }
      local_18 = in_ECX;
      cmp = u16string_compare(0,key[4],root,hint[8]);
      if (cmp < 0) {
        rbtree_iteratorIncrement();
        cVar1 = less_stringKey_map(hint + 4,key);
        if (cVar1 == '\0') goto LAB_004e1126;
        if (*(char *)(hint[2] + 0xd) == '\0') {
          insertLeft = 1;
          goto LAB_004e1029;
        }
      }
      else {
LAB_004e1126:
        cVar1 = less_stringKey_map(hint + 4,key);
        if ((cVar1 == '\0') ||
           ((rbtree_iterator_increment(), hint != (int *)*local_18 &&
            (cVar1 = less_stringKey_map(key,hint + 4), cVar1 == '\0')))) {
LAB_004e1181:
          local_8 = 0xffffffff;
          keyPtr = (undefined4 *)QuestText_insertUnique_str(local_1c,0,key,value);
          *param_1 = *keyPtr;
          ExceptionList = local_10;
          return param_1;
        }
        if (*(char *)(hint[2] + 0xd) == '\0') {
          insertLeft = 1;
          goto LAB_004e1029;
        }
      }
      insertLeft = 0;
      goto LAB_004e1029;
    }
    root = hint + 4;
    if (7 < (uint)hint[9]) {
      root = (int *)*root;
    }
    local_14 = (undefined1 *)&uStack_2c;
    cmp = u16string_compare(0,key[4],root,hint[8]);
    if (-1 < cmp) goto LAB_004e1181;
  }
  insertLeft = 1;
LAB_004e1029:
  QuestText_insertRebalance(param_1,insertLeft,hint,key,value);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: QuestText_insertUnique_str  (confidence: high)
 * purpose: QuestText std::map insert-unique for string key; finds slot, checks duplicate, rebalances via QuestText_insertRebalance
 * vars: key key; +8 str
 */
/* Global::QuestText_insertUnique_str @ 004e1480 */

void QuestText_insertUnique_str(undefined4 *param_1,undefined4 *insertLeft,undefined4 *key,undefined4 value)

{
  undefined4 *root;
  int cmp;
  int *piVar3;
  undefined4 *cur;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *in_ECX;
  bool less;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar5 = key;
  puStack_c = &LAB_006e95d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  less = true;
  local_8 = 0;
  root = (undefined4 *)*in_ECX;
  cur = (undefined4 *)((undefined4 *)*in_ECX)[1];
  while (*(char *)((int)cur + 0xd) == '\0') {
    if ((char)insertLeft == '\0') {
      piVar3 = cur + 4;
      if (7 < (uint)cur[9]) {
        piVar3 = (int *)*piVar3;
      }
      cmp = u16string_compare(0,puVar5[4],piVar3,cur[8]);
      less = cmp < 0;
    }
    else {
      root = puVar5;
      if (7 < (uint)puVar5[5]) {
        root = (undefined4 *)*puVar5;
      }
      cmp = u16string_compare(0,cur[8],root,puVar5[4]);
      less = -1 < cmp;
    }
    root = cur;
    if (less == false) {
      cur = (undefined4 *)cur[2];
    }
    else {
      cur = (undefined4 *)*cur;
    }
  }
  insertLeft = root;
  if (less != false) {
    if (root == *(undefined4 **)*in_ECX) {
      cur = &insertLeft;
      less = true;
      goto LAB_004e1541;
    }
    rbtree_iteratorIncrement();
  }
  cur = insertLeft;
  puVar6 = puVar5;
  if (7 < (uint)puVar5[5]) {
    puVar6 = (undefined4 *)*puVar5;
  }
  cmp = u16string_compare(0,insertLeft[8],puVar6,puVar5[4]);
  if (-1 < cmp) {
    QuestText_delete_node(value);
    *param_1 = cur;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  cur = &key;
LAB_004e1541:
  puVar5 = (undefined4 *)QuestText_insertRebalance(cur,less,root,puVar5,value);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: QuestText::member_ctor  (confidence: med)
 * purpose: Constructs a QuestText container member: allocs sentinel via rbtree_allocHeaderNode_28, then QuestText_copyTree init
 * vars: in_ECX=this; QuestText string node
 */
/* Global::QuestText_member_ctor @ 004e1830 */

void QuestText_member_ctor(undefined4 srcRoot)

{
  undefined4 list;
  undefined4 *self;
  uint flag;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = 0;
  self[1] = 0;
  list = rbtree_allocHeaderNode_28();
  *self = list;
  flag = flag & 0xffffff00;
  local_8 = 1;
  QuestText_copyTree(srcRoot,flag);
  ExceptionList = local_10;
  return;
}




/* cube::QuestText::ctor_0 @ 004e3320 */

void cube::QuestText::ctor_0(int key)

{
  uint uVar1;
  int existing;
  int *keyPtr;
  int cmp;
  int *in_ECX;
  undefined1 local_41;
  undefined1 local_40 [4];
  void *local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined **vftablePtr;
  undefined4 local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9a20;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  existing = map_lower_bound_string(key);
  if (existing != *in_ECX) {
    keyPtr = (int *)(existing + 0x10);
    if (7 < *(uint *)(existing + 0x24)) {
      keyPtr = (int *)*keyPtr;
    }
    cmp = u16string_compare(0,*(undefined4 *)(key + 0x10),keyPtr,*(undefined4 *)(existing + 0x20));
    if (-1 < cmp) goto LAB_004e3423;
  }
  cmp = ctor_1(uVar1);
  local_8 = 0;
  u16string_moveConstruct(key);
  vftablePtr = vftable;
  local_20 = *(undefined4 *)(cmp + 4);
  local_8._0_1_ = 1;
  QuestText_member_ctor(cmp + 8,&local_41);
  local_8._0_1_ = 2;
  cmp = ctor_3(local_3c);
  QuestText_insertHint_str(local_40,existing,cmp + 0x10,cmp);
  local_8 = CONCAT31(local_8._1_3_,3);
  ctor_2();
  if (7 < local_28) {
    operator_delete(local_3c[0]);
  }
  local_28 = 7;
  local_2c = 0;
  local_3c[0] = (void *)((uint)local_3c[0] & 0xffff0000);
  local_8 = 0xffffffff;
  ctor_2();
LAB_004e3423:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: QuestText::delete_node  (confidence: med)
 * purpose: Destroys one QuestText tree node: runs dtor, frees string if cap>7, operator_delete node
 * vars: key=node; string ptr +0x10 cap +0x24
 */
/* Global::QuestText_delete_node @ 004e3550 */

void QuestText_delete_node(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9a58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  cube::QuestText::ctor_2(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  if (7 < *(uint *)((int)param_1 + 0x24)) {
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  *(undefined4 *)((int)param_1 + 0x24) = 7;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined2 *)((int)param_1 + 0x10) = 0;
  operator_delete(param_1);
}




