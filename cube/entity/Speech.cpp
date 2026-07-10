// Speech (entity) — cube. 6 functions. Bodies = Ghidra pseudo-C.
#include "Speech.h"

/* cube::Speech::ctor_0 @ 004e2b10 */

void cube::Speech::ctor_0(void)

{
  char isLeaf;
  undefined4 *speechObj;
  int *parent;
  uint cookie;
  undefined4 *self;
  int *cur;
  int *node;
  undefined1 local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e990e;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 9;
  node = (int *)self[0xf];
  cur = (int *)*node;
  if (cur != node) {
    do {
      speechObj = (undefined4 *)cur[10];
      if (speechObj != (undefined4 *)0x0) {
        Speech_map_erase_range2(local_18,*(undefined4 *)*speechObj,(undefined4 *)*speechObj);
        operator_delete((void *)*speechObj);
      }
      if (*(char *)((int)cur + 0xd) == '\0') {
        node = (int *)cur[2];
        if (*(char *)((int)node + 0xd) == '\0') {
          isLeaf = *(char *)(*node + 0xd);
          cur = node;
          node = (int *)*node;
          while (isLeaf == '\0') {
            isLeaf = *(char *)(*node + 0xd);
            cur = node;
            node = (int *)*node;
          }
        }
        else {
          isLeaf = *(char *)(cur[1] + 0xd);
          parent = (int *)cur[1];
          node = cur;
          while ((cur = parent, isLeaf == '\0' && (node == (int *)cur[2]))) {
            isLeaf = *(char *)(cur[1] + 0xd);
            parent = (int *)cur[1];
            node = cur;
          }
        }
      }
    } while (cur != (int *)self[0xf]);
  }
  node = *(int **)self[0x11];
  local_14 = self;
  if (node != (int *)self[0x11]) {
    do {
      if ((undefined4 *)node[10] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)node[10])(1,cookie);
      }
      if (*(char *)((int)node + 0xd) == '\0') {
        cur = (int *)node[2];
        if (*(char *)((int)cur + 0xd) == '\0') {
          isLeaf = *(char *)(*cur + 0xd);
          node = cur;
          cur = (int *)*cur;
          while (isLeaf == '\0') {
            isLeaf = *(char *)(*cur + 0xd);
            node = cur;
            cur = (int *)*cur;
          }
        }
        else {
          isLeaf = *(char *)(node[1] + 0xd);
          parent = (int *)node[1];
          cur = node;
          while ((node = parent, isLeaf == '\0' && (cur == (int *)node[2]))) {
            isLeaf = *(char *)(node[1] + 0xd);
            parent = (int *)node[1];
            cur = node;
          }
        }
      }
    } while (node != (int *)self[0x11]);
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  Speech_map_erase_range(local_18,*(undefined4 *)local_14[0x13],(undefined4 *)local_14[0x13]);
  operator_delete((void *)local_14[0x13]);
}




/* cube::Speech::vfunc_0 @ 004e3450 */

void cube::Speech::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  ctor_0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* [AUDIT] proposed: Speech::map_erase_range  (confidence: med)
 * purpose: Erases all nodes in [param_2,param_3); if whole tree clears to sentinel, else per-node erase
 * vars: in_ECX=map; iterates successor nodes
 */
/* Global::Speech_map_erase_range @ 004e3840 */

undefined4 * Speech_map_erase_range(undefined4 *param_1,int *first,int *last)

