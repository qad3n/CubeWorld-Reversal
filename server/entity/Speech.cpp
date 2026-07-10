// Speech (entity) — server. 30 functions. Bodies = Ghidra pseudo-C.
#include "Speech.h"

/* [AUDIT] proposed: Speech_scrambleBlob  (confidence: high)
 * purpose: Obfuscates a byte buffer: table-driven Fisher-Yates-style shuffle then bitwise-NOT each byte
 * vars: param_1=vector (begin at [0], end at [1]); DAT_0055aa68=shuffle table
 */
/* Global::Speech_scrambleBlob @ 00412f80 */

void __fastcall Speech_scrambleBlob(int *buffer)

{
  char *pcVar1;
  undefined1 tmp;
  int iVar3;
  uint swap_idx;
  int i;
  
  i = (buffer[1] - *buffer) + -1;
  while (-1 < i) {
    iVar3 = *buffer;
    swap_idx = (uint)(*(int *)(&DAT_0055aa68 + (i % 0x2c) * 4) + i) %
            (uint)(buffer[1] - iVar3);
    i = i + -1;
    tmp = *(undefined1 *)(iVar3 + 1 + i);
    *(undefined1 *)(iVar3 + 1 + i) = *(undefined1 *)(swap_idx + iVar3);
    *(undefined1 *)(swap_idx + iVar3) = tmp;
  }
  i = 0;
  if (buffer[1] != *buffer && -1 < buffer[1] - *buffer) {
    do {
      pcVar1 = (char *)(*buffer + i);
      i = i + 1;
      *pcVar1 = -1 - *pcVar1;
    } while (i < buffer[1] - *buffer);
  }
  return;
}




/* [AUDIT] proposed: SpeechDb_createBlobsTable  (confidence: high)
 * purpose: Opens sqlite DB (0467f50) and runs CREATE TABLE blobs(key TEXT PRIMARY KEY, value BLOB)
 * vars: this+4=sqlite handle; buffer=path string
 */
/* Global::SpeechDb_createBlobsTable @ 00413010 */

uint __thiscall SpeechDb_createBlobsTable(void *this,int *filename)

{
  int *db_handle;
  uint rc;
  
  db_handle = (int *)((int)this + 4);
  if (*(int **)((int)this + 4) != (int *)0x0) {
    sqlite3_close(*(int **)((int)this + 4));
    *db_handle = 0;
  }
  if (0xf < (uint)filename[5]) {
    filename = (int *)*filename;
  }
  rc = sqlite3_open(filename,db_handle);
  if (rc != 0) {
    return rc & 0xffffff00;
  }
  rc = sqlite3_exec(*db_handle,(byte *)"CREATE TABLE blobs(key TEXT PRIMARY KEY, value BLOB);",
                       (undefined *)0x0,0,(int *)0x0);
  return CONCAT31((int3)(rc >> 8),1);
}




/* [AUDIT] proposed: SpeechDb_loadBlobToVector  (confidence: high)
 * purpose: Loads a blob by key via readBlobByKey then resizes dest vector and memcpy's the bytes
 * vars: this=db; filename=key; param_2=dest vector
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




/* [AUDIT] proposed: XmlDoc_ctorInit  (confidence: med)
 * purpose: Constructor: zeroes first two fields then calls pool init (XmlDoc_initPool)
 * vars: key[0]=pool head; key[1]=aux ptr
 */
/* Global::XmlDoc_ctorInit @ 00416b60 */

int * __fastcall XmlDoc_ctorInit(int *self)

{
  *self = 0;
  self[1] = 0;
  XmlDoc_initPool(self);
  return self;
}




/* [AUDIT] proposed: Iterator_notEqual  (confidence: med)
 * purpose: Compares two 8-byte handles (this[0..1] vs self[0..1]); returns true if any differ (operator!=)
 * vars: this+0/+4 vs self[0]/[1]; bool in low byte
 */
/* Global::Iterator_notEqual @ 00416be0 */

uint __thiscall Iterator_notEqual(void *this,uint *other)

{
  uint field;
  
  field = *(uint *)this;
  if ((field == *other) && (field = *(uint *)((int)this + 4), field == other[1])) {
    return field & 0xffffff00;
  }
  return CONCAT31((int3)(field >> 8),1);
}




/* [AUDIT] proposed: compareResultToSign  (confidence: low)
 * purpose: Returns 0 if *other nonzero else -1; trivial predicate
 * vars: other=int flag
 */
/* Global::compareResultToSign @ 00416c20 */

int __fastcall compareResultToSign(int *obj)

{
  return (*obj != 0) - 1;
}




/* [AUDIT] proposed: Iterator_derefAndAdvance  (confidence: med)
 * purpose: Copies current node handle to out then advances this[0] to next via node+0x18 (linked-list iterator ++)
 * vars: this+0/+4=cur handle; node+0x18=next
 */
/* Global::Iterator_derefAndAdvance @ 00416c30 */

void __thiscall Iterator_derefAndAdvance(void *this,int *out)

{
  *out = *(int *)this;
  out[1] = *(int *)((int)this + 4);
  *(undefined4 *)this = *(undefined4 *)(*(int *)this + 0x18);
  return;
}




/* [AUDIT] proposed: Xml_findAttributeByName  (confidence: high)
 * purpose: Walks node's attribute list (root+0x1c, next at +0x10) comparing wide names (+4); returns matching node or 0
 * vars: this[0]=doc; iter+4=name; iter+0x10=next; param_2=wide name key
 */
/* Global::Xml_findAttributeByName @ 00417510 */

void __thiscall Xml_findAttributeByName(void *this,int *out,ushort *name)

{
  ushort uVar1;
  int node;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  bool bVar6;
  
  if (*(int *)this == 0) {
    *out = 0;
    return;
  }
  node = *(int *)(*(int *)this + 0x1c);
  do {
    if (node == 0) {
      *out = 0;
      return;
    }
    puVar3 = *(ushort **)(node + 4);
    puVar5 = name;
    if (puVar3 != (ushort *)0x0) {
      do {
        uVar1 = *puVar5;
        bVar6 = uVar1 < *puVar3;
        if (uVar1 != *puVar3) {
LAB_00417566:
          uVar4 = -(uint)bVar6 | 1;
          goto LAB_0041756b;
        }
        if (uVar1 == 0) break;
        uVar1 = puVar5[1];
        bVar6 = uVar1 < puVar3[1];
        if (uVar1 != puVar3[1]) goto LAB_00417566;
        puVar3 = puVar3 + 2;
        puVar5 = puVar5 + 2;
      } while (uVar1 != 0);
      uVar4 = 0;
LAB_0041756b:
      if (uVar4 == 0) {
        *out = node;
        return;
      }
    }
    node = *(int *)(node + 0x10);
  } while( true );
}




/* [AUDIT] proposed: Xml_getFirstChildHandle  (confidence: med)
 * purpose: Returns handle {value@node+0x10, node} for root's first item, else {0,0}
 * vars: this[0]=root node; out out pair
 */
/* Global::Xml_getFirstChildHandle @ 00417590 */

void __thiscall Xml_getFirstChildHandle(void *this,undefined4 *out)

{
  int node;
  
  node = *(int *)this;
  if (node != 0) {
    *out = *(undefined4 *)(node + 0x10);
    out[1] = node;
    return;
  }
  *out = 0;
  out[1] = 0;
  return;
}




/* [AUDIT] proposed: Xml_findChildByName  (confidence: high)
 * purpose: Walks child element list (root+0x10, next at +0x18) comparing wide names (+8); returns matching node or 0
 * vars: this[0]=doc; iter+8=name; iter+0x18=next; param_2=wide name key
 */
/* Global::Xml_findChildByName @ 004175c0 */

void __thiscall Xml_findChildByName(void *this,int *out,ushort *name)

{
  ushort uVar1;
  int node;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  bool bVar6;
  
  if (*(int *)this == 0) {
    *out = 0;
    return;
  }
  node = *(int *)(*(int *)this + 0x10);
  do {
    if (node == 0) {
      *out = 0;
      return;
    }
    puVar3 = *(ushort **)(node + 8);
    puVar5 = name;
    if (puVar3 != (ushort *)0x0) {
      do {
        uVar1 = *puVar5;
        bVar6 = uVar1 < *puVar3;
        if (uVar1 != *puVar3) {
LAB_00417616:
          uVar4 = -(uint)bVar6 | 1;
          goto LAB_0041761b;
        }
        if (uVar1 == 0) break;
        uVar1 = puVar5[1];
        bVar6 = uVar1 < puVar3[1];
        if (uVar1 != puVar3[1]) goto LAB_00417616;
        puVar3 = puVar3 + 2;
        puVar5 = puVar5 + 2;
      } while (uVar1 != 0);
      uVar4 = 0;
LAB_0041761b:
      if (uVar4 == 0) {
        *out = node;
        return;
      }
    }
    node = *(int *)(node + 0x18);
  } while( true );
}




/* [AUDIT] proposed: Xml_getFirstTextValue  (confidence: med)
 * purpose: Scans node children for first CDATA/text node (type 3 or 4) with value; returns its text or empty default
 * vars: *puVar1&7 in {3,4}; puVar1[3]=value; puVar1[6]=next; DAT_0055ae8c=empty str
 */
/* Global::Xml_getFirstTextValue @ 00417640 */

undefined * __fastcall Xml_getFirstTextValue(int *node)

{
  uint *child;
  
  if (*node != 0) {
    for (child = *(uint **)(*node + 0x10); child != (uint *)0x0; child = (uint *)child[6]) {
      if ((child[3] != 0) && (((*child & 7) == 3 || ((*child & 7) == 4)))) {
        return (undefined *)child[3];
      }
    }
  }
  return &DAT_0055ae8c;
}




