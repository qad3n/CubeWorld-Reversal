// Server (net) — server. 7 functions. Bodies = Ghidra pseudo-C.
#include "Server.h"

/* [AUDIT] proposed: String_replaceRange  (confidence: med)
 * purpose: std::string replace/assign substring of param_1 into this; handles self-assign and grow
 * vars: param_2=pos; param_3=count; +0x10=len +0x14=cap
 */
/* Global::String_replaceRange @ 00401920 */

int * __thiscall String_replaceRange(void *this,int *src_str,uint pos,uint count)

{
  void *_Dst;
  uint copy_len;
  
  if ((uint)src_str[4] < pos) {
    std::_Xout_of_range("invalid string position");
  }
  copy_len = src_str[4] - pos;
  if (count < copy_len) {
    copy_len = count;
  }
  if (this == src_str) {
    copy_len = copy_len + pos;
    if (*(uint *)((int)this + 0x10) < copy_len) {
      std::_Xout_of_range("invalid string position");
    }
    *(uint *)((int)this + 0x10) = copy_len;
    if (0xf < *(uint *)((int)this + 0x14)) {
      *(undefined1 *)(copy_len + *(int *)this) = 0;
      String_erase(this,0,pos);
      return this;
    }
    *(undefined1 *)(copy_len + (int)this) = 0;
    String_erase(this,0,pos);
    return this;
  }
  if (copy_len == 0xffffffff) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < copy_len) {
    String_reserveGrow(this,copy_len,*(size_t *)((int)this + 0x10));
    if (copy_len == 0) {
      return this;
    }
  }
  else if (copy_len == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (0xf < *(uint *)((int)this + 0x14)) {
      **(undefined1 **)this = 0;
      return this;
    }
    *(undefined1 *)this = 0;
    return this;
  }
  if (0xf < (uint)src_str[5]) {
    src_str = (int *)*src_str;
  }
  _Dst = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
    _Dst = *(void **)this;
  }
  if (copy_len != 0) {
    memcpy(_Dst,(void *)((int)src_str + pos),copy_len);
  }
  *(uint *)((int)this + 0x10) = copy_len;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + copy_len) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + copy_len) = 0;
  return this;
}




/* [AUDIT] proposed: String_erase  (confidence: high)
 * purpose: std::string erase pos chars at pos src_str via memmove; shrinks length
 * vars: src_str=pos; pos=count; +0x10=len +0x14=cap
 */
/* Global::String_erase @ 00401c00 */

int * __thiscall String_erase(void *this,uint pos,uint count)

{
  uint size;
  void *buf;
  int new_size;
  
  size = *(uint *)((int)this + 0x10);
  if (size < pos) {
    std::_Xout_of_range("invalid string position");
  }
  if (count < size - pos) {
    if (count != 0) {
      buf = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        buf = *(void **)this;
      }
      new_size = size - count;
      if (new_size - pos != 0) {
        memmove((void *)((int)buf + pos),(void *)((int)((int)buf + pos) + count),
                new_size - pos);
      }
      *(int *)((int)this + 0x10) = new_size;
      if (0xf < *(uint *)((int)this + 0x14)) {
        *(undefined1 *)(*(int *)this + new_size) = 0;
        return this;
      }
      *(undefined1 *)((int)this + new_size) = 0;
    }
    return this;
  }
  *(uint *)((int)this + 0x10) = pos;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + pos) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + pos) = 0;
  return this;
}




/* [AUDIT] proposed: ostream_writeCString  (confidence: high)
 * purpose: std::operator<<(ostream&, const char*): pads/writes a C string honoring width/fill, sets state on error
 * vars: pos=ostream; count=C string; ostream+0x20/0x24=width; +0x38=streambuf
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




/* cube::Server::ctor_1 @ 00422e80 */

undefined4 * __thiscall cube::Server::ctor_1(Server *this,int context)

{
  undefined4 obj;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0054c717;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  *(int *)(this + 4) = context;
  *(undefined4 *)(this + 0x20) = 0xf;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0xc] = (Server)0x0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  local_8 = 1;
  uStack_7 = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  obj = buyNode80((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x34) = obj;
  local_8 = 2;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  obj = List_allocNode0x30((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x3c) = obj;
  local_8 = 3;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  obj = buyNode120((undefined4 *)0x0,(undefined4 *)0x0);
  *(undefined4 *)(this + 0x44) = obj;
  this[0x4c] = (Server)0x0;
  _local_8 = CONCAT31(uStack_7,4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(context + 0x800164);
  if (this + 0xc != (Server *)(context + 0x94)) {
    String_replaceRange(this + 0xc,(int *)(context + 0x94),0,0xffffffff);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}




/* cube::Server::ctor_0 @ 00423880 */

void __fastcall cube::Server::ctor_0(undefined4 *self)

{
  int *next;
  basic_ostream<char,std::char_traits<char>_> *this;
  int *node;
  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr
  *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054c817;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 4;
  this = ostream_writeCString((basic_ostream<char,std::char_traits<char>_> *)cout_exref,"Stopping server..."
                     );
  std::basic_ostream<char,std::char_traits<char>_>::operator<<(this,unaff_EDI);
  *(undefined1 *)(self + 0x13) = 0;
  Ordinal_3(self[9]);
  WaitForSingleObject((HANDLE)self[0x14],0xffffffff);
  next = (int *)self[0x11];
  node = (int *)*next;
  *next = (int)next;
  *(undefined4 *)(self[0x11] + 4) = self[0x11];
  self[0x12] = 0;
  if (node != (int *)self[0x11]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0x11]);
  }
  operator_delete((void *)self[0x11]);
  next = (int *)self[0xf];
  node = (int *)*next;
  *next = (int)next;
  *(undefined4 *)(self[0xf] + 4) = self[0xf];
  self[0x10] = 0;
  if (node != (int *)self[0xf]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0xf]);
  }
  operator_delete((void *)self[0xf]);
  next = (int *)self[0xd];
  node = (int *)*next;
  *next = (int)next;
  *(undefined4 *)(self[0xd] + 4) = self[0xd];
  self[0xe] = 0;
  if (node != (int *)self[0xd]) {
    do {
      next = (int *)*node;
      operator_delete(node);
      node = next;
    } while (next != (int *)self[0xd]);
  }
  operator_delete((void *)self[0xd]);
  if ((void *)self[10] != (void *)0x0) {
    operator_delete((void *)self[10]);
    self[10] = 0;
    self[0xb] = 0;
    self[0xc] = 0;
  }
  if (0xf < (uint)self[8]) {
    operator_delete((void *)self[3]);
  }
  self[8] = 0xf;
  self[7] = 0;
  *(undefined1 *)(self + 3) = 0;
  ExceptionList = local_10;
  return;
}




/* cube::Server::vfunc_0 @ 00426780 */

undefined4 * __thiscall cube::Server::vfunc_0(Server *this,byte delete_flag)

{
  ctor_0((undefined4 *)this);
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




