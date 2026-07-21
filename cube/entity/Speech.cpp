// Speech (entity) — cube. 26 functions. Bodies = Ghidra pseudo-C.
#include "Speech.h"

/* [AUDIT] proposed: xml_memoryPool_ctor  (confidence: med)
 * purpose: Initialize parser memory pool object then allocate first arena (xml_memoryPool_initArena)
 * vars: in_ECX=pool
 */
/* Global::xml_memoryPool_ctor @ 004d6d10 */

void xml_memoryPool_ctor(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  xml_memoryPool_initArena();
  return;
}




/* [AUDIT] proposed: xml_iterator_notEqual  (confidence: low)
 * purpose: Compare two 8-byte iterator/cursor pairs for inequality
 * vars: in_ECX,param_1=iters
 */
/* Global::xml_iterator_notEqual @ 004d6d40 */

uint xml_iterator_notEqual(uint *param_1)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX;
  if ((uVar1 == *param_1) && (uVar1 = in_ECX[1], uVar1 == param_1[1])) {
    return uVar1 & 0xffffff00;
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}




/* [AUDIT] proposed: xml_iterator_isValid  (confidence: low)
 * purpose: Return whether iterator/pointer is non-null (0 or -1)
 * vars: in_ECX=iter
 */
/* Global::xml_iterator_isValid @ 004d6d60 */

int xml_iterator_isValid(void)

{
  int *in_ECX;
  
  return (*in_ECX != 0) - 1;
}




/* [AUDIT] proposed: xml_iterator_deref_advance  (confidence: low)
 * purpose: Load current node into out and advance pool iterator to next (+0x18)
 * vars: in_ECX=iter
 */
/* Global::xml_iterator_deref_advance @ 004d6d70 */

void xml_iterator_deref_advance(int *param_1)

{
  int *in_ECX;
  
  *param_1 = *in_ECX;
  param_1[1] = in_ECX[1];
  *in_ECX = *(int *)(*in_ECX + 0x18);
  return;
}




/* [AUDIT] proposed: xml_node_findChildByName  (confidence: med)
 * purpose: Search element's child list for a node whose name matches wide-string key
 * vars: param_2=name
 */
/* Global::xml_node_findChildByName @ 004d7020 */

void xml_node_findChildByName(int *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  int *in_ECX;
  ushort *puVar5;
  bool bVar6;
  
  if (*in_ECX == 0) {
    *param_1 = 0;
    return;
  }
  iVar2 = *(int *)(*in_ECX + 0x1c);
  do {
    if (iVar2 == 0) {
      *param_1 = 0;
      return;
    }
    puVar3 = *(ushort **)(iVar2 + 4);
    puVar5 = param_2;
    if (puVar3 != (ushort *)0x0) {
      do {
        uVar1 = *puVar5;
        bVar6 = uVar1 < *puVar3;
        if (uVar1 != *puVar3) {
LAB_004d7076:
          uVar4 = -(uint)bVar6 | 1;
          goto LAB_004d707b;
        }
        if (uVar1 == 0) break;
        uVar1 = puVar5[1];
        bVar6 = uVar1 < puVar3[1];
        if (uVar1 != puVar3[1]) goto LAB_004d7076;
        puVar3 = puVar3 + 2;
        puVar5 = puVar5 + 2;
      } while (uVar1 != 0);
      uVar4 = 0;
LAB_004d707b:
      if (uVar4 == 0) {
        *param_1 = iVar2;
        return;
      }
    }
    iVar2 = *(int *)(iVar2 + 0x10);
  } while( true );
}




/* [AUDIT] proposed: xml_node_firstChild  (confidence: low)
 * purpose: Return first child node of element (or nulls)
 * vars: in_ECX=element
 */
/* Global::xml_node_firstChild @ 004d70a0 */

void xml_node_firstChild(undefined4 *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  if (iVar1 != 0) {
    *param_1 = *(undefined4 *)(iVar1 + 0x10);
    param_1[1] = iVar1;
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}




/* [AUDIT] proposed: xml_node_findAttributeByName  (confidence: med)
 * purpose: Search element's attribute list for attribute whose name matches wide-string key
 * vars: param_2=name
 */
/* Global::xml_node_findAttributeByName @ 004d70d0 */

void xml_node_findAttributeByName(int *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  int *in_ECX;
  ushort *puVar5;
  bool bVar6;
  
  if (*in_ECX == 0) {
    *param_1 = 0;
    return;
  }
  iVar2 = *(int *)(*in_ECX + 0x10);
  do {
    if (iVar2 == 0) {
      *param_1 = 0;
      return;
    }
    puVar3 = *(ushort **)(iVar2 + 8);
    puVar5 = param_2;
    if (puVar3 != (ushort *)0x0) {
      do {
        uVar1 = *puVar5;
        bVar6 = uVar1 < *puVar3;
        if (uVar1 != *puVar3) {
LAB_004d7126:
          uVar4 = -(uint)bVar6 | 1;
          goto LAB_004d712b;
        }
        if (uVar1 == 0) break;
        uVar1 = puVar5[1];
        bVar6 = uVar1 < puVar3[1];
        if (uVar1 != puVar3[1]) goto LAB_004d7126;
        puVar3 = puVar3 + 2;
        puVar5 = puVar5 + 2;
      } while (uVar1 != 0);
      uVar4 = 0;
LAB_004d712b:
      if (uVar4 == 0) {
        *param_1 = iVar2;
        return;
      }
    }
    iVar2 = *(int *)(iVar2 + 0x18);
  } while( true );
}




/* [AUDIT] proposed: xml_document_firstElementNode  (confidence: low)
 * purpose: Return first element/data node in document, else default sentinel PTR
 * vars: in_ECX=document
 */
/* Global::xml_document_firstElementNode @ 004d7150 */

undefined ** xml_document_firstElementNode(void)

{
  uint *puVar1;
  int *in_ECX;
  
  if (*in_ECX != 0) {
    for (puVar1 = *(uint **)(*in_ECX + 0x10); puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[6]) {
      if ((puVar1[3] != 0) && (((*puVar1 & 7) == 3 || ((*puVar1 & 7) == 4)))) {
        return (undefined **)puVar1[3];
      }
    }
  }
  return &PTR_006fccac;
}




/* [AUDIT] proposed: xml_memoryPool_initArena  (confidence: med)
 * purpose: Reset pool and allocate/link the initial 0x8000 arena
 * vars: in_ECX=pool
 */
/* Global::xml_memoryPool_initArena @ 004d72f0 */

void xml_memoryPool_initArena(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  xml_memoryPool_freeAll();
  puVar5 = (undefined4 *)((int)in_ECX + 0x27U & 0xffffffe0);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
  }
  puVar3 = puVar5 + 6;
  puVar5[4] = 0x8000;
  if (puVar3 == (uint *)0x0) {
    puVar3 = (uint *)0x0;
  }
  else {
    *puVar3 = (uint)puVar5 | 1;
    puVar5[7] = 0;
    puVar5[8] = 0;
    puVar5[9] = 0;
    puVar5[10] = 0;
    puVar5[0xb] = 0;
    puVar5[0xc] = 0;
    puVar5[0xd] = 0;
    puVar5[0xe] = 0;
    puVar5[0xf] = 0;
    puVar5[0x10] = 0;
  }
  *in_ECX = (int)puVar3;
  puVar3[5] = (uint)puVar3;
  iVar1 = *in_ECX;
  uVar2 = puVar5[4];
  puVar4 = (undefined4 *)(iVar1 + 0x20);
  *puVar4 = puVar5;
  *(undefined4 *)(iVar1 + 0x24) = uVar2;
  *puVar5 = puVar4;
  return;
}




