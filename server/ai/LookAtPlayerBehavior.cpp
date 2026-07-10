// LookAtPlayerBehavior (ai) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "LookAtPlayerBehavior.h"

/* cube::LookAtPlayerBehavior::ctor_0 @ 00414720 */

undefined4 * __fastcall cube::LookAtPlayerBehavior::ctor_0(undefined4 *self)

{
  *self = vftable;
  return self;
}




/* cube::LookAtPlayerBehavior::vfunc_0 @ 00414730 */

void cube::LookAtPlayerBehavior::vfunc_0(int creature,int world)

{
  char cVar1;
  undefined4 *puVar2;
  int entity;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int closest;
  float dist;
  float best_dist;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar9 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  best_dist = 64.0;
  puVar2 = (undefined4 *)**(undefined4 **)(world + 4);
  closest = 0;
  while (puVar2 != *(undefined4 **)(world + 4)) {
    entity = puVar2[6];
    if (((entity != 0) && (*(char *)(entity + 0x60) == '\0')) && (0.0 <= *(float *)(entity + 0x16c))) {
      local_20._0_4_ = (uint)*(undefined8 *)(entity + 0x10);
      local_20._4_4_ = (int)((ulonglong)*(undefined8 *)(entity + 0x10) >> 0x20);
      local_20 = CONCAT44((local_20._4_4_ - *(int *)(creature + 0x14)) -
                          (uint)((uint)local_20 < *(uint *)(creature + 0x10)),
                          (uint)local_20 - *(uint *)(creature + 0x10));
      local_18._0_4_ = (uint)*(undefined8 *)(entity + 0x18);
      local_18._4_4_ = (int)((ulonglong)*(undefined8 *)(entity + 0x18) >> 0x20);
      local_18 = CONCAT44((local_18._4_4_ - *(int *)(creature + 0x1c)) -
                          (uint)((uint)local_18 < *(uint *)(creature + 0x18)),
                          (uint)local_18 - *(uint *)(creature + 0x18));
      local_10._0_4_ = (uint)*(undefined8 *)(entity + 0x20);
      local_10._4_4_ = (int)((ulonglong)*(undefined8 *)(entity + 0x20) >> 0x20);
      local_10 = CONCAT44((local_10._4_4_ - *(int *)(creature + 0x24)) -
                          (uint)((uint)local_10 < *(uint *)(creature + 0x20)),
                          (uint)local_10 - *(uint *)(creature + 0x20));
      dist = (float)local_18 * 1.5258789e-05 * (float)local_18 * 1.5258789e-05 +
               (float)local_20 * 1.5258789e-05 * (float)local_20 * 1.5258789e-05 +
               (float)local_10 * 1.5258789e-05 * (float)local_10 * 1.5258789e-05;
      if (dist < best_dist) {
        closest = entity;
        best_dist = dist;
      }
    }
    if (*(char *)((int)puVar2 + 0xd) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0xd) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0xd);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0xd);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0xd);
        puVar8 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar8, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0xd);
          puVar8 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  *(ushort *)(creature + 0x124) = *(ushort *)(creature + 0x124) & 0xfffb;
  if (((closest != 0) && (*(char *)(creature + 0x68) != 'S')) && (*(char *)(creature + 0x68) != 'T')) {
    *(ushort *)(creature + 0x124) = *(ushort *)(creature + 0x124) | 4;
    entity = *(int *)(closest + 0x24);
    uVar5 = *(uint *)(closest + 0x18);
    iVar6 = *(int *)(closest + 0x1c);
    uVar7 = *(uint *)(closest + 0x20);
    *(float *)(creature + 0x160) =
         (float)CONCAT44((*(int *)(closest + 0x14) - *(int *)(creature + 0x14)) -
                         (uint)(*(uint *)(closest + 0x10) < *(uint *)(creature + 0x10)),
                         *(uint *)(closest + 0x10) - *(uint *)(creature + 0x10)) * 1.5258789e-05;
    *(float *)(creature + 0x164) =
         (float)CONCAT44((iVar6 - *(int *)(creature + 0x1c)) -
                         (uint)(uVar5 < *(uint *)(creature + 0x18)),uVar5 - *(uint *)(creature + 0x18)
                        ) * 1.5258789e-05;
    *(float *)(creature + 0x168) =
         (float)CONCAT44((entity - *(int *)(creature + 0x24)) -
                         (uint)(uVar7 < *(uint *)(creature + 0x20)),uVar7 - *(uint *)(creature + 0x20)
                        ) * 1.5258789e-05;
    *(undefined4 *)(creature + 0x40) = 0;
    *(undefined4 *)(creature + 0x44) = 0;
    *(undefined4 *)(creature + 0x48) = 0;
    World_clearContainers(creature);
    __security_check_cookie(uVar9 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(uVar9 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::LookAtPlayerBehavior::vfunc_1 @ 004149c0 */

undefined4 * cube::LookAtPlayerBehavior::vfunc_1(void)

{
  undefined4 *new_obj;
  
  new_obj = operator_new(4);
  if (new_obj != (undefined4 *)0x0) {
    *new_obj = vftable;
    return new_obj;
  }
  return (undefined4 *)0x0;
}




