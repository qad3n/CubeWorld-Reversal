// World (world) — server. 48 functions. Bodies = Ghidra pseudo-C.
#include "World.h"

/* [AUDIT] proposed: Vec3_copy  (confidence: high)
 * purpose: Copies 3 dwords (12 bytes) from param_1 into this; vec3/xyz copy assignment
 * vars: this=dest vec3; param_1=src vec3
 */
/* Global::Vec3_copy @ 00401060 */

undefined4 * __thiscall Vec3_copy(void *this,undefined4 *src)

{
  *(undefined4 *)this = *src;
  *(undefined4 *)((int)this + 4) = src[1];
  *(undefined4 *)((int)this + 8) = src[2];
  return this;
}




/* [AUDIT] proposed: Vec3_set  (confidence: high)
 * purpose: Stores 3 dword args into this+0/4/8; vec3 component setter
 * vars: src..3 = x/y/z
 */
/* Global::Vec3_set @ 00401080 */

undefined4 * __thiscall
Vec3_set(void *this,undefined4 x,undefined4 y,undefined4 z)

{
  *(undefined4 *)this = x;
  *(undefined4 *)((int)this + 4) = y;
  *(undefined4 *)((int)this + 8) = z;
  return this;
}




/* [AUDIT] proposed: String_ctorFromCStr  (confidence: high)
 * purpose: std::string ctor from C string; computes strlen then calls assign helper
 * vars: this=std::string; x=null-term C str; +0x10=len +0x14=cap(0xf SSO)
 */
/* Global::String_ctorFromCStr @ 004010e0 */

undefined1 * __thiscall String_ctorFromCStr(void *this,int *src_str)

{
  int ch;
  int *scan;
  
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)this = 0;
  if ((char)*src_str == '\0') {
    String_assign(this,src_str,0);
    return this;
  }
  scan = src_str;
  do {
    ch = *scan;
    scan = (int *)((int)scan + 1);
  } while ((char)ch != '\0');
  String_assign(this,src_str,(int)scan - ((int)src_str + 1));
  return this;
}




/* [AUDIT] proposed: String_destroy  (confidence: high)
 * purpose: std::string clear/free; frees heap buf if capacity>0xf then resets to empty SSO
 * vars: src_str[5]=cap; src_str[4]=len; *src_str=0
 */
/* Global::String_destroy @ 004013a0 */

void __fastcall String_destroy(undefined4 *str)

{
  if (0xf < (uint)str[5]) {
    operator_delete((void *)*str);
  }
  str[5] = 0xf;
  str[4] = 0;
  *(undefined1 *)str = 0;
  return;
}




/* [AUDIT] proposed: getElemPtr4  (confidence: high)
 * purpose: Returns this + str*4; index into dword array
 * vars: str=index
 */
/* Global::getElemPtr4 @ 004013d0 */

int __thiscall getElemPtr4(void *this,int index)

{
  return (int)(void *)((int)this + index * 4);
}




/* [AUDIT] proposed: getField_plus0x10  (confidence: high)
 * purpose: Returns *index + 0x10
 * vars: index=ptr to base
 */
/* Global::getField_plus0x10 @ 00402bc0 */

int __fastcall getField_plus0x10(int *obj)

{
  return *obj + 0x10;
}




/* [AUDIT] proposed: formula_inverse  (confidence: med)
 * purpose: Game curve: (1/(1-x)-1)*20+1
 * vars: obj
 */
/* Global::formula_inverse @ 00411090 */

float10 __cdecl formula_inverse(float param_1)

{
  return (float10)((1.0 / (1.0 - param_1) - 1.0) * 20.0 + 1.0);
}




/* [AUDIT] proposed: RefCountedNode::init  (confidence: med)
 * purpose: Init node: value=param, refcount(+4)=1, weak(+8)=0
 * vars: this,param_1=value
 */
/* Global::RefCountedNode_init @ 0041d800 */

undefined4 * __thiscall RefCountedNode_init(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 1;
  *(undefined4 *)((int)this + 8) = 0;
  return this;
}




/* [AUDIT] proposed: readCombatActionFromStream  (confidence: med)
 * purpose: Deserialize 0x28 record from recv buffer: 5 ints,2 bytes,2 ints,int64
 * vars: this=stream,param_1=out
 */
/* Global::readCombatActionFromStream @ 0041ebc0 */

void __thiscall readCombatActionFromStream(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)((int)this + 8) = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 1) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(piVar1[3] + *piVar1);
    piVar1[3] = piVar1[3] + 1;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 1) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined1 *)(param_1 + 0x15) = *(undefined1 *)(piVar1[3] + *piVar1);
    piVar1[3] = piVar1[3] + 1;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(piVar1[3] + *piVar1);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(piVar1[3] + *piVar1);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 8) {
    piVar1[3] = iVar2;
    return;
  }
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(piVar1[3] + *piVar1);
  piVar1[3] = piVar1[3] + 8;
  return;
}




/* [AUDIT] proposed: readHitFromStream  (confidence: med)
 * purpose: Deserialize 0x14 record from recv buffer: 2 ints,int,byte,int64
 * vars: this=stream,param_1=out
 */
/* Global::readHitFromStream @ 0041ed50 */

void __thiscall readHitFromStream(void *this,undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined4 *)((int)this + 8) = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    *param_1 = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 4) {
    piVar1[3] = iVar2;
  }
  else {
    param_1[1] = *(undefined4 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 4;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 1) {
    piVar1[3] = iVar2;
  }
  else {
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(*piVar1 + piVar1[3]);
    piVar1[3] = piVar1[3] + 1;
  }
  piVar1 = *(int **)this;
  iVar2 = piVar1[1] - *piVar1;
  if (iVar2 < piVar1[3] + 8) {
    piVar1[3] = iVar2;
    return;
  }
  *(undefined8 *)(param_1 + 3) = *(undefined8 *)(*piVar1 + piVar1[3]);
  piVar1[3] = piVar1[3] + 8;
  return;
}




/* [AUDIT] proposed: pair_set2  (confidence: high)
 * purpose: Stores two dwords into object (constructs a pair/2-field struct)
 * vars: this+0=param_1; this+4=param_2
 */
/* Global::pair_set2 @ 00421e30 */

undefined4 * __thiscall pair_set2(void *this,undefined4 a,undefined4 b)

{
  *(undefined4 *)this = a;
  *(undefined4 *)((int)this + 4) = b;
  return this;
}




/* [AUDIT] proposed: deref_getFirst  (confidence: high)
 * purpose: Writes **this (first element / head) into a
 * vars: this=ptr-to-ptr; a=out
 */
/* Global::deref_getFirst @ 00428070 */

void __thiscall deref_getFirst(void *this,undefined4 *out)

{
  *out = **(undefined4 **)this;
  return;
}




/* [AUDIT] proposed: World_findNearestEntityInRegion  (confidence: med)
 * purpose: Scans 0x4000-unit region grid cells around (x,y) for entities, picks nearest by distance (522cc0); spatial query
 * vars: iVar3..5 cell bounds; local_24 best, local_20 dist
 */
/* Global::World_findNearestEntityInRegion @ 0042e090 */

void __thiscall World_findNearestEntityInRegion(void *this,int x,int y)

