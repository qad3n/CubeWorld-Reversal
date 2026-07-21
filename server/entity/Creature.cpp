// Creature (entity) — server. 10 functions. Bodies = Ghidra pseudo-C.
#include "Creature.h"

/* [AUDIT] proposed: Creature_zeroInit  (confidence: high)
 * purpose: Zero-initializes a large Creature struct (~0x890 bytes) storing vtable/type at this+0
 * vars: this+0=param_1 (type/vtable); rest zeroed
 */
/* Global::Creature_zeroInit @ 00401140 */

undefined4 * __thiscall Creature_zeroInit(void *this,undefined4 owner)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)this = owner;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x8c) = 0;
  *(undefined4 *)((int)this + 0x90) = 0;
  *(undefined4 *)((int)this + 0x94) = 0;
  *(undefined4 *)((int)this + 0x98) = 0;
  *(undefined4 *)((int)this + 0x9c) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined4 *)((int)this + 0xa4) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xac) = 0;
  *(undefined4 *)((int)this + 0xb0) = 0;
  *(undefined4 *)((int)this + 0xb4) = 0;
  *(undefined4 *)((int)this + 0xb8) = 0;
  *(undefined4 *)((int)this + 0xbc) = 0;
  *(undefined4 *)((int)this + 0xc4) = 0;
  *(undefined4 *)((int)this + 200) = 0;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0;
  *(undefined4 *)((int)this + 0xdc) = 0;
  *(undefined4 *)((int)this + 0xe4) = 0;
  *(undefined4 *)((int)this + 0xe8) = 0;
  *(undefined4 *)((int)this + 0x86c) = 0;
  *(undefined4 *)((int)this + 0x870) = 0;
  *(undefined4 *)((int)this + 0x874) = 0;
  *(undefined1 *)((int)this + 0x878) = 0;
  *(undefined4 *)((int)this + 0x880) = 0;
  *(undefined4 *)((int)this + 0x884) = 0;
  *(undefined4 *)((int)this + 0x888) = 0;
  *(undefined4 *)((int)this + 0x88c) = 0;
  return this;
}




/* cube::Creature::ctor_1 @ 00406400 */

undefined4 * __thiscall cube::Creature::ctor_1(Creature *this,undefined4 *id_pair)