/* [AUDIT] proposed: xml_memoryPool_freeAll  (confidence: med)
 * purpose: Free all pool arenas and buffers back to CRT free (PTR_free)
 * vars: in_ECX=pool
 */
/* Global::xml_memoryPool_freeAll @ 004d77d0 */

void xml_memoryPool_freeAll(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_ECX;
  undefined4 *puVar3;
  
  if (in_ECX[1] != 0) {
    (*(code *)PTR_free_007663b0)(in_ECX[1]);
    in_ECX[1] = 0;
  }
  if ((uint *)*in_ECX != (uint *)0x0) {
    puVar3 = (undefined4 *)(*(uint *)*in_ECX & 0xffffffe0);
    iVar2 = puVar3[3];
    while (iVar2 != 0) {
      puVar1 = (undefined4 *)(iVar2 + 4);
      iVar2 = *(int *)(iVar2 + 0xc);
      (*(code *)PTR_free_007663b0)(*puVar1);
    }
    *puVar3 = 0;
    puVar3[3] = 0;
    puVar3[5] = 0;
    puVar3[4] = 0;
    *in_ECX = 0;
  }
  return;
}




/* [AUDIT] proposed: xml_node_ctor_setParent  (confidence: low)
 * purpose: Init node: value=0, parent=current pool node
 * vars: in_ECX=pool
 */
/* Global::xml_node_ctor_setParent @ 004d7840 */

void xml_node_ctor_setParent(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = *in_ECX;
  *param_1 = 0;
  param_1[1] = uVar1;
  return;
}




/* [AUDIT] proposed: xml_document_firstNode  (confidence: low)
 * purpose: Return first node of document root (or null)
 * vars: in_ECX=document
 */
/* Global::xml_document_firstNode @ 004d7860 */

void xml_document_firstNode(undefined4 *param_1)

{
  int *in_ECX;
  
  if (*in_ECX != 0) {
    *param_1 = *(undefined4 *)(*in_ECX + 0x10);
    return;
  }
  *param_1 = 0;
  return;
}




/* [AUDIT] proposed: xml_document_parseWithEncoding  (confidence: med)
 * purpose: Parse XML document: detect encoding, transcode input, run node-tree parser
 * vars: in_ECX=document
 */
/* Global::xml_document_parseWithEncoding @ 004d7b00 */

void xml_document_parseWithEncoding(undefined8 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  undefined8 *puVar6;
  undefined4 *in_ECX;
  undefined1 local_10 [12];
  
  xml_memoryPool_initArena();
  uVar4 = param_3;
  iVar2 = param_2;
  param_5 = xml_detectEncoding(param_5,param_2,param_3);
  param_2 = 0;
  param_3 = 0;
  cVar5 = xml_transcode_dispatch(&param_2,&param_3,param_5,iVar2,uVar4,0);
  iVar3 = param_2;
  if (cVar5 == '\0') {
    *param_1 = 3;
    *(undefined4 *)(param_1 + 1) = 0;
    return;
  }
  puVar6 = (undefined8 *)xml_parse_setjmpWrapper(local_10,param_2,param_3,*in_ECX,param_4);
  uVar1 = *puVar6;
  if (iVar3 != iVar2) {
    in_ECX[1] = iVar3;
  }
  *param_1 = uVar1;
  *(undefined4 *)(param_1 + 1) = param_5;
  return;
}




/* [AUDIT] proposed: xml_document_root  (confidence: low)
 * purpose: Return document root node pointer, else default sentinel
 * vars: in_ECX=document
 */
/* Global::xml_document_root @ 004d7bc0 */

undefined ** xml_document_root(void)

{
  undefined **ppuVar1;
  int *in_ECX;
  
  if ((*in_ECX == 0) || (ppuVar1 = *(undefined ***)(*in_ECX + 8), ppuVar1 == (undefined **)0x0)) {
    ppuVar1 = &PTR_006fccac;
  }
  return ppuVar1;
}




/* [AUDIT] proposed: xml_parse_setjmpWrapper  (confidence: med)
 * purpose: setjmp3 error frame around node-tree parse; returns {errcode,offset}
 * vars: param_2=text;param_4=document
 */
/* Global::xml_parse_setjmpWrapper @ 004d8410 */

void xml_parse_setjmpWrapper(undefined8 *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 local_4c [64];
  int local_c;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  *(int *)(param_4 + 0x28) = param_2;
  if (param_3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_4 + 0x20);
    uVar3 = *(undefined4 *)(param_4 + 0x24);
    local_c = 0;
    sVar1 = *(short *)(param_2 + -2 + param_3 * 2);
    *(undefined2 *)(param_2 + -2 + param_3 * 2) = 0;
    iVar4 = setjmp3(local_4c,0);
    if (iVar4 == 0) {
      xml_parseNodeTree(param_2,param_4,param_5,sVar1);
    }
    if (local_c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = local_c - param_2 >> 1;
    }
    *(undefined4 *)(param_4 + 0x20) = uVar2;
    *(undefined4 *)(param_4 + 0x24) = uVar3;
    if ((iVar4 == 0) && (sVar1 == 0x3c)) {
      uVar6 = CONCAT44(param_3,5);
    }
    else {
      uVar6 = CONCAT44(iVar5,iVar4);
    }
  }
  *param_1 = uVar6;
  *(undefined4 *)(param_1 + 1) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: QuestText_copyTree_b  (confidence: high)
 * purpose: Copies a QuestText red-black tree (nodes via rbtree_copyTreeNode_b), fixing leftmost/rightmost
 * vars: map header
 */
/* Global::QuestText_copyTree_b @ 004e03c0 */

void QuestText_copyTree_b(int *srcRoot,undefined4 param_2)

{
  char cVar1;
  int dstNode;
  int *root;
  int *child;
  int parent;
  int *leaf;
  undefined4 uVar7;
  int *in_ECX;
  
  dstNode = *in_ECX;
  uVar7 = rbtree_copyTreeNode_b(*(undefined4 *)(*srcRoot + 4),dstNode,param_2);
  *(undefined4 *)(dstNode + 4) = uVar7;
  root = (int *)*in_ECX;
  in_ECX[1] = srcRoot[1];
  child = (int *)root[1];
  if (*(char *)((int)child + 0xd) != '\0') {
    *root = (int)root;
    *(int *)(*in_ECX + 8) = *in_ECX;
    return;
  }
  cVar1 = *(char *)(*child + 0xd);
  leaf = (int *)*child;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*leaf + 0xd);
    child = leaf;
    leaf = (int *)*leaf;
  }
  *root = (int)child;
  dstNode = *(int *)(*in_ECX + 4);
  parent = *(int *)(dstNode + 8);
  cVar1 = *(char *)(parent + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(parent + 8) + 0xd);
    dstNode = parent;
    parent = *(int *)(parent + 8);
  }
  *(int *)(*in_ECX + 8) = dstNode;
  return;
}