{
  int cell_val;
  int row;
  int min_col;
  int min_row;
  int max_col;
  int row_base;
  float10 weight;
  int best_cell;
  int best_dist;
  float local_10 [2];
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  min_col = (int)(x + -0x4000 + (x + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  min_row = (int)(y + -0x4000 + (y + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  max_col = (int)((x + 0x4000 >> 0x1f & 0x3fffU) + x + 0x4000) >> 0xe;
  World_terrainOffset2D(local_10,x,y);
  best_cell = 0;
  best_dist = 0;
  if (min_col <= max_col) {
    row_base = min_col * 0x400 + 0x10002f;
    row = min_row;
    do {
      for (; row <= (int)(y + 0x4000 + (y + 0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
          row = row + 1) {
        if ((((-1 < min_col) && (-1 < row)) && (row_base < 0x20002f)) &&
           ((row < 0x400 && (cell_val = *(int *)((int)this + (row_base + row) * 4), cell_val != 0)))) {
          weight = (float10)World_siteDistanceSq();
          if ((best_cell == 0) || ((int)weight < best_dist)) {
            best_cell = cell_val;
            best_dist = (int)weight;
          }
        }
      }
      min_col = min_col + 1;
      row_base = row_base + 0x400;
      row = min_row;
    } while (min_col <= max_col);
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World_loadVoxelModel  (confidence: med)
 * purpose: Loads voxel/model: from file (filebuf/istream read dims+data) or from memory blob; then 430230; World asset load
 * vars: local_e8 filebuf; local_30 rgb buffer; dims read
 */
/* Global::World_loadVoxelModel @ 0042f9a0 */

void __thiscall World_loadVoxelModel(void *this,char *arg_x,void *blob_src,char *flag)

{
  char *pcVar1;
  uint security_cookie;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *data_ptr;
  char *pcVar8;
  int file_stream [3];
  int aiStack_dc [25];
  basic_ios<char,std::char_traits<char>_> stream_ios [72];
  char *voxel_buf;
  int local_2c;
  undefined4 local_28;
  void *local_24;
  void *blob_begin;
  int blob_end;
  undefined4 local_18;
  int blob_cap;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d333;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(char *)((int)this + 0x55) = (char)flag;
  local_24 = this;
  if (blob_src == (void *)0x0) {
    std::basic_filebuf<char,std::char_traits<char>_>::ctor_3
              ((basic_filebuf<char,std::char_traits<char>_> *)file_stream,arg_x,0x20,(int *)0x40,1);
    local_8 = 2;
    if (*(int *)((int)aiStack_dc + *(int *)(file_stream[0] + 4)) == 0) {
      std::basic_istream<char,std::char_traits<char>_>::read
                ((basic_istream<char,std::char_traits<char>_> *)file_stream,(char *)&local_24,
                 (ulonglong)security_cookie << 0x20);
      std::basic_istream<char,std::char_traits<char>_>::read
                ((basic_istream<char,std::char_traits<char>_> *)file_stream,(char *)&blob_src,
                 (ulonglong)security_cookie << 0x20);
      std::basic_istream<char,std::char_traits<char>_>::read
                ((basic_istream<char,std::char_traits<char>_> *)file_stream,(char *)&arg_x,
                 (ulonglong)security_cookie << 0x20);
      voxel_buf = (char *)0x0;
      local_2c = 0;
      local_28 = 0;
      vec3b_resize(&voxel_buf,(int)arg_x * (int)blob_src * (int)local_24);
      data_ptr = voxel_buf;
      local_8 = CONCAT31(local_8._1_3_,3);
      std::basic_istream<char,std::char_traits<char>_>::read
                ((basic_istream<char,std::char_traits<char>_> *)file_stream,voxel_buf,
                 (ulonglong)security_cookie << 0x20);
      World_buildVoxelMesh(this,local_24,blob_src,(int)arg_x,data_ptr,(char)flag);
      if (data_ptr != (char *)0x0) {
        operator_delete(data_ptr);
      }
    }
    std::basic_filebuf<char,std::char_traits<char>_>::ctor_4((int)stream_ios);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(stream_ios)
    ;
  }
  else {
    blob_begin = (void *)0x0;
    blob_end = 0;
    local_18 = 0;
    blob_cap = 0;
    local_8 = 0;
    uVar3 = SpeechDb_loadBlobToVector(blob_src,(undefined4 *)arg_x,&blob_begin);
    if ((char)uVar3 != '\0') {
      Speech_scrambleBlob((int *)&blob_begin);
      iVar4 = blob_end - (int)blob_begin;
      iVar5 = blob_cap + 4;
      if (iVar4 < iVar5) {
        arg_x = flag;
        iVar5 = iVar4;
      }
      else {
        arg_x = *(char **)((int)blob_begin + blob_cap);
      }
      iVar6 = iVar4;
      data_ptr = flag;
      if (iVar5 + 4 <= iVar4) {
        iVar6 = iVar5 + 4;
        data_ptr = *(char **)((int)blob_begin + iVar5);
      }
      pcVar8 = flag;
      blob_cap = iVar4;
      if (iVar6 + 4 <= iVar4) {
        pcVar8 = *(char **)((int)blob_begin + iVar6);
        blob_cap = iVar6 + 4;
      }
      voxel_buf = (char *)0x0;
      local_2c = 0;
      local_28 = 0;
      vec3b_resize(&voxel_buf,(int)pcVar8 * (int)data_ptr * (int)arg_x);
      pcVar1 = voxel_buf;
      blob_src = (void *)(((local_2c - (int)voxel_buf) / 3) * 3);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar5 = blob_end - (int)blob_begin;
      if (blob_cap + (int)blob_src <= blob_end - (int)blob_begin) {
        memcpy(voxel_buf,(void *)((int)blob_begin + blob_cap),(size_t)blob_src);
        iVar5 = blob_cap + (int)blob_src;
      }
      blob_cap = iVar5;
      World_buildVoxelMesh(local_24,arg_x,data_ptr,(int)pcVar8,pcVar1,(char)flag);
      if (pcVar1 != (char *)0x0) {
        operator_delete(pcVar1);
      }
    }
    if (blob_begin != (void *)0x0) {
      operator_delete(blob_begin);
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: vec3b_resize  (confidence: high)
 * purpose: Resizes vector<3byte> to arg_x elements (shrink erases, grow via 42f330); std::vector::resize; World
 * vars: stride 3
 */
/* Global::vec3b_resize @ 0042ff40 */

undefined1 * __thiscall vec3b_resize(void *this,uint new_size)

{
  undefined1 *target_ptr;
  undefined1 *begin_ptr;
  uint cur_count;
  undefined1 *end_ptr;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d360;
  local_10 = ExceptionList;
  end_ptr = *(undefined1 **)((int)this + 4);
  cur_count = ((int)end_ptr - *(int *)this) / 3;
  if (new_size < cur_count) {
    begin_ptr = *(undefined1 **)this;
    target_ptr = begin_ptr + new_size * 3;
    if (target_ptr == begin_ptr) {
      *(undefined1 **)((int)this + 4) = begin_ptr;
      return target_ptr;
    }
    if (target_ptr == end_ptr) {
      return target_ptr;
    }
    ExceptionList = &local_10;
    end_ptr = (undefined1 *)vec3b_copyBackward(end_ptr,end_ptr,target_ptr);
  }
  else {
    if (new_size <= cur_count) {
      return (undefined1 *)(((int)end_ptr - *(int *)this) * 0x55555556);
    }
    ExceptionList = &local_10;
    vec3b_reserveGrow(this,new_size - cur_count);
    local_8 = 0;
    noop_return();
    end_ptr = (undefined1 *)
             (*(int *)((int)this + 4) + (new_size - (*(int *)((int)this + 4) - *(int *)this) / 3) * 3
             );
  }
  *(undefined1 **)((int)this + 4) = end_ptr;
  ExceptionList = local_10;
  return end_ptr;
}




/* [AUDIT] proposed: World_buildVoxelMesh  (confidence: med)
 * purpose: Copies voxel RGB blob to buffer, then per-voxel scans 3 marker colors collecting Vec3i positions into 3 vectors (42feb0)
 * vars: this+0x44/48/4c dims; +0x30 blob; markers FF0000/00FF00/0000FF
 */
/* Global::World_buildVoxelMesh @ 00430230 */

void __thiscall
World_buildVoxelMesh(void *this,undefined4 size_x,undefined4 size_y,int size_z,void *voxel_data,char skip_faces
            )

{
  longlong lVar1;
  void *_Dst;
  undefined2 *puVar2;
  int chan;
  int x;
  int z;
  int y;
  char color_y [4];
  char color_x [4];
  char color_z [4];
  undefined2 cur_color;
  undefined1 local_2e;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)((int)this + 0x44) = size_x;
  *(undefined4 *)((int)this + 0x48) = size_y;
  *(int *)((int)this + 0x4c) = size_z;
  if (*(void **)((int)this + 0x30) != (void *)0x0) {
    operator_delete__(*(void **)((int)this + 0x30));
    *(undefined4 *)((int)this + 0x30) = 0;
  }
  if (((0 < *(int *)((int)this + 0x44)) && (0 < *(int *)((int)this + 0x48))) &&
     (0 < *(int *)((int)this + 0x4c))) {
    lVar1 = (ulonglong)(uint)(*(int *)((int)this + 0x48) * *(int *)((int)this + 0x44) * size_z) * 3
    ;
    _Dst = (void *)operator_new_wrapper(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(void **)((int)this + 0x30) = _Dst;
    memcpy(_Dst,voxel_data,
           *(int *)((int)this + 0x48) * *(int *)((int)this + 0x4c) * *(int *)((int)this + 0x44) * 3)
    ;
  }
  *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 4);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 0x10);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x1c);
  if ((skip_faces == '\0') && (x = 0, 0 < *(int *)((int)this + 0x44))) {
    do {
      y = 0;
      if (0 < *(int *)((int)this + 0x48)) {
        do {
          z = 0;
          if (0 < *(int *)((int)this + 0x4c)) {
            color_x[0] = -1;
            color_x[1] = '\0';
            color_x[2] = 0;
            color_y[0] = '\0';
            color_y[1] = -1;
            color_y[2] = 0;
            color_z[0] = '\0';
            color_z[1] = '\0';
            color_z[2] = 0xff;
            do {
              if (((x < 0) || (y < 0)) ||
                 ((z < 0 ||
                  (((*(int *)((int)this + 0x44) <= x || (*(int *)((int)this + 0x48) <= y))
                   || (*(int *)((int)this + 0x4c) <= z)))))) {
                puVar2 = (undefined2 *)&DAT_00583dfc;
              }
              else {
                puVar2 = (undefined2 *)
                         (((*(int *)((int)this + 0x48) * z + y) * *(int *)((int)this + 0x44)
                          + x) * 3 + *(int *)((int)this + 0x30));
              }
              cur_color = *puVar2;
              local_2e = *(undefined1 *)(puVar2 + 1);
              chan = 0;
              do {
                if (*(char *)((int)&cur_color + chan) != color_x[chan]) goto LAB_004303a5;
                chan = chan + 1;
              } while (chan < 3);
              local_20 = x;
              local_1c = y;
              local_18 = z;
              World_vec3i_pushBack((void *)((int)this + 4),&local_20);
LAB_004303a5:
              chan = 0;
              do {
                if (*(char *)((int)&cur_color + chan) != color_y[chan]) goto LAB_004303d5;
                chan = chan + 1;
              } while (chan < 3);
              local_2c = x;
              local_28 = y;
              local_24 = z;
              World_vec3i_pushBack((undefined4 *)((int)this + 0x10),&local_2c);
LAB_004303d5:
              chan = 0;
              do {
                if (*(char *)((int)&cur_color + chan) != color_z[chan]) goto LAB_00430405;
                chan = chan + 1;
              } while (chan < 3);
              local_14 = x;
              local_10 = y;
              local_c = z;
              World_vec3i_pushBack((void *)((int)this + 0x1c),&local_14);
LAB_00430405:
              z = z + 1;
            } while (z < *(int *)((int)this + 0x4c));
          }
          y = y + 1;
        } while (y < *(int *)((int)this + 0x48));
      }
      x = x + 1;
    } while (x < *(int *)((int)this + 0x44));
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: noop_return  (confidence: high)
 * purpose: Empty function; likely alignment/relocation stub; misattributed World
 * vars: -
 */
/* Global::noop_return @ 0046b250 */

void noop_return(void)

{
  return;
}




/* [AUDIT] proposed: identity_return  (confidence: high)
 * purpose: Return the argument unchanged (thunk)
 * vars: -
 */
/* Global::identity_return @ 004c8120 */

undefined4 __cdecl identity_return(undefined4 value)

{
  return value;
}




/* cube::World::ctor_1 @ 004c8570 */

void __thiscall cube::World::ctor_1(World *this,undefined4 owner_arg,World param_2)

{
  World *pWVar1;
  bool bVar2;
  undefined4 member_str;
  void *pvVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *pbVar8;
  float *pfVar9;
  float fVar10;
  int iVar11;
  World *pWVar12;
  World *pWVar13;
  int iVar14;
  float10 fVar15;
  wchar_t *pwVar16;
  undefined4 local_138 [2];
  undefined4 local_130 [2];
  undefined4 local_128 [2];
  undefined4 local_120 [2];
  undefined4 local_118 [2];
  undefined4 local_110 [2];
  undefined4 local_108 [2];
  undefined4 local_100 [2];
  undefined4 local_f8 [2];
  undefined4 local_f0 [2];
  int local_e8 [2];
  int local_e0 [2];
  World *self;
  int local_d4 [2];
  int local_cc [2];
  int local_c4 [2];
  int local_bc [2];
  int local_b4 [2];
  int local_ac [2];
  int local_a4 [2];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  World *local_84;
  World *local_80;
  World *local_7c;
  World *local_78;
  World *local_74;
  World *local_70;
  World *self_ptr;
  undefined4 owner;
  int local_64 [2];
  World *local_5c;
  World *local_58;
  World *local_54;
  int local_50 [2];
  World *local_48;
  undefined4 local_44;
  World *local_40;
  int local_3c;
  int local_38;
  int local_34;
  World *race_index;
  void *temp_str [3];
  undefined1 local_20 [4];
  undefined4 local_1c;
  uint local_18;
  uint security_cookie;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554740;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  owner = owner_arg;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  self = this;
  self_ptr = this;
  member_str = List_allocSentinel0x20();
  *(undefined4 *)(this + 4) = member_str;
  local_8 = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  member_str = List_allocSentinel0x20();
  *(undefined4 *)(this + 0xc) = member_str;
  local_8._0_1_ = 1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  member_str = buyNode120((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x14) = member_str;
  local_8._0_1_ = 2;
  SpriteManager::ctor_0((SpriteManager *)(this + 0x1c),owner_arg);
  local_8._0_1_ = 3;
  Speech::ctor_0((undefined4 *)(this + 0x30));
  local_70 = this + 0x88;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)local_70 = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0xa8) = 0xf;
  *(undefined4 *)(this + 0xa4) = 0;
  this[0x94] = (World)0x0;
  local_8._0_1_ = 6;
  Database::ctor_1((undefined4 *)(this + 0xac));
  this[0xb4] = param_2;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0x8000bc) = 0;
  pWVar12 = this + 0x800104;
  local_8._0_1_ = 7;
  *(undefined4 *)pWVar12 = 0;
  *(undefined4 *)(this + 0x800108) = 0;
  local_40 = pWVar12;
  member_str = std_map_makeHeader_0x2c();
  pWVar1 = self_ptr;
  *(undefined4 *)pWVar12 = member_str;
  local_8._0_1_ = 8;
  local_7c = self_ptr + 0x80010c;
  *(undefined4 *)local_7c = 0;
  *(undefined4 *)(self_ptr + 0x800110) = 0;
  member_str = std_map_makeHeader_0x2c();
  *(undefined4 *)(pWVar1 + 0x80010c) = member_str;
  local_5c = pWVar1 + 0x800114;
  local_8._0_1_ = 9;
  *(undefined4 *)local_5c = 0;
  *(undefined4 *)(pWVar1 + 0x800118) = 0;
  member_str = std_map_makeHeader_0x2c();
  *(undefined4 *)(pWVar1 + 0x800114) = member_str;
  local_58 = pWVar1 + 0x80011c;
  local_8._0_1_ = 10;
  *(undefined4 *)local_58 = 0;
  *(undefined4 *)(pWVar1 + 0x800120) = 0;
  member_str = std_map_makeHeader_0x2c();
  *(undefined4 *)(pWVar1 + 0x80011c) = member_str;
  pWVar13 = pWVar1 + 0x800124;
  local_8._0_1_ = 0xb;
  *(undefined4 *)pWVar13 = 0;
  *(undefined4 *)(pWVar1 + 0x800128) = 0;
  local_84 = pWVar13;
  member_str = std_Tree_ctor_sentinel();
  *(undefined4 *)pWVar13 = member_str;
  local_80 = self_ptr + 0x80012c;
  local_8._0_1_ = 0xc;
  *(undefined4 *)local_80 = 0;
  *(undefined4 *)(self_ptr + 0x800130) = 0;
  member_str = std_Tree_ctor_sentinel();
  *(undefined4 *)local_80 = member_str;
  local_48 = self_ptr + 0x800134;
  local_8._0_1_ = 0xd;
  *(undefined4 *)local_48 = 0;
  *(undefined4 *)(self_ptr + 0x800138) = 0;
  member_str = std_Tree_ctor_sentinel();
  *(undefined4 *)local_48 = member_str;
  local_78 = self_ptr + 0x80013c;
  local_8._0_1_ = 0xe;
  *(undefined4 *)local_78 = 0;
  *(undefined4 *)(self_ptr + 0x800140) = 0;
  member_str = std_map_makeHeader_0x2c();
  *(undefined4 *)local_78 = member_str;
  local_74 = self_ptr + 0x800144;
  local_8._0_1_ = 0xf;
  *(undefined4 *)local_74 = 0;
  *(undefined4 *)(self_ptr + 0x800148) = 0;
  member_str = std_map_makeHeader_0x2c();
  *(undefined4 *)local_74 = member_str;
  local_54 = self_ptr + 0x80014c;
  local_8._0_1_ = 0x10;
  *(undefined4 *)local_54 = 0;
  *(undefined4 *)(self_ptr + 0x800150) = 0;
  member_str = std_Tree_ctor_sentinel();
  *(undefined4 *)local_54 = member_str;
  race_index = self_ptr + 0x800154;
  local_8._0_1_ = 0x11;
  *(undefined4 *)race_index = 0;
  *(undefined4 *)(self_ptr + 0x800158) = 0;
  member_str = List_allocSentinel0x18();
  *(undefined4 *)race_index = member_str;
  local_8._0_1_ = 0x12;
  *(undefined4 *)(self_ptr + 0x80015c) = 43200000;
  *(undefined4 *)(self_ptr + 0x800160) = 0;
  local_18 = 0xf;
  local_1c = 0;
  temp_str[0] = (void *)((uint)temp_str[0] & 0xffffff00);
  String_assign(temp_str,(int *)&DAT_0055b524,0);
  local_8._0_1_ = 0x13;
  std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_5
            ((basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *)self_ptr,0x7b,
             (int *)temp_str);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  if (0xf < local_18) {
    operator_delete(temp_str[0]);
  }
  race_index = (World *)0x0;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"ElfMale",7);
  race_index = (World *)0x1;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"ElfFemale",9);
  race_index = (World *)0x2;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"HumanMale",9);
  race_index = (World *)0x3;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"HumanFemale",0xb);
  race_index = (World *)0x4;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"GoblinMale",10);
  race_index = (World *)0x5;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"GoblinFemale",0xc);
  race_index = (World *)0x6;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Bullterrier",0xb);
  race_index = (World *)0x7;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"LizardmanMale",0xd);
  race_index = (World *)0x8;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"LizardmanFemale",0xf);
  race_index = (World *)0xd;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"FrogmanMale",0xb);
  race_index = (World *)0xe;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"FrogmanFemale",0xd);
  race_index = (World *)0x60;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Zombie",6);
  race_index = (World *)0x2c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Bandit",6);
  race_index = (World *)0x12;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"OldMan",6);
  race_index = (World *)0x2b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Wizard",6);
  race_index = (World *)0x6c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Troll",5);
  race_index = (World *)0x6e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"HellDemon",9);
  race_index = (World *)0x6f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Golem",5);
  race_index = (World *)0x70;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"EmberGolem",10);
  race_index = (World *)0x71;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SnowGolem",9);
  race_index = (World *)0x5e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Werewolf",8);
  race_index = (World *)0x6d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"DarkTroll",9);
  race_index = (World *)0x72;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Yeti",4);
  race_index = (World *)0x2e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Ogre",4);
  race_index = (World *)0x2f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Rockling",8);
  race_index = (World *)0x61;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Vampire",7);
  race_index = (World *)0x56;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Spitter",7);
  race_index = (World *)0x4c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SpikeCreature",0xd);
  race_index = (World *)0x4d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Anubis",6);
  race_index = (World *)0x4e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Horus",5);
  race_index = (World *)0x4f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Jester",6);
  race_index = (World *)0x50;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Spectrino",9);
  race_index = (World *)0x51;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Djinn",5);
  race_index = (World *)0x52;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Minotaur",8);
  race_index = (World *)0x55;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_005719c4,3);
  race_index = (World *)0x65;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Dragon",6);
  race_index = (World *)0x75;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Lich",4);
  race_index = (World *)0x9;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"DwarfMale",9);
  race_index = (World *)0xa;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"DwarfFemale",0xb);
  race_index = (World *)0x35;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Hornet",6);
  race_index = (World *)0x36;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"InsectGuard",0xb);
  race_index = (World *)0x7f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Ginseng",7);
  race_index = (World *)0x3c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00571a4c,3);
  race_index = (World *)0x3d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Midge",5);
  race_index = (World *)0x3e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Mosquito",8);
  race_index = (World *)0x39;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Seagull",7);
  race_index = (World *)0x46;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"RadishCreature",0xe);
  race_index = (World *)0x45;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"PlantCreature",0xd);
  race_index = (World *)0x47;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Onionling",9);
  race_index = (World *)0x48;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"DesertOnionling",0xf);
  race_index = (World *)0x49;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Devourer",8);
  race_index = (World *)0x6a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Crab",4);
  race_index = (World *)0x6b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SeaCrab",7);
  race_index = (World *)0x66;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"BarkBeetle",10);
  race_index = (World *)0x67;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"FireBeetle",10);
  race_index = (World *)0x68;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SnoutBeetle",0xb);
  race_index = (World *)0x69;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"LemonBeetle",0xb);
  race_index = (World *)0x92;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"LemonFish",9);
  race_index = (World *)0x91;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SapphireFish",0xc);
  race_index = (World *)0x96;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Shark",5);
  race_index = (World *)0x98;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"LanternFish",0xb);
  race_index = (World *)0x99;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"MawFish",7);
  race_index = (World *)0x9a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Piranha",7);
  race_index = (World *)0x9b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Blowfish",8);
  race_index = (World *)0x93;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Seahorse",8);
  race_index = (World *)0x44;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Frog",4);
  race_index = (World *)0x57;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Mole",4);
  race_index = (World *)0x58;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Biter",5);
  race_index = (World *)0x5a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Squirrel",8);
  race_index = (World *)0x5b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Raccoon",7);
  race_index = (World *)0x4a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Duckbill",8);
  race_index = (World *)0x4b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Crocodile",9);
  race_index = (World *)0x5c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00571c90,3);
  race_index = (World *)0x5d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Penguin",7);
  race_index = (World *)0x37;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Crow",4);
  race_index = (World *)0x3a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Parrot",6);
  race_index = (World *)0x77;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Saurian",7);
  race_index = (World *)0x76;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"RuneGiant",9);
  race_index = (World *)0x73;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Cyclops",7);
  race_index = (World *)0x74;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Mammoth",7);
  race_index = (World *)0x2d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Witch",5);
  race_index = (World *)0x33;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Gnobold",7);
  race_index = (World *)0x34;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Insectoid",9);
  race_index = (World *)0x30;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Gnoll",5);
  race_index = (World *)0x31;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"PolarGnoll",10);
  race_index = (World *)0x94;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Mermaid",7);
  race_index = (World *)0x95;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Merman",6);
  race_index = (World *)0x3b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00571d7c,3);
  race_index = (World *)0xb;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"OrcMale",7);
  race_index = (World *)0xc;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"OrcFemale",9);
  race_index = (World *)0x25;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"GreenSlime",10);
  race_index = (World *)0x26;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"PinkSlime",9);
  race_index = (World *)0x27;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"YellowSlime",0xb);
  race_index = (World *)0x28;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"BlueSlime",9);
  race_index = (World *)0x29;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Frightener",10);
  race_index = (World *)0x2a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SandHorror",10);
  race_index = (World *)0x78;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Bush",4);
  race_index = (World *)0x79;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SnowBush",8);
  race_index = (World *)0x7a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SnowBerryBush",0xd);
  race_index = (World *)0x82;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"ThornTree",9);
  race_index = (World *)0x80;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Cactus",6);
  race_index = (World *)0x8e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Dummy",5);
  race_index = (World *)0x8d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00571e9c,3);
  race_index = (World *)0x7b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"CottonPlant",0xb);
  race_index = (World *)0x7c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Scrub",5);
  race_index = (World *)0x7d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"CobwebScrub",0xb);
  race_index = (World *)0x7e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"FireScrub",9);
  race_index = (World *)0x90;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Bomb",4);
  race_index = (World *)0xf;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"UndeadMale",10);
  race_index = (World *)0x10;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"UndeadFemale",0xc);
  race_index = (World *)0x11;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Skeleton",8);
  race_index = (World *)0x3f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"PlainRunner",0xb);
  race_index = (World *)0x40;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"LeafRunner",10);
  race_index = (World *)0x41;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SnowRunner",10);
  race_index = (World *)0x42;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"DesertRunner",0xc);
  race_index = (World *)0x43;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Peacock",7);
  race_index = (World *)0x23;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Bunny",5);
  race_index = (World *)0x24;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Porcupine",9);
  race_index = (World *)0x13;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Collie",6);
  race_index = (World *)0x14;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"ShepherdDog",0xb);
  race_index = (World *)0x16;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Alpaca",6);
  race_index = (World *)0x17;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"BrownAlpaca",0xb);
  race_index = (World *)0x15;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SkullBull",9);
  race_index = (World *)0x18;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00572040,3);
  race_index = (World *)0x19;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Turtle",6);
  race_index = (World *)0x1a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Terrier",7);
  race_index = (World *)0x1b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"ScottishTerrier",0xf);
  race_index = (World *)0x1d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Panther",7);
  race_index = (World *)0x1e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00572098,3);
  race_index = (World *)0x1f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"BrownCat",8);
  race_index = (World *)0x20;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"WhiteCat",8);
  race_index = (World *)0x1c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Wolf",4);
  race_index = (World *)0x21;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_005720d4,3);
  race_index = (World *)0x22;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Sheep",5);
  race_index = (World *)0x62;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Horse",5);
  race_index = (World *)0x64;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_005720f4,3);
  race_index = (World *)0x63;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Camel",5);
  race_index = (World *)0x32;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Monkey",6);
  race_index = (World *)0x38;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Chicken",7);
  race_index = (World *)0x3e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Mosquito",8);
  race_index = (World *)0x24;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Porcupine",9);
  race_index = (World *)0x8f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Vase",4);
  race_index = (World *)0x84;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"IronDeposit",0xb);
  race_index = (World *)0x83;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"GoldDeposit",0xb);
  race_index = (World *)0x87;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"EmeraldDeposit",0xe);
  race_index = (World *)0x88;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SapphireDeposit",0xf);
  race_index = (World *)0x89;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"RubyDeposit",0xb);
  race_index = (World *)0x8a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"DiamondDeposit",0xe);
  race_index = (World *)0x85;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SilverDeposit",0xd);
  race_index = (World *)0x86;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"SandstoneDeposit",0x10);
  race_index = (World *)0x8b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"IceCrystalDeposit",0x11);
  race_index = (World *)0x8c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Scarecrow",9);
  race_index = (World *)0x53;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"NomadMale",9);
  race_index = (World *)0x54;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"NomadFemale",0xb);
  race_index = (World *)0x97;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Bumblebee",9);
  race_index = (World *)0x59;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar12,(int *)&race_index);
  U16String_assignPtrCount(pvVar4,(int *)L"Koala",5);
  pWVar1 = local_48;
  local_3c = 6;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(local_48,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Boots",5);
  local_3c = 5;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Gloves",6);
  local_3c = 4;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"ChestArmor",10);
  local_3c = 7;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"ShoulderArmor",0xd);
  local_3c = 0x13;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_005722f0,3);
  local_3c = 8;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Amulet",6);
  local_3c = 9;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Ring",4);
  local_3c = 2;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Formula",7);
  local_3c = 3;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Sword",5);
  local_3c = 3;
  local_38 = 3;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Dagger",6);
  local_3c = 3;
  local_38 = 4;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Fist",4);
  local_3c = 3;
  local_38 = 2;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Mace",4);
  local_3c = 3;
  local_38 = 1;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00572358,3);
  local_3c = 3;
  local_38 = 6;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)&DAT_00572360,3);
  local_3c = 3;
  local_38 = 7;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Crossbow",8);
  local_3c = 3;
  local_38 = 8;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Boomerang",9);
  local_3c = 3;
  local_38 = 0xe;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Arrows",6);
  pwVar16 = L"Arrow";
  local_3c = 3;
  local_38 = 9;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Torch";
  local_3c = 3;
  local_38 = 0x14;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Staff";
  local_3c = 3;
  local_38 = 10;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Wand";
  local_3c = 3;
  local_38 = 0xb;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Bracelet";
  local_3c = 3;
  local_38 = 0xc;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Shield";
  local_3c = 3;
  local_38 = 0xd;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Greatsword";
  local_3c = 3;
  local_38 = 0xf;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Greataxe";
  local_3c = 3;
  local_38 = 0x10;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Greatmace";
  local_3c = 3;
  local_38 = 0x11;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Longsword";
  local_3c = 3;
  local_38 = 5;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Coin";
  local_3c = 0xc;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"PlatinumCoin";
  local_3c = 0xd;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Candle";
  local_3c = 0x12;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Candle";
  local_3c = 0x12;
  local_38 = 1;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"HangGlider";
  local_3c = 0x17;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Boat";
  local_3c = 0x17;
  local_38 = 1;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Lamp";
  local_3c = 0x18;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"ManaCube";
  local_3c = 0x19;
  local_38 = 0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  iVar14 = 0;
  local_3c = 0x14;
  do {
    local_38 = iVar14;
    pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
    U16String_assignPtrCount(pvVar4,(int *)L"Bait",4);
    iVar14 = iVar14 + 1;
  } while (iVar14 < 0x9c);
  local_3c = 0x14;
  local_38 = 0x28;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"BlueJelly",9);
  local_3c = 0x14;
  local_38 = 0x25;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"GreenJelly",10);
  local_3c = 0x14;
  local_38 = 0x26;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"PinkJelly",9);
  local_3c = 0x14;
  local_38 = 0x27;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"YellowJelly",0xb);
  local_3c = 0x14;
  local_38 = 0x23;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Carrot",6);
  local_3c = 0x14;
  local_38 = 0x21;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"PumpkinMash",0xb);
  local_3c = 0x14;
  local_38 = 0x1e;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Candy",5);
  local_3c = 0x14;
  local_38 = 0x5c;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Lollipop",8);
  local_3c = 0x14;
  local_38 = 0x5d;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Softice",7);
  local_3c = 0x14;
  local_38 = 0x57;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"ChocolateDonut",0xe);
  local_3c = 0x14;
  local_38 = 0x22;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"CottonCandy",0xb);
  local_3c = 0x14;
  local_38 = 0x35;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Popcorn",7);
  local_3c = 0x14;
  local_38 = 0x38;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"CerealBar",9);
  local_3c = 0x14;
  local_38 = 0x5a;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"StrawberryCake",0xe);
  local_3c = 0x14;
  local_38 = 0x5b;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"ChocolateCake",0xd);
  local_3c = 0x14;
  local_38 = 0x17;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"ChocolateCupcake",0x10);
  local_3c = 0x14;
  local_38 = 0x16;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"VanillaCupcake",0xe);
  local_3c = 0x14;
  local_38 = 0x32;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"BananaSplit",0xb);
  local_3c = 0x14;
  local_38 = 0x1b;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Croissant",9);
  local_3c = 0x14;
  local_38 = 0x66;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Bread",5);
  local_3c = 0x14;
  local_38 = 0x68;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"Lolly",5);
  local_3c = 0x14;
  local_38 = 0x69;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignPtrCount(pvVar4,(int *)L"LemonTart",9);
  race_index = (World *)0x14;
  local_44 = 0x43;
  piVar5 = (int *)identity_return(&race_index);
  local_34 = *piVar5;
  puVar6 = std_pair_ctor2(local_50,&local_34,&local_44);
  std_pair_copy_ctor(&local_3c,puVar6);
  std_pair_copy_ctor(local_64,&local_3c);
  pwVar16 = L"ChocolateCookie";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_64);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x13;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"BubbleGum";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x37;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"LicoriceCandy";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x19;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"CinnamonRole";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x4b;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"AppleRing";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x1a;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Waffle";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x56;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"WaterIce";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 99;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"DateCookie";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x62;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"CandiedApple";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x6a;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"StrawberryCocktail";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x3f;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"MilkChocolateBar";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x42;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"CaramelChocolateBar";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x40;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"MintChocolateBar";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x41;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"WhiteChocolateBar";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x4a;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"SugarCandy";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x24;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"BlackberryMarmelade";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x39;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"SaltedCaramel";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x3a;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"GingerTartlet";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x3b;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"MangoJuice";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x3c;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"FruitBasket";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x3d;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"MelonIceCream";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x3e;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"BloodOrangeJuice";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x58;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Pancakes";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x67;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Curry";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x97;
  local_44 = 0x14;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"BiscuitRole";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 1;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"LifePotion";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 2;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"CactusPotion";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 3;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"ManaPotion";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 4;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"GinsengSoup";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 5;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"SnowBerryMash";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 6;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"MushroomSpit";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 8;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"PineappleSlice";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 9;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"PumpkinMuffin";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Cookie";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 7;
  local_44 = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Bomb";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Nugget";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 1;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  piVar5 = (int *)&DAT_00572a60;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,piVar5);
  local_34 = 2;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Feather";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 3;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Horn";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 4;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Claw";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 5;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Fiber";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 7;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Hair";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 8;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Crystal";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 9;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Yarn";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 6;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Cobweb";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 10;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Cube";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0xb;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Capsule";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0xd;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  piVar5 = (int *)&DAT_00572af0;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,piVar5);
  local_34 = 0xc;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Flask";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0xe;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Spirit";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0xf;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Mushroom";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x13;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"ShimmerMushroom";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x14;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"GinsengRoot";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x10;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Pumpkin";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x11;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Pineapple";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x16;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Heartflower";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x17;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"PricklyPear";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x18;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"FrozenHeartflower";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x19;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Soulflower";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x12;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"RadishSlice";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x15;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"OnionSlice";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x1a;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"WaterFlask";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x1b;
  local_44 = 0xb;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"SnowBerry";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0;
  local_44 = 0xf;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Beak";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Amulet1";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 1;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Amulet2";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 2;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"JewelCase";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 3;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  piVar5 = (int *)&DAT_00572c8c;
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,piVar5);
  local_34 = 4;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Medicine";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 5;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Antivenom";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 6;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"BandAid";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 7;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Crutch";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 8;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Bandage";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 9;
  local_44 = 0x15;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Salve";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0;
  local_44 = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Leftovers";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0;
  local_44 = 0x10;
  puVar6 = (undefined4 *)std_pair_ctor_swap(local_50,&local_44,&local_34);
  std_pair_copy_ctor(&local_3c,puVar6);
  pwVar16 = L"Painting";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_3c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pWVar1 = local_7c;
  pwVar16 = L"Statue";
  local_34 = 0;
  pvVar4 = (void *)std_map_subscript_intKey(local_7c,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Door";
  local_34 = 1;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"BigDoor";
  local_34 = 2;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Window";
  local_34 = 3;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"CastleWindow";
  local_34 = 4;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Gate";
  local_34 = 5;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"FireTrap";
  local_34 = 6;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SpikeTrap";
  local_34 = 7;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"StompTrap";
  local_34 = 8;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Lever";
  local_34 = 9;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Chest";
  local_34 = 10;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Table";
  local_34 = 0xc;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Table";
  local_34 = 0xe;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Table";
  local_34 = 0xd;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Stool";
  local_34 = 0x10;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Stool";
  local_34 = 0xf;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Stool";
  local_34 = 0x11;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Bench";
  local_34 = 0x12;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  piVar5 = (int *)&DAT_00572dfc;
  local_34 = 0x13;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,piVar5);
  pwVar16 = L"BedTable";
  local_34 = 0x14;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"MarketStand1";
  local_34 = 0x15;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"MarketStand2";
  local_34 = 0x16;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"MarketStand3";
  local_34 = 0x17;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Barrel";
  local_34 = 0x18;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Crate";
  local_34 = 0x19;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"OpenCrate";
  local_34 = 0x1a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Sack";
  local_34 = 0x1b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Shelter";
  local_34 = 0x1c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Cupboard";
  local_34 = 0x1d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Desktop";
  local_34 = 0x1e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Counter";
  local_34 = 0x1f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Shelf1";
  local_34 = 0x20;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Shelf2";
  local_34 = 0x21;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Shelf3";
  local_34 = 0x22;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Corpse";
  local_34 = 0x2c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"RuneStone";
  local_34 = 0x2d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Artifact";
  local_34 = 0x2e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"FlowerBox1";
  local_34 = 0x2f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"FlowerBox2";
  local_34 = 0x30;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"FlowerBox3";
  local_34 = 0x31;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"StreetLight";
  local_34 = 0x32;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"FireStreetLight";
  local_34 = 0x33;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Fence1";
  local_34 = 0x34;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Fence2";
  local_34 = 0x35;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Fence3";
  local_34 = 0x36;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Fence4";
  local_34 = 0x37;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase1";
  local_34 = 0x38;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase2";
  local_34 = 0x39;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase3";
  local_34 = 0x3a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase4";
  local_34 = 0x3b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase5";
  local_34 = 0x3c;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase6";
  local_34 = 0x3d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase7";
  local_34 = 0x3e;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase8";
  local_34 = 0x3f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Vase9";
  local_34 = 0x40;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x41;
  pwVar16 = L"Campfire";
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Tent";
  local_34 = 0x42;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"BeachUmbrella";
  local_34 = 0x43;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"BeachTowel";
  local_34 = 0x44;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SleepingMat";
  local_34 = 0x45;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Furnace";
  local_34 = 0x47;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Anvil";
  local_34 = 0x48;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SpinningWheel";
  local_34 = 0x49;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"Loom";
  local_34 = 0x4a;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SawBench";
  local_34 = 0x4b;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_34 = 0x4c;
  pwVar16 = L"Workbench";
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"CustomizationBench";
  local_34 = 0x4d;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pWVar1 = local_5c;
  pwVar16 = L"SkillAbility1";
  local_34 = 6;
  pvVar4 = (void *)std_map_subscript_intKey(local_5c,&local_34);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillAbility2";
  local_5c = (World *)0x7;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillAbility3";
  local_5c = (World *)0x8;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillAbility4";
  local_5c = (World *)0x9;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillAbility5";
  local_5c = (World *)0xa;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillPetTaming";
  local_5c = (World *)0x0;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillPetRiding";
  local_5c = (World *)0x1;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillClimbing";
  local_5c = (World *)0x2;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_5c = (World *)0x3;
  pwVar16 = L"SkillHangGliding";
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillSwimming";
  local_5c = (World *)0x4;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"SkillBoatDriving";
  local_5c = (World *)0x5;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pWVar1 = local_58;
  pwVar16 = L"AbilitySmash";
  local_5c = (World *)0x36;
  pvVar4 = (void *)std_map_subscript_intKey(local_58,(int *)&local_5c);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityCyclone";
  local_58 = (World *)0x56;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityBulwark";
  local_58 = (World *)0x65;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityWarFrenzy";
  local_58 = (World *)0x66;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityRangerKick";
  local_58 = (World *)0x15;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityRetreat";
  local_58 = (World *)0x32;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityAim";
  local_58 = (World *)0x63;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_58 = (World *)0x64;
  pwVar16 = L"AbilitySwiftness";
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityFireExplosion";
  local_58 = (World *)0x58;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityManaShield";
  local_58 = (World *)0x67;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityTeleport";
  local_58 = (World *)0x31;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityHealingStream";
  local_58 = (World *)0x22;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityIntercept";
  local_58 = (World *)0x30;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityShuriken";
  local_58 = (World *)0x60;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilityCamouflage";
  local_58 = (World *)0x61;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pwVar16 = L"AbilitySneak";
  local_58 = (World *)0x4f;
  pvVar4 = (void *)std_map_subscript_intKey(pWVar1,(int *)&local_58);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pWVar12 = local_70;
  pWVar1 = local_84;
  race_index = (World *)0x0;
  local_58 = (World *)0x1;
  local_5c = (World *)0x2;
  local_34 = 3;
  local_44 = 4;
  local_90 = 6;
  local_98 = 0xb;
  local_8c = 0xc;
  local_94 = 7;
  local_9c = 8;
  local_64[1] = 0xd;
  local_38 = 0xf;
  do {
    pWVar13 = race_index;
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_138,&local_58,&race_index);
    std_pair_copy_ctor(&local_88,puVar6);
    pwVar16 = L"Village";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,&local_88);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_f0,&local_5c,&race_index);
    std_pair_copy_ctor(local_a4,puVar6);
    pwVar16 = L"Mountain";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_a4);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_100,&local_34,&race_index);
    std_pair_copy_ctor(local_b4,puVar6);
    pwVar16 = L"Forest";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_b4);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_120,&local_44,&race_index);
    std_pair_copy_ctor(local_e8,puVar6);
    pwVar16 = L"Lake";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_e8);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_110,&local_90,&race_index);
    std_pair_copy_ctor(local_d4,puVar6);
    pwVar16 = L"Canyon";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_d4);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_130,&local_98,&race_index);
    std_pair_copy_ctor(local_c4,puVar6);
    pwVar16 = L"Rock";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_c4);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_f8,&local_8c,&race_index);
    std_pair_copy_ctor(local_e0,puVar6);
    pwVar16 = L"Tree";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_e0);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_108,&local_94,&race_index);
    std_pair_copy_ctor(local_ac,puVar6);
    pwVar16 = L"Valley";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_ac);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_118,&local_9c,&race_index);
    std_pair_copy_ctor(local_bc,puVar6);
    pwVar16 = L"Crater";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_bc);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(local_128,local_64 + 1,&race_index);
    std_pair_copy_ctor(local_cc,puVar6);
    pwVar16 = L"Peak";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_cc);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,&local_38,&race_index);
    std_pair_copy_ctor(local_50,puVar6);
    pwVar16 = L"Island";
    pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
    U16String_assignFromCStr(pvVar4,(int *)pwVar16);
    race_index = pWVar13 + 1;
  } while ((int)race_index < 10);
  local_38 = 0;
  local_64[1] = 5;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Ruins";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 1;
  local_64[1] = 5;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Ruins";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 2;
  local_64[1] = 5;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Ruins";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 3;
  local_64[1] = 5;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Ruins";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 4;
  local_64[1] = 5;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Gravesite";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 0;
  local_64[1] = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Castle";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 1;
  local_64[1] = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Ruins";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 2;
  local_64[1] = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Catacombs";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 3;
  local_64[1] = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Palace";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 4;
  local_64[1] = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Temple";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 5;
  local_64[1] = 0xe;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Pyramid";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 0;
  local_64[1] = 9;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Cave";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 0;
  local_64[1] = 10;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Portal";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 1;
  local_64[1] = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pWVar1 = local_80;
  pwVar16 = L"Trade Quarter";
  pvVar4 = (void *)std_map_insert_pair(local_80,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 2;
  local_64[1] = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Crafting Quarter";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 3;
  local_64[1] = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Class Quarter";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 4;
  local_64[1] = 1;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Pet Quarter";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 0;
  local_64[1] = 4;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Portal";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  local_38 = 0;
  local_64[1] = 5;
  puVar6 = (undefined4 *)std_pair_ctor_swap(&local_1c,local_64 + 1,&local_38);
  std_pair_copy_ctor(local_50,puVar6);
  pwVar16 = L"Palace";
  pvVar4 = (void *)std_map_insert_pair(pWVar1,local_50);
  U16String_assignFromCStr(pvVar4,(int *)pwVar16);
  pWVar13 = local_40;
  deref_getFirst(local_40,&race_index);
  piVar5 = (int *)World_getField0(pWVar13,&local_40);
  bVar2 = std_iterator_notEqual(&race_index,piVar5);
  pWVar1 = local_78;
  if (bVar2) {
    do {
      puVar6 = (undefined4 *)getField_plus0x10((int *)&race_index);
      puVar7 = (undefined4 *)std_map_insert_str(pWVar1,(ushort *)(puVar6 + 1));
      *puVar7 = *puVar6;
      RBTree_copyBeginThenInc(&race_index,&local_38);
      piVar5 = (int *)World_getField0(pWVar13,&local_40);
      bVar2 = std_iterator_notEqual(&race_index,piVar5);
      pWVar12 = local_70;
    } while (bVar2);
  }
  pWVar1 = local_7c;
  deref_getFirst(local_7c,&race_index);
  piVar5 = (int *)World_getField0(pWVar1,&local_40);
  bVar2 = std_iterator_notEqual(&race_index,piVar5);
  pWVar13 = local_74;
  if (bVar2) {
    do {
      puVar6 = (undefined4 *)getField_plus0x10((int *)&race_index);
      puVar7 = (undefined4 *)std_map_insert_str(pWVar13,(ushort *)(puVar6 + 1));
      *puVar7 = *puVar6;
      RBTree_copyBeginThenInc(&race_index,&local_38);
      piVar5 = (int *)World_getField0(pWVar1,&local_40);
      bVar2 = std_iterator_notEqual(&race_index,piVar5);
      pWVar12 = local_70;
    } while (bVar2);
  }
  pWVar13 = local_48;
  deref_getFirst(local_48,&race_index);
  piVar5 = (int *)World_getField0(pWVar13,&local_40);
  bVar2 = std_iterator_notEqual(&race_index,piVar5);
  pWVar1 = local_54;
  if (bVar2) {
    do {
      puVar6 = (undefined4 *)getField_plus0x10((int *)&race_index);
      pvVar4 = (void *)std_map_insert_str2(pWVar1,(ushort *)(puVar6 + 2));
      std_pair_copy_ctor2(pvVar4,puVar6);
      RBTree_copyBeginThenInc(&race_index,&local_38);
      piVar5 = (int *)World_getField0(pWVar13,&local_40);
      bVar2 = std_iterator_notEqual(&race_index,piVar5);
      pWVar12 = local_70;
    } while (bVar2);
  }
  pWVar1 = self_ptr;
  iVar14 = 0x400;
  pbVar8 = (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *)
           (self_ptr + 0x4000bc);
  do {
    iVar11 = 0x400;
    do {
      *(undefined4 *)(pbVar8 + -0x400000) = 0;
      *(undefined4 *)pbVar8 = 0;
      pbVar8 = pbVar8 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(self_ptr + 0x8000c0),0x80000400);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(pWVar1 + 0x8000d8),0x80000400);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x14;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  pbVar8 = (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *)(pWVar1 + 0x800154)
  ;
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x0;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-floor-wood.cub");
  local_8._0_1_ = 0x15;
  local_40 = (World *)0x0;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x16;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x1;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-wall-window.cub");
  local_8._0_1_ = 0x17;
  local_40 = (World *)0x1;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x18;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x2;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-wall-door.cub");
  local_8._0_1_ = 0x19;
  local_40 = (World *)0x2;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x1a;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x3;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-roof1.cub");
  local_8._0_1_ = 0x1b;
  local_40 = (World *)0x3;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x1c;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x4;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-entrance.cub");
  local_8._0_1_ = 0x1d;
  local_40 = (World *)0x4;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x1e;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x5;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-wall.cub");
  local_8._0_1_ = 0x1f;
  local_40 = (World *)0x5;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x20;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x6;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-roof2.cub");
  local_8._0_1_ = 0x21;
  local_40 = (World *)0x6;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x22;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x7;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-roof3.cub");
  local_8._0_1_ = 0x23;
  local_40 = (World *)0x7;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x24;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x8;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-wall-balcony.cub");
  local_8._0_1_ = 0x25;
  local_40 = (World *)0x8;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x26;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0x9;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"framework-roof-wall2.cub");
  local_8._0_1_ = 0x27;
  local_40 = (World *)0x9;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x28;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0xa;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"building-stone-well.cub");
  local_8._0_1_ = 0x29;
  local_40 = (World *)0xa;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8._0_1_ = 0x12;
  String_destroy(temp_str);
  local_40 = operator_new(0x60);
  local_8._0_1_ = 0x2a;
  if (local_40 == (World *)0x0) {
    local_54 = (World *)0x0;
  }
  else {
    local_54 = (World *)Sprite::ctor_0((Sprite *)local_40,owner);
  }
  local_8._0_1_ = 0x12;
  local_40 = (World *)0xb;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  *piVar5 = (int)local_54;
  String_ctorFromCStr(temp_str,(int *)"building-stone-stairs2.cub");
  local_8._0_1_ = 0x2b;
  local_40 = (World *)0xb;
  piVar5 = std_map_operator_int(pbVar8,(int *)&local_40);
  World_loadVoxelModel((void *)*piVar5,(char *)temp_str,(void *)0x0,(char *)0x1);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  String_destroy(temp_str);
  puVar6 = Vec3_set(local_20,0x4b002080,0x4b002080,0x42c80000);
  Vec3_copy((basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *)
               (pWVar1 + 0x8000f0),puVar6);
  iVar14 = 0;
  pfVar9 = (float *)getElemPtr4((basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>
                                  *)(pWVar1 + 0x8000f0),1);
  fVar10 = (float)(int)*pfVar9;
  pfVar9 = (float *)getElemPtr4((basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>
                                  *)(pWVar1 + 0x8000f0),0);
  fVar15 = (float10)World_baseHeightField(pWVar1,(int)*pfVar9,fVar10,iVar14);
  local_40 = (World *)(float)fVar15;
  pfVar9 = (float *)getElemPtr4((basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>
                                  *)(pWVar1 + 0x8000f0),2);
  *pfVar9 = (float)local_40;
  puVar6 = pair_set2(&local_1c,0x8000,0x8000);
  std_pair_copy_ctor2((basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *)
               (pWVar1 + 0x8000fc),puVar6);
  *(undefined4 *)(pWVar1 + 0xb8) = 0;
  local_40 = (World *)0x23;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x57;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x3c;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x37;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x22;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x17;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x16;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x1e;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x21;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x62;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x19;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x35;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x43;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x66;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x68;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x69;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x13;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x28;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x25;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x26;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x27;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x5c;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x5d;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x38;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x5a;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x5b;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x32;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x1b;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x4b;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x1a;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x56;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x63;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x6a;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x3f;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x42;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x40;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x41;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x4a;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x24;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x39;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x3a;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x3b;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x3d;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x3e;
  std_vector_push_back_int(pWVar12,&local_40);
  local_40 = (World *)0x58;
  std_vector_push_back_int(pWVar12,&local_40);
  ExceptionList = local_10;
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::World::ctor_0 @ 004cd940 */

