// QuestText (entity) — server. 7 functions. Bodies = Ghidra pseudo-C.
#include "QuestText.h"

/* [AUDIT] proposed: QuestText_assignTree  (confidence: med)
 * purpose: Rebuilds map/set from another tree: copies node structure then recomputes leftmost/rightmost
 * vars: this=dest map; param_1=source root; +4=size
 */
/* Global::QuestText_assignTree @ 0041a670 */

void __thiscall QuestText_assignTree(void *this,int *root,undefined4 param_2)

{
  char cVar1;
  int head;
  int *node;
  int *child;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  head = *(int *)this;
  puVar7 = RBTree_copyRec(this,*(undefined4 **)(*root + 4),head,param_2);
  *(undefined4 **)(head + 4) = puVar7;
  node = *(int **)this;
  *(int *)((int)this + 4) = root[1];
  child = (int *)node[1];
  if (*(char *)((int)child + 0xd) != '\0') {
    *node = (int)node;
    *(int *)(*(int *)this + 8) = *(int *)this;
    return;
  }
  cVar1 = *(char *)(*child + 0xd);
  piVar6 = (int *)*child;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0xd);
    child = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *node = (int)child;
  head = *(int *)(*(int *)this + 4);
  iVar5 = *(int *)(head + 8);
  cVar1 = *(char *)(iVar5 + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0xd);
    head = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)this + 8) = head;
  return;
}




/* cube::QuestText::ctor_1 @ 0041ab90 */

undefined4 * __fastcall cube::QuestText::ctor_1(undefined4 *self)

{
  undefined4 obj;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  obj = MapNode_allocSentinel40();
  self[2] = obj;
  return self;
}




/* cube::QuestText::ctor_3 @ 0041ac90 */

void __fastcall cube::QuestText::ctor_3(undefined4 *self)

{
  uint uVar1;
  undefined4 *self_save;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054bcdb;
  local_10 = ExceptionList;
  uVar1 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  self_save = self;
  if ((undefined4 *)self[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[1])(1,uVar1);
  }
  local_8 = 0xffffffff;
  Tree_eraseRange_variant(self + 2,&self_save,*(int **)self[2],(int *)self[2]);
  operator_delete((void *)self[2]);
  ExceptionList = local_10;
  return;
}




/* cube::QuestText::vfunc_0 @ 0041ae70 */

undefined4 * __thiscall cube::QuestText::vfunc_0(QuestText *this,byte delete_flag)

{
  uint uVar1;
  QuestText *self_save;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054bd6b;
  local_10 = ExceptionList;
  uVar1 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  local_8 = 0;
  self_save = this;
  if (*(undefined4 **)(this + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 4))(1,uVar1);
  }
  local_8 = 0xffffffff;
  Tree_eraseRange_variant(this + 8,&self_save,(int *)**(int **)(this + 8),*(int **)(this + 8));
  operator_delete(*(void **)(this + 8));
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}




/* cube::QuestText::ctor_0 @ 00429380 */

undefined4 * __thiscall cube::QuestText::ctor_0(QuestText *this,undefined4 *src_node)

{
  undefined4 *self;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cb59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  self = std_map_allocRawNode_0x38((undefined4 *)this);
  *(undefined2 *)(self + 3) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (self + 4 != (undefined4 *)0x0) {
    u16string_moveConstruct(self + 4,src_node);
    self[10] = vftable;
    self[0xb] = src_node[7];
    local_8 = CONCAT31(local_8._1_3_,2);
    QuestText_container_copyCtor(self + 0xc,src_node + 8);
  }
  ExceptionList = local_10;
  return self;
}




/* [AUDIT] proposed: QuestText_container_copyCtor  (confidence: med)
 * purpose: Constructs empty container (41a060 head) then copies from param via 41a670; QuestText copy-ctor
 * vars: this[0]=head; this+4=size
 */
/* Global::QuestText_container_copyCtor @ 0042b0e0 */

undefined4 * __thiscall QuestText_container_copyCtor(void *this,int *src_str)

{
  undefined4 new_str;
  uint char_val;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cd98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  new_str = MapNode_allocSentinel40();
  *(undefined4 *)this = new_str;
  char_val = char_val & 0xffffff00;
  local_8 = 1;
  QuestText_assignTree(this,src_str,char_val);
  ExceptionList = local_10;
  return this;
}




/* cube::QuestText::ctor_2 @ 0042cc10 */

void __thiscall cube::QuestText::ctor_2(QuestText *this,ushort *key_str)

{
  ushort *found_node;
  ushort *key_ptr;
  uint cmp_result;
  undefined4 *temp_node;
  int *new_node;
  undefined4 local_54 [5];
  QuestText *self;
  void *key_copy [4];
  undefined4 local_2c;
  uint local_28;
  undefined **local_24;
  undefined4 local_20;
  undefined1 local_1c [8];
  uint security_cookie;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d150;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  self = this;
  found_node = (ushort *)std_map_lowerBound_strKey(this,key_str);
  if (found_node != *(ushort **)this) {
    key_ptr = found_node + 8;
    if (7 < *(uint *)(found_node + 0x12)) {
      key_ptr = *(ushort **)key_ptr;
    }
    cmp_result = wstring_compareSubstr(key_str,0,*(uint *)(key_str + 8),key_ptr,*(uint *)(found_node + 0x10));
    if (-1 < (int)cmp_result) goto LAB_0042cd13;
  }
  temp_node = ctor_1(local_54);
  local_8 = 0;
  u16string_moveConstruct(key_copy,(undefined4 *)key_str);
  local_24 = vftable;
  local_20 = temp_node[1];
  local_8._0_1_ = 1;
  QuestText_container_copyCtor(local_1c,temp_node + 2);
  local_8._0_1_ = 2;
  new_node = ctor_0(self,key_copy);
  std_map_insertHint_strKey_QuestText(self,&self,found_node,(ushort *)(new_node + 4),new_node);
  local_8 = CONCAT31(local_8._1_3_,3);
  ctor_3(&local_24);
  if (7 < local_28) {
    operator_delete(key_copy[0]);
  }
  local_28 = 7;
  local_2c = 0;
  key_copy[0] = (void *)((uint)key_copy[0] & 0xffff0000);
  local_8 = 0xffffffff;
  ctor_3(local_54);
LAB_0042cd13:
  ExceptionList = local_10;
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