/* [AUDIT] proposed: std_list_resize_insert  (confidence: med)
 * purpose: Resize/insert into list with element allocation (std_list_erase_range cleanup)
 * vars: -
 */
/* Global::std_list_resize_insert @ 004e16b0 */

void std_list_resize_insert(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  uint uStack_28;
  undefined1 local_18 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9610;
  local_10 = ExceptionList;
  uStack_28 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_28;
  ExceptionList = &local_10;
  piVar3 = (int *)*in_ECX;
  local_8 = 0;
  for (; piVar3 = (int *)*piVar3, param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    if (piVar3 == (int *)*in_ECX) goto LAB_004e1715;
    if (piVar3 + 2 != param_1 + 2) {
      u16string_replaceRange(param_1 + 2,0,0xffffffff);
    }
  }
LAB_004e176e:
  std_list_erase_range(local_18,piVar3,*in_ECX);
  ExceptionList = local_10;
  return;
LAB_004e1715:
  for (; param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    iVar1 = *in_ECX;
    iVar2 = map_insertVal_strKey(iVar1,*(undefined4 *)(iVar1 + 4),param_1 + 2);
    if (in_ECX[1] == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("list<T> too long");
    }
    in_ECX[1] = in_ECX[1] + 1;
    *(int *)(iVar1 + 4) = iVar2;
    **(int **)(iVar2 + 4) = iVar2;
  }
  goto LAB_004e176e;
}




/* cube::Speech::ctor_1 @ 004e1970 */
/* NOTE(re) 2026-07-15: RECLASSIFIED game function (was mislabeled
 * std::basic_stringbuf<wchar_t>::ctor_3 and misfiled in _library/crt_stl.cpp). This is the
 * cube::Speech constructor (writes cube::Speech::vftable @ in_ECX), constructed by World (see
 * World.cpp). It opens data4.db (db_openBlobStore), builds dict_<lang>.xml from the `language`
 * option (literal "dict_en.xml" @ .rdata 0x00302B80), fetches the blob (db_getBlobInto),
 * deobfuscates it (blob_deobfuscate 0x4496a0), then parses the <root> of <name>/<speech>/
 * <landscape> entries (via a wchar basic_stringstream) into the localization map. Sibling
 * Speech ctor at 0x4e2b10 (ctor_0). Belongs in a cube::Speech unit, not crt_stl.cpp; kept here
 * pending a reclassified regen. Provenance: scratchpad/re_findings.md, scratchpad/loc/. */

void cube::Speech::ctor_1(void)