void __fastcall cube::World::ctor_0(undefined4 *self)

{
  undefined4 *this;
  _Container_base0 *this_00;
  char is_nil;
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *world;
  int *parent;
  uint security_cookie;
  int *node;
  int *cur_entry;
  int iVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this_01;
  void *outer_index;
  int inner_index;
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0055486b;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  pvVar9 = (void *)0x0;
  local_8 = 0x12;
  outer_index = (void *)0x0;
  cur_entry = self + 0x2f;
  inner_index = 0;
  local_14 = (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *)self;
  while( true ) {
    do {
      iVar8 = inner_index;
      if (*cur_entry != 0) {
        if (local_14[0xb4] ==
            (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>)0x0) {
          iVar7 = 0x10018;
          do {
            iVar10 = 0x40;
            do {
              std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_3
                        (local_14,*(int *)(*cur_entry + iVar7));
              iVar8 = inner_index;
              pvVar9 = outer_index;
              iVar7 = iVar7 + 4;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          } while (iVar7 < 0x14018);
          std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_0
                    (local_14,(int)outer_index,inner_index);
        }
        if ((undefined4 *)*cur_entry != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*cur_entry)(1,security_cookie);
        }
      }
      if ((void *)cur_entry[0x100000] != (void *)0x0) {
        operator_delete((void *)cur_entry[0x100000]);
      }
      world = local_14;
      inner_index = iVar8 + 1;
      cur_entry = cur_entry + 1;
    } while (inner_index < 0x400);
    pvVar9 = (void *)((int)pvVar9 + 1);
    outer_index = pvVar9;
    if (0x3ff < (int)pvVar9) break;
    inner_index = 0;
  }
  cur_entry = (int *)**(int **)(local_14 + 4);
  if (cur_entry != *(int **)(local_14 + 4)) {
    do {
      if ((undefined4 *)cur_entry[6] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)cur_entry[6])(1);
      }
      if (*(char *)((int)cur_entry + 0xd) == '\0') {
        node = (int *)cur_entry[2];
        if (*(char *)((int)node + 0xd) == '\0') {
          is_nil = *(char *)(*node + 0xd);
          cur_entry = node;
          node = (int *)*node;
          while (is_nil == '\0') {
            is_nil = *(char *)(*node + 0xd);
            cur_entry = node;
            node = (int *)*node;
          }
        }
        else {
          is_nil = *(char *)(cur_entry[1] + 0xd);
          parent = (int *)cur_entry[1];
          node = cur_entry;
          while ((cur_entry = parent, is_nil == '\0' && (node == (int *)cur_entry[2]))) {
            is_nil = *(char *)(cur_entry[1] + 0xd);
            parent = (int *)cur_entry[1];
            node = cur_entry;
          }
        }
      }
    } while (cur_entry != *(int **)(world + 4));
  }
  cur_entry = (int *)**(int **)(world + 0xc);
  if (cur_entry != *(int **)(world + 0xc)) {
    do {
      outer_index = (void *)cur_entry[6];
      if (outer_index != (void *)0x0) {
        this = (undefined4 *)((int)outer_index + 0x78);
        std_map_erase_range_B(this,&inner_index,*(int **)*this,(int *)*this);
        operator_delete((void *)*this);
        operator_delete(outer_index);
      }
      if (*(char *)((int)cur_entry + 0xd) == '\0') {
        node = (int *)cur_entry[2];
        if (*(char *)((int)node + 0xd) == '\0') {
          is_nil = *(char *)(*node + 0xd);
          cur_entry = node;
          node = (int *)*node;
          while (is_nil == '\0') {
            is_nil = *(char *)(*node + 0xd);
            cur_entry = node;
            node = (int *)*node;
          }
        }
        else {
          is_nil = *(char *)(cur_entry[1] + 0xd);
          parent = (int *)cur_entry[1];
          node = cur_entry;
          while ((cur_entry = parent, is_nil == '\0' && (node == (int *)cur_entry[2]))) {
            is_nil = *(char *)(cur_entry[1] + 0xd);
            parent = (int *)cur_entry[1];
            node = cur_entry;
          }
        }
      }
    } while (cur_entry != *(int **)(world + 0xc));
  }
  this_01 = world + 0xc;
  DeleteCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
  DeleteCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
  local_8._0_1_ = 0x11;
  std_map_erase_range_B(world + 0x800154,&outer_index,(int *)**(int **)(world + 0x800154),
               *(int **)(world + 0x800154));
  operator_delete(*(void **)(world + 0x800154));
  local_8._0_1_ = 0x10;
  Tree_eraseRange_variant(world + 0x80014c,&outer_index,(int *)**(int **)(world + 0x80014c),
               *(int **)(world + 0x80014c));
  operator_delete(*(void **)(world + 0x80014c));
  local_8._0_1_ = 0xf;
  Tree_eraseRange_variant(world + 0x800144,&outer_index,(int *)**(int **)(world + 0x800144),
               *(int **)(world + 0x800144));
  operator_delete(*(void **)(world + 0x800144));
  local_8._0_1_ = 0xe;
  Tree_eraseRange_variant(world + 0x80013c,&outer_index,(int *)**(int **)(world + 0x80013c),
               *(int **)(world + 0x80013c));
  operator_delete(*(void **)(world + 0x80013c));
  local_8._0_1_ = 0xd;
  std_map_erase_range(world + 0x800134,&outer_index,(int *)**(int **)(world + 0x800134),
               *(int **)(world + 0x800134));
  operator_delete(*(void **)(world + 0x800134));
  local_8._0_1_ = 0xc;
  std_map_erase_range(world + 0x80012c,&outer_index,(int *)**(int **)(world + 0x80012c),
               *(int **)(world + 0x80012c));
  operator_delete(*(void **)(world + 0x80012c));
  local_8._0_1_ = 0xb;
  std_map_erase_range(world + 0x800124,&outer_index,(int *)**(int **)(world + 0x800124),
               *(int **)(world + 0x800124));
  operator_delete(*(void **)(world + 0x800124));
  local_8._0_1_ = 10;
  std_map_eraseRange_strNode(world + 0x80011c,&outer_index,(int *)**(int **)(world + 0x80011c),
               *(int **)(world + 0x80011c));
  operator_delete(*(void **)(world + 0x80011c));
  local_8._0_1_ = 9;
  std_map_eraseRange_strNode(world + 0x800114,&outer_index,(int *)**(int **)(world + 0x800114),
               *(int **)(world + 0x800114));
  operator_delete(*(void **)(world + 0x800114));
  local_8._0_1_ = 8;
  std_map_eraseRange_strNode(world + 0x80010c,&outer_index,(int *)**(int **)(world + 0x80010c),
               *(int **)(world + 0x80010c));
  operator_delete(*(void **)(world + 0x80010c));
  local_8._0_1_ = 7;
  std_map_eraseRange_strNode(world + 0x800104,&outer_index,(int *)**(int **)(world + 0x800104),
               *(int **)(world + 0x800104));
  operator_delete(*(void **)(world + 0x800104));
  local_8 = CONCAT31(local_8._1_3_,6);
  Database::ctor_0((undefined4 *)(world + 0xac));
  if (0xf < *(uint *)(world + 0xa8)) {
    operator_delete(*(void **)(world + 0x94));
  }
  *(undefined4 *)(world + 0xa8) = 0xf;
  *(undefined4 *)(world + 0xa4) = 0;
  this_00 = (_Container_base0 *)(world + 0x88);
  world[0x94] = (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  local_8._0_1_ = 4;
  if (*(int *)this_00 != 0) {
    std::_Container_base0::_Orphan_all(this_00);
    operator_delete(*(void **)this_00);
    *(undefined4 *)this_00 = 0;
    *(undefined4 *)(world + 0x8c) = 0;
    *(undefined4 *)(world + 0x90) = 0;
  }
  local_8._0_1_ = 3;
  Speech::ctor_1((undefined4 *)(world + 0x30));
  local_8 = CONCAT31(local_8._1_3_,2);
  SpriteManager::ctor_1((undefined4 *)(world + 0x1c));
  cur_entry = *(int **)(world + 0x14);
  node = (int *)*cur_entry;
  *cur_entry = (int)cur_entry;
  *(int *)(*(int *)(world + 0x14) + 4) = *(int *)(world + 0x14);
  *(undefined4 *)(world + 0x18) = 0;
  if (node != *(int **)(world + 0x14)) {
    do {
      cur_entry = (int *)*node;
      operator_delete(node);
      node = cur_entry;
    } while (cur_entry != (int *)*(int *)(world + 0x14));
  }
  operator_delete(*(void **)(world + 0x14));
  local_8 = local_8 & 0xffffff00;
  std_map_erase_range_B(this_01,&outer_index,(int *)**(int **)this_01,*(int **)this_01);
  operator_delete(*(void **)this_01);
  local_8 = 0xffffffff;
  std_map_erase_range_B(world + 4,&outer_index,(int *)**(int **)(world + 4),*(int **)(world + 4));
  operator_delete(*(void **)(world + 4));
  ExceptionList = local_10;
  return;
}




/* cube::World::vfunc_0 @ 004ce540 */

undefined4 * __thiscall cube::World::vfunc_0(World *this,byte delete_flag)

