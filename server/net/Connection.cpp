// Connection (net) — server. 13 functions. Bodies = Ghidra pseudo-C.
#include "Connection.h"

/* cube::Connection::ctor_1 @ 00422910 */

undefined4 * __fastcall cube::Connection::ctor_1(undefined4 *self)

{
  undefined4 obj;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054c6b7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = vftable;
  Connection_ctor(self + 6);
  local_8 = 0;
  self[0x20] = 0;
  self[0x21] = 0;
  obj = buyNode16((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x20] = obj;
  local_8._0_1_ = 1;
  self[0x22] = 0;
  self[0x23] = 0;
  obj = buyNode16((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x22] = obj;
  local_8 = CONCAT31(local_8._1_3_,2);
  self[0x24] = 0;
  self[0x25] = 0;
  obj = buyNode40((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x24] = obj;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(self + 0x26),0x80000400);
  ExceptionList = local_10;
  return self;
}




/* [AUDIT] proposed: Connection_ctor  (confidence: high)
 * purpose: Constructs Connection: allocates ~13 list/tree sentinel heads of varying node sizes via buynode calls
 * vars: self=Connection; SEH-guarded; fields [0..0x18] each get sentinel
 */
/* Global::Connection_ctor @ 00423510 */

undefined4 * __fastcall Connection_ctor(undefined4 *self)

{
  undefined4 list;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054c7c1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = 0;
  self[1] = 0;
  list = buyNode80((undefined4 *)0x0,(undefined4 *)0x0);
  *self = list;
  local_8 = 0;
  self[2] = 0;
  self[3] = 0;
  list = std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
  self[2] = list;
  local_8._0_1_ = 1;
  self[4] = 0;
  self[5] = 0;
  list = buyNode80((undefined4 *)0x0,(undefined4 *)0x0);
  self[4] = list;
  local_8._0_1_ = 2;
  self[6] = 0;
  self[7] = 0;
  list = buyNode28((undefined4 *)0x0,(undefined4 *)0x0);
  self[6] = list;
  local_8._0_1_ = 3;
  self[8] = 0;
  self[9] = 0;
  list = buyNode120((undefined4 *)0x0,(undefined4 *)0x0);
  self[8] = list;
  local_8._0_1_ = 4;
  self[10] = 0;
  self[0xb] = 0;
  list = buyNode24((undefined4 *)0x0,(undefined4 *)0x0);
  self[10] = list;
  local_8._0_1_ = 5;
  self[0xc] = 0;
  self[0xd] = 0;
  list = buyNode96((undefined4 *)0x0,(undefined4 *)0x0);
  self[0xc] = list;
  local_8._0_1_ = 6;
  self[0xe] = 0;
  self[0xf] = 0;
  list = buyNode24((undefined4 *)0x0,(undefined4 *)0x0);
  self[0xe] = list;
  local_8._0_1_ = 7;
  self[0x10] = 0;
  self[0x11] = 0;
  list = buyNode296((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x10] = list;
  local_8._0_1_ = 8;
  self[0x12] = 0;
  self[0x13] = 0;
  list = std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x12] = list;
  local_8._0_1_ = 9;
  self[0x14] = 0;
  self[0x15] = 0;
  list = std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x14] = list;
  local_8._0_1_ = 10;
  self[0x16] = 0;
  self[0x17] = 0;
  list = List_allocNode0x30((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x16] = list;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  self[0x18] = 0;
  self[0x19] = 0;
  list = buyNode64((undefined4 *)0x0,(undefined4 *)0x0);
  self[0x18] = list;
  ExceptionList = local_10;
  return self;
}




/* cube::Connection::ctor_0 @ 004237b0 */

void __fastcall cube::Connection::ctor_0(undefined4 *self)

{
  int *next;
  int *node;
  
  *self = vftable;
  DeleteCriticalSection((LPCRITICAL_SECTION)(self + 0x26));
  list_destroyWstrings(self + 0x24);
  operator_delete((void *)self[0x24]);
  next = (int *)self[0x22];
  node = (int *)*next;
  *next = (int)next;
  *(undefined4 *)(self[0x22] + 4) = self[0x22];
  self[0x23] = 0;
  if (node != (int *)self[0x22]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x22]);
  }
  operator_delete((void *)self[0x22]);
  next = (int *)self[0x20];
  node = (int *)*next;
  *next = (int)next;
  *(undefined4 *)(self[0x20] + 4) = self[0x20];
  self[0x21] = 0;
  if (node != (int *)self[0x20]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x20]);
  }
  operator_delete((void *)self[0x20]);
  Connection_dtor(self + 6);
  return;
}




/* [AUDIT] proposed: Connection_dtor  (confidence: high)
 * purpose: Destroys Connection: clears and frees all ~13 contained lists/trees and their nodes
 * vars: self=Connection; iterates each list head [0..0x18], deletes nodes
 */
/* Global::Connection_dtor @ 004239f0 */

void __fastcall Connection_dtor(int *self)

