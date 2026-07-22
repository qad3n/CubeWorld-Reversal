// CharacterStyleWidget (ui) — cube. 9 functions. Bodies = Ghidra pseudo-C.
#include "CharacterStyleWidget.h"

/* [AUDIT] proposed: Widget_connectRecursive  (confidence: med)
 * purpose: Recursively traverses widget child tree; where key matches, wires a CharacterStyleWidget member-function callback
 * vars: in_ECX+0x40=key,+0x2c=children list
 */
/* Global::Widget_connectRecursive @ 00427b40 */

void Widget_connectRecursive(undefined4 *nameStr,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int cmpResult;
  int self;
  int *childNode;
  
  if (*(int *)(self + 0x40) != 0) {
    puVar1 = nameStr;
    if (7 < (uint)nameStr[5]) {
      puVar1 = (undefined4 *)*nameStr;
    }
    cmpResult = u16string_compare(0,*(undefined4 *)(*(int *)(self + 0x40) + 0x1c),puVar1,nameStr[4]);
    if (cmpResult == 0) {
      plasma::Widget::MemberFunctionConnection<cube::CharacterStyleWidget>::ctor_0
                (param_2,param_3,param_4,param_5,param_6,1);
    }
  }
  childNode = (int *)**(int **)(self + 0x2c);
  if (childNode != *(int **)(self + 0x2c)) {
    do {
      Widget_connectRecursive(nameStr,param_2,param_3,param_4,param_5,param_6);
      childNode = (int *)*childNode;
    } while (childNode != (int *)*(int *)(self + 0x2c));
  }
  return;
}




/* plasma::Widget::MemberFunctionConnection<cube::CharacterStyleWidget>::ctor_0 @ 00427bc0 */

void plasma::Widget::MemberFunctionConnection<cube::CharacterStyleWidget>::ctor_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *slotPtr;
  undefined4 *connection;
  int *childNode;
  int *childList;
  undefined4 listSize;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006e1e48;
  savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;
  slotPtr = (undefined4 *)rbtree_findOrInsert_intKey(&param_1);
  if ((void *)*slotPtr != (void *)0x0) {
    operator_delete((void *)*slotPtr);
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
  *slotPtr = connection;
  if ((char)param_5 != '\0') {
    tree_clear(&childList);
    trylevel = 0;
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
    listSize = 0;
    if (childNode != childList) {
      operator_delete(childNode);
    }
    operator_delete(childList);
  }
  ExceptionList = savedExceptionList;
  return;
}




/* cube::CharacterStyleWidget::ctor_0 @ 00427ce0 */