/* [AUDIT] proposed: XmlDoc_initPool  (confidence: med)
 * purpose: Initializes XML document memory pool: frees prior, allocates aligned 0x8000 block, sets up ring links
 * vars: node[1]=aux; pool block 0x8000; PTR_FUN_00582198 alloc via XmlDoc_freePool reset
 */
/* Global::XmlDoc_initPool @ 004177e0 */

void __fastcall XmlDoc_initPool(int *self)

{
  int iVar1;
  undefined4 uVar2;
  uint *first;
  undefined4 *puVar4;
  undefined4 *page;
  
  XmlDoc_freePool(self);
  page = (undefined4 *)((int)self + 0x27U & 0xffffffe0);
  if (page != (undefined4 *)0x0) {
    *page = 0;
    page[1] = 0;
    page[2] = 0;
    page[3] = 0;
    page[4] = 0;
    page[5] = 0;
  }
  first = page + 6;
  page[4] = 0x8000;
  if (first == (uint *)0x0) {
    first = (uint *)0x0;
  }
  else {
    *first = (uint)page | 1;
    page[7] = 0;
    page[8] = 0;
    page[9] = 0;
    page[10] = 0;
    page[0xb] = 0;
    page[0xc] = 0;
    page[0xd] = 0;
    page[0xe] = 0;
    page[0xf] = 0;
    page[0x10] = 0;
  }
  *self = (int)first;
  first[5] = (uint)first;
  iVar1 = *self;
  uVar2 = page[4];
  puVar4 = (undefined4 *)(iVar1 + 0x20);
  *puVar4 = page;
  *(undefined4 *)(iVar1 + 0x24) = uVar2;
  *page = puVar4;
  return;
}




/* [AUDIT] proposed: XmlDoc_freePool  (confidence: med)
 * purpose: Frees XML document pool: releases aux buffer (self[1]) and walks/free block chain, clears head
 * vars: self[1]=aux buf; *self=pool head; PTR_free_0058219c=free fn
 */
/* Global::XmlDoc_freePool @ 00417cc0 */

void __fastcall XmlDoc_freePool(int *self)

{
  undefined4 *puVar1;
  int block;
  undefined4 *page;
  
  if (self[1] != 0) {
    (*(code *)PTR_free_0058219c)(self[1]);
    self[1] = 0;
  }
  if ((uint *)*self != (uint *)0x0) {
    page = (undefined4 *)(*(uint *)*self & 0xffffffe0);
    block = page[3];
    while (block != 0) {
      puVar1 = (undefined4 *)(block + 4);
      block = *(int *)(block + 0xc);
      (*(code *)PTR_free_0058219c)(*puVar1);
    }
    *page = 0;
    page[3] = 0;
    page[5] = 0;
    page[4] = 0;
    *self = 0;
  }
  return;
}




/* [AUDIT] proposed: Xml_getRootHandle  (confidence: low)
 * purpose: Returns handle {0, this[0]}; produces {value=0, docRoot}
 * vars: this[0]=doc root; out self pair
 */
/* Global::Xml_getRootHandle @ 00417d30 */

void __thiscall Xml_getRootHandle(void *this,undefined4 *out)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)this;
  *out = 0;
  out[1] = uVar1;
  return;
}




/* [AUDIT] proposed: Xml_getRootValue  (confidence: low)
 * purpose: Returns *(this[0]+0x10) (root value) or 0 if no doc
 * vars: this[0]=doc; node+0x10=value
 */
/* Global::Xml_getRootValue @ 00417e00 */

void __thiscall Xml_getRootValue(void *this,undefined4 *out)

{
  if (*(int *)this != 0) {
    *out = *(undefined4 *)(*(int *)this + 0x10);
    return;
  }
  *out = 0;
  return;
}




/* [AUDIT] proposed: Xml_loadAndParse  (confidence: high)
 * purpose: Top-level XML load: detect encoding, transcode to UTF-16 (Transcode_dispatch), parse (Xml_parseWithSetjmp); sets status
 * vars: param_2=raw bytes; param_3=len; param_5=encoding hint; out out={status,pos}
 */
/* Global::Xml_loadAndParse @ 004180a0 */

void __thiscall
Xml_loadAndParse(void *this,undefined8 *out,uint *data,uint len,uint param_4,uint encoding)

{
  undefined8 uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 local_10;
  
  XmlDoc_initPool(this);
  uVar4 = len;
  puVar2 = data;
  encoding = Xml_detectEncoding(encoding,(char *)data,len);
  data = (uint *)0x0;
  len = 0;
  uVar4 = Transcode_dispatch((int *)&data,&len,encoding,puVar2,uVar4,'\0');
  puVar3 = data;
  if ((char)uVar4 == '\0') {
    *out = 3;
    *(undefined4 *)(out + 1) = 0;
    return;
  }
  puVar5 = (undefined8 *)Xml_parseWithSetjmp(&local_10,(ushort *)data,len,*(uint **)this,param_4);
  uVar1 = *puVar5;
  if (puVar3 != puVar2) {
    *(uint **)((int)this + 4) = puVar3;
  }
  *out = uVar1;
  *(uint *)(out + 1) = encoding;
  return;
}




/* [AUDIT] proposed: Xml_getNodeName  (confidence: med)
 * purpose: Returns node tag/name pointer (this[0]+8) or empty-string default
 * vars: this[0]=node; node+8=name; DAT_0055ae8c=empty
 */
/* Global::Xml_getNodeName @ 00418160 */

undefined * __fastcall Xml_getNodeName(int *node)

{
  undefined *name;
  
  if ((*node == 0) || (name = *(undefined **)(*node + 8), name == (undefined *)0x0)) {
    name = &DAT_0055ae8c;
  }
  return name;
}




/* [AUDIT] proposed: Xml_parseWithSetjmp  (confidence: high)
 * purpose: Sets stack cookie and setjmp3 error boundary, invokes parser (Xml_parseMainLoop), returns {status,count}
 * vars: param_4[8..10]=state; setjmp3; DAT_00583cc8=cookie; out node
 */
/* Global::Xml_parseWithSetjmp @ 004189b0 */

void __cdecl
Xml_parseWithSetjmp(undefined8 *out,ushort *text,int len,uint *doc,uint flags)

{
  ushort saved_char;
  int err;
  int pos;
  undefined8 uVar4;
  uint local_54;
  uint local_50;
  undefined1 local_4c [64];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  doc[10] = (uint)text;
  if (len == 0) {
    uVar4 = 0;
  }
  else {
    local_54 = doc[8];
    local_50 = doc[9];
    local_c = 0;
    saved_char = text[len + -1];
    text[len + -1] = 0;
    err = setjmp3(local_4c,0);
    if (err == 0) {
      Xml_parseMainLoop(&local_54,text,doc,flags,(uint)saved_char);
    }
    if (local_c == 0) {
      pos = 0;
    }
    else {
      pos = local_c - (int)text >> 1;
    }
    doc[8] = local_54;
    doc[9] = local_50;
    if ((err == 0) && (saved_char == 0x3c)) {
      uVar4 = CONCAT44(len,5);
    }
    else {
      uVar4 = CONCAT44(pos,err);
    }
  }
  *out = uVar4;
  *(undefined4 *)(out + 1) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: QuestTextNode_allocSentinel64  (confidence: med)
 * purpose: Allocates 0x40-byte node, self-links prev/parent/next pointers, sets +0xc=0x101 (list/tree sentinel head)
 * vars: Speech tree; +0..8 self-links; +0xc=0x101 flags (nil/red)
 */
/* Global::QuestTextNode_allocSentinel64 @ 0041a030 */

void QuestTextNode_allocSentinel64(void)

{
  void *head;
  
  head = operator_new(0x40);
  if (head == (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0041a03e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::_Xbad_alloc();
    return;
  }
  *(void **)head = head;
  if ((undefined4 *)((int)head + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)head + 4) = head;
  }
  if ((undefined4 *)((int)head + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)head + 8) = head;
  }
  *(undefined2 *)((int)head + 0xc) = 0x101;
  return;
}




/* [AUDIT] proposed: SpeechTree_destroyRec  (confidence: high)
 * purpose: Recursively destroys RB-tree/list nodes, freeing two wstrings per node (offsets 0x10 and 0x04) then node
 * vars: param_1=node; +0xd=nil flag; +0x28..0x3c=wstring1; +0x10..0x24=wstring0
 */
/* Global::SpeechTree_destroyRec @ 0041a090 */

void SpeechTree_destroyRec(int *node)

{
  char cVar1;
  int *parent;
  
  cVar1 = *(char *)((int)node + 0xd);
  while (cVar1 == '\0') {
    SpeechTree_destroyRec((int *)node[2]);
    parent = (int *)*node;
    if (7 < (uint)node[0xf]) {
      operator_delete((void *)node[10]);
    }
    node[0xf] = 7;
    node[0xe] = 0;
    *(undefined2 *)(node + 10) = 0;
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




/* [AUDIT] proposed: SpeechMap_eraseRange  (confidence: high)
 * purpose: Erases iterator range from a map/set, advancing via tree successor and calling erase-node per element
 * vars: this=map; param_2=first,param_3=last iters; special-case full clear
 */
/* Global::SpeechMap_eraseRange @ 0041a180 */

undefined4 * __thiscall SpeechMap_eraseRange(void *this,undefined4 *out_it,int *first,int *last)

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
    SpeechTree_destroyRec((int *)piVar2[1]);
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
    RBTree_eraseNode(this,&self,piVar3);
    piVar3 = first;
  }
  *out_it = piVar3;
  return out_it;
}




/* [AUDIT] proposed: Speech_parseTextToNodes  (confidence: high)
 * purpose: Parses dialogue text into a QuestTextNode tree, splitting on spaces and {} / [] markup markers
 * vars: this=Speech; out_it=wstring text; '{'=0x7b type2,'['=0x5b type3; builds node list
 */
/* Global::Speech_parseTextToNodes @ 0041b050 */

