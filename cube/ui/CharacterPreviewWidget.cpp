// CharacterPreviewWidget (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "CharacterPreviewWidget.h"

/* cube::CharacterPreviewWidget::ctor_0 @ 00424e80 */

void cube::CharacterPreviewWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *self;
  void *nameBuf [4];
  undefined4 nameCap;
  uint stackCookie;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006f0eb8;
  savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;
  stackCookie = 7;
  nameCap = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,nameBuf);
  if (7 < stackCookie) {
    operator_delete(nameBuf[0]);
  }
  self[0x59] = param_3;
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  ExceptionList = savedExceptionList;
  return;
}




/* cube::CharacterPreviewWidget::vfunc_5 @ 004c59a0 */

undefined1 cube::CharacterPreviewWidget::vfunc_5(float *pPoint)

{
  float w;
  
  if ((0.0f <= *pPoint) && (0.0f <= pPoint[1])) {
    w = (float)Widget_measureGuarded();
    if (*pPoint <= (float)w && (float)w != *pPoint) {
      w = (float)Widget_measure();
      if (pPoint[1] <= (float)w && (float)w != pPoint[1]) {
        return 1;
      }
    }
  }
  return 0;
}