void cube::CharacterStyleWidget::ctor_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint stackCookie;
  undefined4 slotObj;
  int *piVar6;
  undefined4 *self;
  int iVar7;
  void *nameBuf [4];
  undefined4 nameSize;
  uint nameCap;
  undefined4 arg1;
  undefined1 local_41;
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 parent;
  undefined4 btnName;
  undefined4 btnSize;
  uint btnCap;
  uint cookieSaved;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006e1ef0;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExceptionList;
  arg1 = param_1;
  parent = param_2;
  nameCap = 7;
  nameSize = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  cookieSaved = stackCookie;
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel = 0;
  plasma::NamedObject::ctor_4(arg1,parent,nameBuf);
  trylevel._0_1_ = 2;
  if (7 < nameCap) {
    operator_delete(nameBuf[0]);
  }
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  *self = vftable;
  self[9] = vftable;
  self[0x58] = param_3;
  self[99] = 0;
  self[100] = 0;
  self[0x65] = 0;
  self[0x66] = 0;
  self[0x67] = 0;
  self[0x68] = 0xff32c8ff;
  nameCap = 7;
  nameSize = 0;
  *(undefined2 *)(self + 0x69) = 0xffff;
  slotObj = Node_clone_subtree_v2(parent);
  self[0x59] = slotObj;
  slotObj = (**(code **)(**(int **)(param_4 + 0x38) + 8))(stackCookie);
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName._2_2_ << 0x10);
  u16string_assignPtrLen(L"leftbutton",10);
  trylevel._0_1_ = 3;
  Widget_connectRecursive(&btnName,2,self,CharCreation_cycle_prev_0x18c,0,1);
  trylevel._0_1_ = 2;
  if (7 < btnCap) {
    operator_delete(btnName);
  }
  slotObj = Node_clone_subtree_v2(parent);
  self[0x5a] = slotObj;
  slotObj = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  trylevel._0_1_ = 4;
  Widget_connectRecursive(&btnName,2,self,CharCreation_cycle_next_0x18c,0,1);
  trylevel._0_1_ = 2;
  if (7 < btnCap) {
    operator_delete(btnName);
  }
  slotObj = Node_clone_subtree_v2(parent);
  self[0x5b] = slotObj;
  slotObj = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  trylevel._0_1_ = 5;
  Widget_connectRecursive(&btnName,2,self,CharCreation_cycle_hairstyle_prev,0,1);
  trylevel._0_1_ = 2;
  if (7 < btnCap) {
    operator_delete(btnName);
  }
  slotObj = Node_clone_subtree_v2(parent);
  self[0x5c] = slotObj;
  slotObj = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  trylevel._0_1_ = 6;
  Widget_connectRecursive(&btnName,2,self,CharCreation_cycle_hairstyle_next,0,1);
  trylevel._0_1_ = 2;
  if (7 < btnCap) {
    operator_delete(btnName);
  }
  slotObj = Node_clone_subtree_v2(parent);
  self[0x5d] = slotObj;
  slotObj = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  trylevel._0_1_ = 7;
  Widget_connectRecursive(&btnName,2,self,CharCreation_toggle_field_0x194,0,1);
  trylevel._0_1_ = 2;
  if (7 < btnCap) {
    operator_delete(btnName);
  }
  slotObj = Node_clone_subtree_v2(parent);
  self[0x5e] = slotObj;
  slotObj = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName & 0xffff0000);
  u16string_assignPtrLen(L"rightbutton",0xb);
  trylevel._0_1_ = 8;
  Widget_connectRecursive(&btnName,2,self,CharCreation_toggle_field_0x194,0,1);
  trylevel._0_1_ = 2;
  if (7 < btnCap) {
    operator_delete(btnName);
  }
  slotObj = Node_clone_subtree_v2(parent);
  self[0x5f] = slotObj;
  slotObj = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
  Node_set_style_slot(slotObj);
  slotObj = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
  Node_set_font_slot(slotObj);
  btnCap = 7;
  btnSize = 0;
  btnName = (void *)((uint)btnName & 0xffff0000);
  u16string_assignPtrLen(L"leftbutton",10);
  trylevel._0_1_ = 9;
  Widget_connectRecursive(&btnName,2,self,CharCreation_adjust_dec_0x198,0,1);
  trylevel._0_1_ = 2;
  if (btnCap < 8) {
    slotObj = Node_clone_subtree_v2(parent);
    self[0x60] = slotObj;
    slotObj = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
    Node_set_style_slot(slotObj);
    slotObj = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
    Node_set_font_slot(slotObj);
    btnCap = 7;
    btnSize = 0;
    btnName = (void *)((uint)btnName & 0xffff0000);
    u16string_assignPtrLen(L"rightbutton",0xb);
    trylevel._0_1_ = 10;
    Widget_connectRecursive(&btnName,2,self,CharCreation_adjust_inc_0x198,0,1);
    trylevel._0_1_ = 2;
    if (7 < btnCap) {
      operator_delete(btnName);
    }
    slotObj = Node_clone_subtree_v2(parent);
    self[0x61] = slotObj;
    slotObj = (**(code **)(**(int **)(param_4 + 0x38) + 8))();
    Node_set_style_slot(slotObj);
    slotObj = (**(code **)(**(int **)(param_4 + 0x3c) + 8))();
    Node_set_font_slot(slotObj);
    btnCap = 7;
    btnSize = 0;
    btnName = (void *)((uint)btnName & 0xffff0000);
    u16string_assignPtrLen(L"leftbutton",10);
    trylevel._0_1_ = 0xb;
    Widget_connectRecursive(&btnName,2,self,CharCreation_adjust_dec_0x19c,0,1);
    trylevel._0_1_ = 2;
    if (7 < btnCap) {
      operator_delete(btnName);
    }
    slotObj = Node_clone_subtree_v2(parent);
    self[0x62] = slotObj;
    slotObj = (**(code **)(**(int **)(param_5 + 0x38) + 8))();
    Node_set_style_slot(slotObj);
    slotObj = (**(code **)(**(int **)(param_5 + 0x3c) + 8))();
    Node_set_font_slot(slotObj);
    btnCap = 7;
    btnSize = 0;
    btnName = (void *)((uint)btnName & 0xffff0000);
    u16string_assignPtrLen(L"rightbutton",0xb);
    trylevel._0_1_ = 0xc;
    Widget_connectRecursive(&btnName,2,self,CharCreation_adjust_inc_0x19c,0,1);
    trylevel._0_1_ = 2;
    if (7 < btnCap) {
      operator_delete(btnName);
    }
    btnCap = 7;
    btnSize = 0;
    btnName = (void *)((uint)btnName & 0xffff0000);
    u16string_assignPtrLen(&PTR_006fccac,0);
    trylevel._0_1_ = 0xd;
    piVar6 = (int *)SmoothMeshShape_new_instance(&btnName);
    trylevel = CONCAT31(trylevel._1_3_,2);
    if (btnCap < 8) {
      btnCap = 7;
      btnSize = 0;
      btnName = (void *)((uint)btnName & 0xffff0000);
      iVar7 = 0;
      if (0 < (int)(piVar6[0x2b] - piVar6[0x2a] & 0xfffffffcU)) {
        do {
          std_vector_resize(4);
          iVar7 = iVar7 + 1;
        } while (iVar7 < piVar6[0x2b] - piVar6[0x2a] >> 2);
      }
      iVar7 = 0;
      if (0 < (int)(piVar6[0x57] - piVar6[0x56] & 0xfffffffcU)) {
        do {
          std_vector_resize_42bf80(4);
          iVar7 = iVar7 + 1;
        } while (iVar7 < piVar6[0x57] - piVar6[0x56] >> 2);
      }
      puVar1 = (undefined4 *)**(undefined4 **)(piVar6[0x2a] + piVar6[0x1f] * 4);
      *puVar1 = 0;
      puVar1[1] = 0;
      iVar7 = **(int **)(piVar6[0x2a] + piVar6[0x1f] * 4);
      *(undefined4 *)(iVar7 + 8) = 0x438c0000;
      *(undefined4 *)(iVar7 + 0xc) = 0;
      iVar7 = **(int **)(piVar6[0x2a] + piVar6[0x1f] * 4);
      *(undefined4 *)(iVar7 + 0x10) = 0x438c0000;
      *(undefined4 *)(iVar7 + 0x14) = 0x43160000;
      iVar7 = **(int **)(piVar6[0x2a] + piVar6[0x1f] * 4);
      *(undefined4 *)(iVar7 + 0x18) = 0;
      *(undefined4 *)(iVar7 + 0x1c) = 0x43160000;
      puVar1 = (undefined4 *)**(undefined4 **)(piVar6[0x56] + piVar6[0x4b] * 4);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      iVar7 = **(int **)(piVar6[0x56] + piVar6[0x4b] * 4);
      *(undefined4 *)(iVar7 + 0x10) = 0;
      *(undefined4 *)(iVar7 + 0x14) = 0;
      *(undefined4 *)(iVar7 + 0x18) = 0;
      *(undefined4 *)(iVar7 + 0x1c) = 0;
      iVar7 = **(int **)(piVar6[0x56] + piVar6[0x4b] * 4);
      *(undefined4 *)(iVar7 + 0x20) = 0;
      *(undefined4 *)(iVar7 + 0x24) = 0;
      *(undefined4 *)(iVar7 + 0x28) = 0;
      *(undefined4 *)(iVar7 + 0x2c) = 0;
      iVar7 = **(int **)(piVar6[0x56] + piVar6[0x4b] * 4);
      *(undefined4 *)(iVar7 + 0x30) = 0;
      *(undefined4 *)(iVar7 + 0x34) = 0;
      *(undefined4 *)(iVar7 + 0x38) = 0;
      *(undefined4 *)(iVar7 + 0x3c) = 0;
      local_40 = (void *)0x0;
      local_3c = 0;
      local_38 = 0;
      trylevel._0_1_ = 0xe;
      std_vector_resize_12(1);
      local_34 = 0;
      std_vector_push_back_4byte(&local_34);
      local_34 = 1;
      std_vector_push_back_4byte(&local_34);
      local_34 = 2;
      std_vector_push_back_4byte(&local_34);
      local_34 = 3;
      std_vector_push_back_4byte(&local_34);
      CharacterStyleWidget_rebuild_mesh(&local_40,1);
      CharacterStyleWidget_set_lod_level(0,1);
      (**(code **)(*piVar6 + 4))(1);
      nameCap = 7;
      nameSize = 0;
      nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
      u16string_assignPtrLen(&PTR_006fccac,0);
      trylevel._0_1_ = 0xf;
      iVar7 = NamedObject_create_with_defaults(0,piVar6,0,parent,nameBuf);
      trylevel._0_1_ = 0xe;
      if (7 < nameCap) {
        operator_delete(nameBuf[0]);
      }
      nameCap = 7;
      nameSize = 0;
      nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
      btnCap = 7;
      btnSize = 0;
      btnName = (void *)((uint)btnName & 0xffff0000);
      u16string_assignPtrLen(&PTR_006fccac,0);
      trylevel._0_1_ = 0x10;
      NamedObject_new_instance_0x160(iVar7,&btnName);
      trylevel = CONCAT31(trylevel._1_3_,0xe);
      if (7 < btnCap) {
        operator_delete(btnName);
      }
      btnCap = 7;
      btnSize = 0;
      btnName = (void *)((uint)btnName & 0xffff0000);
      plasma::Widget::MemberFunctionConnection<cube::CharacterStyleWidget>::ctor_0
                (2,self,CharCreation_apply_color_set,0,1,1);
      iVar2 = *(int *)(*(int *)(iVar7 + 0x38) + 0x68);
      iVar3 = *(int *)(*(int *)(iVar7 + 0x38) + 0x94);
      *(undefined4 *)(iVar3 + iVar2 * 8) = 0x41200000;
      *(undefined4 *)(iVar3 + 4 + iVar2 * 8) = 0x43480000;
      (**(code **)(**(int **)(iVar7 + 0x38) + 4))(1);
      if (local_40 == (void *)0x0) {
        ExceptionList = savedExceptionList;
        __security_check_cookie(cookieSaved ^ (uint)&stack0xfffffffc);
        return;
      }
      std_vector_destroy_ptr_elems_stride3(local_40,local_3c,&local_41,self);
      operator_delete(local_40);
    }
    operator_delete(btnName);
  }
  operator_delete(btnName);
}




