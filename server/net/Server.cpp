// Server (net) — server. 5 functions. Bodies = Ghidra pseudo-C.
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
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  copy_len = src_str[4] - pos;
  if (count < copy_len) {
    copy_len = count;
  }
  if (this == src_str) {
    copy_len = copy_len + pos;
    if (*(uint *)((int)this + 0x10) < copy_len) {
                    /* WARNING: Subroutine does not return */
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
                    /* WARNING: Subroutine does not return */
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
                    /* WARNING: Subroutine does not return */
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