{
  undefined4 obj;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bac0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 8) = *id_pair;
  *(undefined4 *)(this + 0xc) = id_pair[1];
  Creature_construct((undefined4 *)(this + 0x10));
  *(undefined4 *)(this + 0x1178) = 0;
  *(undefined4 *)(this + 0x117c) = 0;
  obj = std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x1178) = obj;
  *(undefined4 *)(this + 0x1180) = 0;
  *(undefined4 *)(this + 0x1184) = 0;
  *(undefined4 *)(this + 0x1188) = 0;
  *(undefined4 *)(this + 0x118c) = 0;
  *(undefined4 *)(this + 0x1190) = 0;
  *(undefined4 *)(this + 0x1194) = 0x3f800000;
  *(undefined4 *)(this + 0x1198) = 0x3f800000;
  *(undefined4 *)(this + 0x119c) = 0;
  local_8 = 0;
  *(undefined4 *)(this + 0x11ac) = 0;
  *(undefined4 *)(this + 0x11b0) = 0;
  obj = List_allocSentinel0x18();
  *(undefined4 *)(this + 0x11ac) = obj;
  local_8._0_1_ = 1;
  *(undefined4 *)(this + 0x11b4) = 0;
  *(undefined4 *)(this + 0x11b8) = 0;
  obj = List_allocSentinel0x18();
  *(undefined4 *)(this + 0x11b4) = obj;
  *(undefined4 *)(this + 0x11c0) = 0;
  *(undefined4 *)(this + 0x11c4) = 0;
  *(undefined4 *)(this + 0x11c8) = 0;
  *(undefined4 *)(this + 0x11cc) = 0;
  *(undefined4 *)(this + 0x11d0) = 0;
  *(undefined4 *)(this + 0x11d4) = 0;
  *(undefined4 *)(this + 0x11d8) = 0;
  Struct_initWithBuffer0x100((undefined4 *)(this + 0x11dc));
  local_8._0_1_ = 3;
  *(undefined4 *)(this + 0x130c) = 0;
  *(undefined4 *)(this + 0x1310) = 0;
  obj = List_allocNode0x134((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x130c) = obj;
  *(undefined4 *)(this + 0x1314) = 0;
  *(undefined4 *)(this + 0x1318) = 0;
  *(undefined4 *)(this + 0x1350) = 0;
  *(undefined4 *)(this + 0x1354) = 0;
  *(undefined4 *)(this + 0x1358) = 0;
  *(undefined4 *)(this + 0x135c) = 0;
  *(undefined4 *)(this + 0x1360) = 0;
  *(undefined4 *)(this + 0x1364) = 0;
  *(undefined4 *)(this + 0x1374) = 0;
  *(undefined4 *)(this + 0x1378) = 0;
  *(undefined4 *)(this + 0x137c) = 0;
  *(undefined4 *)(this + 0x1398) = 0;
  local_8._0_1_ = 4;
  *(undefined4 *)(this + 0x139c) = 0;
  *(undefined4 *)(this + 0x13a0) = 0;
  obj = List_allocSentinel0x18();
  *(undefined4 *)(this + 0x139c) = obj;
  local_8._0_1_ = 5;
  *(undefined4 *)(this + 0x13a4) = 0;
  *(undefined4 *)(this + 0x13a8) = 0;
  obj = List_allocSentinel0x20();
  *(undefined4 *)(this + 0x13a4) = obj;
  local_8._0_1_ = 6;
  *(undefined4 *)(this + 0x13ac) = 0;
  *(undefined4 *)(this + 0x13b0) = 0;
  obj = List_allocSentinel0x20();
  *(undefined4 *)(this + 0x13ac) = obj;
  *(undefined4 *)(this + 0x13b4) = 0;
  this[0x13b8] = (Creature)0x0;
  *(undefined4 *)(this + 0x13bc) = 0;
  this[0x13c0] = (Creature)0x0;
  *(undefined4 *)(this + 0x13c4) = 0;
  *(undefined4 *)(this + 0x13c8) = 0;
  *(undefined4 *)(this + 0x13cc) = 0;
  *(undefined4 *)(this + 0x13d0) = 0;
  *(undefined4 *)(this + 0x13d4) = 0;
  *(undefined4 *)(this + 0x13d8) = 0x3f800000;
  *(undefined4 *)(this + 0x13dc) = 0;
  *(undefined4 *)(this + 0x13e0) = 0;
  *(undefined4 *)(this + 0x13e4) = 0;
  *(undefined4 *)(this + 0x13e8) = 0;
  *(undefined4 *)(this + 0x13ec) = 0;
  *(undefined4 *)(this + 0x13f0) = 0;
  *(undefined4 *)(this + 0x13f4) = 1;
  *(undefined4 *)(this + 0x13f8) = 0;
  *(undefined4 *)(this + 0x13fc) = 0;
  *(undefined4 *)(this + 0x1400) = 0;
  *(undefined4 *)(this + 0x1404) = 0;
  *(undefined4 *)(this + 0x1408) = 0;
  local_8._0_1_ = 9;
  *(undefined4 *)(this + 0x140c) = 0;
  *(undefined4 *)(this + 0x1410) = 0;
  obj = List_allocSentinel0x34();
  *(undefined4 *)(this + 0x140c) = obj;
  local_8._0_1_ = 10;
  *(undefined4 *)(this + 0x1414) = 0;
  *(undefined4 *)(this + 0x1418) = 0;
  obj = std_map_makeHeader_0x1c();
  *(undefined4 *)(this + 0x1414) = obj;
  *(undefined4 *)(this + 0x141c) = 0xffffffff;
  *(undefined4 *)(this + 0x1420) = 0xffffffff;
  *(undefined4 *)(this + 0x1424) = 0xffffffff;
  *(undefined4 *)(this + 0x1458) = 0;
  *(undefined4 *)(this + 0x145c) = 0;
  local_8._0_1_ = 0xb;
  *(undefined4 *)(this + 0x1460) = 0;
  *(undefined4 *)(this + 0x1464) = 0;
  obj = List_allocNode0x14((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x1460) = obj;
  local_8._0_1_ = 0xc;
  *(undefined4 *)(this + 0x1468) = 0;
  *(undefined4 *)(this + 0x146c) = 0;
  obj = std_List_init_sentinel();
  *(undefined4 *)(this + 0x1468) = obj;
  local_8._0_1_ = 0xd;
  *(undefined4 *)(this + 0x1470) = 0;
  *(undefined4 *)(this + 0x1474) = 0;
  obj = List_allocNode0x14((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x1470) = obj;
  *(undefined4 *)(this + 0x1478) = 0xffffffff;
  *(undefined4 *)(this + 0x147c) = 0xffffffff;
  *(undefined4 *)(this + 0x1480) = 0;
  *(undefined4 *)(this + 0x1484) = 0;
  *(undefined4 *)(this + 0x1488) = 0;
  *(undefined4 *)(this + 0x148c) = 0;
  *(undefined4 *)(this + 0x1490) = 0;
  *(undefined4 *)(this + 0x1494) = 0;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  Creature_zeroInit(this + 0x1498,this);
  *(undefined4 *)(this + 0x1d28) = 0;
  *(undefined4 *)(this + 0x1d2c) = 0x43480000;
  this[0x1d38] = (Creature)0x0;
  *(undefined4 *)(this + 0x1d3c) = 1;
  *(undefined4 *)(this + 0x1d40) = 0;
  *(undefined4 *)(this + 0x1d44) = 0;
  *(undefined2 *)(this + 0x1d58) = 1;
  *(undefined2 *)(this + 0x1d48) = 0;
  *(undefined4 *)(this + 0x1d4c) = 0;
  *(undefined4 *)(this + 0x1d50) = 0;
  *(undefined2 *)(this + 0x1d54) = 0;
  this[0x1d56] = (Creature)0x0;
  *(undefined4 *)(this + 0x1e5c) = 0;
  memset(this + 0x1d5c,0,0x100);
  ExceptionList = local_10;
  return (undefined4 *)this;
}




/* [AUDIT] proposed: Creature_construct  (confidence: high)
 * purpose: Full Creature constructor: zeroes fields, sets defaults/floats, inits appearance and slot arrays
 * vars: id_pair=Creature; calls appearance+equip init; +0x1a appearance
 */
/* Global::Creature_construct @ 00407020 */

undefined4 * __fastcall Creature_construct(undefined4 *self)

{
  *self = 0;
  self[1] = 0;
  self[2] = 0;
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
  *(undefined1 *)(self + 0x14) = 3;
  self[0x15] = 0;
  *(undefined1 *)(self + 0x16) = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  CreatureAppearance_initDefault(self + 0x1a);
  *(undefined2 *)(self + 0x45) = 0;
  self[0x46] = 0;
  self[0x48] = 0;
  self[0x49] = 0;
  self[0x4a] = 0;
  self[0x4b] = 0;
  *(undefined2 *)(self + 0x4c) = 0;
  self[0x4d] = 0;
  self[0x47] = 0xfffff448;
  self[0x4e] = 0;
  self[0x4f] = 0;
  self[0x50] = 0;
  self[0x51] = 0;
  self[0x52] = 0;
  self[0x53] = 0;
  self[0x54] = 0;
  self[0x55] = 0;
  self[0x56] = 0;
  self[0x58] = 0;
  self[0x59] = 0;
  self[0x57] = 0x43fa0000;
  self[0x5a] = 0x42c80000;
  self[0x5b] = 0x3f800000;
  self[0x5c] = 0x3f800000;
  self[0x5d] = 0x3f800000;
  self[0x5e] = 0x3f800000;
  *(undefined2 *)(self + 0x5f) = 0;
  self[0x61] = 0;
  self[0x62] = 0;
  self[99] = 0;
  self[100] = 0;
  self[0x65] = 0;
  *(undefined1 *)(self + 0x66) = 0;
  self[0x60] = 1;
  self[0x67] = 0xffffffff;
  self[0x6a] = 0;
  self[0x68] = 0xffffffff;
  self[0x69] = 0xffffffff;
  *(undefined1 *)(self + 0x72) = 0;
  self[0x75] = 0;
  self[0x73] = 0xffffffff;
  self[0x74] = 0xffffffff;
  *(undefined2 *)(self + 0x76) = 0;
  self[0x77] = 0;
  self[0x78] = 0;
  *(undefined2 *)(self + 0x79) = 0;
  *(undefined1 *)((int)self + 0x1e6) = 0;
  *(undefined2 *)(self + 0x7a) = 1;
  self[0xbb] = 0;
  memset(self + 0x7b,0,0x100);
  Creature_initEquipmentSlots((undefined2 *)(self + 0xbc));
  self[0x455] = 0;
  *(undefined8 *)(self + 0x456) = 0;
  *(undefined8 *)(self + 0x458) = 0;
  memset(self + 0x44a,0,0x2c);
  return self;
}




/* cube::Creature::ctor_0 @ 004072d0 */

void __fastcall cube::Creature::ctor_0(undefined4 *creature)

{
  void *ptr;
  int *node;
  int *next;
  undefined4 local_c [2];
  
  *creature = vftable;
  if ((void *)creature[0x4f9] != (void *)0x0) {
    operator_delete((void *)creature[0x4f9]);
  }
  ptr = (void *)creature[0x74a];
  if (ptr != (void *)0x0) {
    Creature_destruct((int)ptr);
    operator_delete(ptr);
  }
  if ((void *)creature[0x523] != (void *)0x0) {
    operator_delete((void *)creature[0x523]);
    creature[0x523] = 0;
    creature[0x524] = 0;
    creature[0x525] = 0;
  }
  node = (int *)creature[0x51c];
  next = (int *)*node;
  *node = (int)node;
  *(undefined4 *)(creature[0x51c] + 4) = creature[0x51c];
  creature[0x51d] = 0;
  if (next != (int *)creature[0x51c]) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)creature[0x51c]);
  }
  operator_delete((void *)creature[0x51c]);
  std_map_erase_range_B(creature + 0x51a,local_c,*(int **)creature[0x51a],(int *)creature[0x51a]);
  operator_delete((void *)creature[0x51a]);
  node = (int *)creature[0x518];
  next = (int *)*node;
  *node = (int)node;
  *(undefined4 *)(creature[0x518] + 4) = creature[0x518];
  creature[0x519] = 0;
  if (next != (int *)creature[0x518]) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)creature[0x518]);
  }
  operator_delete((void *)creature[0x518]);
  Creature_mapEraseRange_v2(creature + 0x505,local_c,*(int **)creature[0x505],(int *)creature[0x505]);
  operator_delete((void *)creature[0x505]);
  Creature_mapEraseRange_v2(creature + 0x503,local_c,*(int **)creature[0x503],(int *)creature[0x503]);
  operator_delete((void *)creature[0x503]);
  if ((void *)creature[0x4fe] != (void *)0x0) {
    operator_delete((void *)creature[0x4fe]);
    creature[0x4fe] = 0;
    creature[0x4ff] = 0;
    creature[0x500] = 0;
  }
  if ((void *)creature[0x4fa] != (void *)0x0) {
    operator_delete((void *)creature[0x4fa]);
    creature[0x4fa] = 0;
    creature[0x4fb] = 0;
    creature[0x4fc] = 0;
  }
  std_map_erase_range_B(creature + 0x4eb,local_c,*(int **)creature[0x4eb],(int *)creature[0x4eb]);
  operator_delete((void *)creature[0x4eb]);
  std_map_erase_range_B(creature + 0x4e9,local_c,*(int **)creature[0x4e9],(int *)creature[0x4e9]);
  operator_delete((void *)creature[0x4e9]);
  std_map_erase_range_B(creature + 0x4e7,local_c,*(int **)creature[0x4e7],(int *)creature[0x4e7]);
  operator_delete((void *)creature[0x4e7]);
  node = (int *)creature[0x4c3];
  next = (int *)*node;
  *node = (int)node;
  *(undefined4 *)(creature[0x4c3] + 4) = creature[0x4c3];
  creature[0x4c4] = 0;
  if (next != (int *)creature[0x4c3]) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)creature[0x4c3]);
  }
  operator_delete((void *)creature[0x4c3]);
  if ((undefined4 *)creature[0x477] != (undefined4 *)0x0) {
    Vector_destroyTriples((undefined4 *)creature[0x477],(undefined4 *)creature[0x478]);
    operator_delete((void *)creature[0x477]);
    creature[0x477] = 0;
    creature[0x478] = 0;
    creature[0x479] = 0;
  }
  std_map_erase_range_B(creature + 0x46d,local_c,*(int **)creature[0x46d],(int *)creature[0x46d]);
  operator_delete((void *)creature[0x46d]);
  std_map_erase_range_B(creature + 0x46b,local_c,*(int **)creature[0x46b],(int *)creature[0x46b]);
  operator_delete((void *)creature[0x46b]);
  node = (int *)creature[0x45e];
  next = (int *)*node;
  *node = (int)node;
  *(undefined4 *)(creature[0x45e] + 4) = creature[0x45e];
  creature[0x45f] = 0;
  if (next != (int *)creature[0x45e]) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)creature[0x45e]);
  }
  operator_delete((void *)creature[0x45e]);
  return;
}




