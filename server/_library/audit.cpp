// audit (_library) — server. 450 functions. Bodies = Ghidra pseudo-C.
#include "audit.h"

/* [AUDIT] proposed: RBNode_allocSetKey  (confidence: med)
 * purpose: Allocates rb-tree node then stores vec3 key (3 dwords) at node+0x10
 * vars: param_1=key vec3; node+0xc=color flag
 */
/* Global::RBNode_allocSetKey @ 004025b0 */

undefined4 * __thiscall RBNode_allocSetKey(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_Tree_node_alloc_0x20b(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    puVar1[4] = *param_1;
    puVar1[5] = param_1[1];
    puVar1[6] = param_1[2];
  }
  return puVar1;
}




/* [AUDIT] proposed: RBTree_insertNode  (confidence: low)
 * purpose: Red-black tree insert-with-hint; positions node relative to hint param_2 then rebalances
 * vars: param_2=hint; param_3=key; param_4=value ptr
 */
/* Global::RBTree_insertNode @ 004025f0 */

undefined4 * __thiscall
RBTree_insertNode(void *this,undefined4 *param_1,int *param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uStack_3c;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  void *local_20;
  int *local_1c [2];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054b940;
  local_10 = ExceptionList;
  uStack_3c = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = this;
  if (*(int *)((int)this + 4) == 0) {
    local_14 = (undefined1 *)&uStack_3c;
    std_Rb_tree_insert_rebalance_C(this,param_1,'\x01',*(undefined4 **)this,param_3,param_4);
    ExceptionList = local_10;
    return param_1;
  }
  piVar1 = *(int **)this;
  if (param_2 == (int *)*piVar1) {
    local_14 = (undefined1 *)&uStack_3c;
    if (((int)param_3[1] <= param_2[5]) &&
       ((puVar3 = &uStack_3c, (int)param_3[1] < param_2[5] ||
        (local_14 = (undefined1 *)&uStack_3c, puVar3 = &uStack_3c, *param_3 < (uint)param_2[4])))) {
LAB_0040267d:
      local_14 = (undefined1 *)puVar3;
      std_Rb_tree_insert_rebalance_C(local_20,param_1,'\x01',param_2,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    puVar5 = (undefined4 *)piVar1[2];
    local_14 = (undefined1 *)&uStack_3c;
    if (((int)puVar5[5] <= (int)param_3[1]) &&
       (((int)puVar5[5] < (int)param_3[1] ||
        (local_14 = (undefined1 *)&uStack_3c, (uint)puVar5[4] < *param_3)))) {
      local_14 = (undefined1 *)&uStack_3c;
      std_Rb_tree_insert_rebalance_C(this,param_1,'\0',puVar5,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    local_28 = param_3[1];
    local_24 = *param_3;
    uVar4 = param_2[4];
    puVar3 = &uStack_3c;
    if (((int)local_28 <= param_2[5]) &&
       (((int)local_28 < param_2[5] || (puVar3 = &uStack_3c, local_24 < uVar4)))) {
      local_1c[0] = param_2;
      std_Rb_tree_increment((int *)local_1c);
      piVar2 = local_1c[0];
      uVar4 = Int64_lessThan((uint *)(local_1c[0] + 4),param_3);
      if ((char)uVar4 != '\0') {
        puVar3 = (uint *)local_14;
        if (*(char *)(piVar2[2] + 0xd) != '\0') {
          std_Rb_tree_insert_rebalance_C(local_20,param_1,'\0',piVar2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        goto LAB_0040267d;
      }
      uVar4 = param_2[4];
      puVar3 = (uint *)local_14;
    }
    local_14 = (undefined1 *)puVar3;
    if ((param_2[5] <= (int)local_28) && ((param_2[5] < (int)local_28 || (uVar4 < local_24)))) {
      local_1c[0] = param_2;
      RBTree_iterIncrement((int *)local_1c);
      piVar2 = local_1c[0];
      if ((local_1c[0] == piVar1) ||
         (uVar4 = Int64_lessThan(param_3,(uint *)(local_1c[0] + 4)), (char)uVar4 != '\0')) {
        if (*(char *)(param_2[2] + 0xd) == '\0') {
          std_Rb_tree_insert_rebalance_C(local_20,param_1,'\x01',piVar2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_Rb_tree_insert_rebalance_C(local_20,param_1,'\0',param_2,param_3,param_4);
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
  local_8 = 0xffffffff;
  puVar5 = (undefined4 *)RBTree_insertRebalance(local_20,&local_2c,'\0',param_3,param_4);
  *param_1 = *puVar5;
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: RBTree_insertRebalance  (confidence: low)
 * purpose: RB tree insert lower_bound search + rebalance; returns node and inserted flag
 * vars: param_2=dir; param_3=key; param_4=value
 */
/* Global::RBTree_insertRebalance @ 00402840 */

void __thiscall RBTree_insertRebalance(void *this,undefined4 *param_1,char param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054b960;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)this;
  local_8 = 0;
  local_18 = true;
  piVar5 = piVar1;
  if (*(char *)(piVar1[1] + 0xd) == '\0') {
    uVar2 = param_3[1];
    piVar3 = (int *)piVar1[1];
    do {
      piVar5 = piVar3;
      if (param_2 == '\0') {
        if ((piVar5[5] < (int)uVar2) || ((piVar5[5] <= (int)uVar2 && ((uint)piVar5[4] <= *param_3)))
           ) {
          local_18 = false;
          goto LAB_004028dc;
        }
        piVar3 = (int *)*piVar5;
        local_18 = true;
      }
      else {
        if (((int)uVar2 < piVar5[5]) || (((int)uVar2 <= piVar5[5] && (*param_3 <= (uint)piVar5[4])))
           ) {
          local_18 = false;
        }
        else {
          local_18 = true;
        }
        local_18 = !local_18;
        if (local_18) {
          piVar3 = (int *)*piVar5;
        }
        else {
LAB_004028dc:
          piVar3 = (int *)piVar5[2];
        }
      }
    } while (*(char *)((int)piVar3 + 0xd) == '\0');
  }
  _param_2 = piVar5;
  if (local_18) {
    if (piVar5 == (int *)*piVar1) {
      local_18 = true;
      goto LAB_00402901;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  piVar1 = _param_2;
  if (((int)param_3[1] < _param_2[5]) ||
     (((int)param_3[1] <= _param_2[5] && (*param_3 <= (uint)_param_2[4])))) {
    operator_delete(param_4);
    *param_1 = piVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_00402901:
  puVar4 = (undefined4 *)std_Rb_tree_insert_rebalance_C(this,(undefined4 *)&param_2,local_18,piVar5,param_3,param_4);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: RBTree_findOrInsert  (confidence: med)
 * purpose: Map find by vec3 key; returns existing value+0x18 or inserts new node and returns it
 * vars: param_1=key vec3; returns value ptr (+6 dwords)
 */
/* Global::RBTree_findOrInsert @ 00402b10 */

uint * __thiscall RBTree_findOrInsert(void *this,uint *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  void *local_8;
  
  piVar3 = *(int **)this;
  piVar4 = piVar3;
  if (*(char *)(piVar3[1] + 0xd) == '\0') {
    piVar1 = (int *)piVar3[1];
    do {
      if (((int)param_1[1] < piVar1[5]) ||
         (((int)param_1[1] <= piVar1[5] && (*param_1 <= (uint)piVar1[4])))) {
        piVar2 = (int *)*piVar1;
        piVar4 = piVar1;
      }
      else {
        piVar2 = (int *)piVar1[2];
      }
      piVar1 = piVar2;
    } while (*(char *)((int)piVar2 + 0xd) == '\0');
  }
  if (piVar4 != piVar3) {
    if ((piVar4[5] < (int)param_1[1]) ||
       ((piVar4[5] <= (int)param_1[1] && ((uint)piVar4[4] <= *param_1)))) {
      return (uint *)(piVar4 + 6);
    }
  }
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = 0;
  local_8 = this;
  piVar3 = RBNode_allocSetKey(this,&local_18);
  RBTree_insertNode(this,&param_1,piVar4,(uint *)(piVar3 + 4),piVar3);
  return param_1 + 6;
}




/* [AUDIT] proposed: RBTree_destroyRec  (confidence: high)
 * purpose: Recursively destroys rb-tree nodes, freeing node+0x10 buffer and node; postorder delete
 * vars: param_1=node; +0xd=nil flag; +4=value buf
 */
/* Global::RBTree_destroyRec @ 00402ed0 */

void RBTree_destroyRec(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    RBTree_destroyRec((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if ((void *)param_1[4] != (void *)0x0) {
      operator_delete((void *)param_1[4]);
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
    }
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}




/* [AUDIT] proposed: Vector_destroyTriples  (confidence: high)
 * purpose: Destroys vector of 12-byte {ptr,?,?} elements from param_1 to param_2, deleting first field
 * vars: param_1=begin; param_2=end; stride 3 dwords
 */
/* Global::Vector_destroyTriples @ 00406310 */

void __cdecl Vector_destroyTriples(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 3) {
    if ((void *)*param_1 != (void *)0x0) {
      operator_delete((void *)*param_1);
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
    }
  }
  return;
}




/* [AUDIT] proposed: RBTree_copyBeginThenInc  (confidence: med)
 * purpose: Stores *this into param_1 then advances this via tree successor
 * vars: this=iterator; param_1=out node
 */
/* Global::RBTree_copyBeginThenInc @ 00407a30 */

int * __thiscall RBTree_copyBeginThenInc(void *this,int *param_1)

{
  *param_1 = *(int *)this;
  RBTree_iterIncrement(this);
  return param_1;
}




/* [AUDIT] proposed: RBTree_iterIncrement  (confidence: high)
 * purpose: std::_Rb_tree iterator increment (++): finds in-order successor node
 * vars: param_1=iterator holding node ptr; +0xd=nil flag
 */
/* Global::RBTree_iterIncrement @ 00407a50 */

int * __fastcall RBTree_iterIncrement(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0xd) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0xd);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0xd);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return param_1;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0xd);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0xd);
    }
    *param_1 = iVar2;
  }
  return param_1;
}




/* [AUDIT] proposed: List_allocSentinel0x34  (confidence: med)
 * purpose: Allocates 0x34-byte list node as self-referential sentinel head; +0xc=0x101
 * vars: returns node; self ptrs at 0/4/8
 */
/* Global::List_allocSentinel0x34 @ 00407ad0 */

void List_allocSentinel0x34(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x34);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: List_allocSentinel0x20  (confidence: med)
 * purpose: Allocates 0x20-byte list node as self-referential sentinel head; +0xc=0x101
 * vars: returns node; self ptrs at 0/4/8
 */
/* Global::List_allocSentinel0x20 @ 00407b00 */

void List_allocSentinel0x20(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x20);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: List_allocSentinel0x18  (confidence: med)
 * purpose: Allocates 0x18-byte list node as self-referential sentinel head; +0xc=0x101
 * vars: returns node; self ptrs at 0/4/8
 */
/* Global::List_allocSentinel0x18 @ 00407b30 */

void List_allocSentinel0x18(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: List_allocNode0x134  (confidence: med)
 * purpose: Allocates 0x134-byte list node; sets prev/next links (param_1/param_2 or self)
 * vars: param_1=prev; param_2=next
 */
/* Global::List_allocNode0x134 @ 00407b60 */

void List_allocNode0x134(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x134);
  if (puVar1 != (void *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      param_1 = puVar1;
      param_2 = puVar1;
    }
    *puVar1 = param_1;
    if (puVar1 + 1 != (undefined4 *)0x0) {
      puVar1[1] = param_2;
    }
    return;
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: List_allocNode0x30  (confidence: med)
 * purpose: Allocates 0x30-byte list node; sets prev/next links (param_1/param_2 or self)
 * vars: param_1=prev; param_2=next
 */
/* Global::List_allocNode0x30 @ 00407ba0 */

void List_allocNode0x30(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x30);
  if (puVar1 != (void *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      param_1 = puVar1;
      param_2 = puVar1;
    }
    *puVar1 = param_1;
    if (puVar1 + 1 != (undefined4 *)0x0) {
      puVar1[1] = param_2;
    }
    return;
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: List_allocNode0x14  (confidence: med)
 * purpose: Allocates 0x14-byte list node; sets prev/next links (param_1/param_2 or self)
 * vars: param_1=prev; param_2=next
 */
/* Global::List_allocNode0x14 @ 00407be0 */

void List_allocNode0x14(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x14);
  if (puVar1 != (void *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      param_1 = puVar1;
      param_2 = puVar1;
    }
    *puVar1 = param_1;
    if (puVar1 + 1 != (undefined4 *)0x0) {
      puVar1[1] = param_2;
    }
    return;
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: RBTree_destroyRecursive  (confidence: high)
 * purpose: Recursively destroys a red-black tree/map subtree, freeing each node's embedded std::string then the node
 * vars: param_1=node; +0xd=isNil flag; [2]=right child; [5]=str buf; [10]=str capacity
 */
/* Global::RBTree_destroyRecursive @ 00407c20 */

void RBTree_destroyRecursive(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    RBTree_destroyRecursive((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[10]) {
      operator_delete((void *)param_1[5]);
    }
    param_1[10] = 0xf;
    param_1[9] = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}




/* [AUDIT] proposed: RBTree_eraseNode_plain  (confidence: high)
 * purpose: Erases one RB-tree node (no owned payload), rebalances colors, operator_delete node
 * vars: this=map header; param_2=node; +0xc/+0xd color/nil flags
 */
/* Global::RBTree_eraseNode_plain @ 0040a1d0 */

void __thiscall RBTree_eraseNode_plain(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  piVar1 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar1;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar6 = piVar5;
    if ((*(char *)(piVar1[2] + 0xd) == '\0') && (piVar6 = (int *)param_2[2], param_2 != piVar1)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar1;
      piVar5 = param_2;
      if (param_2 != (int *)piVar1[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar6 + 0xd) == '\0') {
          piVar6[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar6;
        param_2[2] = piVar1[2];
        *(int **)(piVar1[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar1) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar3 = (int *)piVar1[1];
        if ((int *)*piVar3 == piVar1) {
          *piVar3 = (int)param_2;
        }
        else {
          piVar3[2] = (int)param_2;
        }
      }
      param_2[1] = piVar1[1];
      iVar4 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar1[3];
      *(char *)(piVar1 + 3) = (char)iVar4;
      goto LAB_0040a2ee;
    }
  }
  else {
    piVar6 = (int *)piVar1[2];
  }
  piVar5 = (int *)piVar1[1];
  if (*(char *)((int)piVar6 + 0xd) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar1) {
    *(int **)(*(int *)this + 4) = piVar6;
  }
  else if ((int *)*piVar5 == piVar1) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  piVar3 = *(int **)this;
  if ((int *)*piVar3 == piVar1) {
    piVar2 = piVar5;
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      piVar2 = rbtree_min(piVar6);
      piVar3 = *(int **)this;
    }
    *piVar3 = (int)piVar2;
  }
  if (*(int **)(*(int *)this + 8) == piVar1) {
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar6);
      *(int *)(*(int *)this + 8) = iVar4;
    }
    else {
      *(int **)(*(int *)this + 8) = piVar5;
    }
  }
LAB_0040a2ee:
  if ((char)piVar1[3] == '\x01') {
    if (piVar6 != *(int **)(*(int *)this + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[3] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar3 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar3[3];
              *(undefined1 *)(piVar3 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar3);
              break;
            }
LAB_0040a3b2:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar3 + 3) = 0;
            rbtree_rotateLeft(this,piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_0040a3b2;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 3) = (char)piVar3[3];
            *(undefined1 *)(piVar3 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar6 + 3) = 1;
  }
  operator_delete(piVar1);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: vector_reallocate  (confidence: high)
 * purpose: Reallocates a std::vector buffer to param_1 bytes, memmove-copies old contents, frees old, updates ptrs
 * vars: this=vector (begin/end/cap at +0/+4/+8); param_1=new byte capacity
 */
/* Global::vector_reallocate @ 00412b60 */

void __thiscall vector_reallocate(void *this,uint param_1)

{
  void *pvVar1;
  int iVar2;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if ((param_1 != 0) && (_Dst = operator_new(param_1), _Dst == (void *)0x0)) {
    std::_Xbad_alloc();
  }
  memmove(_Dst,*(void **)this,*(int *)((int)this + 4) - (int)*(void **)this);
  pvVar1 = *(void **)this;
  iVar2 = *(int *)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  *(uint *)((int)this + 8) = (int)_Dst + param_1;
  *(void **)this = _Dst;
  *(int *)((int)this + 4) = (int)_Dst + (iVar2 - (int)pvVar1);
  return;
}




/* [AUDIT] proposed: vector_growToFit  (confidence: high)
 * purpose: Ensures vector capacity >= requested; computes 1.5x growth (or requested) then calls reallocate
 * vars: this=vector; param_1=needed extra bytes; +8=cap end
 */
/* Global::vector_growToFit @ 00412bd0 */

void __thiscall vector_growToFit(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)((int)this + 4);
  if (param_1 <= (uint)(*(int *)((int)this + 8) - iVar1)) {
    return;
  }
  iVar2 = *(int *)this;
  if ((iVar2 - iVar1) - 1U < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
  uVar3 = *(int *)((int)this + 8) - iVar2;
  uVar4 = (iVar1 - iVar2) + param_1;
  if (-(uVar3 >> 1) - 1 < uVar3) {
    uVar3 = 0;
    if (uVar4 != 0) {
      uVar3 = uVar4;
    }
    vector_reallocate(this,uVar3);
    return;
  }
  uVar3 = uVar3 + (uVar3 >> 1);
  if (uVar3 < uVar4) {
    uVar3 = uVar4;
  }
  vector_reallocate(this,uVar3);
  return;
}




/* [AUDIT] proposed: vector_resizeZero  (confidence: high)
 * purpose: Resizes a byte vector to param_1: shrinks in place or grows (growToFit) and zero-fills new tail
 * vars: this=vector; param_1=new size
 */
/* Global::vector_resizeZero @ 00413180 */

void __thiscall vector_resizeZero(void *this,uint param_1)

{
  void *_Src;
  void *pvVar1;
  void *_Dst;
  
  _Src = *(void **)((int)this + 4);
  pvVar1 = *(void **)this;
  if (param_1 < (uint)((int)_Src - (int)pvVar1)) {
    _Dst = (void *)(param_1 + (int)pvVar1);
    if (_Dst == pvVar1) {
      *(void **)((int)this + 4) = pvVar1;
      return;
    }
    if (_Dst != _Src) {
      memmove(_Dst,_Src,0);
      *(void **)((int)this + 4) = _Dst;
      return;
    }
  }
  else if ((uint)((int)_Src - (int)pvVar1) < param_1) {
    vector_growToFit(this,(int)pvVar1 + (param_1 - (int)_Src));
    memset(*(void **)((int)this + 4),0,(*(int *)this - (int)*(void **)((int)this + 4)) + param_1);
    *(uint *)((int)this + 4) = *(int *)this + param_1;
  }
  return;
}




/* [AUDIT] proposed: u16string_moveConstruct  (confidence: high)
 * purpose: Move-constructs a std::u16string (2-byte chars, SSO cap 7): steals heap ptr or memmoves inline, resets source
 * vars: this=dst string; param_1=src; +0x10=len; +0x14=capacity
 */
/* Global::u16string_moveConstruct @ 00416a90 */

undefined4 * __thiscall u16string_moveConstruct(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)this = 0;
  if ((uint)param_1[5] < 8) {
    if (param_1[4] + 1 != 0) {
      memmove(this,param_1,(param_1[4] + 1) * 2);
    }
  }
  else {
    *(undefined4 *)this = *param_1;
    *param_1 = 0;
  }
  *(undefined4 *)((int)this + 0x10) = param_1[4];
  *(undefined4 *)((int)this + 0x14) = param_1[5];
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return this;
}




/* [AUDIT] proposed: U16String_ctorFromCStr  (confidence: high)
 * purpose: std::u16string ctor from null-terminated wide C-string; inits SSO capacity then computes length and assigns
 * vars: this+0x14=capacity(=7 SSO); this+0x10=len; param_1=UTF-16 src; length via 2-byte scan
 */
/* Global::U16String_ctorFromCStr @ 00416b00 */

undefined2 * __thiscall U16String_ctorFromCStr(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)this = 0;
  if ((short)*param_1 == 0) {
    U16String_assignPtrCount(this,param_1,0);
    return this;
  }
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  U16String_assignPtrCount(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return this;
}




/* [AUDIT] proposed: U16String_assignFromCStr  (confidence: high)
 * purpose: std::u16string::assign from null-terminated wide C-string; computes length via 2-byte scan then assigns
 * vars: param_1=UTF-16 src; delegates to U16String_assignPtrCount assign(ptr,len)
 */
/* Global::U16String_assignFromCStr @ 00416b90 */

void __thiscall U16String_assignFromCStr(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((short)*param_1 == 0) {
    U16String_assignPtrCount(this,param_1,0);
    return;
  }
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  U16String_assignPtrCount(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return;
}




/* [AUDIT] proposed: U16String_reallocGrow  (confidence: high)
 * purpose: Grows string buffer: computes new capacity (~1.5x, cap 0x7ffffffe), operator_new, memcpy old data, operator_delete old
 * vars: this+0x14=cap; this+0x10=len; param_1=needed; param_2=copy count; SEH frame
 */
/* Global::U16String_reallocGrow @ 00416d60 */

void __thiscall U16String_reallocGrow(void *this,uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  void *_Src;
  uint uVar3;
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054bbf0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 7;
  if (uVar3 < 0x7fffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = uVar2 + uVar1, 0x7ffffffe - uVar2 < uVar1)) {
      param_1 = 0x7ffffffe;
    }
  }
  uVar3 = param_1 + 1;
  local_8 = 0;
  local_18 = (void *)0x0;
  if ((uVar3 != 0) &&
     ((0x7fffffff < uVar3 || (local_18 = operator_new(uVar3 * 2), local_18 == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  if (param_2 != 0) {
    _Src = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      _Src = *(void **)this;
    }
    if (param_2 != 0) {
      memcpy(local_18,_Src,param_2 * 2);
    }
  }
  if (7 < *(uint *)((int)this + 0x14)) {
    operator_delete(*(void **)this);
  }
  *(void **)this = local_18;
  *(uint *)((int)this + 0x14) = param_1;
  *(int *)((int)this + 0x10) = param_2;
  if (7 < param_1) {
    this = local_18;
  }
  *(undefined2 *)((int)this + param_2 * 2) = 0;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: U16String_appendFill  (confidence: high)
 * purpose: std::u16string append/resize by param_1 copies of char param_2; grows if needed, writes NUL terminator
 * vars: this+0x10=len; this+0x14=cap; error 'string too long'
 */
/* Global::U16String_appendFill @ 00417170 */

int * __thiscall U16String_appendFill(void *this,uint param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 0x10);
  if (-iVar2 - 1U <= param_1) {
    std::_Xlength_error("string too long");
  }
  if (param_1 != 0) {
    uVar1 = iVar2 + param_1;
    if (0x7ffffffe < uVar1) {
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      U16String_reallocGrow(this,uVar1,iVar2);
      if (uVar1 == 0) {
        return this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (7 < *(uint *)((int)this + 0x14)) {
        **(undefined2 **)this = 0;
        return this;
      }
      *(undefined2 *)this = 0;
      return this;
    }
    CharTraits_assignFill(this,*(int *)((int)this + 0x10),param_1,param_2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (7 < *(uint *)((int)this + 0x14)) {
      *(undefined2 *)(*(int *)this + uVar1 * 2) = 0;
      return this;
    }
    *(undefined2 *)((int)this + uVar1 * 2) = 0;
  }
  return this;
}




/* [AUDIT] proposed: U16String_assignSubstr  (confidence: high)
 * purpose: std::u16string::assign(other,pos,count); handles self-assign (erase prefix) vs copy; bounds-checked
 * vars: param_1=src str; param_2=pos; param_3=count; param_1[4]=src len; 'invalid string position'
 */
/* Global::U16String_assignSubstr @ 004172f0 */

int * __thiscall U16String_assignSubstr(void *this,int *param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  uint uVar2;
  
  if ((uint)param_1[4] < param_2) {
    std::_Xout_of_range("invalid string position");
  }
  uVar2 = param_1[4] - param_2;
  if (param_3 < uVar2) {
    uVar2 = param_3;
  }
  if (this == param_1) {
    uVar2 = uVar2 + param_2;
    if (*(uint *)((int)this + 0x10) < uVar2) {
      std::_Xout_of_range("invalid string position");
    }
    *(uint *)((int)this + 0x10) = uVar2;
    pvVar1 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar1 = *(void **)this;
    }
    *(undefined2 *)((int)pvVar1 + uVar2 * 2) = 0;
    U16String_erase(this,0,param_2);
    return this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    U16String_reallocGrow(this,uVar2,*(int *)((int)this + 0x10));
    if (uVar2 == 0) {
      return this;
    }
  }
  else if (uVar2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
      **(undefined2 **)this = 0;
      return this;
    }
    *(undefined2 *)this = 0;
    return this;
  }
  if (7 < (uint)param_1[5]) {
    param_1 = (int *)*param_1;
  }
  pvVar1 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    pvVar1 = *(void **)this;
  }
  if (uVar2 != 0) {
    memcpy(pvVar1,(void *)((int)param_1 + param_2 * 2),uVar2 * 2);
  }
  *(uint *)((int)this + 0x10) = uVar2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)((int)this + uVar2 * 2) = 0;
    return this;
  }
  *(undefined2 *)(*(int *)this + uVar2 * 2) = 0;
  return this;
}




/* [AUDIT] proposed: U16String_assignPtrCount  (confidence: high)
 * purpose: std::u16string::assign(ptr,count); detects ptr aliasing own buffer and reroutes to substr-assign, else copies
 * vars: param_1=src ptr; param_2=count; this+0x10/+0x14=len/cap
 */
/* Global::U16String_assignPtrCount @ 00417410 */

int * __thiscall U16String_assignPtrCount(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    piVar3 = this;
    if (7 < uVar1) {
      piVar3 = *(int **)this;
    }
    if (piVar3 <= param_1) {
      pvVar2 = this;
      if (7 < uVar1) {
        pvVar2 = *(void **)this;
      }
      if (param_1 < (int *)((int)pvVar2 + *(int *)((int)this + 0x10) * 2)) {
        pvVar2 = this;
        if (7 < uVar1) {
          pvVar2 = *(void **)this;
        }
        piVar3 = U16String_assignSubstr(this,this,(int)param_1 - (int)pvVar2 >> 1,param_2);
        return piVar3;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    U16String_reallocGrow(this,param_2,*(int *)((int)this + 0x10));
    if (param_2 == 0) {
      return this;
    }
  }
  else if (param_2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
      **(undefined2 **)this = 0;
      return this;
    }
    *(undefined2 *)this = 0;
    return this;
  }
  pvVar2 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    pvVar2 = *(void **)this;
  }
  if (param_2 != 0) {
    memcpy(pvVar2,param_1,param_2 * 2);
  }
  *(uint *)((int)this + 0x10) = param_2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)((int)this + param_2 * 2) = 0;
    return this;
  }
  *(undefined2 *)(*(int *)this + param_2 * 2) = 0;
  return this;
}




/* [AUDIT] proposed: U16String_erase  (confidence: high)
 * purpose: std::u16string::erase(pos,count): memmove tail down or truncate; sets len and NUL terminator
 * vars: param_1=pos; param_2=count; this+0x10=len; this+0x14=cap; 'invalid string position'
 */
/* Global::U16String_erase @ 00417d50 */

int * __thiscall U16String_erase(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
    std::_Xout_of_range("invalid string position");
  }
  if (param_2 < uVar1 - param_1) {
    if (param_2 != 0) {
      pvVar2 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar2 = *(void **)this;
      }
      iVar3 = uVar1 - param_2;
      pvVar2 = (void *)((int)pvVar2 + param_1 * 2);
      if (iVar3 - param_1 != 0) {
        memmove(pvVar2,(void *)((int)pvVar2 + param_2 * 2),(iVar3 - param_1) * 2);
      }
      *(int *)((int)this + 0x10) = iVar3;
      if (7 < *(uint *)((int)this + 0x14)) {
        *(undefined2 *)(*(int *)this + iVar3 * 2) = 0;
        return this;
      }
      *(undefined2 *)((int)this + iVar3 * 2) = 0;
    }
    return this;
  }
  *(uint *)((int)this + 0x10) = param_1;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)((int)this + param_1 * 2) = 0;
    return this;
  }
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return this;
}




/* [AUDIT] proposed: wstring_compareSubstr  (confidence: high)
 * purpose: std::wstring::compare of substring [param_1,+param_2) against buffer param_3/param_4; returns -1/0/1
 * vars: this+0x10=length; this+0x14=capacity (SSO<8 inline); param_3=other buf; param_4=other len
 */
/* Global::wstring_compareSubstr @ 00419ef0 */

uint __thiscall wstring_compareSubstr(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  uint uVar1;
  ushort *puVar2;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    std::_Xout_of_range("invalid string position");
  }
  uVar1 = *(uint *)((int)this + 0x10) - param_1;
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
    this = *(void **)this;
  }
  uVar1 = param_4;
  if (param_2 < param_4) {
    uVar1 = param_2;
  }
  if (uVar1 != 0) {
    puVar2 = (ushort *)((int)this + param_1 * 2);
    do {
      if (*puVar2 != *param_3) {
        uVar1 = (-(uint)(*puVar2 < *param_3) & 0xfffffffe) + 1;
        goto LAB_00419f46;
      }
      puVar2 = puVar2 + 1;
      param_3 = param_3 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  uVar1 = 0;
LAB_00419f46:
  if (uVar1 == 0) {
    if (param_2 < param_4) {
      return 0xffffffff;
    }
    uVar1 = (uint)(param_2 != param_4);
  }
  return uVar1;
}




/* [AUDIT] proposed: wstring_ctorFromSubstr  (confidence: high)
 * purpose: Initializes empty wstring header then assigns substring [param_2,param_3) via U16String_assignSubstr
 * vars: param_1=new wstring; +8=len,+0xa cap=7 SSO init; this=source
 */
/* Global::wstring_ctorFromSubstr @ 00419f90 */

undefined2 * __thiscall wstring_ctorFromSubstr(void *this,undefined2 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  U16String_assignSubstr(param_1,this,param_2,param_3);
  return param_1;
}




/* [AUDIT] proposed: MapNode_allocSentinel40  (confidence: med)
 * purpose: Allocates 0x28-byte RB-tree sentinel node, self-links 3 pointers, +0xc=0x101
 * vars: QuestText map; +0xc=0x101 nil marker
 */
/* Global::MapNode_allocSentinel40 @ 0041a060 */

void MapNode_allocSentinel40(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x28);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: RBTree_eraseNode  (confidence: high)
 * purpose: Removes one node from red-black tree with successor splice and rebalance, then frees node's two wstrings
 * vars: this=map; param_2=node to erase; +0xd nil,+0xc color; this+4=size
 */
/* Global::RBTree_eraseNode @ 0041a240 */

void __thiscall RBTree_eraseNode(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0xd) == '\0') && (piVar7 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar7 + 0xd) == '\0') {
          piVar7[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar7;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar2) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar6 = (int *)piVar2[1];
        if ((int *)*piVar6 == piVar2) {
          *piVar6 = (int)param_2;
        }
        else {
          piVar6[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar2[3];
      *(char *)(piVar2 + 3) = (char)iVar1;
      goto LAB_0041a36c;
    }
  }
  else {
    piVar7 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar7 + 0xd) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar2) {
    *(int **)(*(int *)this + 4) = piVar7;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  piVar6 = *(int **)this;
  if ((int *)*piVar6 == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      piVar3 = rbtree_min(piVar7);
    }
    *piVar6 = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar7);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_0041a36c:
  if ((char)piVar2[3] == '\x01') {
    if (piVar7 != *(int **)(*(int *)this + 4)) {
      do {
        piVar6 = piVar5;
        if ((char)piVar7[3] != '\x01') break;
        piVar5 = (int *)*piVar6;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar6[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar6);
            piVar5 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar6[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar6[3];
              *(undefined1 *)(piVar6 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar6);
              *(undefined1 *)(piVar7 + 3) = 1;
              goto LAB_0041a49e;
            }
LAB_0041a440:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            rbtree_rotateLeft(this,piVar6);
            piVar5 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_0041a440;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar6;
            }
            *(char *)(piVar5 + 3) = (char)piVar6[3];
            *(undefined1 *)(piVar6 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar6);
            *(undefined1 *)(piVar7 + 3) = 1;
            goto LAB_0041a49e;
          }
        }
        piVar5 = (int *)piVar6[1];
        piVar7 = piVar6;
      } while (piVar6 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar7 + 3) = 1;
  }
LAB_0041a49e:
  if (7 < (uint)piVar2[0xf]) {
    operator_delete((void *)piVar2[10]);
  }
  piVar2[0xf] = 7;
  piVar2[0xe] = 0;
  *(undefined2 *)(piVar2 + 10) = 0;
  if (7 < (uint)piVar2[9]) {
    operator_delete((void *)piVar2[4]);
  }
  piVar2[9] = 7;
  piVar2[8] = 0;
  *(undefined2 *)(piVar2 + 4) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: RBTree_buyNodeStr  (confidence: high)
 * purpose: Allocates tree node, default-constructs its wstring, guarded by SEH
 * vars: this=allocator; param_1=source wstring copied into node+0x10
 */
/* Global::RBTree_buyNodeStr @ 0041a5d0 */

undefined4 * __thiscall RBTree_buyNodeStr(void *this,int *param_1)

{
  undefined4 *this_00;
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bc21;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = RBTree_buyNode40(this);
  this_00 = puVar1 + 4;
  *(undefined2 *)(puVar1 + 3) = 0;
  local_8 = 1;
  if (this_00 != (undefined4 *)0x0) {
    puVar1[9] = 7;
    puVar1[8] = 0;
    *(undefined2 *)this_00 = 0;
    U16String_assignSubstr(this_00,param_1,0,0xffffffff);
  }
  ExceptionList = local_10;
  return puVar1;
}




/* [AUDIT] proposed: RBTree_copyRec  (confidence: high)
 * purpose: Recursively deep-copies red-black tree nodes (left/right children, color, parent links)
 * vars: param_1=src node; param_2=parent; recursion via left(*) and right([2])
 */
/* Global::RBTree_copyRec @ 0041a6f0 */

undefined4 * __thiscall
RBTree_copyRec(void *this,undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bc40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = *(undefined4 **)this;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    puVar1 = RBTree_buyNodeStr(this,param_1 + 4);
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_1 + 3);
    if (*(char *)((int)puVar3 + 0xd) != '\0') {
      puVar3 = puVar1;
    }
    local_8 = 0;
    puVar2 = RBTree_copyRec(this,(undefined4 *)*param_1,puVar1,param_3);
    *puVar1 = puVar2;
    puVar2 = RBTree_copyRec(this,(undefined4 *)param_1[2],puVar1,param_3);
    puVar1[2] = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}




/* [AUDIT] proposed: RBTree_insertRebalance  (confidence: high)
 * purpose: Inserts a bought node into RB-tree and performs rotations/recolor to restore invariants
 * vars: this=map; param_2=leftFlag; param_3=parent; param_4=key wstring; +0xc color
 */
/* Global::RBTree_insertRebalance_41a7b0 @ 0041a7b0 */

void __thiscall
RBTree_insertRebalance_41a7b0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (0x6666664 < *(uint *)((int)this + 4)) {
    std::_Xlength_error("map/set<T> too long");
  }
  piVar3 = RBTree_buyNodeStr(this,param_4);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  piVar3[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = piVar3;
    **(undefined4 **)this = piVar3;
    iVar4 = *(int *)this;
  }
  else {
    if (param_2 != '\0') {
      *param_3 = piVar3;
      if (param_3 == (undefined4 *)**(int **)this) {
        **(int **)this = (int)piVar3;
      }
      goto LAB_0041a80e;
    }
    param_3[2] = piVar3;
    iVar4 = *(int *)this;
    if (param_3 != *(undefined4 **)(iVar4 + 8)) goto LAB_0041a80e;
  }
  *(int **)(iVar4 + 8) = piVar3;
LAB_0041a80e:
  cVar1 = *(char *)(piVar3[1] + 0xc);
  piVar5 = piVar3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = piVar3;
      return;
    }
    piVar7 = (int *)piVar5[1];
    piVar6 = *(int **)piVar7[1];
    if (piVar7 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar7[1])[2];
      if ((char)piVar6[3] != '\0') {
        if (piVar5 == (int *)piVar7[2]) {
          piVar5 = (int *)piVar7[2];
          piVar7[2] = *piVar5;
          if (*(char *)(*piVar5 + 0xd) == '\0') {
            *(int **)(*piVar5 + 4) = piVar7;
          }
          piVar5[1] = piVar7[1];
          if (piVar7 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar5;
          }
          else {
            piVar6 = (int *)piVar7[1];
            if (piVar7 == (int *)*piVar6) {
              *piVar6 = (int)piVar5;
            }
            else {
              piVar6[2] = (int)piVar5;
            }
          }
          *piVar5 = (int)piVar7;
          piVar7[1] = (int)piVar5;
          piVar5 = piVar7;
        }
        *(undefined1 *)(piVar5[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
        piVar7 = *(int **)(piVar5[1] + 4);
        piVar6 = (int *)*piVar7;
        *piVar7 = piVar6[2];
        if (*(char *)(piVar6[2] + 0xd) == '\0') {
          *(int **)(piVar6[2] + 4) = piVar7;
        }
        piVar6[1] = piVar7[1];
        if (piVar7 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar6;
          piVar6[2] = (int)piVar7;
        }
        else {
          piVar2 = (int *)piVar7[1];
          if (piVar7 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar6;
            piVar6[2] = (int)piVar7;
          }
          else {
            *piVar2 = (int)piVar6;
            piVar6[2] = (int)piVar7;
          }
        }
        goto LAB_0041a98a;
      }
LAB_0041a8e1:
      *(undefined1 *)(piVar7 + 3) = 1;
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      piVar5 = *(int **)(piVar5[1] + 4);
    }
    else {
      if ((char)piVar6[3] == '\0') goto LAB_0041a8e1;
      if (piVar5 == (int *)*piVar7) {
        iVar4 = *piVar7;
        *piVar7 = *(int *)(iVar4 + 8);
        if (*(char *)(*(int *)(iVar4 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar4 + 8) + 4) = piVar7;
        }
        *(int *)(iVar4 + 4) = piVar7[1];
        if (piVar7 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar4;
        }
        else {
          piVar5 = (int *)piVar7[1];
          if (piVar7 == (int *)piVar5[2]) {
            piVar5[2] = iVar4;
          }
          else {
            *piVar5 = iVar4;
          }
        }
        *(int **)(iVar4 + 8) = piVar7;
        piVar7[1] = iVar4;
        piVar5 = piVar7;
      }
      *(undefined1 *)(piVar5[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      piVar7 = *(int **)(piVar5[1] + 4);
      piVar6 = (int *)piVar7[2];
      piVar7[2] = *piVar6;
      if (*(char *)(*piVar6 + 0xd) == '\0') {
        *(int **)(*piVar6 + 4) = piVar7;
      }
      piVar6[1] = piVar7[1];
      if (piVar7 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar6;
      }
      else {
        piVar2 = (int *)piVar7[1];
        if (piVar7 == (int *)*piVar2) {
          *piVar2 = (int)piVar6;
        }
        else {
          piVar2[2] = (int)piVar6;
        }
      }
      *piVar6 = (int)piVar7;
LAB_0041a98a:
      piVar7[1] = (int)piVar6;
    }
    cVar1 = *(char *)(piVar5[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: wstring_lessCompare  (confidence: high)
 * purpose: Comparator: returns true if key wstring param_2 < stored wstring param_1 (map ordering predicate)
 * vars: param_1=node wstring (+0x10 len); param_2=key wstring; uses compare
 */
/* Global::wstring_lessCompare @ 0041ae40 */

bool wstring_lessCompare(void *param_1,ushort *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_2 + 8);
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(ushort **)param_2;
  }
  uVar2 = wstring_compareSubstr(param_1,0,*(uint *)((int)param_1 + 0x10),param_2,*puVar1);
  return (int)uVar2 < 0;
}




/* [AUDIT] proposed: RBTree_buyNode40  (confidence: med)
 * purpose: Allocates 0x28 tree node and self-initializes its 3 link pointers from template
 * vars: param_1=template node whose *ptr used to init links
 */
/* Global::RBTree_buyNode40 @ 0041af30 */

undefined4 * __fastcall RBTree_buyNode40(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: list_emplaceCopy40  (confidence: med)
 * purpose: Inserts list node and copies 40-byte (5 qword) payload into node+8
 * vars: param_1/2=list ends; param_3=5-qword source
 */
/* Global::list_emplaceCopy40 @ 00420080 */

void list_emplaceCopy40(undefined4 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = List_allocNode0x30(param_1,param_2);
  if ((undefined8 *)(iVar1 + 8) != (undefined8 *)0x0) {
    *(undefined8 *)(iVar1 + 8) = *param_3;
    *(undefined8 *)(iVar1 + 0x10) = param_3[1];
    *(undefined8 *)(iVar1 + 0x18) = param_3[2];
    *(undefined8 *)(iVar1 + 0x20) = param_3[3];
    *(undefined8 *)(iVar1 + 0x28) = param_3[4];
  }
  return;
}




/* [AUDIT] proposed: list_emplaceCopy24  (confidence: med)
 * purpose: Inserts list node and copies 24-byte (3 qword) payload into node+8
 * vars: param_1/2=list ends; param_3=3-qword source
 */
/* Global::list_emplaceCopy24 @ 004203c0 */

void list_emplaceCopy24(undefined4 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = std_List_node_alloc_0x20(param_1,param_2);
  if ((undefined8 *)(iVar1 + 8) != (undefined8 *)0x0) {
    *(undefined8 *)(iVar1 + 8) = *param_3;
    *(undefined8 *)(iVar1 + 0x10) = param_3[1];
    *(undefined8 *)(iVar1 + 0x18) = param_3[2];
  }
  return;
}




/* [AUDIT] proposed: list_destroyWstrings  (confidence: high)
 * purpose: Clears a list of nodes each holding a wstring (offset 0x10), freeing string then node
 * vars: param_1=list head; node+0x10..0x24 wstring
 */
/* Global::list_destroyWstrings @ 00428100 */

void __fastcall list_destroyWstrings(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      if (7 < (uint)piVar2[9]) {
        operator_delete((void *)piVar2[4]);
      }
      piVar2[9] = 7;
      piVar2[8] = 0;
      *(undefined2 *)(piVar2 + 4) = 0;
      operator_delete(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}




/* [AUDIT] proposed: std_map_Speech_allocPairNode  (confidence: med)
 * purpose: Allocates 0x40 map node (via 42cf80) and default-constructs two std::strings (+0x10,+0x28) copying key/value; std::map node, not game_misc
 * vars: node 0x40; +0xc color/nil; +0x10 & +0x28 std::string (cap at +0x18/+0x30)
 */
/* Global::std_map_Speech_allocPairNode @ 004290d0 */

undefined4 * __thiscall std_map_Speech_allocPairNode(void *this,int *param_1)

{
  undefined4 *this_00;
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054caa9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = std_map_allocRawNode_0x40(this);
  this_00 = puVar1 + 4;
  *(undefined2 *)(puVar1 + 3) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (this_00 != (undefined4 *)0x0) {
    puVar1[9] = 7;
    puVar1[8] = 0;
    *(undefined2 *)this_00 = 0;
    U16String_assignSubstr(this_00,param_1,0,0xffffffff);
    puVar1[0xf] = 7;
    puVar1[0xe] = 0;
    *(undefined2 *)(puVar1 + 10) = 0;
    local_8 = CONCAT31(local_8._1_3_,2);
    U16String_assignSubstr(puVar1 + 10,param_1 + 6,0,0xffffffff);
  }
  ExceptionList = local_10;
  return puVar1;
}




/* [AUDIT] proposed: std_list_Speech_makeStrNode  (confidence: med)
 * purpose: Allocates list node (via 4f7b60) and inits one std::string at node+8; std::list<string> node builder
 * vars: iVar1+8 string; +0x18 len +0x1c cap
 */
/* Global::std_list_Speech_makeStrNode @ 004291a0 */

int std_list_Speech_makeStrNode(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined2 *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cae1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = std_List_node_alloc_0x20(param_1,param_2);
  this = (undefined2 *)(iVar1 + 8);
  local_8 = 1;
  if (this != (undefined2 *)0x0) {
    *(undefined4 *)(iVar1 + 0x1c) = 7;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *this = 0;
    U16String_assignSubstr(this,param_3,0,0xffffffff);
  }
  ExceptionList = local_10;
  return iVar1;
}




/* [AUDIT] proposed: std_map_allocNode_intKeyStr  (confidence: med)
 * purpose: Allocates 0x2c map node (42cf00); sets int key at +0x10 and constructs std::string at +0x14; std::map node ctor
 * vars: node 0x2c; +4=int key; +5 word=string
 */
/* Global::std_map_allocNode_intKeyStr @ 00429240 */

undefined4 * __thiscall std_map_allocNode_intKeyStr(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_map_allocRawNode_0x2c(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    puVar1[4] = *param_1;
    u16string_moveConstruct(puVar1 + 5,param_1 + 1);
  }
  return puVar1;
}




/* [AUDIT] proposed: std_map_Speech_allocEntryNode  (confidence: med)
 * purpose: Allocates 0x38 map node (42cf40); copies string key (+4) and two sub-containers via 42b040/42b180; Speech map entry node
 * vars: node 0x38; +4 string; +0x10 list; +0x18 strlist
 */
/* Global::std_map_Speech_allocEntryNode @ 00429280 */

undefined4 * __thiscall std_map_Speech_allocEntryNode(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cb21;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = std_map_allocRawNode_0x38(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    u16string_moveConstruct(puVar1 + 4,param_1);
    local_8._0_1_ = 2;
    std_list_copyCtor(puVar1 + 10,param_1 + 6);
    local_8 = CONCAT31(local_8._1_3_,3);
    std_list_copyCtor_strList(puVar1 + 0xc,param_1 + 8);
  }
  ExceptionList = local_10;
  return puVar1;
}




/* [AUDIT] proposed: std_map_allocNode_str2  (confidence: med)
 * purpose: Allocates 0x40 map node (42cf80) and copies two std::strings (+0x10,+0x28) via 416a90; std::map<string,string> node
 * vars: node 0x40; +0x10/+0x28 strings
 */
/* Global::std_map_allocNode_str2 @ 00429340 */

undefined4 * __thiscall std_map_allocNode_str2(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_map_allocRawNode_0x40(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    u16string_moveConstruct(puVar1 + 4,param_1);
    u16string_moveConstruct(puVar1 + 10,param_1 + 6);
  }
  return puVar1;
}




/* [AUDIT] proposed: std_map_copyAssign  (confidence: med)
 * purpose: Clones a whole RB-tree into this (recursive 4294b0) then fixes leftmost/rightmost header links; std::map copy
 * vars: this=header; +4 size; node+0xd nil flag
 */
/* Global::std_map_copyAssign @ 00429430 */

void __thiscall std_map_copyAssign(void *this,int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  iVar2 = *(int *)this;
  puVar7 = rbtree_cloneSubtree(this,*(undefined4 **)(*param_1 + 4),iVar2,param_2);
  *(undefined4 **)(iVar2 + 4) = puVar7;
  piVar3 = *(int **)this;
  *(int *)((int)this + 4) = param_1[1];
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0xd) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)this + 8) = *(int *)this;
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0xd);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0xd);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)this + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0xd);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)this + 8) = iVar2;
  return;
}




/* [AUDIT] proposed: rbtree_cloneSubtree  (confidence: high)
 * purpose: Recursively deep-copies RB-tree nodes (left via *node, right via node[2]) allocating via 4290d0; std::map clone helper
 * vars: node+0xd nil; +0xc color; [0]/[2] left/right
 */
/* Global::rbtree_cloneSubtree @ 004294b0 */

undefined4 * __thiscall
rbtree_cloneSubtree(void *this,undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cb80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = *(undefined4 **)this;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    puVar1 = std_map_Speech_allocPairNode(this,param_1 + 4);
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_1 + 3);
    if (*(char *)((int)puVar3 + 0xd) != '\0') {
      puVar3 = puVar1;
    }
    local_8 = 0;
    puVar2 = rbtree_cloneSubtree(this,(undefined4 *)*param_1,puVar1,param_3);
    *puVar1 = puVar2;
    puVar2 = rbtree_cloneSubtree(this,(undefined4 *)param_1[2],puVar1,param_3);
    puVar1[2] = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}




/* [AUDIT] proposed: std_map_insertRebalance_str2  (confidence: high)
 * purpose: RB-tree insert fixup with red/black rotations; overflow throws _Xlength_error 'map/set<T> too long'; frees 2-str node; std::map
 * vars: this+4=count (max 0x5d1745b); node+0xc color +0xd nil
 */
/* Global::std_map_insertRebalance_str2 @ 00429570 */

void __thiscall
std_map_insertRebalance_str2(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x5d1745b < *(uint *)((int)this + 4)) {
    if (7 < (uint)param_5[10]) {
      operator_delete((void *)param_5[5]);
    }
    param_5[10] = 7;
    param_5[9] = 0;
    *(undefined2 *)(param_5 + 5) = 0;
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_0042977a;
      }
LAB_004296d1:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004296d1;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_0042977a:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std_map_insertRebalance_SpeechNode  (confidence: high)
 * purpose: RB-tree insert fixup (rotations); overflow cleans Speech node via 42c2e0; std::map 'map/set<T> too long'
 * vars: max 0x4924922; node+0xc color
 */
/* Global::std_map_insertRebalance_SpeechNode @ 004297a0 */

void __thiscall
std_map_insertRebalance_SpeechNode(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x4924922 < *(uint *)((int)this + 4)) {
    Speech_mapNode_dtor(param_5 + 4);
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] == '\0') goto LAB_004298e1;
      if (piVar4 == (int *)piVar6[2]) {
        piVar4 = (int *)piVar6[2];
        piVar6[2] = *piVar4;
        if (*(char *)(*piVar4 + 0xd) == '\0') {
          *(int **)(*piVar4 + 4) = piVar6;
        }
        piVar4[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar4;
        }
        else {
          piVar5 = (int *)piVar6[1];
          if (piVar6 == (int *)*piVar5) {
            *piVar5 = (int)piVar4;
          }
          else {
            piVar5[2] = (int)piVar4;
          }
        }
        *piVar4 = (int)piVar6;
        piVar6[1] = (int)piVar4;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)*piVar6;
      *piVar6 = piVar5[2];
      if (*(char *)(piVar5[2] + 0xd) == '\0') {
        *(int **)(piVar5[2] + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
        piVar5[2] = (int)piVar6;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)piVar2[2]) {
          piVar2[2] = (int)piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          *piVar2 = (int)piVar5;
          piVar5[2] = (int)piVar6;
        }
      }
LAB_0042998a:
      piVar6[1] = (int)piVar5;
    }
    else {
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)*piVar6) {
          iVar3 = *piVar6;
          *piVar6 = *(int *)(iVar3 + 8);
          if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
            *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
          }
          *(int *)(iVar3 + 4) = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int *)(*(int *)this + 4) = iVar3;
          }
          else {
            piVar4 = (int *)piVar6[1];
            if (piVar6 == (int *)piVar4[2]) {
              piVar4[2] = iVar3;
            }
            else {
              *piVar4 = iVar3;
            }
          }
          *(int **)(iVar3 + 8) = piVar6;
          piVar6[1] = iVar3;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)piVar6[2];
        piVar6[2] = *piVar5;
        if (*(char *)(*piVar5 + 0xd) == '\0') {
          *(int **)(*piVar5 + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)*piVar2) {
            *piVar2 = (int)piVar5;
          }
          else {
            piVar2[2] = (int)piVar5;
          }
        }
        *piVar5 = (int)piVar6;
        goto LAB_0042998a;
      }
LAB_004298e1:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std_map_insertRebalance_variantC  (confidence: high)
 * purpose: RB-tree insert fixup; overflow cleans node via 42d060; std::map insert rebalance
 * vars: max 0x3fffffd; node payload freed by 42d060
 */
/* Global::std_map_insertRebalance_variantC @ 004299b0 */

void __thiscall
std_map_insertRebalance_variantC(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x3fffffd < *(uint *)((int)this + 4)) {
    node_free_twoStrings(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_00429b8e;
      }
LAB_00429ae5:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_00429ae5;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_00429b8e:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std_map_insertRebalance_QuestText  (confidence: high)
 * purpose: RB-tree insert fixup; overflow cleans QuestText node (ctor_3 + string) then throws; std::map
 * vars: max 0x4924922; node+0x28 QuestText, +0x10 string
 */
/* Global::std_map_insertRebalance_QuestText @ 00429bc0 */

void __thiscall
std_map_insertRebalance_QuestText(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054cba8;
  local_10 = ExceptionList;
  if (0x4924922 < *(uint *)((int)this + 4)) {
    local_8 = 0;
    ExceptionList = &local_10;
    cube::QuestText::ctor_3(param_5 + 10);
    local_8 = 0xffffffff;
    if (7 < (uint)param_5[9]) {
      operator_delete((void *)param_5[4]);
    }
    param_5[9] = 7;
    param_5[8] = 0;
    *(undefined2 *)(param_5 + 4) = 0;
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] == '\0') goto LAB_00429d57;
      if (piVar4 == (int *)piVar6[2]) {
        piVar4 = (int *)piVar6[2];
        piVar6[2] = *piVar4;
        if (*(char *)(*piVar4 + 0xd) == '\0') {
          *(int **)(*piVar4 + 4) = piVar6;
        }
        piVar4[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar4;
        }
        else {
          piVar5 = (int *)piVar6[1];
          if (piVar6 == (int *)*piVar5) {
            *piVar5 = (int)piVar4;
          }
          else {
            piVar5[2] = (int)piVar4;
          }
        }
        *piVar4 = (int)piVar6;
        piVar6[1] = (int)piVar4;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)*piVar6;
      *piVar6 = piVar5[2];
      if (*(char *)(piVar5[2] + 0xd) == '\0') {
        *(int **)(piVar5[2] + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
        piVar5[2] = (int)piVar6;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)piVar2[2]) {
          piVar2[2] = (int)piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          *piVar2 = (int)piVar5;
          piVar5[2] = (int)piVar6;
        }
      }
LAB_00429e00:
      piVar6[1] = (int)piVar5;
    }
    else {
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)*piVar6) {
          iVar3 = *piVar6;
          *piVar6 = *(int *)(iVar3 + 8);
          if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
            *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
          }
          *(int *)(iVar3 + 4) = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int *)(*(int *)this + 4) = iVar3;
          }
          else {
            piVar4 = (int *)piVar6[1];
            if (piVar6 == (int *)piVar4[2]) {
              piVar4[2] = iVar3;
            }
            else {
              *piVar4 = iVar3;
            }
          }
          *(int **)(iVar3 + 8) = piVar6;
          piVar6[1] = iVar3;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)piVar6[2];
        piVar6[2] = *piVar5;
        if (*(char *)(*piVar5 + 0xd) == '\0') {
          *(int **)(*piVar5 + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)*piVar2) {
            *piVar2 = (int)piVar5;
          }
          else {
            piVar2[2] = (int)piVar5;
          }
        }
        *piVar5 = (int)piVar6;
        goto LAB_00429e00;
      }
LAB_00429d57:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std_map_insertHint_intKey  (confidence: high)
 * purpose: Chooses insert side vs hint using int-key compare (07a50/dad80 = ++/--) then calls 429570; std::map hinted insert
 * vars: param_3=&intKey; node+0x10=key(word4)
 */
/* Global::std_map_insertHint_intKey @ 00429e40 */

undefined4 * __thiscall
std_map_insertHint_intKey(void *this,undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  bool bVar6;
  uint uStack_34;
  undefined4 local_24;
  void *local_20;
  int local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054cbd0;
  local_10 = ExceptionList;
  uStack_34 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = this;
  if (*(int *)((int)this + 4) == 0) {
    local_14 = (undefined1 *)&uStack_34;
    std_map_insertRebalance_str2(this,param_1,'\x01',*(undefined4 **)this,param_3,param_4);
    ExceptionList = local_10;
    return param_1;
  }
  piVar1 = *(int **)this;
  if (param_2 == (int *)*piVar1) {
    local_14 = (undefined1 *)&uStack_34;
    if (*param_3 < param_2[4]) {
      local_14 = (undefined1 *)&uStack_34;
      std_map_insertRebalance_str2(this,param_1,'\x01',param_2,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    local_14 = (undefined1 *)&uStack_34;
    if ((int)((undefined4 *)piVar1[2])[4] < *param_3) {
      local_14 = (undefined1 *)&uStack_34;
      std_map_insertRebalance_str2(this,param_1,'\0',(undefined4 *)piVar1[2],param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    iVar2 = param_2[4];
    local_1c = *param_3;
    bVar6 = SBORROW4(iVar2,local_1c);
    iVar3 = iVar2 - local_1c;
    puVar4 = &uStack_34;
    if (local_1c < iVar2) {
      local_18 = param_2;
      std_Rb_tree_increment((int *)&local_18);
      if (local_18[4] < local_1c) {
        if (*(char *)(local_18[2] + 0xd) != '\0') {
          std_map_insertRebalance_str2(this,param_1,'\0',local_18,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_map_insertRebalance_str2(this,param_1,'\x01',param_2,param_3,param_4);
        ExceptionList = local_10;
        return param_1;
      }
      bVar6 = SBORROW4(param_2[4],local_1c);
      iVar3 = param_2[4] - local_1c;
      puVar4 = (uint *)local_14;
    }
    local_14 = (undefined1 *)puVar4;
    if (bVar6 != iVar3 < 0) {
      local_18 = param_2;
      RBTree_iterIncrement((int *)&local_18);
      if ((local_18 == piVar1) || (local_1c < local_18[4])) {
        if (*(char *)(param_2[2] + 0xd) != '\0') {
          std_map_insertRebalance_str2(this,param_1,'\0',param_2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_map_insertRebalance_str2(this,param_1,'\x01',local_18,param_3,param_4);
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
  local_8 = 0xffffffff;
  puVar5 = (undefined4 *)std_map_insertLowerBound_intKey(this,&local_24,'\0',param_3,param_4);
  *param_1 = *puVar5;
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std_map_insertHint_strKey  (confidence: high)
 * purpose: Hinted map insert with std::string-key compare (419ef0); falls back to 4c7c50/4c6d20; std::map, not game_misc
 * vars: str at node+8, len +0x10, cap +0x12
 */
/* Global::std_map_insertHint_strKey @ 0042a070 */

undefined4 * __thiscall
std_map_insertHint_strKey(void *this,undefined4 *param_1,ushort *param_2,ushort *param_3,int *param_4)

{
  ushort *puVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uStack_2c;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_3;
  puStack_c = &LAB_0054cbf0;
  local_10 = ExceptionList;
  uStack_2c = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    puVar4 = *(ushort **)this;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    puVar5 = *(ushort **)this;
    puVar4 = param_2;
    if (param_2 != *(ushort **)puVar5) {
      if (param_2 == puVar5) {
        puVar4 = param_3;
        if (7 < *(uint *)(param_3 + 10)) {
          puVar4 = *(ushort **)param_3;
        }
        local_14 = (undefined1 *)&uStack_2c;
        uVar3 = wstring_compareSubstr((void *)(*(int *)(puVar5 + 4) + 0x10),0,
                             *(uint *)(*(int *)(puVar5 + 4) + 0x20),puVar4,*(uint *)(param_3 + 8));
        if (-1 < (int)uVar3) goto LAB_0042a211;
        puVar4 = *(ushort **)(*(int *)this + 8);
        cVar7 = '\0';
        goto LAB_0042a0b9;
      }
      puVar5 = param_2 + 8;
      if (7 < *(uint *)(param_2 + 0x12)) {
        puVar5 = *(ushort **)puVar5;
      }
      uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
      if ((int)uVar3 < 0) {
        param_3 = param_2;
        std_Rb_tree_increment((int *)&param_3);
        puVar5 = param_3;
        bVar2 = wstring_lessCompare(param_3 + 8,puVar1);
        if (!bVar2) goto LAB_0042a1b6;
        if (*(char *)(*(int *)(puVar5 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a0b9;
        }
      }
      else {
LAB_0042a1b6:
        bVar2 = wstring_lessCompare(param_2 + 8,puVar1);
        if (!bVar2) {
LAB_0042a211:
          local_8 = 0xffffffff;
          puVar6 = (undefined4 *)std_Tree_Insert_nohint_str(this,&local_1c,(undefined4 *)0x0,puVar1,param_4);
          *param_1 = *puVar6;
          ExceptionList = local_10;
          return param_1;
        }
        param_3 = param_2;
        RBTree_iterIncrement((int *)&param_3);
        puVar4 = param_3;
        if ((param_3 != (ushort *)*local_18) &&
           (bVar2 = wstring_lessCompare(puVar1,param_3 + 8), this = local_18, !bVar2)) goto LAB_0042a211;
        this = local_18;
        puVar5 = param_2;
        if (*(char *)(*(int *)(param_2 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a0b9;
        }
      }
      cVar7 = '\0';
      puVar4 = puVar5;
      goto LAB_0042a0b9;
    }
    puVar5 = param_2 + 8;
    if (7 < *(uint *)(param_2 + 0x12)) {
      puVar5 = *(ushort **)puVar5;
    }
    local_14 = (undefined1 *)&uStack_2c;
    uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
    if (-1 < (int)uVar3) goto LAB_0042a211;
  }
  cVar7 = '\x01';
LAB_0042a0b9:
  std_Tree_Rebalance_strkey2(this,param_1,cVar7,(undefined4 *)puVar4,puVar1,param_4);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std_map_insertHint_strKey_Speech  (confidence: high)
 * purpose: Same hinted string-key map insert; uses 4297a0/42a970 (Speech node); std::map
 * vars: as 42a070
 */
/* Global::std_map_insertHint_strKey_Speech @ 0042a260 */

undefined4 * __thiscall
std_map_insertHint_strKey_Speech(void *this,undefined4 *param_1,ushort *param_2,ushort *param_3,int *param_4)

{
  ushort *puVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uStack_2c;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_3;
  puStack_c = &LAB_0054cc10;
  local_10 = ExceptionList;
  uStack_2c = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    puVar4 = *(ushort **)this;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    puVar5 = *(ushort **)this;
    puVar4 = param_2;
    if (param_2 != *(ushort **)puVar5) {
      if (param_2 == puVar5) {
        puVar4 = param_3;
        if (7 < *(uint *)(param_3 + 10)) {
          puVar4 = *(ushort **)param_3;
        }
        local_14 = (undefined1 *)&uStack_2c;
        uVar3 = wstring_compareSubstr((void *)(*(int *)(puVar5 + 4) + 0x10),0,
                             *(uint *)(*(int *)(puVar5 + 4) + 0x20),puVar4,*(uint *)(param_3 + 8));
        if (-1 < (int)uVar3) goto LAB_0042a401;
        puVar4 = *(ushort **)(*(int *)this + 8);
        cVar7 = '\0';
        goto LAB_0042a2a9;
      }
      puVar5 = param_2 + 8;
      if (7 < *(uint *)(param_2 + 0x12)) {
        puVar5 = *(ushort **)puVar5;
      }
      uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
      if ((int)uVar3 < 0) {
        param_3 = param_2;
        std_Rb_tree_increment((int *)&param_3);
        puVar5 = param_3;
        bVar2 = wstring_lessCompare(param_3 + 8,puVar1);
        if (!bVar2) goto LAB_0042a3a6;
        if (*(char *)(*(int *)(puVar5 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a2a9;
        }
      }
      else {
LAB_0042a3a6:
        bVar2 = wstring_lessCompare(param_2 + 8,puVar1);
        if (!bVar2) {
LAB_0042a401:
          local_8 = 0xffffffff;
          puVar6 = (undefined4 *)std_map_insertLowerBound_strKey_Speech(this,&local_1c,(undefined4 *)0x0,puVar1,param_4);
          *param_1 = *puVar6;
          ExceptionList = local_10;
          return param_1;
        }
        param_3 = param_2;
        RBTree_iterIncrement((int *)&param_3);
        puVar4 = param_3;
        if ((param_3 != (ushort *)*local_18) &&
           (bVar2 = wstring_lessCompare(puVar1,param_3 + 8), this = local_18, !bVar2)) goto LAB_0042a401;
        this = local_18;
        puVar5 = param_2;
        if (*(char *)(*(int *)(param_2 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a2a9;
        }
      }
      cVar7 = '\0';
      puVar4 = puVar5;
      goto LAB_0042a2a9;
    }
    puVar5 = param_2 + 8;
    if (7 < *(uint *)(param_2 + 0x12)) {
      puVar5 = *(ushort **)puVar5;
    }
    local_14 = (undefined1 *)&uStack_2c;
    uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
    if (-1 < (int)uVar3) goto LAB_0042a401;
  }
  cVar7 = '\x01';
LAB_0042a2a9:
  std_map_insertRebalance_SpeechNode(this,param_1,cVar7,(undefined4 *)puVar4,puVar1,param_4);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std_map_insertHint_strKey_variantC  (confidence: high)
 * purpose: Hinted string-key map insert; uses 4299b0/42aae0; std::map
 * vars: as 42a070
 */
/* Global::std_map_insertHint_strKey_variantC @ 0042a450 */

undefined4 * __thiscall
std_map_insertHint_strKey_variantC(void *this,undefined4 *param_1,ushort *param_2,ushort *param_3,int *param_4)

{
  ushort *puVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uStack_2c;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_3;
  puStack_c = &LAB_0054cc30;
  local_10 = ExceptionList;
  uStack_2c = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    puVar4 = *(ushort **)this;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    puVar5 = *(ushort **)this;
    puVar4 = param_2;
    if (param_2 != *(ushort **)puVar5) {
      if (param_2 == puVar5) {
        puVar4 = param_3;
        if (7 < *(uint *)(param_3 + 10)) {
          puVar4 = *(ushort **)param_3;
        }
        local_14 = (undefined1 *)&uStack_2c;
        uVar3 = wstring_compareSubstr((void *)(*(int *)(puVar5 + 4) + 0x10),0,
                             *(uint *)(*(int *)(puVar5 + 4) + 0x20),puVar4,*(uint *)(param_3 + 8));
        if (-1 < (int)uVar3) goto LAB_0042a5f1;
        puVar4 = *(ushort **)(*(int *)this + 8);
        cVar7 = '\0';
        goto LAB_0042a499;
      }
      puVar5 = param_2 + 8;
      if (7 < *(uint *)(param_2 + 0x12)) {
        puVar5 = *(ushort **)puVar5;
      }
      uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
      if ((int)uVar3 < 0) {
        param_3 = param_2;
        std_Rb_tree_increment((int *)&param_3);
        puVar5 = param_3;
        bVar2 = wstring_lessCompare(param_3 + 8,puVar1);
        if (!bVar2) goto LAB_0042a596;
        if (*(char *)(*(int *)(puVar5 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a499;
        }
      }
      else {
LAB_0042a596:
        bVar2 = wstring_lessCompare(param_2 + 8,puVar1);
        if (!bVar2) {
LAB_0042a5f1:
          local_8 = 0xffffffff;
          puVar6 = (undefined4 *)std_map_insertLowerBound_strKey_variantC(this,&local_1c,(undefined4 *)0x0,puVar1,param_4);
          *param_1 = *puVar6;
          ExceptionList = local_10;
          return param_1;
        }
        param_3 = param_2;
        RBTree_iterIncrement((int *)&param_3);
        puVar4 = param_3;
        if ((param_3 != (ushort *)*local_18) &&
           (bVar2 = wstring_lessCompare(puVar1,param_3 + 8), this = local_18, !bVar2)) goto LAB_0042a5f1;
        this = local_18;
        puVar5 = param_2;
        if (*(char *)(*(int *)(param_2 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a499;
        }
      }
      cVar7 = '\0';
      puVar4 = puVar5;
      goto LAB_0042a499;
    }
    puVar5 = param_2 + 8;
    if (7 < *(uint *)(param_2 + 0x12)) {
      puVar5 = *(ushort **)puVar5;
    }
    local_14 = (undefined1 *)&uStack_2c;
    uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
    if (-1 < (int)uVar3) goto LAB_0042a5f1;
  }
  cVar7 = '\x01';
LAB_0042a499:
  std_map_insertRebalance_variantC(this,param_1,cVar7,(undefined4 *)puVar4,puVar1,param_4);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std_map_insertHint_strKey_QuestText  (confidence: high)
 * purpose: Hinted string-key map insert; uses 42ac40/429bc0 (QuestText node); std::map
 * vars: as 42a070
 */
/* Global::std_map_insertHint_strKey_QuestText @ 0042a640 */

undefined4 * __thiscall
std_map_insertHint_strKey_QuestText(void *this,undefined4 *param_1,ushort *param_2,ushort *param_3,int *param_4)

{
  ushort *puVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uStack_2c;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_3;
  puStack_c = &LAB_0054cc50;
  local_10 = ExceptionList;
  uStack_2c = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    puVar4 = *(ushort **)this;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    puVar5 = *(ushort **)this;
    puVar4 = param_2;
    if (param_2 != *(ushort **)puVar5) {
      if (param_2 == puVar5) {
        puVar4 = param_3;
        if (7 < *(uint *)(param_3 + 10)) {
          puVar4 = *(ushort **)param_3;
        }
        local_14 = (undefined1 *)&uStack_2c;
        uVar3 = wstring_compareSubstr((void *)(*(int *)(puVar5 + 4) + 0x10),0,
                             *(uint *)(*(int *)(puVar5 + 4) + 0x20),puVar4,*(uint *)(param_3 + 8));
        if (-1 < (int)uVar3) goto LAB_0042a7e1;
        puVar4 = *(ushort **)(*(int *)this + 8);
        cVar7 = '\0';
        goto LAB_0042a689;
      }
      puVar5 = param_2 + 8;
      if (7 < *(uint *)(param_2 + 0x12)) {
        puVar5 = *(ushort **)puVar5;
      }
      uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
      if ((int)uVar3 < 0) {
        param_3 = param_2;
        std_Rb_tree_increment((int *)&param_3);
        puVar5 = param_3;
        bVar2 = wstring_lessCompare(param_3 + 8,puVar1);
        if (!bVar2) goto LAB_0042a786;
        if (*(char *)(*(int *)(puVar5 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a689;
        }
      }
      else {
LAB_0042a786:
        bVar2 = wstring_lessCompare(param_2 + 8,puVar1);
        if (!bVar2) {
LAB_0042a7e1:
          local_8 = 0xffffffff;
          puVar6 = (undefined4 *)std_map_insertLowerBound_strKey_QuestText(this,&local_1c,(undefined4 *)0x0,puVar1,param_4);
          *param_1 = *puVar6;
          ExceptionList = local_10;
          return param_1;
        }
        param_3 = param_2;
        RBTree_iterIncrement((int *)&param_3);
        puVar4 = param_3;
        if ((param_3 != (ushort *)*local_18) &&
           (bVar2 = wstring_lessCompare(puVar1,param_3 + 8), this = local_18, !bVar2)) goto LAB_0042a7e1;
        this = local_18;
        puVar5 = param_2;
        if (*(char *)(*(int *)(param_2 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_0042a689;
        }
      }
      cVar7 = '\0';
      puVar4 = puVar5;
      goto LAB_0042a689;
    }
    puVar5 = param_2 + 8;
    if (7 < *(uint *)(param_2 + 0x12)) {
      puVar5 = *(ushort **)puVar5;
    }
    local_14 = (undefined1 *)&uStack_2c;
    uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
    if (-1 < (int)uVar3) goto LAB_0042a7e1;
  }
  cVar7 = '\x01';
LAB_0042a689:
  std_map_insertRebalance_QuestText(this,param_1,cVar7,(undefined4 *)puVar4,puVar1,param_4);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std_map_insertLowerBound_intKey  (confidence: high)
 * purpose: Walks tree by int key to find insert slot; frees dup node or calls 429570; std::map _Insert_hint
 * vars: local_18=less; param_5=node
 */
/* Global::std_map_insertLowerBound_intKey @ 0042a830 */

void __thiscall std_map_insertLowerBound_intKey(void *this,undefined4 *param_1,char param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_3;
  puStack_c = &LAB_0054cc70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar4 = *(undefined4 **)this;
  local_8 = 0;
  local_18 = true;
  if (*(char *)((int)puVar4[1] + 0xd) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if (param_2 == '\0') {
        local_18 = *param_3 < (int)puVar4[4];
      }
      else {
        local_18 = *param_3 <= (int)puVar4[4];
      }
      if (local_18 == false) {
        puVar3 = (undefined4 *)puVar4[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar4;
      }
    } while (*(char *)((int)puVar3 + 0xd) == '\0');
  }
  _param_2 = puVar4;
  if (local_18) {
    if (puVar4 == (undefined4 *)**(int **)this) {
      local_18 = true;
      goto LAB_0042a8c1;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  piVar2 = param_4;
  puVar3 = _param_2;
  if (*piVar1 <= (int)_param_2[4]) {
    if (7 < (uint)param_4[10]) {
      operator_delete((void *)param_4[5]);
    }
    piVar2[10] = 7;
    piVar2[9] = 0;
    *(undefined2 *)(piVar2 + 5) = 0;
    operator_delete(piVar2);
    *param_1 = puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_0042a8c1:
  puVar4 = (undefined4 *)std_map_insertRebalance_str2(this,(undefined4 *)&param_2,local_18,puVar4,piVar1,param_4);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std_map_insertLowerBound_strKey_Speech  (confidence: high)
 * purpose: Walks tree by string key (419ef0) to insert slot; dup frees Speech node (42c2e0); std::map
 * vars: param_2 low byte=direction flag
 */
/* Global::std_map_insertLowerBound_strKey_Speech @ 0042a970 */

void __thiscall
std_map_insertLowerBound_strKey_Speech(void *this,undefined4 *param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  ushort *this_00;
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  this_00 = param_3;
  puStack_c = &LAB_0054cc90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = true;
  puVar3 = *(undefined4 **)this;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  while (*(char *)((int)puVar5 + 0xd) == '\0') {
    if ((char)param_2 == '\0') {
      puVar4 = (ushort *)(puVar5 + 4);
      if (7 < (uint)puVar5[9]) {
        puVar4 = *(ushort **)puVar4;
      }
      uVar2 = wstring_compareSubstr(this_00,0,*(uint *)(this_00 + 8),puVar4,puVar5[8]);
      local_18 = (int)uVar2 < 0;
    }
    else {
      puVar4 = this_00;
      if (7 < *(uint *)(this_00 + 10)) {
        puVar4 = *(ushort **)this_00;
      }
      uVar2 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar4,*(uint *)(this_00 + 8));
      local_18 = -1 < (int)uVar2;
    }
    puVar3 = puVar5;
    if (local_18 == false) {
      puVar5 = (undefined4 *)puVar5[2];
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  param_2 = puVar3;
  if (local_18 != false) {
    if (puVar3 == (undefined4 *)**(int **)this) {
      local_18 = true;
      goto LAB_0042aa2e;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  puVar5 = param_2;
  puVar4 = this_00;
  if (7 < *(uint *)(this_00 + 10)) {
    puVar4 = *(ushort **)this_00;
  }
  uVar2 = wstring_compareSubstr(param_2 + 4,0,param_2[8],puVar4,*(uint *)(this_00 + 8));
  piVar1 = param_4;
  if (-1 < (int)uVar2) {
    Speech_mapNode_dtor(param_4 + 4);
    operator_delete(piVar1);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_0042aa2e:
  puVar3 = (undefined4 *)std_map_insertRebalance_SpeechNode(this,&param_2,local_18,puVar3,this_00,param_4);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std_map_insertLowerBound_strKey_variantC  (confidence: high)
 * purpose: String-key lower-bound insert; dup frees node via 42d060; std::map
 * vars: -
 */
/* Global::std_map_insertLowerBound_strKey_variantC @ 0042aae0 */

void __thiscall
std_map_insertLowerBound_strKey_variantC(void *this,undefined4 *param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  ushort *this_00;
  uint uVar1;
  ushort **ppuVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  bool local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  this_00 = param_3;
  puStack_c = &LAB_0054ccb0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = true;
  puVar3 = *(undefined4 **)this;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  while (*(char *)((int)puVar5 + 0xd) == '\0') {
    if ((char)param_2 == '\0') {
      puVar4 = (ushort *)(puVar5 + 4);
      if (7 < (uint)puVar5[9]) {
        puVar4 = *(ushort **)puVar4;
      }
      uVar1 = wstring_compareSubstr(this_00,0,*(uint *)(this_00 + 8),puVar4,puVar5[8]);
      local_1c = (int)uVar1 < 0;
    }
    else {
      puVar4 = this_00;
      if (7 < *(uint *)(this_00 + 10)) {
        puVar4 = *(ushort **)this_00;
      }
      uVar1 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar4,*(uint *)(this_00 + 8));
      local_1c = -1 < (int)uVar1;
    }
    puVar3 = puVar5;
    if (local_1c == false) {
      puVar5 = (undefined4 *)puVar5[2];
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  param_2 = puVar3;
  if (local_1c != false) {
    if (puVar3 == (undefined4 *)**(int **)this) {
      ppuVar2 = (ushort **)&param_2;
      local_1c = true;
      goto LAB_0042aba1;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  puVar5 = param_2;
  puVar4 = this_00;
  if (7 < *(uint *)(this_00 + 10)) {
    puVar4 = *(ushort **)this_00;
  }
  uVar1 = wstring_compareSubstr(param_2 + 4,0,param_2[8],puVar4,*(uint *)(this_00 + 8));
  if (-1 < (int)uVar1) {
    node_free_twoStrings(param_4);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  ppuVar2 = &param_3;
LAB_0042aba1:
  puVar3 = (undefined4 *)std_map_insertRebalance_variantC(this,ppuVar2,local_1c,puVar3,this_00,param_4);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std_map_insertLowerBound_strKey_QuestText  (confidence: high)
 * purpose: String-key lower-bound insert; dup frees QuestText node (42d0c0); std::map
 * vars: -
 */
/* Global::std_map_insertLowerBound_strKey_QuestText @ 0042ac40 */

void __thiscall
std_map_insertLowerBound_strKey_QuestText(void *this,undefined4 *param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  ushort *this_00;
  uint uVar1;
  ushort **ppuVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  bool local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  this_00 = param_3;
  puStack_c = &LAB_0054ccd0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = true;
  puVar3 = *(undefined4 **)this;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  while (*(char *)((int)puVar5 + 0xd) == '\0') {
    if ((char)param_2 == '\0') {
      puVar4 = (ushort *)(puVar5 + 4);
      if (7 < (uint)puVar5[9]) {
        puVar4 = *(ushort **)puVar4;
      }
      uVar1 = wstring_compareSubstr(this_00,0,*(uint *)(this_00 + 8),puVar4,puVar5[8]);
      local_1c = (int)uVar1 < 0;
    }
    else {
      puVar4 = this_00;
      if (7 < *(uint *)(this_00 + 10)) {
        puVar4 = *(ushort **)this_00;
      }
      uVar1 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar4,*(uint *)(this_00 + 8));
      local_1c = -1 < (int)uVar1;
    }
    puVar3 = puVar5;
    if (local_1c == false) {
      puVar5 = (undefined4 *)puVar5[2];
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  param_2 = puVar3;
  if (local_1c != false) {
    if (puVar3 == (undefined4 *)**(int **)this) {
      ppuVar2 = (ushort **)&param_2;
      local_1c = true;
      goto LAB_0042ad01;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  puVar5 = param_2;
  puVar4 = this_00;
  if (7 < *(uint *)(this_00 + 10)) {
    puVar4 = *(ushort **)this_00;
  }
  uVar1 = wstring_compareSubstr(param_2 + 4,0,param_2[8],puVar4,*(uint *)(this_00 + 8));
  if (-1 < (int)uVar1) {
    QuestText_node_free(param_4);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  ppuVar2 = &param_3;
LAB_0042ad01:
  puVar3 = (undefined4 *)std_map_insertRebalance_QuestText(this,ppuVar2,local_1c,puVar3,this_00,param_4);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std_list_appendCopy_strNodes  (confidence: high)
 * purpose: Appends copies of source list range as new nodes (4291a0); 'list<T> too long' guard; std::list assign
 * vars: this+4=count (max 0x7fffffe)
 */
/* Global::std_list_appendCopy_strNodes @ 0042ada0 */

void __thiscall std_list_appendCopy_strNodes(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054ccf0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  while( true ) {
    if (param_2 == param_3) {
      ExceptionList = local_10;
      return;
    }
    iVar1 = std_list_Speech_makeStrNode(param_1,(undefined4 *)param_1[1],param_2 + 2);
    if (*(int *)((int)this + 4) == 0x7fffffe) break;
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    param_1[1] = iVar1;
    **(int **)(iVar1 + 4) = iVar1;
    param_2 = (undefined4 *)*param_2;
  }
  std::_Xlength_error("list<T> too long");
}




/* [AUDIT] proposed: std_list_assignCopy_Speech  (confidence: high)
 * purpose: Copy-assigns a std::list<string>: reuses existing nodes (copies strings) then erases surplus via 42e000; Speech
 * vars: this+4 count; node+2 string
 */
/* Global::std_list_assignCopy_Speech @ 0042ae70 */

void __thiscall std_list_assignCopy_Speech(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uStack_28;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054cd10;
  local_10 = ExceptionList;
  uStack_28 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_28;
  ExceptionList = &local_10;
  piVar3 = *(int **)this;
  local_8 = 0;
  local_18 = this;
  for (; piVar3 = (int *)*piVar3, param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    if (piVar3 == *(int **)this) goto LAB_0042aed5;
    if (piVar3 + 2 != param_1 + 2) {
      U16String_assignSubstr(piVar3 + 2,param_1 + 2,0,0xffffffff);
    }
  }
LAB_0042af2e:
  std_list_eraseRange(this,(int *)&local_18,piVar3,*(int **)this);
  ExceptionList = local_10;
  return;
LAB_0042aed5:
  for (; param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    puVar1 = *(undefined4 **)this;
    iVar2 = std_list_Speech_makeStrNode(puVar1,(undefined4 *)puVar1[1],param_1 + 2);
    if (*(int *)((int)this + 4) == 0x7fffffe) {
      std::_Xlength_error("list<T> too long");
    }
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    puVar1[1] = iVar2;
    **(int **)(iVar2 + 4) = iVar2;
  }
  goto LAB_0042af2e;
}




/* [AUDIT] proposed: std_use_facet_ctype_wchar  (confidence: high)
 * purpose: MSVC std::use_facet<ctype<wchar_t>>: locate/register facet, throw std::bad_cast 'bad cast'; STL, not Speech
 * vars: id_exref facet id; DAT_00583df0 cached facet
 */
/* Global::std_use_facet_ctype_wchar @ 0042af50 */

facet * __cdecl std_use_facet_ctype_wchar(locale *param_1)

{
  int iVar1;
  uint uVar2;
  _Locimp *p_Var3;
  facet *pfVar4;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cd39;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_18,0);
  local_8 = 0;
  local_14 = DAT_00583df0;
  uVar2 = std::locale::id::operator_unsigned_int((id *)id_exref);
  iVar1 = *(int *)param_1;
  if (uVar2 < *(uint *)(iVar1 + 0xc)) {
    pfVar4 = *(facet **)(*(int *)(iVar1 + 8) + uVar2 * 4);
    if (pfVar4 != (facet *)0x0) goto LAB_0042b022;
  }
  else {
    pfVar4 = (facet *)0x0;
  }
  if (*(char *)(iVar1 + 0x14) == '\0') {
LAB_0042afcf:
    if (pfVar4 != (facet *)0x0) goto LAB_0042b022;
  }
  else {
    p_Var3 = std::locale::_Getgloballocale();
    if (uVar2 < *(uint *)(p_Var3 + 0xc)) {
      pfVar4 = *(facet **)(*(int *)(p_Var3 + 8) + uVar2 * 4);
      goto LAB_0042afcf;
    }
  }
  pfVar4 = local_14;
  if (local_14 == (facet *)0x0) {
    uVar2 = std::ctype<wchar_t>::_Getcat(&local_14,param_1);
    pfVar4 = local_14;
    if (uVar2 == 0xffffffff) {
      std::bad_cast::bad_cast(local_24,"bad cast");
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_005779e4);
    }
    DAT_00583df0 = local_14;
    (**(code **)(*(int *)local_14 + 4))();
    Facet_Register(pfVar4);
  }
LAB_0042b022:
  std::_Lockit::~_Lockit(local_18);
  ExceptionList = local_10;
  return pfVar4;
}




/* [AUDIT] proposed: std_list_copyCtor  (confidence: med)
 * purpose: Builds empty std::list header (41a030) then copies elements via 429430; std::list copy-ctor
 * vars: this[0]=head node; this+4=size
 */
/* Global::std_list_copyCtor @ 0042b040 */

undefined4 * __thiscall std_list_copyCtor(void *this,int *param_1)

{
  undefined4 uVar1;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cd68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  uVar1 = QuestTextNode_allocSentinel64();
  *(undefined4 *)this = uVar1;
  local_18 = local_18 & 0xffffff00;
  local_8 = 1;
  std_map_copyAssign(this,param_1,local_18);
  ExceptionList = local_10;
  return this;
}




/* [AUDIT] proposed: std_list_copyCtor_strList  (confidence: med)
 * purpose: Builds std::list<string> (4f7b60 head) and appends copies via 42ada0; std::list copy-ctor
 * vars: this[0]=head; iterates *param
 */
/* Global::std_list_copyCtor_strList @ 0042b180 */

undefined4 * __thiscall std_list_copyCtor_strList(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cdc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  puVar1 = (undefined4 *)std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 **)this = puVar1;
  local_8 = 1;
  std_list_appendCopy_strNodes(this,(undefined4 *)*puVar1,*(undefined4 **)*param_1,(undefined4 *)*param_1);
  ExceptionList = local_10;
  return this;
}




/* [AUDIT] proposed: std_iterator_notEqual  (confidence: high)
 * purpose: Returns *this != *param_1 (iterator/pointer inequality); trivial
 * vars: -
 */
/* Global::std_iterator_notEqual @ 0042c6f0 */

bool __thiscall std_iterator_notEqual(void *this,int *param_1)

{
  return *(int *)this != *param_1;
}




/* [AUDIT] proposed: std_map_subscript_intKey  (confidence: high)
 * purpose: map::operator[] for int key: lower-bound search then insert default-constructed value (42cf80 path) if absent
 * vars: local_30=key; local_2c string default
 */
/* Global::std_map_subscript_intKey @ 0042c710 */

void __thiscall std_map_subscript_intKey(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_4c;
  void *local_48 [4];
  undefined4 local_38;
  uint local_34;
  int local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d070;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = *(int **)this;
  piVar4 = piVar1;
  if (*(char *)(piVar1[1] + 0xd) == '\0') {
    piVar2 = (int *)piVar1[1];
    do {
      if (piVar2[4] < *param_1) {
        piVar3 = (int *)piVar2[2];
      }
      else {
        piVar3 = (int *)*piVar2;
        piVar4 = piVar2;
      }
      piVar2 = piVar3;
    } while (*(char *)((int)piVar3 + 0xd) == '\0');
  }
  if ((piVar4 == piVar1) || (*param_1 < piVar4[4])) {
    local_30 = *param_1;
    local_34 = 7;
    local_38 = 0;
    local_48[0] = (void *)((uint)local_48[0] & 0xffff0000);
    local_8 = 0;
    u16string_moveConstruct(local_2c,local_48);
    local_8 = CONCAT31(local_8._1_3_,1);
    piVar1 = std_map_allocNode_intKeyStr(this,&local_30);
    std_map_insertHint_intKey(this,&local_4c,piVar4,piVar1 + 4,piVar1);
    if (7 < local_18) {
      operator_delete(local_2c[0]);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
    if (7 < local_34) {
      operator_delete(local_48[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std_map_insert_strToStr  (confidence: med)
 * purpose: Inserts string->string pair into map: builds node (429340) and inserts via 42a450; std::map<string,string>
 * vars: local_44/2c key/val strings
 */
/* Global::std_map_insert_strToStr @ 0042c9a0 */

void __thiscall std_map_insert_strToStr(void *this,ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_60;
  void *local_5c [4];
  undefined4 local_4c;
  uint local_48;
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d100;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (ushort *)std_map_lowerBound_strKey(this,param_1);
  if (puVar1 != *(ushort **)this) {
    puVar2 = puVar1 + 8;
    if (7 < *(uint *)(puVar1 + 0x12)) {
      puVar2 = *(ushort **)puVar2;
    }
    uVar3 = wstring_compareSubstr(param_1,0,*(uint *)(param_1 + 8),puVar2,*(uint *)(puVar1 + 0x10));
    if (-1 < (int)uVar3) goto LAB_0042caaa;
  }
  local_48 = 7;
  local_4c = 0;
  local_5c[0] = (void *)((uint)local_5c[0] & 0xffff0000);
  local_8 = 0;
  u16string_moveConstruct(local_44,(undefined4 *)param_1);
  u16string_moveConstruct(local_2c,local_5c);
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar4 = std_map_allocNode_str2(this,local_44);
  std_map_insertHint_strKey_variantC(this,&local_60,puVar1,(ushort *)(piVar4 + 4),piVar4);
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  if (7 < local_48) {
    operator_delete(local_5c[0]);
  }
LAB_0042caaa:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std_map_insert_strToStr_v2  (confidence: med)
 * purpose: Same string->string map insert (429340/42a450) with key built via 4172f0; std::map
 * vars: local_44 key, local_5c val
 */
/* Global::std_map_insert_strToStr_v2 @ 0042cad0 */

void __thiscall std_map_insert_strToStr_v2(void *this,ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_60;
  void *local_5c [4];
  undefined4 local_4c;
  uint local_48;
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d100;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (ushort *)std_map_lowerBound_strKey(this,param_1);
  if (puVar1 != *(ushort **)this) {
    puVar2 = puVar1 + 8;
    if (7 < *(uint *)(puVar1 + 0x12)) {
      puVar2 = *(ushort **)puVar2;
    }
    uVar3 = wstring_compareSubstr(param_1,0,*(uint *)(param_1 + 8),puVar2,*(uint *)(puVar1 + 0x10));
    if (-1 < (int)uVar3) goto LAB_0042cbeb;
  }
  local_48 = 7;
  local_4c = 0;
  local_5c[0] = (void *)((uint)local_5c[0] & 0xffff0000);
  local_8 = 0;
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  U16String_assignSubstr(local_44,(int *)param_1,0,0xffffffff);
  u16string_moveConstruct(local_2c,local_5c);
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar4 = std_map_allocNode_str2(this,local_44);
  std_map_insertHint_strKey_variantC(this,&local_60,puVar1,(ushort *)(piVar4 + 4),piVar4);
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  if (7 < local_48) {
    operator_delete(local_5c[0]);
  }
LAB_0042cbeb:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std_map_makeHeader_0x2c  (confidence: high)
 * purpose: operator_new(0x2c) RB-tree header/sentinel: self-links left/parent/right, sets nil+red flags 0x101; std::map _Buynode
 * vars: +0..8 links; +0xc=0x0101
 */
/* Global::std_map_makeHeader_0x2c @ 0042cea0 */

void std_map_makeHeader_0x2c(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x2c);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: std_map_makeHeader_0x38  (confidence: high)
 * purpose: operator_new(0x38) RB-tree header node self-linked, flags 0x101; std::map sentinel builder
 * vars: as 42cea0
 */
/* Global::std_map_makeHeader_0x38 @ 0042ced0 */

void std_map_makeHeader_0x38(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x38);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: std_map_allocRawNode_0x2c  (confidence: high)
 * purpose: operator_new(0x2c) node; sets 3 link words from *param_1 (sentinel); std::map node allocator
 * vars: -
 */
/* Global::std_map_allocRawNode_0x2c @ 0042cf00 */

undefined4 * __fastcall std_map_allocRawNode_0x2c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std_map_allocRawNode_0x38  (confidence: high)
 * purpose: operator_new(0x38) node; link words from sentinel; std::map node allocator
 * vars: -
 */
/* Global::std_map_allocRawNode_0x38 @ 0042cf40 */

undefined4 * __fastcall std_map_allocRawNode_0x38(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x38);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std_map_allocRawNode_0x40  (confidence: high)
 * purpose: operator_new(0x40) node; link words from sentinel; std::map node allocator
 * vars: -
 */
/* Global::std_map_allocRawNode_0x40 @ 0042cf80 */

undefined4 * __fastcall std_map_allocRawNode_0x40(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x40);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: rbtree_destroyRecursive_strNode  (confidence: high)
 * purpose: Recursively frees RB-tree (right via [2], left via *node) freeing string(+0x14)+node; std::map clear
 * vars: node+0xd nil; +0x28 string cap
 */
/* Global::rbtree_destroyRecursive_strNode @ 0042d140 */

void rbtree_destroyRecursive_strNode(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    rbtree_destroyRecursive_strNode((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[10]) {
      operator_delete((void *)param_1[5]);
    }
    param_1[10] = 7;
    param_1[9] = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}




/* [AUDIT] proposed: rbtree_destroyRecursive_SpeechNode  (confidence: high)
 * purpose: Recursively frees Speech RB-tree nodes: inner list(+0x30), string(+0x10), sublist(+0x28); std::map clear
 * vars: node+0xd nil
 */
/* Global::rbtree_destroyRecursive_SpeechNode @ 0042d1a0 */

void * __thiscall rbtree_destroyRecursive_SpeechNode(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 local_c;
  void *local_8;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  local_8 = this;
  while (cVar1 == '\0') {
    rbtree_destroyRecursive_SpeechNode(local_8,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    std_list_clear(param_1 + 0xc);
    operator_delete((void *)param_1[0xc]);
    SpeechMap_eraseRange(param_1 + 10,&local_c,*(int **)param_1[10],(int *)param_1[10]);
    operator_delete((void *)param_1[10]);
    if (7 < (uint)param_1[9]) {
      operator_delete((void *)param_1[4]);
    }
    param_1[9] = 7;
    param_1[8] = 0;
    *(undefined2 *)(param_1 + 4) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return local_8;
}




/* [AUDIT] proposed: rbtree_destroyRecursive_QuestText  (confidence: high)
 * purpose: Recursively frees QuestText RB-tree nodes (ctor_3 payload +0x28, string +0x10); std::map clear
 * vars: SEH; node+0xd nil
 */
/* Global::rbtree_destroyRecursive_QuestText @ 0042d250 */

uint __thiscall rbtree_destroyRecursive_QuestText(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d1b8;
  uVar4 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_2 + 0xd);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    rbtree_destroyRecursive_QuestText(param_1,(int *)param_2[2]);
    piVar2 = (int *)*param_2;
    local_8 = 0;
    cube::QuestText::ctor_3(param_2 + 10);
    local_8 = 0xffffffff;
    if (7 < (uint)param_2[9]) {
      operator_delete((void *)param_2[4]);
    }
    param_2[9] = 7;
    param_2[8] = 0;
    *(undefined2 *)(param_2 + 4) = 0;
    operator_delete(param_2);
    ppvVar3 = ExceptionList;
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  ExceptionList = local_10;
  return uVar4;
}




/* [AUDIT] proposed: std_strstreambuf_init  (confidence: med)
 * purpose: Initializes a memory stream buffer: allocs 2*n bytes, memcpy, sets get/put area pointers by mode flags; STL strstream
 * vars: this+0x3c mode flags; +0xc..+0x30 area ptrs
 */
/* Global::std_strstreambuf_init @ 0042d300 */

void __thiscall std_strstreambuf_init(void *this,void *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint _Size;
  void *_Dst;
  void *pvVar2;
  
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = param_3;
  if ((param_2 != 0) && (((byte)param_3 & 6) != 6)) {
    if (param_2 < 0x80000000) {
      _Size = param_2 * 2;
      _Dst = operator_new(_Size);
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,param_1,_Size);
        *(void **)((int)this + 0x38) = (void *)(_Size + (int)_Dst);
        if ((*(byte *)((int)this + 0x3c) & 4) == 0) {
          **(undefined4 **)((int)this + 0xc) = _Dst;
          **(undefined4 **)((int)this + 0x1c) = _Dst;
          **(int **)((int)this + 0x2c) = (int)_Size >> 1;
        }
        uVar1 = *(uint *)((int)this + 0x3c);
        if ((uVar1 & 2) == 0) {
          **(undefined4 **)((int)this + 0x10) = _Dst;
          pvVar2 = _Dst;
          if ((uVar1 & 0x10) != 0) {
            pvVar2 = (void *)(_Size + (int)_Dst);
          }
          **(undefined4 **)((int)this + 0x20) = pvVar2;
          **(int **)((int)this + 0x30) = (int)((_Size - (int)pvVar2) + (int)_Dst) >> 1;
          if (**(int **)((int)this + 0x1c) == 0) {
            **(undefined4 **)((int)this + 0xc) = _Dst;
            **(undefined4 **)((int)this + 0x1c) = 0;
            **(int **)((int)this + 0x2c) = (int)_Dst >> 1;
          }
        }
        *(uint *)((int)this + 0x3c) = *(uint *)((int)this + 0x3c) | 1;
        return;
      }
    }
    std::_Xbad_alloc();
  }
  return;
}




/* [AUDIT] proposed: std_map_lowerBound_strKey  (confidence: high)
 * purpose: Descends RB-tree comparing std::string key (419ef0) to return lower_bound node; std::map find
 * vars: puVar5+4 str,+8 len; +0xd nil
 */
/* Global::std_map_lowerBound_strKey @ 0042d3d0 */

undefined4 * __thiscall std_map_lowerBound_strKey(void *this,ushort *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  cVar1 = *(char *)((int)puVar5 + 0xd);
  puVar2 = *(undefined4 **)this;
  while (cVar1 == '\0') {
    puVar3 = param_1;
    if (7 < *(uint *)(param_1 + 10)) {
      puVar3 = *(ushort **)param_1;
    }
    uVar4 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar3,*(uint *)(param_1 + 8));
    if ((int)uVar4 < 0) {
      puVar6 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar6 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar6;
    cVar1 = *(char *)((int)puVar6 + 0xd);
  }
  return puVar2;
}




/* [AUDIT] proposed: rbtree_max  (confidence: high)
 * purpose: Returns rightmost node of subtree (follow +8 while not nil); std::tree _Max
 * vars: node+8 right; +0xd nil
 */
/* Global::rbtree_max @ 0042d420 */

int __cdecl rbtree_max(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *(char *)(*(int *)(param_1 + 8) + 0xd);
  iVar2 = *(int *)(param_1 + 8);
  while (iVar3 = iVar2, cVar1 == '\0') {
    iVar2 = *(int *)(iVar3 + 8);
    cVar1 = *(char *)(iVar2 + 0xd);
    param_1 = iVar3;
  }
  return param_1;
}




/* [AUDIT] proposed: rbtree_min  (confidence: high)
 * purpose: Returns leftmost node of subtree (follow *node while not nil); std::tree _Min
 * vars: node[0] left; +0xd nil
 */
/* Global::rbtree_min @ 0042d440 */

int * __cdecl rbtree_min(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)(*param_1 + 0xd);
  piVar2 = (int *)*param_1;
  while (piVar3 = piVar2, cVar1 == '\0') {
    piVar2 = (int *)*piVar3;
    cVar1 = *(char *)((int)piVar2 + 0xd);
    param_1 = piVar3;
  }
  return param_1;
}




/* [AUDIT] proposed: rbtree_rotateLeft  (confidence: high)
 * purpose: Left rotation of RB-tree node about param_1; std::tree _Lrotate
 * vars: node[0] left,+4 parent,+8 right
 */
/* Global::rbtree_rotateLeft @ 0042d460 */

void __thiscall rbtree_rotateLeft(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0xd) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)this + 4)) {
    *(int *)(*(int *)this + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}




/* [AUDIT] proposed: std_list_clear  (confidence: high)
 * purpose: Destroys all std::list nodes (free string at +8) and re-inits head sentinel; std::list clear/dtor
 * vars: node+7 cap; +2 string
 */
/* Global::std_list_clear @ 0042d520 */

void __fastcall std_list_clear(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      if (7 < (uint)piVar2[7]) {
        operator_delete((void *)piVar2[2]);
      }
      piVar2[7] = 7;
      piVar2[6] = 0;
      *(undefined2 *)(piVar2 + 2) = 0;
      operator_delete(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}




/* [AUDIT] proposed: std_map_eraseRange_strNode  (confidence: high)
 * purpose: Erases node range [first,last); special-cases full clear via 42d140; erases each via 42d640; std::map
 * vars: handles leftmost/rightmost recompute
 */
/* Global::std_map_eraseRange_strNode @ 0042d580 */

undefined4 * __thiscall std_map_eraseRange_strNode(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)this;
  local_8 = this;
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    rbtree_destroyRecursive_strNode((int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar3 != param_3) {
    param_2 = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      param_2 = (int *)piVar3[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar2 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
    std_map_eraseNode_strNode(this,&local_8,piVar3);
    piVar3 = param_2;
  }
  *param_1 = piVar3;
  return param_1;
}




/* [AUDIT] proposed: std_map_eraseNode_strNode  (confidence: high)
 * purpose: Removes one RB-tree node with rebalance/rotations, frees string(+0x14)+node, decrements size; 'invalid map/set<T> iterator'
 * vars: this+4 count; node+0xc color
 */
/* Global::std_map_eraseNode_strNode @ 0042d640 */

void __thiscall std_map_eraseNode_strNode(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0xd) == '\0') && (piVar7 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar7 + 0xd) == '\0') {
          piVar7[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar7;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar2) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar6 = (int *)piVar2[1];
        if ((int *)*piVar6 == piVar2) {
          *piVar6 = (int)param_2;
        }
        else {
          piVar6[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar2[3];
      *(char *)(piVar2 + 3) = (char)iVar1;
      goto LAB_0042d76c;
    }
  }
  else {
    piVar7 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar7 + 0xd) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar2) {
    *(int **)(*(int *)this + 4) = piVar7;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  piVar6 = *(int **)this;
  if ((int *)*piVar6 == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      piVar3 = rbtree_min(piVar7);
    }
    *piVar6 = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar7);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_0042d76c:
  if ((char)piVar2[3] == '\x01') {
    if (piVar7 != *(int **)(*(int *)this + 4)) {
      do {
        piVar6 = piVar5;
        if ((char)piVar7[3] != '\x01') break;
        piVar5 = (int *)*piVar6;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar6[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar6);
            piVar5 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar6[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar6[3];
              *(undefined1 *)(piVar6 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar6);
              *(undefined1 *)(piVar7 + 3) = 1;
              goto LAB_0042d89e;
            }
LAB_0042d840:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            rbtree_rotateLeft(this,piVar6);
            piVar5 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_0042d840;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar6;
            }
            *(char *)(piVar5 + 3) = (char)piVar6[3];
            *(undefined1 *)(piVar6 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar6);
            *(undefined1 *)(piVar7 + 3) = 1;
            goto LAB_0042d89e;
          }
        }
        piVar5 = (int *)piVar6[1];
        piVar7 = piVar6;
      } while (piVar6 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar7 + 3) = 1;
  }
LAB_0042d89e:
  if (7 < (uint)piVar2[10]) {
    operator_delete((void *)piVar2[5]);
  }
  piVar2[10] = 7;
  piVar2[9] = 0;
  *(undefined2 *)(piVar2 + 5) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: std_map_eraseRange_SpeechNode  (confidence: high)
 * purpose: Erases node range; full clear via 42d1a0 else per-node 42d9b0; std::map (Speech)
 * vars: -
 */
/* Global::std_map_eraseRange_SpeechNode @ 0042d8f0 */

undefined4 * __thiscall std_map_eraseRange_SpeechNode(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)this;
  local_8 = this;
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    rbtree_destroyRecursive_SpeechNode(this,(int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar3 != param_3) {
    param_2 = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      param_2 = (int *)piVar3[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar2 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
    std_map_eraseNode_SpeechNode(&local_8,piVar3);
    piVar3 = param_2;
  }
  *param_1 = piVar3;
  return param_1;
}




/* [AUDIT] proposed: std_map_eraseNode_SpeechNode  (confidence: high)
 * purpose: Removes RB-tree node with rebalance; frees Speech payload (list+2 strings) inline; 'invalid map/set<T> iterator'
 * vars: local_8=header; node+0xc color
 */
/* Global::std_map_eraseNode_SpeechNode @ 0042d9b0 */

void std_map_eraseNode_SpeechNode(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *local_c;
  int *local_8;
  
  piVar1 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar4 = (int *)*piVar1;
  if (*(char *)((int)piVar4 + 0xd) == '\0') {
    piVar6 = piVar4;
    if (*(char *)(piVar1[2] + 0xd) == '\0') {
      local_c = param_2;
      piVar6 = (int *)param_2[2];
      if (param_2 != piVar1) {
        piVar4[1] = (int)param_2;
        *param_2 = *piVar1;
        piVar4 = param_2;
        if (param_2 != (int *)piVar1[2]) {
          piVar4 = (int *)param_2[1];
          if (*(char *)((int)piVar6 + 0xd) == '\0') {
            piVar6[1] = (int)piVar4;
          }
          *piVar4 = (int)piVar6;
          param_2[2] = piVar1[2];
          *(int **)(piVar1[2] + 4) = param_2;
        }
        if (*(int **)(*local_8 + 4) == piVar1) {
          *(int **)(*local_8 + 4) = param_2;
        }
        else {
          piVar2 = (int *)piVar1[1];
          if ((int *)*piVar2 == piVar1) {
            *piVar2 = (int)param_2;
          }
          else {
            piVar2[2] = (int)param_2;
          }
        }
        param_2[1] = piVar1[1];
        iVar3 = param_2[3];
        *(char *)(param_2 + 3) = (char)piVar1[3];
        *(char *)(piVar1 + 3) = (char)iVar3;
        goto LAB_0042dadc;
      }
    }
  }
  else {
    piVar6 = (int *)piVar1[2];
  }
  piVar4 = (int *)piVar1[1];
  if (*(char *)((int)piVar6 + 0xd) == '\0') {
    piVar6[1] = (int)piVar4;
  }
  if (*(int **)(*local_8 + 4) == piVar1) {
    *(int **)(*local_8 + 4) = piVar6;
  }
  else if ((int *)*piVar4 == piVar1) {
    *piVar4 = (int)piVar6;
  }
  else {
    piVar4[2] = (int)piVar6;
  }
  local_c = (int *)*local_8;
  if ((int *)*local_c == piVar1) {
    piVar2 = piVar4;
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      piVar2 = rbtree_min(piVar6);
    }
    *local_c = (int)piVar2;
  }
  local_c = (int *)*local_8;
  if ((int *)local_c[2] == piVar1) {
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      iVar3 = rbtree_max((int)piVar6);
      local_c[2] = iVar3;
    }
    else {
      local_c[2] = (int)piVar4;
    }
  }
LAB_0042dadc:
  if ((char)piVar1[3] == '\x01') {
    piVar2 = local_8;
    if (piVar6 != *(int **)(*local_8 + 4)) {
      do {
        piVar5 = piVar4;
        if ((char)piVar6[3] != '\x01') break;
        piVar4 = (int *)*piVar5;
        if (piVar6 == piVar4) {
          piVar4 = (int *)piVar5[2];
          if ((char)piVar4[3] == '\0') {
            *(undefined1 *)(piVar4 + 3) = 1;
            *(undefined1 *)(piVar5 + 3) = 0;
            std_Rb_tree_rotate(piVar2,(int)piVar5);
            piVar4 = (int *)piVar5[2];
            piVar2 = local_8;
          }
          if (*(char *)((int)piVar4 + 0xd) == '\0') {
            if ((*(char *)(*piVar4 + 0xc) != '\x01') || (*(char *)(piVar4[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar4[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar4 + 0xc) = 1;
                *(undefined1 *)(piVar4 + 3) = 0;
                rbtree_rotateLeft(piVar2,piVar4);
                piVar4 = (int *)piVar5[2];
              }
              *(char *)(piVar4 + 3) = (char)piVar5[3];
              *(undefined1 *)(piVar5 + 3) = 1;
              *(undefined1 *)(piVar4[2] + 0xc) = 1;
              std_Rb_tree_rotate(local_8,(int)piVar5);
              break;
            }
LAB_0042dba7:
            *(undefined1 *)(piVar4 + 3) = 0;
          }
        }
        else {
          if ((char)piVar4[3] == '\0') {
            *(undefined1 *)(piVar4 + 3) = 1;
            *(undefined1 *)(piVar5 + 3) = 0;
            rbtree_rotateLeft(piVar2,piVar5);
            piVar4 = (int *)*piVar5;
            piVar2 = local_8;
          }
          if (*(char *)((int)piVar4 + 0xd) == '\0') {
            if ((*(char *)(piVar4[2] + 0xc) == '\x01') && (*(char *)(*piVar4 + 0xc) == '\x01'))
            goto LAB_0042dba7;
            if (*(char *)(*piVar4 + 0xc) == '\x01') {
              *(undefined1 *)(piVar4[2] + 0xc) = 1;
              *(undefined1 *)(piVar4 + 3) = 0;
              std_Rb_tree_rotate(piVar2,(int)piVar4);
              piVar4 = (int *)*piVar5;
            }
            *(char *)(piVar4 + 3) = (char)piVar5[3];
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(*piVar4 + 0xc) = 1;
            rbtree_rotateLeft(local_8,piVar5);
            break;
          }
        }
        piVar4 = (int *)piVar5[1];
        piVar6 = piVar5;
      } while (piVar5 != *(int **)(*piVar2 + 4));
    }
    *(undefined1 *)(piVar6 + 3) = 1;
  }
  std_list_clear(piVar1 + 0xc);
  operator_delete((void *)piVar1[0xc]);
  SpeechMap_eraseRange(piVar1 + 10,&local_c,*(int **)piVar1[10],(int *)piVar1[10]);
  operator_delete((void *)piVar1[10]);
  if (7 < (uint)piVar1[9]) {
    operator_delete((void *)piVar1[4]);
  }
  piVar1[9] = 7;
  piVar1[8] = 0;
  *(undefined2 *)(piVar1 + 4) = 0;
  operator_delete(piVar1);
  if (local_8[1] != 0) {
    local_8[1] = local_8[1] + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: std_map_eraseRange_QuestText  (confidence: high)
 * purpose: Erases node range; full clear via 42d250 else per-node 42dd40; std::map (QuestText)
 * vars: -
 */
/* Global::std_map_eraseRange_QuestText @ 0042dc80 */

undefined4 * __thiscall std_map_eraseRange_QuestText(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)this;
  local_8 = this;
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    rbtree_destroyRecursive_QuestText(this,(int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar3 != param_3) {
    param_2 = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      param_2 = (int *)piVar3[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar2 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
    std_map_eraseNode_QuestText(this,&local_8,piVar3);
    piVar3 = param_2;
  }
  *param_1 = piVar3;
  return param_1;
}




/* [AUDIT] proposed: std_map_eraseNode_QuestText  (confidence: high)
 * purpose: Removes RB-tree node with rebalance; frees QuestText payload (ctor_3 +string); 'invalid map/set<T> iterator'
 * vars: SEH; node+0xc color
 */
/* Global::std_map_eraseNode_QuestText @ 0042dd40 */

void __thiscall std_map_eraseNode_QuestText(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d1e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar1;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar6 = piVar5;
    if ((*(char *)(piVar1[2] + 0xd) == '\0') && (piVar6 = (int *)param_2[2], param_2 != piVar1)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar1;
      piVar5 = param_2;
      if (param_2 != (int *)piVar1[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar6 + 0xd) == '\0') {
          piVar6[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar6;
        param_2[2] = piVar1[2];
        *(int **)(piVar1[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar1) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar3 = (int *)piVar1[1];
        if ((int *)*piVar3 == piVar1) {
          *piVar3 = (int)param_2;
        }
        else {
          piVar3[2] = (int)param_2;
        }
      }
      param_2[1] = piVar1[1];
      iVar4 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar1[3];
      *(char *)(piVar1 + 3) = (char)iVar4;
      goto LAB_0042de7d;
    }
  }
  else {
    piVar6 = (int *)piVar1[2];
  }
  piVar5 = (int *)piVar1[1];
  if (*(char *)((int)piVar6 + 0xd) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar1) {
    *(int **)(*(int *)this + 4) = piVar6;
  }
  else if ((int *)*piVar5 == piVar1) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  piVar3 = *(int **)this;
  if ((int *)*piVar3 == piVar1) {
    piVar2 = piVar5;
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      piVar2 = rbtree_min(piVar6);
      piVar3 = *(int **)this;
    }
    *piVar3 = (int)piVar2;
  }
  if (*(int **)(*(int *)this + 8) == piVar1) {
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar6);
      *(int *)(*(int *)this + 8) = iVar4;
    }
    else {
      *(int **)(*(int *)this + 8) = piVar5;
    }
  }
LAB_0042de7d:
  if ((char)piVar1[3] == '\x01') {
    if (piVar6 != *(int **)(*(int *)this + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[3] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar3 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar3[3];
              *(undefined1 *)(piVar3 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar3);
              break;
            }
LAB_0042df41:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar3 + 3) = 0;
            rbtree_rotateLeft(this,piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_0042df41;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 3) = (char)piVar3[3];
            *(undefined1 *)(piVar3 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar6 + 3) = 1;
  }
  local_8 = 0;
  cube::QuestText::ctor_3(piVar1 + 10);
  if (7 < (uint)piVar1[9]) {
    operator_delete((void *)piVar1[4]);
  }
  piVar1[9] = 7;
  piVar1[8] = 0;
  *(undefined2 *)(piVar1 + 4) = 0;
  operator_delete(piVar1);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std_list_eraseRange  (confidence: high)
 * purpose: Erases list nodes in [first,last), unlinking and freeing string(+8); decrements size; std::list erase
 * vars: this+4 count; node+2 string
 */
/* Global::std_list_eraseRange @ 0042e000 */

int * __thiscall std_list_eraseRange(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  if ((param_2 == (int *)**(int **)this) && (param_3 == *(int **)this)) {
    std_list_clear(this);
    *param_1 = *(int *)this;
    return param_1;
  }
  while (piVar1 = param_2, piVar1 != param_3) {
    param_2 = (int *)*piVar1;
    if (piVar1 != *(int **)this) {
      *(int **)piVar1[1] = param_2;
      *(int *)(*piVar1 + 4) = piVar1[1];
      if (7 < (uint)piVar1[7]) {
        operator_delete((void *)piVar1[2]);
      }
      piVar1[7] = 7;
      piVar1[6] = 0;
      *(undefined2 *)(piVar1 + 2) = 0;
      operator_delete(piVar1);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
    }
  }
  *param_1 = (int)param_3;
  return param_1;
}




/* [AUDIT] proposed: std_map_makeHeader_0x1c  (confidence: high)
 * purpose: operator_new(0x1c) RB-tree header self-linked, flags 0x101; std::map/set sentinel builder
 * vars: +0..8 links; +0xc=0x0101
 */
/* Global::std_map_makeHeader_0x1c @ 0042f040 */

void std_map_makeHeader_0x1c(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: rbtree_destroyRecursive_SpriteNode  (confidence: high)
 * purpose: Recursively frees RB-tree Sprite nodes: clears list at node+5 then frees node; std::map clear
 * vars: node+0xd nil; +5 list head
 */
/* Global::rbtree_destroyRecursive_SpriteNode @ 0042f1c0 */

undefined4 __thiscall rbtree_destroyRecursive_SpriteNode(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 extraout_ECX;
  
  cVar1 = *(char *)((int)param_2 + 0xd);
  uVar4 = param_1;
  while (cVar1 == '\0') {
    rbtree_destroyRecursive_SpriteNode(param_1,(int *)param_2[2]);
    piVar2 = (int *)param_2[5];
    piVar3 = (int *)*param_2;
    piVar5 = (int *)*piVar2;
    *piVar2 = (int)piVar2;
    *(int *)(param_2[5] + 4) = param_2[5];
    param_2[6] = 0;
    if (piVar5 != (int *)param_2[5]) {
      do {
        piVar2 = (int *)*piVar5;
        operator_delete(piVar5);
        piVar5 = piVar2;
      } while (piVar2 != (int *)param_2[5]);
    }
    operator_delete((void *)param_2[5]);
    operator_delete(param_2);
    uVar4 = extraout_ECX;
    param_2 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0xd);
  }
  return uVar4;
}




/* [AUDIT] proposed: std_vector_free  (confidence: high)
 * purpose: Frees vector buffer (operator_delete) and zeros begin/end/cap; std::vector dtor; misattributed CombatBehavior
 * vars: param_1[0..2] begin/end/cap
 */
/* Global::std_vector_free @ 0042f440 */

void __fastcall std_vector_free(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}




/* [AUDIT] proposed: std_map_eraseRange_SpriteNode  (confidence: high)
 * purpose: Erases Sprite map node range; full clear via 42f1c0 else per-node 42f5a0; std::map
 * vars: -
 */
/* Global::std_map_eraseRange_SpriteNode @ 0042f4e0 */

undefined4 * __thiscall std_map_eraseRange_SpriteNode(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)this;
  local_8 = this;
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    rbtree_destroyRecursive_SpriteNode(this,(int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar3 != param_3) {
    param_2 = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      param_2 = (int *)piVar3[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar2 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
    std_map_eraseNode_SpriteNode(this,&local_8,piVar3);
    piVar3 = param_2;
  }
  *param_1 = piVar3;
  return param_1;
}




/* [AUDIT] proposed: std_map_eraseNode_SpriteNode  (confidence: high)
 * purpose: Removes RB-tree node with rebalance then clears list payload (node+5) and frees; 'invalid map/set<T> iterator'
 * vars: node+5 list; +0xc color
 */
/* Global::std_map_eraseNode_SpriteNode @ 0042f5a0 */

void __thiscall std_map_eraseNode_SpriteNode(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar6 = piVar5;
    if ((*(char *)(piVar2[2] + 0xd) == '\0') && (piVar6 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar6 + 0xd) == '\0') {
          piVar6[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar6;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar2) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar7 = (int *)piVar2[1];
        if ((int *)*piVar7 == piVar2) {
          *piVar7 = (int)param_2;
        }
        else {
          piVar7[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar2[3];
      *(char *)(piVar2 + 3) = (char)iVar1;
      goto LAB_0042f6cc;
    }
  }
  else {
    piVar6 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar6 + 0xd) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar2) {
    *(int **)(*(int *)this + 4) = piVar6;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  piVar7 = *(int **)this;
  if ((int *)*piVar7 == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      piVar3 = rbtree_min(piVar6);
    }
    *piVar7 = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar6);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_0042f6cc:
  if ((char)piVar2[3] == '\x01') {
    if (piVar6 != *(int **)(*(int *)this + 4)) {
      do {
        piVar7 = piVar5;
        if ((char)piVar6[3] != '\x01') break;
        piVar5 = (int *)*piVar7;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar7[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar7 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar7);
            piVar5 = (int *)piVar7[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar7[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar7[3];
              *(undefined1 *)(piVar7 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar7);
              break;
            }
LAB_0042f797:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar7 + 3) = 0;
            rbtree_rotateLeft(this,piVar7);
            piVar5 = (int *)*piVar7;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_0042f797;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar7;
            }
            *(char *)(piVar5 + 3) = (char)piVar7[3];
            *(undefined1 *)(piVar7 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar7);
            break;
          }
        }
        piVar5 = (int *)piVar7[1];
        piVar6 = piVar7;
      } while (piVar7 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar6 + 3) = 1;
  }
  piVar5 = (int *)piVar2[5];
  piVar6 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  *(int *)(piVar2[5] + 4) = piVar2[5];
  piVar2[6] = 0;
  if (piVar6 != (int *)piVar2[5]) {
    do {
      piVar5 = (int *)*piVar6;
      operator_delete(piVar6);
      piVar6 = piVar5;
    } while (piVar5 != (int *)piVar2[5]);
  }
  operator_delete((void *)piVar2[5]);
  operator_delete(piVar2);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: sqlite3_close  (confidence: high)
 * purpose: Thin wrapper: sqlite3_fn_492580(db,0); SQLite sqlite3_close; class Database ok
 * vars: -
 */
/* Global::sqlite3_close @ 00462fe0 */

void __cdecl sqlite3_close(int *param_1)

{
  sqlite3_fn_492580(param_1,0);
  return;
}




/* [AUDIT] proposed: sqlite3_exec  (confidence: high)
 * purpose: SQLite sqlite3_exec: prepare/step each statement, invoke row callback with column text/names; misattributed Speech
 * vars: param_3=callback; local_8=stmt; 'misuse at line'
 */
/* Global::sqlite3_exec @ 00463120 */

uint __cdecl
sqlite3_exec(int param_1,byte *param_2,undefined *param_3,undefined4 param_4,int *param_5)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *_Dst;
  int iVar6;
  int *piVar7;
  undefined *puVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  byte *pbVar12;
  uint uVar13;
  size_t sVar14;
  byte *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  undefined4 *local_1c;
  byte *local_18;
  int local_14;
  undefined4 *local_10;
  uint local_c;
  uint *local_8;
  
  uVar13 = 0;
  local_c = 0;
  local_8 = (uint *)0x0;
  local_10 = (undefined4 *)0x0;
  local_20 = 0;
  iVar5 = sqlite3SafetyCheckOk(param_1);
  if (iVar5 == 0) {
    sqlite3_log(0x15,"misuse at line %d of [%.10s]");
    return 0x15;
  }
  pbVar12 = &DAT_0055b524;
  if (param_2 != (byte *)0x0) {
    pbVar12 = param_2;
  }
  local_18 = pbVar12;
  if (*(int *)(param_1 + 0xc) != 0) {
    (*DAT_00582b18)(*(int *)(param_1 + 0xc));
  }
  sqlite3ErrorWithMsg(param_1,0,(byte *)0x0);
LAB_004631a0:
  while( true ) {
    _Dst = (undefined4 *)0x0;
    if (uVar13 == 0) goto LAB_004631bd;
    do {
      if ((uVar13 != 0x11) || (local_20 = local_20 + 1, 1 < local_20)) goto LAB_0046348d;
LAB_004631bd:
      if (*pbVar12 == 0) goto LAB_0046348d;
      local_1c = (undefined4 *)0x0;
      local_8 = (uint *)0x0;
      uVar13 = sqlite3LockAndPrepare(param_1,pbVar12,0xffffffff,0,0,&local_8,(int *)&local_30);
      local_c = uVar13;
    } while (uVar13 != 0);
    if (local_8 != (uint *)0x0) break;
    local_18 = local_30;
    pbVar12 = local_30;
  }
  iVar5 = 0;
  uVar13 = (uint)(ushort)local_8[0xb];
  local_2c = 0;
  local_c = 0;
  local_28 = uVar13;
LAB_00463213:
  local_c = sqlite3_step_469cb0(local_8);
  if (param_3 != (undefined *)0x0) {
    if (local_c == 100) {
      if (iVar5 == 0) goto LAB_00463257;
LAB_004632b5:
      local_1c = _Dst + uVar13;
      _Dst = local_10;
      if (0 < (int)uVar13) {
        local_14 = 0;
        iVar5 = 0;
        do {
          puVar4 = local_8;
          iVar6 = local_14;
          if (local_8 == (uint *)0x0) {
LAB_00463328:
            piVar7 = (int *)&DAT_00569b70;
          }
          else {
            if (((local_8[5] == 0) || ((int)(uint)(ushort)local_8[0xb] <= iVar5)) || (iVar5 < 0)) {
              if (*local_8 != 0) {
                iVar3 = *(int *)(*local_8 + 0xc);
                if (iVar3 != 0) {
                  (*DAT_00582b18)(iVar3);
                }
                sqlite3ErrorWithMsg(*puVar4,0x19,(byte *)0x0);
              }
              goto LAB_00463328;
            }
            if (*(int *)(*local_8 + 0xc) != 0) {
              (*DAT_00582b18)(*(int *)(*local_8 + 0xc));
            }
            piVar7 = (int *)(puVar4[5] + iVar6);
          }
          local_24 = sqlite3ValueApplyAffinity(piVar7,1);
          if (puVar4 != (uint *)0x0) {
            uVar13 = *puVar4;
            uVar10 = puVar4[0x16];
            if (uVar13 == 0) {
              uVar13 = 0xff;
            }
            else {
              if ((*(char *)(uVar13 + 0x38) != '\0') || (uVar10 == 0xc0a)) {
                sqlite3ErrorWithMsg(uVar13,7,(byte *)0x0);
                *(undefined1 *)(uVar13 + 0x38) = 0;
                uVar10 = 7;
              }
              uVar13 = *(uint *)(uVar13 + 0x30);
            }
            puVar4[0x16] = uVar13 & uVar10;
            iVar6 = local_14;
            if (*(int *)(*puVar4 + 0xc) != 0) {
              (*DAT_00582b20)(*(int *)(*puVar4 + 0xc));
              iVar6 = local_14;
            }
          }
          puVar4 = local_8;
          local_1c[iVar5] = local_24;
          if (local_24 == 0) {
            puVar8 = sqlite3_columnMem((int *)local_8,iVar5);
            cVar1 = puVar8[0x1e];
            sqlite3_column_apiExit((int *)puVar4);
            iVar6 = local_14;
            if (cVar1 != '\x05') {
              *(undefined1 *)(param_1 + 0x38) = 1;
              _Dst = local_10;
              goto LAB_0046348d;
            }
          }
          iVar5 = iVar5 + 1;
          local_14 = iVar6 + 0x28;
          _Dst = local_10;
          uVar13 = local_28;
        } while (iVar5 < (int)local_28);
      }
    }
    else {
      if (local_c != 0x65) goto LAB_004633ef;
      if ((iVar5 != 0) || ((*(byte *)(param_1 + 0x18) & 0x20) == 0)) goto LAB_004633f8;
LAB_00463257:
      sVar14 = uVar13 * 8 + 1;
      _Dst = sqlite3PageMalloc(param_1,sVar14);
      local_10 = _Dst;
      if ((_Dst == (undefined4 *)0x0) || (memset(_Dst,0,sVar14), _Dst == (undefined4 *)0x0))
      goto LAB_0046348d;
      iVar5 = 0;
      if (0 < (int)uVar13) {
        do {
          iVar6 = sqlite3_column_value((int *)local_8,iVar5);
          _Dst[iVar5] = iVar6;
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)uVar13);
      }
      local_2c = 1;
      if (local_c == 100) goto LAB_004632b5;
    }
    iVar6 = (*(code *)param_3)(param_4,uVar13,local_1c,_Dst);
    iVar5 = local_2c;
    if (iVar6 != 0) goto LAB_00463468;
  }
LAB_004633ef:
  if (local_c != 100) goto LAB_004633f8;
  goto LAB_00463213;
LAB_004633f8:
  uVar13 = sqlite3VdbeDelete((int *)local_8);
  local_8 = (uint *)0x0;
  if (uVar13 != 0x11) {
    local_20 = 0;
    bVar2 = (&DAT_00569720)[*local_30];
    local_18 = local_30;
    while ((bVar2 & 1) != 0) {
      pbVar12 = local_18 + 1;
      local_18 = local_18 + 1;
      bVar2 = (&DAT_00569720)[*pbVar12];
    }
  }
  pbVar12 = local_18;
  local_c = uVar13;
  sqlite3PageFree(param_1,_Dst);
  local_10 = (undefined4 *)0x0;
  goto LAB_004631a0;
LAB_00463468:
  local_c = 4;
  sqlite3VdbeDelete((int *)local_8);
  local_8 = (uint *)0x0;
  sqlite3ErrorWithMsg(param_1,4,(byte *)0x0);
LAB_0046348d:
  puVar4 = local_8;
  if (local_8 != (uint *)0x0) {
    if ((local_8[0xc] == 0xbdf20da3) || (local_8[0xc] == 0x519c2973)) {
      sqlite3VdbeHalt((int *)local_8);
    }
    uVar13 = *puVar4;
    sqlite3VdbeFreeCursorsAndProgram(uVar13,(int)puVar4);
    if (puVar4[0xe] == 0) {
      *(uint *)(uVar13 + 4) = puVar4[0xf];
    }
    else {
      *(uint *)(puVar4[0xe] + 0x3c) = puVar4[0xf];
    }
    if (puVar4[0xf] != 0) {
      *(uint *)(puVar4[0xf] + 0x38) = puVar4[0xe];
    }
    puVar4[0xc] = 0xb606c3c8;
    *puVar4 = 0;
    sqlite3PageFree(uVar13,puVar4);
  }
  sqlite3PageFree(param_1,_Dst);
  if ((*(char *)(param_1 + 0x38) != '\0') || (uVar13 = local_c, local_c == 0xc0a)) {
    sqlite3ErrorWithMsg(param_1,7,(byte *)0x0);
    *(undefined1 *)(param_1 + 0x38) = 0;
    uVar13 = 7;
  }
  uVar13 = *(uint *)(param_1 + 0x30) & uVar13;
  if (uVar13 != 0) {
    iVar5 = *(int *)(param_1 + 0x44);
    if (((iVar5 == 0x4b771290) || (iVar5 == -0x5fd65969)) || (iVar5 == -0xfc486fa)) {
      if (*(char *)(param_1 + 0x38) == '\0') {
        uVar10 = *(uint *)(param_1 + 0x2c) & *(uint *)(param_1 + 0x30);
      }
      else {
        uVar10 = 7;
      }
    }
    else {
      sqlite3_log(0x15,"API call with %s database connection pointer");
      sqlite3_log(0x15,"misuse at line %d of [%.10s]");
      uVar10 = 0x15;
    }
    if (uVar13 == uVar10) {
      if (param_5 != (int *)0x0) {
        pcVar9 = sqlite3_errmsg(param_1);
        uVar10 = 0;
        if (pcVar9 != (char *)0x0) {
          cVar1 = *pcVar9;
          pcVar11 = pcVar9;
          while (cVar1 != '\0') {
            pcVar11 = pcVar11 + 1;
            cVar1 = *pcVar11;
          }
          uVar10 = (int)pcVar11 - (int)pcVar9 & 0x3fffffff;
        }
        sVar14 = uVar10 + 1;
        iVar5 = sqlite3Malloc(sVar14);
        *param_5 = iVar5;
        if (iVar5 == 0) {
          uVar13 = 7;
          sqlite3ErrorWithMsg(param_1,7,(byte *)0x0);
        }
        else {
          pcVar9 = sqlite3_errmsg(param_1);
          memcpy((void *)*param_5,pcVar9,sVar14);
        }
      }
      goto LAB_0046360d;
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
LAB_0046360d:
  if (*(int *)(param_1 + 0xc) != 0) {
    (*DAT_00582b20)(*(int *)(param_1 + 0xc));
  }
  return uVar13;
}




/* [AUDIT] proposed: sqlite3_overloadFunction  (confidence: med)
 * purpose: Creates/overrides a SQL function stub (findFunction 4995c0 else createFunction 493f20); SQLite; 'MATCH' caller
 * vars: param_2=name; sets db errcode
 */
/* Global::sqlite3_overloadFunction @ 00464130 */

uint __cdecl sqlite3_overloadFunction(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  byte *pbVar5;
  size_t sVar6;
  
  sVar6 = 0;
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_2;
    pbVar5 = param_2;
    while (bVar1 != 0) {
      pbVar5 = pbVar5 + 1;
      bVar1 = *pbVar5;
    }
    sVar6 = (int)pbVar5 - (int)param_2 & 0x3fffffff;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    (*DAT_00582b18)(*(int *)(param_1 + 0xc));
  }
  psVar3 = sqlite3FindFunction(param_1,param_2,sVar6,param_3,1,'\0');
  if (psVar3 == (short *)0x0) {
    uVar4 = sqlite3CreateFunc(param_1,param_2,param_3,1,0,0x49f6a0,0,0,(int *)0x0);
  }
  else {
    uVar4 = 0;
  }
  if ((*(char *)(param_1 + 0x38) != '\0') || (uVar4 == 0xc0a)) {
    sqlite3ErrorWithMsg(param_1,7,(byte *)0x0);
    *(undefined1 *)(param_1 + 0x38) = 0;
    uVar4 = 7;
  }
  uVar2 = *(uint *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0xc) != 0) {
    (*DAT_00582b20)(*(int *)(param_1 + 0xc));
  }
  return uVar2 & uVar4;
}




/* [AUDIT] proposed: sqlite3_vfs_find  (confidence: high)
 * purpose: Finds registered VFS by name in linked list under mutex; SQLite sqlite3_vfs_find
 * vars: DAT_00583e70 vfs list; +0x10 name +0xc next
 */
/* Global::sqlite3_vfs_find @ 00464e80 */

int __cdecl sqlite3_vfs_find(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar2 = sqlite3_initialize();
  if (iVar2 != 0) {
    return 0;
  }
  if (DAT_00582acc == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*DAT_00582b10)(2);
    if (iVar2 != 0) {
      (*DAT_00582b18)(iVar2);
    }
  }
  iVar6 = DAT_00583e70;
  if (DAT_00583e70 != 0) {
    while (param_1 != (byte *)0x0) {
      pbVar3 = *(byte **)(iVar6 + 0x10);
      pbVar5 = param_1;
      do {
        bVar1 = *pbVar5;
        bVar7 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_00464ef1:
          uVar4 = -(uint)bVar7 | 1;
          goto LAB_00464ef6;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar7 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_00464ef1;
        pbVar5 = pbVar5 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      uVar4 = 0;
LAB_00464ef6:
      if ((uVar4 == 0) || (iVar6 = *(int *)(iVar6 + 0xc), iVar6 == 0)) break;
    }
  }
  if (iVar2 != 0) {
    (*DAT_00582b20)(iVar2);
  }
  return iVar6;
}




/* [AUDIT] proposed: sqlite3_mutex_enter_ind  (confidence: high)
 * purpose: Indirect call to mutex-enter (DAT_00582b18) if arg nonzero; SQLite mutex wrapper
 * vars: -
 */
/* Global::sqlite3_mutex_enter_ind @ 004650e0 */

void __cdecl sqlite3_mutex_enter_ind(int param_1)

{
  if (param_1 != 0) {
    (*DAT_00582b18)();
    return;
  }
  return;
}




/* [AUDIT] proposed: sqlite3_mutex_leave_ind  (confidence: high)
 * purpose: Indirect call to mutex-leave (DAT_00582b20) if arg nonzero; SQLite mutex wrapper
 * vars: -
 */
/* Global::sqlite3_mutex_leave_ind @ 00465120 */

void __cdecl sqlite3_mutex_leave_ind(int param_1)

{
  if (param_1 != 0) {
    (*DAT_00582b20)();
    return;
  }
  return;
}




/* [AUDIT] proposed: sqlite3_snprintf_guarded  (confidence: med)
 * purpose: Reentrancy-guarded printf-to-buffer (4bc920 check then 466700); SQLite public snprintf-style entry
 * vars: varargs via stack
 */
/* Global::sqlite3_snprintf_guarded @ 004666d0 */

undefined4 __cdecl sqlite3_snprintf_guarded(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sqlite3_initialize();
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = sqlite3_vxprintf_toBuf(param_1,(double *)&stack0x00000008);
  return uVar2;
}




/* [AUDIT] proposed: sqlite3_vxprintf_toBuf  (confidence: med)
 * purpose: Formats into a fixed 72-byte StrAccum buffer via 4ad370/4aa8f0; SQLite vsnprintf implementation
 * vars: local_50 buffer; local_5c=0x46 cap
 */
/* Global::sqlite3_vxprintf_toBuf @ 00466700 */

void __cdecl sqlite3_vxprintf_toBuf(byte *param_1,double *param_2)

{
  int iVar1;
  int local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54;
  undefined2 local_53;
  undefined1 local_50 [72];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  iVar1 = sqlite3_initialize();
  if (iVar1 != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_68 = local_50;
  local_6c = 0;
  local_60 = 0;
  local_5c = 0x46;
  local_58 = 1000000000;
  local_53 = 2;
  local_54 = 0;
  local_64 = local_68;
  sqlite3VXPrintf(&local_6c,0,param_1,param_2);
  sqlite3StrAccumFinish(&local_6c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: sqlite3_snprintf_impl  (confidence: med)
 * purpose: StrAccum-based snprintf into buffer with size param_1 (4ad370 format, 4aa8f0 finalize); SQLite
 * vars: local_10=max; local_1c dest
 */
/* Global::sqlite3_snprintf_impl @ 00466a80 */

void __cdecl sqlite3_snprintf_impl(int param_1,undefined4 param_2,byte *param_3)

{
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined2 local_7;
  
  if (0 < param_1) {
    local_1c = param_2;
    local_18 = param_2;
    local_20 = 0;
    local_14 = 0;
    local_10 = param_1;
    local_c = 0;
    local_7 = 0;
    local_8 = 0;
    sqlite3VXPrintf(&local_20,0,param_3,(double *)&stack0x00000010);
    sqlite3StrAccumFinish(&local_20);
  }
  return;
}




/* [AUDIT] proposed: sqlite3_free  (confidence: high)
 * purpose: Frees memory with allocator accounting/statistics (DAT_00582aec free); SQLite sqlite3_free/DbFree
 * vars: DAT_00583e18 used bytes
 */
/* Global::sqlite3_free @ 00466dd0 */

void __cdecl sqlite3_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (DAT_00582ac8 == 0) {
      (*DAT_00582aec)(param_1);
    }
    else {
      if (DAT_00583f40 != 0) {
        (*DAT_00582b18)(DAT_00583f40);
      }
      iVar1 = (*DAT_00582af0._4_4_)(param_1);
      DAT_00583e18 = DAT_00583e18 - iVar1;
      if (DAT_00583e40 < DAT_00583e18) {
        DAT_00583e40 = DAT_00583e18;
      }
      DAT_00583e3c = DAT_00583e3c + -1;
      if (DAT_00583e64 < DAT_00583e3c) {
        DAT_00583e64 = DAT_00583e3c;
      }
      (*DAT_00582aec)(param_1);
      if (DAT_00583f40 != 0) {
        (*DAT_00582b20)();
        return;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3_randomness  (confidence: high)
 * purpose: Fills param_2 with param_1 pseudo-random bytes (RC4 PRNG 487580) under mutex; SQLite sqlite3_randomness
 * vars: -
 */
/* Global::sqlite3_randomness @ 00466fa0 */

void __cdecl sqlite3_randomness(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_00582acc == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*DAT_00582b10)(5);
    if (iVar2 != 0) {
      (*DAT_00582b18)(iVar2);
    }
  }
  for (; param_1 != 0; param_1 = param_1 + -1) {
    uVar1 = prng_nextByte();
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  if (iVar2 != 0) {
    (*DAT_00582b20)(iVar2);
  }
  return;
}




/* [AUDIT] proposed: sqlite3_open  (confidence: high)
 * purpose: Wrapper: openDatabase(4834d0, flags=6); SQLite sqlite3_open; misattributed Speech
 * vars: -
 */
/* Global::sqlite3_open @ 00467f50 */

void __cdecl sqlite3_open(int *param_1,undefined4 *param_2)

{
  openDatabase(param_1,param_2,6,(byte *)0x0);
  return;
}




/* [AUDIT] proposed: sqlite3_log  (confidence: high)
 * purpose: If log hook set (DAT_00582bac), formats and emits log message via 4885a0; SQLite sqlite3_log; misattributed Speech
 * vars: varargs
 */
/* Global::sqlite3_log @ 004683f0 */

void __cdecl sqlite3_log(undefined4 param_1,undefined4 param_2)

{
  if (DAT_00582bac != 0) {
    sqlite3_logCallback(param_1,param_2,&stack0x0000000c);
  }
  return;
}




/* [AUDIT] proposed: sqlite3_errcode  (confidence: high)
 * purpose: Validates db handle magic; returns errCode&errMask or MISUSE(0x15)/NOMEM(7); SQLite sqlite3_errcode
 * vars: +0x44 magic; +0x30/+0x2c code/mask
 */
/* Global::sqlite3_errcode @ 00468670 */

uint __cdecl sqlite3_errcode(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x44);
    if (((iVar1 != 0x4b771290) && (iVar1 != -0x5fd65969)) && (iVar1 != -0xfc486fa)) {
      sqlite3_log(0x15,"API call with %s database connection pointer");
      sqlite3_log(0x15,"misuse at line %d of [%.10s]");
      return 0x15;
    }
    if (*(char *)(param_1 + 0x38) == '\0') {
      return *(uint *)(param_1 + 0x30) & *(uint *)(param_1 + 0x2c);
    }
  }
  return 7;
}




/* [AUDIT] proposed: sqlite3_prepare  (confidence: high)
 * purpose: Wrapper: sqlite3Prepare(4a0180,...); SQLite sqlite3_prepare
 * vars: -
 */
/* Global::sqlite3_prepare @ 00468e30 */

void __cdecl sqlite3_prepare(int param_1,void *param_2,size_t param_3,undefined4 *param_4,int *param_5)

{
  sqlite3LockAndPrepare(param_1,param_2,param_3,0,0,param_4,param_5);
  return;
}




/* [AUDIT] proposed: sqlite3_bind_text  (confidence: high)
 * purpose: Wrapper: bindText(4709e0,...,1); SQLite sqlite3_bind_text
 * vars: -
 */
/* Global::sqlite3_bind_text @ 00469510 */

void __cdecl sqlite3_bind_text(int *param_1,int param_2,void *param_3,size_t param_4,undefined *param_5)

{
  sqlite3_bindValue(param_1,param_2,param_3,param_4,param_5,'\x01');
  return;
}




/* [AUDIT] proposed: sqlite3_column_value  (confidence: high)
 * purpose: Returns applied Mem value for column param_2 under mutex (4ae680); SQLite sqlite3_column_value
 * vars: param_1[0xb]=nCol; [4]=aMem
 */
/* Global::sqlite3_column_value @ 00469a30 */

int __cdecl sqlite3_column_value(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if ((param_2 < (int)(uint)*(ushort *)(param_1 + 0xb)) && (-1 < param_2)) {
    if (*(int *)(iVar1 + 0xc) != 0) {
      (*DAT_00582b18)(*(int *)(iVar1 + 0xc));
    }
    iVar2 = sqlite3ValueApplyAffinity((int *)(param_1[4] + param_2 * 0x28),1);
    if (*(char *)(iVar1 + 0x38) != '\0') {
      *(undefined1 *)(iVar1 + 0x38) = 0;
      iVar2 = 0;
    }
    if (*(int *)(iVar1 + 0xc) != 0) {
      (*DAT_00582b20)(*(int *)(iVar1 + 0xc));
    }
    return iVar2;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3_step  (confidence: high)
 * purpose: SQLite sqlite3_step: runs VDBE, retries on SCHEMA(0x11) up to 5x re-preparing; 'API called with finalized/NULL prepared statement'
 * vars: puVar3=stmt; local_8=db
 */
/* Global::sqlite3_step_469cb0 @ 00469cb0 */

uint __cdecl sqlite3_step_469cb0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  char *pcVar10;
  uint local_cc [48];
  int local_c;
  uint local_8;
  
  puVar3 = param_1;
  if (param_1 == (uint *)0x0) {
    pcVar10 = "API called with NULL prepared statement";
  }
  else {
    local_8 = *param_1;
    if (local_8 != 0) {
      if (*(int *)(local_8 + 0xc) != 0) {
        (*DAT_00582b18)(*(int *)(local_8 + 0xc));
      }
      puVar3[0x18] = puVar3[0x18] & 0xfffffbff;
      uVar4 = sqlite3Step(puVar3);
      iVar7 = 0;
      if (uVar4 == 0x11) {
        while (local_c = iVar7 + 1, iVar7 < 5) {
          if ((puVar3[0x18] & 0x200) == 0) {
            pvVar5 = (void *)0x0;
          }
          else {
            pvVar5 = (void *)puVar3[0x26];
          }
          uVar1 = *puVar3;
          uVar4 = sqlite3LockAndPrepare(uVar1,pvVar5,0xffffffff,0,(int)puVar3,&param_1,(int *)0x0);
          uVar2 = local_8;
          if (uVar4 != 0) {
            if (uVar4 == 7) {
              *(undefined1 *)(uVar1 + 0x38) = 1;
            }
            if (((puVar3[0x18] & 0x200) != 0) && (*(int **)(local_8 + 0xd4) != (int *)0x0)) {
              param_1 = (uint *)sqlite3ValueApplyAffinity(*(int **)(local_8 + 0xd4),1);
              sqlite3PageFree(uVar2,(undefined4 *)puVar3[0xd]);
              if (*(char *)(uVar2 + 0x38) == '\0') {
                puVar6 = sqlite3PageStrdup(uVar2,(char *)param_1);
                puVar3[0xd] = (uint)puVar6;
              }
              else {
                puVar3[0xd] = 0;
                uVar4 = 7;
              }
              puVar3[0x16] = uVar4;
            }
            break;
          }
          puVar8 = param_1;
          puVar9 = local_cc;
          for (iVar7 = 0x30; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          puVar8 = puVar3;
          puVar9 = param_1;
          for (iVar7 = 0x30; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          puVar8 = local_cc;
          puVar9 = puVar3;
          for (iVar7 = 0x30; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          uVar4 = param_1[0xf];
          param_1[0xf] = puVar3[0xf];
          puVar3[0xf] = uVar4;
          uVar4 = param_1[0xe];
          param_1[0xe] = puVar3[0xe];
          puVar3[0xe] = uVar4;
          pvVar5 = (void *)param_1[0x26];
          param_1[0x26] = puVar3[0x26];
          puVar3[0x26] = (uint)pvVar5;
          puVar3[0x18] = puVar3[0x18] ^ (param_1[0x18] ^ puVar3[0x18]) & 0x200;
          sqlite3VdbeFrameRestore(pvVar5,(int)param_1,(int *)puVar3);
          puVar8 = param_1;
          param_1[0x16] = 0;
          if ((param_1[0xc] == 0xbdf20da3) || (param_1[0xc] == 0x519c2973)) {
            sqlite3VdbeHalt((int *)param_1);
          }
          uVar4 = *puVar8;
          sqlite3VdbeFreeCursorsAndProgram(uVar4,(int)puVar8);
          if (puVar8[0xe] == 0) {
            *(uint *)(uVar4 + 4) = puVar8[0xf];
          }
          else {
            *(uint *)(puVar8[0xe] + 0x3c) = puVar8[0xf];
          }
          if (puVar8[0xf] != 0) {
            *(uint *)(puVar8[0xf] + 0x38) = puVar8[0xe];
          }
          puVar8[0xc] = 0xb606c3c8;
          *puVar8 = 0;
          sqlite3PageFree(uVar4,puVar8);
          sqlite3_reset((int *)puVar3);
          puVar3[0x18] = puVar3[0x18] | 0x400;
          uVar4 = sqlite3Step(puVar3);
          iVar7 = local_c;
          if (uVar4 != 0x11) break;
        }
      }
      uVar1 = local_8;
      if ((*(char *)(local_8 + 0x38) != '\0') || (uVar4 == 0xc0a)) {
        sqlite3ErrorWithMsg(local_8,7,(byte *)0x0);
        *(undefined1 *)(uVar1 + 0x38) = 0;
        uVar4 = 7;
      }
      uVar2 = *(uint *)(uVar1 + 0x30);
      if (*(int *)(uVar1 + 0xc) != 0) {
        (*DAT_00582b20)(*(int *)(uVar1 + 0xc));
      }
      return uVar2 & uVar4;
    }
    pcVar10 = "API called with finalized prepared statement";
    local_8 = 0;
  }
  sqlite3_log(0x15,pcVar10);
  sqlite3_log(0x15,"misuse at line %d of [%.10s]");
  return 0x15;
}




/* [AUDIT] proposed: sqlite3_column_int  (confidence: high)
 * purpose: Fetches column value applying int affinity (4ae680) with mutex; SQLite sqlite3_column_int
 * vars: piVar1=Mem; +7 flags
 */
/* Global::sqlite3_column_int @ 00469f40 */

int __cdecl sqlite3_column_int(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)sqlite3_columnMem(param_1,param_2);
  if ((*(byte *)(piVar1 + 7) & 0x12) == 0) {
    iVar2 = sqlite3ValueApplyAffinity(piVar1,1);
    sqlite3_column_apiExit(param_1);
    return iVar2;
  }
  sqlite3VdbeMemExpandBlob(piVar1);
  *(ushort *)(piVar1 + 7) = *(ushort *)(piVar1 + 7) & 0xfffd | 0x10;
  if (piVar1[6] != 0) {
    iVar2 = piVar1[1];
    sqlite3_column_apiExit(param_1);
    return iVar2;
  }
  sqlite3_column_apiExit(param_1);
  return 0;
}




/* [AUDIT] proposed: sqlite3_column_bytes  (confidence: high)
 * purpose: Returns byte length of column value (applies text/blob) with mutex; SQLite sqlite3_column_bytes
 * vars: Mem+6 n; +7 flags 0x4000
 */
/* Global::sqlite3_column_bytes @ 00469fc0 */

int __cdecl sqlite3_column_bytes(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)sqlite3_columnMem(param_1,param_2);
  if ((*(byte *)(piVar1 + 7) & 0x10) == 0) {
    iVar2 = sqlite3ValueApplyAffinity(piVar1,1);
    if (iVar2 == 0) {
      sqlite3_column_apiExit(param_1);
      return 0;
    }
  }
  iVar2 = piVar1[6];
  if ((*(ushort *)(piVar1 + 7) & 0x4000) != 0) {
    iVar2 = iVar2 + piVar1[4];
  }
  sqlite3_column_apiExit(param_1);
  return iVar2;
}




/* [AUDIT] proposed: sqlite3_clear_bindings  (confidence: high)
 * purpose: Resets all bound parameters of stmt (4b5e70 reset, 48ca70 apiExit); SQLite sqlite3_clear_bindings; 'API called with finalized...'
 * vars: -
 */
/* Global::sqlite3_clear_bindings_46aa30 @ 0046aa30 */

uint __cdecl sqlite3_clear_bindings_46aa30(int *param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
    sqlite3_log(0x15,"API called with finalized prepared statement");
    sqlite3_log(0x15,"misuse at line %d of [%.10s]");
    return 0x15;
  }
  if (piVar1[3] != 0) {
    (*DAT_00582b18)(piVar1[3]);
  }
  uVar2 = sqlite3VdbeDelete(param_1);
  uVar2 = sqlite3_apiExit((int)piVar1,uVar2);
  sqlite3Close(piVar1);
  return uVar2;
}




/* [AUDIT] proposed: sqlite3_reset  (confidence: high)
 * purpose: Resets a prepared statement (VdbeReset 4b8640, reinit state fields); SQLite sqlite3_reset; misattributed Speech
 * vars: param_1[0x14] pc=1; magic -0x420df25d
 */
/* Global::sqlite3_reset @ 0046aab0 */

uint __cdecl sqlite3_reset(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (*(int *)(*param_1 + 0xc) != 0) {
    (*DAT_00582b18)(*(int *)(*param_1 + 0xc));
  }
  uVar2 = sqlite3VdbeHalt(param_1);
  iVar1 = *param_1;
  param_1[0x15] = -1;
  param_1[0x16] = 0;
  *(undefined2 *)(param_1 + 0x17) = 0xff02;
  param_1[0xc] = -0x420df25d;
  param_1[0x19] = 0;
  param_1[0x14] = 1;
  param_1[0x1c] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  if (iVar1 == 0) {
    uVar3 = 0xff;
  }
  else {
    if ((*(char *)(iVar1 + 0x38) != '\0') || (uVar2 == 0xc0a)) {
      sqlite3ErrorWithMsg(iVar1,7,(byte *)0x0);
      *(undefined1 *)(iVar1 + 0x38) = 0;
      uVar2 = 7;
    }
    uVar3 = *(uint *)(iVar1 + 0x30);
  }
  if (*(int *)(*param_1 + 0xc) != 0) {
    (*DAT_00582b20)(*(int *)(*param_1 + 0xc));
  }
  return uVar3 & uVar2;
}




/* [AUDIT] proposed: btree_accessPayload  (confidence: high)
 * purpose: Reads btree cell payload (param_2..+param_3) into buffer, traversing overflow pages; SQLite; 'database corruption'
 * vars: local_c cell ptr; local_14 pBt; overflow chain
 */
/* Global::btree_accessPayload @ 0046b2f0 */

uint __cdecl btree_accessPayload(int param_1,uint param_2,size_t param_3,void *param_4,int param_5)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  size_t sVar7;
  undefined4 *puVar8;
  FILL unaff_EDI;
  undefined4 *local_24;
  size_t local_20;
  size_t local_1c;
  void *local_18;
  int *local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_14 = *(int **)(param_1 + 4);
  sVar7 = *(size_t *)(param_1 + 0x88 + *(short *)(param_1 + 0x5e) * 4);
  local_8 = 0;
  local_20 = sVar7;
  if (*(short *)(param_1 + 0x42) == 0) {
    uVar4 = (uint)*(ushort *)(param_1 + 0x60 + *(short *)(param_1 + 0x5e) * 2);
    btree_parseCellPtr(sVar7,(uint)(CONCAT11(*(undefined1 *)(*(int *)(sVar7 + 0x40) + uVar4 * 2),
                                       *(undefined1 *)(*(int *)(sVar7 + 0x40) + 1 + uVar4 * 2)) &
                             *(ushort *)(sVar7 + 0x12)) + *(int *)(sVar7 + 0x38),
                 (uint *)(param_1 + 0x28));
    *(undefined1 *)(param_1 + 0x5a) = 1;
  }
  local_c = (undefined4 *)((uint)*(ushort *)(param_1 + 0x3c) + *(int *)(param_1 + 0x30));
  if (*(char *)(sVar7 + 2) == '\0') {
    iVar5 = *(int *)(param_1 + 0x28);
  }
  else {
    iVar5 = 0;
  }
  if (((uint)(*(int *)(param_1 + 0x34) + iVar5) < param_2 + param_3) ||
     (uVar4 = 0,
     (uint)(*(int *)(local_20 + 0x38) + local_14[9]) <
     (uint)*(ushort *)(param_1 + 0x3e) + (int)local_c)) goto LAB_0046b612;
  uVar6 = (uint)*(ushort *)(param_1 + 0x3e);
  if (param_2 < uVar6) {
    local_1c = param_3;
    if (uVar6 < param_2 + param_3) {
      local_1c = uVar6 - param_2;
    }
    uVar4 = btree_copyPayload((void *)((int)local_c + param_2),param_4,local_1c,param_5,
                         *(undefined4 **)(local_20 + 0x44));
    param_3 = param_3 - local_1c;
    local_18 = (void *)((int)param_4 + local_1c);
    param_2 = 0;
    local_8 = uVar4;
    if (uVar4 != 0) {
      return uVar4;
    }
  }
  else {
    param_2 = param_2 - uVar6;
    local_18 = param_4;
  }
  if (param_3 == 0) {
    return uVar4;
  }
  local_20 = (size_t)*(ushort *)(param_1 + 0x3e);
  puVar8 = (undefined4 *)
           CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_20 + (int)local_c),
                                      *(undefined1 *)(local_20 + 1 + (int)local_c)),
                             *(undefined1 *)(local_20 + 2 + (int)local_c)),
                    *(undefined1 *)(local_20 + 3 + (int)local_c));
  local_10 = local_14[9] - 4;
  local_c = puVar8;
  if ((*(char *)(param_1 + 0x5c) != '\0') && (*(int *)(param_1 + 0x14) == 0)) {
    uVar6 = ((*(int *)(param_1 + 0x38) - local_20) + -1 + local_10) / local_10;
    pvVar3 = operator_new__(uVar6 * 4,unaff_EDI);
    *(void **)(param_1 + 0x14) = pvVar3;
    uVar4 = local_8;
    if ((uVar6 != 0) && (pvVar3 == (void *)0x0)) {
      uVar4 = 7;
    }
  }
  local_20 = *(size_t *)(param_1 + 0x14);
  if (local_20 == 0) {
LAB_0046b4d8:
    uVar6 = 0;
  }
  else {
    uVar6 = param_2 / local_10;
    if (*(int *)(local_20 + uVar6 * 4) == 0) goto LAB_0046b4d8;
    puVar8 = *(undefined4 **)(local_20 + uVar6 * 4);
    param_2 = param_2 % local_10;
    local_c = puVar8;
  }
  if (uVar4 == 0) {
    local_1c = uVar6 << 2;
    sVar7 = param_3;
    uVar6 = param_2;
    while ((sVar7 != 0 && (puVar8 != (undefined4 *)0x0))) {
      if (*(int *)(param_1 + 0x14) != 0) {
        *(undefined4 **)(local_1c + *(int *)(param_1 + 0x14)) = puVar8;
        sVar7 = param_3;
      }
      if (uVar6 < local_10) {
        local_20 = sVar7;
        if (local_10 < uVar6 + sVar7) {
          local_20 = local_10 - uVar6;
        }
        local_8 = getAndInitPage(*local_14,(uint)puVar8,(int *)&local_24,0);
        puVar1 = local_24;
        if (local_8 == 0) {
          puVar2 = (undefined1 *)local_24[1];
          puVar8 = (undefined4 *)sqlite3Get4byte(puVar2);
          local_c = puVar8;
          local_8 = btree_copyPayload(puVar2 + param_2 + 4,local_18,local_20,param_5,puVar1);
          sqlite3PagerUnrefNotNull(puVar1);
          uVar6 = 0;
          param_2 = 0;
        }
        sVar7 = param_3 - local_20;
        local_18 = (void *)((int)local_18 + local_20);
        uVar4 = local_8;
        param_3 = sVar7;
      }
      else {
        local_20 = *(size_t *)(param_1 + 0x14);
        if ((local_20 == 0) ||
           (puVar1 = *(undefined4 **)(local_1c + 4 + local_20), uVar6 = param_2,
           puVar1 == (undefined4 *)0x0)) {
          uVar4 = btree_getOverflowPage(local_14,puVar8,(int *)0x0,&local_c);
          uVar6 = uVar6 - local_10;
          sVar7 = param_3;
          puVar8 = local_c;
          param_2 = uVar6;
        }
        else {
          uVar6 = param_2 - local_10;
          puVar8 = puVar1;
          param_2 = uVar6;
          local_c = puVar1;
        }
      }
      local_1c = local_1c + 4;
      if (uVar4 != 0) {
        return uVar4;
      }
    }
    if ((uVar4 == 0) && (sVar7 != 0)) {
LAB_0046b612:
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      return 0xb;
    }
  }
  return uVar4;
}




/* [AUDIT] proposed: pager_setInAllSavepoints  (confidence: med)
 * purpose: For each savepoint bitvec sets the given page bit (bitvec 48ea60); SQLite pager savepoint set
 * vars: param_1+0x60 nSavepoint; puVar5 bitvec
 */
/* Global::pager_setInAllSavepoints @ 0046b780 */

uint __cdecl pager_setInAllSavepoints(int param_1,uint param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint local_18;
  uint *local_10;
  int local_c;
  int local_8;
  
  local_18 = 0;
  local_8 = 0;
  uVar6 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    local_c = 0;
    do {
      if ((param_2 <= *(uint *)(*(int *)(param_1 + 0x5c) + 0x14 + local_c)) &&
         (puVar5 = *(uint **)(*(int *)(param_1 + 0x5c) + 0x10 + local_c), puVar5 != (uint *)0x0)) {
        uVar6 = param_2 - 1;
        if (4000 < *puVar5) {
          do {
            uVar8 = puVar5[2];
            if (uVar8 == 0) break;
            uVar2 = uVar6 / uVar8;
            uVar6 = uVar6 % uVar8;
            if (puVar5[uVar2 + 3] == 0) {
              if (DAT_00582ac8 == 0) {
                local_10 = (uint *)(*DAT_00582ae8)(0x200);
              }
              else {
                if (DAT_00583f40 != 0) {
                  (*DAT_00582b18)(DAT_00583f40);
                }
                sqlite3_mallocRaw(0x200,(int *)&local_10);
                if (DAT_00583f40 != 0) {
                  (*DAT_00582b20)(DAT_00583f40);
                }
              }
              puVar3 = local_10;
              if (local_10 != (uint *)0x0) {
                memset(local_10,0,0x200);
                *puVar3 = uVar8;
              }
              puVar5[uVar2 + 3] = (uint)puVar3;
              if (puVar3 == (uint *)0x0) goto LAB_0046b906;
            }
            puVar5 = (uint *)puVar5[uVar2 + 3];
          } while (4000 < *puVar5);
          if (4000 < *puVar5) {
            uVar2 = uVar6 % 0x7d;
            uVar6 = uVar6 + 1;
            uVar8 = puVar5[uVar2 + 3];
            if (uVar8 == 0) {
              uVar8 = puVar5[1];
              if (0x7b < uVar8) goto LAB_0046b8e8;
            }
            else {
              do {
                if (uVar8 == uVar6) goto LAB_0046b9cc;
                uVar2 = uVar2 + 1 & -(uint)(uVar2 + 1 < 0x7d);
                uVar8 = puVar5[uVar2 + 3];
              } while (uVar8 != 0);
LAB_0046b8e8:
              uVar8 = puVar5[1];
              if (0x3d < uVar8) {
                puVar3 = (uint *)sqlite3Malloc(500);
                if (puVar3 == (uint *)0x0) {
LAB_0046b906:
                  local_18 = local_18 | 7;
                }
                else {
                  puVar7 = puVar5 + 3;
                  puVar9 = puVar3;
                  for (iVar4 = 0x7d; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar9 = *puVar7;
                    puVar7 = puVar7 + 1;
                    puVar9 = puVar9 + 1;
                  }
                  memset(puVar5 + 3,0,500);
                  puVar5[2] = (*puVar5 + 0x7c) / 0x7d;
                  uVar6 = bitvec_set(puVar5,uVar6);
                  uVar8 = 0;
                  do {
                    if (puVar3[uVar8] != 0) {
                      uVar2 = bitvec_set(puVar5,puVar3[uVar8]);
                      uVar6 = uVar6 | uVar2;
                    }
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < 0x7d);
                  sqlite3_free((int)puVar3);
                  local_18 = local_18 | uVar6;
                }
                goto LAB_0046b9cc;
              }
            }
            puVar5[1] = uVar8 + 1;
            puVar5[uVar2 + 3] = uVar6;
            goto LAB_0046b9cc;
          }
        }
        pbVar1 = (byte *)((uVar6 >> 3) + 0xc + (int)puVar5);
        *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar6 & 7);
      }
LAB_0046b9cc:
      local_8 = local_8 + 1;
      local_c = local_c + 0x30;
      uVar6 = local_18;
    } while (local_8 < *(int *)(param_1 + 0x60));
  }
  return uVar6;
}




/* [AUDIT] proposed: btree_moveToNext  (confidence: med)
 * purpose: Advances/moves a btree cursor to next cell or child page, allocating pages; SQLite; 'database corruption'
 * vars: local_14 pBt; local_1c maxPage
 */
/* Global::btree_moveToNext @ 0046bae0 */

uint __cdecl btree_moveToNext(int *param_1,int *param_2,uint *param_3,undefined4 *param_4,char param_5)

{
  undefined1 uVar1;
  uint *puVar2;
  undefined3 uVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined3 extraout_var;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *local_2c;
  undefined4 *local_28;
  int local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  byte local_5;
  
  iVar10 = 0;
  local_14 = param_1[3];
  local_1c = (undefined4 *)param_1[0xb];
  iVar6 = *(int *)(local_14 + 0x38);
  puVar11 = (undefined4 *)
            CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 0x24),*(undefined1 *)(iVar6 + 0x25)),
                              *(undefined1 *)(iVar6 + 0x26)),*(undefined1 *)(iVar6 + 0x27));
  if (local_1c <= puVar11) {
    sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
    return 0xb;
  }
  if (puVar11 == (undefined4 *)0x0) {
    uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(local_14 + 0x44));
    if (uVar5 != 0) {
      return uVar5;
    }
    uVar5 = DAT_00582bb8 / (uint)param_1[8];
    param_1[0xb] = param_1[0xb] + 1;
    if (param_1[0xb] == uVar5 + 1) {
      param_1[0xb] = param_1[0xb] + 1;
    }
    if (*(char *)((int)param_1 + 0x11) != '\0') {
      uVar5 = param_1[0xb];
      uVar8 = btree_ptrmapPageno((int)param_1,uVar5);
      if (uVar8 == uVar5) {
        local_28 = (undefined4 *)0x0;
        uVar5 = btree_getAndInitPage(param_1,uVar5,(int *)&local_28,1);
        puVar11 = local_28;
        if (uVar5 != 0) {
          return uVar5;
        }
        uVar5 = pagerPlaybackSavepoint((undefined4 *)local_28[0x11]);
        btree_releasePage((int)puVar11);
        if (uVar5 != 0) {
          return uVar5;
        }
        uVar5 = DAT_00582bb8 / (uint)param_1[8];
        param_1[0xb] = param_1[0xb] + 1;
        if (param_1[0xb] == uVar5 + 1) {
          param_1[0xb] = param_1[0xb] + 1;
        }
      }
    }
    iVar6 = param_1[0xb];
    iVar10 = *(int *)(param_1[3] + 0x38);
    *(char *)(iVar10 + 0x1c) = (char)((uint)iVar6 >> 0x18);
    *(char *)(iVar10 + 0x1d) = (char)((uint)iVar6 >> 0x10);
    *(char *)(iVar10 + 0x1e) = (char)((uint)iVar6 >> 8);
    *(char *)(iVar10 + 0x1f) = (char)iVar6;
    uVar5 = param_1[0xb];
    *param_3 = uVar5;
    uVar5 = btree_getAndInitPage(param_1,uVar5,param_2,1);
    if (uVar5 != 0) {
      return uVar5;
    }
    uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(*param_2 + 0x44));
    if (uVar5 == 0) goto LAB_0046c1ed;
    btree_releasePage(*param_2);
  }
  else {
    local_c = local_c & 0xffffff00;
    if ((param_5 != '\0') && (param_4 <= local_1c)) {
      uVar5 = btree_readCellPtrByte(param_1,param_4,&local_5,(undefined4 *)0x0);
      if (uVar5 != 0) {
        return uVar5;
      }
      local_c = local_c & 0xff;
      if (local_5 == 2) {
        local_c = 1;
      }
      *param_3 = (uint)param_4;
    }
    uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(local_14 + 0x44));
    if (uVar5 != 0) {
      return uVar5;
    }
    iVar6 = (int)puVar11 - 1;
    iVar7 = *(int *)(local_14 + 0x38);
    *(char *)(iVar7 + 0x24) = (char)((uint)iVar6 >> 0x18);
    *(char *)(iVar7 + 0x25) = (char)((uint)iVar6 >> 0x10);
    *(char *)(iVar7 + 0x26) = (char)((uint)iVar6 >> 8);
    *(char *)(iVar7 + 0x27) = (char)iVar6;
    do {
      if (iVar10 == 0) {
        iVar6 = *(int *)(local_14 + 0x38);
        uVar3 = CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 0x20),*(undefined1 *)(iVar6 + 0x21)),
                         *(undefined1 *)(iVar6 + 0x22));
        uVar1 = *(undefined1 *)(iVar6 + 0x23);
      }
      else {
        puVar9 = *(undefined1 **)(iVar10 + 0x38);
        uVar3 = CONCAT21(CONCAT11(*puVar9,puVar9[1]),puVar9[2]);
        uVar1 = puVar9[3];
      }
      puVar11 = (undefined4 *)CONCAT31(uVar3,uVar1);
      local_18 = iVar10;
      if (local_1c < puVar11) {
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        uVar5 = 0xb;
        goto LAB_0046c0a1;
      }
      uVar5 = getAndInitPage(*param_1,(uint)puVar11,(int *)&local_2c,0);
      if (uVar5 != 0) goto LAB_0046c0a1;
      iVar10 = local_2c[2];
      *(undefined4 *)(iVar10 + 0x38) = local_2c[1];
      *(int **)(iVar10 + 0x34) = param_1;
      *(byte *)(iVar10 + 5) = (puVar11 != (undefined4 *)0x1) - 1U & 100;
      local_10 = *(int *)(iVar10 + 0x38);
      *(undefined4 **)(iVar10 + 0x44) = local_2c;
      *(undefined4 **)(iVar10 + 0x48) = puVar11;
      local_20 = (undefined4 *)
                 CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_10 + 4),
                                            *(undefined1 *)(local_10 + 5)),
                                   *(undefined1 *)(local_10 + 6)),*(undefined1 *)(local_10 + 7));
      if ((local_20 == (undefined4 *)0x0) && ((char)local_c == '\0')) {
        uVar5 = pagerPlaybackSavepoint(local_2c);
        if (uVar5 == 0) {
          *param_3 = (uint)puVar11;
          *(undefined4 *)(*(int *)(local_14 + 0x38) + 0x20) = **(undefined4 **)(iVar10 + 0x38);
          *param_2 = iVar10;
          iVar10 = 0;
          goto LAB_0046bfc6;
        }
        break;
      }
      if ((undefined4 *)(((uint)param_1[9] >> 2) - 2) < local_20) {
LAB_0046c041:
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        uVar5 = 0xb;
        break;
      }
      if (((char)local_c == '\0') || (param_4 != puVar11)) {
        if (local_20 != (undefined4 *)0x0) {
          if (param_4 == (undefined4 *)0x0) {
LAB_0046bed0:
            puVar12 = (undefined4 *)0x0;
          }
          else {
            local_28 = (undefined4 *)0x0;
            iVar6 = sqlite3Get4byte((undefined1 *)(local_10 + 8));
            iVar6 = abs32(iVar6 - (int)param_4);
            puVar11 = (undefined4 *)0x1;
            if (local_20 < (undefined4 *)0x2) goto LAB_0046bed0;
            puVar9 = (undefined1 *)(local_10 + 0xe);
            do {
              iVar7 = CONCAT31(CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9),puVar9[1]) -
                      (int)param_4;
              if (iVar7 < 0) {
                if (iVar7 == -0x80000000) {
                  iVar7 = 0x7fffffff;
                }
                else {
                  iVar7 = -iVar7;
                }
              }
              if (iVar7 < iVar6) {
                iVar6 = iVar7;
                local_28 = puVar11;
              }
              puVar11 = (undefined4 *)((int)puVar11 + 1);
              puVar9 = puVar9 + 4;
              puVar12 = local_28;
            } while (puVar11 < local_20);
          }
          puVar11 = (undefined4 *)
                    CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_10 + 8 + (int)puVar12 * 4),
                                               *(undefined1 *)(local_10 + 9 + (int)puVar12 * 4)),
                                      *(undefined1 *)(local_10 + 10 + (int)puVar12 * 4)),
                             *(undefined1 *)(local_10 + 0xb + (int)puVar12 * 4));
          if (local_1c < puVar11) goto LAB_0046c041;
          if (((char)local_c == '\0') || (puVar11 == param_4)) {
            *param_3 = (uint)puVar11;
            uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(iVar10 + 0x44));
            if (uVar5 != 0) break;
            puVar11 = (undefined4 *)((int)local_20 - 1);
            if (puVar12 < puVar11) {
              *(undefined4 *)(local_10 + 8 + (int)puVar12 * 4) =
                   *(undefined4 *)(local_10 + 4 + (int)local_20 * 4);
            }
            *(char *)(local_10 + 4) = (char)((uint)puVar11 >> 0x18);
            *(char *)(local_10 + 5) = (char)((uint)puVar11 >> 0x10);
            *(char *)(local_10 + 6) = (char)((uint)puVar11 >> 8);
            *(char *)(local_10 + 7) = (char)puVar11;
            uVar5 = *param_3;
            puVar2 = (uint *)param_1[0xf];
            if ((puVar2 == (uint *)0x0) ||
               ((uVar5 <= *puVar2 &&
                (bVar4 = bitvec_test(puVar2,uVar5), CONCAT31(extraout_var,bVar4) == 0)))) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            uVar5 = btree_getAndInitPage(param_1,uVar5,param_2,(uint)!bVar4);
            if ((uVar5 == 0) &&
               (uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(*param_2 + 0x44)), uVar5 != 0)) {
              btree_releasePage(*param_2);
            }
            local_c = local_c & 0xffffff00;
          }
        }
      }
      else {
        local_c = local_c & 0xffffff00;
        *param_2 = iVar10;
        uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(iVar10 + 0x44));
        iVar6 = local_18;
        puVar11 = local_20;
        if (uVar5 != 0) break;
        if (local_20 == (undefined4 *)0x0) {
          if (local_18 == 0) {
            puVar11 = (undefined4 *)(iVar10 + 0x38);
            iVar10 = 0;
            *(undefined4 *)(*(int *)(local_14 + 0x38) + 0x20) = *(undefined4 *)*puVar11;
          }
          else {
            uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(local_18 + 0x44));
            if (uVar5 != 0) break;
            **(undefined4 **)(iVar6 + 0x38) = **(undefined4 **)(iVar10 + 0x38);
            iVar10 = 0;
          }
        }
        else {
          local_20 = (undefined4 *)sqlite3Get4byte((undefined1 *)(*(int *)(iVar10 + 0x38) + 8));
          if (local_1c < local_20) {
            uVar5 = sqlite3CorruptError();
            break;
          }
          uVar5 = btree_getAndInitPage(param_1,(uint)local_20,&local_24,0);
          if (uVar5 != 0) break;
          uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(local_24 + 0x44));
          if (uVar5 != 0) {
            btree_releasePage(local_24);
            break;
          }
          **(undefined4 **)(local_24 + 0x38) = **(undefined4 **)(iVar10 + 0x38);
          sqlite3Put4byte((undefined1 *)(*(int *)(local_24 + 0x38) + 4),(int)puVar11 - 1U);
          iVar6 = local_24;
          memcpy((void *)(*(int *)(local_24 + 0x38) + 8),(void *)(*(int *)(iVar10 + 0x38) + 0xc),
                 ((int)puVar11 - 1U) * 4);
          btree_releasePage(iVar6);
          iVar6 = local_18;
          if (local_18 == 0) {
            sqlite3Put4byte((undefined1 *)(*(int *)(local_14 + 0x38) + 0x20),local_20);
            iVar10 = 0;
          }
          else {
            uVar5 = pagerPlaybackSavepoint(*(undefined4 **)(local_18 + 0x44));
            if (uVar5 != 0) break;
            sqlite3Put4byte(*(undefined1 **)(iVar6 + 0x38),local_20);
            iVar10 = 0;
          }
        }
      }
LAB_0046bfc6:
      if ((local_18 != 0) &&
         (puVar11 = *(undefined4 **)(local_18 + 0x44), puVar11 != (undefined4 *)0x0)) {
        puVar2 = (uint *)puVar11[4];
        sqlite3PcacheRelease(puVar11);
        if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar2);
        }
      }
      local_18 = 0;
    } while ((char)local_c != '\0');
    if ((iVar10 != 0) && (puVar11 = *(undefined4 **)(iVar10 + 0x44), puVar11 != (undefined4 *)0x0))
    {
      puVar2 = (uint *)puVar11[4];
      sqlite3PcacheRelease(puVar11);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
    }
LAB_0046c0a1:
    if ((local_18 != 0) &&
       (puVar11 = *(undefined4 **)(local_18 + 0x44), puVar11 != (undefined4 *)0x0)) {
      puVar2 = (uint *)puVar11[4];
      sqlite3PcacheRelease(puVar11);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
    }
  }
  if (uVar5 != 0) {
    *param_2 = 0;
    return uVar5;
  }
LAB_0046c1ed:
  puVar9 = (undefined1 *)*param_2;
  puVar11 = *(undefined4 **)(puVar9 + 0x44);
  if (*(short *)((int)puVar11 + 0x1a) < 2) {
    *puVar9 = 0;
    return 0;
  }
  if ((puVar9 != (undefined1 *)0x0) && (puVar11 != (undefined4 *)0x0)) {
    puVar2 = (uint *)puVar11[4];
    sqlite3PcacheRelease(puVar11);
    if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar2);
    }
  }
  sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
  return 0xb;
}




/* [AUDIT] proposed: btree_balanceCleanup  (confidence: low)
 * purpose: Frees overflow, relocates trailing cells (via 47e2e0 insert), updates page count; SQLite btree balance/incrvacuum; 'database corruption'
 * vars: param_1[0xb] pgno; +9 usableSize
 */
/* Global::btree_balanceCleanup @ 0046e160 */

uint __cdecl btree_balanceCleanup(int *param_1)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint local_c;
  
  local_c = 0;
  puVar1 = (uint *)*param_1;
  for (iVar2 = param_1[2]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    sqlite3_free(*(int *)(iVar2 + 0x14));
    *(undefined4 *)(iVar2 + 0x14) = 0;
  }
  if (*(char *)((int)param_1 + 0x12) == '\0') {
    pcVar8 = (char *)param_1[0xb];
    if (pcVar8 < (char *)0x2) {
      pcVar5 = (char *)0x0;
    }
    else {
      uVar6 = (uint)param_1[9] / 5 + 1;
      iVar2 = ((uint)(pcVar8 + -2) / uVar6) * uVar6;
      pcVar5 = (char *)(iVar2 + 2);
      if (pcVar5 == (char *)(DAT_00582bb8 / (uint)param_1[8] + 1)) {
        pcVar5 = (char *)(iVar2 + 3);
      }
    }
    if ((pcVar5 == pcVar8) ||
       (pcVar5 = (char *)(DAT_00582bb8 / (uint)param_1[8] + 1), pcVar8 == pcVar5)) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      return 0xb;
    }
    iVar2 = *(int *)(param_1[3] + 0x38);
    iVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar2 + 0x24),*(undefined1 *)(iVar2 + 0x25)),
                              *(undefined1 *)(iVar2 + 0x26)),*(undefined1 *)(iVar2 + 0x27));
    uVar6 = (uint)param_1[9] / 5;
    iVar2 = btree_ptrmapPageno((int)param_1,(uint)pcVar8);
    pcVar7 = pcVar8 + (-iVar4 - (iVar2 + iVar4 + (uVar6 - (int)pcVar8)) / uVar6);
    if ((pcVar5 < pcVar8) && (pcVar7 < pcVar5)) {
      pcVar7 = pcVar7 + -1;
    }
    while( true ) {
      if (pcVar7 < (char *)0x2) {
        pcVar3 = (char *)0x0;
      }
      else {
        iVar2 = ((uint)(pcVar7 + -2) / (uVar6 + 1)) * (uVar6 + 1);
        pcVar3 = (char *)(iVar2 + 2);
        if (pcVar3 == pcVar5) {
          pcVar3 = (char *)(iVar2 + 3);
        }
      }
      if ((pcVar3 != pcVar7) && (pcVar7 != pcVar5)) break;
      pcVar7 = pcVar7 + -1;
    }
    if (pcVar8 < pcVar7) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      return 0xb;
    }
    uVar6 = 0;
    if (pcVar7 < pcVar8) {
      do {
        if (uVar6 != 0) break;
        uVar6 = btree_clearDbPage(param_1,(undefined4 *)pcVar7,pcVar8);
        pcVar8 = pcVar8 + -1;
      } while (pcVar7 < pcVar8);
      local_c = uVar6;
      if ((uVar6 != 0x65) && (uVar6 != 0)) goto LAB_0046e342;
    }
    if (iVar4 != 0) {
      local_c = pagerPlaybackSavepoint(*(undefined4 **)(param_1[3] + 0x44));
      *(undefined4 *)(*(int *)(param_1[3] + 0x38) + 0x20) = 0;
      *(undefined4 *)(*(int *)(param_1[3] + 0x38) + 0x24) = 0;
      iVar2 = *(int *)(param_1[3] + 0x38);
      *(char *)(iVar2 + 0x1c) = (char)((uint)pcVar7 >> 0x18);
      *(char *)(iVar2 + 0x1d) = (char)((uint)pcVar7 >> 0x10);
      *(char *)(iVar2 + 0x1e) = (char)((uint)pcVar7 >> 8);
      *(char *)(iVar2 + 0x1f) = (char)pcVar7;
      *(char **)(*param_1 + 0x18) = pcVar7;
      param_1[0xb] = (int)pcVar7;
    }
    if (local_c != 0) {
LAB_0046e342:
      sqlite3PagerCommitPhaseTwo_or_sync(puVar1);
      return local_c;
    }
  }
  return 0;
}




/* [AUDIT] proposed: btree_writeOverflow  (confidence: med)
 * purpose: Writes payload across overflow pages using 64-bit page math (allmul/alldvrm); SQLite fillInCell overflow write
 * vars: param_2=nData; page loop
 */
/* Global::btree_writeOverflow @ 0046e390 */


uint __cdecl btree_writeOverflow(int param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  uint uVar7;
  int extraout_ECX;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  uint uVar12;
  
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 4);
  iVar2 = *piVar1;
  uVar3 = piVar1[8];
  uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x18) + 4) + 0x20);
  uVar7 = uVar3;
  if ((int)uVar4 < (int)uVar3) {
    uVar7 = uVar4;
  }
  lVar10 = __allmul((uint)param_2,0,uVar4,(int)uVar4 >> 0x1f);
  uVar9 = 0;
  if ((uVar4 != uVar3) && (*(char *)(iVar2 + 0xe) != '\0')) {
    uVar9 = 8;
  }
  lVar6 = lVar10 - (int)uVar4;
  while( true ) {
    if (uVar9 != 0) {
      return uVar9;
    }
    uVar8 = (uint)((ulonglong)lVar6 >> 0x20);
    if (lVar10 <= lVar6) break;
    param_2 = (undefined4 *)0x0;
    uVar11 = __alldvrm((uint)lVar6,uVar8,uVar3,(int)uVar3 >> 0x1f);
    uVar12 = (int)uVar11 + 1;
    if (uVar12 != DAT_00582bb8 / *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x20) + 1) {
      uVar9 = getAndInitPage(iVar2,uVar12,(int *)&param_2,0);
      if ((uVar9 == 0) && (uVar9 = pagerPlaybackSavepoint(param_2), uVar9 == 0)) {
        uVar12 = uVar7;
        uVar11 = __allrem((uint)lVar6,uVar8,uVar4,(int)uVar4 >> 0x1f);
        memcpy((void *)(param_2[1] + extraout_ECX),(void *)((int)uVar11 + param_3),uVar12);
        *(undefined1 *)param_2[2] = 0;
      }
      if (param_2 != (undefined4 *)0x0) {
        puVar5 = (uint *)param_2[4];
        sqlite3PcacheRelease(param_2);
        if (*(int *)(puVar5[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar5);
        }
      }
    }
    lVar6 = lVar6 + (int)uVar3;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3_bindValue  (confidence: high)
 * purpose: Binds value to statement param (vdbeMemSetStr 4b79e0, apply encoding); SQLite bindText impl
 * vars: param_2=index; param_1[0x11] aVar
 */
/* Global::sqlite3_bindValue @ 004709e0 */

uint __cdecl
sqlite3_bindValue(int *param_1,int param_2,void *param_3,size_t param_4,undefined *param_5,char param_6)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = vdbeUnbind(param_1,param_2);
  if (uVar1 == 0) {
    if (param_3 != (void *)0x0) {
      piVar2 = (int *)(param_1[0x11] + param_2 * 0x28 + -0x28);
      uVar1 = sqlite3VdbeMemSetStr(piVar2,param_3,param_4,param_6,param_5);
      if ((uVar1 == 0) && (param_6 != '\0')) {
        uVar1 = sqlite3VdbeChangeEncoding(piVar2,(uint)*(byte *)(*(int *)(*(int *)(*param_1 + 0x10) + 0xc) + 0x4d
                                                   ));
      }
      sqlite3ErrorWithMsg(*param_1,uVar1,(byte *)0x0);
      uVar1 = sqlite3_apiExit(*param_1,uVar1);
    }
    if (*(int *)(*param_1 + 0xc) != 0) {
      (*DAT_00582b20)(*(int *)(*param_1 + 0xc));
      return uVar1;
    }
  }
  else if ((param_5 != (undefined *)0x0) && (param_5 != (undefined *)0xffffffff)) {
    (*(code *)param_5)(param_3);
  }
  return uVar1;
}




/* [AUDIT] proposed: btree_closeCursor  (confidence: high)
 * purpose: Detaches btree cursor: frees overflow (48e9a0), unlinks from page/shared list (472880); SQLite sqlite3BtreeCloseCursor
 * vars: param_1[1]=pBt; +0x3c overflow
 */
/* Global::btree_closeCursor @ 00471200 */

void __cdecl btree_closeCursor(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  
  iVar2 = param_1[1];
  bitvec_destroy(*(int *)(iVar2 + 0x3c));
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  if ((char)param_1[2] != '\0') {
    if (1 < *(int *)(*param_1 + 0x84)) {
      iVar2 = param_1[1];
      if (*(int **)(iVar2 + 0x4c) == param_1) {
        *(ushort *)(iVar2 + 0x16) = *(ushort *)(iVar2 + 0x16) & 0xff9f;
        *(undefined4 *)(iVar2 + 0x4c) = 0;
        for (iVar2 = *(int *)(iVar2 + 0x48); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
          *(undefined1 *)(iVar2 + 8) = 1;
        }
      }
      *(undefined1 *)(param_1 + 2) = 1;
      return;
    }
    if ((char)param_1[2] != '\0') {
      btree_unlinkCursorOverflow((int)param_1);
      piVar1 = (int *)(iVar2 + 0x28);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined1 *)(iVar2 + 0x13) = 0;
      }
    }
  }
  *(undefined1 *)(param_1 + 2) = 0;
  if ((*(char *)(iVar2 + 0x13) == '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
    puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0xc) + 0x44);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = (uint *)puVar3[4];
      sqlite3PcacheRelease(puVar3);
      if (*(int *)(puVar4[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar4);
      }
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  return;
}




/* [AUDIT] proposed: btree_getAndInitPage  (confidence: high)
 * purpose: Gets page param_2 (4a14c0) and initializes MemPage fields (pgno,flags,pBt); SQLite getAndInitPage
 * vars: local_8=pDbPage; +0x38 aData
 */
/* Global::btree_getAndInitPage @ 004712c0 */

int __cdecl btree_getAndInitPage(int *param_1,uint param_2,int *param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  iVar1 = getAndInitPage(*param_1,param_2,&local_8,param_4);
  if (iVar1 == 0) {
    iVar1 = *(int *)(local_8 + 8);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(local_8 + 4);
    *(byte *)(iVar1 + 5) = (param_2 != 1) - 1U & 100;
    *(int *)(iVar1 + 0x44) = local_8;
    *(int **)(iVar1 + 0x34) = param_1;
    *(uint *)(iVar1 + 0x48) = param_2;
    *param_3 = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}




/* [AUDIT] proposed: btree_initPage  (confidence: high)
 * purpose: Parses MemPage cell pointers, computes nFree/nCell, validates; SQLite btreeInitPage; 'database corruption'
 * vars: param_1+0x10 nCell; +0xe nFree; +0x12 maskPage
 */
/* Global::btree_initPage @ 00471320 */

undefined4 __cdecl btree_initPage(char *param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  
  if (*param_1 == '\0') {
    bVar2 = param_1[5];
    iVar4 = *(int *)(param_1 + 0x38);
    iVar12 = *(int *)(param_1 + 0x34);
    pbVar11 = (byte *)((uint)bVar2 + iVar4);
    iVar6 = btree_decodeFlags((int)param_1,(uint)*pbVar11);
    if (iVar6 != 0) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      return 0xb;
    }
    *(short *)(param_1 + 0x12) = *(short *)(iVar12 + 0x20) + -1;
    uVar8 = (3 - (ushort)(byte)param_1[3]) * 4 + (ushort)bVar2;
    param_1[1] = '\0';
    iVar6 = *(int *)(iVar12 + 0x24);
    *(ushort *)(param_1 + 0xc) = uVar8;
    *(int *)(param_1 + 0x3c) = iVar6 + iVar4;
    *(uint *)(param_1 + 0x40) = (uint)uVar8 + iVar4;
    bVar2 = pbVar11[5];
    bVar3 = pbVar11[6];
    uVar9 = CONCAT11(pbVar11[3],pbVar11[4]);
    *(ushort *)(param_1 + 0x10) = uVar9;
    if ((*(int *)(iVar12 + 0x20) - 8U) / 6 < (uint)uVar9) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      return 0xb;
    }
    uVar1 = (uint)uVar8 + (uint)uVar9 * 2;
    iVar12 = (uint)pbVar11[7] + (CONCAT11(bVar2,bVar3) - 1 & 0xffff) + 1;
    uVar8 = CONCAT11(pbVar11[1],pbVar11[2]);
    uVar5 = (uint)uVar8;
    while (uVar8 != 0) {
      if ((uVar5 < uVar1) || (iVar6 + -4 < (int)uVar5)) {
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        return 0xb;
      }
      uVar8 = CONCAT11(*(undefined1 *)(uVar5 + iVar4),*(undefined1 *)(uVar5 + 1 + iVar4));
      uVar10 = (uint)CONCAT11(*(undefined1 *)(uVar5 + 2 + iVar4),*(undefined1 *)(uVar5 + 3 + iVar4))
      ;
      if (((uVar8 != 0) && ((uint)uVar8 <= uVar5 + 3 + uVar10)) || (iVar6 < (int)(uVar5 + uVar10)))
      {
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        return 0xb;
      }
      iVar12 = iVar12 + uVar10;
      uVar5 = (uint)uVar8;
    }
    if (iVar6 < iVar12) {
      uVar7 = sqlite3CorruptError();
      return uVar7;
    }
    *(short *)(param_1 + 0xe) = (short)iVar12 - (short)uVar1;
    *param_1 = '\x01';
  }
  return 0;
}




/* [AUDIT] proposed: btree_parseCellPtr  (confidence: high)
 * purpose: Parses a btree cell: decodes payload size (varint 49d440) and rowid (49d270), fills CellInfo; SQLite btreeParseCellPtr
 * vars: puVar2 CellInfo out; +0x1a nLocal
 */
/* Global::btree_parseCellPtr @ 00471710 */

void __cdecl btree_parseCellPtr(int param_1,uint param_2,uint *param_3)

{
  byte bVar1;
  uint *puVar2;
  ushort uVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  ushort uVar9;
  short sVar10;
  
  puVar2 = param_3;
  param_3[2] = param_2;
  puVar4 = (uint *)(uint)*(byte *)(param_1 + 6);
  uVar9 = (ushort)*(byte *)(param_1 + 6);
  if (*(char *)(param_1 + 2) == '\0') {
    param_3[3] = 0;
    bVar1 = *(byte *)(uVar9 + param_2);
    if (bVar1 < 0x80) {
      uVar3 = 1;
      puVar8 = (uint *)(uint)bVar1;
    }
    else {
      param_3 = puVar4;
      uVar5 = sqlite3GetVarint32((byte *)(uVar9 + param_2),(uint *)&param_3);
      uVar3 = (ushort)uVar5 & 0xff;
      puVar8 = param_3;
    }
    *puVar2 = (uint)puVar8;
    puVar2[1] = 0;
  }
  else {
    if (*(char *)(param_1 + 4) == '\0') {
      puVar8 = (uint *)0x0;
      param_3 = puVar4;
    }
    else {
      bVar1 = *(byte *)(uVar9 + param_2);
      if (bVar1 < 0x80) {
        uVar9 = uVar9 + 1;
        puVar8 = (uint *)(uint)bVar1;
        param_3 = puVar4;
      }
      else {
        param_3 = puVar4;
        uVar5 = sqlite3GetVarint32((byte *)(uVar9 + param_2),(uint *)&param_3);
        uVar9 = uVar9 + ((ushort)uVar5 & 0xff);
        puVar8 = param_3;
      }
    }
    uVar6 = sqlite3GetVarint((byte *)(uVar9 + param_2),puVar2);
    uVar3 = (ushort)uVar6;
    puVar2[3] = (uint)puVar8;
  }
  sVar10 = uVar9 + (uVar3 & 0xff);
  puVar2[4] = (uint)puVar8;
  *(short *)(puVar2 + 5) = sVar10;
  if (puVar8 <= (uint *)(uint)*(ushort *)(param_1 + 8)) {
    uVar9 = sVar10 + (short)puVar8;
    *(ushort *)((int)puVar2 + 0x1a) = uVar9;
    if (uVar9 < 4) {
      *(undefined2 *)((int)puVar2 + 0x1a) = 4;
    }
    *(short *)((int)puVar2 + 0x16) = (short)puVar8;
    *(undefined2 *)(puVar2 + 6) = 0;
    return;
  }
  uVar9 = *(ushort *)(param_1 + 10);
  iVar7 = ((int)puVar8 - (uint)uVar9) % (*(int *)(*(int *)(param_1 + 0x34) + 0x24) - 4U) +
          (uint)uVar9;
  if ((int)(uint)*(ushort *)(param_1 + 8) < iVar7) {
    *(ushort *)((int)puVar2 + 0x16) = uVar9;
  }
  else {
    *(short *)((int)puVar2 + 0x16) = (short)iVar7;
  }
  sVar10 = *(short *)((int)puVar2 + 0x16) + sVar10;
  *(short *)(puVar2 + 6) = sVar10;
  *(short *)((int)puVar2 + 0x1a) = sVar10 + 4;
  return;
}




/* [AUDIT] proposed: btree_unlinkCursorOverflow  (confidence: high)
 * purpose: Removes cursor from page overflow list, frees overflow entries, clears shared cursor flags; SQLite
 * vars: iVar1+0x48 pCursor list
 */
/* Global::btree_unlinkCursorOverflow @ 00472880 */

void __cdecl btree_unlinkCursorOverflow(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  piVar4 = (int *)(iVar1 + 0x48);
  iVar3 = *(int *)(iVar1 + 0x48);
  while (iVar3 != 0) {
    piVar2 = (int *)*piVar4;
    if (*piVar2 == param_1) {
      *piVar4 = piVar2[3];
      if (piVar2[1] != 1) {
        if (DAT_00582ac8 == 0) {
          (*DAT_00582aec)(piVar2);
        }
        else {
          if (DAT_00583f40 != 0) {
            (*DAT_00582b18)(DAT_00583f40);
          }
          iVar3 = (*DAT_00582af0._4_4_)(piVar2);
          DAT_00583e18 = DAT_00583e18 - iVar3;
          if (DAT_00583e40 < DAT_00583e18) {
            DAT_00583e40 = DAT_00583e18;
          }
          DAT_00583e3c = DAT_00583e3c + -1;
          if (DAT_00583e64 < DAT_00583e3c) {
            DAT_00583e64 = DAT_00583e3c;
          }
          (*DAT_00582aec)(piVar2);
          if (DAT_00583f40 != 0) {
            (*DAT_00582b20)(DAT_00583f40);
          }
        }
      }
    }
    else {
      piVar4 = piVar2 + 3;
    }
    iVar3 = *piVar4;
  }
  if (*(int *)(iVar1 + 0x4c) == param_1) {
    *(ushort *)(iVar1 + 0x16) = *(ushort *)(iVar1 + 0x16) & 0xff9f;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    return;
  }
  if (*(int *)(iVar1 + 0x28) == 2) {
    *(ushort *)(iVar1 + 0x16) = *(ushort *)(iVar1 + 0x16) & 0xffbf;
  }
  return;
}




/* [AUDIT] proposed: sqlite3_exprDelete  (confidence: high)
 * purpose: Recursively frees an Expr tree and its sub-lists/tokens (Expr fields at 0xa..0x13); SQLite sqlite3ExprDelete
 * vars: param_2[0xf] right recurse
 */
/* Global::sqlite3_exprDelete @ 00472d10 */

void __cdecl sqlite3_exprDelete(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  sqlite3ExprListDelete(param_1,(int *)*param_2);
  sqlite3SrcListDelete(param_1,(short *)param_2[10]);
  sqlite3ExprDelete(param_1,(undefined4 *)param_2[0xb]);
  sqlite3ExprListDelete(param_1,(int *)param_2[0xc]);
  sqlite3ExprDelete(param_1,(undefined4 *)param_2[0xd]);
  sqlite3ExprListDelete(param_1,(int *)param_2[0xe]);
  puVar1 = (undefined4 *)param_2[0xf];
  if (puVar1 != (undefined4 *)0x0) {
    sqlite3_exprDelete(param_1,puVar1);
    sqlite3PageFree(param_1,puVar1);
  }
  sqlite3ExprDelete(param_1,(undefined4 *)param_2[0x12]);
  sqlite3ExprDelete(param_1,(undefined4 *)param_2[0x13]);
  return;
}




/* [AUDIT] proposed: sqlite3_column_apiExit  (confidence: high)
 * purpose: Sets stmt rc from db errCode after column access, leaves mutex; SQLite columnMallocFailure/apiExit
 * vars: param_1[0x16] rc
 */
/* Global::sqlite3_column_apiExit @ 00474fe0 */

void __cdecl sqlite3_column_apiExit(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 != (int *)0x0) {
    uVar3 = param_1[0x16];
    iVar1 = *param_1;
    if (iVar1 == 0) {
      uVar2 = 0xff;
    }
    else {
      if ((*(char *)(iVar1 + 0x38) != '\0') || (uVar3 == 0xc0a)) {
        sqlite3ErrorWithMsg(iVar1,7,(byte *)0x0);
        *(undefined1 *)(iVar1 + 0x38) = 0;
        uVar3 = 7;
      }
      uVar2 = *(uint *)(iVar1 + 0x30);
    }
    param_1[0x16] = uVar2 & uVar3;
    if (*(int *)(*param_1 + 0xc) != 0) {
      (*DAT_00582b20)();
      return;
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3_columnMem  (confidence: high)
 * purpose: Returns Mem pointer for column param_2 (bounds-check) or dummy error Mem; SQLite columnMem
 * vars: param_1[5]=pResultSet; [0xb] nCol; DAT_00569b70 dummy
 */
/* Global::sqlite3_columnMem @ 00475040 */

undefined * __cdecl sqlite3_columnMem(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    if (((param_1[5] != 0) && (param_2 < (int)(uint)*(ushort *)(param_1 + 0xb))) && (-1 < param_2))
    {
      if (*(int *)(*param_1 + 0xc) != 0) {
        (*DAT_00582b18)(*(int *)(*param_1 + 0xc));
      }
      return (undefined *)(param_1[5] + param_2 * 0x28);
    }
    if (*param_1 != 0) {
      iVar1 = *(int *)(*param_1 + 0xc);
      if (iVar1 != 0) {
        (*DAT_00582b18)(iVar1);
      }
      sqlite3ErrorWithMsg(*param_1,0x19,(byte *)0x0);
    }
  }
  return &DAT_00569b70;
}




/* [AUDIT] proposed: sqlite3_txnActive  (confidence: med)
 * purpose: Returns 1 if db has active write txn or any btree in-trans backend; SQLite connection-busy check
 * vars: +4 flag; +0x14 nDb; +0x10 aDb
 */
/* Global::sqlite3_txnActive @ 004757a0 */

undefined4 __cdecl sqlite3_txnActive(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    return 1;
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    piVar1 = (int *)(*(int *)(param_1 + 0x10) + 4);
    do {
      if ((*piVar1 != 0) && (*(int *)(*piVar1 + 0x10) != 0)) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x14));
  }
  return 0;
}




/* [AUDIT] proposed: btree_copyPayload  (confidence: high)
 * purpose: memcpy payload in given direction, with mutex/error check when writing (4a2c80); SQLite copyPayload
 * vars: param_4=eOp direction
 */
/* Global::btree_copyPayload @ 004761f0 */

uint __cdecl
btree_copyPayload(void *param_1,void *param_2,size_t param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  
  if (param_4 == 0) {
    memcpy(param_2,param_1,param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = pagerPlaybackSavepoint(param_5);
    if (uVar1 == 0) {
      memcpy(param_1,param_2,param_3);
      return 0;
    }
  }
  return uVar1;
}




/* [AUDIT] proposed: sqlite3_createCollation  (confidence: high)
 * purpose: Registers/removes a collation seq; refuses modify with active statements; SQLite; 'unable to delete/modify collation sequence...'
 * vars: param_3=enc; piVar3 CollSeq slot
 */
/* Global::sqlite3_createCollation @ 004762d0 */

undefined4 __cdecl
sqlite3_createCollation(int param_1,byte *param_2,byte param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  byte *pbVar2;
  int *piVar3;
  int iVar4;
  uint extraout_ECX;
  int extraout_EDX;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_c;
  
  pbVar2 = param_2;
  uVar6 = 0;
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_2;
    pbVar5 = param_2;
    while (bVar1 != 0) {
      pbVar5 = pbVar5 + 1;
      bVar1 = *pbVar5;
    }
    uVar6 = (int)pbVar5 - (int)param_2 & 0x3fffffff;
  }
  param_2 = (byte *)(uint)param_3;
  if ((param_2 == (byte *)0x4) || (param_2 == (byte *)0x8)) {
    param_2 = (byte *)0x2;
  }
  else if ((param_2 == (byte *)0x0) || ((byte *)0x3 < param_2)) {
    sqlite3_log(0x15,"misuse at line %d of [%.10s]");
    return 0x15;
  }
  if (pbVar2 == (byte *)0x0) {
    piVar3 = *(int **)(param_1 + 8);
  }
  else {
    piVar3 = sqlite3_findCollSeq(param_1,pbVar2,0);
  }
  if (((piVar3 != (int *)0x0) && (piVar3 = piVar3 + (int)param_2 * 5, piVar3 != (int *)0x14)) &&
     (piVar3[-2] != 0)) {
    if (*(int *)(param_1 + 0x84) != 0) {
      sqlite3ErrorWithMsg(param_1,5,
                   (byte *)"unable to delete/modify collation sequence due to active statements");
      return 5;
    }
    sqlite3ExpirePreparedStatements(param_1);
    if ((*(byte *)(extraout_EDX + 4) & 0xfffffff7) == extraout_ECX) {
      iVar4 = sqlite3HashFind((uint *)(param_1 + 0x19c),pbVar2,uVar6);
      puVar7 = (undefined4 *)(iVar4 + 0x10);
      local_c = 3;
      do {
        if (*(char *)(puVar7 + -3) == (char)piVar3[-4]) {
          if ((code *)*puVar7 != (code *)0x0) {
            (*(code *)*puVar7)(puVar7[-2]);
          }
          puVar7[-1] = 0;
        }
        puVar7 = puVar7 + 5;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  if (pbVar2 == (byte *)0x0) {
    piVar3 = *(int **)(param_1 + 8);
  }
  else {
    piVar3 = sqlite3_findCollSeq(param_1,pbVar2,1);
  }
  if ((piVar3 != (int *)0x0) && (piVar3 = piVar3 + (int)param_2 * 5, piVar3 != (int *)0x14)) {
    piVar3[-2] = param_5;
    piVar3[-3] = param_4;
    piVar3[-1] = param_6;
    *(byte *)(piVar3 + -4) = param_3 & 8 | (byte)param_2;
    sqlite3ErrorWithMsg(param_1,0,(byte *)0x0);
    return 0;
  }
  return 7;
}




/* [AUDIT] proposed: btree_decodeFlags  (confidence: high)
 * purpose: Decodes MemPage flags into leaf/intkey/cell offsets from page header; SQLite decodeFlags; 'database corruption'
 * vars: param_1+3 leaf; +6 childPtrSize
 */
/* Global::btree_decodeFlags @ 00476810 */

undefined4 __cdecl btree_decodeFlags(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x34);
  cVar2 = (char)((int)param_2 >> 3);
  *(char *)(param_1 + 3) = cVar2;
  *(char *)(param_1 + 6) = ('\x01' - cVar2) * '\x04';
  if ((param_2 & 0xfffffff7) == 5) {
    *(char *)(param_1 + 4) = cVar2;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(iVar1 + 0x1c);
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(iVar1 + 0x1e);
    *(undefined1 *)(param_1 + 7) = *(undefined1 *)(iVar1 + 0x14);
    return 0;
  }
  if ((param_2 & 0xfffffff7) == 2) {
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(iVar1 + 0x18);
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(iVar1 + 0x1a);
    *(undefined1 *)(param_1 + 7) = *(undefined1 *)(iVar1 + 0x14);
    return 0;
  }
  sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
  return 0xb;
}




/* [AUDIT] proposed: sqlite3_step  (confidence: high)
 * purpose: SQLite 3.7.15.2 sqlite3_step: identified by compiler-independent string-anchor match (7 unique-owner string anchors, score 37.0). Anchors: %.16g|%s(%d)|(blob)|collseq(%.20s)
 * vars: -
 */
/* Global::sqlite3_step_476d20 @ 00476d20 */

char * __cdecl sqlite3_step_476d20(int param_1,char *param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0xed:
    *param_2 = '\0';
    return param_2;
  case 0xee:
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"program");
    return param_2;
  case 0xef:
  case 0xfa:
    iVar3 = *(int *)(param_1 + 0x10);
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"keyinfo(%d");
    uVar4 = sqlite3Strlen30(param_2);
    param_1 = 0;
    if (*(short *)(iVar3 + 6) != 0) {
      puVar5 = (undefined4 *)(iVar3 + 0xc);
      while( true ) {
        if ((undefined4 *)*puVar5 == (undefined4 *)0x0) {
          pcVar6 = "nil";
        }
        else {
          pcVar6 = *(char **)*puVar5;
        }
        uVar9 = 0;
        if (pcVar6 != (char *)0x0) {
          cVar1 = *pcVar6;
          pcVar8 = pcVar6;
          while (cVar1 != '\0') {
            pcVar8 = pcVar8 + 1;
            cVar1 = *pcVar8;
          }
          uVar9 = (int)pcVar8 - (int)pcVar6 & 0x3fffffff;
        }
        if (param_3 + -6 < (int)(uVar9 + uVar4)) break;
        param_2[uVar4] = ',';
        iVar7 = uVar4 + 1;
        if (*(char *)(param_1 + *(int *)(iVar3 + 8)) != '\0') {
          param_2[iVar7] = '-';
          iVar7 = uVar4 + 2;
        }
        memcpy(param_2 + iVar7,pcVar6,uVar9 + 1);
        param_1 = param_1 + 1;
        puVar5 = puVar5 + 1;
        uVar4 = iVar7 + uVar9;
        if ((int)(uint)*(ushort *)(iVar3 + 6) <= param_1) {
          (param_2 + uVar4)[0] = ')';
          (param_2 + uVar4)[1] = '\0';
          return param_2;
        }
      }
      builtin_strncpy(param_2 + uVar4,",...",4);
    }
    (param_2 + uVar4)[0] = ')';
    (param_2 + uVar4)[1] = '\0';
    return param_2;
  default:
    pcVar6 = *(char **)(param_1 + 0x10);
    if (*(char **)(param_1 + 0x10) == (char *)0x0) {
      *param_2 = '\0';
      pcVar6 = param_2;
    }
    return pcVar6;
  case 0xf1:
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"intarray");
    return param_2;
  case 0xf2:
    sqlite3_snprintf_impl(param_3,param_2,&DAT_0055ae88);
    return param_2;
  case 0xf3:
    break;
  case 0xf4:
LAB_00476eb8:
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"%.16g");
    return param_2;
  case 0xf6:
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"vtab:%p:%p");
    return param_2;
  case 0xf8:
    uVar2 = *(ushort *)(*(int *)(param_1 + 0x10) + 0x1c);
    if ((uVar2 & 2) != 0) {
      return *(char **)(*(int *)(param_1 + 0x10) + 4);
    }
    if ((uVar2 & 4) == 0) {
      if ((uVar2 & 8) == 0) {
        if ((uVar2 & 1) != 0) {
          sqlite3_snprintf_impl(param_3,param_2,&DAT_0056ddd0);
          return param_2;
        }
        return "(blob)";
      }
      goto LAB_00476eb8;
    }
    break;
  case 0xfb:
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"%s(%d)");
    return param_2;
  case 0xfc:
    sqlite3_snprintf_impl(param_3,param_2,(byte *)"collseq(%.20s)");
    return param_2;
  }
  sqlite3_snprintf_impl(param_3,param_2,&DAT_0056dd58);
  return param_2;
}




/* [AUDIT] proposed: vdbe_runVtabCommit  (confidence: low)
 * purpose: Iterates db backends invoking a per-backend commit/virtual-table callback (+0xc0); SQLite commit phase
 * vars: param_1+0x14 nDb; +0xc0 xCallback
 */
/* Global::vdbe_runVtabCommit @ 00476ff0 */

int __cdecl vdbe_runVtabCommit(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar2 = 0;
  iVar4 = 0;
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    iVar5 = 0;
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar5);
      if (iVar1 != 0) {
        iVar3 = 0;
        iVar2 = *(int *)(**(int **)(iVar1 + 4) + 0xb8);
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + 0xc);
          *(undefined4 *)(iVar2 + 0xc) = 0;
        }
        iVar2 = local_8;
        if (((*(code **)(param_1 + 0xc0) != (code *)0x0) && (0 < iVar3)) && (local_8 == 0)) {
          local_8 = (**(code **)(param_1 + 0xc0))
                              (*(undefined4 *)(param_1 + 0xc4),param_1,
                               *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar5),iVar3);
          iVar2 = local_8;
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar4 < *(int *)(param_1 + 0x14));
  }
  return iVar2;
}




/* [AUDIT] proposed: sqlite3_findCollSeq  (confidence: high)
 * purpose: Hash-lookup collation seq by name; creates+inserts entry if param_3 set; SQLite sqlite3FindCollSeq
 * vars: param_1+0x19c collHash; entry 0x3d hdr
 */
/* Global::sqlite3_findCollSeq @ 004799f0 */

int * __cdecl sqlite3_findCollSeq(int param_1,byte *param_2,int param_3)

{
  int *_Dst;
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *_Dst_00;
  byte *pbVar4;
  size_t _Size;
  
  _Size = 0;
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_2;
    pbVar4 = param_2;
    while (bVar1 != 0) {
      pbVar4 = pbVar4 + 1;
      bVar1 = *pbVar4;
    }
    _Size = (int)pbVar4 - (int)param_2 & 0x3fffffff;
  }
  if (*(int *)(param_1 + 0x1a8) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sqlite3StrHash_wal(param_2,_Size);
    uVar2 = uVar2 % *(uint *)(param_1 + 0x19c);
  }
  puVar3 = hash_find(param_1 + 0x19c,param_2,_Size,uVar2);
  if ((puVar3 != (undefined4 *)0x0) && ((int *)puVar3[2] != (int *)0x0)) {
    return (int *)puVar3[2];
  }
  _Dst_00 = (int *)0x0;
  if (((param_3 != 0) && (_Dst_00 = sqlite3PageMalloc(param_1,_Size + 0x3d), _Dst_00 != (int *)0x0)) &&
     (memset(_Dst_00,0,_Size + 0x3d), _Dst_00 != (int *)0x0)) {
    _Dst = _Dst_00 + 0xf;
    *_Dst_00 = (int)_Dst;
    *(undefined1 *)(_Dst_00 + 1) = 1;
    _Dst_00[5] = (int)_Dst;
    *(undefined1 *)(_Dst_00 + 6) = 2;
    _Dst_00[10] = (int)_Dst;
    *(undefined1 *)(_Dst_00 + 0xb) = 3;
    memcpy(_Dst,param_2,_Size);
    *(undefined1 *)(_Size + *_Dst_00) = 0;
    puVar3 = (undefined4 *)
             sqlite3HashInsert((uint *)(param_1 + 0x19c),(byte *)*_Dst_00,_Size,(uint)_Dst_00);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined1 *)(param_1 + 0x38) = 1;
      sqlite3PageFree(param_1,puVar3);
      return (int *)0x0;
    }
  }
  return _Dst_00;
}




/* [AUDIT] proposed: vdbe_freeP4  (confidence: high)
 * purpose: Frees a VDBE P4 operand by type (funcdef, mem, vtab, collseq, keyinfo...) via switch; SQLite freeP4
 * vars: param_2=P4 type; param_3=P4 ptr
 */
/* Global::vdbe_freeP4 @ 0047bc80 */

void __cdecl vdbe_freeP4(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  
  if (param_3 != (int *)0x0) {
    switch(param_2) {
    case 0xfffffff0:
    case 0xfffffff1:
    case 0xfffffff3:
    case 0xfffffff4:
    case 0xfffffffa:
    case 0xffffffff:
switchD_0047bca6_caseD_fffffff0:
      sqlite3PageFree(param_1,param_3);
      return;
    case 0xfffffff2:
    case 0xfffffff7:
    case 0xfffffffc:
    case 0xfffffffd:
    case 0xfffffffe:
      break;
    case 0xfffffff5:
      if (*(int *)(param_1 + 0x1f0) == 0) {
        sqlite3_free((int)param_3);
        return;
      }
      break;
    case 0xfffffff6:
      if (*(int *)(param_1 + 0x1f0) == 0) {
        sqlite3KeyInfoUnref(param_3);
      }
      break;
    case 0xfffffff8:
      if (*(int *)(param_1 + 0x1f0) != 0) {
        sqlite3PageFree(param_1,(undefined4 *)param_3[9]);
        sqlite3PageFree(param_1,param_3);
        return;
      }
      sqlite3VdbeMemRelease_free(param_3);
      return;
    case 0xfffffff9:
      puVar1 = (undefined4 *)*param_3;
      if ((puVar1 != (undefined4 *)0x0) && ((*(byte *)((int)puVar1 + 3) & 4) != 0)) {
        sqlite3PageFree(param_1,puVar1);
      }
      if (*(int *)(param_1 + 0x1f0) == 0) {
        sqlite3VdbeDeleteAuxData(param_3,0);
      }
      sqlite3PageFree(param_1,param_3);
      return;
    case 0xfffffffb:
      if ((*param_3 & 0x4000000) != 0) goto switchD_0047bca6_caseD_fffffff0;
      break;
    default:
      goto switchD_0047bca6_default;
    }
  }
switchD_0047bca6_default:
  return;
}




/* [AUDIT] proposed: pager_freeSavepointBitvec  (confidence: high)
 * purpose: Frees a bitvec (486af0) at pager+0x50 and nulls it; SQLite
 * vars: param_1+0x50 bitvec
 */
/* Global::pager_freeSavepointBitvec @ 0047c340 */

void __cdecl pager_freeSavepointBitvec(int param_1)

{
  pcache_freePageMem(*(undefined4 **)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = 0;
  return;
}




/* [AUDIT] proposed: vdbe_freeAuxRef  (confidence: high)
 * purpose: Decrements auxdata/funcarg refcount at +0x20 and frees when zero (494b00); SQLite
 * vars: piVar1[0] refcount
 */
/* Global::vdbe_freeAuxRef @ 0047c360 */

void __cdecl vdbe_freeAuxRef(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_2 + 0x20);
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    (*(code *)piVar1[1])(piVar1[2]);
    sqlite3PageFree(param_1,piVar1);
  }
  return;
}




/* [AUDIT] proposed: btree_cacheCellSize  (confidence: high)
 * purpose: Parses/caches current cell info for cursor when not yet cached (471710); SQLite getCellInfo
 * vars: param_1+0x42 cellValid; +0x5e iPage
 */
/* Global::btree_cacheCellSize @ 0047d150 */

void __cdecl btree_cacheCellSize(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x42) == 0) {
    iVar1 = *(int *)(param_1 + 0x88 + *(short *)(param_1 + 0x5e) * 4);
    uVar2 = (uint)*(ushort *)(param_1 + 0x60 + *(short *)(param_1 + 0x5e) * 2);
    btree_parseCellPtr(iVar1,(uint)(CONCAT11(*(undefined1 *)(*(int *)(iVar1 + 0x40) + uVar2 * 2),
                                       *(undefined1 *)(*(int *)(iVar1 + 0x40) + 1 + uVar2 * 2)) &
                             *(ushort *)(iVar1 + 0x12)) + *(int *)(iVar1 + 0x38),
                 (uint *)(param_1 + 0x28));
    *(undefined1 *)(param_1 + 0x5a) = 1;
  }
  return;
}




/* [AUDIT] proposed: btree_getOverflowPage  (confidence: high)
 * purpose: Fetches next overflow page (via ptrmap or scan), returns page & next pgno; SQLite btree overflow walk
 * vars: param_1[9] usableSize; local_8=pPage
 */
/* Global::btree_getOverflowPage @ 0047d460 */

int __cdecl btree_getOverflowPage(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 *local_8;
  
  piVar3 = param_1;
  if (*(char *)((int)param_1 + 0x11) == '\0') {
LAB_0047d505:
    iVar4 = getAndInitPage(*piVar3,(uint)param_2,(int *)&param_1,0);
    if (iVar4 == 0) {
      iVar8 = param_1[2];
      *(int *)(iVar8 + 0x38) = param_1[1];
      *(undefined4 **)(iVar8 + 0x48) = param_2;
      *(int **)(iVar8 + 0x44) = param_1;
      puVar1 = *(undefined1 **)(iVar8 + 0x38);
      *(byte *)(iVar8 + 5) = (param_2 != (undefined4 *)0x1) - 1U & 100;
      *(int **)(iVar8 + 0x34) = piVar3;
      puVar7 = (undefined4 *)CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]);
      goto LAB_0047d568;
    }
LAB_0047d564:
    puVar7 = (undefined4 *)0x0;
  }
  else {
    piVar6 = (int *)((int)param_2 - 1);
    puVar7 = param_2;
    while( true ) {
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      if (puVar7 < (undefined4 *)0x2) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        uVar5 = (uint)param_1[9] / 5 + 1;
        iVar4 = ((uint)piVar6 / uVar5) * uVar5;
        puVar9 = (undefined4 *)(iVar4 + 2);
        if (puVar9 == (undefined4 *)(DAT_00582bb8 / (uint)param_1[8] + 1)) {
          puVar9 = (undefined4 *)(iVar4 + 3);
        }
      }
      if ((puVar9 != puVar7) && (puVar7 != (undefined4 *)(DAT_00582bb8 / (uint)param_1[8] + 1)))
      break;
      piVar6 = (int *)((int)piVar6 + 1);
    }
    puVar2 = (uint *)(param_1 + 0xb);
    param_1 = piVar6;
    if ((undefined4 *)*puVar2 < puVar7) goto LAB_0047d505;
    iVar4 = btree_readCellPtrByte(piVar3,puVar7,(byte *)((int)&param_1 + 3),&local_8);
    if (iVar4 != 0) goto LAB_0047d564;
    bVar10 = param_1._3_1_ != '\x04';
    if ((bVar10) || (local_8 != param_2)) goto LAB_0047d505;
    iVar4 = 0x65;
  }
  iVar8 = 0;
LAB_0047d568:
  *param_4 = puVar7;
  if (param_3 == (int *)0x0) {
    if ((iVar8 != 0) && (puVar7 = *(undefined4 **)(iVar8 + 0x44), puVar7 != (undefined4 *)0x0)) {
      puVar2 = (uint *)puVar7[4];
      sqlite3PcacheRelease(puVar7);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
    }
    if (iVar4 == 0x65) {
      iVar4 = 0;
    }
    return iVar4;
  }
  *param_3 = iVar8;
  if (iVar4 == 0x65) {
    iVar4 = 0;
  }
  return iVar4;
}




/* [AUDIT] proposed: pager_hasHotJournal  (confidence: low)
 * purpose: Queries file existence/size via VFS xAccess/xLock/xShmLock to detect a hot journal; SQLite hasHotJournal
 * vars: iVar4=pVfs; piVar1[0x10] journal file
 */
/* Global::pager_hasHotJournal @ 0047df00 */

int __cdecl pager_hasHotJournal(int *param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int local_c;
  int local_8;
  
  piVar1 = param_1;
  iVar4 = *param_1;
  local_8 = 1;
  bVar5 = *(int *)param_1[0x10] == 0;
  *param_2 = 0;
  if (bVar5) {
    iVar2 = (**(code **)(iVar4 + 0x20))(iVar4,param_1[0x25],0,&local_8);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_8 == 0) {
      return 0;
    }
  }
  local_c = 0;
  iVar2 = (**(code **)(*(int *)piVar1[0xf] + 0x24))((int *)piVar1[0xf],&local_c);
  if (((iVar2 == 0) && (local_c == 0)) &&
     (iVar2 = pager_pageCount((int)piVar1,(uint *)&param_1), iVar2 == 0)) {
    if (param_1 == (int *)0x0) {
      if (DAT_00583e74 != (code *)0x0) {
        (*DAT_00583e74)();
      }
      iVar3 = pager_lockDb((int)piVar1,2);
      if ((iVar3 == 0) &&
         ((**(code **)(iVar4 + 0x1c))(iVar4,piVar1[0x25],0), (char)piVar1[1] == '\0')) {
        pager_unlockDb((int)piVar1,1);
      }
      if (DAT_00583e78 != (code *)0x0) {
        (*DAT_00583e78)();
        return 0;
      }
    }
    else {
      if (bVar5) {
        param_1 = (int *)0x801;
        iVar4 = (**(code **)(iVar4 + 0x18))(iVar4,piVar1[0x25],piVar1[0x10],0x801,&param_1);
        if (iVar4 != 0) {
          if (iVar4 != 0xe) {
            return iVar4;
          }
          *param_2 = 1;
          return 0;
        }
      }
      param_1 = (int *)((uint)param_1 & 0xffffff);
      iVar2 = (**(code **)(*(int *)piVar1[0x10] + 8))((int *)piVar1[0x10],(int)&param_1 + 3,1,0,0);
      if (iVar2 == 0x20a) {
        iVar2 = 0;
      }
      if (bVar5) {
        sqlite3OsClose((int *)piVar1[0x10]);
      }
      *param_2 = (uint)(param_1._3_1_ != '\0');
    }
  }
  return iVar2;
}




/* [AUDIT] proposed: btree_clearDbPage  (confidence: low)
 * purpose: Recursively clears/frees a btree page and its child cells (46bae0 walk, 480840 update); SQLite clearDatabasePage; 'database corruption'
 * vars: param_1[3] pMemPage; pcVar6 pgno
 */
/* Global::btree_clearDbPage @ 0047e2e0 */

uint __cdecl btree_clearDbPage(int *param_1,undefined4 *param_2,char *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  uint local_18;
  uint local_14;
  char *local_10;
  undefined4 *local_c;
  char *local_8;
  
  pcVar6 = param_3;
  if (param_3 < (char *)0x2) {
    pcVar4 = (char *)0x0;
  }
  else {
    uVar2 = (uint)param_1[9] / 5 + 1;
    iVar3 = ((uint)(param_3 + -2) / uVar2) * uVar2;
    pcVar4 = (char *)(iVar3 + 2);
    if (pcVar4 == (char *)(DAT_00582bb8 / (uint)param_1[8] + 1)) {
      pcVar4 = (char *)(iVar3 + 3);
    }
  }
  if ((pcVar4 != param_3) && (param_3 != (char *)(DAT_00582bb8 / (uint)param_1[8] + 1))) {
    iVar3 = *(int *)(param_1[3] + 0x38);
    if (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x24),*(undefined1 *)(iVar3 + 0x25)),
                          *(undefined1 *)(iVar3 + 0x26)),*(undefined1 *)(iVar3 + 0x27)) == 0) {
      return 0x65;
    }
    uVar2 = btree_readCellPtrByte(param_1,(undefined4 *)param_3,(byte *)&local_8,&local_14);
    if (uVar2 != 0) {
      return uVar2;
    }
    if ((char)local_8 == '\x01') {
      uVar2 = sqlite3CorruptError();
      return uVar2;
    }
    if ((char)local_8 == '\x02') {
      if (param_2 != (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = btree_moveToNext(param_1,(int *)&param_3,&local_18,(undefined4 *)pcVar6,'\x01');
      if (uVar2 != 0) {
        return uVar2;
      }
      btree_releasePage((int)param_3);
      goto LAB_0047e485;
    }
    uVar2 = btree_getAndInitPage(param_1,(uint)pcVar6,(int *)&param_3,0);
    if (uVar2 != 0) {
      return uVar2;
    }
    do {
      local_18 = btree_moveToNext(param_1,(int *)&local_10,(uint *)&local_c,(undefined4 *)0x0,'\0');
      if (local_18 != 0) {
        btree_releasePage((int)param_3);
        return local_18;
      }
      btree_releasePage((int)local_10);
    } while ((param_2 != (undefined4 *)0x0) && (param_2 < local_c));
    local_10 = (char *)pagerPlaybackSavepoint(*(undefined4 **)(param_3 + 0x44));
    if (local_10 == (char *)0x0) {
      local_10 = (char *)btree_updateOverflowCell(param_1,param_3,local_8,local_14,(uint)local_c,
                                      (uint)(param_2 != (undefined4 *)0x0));
    }
    btree_releasePage((int)param_3);
    if (local_10 != (char *)0x0) {
      return (uint)local_10;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    return 0;
  }
LAB_0047e485:
  local_8 = pcVar6 + -3;
  do {
    pcVar6 = pcVar6 + -1;
    param_3 = (char *)(DAT_00582bb8 / (uint)param_1[8] + 1);
    if (pcVar6 != param_3) {
      if (pcVar6 < (char *)0x2) {
        pcVar4 = (char *)0x0;
      }
      else {
        uVar2 = (uint)param_1[9] / 5 + 1;
        iVar3 = ((uint)local_8 / uVar2) * uVar2;
        pcVar4 = (char *)(iVar3 + 2);
        if (pcVar4 == param_3) {
          pcVar4 = (char *)(iVar3 + 3);
        }
      }
      if (pcVar4 != pcVar6) {
        *(char **)(*param_1 + 0x18) = pcVar6;
        param_1[0xb] = (int)pcVar6;
        return 0;
      }
    }
    if (pcVar6 < (char *)0x2) {
      pcVar4 = (char *)0x0;
    }
    else {
      uVar2 = (uint)param_1[9] / 5 + 1;
      iVar3 = ((uint)local_8 / uVar2) * uVar2;
      pcVar4 = (char *)(iVar3 + 2);
      if (pcVar4 == param_3) {
        pcVar4 = (char *)(iVar3 + 3);
      }
    }
    if (pcVar4 == pcVar6) {
      puVar1 = (uint *)*param_1;
      if (pcVar6 == (char *)0x0) {
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        return 0xb;
      }
      param_3 = (char *)puVar1[10];
      if ((param_3 == (char *)0x0) &&
         (param_3 = (char *)sqlite3PcacheFetch((int *)puVar1[0x2d],(int)pcVar6,1,&local_c),
         puVar5 = local_c, param_3 == (char *)0x0)) {
        if (local_c[4] != 0) {
          puVar1[0x28] = puVar1[0x28] + 1;
          goto LAB_0047e647;
        }
        local_c[4] = puVar1;
        if (((char *)0x7fffffff < pcVar6) ||
           (pcVar6 == (char *)((int)DAT_00582bb8 / (int)puVar1[0x20] + 1U))) {
          sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
          param_3 = (char *)0xb;
LAB_0047e5f4:
          if ((*(byte *)(puVar5 + 6) & 2) != 0) {
            pcache_removeFromDirty((int)puVar5);
          }
          iVar3 = puVar5[7];
          *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + -1;
          if (puVar5[5] == 1) {
            *(undefined4 *)(iVar3 + 0x2c) = 0;
          }
          (*DAT_00582b4c)(*(undefined4 *)(iVar3 + 0x28),*puVar5,1);
          goto LAB_0047e626;
        }
        if (((*(char *)((int)puVar1 + 0xe) == '\0') && (pcVar6 <= (char *)puVar1[6])) &&
           (*(int *)puVar1[0xf] != 0)) {
          puVar1[0x29] = puVar1[0x29] + 1;
          param_3 = (char *)pager_readDbPage((int)local_c);
          if (param_3 != (char *)0x0) goto LAB_0047e5f4;
        }
        else {
          if ((char *)puVar1[0x21] < pcVar6) {
            param_3 = (char *)0xd;
            goto LAB_0047e5f4;
          }
          memset((void *)local_c[1],0,puVar1[0x20]);
        }
      }
      else {
LAB_0047e626:
        if (*(int *)(puVar1[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar1);
        }
        puVar5 = (undefined4 *)0x0;
        local_c = (undefined4 *)0x0;
        if (param_3 != (char *)0x0) {
          return (uint)param_3;
        }
      }
LAB_0047e647:
      iVar3 = puVar5[2];
      *(undefined4 *)(iVar3 + 0x38) = puVar5[1];
      *(int **)(iVar3 + 0x34) = param_1;
      *(undefined4 **)(iVar3 + 0x44) = puVar5;
      *(char **)(iVar3 + 0x48) = pcVar6;
      *(byte *)(iVar3 + 5) = (pcVar6 != (char *)0x1) - 1U & 100;
      param_3 = (char *)pagerPlaybackSavepoint(puVar5);
      puVar5 = *(undefined4 **)(iVar3 + 0x44);
      if (puVar5 != (undefined4 *)0x0) {
        puVar1 = (uint *)puVar5[4];
        sqlite3PcacheRelease(puVar5);
        if (*(int *)(puVar1[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar1);
        }
      }
      if (param_3 != (char *)0x0) {
        return (uint)param_3;
      }
    }
    local_8 = local_8 + -1;
  } while( true );
}




/* [AUDIT] proposed: pcache_pageInsert  (confidence: high)
 * purpose: Inserts a PgHdr into a hash bucket / LRU list; SQLite pcache add-to-list
 * vars: param_1+8 tail; param_3=new PgHdr
 */
/* Global::pcache_pageInsert @ 0047e8a0 */

void __cdecl pcache_pageInsert(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    if (*param_2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = param_2[1];
    }
    *param_2 = *param_2 + 1;
    param_2[1] = (int)param_3;
    if (iVar1 != 0) {
      *param_3 = iVar1;
      param_3[1] = *(int *)(iVar1 + 4);
      if (*(undefined4 **)(iVar1 + 4) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar1 + 4) = param_3;
        *(int **)(iVar1 + 4) = param_3;
        return;
      }
      *(int **)(param_1 + 8) = param_3;
      *(int **)(iVar1 + 4) = param_3;
      return;
    }
  }
  *param_3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) != 0) {
    *(int **)(*(int *)(param_1 + 8) + 4) = param_3;
  }
  param_3[1] = 0;
  *(int **)(param_1 + 8) = param_3;
  return;
}




/* [AUDIT] proposed: pager_journalHdrOffset  (confidence: high)
 * purpose: Rounds journal offset up to next sector boundary (alldiv/allmul by sector size); SQLite journalHdrOffset
 * vars: +0x48/4c offset; +0x7c sectorSize
 */
/* Global::pager_journalHdrOffset @ 0047f590 */

longlong __cdecl pager_journalHdrOffset(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(param_1 + 0x48);
  if (iVar1 != 0 || *(int *)(param_1 + 0x4c) != 0) {
    uVar2 = *(uint *)(param_1 + 0x7c);
    lVar3 = __alldiv(iVar1 - 1,*(int *)(param_1 + 0x4c) - (uint)(iVar1 == 0),uVar2,0);
    lVar3 = __allmul((uint)(lVar3 + 1),(int)((ulonglong)(lVar3 + 1) >> 0x20),uVar2,0);
    return lVar3;
  }
  return 0;
}




/* [AUDIT] proposed: btree_readPage1  (confidence: med)
 * purpose: Locks and reads database page 1 header, validates 'SQLite format 3' magic, sets page/reserve sizes; SQLite lockBtree
 * vars: piVar2=page1 aData; +8 pageSize
 */
/* Global::btree_readPage1 @ 0047fc00 */

uint __cdecl btree_readPage1(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  int *piVar7;
  short sVar8;
  char *pcVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  piVar3 = param_1;
  uVar4 = pager_playback_4a2980((uint *)*param_1);
  if (uVar4 != 0) {
    return uVar4;
  }
  puVar1 = (uint *)*param_1;
  param_1 = (int *)puVar1[10];
  if (param_1 == (int *)0x0) {
    param_1 = (int *)sqlite3PcacheFetch((int *)puVar1[0x2d],1,1,&local_10);
  }
  puVar10 = local_10;
  iVar5 = DAT_00582bb8;
  if (param_1 == (int *)0x0) {
    if (local_10[4] != 0) {
      puVar1[0x28] = puVar1[0x28] + 1;
      goto LAB_0047fd2b;
    }
    local_10[4] = puVar1;
    if (iVar5 / (int)puVar1[0x20] == 0) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      param_1 = (int *)0xb;
LAB_0047fcd7:
      if ((*(byte *)(puVar10 + 6) & 2) != 0) {
        pcache_removeFromDirty((int)puVar10);
      }
      iVar5 = puVar10[7];
      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + -1;
      if (puVar10[5] == 1) {
        *(undefined4 *)(iVar5 + 0x2c) = 0;
      }
      (*DAT_00582b4c)(*(undefined4 *)(iVar5 + 0x28),*puVar10,1);
      goto LAB_0047fd09;
    }
    if (((*(char *)((int)puVar1 + 0xe) == '\0') && (puVar1[6] != 0)) && (*(int *)puVar1[0xf] != 0))
    {
      puVar1[0x29] = puVar1[0x29] + 1;
      param_1 = (int *)pager_readDbPage((int)local_10);
      if (param_1 != (int *)0x0) goto LAB_0047fcd7;
    }
    else {
      if (puVar1[0x21] == 0) {
        param_1 = (int *)0xd;
        goto LAB_0047fcd7;
      }
      memset((void *)local_10[1],0,puVar1[0x20]);
    }
  }
  else {
LAB_0047fd09:
    if (*(int *)(puVar1[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar1);
    }
    puVar10 = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      return (uint)param_1;
    }
  }
LAB_0047fd2b:
  local_8 = puVar10[2];
  piVar2 = (int *)puVar10[1];
  *(undefined4 **)(local_8 + 0x44) = puVar10;
  *(int **)(local_8 + 0x38) = piVar2;
  *(int **)(local_8 + 0x34) = piVar3;
  *(undefined4 *)(local_8 + 0x48) = 1;
  *(undefined1 *)(local_8 + 5) = 100;
  local_c = CONCAT31(CONCAT21(CONCAT11((char)piVar2[7],*(undefined1 *)((int)piVar2 + 0x1d)),
                              *(undefined1 *)((int)piVar2 + 0x1e)),
                     *(undefined1 *)((int)piVar2 + 0x1f));
  iVar5 = *(int *)(*piVar3 + 0x18);
  if ((local_c == 0) || (piVar2[6] != piVar2[0x17])) {
    local_c = iVar5;
  }
  if (local_c < 1) {
LAB_0047ff15:
    iVar5 = (uint)((piVar3[9] + -0xc) * 0x40) / 0xff - 0x17;
    sVar8 = (short)((uint)((piVar3[9] + -0xc) * 0x20) / 0xff) + -0x17;
    uVar6 = (ushort)iVar5;
    *(ushort *)(piVar3 + 6) = uVar6;
    *(short *)((int)piVar3 + 0x1a) = sVar8;
    *(short *)(piVar3 + 7) = (short)piVar3[9] + -0x23;
    *(short *)((int)piVar3 + 0x1e) = sVar8;
    if (uVar6 < 0x80) {
      *(char *)(piVar3 + 5) = (char)iVar5;
    }
    else {
      *(undefined1 *)(piVar3 + 5) = 0x7f;
    }
    piVar3[3] = local_8;
    piVar3[0xb] = local_c;
    return 0;
  }
  param_1 = (int *)0x1a;
  pcVar9 = "SQLite format 3";
  uVar4 = 0xc;
  piVar7 = piVar2;
  do {
    if (*piVar7 != *(int *)pcVar9) goto LAB_0047fec5;
    piVar7 = piVar7 + 1;
    pcVar9 = (char *)((int)pcVar9 + 4);
    bVar11 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar11);
  if (2 < *(byte *)((int)piVar2 + 0x12)) {
    *(ushort *)((int)piVar3 + 0x16) = *(ushort *)((int)piVar3 + 0x16) | 1;
  }
  if (*(byte *)((int)piVar2 + 0x13) < 3) {
    if ((*(byte *)((int)piVar2 + 0x13) == 2) && ((*(byte *)((int)piVar3 + 0x16) & 0x10) == 0)) {
      local_10 = (undefined4 *)0x0;
      param_1 = (int *)pager_write_dirty_or_openWal((int *)*piVar3,&local_10);
      if (param_1 != (int *)0x0) goto LAB_0047fec5;
      if (local_10 == (undefined4 *)0x0) {
        btree_releasePage(local_8);
        return 0;
      }
    }
    param_1 = (int *)0x1a;
    if ((((*(short *)((int)piVar2 + 0x15) == 0x2040) && (*(char *)((int)piVar2 + 0x17) == ' ')) &&
        (uVar4 = (uint)*(ushort *)(piVar2 + 4) * 0x100, (uVar4 & uVar4 - 1) == 0)) &&
       (uVar4 - 0x101 < 0xff00)) {
      local_10 = (undefined4 *)(uVar4 - *(byte *)(piVar2 + 5));
      if (uVar4 != piVar3[8]) {
        btree_releasePage(local_8);
        puVar10 = local_10;
        piVar3[9] = (int)local_10;
        piVar3[8] = uVar4;
        pager_freeSavepointBitvec((int)piVar3);
        uVar4 = sqlite3PagerSetPagesize(*piVar3,(uint *)(piVar3 + 8),uVar4 - (int)puVar10);
        return uVar4;
      }
      if (((*(uint *)(piVar3[1] + 0x18) & 0x8000) == 0) && (iVar5 < local_c)) {
        param_1 = (int *)sqlite3CorruptError();
      }
      else if ((undefined4 *)0x1df < local_10) {
        piVar3[8] = uVar4;
        piVar3[9] = (int)local_10;
        iVar5 = sqlite3Get4byte((undefined1 *)(piVar2 + 0xd));
        *(bool *)((int)piVar3 + 0x11) = iVar5 != 0;
        iVar5 = sqlite3Get4byte((undefined1 *)(piVar2 + 0x10));
        *(bool *)((int)piVar3 + 0x12) = iVar5 != 0;
        goto LAB_0047ff15;
      }
    }
  }
LAB_0047fec5:
  btree_releasePage(local_8);
  piVar3[3] = 0;
  return (uint)param_1;
}




/* [AUDIT] proposed: sqlite3_mallocRaw  (confidence: high)
 * purpose: Allocates via xMalloc with size/count accounting and soft-heap-limit check; SQLite mallocWithWarning
 * vars: param_2=out ptr; DAT_00583e18 used
 */
/* Global::sqlite3_mallocRaw @ 00480650 */


uint __cdecl sqlite3_mallocRaw(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (*DAT_00582af8)(param_1);
  if (DAT_00583e54 < param_1) {
    DAT_00583e54 = param_1;
  }
  _DAT_00583e2c = param_1;
  if (DAT_00583f50 != 0) {
    iVar2 = (DAT_00583f4c - ((int)uVar1 >> 0x1f)) - (uint)(DAT_00583f48 < uVar1);
    if (((int)DAT_00583e18 >> 0x1f < iVar2) ||
       (((int)DAT_00583e18 >> 0x1f <= iVar2 && (DAT_00583e18 < DAT_00583f48 - uVar1)))) {
      DAT_00583f64 = 0;
    }
    else {
      DAT_00583f64 = 1;
      sqlite3MallocAlarm(uVar1);
    }
  }
  iVar2 = (*DAT_00582ae8)(uVar1);
  if (iVar2 != 0) {
    uVar1 = (*DAT_00582af0._4_4_)(iVar2);
    DAT_00583e18 = DAT_00583e18 + uVar1;
    if (DAT_00583e40 < (int)DAT_00583e18) {
      DAT_00583e40 = DAT_00583e18;
    }
    DAT_00583e3c = DAT_00583e3c + 1;
    if (DAT_00583e64 < DAT_00583e3c) {
      DAT_00583e64 = DAT_00583e3c;
    }
    *param_2 = iVar2;
    return uVar1;
  }
  *param_2 = 0;
  return uVar1;
}




/* [AUDIT] proposed: btree_putCellPtr  (confidence: med)
 * purpose: Writes a 4-byte value into a page cell's pointer field, searching cells by matching old value; SQLite; 'database corruption'
 * vars: param_4=eType; param_2=old val
 */
/* Global::btree_putCellPtr @ 00480840 */

undefined4 __cdecl btree_putCellPtr(char *param_1,int param_2,undefined4 param_3,char param_4)

{
  undefined1 uVar1;
  undefined1 uVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint local_2c [6];
  ushort local_14;
  uint local_c;
  char local_5;
  undefined1 uVar2;
  undefined1 uVar3;
  
  uVar4 = (undefined1)param_3;
  uVar1 = (undefined1)((uint)param_3 >> 8);
  uVar2 = (undefined1)((uint)param_3 >> 0x10);
  uVar3 = (undefined1)((uint)param_3 >> 0x18);
  if (param_4 == '\x04') {
    puVar8 = *(undefined1 **)(param_1 + 0x38);
    if (CONCAT31(CONCAT21(CONCAT11(*puVar8,puVar8[1]),puVar8[2]),puVar8[3]) == param_2) {
      *puVar8 = uVar3;
      puVar8[1] = uVar2;
      puVar8[2] = uVar1;
      puVar8[3] = uVar4;
      return 0;
    }
    sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
    return 0xb;
  }
  local_5 = *param_1;
  btree_initPage(param_1);
  local_c = (uint)*(ushort *)(param_1 + 0x10);
  uVar7 = 0;
  if (local_c != 0) {
    do {
      puVar8 = (undefined1 *)
               ((uint)(CONCAT11(*(undefined1 *)(*(int *)(param_1 + 0x40) + uVar7 * 2),
                                *(undefined1 *)(*(int *)(param_1 + 0x40) + 1 + uVar7 * 2)) &
                      *(ushort *)(param_1 + 0x12)) + *(int *)(param_1 + 0x38));
      if (param_4 == '\x03') {
        btree_parseCellPtr((int)param_1,(uint)puVar8,local_2c);
        if (((local_14 != 0) &&
            (puVar5 = puVar8 + local_14,
            puVar5 + 3 <=
            (undefined1 *)((uint)*(ushort *)(param_1 + 0x12) + *(int *)(param_1 + 0x38)))) &&
           (param_2 == CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]))) {
          puVar8 = puVar8 + local_14;
          *puVar8 = uVar3;
          puVar8[1] = uVar2;
          puVar8[2] = uVar1;
          puVar8[3] = uVar4;
          break;
        }
      }
      else if (CONCAT31(CONCAT21(CONCAT11(*puVar8,puVar8[1]),puVar8[2]),puVar8[3]) == param_2) {
        *puVar8 = uVar3;
        puVar8[1] = uVar2;
        puVar8[2] = uVar1;
        puVar8[3] = uVar4;
        break;
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)local_c);
  }
  if (uVar7 == local_c) {
    if ((param_4 != '\x05') ||
       (iVar6 = (uint)(byte)param_1[5] + *(int *)(param_1 + 0x38),
       CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 8),*(undefined1 *)(iVar6 + 9)),
                         *(undefined1 *)(iVar6 + 10)),*(undefined1 *)(iVar6 + 0xb)) != param_2)) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      return 0xb;
    }
    *(undefined1 *)(iVar6 + 8) = uVar3;
    *(undefined1 *)(iVar6 + 9) = uVar2;
    *(undefined1 *)(iVar6 + 10) = uVar1;
    *(undefined1 *)(iVar6 + 0xb) = uVar4;
  }
  *param_1 = local_5;
  return 0;
}




/* [AUDIT] proposed: pager_pageToOffset  (confidence: high)
 * purpose: Converts a negative page number to file offset (allmul/alldiv by page size); SQLite
 * vars: param_1+0x10 pgno; +0x14/18 sizes
 */
/* Global::pager_pageToOffset @ 00483490 */

undefined8 __cdecl pager_pageToOffset(int param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (-1 < (int)uVar1) {
    return CONCAT44(param_1,uVar1);
  }
  uVar2 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14);
  lVar3 = __allmul(uVar1,(int)uVar1 >> 0x1f,0xfffffc00,-1);
  uVar4 = __alldiv((uint)lVar3,(uint)((ulonglong)lVar3 >> 0x20),uVar2,(int)uVar2 >> 0x1f);
  return uVar4;
}




/* [AUDIT] proposed: openDatabase  (confidence: high)
 * purpose: SQLite 3.7.15.2 openDatabase: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 13.3). Anchors: BINARY|MATCH|NOCASE|RTRIM
 * vars: -
 */
/* Global::openDatabase @ 004834d0 */

uint __cdecl openDatabase(int *param_1,undefined4 *param_2,uint param_3,byte *param_4)

{
  uint uVar1;
  int *_Dst;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  void *pvVar6;
  uint uVar7;
  int local_c;
  byte *local_8;
  
  local_8 = (byte *)0x0;
  local_c = 0;
  *param_2 = 0;
  uVar1 = sqlite3_initialize();
  if (uVar1 != 0) {
    return uVar1;
  }
  if ((1 << ((byte)param_3 & 7) & 0x46U) == 0) {
    sqlite3_log(0x15,"misuse at line %d of [%.10s]");
    return 0x15;
  }
  if (DAT_00582acc == 0) {
    iVar2 = 0;
  }
  else if ((param_3 & 0x8000) == 0) {
    iVar2 = DAT_00582ad0;
    if ((param_3 & 0x10000) != 0) {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 0;
  }
  if ((param_3 & 0x40000) == 0) {
    if (DAT_00582b8c != 0) {
      param_3 = param_3 | 0x20000;
    }
  }
  else {
    param_3 = param_3 & 0xfffdffff;
  }
  uVar1 = param_3 & 0xfff600e7;
  param_3 = uVar1;
  _Dst = (int *)sqlite3Malloc(0x1f8);
  pbVar5 = local_8;
  if ((_Dst != (int *)0x0) && (memset(_Dst,0,0x1f8), pbVar5 = local_8, _Dst != (int *)0x0)) {
    if (iVar2 != 0) {
      if (DAT_00582acc == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*DAT_00582b10)(1);
      }
      _Dst[3] = iVar2;
      if (iVar2 == 0) {
        sqlite3_free((int)_Dst);
        _Dst = (int *)0x0;
        pbVar5 = local_8;
        goto LAB_004835dd;
      }
    }
    if (_Dst[3] != 0) {
      (*DAT_00582b18)(_Dst[3]);
    }
    _Dst[0xc] = 0xff;
    _Dst[5] = 2;
    _Dst[0x11] = -0xfc486fa;
    _Dst[4] = (int)(_Dst + 0x6e);
    _Dst[0x14] = 1000000000;
    _Dst[0x15] = 1000000000;
    _Dst[0x16] = 2000;
    _Dst[0x17] = 1000;
    _Dst[0x18] = 500;
    _Dst[0x19] = 25000;
    _Dst[0x1a] = 0x7f;
    _Dst[0x1b] = 10;
    _Dst[0x1c] = 50000;
    _Dst[0x1d] = 999;
    _Dst[6] = _Dst[6] | 0x480008;
    _Dst[0x1e] = 1000;
    *(undefined1 *)((int)_Dst + 0x36) = 1;
    *(undefined1 *)((int)_Dst + 0x3a) = 0xff;
    _Dst[0x10] = 0;
    _Dst[0x69] = 0;
    _Dst[0x68] = 0;
    _Dst[0x67] = 0;
    _Dst[0x6a] = 0;
    _Dst[0x4b] = 0;
    _Dst[0x4a] = 0;
    _Dst[0x49] = 0;
    _Dst[0x4c] = 0;
    sqlite3_createCollation((int)_Dst,(byte *)"BINARY",1,0,0x4708e0,0);
    sqlite3_createCollation((int)_Dst,(byte *)"BINARY",3,0,0x4708e0,0);
    sqlite3_createCollation((int)_Dst,(byte *)"BINARY",2,0,0x4708e0,0);
    sqlite3_createCollation((int)_Dst,(byte *)"RTRIM",1,1,0x4708e0,0);
    pbVar5 = local_8;
    if ((char)_Dst[0xe] == '\0') {
      piVar3 = sqlite3FindDbFunction((int)_Dst,1,(byte *)"BINARY",0);
      _Dst[2] = (int)piVar3;
      sqlite3_createCollation((int)_Dst,(byte *)"NOCASE",1,0,0x483460,0);
      _Dst[10] = uVar1;
      iVar4 = sqlite3ParseUri(param_4,param_1,&param_3,_Dst,&local_8,&local_c);
      pbVar5 = local_8;
      iVar2 = local_c;
      if (iVar4 == 0) {
        iVar2 = sqlite3BtreeOpen((undefined *)*_Dst,local_8,(int)_Dst,(undefined4 *)(_Dst[4] + 4),0,
                             param_3 | 0x100);
        if (iVar2 == 0) {
          pvVar6 = sqlite3SchemaGet((int)_Dst,*(undefined4 **)(_Dst[4] + 4));
          *(void **)(_Dst[4] + 0xc) = pvVar6;
          pvVar6 = sqlite3SchemaGet((int)_Dst,(undefined4 *)0x0);
          *(void **)(_Dst[4] + 0x1c) = pvVar6;
          *(undefined **)_Dst[4] = &DAT_0057151c;
          *(undefined1 *)(_Dst[4] + 9) = 3;
          *(undefined1 **)(_Dst[4] + 0x10) = &DAT_00571350;
          *(undefined1 *)(_Dst[4] + 0x19) = 1;
          _Dst[0x11] = -0x5fd65969;
          if ((char)_Dst[0xe] == '\0') {
            sqlite3ErrorWithMsg((int)_Dst,0,(byte *)0x0);
            uVar1 = sqlite3_overloadFunction((int)_Dst,(byte *)"MATCH",2);
            if (uVar1 == 7) {
              *(undefined1 *)(_Dst + 0xe) = 1;
            }
            uVar1 = sqlite3_errcode((int)_Dst);
            if (uVar1 == 0) {
              sqlite3_autoExtensions((int)_Dst);
              uVar7 = sqlite3_errcode((int)_Dst);
              uVar1 = 0;
              if (uVar7 != 0) goto LAB_004835dd;
            }
            sqlite3ErrorWithMsg((int)_Dst,uVar1,(byte *)0x0);
            sqlite3_setupLookaside((int)_Dst,(undefined4 *)0x0,DAT_00582ae0,DAT_00582ae4);
            if (_Dst[3] != 0) {
              (*DAT_00582b18)(_Dst[3]);
            }
            _Dst[0x30] = (int)lib_fn_4ba730;
            _Dst[0x31] = 1000;
            if (_Dst[3] != 0) {
              (*DAT_00582b20)(_Dst[3]);
            }
          }
        }
        else {
          if (iVar2 == 0xc0a) {
            iVar2 = 7;
          }
          sqlite3ErrorWithMsg((int)_Dst,iVar2,(byte *)0x0);
        }
      }
      else {
        if (iVar4 == 7) {
          *(undefined1 *)(_Dst + 0xe) = 1;
        }
        pbVar5 = &DAT_0056de50;
        if (local_c == 0) {
          pbVar5 = (byte *)0x0;
        }
        sqlite3ErrorWithMsg((int)_Dst,iVar4,pbVar5);
        sqlite3_free(iVar2);
        pbVar5 = local_8;
      }
    }
  }
LAB_004835dd:
  sqlite3_free((int)pbVar5);
  if ((_Dst != (int *)0x0) && (_Dst[3] != 0)) {
    (*DAT_00582b20)(_Dst[3]);
  }
  uVar1 = sqlite3_errcode((int)_Dst);
  if (uVar1 != 7) {
    if (uVar1 != 0) {
      _Dst[0x11] = 0x4b771290;
    }
    *param_2 = _Dst;
    return uVar1 & 0xff;
  }
  sqlite3_fn_492580(_Dst,0);
  *param_2 = 0;
  return 7;
}




/* [AUDIT] proposed: vdbe_initPseudoCursor  (confidence: low)
 * purpose: Initializes a pseudo/ephemeral cursor default state or xShmMap (+0x18); SQLite VdbeCursor setup
 * vars: param_1[0x11] pCursor
 */
/* Global::vdbe_initPseudoCursor @ 00483b10 */

undefined4 __cdecl vdbe_initPseudoCursor(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)param_1[0x11];
  if (*piVar1 == 0) {
    if ((*(char *)((int)param_1 + 5) != '\x04') && (*(char *)((int)param_1 + 0x15) == '\0')) {
      uVar2 = (**(code **)(*param_1 + 0x18))(*param_1,0,piVar1,0x201e,0);
      return uVar2;
    }
    piVar1[0] = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    *piVar1 = (int)&DAT_00569a48;
  }
  return 0;
}




/* [AUDIT] proposed: pager_walCheckpointCheck  (confidence: low)
 * purpose: Checks/updates WAL frame availability (4ba0e0), marks cursors stale on change; SQLite
 * vars: param_1+0xb8 pWal; +0x58 cursor list
 */
/* Global::pager_walCheckpointCheck @ 00483bd0 */

int __cdecl pager_walCheckpointCheck(int param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  walIteratorFree_or_restart(*(int *)(param_1 + 0xb8));
  iVar2 = walTryBeginRead(*(int **)(param_1 + 0xb8),&local_8);
  if ((iVar2 != 0) || (local_8 != 0)) {
    for (iVar1 = *(int *)(param_1 + 0x58); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
      *(undefined4 *)(iVar1 + 0x10) = 1;
    }
    pcacheTruncate(*(undefined4 **)(param_1 + 0xb4),0);
  }
  return iVar2;
}




/* [AUDIT] proposed: pager_lockDbDefault  (confidence: high)
 * purpose: Acquires DB lock at level 4 (RESERVED) via VFS xLock, updates lock state; SQLite pagerLockDb
 * vars: param_1+0x3c fd; +0x10 eLock
 */
/* Global::pager_lockDbDefault @ 00483c40 */

int __cdecl pager_lockDbDefault(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((3 < *(byte *)(param_1 + 0x10)) && (*(byte *)(param_1 + 0x10) != 5)) {
    return 0;
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x1c))(*(int **)(param_1 + 0x3c),4);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 4;
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x3c);
  if (*piVar1 != 0) {
    (**(code **)(*piVar1 + 0x20))(piVar1,1);
    if (*(char *)(param_1 + 0x10) != '\x05') {
      *(undefined1 *)(param_1 + 0x10) = 1;
    }
  }
  return iVar2;
}




/* [AUDIT] proposed: pager_lockDb  (confidence: high)
 * purpose: Acquires DB lock at level param_2 via VFS xLock, updates eLock; SQLite pagerLockDb
 * vars: param_2=lock level; +0x10 eLock
 */
/* Global::pager_lockDb @ 00483ca0 */

int __cdecl pager_lockDb(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 <= (int)(uint)*(byte *)(param_1 + 0x10)) && (*(byte *)(param_1 + 0x10) != 5)) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x1c))(*(int **)(param_1 + 0x3c),param_2);
  if ((iVar1 == 0) && ((*(char *)(param_1 + 0x10) != '\x05' || (param_2 == 4)))) {
    *(char *)(param_1 + 0x10) = (char)param_2;
  }
  return iVar1;
}




/* [AUDIT] proposed: pager_unlockAndRollback  (confidence: high)
 * purpose: Unlocks/rolls back pager if in error/none state (4bac90); SQLite pagerUnlockAndRollback
 * vars: param_1[0xf] journalMode; [0x2f] fd
 */
/* Global::pager_unlockAndRollback @ 00483cf0 */

void __cdecl pager_unlockAndRollback(int *param_1)

{
  int iVar1;
  
  if (((char)param_1[1] != '\0') && (iVar1 = pager_lockDbDefault((int)param_1), iVar1 != 0)) {
    return;
  }
  sqlite3WalOpen(*param_1,param_1[0xf],param_1[0x2f],(uint)*(byte *)(param_1 + 1),param_1[0x22],
               param_1[0x23],param_1 + 0x2e);
  return;
}




/* [AUDIT] proposed: pager_endTransactionCheck  (confidence: low)
 * purpose: Ends/downgrades transaction: checks file size via VFS then unlock/truncate; SQLite pager_end_transaction
 * vars: piVar1[0x2f] fd; local_8 result
 */
/* Global::pager_endTransactionCheck @ 00483d40 */

void __cdecl pager_endTransactionCheck(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint local_8;
  
  piVar1 = param_1;
  if ((char)param_1[3] == '\0') {
    iVar2 = pager_pageCount((int)param_1,&local_8);
    if (iVar2 == 0) {
      iVar2 = *piVar1;
      if (local_8 == 0) {
        iVar2 = (**(code **)(iVar2 + 0x1c))(iVar2,piVar1[0x2f],0);
        if (iVar2 == 0x170a) {
          iVar2 = 0;
        }
        param_1 = (int *)0x0;
      }
      else {
        iVar2 = (**(code **)(iVar2 + 0x20))(iVar2,piVar1[0x2f],0,&param_1);
      }
      if (iVar2 == 0) {
        if (param_1 != (int *)0x0) {
          pager_write_dirty_or_openWal(piVar1,(undefined4 *)0x0);
          return;
        }
        if (*(char *)((int)piVar1 + 5) == '\x05') {
          *(undefined1 *)((int)piVar1 + 5) = 0;
        }
      }
    }
  }
  return;
}




/* [AUDIT] proposed: pager_pageCount  (confidence: high)
 * purpose: Computes DB size in pages from WAL or VFS xFileSize; SQLite sqlite3PagerPagecount
 * vars: param_1+0xb8 pWal; +0x80 pageSize; +0x84 dbSize
 */
/* Global::pager_pageCount @ 00483dd0 */

int __cdecl pager_pageCount(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 local_c;
  
  iVar2 = *(int *)(param_1 + 0xb8);
  if (((iVar2 == 0) || (*(short *)(iVar2 + 0x28) < 0)) ||
     (uVar3 = *(uint *)(iVar2 + 0x48), uVar3 == 0)) {
    piVar1 = *(int **)(param_1 + 0x3c);
    local_c = 0;
    if ((*piVar1 != 0) && (iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,&local_c), iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = *(uint *)(param_1 + 0x80);
    uVar4 = __alldiv((uVar3 + (uint)local_c) - 1,
                     (((int)uVar3 >> 0x1f) + local_c._4_4_ + (uint)CARRY4(uVar3,(uint)local_c)) -
                     (uint)(uVar3 + (uint)local_c == 0),uVar3,(int)uVar3 >> 0x1f);
    uVar3 = (uint)uVar4;
  }
  if (*(uint *)(param_1 + 0x84) < uVar3) {
    *(uint *)(param_1 + 0x84) = uVar3;
  }
  *param_2 = uVar3;
  return 0;
}




/* [AUDIT] proposed: pager_playbackSavepoint  (confidence: med)
 * purpose: Plays back journal/savepoint pages or full journal to restore state (484f60 per-page); SQLite pagerPlaybackSavepoint
 * vars: param_2=savepoint; local_24 offset
 */
/* Global::pager_playbackSavepoint @ 00483e60 */

uint __cdecl pager_playbackSavepoint(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined8 local_24;
  uint *local_1c;
  uint local_18;
  uint local_14;
  uint *local_10;
  uint local_c;
  uint local_8;
  
  uVar4 = 0;
  local_10 = (uint *)0x0;
  if (param_2 == (uint *)0x0) {
    uVar3 = param_1[7];
LAB_00483ec5:
    puVar2 = local_10;
    param_1[6] = uVar3;
    *(undefined1 *)((int)param_1 + 0x11) = *(undefined1 *)(param_1 + 3);
    if ((param_2 == (uint *)0x0) && (param_1[0x2e] != 0)) {
      uVar4 = pager_playbackAllPages((int)param_1);
      return uVar4;
    }
    local_8 = param_1[0x12];
    local_c = param_1[0x13];
    puVar5 = param_1 + 0x12;
    local_1c = puVar5;
    if ((param_2 != (uint *)0x0) && (param_1[0x2e] == 0)) {
      local_14 = local_8;
      local_18 = local_c;
      if (param_2[2] != 0 || param_2[3] != 0) {
        local_14 = param_2[2];
        local_18 = param_2[3];
      }
      *puVar5 = *param_2;
      param_1[0x13] = param_2[1];
      do {
        if (((int)local_18 < (int)param_1[0x13]) ||
           (((int)local_18 <= (int)param_1[0x13] && (local_14 <= *puVar5)))) {
          if (uVar4 == 0) goto LAB_00484050;
          break;
        }
        uVar4 = pager_playbackOnePageJournal(param_1,puVar5,puVar2,1,1);
      } while (uVar4 == 0);
LAB_00483f73:
      if (param_2 != (uint *)0x0) {
        local_24 = __allmul(param_1[0x20] + 4,(int)(param_1[0x20] + 4) >> 0x1f,param_2[6],0);
        iVar1 = param_1[0x2e];
        if (iVar1 != 0) {
          if (param_2[10] != *(uint *)(iVar1 + 0x68)) {
            param_2[7] = 0;
            param_2[10] = *(uint *)(iVar1 + 0x68);
          }
          if (param_2[7] < *(uint *)(iVar1 + 0x44)) {
            *(uint *)(iVar1 + 0x44) = param_2[7];
            *(uint *)(iVar1 + 0x4c) = param_2[8];
            *(uint *)(iVar1 + 0x50) = param_2[9];
            walCleanupHash(iVar1);
          }
          uVar4 = 0;
        }
        puVar2 = local_10;
        for (uVar3 = param_2[6]; (uVar4 == 0 && (puVar5 = local_1c, uVar3 < (uint)param_1[0xd]));
            uVar3 = uVar3 + 1) {
          uVar4 = pager_playbackOnePageJournal(param_1,(uint *)&local_24,puVar2,0,1);
          puVar5 = local_1c;
        }
      }
      bitvec_destroy((int)local_10);
      if (uVar4 == 0) {
        *puVar5 = local_8;
        puVar5[1] = local_c;
      }
      return uVar4;
    }
    *puVar5 = 0;
    param_1[0x13] = 0;
LAB_00484050:
    do {
      if (((int)local_c < (int)param_1[0x13]) ||
         (((int)local_c <= (int)param_1[0x13] && (local_8 <= *puVar5)))) goto LAB_00483f73;
      local_18 = 0;
      uVar4 = pager_readJournalHeader((int)param_1,0,local_8,local_c,&local_18,(uint *)((int)&local_24 + 4));
      local_14 = local_18;
      if ((local_18 == 0) &&
         ((param_1[0x1f] + param_1[0x14] == *puVar5 &&
          (param_1[0x15] + (uint)CARRY4(param_1[0x1f],param_1[0x14]) == param_1[0x13])))) {
        uVar6 = __alldiv(local_8 - *puVar5,(local_c - param_1[0x13]) - (uint)(local_8 < *puVar5),
                         param_1[0x20] + 8,(int)(param_1[0x20] + 8) >> 0x1f);
        local_14 = (uint)uVar6;
      }
      uVar3 = 0;
      while( true ) {
        if (uVar4 != 0) goto LAB_00483f73;
        if (local_14 <= uVar3) break;
        if ((int)local_c < (int)param_1[0x13]) goto LAB_00483f73;
        if (((int)local_c <= (int)param_1[0x13]) && (local_8 <= *puVar5)) break;
        uVar4 = pager_playbackOnePageJournal(param_1,puVar5,local_10,1,1);
        uVar3 = uVar3 + 1;
      }
    } while( true );
  }
  local_18 = param_2[5];
  puVar2 = (uint *)sqlite3Malloc(0x200);
  if (puVar2 != (uint *)0x0) {
    local_10 = puVar2;
    memset(puVar2,0,0x200);
    *puVar2 = local_18;
    if (puVar2 != (uint *)0x0) {
      uVar3 = param_2[5];
      goto LAB_00483ec5;
    }
  }
  return 7;
}




/* [AUDIT] proposed: pager_playbackAllPages  (confidence: med)
 * purpose: Applies pager_playbackOnePage(4842a0) to every in-journal/dirty page (4baf40 iterate); SQLite
 * vars: param_1+0x1c origSize; +0xb8 pWal
 */
/* Global::pager_playbackAllPages @ 00484120 */

int __cdecl pager_playbackAllPages(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  iVar2 = sqlite3WalUndo_or_iterate(*(int *)(param_1 + 0xb8),pager_playbackOnePage,param_1);
  puVar3 = pcacheSortDirtyList(*(int **)(param_1 + 0xb4));
  if (puVar3 == (undefined1 *)0x0) {
    return iVar2;
  }
  do {
    if (iVar2 != 0) {
      return iVar2;
    }
    piVar1 = (int *)(puVar3 + 0x14);
    puVar3 = *(undefined1 **)(puVar3 + 0xc);
    iVar2 = pager_playbackOnePage(param_1,*piVar1);
  } while (puVar3 != (undefined1 *)0x0);
  return iVar2;
}




/* [AUDIT] proposed: pager_syncJournal  (confidence: high)
 * purpose: Syncs journal file (VFS xSync) unless nosync flag; SQLite pager syncJournal
 * vars: param_1+0x40 fd; +0x50 sync flags
 */
/* Global::pager_syncJournal @ 00484260 */

void __cdecl pager_syncJournal(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 7) == '\0') &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x14))(*(int **)(param_1 + 0x40),2),
     iVar1 != 0)) {
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x40) + 0x18))(*(int **)(param_1 + 0x40),param_1 + 0x50);
  return;
}




/* [AUDIT] proposed: pager_playbackOnePage  (confidence: med)
 * purpose: Reads a page record from savepoint bitvec and writes it back to DB; SQLite pager_playback_one_page; marks cursors
 * vars: local_8=pPager2; +0xb4 pPager
 */
/* Global::pager_playbackOnePage @ 004842a0 */

int __cdecl pager_playbackOnePage(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *local_8;
  
  iVar4 = 0;
  local_8 = (undefined4 *)0x0;
  sqlite3PcacheFetch(*(int **)(param_1 + 0xb4),param_2,0,&local_8);
  puVar3 = local_8;
  if (local_8 != (undefined4 *)0x0) {
    if (*(short *)((int)local_8 + 0x1a) == 1) {
      if ((*(byte *)(local_8 + 6) & 2) != 0) {
        pcache_removeFromDirty((int)local_8);
      }
      iVar1 = puVar3[7];
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -1;
      if (puVar3[5] == 1) {
        *(undefined4 *)(iVar1 + 0x2c) = 0;
      }
      (*DAT_00582b4c)(*(undefined4 *)(iVar1 + 0x28),*puVar3,1);
    }
    else {
      iVar4 = pager_readDbPage((int)local_8);
      if (iVar4 == 0) {
        (**(code **)(param_1 + 0xac))(puVar3);
      }
      puVar2 = (uint *)puVar3[4];
      sqlite3PcacheRelease(puVar3);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
    }
  }
  for (iVar1 = *(int *)(param_1 + 0x58); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  return iVar4;
}




/* [AUDIT] proposed: pcache_releasePage  (confidence: high)
 * purpose: Releases/unrefs a PgHdr: writes back or drops to free list per dirty state; SQLite sqlite3PcacheRelease
 * vars: param_1+0xf nRef; +1 flags
 */
/* Global::pcache_releasePage @ 00484370 */

void __cdecl pcache_releasePage(uint *param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 0xf);
  if ((bVar1 != 6) && (bVar1 != 0)) {
    if (bVar1 < 2) {
      if ((char)param_1[1] == '\0') {
        pager_endTransaction((int *)param_1,0);
      }
    }
    else {
      if (DAT_00583e74 != (code *)0x0) {
        (*DAT_00583e74)();
      }
      sqlite3PagerCommitPhaseTwo_or_sync(param_1);
      if (DAT_00583e78 != (code *)0x0) {
        (*DAT_00583e78)();
        pcache_freePage((int)param_1);
        return;
      }
    }
  }
  pcache_freePage((int)param_1);
  return;
}




/* [AUDIT] proposed: pager_unlockDb  (confidence: high)
 * purpose: Releases DB lock (VFS xUnlock at +0x20) and updates eLock; SQLite pagerUnlockDb
 * vars: param_2=level; +0x10 eLock
 */
/* Global::pager_unlockDb @ 004843d0 */

undefined4 __cdecl pager_unlockDb(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (*piVar1 != 0) {
    uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,param_2);
    if (*(char *)(param_1 + 0x10) != '\x05') {
      *(char *)(param_1 + 0x10) = (char)param_2;
    }
    return uVar2;
  }
  return 0;
}




/* [AUDIT] proposed: pager_writeDirtyList  (confidence: med)
 * purpose: Writes a list of dirty pages to disk (4ba7d0), notifies cursors (48e040); SQLite pager_write_pagelist
 * vars: param_1+0xa8 nWrite; +0xb8 pWal
 */
/* Global::pager_writeDirtyList @ 00484410 */

int __cdecl pager_writeDirtyList(int param_1,uint *param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint **ppuVar5;
  
  uVar3 = param_3;
  if (param_4 == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
    ppuVar5 = &param_2;
    puVar1 = param_2;
    while (puVar1 != (uint *)0x0) {
      if (puVar1[5] <= uVar3) {
        ppuVar5 = (uint **)(puVar1 + 3);
        iVar4 = iVar4 + 1;
      }
      puVar1 = (uint *)puVar1[3];
      *ppuVar5 = puVar1;
    }
  }
  puVar1 = param_2;
  *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + iVar4;
  if (param_2[5] == 1) {
    pager_writeChangeCounter((int)param_2);
  }
  iVar4 = walWriteFrames_inner(*(int **)(param_1 + 0xb8),*(uint *)(param_1 + 0x80),puVar1,uVar3,param_4,
                       (uint)*(byte *)(param_1 + 10));
  if (iVar4 == 0) {
    puVar2 = *(uint **)(param_1 + 0x58);
    while (puVar2 != (uint *)0x0) {
      btree_writeOverflowCursors(*(int **)(param_1 + 0x58),(undefined4 *)puVar1[5],puVar1[1]);
      puVar1 = (uint *)puVar1[3];
      puVar2 = puVar1;
    }
  }
  return iVar4;
}




/* [AUDIT] proposed: pager_cksum  (confidence: high)
 * purpose: Computes page checksum by sampling bytes at 200-byte stride; SQLite pager_cksum
 * vars: param_1+0x80 pageSize; +0x30 cksumInit
 */
/* Global::pager_cksum @ 004844b0 */

int __cdecl pager_cksum(int param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x80) + -200;
  iVar4 = 0;
  iVar5 = 0;
  if (0 < iVar2) {
    if (1 < (*(int *)(param_1 + 0x80) + -1) / 200) {
      do {
        iVar4 = iVar4 + (uint)*(byte *)(param_2 + iVar2);
        pbVar1 = (byte *)(param_2 + -200 + iVar2);
        iVar2 = iVar2 + -400;
        iVar5 = iVar5 + (uint)*pbVar1;
      } while (200 < iVar2);
    }
    if (0 < iVar2) {
      iVar3 = iVar3 + (uint)*(byte *)(iVar2 + param_2);
    }
    return iVar5 + iVar4 + iVar3;
  }
  return iVar3;
}




/* [AUDIT] proposed: pager_deleteMasterJournal  (confidence: low)
 * purpose: Reads super/master-journal, opens each child journal, deletes master if all children obsolete; SQLite pager_delmaster
 * vars: _Dst journal fd; local_c filenames
 */
/* Global::pager_deleteMasterJournal @ 00484530 */

int __cdecl pager_deleteMasterJournal(int *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  size_t _Size;
  int *_Dst;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  char *pcVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  byte *local_10;
  char *local_c;
  int *local_8;
  
  iVar3 = *param_1;
  _Size = *(int *)(iVar3 + 4) * 2;
  local_c = (char *)0x0;
  _Dst = (int *)sqlite3Malloc(_Size);
  if (_Dst != (int *)0x0) {
    memset(_Dst,0,_Size);
  }
  local_8 = (int *)(*(int *)(iVar3 + 4) + (int)_Dst);
  if (_Dst == (int *)0x0) {
    iVar4 = 7;
  }
  else {
    iVar4 = (**(code **)(iVar3 + 0x18))(iVar3,param_2,_Dst,0x4001,0);
    if ((iVar4 == 0) && (iVar4 = (**(code **)(*_Dst + 0x18))(_Dst,&local_20), iVar4 == 0)) {
      local_18 = *(int *)(iVar3 + 8) + 1;
      local_c = (char *)sqlite3Malloc(local_20 + 1 + local_18);
      if (local_c == (char *)0x0) {
        iVar4 = 7;
      }
      else {
        local_10 = (byte *)(local_c + local_20 + 1);
        iVar4 = (**(code **)(*_Dst + 8))(_Dst,local_c,local_20,0,0);
        if (iVar4 == 0) {
          local_c[local_20] = '\0';
          if ((-1 < local_1c) && ((pcVar9 = local_c, 0 < local_1c || (local_20 != 0)))) {
            do {
              iVar4 = (**(code **)(iVar3 + 0x20))(iVar3,pcVar9,0,&local_14);
              if (iVar4 != 0) goto LAB_0048471d;
              if (local_14 != 0) {
                iVar4 = (**(code **)(iVar3 + 0x18))(iVar3,pcVar9,local_8,0x801,0);
                if (iVar4 != 0) goto LAB_0048471d;
                iVar4 = pager_readMasterJournal(local_8,local_10,local_18);
                if (*local_8 != 0) {
                  (**(code **)(*local_8 + 4))(local_8);
                  *local_8 = 0;
                }
                if (iVar4 != 0) goto LAB_0048471d;
                pbVar5 = local_10;
                pbVar8 = param_2;
                if (*local_10 != 0) {
                  do {
                    bVar1 = *pbVar5;
                    bVar10 = bVar1 < *pbVar8;
                    if (bVar1 != *pbVar8) {
LAB_004846c1:
                      uVar6 = -(uint)bVar10 | 1;
                      goto LAB_004846c6;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar5[1];
                    bVar10 = bVar1 < pbVar8[1];
                    if (bVar1 != pbVar8[1]) goto LAB_004846c1;
                    pbVar5 = pbVar5 + 2;
                    pbVar8 = pbVar8 + 2;
                  } while (bVar1 != 0);
                  uVar6 = 0;
LAB_004846c6:
                  if (uVar6 == 0) goto LAB_0048471d;
                }
              }
              uVar6 = 0;
              if (pcVar9 != (char *)0x0) {
                cVar2 = *pcVar9;
                pcVar7 = pcVar9;
                while (cVar2 != '\0') {
                  pcVar7 = pcVar7 + 1;
                  cVar2 = *pcVar7;
                }
                uVar6 = (int)pcVar7 - (int)pcVar9 & 0x3fffffff;
              }
              pcVar9 = pcVar9 + uVar6 + 1;
              iVar4 = (int)pcVar9 - (int)local_c >> 0x1f;
            } while ((iVar4 < local_1c) ||
                    ((iVar4 <= local_1c && ((uint)((int)pcVar9 - (int)local_c) < local_20))));
          }
          sqlite3OsClose(_Dst);
          iVar4 = (**(code **)(iVar3 + 0x1c))(iVar3,param_2,0);
        }
      }
    }
  }
LAB_0048471d:
  sqlite3_free((int)local_c);
  if (_Dst != (int *)0x0) {
    if (*_Dst != 0) {
      (**(code **)(*_Dst + 4))(_Dst);
      *_Dst = 0;
    }
    sqlite3_free((int)_Dst);
  }
  return iVar4;
}




/* [AUDIT] proposed: pager_endTransaction  (confidence: med)
 * purpose: Finalizes/closes journal, releases savepoints, unlocks or resets to read state; SQLite pager_end_transaction
 * vars: param_1[0x10] journal; +0xf eState
 */
/* Global::pager_endTransaction @ 00484760 */

int __cdecl pager_endTransaction(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  if ((*(byte *)((int)param_1 + 0xf) < 2) && (*(byte *)(param_1 + 4) < 2)) {
    return 0;
  }
  pager_freeSavepointArray((int)param_1);
  piVar2 = (int *)param_1[0x10];
  if ((undefined *)*piVar2 != (undefined *)0x0) {
    if ((undefined *)*piVar2 == &DAT_00569a48) {
      memjrnlClose((undefined8 *)piVar2);
      *piVar2 = 0;
    }
    else {
      cVar1 = *(char *)((int)param_1 + 5);
      if (cVar1 == '\x03') {
        if (param_1[0x12] == 0 && param_1[0x13] == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = (**(code **)(*piVar2 + 0x10))(piVar2,0,0);
        }
      }
      else {
        if ((cVar1 != '\x01') && (((char)param_1[1] == '\0' || (cVar1 == '\x05')))) {
          iVar3 = param_1[3];
          sqlite3OsClose(piVar2);
          if ((char)iVar3 == '\0') {
            iVar5 = (**(code **)(*param_1 + 0x1c))(*param_1,param_1[0x25],0);
          }
          goto LAB_00484835;
        }
        iVar5 = pagerWalSyncTruncate((int)param_1,param_2);
      }
      param_1[0x13] = 0;
      param_1[0x12] = 0;
    }
  }
LAB_00484835:
  bitvec_destroy(param_1[0xe]);
  param_1[0xe] = 0;
  param_1[0xb] = 0;
  pagerReleaseAllSavepoints_flush((undefined4 *)param_1[0x2d]);
  pcacheTruncate((undefined4 *)param_1[0x2d],param_1[6]);
  iVar3 = param_1[0x2e];
  if ((iVar3 != 0) && (*(char *)(iVar3 + 0x2c) != '\0')) {
    if (*(char *)(iVar3 + 0x2b) == '\0') {
      (**(code **)(**(int **)(iVar3 + 4) + 0x38))(*(int **)(iVar3 + 4),0,1,9);
    }
    *(undefined1 *)(iVar3 + 0x2c) = 0;
    *(undefined1 *)(iVar3 + 0x2f) = 0;
  }
  local_8 = 0;
  if ((char)param_1[1] != '\0') goto LAB_00484915;
  iVar3 = param_1[0x2e];
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 0x2b) == '\0') goto LAB_00484915;
    *(undefined1 *)(iVar3 + 0x2b) = 0;
    iVar4 = (**(code **)(**(int **)(iVar3 + 4) + 0x38))
                      (*(int **)(iVar3 + 4),*(short *)(iVar3 + 0x28) + 3,1,6);
    if (iVar4 != 0) {
      *(undefined1 *)(iVar3 + 0x2b) = 1;
    }
    if (*(char *)(iVar3 + 0x2b) != '\0') goto LAB_00484915;
  }
  piVar2 = (int *)param_1[0xf];
  local_8 = 0;
  if ((*piVar2 != 0) &&
     (local_8 = (**(code **)(*piVar2 + 0x20))(piVar2,1), (char)param_1[4] != '\x05')) {
    *(undefined1 *)(param_1 + 4) = 1;
  }
  *(undefined1 *)((int)param_1 + 0x11) = 0;
LAB_00484915:
  if (iVar5 == 0) {
    iVar5 = local_8;
  }
  *(undefined1 *)((int)param_1 + 0xf) = 1;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  return iVar5;
}




/* [AUDIT] proposed: pager_error  (confidence: high)
 * purpose: Records IOERR/CORRUPT/FULL error code, sets pager to ERROR state (0xf=6); SQLite pager_error
 * vars: param_1+0x28 errCode; +0xf eState
 */
/* Global::pager_error @ 00484930 */

uint __cdecl pager_error(int param_1,uint param_2)

{
  if (((param_2 & 0xff) == 0xd) || ((param_2 & 0xff) == 10)) {
    *(uint *)(param_1 + 0x28) = param_2;
    *(undefined1 *)(param_1 + 0xf) = 6;
  }
  return param_2;
}




/* [AUDIT] proposed: pager_incrChangeCounter  (confidence: med)
 * purpose: Increments file change counter on page1, syncing/writing via 4876e0; SQLite pager_incr_changecounter
 * vars: param_2 page1 aData
 */
/* Global::pager_incrChangeCounter @ 00484960 */

uint __cdecl pager_incrChangeCounter(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar2 = param_1;
  if ((*(char *)((int)param_1 + 0x11) != '\0') || (param_1[6] == 0)) {
    return 0;
  }
  uVar4 = param_1[10];
  if (uVar4 == 0) {
    uVar4 = sqlite3PcacheFetch((int *)param_1[0x2d],1,1,&param_1);
  }
  puVar5 = param_1;
  iVar3 = DAT_00582bb8;
  if (uVar4 == 0) {
    if (param_1[4] != 0) {
      puVar2[0x28] = puVar2[0x28] + 1;
      goto LAB_00484a78;
    }
    param_1[4] = (uint)puVar2;
    if (iVar3 / (int)puVar2[0x20] == 0) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      uVar4 = 0xb;
    }
    else if (((*(char *)((int)puVar2 + 0xe) == '\0') && (puVar2[6] != 0)) &&
            (*(int *)puVar2[0xf] != 0)) {
      puVar2[0x29] = puVar2[0x29] + 1;
      uVar4 = pager_readDbPage((int)param_1);
      if (uVar4 == 0) goto LAB_00484a78;
    }
    else {
      if (puVar2[0x21] != 0) {
        memset((void *)param_1[1],0,puVar2[0x20]);
        goto LAB_00484a78;
      }
      uVar4 = 0xd;
    }
    if ((puVar5[6] & 2) != 0) {
      pcache_removeFromDirty((int)puVar5);
    }
    uVar1 = puVar5[7];
    *(int *)(uVar1 + 0xc) = *(int *)(uVar1 + 0xc) + -1;
    if (puVar5[5] == 1) {
      *(undefined4 *)(uVar1 + 0x2c) = 0;
    }
    (*DAT_00582b4c)(*(undefined4 *)(uVar1 + 0x28),*puVar5,1);
  }
  if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
    pcache_releasePage(puVar2);
  }
  puVar5 = (uint *)0x0;
  if (uVar4 != 0) {
    return uVar4;
  }
LAB_00484a78:
  uVar4 = pagerPlaybackSavepoint(puVar5);
  if (uVar4 == 0) {
    pager_writeChangeCounter((int)puVar5);
    *(undefined1 *)((int)puVar2 + 0x11) = 1;
  }
  if (puVar5 != (uint *)0x0) {
    puVar2 = (uint *)puVar5[4];
    sqlite3PcacheRelease(puVar5);
    if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar2);
    }
  }
  return uVar4;
}




/* [AUDIT] proposed: pager_getSavepointPtr  (confidence: high)
 * purpose: Looks up savepoint/bitvec entry for page (4a37e0) and returns it; SQLite thin helper
 * vars: local_8=out; param_1+0xb4 pPager
 */
/* Global::pager_getSavepointPtr @ 00484ae0 */

undefined4 __cdecl pager_getSavepointPtr(int param_1,int param_2)

{
  undefined4 local_8;
  
  sqlite3PcacheFetch(*(int **)(param_1 + 0xb4),param_2,0,&local_8);
  return local_8;
}




/* [AUDIT] proposed: pager_openJournal  (confidence: med)
 * purpose: Begins write transaction: allocates in-journal bitvec (0x200), opens journal file, writes header; SQLite pager_open_journal
 * vars: param_1[0xe] bitvec; +5 journalMode
 */
/* Global::pager_openJournal @ 00484b10 */

int __cdecl pager_openJournal(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  iVar4 = param_1[10];
  if (iVar4 == 0) {
    if ((param_1[0x2e] == 0) && (*(char *)((int)param_1 + 5) != '\x02')) {
      iVar4 = param_1[6];
      piVar1 = (int *)sqlite3Malloc(0x200);
      if (piVar1 != (int *)0x0) {
        memset(piVar1,0,0x200);
        *piVar1 = iVar4;
      }
      param_1[0xe] = (int)piVar1;
      if (piVar1 == (int *)0x0) {
        return 7;
      }
      piVar1 = (int *)param_1[0x10];
      if (*piVar1 == 0) {
        if (*(char *)((int)param_1 + 5) == '\x04') {
          StrAccumInit_or_ctor((undefined8 *)piVar1);
        }
        else {
          uVar2 = 0x800;
          if ((char)param_1[3] != '\0') {
            uVar2 = 0x1008;
          }
          iVar3 = (**(code **)(iVar3 + 0x18))(iVar3,param_1[0x25],piVar1,uVar2 | 6,0);
          if (iVar3 != 0) goto LAB_00484bfe;
        }
      }
      param_1[0xb] = 0;
      param_1[0x12] = 0;
      param_1[0x13] = 0;
      *(undefined1 *)((int)param_1 + 0x12) = 0;
      param_1[0x14] = 0;
      param_1[0x15] = 0;
      iVar3 = pagerWriteWalHeader((uint)param_1);
      if (iVar3 != 0) {
LAB_00484bfe:
        bitvec_destroy(param_1[0xe]);
        param_1[0xe] = 0;
        return iVar3;
      }
    }
    iVar4 = 0;
    *(undefined1 *)((int)param_1 + 0xf) = 3;
  }
  return iVar4;
}




/* [AUDIT] proposed: pager_playback  (confidence: med)
 * purpose: Full journal playback loop: reads super-journal name, page records, checksums, replays each; SQLite pager_playback
 * vars: local_20 nRec; local_8 cksum
 */
/* Global::pager_playback @ 00484c20 */

uint __cdecl pager_playback(uint *param_1,int param_2)

{
  char *pcVar1;
  byte *pbVar2;
  int *piVar3;
  code *pcVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined8 uVar9;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  puVar5 = param_1;
  local_c = 1;
  puVar8 = param_1 + 0x10;
  local_8 = 0;
  param_1 = (uint *)*param_1;
  uVar6 = (**(code **)(*(int *)*puVar8 + 0x18))((int *)*puVar8,&local_20);
  if (uVar6 == 0) {
    pcVar1 = (char *)puVar5[0x2c];
    uVar6 = pager_readMasterJournal((int *)puVar5[0x10],pcVar1,*(int *)(*puVar5 + 8) + 1);
    if ((uVar6 == 0) &&
       (((*pcVar1 == '\0' || (uVar6 = (*(code *)param_1[8])(param_1,pcVar1,0,&local_c), uVar6 == 0))
        && (local_c != 0)))) {
      puVar5[0x12] = 0;
      puVar5[0x13] = 0;
      local_14 = param_2;
      uVar6 = pager_readJournalHeader((int)puVar5,param_2,local_20,local_1c,(uint *)&param_1,&local_8);
      uVar7 = local_1c;
      while (uVar6 == 0) {
        local_1c = uVar7;
        if (param_1 == (uint *)0xffffffff) {
          uVar9 = __alldiv(local_20 - puVar5[0x1f],uVar7 - (local_20 < puVar5[0x1f]),
                           puVar5[0x20] + 8,(int)(puVar5[0x20] + 8) >> 0x1f);
          param_1 = (uint *)uVar9;
        }
        if ((param_1 == (uint *)0x0) && (param_2 == 0)) {
          local_10 = puVar5[0x12];
          local_18 = puVar5[0x13];
          if ((puVar5[0x1f] + puVar5[0x14] == local_10) &&
             (puVar5[0x15] + (uint)CARRY4(puVar5[0x1f],puVar5[0x14]) == local_18)) {
            uVar9 = __alldiv(local_20 - local_10,(uVar7 - local_18) - (uint)(local_20 < local_10),
                             puVar5[0x20] + 8,(int)(puVar5[0x20] + 8) >> 0x1f);
            param_1 = (uint *)uVar9;
          }
        }
        uVar7 = local_8;
        if ((puVar5[0x12] == puVar5[0x1f]) && (puVar5[0x13] == 0)) {
          uVar6 = pager_truncateImage((int)puVar5,local_8);
          if (uVar6 != 0) goto LAB_00484e14;
          puVar5[6] = uVar7;
        }
        puVar8 = (uint *)0x0;
        if (param_1 != (uint *)0x0) {
          do {
            if (local_14 != 0) {
              for (uVar6 = puVar5[0x16]; uVar6 != 0; uVar6 = *(uint *)(uVar6 + 0x2c)) {
                *(undefined4 *)(uVar6 + 0x10) = 1;
              }
              pcacheTruncate((undefined4 *)puVar5[0x2d],0);
              local_14 = 0;
            }
            uVar6 = pager_playbackOnePageJournal(puVar5,puVar5 + 0x12,(uint *)0x0,1,0);
            if (uVar6 != 0) {
              if (uVar6 != 0x65) {
                if (uVar6 == 0x20a) {
                  uVar6 = 0;
                }
                goto LAB_00484e14;
              }
              puVar5[0x12] = local_20;
              puVar5[0x13] = local_1c;
              break;
            }
            puVar8 = (uint *)((int)puVar8 + 1);
          } while (puVar8 < param_1);
        }
        uVar6 = pager_readJournalHeader((int)puVar5,param_2,local_20,local_1c,(uint *)&param_1,&local_8);
        uVar7 = local_1c;
      }
      if (uVar6 == 0x65) {
        uVar6 = 0;
      }
    }
  }
LAB_00484e14:
  *(char *)((int)puVar5 + 0x11) = (char)puVar5[3];
  if (uVar6 == 0) {
    pbVar2 = (byte *)puVar5[0x2c];
    uVar6 = pager_readMasterJournal((int *)puVar5[0x10],pbVar2,*(int *)(*puVar5 + 8) + 1);
    if (uVar6 == 0) {
      if ((3 < *(byte *)((int)puVar5 + 0xf)) || (*(byte *)((int)puVar5 + 0xf) == 0)) {
        uVar6 = 0;
        if (*(char *)((int)puVar5 + 7) == '\0') {
          uVar6 = (**(code **)(*(int *)puVar5[0xf] + 0x14))
                            ((int *)puVar5[0xf],*(undefined1 *)((int)puVar5 + 0xb));
        }
        else {
          piVar3 = (int *)puVar5[0xf];
          if ((*piVar3 != 0) && (uVar6 = (**(code **)(*piVar3 + 0x28))(piVar3,8,0), uVar6 == 0xc)) {
            uVar6 = 0;
          }
        }
        if (uVar6 != 0) goto LAB_00484ee2;
      }
      uVar6 = pager_endTransaction((int *)puVar5,(uint)(*pbVar2 != 0));
      if (((uVar6 == 0) && (*pbVar2 != 0)) && (local_c != 0)) {
        uVar6 = pager_deleteMasterJournal((int *)puVar5,pbVar2);
      }
    }
  }
LAB_00484ee2:
  if (((char)puVar5[3] != '\0') ||
     (uVar7 = (**(code **)(*(int *)puVar5[0xf] + 0x30))((int *)puVar5[0xf]), (uVar7 & 0x1000) != 0))
  {
    puVar5[0x1f] = 0x200;
    return uVar6;
  }
  pcVar4 = *(code **)(*(int *)puVar5[0xf] + 0x2c);
  if (pcVar4 == (code *)0x0) {
    puVar5[0x1f] = 0x1000;
    return uVar6;
  }
  uVar7 = (*pcVar4)((int *)puVar5[0xf]);
  if ((int)uVar7 < 0x20) {
    puVar5[0x1f] = 0x200;
    return uVar6;
  }
  if (0x10000 < (int)uVar7) {
    uVar7 = 0x10000;
  }
  puVar5[0x1f] = uVar7;
  return uVar6;
}




/* [AUDIT] proposed: pager_playbackOnePageJournal  (confidence: med)
 * purpose: Reads one page record (pgno+data+cksum) from journal and writes it to DB/page cache; SQLite pager_playback_one_page
 * vars: puVar7=pgno(BE); param_4=isMainJrnl
 */
/* Global::pager_playbackOnePageJournal @ 00484f60 */

uint __cdecl pager_playbackOnePageJournal(undefined4 *param_1,uint *param_2,uint *param_3,int param_4,int param_5)

{
  void *_Dst;
  undefined4 *puVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined3 extraout_var;
  int *piVar6;
  undefined4 *puVar7;
  longlong lVar8;
  uint local_c;
  void *local_8;
  
  puVar2 = param_2;
  puVar1 = param_1;
  local_8 = (void *)param_1[0x2c];
  if (param_4 == 0) {
    piVar6 = (int *)param_1[0x11];
  }
  else {
    piVar6 = (int *)param_1[0x10];
  }
  uVar4 = (**(code **)(*piVar6 + 8))(piVar6,&local_c,4,*param_2,param_2[1]);
  if (uVar4 != 0) {
    return uVar4;
  }
  puVar7 = (undefined4 *)
           ((((local_c & 0xff) << 8 | local_c >> 8 & 0xff) << 8 | local_c >> 0x10 & 0xff) << 8 |
           local_c >> 0x18);
  uVar4 = (**(code **)(*piVar6 + 8))(piVar6,local_8,puVar1[0x20],*puVar2 + 4);
  if (uVar4 != 0) {
    return uVar4;
  }
  uVar5 = puVar1[0x20] + param_4 * 4 + 4;
  uVar4 = *param_2;
  *param_2 = *param_2 + uVar5;
  param_2[1] = param_2[1] + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar4,uVar5);
  if ((puVar7 == (undefined4 *)0x0) ||
     (puVar7 == (undefined4 *)(DAT_00582bb8 / (int)puVar1[0x20] + 1))) {
    return 0x65;
  }
  if (((undefined4 *)puVar1[6] < puVar7) ||
     (bVar3 = bitvec_test(param_3,(uint)puVar7), CONCAT31(extraout_var,bVar3) != 0)) {
    return 0;
  }
  if (param_4 != 0) {
    uVar4 = pager_read32be(piVar6,*param_2 - 4,param_2[1] - (uint)(*param_2 < 4),&local_c);
    if (uVar4 != 0) {
      return uVar4;
    }
    if ((param_5 == 0) && (uVar4 = pager_cksum((int)puVar1,(int)local_8), uVar4 != local_c)) {
      return 0x65;
    }
  }
  if ((param_3 != (uint *)0x0) && (uVar4 = bitvec_set(param_3,(uint)puVar7), uVar4 != 0)) {
    return uVar4;
  }
  uVar4 = 0;
  if ((puVar7 == (undefined4 *)0x1) &&
     (*(ushort *)((int)puVar1 + 0x76) != (ushort)*(byte *)((int)local_8 + 0x14))) {
    *(ushort *)((int)puVar1 + 0x76) = (ushort)*(byte *)((int)local_8 + 0x14);
  }
  if (puVar1[0x2e] == 0) {
    param_1 = (undefined4 *)pager_getSavepointPtr((int)puVar1,(int)puVar7);
  }
  else {
    param_1 = (undefined4 *)0x0;
  }
  if (param_4 == 0) {
    if ((param_1 == (undefined4 *)0x0) || ((*(byte *)(param_1 + 6) & 4) == 0)) goto LAB_00485100;
LAB_0048516e:
    bVar3 = false;
  }
  else {
    if (*(char *)((int)puVar1 + 7) == '\0') {
      if (((int)puVar1[0x15] <= (int)param_2[1]) &&
         (((int)puVar1[0x15] < (int)param_2[1] || ((uint)puVar1[0x14] < *param_2))))
      goto LAB_0048516e;
    }
LAB_00485100:
    bVar3 = true;
  }
  if ((*(int *)puVar1[0xf] == 0) ||
     (((*(byte *)((int)puVar1 + 0xf) < 4 && (*(byte *)((int)puVar1 + 0xf) != 0)) || (!bVar3)))) {
    if (param_4 != 0) goto LAB_004851b6;
    if (param_1 == (undefined4 *)0x0) {
      *(char *)((int)puVar1 + 0x13) = *(char *)((int)puVar1 + 0x13) + '\x01';
      uVar4 = getAndInitPage((int)puVar1,(uint)puVar7,(int *)&param_1,1);
      *(char *)((int)puVar1 + 0x13) = *(char *)((int)puVar1 + 0x13) + -1;
      if (uVar4 != 0) {
        return uVar4;
      }
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff7;
      pcacheManageDirtyList_add((int)param_1);
      uVar4 = 0;
      goto LAB_004851b6;
    }
  }
  else {
    uVar4 = puVar1[0x20];
    lVar8 = __allmul((int)puVar7 - 1,0,uVar4,(int)uVar4 >> 0x1f);
    uVar4 = sqlite3OsWrite((int *)puVar1[0xf],local_8,uVar4,(int)lVar8,(int)((ulonglong)lVar8 >> 0x20)
                        );
    if ((undefined4 *)puVar1[8] < puVar7) {
      puVar1[8] = puVar7;
    }
    if ((int *)puVar1[0x16] != (int *)0x0) {
      btree_writeOverflowCursors((int *)puVar1[0x16],puVar7,(int)local_8);
    }
LAB_004851b6:
    if (param_1 == (undefined4 *)0x0) {
      return uVar4;
    }
  }
  _Dst = (void *)param_1[1];
  memcpy(_Dst,local_8,puVar1[0x20]);
  (*(code *)puVar1[0x2b])(param_1);
  if (param_4 != 0) {
    if (param_5 != 0) {
      if (((int)puVar1[0x15] < (int)param_2[1]) ||
         (((int)puVar1[0x15] <= (int)param_2[1] && ((uint)puVar1[0x14] < *param_2))))
      goto LAB_00485208;
    }
    pcacheMakeClean(param_1);
  }
LAB_00485208:
  if (puVar7 == (undefined4 *)0x1) {
    *(undefined8 *)(puVar1 + 0x19) = *(undefined8 *)((int)_Dst + 0x18);
    *(undefined8 *)(puVar1 + 0x1b) = *(undefined8 *)((int)_Dst + 0x20);
  }
  sqlite3PcacheRelease(param_1);
  return uVar4;
}




/* [AUDIT] proposed: btree_invalidateAllCursors  (confidence: high)
 * purpose: Marks all shared-cache cursors invalid and rolls back backend (4a3b00); SQLite invalidateAllOverflowCache
 * vars: param_1+0x58 cursor list
 */
/* Global::btree_invalidateAllCursors @ 00485250 */

void __cdecl btree_invalidateAllCursors(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x58); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  pcacheTruncate(*(undefined4 **)(param_1 + 0xb4),0);
  return;
}




/* [AUDIT] proposed: pager_truncateImage  (confidence: med)
 * purpose: Truncates DB image to param_2 pages via VFS xTruncate/zero-fill; SQLite pager_truncate
 * vars: param_1+0x80 pageSize; +0x20 dbSize
 */
/* Global::pager_truncateImage @ 00485280 */


int __cdecl pager_truncateImage(int param_1,uint param_2)

{
  int *piVar1;
  uint _Size;
  void *_Dst;
  int iVar2;
  longlong lVar3;
  uint local_20;
  int local_1c;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if ((*piVar1 == 0) || ((*(byte *)(param_1 + 0xf) < 4 && (*(byte *)(param_1 + 0xf) != 0)))) {
    return 0;
  }
  _Size = *(uint *)(param_1 + 0x80);
  iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1);
  lVar3 = __allmul(param_2,0,_Size,(int)_Size >> 0x1f);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (lVar3 == CONCAT44(local_1c,local_20)) {
    return 0;
  }
  if (lVar3 < CONCAT44(local_1c,local_20)) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x10))(*(int **)(param_1 + 0x3c),lVar3);
  }
  else {
    if (lVar3 < CONCAT44(((int)_Size >> 0x1f) + local_1c + (uint)CARRY4(_Size,local_20),
                         _Size + local_20)) goto LAB_00485367;
    _Dst = *(void **)(param_1 + 0xb0);
    memset(_Dst,0,_Size);
    iVar2 = sqlite3OsWrite(*(int **)(param_1 + 0x3c),_Dst,_Size,(int)(lVar3 - (int)_Size),
                         (int)((ulonglong)(lVar3 - (int)_Size) >> 0x20));
  }
  if (iVar2 != 0) {
    return iVar2;
  }
LAB_00485367:
  *(uint *)(param_1 + 0x20) = param_2;
  return 0;
}




/* [AUDIT] proposed: pcache_freePage  (confidence: high)
 * purpose: Destroys a PgHdr page object: frees savepoints (487f30), releases file page, frees memory; SQLite pcacheFree/destroy
 * vars: param_1+0xb8 pWal; +0x3c fd
 */
/* Global::pcache_freePage @ 00485380 */

void __cdecl pcache_freePage(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  bitvec_destroy(*(int *)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x38) = 0;
  pager_freeSavepointArray(param_1);
  if (*(int *)(param_1 + 0xb8) == 0) {
    if (*(char *)(param_1 + 4) != '\0') goto LAB_00485430;
    piVar1 = *(int **)(param_1 + 0x3c);
    if (*piVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1);
    }
    if (((uVar2 & 0x800) == 0) || ((*(byte *)(param_1 + 5) & 5) != 1)) {
      piVar1 = *(int **)(param_1 + 0x40);
      if (*piVar1 != 0) {
        (**(code **)(*piVar1 + 4))(piVar1);
        *piVar1 = 0;
      }
    }
    piVar1 = *(int **)(param_1 + 0x3c);
    if (*piVar1 != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x20))(piVar1,0);
      if (*(char *)(param_1 + 0x10) != '\x05') {
        *(undefined1 *)(param_1 + 0x10) = 0;
      }
      if ((iVar3 != 0) && (*(char *)(param_1 + 0xf) == '\x06')) {
        *(undefined1 *)(param_1 + 0x10) = 5;
      }
    }
    *(undefined1 *)(param_1 + 0x11) = 0;
  }
  else {
    walIteratorFree_or_restart(*(int *)(param_1 + 0xb8));
  }
  *(undefined1 *)(param_1 + 0xf) = 0;
LAB_00485430:
  if (*(int *)(param_1 + 0x28) != 0) {
    for (iVar3 = *(int *)(param_1 + 0x58); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x2c)) {
      *(undefined4 *)(iVar3 + 0x10) = 1;
    }
    pcacheTruncate(*(undefined4 **)(param_1 + 0xb4),0);
    *(undefined1 *)(param_1 + 0x11) = *(undefined1 *)(param_1 + 0xc);
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}




/* [AUDIT] proposed: pager_lockWithRetry  (confidence: high)
 * purpose: Acquires DB lock retrying on BUSY(5) via busy handler (+0x98); SQLite pagerLockDb w/ retry
 * vars: param_2=level; +0x98 xBusy
 */
/* Global::pager_lockWithRetry @ 004854a0 */

int __cdecl pager_lockWithRetry(int param_1,int param_2)

{
  int iVar1;
  
  while( true ) {
    if ((param_2 <= (int)(uint)*(byte *)(param_1 + 0x10)) && (*(byte *)(param_1 + 0x10) != 5)) {
      return 0;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x1c))(*(int **)(param_1 + 0x3c),param_2);
    if (iVar1 == 0) {
      if ((*(char *)(param_1 + 0x10) != '\x05') || (param_2 == 4)) {
        *(char *)(param_1 + 0x10) = (char)param_2;
      }
      return 0;
    }
    if (iVar1 != 5) break;
    iVar1 = (**(code **)(param_1 + 0x98))(*(undefined4 *)(param_1 + 0x9c));
    if (iVar1 == 0) {
      return 5;
    }
  }
  return iVar1;
}




/* [AUDIT] proposed: pager_writePage  (confidence: med)
 * purpose: Writes a page to journal then marks dirty/writes to DB, updates savepoint bitvecs; SQLite pager_write
 * vars: param_1+0x14 pgno; piVar1=pPager
 */
/* Global::pager_writePage @ 00485520 */

uint __cdecl pager_writePage(int param_1)

{
  int *piVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 0x10);
  uVar4 = piVar1[10];
  if (uVar4 == 0) {
    if (*(char *)((int)piVar1 + 0xd) != '\0') {
      return 3;
    }
    uVar4 = 0;
    if ((*(char *)((int)piVar1 + 0xf) != '\x02') || (uVar4 = pager_openJournal(piVar1), uVar4 == 0)) {
      pcacheManageDirtyList_add(param_1);
      puVar2 = *(uint **)(*(int *)(param_1 + 0x10) + 0x38);
      bVar3 = bitvec_test(puVar2,*(uint *)(param_1 + 0x14));
      if ((CONCAT31(extraout_var,bVar3) == 0) || (iVar5 = walDirtyPagesPresent_or_bitTest(param_1), iVar5 != 0)) {
        bVar3 = bitvec_test(puVar2,*(uint *)(param_1 + 0x14));
        if ((CONCAT31(extraout_var_00,bVar3) == 0) && (piVar1[0x2e] == 0)) {
          if (((uint)piVar1[7] < *(uint *)(param_1 + 0x14)) || (*(int *)piVar1[0x10] == 0)) {
            if (*(char *)((int)piVar1 + 0xf) != '\x04') {
              *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 4;
            }
          }
          else {
            iVar5 = piVar1[0x13];
            uVar4 = piVar1[0x12];
            iVar6 = pager_cksum((int)piVar1,iVar9);
            *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 4;
            uVar7 = writeBigEndianToFile((int *)piVar1[0x10],uVar4,iVar5,*(undefined4 *)(param_1 + 0x14));
            if (uVar7 != 0) {
              return uVar7;
            }
            uVar7 = sqlite3OsWrite((int *)piVar1[0x10],iVar9,piVar1[0x20],uVar4 + 4,
                                 iVar5 + (uint)(0xfffffffb < uVar4));
            if (uVar7 != 0) {
              return uVar7;
            }
            uVar7 = piVar1[0x20];
            uVar4 = writeBigEndianToFile((int *)piVar1[0x10],uVar7 + uVar4 + 4,
                                 ((int)uVar7 >> 0x1f) + iVar5 + (uint)CARRY4(uVar7,uVar4) +
                                 (uint)(0xfffffffb < uVar7 + uVar4),iVar6);
            if (uVar4 != 0) {
              return uVar4;
            }
            uVar7 = piVar1[0x20] + 8;
            puVar2 = (uint *)(piVar1 + 0x12);
            uVar4 = *puVar2;
            *puVar2 = *puVar2 + uVar7;
            piVar1[0x13] = piVar1[0x13] + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar4,uVar7);
            piVar1[0xb] = piVar1[0xb] + 1;
            uVar7 = bitvec_set((uint *)piVar1[0xe],*(uint *)(param_1 + 0x14));
            uVar8 = pager_setInAllSavepoints((int)piVar1,*(uint *)(param_1 + 0x14));
            uVar4 = 0;
            if ((uVar7 | uVar8) != 0) {
              return uVar7 | uVar8;
            }
          }
        }
        iVar9 = walDirtyPagesPresent_or_bitTest(param_1);
        if (iVar9 != 0) {
          uVar4 = subjournalPage(param_1);
        }
      }
      if ((uint)piVar1[6] < *(uint *)(param_1 + 0x14)) {
        piVar1[6] = *(uint *)(param_1 + 0x14);
      }
    }
  }
  return uVar4;
}




/* [AUDIT] proposed: pager_writeChangeCounter  (confidence: high)
 * purpose: Writes incremented change counter and version into page1 header fields; SQLite write32bits changecounter
 * vars: iVar2 page1 aData; +0x18..0x1b counter
 */
/* Global::pager_writeChangeCounter @ 004856d0 */

void __cdecl pager_writeChangeCounter(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 uVar6;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 4);
  iVar5 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 100),*(undefined1 *)(iVar1 + 0x65)),
                            *(undefined1 *)(iVar1 + 0x66)),*(undefined1 *)(iVar1 + 0x67)) + 1;
  uVar6 = (undefined1)((uint)iVar5 >> 0x18);
  *(undefined1 *)(iVar2 + 0x18) = uVar6;
  *(char *)(iVar2 + 0x1b) = (char)iVar5;
  uVar4 = (undefined1)((uint)iVar5 >> 0x10);
  *(undefined1 *)(iVar2 + 0x19) = uVar4;
  uVar3 = (undefined1)((uint)iVar5 >> 8);
  *(undefined1 *)(iVar2 + 0x1a) = uVar3;
  iVar1 = *(int *)(param_1 + 4);
  *(undefined1 *)(iVar1 + 0x5e) = uVar3;
  *(undefined1 *)(iVar1 + 0x5c) = uVar6;
  *(undefined1 *)(iVar1 + 0x5d) = uVar4;
  *(char *)(iVar1 + 0x5f) = (char)iVar5;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x60) = 0x27e22d00;
  return;
}




/* [AUDIT] proposed: pager_commitPhaseOne  (confidence: med)
 * purpose: Opens/writes journal and flushes all dirty pages, syncing before commit; SQLite commit phase one
 * vars: param_1[0xf] fd; param_2 dirty list
 */
/* Global::pager_commitPhaseOne @ 00485750 */

int __cdecl pager_commitPhaseOne(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_10;
  int local_8;
  
  local_8 = 0;
  if ((*(int *)param_1[0xf] != 0) ||
     (local_8 = (**(code **)(*param_1 + 0x18))
                          (*param_1,0,(int *)param_1[0xf],param_1[0x1e] & 0x87f7fU | 0x1e,0),
     local_8 == 0)) {
    iVar2 = local_8;
    if ((uint)param_1[9] < (uint)param_1[6]) {
      local_10 = __allmul(param_1[0x20],param_1[0x20] >> 0x1f,param_1[6],0);
      (**(code **)(*(int *)param_1[0xf] + 0x28))((int *)param_1[0xf],5,&local_10);
      param_1[9] = param_1[6];
    }
    do {
      if (param_2 == 0) {
        return iVar2;
      }
      puVar1 = *(undefined4 **)(param_2 + 0x14);
      if ((puVar1 <= (undefined4 *)param_1[6]) && ((*(byte *)(param_2 + 0x18) & 0x20) == 0)) {
        lVar3 = __allmul((int)puVar1 - 1,0,param_1[0x20],param_1[0x20] >> 0x1f);
        local_8 = (int)lVar3;
        if (puVar1 == (undefined4 *)0x1) {
          pager_writeChangeCounter(param_2);
        }
        local_10 = CONCAT44(*(undefined4 *)(param_2 + 4),(undefined4)local_10);
        local_8 = (**(code **)(*(int *)param_1[0xf] + 0xc))
                            ((int *)param_1[0xf],*(undefined4 *)(param_2 + 4),param_1[0x20],local_8,
                             (int)((ulonglong)lVar3 >> 0x20));
        if (puVar1 == (undefined4 *)0x1) {
          *(undefined8 *)(param_1 + 0x19) = *(undefined8 *)(local_10._4_4_ + 0x18);
          *(undefined8 *)(param_1 + 0x1b) = *(undefined8 *)(local_10._4_4_ + 0x20);
        }
        if ((undefined4 *)param_1[8] < puVar1) {
          param_1[8] = (int)puVar1;
        }
        param_1[0x2a] = param_1[0x2a] + 1;
        btree_writeOverflowCursors((int *)param_1[0x16],puVar1,*(int *)(param_2 + 4));
      }
      param_2 = *(int *)(param_2 + 0xc);
      iVar2 = 0;
    } while (local_8 == 0);
  }
  return local_8;
}




/* [AUDIT] proposed: pcache_allocPage  (confidence: high)
 * purpose: Allocates a page buffer from PCache free list or via mallocRaw; SQLite pcache1Alloc
 * vars: DAT_00584220 free list; +0x20 size
 */
/* Global::pcache_allocPage @ 004868a0 */


undefined4 * __cdecl pcache_allocPage(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (DAT_00583e5c < param_1) {
    DAT_00583e5c = param_1;
  }
  _DAT_00583e34 = param_1;
  if (param_1 <= DAT_00584208) {
    if (DAT_0058421c != 0) {
      (*DAT_00582b18)(DAT_0058421c);
    }
    puVar1 = DAT_00584220;
    if (DAT_00584220 != (undefined4 *)0x0) {
      DAT_00584220 = (undefined4 *)*DAT_00584220;
      DAT_00584224 = DAT_00584224 + -1;
      DAT_00584228 = (uint)(DAT_00584224 < DAT_00584210);
      DAT_00583e1c = DAT_00583e1c + 1;
      if (DAT_00583e44 < DAT_00583e1c) {
        DAT_00583e44 = DAT_00583e1c;
      }
    }
    if (DAT_0058421c != 0) {
      (*DAT_00582b20)(DAT_0058421c);
    }
    if (puVar1 != (undefined4 *)0x0) {
      return puVar1;
    }
  }
  puVar1 = (undefined4 *)sqlite3Malloc(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (*DAT_00582af0._4_4_)(puVar1);
    if (DAT_0058421c != 0) {
      (*DAT_00582b18)(DAT_0058421c);
    }
    DAT_00583e20 = DAT_00583e20 + iVar2;
    if (DAT_00583e48 < DAT_00583e20) {
      DAT_00583e48 = DAT_00583e20;
    }
    if (DAT_0058421c != 0) {
      (*DAT_00582b20)(DAT_0058421c);
    }
  }
  return puVar1;
}




/* [AUDIT] proposed: pcache_freePageMem  (confidence: high)
 * purpose: Returns a page buffer to PCache free list or frees via xFree with accounting; SQLite pcache1Free
 * vars: DAT_00584220 free list
 */
/* Global::pcache_freePageMem @ 00486af0 */

int __cdecl pcache_freePageMem(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  if ((param_1 < DAT_00584214) || (DAT_00584218 <= param_1)) {
    iVar1 = (*DAT_00582af0._4_4_)(param_1);
    if (DAT_0058421c != 0) {
      (*DAT_00582b18)(DAT_0058421c);
    }
    DAT_00583e20 = DAT_00583e20 - iVar1;
    if (DAT_00583e48 < DAT_00583e20) {
      DAT_00583e48 = DAT_00583e20;
    }
    if (DAT_0058421c != 0) {
      (*DAT_00582b20)(DAT_0058421c);
    }
    sqlite3_free((int)param_1);
  }
  else {
    if (DAT_0058421c != 0) {
      (*DAT_00582b18)(DAT_0058421c);
    }
    DAT_00583e1c = DAT_00583e1c + -1;
    if (DAT_00583e44 < DAT_00583e1c) {
      DAT_00583e44 = DAT_00583e1c;
    }
    *param_1 = DAT_00584220;
    DAT_00584224 = DAT_00584224 + 1;
    DAT_00584220 = param_1;
    DAT_00584228 = (uint)(DAT_00584224 < DAT_00584210);
    if (DAT_0058421c != 0) {
      (*DAT_00582b20)(DAT_0058421c);
      return 0;
    }
  }
  return iVar1;
}




/* [AUDIT] proposed: pcache_removeFromDirty  (confidence: high)
 * purpose: Unlinks a PgHdr from the dirty page list, fixing head/tail/synced pointers; SQLite pcacheRemoveFromDirtyList
 * vars: param_1+0x20 prev,+0x24 next; +0x1c pCache
 */
/* Global::pcache_removeFromDirty @ 00486ed0 */

void __cdecl pcache_removeFromDirty(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar1[2] == param_1) {
    for (iVar2 = *(int *)(param_1 + 0x24); (iVar2 != 0 && ((*(byte *)(iVar2 + 0x18) & 4) != 0));
        iVar2 = *(int *)(iVar2 + 0x24)) {
    }
    puVar1[2] = iVar2;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    puVar1[1] = *(undefined4 *)(param_1 + 0x24);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24) = *(undefined4 *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    *puVar1 = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}




/* [AUDIT] proposed: btree_readCellPtrByte  (confidence: high)
 * purpose: Reads a cell's leading byte (+optional 4-byte) at page param_2 via getPage (4a14c0); SQLite; 'database corruption'
 * vars: param_3=out byte; param_4=out 4byte
 */
/* Global::btree_readCellPtrByte @ 00486f40 */

int __cdecl btree_readCellPtrByte(int *param_1,undefined4 *param_2,byte *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  
  puVar3 = param_2;
  if (param_2 < (undefined4 *)0x2) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)param_1[9] / 5 + 1;
    iVar6 = (((int)param_2 - 2U) / uVar7) * uVar7;
    uVar7 = iVar6 + 2;
    if (uVar7 == DAT_00582bb8 / (uint)param_1[8] + 1) {
      uVar7 = iVar6 + 3;
    }
  }
  iVar6 = getAndInitPage(*param_1,uVar7,(int *)&param_2,0);
  pbVar5 = param_3;
  puVar4 = param_2;
  if (iVar6 == 0) {
    puVar1 = (undefined4 *)param_2[1];
    iVar6 = ((int)puVar3 + (-1 - uVar7)) * 5;
    if (iVar6 < 0) {
      puVar2 = (uint *)param_2[4];
      param_2 = puVar1;
      sqlite3PcacheRelease(puVar4);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
    }
    else {
      *param_3 = *(byte *)(iVar6 + (int)puVar1);
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 1 + (int)puVar1),
                                              *(undefined1 *)(iVar6 + 2 + (int)puVar1)),
                                     *(undefined1 *)(iVar6 + 3 + (int)puVar1)),
                            *(undefined1 *)(iVar6 + 4 + (int)puVar1));
      }
      puVar2 = (uint *)param_2[4];
      param_2 = puVar1;
      sqlite3PcacheRelease(puVar4);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
      if ((*pbVar5 != 0) && (*pbVar5 < 6)) {
        return 0;
      }
    }
    sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
    iVar6 = 0xb;
  }
  return iVar6;
}




/* [AUDIT] proposed: btree_ptrmapPageno  (confidence: high)
 * purpose: Computes the ptrmap page number that stores an entry for page param_2; SQLite ptrmapPageno
 * vars: param_1+0x24 usableSize; +0x20 pageSize
 */
/* Global::btree_ptrmapPageno @ 00487070 */

int __cdecl btree_ptrmapPageno(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 2) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x24) / 5 + 1;
  iVar2 = ((param_2 - 2) / uVar1) * uVar1;
  iVar3 = iVar2 + 2;
  if (iVar3 == DAT_00582bb8 / *(uint *)(param_1 + 0x20) + 1) {
    iVar3 = iVar2 + 3;
  }
  return iVar3;
}




/* [AUDIT] proposed: btree_ptrmapPut  (confidence: high)
 * purpose: Sets a pointer-map entry (type,parent) for a page, allocating ptrmap page; SQLite ptrmapPut; 'database corruption'
 * vars: param_3=eType; param_4=parent
 */
/* Global::btree_ptrmapPut @ 004870c0 */

void __cdecl btree_ptrmapPut(int *param_1,uint param_2,char param_3,int param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *local_8;
  
  if (*param_5 == 0) {
    if (param_2 == 0) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      *param_5 = 0xb;
      return;
    }
    uVar2 = btree_ptrmapPageno((int)param_1,param_2);
    uVar3 = getAndInitPage(*param_1,uVar2,(int *)&local_8,0);
    if (uVar3 != 0) {
      *param_5 = uVar3;
      return;
    }
    iVar4 = ((param_2 - uVar2) + -1) * 5;
    if (iVar4 < 0) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      *param_5 = 0xb;
    }
    else {
      pcVar5 = (char *)(local_8[1] + iVar4);
      if ((param_3 != *pcVar5) || (iVar4 = sqlite3Get4byte(pcVar5 + 1), iVar4 != param_4)) {
        uVar2 = pagerPlaybackSavepoint(local_8);
        *param_5 = uVar2;
        if (uVar2 == 0) {
          *pcVar5 = param_3;
          sqlite3Put4byte(pcVar5 + 1,param_4);
        }
      }
    }
    if (local_8 != (undefined4 *)0x0) {
      puVar1 = (uint *)local_8[4];
      sqlite3PcacheRelease(local_8);
      if (*(int *)(puVar1[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar1);
      }
    }
  }
  return;
}




/* [AUDIT] proposed: pager_read32be  (confidence: high)
 * purpose: Reads 4 bytes at offset from file (VFS xRead) and returns big-endian uint; SQLite read32bits
 * vars: param_4=out; big-endian assemble
 */
/* Global::pager_read32be @ 00487690 */

int __cdecl pager_read32be(int *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1,&param_1,4,param_2,param_3);
  if (iVar1 == 0) {
    *param_4 = ((((uint)param_1 & 0xff) << 8 | (uint)param_1 >> 8 & 0xff) << 8 |
               (uint)param_1 >> 0x10 & 0xff) << 8 | (uint)param_1 >> 0x18;
  }
  return iVar1;
}




/* [AUDIT] proposed: pager_readDbPage  (confidence: high)
 * purpose: Reads a DB page from file/WAL (xRead) into cache buffer, captures page1 counters; SQLite readDbPage
 * vars: param_1+4 pgno; +0x10 pPager; +0x80 pageSize
 */
/* Global::pager_readDbPage @ 004876e0 */

int __cdecl pager_readDbPage(int param_1)

{
  int iVar1;
  int iVar2;
  size_t _Size;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  iVar3 = param_1;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x10);
  _Size = *(size_t *)(iVar2 + 0x80);
  param_1 = 0;
  if (**(int **)(iVar2 + 0x3c) == 0) {
    memset(*(void **)(iVar3 + 4),0,_Size);
    return 0;
  }
  if (*(int *)(iVar2 + 0xb8) != 0) {
    iVar4 = walFindFrame(*(int *)(iVar2 + 0xb8),iVar1,&param_1,_Size,*(undefined4 *)(iVar3 + 4));
    if ((iVar4 != 0) || (param_1 != 0)) goto LAB_00487787;
  }
  lVar5 = __allmul(iVar1 - 1,0,*(uint *)(iVar2 + 0x80),(int)*(uint *)(iVar2 + 0x80) >> 0x1f);
  iVar4 = (**(code **)(**(int **)(iVar2 + 0x3c) + 8))
                    (*(int **)(iVar2 + 0x3c),*(undefined4 *)(iVar3 + 4),_Size,lVar5);
  if (iVar4 == 0x20a) {
    iVar4 = 0;
  }
LAB_00487787:
  if (iVar1 == 1) {
    if (iVar4 != 0) {
      *(undefined4 *)(iVar2 + 100) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x68) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x6c) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x70) = 0xffffffff;
      return iVar4;
    }
    iVar1 = *(int *)(iVar3 + 4);
    *(undefined8 *)(iVar2 + 100) = *(undefined8 *)(iVar1 + 0x18);
    *(undefined8 *)(iVar2 + 0x6c) = *(undefined8 *)(iVar1 + 0x20);
  }
  return iVar4;
}




/* [AUDIT] proposed: pager_readJournalHeader  (confidence: high)
 * purpose: Reads/validates a journal header (magic), records nRec/pageSize/sectorSize; SQLite readJournalHdr
 * vars: local_10 magic; +0x48/4c offset
 */
/* Global::pager_readJournalHeader @ 004877e0 */

void __cdecl
pager_readJournalHeader(int param_1,int param_2,uint param_3,int param_4,uint *param_5,uint *param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  uint *local_18;
  uint *local_14;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = param_5;
  iVar2 = *(int *)(param_1 + 0x48);
  local_18 = param_6;
  local_10 = 0;
  if (iVar2 == 0 && *(int *)(param_1 + 0x4c) == 0) {
    lVar5 = 0;
    local_10._0_4_ = 0;
    uVar4 = (uint)local_10;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x7c);
    lVar5 = __alldiv(iVar2 - 1,*(int *)(param_1 + 0x4c) - (uint)(iVar2 == 0),uVar4,0);
    lVar5 = __allmul((uint)(lVar5 + 1),(int)((ulonglong)(lVar5 + 1) >> 0x20),uVar4,0);
    uVar4 = (uint)lVar5;
  }
  iVar3 = (int)((ulonglong)lVar5 >> 0x20);
  iVar2 = iVar3 + (uint)CARRY4(*(uint *)(param_1 + 0x7c),uVar4);
  *(uint *)(param_1 + 0x48) = uVar4;
  *(int *)(param_1 + 0x4c) = iVar3;
  if (((param_4 <= iVar2) && ((param_4 < iVar2 || (param_3 < *(uint *)(param_1 + 0x7c) + uVar4))))
     || (((param_2 != 0 ||
          ((uVar4 != *(uint *)(param_1 + 0x50) || (iVar3 != *(int *)(param_1 + 0x54))))) &&
         ((iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 8))
                             (*(int **)(param_1 + 0x40),&local_10,8,uVar4,iVar3), iVar2 != 0 ||
          (((uint)local_10 != -0x6fa2a27 || (local_10._4_4_ != -0x289c5ee0))))))))
  goto LAB_004879e1;
  iVar2 = pager_read32be(*(int **)(param_1 + 0x40),uVar4 + 8,iVar3 + (uint)(0xfffffff7 < uVar4),
                       local_14);
  if ((iVar2 == 0) &&
     ((iVar2 = pager_read32be(*(int **)(param_1 + 0x40),uVar4 + 0xc,iVar3 + (uint)(0xfffffff3 < uVar4)
                            ,(uint *)(param_1 + 0x30)), iVar2 == 0 &&
      (iVar2 = pager_read32be(*(int **)(param_1 + 0x40),uVar4 + 0x10,
                            iVar3 + (uint)(0xffffffef < uVar4),local_18), iVar2 == 0)))) {
    if (*(int *)(param_1 + 0x48) == 0 && *(int *)(param_1 + 0x4c) == 0) {
      iVar2 = pager_read32be(*(int **)(param_1 + 0x40),uVar4 + 0x14,iVar3 + (uint)(0xffffffeb < uVar4)
                           ,(uint *)&local_18);
      if ((iVar2 != 0) ||
         (iVar2 = pager_read32be(*(int **)(param_1 + 0x40),uVar4 + 0x18,
                               iVar3 + (uint)(0xffffffe7 < uVar4),(uint *)&local_14),
         puVar1 = local_18, iVar2 != 0)) {
LAB_004879e1:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      if (local_14 == (uint *)0x0) {
        local_14 = *(uint **)(param_1 + 0x80);
      }
      if ((((local_14 < (uint *)0x200) || (local_18 < (uint *)0x20)) || ((uint *)0x10000 < local_14)
          ) || ((((uint *)0x10000 < local_18 || (((uint)local_14 & (int)local_14 - 1U) != 0)) ||
                (((uint)local_18 & (int)local_18 - 1U) != 0)))) goto LAB_004879e1;
      sqlite3PagerSetPagesize(param_1,(uint *)&local_14,-1);
      *(uint **)(param_1 + 0x7c) = puVar1;
    }
    puVar1 = (uint *)(param_1 + 0x48);
    uVar4 = *puVar1;
    *puVar1 = *puVar1 + *(uint *)(param_1 + 0x7c);
    *(int *)(param_1 + 0x4c) =
         *(int *)(param_1 + 0x4c) + (uint)CARRY4(uVar4,*(uint *)(param_1 + 0x7c));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: pager_readMasterJournal  (confidence: high)
 * purpose: Reads super/master-journal name appended to journal, validates magic+checksum; SQLite readMasterJournal
 * vars: param_2=out name; local_10 magic
 */
/* Global::pager_readMasterJournal @ 00487a00 */

void __cdecl pager_readMasterJournal(int *param_1,undefined1 *param_2,uint param_3)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  *param_2 = 0;
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,&local_1c);
  if (((iVar2 == 0) && (-1 < local_18)) && ((0 < local_18 || (0xf < local_1c)))) {
    iVar2 = pager_read32be(param_1,local_1c - 0x10,local_18 - (uint)(local_1c < 0x10),&local_14);
    uVar4 = local_14;
    if ((iVar2 == 0) && (local_14 < param_3)) {
      iVar2 = pager_read32be(param_1,local_1c - 0xc,local_18 - (uint)(local_1c < 0xc),&local_14);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*param_1 + 8))
                          (param_1,&local_10,8,local_1c - 8,local_18 - (uint)(local_1c < 8));
        if (((iVar2 == 0) && (local_10 == -0x6fa2a27)) && (local_c == -0x289c5ee0)) {
          iVar2 = sqlite3OsFileControl(param_1,param_2,uVar4,(local_1c - uVar4) - 0x10,
                               (local_18 - (uint)(local_1c < uVar4)) -
                               (uint)(local_1c - uVar4 < 0x10));
          if (iVar2 == 0) {
            uVar3 = 0;
            if (uVar4 != 0) {
              do {
                pcVar1 = param_2 + uVar3;
                uVar3 = uVar3 + 1;
                local_14 = local_14 - (int)*pcVar1;
              } while (uVar3 < uVar4);
            }
            if (local_14 != 0) {
              uVar4 = 0;
            }
            param_2[uVar4] = 0;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: pager_freeSavepointArray  (confidence: high)
 * purpose: Frees pager savepoint bitvecs (48e9a0) and the savepoint array; SQLite releaseAllSavepoints
 * vars: param_1+0x5c aSavepoint; +0x60 nSavepoint
 */
/* Global::pager_freeSavepointArray @ 00487f30 */

void __cdecl pager_freeSavepointArray(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    iVar2 = 0;
    do {
      bitvec_destroy(*(int *)(iVar2 + 0x10 + *(int *)(param_1 + 0x5c)));
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar3 < *(int *)(param_1 + 0x60));
  }
  if ((*(char *)(param_1 + 4) == '\0') ||
     ((undefined *)**(undefined4 **)(param_1 + 0x44) == &DAT_00569a48)) {
    piVar1 = *(int **)(param_1 + 0x44);
    if (*piVar1 != 0) {
      (**(code **)(*piVar1 + 4))(piVar1);
      *piVar1 = 0;
    }
  }
  sqlite3_free(*(int *)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}




/* [AUDIT] proposed: vdbe_releaseMemArray  (confidence: high)
 * purpose: Releases an array of param_2 Mem cells (frees strings/blobs, 40-byte stride); SQLite releaseMemArray
 * vars: stride 0x28; piVar3+(-2) flags
 */
/* Global::vdbe_releaseMemArray @ 00487fb0 */

void __cdecl vdbe_releaseMemArray(int *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar2 = *param_1;
    uVar1 = *(undefined1 *)(iVar2 + 0x38);
    if (*(int *)(iVar2 + 0x1f0) == 0) {
      if (param_1 < param_1 + param_2 * 10) {
        local_8 = (uint)((int)(param_1 + param_2 * 10) + (-1 - (int)param_1)) / 0x28 + 1;
        piVar3 = param_1 + 9;
        do {
          if ((*(ushort *)(piVar3 + -2) & 0x2460) == 0) {
            if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
              sqlite3PageFree(iVar2,(undefined4 *)*piVar3);
              goto LAB_00488071;
            }
          }
          else {
            sqlite3VdbeMemReleaseExternal(piVar3 + -9);
            sqlite3PageFree(piVar3[-9],(undefined4 *)*piVar3);
            piVar3[-8] = 0;
            piVar3[-1] = 0;
LAB_00488071:
            *piVar3 = 0;
          }
          *(undefined2 *)(piVar3 + -2) = 0x80;
          piVar3 = piVar3 + 10;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      *(undefined1 *)(iVar2 + 0x38) = uVar1;
    }
    else {
      piVar3 = param_1 + param_2 * 10;
      if (param_1 < piVar3) {
        do {
          sqlite3PageFree(iVar2,(undefined4 *)param_1[9]);
          param_1 = param_1 + 10;
        } while (param_1 < piVar3);
        return;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: btree_releasePage  (confidence: high)
 * purpose: Releases the page referenced by a btree cursor (+0x44) via pcacheRelease; SQLite releasePage
 * vars: param_1+0x44 pDbPage
 */
/* Global::btree_releasePage @ 004880a0 */

void __cdecl btree_releasePage(int param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  if ((param_1 != 0) && (puVar1 = *(undefined4 **)(param_1 + 0x44), puVar1 != (undefined4 *)0x0)) {
    puVar2 = (uint *)puVar1[4];
    sqlite3PcacheRelease(puVar1);
    if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar2);
    }
  }
  return;
}




/* [AUDIT] proposed: btree_updateOverflowCell  (confidence: med)
 * purpose: Rewrites a cell's overflow chain/ptrmap and copies payload for balance; SQLite balance helper
 * vars: param_2=pCell; param_5=newPgno
 */
/* Global::btree_updateOverflowCell @ 00488380 */

uint __cdecl
btree_updateOverflowCell(int *param_1,char *param_2,undefined4 param_3,uint param_4,uint param_5,int param_6)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  uint local_8;
  
  uVar5 = param_5;
  iVar1 = *(int *)(param_2 + 0x48);
  uVar4 = sqlite3PagerMovepage((undefined4 *)*param_1,*(undefined4 **)(param_2 + 0x44),param_5,param_6);
  if (uVar4 == 0) {
    *(uint *)(param_2 + 0x48) = uVar5;
    cVar7 = (char)param_3;
    local_8 = uVar4;
    if ((cVar7 == '\x05') || (cVar7 == '\x01')) {
      uVar5 = btree_clearCell(param_2);
      uVar4 = 0;
      if (uVar5 != 0) {
        return uVar5;
      }
    }
    else {
      puVar2 = *(undefined1 **)(param_2 + 0x38);
      uVar6 = CONCAT31(CONCAT21(CONCAT11(*puVar2,puVar2[1]),puVar2[2]),puVar2[3]);
      if (uVar6 != 0) {
        btree_ptrmapPut(param_1,uVar6,'\x04',uVar5,&local_8);
        uVar4 = 0;
        if (local_8 != 0) {
          return local_8;
        }
      }
    }
    if ((cVar7 != '\x01') &&
       (uVar4 = btree_getAndInitPage(param_1,param_4,(int *)&param_2,0), pcVar3 = param_2, uVar4 == 0)) {
      uVar4 = pagerPlaybackSavepoint(*(undefined4 **)(param_2 + 0x44));
      if (uVar4 != 0) {
        btree_releasePage((int)pcVar3);
        return uVar4;
      }
      uVar4 = btree_putCellPtr(pcVar3,iVar1,param_5,cVar7);
      local_8 = uVar4;
      btree_releasePage((int)pcVar3);
      if (uVar4 == 0) {
        btree_ptrmapPut(param_1,param_5,cVar7,param_4,&local_8);
        uVar4 = local_8;
      }
    }
  }
  return uVar4;
}




/* [AUDIT] proposed: btree_unrefSharedCache  (confidence: high)
 * purpose: Decrements shared BtShared refcount, unlinks from global list, frees mutex when zero; SQLite removeFromSharingList
 * vars: param_1+0x40 nRef; DAT_00583e80 list
 */
/* Global::btree_unrefSharedCache @ 00488510 */

undefined4 __cdecl btree_unrefSharedCache(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_00582acc == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*DAT_00582b10)(2);
    if (iVar3 != 0) {
      (*DAT_00582b18)(iVar3);
    }
  }
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
  if (*(int *)(param_1 + 0x40) < 1) {
    iVar2 = DAT_00583e80;
    if (DAT_00583e80 == param_1) {
      DAT_00583e80 = *(int *)(param_1 + 0x44);
    }
    else {
      do {
        iVar1 = iVar2;
        if (iVar1 == 0) goto LAB_00488576;
        iVar2 = *(int *)(iVar1 + 0x44);
      } while (*(int *)(iVar1 + 0x44) != param_1);
      *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(param_1 + 0x44);
    }
LAB_00488576:
    if (*(int *)(param_1 + 0x38) != 0) {
      (*DAT_00582b14)(*(int *)(param_1 + 0x38));
    }
    uVar4 = 1;
  }
  if (iVar3 != 0) {
    (*DAT_00582b20)(iVar3);
  }
  return uVar4;
}




/* [AUDIT] proposed: sqlite3_logCallback  (confidence: med)
 * purpose: Formats a message into 212-byte StrAccum and invokes the log hook (DAT_00582bac); SQLite; misattributed Speech
 * vars: local_dc buffer; local_e8=0xd2 cap
 */
/* Global::sqlite3_logCallback @ 004885a0 */

void __cdecl sqlite3_logCallback(undefined4 param_1,byte *param_2,double *param_3)

{
  int iVar1;
  int local_f8;
  undefined1 *local_f4;
  undefined1 *local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 local_e0;
  undefined2 local_df;
  undefined1 local_dc [212];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_f4 = local_dc;
  local_f8 = 0;
  local_ec = 0;
  local_e8 = 0xd2;
  local_e4 = 0;
  local_df = 0;
  local_e0 = 0;
  local_f0 = local_f4;
  sqlite3VXPrintf(&local_f8,0,param_2,param_3);
  iVar1 = sqlite3StrAccumFinish(&local_f8);
  (*DAT_00582bac)(DAT_00582bb0,param_1,iVar1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: btree_saveCursorPages  (confidence: low)
 * purpose: Reads current page (46b2f0), caches, then releases all cursor pages resetting cell cache; SQLite btree cursor save/clear
 * vars: param_1+0x5e iPage; +0x50 payload buf
 */
/* Global::btree_saveCursorPages @ 00489c10 */

uint __cdecl btree_saveCursorPages(uint param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  
  uVar4 = param_1;
  if (*(char *)(param_1 + 0x5b) == '\x01') {
    btree_cacheCellSize(param_1);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x2c);
  }
  else {
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  piVar1 = (int *)(param_1 + 0x88);
  piVar7 = (int *)(param_1 + 0x88);
  param_1 = 0;
  if (*(char *)(*piVar1 + 2) == '\0') {
    pvVar5 = (void *)sqlite3Malloc(*(int *)(uVar4 + 0x48));
    if (pvVar5 == (void *)0x0) {
      param_1 = 7;
      goto LAB_00489cf1;
    }
    param_1 = btree_accessPayload(uVar4,0,*(size_t *)(uVar4 + 0x48),pvVar5,0);
    if (param_1 != 0) {
      sqlite3_free((int)pvVar5);
      goto LAB_00489cf1;
    }
    *(void **)(uVar4 + 0x50) = pvVar5;
  }
  iVar6 = 0;
  if (*(ushort *)(uVar4 + 0x5e) < 0x8000) {
    do {
      if ((*piVar7 != 0) && (puVar2 = *(undefined4 **)(*piVar7 + 0x44), puVar2 != (undefined4 *)0x0)
         ) {
        puVar3 = (uint *)puVar2[4];
        sqlite3PcacheRelease(puVar2);
        if (*(int *)(puVar3[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar3);
        }
      }
      *piVar7 = 0;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 <= *(short *)(uVar4 + 0x5e));
  }
  *(undefined2 *)(uVar4 + 0x5e) = 0xffff;
  *(undefined1 *)(uVar4 + 0x5b) = 2;
LAB_00489cf1:
  sqlite3_free(*(int *)(uVar4 + 0x14));
  *(undefined4 *)(uVar4 + 0x14) = 0;
  return param_1;
}




/* [AUDIT] proposed: vdbe_commitAllBtrees  (confidence: med)
 * purpose: Iterates db backends: parses page1 (47fc00), commits/updates change counters, sets SCHEMA retry; SQLite vdbeCommit
 * vars: iVar5+0x10 aDb; local_c iDb
 */
/* Global::vdbe_commitAllBtrees @ 00489d30 */

void __cdecl vdbe_commitAllBtrees(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint *puVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  uint uVar14;
  int local_10;
  int local_c;
  
  local_c = 0;
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x14) < 1) {
    return;
  }
  local_10 = 0;
LAB_00489d57:
  uVar14 = 0;
  piVar6 = *(int **)(local_10 + 4 + *(int *)(iVar5 + 0x10));
  if (piVar6 != (int *)0x0) {
    if ((char)piVar6[2] == '\0') {
      piVar7 = (int *)piVar6[1];
      btree_enter(piVar6);
      if (((char)piVar6[2] != '\x02') && ((char)piVar6[2] != '\x01')) {
        if (((*(ushort *)((int)piVar7 + 0x16) & 0x40) == 0) || (*(int *)piVar7[0x13] == 0)) {
          iVar11 = piVar6[1];
          if (*(char *)((int)piVar6 + 9) == '\0') {
LAB_00489de8:
            uVar14 = 0;
            uVar13 = *(ushort *)((int)piVar7 + 0x16) & 0xfff7;
            *(ushort *)((int)piVar7 + 0x16) = uVar13;
            if (piVar7[0xb] == 0) {
              *(ushort *)((int)piVar7 + 0x16) = uVar13 | 8;
            }
LAB_00489e00:
            if (piVar7[3] == 0) goto code_r0x00489e06;
            if (uVar14 != 0) goto LAB_00489e1b;
            goto LAB_00489e57;
          }
          if ((*(int **)(iVar11 + 0x4c) == piVar6) || ((*(byte *)(iVar11 + 0x16) & 0x20) == 0)) {
            for (puVar8 = *(undefined4 **)(iVar11 + 0x48); puVar8 != (undefined4 *)0x0;
                puVar8 = (undefined4 *)puVar8[3]) {
              if ((((int *)*puVar8 != piVar6) && (puVar8[1] == 1)) &&
                 (*(char *)(puVar8 + 2) != '\x01')) goto LAB_00489da3;
            }
            goto LAB_00489de8;
          }
          uVar14 = 0x106;
        }
        else {
LAB_00489da3:
          uVar14 = 0x106;
        }
      }
      goto LAB_00489ec8;
    }
    goto LAB_00489f0c;
  }
  goto LAB_00489fe1;
code_r0x00489e06:
  uVar14 = btree_readPage1(piVar7);
  if (uVar14 != 0) {
LAB_00489e1b:
    if ((*(char *)((int)piVar7 + 0x13) == '\0') && (piVar7[3] != 0)) {
      puVar8 = *(undefined4 **)(piVar7[3] + 0x44);
      if (puVar8 != (undefined4 *)0x0) {
        puVar9 = (uint *)puVar8[4];
        sqlite3PcacheRelease(puVar8);
        if (*(int *)(puVar9[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar9);
        }
      }
      piVar7[3] = 0;
    }
LAB_00489e57:
    if (((char)uVar14 != '\x05') || (*(char *)((int)piVar7 + 0x13) != '\0')) goto LAB_00489e96;
    iVar11 = piVar7[1];
    if (((undefined4 *)(iVar11 + 0x1ac) == (undefined4 *)0x0) ||
       ((pcVar10 = *(code **)(iVar11 + 0x1ac), pcVar10 == (code *)0x0 ||
        (*(int *)(iVar11 + 0x1b4) < 0)))) goto LAB_00489e96;
    iVar12 = (*pcVar10)(*(undefined4 *)(iVar11 + 0x1b0),*(int *)(iVar11 + 0x1b4));
    if (iVar12 == 0) goto LAB_00489e8f;
    *(int *)(iVar11 + 0x1b4) = *(int *)(iVar11 + 0x1b4) + 1;
  }
  goto LAB_00489e00;
LAB_00489e8f:
  *(undefined4 *)(iVar11 + 0x1b4) = 0xffffffff;
LAB_00489e96:
  if (uVar14 == 0) {
    if (((char)piVar6[2] == '\0') &&
       (piVar7[10] = piVar7[10] + 1, *(char *)((int)piVar6 + 9) != '\0')) {
      *(undefined1 *)(piVar6 + 9) = 1;
      piVar6[10] = piVar7[0x12];
      piVar7[0x12] = (int)(piVar6 + 7);
    }
    *(undefined1 *)(piVar6 + 2) = 1;
    if (*(char *)((int)piVar7 + 0x13) == '\0') {
      *(undefined1 *)((int)piVar7 + 0x13) = 1;
    }
  }
LAB_00489ec8:
  if (*(char *)((int)piVar6 + 9) != '\0') {
    piVar7 = piVar6 + 3;
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      if (*(int *)(piVar6[1] + 0x38) != 0) {
        (*DAT_00582b20)(*(int *)(piVar6[1] + 0x38));
      }
      *(undefined1 *)((int)piVar6 + 10) = 0;
    }
  }
  if ((uVar14 == 7) || (uVar14 == 0xc0a)) {
    *(undefined1 *)(iVar5 + 0x38) = 1;
  }
  if (uVar14 != 0) {
    return;
  }
  uVar14 = 1;
LAB_00489f0c:
  iVar11 = piVar6[1];
  btree_enter(piVar6);
  iVar11 = *(int *)(*(int *)(iVar11 + 0xc) + 0x38);
  uVar1 = *(undefined1 *)(iVar11 + 0x28);
  uVar2 = *(undefined1 *)(iVar11 + 0x29);
  uVar3 = *(undefined1 *)(iVar11 + 0x2a);
  uVar4 = *(undefined1 *)(iVar11 + 0x2b);
  if (*(char *)((int)piVar6 + 9) != '\0') {
    piVar7 = piVar6 + 3;
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      if (*(int *)(piVar6[1] + 0x38) != 0) {
        (*DAT_00582b20)(*(int *)(piVar6[1] + 0x38));
      }
      *(undefined1 *)((int)piVar6 + 10) = 0;
    }
  }
  piVar7 = *(int **)(local_10 + 0xc + *(int *)(iVar5 + 0x10));
  if (CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4) != *piVar7) {
    sqlite3SchemaClear((int)piVar7);
    if (local_c != 1) {
      sqlite3SchemaClear(*(int *)(*(int *)(iVar5 + 0x10) + 0x1c));
    }
    param_1[3] = 0x11;
  }
  if (uVar14 != 0) {
    btree_enter(piVar6);
    uVar14 = btree_rollback(piVar6,(char *)0x0);
    if (uVar14 == 0) {
      btree_commitPhaseTwo(piVar6,0);
    }
    if (*(char *)((int)piVar6 + 9) != '\0') {
      piVar7 = piVar6 + 3;
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        if (*(int *)(piVar6[1] + 0x38) != 0) {
          (*DAT_00582b20)(*(int *)(piVar6[1] + 0x38));
        }
        *(undefined1 *)((int)piVar6 + 10) = 0;
      }
    }
  }
LAB_00489fe1:
  local_c = local_c + 1;
  local_10 = local_10 + 0x10;
  if (*(int *)(iVar5 + 0x14) <= local_c) {
    return;
  }
  goto LAB_00489d57;
}




/* [AUDIT] proposed: btree_clearCell  (confidence: high)
 * purpose: Frees a cell's overflow-page chain and updates ptrmap entries (4870c0); SQLite clearCell
 * vars: param_1+0x34 pBt; +0x10 nCell
 */
/* Global::btree_clearCell @ 0048b310 */

uint __cdecl btree_clearCell(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  uint local_34 [6];
  ushort local_1c;
  uint local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  piVar5 = *(int **)(param_1 + 0x34);
  cVar1 = *param_1;
  local_10 = *(int *)(param_1 + 0x48);
  local_c = piVar5;
  uVar2 = btree_initPage(param_1);
  if (uVar2 != 0) {
    *param_1 = cVar1;
    return uVar2;
  }
  local_14 = (uint)*(ushort *)(param_1 + 0x10);
  iVar3 = 0;
  local_8 = 0;
  if (local_14 != 0) {
    do {
      puVar4 = (undefined1 *)
               ((uint)(CONCAT11(*(undefined1 *)(*(int *)(param_1 + 0x40) + iVar3 * 2),
                                *(undefined1 *)(*(int *)(param_1 + 0x40) + 1 + iVar3 * 2)) &
                      *(ushort *)(param_1 + 0x12)) + *(int *)(param_1 + 0x38));
      if ((local_8 == 0) && (btree_parseCellPtr((int)param_1,(uint)puVar4,local_34), local_1c != 0)) {
        uVar2 = (uint)local_1c;
        btree_ptrmapPut(*(int **)(param_1 + 0x34),
                     CONCAT31(CONCAT21(CONCAT11(puVar4[uVar2],puVar4[uVar2 + 1]),puVar4[uVar2 + 2]),
                              puVar4[uVar2 + 3]),'\x03',*(int *)(param_1 + 0x48),&local_8);
      }
      piVar5 = local_c;
      if (param_1[3] == '\0') {
        btree_ptrmapPut(local_c,CONCAT31(CONCAT21(CONCAT11(*puVar4,puVar4[1]),puVar4[2]),puVar4[3]),
                     '\x05',local_10,&local_8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)local_14);
  }
  if (param_1[3] != '\0') {
    *param_1 = cVar1;
    return local_8;
  }
  iVar3 = (uint)(byte)param_1[5] + *(int *)(param_1 + 0x38);
  btree_ptrmapPut(piVar5,CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 8),
                                                 *(undefined1 *)(iVar3 + 9)),
                                        *(undefined1 *)(iVar3 + 10)),*(undefined1 *)(iVar3 + 0xb)),
               '\x05',local_10,&local_8);
  *param_1 = cVar1;
  return local_8;
}




/* [AUDIT] proposed: pager_setSectorSize  (confidence: high)
 * purpose: Determines pager sector size from VFS xSectorSize/xDeviceCharacteristics, clamps 0x200..0x10000
 * vars: param_1+0x7c sectorSize; +0x3c fd
 */
/* Global::pager_setSectorSize @ 0048b530 */

void __cdecl pager_setSectorSize(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x30))(*(int **)(param_1 + 0x3c));
    if ((uVar2 & 0x1000) == 0) {
      pcVar1 = *(code **)(**(int **)(param_1 + 0x3c) + 0x2c);
      if (pcVar1 == (code *)0x0) {
        *(undefined4 *)(param_1 + 0x7c) = 0x1000;
        return;
      }
      iVar3 = (*pcVar1)(*(int **)(param_1 + 0x3c));
      if (iVar3 < 0x20) {
        *(undefined4 *)(param_1 + 0x7c) = 0x200;
        return;
      }
      if (0x10000 < iVar3) {
        iVar3 = 0x10000;
      }
      *(int *)(param_1 + 0x7c) = iVar3;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x7c) = 0x200;
  return;
}




/* [AUDIT] proposed: sqlite3_setupLookaside  (confidence: high)
 * purpose: Configures a DB connection's lookaside memory pool (slot size/count linked free list); SQLite setupLookaside; misattributed Speech
 * vars: param_1+0x104 pStart; +0xe8 slotSize
 */
/* Global::sqlite3_setupLookaside @ 0048b660 */

undefined4 __cdecl sqlite3_setupLookaside(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0xec) != 0) {
    return 5;
  }
  if (*(char *)(param_1 + 0xeb) != '\0') {
    sqlite3_free(*(int *)(param_1 + 0x104));
  }
  uVar3 = param_3 & 0xfffffff8;
  if ((int)uVar3 < 5) {
    uVar3 = 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if ((uVar3 == 0) || (param_4 == 0)) {
    uVar3 = 0;
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = param_2;
    if (param_2 == (undefined4 *)0x0) {
      if (DAT_00583e74 != (code *)0x0) {
        (*DAT_00583e74)();
      }
      puVar1 = (undefined4 *)sqlite3Malloc(uVar3 * param_4);
      if (DAT_00583e78 != (code *)0x0) {
        (*DAT_00583e78)();
      }
      if (puVar1 != (undefined4 *)0x0) {
        iVar2 = (*DAT_00582af0._4_4_)(puVar1);
        param_4 = iVar2 / (int)uVar3;
      }
    }
  }
  *(undefined4 **)(param_1 + 0x104) = puVar1;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(short *)(param_1 + 0xe8) = (short)uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined2 *)(param_1 + 0xea) = 0;
    return 0;
  }
  while (param_4 = param_4 + -1, -1 < param_4) {
    *puVar1 = *(undefined4 *)(param_1 + 0x100);
    *(undefined4 **)(param_1 + 0x100) = puVar1;
    puVar1 = (undefined4 *)((int)puVar1 + uVar3);
  }
  *(undefined4 **)(param_1 + 0x108) = puVar1;
  *(bool *)(param_1 + 0xeb) = param_2 == (undefined4 *)0x0;
  *(undefined1 *)(param_1 + 0xea) = 1;
  return 0;
}




/* [AUDIT] proposed: sqlite3_apiExit  (confidence: high)
 * purpose: Maps rc to db errMask, sets NOMEM on mallocFailed; SQLite sqlite3ApiExit
 * vars: param_1+0x38 mallocFailed; +0x30 errMask
 */
/* Global::sqlite3_apiExit @ 0048ca70 */

uint __cdecl sqlite3_apiExit(int param_1,uint param_2)

{
  if (param_1 != 0) {
    if ((*(char *)(param_1 + 0x38) != '\0') || (param_2 == 0xc0a)) {
      sqlite3ErrorWithMsg(param_1,7,(byte *)0x0);
      *(undefined1 *)(param_1 + 0x38) = 0;
      param_2 = 7;
    }
    return param_2 & *(uint *)(param_1 + 0x30);
  }
  return param_2 & 0xff;
}




/* [AUDIT] proposed: sqlite3_autoExtensions  (confidence: high)
 * purpose: Runs all registered auto-extensions on a new connection; logs failures; SQLite; 'automatic extension loading failed: %s'
 * vars: DAT_00583e68 nExt; DAT_00583e6c aExt
 */
/* Global::sqlite3_autoExtensions @ 0048d6f0 */

void __cdecl sqlite3_autoExtensions(int param_1)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  bVar1 = true;
  if (DAT_00583e68 != 0) {
    iVar4 = 0;
    do {
      if (DAT_00582acc == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*DAT_00582b10)(2);
        if (iVar3 != 0) {
          (*DAT_00582b18)(iVar3);
        }
      }
      if (iVar4 < DAT_00583e68) {
        pcVar2 = *(code **)(DAT_00583e6c + iVar4 * 4);
      }
      else {
        pcVar2 = (code *)0x0;
        bVar1 = false;
      }
      if (iVar3 != 0) {
        (*DAT_00582b20)(iVar3);
      }
      local_8 = 0;
      if ((pcVar2 != (code *)0x0) &&
         (iVar3 = (*pcVar2)(param_1,&local_8,&PTR_FUN_0056a290), iVar3 != 0)) {
        sqlite3ErrorWithMsg(param_1,iVar3,(byte *)"automatic extension loading failed: %s");
        bVar1 = false;
      }
      sqlite3_free(local_8);
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
  return;
}




/* [AUDIT] proposed: btree_writeOverflowCursors  (confidence: low)
 * purpose: For each affected cursor, writes overflow payload for a page (46e390); SQLite incremental-vacuum cursor update
 * vars: param_1[0xb] next; [7] eState
 */
/* Global::btree_writeOverflowCursors @ 0048e040 */

void __cdecl btree_writeOverflowCursors(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  for (; param_1 != (int *)0x0; param_1 = (int *)param_1[0xb]) {
    iVar1 = param_1[7];
    if ((((iVar1 == 0) || (iVar1 == 5)) || (iVar1 == 6)) && (param_2 < (undefined4 *)param_1[4])) {
      if (*(int *)(*param_1 + 0xc) != 0) {
        (*DAT_00582b18)(*(int *)(*param_1 + 0xc));
      }
      uVar2 = btree_writeOverflow((int)param_1,param_2,param_3);
      if (*(int *)(*param_1 + 0xc) != 0) {
        (*DAT_00582b20)(*(int *)(*param_1 + 0xc));
      }
      if (uVar2 != 0) {
        param_1[7] = uVar2;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: btree_closeConnection  (confidence: med)
 * purpose: Closes a Btree connection: finalizes cursors, unlinks from shared list, frees schema/pager; SQLite sqlite3BtreeClose
 * vars: param_1[1]=pBt; [5]/[6] list links
 */
/* Global::btree_closeConnection @ 0048f070 */

undefined4 __cdecl btree_closeConnection(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)param_1[1];
  btree_enter(param_1);
  piVar2 = (int *)puVar1[2];
  while (piVar3 = piVar2, piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[2];
    if ((int *)*piVar3 == param_1) {
      btree_dropCursor(piVar3);
    }
  }
  sqlite3BtreeCommitPhaseOne(param_1,0);
  if (*(char *)((int)param_1 + 9) != '\0') {
    piVar2 = param_1 + 3;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (*(int *)(param_1[1] + 0x38) != 0) {
        (*DAT_00582b20)(*(int *)(param_1[1] + 0x38));
      }
      *(undefined1 *)((int)param_1 + 10) = 0;
    }
    if ((*(char *)((int)param_1 + 9) != '\0') && (iVar4 = btree_unrefSharedCache((int)puVar1), iVar4 == 0))
    goto LAB_0048f125;
  }
  sqlite3PagerClose((uint *)*puVar1);
  if (((code *)puVar1[0xd] != (code *)0x0) && (puVar1[0xc] != 0)) {
    (*(code *)puVar1[0xd])(puVar1[0xc]);
  }
  sqlite3_free(puVar1[0xc]);
  pcache_freePageMem((undefined4 *)puVar1[0x14]);
  puVar1[0x14] = 0;
  sqlite3_free((int)puVar1);
LAB_0048f125:
  if (param_1[6] != 0) {
    *(int *)(param_1[6] + 0x14) = param_1[5];
  }
  if (param_1[5] != 0) {
    *(int *)(param_1[5] + 0x18) = param_1[6];
  }
  sqlite3_free((int)param_1);
  return 0;
}




/* [AUDIT] proposed: btree_dropCursor  (confidence: high)
 * purpose: Removes one BtCursor: releases pages, unlinks from list, releases overflow cache; SQLite
 * vars: param_1[2]/[3] next/prev; +0x5e iPage
 */
/* Global::btree_dropCursor @ 0048f150 */

undefined4 __cdecl btree_dropCursor(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = param_1[1];
    btree_enter(puVar1);
    sqlite3_free(param_1[0x14]);
    param_1[0x14] = 0;
    *(undefined1 *)((int)param_1 + 0x5b) = 0;
    if (param_1[3] == 0) {
      *(undefined4 *)(iVar2 + 8) = param_1[2];
    }
    else {
      *(undefined4 *)(param_1[3] + 8) = param_1[2];
    }
    if (param_1[2] != 0) {
      *(undefined4 *)(param_1[2] + 0xc) = param_1[3];
    }
    if (*(ushort *)((int)param_1 + 0x5e) < 0x8000) {
      piVar6 = param_1 + 0x22;
      iVar5 = 0;
      do {
        if ((*piVar6 != 0) &&
           (puVar3 = *(undefined4 **)(*piVar6 + 0x44), puVar3 != (undefined4 *)0x0)) {
          puVar4 = (uint *)puVar3[4];
          sqlite3PcacheRelease(puVar3);
          if (*(int *)(puVar4[0x2d] + 0xc) == 0) {
            pcache_releasePage(puVar4);
          }
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar5 <= *(short *)((int)param_1 + 0x5e));
    }
    if ((*(char *)(iVar2 + 0x13) == '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
      puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0xc) + 0x44);
      if (puVar3 != (undefined4 *)0x0) {
        puVar4 = (uint *)puVar3[4];
        sqlite3PcacheRelease(puVar3);
        if (*(int *)(puVar4[0x2d] + 0xc) == 0) {
          pcache_releasePage(puVar4);
        }
      }
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
    sqlite3_free(param_1[5]);
    param_1[5] = 0;
    if (*(char *)((int)puVar1 + 9) != '\0') {
      piVar6 = puVar1 + 3;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        if (*(int *)(puVar1[1] + 0x38) != 0) {
          (*DAT_00582b20)(*(int *)(puVar1[1] + 0x38));
        }
        *(undefined1 *)((int)puVar1 + 10) = 0;
      }
    }
  }
  return 0;
}




/* [AUDIT] proposed: btree_rollback  (confidence: med)
 * purpose: Rolls back a btree transaction: reverts page cache (46e160) or aborts (4a19a0); SQLite sqlite3BtreeRollback
 * vars: param_1[1]=pBt; +2 inTrans
 */
/* Global::btree_rollback @ 0048f2f0 */

uint __cdecl btree_rollback(undefined4 *param_1,char *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 2) == '\x02') {
    piVar1 = (int *)param_1[1];
    btree_enter(param_1);
    if (*(char *)((int)piVar1 + 0x11) != '\0') {
      uVar2 = btree_balanceCleanup(piVar1);
      if (uVar2 != 0) {
        if (*(char *)((int)param_1 + 9) != '\0') {
          piVar1 = param_1 + 3;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            if (*(int *)(param_1[1] + 0x38) != 0) {
              (*DAT_00582b20)(*(int *)(param_1[1] + 0x38));
            }
            *(undefined1 *)((int)param_1 + 10) = 0;
          }
        }
        return uVar2;
      }
    }
    uVar2 = sqlite3PagerCommitPhaseOne((uint *)*piVar1,param_2,0);
    if (*(char *)((int)param_1 + 9) != '\0') {
      piVar1 = param_1 + 3;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        if (*(int *)(param_1[1] + 0x38) != 0) {
          (*DAT_00582b20)(*(int *)(param_1[1] + 0x38));
        }
        *(undefined1 *)((int)param_1 + 10) = 0;
      }
    }
  }
  return uVar2;
}




/* [AUDIT] proposed: btree_commitPhaseTwo  (confidence: high)
 * purpose: Commits btree phase two: commits pager (4a1bb0) and releases lock (471200); SQLite sqlite3BtreeCommitPhaseTwo
 * vars: param_1[1]=pBt; +2 inTrans
 */
/* Global::btree_commitPhaseTwo @ 0048f390 */

int __cdecl btree_commitPhaseTwo(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((char)param_1[2] == '\0') {
    return 0;
  }
  btree_enter(param_1);
  if ((char)param_1[2] == '\x02') {
    puVar2 = (undefined4 *)param_1[1];
    iVar3 = pager_playback_or_reset((int *)*puVar2);
    if ((iVar3 != 0) && (param_2 == 0)) {
      sqlite3BtreeLeave((int)param_1);
      return iVar3;
    }
    *(undefined1 *)((int)puVar2 + 0x13) = 1;
  }
  btree_closeCursor(param_1);
  if (*(char *)((int)param_1 + 9) != '\0') {
    piVar1 = param_1 + 3;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      if (*(int *)(param_1[1] + 0x38) != 0) {
        (*DAT_00582b20)(*(int *)(param_1[1] + 0x38));
      }
      *(undefined1 *)((int)param_1 + 10) = 0;
    }
  }
  return 0;
}




/* [AUDIT] proposed: btree_enter  (confidence: high)
 * purpose: Enters a Btree's shared mutex, saving other locked cursors' state; SQLite sqlite3BtreeEnter
 * vars: param_1+9 sharable; +10 locked
 */
/* Global::btree_enter @ 0048fbc0 */


void __cdecl btree_enter(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((*(char *)((int)param_1 + 9) != '\0') &&
     (param_1[3] = param_1[3] + 1, *(char *)((int)param_1 + 10) == '\0')) {
    if ((*(int *)(param_1[1] + 0x38) == 0) ||
       (iVar3 = (*_DAT_00582b1c)(*(int *)(param_1[1] + 0x38)), iVar3 == 0)) {
      *(undefined4 *)(param_1[1] + 4) = *param_1;
      *(undefined1 *)((int)param_1 + 10) = 1;
      return;
    }
    for (iVar3 = param_1[5]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
      if (*(char *)(iVar3 + 10) != '\0') {
        iVar1 = *(int *)(*(int *)(iVar3 + 4) + 0x38);
        if (iVar1 != 0) {
          (*DAT_00582b20)(iVar1);
        }
        *(undefined1 *)(iVar3 + 10) = 0;
      }
    }
    if (*(int *)(param_1[1] + 0x38) != 0) {
      (*DAT_00582b18)(*(int *)(param_1[1] + 0x38));
    }
    *(undefined4 *)(param_1[1] + 4) = *param_1;
    puVar2 = (undefined4 *)param_1[5];
    *(undefined1 *)((int)param_1 + 10) = 1;
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[5]) {
      if (puVar2[3] != 0) {
        if (*(int *)(puVar2[1] + 0x38) != 0) {
          (*DAT_00582b18)(*(int *)(puVar2[1] + 0x38));
        }
        *(undefined4 *)(puVar2[1] + 4) = *puVar2;
        *(undefined1 *)((int)puVar2 + 10) = 1;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: btree_enterAll  (confidence: high)
 * purpose: Enters mutexes on all shared btrees of a connection (iterate aDb); SQLite sqlite3BtreeEnterAll
 * vars: param_1+0x14 nDb; +0x10 aDb
 */
/* Global::btree_enterAll @ 0048fca0 */


void __cdecl btree_enterAll(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  if (0 < *(int *)(param_1 + 0x14)) {
    local_8 = 0;
    iVar5 = 0;
    do {
      puVar1 = *(undefined4 **)(local_8 + 4 + *(int *)(param_1 + 0x10));
      if (((puVar1 != (undefined4 *)0x0) && (*(char *)((int)puVar1 + 9) != '\0')) &&
         (puVar1[3] = puVar1[3] + 1, *(char *)((int)puVar1 + 10) == '\0')) {
        if ((*(int *)(puVar1[1] + 0x38) == 0) ||
           (iVar4 = (*_DAT_00582b1c)(*(int *)(puVar1[1] + 0x38)), iVar4 == 0)) {
          *(undefined4 *)(puVar1[1] + 4) = *puVar1;
          *(undefined1 *)((int)puVar1 + 10) = 1;
        }
        else {
          for (iVar4 = puVar1[5]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x14)) {
            if (*(char *)(iVar4 + 10) != '\0') {
              iVar2 = *(int *)(*(int *)(iVar4 + 4) + 0x38);
              if (iVar2 != 0) {
                (*DAT_00582b20)(iVar2);
              }
              *(undefined1 *)(iVar4 + 10) = 0;
            }
          }
          if (*(int *)(puVar1[1] + 0x38) != 0) {
            (*DAT_00582b18)(*(int *)(puVar1[1] + 0x38));
          }
          *(undefined4 *)(puVar1[1] + 4) = *puVar1;
          puVar3 = (undefined4 *)puVar1[5];
          *(undefined1 *)((int)puVar1 + 10) = 1;
          for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[5]) {
            if (puVar3[3] != 0) {
              if (*(int *)(puVar3[1] + 0x38) != 0) {
                (*DAT_00582b18)(*(int *)(puVar3[1] + 0x38));
              }
              *(undefined4 *)(puVar3[1] + 4) = *puVar3;
              *(undefined1 *)((int)puVar3 + 10) = 1;
            }
          }
        }
      }
      iVar5 = iVar5 + 1;
      local_8 = local_8 + 0x10;
    } while (iVar5 < *(int *)(param_1 + 0x14));
  }
  return;
}




/* [AUDIT] proposed: sqlite3BtreeLeave  (confidence: high)
 * purpose: Release one BtShared mutex: decrement lock nRef at +0xc, on zero call sqlite3_mutex_leave(BtShared->mutex)
 * vars: param_1+9 sharable flag; +0xc wantToLock/nRef; +4 BtShared; +0x38 mutex; DAT_00582b20=mutex_leave
 */
/* Global::sqlite3BtreeLeave @ 00490750 */

void __cdecl sqlite3BtreeLeave(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 9) != '\0') {
    piVar1 = (int *)(param_1 + 0xc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x38);
      if (iVar2 != 0) {
        (*DAT_00582b20)(iVar2);
      }
      *(undefined1 *)(param_1 + 10) = 0;
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3BtreeLeaveAll  (confidence: high)
 * purpose: Loop over db->aDb[] (base +0x10, count +0x14) releasing each Btree's shared mutex
 * vars: stride 0x10 per Db; entry+4 Btree; mirrors BtreeLeave
 */
/* Global::sqlite3BtreeLeaveAll @ 00490780 */

void __cdecl sqlite3BtreeLeaveAll(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    iVar4 = 0;
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar4);
      if ((iVar2 != 0) && (*(char *)(iVar2 + 9) != '\0')) {
        piVar1 = (int *)(iVar2 + 0xc);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x38);
          if (iVar3 != 0) {
            (*DAT_00582b20)(iVar3);
          }
          *(undefined1 *)(iVar2 + 10) = 0;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar5 < *(int *)(param_1 + 0x14));
  }
  return;
}




/* [AUDIT] proposed: sqlite3BtreeOpen  (confidence: high)
 * purpose: Open a Btree/BtShared (alloc 0x2c btree + 0x54 shared), handle ':memory:', shared-cache list; sets pager pagesize
 * vars: _Dst=Btree(0x2c); piVar7=BtShared(0x54); DAT_00583e80=shared-cache list; param_6 open flags
 */
/* Global::sqlite3BtreeOpen @ 00490e00 */

void __cdecl
sqlite3BtreeOpen(undefined *param_1,byte *param_2,int param_3,undefined4 *param_4,byte param_5,
            uint param_6)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int *_Dst;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  char *pcVar11;
  byte *pbVar12;
  void *_Src;
  bool bVar13;
  bool bVar14;
  int local_94;
  int local_80;
  int local_70;
  undefined1 local_6c [16];
  ushort local_5c;
  byte local_58;
  undefined1 local_38 [12];
  undefined1 local_2c [36];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  bVar14 = false;
  local_80 = 0;
  local_70 = 0;
  if ((param_2 == (byte *)0x0) || (*param_2 == 0)) {
    bVar14 = true;
  }
  if (param_2 == (byte *)0x0) {
LAB_00490e7d:
    if (((bVar14) && (*(char *)(param_3 + 0x37) == '\x02')) || ((char)param_6 < '\0'))
    goto LAB_00490e98;
    bVar13 = false;
  }
  else {
    pcVar11 = ":memory:";
    pbVar4 = param_2;
    do {
      bVar2 = *pbVar4;
      bVar13 = bVar2 < (byte)*pcVar11;
      if (bVar2 != *pcVar11) {
LAB_00490e71:
        uVar5 = -(uint)bVar13 | 1;
        goto LAB_00490e76;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar13 = bVar2 < (byte)pcVar11[1];
      if (bVar2 != pcVar11[1]) goto LAB_00490e71;
      pbVar4 = pbVar4 + 2;
      pcVar11 = pcVar11 + 2;
    } while (bVar2 != 0);
    uVar5 = 0;
LAB_00490e76:
    if (uVar5 != 0) goto LAB_00490e7d;
LAB_00490e98:
    bVar13 = true;
    param_5 = param_5 | 2;
  }
  if (((param_6 & 0x100) != 0) && ((bVar13 || (bVar14)))) {
    param_6 = param_6 & 0xfffffeff | 0x200;
  }
  _Dst = (int *)sqlite3Malloc(0x2c);
  if (_Dst == (int *)0x0) {
LAB_00490f4c:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  memset(_Dst,0,0x2c);
  *(undefined1 *)(_Dst + 2) = 0;
  *_Dst = param_3;
  _Dst[7] = (int)_Dst;
  _Dst[8] = 1;
  if (((bVar14) || ((bVar13 && ((param_6 & 0x40) == 0)))) || ((param_6 & 0x20000) == 0)) {
LAB_004910e5:
    piVar7 = (int *)sqlite3Malloc(0x54);
    if ((((piVar7 != (int *)0x0) && (memset(piVar7,0,0x54), piVar7 != (int *)0x0)) &&
        (iVar8 = sqlite3PagerOpen(param_1,piVar7,(char *)param_2,0x4c,param_5,param_6,0x483ba0),
        iVar8 == 0)) && (iVar8 = pagerReadFileheader(*piVar7,100,local_6c), iVar8 == 0)) {
      *(byte *)(piVar7 + 4) = param_5;
      piVar7[1] = param_3;
      sqlite3PagerSetBusyhandler(*piVar7,lib_fn_471550,piVar7);
      _Dst[1] = (int)piVar7;
      piVar7[2] = 0;
      piVar7[3] = 0;
      if (*(char *)(*piVar7 + 0xd) != '\0') {
        *(ushort *)((int)piVar7 + 0x16) = *(ushort *)((int)piVar7 + 0x16) | 1;
      }
      uVar5 = (uint)local_5c * 0x100;
      puVar1 = (uint *)(piVar7 + 8);
      *puVar1 = uVar5;
      if (((uVar5 < 0x200) || (0x10000 < uVar5)) || ((uVar5 & uVar5 - 1) != 0)) {
        *puVar1 = 0;
        if ((param_2 != (byte *)0x0) && (!bVar13)) {
          *(undefined2 *)((int)piVar7 + 0x11) = 0;
        }
        local_58 = 0;
      }
      else {
        *(ushort *)((int)piVar7 + 0x16) = *(ushort *)((int)piVar7 + 0x16) | 2;
        iVar8 = sqlite3Get4byte(local_38);
        *(bool *)((int)piVar7 + 0x11) = iVar8 != 0;
        iVar8 = sqlite3Get4byte(local_2c);
        *(bool *)((int)piVar7 + 0x12) = iVar8 != 0;
      }
      iVar8 = sqlite3PagerSetPagesize(*piVar7,puVar1,(uint)local_58);
      if (iVar8 == 0) {
        piVar7[9] = *puVar1 - (uint)local_58;
        local_70 = 0;
        if (*(char *)((int)_Dst + 9) != '\0') {
          piVar7[0x10] = 1;
          if (DAT_00582acc == 0) {
            iVar8 = 0;
          }
          else {
            iVar8 = (*DAT_00582b10)(2);
            if (DAT_00582acc != 0) {
              iVar10 = (*DAT_00582b10)(0);
              piVar7[0xe] = iVar10;
              if (iVar10 == 0) {
                *(undefined1 *)(param_3 + 0x38) = 0;
                goto LAB_004913f8;
              }
            }
          }
          sqlite3_mutex_enter_ind(iVar8);
          piVar7[0x11] = (int)DAT_00583e80;
          DAT_00583e80 = piVar7;
          sqlite3_mutex_leave_ind(iVar8);
          goto LAB_004912bc;
        }
        goto LAB_0049138b;
      }
    }
  }
  else {
    iVar8 = *(int *)(param_1 + 8);
    pbVar4 = (byte *)sqlite3Malloc(iVar8 + 1);
    *(undefined1 *)((int)_Dst + 9) = 1;
    if (pbVar4 == (byte *)0x0) {
      sqlite3_free((int)_Dst);
      goto LAB_00490f4c;
    }
    if (bVar13) {
      uVar5 = sqlite3Strlen30((char *)param_2);
      memcpy(pbVar4,_Src,uVar5 + 1);
    }
    else {
      *pbVar4 = 0;
      local_70 = (**(code **)(param_1 + 0x24))(param_1,param_2,iVar8 + 1,pbVar4);
      if (local_70 != 0) {
        sqlite3_free((int)pbVar4);
        sqlite3_free((int)_Dst);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    if (DAT_00582acc == 0) {
      local_80 = 0;
      local_94 = 0;
    }
    else {
      local_80 = (*DAT_00582b10)(4);
      if (local_80 != 0) {
        (*DAT_00582b18)(local_80);
      }
      if (DAT_00582acc == 0) {
        local_94 = 0;
      }
      else {
        local_94 = (*DAT_00582b10)(2);
        if (local_94 != 0) {
          (*DAT_00582b18)(local_94);
        }
      }
    }
    piVar7 = DAT_00583e80;
    if (DAT_00583e80 != (int *)0x0) {
LAB_00491040:
      pbVar12 = (byte *)((int *)*piVar7)[0x24];
      pbVar6 = pbVar4;
      do {
        bVar2 = *pbVar6;
        bVar14 = bVar2 < *pbVar12;
        if (bVar2 != *pbVar12) {
LAB_00491070:
          uVar5 = -(uint)bVar14 | 1;
          goto LAB_00491075;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar6[1];
        bVar14 = bVar2 < pbVar12[1];
        if (bVar2 != pbVar12[1]) goto LAB_00491070;
        pbVar6 = pbVar6 + 2;
        pbVar12 = pbVar12 + 2;
      } while (bVar2 != 0);
      uVar5 = 0;
LAB_00491075:
      if ((uVar5 != 0) || (*(undefined **)*piVar7 != param_1)) goto LAB_00491080;
      iVar8 = *(int *)(param_3 + 0x14) + -1;
      if (-1 < iVar8) {
        piVar9 = (int *)(iVar8 * 0x10 + *(int *)(param_3 + 0x10) + 4);
        do {
          if ((*piVar9 != 0) && (*(int **)(*piVar9 + 4) == piVar7)) {
            if (local_94 != 0) {
              (*DAT_00582b20)(local_94);
            }
            if (local_80 != 0) {
              (*DAT_00582b20)(local_80);
            }
            sqlite3_free((int)pbVar4);
            sqlite3_free((int)_Dst);
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          piVar9 = piVar9 + -4;
          iVar8 = iVar8 + -1;
        } while (-1 < iVar8);
      }
      _Dst[1] = (int)piVar7;
      piVar7[0x10] = piVar7[0x10] + 1;
    }
LAB_004910bd:
    if (local_94 != 0) {
      (*DAT_00582b20)(local_94);
    }
    sqlite3_free((int)pbVar4);
    if (piVar7 == (int *)0x0) goto LAB_004910e5;
LAB_004912bc:
    if (*(char *)((int)_Dst + 9) != '\0') {
      iVar8 = 0;
      if (0 < *(int *)(param_3 + 0x14)) {
        piVar9 = (int *)(*(int *)(param_3 + 0x10) + 4);
LAB_004912e0:
        iVar10 = *piVar9;
        if ((iVar10 == 0) || (*(char *)(iVar10 + 9) == '\0')) goto LAB_004912ec;
        iVar8 = *(int *)(iVar10 + 0x18);
        while (iVar8 != 0) {
          iVar10 = *(int *)(iVar10 + 0x18);
          iVar8 = *(int *)(iVar10 + 0x18);
        }
        if ((uint)_Dst[1] < *(uint *)(iVar10 + 4)) {
          _Dst[5] = iVar10;
          _Dst[6] = 0;
          *(int **)(iVar10 + 0x18) = _Dst;
        }
        else {
          iVar8 = *(int *)(iVar10 + 0x14);
          while ((iVar8 != 0 &&
                 (iVar3 = *(int *)(iVar10 + 0x14), *(uint *)(iVar3 + 4) < (uint)_Dst[1]))) {
            iVar8 = *(int *)(iVar3 + 0x14);
            iVar10 = iVar3;
          }
          iVar8 = *(int *)(iVar10 + 0x14);
          _Dst[5] = iVar8;
          _Dst[6] = iVar10;
          if (iVar8 != 0) {
            *(int **)(iVar8 + 0x18) = _Dst;
          }
          *(int **)(iVar10 + 0x14) = _Dst;
        }
      }
    }
LAB_0049138b:
    *param_4 = _Dst;
    if (local_70 == 0) {
      iVar8 = _Dst[1];
      btree_enter(_Dst);
      if (*(char *)((int)_Dst + 9) != '\0') {
        piVar7 = _Dst + 3;
        *piVar7 = *piVar7 + -1;
        if (*piVar7 == 0) {
          if (*(int *)(_Dst[1] + 0x38) != 0) {
            (*DAT_00582b20)(*(int *)(_Dst[1] + 0x38));
          }
          *(undefined1 *)((int)_Dst + 10) = 0;
        }
      }
      if (*(int *)(iVar8 + 0x30) == 0) {
        iVar8 = *(int *)(*(int *)_Dst[1] + 0xb4);
        *(undefined4 *)(iVar8 + 0x10) = 2000;
        iVar8 = *(int *)(iVar8 + 0x28);
        if (iVar8 != 0) {
          (*DAT_00582b40)(iVar8,2000);
        }
      }
      goto LAB_00491426;
    }
  }
LAB_004913f8:
  if ((piVar7 != (int *)0x0) && ((uint *)*piVar7 != (uint *)0x0)) {
    sqlite3PagerClose((uint *)*piVar7);
  }
  sqlite3_free((int)piVar7);
  sqlite3_free((int)_Dst);
  *param_4 = 0;
LAB_00491426:
  if (local_80 != 0) {
    (*DAT_00582b20)(local_80);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
LAB_00491080:
  piVar7 = (int *)piVar7[0x11];
  if (piVar7 == (int *)0x0) goto LAB_004910bd;
  goto LAB_00491040;
LAB_004912ec:
  iVar8 = iVar8 + 1;
  piVar9 = piVar9 + 4;
  if (*(int *)(param_3 + 0x14) <= iVar8) goto LAB_0049138b;
  goto LAB_004912e0;
}




/* [AUDIT] proposed: sqlite3BtreeCommitPhaseOne  (confidence: high)
 * purpose: Btree enter; save cursors, on locked call trip-cursors; fetch & update page1 change counter; btree leave
 * vars: btree_enter=BtreeEnter; btree_saveCursorPages saveCursor; page1 via pcacheFetch 4a37e0
 */
/* Global::sqlite3BtreeCommitPhaseOne @ 004916b0 */

uint __cdecl sqlite3BtreeCommitPhaseOne(int *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *local_c;
  int *local_8;
  
  uVar6 = param_2;
  piVar5 = param_1;
  piVar8 = (int *)param_1[1];
  local_8 = piVar8;
  btree_enter(param_1);
  if (param_2 == 0) {
    for (uVar1 = piVar8[2]; uVar1 != 0; uVar1 = *(uint *)(uVar1 + 8)) {
      if ((*(char *)(uVar1 + 0x5b) == '\x01') &&
         (uVar6 = btree_saveCursorPages(uVar1), param_2 = uVar6, uVar6 != 0)) goto LAB_00491701;
    }
    uVar6 = 0;
    param_2 = uVar6;
  }
  else {
    param_2 = 0;
  }
LAB_00491701:
  if (uVar6 != 0) {
    sqlite3BtreeTripAllCursors(param_1,uVar6);
  }
  if ((char)param_1[2] != '\x02') goto LAB_004918cc;
  uVar6 = sqlite3PagerCommitPhaseTwo_or_sync((uint *)*piVar8);
  if (uVar6 != 0) {
    param_2 = uVar6;
  }
  puVar2 = (uint *)*piVar8;
  param_1 = (int *)puVar2[10];
  if ((param_1 == (int *)0x0) &&
     (param_1 = (int *)sqlite3PcacheFetch((int *)puVar2[0x2d],1,1,&local_c), iVar3 = DAT_00582bb8,
     param_1 == (int *)0x0)) {
    if (local_c[4] != 0) {
      puVar2[0x28] = puVar2[0x28] + 1;
      goto LAB_0049183a;
    }
    local_c[4] = puVar2;
    if (iVar3 / (int)puVar2[0x20] == 0) {
      sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
      param_1 = (int *)0xb;
LAB_004917e8:
      if ((*(byte *)(local_c + 6) & 2) != 0) {
        pcache_removeFromDirty((int)local_c);
      }
      iVar3 = local_c[7];
      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + -1;
      if (local_c[5] == 1) {
        *(undefined4 *)(iVar3 + 0x2c) = 0;
      }
      (*DAT_00582b4c)(*(undefined4 *)(iVar3 + 0x28),*local_c,1);
      goto LAB_0049181a;
    }
    if (((*(char *)((int)puVar2 + 0xe) == '\0') && (puVar2[6] != 0)) && (*(int *)puVar2[0xf] != 0))
    {
      puVar2[0x29] = puVar2[0x29] + 1;
      param_1 = (int *)pager_readDbPage((int)local_c);
      if (param_1 != (int *)0x0) goto LAB_004917e8;
    }
    else {
      if (puVar2[0x21] == 0) {
        param_1 = (int *)0xd;
        goto LAB_004917e8;
      }
      memset((void *)local_c[1],0,puVar2[0x20]);
    }
LAB_0049183a:
    piVar8 = local_8;
    iVar3 = local_c[2];
    iVar7 = local_c[1];
    *(int *)(iVar3 + 0x38) = iVar7;
    *(undefined4 **)(iVar3 + 0x44) = local_c;
    *(int **)(iVar3 + 0x34) = local_8;
    *(undefined4 *)(iVar3 + 0x48) = 1;
    *(undefined1 *)(iVar3 + 5) = 100;
    iVar7 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar7 + 0x1c),*(undefined1 *)(iVar7 + 0x1d)),
                              *(undefined1 *)(iVar7 + 0x1e)),*(undefined1 *)(iVar7 + 0x1f));
    if (iVar7 == 0) {
      iVar7 = *(int *)(*local_8 + 0x18);
    }
    local_8[0xb] = iVar7;
    puVar4 = *(undefined4 **)(iVar3 + 0x44);
    if (puVar4 != (undefined4 *)0x0) {
      puVar2 = (uint *)puVar4[4];
      sqlite3PcacheRelease(puVar4);
      if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
        pcache_releasePage(puVar2);
      }
    }
  }
  else {
LAB_0049181a:
    if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar2);
    }
    local_c = (undefined4 *)0x0;
    piVar8 = local_8;
    if (param_1 == (int *)0x0) goto LAB_0049183a;
  }
  *(undefined1 *)((int)piVar8 + 0x13) = 1;
LAB_004918cc:
  btree_closeCursor(piVar5);
  if (*(char *)((int)piVar5 + 9) != '\0') {
    piVar8 = piVar5 + 3;
    *piVar8 = *piVar8 + -1;
    if (*piVar8 == 0) {
      if (*(int *)(piVar5[1] + 0x38) != 0) {
        (*DAT_00582b20)(*(int *)(piVar5[1] + 0x38));
      }
      *(undefined1 *)((int)piVar5 + 10) = 0;
    }
  }
  return param_2;
}




/* [AUDIT] proposed: btreeCheckReadConflicts  (confidence: med)
 * purpose: Under btree mutex, scan cursors/locks (iVar1+0x48/0x4c/0x16) and return SQLITE_LOCKED(0x106) on conflict
 * vars: iVar1+0x48 lock list; +0x16 flags bit0x20; returns 0x106
 */
/* Global::btreeCheckReadConflicts @ 004919c0 */

undefined4 __cdecl btreeCheckReadConflicts(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  btree_enter(param_1);
  iVar1 = param_1[1];
  if (*(char *)((int)param_1 + 9) != '\0') {
    if ((*(undefined4 **)(iVar1 + 0x4c) != param_1) && ((*(byte *)(iVar1 + 0x16) & 0x20) != 0)) {
LAB_004919e6:
      uVar3 = 0x106;
      goto LAB_00491a0d;
    }
    for (piVar2 = *(int **)(iVar1 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
      if ((((undefined4 *)*piVar2 != param_1) && (piVar2[1] == 1)) && ((char)piVar2[2] != '\x01'))
      goto LAB_004919e6;
    }
  }
  uVar3 = 0;
LAB_00491a0d:
  if (*(char *)((int)param_1 + 9) != '\0') {
    piVar2 = param_1 + 3;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (*(int *)(iVar1 + 0x38) != 0) {
        (*DAT_00582b20)(*(int *)(iVar1 + 0x38));
      }
      *(undefined1 *)((int)param_1 + 10) = 0;
    }
  }
  return uVar3;
}




/* [AUDIT] proposed: sqlite3BtreeTripAllCursors  (confidence: high)
 * purpose: Set all cursors on BtShared to fault state 3 with error code, drop cached pages
 * vars: iVar1+8 cursor list; +0x5b state=3; +0x54 errcode=param_2
 */
/* Global::sqlite3BtreeTripAllCursors @ 00491f60 */

void __cdecl sqlite3BtreeTripAllCursors(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  
  if (param_1 != (undefined4 *)0x0) {
    btree_enter(param_1);
    for (iVar1 = *(int *)(param_1[1] + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      sqlite3_free(*(int *)(iVar1 + 0x50));
      *(undefined4 *)(iVar1 + 0x54) = param_2;
      iVar4 = 0;
      *(undefined4 *)(iVar1 + 0x50) = 0;
      *(undefined1 *)(iVar1 + 0x5b) = 3;
      if (*(ushort *)(iVar1 + 0x5e) < 0x8000) {
        piVar5 = (int *)(iVar1 + 0x88);
        do {
          if ((*piVar5 != 0) &&
             (puVar2 = *(undefined4 **)(*piVar5 + 0x44), puVar2 != (undefined4 *)0x0)) {
            puVar3 = (uint *)puVar2[4];
            sqlite3PcacheRelease(puVar2);
            if (*(int *)(puVar3[0x2d] + 0xc) == 0) {
              pcache_releasePage(puVar3);
            }
          }
          *piVar5 = 0;
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar4 <= *(short *)(iVar1 + 0x5e));
      }
    }
    if (*(char *)((int)param_1 + 9) != '\0') {
      piVar5 = param_1 + 3;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 == 0) {
        if (*(int *)(param_1[1] + 0x38) != 0) {
          (*DAT_00582b20)(*(int *)(param_1[1] + 0x38));
        }
        *(undefined1 *)((int)param_1 + 10) = 0;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3CantopenError  (confidence: high)
 * purpose: Report SQLITE_CANTOPEN(0xe) via sqlite3ReportError and return 0xe
 * vars: string 'cannot open file at line %d'
 */
/* Global::sqlite3CantopenError @ 004920e0 */

undefined4 sqlite3CantopenError(void)

{
  sqlite3_log(0xe,"cannot open file at line %d of [%.10s]");
  return 0xe;
}




/* [AUDIT] proposed: pcacheCleanupCursorSpace  (confidence: med)
 * purpose: Free per-cursor overflow/aOverflow allocations, adjusting pcache memory counters or free list
 * vars: param_1[0x24] count; [0x25] array; [0x7c] byte-counter; [0x41/0x42] page bounds
 */
/* Global::pcacheCleanupCursorSpace @ 00492650 */

void __cdecl pcacheCleanupCursorSpace(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[0x24]) {
    do {
      (**(code **)(*param_1 + 0x34))(*param_1,*(undefined4 *)(param_1[0x25] + iVar2 * 4));
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[0x24]);
  }
  piVar1 = (int *)param_1[0x25];
  if (param_1[0x7c] != 0) {
    if (((piVar1 != (int *)0x0) && ((int *)param_1[0x41] <= piVar1)) &&
       (piVar1 < (int *)param_1[0x42])) {
      *(int *)param_1[0x7c] = *(int *)param_1[0x7c] + (uint)*(ushort *)(param_1 + 0x3a);
      return;
    }
    iVar2 = (*DAT_00582af0._4_4_)(piVar1);
    *(int *)param_1[0x7c] = *(int *)param_1[0x7c] + iVar2;
    return;
  }
  if (((piVar1 != (int *)0x0) && ((int *)param_1[0x41] <= piVar1)) &&
     (piVar1 < (int *)param_1[0x42])) {
    *piVar1 = param_1[0x40];
    param_1[0x3b] = param_1[0x3b] + -1;
    param_1[0x40] = (int)piVar1;
    return;
  }
  sqlite3_free((int)piVar1);
  return;
}




/* [AUDIT] proposed: pcacheClearOverflowList  (confidence: med)
 * purpose: Walk cursor overflow-cell list at +0x1d8, returning each buffer to page free-list or heap
 * vars: +0x1d8 list head; +0x100 free list; +0x1f0 memdb flag; +0xe8 pagesize
 */
/* Global::pcacheClearOverflowList @ 00492710 */

void __cdecl pcacheClearOverflowList(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1d8);
  while (iVar2 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x1d8);
    *(undefined4 *)(param_1 + 0x1d8) = puVar1[4];
    if (*(int *)(param_1 + 0x1f0) == 0) {
      if ((puVar1 < *(undefined4 **)(param_1 + 0x104)) ||
         (*(undefined4 **)(param_1 + 0x108) <= puVar1)) {
        sqlite3_free((int)puVar1);
      }
      else {
        *puVar1 = *(undefined4 *)(param_1 + 0x100);
        *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + -1;
        *(undefined4 **)(param_1 + 0x100) = puVar1;
      }
    }
    else if ((puVar1 < *(undefined4 **)(param_1 + 0x104)) ||
            (*(undefined4 **)(param_1 + 0x108) <= puVar1)) {
      iVar2 = (*DAT_00582af0._4_4_)(puVar1);
      **(int **)(param_1 + 0x1f0) = **(int **)(param_1 + 0x1f0) + iVar2;
    }
    else {
      **(int **)(param_1 + 0x1f0) = **(int **)(param_1 + 0x1f0) + (uint)*(ushort *)(param_1 + 0xe8);
    }
    iVar2 = *(int *)(param_1 + 0x1d8);
  }
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  return;
}




/* [AUDIT] proposed: pcacheCompactPageArray  (confidence: med)
 * purpose: Compact a Btree cursor/page array (+0x10,count +0x14): drop refcount-0 entries, inline-store when <3
 * vars: stride 0x10; +0x1b8 inline slot; +0x100 free list; sqlite3PageFree freePage
 */
/* Global::pcacheCompactPageArray @ 004934c0 */

void __cdecl pcacheCompactPageArray(int param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  iVar5 = param_1;
  iVar8 = 2;
  iVar7 = 2;
  if (2 < *(int *)(param_1 + 0x14)) {
    param_1 = 0x20;
    local_8 = 0x20;
    do {
      iVar2 = *(int *)(iVar5 + 0x10);
      if (*(int *)(local_8 + 4 + iVar2) == 0) {
        puVar3 = *(undefined4 **)(local_8 + iVar2);
        if (*(int *)(iVar5 + 0x1f0) == 0) {
          if (((puVar3 == (undefined4 *)0x0) || (puVar3 < *(undefined4 **)(iVar5 + 0x104))) ||
             (*(undefined4 **)(iVar5 + 0x108) <= puVar3)) {
            sqlite3_free((int)puVar3);
          }
          else {
            *puVar3 = *(undefined4 *)(iVar5 + 0x100);
            *(int *)(iVar5 + 0xec) = *(int *)(iVar5 + 0xec) + -1;
            *(undefined4 **)(iVar5 + 0x100) = puVar3;
          }
        }
        else if (((puVar3 == (undefined4 *)0x0) || (puVar3 < *(undefined4 **)(iVar5 + 0x104))) ||
                (*(undefined4 **)(iVar5 + 0x108) <= puVar3)) {
          iVar6 = (*DAT_00582af0._4_4_)(puVar3);
          **(int **)(iVar5 + 0x1f0) = **(int **)(iVar5 + 0x1f0) + iVar6;
        }
        else {
          **(int **)(iVar5 + 0x1f0) = **(int **)(iVar5 + 0x1f0) + (uint)*(ushort *)(iVar5 + 0xe8);
        }
        *(undefined4 *)(local_8 + iVar2) = 0;
      }
      else {
        if (iVar8 < iVar7) {
          *(undefined8 *)(param_1 + iVar2) = *(undefined8 *)(local_8 + iVar2);
          *(undefined8 *)(param_1 + 8 + iVar2) = *(undefined8 *)(local_8 + 8 + iVar2);
        }
        iVar8 = iVar8 + 1;
        param_1 = param_1 + 0x10;
      }
      iVar7 = iVar7 + 1;
      local_8 = local_8 + 0x10;
    } while (iVar7 < *(int *)(iVar5 + 0x14));
  }
  memset((void *)(iVar8 * 0x10 + *(int *)(iVar5 + 0x10)),0,(*(int *)(iVar5 + 0x14) - iVar8) * 0x10);
  *(int *)(iVar5 + 0x14) = iVar8;
  if (iVar8 < 3) {
    puVar4 = *(undefined8 **)(iVar5 + 0x10);
    puVar1 = (undefined8 *)(iVar5 + 0x1b8);
    if (puVar4 != puVar1) {
      *puVar1 = *puVar4;
      *(undefined8 *)(iVar5 + 0x1c0) = puVar4[1];
      *(undefined8 *)(iVar5 + 0x1c8) = puVar4[2];
      *(undefined8 *)(iVar5 + 0x1d0) = puVar4[3];
      sqlite3PageFree(iVar5,(undefined4 *)puVar4);
      *(undefined8 **)(iVar5 + 0x10) = puVar1;
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3CorruptError  (confidence: high)
 * purpose: Report SQLITE_CORRUPT(0xb) via sqlite3ReportError and return 0xb
 * vars: 'database corruption at line %d'
 */
/* Global::sqlite3CorruptError @ 00493af0 */

undefined4 sqlite3CorruptError(void)

{
  sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
  return 0xb;
}




/* [AUDIT] proposed: sqlite3CreateFunc  (confidence: high)
 * purpose: Register/replace a user SQL function (handles ANY-encoding fanout), guarding active statements
 * vars: sqlite3FindFunction findFunction; param_4 encoding 4/5 special; 'unable to delete/modify user-function'
 */
/* Global::sqlite3CreateFunc @ 00493f20 */

int __cdecl
sqlite3CreateFunc(int param_1,byte *param_2,int param_3,uint param_4,undefined4 param_5,int param_6,
            int param_7,int param_8,int *param_9)

{
  uint uVar1;
  short *psVar2;
  int iVar3;
  byte *extraout_EDX;
  byte *pbVar4;
  uint extraout_EDX_00;
  
  if (param_2 == (byte *)0x0) goto LAB_00494001;
  if (param_6 == 0) {
    if (param_8 == 0) goto LAB_00493f46;
    if (param_7 == 0) goto LAB_00494001;
  }
  else {
    if (param_8 != 0) goto LAB_00494001;
LAB_00493f46:
    if (param_7 != 0) goto LAB_00494001;
  }
  if ((param_3 + 1U < 0x81) && (uVar1 = sqlite3Strlen30((char *)param_2), (int)uVar1 < 0x100)) {
    pbVar4 = extraout_EDX;
    if (param_4 == 4) {
      param_4 = 2;
    }
    else if (param_4 == 5) {
      iVar3 = sqlite3CreateFunc(param_1,extraout_EDX,param_3,1,param_5,param_6,param_7,param_8,param_9);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = sqlite3CreateFunc(param_1,param_2,param_3,2,param_5,param_6,param_7,param_8,param_9);
      if (iVar3 != 0) {
        return iVar3;
      }
      param_4 = 3;
      pbVar4 = param_2;
    }
    psVar2 = sqlite3FindFunction(param_1,pbVar4,uVar1,param_3,(byte)param_4,'\0');
    if (((psVar2 != (short *)0x0) && (*(byte *)(psVar2 + 1) == param_4)) && (*psVar2 == param_3)) {
      if (*(int *)(param_1 + 0x84) != 0) {
        sqlite3ErrorWithMsg(param_1,5,
                     (byte *)"unable to delete/modify user-function due to active statements");
        return 5;
      }
      sqlite3ExpirePreparedStatements(param_1);
      param_4 = extraout_EDX_00;
    }
    psVar2 = sqlite3FindFunction(param_1,param_2,uVar1,param_3,(byte)param_4,'\x01');
    if (psVar2 == (short *)0x0) {
      return 7;
    }
    vdbe_freeAuxRef(param_1,(int)psVar2);
    if (param_9 != (int *)0x0) {
      *param_9 = *param_9 + 1;
    }
    *(int **)(psVar2 + 0x10) = param_9;
    *(int *)(psVar2 + 6) = param_6;
    *(int *)(psVar2 + 10) = param_8;
    *(undefined4 *)(psVar2 + 2) = param_5;
    *(int *)(psVar2 + 8) = param_7;
    *psVar2 = (short)param_3;
    *(undefined1 *)((int)psVar2 + 3) = 0;
    return 0;
  }
LAB_00494001:
  sqlite3_log(0x15,"misuse at line %d of [%.10s]");
  return 0x15;
}




/* [AUDIT] proposed: sqlite3PageFree  (confidence: high)
 * purpose: Return a page/allocation to pager page-cache free list or heap, updating memdb counters
 * vars: +0x1f0 memdb; +0x104/0x108 page bounds; +0x100 free list; +0xe8 pagesize
 */
/* Global::sqlite3PageFree @ 00494b00 */

void __cdecl sqlite3PageFree(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1f0) != 0) {
      if (((param_2 != (undefined4 *)0x0) && (*(undefined4 **)(param_1 + 0x104) <= param_2)) &&
         (param_2 < *(undefined4 **)(param_1 + 0x108))) {
        **(int **)(param_1 + 0x1f0) =
             **(int **)(param_1 + 0x1f0) + (uint)*(ushort *)(param_1 + 0xe8);
        return;
      }
      iVar1 = (*DAT_00582af0._4_4_)(param_2);
      **(int **)(param_1 + 0x1f0) = **(int **)(param_1 + 0x1f0) + iVar1;
      return;
    }
    if (((param_2 != (undefined4 *)0x0) && (*(undefined4 **)(param_1 + 0x104) <= param_2)) &&
       (param_2 < *(undefined4 **)(param_1 + 0x108))) {
      *param_2 = *(undefined4 *)(param_1 + 0x100);
      *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + -1;
      *(undefined4 **)(param_1 + 0x100) = param_2;
      return;
    }
  }
  sqlite3_free((int)param_2);
  return;
}




/* [AUDIT] proposed: sqlite3PageMalloc  (confidence: high)
 * purpose: Allocate from pager scratch/page pool (+0x100 free list) or fall back to sqlite3Malloc; set OOM flag
 * vars: +0xea useAlloc; +0xe8 pagesize; +0x38 mallocFailed; +0xf0-0xfc stats
 */
/* Global::sqlite3PageMalloc @ 00494b90 */

undefined4 * __cdecl sqlite3PageMalloc(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x38) != '\0') {
      return (undefined4 *)0x0;
    }
    if (*(char *)(param_1 + 0xea) != '\0') {
      if ((int)(uint)*(ushort *)(param_1 + 0xe8) < param_2) {
        *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
      }
      else {
        puVar2 = *(undefined4 **)(param_1 + 0x100);
        if (puVar2 != (undefined4 *)0x0) {
          uVar1 = *puVar2;
          *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
          *(undefined4 *)(param_1 + 0x100) = uVar1;
          *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
          if (*(int *)(param_1 + 0xf0) < *(int *)(param_1 + 0xec)) {
            *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xec);
          }
          return puVar2;
        }
        *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
      }
    }
  }
  puVar2 = (undefined4 *)sqlite3Malloc(param_2);
  if ((puVar2 == (undefined4 *)0x0) && (param_1 != 0)) {
    *(undefined1 *)(param_1 + 0x38) = 1;
  }
  return puVar2;
}




/* [AUDIT] proposed: sqlite3PageRealloc  (confidence: high)
 * purpose: Resize a pager-managed allocation, copying if moving between pool and heap
 * vars: +0xe8 pagesize; +0x38 OOM; sqlite3PageMalloc/00494b00
 */
/* Global::sqlite3PageRealloc @ 00494cf0 */

undefined4 * __cdecl sqlite3PageRealloc(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *_Dst;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if (*(char *)(param_1 + 0x38) == '\0') {
    if (param_2 == (undefined4 *)0x0) {
      puVar2 = sqlite3PageMalloc(param_1,param_3);
      return puVar2;
    }
    if ((param_2 < *(undefined4 **)(param_1 + 0x104)) ||
       (*(undefined4 **)(param_1 + 0x108) <= param_2)) {
      iVar1 = sqlite3_initialize();
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + 0x38) = 1;
        return (undefined4 *)0x0;
      }
      puVar2 = (undefined4 *)sqlite3Realloc((int)param_2,param_3);
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined1 *)(param_1 + 0x38) = 1;
      }
    }
    else {
      if (param_3 <= (int)(uint)*(ushort *)(param_1 + 0xe8)) {
        return param_2;
      }
      _Dst = sqlite3PageMalloc(param_1,param_3);
      puVar2 = (undefined4 *)0x0;
      if (_Dst != (undefined4 *)0x0) {
        memcpy(_Dst,param_2,(uint)*(ushort *)(param_1 + 0xe8));
        sqlite3PageFree(param_1,param_2);
        return _Dst;
      }
    }
  }
  return puVar2;
}




/* [AUDIT] proposed: sqlite3PageStrdup  (confidence: high)
 * purpose: Duplicate a C string into a pager-managed allocation (strlen + PageMalloc + memcpy)
 * vars: _Size=strlen+1; sqlite3PageMalloc
 */
/* Global::sqlite3PageStrdup @ 00494db0 */

undefined4 * __cdecl sqlite3PageStrdup(int param_1,char *param_2)

{
  size_t _Size;
  char cVar1;
  char *pcVar2;
  undefined4 *_Dst;
  
  if (param_2 != (char *)0x0) {
    cVar1 = *param_2;
    pcVar2 = param_2;
    while (cVar1 != '\0') {
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    }
    _Size = ((int)pcVar2 - (int)param_2 & 0x3fffffffU) + 1;
    _Dst = sqlite3PageMalloc(param_1,_Size);
    if (_Dst != (undefined4 *)0x0) {
      memcpy(_Dst,param_2,_Size);
    }
    return _Dst;
  }
  return (undefined4 *)0x0;
}




/* [AUDIT] proposed: sqlite3DeleteTable  (confidence: high)
 * purpose: Free a Table: remove columns from function/fkey hash, delete FKs, indices, ExprList defaults, then free
 * vars: param_2[2] column list; hash at puVar5[6]+0x18; sqlite3DeleteTableAux,00499060,004bce20
 */
/* Global::sqlite3DeleteTable @ 00495300 */

void __cdecl sqlite3DeleteTable(int param_1,undefined4 *param_2)

{
  short *psVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int *piVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_2 != (undefined4 *)0x0) {
    if ((param_1 == 0) || (*(int *)(param_1 + 0x1f0) == 0)) {
      psVar1 = (short *)(param_2 + 10);
      *psVar1 = *psVar1 + -1;
      if (*psVar1 != 0) {
        return;
      }
    }
    puVar5 = (undefined4 *)param_2[2];
    while (puVar5 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)puVar5[5];
      if ((param_1 == 0) || (*(int *)(param_1 + 0x1f0) == 0)) {
        pbVar4 = (byte *)*puVar5;
        uVar9 = 0;
        if (pbVar4 != (byte *)0x0) {
          bVar2 = *pbVar4;
          pbVar8 = pbVar4;
          while (bVar2 != 0) {
            pbVar8 = pbVar8 + 1;
            bVar2 = *pbVar8;
          }
          uVar9 = (int)pbVar8 - (int)pbVar4 & 0x3fffffff;
        }
        puVar6 = (uint *)(puVar5[6] + 0x18);
        if (*puVar6 == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = 0;
          pbVar8 = pbVar4;
          uVar11 = uVar9;
          if (uVar9 != 0) {
            do {
              uVar11 = uVar11 - 1;
              uVar10 = uVar10 ^ (uint)(byte)(&DAT_00569620)[*pbVar8] ^ uVar10 * 8;
              pbVar8 = pbVar8 + 1;
            } while (0 < (int)uVar11);
          }
          uVar10 = uVar10 % *puVar6;
        }
        piVar7 = hash_find((int)puVar6,pbVar4,uVar9,uVar10);
        if (piVar7 != (int *)0x0) {
          hash_removeElement(puVar6,piVar7,uVar10);
        }
      }
      sqlite3PageFree(param_1,(undefined4 *)puVar5[4]);
      sqlite3PageFree(param_1,puVar5);
      puVar5 = puVar3;
    }
    sqlite3DeleteTableAux(param_1,(int)param_2);
    sqlite3WithDelete_or_AggFree(param_1,(int)param_2);
    sqlite3PageFree(param_1,(undefined4 *)*param_2);
    sqlite3PageFree(param_1,(undefined4 *)param_2[5]);
    puVar5 = (undefined4 *)param_2[3];
    if (puVar5 != (undefined4 *)0x0) {
      sqlite3_exprDelete(param_1,puVar5);
      sqlite3PageFree(param_1,puVar5);
    }
    sqlite3ExprListDelete(param_1,(int *)param_2[6]);
    sqlite3AggInfoDelete_or_columns(param_1,(int)param_2);
    sqlite3PageFree(param_1,param_2);
  }
  return;
}




/* [AUDIT] proposed: sqlite3SelectDelete  (confidence: high)
 * purpose: Free a Select chain (pPrior at [8]): ExprLists, SrcList(0x2c), Where/Having/OrderBy/GroupBy exprs
 * vars: param_2[8]=pPrior; [2]=pSrc; recursive expr/list frees
 */
/* Global::sqlite3SelectDelete @ 00495480 */

void __cdecl sqlite3SelectDelete(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  while (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)param_2[8];
    sqlite3ExprDelete(param_1,(undefined4 *)param_2[5]);
    sqlite3ExprListDelete(param_1,(int *)param_2[6]);
    puVar2 = (undefined4 *)param_2[2];
    if (puVar2 != (undefined4 *)0x0) {
      sqlite3ExprListDelete(param_1,(int *)*puVar2);
      sqlite3SrcListDelete(param_1,(short *)puVar2[10]);
      sqlite3ExprDelete(param_1,(undefined4 *)puVar2[0xb]);
      sqlite3ExprListDelete(param_1,(int *)puVar2[0xc]);
      sqlite3ExprDelete(param_1,(undefined4 *)puVar2[0xd]);
      sqlite3ExprListDelete(param_1,(int *)puVar2[0xe]);
      sqlite3WindowListDelete_or_Cte(param_1,(undefined4 *)puVar2[0xf]);
      sqlite3ExprDelete(param_1,(undefined4 *)puVar2[0x12]);
      sqlite3ExprDelete(param_1,(undefined4 *)puVar2[0x13]);
      sqlite3PageFree(param_1,puVar2);
    }
    sqlite3IdListDelete(param_1,(int *)param_2[7]);
    sqlite3PageFree(param_1,param_2);
    param_2 = puVar1;
  }
  return;
}




/* [AUDIT] proposed: sqlite3ErrorWithMsg  (confidence: high)
 * purpose: Set db error code (+0x2c) and formatted message on connection, allocating/formatting error Mem
 * vars: +0xd4 pErr Mem; sqlite3VXPrintf_toAccum vprintf; param_3 fmt
 */
/* Global::sqlite3ErrorWithMsg @ 004961f0 */

void __cdecl sqlite3ErrorWithMsg(int param_1,undefined4 param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xd4) == 0) {
      iVar2 = sqlite3ValueNew(param_1);
      *(int *)(param_1 + 0xd4) = iVar2;
      if (iVar2 == 0) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x2c) = param_2;
    if (param_3 == (byte *)0x0) {
      iVar2 = *(int *)(param_1 + 0xd4);
      if (iVar2 != 0) {
        if ((*(byte *)(iVar2 + 0x1c) & 0x40) != 0) {
          piVar1 = *(int **)(iVar2 + 0x10);
          piVar1[1] = *(int *)(*piVar1 + 0xa4);
          *(int **)(*piVar1 + 0xa4) = piVar1;
        }
        if ((*(byte *)(iVar2 + 0x1c) & 0x20) != 0) {
          sqlite3ExprListClearList(*(undefined4 **)(iVar2 + 0x10));
        }
        *(ushort *)(iVar2 + 0x1c) = *(ushort *)(iVar2 + 0x1c) & 0xbe01 | 1;
        *(undefined1 *)(iVar2 + 0x1e) = 5;
      }
    }
    else {
      pvVar3 = (void *)sqlite3VXPrintf_toAccum(param_1,param_3,(double *)&stack0x00000010);
      if (*(int **)(param_1 + 0xd4) != (int *)0x0) {
        sqlite3VdbeMemSetStr(*(int **)(param_1 + 0xd4),pvVar3,0xffffffff,'\x01',lib_fn_4a0570);
        return;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3ExpirePreparedStatements  (confidence: high)
 * purpose: Mark every VDBE on db (list at +4, next +0x3c) as expired by setting flag bit 0x20 at +0x60
 * vars: iterates prepared-statement list
 */
/* Global::sqlite3ExpirePreparedStatements @ 00496370 */

void __cdecl sqlite3ExpirePreparedStatements(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
    *(uint *)(iVar1 + 0x60) = *(uint *)(iVar1 + 0x60) | 0x20;
  }
  return;
}




/* [AUDIT] proposed: sqlite3ExprDelete  (confidence: high)
 * purpose: Recursively free an Expr node (left [2]/right [3]), its token string, ExprList/Select subtree
 * vars: flags at +2 (0x4000 static,0x2000,0x800,0x8000); +0x22 has-token
 */
/* Global::sqlite3ExprDelete @ 00498790 */

void __cdecl sqlite3ExprDelete(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    if ((*(ushort *)((int)param_2 + 2) & 0x4000) == 0) {
      sqlite3ExprDelete(param_1,(undefined4 *)param_2[2]);
      sqlite3ExprDelete(param_1,(undefined4 *)param_2[3]);
      if (((*(ushort *)((int)param_2 + 2) & 0x2000) == 0) &&
         ((*(byte *)((int)param_2 + 0x22) & 1) != 0)) {
        sqlite3PageFree(param_1,(undefined4 *)param_2[1]);
      }
      if ((*(ushort *)((int)param_2 + 2) & 0x800) == 0) {
        sqlite3ExprListDelete(param_1,(int *)param_2[4]);
      }
      else {
        puVar1 = (undefined4 *)param_2[4];
        if (puVar1 != (undefined4 *)0x0) {
          sqlite3_exprDelete(param_1,puVar1);
          sqlite3PageFree(param_1,puVar1);
        }
      }
    }
    if ((*(ushort *)((int)param_2 + 2) & 0x8000) == 0) {
      sqlite3PageFree(param_1,param_2);
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3ExprListDelete  (confidence: high)
 * purpose: Free an ExprList: iterate items (stride 5), delete each Expr and span string, then free array
 * vars: param_2[2] items; *param_2 count; stride 20 bytes
 */
/* Global::sqlite3ExprListDelete @ 00499060 */

void __cdecl sqlite3ExprListDelete(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_2 != (int *)0x0) {
    iVar3 = 0;
    puVar4 = (undefined4 *)param_2[2];
    if (0 < *param_2) {
      do {
        sqlite3ExprDelete(param_1,(undefined4 *)*puVar4);
        puVar1 = (undefined4 *)puVar4[1];
        if (param_1 == 0) {
LAB_004990ff:
          sqlite3_free((int)puVar1);
        }
        else if (*(int *)(param_1 + 0x1f0) == 0) {
          if (((puVar1 == (undefined4 *)0x0) || (puVar1 < *(undefined4 **)(param_1 + 0x104))) ||
             (*(undefined4 **)(param_1 + 0x108) <= puVar1)) goto LAB_004990ff;
          *puVar1 = *(undefined4 *)(param_1 + 0x100);
          *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + -1;
          *(undefined4 **)(param_1 + 0x100) = puVar1;
        }
        else if (((puVar1 == (undefined4 *)0x0) || (puVar1 < *(undefined4 **)(param_1 + 0x104))) ||
                (*(undefined4 **)(param_1 + 0x108) <= puVar1)) {
          iVar2 = (*DAT_00582af0._4_4_)(puVar1);
          **(int **)(param_1 + 0x1f0) = **(int **)(param_1 + 0x1f0) + iVar2;
        }
        else {
          **(int **)(param_1 + 0x1f0) =
               **(int **)(param_1 + 0x1f0) + (uint)*(ushort *)(param_1 + 0xe8);
        }
        sqlite3PageFree(param_1,(undefined4 *)puVar4[2]);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 5;
      } while (iVar3 < *param_2);
    }
    sqlite3PageFree(param_1,(undefined4 *)param_2[2]);
    sqlite3PageFree(param_1,param_2);
  }
  return;
}




/* [AUDIT] proposed: sqlite3FindDbFunction  (confidence: med)
 * purpose: Locate function/column struct: use table lookup (sqlite3_findCollSeq) then index by param_2*5 slot
 * vars: returns piVar1 + param_2*5 - 5
 */
/* Global::sqlite3FindDbFunction @ 00499500 */

int * __cdecl sqlite3FindDbFunction(int param_1,byte param_2,byte *param_3,int param_4)

{
  int *piVar1;
  
  if (param_3 == (byte *)0x0) {
    piVar1 = *(int **)(param_1 + 8);
  }
  else {
    piVar1 = sqlite3_findCollSeq(param_1,param_3,param_4);
  }
  if (piVar1 != (int *)0x0) {
    return piVar1 + (uint)param_2 * 5 + -5;
  }
  return (int *)0x0;
}




/* [AUDIT] proposed: sqlite3FindFunction  (confidence: high)
 * purpose: Find best-matching FuncDef in per-db and global hash by name/nArg/encoding; optionally create new
 * vars: hash bucket via DAT_00569620 xlat; scoring uVar3; global hash 0x583f68; create path allocs size+0x25
 */
/* Global::sqlite3FindFunction @ 004995c0 */

short * __cdecl
sqlite3FindFunction(int param_1,byte *param_2,size_t param_3,int param_4,byte param_5,char param_6)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short *_Dst;
  uint local_8;
  
  iVar4 = (int)((byte)(&DAT_00569620)[*param_2] + param_3) % 0x17;
  uVar5 = 0;
  _Dst = (short *)0x0;
  local_8 = 0;
  for (psVar2 = (short *)hash_findEntry(param_1 + 0x140,iVar4,param_2,param_3); psVar2 != (short *)0x0
      ; psVar2 = *(short **)(psVar2 + 4)) {
    if (param_4 == -2) {
      if ((*(int *)(psVar2 + 6) == 0) && (*(int *)(psVar2 + 8) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 6;
      }
    }
    else {
      sVar1 = *psVar2;
      if ((sVar1 == param_4) || (sVar1 < 0)) {
        uVar3 = 1;
        if (sVar1 == param_4) {
          uVar3 = 4;
        }
        uVar5 = local_8;
        if (param_5 == *(byte *)(psVar2 + 1)) {
          uVar3 = uVar3 + 2;
        }
        else if ((*(byte *)(psVar2 + 1) & param_5 & 2) != 0) {
          uVar3 = uVar3 + 1;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    if (uVar5 < uVar3) {
      uVar5 = uVar3;
      _Dst = psVar2;
      local_8 = uVar3;
    }
  }
  if (param_6 == '\0') {
    if ((_Dst == (short *)0x0) || ((*(uint *)(param_1 + 0x18) & 0x100000) != 0)) {
      uVar5 = 0;
      for (psVar2 = (short *)hash_findEntry(0x583f68,iVar4,param_2,param_3); psVar2 != (short *)0x0;
          psVar2 = *(short **)(psVar2 + 4)) {
        if (param_4 == -2) {
          if ((*(int *)(psVar2 + 6) == 0) && (*(int *)(psVar2 + 8) == 0)) {
            uVar3 = 0;
          }
          else {
            uVar3 = 6;
          }
        }
        else {
          sVar1 = *psVar2;
          if ((sVar1 == param_4) || (sVar1 < 0)) {
            uVar3 = 1;
            if (sVar1 == param_4) {
              uVar3 = 4;
            }
            if (param_5 == *(byte *)(psVar2 + 1)) {
              uVar3 = uVar3 + 2;
            }
            else if ((*(byte *)(psVar2 + 1) & param_5 & 2) != 0) {
              uVar3 = uVar3 + 1;
            }
          }
          else {
            uVar3 = 0;
          }
        }
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
          _Dst = psVar2;
        }
      }
    }
  }
  else if (uVar5 < 6) {
    _Dst = (short *)sqlite3PageMalloc(param_1,param_3 + 0x25);
    if (_Dst == (short *)0x0) {
      return (short *)0x0;
    }
    memset(_Dst,0,param_3 + 0x25);
    if (_Dst == (short *)0x0) {
      return (short *)0x0;
    }
    *(short **)(_Dst + 0xc) = _Dst + 0x12;
    *_Dst = (short)param_4;
    *(byte *)(_Dst + 1) = param_5;
    memcpy(_Dst + 0x12,param_2,param_3);
    *(undefined1 *)(param_3 + *(int *)(_Dst + 0xc)) = 0;
    sqlite3HashInsertElement(param_1 + 0x140,(int)_Dst);
  }
  if ((_Dst != (short *)0x0) &&
     (((*(int *)(_Dst + 8) != 0 || (*(int *)(_Dst + 6) != 0)) || (param_6 != '\0')))) {
    return _Dst;
  }
  return (short *)0x0;
}




/* [AUDIT] proposed: sqlite3DeleteTableAux  (confidence: med)
 * purpose: Delete Table auxiliaries: unhash columns, free trigger-step-like nodes ([7]/[8]) exprs and select subtrees
 * vars: param_2+0x10 column list; hash at (+0x40)+0x38
 */
/* Global::sqlite3DeleteTableAux @ 0049ab00 */

void __cdecl sqlite3DeleteTableAux(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  
  puVar6 = *(undefined4 **)(param_2 + 0x10);
  while (puVar6 != (undefined4 *)0x0) {
    if ((param_1 == 0) || (*(int *)(param_1 + 0x1f0) == 0)) {
      if (puVar6[4] == 0) {
        uVar2 = puVar6[3];
        if (uVar2 == 0) {
          pbVar9 = (byte *)puVar6[2];
        }
        else {
          pbVar9 = *(byte **)(uVar2 + 8);
        }
        uVar8 = 0;
        if (pbVar9 != (byte *)0x0) {
          bVar1 = *pbVar9;
          pbVar7 = pbVar9;
          while (bVar1 != 0) {
            pbVar7 = pbVar7 + 1;
            bVar1 = *pbVar7;
          }
          uVar8 = (int)pbVar7 - (int)pbVar9 & 0x3fffffff;
        }
        sqlite3HashInsert((uint *)(*(int *)(param_2 + 0x40) + 0x38),pbVar9,uVar8,uVar2);
      }
      else {
        *(undefined4 *)(puVar6[4] + 0xc) = puVar6[3];
      }
      if (puVar6[3] != 0) {
        *(undefined4 *)(puVar6[3] + 0x10) = puVar6[4];
      }
    }
    puVar3 = (undefined4 *)puVar6[7];
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = puVar3[7];
      sqlite3ExprDelete(param_1,*(undefined4 **)(iVar4 + 0x14));
      sqlite3ExprListDelete(param_1,*(int **)(iVar4 + 0x18));
      puVar5 = *(undefined4 **)(iVar4 + 8);
      if (puVar5 != (undefined4 *)0x0) {
        sqlite3_exprDelete(param_1,puVar5);
        sqlite3PageFree(param_1,puVar5);
      }
      sqlite3ExprDelete(param_1,(undefined4 *)puVar3[3]);
      sqlite3PageFree(param_1,puVar3);
    }
    puVar3 = (undefined4 *)puVar6[8];
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = puVar3[7];
      sqlite3ExprDelete(param_1,*(undefined4 **)(iVar4 + 0x14));
      sqlite3ExprListDelete(param_1,*(int **)(iVar4 + 0x18));
      puVar5 = *(undefined4 **)(iVar4 + 8);
      if (puVar5 != (undefined4 *)0x0) {
        sqlite3_exprDelete(param_1,puVar5);
        sqlite3PageFree(param_1,puVar5);
      }
      sqlite3ExprDelete(param_1,(undefined4 *)puVar3[3]);
      sqlite3PageFree(param_1,puVar3);
    }
    puVar3 = (undefined4 *)puVar6[1];
    sqlite3PageFree(param_1,puVar6);
    puVar6 = puVar3;
  }
  return;
}




/* [AUDIT] proposed: sqlite3HashInsertElement  (confidence: high)
 * purpose: Insert a hash element into the per-name function hash bucket, computing bucket from first byte+len
 * vars: DAT_00569620 upper-map; %0x17 buckets; hash_findEntry lookup
 */
/* Global::sqlite3HashInsertElement @ 0049b0f0 */

void __cdecl sqlite3HashInsertElement(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  pbVar2 = *(byte **)(param_2 + 0x18);
  uVar5 = 0;
  if (pbVar2 != (byte *)0x0) {
    bVar1 = *pbVar2;
    pbVar4 = pbVar2;
    while (bVar1 != 0) {
      pbVar4 = pbVar4 + 1;
      bVar1 = *pbVar4;
    }
    uVar5 = (int)pbVar4 - (int)pbVar2 & 0x3fffffff;
  }
  uVar6 = ((byte)(&DAT_00569620)[*pbVar2] + uVar5) % 0x17;
  iVar3 = hash_findEntry(param_1,uVar6,pbVar2,uVar5);
  if (iVar3 == 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + uVar6 * 4);
    *(int *)(param_1 + uVar6 * 4) = param_2;
    return;
  }
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar3 + 8);
  *(int *)(iVar3 + 8) = param_2;
  return;
}




/* [AUDIT] proposed: sqlite3Get4byte  (confidence: high)
 * purpose: Read a 4-byte big-endian unsigned int from buffer
 * vars: CONCAT31 of 4 bytes
 */
/* Global::sqlite3Get4byte @ 0049c920 */

undefined4 __cdecl sqlite3Get4byte(undefined1 *param_1)

{
  return CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
}




/* [AUDIT] proposed: sqlite3GetVarint  (confidence: high)
 * purpose: Decode a 1-9 byte SQLite varint into 64-bit result, returning byte count
 * vars: param_2[0]=low32, [1]=high; returns length in low byte
 */
/* Global::sqlite3GetVarint @ 0049d270 */

undefined4 __cdecl sqlite3GetVarint(byte *param_1,uint *param_2)

{
  uint uVar1;
  byte bVar2;
  undefined3 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (uint)*param_1;
  uVar3 = (undefined3)((uint)param_2 >> 8);
  if (-1 < (char)*param_1) {
    *param_2 = uVar4;
    param_2[1] = 0;
    return CONCAT31(uVar3,1);
  }
  uVar5 = (uint)param_1[1];
  if (-1 < (char)param_1[1]) {
    *param_2 = (uVar4 & 0x7f) << 7 | uVar5;
    param_2[1] = 0;
    return CONCAT31(uVar3,2);
  }
  uVar4 = uVar4 << 0xe | (uint)param_1[2];
  if (-1 < (char)param_1[2]) {
    *param_2 = (uVar5 & 0x7f) << 7 | uVar4 & 0x1fc07f;
    param_2[1] = 0;
    return CONCAT31(uVar3,3);
  }
  uVar5 = uVar5 << 0xe | (uint)param_1[3];
  uVar4 = uVar4 & 0x1fc07f;
  if (-1 < (char)param_1[3]) {
    *param_2 = uVar5 & 0x1fc07f | uVar4 << 7;
    param_2[1] = 0;
    return CONCAT31(uVar3,4);
  }
  uVar1 = uVar4 << 0xe | (uint)param_1[4];
  uVar5 = uVar5 & 0x1fc07f;
  if (-1 < (char)param_1[4]) {
    *param_2 = uVar5 << 7 | uVar1;
    param_2[1] = uVar4 >> 0x12;
    return CONCAT31(uVar3,5);
  }
  uVar4 = uVar4 << 7 | uVar5;
  uVar5 = uVar5 << 0xe | (uint)param_1[5];
  if (-1 < (char)param_1[5]) {
    *param_2 = (uVar1 & 0x1fc07f) << 7 | uVar5;
    param_2[1] = uVar4 >> 0x12;
    return CONCAT31(uVar3,6);
  }
  uVar1 = uVar1 << 0xe | (uint)param_1[6];
  if (-1 < (char)param_1[6]) {
    *param_2 = (uVar5 << 7 ^ uVar1) & 0xfe03f80 ^ uVar1;
    param_2[1] = uVar4 >> 0xb;
    return CONCAT31(uVar3,7);
  }
  uVar6 = uVar5 << 0xe | (uint)param_1[7];
  uVar5 = (uVar1 & 0x1fc07f) << 7;
  if (-1 < (char)param_1[7]) {
    *param_2 = uVar6 & 0xf01fc07f | uVar5;
    param_2[1] = uVar4 >> 4;
    return CONCAT31(uVar3,8);
  }
  bVar2 = param_1[4];
  *param_2 = (uVar6 & 0x1fc07f | uVar5) << 8 | (uint)param_1[8];
  param_2[1] = bVar2 >> 3 & 0xf | uVar4 << 4;
  return CONCAT31(uVar3,9);
}




/* [AUDIT] proposed: sqlite3GetVarint32  (confidence: high)
 * purpose: Fast-path decode of a 1-3 byte varint, delegating to GetVarint for longer
 * vars: returns byte count; overflow -> 0xffffffff
 */
/* Global::sqlite3GetVarint32 @ 0049d440 */

uint __cdecl sqlite3GetVarint32(byte *param_1,uint *param_2)

{
  byte bVar1;
  undefined3 uVar3;
  undefined4 uVar2;
  uint local_c;
  int local_8;
  
  bVar1 = param_1[1];
  uVar3 = (undefined3)((uint)param_2 >> 8);
  if (-1 < (char)bVar1) {
    *param_2 = (*param_1 & 0x7f) << 7 | (uint)bVar1;
    return CONCAT31(uVar3,2);
  }
  if ((char)param_1[2] < '\0') {
    uVar2 = sqlite3GetVarint(param_1,&local_c);
    if (local_8 != 0) {
      *param_2 = 0xffffffff;
      return CONCAT31(uVar3,(char)uVar2);
    }
    *param_2 = local_c;
    return CONCAT31(uVar3,(char)uVar2);
  }
  *param_2 = (bVar1 & 0x7f) << 7 | ((uint)*param_1 << 0xe | (uint)param_1[2]) & 0x1fc07f;
  return CONCAT31(uVar3,3);
}




/* [AUDIT] proposed: sqlite3PageFreeList  (confidence: high)
 * purpose: Free a linked list of page allocations (head at param_1[2]), updating global memory stats under mutex
 * vars: DAT_00583e18 used; DAT_00582aec=xFree; DAT_00583f40 mutex
 */
/* Global::sqlite3PageFreeList @ 0049d5c0 */

void __cdecl sqlite3PageFreeList(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)param_1[2];
  param_1[2] = 0;
  sqlite3_free(param_1[3]);
  param_1[3] = 0;
  *param_1 = 0;
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    if (DAT_00582ac8 == 0) {
      (*DAT_00582aec)(puVar1);
      puVar1 = puVar2;
    }
    else {
      if (DAT_00583f40 != 0) {
        (*DAT_00582b18)(DAT_00583f40);
      }
      iVar3 = (*DAT_00582af0._4_4_)(puVar1);
      DAT_00583e18 = DAT_00583e18 - iVar3;
      if (DAT_00583e40 < DAT_00583e18) {
        DAT_00583e40 = DAT_00583e18;
      }
      DAT_00583e3c = DAT_00583e3c + -1;
      if (DAT_00583e64 < DAT_00583e3c) {
        DAT_00583e64 = DAT_00583e3c;
      }
      (*DAT_00582aec)(puVar1);
      puVar1 = puVar2;
      if (DAT_00583f40 != 0) {
        (*DAT_00582b20)(DAT_00583f40);
      }
    }
  }
  param_1[1] = 0;
  return;
}




/* [AUDIT] proposed: sqlite3HashFind  (confidence: high)
 * purpose: Look up key (param_2,len) in hash, returning associated data pointer or 0
 * vars: param_1[3] buckets present; sqlite3StrHash_wal hash; hash_find probe
 */
/* Global::sqlite3HashFind @ 0049d6a0 */

undefined4 __cdecl sqlite3HashFind(uint *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1[3] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sqlite3StrHash_wal(param_2,param_3);
    uVar1 = uVar1 % *param_1;
  }
  puVar2 = hash_find((int)param_1,param_2,param_3,uVar1);
  if (puVar2 != (undefined4 *)0x0) {
    return puVar2[2];
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3HashInsert  (confidence: high)
 * purpose: Insert/replace/delete a hash entry; grow & rehash when load high; allocate HashElem(0x14)
 * vars: sqlite3StrHash_wal hash; grow at hash_rehash; param_4=data (0 deletes)
 */
/* Global::sqlite3HashInsert @ 0049d6f0 */

uint __cdecl sqlite3HashInsert(uint *param_1,byte *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sqlite3StrHash_wal(param_2,param_3);
    uVar2 = uVar2 % uVar1;
  }
  piVar3 = hash_find((int)param_1,param_2,param_3,uVar2);
  if (piVar3 != (int *)0x0) {
    uVar1 = piVar3[2];
    if (param_4 == 0) {
      hash_removeElement(param_1,piVar3,uVar2);
      return uVar1;
    }
    piVar3[3] = (int)param_2;
    piVar3[2] = param_4;
    return uVar1;
  }
  if (param_4 != 0) {
    puVar4 = (uint *)sqlite3Malloc(0x14);
    if (puVar4 == (uint *)0x0) {
      return param_4;
    }
    puVar4[3] = (uint)param_2;
    puVar4[4] = param_3;
    puVar4[2] = param_4;
    param_1[1] = param_1[1] + 1;
    uVar1 = param_1[1];
    if ((9 < uVar1) && (*param_1 * 2 < uVar1)) {
      iVar5 = hash_rehash(param_1,uVar1 * 2);
      if (iVar5 != 0) {
        uVar2 = sqlite3StrHash_wal(param_2,param_3);
        uVar2 = uVar2 % *param_1;
      }
    }
    if (param_1[3] != 0) {
      pcache_pageInsert((int)param_1,(int *)(param_1[3] + uVar2 * 8),(int *)puVar4);
      return 0;
    }
    *puVar4 = param_1[2];
    if (param_1[2] != 0) {
      *(uint **)(param_1[2] + 4) = puVar4;
    }
    puVar4[1] = 0;
    param_1[2] = (uint)puVar4;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3IdListDelete  (confidence: high)
 * purpose: Free an IdList: free each item name string then the array
 * vars: param_2[1] count; *param_2 items(stride 8)
 */
/* Global::sqlite3IdListDelete @ 0049d910 */

void __cdecl sqlite3IdListDelete(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != (int *)0x0) {
    iVar3 = 0;
    if (0 < param_2[1]) {
      do {
        puVar1 = *(undefined4 **)(*param_2 + iVar3 * 8);
        if (param_1 == 0) {
LAB_0049d9a5:
          sqlite3_free((int)puVar1);
        }
        else if (*(int *)(param_1 + 0x1f0) == 0) {
          if (((puVar1 == (undefined4 *)0x0) || (puVar1 < *(undefined4 **)(param_1 + 0x104))) ||
             (*(undefined4 **)(param_1 + 0x108) <= puVar1)) goto LAB_0049d9a5;
          *puVar1 = *(undefined4 *)(param_1 + 0x100);
          *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + -1;
          *(undefined4 **)(param_1 + 0x100) = puVar1;
        }
        else if (((puVar1 == (undefined4 *)0x0) || (puVar1 < *(undefined4 **)(param_1 + 0x104))) ||
                (*(undefined4 **)(param_1 + 0x108) <= puVar1)) {
          iVar2 = (*DAT_00582af0._4_4_)(puVar1);
          **(int **)(param_1 + 0x1f0) = **(int **)(param_1 + 0x1f0) + iVar2;
        }
        else {
          **(int **)(param_1 + 0x1f0) =
               **(int **)(param_1 + 0x1f0) + (uint)*(ushort *)(param_1 + 0xe8);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_2[1]);
    }
    sqlite3PageFree(param_1,(undefined4 *)*param_2);
    sqlite3PageFree(param_1,param_2);
  }
  return;
}




/* [AUDIT] proposed: sqlite3Close  (confidence: high)
 * purpose: Tear down a database connection: free cursors, VTables, schema, funcs, collations, aggregate ctx, pager
 * vars: magic 0x64cffc7f open, sets -0x4aca86d0 then -0x60c3d2cd closed; frees aDb, pErr
 */
/* Global::sqlite3Close @ 0049fad0 */

void __cdecl sqlite3Close(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_8;
  
  piVar6 = param_1;
  if ((param_1[0x11] == 0x64cffc7f) && (iVar7 = sqlite3_txnActive((int)param_1), iVar7 == 0)) {
    pcacheClearOverflowList((int)param_1);
    iVar7 = 0;
    if (0 < param_1[5]) {
      param_1 = (int *)0x0;
      do {
        iVar2 = piVar6[4];
        piVar8 = *(int **)((int)param_1 + iVar2 + 4);
        if (piVar8 != (int *)0x0) {
          btree_closeConnection(piVar8);
          *(undefined4 *)((int)param_1 + iVar2 + 4) = 0;
          if (iVar7 != 1) {
            *(undefined4 *)((int)param_1 + iVar2 + 0xc) = 0;
          }
        }
        iVar7 = iVar7 + 1;
        param_1 = param_1 + 4;
      } while (iVar7 < piVar6[5]);
    }
    if (*(int *)(piVar6[4] + 0x1c) != 0) {
      sqlite3SchemaClear(*(int *)(piVar6[4] + 0x1c));
    }
    sqlite3VtabUnlockList((int)piVar6);
    pcacheCompactPageArray((int)piVar6);
    piVar8 = piVar6 + 0x50;
    local_8 = 0x17;
    do {
      puVar5 = (undefined4 *)*piVar8;
      while (puVar5 != (undefined4 *)0x0) {
        puVar9 = (undefined4 *)puVar5[7];
        puVar10 = puVar5;
        do {
          piVar3 = (int *)puVar10[8];
          if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
            (*(code *)piVar3[1])(piVar3[2]);
            sqlite3PageFree((int)piVar6,piVar3);
          }
          puVar4 = (undefined4 *)puVar10[2];
          sqlite3PageFree((int)piVar6,puVar10);
          puVar10 = puVar4;
          puVar5 = puVar9;
        } while (puVar4 != (undefined4 *)0x0);
      }
      piVar8 = piVar8 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    for (puVar5 = (undefined4 *)piVar6[0x69]; puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      puVar10 = (undefined4 *)puVar5[2];
      puVar9 = puVar10 + 4;
      iVar7 = 3;
      do {
        if ((code *)*puVar9 != (code *)0x0) {
          (*(code *)*puVar9)(puVar9[-2]);
        }
        puVar9 = puVar9 + 5;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      sqlite3PageFree((int)piVar6,puVar10);
    }
    sqlite3PageFreeList(piVar6 + 0x67);
    for (puVar5 = (undefined4 *)piVar6[0x4b]; puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      puVar9 = (undefined4 *)puVar5[2];
      if ((code *)puVar9[3] != (code *)0x0) {
        (*(code *)puVar9[3])(puVar9[2]);
      }
      sqlite3PageFree((int)piVar6,puVar9);
    }
    sqlite3PageFreeList(piVar6 + 0x49);
    sqlite3ErrorWithMsg((int)piVar6,0,(byte *)0x0);
    piVar8 = (int *)piVar6[0x35];
    if (piVar8 != (int *)0x0) {
      uVar1 = *(ushort *)(piVar8 + 7);
      if ((uVar1 & 0x2460) != 0) {
        if ((uVar1 & 0x2000) == 0) {
          if (((uVar1 & 0x400) == 0) || ((code *)piVar8[8] == (code *)0x0)) {
            if ((uVar1 & 0x20) == 0) {
              if ((uVar1 & 0x40) != 0) {
                piVar3 = (int *)piVar8[4];
                piVar3[1] = *(int *)(*piVar3 + 0xa4);
                *(int **)(*piVar3 + 0xa4) = piVar3;
                if ((*(byte *)(piVar8 + 7) & 0x20) != 0) {
                  sqlite3ExprListClearList((undefined4 *)piVar8[4]);
                }
                *(ushort *)(piVar8 + 7) = *(ushort *)(piVar8 + 7) & 0xbe01 | 1;
                *(undefined1 *)((int)piVar8 + 0x1e) = 5;
              }
            }
            else {
              sqlite3ExprListClearList((undefined4 *)piVar8[4]);
            }
          }
          else {
            (*(code *)piVar8[8])(piVar8[1]);
            piVar8[8] = 0;
          }
        }
        else {
          sqlite3VdbeMemFinalize(piVar8,piVar8[4]);
          sqlite3VdbeMemRelease(piVar8);
        }
      }
      sqlite3PageFree(*piVar8,(undefined4 *)piVar8[9]);
      piVar8[1] = 0;
      piVar8[9] = 0;
      piVar8[8] = 0;
      sqlite3PageFree(*piVar8,piVar8);
    }
    pcacheCleanupCursorSpace(piVar6);
    piVar6[0x11] = -0x4aca86d0;
    sqlite3PageFree((int)piVar6,*(undefined4 **)(piVar6[4] + 0x1c));
    if (piVar6[3] != 0) {
      (*DAT_00582b20)(piVar6[3]);
    }
    piVar6[0x11] = -0x60c3d2cd;
    if (piVar6[3] != 0) {
      (*DAT_00582b14)(piVar6[3]);
    }
    if (*(char *)((int)piVar6 + 0xeb) != '\0') {
      sqlite3_free(piVar6[0x41]);
    }
    sqlite3_free((int)piVar6);
    return;
  }
  if (param_1[3] != 0) {
    (*DAT_00582b20)(param_1[3]);
  }
  return;
}




/* [AUDIT] proposed: sqlite3LockAndPrepare  (confidence: high)
 * purpose: Safety-check + mutex-enter connection, run sqlite3Prepare, retry once on SCHEMA(0x11), release
 * vars: sqlite3SafetyCheckOk safetyCheck; sqlite3Prepare prepare; 0x11=SQLITE_SCHEMA
 */
/* Global::sqlite3LockAndPrepare @ 004a0180 */

uint __cdecl
sqlite3LockAndPrepare(int param_1,void *param_2,size_t param_3,byte param_4,int param_5,undefined4 *param_6,
            int *param_7)

{
  int iVar1;
  uint uVar2;
  
  *param_6 = 0;
  iVar1 = sqlite3SafetyCheckOk(param_1);
  if (iVar1 == 0) {
    sqlite3_log(0x15,"misuse at line %d of [%.10s]");
    return 0x15;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    (*DAT_00582b18)(*(int *)(param_1 + 0xc));
  }
  btree_enterAll(param_1);
  uVar2 = sqlite3Prepare(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (uVar2 == 0x11) {
    sqlite3_clear_bindings_46aa30((int *)*param_6);
    uVar2 = sqlite3Prepare(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  sqlite3BtreeLeaveAll(param_1);
  if (*(int *)(param_1 + 0xc) != 0) {
    (*DAT_00582b20)(*(int *)(param_1 + 0xc));
  }
  return uVar2;
}




/* [AUDIT] proposed: sqlite3Malloc  (confidence: high)
 * purpose: Allocate memory (size guard <0x7ffffeff) via configured xMalloc, tracking stats under mem mutex
 * vars: DAT_00582ac8 memstat on; DAT_00582ae8=xMalloc; sqlite3_mallocRaw tracked path
 */
/* Global::sqlite3Malloc @ 004a0350 */

int __cdecl sqlite3Malloc(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (0x7ffffefe < param_1 - 1U) {
    return 0;
  }
  if (DAT_00582ac8 != 0) {
    if (DAT_00583f40 != 0) {
      (*DAT_00582b18)(DAT_00583f40);
    }
    sqlite3_mallocRaw(iVar1,&param_1);
    if (DAT_00583f40 != 0) {
      (*DAT_00582b20)(DAT_00583f40);
    }
    return param_1;
  }
  iVar1 = (*DAT_00582ae8)(param_1);
  return iVar1;
}




/* [AUDIT] proposed: sqlite3MallocAlarm  (confidence: high)
 * purpose: Invoke registered soft-heap-limit alarm callback once (re-entrancy guarded), around mem mutex
 * vars: DAT_00583f50 alarm cb; DAT_00583e18 used; param_1 nByte
 */
/* Global::sqlite3MallocAlarm @ 004a03c0 */

void __cdecl sqlite3MallocAlarm(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = DAT_00583f54;
  pcVar2 = DAT_00583f50;
  iVar1 = DAT_00583e18;
  if (DAT_00583f50 != (code *)0x0) {
    iVar4 = DAT_00583e18 >> 0x1f;
    DAT_00583f50 = (code *)0x0;
    if (DAT_00583f40 != 0) {
      (*DAT_00582b20)(DAT_00583f40);
    }
    (*pcVar2)(uVar3,iVar1,iVar4,param_1);
    if (DAT_00583f40 != 0) {
      (*DAT_00582b18)(DAT_00583f40);
    }
  }
  DAT_00583f50 = pcVar2;
  DAT_00583f54 = uVar3;
  return;
}




/* [AUDIT] proposed: pcache1Initialize  (confidence: med)
 * purpose: Init memory subsystem: default methods if unset, set up page-cache buffer and scratch from config
 * vars: DAT_00582b70 pagebuf; builds free-list; _DAT_00582afc init call
 */
/* Global::pcache1Initialize @ 004a0440 */


void __cdecl pcache1Initialize(undefined4 param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_retaddr;
  
  if (DAT_00582ae8 == 0) {
    sqlite3_config(4,(undefined8 *)&PTR_FUN_0056a9dc,unaff_retaddr,param_1);
  }
  _DAT_00583f40 = 0;
  _DAT_00583f48 = 0;
  _DAT_00583f50 = 0;
  _DAT_00583f58 = 0;
  _DAT_00583f60 = 0;
  if (DAT_00582acc != 0) {
    uVar2 = (*DAT_00582b10)(3);
    _DAT_00583f40 = CONCAT44(DAT_00583f40_4,uVar2);
  }
  if (((DAT_00582b70 == (undefined4 *)0x0) || ((int)DAT_00582b74 < 100)) || (DAT_00582b78 < 1)) {
    _DAT_00583f58 = _DAT_00583f58 & 0xffffffff00000000;
    DAT_00582b70 = (undefined4 *)0x0;
    DAT_00582b74 = 0;
    DAT_00582b78 = 0;
  }
  else {
    _DAT_00583f60 = CONCAT44(DAT_00583f64,DAT_00582b78);
    uVar6 = DAT_00582b74 & 0xfffffff8;
    iVar5 = DAT_00582b78 + -1;
    _DAT_00583f58 = ZEXT48(DAT_00582b70) << 0x20;
    lVar1 = _DAT_00583f58;
    DAT_00583f5c = DAT_00582b70;
    puVar3 = DAT_00582b70;
    puVar4 = DAT_00582b70;
    DAT_00582b74 = uVar6;
    if (0 < iVar5) {
      do {
        _DAT_00583f58 = lVar1;
        puVar4 = (undefined4 *)((int)puVar3 + uVar6);
        *puVar3 = puVar4;
        iVar5 = iVar5 + -1;
        puVar3 = puVar4;
        lVar1 = _DAT_00583f58;
      } while (iVar5 != 0);
    }
    *puVar4 = 0;
    _DAT_00583f58 = CONCAT44(DAT_00583f5c,puVar4 + 1);
  }
  if (((DAT_00582b7c == 0) || (DAT_00582b80 < 0x200)) || (DAT_00582b84 < 1)) {
    DAT_00582b7c = 0;
    DAT_00582b80 = 0;
    DAT_00582b84 = 0;
  }
  (*_DAT_00582afc)(DAT_00582b00._4_4_);
  return;
}




/* [AUDIT] proposed: sqlite3MutexInit  (confidence: med)
 * purpose: Lazily select mutex method table (threaded vs noop) then tail-call its xMutexInit
 * vars: PTR_LAB_0056caa0 vs 0056c24c; DAT_00582b08 methods
 */
/* Global::sqlite3MutexInit @ 004a0cd0 */


void sqlite3MutexInit(void)

{
  undefined **ppuVar1;
  
  if (DAT_00582b10 == (undefined *)0x0) {
    ppuVar1 = &PTR_LAB_0056caa0;
    if (DAT_00582acc == 0) {
      ppuVar1 = &PTR_LAB_0056c24c;
    }
    _DAT_00582b14 = *(undefined8 *)(ppuVar1 + 3);
    DAT_00582b08._4_4_ = ppuVar1[1];
    DAT_00582b08._0_4_ = (code *)*ppuVar1;
    _DAT_00582b1c = *(undefined8 *)(ppuVar1 + 5);
    DAT_00582b10 = ppuVar1[2];
    _DAT_00582b24 = *(undefined8 *)(ppuVar1 + 7);
  }
  (*(code *)DAT_00582b08)();
  return;
}




/* [AUDIT] proposed: sqlite3OsClose  (confidence: high)
 * purpose: Close an OS file: if handle open call pMethods->xClose(vtable+4) and null it
 * vars: *param_1 pMethods; returns rc
 */
/* Global::sqlite3OsClose @ 004a1250 */

undefined4 __cdecl sqlite3OsClose(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = (**(code **)(*param_1 + 4))(param_1);
    *param_1 = 0;
    return uVar1;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3OsCurrentTimeInt64  (confidence: high)
 * purpose: Get current time as int64 ms: use xCurrentTimeInt64 if v>=2 else xCurrentTime*86400000
 * vars: param_1[0x12]/[0x10] method slots; ftol2 f2ll
 */
/* Global::sqlite3OsCurrentTimeInt64 @ 004a1280 */

undefined4 __cdecl sqlite3OsCurrentTimeInt64(int *param_1,ulonglong *param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  double local_c;
  
  if ((1 < *param_1) && ((code *)param_1[0x12] != (code *)0x0)) {
    uVar1 = (*(code *)param_1[0x12])(param_1,param_2);
    return uVar1;
  }
  uVar1 = (*(code *)param_1[0x10])(param_1,&local_c);
  local_c = local_c * 86400000.0;
  uVar2 = ftol2();
  *param_2 = uVar2;
  return uVar1;
}




/* [AUDIT] proposed: sqlite3OsFileControl  (confidence: high)
 * purpose: Invoke file vtable method at +8 (xFileControl-like) with 4 args
 * vars: *param_1 pMethods
 */
/* Global::sqlite3OsFileControl @ 004a1350 */

void __cdecl
sqlite3OsFileControl(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  (**(code **)(*param_1 + 8))(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* [AUDIT] proposed: sqlite3OsShmMap_or_v10  (confidence: med)
 * purpose: Invoke OS/vtable method at offset +0x10 with two args
 * vars: *param_1 pMethods+0x10
 */
/* Global::sqlite3OsShmMap_or_v10 @ 004a1370 */

void __cdecl sqlite3OsShmMap_or_v10(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x10))(param_1,param_2,param_3);
  return;
}




/* [AUDIT] proposed: sqlite3OsWrite  (confidence: high)
 * purpose: Invoke OS file vtable method at +0xc (xWrite) with buf/amt/offset args
 * vars: *param_1 pMethods+0xc
 */
/* Global::sqlite3OsWrite @ 004a1390 */

void __cdecl
sqlite3OsWrite(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  (**(code **)(*param_1 + 0xc))(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* [AUDIT] proposed: sqlite3PcacheBufferSetup  (confidence: high)
 * purpose: Build page-cache buffer free-list from configured page memory (pPage,sz,n) at init
 * vars: DAT_00584204 enabled; DAT_00584220 free head; slots masked to 8
 */
/* Global::sqlite3PcacheBufferSetup @ 004a13b0 */

void __cdecl sqlite3PcacheBufferSetup(undefined4 *param_1,uint param_2,int param_3)

{
  if (DAT_00584204 != 0) {
    if (param_3 < 0x5b) {
      DAT_00584210 = param_3 / 10 + 1;
    }
    else {
      DAT_00584210 = 10;
    }
    DAT_00584220 = (undefined4 *)0x0;
    DAT_00584228 = 0;
    DAT_00584208 = param_2 & 0xfffffff8;
    DAT_00584224 = param_3;
    DAT_0058420c = param_3;
    DAT_00584214 = param_1;
    DAT_00584218 = param_1;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *DAT_00584218 = DAT_00584220;
      DAT_00584220 = DAT_00584218;
      DAT_00584218 = (undefined4 *)((int)DAT_00584218 + (param_2 & 0xfffffff8));
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3PagerClose  (confidence: high)
 * purpose: Close pager: purge cache, write journal cleanup, close DB/journal files, free pager
 * vars: param_1[0x2c] tmp space; [0x10] fd; [0x2d] pcache; pcache_freePageMem free
 */
/* Global::sqlite3PagerClose @ 004a17a0 */

undefined4 __cdecl sqlite3PagerClose(uint *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  
  puVar1 = (undefined4 *)param_1[0x2c];
  if (DAT_00583e74 != (code *)0x0) {
    (*DAT_00583e74)();
  }
  *(undefined1 *)(param_1 + 1) = 0;
  sqlite3WalClose((int *)param_1[0x2e],(uint)*(byte *)((int)param_1 + 9),param_1[0x20],puVar1);
  uVar3 = param_1[0x16];
  param_1[0x2e] = 0;
  for (; uVar3 != 0; uVar3 = *(uint *)(uVar3 + 0x2c)) {
    *(undefined4 *)(uVar3 + 0x10) = 1;
  }
  pcacheTruncate((undefined4 *)param_1[0x2d],0);
  if (*(char *)((int)param_1 + 0xe) == '\0') {
    piVar2 = (int *)param_1[0x10];
    if (*piVar2 != 0) {
      if ((*(char *)((int)param_1 + 7) != '\0') ||
         (uVar3 = (**(code **)(*piVar2 + 0x14))(piVar2,2), uVar3 == 0)) {
        uVar3 = (**(code **)(*(int *)param_1[0x10] + 0x18))((int *)param_1[0x10],param_1 + 0x14);
      }
      if (((uVar3 & 0xff) == 0xd) || ((uVar3 & 0xff) == 10)) {
        param_1[10] = uVar3;
        *(undefined1 *)((int)param_1 + 0xf) = 6;
      }
    }
    pcache_releasePage(param_1);
  }
  else {
    pcache_freePage((int)param_1);
  }
  if (DAT_00583e78 != (code *)0x0) {
    (*DAT_00583e78)();
  }
  piVar2 = (int *)param_1[0x10];
  if (*piVar2 != 0) {
    (**(code **)(*piVar2 + 4))(piVar2);
    *piVar2 = 0;
  }
  piVar2 = (int *)param_1[0xf];
  if (*piVar2 != 0) {
    (**(code **)(*piVar2 + 4))(piVar2);
    *piVar2 = 0;
  }
  pcache_freePageMem(puVar1);
  if (*(int *)(param_1[0x2d] + 0x28) != 0) {
    (*DAT_00582b58)(*(int *)(param_1[0x2d] + 0x28));
  }
  sqlite3_free((int)param_1);
  return 0;
}




/* [AUDIT] proposed: sqlite3PagerCommitPhaseOne  (confidence: high)
 * purpose: Sync journal and flush dirty pages to DB during commit; handle incremental-vacuum truncation
 * vars: pcacheDirtyList 4a3620; walWriteWalFrames_journal walFrames; pager_incr_changecounter changecounter
 */
/* Global::sqlite3PagerCommitPhaseOne @ 004a19a0 */

uint __cdecl sqlite3PagerCommitPhaseOne(uint *param_1,char *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  undefined3 extraout_var;
  undefined1 *puVar8;
  uint *puVar9;
  undefined4 *local_8;
  
  puVar2 = param_1;
  if (param_1[10] != 0) {
    return param_1[10];
  }
  if (*(byte *)((int)param_1 + 0xf) < 3) {
    return 0;
  }
  if (*(char *)((int)param_1 + 0xe) == '\0') {
    if (param_1[0x2e] == 0) {
      uVar6 = pager_incrChangeCounter(param_1);
      if (uVar6 != 0) {
        return uVar6;
      }
      puVar5 = (uint *)puVar2[6];
      puVar1 = (uint *)puVar2[7];
      if ((puVar5 < puVar1) && (*(char *)((int)puVar2 + 5) != '\x02')) {
        iVar7 = DAT_00582bb8 / (int)puVar2[0x20];
        puVar9 = (uint *)((int)puVar5 + 1);
        puVar2[6] = (uint)puVar1;
        param_1 = puVar9;
        if (puVar9 <= puVar1) {
          do {
            param_1 = puVar9;
            bVar4 = bitvec_test((uint *)puVar2[0xe],(uint)puVar9);
            if ((CONCAT31(extraout_var,bVar4) == 0) && (puVar9 != (uint *)(iVar7 + 1U))) {
              uVar6 = getAndInitPage((int)puVar2,(uint)puVar9,(int *)&local_8,0);
              puVar3 = local_8;
              if (uVar6 != 0) {
                return uVar6;
              }
              uVar6 = pagerPlaybackSavepoint(local_8);
              sqlite3PagerUnrefNotNull(puVar3);
              puVar9 = param_1;
              if (uVar6 != 0) {
                return uVar6;
              }
            }
            puVar9 = (uint *)((int)puVar9 + 1);
            param_1 = puVar9;
          } while (puVar9 <= (uint *)puVar2[7]);
        }
        puVar2[6] = (uint)puVar5;
      }
      uVar6 = walWriteWalFrames_journal((int)puVar2,param_2);
      if (uVar6 != 0) {
        return uVar6;
      }
      uVar6 = pager_incr_changecounter((uint)puVar2,0);
      if (uVar6 != 0) {
        return uVar6;
      }
      puVar8 = pcacheSortDirtyList((int *)puVar2[0x2d]);
      uVar6 = pager_commitPhaseOne((int *)puVar2,(int)puVar8);
      if (uVar6 != 0) {
        return uVar6;
      }
      pagerReleaseAllSavepoints_flush((undefined4 *)puVar2[0x2d]);
      uVar6 = puVar2[6];
      if ((uVar6 != puVar2[8]) &&
         (uVar6 = pager_truncateImage((int)puVar2,uVar6 - (uVar6 == DAT_00582bb8 / (int)puVar2[0x20] + 1U))
         , uVar6 != 0)) {
        return uVar6;
      }
      uVar6 = 0;
      if (param_3 == 0) {
        uVar6 = pagerSyncHotJournal((int)puVar2);
      }
      if (uVar6 != 0) {
        return uVar6;
      }
    }
    else {
      puVar5 = (uint *)pcacheSortDirtyList((int *)param_1[0x2d]);
      param_1 = (uint *)0x0;
      if (puVar5 == (uint *)0x0) {
        getAndInitPage((int)puVar2,1,(int *)&param_1,0);
        param_1[3] = 0;
        puVar5 = param_1;
      }
      puVar1 = param_1;
      uVar6 = pager_writeDirtyList((int)puVar2,puVar5,puVar2[6],1);
      sqlite3PagerUnrefNotNull(puVar1);
      if (uVar6 != 0) {
        return uVar6;
      }
      pagerReleaseAllSavepoints_flush((undefined4 *)puVar2[0x2d]);
    }
  }
  else {
    for (uVar6 = param_1[0x16]; uVar6 != 0; uVar6 = *(uint *)(uVar6 + 0x2c)) {
      *(undefined4 *)(uVar6 + 0x10) = 1;
    }
  }
  if (puVar2[0x2e] == 0) {
    *(undefined1 *)((int)puVar2 + 0xf) = 5;
  }
  return 0;
}




/* [AUDIT] proposed: pager_playback_or_reset  (confidence: med)
 * purpose: On error state, reset/playback pager: set state; on I/O error latch code and mark error(6)
 * vars: +0xf state; +0x12 errhandler byte; pager_endTransaction pager_end
 */
/* Global::pager_playback_or_reset @ 004a1bb0 */

void __cdecl pager_playback_or_reset(int *param_1)

{
  uint uVar1;
  
  if (param_1[10] == 0) {
    if (((*(char *)((int)param_1 + 0xf) == '\x02') && ((char)param_1[1] != '\0')) &&
       (*(char *)((int)param_1 + 5) == '\x01')) {
      *(undefined1 *)((int)param_1 + 0xf) = 1;
      return;
    }
    uVar1 = pager_endTransaction(param_1,(uint)*(byte *)((int)param_1 + 0x12));
    if (((uVar1 & 0xff) == 0xd) || ((uVar1 & 0xff) == 10)) {
      param_1[10] = uVar1;
      *(undefined1 *)((int)param_1 + 0xf) = 6;
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3PagerMovepage  (confidence: high)
 * purpose: Relocate a pager page to new pgno, updating dirty list, journaling and change-count flags
 * vars: sqlite3PcacheFetch fetch; sqlite3PcacheMove rekey; sqlite3PcacheRelease release
 */
/* Global::sqlite3PagerMovepage @ 004a1ce0 */

uint __cdecl sqlite3PagerMovepage(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *piVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint local_8;
  
  puVar5 = param_2;
  puVar3 = param_1;
  local_8 = 0;
  if ((*(char *)((int)param_1 + 0xe) != '\0') && (uVar6 = pagerPlaybackSavepoint(param_2), uVar6 != 0)) {
    return uVar6;
  }
  if ((((*(byte *)(puVar5 + 6) & 2) != 0) && (iVar7 = walDirtyPagesPresent_or_bitTest((int)puVar5), iVar7 != 0)) &&
     (uVar6 = subjournalPage((int)puVar5), uVar6 != 0)) {
    return uVar6;
  }
  if (((*(ushort *)(puVar5 + 6) & 4) != 0) && (param_4 == 0)) {
    local_8 = puVar5[5];
  }
  *(ushort *)(puVar5 + 6) = *(ushort *)(puVar5 + 6) & 0xfffb;
  sqlite3PcacheFetch((int *)puVar3[0x2d],param_3,0,&param_1);
  puVar4 = param_1;
  if (param_1 != (undefined4 *)0x0) {
    *(ushort *)(puVar5 + 6) = *(ushort *)(puVar5 + 6) | *(ushort *)(param_1 + 6) & 4;
    if (*(char *)((int)puVar3 + 0xe) == '\0') {
      pcacheRelease_writeSubj(param_1);
    }
    else {
      sqlite3PcacheMove(param_1,puVar3[6] + 1);
    }
  }
  param_1 = (undefined4 *)puVar5[5];
  sqlite3PcacheMove(puVar5,param_3);
  *(ushort *)(puVar5 + 6) = *(ushort *)(puVar5 + 6) & 0xffdf;
  if ((*(ushort *)(puVar5 + 6) & 2) == 0) {
    *(ushort *)(puVar5 + 6) = *(ushort *)(puVar5 + 6) | 2;
    piVar1 = (int *)puVar5[7];
    iVar7 = *piVar1;
    puVar5[8] = iVar7;
    if (iVar7 != 0) {
      *(undefined4 **)(iVar7 + 0x24) = puVar5;
    }
    *piVar1 = (int)puVar5;
    if (piVar1[1] == 0) {
      piVar1[1] = (int)puVar5;
    }
    if ((piVar1[2] == 0) && ((*(byte *)(puVar5 + 6) & 4) == 0)) {
      piVar1[2] = (int)puVar5;
    }
  }
  if ((*(char *)((int)puVar3 + 0xe) != '\0') &&
     (sqlite3PcacheMove(puVar4,param_1), puVar4 != (undefined4 *)0x0)) {
    puVar2 = (uint *)puVar4[4];
    sqlite3PcacheRelease(puVar4);
    if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar2);
    }
  }
  if (local_8 != 0) {
    uVar6 = getAndInitPage((int)puVar3,local_8,(int *)&param_1,0);
    puVar5 = param_1;
    if (uVar6 != 0) {
      if (local_8 <= (uint)puVar3[7]) {
        bitvec_clear((uint *)puVar3[0xe],local_8,(uint *)puVar3[0x2c]);
      }
      return uVar6;
    }
    *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 4;
    pcacheManageDirtyList_add((int)param_1);
    puVar2 = (uint *)puVar5[4];
    sqlite3PcacheRelease(puVar5);
    if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar2);
    }
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3PagerOpen  (confidence: high)
 * purpose: Allocate & init a Pager (fixup filename, journal '-journal', wal '-wal', open DB file, set pagesize)
 * vars: '-journal'/'-wal' suffixes; _Dst pager; +0x94/0xbc journal/wal names
 */
/* Global::sqlite3PagerOpen @ 004a1ea0 */

int __cdecl
sqlite3PagerOpen(undefined *param_1,undefined4 *param_2,char *param_3,int param_4,byte param_5,
            uint param_6,uint param_7)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  undefined *puVar7;
  byte bVar8;
  uint uVar9;
  char *_Dst;
  void *pvVar10;
  code *pcVar11;
  char *pcVar12;
  byte bVar13;
  uint uVar14;
  char *pcVar15;
  char local_1c;
  uint local_14;
  char *local_10;
  char *local_c;
  int local_8;
  
  bVar13 = param_5;
  puVar7 = param_1;
  local_1c = '\0';
  bVar6 = false;
  local_c = (char *)0x0;
  bVar8 = ~param_5;
  uVar14 = 0;
  pcVar15 = (char *)0x0;
  local_8 = 0;
  local_14 = 0x400;
  local_10 = (char *)0x0;
  if (*(int *)(param_1 + 4) < 0x29) {
    _param_5 = 0x28;
  }
  else {
    _param_5 = *(int *)(param_1 + 4) + 7U & 0xfffffff8;
  }
  *param_2 = 0;
  if ((bVar13 & 2) == 0) {
LAB_004a1f40:
    if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
      iVar2 = *(int *)(param_1 + 8);
      _Dst = (char *)sqlite3Malloc((iVar2 + 1) * 2);
      pcVar15 = param_3;
      if (_Dst == (char *)0x0) {
        return 7;
      }
      *_Dst = '\0';
      local_c = _Dst;
      local_8 = (**(code **)(puVar7 + 0x24))(puVar7,param_3,iVar2 + 1,_Dst);
      cVar3 = *_Dst;
      pcVar12 = _Dst;
      while (cVar3 != '\0') {
        pcVar12 = pcVar12 + 1;
        cVar3 = *pcVar12;
      }
      uVar14 = (int)pcVar12 - (int)_Dst & 0x3fffffff;
      cVar3 = *pcVar15;
      pcVar12 = pcVar15;
      while (cVar3 != '\0') {
        pcVar12 = pcVar12 + 1;
        cVar3 = *pcVar12;
      }
      local_10 = pcVar15 + ((int)pcVar12 - (int)pcVar15 & 0x3fffffffU) + 1;
      cVar3 = *local_10;
      pcVar15 = local_10;
      while (cVar3 != '\0') {
        cVar3 = *pcVar15;
        pcVar12 = pcVar15;
        while (cVar3 != '\0') {
          pcVar12 = pcVar12 + 1;
          cVar3 = *pcVar12;
        }
        pcVar15 = pcVar15 + ((int)pcVar12 - (int)pcVar15 & 0x3fffffffU) + 1;
        if (pcVar15 == (char *)0x0) {
          uVar9 = 0;
        }
        else {
          cVar3 = *pcVar15;
          pcVar12 = pcVar15;
          while (cVar3 != '\0') {
            pcVar12 = pcVar12 + 1;
            cVar3 = *pcVar12;
          }
          uVar9 = (int)pcVar12 - (int)pcVar15 & 0x3fffffff;
        }
        pcVar15 = pcVar15 + uVar9 + 1;
        cVar3 = *pcVar15;
      }
      pcVar15 = pcVar15 + (1 - (int)local_10);
      if ((local_8 != 0) ||
         ((*(int *)(param_1 + 8) < (int)(uVar14 + 8) && (local_8 = sqlite3CantopenError(), local_8 != 0))))
      goto LAB_004a22d9;
    }
  }
  else {
    bVar6 = true;
    if (param_3 != (char *)0x0) {
      if (*param_3 == '\0') goto LAB_004a1f40;
      local_c = (char *)sqlite3PageStrdup(0,param_3);
      if (local_c == (char *)0x0) {
        return 7;
      }
      uVar14 = sqlite3Strlen30(local_c);
      param_3 = (char *)0x0;
    }
  }
  iVar4 = *(int *)(param_1 + 4);
  iVar2 = _param_5 * 2;
  _Dst = (char *)sqlite3Malloc((int)(pcVar15 + uVar14 * 3 + iVar2 + (iVar4 + 7U & 0xfffffff8) + 0x101
                                   ));
  if (_Dst == (char *)0x0) {
    sqlite3_free((int)local_c);
    return 7;
  }
  memset(_Dst,0,(size_t)(pcVar15 + uVar14 * 3 + iVar2 + (iVar4 + 7U & 0xfffffff8) + 0x101));
  *(char **)(_Dst + 0xb4) = _Dst + 0xc0;
  pcVar12 = _Dst + 0xf0;
  *(char **)(_Dst + 0x3c) = pcVar12;
  pcVar12 = pcVar12 + (*(int *)(param_1 + 4) + 7U & 0xfffffff8);
  *(char **)(_Dst + 0x44) = pcVar12;
  *(char **)(_Dst + 0x40) = pcVar12 + _param_5;
  pcVar12 = pcVar12 + _param_5 + _param_5;
  *(char **)(_Dst + 0x90) = pcVar12;
  if (local_c != (char *)0x0) {
    *(char **)(_Dst + 0x94) = pcVar12 + (int)(pcVar15 + uVar14 + 1);
    memcpy(pcVar12,local_c,uVar14);
    if (pcVar15 != (char *)0x0) {
      memcpy((void *)(*(int *)(_Dst + 0x90) + 1 + uVar14),local_10,(size_t)pcVar15);
    }
    pcVar15 = local_c;
    memcpy(*(void **)(_Dst + 0x94),local_c,uVar14);
    iVar2 = *(int *)(_Dst + 0x94);
    *(undefined8 *)(iVar2 + uVar14) = 0x6c616e72756f6a2d;
    *(undefined2 *)(iVar2 + 8 + uVar14) = 0;
    pvVar10 = (void *)(*(int *)(_Dst + 0x94) + 9 + uVar14);
    *(void **)(_Dst + 0xbc) = pvVar10;
    memcpy(pvVar10,pcVar15,uVar14);
    iVar2 = *(int *)(_Dst + 0xbc);
    *(undefined4 *)(iVar2 + uVar14) = 0x6c61772d;
    *(undefined1 *)(iVar2 + 4 + uVar14) = 0;
    sqlite3_free((int)pcVar15);
  }
  puVar7 = param_1;
  *(undefined **)_Dst = param_1;
  *(uint *)(_Dst + 0x78) = param_6;
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    bVar13 = (byte)param_6 & 1;
    local_1c = '\x01';
    _Dst[0xf] = '\x01';
    _Dst[0x10] = '\x04';
    if (local_8 == 0) goto LAB_004a21d4;
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 0x18);
    param_1 = (undefined *)0x0;
    local_8 = (*(code *)*puVar1)(puVar7,*(undefined4 *)(_Dst + 0x90),*(undefined4 *)(_Dst + 0x3c),
                                 param_6 & 0x87f7f,&param_1);
    bVar13 = (byte)((uint)param_1 & 1);
    if (local_8 == 0) {
      if (((uint)param_1 & 1) == 0) {
        pager_setSectorSize((int)_Dst);
        uVar14 = *(uint *)(_Dst + 0x7c);
        if ((0x400 < uVar14) && (local_14 = uVar14, 0x2000 < uVar14)) {
          local_14 = 0x2000;
        }
      }
LAB_004a21d4:
      local_8 = sqlite3PagerSetPagesize((int)_Dst,&local_14,-1);
      if (local_8 == 0) {
        pvVar10 = *(void **)(_Dst + 0xb4);
        param_1 = (undefined *)(param_4 + 7U & 0xfffffff8);
        memset(pvVar10,0,0x30);
        puVar7 = param_1;
        *(uint *)((int)pvVar10 + 0x14) = local_14;
        *(undefined **)((int)pvVar10 + 0x18) = param_1;
        *(char **)((int)pvVar10 + 0x24) = _Dst;
        *(undefined4 *)((int)pvVar10 + 0x10) = 100;
        param_1 = lib_fn_484180;
        *(uint *)((int)pvVar10 + 0x1c) = (uint)!bVar6;
        pcVar11 = (code *)0x0;
        if (!bVar6) {
          pcVar11 = lib_fn_484180;
        }
        *(code **)((int)pvVar10 + 0x20) = pcVar11;
        _Dst[6] = bVar8 & 1;
        _Dst[0x84] = -1;
        _Dst[0x85] = -1;
        _Dst[0x86] = -1;
        _Dst[0x87] = '?';
        _Dst[0xc] = local_1c;
        _Dst[4] = local_1c;
        _Dst[0x11] = local_1c;
        _Dst[0xe] = bVar6;
        _Dst[0xd] = bVar13;
        _Dst[7] = local_1c;
        if (local_1c == '\0') {
          builtin_strncpy(_Dst + 8,"\x01\x02\"\x02",4);
        }
        *(short *)(_Dst + 0x74) = (short)puVar7;
        _Dst[0x88] = -1;
        _Dst[0x89] = -1;
        _Dst[0x8a] = -1;
        _Dst[0x8b] = -1;
        _Dst[0x8c] = -1;
        _Dst[0x8d] = -1;
        _Dst[0x8e] = -1;
        _Dst[0x8f] = -1;
        pager_setSectorSize((int)_Dst);
        if ((bVar8 & 1) == 0) {
          _Dst[5] = '\x02';
        }
        else if (bVar6) {
          _Dst[5] = '\x04';
        }
        *(uint *)(_Dst + 0xac) = param_7;
        *param_2 = _Dst;
        return 0;
      }
    }
  }
  piVar5 = *(int **)(_Dst + 0x3c);
  if (*piVar5 != 0) {
    (**(code **)(*piVar5 + 4))(piVar5);
    *piVar5 = 0;
  }
LAB_004a22d9:
  sqlite3_free((int)_Dst);
  return local_8;
}




/* [AUDIT] proposed: pager_write_dirty_or_openWal  (confidence: med)
 * purpose: If writable & no savepoint: close read fd and open write-mode/WAL, set pager state 5
 * vars: pager_unlockAndRollback openWal; +0xf state; +5 eLock
 */
/* Global::pager_write_dirty_or_openWal @ 004a2440 */

int __cdecl pager_write_dirty_or_openWal(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (((char)param_1[3] == '\0') && (param_1[0x2e] == 0)) {
    if (((char)param_1[1] == '\0') &&
       ((**(int **)param_1[0xf] < 2 || ((*(int **)param_1[0xf])[0xd] == 0)))) {
      return 0xe;
    }
    piVar1 = (int *)param_1[0x10];
    if (*piVar1 != 0) {
      (**(code **)(*piVar1 + 4))(piVar1);
      *piVar1 = 0;
    }
    iVar2 = pager_unlockAndRollback(param_1);
    if (iVar2 == 0) {
      *(undefined1 *)((int)param_1 + 5) = 5;
      *(undefined1 *)((int)param_1 + 0xf) = 0;
      return 0;
    }
  }
  else {
    *param_2 = 1;
  }
  return iVar2;
}




/* [AUDIT] proposed: pagerReadFileheader  (confidence: high)
 * purpose: Zero dst then read up to param_2 bytes of DB header via xRead, mapping SHORT_READ(0x20a) to 0
 * vars: *(+0x3c) fd methods; rc 0x20a->0
 */
/* Global::pagerReadFileheader @ 004a24c0 */

int __cdecl pagerReadFileheader(int param_1,size_t param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  
  memset(param_3,0,param_2);
  piVar1 = *(int **)(param_1 + 0x3c);
  if (*piVar1 != 0) {
    iVar2 = (**(code **)(*piVar1 + 8))(piVar1,param_3,param_2,0,0);
    if (iVar2 == 0x20a) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3PagerCommitPhaseTwo_or_sync  (confidence: med)
 * purpose: Finalize pager: commit/sync per state, on I/O error latch code and set error state 6
 * vars: +0xf state; +0x2e savepoint; pager_endTransaction pager_end
 */
/* Global::sqlite3PagerCommitPhaseTwo_or_sync @ 004a2510 */

uint __cdecl sqlite3PagerCommitPhaseTwo_or_sync(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *(byte *)((int)param_1 + 0xf);
  if (bVar1 == 6) {
    return param_1[10];
  }
  if (bVar1 < 2) {
    return 0;
  }
  if (param_1[0x2e] == 0) {
    if ((*(int *)param_1[0x10] == 0) || (bVar1 == 2)) {
      uVar2 = pager_endTransaction((int *)param_1,0);
      if ((*(char *)((int)param_1 + 0xe) == '\0') && (2 < bVar1)) {
        param_1[10] = 4;
        *(undefined1 *)((int)param_1 + 0xf) = 6;
        return uVar2;
      }
      goto LAB_004a255a;
    }
    uVar3 = pager_playback(param_1,0);
  }
  else {
    uVar2 = sqlite3PagerReleaseSavepoints(param_1,2,-1);
    uVar3 = pager_endTransaction((int *)param_1,(uint)*(byte *)((int)param_1 + 0x12));
    if (uVar2 != 0) goto LAB_004a255a;
  }
  uVar2 = uVar3;
LAB_004a255a:
  if (((uVar2 & 0xff) == 0xd) || ((uVar2 & 0xff) == 10)) {
    param_1[10] = uVar2;
    *(undefined1 *)((int)param_1 + 0xf) = 6;
  }
  return uVar2;
}




/* [AUDIT] proposed: sqlite3PagerReleaseSavepoints  (confidence: med)
 * purpose: Release/rollback pager savepoints down to param_3, freeing bitvecs and syncing sub-journal
 * vars: param_1[0x18] nSavepoint; [0x17] aSavepoint(stride0x30); bitvec_destroy free
 */
/* Global::sqlite3PagerReleaseSavepoints @ 004a25c0 */

uint __cdecl sqlite3PagerReleaseSavepoints(undefined4 *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1[10] != 0) || ((int)param_1[0x18] <= param_3)) {
    return param_1[10];
  }
  iVar3 = (uint)(param_2 != 1) + param_3;
  if (iVar3 < (int)param_1[0x18]) {
    iVar5 = iVar3 * 0x30;
    iVar4 = iVar3;
    do {
      bitvec_destroy(*(int *)(iVar5 + 0x10 + param_1[0x17]));
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x30;
    } while (iVar4 < (int)param_1[0x18]);
  }
  param_1[0x18] = iVar3;
  uVar2 = 0;
  if (param_2 == 1) {
    if (iVar3 == 0) {
      puVar1 = *(undefined **)param_1[0x11];
      if (puVar1 != (undefined *)0x0) {
        if (puVar1 == &DAT_00569a48) {
          uVar2 = memjrnlFreePages((undefined8 *)param_1[0x11]);
        }
        param_1[0xd] = 0;
      }
    }
  }
  else if ((param_1[0x2e] != 0) || (*(int *)param_1[0x10] != 0)) {
    if (iVar3 != 0) {
      uVar2 = pager_playbackSavepoint(param_1,(uint *)(param_1[0x17] + -0x30 + iVar3 * 0x30));
      return uVar2;
    }
    uVar2 = pager_playbackSavepoint(param_1,(uint *)0x0);
    return uVar2;
  }
  return uVar2;
}




/* [AUDIT] proposed: sqlite3PagerSetBusyhandler  (confidence: high)
 * purpose: Store busy-handler callback (+0x98/+0x9c) and forward to VFS via xFileControl (+0x28)
 * vars: pager fd methods +0x28
 */
/* Global::sqlite3PagerSetBusyhandler @ 004a26b0 */

void __cdecl sqlite3PagerSetBusyhandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x98) = param_2;
  *(undefined4 *)(param_1 + 0x9c) = param_3;
  if (**(int **)(param_1 + 0x3c) != 0) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 0x28))();
    return;
  }
  return;
}




/* [AUDIT] proposed: sqlite3PagerSetPagesize  (confidence: high)
 * purpose: Change pager page size: alloc temp space, compute nPage via alldiv, update cache & reserve bytes
 * vars: param_2 new size; +0x80 pagesize; +0x18 dbSize; +0xb0 tmp
 */
/* Global::sqlite3PagerSetPagesize @ 004a27d0 */

int __cdecl sqlite3PagerSetPagesize(int param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 local_c;
  
  uVar1 = *param_2;
  iVar5 = 0;
  if ((((*(char *)(param_1 + 0xe) == '\0') || (*(int *)(param_1 + 0x18) == 0)) &&
      (*(int *)(*(int *)(param_1 + 0xb4) + 0xc) == 0)) &&
     ((uVar1 != 0 && (uVar1 != *(uint *)(param_1 + 0x80))))) {
    local_c = 0;
    if ((*(char *)(param_1 + 0xf) != '\0') && (piVar2 = *(int **)(param_1 + 0x3c), *piVar2 != 0)) {
      iVar5 = (**(code **)(*piVar2 + 0x18))(piVar2,&local_c);
      if (iVar5 != 0) goto LAB_004a28cc;
    }
    puVar4 = pcache_allocPage(uVar1);
    if (puVar4 == (undefined4 *)0x0) {
      iVar5 = 7;
    }
    else {
      btree_invalidateAllCursors(param_1);
      uVar6 = __alldiv((uVar1 + (uint)local_c) - 1,
                       (local_c._4_4_ + (uint)CARRY4(uVar1,(uint)local_c)) -
                       (uint)(uVar1 + (uint)local_c == 0),uVar1,0);
      *(int *)(param_1 + 0x18) = (int)uVar6;
      *(uint *)(param_1 + 0x80) = uVar1;
      pcache_freePageMem(*(undefined4 **)(param_1 + 0xb0));
      *(undefined4 **)(param_1 + 0xb0) = puVar4;
      iVar3 = *(int *)(param_1 + 0xb4);
      if (*(int *)(iVar3 + 0x28) != 0) {
        (*DAT_00582b58)(*(int *)(iVar3 + 0x28));
        *(undefined4 *)(iVar3 + 0x28) = 0;
        *(undefined4 *)(iVar3 + 0x2c) = 0;
      }
      *(uint *)(iVar3 + 0x14) = uVar1;
    }
  }
LAB_004a28cc:
  *param_2 = *(uint *)(param_1 + 0x80);
  if (iVar5 == 0) {
    if (param_3 < 0) {
      param_3 = (int)*(short *)(param_1 + 0x76);
    }
    *(short *)(param_1 + 0x76) = (short)param_3;
  }
  return iVar5;
}




/* [AUDIT] proposed: pager_playback  (confidence: high)
 * purpose: Roll back changes from hot journal: read super/header, replay pages, sync & end transaction
 * vars: pager_pageCount readMasterJournal; pager_endTransactionCheck; pcache_freePage unlock
 */
/* Global::pager_playback_4a2980 @ 004a2980 */

void __cdecl pager_playback_4a2980(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  bool bVar6;
  int local_20;
  uint local_1c;
  uint local_18 [5];
  
  local_18[4] = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  uVar5 = 0;
  if ((*(char *)((int)param_1 + 0xe) != '\0') && (param_1[10] != 0)) goto LAB_004a2bbd;
  if ((param_1[0x2e] == 0) && (*(char *)((int)param_1 + 0xf) == '\0')) {
    local_1c = 1;
    iVar2 = pager_lockWithRetry((int)param_1,1);
    if (iVar2 != 0) goto LAB_004a2b9c;
    if ((byte)param_1[4] < 2) {
      iVar2 = pager_hasHotJournal((int *)param_1,&local_1c);
      if (iVar2 != 0) goto LAB_004a2b9c;
      if (local_1c != 0) goto LAB_004a2a00;
LAB_004a2ac8:
      if (((char)param_1[3] == '\0') &&
         ((param_1[0x16] != 0 || (iVar2 = pagerFileSync(param_1[0x2d]), 0 < iVar2)))) {
        local_1c = 0;
        iVar2 = pager_pageCount((int)param_1,&local_1c);
        if (iVar2 != 0) goto LAB_004a2b9c;
        if (local_1c == 0) {
          local_18[0] = 0;
          local_18[1] = 0;
          local_18[2] = 0;
          local_18[3] = 0;
        }
        else {
          iVar2 = (**(code **)(*(int *)param_1[0xf] + 8))((int *)param_1[0xf],local_18,0x10,0x18,0);
          if (iVar2 != 0) goto LAB_004a2b9c;
        }
        puVar3 = param_1 + 0x19;
        puVar4 = local_18;
        uVar5 = 0xc;
        do {
          if (*puVar3 != *puVar4) {
            btree_invalidateAllCursors((int)param_1);
            break;
          }
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          bVar6 = 3 < uVar5;
          uVar5 = uVar5 - 4;
        } while (bVar6);
      }
      uVar5 = pager_endTransactionCheck((int *)param_1);
      goto LAB_004a2b6b;
    }
LAB_004a2a00:
    iVar2 = pager_lockDb((int)param_1,4);
    if (iVar2 != 0) goto LAB_004a2b9c;
    uVar5 = 0;
    if (*(int *)param_1[0x10] == 0) {
      uVar1 = *param_1;
      uVar5 = (**(code **)(uVar1 + 0x20))(uVar1,param_1[0x25],0,&local_20);
      if ((((uVar5 == 0) && (local_20 != 0)) &&
          (local_1c = uVar5,
          uVar5 = (**(code **)(uVar1 + 0x18))(uVar1,param_1[0x25],param_1[0x10],0x802,&local_1c),
          uVar5 == 0)) && ((local_1c & 1) != 0)) {
        uVar5 = sqlite3CantopenError();
        sqlite3OsClose((int *)param_1[0x10]);
      }
    }
    if (*(int *)param_1[0x10] == 0) {
      if ((char)param_1[1] == '\0') {
        pager_unlockDb((int)param_1,1);
      }
LAB_004a2ab8:
      if (uVar5 == 0) goto LAB_004a2ac8;
    }
    else {
      uVar5 = pager_syncJournal((int)param_1);
      if (uVar5 == 0) {
        uVar5 = pager_playback(param_1,1);
        *(undefined1 *)((int)param_1 + 0xf) = 0;
        goto LAB_004a2ab8;
      }
    }
    pager_error((int)param_1,uVar5);
  }
  else {
LAB_004a2b6b:
    if (param_1[0x2e] != 0) {
      uVar5 = pager_walCheckpointCheck((int)param_1);
    }
    if (*(char *)((int)param_1 + 0xf) == '\0') {
      if (uVar5 != 0) goto LAB_004a2b9c;
      uVar5 = pager_pageCount((int)param_1,param_1 + 6);
    }
  }
  if (uVar5 == 0) {
    *(undefined1 *)((int)param_1 + 0xf) = 1;
LAB_004a2bbd:
    __security_check_cookie(local_18[4] ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_004a2b9c:
  pcache_freePage((int)param_1);
  __security_check_cookie(local_18[4] ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: pagerSyncHotJournal  (confidence: med)
 * purpose: Sync journal file via VFS (xSync at +0xb or xFileControl+0x28), mapping NOTFOUND(0xc)->0
 * vars: *(+0x3c) fd; +7 noSync
 */
/* Global::pagerSyncHotJournal @ 004a2bd0 */

int __cdecl pagerSyncHotJournal(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x14))
                      (*(int **)(param_1 + 0x3c),*(undefined1 *)(param_1 + 0xb));
    return iVar2;
  }
  piVar1 = *(int **)(param_1 + 0x3c);
  if (*piVar1 != 0) {
    iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,8,0);
    if (iVar2 == 0xc) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3PagerUnrefNotNull  (confidence: high)
 * purpose: Release one reference to a pager page (pcacheRelease + free BtShared if refless)
 * vars: sqlite3PcacheRelease pcacheRelease; puVar1[0x2d] pcache
 */
/* Global::sqlite3PagerUnrefNotNull @ 004a2c20 */

void __cdecl sqlite3PagerUnrefNotNull(undefined4 *param_1)

{
  uint *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (uint *)param_1[4];
    sqlite3PcacheRelease(param_1);
    if (*(int *)(puVar1[0x2d] + 0xc) == 0) {
      pcache_releasePage(puVar1);
    }
  }
  return;
}




/* [AUDIT] proposed: pagerPlaybackSavepoint  (confidence: med)
 * purpose: Replay/reload pages over a savepoint range, reacquiring/reinitializing each affected page
 * vars: local_8 nPage; DAT_00582bb8 PENDING; getAndInitPage getPage
 */
/* Global::pagerPlaybackSavepoint @ 004a2c80 */

uint __cdecl pagerPlaybackSavepoint(undefined4 *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  bool bVar5;
  undefined3 extraout_var;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar1 = param_1[4];
  local_8 = *(uint *)(iVar1 + 0x7c) / *(uint *)(iVar1 + 0x80);
  local_10 = 0;
  if (local_8 < 2) {
    uVar6 = pager_writePage((int)param_1);
    return uVar6;
  }
  *(char *)(iVar1 + 0x14) = *(char *)(iVar1 + 0x14) + '\x01';
  uVar6 = param_1[5];
  iVar8 = 0;
  uVar7 = (~(local_8 - 1) & uVar6 - 1) + 1;
  local_c = 0;
  if (*(uint *)(iVar1 + 0x18) < uVar6) {
    local_8 = (uVar6 - uVar7) + 1;
  }
  else if (*(uint *)(iVar1 + 0x18) < (local_8 - 1) + uVar7) {
    local_8 = (*(uint *)(iVar1 + 0x18) - uVar7) + 1;
  }
  local_18 = 0;
  uVar6 = local_8;
  uVar9 = uVar7;
  if (0 < (int)local_8) {
    do {
      if (local_10 != 0) goto LAB_004a2e6a;
      if ((uVar9 == param_1[5]) ||
         (bVar5 = bitvec_test(*(uint **)(iVar1 + 0x38),uVar9), uVar6 = local_8,
         CONCAT31(extraout_var,bVar5) == 0)) {
        if ((uVar9 != DAT_00582bb8 / *(int *)(iVar1 + 0x80) + 1U) &&
           (local_10 = getAndInitPage(iVar1,uVar9,(int *)&local_14,0), puVar3 = local_14,
           uVar6 = local_8, local_10 == 0)) {
          local_10 = pager_writePage((int)local_14);
          if ((*(byte *)(puVar3 + 6) & 4) != 0) {
            local_c = 1;
          }
          puVar2 = (uint *)puVar3[4];
          sqlite3PcacheRelease(puVar3);
          uVar6 = local_8;
          iVar8 = local_c;
          if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
            pcache_releasePage(puVar2);
            uVar6 = local_8;
            iVar8 = local_c;
          }
        }
      }
      else {
        sqlite3PcacheFetch(*(int **)(iVar1 + 0xb4),uVar9,0,&local_1c);
        local_14 = local_1c;
        uVar6 = local_8;
        if (local_1c != (undefined4 *)0x0) {
          if ((*(byte *)(local_1c + 6) & 4) != 0) {
            iVar8 = 1;
          }
          puVar2 = (uint *)local_1c[4];
          local_c = iVar8;
          sqlite3PcacheRelease(local_1c);
          uVar6 = local_8;
          if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
            pcache_releasePage(puVar2);
            uVar6 = local_8;
          }
        }
      }
      uVar4 = local_8;
      local_18 = local_18 + 1;
      uVar9 = uVar9 + 1;
    } while (local_18 < (int)uVar6);
    if ((local_10 == 0) && (iVar8 != 0)) {
      iVar8 = 0;
      do {
        sqlite3PcacheFetch(*(int **)(iVar1 + 0xb4),uVar7 + iVar8,0,&param_1);
        if (param_1 != (undefined4 *)0x0) {
          puVar2 = (uint *)param_1[4];
          *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 4;
          sqlite3PcacheRelease(param_1);
          if (*(int *)(puVar2[0x2d] + 0xc) == 0) {
            pcache_releasePage(puVar2);
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar4);
    }
  }
LAB_004a2e6a:
  *(char *)(iVar1 + 0x14) = *(char *)(iVar1 + 0x14) + -1;
  return local_10;
}




/* [AUDIT] proposed: sqlite3ParseUri  (confidence: high)
 * purpose: SQLite 3.7.15.2 sqlite3ParseUri: identified by compiler-independent string-anchor match (6 unique-owner string anchors, score 30.0). Anchors: %s mode not allowed: %s|access|cache|invalid uri authority: %.*s
 * vars: -
 */
/* Global::sqlite3ParseUri @ 004a2e90 */

undefined4 __cdecl
sqlite3ParseUri(byte *param_1,int *param_2,uint *param_3,int *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined **ppuVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  char cVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  bool bVar19;
  uint local_20;
  uint local_1c;
  undefined4 local_14;
  uint local_10;
  int local_c;
  char *local_8;
  
  piVar4 = param_2;
  local_10 = *param_3;
  local_14 = 0;
  uVar16 = 0;
  if (param_2 != (int *)0x0) {
    cVar13 = (char)*param_2;
    piVar15 = param_2;
    while (cVar13 != '\0') {
      piVar15 = (int *)((int)piVar15 + 1);
      cVar13 = *(char *)piVar15;
    }
    uVar16 = (int)piVar15 - (int)param_2 & 0x3fffffff;
  }
  if (((((local_10 & 0x40) == 0) && (DAT_00582ad4 == 0)) || (uVar16 < 5)) ||
     ((*param_2 != 0x656c6966 || ((char)param_2[1] != ':')))) {
    iVar17 = sqlite3_initialize();
    if (iVar17 != 0) {
      return 7;
    }
    local_8 = (char *)sqlite3Malloc(uVar16 + 2);
    if (local_8 == (char *)0x0) {
      return 7;
    }
    memcpy(local_8,param_2,uVar16);
    local_10 = local_10 & 0xffffffbf;
    (local_8 + uVar16)[0] = '\0';
    (local_8 + uVar16)[1] = '\0';
LAB_004a3384:
    iVar17 = sqlite3_vfs_find(param_1);
    *param_4 = iVar17;
    if (iVar17 != 0) goto LAB_004a33c2;
    uVar5 = sqlite3_snprintf_guarded((byte *)"no such vfs: %s");
  }
  else {
    local_10 = local_10 | 0x40;
    iVar14 = 0;
    iVar17 = uVar16 + 2;
    iVar10 = 0;
    local_8 = (char *)0x0;
    param_2 = (int *)0x0;
    local_c = 0;
    if (1 < uVar16) {
      do {
        iVar14 = iVar14 + (uint)(*(char *)((int)piVar4 + iVar10) == '&');
        iVar6 = iVar10 + 1;
        iVar10 = iVar10 + 2;
        param_2 = (int *)((int)param_2 + (uint)(*(char *)((int)piVar4 + iVar6) == '&'));
        local_8 = (char *)iVar14;
      } while (iVar10 < (int)(uVar16 - 1));
    }
    iVar14 = 0;
    if (iVar10 < (int)uVar16) {
      iVar17 = iVar17 + (uint)(*(char *)(iVar10 + (int)piVar4) == '&');
    }
    iVar10 = sqlite3_initialize();
    if ((iVar10 != 0) ||
       (local_8 = (char *)sqlite3Malloc((int)param_2 + iVar17 + (int)local_8), local_8 == (char *)0x0
       )) {
      return 7;
    }
    if ((*(char *)((int)piVar4 + 5) != '/') || (*(char *)((int)piVar4 + 6) != '/')) {
      iVar17 = 5;
LAB_004a2ff1:
      cVar13 = *(char *)(iVar17 + (int)piVar4);
      if (cVar13 != '\0') {
        iVar10 = 0;
        do {
          if (cVar13 == '#') break;
          iVar6 = iVar17 + 1;
          if (((cVar13 == '%') &&
              (bVar1 = *(byte *)(iVar6 + (int)piVar4), ((&DAT_00569720)[bVar1] & 8) != 0)) &&
             (((&DAT_00569720)[*(byte *)(iVar17 + 2 + (int)piVar4)] & 8) != 0)) {
            cVar13 = *(char *)(iVar17 + 2 + (int)piVar4);
            iVar6 = iVar17 + 3;
            cVar13 = (bVar1 + ((char)bVar1 >> 6 & 1U) * -7) * '\x10' +
                     (cVar13 + (cVar13 >> 6 & 1U) * -7 & 0xf);
            if (cVar13 == '\0') {
              cVar13 = *(char *)(iVar6 + (int)piVar4);
              while ((iVar14 = local_c, cVar13 != '\0' && (cVar13 != '#'))) {
                if (iVar10 == 0) {
                  bVar19 = cVar13 == '?';
LAB_004a30d4:
                  if (bVar19) break;
                }
                else {
                  if (iVar10 == 1) {
                    if (cVar13 != '=') {
LAB_004a30d1:
                      bVar19 = cVar13 == '&';
                      goto LAB_004a30d4;
                    }
                    break;
                  }
                  if (iVar10 == 2) goto LAB_004a30d1;
                }
                iVar17 = iVar6 + 1;
                iVar6 = iVar6 + 1;
                cVar13 = *(char *)(iVar17 + (int)piVar4);
              }
            }
            else {
              local_8[local_c] = cVar13;
              iVar14 = local_c + 1;
              local_c = local_c + 1;
            }
          }
          else {
            if (iVar10 == 1) {
              if ((cVar13 == '&') || (cVar13 == '=')) {
                if (local_8[iVar14 + -1] == '\0') {
                  cVar13 = *(char *)(iVar6 + (int)piVar4);
                  for (; ((cVar13 != '\0' && (cVar13 != '#')) &&
                         (*(char *)(iVar6 + -1 + (int)piVar4) != '&')); iVar6 = iVar6 + 1) {
                    cVar13 = *(char *)(iVar6 + 1 + (int)piVar4);
                  }
                }
                else if (cVar13 == '&') {
                  local_8[iVar14] = '\0';
                  local_8[iVar14 + 1] = '\0';
                  local_c = iVar14 + 2;
                  iVar14 = local_c;
                }
                else {
                  local_8[iVar14] = '\0';
                  local_c = iVar14 + 1;
                  iVar10 = 2;
                  iVar14 = local_c;
                }
                goto LAB_004a30ab;
              }
            }
            else {
              if (iVar10 == 0) {
                if (cVar13 != '?') {
                  local_c = iVar14 + 1;
                  local_8[iVar14] = cVar13;
                  iVar14 = local_c;
                  goto LAB_004a30ab;
                }
              }
              else if ((iVar10 != 2) || (cVar13 != '&')) goto LAB_004a318d;
              iVar10 = 1;
              cVar13 = '\0';
            }
LAB_004a318d:
            local_c = iVar14 + 1;
            local_8[iVar14] = cVar13;
            iVar14 = local_c;
          }
LAB_004a30ab:
          cVar13 = *(char *)(iVar6 + (int)piVar4);
          iVar17 = iVar6;
        } while (cVar13 != '\0');
        if (iVar10 == 1) {
          local_8[iVar14] = '\0';
          iVar14 = iVar14 + 1;
        }
      }
      (local_8 + iVar14)[0] = '\0';
      (local_8 + iVar14)[1] = '\0';
      cVar13 = *local_8;
      pcVar7 = local_8;
      while (cVar13 != '\0') {
        pcVar7 = pcVar7 + 1;
        cVar13 = *pcVar7;
      }
      pbVar11 = (byte *)(local_8 + ((int)pcVar7 - (int)local_8 & 0x3fffffffU) + 1);
      pbVar12 = pbVar11;
      if (*pbVar11 != 0) {
LAB_004a31d7:
        do {
          pbVar11 = pbVar11 + 1;
        } while (*pbVar11 != 0);
        uVar16 = (int)pbVar11 - (int)pbVar12 & 0x3fffffff;
        pbVar11 = pbVar12 + uVar16 + 1;
        if (pbVar11 == (byte *)0x0) {
          uVar18 = 0;
        }
        else {
          bVar1 = *pbVar11;
          pbVar9 = pbVar11;
          while (bVar1 != 0) {
            pbVar9 = pbVar9 + 1;
            bVar1 = *pbVar9;
          }
          uVar18 = (int)pbVar9 - (int)pbVar11 & 0x3fffffff;
        }
        if (uVar16 != 3) {
          if (uVar16 != 5) {
            if ((uVar16 == 4) && (*(int *)pbVar12 == 0x65646f6d)) {
              local_1c = local_10 & 0x87;
              local_20 = 0x87;
              ppuVar8 = &PTR_DAT_0058353c;
              goto LAB_004a329e;
            }
            goto LAB_004a3373;
          }
          if ((*(int *)pbVar12 != 0x68636163) || (pbVar12[4] != 0x65)) goto LAB_004a3373;
          local_20 = 0x60000;
          ppuVar8 = &PTR_s_shared_00583524;
          local_1c = 0x60000;
LAB_004a329e:
          pbVar12 = *ppuVar8;
          iVar17 = 0;
          if (pbVar12 != (byte *)0x0) {
            do {
              uVar16 = 0;
              if (pbVar12 != (byte *)0x0) {
                bVar1 = *pbVar12;
                pbVar9 = pbVar12;
                while (bVar1 != 0) {
                  pbVar9 = pbVar9 + 1;
                  bVar1 = *pbVar9;
                }
                uVar16 = (int)pbVar9 - (int)pbVar12 & 0x3fffffff;
              }
              pbVar9 = pbVar11;
              uVar3 = uVar18;
              if (uVar18 == uVar16) {
                while (uVar16 = uVar3 - 4, 3 < uVar3) {
                  if (*(int *)pbVar9 != *(int *)pbVar12) goto LAB_004a32ee;
                  pbVar12 = pbVar12 + 4;
                  pbVar9 = pbVar9 + 4;
                  uVar3 = uVar16;
                }
                if (uVar16 == 0xfffffffc) goto LAB_004a333e;
LAB_004a32ee:
                if ((*pbVar9 == *pbVar12) &&
                   ((uVar16 == 0xfffffffd ||
                    ((pbVar9[1] == pbVar12[1] &&
                     ((uVar16 == 0xfffffffe ||
                      ((pbVar9[2] == pbVar12[2] &&
                       ((uVar16 == 0xffffffff || (pbVar9[3] == pbVar12[3]))))))))))))
                goto LAB_004a333e;
              }
              iVar17 = iVar17 + 1;
              pbVar12 = ppuVar8[iVar17 * 2];
              if (pbVar12 == (byte *)0x0) break;
            } while( true );
          }
          goto LAB_004a3329;
        }
        if ((*(short *)pbVar12 == 0x6676) && (pbVar12[2] == 0x73)) {
          param_1 = pbVar11;
        }
        goto LAB_004a3373;
      }
      goto LAB_004a3384;
    }
    cVar13 = *(char *)((int)piVar4 + 7);
    iVar17 = 7;
    if (cVar13 == '\0') goto LAB_004a2ff1;
    do {
      if (cVar13 == '/') break;
      cVar13 = *(char *)(iVar17 + 1 + (int)piVar4);
      iVar17 = iVar17 + 1;
    } while (cVar13 != '\0');
    if ((iVar17 == 7) ||
       ((((iVar17 == 0x10 && (*(int *)((int)piVar4 + 7) == 0x61636f6c)) &&
         (*(int *)((int)piVar4 + 0xb) == 0x736f686c)) && (*(char *)((int)piVar4 + 0xf) == 't'))))
    goto LAB_004a2ff1;
    uVar5 = sqlite3_snprintf_guarded((byte *)"invalid uri authority: %.*s");
  }
LAB_004a33a9:
  local_14 = 1;
LAB_004a33b0:
  *param_6 = uVar5;
  sqlite3_free((int)local_8);
  local_8 = (char *)0x0;
LAB_004a33c2:
  *param_3 = local_10;
  *param_5 = local_8;
  return local_14;
LAB_004a333e:
  puVar2 = ppuVar8[iVar17 * 2 + 1];
  if (puVar2 == (undefined *)0x0) {
LAB_004a3329:
    uVar5 = sqlite3_snprintf_guarded((byte *)"no such %s mode: %s");
    goto LAB_004a33a9;
  }
  if ((int)local_1c < (int)((uint)puVar2 & 0xffffff7f)) {
    uVar5 = sqlite3_snprintf_guarded((byte *)"%s mode not allowed: %s");
    local_14 = 3;
    goto LAB_004a33b0;
  }
  local_10 = ~local_20 & local_10 | (uint)puVar2;
LAB_004a3373:
  pbVar11 = pbVar11 + uVar18 + 1;
  pbVar12 = pbVar11;
  if (*pbVar11 == 0) goto LAB_004a3384;
  goto LAB_004a31d7;
}




/* [AUDIT] proposed: pagerReleaseAllSavepoints_flush  (confidence: med)
 * purpose: Flush pages holding savepoint bit 2: write to sub-journal, clear dirty, notify pcache
 * vars: puVar1[6]&2 flag; pcache_removeFromDirty; DAT_00582b4c pcache notify
 */
/* Global::pagerReleaseAllSavepoints_flush @ 004a35c0 */

void __cdecl pagerReleaseAllSavepoints_flush(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)*param_1;
  while (puVar1 != (undefined4 *)0x0) {
    if ((*(byte *)(puVar1 + 6) & 2) != 0) {
      pcache_removeFromDirty((int)puVar1);
      *(ushort *)(puVar1 + 6) = *(ushort *)(puVar1 + 6) & 0xfff9;
      if ((*(short *)((int)puVar1 + 0x1a) == 0) && (iVar2 = puVar1[7], *(int *)(iVar2 + 0x1c) != 0))
      {
        if (puVar1[5] == 1) {
          *(undefined4 *)(iVar2 + 0x2c) = 0;
        }
        (*DAT_00582b4c)(*(undefined4 *)(iVar2 + 0x28),*puVar1,0);
      }
    }
    puVar1 = (undefined4 *)*param_1;
  }
  return;
}




/* [AUDIT] proposed: pcacheSortDirtyList  (confidence: high)
 * purpose: Merge-sort the pager dirty-page list (32-bucket radix merge) by page number for flushing
 * vars: link at +0xc; key at +0x14 pgno; 0x1f buckets
 */
/* Global::pcacheSortDirtyList @ 004a3620 */

undefined1 * __cdecl pcacheSortDirtyList(int *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *local_ac [32];
  undefined1 local_2c [12];
  undefined1 *local_20;
  
  iVar7 = *param_1;
  while (iVar7 != 0) {
    *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0x20);
    iVar7 = *(int *)(iVar7 + 0x20);
  }
  puVar2 = (undefined1 *)*param_1;
  memset(local_ac,0,0x80);
  while (puVar2 != (undefined1 *)0x0) {
    puVar1 = *(undefined1 **)(puVar2 + 0xc);
    *(int *)(puVar2 + 0xc) = 0;
    iVar7 = 0;
    do {
      if (local_ac[iVar7] == (undefined1 *)0x0) {
        local_ac[iVar7] = puVar2;
        puVar4 = puVar2;
        break;
      }
      puVar4 = local_2c;
      puVar5 = local_ac[iVar7];
      do {
        if (puVar2 == (undefined1 *)0x0) {
          if (puVar5 == (undefined1 *)0x0) goto LAB_004a36b4;
          *(undefined1 **)(puVar4 + 0xc) = puVar5;
          goto LAB_004a36bb;
        }
        if (*(uint *)(puVar5 + 0x14) < *(uint *)(puVar2 + 0x14)) {
          *(undefined1 **)(puVar4 + 0xc) = puVar5;
          puVar3 = puVar2;
          puVar6 = *(undefined1 **)(puVar5 + 0xc);
          puVar4 = puVar5;
        }
        else {
          *(undefined1 **)(puVar4 + 0xc) = puVar2;
          puVar3 = *(undefined1 **)(puVar2 + 0xc);
          puVar6 = puVar5;
          puVar4 = puVar2;
        }
        puVar2 = puVar3;
        puVar5 = puVar6;
      } while (puVar6 != (undefined1 *)0x0);
      if (puVar3 == (undefined1 *)0x0) {
LAB_004a36b4:
        *(undefined4 *)(puVar4 + 0xc) = 0;
      }
      else {
        *(undefined1 **)(puVar4 + 0xc) = puVar3;
      }
LAB_004a36bb:
      local_ac[iVar7] = (undefined1 *)0x0;
      iVar7 = iVar7 + 1;
      puVar2 = local_20;
      puVar4 = local_20;
    } while (iVar7 < 0x1f);
    puVar2 = puVar1;
    if (iVar7 == 0x1f) {
      puVar1 = local_2c;
      while (local_ac[0x1f] != (undefined1 *)0x0) {
        if (puVar4 == (undefined1 *)0x0) {
          if (local_ac[0x1f] == (undefined1 *)0x0) goto LAB_004a371b;
          *(undefined1 **)(puVar1 + 0xc) = local_ac[0x1f];
          goto LAB_004a3722;
        }
        if (*(uint *)(local_ac[0x1f] + 0x14) < *(uint *)(puVar4 + 0x14)) {
          *(undefined1 **)(puVar1 + 0xc) = local_ac[0x1f];
          puVar1 = local_ac[0x1f];
          local_ac[0x1f] = *(undefined1 **)(local_ac[0x1f] + 0xc);
        }
        else {
          *(undefined1 **)(puVar1 + 0xc) = puVar4;
          puVar1 = puVar4;
          puVar4 = *(undefined1 **)(puVar4 + 0xc);
        }
      }
      if (puVar4 == (undefined1 *)0x0) {
LAB_004a371b:
        *(undefined4 *)(puVar1 + 0xc) = 0;
      }
      else {
        *(undefined1 **)(puVar1 + 0xc) = puVar4;
      }
LAB_004a3722:
      local_ac[0x1f] = local_20;
    }
  }
  iVar7 = 1;
  do {
    puVar1 = local_ac[iVar7];
    puVar2 = local_2c;
    while (puVar4 = puVar1, local_ac[0] != (undefined1 *)0x0) {
      if (puVar4 == (undefined1 *)0x0) {
        if (local_ac[0] == (undefined1 *)0x0) goto LAB_004a3784;
        *(undefined1 **)(puVar2 + 0xc) = local_ac[0];
        goto LAB_004a378b;
      }
      if (*(uint *)(local_ac[0] + 0x14) < *(uint *)(puVar4 + 0x14)) {
        *(undefined1 **)(puVar2 + 0xc) = local_ac[0];
        puVar1 = puVar4;
        puVar2 = local_ac[0];
        local_ac[0] = *(undefined1 **)(local_ac[0] + 0xc);
      }
      else {
        *(undefined1 **)(puVar2 + 0xc) = puVar4;
        puVar1 = *(undefined1 **)(puVar4 + 0xc);
        puVar2 = puVar4;
      }
    }
    if (puVar4 == (undefined1 *)0x0) {
LAB_004a3784:
      *(undefined4 *)(puVar2 + 0xc) = 0;
    }
    else {
      *(undefined1 **)(puVar2 + 0xc) = puVar4;
    }
LAB_004a378b:
    iVar7 = iVar7 + 1;
    local_ac[0] = local_20;
    if (0x1f < iVar7) {
      return local_20;
    }
  } while( true );
}




/* [AUDIT] proposed: pcacheRelease_writeSubj  (confidence: med)
 * purpose: Release a page that is in savepoint state: write sub-journal then decrement pin and recycle
 * vars: param_1[6]&2; [7] pcache; [5]==1 page1
 */
/* Global::pcacheRelease_writeSubj @ 004a37a0 */

void __cdecl pcacheRelease_writeSubj(undefined4 *param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 6) & 2) != 0) {
    pcache_removeFromDirty((int)param_1);
  }
  iVar1 = param_1[7];
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -1;
  if (param_1[5] == 1) {
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  (*DAT_00582b4c)(*(undefined4 *)(iVar1 + 0x28),*param_1,1);
  return;
}




/* [AUDIT] proposed: sqlite3PcacheFetch  (confidence: high)
 * purpose: Fetch/create a page slot in the page cache, recycling LRU when needed; return PgHdr in *param_4
 * vars: DAT_00582b3c create,0x2b48 fetch; param_3=createFlag; spill via [8] xStress
 */
/* Global::sqlite3PcacheFetch @ 004a37e0 */

int __cdecl sqlite3PcacheFetch(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  
  piVar4 = (int *)0x0;
  if ((param_1[10] == 0) && (param_3 != 0)) {
    iVar1 = (*DAT_00582b3c)(param_1[5],param_1[6] + 0x28,param_1[7]);
    if (iVar1 == 0) {
      return 7;
    }
    uVar5 = pager_pageToOffset((int)param_1);
    (*DAT_00582b40)(iVar1,(int)uVar5);
    param_1[10] = iVar1;
  }
  if ((param_1[7] == 0) || (*param_1 == 0)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  iVar1 = (iVar1 + 1) * param_3;
  if ((param_1[10] == 0) ||
     (piVar2 = (int *)(*DAT_00582b48)(param_1[10],param_2,iVar1), piVar2 == (int *)0x0)) {
    if (iVar1 != 1) goto LAB_004a3936;
    for (iVar3 = param_1[2];
        (iVar3 != 0 && ((*(short *)(iVar3 + 0x1a) != 0 || ((*(byte *)(iVar3 + 0x18) & 4) != 0))));
        iVar3 = *(int *)(iVar3 + 0x24)) {
    }
    param_1[2] = iVar3;
    if (iVar3 == 0) {
      for (iVar3 = param_1[1]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {
        if (*(short *)(iVar3 + 0x1a) == 0) goto LAB_004a38a5;
      }
    }
    else {
LAB_004a38a5:
      iVar3 = (*(code *)param_1[8])(param_1[9],iVar3);
      if ((iVar3 != 0) && (iVar3 != 5)) {
        return iVar3;
      }
    }
    piVar2 = (int *)(*DAT_00582b48)(param_1[10],param_2,2);
    if (piVar2 == (int *)0x0) goto LAB_004a3936;
  }
  piVar4 = (int *)piVar2[1];
  if (*piVar4 == 0) {
    piVar4[0] = 0;
    piVar4[1] = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    piVar4[6] = 0;
    piVar4[7] = 0;
    piVar4[8] = 0;
    piVar4[9] = 0;
    *piVar4 = (int)piVar2;
    piVar4[1] = *piVar2;
    piVar4[2] = (int)(piVar4 + 10);
    memset(piVar4 + 10,0,param_1[6]);
    piVar4[7] = (int)param_1;
    piVar4[5] = param_2;
  }
  if (*(short *)((int)piVar4 + 0x1a) == 0) {
    param_1[3] = param_1[3] + 1;
  }
  *(short *)((int)piVar4 + 0x1a) = *(short *)((int)piVar4 + 0x1a) + 1;
  if (param_2 == 1) {
    param_1[0xb] = (int)piVar4;
  }
LAB_004a3936:
  *param_4 = piVar4;
  if ((piVar4 == (int *)0x0) && (iVar1 != 0)) {
    return 7;
  }
  return 0;
}




/* [AUDIT] proposed: pcacheMakeClean  (confidence: med)
 * purpose: Clear dirty flag on a page: write sub-journal, remove from dirty list, notify pcache backend
 * vars: param_1[6]&2; DAT_00582b4c notify
 */
/* Global::pcacheMakeClean @ 004a3950 */

void __cdecl pcacheMakeClean(undefined4 *param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 6) & 2) != 0) {
    pcache_removeFromDirty((int)param_1);
    *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff9;
    if ((*(short *)((int)param_1 + 0x1a) == 0) && (iVar1 = param_1[7], *(int *)(iVar1 + 0x1c) != 0))
    {
      if (param_1[5] == 1) {
        *(undefined4 *)(iVar1 + 0x2c) = 0;
      }
      (*DAT_00582b4c)(*(undefined4 *)(iVar1 + 0x28),*param_1,0);
    }
  }
  return;
}




/* [AUDIT] proposed: pcacheManageDirtyList_add  (confidence: high)
 * purpose: Add a page to the pager dirty list, maintaining head/tail/first-synced pointers
 * vars: +0x18 flags bit2; +0x1c PgHdr1 owner; +0x20 next
 */
/* Global::pcacheManageDirtyList_add @ 004a39a0 */

void __cdecl pcacheManageDirtyList_add(int param_1)

{
  int *piVar1;
  int iVar2;
  
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xffdf;
  if ((*(ushort *)(param_1 + 0x18) & 2) == 0) {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 2;
    piVar1 = *(int **)(param_1 + 0x1c);
    iVar2 = *piVar1;
    *(int *)(param_1 + 0x20) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x24) = param_1;
    }
    *piVar1 = param_1;
    if (piVar1[1] == 0) {
      piVar1[1] = param_1;
    }
    if ((piVar1[2] == 0) && ((*(byte *)(param_1 + 0x18) & 4) == 0)) {
      piVar1[2] = param_1;
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3PcacheMove  (confidence: high)
 * purpose: Rekey a cached page to new pgno via pcache xRekey, re-adding to dirty list if applicable
 * vars: DAT_00582b50 xRekey; param_1[5] pgno=param_2
 */
/* Global::sqlite3PcacheMove @ 004a39f0 */

void __cdecl sqlite3PcacheMove(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  (*DAT_00582b50)(*(undefined4 *)(param_1[7] + 0x28),*param_1,param_1[5],param_2);
  param_1[5] = param_2;
  if (((*(ushort *)(param_1 + 6) & 2) != 0) && ((*(ushort *)(param_1 + 6) & 4) != 0)) {
    pcache_removeFromDirty((int)param_1);
    piVar1 = (int *)param_1[7];
    iVar2 = *piVar1;
    param_1[8] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 0x24) = param_1;
    }
    *piVar1 = (int)param_1;
    if (piVar1[1] == 0) {
      piVar1[1] = (int)param_1;
    }
    if ((piVar1[2] == 0) && ((*(byte *)(param_1 + 6) & 4) == 0)) {
      piVar1[2] = (int)param_1;
    }
  }
  return;
}




/* [AUDIT] proposed: pagerFileSync  (confidence: low)
 * purpose: If VFS present, tail-call a file-control/sync method (jumptable via DAT_00582b44)
 * vars: +0x28 fd; DAT_00582b44
 */
/* Global::pagerFileSync @ 004a3a60 */

undefined4 __cdecl pagerFileSync(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    uVar1 = (*DAT_00582b44)();
    return uVar1;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3PcacheRelease  (confidence: high)
 * purpose: Drop one page reference; when zero, either write sub-journal & recycle or return to clean LRU
 * vars: nRef at +0x1a; [7] pcache; [6]&2 dirty
 */
/* Global::sqlite3PcacheRelease @ 004a3a80 */

void __cdecl sqlite3PcacheRelease(undefined4 *param_1)

{
  short *psVar1;
  int iVar2;
  int *piVar3;
  
  psVar1 = (short *)((int)param_1 + 0x1a);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    *(int *)(param_1[7] + 0xc) = *(int *)(param_1[7] + 0xc) + -1;
    if ((*(byte *)(param_1 + 6) & 2) == 0) {
      iVar2 = param_1[7];
      if (*(int *)(iVar2 + 0x1c) != 0) {
        if (param_1[5] == 1) {
          *(undefined4 *)(iVar2 + 0x2c) = 0;
        }
        (*DAT_00582b4c)(*(undefined4 *)(iVar2 + 0x28),*param_1,0);
        return;
      }
    }
    else {
      pcache_removeFromDirty((int)param_1);
      piVar3 = (int *)param_1[7];
      iVar2 = *piVar3;
      param_1[8] = iVar2;
      if (iVar2 != 0) {
        *(undefined4 **)(iVar2 + 0x24) = param_1;
      }
      *piVar3 = (int)param_1;
      if (piVar3[1] == 0) {
        piVar3[1] = (int)param_1;
      }
      if ((piVar3[2] == 0) && ((*(byte *)(param_1 + 6) & 4) == 0)) {
        piVar3[2] = (int)param_1;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: pcacheTruncate  (confidence: high)
 * purpose: Discard cached pages with pgno>=param_2 (write sub-journal), zero page1 buffer, resize pcache
 * vars: param_1[10] pcache; DAT_00582b54 truncate; param_1[0xb] page1
 */
/* Global::pcacheTruncate @ 004a3b00 */

void __cdecl pcacheTruncate(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1[10] != 0) {
    puVar1 = (undefined4 *)*param_1;
    while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar3[8];
      if ((param_2 < (uint)puVar3[5]) && ((*(byte *)(puVar3 + 6) & 2) != 0)) {
        pcache_removeFromDirty((int)puVar3);
        *(ushort *)(puVar3 + 6) = *(ushort *)(puVar3 + 6) & 0xfff9;
        if ((*(short *)((int)puVar3 + 0x1a) == 0) &&
           (iVar2 = puVar3[7], *(int *)(iVar2 + 0x1c) != 0)) {
          if (puVar3[5] == 1) {
            *(undefined4 *)(iVar2 + 0x2c) = 0;
          }
          (*DAT_00582b4c)(*(undefined4 *)(iVar2 + 0x28),*puVar3,0);
        }
      }
    }
    if ((param_2 == 0) && (param_1[0xb] != 0)) {
      memset(*(void **)(param_1[0xb] + 4),0,param_1[5]);
      param_2 = 1;
    }
    (*DAT_00582b54)(param_1[10],param_2 + 1);
  }
  return;
}




/* [AUDIT] proposed: sqlite3Prepare  (confidence: high)
 * purpose: SQLite 3.7.15.2 sqlite3Prepare: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: database schema is locked: %s|statement too long
 * vars: -
 */
/* Global::sqlite3Prepare @ 004a5af0 */

uint __cdecl
sqlite3Prepare(int param_1,void *param_2,size_t param_3,byte param_4,int param_5,undefined4 *param_6,
            int *param_7)

{
  int *piVar1;
  int *_Dst;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  size_t _Size;
  int iVar5;
  uint uVar6;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  _Dst = sqlite3PageMalloc(param_1,0x230);
  if (_Dst == (int *)0x0) {
    uVar2 = 7;
  }
  else {
    memset(_Dst,0,0x230);
    _Dst[0x7c] = param_5;
    local_c = 0;
    if (0 < *(int *)(param_1 + 0x14)) {
      local_10 = 0;
      do {
        puVar3 = *(undefined4 **)(local_10 + 4 + *(int *)(param_1 + 0x10));
        if ((puVar3 != (undefined4 *)0x0) && (uVar2 = btreeCheckReadConflicts(puVar3), uVar2 != 0)) {
          sqlite3ErrorWithMsg(param_1,uVar2,(byte *)"database schema is locked: %s");
          goto LAB_004a5e39;
        }
        local_c = local_c + 1;
        local_10 = local_10 + 0x10;
      } while (local_c < *(int *)(param_1 + 0x14));
    }
    sqlite3VtabUnlockList(param_1);
    *_Dst = param_1;
    _Dst[0x6e] = 0;
    _Dst[0x6f] = 0x3ff00000;
    if (((int)param_3 < 0) || ((param_3 != 0 && (*(char *)((int)param_2 + (param_3 - 1)) == '\0'))))
    {
      sqlite3RunParser(_Dst,(int)param_2,(int *)&local_8);
    }
    else {
      if (*(int *)(param_1 + 0x54) < (int)param_3) {
        sqlite3ErrorWithMsg(param_1,0x12,(byte *)"statement too long");
        uVar2 = 0x12;
        if (*(char *)(param_1 + 0x38) != '\0') {
          sqlite3ErrorWithMsg(param_1,7,(byte *)0x0);
          *(undefined1 *)(param_1 + 0x38) = 0;
          uVar2 = 7;
        }
        uVar2 = *(uint *)(param_1 + 0x30) & uVar2;
        goto LAB_004a5e39;
      }
      if ((param_2 == (void *)0x0) ||
         (puVar3 = sqlite3PageMalloc(param_1,param_3 + 1), puVar3 == (undefined4 *)0x0)) {
        _Dst[0x7e] = (int)param_2 + param_3;
      }
      else {
        memcpy(puVar3,param_2,param_3);
        *(undefined1 *)((int)puVar3 + param_3) = 0;
        sqlite3RunParser(_Dst,(int)puVar3,(int *)&local_8);
        sqlite3PageFree(param_1,puVar3);
        _Dst[0x7e] = (int)param_2 + (_Dst[0x7e] - (int)puVar3);
      }
    }
    if (*(char *)(param_1 + 0x38) != '\0') {
      _Dst[3] = 7;
    }
    if (_Dst[3] == 0x65) {
      _Dst[3] = 0;
    }
    if (*(char *)((int)_Dst + 0x11) != '\0') {
      vdbe_commitAllBtrees(_Dst);
    }
    if (*(char *)(param_1 + 0x38) != '\0') {
      _Dst[3] = 7;
    }
    if (param_7 != (int *)0x0) {
      *param_7 = _Dst[0x7e];
    }
    uVar2 = _Dst[3];
    if (((uVar2 == 0) && (piVar1 = (int *)_Dst[2], piVar1 != (int *)0x0)) &&
       ((char)_Dst[0x75] != '\0')) {
      if ((char)_Dst[0x75] == '\x02') {
        sqlite3VdbeResizeMemArray(piVar1,4);
        uVar6 = 8;
        uVar4 = 0xc;
      }
      else {
        sqlite3VdbeResizeMemArray(piVar1,8);
        uVar6 = 0;
        uVar4 = 8;
      }
      if (uVar6 < uVar4) {
        iVar5 = 0;
        do {
          if (*(char *)(*(int *)_Dst[2] + 0x38) == '\0') {
            sqlite3VdbeMemSetStr((int *)(((int *)_Dst[2])[4] + iVar5),(&PTR_DAT_0056a254)[uVar6],0xffffffff,
                         '\x01',(undefined *)0x0);
          }
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x28;
        } while ((int)uVar6 < (int)uVar4);
      }
    }
    if (*(char *)(param_1 + 0x81) == '\0') {
      piVar1 = (int *)_Dst[2];
      _Size = _Dst[0x7e] - (int)param_2;
      if (piVar1 != (int *)0x0) {
        puVar3 = (undefined4 *)0x0;
        if ((param_2 != (void *)0x0) &&
           (puVar3 = sqlite3PageMalloc(*piVar1,_Size + 1), puVar3 != (undefined4 *)0x0)) {
          memcpy(puVar3,param_2,_Size);
          *(undefined1 *)((int)puVar3 + _Size) = 0;
        }
        piVar1[0x26] = (int)puVar3;
        piVar1[0x18] = piVar1[0x18] ^ ((uint)param_4 << 9 ^ piVar1[0x18]) & 0x200;
      }
    }
    piVar1 = (int *)_Dst[2];
    if ((piVar1 == (int *)0x0) || ((uVar2 == 0 && (*(char *)(param_1 + 0x38) == '\0')))) {
      *param_6 = piVar1;
    }
    else {
      sqlite3VdbeDelete(piVar1);
    }
    if (local_8 == (undefined4 *)0x0) {
      sqlite3ErrorWithMsg(param_1,uVar2,(byte *)0x0);
    }
    else {
      sqlite3ErrorWithMsg(param_1,uVar2,&DAT_0056de50);
      sqlite3PageFree(param_1,local_8);
    }
    iVar5 = _Dst[0x8a];
    while (iVar5 != 0) {
      puVar3 = (undefined4 *)_Dst[0x8a];
      _Dst[0x8a] = puVar3[1];
      sqlite3PageFree(param_1,puVar3);
      iVar5 = _Dst[0x8a];
    }
  }
LAB_004a5e39:
  sqlite3PageFree(param_1,_Dst);
  if (param_1 != 0) {
    if ((*(char *)(param_1 + 0x38) != '\0') || (uVar2 == 0xc0a)) {
      sqlite3ErrorWithMsg(param_1,7,(byte *)0x0);
      *(undefined1 *)(param_1 + 0x38) = 0;
      uVar2 = 7;
    }
    return *(uint *)(param_1 + 0x30) & uVar2;
  }
  return uVar2 & 0xff;
}




/* [AUDIT] proposed: sqlite3Put4byte  (confidence: high)
 * purpose: Write a 4-byte big-endian unsigned int to buffer
 * vars: stores param_2 MSB-first
 */
/* Global::sqlite3Put4byte @ 004a5f90 */

void __cdecl sqlite3Put4byte(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 0x18);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[3] = (char)param_2;
  return;
}




/* [AUDIT] proposed: sqlite3Realloc  (confidence: high)
 * purpose: Reallocate memory via configured xRealloc with mem-stat accounting and soft-heap alarm
 * vars: DAT_00582af0 xRealloc; sqlite3MallocAlarm alarm; size guard 0x7ffffeff
 */
/* Global::sqlite3Realloc @ 004a6140 */

int __cdecl sqlite3Realloc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar1 = sqlite3Malloc(param_2);
    return iVar1;
  }
  if (param_2 < 1) {
    sqlite3_free(param_1);
    return 0;
  }
  if (0x7ffffeff < param_2) {
    return 0;
  }
  iVar1 = (*DAT_00582af0._4_4_)(param_1);
  iVar2 = (*DAT_00582af8)(param_2);
  if (iVar1 == iVar2) {
    return param_1;
  }
  if (DAT_00582ac8 == 0) {
    iVar1 = (*(code *)DAT_00582af0)(param_1,iVar2);
    return iVar1;
  }
  if (DAT_00583f40 != 0) {
    (*DAT_00582b18)(DAT_00583f40);
  }
  sqlite3StatusSet(5,param_2);
  uVar3 = iVar2 - iVar1;
  iVar4 = (DAT_00583f4c - ((int)uVar3 >> 0x1f)) - (uint)(DAT_00583f48 < uVar3);
  if ((iVar4 <= (int)DAT_00583e18 >> 0x1f) &&
     ((iVar4 < (int)DAT_00583e18 >> 0x1f || (DAT_00583f48 - uVar3 <= DAT_00583e18)))) {
    sqlite3MallocAlarm(uVar3);
  }
  iVar4 = (*(code *)DAT_00582af0)(param_1,iVar2);
  if (iVar4 == 0) {
    if (DAT_00583f50 == 0) goto LAB_004a6253;
    sqlite3MallocAlarm(param_2);
    iVar4 = (*(code *)DAT_00582af0)(param_1,iVar2);
    if (iVar4 == 0) goto LAB_004a6253;
  }
  iVar2 = (*DAT_00582af0._4_4_)(iVar4);
  sqlite3StatusUp(0,iVar2 - iVar1);
LAB_004a6253:
  if (DAT_00583f40 == 0) {
    return iVar4;
  }
  (*DAT_00582b20)(DAT_00583f40);
  return iVar4;
}




/* [AUDIT] proposed: sqlite3RegisterBuiltinFunctions  (confidence: high)
 * purpose: Populate global function hash with built-in scalar/aggregate FuncDefs, then date/time & like
 * vars: base &DAT_00582ce8; calls 4a6530, func_buildHash
 */
/* Global::sqlite3RegisterBuiltinFunctions @ 004a65c0 */

void sqlite3RegisterBuiltinFunctions(void)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  
  puVar8 = &DAT_00582ce8;
  do {
    pbVar2 = *(byte **)(puVar8 + 0x18);
    uVar6 = 0;
    if (pbVar2 != (byte *)0x0) {
      bVar1 = *pbVar2;
      pbVar5 = pbVar2;
      while (bVar1 != 0) {
        pbVar5 = pbVar5 + 1;
        bVar1 = *pbVar5;
      }
      uVar6 = (int)pbVar5 - (int)pbVar2 & 0x3fffffff;
    }
    uVar7 = ((byte)(&DAT_00569620)[*pbVar2] + uVar6) % 0x17;
    iVar4 = hash_findEntry(0x583f68,uVar7,pbVar2,uVar6);
    if (iVar4 == 0) {
      uVar3 = *(undefined4 *)(&DAT_00583f68 + uVar7 * 4);
      *(undefined4 *)(puVar8 + 8) = 0;
      *(undefined4 *)(puVar8 + 0x1c) = uVar3;
      *(undefined **)(&DAT_00583f68 + uVar7 * 4) = puVar8;
    }
    else {
      *(undefined4 *)(puVar8 + 8) = *(undefined4 *)(iVar4 + 8);
      *(undefined **)(iVar4 + 8) = puVar8;
    }
    puVar8 = puVar8 + 0x24;
  } while ((int)puVar8 < 0x58345c);
  registerDateTimeFunctions();
  func_buildHash();
  return;
}




/* [AUDIT] proposed: sqlite3ExprListClearList  (confidence: med)
 * purpose: Free a null-terminated list of pager-managed allocations (head *param_1), reset owner header
 * vars: iVar1 pager owner; recycles via free-list; resets +6,[2],[3],[5]
 */
/* Global::sqlite3ExprListClearList @ 004a6e20 */

void __cdecl sqlite3ExprListClearList(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)*param_1;
joined_r0x004a6e2b:
  do {
    if (puVar3 == (undefined4 *)0x0) {
      *param_1 = 0;
      *(undefined2 *)(param_1 + 6) = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[5] = 0;
      *(undefined1 *)((int)param_1 + 0x1a) = 1;
      return;
    }
    iVar1 = param_1[1];
    puVar2 = (undefined4 *)*puVar3;
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 0x1f0) != 0) {
        if ((puVar3 < *(undefined4 **)(iVar1 + 0x104)) ||
           (*(undefined4 **)(iVar1 + 0x108) <= puVar3)) {
          iVar4 = (*DAT_00582af0._4_4_)(puVar3);
          **(int **)(iVar1 + 0x1f0) = **(int **)(iVar1 + 0x1f0) + iVar4;
          puVar3 = puVar2;
        }
        else {
          **(int **)(iVar1 + 0x1f0) = **(int **)(iVar1 + 0x1f0) + (uint)*(ushort *)(iVar1 + 0xe8);
          puVar3 = puVar2;
        }
        goto joined_r0x004a6e2b;
      }
      if ((*(undefined4 **)(iVar1 + 0x104) <= puVar3) && (puVar3 < *(undefined4 **)(iVar1 + 0x108)))
      {
        *puVar3 = *(undefined4 *)(iVar1 + 0x100);
        *(int *)(iVar1 + 0xec) = *(int *)(iVar1 + 0xec) + -1;
        *(undefined4 **)(iVar1 + 0x100) = puVar3;
        puVar3 = puVar2;
        goto joined_r0x004a6e2b;
      }
    }
    sqlite3_free((int)puVar3);
    puVar3 = puVar2;
  } while( true );
}




/* [AUDIT] proposed: sqlite3SafetyCheckOk  (confidence: high)
 * purpose: Validate db connection magic word, reporting misuse(0x15) on null/invalid pointer
 * vars: +0x44 magic -0x5fd65969=OPEN; 'API call with %s database connection pointer'
 */
/* Global::sqlite3SafetyCheckOk @ 004a7850 */

undefined4 __cdecl sqlite3SafetyCheckOk(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    sqlite3_log(0x15,"API call with %s database connection pointer");
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x44);
  if (iVar1 != -0x5fd65969) {
    if ((iVar1 != 0x4b771290) && (iVar1 != -0xfc486fa)) {
      sqlite3_log(0x15,"API call with %s database connection pointer");
      return 0;
    }
    sqlite3_log(0x15,"API call with %s database connection pointer");
    return 0;
  }
  return 1;
}




/* [AUDIT] proposed: sqlite3SchemaClear  (confidence: high)
 * purpose: Reset a schema object: delete all Tables, Indices, Triggers, Views and collations, mark reset
 * vars: +8 tblHash; +0x10 idxHash; +0x28/0x30 trig/collate; sqlite3DeleteTable deleteTable
 */
/* Global::sqlite3SchemaClear @ 004a7960 */

void __cdecl sqlite3SchemaClear(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined8 local_24;
  undefined8 local_1c;
  undefined8 local_14;
  undefined8 local_c;
  
  local_24 = *(undefined8 *)(param_1 + 8);
  local_1c = *(undefined8 *)(param_1 + 0x10);
  local_14 = *(undefined8 *)(param_1 + 0x28);
  local_c = *(undefined8 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  sqlite3PageFreeList((undefined4 *)(param_1 + 0x18));
  for (puVar2 = (undefined4 *)local_c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2)
  {
    piVar1 = (int *)puVar2[2];
    if (piVar1 != (int *)0x0) {
      sqlite3SelectDelete(0,(undefined4 *)piVar1[7]);
      sqlite3_free(*piVar1);
      sqlite3_free(piVar1[1]);
      sqlite3ExprDelete(0,(undefined4 *)piVar1[3]);
      sqlite3IdListDelete(0,(int *)piVar1[4]);
      sqlite3_free((int)piVar1);
    }
  }
  sqlite3PageFreeList((undefined4 *)&local_14);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  for (puVar2 = (undefined4 *)local_1c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2)
  {
    sqlite3DeleteTable(0,(undefined4 *)puVar2[2]);
  }
  sqlite3PageFreeList((undefined4 *)&local_24);
  sqlite3PageFreeList((undefined4 *)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x48) = 0;
  if ((*(ushort *)(param_1 + 0x4e) & 1) != 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    *(ushort *)(param_1 + 0x4e) = *(ushort *)(param_1 + 0x4e) & 0xfffe;
  }
  return;
}




/* [AUDIT] proposed: sqlite3SchemaGet  (confidence: high)
 * purpose: Get or allocate (0x54) the shared Schema for a Btree, resetting its fields; set OOM on fail
 * vars: iVar2 Btree pager; +0x30 schema; +0x34 xFree=SchemaClear
 */
/* Global::sqlite3SchemaGet @ 004a7a80 */

void * __cdecl sqlite3SchemaGet(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    pvVar3 = (void *)sqlite3Malloc(0x54);
    if (pvVar3 == (void *)0x0) goto LAB_004a7b11;
    memset(pvVar3,0,0x54);
  }
  else {
    iVar2 = param_2[1];
    btree_enter(param_2);
    if (*(int *)(iVar2 + 0x30) == 0) {
      pvVar3 = (void *)sqlite3Malloc(0x54);
      if (pvVar3 != (void *)0x0) {
        memset(pvVar3,0,0x54);
      }
      *(void **)(iVar2 + 0x30) = pvVar3;
      *(code **)(iVar2 + 0x34) = sqlite3SchemaClear;
    }
    if (*(char *)((int)param_2 + 9) != '\0') {
      piVar1 = param_2 + 3;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        if (*(int *)(param_2[1] + 0x38) != 0) {
          (*DAT_00582b20)(*(int *)(param_2[1] + 0x38));
        }
        *(undefined1 *)((int)param_2 + 10) = 0;
      }
    }
    pvVar3 = *(void **)(iVar2 + 0x30);
  }
  if (pvVar3 != (void *)0x0) {
    if (*(char *)((int)pvVar3 + 0x4c) == '\0') {
      *(undefined4 *)((int)pvVar3 + 0x10) = 0;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0;
      *(undefined4 *)((int)pvVar3 + 8) = 0;
      *(undefined4 *)((int)pvVar3 + 0x14) = 0;
      *(undefined4 *)((int)pvVar3 + 0x20) = 0;
      *(undefined4 *)((int)pvVar3 + 0x1c) = 0;
      *(undefined4 *)((int)pvVar3 + 0x18) = 0;
      *(undefined4 *)((int)pvVar3 + 0x24) = 0;
      *(undefined4 *)((int)pvVar3 + 0x30) = 0;
      *(undefined4 *)((int)pvVar3 + 0x2c) = 0;
      *(undefined4 *)((int)pvVar3 + 0x28) = 0;
      *(undefined4 *)((int)pvVar3 + 0x34) = 0;
      *(undefined4 *)((int)pvVar3 + 0x40) = 0;
      *(undefined4 *)((int)pvVar3 + 0x3c) = 0;
      *(undefined4 *)((int)pvVar3 + 0x38) = 0;
      *(undefined4 *)((int)pvVar3 + 0x44) = 0;
      *(undefined1 *)((int)pvVar3 + 0x4d) = 1;
    }
    return pvVar3;
  }
LAB_004a7b11:
  *(undefined1 *)(param_1 + 0x38) = 1;
  return (void *)0x0;
}




/* [AUDIT] proposed: pcache1Free  (confidence: high)
 * purpose: Free a page buffer: return to configured page-buffer pool or heap, updating slot/mem counters
 * vars: DAT_00582b70..0x583f58 pool range; DAT_00583f5c free head
 */
/* Global::pcache1Free @ 004a7be0 */

void __cdecl pcache1Free(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((param_1 < DAT_00582b70) || (DAT_00583f58 <= param_1)) {
      if (DAT_00582ac8 == 0) {
        (*DAT_00582aec)(param_1);
      }
      else {
        iVar1 = (*DAT_00582af0._4_4_)(param_1);
        if (DAT_00583f40 != 0) {
          (*DAT_00582b18)(DAT_00583f40);
        }
        DAT_00583e28 = DAT_00583e28 - iVar1;
        if (DAT_00583e50 < DAT_00583e28) {
          DAT_00583e50 = DAT_00583e28;
        }
        DAT_00583e18 = DAT_00583e18 - iVar1;
        if (DAT_00583e40 < DAT_00583e18) {
          DAT_00583e40 = DAT_00583e18;
        }
        DAT_00583e3c = DAT_00583e3c + -1;
        if (DAT_00583e64 < DAT_00583e3c) {
          DAT_00583e64 = DAT_00583e3c;
        }
        (*DAT_00582aec)(param_1);
        if (DAT_00583f40 != 0) {
          (*DAT_00582b20)();
          return;
        }
      }
    }
    else {
      if (DAT_00583f40 != 0) {
        (*DAT_00582b18)(DAT_00583f40);
      }
      *param_1 = DAT_00583f5c;
      DAT_00583f60 = DAT_00583f60 + 1;
      DAT_00583e24 = DAT_00583e24 + -1;
      if (DAT_00583e4c < DAT_00583e24) {
        DAT_00583e4c = DAT_00583e24;
      }
      DAT_00583f5c = param_1;
      if (DAT_00583f40 != 0) {
        (*DAT_00582b20)();
        return;
      }
    }
  }
  return;
}




/* [AUDIT] proposed: pcache1Alloc  (confidence: high)
 * purpose: Allocate a page buffer from configured page-buffer pool free-list, else tracked heap
 * vars: DAT_00583f60 free count; DAT_00582b74 pageSize; sqlite3_mallocRaw
 */
/* Global::pcache1Alloc @ 004a7d10 */


undefined4 * __cdecl pcache1Alloc(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *local_8;
  
  if (DAT_00583f40 != 0) {
    (*DAT_00582b18)(DAT_00583f40);
  }
  puVar2 = DAT_00583f5c;
  if ((DAT_00583f60 != 0) && (param_1 <= DAT_00582b74)) {
    DAT_00583f60 = DAT_00583f60 + -1;
    _DAT_00583e38 = param_1;
    DAT_00583f5c = (undefined4 *)*DAT_00583f5c;
    DAT_00583e24 = DAT_00583e24 + 1;
    if (DAT_00583e4c < DAT_00583e24) {
      DAT_00583e4c = DAT_00583e24;
    }
    if (DAT_00583e60 < param_1) {
      DAT_00583e60 = param_1;
    }
    if (DAT_00583f40 != 0) {
      (*DAT_00582b20)(DAT_00583f40);
    }
    return puVar2;
  }
  if (DAT_00582ac8 == 0) {
    if (DAT_00583f40 != 0) {
      (*DAT_00582b20)(DAT_00583f40);
    }
    puVar2 = (undefined4 *)(*DAT_00582ae8)(param_1);
    return puVar2;
  }
  if (DAT_00583e60 < param_1) {
    DAT_00583e60 = param_1;
  }
  _DAT_00583e38 = param_1;
  uVar1 = sqlite3_mallocRaw(param_1,(int *)&local_8);
  if ((local_8 != (undefined4 *)0x0) &&
     (DAT_00583e28 = DAT_00583e28 + uVar1, DAT_00583e50 < DAT_00583e28)) {
    DAT_00583e50 = DAT_00583e28;
  }
  if (DAT_00583f40 != 0) {
    (*DAT_00582b20)(DAT_00583f40);
  }
  return local_8;
}




/* [AUDIT] proposed: sqlite3WindowListDelete_or_Cte  (confidence: med)
 * purpose: If non-null, walk/free a substructure (sqlite3_exprDelete) then free the node itself
 * vars: sqlite3_exprDelete sub-free + PageFree
 */
/* Global::sqlite3WindowListDelete_or_Cte @ 004a9650 */

void __cdecl sqlite3WindowListDelete_or_Cte(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    sqlite3_exprDelete(param_1,param_2);
    sqlite3PageFree(param_1,param_2);
  }
  return;
}




/* [AUDIT] proposed: sqlite3SetString  (confidence: high)
 * purpose: Format string with sqlite3VXPrintf into StrAccum, free old *param_1 and store result
 * vars: local StrAccum 0x50; sqlite3VXPrintf vprintf; sqlite3StrAccumFinish finish
 */
/* Global::sqlite3SetString @ 004a9a30 */

void __cdecl sqlite3SetString(int *param_1,int param_2,byte *param_3)

{
  int iVar1;
  int local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  char local_54;
  undefined2 local_53;
  undefined1 local_50 [72];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_68 = local_50;
  local_58 = *(undefined4 *)(param_2 + 0x50);
  local_60 = 0;
  local_5c = 0x46;
  local_53 = 1;
  local_54 = '\0';
  local_6c = param_2;
  local_64 = local_68;
  sqlite3VXPrintf(&local_6c,1,param_3,(double *)&stack0x00000010);
  iVar1 = sqlite3StrAccumFinish(&local_6c);
  if (local_54 != '\0') {
    *(undefined1 *)(param_2 + 0x38) = 1;
  }
  sqlite3PageFree(param_2,(undefined4 *)*param_1);
  *param_1 = iVar1;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: sqlite3SrcListDelete  (confidence: high)
 * purpose: Free a SrcList: for each item free names/aliases, index, on/using exprs & subquery Select
 * vars: *param_2 nSrc; stride 0x24 shorts; sqlite3DeleteTable deleteTable
 */
/* Global::sqlite3SrcListDelete @ 004a9cb0 */

void __cdecl sqlite3SrcListDelete(int param_1,short *param_2)

{
  undefined4 *puVar1;
  short *psVar2;
  int local_8;
  
  if (param_2 != (short *)0x0) {
    local_8 = 0;
    if (0 < *param_2) {
      psVar2 = param_2 + 8;
      do {
        sqlite3PageFree(param_1,*(undefined4 **)(psVar2 + -2));
        sqlite3PageFree(param_1,*(undefined4 **)psVar2);
        sqlite3PageFree(param_1,*(undefined4 **)(psVar2 + 2));
        sqlite3PageFree(param_1,*(undefined4 **)(psVar2 + 0x1c));
        sqlite3DeleteTable(param_1,*(undefined4 **)(psVar2 + 4));
        puVar1 = *(undefined4 **)(psVar2 + 6);
        if (puVar1 != (undefined4 *)0x0) {
          sqlite3_exprDelete(param_1,puVar1);
          sqlite3PageFree(param_1,puVar1);
        }
        sqlite3ExprDelete(param_1,*(undefined4 **)(psVar2 + 0x14));
        sqlite3IdListDelete(param_1,*(int **)(psVar2 + 0x16));
        local_8 = local_8 + 1;
        psVar2 = psVar2 + 0x24;
      } while (local_8 < *param_2);
    }
    sqlite3PageFree(param_1,(undefined4 *)param_2);
  }
  return;
}




/* [AUDIT] proposed: sqlite3StatusUp  (confidence: high)
 * purpose: Increment mem-status counter[param_1] by param_2 and update its high-water mark
 * vars: &DAT_00583e18 stat array; +0x28 highwater
 */
/* Global::sqlite3StatusUp @ 004aa580 */

void __cdecl sqlite3StatusUp(int param_1,int param_2)

{
  (&DAT_00583e18)[param_1] = (&DAT_00583e18)[param_1] + param_2;
  if ((int)(&DAT_00583e40)[param_1] < (int)(&DAT_00583e18)[param_1]) {
    (&DAT_00583e40)[param_1] = (&DAT_00583e18)[param_1];
  }
  return;
}




/* [AUDIT] proposed: sqlite3StatusSet  (confidence: high)
 * purpose: Set mem-status counter[param_1]=param_2 and update its high-water mark
 * vars: &DAT_00583e18 base
 */
/* Global::sqlite3StatusSet @ 004aa5b0 */

void __cdecl sqlite3StatusSet(int param_1,int param_2)

{
  (&DAT_00583e18)[param_1] = param_2;
  if ((int)(&DAT_00583e40)[param_1] < param_2) {
    (&DAT_00583e40)[param_1] = param_2;
  }
  return;
}




/* [AUDIT] proposed: sqlite3Step  (confidence: high)
 * purpose: Execute one step of a prepared statement (VdbeExec or Explain), profile timing, map errors
 * vars: magic 0xbdf20da3; sqlite3VdbeExec VdbeExec; sqlite3VdbeList VdbeList; [0x16] rc
 */
/* Global::sqlite3Step @ 004aa5e0 */

uint __cdecl sqlite3Step(uint *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint local_c;
  int local_8;
  
  if (param_1[0xc] != 0xbdf20da3) {
    sqlite3_reset((int *)param_1);
  }
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)(puVar1 + 0xe) == '\0') {
    if (((int)param_1[0x15] < 1) && ((param_1[0x18] & 0x20) != 0)) {
      param_1[0x16] = 0x11;
      uVar4 = 1;
    }
    else {
      if ((int)param_1[0x15] < 0) {
        if (puVar1[0x21] == 0) {
          puVar1[0x38] = 0;
        }
        if ((puVar1[0x28] != 0) && (*(char *)((int)puVar1 + 0x81) == '\0')) {
          sqlite3OsCurrentTimeInt64((int *)*puVar1,(ulonglong *)(param_1 + 0x20));
        }
        puVar1[0x21] = puVar1[0x21] + 1;
        if ((param_1[0x18] & 0x100) == 0) {
          puVar1[0x22] = puVar1[0x22] + 1;
        }
        param_1[0x15] = 0;
      }
      if ((param_1[0x18] & 3) == 0) {
        puVar1[0x23] = puVar1[0x23] + 1;
        uVar4 = sqlite3VdbeExec(param_1);
        puVar1[0x23] = puVar1[0x23] + -1;
      }
      else {
        uVar4 = sqlite3VdbeList((int *)param_1);
      }
      if ((((uVar4 != 100) && (puVar1[0x28] != 0)) && (*(char *)((int)puVar1 + 0x81) == '\0')) &&
         (param_1[0x26] != 0)) {
        sqlite3OsCurrentTimeInt64((int *)*puVar1,(ulonglong *)&local_c);
        lVar5 = __allmul(local_c - param_1[0x20],
                         (local_8 - param_1[0x21]) - (uint)(local_c < param_1[0x20]),1000000,0);
        (*(code *)puVar1[0x28])(puVar1[0x29],param_1[0x26],lVar5);
      }
      if (uVar4 == 0x65) {
        uVar2 = vdbe_runVtabCommit((int)puVar1);
        param_1[0x16] = uVar2;
        if (uVar2 != 0) {
          uVar4 = 1;
        }
      }
      puVar1[0xb] = uVar4;
      uVar2 = *param_1;
      uVar3 = param_1[0x16];
      if (uVar2 == 0) {
        uVar2 = 0xff;
      }
      else {
        if ((*(char *)(uVar2 + 0x38) != '\0') || (uVar3 == 0xc0a)) {
          sqlite3ErrorWithMsg(uVar2,7,(byte *)0x0);
          *(undefined1 *)(uVar2 + 0x38) = 0;
          uVar3 = 7;
        }
        uVar2 = *(uint *)(uVar2 + 0x30);
      }
      if ((uVar2 & uVar3) == 7) {
        param_1[0x16] = 7;
      }
    }
    if ((((param_1[0x18] & 0x200) != 0) && (uVar4 != 100)) && (uVar4 != 0x65)) {
      uVar4 = sqlite3VdbeTransferError((int *)param_1);
    }
    return puVar1[0xc] & uVar4;
  }
  param_1[0x16] = 7;
  return 7;
}




/* [AUDIT] proposed: sqlite3StrAccumAppend  (confidence: high)
 * purpose: Append text to a StrAccum, growing buffer (realloc/PageMalloc) or setting overflow/OOM flags
 * vars: +3 nChar; +4 nAlloc; +0x18 accError; +0x19 useMalloc
 */
/* Global::sqlite3StrAccumAppend @ 004aa7b0 */

void __cdecl sqlite3StrAccumAppend(int *param_1,char *param_2,size_t param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *_Dst;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  if ((char)param_1[6] == '\0' && *(char *)((int)param_1 + 0x1a) == '\0') {
    if ((int)param_3 < 0) {
      if (param_2 == (char *)0x0) {
        return;
      }
      cVar3 = *param_2;
      pcVar8 = param_2;
      while (cVar3 != '\0') {
        pcVar8 = pcVar8 + 1;
        cVar3 = *pcVar8;
      }
      param_3 = (int)pcVar8 - (int)param_2 & 0x3fffffff;
    }
    if (param_3 == 0) {
      return;
    }
    if (param_2 == (char *)0x0) {
      return;
    }
    if (param_1[4] <= (int)(param_1[3] + param_3)) {
      if (*(char *)((int)param_1 + 0x19) == '\0') {
        param_3 = (param_1[4] - param_1[3]) - 1;
        *(undefined1 *)((int)param_1 + 0x1a) = 1;
        if ((int)param_3 < 1) {
          return;
        }
      }
      else {
        puVar5 = (undefined4 *)param_1[2];
        if (puVar5 == (undefined4 *)param_1[1]) {
          puVar5 = (undefined4 *)0x0;
        }
        uVar1 = param_3 + 1;
        uVar4 = param_1[3];
        uVar2 = uVar1 + uVar4;
        iVar6 = ((int)uVar1 >> 0x1f) + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar1,uVar4);
        iVar7 = param_1[5] >> 0x1f;
        if ((iVar7 <= iVar6) && ((iVar7 < iVar6 || ((uint)param_1[5] < uVar2)))) {
          sqlite3StrAccumReset(param_1);
          *(undefined1 *)((int)param_1 + 0x1a) = 1;
          return;
        }
        param_1[4] = uVar2;
        if (*(char *)((int)param_1 + 0x19) == '\x01') {
          _Dst = sqlite3PageRealloc(*param_1,puVar5,uVar2);
        }
        else {
          iVar6 = sqlite3_initialize();
          if (iVar6 != 0) goto LAB_004aa8d5;
          _Dst = (undefined4 *)sqlite3Realloc((int)puVar5,uVar2);
        }
        if (_Dst == (undefined4 *)0x0) {
LAB_004aa8d5:
          *(undefined1 *)(param_1 + 6) = 1;
          sqlite3StrAccumReset(param_1);
          return;
        }
        if ((puVar5 == (undefined4 *)0x0) && (0 < param_1[3])) {
          memcpy(_Dst,(void *)param_1[2],param_1[3]);
        }
        param_1[2] = (int)_Dst;
      }
    }
    memcpy((void *)(param_1[2] + param_1[3]),param_2,param_3);
    param_1[3] = param_1[3] + param_3;
  }
  return;
}




/* [AUDIT] proposed: sqlite3StrAccumFinish  (confidence: high)
 * purpose: NUL-terminate a StrAccum and, if using page buffer, copy result to a heap/db allocation
 * vars: param_1[1] base buf; +0x19 mallocFlag; +6 OOM
 */
/* Global::sqlite3StrAccumFinish @ 004aa8f0 */

int __cdecl sqlite3StrAccumFinish(int *param_1)

{
  int iVar1;
  undefined4 *_Dst;
  int iVar2;
  
  if (param_1[2] != 0) {
    *(undefined1 *)(param_1[2] + param_1[3]) = 0;
    iVar1 = param_1[2];
    if (*(char *)((int)param_1 + 0x19) == '\0') {
      return iVar1;
    }
    if (iVar1 != param_1[1]) {
      return iVar1;
    }
    if (*(char *)((int)param_1 + 0x19) == '\x01') {
      _Dst = sqlite3PageMalloc(*param_1,param_1[3] + 1);
    }
    else {
      iVar1 = param_1[3];
      iVar2 = sqlite3_initialize();
      if (iVar2 == 0) {
        _Dst = (undefined4 *)sqlite3Malloc(iVar1 + 1);
      }
      else {
        _Dst = (undefined4 *)0x0;
      }
    }
    param_1[2] = (int)_Dst;
    if (_Dst != (undefined4 *)0x0) {
      memcpy(_Dst,(void *)param_1[1],param_1[3] + 1);
      return param_1[2];
    }
    *(undefined1 *)(param_1 + 6) = 1;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3StrAccumReset  (confidence: high)
 * purpose: Reset a StrAccum, freeing its heap/db buffer if it differs from the static base
 * vars: param_1[2] text vs [1] base; +0x19 useMalloc
 */
/* Global::sqlite3StrAccumReset @ 004aa970 */

void __cdecl sqlite3StrAccumReset(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[2];
  if (puVar1 != (undefined4 *)param_1[1]) {
    if (*(char *)((int)param_1 + 0x19) == '\x01') {
      sqlite3PageFree(*param_1,puVar1);
      param_1[2] = 0;
      return;
    }
    sqlite3_free((int)puVar1);
  }
  param_1[2] = 0;
  return;
}




/* [AUDIT] proposed: sqlite3Strlen30  (confidence: high)
 * purpose: Return length of a C string masked to 30 bits (0 for null)
 * vars: & 0x3fffffff
 */
/* Global::sqlite3Strlen30 @ 004aa9b0 */

uint __cdecl sqlite3Strlen30(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    pcVar2 = param_1;
    while (cVar1 != '\0') {
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    }
    return (int)pcVar2 - (int)param_1 & 0x3fffffff;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeFrameRestore  (confidence: med)
 * purpose: Restore VDBE Mem-cell array from a saved frame: release externals, copy back saved cells
 * vars: param_1+0x4c nMem; [0x11] aMem; per-cell 0x28
 */
/* Global::sqlite3VdbeFrameRestore @ 004aac10 */

undefined4 __thiscall sqlite3VdbeFrameRestore(void *this,int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  undefined8 *puVar4;
  int iVar5;
  
  if (*(int *)(*param_2 + 0xc) != 0) {
    (*DAT_00582b18)(*(int *)(*param_2 + 0xc),this);
  }
  iVar5 = 0;
  if (0 < *(short *)(param_1 + 0x4c)) {
    iVar2 = 0;
    do {
      uVar1 = *(ushort *)(param_2[0x11] + 0x1c + iVar2);
      piVar3 = (int *)(param_2[0x11] + iVar2);
      puVar4 = (undefined8 *)(*(int *)(param_1 + 0x44) + iVar2);
      if ((uVar1 & 0x2460) != 0) {
        if ((uVar1 & 0x2000) == 0) {
          if (((uVar1 & 0x400) == 0) || ((code *)piVar3[8] == (code *)0x0)) {
            if ((uVar1 & 0x20) == 0) {
              if ((uVar1 & 0x40) != 0) {
                sqlite3VdbeMemClearExternAndSetNull((int)piVar3);
              }
            }
            else {
              sqlite3ExprListClearList((undefined4 *)piVar3[4]);
            }
          }
          else {
            (*(code *)piVar3[8])(piVar3[1]);
            piVar3[8] = 0;
          }
        }
        else {
          sqlite3VdbeMemFinalize(piVar3,piVar3[4]);
          sqlite3VdbeMemRelease(piVar3);
        }
      }
      sqlite3PageFree(*piVar3,(undefined4 *)piVar3[9]);
      piVar3[1] = 0;
      piVar3[9] = 0;
      piVar3[8] = 0;
      *(undefined8 *)piVar3 = *puVar4;
      *(undefined8 *)(piVar3 + 2) = puVar4[1];
      *(undefined8 *)(piVar3 + 4) = puVar4[2];
      *(undefined8 *)(piVar3 + 6) = puVar4[3];
      *(undefined8 *)(piVar3 + 8) = puVar4[4];
      *(undefined2 *)((int)puVar4 + 0x1c) = 1;
      *(undefined4 *)(puVar4 + 4) = 0;
      *(undefined4 *)((int)puVar4 + 0x24) = 0;
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 0x28;
    } while (iVar5 < *(short *)(param_1 + 0x4c));
  }
  if (*(int *)(*param_2 + 0xc) != 0) {
    (*DAT_00582b20)(*(int *)(*param_2 + 0xc));
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VXPrintf_toAccum  (confidence: high)
 * purpose: Format args into a temporary StrAccum via sqlite3VXPrintf, set OOM on connection if failed
 * vars: StrAccum 0x50; sqlite3VXPrintf core
 */
/* Global::sqlite3VXPrintf_toAccum @ 004ad2f0 */

void __cdecl sqlite3VXPrintf_toAccum(int param_1,byte *param_2,double *param_3)

{
  int local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  char local_54;
  undefined2 local_53;
  undefined1 local_50 [72];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_68 = local_50;
  local_58 = *(undefined4 *)(param_1 + 0x50);
  local_60 = 0;
  local_5c = 0x46;
  local_53 = 1;
  local_54 = '\0';
  local_6c = param_1;
  local_64 = local_68;
  sqlite3VXPrintf(&local_6c,1,param_2,param_3);
  sqlite3StrAccumFinish(&local_6c);
  if (local_54 != '\0') {
    *(undefined1 *)(param_1 + 0x38) = 1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: sqlite3VXPrintf  (confidence: high)
 * purpose: SQLite 3.7.15.2 sqlite3VXPrintf: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: 0123456789ABCDEF0123456789abcdef|thstndrd
 * vars: -
 */
/* Global::sqlite3VXPrintf @ 004ad370 */


void __cdecl sqlite3VXPrintf(int *param_1,int param_2,byte *param_3,double *param_4)

{
  byte bVar1;
  undefined4 *puVar2;
  byte bVar3;
  byte *pbVar4;
  char cVar5;
  size_t sVar6;
  int iVar7;
  int extraout_ECX;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *unaff_EBX;
  byte *pbVar11;
  char *pcVar12;
  double *pdVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  int *piVar17;
  bool bVar18;
  double dVar19;
  double dVar20;
  undefined8 uVar21;
  longlong lVar22;
  byte *local_a4;
  uint local_a0;
  byte *local_9c;
  undefined8 local_98;
  byte *local_90;
  byte *local_8c;
  undefined1 *local_88;
  byte *local_80;
  int *local_7c;
  byte *local_78;
  byte *local_74;
  byte *local_70;
  char local_6a;
  char local_69;
  byte local_68;
  bool local_67;
  bool local_66;
  char local_65;
  byte *local_64;
  byte local_5d;
  byte *local_5c;
  double *local_58;
  char local_52;
  byte local_51;
  byte local_50;
  int local_4f [17];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  bVar3 = *param_3;
  pbVar15 = (byte *)0x0;
  local_5c = (byte *)0x0;
  local_7c = param_1;
  local_58 = param_4;
  do {
    if (bVar3 == 0) {
switchD_004ad606_default:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    pbVar11 = param_3;
    if (bVar3 != 0x25) {
      local_78 = param_3 + 1;
      sVar6 = 1;
      bVar3 = *local_78;
      while ((bVar3 != 0x25 && (bVar18 = bVar3 != 0, bVar3 = 0, bVar18))) {
        pbVar15 = local_78 + 1;
        local_78 = local_78 + 1;
        sVar6 = sVar6 + 1;
        bVar3 = *pbVar15;
      }
      local_5c = param_3;
      sqlite3StrAccumAppend(local_7c,(char *)param_3,sVar6);
      pbVar11 = local_78;
      pbVar15 = param_3;
      if (bVar3 == 0) goto switchD_004ad606_default;
    }
    iVar7 = (int)(char)pbVar11[1];
    pbVar11 = pbVar11 + 1;
    if (iVar7 == 0) {
      sqlite3StrAccumAppend(local_7c,"%",1);
      goto switchD_004ad606_default;
    }
    local_69 = '\0';
    local_67 = false;
    local_68 = 0;
    local_51 = 0;
    local_5d = 0;
    local_65 = '\0';
    do {
      switch(iVar7) {
      case 0x20:
        local_51 = 1;
        break;
      case 0x21:
        local_67 = true;
        break;
      default:
        goto switchD_004ad464_caseD_22;
      case 0x23:
        local_68 = 1;
        break;
      case 0x2b:
        local_5d = 1;
        break;
      case 0x2d:
        local_65 = '\x01';
        break;
      case 0x30:
        local_69 = '\x01';
      }
      iVar7 = (int)(char)pbVar11[1];
      pbVar11 = pbVar11 + 1;
    } while (iVar7 != 0);
switchD_004ad464_caseD_22:
    local_64 = (byte *)0x0;
    if (iVar7 == 0x2a) {
      local_64 = *(byte **)local_58;
      local_58 = (double *)((int)local_58 + 4);
      if ((int)local_64 < 0) {
        local_64 = (byte *)-(int)local_64;
        local_65 = '\x01';
      }
      iVar7 = (int)(char)pbVar11[1];
      pbVar11 = pbVar11 + 1;
    }
    else if (0x2f < iVar7) {
      local_64 = (byte *)0x0;
      do {
        pbVar15 = local_5c;
        if (0x39 < iVar7) break;
        pbVar11 = pbVar11 + 1;
        local_64 = (byte *)(iVar7 + ((int)local_64 * 5 + -0x18) * 2);
        iVar7 = (int)(char)*pbVar11;
      } while (0x2f < iVar7);
    }
    if (iVar7 == 0x2e) {
      iVar7 = (int)(char)pbVar11[1];
      local_78 = pbVar11 + 1;
      local_74 = (byte *)0x0;
      if (iVar7 == 0x2a) {
        local_74 = *(byte **)local_58;
        if ((int)local_74 < 0) {
          local_74 = (byte *)-(int)local_74;
        }
        iVar7 = (int)(char)pbVar11[2];
        local_78 = pbVar11 + 2;
        local_58 = (double *)((int)local_58 + 4);
      }
      else {
        while ((0x2f < iVar7 && (iVar7 < 0x3a))) {
          local_78 = local_78 + 1;
          local_74 = (byte *)(iVar7 + ((int)local_74 * 5 + -0x18) * 2);
          iVar7 = (int)(char)*local_78;
        }
      }
    }
    else {
      local_74 = (byte *)0xffffffff;
      local_78 = pbVar11;
    }
    if (iVar7 == 0x6c) {
      iVar7 = (int)(char)local_78[1];
      local_66 = true;
      pbVar11 = local_78 + 1;
      if (iVar7 != 0x6c) goto LAB_004ad57d;
      iVar7 = (int)(char)local_78[2];
      local_78 = local_78 + 2;
      local_6a = '\x01';
    }
    else {
      local_66 = false;
      pbVar11 = local_78;
LAB_004ad57d:
      local_78 = pbVar11;
      local_6a = '\0';
    }
    local_88 = &DAT_00569ab8;
    local_52 = '\0';
    local_8c = (byte *)0x0;
    pcVar12 = "d\n\x01\x01";
    do {
      if (iVar7 == *pcVar12) {
        iVar7 = (int)local_8c * 6;
        local_88 = &DAT_00569ab8 + iVar7;
        if ((param_2 == 0) && (((&DAT_00569aba)[iVar7] & 2) != 0)) goto switchD_004ad606_default;
        local_52 = (&DAT_00569abb)[iVar7];
        break;
      }
      local_8c = local_8c + 1;
      pcVar12 = pcVar12 + 6;
    } while ((int)pcVar12 < 0x569b42);
    local_8c = (byte *)0x0;
    switch(local_52) {
    case '\x01':
    case '\x10':
      cVar5 = local_6a;
      goto LAB_004ad619;
    case '\x02':
    case '\x03':
    case '\x04':
      pdVar13 = local_58 + 1;
      local_98 = *local_58;
      if ((int)local_74 < 0) {
        local_74 = (byte *)0x6;
      }
      if (0.0 <= local_98) {
        if (local_5d == 0) {
          local_51 = -(local_51 != 0) & 0x20;
        }
        else {
          local_51 = 0x2b;
        }
      }
      else {
        local_98 = -local_98;
        local_51 = 0x2d;
      }
      if ((local_52 == '\x04') && (0 < (int)local_74)) {
        local_74 = local_74 + -1;
      }
      dVar19 = 0.5;
      pbVar15 = local_74;
      if (7 < (int)local_74) {
        iVar7 = ((uint)(local_74 + -8) >> 3) + 1;
        pbVar15 = local_74 + iVar7 * -8;
        do {
          dVar19 = dVar19 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      for (; 0 < (int)pbVar15; pbVar15 = pbVar15 + -1) {
        dVar19 = dVar19 * 0.1;
      }
      if (local_52 == '\x02') {
        local_98 = local_98 + dVar19;
      }
      pbVar15 = (byte *)0x0;
      local_80 = (byte *)0x0;
      local_58 = pdVar13;
      if (0.0 < local_98) {
        dVar20 = 1.0;
        if (1e+100 <= local_98) {
          do {
            local_80 = pbVar15;
            if (0x15e < (int)pbVar15) break;
            dVar20 = dVar20 * 1e+100;
            pbVar15 = pbVar15 + 100;
            local_80 = pbVar15;
          } while (dVar20 * 1e+100 <= local_98);
        }
        for (; (dVar20 * 1e+64 <= local_98 && ((int)local_80 < 0x15f)); local_80 = local_80 + 0x40)
        {
          dVar20 = dVar20 * 1e+64;
        }
        for (; (dVar20 * 100000000.0 <= local_98 && ((int)local_80 < 0x15f));
            local_80 = local_80 + 8) {
          dVar20 = dVar20 * 100000000.0;
        }
        for (; (dVar20 * 10.0 <= local_98 && ((int)local_80 < 0x15f)); local_80 = local_80 + 1) {
          dVar20 = dVar20 * 10.0;
        }
        for (local_98 = local_98 / dVar20; local_98 < 1e-08; local_98 = local_98 * 100000000.0) {
          local_80 = local_80 + -8;
        }
        for (; local_98 < 1.0; local_98 = local_98 * 10.0) {
          local_80 = local_80 + -1;
        }
        if (0x15e < (int)local_80) {
          if (local_51 == 0x2d) {
            local_5c = &DAT_0056ddbc;
          }
          else {
            local_5c = &DAT_0056ddc4;
            if (local_51 != 0x2b) {
              local_5c = &DAT_0056ddcc;
            }
          }
          if (local_5c == (byte *)0x0) goto LAB_004ae0a4;
          bVar3 = *local_5c;
          pbVar15 = local_5c;
          while (bVar3 != 0) {
            pbVar15 = pbVar15 + 1;
            bVar3 = *pbVar15;
          }
LAB_004adae6:
          pbVar11 = (byte *)((int)pbVar15 - (int)local_5c & 0x3fffffff);
          pbVar15 = local_5c;
          break;
        }
      }
      pbVar15 = &local_50;
      if ((local_52 != '\x02') && (local_98 = local_98 + dVar19, 10.0 <= local_98)) {
        local_98 = local_98 * 0.1;
        local_80 = local_80 + 1;
      }
      local_70 = local_80;
      if (local_52 == '\x04') {
        local_66 = local_68 == 0;
        if (((int)local_80 < -4) || ((int)local_74 < (int)local_80)) {
          local_52 = '\x03';
LAB_004adb4c:
          local_70 = (byte *)0x0;
        }
        else {
          local_74 = local_74 + -(int)local_80;
          local_52 = '\x02';
        }
      }
      else {
        local_66 = local_67;
        if (local_52 == '\x03') goto LAB_004adb4c;
      }
      if ((0x37 < (int)(local_70 + (int)local_74 + (int)local_64)) &&
         (pbVar15 = (byte *)sqlite3Malloc((int)(local_70 + (int)local_74 + (int)local_64 + 0xf)),
         local_8c = pbVar15, pbVar15 == (byte *)0x0)) goto LAB_004adfc7;
      local_90 = (byte *)((uint)local_67 * 10 + 0x10);
      local_5d = 0 < (int)local_74 | local_67 | local_68;
      pbVar11 = pbVar15;
      if (local_51 != 0) {
        *pbVar15 = local_51;
        pbVar11 = pbVar15 + 1;
      }
      dVar19 = local_98;
      if ((int)local_70 < 0) {
        *pbVar11 = 0x30;
        pbVar11 = pbVar11 + 1;
      }
      else {
        do {
          if ((int)local_90 < 1) {
            bVar3 = 0x30;
          }
          else {
            local_90 = local_90 + -1;
            bVar3 = (char)(int)dVar19 + 0x30;
            dVar19 = (dVar19 - (double)(int)dVar19) * 10.0;
          }
          *pbVar11 = bVar3;
          pbVar11 = pbVar11 + 1;
          local_70 = local_70 + -1;
        } while (-1 < (int)local_70);
      }
      if (local_5d != 0) {
        *pbVar11 = 0x2e;
        pbVar11 = pbVar11 + 1;
      }
      pbVar4 = local_70 + 1;
      pbVar14 = local_90;
      pbVar10 = local_74;
      if ((int)pbVar4 < 0) {
        local_70 = (byte *)-(int)pbVar4;
        pbVar16 = pbVar11;
        for (uVar9 = (uint)local_70 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          pbVar16[0] = 0x30;
          pbVar16[1] = 0x30;
          pbVar16[2] = 0x30;
          pbVar16[3] = 0x30;
          pbVar16 = pbVar16 + 4;
        }
        pbVar11 = pbVar11 + (int)local_70;
        pbVar10 = local_74 + (int)pbVar4;
        for (uVar9 = (uint)local_70 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pbVar16 = 0x30;
          pbVar16 = pbVar16 + 1;
        }
      }
      while (0 < (int)pbVar10) {
        if ((int)pbVar14 < 1) {
          bVar3 = 0x30;
        }
        else {
          pbVar14 = pbVar14 + -1;
          bVar3 = (char)(int)dVar19 + 0x30;
          dVar19 = (dVar19 - (double)(int)dVar19) * 10.0;
        }
        *pbVar11 = bVar3;
        pbVar11 = pbVar11 + 1;
        pbVar10 = pbVar10 + -1;
      }
      if ((local_66 != false) && (local_5d != 0)) {
        bVar3 = pbVar11[-1];
        pbVar14 = pbVar11 + -1;
        while (pbVar10 = pbVar14, bVar3 == 0x30) {
          *pbVar10 = 0;
          pbVar14 = pbVar10 + -1;
          pbVar11 = pbVar10;
          bVar3 = pbVar10[-1];
        }
        if (pbVar11[-1] == 0x2e) {
          if (local_67 == false) {
            pbVar11 = pbVar11 + -1;
            *pbVar11 = 0;
          }
          else {
            *pbVar11 = 0x30;
            pbVar11 = pbVar11 + 1;
          }
        }
      }
      if (local_52 == '\x03') {
        *pbVar11 = "0123456789ABCDEF0123456789abcdef"[(byte)local_88[4]];
        if ((int)local_80 < 0) {
          pbVar11[1] = 0x2d;
          local_80 = (byte *)-(int)local_80;
        }
        else {
          pbVar11[1] = 0x2b;
        }
        pbVar14 = pbVar11 + 2;
        if (99 < (int)local_80) {
          *pbVar14 = (char)((int)local_80 / 100) + 0x30;
          pbVar14 = pbVar11 + 3;
          local_80 = (byte *)((int)local_80 % 100);
        }
        cVar5 = (char)((int)local_80 / 10);
        *pbVar14 = cVar5 + 0x30;
        pbVar14[1] = (char)local_80 + cVar5 * -10 + 0x30;
        pbVar11 = pbVar14 + 2;
      }
      *pbVar11 = 0;
      pbVar11 = pbVar11 + -(int)pbVar15;
      local_5c = pbVar15;
      if (local_69 == '\0') break;
      if (local_65 == '\0') {
        if ((int)pbVar11 < (int)local_64) {
          uVar9 = (int)local_64 - (int)pbVar11;
          if ((int)uVar9 <= (int)local_64) {
            pbVar11 = local_64;
            do {
              pbVar15[(int)pbVar11] = pbVar15[(int)pbVar11 - uVar9];
              pbVar11 = pbVar11 + -1;
            } while ((int)uVar9 <= (int)pbVar11);
          }
          pbVar11 = local_64;
          if (uVar9 != 0) {
            pbVar14 = pbVar15 + (local_51 != 0);
            for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              pbVar14[0] = 0x30;
              pbVar14[1] = 0x30;
              pbVar14[2] = 0x30;
              pbVar14[3] = 0x30;
              pbVar14 = pbVar14 + 4;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *pbVar14 = 0x30;
              pbVar14 = pbVar14 + 1;
            }
          }
        }
        goto LAB_004ae0af;
      }
      goto LAB_004ae0c1;
    case '\x05':
      **(int **)local_58 = local_7c[3];
      local_64 = (byte *)0x0;
      pbVar11 = (byte *)0x0;
      local_58 = (double *)((int)local_58 + 4);
      break;
    case '\x06':
    case '\a':
      pdVar13 = (double *)((int)local_58 + 4);
      local_5c = *(byte **)local_58;
      if (local_5c == (byte *)0x0) {
        local_5c = &DAT_0055b524;
      }
      else {
        local_8c = (byte *)0x0;
        if (local_52 == '\a') {
          local_8c = local_5c;
        }
      }
      pbVar15 = local_5c;
      local_58 = pdVar13;
      if ((int)local_74 < 0) {
        if (local_5c == (byte *)0x0) {
LAB_004ae0a4:
          pbVar11 = (byte *)0x0;
          pbVar15 = local_5c;
        }
        else {
          pbVar11 = local_5c;
          if (*local_5c == 0) goto LAB_004adae6;
          do {
            pbVar11 = pbVar11 + 1;
          } while (*pbVar11 != 0);
          pbVar11 = (byte *)((int)pbVar11 - (int)local_5c & 0x3fffffff);
        }
      }
      else {
        pbVar11 = (byte *)0x0;
        if (0 < (int)local_74) {
          do {
            if (local_5c[(int)pbVar11] == 0) break;
            pbVar11 = pbVar11 + 1;
          } while ((int)pbVar11 < (int)local_74);
        }
      }
      break;
    case '\b':
      local_50 = 0x25;
      pbVar11 = (byte *)0x1;
      pbVar15 = &local_50;
      local_5c = &local_50;
      break;
    case '\t':
      local_50 = (byte)*(uint *)local_58;
      if ((int)local_74 < 0) {
        pbVar11 = (byte *)0x1;
        pbVar15 = &local_50;
        local_5c = &local_50;
        local_58 = (double *)((int)local_58 + 4);
      }
      else {
        if (1 < (int)local_74) {
          iVar7 = (*(uint *)local_58 & 0xff) * 0x1010101;
          piVar17 = local_4f;
          for (uVar9 = (uint)(local_74 + -1) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *piVar17 = iVar7;
            piVar17 = piVar17 + 1;
          }
          for (uVar9 = (uint)(local_74 + -1) & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(char *)piVar17 = (char)iVar7;
            piVar17 = (int *)((int)piVar17 + 1);
          }
        }
        pbVar11 = local_74;
        pbVar15 = &local_50;
        local_5c = &local_50;
        local_58 = (double *)((int)local_58 + 4);
      }
      break;
    case '\n':
    case '\v':
    case '\x0f':
      local_70 = (byte *)0x27;
      if (local_52 == '\x0f') {
        local_70 = (byte *)0x22;
      }
      local_80 = *(byte **)local_58;
      local_58 = (double *)((int)local_58 + 4);
      bVar18 = local_80 == (byte *)0x0;
      local_98 = (double)(ulonglong)CONCAT14(bVar18,(undefined4)local_98);
      if ((bVar18) && (local_80 = &DAT_0056ddd0, local_52 != '\v')) {
        local_80 = &DAT_0056ddd8;
      }
      iVar7 = 0;
      pbVar15 = local_74;
      for (local_90 = (byte *)0x0; (pbVar15 != (byte *)0x0 && (local_90[(int)local_80] != 0));
          local_90 = local_90 + 1) {
        if (local_90[(int)local_80] == (byte)local_70) {
          iVar7 = iVar7 + 1;
        }
        pbVar15 = pbVar15 + -1;
      }
      if ((bVar18) || (local_52 != '\v')) {
        local_88 = (undefined1 *)0x0;
      }
      else {
        local_88 = (undefined1 *)0x1;
      }
      pbVar15 = local_90 + iVar7 + 1 + (int)local_88 * 2;
      if ((int)pbVar15 < 0x47) {
        local_5c = &local_50;
      }
      else {
        if (pbVar15 + -1 < (byte *)0x7ffffeff) {
          if (DAT_00582ac8 == 0) {
            local_a4 = (byte *)(*DAT_00582ae8)(pbVar15);
          }
          else {
            if (DAT_00583f40 != 0) {
              (*DAT_00582b18)(DAT_00583f40);
            }
            sqlite3_mallocRaw((int)pbVar15,(int *)&local_a4);
            if (DAT_00583f40 != 0) {
              (*DAT_00582b20)(DAT_00583f40);
            }
          }
        }
        else {
          local_a4 = (byte *)0x0;
        }
        local_8c = local_a4;
        local_5c = local_a4;
        if (local_a4 == (byte *)0x0) goto LAB_004adfc7;
      }
      bVar3 = (byte)local_70;
      if (local_88 != (undefined1 *)0x0) {
        *local_5c = bVar3;
      }
      pbVar11 = (byte *)(uint)(local_88 != (undefined1 *)0x0);
      iVar7 = 0;
      pbVar15 = pbVar11;
      if (0 < (int)local_90) {
        do {
          pbVar11 = pbVar15 + 1;
          bVar1 = local_80[iVar7];
          local_5c[(int)pbVar15] = bVar1;
          if (bVar1 == bVar3) {
            local_5c[(int)pbVar11] = bVar1;
            pbVar11 = pbVar15 + 2;
          }
          iVar7 = iVar7 + 1;
          pbVar15 = pbVar11;
        } while (iVar7 < (int)local_90);
      }
      if (local_88 != (undefined1 *)0x0) {
        local_5c[(int)pbVar11] = bVar3;
        pbVar11 = pbVar11 + 1;
      }
      local_5c[(int)pbVar11] = 0;
      pbVar15 = local_5c;
      break;
    case '\f':
      pdVar13 = (double *)((int)local_58 + 4);
      puVar2 = *(undefined4 **)local_58;
      local_58 = pdVar13;
      if (puVar2 != (undefined4 *)0x0) {
        sVar6 = puVar2[1];
        pcVar12 = (char *)*puVar2;
        goto LAB_004ae045;
      }
      goto LAB_004ae050;
    case '\r':
      pdVar13 = local_58 + 1;
      iVar7 = *(int *)local_58;
      local_98 = (double)CONCAT44(*(int *)((int)local_58 + 4) * 9,(undefined4)local_98);
      pcVar12 = *(char **)(iVar7 + 0xc + *(int *)((int)local_58 + 4) * 0x48);
      local_58 = pdVar13;
      if (pcVar12 != (char *)0x0) {
        sqlite3StrAccumAppend(local_7c,pcVar12,0xffffffff);
        sqlite3StrAccumAppend(local_7c,".",1);
      }
      sVar6 = 0xffffffff;
      pcVar12 = *(char **)(iVar7 + 0x10 + local_98._4_4_ * 8);
LAB_004ae045:
      sqlite3StrAccumAppend(local_7c,pcVar12,sVar6);
LAB_004ae050:
      local_64 = (byte *)0x0;
      pbVar11 = (byte *)0x0;
      break;
    case '\x0e':
      cVar5 = '\0';
LAB_004ad619:
      if ((local_88[2] & 1) == 0) {
        if (cVar5 == '\0') {
          local_80 = *(byte **)local_58;
          pdVar13 = (double *)((int)local_58 + 4);
          local_5c = (byte *)0x0;
        }
        else {
          local_80 = *(byte **)local_58;
          pdVar13 = local_58 + 1;
          local_5c = *(byte **)((int)local_58 + 4);
        }
        local_51 = 0;
        local_58 = pdVar13;
      }
      else {
        if (cVar5 == '\0') {
          local_80 = *(byte **)local_58;
          local_58 = (double *)((int)local_58 + 4);
          local_5c = (byte *)((int)local_80 >> 0x1f);
        }
        else {
          local_80 = *(byte **)local_58;
          local_5c = *(byte **)((int)local_58 + 4);
          local_58 = local_58 + 1;
        }
        if (((int)local_5c < 1) && ((int)local_5c < 0)) {
          if ((local_80 == (byte *)0x0) && (local_5c == (byte *)0x80000000)) {
            local_51 = 0x2d;
          }
          else {
            bVar18 = local_80 != (byte *)0x0;
            local_80 = (byte *)-(int)local_80;
            local_5c = (byte *)-(int)(local_5c + bVar18);
            local_51 = 0x2d;
          }
        }
        else if (local_5d == 0) {
          local_51 = -(local_51 != 0) & 0x20;
        }
        else {
          local_51 = 0x2b;
        }
      }
      if (local_80 == (byte *)0x0 && local_5c == (byte *)0x0) {
        local_68 = 0;
      }
      if ((local_69 != '\0') && ((int)local_74 < (int)(local_64 + -(uint)(local_51 != 0)))) {
        local_74 = local_64 + -(uint)(local_51 != 0);
      }
      if ((int)local_74 < 0x3c) {
        pbVar15 = (byte *)0x46;
        local_90 = &local_50;
        local_70 = (byte *)0x46;
      }
      else {
        pbVar15 = local_74 + 10;
        local_70 = pbVar15;
        local_90 = (byte *)sqlite3Malloc((int)pbVar15);
        local_8c = local_90;
        if (local_90 == (byte *)0x0) {
LAB_004adfc7:
          *(undefined1 *)(local_7c + 6) = 1;
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      pbVar15 = local_90 + (int)(pbVar15 + -1);
      if (local_52 == '\x10') {
        uVar21 = __aulldiv((uint)local_80,(uint)local_5c,10,0);
        local_a0 = (uint)uVar21;
        local_9c = local_80 + local_a0 * -10;
        if ((3 < (int)local_9c) ||
           (lVar22 = __aullrem(local_a0,(uint)((ulonglong)uVar21 >> 0x20),10,0), lVar22 == 1)) {
          local_9c = (byte *)0x0;
        }
        pbVar15[-1] = "thstndrd"[(int)local_9c * 2 + 1];
        pbVar15 = pbVar15 + -2;
        *pbVar15 = "thstndrd"[(int)local_9c * 2];
      }
      local_98 = (double)CONCAT44("0123456789ABCDEF0123456789abcdef" + (byte)local_88[4],
                                  (undefined4)local_98);
      local_a0 = (uint)(byte)local_88[1];
      lVar22 = CONCAT44(local_5c,local_80);
      local_9c = (byte *)0x0;
      do {
        pbVar11 = unaff_EBX;
        pbVar15 = pbVar15 + -1;
        unaff_EBX = pbVar11;
        lVar22 = __aulldvrm((uint)lVar22,(uint)((ulonglong)lVar22 >> 0x20),local_a0,(uint)local_9c);
        *pbVar15 = *(byte *)(extraout_ECX + local_98._4_4_);
        local_80 = pbVar11;
      } while (lVar22 != 0);
      local_5c = pbVar15;
      for (pbVar11 = pbVar15 + (int)(local_74 + (-(int)local_70 - (int)local_90) + 1);
          0 < (int)pbVar11; pbVar11 = pbVar11 + -1) {
        local_5c = local_5c + -1;
        *local_5c = 0x30;
      }
      if (local_51 != 0) {
        local_5c = local_5c + -1;
        *local_5c = local_51;
      }
      if ((local_68 != 0) && (local_88[5] != 0)) {
        pbVar15 = &DAT_00569ab0 + (byte)local_88[5];
        bVar3 = *pbVar15;
        while (bVar3 != 0) {
          local_5c = local_5c + -1;
          pbVar15 = pbVar15 + 1;
          *local_5c = bVar3;
          bVar3 = *pbVar15;
        }
      }
      pbVar11 = local_90 + (int)(local_70 + (-1 - (int)local_5c));
      pbVar15 = local_5c;
      break;
    default:
      goto switchD_004ad606_default;
    }
    if (local_65 == '\0') {
LAB_004ae0af:
      if (0 < (int)local_64 - (int)pbVar11) {
        strAccum_appendSpaces(local_7c,(int)local_64 - (int)pbVar11);
      }
    }
LAB_004ae0c1:
    if (0 < (int)pbVar11) {
      sqlite3StrAccumAppend(local_7c,(char *)pbVar15,(size_t)pbVar11);
    }
    if ((local_65 != '\0') && (0 < (int)local_64 - (int)pbVar11)) {
      strAccum_appendSpaces(local_7c,(int)local_64 - (int)pbVar11);
    }
    sqlite3_free((int)local_8c);
    param_3 = local_78 + 1;
    bVar3 = *param_3;
  } while( true );
}




/* [AUDIT] proposed: sqlite3VdbeMemRelease_free  (confidence: med)
 * purpose: Release a Mem's external resources (flag 0x2460) and its dynamic buffer, then free the Mem
 * vars: param_1+7 flags; [9] zMalloc; sqlite3VdbeMemReleaseExternal clearExt
 */
/* Global::sqlite3VdbeMemRelease_free @ 004ae2b0 */

void __cdecl sqlite3VdbeMemRelease_free(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if ((*(ushort *)(param_1 + 7) & 0x2460) != 0) {
      sqlite3VdbeMemReleaseExternal(param_1);
    }
    sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
    param_1[1] = 0;
    param_1[9] = 0;
    param_1[8] = 0;
    sqlite3PageFree(*param_1,param_1);
  }
  return;
}




/* [AUDIT] proposed: sqlite3ValueNew  (confidence: high)
 * purpose: Allocate and zero-init a Mem (0x28) value with type-null/encoding defaults
 * vars: flags +0x1c=1; +0x1e enc=5(UTF8)
 */
/* Global::sqlite3ValueNew @ 004ae630 */

void __cdecl sqlite3ValueNew(int param_1)

{
  int *piVar1;
  
  piVar1 = sqlite3PageMalloc(param_1,0x28);
  if (piVar1 != (int *)0x0) {
    piVar1[0] = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    *(undefined2 *)(piVar1 + 7) = 1;
    *(undefined1 *)((int)piVar1 + 0x1e) = 5;
    *piVar1 = param_1;
  }
  return;
}




/* [AUDIT] proposed: sqlite3ValueApplyAffinity  (confidence: med)
 * purpose: Coerce a Mem value to target affinity/encoding (numeric, text, blob-to-text) as needed
 * vars: param_2 affinity; sqlite3VdbeMemStringify stringify; sqlite3VdbeMemTranslate xlate
 */
/* Global::sqlite3ValueApplyAffinity @ 004ae680 */

int __cdecl sqlite3ValueApplyAffinity(int *param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (uVar1 = *(ushort *)(param_1 + 7), (uVar1 & 1) != 0)) {
    return 0;
  }
  *(ushort *)(param_1 + 7) = uVar1 >> 3 & 2 | uVar1;
  if ((uVar1 & 0x4000) != 0) {
    sqlite3VdbeMemExpandBlob(param_1);
  }
  if ((*(byte *)(param_1 + 7) & 2) == 0) {
    sqlite3VdbeMemStringify(param_1,(uint)param_2);
  }
  else {
    if (*(byte *)((int)param_1 + 0x1f) != (param_2 & 0xf7)) {
      sqlite3VdbeMemTranslate(param_1,param_2 & 0xf7);
    }
    if ((((param_2 & 8) != 0) && ((param_1[1] & 1U) != 0)) &&
       (iVar2 = sqlite3VdbeMemMakeWriteable(param_1), iVar2 != 0)) {
      return 0;
    }
    sqlite3VdbeMemNulTerminate(param_1);
  }
  if (*(byte *)((int)param_1 + 0x1f) != (param_2 & 0xf7)) {
    return 0;
  }
  return param_1[1];
}




/* [AUDIT] proposed: sqlite3VdbeChangeEncoding  (confidence: high)
 * purpose: If Mem holds text (flag 2) with wrong encoding, translate it via sqlite3VdbeMemTranslate
 * vars: +0x1f enc; sqlite3VdbeMemTranslate
 */
/* Global::sqlite3VdbeChangeEncoding @ 004aec30 */

undefined4 __cdecl sqlite3VdbeChangeEncoding(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((*(byte *)(param_1 + 7) & 2) != 0) && (*(byte *)((int)param_1 + 0x1f) != param_2)) {
    uVar1 = sqlite3VdbeMemTranslate(param_1,(char)param_2);
    return uVar1;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeFreeCursorsAndProgram  (confidence: high)
 * purpose: Free a VDBE program: op array (aOp), aColName, sub-programs, aVar, result columns, aMem
 * vars: +0x44 aColName; +0xb0 pProgram list; +0x48 apVar; per-op 0x14 stride
 */
/* Global::sqlite3VdbeFreeCursorsAndProgram @ 004aef00 */

void __cdecl sqlite3VdbeFreeCursorsAndProgram(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  
  vdbe_releaseMemArray(*(int **)(param_2 + 0x44),(int)*(short *)(param_2 + 0x4c));
  vdbe_releaseMemArray(*(int **)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x2c) * 2);
  puVar3 = *(undefined4 **)(param_2 + 0xb0);
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar3;
    puVar2 = (undefined4 *)puVar3[6];
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 < puVar1 + puVar3[1] * 5)) {
      pcVar5 = (char *)((int)puVar1 + 1);
      iVar4 = (uint)((int)(puVar1 + puVar3[1] * 5) + (-1 - (int)puVar1)) / 0x14 + 1;
      do {
        vdbe_freeP4(param_1,(int)*pcVar5,*(int **)(pcVar5 + 0xf));
        pcVar5 = pcVar5 + 0x14;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    sqlite3PageFree(param_1,puVar1);
    sqlite3PageFree(param_1,puVar3);
    puVar3 = puVar2;
  }
  iVar4 = (int)*(short *)(param_2 + 0x4e);
  while (iVar4 = iVar4 + -1, -1 < iVar4) {
    sqlite3PageFree(param_1,*(undefined4 **)(*(int *)(param_2 + 0x48) + iVar4 * 4));
  }
  puVar3 = *(undefined4 **)(param_2 + 4);
  if ((puVar3 != (undefined4 *)0x0) && (puVar3 < puVar3 + *(int *)(param_2 + 0x1c) * 5)) {
    pcVar5 = (char *)((int)puVar3 + 1);
    iVar4 = (uint)((int)(puVar3 + *(int *)(param_2 + 0x1c) * 5) + (-1 - (int)puVar3)) / 0x14 + 1;
    do {
      vdbe_freeP4(param_1,(int)*pcVar5,*(int **)(pcVar5 + 0xf));
      pcVar5 = pcVar5 + 0x14;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  sqlite3PageFree(param_1,puVar3);
  sqlite3PageFree(param_1,*(undefined4 **)(param_2 + 0x28));
  sqlite3PageFree(param_1,*(undefined4 **)(param_2 + 0x10));
  sqlite3PageFree(param_1,*(undefined4 **)(param_2 + 0x98));
  sqlite3PageFree(param_1,*(undefined4 **)(param_2 + 0x9c));
  return;
}




/* [AUDIT] proposed: sqlite3VdbeDeleteAuxData  (confidence: high)
 * purpose: Free auxdata (sqlite3_set_auxdata) entries not preserved by mask, invoking each xDelete
 * vars: param_1[1] count; mask param_2; piVar1[3] xDelete
 */
/* Global::sqlite3VdbeDeleteAuxData @ 004af2b0 */

void __cdecl sqlite3VdbeDeleteAuxData(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar1 = param_1;
  if (0 < param_1[1]) {
    do {
      piVar3 = piVar1 + 2;
      if (((0x1f < iVar2) || ((param_2 & 1 << ((byte)iVar2 & 0x1f)) == 0)) && (*piVar3 != 0)) {
        if ((code *)piVar1[3] != (code *)0x0) {
          (*(code *)piVar1[3])(*piVar3);
        }
        *piVar3 = 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar3;
    } while (iVar2 < param_1[1]);
  }
  return;
}




/* [AUDIT] proposed: sqlite3VdbeDelete  (confidence: high)
 * purpose: Finalize and unlink a VDBE from the connection's prepared-statement list, then free it
 * vars: magic -0x420df25d; +0xe/0xf prev/next links; sqlite3VdbeFreeCursorsAndProgram clear
 */
/* Global::sqlite3VdbeDelete @ 004b5e70 */

uint __cdecl sqlite3VdbeDelete(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((param_1[0xc] == -0x420df25d) || (param_1[0xc] == 0x519c2973)) {
    uVar2 = sqlite3VdbeHalt(param_1);
  }
  iVar1 = *param_1;
  sqlite3VdbeFreeCursorsAndProgram(iVar1,(int)param_1);
  if (param_1[0xe] == 0) {
    *(int *)(iVar1 + 4) = param_1[0xf];
  }
  else {
    *(int *)(param_1[0xe] + 0x3c) = param_1[0xf];
  }
  if (param_1[0xf] != 0) {
    *(int *)(param_1[0xf] + 0x38) = param_1[0xe];
  }
  param_1[0xc] = -0x49f93c38;
  *param_1 = 0;
  sqlite3PageFree(iVar1,param_1);
  return uVar2;
}




/* [AUDIT] proposed: sqlite3VdbeList  (confidence: high)
 * purpose: Produce EXPLAIN / EXPLAIN QUERY PLAN result rows from a VDBE's op array
 * vars: 'unknown error','interrupted'; modes param_1[0x18]&3; opcode names PTR_DAT_0056a750
 */
/* Global::sqlite3VdbeList @ 004b67d0 */

undefined4 __cdecl sqlite3VdbeList(int *param_1)

{
  byte *pbVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int local_18;
  int local_14;
  int *local_10;
  uint local_c;
  
  iVar7 = param_1[2];
  iVar6 = *param_1;
  piVar11 = (int *)(iVar7 + 0x28);
  piVar10 = (int *)0x0;
  local_c = 0;
  local_10 = (int *)0x0;
  vdbe_releaseMemArray(piVar11,8);
  param_1[5] = 0;
  if (param_1[0x16] == 7) {
    *(undefined1 *)(iVar6 + 0x38) = 1;
  }
  else {
    local_18 = param_1[7];
    if ((param_1[0x18] & 3U) == 1) {
      iVar8 = param_1[2];
      local_10 = (int *)(iVar8 + 0x168);
      if ((*(byte *)(iVar8 + 0x184) & 0x10) != 0) {
        piVar10 = *(int **)(iVar8 + 0x16c);
        local_c = *(uint *)(iVar8 + 0x180) >> 2;
      }
      iVar8 = 0;
      local_14 = 0;
      local_18 = 0;
      if (1 < local_c) {
        local_14 = 0;
        local_18 = 0;
        iVar9 = iVar8;
        do {
          iVar8 = iVar9 + 2;
          local_14 = local_14 + *(int *)(piVar10[iVar9] + 4);
          local_18 = local_18 + *(int *)(piVar10[iVar9 + 1] + 4);
          iVar9 = iVar8;
        } while (iVar8 < (int)(local_c - 1));
      }
      iVar9 = param_1[7];
      if (iVar8 < (int)local_c) {
        iVar9 = iVar9 + *(int *)(piVar10[iVar8] + 4);
      }
      local_18 = iVar9 + local_14 + local_18;
    }
    do {
      iVar8 = param_1[0x15];
      param_1[0x15] = iVar8 + 1;
      if (local_18 <= iVar8) {
        param_1[0x16] = 0;
        return 0x65;
      }
    } while (((param_1[0x18] & 3U) == 2) && (*(char *)(param_1[1] + iVar8 * 0x14) != -0x6a));
    if (*(int *)(iVar6 + 0xe0) != 0) {
      param_1[0x16] = 9;
      sqlite3SetString(param_1 + 0xd,iVar6,&DAT_0056de50);
      return 1;
    }
    if (iVar8 < param_1[7]) {
      iVar6 = param_1[1];
    }
    else {
      iVar8 = iVar8 - param_1[7];
      iVar9 = 0;
      iVar6 = *(int *)(*piVar10 + 4);
      if (iVar6 <= iVar8) {
        do {
          iVar9 = iVar9 + 1;
          iVar8 = iVar8 - iVar6;
          iVar6 = *(int *)(piVar10[iVar9] + 4);
        } while (iVar6 <= iVar8);
      }
      iVar6 = *(int *)piVar10[iVar9];
    }
    pbVar1 = (byte *)(iVar6 + iVar8 * 0x14);
    if (((byte)param_1[0x18] & 3) == 1) {
      *(undefined2 *)(iVar7 + 0x44) = 4;
      *(int *)(iVar7 + 0x38) = iVar8;
      *(int *)(iVar7 + 0x3c) = iVar8 >> 0x1f;
      *(undefined1 *)(iVar7 + 0x46) = 1;
      *(undefined2 *)(iVar7 + 0x6c) = 0xa02;
      pcVar3 = (&PTR_DAT_0056a750)[*pbVar1];
      *(char **)(iVar7 + 0x54) = pcVar3;
      uVar5 = 0;
      if (pcVar3 != (char *)0x0) {
        cVar2 = *pcVar3;
        pcVar4 = pcVar3;
        while (cVar2 != '\0') {
          pcVar4 = pcVar4 + 1;
          cVar2 = *pcVar4;
        }
        uVar5 = (int)pcVar4 - (int)pcVar3 & 0x3fffffff;
      }
      *(uint *)(iVar7 + 0x68) = uVar5;
      *(undefined2 *)(iVar7 + 0x6e) = 0x103;
      piVar11 = (int *)(iVar7 + 0x78);
      if (pbVar1[1] == 0xee) {
        iVar7 = local_c * 4;
        uVar5 = 0;
        if (local_c != 0) {
          do {
            if (piVar10[uVar5] == *(int *)(pbVar1 + 0x10)) break;
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 < (int)local_c);
        }
        if ((uVar5 == local_c) &&
           (iVar6 = sqlite3VdbeMemGrow(local_10,iVar7 + 4,(uint)(local_c != 0)), iVar6 == 0)) {
          *(undefined4 *)(iVar7 + local_10[1]) = *(undefined4 *)(pbVar1 + 0x10);
          *(ushort *)(local_10 + 7) = *(ushort *)(local_10 + 7) | 0x10;
          local_10[6] = iVar7 + 4;
        }
      }
    }
    *(undefined2 *)(piVar11 + 7) = 4;
    iVar7 = *(int *)(pbVar1 + 4);
    *(undefined1 *)((int)piVar11 + 0x1e) = 1;
    piVar11[4] = iVar7;
    piVar11[5] = iVar7 >> 0x1f;
    *(undefined2 *)(piVar11 + 0x11) = 4;
    iVar7 = *(int *)(pbVar1 + 8);
    piVar11[0xe] = iVar7;
    piVar11[0xf] = iVar7 >> 0x1f;
    *(undefined1 *)((int)piVar11 + 0x46) = 1;
    *(undefined2 *)(piVar11 + 0x1b) = 4;
    iVar7 = *(int *)(pbVar1 + 0xc);
    piVar11[0x18] = iVar7;
    piVar11[0x19] = iVar7 >> 0x1f;
    *(undefined1 *)((int)piVar11 + 0x6e) = 1;
    iVar7 = sqlite3VdbeMemGrow(piVar11 + 0x1e,0x20,0);
    if (iVar7 == 0) {
      *(undefined2 *)(piVar11 + 0x25) = 0x602;
      pcVar4 = sqlite3_step_476d20((int)pbVar1,(char *)piVar11[0x1f],0x20);
      pcVar3 = (char *)piVar11[0x1f];
      if (pcVar4 == pcVar3) {
        uVar5 = 0;
        if (pcVar3 != (char *)0x0) {
          cVar2 = *pcVar3;
          pcVar4 = pcVar3;
          while (cVar2 != '\0') {
            pcVar4 = pcVar4 + 1;
            cVar2 = *pcVar4;
          }
          uVar5 = (int)pcVar4 - (int)pcVar3 & 0x3fffffff;
        }
        piVar11[0x24] = uVar5;
        *(undefined1 *)((int)piVar11 + 0x97) = 1;
      }
      else {
        sqlite3VdbeMemSetStr(piVar11 + 0x1e,pcVar4,0xffffffff,'\x01',(undefined *)0x0);
      }
      *(undefined1 *)((int)piVar11 + 0x96) = 3;
      if (((byte)param_1[0x18] & 3) == 1) {
        iVar7 = sqlite3VdbeMemGrow(piVar11 + 0x28,4,0);
        if (iVar7 != 0) {
          return 1;
        }
        *(undefined2 *)(piVar11 + 0x2f) = 0x602;
        piVar11[0x2e] = 2;
        sqlite3_snprintf_impl(3,piVar11[0x29],&DAT_0056e4f4);
        *(undefined2 *)((int)piVar11 + 0xbe) = 0x103;
        *(undefined2 *)(piVar11 + 0x39) = 1;
        *(undefined1 *)((int)piVar11 + 0xe6) = 5;
      }
      *(ushort *)(param_1 + 0xb) = (2 - ((*(ushort *)(param_1 + 0x18) & 3) - 1)) * 4;
      param_1[5] = param_1[2] + 0x28;
      param_1[0x16] = 0;
      return 100;
    }
  }
  return 1;
}




/* [AUDIT] proposed: sqlite3VdbeMemExpandBlob  (confidence: high)
 * purpose: Materialize a zero-padded blob (MEM_Zero flag 0x4000): grow buffer and memset the zero region
 * vars: +7 flags; [4] nZero; [6] n
 */
/* Global::sqlite3VdbeMemExpandBlob @ 004b6fa0 */

undefined4 __cdecl sqlite3VdbeMemExpandBlob(int *param_1)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 7) & 0x4000) != 0) {
    iVar1 = param_1[4] + param_1[6];
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    iVar1 = sqlite3VdbeMemGrow(param_1,iVar1,1);
    if (iVar1 != 0) {
      return 7;
    }
    memset((void *)(param_1[1] + param_1[6]),0,param_1[4]);
    param_1[6] = param_1[6] + param_1[4];
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) & 0xbdff;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeMemFinalize  (confidence: high)
 * purpose: Run an aggregate function's xFinalize into a Mem, then release the previous value
 * vars: param_2+0x14 xFinalize; local Mem context 0x40
 */
/* Global::sqlite3VdbeMemFinalize @ 004b7010 */

undefined4 __cdecl sqlite3VdbeMemFinalize(int *param_1,int param_2)

{
  code *pcVar1;
  int local_44 [2];
  int local_3c;
  undefined4 uStack_38;
  undefined8 local_34;
  undefined8 local_2c;
  undefined4 local_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined8 local_1c;
  int *local_14;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0;
  }
  pcVar1 = *(code **)(param_2 + 0x14);
  if (pcVar1 != (code *)0x0) {
    memset(local_44,0,0x40);
    uStack_20 = 1;
    local_3c = *param_1;
    local_14 = param_1;
    local_44[0] = param_2;
    (*pcVar1)(local_44);
    sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
    *(ulonglong *)param_1 = CONCAT44(uStack_38,local_3c);
    *(undefined8 *)(param_1 + 2) = local_34;
    *(undefined8 *)(param_1 + 4) = local_2c;
    *(ulonglong *)(param_1 + 6) = CONCAT26(uStack_1e,CONCAT24(uStack_20,local_24));
    *(undefined8 *)(param_1 + 8) = local_1c;
    return local_c;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeMemGrow  (confidence: high)
 * purpose: Ensure a Mem's dynamic buffer is >=param_2 bytes, preserving old content if requested
 * vars: param_1[9] zMalloc; [1] z; +7 flags; min 0x20
 */
/* Global::sqlite3VdbeMemGrow @ 004b7260 */

undefined4 __cdecl sqlite3VdbeMemGrow(int *param_1,int param_2,int param_3)

{
  int iVar1;
  void *_Src;
  void *_Dst;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  iVar1 = *param_1;
  if (param_2 < 0x20) {
    param_2 = 0x20;
  }
  uVar2 = param_1[9];
  if ((((iVar1 == 0) || (uVar2 == 0)) || (uVar2 < *(uint *)(iVar1 + 0x104))) ||
     (*(uint *)(iVar1 + 0x108) <= uVar2)) {
    uVar2 = (*DAT_00582af0._4_4_)(uVar2);
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar1 + 0xe8);
  }
  if ((int)uVar2 < param_2) {
    if (param_3 != 0) {
      puVar4 = (undefined4 *)param_1[1];
      if (puVar4 == (undefined4 *)param_1[9]) {
        iVar1 = *param_1;
        puVar3 = sqlite3PageRealloc(iVar1,puVar4,param_2);
        if (puVar3 == (undefined4 *)0x0) {
          sqlite3PageFree(iVar1,puVar4);
        }
        param_1[9] = (int)puVar3;
        param_1[1] = (int)puVar3;
        param_3 = 0;
        goto LAB_004b7302;
      }
    }
    sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
    puVar4 = sqlite3PageMalloc(*param_1,param_2);
    param_1[9] = (int)puVar4;
  }
LAB_004b7302:
  _Src = (void *)param_1[1];
  if (((_Src != (void *)0x0) && (param_3 != 0)) &&
     ((_Dst = (void *)param_1[9], _Dst != (void *)0x0 && (_Src != _Dst)))) {
    memcpy(_Dst,_Src,param_1[6]);
  }
  if (((*(ushort *)(param_1 + 7) & 0x400) != 0) && ((code *)param_1[8] != (code *)0x0)) {
    (*(code *)param_1[8])(param_1[1]);
  }
  iVar1 = param_1[9];
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 7) = 1;
  }
  else {
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) & 0xe7ff;
  }
  param_1[8] = 0;
  uVar5 = 7;
  if (iVar1 != 0) {
    uVar5 = 0;
  }
  return uVar5;
}




/* [AUDIT] proposed: sqlite3VdbeMemHandleBom  (confidence: high)
 * purpose: Strip a leading UTF BOM from a text Mem and set its encoding (UTF16LE/BE) accordingly
 * vars: FE FF / FF FE detection; enc +0x1f
 */
/* Global::sqlite3VdbeMemHandleBom @ 004b7380 */

int __cdecl sqlite3VdbeMemHandleBom(int *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined1 uVar4;
  
  if (param_1[6] < 2) {
    return 0;
  }
  cVar1 = *(char *)param_1[1];
  cVar2 = ((char *)param_1[1])[1];
  if (cVar1 == -2) {
    if (cVar2 != -1) {
      return 0;
    }
    uVar4 = 3;
  }
  else {
    if (cVar1 != -1) {
      return 0;
    }
    if (cVar2 != -2) {
      return 0;
    }
    uVar4 = 2;
  }
  iVar3 = sqlite3VdbeMemMakeWriteable(param_1);
  if (iVar3 == 0) {
    param_1[6] = param_1[6] + -2;
    memmove((void *)param_1[1],(void *)(param_1[1] + 2),param_1[6]);
    *(undefined1 *)(param_1[6] + param_1[1]) = 0;
    *(undefined1 *)(param_1[6] + 1 + param_1[1]) = 0;
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) | 0x200;
    *(undefined1 *)((int)param_1 + 0x1f) = uVar4;
  }
  return iVar3;
}




/* [AUDIT] proposed: sqlite3VdbeMemMakeWriteable  (confidence: high)
 * purpose: Make a Mem's buffer writable/owned: expand blob then copy to its own zMalloc, NUL-terminate
 * vars: +7 flags 0x12; grows n+2
 */
/* Global::sqlite3VdbeMemMakeWriteable @ 004b7490 */

undefined4 __cdecl sqlite3VdbeMemMakeWriteable(int *param_1)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 7) & 0x4000) != 0) {
    sqlite3VdbeMemExpandBlob(param_1);
  }
  if (((*(byte *)(param_1 + 7) & 0x12) != 0) && (param_1[1] != param_1[9])) {
    iVar1 = sqlite3VdbeMemGrow(param_1,param_1[6] + 2,1);
    if (iVar1 != 0) {
      return 7;
    }
    *(undefined1 *)(param_1[6] + param_1[1]) = 0;
    *(undefined1 *)(param_1[6] + 1 + param_1[1]) = 0;
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) | 0x200;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeMemNulTerminate  (confidence: high)
 * purpose: Add a NUL terminator to a text Mem lacking one (grow buffer, set term flag 0x200)
 * vars: +7 flags 0x200 term/2 str
 */
/* Global::sqlite3VdbeMemNulTerminate @ 004b7590 */

undefined4 __cdecl sqlite3VdbeMemNulTerminate(int *param_1)

{
  int iVar1;
  
  if (((*(ushort *)(param_1 + 7) & 0x200) == 0) && ((*(ushort *)(param_1 + 7) & 2) != 0)) {
    iVar1 = sqlite3VdbeMemGrow(param_1,param_1[6] + 2,1);
    if (iVar1 != 0) {
      return 7;
    }
    *(undefined1 *)(param_1[6] + param_1[1]) = 0;
    *(undefined1 *)(param_1[6] + 1 + param_1[1]) = 0;
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) | 0x200;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeMemRelease  (confidence: high)
 * purpose: Release a Mem's external bindings (flag 0x2460) and free its dynamic buffer, null pointers
 * vars: +7 flags; [9] zMalloc
 */
/* Global::sqlite3VdbeMemRelease @ 004b76e0 */

void __cdecl sqlite3VdbeMemRelease(int *param_1)

{
  if ((*(ushort *)(param_1 + 7) & 0x2460) != 0) {
    sqlite3VdbeMemReleaseExternal(param_1);
  }
  sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
  param_1[1] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  return;
}




/* [AUDIT] proposed: sqlite3VdbeMemReleaseExternal  (confidence: high)
 * purpose: Free a Mem's external resource: frame(0x2000), destructor(0x400), rowset(0x20) or agg-ctx(0x40)
 * vars: +7 flags; [8] xDel; [4] payload
 */
/* Global::sqlite3VdbeMemReleaseExternal @ 004b7720 */

void __cdecl sqlite3VdbeMemReleaseExternal(int *param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 7);
  if ((uVar1 & 0x2000) != 0) {
    sqlite3VdbeMemFinalize(param_1,param_1[4]);
    sqlite3VdbeMemRelease(param_1);
    return;
  }
  if (((uVar1 & 0x400) != 0) && ((code *)param_1[8] != (code *)0x0)) {
    (*(code *)param_1[8])(param_1[1]);
    param_1[8] = 0;
    return;
  }
  if ((uVar1 & 0x20) != 0) {
    sqlite3ExprListClearList((undefined4 *)param_1[4]);
    return;
  }
  if ((uVar1 & 0x40) != 0) {
    sqlite3VdbeMemClearExternAndSetNull((int)param_1);
  }
  return;
}




/* [AUDIT] proposed: sqlite3VdbeMemClearExternAndSetNull  (confidence: high)
 * purpose: Clear a Mem's aggregate-context / rowset resource and reset it to type-null
 * vars: +0x1c flags 0x40/0x20; sets null +1
 */
/* Global::sqlite3VdbeMemClearExternAndSetNull @ 004b78c0 */

void __cdecl sqlite3VdbeMemClearExternAndSetNull(int param_1)

{
  int *piVar1;
  
  if ((*(byte *)(param_1 + 0x1c) & 0x40) != 0) {
    piVar1 = *(int **)(param_1 + 0x10);
    piVar1[1] = *(int *)(*piVar1 + 0xa4);
    *(int **)(*piVar1 + 0xa4) = piVar1;
  }
  if ((*(byte *)(param_1 + 0x1c) & 0x20) != 0) {
    sqlite3ExprListClearList(*(undefined4 **)(param_1 + 0x10));
  }
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xbe01 | 1;
  *(undefined1 *)(param_1 + 0x1e) = 5;
  return;
}




/* [AUDIT] proposed: sqlite3VdbeMemSetStr  (confidence: high)
 * purpose: Set a Mem to a text/blob value (copy, transfer-ownership, or static) with length/encoding
 * vars: param_4 enc; param_5 xDel (0xffffffff=copy, lib_fn_4a0570=transfer); MEM flags
 */
/* Global::sqlite3VdbeMemSetStr @ 004b79e0 */

undefined4 __cdecl
sqlite3VdbeMemSetStr(int *param_1,void *param_2,size_t param_3,char param_4,undefined *param_5)

{
  int *piVar1;
  ushort uVar2;
  uint uVar3;
  size_t _Size;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  size_t sVar8;
  bool bVar9;
  
  if (param_2 == (void *)0x0) {
    if ((*(byte *)(param_1 + 7) & 0x40) != 0) {
      piVar1 = (int *)param_1[4];
      piVar1[1] = *(int *)(*piVar1 + 0xa4);
      *(int **)(*piVar1 + 0xa4) = piVar1;
    }
    if ((*(byte *)(param_1 + 7) & 0x20) != 0) {
      sqlite3ExprListClearList((undefined4 *)param_1[4]);
    }
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) & 0xbe01 | 1;
    *(undefined1 *)((int)param_1 + 0x1e) = 5;
    return 0;
  }
  if (*param_1 == 0) {
    iVar7 = 1000000000;
  }
  else {
    iVar7 = *(int *)(*param_1 + 0x50);
  }
  uVar3 = 2;
  if (param_4 == '\0') {
    uVar3 = 0x10;
  }
  bVar9 = (int)param_3 < 0;
  sVar8 = param_3;
  param_3 = uVar3;
  if (bVar9) {
    sVar8 = 0;
    if (param_4 == '\x01') {
      if (-1 < iVar7) {
        do {
          if (*(char *)(sVar8 + (int)param_2) == '\0') break;
          sVar8 = sVar8 + 1;
        } while ((int)sVar8 <= iVar7);
      }
    }
    else if (-1 < iVar7) {
      do {
        if (*(char *)(sVar8 + 1 + (int)param_2) == '\0' && *(char *)(sVar8 + (int)param_2) == '\0')
        break;
        sVar8 = sVar8 + 2;
      } while ((int)sVar8 <= iVar7);
    }
    param_3 = uVar3 | 0x200;
  }
  if (param_5 == (undefined *)0xffffffff) {
    _Size = sVar8;
    if ((param_3 & 0x200) != 0) {
      _Size = (param_4 != '\x01') + 1 + sVar8;
    }
    if (iVar7 < (int)sVar8) {
      return 0x12;
    }
    iVar4 = sqlite3VdbeMemGrow(param_1,_Size,0);
    if (iVar4 != 0) {
      return 7;
    }
    memcpy((void *)param_1[1],param_2,_Size);
  }
  else {
    if ((code *)param_5 == lib_fn_4a0570) {
      if ((*(ushort *)(param_1 + 7) & 0x2460) != 0) {
        sqlite3VdbeMemReleaseExternal(param_1);
      }
      sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
      param_1[9] = (int)param_2;
      param_1[8] = 0;
    }
    else {
      if ((*(ushort *)(param_1 + 7) & 0x2460) != 0) {
        sqlite3VdbeMemReleaseExternal(param_1);
      }
      sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
      param_1[8] = (int)param_5;
      uVar2 = 0x400;
      if (param_5 == (undefined *)0x0) {
        uVar2 = 0x800;
      }
      param_1[9] = 0;
      param_3._0_2_ = (ushort)param_3 | uVar2;
    }
    param_1[1] = (int)param_2;
  }
  *(ushort *)(param_1 + 7) = (ushort)param_3;
  param_1[6] = sVar8;
  cVar6 = '\x01';
  if (param_4 != '\0') {
    cVar6 = param_4;
  }
  *(char *)((int)param_1 + 0x1f) = cVar6;
  *(char *)((int)param_1 + 0x1e) = (param_4 == '\0') + '\x03';
  if ((cVar6 != '\x01') && (iVar4 = sqlite3VdbeMemHandleBom(param_1), iVar4 != 0)) {
    return 7;
  }
  uVar5 = 0;
  if (iVar7 < (int)sVar8) {
    uVar5 = 0x12;
  }
  return uVar5;
}




/* [AUDIT] proposed: sqlite3VdbeMemStringify  (confidence: high)
 * purpose: Convert a numeric Mem to its text representation ('%!.15g' for real), optional re-encoding
 * vars: '%!.15g'; sets flags 0x202; sqlite3VdbeMemTranslate recode
 */
/* Global::sqlite3VdbeMemStringify @ 004b7cf0 */

undefined4 __cdecl sqlite3VdbeMemStringify(int *param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar2 = *(ushort *)(param_1 + 7);
  iVar3 = sqlite3VdbeMemGrow(param_1,0x20,0);
  if (iVar3 == 0) {
    if ((uVar2 & 4) == 0) {
      pcVar6 = "%!.15g";
    }
    else {
      pcVar6 = &DAT_0056dd58;
    }
    sqlite3_snprintf_impl(0x20,param_1[1],(byte *)pcVar6);
    pcVar6 = (char *)param_1[1];
    uVar5 = 0;
    if (pcVar6 != (char *)0x0) {
      cVar1 = *pcVar6;
      pcVar4 = pcVar6;
      while (cVar1 != '\0') {
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
      uVar5 = (int)pcVar4 - (int)pcVar6 & 0x3fffffff;
    }
    param_1[6] = uVar5;
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) | 0x202;
    *(undefined1 *)((int)param_1 + 0x1f) = 1;
    if (((*(byte *)(param_1 + 7) & 2) != 0) && (param_2 != 1)) {
      sqlite3VdbeMemTranslate(param_1,(char)param_2);
    }
    return 0;
  }
  return 7;
}




/* [AUDIT] proposed: sqlite3VdbeMemTranslate  (confidence: high)
 * purpose: Transcode a Mem's text between UTF-8 and UTF-16LE/BE, allocating a new buffer
 * vars: +0x1f src enc; surrogate/BOM handling; &DAT_0056c6f8 utf8 trailing table
 */
/* Global::sqlite3VdbeMemTranslate @ 004b7dc0 */

undefined4 __cdecl sqlite3VdbeMemTranslate(int *param_1,char param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  undefined1 *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  undefined1 *puVar12;
  ushort *puVar13;
  uint local_8;
  
  if (*(char *)((int)param_1 + 0x1f) == '\x01') {
    if (param_2 != '\x01') {
      iVar3 = param_1[6] * 2 + 2;
      goto LAB_004b7e40;
    }
  }
  else if (param_2 != '\x01') {
    iVar3 = sqlite3VdbeMemMakeWriteable(param_1);
    if (iVar3 != 0) {
      return 7;
    }
    puVar9 = (undefined1 *)param_1[1];
    puVar12 = puVar9 + (param_1[6] & 0xfffffffe);
    for (; puVar9 < puVar12; puVar9 = puVar9 + 2) {
      uVar1 = *puVar9;
      *puVar9 = puVar9[1];
      puVar9[1] = uVar1;
    }
    *(char *)((int)param_1 + 0x1f) = param_2;
    return 0;
  }
  param_1[6] = param_1[6] & 0xfffffffe;
  iVar3 = param_1[6] * 2 + 1;
LAB_004b7e40:
  puVar10 = (ushort *)param_1[1];
  puVar13 = (ushort *)(param_1[6] + (int)puVar10);
  pbVar4 = (byte *)sqlite3PageMalloc(*param_1,iVar3);
  if (pbVar4 == (byte *)0x0) {
    return 7;
  }
  if (*(char *)((int)param_1 + 0x1f) == '\x01') {
    pbVar5 = pbVar4;
    if (param_2 == '\x02') {
      while (puVar10 < puVar13) {
        local_8 = (uint)(byte)*puVar10;
        puVar10 = (ushort *)((int)puVar10 + 1);
        if (local_8 < 0xc0) {
LAB_004b7eeb:
          bVar7 = (byte)(local_8 >> 8);
          if (local_8 < 0x10000) {
            *pbVar5 = (byte)local_8;
            pbVar5[1] = bVar7;
            pbVar5 = pbVar5 + 2;
          }
          else {
            bVar6 = (byte)(local_8 - 0x10000 >> 10);
            *pbVar5 = ((byte)(local_8 >> 10) ^ bVar6) & 0x3f ^ bVar6;
            pbVar5[1] = ((byte)(local_8 - 0x10000 >> 0x12) & 3) - 0x28;
            pbVar5[2] = (byte)local_8;
            pbVar5[3] = (bVar7 & 3) - 0x24;
            pbVar5 = pbVar5 + 4;
          }
        }
        else {
          local_8 = (uint)(byte)(&DAT_0056c6f8)[local_8];
          for (; (puVar10 != puVar13 && (((byte)*puVar10 & 0xc0) == 0x80));
              puVar10 = (ushort *)((int)puVar10 + 1)) {
            local_8 = local_8 * 0x40 + ((byte)*puVar10 & 0x3f);
          }
          if (((0x7f < local_8) && ((local_8 & 0xfffff800) != 0xd800)) &&
             ((local_8 & 0xfffffffe) != 0xfffe)) goto LAB_004b7eeb;
          *pbVar5 = 0xfd;
          pbVar5[1] = 0xff;
          pbVar5 = pbVar5 + 2;
        }
      }
    }
    else {
      while (puVar10 < puVar13) {
        uVar8 = (uint)(byte)*puVar10;
        puVar10 = (ushort *)((int)puVar10 + 1);
        if (uVar8 < 0xc0) {
LAB_004b7fbc:
          bVar7 = (byte)(uVar8 >> 8);
          if (uVar8 < 0x10000) {
            *pbVar5 = bVar7;
            pbVar5[1] = (byte)uVar8;
            pbVar5 = pbVar5 + 2;
          }
          else {
            *pbVar5 = ((byte)(uVar8 - 0x10000 >> 0x12) & 3) - 0x28;
            bVar6 = (byte)(uVar8 - 0x10000 >> 10);
            pbVar5[1] = ((byte)(uVar8 >> 10) ^ bVar6) & 0x3f ^ bVar6;
            pbVar5[2] = (bVar7 & 3) - 0x24;
            pbVar5[3] = (byte)uVar8;
            pbVar5 = pbVar5 + 4;
          }
        }
        else {
          uVar8 = (uint)(byte)(&DAT_0056c6f8)[uVar8];
          for (; (puVar10 != puVar13 && (((byte)*puVar10 & 0xc0) == 0x80));
              puVar10 = (ushort *)((int)puVar10 + 1)) {
            uVar8 = uVar8 * 0x40 + ((byte)*puVar10 & 0x3f);
          }
          if (((0x7f < uVar8) && ((uVar8 & 0xfffff800) != 0xd800)) &&
             ((uVar8 & 0xfffffffe) != 0xfffe)) goto LAB_004b7fbc;
          *pbVar5 = 0xff;
          pbVar5[1] = 0xfd;
          pbVar5 = pbVar5 + 2;
        }
      }
    }
    param_1[6] = (int)pbVar5 - (int)pbVar4;
    *pbVar5 = 0;
    pbVar5 = pbVar5 + 1;
  }
  else {
    pbVar5 = pbVar4;
    if (*(char *)((int)param_1 + 0x1f) == '\x02') {
      while (puVar10 < puVar13) {
        uVar8 = (uint)*puVar10;
        puVar11 = puVar10 + 1;
        if ((uVar8 - 0xd800 < 0x800) && (puVar11 < puVar13)) {
          uVar2 = *puVar11;
          puVar11 = puVar10 + 2;
          uVar8 = ((uVar8 & 0x3f) + 0x40 + (uVar8 & 0x3c0)) * 0x400 + (uVar2 & 0x3ff);
        }
        bVar7 = (byte)uVar8;
        puVar10 = puVar11;
        if (uVar8 < 0x80) {
          *pbVar5 = bVar7;
          pbVar5 = pbVar5 + 1;
        }
        else if (uVar8 < 0x800) {
          *pbVar5 = ((byte)(uVar8 >> 6) & 0x1f) - 0x40;
          pbVar5[1] = (bVar7 & 0x3f) + 0x80;
          pbVar5 = pbVar5 + 2;
        }
        else if (uVar8 < 0x10000) {
          *pbVar5 = ((byte)(uVar8 >> 0xc) & 0xf) - 0x20;
          pbVar5[1] = ((byte)(uVar8 >> 6) & 0x3f) + 0x80;
          pbVar5[2] = (bVar7 & 0x3f) + 0x80;
          pbVar5 = pbVar5 + 3;
        }
        else {
          *pbVar5 = (char)(uVar8 >> 0x12) - 0x10;
          pbVar5[1] = ((byte)(uVar8 >> 0xc) & 0x3f) + 0x80;
          pbVar5[2] = ((byte)(uVar8 >> 6) & 0x3f) + 0x80;
          pbVar5[3] = (bVar7 & 0x3f) + 0x80;
          pbVar5 = pbVar5 + 4;
        }
      }
    }
    else {
      while (puVar10 < puVar13) {
        uVar8 = (uint)CONCAT11((byte)*puVar10,*(byte *)((int)puVar10 + 1));
        puVar11 = puVar10 + 1;
        if ((uVar8 - 0xd800 < 0x800) && (puVar11 < puVar13)) {
          uVar2 = *puVar11;
          puVar11 = puVar10 + 2;
          uVar8 = ((uVar8 & 0x3f) + 0x40 + (uVar8 & 0x3c0)) * 0x400 +
                  (CONCAT11((byte)uVar2,*(byte *)((int)puVar10 + 3)) & 0x3ff);
        }
        bVar7 = (byte)uVar8;
        puVar10 = puVar11;
        if (uVar8 < 0x80) {
          *pbVar5 = bVar7;
          pbVar5 = pbVar5 + 1;
        }
        else if (uVar8 < 0x800) {
          *pbVar5 = ((byte)(uVar8 >> 6) & 0x1f) - 0x40;
          pbVar5[1] = (bVar7 & 0x3f) + 0x80;
          pbVar5 = pbVar5 + 2;
        }
        else if (uVar8 < 0x10000) {
          *pbVar5 = ((byte)(uVar8 >> 0xc) & 0xf) - 0x20;
          pbVar5[1] = ((byte)(uVar8 >> 6) & 0x3f) + 0x80;
          pbVar5[2] = (bVar7 & 0x3f) + 0x80;
          pbVar5 = pbVar5 + 3;
        }
        else {
          *pbVar5 = (char)(uVar8 >> 0x12) - 0x10;
          pbVar5[1] = ((byte)(uVar8 >> 0xc) & 0x3f) + 0x80;
          pbVar5[2] = ((byte)(uVar8 >> 6) & 0x3f) + 0x80;
          pbVar5[3] = (bVar7 & 0x3f) + 0x80;
          pbVar5 = pbVar5 + 4;
        }
      }
    }
    param_1[6] = (int)pbVar5 - (int)pbVar4;
  }
  *pbVar5 = 0;
  if ((*(ushort *)(param_1 + 7) & 0x2460) != 0) {
    sqlite3VdbeMemReleaseExternal(param_1);
  }
  sqlite3PageFree(*param_1,(undefined4 *)param_1[9]);
  *(char *)((int)param_1 + 0x1f) = param_2;
  param_1[1] = (int)pbVar4;
  param_1[9] = (int)pbVar4;
  *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) & 0xe7ff | 0x600;
  param_1[8] = 0;
  return 0;
}




/* [AUDIT] proposed: sqlite3VdbeHalt  (confidence: high)
 * purpose: Halt a VDBE: rollback/commit statement, propagate error string to db, set closed magic
 * vars: sqlite3_fn_4b60e0 closeAllCursors; +0x16 rc; magic 0x26bceaa5; +0xd zErrMsg
 */
/* Global::sqlite3VdbeHalt @ 004b8640 */

uint __cdecl sqlite3VdbeHalt(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *_Src;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  sqlite3_fn_4b60e0(param_1);
  if (param_1[0x15] < 0) {
    if ((param_1[0x16] != 0) && ((*(byte *)(param_1 + 0x18) & 0x20) != 0)) {
      sqlite3ErrorWithMsg(iVar1,param_1[0x16],(byte *)0x0);
      piVar2 = *(int **)(iVar1 + 0xd4);
      _Src = (void *)param_1[0xd];
      if (piVar2 != (int *)0x0) {
        if (_Src == (void *)0x0) {
          if ((*(byte *)(piVar2 + 7) & 0x40) != 0) {
            piVar3 = (int *)piVar2[4];
            piVar3[1] = *(int *)(*piVar3 + 0xa4);
            *(int **)(*piVar3 + 0xa4) = piVar3;
          }
          if ((*(byte *)(piVar2 + 7) & 0x20) != 0) {
            sqlite3ExprListClearList((undefined4 *)piVar2[4]);
          }
          *(ushort *)(piVar2 + 7) = *(ushort *)(piVar2 + 7) & 0xbe01 | 1;
          *(undefined1 *)((int)piVar2 + 0x1e) = 5;
        }
        else {
          if (*piVar2 == 0) {
            iVar4 = 1000000000;
          }
          else {
            iVar4 = *(int *)(*piVar2 + 0x50);
          }
          iVar5 = 0;
          if (-1 < iVar4) {
            do {
              if (*(char *)(iVar5 + (int)_Src) == '\0') break;
              iVar5 = iVar5 + 1;
            } while (iVar5 <= iVar4);
          }
          if ((iVar5 <= iVar4) && (iVar4 = sqlite3VdbeMemGrow(piVar2,iVar5 + 1,0), iVar4 == 0)) {
            memcpy((void *)piVar2[1],_Src,iVar5 + 1);
            piVar2[6] = iVar5;
            piVar2[7] = 0x1030202;
          }
        }
      }
      sqlite3PageFree(iVar1,(undefined4 *)param_1[0xd]);
      param_1[0xd] = 0;
    }
  }
  else {
    sqlite3VdbeTransferError(param_1);
    sqlite3PageFree(iVar1,(undefined4 *)param_1[0xd]);
    param_1[0xd] = 0;
    if ((param_1[0x18] & 0x40U) != 0) {
      param_1[0x18] = param_1[0x18] | 0x20;
    }
  }
  sqlite3PageFree(*param_1,(undefined4 *)param_1[0xd]);
  param_1[0xd] = 0;
  param_1[5] = 0;
  param_1[0xc] = 0x26bceaa5;
  return param_1[0x16] & *(uint *)(iVar1 + 0x30);
}




/* [AUDIT] proposed: sqlite3VdbeResizeMemArray  (confidence: med)
 * purpose: Free old and allocate param_2 fresh Mem cells (0x50 each), init each to type-null
 * vars: +0xb nMem; [4] aMem; per-cell 0x50; flags +7=1
 */
/* Global::sqlite3VdbeResizeMemArray @ 004b8c50 */

void __cdecl sqlite3VdbeResizeMemArray(int *param_1,int param_2)

{
  int iVar1;
  int *_Dst;
  int iVar2;
  
  iVar1 = *param_1;
  vdbe_releaseMemArray((int *)param_1[4],(uint)*(ushort *)(param_1 + 0xb) * 2);
  sqlite3PageFree(iVar1,(undefined4 *)param_1[4]);
  *(short *)(param_1 + 0xb) = (short)param_2;
  iVar2 = param_2 * 2;
  _Dst = sqlite3PageMalloc(iVar1,param_2 * 0x50);
  if (_Dst != (int *)0x0) {
    memset(_Dst,0,param_2 * 0x50);
  }
  param_1[4] = (int)_Dst;
  if (_Dst != (int *)0x0) {
    for (; 0 < iVar2; iVar2 = iVar2 + -1) {
      *(undefined2 *)(_Dst + 7) = 1;
      *_Dst = *param_1;
      _Dst = _Dst + 10;
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3VdbeTransferError  (confidence: high)
 * purpose: Move a VDBE's error code/message into the parent connection's error Mem
 * vars: +0xd zErrMsg; iVar2+0x2c db->errCode; +0x16 rc
 */
/* Global::sqlite3VdbeTransferError @ 004b9420 */

int __cdecl sqlite3VdbeTransferError(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *_Src;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  iVar3 = param_1[0x16];
  if (param_1[0xd] == 0) {
    sqlite3ErrorWithMsg(iVar2,iVar3,(byte *)0x0);
    return iVar3;
  }
  uVar1 = *(undefined1 *)(iVar2 + 0x38);
  if (DAT_00583e74 != (code *)0x0) {
    (*DAT_00583e74)();
  }
  piVar4 = *(int **)(iVar2 + 0xd4);
  _Src = (void *)param_1[0xd];
  if (piVar4 != (int *)0x0) {
    if (_Src == (void *)0x0) {
      if ((*(byte *)(piVar4 + 7) & 0x40) != 0) {
        piVar5 = (int *)piVar4[4];
        piVar5[1] = *(int *)(*piVar5 + 0xa4);
        *(int **)(*piVar5 + 0xa4) = piVar5;
      }
      if ((*(byte *)(piVar4 + 7) & 0x20) != 0) {
        sqlite3ExprListClearList((undefined4 *)piVar4[4]);
      }
      *(ushort *)(piVar4 + 7) = *(ushort *)(piVar4 + 7) & 0xbe01 | 1;
      *(undefined1 *)((int)piVar4 + 0x1e) = 5;
    }
    else {
      if (*piVar4 == 0) {
        iVar6 = 1000000000;
      }
      else {
        iVar6 = *(int *)(*piVar4 + 0x50);
      }
      iVar7 = 0;
      if (-1 < iVar6) {
        do {
          if (*(char *)(iVar7 + (int)_Src) == '\0') break;
          iVar7 = iVar7 + 1;
        } while (iVar7 <= iVar6);
      }
      if (iVar7 <= iVar6) {
        iVar6 = sqlite3VdbeMemGrow(piVar4,iVar7 + 1,0);
        if (iVar6 == 0) {
          memcpy((void *)piVar4[1],_Src,iVar7 + 1);
          piVar4[6] = iVar7;
          piVar4[7] = 0x1030202;
        }
      }
    }
  }
  if (DAT_00583e78 != (code *)0x0) {
    (*DAT_00583e78)();
  }
  *(undefined1 *)(iVar2 + 0x38) = uVar1;
  *(int *)(iVar2 + 0x2c) = iVar3;
  return iVar3;
}




/* [AUDIT] proposed: sqlite3AggInfoDelete_or_columns  (confidence: med)
 * purpose: Free a table auxiliary array at +0x34 (skip index1) then the array itself
 * vars: param_2+0x30 count; +0x34 array
 */
/* Global::sqlite3AggInfoDelete_or_columns @ 004b9b30 */

void __cdecl sqlite3AggInfoDelete_or_columns(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1f0) == 0)) {
    sqlite3VtabMoveToList(0,param_2);
  }
  if (*(int *)(param_2 + 0x34) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_2 + 0x30)) {
      do {
        if (iVar1 != 1) {
          sqlite3PageFree(param_1,*(undefined4 **)(*(int *)(param_2 + 0x34) + iVar1 * 4));
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_2 + 0x30));
    }
    sqlite3PageFree(param_1,*(undefined4 **)(param_2 + 0x34));
  }
  return;
}




/* [AUDIT] proposed: sqlite3KeyInfoUnref  (confidence: high)
 * purpose: Decrement a KeyInfo refcount (+0xc); when zero run destructor (vtable+0x10) and free
 * vars: param_1[3] nRef; [2] obj; [6] collseq
 */
/* Global::sqlite3KeyInfoUnref @ 004ba040 */

void __cdecl sqlite3KeyInfoUnref(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 3;
  *piVar2 = *piVar2 + -1;
  iVar1 = *param_1;
  if (*piVar2 == 0) {
    piVar2 = (int *)param_1[2];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(piVar2);
    }
    sqlite3PageFree(iVar1,param_1);
  }
  return;
}




/* [AUDIT] proposed: sqlite3VtabUnlockList  (confidence: med)
 * purpose: Expire prepared statements then walk & unref the connection's deferred VTable list (+0x13c)
 * vars: db+0x13c list; per-node nRef +0xc; +0x3c vdbe chain
 */
/* Global::sqlite3VtabUnlockList @ 004ba070 */

void __cdecl sqlite3VtabUnlockList(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x13c);
  *(undefined4 *)(param_1 + 0x13c) = 0;
  if (piVar4 != (int *)0x0) {
    for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
      *(uint *)(iVar1 + 0x60) = *(uint *)(iVar1 + 0x60) | 0x20;
    }
    do {
      piVar3 = piVar4 + 3;
      *piVar3 = *piVar3 + -1;
      piVar2 = (int *)piVar4[6];
      iVar1 = *piVar4;
      if (*piVar3 == 0) {
        piVar3 = (int *)piVar4[2];
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x10))(piVar3);
        }
        sqlite3PageFree(iVar1,piVar4);
      }
      piVar4 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}




/* [AUDIT] proposed: walTryBeginRead  (confidence: med)
 * purpose: Retry loop to establish a WAL read transaction, reading wal-index header and picking a read-mark
 * vars: walIndexReadHdr readHdr; page1 [8]; read-marks +0x64; busy retries
 */
/* Global::walTryBeginRead @ 004ba0e0 */

int __cdecl walTryBeginRead(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  uint local_14;
  int local_8;
  
  iVar5 = 0;
  iVar8 = -0x85e;
LAB_004ba0f3:
  do {
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 0xee;
    if (5 < iVar5) {
      if (0x549a < iVar8) {
        return 0xf;
      }
      iVar2 = 1;
      if (9 < iVar5) {
        iVar2 = iVar8;
      }
      (**(code **)(*param_1 + 0x3c))(*param_1,iVar2);
    }
    iVar2 = walIndexReadHdr((int)param_1,param_2);
    if (iVar2 == 5) {
      if (*(int *)param_1[8] == 0) {
        iVar2 = -1;
      }
      else {
        if (*(char *)((int)param_1 + 0x2b) == '\0') {
          iVar2 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],2,1,6);
          if (iVar2 != 0) {
            if (iVar2 != 5) goto LAB_004ba19c;
            iVar2 = 0x105;
            goto LAB_004ba353;
          }
          if (*(char *)((int)param_1 + 0x2b) == '\0') {
            (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],2,1,5);
          }
        }
        iVar2 = -1;
      }
    }
    else {
LAB_004ba19c:
      if (iVar2 == 0) {
        iVar1 = *(int *)param_1[8];
        iVar3 = 0;
        if (*(int *)(iVar1 + 0x60) == param_1[0x11]) {
          if (*(char *)((int)param_1 + 0x2b) == '\0') {
            iVar2 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],3,1,6);
          }
          if (*(char *)((int)param_1 + 0x2b) != '\x02') {
            (**(code **)(*(int *)param_1[1] + 0x3c))((int *)param_1[1]);
          }
          if (iVar2 == 0) {
            piVar7 = param_1 + 0xd;
            piVar4 = *(int **)param_1[8];
            uVar9 = 0x2c;
            while (*piVar4 == *piVar7) {
              piVar4 = piVar4 + 1;
              piVar7 = piVar7 + 1;
              bVar10 = uVar9 < 4;
              uVar9 = uVar9 - 4;
              if (bVar10) {
                *(undefined2 *)(param_1 + 10) = 0;
                return 0;
              }
            }
            if (*(char *)((int)param_1 + 0x2b) == '\0') {
              (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],3,1,5);
            }
            goto LAB_004ba0f3;
          }
          iVar3 = iVar2;
          if (iVar2 != 5) goto LAB_004ba353;
        }
        iVar2 = iVar3;
        local_14 = 0;
        local_8 = 0;
        iVar3 = 1;
        puVar6 = (uint *)(iVar1 + 0x68);
        do {
          uVar9 = *puVar6;
          if ((local_14 <= uVar9) && (uVar9 <= (uint)param_1[0x11])) {
            local_14 = uVar9;
            local_8 = iVar3;
          }
          iVar3 = iVar3 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar3 < 5);
        if ((*(byte *)((int)param_1 + 0x2e) & 2) == 0) {
          if ((local_14 < (uint)param_1[0x11]) || (local_8 == 0)) {
            iVar3 = 1;
            do {
              if (*(char *)((int)param_1 + 0x2b) != '\0') {
                iVar2 = 0;
LAB_004ba2d4:
                local_14 = param_1[0x11];
                *(uint *)(iVar1 + 100 + iVar3 * 4) = local_14;
                local_8 = iVar3;
                if (*(char *)((int)param_1 + 0x2b) == '\0') {
                  (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],iVar3 + 3,1,9);
                }
                break;
              }
              iVar2 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],iVar3 + 3,1,10);
              if (iVar2 == 0) goto LAB_004ba2d4;
              if (iVar2 != 5) goto LAB_004ba353;
              iVar3 = iVar3 + 1;
            } while (iVar3 < 5);
            goto LAB_004ba305;
          }
        }
        else {
LAB_004ba305:
          if (local_8 == 0) {
            bVar10 = iVar2 == 5;
            iVar2 = 0x208;
            if (bVar10) {
              iVar2 = -1;
            }
            goto LAB_004ba353;
          }
        }
        if ((*(char *)((int)param_1 + 0x2b) != '\0') ||
           (iVar2 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],local_8 + 3,1,6),
           iVar2 == 0)) {
          if (*(char *)((int)param_1 + 0x2b) != '\x02') {
            (**(code **)(*(int *)param_1[1] + 0x3c))((int *)param_1[1]);
          }
          if (*(uint *)(iVar1 + 100 + local_8 * 4) == local_14) {
            piVar7 = param_1 + 0xd;
            piVar4 = *(int **)param_1[8];
            uVar9 = 0x2c;
            while (*piVar4 == *piVar7) {
              piVar4 = piVar4 + 1;
              piVar7 = piVar7 + 1;
              bVar10 = uVar9 < 4;
              uVar9 = uVar9 - 4;
              if (bVar10) {
                *(short *)(param_1 + 10) = (short)local_8;
                return 0;
              }
            }
          }
          if (*(char *)((int)param_1 + 0x2b) == '\0') {
            (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],local_8 + 3,1,5);
          }
          goto LAB_004ba0f3;
        }
        if (iVar2 == 5) {
          iVar2 = -1;
        }
      }
    }
LAB_004ba353:
    if (iVar2 != -1) {
      return iVar2;
    }
  } while( true );
}




/* [AUDIT] proposed: sqlite3WalFrames  (confidence: high)
 * purpose: Write a set of dirty pages as frames into the WAL, taking the write lock and checkpointing
 * vars: walBusyLock lock; walCheckpoint checkpoint; walCheckpoint writeFrames; corrupt->0xb
 */
/* Global::sqlite3WalFrames @ 004ba4a0 */

int __cdecl
sqlite3WalFrames(int param_1,int param_2,undefined *param_3,undefined4 param_4,int param_5,int param_6,
            undefined4 param_7,undefined4 *param_8,undefined4 *param_9)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = param_2;
  local_8 = 0;
  if (*(char *)(param_1 + 0x2e) != '\0') {
    return 8;
  }
  if ((*(char *)(param_1 + 0x2b) == '\0') &&
     (iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),1,1,10),
     iVar2 != 0)) {
    return iVar2;
  }
  *(undefined1 *)(param_1 + 0x2d) = 1;
  if (param_2 != 0) {
    iVar2 = walBusyLock(param_1,param_3,param_4,0,1);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x2c) = 1;
    }
    else {
      if (iVar2 != 5) goto LAB_004ba5b7;
      param_2 = 0;
    }
  }
  iVar2 = walIndexReadHdr(param_1,&local_8);
  if (iVar2 == 0) {
    if ((*(int *)(param_1 + 0x44) == 0) ||
       ((*(ushort *)(param_1 + 0x42) & 1) * 0x10000 + (*(ushort *)(param_1 + 0x42) & 0xfe00) ==
        param_6)) {
      iVar2 = walCheckpoint(param_1,param_2,param_3,param_4,param_5,param_7);
    }
    else {
      iVar2 = sqlite3CorruptError();
    }
    if ((iVar2 == 0) || (iVar2 == 5)) {
      if (param_8 != (undefined4 *)0x0) {
        *param_8 = *(undefined4 *)(param_1 + 0x44);
      }
      if (param_9 != (undefined4 *)0x0) {
        *param_9 = *(undefined4 *)(**(int **)(param_1 + 0x20) + 0x60);
      }
    }
  }
  if (local_8 != 0) {
    memset((void *)(param_1 + 0x34),0,0x30);
  }
LAB_004ba5b7:
  if (*(char *)(param_1 + 0x2c) != '\0') {
    if (*(char *)(param_1 + 0x2b) == '\0') {
      (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),0,1,9);
    }
    *(undefined1 *)(param_1 + 0x2c) = 0;
    *(undefined1 *)(param_1 + 0x2f) = 0;
  }
  if (*(char *)(param_1 + 0x2b) == '\0') {
    (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),1,1,9);
  }
  *(undefined1 *)(param_1 + 0x2d) = 0;
  if ((iVar2 == 0) && (iVar1 != param_2)) {
    iVar2 = 5;
  }
  return iVar2;
}




/* [AUDIT] proposed: sqlite3WalClose  (confidence: high)
 * purpose: Checkpoint (if lockable) and close the WAL: run checkpoint, delete/limit wal file, free Wal
 * vars: sqlite3WalFrames frames/checkpoint; sqlite3WalLimitSize limitSize; +8 fd
 */
/* Global::sqlite3WalClose @ 004ba620 */

int __cdecl sqlite3WalClose(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  bVar2 = false;
  local_8 = (**(code **)(*(int *)param_1[1] + 0x1c))((int *)param_1[1],4);
  if (local_8 == 0) {
    if (*(char *)((int)piVar3 + 0x2b) == '\0') {
      *(undefined1 *)((int)piVar3 + 0x2b) = 1;
    }
    local_8 = sqlite3WalFrames((int)piVar3,0,(undefined *)0x0,0,param_2,param_3,param_4,
                           (undefined4 *)0x0,(undefined4 *)0x0);
    if (local_8 == 0) {
      param_1 = (int *)0xffffffff;
      (**(code **)(*(int *)piVar3[1] + 0x28))((int *)piVar3[1],10,&param_1);
      if (param_1 == (int *)0x1) {
        if (-1 < piVar3[5]) {
          sqlite3WalLimitSize((int)piVar3,0,0);
        }
      }
      else {
        bVar2 = true;
      }
    }
  }
  walIndexClose((int)piVar3);
  piVar1 = (int *)piVar3[2];
  if (*piVar1 != 0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    *piVar1 = 0;
  }
  if (bVar2) {
    if (DAT_00583e74 != (code *)0x0) {
      (*DAT_00583e74)();
    }
    (**(code **)(*piVar3 + 0x1c))(*piVar3,piVar3[0x19],0);
    if (DAT_00583e78 != (code *)0x0) {
      (*DAT_00583e78)();
    }
  }
  sqlite3_free(piVar3[8]);
  sqlite3_free((int)piVar3);
  return local_8;
}




/* [AUDIT] proposed: walIteratorFree_or_restart  (confidence: med)
 * purpose: Release WAL read/write locks held by a checkpoint/writer and reset lock state
 * vars: +0x2c writeLock; +0x28 readLock; unlocks via xShmLock(+0x38)
 */
/* Global::walIteratorFree_or_restart @ 004ba770 */

void __cdecl walIteratorFree_or_restart(int param_1)

{
  if (*(char *)(param_1 + 0x2c) != '\0') {
    if (*(char *)(param_1 + 0x2b) == '\0') {
      (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),0,1,9);
    }
    *(undefined1 *)(param_1 + 0x2c) = 0;
    *(undefined1 *)(param_1 + 0x2f) = 0;
  }
  if (-1 < *(short *)(param_1 + 0x28)) {
    if (*(char *)(param_1 + 0x2b) == '\0') {
      (**(code **)(**(int **)(param_1 + 4) + 0x38))
                (*(int **)(param_1 + 4),*(short *)(param_1 + 0x28) + 3,1,5);
    }
    *(undefined2 *)(param_1 + 0x28) = 0xffff;
  }
  return;
}




/* [AUDIT] proposed: walWriteFrames_inner  (confidence: med)
 * purpose: Encode and write successive WAL frames (header+page) to the log file, updating checksums/salts
 * vars: walEncodeFrame encodeFrame; walWriteToLog writeToLog; salt local_28
 */
/* Global::walWriteFrames_inner @ 004ba7d0 */


void __cdecl
walWriteFrames_inner(int *param_1,uint param_2,uint *param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  int *local_64;
  int *local_60;
  undefined8 local_5c;
  uint local_54;
  uint local_50;
  int *local_4c;
  uint *local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint *local_34;
  uint *local_30;
  int local_2c;
  int local_28 [2];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  int local_18;
  int local_14;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_4c = param_1;
  local_48 = param_3;
  local_34 = (uint *)0x0;
  local_40 = 0;
  iVar3 = walRestartHdr(param_1);
  lVar10 = CONCAT44(local_2c,local_44);
  if (iVar3 != 0) goto LAB_004bac7b;
  local_3c = param_1[0x11];
  if (local_3c == 0) {
    local_20._0_1_ = (char)(param_2 >> 0x18);
    local_20._1_1_ = (char)(param_2 >> 0x10);
    local_20._2_1_ = (char)(param_2 >> 8);
    local_20._3_1_ = (char)param_2;
    iVar3 = param_1[0x1a];
    local_1c = (char)((uint)iVar3 >> 0x18);
    local_1b = (char)((uint)iVar3 >> 0x10);
    local_28[0] = -0x7df980c9;
    local_28[1] = 0x18e22d00;
    local_1a = (char)((uint)iVar3 >> 8);
    local_19 = (char)iVar3;
    if (iVar3 == 0) {
      sqlite3_randomness(8,(undefined1 *)(param_1 + 0x15));
    }
    local_18 = param_1[0x15];
    iVar3 = 0;
    local_14 = param_1[0x16];
    piVar5 = local_28;
    local_38 = 0;
    do {
      local_38 = local_38 + *piVar5 + iVar3;
      iVar3 = iVar3 + piVar5[1] + local_38;
      piVar5 = piVar5 + 2;
    } while (piVar5 < &local_10);
    local_10 = (undefined1)(local_38 >> 0x18);
    local_f = (undefined1)(local_38 >> 0x10);
    local_e = (undefined1)(local_38 >> 8);
    local_c = (undefined1)((uint)iVar3 >> 0x18);
    local_b = (undefined1)((uint)iVar3 >> 0x10);
    local_a = (undefined1)((uint)iVar3 >> 8);
    param_1[9] = param_2;
    *(undefined1 *)((int)param_1 + 0x41) = 0;
    param_1[0x14] = iVar3;
    param_1[0x13] = local_38;
    local_9 = (undefined1)iVar3;
    local_d = (undefined1)local_38;
    *(undefined1 *)((int)param_1 + 0x2f) = 1;
    iVar3 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],local_28,0x20,0);
    lVar10 = CONCAT44(local_2c,local_44);
    if (iVar3 != 0) goto LAB_004bac7b;
    if ((((char)param_1[0xc] != '\0') && (param_6 != 0)) &&
       (iVar3 = (**(code **)(*(int *)param_1[2] + 0x14))((int *)param_1[2]), iVar3 != 0)) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  piVar5 = (int *)param_1[2];
  local_50 = param_2;
  uVar4 = param_2 + 0x18;
  local_64 = param_1;
  local_5c = 0;
  local_54 = param_6;
  local_60 = piVar5;
  local_38 = uVar4;
  lVar10 = __allmul(local_3c,0,uVar4,(int)uVar4 >> 0x1f);
  lVar10 = lVar10 + 0x20;
  puVar2 = local_48;
  while( true ) {
    local_30 = puVar2;
    uVar6 = (uint)lVar10;
    local_2c = (int)((ulonglong)lVar10 >> 0x20);
    local_44 = uVar6;
    if (local_30 == (uint *)0x0) break;
    local_3c = local_3c + 1;
    if ((param_5 == 0) || (iVar3 = param_4, local_30[3] != 0)) {
      iVar3 = 0;
    }
    local_34 = (uint *)local_30[1];
    walEncodeFrame((int)param_1,local_30[5],iVar3,local_34,&local_20);
    iVar3 = walWriteToLog((int)&local_64,(int)&local_20,0x18,uVar6,local_2c);
    lVar10 = CONCAT44(local_2c,local_44);
    if (iVar3 != 0) goto LAB_004bac7b;
    iVar3 = walWriteToLog((int)&local_64,(int)local_34,param_2,uVar6 + 0x18,
                         local_2c + (uint)(0xffffffe7 < uVar6));
    lVar10 = CONCAT44(local_2c,local_44);
    if (iVar3 != 0) goto LAB_004bac7b;
    lVar10 = CONCAT44(local_2c + ((int)local_38 >> 0x1f) + (uint)CARRY4(uVar6,local_38),
                      uVar6 + local_38);
    puVar2 = (uint *)local_30[3];
    local_34 = local_30;
  }
  iVar3 = 0;
  if (param_5 != 0) {
    if ((param_6 & 0x20) == 0) {
LAB_004bab82:
      iVar7 = 0;
    }
    else {
      if (*(char *)((int)param_1 + 0x31) == '\0') {
        iVar3 = (**(code **)(*piVar5 + 0x14))(piVar5);
        lVar10 = CONCAT44(local_2c,local_44);
        goto LAB_004bab82;
      }
      if (*(code **)(*(int *)param_1[2] + 0x2c) == (code *)0x0) {
        local_30 = (uint *)0x1000;
      }
      else {
        local_30 = (uint *)(**(code **)(*(int *)param_1[2] + 0x2c))();
        lVar10 = CONCAT44(local_2c,local_44);
        if ((int)local_30 < 0x20) {
          local_30 = (uint *)0x200;
          lVar10 = CONCAT44(local_2c,local_44);
        }
        else if (0x10000 < (int)local_30) {
          local_30 = (uint *)0x10000;
        }
      }
      local_2c = (int)((ulonglong)lVar10 >> 0x20);
      local_44 = (uint)lVar10;
      uVar6 = (int)local_30 >> 0x1f;
      iVar7 = (int)(lVar10 + (int)local_30);
      uVar11 = __alldiv(iVar7 - 1,
                        (int)((ulonglong)(lVar10 + (int)local_30) >> 0x20) - (uint)(iVar7 == 0),
                        (uint)local_30,uVar6);
      local_5c = __allmul((uint)uVar11,(int)((ulonglong)uVar11 >> 0x20),(uint)local_30,uVar6);
      param_1 = local_4c;
      lVar10 = CONCAT44(local_2c,local_44);
      uVar6 = local_44;
      if (local_5c <= lVar10) goto LAB_004bab82;
      do {
        local_30 = (uint *)local_34[1];
        walEncodeFrame((int)param_1,local_34[5],param_4,local_30,&local_20);
        iVar3 = walWriteToLog((int)&local_64,(int)&local_20,0x18,uVar6,local_2c);
        lVar10 = CONCAT44(local_2c,local_44);
        if (iVar3 != 0) goto LAB_004bac7b;
        iVar3 = walWriteToLog((int)&local_64,(int)local_30,param_2,uVar6 + 0x18,
                             local_2c + (uint)(0xffffffe7 < uVar6));
        lVar10 = CONCAT44(local_2c,local_44);
        if (iVar3 != 0) goto LAB_004bac7b;
        uVar8 = uVar6 + local_38;
        local_2c = local_2c + ((int)local_38 >> 0x1f) + (uint)CARRY4(uVar6,local_38);
        iVar7 = local_40 + 1;
        uVar6 = uVar8;
        local_40 = iVar7;
      } while ((local_2c < local_5c._4_4_) ||
              ((iVar3 = 0, lVar10 = CONCAT44(local_2c,local_44), local_2c <= local_5c._4_4_ &&
               (lVar10 = CONCAT44(local_2c,local_44), uVar8 < (uint)local_5c))));
    }
    local_2c = (int)((ulonglong)lVar10 >> 0x20);
    local_44 = (uint)lVar10;
    if ((*(char *)((int)param_1 + 0x2f) != '\0') && (iVar1 = param_1[4], -1 < param_1[5])) {
      lVar12 = __allmul(local_3c + iVar7,0,uVar4,(int)uVar4 >> 0x1f);
      lVar10 = CONCAT44(param_1[5],iVar1);
      if (CONCAT44(param_1[5],iVar1) < lVar12 + 0x20) {
        lVar10 = lVar12 + 0x20;
      }
      sqlite3WalLimitSize((int)param_1,(uint)lVar10,(int)((ulonglong)lVar10 >> 0x20));
      lVar10 = CONCAT44(local_2c,local_44);
      *(undefined1 *)((int)param_1 + 0x2f) = 0;
    }
  }
  pvVar9 = (void *)param_1[0x11];
  for (; local_48 != (uint *)0x0; local_48 = (uint *)local_48[3]) {
    local_2c = (int)((ulonglong)lVar10 >> 0x20);
    local_44 = (uint)lVar10;
    if (iVar3 != 0) goto LAB_004bac7b;
    pvVar9 = (void *)((int)pvVar9 + 1);
    iVar3 = walIndexAppend((int)param_1,pvVar9,local_48[5]);
    lVar10 = CONCAT44(local_2c,local_44);
  }
  if (iVar3 == 0) {
    while( true ) {
      local_2c = (int)((ulonglong)lVar10 >> 0x20);
      local_44 = (uint)lVar10;
      if (local_40 < 1) break;
      local_40 = local_40 + -1;
      pvVar9 = (void *)((int)pvVar9 + 1);
      iVar3 = walIndexAppend((int)param_1,pvVar9,local_34[5]);
      lVar10 = CONCAT44(local_2c,local_44);
      if (iVar3 != 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    *(ushort *)((int)param_1 + 0x42) = (ushort)(param_2 >> 0x10) | (ushort)param_2 & 0xff00;
    param_1[0x11] = (int)pvVar9;
    if (param_5 != 0) {
      param_1[0xf] = param_1[0xf] + 1;
      param_1[0x12] = param_4;
      walIndexWriteHdr((int)param_1);
      lVar10 = CONCAT44(local_2c,local_44);
      param_1[3] = (int)pvVar9;
    }
  }
LAB_004bac7b:
  local_2c = (int)((ulonglong)lVar10 >> 0x20);
  local_44 = (uint)lVar10;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: sqlite3WalOpen  (confidence: high)
 * purpose: Allocate & init a Wal object (0x70 + pagesize), open the WAL file, read its shm/pagesize flags
 * vars: _Dst Wal; [2] shm fd; [0x19] path; +0x2b exclusive
 */
/* Global::sqlite3WalOpen @ 004bac90 */

int __cdecl
sqlite3WalOpen(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 *param_7)

{
  int *piVar1;
  undefined4 *puVar2;
  int *_Dst;
  int iVar3;
  uint uVar4;
  size_t _Size;
  
  puVar2 = param_7;
  *param_7 = 0;
  _Size = *(int *)(param_1 + 4) + 0x70;
  _Dst = (int *)sqlite3Malloc(_Size);
  if (_Dst == (int *)0x0) {
    return 7;
  }
  memset(_Dst,0,_Size);
  _Dst[2] = (int)(_Dst + 0x1c);
  _Dst[1] = param_2;
  *(undefined2 *)(_Dst + 10) = 0xffff;
  _Dst[4] = param_5;
  _Dst[5] = param_6;
  *(byte *)((int)_Dst + 0x2b) = -(param_4 != 0) & 2;
  *_Dst = param_1;
  _Dst[0x19] = param_3;
  *(undefined2 *)(_Dst + 0xc) = 0x101;
  param_7 = (undefined4 *)0x80006;
  iVar3 = (**(code **)(param_1 + 0x18))(param_1,param_3,_Dst[2],0x80006,&param_7);
  if (iVar3 == 0) {
    if (((uint)param_7 & 1) != 0) {
      *(undefined1 *)((int)_Dst + 0x2e) = 1;
    }
    uVar4 = (**(code **)(*(int *)_Dst[2] + 0x30))((int *)_Dst[2]);
    if ((uVar4 & 0x400) != 0) {
      *(undefined1 *)(_Dst + 0xc) = 0;
    }
    if ((uVar4 & 0x1000) != 0) {
      *(undefined1 *)((int)_Dst + 0x31) = 0;
    }
    *puVar2 = _Dst;
    return 0;
  }
  walIndexClose((int)_Dst);
  piVar1 = (int *)_Dst[2];
  if (*piVar1 != 0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    *piVar1 = 0;
  }
  sqlite3_free((int)_Dst);
  return iVar3;
}




/* [AUDIT] proposed: walFindFrame  (confidence: high)
 * purpose: Search the WAL hash tables for the newest frame of a given page, returning its frame offset
 * vars: param_1+0x44 mxFrame; hash table blocks; corrupt->0xb; walIndexPage mapPage
 */
/* Global::walFindFrame @ 004bada0 */

int __cdecl walFindFrame(int param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  int local_c;
  uint local_8;
  
  uVar2 = *(uint *)(param_1 + 0x44);
  local_8 = 0;
  if ((uVar2 == 0) || (*(short *)(param_1 + 0x28) == 0)) {
    *param_3 = 0;
    return 0;
  }
  uVar10 = uVar2 + 0x21 >> 0xc;
  uVar9 = 0;
  do {
    if (uVar9 != 0) goto LAB_004baec6;
    iVar5 = walIndexPage(param_1,uVar10,&local_c);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = local_c + 0x4000;
    if (uVar10 == 0) {
      local_c = local_c + 0x88;
      iVar11 = 0;
    }
    else {
      iVar11 = (uVar10 - 1) * 0x1000 + 0xfde;
    }
    uVar6 = param_2 * 0x17f & 0x1fff;
    sVar1 = *(short *)(iVar5 + uVar6 * 2);
    iVar4 = 0x2000;
    while (sVar1 != 0) {
      puVar7 = (ushort *)(iVar5 + uVar6 * 2);
      uVar8 = (uint)*puVar7 + iVar11;
      if ((uVar8 <= uVar2) &&
         (uVar9 = local_8, *(int *)(local_c + -4 + (uint)*puVar7 * 4) == param_2)) {
        uVar9 = uVar8;
        local_8 = uVar8;
      }
      if (iVar4 == 0) {
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        return 0xb;
      }
      uVar6 = uVar6 + 1 & 0x1fff;
      iVar4 = iVar4 + -1;
      sVar1 = *(short *)(iVar5 + uVar6 * 2);
    }
    uVar10 = uVar10 - 1;
  } while (-1 < (int)uVar10);
  if (uVar9 == 0) {
    *param_3 = 0;
    return 0;
  }
LAB_004baec6:
  iVar11 = (*(ushort *)(param_1 + 0x42) & 1) * 0x10000 + (*(ushort *)(param_1 + 0x42) & 0xfe00);
  *param_3 = 1;
  piVar3 = *(int **)(param_1 + 8);
  iVar5 = *piVar3;
  lVar12 = __allmul(iVar11 + 0x18,0,local_8 - 1,0);
  if (iVar11 < param_4) {
    param_4 = iVar11;
  }
  iVar5 = (**(code **)(iVar5 + 8))(piVar3,param_5,param_4,lVar12 + 0x38);
  return iVar5;
}




/* [AUDIT] proposed: sqlite3WalUndo_or_iterate  (confidence: med)
 * purpose: Iterate WAL frames from a saved point invoking a callback per page, then cleanup hash on rollback
 * vars: +0x2c writeLock; +0x44 mxFrame; +0x20 apWiData; walCleanupHash cleanupHash
 */
/* Global::sqlite3WalUndo_or_iterate @ 004baf40 */

int __cdecl sqlite3WalUndo_or_iterate(int param_1,undefined *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = 0;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    uVar1 = *(uint *)(param_1 + 0x44);
    puVar2 = (undefined8 *)**(undefined4 **)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x34) = *puVar2;
    *(undefined8 *)(param_1 + 0x3c) = puVar2[1];
    *(undefined8 *)(param_1 + 0x44) = puVar2[2];
    *(undefined8 *)(param_1 + 0x4c) = puVar2[3];
    *(undefined8 *)(param_1 + 0x54) = puVar2[4];
    *(undefined8 *)(param_1 + 0x5c) = puVar2[5];
    uVar3 = *(uint *)(param_1 + 0x44);
    uVar7 = uVar3 + 0x22;
    iVar5 = uVar7 * 4;
    do {
      uVar3 = uVar3 + 1;
      if (uVar1 < uVar3) break;
      if (uVar7 >> 0xc == 0) {
        uVar4 = *(undefined4 *)(iVar5 + **(int **)(param_1 + 0x20));
      }
      else {
        uVar4 = *(undefined4 *)
                 (*(int *)(*(int *)(param_1 + 0x20) + (uVar7 >> 0xc) * 4) + (uVar7 & 0xfff) * 4);
      }
      iVar6 = (*(code *)param_2)(param_3,uVar4);
      iVar5 = iVar5 + 4;
      uVar7 = uVar7 + 1;
    } while (iVar6 == 0);
    if (uVar1 != *(uint *)(param_1 + 0x44)) {
      walCleanupHash(param_1);
    }
  }
  return iVar6;
}




/* [AUDIT] proposed: sqlite3_config  (confidence: high)
 * purpose: Global config dispatch: set/get memory,mutex,pcache methods, page/scratch buffers, lookaside etc
 * vars: switch(param_1) cases 1-0x14; DAT_00582ac8/acc flags; 'misuse'
 */
/* Global::sqlite3_config @ 004bc440 */


undefined4 __cdecl
sqlite3_config(undefined4 param_1,undefined8 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 unaff_EDI;
  
  uVar2 = 0;
  if (DAT_00582b90 == 0) {
    switch(param_1) {
    case 1:
      DAT_00582acc = 0;
      DAT_00582ad0 = 0;
      return 0;
    case 2:
      DAT_00582ad0 = 0;
      DAT_00582acc = 1;
      return 0;
    case 3:
      DAT_00582acc = 1;
      DAT_00582ad0 = 1;
      return 0;
    case 4:
      _DAT_00582ae8 = *param_2;
      DAT_00582af0 = param_2[1];
      _DAT_00582af8 = param_2[2];
      DAT_00582b00 = param_2[3];
      return 0;
    case 5:
      if (DAT_00582ae8 == 0) {
        sqlite3_config(4,(undefined8 *)&PTR_FUN_0056a9dc,unaff_EDI,unaff_ESI);
      }
      *param_2 = _DAT_00582ae8;
      param_2[1] = DAT_00582af0;
      param_2[2] = _DAT_00582af8;
      param_2[3] = DAT_00582b00;
      return 0;
    case 6:
      DAT_00582b70 = param_2;
      DAT_00582b74 = param_3;
      DAT_00582b78 = param_4;
      return 0;
    case 7:
      DAT_00582b7c = param_2;
      DAT_00582b80 = param_3;
      DAT_00582b84 = param_4;
      return 0;
    default:
      uVar2 = 1;
switchD_004bc47c_caseD_e:
      return uVar2;
    case 9:
      DAT_00582ac8 = param_2;
      return 0;
    case 10:
      DAT_00582b08 = *param_2;
      _DAT_00582b10 = param_2[1];
      _DAT_00582b18 = param_2[2];
      _DAT_00582b20 = param_2[3];
      DAT_00582b28 = *(undefined4 *)(param_2 + 4);
      return 0;
    case 0xb:
      *param_2 = DAT_00582b08;
      param_2[1] = _DAT_00582b10;
      param_2[2] = _DAT_00582b18;
      param_2[3] = _DAT_00582b20;
      *(undefined4 *)(param_2 + 4) = DAT_00582b28;
      return 0;
    case 0xd:
      DAT_00582ae0 = param_2;
      DAT_00582ae4 = param_3;
      return 0;
    case 0xe:
      goto switchD_004bc47c_caseD_e;
    case 0x10:
      DAT_00582bac = param_2;
      DAT_00582bb0 = param_3;
      return 0;
    case 0x11:
      DAT_00582ad4 = param_2;
      return 0;
    case 0x12:
      puVar3 = &DAT_00582b2c;
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *(undefined4 *)param_2;
        param_2 = (undefined8 *)((int)param_2 + 4);
        puVar3 = puVar3 + 1;
      }
      return 0;
    case 0x13:
      if (DAT_00582b34 == 0) {
        sqlite3_config(0x12,(undefined8 *)&DAT_00569e0c,unaff_EDI,unaff_ESI);
      }
      puVar3 = &DAT_00582b2c;
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)param_2 = *puVar3;
        puVar3 = puVar3 + 1;
        param_2 = (undefined8 *)((int)param_2 + 4);
      }
      return 0;
    case 0x14:
      DAT_00582ad8 = param_2;
      return 0;
    }
  }
  sqlite3_log(0x15,"misuse at line %d of [%.10s]");
  return 0x15;
}




/* [AUDIT] proposed: sqlite3_initialize  (confidence: high)
 * purpose: One-time library init: mutex, malloc, pcache subsystems and built-in functions, set inited flag
 * vars: DAT_00582b90 inited; sqlite3MutexInit mutexInit; pcache1Initialize mallocInit; sqlite3RegisterBuiltinFunctions funcs
 */
/* Global::sqlite3_initialize @ 004bc920 */


int sqlite3_initialize(void)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  if (DAT_00582b90 != 0) {
    return 0;
  }
  iVar1 = sqlite3MutexInit();
  if (iVar1 != 0) {
    return iVar1;
  }
  if (DAT_00582acc == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*DAT_00582b10)(2);
    if (iVar1 != 0) {
      (*DAT_00582b18)(iVar1);
    }
  }
  _DAT_00582b98 = 1;
  iVar2 = 0;
  if ((DAT_00582b9c != 0) || (iVar2 = pcache1Initialize(unaff_EDI), iVar2 == 0)) {
    DAT_00582b9c = 1;
    if (DAT_00582ba4 == 0) {
      if (DAT_00582acc != 0) {
        DAT_00582ba4 = (*DAT_00582b10)(1);
      }
      if ((DAT_00582acc != 0) && (DAT_00582ba4 == 0)) {
        iVar2 = 7;
        goto LAB_004bc9d1;
      }
    }
    DAT_00582ba8 = DAT_00582ba8 + 1;
  }
LAB_004bc9d1:
  if (iVar1 != 0) {
    (*DAT_00582b20)(iVar1);
  }
  if (iVar2 != 0) {
    return iVar2;
  }
  if (DAT_00582ba4 != 0) {
    (*DAT_00582b18)(DAT_00582ba4);
  }
  iVar2 = 0;
  if ((DAT_00582b90 != 0) || (DAT_00582b94 != 0)) goto LAB_004bcae2;
  DAT_00582b94 = 1;
  memset(&DAT_00583f68,0,0x5c);
  sqlite3RegisterBuiltinFunctions();
  if (DAT_00582ba0 == 0) {
    if (DAT_00582b34 == (code *)0x0) {
      sqlite3_config(0x12,(undefined8 *)&DAT_00569e0c,unaff_EDI,unaff_ESI);
    }
    iVar2 = (*DAT_00582b34)(DAT_00582b30);
    if (iVar2 == 0) goto LAB_004bca72;
  }
  else {
LAB_004bca72:
    DAT_00582ba0 = 1;
    iVar2 = sqlite3_initialize();
    if ((iVar2 == 0) && (iVar2 = sqlite3Malloc(10), iVar2 != 0)) {
      sqlite3_free(iVar2);
      iVar2 = pcache1_init_systeminfo();
      if (iVar2 == 0) {
        sqlite3PcacheBufferSetup(DAT_00582b7c,DAT_00582b80,DAT_00582b84);
        DAT_00582b90 = 1;
      }
    }
    else {
      iVar2 = 7;
    }
  }
  DAT_00582b94 = 0;
LAB_004bcae2:
  if (DAT_00582ba4 != 0) {
    (*DAT_00582b20)(DAT_00582ba4);
  }
  if (iVar1 != 0) {
    (*DAT_00582b18)(iVar1);
  }
  DAT_00582ba8 = DAT_00582ba8 + -1;
  if (DAT_00582ba8 < 1) {
    if (DAT_00582ba4 != 0) {
      (*DAT_00582b14)(DAT_00582ba4);
    }
    DAT_00582ba4 = 0;
  }
  if (iVar1 != 0) {
    (*DAT_00582b20)(iVar1);
  }
  return iVar2;
}




/* [AUDIT] proposed: pcache1_init_systeminfo  (confidence: med)
 * purpose: Query system info (GetSystemInfo) for page granularity and register a pcache/pager cleanup entry
 * vars: PTR_GetSystemInfo; pcache1RemoveFromList unlink; DAT_00583e70 list
 */
/* Global::pcache1_init_systeminfo @ 004bcbc0 */


undefined4 pcache1_init_systeminfo(void)

{
  int iVar1;
  
  _DAT_00584660 = 0;
  _DAT_00584668 = 0;
  _DAT_00584670 = 0;
  _DAT_00584678 = 0;
  _DAT_00584680 = 0;
  (*(code *)PTR_GetSystemInfo_005836bc)(&DAT_00584660);
  iVar1 = sqlite3_initialize();
  if (iVar1 == 0) {
    if (DAT_00582acc == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*DAT_00582b10)(2);
      if (iVar1 != 0) {
        (*DAT_00582b18)(iVar1);
      }
    }
    pcache1RemoveFromList(0x583460);
    _DAT_0058346c = DAT_00583e70;
    DAT_00583e70 = &DAT_00583460;
    if (iVar1 != 0) {
      (*DAT_00582b20)(iVar1);
    }
    return 0;
  }
  return 0;
}




/* [AUDIT] proposed: sqlite3WithDelete_or_AggFree  (confidence: med)
 * purpose: Free a linked structure at param_2+4 (6-word items): delete Expr, free 3 sub-buffers, then array
 * vars: *(param_2+4) items; +0x26 count; stride 6 words
 */
/* Global::sqlite3WithDelete_or_AggFree @ 004bce20 */

void __cdecl sqlite3WithDelete_or_AggFree(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar2 = param_2;
  puVar4 = *(uint **)(param_2 + 4);
  if (puVar4 != (uint *)0x0) {
    param_2 = 0;
    if (0 < *(short *)(iVar2 + 0x26)) {
      do {
        puVar1 = (undefined4 *)*puVar4;
        if (param_1 == 0) {
LAB_004bcec2:
          sqlite3_free((int)puVar1);
        }
        else if (*(int *)(param_1 + 0x1f0) == 0) {
          if (((puVar1 == (undefined4 *)0x0) || (puVar1 < *(undefined4 **)(param_1 + 0x104))) ||
             (*(undefined4 **)(param_1 + 0x108) <= puVar1)) goto LAB_004bcec2;
          *puVar1 = *(undefined4 *)(param_1 + 0x100);
          *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + -1;
          *(undefined4 **)(param_1 + 0x100) = puVar1;
        }
        else if (((puVar1 == (undefined4 *)0x0) || (puVar1 < *(undefined4 **)(param_1 + 0x104))) ||
                (*(undefined4 **)(param_1 + 0x108) <= puVar1)) {
          iVar3 = (*DAT_00582af0._4_4_)(puVar1);
          **(int **)(param_1 + 0x1f0) = **(int **)(param_1 + 0x1f0) + iVar3;
        }
        else {
          **(int **)(param_1 + 0x1f0) =
               **(int **)(param_1 + 0x1f0) + (uint)*(ushort *)(param_1 + 0xe8);
        }
        sqlite3ExprDelete(param_1,(undefined4 *)puVar4[1]);
        sqlite3PageFree(param_1,(undefined4 *)puVar4[2]);
        sqlite3PageFree(param_1,(undefined4 *)puVar4[3]);
        sqlite3PageFree(param_1,(undefined4 *)puVar4[4]);
        param_2 = param_2 + 1;
        puVar4 = puVar4 + 6;
      } while (param_2 < *(short *)(iVar2 + 0x26));
    }
    sqlite3PageFree(param_1,*(undefined4 **)(iVar2 + 4));
  }
  return;
}




/* [AUDIT] proposed: sqlite3StrHash_wal  (confidence: high)
 * purpose: Compute a rolling hash over param_2 bytes (xor + *8) using the case-fold table
 * vars: &DAT_00569620 fold table
 */
/* Global::sqlite3StrHash_wal @ 004bd210 */

uint __cdecl sqlite3StrHash_wal(byte *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; 0 < param_2; param_2 = param_2 + -1) {
    uVar1 = uVar1 ^ (uint)(byte)(&DAT_00569620)[*param_1] ^ uVar1 * 8;
    param_1 = param_1 + 1;
  }
  return uVar1;
}




/* [AUDIT] proposed: walDirtyPagesPresent_or_bitTest  (confidence: low)
 * purpose: Test whether required pages exist in a page-map/bitvec structure, returning 1 if missing
 * vars: page-map at (+0x10)+0x5c; sub-bitvec traversal; 0xfa1 threshold
 */
/* Global::walDirtyPagesPresent_or_bitTest @ 004bd250 */

undefined4 __cdecl walDirtyPagesPresent_or_bitTest(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  piVar1 = (int *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0x14);
  iVar3 = *(int *)(*piVar1 + 0x60);
  param_1 = 0;
  if (0 < iVar3) {
    puVar8 = (undefined4 *)(*(int *)(*piVar1 + 0x5c) + 0x10);
    do {
      if (uVar2 <= (uint)puVar8[1]) {
        puVar4 = (uint *)*puVar8;
        if (((puVar4 == (uint *)0x0) || (*puVar4 < uVar2)) || (uVar2 == 0)) {
          return 1;
        }
        uVar7 = uVar2 - 1;
        uVar6 = puVar4[2];
        while (uVar6 != 0) {
          uVar5 = uVar7 / uVar6;
          uVar7 = uVar7 % uVar6;
          puVar4 = (uint *)puVar4[uVar5 + 3];
          if (puVar4 == (uint *)0x0) {
            return 1;
          }
          uVar6 = puVar4[2];
        }
        if (*puVar4 < 0xfa1) {
          if ((*(byte *)((uVar7 >> 3) + 0xc + (int)puVar4) & (byte)(1 << ((byte)uVar7 & 7))) == 0) {
            return 1;
          }
        }
        else {
          uVar5 = uVar7 % 0x7d;
          uVar6 = puVar4[uVar5 + 3];
          if (uVar6 == 0) {
            return 1;
          }
          while (uVar6 != uVar7 + 1) {
            uVar5 = (uVar5 + 1) % 0x7d;
            uVar6 = puVar4[uVar5 + 3];
            if (uVar6 == 0) {
              return 1;
            }
          }
        }
      }
      param_1 = param_1 + 1;
      puVar8 = puVar8 + 0xc;
    } while (param_1 < iVar3);
  }
  return 0;
}




/* [AUDIT] proposed: pager_incr_changecounter  (confidence: high)
 * purpose: Increment DB change-counter on page1, write sync-flags/header magic, optionally to WAL
 * vars: magic 0xf905d5d9/0xd763a120; +0x2c changeCounter; pagerWriteWalHeader walHdr
 */
/* Global::pager_incr_changecounter @ 004bd5d0 */

void __cdecl pager_incr_changecounter(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  longlong lVar5;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [4];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(param_1 + 0xb8) != 0) || (iVar2 = pager_lockWithRetry(param_1,4), iVar2 == 0)) {
    if (*(char *)(param_1 + 7) == '\0') {
      if ((**(int **)(param_1 + 0x40) == 0) || (*(char *)(param_1 + 5) == '\x04')) {
        *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x48);
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x4c);
      }
      else {
        uVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x30))(*(int **)(param_1 + 0x3c));
        if ((uVar3 & 0x200) == 0) {
          local_14 = 0xf905d5d9;
          local_10 = 0xd763a120;
          sqlite3Put4byte(local_c,*(undefined4 *)(param_1 + 0x2c));
          lVar5 = pager_journalHdrOffset(param_1);
          iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 8))
                            (*(int **)(param_1 + 0x40),&local_1c,8,lVar5);
          if ((((iVar2 != 0) ||
               (((local_1c == -0x6fa2a27 && (local_18 == -0x289c5ee0)) &&
                (iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0xc))
                                   (*(int **)(param_1 + 0x40),&DAT_005699af,1,lVar5), iVar2 != 0))))
              && (iVar2 != 0x20a)) ||
             ((((*(char *)(param_1 + 8) != '\0' && ((uVar3 & 0x400) == 0)) &&
               (iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x14))
                                  (*(int **)(param_1 + 0x40),*(undefined1 *)(param_1 + 0xb)),
               iVar2 != 0)) ||
              (iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0xc))
                                 (*(int **)(param_1 + 0x40),&local_14,0xc,
                                  *(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54)),
              iVar2 != 0)))) goto LAB_004bd7af;
        }
        if ((uVar3 & 0x400) == 0) {
          bVar4 = 0;
          if (*(char *)(param_1 + 0xb) == '\x03') {
            bVar4 = 0x10;
          }
          iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x14))
                            (*(int **)(param_1 + 0x40),bVar4 | *(byte *)(param_1 + 0xb));
          if (iVar2 != 0) goto LAB_004bd7af;
        }
        *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x48);
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x4c);
        if ((param_2 != 0) && ((uVar3 & 0x200) == 0)) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
          iVar2 = pagerWriteWalHeader(param_1);
          if (iVar2 != 0) {
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
      }
    }
    piVar1 = *(int **)(param_1 + 0xb4);
    for (iVar2 = *piVar1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
      *(ushort *)(iVar2 + 0x18) = *(ushort *)(iVar2 + 0x18) & 0xfffb;
    }
    piVar1[2] = piVar1[1];
    *(undefined1 *)(param_1 + 0xf) = 4;
  }
LAB_004bd7af:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: vdbeUnbind  (confidence: high)
 * purpose: Validate a prepared-statement bind index and release the target Mem parameter
 * vars: 'API called with finalized/NULL prepared statement','bind on a busy prepared statement'; magic -0x420df25d
 */
/* Global::vdbeUnbind @ 004bfc30 */

undefined4 __cdecl vdbeUnbind(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == (int *)0x0) {
    pcVar3 = "API called with NULL prepared statement";
  }
  else {
    if (*param_1 != 0) {
      iVar2 = *(int *)(*param_1 + 0xc);
      if (iVar2 != 0) {
        (*DAT_00582b18)(iVar2);
      }
      if ((param_1[0xc] == -0x420df25d) && (param_1[0x15] < 0)) {
        if ((0 < param_2) && (param_2 <= (short)param_1[0x13])) {
          iVar2 = param_2 + -1;
          piVar1 = (int *)(param_1[0x11] + iVar2 * 0x28);
          sqlite3VdbeMemRelease(piVar1);
          *(undefined2 *)(piVar1 + 7) = 1;
          sqlite3ErrorWithMsg(*param_1,0,(byte *)0x0);
          if (((param_1[0x18] & 0x200U) != 0) &&
             (((iVar2 < 0x20 && ((param_1[0x2b] & 1 << ((byte)iVar2 & 0x1f)) != 0)) ||
              (param_1[0x2b] == -1)))) {
            param_1[0x18] = param_1[0x18] | 0x20;
          }
          return 0;
        }
        sqlite3ErrorWithMsg(*param_1,0x19,(byte *)0x0);
        if (*(int *)(*param_1 + 0xc) != 0) {
          (*DAT_00582b20)(*(int *)(*param_1 + 0xc));
        }
        return 0x19;
      }
      sqlite3ErrorWithMsg(*param_1,0x15,(byte *)0x0);
      if (*(int *)(*param_1 + 0xc) != 0) {
        (*DAT_00582b20)(*(int *)(*param_1 + 0xc));
      }
      sqlite3_log(0x15,"bind on a busy prepared statement: [%s]");
      sqlite3_log(0x15,"misuse at line %d of [%.10s]");
      return 0x15;
    }
    pcVar3 = "API called with finalized prepared statement";
  }
  sqlite3_log(0x15,pcVar3);
  sqlite3_log(0x15,"misuse at line %d of [%.10s]");
  return 0x15;
}




/* [AUDIT] proposed: pcache1RemoveFromList  (confidence: high)
 * purpose: Unlink a page-cache/pager object from the singly-linked global list at DAT_00583e70
 * vars: next ptr at +0xc
 */
/* Global::pcache1RemoveFromList @ 004bfd90 */

void __cdecl pcache1RemoveFromList(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    if (DAT_00583e70 == param_1) {
      DAT_00583e70 = *(undefined4 *)(param_1 + 0xc);
      return;
    }
    if (DAT_00583e70 != 0) {
      iVar1 = *(int *)(DAT_00583e70 + 0xc);
      iVar3 = DAT_00583e70;
      while ((iVar1 != 0 && (iVar2 = *(int *)(iVar3 + 0xc), iVar2 != param_1))) {
        iVar1 = *(int *)(iVar2 + 0xc);
        iVar3 = iVar2;
      }
      if (*(int *)(iVar3 + 0xc) == param_1) {
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      }
    }
  }
  return;
}




/* [AUDIT] proposed: sqlite3VtabMoveToList  (confidence: med)
 * purpose: Move VTable nodes matching db==param_1 to output; push others back onto their db's disconnect list
 * vars: param_2+0x38 list; node[6] next; db+0x13c
 */
/* Global::sqlite3VtabMoveToList @ 004c01d0 */

int * __cdecl sqlite3VtabMoveToList(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = *(int **)(param_2 + 0x38);
  *(undefined4 *)(param_2 + 0x38) = 0;
  piVar4 = (int *)0x0;
  while (piVar3 = piVar1, piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    piVar1 = (int *)piVar3[6];
    if (iVar2 == param_1) {
      *(int **)(param_2 + 0x38) = piVar3;
      piVar3[6] = 0;
      piVar4 = piVar3;
    }
    else {
      piVar3[6] = *(int *)(iVar2 + 0x13c);
      *(int **)(iVar2 + 0x13c) = piVar3;
    }
  }
  return piVar4;
}




/* [AUDIT] proposed: walBusyLock  (confidence: high)
 * purpose: Acquire a WAL shm lock, invoking the busy-handler callback and retrying while it returns nonzero
 * vars: xShmLock(+0x38); param_2 busy cb; SQLITE_BUSY(5)
 */
/* Global::walBusyLock @ 004c0220 */

int __cdecl
walBusyLock(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  do {
    if (*(char *)(param_1 + 0x2b) == '\0') {
      iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x38))
                        (*(int **)(param_1 + 4),param_4,param_5,10);
    }
    else {
      iVar1 = 0;
    }
    if (param_2 == (undefined *)0x0) {
      return iVar1;
    }
    if (iVar1 != 5) {
      return iVar1;
    }
    iVar1 = (*(code *)param_2)(param_3);
  } while (iVar1 != 0);
  return 5;
}




/* [AUDIT] proposed: walCheckpoint  (confidence: high)
 * purpose: Copy frames from the WAL back into the DB file (checkpoint), advancing backfill counters
 * vars: walIteratorInit iterInit; walIteratorNext iterNext; read-marks +0x68; alldiv offsets
 */
/* Global::walCheckpoint @ 004c0270 */

int __cdecl
walCheckpoint(int param_1,int param_2,undefined *param_3,undefined4 param_4,int param_5,
            undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  undefined3 extraout_var;
  int iVar9;
  longlong lVar10;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_20;
  uint *local_1c;
  uint local_18;
  uint local_14;
  uint *local_10;
  undefined *local_c;
  uint local_8;
  
  local_14 = (*(ushort *)(param_1 + 0x42) & 1) * 0x10000 + (*(ushort *)(param_1 + 0x42) & 0xfe00);
  iVar9 = **(int **)(param_1 + 0x20);
  puVar6 = (uint *)(iVar9 + 0x60);
  local_1c = (uint *)0x0;
  local_18 = 0;
  local_20 = 0;
  if (*(uint *)(param_1 + 0x44) <= *puVar6) {
    return 0;
  }
  iVar7 = walIteratorInit(param_1,&local_1c);
  if (iVar7 != 0) {
    return iVar7;
  }
  uVar1 = *(uint *)(param_1 + 0x48);
  local_c = (undefined *)0x0;
  if (param_2 != 0) {
    local_c = param_3;
  }
  uVar8 = *(uint *)(param_1 + 0x44);
  local_10 = (uint *)(iVar9 + 0x68);
  iVar9 = 1;
  iVar7 = 0;
  local_8 = uVar8;
  do {
    uVar2 = *local_10;
    if (uVar2 < uVar8) {
      iVar7 = walBusyLock(param_1,local_c,param_4,iVar9 + 3,1);
      if (iVar7 == 0) {
        uVar8 = 0xffffffff;
        if (iVar9 == 1) {
          uVar8 = local_8;
        }
        *local_10 = uVar8;
        uVar8 = local_8;
        if (*(char *)(param_1 + 0x2b) == '\0') {
          (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),iVar9 + 3,1);
          uVar8 = local_8;
        }
      }
      else {
        if (iVar7 != 5) goto LAB_004c05af;
        local_c = (undefined *)0x0;
        uVar8 = uVar2;
        local_8 = uVar2;
      }
    }
    iVar9 = iVar9 + 1;
    local_10 = local_10 + 1;
  } while (iVar9 < 5);
  if ((*puVar6 < uVar8) && (iVar7 = walBusyLock(param_1,local_c,param_4,3,1), iVar7 == 0)) {
    uVar8 = *puVar6;
    if ((param_5 == 0) ||
       (iVar7 = (**(code **)(**(int **)(param_1 + 8) + 0x14))(*(int **)(param_1 + 8)), iVar7 == 0))
    {
      uVar2 = local_14;
      local_10 = (uint *)((int)local_14 >> 0x1f);
      lVar10 = __allmul(uVar1,0,local_14,(int)local_10);
      iVar7 = (**(code **)(**(int **)(param_1 + 4) + 0x18))(*(int **)(param_1 + 4));
      if (iVar7 == 0) {
        local_30 = (int)((ulonglong)lVar10 >> 0x20);
        uVar4 = local_8;
        if ((local_38 <= local_30) &&
           ((local_38 < local_30 || (local_34 = (uint)lVar10, local_3c < local_34)))) {
          (**(code **)(**(int **)(param_1 + 4) + 0x28))(*(int **)(param_1 + 4),5);
          uVar4 = local_8;
        }
        do {
          do {
            bVar5 = walIteratorNext(local_1c,&local_18,(int *)&local_20);
            if (CONCAT31(extraout_var,bVar5) != 0) {
              if (uVar4 == *(uint *)(**(int **)(param_1 + 0x20) + 0x10)) {
                lVar10 = __allmul(*(uint *)(param_1 + 0x48),0,uVar2,(int)local_10);
                iVar7 = (**(code **)(**(int **)(param_1 + 4) + 0x10))(*(int **)(param_1 + 4),lVar10)
                ;
                if ((iVar7 != 0) ||
                   ((param_5 != 0 &&
                    (iVar7 = (**(code **)(**(int **)(param_1 + 4) + 0x14))(*(int **)(param_1 + 4)),
                    iVar7 != 0)))) goto LAB_004c04b0;
              }
              *puVar6 = uVar4;
              goto LAB_004c04b0;
            }
          } while (((local_20 <= uVar8) || (uVar4 < local_20)) || (uVar1 < local_18));
          piVar3 = *(int **)(param_1 + 8);
          iVar9 = *piVar3;
          lVar10 = __allmul(local_14 + 0x18,(int)(local_14 + 0x18) >> 0x1f,local_20 - 1,0);
          iVar7 = (**(code **)(iVar9 + 8))(piVar3,param_6,local_14,lVar10 + 0x38);
          if (iVar7 != 0) break;
          piVar3 = *(int **)(param_1 + 4);
          iVar9 = *piVar3;
          lVar10 = __allmul(local_18 - 1,0,uVar2,(int)local_10);
          iVar7 = (**(code **)(iVar9 + 0xc))(piVar3,param_6,local_14,lVar10);
          uVar4 = local_8;
        } while (iVar7 == 0);
      }
    }
LAB_004c04b0:
    if (*(char *)(param_1 + 0x2b) == '\0') {
      (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),3,1);
    }
  }
  if (iVar7 == 5) {
    iVar7 = 0;
  }
  else if (iVar7 != 0) goto LAB_004c05af;
  if (param_2 != 0) {
    if (*puVar6 < *(uint *)(param_1 + 0x44)) {
      pcache1Free(local_1c);
      return 5;
    }
    if (((param_2 == 2) && (iVar7 = walBusyLock(param_1,local_c,param_4,4,4), iVar7 == 0)) &&
       (*(char *)(param_1 + 0x2b) == '\0')) {
      (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),4,4);
    }
  }
LAB_004c05af:
  pcache1Free(local_1c);
  return iVar7;
}




/* [AUDIT] proposed: walChecksumBytes  (confidence: high)
 * purpose: Compute the two-word Fibonacci-weighted WAL checksum over a data block (native/byteswapped)
 * vars: param_1 nativeCksum flag; param_5[0..1] out s0/s1
 */
/* Global::walChecksumBytes @ 004c05d0 */

void __cdecl walChecksumBytes(int param_1,uint *param_2,int param_3,int *param_4,int *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  puVar4 = (uint *)(param_3 + (int)param_2);
  if (param_4 == (int *)0x0) {
    iVar7 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = *param_4;
    iVar7 = param_4[1];
  }
  if (param_1 != 0) {
    do {
      iVar6 = iVar6 + *param_2 + iVar7;
      puVar5 = param_2 + 1;
      param_2 = param_2 + 2;
      iVar7 = iVar7 + *puVar5 + iVar6;
    } while (param_2 < puVar4);
    param_5[1] = iVar7;
    *param_5 = iVar6;
    return;
  }
  puVar5 = param_2 + 1;
  do {
    uVar2 = puVar5[-1];
    uVar3 = *puVar5;
    iVar6 = iVar6 + (uint)*(byte *)((int)puVar5 + -1) +
                    (uVar2 >> 8 & 0xff00) + iVar7 + (uVar2 * 0x10000 + (uVar2 & 0xff00)) * 0x100;
    iVar7 = iVar7 + (uint)*(byte *)((int)puVar5 + 3) +
                    (uVar3 >> 8 & 0xff00) + iVar6 + (uVar3 * 0x10000 + (uVar3 & 0xff00)) * 0x100;
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
  } while (puVar1 < puVar4);
  param_5[1] = iVar7;
  *param_5 = iVar6;
  return;
}




/* [AUDIT] proposed: walCleanupHash  (confidence: high)
 * purpose: Reset the WAL hash slots and page-number array for frames beyond the current mxFrame
 * vars: +0x44 mxFrame; hash at +0x4000; walIndexPage mapPage
 */
/* Global::walCleanupHash @ 004c0690 */

void __cdecl walCleanupHash(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar4 = 0;
  iVar5 = 0;
  if (*(int *)(param_1 + 0x44) != 0) {
    uVar3 = *(int *)(param_1 + 0x44) + 0x21U >> 0xc;
    iVar1 = walIndexPage(param_1,uVar3,&local_8);
    if (iVar1 == 0) {
      iVar4 = local_8 + 0x4000;
      if (uVar3 == 0) {
        iVar1 = local_8 + 0x84;
        local_8 = local_8 + 0x88;
      }
      else {
        iVar5 = (uVar3 - 1) * 0x1000 + 0xfde;
        iVar1 = local_8 + -4;
      }
    }
    else {
      iVar1 = 0;
    }
    iVar5 = *(int *)(param_1 + 0x44) - iVar5;
    iVar2 = 0;
    do {
      if (iVar5 < (int)(uint)*(ushort *)(iVar4 + iVar2 * 2)) {
        *(undefined2 *)(iVar4 + iVar2 * 2) = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x2000);
    memset((void *)(iVar5 * 4 + 4 + iVar1),0,((iVar4 + iVar5 * -4) - iVar1) - 4);
  }
  return;
}




/* [AUDIT] proposed: walDecodeFrame  (confidence: high)
 * purpose: Validate a WAL frame header (salt + checksums) and extract its page number & DB size
 * vars: param_5 frame; checks salts +0x54/0x58; walChecksumBytes checksum
 */
/* Global::walDecodeFrame @ 004c0740 */

undefined4 __cdecl
walDecodeFrame(int param_1,int *param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0x4c);
  if ((*(uint *)(param_1 + 0x54) != param_5[2]) || (*(uint *)(param_1 + 0x58) != param_5[3])) {
    return 0;
  }
  iVar3 = CONCAT31(CONCAT21(CONCAT11((char)*param_5,*(undefined1 *)((int)param_5 + 1)),
                            *(undefined1 *)((int)param_5 + 2)),*(undefined1 *)((int)param_5 + 3));
  if (iVar3 != 0) {
    uVar2 = (uint)(*(char *)(param_1 + 0x41) == '\0');
    walChecksumBytes(uVar2,param_5,8,piVar1,piVar1);
    walChecksumBytes(uVar2,param_4,*(int *)(param_1 + 0x24),piVar1,piVar1);
    if ((*piVar1 ==
         CONCAT31(CONCAT21(CONCAT11((char)param_5[4],*(undefined1 *)((int)param_5 + 0x11)),
                           *(undefined1 *)((int)param_5 + 0x12)),
                  *(undefined1 *)((int)param_5 + 0x13))) &&
       (*(int *)(param_1 + 0x50) ==
        CONCAT31(CONCAT21(CONCAT11((char)param_5[5],*(undefined1 *)((int)param_5 + 0x15)),
                          *(undefined1 *)((int)param_5 + 0x16)),*(undefined1 *)((int)param_5 + 0x17)
                ))) {
      *param_2 = iVar3;
      *param_3 = CONCAT31(CONCAT21(CONCAT11((char)param_5[1],*(undefined1 *)((int)param_5 + 5)),
                                   *(undefined1 *)((int)param_5 + 6)),
                          *(undefined1 *)((int)param_5 + 7));
      return 1;
    }
  }
  return 0;
}




/* [AUDIT] proposed: walEncodeFrame  (confidence: high)
 * purpose: Build a WAL frame header: page number, DB size/commit, salts and cumulative checksums
 * vars: param_5 out header; +0x54/0x58 salts; walChecksumBytes checksum
 */
/* Global::walEncodeFrame @ 004c0850 */

void __cdecl
walEncodeFrame(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  *(char *)param_5 = (char)((uint)param_2 >> 0x18);
  *(char *)((int)param_5 + 3) = (char)param_2;
  *(char *)((int)param_5 + 1) = (char)((uint)param_2 >> 0x10);
  *(char *)((int)param_5 + 2) = (char)((uint)param_2 >> 8);
  *(char *)(param_5 + 1) = (char)((uint)param_3 >> 0x18);
  *(char *)((int)param_5 + 5) = (char)((uint)param_3 >> 0x10);
  *(char *)((int)param_5 + 6) = (char)((uint)param_3 >> 8);
  *(char *)((int)param_5 + 7) = (char)param_3;
  param_5[2] = *(uint *)(param_1 + 0x54);
  param_5[3] = *(uint *)(param_1 + 0x58);
  piVar1 = (int *)(param_1 + 0x4c);
  uVar4 = (uint)(*(char *)(param_1 + 0x41) == '\0');
  walChecksumBytes(uVar4,param_5,8,piVar1,piVar1);
  walChecksumBytes(uVar4,param_4,*(int *)(param_1 + 0x24),piVar1,piVar1);
  iVar2 = *piVar1;
  *(char *)(param_5 + 4) = (char)((uint)iVar2 >> 0x18);
  *(char *)((int)param_5 + 0x11) = (char)((uint)iVar2 >> 0x10);
  *(char *)((int)param_5 + 0x12) = (char)((uint)iVar2 >> 8);
  *(char *)((int)param_5 + 0x13) = (char)iVar2;
  uVar3 = *(undefined4 *)(param_1 + 0x50);
  *(char *)(param_5 + 5) = (char)((uint)uVar3 >> 0x18);
  *(char *)((int)param_5 + 0x15) = (char)((uint)uVar3 >> 0x10);
  *(char *)((int)param_5 + 0x16) = (char)((uint)uVar3 >> 8);
  *(char *)((int)param_5 + 0x17) = (char)uVar3;
  return;
}




/* [AUDIT] proposed: walIndexAppend  (confidence: high)
 * purpose: Insert a frame's page number into the appropriate wal-index hash table (linear probe)
 * vars: iHash param_3*0x17f; +0x4000 hash region; corrupt->0xb
 */
/* Global::walIndexAppend @ 004c0910 */

int __cdecl walIndexAppend(int param_1,void *param_2,int param_3)

{
  int iVar1;
  short sVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  pvVar4 = param_2;
  uVar8 = (int)param_2 + 0x21U >> 0xc;
  iVar6 = walIndexPage(param_1,uVar8,&param_2);
  pvVar5 = param_2;
  if (iVar6 == 0) {
    if (uVar8 == 0) {
      param_2 = (void *)((int)param_2 + 0x88);
      iVar7 = 0;
    }
    else {
      iVar7 = (uVar8 - 1) * 0x1000 + 0xfde;
    }
    iVar7 = (int)pvVar4 - iVar7;
    iVar1 = (int)param_2 + -4;
    if (iVar7 == 1) {
      memset(param_2,0,(int)pvVar5 + (0x7ffc - iVar1));
    }
    if (*(int *)(iVar1 + iVar7 * 4) != 0) {
      walCleanupHash(param_1);
    }
    uVar8 = param_3 * 0x17f & 0x1fff;
    sVar2 = *(short *)((int)pvVar5 + uVar8 * 2 + 0x4000);
    iVar3 = iVar7;
    while (sVar2 != 0) {
      if (iVar3 == 0) {
        sqlite3_log(0xb,"database corruption at line %d of [%.10s]");
        return 0xb;
      }
      uVar8 = uVar8 + 1 & 0x1fff;
      iVar3 = iVar3 + -1;
      sVar2 = *(short *)((int)pvVar5 + uVar8 * 2 + 0x4000);
    }
    *(int *)(iVar1 + iVar7 * 4) = param_3;
    *(short *)((int)pvVar5 + uVar8 * 2 + 0x4000) = (short)iVar7;
  }
  return iVar6;
}




/* [AUDIT] proposed: walIndexClose  (confidence: high)
 * purpose: Free/unmap the wal-index (heap-mode) shared-memory pages or delegate to VFS xShmUnmap
 * vars: +0x2b exclusive; +0x20 apWiData; else xShmUnmap(+0x40)
 */
/* Global::walIndexClose @ 004c0a00 */

void __cdecl walIndexClose(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x2b) == '\x02') {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      do {
        iVar1 = *(int *)(*(int *)(param_1 + 0x20) + iVar3 * 4);
        if (iVar1 != 0) {
          if (DAT_00582ac8 == 0) {
            (*DAT_00582aec)(iVar1);
          }
          else {
            if (DAT_00583f40 != 0) {
              (*DAT_00582b18)(DAT_00583f40);
            }
            iVar2 = (*DAT_00582af0._4_4_)(iVar1);
            DAT_00583e18 = DAT_00583e18 - iVar2;
            if (DAT_00583e40 < DAT_00583e18) {
              DAT_00583e40 = DAT_00583e18;
            }
            DAT_00583e3c = DAT_00583e3c + -1;
            if (DAT_00583e64 < DAT_00583e3c) {
              DAT_00583e64 = DAT_00583e3c;
            }
            (*DAT_00582aec)(iVar1);
            if (DAT_00583f40 != 0) {
              (*DAT_00582b20)(DAT_00583f40);
            }
          }
        }
        iVar3 = iVar3 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x20) + -4 + iVar3 * 4) = 0;
      } while (iVar3 < *(int *)(param_1 + 0x18));
    }
    return;
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x40))();
  return;
}




/* [AUDIT] proposed: walIndexPage  (confidence: high)
 * purpose: Map or lazily allocate the requested wal-index shared-memory page (heap 0x8000 blocks)
 * vars: +0x18 nWiData; +0x20 apWiData; xShmMap(+0x34); heap flag +0x2b
 */
/* Global::walIndexPage @ 004c0ae0 */

int __cdecl walIndexPage(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *_Dst;
  int iVar4;
  
  iVar4 = 0;
  if (param_2 < *(int *)(param_1 + 0x18)) {
LAB_004c0b4e:
    iVar3 = param_2 * 4;
    piVar1 = (int *)(*(int *)(param_1 + 0x20) + param_2 * 4);
    if (*piVar1 == 0) {
      if (*(char *)(param_1 + 0x2b) == '\x02') {
        _Dst = (void *)sqlite3Malloc(0x8000);
        if (_Dst != (void *)0x0) {
          memset(_Dst,0,0x8000);
        }
        *(void **)(iVar3 + *(int *)(param_1 + 0x20)) = _Dst;
        if (*(int *)(iVar3 + *(int *)(param_1 + 0x20)) == 0) {
          iVar4 = 7;
        }
      }
      else {
        iVar4 = (**(code **)(**(int **)(param_1 + 4) + 0x34))
                          (*(int **)(param_1 + 4),param_2,0x8000,*(undefined1 *)(param_1 + 0x2c),
                           piVar1);
        if (iVar4 == 8) {
          *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
          iVar4 = 0;
        }
      }
    }
    *param_3 = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x20));
    return iVar4;
  }
  iVar3 = *(int *)(param_1 + 0x20);
  iVar2 = sqlite3_initialize();
  if (iVar2 == 0) {
    iVar3 = sqlite3Realloc(iVar3,param_2 * 4 + 4);
    if (iVar3 != 0) {
      memset((void *)(iVar3 + *(int *)(param_1 + 0x18) * 4),0,
             (param_2 - *(int *)(param_1 + 0x18)) * 4 + 4);
      *(int *)(param_1 + 0x20) = iVar3;
      *(int *)(param_1 + 0x18) = param_2 + 1;
      goto LAB_004c0b4e;
    }
  }
  *param_3 = 0;
  return 7;
}




/* [AUDIT] proposed: walIndexReadHdr  (confidence: high)
 * purpose: Read & validate the wal-index header, recovering it under a write lock if inconsistent
 * vars: walIndexTryHdr tryHdr; walIndexRecover recover; 'cannot open file'->0xe
 */
/* Global::walIndexReadHdr @ 004c0c00 */

int __cdecl walIndexReadHdr(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = walIndexPage(param_1,0,&local_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_8 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = walIndexTryHdr(param_1,param_2);
    iVar2 = 0;
    if (iVar1 == 0) goto LAB_004c0d0f;
  }
  if ((*(byte *)(param_1 + 0x2e) & 2) == 0) {
    if ((*(char *)(param_1 + 0x2b) != '\0') ||
       (iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),0,1,10),
       iVar2 == 0)) {
      *(undefined1 *)(param_1 + 0x2c) = 1;
      iVar2 = walIndexPage(param_1,0,&local_8);
      if ((iVar2 == 0) && (iVar1 = walIndexTryHdr(param_1,param_2), iVar1 != 0)) {
        iVar2 = walIndexRecover(param_1);
        *param_2 = 1;
      }
      *(undefined1 *)(param_1 + 0x2c) = 0;
      if (*(char *)(param_1 + 0x2b) == '\0') {
        (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),0,1,9);
      }
    }
  }
  else {
    if (*(char *)(param_1 + 0x2b) == '\0') {
      iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),0,1,6);
      if (iVar2 != 0) goto LAB_004c0d0b;
      if (*(char *)(param_1 + 0x2b) == '\0') {
        (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),0,1,5);
      }
    }
    iVar2 = 0x108;
  }
LAB_004c0d0b:
  if (iVar1 != 0) {
    return iVar2;
  }
LAB_004c0d0f:
  if (*(int *)(param_1 + 0x34) != 0x2de218) {
    sqlite3_log(0xe,"cannot open file at line %d of [%.10s]");
    iVar2 = 0xe;
  }
  return iVar2;
}




/* [AUDIT] proposed: walIndexRecover  (confidence: high)
 * purpose: Reconstruct the wal-index by scanning the WAL file frames and rebuilding hash tables
 * vars: 'Recovered %d frames from WAL file %s'; magic 0x377f0682; walIndexAppend append
 */
/* Global::walIndexRecover @ 004c0d40 */

void __cdecl walIndexRecover(int param_1)

{
  uint uVar1;
  undefined3 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  int local_5c;
  int local_58;
  uint *local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint *local_34;
  uint local_30;
  void *local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  iVar7 = *(byte *)(param_1 + 0x2d) + 1;
  local_58 = 8 - iVar7;
  local_4c = 0;
  local_48 = 0;
  if ((*(char *)(param_1 + 0x2b) == '\0') &&
     (iVar3 = (**(code **)(**(int **)(param_1 + 4) + 0x38))
                        (*(int **)(param_1 + 4),iVar7,local_58,10), iVar3 != 0)) goto LAB_004c1091;
  memset((void *)(param_1 + 0x34),0,0x30);
  iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x18))(*(int **)(param_1 + 8),&local_40);
  if (iVar3 == 0) {
    if ((-1 < local_3c) && ((0 < local_3c || (0x20 < local_40)))) {
      iVar3 = (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8),&local_28,0x20,0,0);
      if (iVar3 != 0) goto LAB_004c1073;
      uVar2 = CONCAT21(CONCAT11((undefined1)local_28,local_28._1_1_),local_28._2_1_);
      uVar8 = CONCAT31(CONCAT21(CONCAT11(local_20,local_1f),local_1e),local_1d);
      if ((((CONCAT31(uVar2,local_28._3_1_) & 0xfffffffe) == 0x377f0682) &&
          ((uVar8 & uVar8 - 1) == 0)) && (uVar8 - 0x200 < 0xfe01)) {
        local_30 = CONCAT31(uVar2,local_28._3_1_) & 0xffffff01;
        *(char *)(param_1 + 0x41) = (char)local_30;
        *(uint *)(param_1 + 0x24) = uVar8;
        uVar4 = sqlite3Get4byte(local_1c);
        *(undefined4 *)(param_1 + 0x68) = uVar4;
        *(undefined4 *)(param_1 + 0x54) = local_18;
        *(undefined4 *)(param_1 + 0x58) = local_14;
        walChecksumBytes((uint)((char)local_30 == '\0'),&local_28,0x18,(int *)0x0,
                     (int *)(param_1 + 0x4c));
        iVar3 = sqlite3Get4byte(local_10);
        if ((*(int *)(param_1 + 0x4c) == iVar3) &&
           (iVar3 = sqlite3Get4byte(local_c), *(int *)(param_1 + 0x50) == iVar3)) {
          iVar3 = sqlite3Get4byte(local_24);
          if (iVar3 == 0x2de218) {
            iVar3 = sqlite3_initialize();
            if ((iVar3 != 0) ||
               (local_34 = (uint *)sqlite3Malloc(uVar8 + 0x18), local_34 == (uint *)0x0))
            goto LAB_004c1073;
            local_54 = local_34 + 6;
            uVar1 = uVar8 + 0x18;
            local_30 = (int)uVar1 >> 0x1f;
            iVar6 = local_30 + (0xffffffdf < uVar1);
            local_2c = (void *)0x0;
            local_38 = 0x20;
            local_44 = 0;
            iVar3 = 0;
            if ((iVar6 <= local_3c) && ((iVar6 < local_3c || (uVar8 + 0x38 <= local_40)))) {
              while( true ) {
                local_2c = (void *)((int)local_2c + 1);
                iVar3 = sqlite3OsFileControl(*(int **)(param_1 + 8),local_34,uVar8 + 0x18,local_38,local_44)
                ;
                if ((iVar3 != 0) ||
                   ((iVar6 = walDecodeFrame(param_1,&local_50,&local_5c,local_54,local_34), iVar6 == 0
                    || (iVar3 = walIndexAppend(param_1,local_2c,local_50), iVar3 != 0)))) break;
                if (local_5c != 0) {
                  *(void **)(param_1 + 0x44) = local_2c;
                  *(int *)(param_1 + 0x48) = local_5c;
                  *(ushort *)(param_1 + 0x42) = CONCAT11(local_20,local_1f) | (ushort)uVar8 & 0xff00
                  ;
                  local_4c = *(undefined4 *)(param_1 + 0x4c);
                  local_48 = *(undefined4 *)(param_1 + 0x50);
                }
                bVar9 = CARRY4(local_38,uVar1);
                local_38 = local_38 + uVar1;
                local_44 = local_44 + local_30 + (uint)bVar9;
                iVar6 = local_30 + local_44 + (uint)CARRY4(uVar1,local_38);
                if ((local_3c <= iVar6) && ((local_3c < iVar6 || (local_40 < uVar1 + local_38))))
                break;
              }
            }
            sqlite3_free((int)local_34);
          }
          else {
            iVar3 = sqlite3CantopenError();
          }
          if (iVar3 != 0) goto LAB_004c1073;
        }
      }
    }
    *(undefined4 *)(param_1 + 0x4c) = local_4c;
    *(undefined4 *)(param_1 + 0x50) = local_48;
    walIndexWriteHdr(param_1);
    iVar3 = **(int **)(param_1 + 0x20);
    iVar6 = 4;
    *(undefined4 *)(iVar3 + 0x60) = 0;
    *(undefined4 *)(iVar3 + 100) = 0;
    piVar5 = (int *)(iVar3 + 0x68);
    do {
      *piVar5 = -1;
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (*(int *)(param_1 + 0x44) != 0) {
      *(int *)(iVar3 + 0x68) = *(int *)(param_1 + 0x44);
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      sqlite3_log(0,"Recovered %d frames from WAL file %s");
    }
  }
LAB_004c1073:
  if (*(char *)(param_1 + 0x2b) == '\0') {
    (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),iVar7,local_58,9);
  }
LAB_004c1091:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: walIndexTryHdr  (confidence: high)
 * purpose: Copy the two wal-index header copies from shm and verify they match with checksum
 * vars: +0x34 hdr; checksum loop; sets *param_2 changed flag
 */
/* Global::walIndexTryHdr @ 004c10b0 */

void __cdecl walIndexTryHdr(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  puVar7 = (undefined8 *)**(undefined4 **)(param_1 + 0x20);
  uVar1 = *puVar7;
  uVar2 = puVar7[1];
  uVar3 = puVar7[2];
  uVar4 = puVar7[3];
  uVar5 = puVar7[4];
  uVar6 = puVar7[5];
  local_38 = uVar1;
  local_30 = uVar2;
  local_28 = uVar3;
  local_20 = uVar4;
  local_18 = uVar5;
  local_10 = uVar6;
  if (*(char *)(param_1 + 0x2b) != '\x02') {
    (**(code **)(**(int **)(param_1 + 4) + 0x3c))(*(int **)(param_1 + 4));
  }
  local_68 = puVar7[6];
  local_60 = puVar7[7];
  local_58 = puVar7[8];
  local_50 = puVar7[9];
  local_48 = puVar7[10];
  local_40 = puVar7[0xb];
  piVar8 = (int *)&local_38;
  piVar10 = (int *)&local_68;
  uVar11 = 0x2c;
  do {
    if (*piVar8 != *piVar10) goto LAB_004c1295;
    piVar8 = piVar8 + 1;
    piVar10 = piVar10 + 1;
    bVar13 = 3 < uVar11;
    uVar11 = uVar11 - 4;
  } while (bVar13);
  if (local_30._4_1_ != '\0') {
    iVar12 = 0;
    piVar8 = (int *)&local_38;
    iVar9 = 0;
    do {
      iVar9 = iVar9 + *piVar8 + iVar12;
      iVar12 = iVar12 + piVar8[1] + iVar9;
      piVar8 = piVar8 + 2;
    } while (piVar8 < &local_10);
    if ((iVar9 == (int)local_10) && (iVar12 == local_10._4_4_)) {
      piVar8 = (int *)(param_1 + 0x34);
      piVar10 = (int *)&local_38;
      uVar11 = 0x2c;
      do {
        if (*piVar8 != *piVar10) {
          *param_2 = 1;
          *(undefined8 *)(param_1 + 0x34) = uVar1;
          *(undefined8 *)(param_1 + 0x3c) = uVar2;
          *(undefined8 *)(param_1 + 0x44) = uVar3;
          *(undefined8 *)(param_1 + 0x4c) = uVar4;
          *(undefined8 *)(param_1 + 0x54) = uVar5;
          *(undefined8 *)(param_1 + 0x5c) = uVar6;
          *(uint *)(param_1 + 0x24) =
               (*(ushort *)(param_1 + 0x42) & 1) * 0x10000 + (*(ushort *)(param_1 + 0x42) & 0xfe00);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        piVar8 = piVar8 + 1;
        piVar10 = piVar10 + 1;
        bVar13 = 3 < uVar11;
        uVar11 = uVar11 - 4;
      } while (bVar13);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_004c1295:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: walIndexWriteHdr  (confidence: high)
 * purpose: Write the current wal-index header (with checksum) into both shm header copies
 * vars: magic 0x2de218; checksum at +0x5c; two copies puVar2[0/6]
 */
/* Global::walIndexWriteHdr @ 004c12b0 */

void __cdecl walIndexWriteHdr(int param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = (undefined8 *)**(undefined4 **)(param_1 + 0x20);
  *(undefined1 *)(param_1 + 0x40) = 1;
  *(undefined4 *)(param_1 + 0x34) = 0x2de218;
  piVar3 = (int *)(param_1 + 0x34);
  iVar4 = 0;
  iVar5 = 0;
  do {
    iVar5 = iVar5 + *piVar3 + iVar4;
    piVar1 = piVar3 + 1;
    piVar3 = piVar3 + 2;
    iVar4 = iVar4 + *piVar1 + iVar5;
  } while (piVar3 < (int *)(param_1 + 0x5cU));
  *(int *)(param_1 + 0x5c) = iVar5;
  *(int *)(param_1 + 0x60) = iVar4;
  puVar2[6] = *(undefined8 *)(param_1 + 0x34);
  puVar2[7] = *(undefined8 *)(param_1 + 0x3c);
  puVar2[8] = *(undefined8 *)(param_1 + 0x44);
  puVar2[9] = *(undefined8 *)(param_1 + 0x4c);
  puVar2[10] = *(undefined8 *)(param_1 + 0x54);
  puVar2[0xb] = *(undefined8 *)(param_1 + 0x5c);
  if (*(char *)(param_1 + 0x2b) != '\x02') {
    (**(code **)(**(int **)(param_1 + 4) + 0x3c))(*(int **)(param_1 + 4));
  }
  *puVar2 = *(undefined8 *)(param_1 + 0x34);
  puVar2[1] = *(undefined8 *)(param_1 + 0x3c);
  puVar2[2] = *(undefined8 *)(param_1 + 0x44);
  puVar2[3] = *(undefined8 *)(param_1 + 0x4c);
  puVar2[4] = *(undefined8 *)(param_1 + 0x54);
  puVar2[5] = *(undefined8 *)(param_1 + 0x5c);
  return;
}




/* [AUDIT] proposed: walIteratorInit  (confidence: high)
 * purpose: Build a WAL checkpoint iterator: merge-sort each index block's page list by frame order
 * vars: walMergesort mergesort; +0x44 mxFrame; alloc via pcache1Alloc
 */
/* Global::walIteratorInit @ 004c1390 */

int __cdecl walIteratorInit(int param_1,undefined4 *param_2)

{
  size_t _Size;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_24;
  int local_14;
  int local_10;
  uint local_c;
  undefined4 *local_8;
  
  uVar1 = *(uint *)(param_1 + 0x44);
  iVar7 = (uVar1 + 0x21 >> 0xc) + 1;
  iVar5 = 0;
  _Size = (uVar1 + iVar7 * 10) * 2 + 8;
  local_8 = pcache1Alloc(_Size);
  if (local_8 != (undefined4 *)0x0) {
    memset(local_8,0,_Size);
    uVar2 = uVar1;
    if (0x1000 < uVar1) {
      uVar2 = 0x1000;
    }
    local_8[1] = iVar7;
    puVar3 = pcache1Alloc(uVar2 * 2);
    if (puVar3 == (undefined4 *)0x0) {
      iVar5 = 7;
    }
    iVar8 = param_1;
    for (iVar9 = 0; (iVar5 == 0 && (iVar9 < iVar7)); iVar9 = iVar9 + 1) {
      iVar5 = walIndexPage(param_1,iVar9,&local_14);
      if (iVar5 == 0) {
        local_24 = local_14 + 0x4000;
        if (iVar9 == 0) {
          local_10 = local_14 + 0x84;
          iVar8 = 0;
          local_14 = local_14 + 0x88;
        }
        else {
          local_10 = local_14 + -4;
          iVar8 = (iVar9 + -1) * 0x1000 + 0xfde;
        }
      }
      if (iVar5 == 0) {
        local_10 = local_10 + 4;
        if (iVar9 + 1 == iVar7) {
          local_c = uVar1 - iVar8;
        }
        else {
          local_c = local_24 - local_10 >> 2;
        }
        iVar4 = iVar8 + local_8[1] * 10;
        iVar8 = iVar8 + 1;
        pvVar6 = (void *)((int)local_8 + iVar4 * 2 + 8);
        iVar4 = 0;
        if (0 < (int)local_c) {
          do {
            *(short *)((int)pvVar6 + iVar4 * 2) = (short)iVar4;
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)local_c);
        }
        walMergesort(local_10,puVar3,pvVar6,&local_c);
        local_8[iVar9 * 5 + 5] = local_c;
        local_8[iVar9 * 5 + 3] = pvVar6;
        local_8[iVar9 * 5 + 6] = iVar8;
        local_8[iVar9 * 5 + 4] = local_10;
      }
    }
    pcache1Free(puVar3);
    if (iVar5 != 0) {
      pcache1Free(local_8);
    }
    *param_2 = local_8;
    return iVar5;
  }
  return 7;
}




/* [AUDIT] proposed: walIteratorNext  (confidence: high)
 * purpose: Return the next (pageNumber,frame) from a merge iterator across sorted index segments
 * vars: param_1 iterator; per-seg stride 5; returns done bool
 */
/* Global::walIteratorNext @ 004c1520 */

bool __cdecl walIteratorNext(uint *param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint local_8;
  
  uVar1 = *param_1;
  uVar4 = 0xffffffff;
  iVar5 = param_1[1] - 1;
  local_8 = 0xffffffff;
  if (-1 < iVar5) {
    puVar3 = param_1 + iVar5 * 5 + 2;
    do {
      if ((int)*puVar3 < (int)puVar3[3]) {
        do {
          uVar2 = *(uint *)(puVar3[2] + (uint)*(ushort *)(puVar3[1] + *puVar3 * 2) * 4);
          uVar4 = local_8;
          if (uVar1 < uVar2) {
            if (uVar2 < local_8) {
              *param_3 = (uint)*(ushort *)(puVar3[1] + *puVar3 * 2) + puVar3[4];
              uVar4 = uVar2;
              local_8 = uVar2;
            }
            break;
          }
          uVar2 = *puVar3 + 1;
          *puVar3 = uVar2;
        } while ((int)uVar2 < (int)puVar3[3]);
      }
      puVar3 = puVar3 + -5;
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  *param_1 = uVar4;
  *param_2 = uVar4;
  return uVar4 == 0xffffffff;
}




/* [AUDIT] proposed: sqlite3WalLimitSize  (confidence: high)
 * purpose: Truncate the WAL file down to a limit via xFileSize/xTruncate under I/O barriers
 * vars: 'cannot limit WAL size: %s'; fd +8
 */
/* Global::sqlite3WalLimitSize @ 004c15c0 */

void __cdecl sqlite3WalLimitSize(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint local_c;
  int local_8;
  
  if (DAT_00583e74 != (code *)0x0) {
    (*DAT_00583e74)();
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))(*(int **)(param_1 + 8),&local_c);
  if (((iVar1 == 0) && (param_3 <= local_8)) && ((param_3 < local_8 || (param_2 < local_c)))) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(*(int **)(param_1 + 8),param_2,param_3);
  }
  if (DAT_00583e78 != (code *)0x0) {
    (*DAT_00583e78)();
  }
  if (iVar1 != 0) {
    sqlite3_log(iVar1,"cannot limit WAL size: %s");
  }
  return;
}




/* [AUDIT] proposed: walMerge  (confidence: high)
 * purpose: Merge two sorted frame-index runs (by page number, dedup) into an output list
 * vars: param_4/5 in runs; param_6 scratch; page-key at param_1+idx*4
 */
/* Global::walMerge @ 004c1640 */

void __cdecl
walMerge(int param_1,void *param_2,int param_3,int *param_4,int *param_5,void *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int local_10;
  
  iVar1 = *param_5;
  iVar2 = *param_4;
  iVar4 = 0;
  iVar6 = 0;
  local_10 = 0;
  do {
    if (iVar6 < iVar1) {
      if (iVar4 < param_3) goto LAB_004c16a3;
LAB_004c16ce:
      iVar6 = iVar6 + 1;
      uVar5 = *(ushort *)(iVar2 + -2 + iVar6 * 2);
    }
    else {
      if (param_3 <= iVar4) {
        *param_4 = (int)param_2;
        *param_5 = local_10;
        memcpy(param_2,param_6,local_10 * 2);
        return;
      }
LAB_004c16a3:
      if (iVar6 < iVar1) {
        if (*(uint *)(param_1 + (uint)*(ushort *)(iVar2 + iVar6 * 2) * 4) <=
            *(uint *)(param_1 + (uint)*(ushort *)((int)param_2 + iVar4 * 2) * 4)) goto LAB_004c16ce;
        uVar5 = *(ushort *)((int)param_2 + iVar4 * 2);
        iVar4 = iVar4 + 1;
      }
      else {
        uVar5 = *(ushort *)((int)param_2 + iVar4 * 2);
        iVar4 = iVar4 + 1;
      }
    }
    iVar3 = *(int *)(param_1 + (uint)uVar5 * 4);
    local_10 = local_10 + 1;
    *(ushort *)((int)param_6 + local_10 * 2 + -2) = uVar5;
    if ((iVar4 < param_3) &&
       (*(int *)(param_1 + (uint)*(ushort *)((int)param_2 + iVar4 * 2) * 4) == iVar3)) {
      iVar4 = iVar4 + 1;
    }
  } while( true );
}




/* [AUDIT] proposed: walMergesort  (confidence: high)
 * purpose: Recursively merge-sort a WAL index block's page-number list into ascending order
 * vars: local_70 sublists; walMerge merge; up to 12 levels
 */
/* Global::walMergesort @ 004c1720 */

void __cdecl walMergesort(int param_1,void *param_2,void *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  void *_Dst;
  uint uVar9;
  int local_90;
  uint local_88;
  uint local_80;
  void *local_78;
  uint local_74;
  uint local_70 [26];
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  uVar1 = *param_4;
  local_74 = 0;
  local_78 = (void *)0x0;
  iVar6 = 0;
  memset(local_70,0,0x68);
  local_80 = 0;
  if ((int)uVar1 < 1) {
    uVar5 = 0;
  }
  else {
    do {
      iVar6 = 0;
      local_74 = 1;
      local_90 = 0;
      pvVar8 = param_3;
      _Dst = param_3;
      local_78 = param_3;
      if ((local_80 & 1) != 0) {
LAB_004c17a0:
        uVar5 = local_70[local_90 * 2];
        _Dst = (void *)local_70[local_90 * 2 + 1];
        iVar6 = 0;
        iVar7 = 0;
        local_88 = 0;
LAB_004c17c3:
        if (iVar7 < (int)local_74) {
          if (iVar6 < (int)uVar5) goto LAB_004c183c;
LAB_004c1867:
          iVar7 = iVar7 + 1;
          uVar4 = *(ushort *)((int)local_78 + iVar7 * 2 + -2);
        }
        else {
          if ((int)uVar5 <= iVar6) goto code_r0x004c17cb;
LAB_004c183c:
          if (iVar7 < (int)local_74) {
            if (*(uint *)(param_1 + (uint)*(ushort *)((int)pvVar8 + iVar7 * 2) * 4) <=
                *(uint *)(param_1 + (uint)*(ushort *)((int)_Dst + iVar6 * 2) * 4))
            goto LAB_004c1867;
            uVar4 = *(ushort *)((int)_Dst + iVar6 * 2);
            iVar6 = iVar6 + 1;
          }
          else {
            uVar4 = *(ushort *)((int)_Dst + iVar6 * 2);
            iVar6 = iVar6 + 1;
          }
        }
        iVar2 = *(int *)(param_1 + (uint)uVar4 * 4);
        local_88 = local_88 + 1;
        *(ushort *)((int)param_2 + local_88 * 2 + -2) = uVar4;
        pvVar8 = local_78;
        if ((iVar6 < (int)uVar5) &&
           (*(int *)(param_1 + (uint)*(ushort *)((int)_Dst + iVar6 * 2) * 4) == iVar2)) {
          iVar6 = iVar6 + 1;
        }
        goto LAB_004c17c3;
      }
LAB_004c1813:
      local_80 = local_80 + 1;
      param_3 = (void *)((int)param_3 + 2);
      local_70[iVar6 * 2 + 1] = (uint)_Dst;
      local_70[iVar6 * 2] = local_74;
      uVar5 = local_74;
    } while ((int)local_80 < (int)uVar1);
  }
  iVar6 = iVar6 + 1;
  bVar3 = (byte)iVar6 & 0x1f;
  uVar9 = 1 << bVar3 | 1U >> 0x20 - bVar3;
  if (0xc < iVar6) {
    *param_4 = uVar5;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  do {
    if ((uVar1 & uVar9) != 0) {
      walMerge(param_1,(void *)local_70[iVar6 * 2 + 1],local_70[iVar6 * 2],(int *)&local_78,
                   (int *)&local_74,param_2);
    }
    uVar9 = uVar9 << 1 | (uint)((int)uVar9 < 0);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xd);
  *param_4 = local_74;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
code_r0x004c17cb:
  local_74 = local_88;
  local_78 = _Dst;
  memcpy(_Dst,param_2,local_88 * 2);
  iVar6 = local_90 + 1;
  pvVar8 = _Dst;
  local_90 = iVar6;
  if ((local_80 & 1 << ((byte)iVar6 & 0x1f)) == 0) goto LAB_004c1813;
  goto LAB_004c17a0;
}




/* [AUDIT] proposed: walRestartHdr  (confidence: high)
 * purpose: Reset the WAL header for restart: bump change counter & salt via randomness, rewrite index hdr
 * vars: prng_nextByte randByte; walIndexWriteHdr writeHdr; read-marks reset
 */
/* Global::walRestartHdr @ 004c1940 */

void __cdecl walRestartHdr(int *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  piVar1 = param_1;
  if ((short)param_1[10] != 0) {
    return;
  }
  local_c = (int *)(*(int *)param_1[8] + 0x60);
  if (*local_c != 0) {
    iVar5 = 4;
    piVar3 = &local_8;
    if (DAT_00582acc == 0) {
      param_1 = (int *)0x0;
    }
    else {
      param_1 = (int *)(*DAT_00582b10)(5);
      if (param_1 != (int *)0x0) {
        (*DAT_00582b18)(param_1);
      }
    }
    do {
      uVar2 = prng_nextByte();
      *(undefined1 *)piVar3 = uVar2;
      piVar3 = (int *)((int)piVar3 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (param_1 != (int *)0x0) {
      (*DAT_00582b20)(param_1);
    }
    if ((*(char *)((int)piVar1 + 0x2b) == '\0') &&
       (iVar5 = (**(code **)(*(int *)piVar1[1] + 0x38))((int *)piVar1[1],4,4,10), iVar5 != 0)) {
      if (iVar5 != 5) {
        return;
      }
    }
    else {
      piVar1[0x1a] = piVar1[0x1a] + 1;
      piVar1[0x11] = 0;
      iVar5 = CONCAT31(CONCAT21(CONCAT11((char)piVar1[0x15],*(undefined1 *)((int)piVar1 + 0x55)),
                                *(undefined1 *)((int)piVar1 + 0x56)),
                       *(undefined1 *)((int)piVar1 + 0x57)) + 1;
      *(char *)(piVar1 + 0x15) = (char)((uint)iVar5 >> 0x18);
      *(char *)((int)piVar1 + 0x55) = (char)((uint)iVar5 >> 0x10);
      *(char *)((int)piVar1 + 0x56) = (char)((uint)iVar5 >> 8);
      *(char *)((int)piVar1 + 0x57) = (char)iVar5;
      piVar1[0x16] = local_8;
      walIndexWriteHdr((int)piVar1);
      *local_c = 0;
      local_c[2] = 0;
      piVar3 = local_c + 3;
      iVar5 = 3;
      do {
        *piVar3 = -1;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (*(char *)((int)piVar1 + 0x2b) != '\0') goto LAB_004c1a9f;
      (**(code **)(*(int *)piVar1[1] + 0x38))((int *)piVar1[1],4,4,9);
    }
  }
  if (*(char *)((int)piVar1 + 0x2b) == '\0') {
    (**(code **)(*(int *)piVar1[1] + 0x38))((int *)piVar1[1],3,1,5);
  }
LAB_004c1a9f:
  *(undefined2 *)(piVar1 + 10) = 0xffff;
  iVar5 = 0;
  do {
    iVar5 = iVar5 + 1;
    iVar4 = walTryBeginRead_4c1ad0(piVar1,&local_10,1,iVar5);
  } while (iVar4 == -1);
  return;
}




/* [AUDIT] proposed: walTryBeginRead  (confidence: high)
 * purpose: Attempt to begin a WAL read transaction: pick a read-mark, lock it, validate header stability
 * vars: walIndexReadHdr readHdr; read-marks +0x68; SQLITE_BUSY retries; -1=retry
 */
/* Global::walTryBeginRead_4c1ad0 @ 004c1ad0 */

int __cdecl walTryBeginRead_4c1ad0(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  uint local_8;
  
  if (5 < param_4) {
    iVar2 = 1;
    if (100 < param_4) {
      return 0xf;
    }
    if (9 < param_4) {
      iVar2 = (param_4 + -9) * 0xee;
    }
    (**(code **)(*param_1 + 0x3c))(*param_1,iVar2);
  }
  if (param_3 == 0) {
    iVar2 = walIndexReadHdr((int)param_1,param_2);
    if (iVar2 == 5) {
      if (*(int *)param_1[8] == 0) {
        return -1;
      }
      if ((*(char *)((int)param_1 + 0x2b) != '\0') ||
         (iVar2 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],2,1,6), iVar2 == 0)) {
        walUnlockShared((int)param_1,2);
        return -1;
      }
      if (iVar2 == 5) {
        return 0x105;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  iVar6 = 0;
  iVar2 = *(int *)param_1[8];
  if ((param_3 == 0) && (*(int *)(iVar2 + 0x60) == param_1[0x11])) {
    if (*(char *)((int)param_1 + 0x2b) == '\0') {
      iVar6 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],3,1,6);
    }
    else {
      iVar6 = 0;
    }
    if (*(char *)((int)param_1 + 0x2b) != '\x02') {
      (**(code **)(*(int *)param_1[1] + 0x3c))((int *)param_1[1]);
    }
    if (iVar6 == 0) {
      piVar5 = param_1 + 0xd;
      piVar3 = *(int **)param_1[8];
      uVar7 = 0x2c;
      do {
        if (*piVar3 != *piVar5) {
          walUnlockShared((int)param_1,3);
          return -1;
        }
        piVar3 = piVar3 + 1;
        piVar5 = piVar5 + 1;
        bVar8 = 3 < uVar7;
        uVar7 = uVar7 - 4;
      } while (bVar8);
      *(undefined2 *)(param_1 + 10) = 0;
      return 0;
    }
    if (iVar6 != 5) {
      return iVar6;
    }
  }
  local_8 = 0;
  param_4 = 0;
  iVar1 = 1;
  puVar4 = (uint *)(iVar2 + 0x68);
  do {
    uVar7 = *puVar4;
    if ((local_8 <= uVar7) && (uVar7 <= (uint)param_1[0x11])) {
      local_8 = uVar7;
      param_4 = iVar1;
    }
    iVar1 = iVar1 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar1 < 5);
  if ((*(byte *)((int)param_1 + 0x2e) & 2) == 0) {
    if (((uint)param_1[0x11] <= local_8) && (param_4 != 0)) goto LAB_004c1cf1;
    iVar1 = 1;
    do {
      if (*(char *)((int)param_1 + 0x2b) != '\0') {
        iVar6 = 0;
LAB_004c1ca4:
        local_8 = param_1[0x11];
        *(uint *)(iVar2 + 100 + iVar1 * 4) = local_8;
        param_4 = iVar1;
        if (*(char *)((int)param_1 + 0x2b) == '\0') {
          (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],iVar1 + 3,1,9);
        }
        break;
      }
      iVar6 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],iVar1 + 3,1,10);
      if (iVar6 == 0) goto LAB_004c1ca4;
      if (iVar6 != 5) {
        return iVar6;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 5);
  }
  if (param_4 == 0) {
    iVar2 = 0x208;
    if (iVar6 == 5) {
      iVar2 = -1;
    }
    return iVar2;
  }
LAB_004c1cf1:
  if ((*(char *)((int)param_1 + 0x2b) == '\0') &&
     (iVar6 = (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],param_4 + 3,1,6),
     iVar6 != 0)) {
    if (iVar6 == 5) {
      iVar6 = -1;
    }
    return iVar6;
  }
  if (*(char *)((int)param_1 + 0x2b) != '\x02') {
    (**(code **)(*(int *)param_1[1] + 0x3c))((int *)param_1[1]);
  }
  if (*(uint *)(iVar2 + 100 + param_4 * 4) == local_8) {
    piVar5 = param_1 + 0xd;
    piVar3 = *(int **)param_1[8];
    uVar7 = 0x2c;
    while (*piVar3 == *piVar5) {
      piVar3 = piVar3 + 1;
      piVar5 = piVar5 + 1;
      bVar8 = uVar7 < 4;
      uVar7 = uVar7 - 4;
      if (bVar8) {
        *(short *)(param_1 + 10) = (short)param_4;
        return 0;
      }
    }
  }
  if (*(char *)((int)param_1 + 0x2b) == '\0') {
    (**(code **)(*(int *)param_1[1] + 0x38))((int *)param_1[1],param_4 + 3,1,5);
  }
  return -1;
}




/* [AUDIT] proposed: walUnlockShared  (confidence: high)
 * purpose: Release a WAL shared read lock at slot param_2 via xShmLock
 * vars: xShmLock(+0x38) unlock-shared
 */
/* Global::walUnlockShared @ 004c1da0 */

void __cdecl walUnlockShared(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x2b) == '\0') {
    (**(code **)(**(int **)(param_1 + 4) + 0x38))(*(int **)(param_1 + 4),param_2,1,5);
  }
  return;
}




/* [AUDIT] proposed: walWriteToLog  (confidence: high)
 * purpose: Write data to the WAL/DB file, splitting the write at the mapping/size boundary with a sync
 * vars: iVar1+0xc mapEnd; xWrite(+0xc); xSync(+0x14)
 */
/* Global::walWriteToLog @ 004c1dd0 */

void __cdecl walWriteToLog(int param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = param_1;
  param_1 = param_5;
  if ((param_5 <= *(int *)(iVar1 + 0xc)) &&
     ((param_5 < *(int *)(iVar1 + 0xc) || (param_4 < *(uint *)(iVar1 + 8))))) {
    iVar3 = ((int)param_3 >> 0x1f) + param_5 + (uint)CARRY4(param_3,param_4);
    if ((*(int *)(iVar1 + 0xc) <= iVar3) &&
       ((*(int *)(iVar1 + 0xc) < iVar3 || (*(uint *)(iVar1 + 8) <= param_3 + param_4)))) {
      uVar2 = *(int *)(iVar1 + 8) - param_4;
      iVar3 = (**(code **)(**(int **)(iVar1 + 4) + 0xc))
                        (*(int **)(iVar1 + 4),param_2,uVar2,param_4,param_5);
      if (iVar3 != 0) {
        return;
      }
      bVar4 = CARRY4(param_4,uVar2);
      param_4 = param_4 + uVar2;
      param_1 = param_5 + ((int)uVar2 >> 0x1f) + (uint)bVar4;
      param_2 = param_2 + uVar2;
      param_3 = param_3 - uVar2;
      iVar3 = (**(code **)(**(int **)(iVar1 + 4) + 0x14))
                        (*(int **)(iVar1 + 4),*(undefined4 *)(iVar1 + 0x10));
      if (param_3 == 0) {
        return;
      }
      if (iVar3 != 0) {
        return;
      }
    }
  }
  (**(code **)(**(int **)(iVar1 + 4) + 0xc))(*(int **)(iVar1 + 4),param_2,param_3,param_4,param_1);
  return;
}




/* [AUDIT] proposed: pagerWriteWalHeader  (confidence: med)
 * purpose: Rewrite pager WAL/journal header: recompute page sizes, salts (randomness) & checksums, write out
 * vars: magic 0xf905d5d9/0xd763a120; prng_nextByte rand; +0x7c/0x80 sizes
 */
/* Global::pagerWriteWalHeader @ 004c29f0 */

int __cdecl pagerWriteWalHeader(uint param_1)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  longlong lVar12;
  int local_8;
  
  uVar4 = param_1;
  puVar2 = *(undefined8 **)(param_1 + 0xb0);
  uVar7 = *(uint *)(param_1 + 0x80);
  if (*(uint *)(param_1 + 0x7c) < *(uint *)(param_1 + 0x80)) {
    uVar7 = *(uint *)(param_1 + 0x7c);
  }
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    iVar11 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x5c) + iVar11;
      if (*(int *)(iVar8 + 8) == 0 && *(int *)(iVar8 + 0xc) == 0) {
        *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(param_1 + 0x48);
        *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(param_1 + 0x4c);
      }
      iVar9 = iVar9 + 1;
      iVar11 = iVar11 + 0x30;
    } while (iVar9 < *(int *)(param_1 + 0x60));
  }
  iVar9 = *(int *)(param_1 + 0x48);
  if (iVar9 == 0 && *(int *)(param_1 + 0x4c) == 0) {
    lVar12 = 0;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x7c);
    lVar12 = __alldiv(iVar9 - 1,*(int *)(param_1 + 0x4c) - (uint)(iVar9 == 0),uVar6,0);
    lVar12 = __allmul((uint)(lVar12 + 1),(int)((ulonglong)(lVar12 + 1) >> 0x20),uVar6,0);
  }
  *(longlong *)(param_1 + 0x48) = lVar12;
  *(longlong *)(param_1 + 0x50) = lVar12;
  if (((*(char *)(param_1 + 7) == '\0') && (*(char *)(param_1 + 5) != '\x04')) &&
     (uVar6 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x30))(*(int **)(param_1 + 0x3c)),
     (uVar6 & 0x200) == 0)) {
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
  }
  else {
    *(undefined4 *)puVar2 = 0xf905d5d9;
    *(undefined4 *)((int)puVar2 + 4) = 0xd763a120;
    *(undefined4 *)(puVar2 + 1) = 0xffffffff;
  }
  puVar10 = (undefined1 *)(param_1 + 0x30);
  iVar9 = 4;
  if (DAT_00582acc == 0) {
    local_8 = 0;
  }
  else {
    local_8 = (*DAT_00582b10)(5);
    if (local_8 != 0) {
      (*DAT_00582b18)(local_8);
    }
  }
  do {
    uVar5 = prng_nextByte();
    *puVar10 = uVar5;
    puVar10 = puVar10 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (local_8 != 0) {
    (*DAT_00582b20)(local_8);
  }
  uVar3 = *(undefined4 *)(param_1 + 0x30);
  *(char *)((int)puVar2 + 0xc) = (char)((uint)uVar3 >> 0x18);
  *(char *)((int)puVar2 + 0xf) = (char)uVar3;
  *(char *)((int)puVar2 + 0xd) = (char)((uint)uVar3 >> 0x10);
  *(char *)((int)puVar2 + 0xe) = (char)((uint)uVar3 >> 8);
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  *(char *)(puVar2 + 2) = (char)((uint)uVar3 >> 0x18);
  *(char *)((int)puVar2 + 0x11) = (char)((uint)uVar3 >> 0x10);
  *(char *)((int)puVar2 + 0x13) = (char)uVar3;
  *(char *)((int)puVar2 + 0x12) = (char)((uint)uVar3 >> 8);
  uVar3 = *(undefined4 *)(param_1 + 0x7c);
  *(char *)((int)puVar2 + 0x14) = (char)((uint)uVar3 >> 0x18);
  *(char *)((int)puVar2 + 0x15) = (char)((uint)uVar3 >> 0x10);
  *(char *)((int)puVar2 + 0x16) = (char)((uint)uVar3 >> 8);
  *(char *)((int)puVar2 + 0x17) = (char)uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x80);
  *(char *)(puVar2 + 3) = (char)((uint)uVar3 >> 0x18);
  *(char *)((int)puVar2 + 0x19) = (char)((uint)uVar3 >> 0x10);
  *(char *)((int)puVar2 + 0x1a) = (char)((uint)uVar3 >> 8);
  *(char *)((int)puVar2 + 0x1b) = (char)uVar3;
  memset((void *)((int)puVar2 + 0x1c),0,uVar7 - 0x1c);
  param_1 = 0;
  do {
    if (*(uint *)(uVar4 + 0x7c) <= param_1) {
      return 0;
    }
    iVar9 = (**(code **)(**(int **)(uVar4 + 0x40) + 0xc))
                      (*(int **)(uVar4 + 0x40),puVar2,uVar7,*(undefined4 *)(uVar4 + 0x48),
                       *(undefined4 *)(uVar4 + 0x4c));
    puVar1 = (uint *)(uVar4 + 0x48);
    uVar6 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    *(int *)(uVar4 + 0x4c) = *(int *)(uVar4 + 0x4c) + (uint)CARRY4(uVar6,uVar7);
    param_1 = param_1 + uVar7;
  } while (iVar9 == 0);
  return iVar9;
}




/* [AUDIT] proposed: walWriteWalFrames_journal  (confidence: med)
 * purpose: Write a super-journal/WAL header record (name + sizes + checksum) via file writes
 * vars: writeBigEndianToFile writeInt; &DAT_0056a700 salt; +0x40 fd
 */
/* Global::walWriteWalFrames_journal @ 004c2c10 */

int __cdecl walWriteWalFrames_journal(int param_1,char *param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  longlong lVar8;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  iVar4 = 0;
  local_14 = 0;
  if (((param_2 != (char *)0x0) && (*(char *)(param_1 + 5) != '\x04')) &&
     (*(char *)(param_1 + 5) != '\x02')) {
    *(undefined1 *)(param_1 + 0x12) = 1;
    cVar3 = *param_2;
    uVar6 = 0;
    if (cVar3 != '\0') {
      uVar6 = 0;
      do {
        uVar6 = uVar6 + 1;
        iVar4 = iVar4 + cVar3;
        cVar3 = param_2[uVar6];
        local_14 = iVar4;
      } while (cVar3 != '\0');
    }
    if (*(char *)(param_1 + 8) != '\0') {
      lVar8 = pager_journalHdrOffset(param_1);
      *(longlong *)(param_1 + 0x48) = lVar8;
    }
    local_c = *(uint *)(param_1 + 0x48);
    local_10 = *(int *)(param_1 + 0x4c);
    iVar4 = DAT_00582bb8 / *(int *)(param_1 + 0x80) + 1;
    local_8 = (undefined1)((uint)iVar4 >> 0x18);
    local_7 = (undefined1)((uint)iVar4 >> 0x10);
    local_6 = (undefined1)((uint)iVar4 >> 8);
    local_5 = (undefined1)iVar4;
    iVar4 = (**(code **)(**(int **)(param_1 + 0x40) + 0xc))
                      (*(int **)(param_1 + 0x40),&local_8,4,local_c,local_10);
    if ((iVar4 == 0) &&
       (iVar4 = (**(code **)(**(int **)(param_1 + 0x40) + 0xc))
                          (*(int **)(param_1 + 0x40),param_2,uVar6,local_c + 4,
                           local_10 + (uint)(0xfffffffb < local_c)), iVar4 == 0)) {
      bVar7 = CARRY4(uVar6,local_c);
      local_c = uVar6 + local_c;
      iVar5 = ((int)uVar6 >> 0x1f) + local_10 + (uint)bVar7;
      iVar4 = writeBigEndianToFile(*(int **)(param_1 + 0x40),local_c + 4,
                           iVar5 + (uint)(0xfffffffb < local_c),uVar6);
      uVar2 = local_c;
      if ((iVar4 == 0) &&
         ((iVar4 = writeBigEndianToFile(*(int **)(param_1 + 0x40),local_c + 8,
                                iVar5 + (uint)(0xfffffff7 < local_c),local_14), iVar4 == 0 &&
          (iVar4 = (**(code **)(**(int **)(param_1 + 0x40) + 0xc))
                             (*(int **)(param_1 + 0x40),&DAT_0056a700,8,uVar2 + 0xc,
                              iVar5 + (uint)(0xfffffff3 < uVar2)), iVar4 == 0)))) {
        uVar6 = uVar6 + 0x14;
        puVar1 = (uint *)(param_1 + 0x48);
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + uVar6;
        *(int *)(param_1 + 0x4c) =
             *(int *)(param_1 + 0x4c) + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar2,uVar6);
        iVar4 = (**(code **)(**(int **)(param_1 + 0x40) + 0x18))
                          (*(int **)(param_1 + 0x40),&local_1c);
        if (iVar4 == 0) {
          iVar5 = *(int *)(param_1 + 0x4c);
          if ((iVar5 <= local_18) && ((iVar5 < local_18 || (*(uint *)(param_1 + 0x48) < local_1c))))
          {
            iVar4 = sqlite3OsShmMap_or_v10(*(int **)(param_1 + 0x40),*(uint *)(param_1 + 0x48),iVar5);
          }
        }
      }
    }
    return iVar4;
  }
  return 0;
}




/* [AUDIT] proposed: pagerWalSyncTruncate  (confidence: low)
 * purpose: Finalize WAL/journal: write header, sync and truncate/zero the file per commit mode
 * vars: &DAT_0056bfc4 zero header; fd +0x40; xTruncate(+0x10)
 */
/* Global::pagerWalSyncTruncate @ 004c5a60 */

int __cdecl pagerWalSyncTruncate(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_c;
  int local_8;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x48) != 0 || *(int *)(param_1 + 0x4c) != 0) {
    iVar1 = *(int *)(param_1 + 0x8c);
    uVar2 = *(uint *)(param_1 + 0x88);
    if ((param_2 == 0) && (uVar2 != 0 || iVar1 != 0)) {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 0xc))
                        (*(int **)(param_1 + 0x40),&DAT_0056bfc4,0x1c,0,0);
    }
    else {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 0x10))(*(int **)(param_1 + 0x40),0,0);
    }
    if ((((iVar3 == 0) &&
         ((((*(char *)(param_1 + 7) != '\0' ||
            (iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 0x14))
                               (*(int **)(param_1 + 0x40),*(byte *)(param_1 + 0xb) | 0x10),
            iVar3 == 0)) && (-1 < iVar1)) && ((0 < iVar1 || (uVar2 != 0)))))) &&
        (iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 0x18))
                           (*(int **)(param_1 + 0x40),&local_c), iVar3 == 0)) &&
       ((iVar1 <= local_8 && ((iVar1 < local_8 || (uVar2 < local_c)))))) {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 0x10))
                        (*(int **)(param_1 + 0x40),uVar2,iVar1);
    }
  }
  return iVar3;
}




/* [AUDIT] proposed: std::vector::_Ucopy  (confidence: med)
 * purpose: Copy a range of 24-byte (6-word) elements to a destination buffer (misattributed WalkPathBehavior)
 * vars: stride 6 words; std::vector<struct24>
 */
/* Global::std_vector_Ucopy_4c5c10 @ 004c5c10 */

void __cdecl std_vector_Ucopy_4c5c10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 6) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
    }
    param_3 = param_3 + 6;
  }
  return;
}




/* [AUDIT] proposed: std::vector::copy_ctor  (confidence: med)
 * purpose: Copy-construct a std::vector of 24-byte structs: reserve then uninitialized-copy source range
 * vars: SEH frame; std_vector_Reserve_4c5d90 reserve; nElem=(end-begin)/0x18
 */
/* Global::std_vector_copy_ctor @ 004c5c60 */

undefined4 * __thiscall std_vector_copy_ctor(void *this,int *param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005542f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = std_vector_Reserve_4c5d90(this,(param_1[1] - *param_1) / 0x18);
  if ((char)uVar1 != '\0') {
    local_8 = 0;
    uVar1 = std_vector_Ucopy_4c5c10((undefined4 *)*param_1,(undefined4 *)param_1[1],*(undefined4 **)this);
    *(undefined4 *)((int)this + 4) = uVar1;
  }
  ExceptionList = local_10;
  return this;
}




/* [AUDIT] proposed: std::vector::_Reserve  (confidence: high)
 * purpose: Allocate storage for a std::vector of 24-byte elements, guarding overflow
 * vars: 'vector<T> too long'; max 0xaaaaaaa; operator_new(n*0x18)
 */
/* Global::std_vector_Reserve_4c5d90 @ 004c5d90 */

undefined4 __thiscall std_vector_Reserve_4c5d90(void *this,uint param_1)

{
  void *pvVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0xaaaaaaa < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
  pvVar1 = operator_new(param_1 * 0x18);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    *(void **)((int)this + 4) = pvVar1;
    pvVar1 = (void *)((int)pvVar1 + param_1 * 0x18);
    *(void **)((int)this + 8) = pvVar1;
    return CONCAT31((int3)((uint)pvVar1 >> 8),1);
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: std::pair::ctor2  (confidence: high)
 * purpose: Construct a 2-field pair/struct from two source pointers (misattributed World)
 * vars: copies *param_1,*param_2
 */
/* Global::std_pair_ctor2 @ 004c6540 */

undefined4 * __thiscall std_pair_ctor2(void *this,undefined4 *param_1,undefined4 *param_2)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = *param_2;
  return this;
}




/* [AUDIT] proposed: std::pair::copy_ctor  (confidence: high)
 * purpose: Copy a 2-word pair/struct (misattributed World)
 * vars: copies param_1[0],[1]
 */
/* Global::std_pair_copy_ctor @ 004c6560 */

undefined4 * __thiscall std_pair_copy_ctor(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  return this;
}




/* [AUDIT] proposed: std::_Tree::_Buynode_int2  (confidence: med)
 * purpose: Allocate a red-black tree node and copy a {int,int}+String key into it
 * vars: std_Tree_node_alloc_0x30 buynode; +6 String copy u16string_moveConstruct
 */
/* Global::std_Tree_Buynode_int2 @ 004c67a0 */

undefined4 * __thiscall std_Tree_Buynode_int2(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_Tree_node_alloc_0x30(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    puVar1[4] = *param_1;
    puVar1[5] = param_1[1];
    u16string_moveConstruct(puVar1 + 6,param_1 + 2);
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Tree::_Buynode_str  (confidence: med)
 * purpose: Allocate a map node and construct its std::string key + trailing value
 * vars: std_map_allocRawNode_0x2c buynode; +4 String; [10] value
 */
/* Global::std_Tree_Buynode_str @ 004c67e0 */

undefined4 * __thiscall std_Tree_Buynode_str(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_map_allocRawNode_0x2c(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    u16string_moveConstruct(puVar1 + 4,param_1);
    puVar1[10] = param_1[6];
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Tree::_Buynode_str2  (confidence: med)
 * purpose: Allocate a map node and construct its std::string key + two trailing values
 * vars: std_Tree_node_alloc_0x30 buynode; [10],[0xb] values
 */
/* Global::std_Tree_Buynode_str2 @ 004c6820 */

undefined4 * __thiscall std_Tree_Buynode_str2(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_Tree_node_alloc_0x30(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    u16string_moveConstruct(puVar1 + 4,param_1);
    puVar1[10] = param_1[6];
    puVar1[0xb] = param_1[7];
  }
  return puVar1;
}




/* [AUDIT] proposed: std::vector_of_vector::dtor  (confidence: med)
 * purpose: Destroy a range of objects each owning a vector<struct12>, freeing nested & outer storage (Zone)
 * vars: outer stride 0x62 words; inner stride 3; operator_delete
 */
/* Global::std_vector_of_vector_dtor @ 004c6860 */

void __cdecl std_vector_of_vector_dtor(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 != param_2) {
    puVar3 = param_1 + 0x12;
    do {
      puVar2 = (undefined4 *)*puVar3;
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)puVar3[1];
        for (; puVar2 != puVar1; puVar2 = puVar2 + 3) {
          if ((void *)*puVar2 != (void *)0x0) {
            operator_delete((void *)*puVar2);
            *puVar2 = 0;
            puVar2[1] = 0;
            puVar2[2] = 0;
          }
        }
        operator_delete((void *)*puVar3);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
      }
      puVar2 = puVar3 + 0x50;
      puVar3 = puVar3 + 0x62;
    } while (puVar2 != param_2);
  }
  return;
}




/* [AUDIT] proposed: std::_Tree::_Rebalance_int  (confidence: high)
 * purpose: Red-black tree insert fixup (recolor/rotate) after inserting an {int}-keyed node
 * vars: 'map/set<T> too long'; color byte +0xc; parent [1]
 */
/* Global::std_Tree_Rebalance_int @ 004c68e0 */

void __thiscall
std_Tree_Rebalance_int(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0xaaaaaa8 < *(uint *)((int)this + 4)) {
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_004c6ac1;
      }
LAB_004c6a18:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004c6a18;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_004c6ac1:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_Tree::_Rebalance_strkey  (confidence: high)
 * purpose: Red-black insert fixup for a node whose payload is a std::string (frees string on length error)
 * vars: 'map/set<T> too long'; +6 string, [0xb] cap
 */
/* Global::std_Tree_Rebalance_strkey @ 004c6af0 */

void __thiscall
std_Tree_Rebalance_strkey(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x5555553 < *(uint *)((int)this + 4)) {
    if (7 < (uint)param_5[0xb]) {
      operator_delete((void *)param_5[6]);
    }
    param_5[0xb] = 7;
    param_5[10] = 0;
    *(undefined2 *)(param_5 + 6) = 0;
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_004c6cfa;
      }
LAB_004c6c51:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004c6c51;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_004c6cfa:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_Tree::_Rebalance_strkey2  (confidence: high)
 * purpose: Red-black insert fixup for a string-keyed node variant (frees string buffer on overflow)
 * vars: 'map/set<T> too long'; +4 string,[9] cap
 */
/* Global::std_Tree_Rebalance_strkey2 @ 004c6d20 */

void __thiscall
std_Tree_Rebalance_strkey2(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x5d1745b < *(uint *)((int)this + 4)) {
    if (7 < (uint)param_5[9]) {
      operator_delete((void *)param_5[4]);
    }
    param_5[9] = 7;
    param_5[8] = 0;
    *(undefined2 *)(param_5 + 4) = 0;
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_004c6f2a;
      }
LAB_004c6e81:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004c6e81;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_004c6f2a:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_Tree::_Rebalance_strkey3  (confidence: high)
 * purpose: Red-black insert fixup for another string-keyed node layout (frees on length error)
 * vars: 'map/set<T> too long'; +4 string,[9] cap
 */
/* Global::std_Tree_Rebalance_strkey3 @ 004c6f50 */

void __thiscall
std_Tree_Rebalance_strkey3(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x5555553 < *(uint *)((int)this + 4)) {
    if (7 < (uint)param_5[9]) {
      operator_delete((void *)param_5[4]);
    }
    param_5[9] = 7;
    param_5[8] = 0;
    *(undefined2 *)(param_5 + 4) = 0;
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_004c715a;
      }
LAB_004c70b1:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004c70b1;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_004c715a:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_Tree::_Rebalance_buynode  (confidence: high)
 * purpose: Buynode via Path_allocNodeAssign then red-black insert fixup for a keyed node
 * vars: 'map/set<T> too long'; Path_allocNodeAssign alloc
 */
/* Global::std_Tree_Rebalance_buynode @ 004c7180 */

void __thiscall
std_Tree_Rebalance_buynode(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (0xcccccca < *(uint *)((int)this + 4)) {
    std::_Xlength_error("map/set<T> too long");
  }
  piVar3 = (int *)Path_allocNodeAssign(this,param_4);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  piVar3[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = piVar3;
    **(undefined4 **)this = piVar3;
    iVar4 = *(int *)this;
  }
  else {
    if (param_2 != '\0') {
      *param_3 = piVar3;
      if (param_3 == (undefined4 *)**(int **)this) {
        **(int **)this = (int)piVar3;
      }
      goto LAB_004c71de;
    }
    param_3[2] = piVar3;
    iVar4 = *(int *)this;
    if (param_3 != *(undefined4 **)(iVar4 + 8)) goto LAB_004c71de;
  }
  *(int **)(iVar4 + 8) = piVar3;
LAB_004c71de:
  cVar1 = *(char *)(piVar3[1] + 0xc);
  piVar5 = piVar3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = piVar3;
      return;
    }
    piVar7 = (int *)piVar5[1];
    piVar6 = *(int **)piVar7[1];
    if (piVar7 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar7[1])[2];
      if ((char)piVar6[3] != '\0') {
        if (piVar5 == (int *)piVar7[2]) {
          piVar5 = (int *)piVar7[2];
          piVar7[2] = *piVar5;
          if (*(char *)(*piVar5 + 0xd) == '\0') {
            *(int **)(*piVar5 + 4) = piVar7;
          }
          piVar5[1] = piVar7[1];
          if (piVar7 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar5;
          }
          else {
            piVar6 = (int *)piVar7[1];
            if (piVar7 == (int *)*piVar6) {
              *piVar6 = (int)piVar5;
            }
            else {
              piVar6[2] = (int)piVar5;
            }
          }
          *piVar5 = (int)piVar7;
          piVar7[1] = (int)piVar5;
          piVar5 = piVar7;
        }
        *(undefined1 *)(piVar5[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
        piVar7 = *(int **)(piVar5[1] + 4);
        piVar6 = (int *)*piVar7;
        *piVar7 = piVar6[2];
        if (*(char *)(piVar6[2] + 0xd) == '\0') {
          *(int **)(piVar6[2] + 4) = piVar7;
        }
        piVar6[1] = piVar7[1];
        if (piVar7 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar6;
          piVar6[2] = (int)piVar7;
        }
        else {
          piVar2 = (int *)piVar7[1];
          if (piVar7 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar6;
            piVar6[2] = (int)piVar7;
          }
          else {
            *piVar2 = (int)piVar6;
            piVar6[2] = (int)piVar7;
          }
        }
        goto LAB_004c735a;
      }
LAB_004c72b1:
      *(undefined1 *)(piVar7 + 3) = 1;
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      piVar5 = *(int **)(piVar5[1] + 4);
    }
    else {
      if ((char)piVar6[3] == '\0') goto LAB_004c72b1;
      if (piVar5 == (int *)*piVar7) {
        iVar4 = *piVar7;
        *piVar7 = *(int *)(iVar4 + 8);
        if (*(char *)(*(int *)(iVar4 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar4 + 8) + 4) = piVar7;
        }
        *(int *)(iVar4 + 4) = piVar7[1];
        if (piVar7 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar4;
        }
        else {
          piVar5 = (int *)piVar7[1];
          if (piVar7 == (int *)piVar5[2]) {
            piVar5[2] = iVar4;
          }
          else {
            *piVar5 = iVar4;
          }
        }
        *(int **)(iVar4 + 8) = piVar7;
        piVar7[1] = iVar4;
        piVar5 = piVar7;
      }
      *(undefined1 *)(piVar5[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      piVar7 = *(int **)(piVar5[1] + 4);
      piVar6 = (int *)piVar7[2];
      piVar7[2] = *piVar6;
      if (*(char *)(*piVar6 + 0xd) == '\0') {
        *(int **)(*piVar6 + 4) = piVar7;
      }
      piVar6[1] = piVar7[1];
      if (piVar7 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar6;
      }
      else {
        piVar2 = (int *)piVar7[1];
        if (piVar7 == (int *)*piVar2) {
          *piVar2 = (int)piVar6;
        }
        else {
          piVar2[2] = (int)piVar6;
        }
      }
      *piVar6 = (int)piVar7;
LAB_004c735a:
      piVar7[1] = (int)piVar6;
    }
    cVar1 = *(char *)(piVar5[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_Tree::_Insert_hint_int  (confidence: high)
 * purpose: Insert with hint into an int-keyed map: check adjacency to hint, else lower_bound + rebalance
 * vars: SEH; std_Tree_Rebalance_int rebalance; std_Tree_Insert_nohint_int nohint-insert
 */
/* Global::std_Tree_Insert_hint_int @ 004c7380 */

undefined4 * __thiscall
std_Tree_Insert_hint_int(void *this,undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  uint uStack_30;
  undefined4 local_20 [2];
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar5 = param_3;
  puStack_c = &LAB_00554370;
  local_10 = ExceptionList;
  uStack_30 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    local_14 = (undefined1 *)&uStack_30;
    std_Tree_Rebalance_int(this,param_1,'\x01',*(undefined4 **)this,param_3,param_4);
    ExceptionList = local_10;
    return param_1;
  }
  piVar1 = *(int **)this;
  if (param_2 == (int *)*piVar1) {
    local_14 = (undefined1 *)&uStack_30;
    puVar6 = &uStack_30;
    if (*param_3 < param_2[4]) {
LAB_004c73ff:
      local_14 = (undefined1 *)puVar6;
      std_Tree_Rebalance_int(local_18,param_1,'\x01',param_2,piVar5,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    local_14 = (undefined1 *)&uStack_30;
    if ((int)((undefined4 *)piVar1[2])[4] < *param_3) {
      local_14 = (undefined1 *)&uStack_30;
      std_Tree_Rebalance_int(this,param_1,'\0',(undefined4 *)piVar1[2],param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    iVar2 = *param_3;
    iVar3 = param_2[4];
    bVar8 = SBORROW4(iVar3,iVar2);
    iVar4 = iVar3 - iVar2;
    puVar6 = &uStack_30;
    if (iVar2 < iVar3) {
      param_3 = param_2;
      std_Rb_tree_increment((int *)&param_3);
      iVar4 = *piVar5;
      if (param_3[4] < iVar4) {
        puVar6 = (uint *)local_14;
        if (*(char *)(param_3[2] + 0xd) != '\0') {
          std_Tree_Rebalance_int(local_18,param_1,'\0',param_3,piVar5,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        goto LAB_004c73ff;
      }
      bVar8 = SBORROW4(param_2[4],iVar4);
      iVar4 = param_2[4] - iVar4;
      puVar6 = (uint *)local_14;
    }
    local_14 = (undefined1 *)puVar6;
    if (bVar8 != iVar4 < 0) {
      param_3 = param_2;
      RBTree_iterIncrement((int *)&param_3);
      if ((param_3 == piVar1) || (*piVar5 < param_3[4])) {
        if (*(char *)(param_2[2] + 0xd) == '\0') {
          std_Tree_Rebalance_int(local_18,param_1,'\x01',param_3,piVar5,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_Tree_Rebalance_int(local_18,param_1,'\0',param_2,piVar5,param_4);
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
  local_8 = 0xffffffff;
  puVar7 = (undefined4 *)std_Tree_Insert_nohint_int(local_18,local_20,'\0',piVar5,param_4);
  *param_1 = *puVar7;
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std::_Tree::_Insert_hint_pair  (confidence: high)
 * purpose: Insert with hint into a {int,int}-keyed map using comparator, else fall back to positional insert
 * vars: std_pair_less_2 compare; std_Tree_Rebalance_strkey rebalance; std_Tree_Insert_nohint_pair nohint
 */
/* Global::std_Tree_Insert_hint_pair @ 004c7570 */

undefined4 * __thiscall
std_Tree_Insert_hint_pair(void *this,undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uStack_34;
  undefined4 local_24;
  int *local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00554390;
  local_10 = ExceptionList;
  uStack_34 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = this;
  if (*(int *)((int)this + 4) == 0) {
    local_14 = (undefined1 *)&uStack_34;
    std_Tree_Rebalance_strkey(this,param_1,'\x01',*(undefined4 **)this,param_3,param_4);
    ExceptionList = local_10;
    return param_1;
  }
  piVar1 = *(int **)this;
  if (param_2 == (int *)*piVar1) {
    puVar3 = &uStack_34;
    if ((*param_3 < param_2[4]) ||
       ((local_14 = (undefined1 *)&uStack_34, *param_3 <= param_2[4] &&
        (local_14 = (undefined1 *)&uStack_34, puVar3 = &uStack_34, param_3[1] < param_2[5])))) {
LAB_004c7601:
      local_14 = (undefined1 *)puVar3;
      std_Tree_Rebalance_strkey(local_1c,param_1,'\x01',param_2,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    puVar5 = (undefined4 *)piVar1[2];
    if (((int)puVar5[4] < *param_3) ||
       ((local_14 = (undefined1 *)&uStack_34, (int)puVar5[4] <= *param_3 &&
        (local_14 = (undefined1 *)&uStack_34, (int)puVar5[5] < param_3[1])))) {
      local_14 = (undefined1 *)&uStack_34;
      std_Tree_Rebalance_strkey(this,param_1,'\0',puVar5,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    if ((*param_3 < param_2[4]) ||
       ((puVar3 = &uStack_34, *param_3 <= param_2[4] &&
        (puVar3 = &uStack_34, param_3[1] < param_2[5])))) {
      local_20 = param_2;
      std_Rb_tree_increment((int *)&local_20);
      piVar2 = local_20;
      uVar4 = std_pair_less_2(local_20 + 4,param_3);
      puVar3 = (uint *)local_14;
      if ((char)uVar4 != '\0') {
        if (*(char *)(piVar2[2] + 0xd) != '\0') {
          std_Tree_Rebalance_strkey(local_1c,param_1,'\0',piVar2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        goto LAB_004c7601;
      }
    }
    local_14 = (undefined1 *)puVar3;
    uVar4 = std_pair_less_2(param_2 + 4,param_3);
    if ((char)uVar4 != '\0') {
      local_20 = param_2;
      RBTree_iterIncrement((int *)&local_20);
      piVar2 = local_20;
      if ((local_20 == piVar1) || (uVar4 = std_pair_less_2(param_3,local_20 + 4), (char)uVar4 != '\0'))
      {
        if (*(char *)(param_2[2] + 0xd) == '\0') {
          std_Tree_Rebalance_strkey(local_1c,param_1,'\x01',piVar2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_Tree_Rebalance_strkey(local_1c,param_1,'\0',param_2,param_3,param_4);
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
  local_8 = 0xffffffff;
  puVar5 = (undefined4 *)std_Tree_Insert_nohint_pair(local_1c,&local_24,'\0',param_3,param_4);
  *param_1 = *puVar5;
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std::_Tree::_Insert_hint_str  (confidence: high)
 * purpose: Insert with hint into a string-keyed map (string compare via wstring_compareSubstr), else nohint insert
 * vars: wstring_compareSubstr memcmp; std_Tree_Rebalance_strkey3 rebalance; std_Tree_Insert_nohint_str2 nohint
 */
/* Global::std_Tree_Insert_hint_str @ 004c77c0 */

undefined4 * __thiscall
std_Tree_Insert_hint_str(void *this,undefined4 *param_1,ushort *param_2,ushort *param_3,int *param_4)

{
  ushort *puVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uStack_2c;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_3;
  puStack_c = &LAB_005543b0;
  local_10 = ExceptionList;
  uStack_2c = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    puVar4 = *(ushort **)this;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    puVar5 = *(ushort **)this;
    puVar4 = param_2;
    if (param_2 != *(ushort **)puVar5) {
      if (param_2 == puVar5) {
        puVar4 = param_3;
        if (7 < *(uint *)(param_3 + 10)) {
          puVar4 = *(ushort **)param_3;
        }
        local_14 = (undefined1 *)&uStack_2c;
        uVar3 = wstring_compareSubstr((void *)(*(int *)(puVar5 + 4) + 0x10),0,
                             *(uint *)(*(int *)(puVar5 + 4) + 0x20),puVar4,*(uint *)(param_3 + 8));
        if (-1 < (int)uVar3) goto LAB_004c7961;
        puVar4 = *(ushort **)(*(int *)this + 8);
        cVar7 = '\0';
        goto LAB_004c7809;
      }
      puVar5 = param_2 + 8;
      if (7 < *(uint *)(param_2 + 0x12)) {
        puVar5 = *(ushort **)puVar5;
      }
      uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
      if ((int)uVar3 < 0) {
        param_3 = param_2;
        std_Rb_tree_increment((int *)&param_3);
        puVar5 = param_3;
        bVar2 = wstring_lessCompare(param_3 + 8,puVar1);
        if (!bVar2) goto LAB_004c7906;
        if (*(char *)(*(int *)(puVar5 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_004c7809;
        }
      }
      else {
LAB_004c7906:
        bVar2 = wstring_lessCompare(param_2 + 8,puVar1);
        if (!bVar2) {
LAB_004c7961:
          local_8 = 0xffffffff;
          puVar6 = (undefined4 *)std_Tree_Insert_nohint_str2(this,&local_1c,(undefined4 *)0x0,puVar1,param_4);
          *param_1 = *puVar6;
          ExceptionList = local_10;
          return param_1;
        }
        param_3 = param_2;
        RBTree_iterIncrement((int *)&param_3);
        puVar4 = param_3;
        if ((param_3 != (ushort *)*local_18) &&
           (bVar2 = wstring_lessCompare(puVar1,param_3 + 8), this = local_18, !bVar2)) goto LAB_004c7961;
        this = local_18;
        puVar5 = param_2;
        if (*(char *)(*(int *)(param_2 + 4) + 0xd) == '\0') {
          cVar7 = '\x01';
          goto LAB_004c7809;
        }
      }
      cVar7 = '\0';
      puVar4 = puVar5;
      goto LAB_004c7809;
    }
    puVar5 = param_2 + 8;
    if (7 < *(uint *)(param_2 + 0x12)) {
      puVar5 = *(ushort **)puVar5;
    }
    local_14 = (undefined1 *)&uStack_2c;
    uVar3 = wstring_compareSubstr(param_3,0,*(uint *)(param_3 + 8),puVar5,*(uint *)(param_2 + 0x10));
    if (-1 < (int)uVar3) goto LAB_004c7961;
  }
  cVar7 = '\x01';
LAB_004c7809:
  std_Tree_Rebalance_strkey3(this,param_1,cVar7,(undefined4 *)puVar4,puVar1,param_4);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std::_Tree::_Insert_nohint_int  (confidence: high)
 * purpose: Locate insertion point in an int-keyed tree (descend by key) and rebalance-insert the new node
 * vars: SEH; std_Rb_tree_increment predecessor; std_Tree_Rebalance_int rebalance
 */
/* Global::std_Tree_Insert_nohint_int @ 004c79b0 */

void __thiscall std_Tree_Insert_nohint_int(void *this,undefined4 *param_1,char param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_3;
  puStack_c = &LAB_005543d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)this;
  local_8 = 0;
  local_18 = true;
  piVar5 = piVar1;
  if (*(char *)(piVar1[1] + 0xd) == '\0') {
    piVar3 = (int *)piVar1[1];
    do {
      piVar5 = piVar3;
      if (param_2 == '\0') {
        local_18 = *param_3 < piVar5[4];
      }
      else {
        local_18 = *param_3 <= piVar5[4];
      }
      if (local_18 == false) {
        piVar3 = (int *)piVar5[2];
      }
      else {
        piVar3 = (int *)*piVar5;
      }
    } while (*(char *)((int)piVar3 + 0xd) == '\0');
  }
  _param_2 = piVar5;
  if (local_18 != false) {
    if (piVar5 == (int *)*piVar1) {
      local_18 = true;
      goto LAB_004c7a43;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  piVar1 = _param_2;
  if (*piVar2 <= _param_2[4]) {
    operator_delete(param_4);
    *param_1 = piVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_004c7a43:
  puVar4 = (undefined4 *)std_Tree_Rebalance_int(this,(undefined4 *)&param_2,local_18,piVar5,piVar2,param_4);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::_Tree::_Insert_nohint_pair  (confidence: high)
 * purpose: Locate insertion point in a {int,int}-keyed tree and rebalance-insert, freeing node if duplicate
 * vars: std_Rb_tree_increment predecessor; std_Tree_Rebalance_strkey rebalance
 */
/* Global::std_Tree_Insert_nohint_pair @ 004c7ad0 */

void __thiscall std_Tree_Insert_nohint_pair(void *this,undefined4 *param_1,char param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar3 = param_3;
  puStack_c = &LAB_005543f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar5 = *(undefined4 **)this;
  local_8 = 0;
  local_18 = true;
  if (*(char *)((int)puVar5[1] + 0xd) == '\0') {
    iVar1 = *param_3;
    puVar6 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar6;
      iVar2 = puVar5[4];
      if (param_2 == '\0') {
        if ((iVar1 < iVar2) || ((iVar1 <= iVar2 && (param_3[1] < (int)puVar5[5])))) {
          local_18 = true;
          goto LAB_004c7b71;
        }
        local_18 = false;
LAB_004c7b67:
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
        if ((iVar2 < iVar1) || ((iVar2 <= iVar1 && ((int)puVar5[5] < param_3[1])))) {
          local_18 = true;
        }
        else {
          local_18 = false;
        }
        local_18 = !local_18;
        if (!local_18) goto LAB_004c7b67;
LAB_004c7b71:
        puVar6 = (undefined4 *)*puVar5;
      }
    } while (*(char *)((int)puVar6 + 0xd) == '\0');
  }
  _param_2 = puVar5;
  if (local_18) {
    if (puVar5 == (undefined4 *)**(int **)this) {
      local_18 = true;
      goto LAB_004c7b92;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  piVar4 = param_4;
  puVar6 = _param_2;
  if ((*piVar3 <= (int)_param_2[4]) &&
     ((*piVar3 < (int)_param_2[4] || (piVar3[1] <= (int)_param_2[5])))) {
    if (7 < (uint)param_4[0xb]) {
      operator_delete((void *)param_4[6]);
    }
    piVar4[0xb] = 7;
    piVar4[10] = 0;
    *(undefined2 *)(piVar4 + 6) = 0;
    operator_delete(piVar4);
    *param_1 = puVar6;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_004c7b92:
  puVar5 = (undefined4 *)std_Tree_Rebalance_strkey(this,(undefined4 *)&param_2,local_18,puVar5,piVar3,param_4);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::_Tree::_Insert_nohint_str  (confidence: high)
 * purpose: Locate insertion point in a string-keyed tree (wstring_compareSubstr compare) and rebalance-insert
 * vars: wstring_compareSubstr compare; std_Tree_Rebalance_strkey2 rebalance
 */
/* Global::std_Tree_Insert_nohint_str @ 004c7c50 */

void __thiscall
std_Tree_Insert_nohint_str(void *this,undefined4 *param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  ushort *this_00;
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  this_00 = param_3;
  puStack_c = &LAB_00554410;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = true;
  puVar3 = *(undefined4 **)this;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  while (*(char *)((int)puVar5 + 0xd) == '\0') {
    if ((char)param_2 == '\0') {
      puVar4 = (ushort *)(puVar5 + 4);
      if (7 < (uint)puVar5[9]) {
        puVar4 = *(ushort **)puVar4;
      }
      uVar2 = wstring_compareSubstr(this_00,0,*(uint *)(this_00 + 8),puVar4,puVar5[8]);
      local_18 = (int)uVar2 < 0;
    }
    else {
      puVar4 = this_00;
      if (7 < *(uint *)(this_00 + 10)) {
        puVar4 = *(ushort **)this_00;
      }
      uVar2 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar4,*(uint *)(this_00 + 8));
      local_18 = -1 < (int)uVar2;
    }
    puVar3 = puVar5;
    if (local_18 == false) {
      puVar5 = (undefined4 *)puVar5[2];
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  param_2 = puVar3;
  if (local_18 != false) {
    if (puVar3 == (undefined4 *)**(int **)this) {
      local_18 = true;
      goto LAB_004c7d0e;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  puVar5 = param_2;
  puVar4 = this_00;
  if (7 < *(uint *)(this_00 + 10)) {
    puVar4 = *(ushort **)this_00;
  }
  uVar2 = wstring_compareSubstr(param_2 + 4,0,param_2[8],puVar4,*(uint *)(this_00 + 8));
  piVar1 = param_4;
  if (-1 < (int)uVar2) {
    if (7 < (uint)param_4[9]) {
      operator_delete((void *)param_4[4]);
    }
    piVar1[9] = 7;
    piVar1[8] = 0;
    *(undefined2 *)(piVar1 + 4) = 0;
    operator_delete(piVar1);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_004c7d0e:
  puVar3 = (undefined4 *)std_Tree_Rebalance_strkey2(this,&param_2,local_18,puVar3,this_00,param_4);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::_Tree::_Insert_nohint_str2  (confidence: high)
 * purpose: String-keyed tree insertion-point search and rebalance-insert (variant of 4c7c50)
 * vars: wstring_compareSubstr compare; std_Tree_Rebalance_strkey3 rebalance
 */
/* Global::std_Tree_Insert_nohint_str2 @ 004c7de0 */

void __thiscall
std_Tree_Insert_nohint_str2(void *this,undefined4 *param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  ushort *this_00;
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  this_00 = param_3;
  puStack_c = &LAB_00554430;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = true;
  puVar3 = *(undefined4 **)this;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  while (*(char *)((int)puVar5 + 0xd) == '\0') {
    if ((char)param_2 == '\0') {
      puVar4 = (ushort *)(puVar5 + 4);
      if (7 < (uint)puVar5[9]) {
        puVar4 = *(ushort **)puVar4;
      }
      uVar2 = wstring_compareSubstr(this_00,0,*(uint *)(this_00 + 8),puVar4,puVar5[8]);
      local_18 = (int)uVar2 < 0;
    }
    else {
      puVar4 = this_00;
      if (7 < *(uint *)(this_00 + 10)) {
        puVar4 = *(ushort **)this_00;
      }
      uVar2 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar4,*(uint *)(this_00 + 8));
      local_18 = -1 < (int)uVar2;
    }
    puVar3 = puVar5;
    if (local_18 == false) {
      puVar5 = (undefined4 *)puVar5[2];
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  param_2 = puVar3;
  if (local_18 != false) {
    if (puVar3 == (undefined4 *)**(int **)this) {
      local_18 = true;
      goto LAB_004c7e9e;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  puVar5 = param_2;
  puVar4 = this_00;
  if (7 < *(uint *)(this_00 + 10)) {
    puVar4 = *(ushort **)this_00;
  }
  uVar2 = wstring_compareSubstr(param_2 + 4,0,param_2[8],puVar4,*(uint *)(this_00 + 8));
  piVar1 = param_4;
  if (-1 < (int)uVar2) {
    if (7 < (uint)param_4[9]) {
      operator_delete((void *)param_4[4]);
    }
    piVar1[9] = 7;
    piVar1[8] = 0;
    *(undefined2 *)(piVar1 + 4) = 0;
    operator_delete(piVar1);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_004c7e9e:
  puVar3 = (undefined4 *)std_Tree_Rebalance_strkey3(this,&param_2,local_18,puVar3,this_00,param_4);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::pair::ctor_swap  (confidence: high)
 * purpose: Construct a 2-field pair, taking first from param_2, second from param_3
 * vars: -
 */
/* Global::std_pair_ctor_swap @ 004c8130 */

void __cdecl std_pair_ctor_swap(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = *param_3;
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return;
}




/* [AUDIT] proposed: std::pair::copy_ctor2  (confidence: high)
 * purpose: Copy a 2-word pair/struct from source (World)
 * vars: -
 */
/* Global::std_pair_copy_ctor2 @ 004cde20 */

undefined4 * __thiscall std_pair_copy_ctor2(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  return this;
}




/* [AUDIT] proposed: std::map::operator[]_int  (confidence: high)
 * purpose: Map operator[] for int key: find lower_bound; if absent insert default-valued node; return value slot
 * vars: std_Tree_node_alloc_assign2 make node; std_Tree_Insert_hint_int insert; returns node+5
 */
/* Global::std_map_operator_int @ 004cde60 */

int * __thiscall std_map_operator_int(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_c [2];
  
  piVar3 = *(int **)this;
  piVar4 = piVar3;
  if (*(char *)(piVar3[1] + 0xd) == '\0') {
    piVar1 = (int *)piVar3[1];
    do {
      if (piVar1[4] < *param_1) {
        piVar2 = (int *)piVar1[2];
      }
      else {
        piVar2 = (int *)*piVar1;
        piVar4 = piVar1;
      }
      piVar1 = piVar2;
    } while (*(char *)((int)piVar2 + 0xd) == '\0');
  }
  if ((piVar4 != piVar3) && (piVar4[4] <= *param_1)) {
    return piVar4 + 5;
  }
  local_c[0] = *param_1;
  local_c[1] = 0;
  piVar3 = std_Tree_node_alloc_assign2(this,local_c);
  std_Tree_Insert_hint_int(this,&param_1,piVar4,piVar3 + 4,piVar3);
  return param_1 + 5;
}




/* [AUDIT] proposed: std::map::insert_pair  (confidence: high)
 * purpose: Insert a {int,int}->value entry into a map if key absent (lower_bound + hinted insert)
 * vars: SEH; std_map_lower_bound_2key lower_bound; std_Tree_Insert_hint_pair insert
 */
/* Global::std_map_insert_pair @ 004cdef0 */

void __thiscall std_map_insert_pair(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_50;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  int local_34;
  int local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005548a0;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = std_map_lower_bound_2key(this,param_1);
  if (piVar1 != *(int **)this) {
    if ((piVar1[4] <= *param_1) && ((piVar1[4] < *param_1 || (piVar1[5] <= param_1[1]))))
    goto LAB_004cdfd0;
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_8 = 0;
  local_34 = *param_1;
  local_30 = param_1[1];
  u16string_moveConstruct(local_2c,local_4c);
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar2 = std_Tree_Buynode_int2(this,&local_34);
  std_Tree_Insert_hint_pair(this,&local_50,piVar1,piVar2 + 4,piVar2);
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
LAB_004cdfd0:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::map::insert_str  (confidence: high)
 * purpose: Insert a std::string-keyed entry into a map if key absent (buynode + positional insert)
 * vars: std_map_lowerBound_strKey lower_bound; wstring_compareSubstr compare; std_map_insertHint_strKey insert
 */
/* Global::std_map_insert_str @ 004ce000 */

void __thiscall std_map_insert_str(void *this,ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005548d8;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (ushort *)std_map_lowerBound_strKey(this,param_1);
  if (puVar1 != *(ushort **)this) {
    puVar2 = puVar1 + 8;
    if (7 < *(uint *)(puVar1 + 0x12)) {
      puVar2 = *(ushort **)puVar2;
    }
    uVar3 = wstring_compareSubstr(param_1,0,*(uint *)(param_1 + 8),puVar2,*(uint *)(puVar1 + 0x10));
    if (-1 < (int)uVar3) goto LAB_004ce0ba;
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  U16String_assignSubstr(local_30,(int *)param_1,0,0xffffffff);
  local_18 = 0;
  local_8 = 0;
  piVar4 = std_Tree_Buynode_str(this,local_30);
  std_map_insertHint_strKey(this,&local_34,puVar1,(ushort *)(piVar4 + 4),piVar4);
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
LAB_004ce0ba:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::map::insert_str2  (confidence: high)
 * purpose: Insert a std::string-keyed entry (variant) into a map if key absent
 * vars: std_map_lowerBound_strKey lower_bound; std_Tree_Insert_hint_str insert; std_Tree_Buynode_str2 buynode
 */
/* Global::std_map_insert_str2 @ 004ce0e0 */

void __thiscall std_map_insert_str2(void *this,ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_38;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554908;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (ushort *)std_map_lowerBound_strKey(this,param_1);
  if (puVar1 != *(ushort **)this) {
    puVar2 = puVar1 + 8;
    if (7 < *(uint *)(puVar1 + 0x12)) {
      puVar2 = *(ushort **)puVar2;
    }
    uVar3 = wstring_compareSubstr(param_1,0,*(uint *)(param_1 + 8),puVar2,*(uint *)(puVar1 + 0x10));
    if (-1 < (int)uVar3) goto LAB_004ce1a1;
  }
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
  U16String_assignSubstr(local_34,(int *)param_1,0,0xffffffff);
  local_1c = 0;
  local_18 = 0;
  local_8 = 0;
  piVar4 = std_Tree_Buynode_str2(this,local_34);
  std_Tree_Insert_hint_str(this,&local_38,puVar1,(ushort *)(piVar4 + 4),piVar4);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
LAB_004ce1a1:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::pair_less  (confidence: high)
 * purpose: Comparator: return true if this-pair < param_1-pair (lexicographic on {second,first})
 * vars: +4 first vs +0 second ordering
 */
/* Global::std_pair_less @ 004ce350 */

uint __thiscall std_pair_less(void *this,uint *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
  if (((int)uVar1 <= (int)param_1[1]) &&
     (((int)uVar1 < (int)param_1[1] || (uVar1 = *(uint *)this, uVar1 < *param_1)))) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}




/* [AUDIT] proposed: std::pair_lessequal  (confidence: high)
 * purpose: Comparator: return true if this-pair <= param_1-pair (lexicographic)
 * vars: mirror of 4ce350
 */
/* Global::std_pair_lessequal @ 004ce380 */

uint __thiscall std_pair_lessequal(void *this,uint *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
  if (((int)param_1[1] <= (int)uVar1) &&
     (((int)param_1[1] < (int)uVar1 || (uVar1 = *(uint *)this, *param_1 <= uVar1)))) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}




/* [AUDIT] proposed: std::pair_less_2  (confidence: high)
 * purpose: Comparator on two {int,int} pointers: *p2 < *p1 lexicographically
 * vars: param_1/param_2 {key,val}
 */
/* Global::std_pair_less_2 @ 004ce3b0 */

uint std_pair_less_2(int *param_1,int *param_2)

{
  if ((*param_2 <= *param_1) &&
     ((*param_2 < *param_1 || (param_1 = (int *)param_1[1], param_2[1] <= (int)param_1)))) {
    return (uint)param_1 & 0xffffff00;
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}




/* [AUDIT] proposed: std::_Tree::ctor_sentinel  (confidence: high)
 * purpose: Allocate a red-black tree head/sentinel node (0x30), self-linking its three child pointers
 * vars: operator_new(0x30); color +0xc=0x0101
 */
/* Global::std_Tree_ctor_sentinel @ 004ce5f0 */

void std_Tree_ctor_sentinel(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x30);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: std::_List_node_alloc_0x48  (confidence: med)
 * purpose: Allocates+links a 0x48-byte list/tree sentinel node via operator_new; throws bad_alloc; class=Zone likely misattributed STL
 * vars: param_1/param_2=prev/next ptrs stored at [0],[1]; self-links when null
 */
/* Global::std_List_node_alloc_0x48 @ 004ce620 */

void std_List_node_alloc_0x48(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x48);
  if (puVar1 != (void *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      param_1 = puVar1;
      param_2 = puVar1;
    }
    *puVar1 = param_1;
    if (puVar1 + 1 != (undefined4 *)0x0) {
      puVar1[1] = param_2;
    }
    return;
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: std::_List_node_alloc_0xc  (confidence: med)
 * purpose: Allocates+links a 0xc-byte list node (operator_new) with prev/next self-link; shared STL list-node ctor
 * vars: widely called sentinel/node allocator; [0]=next [1]=prev
 */
/* Global::std_List_node_alloc_0xc @ 004ce660 */

void std_List_node_alloc_0xc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 != (void *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      param_1 = puVar1;
      param_2 = puVar1;
    }
    *puVar1 = param_1;
    if (puVar1 + 1 != (undefined4 *)0x0) {
      puVar1[1] = param_2;
    }
    return;
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: std::_Tree_node_alloc_0x30  (confidence: med)
 * purpose: Allocates 0x30-byte RB-tree node, copies *param_1 into [0..2] (left/parent/right); bad_alloc on fail
 * vars: puVar1[0..2] init from *param_1 sentinel
 */
/* Global::std_Tree_node_alloc_0x30 @ 004ce6a0 */

undefined4 * __fastcall std_Tree_node_alloc_0x30(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x30);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Rb_tree_destroy_recursive  (confidence: high)
 * purpose: Recursively frees RB-tree map subtree; frees embedded string buffer (>7 uses heap) then node
 * vars: +0xd=nil/leaf flag; [2]=right child; [0xb]=str capacity; [6]=str buffer ptr
 */
/* Global::std_Rb_tree_destroy_recursive @ 004ce720 */

void std_Rb_tree_destroy_recursive(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    std_Rb_tree_destroy_recursive((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[0xb]) {
      operator_delete((void *)param_1[6]);
    }
    param_1[0xb] = 7;
    param_1[10] = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}




/* [AUDIT] proposed: std::_Rb_tree_rotate  (confidence: high)
 * purpose: Red-black tree single rotation (rebalance) relinking parent/child/root pointers
 * vars: this[0]=root holder; +4=leftmost; [0]/[1]/[2]=left/parent/right; +0xd nil flag
 */
/* Global::std_Rb_tree_rotate @ 004ce780 */

void __thiscall std_Rb_tree_rotate(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0xd) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)this + 4)) {
    *(int **)(*(int *)this + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}




/* [AUDIT] proposed: std::map::erase_range  (confidence: high)
 * purpose: Erases [param_2,param_3) from a map/set; full-clear fast path resets sentinel
 * vars: this=tree; sentinel[1]=root; +0xd nil flag; iterates via successor walk
 */
/* Global::std_map_erase_range @ 004d3e10 */

undefined4 * __thiscall std_map_erase_range(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)this;
  local_8 = this;
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    std_Rb_tree_destroy_recursive((int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar3 != param_3) {
    param_2 = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      param_2 = (int *)piVar3[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar2 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
    std_Rb_tree_erase_node(this,&local_8,piVar3);
    piVar3 = param_2;
  }
  *param_1 = piVar3;
  return param_1;
}




/* [AUDIT] proposed: std::_Rb_tree_erase_node  (confidence: high)
 * purpose: Removes one node from RB-tree map<...,string>, rebalances (recolor/rotate), frees node+string buffer
 * vars: +0xd nil; [3]byte=color; +4=leftmost; [6]/[0xb]=str buf/cap; this+4=size
 */
/* Global::std_Rb_tree_erase_node @ 004d3ed0 */

void __thiscall std_Rb_tree_erase_node(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0xd) == '\0') && (piVar7 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar7 + 0xd) == '\0') {
          piVar7[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar7;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar2) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar6 = (int *)piVar2[1];
        if ((int *)*piVar6 == piVar2) {
          *piVar6 = (int)param_2;
        }
        else {
          piVar6[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar2[3];
      *(char *)(piVar2 + 3) = (char)iVar1;
      goto LAB_004d3ffc;
    }
  }
  else {
    piVar7 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar7 + 0xd) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar2) {
    *(int **)(*(int *)this + 4) = piVar7;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  piVar6 = *(int **)this;
  if ((int *)*piVar6 == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      piVar3 = rbtree_min(piVar7);
    }
    *piVar6 = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar7);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_004d3ffc:
  if ((char)piVar2[3] == '\x01') {
    if (piVar7 != *(int **)(*(int *)this + 4)) {
      do {
        piVar6 = piVar5;
        if ((char)piVar7[3] != '\x01') break;
        piVar5 = (int *)*piVar6;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar6[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar6);
            piVar5 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar6[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar6[3];
              *(undefined1 *)(piVar6 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar6);
              *(undefined1 *)(piVar7 + 3) = 1;
              goto LAB_004d412e;
            }
LAB_004d40d0:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            rbtree_rotateLeft(this,piVar6);
            piVar5 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_004d40d0;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar6;
            }
            *(char *)(piVar5 + 3) = (char)piVar6[3];
            *(undefined1 *)(piVar6 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar6);
            *(undefined1 *)(piVar7 + 3) = 1;
            goto LAB_004d412e;
          }
        }
        piVar5 = (int *)piVar6[1];
        piVar7 = piVar6;
      } while (piVar6 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar7 + 3) = 1;
  }
LAB_004d412e:
  if (7 < (uint)piVar2[0xb]) {
    operator_delete((void *)piVar2[6]);
  }
  piVar2[0xb] = 7;
  piVar2[10] = 0;
  *(undefined2 *)(piVar2 + 6) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: std::_Rb_tree_erase_node_variant  (confidence: high)
 * purpose: RB-tree erase+rebalance for map with smaller value; frees node[4] buffer (cap at [9]); mirror of 4d3ed0
 * vars: node[9]=str capacity; node[4]=buffer ptr; [3]=color; +0xd nil flag
 */
/* Global::std_Rb_tree_erase_node_variant @ 004d4180 */

void __thiscall std_Rb_tree_erase_node_variant(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0xd) == '\0') && (piVar7 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar7 + 0xd) == '\0') {
          piVar7[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar7;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)this + 4) == piVar2) {
        *(int **)(*(int *)this + 4) = param_2;
      }
      else {
        piVar6 = (int *)piVar2[1];
        if ((int *)*piVar6 == piVar2) {
          *piVar6 = (int)param_2;
        }
        else {
          piVar6[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[3];
      *(char *)(param_2 + 3) = (char)piVar2[3];
      *(char *)(piVar2 + 3) = (char)iVar1;
      goto LAB_004d42ac;
    }
  }
  else {
    piVar7 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar7 + 0xd) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)this + 4) == piVar2) {
    *(int **)(*(int *)this + 4) = piVar7;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  piVar6 = *(int **)this;
  if ((int *)*piVar6 == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      piVar3 = rbtree_min(piVar7);
    }
    *piVar6 = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      iVar4 = rbtree_max((int)piVar7);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_004d42ac:
  if ((char)piVar2[3] == '\x01') {
    if (piVar7 != *(int **)(*(int *)this + 4)) {
      do {
        piVar6 = piVar5;
        if ((char)piVar7[3] != '\x01') break;
        piVar5 = (int *)*piVar6;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar6[2];
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            std_Rb_tree_rotate(this,(int)piVar6);
            piVar5 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(*piVar5 + 0xc) != '\x01') || (*(char *)(piVar5[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xc) = 1;
                *(undefined1 *)(piVar5 + 3) = 0;
                rbtree_rotateLeft(this,piVar5);
                piVar5 = (int *)piVar6[2];
              }
              *(char *)(piVar5 + 3) = (char)piVar6[3];
              *(undefined1 *)(piVar6 + 3) = 1;
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)piVar6);
              *(undefined1 *)(piVar7 + 3) = 1;
              goto LAB_004d43de;
            }
LAB_004d4380:
            *(undefined1 *)(piVar5 + 3) = 0;
          }
        }
        else {
          if ((char)piVar5[3] == '\0') {
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(piVar6 + 3) = 0;
            rbtree_rotateLeft(this,piVar6);
            piVar5 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            if ((*(char *)(piVar5[2] + 0xc) == '\x01') && (*(char *)(*piVar5 + 0xc) == '\x01'))
            goto LAB_004d4380;
            if (*(char *)(*piVar5 + 0xc) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xc) = 1;
              *(undefined1 *)(piVar5 + 3) = 0;
              std_Rb_tree_rotate(this,(int)piVar5);
              piVar5 = (int *)*piVar6;
            }
            *(char *)(piVar5 + 3) = (char)piVar6[3];
            *(undefined1 *)(piVar6 + 3) = 1;
            *(undefined1 *)(*piVar5 + 0xc) = 1;
            rbtree_rotateLeft(this,piVar6);
            *(undefined1 *)(piVar7 + 3) = 1;
            goto LAB_004d43de;
          }
        }
        piVar5 = (int *)piVar6[1];
        piVar7 = piVar6;
      } while (piVar6 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar7 + 3) = 1;
  }
LAB_004d43de:
  if (7 < (uint)piVar2[9]) {
    operator_delete((void *)piVar2[4]);
  }
  piVar2[9] = 7;
  piVar2[8] = 0;
  *(undefined2 *)(piVar2 + 4) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = param_2;
  return;
}




/* [AUDIT] proposed: WalkPathBehavior::checkPathClear  (confidence: low)
 * purpose: Samples random AABB volume against voxel terrain to test walkability/collision along a box region
 * vars: __alldiv by 0x10000 fixed-pt->cells; voxel lookup this+0xbc grid; puVar9[3]&0x1f=block type
 */
/* Global::WalkPathBehavior_checkPathClear @ 004d4f90 */


void __thiscall WalkPathBehavior_checkPathClear(void *this,uint *param_1,float *param_2,char param_3)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  void *this_00;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  bool bVar20;
  ulonglong uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  ulonglong uVar28;
  uint local_2c [6];
  undefined8 local_14;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = CONCAT44(param_2[1] * 0.5f,*param_2 * 0.5f);
  local_c = param_2[2] * 0.5f;
  iVar15 = 0;
  do {
    uVar21 = ftol2();
    local_2c[iVar15 * 2] = (uint)uVar21;
    local_2c[iVar15 * 2 + 1] = (uint)(uVar21 >> 0x20);
    iVar15 = iVar15 + 1;
  } while (iVar15 < 3);
  bVar19 = param_1[2] < local_2c[2];
  uVar14 = param_1[2] - local_2c[2];
  iVar15 = param_1[3] - local_2c[3];
  bVar20 = param_1[4] < local_2c[4];
  uVar13 = param_1[4] - local_2c[4];
  uVar10 = param_1[5];
  iVar7 = uVar10 - local_2c[5];
  uVar22 = __alldiv(*param_1 - local_2c[0],
                    (param_1[1] - local_2c[1]) - (uint)(*param_1 < local_2c[0]),0x10000,0);
  uVar23 = __alldiv(uVar14,iVar15 - (uint)bVar19,0x10000,0);
  uVar24 = __alldiv(uVar13,iVar7 - (uint)bVar20,0x10000,0);
  iVar15 = 0;
  local_14 = CONCAT44(param_2[1] * 0.5f,*param_2 * 0.5f);
  local_c = param_2[2] * 0.5f;
  do {
    uVar21 = ftol2();
    local_2c[iVar15 * 2] = (uint)uVar21;
    local_2c[iVar15 * 2 + 1] = (uint)(uVar21 >> 0x20);
    iVar15 = iVar15 + 1;
  } while (iVar15 < 3);
  uVar13 = param_1[2];
  uVar14 = param_1[3];
  uVar16 = param_1[4];
  uVar25 = __alldiv(*param_1 + local_2c[0],
                    param_1[1] + local_2c[1] + (uint)CARRY4(*param_1,local_2c[0]),0x10000,0);
  uVar26 = __alldiv(uVar13 + local_2c[2],uVar14 + local_2c[3] + (uint)CARRY4(uVar13,local_2c[2]),
                    0x10000,0);
  uVar27 = __alldiv(uVar16 + local_2c[4],uVar10 + local_2c[5] + (uint)CARRY4(uVar16,local_2c[4]),
                    0x10000,0);
  for (uVar10 = (uint)uVar22; uVar13 = (uint)uVar23, (int)uVar10 <= (int)uVar25; uVar10 = uVar10 + 1
      ) {
    for (; iVar15 = (int)uVar24, (int)uVar13 <= (int)uVar26; uVar13 = uVar13 + 1) {
      for (; iVar15 <= (int)uVar27; iVar15 = iVar15 + 1) {
        if ((((((int)uVar10 <= (int)(uint)uVar22) || ((int)uVar25 <= (int)uVar10)) ||
             ((int)uVar13 <= (int)(uint)uVar23)) ||
            (((int)uVar26 <= (int)uVar13 || (iVar15 <= (int)uVar24)))) || ((int)uVar27 <= iVar15)) {
          if ((((int)uVar10 < 0) || ((int)uVar13 < 0)) ||
             ((0xffffff < (int)uVar10 || (0xffffff < (int)uVar13)))) {
LAB_004d52f7:
            puVar9 = &DAT_00584248;
          }
          else {
            iVar7 = ((int)uVar13 >> 0x1f & 0xffU) + uVar13;
            uVar16 = iVar7 >> 8;
            iVar8 = ((int)uVar10 >> 0x1f & 0xffU) + uVar10;
            uVar14 = iVar8 >> 8;
            if (((((int)uVar14 < 0) || ((int)uVar16 < 0)) || (0xffff < (int)uVar14)) ||
               (0xffff < (int)uVar16)) goto LAB_004d52f7;
            iVar7 = (int)(uVar16 + (iVar7 >> 0x1f & 0x3fU)) >> 6;
            iVar8 = (int)(uVar14 + (iVar8 >> 0x1f & 0x3fU)) >> 6;
            if (((iVar8 < 0) || (iVar7 < 0)) ||
               ((0x3ff < iVar8 ||
                ((0x3ff < iVar7 ||
                 (iVar7 = *(int *)((int)this + (iVar8 * 0x400 + iVar7) * 4 + 0xbc), iVar7 == 0))))))
            goto LAB_004d52f7;
            uVar14 = uVar14 & 0x8000003f;
            if ((int)uVar14 < 0) {
              uVar14 = (uVar14 - 1 | 0xffffffc0) + 1;
            }
            uVar16 = uVar16 & 0x8000003f;
            if ((int)uVar16 < 0) {
              uVar16 = (uVar16 - 1 | 0xffffffc0) + 1;
            }
            iVar7 = *(int *)(iVar7 + 0x10018 + (uVar14 * 0x40 + uVar16) * 4);
            if (iVar7 == 0) goto LAB_004d52f7;
            uVar14 = uVar13 & 0x800000ff;
            if ((int)uVar14 < 0) {
              uVar14 = (uVar14 - 1 | 0xffffff00) + 1;
            }
            uVar16 = uVar10 & 0x800000ff;
            if ((int)uVar16 < 0) {
              uVar16 = (uVar16 - 1 | 0xffffff00) + 1;
            }
            this_00 = (void *)((uVar14 * 0x100 + uVar16) * 0x20 + *(int *)(iVar7 + 0xa8));
            if ((this_00 == (void *)0x0) || (iVar7 = *(int *)((int)this_00 + 0x10), iVar15 < iVar7))
            goto LAB_004d52f7;
            if (iVar15 < *(int *)((int)this_00 + 0x1c) + iVar7) {
              puVar9 = Column_getBlockChecked(this_00,iVar15 - iVar7);
              if ((((puVar9[3] & 0x1f) == 0) && (iVar15 < 1)) && ((puVar9[3] & 0x40) == 0)) {
                puVar9 = &DAT_00584240;
              }
            }
            else {
              puVar9 = &DAT_00584240;
              if (0 < iVar15) {
                puVar9 = &DAT_00584244;
              }
            }
          }
          if (((puVar9[3] & 0x1f) != 0) && ((puVar9[3] & 0x1f) != 2)) goto LAB_004d54bb;
        }
      }
    }
  }
  if (param_3 != '\0') {
    uVar22 = __alldiv(*param_1,param_1[1],0x10000,0);
    iVar15 = (int)(((int)uVar22 >> 0x1f & 7U) + (int)uVar22) >> 3;
    uVar22 = __alldiv(param_1[2],param_1[3],0x10000,0);
    uVar10 = iVar15 - 1;
    iVar15 = iVar15 + 1;
    iVar7 = (int)((int)uVar22 + ((int)uVar22 >> 0x1f & 7U)) >> 3;
    if ((int)uVar10 <= iVar15) {
      uVar13 = iVar7 - 1;
      uVar14 = uVar13;
      do {
        for (; (int)uVar14 <= iVar7 + 1; uVar14 = uVar14 + 1) {
          if (((-1 < (int)uVar10) && (-1 < (int)uVar14)) &&
             (((int)uVar10 < 0x200000 &&
              (((int)uVar14 < 0x200000 &&
               (iVar8 = Region_getChunkCell(this,(int)(uVar10 + ((int)uVar10 >> 0x1f & 0x1fU)) >> 5,
                                     (int)(uVar14 + ((int)uVar14 >> 0x1f & 0x1fU)) >> 5), iVar8 != 0
               )))))) {
            uVar16 = uVar14 & 0x8000001f;
            if ((int)uVar16 < 0) {
              uVar16 = (uVar16 - 1 | 0xffffffe0) + 1;
            }
            uVar11 = uVar10 & 0x8000001f;
            if ((int)uVar11 < 0) {
              uVar11 = (uVar11 - 1 | 0xffffffe0) + 1;
            }
            piVar2 = (int *)(*(int *)(iVar8 + 0xac) + (uVar16 * 0x20 + uVar11) * 8);
            if (piVar2 != (int *)0x0) {
              puVar3 = (undefined4 *)*piVar2;
              for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4)
              {
                piVar2 = (int *)puVar4[2];
                iVar8 = *piVar2;
                if ((((iVar8 != 7) && (iVar8 != 6)) && (iVar8 != 9)) &&
                   ((((iVar8 != 1 && (iVar8 != 8)) &&
                     ((iVar8 != 2 && ((iVar8 != 3 && (iVar8 != 5)))))) ||
                    ((char)piVar2[0xc] != '\0')))) {
                  local_c = (float)piVar2[0xb];
                  local_14 = *(undefined8 *)(piVar2 + 9);
                  uVar21 = ftol2();
                  uVar28 = ftol2();
                  iVar18 = (int)(uVar28 >> 0x20);
                  uVar11 = (uint)uVar28;
                  uVar16 = piVar2[2];
                  iVar17 = (piVar2[3] - (int)(uVar21 >> 0x20)) - (uint)(uVar16 < (uint)uVar21);
                  iVar12 = iVar18 + param_1[1] + (uint)CARRY4(uVar11,*param_1);
                  iVar8 = puVar4[2];
                  if ((iVar17 <= iVar12) &&
                     (((iVar17 < iVar12 || (uVar16 - (uint)uVar21 <= uVar11 + *param_1)) &&
                      (CONCAT44((param_1[1] - iVar18) - (uint)(*param_1 < uVar11),*param_1 - uVar11)
                       < (longlong)(uVar21 + *(longlong *)(piVar2 + 2)))))) {
                    uVar21 = ftol2();
                    uVar28 = ftol2();
                    iVar12 = (int)(uVar28 >> 0x20);
                    uVar11 = (uint)uVar28;
                    puVar1 = (uint *)(iVar8 + 0x10);
                    uVar16 = *puVar1;
                    iVar18 = (*(int *)(iVar8 + 0x14) - (int)(uVar21 >> 0x20)) -
                             (uint)(uVar16 < (uint)uVar21);
                    iVar8 = iVar12 + param_1[3] + (uint)CARRY4(uVar11,param_1[2]);
                    if ((iVar18 <= iVar8) &&
                       (((iVar18 < iVar8 || (uVar16 - (uint)uVar21 <= uVar11 + param_1[2])) &&
                        (CONCAT44((param_1[3] - iVar12) - (uint)(param_1[2] < uVar11),
                                  param_1[2] - uVar11) < (longlong)(uVar21 + *(longlong *)puVar1))))
                       ) {
                      uVar16 = param_1[4];
                      puVar1 = (uint *)(puVar4[2] + 0x18);
                      uVar11 = *puVar1;
                      iVar8 = *(int *)(puVar4[2] + 0x1c);
                      lVar6 = *(longlong *)puVar1;
                      uVar21 = ftol2();
                      uVar5 = param_1[5];
                      iVar12 = (int)(uVar21 >> 0x20) + uVar5 + (uint)CARRY4((uint)uVar21,uVar16);
                      if ((iVar8 <= iVar12) &&
                         ((iVar8 < iVar12 || (uVar11 <= (uint)uVar21 + uVar16)))) {
                        uVar21 = ftol2();
                        uVar28 = ftol2();
                        if (CONCAT44((uVar5 - (int)(uVar21 >> 0x20)) - (uint)(uVar16 < (uint)uVar21)
                                     ,uVar16 - (uint)uVar21) < (longlong)(uVar28 + lVar6)) {
LAB_004d54bb:
                          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                          return;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        uVar10 = uVar10 + 1;
        uVar14 = uVar13;
      } while ((int)uVar10 <= iVar15);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::_Tree_node_construct_seh  (confidence: med)
 * purpose: Allocates tree node (std_Tree_node_alloc_0x1c), zeroes color/flag, in-place copy-constructs vector at node+4 (SEH guarded)
 * vars: node+3=color/nil bytes; node+4=embedded int-vector; std_vector_copyConstruct=vector copy
 */
/* Global::std_Tree_node_construct_seh @ 004d9ac0 */

undefined4 * __thiscall std_Tree_node_construct_seh(void *this,int *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554ca1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = std_Tree_node_alloc_0x1c(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  local_8 = 1;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    std_vector_copyConstruct(puVar1 + 4,param_1);
  }
  ExceptionList = local_10;
  return puVar1;
}




/* [AUDIT] proposed: std::list::insertNode3  (confidence: med)
 * purpose: Inserts list node (List_allocNode0x14) and writes 3-int payload (xyz) at node+8..+0x10
 * vars: param_3=xyz coords; returns node
 */
/* Global::std_list_insertNode3 @ 004d9b70 */

int std_list_insertNode3(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = List_allocNode0x14(param_1,param_2);
  if ((undefined4 *)(iVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)(iVar1 + 8) = *param_3;
    *(undefined4 *)(iVar1 + 0xc) = param_3[1];
    *(undefined4 *)(iVar1 + 0x10) = param_3[2];
  }
  return iVar1;
}




/* [AUDIT] proposed: std::_Tree_node_move_construct  (confidence: med)
 * purpose: Allocates tree node (std_Tree_node_alloc_0x34), zeroes color, move-constructs 9-field value at node+4 via Path_moveConstruct
 * vars: node+4=moved value object
 */
/* Global::std_Tree_node_move_construct @ 004d9bb0 */

undefined4 * __thiscall std_Tree_node_move_construct(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_Tree_node_alloc_0x34(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    Path_moveConstruct(puVar1 + 4,param_1);
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Rb_tree_insert_rebalance_A  (confidence: high)
 * purpose: RB-tree insert fixup (recolor/rotate) for map/set variant; frees new node buffer+throws on overflow
 * vars: this+4=size (cap 0x4ec4ec2); +0xc=color byte; +0xd nil; param_5=new node; param_2=insert side
 */
/* Global::std_Rb_tree_insert_rebalance_A @ 004d9de0 */

void __thiscall
std_Rb_tree_insert_rebalance_A(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x4ec4ec2 < *(uint *)((int)this + 4)) {
    if ((void *)param_5[4] != (void *)0x0) {
      operator_delete((void *)param_5[4]);
      param_5[4] = 0;
      param_5[5] = 0;
      param_5[6] = 0;
    }
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_004d9fea;
      }
LAB_004d9f41:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004d9f41;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_004d9fea:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_Rb_tree_insert_rebalance_B  (confidence: high)
 * purpose: RB-tree insert fixup mirror (cap 0x9249247); allocs value via std_Tree_node_construct_seh then rebalances
 * vars: param_2=left/right side; [0xc]color; +0xd nil; param_4=value source
 */
/* Global::std_Rb_tree_insert_rebalance_B @ 004da010 */

void __thiscall
std_Rb_tree_insert_rebalance_B(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (0x9249247 < *(uint *)((int)this + 4)) {
    std::_Xlength_error("map/set<T> too long");
  }
  piVar3 = std_Tree_node_construct_seh(this,param_4);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  piVar3[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = piVar3;
    **(undefined4 **)this = piVar3;
    iVar4 = *(int *)this;
  }
  else {
    if (param_2 != '\0') {
      *param_3 = piVar3;
      if (param_3 == (undefined4 *)**(int **)this) {
        **(int **)this = (int)piVar3;
      }
      goto LAB_004da06e;
    }
    param_3[2] = piVar3;
    iVar4 = *(int *)this;
    if (param_3 != *(undefined4 **)(iVar4 + 8)) goto LAB_004da06e;
  }
  *(int **)(iVar4 + 8) = piVar3;
LAB_004da06e:
  cVar1 = *(char *)(piVar3[1] + 0xc);
  piVar5 = piVar3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = piVar3;
      return;
    }
    piVar7 = (int *)piVar5[1];
    piVar6 = *(int **)piVar7[1];
    if (piVar7 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar7[1])[2];
      if ((char)piVar6[3] != '\0') {
        if (piVar5 == (int *)piVar7[2]) {
          piVar5 = (int *)piVar7[2];
          piVar7[2] = *piVar5;
          if (*(char *)(*piVar5 + 0xd) == '\0') {
            *(int **)(*piVar5 + 4) = piVar7;
          }
          piVar5[1] = piVar7[1];
          if (piVar7 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar5;
          }
          else {
            piVar6 = (int *)piVar7[1];
            if (piVar7 == (int *)*piVar6) {
              *piVar6 = (int)piVar5;
            }
            else {
              piVar6[2] = (int)piVar5;
            }
          }
          *piVar5 = (int)piVar7;
          piVar7[1] = (int)piVar5;
          piVar5 = piVar7;
        }
        *(undefined1 *)(piVar5[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
        piVar7 = *(int **)(piVar5[1] + 4);
        piVar6 = (int *)*piVar7;
        *piVar7 = piVar6[2];
        if (*(char *)(piVar6[2] + 0xd) == '\0') {
          *(int **)(piVar6[2] + 4) = piVar7;
        }
        piVar6[1] = piVar7[1];
        if (piVar7 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar6;
          piVar6[2] = (int)piVar7;
        }
        else {
          piVar2 = (int *)piVar7[1];
          if (piVar7 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar6;
            piVar6[2] = (int)piVar7;
          }
          else {
            *piVar2 = (int)piVar6;
            piVar6[2] = (int)piVar7;
          }
        }
        goto LAB_004da1ea;
      }
LAB_004da141:
      *(undefined1 *)(piVar7 + 3) = 1;
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      piVar5 = *(int **)(piVar5[1] + 4);
    }
    else {
      if ((char)piVar6[3] == '\0') goto LAB_004da141;
      if (piVar5 == (int *)*piVar7) {
        iVar4 = *piVar7;
        *piVar7 = *(int *)(iVar4 + 8);
        if (*(char *)(*(int *)(iVar4 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar4 + 8) + 4) = piVar7;
        }
        *(int *)(iVar4 + 4) = piVar7[1];
        if (piVar7 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar4;
        }
        else {
          piVar5 = (int *)piVar7[1];
          if (piVar7 == (int *)piVar5[2]) {
            piVar5[2] = iVar4;
          }
          else {
            *piVar5 = iVar4;
          }
        }
        *(int **)(iVar4 + 8) = piVar7;
        piVar7[1] = iVar4;
        piVar5 = piVar7;
      }
      *(undefined1 *)(piVar5[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      piVar7 = *(int **)(piVar5[1] + 4);
      piVar6 = (int *)piVar7[2];
      piVar7[2] = *piVar6;
      if (*(char *)(*piVar6 + 0xd) == '\0') {
        *(int **)(*piVar6 + 4) = piVar7;
      }
      piVar6[1] = piVar7[1];
      if (piVar7 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar6;
      }
      else {
        piVar2 = (int *)piVar7[1];
        if (piVar7 == (int *)*piVar2) {
          *piVar2 = (int)piVar6;
        }
        else {
          piVar2[2] = (int)piVar6;
        }
      }
      *piVar6 = (int)piVar7;
LAB_004da1ea:
      piVar7[1] = (int)piVar6;
    }
    cVar1 = *(char *)(piVar5[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::map::insert_hint  (confidence: high)
 * purpose: Hinted insert into map<vector,...>: validates hint position via range-compare then rebalance or full insert
 * vars: param_2=hint iter; param_3=key range; std_lexicographical_less=lexicographic less; SEH frame
 */
/* Global::std_map_insert_hint_4da210 @ 004da210 */

undefined4 * __thiscall
std_map_insert_hint_4da210(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uStack_30;
  undefined4 local_20;
  int *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00554d00;
  local_10 = ExceptionList;
  uStack_30 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = this;
  if (*(int *)((int)this + 4) == 0) {
    local_14 = (undefined1 *)&uStack_30;
    std_Rb_tree_insert_rebalance_A(this,param_1,'\x01',*(undefined4 **)this,param_3,param_4);
    ExceptionList = local_10;
    return param_1;
  }
  piVar1 = *(int **)this;
  if (param_2 == (int *)*piVar1) {
    local_14 = (undefined1 *)&uStack_30;
    uVar3 = std_lexicographical_less((int *)*param_3,(int *)param_3[1],(int *)param_2[4],(int *)param_2[5]);
    if ((char)uVar3 != '\0') {
      std_Rb_tree_insert_rebalance_A(this,param_1,'\x01',param_2,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    puVar4 = (undefined4 *)piVar1[2];
    local_14 = (undefined1 *)&uStack_30;
    uVar3 = std_lexicographical_less((int *)puVar4[4],(int *)puVar4[5],(int *)*param_3,(int *)param_3[1]);
    if ((char)uVar3 != '\0') {
      std_Rb_tree_insert_rebalance_A(this,param_1,'\0',puVar4,param_3,param_4);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    uVar3 = std_lexicographical_less((int *)*param_3,(int *)param_3[1],(int *)param_2[4],(int *)param_2[5]);
    if ((char)uVar3 != '\0') {
      local_1c = param_2;
      std_Rb_tree_increment((int *)&local_1c);
      piVar2 = local_1c;
      uVar3 = std_lexicographical_less((int *)local_1c[4],(int *)local_1c[5],(int *)*param_3,(int *)param_3[1]);
      if ((char)uVar3 != '\0') {
        if (*(char *)(piVar2[2] + 0xd) == '\0') {
          std_Rb_tree_insert_rebalance_A(local_18,param_1,'\x01',param_2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_Rb_tree_insert_rebalance_A(local_18,param_1,'\0',piVar2,param_3,param_4);
        ExceptionList = local_10;
        return param_1;
      }
    }
    uVar3 = std_lexicographical_less((int *)param_2[4],(int *)param_2[5],(int *)*param_3,(int *)param_3[1]);
    if ((char)uVar3 != '\0') {
      local_1c = param_2;
      RBTree_iterIncrement((int *)&local_1c);
      piVar2 = local_1c;
      if ((local_1c == piVar1) ||
         (uVar3 = std_lexicographical_less((int *)*param_3,(int *)param_3[1],(int *)local_1c[4],
                               (int *)local_1c[5]), (char)uVar3 != '\0')) {
        if (*(char *)(param_2[2] + 0xd) == '\0') {
          std_Rb_tree_insert_rebalance_A(local_18,param_1,'\x01',piVar2,param_3,param_4);
          ExceptionList = local_10;
          return param_1;
        }
        std_Rb_tree_insert_rebalance_A(local_18,param_1,'\0',param_2,param_3,param_4);
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
  local_8 = 0xffffffff;
  puVar4 = (undefined4 *)std_map_insert_unique(local_18,&local_20,'\0',param_3,param_4);
  *param_1 = *puVar4;
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std::map::insert_unique  (confidence: high)
 * purpose: Locates insert position by walking tree with range comparisons, inserts or discards duplicate node
 * vars: local_1c=less-than result; param_2=orient; param_4=node to insert/free; std_lexicographical_less=compare
 */
/* Global::std_map_insert_unique @ 004da4a0 */

void __thiscall
std_map_insert_unique(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  char local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00554d20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)this;
  local_8 = 0;
  local_1c = '\x01';
  piVar8 = piVar1;
  if (*(char *)(piVar1[1] + 0xd) == '\0') {
    piVar2 = (int *)param_3[1];
    piVar5 = (int *)piVar1[1];
    do {
      piVar8 = piVar5;
      piVar5 = (int *)piVar8[5];
      if (param_2 == '\0') {
        piVar7 = (int *)piVar8[4];
        for (piVar6 = (int *)*param_3; piVar6 != piVar2; piVar6 = piVar6 + 1) {
          if (piVar7 == piVar5) {
            if (piVar6 != piVar2) goto LAB_004da578;
            break;
          }
          if (*piVar6 < *piVar7) goto LAB_004da574;
          if (*piVar7 < *piVar6) goto LAB_004da578;
          piVar7 = piVar7 + 1;
        }
        if (piVar7 == piVar5) {
LAB_004da578:
          local_1c = '\0';
        }
        else {
LAB_004da574:
          local_1c = '\x01';
        }
      }
      else {
        piVar6 = (int *)*param_3;
        for (piVar7 = (int *)piVar8[4]; piVar7 != piVar5; piVar7 = piVar7 + 1) {
          if (piVar6 == piVar2) {
            if (piVar7 != piVar5) goto LAB_004da540;
            break;
          }
          if (*piVar7 < *piVar6) goto LAB_004da537;
          if (*piVar6 < *piVar7) goto LAB_004da540;
          piVar6 = piVar6 + 1;
        }
        if (piVar6 == piVar2) {
LAB_004da540:
          local_1c = '\x01';
        }
        else {
LAB_004da537:
          local_1c = '\0';
        }
      }
      if (local_1c == '\0') {
        piVar5 = (int *)piVar8[2];
      }
      else {
        piVar5 = (int *)*piVar8;
      }
    } while (*(char *)((int)piVar5 + 0xd) == '\0');
  }
  _param_2 = piVar8;
  if (local_1c != '\0') {
    if (piVar8 == (int *)*piVar1) {
      local_1c = '\x01';
      puVar3 = param_3;
      goto LAB_004da5b7;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  puVar3 = param_3;
  piVar1 = _param_2;
  uVar4 = std_lexicographical_less((int *)_param_2[4],(int *)_param_2[5],(int *)*param_3,(int *)param_3[1]);
  piVar2 = param_4;
  if ((char)uVar4 == '\0') {
    if ((void *)param_4[4] != (void *)0x0) {
      operator_delete((void *)param_4[4]);
      piVar2[4] = 0;
      piVar2[5] = 0;
      piVar2[6] = 0;
    }
    operator_delete(piVar2);
    *param_1 = piVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
LAB_004da5b7:
  puVar3 = (undefined4 *)std_Rb_tree_insert_rebalance_A(this,(undefined4 *)&param_2,local_1c,piVar8,puVar3,param_4);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::map::insert_scalarKey  (confidence: med)
 * purpose: Lower-bound walk on tree keyed by single uint (offset+4), inserts unique or returns existing
 * vars: param_3=key ptr; puVar6[4]=node key; local_18=<; std_Tree_Rebalance_buynode=insert node
 */
/* Global::std_map_insert_scalarKey @ 004da680 */

undefined4 * __thiscall
std_map_insert_scalarKey(void *this,undefined4 *param_1,char param_2,uint *param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint **ppuVar4;
  undefined4 *puVar5;
  uint *puVar6;
  bool local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar2 = param_3;
  puStack_c = &LAB_00554d40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(uint **)this;
  local_8 = 0;
  local_18 = true;
  puVar6 = puVar1;
  if (*(char *)((int)puVar1[1] + 0xd) == '\0') {
    puVar3 = (uint *)puVar1[1];
    do {
      puVar6 = puVar3;
      if (param_2 == '\0') {
        local_18 = *param_3 < puVar6[4];
      }
      else {
        local_18 = *param_3 <= puVar6[4];
      }
      if (local_18 == false) {
        puVar3 = (uint *)puVar6[2];
      }
      else {
        puVar3 = (uint *)*puVar6;
      }
    } while (*(char *)((int)puVar3 + 0xd) == '\0');
  }
  _param_2 = puVar6;
  if (local_18 != false) {
    if (puVar6 == (uint *)*puVar1) {
      ppuVar4 = (uint **)&param_2;
      local_18 = true;
      goto LAB_004da719;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  if (*puVar2 <= _param_2[4]) {
    *param_1 = _param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return param_1;
  }
  ppuVar4 = &param_3;
LAB_004da719:
  puVar5 = (undefined4 *)std_Tree_Rebalance_buynode(this,ppuVar4,local_18,puVar6,puVar2);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: std::map::insert_vectorKey  (confidence: high)
 * purpose: Insert unique into map keyed by int-vector: walk with lexicographic compare then std_Rb_tree_insert_rebalance_B rebalance
 * vars: param_3=key range; local_1c=less; std_lexicographical_less=compare; node[4]/[5]=key begin/end
 */
/* Global::std_map_insert_vectorKey @ 004da790 */

void __thiscall
std_map_insert_vectorKey(void *this,undefined4 *param_1,char param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  char local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00554d60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar9 = *(int **)this;
  local_8 = 0;
  local_1c = '\x01';
  piVar8 = piVar9;
  if (*(char *)(piVar9[1] + 0xd) == '\0') {
    piVar1 = (int *)param_3[1];
    piVar5 = (int *)piVar9[1];
    do {
      piVar8 = piVar5;
      piVar5 = (int *)piVar8[5];
      if (param_2 == '\0') {
        piVar7 = (int *)piVar8[4];
        for (piVar6 = (int *)*param_3; piVar6 != piVar1; piVar6 = piVar6 + 1) {
          if (piVar7 == piVar5) {
            if (piVar6 != piVar1) goto LAB_004da868;
            break;
          }
          if (*piVar6 < *piVar7) goto LAB_004da864;
          if (*piVar7 < *piVar6) goto LAB_004da868;
          piVar7 = piVar7 + 1;
        }
        if (piVar7 == piVar5) {
LAB_004da868:
          local_1c = '\0';
        }
        else {
LAB_004da864:
          local_1c = '\x01';
        }
      }
      else {
        piVar6 = (int *)*param_3;
        for (piVar7 = (int *)piVar8[4]; piVar7 != piVar5; piVar7 = piVar7 + 1) {
          if (piVar6 == piVar1) {
            if (piVar7 != piVar5) goto LAB_004da830;
            break;
          }
          if (*piVar7 < *piVar6) goto LAB_004da827;
          if (*piVar6 < *piVar7) goto LAB_004da830;
          piVar6 = piVar6 + 1;
        }
        if (piVar6 == piVar1) {
LAB_004da830:
          local_1c = '\x01';
        }
        else {
LAB_004da827:
          local_1c = '\0';
        }
      }
      if (local_1c == '\0') {
        piVar5 = (int *)piVar8[2];
      }
      else {
        piVar5 = (int *)*piVar8;
      }
    } while (*(char *)((int)piVar5 + 0xd) == '\0');
  }
  _param_2 = piVar8;
  if (local_1c != '\0') {
    if (piVar8 == (int *)*piVar9) {
      ppiVar2 = (int **)&param_2;
      local_1c = '\x01';
      piVar9 = param_3;
      goto LAB_004da8ac;
    }
    std_Rb_tree_increment((int *)&param_2);
  }
  piVar9 = param_3;
  piVar1 = _param_2;
  uVar4 = std_lexicographical_less((int *)_param_2[4],(int *)_param_2[5],(int *)*param_3,(int *)param_3[1]);
  if ((char)uVar4 == '\0') {
    *param_1 = piVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  ppiVar2 = &param_3;
LAB_004da8ac:
  puVar3 = (undefined4 *)std_Rb_tree_insert_rebalance_B(this,ppiVar2,local_1c,piVar8,piVar9);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: std::lexicographical_less  (confidence: high)
 * purpose: Lexicographic less-than compare of two int ranges [p1,p2) vs [p3,p4); returns tri-state in low byte
 * vars: returns 1 if first<second; 0 otherwise; elementwise *param compare
 */
/* Global::std_lexicographical_less @ 004da930 */

undefined4 __cdecl std_lexicographical_less(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint3 uVar1;
  
  do {
    if (param_1 == param_2) {
LAB_004da974:
      if (param_3 == param_4) {
        return 0;
      }
      return 1;
    }
    if (param_3 == param_4) {
      if (param_1 != param_2) {
        return 0;
      }
      goto LAB_004da974;
    }
    uVar1 = (uint3)((uint)param_3 >> 8);
    if (*param_1 < *param_3) {
      return CONCAT31(uVar1,1);
    }
    if (*param_3 < *param_1) {
      return (uint)uVar1 << 8;
    }
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  } while( true );
}




/* [AUDIT] proposed: std::copy_ints  (confidence: high)
 * purpose: Copies ints from [param_1,param_2) to param_3, guarding null dest
 * vars: trivial range copy
 */
/* Global::std_copy_ints @ 004da9c0 */

void __cdecl std_copy_ints(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
    }
    param_3 = param_3 + 1;
  }
  return;
}




/* [AUDIT] proposed: std::vector<int>::copyConstruct  (confidence: med)
 * purpose: Copy-constructs an int vector from source [*param_1,param_1[1]); reserves then copies (SEH)
 * vars: this=vec(ptr,size,cap); std_vector_reserve_4dae20=reserve; std_copy_ints=copy
 */
/* Global::std_vector_copyConstruct @ 004daa80 */

undefined4 * __thiscall std_vector_copyConstruct(void *this,int *param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554d80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = std_vector_reserve_4dae20(this,param_1[1] - *param_1 >> 2);
  if ((char)uVar1 != '\0') {
    local_8 = 0;
    uVar1 = std_copy_ints((undefined4 *)*param_1,(undefined4 *)param_1[1],*(undefined4 **)this);
    *(undefined4 *)((int)this + 4) = uVar1;
  }
  ExceptionList = local_10;
  return this;
}




/* [AUDIT] proposed: std::map::insertOrAssign  (confidence: high)
 * purpose: Insert-or-update entry keyed by int-vector: find via lower_bound, if new build vector+node and insert (SEH)
 * vars: std_map_lower_bound_vecKey=lower_bound; std_Tree_node_move_construct=make node; std_map_insert_hint_4da210=insert; local_38=temp vector
 */
/* Global::std_map_insertOrAssign @ 004daca0 */

void __thiscall std_map_insertOrAssign(void *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_3c;
  void *local_38 [9];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554da8;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = std_map_lower_bound_vecKey(this,param_1);
  if (piVar1 != *(int **)this) {
    uVar2 = std_lexicographical_less((int *)*param_1,(int *)param_1[1],(int *)piVar1[4],(int *)piVar1[5]);
    if ((char)uVar2 == '\0') goto LAB_004dad56;
  }
  std_vector_copyConstruct(local_38,param_1);
  local_8 = 0;
  piVar3 = std_Tree_node_move_construct(this,local_38);
  std_map_insert_hint_4da210(this,&local_3c,piVar1,piVar3 + 4,piVar3);
  if (local_38[0] != (void *)0x0) {
    operator_delete(local_38[0]);
  }
LAB_004dad56:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std::_Rb_tree_increment  (confidence: high)
 * purpose: In-order successor (iterator++) for RB-tree map/set node
 * vars: +0xd nil flag; [0]left [1]parent [2]right
 */
/* Global::std_Rb_tree_increment @ 004dad80 */

int * __fastcall std_Rb_tree_increment(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar2 + 0xd) != '\0') {
    *param_1 = puVar2[2];
    return param_1;
  }
  piVar5 = (int *)*puVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    iVar3 = piVar5[2];
    if (*(char *)(piVar5[2] + 0xd) == '\0') {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (*(char *)(iVar3 + 0xd) == '\0');
      *param_1 = iVar4;
      return param_1;
    }
  }
  else {
    piVar5 = (int *)puVar2[1];
    cVar1 = *(char *)((int)piVar5 + 0xd);
    while ((cVar1 == '\0' && (*param_1 == *piVar5))) {
      *param_1 = (int)piVar5;
      piVar5 = (int *)piVar5[1];
      cVar1 = *(char *)((int)piVar5 + 0xd);
    }
    if (*(char *)(*param_1 + 0xd) != '\0') {
      return param_1;
    }
  }
  *param_1 = (int)piVar5;
  return param_1;
}




/* [AUDIT] proposed: std::vector<int>::reserve  (confidence: high)
 * purpose: Allocates param_1*4 bytes for int vector, sets begin/end/cap; throws length/bad_alloc
 * vars: this=(begin,end,cap); cap 0x3fffffff
 */
/* Global::std_vector_reserve_4dae20 @ 004dae20 */

undefined4 __thiscall std_vector_reserve_4dae20(void *this,uint param_1)

{
  void *pvVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x3fffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
  pvVar1 = operator_new(param_1 * 4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    *(void **)((int)this + 4) = pvVar1;
    pvVar1 = (void *)((int)pvVar1 + param_1 * 4);
    *(void **)((int)this + 8) = pvVar1;
    return CONCAT31((int3)((uint)pvVar1 >> 8),1);
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: std::_Tree_node_alloc_0x14  (confidence: med)
 * purpose: Allocates 0x14-byte tree/list node, inits [0..2] from *param_1 sentinel; bad_alloc on fail
 * vars: node small variant
 */
/* Global::std_Tree_node_alloc_0x14 @ 004dae90 */

undefined4 * __fastcall std_Tree_node_alloc_0x14(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Tree_node_alloc_0x34  (confidence: med)
 * purpose: Allocates 0x34-byte tree node, inits [0..2]=sentinel; bad_alloc on fail
 * vars: larger node for vector-keyed map
 */
/* Global::std_Tree_node_alloc_0x34 @ 004daed0 */

undefined4 * __fastcall std_Tree_node_alloc_0x34(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x34);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std::map::lower_bound_vecKey  (confidence: high)
 * purpose: Lower-bound search in map keyed by int-vector using lexicographic compare; returns node or header
 * vars: local_8=candidate; node[4]/[5]=key range; param_1=search key range
 */
/* Global::std_map_lower_bound_vecKey @ 004daf50 */

undefined4 * __thiscall std_map_lower_bound_vecKey(void *this,undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)this;
  if (*(char *)((int)local_8[1] + 0xd) == '\0') {
    puVar3 = (undefined4 *)local_8[1];
    do {
      piVar2 = (int *)*param_1;
      for (piVar1 = (int *)puVar3[4]; piVar1 != (int *)puVar3[5]; piVar1 = piVar1 + 1) {
        if (piVar2 == (int *)param_1[1]) {
          if (piVar1 != (int *)puVar3[5]) goto LAB_004dafa8;
          break;
        }
        if (*piVar1 < *piVar2) goto LAB_004dafc6;
        if (*piVar2 < *piVar1) goto LAB_004dafa8;
        piVar2 = piVar2 + 1;
      }
      if (piVar2 == (int *)param_1[1]) {
LAB_004dafa8:
        puVar4 = (undefined4 *)*puVar3;
        local_8 = puVar3;
      }
      else {
LAB_004dafc6:
        puVar4 = (undefined4 *)puVar3[2];
      }
      puVar3 = puVar4;
    } while (*(char *)((int)puVar4 + 0xd) == '\0');
  }
  return local_8;
}




/* [AUDIT] proposed: std::vector::push_back_int  (confidence: high)
 * purpose: Appends an int to a vector, growing capacity if full; handles push of element aliasing own storage
 * vars: this=(begin,end,cap); vecInt_reserveGrow=grow; param_1 may point into vector
 */
/* Global::std_vector_push_back_int @ 004f2be0 */

void __thiscall std_vector_push_back_int(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar1) && (puVar2 = *(undefined4 **)this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      vecInt_reserveGrow(this,1);
    }
    if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
      **(undefined4 **)((int)this + 4) =
           *(undefined4 *)(*(int *)this + ((int)param_1 - (int)puVar2 >> 2) * 4);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
      return;
    }
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      vecInt_reserveGrow(this,1);
    }
    if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
      **(undefined4 **)((int)this + 4) = *param_1;
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}




/* [AUDIT] proposed: std::_Rb_tree_insert_rebalance_C  (confidence: high)
 * purpose: RB-tree insert fixup (recolor/rotate) for map; frees node+throws on overflow (cap 0x7fffffd)
 * vars: this+4=size; +0xc color; +0xd nil; param_5=new node
 */
/* Global::std_Rb_tree_insert_rebalance_C @ 004f3e70 */

void __thiscall
std_Rb_tree_insert_rebalance_C(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (0x7fffffd < *(uint *)((int)this + 4)) {
    operator_delete(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_004f4051;
      }
LAB_004f3fa8:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_004f3fa8;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_004f4051:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}




/* [AUDIT] proposed: std::_List_node_alloc_0x20  (confidence: med)
 * purpose: Allocates 0x20-byte list node, self-links prev/next when null; bad_alloc on fail
 * vars: shared list-node ctor
 */
/* Global::std_List_node_alloc_0x20 @ 004f7b60 */

void std_List_node_alloc_0x20(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x20);
  if (puVar1 != (void *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      param_1 = puVar1;
      param_2 = puVar1;
    }
    *puVar1 = param_1;
    if (puVar1 + 1 != (undefined4 *)0x0) {
      puVar1[1] = param_2;
    }
    return;
  }
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: std::_Tree_node_alloc_0x1c  (confidence: med)
 * purpose: Allocates 0x1c-byte tree node, inits [0..2]=sentinel; bad_alloc
 * vars: small tree node
 */
/* Global::std_Tree_node_alloc_0x1c @ 004f7ba0 */

undefined4 * __fastcall std_Tree_node_alloc_0x1c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Tree_node_alloc_0x20b  (confidence: med)
 * purpose: Allocates 0x20-byte tree node, inits [0..2]=sentinel; bad_alloc
 * vars: variant node alloc
 */
/* Global::std_Tree_node_alloc_0x20b @ 004f7be0 */

undefined4 * __fastcall std_Tree_node_alloc_0x20b(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std::_Rb_tree_destroy_recursive_B  (confidence: high)
 * purpose: Recursively frees an RB-tree subtree (nodes only, no embedded buffer)
 * vars: +0xd nil flag; [2]=right; [0]=left
 */
/* Global::std_Rb_tree_destroy_recursive_B @ 004f7c20 */

void std_Rb_tree_destroy_recursive_B(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    std_Rb_tree_destroy_recursive_B((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}




/* [AUDIT] proposed: std::map::lower_bound_2key  (confidence: high)
 * purpose: Lower-bound in map keyed by 2 ints (node[4],node[5]); descends comparing (a,b) lexically
 * vars: param_1=(key0,key1); node[4]/[5]=key
 */
/* Global::std_map_lower_bound_2key @ 004f7c60 */

undefined4 * __thiscall std_map_lower_bound_2key(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)this;
  if (*(char *)((int)puVar3[1] + 0xd) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (((int)puVar1[4] < *param_1) ||
         (((int)puVar1[4] <= *param_1 && ((int)puVar1[5] < param_1[1])))) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0xd) == '\0');
  }
  return puVar3;
}




/* [AUDIT] proposed: std::map::clear  (confidence: high)
 * purpose: Clears a tree/list container: recursively frees children then resets header sentinel and size
 * vars: *param_1=header; +4=root; std_Rb_tree_destroy_recursive_B=recursive destroy
 */
/* Global::std_map_clear @ 004f8520 */

void __fastcall std_map_clear(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(*param_1 + 4) + 0xd);
  piVar3 = *(int **)(*param_1 + 4);
  while (cVar1 == '\0') {
    std_Rb_tree_destroy_recursive_B((int *)piVar3[2]);
    piVar2 = (int *)*piVar3;
    operator_delete(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  *(int *)(*param_1 + 4) = *param_1;
  *(int *)*param_1 = *param_1;
  *(int *)(*param_1 + 8) = *param_1;
  param_1[1] = 0;
  return;
}




/* [AUDIT] proposed: std::map::erase_range_B  (confidence: high)
 * purpose: Erases node range [param_2,param_3) from a map; full-clear fast path; per-node RBTree_eraseNode_plain erase
 * vars: this=tree header; successor walk; std_map_clear clear path
 */
/* Global::std_map_erase_range_B @ 004fc060 */

undefined4 * __thiscall std_map_erase_range_B(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  local_8 = this;
  piVar2 = param_2;
  if ((param_2 == (int *)**(int **)this) && (param_3 == *(int **)this)) {
    std_map_clear(this);
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar2 != param_3) {
    param_2 = piVar2;
    if (*(char *)((int)piVar2 + 0xd) == '\0') {
      param_2 = (int *)piVar2[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar3 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar3 + 0xd);
          param_2 = piVar3;
          piVar3 = (int *)*piVar3;
        }
      }
      else {
        cVar1 = *(char *)(piVar2[1] + 0xd);
        piVar4 = (int *)piVar2[1];
        piVar3 = piVar2;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar3 = param_2;
        }
      }
    }
    RBTree_eraseNode_plain(this,&local_8,piVar2);
    piVar2 = param_2;
  }
  *param_1 = piVar2;
  return param_1;
}




/* [AUDIT] proposed: std::_Tree_node_alloc_assign2  (confidence: med)
 * purpose: Allocates World tree node (std_Tree_node_alloc_0x18), zeroes color, stores 2-int key at node+4/+5
 * vars: node+4/+5=key pair
 */
/* Global::std_Tree_node_alloc_assign2 @ 0052df80 */

undefined4 * __thiscall std_Tree_node_alloc_assign2(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = std_Tree_node_alloc_0x18(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    puVar1[4] = *param_1;
    puVar1[5] = param_1[1];
  }
  return puVar1;
}




/* [AUDIT] proposed: std::list::insertNode1  (confidence: med)
 * purpose: Inserts list node (std_List_node_alloc_0xc) and stores single value at node+8
 * vars: param_3=payload
 */
/* Global::std_list_insertNode1 @ 0052dfb0 */

void std_list_insertNode1(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = std_List_node_alloc_0xc(param_1,param_2);
  if ((undefined4 *)(iVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)(iVar1 + 8) = *param_3;
  }
  return;
}




/* [AUDIT] proposed: std::_List_init_sentinel  (confidence: med)
 * purpose: Allocates 0x14-byte list sentinel, self-links [0..2], sets [0xc]=0x101 (nil/color init)
 * vars: Creature list header init
 */
/* Global::std_List_init_sentinel @ 0052ed30 */

void std_List_init_sentinel(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: std::_Tree_node_alloc_0x18  (confidence: med)
 * purpose: Allocates 0x18-byte tree node, inits [0..2]=sentinel; bad_alloc
 * vars: World map node
 */
/* Global::std_Tree_node_alloc_0x18 @ 0052ed60 */

undefined4 * __fastcall std_Tree_node_alloc_0x18(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}




/* [AUDIT] proposed: std::map::lower_bound_yx  (confidence: high)
 * purpose: Lower-bound in map ordered by (y,x): descends tree comparing key[1] then key[0]
 * vars: param_2=(x,y) key; node[4]/[5]=x/y; returns node or header
 */
/* Global::std_map_lower_bound_yx @ 00530600 */

void __thiscall std_map_lower_bound_yx(void *this,int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)this;
  puVar4 = puVar1;
  if (*(char *)((int)puVar1[1] + 0xd) == '\0') {
    puVar2 = (undefined4 *)puVar1[1];
    do {
      if (((int)param_2[1] < (int)puVar2[5]) ||
         (((int)param_2[1] <= (int)puVar2[5] && (*param_2 <= (uint)puVar2[4])))) {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      else {
        puVar3 = (undefined4 *)puVar2[2];
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0xd) == '\0');
  }
  if (puVar4 != puVar1) {
    if (((int)puVar4[5] <= (int)param_2[1]) &&
       (((int)puVar4[5] < (int)param_2[1] || ((uint)puVar4[4] <= *param_2)))) {
      *param_1 = (int)puVar4;
      return;
    }
  }
  *param_1 = (int)puVar1;
  return;
}




/* [AUDIT] proposed: operator_new_wrapper  (confidence: high)
 * purpose: Thin wrapper calling operator_new(param_1); discards result (allocation stub)
 * vars: -
 */
/* Global::operator_new_wrapper @ 0054a6ce */

void __cdecl operator_new_wrapper(uint param_1)

{
  operator_new(param_1);
  return;
}




/* [AUDIT] proposed: __ftol2  (confidence: high)
 * purpose: Statically-linked MSVC CRT/STL function identified by signature match (flirt-crc, crc:swap~;len=0x75). Mangled: __ftol2.
 * vars: -
 */
/* Global::ftol2 @ 0054a946 */

ulonglong ftol2(void)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float in_ST0;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  uVar1 = (ulonglong)ROUND(in_ST0);
  local_20 = (uint)uVar1;
  uStack_1c = (float)(uVar1 >> 0x20);
  fVar3 = (float)in_ST0;
  if ((local_20 != 0) || (fVar3 = uStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
    if ((int)fVar3 < 0) {
      uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float)(longlong)uVar1));
    }
    else {
      uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float)(longlong)uVar1));
      uVar1 = CONCAT44((int)uStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);
    }
  }
  return uVar1;
}




/* [AUDIT] proposed: eh_vector_ctor_iter_unwind  (confidence: med)
 * purpose: Compiler EH thunk: on exception calls __ArrayUnwind for array element constructor iterator
 * vars: reads unaff regs; EBP+0x18=dtor
 */
/* Global::eh_vector_ctor_iter_unwind @ 0054ada6 */

void eh_vector_ctor_iter_unwind(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  void *unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_EDI,unaff_EBX,unaff_ESI,*(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}




/* [AUDIT] proposed: eh_vector_dtor_iter_unwind  (confidence: med)
 * purpose: Compiler EH thunk: on exception calls __ArrayUnwind for array element destructor iterator
 * vars: EBP+0x14=dtor ptr
 */
/* Global::eh_vector_dtor_iter_unwind @ 0054ae15 */

void eh_vector_dtor_iter_unwind(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  void *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_ESI,unaff_EBX,unaff_EDI,*(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}




