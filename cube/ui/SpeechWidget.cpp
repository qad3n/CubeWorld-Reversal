// SpeechWidget (ui) — cube. 6 functions. Bodies = Ghidra pseudo-C.
#include "SpeechWidget.h"

/* cube::SpeechWidget::ctor_0 @ 004e5c90 */

void cube::SpeechWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint cookie;
  undefined4 *self;
  void *local_8c [4];
  undefined4 local_7c;
  uint local_78;
  undefined1 local_74 [64];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9e39;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_78 = 7;
  local_7c = 0;
  local_8c[0] = (void *)((uint)local_8c[0] & 0xffff0000);
  local_14 = cookie;
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8 = 0;
  plasma::NamedObject::ctor_4(param_1,param_2,local_8c);
  if (7 < local_78) {
    operator_delete(local_8c[0]);
  }
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  self[0x59] = 0;
  self[0x5a] = 0;
  self[0x5b] = 0;
  self[0x5c] = 0;
  self[0x5e] = 0;
  self[0x5f] = 0;
  self[0x60] = 0;
  self[0x61] = 0;
  self[0x62] = 0;
  self[0x6f] = 7;
  self[0x6e] = 0;
  *(undefined2 *)(self + 0x6a) = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  self[0x75] = 0x28;
  self[0x76] = param_3;
  mat4_identity(cookie);
  local_24 = 0x43660000;
  local_20 = 0x43340000;
  local_34 = 0x41200000;
  local_30 = 0x41200000;
  local_1c = 0x437a0000;
  local_18 = 0x43480000;
  local_2c = 0;
  local_28 = 0;
  SpeechWidget_setBounds(&local_2c,&local_1c,&local_34,&local_24,local_74);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  self[0x70] = 0xe;
  self[0x71] = 3;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: SpeechWidget::dtor  (confidence: high)
 * purpose: SpeechWidget destructor (vfunc_0): frees text string at +0x1a8, sub-widget at +0x178, calls Widget base dtor
 * vars: self=this; str +0x1a8 cap +0x1bc
 */
/* Global::SpeechWidget_dtor @ 004e5ec0 */

void SpeechWidget_dtor(void)

{
  int self;
  undefined1 dummy;
  
  if (7 < *(uint *)(self + 0x1bc)) {
    operator_delete(*(void **)(self + 0x1a8));
  }
  *(undefined4 *)(self + 0x1bc) = 7;
  *(undefined4 *)(self + 0x1b8) = 0;
  *(undefined2 *)(self + 0x1a8) = 0;
  if (*(int *)(self + 0x178) != 0) {
    dtor_stringRange_0x18(*(int *)(self + 0x178),*(undefined4 *)(self + 0x17c),&dummy);
    operator_delete(*(void **)(self + 0x178));
  }
  vector_destroy_stringElems();
  plasma::Widget::ctor_0();
  return;
}




/* cube::SpeechWidget::vfunc_0 @ 004e5f60 */

void cube::SpeechWidget::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  SpeechWidget_dtor();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* cube::SpeechWidget::vfunc_1 @ 004e5f90 */

void cube::SpeechWidget::vfunc_1(void)

