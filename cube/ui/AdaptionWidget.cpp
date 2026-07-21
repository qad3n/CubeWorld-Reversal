// AdaptionWidget (ui) — cube. 58 functions. Bodies = Ghidra pseudo-C.
#include "AdaptionWidget.h"

/* cube::AdaptionWidget::ctor_0 @ 0040ecd0 */

void cube::AdaptionWidget::ctor_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
               undefined4 param_5)

{
  uint stackCookie;
  int iconObj;
  undefined4 tmp;
  undefined4 *self;
  void *nameBuf [4];
  undefined4 nameCap;
  uint nameSize;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006e1a90;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExceptionList;
  nameSize = 7;
  nameCap = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,nameBuf);
  trylevel = CONCAT31(trylevel._1_3_,2);
  if (7 < nameSize) {
    operator_delete(nameBuf[0]);
  }
  self[0x58] = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  *self = vftable;
  self[9] = vftable;
  self[0x59] = 0xffffffff;
  self[0x5a] = 0xffffffff;
  self[0x5b] = param_3;
  nameSize = 7;
  nameCap = 0;
  self[0x5c] = param_4;
  self[0x5d] = param_5;
  if (param_4 != 0) {
    iconObj = Node_clone_subtree_v2(param_2);
    self[0x5c] = iconObj;
    tmp = (**(code **)(**(int **)(iconObj + 0x38) + 8))(stackCookie);
    Node_set_style_slot(tmp);
    tmp = (**(code **)(**(int **)(self[0x5c] + 0x3c) + 8))();
    Node_set_font_slot(tmp);
  }
  if (self[0x5d] != 0) {
    iconObj = Node_clone_subtree_v2(param_2);
    self[0x5d] = iconObj;
    tmp = (**(code **)(**(int **)(iconObj + 0x38) + 8))();
    Node_set_style_slot(tmp);
    tmp = (**(code **)(**(int **)(self[0x5d] + 0x3c) + 8))();
    Node_set_font_slot(tmp);
  }
  ExceptionList = savedExceptionList;
  return;
}




/* cube::AdaptionWidget::vfunc_1_0040f8f0 @ 0040f8f0 */

void cube::AdaptionWidget::vfunc_1_0040f8f0(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int targetEntity;
  int iVar7;
  undefined8 *puVar8;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar9;
  undefined4 *puVar10;
  undefined4 *self;
  undefined8 *puVar11;
  float10 fVar12;
  double dVar13;
  float fVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  char *pcVar23;
  int iStack_454;
  undefined **local_450 [4];
  undefined *local_440 [2];
  undefined **local_438 [3];
  undefined4 *local_42c;
  undefined4 local_400;
  uint local_3fc;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_3e8 [72];
  int local_3a0;
  float local_39c;
  float screenY;
  undefined4 *selfSaved;
  float *coinPtr;
  undefined1 local_38c [16];
  undefined2 local_37c;
  void *local_274 [5];
  uint local_260;
  void *local_25c [4];
  undefined4 local_24c;
  uint local_248;
  undefined4 local_244;
  undefined4 local_240;
  float local_23c;
  float screenX;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  void *local_224 [2];
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  uint local_210;
  undefined4 local_20c;
  undefined4 uStack_208;
  undefined4 local_204;
  undefined4 uStack_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 uStack_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  uint local_1d8;
  undefined8 local_1d4 [32];
  undefined8 local_d4 [24];
  uint stackCookie;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006e1c1e;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExceptionList;
  coinPtr = (float *)0x0;
  selfSaved = self;
  targetEntity = getTargetEntity(stackCookie);
  local_3a0 = targetEntity;
  if (targetEntity == 0) {
    targetEntity = *(int *)(*(int *)((int)self + 0x174) + 0x3c);
    *(undefined4 *)(*(int *)(targetEntity + 0x94) + *(int *)(targetEntity + 0x68) * 4) = 0;
  }
  else {
    iVar7 = *(int *)((int)self + 0x148);
    iVar2 = *(int *)(*(int *)(iVar7 + 0x38) + 0x170);
    iVar3 = *(int *)(*(int *)(iVar7 + 0x38) + 0x19c);
    fVar14 = *(float *)(iVar3 + 4 + iVar2 * 8);
    fVar1 = *(float *)(iVar3 + iVar2 * 8);
    screenY = 1.0 / (fVar1 * *(float *)(iVar7 + 0x54) + fVar14 * *(float *)(iVar7 + 100) +
                      *(float *)(iVar7 + 0x84));
    screenX = screenY *
                (fVar1 * *(float *)(iVar7 + 0x48) + fVar14 * *(float *)(iVar7 + 0x58) +
                *(float *)(iVar7 + 0x78));
    screenY = screenY *
                (fVar14 * *(float *)(iVar7 + 0x5c) + fVar1 * *(float *)(iVar7 + 0x4c) +
                *(float *)(iVar7 + 0x7c));
    iVar7 = GameController_item_icon_id(targetEntity);
    if (iVar7 != 0) {
      piVar4 = *(int **)(*(int *)((int)self + 0x16c) + 0x134);
      (**(code **)(*piVar4 + 0xe4))(piVar4,7,1);
      local_20c = 0;
      uStack_208 = 0;
      local_204 = 0;
      uStack_200 = 0;
      local_1f8 = 0;
      uStack_1f4 = 0;
      local_1f0 = 0;
      puVar8 = local_d4;
      puVar11 = local_1d4;
      targetEntity = 0x10;
      do {
        *puVar11 = 0;
        *puVar8 = 0;
        puVar11[1] = 0;
        *(undefined4 *)(puVar8 + 1) = 0;
        puVar11 = puVar11 + 2;
        puVar8 = (undefined8 *)((int)puVar8 + 0xc);
        targetEntity = targetEntity + -1;
      } while (targetEntity != 0);
      render_bindNodeTransformA();
      render_uploadBoneMatrices(local_1d4,local_d4);
      local_1fc = 0x3f800000;
      local_1f8 = 0x3f800000;
      uStack_1f4 = 0x3f800000;
      local_1f0 = 0x3f800000;
      render_setUniform30(&local_1fc);
      local_39c = (float)(*(int *)((int)self + 0x16c) + 0x800a1c);
      targetEntity = AdaptionWidget_getContentSize(&local_204);
      coinPtr = (float *)AdaptionWidget_getContentSize(&uStack_1f4);
      uVar21 = 0;
      uVar18 = 0x3d75c28f;
      iVar7 = local_3a0;
      fVar12 = (float10)Widget_measure(local_39c,0x3d75c28f,local_3a0,0);
      fVar14 = (float)fVar12 * 0.5 + *(float *)(targetEntity + 4) + screenY;
      targetEntity = (int)local_39c;
      local_39c = (float)fVar12;
      fVar12 = (float10)Widget_measureGuarded(fVar14);
      screenY = (float)fVar12;
      drawBillboardModelRotated(screenY * 0.5 + screenX + *coinPtr,fVar14,targetEntity,uVar18,iVar7,uVar21);
      self = selfSaved;
      targetEntity = local_3a0;
    }
    piVar4 = *(int **)(*(int *)((int)self + 0x16c) + 0x134);
    (**(code **)(*piVar4 + 0xe4))(piVar4,7,0);
    cube::GameController::drawItemTooltip
              (targetEntity,0xf,0xb4,0x3f800000,300,1,0,0);
    entityState_copy(targetEntity);
    local_37c = *(undefined2 *)(*(int *)(*(int *)((int)self + 0x16c) + 0x8006d0) + 400);
    fVar12 = (float10)security_cookie_guard_b(0xb4,0x3f800000,300,0,0,0);
    coinPtr = (float *)(float)fVar12;
    cube::GameController::drawItemTooltip
              (local_38c,(int)((float)coinPtr * 0.5 + 50.0));
    targetEntity = *(int *)(*(int *)((int)self + 0x174) + 0x3c);
    *(undefined4 *)(*(int *)(targetEntity + 0x94) + *(int *)(targetEntity + 0x68) * 4) = 1;
  }
  local_450[0] = &PTR_006fcd00;
  local_440[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_3e8);
  trylevel = 0;
  coinPtr = (float *)0x1;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_450,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438);
  trylevel = 1;
  *(undefined ***)((int)local_450 + (int)local_450[0][1]) =
       std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_454 + (int)local_450[0][1]) = local_450[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438);
  local_438[0] = std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
                 vftable;
  local_400 = 0;
  local_3fc = 0;
  trylevel = 3;
  wostream_insertWide(local_440,L"Adaption");
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 4;
  uVar18 = u16_ostrstream_str_wrap(local_224);
  trylevel._0_1_ = 5;
  local_1fc = 0;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_20c = 0;
  uStack_208 = 0;
  local_204 = 0;
  uStack_200 = 0x3f800000;
  local_244 = 0x3f800000;
  local_240 = 0x3f800000;
  local_23c = 1.0;
  screenX = 1.0;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,0x41700000,0x41c80000,0x41400000,0x40400000,&local_244,
               &local_20c,&local_1fc,0,0xbf800000,1);
  if (7 < local_210) {
    operator_delete(local_224[0]);
  }
  local_210 = 7;
  local_214 = 0;
  local_224[0] = (void *)((uint)local_224[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 6;
  uVar18 = u16_ostrstream_str_wrap(local_224);
  local_1fc = 0;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_20c = 0;
  uStack_208 = 0;
  local_204 = 0;
  uStack_200 = 0;
  local_244 = 0x3f800000;
  local_240 = 0x3f800000;
  local_23c = 1.0;
  screenX = 1.0;
  trylevel._0_1_ = 7;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,0x41700000,0x41c80000,0x41400000,0,&local_244,&local_20c,
               &local_1fc,0,0xbf800000,1);
  if (7 < local_210) {
    operator_delete(local_224[0]);
  }
  local_210 = 7;
  local_214 = 0;
  local_224[0] = (void *)((uint)local_224[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel._0_1_ = 8;
  if ((local_3fc & 1) != 0) {
    operator_delete((void *)*local_42c);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438,(wchar_t *)0x0,
             (wchar_t *)0x0);
  local_3fc = local_3fc & 0xfffffffe;
  puVar10 = &local_1ec;
  if (7 < local_1d8) {
    puVar10 = local_1ec;
  }
  local_400 = 0;
  strstreambuf_init(puVar10,local_1dc,local_3fc);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  wostream_insertNarrow(local_440,"Adapt");
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 9;
  uVar18 = u16_ostrstream_str_wrap(local_224);
  uVar22 = 1;
  local_1fc = 0;
  uVar20 = 0xbf800000;
  uVar19 = 1;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_20c = 0;
  uStack_208 = 0;
  local_204 = 0;
  uStack_200 = 0x3f800000;
  local_244 = 0x3f800000;
  local_240 = 0x3f800000;
  local_23c = 1.0;
  screenX = 1.0;
  puVar10 = &local_1fc;
  puVar17 = &local_20c;
  puVar16 = &local_244;
  uVar15 = 0x40400000;
  trylevel._0_1_ = 10;
  uVar21 = 0x41400000;
  fVar12 = (float10)security_cookie_guard_a(0x41400000,0x40400000,puVar16,puVar17,puVar10,1,0xbf800000,1);
  coinPtr = (float *)(float)fVar12;
  fVar14 = (float)coinPtr - 20.0;
  fVar12 = (float10)security_cookie_guard_b(fVar14);
  coinPtr = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,(float)coinPtr / 3.0,fVar14,uVar21,uVar15,puVar16,puVar17,
               puVar10,uVar19,uVar20,uVar22);
  if (7 < local_210) {
    operator_delete(local_224[0]);
  }
  local_210 = 7;
  local_214 = 0;
  local_224[0] = (void *)((uint)local_224[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  if (local_3a0 == 0) {
    local_1fc = 0x3f333333;
    local_1f8 = 0x3f333333;
    uStack_1f4 = 0x3f333333;
    local_1f0 = 0x3f800000;
    selfSaved = &local_1fc;
  }
  else {
    cVar5 = proximityCheck();
    uStack_208 = 0x3f800000;
    local_204 = 0x3f800000;
    uStack_200 = 0x3f800000;
    local_20c = 0;
    if (cVar5 == '\0') {
      local_20c = 0x3f800000;
    }
    local_244 = local_20c;
    local_240 = 0x3f800000;
    local_23c = 1.0;
    screenX = 1.0;
    selfSaved = &local_244;
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 0xb;
  uVar18 = u16_ostrstream_str_wrap(local_25c);
  uVar22 = 1;
  local_234 = 0;
  uVar20 = 0xbf800000;
  uVar19 = 1;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0;
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  puVar10 = &local_234;
  puVar17 = &local_21c;
  trylevel._0_1_ = 0xc;
  uVar15 = 0;
  uVar21 = 0x41400000;
  puVar16 = selfSaved;
  fVar12 = (float10)security_cookie_guard_a(0x41400000,0,selfSaved,puVar17,puVar10,1,0xbf800000,1);
  coinPtr = (float *)(float)fVar12;
  fVar14 = (float)coinPtr - 20.0;
  fVar12 = (float10)security_cookie_guard_b(fVar14);
  coinPtr = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,(float)coinPtr / 3.0,fVar14,uVar21,uVar15,puVar16,puVar17,
               puVar10,uVar19,uVar20,uVar22);
  if (7 < local_248) {
    operator_delete(local_25c[0]);
  }
  local_248 = 7;
  local_24c = 0;
  local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel._0_1_ = 0xd;
  if ((local_3fc & 1) != 0) {
    operator_delete((void *)*local_42c);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438,(wchar_t *)0x0,
             (wchar_t *)0x0);
  local_3fc = local_3fc & 0xfffffffe;
  puVar10 = &local_1ec;
  if (7 < local_1d8) {
    puVar10 = local_1ec;
  }
  local_400 = 0;
  strstreambuf_init(puVar10,local_1dc,local_3fc);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  wostream_insertNarrow(local_440,"Goodbye!");
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 0xe;
  uVar18 = u16_ostrstream_str_wrap(local_25c);
  uVar22 = 1;
  local_21c = 0;
  uVar20 = 0xbf800000;
  uVar19 = 1;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0x3f800000;
  local_1fc = 0x3f800000;
  local_1f8 = 0x3f800000;
  uStack_1f4 = 0x3f800000;
  local_1f0 = 0x3f800000;
  puVar10 = &local_21c;
  puVar17 = &local_234;
  puVar16 = &local_1fc;
  uVar15 = 0x40400000;
  trylevel._0_1_ = 0xf;
  uVar21 = 0x41400000;
  fVar12 = (float10)security_cookie_guard_a(0x41400000,0x40400000,puVar16,puVar17,puVar10,1,0xbf800000,1);
  coinPtr = (float *)(float)fVar12;
  fVar14 = (float)coinPtr - 20.0;
  fVar12 = (float10)security_cookie_guard_b(fVar14);
  coinPtr = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,((float)coinPtr * 2.0) / 3.0,fVar14,uVar21,uVar15,puVar16,
               puVar17,puVar10,uVar19,uVar20,uVar22);
  if (7 < local_248) {
    operator_delete(local_25c[0]);
  }
  local_248 = 7;
  local_24c = 0;
  local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
  trylevel = CONCAT31(trylevel._1_3_,3);
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  Widget_computeBoundsFloat(&local_23c);
  fVar12 = (float10)security_cookie_guard_a();
  coinPtr = (float *)(float)fVar12;
  if ((float)coinPtr - 30.0 < screenX) {
    fVar12 = (float10)security_cookie_guard_a();
    coinPtr = (float *)(float)fVar12;
    if (screenX < (float)coinPtr) {
      fVar12 = (float10)security_cookie_guard_b();
      coinPtr = (float *)(float)fVar12;
      if ((float)coinPtr * 0.5 < local_23c) {
        fVar12 = (float10)security_cookie_guard_b();
        coinPtr = (float *)(float)fVar12;
        if (local_23c < (float)coinPtr) {
          local_21c = 0;
          local_218 = 0x3f800000;
          local_214 = 0x3f800000;
          local_210 = 0x3f800000;
          selfSaved = &local_21c;
          goto LAB_00410902;
        }
      }
    }
  }
  local_234 = 0x3f800000;
  local_230 = 0x3f800000;
  local_22c = 0x3f800000;
  local_228 = 0x3f800000;
  selfSaved = &local_234;
LAB_00410902:
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 0x10;
  uVar18 = u16_ostrstream_str_wrap(local_25c);
  uVar22 = 1;
  local_1fc = 0;
  uVar20 = 0xbf800000;
  uVar19 = 1;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_20c = 0;
  uStack_208 = 0;
  local_204 = 0;
  uStack_200 = 0;
  puVar10 = &local_1fc;
  puVar17 = &local_20c;
  trylevel._0_1_ = 0x11;
  uVar15 = 0;
  uVar21 = 0x41400000;
  puVar16 = selfSaved;
  fVar12 = (float10)security_cookie_guard_a(0x41400000,0,selfSaved,puVar17,puVar10,1,0xbf800000,1);
  coinPtr = (float *)(float)fVar12;
  fVar14 = (float)coinPtr - 20.0;
  fVar12 = (float10)security_cookie_guard_b(fVar14);
  coinPtr = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,((float)coinPtr * 2.0) / 3.0,fVar14,uVar21,uVar15,puVar16,
               puVar17,puVar10,uVar19,uVar20,uVar22);
  if (7 < local_248) {
    operator_delete(local_25c[0]);
  }
  local_248 = 7;
  local_24c = 0;
  local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  fVar12 = (float10)security_cookie_guard_a();
  coinPtr = (float *)(float)fVar12;
  fVar14 = (float)coinPtr - 50.0;
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  screenX = (float)(int)fVar14;
  u16string_assignPtrLen(&PTR_006fccac,0);
  trylevel._0_1_ = 0x12;
  if ((local_3fc & 1) != 0) {
    operator_delete((void *)*local_42c);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_438,(wchar_t *)0x0,
             (wchar_t *)0x0);
  local_3fc = local_3fc & 0xfffffffe;
  puVar10 = &local_1ec;
  if (7 < local_1d8) {
    puVar10 = local_1ec;
  }
  local_400 = 0;
  strstreambuf_init(puVar10,local_1dc,local_3fc);
  trylevel = CONCAT31(trylevel._1_3_,3);
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  targetEntity = getTargetEntity();
  iVar7 = 0;
  fVar14 = (float)(int)fVar14;
  if (targetEntity != 0) {
    targetEntity = (int)*(short *)(targetEntity + 0x10);
    coinPtr = *(float **)(*(int *)((int)self + 0x16c) + 0x8006d0);
    fVar14 = screenX;
    if (targetEntity < *(int *)((int)coinPtr + 400)) {
      dVar13 = 2.0;
      libm_sse2_pow_precise();
      do {
        targetEntity = targetEntity + 1;
        iVar7 = (int)((float)iVar7 + (float)dVar13 * 2.0);
        fVar14 = screenX;
      } while (targetEntity < *(int *)((int)coinPtr + 400));
    }
  }
  pcVar23 = " Platinum Coins ";
  pbVar9 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_440,iVar7);
  wostream_insertNarrow(pbVar9,pcVar23);
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  trylevel._0_1_ = 0x13;
  uVar18 = u16_ostrstream_str_wrap(local_25c);
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0x3f800000;
  local_1fc = 0x3f800000;
  local_1f8 = 0x3f800000;
  uStack_1f4 = 0x3f800000;
  local_1f0 = 0x3f800000;
  trylevel._0_1_ = 0x14;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,0x435c0000,(float)(int)fVar14,0x41200000,0x40200000,&local_1fc,
               &local_234,&local_21c,2,0xbf800000,1);
  if (7 < local_248) {
    operator_delete(local_25c[0]);
  }
  local_248 = 7;
  local_24c = 0;
  local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  u16string_assignCStr(L"resource1.dat");
  trylevel._0_1_ = 0x15;
  uVar18 = u16_ostrstream_str_wrap(local_25c);
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0;
  local_1fc = 0x3f000000;
  local_1f8 = 0x3e4ccccd;
  uStack_1f4 = 0x3f800000;
  local_1f0 = 0x3f800000;
  trylevel._0_1_ = 0x16;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,0x435c0000,(float)(int)fVar14,0x41200000,0,&local_1fc,
               &local_234,&local_21c,2,0xbf800000,1);
  if (7 < local_248) {
    operator_delete(local_25c[0]);
  }
  local_248 = 7;
  local_24c = 0;
  local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  u16string_assignCStr(&PTR_006fccac);
  trylevel._0_1_ = 0x17;
  strstreambuf_tidy();
  puVar10 = &local_1ec;
  if (7 < local_1d8) {
    puVar10 = local_1ec;
  }
  strstreambuf_init(puVar10,local_1dc,local_3fc);
  trylevel._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  wostream_insertNarrow(local_440,"COST:");
  u16string_assignCStr(L"resource1.dat");
  trylevel._0_1_ = 0x18;
  uVar18 = u16_ostrstream_str_wrap(local_25c);
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0x3f800000;
  local_1fc = 0x3f800000;
  local_1f8 = 0x3f800000;
  uStack_1f4 = 0x3f800000;
  local_1f0 = 0x3f800000;
  trylevel._0_1_ = 0x19;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar18,0,0,0x41700000,(float)(int)fVar14,0x41200000,0x40000000,&local_1fc,
               &local_234,&local_21c,0,0xbf800000,1);
  if (7 < local_248) {
    operator_delete(local_25c[0]);
  }
  local_248 = 7;
  local_24c = 0;
  local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
  trylevel._0_1_ = 3;
  if (local_1d8 < 8) {
    u16string_assignCStr(L"resource1.dat");
    trylevel._0_1_ = 0x1a;
    uVar18 = u16_ostrstream_str_wrap(local_25c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_234 = 0;
    local_230 = 0;
    local_22c = 0;
    local_228 = 0;
    local_1e4 = 0x3f800000;
    local_1e0 = 0x3f800000;
    local_1dc = 0x3f800000;
    local_1d8 = 0x3f800000;
    trylevel = CONCAT31(trylevel._1_3_,0x1b);
    AdaptionWidget_draw_text_locked(local_274,uVar18,0,0,0x41700000,(float)(int)fVar14,0x41200000,0,&local_1e4,
                 &local_234,&local_21c,0,0xbf800000,1);
    if (7 < local_248) {
      operator_delete(local_25c[0]);
    }
    local_248 = 7;
    local_24c = 0;
    local_25c[0] = (void *)((uint)local_25c[0] & 0xffff0000);
    if (local_260 < 8) {
      std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_18();
      ExceptionList = savedExceptionList;
      __security_check_cookie(stackCookie ^ (uint)&stack0xfffffffc);
      return;
    }
    operator_delete(local_274[0]);
  }
  operator_delete(local_1ec);
}




/* cube::AdaptionWidget::vfunc_4 @ 00411330 */

undefined1 cube::AdaptionWidget::vfunc_4(void)

{
  return 0;
}




/* cube::AdaptionWidget::vfunc_10 @ 00411410 */

void cube::AdaptionWidget::vfunc_10(void)

