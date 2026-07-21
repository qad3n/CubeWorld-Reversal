// CharacterWidget (ui) — cube. 1 functions. Bodies = Ghidra pseudo-C.
#include "CharacterWidget.h"

/* cube::CharacterWidget::ctor_0 @ 00434d90 */

void cube::CharacterWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *self;
  void *nameBuf [4];
  undefined4 nameLen;
  uint nameCap;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f0eb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  nameCap = 7;
  nameLen = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,nameBuf);
  if (7 < nameCap) {
                    /* WARNING: Subroutine does not return */
    operator_delete(nameBuf[0]);
  }
  self[0x58] = param_3;
  *self = vftable;
  self[9] = vftable;
  ExceptionList = local_10;
  return;
}




