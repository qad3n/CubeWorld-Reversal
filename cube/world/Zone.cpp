// Zone (world) — cube. 6 functions. Bodies = Ghidra pseudo-C.
#include "Zone.h"

/* [AUDIT] proposed: Zone_rbtree_eraseRange  (confidence: med)
 * purpose: Erase RB-tree node range [param_2,param_3); clear whole tree if full range; class Zone
 * vars: rbtree_destroyRecursive clear; Zone_rbtree_eraseNode erase
 */
/* Global::Zone_rbtree_eraseRange @ 004777f0 */

undefined4 * Zone_rbtree_eraseRange(undefined4 *pResult,int *pFirst,int *pLast)

{
  char isBlack;
  int *pRoot;
  int *pIt;
  int *piVar4;
  int *pThis;
  undefined1 local_8 [4];
  
  pRoot = (int *)*pThis;
  pIt = pFirst;
  if ((pFirst == (int *)*pRoot) && (pLast == pRoot)) {
    rbtree_destroyRecursive(pRoot[1]);
    *(int *)(*pThis + 4) = *pThis;
    *(int *)*pThis = *pThis;
    *(int *)(*pThis + 8) = *pThis;
    pThis[1] = 0;
    *pResult = *(undefined4 *)*pThis;
    return pResult;
  }
  while (pIt != pLast) {
    pFirst = pIt;
    if (*(char *)((int)pIt + 0xd) == '\0') {
      pFirst = (int *)pIt[2];
      if (*(char *)((int)pFirst + 0xd) == '\0') {
        isBlack = *(char *)(*pFirst + 0xd);
        pRoot = (int *)*pFirst;
        while (isBlack == '\0') {
          isBlack = *(char *)(*pRoot + 0xd);
          pFirst = pRoot;
          pRoot = (int *)*pRoot;
        }
      }
      else {
        isBlack = *(char *)(pIt[1] + 0xd);
        piVar4 = (int *)pIt[1];
        pRoot = pIt;
        while ((pFirst = piVar4, isBlack == '\0' && (pRoot == (int *)pFirst[2]))) {
          isBlack = *(char *)(pFirst[1] + 0xd);
          piVar4 = (int *)pFirst[1];
          pRoot = pFirst;
        }
      }
    }
    Zone_rbtree_eraseNode(local_8,pIt);
    pIt = pFirst;
  }
  *pResult = pIt;
  return pResult;
}




/* [AUDIT] proposed: Zone_rbtree_eraseNode  (confidence: low)
 * purpose: Red-black tree single-node erase with rebalance/recolor then free 2 strings and delete
 * vars: 'invalid map/set<T> iterator'
 */
/* Global::Zone_rbtree_eraseNode @ 004778b0 */

/* WARNING: Removing unreachable block (ram,0x0047797d) */
/* WARNING: Removing unreachable block (ram,0x0047798d) */
/* WARNING: Removing unreachable block (ram,0x00477996) */
/* WARNING: Removing unreachable block (ram,0x00477999) */
/* WARNING: Removing unreachable block (ram,0x00477989) */
/* WARNING: Removing unreachable block (ram,0x004779a7) */
/* WARNING: Removing unreachable block (ram,0x004779b6) */
/* WARNING: Removing unreachable block (ram,0x004779c1) */
/* WARNING: Removing unreachable block (ram,0x004779bd) */
/* WARNING: Removing unreachable block (ram,0x004779b1) */
/* WARNING: Removing unreachable block (ram,0x004779c4) */

void Zone_rbtree_eraseNode(undefined4 pResult,int *pNode)