void __thiscall Speech_parseTextToNodes(void *this,undefined4 *text)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  int *node_list;
  int iVar7;
  undefined4 **ppuVar8;
  undefined4 *puVar9;
  int iVar10;
  short ****ppppsVar11;
  undefined4 **ppuVar12;
  uint extraout_ECX;
  uint uVar13;
  short *psVar14;
  undefined4 **extraout_EDX;
  uint count;
  int in_stack_00000014;
  uint in_stack_00000018;
  undefined4 local_68 [2];
  undefined4 local_60 [2];
  void *local_58;
  undefined4 *local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  int *local_44;
  uint local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  int char_index;
  undefined4 *local_30;
  short ***local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054bdf5;
  local_10 = ExceptionList;
  local_14 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar9 = (undefined4 *)((int)this + 4);
  local_8 = 0;
  local_58 = this;
  if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 4))(1,local_14);
    *puVar9 = 0;
  }
  local_54 = operator_new(0x44);
  local_8._0_1_ = 1;
  if (local_54 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = cube::QuestTextNode::ctor_0(local_54);
  }
  *puVar9 = puVar5;
  local_8._0_1_ = 0;
  Tree_destroyRec_oneStr(*(int **)(*(int *)((int)this + 8) + 4));
  *(int *)(*(int *)((int)this + 8) + 4) = *(int *)((int)this + 8);
  *(undefined4 *)*(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 8);
  *(int *)(*(int *)((int)this + 8) + 8) = *(int *)((int)this + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  local_40 = 0;
  node_list = (int *)std_List_node_alloc_0xc((undefined4 *)0x0,(undefined4 *)0x0);
  local_8._0_1_ = 2;
  local_44 = node_list;
  iVar7 = std_list_insertNode1(node_list,(undefined4 *)node_list[1],puVar9);
  node_list[1] = iVar7;
  **(int **)(iVar7 + 4) = iVar7;
  count = 1;
  local_40 = 1;
  local_54 = (undefined4 *)in_stack_00000014;
  local_50 = -1;
  char_index = 0;
  uVar13 = in_stack_00000018;
  ppuVar12 = (undefined4 **)text;
  if (-1 < in_stack_00000014) {
    do {
      iVar7 = char_index;
      ppuVar8 = &text;
      if (7 < uVar13) {
        ppuVar8 = ppuVar12;
      }
      if (*(short *)((int)ppuVar8 + char_index * 2) == 0x20) {
LAB_0041b1f8:
        ppuVar8 = &text;
        if (7 < uVar13) {
          ppuVar8 = ppuVar12;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x7b) {
          local_30 = operator_new(0x44);
          local_8._0_1_ = 3;
          if (local_30 == (undefined4 *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            puVar9 = cube::QuestTextNode::ctor_0(local_30);
          }
          puVar9[0x10] = 2;
          local_38 = (undefined4 *)(*(int *)(node_list[1] + 8) + 0x38);
          local_48 = (undefined4 *)*local_38;
          local_8._0_1_ = 2;
          local_3c = puVar9;
          local_30 = (undefined4 *)std_list_insertNode1(local_48,(undefined4 *)local_48[1],&local_3c);
          if (local_38[1] == 0x15555554) goto LAB_0041b8eb;
          local_38[1] = local_38[1] + 1;
          local_48[1] = local_30;
          *(undefined4 **)local_30[1] = local_30;
          puVar9[0xd] = *(undefined4 *)(node_list[1] + 8);
          iVar7 = std_list_insertNode1(node_list,(undefined4 *)node_list[1],&local_3c);
          if (count == 0x15555554) goto LAB_0041b8eb;
          node_list[1] = iVar7;
          **(int **)(iVar7 + 4) = iVar7;
          local_40 = count + 1;
          local_30 = operator_new(0x44);
          local_8._0_1_ = 4;
          if (local_30 == (undefined4 *)0x0) {
            local_3c = (undefined4 *)0x0;
          }
          else {
            local_3c = cube::QuestTextNode::ctor_0(local_30);
          }
          iVar7 = *(int *)(node_list[1] + 8);
          local_30 = *(undefined4 **)(iVar7 + 0x38);
          local_8._0_1_ = 2;
          local_38 = local_3c;
          iVar10 = std_list_insertNode1(local_30,(undefined4 *)local_30[1],&local_38);
          if (*(int *)(iVar7 + 0x3c) == 0x15555554) goto LAB_0041b8eb;
          *(int *)(iVar7 + 0x3c) = *(int *)(iVar7 + 0x3c) + 1;
          local_30[1] = iVar10;
          **(int **)(iVar10 + 4) = iVar10;
          local_3c[0xd] = *(undefined4 *)(node_list[1] + 8);
          iVar7 = std_list_insertNode1(node_list,(undefined4 *)node_list[1],&local_38);
          if (count + 1 == 0x15555554) goto LAB_0041b8eb;
          node_list[1] = iVar7;
          count = count + 2;
          **(int **)(iVar7 + 4) = iVar7;
          local_40 = count;
          uVar13 = in_stack_00000018;
          ppuVar12 = (undefined4 **)text;
          iVar7 = char_index;
        }
        ppuVar8 = &text;
        if (7 < uVar13) {
          ppuVar8 = ppuVar12;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x5b) {
          local_30 = operator_new(0x44);
          local_8._0_1_ = 5;
          if (local_30 == (undefined4 *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            puVar9 = cube::QuestTextNode::ctor_0(local_30);
          }
          puVar9[0x10] = 3;
          local_30 = (undefined4 *)(*(int *)(node_list[1] + 8) + 0x38);
          local_48 = (undefined4 *)*local_30;
          local_8._0_1_ = 2;
          local_38 = puVar9;
          local_3c = (undefined4 *)std_list_insertNode1(local_48,(undefined4 *)local_48[1],&local_38);
          if (local_30[1] == 0x15555554) goto LAB_0041b8eb;
          local_30[1] = local_30[1] + 1;
          local_48[1] = local_3c;
          *(undefined4 **)local_3c[1] = local_3c;
          puVar9[0xd] = *(undefined4 *)(node_list[1] + 8);
          iVar7 = std_list_insertNode1(node_list,(undefined4 *)node_list[1],&local_38);
          if (count == 0x15555554) goto LAB_0041b8eb;
          node_list[1] = iVar7;
          count = count + 1;
          **(int **)(iVar7 + 4) = iVar7;
          local_40 = count;
          uVar13 = in_stack_00000018;
          ppuVar12 = (undefined4 **)text;
        }
        if ((int)(local_50 + 1U) < char_index) {
LAB_0041b489:
          wstring_ctorFromSubstr(&text,(undefined2 *)local_2c,local_50 + 1U,(char_index - local_50) - 1);
          ppppsVar11 = local_2c;
          if (7 < local_18) {
            ppppsVar11 = (short ****)local_2c[0];
          }
          local_8._0_1_ = 6;
          if (*(short *)ppppsVar11 == 0x23) {
            SpeechMap_findOrInsert((void *)(*(int *)(node_list[1] + 8) + 4),local_68,(undefined4 *)0x0,
                         (ushort *)local_2c,(uint)DAT_00583d7a);
          }
          else {
            ppppsVar11 = local_2c;
            if (7 < local_18) {
              ppppsVar11 = (short ****)local_2c[0];
            }
            if (*(short *)ppppsVar11 == 0x24) {
              SpeechMap_findOrInsert((void *)(*(int *)(node_list[1] + 8) + 0x14),local_60,(undefined4 *)0x0,
                           (ushort *)local_2c,(uint)DAT_00583d7a);
            }
            else {
              local_30 = operator_new(0x44);
              local_8._0_1_ = 7;
              if (local_30 == (undefined4 *)0x0) {
                puVar9 = (undefined4 *)0x0;
              }
              else {
                puVar9 = cube::QuestTextNode::ctor_0(local_30);
              }
              local_8._0_1_ = 6;
              local_30 = puVar9;
              if ((short ****)(puVar9 + 7) != local_2c) {
                U16String_assignSubstr(puVar9 + 7,(int *)local_2c,0,0xffffffff);
              }
              local_48 = (undefined4 *)(*(int *)(node_list[1] + 8) + 0x38);
              local_38 = (undefined4 *)*local_48;
              local_30 = (undefined4 *)std_list_insertNode1(local_38,(undefined4 *)local_38[1],&local_30);
              if (local_48[1] == 0x15555554) goto LAB_0041b8eb;
              local_48[1] = local_48[1] + 1;
              local_38[1] = local_30;
              *(undefined4 **)local_30[1] = local_30;
              puVar9[0xd] = *(undefined4 *)(node_list[1] + 8);
              ppuVar12 = &text;
              if (7 < in_stack_00000018) {
                ppuVar12 = (undefined4 **)text;
              }
              sVar1 = *(short *)((int)ppuVar12 + char_index * 2);
              if (((((sVar1 == 0x2e) || (sVar1 == 0x3a)) || (sVar1 == 0x2d)) ||
                  (((sVar1 == 0x2c || (sVar1 == 0x3b)) ||
                   ((sVar1 == 0x21 || ((sVar1 == 0x3f || (sVar1 == 0x2f)))))))) ||
                 ((sVar1 == 0x28 || (sVar1 == 0x29)))) {
                ppuVar12 = &text;
                if (7 < in_stack_00000018) {
                  ppuVar12 = (undefined4 **)text;
                }
                local_4c._0_2_ = *(short *)((int)ppuVar12 + char_index * 2);
                local_4c._2_2_ = 0;
                local_30 = operator_new(0x44);
                local_8._0_1_ = 8;
                if (local_30 == (undefined4 *)0x0) {
                  puVar9 = (undefined4 *)0x0;
                }
                else {
                  puVar9 = cube::QuestTextNode::ctor_0(local_30);
                }
                local_8._0_1_ = 6;
                local_30 = puVar9;
                if ((short)local_4c == 0) {
                  uVar13 = 0;
                }
                else {
                  psVar14 = (short *)&local_4c;
                  do {
                    sVar1 = *psVar14;
                    psVar14 = psVar14 + 1;
                  } while (sVar1 != 0);
                  uVar13 = (int)psVar14 - ((int)&local_4c + 2) >> 1;
                }
                U16String_assignPtrCount(puVar9 + 7,&local_4c,uVar13);
                puVar9[0x10] = 1;
                puVar9[0xd] = *(undefined4 *)(node_list[1] + 8);
                iVar7 = *(int *)(node_list[1] + 8);
                local_48 = *(undefined4 **)(iVar7 + 0x38);
                iVar10 = std_list_insertNode1(local_48,(undefined4 *)local_48[1],&local_30);
                if (*(int *)(iVar7 + 0x3c) == 0x15555554) goto LAB_0041b8eb;
                *(int *)(iVar7 + 0x3c) = *(int *)(iVar7 + 0x3c) + 1;
                local_48[1] = iVar10;
                **(int **)(iVar10 + 4) = iVar10;
              }
            }
          }
          local_8._0_1_ = 2;
          ppuVar12 = (undefined4 **)text;
          if (7 < local_18) {
            operator_delete(local_2c[0]);
            ppuVar12 = (undefined4 **)text;
          }
        }
        else {
          ppuVar8 = &text;
          if (7 < uVar13) {
            ppuVar8 = ppuVar12;
          }
          sVar1 = *(short *)((int)ppuVar8 + char_index * 2);
          if (((((((sVar1 == 0x2e) || (sVar1 == 0x3a)) || (sVar1 == 0x2d)) ||
                ((sVar1 == 0x2c || (sVar1 == 0x3b)))) ||
               ((sVar1 == 0x21 || ((sVar1 == 0x3f || (sVar1 == 0x2f)))))) || (sVar1 == 0x28)) ||
             (sVar1 == 0x29)) goto LAB_0041b489;
        }
        ppuVar8 = &text;
        if (7 < in_stack_00000018) {
          ppuVar8 = ppuVar12;
        }
        local_50 = char_index;
        if (*(short *)((int)ppuVar8 + char_index * 2) == 0x7c) {
          if (count < 2) goto LAB_0041b894;
          piVar2 = (int *)node_list[1];
          if (piVar2 != node_list) {
            *(int *)piVar2[1] = *piVar2;
            *(int *)(*piVar2 + 4) = piVar2[1];
            operator_delete(piVar2);
            count = count - 1;
            local_40 = count;
          }
          local_30 = operator_new(0x44);
          local_8._0_1_ = 9;
          if (local_30 == (undefined4 *)0x0) {
            local_3c = (undefined4 *)0x0;
          }
          else {
            local_3c = cube::QuestTextNode::ctor_0(local_30);
          }
          iVar7 = *(int *)(node_list[1] + 8);
          local_30 = *(undefined4 **)(iVar7 + 0x38);
          local_8._0_1_ = 2;
          local_38 = local_3c;
          iVar10 = std_list_insertNode1(local_30,(undefined4 *)local_30[1],&local_3c);
          if (*(int *)(iVar7 + 0x3c) == 0x15555554) {
LAB_0041b8eb:
            std::_Xlength_error("list<T> too long");
          }
          *(int *)(iVar7 + 0x3c) = *(int *)(iVar7 + 0x3c) + 1;
          local_30[1] = iVar10;
          **(int **)(iVar10 + 4) = iVar10;
          local_38[0xd] = *(undefined4 *)(node_list[1] + 8);
          iVar7 = std_list_insertNode1(node_list,(undefined4 *)node_list[1],&local_3c);
          if (count == 0x15555554) goto LAB_0041b8eb;
          node_list[1] = iVar7;
          count = count + 1;
          **(int **)(iVar7 + 4) = iVar7;
          local_40 = count;
          ppuVar12 = (undefined4 **)text;
        }
        ppuVar8 = &text;
        if (7 < in_stack_00000018) {
          ppuVar8 = ppuVar12;
        }
        if (*(short *)((int)ppuVar8 + char_index * 2) == 0x7d) {
          if (count < 3) goto LAB_0041b894;
          piVar2 = (int *)node_list[1];
          if (piVar2 != node_list) {
            *(int *)piVar2[1] = *piVar2;
            *(int *)(*piVar2 + 4) = piVar2[1];
            operator_delete(piVar2);
            count = count - 1;
            local_40 = count;
            ppuVar12 = (undefined4 **)text;
          }
          piVar2 = (int *)node_list[1];
          if (piVar2 != node_list) {
            *(int *)piVar2[1] = *piVar2;
            *(int *)(*piVar2 + 4) = piVar2[1];
            operator_delete(piVar2);
            count = count - 1;
            local_40 = count;
            ppuVar12 = (undefined4 **)text;
          }
        }
        ppuVar8 = &text;
        if (7 < in_stack_00000018) {
          ppuVar8 = ppuVar12;
        }
        uVar13 = in_stack_00000018;
        iVar7 = char_index;
        if (*(short *)((int)ppuVar8 + char_index * 2) == 0x5d) {
          if (count < 2) goto LAB_0041b894;
          piVar2 = (int *)node_list[1];
          if (piVar2 != node_list) {
            *(int *)piVar2[1] = *piVar2;
            *(int *)(*piVar2 + 4) = piVar2[1];
            operator_delete(piVar2);
            count = count - 1;
            local_40 = count;
            uVar13 = in_stack_00000018;
            ppuVar12 = (undefined4 **)text;
            iVar7 = char_index;
          }
        }
      }
      else {
        ppuVar8 = &text;
        if (7 < uVar13) {
          ppuVar8 = ppuVar12;
        }
        if (*(short *)((int)ppuVar8 + char_index * 2) == 10) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < uVar13) {
          ppuVar8 = ppuVar12;
        }
        if (*(short *)((int)ppuVar8 + char_index * 2) == 9) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < uVar13) {
          ppuVar8 = ppuVar12;
        }
        if (*(short *)((int)ppuVar8 + char_index * 2) == 0) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < uVar13) {
          ppuVar8 = ppuVar12;
        }
        uVar4 = isPunctuation(*(short *)((int)ppuVar8 + char_index * 2));
        uVar13 = extraout_ECX;
        ppuVar12 = extraout_EDX;
        if ((char)uVar4 != '\0') goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < extraout_ECX) {
          ppuVar8 = extraout_EDX;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x7b) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < extraout_ECX) {
          ppuVar8 = extraout_EDX;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x7d) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < extraout_ECX) {
          ppuVar8 = extraout_EDX;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x5b) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < extraout_ECX) {
          ppuVar8 = extraout_EDX;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x5d) goto LAB_0041b1f8;
        ppuVar8 = &text;
        if (7 < extraout_ECX) {
          ppuVar8 = extraout_EDX;
        }
        if (*(short *)((int)ppuVar8 + iVar7 * 2) == 0x7c) goto LAB_0041b1f8;
      }
      char_index = iVar7 + 1;
    } while (iVar7 + 1 <= (int)local_54);
  }
  QuestTextNode_copyRec(local_58,*(uint *)((int)local_58 + 4));
