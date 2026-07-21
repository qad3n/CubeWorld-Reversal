// BlueprintPreviewWidget (ui) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "BlueprintPreviewWidget.h"

/* cube::BlueprintPreviewWidget::ctor_0 @ 0042f190 */

void cube::BlueprintPreviewWidget::ctor_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  uint stackCookie;
  undefined4 iconObj;
  undefined4 *self;
  void *nameBuf [4];
  undefined4 nameSize;
  uint nameCap;
  void *iconBuf [5];
  uint iconCap;
  uint cookieSaved;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006e2226;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExceptionList;
  nameCap = 7;
  nameSize = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  cookieSaved = stackCookie;
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,nameBuf);
  if (7 < nameCap) {
                    /* WARNING: Subroutine does not return */
    operator_delete(nameBuf[0]);
  }
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0xc2f00000;
  self[0x59] = 0;
  self[0x5a] = 0;
  state_initA(stackCookie);
  self[0xa5] = param_3;
  self[0xa6] = param_4;
  self[0xa7] = param_5;
  self[0xa8] = param_6;
  self[0xa9] = 0;
  self[0xaa] = 0xffffffff;
  *(undefined2 *)(self + 0xaf) = 1;
  trylevel = CONCAT31(trylevel._1_3_,3);
  *(undefined2 *)(self + 0xab) = 0;
  self[0xac] = 0;
  self[0xad] = 0;
  *(undefined2 *)(self + 0xae) = 0;
  *(undefined1 *)((int)self + 0x2ba) = 0;
  self[0xf0] = 0;
  memset(self + 0xb0,0,0x100);
  *(undefined1 *)(self + 0xf1) = 0;
  if (self[0xa7] != 0) {
    Node_detach_from_parent(param_2);
  }
  if (self[0xa8] != 0) {
    Node_detach_from_parent(param_2);
    u16string_assignCStr(&DAT_006fd41c);
    trylevel = CONCAT31(trylevel._1_3_,4);
    iconObj = Node_find_child_by_name_recursive(iconBuf);
    self[0xa9] = iconObj;
    if (7 < iconCap) {
                    /* WARNING: Subroutine does not return */
      operator_delete(iconBuf[0]);
    }
  }
  ExceptionList = savedExceptionList;
  __security_check_cookie(cookieSaved ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::BlueprintPreviewWidget::vfunc_0 @ 0042f5e0 */

void cube::BlueprintPreviewWidget::vfunc_0(byte deleteFlag)

{
  void *self;
  
  if (*(void **)((int)self + 0x288) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)((int)self + 0x288));
  }
  plasma::Widget::ctor_0();
  if ((deleteFlag & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(self);
  }
  return;
}




/* cube::BlueprintPreviewWidget::vfunc_10 @ 004348f0 */

void cube::BlueprintPreviewWidget::vfunc_10(void)

{
  int child;
  int self;
  float10 fVar2;
  float10 fVar3;
  float width;
  float height;
  undefined4 argA;
  undefined4 argB;
  
  child = *(int *)(self + 0x298);
  if (child != 0) {
    if (*(int *)(child + 0x28) != *(int *)(*(int *)(self + 0x148) + 0x28)) {
      Node_detach_or_remove_child(child,*(int *)(self + 0x148));
    }
    argB = 1;
    argA = 0x42b40000;
    fVar2 = (float10)Widget_measureGuarded(0x42b40000,1);
    fVar3 = (float10)Widget_measureGuarded();
    Widget_setScroll(((float)fVar2 - (float)fVar3) * 0.5,argA,argB);
  }
  if (*(int *)(self + 0x29c) != 0) {
    argA = 1;
    fVar2 = (float10)Widget_measure(1);
    fVar3 = (float10)Widget_measure();
    width = ((float)fVar2 - (float)fVar3) - 20.0;
    fVar2 = (float10)Widget_measureGuarded(width);
    fVar3 = (float10)Widget_measureGuarded();
    Widget_setScroll(((float)fVar2 - (float)fVar3) - 20.0,width,argA);
  }
  if ((*(int *)(self + 0x2a0) != 0) && (*(int *)(self + 0x29c) != 0)) {
    argA = 1;
    fVar2 = (float10)Widget_measure(1);
    width = (float)fVar2;
    fVar2 = (float10)Widget_measureGuarded(width);
    fVar3 = (float10)Widget_measureGuarded();
    height = (((float)fVar2 - (float)fVar3) - 40.0) - 10.0;
    fVar2 = (float10)Widget_measure(height);
    fVar3 = (float10)Widget_measure();
    Widget_layoutChildrenGuarded(0x41a00000,((float)fVar2 - (float)fVar3) - 20.0,height,width,argA);
  }
  return;
}




