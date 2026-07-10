// LookAtPlayerBehavior (ai) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "LookAtPlayerBehavior.h"

/* cube::LookAtPlayerBehavior::ctor_0 @ 004c8130 */

void cube::LookAtPlayerBehavior::ctor_0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  return;
}




/* cube::LookAtPlayerBehavior::vfunc_0 @ 004c8140 */

void cube::LookAtPlayerBehavior::vfunc_0(int self,int region)

{
  char cVar1;
  undefined4 *node;
  int entity;
  undefined4 *nextNode;
  uint oy;
  int oyHi;
  uint oz;
  undefined4 *parentNode;
  uint cookie;
  int nearestEntity;
  float distSq;
  float nearestDistSq;
  undefined8 dx;
  undefined8 dy;
  undefined8 dz;
  
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  nearestDistSq = 64.0;
  node = (undefined4 *)**(undefined4 **)(region + 4);
  nearestEntity = 0;
  while (node != *(undefined4 **)(region + 4)) {
    entity = node[6];
    if (((entity != 0) && (*(char *)(entity + 0x60) == '\0')) && (0.0 <= *(float *)(entity + 0x16c))) {
      dx._0_4_ = (uint)*(undefined8 *)(entity + 0x10);
      dx._4_4_ = (int)((ulonglong)*(undefined8 *)(entity + 0x10) >> 0x20);
      dx = CONCAT44((dx._4_4_ - *(int *)(self + 0x14)) -
                          (uint)((uint)dx < *(uint *)(self + 0x10)),
                          (uint)dx - *(uint *)(self + 0x10));
      dy._0_4_ = (uint)*(undefined8 *)(entity + 0x18);
      dy._4_4_ = (int)((ulonglong)*(undefined8 *)(entity + 0x18) >> 0x20);
      dy = CONCAT44((dy._4_4_ - *(int *)(self + 0x1c)) -
                          (uint)((uint)dy < *(uint *)(self + 0x18)),
                          (uint)dy - *(uint *)(self + 0x18));
      dz._0_4_ = (uint)*(undefined8 *)(entity + 0x20);
      dz._4_4_ = (int)((ulonglong)*(undefined8 *)(entity + 0x20) >> 0x20);
      dz = CONCAT44((dz._4_4_ - *(int *)(self + 0x24)) -
                          (uint)((uint)dz < *(uint *)(self + 0x20)),
                          (uint)dz - *(uint *)(self + 0x20));
      distSq = (float)dy * 1.5258789e-05 * (float)dy * 1.5258789e-05 +
               (float)dx * 1.5258789e-05 * (float)dx * 1.5258789e-05 +
               (float)dz * 1.5258789e-05 * (float)dz * 1.5258789e-05;
      if (distSq < nearestDistSq) {
        nearestEntity = entity;
        nearestDistSq = distSq;
      }
    }
    if (*(char *)((int)node + 0xd) == '\0') {
      nextNode = (undefined4 *)node[2];
      if (*(char *)((int)nextNode + 0xd) == '\0') {
        cVar1 = *(char *)((int)*nextNode + 0xd);
        node = nextNode;
        nextNode = (undefined4 *)*nextNode;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*nextNode + 0xd);
          node = nextNode;
          nextNode = (undefined4 *)*nextNode;
        }
      }
      else {
        cVar1 = *(char *)((int)node[1] + 0xd);
        parentNode = (undefined4 *)node[1];
        nextNode = node;
        while ((node = parentNode, cVar1 == '\0' && (nextNode == (undefined4 *)node[2]))) {
          cVar1 = *(char *)((int)node[1] + 0xd);
          parentNode = (undefined4 *)node[1];
          nextNode = node;
        }
      }
    }
  }
  *(ushort *)(self + 0x124) = *(ushort *)(self + 0x124) & 0xfffb;
  if (((nearestEntity != 0) && (*(char *)(self + 0x68) != 'S')) && (*(char *)(self + 0x68) != 'T')) {
    *(ushort *)(self + 0x124) = *(ushort *)(self + 0x124) | 4;
    entity = *(int *)(nearestEntity + 0x24);
    oy = *(uint *)(nearestEntity + 0x18);
    oyHi = *(int *)(nearestEntity + 0x1c);
    oz = *(uint *)(nearestEntity + 0x20);
    *(float *)(self + 0x160) =
         (float)CONCAT44((*(int *)(nearestEntity + 0x14) - *(int *)(self + 0x14)) -
                         (uint)(*(uint *)(nearestEntity + 0x10) < *(uint *)(self + 0x10)),
                         *(uint *)(nearestEntity + 0x10) - *(uint *)(self + 0x10)) * 1.5258789e-05;
    *(float *)(self + 0x164) =
         (float)CONCAT44((oyHi - *(int *)(self + 0x1c)) -
                         (uint)(oy < *(uint *)(self + 0x18)),oy - *(uint *)(self + 0x18)
                        ) * 1.5258789e-05;
    *(float *)(self + 0x168) =
         (float)CONCAT44((entity - *(int *)(self + 0x24)) -
                         (uint)(oz < *(uint *)(self + 0x20)),oz - *(uint *)(self + 0x20)
                        ) * 1.5258789e-05;
    *(undefined4 *)(self + 0x40) = 0;
    *(undefined4 *)(self + 0x44) = 0;
    *(undefined4 *)(self + 0x48) = 0;
    GameController_clearContainers();
    __security_check_cookie(cookie ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::LookAtPlayerBehavior::vfunc_1 @ 004c83d0 */

undefined4 * cube::LookAtPlayerBehavior::vfunc_1(void)

{
  undefined4 *obj;
  
  obj = operator_new(4);
  if (obj != (undefined4 *)0x0) {
    *obj = vftable;
    return obj;
  }
  return (undefined4 *)0x0;
}