{
  short sVar1;
  undefined4 ****ppppuVar2;
  undefined1 uVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  short *psVar7;
  int iVar8;
  undefined4 ****ppppuVar9;
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *pbVar10;
  undefined4 *puVar11;
  undefined4 *in_ECX;
  short *psVar12;
  uint uVar13;
  uint local_2c0;
  undefined1 *puStack_2bc;
  void *pvStack_2b8;
  undefined4 ****ppppuStack_2b4;
  int iStack_28c;
  undefined **local_288 [3];
  int iStack_27c;
  undefined *local_278;
  undefined **local_270 [2];
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> local_268 [72];
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_220 [132];
  uint local_19c;
  undefined4 *local_198;
  undefined4 *local_18c;
  undefined4 *local_188;
  undefined4 *local_184;
  uint local_180;
  void *local_17c;
  void *local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 *local_16c;
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *local_158;
  int local_154;
  int local_150;
  undefined4 ****local_14c;
  int local_148;
  undefined4 local_144;
  undefined4 *local_140;
  undefined4 *local_134;
  undefined1 local_68 [12];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  void *local_44 [4];
  int local_34;
  uint local_30;
  undefined4 ****local_2c [4];
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e983b;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar13 = 0;
  local_180 = 0;
  *in_ECX = cube::Speech::vftable;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  local_140 = in_ECX;
  uVar5 = node_alloc();
  in_ECX[1] = uVar5;
  puVar11 = in_ECX + 3;
  local_8 = 0;
  *puVar11 = 0;
  in_ECX[4] = 0;
  local_198 = puVar11;
  uVar5 = object_alloc();
  *puVar11 = uVar5;
  puVar11 = in_ECX + 5;
  local_8._0_1_ = 1;
  *puVar11 = 0;
  in_ECX[6] = 0;
  local_184 = puVar11;
  uVar5 = object_alloc();
  *puVar11 = uVar5;
  puVar11 = in_ECX + 7;
  local_8._0_1_ = 2;
  *puVar11 = 0;
  in_ECX[8] = 0;
  local_18c = puVar11;
  uVar5 = object_alloc();
  *puVar11 = uVar5;
  puVar11 = in_ECX + 9;
  local_8._0_1_ = 3;
  *puVar11 = 0;
  in_ECX[10] = 0;
  local_188 = puVar11;
  uVar5 = object_alloc();
  *puVar11 = uVar5;
  local_8._0_1_ = 4;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  uVar5 = object_alloc();
  in_ECX[0xb] = uVar5;
  puVar11 = in_ECX + 0xd;
  local_8._0_1_ = 5;
  *puVar11 = 0;
  in_ECX[0xe] = 0;
  local_16c = puVar11;
  uVar5 = object_alloc();
  *puVar11 = uVar5;
  local_8._0_1_ = 6;
  local_134 = local_140 + 0xf;
  *local_134 = 0;
  local_140[0x10] = 0;
  uVar5 = std_list_alloc_sentinel_0x2c();
  local_140[0xf] = uVar5;
  local_8._0_1_ = 7;
  local_140[0x11] = 0;
  local_140[0x12] = 0;
  uVar5 = std_list_alloc_sentinel_0x2c();
  local_140[0x11] = uVar5;
  local_8._0_1_ = 8;
  local_140[0x13] = 0;
  local_140[0x14] = 0;
  uVar5 = std_list_alloc_sentinel_0x2c();
  local_140[0x13] = uVar5;
  local_8._0_1_ = 9;
  xml_memoryPool_ctor();
  local_8._0_1_ = 10;
  cube::Database::ctor_1();
  local_8._0_1_ = 0xb;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (undefined4 ****)((uint)local_2c[0] & 0xffffff00);
  ppppuStack_2b4 = (undefined4 ****)0x4e1af0;
  string_assignPtrLen();
  local_8._0_1_ = 0xc;
  db_openBlobStore();
  if (0xf < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  local_17c = (void *)0x0;
  local_178 = (void *)0x0;
  local_174 = 0;
  local_170 = 0;
  local_8._0_1_ = 0xd;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (undefined4 ****)((uint)local_2c[0] & 0xffffff00);
  ppppuStack_2b4 = (undefined4 ****)0x4e1b61;
  string_assignPtrLen();
  local_8._0_1_ = 0xe;
  ppppuStack_2b4 = (undefined4 ****)0x4e1b7b;
  db_getBlobInto();
  local_8 = CONCAT31(local_8._1_3_,0xd);
  if (0xf < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c[0]);
  }
  blob_deobfuscate();
  if (0 < (int)local_178 - (int)local_17c) {
    local_144 = 0;
    pvStack_2b8 = local_17c;
    if (local_17c == local_178) {
      pvStack_2b8 = (void *)0x0;
    }
    puStack_2bc = local_68;
    local_2c0 = 0x4e1bdb;
    ppppuStack_2b4 = (undefined4 ****)((int)local_178 - (int)local_17c);
    piVar6 = (int *)xml_document_parseWithEncoding();
    if (*piVar6 == 0) {
      xml_document_firstNode();
      xml_node_firstChild();
      xml_node_ctor_setParent();
      cVar4 = xml_iterator_notEqual();
      while (cVar4 != '\0') {
        noop();
        psVar7 = (short *)xml_document_root();
        local_48 = 7;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffff0000);
        sVar1 = *psVar7;
        while (sVar1 != 0) {
          sVar1 = *psVar7;
          psVar7 = psVar7 + 1;
        }
        ppppuStack_2b4 = (undefined4 ****)0x4e1c7f;
        u16string_assignPtrLen();
        local_8._0_1_ = 0xf;
        ppppuStack_2b4 = (undefined4 ****)0x4e1c9a;
        noop();
        ppppuStack_2b4 = (undefined4 ****)0x4e1ca1;
        xml_node_findChildByName();
        psVar7 = (short *)xml_document_root();
        local_30 = 7;
        local_34 = 0;
        local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
        sVar1 = *psVar7;
        while (sVar1 != 0) {
          sVar1 = *psVar7;
          psVar7 = psVar7 + 1;
        }
        ppppuStack_2b4 = (undefined4 ****)0x4e1ce9;
        u16string_assignPtrLen();
        local_8._0_1_ = 0x10;
        uVar3 = (undefined1)local_8;
        local_8._0_1_ = 0x10;
        if (local_34 != 0) {
          ppppuStack_2b4 = (undefined4 ****)local_4c;
          pvStack_2b8 = (void *)0x0;
          puStack_2bc = (undefined1 *)0x4e1d0b;
          local_154 = u16string_compare();
          if (local_154 == 0) {
            local_150 = local_154;
            local_154 = object_alloc();
            local_8._0_1_ = 0x11;
            local_14c = (undefined4 ****)0x0;
            local_148 = 0;
            ppppuStack_2b4 = (undefined4 ****)0x4e1d57;
            local_14c = (undefined4 ****)list_allocNode32();
            local_8 = CONCAT31(local_8._1_3_,0x12);
            noop();
            xml_node_firstChild();
            noop();
            xml_node_ctor_setParent();
            cVar4 = xml_iterator_notEqual();
            while (cVar4 != '\0') {
              noop();
              iVar8 = xml_document_root();
              if (iVar8 != 0) {
                noop();
                iVar8 = xml_document_firstElementNode();
                if (iVar8 != 0) {
                  noop();
                  xml_document_root();
                  u16string_assignCStr();
                  local_8._0_1_ = 0x13;
                  noop();
                  psVar7 = (short *)xml_document_firstElementNode();
                  rbtree_eraseByStringKey();
                  sVar1 = *psVar7;
                  while (sVar1 != 0) {
                    sVar1 = *psVar7;
                    psVar7 = psVar7 + 1;
                  }
                  ppppuStack_2b4 = (undefined4 ****)0x4e1e4f;
                  u16string_assignPtrLen();
                  local_8 = CONCAT31(local_8._1_3_,0x12);
                  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
                    operator_delete(local_2c[0]);
                  }
                }
              }
              ppppuStack_2b4 = (undefined4 ****)0x4e1e78;
              xml_iterator_deref_advance();
              noop();
              xml_node_ctor_setParent();
              cVar4 = xml_iterator_notEqual();
            }
            ppppuStack_2b4 = (undefined4 ****)0x4e1ebc;
            noop();
            ppppuStack_2b4 = (undefined4 *****)0x4e1ec3;
            xml_node_findChildByName();
            iVar8 = xml_iterator_isValid();
            if (iVar8 != -1) {
              ppppuStack_2b4 = (undefined4 ****)0x4e1eea;
              noop();
              ppppuStack_2b4 = (undefined4 ****)0x4e1ef1;
              xml_node_findChildByName();
              psVar7 = (short *)xml_document_root();
              local_18 = 7;
              local_1c = 0;
              local_2c[0] = (undefined4 ****)((uint)local_2c[0] & 0xffff0000);
              sVar1 = *psVar7;
              while (sVar1 != 0) {
                sVar1 = *psVar7;
                psVar7 = psVar7 + 1;
              }
              ppppuStack_2b4 = (undefined4 ****)0x4e1f39;
              u16string_assignPtrLen();
              local_8._0_1_ = 0x14;
              local_288[0] = &PTR_006fcd00;
              local_278 = &DAT_006fcd08;
              std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
              basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_220);
              local_180 = uVar13 | 1;
              local_8 = CONCAT31(local_8._1_3_,0x15);
              ppppuStack_2b4 = (undefined4 ****)0x4e1f7f;
              std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
              basic_iostream<wchar_t,std::char_traits<wchar_t>_>
                        ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_288,
                         (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_270);
              local_8 = 0x16;
              *(undefined ***)((int)local_288 + (int)local_288[0][1]) =
                   basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
                   vftable;
              *(undefined **)((int)&iStack_28c + (int)local_288[0][1]) = local_288[0][1] + -0x68;
              local_158 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_270;
              std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
              basic_streambuf<wchar_t,std::char_traits<wchar_t>_>(local_158);
              ppppuStack_2b4 = local_2c;
              if (7 < local_18) {
                ppppuStack_2b4 = local_2c[0];
              }
              local_8 = CONCAT31(local_8._1_3_,0x17);
              local_270[0] = vftable;
              pvStack_2b8 = (void *)0x4e1feb;
              strstreambuf_init();
              if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
                operator_delete(local_2c[0]);
              }
              iVar8 = *(int *)((int)&iStack_27c + (int)local_288[0][1]);
              while (local_8._1_3_ = (undefined3)((uint)local_8 >> 8), iVar8 == 0) {
                local_18 = 7;
                local_1c = 0;
                local_2c[0] = (undefined4 ****)((uint)local_2c[0] & 0xffff0000);
                local_8 = CONCAT31(local_8._1_3_,0x1a);
                ppppuStack_2b4 = (undefined4 *****)0x4e2048;
                std_operator_wistream_wstring();
                ppppuVar2 = local_14c;
                if (local_1c != 0) {
                  ppppuStack_2b4 = local_14c;
                  pvStack_2b8 = (void *)0x4e206a;
                  ppppuVar9 = (undefined4 ****)map_insertVal_strKey();
                  if (local_148 == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
                    std::_Xlength_error("list<T> too long");
                  }
                  local_148 = local_148 + 1;
                  ppppuVar2[1] = ppppuVar9;
                  *ppppuVar9[1] = ppppuVar9;
                }
                if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
                  operator_delete(local_2c[0]);
                }
                iVar8 = *(int *)((int)&iStack_27c + (int)local_288[0][1]);
              }
              local_8 = CONCAT31(local_8._1_3_,0x12);
              *(undefined ***)((int)local_288 + (int)local_288[0][1]) =
                   basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
                   vftable;
              *(undefined **)((int)&iStack_28c + (int)local_288[0][1]) = local_288[0][1] + -0x68;
              local_270[0] = vftable;
              strstreambuf_tidy();
              std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
              ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                        ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_270);
              std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
              ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>(local_268);
              std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
              ~basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_220);
            }
            piVar6 = (int *)map_insert_string_key2();
            if (piVar6 != &local_154) {
              rbtree_destroyRecursive();
              local_19c = local_19c & 0xffffff00;
              *(int *)(*piVar6 + 4) = *piVar6;
              *(int *)*piVar6 = *piVar6;
              *(int *)(*piVar6 + 8) = *piVar6;
              piVar6[1] = 0;
              ppppuStack_2b4 = (undefined4 *****)0x4e2171;
              QuestText_copyTree_b();
            }
            if ((undefined4 *****)(piVar6 + 2) != &local_14c) {
              ppppuStack_2b4 = (undefined4 *****)0x4e218c;
              std_list_resize_insert();
            }
            local_8 = CONCAT31(local_8._1_3_,0x10);
            listNode_free_ownsString();
                    /* WARNING: Subroutine does not return */
            operator_delete(local_14c);
          }
          ppppuStack_2b4 = (undefined4 ****)local_4c;
          pvStack_2b8 = (void *)0x0;
          puStack_2bc = (undefined1 *)0x4e21ec;
          iVar8 = u16string_compare();
          if (iVar8 == 0) {
            noop();
            psVar7 = (short *)xml_document_firstElementNode();
            map_string_operation();
            sVar1 = *psVar7;
            while (sVar1 != 0) {
              sVar1 = *psVar7;
              psVar7 = psVar7 + 1;
            }
            ppppuStack_2b4 = (undefined4 ****)0x4e2238;
            u16string_assignPtrLen();
          }
          ppppuStack_2b4 = (undefined4 ****)local_4c;
          pvStack_2b8 = (void *)0x0;
          puStack_2bc = (undefined1 *)0x4e224c;
          iVar8 = u16string_compare();
          if (iVar8 == 0) {
            ppppuStack_2b4 = (undefined4 ****)0x4e226b;
            noop();
            ppppuStack_2b4 = (undefined4 ****)0x4e2272;
            xml_node_findAttributeByName();
            psVar7 = (short *)xml_document_firstElementNode();
            map_string_operation();
            sVar1 = *psVar7;
            while (sVar1 != 0) {
              sVar1 = *psVar7;
              psVar7 = psVar7 + 1;
            }
            ppppuStack_2b4 = (undefined4 ****)0x4e22b8;
            u16string_assignPtrLen();
            ppppuStack_2b4 = (undefined4 ****)0x4e22cf;
            noop();
            ppppuStack_2b4 = (undefined4 ****)0x4e22d6;
            xml_node_findAttributeByName();
            psVar7 = (short *)xml_document_firstElementNode();
            map_string_operation();
            sVar1 = *psVar7;
            while (sVar1 != 0) {
              sVar1 = *psVar7;
              psVar7 = psVar7 + 1;
            }
            ppppuStack_2b4 = (undefined4 ****)0x4e2318;
            u16string_assignPtrLen();
            ppppuStack_2b4 = (undefined4 ****)0x4e232f;
            noop();
            ppppuStack_2b4 = (undefined4 ****)0x4e2336;
            xml_node_findAttributeByName();
            psVar7 = (short *)xml_document_firstElementNode();
            map_string_operation();
            sVar1 = *psVar7;
            while (sVar1 != 0) {
              sVar1 = *psVar7;
              psVar7 = psVar7 + 1;
            }
            ppppuStack_2b4 = (undefined4 ****)0x4e2378;
            u16string_assignPtrLen();
            ppppuStack_2b4 = (undefined4 ****)0x4e238f;
            noop();
            ppppuStack_2b4 = (undefined4 ****)0x4e2396;
            xml_node_findAttributeByName();
            psVar7 = (short *)xml_document_firstElementNode();
            map_string_operation();
            sVar1 = *psVar7;
            while (sVar1 != 0) {
              sVar1 = *psVar7;
              psVar7 = psVar7 + 1;
            }
            ppppuStack_2b4 = (undefined4 ****)0x4e23d8;
            u16string_assignPtrLen();
          }
          ppppuStack_2b4 = (undefined4 ****)local_4c;
          pvStack_2b8 = (void *)0x0;
          puStack_2bc = (undefined1 *)0x4e23ec;
          iVar8 = u16string_compare();
          if (iVar8 == 0) {
            pbVar10 = operator_new(8);
            local_8._0_1_ = 0x1b;
            local_158 = pbVar10;
            if (pbVar10 == (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)0x0) {
              pbVar10 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)0x0;
            }
            else {
              *(undefined4 *)pbVar10 = 0;
              *(undefined4 *)(pbVar10 + 4) = 0;
              uVar5 = node_alloc();
              *(undefined4 *)pbVar10 = uVar5;
            }
            local_8._0_1_ = 0x10;
            puVar11 = (undefined4 *)std_map_getOrInsertByKey();
            *puVar11 = pbVar10;
            noop();
            xml_node_firstChild();
            noop();
            xml_node_ctor_setParent();
            cVar4 = xml_iterator_notEqual();
            while (cVar4 != '\0') {
              noop();
              iVar8 = xml_document_root();
              if (iVar8 != 0) {
                noop();
                iVar8 = xml_document_firstElementNode();
                if (iVar8 != 0) {
                  noop();
                  psVar7 = (short *)xml_document_root();
                  local_18 = 7;
                  local_1c = 0;
                  local_2c[0] = (undefined4 ****)((uint)local_2c[0] & 0xffff0000);
                  sVar1 = *psVar7;
                  while (sVar1 != 0) {
                    sVar1 = *psVar7;
                    psVar7 = psVar7 + 1;
                  }
                  ppppuStack_2b4 = (undefined4 ****)0x4e2509;
                  u16string_assignPtrLen();
                  local_8._0_1_ = 0x1c;
                  noop();
                  psVar7 = (short *)xml_document_firstElementNode();
                  local_158 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&local_2c0;
                  local_2c0 = local_2c0 & 0xffff0000;
                  if (*psVar7 == 0) {
                    iVar8 = 0;
                  }
                  else {
                    psVar12 = psVar7;
                    do {
                      sVar1 = *psVar12;
                      psVar12 = psVar12 + 1;
                    } while (sVar1 != 0);
                    iVar8 = (int)psVar12 - (int)(psVar7 + 1) >> 1;
                  }
                  u16string_assignPtrLen(psVar7,iVar8);
                  local_8._0_1_ = 0x1d;
                  cube::QuestText::ctor_0(local_2c);
                  local_8._0_1_ = 0x1c;
                  cube::QuestText::parseTemplate();
                  local_8._0_1_ = 0x10;
                  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
                    operator_delete(local_2c[0]);
                  }
                }
              }
              ppppuStack_2b4 = (undefined4 ****)0x4e25ab;
              xml_iterator_deref_advance();
              noop();
              xml_node_ctor_setParent();
              cVar4 = xml_iterator_notEqual();
              uVar13 = local_180;
            }
          }
          ppppuStack_2b4 = (undefined4 ****)local_4c;
          pvStack_2b8 = (void *)0x0;
          puStack_2bc = (undefined1 *)0x4e25f2;
          iVar8 = u16string_compare();
          uVar3 = (undefined1)local_8;
          if (iVar8 == 0) {
            local_158 = operator_new(0x10);
            local_8._0_1_ = 0x1e;
            if (local_158 == (void *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar5 = cube::QuestText::ctor_1();
            }
            local_8._0_1_ = 0x10;
            puVar11 = (undefined4 *)std_map_getOrInsertByKey();
            *puVar11 = uVar5;
            noop();
            psVar7 = (short *)xml_document_firstElementNode();
            local_158 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&local_2c0;
            local_2c0 = local_2c0 & 0xffff0000;
            if (*psVar7 == 0) {
              iVar8 = 0;
            }
            else {
              psVar12 = psVar7;
              do {
                sVar1 = *psVar12;
                psVar12 = psVar12 + 1;
              } while (sVar1 != 0);
              iVar8 = (int)psVar12 - (int)(psVar7 + 1) >> 1;
            }
            u16string_assignPtrLen(psVar7,iVar8);
            local_8._0_1_ = 0x1f;
            std_map_getOrInsertByKey(local_44);
            local_8._0_1_ = 0x10;
            cube::QuestText::parseTemplate();
            uVar3 = (undefined1)local_8;
          }
        }
        local_8._0_1_ = uVar3;
        if (7 < local_30) {
                    /* WARNING: Subroutine does not return */
          operator_delete(local_44[0]);
        }
        local_30 = 7;
        local_34 = 0;
        local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
        local_8 = CONCAT31(local_8._1_3_,0xd);
        if (7 < local_48) {
                    /* WARNING: Subroutine does not return */
          operator_delete(local_5c);
        }
        ppppuStack_2b4 = (undefined4 ****)0x4e270f;
        xml_iterator_deref_advance();
        xml_node_ctor_setParent();
        cVar4 = xml_iterator_notEqual();
      }
    }
  }
  local_134 = (undefined4 *)0x1;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e275c;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x2;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e2783;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x3;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e27aa;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x4;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e27d1;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x5;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e27f8;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x6;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e281f;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x7;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e2846;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x8;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e286d;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0x9;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e2894;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0xa;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e28bb;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0xb;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e28e2;
  u16string_assignPtrLen();
  local_134 = (undefined4 *)0xc;
  World_map_find_or_insert_int();
  ppppuStack_2b4 = (undefined4 ****)0x4e2909;
  u16string_assignPtrLen();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  if (local_17c != (void *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_17c);
                    /* WARNING: Subroutine does not return */
    operator_delete(local_17c);
  }
  local_8._0_1_ = 10;
  cube::Database::ctor_0();
  local_8 = CONCAT31(local_8._1_3_,9);
  thunk_FUN_004d77d0();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::Speech::ctor_0 @ 004e2b10 */