{
  ctor_0((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




/* [AUDIT] proposed: World_roadField  (confidence: med)
 * purpose: Samples terrain/noise value at world coords via chunk lookup; returns 0 if chunk type!=1
 * vars: param_2/3=fixed-point coords >>0xb=chunk idx; chunk[6]=type; World_falloffSquared=falloff
 */
/* Global::World_roadField @ 004d19f0 */

float10 __thiscall World_roadField(void *world,uint x,uint y)

{
  uint *chunk;
  float10 result;
  uint x_lo;
  uint x_hi;
  uint y_lo;
  uint y_hi;
  
  chunk = (uint *)World_getTileAtCoords(world,(int)(x + ((int)x >> 0x1f & 0x7ffU)) >> 0xb,
                                (int)(y + ((int)y >> 0x1f & 0x7ffU)) >> 0xb);
  if ((chunk != (uint *)0x0) && (chunk[6] == 1)) {
    y_hi = ((int)y >> 0x1f) << 0x10 | y >> 0x10;
    y_lo = y << 0x10;
    x_hi = ((int)x >> 0x1f) << 0x10 | x >> 0x10;
    x_lo = x << 0x10;
    result = World_falloffSquared(chunk,&x_lo,&y_lo);
    return result;
  }
  return (float10)0;
}




/* [AUDIT] proposed: valueNoise2D  (confidence: high)
 * purpose: 2D value/gradient noise with cosine interpolation and integer hash mixing; core terrain noise fn
 * vars: world:2=x (double via CONCAT), y=y; 0x39 hash mult; cos smoothstep
 */
/* Global::valueNoise2D @ 004d5d30 */

float10 __cdecl valueNoise2D(undefined4 param_1,undefined4 param_2,double y)

{
  int iVar1;
  uint hash10;
  uint hash11;
  uint hash00;
  uint hash01;
  double frac_x;
  double cos_x;
  double y_floor;
  
  y_floor = (double)(int)y;
  frac_x = (double)(int)(double)CONCAT44(param_2,param_1);
  iVar1 = (int)y_floor * 0x39;
  hash00 = (int)frac_x + iVar1;
  hash10 = iVar1 + (int)(frac_x + 1.0);
  hash00 = hash00 ^ hash00 * 0x2000;
  hash10 = hash10 ^ hash10 * 0x2000;
  cos_x = ((double)CONCAT44(param_2,param_1) - frac_x) * 3.1415927;
  iVar1 = (int)(y_floor + 1.0) * 0x39;
  hash01 = (int)frac_x + iVar1;
  hash11 = iVar1 + (int)(frac_x + 1.0);
  hash01 = hash01 ^ hash01 * 0x2000;
  hash11 = hash11 ^ hash11 * 0x2000;
  libm_sse2_cos_precise();
  frac_x = (1.0 - cos_x) * 0.5;
  cos_x = (y - (double)(int)y) * 3.1415927;
  libm_sse2_cos_precise();
  cos_x = (1.0 - cos_x) * 0.5;
  return (float10)(float)(((1.0 - (double)((hash00 * hash00 * 0xec4d + 0x131071f) * hash00 + 0xd208dd0d
                                          & 0x7fffffff) * 9.313225746154785e-10) * (1.0 - frac_x) +
                          (1.0 - (double)((hash10 * hash10 * 0xec4d + 0x131071f) * hash10 + 0xd208dd0d
                                         & 0x7fffffff) * 9.313225746154785e-10) * frac_x) *
                          (1.0 - cos_x) +
                         ((1.0 - (double)((hash01 * hash01 * 0xec4d + 0x131071f) * hash01 + 0xd208dd0d
                                         & 0x7fffffff) * 9.313225746154785e-10) * (1.0 - frac_x) +
                         (1.0 - (double)((hash11 * hash11 * 0xec4d + 0x131071f) * hash11 + 0xd208dd0d &
                                        0x7fffffff) * 9.313225746154785e-10) * frac_x) * cos_x);
}




/* [AUDIT] proposed: World_featureTier  (confidence: high)
 * purpose: Feature tier from distance-from-spawn-region (sqrt from map center 0x200)
 * vars: 
 */
/* Global::World_featureTier @ 004d7870 */

int World_featureTier(int param_1,int param_2)

{
  double dVar1;
  
  if ((param_1 == 0x200) && (param_2 == 0x200)) {
    return 1;
  }
  dVar1 = (double)((float)(0x200 - param_2) * (float)(0x200 - param_2) +
                  (float)(0x200 - param_1) * (float)(0x200 - param_1));
  libm_sse2_sqrt_precise();
  return 2 - (int)((float)dVar1 * -0.75);
}




/* Global::FUN_004d8f70 @ 004d8f70 */

void * __thiscall FUN_004d8f70(void *this,void *param_1)

{
  FUN_004d8e60((void *)((int)this + 0x18),param_1);
  return param_1;
}




/* Global::FUN_004e25e0 @ 004e25e0 */

void __thiscall FUN_004e25e0(void *this,uint param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554fc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)0x0;
  if (param_1 != 0) {
    if (param_1 < 0x20000000) {
      puVar3 = operator_new(param_1 * 8);
      if (puVar3 != (undefined4 *)0x0) goto LAB_004e2640;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_004e2640:
  local_8 = 0;
  FUN_004e1e50(*(undefined4 **)this,*(undefined4 **)((int)this + 4),puVar3);
  pvVar1 = *(void **)this;
  iVar2 = *(int *)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  *(undefined4 **)((int)this + 8) = puVar3 + param_1 * 2;
  *(undefined4 **)this = puVar3;
  *(undefined4 **)((int)this + 4) = puVar3 + (iVar2 - (int)pvVar1 >> 3) * 2;
  ExceptionList = local_10;
  return;
}




/* Global::FUN_004f5cc0 @ 004f5cc0 */

void __cdecl FUN_004f5cc0(float *param_1,float *param_2,int param_3,undefined4 param_4)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  undefined4 local_c [2];
  
  iVar3 = (int)param_2 - (int)param_1;
  do {
    iVar3 = iVar3 / 0xc;
    if (iVar3 < 0x21) {
LAB_004f5d98:
      if (1 < iVar3) {
        FUN_004f4860(param_1,param_2);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar3) {
        if (1 < ((int)param_2 - (int)param_1) / 0xc) {
          FUN_004f4b50((int)param_1,(int)param_2);
        }
        FUN_004f61c0(param_1,(int)param_2);
        return;
      }
      goto LAB_004f5d98;
    }
    puVar2 = (undefined4 *)FUN_004f64a0(local_c,param_1,param_2);
    pfVar4 = (float *)*puVar2;
    pfVar1 = (float *)puVar2[1];
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if (((int)pfVar4 - (int)param_1) / 0xc < ((int)param_2 - (int)pfVar1) / 0xc) {
      FUN_004f5cc0(param_1,pfVar4,param_3,param_4);
      param_1 = pfVar1;
      pfVar4 = param_2;
    }
    else {
      FUN_004f5cc0(pfVar1,param_2,param_3,param_4);
    }
    iVar3 = (int)pfVar4 - (int)param_1;
    param_2 = pfVar4;
  } while( true );
}




/* Global::FUN_004f5f40 @ 004f5f40 */

void __cdecl FUN_004f5f40(float *param_1,float *param_2,int param_3,undefined4 param_4)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  undefined4 local_c [2];
  
  iVar3 = (int)param_2 - (int)param_1;
  do {
    iVar3 = iVar3 / 0xc;
    if (iVar3 < 0x21) {
LAB_004f6018:
      if (1 < iVar3) {
        FUN_004f49d0(param_1,param_2);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar3) {
        if (1 < ((int)param_2 - (int)param_1) / 0xc) {
          FUN_004f4dd0((int)param_1,(int)param_2);
        }
        FUN_004f6330(param_1,(int)param_2);
        return;
      }
      goto LAB_004f6018;
    }
    puVar2 = (undefined4 *)FUN_004f6a60(local_c,param_1,param_2);
    pfVar4 = (float *)*puVar2;
    pfVar1 = (float *)puVar2[1];
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if (((int)pfVar4 - (int)param_1) / 0xc < ((int)param_2 - (int)pfVar1) / 0xc) {
      FUN_004f5f40(param_1,pfVar4,param_3,param_4);
      param_1 = pfVar1;
      pfVar4 = param_2;
    }
    else {
      FUN_004f5f40(pfVar1,param_2,param_3,param_4);
    }
    iVar3 = (int)pfVar4 - (int)param_1;
    param_2 = pfVar4;
  } while( true );
}




/* Global::FUN_004f61c0 @ 004f61c0 */

void __cdecl FUN_004f61c0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  if (1 < (param_2 - (int)param_1) / 0xc) {
    puVar1 = (undefined4 *)(param_2 + -8);
    do {
      local_10 = *puVar1;
      local_14 = (float)puVar1[-1];
      local_c = puVar1[1];
      puVar1[-1] = *param_1;
      *puVar1 = param_1[1];
      puVar1[1] = param_1[2];
      FUN_004f38a0((int)param_1,0,((-4 - (int)param_1) + (int)puVar1) / 0xc,&local_14);
      puVar1 = puVar1 + -3;
    } while (1 < ((8 - (int)param_1) + (int)puVar1) / 0xc);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004f6330 @ 004f6330 */

void __cdecl FUN_004f6330(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  if (1 < (param_2 - (int)param_1) / 0xc) {
    puVar1 = (undefined4 *)(param_2 + -8);
    do {
      local_10 = *puVar1;
      local_14 = (float)puVar1[-1];
      local_c = puVar1[1];
      puVar1[-1] = *param_1;
      *puVar1 = param_1[1];
      puVar1[1] = param_1[2];
      FUN_004f39e0((int)param_1,0,((-4 - (int)param_1) + (int)puVar1) / 0xc,&local_14);
      puVar1 = puVar1 + -3;
    } while (1 < ((8 - (int)param_1) + (int)puVar1) / 0xc);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::FUN_004f64a0 @ 004f64a0 */

void __cdecl FUN_004f64a0(undefined4 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  undefined8 uVar3;
  float *pfVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *local_64;
  
  uVar5 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_64 = param_2 + (((int)param_3 - (int)param_2) / 0x18) * 3;
  FUN_004f5170(param_2,local_64,param_3 + -3);
  pfVar6 = local_64 + 3;
  for (; param_2 < local_64; local_64 = local_64 + -3) {
    if ((local_64[-3] < *local_64) || (*local_64 < local_64[-3])) break;
  }
  pfVar4 = pfVar6;
  pfVar9 = local_64;
  if (pfVar6 < param_3) {
    if (3 < ((int)param_3 + (0xb - (int)pfVar6)) / 0xc) {
      fVar1 = *local_64;
      do {
        pfVar4 = pfVar6;
        if ((*pfVar6 < fVar1) || (fVar1 < *pfVar6)) goto joined_r0x004f65d3;
        if ((pfVar6[3] < fVar1) || (fVar1 < pfVar6[3])) {
          pfVar6 = pfVar6 + 3;
          pfVar4 = pfVar6;
          goto joined_r0x004f65d3;
        }
        if ((pfVar6[6] < fVar1) || (fVar1 < pfVar6[6])) {
          pfVar6 = pfVar6 + 6;
          pfVar4 = pfVar6;
          goto joined_r0x004f65d3;
        }
        if ((pfVar6[9] < fVar1) || (fVar1 < pfVar6[9])) {
          pfVar6 = pfVar6 + 9;
          pfVar4 = pfVar6;
          goto joined_r0x004f65d3;
        }
        pfVar6 = pfVar6 + 0xc;
      } while ((int)pfVar6 < (int)(param_3 + -9));
    }
    pfVar4 = pfVar6;
    if (pfVar6 < param_3) {
      do {
        pfVar4 = pfVar6;
        if ((*pfVar6 < *local_64) || (*local_64 < *pfVar6)) break;
        pfVar6 = pfVar6 + 3;
        pfVar4 = pfVar6;
      } while (pfVar6 < param_3);
    }
  }
joined_r0x004f65d3:
  do {
    if (param_3 <= pfVar4) {
joined_r0x004f6629:
      for (; param_2 < local_64; local_64 = local_64 + -3) {
        fVar1 = local_64[-3];
        pfVar7 = pfVar9;
        if (*pfVar9 <= fVar1) {
          if (*pfVar9 < fVar1) break;
          fVar2 = pfVar9[-3];
          pfVar7 = pfVar9 + -3;
          uVar3 = *(undefined8 *)(pfVar9 + -2);
          *pfVar7 = fVar1;
          pfVar9[-2] = local_64[-2];
          pfVar9[-1] = local_64[-1];
          local_64[-3] = fVar2;
          *(undefined8 *)(local_64 + -2) = uVar3;
        }
        pfVar9 = pfVar7;
      }
      if (local_64 == param_2) {
        if (pfVar4 == param_3) {
          *param_1 = pfVar9;
          param_1[1] = pfVar6;
          __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
          return;
        }
        if (pfVar6 != pfVar4) {
          fVar1 = *pfVar9;
          uVar3 = *(undefined8 *)(pfVar9 + 1);
          *pfVar9 = *pfVar6;
          pfVar9[1] = pfVar6[1];
          pfVar9[2] = pfVar6[2];
          *pfVar6 = fVar1;
          *(undefined8 *)(pfVar6 + 1) = uVar3;
        }
        fVar1 = *pfVar9;
        uVar3 = *(undefined8 *)(pfVar9 + 1);
        *pfVar9 = *pfVar4;
        pfVar9[1] = pfVar4[1];
        pfVar9[2] = pfVar4[2];
        *pfVar4 = fVar1;
        *(undefined8 *)(pfVar4 + 1) = uVar3;
        pfVar6 = pfVar6 + 3;
        pfVar4 = pfVar4 + 3;
        pfVar9 = pfVar9 + 3;
      }
      else {
        pfVar7 = local_64 + -3;
        if (pfVar4 == param_3) {
          pfVar10 = pfVar9 + -3;
          if (pfVar7 != pfVar10) {
            fVar1 = *pfVar7;
            uVar3 = *(undefined8 *)(local_64 + -2);
            *pfVar7 = *pfVar10;
            local_64[-2] = pfVar9[-2];
            local_64[-1] = pfVar9[-1];
            *pfVar10 = fVar1;
            *(undefined8 *)(pfVar9 + -2) = uVar3;
          }
          fVar1 = *pfVar10;
          uVar3 = *(undefined8 *)(pfVar9 + -2);
          pfVar8 = pfVar6 + -3;
          *pfVar10 = *pfVar8;
          pfVar9[-2] = pfVar6[-2];
          pfVar9[-1] = pfVar6[-1];
          *pfVar8 = fVar1;
          *(undefined8 *)(pfVar6 + -2) = uVar3;
          pfVar6 = pfVar8;
          local_64 = pfVar7;
          pfVar9 = pfVar10;
        }
        else {
          fVar1 = *pfVar4;
          uVar3 = *(undefined8 *)(pfVar4 + 1);
          *pfVar4 = *pfVar7;
          pfVar4[1] = local_64[-2];
          pfVar4[2] = local_64[-1];
          *pfVar7 = fVar1;
          *(undefined8 *)(local_64 + -2) = uVar3;
          pfVar4 = pfVar4 + 3;
          local_64 = pfVar7;
        }
      }
      goto joined_r0x004f65d3;
    }
    fVar1 = *pfVar4;
    pfVar7 = pfVar6;
    if (fVar1 <= *pfVar9) {
      if (fVar1 < *pfVar9) goto joined_r0x004f6629;
      pfVar7 = pfVar6 + 3;
      fVar2 = *pfVar6;
      uVar3 = *(undefined8 *)(pfVar6 + 1);
      *pfVar6 = fVar1;
      pfVar6[1] = pfVar4[1];
      pfVar6[2] = pfVar4[2];
      *pfVar4 = fVar2;
      *(undefined8 *)(pfVar4 + 1) = uVar3;
    }
    pfVar6 = pfVar7;
    pfVar4 = pfVar4 + 3;
  } while( true );
}




/* Global::FUN_004f6a60 @ 004f6a60 */

void __cdecl FUN_004f6a60(undefined4 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  undefined8 uVar3;
  float *pfVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *local_64;
  
  uVar5 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_64 = param_2 + (((int)param_3 - (int)param_2) / 0x18) * 3;
  FUN_004f55b0(param_2,local_64,param_3 + -3);
  pfVar6 = local_64 + 3;
  for (; param_2 < local_64; local_64 = local_64 + -3) {
    if ((*local_64 < local_64[-3]) || (local_64[-3] < *local_64)) break;
  }
  pfVar4 = pfVar6;
  pfVar9 = local_64;
  if (pfVar6 < param_3) {
    if (3 < ((int)param_3 + (0xb - (int)pfVar6)) / 0xc) {
      fVar1 = *local_64;
      do {
        pfVar4 = pfVar6;
        if ((fVar1 < *pfVar6) || (*pfVar6 < fVar1)) goto joined_r0x004f6b93;
        if ((fVar1 < pfVar6[3]) || (pfVar6[3] < fVar1)) {
          pfVar6 = pfVar6 + 3;
          pfVar4 = pfVar6;
          goto joined_r0x004f6b93;
        }
        if ((fVar1 < pfVar6[6]) || (pfVar6[6] < fVar1)) {
          pfVar6 = pfVar6 + 6;
          pfVar4 = pfVar6;
          goto joined_r0x004f6b93;
        }
        if ((fVar1 < pfVar6[9]) || (pfVar6[9] < fVar1)) {
          pfVar6 = pfVar6 + 9;
          pfVar4 = pfVar6;
          goto joined_r0x004f6b93;
        }
        pfVar6 = pfVar6 + 0xc;
      } while ((int)pfVar6 < (int)(param_3 + -9));
    }
    pfVar4 = pfVar6;
    if (pfVar6 < param_3) {
      do {
        pfVar4 = pfVar6;
        if ((*local_64 < *pfVar6) || (*pfVar6 < *local_64)) break;
        pfVar6 = pfVar6 + 3;
        pfVar4 = pfVar6;
      } while (pfVar6 < param_3);
    }
  }
joined_r0x004f6b93:
  do {
    if (param_3 <= pfVar4) {
joined_r0x004f6be9:
      for (; param_2 < local_64; local_64 = local_64 + -3) {
        fVar1 = local_64[-3];
        pfVar7 = pfVar9;
        if (fVar1 <= *pfVar9) {
          if (fVar1 < *pfVar9) break;
          fVar2 = pfVar9[-3];
          pfVar7 = pfVar9 + -3;
          uVar3 = *(undefined8 *)(pfVar9 + -2);
          *pfVar7 = fVar1;
          pfVar9[-2] = local_64[-2];
          pfVar9[-1] = local_64[-1];
          local_64[-3] = fVar2;
          *(undefined8 *)(local_64 + -2) = uVar3;
        }
        pfVar9 = pfVar7;
      }
      if (local_64 == param_2) {
        if (pfVar4 == param_3) {
          *param_1 = pfVar9;
          param_1[1] = pfVar6;
          __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
          return;
        }
        if (pfVar6 != pfVar4) {
          fVar1 = *pfVar9;
          uVar3 = *(undefined8 *)(pfVar9 + 1);
          *pfVar9 = *pfVar6;
          pfVar9[1] = pfVar6[1];
          pfVar9[2] = pfVar6[2];
          *pfVar6 = fVar1;
          *(undefined8 *)(pfVar6 + 1) = uVar3;
        }
        fVar1 = *pfVar9;
        uVar3 = *(undefined8 *)(pfVar9 + 1);
        *pfVar9 = *pfVar4;
        pfVar9[1] = pfVar4[1];
        pfVar9[2] = pfVar4[2];
        *pfVar4 = fVar1;
        *(undefined8 *)(pfVar4 + 1) = uVar3;
        pfVar6 = pfVar6 + 3;
        pfVar4 = pfVar4 + 3;
        pfVar9 = pfVar9 + 3;
      }
      else {
        pfVar7 = local_64 + -3;
        if (pfVar4 == param_3) {
          pfVar10 = pfVar9 + -3;
          if (pfVar7 != pfVar10) {
            fVar1 = *pfVar7;
            uVar3 = *(undefined8 *)(local_64 + -2);
            *pfVar7 = *pfVar10;
            local_64[-2] = pfVar9[-2];
            local_64[-1] = pfVar9[-1];
            *pfVar10 = fVar1;
            *(undefined8 *)(pfVar9 + -2) = uVar3;
          }
          fVar1 = *pfVar10;
          uVar3 = *(undefined8 *)(pfVar9 + -2);
          pfVar8 = pfVar6 + -3;
          *pfVar10 = *pfVar8;
          pfVar9[-2] = pfVar6[-2];
          pfVar9[-1] = pfVar6[-1];
          *pfVar8 = fVar1;
          *(undefined8 *)(pfVar6 + -2) = uVar3;
          pfVar6 = pfVar8;
          local_64 = pfVar7;
          pfVar9 = pfVar10;
        }
        else {
          fVar1 = *pfVar4;
          uVar3 = *(undefined8 *)(pfVar4 + 1);
          *pfVar4 = *pfVar7;
          pfVar4[1] = local_64[-2];
          pfVar4[2] = local_64[-1];
          *pfVar7 = fVar1;
          *(undefined8 *)(local_64 + -2) = uVar3;
          pfVar4 = pfVar4 + 3;
          local_64 = pfVar7;
        }
      }
      goto joined_r0x004f6b93;
    }
    fVar1 = *pfVar4;
    pfVar7 = pfVar6;
    if (*pfVar9 <= fVar1) {
      if (*pfVar9 < fVar1) goto joined_r0x004f6be9;
      pfVar7 = pfVar6 + 3;
      fVar2 = *pfVar6;
      uVar3 = *(undefined8 *)(pfVar6 + 1);
      *pfVar6 = fVar1;
      pfVar6[1] = pfVar4[1];
      pfVar6[2] = pfVar4[2];
      *pfVar4 = fVar2;
      *(undefined8 *)(pfVar4 + 1) = uVar3;
    }
    pfVar6 = pfVar7;
    pfVar4 = pfVar4 + 3;
  } while( true );
}




/* Global::FUN_004f7ef0 @ 004f7ef0 */

void __thiscall FUN_004f7ef0(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00555690;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)0x0;
  if (param_1 != 0) {
    if (param_1 < 0x15555556) {
      puVar3 = operator_new(param_1 * 0xc);
      if (puVar3 != (undefined4 *)0x0) goto LAB_004f7f4f;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_004f7f4f:
  local_8 = 0;
  FUN_004f71e0(*(int *)this,*(int *)((int)this + 4),puVar3);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 **)this = puVar3;
  *(undefined4 **)((int)this + 8) = puVar3 + param_1 * 3;
  *(undefined4 **)((int)this + 4) = puVar3 + ((iVar1 - iVar2) / 0xc) * 3;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: World_temperatureBlend  (confidence: high)
 * purpose: Per-column temperature: weighted average over 3x3 warped site window
 * vars: 
 */
/* Global::World_temperatureBlend @ 004f8570 */

void __thiscall World_temperatureBlend(void *this,float param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  uint *puVar6;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint *local_a4;
  int local_a0;
  int local_9c;
  uint local_98;
  float local_94;
  int local_90;
  int local_8c;
  float local_88;
  int local_84;
  int local_80;
  void *local_7c;
  int local_78;
  float local_74;
  float local_70;
  uint *local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  uint local_58;
  uint uStack_54;
  uint local_50;
  uint uStack_4c;
  uint local_48;
  uint uStack_44;
  uint local_40;
  uint uStack_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_84 = (int)((int)param_1 + -0x4000 + ((int)param_1 + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  local_80 = (int)((param_2 - 0x4000) + ((int)(param_2 - 0x4000) >> 0x1f & 0x3fffU)) >> 0xe;
  local_68 = (float)((int)((int)param_1 + 0x4000 + ((int)param_1 + 0x4000 >> 0x1f & 0x3fffU)) >> 0xe
                    );
  fVar5 = (float)((int)(((int)(param_2 + 0x4000) >> 0x1f & 0x3fffU) + param_2 + 0x4000) >> 0xe);
  local_94 = param_1;
  local_98 = param_2;
  local_7c = this;
  local_74 = fVar5;
  fVar7 = valueNoise2D(SUB84((double)(int)param_2 * 0.0005,0),
                       (int)((ulonglong)((double)(int)param_2 * 0.0005) >> 0x20),3423.0);
  local_70 = (float)fVar7;
  local_88 = local_70 * 3.0 * 256.0;
  local_60 = local_88;
  fVar7 = valueNoise2D(SUB84((double)(int)param_1 * 0.0005,0),
                       (int)((ulonglong)((double)(int)param_1 * 0.0005) >> 0x20),23421.0);
  fVar8 = local_94;
  uVar1 = local_98;
  local_5c = (float)fVar7 * 3.0 * 256.0;
  puVar6 = (uint *)0x0;
  local_a4 = (uint *)0x0;
  local_70 = (float)(int)((float)(int)param_1 + local_88);
  local_8c = 0;
  local_88 = (float)(int)((float)(int)local_98 + local_5c);
  local_a0 = local_84;
  if (local_84 <= (int)local_68) {
    local_90 = local_84 * 0x400 + 0x10002f;
    local_78 = local_90;
    do {
      local_9c = local_80;
      if (local_80 <= (int)fVar5) {
        do {
          if ((((local_a0 < 0) || (local_9c < 0)) || (0x20002e < local_78)) ||
             ((0x3ff < local_9c ||
              (local_6c = *(uint **)((int)this + (local_9c + local_78) * 4), local_6c == (uint *)0x0
              )))) goto LAB_004f8b21;
          local_48 = *local_6c;
          uStack_44 = ((int)local_48 >> 0x1f) << 0x10 | local_48 >> 0x10;
          local_48 = local_48 * 0x10000;
          local_40 = local_6c[1];
          uStack_3c = ((int)local_40 >> 0x1f) << 0x10 | local_40 >> 0x10;
          local_40 = local_40 * 0x10000;
          local_18 = CONCAT44((uStack_44 -
                              (((int)local_70 >> 0x1f) << 0x10 | (uint)local_70 >> 0x10)) -
                              (uint)(local_48 < (uint)((int)local_70 * 0x10000)),
                              local_48 + (int)local_70 * -0x10000);
          local_10 = CONCAT44((uStack_3c -
                              (((int)local_88 >> 0x1f) << 0x10 | (uint)local_88 >> 0x10)) -
                              (uint)(local_40 < (uint)((int)local_88 * 0x10000)),
                              local_40 + (int)local_88 * -0x10000);
          local_64 = (float)local_10;
          local_30 = (float)local_18 * 1.5258789e-05;
          local_2c = local_64 * 1.5258789e-05;
          iVar2 = (int)(local_2c * local_2c + local_30 * local_30);
          if ((local_a4 == (uint *)0x0) || (iVar2 < local_8c)) {
            local_a4 = local_6c;
            local_8c = iVar2;
          }
          local_9c = local_9c + 1;
          fVar5 = local_74;
          this = local_7c;
          puVar6 = local_a4;
        } while (local_9c <= (int)local_74);
      }
      local_a0 = local_a0 + 1;
      local_78 = local_78 + 0x400;
    } while (local_a0 <= (int)local_68);
    if (puVar6 != (uint *)0x0) {
      fVar10 = 0.0;
      fVar9 = 0.0;
      do {
        local_78 = local_80;
        if (local_80 <= (int)fVar5) {
          do {
            if (((local_84 < 0) || (local_78 < 0)) ||
               ((0x20002e < local_90 ||
                ((0x3ff < local_78 ||
                 (local_6c = *(uint **)((int)this + (local_78 + local_90) * 4),
                 local_6c == (uint *)0x0)))))) goto LAB_004f8b21;
            local_58 = *local_6c;
            uStack_54 = ((int)local_58 >> 0x1f) << 0x10 | local_58 >> 0x10;
            local_58 = local_58 * 0x10000;
            local_50 = local_6c[1];
            uStack_4c = ((int)local_50 >> 0x1f) << 0x10 | local_50 >> 0x10;
            local_50 = local_50 * 0x10000;
            local_28 = CONCAT44((uStack_54 -
                                (((int)local_70 >> 0x1f) << 0x10 | (uint)local_70 >> 0x10)) -
                                (uint)(local_58 < (uint)((int)local_70 * 0x10000)),
                                local_58 + (int)local_70 * -0x10000);
            local_20 = CONCAT44((uStack_4c -
                                (((int)local_88 >> 0x1f) << 0x10 | (uint)local_88 >> 0x10)) -
                                (uint)(local_50 < (uint)((int)local_88 * 0x10000)),
                                local_50 + (int)local_88 * -0x10000);
            local_64 = (float)local_20;
            local_38 = (float)local_28 * 1.5258789e-05;
            local_34 = local_64 * 1.5258789e-05;
            fVar5 = (float)((int)(local_34 * local_34 + local_38 * local_38) - local_8c) * 5e-07;
            if (1.0 < fVar5) {
              fVar5 = 1.0;
            }
            fVar10 = fVar10 + (1.0 - fVar5);
            local_78 = local_78 + 1;
            fVar9 = fVar9 + (float)local_6c[3] * (1.0 - fVar5);
            fVar5 = local_74;
            this = local_7c;
          } while (local_78 <= (int)local_74);
        }
        local_84 = local_84 + 1;
        local_90 = local_90 + 0x400;
        this = local_7c;
      } while (local_84 <= (int)local_68);
      if (0.0 < fVar10) {
        local_74 = fVar9 / fVar10;
        uVar3 = (int)local_98 >> 0x1f;
        uVar4 = (int)local_94 >> 0x1f;
        local_68 = local_74;
        puVar6 = (uint *)World_getTileAtCoords(local_7c,(int)((int)local_94 + (uVar4 & 0x7ff)) >> 0xb,
                                      (int)(local_98 + (uVar3 & 0x7ff)) >> 0xb);
        if (((local_74 < 0.2) && (puVar6 != (uint *)0x0)) && (puVar6[6] == 3)) {
          local_b0 = uVar3 << 0x10 | uVar1 >> 0x10;
          local_b4 = uVar1 << 0x10;
          local_a8 = uVar4 << 0x10 | (uint)fVar8 >> 0x10;
          local_ac = (int)fVar8 << 0x10;
          fVar7 = World_objectFalloffWeight(puVar6,&local_ac,&local_b4);
          local_94 = (float)fVar7;
          fVar5 = 1.0 - local_94;
          fVar8 = 0.0;
          if (0.0 < fVar5) {
            fVar8 = fVar5 * fVar5;
          }
          local_68 = fVar8 * 0.3 + local_74;
          if (1.0 < local_68) {
            local_68 = 1.0;
          }
        }
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_004f8b21:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World_humidityBlend  (confidence: high)
 * purpose: Per-column humidity: weighted average over 3x3 warped site window
 * vars: 
 */
/* Global::World_humidityBlend @ 004f8b40 */

void __thiscall World_humidityBlend(void *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  float10 fVar15;
  float10 fVar16;
  float fVar17;
  float fVar18;
  uint *local_90;
  int local_84;
  undefined4 local_7c;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar3 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  local_7c = (int)(param_1 + -0x4000 + (param_1 + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  iVar4 = (int)(param_2 + -0x4000 + (param_2 + -0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  iVar5 = (int)(param_1 + 0x4000 + (param_1 + 0x4000 >> 0x1f & 0x3fffU)) >> 0xe;
  iVar13 = (int)((param_2 + 0x4000 >> 0x1f & 0x3fffU) + param_2 + 0x4000) >> 0xe;
  fVar15 = valueNoise2D(SUB84((double)param_2 * 0.0005,0),
                        (int)((ulonglong)((double)param_2 * 0.0005) >> 0x20),3423.0);
  fVar16 = valueNoise2D(SUB84((double)param_1 * 0.0005,0),
                        (int)((ulonglong)((double)param_1 * 0.0005) >> 0x20),23421.0);
  uVar6 = (uint)((float)param_1 + (float)fVar15 * 3.0 * 256.0);
  puVar14 = (uint *)0x0;
  local_90 = (uint *)0x0;
  local_84 = 0;
  uVar7 = (uint)((float)param_2 + (float)fVar16 * 3.0 * 256.0);
  if (local_7c <= iVar5) {
    iVar11 = local_7c * 0x400 + 0x10002f;
    iVar10 = iVar11;
    iVar12 = local_7c;
    do {
      for (iVar9 = iVar4; iVar9 <= iVar13; iVar9 = iVar9 + 1) {
        if ((((iVar12 < 0) || (iVar9 < 0)) || (0x20002e < iVar10)) ||
           ((0x3ff < iVar9 ||
            (puVar14 = *(uint **)((int)this + (iVar9 + iVar10) * 4), puVar14 == (uint *)0x0))))
        goto LAB_004f8ff6;
        uVar1 = *puVar14;
        uVar2 = puVar14[1];
        local_28 = CONCAT44(((((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10) -
                            (((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10)) -
                            (uint)(uVar1 * 0x10000 < uVar6 * 0x10000),
                            uVar1 * 0x10000 + uVar6 * -0x10000);
        local_20 = CONCAT44(((((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) -
                            (((int)uVar7 >> 0x1f) << 0x10 | uVar7 >> 0x10)) -
                            (uint)(uVar2 * 0x10000 < uVar7 * 0x10000),
                            uVar2 * 0x10000 + uVar7 * -0x10000);
        iVar8 = (int)((float)local_20 * 1.5258789e-05 * (float)local_20 * 1.5258789e-05 +
                     (float)local_28 * 1.5258789e-05 * (float)local_28 * 1.5258789e-05);
        if ((local_90 == (uint *)0x0) || (iVar8 < local_84)) {
          local_90 = puVar14;
          local_84 = iVar8;
        }
        puVar14 = local_90;
      }
      iVar12 = iVar12 + 1;
      iVar10 = iVar10 + 0x400;
    } while (iVar12 <= iVar5);
    if (puVar14 != (uint *)0x0) {
      fVar18 = 0.0;
      iVar10 = iVar4;
      do {
        for (; iVar10 <= iVar13; iVar10 = iVar10 + 1) {
          if (((local_7c < 0) || (iVar10 < 0)) ||
             ((0x20002e < iVar11 ||
              ((0x3ff < iVar10 ||
               (puVar14 = *(uint **)((int)this + (iVar10 + iVar11) * 4), puVar14 == (uint *)0x0)))))
             ) goto LAB_004f8ff6;
          uVar1 = *puVar14;
          uVar2 = puVar14[1];
          local_18 = CONCAT44(((((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10) -
                              (((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10)) -
                              (uint)(uVar1 * 0x10000 < uVar6 * 0x10000),
                              uVar1 * 0x10000 + uVar6 * -0x10000);
          local_10 = CONCAT44(((((int)uVar2 >> 0x1f) << 0x10 | uVar2 >> 0x10) -
                              (((int)uVar7 >> 0x1f) << 0x10 | uVar7 >> 0x10)) -
                              (uint)(uVar2 * 0x10000 < uVar7 * 0x10000),
                              uVar2 * 0x10000 + uVar7 * -0x10000);
          fVar17 = (float)((int)((float)local_10 * 1.5258789e-05 * (float)local_10 * 1.5258789e-05 +
                                (float)local_18 * 1.5258789e-05 * (float)local_18 * 1.5258789e-05) -
                          local_84) * 5e-07;
          if (1.0 < fVar17) {
            fVar17 = 1.0;
          }
          fVar18 = fVar18 + (1.0 - fVar17);
        }
        local_7c = local_7c + 1;
        iVar11 = iVar11 + 0x400;
        iVar10 = iVar4;
      } while (local_7c <= iVar5);
      if (0.0 < fVar18) {
        __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_004f8ff6:
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World_baseHeightField  (confidence: low)
 * purpose: Multi-octave terrain/biome generator: sums value-noise layers, computes climate/height and blends region data
 * vars: this+0x80018c.. many noise seed offsets; valueNoise2D noise; World_objectFalloffWeight/0052cd50 helpers
 */
/* Global::World_baseHeightField @ 004f9b70 */

void __thiscall World_baseHeightField(void *this,uint x,float y,int z)

{
  uint *puVar1;
  longlong lVar2;
  float fVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  float local_174;
  float min_col;
  float max_row;
  float local_168;
  float local_164;
  float local_160;
  uint *local_15c;
  float min_row;
  float max_col;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  double local_140;
  uint local_134;
  float x_float;
  uint local_12c;
  uint local_128;
  float local_124;
  undefined8 local_120;
  double local_118;
  double local_110;
  undefined8 local_108;
  undefined8 local_100;
  double local_f8;
  uint local_f0;
  int z_arg;
  int local_e8;
  float local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  double local_b8;
  uint local_b0;
  uint local_ac;
  float local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  uint local_70;
  uint uStack_6c;
  uint local_68;
  uint uStack_64;
  uint local_60;
  uint uStack_5c;
  uint local_58;
  uint uStack_54;
  float local_4c;
  float local_48;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&local_174;
  local_110 = (double)(int)y;
  local_100 = local_110 * 0.0001;
  local_118 = (double)(int)x;
  local_108 = local_118 * 0.0001;
  x_float = (float)x;
  dVar11 = (double)*(int *)((int)this + 0x80018c) + local_108;
  local_124 = y;
  z_arg = z;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x800190) + local_100);
  local_164 = (float)fVar10;
  local_14c = (local_164 + 1.0) * 0.5;
  dVar11 = (double)*(int *)((int)this + 0x800194) + local_108;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x800198) + local_100);
  local_164 = (float)fVar10;
  local_100 = local_110 * 0.001;
  local_148 = (local_164 + 1.0) * 0.5;
  local_108 = local_118 * 0.001;
  dVar11 = (double)*(int *)((int)this + 0x80019c) + local_108;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001a0) + local_100);
  local_164 = (float)fVar10;
  local_160 = (local_164 + 1.0) * 0.5;
  dVar11 = (double)*(int *)((int)this + 0x8001a4) + local_108;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001a8) + local_100);
  local_164 = (float)fVar10;
  local_b8 = local_110 * 0.002;
  min_row = (local_164 + 1.0) * 0.5;
  local_120 = local_118 * 0.002;
  dVar11 = (double)*(int *)((int)this + 0x8001ac) + local_120;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001b0) + local_b8);
  local_164 = (float)fVar10;
  local_14c = local_14c * local_14c;
  local_140._0_4_ = (local_164 + 1.0) * 0.5;
  local_148 = local_148 * local_148;
  local_140._0_4_ = local_140._0_4_ * local_140._0_4_;
  local_160 = local_160 * local_160;
  min_row = min_row * min_row;
  fVar10 = World_riverClimateGate(this,x,y,z_arg);
  fVar12 = (float)fVar10 * 4.0;
  if (1.0 < fVar12) {
    fVar12 = 1.0;
  }
  local_150 = fVar12 * 3.0 * fVar12 - fVar12 * 2.0 * fVar12 * fVar12;
  local_150 = local_150 * local_150;
  local_e4 = local_150 * local_160;
  local_174 = local_150 * min_row;
  local_150 = local_150 * local_140._0_4_;
  max_col = (float)((int)(x + 0x4000 + ((int)(x + 0x4000) >> 0x1f & 0x3fffU)) >> 0xe);
  max_row = (float)((int)((int)local_124 + 0x4000 + ((int)local_124 + 0x4000 >> 0x1f & 0x3fffU))
                     >> 0xe);
  iVar8 = (int)(((int)(x - 0x4000) >> 0x1f & 0x3fffU) + (x - 0x4000)) >> 0xe;
  local_164 = 0.0;
  min_col = (float)iVar8;
  min_row = (float)((int)((int)local_124 + -0x4000 + ((int)local_124 + -0x4000 >> 0x1f & 0x3fffU))
                     >> 0xe);
  fVar10 = valueNoise2D(SUB84(local_110 * 0.0005,0),(int)((ulonglong)(local_110 * 0.0005) >> 0x20),
                        3423.0);
  local_140._0_4_ = (float)fVar10;
  local_4c = local_140._0_4_ * 3.0 * 256.0;
  local_f8 = (double)CONCAT44(local_f8._4_4_,local_4c);
  fVar10 = valueNoise2D(SUB84(local_118 * 0.0005,0),(int)((ulonglong)(local_118 * 0.0005) >> 0x20),
                        23421.0);
  local_15c = (uint *)((float)fVar10 * 3.0 * 256.0);
  local_140._0_4_ = local_f8._0_4_ * 65536.0;
  local_134 = ((int)x >> 0x1f) << 0x10 | x >> 0x10;
  local_128 = x * 0x10000;
  local_48 = (float)local_15c;
  uVar17 = ftol2();
  lVar2 = uVar17 + CONCAT44(local_134,x * 0x10000);
  local_f0 = (uint)lVar2;
  local_e8 = (int)((ulonglong)lVar2 >> 0x20);
  local_12c = ((int)local_124 >> 0x1f) << 0x10 | (uint)local_124 >> 0x10;
  local_140 = (double)CONCAT44(local_140._4_4_,(float)local_15c * 65536.0);
  uVar6 = (int)local_124 * 0x10000;
  local_160 = (float)uVar6;
  uVar17 = ftol2();
  lVar2 = uVar17 + CONCAT44(local_12c,uVar6);
  uVar6 = (uint)lVar2;
  iVar5 = (int)((ulonglong)lVar2 >> 0x20);
  puVar4 = (uint *)0x0;
  fVar15 = 0.0;
  local_15c = (uint *)0x0;
  fVar12 = 0.0;
  if (iVar8 <= (int)max_col) {
    iVar9 = iVar8 * 0x400 + 0x10002f;
    fVar16 = min_row;
    do {
      for (; (int)fVar16 <= (int)max_row; fVar16 = (float)((int)fVar16 + 1)) {
        if ((((-1 < iVar8) && (-1 < (int)fVar16)) && (iVar9 < 0x20002f)) &&
           (((int)fVar16 < 0x400 &&
            (puVar1 = *(uint **)((int)this + (iVar9 + (int)fVar16) * 4), puVar4 = local_15c,
            puVar1 != (uint *)0x0)))) {
          local_70 = *puVar1;
          uStack_6c = ((int)local_70 >> 0x1f) << 0x10 | local_70 >> 0x10;
          local_70 = local_70 * 0x10000;
          local_68 = puVar1[1];
          uStack_64 = ((int)local_68 >> 0x1f) << 0x10 | local_68 >> 0x10;
          local_68 = local_68 * 0x10000;
          local_90 = CONCAT44((uStack_6c - local_e8) - (uint)(local_70 < local_f0),
                              local_70 - local_f0);
          local_88 = CONCAT44((uStack_64 - iVar5) - (uint)(local_68 < uVar6),local_68 - uVar6);
          local_168 = (float)local_88;
          local_80 = (float)local_90 * 1.5258789e-05;
          local_7c = local_168 * 1.5258789e-05;
          fVar13 = local_7c * local_7c + local_80 * local_80;
          if ((local_15c == (uint *)0x0) || (fVar13 < fVar12)) {
            puVar4 = puVar1;
            fVar12 = fVar13;
            local_15c = puVar1;
          }
        }
      }
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x400;
      fVar16 = min_row;
    } while (iVar8 <= (int)max_col);
  }
  fVar16 = 0.0;
  local_15c = (uint *)0x3f800000;
  local_144 = 0.0;
  if (puVar4 != (uint *)0x0) {
    fVar13 = 0.0;
    if ((int)min_col <= (int)max_col) {
      iVar8 = (int)min_col * 0x400 + 0x10002f;
      fVar3 = min_row;
      do {
        for (; (int)fVar3 <= (int)max_row; fVar3 = (float)((int)fVar3 + 1)) {
          if (((-1 < (int)min_col) && (-1 < (int)fVar3)) &&
             ((iVar8 < 0x20002f &&
              (((int)fVar3 < 0x400 &&
               (puVar4 = *(uint **)((int)this + (iVar8 + (int)fVar3) * 4), puVar4 != (uint *)0x0))))
             )) {
            local_60 = *puVar4;
            uStack_5c = ((int)local_60 >> 0x1f) << 0x10 | local_60 >> 0x10;
            local_60 = local_60 * 0x10000;
            local_58 = puVar4[1];
            uStack_54 = ((int)local_58 >> 0x1f) << 0x10 | local_58 >> 0x10;
            local_58 = local_58 * 0x10000;
            local_a0 = CONCAT44((uStack_5c - local_e8) - (uint)(local_60 < local_f0),
                                local_60 - local_f0);
            local_98 = CONCAT44((uStack_54 - iVar5) - (uint)(local_58 < uVar6),local_58 - uVar6);
            local_168 = (float)local_98;
            local_78 = (float)local_a0 * 1.5258789e-05;
            local_74 = local_168 * 1.5258789e-05;
            fVar14 = ((local_74 * local_74 + local_78 * local_78) - fVar12) * 5e-08;
            if (1.0 < fVar14) {
              fVar14 = 1.0;
            }
            fVar14 = (1.0 - fVar14) * (1.0 - fVar14);
            fVar13 = fVar13 + fVar14;
            fVar16 = fVar16 + (float)(int)puVar4[6] * fVar14;
            if (0 < (int)puVar4[6]) {
              fVar15 = fVar15 + fVar14;
            }
          }
        }
        min_col = (float)((int)min_col + 1);
        iVar8 = iVar8 + 0x400;
        fVar3 = min_row;
      } while ((int)min_col <= (int)max_col);
    }
    local_164 = fVar16 / fVar13;
    local_15c = (uint *)(fVar15 / fVar13);
    local_144 = local_164;
  }
  local_140 = local_110 * 0.0002;
  local_f8 = local_118 * 0.0002;
  dVar11 = (double)*(int *)((int)this + 0x8001bc) + local_f8;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001c0) + local_140);
  local_168 = (float)fVar10;
  max_col = (local_168 + 1.0) * 100.0 * local_148;
  dVar11 = (double)*(int *)((int)this + 0x8001b4) + local_f8;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001b8) + local_140);
  fVar15 = local_124;
  fVar12 = x_float;
  local_168 = (float)fVar10;
  max_col = (max_col + (local_168 + 1.0) * 100.0 * local_14c) * (float)local_15c + local_164;
  fVar10 = World_roadField(this,(uint)x_float,(uint)local_124);
  x_float = (float)fVar10;
  if (0.5 < x_float) {
    fVar16 = (x_float - 0.5) * 2.0;
    if (1.0 < fVar16) {
      fVar16 = 1.0;
    }
    local_150 = (1.0 - (fVar16 * 3.0 * fVar16 - fVar16 * 2.0 * fVar16 * fVar16)) * local_150;
  }
  fVar10 = (float10)World_waterDepthField(this,(uint)fVar12,(uint)fVar15);
  x_float = (float)fVar10;
  fVar16 = x_float;
  if (x_float < 0.02) {
    fVar16 = 0.02;
  }
  fVar16 = fVar16 * 2.0;
  if (1.0 < fVar16) {
    fVar16 = 1.0;
  }
  fVar16 = 1.0 - fVar16;
  uVar7 = (int)(((int)fVar12 >> 0x1f & 0x7ffU) + (int)fVar12) >> 0xb;
  uVar6 = (int)(((int)fVar15 >> 0x1f & 0x7ffU) + (int)fVar15) >> 0xb;
  fVar12 = 1.0 - fVar16 * fVar16 * fVar16 * fVar16;
  local_14c = fVar12 * 0.1 + 0.9;
  local_150 = (fVar12 * 0.5 + 0.5) * local_150;
  local_148 = local_14c * local_e4;
  local_14c = local_14c * local_174;
  if ((((-1 < (int)uVar7) && (-1 < (int)uVar6)) && ((int)uVar7 < 0x2000)) && ((int)uVar6 < 0x2000))
  {
    iVar5 = (int)(uVar7 * 8 + ((int)(uVar7 * 8) >> 0x1f & 0x3fU)) >> 6;
    iVar8 = (int)(((int)(uVar6 * 8) >> 0x1f & 0x3fU) + uVar6 * 8) >> 6;
    if (((-1 < iVar5) && (-1 < iVar8)) &&
       ((iVar5 < 0x400 &&
        ((iVar8 < 0x400 &&
         (iVar5 = *(int *)((int)this + (iVar5 * 0x400 + iVar8) * 4 + 0xbc), iVar5 != 0)))))) {
      uVar7 = uVar7 & 0x80000007;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
      }
      uVar6 = uVar6 & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      puVar4 = (uint *)(iVar5 + 0x14018 + (uVar6 + uVar7 * 8) * 0x68);
      if ((puVar4 != (uint *)0x0) && (puVar4[6] == 1)) {
        local_d8 = (uint)local_160;
        local_d4 = local_12c;
        local_e0 = local_128;
        local_dc = local_134;
        fVar10 = World_objectFalloffWeight(puVar4,&local_e0,&local_d8);
        local_174 = (float)fVar10;
        fVar12 = 1.0 - local_174;
        if (0.0 < fVar12) {
          fVar12 = fVar12 * fVar12;
        }
        else {
          fVar12 = 0.0;
        }
        fVar12 = 1.0 - fVar12 * 0.5;
        local_148 = fVar12 * local_148;
        local_14c = fVar12 * local_14c;
        local_150 = fVar12 * local_150;
      }
      goto LAB_004fa7b3;
    }
  }
  puVar4 = (uint *)0x0;
LAB_004fa7b3:
  dVar11 = (double)*(int *)((int)this + 0x8001cc) + local_120;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001d0) + local_b8);
  local_174 = (float)fVar10;
  min_col = (local_174 + 1.0) * 50.0 * local_14c;
  dVar11 = (double)*(int *)((int)this + 0x8001c4) + local_120;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001c8) + local_b8);
  local_174 = (float)fVar10;
  min_col = min_col + (local_174 + 1.0) * 50.0 * local_148;
  dVar11 = (double)*(int *)((int)this + 0x8001d4) + local_118 * 0.01;
  fVar10 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                        (double)*(int *)((int)this + 0x8001d8) + local_110 * 0.01);
  local_174 = (float)fVar10;
  min_col = min_col + (local_174 + 1.0) * 20.0 * local_150 + max_col;
  max_row = min_col;
  if ((puVar4 != (uint *)0x0) && (puVar4[6] != 0)) {
    uVar18 = __alldiv(puVar4[2],puVar4[3],0x10000,0);
    uVar19 = __alldiv(*puVar4,puVar4[1],0x10000,0);
    iVar5 = World_findNearestEntityInRegion(this,(int)uVar19,(int)uVar18);
    uVar6 = local_128;
    if ((iVar5 != 0) && ((iVar5 = *(int *)(iVar5 + 0x18), iVar5 < 0 && (puVar4[6] != 0xb)))) {
      local_110 = local_110 * 0.0025;
      local_118 = local_118 * 0.0025;
      fVar10 = valueNoise2D(SUB84(local_118 + 8432984.0,0),
                            (int)((ulonglong)(local_118 + 8432984.0) >> 0x20),local_110 + 90493.0);
      local_174 = (float)fVar10 * 100.0 * 65536.0;
      uVar17 = ftol2();
      uVar6 = local_128;
      uVar7 = (uint)uVar17 - *puVar4;
      local_120 = (double)CONCAT44((((int)(uVar17 >> 0x20) - puVar4[1]) -
                                   (uint)((uint)uVar17 < *puVar4)) + local_134 +
                                   (uint)CARRY4(uVar7,local_128),uVar7 + local_128);
      local_174 = (float)(longlong)local_120;
      local_a8 = local_174 * 1.5258789e-05;
      fVar10 = valueNoise2D(SUB84(local_118 + 3423.0,0),
                            (int)((ulonglong)(local_118 + 3423.0) >> 0x20),local_110 + 112.0);
      local_174 = ((float)fVar10 * 100.0 + (float)(int)local_124) * 65536.0;
      uVar17 = ftol2();
      local_120 = (double)CONCAT44(((int)(uVar17 >> 0x20) - puVar4[3]) -
                                   (uint)((uint)uVar17 < puVar4[2]),(uint)uVar17 - puVar4[2]);
      local_174 = (float)(longlong)local_120;
      fVar12 = (local_174 * 1.5258789e-05 * local_174 * 1.5258789e-05 + local_a8 * local_a8) /
               (((float)puVar4[4] + 256.0) * ((float)puVar4[4] + 256.0));
      if (1.0 < fVar12) {
        fVar12 = 1.0;
      }
      if (0.0 < 1.0 - fVar12) {
        fVar12 = (1.0 - fVar12) * 1.1;
        if (1.0 < fVar12) {
          fVar12 = 1.0;
        }
        min_col = min_col -
                    (fVar12 * 3.0 * fVar12 - fVar12 * 2.0 * fVar12 * fVar12) * (float)iVar5;
        max_row = min_col;
      }
    }
    uVar7 = puVar4[6];
    if (uVar7 == 4) {
      local_c0 = (uint)local_160;
      local_bc = local_12c;
      local_ac = local_134;
      local_b0 = uVar6;
      fVar10 = World_objectFalloffWeight(puVar4,&local_b0,&local_c0);
      local_174 = (float)fVar10;
      if (0.25 < local_174) {
        if (local_174 < 1.0) {
          dVar11 = (double)local_174;
          libm_sse2_sqrt_precise();
          fVar12 = ((float)dVar11 - 0.5) * 2.0;
          fVar12 = 1.0 - fVar12 * fVar12;
          min_col = (((float)puVar4[5] - 25.0) - min_col) * fVar12 * fVar12 + min_col;
          max_row = min_col;
        }
      }
      else {
        fVar12 = 1.0 - local_174 * 4.0;
        fVar12 = fVar12 * fVar12;
        min_col = (1.0 - fVar12) * ((float)puVar4[5] - 25.0) + ((float)puVar4[5] - 50.0) * fVar12;
        max_row = min_col;
      }
    }
    if ((uVar7 == 6) || (uVar7 == 7)) {
      local_d0 = (uint)local_160;
      local_cc = local_12c;
      local_c4 = local_134;
      local_c8 = uVar6;
      fVar10 = World_objectFalloffWeight(puVar4,&local_c8,&local_d0);
      local_174 = (float)fVar10;
      if (0.25 < local_174) {
        if (local_174 < 1.0) {
          dVar11 = (double)local_174;
          libm_sse2_sqrt_precise();
          fVar12 = ((float)dVar11 - 0.5) * 2.0;
          fVar12 = 1.0 - fVar12 * fVar12;
          min_col = fVar12 * fVar12 * 10.0 + min_col;
          max_row = min_col;
        }
      }
      else {
        fVar12 = 1.0 - local_174 * 4.0;
        fVar12 = fVar12 * fVar12;
        min_col = (1.0 - fVar12) * (min_col + 10.0) + (min_col - 30.0) * fVar12;
        max_row = min_col;
      }
      if (min_col < local_144) {
        min_col = local_144;
        max_row = local_144;
      }
    }
    if (uVar7 == 0xd) {
      local_108 = (double)CONCAT44(local_12c,local_160);
      local_100 = (double)CONCAT44(local_134,uVar6);
      fVar10 = World_objectFalloffWeight(puVar4,(uint *)&local_100,(uint *)&local_108);
      local_174 = (float)fVar10;
      if (0.010000001 < local_174) {
        if (local_174 < 1.0) {
          dVar11 = (double)local_174;
          libm_sse2_sqrt_precise();
          fVar12 = ((float)dVar11 - 0.1) / 0.9;
          fVar12 = 1.0 - fVar12 * fVar12;
          max_row = fVar12 * fVar12 * fVar12 * fVar12 * 150.0 + min_col;
        }
      }
      else {
        max_row = min_col + 150.0;
      }
    }
  }
  __security_check_cookie(security_cookie ^ (uint)&local_174);
  return;
}




/* [AUDIT] proposed: World_generateRegionSite  (confidence: high)
 * purpose: Region-site generator: srand(regX+0x108a+regZ*0x400+base*3); fills 0x1c-byte site record
 * vars: 
 */
/* Global::World_generateRegionSite @ 0050b870 */

int * __thiscall World_generateRegionSite(void *this,int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  float fVar10;
  double dVar11;
  double dVar12;
  
  if ((((param_1 < 0) || (param_2 < 0)) || (0x3ff < param_1)) || (0x3ff < param_2)) {
    return (int *)0x0;
  }
  iVar1 = param_1 * 0x400 + param_2;
  piVar2 = *(int **)((int)this + iVar1 * 4 + 0x4000bc);
  if (piVar2 != (int *)0x0) {
    return piVar2;
  }
  srand(param_1 + 0x108a + param_2 * 0x400 + *(int *)((int)this + 0x800188) * 3);
  piVar2 = operator_new(0x1c);
  piVar2[5] = param_2 * 0x400 + param_1 + *(int *)((int)this + 0x800188);
  *(undefined1 *)(piVar2 + 2) = 0;
  iVar3 = (int)*(float *)((int)this + 0x8000f0) +
          ((int)*(float *)((int)this + 0x8000f0) >> 0x1f & 0xffU);
  if ((param_1 != (int)((iVar3 >> 8) + (iVar3 >> 0x1f & 0x3fU)) >> 6) ||
     (bVar7 = true,
     iVar3 = (int)*(float *)((int)this + 0x8000f4) +
             ((int)*(float *)((int)this + 0x8000f4) >> 0x1f & 0xffU),
     param_2 != (int)((iVar3 >> 8) + (iVar3 >> 0x1f & 0x3fU)) >> 6)) {
    bVar7 = false;
  }
  uVar4 = rand();
  uVar4 = uVar4 & 0x80000001;
  bVar6 = uVar4 == 0;
  if ((int)uVar4 < 0) {
    bVar6 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if ((bVar6) || (bVar7)) {
    iVar3 = rand();
    piVar2[3] = (int)(((float)iVar3 * 0.4) / 32767.0 + 0.3);
    iVar3 = rand();
    piVar2[4] = (int)(((float)iVar3 * 0.4) / 32767.0 + 0.4);
    if (bVar7) {
      iVar3 = (int)*(float *)((int)this + 0x8000f0);
      piVar2[1] = (int)*(float *)((int)this + 0x8000f4);
      goto LAB_0050bb29;
    }
    iVar3 = rand();
    if (iVar3 % 10 == 0) {
      *(undefined1 *)(piVar2 + 2) = 1;
      iVar3 = rand();
      piVar2[4] = (int)(((float)iVar3 * 0.2) / 32767.0 + 0.8);
      iVar3 = rand();
      piVar2[3] = (int)(((float)iVar3 * 0.5) / 32767.0);
    }
  }
  else {
    uVar4 = rand();
    uVar4 = uVar4 & 0x80000001;
    bVar6 = uVar4 == 0;
    if ((int)uVar4 < 0) {
      bVar6 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar6) {
      iVar3 = rand();
      fVar10 = ((float)iVar3 * 0.1) / 32767.0;
    }
    else {
      iVar3 = rand();
      fVar10 = ((float)iVar3 * 0.1) / 32767.0 + 0.9;
    }
    piVar2[3] = (int)fVar10;
    uVar4 = rand();
    uVar4 = uVar4 & 0x80000001;
    bVar6 = uVar4 == 0;
    if ((int)uVar4 < 0) {
      bVar6 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar6) {
      iVar3 = rand();
      piVar2[4] = (int)(((float)iVar3 * 0.1) / 32767.0);
    }
    else {
      iVar3 = rand();
      piVar2[4] = (int)(((float)iVar3 * 0.1) / 32767.0 + 0.9);
    }
  }
  iVar3 = rand();
  iVar5 = rand();
  piVar2[1] = param_2 * 0x4000 + iVar3 % 0x3c00 + 0x200;
  iVar3 = param_1 * 0x4000 + 0x200 + iVar5 % 0x3c00;
LAB_0050bb29:
  *piVar2 = iVar3;
  *piVar2 = (iVar3 + (iVar3 >> 0x1f & 0x7ffU) & 0xfffff800) + 0x400;
  piVar2[1] = (piVar2[1] + (piVar2[1] >> 0x1f & 0x7ffU) & 0xfffff800) + 0x400;
  dVar12 = (double)*(int *)((int)this + 0x800188);
  dVar11 = (double)param_1 * 1.4 + dVar12;
  fVar8 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                       (double)param_2 * 1.4 + dVar12 + 843.0);
  dVar11 = (double)param_1 * 4.0 + dVar12;
  fVar9 = valueNoise2D(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20),
                       (double)param_2 * 4.0 + dVar12 + 843.0);
  iVar3 = (int)((((float)fVar8 + 1.0) * 100.0 - 70.0) + (float)fVar9 * 30.0);
  piVar2[6] = iVar3;
  if (iVar3 < 1) {
    *(undefined1 *)(piVar2 + 2) = 0;
    if (bVar7) {
      iVar3 = rand();
      piVar2[6] = iVar3 % 0x32 + 0x14;
      *(int **)((int)this + iVar1 * 4 + 0x4000bc) = piVar2;
      return piVar2;
    }
    piVar2[6] = piVar2[6] + -100;
    iVar3 = piVar2[6];
    if (iVar3 < -100) {
      iVar3 = -100;
    }
    piVar2[6] = iVar3;
    uVar4 = rand();
    uVar4 = uVar4 & 0x80000001;
    bVar7 = uVar4 == 0;
    if ((int)uVar4 < 0) {
      bVar7 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar7) {
      iVar3 = rand();
      piVar2[3] = (int)(((float)iVar3 * 0.1) / 32767.0 + 0.9);
      iVar3 = rand();
      fVar10 = ((float)iVar3 * 0.1) / 32767.0 + 0.9;
    }
    else {
      iVar3 = rand();
      piVar2[3] = (int)(((float)iVar3 * 0.4) / 32767.0 + 0.3);
      iVar3 = rand();
      fVar10 = ((float)iVar3 * 0.4) / 32767.0 + 0.4;
    }
    piVar2[4] = (int)fVar10;
  }
  *(int **)((int)this + iVar1 * 4 + 0x4000bc) = piVar2;
  return piVar2;
}




/* [AUDIT] proposed: World_generateRegionFeatures  (confidence: high)
 * purpose: Per-region 8x8=64 feature-cell generator: srand(base+regZ*0x400+regX) then multi-pass placement
 * vars: mislabeled std::basic_stringbuf::ctor_1 by Ghidra ns
 */
/* World_generateRegionFeatures @ 0050e080 */
/* NOTE(re) 2026-07-21: RECLASSIFIED lib->game (World). Mislabeled std::basic_stringbuf<char>::ctor_1 by Ghidra namespace attribution; actually the per-region 8x8=64 feature-cell generator: srand(base+regZ*0x400+regX) then multi-pass placement. Renamed World_generateRegionFeatures (gap audit, high confidence; commit 7fa4843). */

/* WARNING: Removing unreachable block (ram,0x0050eac3) */

void __thiscall
World_generateRegionFeatures
          (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this,int param_1,
          int param_2)

{
  float *pfVar1;
  uint *puVar2;
  longlong lVar3;
  float *pfVar4;
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this_00;
  char cVar5;
  uint uVar6;
  uint *puVar7;
  float *pfVar8;
  basic_ostream<char,std::char_traits<char>_> *pbVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 extraout_ECX;
  float *pfVar13;
  uint uVar14;
  undefined4 extraout_EDX;
  int iVar15;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar16;
  undefined4 *puVar17;
  int iVar18;
  uint uVar19;
  undefined **ppuVar20;
  code *pcVar21;
  float fVar22;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar23;
  int iVar24;
  uint uVar25;
  float fVar26;
  undefined4 *puVar27;
  float10 fVar28;
  double dVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  char *in_stack_fffffcac;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar33;
  char *pcVar34;
  float fVar35;
  undefined1 auStack_324 [4];
  int iStack_320;
  float local_318;
  undefined4 local_314;
  float local_310;
  uint local_30c;
  undefined4 *local_308;
  char cStack_301;
  float local_300;
  undefined **local_2fc;
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *local_2f8;
  uint local_2f4;
  undefined4 *local_2f0;
  undefined **local_2ec;
  double local_2e8;
  float *local_2dc;
  int local_2d8;
  int local_2d4;
  uint *local_2d0;
  undefined **local_2cc;
  uint local_2c8;
  float *local_2c4;
  float *local_2c0;
  undefined4 local_2bc;
  int *local_2b8;
  int *local_2b4;
  int *local_2b0;
  int local_2ac;
  undefined **local_2a8;
  uint local_2a4;
  float local_2a0;
  float local_29c;
  basic_ostream<char,struct_std::char_traits<char>_> *local_298;
  basic_ostream<char,struct_std::char_traits<char>_> *local_294;
  basic_ostream<char,struct_std::char_traits<char>_> *local_290;
  float local_28c;
  float local_288;
  float local_284;
  float local_280;
  float local_27c;
  float local_278;
  int local_274;
  float local_270;
  uint local_26c;
  float local_268;
  uint local_264;
  void *pvStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  float local_240;
  uint local_23c;
  double local_238;
  undefined8 local_230;
  undefined **local_228;
  uint local_224;
  int local_21c;
  undefined **appuStack_218 [2];
  undefined **appuStack_210 [4];
  undefined **appuStack_200 [2];
  basic_iostream<char,std::char_traits<char>_> abStack_1f8 [4];
  undefined4 *puStack_1f4;
  undefined4 *puStack_1f0;
  undefined4 *puStack_1e0;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 *puStack_1d0;
  undefined4 uStack_1c8;
  uint uStack_1c4;
  code *pcStack_1c0;
  basic_ios<char,std::char_traits<char>_> abStack_1b0 [36];
  int iStack_18c;
  undefined **appuStack_188 [3];
  int iStack_17c;
  undefined **appuStack_178 [2];
  undefined **appuStack_170 [4];
  undefined **appuStack_160 [2];
  basic_iostream<char,std::char_traits<char>_> local_158 [4];
  undefined4 *puStack_154;
  undefined4 *local_150;
  undefined4 *puStack_140;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 *puStack_130;
  undefined4 uStack_128;
  uint uStack_124;
  code *pcStack_120;
  basic_ios<char,std::char_traits<char>_> abStack_110 [76];
  undefined1 auStack_c4 [28];
  undefined1 auStack_a8 [12];
  int local_9c;
  float fStack_98;
  float local_94;
  int iStack_90;
  int local_8c;
  int iStack_88;
  float local_84;
  float local_80;
  int iStack_7c;
  undefined **local_78;
  int iStack_74;
  undefined **local_70;
  uint uStack_6c;
  float local_68;
  undefined **local_64;
  int iStack_60;
  void *local_5c;
  float local_58;
  uint local_54;
  uint local_50;
  uint uStack_48;
  void *apvStack_34 [2];
  undefined4 uStack_2c;
  uint uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00555c01;
  local_14 = ExceptionList;
  local_1c = DAT_00583cc8 ^ (uint)auStack_324;
  ExceptionList = &local_14;
  local_2d4 = param_1;
  local_2d8 = param_2;
  local_278 = 0.0;
  local_2f8 = this;
  if ((((-1 < param_1) && (-1 < param_2)) && (param_1 < 0x400)) &&
     ((param_2 < 0x400 &&
      (local_274 = param_1 * 0x400 + param_2, *(int *)(this + local_274 * 4 + 0xbc) == 0)))) {
    iVar24 = -2;
    do {
      iVar18 = -2;
      do {
        World_generateRegionSite(this,local_2d4 + iVar24,local_2d8 + iVar18);
        iVar15 = local_2d8;
        iVar18 = iVar18 + 1;
      } while (iVar18 < 3);
      iVar24 = iVar24 + 1;
    } while (iVar24 < 3);
    srand(*(int *)(this + 0x800188) + local_2d8 * 0x400 + local_2d4);
    local_308 = operator_new(0x15a28);
    local_c = 0;
    if (local_308 == (undefined4 *)0x0) {
      local_2f0 = (undefined4 *)0x0;
    }
    else {
      local_2f0 = cube::Region::ctor_0(local_308);
    }
    puVar17 = local_2f0;
    local_c = 0xffffffff;
    iVar24 = World_featureTier(local_2d4,iVar15);
    pcVar21 = rand_exref;
    puVar17[3] = iVar24;
    puVar17[4] = 0;
    if (4 < iVar24) {
      iVar24 = rand();
      puVar17[4] = iVar24 % 5;
    }
    uVar6 = rand();
    uVar6 = uVar6 & 0x80000003;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
    }
    puVar17[5] = uVar6;
    local_2ac = rand();
    local_2ac = local_2ac % 10000;
    puVar7 = *(uint **)(this + local_274 * 4 + 0x4000bc);
    local_2d0 = puVar7;
    if (0.81 < (float)puVar7[4]) {
      uVar6 = rand();
      uVar6 = uVar6 & 0x80000001;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
      }
      puVar17[5] = uVar6 + 4;
    }
    local_310 = 1.4013e-45;
    World_featureCountRange(puVar7,&local_310,&local_21c);
    local_2c4 = (float *)0x0;
    local_2c0 = (float *)0x0;
    local_2bc = 0;
    local_54 = *puVar7;
    local_50 = puVar7[1];
    local_c = 1;
    local_228 = (undefined **)
                ((int)(((int)local_54 >> 0x1f & 0x7ffU) + local_54) >> 0xb & 0x80000007);
    if ((int)local_228 < 0) {
      local_228 = (undefined **)(((int)local_228 - 1U | 0xfffffff8) + 1);
    }
    uStack_6c = (int)(local_50 + ((int)local_50 >> 0x1f & 0x7ffU)) >> 0xb & 0x80000007;
    if ((int)uStack_6c < 0) {
      uStack_6c = (uStack_6c - 1 | 0xfffffff8) + 1;
    }
    local_230 = (double)CONCAT44(local_230._4_4_,uStack_6c);
    local_300 = (float)(local_2d8 << 0xe);
    local_2c8 = local_2d4 * 0x4000;
    local_2fc = (undefined **)0x0;
    local_314 = local_2c8 + 0x800;
    local_2a8 = (undefined **)0x0;
    pfVar8 = (float *)(puVar17 + 0x500a);
    local_70 = local_228;
    do {
      local_2f4 = (int)local_300 + 0x800;
      local_30c = 0;
      local_2ec = (undefined **)0x0;
      do {
        puVar7 = local_2d0;
        local_2dc = pfVar8;
        if (((*(int *)(local_2f8 + 0xa4) == 0) || (local_2fc != local_228)) ||
           (local_30c != (int)local_230)) {
          puVar7 = (uint *)World_findNearestEntityInRegion(local_2f8,local_314 - 0x400,local_2f4 - 0x400);
          if (puVar7 == local_2d0) {
            uVar6 = (*pcVar21)();
            uVar6 = uVar6 & 0x800000ff;
            if ((int)uVar6 < 0) {
              uVar6 = (uVar6 - 1 | 0xffffff00) + 1;
            }
            iVar24 = (int)local_300 >> 0x1f;
            *pfVar8 = (float)(int)(uVar6 + 0x200);
            local_280 = (float)(int)(uVar6 + 0x200) * 65536.0;
            iVar18 = (int)local_2ec >> 0x1f;
            uVar6 = (uint)local_300 >> 0x10;
            uVar19 = (uint)local_2ec >> 0x10;
            uVar14 = (int)local_300 * 0x10000;
            uVar25 = (int)local_2ec * 0x10000;
            uVar30 = ftol2();
            lVar3 = uVar30 + CONCAT44((iVar18 << 0x10 | uVar19) + (iVar24 << 0x10 | uVar6) +
                                      (uint)CARRY4(uVar25,uVar14),uVar25 + uVar14) + 0x1000000;
            local_2a0 = (float)((ulonglong)lVar3 >> 0x20);
            local_318 = *local_2dc + 256.0;
            iVar24 = rand();
            local_288 = (((float)iVar24 * (2048.0 - local_318 * 2.0)) / 32767.0) * 65536.0;
            uVar30 = ftol2();
            local_29c = local_318 * 65536.0;
            lVar3 = uVar30 + CONCAT44(local_2a0,(int)lVar3);
            local_308 = (undefined4 *)((ulonglong)lVar3 >> 0x20);
            local_2e8 = (double)CONCAT44(local_2e8._4_4_,(int)lVar3);
            iVar24 = (int)local_2c8 >> 0x1f;
            iVar18 = (int)local_2a8 >> 0x1f;
            uVar6 = local_2c8 >> 0x10;
            uVar19 = (uint)local_2a8 >> 0x10;
            uVar14 = local_2c8 * 0x10000;
            uVar25 = (int)local_2a8 * 0x10000;
            uVar30 = ftol2();
            pcVar21 = rand_exref;
            lVar3 = uVar30 + CONCAT44((iVar18 << 0x10 | uVar19) + (iVar24 << 0x10 | uVar6) +
                                      (uint)CARRY4(uVar25,uVar14),uVar25 + uVar14);
            local_2a0 = (float)((ulonglong)lVar3 >> 0x20);
            iVar24 = rand();
            pfVar8 = local_2dc;
            local_2cc = (undefined **)
                        ((((float)iVar24 * (2048.0 - (*local_2dc + 256.0) * 2.0)) / 32767.0) *
                        65536.0);
            uVar30 = ftol2();
            *(ulonglong *)(pfVar8 + -4) = uVar30 + CONCAT44(local_2a0,(int)lVar3);
            pfVar8[-2] = local_2e8._0_4_;
            pfVar8[-1] = (float)local_308;
            uVar31 = __alldiv((uint)local_2e8._0_4_,(uint)local_308,0x10000,0);
            uVar32 = __alldiv((uint)pfVar8[-4],(uint)pfVar8[-3],0x10000,0);
            fVar28 = (float10)World_baseHeightField(local_2f8,(uint)uVar32,(float)uVar31,0);
            pfVar8[1] = (float)fVar28;
            pfVar8[5] = local_310;
            uVar31 = __alldiv((uint)pfVar8[-2],(uint)pfVar8[-1],0x10000,0);
            uVar32 = __alldiv((uint)pfVar8[-4],(uint)pfVar8[-3],0x10000,0);
            puVar7 = (uint *)World_findNearestEntityInRegion(local_2f8,(int)uVar32,(int)uVar31);
            uVar6 = local_30c;
            if (puVar7 == local_2d0) {
              local_5c = (void *)(float)((int)local_70 - (int)local_2fc);
              local_58 = (float)(int)(uStack_6c - local_30c);
              _local_8c = CONCAT44(uStack_6c - local_30c,(int)local_70 - (int)local_2fc);
              dVar29 = (double)(local_58 * local_58 + (float)local_5c * (float)local_5c);
              libm_sse2_sqrt_precise();
              local_308 = (undefined4 *)(float)dVar29;
              iVar24 = rand();
              local_78 = local_2fc;
              iStack_74 = uVar6;
              local_68 = (((float)iVar24 * 4.0) / 32767.0 + (float)local_308) - 2.0;
              local_64 = local_2fc;
              iStack_60 = uVar6;
              FUN_005286a0(&local_2c4,&local_68);
            }
          }
        }
        else {
          pfVar8[2] = 1.4013e-45;
          pfVar8[3] = (float)local_2f0[5];
          pfVar8[4] = (float)local_2d0[5];
          iVar24 = (*pcVar21)();
          *pfVar8 = (float)(iVar24 % 200 + 0x200);
          uVar6 = *puVar7;
          pfVar8[-4] = (float)(uVar6 << 0x10);
          pfVar8[-3] = (float)(((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10);
          uVar6 = puVar7[1];
          pfVar8[-2] = (float)(uVar6 << 0x10);
          pfVar8[-1] = (float)(((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10);
          local_238 = (double)CONCAT44(local_238._4_4_,*pfVar8 * 65536.0);
          uVar30 = ftol2();
          uVar19 = (int)pfVar8[-4] - (int)(float)uVar30;
          iVar24 = (((int)pfVar8[-3] - (int)(uVar30 >> 0x20)) -
                   (uint)((uint)pfVar8[-4] < (uint)(float)uVar30)) - (uint)(uVar19 < 0x1000000);
          local_318 = (float)(local_314 - 0x800);
          uVar6 = ((int)local_318 >> 0x1f) << 0x10 | (uint)local_318 >> 0x10;
          if ((iVar24 <= (int)uVar6) &&
             ((iVar24 < (int)uVar6 || (uVar19 - 0x1000000 < (uint)((int)local_318 * 0x10000))))) {
            local_240 = ((float)(int)local_318 + *pfVar8 + 256.0) * 65536.0;
            uVar30 = ftol2();
            *(ulonglong *)(pfVar8 + -4) = uVar30;
          }
          local_270 = *pfVar8 * 65536.0;
          uVar30 = ftol2();
          uVar19 = local_2f4;
          uVar6 = (int)pfVar8[-2] - (int)(float)uVar30;
          local_318 = (float)(uVar6 - 0x1000000);
          iVar24 = (((int)pfVar8[-1] - (int)(uVar30 >> 0x20)) -
                   (uint)((uint)pfVar8[-2] < (uint)(float)uVar30)) - (uint)(uVar6 < 0x1000000);
          uVar6 = local_2f4 - 0x800;
          uVar14 = ((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10;
          if ((iVar24 <= (int)uVar14) &&
             ((iVar24 < (int)uVar14 || ((uint)local_318 < uVar6 * 0x10000)))) {
            local_268 = ((float)(int)(local_2f4 - 0x800) + *pfVar8 + 256.0) * 65536.0;
            uVar30 = ftol2();
            *(ulonglong *)(pfVar8 + -2) = uVar30;
          }
          local_94 = *pfVar8 * 65536.0;
          uVar30 = ftol2();
          uVar6 = (uint)uVar30 + (int)pfVar8[-4];
          local_318 = (float)(uVar6 + 0x1000000);
          iVar24 = (int)(uVar30 >> 0x20) + (int)pfVar8[-3] +
                   (uint)CARRY4((uint)uVar30,(uint)pfVar8[-4]) + (uint)(0xfeffffff < uVar6);
          uVar6 = ((int)local_314 >> 0x1f) << 0x10 | local_314 >> 0x10;
          if (((int)uVar6 <= iVar24) &&
             (((int)uVar6 < iVar24 || (local_314 << 0x10 < (uint)local_318)))) {
            local_27c = (((float)(int)local_314 - *pfVar8) - 256.0) * 65536.0;
            uVar30 = ftol2();
            *(ulonglong *)(pfVar8 + -4) = uVar30;
          }
          local_28c = *pfVar8 * 65536.0;
          uVar30 = ftol2();
          uVar6 = (uint)uVar30 + (int)pfVar8[-2];
          local_318 = (float)(uVar6 + 0x1000000);
          iVar24 = (int)(uVar30 >> 0x20) + (int)pfVar8[-1] +
                   (uint)CARRY4((uint)uVar30,(uint)pfVar8[-2]) + (uint)(0xfeffffff < uVar6);
          uVar6 = ((int)uVar19 >> 0x1f) << 0x10 | uVar19 >> 0x10;
          if (((int)uVar6 <= iVar24) &&
             (((int)uVar6 < iVar24 || (uVar19 << 0x10 < (uint)local_318)))) {
            local_284 = (((float)(int)uVar19 - *pfVar8) - 256.0) * 65536.0;
            uVar30 = ftol2();
            *(ulonglong *)(pfVar8 + -2) = uVar30;
          }
          uVar31 = __alldiv((uint)pfVar8[-2],(uint)pfVar8[-1],0x10000,0);
          uVar32 = __alldiv((uint)pfVar8[-4],(uint)pfVar8[-3],0x10000,0);
          fVar28 = (float10)World_baseHeightField(local_2f8,(uint)uVar32,(float)uVar31,0);
          local_318 = (float)fVar28;
          pfVar8[1] = local_318;
          if (local_318 < 0.0) {
            pfVar8[1] = 0.0;
          }
        }
        local_2ec = (undefined **)((int)local_2ec + 0x800);
        local_30c = local_30c + 1;
        pfVar8 = pfVar8 + 0x1a;
        local_2f4 = local_2f4 + 0x800;
      } while ((int)local_2ec < 0x4000);
      local_2fc = (undefined **)((int)local_2fc + 1);
      local_2a8 = local_2a8 + 0x200;
      local_314 = local_314 + 0x800;
    } while ((int)local_2a8 < 0x4000);
    local_308 = (undefined4 *)((uint)local_308 & 0xffffff00);
    local_2dc = pfVar8;
    FUN_004f5cc0(local_2c4,local_2c0,((int)local_2c0 - (int)local_2c4) / 0xc,local_308);
    local_30c = 0;
    pfVar8 = local_2c4;
    pfVar13 = local_2c0;
    do {
      puVar17 = local_2f0;
      uVar6 = local_30c;
      if (pfVar8 == pfVar13) break;
      if ((local_30c & 1) != 0) goto LAB_0050f27c;
      local_2cc = (undefined **)pfVar8[1];
      fVar22 = pfVar8[2];
      pfVar1 = pfVar8 + 1;
      local_2e8 = (double)CONCAT44(local_2e8._4_4_,fVar22);
      pfVar4 = pfVar13;
      while (pfVar8 = pfVar8 + 3, pfVar8 != pfVar13) {
        pfVar1[-1] = *pfVar8;
        *pfVar1 = pfVar8[1];
        pfVar1[1] = pfVar8[2];
        pfVar1 = pfVar1 + 3;
        pfVar4 = local_2c0;
      }
      iVar24 = (int)fVar22 + (int)local_2cc * 8;
      uVar19 = iVar24 * 0x68;
      local_2c0 = pfVar4 + -3;
      if ((float)local_2f0[iVar24 * 0x1a + 0x500b] <= 0.0 &&
          (float)local_2f0[iVar24 * 0x1a + 0x500b] != 0.0) {
        local_2f0[iVar24 * 0x1a + 0x500b] = 0;
      }
      local_314 = uVar19;
      formula_inverse((float)(int)local_30c * 0.015625);
      uVar30 = FUN_0054a910(extraout_ECX,extraout_EDX);
      puVar17[iVar24 * 0x1a + 0x500f] = (int)uVar30;
      pcVar21 = rand_exref;
      if ((uVar6 >> 1 & 0x80000001) != 0) {
        puVar17[iVar24 * 0x1a + 0x500c] = 0xe;
        puVar17[iVar24 * 0x1a + 0x500a] = 0x43160000;
        uVar31 = __alldiv(puVar17[iVar24 * 0x1a + 0x5008],puVar17[iVar24 * 0x1a + 0x5009],0x10000,0)
        ;
        uVar6 = ((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU) & 0xffffff00) + 0x80;
        uVar14 = ((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10;
        local_240 = (float)(uVar6 * 0x10000);
        local_23c = uVar14;
        uVar31 = __alldiv(*(uint *)(local_314 + 0x14018 + (int)puVar17),
                          *(uint *)(local_314 + 0x1401c + (int)puVar17),0x10000,0);
        uVar19 = ((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU) & 0xffffff00) + 0x80;
        *(uint *)(local_314 + 0x1401c + (int)puVar17) =
             ((int)uVar19 >> 0x1f) << 0x10 | uVar19 >> 0x10;
        *(uint *)(local_314 + 0x14018 + (int)puVar17) = uVar19 * 0x10000;
        *(uint *)(local_314 + 0x14020 + (int)puVar17) = uVar6 * 0x10000;
        *(uint *)(local_314 + 0x14024 + (int)puVar17) = uVar14;
        local_2e8 = (double)*(longlong *)(local_314 + 0x14018 + (int)puVar17);
        local_238 = local_2e8 * 0.00390625;
        uVar30 = ftol2();
        uVar31 = __alldiv((uint)uVar30,(uint)(uVar30 >> 0x20),0x10000,0);
        uVar6 = (uint)uVar31 & 0x8000003f;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
        }
        local_2e8 = (double)*(longlong *)(local_314 + 0x14020 + (int)puVar17);
        local_230 = local_2e8 * 0.00390625;
        uVar30 = ftol2();
        uVar31 = __alldiv((uint)uVar30,(uint)(uVar30 >> 0x20),0x10000,0);
        uVar19 = (uint)uVar31 & 0x8000003f;
        if ((int)uVar19 < 0) {
          uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
        }
        local_29c = (float)(uVar6 * 0x40 + uVar19);
        local_2fc = (undefined **)((int)local_29c * 0x10);
        *(undefined1 *)((int)(local_2fc + 6) + (int)puVar17) = 3;
        uVar14 = rand();
        this_00 = local_2f8;
        uVar14 = uVar14 & 0x80000003;
        if ((int)uVar14 < 0) {
          uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
        }
        *(char *)((int)local_2fc + 0x19 + (int)puVar17) = (char)uVar14;
        local_2cc = (undefined **)((local_2d4 * 0x40 + uVar6) * 0x100 + 0x80);
        uVar6 = (local_2d8 * 0x40 + uVar19) * 0x100 + 0x80;
        fVar28 = (float10)World_humidityBlend(local_2f8,(int)local_2cc,uVar6);
        local_2e8 = (double)CONCAT44(local_2e8._4_4_,(float)fVar28);
        if (0.8 < (float)fVar28) {
          fVar28 = (float10)World_temperatureBlend(this_00,(float)local_2cc,uVar6);
          local_2e8 = (double)CONCAT44(local_2e8._4_4_,(float)fVar28);
          *(char *)((int)local_2fc + 0x19 + (int)puVar17) = ((float)fVar28 <= 0.8) + '\x04';
        }
        iVar24 = rand();
        uVar6 = local_314;
        *(int *)((int)(local_2fc + 7) + (int)puVar17) = iVar24 % 10000000 + 1;
        puVar17[((int)local_29c + 2) * 4] = *(undefined4 *)(local_314 + 0x1403c + (int)puVar17);
        *(int *)(local_314 + 0x14038 + (int)puVar17) = local_2ac;
        iVar24 = rand();
        local_2ac = local_2ac + 1 + iVar24 % 0x32;
        *(uint *)(uVar6 + 0x14034 + (int)puVar17) =
             (uint)*(byte *)((int)local_2fc + 0x19 + (int)puVar17);
        iVar24 = *(int *)(uVar6 + 0x1403c + (int)puVar17);
        if (iVar24 < 5) {
          *(undefined1 *)((int)(local_2fc + 9) + (int)puVar17) = 0;
          pfVar8 = local_2c4;
          pfVar13 = local_2c0;
        }
        else if (iVar24 < 10) {
          uVar6 = rand();
          uVar6 = uVar6 & 0x80000001;
          if ((int)uVar6 < 0) {
            *(byte *)((int)(local_2fc + 9) + (int)puVar17) = ((char)uVar6 - 1U | 0xfe) + 1;
            pfVar8 = local_2c4;
            pfVar13 = local_2c0;
          }
          else {
LAB_0050edc0:
            *(char *)((int)(local_2fc + 9) + (int)puVar17) = (char)uVar6;
            pfVar8 = local_2c4;
            pfVar13 = local_2c0;
          }
        }
        else if (iVar24 < 0xf) {
          iVar24 = rand();
          *(char *)((int)(local_2fc + 9) + (int)puVar17) = (char)(iVar24 % 3);
          pfVar8 = local_2c4;
          pfVar13 = local_2c0;
        }
        else {
          if (0x12 < iVar24) {
            uVar6 = rand();
            uVar6 = uVar6 & 0x80000003;
            if ((int)uVar6 < 0) {
              uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
            }
            uVar6 = uVar6 + 1;
            goto LAB_0050edc0;
          }
          iVar24 = rand();
          *(char *)((int)(local_2fc + 9) + (int)puVar17) = (char)(iVar24 % 3) + '\x01';
          pfVar8 = local_2c4;
          pfVar13 = local_2c0;
        }
        goto LAB_0050f27c;
      }
      uVar6 = rand();
      uVar6 = uVar6 & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      switch(uVar6) {
      case 0:
        puVar17[iVar24 * 0x1a + 0x500c] = 2;
        break;
      case 1:
        puVar17[iVar24 * 0x1a + 0x500c] = 3;
        iVar18 = rand();
        puVar17[iVar24 * 0x1a + 0x500d] = iVar18 % 3;
        break;
      case 2:
        uVar11 = 4;
        goto LAB_0050ee27;
      case 3:
        puVar17[iVar24 * 0x1a + 0x500c] = 5;
        if ((float)local_2d0[4] <= 0.8) {
LAB_0050ee95:
          puVar17[iVar24 * 0x1a + 0x500d] = 0;
        }
        else if ((float)local_2d0[3] <= 0.8) {
          if (0.2 <= (float)local_2d0[3]) goto LAB_0050ee95;
          puVar17[iVar24 * 0x1a + 0x500d] = 2;
        }
        else {
          puVar17[iVar24 * 0x1a + 0x500d] = 3;
        }
        uVar6 = rand();
        uVar6 = uVar6 & 0x800000ff;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xffffff00) + 1;
        }
        iVar15 = (int)local_300 >> 0x1f;
        iVar18 = (int)local_2e8._0_4_ << 0xb;
        puVar17[iVar24 * 0x1a + 0x500a] = (float)(int)(uVar6 + 0x100);
        local_2a0 = (float)(int)(uVar6 + 0x100) * 65536.0;
        uVar6 = (uint)local_300 >> 0x10;
        uVar19 = (uint)local_2e8._0_4_ & 0x1fffff;
        uVar14 = (int)local_300 * 0x10000;
        uVar25 = (int)local_2e8._0_4_ * 0x8000000;
        uVar30 = ftol2();
        lVar3 = uVar30 + CONCAT44(((iVar18 >> 0x1f) << 0x10 | uVar19 >> 5) +
                                  (iVar15 << 0x10 | uVar6) + (uint)CARRY4(uVar25,uVar14),
                                  uVar25 + uVar14) + 0x1000000;
        local_318 = *(float *)(local_314 + 0x14028 + (int)local_2f0) + 256.0;
        local_2e8._0_4_ = (float)(int)((ulonglong)lVar3 >> 0x20);
        iVar24 = rand();
        local_288 = (((float)iVar24 * (2048.0 - local_318 * 2.0)) / 32767.0) * 65536.0;
        uVar30 = ftol2();
        local_280 = local_318 * 65536.0;
        lVar3 = uVar30 + CONCAT44(local_2e8._0_4_,(int)lVar3);
        local_29c = (float)lVar3;
        local_28c = (float)((ulonglong)lVar3 >> 0x20);
        iVar18 = (int)local_2c8 >> 0x1f;
        iVar24 = (int)local_2cc << 0xb;
        uVar6 = local_2c8 >> 0x10;
        uVar19 = (uint)local_2cc & 0x1fffff;
        uVar14 = local_2c8 * 0x10000;
        uVar25 = (int)local_2cc * 0x8000000;
        uVar30 = ftol2();
        lVar3 = uVar30 + CONCAT44(((iVar24 >> 0x1f) << 0x10 | uVar19 >> 5) +
                                  (iVar18 << 0x10 | uVar6) + (uint)CARRY4(uVar25,uVar14),
                                  uVar25 + uVar14);
        uVar6 = (uint)lVar3;
        local_2e8 = (double)CONCAT44(local_2e8._4_4_,(int)((ulonglong)lVar3 >> 0x20));
        iVar24 = rand();
        puVar17 = local_2f0;
        uVar19 = local_314;
        local_284 = (((float)iVar24 *
                     (2048.0 - (*(float *)(local_314 + 0x14028 + (int)local_2f0) + 256.0) * 2.0)) /
                    32767.0) * 65536.0;
        uVar30 = ftol2();
        *(uint *)(uVar19 + 0x14018 + (int)puVar17) = (uint)uVar30 + uVar6;
        *(float *)(uVar19 + 0x14020 + (int)puVar17) = local_29c;
        *(uint *)(uVar19 + 0x1401c + (int)puVar17) =
             (int)(uVar30 >> 0x20) + (int)local_2e8._0_4_ + (uint)CARRY4((uint)uVar30,uVar6);
        *(float *)(uVar19 + 0x14024 + (int)puVar17) = local_28c;
        pcVar21 = rand_exref;
        break;
      case 4:
        uVar11 = 6;
LAB_0050ee27:
        if ((int)local_2d0[6] < 0) {
          uVar11 = 0xf;
        }
        puVar17[iVar24 * 0x1a + 0x500c] = uVar11;
        break;
      case 5:
        puVar17[iVar24 * 0x1a + 0x500c] = (uint)((int)local_2d0[6] < 0) * 8 + 7;
        break;
      case 6:
        puVar17[iVar24 * 0x1a + 0x500c] = 0xb;
        puVar17[iVar24 * 0x1a + 0x500a] = 0x43000000;
        uVar31 = __alldiv(puVar17[iVar24 * 0x1a + 0x5008],puVar17[iVar24 * 0x1a + 0x5009],0x10000,0)
        ;
        uVar6 = ((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU) & 0xffffff00) + 0x80;
        uVar19 = ((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10;
        ppuVar20 = (undefined **)(uVar6 * 0x10000);
        local_228 = ppuVar20;
        local_224 = uVar19;
        goto LAB_0050f173;
      case 7:
        puVar17[iVar24 * 0x1a + 0x500c] = 0xc;
        puVar17[iVar24 * 0x1a + 0x500a] = 0x43000000;
        uVar31 = __alldiv(puVar17[iVar24 * 0x1a + 0x5008],puVar17[iVar24 * 0x1a + 0x5009],0x10000,0)
        ;
        uVar6 = ((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU) & 0xffffff00) + 0x80;
        uVar19 = ((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10;
        ppuVar20 = (undefined **)(uVar6 * 0x10000);
        local_2a8 = ppuVar20;
        local_2a4 = uVar19;
LAB_0050f173:
        uVar31 = __alldiv(*(uint *)(local_314 + 0x14018 + (int)puVar17),
                          *(uint *)(local_314 + 0x1401c + (int)puVar17),0x10000,0);
        uVar6 = ((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU) & 0xffffff00) + 0x80;
        *(uint *)(local_314 + 0x14018 + (int)puVar17) = uVar6 * 0x10000;
        *(uint *)(local_314 + 0x1401c + (int)puVar17) = ((int)uVar6 >> 0x1f) << 0x10 | uVar6 >> 0x10
        ;
        *(uint *)(local_314 + 0x14024 + (int)puVar17) = uVar19;
        *(undefined ***)(local_314 + 0x14020 + (int)puVar17) = ppuVar20;
        pcVar21 = rand_exref;
        uVar19 = local_314;
      }
      iVar24 = *(int *)(uVar19 + 0x1403c + (int)puVar17);
      if (iVar24 < 5) {
        *(undefined4 *)(uVar19 + 0x14040 + (int)puVar17) = 0;
      }
      else if (iVar24 < 10) {
        uVar6 = (*pcVar21)();
        uVar6 = uVar6 & 0x80000001;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
        }
LAB_0050f240:
        *(uint *)(uVar19 + 0x14040 + (int)puVar17) = uVar6;
      }
      else if (iVar24 < 0xf) {
        iVar24 = (*pcVar21)();
        *(int *)(uVar19 + 0x14040 + (int)puVar17) = iVar24 % 3;
      }
      else {
        if (0x12 < iVar24) {
          uVar6 = (*pcVar21)();
          uVar6 = uVar6 & 0x80000003;
          if ((int)uVar6 < 0) {
            uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
          }
          uVar6 = uVar6 + 1;
          goto LAB_0050f240;
        }
        iVar24 = (*pcVar21)();
        *(int *)(uVar19 + 0x14040 + (int)puVar17) = iVar24 % 3 + 1;
      }
      *(int *)(uVar19 + 0x14038 + (int)puVar17) = local_2ac;
      iVar24 = (*pcVar21)();
      local_2ac = local_2ac + 1 + iVar24 % 0x32;
      pfVar8 = local_2c4;
      pfVar13 = local_2c0;
LAB_0050f27c:
      local_30c = local_30c + 1;
    } while ((int)local_30c < 0x40);
    puVar17 = local_2f0;
    local_310 = 0.0;
    do {
      if (pfVar8 == pfVar13) break;
      uVar6 = rand();
      uVar6 = uVar6 % (uint)(((int)pfVar13 - (int)pfVar8) / 0xc);
      local_308 = (undefined4 *)local_2c4[uVar6 * 3 + 2];
      fVar22 = local_2c4[uVar6 * 3 + 1];
      pfVar8 = local_2c4 + uVar6 * 3 + 3;
      if (pfVar8 != local_2c0) {
        pfVar13 = pfVar8 + -2;
        do {
          pfVar13[-1] = *pfVar8;
          *pfVar13 = pfVar13[3];
          pfVar8 = pfVar8 + 3;
          pfVar13[1] = pfVar13[4];
          pfVar13 = pfVar13 + 3;
        } while (pfVar8 != local_2c0);
      }
      local_2c0 = local_2c0 + -3;
      iVar24 = (int)local_308 + (int)fVar22 * 8;
      puVar17[iVar24 * 0x1a + 0x500c] = 10;
      iVar18 = rand();
      puVar17[iVar24 * 0x1a + 0x500e] = iVar18 % 10000000 + 1;
      uVar31 = __alldiv(puVar17[iVar24 * 0x1a + 0x5006],puVar17[iVar24 * 0x1a + 0x5007],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar17[iVar24 * 0x1a + 0x5008],puVar17[iVar24 * 0x1a + 0x5009],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      iVar18 = uVar6 * 0x40 + uVar19;
      local_310 = (float)((int)local_310 + 1);
      *(undefined1 *)(puVar17 + iVar18 * 4 + 6) = 4;
      puVar17[iVar18 * 4 + 7] = puVar17[iVar24 * 0x1a + 0x500e];
      pfVar8 = local_2c4;
      pfVar13 = local_2c0;
    } while ((int)local_310 < 5);
    puVar7 = puVar17 + 0x5008;
    local_310 = 1.12104e-44;
    do {
      uVar31 = __alldiv(puVar7[-2],puVar7[-1],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(*puVar7,puVar7[1],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[7];
      uVar31 = __alldiv(puVar7[0x18],puVar7[0x19],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar7[0x1a],puVar7[0x1b],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[0x21];
      uVar31 = __alldiv(puVar7[0x32],puVar7[0x33],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar7[0x34],puVar7[0x35],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[0x3b];
      uVar31 = __alldiv(puVar7[0x4c],puVar7[0x4d],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar7[0x4e],puVar7[0x4f],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[0x55];
      uVar31 = __alldiv(puVar7[0x66],puVar7[0x67],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar7[0x68],puVar7[0x69],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[0x6f];
      uVar31 = __alldiv(puVar7[0x80],puVar7[0x81],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar7[0x82],puVar7[0x83],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[0x89];
      uVar31 = __alldiv(puVar7[0x9a],puVar7[0x9b],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      uVar31 = __alldiv(puVar7[0x9c],puVar7[0x9d],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = puVar7[0xa3];
      uVar31 = __alldiv(puVar7[0xb4],puVar7[0xb5],0x10000,0);
      uVar6 = (int)(((int)uVar31 >> 0x1f & 0xffU) + (int)uVar31) >> 8 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      pbVar33 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x50f737;
      uVar31 = __alldiv(puVar7[0xb6],puVar7[0xb7],0x10000,0);
      uVar19 = (int)((int)uVar31 + ((int)uVar31 >> 0x1f & 0xffU)) >> 8 & 0x8000003f;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xffffffc0) + 1;
      }
      puVar2 = puVar7 + 0xbd;
      puVar7 = puVar7 + 0xd0;
      local_310 = (float)((int)local_310 + -1);
      puVar17[(uVar19 + 2 + uVar6 * 0x40) * 4] = *puVar2;
    } while (local_310 != 0.0);
    local_2b8 = (int *)0x0;
    local_2b4 = (int *)0x0;
    local_2b0 = (int *)0x0;
    local_c = CONCAT31(local_c._1_3_,2);
    local_2ec = (undefined **)(local_2d4 << 6);
    local_2f4 = 0;
    local_2e8 = (double)CONCAT44(local_2e8._4_4_,local_2d8 * 0x140);
    local_2a8 = (undefined **)(local_2d8 * 0x140);
    local_2cc = local_2ec;
    do {
      local_310 = (float)(local_2c8 + 0x100);
      local_318 = 0.0;
      fVar22 = local_300;
      do {
        fVar26 = local_318;
        local_2dc = (float *)fVar22;
        World_baseHeightField(local_2f8,local_2c8,fVar22,0);
        World_baseHeightField(local_2f8,(uint)local_310,fVar22,0);
        World_baseHeightField(local_2f8,local_2c8,(float)((int)fVar22 + 0x100),0);
        fVar35 = 0.0;
        uVar31 = CONCAT44(local_310,0x50f829);
        World_baseHeightField(local_2f8,(uint)local_310,(float)((int)fVar22 + 0x100),0);
        if (((int)local_2ec + (int)local_2a8) % 0xd == 0) {
          local_9c = local_2f4;
          fStack_98 = fVar26;
          if ((&local_9c < local_2b4) && (local_2b8 <= &local_9c)) {
            iVar24 = (int)&local_9c - (int)local_2b8 >> 3;
            if ((local_2b4 == local_2b0) && ((int)local_2b0 - (int)local_2b4 >> 3 == 0)) {
              iVar18 = (int)local_2b4 - (int)local_2b8 >> 3;
              if (iVar18 == 0x1fffffff) {
LAB_0050f9e0:
                    /* WARNING: Subroutine does not return */
                std::_Xlength_error("vector<T> too long");
              }
              local_308 = (undefined4 *)(iVar18 + 1);
              uVar6 = (int)local_2b0 - (int)local_2b8 >> 3;
              if (0x1fffffff - (uVar6 >> 1) < uVar6) {
                fVar35 = 0.0;
              }
              else {
                fVar35 = (float)(uVar6 + (uVar6 >> 1));
              }
              if ((uint)fVar35 < local_308) {
                fVar35 = (float)local_308;
              }
              FUN_004e25e0(&local_2b8,(uint)fVar35);
            }
            if (local_2b4 != (int *)0x0) {
              *local_2b4 = local_2b8[iVar24 * 2];
              local_2b4[1] = local_2b8[iVar24 * 2 + 1];
            }
          }
          else {
            if ((local_2b4 == local_2b0) && ((int)local_2b0 - (int)local_2b4 >> 3 == 0)) {
              iVar24 = (int)local_2b4 - (int)local_2b8 >> 3;
              if (iVar24 == 0x1fffffff) goto LAB_0050f9e0;
              local_308 = (undefined4 *)(iVar24 + 1);
              uVar6 = (int)local_2b0 - (int)local_2b8 >> 3;
              if (0x1fffffff - (uVar6 >> 1) < uVar6) {
                fVar35 = 0.0;
              }
              else {
                fVar35 = (float)(uVar6 + (uVar6 >> 1));
              }
              if ((uint)fVar35 < local_308) {
                fVar35 = (float)local_308;
              }
              FUN_004e25e0(&local_2b8,(uint)fVar35);
            }
            local_318 = fVar26;
            if (local_2b4 != (int *)0x0) {
              *local_2b4 = local_9c;
              local_2b4[1] = (int)fStack_98;
            }
          }
          local_2b4 = local_2b4 + 2;
          fVar26 = local_318;
        }
        local_2a8 = (undefined **)((int)local_2a8 + 5);
        local_318 = (float)((int)fVar26 + 1);
        fVar22 = (float)((int)local_2dc + 0x100);
      } while ((int)local_318 < 0x40);
      local_2ec = (undefined **)((int)local_2ec + 1);
      local_2f4 = local_2f4 + 1;
      local_2c8 = local_2c8 + 0x100;
      if (0x3f < (int)local_2f4) goto LAB_0050f9eb;
      local_2a8 = (undefined **)local_2e8._0_4_;
    } while( true );
  }
LAB_00510493:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_324);
  return;
LAB_0050f9eb:
  local_2fc = (undefined **)(puVar17 + 0x5006);
  local_300 = 0.0;
  local_2dc = (float *)fVar22;
  do {
    local_2f4 = 0;
    local_2ec = local_2fc;
    fVar22 = local_300;
    do {
      if (local_2ec[6] == (undefined *)0x1) {
        pbVar33 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        pbVar16 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        local_298 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        local_294 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        local_290 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        local_308 = (undefined4 *)((local_2f4 + local_2d8 * 8) * 0x800 + 0x80);
        local_c = CONCAT31(local_c._1_3_,3);
        local_30c = ((int)local_300 + local_2d4 * 8) * 0x800 + 0x80;
        local_2dc = (float *)0x0;
        do {
          local_26c = ((int)local_30c >> 0x1f) << 0x10 | local_30c >> 0x10;
          local_270 = (float)(local_30c << 0x10);
          local_2a8 = (undefined **)0x0;
          local_94 = (float)((int)local_2dc + (int)local_300 * 8);
          local_318 = (float)local_308;
          do {
            pbVar23 = local_294;
            local_264 = ((int)local_318 >> 0x1f) << 0x10 | (uint)local_318 >> 0x10;
            local_268 = (float)((int)local_318 << 0x10);
            fVar28 = World_objectFalloffWeight((uint *)local_2ec,(uint *)&local_270,(uint *)&local_268);
            local_2e8 = (double)CONCAT44(local_2e8._4_4_,(float)fVar28);
            local_310 = 1.0 - (float)fVar28;
            if (0.0 < local_310) {
              local_310 = local_310 * local_310;
            }
            else {
              local_310 = 0.0;
            }
            iStack_90 = (int)local_2a8 + local_2f4 * 8;
            local_80 = local_94;
            local_84 = local_310;
            iStack_7c = iStack_90;
            if (((basic_ostream<char,struct_std::char_traits<char>_> *)&local_84 < pbVar23) &&
               (pbVar33 <= (basic_ostream<char,struct_std::char_traits<char>_> *)&local_84)) {
              local_310 = (float)(((int)&local_84 - (int)pbVar33) / 0xc);
              if ((pbVar23 == pbVar16) &&
                 (iVar24 = (int)pbVar16 - (int)pbVar23 >> 0x1f,
                 ((int)pbVar16 - (int)pbVar23) / 0xc + iVar24 == iVar24)) {
                iVar24 = ((int)pbVar23 - (int)pbVar33) / 0xc;
                if (iVar24 == 0x15555555) goto LAB_0050f9e0;
                uVar19 = ((int)pbVar16 - (int)pbVar33) / 0xc;
                uVar6 = iVar24 + 1;
                if (0x15555555 - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar6) {
                  uVar19 = uVar6;
                }
                FUN_004f7ef0(&local_298,uVar19);
                pbVar16 = local_290;
                pbVar23 = local_294;
                pbVar33 = local_298;
              }
              if (pbVar23 != (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) {
                *(int *)pbVar23 = *(int *)(pbVar33 + (int)local_310 * 0xc);
                *(int *)(pbVar23 + 4) = *(int *)(pbVar33 + (int)local_310 * 0xc + 4);
                *(int *)(pbVar23 + 8) = *(int *)(pbVar33 + (int)local_310 * 0xc + 8);
              }
            }
            else {
              if ((pbVar23 == pbVar16) &&
                 (iVar24 = (int)pbVar16 - (int)pbVar23 >> 0x1f,
                 ((int)pbVar16 - (int)pbVar23) / 0xc + iVar24 == iVar24)) {
                iVar24 = ((int)pbVar23 - (int)pbVar33) / 0xc;
                if (iVar24 == 0x15555555) goto LAB_0050f9e0;
                uVar19 = ((int)pbVar16 - (int)pbVar33) / 0xc;
                uVar6 = iVar24 + 1;
                if (0x15555555 - (uVar19 >> 1) < uVar19) {
                  uVar19 = 0;
                }
                else {
                  uVar19 = uVar19 + (uVar19 >> 1);
                }
                if (uVar19 < uVar6) {
                  uVar19 = uVar6;
                }
                FUN_004f7ef0(&local_298,uVar19);
                pbVar16 = local_290;
                pbVar23 = local_294;
                pbVar33 = local_298;
              }
              if (pbVar23 != (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) {
                *(float *)pbVar23 = local_310;
                *(float *)(pbVar23 + 4) = local_94;
                *(int *)(pbVar23 + 8) = iStack_90;
              }
            }
            local_2a8 = (undefined **)((int)local_2a8 + 1);
            local_294 = pbVar23 + 0xc;
            local_318 = (float)((int)local_318 + 0x100);
          } while ((int)local_2a8 < 8);
          local_2dc = (float *)((int)local_2dc + 1);
          local_30c = local_30c + 0x100;
        } while ((int)local_2dc < 8);
        local_27c = (float)((uint)local_27c & 0xffffff00);
        uVar31 = CONCAT44(local_294,pbVar33);
        fVar35 = local_27c;
        FUN_004f5f40((float *)pbVar33,(float *)local_294,((int)local_294 - (int)pbVar33) / 0xc,
                     local_27c);
        puVar17 = local_2f0;
        *(undefined1 *)(local_2f0 + (*(int *)(pbVar33 + 4) * 0x40 + *(int *)(pbVar33 + 8)) * 4 + 6)
             = 1;
        *(undefined1 *)
         ((int)local_2f0 + (*(int *)(pbVar33 + 4) * 0x40 + *(int *)(pbVar33 + 8)) * 0x10 + 0x19) = 1
        ;
        *(undefined1 *)
         (local_2f0 + (*(int *)(pbVar33 + 0x10) * 0x40 + *(int *)(pbVar33 + 0x14)) * 4 + 6) = 1;
        *(undefined1 *)
         ((int)local_2f0 +
         (*(int *)(pbVar33 + 0x10) * 0x40 + *(int *)(pbVar33 + 0x14)) * 0x10 + 0x19) = 2;
        *(undefined1 *)
         (local_2f0 + (*(int *)(pbVar33 + 0x1c) * 0x40 + *(int *)(pbVar33 + 0x20)) * 4 + 6) = 1;
        *(undefined1 *)
         ((int)local_2f0 +
         (*(int *)(pbVar33 + 0x1c) * 0x40 + *(int *)(pbVar33 + 0x20)) * 0x10 + 0x19) = 3;
        *(undefined1 *)
         (local_2f0 + (*(int *)(pbVar33 + 0x28) * 0x40 + *(int *)(pbVar33 + 0x2c)) * 4 + 6) = 1;
        *(undefined1 *)
         ((int)local_2f0 +
         (*(int *)(pbVar33 + 0x28) * 0x40 + *(int *)(pbVar33 + 0x2c)) * 0x10 + 0x19) = 4;
        operator_delete(pbVar33);
        local_298 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        local_294 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        local_290 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
        fVar22 = local_300;
      }
      local_2f4 = local_2f4 + 1;
      local_2ec = local_2ec + 0x1a;
    } while ((int)local_2f4 < 8);
    local_300 = (float)((int)fVar22 + 1);
    local_2fc = local_2fc + 0xd0;
  } while ((int)local_300 < 8);
  if ((local_2f8[0xb4] == (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>)0x0)
     && (*(int *)(local_2f8 + 0xa4) != 0)) {
    puVar27 = puVar17 + 0x501b;
    local_308 = (undefined4 *)((int)((local_2d8 * 0x40 >> 0x1f & 7U) + local_2d8 * 0x40) >> 3);
    local_30c = (int)((int)local_2cc + ((int)local_2cc >> 0x1f & 7U)) >> 3;
    local_318 = 1.12104e-44;
    fVar22 = local_278;
    do {
      local_310 = 1.12104e-44;
      local_300 = (float)local_308;
      do {
        pcVar34 = (char *)uVar31;
        appuStack_188[0] = &PTR_0055b2c0;
        appuStack_178[0] = &PTR_00571718;
        pcStack_120 = _vftable__exref;
        local_298 = (basic_ostream<char,struct_std::char_traits<char>_> *)((uint)fVar22 | 1);
        uStack_2c = CONCAT31(uStack_2c._1_3_,4);
        std::basic_iostream<char,std::char_traits<char>_>::
        basic_iostream<char,std::char_traits<char>_>
                  ((basic_iostream<char,std::char_traits<char>_> *)appuStack_188,
                   (basic_streambuf<char,std::char_traits<char>_> *)appuStack_170);
        uStack_2c = 5;
        *(undefined ***)((int)appuStack_188 + (int)appuStack_188[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&iStack_18c + (int)appuStack_188[0][1]) = appuStack_188[0][1] + -0x68;
        std::basic_streambuf<char,std::char_traits<char>_>::
        basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)appuStack_170);
        appuStack_170[0] = vftable;
        uStack_138 = 0;
        uStack_134 = 0;
        uStack_2c = CONCAT31(uStack_2c._1_3_,7);
        iVar24 = iStack_320;
        pbVar9 = ostream_writeCString((basic_ostream<char,std::char_traits<char>_> *)appuStack_178,"mission"
                             );
        pbVar16 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar9,iVar24);
        pbVar9 = ostream_writeCString((basic_ostream<char,std::char_traits<char>_> *)pbVar16,
                              in_stack_fffffcac);
        std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar9,(int)pbVar33);
        pvStack_260 = (void *)0x0;
        uStack_25c = 0;
        uStack_258 = 0;
        uStack_254 = 0;
        local_1c._0_1_ = 8;
        puVar10 = FUN_004d8f70(appuStack_178,&local_5c);
        local_1c._0_1_ = 9;
        uVar11 = SpeechDb_loadBlobToVector((void *)((int)local_308 + 0xac),puVar10,&pvStack_260);
        local_314 = CONCAT13((char)uVar11,(undefined3)local_314);
        local_1c = CONCAT31(local_1c._1_3_,8);
        cVar5 = (char)uVar11;
        if (0xf < uStack_48) {
          operator_delete(local_5c);
          cVar5 = local_314._3_1_;
        }
        if (cVar5 != '\0') {
          puVar10 = puVar27 + -10;
          puVar12 = RefCountedNode_init(auStack_c4,&pvStack_260);
          readCombatActionFromStream(puVar12,(int)puVar10);
          *(undefined1 *)(puVar17 + 0x5686) = 1;
        }
        if (pvStack_260 != (void *)0x0) {
          operator_delete(pvStack_260);
          pvStack_260 = (void *)0x0;
          uStack_25c = 0;
          uStack_258 = 0;
        }
        local_1c = CONCAT31(local_1c._1_3_,2);
        *(undefined ***)((int)appuStack_178 + (int)appuStack_178[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&iStack_17c + (int)appuStack_178[0][1]) = appuStack_178[0][1] + -0x68;
        appuStack_160[0] = vftable;
        if ((uStack_124 & 1) != 0) {
          operator_delete((void *)*puStack_154);
        }
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  ((basic_streambuf<char,std::char_traits<char>_> *)appuStack_160,(char *)0x0,
                   (char *)0x0,(char *)0x0);
        *local_150 = 0;
        *puStack_140 = 0;
        *puStack_130 = 0;
        uStack_124 = uStack_124 & 0xfffffffe;
        uStack_128 = 0;
        std::basic_streambuf<char,std::char_traits<char>_>::
        ~basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)appuStack_160);
        std::basic_iostream<char,std::char_traits<char>_>::
        ~basic_iostream<char,std::char_traits<char>_>(local_158);
        std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                  (abStack_110);
        local_228 = &PTR_0055b2c0;
        appuStack_218[0] = &PTR_00571718;
        pcStack_1c0 = _vftable__exref;
        fVar22 = (float)((uint)fVar22 | 3);
        local_1c = CONCAT31(local_1c._1_3_,10);
        local_288 = fVar22;
        std::basic_iostream<char,std::char_traits<char>_>::
        basic_iostream<char,std::char_traits<char>_>
                  ((basic_iostream<char,std::char_traits<char>_> *)&local_228,
                   (basic_streambuf<char,std::char_traits<char>_> *)appuStack_210);
        local_1c = 0xb;
        *(undefined ***)((int)&local_228 + (int)local_228[1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&local_230 + (int)(local_228[1] + 4)) = local_228[1] + -0x68;
        std::basic_streambuf<char,std::char_traits<char>_>::
        basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)appuStack_210);
        appuStack_210[0] = vftable;
        uStack_1d8 = 0;
        uStack_1d4 = 0;
        local_1c = CONCAT31(local_1c._1_3_,0xd);
        in_stack_fffffcac = "monster";
        fVar26 = local_310;
        pbVar9 = ostream_writeCString((basic_ostream<char,std::char_traits<char>_> *)appuStack_218,"monster"
                             );
        pbVar33 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar9,(int)fVar26);
        pbVar9 = ostream_writeCString((basic_ostream<char,std::char_traits<char>_> *)pbVar33,pcVar34);
        std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar9,(int)fVar35);
        pvStack_260 = (void *)0x0;
        uStack_25c = 0;
        uStack_258 = 0;
        uStack_254 = 0;
        local_c._0_1_ = 0xe;
        puVar10 = FUN_004d8f70(appuStack_218,apvStack_34);
        local_c._0_1_ = 0xf;
        uVar11 = SpeechDb_loadBlobToVector(local_2f8 + 0xac,puVar10,&pvStack_260);
        cStack_301 = (char)uVar11;
        local_c = CONCAT31(local_c._1_3_,0xe);
        if (0xf < uStack_20) {
          operator_delete(apvStack_34[0]);
        }
        if (cStack_301 != '\0') {
          puVar10 = puVar27;
          puVar12 = RefCountedNode_init(auStack_a8,&pvStack_260);
          readHitFromStream(puVar12,puVar10);
        }
        if (pvStack_260 != (void *)0x0) {
          operator_delete(pvStack_260);
          pvStack_260 = (void *)0x0;
          uStack_25c = 0;
          uStack_258 = 0;
        }
        local_c = CONCAT31(local_c._1_3_,2);
        *(undefined ***)((int)appuStack_218 + (int)appuStack_218[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&local_21c + (int)appuStack_218[0][1]) = appuStack_218[0][1] + -0x68;
        appuStack_200[0] = vftable;
        if ((uStack_1c4 & 1) != 0) {
          operator_delete((void *)*puStack_1f4);
        }
        uVar31 = 0x51038c;
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  ((basic_streambuf<char,std::char_traits<char>_> *)appuStack_200,(char *)0x0,
                   (char *)0x0,(char *)0x0);
        *puStack_1f0 = 0;
        *puStack_1e0 = 0;
        *puStack_1d0 = 0;
        uStack_1c4 = uStack_1c4 & 0xfffffffe;
        uStack_1c8 = 0;
        std::basic_streambuf<char,std::char_traits<char>_>::
        ~basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)appuStack_200);
        std::basic_iostream<char,std::char_traits<char>_>::
        ~basic_iostream<char,std::char_traits<char>_>(abStack_1f8);
        fVar35 = 7.440083e-39;
        std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                  (abStack_1b0);
        local_300 = (float)((int)local_300 + 1);
        puVar27 = puVar27 + 0x1a;
        local_310 = (float)((int)local_310 + -1);
      } while (local_310 != 0.0);
      local_30c = local_30c + 1;
      local_318 = (float)((int)local_318 + -1);
    } while (local_318 != 0.0);
    local_310 = 0.0;
    local_318 = 0.0;
  }
  local_c = CONCAT31(local_c._1_3_,1);
  *(undefined4 **)(local_2f8 + local_274 * 4 + 0xbc) = puVar17;
  if (local_2b8 != (int *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_2b8);
    operator_delete(local_2b8);
    local_2b8 = (int *)0x0;
    local_2b4 = (int *)0x0;
    local_2b0 = (int *)0x0;
  }
  local_c = 0xffffffff;
  if (local_2c4 != (float *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_2c4);
    operator_delete(local_2c4);
  }
  goto LAB_00510493;
}




/* [AUDIT] proposed: World_featureCountRange  (confidence: high)
 * purpose: Feature-count [min,max] range from site climate floats
 * vars: 
 */
/* Global::World_featureCountRange @ 00522290 */

void __thiscall World_featureCountRange(void *this,undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = 1;
  *param_2 = 10;
  if (*(float *)((int)this + 0x10) <= 0.2 && *(float *)((int)this + 0x10) != 0.2) {
    *param_1 = 10;
    *param_2 = 0x14;
  }
  if ((*(float *)((int)this + 0xc) <= 0.2 && *(float *)((int)this + 0xc) != 0.2) &&
     (0.8 < *(float *)((int)this + 0x10))) {
    *param_1 = 0xf;
    *param_2 = 0x19;
  }
  if ((0.8 < *(float *)((int)this + 0xc)) && (0.8 < *(float *)((int)this + 0x10))) {
    *param_1 = 10;
    *param_2 = 0x14;
  }
  if (*(char *)((int)this + 8) == '\x01') {
    *param_1 = 0x14;
    *param_2 = 0x1e;
  }
  return;
}




/* [AUDIT] proposed: World_siteDistanceSq  (confidence: low)
 * purpose: Effectively empty stub; only runs stack-cookie check (cookie xors cancel)
 * vars: no real work
 */
/* Global::World_siteDistanceSq @ 00522cc0 */

void World_siteDistanceSq(void)

{
  __security_check_cookie(DAT_00583cc8 ^ (uint)&stack0xfffffffc ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World::terrainOffset2D  (confidence: high)
 * purpose: Returns 2-component fractional terrain offset from two value-noise samples (scaled *3*256)
 * vars: param_2/3=x/y; seeds 3423.0/23421.0
 */
/* Global::World_terrainOffset2D @ 00522d80 */

float * World_terrainOffset2D(float *out,int x,int y)

{
  float10 fVar1;
  
  fVar1 = valueNoise2D(SUB84((double)y * 0.0005,0),
                       (int)((ulonglong)((double)y * 0.0005) >> 0x20),3423.0);
  *out = (float)fVar1 * 3.0 * 256.0;
  fVar1 = valueNoise2D(SUB84((double)x * 0.0005,0),
                       (int)((ulonglong)((double)x * 0.0005) >> 0x20),23421.0);
  out[1] = (float)fVar1 * 3.0 * 256.0;
  return out;
}




/* Global::FUN_005286a0 @ 005286a0 */

void __thiscall FUN_005286a0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar1) && (*(undefined4 **)this <= param_1)) {
    iVar3 = ((int)param_1 - (int)*(undefined4 **)this) / 0xc;
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_004f8230(this,1);
    }
    puVar1 = *(undefined4 **)((int)this + 4);
    iVar2 = *(int *)this;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *(undefined4 *)(iVar2 + iVar3 * 0xc);
      puVar1[1] = *(undefined4 *)(iVar2 + 4 + iVar3 * 0xc);
      puVar1[2] = *(undefined4 *)(iVar2 + 8 + iVar3 * 0xc);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0xc;
      return;
    }
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_004f8230(this,1);
    }
    puVar1 = *(undefined4 **)((int)this + 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
      puVar1[1] = param_1[1];
      puVar1[2] = param_1[2];
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0xc;
  return;
}




/* [AUDIT] proposed: World::objectFalloffWeight  (confidence: high)
 * purpose: Distance-based falloff/influence weight of an object over a point, branching on object type (0xb-0xe special)
 * vars: param_1[4]=radius; [6]=type; ftol2=ftol; result=dist^2/radius^2
 */
/* Global::World_objectFalloffWeight @ 0052c820 */

float10 __thiscall World_objectFalloffWeight(uint *feature,uint *pos_a,uint *pos_b)

{
  float radius;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  float dx;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint feature_type;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 tmp;
  
  radius = (float)feature[4];
  if (radius < 0.001) {
    return (float10)0;
  }
  feature_type = feature[6];
  if (((feature_type != 0xb) && (feature_type != 0xc)) && (feature_type != 0xe)) {
    uVar2 = *pos_b;
    uVar3 = pos_b[1];
    if (feature_type == 0xd) {
      uVar13 = ftol2();
      iVar11 = (int)(uVar13 >> 0x20);
      uVar7 = (uint)uVar13;
      feature_type = *pos_a;
      uVar4 = pos_a[1];
      uVar13 = ftol2();
      iVar12 = (int)(uVar13 >> 0x20);
      uVar8 = (uint)uVar13;
      tmp = CONCAT44((1 - iVar11) - (uint)(0x617d0000 < uVar7),0x617d0000 - uVar7);
      dVar5 = (double)tmp;
      tmp = CONCAT44((0x80 - iVar12) - (uint)(0xad580000 < uVar8),-0x52a80000 - uVar8);
      valueNoise2D(SUB84((double)tmp * 1.52587890625e-05,0),
                   (int)((ulonglong)((double)tmp * 1.52587890625e-05) >> 0x20),
                   dVar5 * 1.52587890625e-05);
      uVar13 = ftol2();
      uVar9 = (uint)uVar13 - *feature;
      tmp = CONCAT44((((int)(uVar13 >> 0x20) - feature[1]) - (uint)((uint)uVar13 < *feature)) +
                          uVar4 + (uint)CARRY4(uVar9,feature_type),uVar9 + feature_type);
      dx = (float)tmp;
      tmp = CONCAT44(-(uint)(0x700000 < uVar7) - iVar11,0x700000 - uVar7);
      dVar5 = (double)tmp;
      tmp = CONCAT44(-(uint)(0xd5f0000 < uVar8) - iVar12,0xd5f0000 - uVar8);
      valueNoise2D(SUB84((double)tmp * 1.52587890625e-05,0),
                   (int)((ulonglong)((double)tmp * 1.52587890625e-05) >> 0x20),
                   dVar5 * 1.52587890625e-05);
      uVar13 = ftol2();
      feature_type = (uint)uVar13 - feature[2];
      tmp = CONCAT44((((int)(uVar13 >> 0x20) - feature[3]) - (uint)((uint)uVar13 < feature[2]))
                          + uVar3 + (uint)CARRY4(feature_type,uVar2),feature_type + uVar2);
      return (float10)(((float)tmp * 1.5258789e-05 * (float)tmp * 1.5258789e-05 +
                       dx * 1.5258789e-05 * dx * 1.5258789e-05) / (radius * radius));
    }
    uVar13 = ftol2();
    iVar11 = (int)(uVar13 >> 0x20);
    uVar7 = (uint)uVar13;
    feature_type = *pos_a;
    uVar4 = pos_a[1];
    uVar13 = ftol2();
    iVar12 = (int)(uVar13 >> 0x20);
    uVar8 = (uint)uVar13;
    tmp = CONCAT44((1 - iVar11) - (uint)(0x617d0000 < uVar7),0x617d0000 - uVar7);
    dVar5 = (double)tmp;
    tmp = CONCAT44((0x80 - iVar12) - (uint)(0xad580000 < uVar8),-0x52a80000 - uVar8);
    valueNoise2D(SUB84((double)tmp * 1.52587890625e-05,0),
                 (int)((ulonglong)((double)tmp * 1.52587890625e-05) >> 0x20),
                 dVar5 * 1.52587890625e-05);
    uVar13 = ftol2();
    uVar9 = (uint)uVar13 - *feature;
    tmp = CONCAT44((((int)(uVar13 >> 0x20) - feature[1]) - (uint)((uint)uVar13 < *feature)) +
                        uVar4 + (uint)CARRY4(uVar9,feature_type),uVar9 + feature_type);
    dx = (float)tmp;
    tmp = CONCAT44(-(uint)(0x700000 < uVar7) - iVar11,0x700000 - uVar7);
    dVar5 = (double)tmp;
    tmp = CONCAT44(-(uint)(0xd5f0000 < uVar8) - iVar12,0xd5f0000 - uVar8);
    valueNoise2D(SUB84((double)tmp * 1.52587890625e-05,0),
                 (int)((ulonglong)((double)tmp * 1.52587890625e-05) >> 0x20),
                 dVar5 * 1.52587890625e-05);
    uVar13 = ftol2();
    feature_type = (uint)uVar13 - feature[2];
    tmp = CONCAT44((((int)(uVar13 >> 0x20) - feature[3]) - (uint)((uint)uVar13 < feature[2])) +
                        uVar3 + (uint)CARRY4(feature_type,uVar2),feature_type + uVar2);
    return (float10)(((float)tmp * 1.5258789e-05 * (float)tmp * 1.5258789e-05 +
                     dx * 1.5258789e-05 * dx * 1.5258789e-05) / (radius * radius));
  }
  tmp = CONCAT44((pos_a[1] - feature[1]) - (uint)(*pos_a < *feature),*pos_a - *feature);
  dx = (float)tmp;
  tmp = CONCAT44((pos_b[1] - feature[3]) - (uint)(*pos_b < feature[2]),
                      *pos_b - feature[2]);
  return (float10)(((float)tmp * 1.5258789e-05 * (float)tmp * 1.5258789e-05 +
                   dx * 1.5258789e-05 * dx * 1.5258789e-05) / (radius * radius));
}




/* [AUDIT] proposed: World_riverClimateGate  (confidence: med)
 * purpose: Computes terrain height/elevation at (x,y): base noise + slope + object/vegetation contributions
 * vars: this+0x800168..=noise offsets; World_objectFalloffWeight obj weight; World_biomeBorderDistance slope; Chunk_getColumnAt tile
 */
/* Global::World_riverClimateGate @ 0052cd50 */

float10 __thiscall World_riverClimateGate(void *world,uint x,float y,int param_4)

{
  float fVar1;
  uint uVar2;
  uint *chunk;
  int creature;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  float10 fVar8;
  float elevation;
  double dVar10;
  float fVar11;
  undefined8 local_20;
  undefined8 local_18;
  uint local_10;
  float noise;
  void *world_ptr;
  
  fVar1 = y;
  local_18 = (double)(int)y * 0.001;
  local_20 = (double)(int)x * 0.001;
  dVar10 = (double)*(int *)((int)world + 0x800170) + (double)(int)x * 0.01;
  world_ptr = world;
  fVar7 = valueNoise2D(SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20),
                       (double)*(int *)((int)world + 0x800174) + (double)(int)y * 0.01);
  dVar10 = (double)*(int *)((int)world_ptr + 0x800168) + local_20;
  fVar8 = valueNoise2D(SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20),
                       (double)*(int *)((int)world_ptr + 0x80016c) + local_18);
  noise = (float)fVar8;
  elevation = (float)fVar7 * 0.1 + noise;
  fVar7 = valueNoise2D(SUB84(local_20,0),(int)((ulonglong)local_20 >> 0x20),local_18);
  noise = (float)fVar7;
  elevation = ABS(elevation) * ((noise + 1.0) * 0.1 + 0.8);
  fVar7 = (float10)World_biomeBorderDistance(world_ptr,x,(int)y);
  noise = (float)fVar7;
  fVar11 = 1.0 - noise * 0.75;
  y = elevation;
  if (0.0 < fVar11) {
    y = fVar11 * fVar11 * 0.05 + elevation;
  }
  uVar5 = (int)fVar1 >> 0x1f;
  uVar6 = (int)x >> 0x1f;
  chunk = (uint *)World_getTileAtCoords(world_ptr,(int)(x + (uVar6 & 0x7ff)) >> 0xb,
                                (int)((int)fVar1 + (uVar5 & 0x7ff)) >> 0xb);
  local_18._4_4_ = chunk;
  if (chunk != (uint *)0x0) {
    uVar2 = chunk[6];
    if ((((uVar2 == 1) || (uVar2 == 2)) || (uVar2 == 4)) || (uVar2 == 0xd)) {
      local_20 = (double)CONCAT44(uVar5 << 0x10 | (uint)fVar1 >> 0x10,(int)fVar1 << 0x10);
      noise = (float)(uVar6 << 0x10 | x >> 0x10);
      local_10 = x << 0x10;
      fVar7 = World_objectFalloffWeight(chunk,&local_10,(uint *)&local_20);
      noise = (float)fVar7;
      elevation = 1.0 - noise;
      if (0.0 < elevation) {
        elevation = elevation * elevation;
      }
      else {
        elevation = 0.0;
      }
      y = elevation + y;
    }
    chunk = local_18._4_4_;
    if ((uVar2 == 6) || (uVar2 == 7)) {
      local_20 = (double)CONCAT44(uVar5 << 0x10 | (uint)fVar1 >> 0x10,(int)fVar1 << 0x10);
      local_18._4_4_ = (uint *)(uVar6 << 0x10 | x >> 0x10);
      local_18._0_4_ = x << 0x10;
      fVar7 = World_objectFalloffWeight(chunk,(uint *)&local_18,(uint *)&local_20);
      fVar11 = 1.0 - (float)fVar7;
      elevation = 0.0;
      if (0.0 < fVar11) {
        elevation = fVar11 * fVar11;
      }
      y = elevation * 0.5 + y;
    }
  }
  creature = Chunk_getColumnAt(world_ptr,x,(uint)fVar1,param_4);
  if (creature == 0) {
    fVar7 = (float10)World_waterProximityInfluence(world_ptr,x,(int)fVar1);
    fVar1 = (float)fVar7;
  }
  else {
    fVar1 = *(float *)(creature + 0xc);
  }
  return (float10)(fVar1 + y);
}




/* [AUDIT] proposed: World_waterDepthField  (confidence: low)
 * purpose: Computes climate/lighting factor at (x,y) from noise, gradient cosine terms, and water proximity
 * vars: World_roadField=noise; World_sampleTerrainGradient=gradient; local_28=climate; local_1c=result
 */
/* Global::World_waterDepthField @ 0052d990 */

void __thiscall World_waterDepthField(void *this,uint x,uint y)

{
  uint *chunk;
  float10 fVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  uint local_2c;
  float moisture;
  uint local_24;
  float falloff;
  float temperature;
  double noise_a;
  double noise_b;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  fVar2 = World_roadField(this,x,y);
  moisture = (float)fVar2;
  World_sampleTerrainGradient(this,&noise_a,x,y);
  fVar2 = (float10)World_biomeBorderDistance(this,x,y);
  temperature = (float)fVar2;
  if (0.0 < moisture) {
    fVar4 = moisture * 3.0;
    if (1.0 < fVar4) {
      fVar4 = 1.0;
    }
    fVar4 = 1.0 - fVar4 * fVar4;
    falloff = 1.0 - fVar4 * fVar4;
    dVar3 = noise_a * 360.0;
    libm_sse2_cos_precise();
    fVar4 = (float)(dVar3 * (double)falloff + 1.0);
    if (fVar4 < temperature) {
      temperature = fVar4;
    }
    dVar3 = noise_b * 360.0;
    libm_sse2_cos_precise();
    fVar4 = (float)(dVar3 * (double)falloff + 1.0);
    if (fVar4 < temperature) {
      temperature = fVar4;
    }
  }
  if (0.65 < moisture) {
    fVar4 = (0.7 - moisture) / 0.05;
    if (fVar4 <= 0.0) {
      fVar4 = 0.0;
    }
    temperature = fVar4 * temperature;
  }
  chunk = (uint *)World_getTileAtCoords(this,(int)(x + ((int)x >> 0x1f & 0x7ffU)) >> 0xb,
                                (int)(y + ((int)y >> 0x1f & 0x7ffU)) >> 0xb);
  if ((chunk != (uint *)0x0) && ((chunk[6] == 2 || (chunk[6] == 4)))) {
    falloff = (float)(((int)y >> 0x1f) << 0x10 | y >> 0x10);
    local_24 = y << 0x10;
    moisture = (float)(((int)x >> 0x1f) << 0x10 | x >> 0x10);
    local_2c = x << 0x10;
    fVar2 = World_objectFalloffWeight(chunk,&local_2c,&local_24);
    falloff = (float)fVar2;
    fVar5 = 1.0 - falloff;
    fVar4 = 0.0;
    if (0.0 < fVar5) {
      fVar4 = fVar5 * fVar5;
    }
    temperature = fVar4 * 2.0 + temperature;
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: World::falloffSquared  (confidence: high)
 * purpose: Returns (1-w)^2 clamped>=0 where w=objectFalloffWeight; smoothstep-like influence
 * vars: wraps World_objectFalloffWeight
 */
/* Global::World_falloffSquared @ 0052dee0 */

float10 __thiscall World_falloffSquared(uint *feature,uint *pos_a,uint *pos_b)

{
  float10 fVar1;
  float weight;
  
  fVar1 = World_objectFalloffWeight(feature,pos_a,pos_b);
  weight = 1.0 - (float)fVar1;
  if (weight <= 0.0) {
    return (float10)0;
  }
  return (float10)(weight * weight);
}




/* [AUDIT] proposed: World::getField0  (confidence: high)
 * purpose: Trivial getter: writes *this to *feature
 * vars: one-word accessor
 */
/* Global::World_getField0 @ 00530550 */

void __thiscall World_getField0(void *this,undefined4 *out)

{
  *out = *(undefined4 *)this;
  return;
}




/* Global::FUN_0054a910 @ 0054a910 */

ulonglong __fastcall FUN_0054a910(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint uStack_20;
  float fStack_1c;
  
  if (DAT_00584640 == 0) {
    uVar1 = (ulonglong)ROUND(in_ST0);
    uStack_20 = (uint)uVar1;
    fStack_1c = (float)(uVar1 >> 0x20);
    fVar3 = (float)in_ST0;
    if ((uStack_20 != 0) || (fVar3 = fStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
      if ((int)fVar3 < 0) {
        uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
      }
      else {
        uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
        uVar1 = CONCAT44((int)fStack_1c - (uint)(uStack_20 < uVar2),uStack_20 - uVar2);
      }
    }
    return uVar1;
  }
  return CONCAT44(param_2,(int)in_ST0);
}




