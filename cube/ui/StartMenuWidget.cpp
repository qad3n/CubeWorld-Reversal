// StartMenuWidget (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "StartMenuWidget.h"

/* cube::StartMenuWidget::ctor_0 @ 00583270 */

void cube::StartMenuWidget::ctor_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  in_ECX[0x59] = param_3;
  *in_ECX = vftable;
  in_ECX[9] = vftable;
  in_ECX[0x58] = 0xffffffff;
  ExceptionList = local_10;
  return;
}




/* cube::StartMenuWidget::vfunc_1 @ 00583320 */

void cube::StartMenuWidget::vfunc_1(void)

{
  uint uVar1;
  int fontLoaded;
  int self;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  void *local_c4 [4];
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  void *local_8c [4];
  undefined4 local_7c;
  uint local_78;
  void *local_74 [5];
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float mouseY;
  float mouseX;
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
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f0f1e;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_78 = 7;
  local_7c = 0;
  local_8c[0] = (void *)((uint)local_8c[0] & 0xffff0000);
  local_14 = uVar1;
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8 = 0;
  fontLoaded = FontCache_find_or_create_scalable(local_8c);
  local_8 = 0xffffffff;
  if (7 < local_78) {
    operator_delete(local_8c[0]);
  }
  local_78 = 7;
  local_7c = 0;
  local_8c[0] = (void *)((uint)local_8c[0] & 0xffff0000);
  if (fontLoaded != 0) {
    (**(code **)(**(int **)(self + 4) + 0x40))(*(undefined4 *)(self + 0x148),uVar1);
    Widget_computeBoundsFloat(&mouseY);
    *(undefined4 *)(self + 0x160) = 0xffffffff;
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_1c = 0x3f800000;
    local_18 = 0x3f800000;
    if (0.0f <= mouseY) {
      fVar3 = (float)security_cookie_guard_b();
      if (((mouseY < (float)fVar3) && (10.0f <= mouseX)) && (mouseX < 40.0f)) {
        *(undefined4 *)(self + 0x160) = 0;
        local_24 = 0x3e4ccccd;
        local_20 = 0x3f800000;
        local_1c = 0x3f800000;
        local_18 = 0x3f800000;
      }
    }
    u16string_assignCStr(L"Start Game");
    uVar14 = 1;
    uVar13 = 1;
    puVar11 = &local_5c;
    puVar12 = &local_44;
    puVar10 = &local_34;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0x40800000;
    uVar5 = 0x41900000;
    local_8 = 1;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0x3f800000;
    local_34 = 0x3f800000;
    local_30 = 0x3f800000;
    local_2c = 0x3f800000;
    local_28 = 0x3f800000;
    uVar4 = 0x41f00000;
    fVar3 = (float)security_cookie_guard_b(0x41f00000,0x41900000,0x40800000,0,0,0,puVar10,puVar12,puVar11,1,1
                                 );
    Font_drawTextTransformed(local_74,(float)fVar3 * 0.5f,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,puVar10,puVar12,
                 puVar11,uVar13,uVar14);
    local_8 = 0xffffffff;
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    u16string_assignCStr(L"Start Game");
    uVar14 = 1;
    uVar13 = 1;
    puVar11 = &local_34;
    puVar12 = &local_44;
    puVar10 = &local_24;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = 0x41900000;
    local_8 = 2;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    uVar4 = 0x41f00000;
    fVar3 = (float)security_cookie_guard_b(0x41f00000,0x41900000,0,0,0,0,puVar10,puVar12,puVar11,1,1);
    Font_drawTextTransformed(local_74,(float)fVar3 * 0.5f,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,puVar10,puVar12,
                 puVar11,uVar13,uVar14);
    local_8 = 0xffffffff;
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_1c = 0x3f800000;
    local_18 = 0x3f800000;
    if (0.0f <= mouseY) {
      fVar3 = (float)security_cookie_guard_b();
      if (((mouseY < (float)fVar3) && (60.0f <= mouseX)) && (mouseX < 90.0f)) {
        *(undefined4 *)(self + 0x160) = 1;
        local_24 = 0x3e4ccccd;
        local_20 = 0x3f800000;
        local_1c = 0x3f800000;
        local_18 = 0x3f800000;
      }
    }
    u16string_assignCStr(L"Options");
    uVar14 = 1;
    uVar13 = 1;
    puVar11 = &local_34;
    puVar12 = &local_44;
    puVar10 = &local_5c;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0x40800000;
    uVar5 = 0x41900000;
    local_8 = 3;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    uVar4 = 0x42a00000;
    fVar3 = (float)security_cookie_guard_b(0x42a00000,0x41900000,0x40800000,0,0,0,puVar10,puVar12,puVar11,1,1
                                 );
    Font_drawTextTransformed(local_74,(float)fVar3 * 0.5f,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,puVar10,puVar12,
                 puVar11,uVar13,uVar14);
    local_8 = 0xffffffff;
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    u16string_assignCStr(L"Options");
    uVar14 = 1;
    uVar13 = 1;
    puVar11 = &local_34;
    puVar12 = &local_44;
    puVar10 = &local_24;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = 0x41900000;
    local_8 = 4;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    uVar4 = 0x42a00000;
    fVar3 = (float)security_cookie_guard_b(0x42a00000,0x41900000,0,0,0,0,puVar10,puVar12,puVar11,1,1);
    Font_drawTextTransformed(local_74,(float)fVar3 * 0.5f,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,puVar10,puVar12,
                 puVar11,uVar13,uVar14);
    local_8 = 0xffffffff;
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_1c = 0x3f800000;
    local_18 = 0x3f800000;
    if (0.0f <= mouseY) {
      fVar3 = (float)security_cookie_guard_b();
      if (((mouseY < (float)fVar3) && (110.0f <= mouseX)) && (mouseX < 140.0f)) {
        *(undefined4 *)(self + 0x160) = 2;
        local_24 = 0x3e4ccccd;
        local_20 = 0x3f800000;
        local_1c = 0x3f800000;
        local_18 = 0x3f800000;
      }
    }
    u16string_assignCStr(L"Exit");
    uVar14 = 1;
    uVar13 = 1;
    puVar11 = &local_34;
    puVar12 = &local_44;
    puVar10 = &local_5c;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0x40800000;
    uVar5 = 0x41900000;
    local_8 = 5;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    uVar4 = 0x43020000;
    fVar3 = (float)security_cookie_guard_b(0x43020000,0x41900000,0x40800000,0,0,0,puVar10,puVar12,puVar11,1,1
                                 );
    Font_drawTextTransformed(local_74,(float)fVar3 * 0.5f,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,puVar10,puVar12,
                 puVar11,uVar13,uVar14);
    local_8 = 0xffffffff;
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    u16string_assignCStr(L"Exit");
    uVar14 = 1;
    uVar13 = 1;
    puVar12 = &local_9c;
    puVar10 = &local_ac;
    puVar11 = &local_24;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = 0x41900000;
    local_8 = 6;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    uVar4 = 0x43020000;
    fVar3 = (float)security_cookie_guard_b(0x43020000,0x41900000,0,0,0,0,puVar11,puVar10,puVar12,1,1);
    Font_drawTextTransformed(local_c4,(float)fVar3 * 0.5f,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,puVar11,puVar10,
                 puVar12,uVar13,uVar14);
    local_8 = 0xffffffff;
    if (7 < local_b0) {
      operator_delete(local_c4[0]);
    }
    local_c4[0] = (void *)((uint)local_c4[0] & 0xffff0000);
    local_b0 = 7;
    local_b4 = 0;
    (**(code **)(**(int **)(self + 4) + 0x44))(*(undefined4 *)(self + 0x148));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