void cube::Speech::ctor_0(void)

{
  char isLeaf;
  undefined4 *speechObj;
  int *parent;
  uint cookie;
  undefined4 *self;
  int *cur;
  int *node;
  undefined1 local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e990e;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 9;
  node = (int *)self[0xf];
  cur = (int *)*node;
  if (cur != node) {
    do {
      speechObj = (undefined4 *)cur[10];
      if (speechObj != (undefined4 *)0x0) {
        Speech_map_erase_range2(local_18,*(undefined4 *)*speechObj,(undefined4 *)*speechObj);
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)*speechObj);
      }
      if (*(char *)((int)cur + 0xd) == '\0') {
        node = (int *)cur[2];
        if (*(char *)((int)node + 0xd) == '\0') {
          isLeaf = *(char *)(*node + 0xd);
          cur = node;
          node = (int *)*node;
          while (isLeaf == '\0') {
            isLeaf = *(char *)(*node + 0xd);
            cur = node;
            node = (int *)*node;
          }
        }
        else {
          isLeaf = *(char *)(cur[1] + 0xd);
          parent = (int *)cur[1];
          node = cur;
          while ((cur = parent, isLeaf == '\0' && (node == (int *)cur[2]))) {
            isLeaf = *(char *)(cur[1] + 0xd);
            parent = (int *)cur[1];
            node = cur;
          }
        }
      }
    } while (cur != (int *)self[0xf]);
  }
  node = *(int **)self[0x11];
  local_14 = self;
  if (node != (int *)self[0x11]) {
    do {
      if ((undefined4 *)node[10] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)node[10])(1,cookie);
      }
      if (*(char *)((int)node + 0xd) == '\0') {
        cur = (int *)node[2];
        if (*(char *)((int)cur + 0xd) == '\0') {
          isLeaf = *(char *)(*cur + 0xd);
          node = cur;
          cur = (int *)*cur;
          while (isLeaf == '\0') {
            isLeaf = *(char *)(*cur + 0xd);
            node = cur;
            cur = (int *)*cur;
          }
        }
        else {
          isLeaf = *(char *)(node[1] + 0xd);
          parent = (int *)node[1];
          cur = node;
          while ((node = parent, isLeaf == '\0' && (cur == (int *)node[2]))) {
            isLeaf = *(char *)(node[1] + 0xd);
            parent = (int *)node[1];
            cur = node;
          }
        }
      }
    } while (node != (int *)self[0x11]);
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  Speech_map_erase_range(local_18,*(undefined4 *)local_14[0x13],(undefined4 *)local_14[0x13]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)local_14[0x13]);
}