LAB_0041b894:
  piVar2 = (int *)*node_list;
  *node_list = (int)node_list;
  node_list[1] = (int)node_list;
  while (piVar2 != node_list) {
    piVar3 = (int *)*piVar2;
    operator_delete(piVar2);
    piVar2 = piVar3;
  }
  operator_delete(node_list);
  if (7 < in_stack_00000018) {
    operator_delete(text);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: identityReturn  (confidence: high)
 * purpose: Returns its argument unchanged (thunk/identity)
 * vars: text returned as-is
 */
/* Global::identityReturn @ 0041cba0 */

undefined4 __fastcall identityReturn(undefined4 value)

{
  return value;
}




/* [AUDIT] proposed: wistream_extractWord  (confidence: high)
 * purpose: operator>>(wistream, wstring): skips to non-space, reads word chars until whitespace/EOF into string
 * vars: value=wistream; param_2=out wstring; ctype::is(0x48=space); width limit
 */
/* Global::wistream_extractWord @ 00428ef0 */

basic_istream<wchar_t,std::char_traits<wchar_t>_> *
wistream_extractWord(basic_istream<wchar_t,std::char_traits<wchar_t>_> *in_stream,undefined4 *out_str)

{
  int vtbl_off;
  bool got_char;
  bool prefix_ok;
  wchar_t wVar4;
  locale *locale_ptr;
  facet *this;
  undefined4 *puVar6;
  basic_istream<wchar_t,std::char_traits<wchar_t>_> *eof_ret;
  int err_state;
  int *facet_check;
  uint max_count;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054ca68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  err_state = 0;
  got_char = false;
  if (*(int **)(in_stream + *(int *)(*(int *)in_stream + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_stream + *(int *)(*(int *)in_stream + 4) + 0x38) + 4))();
  }
  local_8 = 0;
  prefix_ok = std::basic_istream<wchar_t,std::char_traits<wchar_t>_>::_Ipfx(in_stream,false);
  local_8 = 1;
  if (prefix_ok) {
    locale_ptr = (locale *)std::ios_base::getloc((ios_base *)(in_stream + *(int *)(*(int *)in_stream + 4)));
    local_8._0_1_ = 2;
    this = std_use_facet_ctype_wchar(locale_ptr);
    local_8._0_1_ = 1;
    if ((facet_check != (int *)0x0) &&
       (puVar6 = (undefined4 *)(**(code **)(*facet_check + 8))(), puVar6 != (undefined4 *)0x0)) {
      (**(code **)*puVar6)(1);
    }
    out_str[4] = 0;
    puVar6 = out_str;
    if (7 < (uint)out_str[5]) {
      puVar6 = (undefined4 *)*out_str;
    }
    *(undefined2 *)puVar6 = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    vtbl_off = *(int *)(*(int *)in_stream + 4);
    max_count = *(uint *)(in_stream + vtbl_off + 0x20);
    if ((*(int *)(in_stream + vtbl_off + 0x24) < 0) ||
       (((*(int *)(in_stream + vtbl_off + 0x24) < 1 && (max_count == 0)) || (0x7ffffffd < max_count)))) {
      max_count = 0x7ffffffe;
    }
    wVar4 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::sgetc
                      (*(basic_streambuf<wchar_t,std::char_traits<wchar_t>_> **)
                        (in_stream + vtbl_off + 0x38));
    while (max_count != 0) {
      if (wVar4 == L'\xffff') {
        eof_ret = (basic_istream<wchar_t,std::char_traits<wchar_t>_> *)wistream_extractWord_ehExit();
        return eof_ret;
      }
      prefix_ok = std::ctype<wchar_t>::is((ctype<wchar_t> *)this,0x48,wVar4);
      if (prefix_ok) break;
      U16String_appendFill(out_str,1,wVar4);
      max_count = max_count - 1;
      got_char = true;
      wVar4 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::snextc
                        (*(basic_streambuf<wchar_t,std::char_traits<wchar_t>_> **)
                          (in_stream + *(int *)(*(int *)in_stream + 4) + 0x38));
    }
  }
  local_8 = 1;
  vtbl_off = *(int *)(*(int *)in_stream + 4);
  *(undefined4 *)(in_stream + vtbl_off + 0x20) = 0;
  *(undefined4 *)(in_stream + vtbl_off + 0x24) = 0;
  if (!got_char) {
    err_state = 2;
  }
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (in_stream + *(int *)(*(int *)in_stream + 4)),err_state,false);
  local_8 = 0xffffffff;
  if (*(int **)(in_stream + *(int *)(*(int *)in_stream + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_stream + *(int *)(*(int *)in_stream + 4) + 0x38) + 8))();
  }
  ExceptionList = local_10;
  return in_stream;
}