/* [AUDIT] proposed: Creature_destruct  (confidence: high)
 * purpose: Creature destructor: frees SSO string, destroys tree/list containers and their nodes
 * vars: creature=Creature; +0x28 string; +0x14/+0x1c containers
 */
/* Global::Creature_destruct @ 004076a0 */

void __fastcall Creature_destruct(int obj)

{
  int *node;
  int *next;
  int self;
  
  self = obj;
  if (0xf < *(uint *)(obj + 0x3c)) {
    operator_delete(*(void **)(obj + 0x28));
  }
  *(undefined4 *)(obj + 0x3c) = 0xf;
  *(undefined4 *)(obj + 0x38) = 0;
  *(undefined1 *)(obj + 0x28) = 0;
  Creature_mapEraseRange((void *)(obj + 0x1c),&self,(int *)**(int **)(obj + 0x1c),
               *(int **)(obj + 0x1c));
  operator_delete(*(void **)(obj + 0x1c));
  node = *(int **)(obj + 0x14);
  next = (int *)*node;
  *node = (int)node;
  *(int *)(*(int *)(obj + 0x14) + 4) = *(int *)(obj + 0x14);
  *(undefined4 *)(obj + 0x18) = 0;
  if (next != *(int **)(obj + 0x14)) {
    do {
      node = (int *)*next;
      operator_delete(next);
      next = node;
    } while (node != (int *)*(int *)(obj + 0x14));
  }
  operator_delete(*(void **)(obj + 0x14));
  return;
}