/* [AUDIT] proposed: map::insert_string_key2  (confidence: med)
 * purpose: Variant of insert_string_key using u16string_replaceRange to build key; inserts node if absent
 * vars: param_1=key record; node built on stack
 */
/* Global::map_insert_string_key2 @ 004e3060 */

void map_insert_string_key2(int key)

{
  uint uVar1;
  int existing;
  int *keyPtr;
  int cmp;
  int *in_ECX;
  undefined4 keyCopy;
  undefined4 local_50;
  void *valueList;
  undefined4 local_48;
  undefined1 local_41;
  undefined1 *local_40;
  undefined2 local_3c [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9998;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  existing = map_lower_bound_string(key);
  if (existing != *in_ECX) {
    keyPtr = (int *)(existing + 0x10);
    if (7 < *(uint *)(existing + 0x24)) {
      keyPtr = (int *)*keyPtr;
    }
    cmp = u16string_compare(0,*(undefined4 *)(key + 0x10),keyPtr,*(undefined4 *)(existing + 0x20));
    if (-1 < cmp) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  keyCopy = 0;
  local_50 = 0;
  keyCopy = object_alloc(uVar1);
  local_8 = 0;
  valueList = (void *)0x0;
  local_48 = 0;
  valueList = (void *)list_allocNode32(0,0);
  local_8 = 1;
  local_28 = 7;
  local_2c = 0;
  local_3c[0] = 0;
  u16string_replaceRange(key,0,0xffffffff);
  local_40 = local_24;
  local_8._0_1_ = 2;
  Container_ctor_default(&keyCopy,&local_41);
  local_8._0_1_ = 3;
  std_list_copy_ctor(&valueList);
  local_8 = CONCAT31(local_8._1_3_,4);
  cmp = rbtree_allocNode_strKey(local_3c);
  rbtree_insertHint_str(&local_40,existing,cmp + 0x10,cmp);
  unwind_delete_member();
  local_8 = 0xffffffff;
  listNode_free_ownsString();
                    /* WARNING: Subroutine does not return */
  operator_delete(valueList);
}




/* cube::Speech::vfunc_0 @ 004e3450 */

void cube::Speech::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  ctor_0();
  if ((param_1 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(in_ECX);
  }
  return;
}




/* [AUDIT] proposed: node_alloc  (confidence: med)
 * purpose: Allocate a container node (operator new)
 * vars: -
 */
/* Global::node_alloc @ 004e3480 */

void node_alloc(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x38);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004e348e. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: Speech::map_erase_range  (confidence: med)
 * purpose: Erases all nodes in [param_2,param_3); if whole tree clears to sentinel, else per-node erase
 * vars: in_ECX=map; iterates successor nodes
 */
/* Global::Speech_map_erase_range @ 004e3840 */

undefined4 * Speech_map_erase_range(undefined4 *param_1,int *first,int *last)

{
  char isLeaf;
  int *next;
  int *cur;
  int *parent;
  int *in_ECX;
  undefined1 local_8 [4];
  
  next = (int *)*in_ECX;
  cur = first;
  if ((first == (int *)*next) && (last == next)) {
    rbtree_destroy_recursive(next[1]);
    *(int *)(*in_ECX + 4) = *in_ECX;
    *(int *)*in_ECX = *in_ECX;
    *(int *)(*in_ECX + 8) = *in_ECX;
    in_ECX[1] = 0;
    *param_1 = *(undefined4 *)*in_ECX;
    return param_1;
  }
  while (cur != last) {
    first = cur;
    if (*(char *)((int)cur + 0xd) == '\0') {
      first = (int *)cur[2];
      if (*(char *)((int)first + 0xd) == '\0') {
        isLeaf = *(char *)(*first + 0xd);
        next = (int *)*first;
        while (isLeaf == '\0') {
          isLeaf = *(char *)(*next + 0xd);
          first = next;
          next = (int *)*next;
        }
      }
      else {
        isLeaf = *(char *)(cur[1] + 0xd);
        parent = (int *)cur[1];
        next = cur;
        while ((first = parent, isLeaf == '\0' && (next == (int *)first[2]))) {
          isLeaf = *(char *)(first[1] + 0xd);
          parent = (int *)first[1];
          next = first;
        }
      }
    }
    Speech_map_erase_node(local_8,cur);
    cur = first;
  }
  *param_1 = cur;
  return param_1;
}




/* [AUDIT] proposed: Speech::map_erase_node  (confidence: high)
 * purpose: Removes one map/set node with red-black rebalance and frees it; throws on invalid iterator
 * vars: first=node; color +3; str +5 cap +10
 */
/* Global::Speech_map_erase_node @ 004e3900 */

/* WARNING: Removing unreachable block (ram,0x004e39cd) */
/* WARNING: Removing unreachable block (ram,0x004e39dd) */
/* WARNING: Removing unreachable block (ram,0x004e39e6) */
/* WARNING: Removing unreachable block (ram,0x004e39e9) */
/* WARNING: Removing unreachable block (ram,0x004e39d9) */
/* WARNING: Removing unreachable block (ram,0x004e39f7) */
/* WARNING: Removing unreachable block (ram,0x004e3a06) */
/* WARNING: Removing unreachable block (ram,0x004e3a11) */
/* WARNING: Removing unreachable block (ram,0x004e3a0d) */
/* WARNING: Removing unreachable block (ram,0x004e3a01) */
/* WARNING: Removing unreachable block (ram,0x004e3a14) */

void Speech_map_erase_node(undefined4 param_1,int *node)

{
  undefined4 *puVar1;
  int iVar2;
  int *sibling;
  undefined4 uVar4;
  int *in_ECX;
  int *parentNode;
  int *fixupNode;
  
  if (*(char *)((int)node + 0xd) != '\0') {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  rbtree_iterator_increment();
  fixupNode = (int *)*node;
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    if (*(char *)(node[2] + 0xd) == '\0') {
      fixupNode = (int *)node[2];
    }
  }
  else {
    fixupNode = (int *)node[2];
  }
  parentNode = (int *)node[1];
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    fixupNode[1] = (int)parentNode;
  }
  if (*(int **)(*in_ECX + 4) == node) {
    *(int **)(*in_ECX + 4) = fixupNode;
  }
  else if ((int *)*parentNode == node) {
    *parentNode = (int)fixupNode;
  }
  else {
    parentNode[2] = (int)fixupNode;
  }
  puVar1 = (undefined4 *)*in_ECX;
  if ((int *)*puVar1 == node) {
    sibling = parentNode;
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      sibling = (int *)rbtree_min_node(fixupNode);
    }
    *puVar1 = sibling;
  }
  iVar2 = *in_ECX;
  if (*(int **)(iVar2 + 8) == node) {
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      uVar4 = RBTree_next(fixupNode);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = parentNode;
    }
  }
  if ((char)node[3] == '\x01') {
    if (fixupNode != *(int **)(*in_ECX + 4)) {
      do {
        sibling = parentNode;
        if ((char)fixupNode[3] != '\x01') break;
        parentNode = (int *)*sibling;
        if (fixupNode == parentNode) {
          parentNode = (int *)sibling[2];
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate_left(sibling);
            parentNode = (int *)sibling[2];
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(*parentNode + 0xc) != '\x01') || (*(char *)(parentNode[2] + 0xc) != '\x01')) {
              if (*(char *)(parentNode[2] + 0xc) == '\x01') {
                *(undefined1 *)(*parentNode + 0xc) = 1;
                *(undefined1 *)(parentNode + 3) = 0;
                rbtree_rotate(parentNode);
                parentNode = (int *)sibling[2];
              }
              *(char *)(parentNode + 3) = (char)sibling[3];
              *(undefined1 *)(sibling + 3) = 1;
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              rbtree_rotate_left(sibling);
              *(undefined1 *)(fixupNode + 3) = 1;
              goto LAB_004e3b5e;
            }
LAB_004e3b00:
            *(undefined1 *)(parentNode + 3) = 0;
          }
        }
        else {
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate(sibling);
            parentNode = (int *)*sibling;
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(parentNode[2] + 0xc) == '\x01') && (*(char *)(*parentNode + 0xc) == '\x01'))
            goto LAB_004e3b00;
            if (*(char *)(*parentNode + 0xc) == '\x01') {
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              *(undefined1 *)(parentNode + 3) = 0;
              rbtree_rotate_left(parentNode);
              parentNode = (int *)*sibling;
            }
            *(char *)(parentNode + 3) = (char)sibling[3];
            *(undefined1 *)(sibling + 3) = 1;
            *(undefined1 *)(*parentNode + 0xc) = 1;
            rbtree_rotate(sibling);
            *(undefined1 *)(fixupNode + 3) = 1;
            goto LAB_004e3b5e;
          }
        }
        parentNode = (int *)sibling[1];
        fixupNode = sibling;
      } while (sibling != *(int **)(*in_ECX + 4));
    }
    *(undefined1 *)(fixupNode + 3) = 1;
  }
