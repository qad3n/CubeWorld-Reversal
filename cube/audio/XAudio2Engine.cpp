// XAudio2Engine (audio) — cube. 24 functions. Bodies = Ghidra pseudo-C.
#include "XAudio2Engine.h"

/* [AUDIT] proposed: blob::deobfuscate  (confidence: high)
 * purpose: Deobfuscates a byte buffer: table-driven (006ffa68) shuffle/unswap then bitwise-complement each byte
 * vars: table 006ffa68 mod 0x2c
 */
/* Global::blob_deobfuscate @ 004496a0 */
/* NOTE(re) 2026-07-15: CONFIRMED shared asset-blob deobfuscator; decode is byte-exact
 * (round-trip proven). `self` is a std::vector<char> {begin,end,cap}; the buffer is
 * transformed in place, equivalent to:
 *     len = end - begin
 *     for i = len-1 downto 0:  swap(buf[i], buf[(T[i % 44] + i) % len])   // de-shuffle
 *     for i = 0 .. len-1:      buf[i] = ~buf[i]                            // XOR 0xFF
 * T = 44 int32 @ 0x006FFA68 (.rdata, file off 0x2FEA68):
 *   4242,9551,840,84800,9242,9846,127,9,9483,394,123,4834,32444,24355,2433,17,34234,42342,
 *   4243,14,184934,1987,3094,1901,89409,4813,37,143,3490,19483,1343,432,84732,9184,9612,1233,
 *   3434,1839,2984,1993,2984,4895,816583,13
 * Keyless + deterministic (independent of db.dat, which ships as "PLACEHOLDER..."). Callers:
 * 0x623a60 (XAudio2Engine, data2 *.wav), 0x4e1970 (cube::Speech, data4 dict_*.xml), 0x486a20,
 * 0x4e7290. Verified by decoding data4.db dict_en/de.xml to valid UTF-8 XML and re-encoding to
 * the exact stored bytes. Tool + decoded output: scratchpad/decode_loc.py, scratchpad/loc/.
 * This is a Global helper; its placement under XAudio2Engine.cpp is a caller-dominance misfiling.
 */

void blob_deobfuscate(void)

{
  char *bytePtr;
  undefined1 tmpByte;
  int bufStart;
  int *self;
  uint swapPos;
  int i;
  
  i = (self[1] - *self) + -1;
  while (-1 < i) {
    bufStart = *self;
    swapPos = (uint)(*(int *)(&DAT_006ffa68 + (i % 0x2c) * 4) + i) % (uint)(self[1] - bufStart)
    ;
    i = i + -1;
    tmpByte = *(undefined1 *)(bufStart + 1 + i);
    *(undefined1 *)(bufStart + 1 + i) = *(undefined1 *)(swapPos + bufStart);
    *(undefined1 *)(swapPos + bufStart) = tmpByte;
  }
  i = 0;
  if (self[1] != *self && -1 < self[1] - *self) {
    do {
      bytePtr = (char *)(*self + i);
      i = i + 1;
      *bytePtr = -1 - *bytePtr;
    } while (i < self[1] - *self);
  }
  return;
}




/* cube::XAudio2Engine::ctor_0 @ 00622da0 */

void cube::XAudio2Engine::ctor_0(void)