{
  char isLeaf;
  int *next;
  int *cur;
  int *parent;
  int *in_ECX;
  undefined1 local_8 [4];
  
  next = (int *)*in_ECX;
  cur = first;
  if ((first == (int *)*next) && (last == next)) {
    rbtree_destroy_recursive(next[1]);
    *(int *)(*in_ECX + 4) = *in_ECX;
    *(int *)*in_ECX = *in_ECX;
    *(int *)(*in_ECX + 8) = *in_ECX;
    in_ECX[1] = 0;
    *param_1 = *(undefined4 *)*in_ECX;
    return param_1;
  }
  while (cur != last) {
    first = cur;
    if (*(char *)((int)cur + 0xd) == '\0') {
      first = (int *)cur[2];
      if (*(char *)((int)first + 0xd) == '\0') {
        isLeaf = *(char *)(*first + 0xd);
        next = (int *)*first;
        while (isLeaf == '\0') {
          isLeaf = *(char *)(*next + 0xd);
          first = next;
          next = (int *)*next;
        }
      }
      else {
        isLeaf = *(char *)(cur[1] + 0xd);
        parent = (int *)cur[1];
        next = cur;
        while ((first = parent, isLeaf == '\0' && (next == (int *)first[2]))) {
          isLeaf = *(char *)(first[1] + 0xd);
          parent = (int *)first[1];
          next = first;
        }
      }
    }
    Speech_map_erase_node(local_8,cur);
    cur = first;
  }
  *param_1 = cur;
  return param_1;
}




/* [AUDIT] proposed: Speech::map_erase_node  (confidence: high)
 * purpose: Removes one map/set node with red-black rebalance and frees it; throws on invalid iterator
 * vars: first=node; color +3; str +5 cap +10
 */
/* Global::Speech_map_erase_node @ 004e3900 */

/* WARNING: Removing unreachable block (ram,0x004e39cd) */
/* WARNING: Removing unreachable block (ram,0x004e39dd) */
/* WARNING: Removing unreachable block (ram,0x004e39e6) */
/* WARNING: Removing unreachable block (ram,0x004e39e9) */
/* WARNING: Removing unreachable block (ram,0x004e39d9) */
/* WARNING: Removing unreachable block (ram,0x004e39f7) */
/* WARNING: Removing unreachable block (ram,0x004e3a06) */
/* WARNING: Removing unreachable block (ram,0x004e3a11) */
/* WARNING: Removing unreachable block (ram,0x004e3a0d) */
/* WARNING: Removing unreachable block (ram,0x004e3a01) */
/* WARNING: Removing unreachable block (ram,0x004e3a14) */

void Speech_map_erase_node(undefined4 param_1,int *node)

{
  undefined4 *puVar1;
  int iVar2;
  int *sibling;
  undefined4 uVar4;
  int *in_ECX;
  int *parentNode;
  int *fixupNode;
  
  if (*(char *)((int)node + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  rbtree_iterator_increment();
  fixupNode = (int *)*node;
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    if (*(char *)(node[2] + 0xd) == '\0') {
      fixupNode = (int *)node[2];
    }
  }
  else {
    fixupNode = (int *)node[2];
  }
  parentNode = (int *)node[1];
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    fixupNode[1] = (int)parentNode;
  }
  if (*(int **)(*in_ECX + 4) == node) {
    *(int **)(*in_ECX + 4) = fixupNode;
  }
  else if ((int *)*parentNode == node) {
    *parentNode = (int)fixupNode;
  }
  else {
    parentNode[2] = (int)fixupNode;
  }
  puVar1 = (undefined4 *)*in_ECX;
  if ((int *)*puVar1 == node) {
    sibling = parentNode;
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      sibling = (int *)rbtree_min_node(fixupNode);
    }
    *puVar1 = sibling;
  }
  iVar2 = *in_ECX;
  if (*(int **)(iVar2 + 8) == node) {
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      uVar4 = RBTree_next(fixupNode);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = parentNode;
    }
  }
  if ((char)node[3] == '\x01') {
    if (fixupNode != *(int **)(*in_ECX + 4)) {
      do {
        sibling = parentNode;
        if ((char)fixupNode[3] != '\x01') break;
        parentNode = (int *)*sibling;
        if (fixupNode == parentNode) {
          parentNode = (int *)sibling[2];
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate_left(sibling);
            parentNode = (int *)sibling[2];
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(*parentNode + 0xc) != '\x01') || (*(char *)(parentNode[2] + 0xc) != '\x01')) {
              if (*(char *)(parentNode[2] + 0xc) == '\x01') {
                *(undefined1 *)(*parentNode + 0xc) = 1;
                *(undefined1 *)(parentNode + 3) = 0;
                rbtree_rotate(parentNode);
                parentNode = (int *)sibling[2];
              }
              *(char *)(parentNode + 3) = (char)sibling[3];
              *(undefined1 *)(sibling + 3) = 1;
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              rbtree_rotate_left(sibling);
              *(undefined1 *)(fixupNode + 3) = 1;
              goto LAB_004e3b5e;
            }
LAB_004e3b00:
            *(undefined1 *)(parentNode + 3) = 0;
          }
        }
        else {
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate(sibling);
            parentNode = (int *)*sibling;
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(parentNode[2] + 0xc) == '\x01') && (*(char *)(*parentNode + 0xc) == '\x01'))
            goto LAB_004e3b00;
            if (*(char *)(*parentNode + 0xc) == '\x01') {
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              *(undefined1 *)(parentNode + 3) = 0;
              rbtree_rotate_left(parentNode);
              parentNode = (int *)*sibling;
            }
            *(char *)(parentNode + 3) = (char)sibling[3];
            *(undefined1 *)(sibling + 3) = 1;
            *(undefined1 *)(*parentNode + 0xc) = 1;
            rbtree_rotate(sibling);
            *(undefined1 *)(fixupNode + 3) = 1;
            goto LAB_004e3b5e;
          }
        }
        parentNode = (int *)sibling[1];
        fixupNode = sibling;
      } while (sibling != *(int **)(*in_ECX + 4));
    }
    *(undefined1 *)(fixupNode + 3) = 1;
  }
