// ChatWidget (ui) — cube. 13 functions. Bodies = Ghidra pseudo-C.
#include "ChatWidget.h"

/* cube::ChatWidget::ctor_0 @ 004393b0 */

void cube::ChatWidget::ctor_0(undefined4 param_1,undefined4 param_2)

{
  undefined4 tmp;
  undefined4 *self;
  void *nameBuf [4];
  undefined4 nameLen;
  uint nameCap;
  undefined4 resNameBuf;
  undefined4 resNameLen;
  uint resNameCap;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e29c4;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  nameCap = 7;
  nameLen = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,nameBuf);
  local_8._0_1_ = 2;
  if (7 < nameCap) {
    operator_delete(nameBuf[0]);
  }
  *self = vftable;
  self[9] = vftable;
  nameCap = 7;
  nameLen = 0;
  nameBuf[0] = (void *)((uint)nameBuf[0] & 0xffff0000);
  self[0x58] = 0;
  self[0x59] = 0;
  tmp = rbtree_allocNode_10(0,0);
  self[0x58] = tmp;
  self[0x5f] = 7;
  self[0x5e] = 0;
  *(undefined2 *)(self + 0x5a) = 0;
  local_8._0_1_ = 4;
  *(undefined1 *)(self + 0x60) = 0;
  self[0x62] = 0;
  self[99] = 0;
  resNameCap = 7;
  resNameLen = 0;
  resNameBuf = (void *)((uint)resNameBuf._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8 = CONCAT31(local_8._1_3_,5);
  tmp = FontCache_find_or_create_scalable(&resNameBuf);
  self[0x61] = tmp;
  if (7 < resNameCap) {
    operator_delete(resNameBuf);
  }
  self[0x4a] = self[0x4a] | 0x40;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: ChatWidget::clearText  (confidence: med)
 * purpose: Frees SSO string at +0x168 (cap>7) and clears, then list::clear 00439680, deletes buffer +0x160
 * vars: +0x17c cap; +0x168 str
 */
/* Global::ChatWidget_clearText @ 00439530 */

void ChatWidget_clearText(void)

{
  int self;
  
  if (7 < *(uint *)(self + 0x17c)) {
    operator_delete(*(void **)(self + 0x168));
  }
  *(undefined4 *)(self + 0x17c) = 7;
  *(undefined4 *)(self + 0x178) = 0;
  *(undefined2 *)(self + 0x168) = 0;
  list_clear();
  operator_delete(*(void **)(self + 0x160));
}




/* cube::ChatWidget::vfunc_0 @ 00439590 */

void cube::ChatWidget::vfunc_0(byte deleteFlag)

{
  void *self;
  
  ChatWidget_clearText();
  if ((deleteFlag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




/* cube::ChatWidget::vfunc_3 @ 00439660 */

undefined4 cube::ChatWidget::vfunc_3(undefined4 obj)

{
  AdaptionWidget_getBoundsRect(obj);
  return obj;
}




/* [AUDIT] proposed: list::clear  (confidence: med)
 * purpose: Clears intrusive list: unlink nodes, reset head self-links, size=0, free node buffer
 * vars: head at *ECX
 */
/* Global::list_clear @ 00439680 */

void list_clear(void)

{
  int *listHead;
  int firstNode;
  int *self;
  
  listHead = (int *)*self;
  firstNode = *listHead;
  *listHead = (int)listHead;
  *(int *)(*self + 4) = *self;
  self[1] = 0;
  if (firstNode != *self) {
    listNode_free_ownsString();
    operator_delete(*(void **)(firstNode + 8));
  }
  return;
}




/* cube::ChatWidget::vfunc_1 @ 00439730 */

void cube::ChatWidget::vfunc_1(void)

{
  int maxPos;
  int pos;
  int hasColor;
  uint msgCount;
  int self;
  int *segNode;
  int *msgNode;
  bool bVar7;
  float10 fVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int yPos;
  undefined1 local_e4 [8];
  float bounds0 [2];
  float bounds1 [2];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  uint local_88;
  float colR;
  float colG;
  float colB;
  undefined4 uStack_78;
  void *local_74 [2];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  float local_5c;
  float fStack_58;
  float local_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float xPos;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e2a03;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  msgCount = *(uint *)(self + 0x164);
  yPos = 0x13;
  while (10 < msgCount) {
    msgNode = (int *)**(int **)(self + 0x160);
    if (msgNode != *(int **)(self + 0x160)) {
      *(int *)msgNode[1] = *msgNode;
      *(int *)(*msgNode + 4) = msgNode[1];
      listNode_free_ownsString();
      operator_delete((void *)msgNode[2]);
    }
    msgCount = *(uint *)(self + 0x164);
  }
  (**(code **)(**(int **)(self + 4) + 0x40))(*(undefined4 *)(self + 0x148),local_14);
  msgNode = (int *)**(int **)(self + 0x160);
  if (msgNode != *(int **)(self + 0x160)) {
    do {
      xPos = 3.0;
      segNode = *(int **)msgNode[2];
      if (segNode != (int *)msgNode[2]) {
        do {
          hasColor = u16string_compare(0,segNode[6],&DAT_006fd844,1);
          if (hasColor == 0) {
            xPos = xPos + 5.0;
          }
          else {
            colR = (float)*(byte *)(segNode + 8) / 255.0;
            colG = (float)*(byte *)((int)segNode + 0x21) / 255.0;
            colB = (float)*(byte *)((int)segNode + 0x22) / 255.0;
            uStack_78 = 0x3f800000;
            Font_measureTextScaled(segNode + 2,*(int *)(self + 0x148) + 0x48,0x41200000,0x40000000,0,0,0,
                         bounds0,bounds1,0,1,0xffffffff,0);
            _local_5c = CONCAT44(colG * 0.0,colR * 0.0);
            _local_54 = CONCAT44(uStack_78,colB * 0.0);
            local_6c = 0;
            local_68 = 0;
            local_64 = 0;
            local_60 = 0;
            local_3c = 0;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            Font_drawTextTransformed(segNode + 2,xPos,(float)yPos,0x41200000,0x40000000,0,0,0,&local_3c,
                         &local_5c,&local_6c,0,1);
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            local_2c = 0;
            local_28 = 0;
            local_24 = 0;
            local_20 = 0;
            Font_drawTextTransformed(segNode + 2,xPos,(float)yPos,0x41200000,0x40000000,0,0,0,&colR,
                         &local_2c,&local_4c,0,1);
            xPos = (bounds1[0] - bounds0[0]) + xPos;
          }
          segNode = (int *)*segNode;
        } while (segNode != (int *)msgNode[2]);
      }
      msgNode = (int *)*msgNode;
      yPos = yPos + 0x12;
    } while (msgNode != (int *)*(int *)(self + 0x160));
  }
  uVar18 = 1;
  uVar17 = 0;
  puVar16 = &local_2c;
  puVar15 = &local_4c;
  puVar14 = &local_3c;
  uVar13 = 0;
  uVar12 = 0;
  uVar11 = 0;
  uVar10 = 0x40000000;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0x3f800000;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  hasColor = self + 0x168;
  uVar9 = 0x41200000;
  fVar8 = (float10)security_cookie_guard_a(0x41200000,0x40000000,0,0,0,puVar14,puVar15,puVar16,0,1);
  Font_drawTextTransformed(hasColor,0x40400000,(float)fVar8 - 12.0,uVar9,uVar10,uVar11,uVar12,uVar13,puVar14,
               puVar15,puVar16,uVar17,uVar18);
  uVar18 = 1;
  uVar17 = 0;
  puVar16 = &local_2c;
  puVar15 = &local_4c;
  puVar14 = &local_3c;
  uVar13 = 0;
  uVar12 = 0;
  uVar11 = 0;
  uVar10 = 0x40000000;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0x3f800000;
  local_38 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  uVar9 = 0x41200000;
  fVar8 = (float10)security_cookie_guard_a(0x41200000,0x40000000,0,0,0,puVar14,puVar15,puVar16,0,1);
  Font_drawTextTransformed(hasColor,0x40400000,(float)fVar8 - 12.0,uVar9,uVar10,uVar11,uVar12,uVar13,puVar14,
               puVar15,puVar16,uVar17,uVar18);
  if (*(char *)(self + 0x180) != '\0') {
    msgCount = *(int *)(*(int *)(self + 4) + 0xe8) / 500 & 0x80000001;
    bVar7 = msgCount == 0;
    if ((int)msgCount < 0) {
      bVar7 = (msgCount - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar7) {
      if (*(int *)(self + 0x188) < 0) {
        *(undefined4 *)(self + 0x188) = 0;
      }
      maxPos = *(int *)(self + 0x178);
      if (maxPos < *(int *)(self + 0x188)) {
        *(int *)(self + 0x188) = maxPos;
      }
      pos = *(int *)(self + 0x188);
      if (*(int *)(self + 0x18c) + pos < 0) {
        *(int *)(self + 0x18c) = -pos;
      }
      if (maxPos < *(int *)(self + 0x18c) + pos) {
        *(int *)(self + 0x188) = maxPos - *(int *)(self + 0x18c);
      }
      ChatWidget_measureChatText(hasColor,*(undefined4 *)(self + 0x188),*(int *)(self + 0x148) + 0x48,0x41200000,
                   0x40000000,0,0,0,&local_1c,local_e4,0,1);
      local_60 = 7;
      local_64 = 0;
      local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
      u16string_assignPtrLen(&DAT_006fd848,1);
      uVar18 = 1;
      uVar17 = 0;
      puVar16 = &local_2c;
      puVar15 = &local_4c;
      puVar14 = &local_3c;
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0x40000000;
      local_8 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0x3f800000;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      uVar9 = 0x41200000;
      fVar8 = (float10)security_cookie_guard_a(0x41200000,0x40000000,0,0,0,puVar14,puVar15,puVar16,0,1);
      Font_drawTextTransformed(local_74,local_1c + 3.0,(float)fVar8 - 12.0,uVar9,uVar10,uVar11,uVar12,uVar13,
                   puVar14,puVar15,puVar16,uVar17,uVar18);
      local_8 = 0xffffffff;
      if (7 < local_60) {
        operator_delete(local_74[0]);
      }
      local_88 = 7;
      local_8c = 0;
      local_9c = (void *)((uint)local_9c._2_2_ << 0x10);
      u16string_assignPtrLen(&DAT_006fd848,1);
      uVar18 = 1;
      uVar17 = 0;
      puVar16 = &local_cc;
      puVar15 = &local_bc;
      puVar14 = &local_ac;
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0x40000000;
      local_8 = 1;
      local_cc = 0;
      local_c8 = 0;
      local_c4 = 0;
      local_c0 = 0;
      local_bc = 0;
      local_b8 = 0;
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0x3f800000;
      local_a8 = 0x3f800000;
      local_a4 = 0x3f800000;
      local_a0 = 0x3f800000;
      uVar9 = 0x41200000;
      fVar8 = (float10)security_cookie_guard_a(0x41200000,0x40000000,0,0,0,puVar14,puVar15,puVar16,0,1);
      Font_drawTextTransformed(&local_9c,local_1c + 3.0,(float)fVar8 - 12.0,uVar9,uVar10,uVar11,uVar12,uVar13,
                   puVar14,puVar15,puVar16,uVar17,uVar18);
      local_8 = 0xffffffff;
      if (7 < local_88) {
        operator_delete(local_9c);
      }
      local_88 = 7;
      local_8c = 0;
      local_9c = (void *)((uint)local_9c & 0xffff0000);
    }
  }
  (**(code **)(**(int **)(self + 4) + 0x44))(*(undefined4 *)(self + 0x148));
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::ChatWidget::vfunc_4 @ 0043a000 */

undefined1 cube::ChatWidget::vfunc_4(void)

{
  return 1;
}




/* [AUDIT] proposed: ChatWidget::measureChatText  (confidence: med)
 * purpose: Wrapper: under CS measures a text block (Font_measureTextBlock) with optional truncation, scales returned min/max by cell width/height.
 * vars: class ChatWidget; param_8/9=out bounds; +0x10c CS
 */
/* Global::ChatWidget_measureChatText @ 0065e8d0 */

void ChatWidget_measureChatText(undefined4 text,undefined4 lineIndex,undefined4 arg3,float size,
                 undefined4 arg5,undefined4 arg6,undefined4 arg7,float arg8,
                 float *minOut,float *maxOut,uint flags,undefined4 param_12)

{
  int self;
  float scaleY;
  void *clippedText [4];
  undefined4 clipStub;
  uint clipCap;
  uint stackCookie;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 ehState;
  
  ehState = 0xffffffff;
  sehHandler = &LAB_006f7008;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExceptionList;
  EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x10c));
  TextRender_configureSize(size,arg5,arg6,arg7,arg3,param_12);
  scaleY = size / *(float *)(self + 0xe4);
  size = size / *(float *)(self + 0xe0);
  if ((char)param_12 != '\0') {
    arg8 = arg8 / size;
  }
  if ((flags & 0x10) == 0) {
    Font_measureTextBlock(text,lineIndex,minOut,maxOut,flags);
  }
  else {
    clipCap = 7;
    clipStub = 0;
    clippedText[0] = (void *)((uint)clippedText[0] & 0xffff0000);
    u16string_replaceRange(text,0,0xffffffff);
    ehState = 0;
    TextRender_layoutAndWrap(clippedText,arg8);
    Font_measureTextBlock(clippedText,lineIndex,minOut,maxOut,flags);
    if (7 < clipCap) {
      operator_delete(clippedText[0]);
    }
  }
  *minOut = *minOut * size;
  minOut[1] = minOut[1] * scaleY;
  *maxOut = *maxOut * size;
  maxOut[1] = maxOut[1] * scaleY;
  LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x10c));
  ExceptionList = savedExceptionList;
  __security_check_cookie(stackCookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: TextRender::configureSize  (confidence: med)
 * purpose: Chooses fixed vs scaled text sizing: computes scaled size then applies, or falls through to transform path; stores render params
 * vars: self+0xf4=mode flag; +0xe0..0xec size/pos; arg6=scaled flag
 */
/* Global::TextRender_configureSize @ 006605c0 */

void TextRender_configureSize(undefined4 size,undefined4 arg2,undefined4 arg3,undefined4 arg4,
                 undefined4 text,char useKerning)

{
  int self;
  undefined4 outMin;
  undefined4 outSize;
  undefined4 outAdvance;
  undefined4 outScaleX;
  undefined4 outScaleY;
  uint stackCookie;
  
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if (*(int *)(self + 0xf4) == 0) {
    if (useKerning != '\0') {
      TextRender_computeScaledSize(text,size,arg2,arg3,arg4,&outScaleX,&outMin,&outAdvance,&outSize);
      Font_setPixelSizeAndCacheGlyphs(outScaleX,outScaleY,outMin);
      *(undefined4 *)(self + 0xec) = outAdvance;
      arg4 = outSize;
      goto LAB_006606cb;
    }
    TextRender_setTransform(size,arg2,text);
  }
  else {
    *(undefined4 *)(self + 0xe0) = size;
    *(undefined4 *)(self + 0xe4) = size;
    *(undefined4 *)(self + 0xe8) = arg2;
    *(undefined1 *)(self + 0x108) = 0;
  }
  *(undefined4 *)(self + 0xec) = arg3;
LAB_006606cb:
  *(undefined4 *)(self + 0xf0) = arg4;
  __security_check_cookie(stackCookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: TextRender::setTransform  (confidence: med)
 * purpose: Builds a 16.16 fixed-point 2x2 transform from a matrix, computes sqrt scale, sets FT transform and caches transformed glyphs
 * vars: self+0x78..0x84=16.16 matrix; +0x88..0x9c float matrix; +0xe0/0xe8 scale; map cache
 */
/* Global::TextRender_setTransform @ 006606f0 */

void TextRender_setTransform(float size,float arg2,float *matrix)

{
  void *pvVar1;
  uint stackCookie;
  undefined4 **ppuVar3;
  undefined4 uVar4;
  undefined4 *glyphSlot;
  int *matrixPtr;
  int self;
  undefined4 *roundedSize;
  double len;
  float dx;
  float dy;
  undefined4 *faceSizeX;
  undefined4 local_4c;
  undefined4 *metric;
  undefined4 *faceSizeY;
  int *charData;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *matrixField;
  undefined4 *local_30;
  undefined1 vecTmp [8];
  void *allocGuard;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 ehState;
  
  pvVar1 = ExceptionList;
  ehState = 0xffffffff;
  sehHandler = &LAB_006f71ae;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xffffffa0;
  ExceptionList = &savedExceptionList;
  *(float *)(self + 0x88) = *matrix;
  *(float *)(self + 0x8c) = matrix[1];
  *(float *)(self + 0x9c) = matrix[5];
  *(float *)(self + 0x98) = matrix[4];
  matrixPtr = (int *)(self + 0x78);
  *matrixPtr = (int)(*matrix * 65536.0);
  *(int *)(self + 0x80) = -(int)(matrix[1] * 65536.0);
  *(int *)(self + 0x84) = (int)(matrix[5] * 65536.0);
  *(int *)(self + 0x7c) = -(int)(matrix[4] * 65536.0);
  if (size <= 0.0) {
    ExceptionList = pvVar1;
    return;
  }
  *(float *)(self + 0xe0) = size;
  *(float *)(self + 0xe4) = size;
  *(undefined1 *)(self + 0x108) = 0;
  faceSizeX = (undefined4 *)(matrix[4] * 0.0 + *matrix);
  dx = *matrix * 0.0 + matrix[4];
  faceSizeY = (undefined4 *)(matrix[5] * 0.0 + matrix[1]);
  dy = matrix[1] * 0.0 + matrix[5];
  len = (double)(dy * dy + dx * dx);
  libm_sse2_sqrt_precise(stackCookie);
  metric = (undefined4 *)(float)len;
  len = (double)((float)faceSizeY * (float)faceSizeY + (float)faceSizeX * (float)faceSizeX);
  libm_sse2_sqrt_precise();
  faceSizeX = (undefined4 *)(float)len;
  ppuVar3 = &metric;
  if ((float)len <= (float)metric) {
    ppuVar3 = &faceSizeX;
  }
  *(float *)(self + 0xe8) = (float)*ppuVar3 * arg2;
  roundedSize = (undefined4 *)(int)(size * 64.0 + 0.5);
  metric = roundedSize;
  FT_Set_Pixel_Sizes(*(undefined4 *)(self + 0xd8),roundedSize,roundedSize,0,0);
  ChatWidget_setBindTransform(*(undefined4 *)(self + 0xd8),matrixPtr,0);
  charData = (int *)0x0;
  local_3c = 0;
  local_38 = 0;
  vectorInt_resize(4);
  ehState._0_1_ = 0;
  ehState._1_3_ = 0;
  *charData = *matrixPtr;
  charData[1] = *(int *)(self + 0x7c);
  charData[2] = *(int *)(self + 0x80);
  charData[3] = *(int *)(self + 0x84);
  local_4c = 0;
  faceSizeX = roundedSize;
  uVar4 = Pair_constructMoveKeyString(vecTmp,&faceSizeX,&charData);
  std_map_findVecKeyNode(&faceSizeX,uVar4);
  if (allocGuard != (void *)0x0) {
    operator_delete(allocGuard);
  }
  if (faceSizeX == *(undefined4 **)(self + 0x70)) {
    glyphSlot = operator_new(8);
    ehState._0_1_ = 1;
    if (glyphSlot == (undefined4 *)0x0) {
      glyphSlot = (undefined4 *)0x0;
    }
    else {
      *glyphSlot = 0;
      glyphSlot[1] = 0;
      faceSizeX = glyphSlot;
      uVar4 = rbtree_allocHead24();
      *glyphSlot = uVar4;
    }
    roundedSize = metric;
    *(undefined4 **)(self + 200) = glyphSlot;
    ehState._0_1_ = 0;
    faceSizeX = metric;
    local_4c = 0;
    uVar4 = Pair_constructMoveKeyString(vecTmp,&faceSizeX,&charData);
    ehState._0_1_ = 2;
    glyphSlot = (undefined4 *)std_map_insertOrAssignMoveVal(uVar4);
    *glyphSlot = *(undefined4 *)(self + 200);
    ehState._0_1_ = 0;
    if (allocGuard != (void *)0x0) {
      operator_delete(allocGuard);
    }
  }
  else {
    *(undefined4 *)(self + 200) = faceSizeX[9];
  }
  if (arg2 <= 0.0) {
    *(undefined4 *)(self + 0xcc) = 0;
  }
  else {
    faceSizeX = (undefined4 *)(int)(arg2 * 64.0 + 0.5);
    matrixField = roundedSize;
    local_30 = faceSizeX;
    uVar4 = Pair_constructMoveKeyString(vecTmp,&matrixField,&charData);
    matrixPtr = (int *)std_map_findVecKeyNode(&faceSizeY,uVar4);
    if (allocGuard != (void *)0x0) {
      operator_delete(allocGuard);
    }
    if (*matrixPtr == *(int *)(self + 0x70)) {
      roundedSize = operator_new(8);
      ehState._0_1_ = 3;
      faceSizeY = roundedSize;
      if (roundedSize == (undefined4 *)0x0) {
        roundedSize = (undefined4 *)0x0;
      }
      else {
        *roundedSize = 0;
        roundedSize[1] = 0;
        uVar4 = rbtree_allocHead24();
        *roundedSize = uVar4;
      }
      matrixField = metric;
      local_30 = faceSizeX;
      ehState._0_1_ = 0;
      *(undefined4 **)(self + 0xcc) = roundedSize;
      uVar4 = Pair_constructMoveKeyString(vecTmp,&matrixField,&charData);
      ehState._0_1_ = 4;
      roundedSize = (undefined4 *)std_map_insertOrAssignMoveVal(uVar4);
      *roundedSize = *(undefined4 *)(self + 0xcc);
      if (allocGuard != (void *)0x0) {
        operator_delete(allocGuard);
      }
    }
    else {
      *(undefined4 *)(self + 0xcc) = *(undefined4 *)(*matrixPtr + 0x24);
    }
    ft_stroker_set_params(*(undefined4 *)(self + 0xdc),(int)(*(float *)(self + 0xe8) * 64.0 + 0.5),1,0,0)
    ;
  }
  operator_delete(charData);
}




/* [AUDIT] proposed: TextRender::computeScaledSize  (confidence: high)
 * purpose: Computes clamped scaled glyph width/height (max 1000) and derived spacing from a transform matrix and scale factor
 * vars: size=matrix; param_6/7/8/9=out w-h/spacing; DAT_00768f6c=max spacing clamp
 */
/* Global::TextRender_computeScaledSize @ 00660b60 */

void TextRender_computeScaledSize(float *matrix,float size,float arg3,float arg4,float arg5,
                 float *outSizeVec,float *outAdvance,float *outWidth,float *outHeight)

{
  int self;
  double lenX;
  double lenY;
  float basisX;
  float basisY;
  float basisX2;
  float basisY2;
  
  if (*(int *)(self + 0xf4) != 0) {
    *outSizeVec = size;
    outSizeVec[1] = size;
    *outAdvance = arg3;
    *outWidth = arg4;
    *outHeight = arg5;
    return;
  }
  basisX = matrix[5] * 0.0 + matrix[1];
  basisY = matrix[4] * 0.0 + *matrix;
  basisX2 = matrix[1] * 0.0 + matrix[5];
  basisY2 = *matrix * 0.0 + matrix[4];
  lenX = (double)(basisX * basisX + basisY * basisY);
  libm_sse2_sqrt_precise();
  lenY = (double)(basisX2 * basisX2 + basisY2 * basisY2);
  libm_sse2_sqrt_precise();
  basisY = (float)(int)((float)lenX * size * 64.0 + 0.5) * 0.015625;
  basisX = (float)(int)((float)lenY * size * 64.0 + 0.5) * 0.015625;
  *outSizeVec = basisY;
  outSizeVec[1] = basisX;
  if (1000.0 < basisY) {
    *outSizeVec = 1000.0;
  }
  if (1000.0 < basisX) {
    outSizeVec[1] = 1000.0;
  }
  basisX = outSizeVec[1];
  basisY = *outSizeVec;
  *outAdvance = (basisX / size + basisY / size) * 0.5 * arg3;
  *outWidth = (basisY / size) * arg4;
  *outHeight = (basisX / size) * arg5;
  if (*outSizeVec <= 1.0 && *outSizeVec != 1.0) {
    *outSizeVec = 1.0;
  }
  if (outSizeVec[1] <= 1.0 && outSizeVec[1] != 1.0) {
    outSizeVec[1] = 1.0;
  }
  if (DAT_00768f6c < *outAdvance) {
    *outAdvance = DAT_00768f6c;
  }
  return;
}




/* [AUDIT] proposed: TextRender::layoutAndWrap  (confidence: med)
 * purpose: Walks a UTF-16 string measuring per-glyph advances/kerning, handles space/newline/CR word-wrap by inserting break chars
 * vars: self+0xf4=mode; +0x108=fixed flag; iVar8*2=UTF-16 index; FT_Get_Char_Index=glyph advance/kern
 */
/* Global::TextRender_layoutAndWrap @ 00660d50 */

void TextRender_layoutAndWrap(undefined4 *text,float maxWidth)

{
  undefined2 charCode;
  uint strFlag;
  undefined4 *textStr;
  float fVar4;
  undefined4 *charPtr;
  int glyph;
  undefined4 uVar7;
  int self;
  int charIndex;
  float nextWidth;
  int kernPair [2];
  int lastSpace;
  float scaleY;
  undefined4 *charPtr2;
  int charCount;
  float wordStart;
  float lineWidth;
  
  textStr = text;
  charCount = text[4];
  lineWidth = 0.0;
  wordStart = 0.0;
  lastSpace = -1;
  scaleY = 1.0;
  if (*(int *)(self + 0xf4) != 0) {
    scaleY = *(float *)(self + 0xe4) / (*(float *)(self + 0x104) - *(float *)(self + 0xfc));
  }
  charIndex = 0;
  if (0 < charCount) {
    do {
      nextWidth = 0.0;
      strFlag = textStr[5];
      charPtr = textStr;
      if (7 < strFlag) {
        charPtr = (undefined4 *)*textStr;
      }
      if (*(short *)((int)charPtr + charIndex * 2) == 0x20) {
LAB_00660e03:
        glyph = charIndex;
        fVar4 = lineWidth;
        if (maxWidth <= lineWidth) {
          if (-1 < lastSpace) {
            charPtr = textStr;
            if (7 < strFlag) {
              charPtr = (undefined4 *)*textStr;
            }
            *(undefined2 *)((int)charPtr + lastSpace * 2) = 10;
          }
          lineWidth = lineWidth - wordStart;
          fVar4 = lineWidth;
        }
      }
      else {
        charPtr = textStr;
        if (7 < strFlag) {
          charPtr = (undefined4 *)*textStr;
        }
        if (*(short *)((int)charPtr + charIndex * 2) == 10) goto LAB_00660e03;
        charPtr = textStr;
        if (7 < strFlag) {
          charPtr = (undefined4 *)*textStr;
        }
        if ((*(short *)((int)charPtr + charIndex * 2) == 0xd) ||
           (glyph = lastSpace, fVar4 = wordStart, charIndex == charCount + -1)) goto LAB_00660e03;
      }
      wordStart = fVar4;
      lastSpace = glyph;
      strFlag = textStr[5];
      charPtr = textStr;
      if (7 < strFlag) {
        charPtr = (undefined4 *)*textStr;
      }
      if (*(short *)((int)charPtr + charIndex * 2) == 10) {
LAB_00661027:
        wordStart = 0.0;
      }
      else {
        charPtr = textStr;
        if (7 < strFlag) {
          charPtr = (undefined4 *)*textStr;
        }
        if (*(short *)((int)charPtr + charIndex * 2) == 0xd) goto LAB_00661027;
        charPtr = textStr;
        if (7 < strFlag) {
          charPtr = (undefined4 *)*textStr;
        }
        charCode = *(undefined2 *)((int)charPtr + charIndex * 2);
        if (*(int *)(self + 0xf4) == 0) {
          if (*(char *)(self + 0x108) == '\0') {
            glyph = Font_rasterizeGlyph3D(*(undefined4 *)(self + 200),charCode,0);
          }
          else {
            glyph = Font_rasterizeGlyphBitmap(*(undefined4 *)(self + 200),charCode,0);
          }
        }
        else {
          glyph = Font_findCachedGlyph3D(charCode);
        }
        text = (undefined4 *)0x0;
        if (glyph != 0) {
          text = *(undefined4 **)(glyph + 0x10);
        }
        if (charIndex < charCount + -1) {
          if (*(int *)(self + 0xf4) == 0) {
            if (*(char *)(self + 0x108) == '\0') {
              if ((uint)textStr[5] < 8) {
                charPtr2 = textStr;
                charPtr = textStr;
              }
              else {
                charPtr2 = (undefined4 *)*textStr;
                charPtr = (undefined4 *)*textStr;
              }
              uVar7 = FT_Get_Char_Index(*(undefined4 *)(self + 0xd8),
                                   *(undefined2 *)((int)charPtr + charIndex * 2 + 2),2,kernPair);
              uVar7 = FT_Get_Char_Index(*(undefined4 *)(self + 0xd8),
                                   *(undefined2 *)((int)charPtr2 + charIndex * 2),uVar7);
              FT_Get_Kerning(*(undefined4 *)(self + 0xd8),uVar7);
              text = (undefined4 *)
                        (((float)kernPair[0] * *(float *)(self + 0xe0)) /
                         (float)*(ushort *)(*(int *)(self + 0xd8) + 0x44) + (float)text);
            }
            else {
              if ((uint)textStr[5] < 8) {
                charPtr2 = textStr;
                charPtr = textStr;
              }
              else {
                charPtr2 = (undefined4 *)*textStr;
                charPtr = (undefined4 *)*textStr;
              }
              uVar7 = FT_Get_Char_Index(*(undefined4 *)(self + 0xd8),
                                   *(undefined2 *)((int)charPtr + charIndex * 2 + 2),0,kernPair);
              uVar7 = FT_Get_Char_Index(*(undefined4 *)(self + 0xd8),
                                   *(undefined2 *)((int)charPtr2 + charIndex * 2),uVar7);
              FT_Get_Kerning(*(undefined4 *)(self + 0xd8),uVar7);
              text = (undefined4 *)((float)(kernPair[0] >> 6) + (float)text);
            }
          }
          lineWidth = *(float *)(self + 0xec) + lineWidth;
        }
        if (*(char *)(self + 0x108) == '\0') {
          nextWidth = (float)text * scaleY + lineWidth;
        }
        else {
          nextWidth = (float)(int)((float)text + lineWidth);
        }
      }
      charIndex = charIndex + 1;
      lineWidth = nextWidth;
    } while (charIndex < charCount);
  }
  return;
}




/* [AUDIT] proposed: ChatWidget::setBindTransform  (confidence: high)
 * purpose: Sets bind pos/size (maxWidth, default identity 0x10000) and offset (param_3) into widget layout obj+0x80, sets dirty flags
 * vars: text=widget; +0x80=layout; +0x1c dirty bits 1/2
 */
/* Global::ChatWidget_setBindTransform @ 0068f1b0 */

void ChatWidget_setBindTransform(int glyph,int *matrix,int *offset)

{
  int renderState;
  int offsetY;
  
  offsetY = 0;
  if (glyph != 0) {
    renderState = *(int *)(glyph + 0x80);
    *(undefined4 *)(renderState + 0x1c) = 0;
    if (matrix == (int *)0x0) {
      matrix = (int *)(renderState + 4);
      *matrix = 0x10000;
      *(undefined4 *)(renderState + 8) = 0;
      *(undefined4 *)(renderState + 0xc) = 0;
      *(undefined4 *)(renderState + 0x10) = 0x10000;
    }
    else {
      *(int *)(renderState + 4) = *matrix;
      *(int *)(renderState + 8) = matrix[1];
      *(int *)(renderState + 0xc) = matrix[2];
      *(int *)(renderState + 0x10) = matrix[3];
    }
    if (((matrix[2] != 0 || matrix[1] != 0) || (*matrix != 0x10000)) || (matrix[3] != 0x10000))
    {
      *(undefined4 *)(renderState + 0x1c) = 1;
    }
    if (offset == (int *)0x0) {
      offset = (int *)(renderState + 0x14);
      *offset = 0;
    }
    else {
      *(int *)(renderState + 0x14) = *offset;
      offsetY = offset[1];
    }
    *(int *)(renderState + 0x18) = offsetY;
    if (offset[1] != 0 || *offset != 0) {
      *(uint *)(renderState + 0x1c) = *(uint *)(renderState + 0x1c) | 2;
    }
  }
  return;
}