/* cube::Creature::vfunc_0 @ 00407aa0 */

undefined4 * __thiscall cube::Creature::vfunc_0(Creature *this,byte delete_flag)

{
  ctor_0((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




/* [AUDIT] proposed: Creature_mapEraseRange  (confidence: high)
 * purpose: Erases a range [first,last) of nodes from a std::map, rebalancing; clears map when full range
 * vars: this=map; param_2=first it; param_3=last it; nodes hold std::string
 */
/* Global::Creature_mapEraseRange @ 00409e60 */

undefined4 * __thiscall Creature_mapEraseRange(void *this,undefined4 *out_it,int *first,int *last)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *self;
  
  piVar2 = *(int **)this;
  self = this;
  piVar3 = first;
  if ((first == (int *)*piVar2) && (last == piVar2)) {
    RBTree_destroyRecursive((int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *out_it = **(undefined4 **)this;
    return out_it;
  }
  while (piVar3 != last) {
    first = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      first = (int *)piVar3[2];
      if (*(char *)((int)first + 0xd) == '\0') {
        cVar1 = *(char *)(*first + 0xd);
        piVar2 = (int *)*first;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          first = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((first = piVar4, cVar1 == '\0' && (piVar2 == (int *)first[2]))) {
          cVar1 = *(char *)(first[1] + 0xd);
          piVar4 = (int *)first[1];
          piVar2 = first;
        }
      }
    }
    Creature_mapEraseNode_str(this,&self,piVar3);
    piVar3 = first;
  }
  *out_it = piVar3;
  return out_it;
}




/* [AUDIT] proposed: Creature_mapEraseNode_str  (confidence: high)
 * purpose: Erases one RB-tree node with embedded std::string, rebalances tree, frees string then node
 * vars: this=map header; first=node; +0xd=nil; +0x14=str len; +5=str buf
 */
/* Global::Creature_mapEraseNode_str @ 00409f20 */

void __thiscall Creature_mapEraseNode_str(void *this,undefined4 *out_it,int *node)

{
  int iVar1;
  int *z;
  int *piVar3;
  int iVar4;
  int *x;
  int *parent;
  int *y;
  
  z = node;
  if (*(char *)((int)node + 0xd) != '\0') {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&node);
  x = (int *)*z;
  if (*(char *)((int)x + 0xd) == '\0') {
    y = x;
    if ((*(char *)(z[2] + 0xd) == '\0') && (y = (int *)node[2], node != z)) {
      x[1] = (int)node;
      *node = *z;
      x = node;
      if (node != (int *)z[2]) {
        x = (int *)node[1];
        if (*(char *)((int)y + 0xd) == '\0') {
          y[1] = (int)x;
        }
        *x = (int)y;
        node[2] = z[2];
        *(int **)(z[2] + 4) = node;
      }
      if (*(int **)(*(int *)this + 4) == z) {
        *(int **)(*(int *)this + 4) = node;
      }
      else {
        parent = (int *)z[1];
        if ((int *)*parent == z) {
          *parent = (int)node;
        }
        else {
          parent[2] = (int)node;
        }
      }
      node[1] = z[1];
      iVar1 = node[3];
      *(char *)(node + 3) = (char)z[3];
      *(char *)(z + 3) = (char)iVar1;
      goto LAB_0040a04c;
    }
  }
  else {
    y = (int *)z[2];
  }
  x = (int *)z[1];
  if (*(char *)((int)y + 0xd) == '\0') {
    y[1] = (int)x;
  }
  if (*(int **)(*(int *)this + 4) == z) {
    *(int **)(*(int *)this + 4) = y;
  }
  else if ((int *)*x == z) {
    *x = (int)y;
  }
  else {
    x[2] = (int)y;
  }
  parent = *(int **)this;
  if ((int *)*parent == z) {
    piVar3 = x;
    if (*(char *)((int)y + 0xd) == '\0') {
      piVar3 = rbtree_min(y);
    }
    *parent = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == z) {
    if (*(char *)((int)y + 0xd) == '\0') {
      iVar4 = rbtree_max((int)y);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = x;
    }
  }
LAB_0040a04c:
  if ((char)z[3] == '\x01') {
    if (y != *(int **)(*(int *)this + 4)) {
      do {
        parent = x;
        if ((char)y[3] != '\x01') break;
        x = (int *)*parent;
        if (y == x) {
          x = (int *)parent[2];
          if ((char)x[3] == '\0') {
            *(undefined1 *)(x + 3) = 1;
            *(undefined1 *)(parent + 3) = 0;
            std_Rb_tree_rotate(this,(int)parent);
            x = (int *)parent[2];
          }
          if (*(char *)((int)x + 0xd) == '\0') {
            if ((*(char *)(*x + 0xc) != '\x01') || (*(char *)(x[2] + 0xc) != '\x01')) {
              if (*(char *)(x[2] + 0xc) == '\x01') {
                *(undefined1 *)(*x + 0xc) = 1;
                *(undefined1 *)(x + 3) = 0;
                rbtree_rotateLeft(this,x);
                x = (int *)parent[2];
              }
              *(char *)(x + 3) = (char)parent[3];
              *(undefined1 *)(parent + 3) = 1;
              *(undefined1 *)(x[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)parent);
              *(undefined1 *)(y + 3) = 1;
              goto LAB_0040a17e;
            }
LAB_0040a120:
            *(undefined1 *)(x + 3) = 0;
          }
        }
        else {
          if ((char)x[3] == '\0') {
            *(undefined1 *)(x + 3) = 1;
            *(undefined1 *)(parent + 3) = 0;
            rbtree_rotateLeft(this,parent);
            x = (int *)*parent;
          }
          if (*(char *)((int)x + 0xd) == '\0') {
            if ((*(char *)(x[2] + 0xc) == '\x01') && (*(char *)(*x + 0xc) == '\x01'))
            goto LAB_0040a120;
            if (*(char *)(*x + 0xc) == '\x01') {
              *(undefined1 *)(x[2] + 0xc) = 1;
              *(undefined1 *)(x + 3) = 0;
              std_Rb_tree_rotate(this,(int)x);
              x = (int *)*parent;
            }
            *(char *)(x + 3) = (char)parent[3];
            *(undefined1 *)(parent + 3) = 1;
            *(undefined1 *)(*x + 0xc) = 1;
            rbtree_rotateLeft(this,parent);
            *(undefined1 *)(y + 3) = 1;
            goto LAB_0040a17e;
          }
        }
        x = (int *)parent[1];
        y = parent;
      } while (parent != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(y + 3) = 1;
  }
LAB_0040a17e:
  if (0xf < (uint)z[10]) {
    operator_delete((void *)z[5]);
  }
  z[10] = 0xf;
  z[9] = 0;
  *(undefined1 *)(z + 5) = 0;
  operator_delete(z);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *out_it = node;
  return;
}




/* [AUDIT] proposed: Creature_mapEraseRange_v2  (confidence: high)
 * purpose: Erases node range from a std::map (variant using 0040a4f0 per-node eraser)
 * vars: this=map; node=first; param_3=last
 */
/* Global::Creature_mapEraseRange_v2 @ 0040a430 */

undefined4 * __thiscall Creature_mapEraseRange_v2(void *this,undefined4 *out_it,int *first,int *last)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *self;
  
  piVar2 = *(int **)this;
  self = this;
  piVar3 = first;
  if ((first == (int *)*piVar2) && (last == piVar2)) {
    RBTree_destroyRec((int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *out_it = **(undefined4 **)this;
    return out_it;
  }
  while (piVar3 != last) {
    first = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      first = (int *)piVar3[2];
      if (*(char *)((int)first + 0xd) == '\0') {
        cVar1 = *(char *)(*first + 0xd);
        piVar2 = (int *)*first;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          first = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((first = piVar4, cVar1 == '\0' && (piVar2 == (int *)first[2]))) {
          cVar1 = *(char *)(first[1] + 0xd);
          piVar4 = (int *)first[1];
          piVar2 = first;
        }
      }
    }
    Creature_mapEraseNode_vec(this,&self,piVar3);
    piVar3 = first;
  }
  *out_it = piVar3;
  return out_it;
}




/* [AUDIT] proposed: Creature_mapEraseNode_vec  (confidence: high)
 * purpose: Erases one RB-tree node owning a heap vector at [4], rebalances, frees vector then node
 * vars: this=map; first=node; [4]=vec begin/data freed
 */
/* Global::Creature_mapEraseNode_vec @ 0040a4f0 */

void __thiscall Creature_mapEraseNode_vec(void *this,undefined4 *out_it,int *node)

{
  int iVar1;
  int *z;
  int *piVar3;
  int iVar4;
  int *x;
  int *parent;
  int *y;
  
  z = node;
  if (*(char *)((int)node + 0xd) != '\0') {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  RBTree_iterIncrement((int *)&node);
  x = (int *)*z;
  if (*(char *)((int)x + 0xd) == '\0') {
    y = x;
    if ((*(char *)(z[2] + 0xd) == '\0') && (y = (int *)node[2], node != z)) {
      x[1] = (int)node;
      *node = *z;
      x = node;
      if (node != (int *)z[2]) {
        x = (int *)node[1];
        if (*(char *)((int)y + 0xd) == '\0') {
          y[1] = (int)x;
        }
        *x = (int)y;
        node[2] = z[2];
        *(int **)(z[2] + 4) = node;
      }
      if (*(int **)(*(int *)this + 4) == z) {
        *(int **)(*(int *)this + 4) = node;
      }
      else {
        parent = (int *)z[1];
        if ((int *)*parent == z) {
          *parent = (int)node;
        }
        else {
          parent[2] = (int)node;
        }
      }
      node[1] = z[1];
      iVar1 = node[3];
      *(char *)(node + 3) = (char)z[3];
      *(char *)(z + 3) = (char)iVar1;
      goto LAB_0040a61c;
    }
  }
  else {
    y = (int *)z[2];
  }
  x = (int *)z[1];
  if (*(char *)((int)y + 0xd) == '\0') {
    y[1] = (int)x;
  }
  if (*(int **)(*(int *)this + 4) == z) {
    *(int **)(*(int *)this + 4) = y;
  }
  else if ((int *)*x == z) {
    *x = (int)y;
  }
  else {
    x[2] = (int)y;
  }
  parent = *(int **)this;
  if ((int *)*parent == z) {
    piVar3 = x;
    if (*(char *)((int)y + 0xd) == '\0') {
      piVar3 = rbtree_min(y);
    }
    *parent = (int)piVar3;
  }
  iVar1 = *(int *)this;
  if (*(int **)(iVar1 + 8) == z) {
    if (*(char *)((int)y + 0xd) == '\0') {
      iVar4 = rbtree_max((int)y);
      *(int *)(iVar1 + 8) = iVar4;
    }
    else {
      *(int **)(iVar1 + 8) = x;
    }
  }
LAB_0040a61c:
  if ((char)z[3] == '\x01') {
    if (y != *(int **)(*(int *)this + 4)) {
      do {
        parent = x;
        if ((char)y[3] != '\x01') break;
        x = (int *)*parent;
        if (y == x) {
          x = (int *)parent[2];
          if ((char)x[3] == '\0') {
            *(undefined1 *)(x + 3) = 1;
            *(undefined1 *)(parent + 3) = 0;
            std_Rb_tree_rotate(this,(int)parent);
            x = (int *)parent[2];
          }
          if (*(char *)((int)x + 0xd) == '\0') {
            if ((*(char *)(*x + 0xc) != '\x01') || (*(char *)(x[2] + 0xc) != '\x01')) {
              if (*(char *)(x[2] + 0xc) == '\x01') {
                *(undefined1 *)(*x + 0xc) = 1;
                *(undefined1 *)(x + 3) = 0;
                rbtree_rotateLeft(this,x);
                x = (int *)parent[2];
              }
              *(char *)(x + 3) = (char)parent[3];
              *(undefined1 *)(parent + 3) = 1;
              *(undefined1 *)(x[2] + 0xc) = 1;
              std_Rb_tree_rotate(this,(int)parent);
              *(undefined1 *)(y + 3) = 1;
              goto LAB_0040a74e;
            }
LAB_0040a6f0:
            *(undefined1 *)(x + 3) = 0;
          }
        }
        else {
          if ((char)x[3] == '\0') {
            *(undefined1 *)(x + 3) = 1;
            *(undefined1 *)(parent + 3) = 0;
            rbtree_rotateLeft(this,parent);
            x = (int *)*parent;
          }
          if (*(char *)((int)x + 0xd) == '\0') {
            if ((*(char *)(x[2] + 0xc) == '\x01') && (*(char *)(*x + 0xc) == '\x01'))
            goto LAB_0040a6f0;
            if (*(char *)(*x + 0xc) == '\x01') {
              *(undefined1 *)(x[2] + 0xc) = 1;
              *(undefined1 *)(x + 3) = 0;
              std_Rb_tree_rotate(this,(int)x);
              x = (int *)*parent;
            }
            *(char *)(x + 3) = (char)parent[3];
            *(undefined1 *)(parent + 3) = 1;
            *(undefined1 *)(*x + 0xc) = 1;
            rbtree_rotateLeft(this,parent);
            *(undefined1 *)(y + 3) = 1;
            goto LAB_0040a74e;
          }
        }
        x = (int *)parent[1];
        y = parent;
      } while (parent != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(y + 3) = 1;
  }
LAB_0040a74e:
  if ((void *)z[4] != (void *)0x0) {
    operator_delete((void *)z[4]);
    z[4] = 0;
    z[5] = 0;
    z[6] = 0;
  }
  operator_delete(z);
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *out_it = node;
  return;
}