/* [AUDIT] proposed: wistream_extractWord_ehExit  (confidence: low)
 * purpose: SEH/exception cleanup tail for extractWord: sets stream state and releases streambuf sentry
 * vars: uses unaff regs from parent frame; EBP-relative locals
 */
/* Global::wistream_extractWord_ehExit @ 00429060 */

void wistream_extractWord_ehExit(void)

{
  char got_char;
  int *stream_obj;
  int vtbl_off;
  uint err_state;
  int unaff_EBP;
  int *stream_base;
  
  stream_obj = *(int **)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  got_char = *(char *)(unaff_EBP + -0x11);
  vtbl_off = *(int *)(*stream_base + 4);
  *(undefined4 *)(vtbl_off + 0x20 + (int)stream_base) = 0;
  *(undefined4 *)(vtbl_off + 0x24 + (int)stream_base) = 0;
  if (got_char == '\0') {
    err_state = err_state | 2;
  }
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (*(int *)(*stream_base + 4) + (int)stream_base),err_state,false);
  vtbl_off = *stream_obj;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  stream_obj = *(int **)(*(int *)(vtbl_off + 4) + 0x38 + (int)stream_obj);
  if (stream_obj != (int *)0x0) {
    (**(code **)(*stream_obj + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}




/* cube::Speech::ctor_0 @ 0042b220 */

void __fastcall cube::Speech::ctor_0(undefined4 *self)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  uint *puVar5;
  uint uVar6;
  void *pvVar7;
  undefined *puVar8;
  int iVar9;
  undefined4 ****ppppuVar10;
  int **this;
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *pbVar11;
  undefined4 *field_ptr;
  undefined4 *puVar13;
  int *piVar14;
  uint index;
  undefined4 *puVar16;
  ushort *puVar17;
  wchar_t *pwVar18;
  int local_298 [2];
  int local_290;
  int iStack_28c;
  undefined **local_288 [3];
  int iStack_27c;
  undefined **local_278;
  undefined **local_270 [2];
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> local_268 [72];
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_220 [72];
  undefined4 *local_1d8;
  int local_1d4;
  undefined4 local_1d0 [2];
  int local_1c8;
  undefined4 local_1c4;
  int local_1c0;
  undefined4 local_1bc [2];
  int local_1b4;
  undefined4 local_1b0 [2];
  int local_1a8;
  int local_1a4;
  int local_1a0;
  uint local_19c;
  undefined4 *local_198;
  undefined4 database [2];
  undefined4 *local_18c;
  undefined4 *local_188;
  undefined4 *local_184;
  uint count;
  uint *xml_buf_begin;
  uint *xml_buf_end;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 *local_16c;
  undefined4 local_168 [2];
  undefined4 local_160 [2];
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *local_158;
  int *local_154;
  int *local_150;
  int *local_14c;
  int local_148;
  undefined4 stmt;
  undefined4 *local_140;
  undefined4 local_13c [2];
  undefined4 *local_134;
  int xml_reader [50];
  undefined8 local_68;
  void *local_5c [4];
  uint local_4c;
  uint local_48;
  void *local_44 [4];
  int local_34;
  uint local_30;
  undefined4 ***temp_str [4];
  uint local_1c;
  uint local_18;
  uint security_cookie;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cf6b;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  index = 0;
  count = 0;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  local_1d8 = self;
  local_140 = self;
  uVar3 = std_map_makeHeader_0x38();
  self[1] = uVar3;
  field_ptr = self + 3;
  local_8 = 0;
  *field_ptr = 0;
  self[4] = 0;
  local_198 = field_ptr;
  uVar3 = QuestTextNode_allocSentinel64();
  *field_ptr = uVar3;
  field_ptr = self + 5;
  local_8._0_1_ = 1;
  *field_ptr = 0;
  self[6] = 0;
  local_184 = field_ptr;
  uVar3 = QuestTextNode_allocSentinel64();
  *field_ptr = uVar3;
  field_ptr = self + 7;
  local_8._0_1_ = 2;
  *field_ptr = 0;
  self[8] = 0;
  local_18c = field_ptr;
  uVar3 = QuestTextNode_allocSentinel64();
  *field_ptr = uVar3;
  field_ptr = self + 9;
  local_8._0_1_ = 3;
  *field_ptr = 0;
  self[10] = 0;
  local_188 = field_ptr;
  uVar3 = QuestTextNode_allocSentinel64();
  *field_ptr = uVar3;
  local_8._0_1_ = 4;
  self[0xb] = 0;
  self[0xc] = 0;
  uVar3 = QuestTextNode_allocSentinel64();
  self[0xb] = uVar3;
  field_ptr = self + 0xd;
  local_8._0_1_ = 5;
  *field_ptr = 0;
  self[0xe] = 0;
  local_16c = field_ptr;
  uVar3 = QuestTextNode_allocSentinel64();
  puVar13 = local_140;
  *field_ptr = uVar3;
  local_8._0_1_ = 6;
  local_134 = local_140 + 0xf;
  *local_134 = 0;
  local_140[0x10] = 0;
  uVar3 = std_map_makeHeader_0x2c();
  puVar13[0xf] = uVar3;
  local_8._0_1_ = 7;
  puVar13[0x11] = 0;
  puVar13[0x12] = 0;
  uVar3 = std_map_makeHeader_0x2c();
  puVar13[0x11] = uVar3;
  local_8._0_1_ = 8;
  puVar13[0x13] = 0;
  puVar13[0x14] = 0;
  uVar3 = std_map_makeHeader_0x2c();
  puVar13[0x13] = uVar3;
  local_8._0_1_ = 9;
  XmlDoc_ctorInit(xml_reader);
  local_8._0_1_ = 10;
  Database::ctor_1(database);
  local_8._0_1_ = 0xb;
  local_18 = 0xf;
  local_1c = 0;
  temp_str[0] = (undefined4 ***)((uint)temp_str[0] & 0xffffff00);
  String_assign(temp_str,(int *)"data4.db",8);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  SpeechDb_createBlobsTable(database,(int *)temp_str);
  if (0xf < local_18) {
    operator_delete(temp_str[0]);
  }
  xml_buf_begin = (uint *)0x0;
  xml_buf_end = (uint *)0x0;
  local_174 = 0;
  local_170 = 0;
  local_8._0_1_ = 0xd;
  local_18 = 0xf;
  local_1c = 0;
  temp_str[0] = (undefined4 ***)((uint)temp_str[0] & 0xffffff00);
  String_assign(temp_str,(int *)"dict_en.xml",0xb);
  local_8._0_1_ = 0xe;
  SpeechDb_loadBlobToVector(database,temp_str,&xml_buf_begin);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  if (0xf < local_18) {
    operator_delete(temp_str[0]);
  }
  Speech_scrambleBlob((int *)&xml_buf_begin);
  if (0 < (int)xml_buf_end - (int)xml_buf_begin) {
    stmt = 0;
    puVar5 = xml_buf_begin;
    if (xml_buf_begin == xml_buf_end) {
      puVar5 = (uint *)0x0;
    }
    puVar16 = (undefined4 *)0x42b48b;
    piVar4 = (int *)Xml_loadAndParse(xml_reader,&local_68,puVar5,(int)xml_buf_end - (int)xml_buf_begin,0x74,0);
    if (*piVar4 == 0) {
      Xml_getRootValue(xml_reader,&stmt);
      Xml_getFirstChildHandle(&stmt,local_13c);
      puVar5 = (uint *)Xml_getRootHandle(&stmt,local_1bc);
      uVar6 = Iterator_notEqual(local_13c,puVar5);
      cVar2 = (char)uVar6;
      while (cVar2 != '\0') {
        piVar4 = (int *)identityReturn(local_13c);
        piVar4 = (int *)Xml_getNodeName(piVar4);
        local_48 = 7;
        local_4c = 0;
        local_5c[0] = (void *)((uint)local_5c[0] & 0xffff0000);
        if ((short)*piVar4 == 0) {
          uVar6 = 0;
        }
        else {
          piVar14 = piVar4;
          do {
            iVar9 = *piVar14;
            piVar14 = (int *)((int)piVar14 + 2);
          } while ((short)iVar9 != 0);
          uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
        }
        U16String_assignPtrCount(local_5c,piVar4,uVar6);
        puVar17 = (ushort *)&DAT_0055b2e0;
        piVar4 = &local_1b4;
        local_8._0_1_ = 0xf;
        pvVar7 = (void *)identityReturn(local_13c);
        piVar4 = (int *)Xml_findAttributeByName(pvVar7,piVar4,puVar17);
        piVar4 = (int *)Xml_getNodeName(piVar4);
        local_30 = 7;
        local_34 = 0;
        local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
        if ((short)*piVar4 == 0) {
          uVar6 = 0;
        }
        else {
          piVar14 = piVar4;
          do {
            iVar9 = *piVar14;
            piVar14 = (int *)((int)piVar14 + 2);
          } while ((short)iVar9 != 0);
          uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
        }
        U16String_assignPtrCount(local_44,piVar4,uVar6);
        local_8._0_1_ = 0x10;
        uVar1 = (undefined1)local_8;
        local_8._0_1_ = 0x10;
        puVar13 = local_140;
        if (local_34 != 0) {
          piVar4 = (int *)wstring_compareSubstr(local_5c,0,local_4c,(ushort *)L"name",4);
          if (piVar4 == (int *)0x0) {
            local_154 = piVar4;
            local_150 = piVar4;
            local_154 = (int *)QuestTextNode_allocSentinel64();
            local_8._0_1_ = 0x11;
            local_14c = (int *)0x0;
            local_148 = 0;
            local_14c = (int *)std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
            field_ptr = local_168;
            local_8 = CONCAT31(local_8._1_3_,0x12);
            pvVar7 = (void *)identityReturn(local_13c);
            Xml_getFirstChildHandle(pvVar7,field_ptr);
            field_ptr = local_1b0;
            pvVar7 = (void *)identityReturn(local_13c);
            puVar5 = (uint *)Xml_getRootHandle(pvVar7,field_ptr);
            uVar6 = Iterator_notEqual(local_168,puVar5);
            cVar2 = (char)uVar6;
            while (cVar2 != '\0') {
              piVar4 = (int *)identityReturn(local_168);
              puVar8 = Xml_getNodeName(piVar4);
              if (puVar8 != (undefined *)0x0) {
                piVar4 = (int *)identityReturn(local_168);
                puVar8 = Xml_getFirstTextValue(piVar4);
                if (puVar8 != (undefined *)0x0) {
                  piVar4 = (int *)identityReturn(local_168);
                  piVar4 = (int *)Xml_getNodeName(piVar4);
                  U16String_ctorFromCStr(temp_str,piVar4);
                  local_8._0_1_ = 0x13;
                  piVar4 = (int *)identityReturn(local_168);
                  piVar4 = (int *)Xml_getFirstTextValue(piVar4);
                  pvVar7 = (void *)std_map_insert_strToStr(&local_154,(ushort *)temp_str);
                  if ((short)*piVar4 == 0) {
                    uVar6 = 0;
                  }
                  else {
                    piVar14 = piVar4;
                    do {
                      iVar9 = *piVar14;
                      piVar14 = (int *)((int)piVar14 + 2);
                    } while ((short)iVar9 != 0);
                    uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
                  }
                  U16String_assignPtrCount(pvVar7,piVar4,uVar6);
                  local_8 = CONCAT31(local_8._1_3_,0x12);
                  if (7 < local_18) {
                    operator_delete(temp_str[0]);
                  }
                }
              }
              Iterator_derefAndAdvance(local_168,local_298);
              field_ptr = local_1b0;
              pvVar7 = (void *)identityReturn(local_13c);
              puVar5 = (uint *)Xml_getRootHandle(pvVar7,field_ptr);
              uVar6 = Iterator_notEqual(local_168,puVar5);
              cVar2 = (char)uVar6;
            }
            pwVar18 = L"tags";
            piVar4 = &local_1c8;
            pvVar7 = (void *)identityReturn(local_13c);
            piVar4 = (int *)Xml_findAttributeByName(pvVar7,piVar4,(ushort *)pwVar18);
            iVar9 = compareResultToSign(piVar4);
            if (iVar9 != -1) {
              pwVar18 = L"tags";
              piVar4 = &local_1d4;
              pvVar7 = (void *)identityReturn(local_13c);
              piVar4 = (int *)Xml_findAttributeByName(pvVar7,piVar4,(ushort *)pwVar18);
              piVar4 = (int *)Xml_getNodeName(piVar4);
              local_18 = 7;
              local_1c = 0;
              temp_str[0] = (undefined4 ***)((uint)temp_str[0] & 0xffff0000);
              if ((short)*piVar4 == 0) {
                uVar6 = 0;
              }
              else {
                piVar14 = piVar4;
                do {
                  iVar9 = *piVar14;
                  piVar14 = (int *)((int)piVar14 + 2);
                } while ((short)iVar9 != 0);
                uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
              }
              U16String_assignPtrCount(temp_str,piVar4,uVar6);
              local_8._0_1_ = 0x14;
              local_288[0] = &PTR_0055b2c0;
              local_278 = &PTR_00571718;
              std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
              basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_220);
              index = index | 1;
              local_8 = CONCAT31(local_8._1_3_,0x15);
              count = index;
              std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
              basic_iostream<wchar_t,std::char_traits<wchar_t>_>
                        ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_288,
                         (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_270);
              local_8 = 0x16;
              *(undefined ***)((int)local_288 + (int)local_288[0][1]) =
                   std::
                   basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
                   vftable;
              *(undefined **)((int)&iStack_28c + (int)local_288[0][1]) = local_288[0][1] + -0x68;
              local_158 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_270;
              std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
              basic_streambuf<wchar_t,std::char_traits<wchar_t>_>(local_158);
              ppppuVar10 = temp_str;
              if (7 < local_18) {
                ppppuVar10 = (undefined4 ****)temp_str[0];
              }
              local_8 = CONCAT31(local_8._1_3_,0x17);
              local_270[0] = std::
                             basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                             ::vftable;
              std_strstreambuf_init(local_270,ppppuVar10,local_1c,0);
              if (7 < local_18) {
                operator_delete(temp_str[0]);
              }
              iVar9 = *(int *)((int)&iStack_27c + (int)local_288[0][1]);
              while (local_8._1_3_ = (undefined3)((uint)local_8 >> 8), iVar9 == 0) {
                local_18 = 7;
                local_1c = 0;
                temp_str[0] = (undefined4 ***)((uint)temp_str[0] & 0xffff0000);
                local_8 = CONCAT31(local_8._1_3_,0x1a);
                wistream_extractWord((basic_istream<wchar_t,std::char_traits<wchar_t>_> *)local_288,temp_str
                            );
                piVar4 = local_14c;
                if (local_1c != 0) {
                  iVar9 = std_list_Speech_makeStrNode(local_14c,(undefined4 *)local_14c[1],(int *)temp_str);
                  if (local_148 == 0x7fffffe) {
                    std::_Xlength_error("list<T> too long");
                  }
                  local_148 = local_148 + 1;
                  piVar4[1] = iVar9;
                  **(int **)(iVar9 + 4) = iVar9;
                }
                if (7 < local_18) {
                  operator_delete(temp_str[0]);
                }
                iVar9 = *(int *)((int)&iStack_27c + (int)local_288[0][1]);
              }
              local_8 = CONCAT31(local_8._1_3_,0x12);
              *(undefined ***)((int)local_288 + (int)local_288[0][1]) =
                   std::
                   basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
                   vftable;
              *(undefined **)((int)&iStack_28c + (int)local_288[0][1]) = local_288[0][1] + -0x68;
              local_270[0] = std::
                             basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                             ::vftable;
              Speech_clear((int)local_270);
              std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
              ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                        ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_270);
              std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
              ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>(local_268);
              std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
              ~basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_220);
            }
            this = (int **)Speech_map_insertStringEntry(local_140 + 1,(ushort *)local_44);
            if (this != &local_154) {
              SpeechTree_destroyRec((int *)(*this)[1]);
              local_19c = local_19c & 0xffffff00;
              (*this)[1] = (int)*this;
              **this = (int)*this;
              (*this)[2] = (int)*this;
              this[1] = (int *)0x0;
              std_map_copyAssign(this,(int *)&local_154,local_19c);
            }
            if (this + 2 != &local_14c) {
              std_list_assignCopy_Speech(this + 2,(undefined4 *)*local_14c,local_14c);
            }
            local_8._0_1_ = 0x10;
            std_list_clear((int *)&local_14c);
            operator_delete(local_14c);
            SpeechMap_eraseRange(&local_154,&local_1c4,(int *)*local_154,local_154);
            operator_delete(local_154);
            field_ptr = local_16c;
          }
          uVar6 = wstring_compareSubstr(local_5c,0,local_4c,(ushort *)L"sentence",8);
          if (uVar6 == 0) {
            piVar4 = (int *)identityReturn(local_13c);
            piVar4 = (int *)Xml_getFirstTextValue(piVar4);
            pvVar7 = (void *)std_map_insert_strToStr_v2(field_ptr,(ushort *)local_44);
            if ((short)*piVar4 == 0) {
              uVar6 = 0;
            }
            else {
              piVar14 = piVar4;
              do {
                iVar9 = *piVar14;
                piVar14 = (int *)((int)piVar14 + 2);
              } while ((short)iVar9 != 0);
              uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
            }
            U16String_assignPtrCount(pvVar7,piVar4,uVar6);
          }
          uVar6 = wstring_compareSubstr(local_5c,0,local_4c,(ushort *)L"landscape",9);
          if (uVar6 == 0) {
            pwVar18 = L"normal";
            piVar4 = &local_1a4;
            pvVar7 = (void *)identityReturn(local_13c);
            piVar4 = (int *)Xml_findChildByName(pvVar7,piVar4,(ushort *)pwVar18);
            piVar4 = (int *)Xml_getFirstTextValue(piVar4);
            pvVar7 = (void *)std_map_insert_strToStr_v2(local_198,(ushort *)local_44);
            if ((short)*piVar4 == 0) {
              uVar6 = 0;
            }
            else {
              piVar14 = piVar4;
              do {
                iVar9 = *piVar14;
                piVar14 = (int *)((int)piVar14 + 2);
              } while ((short)iVar9 != 0);
              uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
            }
            U16String_assignPtrCount(pvVar7,piVar4,uVar6);
            puVar17 = (ushort *)&DAT_0055b32c;
            piVar4 = &local_1a8;
            pvVar7 = (void *)identityReturn(local_13c);
            piVar4 = (int *)Xml_findChildByName(pvVar7,piVar4,puVar17);
            piVar4 = (int *)Xml_getFirstTextValue(piVar4);
            pvVar7 = (void *)std_map_insert_strToStr_v2(local_184,(ushort *)local_44);
            if ((short)*piVar4 == 0) {
              uVar6 = 0;
            }
            else {
              piVar14 = piVar4;
              do {
                iVar9 = *piVar14;
                piVar14 = (int *)((int)piVar14 + 2);
              } while ((short)iVar9 != 0);
              uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
            }
            U16String_assignPtrCount(pvVar7,piVar4,uVar6);
            puVar17 = (ushort *)&DAT_0055b334;
            piVar4 = &local_1a0;
            pvVar7 = (void *)identityReturn(local_13c);
            piVar4 = (int *)Xml_findChildByName(pvVar7,piVar4,puVar17);
            piVar4 = (int *)Xml_getFirstTextValue(piVar4);
            pvVar7 = (void *)std_map_insert_strToStr_v2(local_18c,(ushort *)local_44);
            if ((short)*piVar4 == 0) {
              uVar6 = 0;
            }
            else {
              piVar14 = piVar4;
              do {
                iVar9 = *piVar14;
                piVar14 = (int *)((int)piVar14 + 2);
              } while ((short)iVar9 != 0);
              uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
            }
            U16String_assignPtrCount(pvVar7,piVar4,uVar6);
            puVar17 = (ushort *)&DAT_0055b33c;
            piVar4 = &local_1c0;
            pvVar7 = (void *)identityReturn(local_13c);
            piVar4 = (int *)Xml_findChildByName(pvVar7,piVar4,puVar17);
            piVar4 = (int *)Xml_getFirstTextValue(piVar4);
            pvVar7 = (void *)std_map_insert_strToStr_v2(local_188,(ushort *)local_44);
            if ((short)*piVar4 == 0) {
              uVar6 = 0;
            }
            else {
              piVar14 = piVar4;
              do {
                iVar9 = *piVar14;
                piVar14 = (int *)((int)piVar14 + 2);
              } while ((short)iVar9 != 0);
              uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
            }
            U16String_assignPtrCount(pvVar7,piVar4,uVar6);
          }
          uVar6 = wstring_compareSubstr(local_5c,0,local_4c,(ushort *)L"quest",5);
          if (uVar6 == 0) {
            pbVar11 = operator_new(8);
            local_8._0_1_ = 0x1b;
            local_158 = pbVar11;
            if (pbVar11 == (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)0x0) {
              pbVar11 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)0x0;
            }
            else {
              *(undefined4 *)pbVar11 = 0;
              *(undefined4 *)(pbVar11 + 4) = 0;
              uVar3 = std_map_makeHeader_0x38();
              *(undefined4 *)pbVar11 = uVar3;
            }
            local_8._0_1_ = 0x10;
            field_ptr = (undefined4 *)std_map_insert_str(local_134,(ushort *)local_44);
            *field_ptr = pbVar11;
            field_ptr = local_160;
            pvVar7 = (void *)identityReturn(local_13c);
            Xml_getFirstChildHandle(pvVar7,field_ptr);
            field_ptr = local_1d0;
            pvVar7 = (void *)identityReturn(local_13c);
            puVar5 = (uint *)Xml_getRootHandle(pvVar7,field_ptr);
            uVar6 = Iterator_notEqual(local_160,puVar5);
            cVar2 = (char)uVar6;
            while (cVar2 != '\0') {
              piVar4 = (int *)identityReturn(local_160);
              puVar8 = Xml_getNodeName(piVar4);
              if (puVar8 != (undefined *)0x0) {
                piVar4 = (int *)identityReturn(local_160);
                puVar8 = Xml_getFirstTextValue(piVar4);
                if (puVar8 != (undefined *)0x0) {
                  piVar4 = (int *)identityReturn(local_160);
                  piVar4 = (int *)Xml_getNodeName(piVar4);
                  local_18 = 7;
                  local_1c = 0;
                  temp_str[0] = (undefined4 ***)((uint)temp_str[0] & 0xffff0000);
                  if ((short)*piVar4 == 0) {
                    index = 0;
                  }
                  else {
                    piVar14 = piVar4;
                    do {
                      iVar9 = *piVar14;
                      piVar14 = (int *)((int)piVar14 + 2);
                    } while ((short)iVar9 != 0);
                    index = (int)piVar14 - ((int)piVar4 + 2) >> 1;
                  }
                  U16String_assignPtrCount(temp_str,piVar4,index);
                  local_8._0_1_ = 0x1c;
                  piVar4 = (int *)identityReturn(local_160);
                  piVar4 = (int *)Xml_getFirstTextValue(piVar4);
                  local_158 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)
                              &stack0xfffffd40;
                  puVar16 = (undefined4 *)((uint)puVar16 & 0xffff0000);
                  if ((short)*piVar4 == 0) {
                    index = 0;
                  }
                  else {
                    piVar14 = piVar4;
                    do {
                      iVar9 = *piVar14;
                      piVar14 = (int *)((int)piVar14 + 2);
                    } while ((short)iVar9 != 0);
                    index = (int)piVar14 - ((int)piVar4 + 2) >> 1;
                  }
                  U16String_assignPtrCount(&stack0xfffffd40,piVar4,index);
                  local_8._0_1_ = 0x1d;
                  pvVar7 = (void *)QuestText::ctor_2((QuestText *)pbVar11,(ushort *)temp_str);
                  local_8._0_1_ = 0x1c;
                  Speech_parseTextToNodes(pvVar7,puVar16);
                  local_8._0_1_ = 0x10;
                  if (7 < local_18) {
                    operator_delete(temp_str[0]);
                  }
                }
              }
              Iterator_derefAndAdvance(local_160,&local_290);
              field_ptr = local_1d0;
              pvVar7 = (void *)identityReturn(local_13c);
              puVar5 = (uint *)Xml_getRootHandle(pvVar7,field_ptr);
              index = Iterator_notEqual(local_160,puVar5);
              cVar2 = (char)index;
              index = count;
            }
          }
          uVar6 = wstring_compareSubstr(local_5c,0,local_4c,(ushort *)L"speech",6);
          puVar13 = local_140;
          field_ptr = local_16c;
          uVar1 = (undefined1)local_8;
          if (uVar6 == 0) {
            local_158 = operator_new(0x10);
            local_8._0_1_ = 0x1e;
            if (local_158 == (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)0x0) {
              field_ptr = (undefined4 *)0x0;
            }
            else {
              field_ptr = QuestText::ctor_1((undefined4 *)local_158);
            }
            local_8._0_1_ = 0x10;
            puVar13 = (undefined4 *)std_map_insert_str(local_140 + 0x11,(ushort *)local_44);
            *puVar13 = field_ptr;
            piVar4 = (int *)identityReturn(local_13c);
            piVar4 = (int *)Xml_getFirstTextValue(piVar4);
            local_158 = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&stack0xfffffd40;
            puVar16 = (undefined4 *)((uint)puVar16 & 0xffff0000);
            if ((short)*piVar4 == 0) {
              uVar6 = 0;
            }
            else {
              piVar14 = piVar4;
              do {
                iVar9 = *piVar14;
                piVar14 = (int *)((int)piVar14 + 2);
              } while ((short)iVar9 != 0);
              uVar6 = (int)piVar14 - ((int)piVar4 + 2) >> 1;
            }
            U16String_assignPtrCount(&stack0xfffffd40,piVar4,uVar6);
            puVar13 = local_140;
            local_8._0_1_ = 0x1f;
            field_ptr = (undefined4 *)std_map_insert_str(local_140 + 0x11,(ushort *)local_44);
            local_8._0_1_ = 0x10;
            Speech_parseTextToNodes((void *)*field_ptr,puVar16);
            field_ptr = local_16c;
            uVar1 = (undefined1)local_8;
          }
        }
        local_8._0_1_ = uVar1;
        if (7 < local_30) {
          operator_delete(local_44[0]);
        }
        local_30 = 7;
        local_34 = 0;
        local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
        local_8 = CONCAT31(local_8._1_3_,0xd);
        if (7 < local_48) {
          operator_delete(local_5c[0]);
        }
        Iterator_derefAndAdvance(local_13c,(int *)((int)&local_68 + 4));
        puVar5 = (uint *)Xml_getRootHandle(&stmt,local_1bc);
        uVar6 = Iterator_notEqual(local_13c,puVar5);
        cVar2 = (char)uVar6;
      }
    }
  }
  local_134 = (undefined4 *)0x1;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"talk:test:1",0xb);
  local_134 = (undefined4 *)0x2;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"talk:test:2",0xb);
  local_134 = (undefined4 *)0x3;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"talk:test:3",0xb);
  local_134 = (undefined4 *)0x4;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"talk:test:4",0xb);
  local_134 = (undefined4 *)0x5;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"kill:test",9);
  local_134 = (undefined4 *)0x6;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"creature:strong",0xf);
  local_134 = (undefined4 *)0x7;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"creature:stupid",0xf);
  local_134 = (undefined4 *)0x8;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"creature:clever",0xf);
  local_134 = (undefined4 *)0x9;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"takecare:1",10);
  local_134 = (undefined4 *)0xa;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"takecare:2",10);
  local_134 = (undefined4 *)0xb;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"takecare:3",10);
  local_134 = (undefined4 *)0xc;
  pvVar7 = (void *)std_map_subscript_intKey(puVar13 + 0x13,(int *)&local_134);
  U16String_assignPtrCount(pvVar7,(int *)L"takecare:4",10);
  local_8._0_1_ = 0xb;
  if (xml_buf_begin != (uint *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&xml_buf_begin);
    operator_delete(xml_buf_begin);
    xml_buf_begin = (uint *)0x0;
    xml_buf_end = (uint *)0x0;
    local_174 = 0;
  }
  local_8._0_1_ = 10;
  Database::ctor_0(database);
  local_8 = CONCAT31(local_8._1_3_,9);
  thunk_FUN_00417cc0(xml_reader);
  ExceptionList = local_10;
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::Speech::ctor_1 @ 0042c450 */

