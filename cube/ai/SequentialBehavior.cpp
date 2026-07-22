// SequentialBehavior (ai) — cube. 6 functions. Bodies = Ghidra pseudo-C.
#include "SequentialBehavior.h"

/* cube::SequentialBehavior::ctor_0 @ 004dc200 */

undefined4 * cube::SequentialBehavior::ctor_0(int source)

{
  int *piVar1;
  uint uVar2;
  int list;
  int inserted;
  undefined4 *self;
  int *srcNode;
  undefined4 copy;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e907b;
  local_10 = ExceptionList;
  uVar2 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = self + 1;
  *self = vftable;
  *piVar1 = 0;
  self[2] = 0;
  list = list_buyNode_0c(0,0);
  *piVar1 = list;
  local_8 = 0;
  srcNode = (int *)**(int **)(source + 4);
  if (srcNode != *(int **)(source + 4)) {
    do {
      copy = (**(code **)(*(int *)srcNode[2] + 4))(uVar2);
      list = *piVar1;
      inserted = IntMap_SetScalar(list,*(undefined4 *)(list + 4),&copy);
      if (self[2] == 0x15555554) {
        std::_Xlength_error("list<T> too long");
      }
      self[2] = self[2] + 1;
      *(int *)(list + 4) = inserted;
      **(int **)(inserted + 4) = inserted;
      srcNode = (int *)*srcNode;
    } while (srcNode != (int *)*(int *)(source + 4));
  }
  ExceptionList = local_10;
  return self;
}




/* cube::SequentialBehavior::ctor_1 @ 004dc2d0 */

void cube::SequentialBehavior::ctor_1(void)

{
  undefined4 list;
  undefined4 *self;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  list = list_buyNode_0c(0,0);
  self[1] = list;
  return;
}




/* cube::SequentialBehavior::ctor_2 @ 004dc300 */

void cube::SequentialBehavior::ctor_2(void)

{
  int *node;
  undefined4 *listHead;
  void *firstNode;
  undefined4 *self;
  
  *self = vftable;
  node = *(int **)self[1];
  if (node != (int *)self[1]) {
    operator_delete((void *)node[2]);
  }
  listHead = (undefined4 *)self[1];
  firstNode = (void *)*listHead;
  *listHead = listHead;
  *(undefined4 *)(self[1] + 4) = self[1];
  self[2] = 0;
  if (firstNode != (void *)self[1]) {
    operator_delete(firstNode);
  }
  operator_delete((void *)self[1]);
}




/* cube::SequentialBehavior::vfunc_2 @ 004dc360 */

void cube::SequentialBehavior::vfunc_2(byte param_1)

{
  void *in_ECX;
  
  ctor_2();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* cube::SequentialBehavior::vfunc_0 @ 004dc390 */

undefined4
cube::SequentialBehavior::vfunc_0
          (int entity,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char handled;
  int self;
  int *behaviorNode;
  
  behaviorNode = (int *)**(int **)(self + 4);
  if (behaviorNode != *(int **)(self + 4)) {
    do {
      handled = (*(code *)**(undefined4 **)behaviorNode[2])(entity,param_2,param_3,param_4);
      if (handled != '\0') {
        return 1;
      }
      behaviorNode = (int *)*behaviorNode;
    } while (behaviorNode != (int *)*(int *)(self + 4));
  }
  *(undefined4 *)(entity + 0x40) = 0;
  *(undefined4 *)(entity + 0x44) = 0;
  *(undefined4 *)(entity + 0x48) = 0;
  return 0;
}




/* cube::SequentialBehavior::vfunc_1 @ 004dc400 */

undefined4 cube::SequentialBehavior::vfunc_1(void)

{
  void *mem;
  undefined4 obj;
  undefined4 self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f661b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  mem = operator_new(0xc);
  local_8 = 0;
  if (mem != (void *)0x0) {
    obj = ctor_0(self);
    ExceptionList = local_10;
    return obj;
  }
  ExceptionList = local_10;
  return 0;
}