LAB_004e3b5e:
  if (7 < (uint)node[10]) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)node[5]);
  }
  node[10] = 7;
  node[9] = 0;
  *(undefined2 *)(node + 5) = 0;
                    /* WARNING: Subroutine does not return */
  operator_delete(node);
}




/* [AUDIT] proposed: Speech::map_erase_range2  (confidence: med)
 * purpose: Erase range variant using Speech_map_erase_node_qt node-erase with QuestText dtor
 * vars: in_ECX=map; range node..param_3
 */
/* Global::Speech_map_erase_range2 @ 004e3f40 */

undefined4 * Speech_map_erase_range2(undefined4 *param_1,int *first,int *last)

{
  char isLeaf;
  int *next;
  int *cur;
  int *parent;
  int *in_ECX;
  undefined1 local_8 [4];
  
  next = (int *)*in_ECX;
  cur = first;
  if ((first == (int *)*next) && (last == next)) {
    rbtree_destroy_recursive_qt(next[1]);
    *(int *)(*in_ECX + 4) = *in_ECX;
    *(int *)*in_ECX = *in_ECX;
    *(int *)(*in_ECX + 8) = *in_ECX;
    in_ECX[1] = 0;
    *param_1 = *(undefined4 *)*in_ECX;
    return param_1;
  }
  while (cur != last) {
    first = cur;
    if (*(char *)((int)cur + 0xd) == '\0') {
      first = (int *)cur[2];
      if (*(char *)((int)first + 0xd) == '\0') {
        isLeaf = *(char *)(*first + 0xd);
        next = (int *)*first;
        while (isLeaf == '\0') {
          isLeaf = *(char *)(*next + 0xd);
          first = next;
          next = (int *)*next;
        }
      }
      else {
        isLeaf = *(char *)(cur[1] + 0xd);
        parent = (int *)cur[1];
        next = cur;
        while ((first = parent, isLeaf == '\0' && (next == (int *)first[2]))) {
          isLeaf = *(char *)(first[1] + 0xd);
          parent = (int *)first[1];
          next = first;
        }
      }
    }
    Speech_map_erase_node_qt(local_8,cur);
    cur = first;
  }
  *param_1 = cur;
  return param_1;
}