LAB_004e3b5e:
  if (7 < (uint)node[10]) {
    operator_delete((void *)node[5]);
  }
  node[10] = 7;
  node[9] = 0;
  *(undefined2 *)(node + 5) = 0;
  operator_delete(node);
}




/* [AUDIT] proposed: Speech::map_erase_range2  (confidence: med)
 * purpose: Erase range variant using Speech_map_erase_node_qt node-erase with QuestText dtor
 * vars: in_ECX=map; range node..param_3
 */
/* Global::Speech_map_erase_range2 @ 004e3f40 */

undefined4 * Speech_map_erase_range2(undefined4 *param_1,int *first,int *last)

{
  char isLeaf;
  int *next;
  int *cur;
  int *parent;
  int *in_ECX;
  undefined1 local_8 [4];
  
  next = (int *)*in_ECX;
  cur = first;
  if ((first == (int *)*next) && (last == next)) {
    rbtree_destroy_recursive_qt(next[1]);
    *(int *)(*in_ECX + 4) = *in_ECX;
    *(int *)*in_ECX = *in_ECX;
    *(int *)(*in_ECX + 8) = *in_ECX;
    in_ECX[1] = 0;
    *param_1 = *(undefined4 *)*in_ECX;
    return param_1;
  }
  while (cur != last) {
    first = cur;
    if (*(char *)((int)cur + 0xd) == '\0') {
      first = (int *)cur[2];
      if (*(char *)((int)first + 0xd) == '\0') {
        isLeaf = *(char *)(*first + 0xd);
        next = (int *)*first;
        while (isLeaf == '\0') {
          isLeaf = *(char *)(*next + 0xd);
          first = next;
          next = (int *)*next;
        }
      }
      else {
        isLeaf = *(char *)(cur[1] + 0xd);
        parent = (int *)cur[1];
        next = cur;
        while ((first = parent, isLeaf == '\0' && (next == (int *)first[2]))) {
          isLeaf = *(char *)(first[1] + 0xd);
          parent = (int *)first[1];
          next = first;
        }
      }
    }
    Speech_map_erase_node_qt(local_8,cur);
    cur = first;
  }
  *param_1 = cur;
  return param_1;
}




/* [AUDIT] proposed: Speech::map_erase_node_qt  (confidence: high)
 * purpose: Erase single map node with RB rebalance, runs QuestText::ctor_2, frees string(+4/+9) and node
 * vars: first=node; color +3
 */
/* Global::Speech_map_erase_node_qt @ 004e4000 */