{
  undefined4 *puVar1;
  int pRoot;
  int *pFixup;
  undefined4 uVar4;
  int *pThis;
  int *pParent;
  int *pSucc;
  
  if (*(char *)((int)pNode + 0xd) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  rbtree_iterator_increment();
  pSucc = (int *)*pNode;
  if (*(char *)((int)pSucc + 0xd) == '\0') {
    if (*(char *)(pNode[2] + 0xd) == '\0') {
      pSucc = (int *)pNode[2];
    }
  }
  else {
    pSucc = (int *)pNode[2];
  }
  pParent = (int *)pNode[1];
  if (*(char *)((int)pSucc + 0xd) == '\0') {
    pSucc[1] = (int)pParent;
  }
  if (*(int **)(*pThis + 4) == pNode) {
    *(int **)(*pThis + 4) = pSucc;
  }
  else if ((int *)*pParent == pNode) {
    *pParent = (int)pSucc;
  }
  else {
    pParent[2] = (int)pSucc;
  }
  puVar1 = (undefined4 *)*pThis;
  if ((int *)*puVar1 == pNode) {
    pFixup = pParent;
    if (*(char *)((int)pSucc + 0xd) == '\0') {
      pFixup = (int *)rbtree_min_node(pSucc);
    }
    *puVar1 = pFixup;
  }
  pRoot = *pThis;
  if (*(int **)(pRoot + 8) == pNode) {
    if (*(char *)((int)pSucc + 0xd) == '\0') {
      uVar4 = RBTree_next(pSucc);
      *(undefined4 *)(pRoot + 8) = uVar4;
    }
    else {
      *(int **)(pRoot + 8) = pParent;
    }
  }
  if ((char)pNode[3] == '\x01') {
    if (pSucc != *(int **)(*pThis + 4)) {
      do {
        pFixup = pParent;
        if ((char)pSucc[3] != '\x01') break;
        pParent = (int *)*pFixup;
        if (pSucc == pParent) {
          pParent = (int *)pFixup[2];
          if ((char)pParent[3] == '\0') {
            *(undefined1 *)(pParent + 3) = 1;
            *(undefined1 *)(pFixup + 3) = 0;
            rbtree_rotate_left(pFixup);
            pParent = (int *)pFixup[2];
          }
          if (*(char *)((int)pParent + 0xd) == '\0') {
            if ((*(char *)(*pParent + 0xc) != '\x01') || (*(char *)(pParent[2] + 0xc) != '\x01')) {
              if (*(char *)(pParent[2] + 0xc) == '\x01') {
                *(undefined1 *)(*pParent + 0xc) = 1;
                *(undefined1 *)(pParent + 3) = 0;
                rbtree_rotate(pParent);
                pParent = (int *)pFixup[2];
              }
              *(char *)(pParent + 3) = (char)pFixup[3];
              *(undefined1 *)(pFixup + 3) = 1;
              *(undefined1 *)(pParent[2] + 0xc) = 1;
              rbtree_rotate_left(pFixup);
              *(undefined1 *)(pSucc + 3) = 1;
              goto LAB_00477b0e;
            }
LAB_00477ab0:
            *(undefined1 *)(pParent + 3) = 0;
          }
        }
        else {
          if ((char)pParent[3] == '\0') {
            *(undefined1 *)(pParent + 3) = 1;
            *(undefined1 *)(pFixup + 3) = 0;
            rbtree_rotate(pFixup);
            pParent = (int *)*pFixup;
          }
          if (*(char *)((int)pParent + 0xd) == '\0') {
            if ((*(char *)(pParent[2] + 0xc) == '\x01') && (*(char *)(*pParent + 0xc) == '\x01'))
            goto LAB_00477ab0;
            if (*(char *)(*pParent + 0xc) == '\x01') {
              *(undefined1 *)(pParent[2] + 0xc) = 1;
              *(undefined1 *)(pParent + 3) = 0;
              rbtree_rotate_left(pParent);
              pParent = (int *)*pFixup;
            }
            *(char *)(pParent + 3) = (char)pFixup[3];
            *(undefined1 *)(pFixup + 3) = 1;
            *(undefined1 *)(*pParent + 0xc) = 1;
            rbtree_rotate(pFixup);
            *(undefined1 *)(pSucc + 3) = 1;
            goto LAB_00477b0e;
          }
        }
        pParent = (int *)pFixup[1];
        pSucc = pFixup;
      } while (pFixup != *(int **)(*pThis + 4));
    }
    *(undefined1 *)(pSucc + 3) = 1;
  }
LAB_00477b0e:
  if (7 < (uint)pNode[0xf]) {
    operator_delete((void *)pNode[10]);
  }
  pNode[0xf] = 7;
  pNode[0xe] = 0;
  *(undefined2 *)(pNode + 10) = 0;
  if (7 < (uint)pNode[9]) {
    operator_delete((void *)pNode[4]);
  }
  pNode[9] = 7;
  pNode[8] = 0;
  *(undefined2 *)(pNode + 4) = 0;
  operator_delete(pNode);
}




/* [AUDIT] proposed: Zone_DestroyObjectRange  (confidence: med)
 * purpose: Game/STL: destroys a range of Zone objects (stride 0x188 bytes = 0x62 dwords), freeing nested container storage
 * vars: stride 0x62 dwords; operator_delete
 */
/* Global::Zone_DestroyObjectRange @ 0058d970 */

void Zone_DestroyObjectRange(int *begin,int *end)

{
  int *zoneEnd;
  undefined4 *objList;
  int *zonePtr;
  
  if (begin != end) {
    zonePtr = begin + 0x12;
    do {
      objList = (undefined4 *)*zonePtr;
      if (objList != (undefined4 *)0x0) {
        while( true ) {
          if (objList == (undefined4 *)zonePtr[1]) {
            operator_delete((void *)*zonePtr);
          }
          if ((void *)*objList != (void *)0x0) break;
          objList = objList + 3;
        }
        operator_delete((void *)*objList);
      }
      zoneEnd = zonePtr + 0x50;
      zonePtr = zonePtr + 0x62;
    } while (zoneEnd != end);
  }
  return;
}




/* cube::Zone::ctor_0 @ 006240f0 */

void cube::Zone::ctor_0(void)

{
  uint security_cookie;
  undefined4 uVar2;
  undefined4 *alloc;
  undefined4 *self;
  undefined4 *field_array;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f54a5;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  uVar2 = list_allocNode(0,0);
  self[1] = uVar2;
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
  *(undefined2 *)(self + 0x1d) = 1;
  *(undefined1 *)((int)self + 0x76) = 0;
  self[0x1e] = 0;
  self[0x1f] = 0;
  self[0x20] = 1;
  *(undefined1 *)(self + 0x21) = 0;
  self[0x22] = 0;
  self[0x23] = 0;
  self[0x24] = 0;
  self[0x25] = 0;
  self[0x26] = 0;
  self[0x27] = 0;
  local_8._0_1_ = 10;
  local_8._1_3_ = 0;
  self[0x28] = 0;
  self[0x29] = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(self + 0x2c),0x80000400);
  alloc = (undefined4 *)operator_new_wrapper(0x200004,security_cookie);
  local_8._0_1_ = 0xb;
  if (alloc == (undefined4 *)0x0) {
    field_array = (undefined4 *)0x0;
  }
  else {
    field_array = alloc + 1;
    *alloc = 0x10000;
    _eh_vector_constructor_iterator_
              (field_array,0x20,0x10000,(_func_void_void_ptr *)&LAB_00450bf0,Field::ctor_0);
  }
  local_8._0_1_ = 10;
  self[0x2a] = field_array;
  alloc = (undefined4 *)operator_new_wrapper(0x2004,security_cookie);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  if (alloc != (undefined4 *)0x0) {
    *alloc = 0x400;
    _eh_vector_constructor_iterator_(alloc + 1,8,0x400,lib_fn_6240d0,std_list_clear_4da480);
    self[0x2b] = alloc + 1;
    ExceptionList = local_10;
    return;
  }
  self[0x2b] = 0;
  ExceptionList = local_10;
  return;
}




