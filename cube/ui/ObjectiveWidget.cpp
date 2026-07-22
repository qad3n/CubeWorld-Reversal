// ObjectiveWidget (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "ObjectiveWidget.h"

/* cube::ObjectiveWidget::ctor_0 @ 004ce180 */

void cube::ObjectiveWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  void *local_28 [4];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f0eb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 7;
  local_18 = 0;
  local_28[0] = (void *)((uint)local_28[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,local_28);
  if (7 < local_14) {
    operator_delete(local_28[0]);
  }
  *in_ECX = vftable;
  in_ECX[9] = vftable;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x5a] = 0;
  in_ECX[0x5b] = param_3;
  ExceptionList = local_10;
  return;
}




/* cube::ObjectiveWidget::vfunc_0 @ 004ce240 */

void cube::ObjectiveWidget::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  if (*(void **)((int)in_ECX + 0x160) != (void *)0x0) {
    operator_delete(*(void **)((int)in_ECX + 0x160));
  }
  plasma::Widget::ctor_0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