/* cube::CharacterStyleWidget::vfunc_10 @ 0042bb00 */

void cube::CharacterStyleWidget::vfunc_10(void)

{
  float10 labelW;
  float10 elemW;
  undefined4 argA;
  undefined4 argB;
  
  Widget_setScroll(0x42c80000,0x41400000,1);
  argB = 1;
  argA = 0x41400000;
  labelW = (float10)Widget_measureGuarded(0x41400000,1);
  elemW = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)labelW - (float)elemW) - 15.0,argA,argB);
  Widget_setScroll(0x42c80000,0x42280000,1);
  argB = 1;
  argA = 0x42280000;
  labelW = (float10)Widget_measureGuarded(0x42280000,1);
  elemW = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)labelW - (float)elemW) - 15.0,argA,argB);
  Widget_setScroll(0x42c80000,0x42900000,1);
  argB = 1;
  argA = 0x42900000;
  labelW = (float10)Widget_measureGuarded(0x42900000,1);
  elemW = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)labelW - (float)elemW) - 15.0,argA,argB);
  Widget_setScroll(0x42c80000,0x42cc0000,1);
  argB = 1;
  argA = 0x42cc0000;
  labelW = (float10)Widget_measureGuarded(0x42cc0000,1);
  elemW = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)labelW - (float)elemW) - 15.0,argA,argB);
  Widget_setScroll(0x42c80000,0x43040000,1);
  argB = 1;
  argA = 0x43040000;
  labelW = (float10)Widget_measureGuarded(0x43040000,1);
  elemW = (float10)Widget_measureGuarded();
  Widget_setScroll(((float)labelW - (float)elemW) - 15.0,argA,argB);
  return;
}




