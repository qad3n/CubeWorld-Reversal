// SequentialBehavior (ai) — server. 6 functions. Bodies = Ghidra pseudo-C.
#include "SequentialBehavior.h"

/* cube::SequentialBehavior::ctor_0 @ 0041cef0 */

undefined4 * __thiscall cube::SequentialBehavior::ctor_0(SequentialBehavior *this,int src)

{
  SequentialBehavior *pSVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int new_node;
  int *behavior;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054be8b;
  local_10 = ExceptionList;
  uVar3 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pSVar1 = this + 4;
  *(undefined ***)this = vftable;
  *(undefined4 *)pSVar1 = 0;
  *(undefined4 *)(this + 8) = 0;
  uVar4 = std_List_node_alloc_0xc((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)pSVar1 = uVar4;
  local_8 = 0;
  behavior = (int *)**(int **)(src + 4);
  if (behavior != *(int **)(src + 4)) {
    do {
      local_14 = (**(code **)(*(int *)behavior[2] + 4))(uVar3);
      puVar2 = *(undefined4 **)pSVar1;
      new_node = std_list_insertNode1(puVar2,(undefined4 *)puVar2[1],&local_14);
      if (*(int *)(this + 8) == 0x15555554) {
        std::_Xlength_error("list<T> too long");
      }
      *(int *)(this + 8) = *(int *)(this + 8) + 1;
      puVar2[1] = new_node;
      **(int **)(new_node + 4) = new_node;
      behavior = (int *)*behavior;
    } while (behavior != (int *)*(int *)(src + 4));
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}




/* cube::SequentialBehavior::ctor_1 @ 0041cfc0 */

undefined4 * __fastcall cube::SequentialBehavior::ctor_1(undefined4 *self)

{
  undefined4 list;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  list = std_List_node_alloc_0xc((undefined4 *)0x0,(undefined4 *)0x0);
  self[1] = list;
  return self;
}




/* cube::SequentialBehavior::ctor_2 @ 0041cff0 */

void __fastcall cube::SequentialBehavior::ctor_2(undefined4 *self)

{
  int *next;
  int *node;
  
  *self = vftable;
  node = *(int **)self[1];
  if (node != (int *)self[1]) {
    do {
      operator_delete((void *)node[2]);
      node = (int *)*node;
    } while (node != (int *)self[1]);
  }
  node = (int *)self[1];
  next = (int *)*node;
  *node = (int)node;
  *(undefined4 *)(self[1] + 4) = self[1];
  self[2] = 0;
  if (next != (int *)self[1]) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)self[1]);
  }
  operator_delete((void *)self[1]);
  return;
}




/* cube::SequentialBehavior::vfunc_2 @ 0041d050 */

undefined4 * __thiscall cube::SequentialBehavior::vfunc_2(SequentialBehavior *this,byte delete_flag)

{
  ctor_2((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




/* cube::SequentialBehavior::vfunc_0 @ 0041d080 */

uint __thiscall
cube::SequentialBehavior::vfunc_0
          (SequentialBehavior *this,int creature,undefined4 param_2,undefined4 param_3,
          undefined4 param_4)

{
  int *list;
  int *node;
  
  list = *(int **)(this + 4);
  node = (int *)*list;
  if (node != list) {
    do {
      list = (int *)(*(code *)**(undefined4 **)node[2])(creature,param_2,param_3,param_4);
      if ((char)list != '\0') {
        return CONCAT31((int3)((uint)list >> 8),1);
      }
      node = (int *)*node;
    } while (node != (int *)*(int *)(this + 4));
  }
  *(undefined4 *)(creature + 0x40) = 0;
  *(undefined4 *)(creature + 0x44) = 0;
  *(undefined4 *)(creature + 0x48) = 0;
  return (uint)list & 0xffffff00;
}




/* cube::SequentialBehavior::vfunc_1 @ 0041d0f0 */

undefined4 * __fastcall cube::SequentialBehavior::vfunc_1(int src)

{
  SequentialBehavior *this;
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bebb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = operator_new(0xc);
  local_8 = 0;
  if (this != (SequentialBehavior *)0x0) {
    puVar1 = ctor_0(this,src);
    ExceptionList = local_10;
    return puVar1;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}




