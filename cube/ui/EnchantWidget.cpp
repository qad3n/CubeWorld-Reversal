// EnchantWidget (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "EnchantWidget.h"

/* cube::EnchantWidget::ctor_0 @ 0044e910 */

void cube::EnchantWidget::ctor_0
               (undefined4 parent,undefined4 name,undefined4 slot,int itemPtr)

{
  uint cookie;
  int item;
  undefined4 cb;
  undefined4 *self;
  void *nameBuf [4];
  undefined4 local_1c;
  uint nameCap;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e2f00;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  nameCap = 7;
  local_1c = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(parent,name,nameBuf);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (7 < nameCap) {
    operator_delete(nameBuf[0]);
  }
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0xffffffff;
  self[0x59] = 0xffffffff;
  nameCap = 7;
  local_1c = 0;
  self[0x5a] = 1;
  self[0x5b] = slot;
  self[0x5c] = itemPtr;
  if (itemPtr != 0) {
    item = Node_clone_subtree_v2(name);
    self[0x5c] = item;
    cb = (**(code **)(**(int **)(item + 0x38) + 8))(cookie);
    Node_set_style_slot(cb);
    cb = (**(code **)(**(int **)(self[0x5c] + 0x3c) + 8))();
    Node_set_font_slot(cb);
  }
  ExceptionList = local_10;
  return;
}




/* cube::EnchantWidget::vfunc_10 @ 00450b90 */

void cube::EnchantWidget::vfunc_10(void)

{
  int self;
  float full;
  float used;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (*(int *)(self + 0x170) != 0) {
    uVar4 = 1;
    uVar3 = 0x42480000;
    full = (float)security_cookie_guard_b(0x42480000,1);
    used = (float)Widget_measureGuarded();
    Widget_setScroll(((float)full - (float)used) * 0.5f,uVar3,uVar4);
  }
  return;
}




