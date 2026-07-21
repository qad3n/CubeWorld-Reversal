// OptionsWidget (ui) — cube. 5 functions. Bodies = Ghidra pseudo-C.
#include "OptionsWidget.h"

/* [AUDIT] proposed: OptionsWidget_initDefaults  (confidence: high)
 * purpose: Initializes OptionsWidget config fields to defaults (0x32,100,0x50,9,...)
 * vars: 12 config dwords
 */
/* Global::OptionsWidget_initDefaults @ 004ce660 */

void OptionsWidget_initDefaults(void)

{
  undefined4 *self;
  
  *self = 0;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0x32;
  self[5] = 100;
  self[6] = 100;
  self[7] = 0x32;
  self[8] = 0x50;
  self[9] = 0;
  self[10] = 0;
  self[0xb] = 9;
  return;
}




/* [AUDIT] proposed: OptionsWidget_dispatchEvent  (confidence: high)
 * purpose: Recursively walks child widgets matching focus and fires a MemberFunctionConnection callback
 * vars: 0x40 focus; 0x2c children
 */
/* Global::OptionsWidget_dispatchEvent @ 004cf220 */

void OptionsWidget_dispatchEvent(undefined4 *name,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *namePtr;
  int cmp;
  int in_ECX;
  int *child;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    namePtr = name;
    if (7 < (uint)name[5]) {
      namePtr = (undefined4 *)*name;
    }
    cmp = u16string_compare(0,*(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x1c),namePtr,name[4]);
    if (cmp == 0) {
      plasma::Widget::MemberFunctionConnection<cube::OptionsWidget>::ctor_0
                (param_2,param_3,param_4,param_5,param_6,1);
    }
  }
  child = (int *)**(int **)(in_ECX + 0x2c);
  if (child != *(int **)(in_ECX + 0x2c)) {
    do {
      OptionsWidget_dispatchEvent(name,param_2,param_3,param_4,param_5,param_6);
      child = (int *)*child;
    } while (child != (int *)*(int *)(in_ECX + 0x2c));
  }
  return;
}




/* plasma::Widget::MemberFunctionConnection<cube::OptionsWidget>::ctor_0 @ 004cf2a0 */

void plasma::Widget::MemberFunctionConnection<cube::OptionsWidget>::ctor_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *slot;
  undefined4 *connection;
  int *childNode;
  int *childList;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1e48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  slot = (undefined4 *)rbtree_findOrInsert_intKey(&param_1);
  if ((void *)*slot != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)*slot);
  }
  connection = operator_new(0x18);
  uVar2 = param_5;
  uVar1 = param_2;
  if (connection == (undefined4 *)0x0) {
    connection = (undefined4 *)0x0;
  }
  else {
    *(char *)(connection + 1) = (char)param_6;
    *connection = vftable;
    connection[2] = param_2;
    connection[4] = param_3;
    connection[5] = param_4;
  }
  *slot = connection;
  if ((char)param_5 != '\0') {
    tree_clear(&childList);
    local_8 = 0;
    childNode = (int *)*childList;
    if (childNode != childList) {
      do {
        ctor_0(param_1,uVar1,param_3,param_4,uVar2,param_6);
        childNode = (int *)*childNode;
      } while (childNode != childList);
    }
    childNode = (int *)*childList;
    *childList = (int)childList;
    childList[1] = (int)childList;
    local_18 = 0;
    if (childNode != childList) {
                    /* WARNING: Subroutine does not return */
      operator_delete(childNode);
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(childList);
  }
  ExceptionList = local_10;
  return;
}




/* cube::OptionsWidget::ctor_0 @ 004cf3c0 */

