// PreviewWidget (ui) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "PreviewWidget.h"

/* cube::PreviewWidget::ctor_0 @ 004d4f10 */

void cube::PreviewWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 list;
  undefined4 *self;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1a90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,local_2c);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  *(undefined1 *)(self + 0x59) = 0;
  self[0x5a] = 0xffffffff;
  self[0x5b] = 0;
  self[0x5c] = 0xffffffff;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  self[0x5d] = 0;
  self[0x5e] = 0;
  list = list_buyNode_0c(0,0);
  self[0x5d] = list;
  self[0x5f] = param_3;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: PreviewWidget_dtor  (confidence: high)
 * purpose: Destructor: destroys intrusive list at +0x174 and frees its storage
 * vars: offset 0x174
 */
/* Global::PreviewWidget_dtor @ 004d5010 */

void PreviewWidget_dtor(void)

{
  undefined4 *listHead;
  void *firstNode;
  int self;
  
  listHead = *(undefined4 **)(self + 0x174);
  firstNode = (void *)*listHead;
  *listHead = listHead;
  *(int *)(*(int *)(self + 0x174) + 4) = *(int *)(self + 0x174);
  *(undefined4 *)(self + 0x178) = 0;
  if (firstNode != *(void **)(self + 0x174)) {
    operator_delete(firstNode);
  }
  operator_delete(*(void **)(self + 0x174));
}




/* cube::PreviewWidget::vfunc_0 @ 004d5070 */

void cube::PreviewWidget::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  PreviewWidget_dtor();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