{
  uint security_cookie;
  undefined4 uVar2;
  void *db_obj;
  undefined4 *self;
  void *dbname_buf [4];
  undefined4 local_1c;
  uint dbname_cap;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f5334;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
  local_14 = security_cookie;
  uVar2 = list_buyNode_0c(0,0);
  self[3] = uVar2;
  local_8 = 0;
  self[5] = 0;
  self[6] = 0;
  uVar2 = rbtree_allocHead24(security_cookie);
  self[5] = uVar2;
  local_8._0_1_ = 1;
  self[7] = 0;
  self[8] = 0;
  uVar2 = std_list_alloc_sentinel_0x2c();
  self[7] = uVar2;
  local_8._0_1_ = 2;
  self[9] = 0;
  self[10] = 0;
  self[0xb] = 0;
  self[0xc] = 0;
  db_obj = operator_new(8);
  local_8._0_1_ = 3;
  if (db_obj == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Database::ctor_1();
  }
  local_8._0_1_ = 2;
  self[0xb] = uVar2;
  dbname_cap = 0xf;
  local_1c = 0;
  dbname_buf[0] = (void *)((uint)dbname_buf[0] & 0xffffff00);
  string_assignPtrLen("data2.db",8);
  local_8 = CONCAT31(local_8._1_3_,4);
  db_openBlobStore(dbname_buf);
  if (0xf < dbname_cap) {
    operator_delete(dbname_buf[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::XAudio2Engine::ctor_1 @ 00622ef0 */

void cube::XAudio2Engine::ctor_1(void)

{
  char is_nil;
  int *node2;
  int *node3;
  uint security_cookie;
  undefined4 *self;
  int *node;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f5381;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 2;
  vfunc_0(security_cookie);
  node = *(int **)self[5];
  if (node != (int *)self[5]) {
    do {
      if ((undefined4 *)node[5] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)node[5])(1);
      }
      if (*(char *)((int)node + 0xd) == '\0') {
        node2 = (int *)node[2];
        if (*(char *)((int)node2 + 0xd) == '\0') {
          is_nil = *(char *)(*node2 + 0xd);
          node = node2;
          node2 = (int *)*node2;
          while (is_nil == '\0') {
            is_nil = *(char *)(*node2 + 0xd);
            node = node2;
            node2 = (int *)*node2;
          }
        }
        else {
          is_nil = *(char *)(node[1] + 0xd);
          node3 = (int *)node[1];
          node2 = node;
          while ((node = node3, is_nil == '\0' && (node2 == (int *)node[2]))) {
            is_nil = *(char *)(node[1] + 0xd);
            node3 = (int *)node[1];
            node2 = node;
          }
        }
      }
    } while (node != (int *)self[5]);
  }
  if ((undefined4 *)self[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[9])(1);
  }
  if ((undefined4 *)self[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[10])(1);
  }
  node = (int *)self[2];
  if (node != (int *)0x0) {
    (**(code **)(*node + 0x48))(node);
  }
  node = (int *)self[1];
  if (node != (int *)0x0) {
    (**(code **)(*node + 8))(node);
  }
  if ((undefined4 *)self[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[0xb])(1);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  map_eraseRange(local_18,*(undefined4 *)self[7],(undefined4 *)self[7]);
  operator_delete((void *)self[7]);
}




/* cube::XAudio2Engine::Sound::vfunc_0 @ 006230a0 */

void cube::XAudio2Engine::Sound::vfunc_0(byte delete_flag)

{
  undefined4 *self;
  
  *self = vftable;
  if ((delete_flag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




/* cube::XAudio2Engine::vfunc_8 @ 006230d0 */

void cube::XAudio2Engine::vfunc_8(byte delete_flag)

{
  void *self;
  
  ctor_1();
  if ((delete_flag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




/* [AUDIT] proposed: riff_findChunkInMemory  (confidence: high)
 * purpose: Scans an in-memory RIFF/WAV buffer for a chunk id (param_2), returns data ptr/size
 * vars: 0x46464952='RIFF'; delete_flag stream {base,end,,pos}; param_3/4 out
 */
/* Global::riff_findChunkInMemory @ 00623100 */

undefined4 riff_findChunkInMemory(int *param_1,int *target_fourcc,undefined4 *out_data,int *out_size)

{
  int iVar1;
  uint avail;
  int iVar3;
  int offset;
  int *piVar5;
  int *piVar6;
  int *riff_ptr;
  int *chunk_id;
  
  param_1[3] = 0;
  iVar3 = *param_1;
  offset = 0;
  riff_ptr = (int *)0x0;
  avail = param_1[1] - iVar3;
  if (avail != 0) {
    chunk_id = param_1;
    piVar6 = param_1;
    while( true ) {
      iVar1 = param_1[3];
      if (iVar1 + 4 <= (int)avail) {
        chunk_id = *(int **)(iVar3 + iVar1);
        avail = iVar1 + 4;
      }
      param_1[3] = avail;
      iVar1 = param_1[3];
      iVar3 = param_1[1] - *param_1;
      piVar5 = piVar6;
      if (iVar1 + 4 <= iVar3) {
        piVar5 = *(int **)(*param_1 + iVar1);
        iVar3 = iVar1 + 4;
      }
      param_1[3] = iVar3;
      if (chunk_id == (int *)0x46464952) {
        piVar6 = (int *)0x4;
        iVar3 = param_1[3] + 4;
        if (param_1[1] - *param_1 < param_1[3] + 4) {
          iVar3 = param_1[1] - *param_1;
        }
        param_1[3] = iVar3;
        riff_ptr = piVar5;
      }
      else {
        param_1[3] = param_1[3] + (int)piVar5;
        piVar6 = piVar5;
      }
      if (chunk_id == target_fourcc) break;
      offset = offset + 8 + (int)piVar6;
      if (riff_ptr == (int *)0x0) {
        return 1;
      }
      iVar3 = *param_1;
      avail = param_1[1] - iVar3;
      if (avail <= (uint)param_1[3]) {
        return 0;
      }
    }
    *out_data = piVar6;
    *out_size = offset + 8;
  }
  return 0;
}




/* [AUDIT] proposed: riff_findChunkInFile  (confidence: high)
 * purpose: Seeks a WAV file (SetFilePointer/ReadFile) for RIFF chunk target_fourcc, returns offset/size
 * vars: 'RIFF'; param_1 HANDLE; out_data/4 out
 */
/* Global::riff_findChunkInFile @ 006231e0 */

uint riff_findChunkInFile(HANDLE param_1,int target_fourcc,int *out_size,int *out_offset)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD DVar3;
  int offset;
  undefined1 local_18 [4];
  int riff_size;
  int chunk_id;
  DWORD bytes_read;
  int chunk_size;
  
  DVar3 = 0;
  DVar1 = SetFilePointer(param_1,0,(PLONG)0x0,0);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    if ((int)DVar1 < 1) {
      return DVar1;
    }
    return DVar1 & 0xffff | 0x80070000;
  }
  riff_size = 0;
  offset = 0;
  do {
    BVar2 = ReadFile(param_1,&chunk_id,4,&bytes_read,(LPOVERLAPPED)0x0);
    if ((BVar2 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    BVar2 = ReadFile(param_1,&chunk_size,4,&bytes_read,(LPOVERLAPPED)0x0);
    if ((BVar2 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    if (chunk_id == 0x46464952) {
      riff_size = chunk_size;
      chunk_size = 4;
      BVar2 = ReadFile(param_1,local_18,4,&bytes_read,(LPOVERLAPPED)0x0);
      if ((BVar2 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
    }
    else {
      DVar1 = SetFilePointer(param_1,chunk_size,(PLONG)0x0,1);
      if (DVar1 == 0xffffffff) {
        DVar1 = GetLastError();
        if ((int)DVar1 < 1) {
          return DVar1;
        }
        return DVar1 & 0xffff | 0x80070000;
      }
    }
    if (chunk_id == target_fourcc) {
      *out_size = chunk_size;
      *out_offset = offset + 8;
      return 0;
    }
    offset = offset + 8 + chunk_size;
    if (riff_size == 0) {
      return 1;
    }
  } while (DVar3 == 0);
  return 0;
}




/* [AUDIT] proposed: riff_readFromMemory  (confidence: high)
 * purpose: Copies out_size bytes from in-memory RIFF stream at offset out_offset (memcpy, bounds-checked)
 * vars: param_1 stream; target_fourcc dst; out_offset offset
 */
/* Global::riff_readFromMemory @ 00623340 */

undefined4 riff_readFromMemory(int *param_1,void *dst,size_t size,int offset)

{
  int avail;
  
  if ((uint)(param_1[1] - *param_1) < size + offset) {
    return 1;
  }
  param_1[3] = offset;
  avail = param_1[1] - *param_1;
  if (avail < (int)(size + offset)) {
    param_1[3] = avail;
    return 0;
  }
  memcpy(dst,(void *)(*param_1 + offset),size);
  param_1[3] = param_1[3] + size;
  return 0;
}




/* [AUDIT] proposed: riff_readFromFile  (confidence: high)
 * purpose: Seeks file to offset and reads size bytes (SetFilePointer/ReadFile) into dst
 * vars: param_1 HANDLE; HRESULT-style error
 */
/* Global::riff_readFromFile @ 006233a0 */

uint riff_readFromFile(HANDLE param_1,LPVOID buf,DWORD size,LONG offset)

{
  DWORD DVar1;
  BOOL BVar2;
  uint hresult;
  DWORD bytes_read;
  
  hresult = 0;
  DVar1 = SetFilePointer(param_1,offset,(PLONG)0x0,0);
  if (DVar1 == 0xffffffff) {
    hresult = GetLastError();
    if (0 < (int)hresult) {
      return hresult & 0xffff | 0x80070000;
    }
  }
  else {
    BVar2 = ReadFile(param_1,buf,size,&bytes_read,(LPOVERLAPPED)0x0);
    if ((BVar2 == 0) && (hresult = GetLastError(), 0 < (int)hresult)) {
      hresult = hresult & 0xffff | 0x80070000;
    }
  }
  return hresult;
}




/* cube::XAudio2Engine::vfunc_0 @ 00623410 */

void cube::XAudio2Engine::vfunc_0(void)

{
  undefined4 *puVar1;
  uint security_cookie;
  undefined4 *voice_list;
  int inserted;
  int in_ECX;
  int *node;
  undefined1 local_2c [4];
  int local_28;
  undefined4 *local_1c;
  int count;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f53a8;
  local_10 = ExceptionList;
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  count = 0;
  voice_list = (undefined4 *)list_buyNode_0c(0,0);
  local_8 = 0;
  node = (int *)**(int **)(in_ECX + 0xc);
  local_1c = voice_list;
  local_14 = node;
  if (node != *(int **)(in_ECX + 0xc)) {
    do {
      local_14 = node;
      (**(code **)(*(int *)node[2] + 100))((int *)node[2],local_2c,security_cookie);
      if (local_28 == 0) {
        (**(code **)(*(int *)node[2] + 0x48))((int *)node[2]);
        inserted = IntMap_SetScalar(voice_list,voice_list[1],&local_14);
        if (count == 0x15555554) {
          std::_Xlength_error("list<T> too long");
        }
        voice_list[1] = inserted;
        count = count + 1;
        **(int **)(inserted + 4) = inserted;
      }
      node = (int *)*node;
      local_14 = node;
    } while (node != (int *)*(int *)(in_ECX + 0xc));
  }
  for (puVar1 = (undefined4 *)*voice_list; puVar1 != voice_list; puVar1 = (undefined4 *)*puVar1) {
    node = (int *)puVar1[2];
    if (node != *(int **)(in_ECX + 0xc)) {
      *(int *)node[1] = *node;
      *(int *)(*node + 4) = node[1];
      operator_delete(node);
    }
  }
  puVar1 = (undefined4 *)*voice_list;
  *voice_list = voice_list;
  voice_list[1] = voice_list;
  if (puVar1 != voice_list) {
    operator_delete(puVar1);
  }
  operator_delete(voice_list);
}




/* cube::XAudio2Engine::vfunc_4 @ 00623600 */

undefined4 cube::XAudio2Engine::vfunc_4(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 0x24) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 0x24) + 0x1e0010));
}




/* cube::XAudio2Engine::vfunc_6 @ 00623610 */

void cube::XAudio2Engine::vfunc_6(int *param_1,float volume,undefined4 param_3,undefined4 param_4)

{
  int sound_data;
  int *sound;
  int inserted;
  int in_ECX;
  
  if (0.0 < volume) {
    sound = (int *)rbtree_findOrInsert_intKey(&param_1);
    sound_data = *sound;
    if (sound_data != 0) {
      param_1 = (int *)0x0;
      (**(code **)(**(int **)(in_ECX + 4) + 0x20))
                (*(int **)(in_ECX + 4),&param_1,sound_data + 4,0,0x40000000,0,0,0);
      (**(code **)(*param_1 + 0x30))(param_1,volume,0);
      (**(code **)(*param_1 + 0x54))(param_1,sound_data + 0x2c,0);
      (**(code **)(*param_1 + 0x4c))(param_1,0,0);
      (**(code **)(*param_1 + 0x30))(param_1,volume,0);
      (**(code **)(*param_1 + 0x68))(param_1,param_4,0);
      sound_data = *(int *)(in_ECX + 0xc);
      inserted = IntMap_SetScalar(sound_data,*(undefined4 *)(sound_data + 4),&param_1);
      if (*(int *)(in_ECX + 0x10) == 0x15555554) {
        std::_Xlength_error("list<T> too long");
      }
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
      *(int *)(sound_data + 4) = inserted;
      **(int **)(inserted + 4) = inserted;
    }
  }
  return;
}




/* [AUDIT] proposed: XAudio2_loadSound  (confidence: med)
 * purpose: Loads/parses a WAV/audio asset (vfunc_1): reads headers and inits decoder via XAudio2_setupDecoder
 * vars: param_1 path; XAudio2_initDecodeState init; XAudio2_setupDecoder decode setup
 */
/* Global::XAudio2_loadSound @ 00623710 */

void XAudio2_loadSound(char *path,undefined1 loop_flag)

{
  undefined4 *puVar1;
  ushort uVar2;
  int *voice;
  FILE *fp;
  int ret;
  int decoder_ctx;
  int in_ECX;
  uint uVar7;
  undefined1 local_54 [4];
  int local_50;
  undefined4 local_44;
  undefined4 local_40;
  int iStack_3c;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined2 local_1c;
  undefined6 uStack_1a;
  int local_14;
  undefined4 uStack_10;
  undefined2 local_c;
  uint security_cookie;
  
  security_cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  voice = *(int **)(in_ECX + 0x1e000c);
  if (voice != (int *)0x0) {
    (**(code **)(*voice + 0x50))(voice,0,0);
    XAudio2_resetDecoder(in_ECX + 0x1e0020);
    *(undefined1 *)(in_ECX + 0x1e0010) = 0;
    *(undefined2 *)(in_ECX + 0x1e0012) = 0;
    (**(code **)(**(int **)(in_ECX + 0x1e000c) + 0x48))(*(int **)(in_ECX + 0x1e000c));
  }
  if (0xf < *(uint *)(path + 0x14)) {
    path = *(char **)path;
  }
  fp = fopen(path,"rb");
  if (fp == (FILE *)0x0) {
    __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
    return;
  }
  decoder_ctx = in_ECX + 0x1e0020;
  ret = XAudio2_setupDecoder(fp,decoder_ctx,0,0);
  if (-1 < ret) {
    ret = codec_readHeaderFields(decoder_ctx,0xffffffff);
    local_c = 0x12;
    uVar2 = *(ushort *)(ret + 4);
    _local_1c = CONCAT62(CONCAT42(*(int *)(ret + 8),uVar2),1);
    uVar7 = 0;
    _local_14 = CONCAT44(CONCAT22(0x10,uVar2 * 2),(uint)uVar2 * *(int *)(ret + 8) * 2);
    local_20 = 0;
    memset((void *)(*(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + in_ECX),0,0xa0000);
    do {
      if (0x9ffff < uVar7) break;
      ret = XAudio2_initDecodeState(decoder_ctx,*(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + in_ECX + uVar7,
                           0xa0000 - uVar7,0,2,1,&local_20);
      uVar7 = uVar7 + ret;
    } while (ret != 0);
    puVar1 = (undefined4 *)(in_ECX + 0x1e000c);
    decoder_ctx = (**(code **)(**(int **)(in_ECX + 0x1e0008) + 0x20))
                      (*(int **)(in_ECX + 0x1e0008),puVar1,&local_1c,0,0x40000000,0,0,0);
    if (-1 < decoder_ctx) {
      local_44 = 0;
      local_38 = 0;
      local_30 = 0;
      local_28 = 0;
      _local_40 = CONCAT44(*(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + in_ECX,0xa0000);
      decoder_ctx = (**(code **)(*(int *)*puVar1 + 0x54))((int *)*puVar1,&local_44,0);
      if (-1 < decoder_ctx) {
        *(uint *)(in_ECX + 0x1e0014) = (*(int *)(in_ECX + 0x1e0014) + 1U) % 3;
        (**(code **)(*(int *)*puVar1 + 0x4c))((int *)*puVar1,0,0);
        (**(code **)(*(int *)*puVar1 + 0x30))((int *)*puVar1,*(undefined4 *)(in_ECX + 0x1e0018),0);
        (**(code **)(*(int *)*puVar1 + 100))((int *)*puVar1,local_54);
        *(bool *)(in_ECX + 0x1e0010) = local_50 != 0;
        *(undefined1 *)(in_ECX + 0x1e0011) = loop_flag;
        *(undefined2 *)(in_ECX + 0x1e0012) = 0;
        __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::XAudio2Engine::vfunc_1 @ 00623980 */

void cube::XAudio2Engine::vfunc_1(undefined4 param_1,int param_2,undefined4 loop_flag)

{
  int engine;
  int *voice;
  int self;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    engine = *(int *)(self + 0x28);
    voice = *(int **)(engine + 0x1e000c);
    if (voice != (int *)0x0) {
      (**(code **)(*voice + 0x50))(voice,0,0);
      XAudio2_resetDecoder(engine + 0x1e0020);
      *(undefined1 *)(engine + 0x1e0010) = 0;
      *(undefined2 *)(engine + 0x1e0012) = 0;
      XAudio2_loadSound(param_1,loop_flag);
      return;
    }
  }
  else {
    XAudio2_loadSound(param_2,loop_flag);
  }
  XAudio2_loadSound(param_1,loop_flag);
  return;
}




/* cube::XAudio2Engine::vfunc_5 @ 00623a00 */

void cube::XAudio2Engine::vfunc_5(undefined4 left_volume,undefined4 right_volume)

{
  int *voice;
  int self;
  
  voice = *(int **)(*(int *)(self + 0x24) + 0x1e000c);
  *(undefined4 *)(*(int *)(self + 0x24) + 0x1e0018) = left_volume;
  if (voice != (int *)0x0) {
    (**(code **)(*voice + 0x30))(voice,left_volume,0);
  }
  voice = *(int **)(*(int *)(self + 0x28) + 0x1e000c);
  *(undefined4 *)(*(int *)(self + 0x28) + 0x1e0018) = right_volume;
  if (voice != (int *)0x0) {
    (**(code **)(*voice + 0x30))(voice,right_volume,0);
  }
  return;
}




/* cube::XAudio2Engine::Sound::ctor_0 @ 00623a60 */

void cube::XAudio2Engine::Sound::ctor_0(undefined4 *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  LPCWSTR ***ppppWVar8;
  HANDLE hFile;
  DWORD DVar9;
  int self;
  undefined4 *puVar10;
  int fourcc;
  int local_40;
  HANDLE file_handle;
  undefined4 chunk_size;
  undefined4 *sound;
  undefined4 chunk_offset;
  LPCWSTR **local_2c [2];
  LPCWSTR **local_24;
  LPCWSTR **local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f53e0;
  local_10 = ExceptionList;
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)(self + 0x1c);
  local_40 = self;
  local_14 = uVar3;
  file_handle = (HANDLE)map_lowerBound(param_1);
  if (file_handle == (HANDLE)*piVar1) {
LAB_00623ac9:
    file_handle = (HANDLE)*piVar1;
  }
  else {
    piVar6 = (int *)((int)file_handle + 0x10);
    if (0xf < *(uint *)((int)file_handle + 0x24)) {
      piVar6 = (int *)*piVar6;
    }
    iVar4 = string_compare(0,param_1[4],piVar6,*(undefined4 *)((int)file_handle + 0x20));
    if (iVar4 < 0) goto LAB_00623ac9;
  }
  if ((file_handle == (HANDLE)*piVar1) || (*(int *)((int)file_handle + 0x28) == 0)) {
    if (*(int *)(local_40 + 0x2c) == 0) {
      puVar7 = param_1;
      if (0xf < (uint)param_1[5]) {
        puVar7 = (undefined4 *)*param_1;
      }
      puVar10 = param_1;
      if (0xf < (uint)param_1[5]) {
        puVar10 = (undefined4 *)*param_1;
      }
      local_18 = 7;
      local_1c = 0;
      local_2c[0] = (LPCWSTR **)((uint)local_2c[0] & 0xffff0000);
      u16string_assignCharRange(puVar10,param_1[4] + (int)puVar7,fourcc);
      ppppWVar8 = local_2c;
      if (7 < local_18) {
        ppppWVar8 = (LPCWSTR ***)local_2c[0];
      }
      local_8 = 1;
      hFile = CreateFileW((LPCWSTR)ppppWVar8,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0
                         );
      file_handle = hFile;
      if ((hFile != (HANDLE)0xffffffff) &&
         (DVar9 = SetFilePointer(hFile,0,(PLONG)0x0,0), DVar9 != 0xffffffff)) {
        riff_findChunkInFile(hFile,0x46464952,&chunk_size,&chunk_offset);
        riff_readFromFile(hFile,&fourcc,4,chunk_offset);
        if (fourcc == 0x45564157) {
          sound = operator_new(0x50);
          if (sound == (undefined4 *)0x0) {
            sound = (undefined4 *)0x0;
          }
          else {
            *sound = vftable;
          }
          puVar7 = sound;
          riff_findChunkInFile(hFile,0x20746d66,&chunk_size,&chunk_offset);
          *(undefined8 *)(puVar7 + 1) = 0;
          *(undefined8 *)(puVar7 + 3) = 0;
          *(undefined8 *)(puVar7 + 5) = 0;
          *(undefined8 *)(puVar7 + 7) = 0;
          *(undefined8 *)(puVar7 + 9) = 0;
          riff_readFromFile(hFile,puVar7 + 1,chunk_size,chunk_offset);
          riff_findChunkInFile(hFile,0x61746164,&chunk_size,&chunk_offset);
          uVar5 = operator_new_wrapper(chunk_size);
          riff_readFromFile(file_handle,uVar5,chunk_size,chunk_offset);
          *(undefined8 *)(sound + 0xb) = 0;
          *(undefined8 *)(sound + 0xd) = 0;
          *(undefined8 *)(sound + 0xf) = 0;
          *(undefined8 *)(sound + 0x11) = 0;
          sound[0x13] = 0;
          sound[0xc] = chunk_size;
          sound[0xd] = uVar5;
          sound[0xb] = 0x40;
          CloseHandle(file_handle);
          *(int *)(local_40 + 0x30) = *(int *)(local_40 + 0x30) + 1;
          puVar7 = (undefined4 *)map_findOrInsertEmpty(param_1);
          *puVar7 = *(undefined4 *)(local_40 + 0x30);
          puVar7 = (undefined4 *)rbtree_findOrInsert_intKey((undefined4 *)(local_40 + 0x30));
          *puVar7 = sound;
        }
      }
      ppppWVar8 = (LPCWSTR ***)local_2c[0];
      if (7 < local_18) goto LAB_00623e29;
    }
    else {
      local_24 = (LPCWSTR **)0x0;
      local_20 = (LPCWSTR **)0x0;
      local_1c = 0;
      local_18 = 0;
      local_8 = 0;
      cVar2 = db_getBlobInto(param_1,&local_24);
      if ((cVar2 != '\0') && (local_20 != local_24)) {
        blob_deobfuscate(uVar3);
        riff_findChunkInMemory(&local_24,0x46464952,&chunk_size,&chunk_offset);
        sound = (undefined4 *)0x0;
        riff_readFromMemory(&local_24,&sound,4,chunk_offset);
        if (sound == (undefined4 *)0x45564157) {
          sound = operator_new(0x50);
          if (sound == (undefined4 *)0x0) {
            sound = (undefined4 *)0x0;
          }
          else {
            *sound = vftable;
          }
          puVar7 = sound;
          riff_findChunkInMemory(&local_24,0x20746d66,&chunk_size,&chunk_offset);
          *(undefined8 *)(puVar7 + 1) = 0;
          *(undefined8 *)(puVar7 + 3) = 0;
          *(undefined8 *)(puVar7 + 5) = 0;
          *(undefined8 *)(puVar7 + 7) = 0;
          *(undefined8 *)(puVar7 + 9) = 0;
          riff_readFromMemory(&local_24,puVar7 + 1,chunk_size,chunk_offset);
          riff_findChunkInMemory(&local_24,0x61746164,&chunk_size,&chunk_offset);
          uVar5 = operator_new_wrapper(chunk_size);
          riff_readFromMemory(&local_24,uVar5,chunk_size,chunk_offset);
          *(undefined8 *)(sound + 0xb) = 0;
          *(undefined8 *)(sound + 0xd) = 0;
          *(undefined8 *)(sound + 0xf) = 0;
          *(undefined8 *)(sound + 0x11) = 0;
          sound[0x13] = 0;
          sound[0xc] = chunk_size;
          sound[0xd] = uVar5;
          piVar1 = (int *)(local_40 + 0x30);
          sound[0xb] = 0x40;
          *piVar1 = *piVar1 + 1;
          piVar6 = (int *)map_findOrInsertEmpty(param_1);
          *piVar6 = *piVar1;
          puVar7 = (undefined4 *)rbtree_findOrInsert_intKey(piVar1);
          *puVar7 = sound;
        }
      }
      ppppWVar8 = (LPCWSTR ***)local_24;
      if ((LPCWSTR ***)local_24 != (LPCWSTR ***)0x0) {
LAB_00623e29:
        operator_delete(ppppWVar8);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::XAudio2Engine::vfunc_3 @ 00623e60 */

void cube::XAudio2Engine::vfunc_3(void)

{
  int engine;
  int *voice;
  int self;
  
  engine = *(int *)(self + 0x24);
  voice = *(int **)(engine + 0x1e000c);
  if (voice != (int *)0x0) {
    (**(code **)(*voice + 0x50))(voice,0,0);
    XAudio2_resetDecoder(engine + 0x1e0020);
    *(undefined1 *)(engine + 0x1e0010) = 0;
    *(undefined2 *)(engine + 0x1e0012) = 0;
  }
  engine = *(int *)(self + 0x28);
  voice = *(int **)(engine + 0x1e000c);
  if (voice != (int *)0x0) {
    (**(code **)(*voice + 0x50))(voice,0,0);
    XAudio2_resetDecoder(engine + 0x1e0020);
    *(undefined1 *)(engine + 0x1e0010) = 0;
    *(undefined2 *)(engine + 0x1e0012) = 0;
  }
  return;
}




/* [AUDIT] proposed: XAudio2_decodeStream  (confidence: med)
 * purpose: Decodes/streams audio (vfunc_2) via XAudio2_decodeFrame into memset buffer
 * vars: XAudio2_decodeFrame decode; XAudio2_initDecodeState
 */
/* Global::XAudio2_decodeStream @ 00623ee0 */

void XAudio2_decodeStream(void)

{
  int *source_voice;
  int bytes_read;
  int in_ECX;
  uint offset;
  undefined4 local_3c;
  undefined4 local_38;
  int iStack_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [4];
  uint local_14;
  undefined4 local_8;
  
  source_voice = *(int **)(in_ECX + 0x1e000c);
  if (((source_voice != (int *)0x0) && (*(char *)(in_ECX + 0x1e0010) != '\0')) &&
     ((**(code **)(*source_voice + 100))(source_voice,local_18), local_14 < 2)) {
    if ((*(char *)(in_ECX + 0x1e0013) != '\0') && (*(char *)(in_ECX + 0x1e0011) == '\0')) {
      (**(code **)(**(int **)(in_ECX + 0x1e000c) + 0x50))(*(int **)(in_ECX + 0x1e000c),0,0);
    }
    if ((*(char *)(in_ECX + 0x1e0012) != '\0') && (*(char *)(in_ECX + 0x1e0011) == '\0')) {
      *(undefined1 *)(in_ECX + 0x1e0013) = 1;
    }
    memset((void *)(*(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + in_ECX),0,0xa0000);
    local_8 = 0;
    bytes_read = 1;
    offset = 0;
    do {
      if (0x9ffff < offset) {
        if (bytes_read != 0) goto LAB_0062402f;
        break;
      }
      bytes_read = XAudio2_initDecodeState(in_ECX + 0x1e0020,
                           *(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + offset + in_ECX,
                           0xa0000 - offset,0,2,1,&local_8);
      offset = offset + bytes_read;
    } while (bytes_read != 0);
    if (*(char *)(in_ECX + 0x1e0011) == '\0') {
      *(undefined1 *)(in_ECX + 0x1e0012) = 1;
    }
    else {
      XAudio2_decodeFrame(in_ECX + 0x1e0020,0,0);
      do {
        if (0x9ffff < offset) break;
        bytes_read = XAudio2_initDecodeState(in_ECX + 0x1e0020,
                             *(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + offset + in_ECX,
                             0xa0000 - offset,0,2,1,&local_8);
        offset = offset + bytes_read;
      } while (bytes_read != 0);
    }
LAB_0062402f:
    local_3c = 0;
    if (*(char *)(in_ECX + 0x1e0012) != '\0') {
      local_3c = 0x40;
    }
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    _local_38 = CONCAT44(*(int *)(in_ECX + 0x1e0014) * 0xa0000 + 8 + in_ECX,0xa0000);
    bytes_read = (**(code **)(**(int **)(in_ECX + 0x1e000c) + 0x54))
                      (*(int **)(in_ECX + 0x1e000c),&local_3c,0);
    if (bytes_read == 0) {
      *(uint *)(in_ECX + 0x1e0014) = (*(int *)(in_ECX + 0x1e0014) + 1U) % 3;
    }
  }
  return;
}




/* cube::XAudio2Engine::vfunc_2 @ 006240b0 */

void cube::XAudio2Engine::vfunc_2(void)

{
  XAudio2_decodeStream();
  XAudio2_decodeStream();
  return;
}




/* [AUDIT] proposed: XAudio2_resetDecoder  (confidence: med)
 * purpose: Resets/clears decoder state buffers (memset, vorbis_free_channel_state/006d0290 tables)
 * vars: param_1 decoder ctx
 */
/* Global::XAudio2_resetDecoder @ 00625a60 */

undefined4 XAudio2_resetDecoder(int *param_1)

{
  int *piVar1;
  int *_Dst;
  int elem_off;
  int byte_off;
  code *free_fn;
  
  _Dst = param_1;
  byte_off = 0;
  if (param_1 != (int *)0x0) {
    vorbis_free_bitreader_state(param_1 + 0x94);
    vorbis_free_channel_state(param_1 + 0x78);
    OggStream_clear(param_1 + 0x1e);
    free_fn = free_exref;
    if ((param_1[0x12] != 0) && (piVar1 = param_1 + 0xd, *piVar1 != 0)) {
      param_1 = (int *)0x0;
      if (0 < *piVar1) {
        elem_off = 0;
        do {
          vorbis_free_setup(_Dst[0x12] + byte_off);
          vorbis_free_residue_arrays(_Dst[0x13] + elem_off);
          param_1 = (int *)((int)param_1 + 1);
          byte_off = byte_off + 0x20;
          elem_off = elem_off + 0x10;
        } while ((int)param_1 < _Dst[0xd]);
      }
      free_fn = free_exref;
      free((void *)_Dst[0x12]);
      free((void *)_Dst[0x13]);
    }
    if (_Dst[0xf] != 0) {
      (*free_fn)(_Dst[0xf]);
    }
    if (_Dst[0x11] != 0) {
      (*free_fn)(_Dst[0x11]);
    }
    if (_Dst[0x10] != 0) {
      (*free_fn)(_Dst[0x10]);
    }
    if (_Dst[0xe] != 0) {
      (*free_fn)(_Dst[0xe]);
    }
    OggBuffer_free(_Dst + 6);
    if ((*_Dst != 0) && ((code *)_Dst[0xb2] != (code *)0x0)) {
      (*(code *)_Dst[0xb2])(*_Dst);
    }
    memset(_Dst,0,0x2d0);
  }
  return 0;
}




/* [AUDIT] proposed: XAudio2_decodeFrame  (confidence: med)
 * purpose: Decodes one audio frame (codec_decodeSetup setup + codec_synthesizeWindow synth), 64-bit shifts
 * vars: param_1 ctx; param_2 size; __allshr/shl
 */
/* Global::XAudio2_decodeFrame @ 00626740 */

int XAudio2_decodeFrame(int vf,uint target_lo,int target_hi)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int *piVar10;
  int extraout_EDX;
  undefined8 uVar11;
  undefined1 local_40 [16];
  uint local_30;
  uint local_2c;
  undefined1 local_20 [8];
  undefined8 local_18;
  int local_10;
  uint local_c;
  int prev_block;
  
  prev_block = 0;
  iVar2 = codec_decodeSetup(vf,target_lo,target_hi);
  if ((-1 < iVar2) && (iVar2 = codec_setupHelperA(), iVar2 == 0)) {
LAB_00626780:
    while( true ) {
      iVar2 = vf + 0x78;
      iVar3 = OggStream_packetpeek(iVar2,local_40);
      if (iVar3 < 1) break;
      iVar3 = vorbis_decode_mode_mapping(*(int *)(vf + 0x60) * 0x20 + *(int *)(vf + 0x48),local_40);
      local_10 = iVar3;
      if (iVar3 < 0) {
        OggStream_packetout(iVar2,0);
      }
      else {
        if (prev_block != 0) {
          uVar4 = prev_block + iVar3 >> 2;
          puVar7 = (uint *)(vf + 0x50);
          uVar6 = *puVar7;
          *puVar7 = *puVar7 + uVar4;
          *(int *)(vf + 0x54) =
               *(int *)(vf + 0x54) + (prev_block + iVar3 >> 0x1f) + (uint)CARRY4(uVar6,uVar4);
        }
        iVar5 = vorbis_get_serial_or_index(*(undefined4 *)(vf + 0x48),1);
        uVar6 = iVar5 + iVar3 >> 2;
        iVar5 = (iVar5 + iVar3 >> 0x1f) + *(int *)(vf + 0x54) +
                (uint)CARRY4(uVar6,*(uint *)(vf + 0x50));
        if ((target_hi < iVar5) ||
           ((target_hi <= iVar5 && (target_lo <= uVar6 + *(uint *)(vf + 0x50)))))
        goto LAB_00626969;
        OggStream_packetout(iVar2,0);
        vorbis_start_packet_decode(vf + 0x250,local_40);
        vorbis_apply_window_overlap(vf + 0x1e0,vf + 0x250);
        prev_block = iVar3;
        if ((-2 < (int)local_2c) && (local_2c < 0x80000000)) {
          iVar2 = *(int *)(vf + 0x60);
          iVar3 = *(int *)(vf + 0x44);
          puVar7 = (uint *)(iVar3 + iVar2 * 0x10);
          uVar6 = *puVar7;
          iVar5 = *(int *)(iVar3 + 4 + iVar2 * 0x10);
          *(uint *)(vf + 0x50) = local_30 - *puVar7;
          *(uint *)(vf + 0x54) = (local_2c - iVar5) - (uint)(local_30 < uVar6);
          iVar5 = 0;
          if ((*(int *)(vf + 0x54) < 1) && (*(int *)(vf + 0x54) < 0)) {
            *(undefined4 *)(vf + 0x50) = 0;
            *(undefined4 *)(vf + 0x54) = 0;
          }
          prev_block = local_10;
          if (0 < iVar2) {
            puVar7 = (uint *)(iVar3 + 8);
            do {
              uVar4 = *puVar7;
              puVar1 = (uint *)(vf + 0x50);
              uVar6 = *puVar1;
              *puVar1 = *puVar1 + uVar4;
              *(int *)(vf + 0x54) =
                   *(int *)(vf + 0x54) + puVar7[1] + (uint)CARRY4(uVar6,uVar4);
              iVar5 = iVar5 + 1;
              puVar7 = puVar7 + 4;
              prev_block = local_10;
            } while (iVar5 < iVar2);
          }
        }
      }
    }
    if (((-1 < iVar3) || (iVar3 == -3)) &&
       (codec_readBits(local_20,0xffffffff,0xffffffff), -1 < extraout_EDX)) {
      iVar2 = OggPage_bos(local_20);
      if (iVar2 != 0) {
        vorbis_free_channel_state(vf + 0x1e0);
        vorbis_free_bitreader_state(vf + 0x250);
        *(undefined4 *)(vf + 0x58) = 2;
      }
      if (*(int *)(vf + 0x58) < 3) goto code_r0x006268f3;
      goto LAB_00626957;
    }
LAB_00626969:
    *(undefined8 *)(vf + 0x68) = 0;
    *(undefined8 *)(vf + 0x70) = 0;
    local_10 = vorbis_get_codebook_dim_log(*(undefined4 *)(vf + 0x48));
    __allshr();
    uVar11 = __allshl();
    iVar2 = (int)((ulonglong)uVar11 >> 0x20);
    if ((*(int *)(vf + 0x54) <= iVar2) &&
       ((*(int *)(vf + 0x54) < iVar2 || (*(uint *)(vf + 0x50) < (uint)uVar11)))) {
      do {
        local_18 = uVar11;
        uVar11 = __allshr();
        iVar2 = (int)((ulonglong)uVar11 >> 0x20);
        local_c = (uint)uVar11;
        uVar6 = vorbis_get_channel_ptrs(vf + 0x1e0,0);
        if ((iVar2 <= (int)uVar6 >> 0x1f) && ((iVar2 < (int)uVar6 >> 0x1f || (local_c < uVar6)))) {
          uVar6 = local_c;
        }
        vorbis_advance_read_pos(vf + 0x1e0,uVar6);
        uVar9 = uVar6 << ((byte)local_10 & 0x1f);
        puVar7 = (uint *)(vf + 0x50);
        uVar4 = *puVar7;
        *puVar7 = *puVar7 + uVar9;
        *(int *)(vf + 0x54) =
             *(int *)(vf + 0x54) + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar4,uVar9);
        uVar11 = local_18;
        if (((int)uVar6 >> 0x1f <= iVar2) && (((int)uVar6 >> 0x1f < iVar2 || (uVar6 < local_c)))) {
          iVar2 = codec_synthesizeWindow(0,1,1);
          uVar11 = local_18;
          if (iVar2 < 1) {
            uVar11 = codec_recursiveSum(vf,0xffffffff);
            *(undefined8 *)(vf + 0x50) = uVar11;
            uVar11 = local_18;
          }
        }
        local_18._4_4_ = (int)((ulonglong)uVar11 >> 0x20);
        local_18._0_4_ = (uint)uVar11;
      } while ((*(int *)(vf + 0x54) < local_18._4_4_) ||
              ((*(int *)(vf + 0x54) <= local_18._4_4_ &&
               (*(uint *)(vf + 0x50) < (uint)local_18))));
    }
    iVar2 = 0;
  }
  return iVar2;
code_r0x006268f3:
  iVar3 = OggPage_serialno(local_20);
  iVar2 = *(int *)(vf + 0x34);
  iVar5 = 0;
  if (0 < iVar2) {
    piVar10 = *(int **)(vf + 0x40);
    do {
      if (*piVar10 == iVar3) break;
      iVar5 = iVar5 + 1;
      piVar10 = piVar10 + 1;
    } while (iVar5 < iVar2);
  }
  if (iVar5 != iVar2) {
    *(int *)(vf + 0x60) = iVar5;
    *(undefined4 *)(vf + 0x58) = 3;
    uVar8 = OggPage_serialno(local_20);
    *(undefined4 *)(vf + 0x5c) = uVar8;
    OggStream_resetSerialno(vf + 0x78,iVar3);
    iVar2 = codec_setupHelperA();
    if (iVar2 != 0) {
      return iVar2;
    }
    prev_block = 0;
LAB_00626957:
    OggStream_pagein(vf + 0x78,local_20);
  }
  goto LAB_00626780;
}




/* [AUDIT] proposed: codec_readHeaderFields  (confidence: low)
 * purpose: Reads/parses two header fields (no callees)
 * vars: vf/2
 */
/* Global::codec_readHeaderFields @ 00626a70 */

int codec_readHeaderFields(int vf,int link)

{
  if (*(int *)(vf + 4) != 0) {
    if (link < 0) {
      if (*(int *)(vf + 0x58) < 3) goto LAB_00626a9d;
      link = *(int *)(vf + 0x60);
    }
    else if (*(int *)(vf + 0x34) <= link) {
      return 0;
    }
    return link * 0x20 + *(int *)(vf + 0x48);
  }
LAB_00626a9d:
  return *(int *)(vf + 0x48);
}




/* [AUDIT] proposed: XAudio2_initDecodeState  (confidence: med)
 * purpose: Initializes decode state via codec_windowOverlapAdd
 * vars: 5 params; forwards to 626ab0
 */
/* Global::XAudio2_initDecodeState @ 00626de0 */

void XAudio2_initDecodeState(undefined4 vf,undefined4 out_buf,undefined4 length,undefined4 bigendian,
                 undefined4 word_size,undefined4 is_signed,undefined4 bitstream_out)

{
  codec_windowOverlapAdd(vf,out_buf,length,bigendian,word_size,is_signed,bitstream_out,0,0);
  return;
}




/* [AUDIT] proposed: XAudio2_setupDecoder  (confidence: med)
 * purpose: Decoder setup entry forwarding to codec_decodeStreamEntry
 * vars: forwards to 627120
 */
/* Global::XAudio2_setupDecoder @ 006271b0 */

void XAudio2_setupDecoder(undefined4 fp,undefined4 vf,undefined4 initial,undefined4 ibytes)

{
  codec_decodeStreamEntry(fp,vf,initial,ibytes,fread_exref,lib_fn_625a30,fclose_exref,ftell_exref);
  return;
}