void __fastcall cube::Speech::ctor_1(undefined4 *self)

{
  int *this;
  char is_nil;
  undefined4 *elem;
  int *node;
  undefined4 *self_ptr;
  int *parent;
  uint security_cookie;
  int *cur_node;
  undefined4 local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0054d03e;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  this = self + 0xf;
  local_8 = 9;
  cur_node = *(int **)*this;
  local_14 = self;
  if (cur_node != (int *)*this) {
    do {
      elem = (undefined4 *)cur_node[10];
      if (elem != (undefined4 *)0x0) {
        std_map_eraseRange_QuestText(elem,&local_18,*(int **)*elem,(int *)*elem);
        operator_delete((void *)*elem);
        operator_delete(elem);
      }
      if (*(char *)((int)cur_node + 0xd) == '\0') {
        node = (int *)cur_node[2];
        if (*(char *)((int)node + 0xd) == '\0') {
          is_nil = *(char *)(*node + 0xd);
          cur_node = node;
          node = (int *)*node;
          while (is_nil == '\0') {
            is_nil = *(char *)(*node + 0xd);
            cur_node = node;
            node = (int *)*node;
          }
        }
        else {
          is_nil = *(char *)(cur_node[1] + 0xd);
          parent = (int *)cur_node[1];
          node = cur_node;
          while ((cur_node = parent, is_nil == '\0' && (node == (int *)cur_node[2]))) {
            is_nil = *(char *)(cur_node[1] + 0xd);
            parent = (int *)cur_node[1];
            node = cur_node;
          }
        }
      }
    } while (cur_node != (int *)*this);
  }
  elem = local_14;
  cur_node = *(int **)local_14[0x11];
  if (cur_node != (int *)local_14[0x11]) {
    do {
      if ((undefined4 *)cur_node[10] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)cur_node[10])(1,security_cookie);
      }
      if (*(char *)((int)cur_node + 0xd) == '\0') {
        node = (int *)cur_node[2];
        if (*(char *)((int)node + 0xd) == '\0') {
          is_nil = *(char *)(*node + 0xd);
          cur_node = node;
          node = (int *)*node;
          while (is_nil == '\0') {
            is_nil = *(char *)(*node + 0xd);
            cur_node = node;
            node = (int *)*node;
          }
        }
        else {
          is_nil = *(char *)(cur_node[1] + 0xd);
          parent = (int *)cur_node[1];
          node = cur_node;
          while ((cur_node = parent, is_nil == '\0' && (node == (int *)cur_node[2]))) {
            is_nil = *(char *)(cur_node[1] + 0xd);
            parent = (int *)cur_node[1];
            node = cur_node;
          }
        }
      }
    } while (cur_node != (int *)elem[0x11]);
  }
  self_ptr = local_14;
  local_8._0_1_ = 8;
  std_map_eraseRange_strNode(local_14 + 0x13,&local_18,*(int **)local_14[0x13],(int *)local_14[0x13]);
  operator_delete((void *)self_ptr[0x13]);
  local_8._0_1_ = 7;
  Tree_eraseRange_variant(elem + 0x11,&local_18,*(int **)elem[0x11],(int *)elem[0x11]);
  operator_delete((void *)elem[0x11]);
  local_8._0_1_ = 6;
  Tree_eraseRange_variant(this,&local_18,*(int **)*this,(int *)*this);
  operator_delete((void *)*this);
  local_8._0_1_ = 5;
  SpeechMap_eraseRange(self_ptr + 0xd,&local_18,*(int **)self_ptr[0xd],(int *)self_ptr[0xd]);
  operator_delete((void *)self_ptr[0xd]);
  local_8._0_1_ = 4;
  SpeechMap_eraseRange(self_ptr + 0xb,&local_18,*(int **)self_ptr[0xb],(int *)self_ptr[0xb]);
  operator_delete((void *)self_ptr[0xb]);
  local_8._0_1_ = 3;
  SpeechMap_eraseRange(self_ptr + 9,&local_18,*(int **)self_ptr[9],(int *)self_ptr[9]);
  operator_delete((void *)self_ptr[9]);
  local_8._0_1_ = 2;
  SpeechMap_eraseRange(self_ptr + 7,&local_18,*(int **)self_ptr[7],(int *)self_ptr[7]);
  operator_delete((void *)self_ptr[7]);
  local_8._0_1_ = 1;
  SpeechMap_eraseRange(self_ptr + 5,&local_18,*(int **)self_ptr[5],(int *)self_ptr[5]);
  operator_delete((void *)self_ptr[5]);
  local_8 = (uint)local_8._1_3_ << 8;
  SpeechMap_eraseRange(self_ptr + 3,&local_18,*(int **)self_ptr[3],(int *)self_ptr[3]);
  operator_delete((void *)self_ptr[3]);
  local_8 = 0xffffffff;
  std_map_eraseRange_SpeechNode(self_ptr + 1,&local_18,*(int **)self_ptr[1],(int *)self_ptr[1]);
  operator_delete((void *)self_ptr[1]);
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: Speech_map_insertStringEntry  (confidence: med)
 * purpose: Builds a Speech map entry (string key + list + strlist via 42b040/42b180) and inserts into map (42a260); dialogue add
 * vars: local_3c key string; local_24/1c sub-lists
 */
