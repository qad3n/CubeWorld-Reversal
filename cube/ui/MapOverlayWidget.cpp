// MapOverlayWidget (ui) — cube. 1 functions. Bodies = Ghidra pseudo-C.
#include "MapOverlayWidget.h"

/* cube::MapOverlayWidget::ctor_0 @ 004c95a0 */

void cube::MapOverlayWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
                    /* WARNING: Subroutine does not return */
    operator_delete(local_28[0]);
  }
  in_ECX[0x58] = param_3;
  *in_ECX = vftable;
  in_ECX[9] = vftable;
  ExceptionList = local_10;
  return;
}




