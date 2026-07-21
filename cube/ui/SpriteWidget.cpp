// SpriteWidget (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "SpriteWidget.h"

/* cube::SpriteWidget::ctor_0 @ 0051c310 */

void cube::SpriteWidget::ctor_0(undefined4 world,undefined4 name,undefined4 owner)

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
  plasma::NamedObject::ctor_4(world,name,local_28);
  if (7 < local_14) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_28[0]);
  }
  self[0x5a] = owner;
  *self = vftable;
  self[9] = vftable;
  self[0x58] = 0;
  self[0x59] = 0;
  ExceptionList = local_10;
  return;
}




/* cube::SpriteWidget::vfunc_1 @ 0051c3d0 */

void cube::SpriteWidget::vfunc_1(void)

{
  float depth;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  int self;
  undefined8 *puVar5;
  int zeroCount;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float screenX;
  float invW;
  float camX;
  char *modelName;
  undefined4 uVar14;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined8 local_1c8 [32];
  undefined8 local_c8 [24];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(self + 0x160) != 0) || (*(int *)(self + 0x164) != 0)) {
    piVar2 = *(int **)(*(int *)(self + 0x168) + 0x134);
    (**(code **)(*piVar2 + 0xe4))(piVar2,7,1);
    local_1d8 = 0;
    uStack_1d4 = 0;
    local_1d0 = 0;
    uStack_1cc = 0;
    puVar4 = local_c8;
    puVar5 = local_1c8;
    zeroCount = 0x10;
    do {
      *puVar5 = 0;
      *puVar4 = 0;
      puVar5[1] = 0;
      *(undefined4 *)(puVar4 + 1) = 0;
      puVar5 = puVar5 + 2;
      puVar4 = (undefined8 *)((int)puVar4 + 0xc);
      zeroCount = zeroCount + -1;
    } while (zeroCount != 0);
    render_bindNodeTransformA();
    render_uploadBoneMatrices(local_1c8,local_c8);
    render_setVec3Uniform5c(0x3f800000);
    render_setVec3Uniform58(0);
    local_1d8 = 0x3f800000;
    uStack_1d4 = 0x3f800000;
    local_1d0 = 0x3f800000;
    uStack_1cc = 0x3f800000;
    render_setUniform30(&local_1d8);
    fVar8 = (float10)security_cookie_guard_b();
    fVar9 = (float10)security_cookie_guard_a();
    zeroCount = *(int *)(self + 0x148);
    iVar3 = *(int *)(*(int *)(zeroCount + 0x38) + 0x170);
    iVar7 = *(int *)(*(int *)(zeroCount + 0x38) + 0x19c);
    camX = *(float *)(iVar7 + iVar3 * 8);
    depth = *(float *)(iVar7 + 4 + iVar3 * 8);
    invW = 1.0 / (*(float *)(zeroCount + 0x54) * camX + *(float *)(zeroCount + 100) * depth +
                   *(float *)(zeroCount + 0x84));
    modelName = *(char **)(self + 0x164);
    screenX = (float)fVar8 * 0.5 +
             invW * (*(float *)(zeroCount + 0x58) * depth + camX * *(float *)(zeroCount + 0x48) +
                      *(float *)(zeroCount + 0x78));
    camX = (float)fVar9 * 0.5 +
             invW * (*(float *)(zeroCount + 0x4c) * camX + *(float *)(zeroCount + 0x5c) * depth +
                      *(float *)(zeroCount + 0x7c));
    if (modelName == (char *)0x0) {
      zeroCount = *(int *)(self + 0x160);
      iVar3 = *(int *)(self + 0x168);
      iVar7 = *(int *)(zeroCount + 0x44);
      if (*(int *)(zeroCount + 0x44) < *(int *)(zeroCount + 0x48)) {
        iVar7 = *(int *)(zeroCount + 0x48);
      }
      uVar14 = 0;
      if (iVar7 < *(int *)(zeroCount + 0x4c)) {
        iVar7 = *(int *)(zeroCount + 0x4c);
      }
      fVar8 = (float10)security_cookie_guard_b(zeroCount,0);
      drawModelAtProjectedPos(screenX,camX,iVar3 + 0x800a1c,((float)fVar8 * 0.0006) / (float)iVar7,zeroCount,
                   uVar14);
    }
    else if (*modelName != '\0') {
      zeroCount = *(int *)(self + 0x168);
      uVar14 = 0;
      fVar8 = (float10)security_cookie_guard_b(modelName,0);
      drawBillboardModelRotated(screenX,camX,zeroCount + 0x800a1c,(float)fVar8 * 0.0006,modelName,uVar14);
    }
    piVar2 = *(int **)(*(int *)(self + 0x168) + 0x134);
    (**(code **)(*piVar2 + 0xe4))(piVar2,7,0);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