/* cube::Zone::ctor_1 @ 00624390 */

void cube::Zone::ctor_1(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint security_cookie;
  undefined4 *self;
  int *iter;
  undefined4 local_24;
  undefined1 local_20 [8];
  int item;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f553f;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  puVar1 = (undefined4 *)self[0x2a];
  local_8 = 10;
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1[-1] == 0) {
      operator_delete__(puVar1 + -1);
    }
    else {
      (**(code **)*puVar1)(3,security_cookie);
    }
  }
  pvVar2 = (void *)self[0x2b];
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar2,8,*(int *)((int)pvVar2 + -4),std_list_clear_4da480);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  iter = (int *)self[6];
  if (iter != (int *)self[7]) {
    do {
      if ((undefined4 *)*iter != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*iter)(1);
      }
      iter = iter + 1;
    } while (iter != (int *)self[7]);
  }
  iter = (int *)self[9];
  if (iter != (int *)self[10]) {
    do {
      item = *iter;
      if (item != 0) {
        puVar1 = (undefined4 *)(item + 0x78);
        puVar3 = (undefined4 *)*puVar1;
        std_Tree_eraseRange(local_20,*puVar3,puVar3);
        operator_delete((void *)*puVar1);
      }
      iter = iter + 1;
      item = 0;
    } while (iter != (int *)self[10]);
  }
  iter = (int *)self[0x22];
  if (iter != (int *)self[0x23]) {
    do {
      if ((undefined4 *)*iter != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*iter)(1);
      }
      iter = iter + 1;
    } while (iter != (int *)self[0x23]);
  }
  iter = (int *)self[0x25];
  if (iter != (int *)self[0x26]) {
    do {
      item = *iter;
      if (item != 0) {
        puVar1 = (undefined4 *)(item + 8);
        puVar3 = (undefined4 *)*puVar1;
        Zone_rbtree_eraseRange(local_20,*puVar3,puVar3);
        operator_delete((void *)*puVar1);
      }
      iter = iter + 1;
      item = 0;
    } while (iter != (int *)self[0x26]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(self + 0x2c));
  if ((void *)self[0x25] != (void *)0x0) {
    operator_delete((void *)self[0x25]);
  }
  if ((void *)self[0x22] != (void *)0x0) {
    operator_delete((void *)self[0x22]);
  }
  if ((void *)self[0x1a] != (void *)0x0) {
    operator_delete((void *)self[0x1a]);
  }
  if ((void *)self[0x15] != (void *)0x0) {
    operator_delete((void *)self[0x15]);
  }
  if ((void *)self[0x12] != (void *)0x0) {
    operator_delete((void *)self[0x12]);
  }
  if ((void *)self[0xf] != (void *)0x0) {
    operator_delete((void *)self[0xf]);
  }
  if ((void *)self[0xc] == (void *)0x0) {
    if ((void *)self[9] != (void *)0x0) {
      operator_delete((void *)self[9]);
    }
    if ((void *)self[6] != (void *)0x0) {
      operator_delete((void *)self[6]);
    }
    if (self[3] != 0) {
      Zone_DestroyObjectRange(self[3],self[4],&local_11,local_24);
      operator_delete((void *)self[3]);
    }
    puVar1 = (undefined4 *)self[1];
    pvVar2 = (void *)*puVar1;
    *puVar1 = puVar1;
    *(undefined4 *)(self[1] + 4) = self[1];
    self[2] = 0;
    if (pvVar2 == (void *)self[1]) {
      operator_delete((void *)self[1]);
    }
    operator_delete(pvVar2);
  }
  operator_delete((void *)self[0xc]);
}




/* cube::Zone::vfunc_0 @ 00624760 */

void cube::Zone::vfunc_0(byte delete_flag)

{
  void *self;
  
  ctor_1();
  if ((delete_flag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




