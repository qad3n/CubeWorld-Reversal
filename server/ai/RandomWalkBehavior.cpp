// RandomWalkBehavior (ai) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "RandomWalkBehavior.h"

/* cube::RandomWalkBehavior::ctor_0 @ 0041cb90 */

undefined4 * __fastcall cube::RandomWalkBehavior::ctor_0(undefined4 *self)

{
  *self = vftable;
  self[1] = 0;
  return self;
}




/* cube::RandomWalkBehavior::vfunc_0 @ 0041cbb0 */

void __thiscall
cube::RandomWalkBehavior::vfunc_0
          (RandomWalkBehavior *this,int creature,undefined4 param_2,int dt)

{
  RandomWalkBehavior *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  float fVar9;
  longlong lVar10;
  undefined8 uVar11;
  float local_5c;
  int creature_p;
  uint local_54;
  uint pos_x;
  RandomWalkBehavior *self;
  uint local_48;
  int local_44;
  int local_40;
  int iStack_3c;
  int local_38;
  int iStack_34;
  int local_30;
  int iStack_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_c;
  
  local_c = DAT_00583cc8 ^ (uint)&local_5c;
  *(ushort *)(creature + 0x124) = *(ushort *)(creature + 0x124) & 0xffbf;
  pRVar1 = this + 4;
  *(int *)pRVar1 = *(int *)pRVar1 - dt;
  iVar2 = *(int *)(this + 4);
  if (*(int *)pRVar1 < 0) {
    iVar2 = 0;
  }
  creature_p = creature;
  *(int *)(this + 4) = iVar2;
  self = this;
  if (iVar2 == 0) {
    pos_x = *(uint *)(creature + 0x10);
    local_44 = *(int *)(creature + 0x14);
    local_5c = *(float *)(creature + 0x1c);
    local_28 = pos_x - *(uint *)(creature + 0x1c0);
    local_24 = (local_44 - *(int *)(creature + 0x1c4)) -
               (uint)(pos_x < *(uint *)(creature + 0x1c0));
    local_54 = *(uint *)(creature + 0x18);
    uVar5 = local_54 - *(uint *)(creature + 0x1c8);
    iVar2 = ((int)local_5c - *(int *)(creature + 0x1cc)) -
            (uint)(local_54 < *(uint *)(creature + 0x1c8));
    local_20 = uVar5;
    local_1c = iVar2;
    lVar10 = __allmul(local_28,local_24,local_28,local_24);
    uVar11 = __alldiv((uint)lVar10,(uint)((ulonglong)lVar10 >> 0x20),0x10000,0);
    iVar3 = (int)((ulonglong)uVar11 >> 0x20);
    local_48 = (uint)uVar11;
    lVar10 = __allmul(uVar5,iVar2,uVar5,iVar2);
    uVar11 = __alldiv((uint)lVar10,(uint)((ulonglong)lVar10 >> 0x20),0x10000,0);
    iVar6 = creature_p;
    iVar4 = (int)((ulonglong)uVar11 >> 0x20);
    uVar5 = (uint)CARRY4(local_48,(uint)uVar11);
    iVar2 = iVar3 + iVar4;
    iVar7 = iVar2 + uVar5;
    if ((iVar7 < 0) ||
       ((iVar7 == 0 || SCARRY4(iVar3,iVar4) != SCARRY4(iVar2,uVar5) &&
        (local_48 + (uint)uVar11 < 0x640001)))) {
      iVar2 = rand();
      local_5c = ((float)iVar2 * 2.0) / 32767.0 - 1.0;
      iVar2 = rand();
      *(float *)(creature_p + 0x40) = local_5c * 10.0;
      *(undefined4 *)(creature_p + 0x48) = 0;
      *(float *)(creature_p + 0x44) = (((float)iVar2 * 2.0) / 32767.0 - 1.0) * 10.0;
      iVar6 = creature_p;
    }
    else {
      local_40 = *(uint *)(creature_p + 0x1c0) - pos_x;
      iStack_3c = (*(int *)(creature_p + 0x1c4) - local_44) -
                  (uint)(*(uint *)(creature_p + 0x1c0) < pos_x);
      local_38 = *(uint *)(creature_p + 0x1c8) - local_54;
      iStack_34 = (*(int *)(creature_p + 0x1cc) - (int)local_5c) -
                  (uint)(*(uint *)(creature_p + 0x1c8) < local_54);
      local_30 = *(uint *)(creature_p + 0x1d0) - *(uint *)(creature_p + 0x20);
      iStack_2c = (*(int *)(creature_p + 0x1d4) - *(int *)(creature_p + 0x24)) -
                  (uint)(*(uint *)(creature_p + 0x1d0) < *(uint *)(creature_p + 0x20));
      *(float *)(creature_p + 0x40) = (float)CONCAT44(iStack_3c,local_40) * 1.5258789e-05;
      local_5c = (float)CONCAT44(iStack_2c,local_30);
      *(float *)(creature_p + 0x44) = (float)CONCAT44(iStack_34,local_38) * 1.5258789e-05;
      *(undefined4 *)(creature_p + 0x48) = 0;
      dVar8 = libm_sse2_sqrt_precise
                        ((double)(*(float *)(creature_p + 0x40) * *(float *)(creature_p + 0x40) +
                                  *(float *)(creature_p + 0x44) * *(float *)(creature_p + 0x44) +
                                 *(float *)(creature_p + 0x48) * *(float *)(creature_p + 0x48)));
      fVar9 = 1.0 / (float)dVar8;
      *(float *)(iVar6 + 0x40) = fVar9 * *(float *)(iVar6 + 0x40) * 10.0;
      *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * fVar9 * 10.0;
      *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * fVar9 * 10.0;
    }
    iVar2 = rand();
    *(int *)(self + 4) = iVar2 % 5000 + 3000;
    *(undefined1 *)(iVar6 + 0x68) = 0;
  }
  __security_check_cookie(local_c ^ (uint)&local_5c);
  return;
}




/* cube::RandomWalkBehavior::vfunc_1 @ 0041ce70 */

undefined4 * cube::RandomWalkBehavior::vfunc_1(void)

{
  undefined4 *new_obj;
  
  new_obj = operator_new(8);
  if (new_obj != (undefined4 *)0x0) {
    *new_obj = vftable;
    new_obj[1] = 0;
    return new_obj;
  }
  return (undefined4 *)0x0;
}