{
  float fontSize;
  char cVar2;
  int iVar3;
  int *lineNode;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  int charIndex;
  float10 fVar8;
  float posX;
  float fVar10;
  int cursorX;
  undefined1 first;
  undefined1 local_ec [64];
  float local_ac [2];
  float local_a4 [2];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9e78;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((-1 < *(int *)(in_ECX + 0x170)) &&
     (*(int *)(in_ECX + 0x170) < *(int *)(in_ECX + 0x164) - *(int *)(in_ECX + 0x160) >> 3)) {
    *(undefined4 *)(in_ECX + 0x1c8) = 0;
    *(undefined4 *)(in_ECX + 0x1cc) = 0;
    *(undefined4 *)(in_ECX + 0x1d0) = 0;
    (**(code **)(**(int **)(in_ECX + 4) + 0x40))(*(undefined4 *)(in_ECX + 0x148),local_14);
    first = 1;
    lineNode = (int *)**(int **)(*(int *)(in_ECX + 0x160) + *(int *)(in_ECX + 0x170) * 8);
    if (lineNode != *(int **)(*(int *)(in_ECX + 0x160) + *(int *)(in_ECX + 0x170) * 8)) {
      do {
        cVar2 = SpeechWidget_render_text(lineNode + 2,lineNode + 8,&first);
        if (cVar2 == '\0') break;
        lineNode = (int *)*lineNode;
      } while (lineNode != (int *)*(int *)(*(int *)(in_ECX + 0x160) + *(int *)(in_ECX + 0x170) * 8));
    }
    if (*(int *)(in_ECX + 0x174) / 3 != *(int *)(in_ECX + 0x1d0) / 3) {
      iVar5 = *(int *)(*(int *)(in_ECX + 0x1d8) + 0x8006d0);
      iVar3 = rand();
      playHitSoundAtPos(0x32,iVar5 + 0x10,0x3f800000,((float)iVar3 * 0.5) / 32767.0 + 1.0);
    }
    iVar5 = *(int *)(in_ECX + 0x170);
    *(undefined4 *)(in_ECX + 0x174) = *(undefined4 *)(in_ECX + 0x1d0);
    if ((iVar5 < 0) ||
       (iVar3 = *(int *)(in_ECX + 0x160), *(int *)(in_ECX + 0x164) - iVar3 >> 3 <= iVar5)) {
      charIndex = 0;
    }
    else {
      charIndex = 0;
      lineNode = (int *)**(int **)(iVar3 + iVar5 * 8);
      if (lineNode != *(int **)(iVar3 + iVar5 * 8)) {
        do {
          charIndex = charIndex + 1 + lineNode[6];
          lineNode = (int *)*lineNode;
        } while (lineNode != (int *)*(int *)(iVar3 + iVar5 * 8));
      }
      charIndex = *(int *)(in_ECX + 0x1d4) * charIndex;
    }
    if ((charIndex <= *(int *)(in_ECX + 0x16c)) &&
       (*(int *)(in_ECX + 0x178) != *(int *)(in_ECX + 0x17c))) {
      fVar8 = (float10)security_cookie_guard_a();
      cursorX = 0xf;
      iVar5 = FontCache_find_or_create_scalable(in_ECX + 0x1a8);
      if (iVar5 != 0) {
        (**(code **)(**(int **)(in_ECX + 4) + 0x38))(local_ec);
        iVar5 = *(int *)(*(int *)(in_ECX + 0x148) + 0x38);
        iVar3 = *(int *)(iVar5 + 0x170);
        iVar5 = *(int *)(iVar5 + 0x19c);
        fontSize = *(float *)(iVar5 + iVar3 * 8);
        charIndex = 0;
        if (0 < (*(int *)(in_ECX + 0x17c) - *(int *)(in_ECX + 0x178)) / 0x18) {
          posX = (float)(int)((float)fVar8 - 75.0) + *(float *)(iVar5 + 4 + iVar3 * 8);
          iVar5 = 0;
          do {
            local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
            local_18 = 7;
            local_1c = 0;
            u16string_replaceRange(*(int *)(in_ECX + 0x178) + iVar5,0,0xffffffff);
            fVar10 = (float)cursorX + fontSize;
            local_8 = 0;
            local_3c = 0;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0x3f800000;
            local_7c = 0x3f800000;
            local_78 = 0x3f800000;
            local_74 = 0x3f800000;
            local_70 = 0x3f800000;
            Font_drawTextTransformed(local_2c,fVar10,posX,(float)*(int *)(in_ECX + 0x1c0),
                         (float)*(int *)(in_ECX + 0x1c4),0,0,0,&local_7c,&local_4c,&local_3c,0,1);
            if (charIndex == *(int *)(in_ECX + 0x184)) {
              local_9c = 0;
              local_98 = 0x3f800000;
              local_94 = 0x3f800000;
              local_90 = 0x3f800000;
              puVar6 = &local_9c;
            }
            else {
              local_8c = 0x3f800000;
              local_88 = 0x3f800000;
              local_84 = 0x3f800000;
              local_80 = 0x3f800000;
              puVar6 = &local_8c;
            }
            local_6c = 0;
            local_68 = 0;
            local_64 = 0;
            local_60 = 0;
            local_5c = 0;
            local_58 = 0;
            local_54 = 0;
            local_50 = 0x3f800000;
            Font_drawTextTransformed(local_2c,fVar10,posX,(float)*(int *)(in_ECX + 0x1c0),0,0,0,0,puVar6,
                         &local_5c,&local_6c,0,1);
            Font_measureTextScaled(local_2c,local_ec,(float)*(int *)(in_ECX + 0x1c0),0,0,0,0,local_a4,local_ac
                         ,0,1,0xffffffff,0);
            local_8 = 0xffffffff;
            cursorX = cursorX + 0x14 + (int)(local_ac[0] - local_a4[0]);
            if (7 < local_18) {
              operator_delete(local_2c[0]);
            }
            local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
            charIndex = charIndex + 1;
            iVar5 = iVar5 + 0x18;
            local_18 = 7;
            local_1c = 0;
          } while (charIndex < (*(int *)(in_ECX + 0x17c) - *(int *)(in_ECX + 0x178)) / 0x18);
        }
      }
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x44))(*(undefined4 *)(in_ECX + 0x148));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: SpeechWidget::render_text  (confidence: high)
 * purpose: Renders speech-bubble text with typewriter reveal: measures glyphs, advances counters, draws lines via Font_drawTextTransformed
 * vars: param_1=text; in_ECX=widget; +0x1c8/+0x1cc scroll offsets
 */
/* Global::SpeechWidget_render_text @ 004e65a0 */

void SpeechWidget_render_text(int charSprite,undefined4 param_2,char *isSpace)

{
  float originX;
  float originY;
  int iVar3;
  int iVar4;
  bool isPunct;
  char matched;
  uint uVar7;
  int maxChars;
  int iVar9;
  undefined4 uVar10;
  int in_ECX;
  float10 fVar11;
  undefined1 local_a4 [64];
  float advance [2];
  float startX [2];
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined1 local_3c [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9ea8;
  local_10 = ExceptionList;
  uVar7 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar7;
  if (((*(int *)(charSprite + 0x10) == 0) ||
      (maxChars = *(int *)(in_ECX + 0x16c) / *(int *)(in_ECX + 0x1d4), maxChars < *(int *)(in_ECX + 0x1d0)
      )) || (iVar9 = FontCache_find_or_create_scalable(in_ECX + 0x1a8), iVar9 == 0)) goto LAB_004e69f8;
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))(local_a4,uVar7);
  Font_measureTextScaled(charSprite,local_a4,(float)*(int *)(in_ECX + 0x1c0),0,0,0,0,startX,advance,0,1,
               0xffffffff,0);
  matched = wstring_equalsCI(charSprite,&DAT_007020b8);
  if ((((matched == '\0') && (matched = wstring_equalsCI(charSprite,&DAT_007020bc), matched == '\0')) &&
      ((matched = wstring_equalsCI(charSprite,&DAT_007020c0), matched == '\0' &&
       ((matched = wstring_equalsCI(charSprite,&DAT_007020c4), matched == '\0' &&
        (matched = wstring_equalsCI(charSprite,&DAT_007020c8), matched == '\0')))))) &&
     (matched = wstring_equalsCI(charSprite,&DAT_007020cc), matched == '\0')) {
    matched = wstring_equalsCI(charSprite,&DAT_00701ba8);
    isPunct = false;
    if (matched != '\0') goto LAB_004e6722;
  }
  else {
LAB_004e6722:
    isPunct = true;
  }
  if (*isSpace == '\0') {
    if (isPunct) {
      *(int *)(in_ECX + 0x1c8) = *(int *)(in_ECX + 0x1c8) + 3;
    }
    else {
      *(int *)(in_ECX + 0x1c8) = *(int *)(in_ECX + 0x1c8) + 0xe;
    }
  }
  matched = wstring_equalsCI(charSprite,&DAT_007020bc);
  *isSpace = matched != '\0';
  if ((!isPunct) &&
     (iVar9 = *(int *)(in_ECX + 0x1c8), fVar11 = (float10)security_cookie_guard_b(),
     (float)fVar11 - 30.0 < (float)(iVar9 + (int)(advance[0] - startX[0])))) {
    *(undefined4 *)(in_ECX + 0x1c8) = 0;
    *(int *)(in_ECX + 0x1cc) = *(int *)(in_ECX + 0x1cc) + 0x12;
  }
  iVar9 = *(int *)(charSprite + 0x10);
  iVar3 = *(int *)(*(int *)(in_ECX + 0x148) + 0x38);
  iVar4 = *(int *)(iVar3 + 0x170);
  iVar3 = *(int *)(iVar3 + 0x19c);
  originX = *(float *)(iVar3 + iVar4 * 8);
  originY = *(float *)(iVar3 + 4 + iVar4 * 8);
  local_40 = 7;
  local_44 = 0;
  local_54 = (void *)((uint)local_54._2_2_ << 0x10);
  u16string_replaceRange(charSprite,0,0xffffffff);
  local_8 = 0;
  if (maxChars < *(int *)(in_ECX + 0x1d0) + iVar9) {
    iVar9 = maxChars - *(int *)(in_ECX + 0x1d0);
    uVar10 = wstring_ctorFromRange(local_3c,0,iVar9);
    u16string_moveClear(uVar10);
    std_string_FreeMember();
  }
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  Font_drawTextTransformed(&local_54,(float)(*(int *)(in_ECX + 0x1c8) + 10) + originX,
               (float)(*(int *)(in_ECX + 0x1cc) + 0x19) + originY,(float)*(int *)(in_ECX + 0x1c0),
               (float)*(int *)(in_ECX + 0x1c4),0,0,0,param_2,&local_34,&local_24,0,1);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  Font_drawTextTransformed(&local_54,(float)(*(int *)(in_ECX + 0x1c8) + 10) + originX,
               (float)(*(int *)(in_ECX + 0x1cc) + 0x19) + originY,(float)*(int *)(in_ECX + 0x1c0),0,0,
               0,0,param_2,&local_24,&local_34,0,1);
  *(int *)(in_ECX + 0x1c8) = *(int *)(in_ECX + 0x1c8) + (int)(advance[0] - startX[0]);
  *(int *)(in_ECX + 0x1d0) = *(int *)(in_ECX + 0x1d0) + iVar9 + 1;
  if (7 < local_40) {
    operator_delete(local_54);
  }
LAB_004e69f8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: SpeechWidget_setBounds  (confidence: med)
 * purpose: Sets widget bounds/anchors (offsets 0x48..0x54) from isSpace/param_4 rects
 * vars: in_ECX+0x48..0x54 rect; Matrix4_Invert
 */
/* Global::SpeechWidget_setBounds @ 00627c00 */

void SpeechWidget_setBounds(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *matrix)

{
  int self;
  int i;
  undefined4 *src;
  undefined4 *dst;
  
  *(undefined4 *)(self + 0x48) = *param_3;
  *(undefined4 *)(self + 0x4c) = param_3[1];
  *(undefined4 *)(self + 0x50) = *param_4;
  *(undefined4 *)(self + 0x54) = param_4[1];
  *(undefined4 *)(self + 0x58) = *param_1;
  *(undefined4 *)(self + 0x5c) = param_1[1];
  *(undefined4 *)(self + 0x60) = *param_2;
  *(undefined4 *)(self + 100) = param_2[1];
  *(undefined4 *)(self + 0x68) = *param_1;
  *(undefined4 *)(self + 0x6c) = param_1[1];
  *(undefined4 *)(self + 0x70) = *param_2;
  *(undefined4 *)(self + 0x74) = param_2[1];
  *(float *)(self + 0x78) = *(float *)(self + 0x60) - *(float *)(self + 0x50);
  *(float *)(self + 0x7c) = *(float *)(self + 100) - *(float *)(self + 0x54);
  src = matrix;
  dst = (undefined4 *)(self + 0xa8);
  for (i = 0x10; i != 0; i = i + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  src = (undefined4 *)(self + 0xe8);
  for (i = 0x10; i != 0; i = i + -1) {
    *src = *matrix;
    matrix = matrix + 1;
    src = src + 1;
  }
  Matrix4_Invert();
  return;
}