void cube::OptionsWidget::ctor_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 widget;
  undefined4 *self;
  void *local_44 [5];
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8786;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  local_14 = uVar1;
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,local_2c);
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  self[0x59] = 0;
  self[0x5a] = 0;
  local_8._0_1_ = 3;
  self[0x5b] = param_3;
  OptionsWidget_initDefaults(uVar1);
  self[0x81] = 0;
  widget = Node_clone_subtree_v2(param_2);
  self[0x5c] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 4;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4570,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x5d] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 5;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d45b0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x5e] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 6;
  OptionsWidget_dispatchEvent(local_2c,2,self,UiCarousel_selectPrev,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x5f] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 7;
  OptionsWidget_dispatchEvent(local_2c,2,self,UiCarousel_selectNext,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x60] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 8;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4430,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x61] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 9;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4450,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x62] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 10;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4690,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[99] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 0xb;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d46b0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[100] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 0xc;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4da0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x65] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 0xd;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4dc0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x66] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 0xe;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4610,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x67] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 0xf;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4630,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x68] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 0x10;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d44d0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x69] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 0x11;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d44f0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x6a] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  local_8._0_1_ = 0x12;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4490,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x6b] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  local_8._0_1_ = 0x13;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d44b0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x6c] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  u16string_assignCStr(L"leftbutton");
  local_8._0_1_ = 0x14;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d45d0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x6d] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  u16string_assignCStr(L"rightbutton");
  local_8._0_1_ = 0x15;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d45d0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x6e] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  u16string_assignCStr(L"leftbutton");
  local_8._0_1_ = 0x16;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4530,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x6f] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  u16string_assignCStr(L"rightbutton");
  local_8._0_1_ = 0x17;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4550,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x70] = widget;
  widget = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  u16string_assignCStr(L"leftbutton");
  local_8._0_1_ = 0x18;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d45f0,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree_v2(param_2);
  self[0x71] = widget;
  widget = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(widget);
  widget = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(widget);
  u16string_assignCStr(L"rightbutton");
  local_8._0_1_ = 0x19;
  OptionsWidget_dispatchEvent(local_2c,2,self,&LAB_004d4600,0,1);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  widget = Node_clone_subtree(param_2);
  self[0x72] = widget;
  widget = Node_clone_subtree(param_2);
  self[0x73] = widget;
  widget = Node_clone_subtree(param_2);
  self[0x74] = widget;
  Widget_measureContentEntry(0x42dc0000,0x41700000,1);
  u16string_assignCStr(L"Apply");
  local_8._0_1_ = 0x1a;
  Node_select_glyph_by_name(local_2c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  Widget_measureContentEntry(0x42dc0000,0x41700000,1);
  u16string_assignCStr(&DAT_007033d0);
  local_8._0_1_ = 0x1b;
  Node_select_glyph_by_name(local_2c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  Widget_measureContentEntry(0x42dc0000,0x41700000,1);
  u16string_assignCStr(L"Cancel");
  local_8._0_1_ = 0x1c;
  Node_select_glyph_by_name(local_44);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_30) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_44[0]);
  }
  plasma::Widget::MemberFunctionConnection<cube::OptionsWidget>::ctor_0
            (2,self,&LAB_004d4470,0,1,1);
  plasma::Widget::MemberFunctionConnection<cube::OptionsWidget>::ctor_0(2,self,OptionsMenu_applyAndClearSelection,0,1,1)
  ;
  plasma::Widget::MemberFunctionConnection<cube::OptionsWidget>::ctor_0
            (2,self,&LAB_004d4510,0,1,1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::OptionsWidget::vfunc_10 @ 004d46d0 */

void cube::OptionsWidget::vfunc_10(void)

{
  float10 itemWidth;
  float10 labelWidth;
  float10 fVar3;
  float slotHeight;
  undefined4 uVar5;
  undefined4 uVar6;
  
  Widget_setScroll(0x43700000,0x41400000,1);
  uVar6 = 1;
  uVar5 = 0x41400000;
  itemWidth = (float10)Widget_measureGuarded(0x41400000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x42280000,1);
  uVar6 = 1;
  uVar5 = 0x42280000;
  itemWidth = (float10)Widget_measureGuarded(0x42280000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x42900000,1);
  uVar6 = 1;
  uVar5 = 0x42900000;
  itemWidth = (float10)Widget_measureGuarded(0x42900000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x42cc0000,1);
  uVar6 = 1;
  uVar5 = 0x42cc0000;
  itemWidth = (float10)Widget_measureGuarded(0x42cc0000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x43040000,1);
  uVar6 = 1;
  uVar5 = 0x43040000;
  itemWidth = (float10)Widget_measureGuarded(0x43040000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x43220000,1);
  uVar6 = 1;
  uVar5 = 0x43220000;
  itemWidth = (float10)Widget_measureGuarded(0x43220000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x43400000,1);
  uVar6 = 1;
  uVar5 = 0x43400000;
  itemWidth = (float10)Widget_measureGuarded(0x43400000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x435e0000,1);
  uVar6 = 1;
  uVar5 = 0x435e0000;
  itemWidth = (float10)Widget_measureGuarded();
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x437c0000,1);
  uVar6 = 1;
  uVar5 = 0x437c0000;
  itemWidth = (float10)Widget_measureGuarded(0x437c0000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x438d0000,1);
  uVar6 = 1;
  uVar5 = 0x438d0000;
  itemWidth = (float10)Widget_measureGuarded();
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  Widget_setScroll(0x43700000,0x439c0000,1);
  uVar6 = 1;
  uVar5 = 0x439c0000;
  itemWidth = (float10)Widget_measureGuarded(0x439c0000,1);
  labelWidth = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)itemWidth - (float)labelWidth) - 15.0,uVar5,uVar6);
  uVar5 = 1;
  itemWidth = (float10)Widget_measure(1);
  labelWidth = (float10)Widget_measure();
  Widget_setScroll(0x41a00000,((float)itemWidth - (float)labelWidth) - 20.0,uVar5);
  itemWidth = (float10)Widget_measureGuarded();
  uVar5 = 1;
  labelWidth = (float10)Widget_measure(1);
  fVar3 = (float10)Widget_measure();
  slotHeight = ((float)labelWidth - (float)fVar3) - 20.0;
  labelWidth = (float10)Widget_measureGuarded(slotHeight);
  Widget_setScroll((((float)itemWidth - 40.0) - (float)labelWidth) * 0.5 + 20.0,slotHeight,uVar5);
  itemWidth = (float10)Widget_measureGuarded();
  uVar5 = 1;
  labelWidth = (float10)Widget_measure(1);
  fVar3 = (float10)Widget_measure();
  slotHeight = ((float)labelWidth - (float)fVar3) - 20.0;
  labelWidth = (float10)Widget_measureGuarded(slotHeight);
  Widget_setScroll(((float)itemWidth - 20.0) - (float)labelWidth,slotHeight,uVar5);
  return;
}