/* Global::Speech_map_insertStringEntry @ 0042c820 */

void __thiscall Speech_map_insertStringEntry(void *this,ushort *key_str)

{
  ushort *found_node;
  ushort *key_ptr;
  uint cmp_result;
  int *new_node;
  int *val1;
  undefined4 local_50;
  void *val2;
  undefined4 local_48;
  undefined1 *local_40;
  undefined2 key_copy [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [8];
  undefined1 local_1c [8];
  uint security_cookie;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d0c8;
  local_10 = ExceptionList;
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  found_node = (ushort *)std_map_lowerBound_strKey(this,key_str);
  if (found_node != *(ushort **)this) {
    key_ptr = found_node + 8;
    if (7 < *(uint *)(found_node + 0x12)) {
      key_ptr = *(ushort **)key_ptr;
    }
    cmp_result = wstring_compareSubstr(key_str,0,*(uint *)(key_str + 8),key_ptr,*(uint *)(found_node + 0x10));
    if (-1 < (int)cmp_result) goto LAB_0042c970;
  }
  val1 = (int *)0x0;
  local_50 = 0;
  val1 = (int *)QuestTextNode_allocSentinel64();
  local_8 = 0;
  val2 = (void *)0x0;
  local_48 = 0;
  val2 = (void *)std_List_node_alloc_0x20((undefined4 *)0x0,(undefined4 *)0x0);
  local_8 = 1;
  local_28 = 7;
  local_2c = 0;
  key_copy[0] = 0;
  U16String_assignSubstr(key_copy,(int *)key_str,0,0xffffffff);
  local_40 = local_24;
  local_8._0_1_ = 2;
  std_list_copyCtor(local_24,(int *)&val1);
  local_8._0_1_ = 3;
  std_list_copyCtor_strList(local_1c,&val2);
  local_8 = CONCAT31(local_8._1_3_,4);
  new_node = std_map_Speech_allocEntryNode(this,(undefined4 *)key_copy);
  std_map_insertHint_strKey_Speech(this,&local_40,found_node,(ushort *)(new_node + 4),new_node);
  Speech_mapNode_dtor((undefined4 *)key_copy);
  local_8 = 0xffffffff;
  std_list_clear((int *)&val2);
  operator_delete(val2);
  SpeechMap_eraseRange(&val1,&local_40,(int *)*val1,val1);
  operator_delete(val1);
LAB_0042c970:
  ExceptionList = local_10;
  __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::Speech::vfunc_0 @ 0042ce60 */

undefined4 * __thiscall cube::Speech::vfunc_0(Speech *this,byte delete_flag)

{
  ctor_1((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




/* [AUDIT] proposed: Speech::clear  (confidence: med)
 * purpose: Resets/clears object: frees buffer if flag&1 set, zeroes 6 indirect pointer targets and length
 * vars: +0x3c=flags(bit0=owns buf); +0xc..+0x30=ptr fields; +0x38=count
 */
/* Global::Speech_clear @ 004ce990 */

void __fastcall Speech_clear(int node)

{
  if ((*(byte *)(node + 0x3c) & 1) != 0) {
    operator_delete((void *)**(undefined4 **)(node + 0xc));
  }
  **(undefined4 **)(node + 0xc) = 0;
  **(undefined4 **)(node + 0x1c) = 0;
  **(undefined4 **)(node + 0x2c) = 0;
  **(undefined4 **)(node + 0x10) = 0;
  **(undefined4 **)(node + 0x20) = 0;
  **(undefined4 **)(node + 0x30) = 0;
  *(uint *)(node + 0x3c) = *(uint *)(node + 0x3c) & 0xfffffffe;
  *(undefined4 *)(node + 0x38) = 0;
  return;
}




