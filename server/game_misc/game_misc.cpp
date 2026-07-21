// game_misc (game_misc) — server. 120 functions. Bodies = Ghidra pseudo-C.
#include "game_misc.h"

/* [AUDIT] proposed: String_reserveGrow  (confidence: high)
 * purpose: std::string capacity grow/reallocate with growth policy; copies param_2 bytes to new buffer
 * vars: param_1=req cap; param_2=copy len; +0x14=cap +0x10=len
 */
/* Global::String_reserveGrow @ 004016f0 */

void __thiscall String_reserveGrow(void *this,uint new_capacity,size_t copy_len)

{
  uint old_capacity;
  uint uVar2;
  void *_Src;
  uint requested;
  void *new_buffer;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054b920;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  requested = new_capacity | 0xf;
  if (requested != 0xffffffff) {
    old_capacity = *(uint *)((int)this + 0x14);
    uVar2 = old_capacity >> 1;
    new_capacity = requested;
    if ((requested / 3 < uVar2) && (new_capacity = uVar2 + old_capacity, -uVar2 - 2 < old_capacity)) {
      new_capacity = 0xfffffffe;
    }
  }
  local_8 = 0;
  new_buffer = (void *)0x0;
  if ((new_capacity + 1 != 0) && (new_buffer = operator_new(new_capacity + 1), new_buffer == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  if (copy_len != 0) {
    _Src = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      _Src = *(void **)this;
    }
    if (copy_len != 0) {
      memcpy(new_buffer,_Src,copy_len);
    }
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
    operator_delete(*(void **)this);
  }
  *(undefined1 *)this = 0;
  *(void **)this = new_buffer;
  *(uint *)((int)this + 0x14) = new_capacity;
  *(size_t *)((int)this + 0x10) = copy_len;
  if (0xf < new_capacity) {
    this = new_buffer;
  }
  *(undefined1 *)((int)this + copy_len) = 0;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: String_assign  (confidence: high)
 * purpose: std::string assign from buffer new_capacity of length copy_len; grows or reuses SSO buffer
 * vars: new_capacity=src; copy_len=len; +0x10=len +0x14=cap
 */
/* Global::String_assign @ 00401a40 */

int * __thiscall String_assign(void *this,int *src,uint len)

{
  uint capacity;
  int *cur_buf;
  void *cur_buf2;
  
  if (src != (int *)0x0) {
    capacity = *(uint *)((int)this + 0x14);
    cur_buf = this;
    if (0xf < capacity) {
      cur_buf = *(int **)this;
    }
    if (cur_buf <= src) {
      cur_buf2 = this;
      if (0xf < capacity) {
        cur_buf2 = *(void **)this;
      }
      if (src < (int *)(*(int *)((int)this + 0x10) + (int)cur_buf2)) {
        if (0xf < capacity) {
          cur_buf = String_replaceRange(this,this,(int)src - *(int *)this,len);
          return cur_buf;
        }
        cur_buf = String_replaceRange(this,this,(int)src - (int)this,len);
        return cur_buf;
      }
    }
  }
  if (len == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < len) {
    String_reserveGrow(this,len,*(size_t *)((int)this + 0x10));
    if (len == 0) {
      return this;
    }
  }
  else if (len == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (0xf < *(uint *)((int)this + 0x14)) {
      **(undefined1 **)this = 0;
      return this;
    }
    *(undefined1 *)this = 0;
    return this;
  }
  cur_buf2 = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
    cur_buf2 = *(void **)this;
  }
  if (len != 0) {
    memcpy(cur_buf2,src,len);
  }
  *(uint *)((int)this + 0x10) = len;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + len) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + len) = 0;
  return this;
}




/* [AUDIT] proposed: Matrix4_setIdentity  (confidence: high)
 * purpose: Initializes a 4x4 float identity matrix (diagonal = 1.0f=0x3f800000)
 * vars: src=16-float matrix
 */
/* Global::Matrix4_setIdentity @ 00401cd0 */

void __fastcall Matrix4_setIdentity(undefined4 *matrix)

{
  *matrix = 0x3f800000;
  matrix[1] = 0;
  matrix[2] = 0;
  matrix[3] = 0;
  matrix[4] = 0;
  matrix[5] = 0x3f800000;
  matrix[6] = 0;
  matrix[7] = 0;
  matrix[8] = 0;
  matrix[9] = 0;
  matrix[10] = 0x3f800000;
  matrix[0xb] = 0;
  matrix[0xc] = 0;
  matrix[0xd] = 0;
  matrix[0xe] = 0;
  matrix[0xf] = 0x3f800000;
  return;
}




/* [AUDIT] proposed: Vec3i64_randomize  (confidence: high)
 * purpose: Fills 3 int64 slots with 64-bit random values via ftol2 (RNG)
 * vars: matrix=dest 3x int64; loop x3
 */
/* Global::Vec3i64_randomize @ 00402510 */

int __fastcall Vec3i64_randomize(int dst)

{
  int i;
  ulonglong val;
  
  i = 0;
  do {
    val = ftol2();
    *(int *)(dst + i * 8) = (int)val;
    *(int *)(dst + 4 + i * 8) = (int)(val >> 0x20);
    i = i + 1;
  } while (i < 3);
  return dst;
}




/* [AUDIT] proposed: Vec3i64_toFloatScaled  (confidence: high)
 * purpose: Converts 3 int64 to floats scaled by 1.5258789e-05 (1/65536); fixed-point to float vec3
 * vars: this=dest floats; dst=src int64[3]; scale 2^-16
 */
/* Global::Vec3i64_toFloatScaled @ 00402550 */

float * __thiscall Vec3i64_toFloatScaled(void *this,longlong *src_vec)

{
  *(float *)this = (float)*src_vec * 1.5258789e-05;
  *(float *)((int)this + 4) = (float)src_vec[1] * 1.5258789e-05;
  *(float *)((int)this + 8) = (float)src_vec[2] * 1.5258789e-05;
  return this;
}




/* [AUDIT] proposed: Copy24Bytes  (confidence: high)
 * purpose: Copies 6 dwords (24 bytes) from src_vec to this; vec3-of-int64 or 6-field copy
 * vars: this=dest; src_vec=src 6 dwords
 */
/* Global::Copy24Bytes @ 00402a40 */

undefined4 * __thiscall Copy24Bytes(void *this,undefined4 *src)

{
  *(undefined4 *)this = *src;
  *(undefined4 *)((int)this + 4) = src[1];
  *(undefined4 *)((int)this + 8) = src[2];
  *(undefined4 *)((int)this + 0xc) = src[3];
  *(undefined4 *)((int)this + 0x10) = src[4];
  *(undefined4 *)((int)this + 0x14) = src[5];
  return this;
}




/* [AUDIT] proposed: Vec3i64_subtract  (confidence: high)
 * purpose: Copies 6 dwords then subtracts param_2's three int64 with borrow; 64-bit vec3 subtract
 * vars: src=dest; param_2=subtrahend 3x int64
 */
/* Global::Vec3i64_subtract @ 00402c50 */

uint * __thiscall Vec3i64_subtract(void *this,uint *dst,uint *rhs)

{
  uint *puVar1;
  uint lo_prev;
  uint sub_val;
  
  *dst = *(uint *)this;
  dst[1] = *(uint *)((int)this + 4);
  dst[2] = *(uint *)((int)this + 8);
  dst[3] = *(uint *)((int)this + 0xc);
  dst[4] = *(uint *)((int)this + 0x10);
  dst[5] = *(uint *)((int)this + 0x14);
  sub_val = *rhs;
  lo_prev = *dst;
  *dst = *dst - sub_val;
  dst[1] = (dst[1] - rhs[1]) - (uint)(lo_prev < sub_val);
  sub_val = rhs[2];
  puVar1 = dst + 2;
  lo_prev = *puVar1;
  *puVar1 = *puVar1 - sub_val;
  dst[3] = (dst[3] - rhs[3]) - (uint)(lo_prev < sub_val);
  sub_val = rhs[4];
  puVar1 = dst + 4;
  lo_prev = *puVar1;
  *puVar1 = *puVar1 - sub_val;
  dst[5] = (dst[5] - rhs[5]) - (uint)(lo_prev < sub_val);
  return dst;
}




/* [AUDIT] proposed: Vec3i64_add  (confidence: high)
 * purpose: Copies 6 dwords then adds rhs's three int64 with carry; 64-bit vec3 add
 * vars: dst=dest; rhs=addend 3x int64
 */
/* Global::Vec3i64_add @ 00402cb0 */

uint * __thiscall Vec3i64_add(void *this,uint *dst,uint *rhs)

{
  uint *puVar1;
  uint lo_prev;
  uint add_val;
  
  *dst = *(uint *)this;
  dst[1] = *(uint *)((int)this + 4);
  dst[2] = *(uint *)((int)this + 8);
  dst[3] = *(uint *)((int)this + 0xc);
  dst[4] = *(uint *)((int)this + 0x10);
  dst[5] = *(uint *)((int)this + 0x14);
  add_val = *rhs;
  lo_prev = *dst;
  *dst = *dst + add_val;
  dst[1] = dst[1] + rhs[1] + (uint)CARRY4(lo_prev,add_val);
  add_val = rhs[2];
  puVar1 = dst + 2;
  lo_prev = *puVar1;
  *puVar1 = *puVar1 + add_val;
  dst[3] = dst[3] + rhs[3] + (uint)CARRY4(lo_prev,add_val);
  add_val = rhs[4];
  puVar1 = dst + 4;
  lo_prev = *puVar1;
  *puVar1 = *puVar1 + add_val;
  dst[5] = dst[5] + rhs[5] + (uint)CARRY4(lo_prev,add_val);
  return dst;
}




/* [AUDIT] proposed: World_clearContainers  (confidence: med)
 * purpose: Resets two rb-trees and a linked list plus calls std_map_clear; clears world/zone sub-structures
 * vars: dst=owner; +0x140c/+0x1414 trees; +0x1460 list
 */
/* Global::World_clearContainers @ 00405330 */

void __fastcall World_clearContainers(int creature)

{
  int *list1;
  int *list2;
  int *node;
  
  list1 = (int *)(creature + 0x140c);
  RBTree_destroyRec(*(int **)(*(int *)(creature + 0x140c) + 4));
  list2 = (int *)(creature + 0x1414);
  *(int *)(*list1 + 4) = *list1;
  *(int *)*list1 = *list1;
  *(int *)(*list1 + 8) = *list1;
  *(undefined4 *)(creature + 0x1410) = 0;
  RBTree_destroyRec(*(int **)(*list2 + 4));
  *(int *)(*list2 + 4) = *list2;
  *(int *)*list2 = *list2;
  *(int *)(*list2 + 8) = *list2;
  *(undefined4 *)(creature + 0x1418) = 0;
  list2 = *(int **)(creature + 0x1460);
  node = (int *)*list2;
  *list2 = (int)list2;
  *(int *)(*(int *)(creature + 0x1460) + 4) = *(int *)(creature + 0x1460);
  *(undefined4 *)(creature + 0x1464) = 0;
  if (node != *(int **)(creature + 0x1460)) {
    do {
      list2 = (int *)*node;
      operator_delete(node);
      node = list2;
    } while (list2 != (int *)*(int *)(creature + 0x1460));
  }
  *(int *)(creature + 0x1408) = *list1;
  std_map_clear((int *)(creature + 0x1468));
  return;
}




/* [AUDIT] proposed: Vec3i64_toBlockCoords  (confidence: high)
 * purpose: Divides each vec3 int64 component by 0x10000 with floor; fixed-point to integer block coords
 * vars: creature=out int[3]; param_2=3x int64
 */
/* Global::Vec3i64_toBlockCoords @ 00405450 */

void __cdecl Vec3i64_toBlockCoords(int *dst,uint *src)

{
  uint denom;
  int qz;
  int qy;
  undefined8 uVar4;
  
  denom = src[5];
  if (((int)denom < 1) && ((int)denom < 0)) {
    uVar4 = __alldiv(src[4],denom,0x10000,0);
    qz = (int)uVar4 + -1;
  }
  else {
    uVar4 = __alldiv(src[4],denom,0x10000,0);
    qz = (int)uVar4;
  }
  denom = src[3];
  if (((int)denom < 1) && ((int)denom < 0)) {
    uVar4 = __alldiv(src[2],denom,0x10000,0);
    qy = (int)uVar4 + -1;
  }
  else {
    uVar4 = __alldiv(src[2],denom,0x10000,0);
    qy = (int)uVar4;
  }
  denom = src[1];
  if (((int)denom < 1) && ((int)denom < 0)) {
    uVar4 = __alldiv(*src,denom,0x10000,0);
    dst[1] = qy;
    dst[2] = qz;
    *dst = (int)uVar4 + -1;
    return;
  }
  uVar4 = __alldiv(*src,denom,0x10000,0);
  dst[1] = qy;
  dst[2] = qz;
  *dst = (int)uVar4;
  return;
}




/* [AUDIT] proposed: Column_getBlockChecked  (confidence: med)
 * purpose: Bounds-checked access into block column array (this+0x18), returns element or sentinel default
 * vars: dst=index; +0x1c=count; +0x18=array
 */
/* Global::Column_getBlockChecked @ 00405f20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __thiscall Column_getBlockChecked(void *this,int index)

{
  if (index < 0) {
    if ((DAT_00583d1c & 1) == 0) {
      DAT_00583d1c = DAT_00583d1c | 1;
    }
    _DAT_00583d18 = 0;
    _DAT_00583d1a = 0x100;
    return &DAT_00583d18;
  }
  if (*(int *)((int)this + 0x1c) <= index) {
    if ((DAT_00583d1c & 2) == 0) {
      DAT_00583d1c = DAT_00583d1c | 2;
    }
    _DAT_00583d20 = 0xffff;
    DAT_00583d22 = 0xff;
    DAT_00583d23 = 0;
    return &DAT_00583d20;
  }
  return (undefined *)(*(int *)((int)this + 0x18) + index * 4);
}




/* [AUDIT] proposed: World_getBlockAt  (confidence: med)
 * purpose: Looks up chunk then block by coords; returns block ptr or sentinel defaults on out-of-range
 * vars: index/2=xy; param_3=z; param_4=chunk hint
 */
/* Global::World_getBlockAt @ 00405fd0 */

undefined * __thiscall World_getBlockAt(void *this,uint x,uint y,int z,int hint)

{
  int base_z;
  void *this_00;
  undefined *result;
  
  this_00 = (void *)Chunk_getColumnAt(this,x,y,hint);
  if (this_00 == (void *)0x0) {
    return &DAT_00583d14;
  }
  base_z = *(int *)((int)this_00 + 0x10);
  if (z < base_z) {
    return &DAT_00583d14;
  }
  if (*(int *)((int)this_00 + 0x1c) + base_z <= z) {
    result = &DAT_00583d0c;
    if (0 < z) {
      result = &DAT_00583d10;
    }
    return result;
  }
  result = Column_getBlockChecked(this_00,z - base_z);
  if ((((result[3] & 0x1f) == 0) && (z < 1)) && ((result[3] & 0x40) == 0)) {
    result = &DAT_00583d0c;
  }
  return result;
}




/* [AUDIT] proposed: World_getBlockFloat  (confidence: med)
 * purpose: Floor-divides fixed-point coords by 0x10000 then fetches block via World_getBlockAt
 * vars: x..6=3x fixed-point coord {lo,hi}; param_7=hint
 */
/* Global::World_getBlockFloat @ 00406050 */

void __thiscall
World_getBlockFloat(void *this,uint x_lo,uint x_hi,uint y_lo,uint y_hi,uint z_lo,
            uint z_hi,int hint)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (((int)x_hi < 1) && ((int)x_hi < 0)) {
    bVar1 = 0xffff < x_lo;
    x_lo = x_lo - 0x10000;
    x_hi = (x_hi - 1) + (uint)bVar1;
  }
  if (((int)y_hi < 1) && ((int)y_hi < 0)) {
    bVar1 = 0xffff < y_lo;
    y_lo = y_lo - 0x10000;
    y_hi = (y_hi - 1) + (uint)bVar1;
  }
  if (((int)z_hi < 1) && ((int)z_hi < 0)) {
    bVar1 = 0xffff < z_lo;
    z_lo = z_lo - 0x10000;
    z_hi = (z_hi - 1) + (uint)bVar1;
  }
  uVar2 = __alldiv(z_lo,z_hi,0x10000,0);
  uVar3 = __alldiv(y_lo,y_hi,0x10000,0);
  uVar4 = __alldiv(x_lo,x_hi,0x10000,0);
  World_getBlockAt(this,(uint)uVar4,(uint)uVar3,(int)uVar2,hint);
  return;
}




/* [AUDIT] proposed: Chunk_getColumnAt  (confidence: med)
 * purpose: Validates world coords in range, resolves chunk (hint or lookup) and returns column ptr
 * vars: x_lo/2=world xy; y_lo=chunk; +0xa8=column array
 */
/* Global::Chunk_getColumnAt @ 00406100 */

int __thiscall Chunk_getColumnAt(void *this,uint x,uint y,int region)

{
  int iVar1;
  int iVar2;
  uint ly;
  uint lx;
  
  if ((((-1 < (int)x) && (-1 < (int)y)) && ((int)x < 0x1000000)) &&
     ((int)y < 0x1000000)) {
    if (region == 0) {
      region = Region_getChunkCell(this,(int)(x + ((int)x >> 0x1f & 0xffU)) >> 8,
                             (int)(y + ((int)y >> 0x1f & 0xffU)) >> 8);
    }
    else {
      iVar1 = *(int *)(region + 0x60) * 0x100;
      if ((int)x < iVar1) {
        return 0;
      }
      iVar2 = *(int *)(region + 100) * 0x100;
      if ((int)y < iVar2) {
        return 0;
      }
      if (iVar1 + 0x100 <= (int)x) {
        return 0;
      }
      if (iVar2 + 0x100 <= (int)y) {
        return 0;
      }
    }
    if (region != 0) {
      ly = y & 0x800000ff;
      if ((int)ly < 0) {
        ly = (ly - 1 | 0xffffff00) + 1;
      }
      lx = x & 0x800000ff;
      if ((int)lx < 0) {
        lx = (lx - 1 | 0xffffff00) + 1;
      }
      return (lx + ly * 0x100) * 0x20 + *(int *)(region + 0xa8);
    }
  }
  return 0;
}




/* [AUDIT] proposed: Grid_lookup1024  (confidence: high)
 * purpose: Bounds-checked 2D grid lookup (0..0x3ff each); returns dword at this+0xbc+(x*0x400+y)*4
 * vars: x/2=x/y; grid at +0xbc
 */
/* Global::Grid_lookup1024 @ 00406210 */

undefined4 __thiscall Grid_lookup1024(void *this,int cx,int cy)

{
  if ((((-1 < cx) && (-1 < cy)) && (cx < 0x400)) && (cy < 0x400)) {
    return *(undefined4 *)((int)this + (cx * 0x400 + cy) * 4 + 0xbc);
  }
  return 0;
}




/* [AUDIT] proposed: Region_getChunkCell  (confidence: med)
 * purpose: Bounds-checked (0..0xffff) region lookup via grid then returns cell at +0x10018
 * vars: cx/2=coords; >>6 to grid; cell array +0x10018
 */
/* Global::Region_getChunkCell @ 00406290 */

undefined4 __thiscall Region_getChunkCell(void *this,uint x,uint y)

{
  int cell;
  uint lx;
  uint ly;
  
  if ((((-1 < (int)x) && (-1 < (int)y)) && ((int)x < 0x10000)) &&
     ((int)y < 0x10000)) {
    cell = Grid_lookup1024(this,(int)(x + ((int)x >> 0x1f & 0x3fU)) >> 6,
                         (int)(y + ((int)y >> 0x1f & 0x3fU)) >> 6);
    if (cell != 0) {
      lx = x & 0x8000003f;
      if ((int)lx < 0) {
        lx = (lx - 1 | 0xffffffc0) + 1;
      }
      ly = y & 0x8000003f;
      if ((int)ly < 0) {
        ly = (ly - 1 | 0xffffffc0) + 1;
      }
      return *(undefined4 *)(cell + 0x10018 + (lx * 0x40 + ly) * 4);
    }
  }
  return 0;
}




/* [AUDIT] proposed: Struct_initWithBuffer0x100  (confidence: med)
 * purpose: Zero-inits struct and memsets an inner 0x100 buffer; per-slot init template
 * vars: x=struct; +9=0x100 buffer
 */
/* Global::Struct_initWithBuffer0x100 @ 00406ef0 */

undefined4 * __fastcall Struct_initWithBuffer0x100(undefined4 *self)

{
  *self = 0;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  *(undefined2 *)(self + 8) = 1;
  *(undefined2 *)(self + 4) = 0;
  self[5] = 0;
  self[6] = 0;
  *(undefined2 *)(self + 7) = 0;
  *(undefined1 *)((int)self + 0x1e) = 0;
  self[0x49] = 0;
  memset(self + 9,0,0x100);
  self[0x4a] = 0;
  self[0x4b] = 0;
  return self;
}




/* [AUDIT] proposed: mapItemTypeToSlotIndex  (confidence: med)
 * purpose: Maps an item/equip type opcode to a bonus-slot index (6/7/8) or -1 for unhandled
 * vars: self=type code; returns slot index used at base+0x1138
 */
/* Global::mapItemTypeToSlotIndex @ 00407cc0 */

undefined4 __cdecl mapItemTypeToSlotIndex(undefined4 type)

{
  switch(type) {
  case 0x15:
  case 0x22:
  case 0x30:
  case 0x36:
  case 0x58:
    return 6;
  default:
    return 0xffffffff;
  case 0x31:
  case 0x60:
  case 0x61:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    return 8;
  case 0x32:
  case 0x4f:
  case 0x56:
  case 0x67:
    return 7;
  }
}




/* [AUDIT] proposed: Combat_getResistFactor  (confidence: high)
 * purpose: Diminishing-returns factor 1-1/(level*0.1+1) from a resist/level slot, or 1.0 if type unhandled
 * vars: type=creature; param_2=type; param_3=level override; +0x1138=slot array
 */
/* Global::Combat_getResistFactor @ 00409de0 */

float10 __thiscall Combat_getResistFactor(int param_1,undefined4 damage_type,int stacks)

{
  int type_index;
  
  type_index = mapItemTypeToSlotIndex(damage_type);
  if (type_index < 0) {
    return (float10)1;
  }
  if (stacks < 0) {
    stacks = *(int *)(param_1 + 0x1138 + type_index * 4);
  }
  if ((stacks == 0) && (*(char *)(param_1 + 0x60) != '\0')) {
    stacks = *(int *)(param_1 + 400) / 2 + *(byte *)(param_1 + 0x1a8) + 1;
  }
  return (float10)(1.0 - 1.0 / ((float)stacks * 0.1 + 1.0));
}




/* [AUDIT] proposed: Combat_isSpecialSpiritActive  (confidence: high)
 * purpose: Predicate: true if this+0xaa8==3 and spirit-state this+0xaa9 in a specific set of ids
 * vars: param_1+0xaa8=spirit flag; +0xaa9=spirit subtype
 */
/* Global::Combat_isSpecialSpiritActive @ 0040f2b0 */

undefined1 __fastcall Combat_isSpecialSpiritActive(int creature)

{
  char cVar1;
  
  if ((*(char *)(creature + 0xaa8) == '\x03') &&
     ((((((cVar1 = *(char *)(creature + 0xaa9), cVar1 == '\x0f' || (cVar1 == '\x10')) ||
         (cVar1 == '\x11')) || ((cVar1 == '\x05' || (cVar1 == '\n')))) ||
       ((cVar1 == '\v' || ((cVar1 == '\x12' || (cVar1 == '\b')))))) ||
      ((cVar1 == '\x06' || (cVar1 == '\a')))))) {
    return 1;
  }
  return 0;
}




/* [AUDIT] proposed: Combat_getStaminaRegenRate  (confidence: med)
 * purpose: Returns stamina/regen amount = this+0x17c * factor (20/50/60/80) chosen by spirit/flag state
 * vars: creature+0xaa8/0xaa9=spirit; +0x7e flags; +0x17c=scale
 */
/* Global::Combat_getStaminaRegenRate @ 0040fcf0 */

int __fastcall Combat_getStaminaRegenRate(int creature)

{
  if (*(char *)(creature + 0xaa8) == '\x03') {
    switch(*(undefined1 *)(creature + 0xaa9)) {
    case 6:
      return (int)(*(float *)(creature + 0x17c) * 60.0);
    case 8:
      return (int)(*(float *)(creature + 0x17c) * 80.0);
    case 0xb:
    case 0xc:
    case 0xf:
    case 0x10:
    case 0x11:
switchD_0040fd08_caseD_b:
      return (int)(*(float *)(creature + 0x17c) * 20.0);
    }
  }
  else if ((*(byte *)(creature + 0x7e) & 0x10) != 0) goto switchD_0040fd08_caseD_b;
  return (int)(*(float *)(creature + 0x17c) * 50.0);
}




/* [AUDIT] proposed: Combat_computeMaxHealth  (confidence: high)
 * purpose: Computes max HP: 2^a*2^b*base(+0x178) with class/mode multipliers plus per-equipment-slot bonuses
 * vars: creature+0x178=base; +0x140/0x141=class/subclass; equip slots at 0x990,0xaa8,0x530...
 */
/* Global::Combat_computeMaxHealth @ 0040fda0 */

float10 __fastcall Combat_computeMaxHealth(int creature)

{
  float10 fVar1;
  double dVar2;
  double dVar3;
  float result;
  float value;
  
  dVar2 = 2.0;
  libm_sse2_pow_precise();
  dVar3 = 2.0;
  libm_sse2_pow_precise();
  value = (float)dVar3 * (float)dVar2 * *(float *)(creature + 0x178);
  if (*(char *)(creature + 0x60) == '\0') {
    dVar3 = 2.0;
    libm_sse2_pow_precise();
    value = (float)dVar3 * (float)dVar2 * *(float *)(creature + 0x178);
  }
  switch(*(char *)(creature + 0x140)) {
  case '\x01':
    value = value * 1.3;
    break;
  case '\x02':
    value = value * 1.1;
    break;
  case '\x04':
    value = value * 1.2;
  }
  if ((*(char *)(creature + 0x140) == '\x01') && (*(char *)(creature + 0x141) == '\x01')) {
    value = value * 1.25;
  }
  if (*(char *)(creature + 0x990) == '\x03') {
    fVar1 = Combat_equipHealthBonus((char *)(creature + 0x990));
    value = (float)fVar1 + value;
  }
  if (*(char *)(creature + 0xaa8) == '\x03') {
    fVar1 = Combat_equipHealthBonus((char *)(creature + 0xaa8));
    value = (float)fVar1 + value;
  }
  if (*(char *)(creature + 0x530) == '\x04') {
    fVar1 = Combat_equipHealthBonus((char *)(creature + 0x530));
    value = (float)fVar1 + value;
  }
  if (*(char *)(creature + 0x648) == '\x06') {
    fVar1 = Combat_equipHealthBonus((char *)(creature + 0x648));
    value = (float)fVar1 + value;
  }
  if (*(char *)(creature + 0x760) == '\x05') {
    fVar1 = Combat_equipHealthBonus((char *)(creature + 0x760));
    value = (float)fVar1 + value;
  }
  result = value;
  if (*(char *)(creature + 0x878) == '\a') {
    fVar1 = Combat_equipHealthBonus((char *)(creature + 0x878));
    result = (float)fVar1 + value;
  }
  return (float10)result;
}




/* [AUDIT] proposed: Combat_selectNextAttackAnim  (confidence: med)
 * purpose: Large decision tree selecting the next attack/animation id (char) from class, spirit, weapon state
 * vars: creature+0x140/0x141=class; +0x68=cur anim; +0xaa8/0xaa9=spirit; +0x6c timer vs windup
 */
/* Global::Combat_selectNextAttackAnim @ 00410010 */

char __fastcall Combat_selectNextAttackAnim(int creature)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int cooldown;
  
  if ((((*(char *)(creature + 0x140) == '\x03') || (cooldown = *(int *)(creature + 100), cooldown == 0x75))
      || (cooldown == 0x56)) ||
     ((cVar3 = *(char *)(creature + 0xaa8), cVar3 == '\x03' &&
      (((cVar1 = *(char *)(creature + 0xaa9), cVar1 == '\n' || (cVar1 == '\v')) || (cVar1 == '\f'))))
     )) {
    if (*(char *)(creature + 0xaa9) == '\v') {
      cVar3 = '&';
      if (*(char *)(creature + 0x141) == '\x01') {
        cVar3 = ',';
      }
      return cVar3;
    }
    if (*(char *)(creature + 0xaa9) == '\n') {
      return (*(char *)(creature + 0x141) == '\x01') * '\x02' + '\x1e';
    }
    if (*(char *)(creature + 0x141) != '\x01') {
      if (*(char *)(creature + 0x68) == '(') {
        cooldown = Combat_getWindupAndRecovery(creature);
        if (*(int *)(creature + 0x6c) < cooldown + 200) {
          return '\'';
        }
      }
      return '(';
    }
    if (*(char *)(creature + 0x68) == '*') {
      cooldown = Combat_getWindupAndRecovery(creature);
      if (*(int *)(creature + 0x6c) < cooldown + 200) {
        return ')';
      }
    }
    return '*';
  }
  if ((cooldown == 0x68) ||
     ((cVar3 == '\x03' &&
      ((*(char *)(creature + 0xaa9) == '\x06' || (*(char *)(creature + 0xaa9) == '\a')))))) {
    return '\x16';
  }
  cVar1 = *(char *)(creature + 0x990);
  if ((cVar1 == '\x03') &&
     ((*(char *)(creature + 0x991) == '\x06' || (*(char *)(creature + 0x991) == '\a')))) {
    return '\x16';
  }
  cVar2 = *(char *)(creature + 0xaa9);
  if (cVar2 == '\x03') {
    if (*(char *)(creature + 0x68) == '\x13') {
      cooldown = Combat_getWindupAndRecovery(creature);
      if (*(int *)(creature + 0x6c) < cooldown + 200) {
        return '\x12';
      }
    }
    return '\x13';
  }
  if ((cVar2 != '\x04') && (cVar3 != '\0')) {
    if (cVar2 == '\x05') {
      if (*(char *)(creature + 0x68) == '\x0e') {
        cooldown = Combat_getWindupAndRecovery(creature);
        if (*(int *)(creature + 0x6c) < cooldown + 200) {
          return '\r';
        }
      }
      return '\x0e';
    }
    if ((cVar3 == '\x03') && (cVar2 == '\b')) {
      return '\x1a';
    }
    cVar3 = Combat_isSpecialSpiritActive(creature);
    if (cVar3 != '\0') {
      if (*(char *)(creature + 0x68) == '9') {
        cooldown = Combat_getWindupAndRecovery(creature);
        if (*(int *)(creature + 0x6c) < cooldown + 200) {
          return 'C';
        }
      }
      if (*(char *)(creature + 0x68) == 'C') {
        cooldown = Combat_getWindupAndRecovery(creature);
        if (*(int *)(creature + 0x6c) < cooldown + 200) {
          return ':';
        }
      }
      return '9';
    }
    if ((cVar1 == '\x03') && (*(char *)(creature + 0x991) == '\r')) {
      if (*(char *)(creature + 0x68) == '\n') {
        cooldown = Combat_getWindupAndRecovery(creature);
        if (*(int *)(creature + 0x6c) < cooldown + 200) {
          return '\t';
        }
      }
      return '\n';
    }
    if ((*(byte *)(creature + 0x7e) & 0x10) != 0) {
      return 'K';
    }
    if (*(char *)(creature + 0x68) == '\x01') {
      cooldown = Combat_getWindupAndRecovery(creature);
      if (*(int *)(creature + 0x6c) < cooldown + 200) {
        return '\x02';
      }
    }
    return '\x01';
  }
  if (*(char *)(creature + 0x68) == '\x06') {
    cooldown = Combat_getWindupAndRecovery(creature);
    if (*(int *)(creature + 0x6c) < cooldown + 200) {
      return '\a';
    }
  }
  return '\x06';
}




/* [AUDIT] proposed: Combat_selectSpiritAttackId  (confidence: med)
 * purpose: Returns an action/attack id chosen from spirit state, class and a parity of position bits
 * vars: creature+0xaa8/0xaa9=spirit; +0x140/0x141=class; +0x70=pos bits
 */
/* Global::Combat_selectSpiritAttackId @ 00410290 */

int __fastcall Combat_selectSpiritAttackId(int creature)

{
  char cVar1;
  uint parity;
  int action;
  
  if ((*(char *)(creature + 0xaa8) == '\x03') && (*(char *)(creature + 0xaa9) == '\x06')) {
    return 0x17;
  }
  if (((*(char *)(creature + 0x140) != '\x03') && (*(int *)(creature + 100) != 0x75)) &&
     (*(int *)(creature + 100) != 0x56)) {
    if (*(char *)(creature + 0xaa8) == '\x03') {
      cVar1 = *(char *)(creature + 0xaa9);
      if (((cVar1 == '\n') || (cVar1 == '\v')) || (cVar1 == '\f')) goto LAB_00410355;
      if (cVar1 == '\x05') {
        return 5;
      }
      cVar1 = *(char *)(creature + 0xaa9);
      if ((((cVar1 == '\x0f') || (cVar1 == '\x10')) ||
          (((cVar1 == '\x11' ||
            ((((cVar1 == '\x05' || (cVar1 == '\n')) || (cVar1 == '\v')) ||
             ((cVar1 == '\x12' || (cVar1 == '\b')))))) || (cVar1 == '\x06')))) || (cVar1 == '\a')) {
        parity = *(uint *)(creature + 0x70) & 0x80000001;
        if ((int)parity < 0) {
          parity = (parity - 1 | 0xfffffffe) + 1;
        }
        return 0x42 - (uint)(parity != 0);
      }
    }
    parity = *(uint *)(creature + 0x70) & 0x80000001;
    if ((int)parity < 0) {
      parity = (parity - 1 | 0xfffffffe) + 1;
    }
    return (parity != 0) + 3;
  }
LAB_00410355:
  if (*(char *)(creature + 0xaa9) == '\v') {
    return (*(char *)(creature + 0x141) != '\x01') + 0x2d;
  }
  if (*(char *)(creature + 0xaa9) == '\n') {
    return (uint)(*(char *)(creature + 0x141) == '\x01') * 2 + 0x1f;
  }
  action = 0x25;
  if (*(char *)(creature + 0x141) == '\x01') {
    action = 0x2b;
  }
  return action;
}




/* [AUDIT] proposed: pow2Mul  (confidence: high)
 * purpose: Helper: returns 2^a * 2^b (two pow calls, product) for stat scaling
 * vars: -
 */
/* Global::pow2Mul @ 00410f00 */

float10 pow2Mul(void)

{
  double val;
  float fStack00000004;
  
  val = 2.0;
  libm_sse2_pow_precise();
  fStack00000004 = (float)val;
  val = 2.0;
  libm_sse2_pow_precise();
  return (float10)(fStack00000004 * (float)val);
}




/* [AUDIT] proposed: pow2MulDiv  (confidence: high)
 * purpose: Helper: returns 2^a * 2^b / 2^c for stat scaling
 * vars: -
 */
/* Global::pow2MulDiv @ 00410f90 */

float10 pow2MulDiv(void)

{
  double val;
  float fStack00000004;
  
  val = 2.0;
  libm_sse2_pow_precise();
  fStack00000004 = (float)val;
  val = 2.0;
  libm_sse2_pow_precise();
  fStack00000004 = fStack00000004 * (float)val;
  val = 2.0;
  libm_sse2_pow_precise();
  return (float10)(fStack00000004 / (float)val);
}




/* [AUDIT] proposed: Combat_upsertBuffEntry  (confidence: high)
 * purpose: Updates existing buff of same type in list at 0x1178 or appends a new 0x20-byte node; guards list length
 * vars: this+0x1178=buff list; +0x117c=count; param_1=buff record (type at +8)
 */
/* Global::Combat_upsertBuffEntry @ 00411740 */

void __thiscall Combat_upsertBuffEntry(void *this,char *buff)

{
  char cVar1;
  undefined4 *node;
  int new_node;
  
  cVar1 = *buff;
  if (((((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) ||
      ((cVar1 == '\x06' || (cVar1 == '\a')))) ||
     ((cVar1 == '\t' || ((cVar1 == '\n' || (cVar1 == '\v')))))) {
    for (node = (undefined4 *)**(undefined4 **)((int)this + 0x1178);
        node != *(undefined4 **)((int)this + 0x1178); node = (undefined4 *)*node) {
      if (*(char *)(node + 2) == cVar1) {
        *(undefined8 *)(node + 2) = *(undefined8 *)buff;
        *(undefined8 *)(node + 4) = *(undefined8 *)(buff + 8);
        *(undefined8 *)(node + 6) = *(undefined8 *)(buff + 0x10);
        return;
      }
    }
  }
  node = *(undefined4 **)((int)this + 0x1178);
  new_node = list_emplaceCopy24(node,(undefined4 *)node[1],(undefined8 *)buff);
  if (*(int *)((int)this + 0x117c) != 0x7fffffe) {
    *(int *)((int)this + 0x117c) = *(int *)((int)this + 0x117c) + 1;
    node[1] = new_node;
    **(int **)(new_node + 4) = new_node;
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("list<T> too long");
}




/* [AUDIT] proposed: ostream_writeCString  (confidence: high)
 * purpose: std::operator<<(ostream&, const char*): pads/writes a C string honoring width/fill, sets state on error
 * vars: buff=ostream; param_2=C string; ostream+0x20/0x24=width; +0x38=streambuf
 */
/* Global::ostream_writeCString @ 00412710 */

basic_ostream<char,std::char_traits<char>_> *
ostream_writeCString(basic_ostream<char,std::char_traits<char>_> *param_1,char *str)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  basic_ostream<char,std::char_traits<char>_> *pbVar6;
  uint len;
  char *pcVar8;
  int extraout_ECX;
  int extraout_ECX_00;
  int vtoff;
  int extraout_ECX_01;
  bool bVar10;
  __int64 _Var11;
  int pad_lo;
  int pad_hi;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bb20;
  local_10 = ExceptionList;
  uVar4 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar3 = false;
  if (*str == '\0') {
    len = 0;
  }
  else {
    pcVar8 = str;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    len = (int)pcVar8 - (int)(str + 1);
  }
  vtoff = *(int *)(*(int *)param_1 + 4);
  pad_hi = *(int *)(param_1 + vtoff + 0x24);
  uVar2 = *(uint *)(param_1 + vtoff + 0x20);
  if ((pad_hi < 0) ||
     ((pad_hi < 1 && (((uVar2 == 0 || (pad_hi < 0)) || ((pad_hi < 1 && (uVar2 <= len)))))
      ))) {
    pad_hi = 0;
    pad_lo = 0;
  }
  else {
    pad_lo = uVar2 - len;
    pad_hi = pad_hi - (uint)(uVar2 < len);
  }
  if (*(int **)(param_1 + vtoff + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + vtoff + 0x38) + 4))();
  }
  local_8 = 0;
  if ((*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) == 0) &&
     (*(basic_ostream<char,std::char_traits<char>_> **)
       (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c) !=
      (basic_ostream<char,std::char_traits<char>_> *)0x0)) {
    std::basic_ostream<char,std::char_traits<char>_>::flush
              (*(basic_ostream<char,std::char_traits<char>_> **)
                (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c));
  }
  vtoff = *(int *)(*(int *)param_1 + 4);
  local_8 = 1;
  if (*(int *)(param_1 + vtoff + 0xc) != 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(param_1 + *(int *)(*(int *)param_1 + 4)),
               4,false);
    local_8 = 0xffffffff;
    bVar3 = std::uncaught_exception();
    if (!bVar3) {
      std::basic_ostream<char,std::char_traits<char>_>::_Osfx(param_1);
    }
    if (*(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_8 = 2;
  if ((*(uint *)(param_1 + vtoff + 0x14) & 0x1c0) != 0x40) {
    while( true ) {
      if ((pad_hi < 0) || ((pad_hi < 1 && (pad_lo == 0)))) goto LAB_00412834;
      iVar5 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                        (*(basic_streambuf<char,std::char_traits<char>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                         (char)param_1[*(int *)(*(int *)param_1 + 4) + 0x40]);
      vtoff = extraout_ECX;
      if (iVar5 == -1) break;
      bVar10 = pad_lo != 0;
      pad_lo = pad_lo + -1;
      pad_hi = pad_hi + -1 + (uint)bVar10;
    }
    bVar3 = true;
LAB_00412834:
    if (bVar3) goto LAB_004128a3;
  }
  _Var11 = std::basic_streambuf<char,std::char_traits<char>_>::sputn
                     (*(basic_streambuf<char,std::char_traits<char>_> **)
                       (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),str,
                      (ulonglong)uVar4 << 0x20);
  vtoff = extraout_ECX_00;
  if (((uint)_Var11 == len) && ((int)((ulonglong)_Var11 >> 0x20) == 0)) {
    while ((-1 < pad_hi &&
           (((0 < pad_hi || (pad_lo != 0)) &&
            (iVar5 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                               (*(basic_streambuf<char,std::char_traits<char>_> **)
                                 (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                                (char)param_1[*(int *)(*(int *)param_1 + 4) + 0x40]),
            vtoff = extraout_ECX_01, iVar5 != -1))))) {
      bVar3 = pad_lo != 0;
      pad_lo = pad_lo + -1;
      pad_hi = pad_hi + -1 + (uint)bVar3;
    }
  }
LAB_004128a3:
  iVar5 = *(int *)(*(int *)param_1 + 4);
  *(undefined4 *)(param_1 + iVar5 + 0x20) = 0;
  *(undefined4 *)(param_1 + iVar5 + 0x24) = 0;
  pbVar6 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writeCleanupHandler(vtoff,(int *)param_1);
  return pbVar6;
}




/* [AUDIT] proposed: ostream_writeCleanupHandler  (confidence: med)
 * purpose: Exception-unwind/finally handler for ostream_writeCString: setstate, _Osfx, restore ExceptionList
 * vars: uses unaff_EBP frame of caller; str=ostream vtbl
 */
/* Global::ostream_writeCleanupHandler @ 004128da */

undefined4 __fastcall ostream_writeCleanupHandler(undefined4 param_1,int *param_2)

{
  basic_ostream<char,std::char_traits<char>_> *this;
  bool bVar1;
  int unaff_EBP;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)(*(int *)(*param_2 + 4) + (int)param_2),
             unaff_EDI,false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  bVar1 = std::uncaught_exception();
  this = *(basic_ostream<char,std::char_traits<char>_> **)(unaff_EBP + -0x24);
  if (!bVar1) {
    std::basic_ostream<char,std::char_traits<char>_>::_Osfx(this);
  }
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}




/* [AUDIT] proposed: string_dataPtr  (confidence: high)
 * purpose: std::string data accessor: returns heap buffer *param_1 if capacity(>=0x10) else inline SSO buffer
 * vars: param_1=string; [5]=capacity
 */
/* Global::string_dataPtr @ 00412c40 */

undefined4 * __fastcall string_dataPtr(undefined4 *str)

{
  if (0xf < (uint)str[5]) {
    return (undefined4 *)*str;
  }
  return str;
}




/* [AUDIT] proposed: SpeechDb_readBlobByKey  (confidence: high)
 * purpose: SELECT value FROM blobs WHERE key=?: binds key, steps, copies BLOB into out buffer
 * vars: this+4=db; str=key; param_2=out data ptr; param_3=out size
 */
/* Global::SpeechDb_readBlobByKey @ 00413070 */

uint __thiscall SpeechDb_readBlobByKey(void *this,undefined4 *key,uint *out_ptr,uint *out_len)

{
  uint *puVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint rc;
  void *_Src;
  size_t sVar6;
  
  puVar1 = out_ptr;
  *out_ptr = 0;
  *out_len = 0;
  do {
    puVar3 = (undefined *)
             sqlite3_prepare(*(int *)((int)this + 4),"SELECT value FROM blobs WHERE key = ?",0xffffffff
                          ,&out_ptr,(int *)0x0);
    if (puVar3 != (undefined *)0x0) break;
    sVar6 = 0xffffffff;
    puVar4 = string_dataPtr(key);
    sqlite3_bind_text((int *)out_ptr,1,puVar4,sVar6,puVar3);
    rc = sqlite3_step_469cb0(out_ptr);
    if (rc == 100) {
      rc = sqlite3_column_bytes((int *)out_ptr,0);
      puVar2 = out_len;
      *out_len = rc;
      rc = operator_new_wrapper(rc);
      *puVar1 = rc;
      rc = *puVar2;
      _Src = (void *)sqlite3_column_int((int *)out_ptr,0);
      memcpy((void *)*puVar1,_Src,rc);
      rc = sqlite3_clear_bindings_46aa30((int *)out_ptr);
      return CONCAT31((int3)(rc >> 8),1);
    }
    puVar3 = (undefined *)sqlite3_clear_bindings_46aa30((int *)out_ptr);
  } while (puVar3 == (undefined *)0x11);
  return (uint)puVar3 & 0xffffff00;
}




/* [AUDIT] proposed: SpeechDb_loadBlobToVector  (confidence: high)
 * purpose: Loads a blob by key via readBlobByKey then resizes dest vector and memcpy's the bytes
 * vars: this=db; key=key; out_ptr=dest vector
 */
/* Global::SpeechDb_loadBlobToVector @ 00413130 */

undefined4 __thiscall SpeechDb_loadBlobToVector(void *this,undefined4 *key,undefined4 *out_vec)

{
  undefined4 uVar1;
  void *pvVar2;
  void *blob_ptr;
  uint blob_len;
  
  uVar1 = SpeechDb_readBlobByKey(this,key,(uint *)&blob_ptr,&blob_len);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  out_vec[3] = 0;
  vector_resizeZero(out_vec,blob_len);
  pvVar2 = memcpy((void *)*out_vec,blob_ptr,blob_len);
  return CONCAT31((int3)((uint)pvVar2 >> 8),1);
}




/* [AUDIT] proposed: struct_copy0x118  (confidence: high)
 * purpose: Copies a 0x118-byte record field-by-field (header + 0x20 array of 8-byte entries + tail)
 * vars: this=dst; key=src; loop over 0x20 8-byte entries
 */
/* Global::struct_copy0x118 @ 00413710 */

undefined1 * __thiscall struct_copy0x118(void *this,undefined1 *src)

{
  undefined1 *dst_ptr;
  undefined1 *src_ptr;
  int count;
  
  *(undefined1 *)this = *src;
  *(undefined1 *)((int)this + 1) = src[1];
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(src + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(src + 8);
  *(undefined1 *)((int)this + 0xc) = src[0xc];
  *(undefined1 *)((int)this + 0xd) = src[0xd];
  *(undefined1 *)((int)this + 0xe) = src[0xe];
  *(undefined2 *)((int)this + 0x10) = *(undefined2 *)(src + 0x10);
  count = 0x1f;
  src_ptr = src + 0x17;
  dst_ptr = (undefined1 *)((int)this + 0x16);
  do {
    count = count + -1;
    dst_ptr[-2] = src_ptr[-3];
    dst_ptr[-1] = src_ptr[-2];
    *dst_ptr = dst_ptr[(int)src - (int)this];
    dst_ptr[1] = *src_ptr;
    *(undefined4 *)(dst_ptr + 2) = *(undefined4 *)(src_ptr + 1);
    src_ptr = src_ptr + 8;
    dst_ptr = dst_ptr + 8;
  } while (-1 < count);
  *(undefined4 *)((int)this + 0x114) = *(undefined4 *)(src + 0x114);
  return this;
}




/* [AUDIT] proposed: Combat_equipHealthBonus  (confidence: high)
 * purpose: Computes a health/stat bonus from an equipment slot (rarity+type), scaled by 2^*5*factor; 0 if slot empty
 * vars: src=slot (type at [0], id at +4, subtype at 0xd)
 */
/* Global::Combat_equipHealthBonus @ 00413ce0 */

float10 __fastcall Combat_equipHealthBonus(char *item)

{
  char cVar1;
  float10 fVar2;
  float multiplier;
  float factor;
  
  cVar1 = *item;
  if ((((cVar1 != '\x03') && (cVar1 != '\x04')) && (cVar1 != '\a')) &&
     ((cVar1 != '\x05' && (cVar1 != '\x06')))) {
    return (float10)0;
  }
  multiplier = 0.5;
  if (cVar1 == '\x04') {
    multiplier = 1.0;
  }
  cVar1 = item[0xd];
  factor = (1.0 - ((float)(int)((ulonglong)(uint)(*(int *)(item + 4) << 3) % 0x15) + 0.0) / 20.0
            ) + 1.0;
  if (cVar1 == '\x01') {
    factor = factor + 1.0;
  }
  else if (cVar1 == '\x1a') {
    factor = factor + 0.5;
  }
  else if (cVar1 == '\x1b') {
    factor = factor + 0.75;
  }
  fVar2 = pow2Mul();
  return (float10)((float)fVar2 * 5.0 * multiplier * factor);
}




/* [AUDIT] proposed: malloc_thunk  (confidence: high)
 * purpose: Tail-jump thunk to malloc (jumptable via indirect jump)
 * vars: item=size
 */
/* Global::malloc_thunk @ 00416930 */

void malloc_thunk(size_t size)

{
                    /* WARNING: Could not recover jumptable at 0x00416934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  malloc(size);
  return;
}




/* [AUDIT] proposed: utf32_to_utf16  (confidence: high)
 * purpose: Converts a UTF-32 buffer to UTF-16: counts units (surrogate pairs for >=0x10000), allocates, converts
 * vars: param_3=UTF-32 src; param_4=byte len; size=out buf; param_2=out count
 */
/* Global::utf32_to_utf16 @ 00416950 */

undefined4 __cdecl utf32_to_utf16(undefined4 *out_buf,int *out_len,uint *src,uint byte_len)

{
  uint *puVar1;
  int iVar2;
  ushort *puVar3;
  int char_count;
  
  char_count = 0;
  for (puVar1 = src; puVar1 < src + (byte_len >> 2); puVar1 = puVar1 + 1) {
    if (*puVar1 < 0x10000) {
      char_count = char_count + 1;
    }
    else {
      char_count = char_count + 2;
    }
  }
  *out_len = char_count;
  iVar2 = 1;
  if (char_count != 0) {
    iVar2 = char_count;
  }
  puVar3 = (ushort *)(*(code *)PTR_FUN_00582198)(iVar2 * 2);
  *out_buf = puVar3;
  if (puVar3 == (ushort *)0x0) {
    return 0;
  }
  puVar3 = Utf32_toUtf16(src,byte_len >> 2,puVar3);
  return CONCAT31((int3)((uint)puVar3 >> 8),1);
}




/* [AUDIT] proposed: utf_convert_variant  (confidence: high)
 * purpose: Counts output length (00417890) then allocates and converts a UTF buffer (variant encoding)
 * vars: src=src; byte_len=byte len; out_buf=out buf; out_len=out count
 */
/* Global::utf_convert_variant @ 004169c0 */

undefined4 __cdecl utf_convert_variant(undefined4 *out_buf,int *out_len,uint *src,uint byte_len)

{
  int char_count;
  int iVar2;
  ushort *puVar3;
  
  char_count = Utf32BE_countUtf16Units(src,byte_len >> 2,0);
  iVar2 = 1;
  if (char_count != 0) {
    iVar2 = char_count;
  }
  *out_len = char_count;
  puVar3 = (ushort *)(*(code *)PTR_FUN_00582198)(iVar2 * 2);
  *out_buf = puVar3;
  if (puVar3 == (ushort *)0x0) {
    return 0;
  }
  puVar3 = Utf32BE_toUtf16(src,byte_len >> 2,puVar3);
  return CONCAT31((int3)((uint)puVar3 >> 8),1);
}




/* [AUDIT] proposed: std::string::string(string&&)  (confidence: high)
 * purpose: SSO(16) move-construct std::basic_string<char>, steals heap ptr, resets source
 * vars: this=dst,out_buf=src str
 */
/* Global::std_string_string_string @ 00416a20 */

undefined4 * __thiscall std_string_string_string(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)this = 0;
  if ((uint)param_1[5] < 0x10) {
    if (param_1[4] + 1 != 0) {
      memmove(this,param_1,param_1[4] + 1);
    }
  }
  else {
    *(undefined4 *)this = *param_1;
    *param_1 = 0;
  }
  *(undefined4 *)((int)this + 0x10) = param_1[4];
  *(undefined4 *)((int)this + 0x14) = param_1[5];
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return this;
}




/* [AUDIT] proposed: Pool_allocBlock  (confidence: med)
 * purpose: Pool allocator: gets a node sized by param_1 (small vs >0x2000 large lists), links it, returns data ptr (+0x18)
 * vars: this+0/+4/+8=pool list heads; param_2=out node; returns node+0x18
 */
/* Global::Pool_allocBlock @ 00416ef0 */

int __thiscall Pool_allocBlock(void *this,uint size,int *out_block)

{
  uint alloc_size;
  int block;
  
  alloc_size = size;
  if (size < 0x2001) {
    alloc_size = 0x8000;
  }
  block = Pool_mallocAlignedBlock(this,alloc_size);
  if (block == 0) {
    return 0;
  }
  if (size < 0x2001) {
    *(undefined4 *)(*(int *)this + 0x10) = *(undefined4 *)((int)this + 4);
    *(undefined4 *)(block + 8) = *(undefined4 *)this;
    *(int *)(*(int *)this + 0xc) = block;
    *(uint *)((int)this + 4) = size;
    *(int *)this = block;
    *(uint *)(block + 0x10) = size;
    *out_block = block;
    return block + 0x18;
  }
  *(undefined4 *)(block + 8) = *(undefined4 *)(*(int *)this + 8);
  *(undefined4 *)(block + 0xc) = *(undefined4 *)this;
  *(int *)(*(int *)(*(int *)this + 8) + 0xc) = block;
  *(int *)(*(int *)this + 8) = block;
  *(uint *)(block + 0x10) = size;
  *out_block = block;
  return block + 0x18;
}




/* [AUDIT] proposed: Pool_allocElementNode  (confidence: med)
 * purpose: Allocates a 0x20-byte node from pool (inline if room in current 0x8000 block else spill), zero-inits, tags with out_block
 * vars: size[0]=block base; size[1]=offset; out_block=node type tag ORed into puVar2[0]
 */
/* Global::Pool_allocElementNode @ 00416f80 */

uint * __cdecl Pool_allocElementNode(int *param_1,uint flags)

{
  uint new_off;
  uint *node;
  int *pool;
  
  new_off = param_1[1] + 0x20;
  if (new_off < 0x8001) {
    pool = (int *)*param_1;
    node = (uint *)(param_1[1] + 0x18 + (int)pool);
    param_1[1] = new_off;
  }
  else {
    node = (uint *)Pool_allocBlock(param_1,0x20,(int *)&param_1);
    pool = param_1;
  }
  if (node != (uint *)0x0) {
    node[1] = 0;
    *node = (uint)pool | flags;
    node[2] = 0;
    node[3] = 0;
    node[4] = 0;
    node[5] = 0;
    node[6] = 0;
    node[7] = 0;
    return node;
  }
  return (uint *)0x0;
}




/* [AUDIT] proposed: Pool_mallocAlignedBlock  (confidence: med)
 * purpose: Requests a memory block (size+0x38) via PTR_FUN_00582198 malloc, aligns to 32 bytes, links into pool chain
 * vars: this[0]=chain; PTR_FUN_00582198=allocator fn; align &0xffffffe0
 */
/* Global::Pool_mallocAlignedBlock @ 00417000 */

void __thiscall Pool_mallocAlignedBlock(void *this,int size)

{
  int raw;
  undefined4 *page;
  
  raw = (*(code *)PTR_FUN_00582198)(size + 0x38);
  if (raw == 0) {
    return;
  }
  page = (undefined4 *)(raw + 0x1fU & 0xffffffe0);
  if (page == (undefined4 *)0x0) {
    iRam00000004 = raw;
    uRam00000000 = **(undefined4 **)this;
    return;
  }
  *page = 0;
  page[1] = 0;
  page[2] = 0;
  page[3] = 0;
  page[4] = 0;
  page[5] = 0;
  page[1] = raw;
  *page = **(undefined4 **)this;
  return;
}




/* [AUDIT] proposed: encodeUtf16Codepoint  (confidence: high)
 * purpose: Encodes one Unicode codepoint to UTF-16: direct if <0x10000 else surrogate pair; returns advanced ptr
 * vars: size=out buf; param_2=codepoint; 0xd800/0xdc00 surrogates
 */
/* Global::encodeUtf16Codepoint @ 00417070 */

ushort * __cdecl encodeUtf16Codepoint(ushort *out,uint codepoint)

{
  if (codepoint < 0x10000) {
    *out = (ushort)codepoint;
    return out + 1;
  }
  *out = (short)(codepoint - 0x10000 >> 10) + 0xd800;
  out[1] = ((ushort)codepoint & 0x3ff) + 0xdc00;
  return out + 2;
}




/* [AUDIT] proposed: XmlPool_allocAttrNode  (confidence: med)
 * purpose: Allocates 0x14-byte attribute node from pool and links into element's attr list (out+0x1c)
 * vars: out+0x1c=attr list head; node+0x10=next,+0xc=prev-ish
 */
/* Global::XmlPool_allocAttrNode @ 00417230 */

int * __cdecl XmlPool_allocAttrNode(int element,int *pool)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *node;
  int *pool_base;
  
  uVar1 = pool[1] + 0x14;
  if (uVar1 < 0x8001) {
    pool_base = (int *)*pool;
    node = (int *)(pool[1] + 0x18 + (int)pool_base);
    pool[1] = uVar1;
  }
  else {
    node = (int *)Pool_allocBlock(pool,0x14,(int *)&pool);
    pool_base = pool;
  }
  if (node != (int *)0x0) {
    *node = (int)pool_base;
    node[1] = 0;
    node[2] = 0;
    node[3] = 0;
    node[4] = 0;
    iVar2 = *(int *)(element + 0x1c);
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0xc);
      *(int **)(iVar3 + 0x10) = node;
      node[3] = iVar3;
      *(int **)(iVar2 + 0xc) = node;
      return node;
    }
    *(int **)(element + 0x1c) = node;
    node[3] = (int)node;
    return node;
  }
  return (int *)0x0;
}




/* [AUDIT] proposed: XmlPool_allocChildNode  (confidence: med)
 * purpose: Allocates node via Pool_allocElementNode and links as child into parent's child list (element+0x10)
 * vars: element+0x10=child list; puVar3[5]=sibling link; param_3=node type
 */
/* Global::XmlPool_allocChildNode @ 004172b0 */

uint * __cdecl XmlPool_allocChildNode(uint parent,int *pool,uint flags)

{
  int iVar1;
  uint uVar2;
  uint *node;
  
  node = Pool_allocElementNode(pool,flags);
  if (node == (uint *)0x0) {
    return (uint *)0x0;
  }
  node[1] = parent;
  iVar1 = *(int *)(parent + 0x10);
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    *(uint **)(uVar2 + 0x18) = node;
    node[5] = uVar2;
    *(uint **)(iVar1 + 0x14) = node;
    return node;
  }
  *(uint **)(parent + 0x10) = node;
  node[5] = (uint)node;
  return node;
}




/* [AUDIT] proposed: Transcode_dispatch  (confidence: high)
 * purpose: Dispatches byte-buffer to UTF-16 conversion by encoding id: 1=UTF8,2/5=UTF32,3=UTF16BE,6=UTF16LE swap
 * vars: flags=encoding id; routes to Utf16_copyOrPassthrough/730/790/416950/4169c0
 */
/* Global::Transcode_dispatch @ 00417680 */

uint __cdecl
Transcode_dispatch(int *out,uint *out_len,uint encoding,uint *src,uint len,char inplace)

{
  uint uVar1;
  
  if (encoding == 2) {
    uVar1 = Utf16_copyOrPassthrough(out,out_len,src,len,inplace);
    return uVar1;
  }
  if (encoding == 3) {
    uVar1 = Utf16BE_byteSwapToNative(out,out_len,(int)src,len,inplace);
    return uVar1;
  }
  if (encoding != 5) {
    if (encoding == 1) {
      uVar1 = Utf8_toUtf16Alloc(out,(int *)out_len,src,len);
      return uVar1;
    }
    if (encoding == 6) {
      uVar1 = utf_convert_variant(out,(int *)out_len,src,len);
      return uVar1;
    }
    if (encoding != 5) {
      return encoding & 0xffffff00;
    }
  }
  uVar1 = utf32_to_utf16(out,(int *)out_len,src,len);
  return uVar1;
}




/* [AUDIT] proposed: Utf16BE_byteSwapToNative  (confidence: high)
 * purpose: Converts UTF-16BE buffer to native by byte-swapping each unit; allocates dest unless len in-place
 * vars: encoding=src; src=byte count; len=in-place flag; PTR_FUN_00582198=malloc
 */
/* Global::Utf16BE_byteSwapToNative @ 00417730 */

undefined4 __cdecl Utf16BE_byteSwapToNative(int *out,uint *out_len,int src,uint byte_len,char inplace)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int char_count;
  
  if (inplace == '\0') {
    uVar3 = 1;
    if (byte_len != 0) {
      uVar3 = byte_len;
    }
    char_count = (*(code *)PTR_FUN_00582198)(uVar3);
    *out = char_count;
    if (char_count == 0) {
      return 0;
    }
  }
  else {
    *out = src;
  }
  uVar3 = byte_len >> 1;
  *out_len = uVar3;
  puVar2 = (ushort *)*out;
  if (uVar3 != 0) {
    char_count = src - (int)puVar2;
    do {
      uVar1 = *(ushort *)(char_count + (int)puVar2);
      uVar1 = uVar1 << 8 | uVar1 >> 8;
      out_len = (uint *)(uint)uVar1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return CONCAT31((int3)((uint)out_len >> 8),1);
}




/* [AUDIT] proposed: Utf8_toUtf16Alloc  (confidence: high)
 * purpose: UTF-8 to UTF-16: counts units (Utf8_countUtf16Units), allocates buffer, decodes (Utf8_decodeToUtf16)
 * vars: src=UTF8 src; byte_len=byte len; out_len=out unit count
 */
/* Global::Utf8_toUtf16Alloc @ 00417790 */

undefined4 __cdecl Utf8_toUtf16Alloc(undefined4 *out,int *out_len,uint *src,uint byte_len)

{
  int char_count;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  char_count = Utf8_countUtf16Units(src,byte_len,0);
  iVar2 = 1;
  if (char_count != 0) {
    iVar2 = char_count;
  }
  *out_len = char_count;
  puVar3 = (ushort *)(*(code *)PTR_FUN_00582198)(iVar2 * 2);
  *out = puVar3;
  if (puVar3 == (ushort *)0x0) {
    return 0;
  }
  uVar4 = Utf8_decodeToUtf16(src,byte_len,puVar3);
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}




/* [AUDIT] proposed: Utf32BE_countUtf16Units  (confidence: high)
 * purpose: Counts UTF-16 units needed for a byte-swapped UTF-32 buffer (2 for >=0x10000 else 1)
 * vars: out=UTF32 src; out_len=count; src=running total; byteswap inline
 */
/* Global::Utf32BE_countUtf16Units @ 00417890 */

int __cdecl Utf32BE_countUtf16Units(uint *src,int count,int total)

{
  uint *puVar1;
  uint cp;
  
  puVar1 = src + count;
  if (puVar1 <= src) {
    return total;
  }
  do {
    cp = *src;
    if (((cp & 0xff0000 | cp >> 0x10) >> 8 | (cp & 0xff00 | cp << 0x10) << 8) < 0x10000)
    {
      total = total + 1;
    }
    else {
      total = total + 2;
    }
    src = src + 1;
  } while (src < puVar1);
  return total;
}




/* [AUDIT] proposed: Utf32_toUtf16  (confidence: high)
 * purpose: Converts UTF-32 (native) buffer to UTF-16 with surrogate encoding
 * vars: src=UTF32 src; count=count; total=out UTF-16 ptr
 */
/* Global::Utf32_toUtf16 @ 004178f0 */

ushort * __cdecl Utf32_toUtf16(uint *src,int count,ushort *out)

{
  uint *puVar1;
  uint cp;
  
  puVar1 = src + count;
  if (puVar1 <= src) {
    return out;
  }
  do {
    cp = *src;
    if (cp < 0x10000) {
      *out = (ushort)cp;
      out = out + 1;
    }
    else {
      *out = (short)(cp - 0x10000 >> 10) + 0xd800;
      out[1] = ((ushort)cp & 0x3ff) + 0xdc00;
      out = out + 2;
    }
    src = src + 1;
  } while (src < puVar1);
  return out;
}




/* [AUDIT] proposed: Utf32BE_toUtf16  (confidence: high)
 * purpose: Converts byte-swapped UTF-32BE buffer to UTF-16 with surrogate encoding
 * vars: src=src; count=count; out=out; inline byteswap
 */
/* Global::Utf32BE_toUtf16 @ 00417950 */

ushort * __cdecl Utf32BE_toUtf16(uint *src,int count,ushort *out)

{
  uint *puVar1;
  ushort hi;
  uint uVar3;
  uint cp;
  
  puVar1 = src + count;
  if (puVar1 <= src) {
    return out;
  }
  do {
    cp = *src;
    uVar3 = cp & 0xff0000 | cp >> 0x10;
    cp = uVar3 >> 8 | (cp & 0xff00 | cp << 0x10) << 8;
    hi = (ushort)(uVar3 >> 8);
    if (cp < 0x10000) {
      *out = hi;
      out = out + 1;
    }
    else {
      *out = (short)(cp - 0x10000 >> 10) + 0xd800;
      out[1] = (hi & 0x3ff) + 0xdc00;
      out = out + 2;
    }
    src = src + 1;
  } while (src < puVar1);
  return out;
}




/* [AUDIT] proposed: Utf8_countUtf16Units  (confidence: high)
 * purpose: Counts UTF-16 units for a UTF-8 byte buffer; validates 1-4 byte sequences, ASCII fast-path via word mask
 * vars: src=UTF8 bytes; count=byte count; out=accumulator; 0x80808080 ASCII test
 */
/* Global::Utf8_countUtf16Units @ 004179e0 */

int __cdecl Utf8_countUtf16Units(uint *src,uint byte_len,int total)

{
  uint lead;
  
  if (byte_len == 0) {
    return total;
  }
  do {
    if ((byte)*src < 0x80) {
      src = (uint *)((int)src + 1);
      total = total + 1;
      byte_len = byte_len - 1;
      if (((uint)src & 3) == 0) {
        for (; (3 < byte_len && ((*src & 0x80808080) == 0)); src = src + 1) {
          byte_len = byte_len - 4;
          total = total + 4;
        }
      }
    }
    else {
      lead = (uint)(byte)*src;
      if (((lead - 0xc0 < 0x20) && (1 < byte_len)) && ((*src & 0xc000) == 0x8000)) {
        total = total + 1;
        src = (uint *)((int)src + 2);
        byte_len = byte_len - 2;
      }
      else if (((lead - 0xe0 < 0x10) && (2 < byte_len)) &&
              (((*src & 0xc000) == 0x8000 && ((*src & 0xc00000) == 0x800000)))) {
        total = total + 1;
        src = (uint *)((int)src + 3);
        byte_len = byte_len - 3;
      }
      else if (((lead - 0xf0 < 8) && (3 < byte_len)) &&
              (((*src & 0xc000) == 0x8000 &&
               (((*src & 0xc00000) == 0x800000 && ((*src & 0xc0000000) == 0x80000000)))))) {
        total = total + 2;
        src = src + 1;
        byte_len = byte_len - 4;
      }
      else {
        src = (uint *)((int)src + 1);
        byte_len = byte_len - 1;
      }
    }
  } while (byte_len != 0);
  return total;
}




/* [AUDIT] proposed: Utf8_decodeToUtf16  (confidence: high)
 * purpose: Full UTF-8 to UTF-16 decoder: handles 1-4 byte seqs and surrogate emission, ASCII word fast-path
 * vars: src=UTF8 src; byte_len=byte count; total=UTF-16 out
 */
/* Global::Utf8_decodeToUtf16 @ 00417ae0 */

void __cdecl Utf8_decodeToUtf16(uint *src,uint byte_len,ushort *out)

{
  byte lead;
  uint uVar2;
  uint uVar3;
  
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if (byte_len == 0) {
              return;
            }
            lead = (byte)*src;
            if (0x7f < lead) break;
            *out = (ushort)lead;
            src = (uint *)((int)src + 1);
            out = out + 1;
            byte_len = byte_len - 1;
            if (((uint)src & 3) == 0) {
              for (; (3 < byte_len && ((*src & 0x80808080) == 0)); src = src + 1) {
                *out = (ushort)(byte)*src;
                out[1] = (ushort)*(byte *)((int)src + 1);
                out[2] = (ushort)*(byte *)((int)src + 2);
                out[3] = (ushort)*(byte *)((int)src + 3);
                byte_len = byte_len - 4;
                out = out + 4;
              }
            }
          }
          uVar3 = (uint)lead;
          if (((0x1f < uVar3 - 0xc0) || (byte_len < 2)) ||
             (uVar2 = CONCAT11(*(byte *)((int)src + 1),*(byte *)((int)src + 1)) & 0xffffffc0
             , (char)uVar2 != -0x80)) break;
          *out = (lead & 0x3f) << 6 | (ushort)((byte)(uVar2 >> 8) & 0x3f);
          src = (uint *)((int)src + 2);
          byte_len = byte_len - 2;
          out = out + 1;
        }
        if (((0xf < uVar3 - 0xe0) || (byte_len < 3)) ||
           ((uVar2 = CONCAT11(*(byte *)((int)src + 1),*(byte *)((int)src + 1)) & 0xffffffc0,
            (char)uVar2 != -0x80 ||
            (uVar2 = CONCAT31((int3)(uVar2 >> 8),*(byte *)((int)src + 2)) & 0xffffffc0,
            (char)uVar2 != -0x80)))) break;
        *out = ((CONCAT11((char)(uVar2 >> 8),lead) & 0x3fff) >> 8 | (ushort)lead << 6) << 6 |
                   (ushort)(*(byte *)((int)src + 2) & 0x3f);
        src = (uint *)((int)src + 3);
        byte_len = byte_len - 3;
        out = out + 1;
      }
      if (((uVar3 - 0xf0 < 8) && (3 < byte_len)) && ((*(byte *)((int)src + 1) & 0xc0) == 0x80))
      break;
LAB_00417ca8:
      src = (uint *)((int)src + 1);
      byte_len = byte_len - 1;
    }
    if (((*(byte *)((int)src + 2) & 0xc0) != 0x80) ||
       ((*(byte *)((int)src + 3) & 0xc0) != 0x80)) goto LAB_00417ca8;
    uVar2 = *(byte *)((int)src + 3) & 0x3f;
    uVar3 = (((uVar3 & 0xffffff0f) << 6 | *(byte *)((int)src + 1) & 0x3f) << 6 |
            *(byte *)((int)src + 2) & 0x3f) << 6;
    *out = (short)((uVar3 | uVar2) - 0x10000 >> 10) + 0xd800;
    out[1] = ((ushort)uVar3 & 0x3ff | (ushort)uVar2) + 0xdc00;
    src = src + 1;
    byte_len = byte_len - 4;
    out = out + 2;
  } while( true );
}




/* [AUDIT] proposed: Xml_detectEncoding  (confidence: high)
 * purpose: Detects text encoding from BOM and <?xml prefix bytes; returns encoding id (1 UTF8,2/3 UTF16,5/6 UTF32)
 * vars: src=hint id; byte_len=byte buf; out=len; matches FEFF/FFFE/00 00 FE FF, '<?xm'
 */
/* Global::Xml_detectEncoding @ 00417e40 */

int __cdecl Xml_detectEncoding(int encoding,char *data,uint len)

{
  char first;
  
  if ((encoding == 8) || (encoding == 4)) {
    return 2;
  }
  if (encoding == 7) {
    return 5;
  }
  if (encoding != 0) {
    return encoding;
  }
  if (4 < len) {
    if ((((*data == '\0') && (data[1] == '\0')) && (data[2] == -2)) && (data[3] == -1))
    {
      return 6;
    }
    if (((*data == -1) && (data[1] == -2)) && ((data[2] == '\0' && (data[3] == '\0'))))
    {
      return 5;
    }
  }
  if (2 < len) {
    if ((*data == -2) && (data[1] == -1)) {
      return 3;
    }
    if ((*data == -1) && (data[1] == -2)) {
      return 2;
    }
  }
  if ((((len < 4) || (*data != -0x11)) || (data[1] != -0x45)) || (data[2] != -0x41)) {
    if (4 < len) {
      first = *data;
      if (((first == '\0') && (data[1] == '\0')) && ((data[2] == '\0' && (data[3] == '<')))
         ) {
        return 6;
      }
      if (((first == '<') && (data[1] == '\0')) && ((data[2] == '\0' && (data[3] == '\0')))
         ) {
        return 5;
      }
      if ((((first == '\0') && (data[1] == '<')) && (data[2] == '\0')) && (data[3] == '?'))
      {
        return 3;
      }
      if (first == '<') {
        if (((data[1] == '\0') && (data[2] == '?')) && (data[3] == '\0')) {
          return 2;
        }
        if (((data[1] == '?') && (data[2] == 'x')) && (data[3] == 'm')) {
          return 1;
        }
      }
    }
    if (2 < len) {
      if ((*data == '\0') && (data[1] == '<')) {
        return 3;
      }
      if ((*data == '<') && (data[1] == '\0')) {
        return 2;
      }
    }
  }
  return 1;
}




/* [AUDIT] proposed: Utf16_copyOrPassthrough  (confidence: med)
 * purpose: UTF-16 native path: in-place (param_5 set) or malloc+memcpy of buffer; sets unit count = bytes>>1
 * vars: len=src; param_4=byte len; param_5=in-place flag
 */
/* Global::Utf16_copyOrPassthrough @ 00417f90 */

undefined4 __cdecl
Utf16_copyOrPassthrough(undefined4 *out,uint *out_len,void *src,uint byte_len,char inplace)

{
  undefined3 uVar2;
  uint uVar1;
  void *_Dst;
  
  uVar2 = (undefined3)((uint)out_len >> 8);
  if (inplace != '\0') {
    *out = src;
    *out_len = byte_len >> 1;
    return CONCAT31(uVar2,1);
  }
  uVar1 = 1;
  if (byte_len != 0) {
    uVar1 = byte_len;
  }
  _Dst = (void *)(*(code *)PTR_FUN_00582198)(uVar1);
  if (_Dst == (void *)0x0) {
    return 0;
  }
  memcpy(_Dst,src,byte_len);
  *out = _Dst;
  *out_len = byte_len >> 1;
  return CONCAT31(uVar2,1);
}




/* [AUDIT] proposed: XmlParse_selectHandler  (confidence: high)
 * purpose: Returns element-content parse handler fn ptr chosen by bits (out>>4)&0xf (8 encoding/normalization variants)
 * vars: out=flags; returns one of FUN_004194xx-198e0
 */
/* Global::XmlParse_selectHandler @ 00418000 */

undefined * __cdecl XmlParse_selectHandler(uint encoding_flags)

{
  switch(encoding_flags >> 4 & 0xf) {
  case 0:
    return rapidxml_skip_attr_value;
  case 1:
    return rapidxml_parse_attr_value;
  case 2:
    return rapidxml_skip_attr_value_crlf;
  case 3:
    return rapidxml_parse_attr_value_crlf;
  case 4:
  case 6:
    return rapidxml_parse_attr_value_ws;
  case 5:
  case 7:
    return rapidxml_parse_attr_value_ws_ent;
  case 8:
  case 10:
  case 0xc:
  case 0xe:
    return rapidxml_parse_attr_value_trim;
  case 9:
  case 0xb:
  case 0xd:
  case 0xf:
    return rapidxml_parse_attr_value_trim_ent;
  default:
    return (undefined *)0x0;
  }
}




/* [AUDIT] proposed: Xml_normalizeTextRun  (confidence: high)
 * purpose: Scans UTF-16 text: normalizes CR/CRLF to LF, resolves entities at '&' (decodeXmlEntity), stops at '<' or NUL
 * vars: encoding_flags=text cursor; DAT_0055ac88=char class table; local_c=entity out
 */
/* Global::Xml_normalizeTextRun @ 00418280 */

ushort * __cdecl Xml_normalizeTextRun(ushort *text)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  ushort *_Src;
  ushort *puVar4;
  int shift;
  ushort *amp_src;
  int amp_shift;
  
  _Src = (ushort *)0x0;
  shift = 0;
  amp_src = _Src;
  amp_shift = shift;
  while( true ) {
    while( true ) {
      puVar4 = text;
      if (*puVar4 < 0x80) {
        bVar2 = (&DAT_0055ac88)[*puVar4];
      }
      else {
        bVar2 = 0;
      }
      if ((bVar2 & 1) != 0) break;
      text = puVar4 + 1;
    }
    uVar1 = *puVar4;
    if (uVar1 == 0x3c) break;
    if (uVar1 == 0xd) {
      *puVar4 = 10;
      text = puVar4 + 1;
      if (*text == 10) {
        if (_Src != (ushort *)0x0) {
          memmove(_Src + -shift,_Src,(int)text - (int)_Src);
        }
        _Src = puVar4 + 2;
        shift = shift + 1;
        text = _Src;
        amp_src = _Src;
        amp_shift = shift;
      }
    }
    else if (uVar1 == 0x26) {
      text = decodeXmlEntity(puVar4,&amp_src);
      _Src = amp_src;
      shift = amp_shift;
    }
    else {
      if (uVar1 == 0) {
        return puVar4;
      }
      text = puVar4 + 1;
    }
  }
  puVar3 = puVar4;
  if (_Src != (ushort *)0x0) {
    memmove(_Src + -shift,_Src,(int)puVar4 - (int)_Src);
    puVar3 = puVar4 + -shift;
  }
  *puVar3 = 0;
  return puVar4 + 1;
}




/* [AUDIT] proposed: Xml_parseMainLoop  (confidence: high)
 * purpose: Core XML tokenizer/parser: walks tags, elements, attributes, dispatches to comment/PI/CDATA handlers via longjmp on error
 * vars: this+8=jmp_buf; this+0x48=error pos; param_3=flags; DAT_0055ac88=charclass; longjmp codes 3/0xb/0xc
 */
/* Global::Xml_parseMainLoop @ 00418410 */

void __thiscall
Xml_parseMainLoop(void *this,ushort *text,uint *pool,uint flags,undefined4 end_char)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  code *pcVar5;
  uint *puVar6;
  int *piVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  ushort *puVar11;
  uint *puVar12;
  code *local_c;
  uint *local_8;
  
  uVar9 = flags;
  pcVar5 = (code *)XmlParse_selectHandler(flags);
  switch(uVar9 >> 4 & 3) {
  case 0:
    local_c = rapidxml_skip_whitespace_to_tag;
    break;
  case 1:
    local_c = rapidxml_parse_node_data;
    break;
  case 2:
    local_c = rapidxml_parse_data_crlf;
    break;
  case 3:
    local_c = Xml_normalizeTextRun;
    break;
  default:
    local_c = (code *)0x0;
  }
  uVar4 = *text;
  local_8 = pool;
  puVar11 = text;
  puVar6 = pool;
  if (uVar4 != 0) {
    do {
      puVar8 = puVar11;
      if (uVar4 == 0x3c) {
LAB_00418556:
        puVar11 = puVar11 + 1;
LAB_0041855c:
        uVar9 = (uint)*puVar11;
        if (*puVar11 < 0x80) {
          cVar3 = (&DAT_0055ac88)[uVar9];
        }
        else {
          cVar3 = -0x40;
        }
        text = puVar11;
        if (cVar3 < '\0') {
          local_8 = XmlPool_allocChildNode((uint)puVar6,this,2);
          if (local_8 == (uint *)0x0) {
LAB_00418957:
                    /* WARNING: Subroutine does not return */
            longjmp((int *)((int)this + 8),3);
          }
          local_8[2] = (uint)puVar11;
          while( true ) {
            if (*puVar11 < 0x80) {
              bVar2 = (&DAT_0055ac88)[*puVar11];
            }
            else {
              bVar2 = 0xc0;
            }
            if ((bVar2 & 0x40) == 0) break;
            puVar11 = puVar11 + 1;
          }
          uVar4 = *puVar11;
          uVar9 = (uint)uVar4;
          *puVar11 = 0;
          puVar8 = puVar11 + 1;
          puVar6 = local_8;
          if (uVar9 != 0x3e) {
            if (uVar4 < 0x80) {
              bVar2 = (&DAT_0055ac88)[uVar9];
            }
            else {
              bVar2 = 0;
            }
            puVar12 = local_8;
            if ((bVar2 & 8) == 0) {
              if (uVar9 == 0x2f) {
                uVar4 = *puVar8;
                if ((uVar4 != 0x3e) && ((puVar10 = puVar8, uVar4 != 0 || ((ushort)end_char != 0x3e)))
                   ) goto LAB_0041862c;
                puVar8 = puVar8 + (uVar4 == 0x3e);
                puVar6 = (uint *)local_8[1];
                local_8 = (uint *)local_8[1];
              }
              else {
joined_r0x004188ab:
                puVar10 = puVar8;
                if ((uVar4 != 0) ||
                   (puVar8 = puVar11, puVar10 = puVar11, puVar6 = puVar12, (ushort)end_char != 0x3e))
                {
LAB_0041862c:
                  *(ushort **)((int)this + 0x48) = puVar10;
                    /* WARNING: Subroutine does not return */
                  longjmp((int *)((int)this + 8),0xb);
                }
              }
            }
            else {
LAB_00418720:
              while( true ) {
                while( true ) {
                  if (*puVar8 < 0x80) {
                    bVar2 = (&DAT_0055ac88)[*puVar8];
                  }
                  else {
                    bVar2 = 0;
                  }
                  if ((bVar2 & 8) == 0) break;
                  puVar8 = puVar8 + 1;
                }
                if (*puVar8 < 0x80) {
                  cVar3 = (&DAT_0055ac88)[*puVar8];
                }
                else {
                  cVar3 = -0x40;
                }
                if (-1 < cVar3) break;
                piVar7 = XmlPool_allocAttrNode((int)puVar12,this);
                if (piVar7 == (int *)0x0) {
                  *(undefined4 *)((int)this + 0x48) = 0;
                  goto LAB_00418957;
                }
                piVar7[1] = (int)puVar8;
                while( true ) {
                  if (*puVar8 < 0x80) {
                    bVar2 = (&DAT_0055ac88)[*puVar8];
                  }
                  else {
                    bVar2 = 0xc0;
                  }
                  if ((bVar2 & 0x40) == 0) break;
                  puVar8 = puVar8 + 1;
                }
                uVar4 = *puVar8;
                if (uVar4 == 0) goto LAB_0041892f;
                *puVar8 = 0;
                puVar8 = puVar8 + 1;
                if (*puVar8 == 0) goto LAB_0041892f;
                if (uVar4 < 0x80) {
                  bVar2 = (&DAT_0055ac88)[uVar4];
                }
                else {
                  bVar2 = 0;
                }
                if ((bVar2 & 8) != 0) {
                  while( true ) {
                    if (*puVar8 < 0x80) {
                      bVar2 = (&DAT_0055ac88)[*puVar8];
                    }
                    else {
                      bVar2 = 0;
                    }
                    if ((bVar2 & 8) == 0) break;
                    puVar8 = puVar8 + 1;
                  }
                  uVar4 = *puVar8;
                  if (uVar4 == 0) goto LAB_0041892f;
                  puVar8 = puVar8 + 1;
                }
                if (uVar4 != 0x3d) goto LAB_0041892f;
                while( true ) {
                  if (*puVar8 < 0x80) {
                    bVar2 = (&DAT_0055ac88)[*puVar8];
                  }
                  else {
                    bVar2 = 0;
                  }
                  if ((bVar2 & 8) == 0) break;
                  puVar8 = puVar8 + 1;
                }
                uVar4 = *puVar8;
                if ((uVar4 != 0x22) && (uVar4 != 0x27)) goto LAB_0041892f;
                piVar7[2] = (int)(puVar8 + 1);
                puVar8 = (ushort *)(*pcVar5)(puVar8 + 1,uVar4);
                if (puVar8 == (ushort *)0x0) {
                  *(int *)((int)this + 0x48) = piVar7[2];
                    /* WARNING: Subroutine does not return */
                  longjmp((int *)((int)this + 8),0xc);
                }
                if (*puVar8 < 0x80) {
                  cVar3 = (&DAT_0055ac88)[*puVar8];
                }
                else {
                  cVar3 = -0x40;
                }
                puVar12 = local_8;
                if (cVar3 < '\0') {
LAB_0041892f:
                  *(ushort **)((int)this + 0x48) = puVar8;
                    /* WARNING: Subroutine does not return */
                  longjmp((int *)((int)this + 8),0xc);
                }
              }
              uVar4 = *puVar8;
              if (uVar4 == 0x2f) {
                puVar10 = puVar8 + 1;
                if (puVar8[1] == 0x3e) {
                  puVar8 = puVar8 + 2;
                  puVar6 = (uint *)puVar12[1];
                  local_8 = (uint *)puVar12[1];
                }
                else {
                  if ((puVar8[1] != 0) || ((ushort)end_char != 0x3e)) goto LAB_0041862c;
                  puVar8 = puVar10;
                  puVar6 = (uint *)puVar12[1];
                  local_8 = (uint *)puVar12[1];
                }
              }
              else {
                puVar11 = puVar8;
                if (uVar4 != 0x3e) goto joined_r0x004188ab;
                puVar8 = puVar8 + 1;
                puVar6 = puVar12;
              }
            }
          }
        }
        else if (uVar9 == 0x2f) {
          puVar10 = (ushort *)puVar6[2];
          puVar8 = puVar11 + 1;
          if (puVar10 == (ushort *)0x0) {
LAB_0041867b:
            *(ushort **)((int)this + 0x48) = puVar8;
                    /* WARNING: Subroutine does not return */
            longjmp((int *)((int)this + 8),0xe);
          }
          while( true ) {
            uVar4 = *puVar8;
            if (uVar4 < 0x80) {
              bVar2 = (&DAT_0055ac88)[uVar4];
            }
            else {
              bVar2 = 0xc0;
            }
            if ((bVar2 & 0x40) == 0) break;
            uVar1 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar8 = puVar8 + 1;
            if (uVar4 != uVar1) goto LAB_0041867b;
          }
          if (*puVar10 != 0) {
            if (((*puVar8 == 0) && (*puVar10 == (ushort)end_char)) && (puVar10[1] == 0))
            goto LAB_00418920;
            goto LAB_0041867b;
          }
          puVar6 = (uint *)puVar6[1];
          while( true ) {
            if (*puVar8 < 0x80) {
              bVar2 = (&DAT_0055ac88)[*puVar8];
            }
            else {
              bVar2 = 0;
            }
            if ((bVar2 & 8) == 0) break;
            puVar8 = puVar8 + 1;
          }
          local_8 = puVar6;
          if (*puVar8 == 0) {
            if ((ushort)end_char != 0x3e) {
LAB_00418920:
              *(ushort **)((int)this + 0x48) = puVar8;
                    /* WARNING: Subroutine does not return */
              longjmp((int *)((int)this + 8),0xd);
            }
          }
          else {
            if (*puVar8 != 0x3e) goto LAB_00418920;
            puVar8 = puVar8 + 1;
          }
        }
        else if (uVar9 == 0x3f) {
          Xml_parseProcInstr(this,(int *)&text,(uint *)&local_8,flags,(ushort)end_char);
          puVar8 = text;
          puVar6 = local_8;
          if ((local_8 != (uint *)0x0) && (puVar12 = local_8, ((byte)*local_8 & 7) == 7))
          goto LAB_00418720;
        }
        else {
          if (uVar9 != 0x21) {
            if ((*puVar11 == 0) && ((ushort)end_char == 0x3f)) {
              *(ushort **)((int)this + 0x48) = puVar11;
                    /* WARNING: Subroutine does not return */
              longjmp((int *)((int)this + 8),6);
            }
            *(ushort **)((int)this + 0x48) = puVar11;
                    /* WARNING: Subroutine does not return */
            longjmp((int *)((int)this + 8),5);
          }
          Xml_parseCommentOrCData(this,(int *)&text,puVar6,flags,end_char);
          puVar8 = text;
        }
      }
      else {
        while( true ) {
          if (*puVar8 < 0x80) {
            bVar2 = (&DAT_0055ac88)[*puVar8];
          }
          else {
            bVar2 = 0;
          }
          if ((bVar2 & 8) == 0) break;
          puVar8 = puVar8 + 1;
        }
        if (((flags & 8) != 0) && (puVar11 != puVar8)) {
LAB_004184ce:
          if (puVar6[1] == 0) {
            uVar4 = *puVar11;
            puVar8 = puVar11;
            if (uVar4 != 0) {
              while (puVar8 = puVar11, uVar4 != 0x3c) {
                uVar4 = puVar11[1];
                puVar8 = puVar11 + 1;
                puVar11 = puVar8;
                if (uVar4 == 0) goto LAB_00418532;
              }
            }
            puVar11 = puVar8;
            if (*puVar8 != 0) goto LAB_00418556;
          }
          else {
            puVar6 = XmlPool_allocChildNode((uint)puVar6,this,3);
            if (puVar6 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
              longjmp((int *)((int)this + 8),3);
            }
            puVar6[3] = (uint)puVar11;
            puVar8 = (ushort *)(*local_c)(puVar11);
            puVar6 = (uint *)puVar6[1];
            puVar11 = puVar8;
            text = puVar8;
            local_8 = puVar6;
            if (*puVar8 != 0) goto LAB_0041855c;
          }
          break;
        }
        if (*puVar8 != 0x3c) {
          if (*puVar8 != 0) goto LAB_004184ce;
          break;
        }
      }
      uVar4 = *puVar8;
      puVar11 = puVar8;
    } while (uVar4 != 0);
LAB_00418532:
    if (puVar6 != pool) {
      *(ushort **)((int)this + 0x48) = puVar8;
                    /* WARNING: Subroutine does not return */
      longjmp((int *)((int)this + 8),0xe);
    }
  }
  return;
}




/* [AUDIT] proposed: Xml_skipDoctypeSubset  (confidence: med)
 * purpose: Recursively skips DOCTYPE markup/internal subset: nested markup, CDATA (Xml_skipMarkedSection), quotes/comments (Xml_skipQuotedOrComment)
 * vars: this+0x48=err pos; this+8=jmp_buf; text=cursor; longjmp 9 on unterminated
 */
/* Global::Xml_skipDoctypeSubset @ 00418ab0 */

void __thiscall Xml_skipDoctypeSubset(void *this,int *cursor,undefined4 end_char,char in_doctype)

{
  short ch;
  short *p;
  
  *cursor = *cursor + 2;
  ch = *(short *)*cursor;
  do {
    if (ch == 0) {
      if ((in_doctype != '\0') && ((short)end_char == 0x3e)) {
        return;
      }
      *(int *)((int)this + 0x48) = *cursor;
                    /* WARNING: Subroutine does not return */
      longjmp((int *)((int)this + 8),9);
    }
    p = (short *)*cursor;
    ch = *p;
    if (ch == 0x3c) {
      if ((p[1] == 0x21) && (p[2] != 0x2d)) {
        if (p[2] == 0x5b) {
          Xml_skipMarkedSection(this,cursor);
        }
        else {
          Xml_skipDoctypeSubset(this,cursor,end_char,'\0');
        }
      }
      else {
LAB_00418b1f:
        Xml_skipQuotedOrComment(this,cursor);
      }
    }
    else {
      if ((ch == 0x22) || (ch == 0x27)) goto LAB_00418b1f;
      if (ch == 0x3e) {
        *cursor = *cursor + 2;
        return;
      }
      *cursor = (int)(p + 1);
    }
    ch = *(short *)*cursor;
  } while( true );
}




/* [AUDIT] proposed: Xml_skipMarkedSection  (confidence: med)
 * purpose: Recursively skips a nested <![ ... ]]> marked section until matching ']]>' terminator
 * vars: cursor=cursor; this+0x48=err; longjmp 9 unterminated
 */
/* Global::Xml_skipMarkedSection @ 00418b60 */

void __thiscall Xml_skipMarkedSection(void *this,int *cursor)

{
  short ch;
  short *p;
  
  *cursor = *cursor + 2;
  ch = *(short *)*cursor;
  do {
    if (ch == 0) {
      *(int *)((int)this + 0x48) = *cursor;
                    /* WARNING: Subroutine does not return */
      longjmp((int *)((int)this + 8),9);
    }
    p = (short *)*cursor;
    if (((*p == 0x3c) && (p[1] == 0x21)) && (p[2] == 0x5b)) {
      Xml_skipMarkedSection(this,cursor);
    }
    else {
      if (((*p == 0x5d) && (p[1] == 0x5d)) && (p[2] == 0x3e)) {
        *cursor = *cursor + 6;
        return;
      }
      *cursor = (int)(p + 1);
    }
    ch = *(short *)*cursor;
  } while( true );
}




/* [AUDIT] proposed: Xml_skipQuotedOrComment  (confidence: med)
 * purpose: Skips a quoted literal, a <?...?> PI, or a <!-- --> comment; errors via longjmp if unterminated
 * vars: cursor=cursor; this+0x48=err; handles 0x22/0x27/0x3f/comment
 */
/* Global::Xml_skipQuotedOrComment @ 00418bd0 */

void __thiscall Xml_skipQuotedOrComment(void *this,undefined4 *cursor)

{
  short quote;
  short ch;
  short *p;
  
  p = (short *)*cursor;
  quote = *p;
  if ((quote == 0x22) || (quote == 0x27)) {
    p = p + 1;
    *cursor = p;
    ch = *p;
    while ((ch != 0 && (*p != quote))) {
      p = p + 1;
      *cursor = p;
      ch = *p;
    }
    p = (short *)*cursor;
    if (*p != 0) {
      *cursor = p + 1;
      return;
    }
    *(short **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
    longjmp((int *)((int)this + 8),9);
  }
  if (quote == 0x3c) {
    if (p[1] == 0x3f) {
      *cursor = p + 2;
      quote = p[2];
      while ((quote != 0 && ((p = (short *)*cursor, *p != 0x3f || (p[1] != 0x3e)))))
      {
        *cursor = p + 1;
        quote = p[1];
      }
      p = (short *)*cursor;
      if (*p != 0) {
        *cursor = p + 2;
        return;
      }
    }
    else if (((p[1] == 0x21) && (p[2] == 0x2d)) && (p[3] == 0x2d)) {
      *cursor = p + 4;
      quote = p[4];
      while ((quote != 0 &&
             (((p = (short *)*cursor, *p != 0x2d || (p[1] != 0x2d)) ||
              (p[2] != 0x3e))))) {
        *cursor = p + 1;
        quote = p[1];
      }
      p = (short *)*cursor;
      if (*p != 0) {
        *cursor = p + 4;
        return;
      }
      *(short **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
      longjmp((int *)((int)this + 8),9);
    }
  }
  *(short **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
  longjmp((int *)((int)this + 8),9);
}




/* [AUDIT] proposed: Xml_parseCommentOrCData  (confidence: high)
 * purpose: Parses <!-- comment --> or <![CDATA[ ... ]]> section, optionally creating a node and normalizing content
 * vars: param_3=flags(2=comment node,4=cdata node,0x20=normalize); this+0x48=err; longjmp 5/7/8
 */
/* Global::Xml_parseCommentOrCData @ 00418ea0 */

void __thiscall Xml_parseCommentOrCData(void *this,int *cursor,uint *pool,uint flags,undefined4 end_char)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  ushort *puVar5;
  short sVar6;
  ushort *p;
  
  iVar2 = *cursor;
  p = (ushort *)(iVar2 + 2);
  uVar1 = *p;
  sVar6 = (short)end_char;
  if (uVar1 != 0x2d) {
    if (uVar1 == 0x5b) {
      p = (ushort *)(iVar2 + 4);
      if (((((*(ushort *)(iVar2 + 4) == 0x43) &&
            (p = (ushort *)(iVar2 + 6), *(ushort *)(iVar2 + 6) == 0x44)) &&
           (p = (ushort *)(iVar2 + 8), *(ushort *)(iVar2 + 8) == 0x41)) &&
          ((p = (ushort *)(iVar2 + 10), *(ushort *)(iVar2 + 10) == 0x54 &&
           (p = (ushort *)(iVar2 + 0xc), *(ushort *)(iVar2 + 0xc) == 0x41)))) &&
         (p = (ushort *)(iVar2 + 0xe), *(ushort *)(iVar2 + 0xe) == 0x5b)) {
        p = (ushort *)(iVar2 + 0x10);
        if ((flags & 4) != 0) {
          puVar4 = XmlPool_allocChildNode((uint)pool,this,4);
          if (puVar4 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
            longjmp((int *)((int)this + 8),3);
          }
          puVar4[3] = (uint)p;
          if ((flags & 0x20) == 0) {
            uVar1 = *p;
            puVar5 = p;
            while (p = puVar5, uVar1 != 0) {
              if (((uVar1 == 0x5d) && (puVar5[1] == 0x5d)) &&
                 ((puVar5[2] == 0x3e || ((puVar5[2] == 0 && (sVar6 == 0x3e)))))) {
                if (*puVar5 != 0) {
                  *puVar5 = 0;
                  goto LAB_0041912d;
                }
                break;
              }
              puVar5 = puVar5 + 1;
              uVar1 = *puVar5;
            }
          }
          else {
            puVar5 = Xml_scanCDataContent(p,sVar6);
            if (puVar5 != (ushort *)0x0) goto LAB_00419133;
            puVar5 = (ushort *)puVar4[3];
            p = (ushort *)0x0;
          }
          *(ushort **)((int)this + 0x48) = puVar5;
                    /* WARNING: Subroutine does not return */
          longjmp((int *)((int)this + 8),8);
        }
        uVar1 = *p;
        puVar5 = p;
        while (p = puVar5, uVar1 != 0) {
          if (((uVar1 == 0x5d) && (puVar5[1] == 0x5d)) &&
             ((puVar5[2] == 0x3e || ((puVar5[2] == 0 && (sVar6 == 0x3e)))))) {
            if (*puVar5 != 0) goto LAB_0041912d;
            break;
          }
          puVar5 = puVar5 + 1;
          uVar1 = *puVar5;
        }
      }
LAB_004191e7:
      *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
      longjmp((int *)((int)this + 8),8);
    }
    if (((((uVar1 == 0x44) && (*(short *)(iVar2 + 4) == 0x4f)) && (*(short *)(iVar2 + 6) == 0x43))
        && ((*(short *)(iVar2 + 8) == 0x54 && (*(short *)(iVar2 + 10) == 0x59)))) &&
       (*(short *)(iVar2 + 0xc) == 0x50)) {
      if (*(short *)(iVar2 + 0xe) == 0x45) {
        p = (ushort *)(iVar2 + -2);
        Xml_skipDoctypeSubset(this,(int *)&p,end_char,'\x01');
        goto LAB_004191b9;
      }
      if ((*(short *)(iVar2 + 0xe) == 0) && (sVar6 == 0x45)) {
        *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
        longjmp((int *)((int)this + 8),9);
      }
    }
    if (uVar1 == 0) {
      if (sVar6 == 0x2d) goto LAB_004191d2;
      if (sVar6 == 0x5b) goto LAB_004191e7;
    }
    *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
    longjmp((int *)((int)this + 8),5);
  }
  p = (ushort *)(iVar2 + 4);
  if (*p == 0x2d) {
    p = (ushort *)(iVar2 + 6);
    uVar3 = flags & 2;
    if (uVar3 != 0) {
      pool = XmlPool_allocChildNode((uint)pool,this,5);
      if (pool == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
        longjmp((int *)((int)this + 8),3);
      }
      pool[3] = (uint)p;
    }
    if (((flags & 0x20) != 0) && (uVar3 != 0)) {
      p = Xml_scanCommentContent(p,sVar6);
      if (p == (ushort *)0x0) {
        *(uint *)((int)this + 0x48) = pool[3];
                    /* WARNING: Subroutine does not return */
        longjmp((int *)((int)this + 8),7);
      }
LAB_004191b9:
      *cursor = (int)p;
      return;
    }
    uVar1 = *p;
    while (uVar1 != 0) {
      if (((uVar1 == 0x2d) && (p[1] == 0x2d)) &&
         ((p[2] == 0x3e || ((p[2] == 0 && (sVar6 == 0x3e)))))) {
        if (*p != 0) {
          if (uVar3 != 0) {
            *p = 0;
          }
          *cursor = (int)(p + (p[2] == 0x3e) + 2);
          return;
        }
        break;
      }
      p = p + 1;
      uVar1 = *p;
    }
  }
LAB_004191d2:
  *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
  longjmp((int *)((int)this + 8),7);
LAB_0041912d:
  puVar5 = puVar5 + 1;
LAB_00419133:
  *cursor = (int)(puVar5 + (puVar5[1] == 0x3e) + 1);
  return;
}




/* [AUDIT] proposed: Xml_parseProcInstr  (confidence: high)
 * purpose: Parses processing instruction / XML declaration <? ... ?>; special-cases 'xml' decl, creates PI node, captures target/data
 * vars: flags flags(1 PI,0x100 xmldecl); puVar7[2]=target,[3]=data; longjmp 6 on error
 */
/* Global::Xml_parseProcInstr @ 00419210 */

void __thiscall Xml_parseProcInstr(void *this,int *cursor,uint *pool,uint flags,short end_char)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  ushort *name;
  ushort *p;
  
  puVar8 = (undefined4 *)*pool;
  iVar1 = *cursor;
  name = (ushort *)(iVar1 + 2);
  if (*name < 0x80) {
    cVar3 = (&DAT_0055ac88)[*name];
  }
  else {
    cVar3 = -0x40;
  }
  p = name;
  if (cVar3 < '\0') {
    while( true ) {
      if (*p < 0x80) {
        bVar4 = (&DAT_0055ac88)[*p];
      }
      else {
        bVar4 = 0xc0;
      }
      if ((bVar4 & 0x40) == 0) break;
      p = p + 1;
    }
    if (*p == 0) {
      *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
      longjmp((int *)((int)this + 8),6);
    }
    if (((((*name | 0x20) == 0x78) && ((*(ushort *)(iVar1 + 4) | 0x20) == 0x6d)) &&
        ((*(ushort *)(iVar1 + 6) | 0x20) == 0x6c)) && ((ushort *)(iVar1 + 8) == p)) {
      bVar2 = true;
      uVar6 = flags & 0x100;
    }
    else {
      bVar2 = false;
      uVar6 = flags & 1;
    }
    if (uVar6 == 0) {
      uVar5 = *p;
      do {
        if ((uVar5 == 0x3f) && ((p[1] == 0x3e || ((p[1] == 0 && (end_char == 0x3e)))))) {
          if (*p != 0) {
            uVar6 = (p[1] == 0x3e) + 1;
            goto LAB_00419471;
          }
          break;
        }
        uVar5 = p[1];
        p = p + 1;
      } while (uVar5 != 0);
    }
    else {
      if (bVar2) {
        if (((byte)*puVar8 & 7) != 1) {
          *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
          longjmp((int *)((int)this + 8),6);
        }
        puVar7 = XmlPool_allocChildNode((uint)puVar8,this,7);
        if (puVar7 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
          longjmp((int *)((int)this + 8),3);
        }
      }
      else {
        puVar7 = XmlPool_allocChildNode((uint)puVar8,this,6);
        if (puVar7 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
          longjmp((int *)((int)this + 8),3);
        }
      }
      puVar7[2] = (uint)name;
      uVar5 = *p;
      *p = 0;
      p = p + 1;
      if (uVar5 == 0x3f) {
        uVar5 = *p;
        if ((uVar5 != 0x3e) && ((uVar5 != 0 || (end_char != 0x3e)))) {
          *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
          longjmp((int *)((int)this + 8),6);
        }
        puVar8 = (undefined4 *)puVar7[1];
        uVar6 = (uint)(uVar5 == 0x3e);
LAB_00419471:
        *cursor = (int)(p + uVar6);
        *pool = (uint)puVar8;
        return;
      }
      if (uVar5 < 0x80) {
        bVar4 = (&DAT_0055ac88)[uVar5];
      }
      else {
        bVar4 = 0;
      }
      if ((bVar4 & 8) != 0) {
        while( true ) {
          if (*p < 0x80) {
            bVar4 = (&DAT_0055ac88)[*p];
          }
          else {
            bVar4 = 0;
          }
          if ((bVar4 & 8) == 0) break;
          p = p + 1;
        }
        name = p;
        if (*p != 0) {
          do {
            if ((*name == 0x3f) &&
               ((name[1] == 0x3e || ((name[1] == 0 && (end_char == 0x3e)))))) break;
            name = name + 1;
          } while (*name != 0);
          if (*name != 0) {
            if (bVar2) {
              *name = 0x2f;
              *cursor = (int)p;
              *pool = (uint)puVar7;
              return;
            }
            puVar7[3] = (uint)p;
            puVar8 = (undefined4 *)puVar7[1];
            *name = 0;
            p = name + 1;
            uVar6 = (uint)(*p == 0x3e);
            goto LAB_00419471;
          }
        }
        *(ushort **)((int)this + 0x48) = name;
                    /* WARNING: Subroutine does not return */
        longjmp((int *)((int)this + 8),6);
      }
    }
  }
  *(ushort **)((int)this + 0x48) = p;
                    /* WARNING: Subroutine does not return */
  longjmp((int *)((int)this + 8),6);
}




/* [AUDIT] proposed: Xml_shiftBufferForNewline  (confidence: med)
 * purpose: Shifts text buffer left to collapse removed CR bytes (memmove) and advances write cursor by pool units
 * vars: this[0]=src base; this+4=shift count; cursor=cursor; pool=advance
 */
/* Global::Xml_shiftBufferForNewline @ 00419a80 */

void __thiscall Xml_shiftBufferForNewline(void *this,int *cursor,int shift)

{
  void *_Src;
  int iVar1;
  
  _Src = *(void **)this;
  if (_Src != (void *)0x0) {
    memmove((void *)((int)_Src + *(int *)((int)this + 4) * -2),_Src,*cursor - (int)_Src);
  }
  *cursor = *cursor + shift * 2;
  iVar1 = *cursor;
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + shift;
  *(int *)this = iVar1;
  return;
}




/* [AUDIT] proposed: Xml_scanCDataContent  (confidence: high)
 * purpose: Scans CDATA body: normalizes CR/CRLF to LF, terminates at ']]>' (NUL-terminating), returns ptr past terminator or 0
 * vars: cursor=text; shift=end-quote char(0x3e); DAT_0055ac88 class bit 0x10
 */
/* Global::Xml_scanCDataContent @ 00419ac0 */

ushort * __cdecl Xml_scanCDataContent(ushort *text,short end_char)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  ushort *_Src;
  ushort *puVar4;
  int shift;
  
  if (*text == 0) {
    return (ushort *)0x0;
  }
  _Src = (ushort *)0x0;
  shift = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        puVar4 = text;
        if (*puVar4 < 0x80) {
          bVar2 = (&DAT_0055ac88)[*puVar4];
        }
        else {
          bVar2 = 0;
        }
        if ((bVar2 & 0x10) != 0) break;
        text = puVar4 + 1;
      }
      uVar1 = *puVar4;
      if (uVar1 != 0xd) break;
      *puVar4 = 10;
      text = puVar4 + 1;
      if (*text == 10) {
        if (_Src != (ushort *)0x0) {
          memmove(_Src + -shift,_Src,(int)text - (int)_Src);
        }
        _Src = puVar4 + 2;
        shift = shift + 1;
        text = _Src;
      }
    }
    if (((uVar1 == 0x5d) && (puVar4[1] == 0x5d)) &&
       ((puVar4[2] == 0x3e || ((puVar4[2] == 0 && (end_char == 0x3e)))))) break;
    if (uVar1 == 0) {
      return (ushort *)0x0;
    }
    text = puVar4 + 1;
  }
  puVar3 = puVar4;
  if (_Src != (ushort *)0x0) {
    memmove(_Src + -shift,_Src,(int)puVar4 - (int)_Src);
    puVar3 = puVar4 + -shift;
  }
  *puVar3 = 0;
  return puVar4 + 1;
}




/* [AUDIT] proposed: Xml_scanCommentContent  (confidence: high)
 * purpose: Scans comment body: normalizes CR/CRLF to LF, terminates at '-->' (NUL-terminating), returns ptr past terminator or 0
 * vars: text=text; end_char=end char(0x3e); DAT_0055ac88 class bit 0x20
 */
/* Global::Xml_scanCommentContent @ 00419ba0 */

ushort * __cdecl Xml_scanCommentContent(ushort *text,short end_char)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  ushort *_Src;
  ushort *puVar4;
  int shift;
  
  if (*text == 0) {
    return (ushort *)0x0;
  }
  _Src = (ushort *)0x0;
  shift = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        puVar4 = text;
        if (*puVar4 < 0x80) {
          bVar2 = (&DAT_0055ac88)[*puVar4];
        }
        else {
          bVar2 = 0;
        }
        if ((bVar2 & 0x20) != 0) break;
        text = puVar4 + 1;
      }
      uVar1 = *puVar4;
      if (uVar1 != 0xd) break;
      *puVar4 = 10;
      text = puVar4 + 1;
      if (*text == 10) {
        if (_Src != (ushort *)0x0) {
          memmove(_Src + -shift,_Src,(int)text - (int)_Src);
        }
        _Src = puVar4 + 2;
        shift = shift + 1;
        text = _Src;
      }
    }
    if (((uVar1 == 0x2d) && (puVar4[1] == 0x2d)) &&
       ((puVar4[2] == 0x3e || ((puVar4[2] == 0 && (end_char == 0x3e)))))) break;
    if (uVar1 == 0) {
      return (ushort *)0x0;
    }
    text = puVar4 + 1;
  }
  puVar3 = puVar4;
  if (_Src != (ushort *)0x0) {
    memmove(_Src + -shift,_Src,(int)puVar4 - (int)_Src);
    puVar3 = puVar4 + -shift;
  }
  *puVar3 = 0;
  return puVar4 + (puVar4[2] == 0x3e) + 2;
}




/* [AUDIT] proposed: decodeXmlEntity  (confidence: high)
 * purpose: Decodes one XML/HTML entity in wide-char string (&#dec; &#xhex; &amp; &apos; &gt; &lt; &quot;) then appends result
 * vars: text=ushort* cursor at '&'; end_char=output collector; switch on char after '&'; 0x3b=';'
 */
/* Global::decodeXmlEntity @ 00419c90 */

ushort * __cdecl decodeXmlEntity(ushort *entity,void *cursor)

{
  ushort *puVar1;
  uint code;
  uint uVar3;
  ushort *p;
  ushort ch;
  uint uVar6;
  
  puVar1 = entity + 1;
  p = puVar1;
  switch(*puVar1) {
  case 0x23:
    code = 0;
    if (entity[2] == 0x78) {
      uVar6 = (uint)entity[3];
      p = entity + 3;
      if (uVar6 == 0x3b) {
        return p;
      }
      while( true ) {
        while (uVar6 - 0x30 < 10) {
          puVar1 = p + 1;
          code = code * 0x10 + -0x30 + uVar6;
          p = p + 1;
          uVar6 = (uint)*puVar1;
        }
        uVar3 = uVar6 | 0x20;
        if (5 < uVar3 - 0x61) break;
        uVar6 = (uint)p[1];
        code = code * 0x10 + -0x57 + uVar3;
        p = p + 1;
      }
      ch = (ushort)uVar6;
    }
    else {
      ch = entity[2];
      uVar6 = (uint)ch;
      p = entity + 2;
      if (uVar6 == 0x3b) {
        return p;
      }
      while (uVar6 - 0x30 < 10) {
        ch = p[1];
        p = p + 1;
        code = uVar6 + code * 10 + -0x30;
        uVar6 = (uint)ch;
      }
    }
    if (ch == 0x3b) {
      entity = encodeUtf16Codepoint(entity,code);
      Xml_shiftBufferForNewline(cursor,(int *)&entity,(int)(p + 1) - (int)entity >> 1);
      return p + 1;
    }
    break;
  case 0x61:
    p = entity + 2;
    if (entity[2] == 0x6d) {
      p = entity + 3;
      if ((*p == 0x70) && (p = entity + 4, *p == 0x3b)) {
        ch = 0x26;
        goto LAB_00419da1;
      }
    }
    else if ((((entity[2] == 0x70) && (p = entity + 3, *p == 0x6f)) &&
             (p = entity + 4, *p == 0x73)) && (p = entity + 5, *p == 0x3b)) {
      ch = 0x27;
      goto LAB_00419da1;
    }
    break;
  case 0x67:
    p = entity + 2;
    if ((*p == 0x74) && (p = entity + 3, *p == 0x3b)) {
      ch = 0x3e;
LAB_00419da1:
      *entity = ch;
      entity = puVar1;
      Xml_shiftBufferForNewline(cursor,(int *)&entity,(int)p + (2 - (int)puVar1) >> 1);
      return p + 1;
    }
    break;
  case 0x6c:
    p = entity + 2;
    if ((*p == 0x74) && (p = entity + 3, *p == 0x3b)) {
      ch = 0x3c;
      goto LAB_00419da1;
    }
    break;
  case 0x71:
    p = entity + 2;
    if ((((*p == 0x75) && (p = entity + 3, *p == 0x6f)) &&
        (p = entity + 4, *p == 0x74)) && (p = entity + 5, *p == 0x3b)) {
      ch = 0x22;
      goto LAB_00419da1;
    }
  }
  return p;
}




/* [AUDIT] proposed: Tree_destroyRec_oneStr  (confidence: high)
 * purpose: Recursively destroys tree nodes freeing one wstring (offset 0x10) per node then the node
 * vars: entity=node; +0xd=nil flag; +0x24..0x38=wstring
 */
/* Global::Tree_destroyRec_oneStr @ 0041a120 */

void Tree_destroyRec_oneStr(int *node)

{
  char cVar1;
  int *parent;
  
  cVar1 = *(char *)((int)node + 0xd);
  while (cVar1 == '\0') {
    Tree_destroyRec_oneStr((int *)node[2]);
    parent = (int *)*node;
    if (7 < (uint)node[9]) {
      operator_delete((void *)node[4]);
    }
    node[9] = 7;
    node[8] = 0;
    *(undefined2 *)(node + 4) = 0;
    operator_delete(node);
    node = parent;
    cVar1 = *(char *)((int)parent + 0xd);
  }
  return;
}




/* [AUDIT] proposed: Tree_eraseRange_variant  (confidence: high)
 * purpose: Erases iterator range from map/set (variant using std_Rb_tree_erase_node_variant erase-node)
 * vars: this=map; param_2=first,param_3=last; full-clear fast path
 */
/* Global::Tree_eraseRange_variant @ 0041a510 */

undefined4 * __thiscall Tree_eraseRange_variant(void *this,undefined4 *out_it,int *first,int *last)

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
    Tree_destroyRec_oneStr((int *)piVar2[1]);
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
    std_Rb_tree_erase_node_variant(this,&self,piVar3);
    piVar3 = first;
  }
  *out_it = piVar3;
  return out_it;
}




/* [AUDIT] proposed: SpeechMap_findOrInsert  (confidence: high)
 * purpose: Lower-bound search by wstring key (via compare) then insert new node; returns iter+bool
 * vars: this=map; last=key wstring; first=hint dir; wstring cmp wstring_compareSubstr
 */
/* Global::SpeechMap_findOrInsert @ 0041a9b0 */

void __thiscall
SpeechMap_findOrInsert(void *this,undefined4 *out,undefined4 *hint,ushort *key,undefined4 param_4)

{
  ushort *this_00;
  uint uVar1;
  ushort **ppuVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  bool go_left;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  this_00 = key;
  puStack_c = &LAB_0054bc60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  go_left = true;
  puVar3 = *(undefined4 **)this;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  while (*(char *)((int)puVar5 + 0xd) == '\0') {
    if ((char)hint == '\0') {
      puVar4 = (ushort *)(puVar5 + 4);
      if (7 < (uint)puVar5[9]) {
        puVar4 = *(ushort **)puVar4;
      }
      uVar1 = wstring_compareSubstr(this_00,0,*(uint *)(this_00 + 8),puVar4,puVar5[8]);
      go_left = (int)uVar1 < 0;
    }
    else {
      puVar4 = this_00;
      if (7 < *(uint *)(this_00 + 10)) {
        puVar4 = *(ushort **)this_00;
      }
      uVar1 = wstring_compareSubstr(puVar5 + 4,0,puVar5[8],puVar4,*(uint *)(this_00 + 8));
      go_left = -1 < (int)uVar1;
    }
    puVar3 = puVar5;
    if (go_left == false) {
      puVar5 = (undefined4 *)puVar5[2];
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  hint = puVar3;
  if (go_left != false) {
    if (puVar3 == (undefined4 *)**(int **)this) {
      ppuVar2 = (ushort **)&hint;
      go_left = true;
      goto LAB_0041aa71;
    }
    std_Rb_tree_increment((int *)&hint);
  }
  puVar5 = hint;
  puVar4 = this_00;
  if (7 < *(uint *)(this_00 + 10)) {
    puVar4 = *(ushort **)this_00;
  }
  uVar1 = wstring_compareSubstr(hint + 4,0,hint[8],puVar4,*(uint *)(this_00 + 8));
  if (-1 < (int)uVar1) {
    *out = puVar5;
    *(undefined1 *)(out + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  ppuVar2 = &key;
LAB_0041aa71:
  puVar3 = (undefined4 *)RBTree_insertRebalance_41a7b0(this,ppuVar2,go_left,puVar3,(int *)this_00);
  *out = *puVar3;
  *(undefined1 *)(out + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: SpeechMap_insertEach  (confidence: med)
 * purpose: Traverses a tree in order and calls findOrInsert per node (merge/copy map entries)
 * vars: this=dest; out..hint=src iterator range
 */
/* Global::SpeechMap_insertEach @ 0041ab00 */

void __thiscall SpeechMap_insertEach(void *this,int *first,int *last)

{
  char cVar1;
  int *piVar2;
  int *node;
  undefined4 local_c [2];
  
  do {
    do {
      while( true ) {
        do {
          node = first;
          if (node == last) {
            return;
          }
          SpeechMap_findOrInsert(this,local_c,(undefined4 *)0x0,(ushort *)(node + 4),(uint)DAT_00583d7a);
          first = node;
        } while (*(char *)((int)node + 0xd) != '\0');
        first = (int *)node[2];
        if (*(char *)((int)first + 0xd) != '\0') break;
        cVar1 = *(char *)(*first + 0xd);
        node = (int *)*first;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*node + 0xd);
          first = node;
          node = (int *)*node;
        }
      }
      first = (int *)node[1];
    } while (*(char *)((int)first + 0xd) != '\0');
    do {
      if (node != (int *)first[2]) break;
      piVar2 = (int *)first[1];
      node = first;
      first = piVar2;
    } while (*(char *)((int)piVar2 + 0xd) == '\0');
  } while( true );
}




/* [AUDIT] proposed: QuestTextNode_copyRec  (confidence: high)
 * purpose: Recursively deep-copies a QuestTextNode subtree including its child map and nested node lists
 * vars: this=dest; first=source node; +8=child map,+0x38=node list,+0xc inner tree
 */
/* Global::QuestTextNode_copyRec @ 0041af70 */

void __thiscall QuestTextNode_copyRec(void *this,uint src_node)

{
  int *this_00;
  uint uVar1;
  int *child;
  
  uVar1 = src_node;
  if (src_node != 0) {
    child = (int *)(src_node + 4);
    SpeechMap_insertEach((void *)((int)this + 8),(int *)**(int **)(src_node + 4),*(int **)(src_node + 4));
    this_00 = (int *)(src_node + 0xc);
    if (this_00 != child) {
      Tree_destroyRec_oneStr(*(int **)(*this_00 + 4));
      src_node = src_node & 0xffffff00;
      *(int *)(*this_00 + 4) = *this_00;
      *(int *)*this_00 = *this_00;
      *(int *)(*this_00 + 8) = *this_00;
      *(undefined4 *)(uVar1 + 0x10) = 0;
      QuestText_assignTree(this_00,child,src_node);
    }
    child = (int *)**(int **)(uVar1 + 0x38);
    if (child != *(int **)(uVar1 + 0x38)) {
      do {
        QuestTextNode_copyRec(this,child[2]);
        SpeechMap_insertEach(this_00,(int *)**(int **)(child[2] + 0xc),*(int **)(child[2] + 0xc));
        child = (int *)*child;
      } while (child != (int *)*(int *)(uVar1 + 0x38));
    }
  }
  return;
}




/* [AUDIT] proposed: isPunctuation  (confidence: high)
 * purpose: Returns true if wide char is one of . : - , ; ! ? / ( ) punctuation marks
 * vars: src_node=wchar; low byte flag set in return CONCAT11
 */
/* Global::isPunctuation @ 0041b000 */

short __cdecl isPunctuation(short ch)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)ch >> 8);
  if ((((((ch != 0x2e) && (ch != 0x3a)) && (ch != 0x2d)) &&
       ((ch != 0x2c && (ch != 0x3b)))) &&
      ((ch != 0x21 && ((ch != 0x3f && (ch != 0x2f)))))) &&
     ((ch != 0x28 && (ch != 0x29)))) {
    return (ushort)bVar1 << 8;
  }
  return CONCAT11(bVar1,1);
}




/* [AUDIT] proposed: copyVec12Range  (confidence: high)
 * purpose: Copies range of 12-byte (3-dword) elements from [ch,param_2) into param_3
 * vars: vector<vec3-ish> copy; stride 3 dwords
 */
/* Global::copyVec12Range @ 0041b930 */

undefined4 * __cdecl copyVec12Range(undefined4 *first,undefined4 *last,undefined4 *dst)

{
  if (first == last) {
    return dst;
  }
  do {
    if (dst != (undefined4 *)0x0) {
      *dst = *first;
      dst[1] = first[1];
      dst[2] = first[2];
    }
    first = first + 3;
    dst = dst + 3;
  } while (first != last);
  return dst;
}




/* [AUDIT] proposed: vec12_reallocate  (confidence: high)
 * purpose: Reallocates 12-byte-element vector to first capacity, copies old elements, frees old buffer
 * vars: this+0=begin,+4=end,+8=cap; element size 0xc; first=new capacity
 */
/* Global::vec12_reallocate @ 0041ba90 */

void __thiscall vec12_reallocate(void *this,uint new_capacity)

{
  int old_end;
  int old_begin;
  undefined4 *new_buffer;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054be20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  new_buffer = (undefined4 *)0x0;
  if (new_capacity != 0) {
    if (new_capacity < 0x15555556) {
      new_buffer = operator_new(new_capacity * 0xc);
      if (new_buffer != (undefined4 *)0x0) goto LAB_0041baef;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_0041baef:
  local_8 = 0;
  copyVec12Range(*(undefined4 **)this,*(undefined4 **)((int)this + 4),new_buffer);
  old_end = *(int *)((int)this + 4);
  old_begin = *(int *)this;
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 **)this = new_buffer;
  *(undefined4 **)((int)this + 8) = new_buffer + new_capacity * 3;
  *(undefined4 **)((int)this + 4) = new_buffer + ((old_end - old_begin) / 0xc) * 3;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: vec12_reserveGrow  (confidence: high)
 * purpose: Ensures 12-byte-element vector capacity for new_capacity more, computing 1.5x growth
 * vars: this=vector; element 0xc bytes; max 0x15555555
 */
/* Global::vec12_reserveGrow @ 0041bb80 */

void __thiscall vec12_reserveGrow(void *this,uint add_count)

{
  int size;
  uint capacity;
  uint required;
  
  if (add_count <= (uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0xc)) {
    return;
  }
  size = (*(int *)((int)this + 4) - *(int *)this) / 0xc;
  if (0x15555555U - size < add_count) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("vector<T> too long");
  }
  capacity = (*(int *)((int)this + 8) - *(int *)this) / 0xc;
  required = size + add_count;
  if (0x15555555 - (capacity >> 1) < capacity) {
    capacity = 0;
    if (required != 0) {
      capacity = required;
    }
    vec12_reallocate(this,capacity);
    return;
  }
  capacity = capacity + (capacity >> 1);
  if (capacity < required) {
    capacity = required;
  }
  vec12_reallocate(this,capacity);
  return;
}




/* [AUDIT] proposed: buyNode120  (confidence: med)
 * purpose: Allocates 0x78-byte list sentinel node, self-links if null args
 * vars: add_count/2=prev/next or self
 */
/* Global::buyNode120 @ 004267f0 */

void buyNode120(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x78);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
      prev = node;
      next = node;
    }
    *node = prev;
    if (node + 1 != (undefined4 *)0x0) {
      node[1] = next;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: buyNode80  (confidence: med)
 * purpose: Allocates 0x50-byte list node, self-links if null args
 * vars: list sentinel
 */
/* Global::buyNode80 @ 004268b0 */

void buyNode80(undefined4 *prev,undefined4 *next)

{
  undefined4 *node;
  
  node = operator_new(0x50);
  if (node != (void *)0x0) {
    if (prev == (undefined4 *)0x0) {
      prev = node;
      next = node;
    }
    *node = prev;
    if (node + 1 != (undefined4 *)0x0) {
      node[1] = next;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xbad_alloc();
}




/* [AUDIT] proposed: vecInt_reallocate  (confidence: high)
 * purpose: Reallocates 4-byte-element (int/ptr) vector, memmoves old data, frees old buffer
 * vars: this begin/end/cap; element 4 bytes; prev=new cap; max 0x40000000
 */
/* Global::vecInt_reallocate @ 00426d30 */

void __thiscall vecInt_reallocate(void *this,uint new_capacity)

{
  void *old_buffer;
  int old_end;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if (new_capacity != 0) {
    if (new_capacity < 0x40000000) {
      _Dst = operator_new(new_capacity * 4);
      if (_Dst != (void *)0x0) goto LAB_00426d65;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_00426d65:
  memmove(_Dst,*(void **)this,*(int *)((int)this + 4) - (int)*(void **)this & 0xfffffffc);
  old_buffer = *(void **)this;
  old_end = *(int *)((int)this + 4);
  if (old_buffer != (void *)0x0) {
    operator_delete(old_buffer);
  }
  *(void **)((int)this + 8) = (void *)((int)_Dst + new_capacity * 4);
  *(void **)this = _Dst;
  *(void **)((int)this + 4) = (void *)((int)_Dst + (old_end - (int)old_buffer >> 2) * 4);
  return;
}




/* [AUDIT] proposed: vecInt_reserveGrow  (confidence: high)
 * purpose: Ensures int-vector capacity for new_capacity more elements with 1.5x growth policy
 * vars: this=vector; element 4 bytes
 */
/* Global::vecInt_reserveGrow @ 00426eb0 */

void __thiscall vecInt_reserveGrow(void *this,uint add_count)

{
  uint capacity;
  int size;
  uint required;
  
  if (add_count <= (uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 2)) {
    return;
  }
  size = *(int *)((int)this + 4) - *(int *)this >> 2;
  if (0x3fffffffU - size < add_count) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("vector<T> too long");
  }
  required = size + add_count;
  capacity = *(int *)((int)this + 8) - *(int *)this >> 2;
  if (0x3fffffff - (capacity >> 1) < capacity) {
    capacity = 0;
    if (required != 0) {
      capacity = required;
    }
    vecInt_reallocate(this,capacity);
    return;
  }
  capacity = capacity + (capacity >> 1);
  if (capacity < required) {
    capacity = required;
  }
  vecInt_reallocate(this,capacity);
  return;
}




/* [AUDIT] proposed: World_getTileAtCoords  (confidence: high)
 * purpose: Bounds-checks (x,y)<0x2000, locates chunk via /64 then indexes 8x8 subtile (0x68 bytes) returning tile ptr
 * vars: this=world; add_count=x,param_2=y; chunk stride 0x68; base off 0x14018
 */
/* Global::World_getTileAtCoords @ 004286f0 */

int __thiscall World_getTileAtCoords(void *this,uint x,uint y)

{
  int cell;
  uint ly;
  uint lx;
  
  if ((((-1 < (int)x) && (-1 < (int)y)) && ((int)x < 0x2000)) &&
     ((int)y < 0x2000)) {
    cell = Grid_lookup1024(this,(int)(x * 8 + ((int)(x * 8) >> 0x1f & 0x3fU)) >> 6,
                         (int)(y * 8 + ((int)(y * 8) >> 0x1f & 0x3fU)) >> 6);
    if (cell != 0) {
      lx = x & 0x80000007;
      if ((int)lx < 0) {
        lx = (lx - 1 | 0xfffffff8) + 1;
      }
      ly = y & 0x80000007;
      if ((int)ly < 0) {
        ly = (ly - 1 | 0xfffffff8) + 1;
      }
      return (ly + lx * 8) * 0x68 + 0x14018 + cell;
    }
  }
  return 0;
}




/* [AUDIT] proposed: Speech_mapNode_dtor  (confidence: high)
 * purpose: Destroys Speech map-node payload: clears list (+0x20), frees string (+0x10) and inner list (+0x18), then frees node
 * vars: param+0x20 list; +0x10/+0x28 strings
 */
/* Global::Speech_mapNode_dtor @ 0042c2e0 */

void __fastcall Speech_mapNode_dtor(undefined4 *node)

{
  undefined4 *node_ptr;
  
  node_ptr = node;
  std_list_clear(node + 8);
  operator_delete((void *)node[8]);
  SpeechMap_eraseRange(node + 6,&node_ptr,*(int **)node[6],(int *)node[6]);
  operator_delete((void *)node[6]);
  if (7 < (uint)node[5]) {
    operator_delete((void *)*node);
  }
  node[5] = 7;
  node[4] = 0;
  *(undefined2 *)node = 0;
  return;
}




/* [AUDIT] proposed: vec3b_copyBackward  (confidence: high)
 * purpose: copy_backward of 3-byte (RGB) elements [first,last)->dest; std::copy_backward
 * vars: stride 3
 */
/* Global::vec3b_copyBackward @ 0042e920 */

void __cdecl vec3b_copyBackward(undefined1 *src_begin,undefined1 *src_end,undefined1 *dst)

{
  undefined1 *dst_ptr;
  undefined1 *src_ptr;
  
  if (src_begin != src_end) {
    dst_ptr = dst;
    src_ptr = src_begin;
    do {
      *dst_ptr = *src_ptr;
      dst_ptr[1] = dst_ptr[(int)(src_begin + (1 - (int)dst))];
      dst_ptr[2] = src_ptr[2];
      src_ptr = src_ptr + 3;
      dst_ptr = dst_ptr + 3;
    } while (src_ptr != src_end);
  }
  return;
}




/* [AUDIT] proposed: vec3b_uninitCopy  (confidence: high)
 * purpose: uninitialized_copy of 3-byte (RGB) elements; returns dest end; std::copy
 * vars: stride 3; null dest tolerated
 */
/* Global::vec3b_uninitCopy @ 0042e960 */

undefined1 * __cdecl vec3b_uninitCopy(undefined1 *src_begin,undefined1 *src_end,undefined1 *dst)

{
  if (src_begin == src_end) {
    return dst;
  }
  do {
    if (dst != (undefined1 *)0x0) {
      *dst = *src_begin;
      dst[1] = src_begin[1];
      dst[2] = src_begin[2];
    }
    src_begin = src_begin + 3;
    dst = dst + 3;
  } while (src_begin != src_end);
  return dst;
}




/* [AUDIT] proposed: vec3b_reallocate  (confidence: high)
 * purpose: Reallocates vector of 3-byte elements to capacity src_begin, moves via 42e960, frees old; std::vector growth
 * vars: stride 3; this[0..2] begin/end/cap
 */
/* Global::vec3b_reallocate @ 0042f250 */

void __thiscall vec3b_reallocate(void *this,uint new_count)

{
  int old_end;
  int old_begin;
  undefined1 *new_buf;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d2c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  new_buf = (undefined1 *)0x0;
  if (new_count != 0) {
    if (new_count < 0x55555556) {
      new_buf = operator_new(new_count * 3);
      if (new_buf != (undefined1 *)0x0) goto LAB_0042f2ac;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_0042f2ac:
  local_8 = 0;
  vec3b_uninitCopy(*(undefined1 **)this,*(undefined1 **)((int)this + 4),new_buf);
  old_end = *(int *)((int)this + 4);
  old_begin = *(int *)this;
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined1 **)((int)this + 8) = new_buf + new_count * 3;
  *(undefined1 **)((int)this + 4) = new_buf + ((old_end - old_begin) / 3) * 3;
  *(undefined1 **)this = new_buf;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: vec3b_reserveGrow  (confidence: high)
 * purpose: Ensures vector<3byte> has room for new_count more (1.5x growth); 'vector<T> too long'; calls 42f250
 * vars: cap = (end-begin)/3
 */
/* Global::vec3b_reserveGrow @ 0042f330 */

void __thiscall vec3b_reserveGrow(void *this,uint add_count)

{
  int cur_size;
  uint new_cap;
  uint needed;
  
  if (add_count <= (uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 3)) {
    return;
  }
  cur_size = (*(int *)((int)this + 4) - *(int *)this) / 3;
  if (0x55555555U - cur_size < add_count) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("vector<T> too long");
  }
  new_cap = (*(int *)((int)this + 8) - *(int *)this) / 3;
  needed = cur_size + add_count;
  if (0x55555555 - (new_cap >> 1) < new_cap) {
    new_cap = 0;
    if (needed != 0) {
      new_cap = needed;
    }
    vec3b_reallocate(this,new_cap);
    return;
  }
  new_cap = new_cap + (new_cap >> 1);
  if (new_cap < needed) {
    new_cap = needed;
  }
  vec3b_reallocate(this,new_cap);
  return;
}




/* [AUDIT] proposed: vec_ptr_resize  (confidence: high)
 * purpose: Resizes vector<void*> (4-byte elems) to add_count: shrink via memmove or grow+zero via 426eb0; std::vector::resize
 * vars: stride 4
 */
/* Global::vec_ptr_resize @ 0045f080 */

void __thiscall vec_ptr_resize(void *this,uint new_size)

{
  void *_Dst;
  void *_Src;
  void *pvVar1;
  uint cur_count;
  int fill_count;
  undefined4 *fill_ptr;
  
  _Src = *(void **)((int)this + 4);
  pvVar1 = *(void **)this;
  cur_count = (int)_Src - (int)pvVar1 >> 2;
  if (new_size < cur_count) {
    _Dst = (void *)((int)pvVar1 + new_size * 4);
    if (_Dst == pvVar1) {
      *(void **)((int)this + 4) = pvVar1;
      return;
    }
    if (_Dst != _Src) {
      memmove(_Dst,_Src,0);
      *(void **)((int)this + 4) = _Dst;
      return;
    }
  }
  else if (cur_count < new_size) {
    vecInt_reserveGrow(this,new_size - cur_count);
    fill_ptr = *(undefined4 **)((int)this + 4);
    fill_count = new_size - ((int)fill_ptr - *(int *)this >> 2);
    if (fill_count != 0) {
      for (; fill_count != 0; fill_count = fill_count + -1) {
        *fill_ptr = 0;
        fill_ptr = fill_ptr + 1;
      }
    }
    *(uint *)((int)this + 4) =
         *(int *)((int)this + 4) + (new_size - (*(int *)((int)this + 4) - *(int *)this >> 2)) * 4;
  }
  return;
}




/* [AUDIT] proposed: VoxelGrid::cellAt3D  (confidence: high)
 * purpose: Bounds-checked accessor into 3D voxel grid returning 0xc-byte cell ptr; returns dummy on OOB
 * vars: +0x64/+0x68/+0x6c=dims x/y/z; +0x70=data base; stride 0xc; VoxelGrid_remapCoords remaps coords
 */
/* Global::VoxelGrid_cellAt3D @ 004d1950 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __thiscall VoxelGrid_cellAt3D(void *this,int x,int y,int z)

{
  VoxelGrid_remapCoords(this,&x,&y);
  if ((((-1 < x) && (-1 < y)) && (-1 < z)) &&
     (((x < *(int *)((int)this + 100) && (y < *(int *)((int)this + 0x68))) &&
      (z < *(int *)((int)this + 0x6c))))) {
    return (undefined *)
           (*(int *)((int)this + 0x70) +
           ((*(int *)((int)this + 0x68) * z + y) * *(int *)((int)this + 100) + x)
           * 0xc);
  }
  if ((DAT_00584264 & 1) == 0) {
    DAT_00584264 = DAT_00584264 | 1;
    _DAT_00584259 = 0;
    DAT_0058425b = 0;
    _DAT_0058425c = 0;
    DAT_00584260 = 0;
  }
  DAT_00584258 = 0;
  return &DAT_00584258;
}




/* [AUDIT] proposed: Creature::moveToward  (confidence: med)
 * purpose: Computes normalized direction from x to y, if within range param_4 calls step/move helper
 * vars: 1.5258789e-05=1/65536 fixed->float; z=flag; Creature_stepAlongPath=path step
 */
/* Global::Creature_moveToward @ 004d4d80 */

void Creature_moveToward(uint *from_pos,uint *to_pos,char param_3,float max_dist)

{
  float10 fVar1;
  double dVar2;
  float dist_sq;
  float dz;
  void *local_40;
  uint *local_3c;
  float length;
  float dx;
  float dy;
  float nz;
  int local_28;
  int iStack_24;
  int local_20;
  int iStack_1c;
  int local_18;
  int iStack_14;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&dz;
  local_3c = from_pos;
  local_28 = *to_pos - *from_pos;
  iStack_24 = (to_pos[1] - from_pos[1]) - (uint)(*to_pos < *from_pos);
  local_20 = to_pos[2] - from_pos[2];
  iStack_1c = (to_pos[3] - from_pos[3]) - (uint)(to_pos[2] < from_pos[2]);
  local_18 = to_pos[4] - from_pos[4];
  iStack_14 = (to_pos[5] - from_pos[5]) - (uint)(to_pos[4] < from_pos[4]);
  dx = (float)CONCAT44(iStack_24,local_28) * 1.5258789e-05;
  dy = (float)CONCAT44(iStack_1c,local_20) * 1.5258789e-05;
  dz = (float)CONCAT44(iStack_14,local_18) * 1.5258789e-05;
  dist_sq = dy * dy + dx * dx + dz * dz;
  if (dist_sq < 0.0001) {
    __security_check_cookie(security_cookie ^ (uint)&dz);
    return;
  }
  if (max_dist * max_dist < dist_sq) {
    __security_check_cookie(security_cookie ^ (uint)&dz);
    return;
  }
  dVar2 = (double)dist_sq;
  libm_sse2_sqrt_precise();
  length = (float)dVar2;
  dx = dx / length;
  dy = dy / length;
  nz = dz / length;
  fVar1 = (float10)Creature_stepAlongPath(local_40,local_3c,&dx,length,'\0',param_3);
  local_40 = (void *)(float)fVar1;
  __security_check_cookie(security_cookie ^ (uint)&dz);
  return;
}




/* [AUDIT] proposed: World::sampleTerrainGradient  (confidence: med)
 * purpose: Computes 2-component terrain gradient/flow from multiple value-noise samples at scaled world coords
 * vars: this+0x8001fc..+0x800218=noise seed offsets; to_pos/3=x/y; 6.1e-05=1/16384
 */
/* Global::World_sampleTerrainGradient @ 004d5a80 */

double * __thiscall World_sampleTerrainGradient(void *this,double *out,int x,int y)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  double dVar4;
  double x_scaled2;
  double x_scaled;
  double y_scaled2;
  double y_scaled;
  
  y_scaled2 = (double)y * 0.01;
  y_scaled = (double)y * 0.0005;
  x_scaled = (double)x * 0.01;
  x_scaled2 = (double)x * 0.0005;
  dVar4 = (double)*(int *)((int)this + 0x800204) + x_scaled;
  fVar2 = valueNoise2D(SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20),
                       (double)*(int *)((int)this + 0x800208) + y_scaled2);
  dVar4 = (double)*(int *)((int)this + 0x8001fc) + x_scaled2;
  fVar3 = valueNoise2D(SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20),
                       (double)*(int *)((int)this + 0x800200) + y_scaled);
  iVar1 = *(int *)((int)this + 0x800218);
  x_scaled = (double)*(int *)((int)this + 0x800214) + x_scaled;
  *out = ((double)(float)fVar2 * 0.1 + (double)(float)fVar3) * 500.0 * 6.103515625e-05 +
             (double)x * 6.103515625e-05;
  fVar2 = valueNoise2D(SUB84(x_scaled,0),(int)((ulonglong)x_scaled >> 0x20),(double)iVar1 + y_scaled2);
  x_scaled2 = (double)*(int *)((int)this + 0x80020c) + x_scaled2;
  fVar3 = valueNoise2D(SUB84(x_scaled2,0),(int)((ulonglong)x_scaled2 >> 0x20),
                       (double)*(int *)((int)this + 0x800210) + y_scaled);
  out[1] = ((double)(float)fVar2 * 0.1 + (double)(float)fVar3) * 500.0 * 6.103515625e-05 +
               (double)y * 6.103515625e-05;
  return out;
}




/* [AUDIT] proposed: Creature::stepAlongPath  (confidence: low)
 * purpose: Iterative path/raycast stepping over voxel terrain sampling walkable cells up to 500 iters
 * vars: __alldiv/0x10000 fixed->cells; y=max dist; param_4=target block type; local_14=cur cell
 */
/* Global::Creature_stepAlongPath @ 004d6730 */

/* WARNING: Removing unreachable block (ram,0x004d72e4) */
/* WARNING: Removing unreachable block (ram,0x004d7570) */
/* WARNING: Removing unreachable block (ram,0x004d77b4) */

void __thiscall
Creature_stepAlongPath(void *this,uint *origin,float *direction,float max_dist,char solid_flag,char mode)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  undefined *puVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  void *this_00;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  float *pfVar17;
  uint uVar18;
  bool bVar19;
  float fVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  undefined8 uVar23;
  ulonglong uVar24;
  uint step;
  float local_194;
  int local_190;
  float nearest;
  float local_17c;
  float t_accum;
  uint local_168 [31];
  int iStack_ec;
  int local_e8;
  undefined8 local_e4;
  undefined8 local_dc;
  undefined8 local_d4;
  undefined8 local_cc;
  undefined8 local_c4;
  undefined8 local_bc;
  uint local_b4;
  uint local_b0;
  undefined8 local_ac;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  uint local_7c;
  uint local_78;
  undefined8 local_74;
  float local_6c;
  undefined8 local_68;
  float local_60;
  undefined8 local_5c;
  float local_54;
  undefined8 local_50;
  float local_48;
  undefined8 local_44;
  float local_3c;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  int local_18;
  uint voxel [4];
  
  voxel[3] = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  uVar11 = origin[1];
  t_accum = 0.0;
  uVar21 = __alldiv(*origin,uVar11,0x10000,0);
  voxel[0] = (uint)uVar21;
  uVar21 = __alldiv(origin[2],origin[3],0x10000,0);
  voxel[1] = (uint)uVar21;
  uVar21 = __alldiv(origin[4],origin[5],0x10000,0);
  voxel[2] = (int)uVar21;
  if (((int)uVar11 < 1) && ((int)uVar11 < 0)) {
    voxel[0] = voxel[0] - 1;
  }
  if (((int)origin[3] < 1) && ((int)origin[3] < 0)) {
    voxel[1] = voxel[1] - 1;
  }
  if (((int)origin[5] < 1) && ((int)origin[5] < 0)) {
    voxel[2] = (int)uVar21 + -1;
  }
  step = 0;
  if (0.0 < max_dist) {
    do {
      uVar2 = voxel[2];
      uVar11 = voxel[1];
      if (((((int)voxel[0] < 0) || ((int)voxel[1] < 0)) || (0xffffff < (int)voxel[0])) ||
         ((0xffffff < (int)voxel[1] ||
          (iVar6 = Region_getChunkCell(this,(int)(voxel[0] + ((int)voxel[0] >> 0x1f & 0xffU)) >> 8,
                                (int)(voxel[1] + ((int)voxel[1] >> 0x1f & 0xffU)) >> 8),
          iVar6 == 0)))) {
LAB_004d68cf:
        puVar7 = &DAT_00584248;
      }
      else {
        uVar11 = uVar11 & 0x800000ff;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xffffff00) + 1;
        }
        uVar9 = voxel[0] & 0x800000ff;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xffffff00) + 1;
        }
        this_00 = (void *)((uVar11 * 0x100 + uVar9) * 0x20 + *(int *)(iVar6 + 0xa8));
        if ((this_00 == (void *)0x0) || (iVar6 = *(int *)((int)this_00 + 0x10), (int)uVar2 < iVar6))
        goto LAB_004d68cf;
        if ((int)uVar2 < *(int *)((int)this_00 + 0x1c) + iVar6) {
          puVar7 = Column_getBlockChecked(this_00,uVar2 - iVar6);
          if ((((puVar7[3] & 0x1f) == 0) && ((int)uVar2 < 1)) && ((puVar7[3] & 0x40) == 0)) {
            puVar7 = &DAT_00584240;
          }
        }
        else {
          puVar7 = &DAT_00584240;
          if (0 < (int)uVar2) {
            puVar7 = &DAT_00584244;
          }
        }
      }
      if (((puVar7[3] & 0x1f) == 0) || ((puVar7[3] & 0x1f) == 2)) {
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      if ((cVar5 != solid_flag) || (500 < (int)step)) break;
      local_5c._0_4_ = (float)*(undefined8 *)direction;
      step = step + 1;
      local_5c._4_4_ = (float)((ulonglong)*(undefined8 *)direction >> 0x20);
      iVar6 = 0;
      local_5c = CONCAT44(local_5c._4_4_ * t_accum,(float)local_5c * t_accum);
      local_54 = direction[2] * t_accum;
      do {
        uVar22 = ftol2();
        local_168[iVar6 * 2 + 0x18] = (uint)uVar22;
        local_168[iVar6 * 2 + 0x19] = (uint)(uVar22 >> 0x20);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      fVar20 = 10.0;
      local_38._0_4_ = (uint)*(undefined8 *)origin;
      local_38._4_4_ = (int)((ulonglong)*(undefined8 *)origin >> 0x20);
      local_38 = CONCAT44(local_38._4_4_ + local_168[0x19] +
                          (uint)CARRY4((uint)local_38,local_168[0x18]),
                          (uint)local_38 + local_168[0x18]);
      local_30._0_4_ = (uint)*(undefined8 *)(origin + 2);
      local_30._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 2) >> 0x20);
      local_30 = CONCAT44(local_30._4_4_ + local_168[0x1b] +
                          (uint)CARRY4((uint)local_30,local_168[0x1a]),
                          (uint)local_30 + local_168[0x1a]);
      local_28._0_4_ = (uint)*(undefined8 *)(origin + 4);
      local_28._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 4) >> 0x20);
      local_28 = CONCAT44(local_28._4_4_ + local_168[0x1d] +
                          (uint)CARRY4((uint)local_28,local_168[0x1c]),
                          (uint)local_28 + local_168[0x1c]);
      fVar8 = 0.0;
      fVar13 = 0.0;
      nearest = 10.0;
      local_194 = 0.0;
      pfVar17 = direction;
      do {
        fVar1 = *pfVar17;
        if (1e-06 <= fVar1 * fVar1) {
          if (fVar1 <= 0.0) {
            uVar22 = ftol2();
          }
          else {
            uVar22 = ftol2();
          }
          local_17c = (float)(longlong)uVar22;
          local_17c = local_17c * 1.5258789e-05;
          fVar8 = local_194;
          fVar20 = nearest;
          if (local_17c < nearest) {
            fVar8 = fVar13;
            fVar20 = local_17c;
            nearest = local_17c;
            local_194 = fVar13;
          }
        }
        fVar13 = (float)((int)fVar13 + 1);
        pfVar17 = pfVar17 + 1;
      } while ((int)fVar13 < 3);
      if (direction[(int)fVar8] <= 0.0) {
        voxel[(int)fVar8] = voxel[(int)fVar8] - 1;
      }
      else {
        voxel[(int)fVar8] = voxel[(int)fVar8] + 1;
      }
      t_accum = t_accum + fVar20;
    } while (t_accum < max_dist);
  }
  if (max_dist < t_accum) {
    t_accum = max_dist;
  }
  if (mode != '\0') {
    uVar11 = origin[1];
    uVar2 = *origin;
    uVar21 = __alldiv(uVar2,uVar11,0x10000,0);
    uVar9 = origin[2];
    uVar3 = origin[3];
    uVar23 = __alldiv(uVar9,uVar3,0x10000,0);
    uVar14 = (int)(((int)uVar21 >> 0x1f & 0xffU) + (int)uVar21) >> 8;
    uVar12 = (int)(((int)uVar23 >> 0x1f & 0xffU) + (int)uVar23) >> 8;
    uVar15 = (int)(((int)voxel[0] >> 0x1f & 0xffU) + voxel[0]) >> 8;
    uVar18 = (int)(((int)voxel[1] >> 0x1f & 0xffU) + voxel[1]) >> 8;
    nearest = (float)uVar14;
    if ((int)uVar15 < (int)uVar14) {
      nearest = (float)uVar15;
      uVar15 = uVar14;
    }
    uVar14 = uVar12;
    if ((int)uVar18 < (int)uVar12) {
      uVar14 = uVar18;
      uVar18 = uVar12;
    }
    step = uVar14;
    local_b4 = (uint)nearest;
    local_b0 = uVar14;
    local_7c = uVar15;
    local_78 = uVar18;
    if ((int)nearest <= (int)uVar15) {
      do {
        if ((int)uVar14 <= (int)uVar18) {
          do {
            if ((((-1 < (int)nearest) && (-1 < (int)uVar14)) && ((int)nearest < 0x10000)) &&
               ((int)uVar14 < 0x10000)) {
              iVar6 = (int)((int)nearest + ((int)nearest >> 0x1f & 0x3fU)) >> 6;
              iVar10 = (int)(((int)uVar14 >> 0x1f & 0x3fU) + uVar14) >> 6;
              if (((-1 < iVar6) && (-1 < iVar10)) &&
                 ((iVar6 < 0x400 &&
                  ((iVar10 < 0x400 &&
                   (iVar6 = *(int *)((int)this + (iVar6 * 0x400 + iVar10) * 4 + 0xbc), iVar6 != 0)))
                  ))) {
                uVar15 = (uint)nearest & 0x8000003f;
                if ((int)uVar15 < 0) {
                  uVar15 = (uVar15 - 1 | 0xffffffc0) + 1;
                }
                uVar12 = uVar14 & 0x8000003f;
                if ((int)uVar12 < 0) {
                  uVar12 = (uVar12 - 1 | 0xffffffc0) + 1;
                }
                iVar6 = *(int *)(iVar6 + 0x10018 + (uVar15 * 0x40 + uVar12) * 4);
                if (iVar6 != 0) {
                  piVar4 = *(int **)(iVar6 + 0x10);
                  fVar8 = t_accum;
                  for (piVar16 = *(int **)(iVar6 + 0xc); t_accum = fVar8, piVar16 != piVar4;
                      piVar16 = piVar16 + 0x62) {
                    iVar6 = *piVar16;
                    if (((((iVar6 == 4) || (iVar6 == 3)) || (iVar6 == 5)) || (iVar6 == 8)) &&
                       ((char)piVar16[0xc] != '\0')) {
                      iVar6 = piVar16[9];
                      local_20 = *(undefined8 *)(piVar16 + 9);
                      local_18 = piVar16[0xb];
                      uVar18 = piVar16[8] & 0x80000001;
                      bVar19 = uVar18 == 0;
                      if ((int)uVar18 < 0) {
                        bVar19 = (uVar18 - 1 | 0xfffffffe) == 0xffffffff;
                      }
                      if (!bVar19) {
                        local_20 = CONCAT44(iVar6,piVar16[10]);
                        local_168[0x1e] = piVar16[10];
                        iStack_ec = iVar6;
                        local_e8 = local_18;
                      }
                      fVar20 = *direction;
                      if (fVar20 != 0.0) {
                        uVar22 = ftol2();
                        uVar18 = piVar16[2];
                        iVar6 = piVar16[3];
                        uVar15 = uVar18 - (uint)uVar22;
                        fVar13 = ((float)CONCAT44((((iVar6 - (int)(uVar22 >> 0x20)) -
                                                   (uint)(uVar18 < (uint)uVar22)) - uVar11) -
                                                  (uint)(uVar15 < uVar2),uVar15 - uVar2) *
                                 1.5258789e-05) / fVar20;
                        if ((0.0 <= fVar13) && (fVar13 < fVar8)) {
                          iVar10 = 0;
                          local_44._0_4_ = (float)*(undefined8 *)direction;
                          local_44._4_4_ = (float)((ulonglong)*(undefined8 *)direction >> 0x20);
                          local_44 = CONCAT44(local_44._4_4_ * fVar13,(float)local_44 * fVar13);
                          local_3c = direction[2] * fVar13;
                          do {
                            uVar24 = ftol2();
                            local_168[iVar10 * 2 + 6] = (uint)uVar24;
                            local_168[iVar10 * 2 + 7] = (uint)(uVar24 >> 0x20);
                            iVar10 = iVar10 + 1;
                          } while (iVar10 < 3);
                          local_ac = *(undefined8 *)origin;
                          local_a4._0_4_ = (uint)*(undefined8 *)(origin + 2);
                          uVar15 = (uint)local_a4 + local_168[8];
                          local_a4._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 2) >> 0x20);
                          local_9c._0_4_ = (uint)*(undefined8 *)(origin + 4);
                          local_9c._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 4) >> 0x20);
                          local_a4 = CONCAT44(local_a4._4_4_ + local_168[9] +
                                              (uint)CARRY4((uint)local_a4,local_168[8]),uVar15);
                          local_9c = CONCAT44(local_9c._4_4_ + local_168[0xb] +
                                              (uint)CARRY4((uint)local_9c,local_168[10]),
                                              (uint)local_9c + local_168[10]);
                          uVar24 = ftol2();
                          fVar1 = (float)piVar16[4];
                          local_190 = (int)(uVar24 >> 0x20);
                          iVar10 = (piVar16[5] - local_190) - (uint)((uint)fVar1 < (uint)local_194);
                          if ((iVar10 <= local_a4._4_4_) &&
                             ((iVar10 < local_a4._4_4_ ||
                              ((uint)((int)fVar1 - (int)local_194) <= uVar15)))) {
                            if ((piVar16[7] <= local_9c._4_4_) &&
                               ((piVar16[7] < local_9c._4_4_ || ((uint)piVar16[6] <= (uint)local_9c)
                                ))) {
                              local_194 = (float)uVar24;
                              iVar10 = piVar16[5] + local_190 +
                                       (uint)CARRY4((uint)fVar1,(uint)local_194);
                              if ((local_a4._4_4_ <= iVar10) &&
                                 ((local_a4._4_4_ < iVar10 ||
                                  ((uint)local_a4 < (uint)((int)fVar1 + (int)local_194))))) {
                                uVar24 = ftol2();
                                iVar10 = (int)(uVar24 >> 0x20) + piVar16[7] +
                                         (uint)CARRY4((uint)uVar24,piVar16[6]);
                                if ((local_9c._4_4_ <= iVar10) &&
                                   ((t_accum = fVar13, local_9c._4_4_ < iVar10 ||
                                    ((uint)local_9c < (uint)uVar24 + piVar16[6]))))
                                goto LAB_004d70ee;
                              }
                            }
                          }
                          t_accum = fVar8;
                        }
LAB_004d70ee:
                        fVar20 = ((float)(longlong)
                                         (uVar22 + CONCAT44((iVar6 - uVar11) -
                                                            (uint)(uVar18 < uVar2),uVar18 - uVar2))
                                 * 1.5258789e-05) / fVar20;
                        if ((0.0 <= fVar20) && (fVar20 < t_accum)) {
                          iVar6 = 0;
                          local_74._0_4_ = (float)*(undefined8 *)direction;
                          local_74._4_4_ = (float)((ulonglong)*(undefined8 *)direction >> 0x20);
                          local_74 = CONCAT44(local_74._4_4_ * fVar20,(float)local_74 * fVar20);
                          local_6c = direction[2] * fVar20;
                          do {
                            uVar22 = ftol2();
                            local_168[iVar6 * 2 + 0xc] = (uint)uVar22;
                            local_168[iVar6 * 2 + 0xd] = (uint)(uVar22 >> 0x20);
                            iVar6 = iVar6 + 1;
                          } while (iVar6 < 3);
                          local_e4 = *(undefined8 *)origin;
                          local_dc._0_4_ = (uint)*(undefined8 *)(origin + 2);
                          uVar12 = (uint)local_dc + local_168[0xe];
                          local_dc._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 2) >> 0x20);
                          local_d4._0_4_ = (uint)*(undefined8 *)(origin + 4);
                          uVar15 = (uint)local_d4 + local_168[0x10];
                          local_d4._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 4) >> 0x20);
                          local_dc = CONCAT44(local_dc._4_4_ + local_168[0xf] +
                                              (uint)CARRY4((uint)local_dc,local_168[0xe]),uVar12);
                          local_d4 = CONCAT44(local_d4._4_4_ + local_168[0x11] +
                                              (uint)CARRY4((uint)local_d4,local_168[0x10]),uVar15);
                          uVar22 = ftol2();
                          uVar18 = piVar16[4];
                          iVar6 = (piVar16[5] - (int)(uVar22 >> 0x20)) -
                                  (uint)(uVar18 < (uint)uVar22);
                          if ((iVar6 <= local_dc._4_4_) &&
                             ((iVar6 < local_dc._4_4_ || (uVar18 - (uint)uVar22 <= uVar12)))) {
                            if ((piVar16[7] <= local_d4._4_4_) &&
                               (((piVar16[7] < local_d4._4_4_ || ((uint)piVar16[6] <= uVar15)) &&
                                (CONCAT44(local_dc._4_4_,uVar12) <
                                 (longlong)(uVar22 + *(longlong *)(piVar16 + 4)))))) {
                              uVar22 = ftol2();
                              iVar6 = (int)(uVar22 >> 0x20) + piVar16[7] +
                                      (uint)CARRY4((uint)uVar22,piVar16[6]);
                              if ((local_d4._4_4_ <= iVar6) &&
                                 ((local_d4._4_4_ < iVar6 || (uVar15 < (uint)uVar22 + piVar16[6]))))
                              {
                                t_accum = fVar20;
                              }
                            }
                          }
                        }
                      }
                      local_194 = direction[1];
                      if (local_194 != 0.0) {
                        uVar22 = ftol2();
                        uVar18 = piVar16[4];
                        iVar6 = piVar16[5];
                        uVar15 = uVar18 - (uint)uVar22;
                        fVar20 = ((float)CONCAT44((((iVar6 - (int)(uVar22 >> 0x20)) -
                                                   (uint)(uVar18 < (uint)uVar22)) - uVar3) -
                                                  (uint)(uVar15 < uVar9),uVar15 - uVar9) *
                                 1.5258789e-05) / local_194;
                        fVar8 = t_accum;
                        if ((0.0 <= fVar20) && (fVar20 < t_accum)) {
                          iVar10 = 0;
                          local_50._0_4_ = (float)*(undefined8 *)direction;
                          local_50._4_4_ = (float)((ulonglong)*(undefined8 *)direction >> 0x20);
                          local_50 = CONCAT44(local_50._4_4_ * fVar20,(float)local_50 * fVar20);
                          local_48 = direction[2] * fVar20;
                          do {
                            uVar24 = ftol2();
                            local_168[iVar10 * 2 + 0x12] = (uint)uVar24;
                            local_168[iVar10 * 2 + 0x13] = (uint)(uVar24 >> 0x20);
                            iVar10 = iVar10 + 1;
                          } while (iVar10 < 3);
                          local_8c = *(undefined8 *)(origin + 2);
                          local_94._0_4_ = (uint)*(undefined8 *)origin;
                          uVar12 = (uint)local_94 + local_168[0x12];
                          local_94._4_4_ = (int)((ulonglong)*(undefined8 *)origin >> 0x20);
                          local_84._0_4_ = (uint)*(undefined8 *)(origin + 4);
                          local_84._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 4) >> 0x20);
                          local_94 = CONCAT44(local_94._4_4_ + local_168[0x13] +
                                              (uint)CARRY4((uint)local_94,local_168[0x12]),uVar12);
                          local_84 = CONCAT44(local_84._4_4_ + local_168[0x17] +
                                              (uint)CARRY4((uint)local_84,local_168[0x16]),
                                              (uint)local_84 + local_168[0x16]);
                          uVar24 = ftol2();
                          uVar15 = piVar16[2];
                          iVar10 = (piVar16[3] - (int)(uVar24 >> 0x20)) -
                                   (uint)(uVar15 < (uint)uVar24);
                          if ((iVar10 <= local_94._4_4_) &&
                             ((iVar10 < local_94._4_4_ || (uVar15 - (uint)uVar24 <= uVar12)))) {
                            if ((piVar16[7] <= local_84._4_4_) &&
                               (((piVar16[7] < local_84._4_4_ ||
                                 ((uint)piVar16[6] <= (uint)local_84)) &&
                                (local_94 < (longlong)(uVar24 + *(longlong *)(piVar16 + 2)))))) {
                              uVar24 = ftol2();
                              iVar10 = (int)(uVar24 >> 0x20) + piVar16[7] +
                                       (uint)CARRY4((uint)uVar24,piVar16[6]);
                              if ((local_84._4_4_ <= iVar10) &&
                                 ((fVar8 = fVar20, local_84._4_4_ < iVar10 ||
                                  ((uint)local_84 < (uint)uVar24 + piVar16[6])))) goto LAB_004d75c0;
                            }
                          }
                          fVar8 = t_accum;
                        }
LAB_004d75c0:
                        t_accum = fVar8;
                        fVar8 = ((float)(longlong)
                                        (uVar22 + CONCAT44((iVar6 - uVar3) - (uint)(uVar18 < uVar9),
                                                           uVar18 - uVar9)) * 1.5258789e-05) /
                                local_194;
                        if ((0.0 <= fVar8) && (fVar8 < t_accum)) {
                          iVar6 = 0;
                          local_68._0_4_ = (float)*(undefined8 *)direction;
                          local_68._4_4_ = (float)((ulonglong)*(undefined8 *)direction >> 0x20);
                          local_68 = CONCAT44(local_68._4_4_ * fVar8,(float)local_68 * fVar8);
                          local_60 = direction[2] * fVar8;
                          do {
                            uVar22 = ftol2();
                            local_168[iVar6 * 2] = (uint)uVar22;
                            local_168[iVar6 * 2 + 1] = (uint)(uVar22 >> 0x20);
                            iVar6 = iVar6 + 1;
                          } while (iVar6 < 3);
                          local_c4 = *(undefined8 *)(origin + 2);
                          local_cc._0_4_ = (uint)*(undefined8 *)origin;
                          uVar12 = (uint)local_cc + local_168[0];
                          local_cc._4_4_ = (int)((ulonglong)*(undefined8 *)origin >> 0x20);
                          local_bc._0_4_ = (uint)*(undefined8 *)(origin + 4);
                          uVar15 = (uint)local_bc + local_168[4];
                          local_bc._4_4_ = (int)((ulonglong)*(undefined8 *)(origin + 4) >> 0x20);
                          local_cc = CONCAT44(local_cc._4_4_ + local_168[1] +
                                              (uint)CARRY4((uint)local_cc,local_168[0]),uVar12);
                          local_bc = CONCAT44(local_bc._4_4_ + local_168[5] +
                                              (uint)CARRY4((uint)local_bc,local_168[4]),uVar15);
                          uVar22 = ftol2();
                          uVar18 = piVar16[2];
                          iVar6 = (piVar16[3] - (int)(uVar22 >> 0x20)) -
                                  (uint)(uVar18 < (uint)uVar22);
                          if ((iVar6 <= local_cc._4_4_) &&
                             ((iVar6 < local_cc._4_4_ || (uVar18 - (uint)uVar22 <= uVar12)))) {
                            if ((piVar16[7] <= local_bc._4_4_) &&
                               (((piVar16[7] < local_bc._4_4_ || ((uint)piVar16[6] <= uVar15)) &&
                                (CONCAT44(local_cc._4_4_,uVar12) <
                                 (longlong)(uVar22 + *(longlong *)(piVar16 + 2)))))) {
                              uVar22 = ftol2();
                              iVar6 = (int)(uVar22 >> 0x20) + piVar16[7] +
                                      (uint)CARRY4((uint)uVar22,piVar16[6]);
                              if ((local_bc._4_4_ <= iVar6) &&
                                 ((local_bc._4_4_ < iVar6 || (uVar15 < (uint)uVar22 + piVar16[6]))))
                              {
                                t_accum = fVar8;
                              }
                            }
                          }
                        }
                      }
                    }
                    uVar14 = step;
                    uVar18 = local_78;
                    fVar8 = t_accum;
                  }
                }
              }
            }
            uVar14 = uVar14 + 1;
            step = uVar14;
          } while ((int)uVar14 <= (int)uVar18);
          step = local_b0;
          uVar14 = local_b0;
          uVar15 = local_7c;
        }
        nearest = (float)((int)nearest + 1);
      } while ((int)nearest <= (int)uVar15);
    }
  }
  __security_check_cookie(voxel[3] ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004d8e60 @ 004d8e60 */

void __thiscall FUN_004d8e60(void *this,void *param_1)

{
  uint uVar1;
  uint uVar2;
  void *local_20 [4];
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  if (((*(uint *)((int)this + 0x3c) & 2) == 0) &&
     (uVar1 = **(uint **)((int)this + 0x20), uVar1 != 0)) {
    uVar2 = *(uint *)((int)this + 0x38);
    if (*(uint *)((int)this + 0x38) < uVar1) {
      uVar2 = uVar1;
    }
    local_c = 0xf;
    local_10 = 0;
    local_20[0] = (void *)((uint)local_20[0]._1_3_ << 8);
    String_assign(local_20,(int *)**(undefined4 **)((int)this + 0x10),
                 uVar2 - (int)**(undefined4 **)((int)this + 0x10));
    std_string_string_string(param_1,local_20);
    if (0xf < local_c) {
      operator_delete(local_20[0]);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    if (((*(uint *)((int)this + 0x3c) & 4) == 0) && (**(int **)((int)this + 0x1c) != 0)) {
      local_c = 0xf;
      local_10 = 0;
      local_20[0] = (void *)((uint)local_20[0]._1_3_ << 8);
      String_assign(local_20,(int *)**(undefined4 **)((int)this + 0xc),
                   (**(int **)((int)this + 0x2c) + **(int **)((int)this + 0x1c)) -
                   (int)**(undefined4 **)((int)this + 0xc));
    }
    else {
      local_c = 0xf;
      local_10 = 0;
      local_20[0] = (void *)((uint)local_20[0]._1_3_ << 8);
    }
    std_string_string_string(param_1,local_20);
    if (0xf < local_c) {
      operator_delete(local_20[0]);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: VoxelGrid::remapCoords  (confidence: high)
 * purpose: Applies chunk rotation/mirror (orientation in low 2 bits) to (x,y) grid coords; optional y-flip
 * vars: this+4 low2bits=orientation 0-3; +0x64/+0x68=w/h; +8=extra flip flag
 */
/* Global::VoxelGrid_remapCoords @ 004d8f90 */

void __thiscall VoxelGrid_remapCoords(void *this,int *coord_a,int *coord_b)

{
  int tmp;
  uint orientation;
  
  orientation = *(uint *)((int)this + 4) & 0x80000003;
  if ((int)orientation < 0) {
    orientation = (orientation - 1 | 0xfffffffc) + 1;
  }
  if (orientation == 1) {
    tmp = *coord_a;
    *coord_a = *coord_b;
    *coord_b = tmp;
    *coord_a = (*(int *)((int)this + 100) - *coord_a) + -1;
  }
  else if (orientation == 2) {
    *coord_a = (*(int *)((int)this + 100) - *coord_a) + -1;
    *coord_b = (*(int *)((int)this + 0x68) - *coord_b) + -1;
  }
  else if (orientation == 3) {
    tmp = *coord_a;
    *coord_a = *coord_b;
    *coord_b = tmp;
    *coord_b = (*(int *)((int)this + 0x68) - tmp) + -1;
  }
  if (*(char *)((int)this + 8) != '\0') {
    *coord_b = (*(int *)((int)this + 0x68) - *coord_b) + -1;
  }
  return;
}




/* [AUDIT] proposed: Object::construct6  (confidence: low)
 * purpose: Trivial 6-field constructor: 3 scalar params + 3 ints from *param_4
 * vars: this[0..2]=params; this[3..5]=param_4 xyz
 */
/* Global::Object_construct6 @ 004dab60 */

undefined4 * __thiscall
Object_construct6(void *this,undefined4 field0,undefined4 field1,undefined4 field2,undefined4 *vec3
            )

{
  *(undefined4 *)this = field0;
  *(undefined4 *)((int)this + 4) = field1;
  *(undefined4 *)((int)this + 8) = field2;
  *(undefined4 *)((int)this + 0xc) = *vec3;
  *(undefined4 *)((int)this + 0x10) = vec3[1];
  *(undefined4 *)((int)this + 0x14) = vec3[2];
  return this;
}




/* [AUDIT] proposed: NavGraph::reconstructPath  (confidence: med)
 * purpose: Rebuilds a path list by walking predecessor map from goal to start, pushing waypoints; enforces list cap
 * vars: obj+0x1428=start,+0x1440=goal; +0x1460 waypoint list; NavGraph_lookupNode=lookup pred; cap 0xccccccb
 */
/* Global::NavGraph_reconstructPath @ 004dafe0 */

void NavGraph_reconstructPath(void *agent)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iterations;
  undefined4 *puVar5;
  int *open_node;
  int iVar7;
  int iVar8;
  int goal_z;
  int start_pos [3];
  undefined4 *goal_pos;
  int iStack_1c;
  int local_18;
  undefined4 *cur_pos;
  int iStack_10;
  int local_c;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  Vec3i64_toBlockCoords(start_pos,(uint *)((int)agent + 0x1428));
  Vec3i64_toBlockCoords((int *)&goal_pos,(uint *)((int)agent + 0x1440));
  piVar2 = *(int **)((int)agent + 0x1460);
  piVar1 = (int *)((int)agent + 0x1460);
  open_node = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*piVar1 + 4) = *piVar1;
  *(undefined4 *)((int)agent + 0x1464) = 0;
  if (open_node != (int *)*piVar1) {
    do {
      piVar2 = (int *)*open_node;
      operator_delete(open_node);
      open_node = piVar2;
    } while (piVar2 != (int *)*piVar1);
  }
  iStack_10 = iStack_1c;
  puVar5 = goal_pos;
  iVar8 = local_18;
  if (*(int *)((int)agent + 0x1408) != *(int *)((int)agent + 0x140c)) {
    puVar3 = *(undefined4 **)(*(int *)((int)agent + 0x1408) + 0x10);
    iStack_10 = puVar3[1];
    puVar5 = (undefined4 *)*puVar3;
    iVar8 = puVar3[2];
  }
  goal_z = iStack_10;
  puVar3 = *(undefined4 **)*piVar1;
  local_c = iVar8;
  cur_pos = puVar5;
  iterations = std_list_insertNode3(puVar3,(undefined4 *)puVar3[1],&cur_pos);
  if (*(int *)((int)agent + 0x1464) != 0xccccccb) {
    *(int *)((int)agent + 0x1464) = *(int *)((int)agent + 0x1464) + 1;
    puVar3[1] = iterations;
    **(int **)(iterations + 4) = iterations;
    iterations = 0;
    do {
      iVar7 = 0;
      while (*(int *)((int)&cur_pos + iVar7) == *(int *)((int)start_pos + iVar7)) {
        iVar7 = iVar7 + 4;
        if (0xb < iVar7) goto LAB_004db0e5;
      }
      if (*(int *)((int)agent + 0x1410) < iterations) {
LAB_004db0e5:
        __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
        return;
      }
      iterations = iterations + 1;
      puVar5 = NavGraph_lookupNode(agent,puVar5,goal_z,iVar8);
      if (puVar5 == (undefined4 *)0x0) goto LAB_004db0e5;
      iVar8 = puVar5[5];
      goal_pos = (undefined4 *)puVar5[3];
      iStack_1c = puVar5[4];
      local_18 = iVar8;
      iVar7 = 0;
      while (*(int *)((int)&cur_pos + iVar7) == *(int *)((int)&goal_pos + iVar7)) {
        iVar7 = iVar7 + 4;
        if (0xb < iVar7) {
          __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      puVar3 = *(undefined4 **)*piVar1;
      local_c = iVar8;
      cur_pos = (undefined4 *)puVar5[3];
      iStack_10 = puVar5[4];
      iVar7 = std_list_insertNode3(puVar3,(undefined4 *)puVar3[1],&goal_pos);
      if (*(int *)((int)agent + 0x1464) == 0xccccccb) break;
      *(int *)((int)agent + 0x1464) = *(int *)((int)agent + 0x1464) + 1;
      puVar3[1] = iVar7;
      **(int **)(iVar7 + 4) = iVar7;
      goal_z = iStack_10;
      puVar5 = cur_pos;
    } while( true );
  }
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("list<T> too long");
}




/* [AUDIT] proposed: NavGraph::openSetContains  (confidence: med)
 * purpose: Tests whether a 3-int key (x,y,z) exists in the open-set map at this+0x1414
 * vars: builds temp vector key; std_map_lower_bound_vecKey lower_bound; returns membership bool
 */
/* Global::NavGraph_openSetContains @ 004dcff0 */

bool __thiscall NavGraph_openSetContains(void *this,undefined4 *key_x,int key_y,int key_z)

{
  undefined4 *end_node;
  int *key_ptr;
  undefined4 uVar3;
  int *key_node;
  int *local_c;
  undefined4 local_8;
  
  key_node = (int *)0x0;
  local_c = (int *)0x0;
  local_8 = 0;
  vec_ptr_resize(&key_node,3);
  key_ptr = key_node;
  *key_node = (int)key_x;
  key_node[1] = key_y;
  key_node[2] = key_z;
  end_node = *(undefined4 **)((int)this + 0x1414);
  key_x = std_map_lower_bound_vecKey((void *)((int)this + 0x1414),&key_node);
  if (key_x != end_node) {
    uVar3 = std_lexicographical_less(key_ptr,local_c,(int *)key_x[4],(int *)key_x[5]);
    if ((char)uVar3 == '\0') goto LAB_004dd065;
  }
  key_x = end_node;
LAB_004dd065:
  operator_delete(key_node);
  return key_x != end_node;
}




/* [AUDIT] proposed: NavGraph::heuristicCost  (confidence: high)
 * purpose: Weighted manhattan/diagonal distance heuristic from a 3-int delta vector (10/4 weights, x2)
 * vars: abs of param[0..2]; picks weighting by which axis larger
 */
/* Global::NavGraph_heuristicCost @ 004dd090 */

int __cdecl NavGraph_heuristicCost(uint *delta)

{
  uint uVar1;
  int abs_z;
  int abs_x;
  int abs_y;
  
  uVar1 = (int)*delta >> 0x1f;
  abs_x = (*delta ^ uVar1) - uVar1;
  uVar1 = (int)delta[1] >> 0x1f;
  abs_y = (delta[1] ^ uVar1) - uVar1;
  uVar1 = (int)delta[2] >> 0x1f;
  abs_z = (delta[2] ^ uVar1) - uVar1;
  if (abs_y < abs_x) {
    return (abs_x * 10 + abs_y * 4 + abs_z * 10) * 2;
  }
  return (abs_x * 4 + abs_y * 10 + abs_z * 10) * 2;
}




/* [AUDIT] proposed: NavGraph::lookupNode  (confidence: high)
 * purpose: Finds node for 3-int key (x,y,z) in map at this+0x140c; returns value ptr (node+7) or null
 * vars: builds temp vec key; std_map_lower_bound_vecKey find; +7 word offset to value
 */
/* Global::NavGraph_lookupNode @ 004dd0f0 */

undefined4 * __thiscall NavGraph_lookupNode(void *this,undefined4 *key_x,int key_y,int key_z)

{
  undefined4 *end_node;
  int *key_ptr;
  undefined4 uVar3;
  int *key_node;
  int *local_c;
  undefined4 local_8;
  
  key_node = (int *)0x0;
  local_c = (int *)0x0;
  local_8 = 0;
  vec_ptr_resize(&key_node,3);
  key_ptr = key_node;
  *key_node = (int)key_x;
  key_node[1] = key_y;
  key_node[2] = key_z;
  key_x = std_map_lower_bound_vecKey((void *)((int)this + 0x140c),&key_node);
  end_node = *(undefined4 **)((int)this + 0x140c);
  if (key_x != end_node) {
    uVar3 = std_lexicographical_less(key_ptr,local_c,(int *)key_x[4],(int *)key_x[5]);
    if ((char)uVar3 == '\0') goto LAB_004dd165;
  }
  key_x = end_node;
LAB_004dd165:
  if (key_x == end_node) {
    operator_delete(key_ptr);
    return (undefined4 *)0x0;
  }
  operator_delete(key_ptr);
  return key_x + 7;
}




/* [AUDIT] proposed: NavGraph::addNode  (confidence: high)
 * purpose: Inserts a graph node keyed by (x,y,z) into map(+0x140c) and open-set(+0x1414); updates best-open pointer
 * vars: param_4=6-word node value; +0x1408=current best open node; std_map_insertOrAssign insert
 */
/* Global::NavGraph_addNode @ 004dd1a0 */

void __thiscall
NavGraph_addNode(void *this,undefined4 *key_x,int key_y,int key_z,undefined4 *node_data)

{
  int *this_00;
  int *self;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *key_node;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c [2];
  void *self_ptr;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554e48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  key_node = (int *)0x0;
  local_24 = (int *)0x0;
  local_20 = 0;
  self_ptr = this;
  vec_ptr_resize(&key_node,3);
  *key_node = (int)key_x;
  key_node[1] = key_y;
  key_node[2] = key_z;
  this_00 = (int *)((int)this + 0x140c);
  local_8 = 0;
  puVar2 = (undefined4 *)std_map_insertOrAssign(this_00,(int *)&key_node);
  *puVar2 = *node_data;
  puVar2[1] = node_data[1];
  puVar2[2] = node_data[2];
  puVar2[3] = node_data[3];
  puVar2[4] = node_data[4];
  puVar2[5] = node_data[5];
  std_map_insert_vectorKey((void *)((int)this + 0x1414),local_1c,'\0',(int *)&key_node,(uint)DAT_0058426a);
  self = key_node;
  puVar2 = (undefined4 *)*this_00;
  if ((*(undefined4 **)((int)this + 0x1408) != puVar2) &&
     ((int)(*(undefined4 **)((int)this + 0x1408))[8] <= (int)node_data[1])) goto LAB_004dd2b2;
  key_x = std_map_lower_bound_vecKey(this_00,&key_node);
  if (key_x == puVar2) {
LAB_004dd2a1:
    key_x = puVar2;
  }
  else {
    uVar3 = std_lexicographical_less(self,local_24,(int *)key_x[4],(int *)key_x[5]);
    if ((char)uVar3 != '\0') goto LAB_004dd2a1;
  }
  *(undefined4 **)((int)self_ptr + 0x1408) = key_x;
LAB_004dd2b2:
  if (self != (int *)0x0) {
    operator_delete(self);
  }
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: NavGraph::expandNeighbors  (confidence: low)
 * purpose: A* neighbor expansion: samples random offset, iterates object grid cells, adds reachable neighbor nodes
 * vars: obj+0x141c start,+0x1428 goal,+0x1468 grid; NavGraph_addNode=addNode; Region_getChunkCell=chunk lookup
 */
/* Global::NavGraph_expandNeighbors @ 004dd2e0 */

/* WARNING: Removing unreachable block (ram,0x004ddc29) */
/* WARNING: Removing unreachable block (ram,0x004dd78e) */
/* WARNING: Removing unreachable block (ram,0x004dd6d1) */
/* WARNING: Removing unreachable block (ram,0x004dd6fd) */
/* WARNING: Removing unreachable block (ram,0x004dd7bd) */
/* WARNING: Removing unreachable block (ram,0x004ddcdf) */

void __thiscall NavGraph_expandNeighbors(void *this,void *agent)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int heuristic;
  uint uVar20;
  int iVar21;
  int *piVar22;
  ulonglong uVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  uint local_78;
  int local_74;
  uint local_38 [3];
  undefined4 *cur_pos;
  uint local_28;
  int local_24;
  undefined4 local_20;
  int cost;
  int cost2;
  undefined8 local_14;
  float local_c;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  World_clearContainers((int)agent);
  puVar6 = (undefined4 *)Vec3i64_toBlockCoords((int *)&local_14,(uint *)((int)agent + 0x1428));
  *(undefined4 *)((int)agent + 0x141c) = *puVar6;
  *(undefined4 *)((int)agent + 0x1420) = puVar6[1];
  *(undefined4 *)((int)agent + 0x1424) = puVar6[2];
  Vec3i64_toBlockCoords((int *)&cur_pos,(uint *)((int)agent + 0x1428));
  *(undefined4 *)((int)agent + 0x145c) = 0;
  piVar7 = (int *)Vec3i64_toBlockCoords((int *)&local_14,(uint *)((int)agent + 0x1440));
  uVar16 = (int)cur_pos - *piVar7 >> 0x1f;
  heuristic = ((int)cur_pos - *piVar7 ^ uVar16) - uVar16;
  uVar16 = (int)(local_28 - piVar7[1]) >> 0x1f;
  iVar21 = (local_28 - piVar7[1] ^ uVar16) - uVar16;
  uVar16 = local_24 - piVar7[2] >> 0x1f;
  if (iVar21 < heuristic) {
    heuristic = heuristic * 10 + iVar21 * 4;
  }
  else {
    heuristic = heuristic * 4 + iVar21 * 10;
  }
  cost = (int)(float)(int)((heuristic + ((local_24 - piVar7[2] ^ uVar16) - uVar16) * 10) * 2);
  local_20 = 1;
  local_c = (float)local_24;
  cost2 = cost;
  NavGraph_addNode(agent,cur_pos,local_28,local_24,&local_20);
  piVar7 = (int *)((int)agent + 0x1468);
  std_map_clear(piVar7);
  local_14 = 0x3f0000003f000000;
  local_c = *(float *)((int)agent + 0x88) * 0.5;
  heuristic = 0;
  do {
    uVar23 = ftol2();
    local_38[heuristic * 2] = (uint)uVar23;
    local_38[heuristic * 2 + 1] = (uint)(uVar23 >> 0x20);
    heuristic = heuristic + 1;
  } while (heuristic < 3);
  puVar8 = (uint *)Vec3i64_toBlockCoords((int *)&local_14,(uint *)((int)agent + 0x1428));
  uVar16 = *puVar8;
  uVar13 = puVar8[1];
  uVar2 = puVar8[2];
  uVar11 = local_38[0] + uVar16 * 0x10000;
  uVar12 = local_38[1] + (((int)uVar16 >> 0x1f) << 0x10 | uVar16 >> 0x10) +
           (uint)CARRY4(local_38[0],uVar16 * 0x10000);
  uVar20 = local_38[2] + uVar13 * 0x10000;
  uVar13 = (int)cur_pos +
           (uint)CARRY4(local_38[2],uVar13 * 0x10000) +
           (((int)uVar13 >> 0x1f) << 0x10 | uVar13 >> 0x10);
  uVar14 = local_28 + uVar2 * 0x10000;
  iVar21 = local_24 + (((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) +
           (uint)CARRY4(local_28,uVar2 * 0x10000);
  uVar24 = __alldiv(uVar11,uVar12,0x10000,0);
  heuristic = (int)(((int)uVar24 >> 0x1f & 7U) + (int)uVar24) >> 3;
  uVar24 = __alldiv(uVar20,uVar13,0x10000,0);
  uVar16 = heuristic - 1;
  heuristic = heuristic + 1;
  iVar9 = (int)((int)uVar24 + ((int)uVar24 >> 0x1f & 7U)) >> 3;
  if ((int)uVar16 <= heuristic) {
    uVar2 = iVar9 - 1;
    uVar5 = uVar2;
    do {
      for (; (int)uVar5 <= iVar9 + 1; uVar5 = uVar5 + 1) {
        if ((((-1 < (int)uVar16) && (-1 < (int)uVar5)) && ((int)uVar16 < 0x200000)) &&
           (((int)uVar5 < 0x200000 &&
            (iVar10 = Region_getChunkCell(this,(int)(uVar16 + ((int)uVar16 >> 0x1f & 0x1fU)) >> 5,
                                   (int)(uVar5 + ((int)uVar5 >> 0x1f & 0x1fU)) >> 5), iVar10 != 0)))
           ) {
          uVar17 = uVar5 & 0x8000001f;
          if ((int)uVar17 < 0) {
            uVar17 = (uVar17 - 1 | 0xffffffe0) + 1;
          }
          uVar15 = uVar16 & 0x8000001f;
          if ((int)uVar15 < 0) {
            uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
          }
          piVar1 = (int *)(*(int *)(iVar10 + 0xac) + (uVar17 * 0x20 + uVar15) * 8);
          if ((piVar1 != (int *)0x0) && (piVar22 = *(int **)*piVar1, piVar22 != (int *)*piVar1)) {
            do {
              piVar3 = (int *)piVar22[2];
              iVar10 = *piVar3;
              if (((iVar10 != 7) && ((iVar10 != 6 && (iVar10 != 9)))) &&
                 (((iVar10 != 1 &&
                   ((((iVar10 != 8 && (iVar10 != 2)) && (iVar10 != 3)) && (iVar10 != 5)))) ||
                  ((char)piVar3[0xc] != '\0')))) {
                local_c = (float)piVar3[0xb];
                local_14 = *(undefined8 *)(piVar3 + 9);
                uVar23 = ftol2();
                uVar25 = ftol2();
                uVar17 = piVar3[2];
                if ((CONCAT44((piVar3[3] - (int)(uVar23 >> 0x20)) - (uint)(uVar17 < (uint)uVar23),
                              uVar17 - (uint)uVar23) <= (longlong)(uVar25 + CONCAT44(uVar12,uVar11))
                    ) && (CONCAT44((uVar12 - (int)(uVar25 >> 0x20)) - (uint)(uVar11 < (uint)uVar25),
                                   uVar11 - (uint)uVar25) <
                          (longlong)(uVar23 + *(longlong *)(piVar3 + 2)))) {
                  uVar23 = ftol2();
                  uVar25 = ftol2();
                  uVar17 = piVar3[4];
                  if ((CONCAT44((piVar3[5] - (int)(uVar23 >> 0x20)) - (uint)(uVar17 < (uint)uVar23),
                                uVar17 - (uint)uVar23) <=
                       (longlong)(uVar25 + CONCAT44(uVar13,uVar20))) &&
                     (CONCAT44((uVar13 - (int)(uVar25 >> 0x20)) - (uint)(uVar20 < (uint)uVar25),
                               uVar20 - (uint)uVar25) <
                      (longlong)(uVar23 + *(longlong *)(piVar3 + 4)))) {
                    uVar23 = ftol2();
                    lVar4 = uVar23 + CONCAT44(iVar21,uVar14);
                    iVar10 = (int)((ulonglong)lVar4 >> 0x20);
                    if ((piVar3[7] <= iVar10) &&
                       ((piVar3[7] < iVar10 || ((uint)piVar3[6] <= (uint)lVar4)))) {
                      uVar25 = ftol2();
                      iVar18 = (int)(uVar25 >> 0x20) + piVar3[7] +
                               (uint)CARRY4((uint)uVar25,piVar3[6]);
                      iVar10 = (iVar21 - (int)(uVar23 >> 0x20)) - (uint)(uVar14 < (uint)uVar23);
                      if ((iVar10 <= iVar18) &&
                         ((iVar10 < iVar18 || (uVar14 - (uint)uVar23 < (uint)uVar25 + piVar3[6]))))
                      {
                        std_map_insert_scalarKey(piVar7,&local_28,'\0',(uint *)(piVar22 + 2),(uint)DAT_0058426a)
                        ;
                      }
                    }
                  }
                }
              }
              piVar22 = (int *)*piVar22;
            } while (piVar22 != (int *)*piVar1);
          }
        }
      }
      uVar16 = uVar16 + 1;
      uVar5 = uVar2;
    } while ((int)uVar16 <= heuristic);
  }
  local_14 = 0x3f0000003f000000;
  heuristic = 0;
  local_c = *(float *)((int)agent + 0x88) * 0.5;
  do {
    uVar23 = ftol2();
    local_38[heuristic * 2] = (uint)uVar23;
    local_38[heuristic * 2 + 1] = (uint)(uVar23 >> 0x20);
    heuristic = heuristic + 1;
  } while (heuristic < 3);
  puVar8 = (uint *)Vec3i64_toBlockCoords((int *)&local_14,(uint *)((int)agent + 0x1440));
  uVar16 = *puVar8;
  uVar13 = puVar8[1];
  uVar2 = puVar8[2];
  uVar11 = local_38[0] + uVar16 * 0x10000;
  uVar12 = local_38[1] + (((int)uVar16 >> 0x1f) << 0x10 | uVar16 >> 0x10) +
           (uint)CARRY4(local_38[0],uVar16 * 0x10000);
  uVar20 = local_38[2] + uVar13 * 0x10000;
  uVar13 = (int)cur_pos +
           (uint)CARRY4(local_38[2],uVar13 * 0x10000) +
           (((int)uVar13 >> 0x1f) << 0x10 | uVar13 >> 0x10);
  uVar14 = local_28 + uVar2 * 0x10000;
  iVar21 = local_24 + (((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) +
           (uint)CARRY4(local_28,uVar2 * 0x10000);
  uVar24 = __alldiv(uVar11,uVar12,0x10000,0);
  heuristic = (int)(((int)uVar24 >> 0x1f & 7U) + (int)uVar24) >> 3;
  uVar24 = __alldiv(uVar20,uVar13,0x10000,0);
  uVar16 = heuristic - 1;
  heuristic = heuristic + 1;
  iVar9 = (int)((int)uVar24 + ((int)uVar24 >> 0x1f & 7U)) >> 3;
  if ((int)uVar16 <= heuristic) {
    uVar2 = iVar9 - 1;
    uVar5 = uVar2;
    do {
      for (; (int)uVar5 <= iVar9 + 1; uVar5 = uVar5 + 1) {
        if ((((-1 < (int)uVar16) && (-1 < (int)uVar5)) && ((int)uVar16 < 0x200000)) &&
           ((int)uVar5 < 0x200000)) {
          iVar10 = ((int)uVar5 >> 0x1f & 0x1fU) + uVar5;
          uVar15 = iVar10 >> 5;
          iVar18 = ((int)uVar16 >> 0x1f & 0x1fU) + uVar16;
          uVar17 = iVar18 >> 5;
          if (((-1 < (int)uVar17) && (-1 < (int)uVar15)) &&
             (((int)uVar17 < 0x10000 && ((int)uVar15 < 0x10000)))) {
            iVar18 = (int)(uVar17 + (iVar18 >> 0x1f & 0x3fU)) >> 6;
            iVar10 = (int)((iVar10 >> 0x1f & 0x3fU) + uVar15) >> 6;
            if (((-1 < iVar18) && (-1 < iVar10)) &&
               ((iVar18 < 0x400 &&
                ((iVar10 < 0x400 &&
                 (iVar10 = *(int *)((int)this + (iVar18 * 0x400 + iVar10) * 4 + 0xbc), iVar10 != 0))
                )))) {
              uVar17 = uVar17 & 0x8000003f;
              if ((int)uVar17 < 0) {
                uVar17 = (uVar17 - 1 | 0xffffffc0) + 1;
              }
              uVar15 = uVar15 & 0x8000003f;
              if ((int)uVar15 < 0) {
                uVar15 = (uVar15 - 1 | 0xffffffc0) + 1;
              }
              iVar10 = *(int *)(iVar10 + 0x10018 + (uVar17 * 0x40 + uVar15) * 4);
              if (iVar10 != 0) {
                uVar17 = uVar5 & 0x8000001f;
                if ((int)uVar17 < 0) {
                  uVar17 = (uVar17 - 1 | 0xffffffe0) + 1;
                }
                uVar15 = uVar16 & 0x8000001f;
                if ((int)uVar15 < 0) {
                  uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
                }
                piVar1 = (int *)(*(int *)(iVar10 + 0xac) + (uVar17 * 0x20 + uVar15) * 8);
                if ((piVar1 != (int *)0x0) &&
                   (piVar22 = *(int **)*piVar1, piVar22 != (int *)*piVar1)) {
                  do {
                    piVar3 = (int *)piVar22[2];
                    iVar10 = *piVar3;
                    if (((iVar10 != 7) && ((iVar10 != 6 && (iVar10 != 9)))) &&
                       (((iVar10 != 1 &&
                         ((((iVar10 != 8 && (iVar10 != 2)) && (iVar10 != 3)) && (iVar10 != 5)))) ||
                        ((char)piVar3[0xc] != '\0')))) {
                      local_c = (float)piVar3[0xb];
                      local_14 = *(undefined8 *)(piVar3 + 9);
                      uVar23 = ftol2();
                      iVar10 = (int)(uVar23 >> 0x20);
                      uVar17 = (uint)uVar23;
                      uVar23 = ftol2();
                      if (CONCAT44((piVar3[3] - iVar10) - (uint)((uint)piVar3[2] < uVar17),
                                   piVar3[2] - uVar17) <=
                          (longlong)(uVar23 + CONCAT44(uVar12,uVar11))) {
                        local_78 = (uint)uVar23;
                        local_74 = (int)(uVar23 >> 0x20);
                        iVar18 = (uVar12 - local_74) - (uint)(uVar11 < local_78);
                        iVar10 = iVar10 + piVar3[3] + (uint)CARRY4(uVar17,piVar3[2]);
                        if ((iVar18 <= iVar10) &&
                           ((iVar18 < iVar10 || (uVar11 - local_78 < uVar17 + piVar3[2])))) {
                          uVar23 = ftol2();
                          iVar10 = (int)(uVar23 >> 0x20);
                          uVar17 = (uint)uVar23;
                          uVar23 = ftol2();
                          if (CONCAT44((piVar3[5] - iVar10) - (uint)((uint)piVar3[4] < uVar17),
                                       piVar3[4] - uVar17) <=
                              (longlong)(uVar23 + CONCAT44(uVar13,uVar20))) {
                            local_78 = (uint)uVar23;
                            local_74 = (int)(uVar23 >> 0x20);
                            iVar18 = (uVar13 - local_74) - (uint)(uVar20 < local_78);
                            iVar10 = iVar10 + piVar3[5] + (uint)CARRY4(uVar17,piVar3[4]);
                            if ((iVar18 <= iVar10) &&
                               ((iVar18 < iVar10 || (uVar20 - local_78 < uVar17 + piVar3[4])))) {
                              uVar23 = ftol2();
                              lVar4 = uVar23 + CONCAT44(iVar21,uVar14);
                              iVar10 = (int)((ulonglong)lVar4 >> 0x20);
                              if ((piVar3[7] <= iVar10) &&
                                 ((piVar3[7] < iVar10 || ((uint)piVar3[6] <= (uint)lVar4)))) {
                                uVar25 = ftol2();
                                iVar18 = (int)(uVar25 >> 0x20) + piVar3[7] +
                                         (uint)CARRY4((uint)uVar25,piVar3[6]);
                                iVar10 = (iVar21 - (int)(uVar23 >> 0x20)) -
                                         (uint)(uVar14 < (uint)uVar23);
                                if ((iVar10 <= iVar18) &&
                                   ((iVar10 < iVar18 ||
                                    (uVar14 - (uint)uVar23 < (uint)uVar25 + piVar3[6])))) {
                                  std_map_insert_scalarKey(piVar7,&local_28,'\0',(uint *)(piVar22 + 2),
                                               (uint)DAT_0058426a);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    piVar22 = (int *)*piVar22;
                  } while (piVar22 != (int *)*piVar1);
                }
              }
            }
          }
        }
      }
      uVar16 = uVar16 + 1;
      uVar5 = uVar2;
    } while ((int)uVar16 <= heuristic);
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: NavGraph::findPath  (confidence: low)
 * purpose: Main A*/pathfinding: pops best open node, expands neighbors, evaluates cost, builds path to goal
 * vars: obj+0x1410=node cap; +0x1414 open map; +0x1418 iter count; heavy locals for candidate xyz
 */
/* Global::NavGraph_findPath @ 004dde90 */

/* WARNING: Removing unreachable block (ram,0x004df1bb) */
/* WARNING: Removing unreachable block (ram,0x004deb9a) */
/* WARNING: Removing unreachable block (ram,0x004dec8e) */
/* WARNING: Removing unreachable block (ram,0x004def61) */
/* WARNING: Removing unreachable block (ram,0x004df550) */
/* WARNING: Removing unreachable block (ram,0x004df64b) */
/* WARNING: Removing unreachable block (ram,0x004df0b8) */
/* WARNING: Removing unreachable block (ram,0x004df307) */

void __thiscall NavGraph_findPath(void *this,void *agent)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  bool bVar5;
  uint *puVar6;
  undefined *puVar7;
  float fVar8;
  undefined4 *puVar9;
  undefined4 **ppuVar10;
  int iVar11;
  int *best_iter;
  undefined4 *puVar13;
  char cVar14;
  int iVar15;
  uint uVar16;
  undefined4 *puVar17;
  int iVar18;
  int *piVar19;
  char cVar20;
  void *pvVar21;
  int *piVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  undefined4 *puVar26;
  void *this_00;
  uint uVar27;
  float fVar28;
  uint uVar29;
  bool bVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  uint *puVar35;
  undefined8 local_238;
  uint local_230;
  int local_22c;
  int local_228;
  int local_224;
  undefined8 local_220;
  uint local_218;
  int local_214;
  uint local_210;
  int local_20c;
  undefined8 local_208;
  int local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  uint local_1f0;
  int local_1ec;
  undefined8 local_1e8;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  undefined4 *local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  undefined4 *local_188;
  float local_184;
  int local_180;
  int local_17c;
  int *local_178;
  int *local_174;
  int *local_170;
  int *local_16c;
  int *local_168;
  int *local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  int *local_154;
  uint local_150;
  int *local_14c;
  void *world_ptr;
  int *local_144;
  int *local_140;
  uint local_13c;
  int *local_138;
  int *local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  float local_124;
  int *local_120;
  uint local_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  int *local_10c;
  int *local_108;
  int *local_104;
  uint local_100;
  uint local_fc;
  uint *local_f8;
  int *local_f4;
  int local_f0;
  uint local_ec;
  int *local_e8;
  int *local_e4;
  uint local_e0;
  int local_dc;
  float local_d8;
  uint local_d4;
  char local_cd;
  uint local_cc;
  uint *best_node;
  char local_c1;
  int *local_c0;
  uint local_bc;
  float local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  undefined4 *local_a8;
  char local_a1;
  uint local_a0;
  uint local_9c;
  int *local_98;
  void *agent_ptr;
  char local_8e;
  byte local_8d;
  uint local_8c;
  int local_88;
  uint local_84;
  int local_80;
  uint local_7c;
  int local_78;
  undefined4 *local_74;
  uint local_70;
  uint local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  undefined8 goal_pos;
  float local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  uint local_c;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  agent_ptr = agent;
  world_ptr = this;
  if (*(uint *)((int)agent + 0x1410) != 0) {
    uVar23 = *(uint *)((int)agent + 0x1418);
    if ((uVar23 < 0x1f5) && (*(uint *)((int)agent + 0x1410) < 0x4e21)) {
      local_f8 = (uint *)((int)agent + 0x1440);
      Vec3i64_toBlockCoords((int *)&goal_pos,local_f8);
      if (uVar23 != 0) {
        uVar23 = 0xffffffff;
        best_iter = (int *)**(int **)((int)agent + 0x1414);
        best_node = (uint *)0x0;
        local_104 = best_iter;
        if (best_iter != *(int **)((int)agent + 0x1414)) {
          do {
            piVar25 = local_104;
            puVar26 = (undefined4 *)local_104[4];
            puVar6 = NavGraph_lookupNode(agent_ptr,(undefined4 *)*puVar26,puVar26[1],puVar26[2]);
            if ((puVar6 != (uint *)0x0) &&
               ((best_node == (uint *)0x0 || ((int)puVar6[2] < (int)uVar23)))) {
              uVar23 = puVar6[2];
              best_iter = piVar25;
              best_node = puVar6;
            }
            RBTree_iterIncrement((int *)&local_104);
          } while (local_104 != *(int **)((int)agent_ptr + 0x1414));
        }
        pvVar21 = agent_ptr;
        puVar6 = (uint *)best_iter[4];
        local_a0 = puVar6[1];
        uVar23 = puVar6[2];
        local_a8 = (undefined4 *)*puVar6;
        local_9c = uVar23;
        local_74 = local_a8;
        local_70 = local_a0;
        local_6c = uVar23;
        Creature_mapEraseNode_vec((void *)((int)agent_ptr + 0x1414),&local_138,best_iter);
        iVar15 = 0;
        do {
          if (*(int *)((int)&local_74 + iVar15) != *(int *)((int)&goal_pos + iVar15)) {
            local_34 = ((int)local_a8 >> 0x1f) << 0x10 | (uint)local_a8 >> 0x10;
            local_38 = (int)local_a8 << 0x10;
            local_30 = local_a0 << 0x10;
            local_58 = (double)*(float *)((int)pvVar21 + 0x88) * 0.5 * 65536.0;
            local_24 = (float)(((int)uVar23 >> 0x1f) << 0x10 | uVar23 >> 0x10);
            goal_pos = CONCAT44(uVar23 << 0x10,((int)local_a0 >> 0x1f) << 0x10 | local_a0 >> 0x10);
            puVar6 = &local_38;
            puVar35 = &local_50;
            uVar31 = ftol2();
            local_68 = ftol2();
            local_60 = local_68;
            local_58 = (double)uVar31;
            Vec3i64_add(&local_68,puVar35,puVar6);
            goal_pos = 0;
            local_24 = 0.01;
            Vec3i64_randomize((int)&local_8c);
            local_24 = *(float *)((int)pvVar21 + 0x88) * 0.5;
            goal_pos = CONCAT44(*(float *)((int)pvVar21 + 0x84) * 0.5,
                                *(float *)((int)pvVar21 + 0x80) * 0.5);
            Vec3i64_randomize((int)&local_68);
            local_12c = local_50 - (uint)local_68;
            local_130 = (local_4c - local_68._4_4_) - (uint)(local_50 < (uint)local_68);
            local_38 = local_8c + local_12c;
            local_34 = local_88 + local_130 + (uint)CARRY4(local_8c,local_12c);
            local_30 = local_84 + (local_48 - (uint)local_60);
            local_24 = (float)(local_78 +
                               ((local_3c - local_58._4_4_) - (uint)(local_40 < (uint)local_58)) +
                              (uint)CARRY4(local_7c,local_40 - (uint)local_58));
            goal_pos = CONCAT44(local_7c + (local_40 - (uint)local_58),
                                local_80 +
                                ((local_44 - local_60._4_4_) - (uint)(local_48 < (uint)local_60)) +
                                (uint)CARRY4(local_84,local_48 - (uint)local_60));
            Vec3i64_toBlockCoords((int *)((int)&local_60 + 4),&local_38);
            local_24 = *(float *)((int)agent_ptr + 0x88) * 0.5;
            goal_pos = CONCAT44(*(float *)((int)agent_ptr + 0x84) * 0.5,
                                *(float *)((int)agent_ptr + 0x80) * 0.5);
            Vec3i64_randomize((int)&local_8c);
            local_20 = local_50 + local_8c;
            local_1c = local_4c + local_88 + (uint)CARRY4(local_50,local_8c);
            local_18 = local_48 + local_84;
            local_14 = (undefined4 *)(local_44 + local_80 + (uint)CARRY4(local_48,local_84));
            local_10 = local_40 + local_7c;
            local_c = local_3c + local_78 + (uint)CARRY4(local_40,local_7c);
            Vec3i64_toBlockCoords((int *)&goal_pos,&local_20);
            local_d8 = (float)(local_58._4_4_ + -1);
            local_b8 = (float)((int)local_24 + 1);
            uVar24 = local_60._4_4_ - 1;
            uVar27 = (uint)local_58 - 1;
            uVar23 = (int)(float)goal_pos + 1;
            local_d4 = (int)goal_pos._4_4_ + 1;
            local_13c = (int)(uVar24 + ((int)uVar24 >> 0x1f & 7U)) >> 3;
            local_12c = (int)(uVar27 + ((int)uVar27 >> 0x1f & 7U)) >> 3;
            local_17c = (int)(uVar23 + ((int)uVar23 >> 0x1f & 7U)) >> 3;
            local_180 = (int)(local_d4 + ((int)local_d4 >> 0x1f & 7U)) >> 3;
            local_150 = local_150 & 0xffffff00;
            local_158 = local_158 & 0xffffff00;
            local_160 = local_160 & 0xffffff00;
            local_15c = local_15c & 0xffffff00;
            local_8e = '\0';
            local_e8 = (int *)((uint)local_e8 & 0xffffff00);
            local_f4 = (int *)((uint)local_f4 & 0xffffff00);
            local_108 = (int *)((uint)local_108 & 0xffffff00);
            local_e4 = (int *)((uint)local_e4 & 0xffffff00);
            local_98 = (int *)((uint)local_98 & 0xffffff00);
            local_168 = (int *)((uint)local_168 & 0xffffff00);
            local_178 = (int *)((uint)local_178 & 0xffffff00);
            local_154 = (int *)((uint)local_154 & 0xffffff00);
            local_164 = (int *)((uint)local_164 & 0xffffff00);
            local_140 = (int *)((uint)local_140 & 0xffffff00);
            local_144 = (int *)((uint)local_144 & 0xffffff00);
            local_14c = (int *)((uint)local_14c & 0xffffff00);
            local_170 = (int *)((uint)local_170 & 0xffffff00);
            local_10c = (int *)((uint)local_10c & 0xffffff00);
            local_16c = (int *)((uint)local_16c & 0xffffff00);
            local_174 = (int *)((uint)local_174 & 0xffffff00);
            local_104 = (int *)((uint)local_104 & 0xffffff00);
            local_118 = (int *)((uint)local_118 & 0xffffff00);
            local_120 = (int *)((uint)local_120 & 0xffffff00);
            local_110 = (int *)((uint)local_110 & 0xffffff00);
            local_114 = (int *)((uint)local_114 & 0xffffff00);
            local_134 = (int *)((uint)local_134 & 0xffffff00);
            local_bc = uVar24;
            local_b0 = uVar27;
            local_ac = uVar23;
            uVar31 = ftol2();
            iVar15 = World_getBlockFloat(world_ptr,local_50,local_4c,local_48,local_44,
                                  local_40 - (uint)uVar31,
                                  (local_3c - (int)(uVar31 >> 0x20)) -
                                  (uint)(local_40 < (uint)uVar31),0);
            local_8d = *(byte *)(iVar15 + 3) >> 1 & 1;
            local_c0 = (int *)0x1;
            uVar16 = local_d4;
            if ((int)uVar24 <= (int)uVar23) {
              do {
                fVar8 = local_d8;
                uVar29 = uVar27;
                if ((int)uVar27 <= (int)uVar16) {
                  do {
                    fVar28 = fVar8;
                    if ((int)fVar8 <= (int)local_b8) {
                      do {
                        if ((((((int)uVar24 <= (int)local_bc) || ((int)local_ac <= (int)uVar24)) ||
                             ((int)uVar29 <= (int)uVar27)) ||
                            (((int)uVar16 <= (int)uVar29 || ((int)fVar28 <= (int)fVar8)))) ||
                           ((int)local_b8 <= (int)fVar28)) {
                          if ((((int)uVar24 < 0) || ((int)uVar29 < 0)) ||
                             ((0xffffff < (int)uVar24 ||
                              ((0xffffff < (int)uVar29 ||
                               (iVar15 = Region_getChunkCell(world_ptr,
                                                      (int)(uVar24 + ((int)uVar24 >> 0x1f & 0xffU))
                                                      >> 8,(int)(uVar29 + ((int)uVar29 >> 0x1f &
                                                                          0xffU)) >> 8), iVar15 == 0
                               )))))) {
LAB_004de4aa:
                            puVar7 = &DAT_00584274;
                          }
                          else {
                            uVar23 = uVar29 & 0x800000ff;
                            if ((int)uVar23 < 0) {
                              uVar23 = (uVar23 - 1 | 0xffffff00) + 1;
                            }
                            uVar16 = uVar24 & 0x800000ff;
                            if ((int)uVar16 < 0) {
                              uVar16 = (uVar16 - 1 | 0xffffff00) + 1;
                            }
                            pvVar21 = (void *)((uVar23 * 0x100 + uVar16) * 0x20 +
                                              *(int *)(iVar15 + 0xa8));
                            if ((pvVar21 == (void *)0x0) ||
                               (iVar15 = *(int *)((int)pvVar21 + 0x10), (int)fVar28 < iVar15))
                            goto LAB_004de4aa;
                            if ((int)fVar28 < *(int *)((int)pvVar21 + 0x1c) + iVar15) {
                              puVar7 = Column_getBlockChecked(pvVar21,(int)fVar28 - iVar15);
                              if ((((puVar7[3] & 0x1f) == 0) && ((int)fVar28 < 1)) &&
                                 ((puVar7[3] & 0x40) == 0)) {
                                puVar7 = &DAT_0058426c;
                              }
                            }
                            else {
                              puVar7 = &DAT_0058426c;
                              if (0 < (int)fVar28) {
                                puVar7 = &DAT_00584270;
                              }
                            }
                          }
                          fVar8 = local_d8;
                          uVar16 = local_d4;
                          uVar27 = local_b0;
                          if (((puVar7[3] & 0x1f) != 0) && ((puVar7[3] & 0x1f) != 2)) {
                            if ((uVar24 == local_bc) &&
                               ((uVar29 == local_b0 &&
                                (local_10c = (int *)((uint)local_10c & 0xff), fVar28 == local_d8))))
                            {
                              local_10c = local_c0;
                            }
                            if (((uVar24 == local_ac) && (uVar29 == local_b0)) &&
                               (local_16c = (int *)((uint)local_16c & 0xff), fVar28 == local_d8)) {
                              local_16c = local_c0;
                            }
                            if (((uVar24 == local_bc) && (uVar29 == local_d4)) &&
                               (local_174 = (int *)((uint)local_174 & 0xff), fVar28 == local_d8)) {
                              local_174 = local_c0;
                            }
                            if (((uVar24 == local_ac) && (uVar29 == local_d4)) &&
                               (local_104 = (int *)((uint)local_104 & 0xff), fVar28 == local_d8)) {
                              local_104 = local_c0;
                            }
                            if ((((uVar24 == local_bc) && (uVar29 == local_b0)) &&
                                ((int)local_d8 < (int)fVar28)) &&
                               (local_118 = (int *)((uint)local_118 & 0xff),
                               (int)fVar28 < (int)local_b8)) {
                              local_118 = local_c0;
                            }
                            if (((uVar24 == local_ac) && (uVar29 == local_b0)) &&
                               (((int)local_d8 < (int)fVar28 &&
                                (local_120 = (int *)((uint)local_120 & 0xff),
                                (int)fVar28 < (int)local_b8)))) {
                              local_120 = local_c0;
                            }
                            if (((uVar24 == local_bc) && (uVar29 == local_d4)) &&
                               (((int)local_d8 < (int)fVar28 &&
                                (local_110 = (int *)((uint)local_110 & 0xff),
                                (int)fVar28 < (int)local_b8)))) {
                              local_110 = local_c0;
                            }
                            if ((((uVar24 == local_ac) && (uVar29 == local_d4)) &&
                                ((int)local_d8 < (int)fVar28)) &&
                               (local_114 = (int *)((uint)local_114 & 0xff),
                               (int)fVar28 < (int)local_b8)) {
                              local_114 = local_c0;
                            }
                            if ((((int)local_bc < (int)uVar24) && ((int)uVar24 < (int)local_ac)) &&
                               ((int)local_b0 < (int)uVar29)) {
                              if (((int)uVar29 < (int)local_d4) &&
                                 (local_98 = (int *)((uint)local_98 & 0xff), fVar28 == local_d8)) {
                                local_98 = local_c0;
                              }
                              if ((((int)local_b0 < (int)uVar29) && ((int)uVar29 < (int)local_d4))
                                 && (local_134 = (int *)((uint)local_134 & 0xff), fVar28 == local_b8
                                    )) {
                                local_134 = local_c0;
                              }
                            }
                            if (((uVar24 == local_bc) && ((int)local_b0 < (int)uVar29)) &&
                               (((int)uVar29 < (int)local_d4 &&
                                (local_168 = (int *)((uint)local_168 & 0xff), fVar28 == local_d8))))
                            {
                              local_168 = local_c0;
                            }
                            if (((uVar24 == local_ac) && ((int)local_b0 < (int)uVar29)) &&
                               (((int)uVar29 < (int)local_d4 &&
                                (local_178 = (int *)((uint)local_178 & 0xff), fVar28 == local_d8))))
                            {
                              local_178 = local_c0;
                            }
                            if ((((uVar29 == local_b0) && ((int)local_bc < (int)uVar24)) &&
                                ((int)uVar24 < (int)local_ac)) &&
                               (local_154 = (int *)((uint)local_154 & 0xff), fVar28 == local_d8)) {
                              local_154 = local_c0;
                            }
                            if (((uVar29 == local_d4) && ((int)local_bc < (int)uVar24)) &&
                               (((int)uVar24 < (int)local_ac &&
                                (local_164 = (int *)((uint)local_164 & 0xff), fVar28 == local_d8))))
                            {
                              local_164 = local_c0;
                            }
                            if (((uVar24 == local_bc) && ((int)local_b0 < (int)uVar29)) &&
                               (((int)uVar29 < (int)local_d4 &&
                                (local_140 = (int *)((uint)local_140 & 0xff), fVar28 == local_b8))))
                            {
                              local_140 = local_c0;
                            }
                            if ((((uVar24 == local_ac) && ((int)local_b0 < (int)uVar29)) &&
                                ((int)uVar29 < (int)local_d4)) &&
                               (local_144 = (int *)((uint)local_144 & 0xff), fVar28 == local_b8)) {
                              local_144 = local_c0;
                            }
                            if (((uVar29 == local_b0) && ((int)local_bc < (int)uVar24)) &&
                               (((int)uVar24 < (int)local_ac &&
                                (local_14c = (int *)((uint)local_14c & 0xff), fVar28 == local_b8))))
                            {
                              local_14c = local_c0;
                            }
                            if (((uVar29 == local_d4) && ((int)local_bc < (int)uVar24)) &&
                               (((int)uVar24 < (int)local_ac &&
                                (local_170 = (int *)((uint)local_170 & 0xff), fVar28 == local_d8))))
                            {
                              local_170 = local_c0;
                            }
                            if ((((uVar24 == local_bc) && ((int)local_b0 < (int)uVar29)) &&
                                ((int)uVar29 < (int)local_d4)) &&
                               (((int)local_d8 < (int)fVar28 &&
                                (local_e8 = (int *)((uint)local_e8 & 0xff),
                                (int)fVar28 < (int)local_b8)))) {
                              local_e8 = local_c0;
                            }
                            if (((uVar24 == local_ac) && ((int)local_b0 < (int)uVar29)) &&
                               (((int)uVar29 < (int)local_d4 &&
                                (((int)local_d8 < (int)fVar28 &&
                                 (local_f4 = (int *)((uint)local_f4 & 0xff),
                                 (int)fVar28 < (int)local_b8)))))) {
                              local_f4 = local_c0;
                            }
                            if ((((uVar29 == local_b0) && ((int)local_bc < (int)uVar24)) &&
                                ((int)uVar24 < (int)local_ac)) &&
                               (((int)local_d8 < (int)fVar28 &&
                                (local_108 = (int *)((uint)local_108 & 0xff),
                                (int)fVar28 < (int)local_b8)))) {
                              local_108 = local_c0;
                            }
                            if (((uVar29 == local_d4) && ((int)local_bc < (int)uVar24)) &&
                               (((int)uVar24 < (int)local_ac &&
                                (((int)local_d8 < (int)fVar28 &&
                                 (local_e4 = (int *)((uint)local_e4 & 0xff),
                                 (int)fVar28 < (int)local_b8)))))) {
                              local_e4 = local_c0;
                            }
                          }
                        }
                        fVar28 = (float)((int)fVar28 + 1);
                      } while ((int)fVar28 <= (int)local_b8);
                    }
                    uVar29 = uVar29 + 1;
                    uVar23 = local_ac;
                  } while ((int)uVar29 <= (int)uVar16);
                }
                uVar24 = uVar24 + 1;
              } while ((int)uVar24 <= (int)uVar23);
            }
            uVar33 = CONCAT44(local_cc,local_b4);
            uVar32 = CONCAT44(local_f0,local_c0);
            lVar2 = CONCAT44(local_fc,local_bc);
            uVar31 = CONCAT44(local_dc,local_ec);
            uVar23 = local_12c;
            iVar15 = local_17c;
            iVar18 = local_180;
            if ((int)local_13c <= local_17c) {
              do {
                uVar16 = uVar23;
                uVar27 = local_13c;
                local_130 = uVar23;
                if ((int)uVar23 <= iVar18) {
                  do {
                    local_cc = (uint)(uVar33 >> 0x20);
                    local_b4 = (uint)uVar33;
                    local_f0 = (int)(uVar32 >> 0x20);
                    local_c0 = (int *)uVar32;
                    local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                    local_bc = (uint)lVar2;
                    local_dc = (int)(uVar31 >> 0x20);
                    local_ec = (uint)uVar31;
                    if ((((-1 < (int)uVar27) && (-1 < (int)uVar23)) && ((int)uVar27 < 0x200000)) &&
                       ((int)uVar23 < 0x200000)) {
                      local_130 = uVar23;
                      iVar15 = Region_getChunkCell(world_ptr,
                                            (int)(uVar27 + ((int)uVar27 >> 0x1f & 0x1fU)) >> 5,
                                            (int)(uVar23 + ((int)uVar23 >> 0x1f & 0x1fU)) >> 5);
                      uVar33 = CONCAT44(local_cc,local_b4);
                      uVar32 = CONCAT44(local_f0,local_c0);
                      lVar2 = CONCAT44(local_fc,local_bc);
                      uVar31 = CONCAT44(local_dc,local_ec);
                      if (iVar15 != 0) {
                        uVar16 = uVar23 & 0x8000001f;
                        if ((int)uVar16 < 0) {
                          uVar16 = (uVar16 - 1 | 0xffffffe0) + 1;
                        }
                        uVar24 = uVar27 & 0x8000001f;
                        if ((int)uVar24 < 0) {
                          uVar24 = (uVar24 - 1 | 0xffffffe0) + 1;
                        }
                        puVar26 = (undefined4 *)
                                  (*(int *)(iVar15 + 0xac) + (uVar16 * 0x20 + uVar24) * 8);
                        if (puVar26 != (undefined4 *)0x0) {
                          local_138 = (int *)*puVar26;
                          best_iter = (int *)*local_138;
                          uVar27 = local_13c;
                          if (best_iter != local_138) {
                            puVar26 = *(undefined4 **)((int)agent_ptr + 0x1468);
                            do {
                              local_cc = (uint)(uVar33 >> 0x20);
                              local_b4 = (uint)uVar33;
                              local_f0 = (int)(uVar32 >> 0x20);
                              local_c0 = (int *)uVar32;
                              local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                              local_bc = (uint)lVar2;
                              local_dc = (int)(uVar31 >> 0x20);
                              local_ec = (uint)uVar31;
                              if (*(char *)((int)puVar26[1] + 0xd) == '\0') {
                                puVar13 = (undefined4 *)puVar26[1];
                                puVar17 = puVar26;
                                do {
                                  if ((uint)puVar13[4] < (uint)best_iter[2]) {
                                    puVar9 = (undefined4 *)puVar13[2];
                                  }
                                  else {
                                    puVar9 = (undefined4 *)*puVar13;
                                    puVar17 = puVar13;
                                  }
                                  puVar13 = puVar9;
                                } while (*(char *)((int)puVar9 + 0xd) == '\0');
                                if ((puVar17 == puVar26) || ((uint)best_iter[2] < (uint)puVar17[4]))
                                goto LAB_004dea80;
                                local_188 = puVar17;
                                ppuVar10 = &local_188;
                              }
                              else {
LAB_004dea80:
                                local_1c0 = puVar26;
                                ppuVar10 = &local_1c0;
                              }
                              if (*ppuVar10 == puVar26) {
                                piVar25 = (int *)best_iter[2];
                                local_24 = (float)piVar25[0xb];
                                uVar1 = *(undefined8 *)(piVar25 + 9);
                                uVar23 = piVar25[8] & 0x80000001;
                                bVar30 = uVar23 == 0;
                                if ((int)uVar23 < 0) {
                                  bVar30 = (uVar23 - 1 | 0xfffffffe) == 0xffffffff;
                                }
                                goal_pos._0_4_ = (float)uVar1;
                                goal_pos._4_4_ = (float)((ulonglong)uVar1 >> 0x20);
                                if (bVar30) {
                                  local_d8 = goal_pos._4_4_;
                                  goal_pos._4_4_ = (float)goal_pos;
                                }
                                else {
                                  local_d8 = (float)goal_pos;
                                }
                                local_11c = piVar25[3];
                                local_1c8 = goal_pos._4_4_ * 0.5 * 65536.0;
                                goal_pos = uVar1;
                                uVar31 = ftol2();
                                local_d4 = (uint)(uVar31 >> 0x20);
                                local_128 = (uint)uVar31;
                                local_b8 = (float)(piVar25[2] - local_128);
                                local_b0 = (piVar25[3] - local_d4) -
                                           (uint)((uint)piVar25[2] < local_128);
                                local_1b0 = *(float *)((int)agent_ptr + 0x80) * 0.5 * 65536.0;
                                uVar32 = ftol2();
                                local_f0 = (int)(uVar32 >> 0x20);
                                local_c0 = (int *)uVar32;
                                lVar2 = uVar32 + CONCAT44(local_4c,local_50);
                                local_bc = (uint)lVar2;
                                local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                                local_124 = local_24;
                                uVar23 = local_ec;
                                uVar33 = CONCAT44(local_cc,local_b4);
                                if (CONCAT44(local_b0,local_b8) <= lVar2) {
                                  local_cc = local_50 - (int)local_c0;
                                  iVar18 = (local_4c - local_f0) - (uint)(local_50 < local_c0);
                                  iVar15 = local_d4 + piVar25[3] +
                                           (uint)CARRY4(local_128,piVar25[2]);
                                  uVar33 = CONCAT44(local_cc,local_b4);
                                  if ((iVar18 <= iVar15) &&
                                     ((iVar18 < iVar15 ||
                                      (uVar33 = CONCAT44(local_cc,local_b4),
                                      local_cc < local_128 + piVar25[2])))) {
                                    local_1ac = local_d8 * 0.5 * 65536.0;
                                    uVar31 = ftol2();
                                    local_dc = (int)(uVar31 >> 0x20);
                                    local_ec = (uint)uVar31;
                                    local_18c = *(float *)((int)agent_ptr + 0x84) * 0.5 * 65536.0;
                                    uVar33 = ftol2();
                                    local_cc = (uint)(uVar33 >> 0x20);
                                    local_e0 = piVar25[4] - local_ec;
                                    lVar3 = uVar33 + CONCAT44(local_44,local_48);
                                    uVar23 = (uint)lVar3;
                                    lVar2 = CONCAT44(local_fc,local_bc);
                                    uVar32 = CONCAT44(local_f0,local_c0);
                                    if (CONCAT44((piVar25[5] - local_dc) -
                                                 (uint)((uint)piVar25[4] < local_ec),local_e0) <=
                                        lVar3) {
                                      iVar18 = local_dc + piVar25[5] +
                                               (uint)CARRY4(local_ec,piVar25[4]);
                                      local_b4 = local_48 - (uint)uVar33;
                                      iVar15 = (local_44 - local_cc) -
                                               (uint)(local_48 < (uint)uVar33);
                                      lVar2 = CONCAT44(local_fc,local_bc);
                                      uVar32 = CONCAT44(local_f0,local_c0);
                                      uVar33 = CONCAT44(local_cc,local_b4);
                                      if ((iVar15 <= iVar18) &&
                                         ((iVar15 < iVar18 ||
                                          (lVar2 = CONCAT44(local_fc,local_bc),
                                          uVar32 = CONCAT44(local_f0,local_c0),
                                          uVar33 = CONCAT44(local_cc,local_b4),
                                          local_b4 < local_ec + piVar25[4])))) {
                                        local_1d0 = *(float *)((int)agent_ptr + 0x88) * 0.5 * 65536.0
                                        ;
                                        local_ec = uVar23;
                                        uVar31 = ftol2();
                                        local_e0 = (uint)(uVar31 >> 0x20);
                                        local_b4 = (uint)uVar31;
                                        lVar2 = uVar31 + CONCAT44(local_3c,local_40);
                                        uVar16 = (uint)lVar2;
                                        iVar15 = (int)((ulonglong)lVar2 >> 0x20) -
                                                 (uint)(uVar16 < 0x10000);
                                        uVar23 = local_ec;
                                        lVar2 = CONCAT44(local_fc,local_bc);
                                        uVar32 = CONCAT44(local_f0,local_c0);
                                        uVar33 = CONCAT44(local_cc,local_b4);
                                        if ((piVar25[7] <= iVar15) &&
                                           ((piVar25[7] < iVar15 ||
                                            (lVar2 = CONCAT44(local_fc,local_bc),
                                            uVar32 = CONCAT44(local_f0,local_c0),
                                            uVar33 = CONCAT44(local_cc,local_b4),
                                            (uint)piVar25[6] <= uVar16 - 0x10000)))) {
                                          local_1d8 = local_124 * 65536.0;
                                          uVar31 = ftol2();
                                          uVar23 = (uint)uVar31 + piVar25[6];
                                          iVar18 = (int)(uVar31 >> 0x20) + piVar25[7] +
                                                   (uint)CARRY4((uint)uVar31,piVar25[6]);
                                          iVar15 = ((local_3c - local_e0) -
                                                   (uint)(local_40 < local_b4)) -
                                                   (uint)(local_40 - local_b4 < 0x10000);
                                          lVar2 = CONCAT44(local_fc,local_bc);
                                          uVar32 = CONCAT44(local_f0,local_c0);
                                          uVar33 = CONCAT44(local_cc,local_b4);
                                          if ((iVar15 <= iVar18) &&
                                             ((iVar15 < iVar18 ||
                                              (lVar2 = CONCAT44(local_fc,local_bc),
                                              uVar32 = CONCAT44(local_f0,local_c0),
                                              uVar33 = CONCAT44(local_cc,local_b4),
                                              (local_40 - local_b4) - 0x10000 < uVar23)))) {
                                            local_8e = '\x01';
                                            lVar2 = CONCAT44(local_fc,local_bc);
                                            uVar32 = CONCAT44(local_f0,local_c0);
                                            uVar33 = CONCAT44(local_cc,local_b4);
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                local_ec = uVar23;
                                local_b4 = (uint)uVar33;
                                local_f0 = (int)(uVar32 >> 0x20);
                                local_c0 = (int *)uVar32;
                                uVar31 = CONCAT44(local_dc,local_ec);
                                local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                                local_bc = (uint)lVar2;
                                if (((((3.0 < (float)piVar25[0xb] || (float)piVar25[0xb] == 3.0) ||
                                      ((char)local_134 != '\0')) || ((char)local_140 != '\0')) ||
                                    ((((char)local_144 != '\0' || ((char)local_14c != '\0')) ||
                                     ((char)local_170 != '\0')))) &&
                                   (((iVar15 = *piVar25, iVar15 != 1 && (iVar15 != 2)) &&
                                    ((iVar15 != 8 && ((iVar15 != 7 && (iVar15 != 6)))))))) {
                                  local_cc = 0;
                                  piVar19 = (int *)((int)agent_ptr + 0x1478);
                                  piVar22 = best_iter + 3;
                                  do {
                                    if (*piVar22 != *piVar19) {
                                      iVar15 = local_fc - (local_bc < 0x10000);
                                      uVar23 = local_b4;
                                      uVar33 = uVar31;
                                      if (((int)local_b0 <= iVar15) &&
                                         (((int)local_b0 < iVar15 ||
                                          ((uint)local_b8 <= local_bc - 0x10000)))) {
                                        iVar18 = ((local_4c - local_f0) -
                                                 (uint)(local_50 < local_c0)) -
                                                 (uint)(local_50 - (int)local_c0 < 0x10000);
                                        local_b4 = local_128 + piVar25[2];
                                        iVar15 = local_d4 + piVar25[3] +
                                                 (uint)CARRY4(local_128,piVar25[2]);
                                        uVar23 = local_b4;
                                        uVar33 = CONCAT44(local_dc,local_ec);
                                        if ((iVar18 <= iVar15) &&
                                           ((iVar18 < iVar15 ||
                                            (uVar33 = uVar31,
                                            (local_50 - (int)local_c0) - 0x10000 < local_b4)))) {
                                          local_1e0 = local_d8 * 0.5 * 65536.0;
                                          uVar31 = ftol2();
                                          local_cc = (uint)(uVar31 >> 0x20);
                                          local_b4 = (uint)uVar31;
                                          local_1cc = *(float *)((int)agent_ptr + 0x84) * 0.5 *
                                                      65536.0;
                                          uVar33 = ftol2();
                                          local_dc = (int)(uVar33 >> 0x20);
                                          local_ec = (uint)uVar33;
                                          local_e0 = piVar25[4] - local_b4;
                                          lVar3 = uVar33 + CONCAT44(local_44,local_48);
                                          uVar23 = (uint)lVar3;
                                          lVar2 = CONCAT44(local_fc,local_bc);
                                          uVar32 = CONCAT44(local_f0,local_c0);
                                          if (CONCAT44((piVar25[5] - local_cc) -
                                                       (uint)((uint)piVar25[4] < local_b4),local_e0)
                                              <= lVar3) {
                                            uVar16 = local_b4 + piVar25[4];
                                            iVar18 = local_cc + piVar25[5] +
                                                     (uint)CARRY4(local_b4,piVar25[4]);
                                            local_b4 = local_48 - local_ec;
                                            iVar15 = (local_44 - local_dc) -
                                                     (uint)(local_48 < local_ec);
                                            uVar23 = local_b4;
                                            lVar2 = CONCAT44(local_fc,local_bc);
                                            uVar32 = CONCAT44(local_f0,local_c0);
                                            if ((iVar15 <= iVar18) &&
                                               ((iVar15 < iVar18 ||
                                                (lVar2 = CONCAT44(local_fc,local_bc),
                                                uVar32 = CONCAT44(local_f0,local_c0),
                                                local_b4 < uVar16)))) {
                                              local_184 = *(float *)((int)agent_ptr + 0x88) * 0.5 *
                                                          65536.0;
                                              uVar31 = ftol2();
                                              local_e0 = (uint)(uVar31 >> 0x20);
                                              local_b4 = (uint)uVar31;
                                              local_1e8 = uVar31 + CONCAT44(local_3c,local_40);
                                              uVar16 = std_pair_lessequal(&local_1e8,(uint *)(piVar25 + 6)
                                                                   );
                                              uVar32 = CONCAT44(local_f0,local_c0);
                                              lVar2 = CONCAT44(local_fc,local_bc);
                                              uVar33 = CONCAT44(local_dc,local_ec);
                                              uVar23 = local_b4;
                                              if ((char)uVar16 != '\0') {
                                                local_1b8 = local_124 * 65536.0;
                                                uVar31 = ftol2();
                                                local_1f0 = (uint)uVar31 + piVar25[6];
                                                local_1ec = (int)(uVar31 >> 0x20) + piVar25[7] +
                                                            (uint)CARRY4((uint)uVar31,piVar25[6]);
                                                local_1f8 = local_40 - local_b4;
                                                local_1f4 = (local_3c - local_e0) -
                                                            (uint)(local_40 < local_b4);
                                                uVar16 = std_pair_less(&local_1f8,&local_1f0);
                                                uVar32 = CONCAT44(local_f0,local_c0);
                                                lVar2 = CONCAT44(local_fc,local_bc);
                                                uVar33 = CONCAT44(local_dc,local_ec);
                                                local_150 = local_150 & 0xff;
                                                uVar23 = local_b4;
                                                if ((char)uVar16 != '\0') {
                                                  local_150 = 1;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      local_b4 = uVar23;
                                      local_f0 = (int)(uVar32 >> 0x20);
                                      local_c0 = (int *)uVar32;
                                      local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                                      local_bc = (uint)lVar2;
                                      local_dc = (int)(uVar33 >> 0x20);
                                      local_ec = (uint)uVar33;
                                      uVar23 = local_b4;
                                      if (CONCAT44(local_b0,local_b8) <= lVar2 + 0x10000) {
                                        iVar18 = ((local_4c - local_f0) -
                                                 (uint)(local_50 < local_c0)) +
                                                 (uint)(0xfffeffff < local_50 - (int)local_c0);
                                        local_b4 = local_128 + piVar25[2];
                                        iVar15 = local_d4 + piVar25[3] +
                                                 (uint)CARRY4(local_128,piVar25[2]);
                                        uVar23 = local_b4;
                                        if ((iVar18 <= iVar15) &&
                                           ((iVar18 < iVar15 ||
                                            ((local_50 - (int)local_c0) + 0x10000 < local_b4)))) {
                                          local_194 = local_d8 * 0.5 * 65536.0;
                                          uVar31 = ftol2();
                                          local_cc = (uint)(uVar31 >> 0x20);
                                          local_b4 = (uint)uVar31;
                                          local_1bc = *(float *)((int)agent_ptr + 0x84) * 0.5 *
                                                      65536.0;
                                          uVar33 = ftol2();
                                          local_dc = (int)(uVar33 >> 0x20);
                                          local_ec = (uint)uVar33;
                                          local_e0 = piVar25[4] - local_b4;
                                          lVar3 = uVar33 + CONCAT44(local_44,local_48);
                                          uVar23 = (uint)lVar3;
                                          lVar2 = CONCAT44(local_fc,local_bc);
                                          uVar32 = CONCAT44(local_f0,local_c0);
                                          if (CONCAT44((piVar25[5] - local_cc) -
                                                       (uint)((uint)piVar25[4] < local_b4),local_e0)
                                              <= lVar3) {
                                            uVar16 = local_b4 + piVar25[4];
                                            iVar18 = local_cc + piVar25[5] +
                                                     (uint)CARRY4(local_b4,piVar25[4]);
                                            local_b4 = local_48 - local_ec;
                                            iVar15 = (local_44 - local_dc) -
                                                     (uint)(local_48 < local_ec);
                                            uVar23 = local_b4;
                                            lVar2 = CONCAT44(local_fc,local_bc);
                                            uVar32 = CONCAT44(local_f0,local_c0);
                                            if ((iVar15 <= iVar18) &&
                                               ((iVar15 < iVar18 ||
                                                (lVar2 = CONCAT44(local_fc,local_bc),
                                                uVar32 = CONCAT44(local_f0,local_c0),
                                                local_b4 < uVar16)))) {
                                              local_19c = *(float *)((int)agent_ptr + 0x88) * 0.5 *
                                                          65536.0;
                                              uVar31 = ftol2();
                                              local_e0 = (uint)(uVar31 >> 0x20);
                                              local_b4 = (uint)uVar31;
                                              local_208 = uVar31 + CONCAT44(local_3c,local_40);
                                              uVar16 = std_pair_lessequal(&local_208,(uint *)(piVar25 + 6)
                                                                   );
                                              uVar32 = CONCAT44(local_f0,local_c0);
                                              lVar2 = CONCAT44(local_fc,local_bc);
                                              uVar33 = CONCAT44(local_dc,local_ec);
                                              uVar23 = local_b4;
                                              if ((char)uVar16 != '\0') {
                                                local_1dc = local_124 * 65536.0;
                                                uVar31 = ftol2();
                                                local_218 = (uint)uVar31 + piVar25[6];
                                                local_214 = (int)(uVar31 >> 0x20) + piVar25[7] +
                                                            (uint)CARRY4((uint)uVar31,piVar25[6]);
                                                local_228 = local_40 - local_b4;
                                                local_224 = (local_3c - local_e0) -
                                                            (uint)(local_40 < local_b4);
                                                uVar16 = std_pair_less(&local_228,&local_218);
                                                uVar32 = CONCAT44(local_f0,local_c0);
                                                lVar2 = CONCAT44(local_fc,local_bc);
                                                uVar33 = CONCAT44(local_dc,local_ec);
                                                local_158 = local_158 & 0xff;
                                                uVar23 = local_b4;
                                                if ((char)uVar16 != '\0') {
                                                  local_158 = 1;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      local_b4 = uVar23;
                                      local_f0 = (int)(uVar32 >> 0x20);
                                      local_c0 = (int *)uVar32;
                                      local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                                      local_bc = (uint)lVar2;
                                      local_dc = (int)(uVar33 >> 0x20);
                                      local_ec = (uint)uVar33;
                                      if (CONCAT44(local_b0,local_b8) <= lVar2) {
                                        local_b4 = local_50 - (int)local_c0;
                                        iVar18 = (local_4c - local_f0) - (uint)(local_50 < local_c0)
                                        ;
                                        iVar15 = local_d4 + piVar25[3] +
                                                 (uint)CARRY4(local_128,piVar25[2]);
                                        if ((iVar18 <= iVar15) &&
                                           ((iVar18 < iVar15 || (local_b4 < local_128 + piVar25[2]))
                                           )) {
                                          local_1a4 = local_d8 * 0.5 * 65536.0;
                                          uVar31 = ftol2();
                                          local_dc = (int)(uVar31 >> 0x20);
                                          local_cc = (uint)uVar31;
                                          local_1c4 = *(float *)((int)agent_ptr + 0x84) * 0.5 *
                                                      65536.0;
                                          uVar31 = ftol2();
                                          local_ec = (uint)(uVar31 >> 0x20);
                                          local_e0 = (uint)uVar31;
                                          lVar2 = uVar31 + CONCAT44(local_44,local_48);
                                          uVar23 = (uint)lVar2;
                                          iVar18 = (int)((ulonglong)lVar2 >> 0x20) -
                                                   (uint)(uVar23 < 0x10000);
                                          local_b4 = piVar25[4] - local_cc;
                                          iVar15 = (piVar25[5] - local_dc) -
                                                   (uint)((uint)piVar25[4] < local_cc);
                                          uVar33 = CONCAT44(local_dc,local_ec);
                                          lVar2 = CONCAT44(local_fc,local_bc);
                                          uVar32 = CONCAT44(local_f0,local_c0);
                                          if ((iVar15 <= iVar18) &&
                                             ((iVar15 < iVar18 ||
                                              (uVar33 = CONCAT44(local_dc,local_ec),
                                              lVar2 = CONCAT44(local_fc,local_bc),
                                              uVar32 = CONCAT44(local_f0,local_c0),
                                              local_b4 <= uVar23 - 0x10000)))) {
                                            iVar15 = ((local_44 - local_ec) -
                                                     (uint)(local_48 < local_e0)) -
                                                     (uint)(local_48 - local_e0 < 0x10000);
                                            puVar6 = (uint *)(piVar25 + 4);
                                            local_dc = local_dc + piVar25[5] +
                                                       (uint)CARRY4(local_cc,*puVar6);
                                            piVar25 = (int *)best_iter[2];
                                            uVar33 = CONCAT44(local_dc,local_ec);
                                            lVar2 = CONCAT44(local_fc,local_bc);
                                            uVar32 = CONCAT44(local_f0,local_c0);
                                            if ((iVar15 <= local_dc) &&
                                               ((iVar15 < local_dc ||
                                                (uVar33 = CONCAT44(local_dc,local_ec),
                                                lVar2 = CONCAT44(local_fc,local_bc),
                                                uVar32 = CONCAT44(local_f0,local_c0),
                                                (local_48 - local_e0) - 0x10000 < local_cc + *puVar6
                                                )))) {
                                              local_1d4 = *(float *)((int)agent_ptr + 0x88) * 0.5 *
                                                          65536.0;
                                              uVar31 = ftol2();
                                              local_b4 = (uint)(uVar31 >> 0x20);
                                              local_100 = (uint)uVar31;
                                              local_238 = uVar31 + CONCAT44(local_3c,local_40);
                                              uVar23 = std_pair_lessequal(&local_238,(uint *)(piVar25 + 6)
                                                                   );
                                              uVar32 = CONCAT44(local_f0,local_c0);
                                              lVar2 = CONCAT44(local_fc,local_bc);
                                              uVar33 = CONCAT44(local_dc,local_ec);
                                              if ((char)uVar23 != '\0') {
                                                local_1b4 = local_124 * 65536.0;
                                                uVar31 = ftol2();
                                                local_230 = (uint)uVar31 + piVar25[6];
                                                local_22c = (int)(uVar31 >> 0x20) + piVar25[7] +
                                                            (uint)CARRY4((uint)uVar31,piVar25[6]);
                                                local_200 = local_40 - local_100;
                                                local_1fc = (local_3c - local_b4) -
                                                            (uint)(local_40 < local_100);
                                                uVar23 = std_pair_less(&local_200,&local_230);
                                                uVar32 = CONCAT44(local_f0,local_c0);
                                                lVar2 = CONCAT44(local_fc,local_bc);
                                                uVar33 = CONCAT44(local_dc,local_ec);
                                                local_160 = local_160 & 0xff;
                                                if ((char)uVar23 != '\0') {
                                                  local_160 = 1;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      local_f0 = (int)(uVar32 >> 0x20);
                                      local_c0 = (int *)uVar32;
                                      local_fc = (uint)((ulonglong)lVar2 >> 0x20);
                                      local_bc = (uint)lVar2;
                                      local_dc = (int)(uVar33 >> 0x20);
                                      local_ec = (uint)uVar33;
                                      uVar31 = uVar33;
                                      uVar33 = CONCAT44(local_cc,local_b4);
                                      if (CONCAT44(local_b0,local_b8) <= lVar2) {
                                        iVar18 = (local_4c - local_f0) - (uint)(local_50 < local_c0)
                                        ;
                                        local_d4 = local_d4 + local_11c +
                                                   (uint)CARRY4(local_128,piVar25[2]);
                                        iVar15 = best_iter[2];
                                        uVar33 = CONCAT44(local_cc,local_b4);
                                        if ((iVar18 <= (int)local_d4) &&
                                           ((iVar18 < (int)local_d4 ||
                                            (uVar33 = CONCAT44(local_cc,local_b4),
                                            local_50 - (int)local_c0 < local_128 + piVar25[2])))) {
                                          local_190 = local_d8 * 0.5 * 65536.0;
                                          uVar31 = ftol2();
                                          local_f0 = (int)(uVar31 >> 0x20);
                                          local_fc = (uint)uVar31;
                                          local_198 = *(float *)((int)agent_ptr + 0x84) * 0.5 *
                                                      65536.0;
                                          uVar34 = ftol2();
                                          local_cc = (uint)(uVar34 >> 0x20);
                                          local_100 = (uint)uVar34;
                                          local_11c = *(uint *)(iVar15 + 0x10) - local_fc;
                                          uVar31 = CONCAT44(local_dc,local_ec);
                                          lVar2 = CONCAT44(local_fc,local_bc);
                                          uVar32 = CONCAT44(local_f0,local_c0);
                                          uVar33 = CONCAT44(local_cc,local_b4);
                                          if (CONCAT44((*(int *)(iVar15 + 0x14) - local_f0) -
                                                       (uint)(*(uint *)(iVar15 + 0x10) < local_fc),
                                                       local_11c) <=
                                              (longlong)
                                              (uVar34 + CONCAT44(local_44,local_48) + 0x10000)) {
                                            iVar11 = ((local_44 - local_cc) -
                                                     (uint)(local_48 < local_100)) +
                                                     (uint)(0xfffeffff < local_48 - local_100);
                                            local_f0 = local_f0 + *(int *)(iVar15 + 0x14) +
                                                       (uint)CARRY4(local_fc,*(uint *)(iVar15 + 0x10
                                                                                      ));
                                            iVar18 = best_iter[2];
                                            uVar31 = CONCAT44(local_dc,local_ec);
                                            lVar2 = CONCAT44(local_fc,local_bc);
                                            uVar32 = CONCAT44(local_f0,local_c0);
                                            uVar33 = CONCAT44(local_cc,local_b4);
                                            if ((iVar11 <= local_f0) &&
                                               ((iVar11 < local_f0 ||
                                                (uVar31 = CONCAT44(local_dc,local_ec),
                                                lVar2 = CONCAT44(local_fc,local_bc),
                                                uVar32 = CONCAT44(local_f0,local_c0),
                                                uVar33 = CONCAT44(local_cc,local_b4),
                                                (local_48 - local_100) + 0x10000 <
                                                local_fc + *(uint *)(iVar15 + 0x10))))) {
                                              local_1a0 = *(float *)((int)agent_ptr + 0x88) * 0.5 *
                                                          65536.0;
                                              uVar31 = ftol2();
                                              local_100 = (uint)(uVar31 >> 0x20);
                                              local_11c = (uint)uVar31;
                                              local_220 = uVar31 + CONCAT44(local_3c,local_40);
                                              puVar6 = (uint *)(iVar18 + 0x18);
                                              uVar23 = std_pair_lessequal(&local_220,puVar6);
                                              uVar33 = CONCAT44(local_cc,local_b4);
                                              uVar32 = CONCAT44(local_f0,local_c0);
                                              uVar31 = CONCAT44(local_dc,local_ec);
                                              lVar2 = CONCAT44(local_fc,local_bc);
                                              if ((char)uVar23 != '\0') {
                                                local_1a8 = local_124 * 65536.0;
                                                uVar31 = ftol2();
                                                local_210 = (uint)uVar31 + *puVar6;
                                                local_20c = (int)(uVar31 >> 0x20) +
                                                            *(int *)(iVar18 + 0x1c) +
                                                            (uint)CARRY4((uint)uVar31,*puVar6);
                                                local_58 = (double)CONCAT44((local_3c - local_100) -
                                                                            (uint)(local_40 <
                                                                                  local_11c),
                                                                            local_40 - local_11c);
                                                uVar23 = std_pair_less(&local_58,&local_210);
                                                uVar33 = CONCAT44(local_cc,local_b4);
                                                uVar32 = CONCAT44(local_f0,local_c0);
                                                uVar31 = CONCAT44(local_dc,local_ec);
                                                lVar2 = CONCAT44(local_fc,local_bc);
                                                local_15c = local_15c & 0xff;
                                                if ((char)uVar23 != '\0') {
                                                  local_15c = 1;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      break;
                                    }
                                    local_cc = local_cc + 1;
                                    uVar33 = CONCAT44(local_cc,local_b4);
                                    piVar22 = piVar22 + 1;
                                    piVar19 = piVar19 + 1;
                                  } while ((int)local_cc < 3);
                                }
                              }
                              best_iter = (int *)*best_iter;
                              uVar23 = local_130;
                              uVar27 = local_13c;
                              iVar18 = local_180;
                            } while (best_iter != local_138);
                          }
                        }
                      }
                    }
                    uVar23 = uVar23 + 1;
                    uVar16 = local_12c;
                    iVar15 = local_17c;
                    local_130 = uVar23;
                  } while ((int)uVar23 <= iVar18);
                }
                local_13c = uVar27 + 1;
                uVar23 = uVar16;
              } while ((int)local_13c <= iVar15);
            }
            pvVar21 = agent_ptr;
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            cVar4 = (char)local_98;
            local_cd = '\0';
            uVar23 = local_9c;
            if (((char)local_e8 == '\0') && ((char)local_150 == '\0')) {
              if ((cVar4 != '\0') ||
                 ((((((char)local_168 != '\0' || ((char)local_108 != '\0')) ||
                    ((char)local_e4 != '\0')) ||
                   (((char)local_118 != '\0' || ((char)local_110 != '\0')))) || (local_8d != 0)))) {
                puVar26 = (undefined4 *)((int)local_a8 - 1);
                best_iter = NavGraph_lookupNode(agent_ptr,puVar26,local_a0,local_9c);
                if (best_iter == (int *)0x0) {
                  best_iter = (int *)Vec3i64_toBlockCoords((int *)&goal_pos,local_f8);
                  pvVar21 = agent_ptr;
                  uVar23 = local_9c;
                  uVar16 = (int)puVar26 - *best_iter >> 0x1f;
                  iVar15 = ((int)puVar26 - *best_iter ^ uVar16) - uVar16;
                  uVar16 = (int)(local_a0 - best_iter[1]) >> 0x1f;
                  iVar18 = (local_a0 - best_iter[1] ^ uVar16) - uVar16;
                  uVar16 = (int)(local_9c - best_iter[2]) >> 0x1f;
                  if (iVar18 < iVar15) {
                    iVar15 = iVar15 * 10 + iVar18 * 4;
                  }
                  else {
                    iVar15 = iVar15 * 4 + iVar18 * 10;
                  }
                  local_1c = (iVar15 + ((local_9c - best_iter[2] ^ uVar16) - uVar16) * 10) * 2;
                  local_20 = *best_node + 10;
                  if ((char)local_98 == '\0') {
                    local_20 = *best_node + 0x14;
                  }
                  local_18 = local_20 + local_1c;
                  local_10 = local_a0;
                  local_14 = local_a8;
                  local_c = local_9c;
                  NavGraph_addNode(agent_ptr,(undefined4 *)((int)local_a8 - 1),local_a0,local_9c,
                               &local_20);
                  local_cd = '\x01';
                }
                else {
                  bVar30 = NavGraph_openSetContains(pvVar21,puVar26,local_a0,local_9c);
                  uVar23 = local_9c;
                  if (bVar30) {
                    uVar16 = *best_node + 10;
                    if ((char)local_98 == '\0') {
                      uVar16 = *best_node + 0x14;
                    }
                    if ((int)uVar16 < *best_iter) {
                      local_18 = uVar16 + best_iter[1];
                      local_14 = local_a8;
                      local_10 = local_a0;
                      local_c = local_9c;
                      local_20 = uVar16;
                      local_1c = best_iter[1];
                      NavGraph_addNode(pvVar21,puVar26,local_a0,local_9c,&local_20);
                      local_cd = '\x01';
                    }
                  }
                }
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                cVar4 = (char)local_98;
                goto LAB_004df9b8;
              }
              cVar20 = '\0';
            }
            else {
LAB_004df9b8:
              cVar20 = (char)local_e4;
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            local_c1 = '\0';
            cVar14 = (char)local_f4;
            uVar16 = local_a0;
            if (((cVar14 == '\0') && ((char)local_158 == '\0')) &&
               ((((cVar4 != '\0' ||
                  (((local_8e != '\0' || ((char)local_178 != '\0')) || ((char)local_108 != '\0'))))
                 || (((cVar20 != '\0' || ((char)local_120 != '\0')) || ((char)local_114 != '\0'))))
                || (local_8d != 0)))) {
              puVar26 = (undefined4 *)((int)local_a8 + 1);
              best_iter = NavGraph_lookupNode(pvVar21,puVar26,local_a0,uVar23);
              if (best_iter == (int *)0x0) {
                best_iter = (int *)Vec3i64_toBlockCoords((int *)&goal_pos,local_f8);
                pvVar21 = agent_ptr;
                uVar16 = local_a0;
                uVar23 = (int)puVar26 - *best_iter >> 0x1f;
                iVar15 = ((int)puVar26 - *best_iter ^ uVar23) - uVar23;
                uVar23 = (int)(local_a0 - best_iter[1]) >> 0x1f;
                iVar18 = (local_a0 - best_iter[1] ^ uVar23) - uVar23;
                uVar23 = (int)(local_9c - best_iter[2]) >> 0x1f;
                if (iVar18 < iVar15) {
                  iVar15 = iVar15 * 10 + iVar18 * 4;
                }
                else {
                  iVar15 = iVar15 * 4 + iVar18 * 10;
                }
                local_1c = (iVar15 + ((local_9c - best_iter[2] ^ uVar23) - uVar23) * 10) * 2;
                local_20 = *best_node + 10;
                if ((char)local_98 == '\0') {
                  local_20 = *best_node + 0x14;
                }
                local_18 = local_20 + local_1c;
                local_10 = local_a0;
                local_c = local_9c;
                local_14 = local_a8;
                NavGraph_addNode(agent_ptr,(undefined4 *)((int)local_a8 + 1),local_a0,local_9c,&local_20)
                ;
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                cVar14 = (char)local_f4;
                local_c1 = '\x01';
              }
              else {
                bVar30 = NavGraph_openSetContains(pvVar21,puVar26,local_a0,local_9c);
                uVar16 = local_a0;
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                cVar14 = (char)local_f4;
                if (bVar30) {
                  uVar23 = *best_node + 10;
                  if ((char)local_98 == '\0') {
                    uVar23 = *best_node + 0x14;
                  }
                  if ((int)uVar23 < *best_iter) {
                    local_18 = uVar23 + best_iter[1];
                    local_14 = local_a8;
                    local_10 = local_a0;
                    local_c = local_9c;
                    local_20 = uVar23;
                    local_1c = best_iter[1];
                    NavGraph_addNode(pvVar21,puVar26,local_a0,local_9c,&local_20);
                    uVar33 = CONCAT44(local_cc,local_b4);
                    uVar32 = CONCAT44(local_f0,local_c0);
                    lVar2 = CONCAT44(local_fc,local_bc);
                    uVar31 = CONCAT44(local_dc,local_ec);
                    cVar14 = (char)local_f4;
                    local_c1 = '\x01';
                  }
                }
              }
            }
            cVar20 = local_c1;
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            cVar4 = (char)local_98;
            bVar30 = false;
            if (((char)local_108 == '\0') && ((char)local_160 == '\0')) {
              if (((cVar4 != '\0') ||
                  (((local_8e != '\0' || ((char)local_154 != '\0')) || ((char)local_e8 != '\0'))))
                 || (((cVar14 != '\0' || ((char)local_118 != '\0')) ||
                     (((char)local_120 != '\0' || (cVar14 = '\0', local_8d != 0)))))) {
                iVar15 = uVar16 - 1;
                best_iter = NavGraph_lookupNode(pvVar21,local_a8,iVar15,local_9c);
                if (best_iter == (int *)0x0) {
                  best_iter = (int *)Vec3i64_toBlockCoords((int *)((int)&local_60 + 4),local_f8);
                  uVar23 = local_9c;
                  goal_pos = CONCAT44(iVar15 - best_iter[1],(int)local_a8 - *best_iter);
                  local_24 = (float)(local_9c - best_iter[2]);
                  local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                  pvVar21 = agent_ptr;
                  local_20 = *best_node + 10;
                  if ((char)local_98 == '\0') {
                    local_20 = *best_node + 0x1e;
                  }
                  local_18 = local_1c + local_20;
                  local_c = uVar23;
                  local_14 = local_a8;
                  local_10 = local_a0;
                  NavGraph_addNode(agent_ptr,local_a8,iVar15,uVar23,&local_20);
                  bVar30 = true;
                }
                else {
                  bVar5 = NavGraph_openSetContains(agent_ptr,local_a8,iVar15,local_9c);
                  pvVar21 = agent_ptr;
                  if (bVar5) {
                    uVar23 = *best_node + 10;
                    if ((char)local_98 == '\0') {
                      uVar23 = *best_node + 0x14;
                    }
                    if ((int)uVar23 < *best_iter) {
                      local_18 = uVar23 + best_iter[1];
                      local_10 = local_a0;
                      local_14 = local_a8;
                      local_c = local_9c;
                      local_20 = uVar23;
                      local_1c = best_iter[1];
                      NavGraph_addNode(agent_ptr,local_a8,iVar15,local_9c,&local_20);
                      bVar30 = true;
                    }
                  }
                }
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                cVar4 = (char)local_98;
                goto LAB_004dfd43;
              }
            }
            else {
LAB_004dfd43:
              cVar14 = (char)local_e8;
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            local_a1 = '\0';
            puVar26 = local_a8;
            if ((((char)local_e4 == '\0') && ((char)local_15c == '\0')) &&
               ((((cVar4 != '\0' ||
                  ((((local_8e != '\0' || ((char)local_164 != '\0')) || (cVar14 != '\0')) ||
                   (((char)local_f4 != '\0' || ((char)local_110 != '\0')))))) ||
                 ((char)local_114 != '\0')) || (local_8d != 0)))) {
              iVar15 = local_a0 + 1;
              best_iter = NavGraph_lookupNode(pvVar21,local_a8,iVar15,local_9c);
              if (best_iter == (int *)0x0) {
                best_iter = (int *)Vec3i64_toBlockCoords((int *)((int)&local_60 + 4),local_f8);
                uVar23 = local_9c;
                goal_pos = CONCAT44(iVar15 - best_iter[1],(int)local_a8 - *best_iter);
                local_24 = (float)(local_9c - best_iter[2]);
                local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                local_20 = *best_node + 10;
                if ((char)local_98 == '\0') {
                  local_20 = *best_node + 0x14;
                }
                local_18 = local_1c + local_20;
                local_c = uVar23;
LAB_004dfe4d:
                puVar26 = local_a8;
                local_14 = local_a8;
                local_10 = local_a0;
                NavGraph_addNode(agent_ptr,local_a8,iVar15,local_c,&local_20);
                local_a1 = '\x01';
              }
              else {
                bVar5 = NavGraph_openSetContains(agent_ptr,local_a8,iVar15,local_9c);
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                puVar26 = local_a8;
                if (!bVar5) goto LAB_004dfee2;
                uVar23 = *best_node + 10;
                if ((char)local_98 == '\0') {
                  uVar23 = *best_node + 0x14;
                }
                if ((int)uVar23 < *best_iter) {
                  local_18 = uVar23 + best_iter[1];
                  local_c = local_9c;
                  local_20 = uVar23;
                  local_1c = best_iter[1];
                  goto LAB_004dfe4d;
                }
              }
              uVar33 = CONCAT44(local_cc,local_b4);
              uVar32 = CONCAT44(local_f0,local_c0);
              lVar2 = CONCAT44(local_fc,local_bc);
              uVar31 = CONCAT44(local_dc,local_ec);
            }
LAB_004dfee2:
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            cVar4 = (char)local_98;
            if (((((char)local_118 == '\0') && (local_cd != '\0')) && (bVar30)) &&
               ((((cVar4 != '\0' || (local_8e != '\0')) || ((char)local_10c != '\0')) ||
                (local_8d != 0)))) {
              puVar26 = (undefined4 *)((int)puVar26 - 1);
              iVar15 = local_a0 - 1;
              local_138 = NavGraph_lookupNode(agent_ptr,puVar26,iVar15,local_9c);
              if (local_138 == (int *)0x0) {
                best_iter = (int *)Vec3i64_toBlockCoords((int *)((int)&local_60 + 4),local_f8);
                goal_pos = CONCAT44(iVar15 - best_iter[1],(int)puVar26 - *best_iter);
                local_24 = (float)(local_9c - best_iter[2]);
                local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                local_20 = *best_node + 0xe;
                if ((char)local_98 == '\0') {
                  local_20 = *best_node + 0x18;
                }
                local_18 = local_1c + local_20;
                local_14 = local_a8;
                puVar6 = &local_20;
                local_10 = local_a0;
                local_c = local_9c;
LAB_004e0021:
                NavGraph_addNode(agent_ptr,puVar26,iVar15,local_9c,puVar6);
              }
              else {
                bVar5 = NavGraph_openSetContains(agent_ptr,puVar26,iVar15,local_9c);
                if (bVar5) {
                  iVar18 = *best_node + 0xe;
                  if ((char)local_98 == '\0') {
                    iVar18 = *best_node + 0x18;
                  }
                  if (iVar18 < *local_138) {
                    puVar6 = Object_construct6(&local_20,iVar18,local_138[1],iVar18 + local_138[1],
                                          &local_74);
                    goto LAB_004e0021;
                  }
                }
              }
              uVar33 = CONCAT44(local_cc,local_b4);
              uVar32 = CONCAT44(local_f0,local_c0);
              lVar2 = CONCAT44(local_fc,local_bc);
              uVar31 = CONCAT44(local_dc,local_ec);
              cVar4 = (char)local_98;
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            pvVar21 = agent_ptr;
            if (((((char)local_120 == '\0') && (cVar20 != '\0')) && (bVar30)) &&
               (((cVar4 != '\0' || (local_8e != '\0')) ||
                (((char)local_16c != '\0' || (local_8d != 0)))))) {
              iVar15 = local_a0 - 1;
              puVar26 = (undefined4 *)((int)local_a8 + 1);
              best_iter = NavGraph_lookupNode(agent_ptr,puVar26,iVar15,local_9c);
              if (best_iter == (int *)0x0) {
                best_iter = (int *)Vec3i64_toBlockCoords((int *)((int)&local_60 + 4),local_f8);
                uVar23 = local_9c;
                goal_pos = CONCAT44(iVar15 - best_iter[1],(int)puVar26 - *best_iter);
                local_24 = (float)(local_9c - best_iter[2]);
                local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                pvVar21 = agent_ptr;
                local_20 = *best_node + 0xe;
                if ((char)local_98 == '\0') {
                  local_20 = *best_node + 0x18;
                }
                local_18 = local_1c + local_20;
                local_14 = local_a8;
                local_10 = local_a0;
                local_c = uVar23;
                NavGraph_addNode(agent_ptr,puVar26,iVar15,uVar23,&local_20);
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
              }
              else {
                bVar30 = NavGraph_openSetContains(agent_ptr,puVar26,iVar15,local_9c);
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                pvVar21 = agent_ptr;
                if (bVar30) {
                  iVar18 = *best_node + 0xe;
                  if ((char)local_98 == '\0') {
                    iVar18 = *best_node + 0x18;
                  }
                  if (iVar18 < *best_iter) {
                    puVar13 = Object_construct6(&local_20,iVar18,best_iter[1],iVar18 + best_iter[1],&local_74
                                          );
                    pvVar21 = agent_ptr;
                    NavGraph_addNode(agent_ptr,puVar26,iVar15,local_9c,puVar13);
                    uVar33 = CONCAT44(local_cc,local_b4);
                    uVar32 = CONCAT44(local_f0,local_c0);
                    lVar2 = CONCAT44(local_fc,local_bc);
                    uVar31 = CONCAT44(local_dc,local_ec);
                  }
                }
              }
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            this_00 = agent_ptr;
            if (((((char)local_110 == '\0') && (local_cd != '\0')) && (local_a1 != '\0')) &&
               ((((char)local_98 != '\0' || (local_8e != '\0')) ||
                (((char)local_174 != '\0' || (local_8d != 0)))))) {
              iVar15 = local_a0 + 1;
              puVar26 = (undefined4 *)((int)local_a8 - 1);
              best_iter = NavGraph_lookupNode(pvVar21,puVar26,iVar15,local_9c);
              if (best_iter == (int *)0x0) {
                best_iter = (int *)Vec3i64_toBlockCoords((int *)((int)&local_60 + 4),local_f8);
                uVar23 = local_9c;
                goal_pos = CONCAT44(iVar15 - best_iter[1],(int)puVar26 - *best_iter);
                local_24 = (float)(local_9c - best_iter[2]);
                local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                local_20 = *best_node + 0xe;
                if ((char)local_98 == '\0') {
                  local_20 = *best_node + 0x18;
                }
                local_18 = local_1c + local_20;
                local_14 = local_a8;
                local_10 = local_a0;
                puVar6 = &local_20;
                local_c = uVar23;
LAB_004e0288:
                this_00 = agent_ptr;
                NavGraph_addNode(agent_ptr,puVar26,iVar15,uVar23,puVar6);
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
              }
              else {
                bVar30 = NavGraph_openSetContains(agent_ptr,puVar26,iVar15,local_9c);
                uVar33 = CONCAT44(local_cc,local_b4);
                uVar32 = CONCAT44(local_f0,local_c0);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar31 = CONCAT44(local_dc,local_ec);
                this_00 = agent_ptr;
                if (bVar30) {
                  iVar18 = *best_node + 0xe;
                  if ((char)local_98 == '\0') {
                    iVar18 = *best_node + 0x18;
                  }
                  if (iVar18 < *best_iter) {
                    puVar6 = Object_construct6(&local_20,iVar18,best_iter[1],iVar18 + best_iter[1],&local_74)
                    ;
                    uVar23 = local_9c;
                    goto LAB_004e0288;
                  }
                }
              }
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            pvVar21 = agent_ptr;
            if ((((char)local_114 == '\0') && (local_c1 != '\0')) && (local_a1 != '\0')) {
              if (((((char)local_98 != '\0') || (local_8e != '\0')) || ((char)local_104 != '\0')) ||
                 (local_8d != 0)) {
                iVar15 = local_a0 + 1;
                puVar26 = (undefined4 *)((int)local_a8 + 1);
                best_iter = NavGraph_lookupNode(this_00,puVar26,iVar15,local_9c);
                if (best_iter == (int *)0x0) {
                  best_iter = (int *)Vec3i64_toBlockCoords((int *)&local_74,local_f8);
                  uVar23 = local_9c;
                  goal_pos = CONCAT44(iVar15 - best_iter[1],(int)puVar26 - *best_iter);
                  local_24 = (float)(local_9c - best_iter[2]);
                  local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                  pvVar21 = agent_ptr;
                  local_20 = *best_node + 0xe;
                  if ((char)local_98 == '\0') {
                    local_20 = *best_node + 0x18;
                  }
                  local_18 = local_1c + local_20;
                  local_14 = local_a8;
                  local_10 = local_a0;
                  local_c = uVar23;
                  NavGraph_addNode(agent_ptr,puVar26,iVar15,uVar23,&local_20);
                  uVar31 = CONCAT44(local_dc,local_ec);
                  lVar2 = CONCAT44(local_fc,local_bc);
                  uVar32 = CONCAT44(local_f0,local_c0);
                  uVar33 = CONCAT44(local_cc,local_b4);
                }
                else {
                  bVar30 = NavGraph_openSetContains(agent_ptr,puVar26,iVar15,local_9c);
                  pvVar21 = agent_ptr;
                  uVar31 = CONCAT44(local_dc,local_ec);
                  lVar2 = CONCAT44(local_fc,local_bc);
                  uVar32 = CONCAT44(local_f0,local_c0);
                  uVar33 = CONCAT44(local_cc,local_b4);
                  if (bVar30) {
                    iVar18 = *best_node + 0xe;
                    if ((char)local_98 == '\0') {
                      iVar18 = *best_node + 0x18;
                    }
                    uVar31 = CONCAT44(local_dc,local_ec);
                    lVar2 = CONCAT44(local_fc,local_bc);
                    uVar32 = CONCAT44(local_f0,local_c0);
                    uVar33 = CONCAT44(local_cc,local_b4);
                    if (iVar18 < *best_iter) {
                      puVar13 = Object_construct6(&local_20,iVar18,best_iter[1],iVar18 + best_iter[1],
                                             &local_74);
                      pvVar21 = agent_ptr;
                      NavGraph_addNode(agent_ptr,puVar26,iVar15,local_9c,puVar13);
                      uVar31 = CONCAT44(local_dc,local_ec);
                      lVar2 = CONCAT44(local_fc,local_bc);
                      uVar32 = CONCAT44(local_f0,local_c0);
                      uVar33 = CONCAT44(local_cc,local_b4);
                    }
                  }
                }
                goto LAB_004e046a;
              }
            }
            else {
LAB_004e046a:
              uVar23 = local_9c;
              if (((char)local_98 != '\0') || (local_8e != '\0')) goto LAB_004e0486;
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            iVar15 = local_9c - 1;
            best_iter = NavGraph_lookupNode(pvVar21,local_a8,local_a0,iVar15);
            if (best_iter == (int *)0x0) {
              best_iter = (int *)Vec3i64_toBlockCoords((int *)&local_74,(uint *)((int)pvVar21 + 0x1440));
              goal_pos = CONCAT44(local_a0 - best_iter[1],(int)local_a8 - *best_iter);
              local_24 = (float)(iVar15 - best_iter[2]);
              uVar27 = NavGraph_heuristicCost((uint *)&goal_pos);
              uVar16 = *best_node;
              uVar24 = uVar16;
              uVar29 = uVar27;
            }
            else {
              bVar30 = NavGraph_openSetContains(pvVar21,local_a8,local_a0,iVar15);
              uVar33 = CONCAT44(local_cc,local_b4);
              uVar32 = CONCAT44(local_f0,local_c0);
              lVar2 = CONCAT44(local_fc,local_bc);
              uVar31 = CONCAT44(local_dc,local_ec);
              uVar23 = local_9c;
              if (!bVar30) goto LAB_004e0486;
              uVar16 = best_iter[1];
              uVar27 = *best_node;
              uVar24 = uVar27;
              uVar29 = uVar16;
              if (*best_iter <= (int)uVar27) goto LAB_004e0486;
            }
            local_1c = uVar29;
            local_20 = uVar24;
            uVar23 = local_9c;
            local_18 = uVar27 + uVar16;
            local_10 = local_a0;
            local_14 = local_a8;
            local_c = local_9c;
            NavGraph_addNode(pvVar21,local_a8,local_a0,iVar15,&local_20);
            uVar33 = CONCAT44(local_cc,local_b4);
            uVar32 = CONCAT44(local_f0,local_c0);
            lVar2 = CONCAT44(local_fc,local_bc);
            uVar31 = CONCAT44(local_dc,local_ec);
LAB_004e0486:
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            if (((char)local_134 == '\0') &&
               ((((char)local_e8 != '\0' || ((char)local_f4 != '\0')) ||
                (((char)local_108 != '\0' || (((char)local_e4 != '\0' || (local_8d != 0)))))))) {
              iVar15 = uVar23 + 1;
              best_iter = NavGraph_lookupNode(pvVar21,local_a8,local_a0,iVar15);
              if (best_iter == (int *)0x0) {
                best_iter = (int *)Vec3i64_toBlockCoords((int *)&local_74,(uint *)((int)pvVar21 + 0x1440));
                puVar26 = local_a8;
                goal_pos = CONCAT44(local_a0 - best_iter[1],(int)local_a8 - *best_iter);
                local_24 = (float)(iVar15 - best_iter[2]);
                local_1c = NavGraph_heuristicCost((uint *)&goal_pos);
                local_20 = *best_node;
                if ((char)local_98 == '\0') {
                  local_20 = local_20 + 0x28;
                }
                local_18 = local_1c + local_20;
                local_c = local_9c;
                local_10 = local_a0;
                local_14 = puVar26;
                NavGraph_addNode(pvVar21,puVar26,local_a0,iVar15,&local_20);
                __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
                return;
              }
              bVar30 = NavGraph_openSetContains(pvVar21,local_a8,local_a0,iVar15);
              uVar31 = CONCAT44(local_dc,local_ec);
              lVar2 = CONCAT44(local_fc,local_bc);
              uVar32 = CONCAT44(local_f0,local_c0);
              uVar33 = CONCAT44(local_cc,local_b4);
              if (bVar30) {
                uVar23 = *best_node;
                if ((char)local_98 == '\0') {
                  uVar23 = uVar23 + 0x28;
                }
                uVar31 = CONCAT44(local_dc,local_ec);
                lVar2 = CONCAT44(local_fc,local_bc);
                uVar32 = CONCAT44(local_f0,local_c0);
                uVar33 = CONCAT44(local_cc,local_b4);
                if ((int)uVar23 < *best_iter) {
                  local_18 = uVar23 + best_iter[1];
                  local_c = local_9c;
                  local_14 = local_a8;
                  local_10 = local_a0;
                  local_20 = uVar23;
                  local_1c = best_iter[1];
                  NavGraph_addNode(pvVar21,local_a8,local_a0,iVar15,&local_20);
                  uVar33 = CONCAT44(local_cc,local_b4);
                  uVar32 = CONCAT44(local_f0,local_c0);
                  lVar2 = CONCAT44(local_fc,local_bc);
                  uVar31 = CONCAT44(local_dc,local_ec);
                }
              }
            }
            local_cc = (uint)(uVar33 >> 0x20);
            local_b4 = (uint)uVar33;
            local_f0 = (int)(uVar32 >> 0x20);
            local_c0 = (int *)uVar32;
            local_fc = (uint)((ulonglong)lVar2 >> 0x20);
            local_bc = (uint)lVar2;
            local_dc = (int)(uVar31 >> 0x20);
            local_ec = (uint)uVar31;
            __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
            return;
          }
          iVar15 = iVar15 + 4;
        } while (iVar15 < 0xc);
      }
    }
    else {
      World_clearContainers((int)agent);
    }
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004e1e50 @ 004e1e50 */

undefined4 * __cdecl FUN_004e1e50(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
    }
    param_1 = param_1 + 2;
    param_3 = param_3 + 2;
  } while (param_1 != param_2);
  return param_3;
}




/* Global::FUN_004f38a0 @ 004f38a0 */

void __cdecl FUN_004f38a0(int param_1,int param_2,int param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2;
  while( true ) {
    iVar4 = iVar3 * 2 + 2;
    if (param_3 <= iVar4) break;
    fVar2 = *(float *)(param_1 + -0xc + iVar4 * 0xc);
    pfVar1 = (float *)(param_1 + iVar4 * 0xc);
    if (*pfVar1 <= fVar2 && fVar2 != *pfVar1) {
      iVar4 = iVar3 * 2 + 1;
    }
    *(undefined4 *)(param_1 + iVar3 * 0xc) = *(undefined4 *)(param_1 + iVar4 * 0xc);
    *(undefined4 *)(param_1 + 4 + iVar3 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar4 * 0xc);
    *(undefined4 *)(param_1 + 8 + iVar3 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar4 * 0xc);
    iVar3 = iVar4;
  }
  if (iVar4 == param_3) {
    *(undefined4 *)(param_1 + iVar3 * 0xc) = *(undefined4 *)(param_1 + -0xc + param_3 * 0xc);
    *(undefined4 *)(param_1 + 4 + iVar3 * 0xc) = *(undefined4 *)(param_1 + -8 + param_3 * 0xc);
    *(undefined4 *)(param_1 + 8 + iVar3 * 0xc) = *(undefined4 *)(param_1 + -4 + param_3 * 0xc);
    iVar3 = param_3 + -1;
  }
  FUN_004f5ac0(param_1,iVar3,param_2,param_4);
  return;
}




/* Global::FUN_004f39e0 @ 004f39e0 */

void __cdecl FUN_004f39e0(int param_1,int param_2,int param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2;
  while( true ) {
    iVar4 = iVar3 * 2 + 2;
    if (param_3 <= iVar4) break;
    fVar2 = *(float *)(param_1 + iVar4 * 0xc);
    pfVar1 = (float *)(param_1 + -0xc + iVar4 * 0xc);
    if (*pfVar1 <= fVar2 && fVar2 != *pfVar1) {
      iVar4 = iVar3 * 2 + 1;
    }
    *(undefined4 *)(param_1 + iVar3 * 0xc) = *(undefined4 *)(param_1 + iVar4 * 0xc);
    *(undefined4 *)(param_1 + 4 + iVar3 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar4 * 0xc);
    *(undefined4 *)(param_1 + 8 + iVar3 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar4 * 0xc);
    iVar3 = iVar4;
  }
  if (iVar4 == param_3) {
    *(undefined4 *)(param_1 + iVar3 * 0xc) = *(undefined4 *)(param_1 + -0xc + param_3 * 0xc);
    *(undefined4 *)(param_1 + 4 + iVar3 * 0xc) = *(undefined4 *)(param_1 + -8 + param_3 * 0xc);
    *(undefined4 *)(param_1 + 8 + iVar3 * 0xc) = *(undefined4 *)(param_1 + -4 + param_3 * 0xc);
    iVar3 = param_3 + -1;
  }
  FUN_004f5bc0(param_1,iVar3,param_2,param_4);
  return;
}




/* Global::FUN_004f4860 @ 004f4860 */

void __cdecl FUN_004f4860(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float *pfVar6;
  uint uVar7;
  float *pfVar8;
  
  uVar7 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  pfVar6 = param_1;
  if (param_1 != param_2) {
    while (pfVar6 = pfVar6 + 3, pfVar6 != param_2) {
      fVar2 = *pfVar6;
      uVar5 = *(undefined8 *)(pfVar6 + 1);
      uVar4 = *(undefined8 *)(pfVar6 + 1);
      if (*param_1 <= fVar2) {
        fVar3 = pfVar6[-3];
        pfVar8 = pfVar6;
        while (fVar2 < fVar3) {
          *pfVar8 = fVar3;
          pfVar8[1] = pfVar8[-2];
          pfVar8[2] = pfVar8[-1];
          fVar3 = pfVar8[-6];
          pfVar8 = pfVar8 + -3;
        }
        *pfVar8 = fVar2;
        *(undefined8 *)(pfVar8 + 1) = uVar5;
      }
      else {
        if (param_1 != pfVar6) {
          pfVar8 = pfVar6 + 4;
          do {
            pfVar8[-4] = pfVar8[-7];
            pfVar8[-3] = pfVar8[-6];
            pfVar8[-2] = pfVar8[-5];
            pfVar1 = pfVar8 + -7;
            pfVar8 = pfVar8 + -3;
          } while (pfVar1 != param_1);
        }
        *param_1 = fVar2;
        *(undefined8 *)(param_1 + 1) = uVar4;
      }
    }
  }
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004f49d0 @ 004f49d0 */

void __cdecl FUN_004f49d0(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float *pfVar6;
  uint uVar7;
  float *pfVar8;
  
  uVar7 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  pfVar6 = param_1;
  if (param_1 != param_2) {
    while (pfVar6 = pfVar6 + 3, pfVar6 != param_2) {
      fVar2 = *pfVar6;
      uVar5 = *(undefined8 *)(pfVar6 + 1);
      uVar4 = *(undefined8 *)(pfVar6 + 1);
      if (fVar2 < *param_1 || fVar2 == *param_1) {
        fVar3 = pfVar6[-3];
        pfVar8 = pfVar6;
        while (fVar3 < fVar2) {
          *pfVar8 = fVar3;
          pfVar8[1] = pfVar8[-2];
          pfVar8[2] = pfVar8[-1];
          fVar3 = pfVar8[-6];
          pfVar8 = pfVar8 + -3;
        }
        *pfVar8 = fVar2;
        *(undefined8 *)(pfVar8 + 1) = uVar5;
      }
      else {
        if (param_1 != pfVar6) {
          pfVar8 = pfVar6 + 4;
          do {
            pfVar8[-4] = pfVar8[-7];
            pfVar8[-3] = pfVar8[-6];
            pfVar8[-2] = pfVar8[-5];
            pfVar1 = pfVar8 + -7;
            pfVar8 = pfVar8 + -3;
          } while (pfVar1 != param_1);
        }
        *param_1 = fVar2;
        *(undefined8 *)(param_1 + 1) = uVar4;
      }
    }
  }
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004f4b50 @ 004f4b50 */

void __cdecl FUN_004f4b50(int param_1,int param_2)

{
  undefined8 *puVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  uVar7 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  iVar5 = (param_2 - param_1) / 0xc;
  iVar12 = iVar5 / 2;
  if (0 < iVar12) {
    iVar10 = iVar12 * 2 + 2;
    iVar8 = param_1 + iVar12 * 0xc + 8;
    do {
      puVar1 = (undefined8 *)(iVar8 + -0x10);
      fVar3 = *(float *)(iVar8 + -0x14);
      iVar8 = iVar8 + -0xc;
      uVar6 = *puVar1;
      iVar10 = iVar10 + -2;
      iVar12 = iVar12 + -1;
      iVar11 = iVar10;
      iVar9 = iVar12;
      while (iVar13 = iVar11, iVar13 < iVar5) {
        fVar4 = *(float *)(param_1 + -0xc + iVar13 * 0xc);
        pfVar2 = (float *)(param_1 + iVar13 * 0xc);
        if (*pfVar2 <= fVar4 && fVar4 != *pfVar2) {
          iVar13 = iVar13 + -1;
        }
        *(undefined4 *)(param_1 + iVar9 * 0xc) = *(undefined4 *)(param_1 + iVar13 * 0xc);
        *(undefined4 *)(param_1 + 4 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar13 * 0xc);
        *(undefined4 *)(param_1 + 8 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar13 * 0xc);
        iVar9 = iVar13;
        iVar11 = iVar13 * 2 + 2;
      }
      if (iVar13 == iVar5) {
        *(undefined4 *)(param_1 + iVar9 * 0xc) = *(undefined4 *)(param_1 + -0xc + iVar5 * 0xc);
        *(undefined4 *)(param_1 + 4 + iVar9 * 0xc) = *(undefined4 *)(param_1 + -8 + iVar5 * 0xc);
        *(undefined4 *)(param_1 + 8 + iVar9 * 0xc) = *(undefined4 *)(param_1 + -4 + iVar5 * 0xc);
        iVar9 = iVar5 + -1;
      }
      while (iVar12 < iVar9) {
        iVar11 = (iVar9 + -1) / 2;
        fVar4 = *(float *)(param_1 + iVar11 * 0xc);
        if (fVar3 <= fVar4) break;
        *(float *)(param_1 + iVar9 * 0xc) = fVar4;
        *(undefined4 *)(param_1 + 4 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar11 * 0xc);
        *(undefined4 *)(param_1 + 8 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar11 * 0xc);
        iVar9 = iVar11;
      }
      *(float *)(param_1 + iVar9 * 0xc) = fVar3;
      *(undefined8 *)(param_1 + 4 + iVar9 * 0xc) = uVar6;
    } while (0 < iVar12);
  }
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004f4dd0 @ 004f4dd0 */

void __cdecl FUN_004f4dd0(int param_1,int param_2)

{
  undefined8 *puVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  uVar7 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  iVar5 = (param_2 - param_1) / 0xc;
  iVar12 = iVar5 / 2;
  if (0 < iVar12) {
    iVar10 = iVar12 * 2 + 2;
    iVar8 = param_1 + iVar12 * 0xc + 8;
    do {
      puVar1 = (undefined8 *)(iVar8 + -0x10);
      fVar3 = *(float *)(iVar8 + -0x14);
      iVar8 = iVar8 + -0xc;
      uVar6 = *puVar1;
      iVar10 = iVar10 + -2;
      iVar12 = iVar12 + -1;
      iVar11 = iVar10;
      iVar9 = iVar12;
      while (iVar13 = iVar11, iVar13 < iVar5) {
        fVar4 = *(float *)(param_1 + iVar13 * 0xc);
        pfVar2 = (float *)(param_1 + -0xc + iVar13 * 0xc);
        if (*pfVar2 <= fVar4 && fVar4 != *pfVar2) {
          iVar13 = iVar13 + -1;
        }
        *(undefined4 *)(param_1 + iVar9 * 0xc) = *(undefined4 *)(param_1 + iVar13 * 0xc);
        *(undefined4 *)(param_1 + 4 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar13 * 0xc);
        *(undefined4 *)(param_1 + 8 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar13 * 0xc);
        iVar9 = iVar13;
        iVar11 = iVar13 * 2 + 2;
      }
      if (iVar13 == iVar5) {
        *(undefined4 *)(param_1 + iVar9 * 0xc) = *(undefined4 *)(param_1 + -0xc + iVar5 * 0xc);
        *(undefined4 *)(param_1 + 4 + iVar9 * 0xc) = *(undefined4 *)(param_1 + -8 + iVar5 * 0xc);
        *(undefined4 *)(param_1 + 8 + iVar9 * 0xc) = *(undefined4 *)(param_1 + -4 + iVar5 * 0xc);
        iVar9 = iVar5 + -1;
      }
      while (iVar12 < iVar9) {
        iVar11 = (iVar9 + -1) / 2;
        fVar4 = *(float *)(param_1 + iVar11 * 0xc);
        if (fVar4 <= fVar3) break;
        *(float *)(param_1 + iVar9 * 0xc) = fVar4;
        *(undefined4 *)(param_1 + 4 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar11 * 0xc);
        *(undefined4 *)(param_1 + 8 + iVar9 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar11 * 0xc);
        iVar9 = iVar11;
      }
      *(float *)(param_1 + iVar9 * 0xc) = fVar3;
      *(undefined8 *)(param_1 + 4 + iVar9 * 0xc) = uVar6;
    } while (0 < iVar12);
  }
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004f5170 @ 004f5170 */

void __cdecl FUN_004f5170(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  
  fVar1 = *param_1;
  iVar5 = ((int)param_3 - (int)param_1) / 0xc;
  if (iVar5 < 0x29) {
    fVar2 = *param_2;
    if (fVar2 < fVar1) {
      fVar3 = param_2[1];
      fVar4 = param_2[2];
      *param_2 = fVar1;
      param_2[1] = param_1[1];
      param_2[2] = param_1[2];
      *param_1 = fVar2;
      param_1[1] = fVar3;
      param_1[2] = fVar4;
    }
    fVar1 = *param_3;
    if (fVar1 < *param_2) {
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      *param_2 = fVar1;
      param_2[1] = fVar2;
      param_2[2] = fVar3;
      fVar1 = *param_2;
      if (fVar1 < *param_1) {
        *param_2 = *param_1;
        param_2[1] = param_1[1];
        param_2[2] = param_1[2];
        *param_1 = fVar1;
        param_1[1] = fVar2;
        param_1[2] = fVar3;
      }
    }
  }
  else {
    iVar5 = iVar5 + 1;
    iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
    fVar2 = param_1[iVar5 * 3];
    if (fVar2 < fVar1) {
      fVar3 = param_1[iVar5 * 3 + 2];
      fVar4 = param_1[iVar5 * 3 + 1];
      param_1[iVar5 * 3] = fVar1;
      param_1[iVar5 * 3 + 1] = param_1[1];
      param_1[iVar5 * 3 + 2] = param_1[2];
      *param_1 = fVar2;
      param_1[2] = fVar3;
      param_1[1] = fVar4;
    }
    fVar1 = param_1[iVar5 * 6];
    if (fVar1 < param_1[iVar5 * 3]) {
      fVar2 = param_1[iVar5 * 6 + 1];
      fVar3 = param_1[iVar5 * 6 + 2];
      param_1[iVar5 * 6] = param_1[iVar5 * 3];
      param_1[iVar5 * 6 + 1] = param_1[iVar5 * 3 + 1];
      param_1[iVar5 * 6 + 2] = param_1[iVar5 * 3 + 2];
      param_1[iVar5 * 3] = fVar1;
      param_1[iVar5 * 3 + 1] = fVar2;
      param_1[iVar5 * 3 + 2] = fVar3;
      fVar1 = param_1[iVar5 * 3];
      if (fVar1 < *param_1) {
        param_1[iVar5 * 3] = *param_1;
        param_1[iVar5 * 3 + 1] = param_1[1];
        param_1[iVar5 * 3 + 2] = param_1[2];
        *param_1 = fVar1;
        param_1[1] = fVar2;
        param_1[2] = fVar3;
      }
    }
    fVar1 = *param_2;
    pfVar6 = param_2 + iVar5 * -3;
    if (fVar1 < *pfVar6) {
      fVar2 = param_2[1];
      fVar3 = param_2[2];
      *param_2 = *pfVar6;
      param_2[1] = pfVar6[1];
      param_2[2] = pfVar6[2];
      *pfVar6 = fVar1;
      pfVar6[1] = fVar2;
      pfVar6[2] = fVar3;
    }
    fVar1 = param_2[iVar5 * 3];
    if (fVar1 < *param_2) {
      fVar2 = param_2[iVar5 * 3 + 1];
      fVar3 = param_2[iVar5 * 3 + 2];
      param_2[iVar5 * 3] = *param_2;
      param_2[iVar5 * 3 + 1] = param_2[1];
      param_2[iVar5 * 3 + 2] = param_2[2];
      *param_2 = fVar1;
      param_2[1] = fVar2;
      param_2[2] = fVar3;
      fVar1 = *param_2;
      if (fVar1 < *pfVar6) {
        *param_2 = *pfVar6;
        param_2[1] = pfVar6[1];
        param_2[2] = pfVar6[2];
        *pfVar6 = fVar1;
        pfVar6[1] = fVar2;
        pfVar6[2] = fVar3;
      }
    }
    pfVar7 = param_3 + iVar5 * -6;
    pfVar6 = param_3 + iVar5 * -3;
    fVar1 = *pfVar6;
    if (fVar1 < *pfVar7) {
      fVar2 = pfVar6[2];
      fVar3 = pfVar6[1];
      *pfVar6 = *pfVar7;
      pfVar6[1] = pfVar7[1];
      pfVar6[2] = pfVar7[2];
      *pfVar7 = fVar1;
      pfVar7[2] = fVar2;
      pfVar7[1] = fVar3;
    }
    fVar1 = *param_3;
    if (fVar1 < *pfVar6) {
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      *param_3 = *pfVar6;
      param_3[1] = pfVar6[1];
      param_3[2] = pfVar6[2];
      *pfVar6 = fVar1;
      pfVar6[1] = fVar2;
      pfVar6[2] = fVar3;
      fVar1 = *pfVar6;
      if (fVar1 < *pfVar7) {
        fVar2 = pfVar6[1];
        *pfVar6 = *pfVar7;
        pfVar6[1] = pfVar7[1];
        pfVar6[2] = pfVar7[2];
        *pfVar7 = fVar1;
        pfVar7[1] = fVar2;
        pfVar7[2] = fVar3;
      }
    }
    fVar1 = *param_2;
    if (fVar1 < param_1[iVar5 * 3]) {
      fVar2 = param_2[1];
      fVar3 = param_2[2];
      *param_2 = param_1[iVar5 * 3];
      param_2[1] = param_1[iVar5 * 3 + 1];
      param_2[2] = param_1[iVar5 * 3 + 2];
      param_1[iVar5 * 3] = fVar1;
      param_1[iVar5 * 3 + 1] = fVar2;
      param_1[iVar5 * 3 + 2] = fVar3;
    }
    fVar1 = *pfVar6;
    if (fVar1 < *param_2) {
      fVar2 = pfVar6[1];
      fVar3 = pfVar6[2];
      *pfVar6 = *param_2;
      pfVar6[1] = param_2[1];
      pfVar6[2] = param_2[2];
      *param_2 = fVar1;
      param_2[1] = fVar2;
      param_2[2] = fVar3;
      fVar1 = *param_2;
      if (fVar1 < param_1[iVar5 * 3]) {
        *param_2 = param_1[iVar5 * 3];
        param_2[1] = param_1[iVar5 * 3 + 1];
        param_2[2] = param_1[iVar5 * 3 + 2];
        param_1[iVar5 * 3] = fVar1;
        param_1[iVar5 * 3 + 1] = fVar2;
        param_1[iVar5 * 3 + 2] = fVar3;
        return;
      }
    }
  }
  return;
}




/* Global::FUN_004f55b0 @ 004f55b0 */

void __cdecl FUN_004f55b0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  
  fVar1 = *param_1;
  iVar5 = ((int)param_3 - (int)param_1) / 0xc;
  if (iVar5 < 0x29) {
    fVar2 = *param_2;
    if (fVar1 < fVar2) {
      fVar3 = param_2[1];
      fVar4 = param_2[2];
      *param_2 = fVar1;
      param_2[1] = param_1[1];
      param_2[2] = param_1[2];
      *param_1 = fVar2;
      param_1[1] = fVar3;
      param_1[2] = fVar4;
    }
    fVar1 = *param_3;
    if (*param_2 < fVar1) {
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      *param_2 = fVar1;
      param_2[1] = fVar2;
      param_2[2] = fVar3;
      fVar1 = *param_2;
      if (*param_1 < fVar1) {
        *param_2 = *param_1;
        param_2[1] = param_1[1];
        param_2[2] = param_1[2];
        *param_1 = fVar1;
        param_1[1] = fVar2;
        param_1[2] = fVar3;
      }
    }
  }
  else {
    iVar5 = iVar5 + 1;
    iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
    fVar2 = param_1[iVar5 * 3];
    if (fVar1 < fVar2) {
      fVar3 = param_1[iVar5 * 3 + 2];
      fVar4 = param_1[iVar5 * 3 + 1];
      param_1[iVar5 * 3] = fVar1;
      param_1[iVar5 * 3 + 1] = param_1[1];
      param_1[iVar5 * 3 + 2] = param_1[2];
      *param_1 = fVar2;
      param_1[2] = fVar3;
      param_1[1] = fVar4;
    }
    fVar1 = param_1[iVar5 * 6];
    if (param_1[iVar5 * 3] < fVar1) {
      fVar2 = param_1[iVar5 * 6 + 1];
      fVar3 = param_1[iVar5 * 6 + 2];
      param_1[iVar5 * 6] = param_1[iVar5 * 3];
      param_1[iVar5 * 6 + 1] = param_1[iVar5 * 3 + 1];
      param_1[iVar5 * 6 + 2] = param_1[iVar5 * 3 + 2];
      param_1[iVar5 * 3] = fVar1;
      param_1[iVar5 * 3 + 1] = fVar2;
      param_1[iVar5 * 3 + 2] = fVar3;
      fVar1 = param_1[iVar5 * 3];
      if (*param_1 < fVar1) {
        param_1[iVar5 * 3] = *param_1;
        param_1[iVar5 * 3 + 1] = param_1[1];
        param_1[iVar5 * 3 + 2] = param_1[2];
        *param_1 = fVar1;
        param_1[1] = fVar2;
        param_1[2] = fVar3;
      }
    }
    fVar1 = *param_2;
    pfVar6 = param_2 + iVar5 * -3;
    if (*pfVar6 < fVar1) {
      fVar2 = param_2[1];
      fVar3 = param_2[2];
      *param_2 = *pfVar6;
      param_2[1] = pfVar6[1];
      param_2[2] = pfVar6[2];
      *pfVar6 = fVar1;
      pfVar6[1] = fVar2;
      pfVar6[2] = fVar3;
    }
    fVar1 = param_2[iVar5 * 3];
    if (*param_2 < fVar1) {
      fVar2 = param_2[iVar5 * 3 + 1];
      fVar3 = param_2[iVar5 * 3 + 2];
      param_2[iVar5 * 3] = *param_2;
      param_2[iVar5 * 3 + 1] = param_2[1];
      param_2[iVar5 * 3 + 2] = param_2[2];
      *param_2 = fVar1;
      param_2[1] = fVar2;
      param_2[2] = fVar3;
      fVar1 = *param_2;
      if (*pfVar6 < fVar1) {
        *param_2 = *pfVar6;
        param_2[1] = pfVar6[1];
        param_2[2] = pfVar6[2];
        *pfVar6 = fVar1;
        pfVar6[1] = fVar2;
        pfVar6[2] = fVar3;
      }
    }
    pfVar7 = param_3 + iVar5 * -6;
    pfVar6 = param_3 + iVar5 * -3;
    fVar1 = *pfVar6;
    if (*pfVar7 < fVar1) {
      fVar2 = pfVar6[2];
      fVar3 = pfVar6[1];
      *pfVar6 = *pfVar7;
      pfVar6[1] = pfVar7[1];
      pfVar6[2] = pfVar7[2];
      *pfVar7 = fVar1;
      pfVar7[2] = fVar2;
      pfVar7[1] = fVar3;
    }
    fVar1 = *param_3;
    if (*pfVar6 < fVar1) {
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      *param_3 = *pfVar6;
      param_3[1] = pfVar6[1];
      param_3[2] = pfVar6[2];
      *pfVar6 = fVar1;
      pfVar6[1] = fVar2;
      pfVar6[2] = fVar3;
      fVar1 = *pfVar6;
      if (*pfVar7 < fVar1) {
        fVar2 = pfVar6[1];
        *pfVar6 = *pfVar7;
        pfVar6[1] = pfVar7[1];
        pfVar6[2] = pfVar7[2];
        *pfVar7 = fVar1;
        pfVar7[1] = fVar2;
        pfVar7[2] = fVar3;
      }
    }
    fVar1 = *param_2;
    if (param_1[iVar5 * 3] < fVar1) {
      fVar2 = param_2[1];
      fVar3 = param_2[2];
      *param_2 = param_1[iVar5 * 3];
      param_2[1] = param_1[iVar5 * 3 + 1];
      param_2[2] = param_1[iVar5 * 3 + 2];
      param_1[iVar5 * 3] = fVar1;
      param_1[iVar5 * 3 + 1] = fVar2;
      param_1[iVar5 * 3 + 2] = fVar3;
    }
    fVar1 = *pfVar6;
    if (*param_2 < fVar1) {
      fVar2 = pfVar6[1];
      fVar3 = pfVar6[2];
      *pfVar6 = *param_2;
      pfVar6[1] = param_2[1];
      pfVar6[2] = param_2[2];
      *param_2 = fVar1;
      param_2[1] = fVar2;
      param_2[2] = fVar3;
      fVar1 = *param_2;
      if (param_1[iVar5 * 3] < fVar1) {
        *param_2 = param_1[iVar5 * 3];
        param_2[1] = param_1[iVar5 * 3 + 1];
        param_2[2] = param_1[iVar5 * 3 + 2];
        param_1[iVar5 * 3] = fVar1;
        param_1[iVar5 * 3 + 1] = fVar2;
        param_1[iVar5 * 3 + 2] = fVar3;
        return;
      }
    }
  }
  return;
}




/* Global::FUN_004f5ac0 @ 004f5ac0 */

void __cdecl FUN_004f5ac0(int param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  
  while (param_3 < param_2) {
    iVar2 = (param_2 + -1) / 2;
    fVar1 = *(float *)(param_1 + iVar2 * 0xc);
    if (*param_4 <= fVar1) break;
    *(float *)(param_1 + param_2 * 0xc) = fVar1;
    *(undefined4 *)(param_1 + 4 + param_2 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 8 + param_2 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar2 * 0xc);
    param_2 = iVar2;
  }
  *(float *)(param_1 + param_2 * 0xc) = *param_4;
  *(float *)(param_1 + 4 + param_2 * 0xc) = param_4[1];
  *(float *)(param_1 + 8 + param_2 * 0xc) = param_4[2];
  return;
}




/* Global::FUN_004f5bc0 @ 004f5bc0 */

void __cdecl FUN_004f5bc0(int param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  
  while (param_3 < param_2) {
    iVar2 = (param_2 + -1) / 2;
    fVar1 = *(float *)(param_1 + iVar2 * 0xc);
    if (fVar1 < *param_4 || fVar1 == *param_4) break;
    *(float *)(param_1 + param_2 * 0xc) = fVar1;
    *(undefined4 *)(param_1 + 4 + param_2 * 0xc) = *(undefined4 *)(param_1 + 4 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 8 + param_2 * 0xc) = *(undefined4 *)(param_1 + 8 + iVar2 * 0xc);
    param_2 = iVar2;
  }
  *(float *)(param_1 + param_2 * 0xc) = *param_4;
  *(float *)(param_1 + 4 + param_2 * 0xc) = param_4[1];
  *(float *)(param_1 + 8 + param_2 * 0xc) = param_4[2];
  return;
}




/* Global::FUN_004f71e0 @ 004f71e0 */

undefined4 * __cdecl FUN_004f71e0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 != param_2) {
    iVar1 = param_1 - (int)param_3;
    do {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(iVar1 + (int)param_3);
        param_3[1] = *(undefined4 *)(iVar1 + 4 + (int)param_3);
        param_3[2] = *(undefined4 *)(iVar1 + 8 + (int)param_3);
      }
      param_3 = param_3 + 3;
    } while (iVar1 + (int)param_3 != param_2);
    return param_3;
  }
  return param_3;
}




/* Global::FUN_004f8230 @ 004f8230 */

void __thiscall FUN_004f8230(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 <= (uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0xc)) {
    return;
  }
  iVar1 = (*(int *)((int)this + 4) - *(int *)this) / 0xc;
  if (0x15555555U - iVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("vector<T> too long");
  }
  uVar2 = (*(int *)((int)this + 8) - *(int *)this) / 0xc;
  uVar3 = iVar1 + param_1;
  if (0x15555555 - (uVar2 >> 1) < uVar2) {
    uVar2 = 0;
    if (uVar3 != 0) {
      uVar2 = uVar3;
    }
    FUN_004f7ef0(this,uVar2);
    return;
  }
  uVar2 = uVar2 + (uVar2 >> 1);
  if (uVar2 < uVar3) {
    uVar2 = uVar3;
  }
  FUN_004f7ef0(this,uVar2);
  return;
}




/* [AUDIT] proposed: World::findNearestFeatureCell  (confidence: high)
 * purpose: Searches a 3x3-ish grid region for the nearest feature/object cell to a point; returns cell coords+ptr
 * vars: this+grid stride 0x400; param_2/3=x/y; local_4c=best cell; local_48=best dist^2
 */
/* Global::World_findNearestFeatureCell @ 004febd0 */

void __thiscall World_findNearestFeatureCell(void *this,undefined8 *out_cell,int x,int y)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint security_cookie;
  int min_row;
  int max_col;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int min_col;
  float10 fVar13;
  float10 fVar14;
  uint *best_cell;
  int best_dist;
  undefined8 dx;
  undefined8 dy;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  min_row = (int)(y + -0x4000 + (y + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  max_col = (int)(x + 0x4000 + (x + 0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  min_col = (int)((x + -0x4000 >> 0x1f & 0x3fffU) + x + -0x4000) >> 0xe;
  fVar13 = valueNoise2D(SUB84((double)y * 0.0005,0),
                        (int)((ulonglong)((double)y * 0.0005) >> 0x20),3423.0);
  fVar14 = valueNoise2D(SUB84((double)x * 0.0005,0),
                        (int)((ulonglong)((double)x * 0.0005) >> 0x20),23421.0);
  best_cell = (uint *)0x0;
  uVar8 = (uint)((float)x + (float)fVar13 * 3.0 * 256.0);
  *(undefined4 *)out_cell = 0xffffffff;
  *(undefined4 *)((int)out_cell + 4) = 0xffffffff;
  uVar9 = (uint)((float)y + (float)fVar14 * 3.0 * 256.0);
  best_dist = 0;
  if (min_col <= max_col) {
    iVar10 = min_col * 0x400 + 0x10002f;
    iVar4 = min_row;
    do {
      for (; iVar4 <= (int)(y + 0x4000 + (y + 0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
          iVar4 = iVar4 + 1) {
        if ((((-1 < min_col) && (-1 < iVar4)) && (iVar10 < 0x20002f)) &&
           ((iVar4 < 0x400 &&
            (puVar1 = *(uint **)((int)this + (iVar10 + iVar4) * 4), puVar1 != (uint *)0x0)))) {
          uVar2 = *puVar1;
          uVar3 = puVar1[1];
          dx = CONCAT44(((((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) -
                              (((int)uVar8 >> 0x1f) << 0x10 | uVar8 >> 0x10)) -
                              (uint)(uVar2 * 0x10000 < uVar8 * 0x10000),
                              uVar2 * 0x10000 + uVar8 * -0x10000);
          dy = CONCAT44(((((int)uVar3 >> 0x1f) << 0x10 | uVar3 >> 0x10) -
                              (((int)uVar9 >> 0x1f) << 0x10 | uVar9 >> 0x10)) -
                              (uint)(uVar3 * 0x10000 < uVar9 * 0x10000),
                              uVar3 * 0x10000 + uVar9 * -0x10000);
          iVar11 = (int)((float)dy * 1.5258789e-05 * (float)dy * 1.5258789e-05 +
                        (float)dx * 1.5258789e-05 * (float)dx * 1.5258789e-05);
          if ((best_cell == (uint *)0x0) || (iVar11 < best_dist)) {
            *out_cell = CONCAT44(iVar4,min_col);
            best_cell = puVar1;
            best_dist = iVar11;
          }
        }
      }
      min_col = min_col + 1;
      iVar10 = iVar10 + 0x400;
      iVar4 = min_row;
    } while (min_col <= max_col);
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World_biomeBorderDistance  (confidence: low)
 * purpose: Computes terrain slope/shading factor at (x,y) sampling neighbor heights via noise; uses point-seg distances
 * vars: this+0x8001fc..+0x800218=noise offsets; pointSegmentDistanceSq=seg dist; World_findNearestFeatureCell=nearest cell
 */
/* Global::World_biomeBorderDistance @ 00522840 */

void __thiscall World_biomeBorderDistance(void *this,int x,int y)

{
  int iVar1;
  int *cell;
  int *neighbor;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  float10 fVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float min_dist;
  double world_x;
  double world_y;
  int cell_x;
  int cell_y;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  World_findNearestFeatureCell(this,(undefined8 *)&cell_x,x,y);
  if ((((-1 < cell_x) && (-1 < cell_y)) && (cell_x < 0x400)) && (cell_y < 0x400)) {
    iVar4 = cell_x * 0x400;
    cell = *(int **)((int)this + (iVar4 + cell_y) * 4 + 0x4000bc);
    if (cell != (int *)0x0) {
      min_dist = -1.0;
      local_20 = (double)y * 0.01;
      dVar8 = (double)y * 0.0005;
      local_10 = (double)x * 0.01;
      dVar7 = (double)x * 0.0005;
      dVar6 = (double)*(int *)((int)this + 0x800204) + local_10;
      fVar5 = valueNoise2D(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20),
                           (double)*(int *)((int)this + 0x800208) + local_20);
      world_y = (double)(float)fVar5 * 0.1;
      dVar6 = (double)*(int *)((int)this + 0x8001fc) + dVar7;
      fVar5 = valueNoise2D(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20),
                           (double)*(int *)((int)this + 0x800200) + dVar8);
      world_x = (world_y + (double)(float)fVar5) * 500.0 + (double)x;
      dVar6 = (double)*(int *)((int)this + 0x800214) + local_10;
      fVar5 = valueNoise2D(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20),
                           (double)*(int *)((int)this + 0x800218) + local_20);
      local_10 = (double)(float)fVar5 * 0.1;
      dVar7 = (double)*(int *)((int)this + 0x80020c) + dVar7;
      fVar5 = valueNoise2D(SUB84(dVar7,0),(int)((ulonglong)dVar7 >> 0x20),
                           (double)*(int *)((int)this + 0x800210) + dVar8);
      iVar1 = cell_x + -1;
      world_y = (local_10 + (double)(float)fVar5) * 500.0 + (double)y;
      if (((-1 < iVar1) && (iVar1 < 0x400)) &&
         (neighbor = *(int **)((int)this + (iVar1 * 0x400 + cell_y) * 4 + 0x4000bc),
         neighbor != (int *)0x0)) {
        local_18 = (double)*neighbor;
        local_10 = (double)neighbor[1];
        local_28 = (double)*cell;
        local_20 = (double)cell[1];
        fVar5 = pointSegmentDistanceSq(&local_28,&local_18,&world_x);
        min_dist = (float)fVar5;
        cell_x = extraout_ECX;
      }
      cell_x = cell_x + 1;
      if (((-1 < cell_x) && (cell_x < 0x400)) &&
         (neighbor = *(int **)((int)this + (cell_x * 0x400 + cell_y) * 4 + 0x4000bc),
         neighbor != (int *)0x0)) {
        local_18 = (double)*neighbor;
        local_10 = (double)neighbor[1];
        local_28 = (double)*cell;
        local_20 = (double)cell[1];
        fVar5 = pointSegmentDistanceSq(&local_28,&local_18,&world_x);
        if ((min_dist < 0.0) || ((float)fVar5 < min_dist)) {
          min_dist = (float)fVar5;
        }
      }
      iVar1 = cell_y + -1;
      if (((-1 < iVar1) && (iVar1 < 0x400)) &&
         (neighbor = *(int **)((int)this + (iVar1 + iVar4) * 4 + 0x4000bc), neighbor != (int *)0x0)) {
        local_18 = (double)*neighbor;
        local_10 = (double)neighbor[1];
        local_28 = (double)*cell;
        local_20 = (double)cell[1];
        fVar5 = pointSegmentDistanceSq(&local_28,&local_18,&world_x);
        iVar4 = extraout_ECX_00;
        if ((min_dist < 0.0) || ((float)fVar5 < min_dist)) {
          min_dist = (float)fVar5;
        }
      }
      cell_y = cell_y + 1;
      if (((-1 < cell_y) && (cell_y < 0x400)) &&
         (neighbor = *(int **)((int)this + (iVar4 + cell_y) * 4 + 0x4000bc), neighbor != (int *)0x0))
      {
        local_18 = (double)*neighbor;
        local_10 = (double)neighbor[1];
        local_28 = (double)*cell;
        local_20 = (double)cell[1];
        fVar5 = pointSegmentDistanceSq(&local_28,&local_18,&world_x);
        if ((min_dist < 0.0) || ((float)fVar5 < min_dist)) {
          min_dist = (float)fVar5;
        }
      }
      if (0.0 <= min_dist) {
        __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World::waterProximityInfluence  (confidence: low)
 * purpose: Scans grid region for water/feature cells (type flag==1); accumulates smoothed proximity influence
 * vars: this+grid; local_80..=cell bounds; 5e-07 dist scaling
 */
/* Global::World_waterProximityInfluence @ 00522e20 */

void __thiscall World_waterProximityInfluence(void *this,int x,int y)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint security_cookie;
  int min_col;
  int max_col;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int row_base;
  int iVar12;
  int max_row;
  int iVar14;
  uint *puVar15;
  float10 fVar16;
  float10 fVar17;
  float fVar18;
  float weight_sum;
  uint *best_cell;
  int best_dist;
  int min_row;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  min_col = (int)(y + -0x4000 + (y + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  max_col = (int)(x + 0x4000 + (x + 0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  min_row = (int)((x + -0x4000 >> 0x1f & 0x3fffU) + x + -0x4000) >> 0xe;
  max_row = (int)((y + 0x4000 >> 0x1f & 0x3fffU) + y + 0x4000) >> 0xe;
  bVar3 = false;
  if (min_row <= max_col) {
    row_base = min_row * 0x400 + 0x10002f;
    iVar10 = min_col;
    iVar14 = min_row;
    iVar12 = row_base;
joined_r0x00522ec4:
    do {
      if (iVar10 <= max_row) {
        if ((((iVar14 < 0) || (iVar10 < 0)) || (0x20002e < iVar12)) ||
           ((0x3ff < iVar10 || (iVar9 = *(int *)((int)this + (iVar12 + iVar10) * 4), iVar9 == 0))))
        goto LAB_0052336b;
        if (*(char *)(iVar9 + 8) != '\x01') {
          iVar10 = iVar10 + 1;
          goto joined_r0x00522ec4;
        }
        bVar3 = true;
      }
      iVar14 = iVar14 + 1;
      iVar12 = iVar12 + 0x400;
      iVar10 = min_col;
    } while (iVar14 <= max_col);
    if (bVar3) {
      fVar16 = valueNoise2D(SUB84((double)y * 0.0005,0),
                            (int)((ulonglong)((double)y * 0.0005) >> 0x20),3423.0);
      fVar17 = valueNoise2D(SUB84((double)x * 0.0005,0),
                            (int)((ulonglong)((double)x * 0.0005) >> 0x20),23421.0);
      uVar7 = (uint)((float)x + (float)fVar16 * 3.0 * 256.0);
      puVar15 = (uint *)0x0;
      best_cell = (uint *)0x0;
      best_dist = 0;
      uVar8 = (uint)((float)y + (float)fVar17 * 3.0 * 256.0);
      iVar10 = row_base;
      iVar14 = min_row;
      do {
        for (iVar12 = min_col; iVar12 <= max_row; iVar12 = iVar12 + 1) {
          if (((iVar14 < 0) || (iVar12 < 0)) ||
             ((0x20002e < iVar10 ||
              ((0x3ff < iVar12 ||
               (puVar15 = *(uint **)((int)this + (iVar12 + iVar10) * 4), puVar15 == (uint *)0x0)))))
             ) goto LAB_0052336b;
          uVar1 = *puVar15;
          uVar2 = puVar15[1];
          local_28 = CONCAT44(((((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10) -
                              (((int)uVar7 >> 0x1f) << 0x10 | uVar7 >> 0x10)) -
                              (uint)(uVar1 * 0x10000 < uVar7 * 0x10000),
                              uVar1 * 0x10000 + uVar7 * -0x10000);
          local_20 = CONCAT44(((((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) -
                              (((int)uVar8 >> 0x1f) << 0x10 | uVar8 >> 0x10)) -
                              (uint)(uVar2 * 0x10000 < uVar8 * 0x10000),
                              uVar2 * 0x10000 + uVar8 * -0x10000);
          iVar9 = (int)((float)local_20 * 1.5258789e-05 * (float)local_20 * 1.5258789e-05 +
                       (float)local_28 * 1.5258789e-05 * (float)local_28 * 1.5258789e-05);
          if ((best_cell == (uint *)0x0) || (iVar9 < best_dist)) {
            best_cell = puVar15;
            best_dist = iVar9;
          }
          puVar15 = best_cell;
        }
        iVar14 = iVar14 + 1;
        iVar10 = iVar10 + 0x400;
      } while (iVar14 <= max_col);
      if (puVar15 != (uint *)0x0) {
        weight_sum = 0.0;
        iVar10 = min_col;
        do {
          for (; iVar10 <= max_row; iVar10 = iVar10 + 1) {
            if ((((min_row < 0) || (iVar10 < 0)) || (0x20002e < row_base)) ||
               ((0x3ff < iVar10 ||
                (puVar15 = *(uint **)((int)this + (iVar10 + row_base) * 4), puVar15 == (uint *)0x0))))
            goto LAB_0052336b;
            uVar1 = *puVar15;
            uVar2 = puVar15[1];
            local_18 = CONCAT44(((((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10) -
                                (((int)uVar7 >> 0x1f) << 0x10 | uVar7 >> 0x10)) -
                                (uint)(uVar1 * 0x10000 < uVar7 * 0x10000),
                                uVar1 * 0x10000 + uVar7 * -0x10000);
            local_10 = CONCAT44(((((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) -
                                (((int)uVar8 >> 0x1f) << 0x10 | uVar8 >> 0x10)) -
                                (uint)(uVar2 * 0x10000 < uVar8 * 0x10000),
                                uVar2 * 0x10000 + uVar8 * -0x10000);
            fVar18 = (float)((int)((float)local_10 * 1.5258789e-05 * (float)local_10 * 1.5258789e-05
                                  + (float)local_18 * 1.5258789e-05 *
                                    (float)local_18 * 1.5258789e-05) - best_dist) * 5e-07;
            if (1.0 < fVar18) {
              fVar18 = 1.0;
            }
            weight_sum = weight_sum + (1.0 - fVar18);
          }
          min_row = min_row + 1;
          row_base = row_base + 0x400;
          iVar10 = min_col;
        } while (min_row <= max_col);
        if (0.0 < weight_sum) {
          __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
LAB_0052336b:
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: pointSegmentDistanceSq  (confidence: high)
 * purpose: Squared distance from point param_3 to segment [x,y] (2D), clamped to endpoints
 * vars: dVar1=seg len^2; projection param t clamped 0..1
 */
/* Global::pointSegmentDistanceSq @ 00523380 */

float10 __cdecl pointSegmentDistanceSq(double *seg_start,double *seg_end,double *point)

{
  double seg_len_sq;
  double pt_dy;
  double pt_dx;
  double seg_dx;
  double seg_dy;
  
  pt_dx = *point - *seg_start;
  seg_dx = *seg_end - *seg_start;
  seg_dy = seg_end[1] - seg_start[1];
  pt_dy = point[1] - seg_start[1];
  seg_len_sq = seg_dx * seg_dx + seg_dy * seg_dy;
  if (seg_len_sq < 9.999999682655225e-21) {
    return (float10)(float)(pt_dy * pt_dy + pt_dx * pt_dx);
  }
  seg_len_sq = (pt_dy * seg_dy + pt_dx * seg_dx) / seg_len_sq;
  if (seg_len_sq <= 0.0) {
    return (float10)(float)(pt_dy * pt_dy + pt_dx * pt_dx);
  }
  if (1.0 <= seg_len_sq) {
    seg_len_sq = point[1] - seg_end[1];
    pt_dy = *point - *seg_end;
    return (float10)(float)(seg_len_sq * seg_len_sq + pt_dy * pt_dy);
  }
  pt_dx = pt_dx - seg_dx * seg_len_sq;
  pt_dy = pt_dy - seg_dy * seg_len_sq;
  return (float10)(float)(pt_dy * pt_dy + pt_dx * pt_dx);
}




/* [AUDIT] proposed: Creature::resolveSeparation  (confidence: low)
 * purpose: Physics separation/collision resolution between two creatures; normalizes overlap and applies push along axis
 * vars: seg_end/3=entity a/b state; param_4=radius; +0x88=creature size; heavy local math
 */
/* Global::Creature_resolveSeparation @ 0052ef00 */

/* WARNING: Removing unreachable block (ram,0x0052fae6) */
/* WARNING: Removing unreachable block (ram,0x0052f93e) */
/* WARNING: Removing unreachable block (ram,0x0052f887) */
/* WARNING: Removing unreachable block (ram,0x0052fa3b) */
/* WARNING: Removing unreachable block (ram,0x0052fb34) */

void __thiscall Creature_resolveSeparation(void *this,int arg,uint *pos_a,uint *pos_b,float radius)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 **ppuVar11;
  undefined4 uVar12;
  uint uVar13;
  void *this_00;
  float fVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  undefined4 *puVar20;
  bool bVar21;
  double dVar22;
  float fVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  undefined8 uVar28;
  undefined1 auStack_2d0 [7];
  char local_2c9;
  float local_2c8;
  float local_2c4;
  uint local_2c0;
  uint local_2bc;
  float local_2b8;
  int *local_2b4;
  uint local_2b0;
  uint local_2ac;
  int *local_2a8;
  int param_copy;
  float local_2a0;
  int iStack_29c;
  char local_291;
  uint local_290;
  uint local_28c;
  float local_288;
  uint local_284;
  float local_280;
  int local_27c;
  int *local_278;
  void *local_274;
  int *local_270;
  float local_26c;
  undefined4 *local_268;
  float *local_264;
  float local_260;
  float local_25c;
  float radius_sq;
  float local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  uint local_234;
  float local_230;
  int local_22c;
  undefined4 *local_228;
  undefined4 local_224;
  float local_220;
  float local_21c;
  undefined8 local_218;
  int local_210;
  int iStack_20c;
  uint local_208 [2];
  int *local_200;
  uint uStack_1fc;
  undefined8 local_1f8;
  float local_1ec [3];
  uint local_1e0;
  int iStack_1dc;
  uint local_1d8;
  int iStack_1d4;
  longlong local_1d0;
  undefined8 local_1c4;
  float local_1bc;
  uint local_1b8;
  int iStack_1b4;
  uint local_1b0;
  int iStack_1ac;
  longlong local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  longlong local_190;
  uint local_188;
  int iStack_184;
  int local_180;
  int iStack_17c;
  undefined8 local_178;
  uint local_170;
  int iStack_16c;
  int local_168;
  int iStack_164;
  longlong local_160;
  int local_154;
  int local_150;
  int local_14c;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  uint local_130;
  int *local_12c;
  int local_128;
  float local_124;
  float local_120;
  float dx;
  float dz;
  int local_110;
  int iStack_10c;
  int local_108;
  int iStack_104;
  int local_100;
  int iStack_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e4 [9];
  uint local_c0 [7];
  float local_a4 [3];
  uint local_98 [18];
  longlong local_50;
  longlong local_48;
  int local_40;
  int iStack_3c;
  int local_38;
  int iStack_34;
  int local_28;
  int iStack_24;
  int local_20;
  int iStack_1c;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)auStack_2d0;
  param_copy = arg;
  local_28c = *pos_a;
  local_2b4 = (int *)pos_a[2];
  local_2ac = pos_a[1];
  local_2b0 = pos_a[3];
  uVar13 = *pos_b;
  local_284 = pos_b[1];
  local_40 = local_28c - uVar13;
  iStack_3c = (local_2ac - local_284) - (uint)(local_28c < uVar13);
  local_2a8 = (int *)pos_b[2];
  local_2c8 = (float)pos_b[3];
  local_38 = (int)local_2b4 - (int)local_2a8;
  iStack_34 = (local_2b0 - (int)local_2c8) - (uint)(local_2b4 < local_2a8);
  dx = (float)CONCAT44(iStack_3c,local_40) * 1.5258789e-05;
  radius_sq = radius * radius;
  dz = (float)CONCAT44(iStack_34,local_38) * 1.5258789e-05;
  local_274 = this;
  if (dz * dz + dx * dx < radius_sq) {
    local_2a0 = (float)(pos_a[4] - pos_b[4]);
    iStack_29c = (pos_a[5] - pos_b[5]) - (uint)(pos_a[4] < pos_b[4]);
    local_2c4 = (float)CONCAT44(iStack_29c,local_2a0);
    if (ABS(local_2c4 * 1.5258789e-05) < *(float *)(arg + 0x88) + radius) {
LAB_0052f06b:
      __security_check_cookie(security_cookie ^ (uint)auStack_2d0);
      return;
    }
  }
  local_28 = uVar13 - local_28c;
  local_1f8._0_4_ = pos_a[4];
  local_1f8._4_4_ = pos_a[5];
  iStack_24 = (local_284 - local_2ac) - (uint)(uVar13 < local_28c);
  local_20 = (int)local_2a8 - (int)local_2b4;
  iStack_1c = ((int)local_2c8 - local_2b0) - (uint)(local_2a8 < local_2b4);
  local_124 = (float)CONCAT44(iStack_24,local_28) * 1.5258789e-05;
  local_120 = (float)CONCAT44(iStack_1c,local_20) * 1.5258789e-05;
  local_21c = 0.0;
  fVar23 = local_120 * local_120 + local_124 * local_124 + 0.0;
  local_2c8 = local_120;
  local_2c4 = local_124;
  local_208[0] = local_28c;
  local_208[1] = local_2ac;
  local_200 = local_2b4;
  uStack_1fc = local_2b0;
  if (2500.0 < fVar23) {
    dVar22 = (double)fVar23;
    libm_sse2_sqrt_precise();
    local_124 = (1.0 / (float)dVar22) * local_2c4 * 50.0;
    local_120 = (1.0 / (float)dVar22) * local_2c8 * 50.0;
  }
  dVar22 = (double)(local_120 * local_120 + local_124 * local_124 + 0.5625);
  libm_sse2_sqrt_precise();
  uVar26 = CONCAT44(local_2c8,local_278);
  uVar24 = CONCAT44(local_2a8,local_290);
  local_2c4 = 0.0;
  local_2a0 = (float)(int)((float)dVar22 + 1.0);
  lVar4 = local_1f8;
  if (0 < (int)local_2a0) {
    do {
      iVar18 = param_copy;
      local_2a8 = (int *)(uVar24 >> 0x20);
      local_290 = (uint)uVar24;
      local_1a0 = CONCAT44((local_208[1] - pos_b[1]) - (uint)(local_208[0] < *pos_b),
                           local_208[0] - *pos_b);
      local_198 = CONCAT44((uStack_1fc - pos_b[3]) - (uint)(local_200 < (int *)pos_b[2]),
                           (int)local_200 - (int)pos_b[2]);
      puVar1 = pos_b + 4;
      local_50 = local_1a0;
      local_190 = local_1f8 - *(longlong *)puVar1;
      local_48 = local_198;
      local_f8 = (float)local_1a0 * 1.5258789e-05;
      local_f4 = (float)local_198 * 1.5258789e-05;
      if (local_f4 * local_f4 + local_f8 * local_f8 <= radius_sq) {
        local_218 = local_1f8 - *(longlong *)puVar1;
        local_2c8 = (float)(local_1f8 - *(longlong *)puVar1);
        if (ABS(local_2c8 * 1.5258789e-05) < *(float *)(param_copy + 0x88) + radius)
        goto LAB_0052f06b;
      }
      local_148._0_4_ = (uint)*(undefined8 *)pos_b;
      local_148._4_4_ = (int)((ulonglong)*(undefined8 *)pos_b >> 0x20);
      local_148 = CONCAT44((local_148._4_4_ - local_208[1]) - (uint)((uint)local_148 < local_208[0])
                           ,(uint)local_148 - local_208[0]);
      local_140._0_4_ = (int *)*(undefined8 *)(pos_b + 2);
      local_140._4_4_ = (int)((ulonglong)*(undefined8 *)(pos_b + 2) >> 0x20);
      local_140 = CONCAT44((local_140._4_4_ - uStack_1fc) - (uint)((int *)local_140 < local_200),
                           (int)(int *)local_140 - (int)local_200);
      local_138 = *(undefined8 *)(pos_b + 4);
      local_1ec[0] = (float)local_148 * 1.5258789e-05;
      local_2c8 = (float)local_140 * 1.5258789e-05;
      local_1ec[1] = local_2c8;
      fVar23 = local_2c8 * local_2c8 + local_1ec[0] * local_1ec[0] + local_21c;
      if (0.0 < fVar23) {
        dVar22 = (double)fVar23;
        libm_sse2_sqrt_precise();
        uVar24 = CONCAT44(local_2a8,local_290);
        local_1ec[0] = (1.0 / (float)dVar22) * local_1ec[0];
        local_1ec[1] = (1.0 / (float)dVar22) * local_2c8;
      }
      uVar26 = CONCAT44(local_2c8,local_278);
      local_1ec[2] = -0.71;
      local_2b0 = 0;
      local_264 = (float *)(iVar18 + 0x80);
      do {
        uVar19 = local_2b0;
        local_2c8 = (float)(uVar26 >> 0x20);
        local_278 = (int *)uVar26;
        local_2a8 = (int *)(uVar24 >> 0x20);
        local_290 = (uint)uVar24;
        local_240 = local_1ec[local_2b0] * 65536.0;
        uVar24 = ftol2();
        local_22c = (int)(uVar24 >> 0x20);
        local_234 = (uint)uVar24;
        puVar1 = local_208 + uVar19 * 2;
        uVar13 = *puVar1;
        *puVar1 = *puVar1 + local_234;
        local_208[uVar19 * 2 + 1] =
             local_208[uVar19 * 2 + 1] + local_22c + (uint)CARRY4(uVar13,local_234);
        local_291 = '\x01';
        cVar5 = WalkPathBehavior_checkPathClear(local_274,local_208,(float *)(iVar18 + 0x80),'\0');
        uVar26 = CONCAT44(local_2c8,local_278);
        uVar24 = CONCAT44(local_2a8,local_290);
        local_2c9 = cVar5;
        if ((cVar5 == '\0') || (cVar6 = local_291, uVar19 == 2)) {
          uVar28 = __alldiv(local_208[0],local_208[1],0x10000,0);
          iVar18 = (int)(((int)uVar28 >> 0x1f & 7U) + (int)uVar28) >> 3;
          uVar28 = __alldiv((uint)local_200,uStack_1fc,0x10000,0);
          uVar26 = CONCAT44(local_2c8,local_278);
          uVar24 = CONCAT44(local_2a8,local_290);
          uVar13 = iVar18 - 1;
          local_288 = (float)(iVar18 + 1);
          iVar18 = (int)((int)uVar28 + ((int)uVar28 >> 0x1f & 7U)) >> 3;
          if ((int)local_288 < (int)uVar13) {
            cVar5 = local_2c9;
            local_2bc = uVar13;
            if (local_2c9 != '\0') {
LAB_0052fba4:
              iVar18 = param_copy;
              cVar6 = '\0';
              goto LAB_0052fbaa;
            }
          }
          else {
            local_280 = (float)(iVar18 - 1);
            uVar17 = iVar18 + 1;
            fVar23 = local_280;
            local_2c0 = uVar17;
            do {
              cVar6 = local_2c9;
              local_2bc = uVar13;
              if ((int)uVar17 < (int)fVar23) {
                fVar14 = fVar23;
                uVar19 = local_2b0;
                cVar5 = local_2c9;
                local_2b8 = fVar23;
                if (local_2c9 != '\0') goto LAB_0052fba4;
              }
              else {
                do {
                  local_278 = (int *)uVar26;
                  local_2b8 = fVar23;
                  if ((((-1 < (int)uVar13) && (-1 < (int)fVar23)) && ((int)uVar13 < 0x200000)) &&
                     ((int)fVar23 < 0x200000)) {
                    iVar18 = ((int)fVar23 >> 0x1f & 0x1fU) + (int)fVar23;
                    uVar16 = iVar18 >> 5;
                    iVar7 = ((int)uVar13 >> 0x1f & 0x1fU) + uVar13;
                    uVar19 = iVar7 >> 5;
                    uVar13 = local_2bc;
                    uVar17 = local_2c0;
                    cVar6 = local_2c9;
                    if (((-1 < (int)uVar19) && (-1 < (int)uVar16)) &&
                       (((int)uVar19 < 0x10000 && ((int)uVar16 < 0x10000)))) {
                      iVar7 = (int)(uVar19 + (iVar7 >> 0x1f & 0x3fU)) >> 6;
                      iVar18 = (int)((iVar18 >> 0x1f & 0x3fU) + uVar16) >> 6;
                      if (((-1 < iVar7) && (-1 < iVar18)) &&
                         ((iVar7 < 0x400 &&
                          ((iVar18 < 0x400 &&
                           (iVar18 = *(int *)((int)local_274 + (iVar7 * 0x400 + iVar18) * 4 + 0xbc),
                           iVar18 != 0)))))) {
                        uVar19 = uVar19 & 0x8000003f;
                        if ((int)uVar19 < 0) {
                          uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
                        }
                        uVar16 = uVar16 & 0x8000003f;
                        if ((int)uVar16 < 0) {
                          uVar16 = (uVar16 - 1 | 0xffffffc0) + 1;
                        }
                        iVar18 = *(int *)(iVar18 + 0x10018 + (uVar19 * 0x40 + uVar16) * 4);
                        if (iVar18 != 0) {
                          uVar19 = (uint)fVar23 & 0x8000001f;
                          if ((int)uVar19 < 0) {
                            uVar19 = (uVar19 - 1 | 0xffffffe0) + 1;
                          }
                          uVar16 = local_2bc & 0x8000001f;
                          if ((int)uVar16 < 0) {
                            uVar16 = (uVar16 - 1 | 0xffffffe0) + 1;
                          }
                          piVar15 = (int *)(*(int *)(iVar18 + 0xac) + (uVar19 * 0x20 + uVar16) * 8);
                          if (piVar15 != (int *)0x0) {
                            local_270 = (int *)*piVar15;
                            piVar15 = (int *)*local_270;
                            if (piVar15 != local_270) {
                              do {
                                local_2a8 = (int *)(uVar24 >> 0x20);
                                local_290 = (uint)uVar24;
                                local_2b4 = (int *)piVar15[2];
                                iVar18 = *local_2b4;
                                uVar26 = CONCAT44(iVar18,local_278);
                                if (((iVar18 != 7) &&
                                    (uVar26 = CONCAT44(iVar18,local_278), iVar18 != 6)) &&
                                   (uVar26 = CONCAT44(iVar18,local_278), iVar18 != 9)) {
                                  puVar3 = *(undefined4 **)(param_copy + 0x1468);
                                  puVar20 = puVar3;
                                  if (*(char *)((int)puVar3[1] + 0xd) == '\0') {
                                    puVar9 = (undefined4 *)puVar3[1];
                                    do {
                                      if ((uint)puVar9[4] < (uint)piVar15[2]) {
                                        puVar10 = (undefined4 *)puVar9[2];
                                      }
                                      else {
                                        puVar10 = (undefined4 *)*puVar9;
                                        puVar20 = puVar9;
                                      }
                                      puVar9 = puVar10;
                                    } while (*(char *)((int)puVar10 + 0xd) == '\0');
                                  }
                                  if ((puVar20 == puVar3) || ((uint)piVar15[2] < (uint)puVar20[4]))
                                  {
                                    local_268 = puVar3;
                                    ppuVar11 = &local_268;
                                  }
                                  else {
                                    local_228 = puVar20;
                                    ppuVar11 = &local_228;
                                  }
                                  uVar26 = CONCAT44(iVar18,local_278);
                                  if ((*ppuVar11 == puVar3) &&
                                     ((((iVar18 != 1 && (iVar18 != 8)) &&
                                       ((iVar18 != 2 && ((iVar18 != 3 && (iVar18 != 5)))))) ||
                                      (uVar26 = CONCAT44(iVar18,local_278),
                                      (char)local_2b4[0xc] != '\0')))) {
                                    local_1c4 = *(undefined8 *)(local_2b4 + 9);
                                    local_1bc = (float)local_2b4[0xb];
                                    uVar13 = local_2b4[8] & 0x80000001;
                                    bVar21 = uVar13 == 0;
                                    if ((int)uVar13 < 0) {
                                      bVar21 = (uVar13 - 1 | 0xfffffffe) == 0xffffffff;
                                    }
                                    if (!bVar21) {
                                      local_1c4._4_4_ = (float)((ulonglong)local_1c4 >> 0x20);
                                      local_1c4 = CONCAT44((float)local_1c4,local_1c4._4_4_);
                                    }
                                    local_210 = local_208[local_2b0 * 2] -
                                                local_2b4[local_2b0 * 2 + 2];
                                    iStack_20c = (local_208[local_2b0 * 2 + 1] -
                                                 local_2b4[local_2b0 * 2 + 3]) -
                                                 (uint)(local_208[local_2b0 * 2] <
                                                       (uint)local_2b4[local_2b0 * 2 + 2]);
                                    local_2c8 = (float)CONCAT44(iStack_20c,local_210);
                                    local_25c = local_2c8 * local_1ec[local_2b0];
                                    uVar27 = ftol2();
                                    local_2c8 = (float)uVar27;
                                    local_224 = 0;
                                    uVar25 = ftol2();
                                    uVar24 = CONCAT44(local_2a8,local_290);
                                    uVar26 = CONCAT44(local_2c8,local_278);
                                    if (CONCAT44((int)(uVar27 >> 0x20),local_2c8) < (longlong)uVar25
                                       ) {
                                      local_260 = (float)local_1c4 * 0.5 * 65536.0;
                                      uVar24 = ftol2();
                                      local_28c = (uint)(uVar24 >> 0x20);
                                      local_278 = (int *)uVar24;
                                      local_2c8 = (float)local_2b4[2];
                                      uVar13 = local_2b4[3];
                                      local_238 = *local_264 * 0.5 * 65536.0;
                                      local_2ac = uVar13;
                                      uVar24 = ftol2();
                                      local_2a8 = (int *)(uVar24 >> 0x20);
                                      local_290 = (uint)uVar24;
                                      local_27c = (int)local_2c8 - (int)local_278;
                                      lVar4 = uVar24 + CONCAT44(local_208[1],local_208[0]);
                                      uVar12 = (undefined4)lVar4;
                                      uVar26 = CONCAT44(uVar12,local_278);
                                      if (CONCAT44((uVar13 - local_28c) -
                                                   (uint)((uint)local_2c8 < local_278),local_27c) <=
                                          lVar4) {
                                        local_2ac = uVar13 + local_28c +
                                                    (uint)CARRY4((uint)local_2c8,(uint)local_278);
                                        iVar18 = (local_208[1] - (int)local_2a8) -
                                                 (uint)(local_208[0] < local_290);
                                        uVar26 = CONCAT44(uVar12,local_278);
                                        if ((iVar18 <= (int)local_2ac) &&
                                           ((iVar18 < (int)local_2ac ||
                                            (uVar26 = CONCAT44(uVar12,local_278),
                                            local_208[0] - local_290 <
                                            (uint)((int)local_2c8 + (int)local_278))))) {
                                          local_250 = local_1c4._4_4_ * 0.5 * 65536.0;
                                          local_2c8 = (float)uVar12;
                                          uVar24 = ftol2();
                                          local_28c = (uint)(uVar24 >> 0x20);
                                          local_2a8 = (int *)uVar24;
                                          local_290 = local_2b4[4];
                                          uVar13 = local_2b4[5];
                                          local_230 = *(float *)(param_copy + 0x84) * 0.5 * 65536.0;
                                          local_2ac = uVar13;
                                          uVar26 = ftol2();
                                          local_2c8 = (float)(uVar26 >> 0x20);
                                          local_278 = (int *)uVar26;
                                          local_27c = local_290 - (int)local_2a8;
                                          lVar4 = uVar26 + CONCAT44(uStack_1fc,local_200);
                                          uVar12 = (undefined4)lVar4;
                                          uVar24 = CONCAT44(local_2a8,uVar12);
                                          if (CONCAT44((uVar13 - local_28c) -
                                                       (uint)(local_290 < local_2a8),local_27c) <=
                                              lVar4) {
                                            local_2ac = uVar13 + local_28c +
                                                        (uint)CARRY4(local_290,(uint)local_2a8);
                                            iVar18 = (uStack_1fc - (int)local_2c8) -
                                                     (uint)(local_200 < local_278);
                                            uVar24 = CONCAT44(local_2a8,uVar12);
                                            if ((iVar18 <= (int)local_2ac) &&
                                               ((iVar18 < (int)local_2ac ||
                                                (uVar24 = CONCAT44(local_2a8,uVar12),
                                                (uint)((int)local_200 - (int)local_278) <
                                                local_290 + (int)local_2a8)))) {
                                              local_248 = *(float *)(param_copy + 0x88) * 0.5 *
                                                          65536.0;
                                              local_290 = uVar12;
                                              uVar27 = ftol2();
                                              local_2c8 = (float)(uVar27 >> 0x20);
                                              local_2a8 = (int *)uVar27;
                                              uVar26 = CONCAT44(local_2c8,local_278);
                                              local_290 = (uint)*(longlong *)(local_2b4 + 6);
                                              local_27c = local_2b4[7];
                                              uVar24 = CONCAT44(local_2a8,local_290);
                                              if (*(longlong *)(local_2b4 + 6) <=
                                                  (longlong)(uVar27 + local_1f8)) {
                                                local_220 = local_1bc * 65536.0;
                                                uVar27 = ftol2();
                                                uVar26 = CONCAT44(local_2c8,local_278);
                                                uVar24 = CONCAT44(local_2a8,local_290);
                                                if (local_1f8 - CONCAT44(local_2c8,local_2a8) <
                                                    (longlong)
                                                    (uVar27 + CONCAT44(local_27c,local_290))) {
                                                  uVar19 = local_2b0;
                                                  cVar5 = '\x01';
                                                  uVar24 = CONCAT44(local_2a8,local_290);
                                                  uVar26 = CONCAT44(local_2c8,local_278);
                                                  goto LAB_0052fba4;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                local_278 = (int *)uVar26;
                                piVar15 = (int *)*piVar15;
                                uVar13 = local_2bc;
                                uVar17 = local_2c0;
                                cVar6 = local_2c9;
                              } while (piVar15 != local_270);
                            }
                          }
                        }
                      }
                    }
                  }
                  uVar19 = local_2b0;
                  cVar5 = local_2c9;
                  if (cVar6 != '\0') goto LAB_0052fba4;
                  fVar23 = (float)((int)local_2b8 + 1);
                  fVar14 = local_280;
                  local_2b8 = fVar23;
                } while ((int)fVar23 <= (int)uVar17);
              }
              uVar13 = uVar13 + 1;
              fVar23 = fVar14;
              uVar19 = local_2b0;
              local_2bc = uVar13;
            } while ((int)uVar13 <= (int)local_288);
          }
        }
        else {
LAB_0052fbaa:
          if (cVar5 != '\0') {
            if (((uVar19 == 2) || (cVar6 == '\0')) || ((*(ushort *)(iVar18 + 0x7e) & 0x100) != 0)) {
LAB_00530301:
              puVar1 = local_208 + uVar19 * 2;
              uVar13 = *puVar1;
              *puVar1 = *puVar1 - local_234;
              local_208[uVar19 * 2 + 1] =
                   (local_208[uVar19 * 2 + 1] - local_22c) - (uint)(uVar13 < local_234);
            }
            else {
              local_288 = *(float *)(iVar18 + 0x80);
              local_280 = *(float *)(iVar18 + 0x84);
              local_270 = *(int **)(iVar18 + 0x88);
              local_284 = local_284 & 0xffffff00;
              local_e4[0] = local_288 * 0.5;
              iVar18 = 0;
              local_e4[1] = local_280 * 0.5;
              local_e4[2] = (float)local_270 * 0.5;
              do {
                local_2c8 = (float)(uVar26 >> 0x20);
                local_278 = (int *)uVar26;
                local_2a8 = (int *)(uVar24 >> 0x20);
                local_290 = (uint)uVar24;
                local_26c = local_e4[iVar18] * 65536.0;
                uVar27 = ftol2();
                uVar26 = CONCAT44(local_2c8,local_278);
                uVar24 = CONCAT44(local_2a8,local_290);
                local_98[iVar18 * 2] = (uint)uVar27;
                local_98[iVar18 * 2 + 1] = (uint)(uVar27 >> 0x20);
                iVar18 = iVar18 + 1;
              } while (iVar18 < 3);
              local_e4[3] = 0.0;
              local_e4[4] = 0.0;
              local_e4[5] = 1.01;
              iVar18 = 0;
              do {
                local_254 = local_e4[iVar18 + 3] * 65536.0;
                uVar24 = ftol2();
                local_c0[iVar18 * 2] = (uint)uVar24;
                local_c0[iVar18 * 2 + 1] = (uint)(uVar24 >> 0x20);
                iVar18 = iVar18 + 1;
              } while (iVar18 < 3);
              uVar13 = local_208[0] + local_c0[0];
              iVar18 = local_208[1] + local_c0[1] + (uint)CARRY4(local_208[0],local_c0[0]);
              _local_1e0 = CONCAT44(iVar18,uVar13);
              uVar19 = (int)local_200 + local_c0[2];
              iVar7 = uStack_1fc + local_c0[3] + (uint)CARRY4((uint)local_200,local_c0[2]);
              _local_1d8 = CONCAT44(iVar7,uVar19);
              local_1d0 = local_1f8 + CONCAT44(local_c0[5],local_c0[4]);
              _local_170 = CONCAT44((iVar18 - local_98[1]) - (uint)(uVar13 < local_98[0]),
                                    uVar13 - local_98[0]);
              _local_168 = CONCAT44((iVar7 - local_98[3]) - (uint)(uVar19 < local_98[2]),
                                    uVar19 - local_98[2]);
              local_160 = (local_1f8 + CONCAT44(local_c0[5],local_c0[4])) -
                          CONCAT44(local_98[5],local_98[4]);
              Vec3i64_toBlockCoords((int *)&local_130,&local_170);
              iVar18 = 0;
              local_a4[0] = local_288 * 0.5;
              local_a4[1] = local_280 * 0.5;
              local_a4[2] = (float)local_270 * 0.5;
              do {
                local_24c = local_a4[iVar18] * 65536.0;
                uVar24 = ftol2();
                local_98[iVar18 * 2 + 6] = (uint)uVar24;
                local_98[iVar18 * 2 + 7] = (uint)(uVar24 >> 0x20);
                iVar18 = iVar18 + 1;
              } while (iVar18 < 3);
              local_e4[6] = 0.0;
              local_e4[7] = 0.0;
              local_e4[8] = 1.01;
              iVar18 = 0;
              do {
                local_244 = local_e4[iVar18 + 6] * 65536.0;
                uVar24 = ftol2();
                local_98[iVar18 * 2 + 0xc] = (uint)uVar24;
                local_98[iVar18 * 2 + 0xd] = (uint)(uVar24 >> 0x20);
                iVar18 = iVar18 + 1;
              } while (iVar18 < 3);
              uVar13 = local_208[0] + local_98[0xc];
              iVar18 = local_208[1] + local_98[0xd] + (uint)CARRY4(local_208[0],local_98[0xc]);
              _local_1b8 = CONCAT44(iVar18,uVar13);
              uVar19 = (int)local_200 + local_98[0xe];
              iVar7 = uStack_1fc + local_98[0xf] + (uint)CARRY4((uint)local_200,local_98[0xe]);
              _local_1b0 = CONCAT44(iVar7,uVar19);
              local_1a8 = local_1f8 + CONCAT44(local_98[0x11],local_98[0x10]);
              _local_188 = CONCAT44(iVar18 + local_98[7] + (uint)CARRY4(uVar13,local_98[6]),
                                    uVar13 + local_98[6]);
              _local_180 = CONCAT44(iVar7 + local_98[9] + (uint)CARRY4(uVar19,local_98[8]),
                                    uVar19 + local_98[8]);
              local_178 = local_1f8 + CONCAT44(local_98[0x11],local_98[0x10]) +
                          CONCAT44(local_98[0xb],local_98[10]);
              Vec3i64_toBlockCoords(&local_154,&local_188);
              local_2c0 = local_130;
              uVar13 = local_130;
              piVar15 = local_12c;
              if ((int)local_130 <= local_154) {
                do {
                  local_2b4 = piVar15;
                  piVar15 = local_2b4;
                  iVar18 = local_128;
                  local_2c0 = uVar13;
                  if ((int)local_2b4 <= local_150) {
                    do {
                      if (iVar18 <= local_14c) {
                        do {
                          if ((((int)uVar13 < 0) || ((int)local_2b4 < 0)) ||
                             ((0xffffff < (int)uVar13 || (0xffffff < (int)local_2b4)))) {
LAB_005301cb:
                            puVar8 = &DAT_005842dc;
                          }
                          else {
                            iVar7 = ((int)local_2b4 >> 0x1f & 0xffU) + (int)local_2b4;
                            uVar19 = iVar7 >> 8;
                            iVar2 = ((int)uVar13 >> 0x1f & 0xffU) + uVar13;
                            uVar13 = iVar2 >> 8;
                            if (((((int)uVar13 < 0) || ((int)uVar19 < 0)) || (0xffff < (int)uVar13))
                               || (0xffff < (int)uVar19)) goto LAB_005301cb;
                            local_288 = (float)((int)(uVar19 + (iVar7 >> 0x1f & 0x3fU)) >> 6);
                            iVar7 = (int)(uVar13 + (iVar2 >> 0x1f & 0x3fU)) >> 6;
                            if ((((iVar7 < 0) || ((int)local_288 < 0)) || (0x3ff < iVar7)) ||
                               ((0x3ff < (int)local_288 ||
                                (iVar7 = *(int *)((int)local_274 +
                                                 (iVar7 * 0x400 + (int)local_288) * 4 + 0xbc),
                                iVar7 == 0)))) goto LAB_005301cb;
                            uVar13 = uVar13 & 0x8000003f;
                            if ((int)uVar13 < 0) {
                              uVar13 = (uVar13 - 1 | 0xffffffc0) + 1;
                            }
                            uVar19 = uVar19 & 0x8000003f;
                            if ((int)uVar19 < 0) {
                              uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
                            }
                            iVar7 = *(int *)(iVar7 + 0x10018 + (uVar13 * 0x40 + uVar19) * 4);
                            if (iVar7 == 0) goto LAB_005301cb;
                            uVar13 = (uint)local_2b4 & 0x800000ff;
                            if ((int)uVar13 < 0) {
                              uVar13 = (uVar13 - 1 | 0xffffff00) + 1;
                            }
                            uVar19 = local_2c0 & 0x800000ff;
                            if ((int)uVar19 < 0) {
                              uVar19 = (uVar19 - 1 | 0xffffff00) + 1;
                            }
                            this_00 = (void *)((uVar13 * 0x100 + uVar19) * 0x20 +
                                              *(int *)(iVar7 + 0xa8));
                            if ((this_00 == (void *)0x0) ||
                               (iVar7 = *(int *)((int)this_00 + 0x10), iVar18 < iVar7))
                            goto LAB_005301cb;
                            if (iVar18 < *(int *)((int)this_00 + 0x1c) + iVar7) {
                              puVar8 = Column_getBlockChecked(this_00,iVar18 - iVar7);
                              if ((((puVar8[3] & 0x1f) == 0) && (iVar18 < 1)) &&
                                 ((puVar8[3] & 0x40) == 0)) {
                                puVar8 = &DAT_005842d4;
                              }
                            }
                            else {
                              puVar8 = &DAT_005842d4;
                              if (0 < iVar18) {
                                puVar8 = &DAT_005842d8;
                              }
                            }
                          }
                          uVar26 = CONCAT44(local_2c8,local_278);
                          uVar24 = CONCAT44(local_2a8,local_290);
                          if (((puVar8[3] & 0x1f) != 0) &&
                             (local_284 = local_284 & 0xff, (puVar8[3] & 0x1f) != 2)) {
                            local_284 = 1;
                          }
                          iVar18 = iVar18 + 1;
                          uVar13 = local_2c0;
                        } while (iVar18 <= local_14c);
                        iVar18 = local_128;
                        uVar19 = local_2b0;
                        if ((char)local_284 != '\0') goto LAB_00530301;
                      }
                      local_2b4 = (int *)((int)local_2b4 + 1);
                      piVar15 = local_12c;
                    } while ((int)local_2b4 <= local_150);
                  }
                  local_2c0 = uVar13 + 1;
                  uVar13 = local_2c0;
                } while ((int)local_2c0 <= local_154);
              }
              local_23c = *(float *)(param_copy + 0x88) * 0.5 * 65536.0;
              uVar24 = ftol2();
              local_280 = (float)(uVar24 >> 0x20);
              local_288 = (float)uVar24;
              lVar4 = local_1f8 - uVar24;
              if ((lVar4 < 0x100000000) && (lVar4 < 0)) {
                lVar4 = lVar4 + -0x10000;
              }
              uVar28 = __alldiv((uint)lVar4,(uint)((ulonglong)lVar4 >> 0x20),0x10000,0);
              uVar13 = (uint)uVar28;
              uVar24 = ftol2();
              uVar19 = uVar13 * 0x10000 - (uint)uVar24;
              local_1f8._0_4_ = uVar19 + (int)local_288;
              local_1f8._4_4_ =
                   (((((int)uVar13 >> 0x1f) << 0x10 | uVar13 >> 0x10) - (int)(uVar24 >> 0x20)) -
                   (uint)(uVar13 * 0x10000 < (uint)uVar24)) + (int)local_280 +
                   (uint)CARRY4(uVar19,(uint)local_288);
              uVar27 = ftol2();
              uVar26 = CONCAT44(local_2c8,local_278);
              uVar24 = CONCAT44(local_2a8,local_290);
              local_1f8 = uVar27 + CONCAT44(local_1f8._4_4_,(uint)local_1f8);
              uVar19 = local_2b0;
            }
          }
        }
        local_278 = (int *)uVar26;
        local_2b0 = uVar19 + 1;
        iVar18 = param_copy;
      } while ((int)local_2b0 < 3);
      local_2c4 = (float)((int)local_2c4 + 1);
      lVar4 = local_1f8;
    } while ((int)local_2c4 < (int)local_2a0);
  }
  local_2c8 = (float)(uVar26 >> 0x20);
  local_278 = (int *)uVar26;
  local_1f8._4_4_ = (uint)((ulonglong)lVar4 >> 0x20);
  local_1f8._0_4_ = (uint)lVar4;
  local_2a8 = (int *)(uVar24 >> 0x20);
  local_290 = (uint)uVar24;
  local_110 = local_208[0] - *pos_a;
  iStack_10c = (local_208[1] - pos_a[1]) - (uint)(local_208[0] < *pos_a);
  local_108 = (int)local_200 - pos_a[2];
  iStack_104 = (uStack_1fc - pos_a[3]) - (uint)(local_200 < (int *)pos_a[2]);
  local_100 = (uint)local_1f8 - pos_a[4];
  iStack_fc = (local_1f8._4_4_ - pos_a[5]) - (uint)((uint)local_1f8 < pos_a[4]);
  local_f0 = (float)CONCAT44(iStack_10c,local_110) * 1.5258789e-05;
  local_2a0 = (float)CONCAT44(iStack_fc,local_100);
  local_ec = (float)CONCAT44(iStack_104,local_108) * 1.5258789e-05;
  local_1f8 = lVar4;
  __security_check_cookie(security_cookie ^ (uint)auStack_2d0);
  return;
}




/* Global::`eh_vector_constructor_iterator' @ 0054ad4e */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int count,_func_void_void_ptr *ctor_fn,
               _func_void_void_ptr *param_5)

{
  int index;
  void *in_stack_ffffffcc;
  
  for (index = 0; index < count; index = index + 1) {
    (*ctor_fn)(in_stack_ffffffcc);
  }
  eh_vector_ctor_iter_unwind();
  return;
}




/* Global::`eh_vector_destructor_iterator' @ 0054adb6 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int count,_func_void_void_ptr *dtor_fn)

{
  void *in_stack_ffffffd0;
  
  while( true ) {
    count = count + -1;
    if (count < 0) break;
    (*dtor_fn)(in_stack_ffffffd0);
  }
  eh_vector_dtor_iter_unwind();
  return;
}