/* [AUDIT] proposed: CharacterStyleWidget::rebuild_mesh  (confidence: high)
 * purpose: Rebuild smooth mesh (SmoothMeshShape_rebuild_buffers) then notify refcount if flag set
 * vars: param_2=notify; +0 vtbl
 */
/* Global::CharacterStyleWidget_rebuild_mesh @ 00642a20 */

void CharacterStyleWidget_rebuild_mesh(undefined4 material,char rebuild)

{
  int *self;
  
  CharacterStyleWidget_buildEdgeGraph(material);
  if (rebuild != '\0') {
    SmoothMeshShape_rebuild_buffers();
    (**(code **)(*self + 4))(1);
  }
  return;
}




/* [AUDIT] proposed: CharacterStyleWidget::set_lod_level  (confidence: high)
 * purpose: Clamp LOD/quality level to [0,6], store at +0x2c9, optionally rebuild
 * vars: material clamped; +0x2c9
 */
/* Global::CharacterStyleWidget_set_lod_level @ 00642a50 */

void CharacterStyleWidget_set_lod_level(int lod_level,char rebuild)

{
  int *self;
  
  if (lod_level < 0) {
    lod_level = 0;
  }
  if (6 < lod_level) {
    lod_level = 6;
  }
  self[0x2c9] = lod_level;
  if (rebuild != '\0') {
    SmoothMeshShape_rebuild_buffers();
    (**(code **)(*self + 4))(1);
  }
  return;
}




