// Zone (world) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "Zone.h"

/* cube::Zone::ctor_0 @ 00548b60 */

undefined4 * __fastcall cube::Zone::ctor_0(undefined4 *self)

{
  undefined4 list_obj;
  undefined4 *field_array;
  undefined4 *fields;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 state;
  
  state = 0xffffffff;
  puStack_c = &LAB_00556565;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  list_obj = std_List_node_alloc_0x48((undefined4 *)0x0,(undefined4 *)0x0);
  self[1] = list_obj;
  self[3] = 0;
  self[4] = 0;
  self[5] = 0;
  self[6] = 0;
  self[7] = 0;
  self[8] = 0;
  self[9] = 0;
  self[10] = 0;
  self[0xb] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0;
  self[0xf] = 0;
  self[0x10] = 0;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  self[0x1a] = 0;
  self[0x1b] = 0;
  self[0x1c] = 0;
  *(undefined2 *)(self + 0x1d) = 1;
  *(undefined1 *)((int)self + 0x76) = 0;
  self[0x1e] = 0;
  self[0x1f] = 0;
  self[0x20] = 1;
  *(undefined1 *)(self + 0x21) = 0;
  self[0x22] = 0;
  self[0x23] = 0;
  self[0x24] = 0;
  self[0x25] = 0;
  self[0x26] = 0;
  self[0x27] = 0;
  state._0_1_ = 10;
  state._1_3_ = 0;
  self[0x28] = 0;
  self[0x29] = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(self + 0x2c),0x80000400);
  field_array = (undefined4 *)operator_new_wrapper(0x200004);
  state._0_1_ = 0xb;
  if (field_array == (undefined4 *)0x0) {
    fields = (undefined4 *)0x0;
  }
  else {
    fields = field_array + 1;
    *field_array = 0x10000;
    _eh_vector_constructor_iterator_
              (fields,0x20,0x10000,(_func_void_void_ptr *)&LAB_004133c0,Field::ctor_0);
  }
  state._0_1_ = 10;
  self[0x2a] = fields;
  field_array = (undefined4 *)operator_new_wrapper(0x2004);
  state = CONCAT31(state._1_3_,0xc);
  if (field_array != (undefined4 *)0x0) {
    *field_array = 0x400;
    _eh_vector_constructor_iterator_(field_array + 1,8,0x400,lib_fn_548b40,std_list_Tidy);
    self[0x2b] = field_array + 1;
    ExceptionList = local_10;
    return self;
  }
  self[0x2b] = 0;
  ExceptionList = local_10;
  return self;
}




/* cube::Zone::ctor_1 @ 00548e00 */

void __fastcall cube::Zone::ctor_1(undefined4 *self)

{
  undefined4 *member;
  void *pvVar2;
  uint security_cookie;
  int *node;
  int *iter;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *self_ptr;
  undefined4 *elem;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_005565ff;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  member = (undefined4 *)self[0x2a];
  local_8 = 10;
  self_ptr = self;
  if (member != (undefined4 *)0x0) {
    if (member[-1] == 0) {
      operator_delete__(member + -1);
    }
    else {
      (**(code **)*member)(3,security_cookie);
    }
  }
  pvVar2 = (void *)self[0x2b];
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar2,8,*(int *)((int)pvVar2 + -4),std_list_Tidy);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  iter = (int *)self[6];
  if (iter != (int *)self[7]) {
    do {
      if ((undefined4 *)*iter != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*iter)(1);
      }
      iter = iter + 1;
    } while (iter != (int *)self[7]);
  }
  iter = (int *)self[9];
  if (iter != (int *)self[10]) {
    do {
      elem = (undefined4 *)*iter;
      if (elem != (undefined4 *)0x0) {
        member = elem + 0x1e;
        std_map_erase_range_B(member,&local_20,*(int **)*member,(int *)*member);
        operator_delete((void *)*member);
        operator_delete(elem);
      }
      iter = iter + 1;
    } while (iter != (int *)self[10]);
  }
  iter = (int *)self[0x22];
  if (iter != (int *)self[0x23]) {
    do {
      if ((undefined4 *)*iter != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*iter)(1);
      }
      iter = iter + 1;
    } while (iter != (int *)self[0x23]);
  }
  iter = (int *)self[0x25];
  if (iter != (int *)self[0x26]) {
    do {
      elem = (undefined4 *)*iter;
      if (elem != (undefined4 *)0x0) {
        member = elem + 2;
        SpeechMap_eraseRange(member,&local_20,*(int **)*member,(int *)*member);
        operator_delete((void *)*member);
        member = elem;
        Tree_eraseRange_variant(elem,&local_24,*(int **)*elem,(int *)*elem);
        operator_delete((void *)*member);
        operator_delete(member);
      }
      iter = iter + 1;
    } while (iter != (int *)self[0x26]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(self + 0x2c));
  if ((void *)self[0x25] != (void *)0x0) {
    operator_delete((void *)self[0x25]);
    self[0x25] = 0;
    self[0x26] = 0;
    self[0x27] = 0;
  }
  if ((void *)self[0x22] != (void *)0x0) {
    operator_delete((void *)self[0x22]);
    self[0x22] = 0;
    self[0x23] = 0;
    self[0x24] = 0;
  }
  if ((void *)self[0x1a] != (void *)0x0) {
    operator_delete((void *)self[0x1a]);
    self[0x1a] = 0;
    self[0x1b] = 0;
    self[0x1c] = 0;
  }
  if ((void *)self[0x15] != (void *)0x0) {
    operator_delete((void *)self[0x15]);
    self[0x15] = 0;
    self[0x16] = 0;
    self[0x17] = 0;
  }
  if ((void *)self[0x12] != (void *)0x0) {
    operator_delete((void *)self[0x12]);
    self[0x12] = 0;
    self[0x13] = 0;
    self[0x14] = 0;
  }
  if ((void *)self[0xf] != (void *)0x0) {
    operator_delete((void *)self[0xf]);
    self[0xf] = 0;
    self[0x10] = 0;
    self[0x11] = 0;
  }
  if ((void *)self[0xc] != (void *)0x0) {
    operator_delete((void *)self[0xc]);
    self[0xc] = 0;
    self[0xd] = 0;
    self[0xe] = 0;
  }
  if ((void *)self[9] != (void *)0x0) {
    operator_delete((void *)self[9]);
    self[9] = 0;
    self[10] = 0;
    self[0xb] = 0;
  }
  if ((void *)self[6] != (void *)0x0) {
    operator_delete((void *)self[6]);
    self[6] = 0;
    self[7] = 0;
    self[8] = 0;
  }
  if ((undefined4 *)self[3] != (undefined4 *)0x0) {
    std_vector_of_vector_dtor((undefined4 *)self[3],(undefined4 *)self[4]);
    operator_delete((void *)self[3]);
    self[3] = 0;
    self[4] = 0;
    self[5] = 0;
  }
  iter = (int *)self[1];
  node = (int *)*iter;
  *iter = (int)iter;
  *(undefined4 *)(self[1] + 4) = self[1];
  self[2] = 0;
  if (node != (int *)self[1]) {
    do {
      iter = (int *)*node;
      operator_delete(node);
      node = iter;
    } while (iter != (int *)self[1]);
  }
  operator_delete((void *)self[1]);
  ExceptionList = local_10;
  return;
}




/* cube::Zone::vfunc_0 @ 005491d0 */

undefined4 * __thiscall cube::Zone::vfunc_0(Zone *this,byte delete_flag)

{
  ctor_1((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




