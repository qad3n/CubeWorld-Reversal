// WorldPreviewWidget (ui) — cube. 1 functions. Bodies = Ghidra pseudo-C.
#include "WorldPreviewWidget.h"

/* cube::WorldPreviewWidget::ctor_0 @ 00605a20 */

void cube::WorldPreviewWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 arg)

{
  undefined4 *self;
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
                    /* WARNING: Subroutine does not return */
    operator_delete(local_28[0]);
  }
  self[0x5a] = arg;
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  self[0x59] = 0;
  ExceptionList = local_10;
  return;
}




