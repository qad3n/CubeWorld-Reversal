// Sprite (entity) — cube. 5 functions. Bodies = Ghidra pseudo-C.
#include "Sprite.h"

/* cube::Sprite::ctor_0 @ 004e6a20 */

void cube::Sprite::ctor_0(undefined4 world)

{
  uint cookie;
  undefined4 list;
  undefined4 *self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9ee6;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  _eh_vector_constructor_iterator_(self + 1,0xc,3,std_vector_initEmpty,unwind_free_object);
  local_8 = 0;
  self[10] = 0;
  self[0xb] = 0;
  list = rbtree_allocHeaderNode_1c(cookie);
  self[10] = list;
  self[0x16] = world;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  *(undefined2 *)(self + 0x15) = 0x100;
  *(undefined2 *)(self + 0x17) = 0;
  *(undefined1 *)((int)self + 0x5e) = 0;
  *(undefined1 *)((int)self + 0x56) = 0;
  ExceptionList = local_10;
  return;
}




/* cube::Sprite::ctor_1 @ 004e6b20 */

void cube::Sprite::ctor_1(void)

{
  int *child;
  uint cookie;
  undefined4 *self;
  undefined1 tmp [8];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_006e9f31;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  child = (int *)self[0xd];
  local_8 = 1;
  if (child != (int *)0x0) {
    (**(code **)(*child + 8))(child,cookie);
  }
  child = (int *)self[0xe];
  if (child != (int *)0x0) {
    (**(code **)(*child + 8))(child);
  }
  if ((void *)self[0xc] != (void *)0x0) {
    operator_delete__((void *)self[0xc]);
  }
  local_8 = local_8 & 0xffffff00;
  Sprite_map_erase_range(tmp,*(undefined4 *)self[10],(undefined4 *)self[10]);
  operator_delete((void *)self[10]);
}




/* cube::Sprite::vfunc_0 @ 004e6c30 */

void cube::Sprite::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  ctor_1();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* [AUDIT] proposed: Sprite::map_erase_range  (confidence: med)
 * purpose: Erases sprite map nodes in [param_2,param_3); clears whole tree or per-node via Sprite_map_erase_node
 * vars: in_ECX=map
 */
/* Global::Sprite_map_erase_range @ 004e6e60 */

undefined4 * Sprite_map_erase_range(undefined4 *param_1,int *first,int *last)

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
    rbtree_destroy_recursive_list(next[1]);
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
    Sprite_map_erase_node(local_8,cur);
    cur = first;
  }
  *param_1 = cur;
  return param_1;
}




/* [AUDIT] proposed: Sprite::map_erase_node  (confidence: high)
 * purpose: Removes one sprite-map node with RB rebalance and frees embedded list(+5) and node
 * vars: first=node; list head +5
 */
/* Global::Sprite_map_erase_node @ 004e6f20 */


void Sprite_map_erase_node(undefined4 param_1,int *node)

{
  undefined4 *puVar1;
  int iVar2;
  void *firstChar;
  int *sibling;
  undefined4 uVar5;
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
      uVar5 = RBTree_next(fixupNode);
      *(undefined4 *)(iVar2 + 8) = uVar5;
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
              break;
            }
LAB_004e7117:
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
            goto LAB_004e7117;
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
  puVar1 = (undefined4 *)node[5];
  firstChar = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(node[5] + 4) = node[5];
  node[6] = 0;
  if (firstChar != (void *)node[5]) {
    operator_delete(firstChar);
  }
  operator_delete((void *)node[5]);
}