{
  int *next;
  int *node;
  
  next = (int *)self[0x18];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[0x18] + 4) = self[0x18];
  self[0x19] = 0;
  if (node != (int *)self[0x18]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x18]);
  }
  operator_delete((void *)self[0x18]);
  next = (int *)self[0x16];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[0x16] + 4) = self[0x16];
  self[0x17] = 0;
  if (node != (int *)self[0x16]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x16]);
  }
  operator_delete((void *)self[0x16]);
  next = (int *)self[0x14];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[0x14] + 4) = self[0x14];
  self[0x15] = 0;
  if (node != (int *)self[0x14]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x14]);
  }
  operator_delete((void *)self[0x14]);
  next = (int *)self[0x12];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[0x12] + 4) = self[0x12];
  self[0x13] = 0;
  if (node != (int *)self[0x12]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x12]);
  }
  operator_delete((void *)self[0x12]);
  next = (int *)self[0x10];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[0x10] + 4) = self[0x10];
  self[0x11] = 0;
  if (node != (int *)self[0x10]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x10]);
  }
  operator_delete((void *)self[0x10]);
  Connection_destroyNestedLists(self + 0xe);
  operator_delete((void *)self[0xe]);
  next = (int *)self[0xc];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[0xc] + 4) = self[0xc];
  self[0xd] = 0;
  if (node != (int *)self[0xc]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0xc]);
  }
  operator_delete((void *)self[0xc]);
  Connection_destroyNestedLists(self + 10);
  operator_delete((void *)self[10]);
  next = (int *)self[8];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[8] + 4) = self[8];
  self[9] = 0;
  if (node != (int *)self[8]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[8]);
  }
  operator_delete((void *)self[8]);
  next = (int *)self[6];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[6] + 4) = self[6];
  self[7] = 0;
  if (node != (int *)self[6]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[6]);
  }
  operator_delete((void *)self[6]);
  next = (int *)self[4];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[4] + 4) = self[4];
  self[5] = 0;
  if (node != (int *)self[4]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[4]);
  }
  operator_delete((void *)self[4]);
  next = (int *)self[2];
  node = (int *)*next;
  *next = (int)next;
  *(int *)(self[2] + 4) = self[2];
  self[3] = 0;
  if (node != (int *)self[2]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[2]);
  }
  operator_delete((void *)self[2]);
  next = (int *)*self;
  node = (int *)*next;
  *next = (int)next;
  *(int *)(*self + 4) = *self;
  self[1] = 0;
  if (node != (int *)*self) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)*self);
  }
  operator_delete((void *)*self);
  return;
}




/* cube::Connection::vfunc_0 @ 00426750 */

undefined4 * __thiscall cube::Connection::vfunc_0(Connection *this,byte delete_flag)

{
  ctor_0((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




/* [AUDIT] proposed: buyNode40  (confidence: med)
 * purpose: Allocates 0x28-byte list node, self-links if null args
 * vars: Connection list node
 */
/* Global::buyNode40 @ 00426830 */

void buyNode40(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x28);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: buyNode28  (confidence: med)
 * purpose: Allocates 0x1c-byte list node, self-links if null args
 * vars: Connection list node
 */
/* Global::buyNode28 @ 00426870 */

void buyNode28(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x1c);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: buyNode24  (confidence: med)
 * purpose: Allocates 0x18-byte list node, self-links if null args
 * vars: Connection list node
 */
/* Global::buyNode24 @ 004268f0 */

void buyNode24(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x18);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: buyNode296  (confidence: med)
 * purpose: Allocates 0x128-byte list node, self-links if null args
 * vars: Connection large payload node
 */
/* Global::buyNode296 @ 00426930 */

void buyNode296(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x128);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: buyNode64  (confidence: med)
 * purpose: Allocates 0x40-byte list node, self-links if null args
 * vars: Connection list node
 */
/* Global::buyNode64 @ 00426970 */

void buyNode64(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x40);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: buyNode96  (confidence: med)
 * purpose: Allocates 0x60-byte list node, self-links if null args
 * vars: Connection list node
 */
/* Global::buyNode96 @ 004269b0 */

void buyNode96(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x60);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: buyNode16  (confidence: med)
 * purpose: Allocates 0x10-byte list node, self-links if null args
 * vars: minimal list node
 */
/* Global::buyNode16 @ 00426a30 */

void buyNode16(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x10);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
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




/* [AUDIT] proposed: Connection_destroyNestedLists  (confidence: high)
 * purpose: Clears a list whose nodes each own an inner list (nested list-of-lists), freeing inner nodes then outer
 * vars: prev=outer list head; node+0x10 inner list head
 */
/* Global::Connection_destroyNestedLists @ 00428080 */

void __fastcall Connection_destroyNestedLists(int *self)

{
  int *piVar1;
  int *next;
  int *inner;
  int *node;
  
  piVar1 = (int *)*self;
  node = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*self + 4) = *self;
  self[1] = 0;
  if (node != (int *)*self) {
    do {
      piVar1 = (int *)node[4];
      next = (int *)*node;
      inner = (int *)*piVar1;
      *piVar1 = (int)piVar1;
      *(int *)(node[4] + 4) = node[4];
      node[5] = 0;
      if (inner != (int *)node[4]) {
        do {
          piVar1 = (int *)*inner;
          operator_delete(inner);
          inner = piVar1;
        } while (piVar1 != (int *)node[4]);
      }
      operator_delete((void *)node[4]);
      operator_delete(node);
      node = next;
    } while (next != (int *)*self);
  }
  return;
}