{
  int self;
  float10 width;
  float10 elemW;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (*(int *)(self + 0x170) != 0) {
    uVar4 = 1;
    uVar3 = 0x42480000;
    width = (float10)security_cookie_guard_b(0x42480000,1);
    elemW = (float10)Widget_measureGuarded();
    Widget_setScroll(((float)width - (float)elemW) * 0.5,uVar3,uVar4);
  }
  if (*(int *)(self + 0x174) != 0) {
    uVar4 = 1;
    uVar3 = 0x43660000;
    width = (float10)security_cookie_guard_b(0x43660000,1);
    Widget_setScroll((float)width * 0.5 - 10.0,uVar3,uVar4);
  }
  return;
}




/* cube::AdaptionWidget::vfunc_6 @ 004114b0 */

void cube::AdaptionWidget::vfunc_6(void)

{
  return;
}




/* cube::AdaptionWidget::vfunc_0_00428a30 @ 00428a30 */

void cube::AdaptionWidget::vfunc_0_00428a30(byte deleteFlag)

{
  void *self;
  
  plasma::Widget::ctor_0();
  if ((deleteFlag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




/* [AUDIT] proposed: Matrix4_Invert  (confidence: high)
 * purpose: Game/math: inverts a 4x4 float matrix via Gauss-Jordan elimination with partial pivoting (thiscall self)
 * vars: self=mat4; local_88 augmented 4x8
 */
/* Global::Matrix4_Invert @ 0058c440 */

void Matrix4_Invert(void)

{
  float *pivotRow;
  float *srcMatrix;
  float *row0;
  float *row1;
  float *row2;
  float *row3;
  float factor;
  float f0;
  float f1;
  float pivot;
  float augMatrix [32];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  augMatrix[1] = srcMatrix[4];
  augMatrix[2] = srcMatrix[8];
  augMatrix[3] = srcMatrix[0xc];
  augMatrix[9] = srcMatrix[5];
  augMatrix[10] = srcMatrix[9];
  augMatrix[0xb] = srcMatrix[0xd];
  augMatrix[0x11] = srcMatrix[6];
  augMatrix[0x12] = srcMatrix[10];
  augMatrix[0x13] = srcMatrix[0xe];
  augMatrix[0x19] = srcMatrix[7];
  augMatrix[0x1a] = srcMatrix[0xb];
  augMatrix[0x1b] = srcMatrix[0xf];
  augMatrix[0x18] = srcMatrix[3];
  augMatrix[0] = *srcMatrix;
  augMatrix[4] = 1.0;
  augMatrix[7] = 0.0;
  augMatrix[6] = 0.0;
  augMatrix[5] = 0.0;
  augMatrix[8] = srcMatrix[1];
  augMatrix[0xd] = 1.0;
  augMatrix[0xf] = 0.0;
  augMatrix[0xe] = 0.0;
  augMatrix[0xc] = 0.0;
  augMatrix[0x10] = srcMatrix[2];
  augMatrix[0x16] = 1.0;
  augMatrix[0x17] = 0.0;
  augMatrix[0x15] = 0.0;
  augMatrix[0x14] = 0.0;
  augMatrix[0x1f] = 1.0;
  augMatrix[0x1e] = 0.0;
  augMatrix[0x1d] = 0.0;
  augMatrix[0x1c] = 0.0;
  row0 = augMatrix + 0x10;
  row3 = augMatrix + 0x18;
  if (ABS(srcMatrix[2]) < ABS(srcMatrix[3])) {
    row0 = augMatrix + 0x18;
    row3 = augMatrix + 0x10;
  }
  row1 = row0;
  row2 = augMatrix + 8;
  if (ABS(srcMatrix[1]) < ABS(*row0)) {
    row1 = augMatrix + 8;
    row2 = row0;
  }
  pivotRow = augMatrix;
  row0 = row2;
  if (ABS(*srcMatrix) < ABS(*row2)) {
    row0 = augMatrix;
    pivotRow = row2;
  }
  pivot = *pivotRow;
  if (pivot != 0.0) {
    f0 = *row0 / pivot;
    f1 = *row1 / pivot;
    factor = pivotRow[1];
    pivot = *row3 / pivot;
    row0[1] = row0[1] - factor * f0;
    row1[1] = row1[1] - factor * f1;
    row3[1] = row3[1] - factor * pivot;
    factor = pivotRow[2];
    row0[2] = row0[2] - factor * f0;
    row1[2] = row1[2] - factor * f1;
    row3[2] = row3[2] - factor * pivot;
    factor = pivotRow[3];
    row0[3] = row0[3] - factor * f0;
    row1[3] = row1[3] - factor * f1;
    row3[3] = row3[3] - factor * pivot;
    factor = pivotRow[4];
    if (factor != 0.0) {
      row0[4] = row0[4] - factor * f0;
      row1[4] = row1[4] - factor * f1;
      row3[4] = row3[4] - factor * pivot;
    }
    factor = pivotRow[5];
    if (factor != 0.0) {
      row0[5] = row0[5] - factor * f0;
      row1[5] = row1[5] - factor * f1;
      row3[5] = row3[5] - factor * pivot;
    }
    factor = pivotRow[6];
    if (factor != 0.0) {
      row0[6] = row0[6] - factor * f0;
      row1[6] = row1[6] - factor * f1;
      row3[6] = row3[6] - factor * pivot;
    }
    factor = pivotRow[7];
    if (factor != 0.0) {
      row0[7] = row0[7] - factor * f0;
      row1[7] = row1[7] - factor * f1;
      row3[7] = row3[7] - factor * pivot;
    }
    row2 = row1;
    if (ABS(row1[1]) < ABS(row3[1])) {
      row2 = row3;
      row3 = row1;
    }
    row1 = row2;
    if (ABS(row0[1]) < ABS(row2[1])) {
      row1 = row0;
      row0 = row2;
    }
    pivot = row0[1];
    if (pivot != 0.0) {
      f0 = row1[1] / pivot;
      pivot = row3[1] / pivot;
      row1[2] = row1[2] - f0 * row0[2];
      row3[2] = row3[2] - pivot * row0[2];
      row1[3] = row1[3] - row0[3] * f0;
      row3[3] = row3[3] - row0[3] * pivot;
      factor = row0[4];
      if (factor != 0.0) {
        row1[4] = row1[4] - factor * f0;
        row3[4] = row3[4] - factor * pivot;
      }
      factor = row0[5];
      if (factor != 0.0) {
        row1[5] = row1[5] - factor * f0;
        row3[5] = row3[5] - factor * pivot;
      }
      factor = row0[6];
      if (factor != 0.0) {
        row1[6] = row1[6] - factor * f0;
        row3[6] = row3[6] - factor * pivot;
      }
      factor = row0[7];
      if (factor != 0.0) {
        row1[7] = row1[7] - factor * f0;
        row3[7] = row3[7] - factor * pivot;
      }
      row2 = row1;
      if (ABS(row1[2]) < ABS(row3[2])) {
        row2 = row3;
        row3 = row1;
      }
      if (row2[2] != 0.0) {
        pivot = row3[2] / row2[2];
        row3[3] = row3[3] - pivot * row2[3];
        row3[4] = row3[4] - row2[4] * pivot;
        row3[5] = row3[5] - pivot * row2[5];
        row3[6] = row3[6] - pivot * row2[6];
        row3[7] = row3[7] - row2[7] * pivot;
        if (row3[3] != 0.0) {
          pivot = 1.0 / row3[3];
          row3[4] = row3[4] * pivot;
          row3[5] = row3[5] * pivot;
          row3[6] = row3[6] * pivot;
          row3[7] = row3[7] * pivot;
          factor = 1.0 / row2[2];
          pivot = row2[3];
          row2[4] = (row2[4] - row3[4] * pivot) * factor;
          row2[5] = (row2[5] - row3[5] * pivot) * factor;
          row2[6] = (row2[6] - row3[6] * pivot) * factor;
          row2[7] = (row2[7] - row3[7] * pivot) * factor;
          pivot = row0[3];
          row0[4] = row0[4] - row3[4] * pivot;
          row0[5] = row0[5] - row3[5] * pivot;
          row0[6] = row0[6] - row3[6] * pivot;
          row0[7] = row0[7] - row3[7] * pivot;
          pivot = pivotRow[3];
          pivotRow[4] = pivotRow[4] - row3[4] * pivot;
          pivotRow[5] = pivotRow[5] - row3[5] * pivot;
          pivotRow[6] = pivotRow[6] - row3[6] * pivot;
          pivotRow[7] = pivotRow[7] - row3[7] * pivot;
          factor = 1.0 / row0[1];
          pivot = row0[2];
          row0[4] = (row0[4] - row2[4] * pivot) * factor;
          row0[5] = (row0[5] - pivot * row2[5]) * factor;
          row0[6] = (row0[6] - pivot * row2[6]) * factor;
          row0[7] = (row0[7] - row2[7] * pivot) * factor;
          pivot = pivotRow[2];
          f0 = 1.0 / *pivotRow;
          pivotRow[4] = pivotRow[4] - row2[4] * pivot;
          pivotRow[5] = pivotRow[5] - pivot * row2[5];
          pivotRow[6] = pivotRow[6] - pivot * row2[6];
          factor = pivotRow[1];
          pivotRow[7] = pivotRow[7] - row2[7] * pivot;
          pivotRow[4] = (pivotRow[4] - row0[4] * factor) * f0;
          pivotRow[5] = (pivotRow[5] - row0[5] * factor) * f0;
          pivotRow[6] = (pivotRow[6] - row0[6] * factor) * f0;
          f0 = (pivotRow[7] - row0[7] * factor) * f0;
          pivotRow[7] = f0;
          *srcMatrix = pivotRow[4];
          srcMatrix[4] = pivotRow[5];
          srcMatrix[0xc] = f0;
          srcMatrix[8] = pivotRow[6];
          srcMatrix[1] = row0[4];
          srcMatrix[5] = row0[5];
          srcMatrix[9] = row0[6];
          srcMatrix[0xd] = row0[7];
          srcMatrix[2] = row2[4];
          srcMatrix[6] = row2[5];
          srcMatrix[10] = row2[6];
          srcMatrix[0xe] = row2[7];
          srcMatrix[3] = row3[4];
          srcMatrix[7] = row3[5];
          srcMatrix[0xb] = row3[6];
          srcMatrix[0xf] = row3[7];
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* plasma::NamedObject::ctor_5 @ 00627450 */

undefined4 * plasma::NamedObject::ctor_5(int param_1,int parent)

{
  int src;
  uint security_cookie;
  undefined4 uVar3;
  undefined4 *src_ptr;
  undefined4 *self;
  int iVar5;
  undefined4 *dst_ptr;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  src = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f55dc;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  Object::ctor_1(*(undefined4 *)(param_1 + 4));
  *self = vftable;
  self[8] = 7;
  self[7] = 0;
  *(undefined2 *)(self + 3) = 0;
  local_8 = 0;
  u16string_replaceRange(src + 0xc,0,0xffffffff);
  self[9] = Deformer::vftable;
  *self = Widget::vftable;
  self[9] = Widget::vftable;
  self[10] = *(undefined4 *)(src + 0x28);
  self[0xb] = *(undefined4 *)(src + 0x2c);
  self[0xc] = *(undefined4 *)(src + 0x30);
  self[0xd] = *(undefined4 *)(src + 0x34);
  self[0xf] = 0;
  self[0x12] = *(undefined4 *)(src + 0x48);
  self[0x13] = *(undefined4 *)(src + 0x4c);
  self[0x14] = *(undefined4 *)(src + 0x50);
  self[0x15] = *(undefined4 *)(src + 0x54);
  self[0x16] = *(undefined4 *)(src + 0x58);
  self[0x17] = *(undefined4 *)(src + 0x5c);
  self[0x18] = *(undefined4 *)(src + 0x60);
  self[0x19] = *(undefined4 *)(src + 100);
  self[0x1a] = *(undefined4 *)(src + 0x68);
  self[0x1b] = *(undefined4 *)(src + 0x6c);
  self[0x1c] = *(undefined4 *)(src + 0x70);
  self[0x1d] = *(undefined4 *)(src + 0x74);
  self[0x1e] = *(undefined4 *)(src + 0x78);
  self[0x1f] = *(undefined4 *)(src + 0x7c);
  self[0x25] = 7;
  self[0x24] = 0;
  *(undefined2 *)(self + 0x20) = 0;
  local_8 = 1;
  u16string_replaceRange(src + 0x80,0,0xffffffff);
  src_ptr = (undefined4 *)(src + 0xa8);
  dst_ptr = self + 0x2a;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *dst_ptr = *src_ptr;
    src_ptr = src_ptr + 1;
    dst_ptr = dst_ptr + 1;
  }
  src_ptr = (undefined4 *)(src + 0xe8);
  dst_ptr = self + 0x3a;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *dst_ptr = *src_ptr;
    src_ptr = src_ptr + 1;
    dst_ptr = dst_ptr + 1;
  }
  local_8._0_1_ = 2;
  self[0x4a] = *(undefined4 *)(src + 0x128);
  self[0x4b] = *(undefined4 *)(src + 300);
  self[0x4c] = *(undefined4 *)(src + 0x130);
  *(undefined1 *)(self + 0x4d) = 0;
  self[0x4e] = *(undefined4 *)(src + 0x138);
  self[0x4f] = *(undefined4 *)(src + 0x13c);
  self[0x50] = 0;
  self[0x51] = 0;
  self[0x52] = parent;
  self[0x54] = 0;
  self[0x55] = 0;
  uVar3 = rbtree_allocHead24(security_cookie);
  self[0x54] = uVar3;
  self[0x56] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  src_ptr = (undefined4 *)Registry_push_node_locked_0x7c(&param_1,self);
  self[0x56] = *src_ptr;
  *(undefined1 *)(self + 0x57) = *(undefined1 *)(src + 0x15c);
  if (parent != 0) {
    *(undefined4 **)(parent + 0x40) = self;
  }
  ExceptionList = local_10;
  return self;
}




/* [AUDIT] proposed: AdaptionWidget_clampScrollToContent  (confidence: med)
 * purpose: Clamps scroll offset (local_10/local_c) to child content bounds, updates scrollbars, notifies (vfunc)
 * vars: self+0x52 child list; +0x40 flag; +0x50/0x51 scrollbars; +0xa8 vcall
 */
/* Global::AdaptionWidget_clampScrollToContent @ 006278a0 */

void AdaptionWidget_clampScrollToContent(void)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int child;
  int *self;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  float offset_x;
  float offset_y;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  child = *(int *)(self[0x52] + 0x28);
  if (child != 0) {
    while (*(int *)(child + 0x40) == 0) {
      child = *(int *)(child + 0x28);
      if (child == 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    AdaptionWidget_getContentSize(&offset_x);
    if (0.0 < offset_x) {
      offset_x = 0.0;
    }
    fVar2 = offset_x;
    pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_18);
    fVar1 = *pfVar3;
    for (child = *(int *)(self[0x52] + 0x28); (child != 0 && (*(int *)(child + 0x40) == 0));
        child = *(int *)(child + 0x28)) {
    }
    pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_20);
    if (*pfVar3 <= fVar1 && fVar1 != *pfVar3) {
      pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_20);
      fVar1 = *pfVar3;
      for (child = *(int *)(self[0x52] + 0x28); (child != 0 && (*(int *)(child + 0x40) == 0));
          child = *(int *)(child + 0x28)) {
      }
      pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_18);
      if (fVar2 + fVar1 < *pfVar3) {
        AdaptionWidget_onContentResized();
        pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_20);
        fVar1 = *pfVar3;
        pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_18);
        offset_x = fVar1 - *pfVar3;
      }
    }
    if (0.0 < offset_y) {
      offset_y = 0.0;
    }
    fVar2 = offset_y;
    child = AdaptionWidget_getBoundsRect(local_20);
    fVar1 = *(float *)(child + 4);
    for (child = *(int *)(self[0x52] + 0x28); (child != 0 && (*(int *)(child + 0x40) == 0));
        child = *(int *)(child + 0x28)) {
    }
    child = AdaptionWidget_getBoundsRect(local_18);
    if (*(float *)(child + 4) <= fVar1 && fVar1 != *(float *)(child + 4)) {
      child = AdaptionWidget_getBoundsRect(local_20);
      fVar1 = *(float *)(child + 4);
      for (child = *(int *)(self[0x52] + 0x28); (child != 0 && (*(int *)(child + 0x40) == 0));
          child = *(int *)(child + 0x28)) {
      }
      child = AdaptionWidget_getBoundsRect(local_18);
      if (fVar2 + fVar1 < *(float *)(child + 4)) {
        AdaptionWidget_onContentResized();
        child = AdaptionWidget_getBoundsRect(local_20);
        fVar1 = *(float *)(child + 4);
        child = AdaptionWidget_getBoundsRect(local_18);
        offset_y = fVar1 - *(float *)(child + 4);
      }
    }
    pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_20);
    fVar1 = *pfVar3;
    for (child = *(int *)(self[0x52] + 0x28); (child != 0 && (*(int *)(child + 0x40) == 0));
        child = *(int *)(child + 0x28)) {
    }
    pfVar3 = (float *)AdaptionWidget_getBoundsRect(local_18);
    if (fVar1 < *pfVar3) {
      offset_x = 0.0;
    }
    child = AdaptionWidget_getBoundsRect(local_20);
    fVar1 = *(float *)(child + 4);
    for (child = *(int *)(self[0x52] + 0x28); (child != 0 && (*(int *)(child + 0x40) == 0));
        child = *(int *)(child + 0x28)) {
    }
    child = AdaptionWidget_getBoundsRect(local_18);
    if (fVar1 < *(float *)(child + 4)) {
      offset_y = 0.0;
    }
    AdaptionWidget_applyScrollLayout(&offset_x,1);
    if (self[0x50] != 0) {
      Widget_layoutAspectFit();
    }
    if (self[0x51] != 0) {
      Widget_layoutAspectFit();
    }
    (**(code **)(*self + 0xa8))();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_40 @ 00627dc0 */

undefined4 cube::AdaptionWidget::vfunc_40(undefined4 parent)

{
  void *mem;
  undefined4 clone;
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
    clone = plasma::NamedObject::ctor_5(self,parent);
    ExceptionList = local_10;
    return clone;
  }
  ExceptionList = local_10;
  return 0;
}




/* cube::AdaptionWidget::vfunc_0_00627e40 @ 00627e40 */

void cube::AdaptionWidget::vfunc_0_00627e40(float *out_point,float *in_point,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  int self;
  int i;
  int count;
  float *pfVar26;
  float *pfVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  float fVar65;
  float local_cc;
  float local_c8;
  float local_a0 [5];
  float local_8c;
  float local_84;
  float local_7c;
  float local_74;
  float local_6c;
  float local_64;
  float local_60 [8];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10 [2];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  fVar28 = (*(float *)(self + 0x24) + *(float *)(self + 0x44)) - *(float *)(self + 0x34);
  fVar48 = (*(float *)(self + 0x28) + *(float *)(self + 0x48)) - *(float *)(self + 0x38);
  fVar56 = (*(float *)(self + 0x2c) + *(float *)(self + 0x54)) - *(float *)(self + 0x3c);
  local_10[0] = (*(float *)(self + 0x2c) + *(float *)(self + 0x4c)) - *(float *)(self + 0x3c);
  local_10[1] = (*(float *)(self + 0x30) + *(float *)(self + 0x50)) - *(float *)(self + 0x40);
  local_60[2] = fVar28;
  fVar55 = (*(float *)(self + 0x30) + *(float *)(self + 0x58)) - *(float *)(self + 0x40);
  local_60[3] = fVar48;
  if (fVar56 < 0.0) {
    fVar56 = 0.0;
  }
  local_cc = local_10[0];
  if (local_10[0] < fVar56) {
    local_10[0] = fVar56;
    local_cc = fVar56;
  }
  if (fVar55 < 0.0) {
    fVar55 = 0.0;
  }
  local_c8 = local_10[1];
  if (local_10[1] < fVar55) {
    local_10[1] = fVar55;
    local_c8 = fVar55;
  }
  fVar55 = *(float *)(self + 0x2c);
  local_60[0] = fVar55;
  local_60[1] = (float)*(undefined4 *)(self + 0x30);
  i = 0;
  do {
    local_10[0] = local_cc;
    if (*(float *)((int)local_10 + i) != *(float *)((int)local_60 + i)) goto LAB_00627fb9;
    i = i + 4;
  } while (i < 8);
  local_10[0] = *(float *)(self + 0x24);
  local_10[1] = (float)*(undefined4 *)(self + 0x28);
  i = 0;
  while (*(float *)((int)local_60 + i + 8) == *(float *)((int)local_10 + i)) {
    i = i + 4;
    if (7 < i) {
      *out_point = *in_point;
      out_point[1] = in_point[1];
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_00627fb9:
  i = *(int *)(self + 0x124);
  fVar56 = *(float *)(i + 0x88);
  fVar57 = *(float *)(i + 0x8c);
  pfVar26 = (float *)(self + 0x84);
  pfVar27 = local_60 + 4;
  for (count = 0x10; fVar9 = local_28, fVar8 = local_2c, fVar7 = local_30, fVar6 = local_38,
      fVar5 = local_3c, fVar4 = local_40, fVar3 = local_60[6], fVar47 = local_60[5],
      fVar60 = local_60[4], count != 0; count = count + -1) {
    *pfVar27 = *pfVar26;
    pfVar26 = pfVar26 + 1;
    pfVar27 = pfVar27 + 1;
  }
  fVar1 = *(float *)(i + 0xc0);
  fVar2 = *(float *)(i + 0xc4);
  fVar57 = fVar56 * local_60[4] + fVar57 * local_40 + *(float *)(i + 0x90) * local_30 +
           *(float *)(i + 0x94) * local_20;
  local_60[4] = fVar57;
  fVar58 = *(float *)(i + 0x98) * fVar60 + *(float *)(i + 0x9c) * local_40 +
           *(float *)(i + 0xa0) * local_30 + *(float *)(i + 0xa4) * local_20;
  fVar56 = *(float *)(i + 0xac) * local_40;
  local_40 = fVar58;
  fVar59 = *(float *)(i + 0xa8) * fVar60 + fVar56 + *(float *)(i + 0xb0) * local_30 +
           *(float *)(i + 0xb4) * local_20;
  local_30 = fVar59;
  fVar60 = *(float *)(i + 0xb8) * fVar60 + *(float *)(i + 0xbc) * fVar4 + fVar1 * fVar7 +
           fVar2 * local_20;
  local_20 = fVar60;
  local_60[5] = *(float *)(i + 0x88) * local_60[5] + *(float *)(i + 0x8c) * local_3c +
                *(float *)(i + 0x90) * local_2c + *(float *)(i + 0x94) * local_1c;
  fVar56 = *(float *)(i + 0xac) * local_3c;
  local_3c = *(float *)(i + 0x98) * fVar47 + *(float *)(i + 0x9c) * local_3c +
             *(float *)(i + 0xa0) * local_2c + *(float *)(i + 0xa4) * local_1c;
  local_2c = *(float *)(i + 0xa8) * fVar47 + fVar56 + *(float *)(i + 0xb0) * local_2c +
             *(float *)(i + 0xb4) * local_1c;
  local_1c = *(float *)(i + 0xb8) * fVar47 + *(float *)(i + 0xbc) * fVar5 + fVar1 * fVar8
             + fVar2 * local_1c;
  local_60[6] = *(float *)(i + 0x88) * local_60[6] + *(float *)(i + 0x8c) * local_38 +
                *(float *)(i + 0x90) * local_28 + *(float *)(i + 0x94) * local_18;
  fVar56 = *(float *)(i + 0xac) * local_38;
  local_38 = *(float *)(i + 0x98) * fVar3 + *(float *)(i + 0x9c) * local_38 +
             *(float *)(i + 0xa0) * local_28 + *(float *)(i + 0xa4) * local_18;
  local_28 = *(float *)(i + 0xa8) * fVar3 + fVar56 + *(float *)(i + 0xb0) * local_28 +
             *(float *)(i + 0xb4) * local_18;
  local_18 = *(float *)(i + 0xb8) * fVar3 + *(float *)(i + 0xbc) * fVar6 + fVar1 * fVar9 +
             fVar2 * local_18;
  local_60[7] = local_60[7] * *(float *)(i + 0x88) + local_34 * *(float *)(i + 0x8c) +
                local_24 * *(float *)(i + 0x90) + local_14 * *(float *)(i + 0x94);
  local_34 = *(float *)(i + 0x98) * local_60[7] + local_34 * *(float *)(i + 0x9c) +
             local_24 * *(float *)(i + 0xa0) + local_14 * *(float *)(i + 0xa4);
  local_24 = *(float *)(i + 0xa8) * local_60[7] + *(float *)(i + 0xac) * local_34 +
             local_24 * *(float *)(i + 0xb0) + local_14 * *(float *)(i + 0xb4);
  local_14 = *(float *)(i + 0xb8) * local_60[7] + *(float *)(i + 0xbc) * local_34 +
             fVar1 * local_24 + local_14 * fVar2;
  pfVar26 = local_60 + 4;
  pfVar27 = local_a0;
  for (count = 0x10; count != 0; count = count + -1) {
    *pfVar27 = *pfVar26;
    pfVar26 = pfVar26 + 1;
    pfVar27 = pfVar27 + 1;
  }
  fVar56 = *(float *)(param_3 + 0x4c);
  fVar47 = *(float *)(param_3 + 0x48);
  fVar3 = *(float *)(param_3 + 0x50);
  fVar4 = *(float *)(param_3 + 0x54);
  fVar5 = *(float *)(param_3 + 0x58);
  fVar6 = *(float *)(param_3 + 0x7c);
  fVar7 = *(float *)(param_3 + 0x5c);
  fVar8 = *(float *)(param_3 + 0x80);
  fVar9 = *(float *)(param_3 + 0x60);
  fVar1 = *(float *)(param_3 + 0x78);
  fVar2 = *(float *)(param_3 + 100);
  fVar10 = *(float *)(param_3 + 0x84);
  fVar29 = local_8c * *(float *)(param_3 + 0x4c);
  fVar64 = local_a0[1] * *(float *)(param_3 + 0x48);
  fVar30 = local_7c * *(float *)(param_3 + 0x50);
  fVar31 = local_6c * *(float *)(param_3 + 0x54);
  fVar32 = local_8c * *(float *)(param_3 + 0x5c);
  fVar53 = local_8c * *(float *)(param_3 + 0x7c);
  fVar33 = local_a0[1] * *(float *)(param_3 + 0x58);
  fVar34 = local_7c * *(float *)(param_3 + 0x60);
  fVar51 = local_7c * fVar8;
  fVar35 = local_6c * *(float *)(param_3 + 100);
  fVar49 = local_6c * fVar10;
  fVar36 = local_a0[1] * fVar1;
  fVar65 = local_a0[3] * *(float *)(param_3 + 0x48);
  fVar37 = local_84 * *(float *)(param_3 + 0x4c);
  fVar38 = local_74 * *(float *)(param_3 + 0x50);
  fVar39 = local_64 * *(float *)(param_3 + 0x54);
  fVar40 = local_84 * *(float *)(param_3 + 0x5c);
  fVar54 = local_84 * *(float *)(param_3 + 0x7c);
  fVar41 = local_a0[3] * *(float *)(param_3 + 0x58);
  fVar42 = local_74 * *(float *)(param_3 + 0x60);
  fVar52 = local_74 * fVar8;
  fVar43 = local_64 * *(float *)(param_3 + 100);
  fVar50 = local_64 * fVar10;
  fVar44 = local_a0[3] * fVar1;
  pfVar26 = (float *)(param_3 + 0x88);
  pfVar27 = local_60 + 4;
  for (count = 0x10; fVar19 = local_28, fVar18 = local_2c, fVar17 = local_30, fVar16 = local_38,
      fVar15 = local_3c, fVar63 = local_40, fVar14 = local_60[6], fVar13 = local_60[5],
      fVar46 = local_60[4], count != 0; count = count + -1) {
    *pfVar27 = *pfVar26;
    pfVar26 = pfVar26 + 1;
    pfVar27 = pfVar27 + 1;
  }
  fVar11 = *(float *)(i + 0x80);
  fVar12 = *(float *)(i + 0x84);
  fVar61 = local_60[4] * *(float *)(i + 0x48) + local_40 * *(float *)(i + 0x4c) +
           local_30 * *(float *)(i + 0x50) + local_20 * *(float *)(i + 0x54);
  local_60[4] = fVar61;
  fVar62 = *(float *)(i + 0x58) * fVar46 + local_40 * *(float *)(i + 0x5c) +
           local_30 * *(float *)(i + 0x60) + local_20 * *(float *)(i + 100);
  fVar45 = *(float *)(i + 0x6c) * local_40;
  local_40 = fVar62;
  fVar45 = *(float *)(i + 0x68) * fVar46 + fVar45 + local_30 * *(float *)(i + 0x70) +
           local_20 * *(float *)(i + 0x74);
  local_30 = fVar45;
  fVar63 = *(float *)(i + 0x78) * fVar46 + *(float *)(i + 0x7c) * fVar63 + fVar11 * fVar17
           + local_20 * fVar12;
  local_20 = fVar63;
  local_60[5] = local_60[5] * *(float *)(i + 0x48) + local_3c * *(float *)(i + 0x4c) +
                local_2c * *(float *)(i + 0x50) + local_1c * *(float *)(i + 0x54);
  fVar46 = *(float *)(i + 0x6c) * local_3c;
  local_3c = *(float *)(i + 0x58) * fVar13 + local_3c * *(float *)(i + 0x5c) +
             local_2c * *(float *)(i + 0x60) + local_1c * *(float *)(i + 100);
  local_2c = *(float *)(i + 0x68) * fVar13 + fVar46 + local_2c * *(float *)(i + 0x70) +
             local_1c * *(float *)(i + 0x74);
  local_1c = *(float *)(i + 0x78) * fVar13 + *(float *)(i + 0x7c) * fVar15 +
             fVar11 * fVar18 + local_1c * fVar12;
  local_60[6] = local_60[6] * *(float *)(i + 0x48) + local_38 * *(float *)(i + 0x4c) +
                local_28 * *(float *)(i + 0x50) + local_18 * *(float *)(i + 0x54);
  fVar46 = *(float *)(i + 0x6c) * local_38;
  local_38 = *(float *)(i + 0x58) * fVar14 + local_38 * *(float *)(i + 0x5c) +
             local_28 * *(float *)(i + 0x60) + local_18 * *(float *)(i + 100);
  local_28 = *(float *)(i + 0x68) * fVar14 + fVar46 + local_28 * *(float *)(i + 0x70) +
             local_18 * *(float *)(i + 0x74);
  local_18 = *(float *)(i + 0x78) * fVar14 + *(float *)(i + 0x7c) * fVar16 +
             fVar11 * fVar19 + local_18 * fVar12;
  local_60[7] = local_60[7] * *(float *)(i + 0x48) + local_34 * *(float *)(i + 0x4c) +
                local_24 * *(float *)(i + 0x50) + local_14 * *(float *)(i + 0x54);
  local_34 = *(float *)(i + 0x58) * local_60[7] + local_34 * *(float *)(i + 0x5c) +
             local_24 * *(float *)(i + 0x60) + local_14 * *(float *)(i + 100);
  local_24 = *(float *)(i + 0x68) * local_60[7] + *(float *)(i + 0x6c) * local_34 +
             local_24 * *(float *)(i + 0x70) + local_14 * *(float *)(i + 0x74);
  fVar46 = *(float *)(self + 200);
  local_14 = *(float *)(i + 0x78) * local_60[7] + *(float *)(i + 0x7c) * local_34 +
             fVar11 * local_24 + local_14 * fVar12;
  fVar13 = *(float *)(self + 0xc4);
  pfVar26 = local_60 + 4;
  pfVar27 = local_a0;
  for (i = 0x10; i != 0; i = i + -1) {
    *pfVar27 = *pfVar26;
    pfVar26 = pfVar26 + 1;
    pfVar27 = pfVar27 + 1;
  }
  local_10[1] = fVar61 * fVar13 + fVar62 * fVar46 + fVar45 * *(float *)(self + 0xcc) +
                fVar63 * *(float *)(self + 0xd0);
  fVar14 = *(float *)(self + 0x100);
  fVar15 = *(float *)(self + 0xf8);
  local_60[1] = fVar61 * *(float *)(self + 0xd4) + fVar62 * *(float *)(self + 0xd8) +
                fVar45 * *(float *)(self + 0xdc) + fVar63 * *(float *)(self + 0xe0);
  fVar16 = *(float *)(self + 0xfc);
  fVar17 = *(float *)(self + 0xcc);
  fVar18 = *(float *)(self + 0xd0);
  fVar19 = *(float *)(self + 0xd4);
  fVar11 = *(float *)(self + 0xd8);
  fVar12 = *(float *)(self + 0xdc);
  fVar20 = *(float *)(self + 0xe0);
  fVar21 = *(float *)(self + 0xf4);
  fVar22 = *in_point;
  local_60[3] = *(float *)(self + 0xf4) * local_a0[3] + fVar15 * local_84 + fVar16 * local_74 +
                local_64 * fVar14;
  fVar23 = in_point[1];
  fVar38 = 1.0 / (fVar22 * (fVar65 + fVar37 + fVar38 + fVar39) +
                  fVar23 * (fVar40 + fVar41 + fVar42 + fVar43) + fVar44 + fVar54 + fVar52 + fVar50);
  fVar37 = *(float *)(self + 0x24);
  fVar56 = fVar38 * (fVar22 * (fVar57 * fVar47 + fVar58 * fVar56 + fVar59 * fVar3 + fVar60 * fVar4)
                     + fVar23 * (fVar5 * fVar57 + fVar58 * fVar7 + fVar9 * fVar59 + fVar2 * fVar60)
                    + fVar1 * fVar57 + fVar6 * fVar58 + fVar8 * fVar59 + fVar10 * fVar60);
  fVar38 = fVar38 * (fVar22 * (fVar64 + fVar29 + fVar30 + fVar31) +
                     fVar23 * (fVar32 + fVar33 + fVar34 + fVar35) +
                    fVar36 + fVar53 + fVar51 + fVar49);
  if (fVar37 <= fVar56) {
    fVar55 = *(float *)(self + 0x2c);
    if (fVar37 + fVar55 <= fVar56) {
      fVar57 = 1.0;
    }
    else {
      fVar57 = (fVar56 - fVar37) / fVar55;
    }
  }
  else {
    fVar57 = 0.0;
  }
  fVar60 = *(float *)(self + 0x28);
  if (fVar60 <= fVar38) {
    if (fVar60 + *(float *)(self + 0x30) <= fVar38) {
      fVar47 = 1.0;
    }
    else {
      fVar47 = (fVar38 - fVar60) / *(float *)(self + 0x30);
    }
  }
  else {
    fVar47 = 0.0;
  }
  fVar55 = ((fVar56 + fVar28) - *(float *)(self + 0x24)) + fVar57 * (local_cc - fVar55);
  fVar28 = ((fVar38 + fVar48) - fVar60) + fVar47 * (local_c8 - *(float *)(self + 0x30));
  fVar48 = 1.0 / ((*(float *)(self + 0xd4) * local_a0[3] + local_84 * *(float *)(self + 0xd8) +
                   *(float *)(self + 0xdc) * local_74 + local_64 * *(float *)(self + 0xe0)) *
                  fVar28 + (local_a0[3] * *(float *)(self + 0xc4) +
                            local_84 * *(float *)(self + 200) +
                            *(float *)(self + 0xcc) * local_74 +
                           local_64 * *(float *)(self + 0xd0)) * fVar55 + local_60[3]);
  *out_point = (local_60[1] * fVar28 + local_10[1] * fVar55 +
             fVar61 * *(float *)(self + 0xf4) + fVar62 * fVar15 + fVar45 * fVar16 +
             fVar63 * fVar14) * fVar48;
  out_point[1] = ((fVar19 * local_a0[1] + local_8c * fVar11 + local_7c * fVar12 + local_6c * fVar20) *
                fVar28 + (local_a0[1] * fVar13 + local_8c * fVar46 + local_7c * fVar17 +
                         local_6c * fVar18) * fVar55 +
               fVar21 * local_a0[1] + fVar15 * local_8c + local_7c * fVar16 + local_6c * fVar14) *
               fVar48;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_41 @ 00628f40 */

void cube::AdaptionWidget::vfunc_41(char enabled)

{
  undefined4 uVar1;
  int self;
  void *event_buf2 [4];
  undefined4 local_34;
  uint local_30;
  void *event_buf [5];
  uint local_18;
  uint security_cookie;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f5660;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(char *)(self + 0x15c) = enabled;
  if (enabled == '\0') {
    u16string_assignCStr(L"widget:disable");
    local_8 = 2;
    AdaptionWidget_apply_to_attributes(event_buf,0);
    local_8 = 0xffffffff;
    if (7 < local_18) {
      operator_delete(event_buf[0]);
    }
    u16string_assignCStr(L"widget:disable");
    local_8 = 3;
    uVar1 = AdaptionWidget_compute_max_content_width(event_buf2);
    AdaptionWidget_relayout(uVar1);
    local_8 = 0xffffffff;
    if (7 < local_30) {
      operator_delete(event_buf2[0]);
    }
    local_30 = 7;
    local_34 = 0;
    event_buf2[0] = (void *)((uint)event_buf2[0] & 0xffff0000);
  }
  else {
    u16string_assignCStr(L"widget:enable");
    local_8 = 0;
    AdaptionWidget_apply_to_attributes(event_buf,0);
    local_8 = 0xffffffff;
    if (7 < local_18) {
      operator_delete(event_buf[0]);
    }
    u16string_assignCStr(L"widget:enable");
    local_8 = 1;
    uVar1 = AdaptionWidget_compute_max_content_width(event_buf);
    AdaptionWidget_relayout(uVar1);
    local_8 = 0xffffffff;
    if (7 < local_18) {
      operator_delete(event_buf[0]);
    }
  }
  local_8 = 0xffffffff;
  AdaptionWidget_apply_attributes_v2();
  ExceptionList = local_10;
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget_layoutRecursive  (confidence: med)
 * purpose: Recursively lays out widget subtree (self-call); returns via cookie guard
 * vars: self-recursive; enabled node
 */
/* Global::AdaptionWidget_layoutRecursive @ 00629300 */

void AdaptionWidget_layoutRecursive(int widget)

{
  float cursor_y;
  float cursor_x;
  char handled;
  int *piVar4;
  int self;
  undefined1 point [8];
  float local_x;
  float local_y;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if ((((~(byte)(*(uint *)(widget + 200) >> 2) & 1) != 0) &&
      (*(int *)(*(int *)(*(int *)(widget + 0x3c) + 0x94) +
               *(int *)(*(int *)(widget + 0x3c) + 0x68) * 4) != 0)) &&
     ((*(int *)(widget + 0x40) == 0 || (*(int *)(widget + 0x40) == self)))) {
    cursor_y = *(float *)(*(int *)(self + 4) + 0xd8);
    cursor_x = *(float *)(*(int *)(self + 4) + 0xd4);
    local_y = 1.0 / (*(float *)(widget + 0xa4) * cursor_y + *(float *)(widget + 0x94) * cursor_x +
                    *(float *)(widget + 0xc4));
    local_x = local_y * (*(float *)(widget + 0x98) * cursor_y + *(float *)(widget + 0x88) * cursor_x +
                         *(float *)(widget + 0xb8));
    local_y = local_y * (*(float *)(widget + 0x9c) * cursor_y + *(float *)(widget + 0x8c) * cursor_x +
                        *(float *)(widget + 0xbc));
    (**(code **)(*(int *)(self + 0x24) + 4))(point,&local_x,widget);
    if (*(int **)(widget + 0x34) != (int *)0x0) {
      handled = (**(code **)(**(int **)(widget + 0x34) + 0x10))(point);
      if (handled != '\0') goto LAB_0062942d;
    }
    if (*(int **)(widget + 0x40) != (int *)0x0) {
      handled = (**(code **)(**(int **)(widget + 0x40) + 0x14))(&local_x);
      if (handled != '\0') {
LAB_0062942d:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    if (*(int *)(*(int *)(*(int *)(widget + 0x3c) + 0xec) +
                *(int *)(*(int *)(widget + 0x3c) + 0xc0) * 4) == 0) {
      piVar4 = *(int **)(widget + 0x2c);
      if (piVar4 != (int *)*piVar4) {
        do {
          handled = AdaptionWidget_layoutRecursive(*(undefined4 *)(piVar4[1] + 8));
          if (handled != '\0') {
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          piVar4 = (int *)piVar4[1];
        } while (piVar4 != (int *)**(undefined4 **)(widget + 0x2c));
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget_applyScrollLayout  (confidence: med)
 * purpose: Applies scroll offset widget and lays out children (AdaptionWidget_getContentSize size, AdaptionWidget_computeBoundsUnion bounds)
 * vars: widget offset; param_2 flag; AdaptionWidget_recompute_transforms_recursive
 */
/* Global::AdaptionWidget_applyScrollLayout @ 006295a0 */

void AdaptionWidget_applyScrollLayout(float *position,char notify)

{
  undefined1 uVar1;
  float *pfVar2;
  int self;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float local_104;
  float local_100;
  float local_e4;
  float local_d8;
  undefined1 matrix [64];
  undefined1 local_90 [4];
  int local_8c;
  float local_88 [4];
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48 [4];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  pfVar2 = (float *)AdaptionWidget_getContentSize(local_90);
  iVar3 = 0;
  iVar4 = (int)position - (int)pfVar2;
  while (*(float *)(iVar4 + (int)pfVar2) == *pfVar2) {
    iVar3 = iVar3 + 1;
    pfVar2 = pfVar2 + 1;
    if (1 < iVar3) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  uVar1 = *(undefined1 *)(*(int *)(*(int *)(self + 0x148) + 0x38) + 0x2d);
  AdaptionWidget_computeLayoutBounds(local_88);
  AdaptionWidget_computeLayoutBounds(local_88);
  iVar3 = *(int *)(self + 0x148);
  local_8c = *(int *)(iVar3 + 0x38);
  mat4_identity();
  fVar14 = local_2c;
  fVar13 = local_30;
  fVar22 = local_34;
  fVar19 = local_38;
  fVar12 = local_48[3];
  fVar11 = local_48[2];
  fVar9 = local_48[1];
  fVar8 = local_48[0];
  iVar3 = *(int *)(iVar3 + 0x28);
  do {
    if (iVar3 == 0) {
LAB_006296c1:
      local_100 = local_c;
      local_d8 = local_10;
      local_104 = local_18;
      local_e4 = local_14;
LAB_006296f5:
      pfVar2 = (float *)AdaptionWidget_computeBoundsUnion(matrix);
      fVar10 = pfVar2[8];
      fVar21 = pfVar2[0xf];
      fVar17 = *pfVar2 * local_48[0] + pfVar2[1] * local_38 + pfVar2[2] * local_28 +
               pfVar2[3] * local_104;
      fVar6 = local_48[0] * pfVar2[4];
      local_48[0] = fVar17;
      fVar18 = pfVar2[5] * local_38 + fVar6 + pfVar2[6] * local_28 + pfVar2[7] * local_104;
      fVar7 = local_38 * pfVar2[9];
      fVar6 = pfVar2[0xd];
      local_38 = fVar18;
      fVar20 = pfVar2[0xe];
      fVar16 = local_28 * fVar20;
      fVar15 = pfVar2[0xc];
      local_28 = fVar8 * fVar10 + fVar7 + pfVar2[10] * local_28 + pfVar2[0xb] * local_104;
      local_18 = fVar8 * fVar15 + fVar19 * fVar6 + fVar16 + fVar21 * local_104;
      local_48[1] = *pfVar2 * local_48[1] + pfVar2[1] * local_34 + pfVar2[2] * local_24 +
                    pfVar2[3] * local_e4;
      fVar8 = local_34 * pfVar2[9];
      local_34 = pfVar2[5] * local_34 + fVar9 * pfVar2[4] + pfVar2[6] * local_24 +
                 pfVar2[7] * local_e4;
      fVar19 = local_24 * fVar20;
      local_24 = fVar9 * fVar10 + fVar8 + pfVar2[10] * local_24 + pfVar2[0xb] * local_e4;
      local_14 = fVar9 * fVar15 + fVar22 * fVar6 + fVar19 + fVar21 * local_e4;
      fVar8 = local_48[2] * pfVar2[4];
      local_48[2] = *pfVar2 * local_48[2] + pfVar2[1] * local_30 + pfVar2[2] * local_20 +
                    pfVar2[3] * local_d8;
      fVar9 = local_30 * pfVar2[9];
      local_30 = pfVar2[5] * local_30 + fVar8 + pfVar2[6] * local_20 + pfVar2[7] * local_d8;
      fVar8 = local_20 * fVar20;
      local_20 = fVar11 * fVar10 + fVar9 + pfVar2[10] * local_20 + pfVar2[0xb] * local_d8;
      local_10 = fVar11 * fVar15 + fVar13 * fVar6 + fVar8 + fVar21 * local_d8;
      fVar8 = local_48[3] * pfVar2[4];
      local_48[3] = *pfVar2 * local_48[3] + pfVar2[1] * local_2c + pfVar2[2] * local_1c +
                    pfVar2[3] * local_100;
      fVar9 = local_2c * pfVar2[9];
      local_2c = pfVar2[5] * local_2c + fVar8 + pfVar2[6] * local_1c + pfVar2[7] * local_100;
      fVar20 = local_1c * fVar20;
      local_1c = fVar12 * fVar10 + fVar9 + pfVar2[10] * local_1c + pfVar2[0xb] * local_100;
      fVar8 = *(float *)(self + 0xa8);
      local_c = fVar12 * fVar15 + fVar14 * fVar6 + fVar20 + fVar21 * local_100;
      fVar9 = *(float *)(self + 0xac);
      pfVar2 = local_48;
      pfVar5 = local_88;
      for (iVar3 = 0x10; fVar13 = local_5c, fVar22 = local_6c, fVar19 = local_88[3],
          fVar12 = local_88[2], fVar11 = local_88[1], iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar5 = pfVar5 + 1;
      }
      local_88[0] = fVar17 * fVar8 + fVar18 * fVar9 + local_28 * *(float *)(self + 0xb0) +
                    local_18 * *(float *)(self + 0xb4);
      local_78 = fVar17 * *(float *)(self + 0xb8) + fVar18 * *(float *)(self + 0xbc) +
                 local_28 * *(float *)(self + 0xc0) + local_18 * *(float *)(self + 0xc4);
      fVar9 = *(float *)(self + 0xe0);
      fVar14 = *(float *)(self + 0xd8);
      local_68 = *(float *)(self + 200) * fVar17 + *(float *)(self + 0xcc) * fVar18 +
                 local_28 * *(float *)(self + 0xd0) + *(float *)(self + 0xd4) * local_18;
      local_58 = fVar14 * fVar17 + *(float *)(self + 0xdc) * fVar18 + local_28 * fVar9 +
                 *(float *)(self + 0xe4) * local_18;
      fVar10 = local_88[1] * *(float *)(self + 0xb8);
      local_88[1] = local_88[1] * fVar8 + local_74 * *(float *)(self + 0xac) +
                    local_64 * *(float *)(self + 0xb0) + local_54 * *(float *)(self + 0xb4);
      fVar8 = local_74 * *(float *)(self + 0xcc);
      fVar21 = local_74 * *(float *)(self + 0xdc);
      local_74 = local_74 * *(float *)(self + 0xbc) + fVar10 +
                 local_64 * *(float *)(self + 0xc0) + local_54 * *(float *)(self + 0xc4);
      fVar10 = local_64 * fVar9;
      local_64 = fVar11 * *(float *)(self + 200) + fVar8 + local_64 * *(float *)(self + 0xd0) +
                 local_54 * *(float *)(self + 0xd4);
      local_54 = fVar11 * fVar14 + fVar21 + fVar10 + local_54 * *(float *)(self + 0xe4);
      fVar8 = local_88[2] * *(float *)(self + 0xb8);
      local_88[2] = local_88[2] * *(float *)(self + 0xa8) + local_70 * *(float *)(self + 0xac) +
                    local_60 * *(float *)(self + 0xb0) + local_50 * *(float *)(self + 0xb4);
      fVar11 = local_70 * *(float *)(self + 0xcc);
      fVar10 = local_70 * *(float *)(self + 0xdc);
      local_70 = local_70 * *(float *)(self + 0xbc) + fVar8 + local_60 * *(float *)(self + 0xc0)
                 + local_50 * *(float *)(self + 0xc4);
      fVar8 = local_60 * fVar9;
      local_60 = fVar12 * *(float *)(self + 200) + fVar11 + local_60 * *(float *)(self + 0xd0) +
                 local_50 * *(float *)(self + 0xd4);
      local_50 = fVar12 * fVar14 + fVar10 + fVar8 + local_50 * *(float *)(self + 0xe4);
      fVar8 = local_88[3] * *(float *)(self + 0xb8);
      local_88[3] = local_88[3] * *(float *)(self + 0xa8) + local_6c * *(float *)(self + 0xac) +
                    local_5c * *(float *)(self + 0xb0) + local_4c * *(float *)(self + 0xb4);
      fVar11 = local_6c * *(float *)(self + 0xcc);
      local_6c = local_6c * *(float *)(self + 0xbc) + fVar8 + local_5c * *(float *)(self + 0xc0)
                 + local_4c * *(float *)(self + 0xc4);
      fVar8 = *(float *)(local_8c + 500);
      local_5c = fVar19 * *(float *)(self + 200) + fVar11 + local_5c * *(float *)(self + 0xd0) +
                 local_4c * *(float *)(self + 0xd4);
      fVar11 = *(float *)(local_8c + 0x1f0);
      fVar12 = *(float *)(local_8c + 0x1f8);
      fVar10 = *(float *)(local_8c + 0x228);
      local_4c = fVar19 * fVar14 + fVar22 * *(float *)(self + 0xdc) + fVar13 * fVar9 +
                 local_4c * *(float *)(self + 0xe4);
      pfVar2 = local_88;
      pfVar5 = local_48;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar5 = pfVar5 + 1;
      }
      local_48[0] = fVar11 * local_88[0] + fVar8 * local_78 + fVar12 * local_68 +
                    *(float *)(local_8c + 0x1fc) * local_58;
      local_38 = *(float *)(local_8c + 0x200) * local_88[0] +
                 *(float *)(local_8c + 0x204) * local_78 + *(float *)(local_8c + 0x208) * local_68 +
                 *(float *)(local_8c + 0x20c) * local_58;
      fVar8 = *(float *)(local_8c + 0x220);
      local_28 = *(float *)(local_8c + 0x210) * local_88[0] +
                 *(float *)(local_8c + 0x214) * local_78 + *(float *)(local_8c + 0x218) * local_68 +
                 *(float *)(local_8c + 0x21c) * local_58;
      local_18 = fVar8 * local_88[0] + *(float *)(local_8c + 0x224) * local_78 + fVar10 * local_68 +
                 *(float *)(local_8c + 0x22c) * local_58;
      fVar12 = local_24 * fVar12;
      fVar9 = *(float *)(local_8c + 0x1fc) * local_14;
      fVar17 = local_48[1] * *(float *)(local_8c + 0x200);
      fVar11 = local_24 * *(float *)(local_8c + 0x208);
      fVar19 = *(float *)(local_8c + 0x20c) * local_14;
      fVar22 = local_24 * fVar10;
      local_24 = local_48[1] * *(float *)(local_8c + 0x210) +
                 local_34 * *(float *)(local_8c + 0x214) + local_24 * *(float *)(local_8c + 0x218) +
                 *(float *)(local_8c + 0x21c) * local_14;
      local_14 = local_48[1] * fVar8 + local_34 * *(float *)(local_8c + 0x224) + fVar22 +
                 *(float *)(local_8c + 0x22c) * local_14;
      fVar22 = local_20 * *(float *)(local_8c + 0x1f8);
      fVar13 = local_10 * *(float *)(local_8c + 0x1fc);
      fVar14 = local_48[2] * *(float *)(local_8c + 0x200);
      fVar21 = local_20 * *(float *)(local_8c + 0x208);
      fVar6 = local_10 * *(float *)(local_8c + 0x20c);
      fVar20 = local_20 * fVar10;
      local_20 = local_48[2] * *(float *)(local_8c + 0x210) +
                 local_30 * *(float *)(local_8c + 0x214) + local_20 * *(float *)(local_8c + 0x218) +
                 local_10 * *(float *)(local_8c + 0x21c);
      local_10 = local_48[2] * fVar8 + local_30 * *(float *)(local_8c + 0x224) + fVar20 +
                 local_10 * *(float *)(local_8c + 0x22c);
      fVar20 = local_1c * *(float *)(local_8c + 0x1f8);
      fVar15 = *(float *)(local_8c + 0x1fc) * local_c;
      fVar18 = local_48[3] * *(float *)(local_8c + 0x200);
      fVar7 = local_1c * *(float *)(local_8c + 0x208);
      fVar16 = *(float *)(local_8c + 0x20c) * local_c;
      fVar10 = local_1c * fVar10;
      local_1c = local_48[3] * *(float *)(local_8c + 0x210) +
                 local_2c * *(float *)(local_8c + 0x214) + local_1c * *(float *)(local_8c + 0x218) +
                 *(float *)(local_8c + 0x21c) * local_c;
      local_c = local_48[3] * fVar8 + local_2c * *(float *)(local_8c + 0x224) + fVar10 +
                *(float *)(local_8c + 0x22c) * local_c;
      local_48[1] = *(float *)(local_8c + 0x1f0) * local_48[1] +
                    *(float *)(local_8c + 500) * local_34 + fVar12 + fVar9;
      local_48[2] = local_48[2] * *(float *)(local_8c + 0x1f0) +
                    local_30 * *(float *)(local_8c + 500) + fVar22 + fVar13;
      local_48[3] = *(float *)(local_8c + 0x1f0) * local_48[3] +
                    *(float *)(local_8c + 500) * local_2c + fVar20 + fVar15;
      local_34 = fVar17 + *(float *)(local_8c + 0x204) * local_34 + fVar11 + fVar19;
      local_30 = local_30 * *(float *)(local_8c + 0x204) + fVar14 + fVar21 + fVar6;
      local_2c = fVar18 + *(float *)(local_8c + 0x204) * local_2c + fVar7 + fVar16;
      Matrix4_Invert();
      iVar3 = *(int *)(*(int *)(self + 0x148) + 0x38);
      mat4_mulRight(local_88,self + 0xe8);
      fVar11 = 1.0 / (local_6c * 0.0 + local_88[3] * 0.0 + local_4c);
      fVar8 = position[1];
      fVar9 = *position;
      iVar4 = *(int *)(iVar3 + 0x68);
      iVar3 = *(int *)(iVar3 + 0x94);
      fVar12 = 1.0 / (fVar9 * local_48[3] + fVar8 * local_2c + local_c);
      *(float *)(iVar3 + iVar4 * 8) =
           (fVar12 * (fVar9 * local_48[0] + fVar8 * local_38 + local_18) -
           fVar11 * (local_78 * 0.0 + local_88[0] * 0.0 + local_58)) + *(float *)(iVar3 + iVar4 * 8)
      ;
      *(float *)(iVar3 + 4 + iVar4 * 8) =
           (fVar12 * (fVar9 * local_48[1] + fVar8 * local_34 + local_14) -
           fVar11 * (local_74 * 0.0 + local_88[1] * 0.0 + local_54)) +
           *(float *)(iVar3 + 4 + iVar4 * 8);
      (**(code **)(**(int **)(*(int *)(self + 0x148) + 0x38) + 4))(1);
      AdaptionWidget_computeLayoutBounds(matrix);
      AdaptionWidget_computeLayoutBounds(matrix);
      if (notify == '\0') {
        *(undefined1 *)(*(int *)(*(int *)(self + 0x148) + 0x38) + 0x2d) = uVar1;
        AdaptionWidget_recompute_transforms_recursive();
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      if (*(int *)(iVar3 + 0x40) != 0) {
        pfVar2 = (float *)AdaptionWidget_computeBoundsUnion(local_88);
        fVar21 = 1.0 / (pfVar2[7] * 0.0 + pfVar2[3] * 0.0 + pfVar2[0xf]);
        fVar10 = fVar21 * (pfVar2[4] * 0.0 + *pfVar2 * 0.0 + pfVar2[0xc]) * -1.0;
        fVar21 = fVar21 * (pfVar2[5] * 0.0 + pfVar2[1] * 0.0 + pfVar2[0xd]) * -1.0;
        local_104 = local_38 * fVar21 + local_48[0] * fVar10 + local_18;
        local_e4 = local_34 * fVar21 + local_48[1] * fVar10 + local_14;
        local_d8 = local_30 * fVar21 + local_48[2] * fVar10 + local_10;
        local_100 = local_2c * fVar21 + local_48[3] * fVar10 + local_c;
        goto LAB_006296f5;
      }
      goto LAB_006296c1;
    }
    iVar3 = *(int *)(iVar3 + 0x28);
  } while( true );
}




/* cube::AdaptionWidget::vfunc_35 @ 0062a690 */

void cube::AdaptionWidget::vfunc_35(void)

{
  int first_child;
  char handled;
  undefined4 *anchor;
  int self;
  int focus_widget;
  undefined1 local_10 [8];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if ((((*(byte *)(self + 0x128) & 1) != 0) || ((*(uint *)(self + 0x128) >> 1 & 1) != 0)) &&
     (first_child = *(int *)(*(int *)(self + 0x148) + 0x28), focus_widget = first_child, first_child != 0)) {
    while (*(int *)(focus_widget + 0x40) == 0) {
      focus_widget = *(int *)(focus_widget + 0x28);
      if (focus_widget == 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    for (; first_child != 0; first_child = *(int *)(first_child + 0x28)) {
      if (*(int *)(first_child + 0x40) != 0) {
        focus_widget = *(int *)(first_child + 0x40);
        goto LAB_0062a6ff;
      }
    }
    focus_widget = 0;
LAB_0062a6ff:
    handled = AdaptionWidget_layoutRecursive(*(undefined4 *)(focus_widget + 0x148));
    if (handled != '\0') {
      Widget_set_flags_word(*(undefined4 *)(self + 0x148));
      anchor = (undefined4 *)AdaptionWidget_getScrollFlag(local_10);
      *(undefined4 *)(self + 0x98) = *anchor;
      *(undefined4 *)(self + 0x9c) = anchor[1];
      focus_widget = *(int *)(*(int *)(self + 0x148) + 0x38);
      first_child = *(int *)(focus_widget + 0x68);
      focus_widget = *(int *)(focus_widget + 0x94);
      *(undefined4 *)(self + 0xa0) = *(undefined4 *)(focus_widget + first_child * 8);
      *(undefined4 *)(self + 0xa4) = *(undefined4 *)(focus_widget + 4 + first_child * 8);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_36 @ 0062a780 */

void cube::AdaptionWidget::vfunc_36(void)

{
  int self;
  
  if ((((*(byte *)(self + 0x128) & 1) != 0) || ((*(uint *)(self + 0x128) >> 1 & 1) != 0)) &&
     (*(int *)(*(int *)(self + 4) + 200) == *(int *)(self + 0x148))) {
    AdaptionWidget_clear_hover();
    return;
  }
  return;
}




/* cube::AdaptionWidget::vfunc_39 @ 0062a7b0 */

void cube::AdaptionWidget::vfunc_39(void)

{
  float fVar1;
  int first_child;
  char handled;
  undefined4 *puVar4;
  int self;
  int focus_widget;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined4 local_10;
  float pos_y;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (((*(uint *)(self + 0x128) >> 1 & 1) != 0) &&
     (first_child = *(int *)(*(int *)(self + 0x148) + 0x28), focus_widget = first_child, first_child != 0)) {
    while (*(int *)(focus_widget + 0x40) == 0) {
      focus_widget = *(int *)(focus_widget + 0x28);
      if (focus_widget == 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    for (; first_child != 0; first_child = *(int *)(first_child + 0x28)) {
      if (*(int *)(first_child + 0x40) != 0) {
        focus_widget = *(int *)(first_child + 0x40);
        goto LAB_0062a819;
      }
    }
    focus_widget = 0;
LAB_0062a819:
    handled = AdaptionWidget_layoutRecursive(*(undefined4 *)(focus_widget + 0x148));
    if (handled != '\0') {
      focus_widget = AdaptionWidget_getContentSize(local_18);
      fVar1 = *(float *)(focus_widget + 4);
      focus_widget = *(int *)(*(int *)(self + 4) + 0x100);
      puVar4 = (undefined4 *)AdaptionWidget_getContentSize(local_20);
      local_10 = *puVar4;
      pos_y = (float)(focus_widget * 10) + fVar1;
      AdaptionWidget_applyScrollLayout(&local_10,1);
      AdaptionWidget_clampScrollToContent();
      Widget_dispatch_event_callback(*(undefined4 *)(self + 0x148),0x11);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_7 @ 0062a8b0 */

void cube::AdaptionWidget::vfunc_7(void)

{
  uint security_cookie;
  undefined4 uVar2;
  int self;
  void *event_buf [5];
  uint local_30;
  void *event_buf2 [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f56e0;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(self + 0x138) = *(undefined4 *)(*(int *)(self + 4) + 0x10c);
  *(undefined4 *)(self + 0x13c) = *(undefined4 *)(*(int *)(self + 4) + 0x110);
  *(float *)(self + 0x78) = *(float *)(self + 0x60) - *(float *)(self + 0x50);
  *(float *)(self + 0x7c) = *(float *)(self + 100) - *(float *)(self + 0x54);
  local_14 = security_cookie;
  if (*(char *)(self + 0x15c) == '\0') {
    u16string_assignCStr(L"widget:disable");
    local_8 = 0;
    AdaptionWidget_apply_to_attributes(event_buf,0);
    local_8 = 0xffffffff;
    if (7 < local_30) {
      operator_delete(event_buf[0]);
    }
    u16string_assignCStr(L"widget:disable");
    local_8 = 1;
    uVar2 = AdaptionWidget_compute_max_content_width(event_buf2);
    AdaptionWidget_relayout(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_18) {
      operator_delete(event_buf2[0]);
    }
    local_18 = 7;
    local_1c = 0;
    event_buf2[0] = (void *)((uint)event_buf2[0] & 0xffff0000);
  }
  local_8 = 0xffffffff;
  AdaptionWidget_setCaption(security_cookie);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_11 @ 0062a9e0 */

void cube::AdaptionWidget::vfunc_11(void)

{
  float *matrix;
  int self;
  float fVar2;
  float fVar3;
  float world_y;
  float world_x;
  undefined1 matrix_buf [64];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if ((*(uint *)(self + 0x128) >> 7 & 1) != 0) {
    *(undefined2 *)(self + 0x14c) = 0;
    matrix = (float *)AdaptionWidget_computeLayoutBounds(matrix_buf);
    world_y = 1.0 / (matrix[7] * 0.0 + matrix[3] * 0.0 + matrix[0xf]);
    world_x = *(float *)(*(int *)(self + 4) + 0xd4) -
            world_y * (matrix[4] * 0.0 + *matrix * 0.0 + matrix[0xc]);
    world_y = *(float *)(*(int *)(self + 4) + 0xd8) -
            world_y * (matrix[5] * 0.0 + matrix[1] * 0.0 + matrix[0xd]);
    if (world_x < (*(float *)(self + 0x68) + *(float *)(self + 0x48)) - *(float *)(self + 0x58))
    {
      Widget_set_flags_word(*(undefined4 *)(self + 0x148));
      *(undefined1 *)(self + 0x14c) = 0xff;
    }
    fVar3 = (*(float *)(self + 0x50) + *(float *)(self + 0x78)) - *(float *)(self + 0x60);
    fVar2 = (*(float *)(self + 0x50) + *(float *)(self + 0x70)) - *(float *)(self + 0x60);
    if (fVar3 < 0.0) {
      fVar3 = 0.0;
    }
    if (fVar2 < fVar3) {
      fVar2 = fVar3;
    }
    if (fVar2 + ((*(float *)(self + 0x68) + *(float *)(self + 0x48)) - *(float *)(self + 0x58)
                ) < world_x) {
      Widget_set_flags_word(*(undefined4 *)(self + 0x148));
      *(undefined1 *)(self + 0x14c) = 1;
    }
    if (world_y < (*(float *)(self + 0x6c) + *(float *)(self + 0x4c)) - *(float *)(self + 0x5c))
    {
      Widget_set_flags_word(*(undefined4 *)(self + 0x148));
      *(undefined1 *)(self + 0x14d) = 0xff;
    }
    fVar2 = (*(float *)(self + 0x7c) + *(float *)(self + 0x54)) - *(float *)(self + 100);
    world_x = (*(float *)(self + 0x74) + *(float *)(self + 0x54)) - *(float *)(self + 100);
    if (fVar2 < 0.0) {
      fVar2 = 0.0;
    }
    if (world_x < fVar2) {
      world_x = fVar2;
    }
    if (world_x + ((*(float *)(self + 0x6c) + *(float *)(self + 0x4c)) - *(float *)(self + 0x5c)
                ) < world_y) {
      Widget_set_flags_word(*(undefined4 *)(self + 0x148));
      *(undefined1 *)(self + 0x14d) = 1;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_12 @ 0062abe0 */

void cube::AdaptionWidget::vfunc_12(void)

{
  int focus_widget;
  int self;
  
  focus_widget = *(int *)(*(int *)(self + 4) + 200);
  if ((focus_widget != 0) && (*(int *)(focus_widget + 0x44) == self)) {
    AdaptionWidget_clear_hover();
  }
  *(undefined2 *)(self + 0x14c) = 0;
  return;
}




/* cube::AdaptionWidget::vfunc_21 @ 0062ac20 */

/* WARNING: Type propagation algorithm not settling */

void cube::AdaptionWidget::vfunc_21(void)

{
  float fVar1;
  char mode;
  int iVar3;
  float *pfVar4;
  int self;
  int axis;
  float fVar6;
  float fVar7;
  float local_70;
  float local_6c;
  float local_60;
  float local_5c;
  float delta [4];
  float local_20;
  float local_1c;
  float velocity [4];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if ((((*(uint *)(self + 0x128) >> 7 & 1) != 0) &&
      ((*(byte *)(*(int *)(self + 4) + 0xf4) & 1) != 0)) &&
     ((*(char *)(self + 0x14c) != '\0' || (*(char *)(self + 0x14d) != '\0')))) {
    AdaptionWidget_getContentSize(velocity);
    AdaptionWidget_getBoundsRect(velocity + 2);
    axis = 0;
    do {
      mode = *(char *)(self + 0x14c + axis);
      if (mode == -1) {
        AdaptionWidget_computeLayoutBounds(&local_70);
        Matrix4_Invert();
        iVar3 = *(int *)(self + 4);
        fVar7 = *(float *)(iVar3 + 0xd4) - *(float *)(iVar3 + 0xdc);
        fVar6 = *(float *)(iVar3 + 0xd8) - *(float *)(iVar3 + 0xe0);
        delta[0] = fVar6 * local_60 + fVar7 * local_70;
        delta[1] = local_5c * fVar6 + local_6c * fVar7;
        velocity[axis] = delta[axis] + velocity[axis];
        AdaptionWidget_computeLayoutBounds(&local_70);
        Matrix4_Invert();
        iVar3 = *(int *)(self + 4);
        fVar7 = *(float *)(iVar3 + 0xd4) - *(float *)(iVar3 + 0xdc);
        fVar6 = *(float *)(iVar3 + 0xd8) - *(float *)(iVar3 + 0xe0);
        local_20 = fVar6 * local_60 + fVar7 * local_70;
        local_1c = local_5c * fVar6 + local_6c * fVar7;
        fVar6 = velocity[axis + 2] - delta[axis + 4];
LAB_0062ae05:
        velocity[axis + 2] = fVar6;
      }
      else if (mode == '\x01') {
        AdaptionWidget_computeLayoutBounds(&local_70);
        Matrix4_Invert();
        iVar3 = *(int *)(self + 4);
        fVar7 = *(float *)(iVar3 + 0xd4) - *(float *)(iVar3 + 0xdc);
        fVar6 = *(float *)(iVar3 + 0xd8) - *(float *)(iVar3 + 0xe0);
        delta[2] = fVar6 * local_60 + fVar7 * local_70;
        delta[3] = local_5c * fVar6 + local_6c * fVar7;
        fVar6 = delta[axis + 2] + velocity[axis + 2];
        goto LAB_0062ae05;
      }
      axis = axis + 1;
    } while (axis < 2);
    AdaptionWidget_applyScrollLayout(velocity,0);
    AdaptionWidget_measureContent(velocity + 2,1);
  }
  if ((((*(byte *)(self + 0x128) & 1) != 0) || ((*(uint *)(self + 0x128) >> 1 & 1) != 0)) &&
     ((*(uint *)(*(int *)(self + 4) + 0xf4) >> 2 & 1) != 0)) {
    pfVar4 = (float *)AdaptionWidget_getScrollFlag(delta + 4);
    fVar7 = *pfVar4 - *(float *)(self + 0x98);
    fVar6 = pfVar4[1] - *(float *)(self + 0x9c);
    if ((*(byte *)(self + 0x128) & 1) == 0) {
      fVar7 = 0.0;
    }
    if ((*(uint *)(self + 0x128) >> 1 & 1) == 0) {
      fVar6 = 0.0;
    }
    fVar1 = *(float *)(self + 0xa4);
    axis = *(int *)(*(int *)(self + 0x148) + 0x38);
    iVar3 = *(int *)(axis + 0x68);
    axis = *(int *)(axis + 0x94);
    *(float *)(axis + iVar3 * 8) = *(float *)(self + 0xa0) + fVar7;
    *(float *)(axis + 4 + iVar3 * 8) = fVar1 + fVar6;
    (**(code **)(**(int **)(*(int *)(self + 0x148) + 0x38) + 4))(1);
    AdaptionWidget_clampScrollToContent();
    Widget_dispatch_event_callback(*(undefined4 *)(self + 0x148),0x11);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_9 @ 0062af10 */

void cube::AdaptionWidget::vfunc_9(float *delta,float *total)

{
  uint uVar1;
  int child;
  float *pfVar3;
  int self;
  float fVar4;
  float fVar5;
  float local_e4;
  undefined1 local_e0 [64];
  undefined1 local_a0 [64];
  float local_60;
  float local_5c;
  float local_50;
  float local_4c;
  float local_40;
  float local_3c;
  float local_30;
  float local_2c;
  undefined1 local_20 [8];
  undefined1 local_18 [4];
  float local_14;
  float new_x;
  float new_y;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (*(int *)(*(int *)(self + 0x148) + 0x28) == 0) goto LAB_0062b269;
  if ((*(int *)(self + 0x130) == 1) && ((*(uint *)(self + 0x128) >> 2 & 1) == 0)) {
    child = AdaptionWidget_getContentSize(local_18);
    local_e4 = *(float *)(child + 4);
    pfVar3 = (float *)AdaptionWidget_getContentSize(local_20);
    new_x = *delta + *pfVar3 + *total;
LAB_0062afbf:
    new_y = local_e4;
    AdaptionWidget_applyScrollLayout(&new_x,1);
  }
  else if (*(int *)(self + 0x130) == 2) {
    child = AdaptionWidget_getContentSize(local_20);
    local_e4 = *(float *)(child + 4);
    pfVar3 = (float *)AdaptionWidget_getContentSize(local_18);
    new_x = *total * 0.5 + *pfVar3;
    goto LAB_0062afbf;
  }
  if ((*(int *)(self + 300) == 1) && ((*(uint *)(self + 0x128) >> 3 & 1) == 0)) {
    child = AdaptionWidget_getContentSize(local_20);
    fVar4 = *(float *)(child + 4);
    pfVar3 = (float *)AdaptionWidget_getContentSize(local_18);
    new_x = *pfVar3;
    new_y = delta[1] + fVar4 + total[1];
LAB_0062b07c:
    AdaptionWidget_applyScrollLayout(&new_x,1);
  }
  else if (*(int *)(self + 300) == 2) {
    child = AdaptionWidget_getContentSize(local_20);
    fVar4 = *(float *)(child + 4);
    pfVar3 = (float *)AdaptionWidget_getContentSize(local_18);
    new_x = *pfVar3;
    new_y = total[1] * 0.5 + fVar4;
    goto LAB_0062b07c;
  }
  mat4_identity();
  for (child = *(int *)(*(int *)(self + 0x148) + 0x28); child != 0; child = *(int *)(child + 0x28)
      ) {
    if (*(int *)(child + 0x40) != 0) {
      if (*(int *)(child + 0x40) != 0) {
        pfVar3 = (float *)AdaptionWidget_computeBoundsUnion(local_a0);
        fVar4 = 1.0 / (pfVar3[7] * 0.0 + pfVar3[3] * 0.0 + pfVar3[0xf]);
        fVar5 = (pfVar3[4] * 0.0 + *pfVar3 * 0.0 + pfVar3[0xc]) * fVar4 * -1.0;
        fVar4 = (pfVar3[5] * 0.0 + pfVar3[1] * 0.0 + pfVar3[0xd]) * fVar4 * -1.0;
        local_14 = local_50 * fVar4 + local_60 * fVar5 + local_30;
        local_e4 = local_4c * fVar4 + local_5c * fVar5 + local_2c;
        goto LAB_0062b0cb;
      }
      break;
    }
  }
  local_e4 = local_2c;
  local_14 = local_30;
LAB_0062b0cb:
  pfVar3 = (float *)AdaptionWidget_computeBoundsUnion(local_e0);
  new_y = *pfVar3 * local_60 + pfVar3[1] * local_50 + pfVar3[2] * local_40 + pfVar3[3] * local_14;
  uVar1 = *(uint *)(self + 0x128);
  fVar4 = pfVar3[7] * local_14;
  local_14 = *pfVar3 * local_5c + pfVar3[1] * local_4c + pfVar3[2] * local_3c + pfVar3[3] * local_e4
  ;
  fVar4 = new_y * *(float *)(self + 0x70) +
          (pfVar3[5] * local_50 + pfVar3[4] * local_60 + pfVar3[6] * local_40 + fVar4) *
          *(float *)(self + 0x74);
  fVar5 = local_14 * *(float *)(self + 0x70) +
          (pfVar3[5] * local_4c + pfVar3[4] * local_5c + pfVar3[6] * local_3c + pfVar3[7] * local_e4
          ) * *(float *)(self + 0x74);
  if (((uVar1 >> 2 & 1) != 0) || ((uVar1 >> 3 & 1) != 0)) {
    new_x = fVar4;
    if ((uVar1 >> 2 & 1) != 0) {
      new_x = fVar4 + *total;
    }
    new_y = fVar5;
    if ((uVar1 >> 3 & 1) != 0) {
      new_y = total[1] + fVar5;
    }
    AdaptionWidget_measureContent(&new_x,1);
  }
  if (*(int *)(self + 0x140) != 0) {
    Widget_layoutAspectFit();
  }
  if (*(int *)(self + 0x144) != 0) {
    Widget_layoutAspectFit();
  }
  if ((*(int *)(self + 0x144) != 0) || (*(int *)(self + 0x140) != 0)) {
    AdaptionWidget_clampScrollToContent();
  }
LAB_0062b269:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::AdaptionWidget::vfunc_8 @ 0062b350 */

void cube::AdaptionWidget::vfunc_8(void)

{
  int child;
  int *self;
  undefined4 local_18;
  undefined4 local_14;
  float delta_x;
  float delta_y;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  for (child = *(int *)(self[0x52] + 0x28); child != 0; child = *(int *)(child + 0x28)) {
    if (*(int *)(child + 0x40) != 0) goto LAB_0062b3cd;
  }
  delta_x = (float)(*(int *)(self[1] + 0x10c) - self[0x4e]);
  delta_y = (float)(*(int *)(self[1] + 0x110) - self[0x4f]);
  local_18 = 0;
  local_14 = 0;
  (**(code **)(*self + 0x24))(&local_18,&delta_x);
LAB_0062b3cd:
  self[0x4e] = *(int *)(self[1] + 0x10c);
  self[0x4f] = *(int *)(self[1] + 0x110);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget_onContentResized  (confidence: low)
 * purpose: Notifies/handles content resize (no callees); shared vfunc target
 * vars: no args
 */
/* Global::AdaptionWidget_onContentResized @ 0062b400 */

undefined4 AdaptionWidget_onContentResized(void)

{
  int child;
  int self;
  
  child = *(int *)(*(int *)(self + 0x148) + 0x28);
  while( true ) {
    if (child == 0) {
      return 0;
    }
    if (*(int *)(child + 0x40) != 0) break;
    child = *(int *)(child + 0x28);
  }
  return *(undefined4 *)(child + 0x40);
}




/* [AUDIT] proposed: AdaptionWidget_getScrollFlag  (confidence: low)
 * purpose: Returns a scroll/state flag (no callees)
 * vars: returns undefined4
 */
/* Global::AdaptionWidget_getScrollFlag @ 0062b430 */

float * AdaptionWidget_getScrollFlag(float *out_pos)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int child;
  int self;
  float inv_w;
  
  child = *(int *)(*(int *)(self + 0x148) + 0x28);
  if (child != 0) {
    fVar1 = *(float *)(*(int *)(self + 4) + 0xd4);
    fVar2 = *(float *)(*(int *)(self + 4) + 0xd8);
    fVar3 = *(float *)(child + 0x8c);
    inv_w = 1.0 / (*(float *)(child + 0x94) * fVar1 + *(float *)(child + 0xa4) * fVar2 +
                  *(float *)(child + 0xc4));
    fVar4 = *(float *)(child + 0x9c);
    fVar5 = *(float *)(child + 0xbc);
    *out_pos = inv_w * (*(float *)(child + 0x98) * fVar2 + fVar1 * *(float *)(child + 0x88) +
                       *(float *)(child + 0xb8));
    out_pos[1] = inv_w * (fVar3 * fVar1 + fVar4 * fVar2 + fVar5);
    return out_pos;
  }
  child = *(int *)(self + 4);
  *out_pos = *(float *)(child + 0xd4);
  out_pos[1] = *(float *)(child + 0xd8);
  return out_pos;
}




/* [AUDIT] proposed: AdaptionWidget_getContentSize  (confidence: med)
 * purpose: Computes content/preferred size into out_pos (AdaptionWidget_computeBoundsUnion bounds union)
 * vars: out_pos float* out size
 */
/* Global::AdaptionWidget_getContentSize @ 0062b510 */

void AdaptionWidget_getContentSize(float *out_point)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int child;
  float *matrix;
  int self;
  float fVar13;
  float fVar14;
  float fVar15;
  float local_d8;
  float local_d0;
  float local_cc;
  undefined1 local_c8 [64];
  undefined1 local_88 [64];
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  float local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  mat4_identity();
  child = *(int *)(*(int *)(self + 0x148) + 0x28);
  do {
    if (child == 0) {
LAB_0062b551:
      local_d0 = local_c;
      local_d8 = local_14;
      local_cc = local_18;
LAB_0062b578:
      matrix = (float *)AdaptionWidget_computeBoundsUnion(local_c8);
      fVar13 = matrix[0xd];
      fVar15 = matrix[0xe];
      fVar1 = *matrix;
      fVar2 = matrix[1];
      fVar3 = matrix[5];
      fVar4 = matrix[2];
      fVar5 = matrix[3];
      fVar6 = matrix[4];
      fVar7 = matrix[0xc];
      fVar8 = matrix[6];
      fVar9 = matrix[7];
      fVar10 = matrix[0xf];
      fVar14 = 1.0 / ((local_3c * *matrix + local_2c * matrix[1] + local_1c * matrix[2] +
                      local_d0 * matrix[3]) * 0.0 +
                      (local_2c * matrix[5] + matrix[4] * local_3c + local_1c * matrix[6] +
                      local_d0 * matrix[7]) * 0.0 +
                     matrix[0xd] * local_2c + fVar7 * local_3c + local_1c * fVar15 +
                     local_d0 * matrix[0xf]);
      *out_point = ((local_48 * *matrix + local_38 * matrix[1] + local_28 * matrix[2] +
                  local_cc * matrix[3]) * 0.0 +
                  (local_38 * matrix[5] + matrix[4] * local_48 + local_28 * matrix[6] +
                  local_cc * matrix[7]) * 0.0 +
                 matrix[0xd] * local_38 + matrix[0xc] * local_48 + local_28 * fVar15 +
                 local_cc * matrix[0xf]) * fVar14;
      out_point[1] = ((local_44 * fVar1 + local_34 * fVar2 + local_24 * fVar4 + local_d8 * fVar5) *
                    0.0 + (local_34 * fVar3 + fVar6 * local_44 + local_24 * fVar8 + local_d8 * fVar9
                          ) * 0.0 +
                   fVar13 * local_34 + fVar7 * local_44 + local_24 * fVar15 + local_d8 * fVar10) *
                   fVar14;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*(int *)(child + 0x40) != 0) {
      if (*(int *)(child + 0x40) != 0) {
        matrix = (float *)AdaptionWidget_computeBoundsUnion(local_88);
        fVar13 = 1.0 / (matrix[7] * 0.0 + matrix[3] * 0.0 + matrix[0xf]);
        fVar15 = (matrix[4] * 0.0 + *matrix * 0.0 + matrix[0xc]) * fVar13 * -1.0;
        fVar13 = (matrix[5] * 0.0 + matrix[1] * 0.0 + matrix[0xd]) * fVar13 * -1.0;
        local_cc = local_38 * fVar13 + local_48 * fVar15 + local_18;
        local_d8 = local_34 * fVar13 + local_44 * fVar15 + local_14;
        local_d0 = local_2c * fVar13 + local_3c * fVar15 + local_c;
        goto LAB_0062b578;
      }
      goto LAB_0062b551;
    }
    child = *(int *)(child + 0x28);
  } while( true );
}




/* [AUDIT] proposed: AdaptionWidget_setCaption  (confidence: med)
 * purpose: Sets widget caption/title text ('caption'), frees old string (operator_delete)
 * vars: 'caption'; Widget_destroyTailSlot string; +0x?? text
 */
/* Global::AdaptionWidget_setCaption @ 0062b920 */

void AdaptionWidget_setCaption(void)

{
  int style;
  int *node2;
  int self;
  int *node;
  int *widget_list;
  undefined4 local_30;
  void *name_buf [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f5720;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(self + 0x90) == 0) || (*(int *)(self + 0x148) == 0)) {
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  widget_list = (int *)0x0;
  local_30 = 0;
  ExceptionList = &local_10;
  widget_list = (int *)list_buyNode_0c(0,0);
  local_8 = 0;
  u16string_assignCStr(L"caption");
  local_8._0_1_ = 1;
  Node_collect_matching_children(&widget_list,name_buf);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_18) {
    operator_delete(name_buf[0]);
  }
  node = (int *)*widget_list;
  node2 = widget_list;
  if (node != widget_list) {
    do {
      style = *(int *)(node[2] + 0x34);
      if ((style != 0) && (*(int *)(style + 0x48) == 3)) {
        Widget_destroyTailSlot(self + 0x80,node[2]);
        node2 = widget_list;
      }
      node = (int *)*node;
    } while (node != node2);
  }
  node = (int *)*node2;
  *node2 = (int)node2;
  widget_list[1] = (int)widget_list;
  local_30 = 0;
  if (node == widget_list) {
    operator_delete(widget_list);
  }
  operator_delete(node);
}




/* [AUDIT] proposed: Widget_measureChildrenRecursive  (confidence: low)
 * purpose: Recursively measures child widgets (self-call, AdaptionWidget_compute_local_transform)
 * vars: self-recursive; param_3 float* out
 */
/* Global::Widget_measureChildrenRecursive @ 0062ba50 */

void Widget_measureChildrenRecursive(int widget,undefined4 param_2,float *delta,undefined4 apply)

{
  int *self;
  int *child;
  
  if ((~(byte)(*(uint *)(widget + 200) >> 2) & 1) != 0) {
    child = *(int **)(widget + 0x40);
    if ((child == self) || (child == (int *)0x0)) {
      AdaptionWidget_compute_local_transform();
      if ((*delta != 0.0) || (delta[1] != 0.0)) {
        *(undefined1 *)(self + 0x4d) = 1;
        child = (int *)**(int **)(widget + 0x2c);
        if (child != *(int **)(widget + 0x2c)) {
          do {
            Widget_measureChildrenRecursive(child[2],param_2,delta,apply);
            child = (int *)*child;
          } while (child != (int *)*(int *)(widget + 0x2c));
        }
      }
    }
    else if ((char)apply != '\0') {
      (**(code **)(*child + 0x24))(param_2,delta);
      return;
    }
  }
  return;
}




/* [AUDIT] proposed: AdaptionWidget_measureContent  (confidence: med)
 * purpose: Measures content bounds recursively (Widget_measureChildrenRecursive) and applies (AdaptionWidget_computeBoundsUnion)
 * vars: widget float* out; param_2 flag
 */
/* Global::AdaptionWidget_measureContent @ 0062bb90 */

void AdaptionWidget_measureContent(float *delta,undefined4 apply)

{
  float fVar1;
  int child;
  float *pfVar3;
  int *self;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float local_10c;
  float local_104;
  float local_f0;
  float local_ec;
  float local_e0;
  float local_dc;
  undefined1 local_d8 [64];
  undefined1 matrix [64];
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  fVar18 = ((float)self[0x1e] + (float)self[0x14]) - (float)self[0x18];
  local_10c = ((float)self[0x1c] + (float)self[0x14]) - (float)self[0x18];
  local_4c = ((float)self[0x1d] + (float)self[0x15]) - (float)self[0x19];
  fVar16 = ((float)self[0x1f] + (float)self[0x15]) - (float)self[0x19];
  if (fVar18 < 0.0) {
    fVar18 = 0.0;
  }
  if (local_10c < fVar18) {
    local_10c = fVar18;
  }
  if (fVar16 < 0.0) {
    fVar16 = 0.0;
  }
  if (local_4c < fVar16) {
    local_4c = fVar16;
  }
  mat4_identity();
  for (child = *(int *)(self[0x52] + 0x28); child != 0; child = *(int *)(child + 0x28)) {
    if (*(int *)(child + 0x40) != 0) {
      if (*(int *)(child + 0x40) != 0) {
        pfVar3 = (float *)AdaptionWidget_computeBoundsUnion(matrix);
        fVar16 = 1.0 / (pfVar3[7] * 0.0 + pfVar3[3] * 0.0 + pfVar3[0xf]);
        fVar18 = (pfVar3[4] * 0.0 + *pfVar3 * 0.0 + pfVar3[0xc]) * fVar16 * -1.0;
        fVar16 = (pfVar3[5] * 0.0 + pfVar3[1] * 0.0 + pfVar3[0xd]) * fVar16 * -1.0;
        local_e0 = local_38 * fVar16 + local_48 * fVar18 + local_18;
        local_ec = local_34 * fVar16 + local_44 * fVar18 + local_14;
        local_f0 = local_40 * fVar18 + local_30 * fVar16 + local_10;
        local_104 = local_2c * fVar16 + local_3c * fVar18 + local_c;
        goto LAB_0062bcdb;
      }
      break;
    }
  }
  local_104 = local_c;
  local_f0 = local_10;
  local_ec = local_14;
  local_e0 = local_18;
LAB_0062bcdb:
  pfVar3 = (float *)AdaptionWidget_computeBoundsUnion(matrix);
  fVar16 = pfVar3[8];
  fVar18 = pfVar3[10];
  fVar9 = pfVar3[4] * local_48;
  fVar4 = fVar16 * local_48;
  fVar17 = pfVar3[0xf];
  fVar10 = pfVar3[9] * local_38;
  fVar19 = pfVar3[0xe];
  fVar1 = pfVar3[0xc];
  local_18 = pfVar3[0xd] * local_38 + fVar1 * local_48 + fVar19 * local_28 + local_e0 * fVar17;
  fVar11 = pfVar3[4] * local_44;
  fVar5 = fVar16 * local_44;
  fVar12 = pfVar3[9] * local_34;
  local_14 = pfVar3[0xd] * local_34 + fVar1 * local_44 + fVar19 * local_24 + local_ec * fVar17;
  fVar13 = pfVar3[4] * local_40;
  fVar6 = fVar16 * local_40;
  fVar14 = pfVar3[9] * local_30;
  local_10 = pfVar3[0xd] * local_30 + fVar1 * local_40 + fVar19 * local_20 + local_f0 * fVar17;
  fVar7 = local_1c * pfVar3[2];
  fVar19 = fVar19 * local_1c;
  fVar15 = pfVar3[4] * local_3c;
  fVar8 = local_1c * pfVar3[6];
  local_1c = pfVar3[9] * local_2c + fVar16 * local_3c + local_1c * fVar18 + local_104 * pfVar3[0xb];
  local_c = pfVar3[0xd] * local_2c + fVar1 * local_3c + fVar19 + local_104 * fVar17;
  local_48 = local_48 * *pfVar3 + local_38 * pfVar3[1] + local_28 * pfVar3[2] + local_e0 * pfVar3[3]
  ;
  local_44 = local_44 * *pfVar3 + local_34 * pfVar3[1] + local_24 * pfVar3[2] + local_ec * pfVar3[3]
  ;
  local_40 = local_40 * *pfVar3 + local_30 * pfVar3[1] + local_20 * pfVar3[2] + local_f0 * pfVar3[3]
  ;
  local_3c = local_3c * *pfVar3 + local_2c * pfVar3[1] + fVar7 + local_104 * pfVar3[3];
  local_38 = fVar9 + local_38 * pfVar3[5] + local_28 * pfVar3[6] + local_e0 * pfVar3[7];
  local_34 = fVar11 + local_34 * pfVar3[5] + local_24 * pfVar3[6] + local_ec * pfVar3[7];
  local_30 = fVar13 + local_30 * pfVar3[5] + local_20 * pfVar3[6] + local_f0 * pfVar3[7];
  local_2c = fVar15 + local_2c * pfVar3[5] + fVar8 + local_104 * pfVar3[7];
  local_28 = fVar10 + fVar4 + local_28 * fVar18 + local_e0 * pfVar3[0xb];
  local_24 = fVar12 + fVar5 + local_24 * fVar18 + local_ec * pfVar3[0xb];
  local_20 = fVar14 + fVar6 + local_20 * fVar18 + local_f0 * pfVar3[0xb];
  Matrix4_Invert();
  fVar16 = *delta;
  fVar17 = local_48 * *delta + local_38 * delta[1];
  fVar18 = delta[1];
  self[0x1c] = (int)fVar17;
  fVar18 = local_44 * fVar16 + local_34 * fVar18;
  self[0x1d] = (int)fVar18;
  fVar19 = ((float)self[0x1e] + (float)self[0x14]) - (float)self[0x18];
  fVar16 = (fVar17 + (float)self[0x14]) - (float)self[0x18];
  fVar17 = ((float)self[0x1f] + (float)self[0x15]) - (float)self[0x19];
  fVar18 = (fVar18 + (float)self[0x15]) - (float)self[0x19];
  if (fVar19 < 0.0) {
    fVar19 = 0.0;
  }
  if (fVar16 < fVar19) {
    fVar16 = fVar19;
  }
  if (fVar17 < 0.0) {
    fVar17 = 0.0;
  }
  if (fVar18 < fVar17) {
    fVar18 = fVar17;
  }
  fVar18 = fVar18 - local_4c;
  mat4_identity();
  child = *(int *)(self[0x52] + 0x28);
  do {
    if (child == 0) {
LAB_0062c1b5:
      local_dc = local_14;
      local_e0 = local_18;
LAB_0062c1cf:
      pfVar3 = (float *)AdaptionWidget_computeBoundsUnion(local_d8);
      local_58 = (fVar16 - local_10c) *
                 (*pfVar3 * local_48 + pfVar3[1] * local_38 + pfVar3[2] * local_28 +
                 pfVar3[3] * local_e0) +
                 fVar18 * (pfVar3[5] * local_38 + pfVar3[4] * local_48 + pfVar3[6] * local_28 +
                          pfVar3[7] * local_e0);
      local_54 = (fVar16 - local_10c) *
                 (*pfVar3 * local_44 + pfVar3[1] * local_34 + pfVar3[2] * local_24 +
                 pfVar3[3] * local_dc) +
                 fVar18 * (pfVar3[5] * local_34 + pfVar3[4] * local_44 + pfVar3[6] * local_24 +
                          pfVar3[7] * local_dc);
      local_50 = 0;
      local_4c = 0.0;
      Widget_measureChildrenRecursive(self[0x52],&local_50,&local_58,apply);
      (**(code **)(*self + 0x28))();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*(int *)(child + 0x40) != 0) {
      if (*(int *)(child + 0x40) != 0) {
        pfVar3 = (float *)AdaptionWidget_computeBoundsUnion(matrix);
        fVar19 = 1.0 / (pfVar3[7] * 0.0 + pfVar3[3] * 0.0 + pfVar3[0xf]);
        fVar17 = fVar19 * (pfVar3[4] * 0.0 + *pfVar3 * 0.0 + pfVar3[0xc]) * -1.0;
        fVar19 = fVar19 * (pfVar3[5] * 0.0 + pfVar3[1] * 0.0 + pfVar3[0xd]) * -1.0;
        local_e0 = local_38 * fVar19 + local_48 * fVar17 + local_18;
        local_dc = local_34 * fVar19 + local_44 * fVar17 + local_14;
        goto LAB_0062c1cf;
      }
      goto LAB_0062c1b5;
    }
    child = *(int *)(child + 0x28);
  } while( true );
}




/* [AUDIT] proposed: AdaptionWidget_computeBoundsUnion  (confidence: med)
 * purpose: Computes union AABB of child bounds via AdaptionWidget_accumulateChildBounds
 * vars: delta float* AABB
 */
/* Global::AdaptionWidget_computeBoundsUnion @ 0062c5b0 */

void AdaptionWidget_computeBoundsUnion(float *out_matrix)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *parent_matrix;
  int self;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined1 local_88 [64];
  float widget_matrix [4];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  mat4_identity();
  iVar7 = *(int *)(*(int *)(*(int *)(self + 4) + 0xb4) + 0x38);
  parent_matrix = (float *)AdaptionWidget_accumulateChildBounds(local_88);
  fVar1 = parent_matrix[1];
  fVar2 = *parent_matrix;
  pfVar10 = (float *)(iVar7 + 0x1f0);
  pfVar11 = widget_matrix;
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *pfVar11 = *pfVar10;
    pfVar10 = pfVar10 + 1;
    pfVar11 = pfVar11 + 1;
  }
  fVar3 = parent_matrix[0xd];
  fVar4 = parent_matrix[0xf];
  fVar25 = fVar1 * local_38 + fVar2 * widget_matrix[0] + parent_matrix[2] * local_28 + parent_matrix[3] * local_18;
  fVar2 = parent_matrix[4];
  fVar26 = fVar2 * widget_matrix[0] + parent_matrix[5] * local_38 + parent_matrix[6] * local_28 + parent_matrix[7] * local_18;
  fVar5 = parent_matrix[8];
  fVar27 = fVar5 * widget_matrix[0] + parent_matrix[9] * local_38 + parent_matrix[10] * local_28 +
           parent_matrix[0xb] * local_18;
  fVar24 = parent_matrix[0xc];
  fVar6 = parent_matrix[0xe];
  fVar13 = fVar24 * widget_matrix[0] + fVar3 * local_38 + fVar6 * local_28 + fVar4 * local_18;
  fVar14 = fVar1 * local_34 + *parent_matrix * widget_matrix[1] + parent_matrix[2] * local_24 + parent_matrix[3] * local_14;
  fVar20 = fVar2 * widget_matrix[1] + parent_matrix[5] * local_34 + parent_matrix[6] * local_24 + parent_matrix[7] * local_14;
  fVar21 = fVar5 * widget_matrix[1] + parent_matrix[9] * local_34 + parent_matrix[10] * local_24 +
           parent_matrix[0xb] * local_14;
  fVar15 = fVar24 * widget_matrix[1] + fVar3 * local_34 + fVar6 * local_24 + fVar4 * local_14;
  fVar16 = fVar1 * local_30 + *parent_matrix * widget_matrix[2] + parent_matrix[2] * local_20 + parent_matrix[3] * local_10;
  fVar22 = fVar2 * widget_matrix[2] + parent_matrix[5] * local_30 + parent_matrix[6] * local_20 + parent_matrix[7] * local_10;
  fVar23 = fVar5 * widget_matrix[2] + parent_matrix[9] * local_30 + parent_matrix[10] * local_20 +
           parent_matrix[0xb] * local_10;
  fVar17 = fVar24 * widget_matrix[2] + fVar3 * local_30 + fVar6 * local_20 + fVar4 * local_10;
  fVar12 = fVar1 * local_2c + *parent_matrix * widget_matrix[3] + parent_matrix[2] * local_1c + parent_matrix[3] * local_c;
  fVar18 = fVar2 * widget_matrix[3] + parent_matrix[5] * local_2c + parent_matrix[6] * local_1c + parent_matrix[7] * local_c;
  fVar19 = fVar5 * widget_matrix[3] + parent_matrix[9] * local_2c + parent_matrix[10] * local_1c +
           parent_matrix[0xb] * local_c;
  fVar1 = out_matrix[4];
  fVar2 = out_matrix[8];
  fVar5 = *out_matrix;
  fVar24 = fVar24 * widget_matrix[3] + fVar3 * local_2c + fVar6 * local_1c + fVar4 * local_c;
  fVar3 = out_matrix[0xc];
  *out_matrix = fVar14 * fVar1 + fVar25 * fVar5 + fVar16 * fVar2 + fVar12 * fVar3;
  out_matrix[4] = fVar20 * fVar1 + fVar26 * fVar5 + fVar22 * fVar2 + fVar18 * fVar3;
  out_matrix[8] = fVar21 * fVar1 + fVar27 * fVar5 + fVar23 * fVar2 + fVar19 * fVar3;
  fVar4 = out_matrix[0xd];
  out_matrix[0xc] = fVar15 * fVar1 + fVar13 * fVar5 + fVar17 * fVar2 + fVar24 * fVar3;
  fVar1 = out_matrix[1];
  fVar2 = out_matrix[5];
  fVar3 = out_matrix[9];
  out_matrix[1] = fVar14 * fVar2 + fVar25 * fVar1 + fVar16 * fVar3 + fVar12 * fVar4;
  out_matrix[5] = fVar20 * fVar2 + fVar26 * fVar1 + fVar22 * fVar3 + fVar18 * fVar4;
  out_matrix[9] = fVar21 * fVar2 + fVar27 * fVar1 + fVar23 * fVar3 + fVar19 * fVar4;
  fVar5 = out_matrix[0xe];
  out_matrix[0xd] = fVar15 * fVar2 + fVar13 * fVar1 + fVar17 * fVar3 + fVar24 * fVar4;
  fVar1 = out_matrix[2];
  fVar2 = out_matrix[6];
  fVar3 = out_matrix[10];
  out_matrix[2] = fVar14 * fVar2 + fVar25 * fVar1 + fVar16 * fVar3 + fVar12 * fVar5;
  out_matrix[6] = fVar20 * fVar2 + fVar26 * fVar1 + fVar22 * fVar3 + fVar18 * fVar5;
  out_matrix[10] = fVar21 * fVar2 + fVar27 * fVar1 + fVar23 * fVar3 + fVar19 * fVar5;
  fVar4 = out_matrix[0xf];
  out_matrix[0xe] = fVar15 * fVar2 + fVar13 * fVar1 + fVar17 * fVar3 + fVar24 * fVar5;
  fVar1 = out_matrix[3];
  fVar2 = out_matrix[7];
  fVar3 = out_matrix[0xb];
  out_matrix[3] = fVar14 * fVar2 + fVar25 * fVar1 + fVar16 * fVar3 + fVar12 * fVar4;
  out_matrix[7] = fVar20 * fVar2 + fVar26 * fVar1 + fVar22 * fVar3 + fVar18 * fVar4;
  out_matrix[0xb] = fVar21 * fVar2 + fVar27 * fVar1 + fVar23 * fVar3 + fVar19 * fVar4;
  out_matrix[0xf] = fVar15 * fVar2 + fVar13 * fVar1 + fVar17 * fVar3 + fVar24 * fVar4;
  fVar1 = *(float *)(self + 0x68);
  fVar2 = *(float *)(self + 0x6c);
  out_matrix[0xc] = fVar1 * *out_matrix + out_matrix[4] * fVar2 + out_matrix[0xc];
  out_matrix[0xd] = out_matrix[5] * fVar2 + out_matrix[1] * fVar1 + out_matrix[0xd];
  out_matrix[0xe] = out_matrix[6] * fVar2 + out_matrix[2] * fVar1 + out_matrix[0xe];
  out_matrix[0xf] = fVar2 * out_matrix[7] + fVar1 * out_matrix[3] + out_matrix[0xf];
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget_accumulateChildBounds  (confidence: med)
 * purpose: Accumulates/expands bounds rect over children (min/max float ops)
 * vars: out_matrix float* rect
 */
/* Global::AdaptionWidget_accumulateChildBounds @ 0062cfd0 */

void AdaptionWidget_accumulateChildBounds(float *out_matrix)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int self;
  int iVar11;
  int iVar12;
  float *src;
  float *dst;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float matrix [4];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  fVar15 = *(float *)(self + 0xe8);
  fVar16 = *(float *)(self + 0xec);
  src = (float *)(*(int *)(*(int *)(self + 0x148) + 0x38) + 0x1b0);
  dst = matrix;
  for (iVar11 = 0x10; fVar18 = local_20, fVar10 = local_24, fVar9 = local_28, fVar8 = local_30,
      fVar7 = local_34, fVar6 = local_38, fVar5 = matrix[3], fVar4 = matrix[2],
      fVar3 = matrix[1], fVar2 = matrix[0], iVar11 != 0; iVar11 = iVar11 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  fVar1 = *(float *)(self + 0x120);
  fVar17 = *(float *)(self + 0x124);
  matrix[0] = fVar15 * matrix[0] + fVar16 * local_38 + *(float *)(self + 0xf0) * local_28 +
                *(float *)(self + 0xf4) * local_18;
  fVar15 = *(float *)(self + 0x10c) * local_38;
  local_38 = *(float *)(self + 0xf8) * fVar2 + *(float *)(self + 0xfc) * local_38 +
             *(float *)(self + 0x100) * local_28 + *(float *)(self + 0x104) * local_18;
  local_28 = *(float *)(self + 0x108) * fVar2 + fVar15 + *(float *)(self + 0x110) * local_28 +
             *(float *)(self + 0x114) * local_18;
  local_18 = *(float *)(self + 0x118) * fVar2 + *(float *)(self + 0x11c) * fVar6 + fVar1 * fVar9
             + fVar17 * local_18;
  matrix[1] = local_34 * *(float *)(self + 0xec) + *(float *)(self + 0xe8) * matrix[1] +
                local_24 * *(float *)(self + 0xf0) + local_14 * *(float *)(self + 0xf4);
  fVar15 = *(float *)(self + 0x10c) * local_34;
  local_34 = local_34 * *(float *)(self + 0xfc) + *(float *)(self + 0xf8) * fVar3 +
             local_24 * *(float *)(self + 0x100) + local_14 * *(float *)(self + 0x104);
  local_24 = *(float *)(self + 0x108) * fVar3 + fVar15 + local_24 * *(float *)(self + 0x110) +
             local_14 * *(float *)(self + 0x114);
  local_14 = *(float *)(self + 0x118) * fVar3 + *(float *)(self + 0x11c) * fVar7 +
             fVar1 * fVar10 + local_14 * fVar17;
  fVar15 = *(float *)(self + 0xf8) * matrix[2];
  matrix[2] = matrix[2] * *(float *)(self + 0xe8) + local_30 * *(float *)(self + 0xec) +
                local_20 * *(float *)(self + 0xf0) + local_10 * *(float *)(self + 0xf4);
  fVar16 = *(float *)(self + 0x10c) * local_30;
  local_30 = local_30 * *(float *)(self + 0xfc) + fVar15 + local_20 * *(float *)(self + 0x100) +
             local_10 * *(float *)(self + 0x104);
  local_20 = *(float *)(self + 0x108) * fVar4 + fVar16 + local_20 * *(float *)(self + 0x110) +
             local_10 * *(float *)(self + 0x114);
  local_10 = *(float *)(self + 0x118) * fVar4 + *(float *)(self + 0x11c) * fVar8 +
             fVar1 * fVar18 + local_10 * fVar17;
  fVar15 = *(float *)(self + 0xf8) * matrix[3];
  matrix[3] = matrix[3] * *(float *)(self + 0xe8) + local_2c * *(float *)(self + 0xec) +
                local_1c * *(float *)(self + 0xf0) + local_c * *(float *)(self + 0xf4);
  local_2c = local_2c * *(float *)(self + 0xfc) + fVar15 + local_1c * *(float *)(self + 0x100) +
             local_c * *(float *)(self + 0x104);
  local_1c = *(float *)(self + 0x108) * fVar5 + *(float *)(self + 0x10c) * local_2c +
             local_1c * *(float *)(self + 0x110) + local_c * *(float *)(self + 0x114);
  local_c = *(float *)(self + 0x118) * fVar5 + *(float *)(self + 0x11c) * local_2c +
            fVar1 * local_1c + local_c * fVar17;
  src = matrix;
  dst = out_matrix;
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  for (iVar11 = *(int *)(*(int *)(self + 0x148) + 0x28); iVar11 != 0;
      iVar11 = *(int *)(iVar11 + 0x28)) {
    src = (float *)(*(int *)(iVar11 + 0x38) + 0x1b0);
    dst = matrix;
    for (iVar12 = 0x10; fVar10 = local_20, fVar9 = local_24, fVar8 = local_28, fVar7 = local_2c,
        fVar6 = local_30, fVar5 = local_34, fVar4 = local_38, fVar3 = matrix[3],
        fVar2 = matrix[2], fVar16 = matrix[1], fVar15 = matrix[0], iVar12 != 0;
        iVar12 = iVar12 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    fVar18 = out_matrix[0xe];
    fVar1 = out_matrix[0xf];
    matrix[0] = matrix[0] * *out_matrix + local_38 * out_matrix[1] + local_28 * out_matrix[2] +
                  local_18 * out_matrix[3];
    fVar17 = out_matrix[9] * local_38;
    local_38 = out_matrix[4] * fVar15 + local_38 * out_matrix[5] + local_28 * out_matrix[6] +
               local_18 * out_matrix[7];
    local_28 = out_matrix[8] * fVar15 + fVar17 + local_28 * out_matrix[10] + local_18 * out_matrix[0xb];
    local_18 = out_matrix[0xc] * fVar15 + out_matrix[0xd] * fVar4 + fVar18 * fVar8 + local_18 * fVar1;
    matrix[1] = matrix[1] * *out_matrix + local_34 * out_matrix[1] + local_24 * out_matrix[2] +
                  local_14 * out_matrix[3];
    fVar15 = out_matrix[9] * local_34;
    local_34 = out_matrix[4] * fVar16 + local_34 * out_matrix[5] + local_24 * out_matrix[6] +
               local_14 * out_matrix[7];
    local_24 = out_matrix[8] * fVar16 + fVar15 + local_24 * out_matrix[10] + local_14 * out_matrix[0xb];
    local_14 = out_matrix[0xc] * fVar16 + out_matrix[0xd] * fVar5 + fVar18 * fVar9 + local_14 * fVar1;
    matrix[2] = matrix[2] * *out_matrix + local_30 * out_matrix[1] + local_20 * out_matrix[2] +
                  local_10 * out_matrix[3];
    fVar15 = out_matrix[9] * local_30;
    local_30 = out_matrix[4] * fVar2 + local_30 * out_matrix[5] + local_20 * out_matrix[6] +
               local_10 * out_matrix[7];
    local_20 = out_matrix[8] * fVar2 + fVar15 + local_20 * out_matrix[10] + local_10 * out_matrix[0xb];
    local_10 = out_matrix[0xc] * fVar2 + out_matrix[0xd] * fVar6 + fVar18 * fVar10 + local_10 * fVar1;
    fVar18 = fVar18 * local_1c;
    matrix[3] = matrix[3] * *out_matrix + local_2c * out_matrix[1] + local_1c * out_matrix[2] +
                  local_c * out_matrix[3];
    fVar15 = out_matrix[9] * local_2c;
    local_2c = out_matrix[4] * fVar3 + local_2c * out_matrix[5] + local_1c * out_matrix[6] +
               local_c * out_matrix[7];
    local_1c = out_matrix[8] * fVar3 + fVar15 + local_1c * out_matrix[10] + local_c * out_matrix[0xb];
    local_c = out_matrix[0xc] * fVar3 + out_matrix[0xd] * fVar7 + fVar18 + local_c * fVar1;
    src = matrix;
    dst = out_matrix;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget_computeLayoutBounds  (confidence: med)
 * purpose: Computes layout bounds via AdaptionWidget_accumulateChildBounds accumulation
 * vars: out_matrix float* bounds
 */
/* Global::AdaptionWidget_computeLayoutBounds @ 0062d7f0 */

void AdaptionWidget_computeLayoutBounds(float *matrix)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *parent_matrix;
  int self;
  undefined1 matrix_buf [64];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  mat4_identity();
  parent_matrix = (float *)AdaptionWidget_accumulateChildBounds(matrix_buf);
  fVar1 = matrix[4];
  fVar2 = *matrix;
  fVar3 = matrix[8];
  fVar4 = matrix[0xc];
  *matrix = fVar1 * parent_matrix[1] + fVar2 * *parent_matrix + fVar3 * parent_matrix[2] + parent_matrix[3] * fVar4;
  matrix[4] = parent_matrix[5] * fVar1 + parent_matrix[4] * fVar2 + parent_matrix[6] * fVar3 + fVar4 * parent_matrix[7];
  matrix[8] = parent_matrix[9] * fVar1 + parent_matrix[8] * fVar2 + parent_matrix[10] * fVar3 + parent_matrix[0xb] * fVar4;
  fVar5 = matrix[0xd];
  matrix[0xc] = fVar1 * parent_matrix[0xd] + fVar2 * parent_matrix[0xc] + parent_matrix[0xe] * fVar3 +
                 parent_matrix[0xf] * fVar4;
  fVar1 = matrix[1];
  fVar2 = matrix[5];
  fVar3 = matrix[9];
  matrix[1] = fVar2 * parent_matrix[1] + fVar1 * *parent_matrix + fVar3 * parent_matrix[2] + parent_matrix[3] * fVar5;
  matrix[5] = parent_matrix[5] * fVar2 + parent_matrix[4] * fVar1 + parent_matrix[6] * fVar3 + fVar5 * parent_matrix[7];
  matrix[9] = parent_matrix[9] * fVar2 + parent_matrix[8] * fVar1 + parent_matrix[10] * fVar3 + parent_matrix[0xb] * fVar5;
  fVar4 = matrix[0xe];
  matrix[0xd] = fVar2 * parent_matrix[0xd] + fVar1 * parent_matrix[0xc] + parent_matrix[0xe] * fVar3 +
                 parent_matrix[0xf] * fVar5;
  fVar1 = matrix[2];
  fVar2 = matrix[6];
  fVar3 = matrix[10];
  matrix[2] = fVar2 * parent_matrix[1] + fVar1 * *parent_matrix + fVar3 * parent_matrix[2] + parent_matrix[3] * fVar4;
  matrix[6] = parent_matrix[5] * fVar2 + parent_matrix[4] * fVar1 + parent_matrix[6] * fVar3 + fVar4 * parent_matrix[7];
  matrix[10] = parent_matrix[9] * fVar2 + parent_matrix[8] * fVar1 + parent_matrix[10] * fVar3 + parent_matrix[0xb] * fVar4;
  matrix[0xe] = fVar2 * parent_matrix[0xd] + fVar1 * parent_matrix[0xc] + parent_matrix[0xe] * fVar3 +
                 parent_matrix[0xf] * fVar4;
  fVar1 = matrix[3];
  fVar2 = matrix[7];
  fVar3 = matrix[0xb];
  fVar4 = matrix[0xf];
  matrix[3] = fVar2 * parent_matrix[1] + fVar1 * *parent_matrix + fVar3 * parent_matrix[2] + parent_matrix[3] * fVar4;
  matrix[7] = parent_matrix[5] * fVar2 + parent_matrix[4] * fVar1 + parent_matrix[6] * fVar3 + fVar4 * parent_matrix[7];
  matrix[0xb] = parent_matrix[9] * fVar2 + parent_matrix[8] * fVar1 + parent_matrix[10] * fVar3 + parent_matrix[0xb] * fVar4;
  matrix[0xf] = fVar2 * parent_matrix[0xd] + fVar1 * parent_matrix[0xc] + parent_matrix[0xe] * fVar3 +
                 parent_matrix[0xf] * fVar4;
  fVar1 = *(float *)(self + 0x68);
  fVar2 = *(float *)(self + 0x6c);
  matrix[0xc] = *matrix * fVar1 + matrix[4] * fVar2 + matrix[0xc];
  matrix[0xd] = matrix[5] * fVar2 + matrix[1] * fVar1 + matrix[0xd];
  matrix[0xe] = matrix[6] * fVar2 + matrix[2] * fVar1 + matrix[0xe];
  matrix[0xf] = matrix[3] * fVar1 + matrix[7] * fVar2 + matrix[0xf];
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget_getBoundsRect  (confidence: med)
 * purpose: Returns pointer to widget bounds rect (float* to x,y,...); heavily shared
 * vars: returns float* rect; +4 = y
 */
/* Global::AdaptionWidget_getBoundsRect @ 0062de60 */

void AdaptionWidget_getBoundsRect(float *out_size)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int child;
  float *pfVar5;
  int self;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float local_d0;
  float local_cc;
  undefined1 inv_matrix [64];
  undefined1 matrix [64];
  float local_48;
  float local_44;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_18;
  float local_14;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  fVar7 = *(float *)(self + 0x50);
  fVar8 = *(float *)(self + 0x60);
  fVar10 = *(float *)(self + 0x54);
  fVar12 = (*(float *)(self + 0x78) + fVar7) - fVar8;
  fVar9 = (*(float *)(self + 0x74) + fVar10) - *(float *)(self + 100);
  fVar11 = (*(float *)(self + 0x7c) + fVar10) - *(float *)(self + 100);
  fVar6 = (*(float *)(self + 0x70) + fVar7) - fVar8;
  if (fVar12 < 0.0) {
    fVar12 = 0.0;
  }
  if (fVar6 < fVar12) {
    fVar6 = fVar12;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  if (fVar9 < fVar11) {
    fVar9 = fVar11;
  }
  fVar10 = (fVar9 + *(float *)(self + 100)) - fVar10;
  fVar7 = (fVar6 + fVar8) - fVar7;
  mat4_identity();
  child = *(int *)(*(int *)(self + 0x148) + 0x28);
  do {
    if (child == 0) {
LAB_0062df31:
      local_d0 = local_14;
      local_cc = local_18;
LAB_0062df4b:
      pfVar5 = (float *)AdaptionWidget_computeBoundsUnion(matrix);
      fVar8 = pfVar5[4];
      fVar6 = pfVar5[1];
      fVar9 = *pfVar5;
      fVar11 = pfVar5[2];
      fVar12 = pfVar5[6];
      fVar1 = pfVar5[3];
      fVar2 = pfVar5[7];
      fVar3 = pfVar5[5];
      *out_size = fVar7 * (local_48 * *pfVar5 + local_38 * pfVar5[1] + local_28 * pfVar5[2] +
                         local_cc * pfVar5[3]) +
                 fVar10 * (local_38 * pfVar5[5] + local_48 * pfVar5[4] + local_28 * pfVar5[6] +
                          local_cc * pfVar5[7]);
      out_size[1] = fVar7 * (local_44 * fVar9 + local_34 * fVar6 + local_24 * fVar11 +
                           local_d0 * fVar1) +
                   fVar10 * (local_34 * fVar3 + local_44 * fVar8 + local_24 * fVar12 +
                            local_d0 * fVar2);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*(int *)(child + 0x40) != 0) {
      if (*(int *)(child + 0x40) != 0) {
        pfVar5 = (float *)AdaptionWidget_computeBoundsUnion(inv_matrix);
        fVar8 = 1.0 / (pfVar5[7] * 0.0 + pfVar5[3] * 0.0 + pfVar5[0xf]);
        fVar6 = (pfVar5[4] * 0.0 + *pfVar5 * 0.0 + pfVar5[0xc]) * fVar8 * -1.0;
        fVar8 = (pfVar5[5] * 0.0 + pfVar5[1] * 0.0 + pfVar5[0xd]) * fVar8 * -1.0;
        local_cc = local_38 * fVar8 + local_48 * fVar6 + local_18;
        local_d0 = local_34 * fVar8 + local_44 * fVar6 + local_14;
        goto LAB_0062df4b;
      }
      goto LAB_0062df31;
    }
    child = *(int *)(child + 0x28);
  } while( true );
}




/* cube::AdaptionWidget::vfunc_1_0062e180 @ 0062e180 */

void cube::AdaptionWidget::vfunc_1_0062e180(float *out_point,float *in_point,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  int self;
  int i;
  int count;
  float *pfVar27;
  float *pfVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  float local_d0;
  float local_c4;
  float local_a0 [5];
  float local_8c;
  float local_84;
  float local_7c;
  float local_74;
  float local_6c;
  float local_64;
  float local_60 [8];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10 [2];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  fVar29 = (*(float *)(self + 0x28) + *(float *)(self + 0x48)) - *(float *)(self + 0x38);
  fVar49 = (*(float *)(self + 0x24) + *(float *)(self + 0x44)) - *(float *)(self + 0x34);
  fVar58 = (*(float *)(self + 0x2c) + *(float *)(self + 0x54)) - *(float *)(self + 0x3c);
  local_10[0] = (*(float *)(self + 0x2c) + *(float *)(self + 0x4c)) - *(float *)(self + 0x3c);
  local_10[1] = (*(float *)(self + 0x30) + *(float *)(self + 0x50)) - *(float *)(self + 0x40);
  local_60[1] = fVar29;
  fVar56 = (*(float *)(self + 0x30) + *(float *)(self + 0x58)) - *(float *)(self + 0x40);
  local_60[0] = fVar49;
  if (fVar58 < 0.0) {
    fVar58 = 0.0;
  }
  local_c4 = local_10[0];
  if (local_10[0] < fVar58) {
    local_10[0] = fVar58;
    local_c4 = fVar58;
  }
  if (fVar56 < 0.0) {
    fVar56 = 0.0;
  }
  local_d0 = local_10[1];
  if (local_10[1] < fVar56) {
    local_10[1] = fVar56;
    local_d0 = fVar56;
  }
  local_60[2] = (float)*(undefined4 *)(self + 0x2c);
  local_60[3] = (float)*(undefined4 *)(self + 0x30);
  i = 0;
  do {
    local_10[0] = local_c4;
    if (*(float *)((int)local_10 + i) != *(float *)((int)local_60 + i + 8))
    goto LAB_0062e2e9;
    i = i + 4;
  } while (i < 8);
  local_10[0] = *(float *)(self + 0x24);
  local_10[1] = (float)*(undefined4 *)(self + 0x28);
  i = 0;
  while (*(float *)((int)local_60 + i) == *(float *)((int)local_10 + i)) {
    i = i + 4;
    if (7 < i) {
      *out_point = *in_point;
      out_point[1] = in_point[1];
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_0062e2e9:
  i = *(int *)(self + 0x124);
  fVar56 = *(float *)(i + 0x88);
  fVar58 = *(float *)(i + 0x8c);
  pfVar27 = (float *)(self + 0x84);
  pfVar28 = local_60 + 4;
  for (count = 0x10; fVar10 = local_28, fVar9 = local_2c, fVar8 = local_30, fVar7 = local_38,
      fVar6 = local_3c, fVar5 = local_40, fVar4 = local_60[6], fVar3 = local_60[5],
      fVar61 = local_60[4], count != 0; count = count + -1) {
    *pfVar28 = *pfVar27;
    pfVar27 = pfVar27 + 1;
    pfVar28 = pfVar28 + 1;
  }
  fVar1 = *(float *)(i + 0xc0);
  fVar2 = *(float *)(i + 0xc4);
  fVar58 = fVar56 * local_60[4] + fVar58 * local_40 + *(float *)(i + 0x90) * local_30 +
           *(float *)(i + 0x94) * local_20;
  local_60[4] = fVar58;
  fVar59 = *(float *)(i + 0x98) * fVar61 + *(float *)(i + 0x9c) * local_40 +
           *(float *)(i + 0xa0) * local_30 + *(float *)(i + 0xa4) * local_20;
  fVar56 = *(float *)(i + 0xac) * local_40;
  local_40 = fVar59;
  fVar60 = *(float *)(i + 0xa8) * fVar61 + fVar56 + *(float *)(i + 0xb0) * local_30 +
           *(float *)(i + 0xb4) * local_20;
  local_30 = fVar60;
  fVar61 = *(float *)(i + 0xb8) * fVar61 + *(float *)(i + 0xbc) * fVar5 + fVar1 * fVar8 +
           fVar2 * local_20;
  local_20 = fVar61;
  local_60[5] = *(float *)(i + 0x88) * local_60[5] + *(float *)(i + 0x8c) * local_3c +
                *(float *)(i + 0x90) * local_2c + *(float *)(i + 0x94) * local_1c;
  fVar56 = *(float *)(i + 0xac) * local_3c;
  local_3c = *(float *)(i + 0x98) * fVar3 + *(float *)(i + 0x9c) * local_3c +
             *(float *)(i + 0xa0) * local_2c + *(float *)(i + 0xa4) * local_1c;
  local_2c = *(float *)(i + 0xa8) * fVar3 + fVar56 + *(float *)(i + 0xb0) * local_2c +
             *(float *)(i + 0xb4) * local_1c;
  local_1c = *(float *)(i + 0xb8) * fVar3 + *(float *)(i + 0xbc) * fVar6 + fVar1 * fVar9 +
             fVar2 * local_1c;
  local_60[6] = *(float *)(i + 0x88) * local_60[6] + *(float *)(i + 0x8c) * local_38 +
                *(float *)(i + 0x90) * local_28 + *(float *)(i + 0x94) * local_18;
  fVar56 = *(float *)(i + 0xac) * local_38;
  local_38 = *(float *)(i + 0x98) * fVar4 + *(float *)(i + 0x9c) * local_38 +
             *(float *)(i + 0xa0) * local_28 + *(float *)(i + 0xa4) * local_18;
  local_28 = *(float *)(i + 0xa8) * fVar4 + fVar56 + *(float *)(i + 0xb0) * local_28 +
             *(float *)(i + 0xb4) * local_18;
  local_18 = *(float *)(i + 0xb8) * fVar4 + *(float *)(i + 0xbc) * fVar7 + fVar1 * fVar10
             + fVar2 * local_18;
  local_60[7] = local_60[7] * *(float *)(i + 0x88) + local_34 * *(float *)(i + 0x8c) +
                local_24 * *(float *)(i + 0x90) + local_14 * *(float *)(i + 0x94);
  local_34 = *(float *)(i + 0x98) * local_60[7] + local_34 * *(float *)(i + 0x9c) +
             local_24 * *(float *)(i + 0xa0) + local_14 * *(float *)(i + 0xa4);
  local_24 = *(float *)(i + 0xa8) * local_60[7] + *(float *)(i + 0xac) * local_34 +
             local_24 * *(float *)(i + 0xb0) + local_14 * *(float *)(i + 0xb4);
  local_14 = *(float *)(i + 0xb8) * local_60[7] + *(float *)(i + 0xbc) * local_34 +
             fVar1 * local_24 + local_14 * fVar2;
  pfVar27 = local_60 + 4;
  pfVar28 = local_a0;
  for (count = 0x10; count != 0; count = count + -1) {
    *pfVar28 = *pfVar27;
    pfVar27 = pfVar27 + 1;
    pfVar28 = pfVar28 + 1;
  }
  fVar56 = *(float *)(param_3 + 0x4c);
  fVar3 = *(float *)(param_3 + 0x48);
  fVar4 = *(float *)(param_3 + 0x50);
  fVar5 = *(float *)(param_3 + 0x54);
  fVar6 = *(float *)(param_3 + 0x58);
  fVar7 = *(float *)(param_3 + 0x5c);
  fVar8 = *(float *)(param_3 + 0x78);
  fVar9 = *(float *)(param_3 + 0x7c);
  fVar10 = *(float *)(param_3 + 0x60);
  fVar1 = *(float *)(param_3 + 0x80);
  fVar2 = *(float *)(param_3 + 100);
  fVar11 = *(float *)(param_3 + 0x84);
  fVar30 = *(float *)(param_3 + 0x48) * local_a0[1];
  fVar31 = fVar56 * local_8c;
  fVar32 = fVar4 * local_7c;
  fVar33 = *(float *)(param_3 + 0x54) * local_6c;
  fVar34 = *(float *)(param_3 + 0x58) * local_a0[1];
  fVar35 = *(float *)(param_3 + 0x5c) * local_8c;
  fVar54 = local_8c * *(float *)(param_3 + 0x7c);
  fVar36 = *(float *)(param_3 + 0x60) * local_7c;
  fVar57 = *(float *)(param_3 + 0x48) * local_a0[3];
  fVar37 = local_6c * *(float *)(param_3 + 100);
  fVar52 = local_7c * fVar1;
  fVar38 = local_a0[1] * fVar8;
  fVar50 = local_6c * fVar11;
  fVar39 = *(float *)(param_3 + 0x4c) * local_84;
  fVar40 = *(float *)(param_3 + 0x50) * local_74;
  fVar41 = *(float *)(param_3 + 0x54) * local_64;
  fVar42 = *(float *)(param_3 + 0x58) * local_a0[3];
  fVar12 = *(float *)(i + 0x84);
  fVar43 = *(float *)(param_3 + 0x5c) * local_84;
  fVar55 = local_84 * *(float *)(param_3 + 0x7c);
  fVar44 = *(float *)(param_3 + 0x60) * local_74;
  fVar53 = local_74 * fVar1;
  fVar45 = local_64 * *(float *)(param_3 + 100);
  fVar51 = local_64 * fVar11;
  fVar46 = local_a0[3] * fVar8;
  pfVar27 = (float *)(param_3 + 0x88);
  pfVar28 = local_60 + 4;
  for (count = 0x10; fVar20 = local_28, fVar19 = local_2c, fVar18 = local_30, fVar17 = local_38,
      fVar16 = local_3c, fVar64 = local_40, fVar15 = local_60[6], fVar14 = local_60[5],
      fVar48 = local_60[4], count != 0; count = count + -1) {
    *pfVar28 = *pfVar27;
    pfVar27 = pfVar27 + 1;
    pfVar28 = pfVar28 + 1;
  }
  fVar13 = *(float *)(i + 0x80);
  fVar62 = local_60[4] * *(float *)(i + 0x48) + local_40 * *(float *)(i + 0x4c) +
           local_30 * *(float *)(i + 0x50) + local_20 * *(float *)(i + 0x54);
  local_60[4] = fVar62;
  fVar63 = *(float *)(i + 0x58) * fVar48 + local_40 * *(float *)(i + 0x5c) +
           local_30 * *(float *)(i + 0x60) + local_20 * *(float *)(i + 100);
  fVar47 = *(float *)(i + 0x6c) * local_40;
  local_40 = fVar63;
  fVar47 = *(float *)(i + 0x68) * fVar48 + fVar47 + local_30 * *(float *)(i + 0x70) +
           local_20 * *(float *)(i + 0x74);
  local_30 = fVar47;
  fVar64 = *(float *)(i + 0x78) * fVar48 + *(float *)(i + 0x7c) * fVar64 + fVar13 * fVar18
           + local_20 * fVar12;
  local_20 = fVar64;
  local_60[5] = local_60[5] * *(float *)(i + 0x48) + local_3c * *(float *)(i + 0x4c) +
                local_2c * *(float *)(i + 0x50) + local_1c * *(float *)(i + 0x54);
  fVar48 = *(float *)(i + 0x6c) * local_3c;
  local_3c = *(float *)(i + 0x58) * fVar14 + local_3c * *(float *)(i + 0x5c) +
             local_2c * *(float *)(i + 0x60) + local_1c * *(float *)(i + 100);
  local_2c = *(float *)(i + 0x68) * fVar14 + fVar48 + local_2c * *(float *)(i + 0x70) +
             local_1c * *(float *)(i + 0x74);
  local_1c = *(float *)(i + 0x78) * fVar14 + *(float *)(i + 0x7c) * fVar16 +
             fVar13 * fVar19 + local_1c * fVar12;
  local_60[6] = local_60[6] * *(float *)(i + 0x48) + local_38 * *(float *)(i + 0x4c) +
                local_28 * *(float *)(i + 0x50) + local_18 * *(float *)(i + 0x54);
  fVar48 = *(float *)(i + 0x6c) * local_38;
  local_38 = *(float *)(i + 0x58) * fVar15 + local_38 * *(float *)(i + 0x5c) +
             local_28 * *(float *)(i + 0x60) + local_18 * *(float *)(i + 100);
  local_28 = *(float *)(i + 0x68) * fVar15 + fVar48 + local_28 * *(float *)(i + 0x70) +
             local_18 * *(float *)(i + 0x74);
  local_18 = *(float *)(i + 0x78) * fVar15 + *(float *)(i + 0x7c) * fVar17 +
             fVar13 * fVar20 + local_18 * fVar12;
  local_60[7] = local_60[7] * *(float *)(i + 0x48) + local_34 * *(float *)(i + 0x4c) +
                local_24 * *(float *)(i + 0x50) + local_14 * *(float *)(i + 0x54);
  local_34 = *(float *)(i + 0x58) * local_60[7] + local_34 * *(float *)(i + 0x5c) +
             local_24 * *(float *)(i + 0x60) + local_14 * *(float *)(i + 100);
  local_24 = *(float *)(i + 0x68) * local_60[7] + *(float *)(i + 0x6c) * local_34 +
             local_24 * *(float *)(i + 0x70) + local_14 * *(float *)(i + 0x74);
  local_14 = *(float *)(i + 0x78) * local_60[7] + *(float *)(i + 0x7c) * local_34 +
             fVar13 * local_24 + local_14 * fVar12;
  fVar12 = *(float *)(self + 200);
  fVar48 = *(float *)(self + 0xc4);
  pfVar27 = local_60 + 4;
  pfVar28 = local_a0;
  for (i = 0x10; i != 0; i = i + -1) {
    *pfVar28 = *pfVar27;
    pfVar27 = pfVar27 + 1;
    pfVar28 = pfVar28 + 1;
  }
  local_10[1] = fVar62 * fVar48 + fVar63 * fVar12 + fVar47 * *(float *)(self + 0xcc) +
                fVar64 * *(float *)(self + 0xd0);
  fVar14 = *(float *)(self + 0x100);
  fVar15 = *(float *)(self + 0xf8);
  local_60[3] = fVar62 * *(float *)(self + 0xd4) + fVar63 * *(float *)(self + 0xd8) +
                fVar47 * *(float *)(self + 0xdc) + fVar64 * *(float *)(self + 0xe0);
  fVar16 = *(float *)(self + 0xfc);
  fVar17 = *(float *)(self + 0xcc);
  fVar18 = *(float *)(self + 0xd0);
  fVar19 = *(float *)(self + 0xd8);
  fVar20 = *(float *)(self + 0xd4);
  fVar13 = *(float *)(self + 0xdc);
  fVar21 = *(float *)(self + 0xe0);
  fVar22 = *(float *)(self + 0xf4);
  fVar23 = in_point[1];
  local_60[1] = *(float *)(self + 0xf4) * local_a0[3] + fVar15 * local_84 + fVar16 * local_74 +
                local_64 * fVar14;
  fVar24 = *in_point;
  fVar39 = 1.0 / (fVar24 * (fVar57 + fVar39 + fVar40 + fVar41) +
                  (fVar42 + fVar43 + fVar44 + fVar45) * fVar23 + fVar46 + fVar55 + fVar53 + fVar51);
  fVar56 = fVar39 * ((fVar56 * fVar59 + fVar3 * fVar58 + fVar4 * fVar60 + fVar5 * fVar61) * fVar24 +
                     (fVar6 * fVar58 + fVar7 * fVar59 + fVar10 * fVar60 + fVar61 * fVar2) * fVar23 +
                    fVar8 * fVar58 + fVar9 * fVar59 + fVar1 * fVar60 + fVar11 * fVar61);
  fVar39 = fVar39 * ((fVar30 + fVar31 + fVar32 + fVar33) * fVar24 +
                     (fVar34 + fVar35 + fVar36 + fVar37) * fVar23 +
                    fVar38 + fVar54 + fVar52 + fVar50);
  if (fVar49 <= fVar56) {
    if (local_c4 + fVar49 <= fVar56) {
      fVar58 = 1.0;
    }
    else {
      fVar58 = (fVar56 - fVar49) / local_c4;
    }
  }
  else {
    fVar58 = 0.0;
  }
  if (fVar29 <= fVar39) {
    if (local_d0 + fVar29 <= fVar39) {
      fVar61 = 1.0;
    }
    else {
      fVar61 = (fVar39 - fVar29) / local_d0;
    }
  }
  else {
    fVar61 = 0.0;
  }
  fVar49 = ((*(float *)(self + 0x24) + fVar56) - fVar49) +
           fVar58 * (*(float *)(self + 0x2c) - local_c4);
  fVar29 = ((*(float *)(self + 0x28) + fVar39) - fVar29) +
           fVar61 * (*(float *)(self + 0x30) - local_d0);
  fVar56 = 1.0 / ((local_84 * *(float *)(self + 0xd8) + *(float *)(self + 0xd4) * local_a0[3] +
                   *(float *)(self + 0xdc) * local_74 + local_64 * *(float *)(self + 0xe0)) *
                  fVar29 + (local_a0[3] * *(float *)(self + 0xc4) +
                            local_84 * *(float *)(self + 200) +
                            *(float *)(self + 0xcc) * local_74 +
                           local_64 * *(float *)(self + 0xd0)) * fVar49 + local_60[1]);
  *out_point = (local_60[3] * fVar29 + local_10[1] * fVar49 +
             fVar62 * *(float *)(self + 0xf4) + fVar63 * fVar15 + fVar47 * fVar16 +
             fVar64 * fVar14) * fVar56;
  out_point[1] = ((local_8c * fVar19 + fVar20 * local_a0[1] + local_7c * fVar13 + local_6c * fVar21) *
                fVar29 + (local_a0[1] * fVar48 + local_8c * fVar12 + local_7c * fVar17 +
                         local_6c * fVar18) * fVar49 +
               fVar22 * local_a0[1] + fVar15 * local_8c + local_7c * fVar16 + local_6c * fVar14) *
               fVar56;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: get_widget_state  (confidence: low)
 * purpose: Returns a widget state/int field (no callees)
 * vars: out_point
 */
/* Global::get_widget_state @ 00630970 */

int get_widget_state(int index)

{
  int data;
  int count;
  int *array;
  
  data = *array;
  if (array[3] != 0) {
    count = (array[1] - data) / 0xc;
    return data + ((index + count) % count) * 0xc;
  }
  if (index < 0) {
    index = 0;
  }
  count = (array[1] - data) / 0xc;
  if (count <= index) {
    index = count + -1;
  }
  return data + index * 0xc;
}




/* [AUDIT] proposed: AdaptionWidget::apply_to_attributes  (confidence: high)
 * purpose: Invoke Widget_triggerTracksByName on each populated attribute slot (+0x34/38/3c) then recurse children
 * vars: index/2 args forwarded; +0x2c children
 */
/* Global::AdaptionWidget_apply_to_attributes @ 00636810 */

void AdaptionWidget_apply_to_attributes(undefined4 param_1,undefined4 param_2)

{
  int self;
  int *child;
  
  if (*(int *)(self + 0x34) != 0) {
    Widget_triggerTracksByName(param_1,param_2);
  }
  if (*(int *)(self + 0x38) != 0) {
    Widget_triggerTracksByName(param_1,param_2);
  }
  if (*(int *)(self + 0x3c) != 0) {
    Widget_triggerTracksByName(param_1,param_2);
  }
  child = (int *)**(int **)(self + 0x2c);
  if (child != *(int **)(self + 0x2c)) {
    do {
      AdaptionWidget_apply_to_attributes(param_1,param_2);
      child = (int *)*child;
    } while (child != (int *)*(int *)(self + 0x2c));
  }
  return;
}




/* [AUDIT] proposed: Node::clear_dirty_flag_2e  (confidence: high)
 * purpose: Recursively clear byte flag +0x2e on populated attribute slots and descend children
 * vars: +0x34/38/3c slot +0x2e; +0x2c children
 */
/* Global::Node_clear_dirty_flag_2e @ 00636be0 */

void Node_clear_dirty_flag_2e(void)

{
  int self;
  int *child;
  
  if ((~(byte)(*(uint *)(self + 200) >> 2) & 1) != 0) {
    if (*(int *)(self + 0x34) != 0) {
      *(undefined1 *)(*(int *)(self + 0x34) + 0x2e) = 0;
    }
    if (*(int *)(self + 0x38) != 0) {
      *(undefined1 *)(*(int *)(self + 0x38) + 0x2e) = 0;
    }
    if (*(int *)(self + 0x3c) != 0) {
      *(undefined1 *)(*(int *)(self + 0x3c) + 0x2e) = 0;
    }
    child = (int *)**(int **)(self + 0x2c);
    if (child != *(int **)(self + 0x2c)) {
      do {
        Node_clear_dirty_flag_2e();
        child = (int *)*child;
      } while (child != (int *)*(int *)(self + 0x2c));
    }
  }
  return;
}




/* [AUDIT] proposed: AdaptionWidget::relayout  (confidence: high)
 * purpose: Clear dirty flags (636be0) then run recursive layout/adaption pass (636cd0)
 * vars: param_1 arg
 */
/* Global::AdaptionWidget_relayout @ 00636cb0 */

void AdaptionWidget_relayout(undefined4 event)

{
  Node_clear_dirty_flag_2e();
  AdaptionWidget_layout_recursive(event,0,0);
  return;
}




/* [AUDIT] proposed: AdaptionWidget::layout_recursive  (confidence: med)
 * purpose: Recursive layout/adaption: resolve +0x44, recompute children (Widget_updateAnimations), local transform, descend
 * vars: +0x44 resolved; +0x40 adaption vtbl+0x6c; +0x2c children
 */
/* Global::AdaptionWidget_layout_recursive @ 00636cd0 */

void AdaptionWidget_layout_recursive(undefined4 event,undefined4 param_2,char force)

{
  int self;
  int *child;
  
  if ((*(uint *)(self + 200) & 0x2000) != 0) {
    force = '\x01';
  }
  if (((~(byte)(*(uint *)(self + 200) >> 2) & 1) != 0) &&
     ((*(int *)(*(int *)(*(int *)(self + 0x3c) + 0x94) +
               *(int *)(*(int *)(self + 0x3c) + 0x68) * 4) != 0 || (force != '\0')))) {
    if (*(int *)(self + 0x40) == 0) {
      if (*(int *)(self + 0x28) == 0) {
        *(undefined4 *)(self + 0x44) = 0;
      }
      else {
        *(undefined4 *)(self + 0x44) = *(undefined4 *)(*(int *)(self + 0x28) + 0x44);
      }
    }
    else {
      *(int *)(self + 0x44) = *(int *)(self + 0x40);
    }
    if ((*(int *)(self + 0x34) != 0) && (*(char *)(*(int *)(self + 0x34) + 0x2e) == '\0')) {
      Widget_updateAnimations(event);
    }
    if ((*(int *)(self + 0x38) != 0) && (*(char *)(*(int *)(self + 0x38) + 0x2e) == '\0')) {
      Widget_updateAnimations(event);
    }
    if ((*(int *)(self + 0x3c) != 0) && (*(char *)(*(int *)(self + 0x3c) + 0x2e) == '\0')) {
      Widget_updateAnimations(event);
    }
    AdaptionWidget_compute_local_transform();
    if (*(int **)(self + 0x40) != (int *)0x0) {
      (**(code **)(**(int **)(self + 0x40) + 0x6c))();
    }
    child = (int *)**(int **)(self + 0x2c);
    if (child != *(int **)(self + 0x2c)) {
      do {
        AdaptionWidget_layout_recursive(event,param_2,force);
        child = (int *)*child;
      } while (child != (int *)*(int *)(self + 0x2c));
    }
  }
  return;
}




/* [AUDIT] proposed: AdaptionWidget::apply_attributes_v2  (confidence: high)
 * purpose: Invoke Widget_resetAnimations on populated attribute slots then recurse active children
 * vars: +0x34/38/3c slots; +0x2c children
 */
/* Global::AdaptionWidget_apply_attributes_v2 @ 00636f10 */

void AdaptionWidget_apply_attributes_v2(void)

{
  int self;
  int *child;
  
  if (*(int *)(self + 0x34) != 0) {
    Widget_resetAnimations();
  }
  if (*(int *)(self + 0x38) != 0) {
    Widget_resetAnimations();
  }
  if (*(int *)(self + 0x3c) != 0) {
    Widget_resetAnimations();
  }
  child = (int *)**(int **)(self + 0x2c);
  if (child != *(int **)(self + 0x2c)) {
    do {
      if ((~(byte)(*(uint *)(child[2] + 200) >> 2) & 1) != 0) {
        AdaptionWidget_apply_attributes_v2();
      }
      child = (int *)*child;
    } while (child != (int *)*(int *)(self + 0x2c));
  }
  return;
}




/* [AUDIT] proposed: AdaptionWidget::compute_max_content_width  (confidence: med)
 * purpose: Recursively compute max content width by querying attribute keyframe arrays (AnimMap_findValueByKey) across slots/children
 * vars: iVar5=max; keyframe stride 0xc
 */
/* Global::AdaptionWidget_compute_max_content_width @ 00636f70 */

int AdaptionWidget_compute_max_content_width(undefined4 param_1)

{
  int *piVar1;
  int count;
  int self;
  int index;
  int *behavior;
  int max_frames;
  
  if ((~(byte)(*(uint *)(self + 200) >> 2) & 1) != 0) {
    max_frames = 0;
    if ((*(int *)(self + 0x34) != 0) &&
       (piVar1 = *(int **)(*(int *)(self + 0x34) + 0x24), behavior = (int *)*piVar1,
       behavior != piVar1)) {
      do {
        piVar1 = (int *)AnimMap_findValueByKey(param_1);
        if ((piVar1 != (int *)0x0) && (count = (piVar1[1] - *piVar1) / 0xc, 0 < count)) {
          count = get_widget_state(count + -1);
          if (max_frames < *(int *)(count + 4)) {
            max_frames = *(int *)(count + 4);
          }
        }
        behavior = (int *)*behavior;
      } while (behavior != (int *)*(int *)(*(int *)(self + 0x34) + 0x24));
    }
    if ((*(int *)(self + 0x38) != 0) &&
       (piVar1 = *(int **)(*(int *)(self + 0x38) + 0x24), behavior = (int *)*piVar1,
       behavior != piVar1)) {
      do {
        piVar1 = (int *)AnimMap_findValueByKey(param_1);
        if ((piVar1 != (int *)0x0) && (count = (piVar1[1] - *piVar1) / 0xc, 0 < count)) {
          count = get_widget_state(count + -1);
          if (max_frames < *(int *)(count + 4)) {
            max_frames = *(int *)(count + 4);
          }
        }
        behavior = (int *)*behavior;
      } while (behavior != (int *)*(int *)(*(int *)(self + 0x38) + 0x24));
    }
    if ((*(int *)(self + 0x3c) != 0) &&
       (piVar1 = *(int **)(*(int *)(self + 0x3c) + 0x24), behavior = (int *)*piVar1,
       behavior != piVar1)) {
      do {
        piVar1 = (int *)AnimMap_findValueByKey(param_1);
        if (piVar1 != (int *)0x0) {
          count = (piVar1[1] - *piVar1) / 0xc;
          if (0 < count) {
            if (piVar1[3] == 0) {
              index = count + -1;
              if (count + -1 < 0) {
                index = 0;
              }
              if (count <= index) {
                index = count + -1;
              }
            }
            else {
              index = (count + -1 + count) % count;
            }
            count = *(int *)(*piVar1 + 4 + index * 0xc);
            if (max_frames < count) {
              max_frames = count;
            }
          }
        }
        behavior = (int *)*behavior;
      } while (behavior != (int *)*(int *)(*(int *)(self + 0x3c) + 0x24));
    }
    piVar1 = (int *)**(int **)(self + 0x2c);
    if (piVar1 != *(int **)(self + 0x2c)) {
      do {
        count = AdaptionWidget_compute_max_content_width(param_1);
        piVar1 = (int *)*piVar1;
        if (max_frames < count) {
          max_frames = count;
        }
      } while (piVar1 != (int *)*(int *)(self + 0x2c));
    }
    return max_frames;
  }
  return 0;
}




/* [AUDIT] proposed: AdaptionWidget::compute_local_transform  (confidence: high)
 * purpose: Compute node world matrix (+0x88) from style matrix (+0x38 +0x1b0) and parent (+0x48), 4x4 copies
 * vars: +0x28 parent; +0x88 out; mat4_mulRight mtxmul
 */
/* Global::AdaptionWidget_compute_local_transform @ 006371b0 */

void AdaptionWidget_compute_local_transform(void)

{
  undefined4 *src;
  int self;
  int iVar2;
  int parent;
  undefined4 *dst;
  undefined1 matrix_buf [64];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  parent = *(int *)(self + 0x28);
  if (parent == 0) {
    parent = *(int *)(self + 0x38);
    src = (undefined4 *)(parent + 0x1b0);
    dst = (undefined4 *)(self + 0x48);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    src = (undefined4 *)(parent + 0x1f0);
  }
  else {
    src = (undefined4 *)mat4_mulRight(matrix_buf,*(int *)(self + 0x38) + 0x1b0);
    dst = (undefined4 *)(self + 0x48);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    src = (undefined4 *)mat4_mulRight(matrix_buf,parent + 0x88);
  }
  dst = (undefined4 *)(self + 0x88);
  for (parent = 0x10; parent != 0; parent = parent + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: AdaptionWidget::recompute_transforms_recursive  (confidence: high)
 * purpose: Recursively call compute_local_transform (6371b0) over node subtree when visible
 * vars: +0x2c children; +200 vis flag
 */
/* Global::AdaptionWidget_recompute_transforms_recursive @ 00637260 */

void AdaptionWidget_recompute_transforms_recursive(void)

{
  int self;
  int *child;
  
  if ((~(byte)(*(uint *)(self + 200) >> 2) & 1) != 0) {
    AdaptionWidget_compute_local_transform();
    child = (int *)**(int **)(self + 0x2c);
    if (child != *(int **)(self + 0x2c)) {
      do {
        AdaptionWidget_recompute_transforms_recursive();
        child = (int *)*child;
      } while (child != (int *)*(int *)(self + 0x2c));
    }
  }
  return;
}




/* [AUDIT] proposed: AdaptionWidget::draw_text_locked  (confidence: med)
 * purpose: Under CS, begin/end render state (vtbl 0x40/0x44) and draw text run via Font_drawTextTransformed
 * vars: +0x24 CS; +4 render dev; many text params
 */
/* Global::AdaptionWidget_draw_text_locked @ 00639b30 */

void AdaptionWidget_draw_text_locked(undefined4 font_name,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14)

{
  int font;
  int self;
  
  font = FontCache_find_or_create_scalable(font_name);
  if (font != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x24));
    (**(code **)(**(int **)(self + 4) + 0x40))(0);
    Font_drawTextTransformed(param_2,param_5,param_6,param_7,param_8,param_3,param_4,param_13,param_9,param_10,
                 param_11,param_12,param_14);
    (**(code **)(**(int **)(self + 4) + 0x44))(0);
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x24));
  }
  return;
}




/* [AUDIT] proposed: Registry::push_node_locked_0x7c  (confidence: high)
 * purpose: Under CS, append list node to AdaptionWidget list at +0x7c
 * vars: +0x58 CS; +0x7c list
 */
/* Global::Registry_push_node_locked_0x7c @ 0064ed40 */

undefined4 * Registry_push_node_locked_0x7c(undefined4 *out)

{
  int list;
  int new_node;
  int self;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x58));
  list = *(int *)(self + 0x7c);
  new_node = IntMap_SetScalar(list,*(undefined4 *)(list + 4),&stack0x00000008);
  if (*(int *)(self + 0x80) == 0x15555554) {
    std::_Xlength_error("list<T> too long");
  }
  *(int *)(self + 0x80) = *(int *)(self + 0x80) + 1;
  *(int *)(list + 4) = new_node;
  **(int **)(new_node + 4) = new_node;
  *out = *(undefined4 *)(*(int *)(self + 0x7c) + 4);
  LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x58));
  return out;
}




/* [AUDIT] proposed: Widget::set_flags_word  (confidence: high)
 * purpose: Store out into flags dword at +200
 * vars: +0xc8
 */
/* Global::Widget_set_flags_word @ 0064efe0 */

void Widget_set_flags_word(undefined4 flags)

{
  int self;
  
  *(undefined4 *)(self + 200) = flags;
  return;
}




/* [AUDIT] proposed: Widget::dispatch_event_callback  (confidence: high)
 * purpose: If widget enabled and has handler (+0x44), fetch registry callback (rbtree_findOrInsert_intKey) and invoke it
 * vars: flags=widget; param_2=event id
 */
/* Global::Widget_dispatch_event_callback @ 00653620 */

void Widget_dispatch_event_callback(int entity,undefined4 eventId)

{
  int controller;
  undefined4 *handler;
  int *behavior;
  
  if (((entity != 0) && ((~(byte)(*(uint *)(entity + 200) >> 1) & 1) != 0)) &&
     (controller = *(int *)(entity + 0x44), controller != 0)) {
    entity = eventId;
    behavior = (int *)rbtree_findOrInsert_intKey(&entity);
    handler = (undefined4 *)*behavior;
    if ((handler != (undefined4 *)0x0) &&
       ((*(char *)(controller + 0x15c) != '\0' || (*(char *)(handler + 1) == '\0')))) {
      (**(code **)*handler)();
    }
  }
  return;
}




/* [AUDIT] proposed: AdaptionWidget::clear_hover  (confidence: high)
 * purpose: Clear captured widget (+200=0) and notify hover change (GameController_set_hover_widget with +0xd4/d8)
 * vars: +0xc8 flag; +0xd4 cursor
 */
/* Global::AdaptionWidget_clear_hover @ 00659cf0 */

void AdaptionWidget_clear_hover(void)

{
  int self;
  
  *(undefined4 *)(self + 200) = 0;
  GameController_set_hover_widget(*(undefined4 *)(self + 0xd4),*(undefined4 *)(self + 0xd8));
  return;
}




/* [AUDIT] proposed: AnimMap::findValueByKey  (confidence: med)
 * purpose: Looks up a string key in a map and returns the value stored at node+0x28, or 0 when not found
 * vars: self+4=tree; node+0x28=value; u16string_compare=key compare
 */
/* Global::AnimMap_findValueByKey @ 00661d90 */

undefined4 AnimMap_findValueByKey(int key)

{
  int *treeEnd;
  int found;
  int *keyPtr;
  int cmp;
  int self;
  
  treeEnd = (int *)(self + 4);
  found = map_lower_bound_string(key);
  if (found != *treeEnd) {
    keyPtr = (int *)(found + 0x10);
    if (7 < *(uint *)(found + 0x24)) {
      keyPtr = (int *)*keyPtr;
    }
    cmp = u16string_compare(0,*(undefined4 *)(key + 0x10),keyPtr,*(undefined4 *)(found + 0x20));
    key = found;
    if (-1 < cmp) goto LAB_00661dd4;
  }
  key = *treeEnd;
LAB_00661dd4:
  if (key != *treeEnd) {
    return *(undefined4 *)(key + 0x28);
  }
  return 0;
}




/* [AUDIT] proposed: Widget::layoutAspectFit  (confidence: med)
 * purpose: Aspect-fit layout: computes scale ratio between content and container dimensions then re-positions via setAlignmentOffset
 * vars: self+0x24c=enabled; +0x238=axis sel; AdaptionWidget_onContentResized/0062de60=size getters
 */
/* Global::Widget_layoutAspectFit @ 00662860 */

void Widget_layoutAspectFit(void)

{
  int widget;
  uint axis;
  int denom;
  int extent;
  int self;
  undefined1 *vecTmp;
  float offset;
  undefined1 vecA [8];
  float sizeVec [2];
  undefined1 vecB [8];
  undefined1 vecC [4];
  float ratio;
  uint stackCookie;
  
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (*(int *)(self + 0x24c) != 0) {
    widget = AdaptionWidget_onContentResized();
    if (widget != 0) {
      widget = AdaptionWidget_onContentResized();
      if (widget != 0) {
        axis = (uint)(*(int *)(self + 0x238) != 1);
        widget = AdaptionWidget_getBoundsRect(vecC);
        vecTmp = vecB;
        AdaptionWidget_onContentResized(vecTmp);
        denom = AdaptionWidget_getBoundsRect(vecTmp);
        ratio = *(float *)(widget + axis * 4) / *(float *)(denom + axis * 4);
        if (ratio < 1.0) {
          ratio = 1.0;
        }
        AdaptionWidget_getBoundsRect(sizeVec);
        vecTmp = vecB;
        AdaptionWidget_onContentResized(vecTmp);
        widget = AdaptionWidget_getBoundsRect(vecTmp);
        sizeVec[axis] = *(float *)(widget + axis * 4) / ratio;
        AdaptionWidget_measureContent(sizeVec,1);
        widget = AdaptionWidget_getBoundsRect(vecB);
        vecTmp = vecC;
        AdaptionWidget_onContentResized(vecTmp);
        denom = AdaptionWidget_getBoundsRect(vecTmp);
        if (*(float *)(denom + axis * 4) < *(float *)(widget + axis * 4)) {
          widget = AdaptionWidget_getContentSize(vecB);
          denom = AdaptionWidget_getBoundsRect(vecC);
          vecTmp = vecA;
          AdaptionWidget_onContentResized(vecTmp);
          extent = AdaptionWidget_getBoundsRect(vecTmp);
          offset = -(*(float *)(widget + axis * 4) /
                   (*(float *)(denom + axis * 4) - *(float *)(extent + axis * 4)));
        }
        else {
          offset = 0.0;
        }
        Widget_applyAlignmentOffset(offset);
      }
    }
  }
  __security_check_cookie(stackCookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: Widget::applyAlignmentOffset  (confidence: med)
 * purpose: Clamps an alignment factor to [0,1] and offsets the widget along the active axis by that fraction of the size delta
 * vars: param_1=factor; self+0x238=axis; AdaptionWidget_applyScrollLayout=apply offset
 */
/* Global::Widget_applyAlignmentOffset @ 00662f00 */

void Widget_applyAlignmentOffset(float t)

{
  int widget;
  int extent;
  int self;
  uint axis;
  float clamped;
  undefined1 *vecTmp;
  undefined1 vecA [8];
  undefined1 vecB [8];
  float offsetVec [2];
  uint stackCookie;
  
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  widget = AdaptionWidget_onContentResized();
  if (widget != 0) {
    clamped = 0.0;
    if ((t < 0.0) || (clamped = 1.0, 1.0 < t)) {
      t = clamped;
    }
    axis = (uint)(*(int *)(self + 0x238) != 1);
    AdaptionWidget_getContentSize(offsetVec);
    vecTmp = vecB;
    AdaptionWidget_onContentResized(vecTmp);
    widget = AdaptionWidget_getBoundsRect(vecTmp);
    extent = AdaptionWidget_getBoundsRect(vecA);
    offsetVec[axis] = (*(float *)(widget + axis * 4) - *(float *)(extent + axis * 4)) * t;
    AdaptionWidget_applyScrollLayout(offsetVec,1);
  }
  __security_check_cookie(stackCookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: Widget::destroyTailSlot  (confidence: med)
 * purpose: Releases a string element unless it is the current tail slot of the vector
 * vars: self+0xa8=base, +0x7c=count; stride 0x18
 */
/* Global::Widget_destroyTailSlot @ 00663eb0 */

void Widget_destroyTailSlot(int elem)

{
  int self;
  
  if (*(int *)(self + 0xa8) + *(int *)(self + 0x7c) * 0x18 != elem) {
    u16string_replaceRange(elem,0,0xffffffff);
  }
  return;
}




/* [AUDIT] proposed: Widget::triggerTracksByName  (confidence: low)
 * purpose: Frees a temp key string, iterates a list of tracks and for each matching name plays its keyframes, marking a dirty flag
 * vars: self+0x24=list; +0x2c=dirty; uses 661d90/661df0
 */
/* Global::Widget_triggerTracksByName @ 00664c10 */

void Widget_triggerTracksByName(int key,undefined4 frame)

{
  int matched;
  int self;
  int *trackIter;
  
  if (self + 0x30 != key) {
    u16string_replaceRange(key,0,0xffffffff);
  }
  trackIter = (int *)**(int **)(self + 0x24);
  if (trackIter != *(int **)(self + 0x24)) {
    do {
      matched = AnimMap_findValueByKey(key);
      if (matched != 0) {
        Anim_playTrackByName(key,frame);
        *(undefined1 *)(self + 0x2c) = 1;
      }
      trackIter = (int *)*trackIter;
    } while (trackIter != (int *)*(int *)(self + 0x24));
  }
  return;
}




/* [AUDIT] proposed: Widget::updateAnimations  (confidence: med)
 * purpose: Iterates a list of animation controllers advancing each to param time; if any changed, fires a vtable notify callback
 * vars: self[9]=list head; per-node 662690; vtable+4=notify
 */
/* Global::Widget_updateAnimations @ 00664c60 */

char Widget_updateAnimations(undefined4 time)

{
  char trackChanged;
  int *self;
  char anyChanged;
  int *trackIter;
  
  anyChanged = '\0';
  *(undefined1 *)((int)self + 0x2e) = 1;
  trackIter = *(int **)self[9];
  if (trackIter != (int *)self[9]) {
    do {
      trackChanged = Spline_setTimeAndEvaluate(time);
      trackIter = (int *)*trackIter;
      if (trackChanged != '\0') {
        anyChanged = '\x01';
      }
    } while (trackIter != (int *)self[9]);
    if (anyChanged != '\0') {
      (**(code **)(*self + 4))(0);
    }
  }
  return anyChanged;
}




/* [AUDIT] proposed: Widget::resetAnimations  (confidence: high)
 * purpose: Clears the dirty flag and iterates the controller list resetting each animation's time to zero
 * vars: self+0x2c=dirty; +0x24=list; per-node 6626b0
 */
/* Global::Widget_resetAnimations @ 00664cc0 */

void Widget_resetAnimations(void)

{
  int self;
  int *trackIter;
  
  *(undefined1 *)(self + 0x2c) = 0;
  trackIter = (int *)**(int **)(self + 0x24);
  if (trackIter != *(int **)(self + 0x24)) {
    do {
      Spline_resetTime();
      trackIter = (int *)*trackIter;
    } while (trackIter != (int *)*(int *)(self + 0x24));
  }
  return;
}




/* cube::AdaptionWidget::vfunc_24 @ 00675660 */

void cube::AdaptionWidget::vfunc_24(void)

{
  return;
}




/* cube::AdaptionWidget::vfunc_2 @ 00687cf0 */

void cube::AdaptionWidget::vfunc_2(undefined4 *outPair)

{
  *outPair = 0;
  outPair[1] = 0;
  return;
}




/* cube::AdaptionWidget::vfunc_5 @ 00687d10 */

undefined1 cube::AdaptionWidget::vfunc_5(void)

{
  return 0;
}