/* [AUDIT] proposed: SmoothMeshShape::new_instance  (confidence: high)
 * purpose: Factory: operator_new(0xc34) + plasma::SmoothMeshShape::ctor_0
 * vars: 0xc34
 */
/* Global::SmoothMeshShape_new_instance @ 00650260 */

undefined4 SmoothMeshShape_new_instance(undefined4 param_1)

{
  void *mem;
  undefined4 shape;
  undefined4 self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f661b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  mem = operator_new(0xc34);
  local_8 = 0;
  if (mem != (void *)0x0) {
    shape = plasma::SmoothMeshShape::ctor_0(self,param_1);
    ExceptionList = local_10;
    return shape;
  }
  ExceptionList = local_10;
  return 0;
}




/* [AUDIT] proposed: NamedObject::new_instance_0x160  (confidence: high)
 * purpose: Factory: operator_new(0x160) + plasma::NamedObject::ctor_4
 * vars: 0x160
 */
/* Global::NamedObject_new_instance_0x160 @ 006503e0 */

undefined4 NamedObject_new_instance_0x160(undefined4 param_1,undefined4 param_2)

{
  void *mem;
  undefined4 widget;
  undefined4 self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f661b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  mem = operator_new(0x160);
  local_8 = 0;
  if (mem != (void *)0x0) {
    widget = plasma::NamedObject::ctor_4(self,param_1,param_2);
    ExceptionList = local_10;
    return widget;
  }
  ExceptionList = local_10;
  return 0;
}




/* [AUDIT] proposed: CharacterStyleWidget::buildEdgeGraph  (confidence: low)
 * purpose: Rebuilds widget geometry: clears vertex/index vectors (0x158/0x100/0x1b0/0x2b8), walks polygon list at 0x86c inserting edges into maps
 * vars: edge keys (x,y) into map std_map_Insert_hint; body truncated; +0xa8 shared vertex buffer
 */
/* Global::CharacterStyleWidget_buildEdgeGraph @ 0066b200 */

void CharacterStyleWidget_buildEdgeGraph(undefined4 *result)