/* WARNING: Removing unreachable block (ram,0x004e40e1) */
/* WARNING: Removing unreachable block (ram,0x004e40f1) */
/* WARNING: Removing unreachable block (ram,0x004e40fa) */
/* WARNING: Removing unreachable block (ram,0x004e40fd) */
/* WARNING: Removing unreachable block (ram,0x004e40ed) */
/* WARNING: Removing unreachable block (ram,0x004e410b) */
/* WARNING: Removing unreachable block (ram,0x004e4117) */
/* WARNING: Removing unreachable block (ram,0x004e4122) */
/* WARNING: Removing unreachable block (ram,0x004e411e) */
/* WARNING: Removing unreachable block (ram,0x004e4112) */
/* WARNING: Removing unreachable block (ram,0x004e4125) */

void Speech_map_erase_node_qt(undefined4 param_1,int *node)

{
  int *sibling;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *parentNode;
  int *fixupNode;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9ab8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)node + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  rbtree_iterator_increment(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  fixupNode = (int *)*node;
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    if (*(char *)(node[2] + 0xd) == '\0') {
      fixupNode = (int *)node[2];
    }
  }
  else {
    fixupNode = (int *)node[2];
  }
  parentNode = (int *)node[1];
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    fixupNode[1] = (int)parentNode;
  }
  if (*(int **)(*in_ECX + 4) == node) {
    *(int **)(*in_ECX + 4) = fixupNode;
  }
  else if ((int *)*parentNode == node) {
    *parentNode = (int)fixupNode;
  }
  else {
    parentNode[2] = (int)fixupNode;
  }
  puVar2 = (undefined4 *)*in_ECX;
  if ((int *)*puVar2 == node) {
    sibling = parentNode;
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      sibling = (int *)rbtree_min_node(fixupNode);
      puVar2 = (undefined4 *)*in_ECX;
    }
    *puVar2 = sibling;
  }
  if (*(int **)(*in_ECX + 8) == node) {
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      uVar3 = RBTree_next(fixupNode);
      *(undefined4 *)(*in_ECX + 8) = uVar3;
    }
    else {
      *(int **)(*in_ECX + 8) = parentNode;
    }
  }
  if ((char)node[3] == '\x01') {
    if (fixupNode != *(int **)(*in_ECX + 4)) {
      do {
        sibling = parentNode;
        if ((char)fixupNode[3] != '\x01') break;
        parentNode = (int *)*sibling;
        if (fixupNode == parentNode) {
          parentNode = (int *)sibling[2];
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate_left(sibling);
            parentNode = (int *)sibling[2];
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(*parentNode + 0xc) != '\x01') || (*(char *)(parentNode[2] + 0xc) != '\x01')) {
              if (*(char *)(parentNode[2] + 0xc) == '\x01') {
                *(undefined1 *)(*parentNode + 0xc) = 1;
                *(undefined1 *)(parentNode + 3) = 0;
                rbtree_rotate(parentNode);
                parentNode = (int *)sibling[2];
              }
              *(char *)(parentNode + 3) = (char)sibling[3];
              *(undefined1 *)(sibling + 3) = 1;
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              rbtree_rotate_left(sibling);
              break;
            }
LAB_004e4201:
            *(undefined1 *)(parentNode + 3) = 0;
          }
        }
        else {
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate(sibling);
            parentNode = (int *)*sibling;
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(parentNode[2] + 0xc) == '\x01') && (*(char *)(*parentNode + 0xc) == '\x01'))
            goto LAB_004e4201;
            if (*(char *)(*parentNode + 0xc) == '\x01') {
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              *(undefined1 *)(parentNode + 3) = 0;
              rbtree_rotate_left(parentNode);
              parentNode = (int *)*sibling;
            }
            *(char *)(parentNode + 3) = (char)sibling[3];
            *(undefined1 *)(sibling + 3) = 1;
            *(undefined1 *)(*parentNode + 0xc) = 1;
            rbtree_rotate(sibling);
            break;
          }
        }
        parentNode = (int *)sibling[1];
        fixupNode = sibling;
      } while (sibling != *(int **)(*in_ECX + 4));
    }
    *(undefined1 *)(fixupNode + 3) = 1;
  }
  local_8 = 0;
  cube::QuestText::ctor_2();
  if (7 < (uint)node[9]) {
    operator_delete((void *)node[4]);
  }
  node[9] = 7;
  node[8] = 0;
  *(undefined2 *)(node + 4) = 0;
  operator_delete(node);
}




