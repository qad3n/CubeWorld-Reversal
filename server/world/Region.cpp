// Region (world) — server. 4 functions. Bodies = Ghidra pseudo-C.
#include "Region.h"

/* cube::Region::ctor_0 @ 004f7570 */

undefined4 * __fastcall cube::Region::ctor_0(undefined4 *self)

{
  undefined4 uVar1;
  int i;
  undefined4 *field_ptr;
  int cell_ptr;
  
  *self = vftable;
  *(undefined1 *)(self + 2) = 1;
  self[3] = 1;
  self[4] = 0;
  self[5] = 0;
  i = 0xfff;
  cell_ptr = (int)self + 0x1a;
  do {
    i = i + -1;
    *(undefined4 *)(cell_ptr + -2) = 0;
    *(undefined4 *)(cell_ptr + 2) = 0;
    *(undefined4 *)(cell_ptr + 6) = 1;
    *(undefined1 *)(cell_ptr + 10) = 0;
    cell_ptr = cell_ptr + 0x10;
  } while (-1 < i);
  field_ptr = self + 0x5006;
  cell_ptr = 0x3f;
  do {
    Region_ctor(field_ptr);
    field_ptr = field_ptr + 0x1a;
    cell_ptr = cell_ptr + -1;
  } while (-1 < cell_ptr);
  *(undefined1 *)(self + 0x5686) = 0;
  self[0x5687] = 0;
  self[0x5688] = 0;
  uVar1 = std_map_makeHeader_0x1c();
  self[0x5687] = uVar1;
  field_ptr = self + 0x4006;
  for (cell_ptr = 0x1000; cell_ptr != 0; cell_ptr = cell_ptr + -1) {
    *field_ptr = 0;
    field_ptr = field_ptr + 1;
  }
  return self;
}




/* [AUDIT] proposed: Region::ctor  (confidence: med)
 * purpose: Zero-initializes a ~0x5c-byte Region struct; sets field[9]=1 as only non-zero default
 * vars: self[9]=1 default flag
 */
/* Global::Region_ctor @ 004f7660 */

undefined4 * __fastcall Region_ctor(undefined4 *field)

{
  *field = 0;
  field[1] = 0;
  field[2] = 0;
  field[3] = 0;
  field[4] = 0;
  field[5] = 0;
  field[6] = 0;
  field[7] = 0;
  field[8] = 0;
  field[9] = 1;
  field[10] = 0;
  field[0xb] = 0;
  field[0xc] = 0;
  field[0xd] = 0;
  field[0xe] = 0;
  field[0xf] = 0;
  *(undefined2 *)(field + 0x10) = 0;
  field[0x11] = 0;
  field[0x12] = 0;
  field[0x13] = 0;
  field[0x14] = 0;
  field[0x15] = 0;
  field[0x16] = 0;
  *(undefined1 *)(field + 0x17) = 0;
  return field;
}




/* cube::Region::ctor_1 @ 004f77f0 */

void __fastcall cube::Region::ctor_1(undefined4 *self)

{
  undefined4 *puVar1;
  uint security_cookie;
  int row;
  int *cell_ptr;
  int col;
  undefined4 *self_ptr;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0055562e;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  cell_ptr = self + 0x4006;
  row = 0x40;
  self_ptr = self;
  do {
    col = 0x40;
    do {
      if ((undefined4 *)*cell_ptr != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*cell_ptr)(1,security_cookie);
      }
      puVar1 = self_ptr;
      cell_ptr = cell_ptr + 1;
      col = col + -1;
    } while (col != 0);
    row = row + -1;
  } while (row != 0);
  local_8 = 0xffffffff;
  std_map_erase_range_B(self_ptr + 0x5687,&self_ptr,*(int **)self_ptr[0x5687],(int *)self_ptr[0x5687]);
  operator_delete((void *)puVar1[0x5687]);
  ExceptionList = local_10;
  return;
}




/* cube::Region::vfunc_0 @ 004f7b30 */

undefined4 * __thiscall cube::Region::vfunc_0(Region *this,byte delete_flag)

{
  ctor_1((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