{
  char colorBit;
  int vertEnd;
  int **ppiVar3;
  int **ppiVar4;
  int *faceIdx;
  int vertBegin;
  int *piVar7;
  int **ppiVar8;
  int *piVar9;
  undefined4 *indices;
  int self;
  uint indexCount;
  int *facePtr;
  int vertIdx;
  undefined1 local_74 [8];
  void *local_6c;
  undefined4 edgeB;
  undefined4 local_64;
  undefined1 edgeA [8];
  int idxA;
  int idxB;
  undefined4 local_50;
  undefined4 local_4c;
  int *edgeMap;
  int edgeMapCount;
  undefined4 local_40;
  undefined4 local_3c;
  int *edgeEntry;
  int *nextIdx;
  int *edgeNode;
  int *edgeKeyA;
  int *edgeKeyB;
  int *faceOffset;
  int *faceIdx2;
  int selfCopy;
  int *faceList;
  int *local_14;
  void *savedExceptionList;
  undefined1 *sehHandler;
  int ehState;
  
  ehState = 0xffffffff;
  sehHandler = &LAB_006f7e00;
  savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;
  vertIdx = 0;
  vertEnd = ((int *)**(int **)(self + 0xa8))[1];
  vertBegin = *(int *)**(int **)(self + 0xa8);
  selfCopy = self;
  if (0 < (int)(*(int *)(self + 0x15c) - *(int *)(self + 0x158) & 0xfffffffcU)) {
    do {
      std_vector_resize_42bf80(vertEnd - vertBegin >> 3);
      vertIdx = vertIdx + 1;
    } while (vertIdx < *(int *)(self + 0x15c) - *(int *)(self + 0x158) >> 2);
  }
  vertIdx = 0;
  vertEnd = ((int *)**(int **)(self + 0xa8))[1];
  vertBegin = *(int *)**(int **)(self + 0xa8);
  if (0 < (int)(*(int *)(self + 0x104) - *(int *)(self + 0x100) & 0xfffffffcU)) {
    do {
      std_vector_resize(vertEnd - vertBegin >> 3);
      vertIdx = vertIdx + 1;
    } while (vertIdx < *(int *)(self + 0x104) - *(int *)(self + 0x100) >> 2);
  }
  vertIdx = 0;
  vertEnd = ((int *)**(int **)(self + 0xa8))[1];
  vertBegin = *(int *)**(int **)(self + 0xa8);
  if (0 < (int)(*(int *)(self + 0x1b4) - *(int *)(self + 0x1b0) & 0xfffffffcU)) {
    do {
      std_vector_resize_42bf80(vertEnd - vertBegin >> 3);
      vertIdx = vertIdx + 1;
    } while (vertIdx < *(int *)(self + 0x1b4) - *(int *)(self + 0x1b0) >> 2);
  }
  vertIdx = 0;
  vertEnd = ((int *)**(int **)(self + 0xa8))[1];
  vertBegin = *(int *)**(int **)(self + 0xa8);
  if (0 < (int)(*(int *)(self + 700) - *(int *)(self + 0x2b8) & 0xfffffffcU)) {
    do {
      vectorInt_resize(vertEnd - vertBegin >> 3);
      vertIdx = vertIdx + 1;
    } while (vertIdx < *(int *)(self + 700) - *(int *)(self + 0x2b8) >> 2);
  }
  vectorInt_resize(((int *)**(int **)(self + 0xa8))[1] - *(int *)**(int **)(self + 0xa8) >> 3);
  vectorInt_resize(((int *)**(int **)(self + 0xa8))[1] - *(int *)**(int **)(self + 0xa8) >> 3);
  faceList = (int *)(self + 0x86c);
  std_vector_assign_range_stride0xc(result);
  result = (undefined4 *)(self + 0x8d0);
  std_list_clear_67e480();
  faceIdx2 = (int *)0x0;
  if (0 < (faceList[1] - *faceList) / 0xc) {
    faceOffset = (int *)0x0;
    do {
      faceIdx = faceIdx2;
      facePtr = (int *)(*faceList + (int)faceOffset);
      edgeNode = facePtr;
      indices = (undefined4 *)*facePtr;
      indexCount = facePtr[1] - (int)indices >> 2;
      faceIdx2 = faceIdx;
      if (1 < indexCount) {
        if (indexCount == 2) {
          local_40 = *indices;
          local_3c = indices[1];
          std_map_Insert_hint(edgeA,0,&local_40,DAT_0076decc);
          local_50 = ((undefined4 *)*facePtr)[1];
          local_4c = *(undefined4 *)*facePtr;
          std_map_Insert_hint(&edgeB,0,&local_50,DAT_0076decc);
          faceIdx2 = faceIdx;
        }
        else {
          facePtr = (int *)0x0;
          if (0 < (int)indexCount) {
            do {
              vertEnd = indices[(int)facePtr];
              nextIdx = (int *)((int)facePtr + 1);
              vertBegin = indices[(uint)((int)facePtr + 1) % indexCount];
              faceIdx = (int *)*result;
              colorBit = *(char *)(faceIdx[1] + 0xd);
              facePtr = faceIdx;
              piVar9 = (int *)faceIdx[1];
              while (colorBit == '\0') {
                if ((piVar9[4] < vertBegin) || ((piVar9[4] <= vertBegin && (piVar9[5] < vertEnd)))) {
                  piVar7 = (int *)piVar9[2];
                }
                else {
                  piVar7 = (int *)*piVar9;
                  facePtr = piVar9;
                }
                piVar9 = piVar7;
                colorBit = *(char *)((int)piVar7 + 0xd);
              }
              if (((facePtr == faceIdx) || (vertBegin < facePtr[4])) ||
                 ((vertBegin <= facePtr[4] && (vertEnd < facePtr[5])))) {
                edgeKeyA = faceIdx;
                ppiVar8 = &edgeKeyA;
              }
              else {
                edgeKeyB = facePtr;
                ppiVar8 = &edgeKeyB;
              }
              if (*ppiVar8 == faceIdx) {
                idxA = vertEnd;
                idxB = vertBegin;
                std_map_Insert_hint(local_74,0,&idxA,DAT_0076decc);
              }
              else {
                rbtree_eraseNode(&edgeEntry,*ppiVar8);
              }
              indices = (undefined4 *)*edgeNode;
              indexCount = edgeNode[1] - (int)indices >> 2;
              facePtr = nextIdx;
            } while ((int)nextIdx < (int)indexCount);
          }
        }
      }
      faceIdx2 = (int *)((int)faceIdx2 + 1);
      faceOffset = (int *)((int)faceOffset + 0xc);
    } while ((int)faceIdx2 < (faceList[1] - *faceList) / 0xc);
  }
  edgeMap = (int *)0x0;
  edgeMapCount = 0;
  edgeMap = (int *)rbtree_allocHeaderNode_1c();
  ehState = 0;
  faceOffset = (int *)0x0;
  if (0 < (faceList[1] - *faceList) / 0xc) {
    result = (undefined4 *)0x0;
    do {
      vertEnd = *faceList;
      vertBegin = *(int *)(vertEnd + (int)result);
      faceIdx2 = (int *)(vertEnd + (int)result);
      indexCount = *(int *)(vertEnd + 4 + (int)result) - vertBegin >> 2;
      if ((1 < indexCount) && (faceIdx = (int *)0x0, 0 < (int)indexCount)) {
        do {
          edgeKeyA = *(int **)(vertBegin + (int)faceIdx * 4);
          edgeEntry = (int *)((int)faceIdx + 1);
          facePtr = *(int **)(selfCopy + 0x8d0);
          colorBit = *(char *)(facePtr[1] + 0xd);
          edgeKeyB = *(int **)(vertBegin + ((uint)((int)faceIdx + 1) % indexCount) * 4);
          faceIdx = facePtr;
          piVar9 = (int *)facePtr[1];
          while (colorBit == '\0') {
            if ((piVar9[4] < (int)edgeKeyA) ||
               ((piVar9[4] <= (int)edgeKeyA && (piVar9[5] < (int)edgeKeyB)))) {
              piVar7 = (int *)piVar9[2];
            }
            else {
              piVar7 = (int *)*piVar9;
              faceIdx = piVar9;
            }
            piVar9 = piVar7;
            colorBit = *(char *)((int)piVar7 + 0xd);
          }
          if (((faceIdx == facePtr) || ((int)edgeKeyA < faceIdx[4])) ||
             (((int)edgeKeyA <= faceIdx[4] && ((int)edgeKeyB < faceIdx[5])))) {
            edgeNode = facePtr;
            ppiVar8 = &edgeNode;
          }
          else {
            nextIdx = faceIdx;
            ppiVar8 = &nextIdx;
          }
          if (*ppiVar8 != facePtr) {
            faceIdx = (int *)std_map_operator_667a90(&edgeKeyA);
            vertEnd = *faceIdx;
            vertBegin = IntMap_SetScalar(vertEnd,*(undefined4 *)(vertEnd + 4),&edgeKeyB);
            if (faceIdx[1] == 0x15555554) {
              std::_Xlength_error("list<T> too long");
            }
            faceIdx[1] = faceIdx[1] + 1;
            *(int *)(vertEnd + 4) = vertBegin;
            **(int **)(vertBegin + 4) = vertBegin;
          }
          vertBegin = *faceIdx2;
          indexCount = faceIdx2[1] - vertBegin >> 2;
          faceIdx = edgeEntry;
        } while ((int)edgeEntry < (int)indexCount);
      }
      result = (undefined4 *)((int)result + 0xc);
      faceOffset = (int *)((int)faceOffset + 1);
    } while ((int)faceOffset < (faceList[1] - *faceList) / 0xc);
  }
  result = (undefined4 *)(selfCopy + 0x8d8);
  for (indices = (undefined4 *)*result; indices != *(undefined4 **)(selfCopy + 0x8dc);
      indices = indices + 3) {
    if ((void *)*indices != (void *)0x0) {
      operator_delete((void *)*indices);
    }
  }
  *(undefined4 *)(selfCopy + 0x8dc) = *result;
  do {
    if (edgeMapCount == 0) {
      ehState = 0xffffffff;
      Sprite_map_erase_range(&result,*edgeMap,edgeMap);
      operator_delete(edgeMap);
    }
    local_6c = (void *)0x0;
    edgeB = 0;
    local_64 = 0;
    ehState._1_3_ = (uint3)((uint)ehState >> 8);
    ehState._0_1_ = 1;
    std_vector_push_back_move_0xc(&local_6c);
    ehState = (uint)ehState._1_3_ << 8;
    if (local_6c != (void *)0x0) {
      operator_delete(local_6c);
    }
    faceIdx = (int *)*faceList;
    if (((faceList[1] - (int)faceIdx) / 0xc == 1) && ((int *)*faceIdx != (int *)faceIdx[1])) {
      if (*(char *)(edgeMap[1] + 0xd) == '\0') {
        vertEnd = *(int *)*faceIdx;
        facePtr = (int *)edgeMap[1];
        piVar9 = edgeMap;
        do {
          if (facePtr[4] < vertEnd) {
            piVar7 = (int *)facePtr[2];
          }
          else {
            piVar7 = (int *)*facePtr;
            piVar9 = facePtr;
          }
          facePtr = piVar7;
        } while (*(char *)((int)piVar7 + 0xd) == '\0');
        if ((piVar9 == edgeMap) || (vertEnd < piVar9[4])) goto LAB_0066b7b9;
        edgeEntry = piVar9;
        ppiVar8 = &edgeEntry;
      }
      else {
LAB_0066b7b9:
        nextIdx = edgeMap;
        ppiVar8 = &nextIdx;
      }
      if (*ppiVar8 == edgeMap) goto LAB_0066b7c9;
      faceIdx2 = *(int **)*faceIdx;
      local_14 = faceIdx2;
    }
    else {
LAB_0066b7c9:
      faceIdx2 = *(int **)(*edgeMap + 0x10);
      local_14 = faceIdx2;
    }
    do {
      faceIdx = local_14;
      facePtr = (int *)edgeMap[1];
      piVar9 = edgeMap;
      if (*(char *)(edgeMap[1] + 0xd) == '\0') {
        do {
          if (facePtr[4] < (int)local_14) {
            piVar7 = (int *)facePtr[2];
          }
          else {
            piVar7 = (int *)*facePtr;
            piVar9 = facePtr;
          }
          facePtr = piVar7;
        } while (*(char *)((int)piVar7 + 0xd) == '\0');
        if ((piVar9 == edgeMap) || ((int)local_14 < piVar9[4])) goto LAB_0066b805;
        edgeNode = piVar9;
        ppiVar8 = &edgeNode;
      }
      else {
LAB_0066b805:
        edgeKeyA = edgeMap;
        ppiVar8 = &edgeKeyA;
      }
      if (*ppiVar8 == edgeMap) break;
      piVar9 = (int *)std_map_operator_667a90(&local_14);
      facePtr = *(int **)*piVar9;
      faceOffset = (int *)facePtr[2];
      if (facePtr != (int *)*piVar9) {
        *(int *)facePtr[1] = *facePtr;
        *(int *)(*facePtr + 4) = facePtr[1];
        operator_delete(facePtr);
      }
      if (piVar9[1] == 0) {
        indices = (undefined4 *)std_map_equal_range(local_74,&local_14);
        Sprite_map_erase_range(&local_3c,*indices,indices[1]);
      }
      vertEnd = *(int *)(selfCopy + 0x8dc);
      ppiVar8 = *(int ***)(vertEnd + -8);
      if ((&local_14 < ppiVar8) && (ppiVar3 = *(int ***)(vertEnd + -0xc), ppiVar3 <= &local_14)) {
        ppiVar4 = *(int ***)(vertEnd + -4);
        if ((ppiVar8 == ppiVar4) && ((int)ppiVar4 - (int)ppiVar8 >> 2 == 0)) {
          vertBegin = (int)ppiVar8 - (int)ppiVar3 >> 2;
          if (vertBegin == 0x3fffffff) {
LAB_0066b97d:
            std::_Xlength_error("vector<T> too long");
          }
          edgeKeyB = (int *)(vertBegin + 1);
          indexCount = (int)ppiVar4 - (int)ppiVar3 >> 2;
          if (0x3fffffff - (indexCount >> 1) < indexCount) {
            faceIdx = (int *)0x0;
          }
          else {
            faceIdx = (int *)(indexCount + (indexCount >> 1));
          }
          if (faceIdx < edgeKeyB) {
            faceIdx = edgeKeyB;
          }
          std_vector_grow_realloc_stride4(faceIdx);
        }
        if (*(undefined4 **)(vertEnd + -8) != (undefined4 *)0x0) {
          **(undefined4 **)(vertEnd + -8) =
               *(undefined4 *)(*(int *)(vertEnd + -0xc) + ((int)&local_14 - (int)ppiVar3 >> 2) * 4);
        }
      }
      else {
        ppiVar3 = *(int ***)(vertEnd + -4);
        if ((ppiVar8 == ppiVar3) && ((int)ppiVar3 - (int)ppiVar8 >> 2 == 0)) {
          vertBegin = (int)ppiVar8 - *(int *)(vertEnd + -0xc) >> 2;
          if (vertBegin == 0x3fffffff) goto LAB_0066b97d;
          edgeKeyB = (int *)(vertBegin + 1);
          indexCount = (int)ppiVar3 - *(int *)(vertEnd + -0xc) >> 2;
          if (0x3fffffff - (indexCount >> 1) < indexCount) {
            facePtr = (int *)0x0;
          }
          else {
            facePtr = (int *)(indexCount + (indexCount >> 1));
          }
          if (facePtr < edgeKeyB) {
            facePtr = edgeKeyB;
          }
          std_vector_grow_realloc_stride4(facePtr);
        }
        if (*(undefined4 **)(vertEnd + -8) != (undefined4 *)0x0) {
          **(undefined4 **)(vertEnd + -8) = faceIdx;
        }
      }
      *(int *)(vertEnd + -8) = *(int *)(vertEnd + -8) + 4;
      local_14 = faceOffset;
    } while (faceOffset != faceIdx2);
  } while( true );
}