/* [AUDIT] proposed: Speech::map_erase_node_qt  (confidence: high)
 * purpose: Erase single map node with RB rebalance, runs QuestText::ctor_2, frees string(+4/+9) and node
 * vars: first=node; color +3
 */
/* Global::Speech_map_erase_node_qt @ 004e4000 */

/* WARNING: Removing unreachable block (ram,0x004e40e1) */
/* WARNING: Removing unreachable block (ram,0x004e40f1) */
/* WARNING: Removing unreachable block (ram,0x004e40fa) */
/* WARNING: Removing unreachable block (ram,0x004e40fd) */
/* WARNING: Removing unreachable block (ram,0x004e40ed) */
/* WARNING: Removing unreachable block (ram,0x004e410b) */
/* WARNING: Removing unreachable block (ram,0x004e4117) */
/* WARNING: Removing unreachable block (ram,0x004e4122) */
/* WARNING: Removing unreachable block (ram,0x004e411e) */
/* WARNING: Removing unreachable block (ram,0x004e4112) */
/* WARNING: Removing unreachable block (ram,0x004e4125) */

void Speech_map_erase_node_qt(undefined4 param_1,int *node)

{
  int *sibling;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *parentNode;
  int *fixupNode;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9ab8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)node + 0xd) != '\0') {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  rbtree_iterator_increment(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  fixupNode = (int *)*node;
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    if (*(char *)(node[2] + 0xd) == '\0') {
      fixupNode = (int *)node[2];
    }
  }
  else {
    fixupNode = (int *)node[2];
  }
  parentNode = (int *)node[1];
  if (*(char *)((int)fixupNode + 0xd) == '\0') {
    fixupNode[1] = (int)parentNode;
  }
  if (*(int **)(*in_ECX + 4) == node) {
    *(int **)(*in_ECX + 4) = fixupNode;
  }
  else if ((int *)*parentNode == node) {
    *parentNode = (int)fixupNode;
  }
  else {
    parentNode[2] = (int)fixupNode;
  }
  puVar2 = (undefined4 *)*in_ECX;
  if ((int *)*puVar2 == node) {
    sibling = parentNode;
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      sibling = (int *)rbtree_min_node(fixupNode);
      puVar2 = (undefined4 *)*in_ECX;
    }
    *puVar2 = sibling;
  }
  if (*(int **)(*in_ECX + 8) == node) {
    if (*(char *)((int)fixupNode + 0xd) == '\0') {
      uVar3 = RBTree_next(fixupNode);
      *(undefined4 *)(*in_ECX + 8) = uVar3;
    }
    else {
      *(int **)(*in_ECX + 8) = parentNode;
    }
  }
  if ((char)node[3] == '\x01') {
    if (fixupNode != *(int **)(*in_ECX + 4)) {
      do {
        sibling = parentNode;
        if ((char)fixupNode[3] != '\x01') break;
        parentNode = (int *)*sibling;
        if (fixupNode == parentNode) {
          parentNode = (int *)sibling[2];
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate_left(sibling);
            parentNode = (int *)sibling[2];
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(*parentNode + 0xc) != '\x01') || (*(char *)(parentNode[2] + 0xc) != '\x01')) {
              if (*(char *)(parentNode[2] + 0xc) == '\x01') {
                *(undefined1 *)(*parentNode + 0xc) = 1;
                *(undefined1 *)(parentNode + 3) = 0;
                rbtree_rotate(parentNode);
                parentNode = (int *)sibling[2];
              }
              *(char *)(parentNode + 3) = (char)sibling[3];
              *(undefined1 *)(sibling + 3) = 1;
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              rbtree_rotate_left(sibling);
              break;
            }
LAB_004e4201:
            *(undefined1 *)(parentNode + 3) = 0;
          }
        }
        else {
          if ((char)parentNode[3] == '\0') {
            *(undefined1 *)(parentNode + 3) = 1;
            *(undefined1 *)(sibling + 3) = 0;
            rbtree_rotate(sibling);
            parentNode = (int *)*sibling;
          }
          if (*(char *)((int)parentNode + 0xd) == '\0') {
            if ((*(char *)(parentNode[2] + 0xc) == '\x01') && (*(char *)(*parentNode + 0xc) == '\x01'))
            goto LAB_004e4201;
            if (*(char *)(*parentNode + 0xc) == '\x01') {
              *(undefined1 *)(parentNode[2] + 0xc) = 1;
              *(undefined1 *)(parentNode + 3) = 0;
              rbtree_rotate_left(parentNode);
              parentNode = (int *)*sibling;
            }
            *(char *)(parentNode + 3) = (char)sibling[3];
            *(undefined1 *)(sibling + 3) = 1;
            *(undefined1 *)(*parentNode + 0xc) = 1;
            rbtree_rotate(sibling);
            break;
          }
        }
        parentNode = (int *)sibling[1];
        fixupNode = sibling;
      } while (sibling != *(int **)(*in_ECX + 4));
    }
    *(undefined1 *)(fixupNode + 3) = 1;
  }
  local_8 = 0;
  cube::QuestText::ctor_2();
  if (7 < (uint)node[9]) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)node[4]);
  }
  node[9] = 7;
  node[8] = 0;
  *(undefined2 *)(node + 4) = 0;
                    /* WARNING: Subroutine does not return */
  operator_delete(node);
}




