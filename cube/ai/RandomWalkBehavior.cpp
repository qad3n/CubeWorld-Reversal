// RandomWalkBehavior (ai) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "RandomWalkBehavior.h"

/* cube::RandomWalkBehavior::ctor_0 @ 004dbf10 */

void cube::RandomWalkBehavior::ctor_0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  in_ECX[1] = 0;
  return;
}




/* cube::RandomWalkBehavior::vfunc_0 @ 004dbf20 */

void cube::RandomWalkBehavior::vfunc_0(int self,undefined4 param_2,int dt)

{
  int *piVar1;
  uint uVar2;
  int timer;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double len;
  float invLen;
  undefined8 uVar10;
  float z;
  int local_58;
  uint local_54;
  uint x;
  int local_4c;
  uint local_48;
  int yHi;
  int local_40;
  int iStack_3c;
  int local_38;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int dxTargetX;
  int local_24;
  int local_20;
  int local_1c;
  uint local_c;
  
  local_c = DAT_0076aa78 ^ (uint)&z;
  *(ushort *)(self + 0x124) = *(ushort *)(self + 0x124) & 0xffbf;
  piVar1 = (int *)(in_ECX + 4);
  *piVar1 = *piVar1 - dt;
  timer = *(int *)(in_ECX + 4);
  if (*piVar1 < 0) {
    timer = 0;
  }
  local_58 = self;
  *(int *)(in_ECX + 4) = timer;
  if (timer == 0) {
    x = *(uint *)(self + 0x10);
    yHi = *(int *)(self + 0x14);
    z = *(float *)(self + 0x1c);
    dxTargetX = x - *(uint *)(self + 0x1c0);
    local_24 = (yHi - *(int *)(self + 0x1c4)) -
               (uint)(x < *(uint *)(self + 0x1c0));
    local_54 = *(uint *)(self + 0x18);
    timer = local_54 - *(uint *)(self + 0x1c8);
    iVar7 = ((int)z - *(int *)(self + 0x1cc)) -
            (uint)(local_54 < *(uint *)(self + 0x1c8));
    local_4c = in_ECX;
    local_20 = timer;
    local_1c = iVar7;
    uVar10 = __allmul(dxTargetX,local_24,dxTargetX,local_24);
    uVar10 = __alldiv(uVar10,0x10000,0);
    iVar4 = (int)((ulonglong)uVar10 >> 0x20);
    local_48 = (uint)uVar10;
    uVar10 = __allmul(timer,iVar7,timer,iVar7);
    uVar10 = __alldiv(uVar10,0x10000,0);
    iVar7 = local_58;
    iVar5 = (int)((ulonglong)uVar10 >> 0x20);
    uVar2 = (uint)CARRY4(local_48,(uint)uVar10);
    timer = iVar4 + iVar5;
    iVar6 = timer + uVar2;
    if ((iVar6 < 0) ||
       ((iVar6 == 0 || SCARRY4(iVar4,iVar5) != SCARRY4(timer,uVar2) &&
        (local_48 + (uint)uVar10 < 0x640001)))) {
      timer = rand();
      z = ((float)timer * 2.0) / 32767.0 - 1.0;
      timer = rand();
      *(float *)(local_58 + 0x40) = z * 10.0;
      *(undefined4 *)(local_58 + 0x48) = 0;
      *(float *)(local_58 + 0x44) = (((float)timer * 2.0) / 32767.0 - 1.0) * 10.0;
      iVar7 = local_58;
    }
    else {
      local_40 = *(uint *)(local_58 + 0x1c0) - x;
      iStack_3c = (*(int *)(local_58 + 0x1c4) - yHi) -
                  (uint)(*(uint *)(local_58 + 0x1c0) < x);
      local_38 = *(uint *)(local_58 + 0x1c8) - local_54;
      iStack_34 = (*(int *)(local_58 + 0x1cc) - (int)z) -
                  (uint)(*(uint *)(local_58 + 0x1c8) < local_54);
      local_30 = *(uint *)(local_58 + 0x1d0) - *(uint *)(local_58 + 0x20);
      iStack_2c = (*(int *)(local_58 + 0x1d4) - *(int *)(local_58 + 0x24)) -
                  (uint)(*(uint *)(local_58 + 0x1d0) < *(uint *)(local_58 + 0x20));
      *(float *)(local_58 + 0x40) = (float)CONCAT44(iStack_3c,local_40) * 1.5258789e-05;
      z = (float)CONCAT44(iStack_2c,local_30);
      *(float *)(local_58 + 0x44) = (float)CONCAT44(iStack_34,local_38) * 1.5258789e-05;
      *(undefined4 *)(local_58 + 0x48) = 0;
      len = (double)(*(float *)(local_58 + 0x40) * *(float *)(local_58 + 0x40) +
                       *(float *)(local_58 + 0x44) * *(float *)(local_58 + 0x44) +
                      *(float *)(local_58 + 0x48) * *(float *)(local_58 + 0x48));
      libm_sse2_sqrt_precise();
      invLen = 1.0 / (float)len;
      *(float *)(iVar7 + 0x40) = invLen * *(float *)(iVar7 + 0x40) * 10.0;
      *(float *)(iVar7 + 0x44) = *(float *)(iVar7 + 0x44) * invLen * 10.0;
      *(float *)(iVar7 + 0x48) = *(float *)(iVar7 + 0x48) * invLen * 10.0;
    }
    timer = rand();
    *(int *)(local_4c + 4) = timer % 5000 + 3000;
    *(undefined1 *)(iVar7 + 0x68) = 0;
  }
  __security_check_cookie(local_c ^ (uint)&z);
  return;
}




/* cube::RandomWalkBehavior::vfunc_1 @ 004dc1e0 */

undefined4 * cube::RandomWalkBehavior::vfunc_1(void)

{
  undefined4 *obj;
  
  obj = operator_new(8);
  if (obj != (undefined4 *)0x0) {
    *obj = vftable;
    obj[1] = 0;
    return obj;
  }
  return (undefined4 *)0x0;
}




