// crt_stl (_library) — cube. 633 functions. Bodies = Ghidra pseudo-C.
#include "crt_stl.h"

/* [AUDIT] proposed: std_ostream_insert_string  (confidence: med)
 * purpose: MSVC STL: operator<<(ostream&,string) width/pad, streambuf sputn, sentry
 * vars: param_1=ostream, param_2=string
 */
/* Global::std_ostream_insert_string @ 00401ff0 */

basic_ostream<char,std::char_traits<char>_> *
std_ostream_insert_string(basic_ostream<char,std::char_traits<char>_> *param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  basic_ostream<char,std::char_traits<char>_> *pbVar6;
  int iVar7;
  __int64 _Var8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e11e0;
  local_10 = ExceptionList;
  uVar4 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(uint *)(param_2 + 0x10);
  bVar3 = false;
  iVar5 = *(int *)(*(int *)param_1 + 4);
  uVar2 = *(uint *)(param_1 + iVar5 + 0x20);
  if ((*(int *)(param_1 + iVar5 + 0x24) < 0) ||
     (((*(int *)(param_1 + iVar5 + 0x24) < 1 && (uVar2 == 0)) || (uVar2 <= uVar1)))) {
    iVar7 = 0;
  }
  else {
    iVar7 = uVar2 - uVar1;
  }
  if (*(int **)(param_1 + iVar5 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + iVar5 + 0x38) + 4))();
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
  local_8 = 1;
  if (*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) != 0) {
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
  if ((*(uint *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x14) & 0x1c0) == 0x40) {
LAB_004020ec:
    if (0xf < *(uint *)(param_2 + 0x14)) {
      param_2 = *(char **)param_2;
    }
    _Var8 = std::basic_streambuf<char,std::char_traits<char>_>::sputn
                      (*(basic_streambuf<char,std::char_traits<char>_> **)
                        (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),param_2,
                       (ulonglong)uVar4 << 0x20);
    if (((uint)_Var8 != uVar1) || ((int)((ulonglong)_Var8 >> 0x20) != 0)) goto LAB_00402147;
  }
  else {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                        (*(basic_streambuf<char,std::char_traits<char>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                         (char)param_1[*(int *)(*(int *)param_1 + 4) + 0x40]);
      if (iVar5 == -1) {
        bVar3 = true;
        break;
      }
    }
    if (!bVar3) goto LAB_004020ec;
  }
  while ((iVar7 != 0 &&
         (iVar5 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                            (*(basic_streambuf<char,std::char_traits<char>_> **)
                              (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                             (char)param_1[*(int *)(*(int *)param_1 + 4) + 0x40]), iVar5 != -1))) {
    iVar7 = iVar7 + -1;
  }
LAB_00402147:
  iVar5 = *(int *)(*(int *)param_1 + 4);
  *(undefined4 *)(param_1 + iVar5 + 0x20) = 0;
  *(undefined4 *)(param_1 + iVar5 + 0x24) = 0;
  pbVar6 = (basic_ostream<char,std::char_traits<char>_> *)std_ostream_insert_cleanup();
  return pbVar6;
}




/* Global::eh_catchall_0040215e @ 0040215e */

undefined * Catch_All_0040215e(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_00402178;
}




/* [AUDIT] proposed: std_ostream_insert_cleanup  (confidence: low)
 * purpose: MSVC STL: SEH cleanup funclet for ostream insert (setstate/_Osfx)
 * vars: -
 */
/* Global::std_ostream_insert_cleanup @ 0040217e */

void std_ostream_insert_cleanup(void)

{
  basic_ostream<char,std::char_traits<char>_> *this;
  bool bVar1;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)(*(int *)(*unaff_EBX + 4) + (int)unaff_EBX),
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
  return;
}




/* Global::eh_catchall_00402269 @ 00402269 */

void Catch_All_00402269(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004022d9 @ 004022d9 */

void Catch_All_004022d9(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: std_fputc_nofail  (confidence: low)
 * purpose: MSVC CRT: fputc wrapper returning success bool (filebuf overflow)
 * vars: param_1=char, param_2=FILE
 */
/* Global::std_fputc_nofail @ 00402350 */

bool std_fputc_nofail(char param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = fputc((int)param_1,param_2);
  return iVar1 != -1;
}




/* Global::eh_catchall_0040249e @ 0040249e */

void Catch_All_0040249e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
}




/* Global::eh_catchall_00402633 @ 00402633 */

void Catch_All_00402633(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
}




/* Global::eh_catchall_00402aa4 @ 00402aa4 */

void Catch_All_00402aa4(void)

{
  int unaff_EBP;
  
  std_string_deleting_dtor(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00402d3b @ 00402d3b */

void Catch_All_00402d3b(void)

{
  int unaff_EBP;
  
  std_string_deleting_dtor(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: std_locale_getfacet  (confidence: med)
 * purpose: MSVC STL: _Getfacet/use_facet<codecvt> lookup, throws bad_cast on miss
 * vars: param_1=locale
 */
/* Global::std_locale_getfacet @ 004030e0 */

facet * std_locale_getfacet(locale *param_1)

{
  int iVar1;
  uint uVar2;
  _Locimp *p_Var3;
  facet *pfVar4;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1a09;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_18,0);
  local_8 = 0;
  local_14 = (facet *)DAT_0076af60;
  uVar2 = std::locale::id::operator_unsigned_int((id *)id_exref);
  iVar1 = *(int *)param_1;
  if (uVar2 < *(uint *)(iVar1 + 0xc)) {
    pfVar4 = *(facet **)(*(int *)(iVar1 + 8) + uVar2 * 4);
    if (pfVar4 != (facet *)0x0) goto LAB_004031b2;
  }
  else {
    pfVar4 = (facet *)0x0;
  }
  if (*(char *)(iVar1 + 0x14) == '\0') {
LAB_0040315f:
    if (pfVar4 != (facet *)0x0) goto LAB_004031b2;
  }
  else {
    p_Var3 = std::locale::_Getgloballocale();
    if (uVar2 < *(uint *)(p_Var3 + 0xc)) {
      pfVar4 = *(facet **)(*(int *)(p_Var3 + 8) + uVar2 * 4);
      goto LAB_0040315f;
    }
  }
  pfVar4 = local_14;
  if (local_14 == (facet *)0x0) {
    uVar2 = std::codecvt<char,char,int>::_Getcat(&local_14,param_1);
    pfVar4 = local_14;
    if (uVar2 == 0xffffffff) {
      std::bad_cast::bad_cast(local_24,"bad cast");
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_0074aee8);
    }
    DAT_0076af60 = (int *)local_14;
    (**(code **)(*(int *)local_14 + 4))();
    Facet_Register(pfVar4);
  }
LAB_004031b2:
  std::_Lockit::~_Lockit(local_18);
  ExceptionList = local_10;
  return pfVar4;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_3 @ 004031d0 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_3
               (undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  int iVar1;
  basic_istream<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f60fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 != 0) {
    *(undefined ***)in_ECX = &PTR_006fcad0;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 0x10);
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            (in_ECX,this,false);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x70;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  local_8._0_1_ = 2;
  *(undefined ***)this = vftable;
  in_ECX[0x5c] = (basic_istream<char,std::char_traits<char>_>)0x0;
  in_ECX[0x55] = (basic_istream<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(int *)(in_ECX + 0x58) = DAT_0076af5c;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = std_filebuf_open(param_1,param_2 | 1,param_3);
  if (iVar1 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(in_ECX + *(int *)(*(int *)in_ECX + 4)),2,
               false);
  }
  ExceptionList = local_10;
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_4 @ 004033d0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_4
               (uint param_1,int param_2)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  uint uVar1;
  basic_iostream<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e12f2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined ***)in_ECX = &PTR_006fcd00;
    *(undefined **)(in_ECX + 0x10) = &DAT_006fcd08;
    *(code **)(in_ECX + 0x68) = _vftable__exref;
    *(code **)(in_ECX + 0x68) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 0x18);
  std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
            (in_ECX,this);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x68;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  uVar1 = 0;
  if ((param_1 & 1) == 0) {
    uVar1 = 4;
  }
  *(undefined ***)this = vftable;
  if ((param_1 & 2) == 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  *(uint *)(in_ECX + 0x54) = uVar1;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  ExceptionList = local_10;
  return;
}




/* Global::eh_catchall_0040354c @ 0040354c */

void Catch_All_0040354c(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_0 @ 00403df0 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_0(void)

{
  undefined4 uVar1;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  
  *(undefined ***)in_ECX = vftable;
  if ((*(int *)(in_ECX + 0x50) != 0) &&
     ((basic_streambuf<char,std::char_traits<char>_> *)**(int **)(in_ECX + 0xc) == in_ECX + 0x44)) {
    uVar1 = *(undefined4 *)(in_ECX + 0x3c);
    **(int **)(in_ECX + 0xc) = *(int *)(in_ECX + 0x38);
    **(undefined4 **)(in_ECX + 0x1c) = uVar1;
    **(undefined4 **)(in_ECX + 0x2c) = 0;
  }
  if (in_ECX[0x4c] != (basic_streambuf<char,std::char_traits<char>_>)0x0) {
    filebuf_close();
  }
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (in_ECX);
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_1 @ 00403e40 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_1(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined ***)(*(int *)(*(int *)(in_ECX + -0x70) + 4) + -0x70 + in_ECX) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  iVar1 = *(int *)(*(int *)(in_ECX + -0x70) + 4);
  *(int *)(iVar1 + -0x74 + in_ECX) = iVar1 + -0x70;
  *(undefined ***)(in_ECX + -0x60) = vftable;
  if ((*(int *)(in_ECX + -0x10) != 0) && (**(int **)(in_ECX + -0x54) == in_ECX + -0x1c)) {
    uVar2 = *(undefined4 *)(in_ECX + -0x24);
    **(int **)(in_ECX + -0x54) = *(int *)(in_ECX + -0x28);
    **(undefined4 **)(in_ECX + -0x44) = uVar2;
    **(undefined4 **)(in_ECX + -0x34) = 0;
  }
  if (*(char *)(in_ECX + -0x14) != '\0') {
    filebuf_close();
  }
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + -0x60));
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)(in_ECX + -0x58));
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_18 @ 00404420 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_18(void)

{
  ios_base *piVar1;
  int *in_ECX;
  
  piVar1 = (ios_base *)(in_ECX + 0x1a);
  *(undefined ***)(piVar1 + *(int *)(*in_ECX + 4) + -0x68) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(int *)(piVar1 + *(int *)(*in_ECX + 4) + -0x6c) = *(int *)(*in_ECX + 4) + -0x68;
  in_ECX[6] = (int)vftable;
  strstreambuf_tidy();
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 6));
  std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
            ((basic_iostream<char,std::char_traits<char>_> *)(in_ECX + 8));
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}




/* std::basic_ifstream<char,std::char_traits<char>_>::vfunc_0 @ 0040447b */

void std::basic_ifstream<char,std::char_traits<char>_>::vfunc_0(void)

{
  std_filebuf_deleting_dtor();
  return;
}




/* std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vfunc_0 @ 00404483 */

void std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vfunc_0(void)

{
  basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_19();
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_0 @ 00404490 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_0(byte param_1)

{
  undefined4 uVar1;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  
  *(undefined ***)in_ECX = vftable;
  if ((*(int *)(in_ECX + 0x50) != 0) &&
     ((basic_streambuf<char,std::char_traits<char>_> *)**(int **)(in_ECX + 0xc) == in_ECX + 0x44)) {
    uVar1 = *(undefined4 *)(in_ECX + 0x3c);
    **(int **)(in_ECX + 0xc) = *(int *)(in_ECX + 0x38);
    **(undefined4 **)(in_ECX + 0x1c) = uVar1;
    **(undefined4 **)(in_ECX + 0x2c) = 0;
  }
  if (in_ECX[0x4c] != (basic_streambuf<char,std::char_traits<char>_>)0x0) {
    filebuf_close();
  }
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* [AUDIT] proposed: std_filebuf_deleting_dtor  (confidence: med)
 * purpose: MSVC STL: basic_filebuf<char> scalar deleting destructor
 * vars: in_ECX=filebuf, param_1=flags
 */
/* Global::std_filebuf_deleting_dtor @ 004044f0 */

ios_base * std_filebuf_deleting_dtor(byte param_1)

{
  ios_base *in_ECX;
  
  std::basic_filebuf<char,std::char_traits<char>_>::ctor_1();
  *(code **)in_ECX = _vftable__exref;
  *(code **)in_ECX = _vftable__exref;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX + -0x70);
  }
  return in_ECX + -0x70;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_0 @ 00404540 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_0(byte param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  
  *(undefined ***)in_ECX = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_19 @ 00404570 */

ios_base *
std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_19(byte param_1)

{
  ios_base *piVar1;
  ios_base *in_ECX;
  
  piVar1 = in_ECX + -0x68;
  *(undefined ***)(in_ECX + *(int *)(*(int *)piVar1 + 4) + -0x68) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)(in_ECX + -0x68) + 4) + -0x6c) =
       *(int *)(*(int *)(in_ECX + -0x68) + 4) + -0x68;
  *(undefined ***)(in_ECX + -0x50) = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + -0x50));
  std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
            ((basic_iostream<char,std::char_traits<char>_> *)(in_ECX + -0x48));
  *(code **)in_ECX = _vftable__exref;
  *(code **)in_ECX = _vftable__exref;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}




/* std::error_category::vfunc_0 @ 00404620 */

void std::error_category::vfunc_0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vfunc_1 @ 0040503c */

void std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vfunc_1(void)

{
  int in_ECX;
  
  std::basic_istream<char,std::char_traits<char>_>::_Add_vtordisp1
            ((basic_istream<char,std::char_traits<char>_> *)
             ((in_ECX - *(int *)(in_ECX + -4)) + -0x50));
  return;
}




/* std::basic_ifstream<char,std::char_traits<char>_>::vfunc_1 @ 00405048 */

void std::basic_ifstream<char,std::char_traits<char>_>::vfunc_1(void)

{
  int in_ECX;
  
  std::basic_istream<char,std::char_traits<char>_>::_Add_vtordisp1
            ((basic_istream<char,std::char_traits<char>_> *)
             ((in_ECX - *(int *)(in_ECX + -4)) + -0x58));
  return;
}




/* std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vfunc_2 @ 00405054 */

void std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vfunc_2(void)

{
  int in_ECX;
  
  std::basic_ostream<char,std::char_traits<char>_>::_Add_vtordisp2
            ((basic_ostream<char,std::char_traits<char>_> *)
             ((in_ECX - *(int *)(in_ECX + -4)) + -0x50));
  return;
}




/* Global::eh_catchall_00405586 @ 00405586 */

undefined * Catch_All_00405586(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8);
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = std_allocate(*(int *)(unaff_EBP + 8) + 1);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &DAT_004055a6;
}




/* Global::eh_catchall_004055c3 @ 004055c3 */

void Catch_All_004055c3(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  if (0xf < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 0xf;
  puVar1[4] = 0;
  *(undefined1 *)puVar1 = 0;
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: std_string_deleting_dtor  (confidence: med)
 * purpose: Destroys std::string (frees heap buf if cap>0xf, resets SSO fields) then operator_delete(this)
 * vars: param_1=std::string; +0x24=cap, +0x10=buf
 */
/* Global::std_string_deleting_dtor @ 00405810 */

void std_string_deleting_dtor(void *param_1)

{
  if (0xf < *(uint *)((int)param_1 + 0x24)) {
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  *(undefined4 *)((int)param_1 + 0x24) = 0xf;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined1 *)((int)param_1 + 0x10) = 0;
  operator_delete(param_1);
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_1 @ 004090a0 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_1(void)

{
  int in_ECX;
  
  if (*(FILE **)(in_ECX + 0x50) != (FILE *)0x0) {
    _lock_file(*(FILE **)(in_ECX + 0x50));
  }
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::_Reset_back @ 0040a990 */

/* Library Function - Single Match
    private: void __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::_Reset_back(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::_Reset_back
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  undefined4 uVar1;
  
  if ((basic_filebuf<char,std::char_traits<char>_> *)**(int **)(this + 0xc) == this + 0x44) {
    uVar1 = *(undefined4 *)(this + 0x3c);
    **(int **)(this + 0xc) = *(int *)(this + 0x38);
    **(undefined4 **)(this + 0x1c) = uVar1;
    **(undefined4 **)(this + 0x2c) = 0;
  }
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::_Set_back @ 0040b4a0 */

/* Library Function - Single Match
    private: void __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::_Set_back(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::_Set_back
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  basic_filebuf<char,std::char_traits<char>_> *pbVar1;
  basic_filebuf<char,std::char_traits<char>_> *pbVar2;
  
  pbVar1 = this + 0x44;
  pbVar2 = (basic_filebuf<char,std::char_traits<char>_> *)**(int **)(this + 0xc);
  if (pbVar2 != pbVar1) {
    *(basic_filebuf<char,std::char_traits<char>_> **)(this + 0x38) = pbVar2;
    *(int *)(this + 0x3c) = **(int **)(this + 0x2c) + **(int **)(this + 0x1c);
  }
  **(int **)(this + 0xc) = (int)pbVar1;
  **(int **)(this + 0x1c) = (int)pbVar1;
  **(undefined4 **)(this + 0x2c) = this + (0x45 - (int)pbVar1);
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_2 @ 0040b540 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_2(void)

{
  int in_ECX;
  
  if (*(FILE **)(in_ECX + 0x50) != (FILE *)0x0) {
    _unlock_file(*(FILE **)(in_ECX + 0x50));
  }
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_0 @ 0040b810 */


void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_0
               (undefined4 param_1,float param_2)

{
  uint uVar1;
  void **ppvVar2;
  int iStack_e4;
  undefined **local_e0 [4];
  undefined *local_d0 [2];
  undefined **local_c8 [2];
  basic_iostream<char,std::char_traits<char>_> local_c0 [48];
  undefined4 local_90;
  undefined4 local_8c;
  code *local_78 [18];
  undefined4 local_30;
  void *local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e186d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_e0[0] = &PTR_006fcd00;
  local_d0[0] = &DAT_006fcd08;
  local_78[0] = _vftable__exref;
  local_8 = 0;
  local_30 = 1;
  local_14 = uVar1;
  std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
            ((basic_iostream<char,std::char_traits<char>_> *)local_e0,
             (basic_streambuf<char,std::char_traits<char>_> *)local_c8);
  local_8 = 1;
  *(undefined ***)((int)local_e0 + (int)local_e0[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_e4 + (int)local_e0[0][1]) = local_e0[0][1] + -0x68;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_c8);
  local_c8[0] = vftable;
  local_90 = 0;
  local_8c = 0;
  local_8 = 3;
  std_ostream_insert_string(local_d0,param_1,uVar1);
  std::basic_ostream<char,std::char_traits<char>_>::operator<<
            ((basic_ostream<char,std::char_traits<char>_> *)local_d0,param_2);
  ppvVar2 = (void **)ostrstream_str_wrap(local_2c);
  if (ppvVar2 != &DAT_00765030) {
    if (0xf < DAT_00765044) {
      operator_delete(DAT_00765030);
    }
    DAT_00765044 = 0xf;
    _DAT_00765040 = 0;
    DAT_00765030 = (void *)((uint)DAT_00765030 & 0xffffff00);
    string_move(ppvVar2);
  }
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  *(undefined ***)((int)local_e0 + (int)local_e0[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_e4 + (int)local_e0[0][1]) = local_e0[0][1] + -0x68;
  local_c8[0] = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_c8);
  std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
            (local_c0);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)local_78);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: std_allocate  (confidence: high)
 * purpose: MSVC std::_Allocate: operator_new(n), throws std::_Xbad_alloc on failure
 * vars: param_1=byte count
 */
/* Global::std_allocate @ 0040bfc0 */

void * std_allocate(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  if ((param_1 != 0) && (pvVar1 = operator_new(param_1), pvVar1 == (void *)0x0)) {
    std::_Xbad_alloc();
  }
  return pvVar1;
}




/* std::_System_error_category::vfunc_3 @ 0040c6d0 */

void std::_System_error_category::vfunc_3(int *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = std::_Syserror_map(param_2);
  *param_1 = param_2;
  if (pcVar1 != (char *)0x0) {
    param_1[1] = (int)&PTR_vftable_00765064;
    return;
  }
  param_1[1] = (int)&PTR_vftable_0076506c;
  return;
}




/* std::error_category::vfunc_3 @ 0040c710 */

void std::error_category::vfunc_3(undefined4 *param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  
  *param_1 = param_2;
  param_1[1] = in_ECX;
  return;
}




/* std::error_category::vfunc_4 @ 0040c730 */

uint std::error_category::vfunc_4(int *param_1,int param_2)

{
  int in_ECX;
  
  if ((in_ECX == param_1[1]) && (param_1 = (int *)*param_1, param_1 == (int *)param_2)) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  return (uint)param_1 & 0xffffff00;
}




/* std::error_category::vfunc_5 @ 0040c750 */

uint std::error_category::vfunc_5(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *in_ECX;
  undefined1 local_c [8];
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))(local_c,param_1);
  if ((piVar1[1] == param_2[1]) && (piVar1 = (int *)*piVar1, piVar1 == (int *)*param_2)) {
    return CONCAT31((int3)((uint)piVar1 >> 8),1);
  }
  return (uint)piVar1 & 0xffffff00;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_14 @ 0040cc00 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_14(undefined4 param_1)

{
  bool bVar1;
  codecvt_base *this;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  
  this = (codecvt_base *)std_locale_getfacet(param_1);
  bVar1 = std::codecvt_base::always_noconv(this);
  if (bVar1) {
    *(undefined4 *)(in_ECX + 0x40) = 0;
    return;
  }
  *(codecvt_base **)(in_ECX + 0x40) = this;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(in_ECX);
  return;
}




/* std::_Generic_error_category::vfunc_2 @ 0040d0c0 */

undefined1 * std::_Generic_error_category::vfunc_2(undefined1 *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = std::_Syserror_map(param_2);
  pcVar3 = "unknown error";
  if (pcVar2 != (char *)0x0) {
    pcVar3 = pcVar2;
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if (*pcVar3 == '\0') {
    string_assignPtrLen(pcVar3,0);
    return param_1;
  }
  pcVar2 = pcVar3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  string_assignPtrLen(pcVar3,(int)pcVar2 - (int)(pcVar3 + 1));
  return param_1;
}




/* std::_Iostream_error_category::vfunc_2 @ 0040d140 */

undefined1 * std::_Iostream_error_category::vfunc_2(undefined1 *param_1,int param_2)

{
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    string_assignPtrLen("iostream stream error",0x15);
    return param_1;
  }
  _Generic_error_category::vfunc_2(param_1,param_2);
  return param_1;
}




/* std::_System_error_category::vfunc_2 @ 0040d190 */

undefined1 * std::_System_error_category::vfunc_2(undefined1 *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = std::_Winerror_map(param_2);
  pcVar3 = "unknown error";
  if (pcVar2 != (char *)0x0) {
    pcVar3 = pcVar2;
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if (*pcVar3 == '\0') {
    string_assignPtrLen(pcVar3,0);
    return param_1;
  }
  pcVar2 = pcVar3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  string_assignPtrLen(pcVar3,(int)pcVar2 - (int)(pcVar3 + 1));
  return param_1;
}




/* std::_Generic_error_category::vfunc_1 @ 0040d210 */

char * std::_Generic_error_category::vfunc_1(void)

{
  return "generic";
}




/* std::_Iostream_error_category::vfunc_1 @ 0040d220 */

char * std::_Iostream_error_category::vfunc_1(void)

{
  return "iostream";
}




/* std::_System_error_category::vfunc_1 @ 0040d230 */

char * std::_System_error_category::vfunc_1(void)

{
  return "system";
}




/* [AUDIT] proposed: std_filebuf_open  (confidence: high)
 * purpose: std::basic_filebuf<char>::open: _Fiopen, wires streambuf get/put ptrs, sets codecvt facet
 * vars: param_1=fname; param_2=mode; in_ECX=filebuf
 */
/* Global::std_filebuf_open @ 0040d240 */

basic_streambuf<char,std::char_traits<char>_> * std_filebuf_open(char *param_1,int param_2,int *param_3)

{
  bool bVar1;
  uint uVar2;
  _iobuf *p_Var3;
  undefined4 uVar4;
  codecvt_base *this;
  undefined4 *puVar5;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1968;
  local_10 = ExceptionList;
  uVar2 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x50) == 0) {
    p_Var3 = std::_Fiopen(param_1,param_2,(int)param_3);
    if (p_Var3 != (_iobuf *)0x0) {
      in_ECX[0x4c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
      in_ECX[0x45] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(in_ECX);
      *(char ***)(in_ECX + 0xc) = &p_Var3->_base;
      *(char ***)(in_ECX + 0x10) = &p_Var3->_base;
      *(int **)(in_ECX + 0x2c) = &p_Var3->_cnt;
      *(int **)(in_ECX + 0x30) = &p_Var3->_cnt;
      *(_iobuf **)(in_ECX + 0x1c) = p_Var3;
      *(_iobuf **)(in_ECX + 0x20) = p_Var3;
      *(_iobuf **)(in_ECX + 0x50) = p_Var3;
      *(undefined4 *)(in_ECX + 0x48) = DAT_0076af5c;
      *(undefined4 *)(in_ECX + 0x40) = 0;
      uVar4 = std::basic_streambuf<char,std::char_traits<char>_>::getloc(in_ECX);
      local_8 = 0;
      this = (codecvt_base *)std_locale_getfacet(uVar4,uVar2);
      bVar1 = std::codecvt_base::always_noconv(this);
      if (bVar1) {
        *(undefined4 *)(in_ECX + 0x40) = 0;
      }
      else {
        *(codecvt_base **)(in_ECX + 0x40) = this;
        std::basic_streambuf<char,std::char_traits<char>_>::_Init(in_ECX);
      }
      local_8 = 0xffffffff;
      if (param_3 != (int *)0x0) {
        puVar5 = (undefined4 *)(**(code **)(*param_3 + 8))();
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)(1);
        }
      }
      ExceptionList = local_10;
      return in_ECX;
    }
  }
  ExceptionList = local_10;
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_3 @ 0040d350 */


void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_3(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  size_t sVar5;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  char *pcVar6;
  char cVar7;
  size_t _Count;
  char *local_38;
  char *local_34;
  undefined4 local_30;
  undefined8 local_2c;
  undefined1 local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f8b28;
  local_10 = ExceptionList;
  uVar2 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (param_1 != -1) {
    uVar1 = **(uint **)(in_ECX + 0x20);
    cVar7 = (char)param_1;
    if (uVar1 != 0) {
      iVar3 = **(int **)(in_ECX + 0x30);
      if (uVar1 < iVar3 + uVar1) {
        **(int **)(in_ECX + 0x30) = iVar3 + -1;
        pcVar6 = (char *)**(int **)(in_ECX + 0x20);
        **(int **)(in_ECX + 0x20) = (int)(pcVar6 + 1);
        *pcVar6 = cVar7;
        goto LAB_0040d515;
      }
    }
    if (*(int *)(in_ECX + 0x50) != 0) {
      if ((basic_streambuf<char,std::char_traits<char>_> *)**(int **)(in_ECX + 0xc) == in_ECX + 0x44
         ) {
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  (in_ECX,*(char **)(in_ECX + 0x38),*(char **)(in_ECX + 0x3c),
                   *(char **)(in_ECX + 0x3c));
      }
      if (*(int *)(in_ECX + 0x40) == 0) {
        fputc((int)cVar7,*(FILE **)(in_ECX + 0x50));
      }
      else {
        local_2c = 0;
        local_30 = CONCAT31(local_30._1_3_,cVar7);
        local_18 = 0xf;
        local_1c = 8;
        local_24 = 0;
        local_8 = 0;
        while( true ) {
          pcVar6 = (char *)&local_2c;
          if (0xf < local_18) {
            pcVar6 = (char *)local_2c;
          }
          iVar3 = std::codecvt<char,char,int>::out
                            (*(codecvt<char,char,int> **)(in_ECX + 0x40),(int *)(in_ECX + 0x48),
                             (char *)&local_30,(char *)((int)&local_30 + 1),&local_38,pcVar6,
                             pcVar6 + local_1c,&local_34);
          if (iVar3 < 0) goto LAB_0040d502;
          if (1 < iVar3) break;
          puVar4 = &local_2c;
          if (0xf < local_18) {
            puVar4 = (undefined8 *)(char *)local_2c;
          }
          _Count = (int)local_34 - (int)puVar4;
          if (_Count != 0) {
            puVar4 = &local_2c;
            if (0xf < local_18) {
              puVar4 = (undefined8 *)(char *)local_2c;
            }
            sVar5 = fwrite(puVar4,1,_Count,*(FILE **)(in_ECX + 0x50));
            if (_Count != sVar5) goto LAB_0040d502;
          }
          in_ECX[0x45] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
          if (local_38 != (char *)&local_30) goto LAB_0040d502;
          if (_Count == 0) {
            if (0x1f < local_1c) goto LAB_0040d502;
            string_appendFill(8,0);
          }
        }
        if (iVar3 == 3) {
          std_fputc_nofail(local_30,*(undefined4 *)(in_ECX + 0x50),uVar2);
        }
LAB_0040d502:
        if (0xf < local_18) {
          operator_delete((char *)local_2c);
        }
      }
    }
  }
LAB_0040d515:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_3 @ 0040d540 */

int std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_3(int param_1)

{
  basic_streambuf<char,std::char_traits<char>_> bVar1;
  int iVar2;
  void *_Src;
  char *pcVar3;
  void *_Dst;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((*(uint *)(in_ECX + 0x3c) & 2) != 0) {
    return -1;
  }
  if (param_1 == -1) {
    return 0;
  }
  if ((((*(uint *)(in_ECX + 0x3c) & 8) != 0) && (uVar6 = **(uint **)(in_ECX + 0x20), uVar6 != 0)) &&
     (uVar4 = *(uint *)(in_ECX + 0x38), uVar6 < uVar4)) {
    iVar2 = **(int **)(in_ECX + 0x30);
    **(uint **)(in_ECX + 0x20) = uVar4;
    **(int **)(in_ECX + 0x30) = (iVar2 + uVar6) - uVar4;
  }
  uVar6 = **(uint **)(in_ECX + 0x20);
  if (uVar6 != 0) {
    if (uVar6 < **(int **)(in_ECX + 0x30) + uVar6) {
      pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::_Pninc(in_ECX);
      *pcVar3 = (char)param_1;
      return param_1;
    }
    if (uVar6 != 0) {
      uVar6 = (**(int **)(in_ECX + 0x30) - **(int **)(in_ECX + 0xc)) + uVar6;
      goto LAB_0040d5d2;
    }
  }
  uVar6 = 0;
LAB_0040d5d2:
  uVar4 = uVar6 >> 1;
  if (uVar4 < 0x20) {
    uVar4 = 0x20;
  }
  else if (uVar4 == 0) {
    return -1;
  }
  do {
    if (uVar6 <= 0x7fffffff - uVar4) break;
    uVar4 = uVar4 >> 1;
  } while (uVar4 != 0);
  if (uVar4 == 0) {
    return -1;
  }
  iVar2 = uVar4 + uVar6;
  _Dst = (void *)std_allocate(iVar2);
  _Src = (void *)**(undefined4 **)(in_ECX + 0xc);
  if ((uVar6 == 0) || (memcpy(_Dst,_Src,uVar6), uVar6 == 0)) {
    *(void **)(in_ECX + 0x38) = _Dst;
    **(undefined4 **)(in_ECX + 0x10) = _Dst;
    **(undefined4 **)(in_ECX + 0x20) = _Dst;
    **(int **)(in_ECX + 0x30) = iVar2;
    bVar1 = in_ECX[0x3c];
    **(undefined4 **)(in_ECX + 0xc) = _Dst;
    if (((byte)bVar1 & 4) == 0) {
      **(undefined4 **)(in_ECX + 0x1c) = _Dst;
      **(undefined4 **)(in_ECX + 0x2c) = 1;
    }
    else {
      **(undefined4 **)(in_ECX + 0x1c) = 0;
      **(undefined4 **)(in_ECX + 0x2c) = _Dst;
    }
  }
  else {
    *(int *)(in_ECX + 0x38) = (int)_Dst + (*(int *)(in_ECX + 0x38) - (int)_Src);
    iVar5 = **(int **)(in_ECX + 0x20);
    **(int **)(in_ECX + 0x10) = (int)_Dst + (**(int **)(in_ECX + 0x10) - (int)_Src);
    iVar5 = (iVar5 - (int)_Src) + (int)_Dst;
    **(int **)(in_ECX + 0x20) = iVar5;
    **(int **)(in_ECX + 0x30) = (int)_Dst + (iVar2 - iVar5);
    if (((byte)in_ECX[0x3c] & 4) == 0) {
      iVar2 = **(int **)(in_ECX + 0x20);
      iVar5 = **(int **)(in_ECX + 0x1c);
      **(undefined4 **)(in_ECX + 0xc) = _Dst;
      iVar5 = (iVar5 - (int)_Src) + (int)_Dst;
      **(int **)(in_ECX + 0x1c) = iVar5;
      **(int **)(in_ECX + 0x2c) = (iVar2 - iVar5) + 1;
    }
    else {
      **(undefined4 **)(in_ECX + 0xc) = _Dst;
      **(undefined4 **)(in_ECX + 0x1c) = 0;
      **(undefined4 **)(in_ECX + 0x2c) = _Dst;
    }
  }
  if (((byte)in_ECX[0x3c] & 1) == 0) {
    *(uint *)(in_ECX + 0x3c) = *(uint *)(in_ECX + 0x3c) | 1;
    pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::_Pninc(in_ECX);
    *pcVar3 = (char)param_1;
    return param_1;
  }
  operator_delete(_Src);
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_4 @ 0040d710 */

uint std::basic_filebuf<char,std::char_traits<char>_>::vfunc_4(uint param_1)

{
  uint uVar1;
  int iVar2;
  basic_filebuf<char,std::char_traits<char>_> *in_ECX;
  
  uVar1 = **(uint **)(in_ECX + 0x1c);
  if (((uVar1 != 0) && (**(uint **)(in_ECX + 0xc) < uVar1)) &&
     ((param_1 == 0xffffffff || (*(byte *)(uVar1 - 1) == param_1)))) {
    **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) + 1;
    **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + -1;
    uVar1 = 0;
    if (param_1 != 0xffffffff) {
      uVar1 = param_1;
    }
    return uVar1;
  }
  if ((*(FILE **)(in_ECX + 0x50) != (FILE *)0x0) && (param_1 != 0xffffffff)) {
    if ((*(int *)(in_ECX + 0x40) == 0) &&
       (iVar2 = ungetc(param_1 & 0xff,*(FILE **)(in_ECX + 0x50)), iVar2 != -1)) {
      return param_1;
    }
    if ((basic_filebuf<char,std::char_traits<char>_> *)**(int **)(in_ECX + 0x1c) != in_ECX + 0x44) {
      in_ECX[0x44] = SUB41(param_1,0);
      _Set_back(in_ECX);
      return param_1;
    }
  }
  return 0xffffffff;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_4 @ 0040d7a0 */

int std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_4(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = **(uint **)(in_ECX + 0x1c);
  if ((uVar1 != 0) && (**(uint **)(in_ECX + 0xc) < uVar1)) {
    if ((param_1 == -1) ||
       (((char)param_1 == *(char *)(uVar1 - 1) || ((*(byte *)(in_ECX + 0x3c) & 2) == 0)))) {
      **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) + 1;
      **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + -1;
      if (param_1 != -1) {
        *(char *)**(undefined4 **)(in_ECX + 0x1c) = (char)param_1;
        return param_1;
      }
      return 0;
    }
  }
  return -1;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_10 @ 0040dad0 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_10
               (undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  int unaff_EDI;
  int iVar5;
  
  iVar4 = param_3;
  iVar5 = param_2;
  if (((**(int **)(in_ECX + 0x1c) == in_ECX + 0x44) && (param_4 == 1)) &&
     (*(int *)(in_ECX + 0x40) == 0)) {
    iVar4 = param_3 + -1 + (uint)(param_2 != 0);
    iVar5 = param_2 + -1;
  }
  if ((((*(int *)(in_ECX + 0x50) != 0) && (cVar3 = filebuf_endWrite(), cVar3 != '\0')) &&
      (((iVar5 == 0 && iVar4 == 0 && (param_4 == 1)) ||
       (iVar4 = _fseeki64(*(FILE **)(in_ECX + 0x50),CONCAT44(param_4,iVar4),unaff_EDI), iVar4 == 0))
      )) && (iVar4 = fgetpos(*(FILE **)(in_ECX + 0x50),(fpos_t *)&param_2), iVar4 == 0)) {
    if (**(int **)(in_ECX + 0xc) == in_ECX + 0x44) {
      uVar1 = *(undefined4 *)(in_ECX + 0x3c);
      **(int **)(in_ECX + 0xc) = *(int *)(in_ECX + 0x38);
      **(undefined4 **)(in_ECX + 0x1c) = uVar1;
      **(undefined4 **)(in_ECX + 0x2c) = 0;
    }
    param_1[2] = param_2;
    param_1[3] = param_3;
    uVar1 = *(undefined4 *)(in_ECX + 0x48);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[4] = uVar1;
    return;
  }
  pcVar2 = _BADOFF_exref;
  *param_1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(pcVar2 + 4);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_10 @ 0040dbd0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_10
               (uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  uVar3 = **(uint **)(in_ECX + 0x20);
  if ((uVar3 != 0) && (*(uint *)(in_ECX + 0x38) < uVar3)) {
    *(uint *)(in_ECX + 0x38) = uVar3;
  }
  if (((param_5 & 1) == 0) || (iVar5 = **(int **)(in_ECX + 0x1c), iVar5 == 0)) {
    if (((param_5 & 2) == 0) || (uVar3 = **(uint **)(in_ECX + 0x20), uVar3 == 0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_0040dd6b;
    }
    else {
      if (param_4 == 2) {
        uVar4 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + ((int)uVar4 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 == 1) {
        uVar4 = uVar3 - **(int **)(in_ECX + 0xc);
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + ((int)uVar4 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        uVar4 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= uVar4)))) {
          iVar5 = (**(int **)(in_ECX + 0xc) - uVar3) + param_2;
          **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) - iVar5;
          **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + iVar5;
          goto LAB_0040dd6b;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      uVar3 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
      bVar7 = CARRY4(param_2,uVar3);
      param_2 = param_2 + uVar3;
      param_3 = param_3 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        uVar3 = iVar5 - **(int **)(in_ECX + 0xc);
        bVar7 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
      }
      else {
LAB_0040dc45:
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else if (param_4 != 0) goto LAB_0040dc45;
    if (-1 < (int)param_3) {
      uVar3 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
      iVar6 = (int)uVar3 >> 0x1f;
      if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= uVar3)))) {
        iVar5 = (**(int **)(in_ECX + 0xc) - iVar5) + param_2;
        **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) - iVar5;
        **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + iVar5;
        if (((param_5 & 2) != 0) && (piVar1 = *(int **)(in_ECX + 0x20), *piVar1 != 0)) {
          iVar5 = **(int **)(in_ECX + 0x30);
          iVar6 = *piVar1;
          iVar2 = **(int **)(in_ECX + 0x1c);
          *piVar1 = iVar2;
          **(int **)(in_ECX + 0x30) = (iVar5 + iVar6) - iVar2;
        }
        goto LAB_0040dd6b;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_0040dd6b:
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_11 @ 0040dda0 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_11
               (undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  basic_filebuf<char,std::char_traits<char>_> *in_ECX;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_4;
  local_8 = param_5;
  if (*(int *)(in_ECX + 0x50) != 0) {
    cVar3 = filebuf_endWrite();
    if (cVar3 != '\0') {
      iVar4 = fsetpos(*(FILE **)(in_ECX + 0x50),(fpos_t *)&local_c);
      if (iVar4 == 0) {
        if (param_2 != 0 || param_3 != 0) {
          iVar4 = _fseeki64(*(FILE **)(in_ECX + 0x50),CONCAT44(1,param_3),unaff_EDI);
          if (iVar4 != 0) goto LAB_0040de4a;
        }
        iVar4 = fgetpos(*(FILE **)(in_ECX + 0x50),(fpos_t *)&local_c);
        if (iVar4 == 0) {
          *(undefined4 *)(in_ECX + 0x48) = param_6;
          _Reset_back(in_ECX);
          param_1[2] = local_c;
          param_1[3] = local_8;
          uVar1 = *(undefined4 *)(in_ECX + 0x48);
          *param_1 = 0;
          param_1[1] = 0;
          param_1[4] = uVar1;
          return;
        }
      }
    }
  }
LAB_0040de4a:
  pcVar2 = _BADOFF_exref;
  *param_1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(pcVar2 + 4);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_11 @ 0040de80 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_11
               (uint *param_1,uint param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
               undefined4 param_7,uint param_8)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = param_4 + param_2;
  uVar7 = param_5 + param_3 + (uint)CARRY4(param_4,param_2);
  uVar5 = **(uint **)(in_ECX + 0x20);
  if ((uVar5 != 0) && (*(uint *)(in_ECX + 0x38) < uVar5)) {
    *(uint *)(in_ECX + 0x38) = uVar5;
  }
  uVar5 = *(uint *)_BADOFF_exref;
  uVar1 = *(uint *)(_BADOFF_exref + 4);
  if ((uVar9 != uVar5) || (uVar8 = uVar7, uVar10 = uVar9, uVar7 != uVar1)) {
    uVar8 = uVar1;
    uVar10 = uVar5;
    if (((param_8 & 1) == 0) || (**(int **)(in_ECX + 0x1c) == 0)) {
      if ((((param_8 & 2) != 0) && (**(int **)(in_ECX + 0x20) != 0)) && (-1 < (int)uVar7)) {
        uVar5 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
        iVar6 = (int)uVar5 >> 0x1f;
        if (((int)uVar7 <= iVar6) && (((int)uVar7 < iVar6 || (uVar9 <= uVar5)))) {
          iVar6 = (**(int **)(in_ECX + 0xc) - **(int **)(in_ECX + 0x20)) + uVar9;
          **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) - iVar6;
          **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + iVar6;
          uVar8 = uVar7;
          uVar10 = uVar9;
        }
      }
    }
    else if (-1 < (int)uVar7) {
      uVar5 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
      iVar6 = (int)uVar5 >> 0x1f;
      if (((int)uVar7 <= iVar6) && (((int)uVar7 < iVar6 || (uVar9 <= uVar5)))) {
        iVar6 = (**(int **)(in_ECX + 0xc) - **(int **)(in_ECX + 0x1c)) + uVar9;
        **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) - iVar6;
        **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + iVar6;
        uVar8 = uVar7;
        uVar10 = uVar9;
        if (((param_8 & 2) != 0) && (piVar2 = *(int **)(in_ECX + 0x20), *piVar2 != 0)) {
          iVar6 = **(int **)(in_ECX + 0x30);
          iVar3 = *piVar2;
          iVar4 = **(int **)(in_ECX + 0x1c);
          *piVar2 = iVar4;
          **(int **)(in_ECX + 0x30) = (iVar6 + iVar3) - iVar4;
        }
      }
    }
  }
  *param_1 = uVar10;
  param_1[1] = uVar8;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_12 @ 0040dfa0 */

basic_streambuf<char,std::char_traits<char>_> *
std::basic_filebuf<char,std::char_traits<char>_>::vfunc_12(char *param_1,size_t param_2,int param_3)

{
  int iVar1;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  
  if (*(FILE **)(in_ECX + 0x50) != (FILE *)0x0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      iVar1 = 4;
    }
    else {
      iVar1 = 0;
    }
    iVar1 = setvbuf(*(FILE **)(in_ECX + 0x50),param_1,iVar1,param_2);
    if (iVar1 == 0) {
      iVar1 = *(int *)(in_ECX + 0x50);
      in_ECX[0x4c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
      in_ECX[0x45] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(in_ECX);
      if (iVar1 != 0) {
        *(int *)(in_ECX + 0xc) = iVar1 + 8;
        *(int *)(in_ECX + 0x10) = iVar1 + 8;
        *(int *)(in_ECX + 0x1c) = iVar1;
        *(int *)(in_ECX + 0x20) = iVar1;
        *(int *)(in_ECX + 0x2c) = iVar1 + 4;
        *(int *)(in_ECX + 0x30) = iVar1 + 4;
      }
      *(int *)(in_ECX + 0x50) = iVar1;
      *(undefined4 *)(in_ECX + 0x48) = DAT_0076af5c;
      *(undefined4 *)(in_ECX + 0x40) = 0;
      return in_ECX;
    }
  }
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_13 @ 0040e160 */

undefined4 std::basic_filebuf<char,std::char_traits<char>_>::vfunc_13(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x14] != 0) {
    iVar1 = (**(code **)(*in_ECX + 0xc))(0xffffffff);
    if (iVar1 != -1) {
      iVar1 = fflush((FILE *)in_ECX[0x14]);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_7 @ 0040e190 */

void std::basic_filebuf<char,std::char_traits<char>_>::vfunc_7(void)

{
  uint uVar1;
  int iVar2;
  char ******ppppppcVar3;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  char *pcVar4;
  char *local_38;
  char *local_34;
  char local_2d;
  char *****local_2c [4];
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f8b28;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = **(uint **)(in_ECX + 0x1c);
  if (uVar1 != 0) {
    iVar2 = **(int **)(in_ECX + 0x2c);
    if (uVar1 < iVar2 + uVar1) {
      **(int **)(in_ECX + 0x2c) = iVar2 + -1;
      **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + 1;
      goto LAB_0040e324;
    }
  }
  if (*(int *)(in_ECX + 0x50) != 0) {
    if ((basic_streambuf<char,std::char_traits<char>_> *)**(int **)(in_ECX + 0xc) == in_ECX + 0x44)
    {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (in_ECX,*(char **)(in_ECX + 0x38),*(char **)(in_ECX + 0x3c),
                 *(char **)(in_ECX + 0x3c));
    }
    if (*(int *)(in_ECX + 0x40) != 0) {
      local_18 = 0xf;
      local_1c = 0;
      local_2c[0] = (char *****)((uint)local_2c[0] & 0xffffff00);
      local_8 = 0;
      iVar2 = fgetc(*(FILE **)(in_ECX + 0x50));
      do {
        if (iVar2 == -1) goto LAB_0040e311;
        string_appendFill(1,iVar2);
        ppppppcVar3 = local_2c;
        if (0xf < local_18) {
          ppppppcVar3 = (char ******)local_2c[0];
        }
        iVar2 = std::codecvt<char,char,int>::in
                          (*(codecvt<char,char,int> **)(in_ECX + 0x40),(int *)(in_ECX + 0x48),
                           (char *)ppppppcVar3,(char *)((int)ppppppcVar3 + local_1c),&local_34,
                           &local_2d,(char *)local_2c,&local_38);
        if (iVar2 < 0) goto LAB_0040e311;
        if (iVar2 < 2) {
          if (local_38 != &local_2d) {
            ppppppcVar3 = local_2c;
            if (0xf < local_18) {
              ppppppcVar3 = (char ******)local_2c[0];
            }
            for (pcVar4 = (char *)((int)ppppppcVar3 + (local_1c - (int)local_34)); 0 < (int)pcVar4;
                pcVar4 = pcVar4 + -1) {
              ungetc((int)local_34[(int)(pcVar4 + -1)],*(FILE **)(in_ECX + 0x50));
            }
LAB_0040e311:
            if (0xf < local_18) {
              operator_delete(local_2c[0]);
            }
            goto LAB_0040e324;
          }
          ppppppcVar3 = local_2c;
          if (0xf < local_18) {
            ppppppcVar3 = (char ******)local_2c[0];
          }
          string_erase(0,(int)local_34 - (int)ppppppcVar3);
        }
        else {
          if (iVar2 != 3) goto LAB_0040e311;
          if (local_1c != 0) {
            ppppppcVar3 = local_2c;
            if (0xf < local_18) {
              ppppppcVar3 = (char ******)local_2c[0];
            }
            memcpy_s(&local_2d,1,ppppppcVar3,1);
            goto LAB_0040e311;
          }
        }
        iVar2 = fgetc(*(FILE **)(in_ECX + 0x50));
      } while( true );
    }
    fgetc(*(FILE **)(in_ECX + 0x50));
  }
LAB_0040e324:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::vfunc_6 @ 0040e380 */

uint std::basic_filebuf<char,std::char_traits<char>_>::vfunc_6(void)

{
  byte *pbVar1;
  uint uVar2;
  int *in_ECX;
  
  pbVar1 = *(byte **)in_ECX[7];
  if ((pbVar1 != (byte *)0x0) && (pbVar1 < pbVar1 + *(int *)in_ECX[0xb])) {
    return (uint)*pbVar1;
  }
  uVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (uVar2 == 0xffffffff) {
    return 0xffffffff;
  }
  (**(code **)(*in_ECX + 0x10))(uVar2);
  return uVar2;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_6 @ 0040e3c0 */

uint std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vfunc_6(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int in_ECX;
  
  pbVar1 = (byte *)**(int **)(in_ECX + 0x1c);
  if (pbVar1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (pbVar1 < pbVar1 + **(int **)(in_ECX + 0x2c)) {
    return (uint)*pbVar1;
  }
  if ((((*(byte *)(in_ECX + 0x3c) & 4) == 0) &&
      (pbVar2 = (byte *)**(undefined4 **)(in_ECX + 0x20), pbVar2 != (byte *)0x0)) &&
     ((pbVar1 < pbVar2 || (pbVar1 < *(byte **)(in_ECX + 0x38))))) {
    if (*(byte **)(in_ECX + 0x38) < pbVar2) {
      *(byte **)(in_ECX + 0x38) = pbVar2;
    }
    **(int **)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0x1c);
    return (uint)*(byte *)**(undefined4 **)(in_ECX + 0x1c);
  }
  return 0xffffffff;
}




/* Global::eh_catchall_0040e676 @ 0040e676 */

undefined * Catch_All_0040e676(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_0040e690;
}




/* Global::eh_catchall_0040e8b6 @ 0040e8b6 */

undefined * Catch_All_0040e8b6(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_0040e8d0;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_17 @ 0040ebe0 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_17
               (uint param_1,int param_2)

{
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this;
  uint uVar1;
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1a62;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined ***)in_ECX = &PTR_006fcd00;
    *(undefined **)(in_ECX + 0x10) = &DAT_006fcd08;
    *(code **)(in_ECX + 0x68) = _vftable__exref;
    *(code **)(in_ECX + 0x68) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)(in_ECX + 0x18);
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>(in_ECX,this);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>(this);
  uVar1 = 0;
  if ((param_1 & 1) == 0) {
    uVar1 = 4;
  }
  *(undefined ***)this = vftable;
  if ((param_1 & 2) == 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  *(uint *)(in_ECX + 0x54) = uVar1;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  ExceptionList = local_10;
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_18 @ 0040efb0 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_18(void)

{
  ios_base *piVar1;
  int *in_ECX;
  
  piVar1 = (ios_base *)(in_ECX + 0x1a);
  *(undefined ***)(piVar1 + *(int *)(*in_ECX + 4) + -0x68) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(int *)(piVar1 + *(int *)(*in_ECX + 4) + -0x6c) = *(int *)(*in_ECX + 4) + -0x68;
  in_ECX[6] = (int)vftable;
  strstreambuf_tidy();
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)(in_ECX + 6));
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)(in_ECX + 8));
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}




/* std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_0 @ 0040f00b */

void std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_0
               (void)

{
  basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_14();
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_0 @ 0040f020 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_0
               (byte param_1)

{
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *in_ECX;
  
  *(undefined ***)in_ECX = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_14 @ 0040f050 */

ios_base *
std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_14
          (byte param_1)

{
  ios_base *piVar1;
  ios_base *in_ECX;
  
  piVar1 = in_ECX + -0x68;
  *(undefined ***)(in_ECX + *(int *)(*(int *)piVar1 + 4) + -0x68) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)(in_ECX + -0x68) + 4) + -0x6c) =
       *(int *)(*(int *)(in_ECX + -0x68) + 4) + -0x68;
  *(undefined ***)(in_ECX + -0x50) = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)(in_ECX + -0x50));
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)(in_ECX + -0x48));
  *(code **)in_ECX = _vftable__exref;
  *(code **)in_ECX = _vftable__exref;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}




/* std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_1 @ 0040f0f3 */

void std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_1
               (void)

{
  int in_ECX;
  
  std::basic_istream<wchar_t,std::char_traits<wchar_t>_>::_Add_vtordisp1
            ((basic_istream<wchar_t,std::char_traits<wchar_t>_> *)
             ((in_ECX - *(int *)(in_ECX + -4)) + -0x50));
  return;
}




/* std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_2 @ 0040f0ff */

void std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_2
               (void)

{
  int in_ECX;
  
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::_Add_vtordisp2
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)
             ((in_ECX - *(int *)(in_ECX + -4)) + -0x50));
  return;
}




/* Global::eh_catchall_0040f20f @ 0040f20f */

undefined * Catch_All_0040f20f(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8);
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = std_wstring_Allocate(*(int *)(unaff_EBP + 8) + 1);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &DAT_0040f22f;
}




/* Global::eh_catchall_0040f24c @ 0040f24c */

void Catch_All_0040f24c(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  if (7 < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: std::wstring::_Allocate  (confidence: high)
 * purpose: allocate wchar_t buffer (n*2), _Xbad_alloc on fail
 * vars: param_1=count
 */
/* Global::std_wstring_Allocate @ 0040f650 */

void * std_wstring_Allocate(uint param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    return (void *)0x0;
  }
  if ((param_1 < 0x80000000) && (pvVar1 = operator_new(param_1 * 2), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  std::_Xbad_alloc();
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_3 @ 004114c0 */

wchar_t std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_3
                  (wchar_t param_1)

{
  void *pvVar1;
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> bVar2;
  int iVar3;
  void *_Src;
  wchar_t *pwVar4;
  void *_Dst;
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *in_ECX;
  uint uVar5;
  uint uVar6;
  
  if ((*(uint *)(in_ECX + 0x3c) & 2) != 0) {
    return L'\xffff';
  }
  if (param_1 == L'\xffff') {
    return L'\0';
  }
  if ((*(uint *)(in_ECX + 0x3c) & 8) != 0) {
    uVar6 = **(uint **)(in_ECX + 0x20);
    if ((uVar6 != 0) && (uVar5 = *(uint *)(in_ECX + 0x38), uVar6 < uVar5)) {
      iVar3 = **(int **)(in_ECX + 0x30);
      **(uint **)(in_ECX + 0x20) = uVar5;
      **(int **)(in_ECX + 0x30) = (int)((uVar6 + iVar3 * 2) - uVar5) >> 1;
    }
  }
  uVar6 = **(uint **)(in_ECX + 0x20);
  if (uVar6 != 0) {
    if (uVar6 < uVar6 + **(int **)(in_ECX + 0x30) * 2) {
      pwVar4 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::_Pninc(in_ECX);
      *pwVar4 = param_1;
      return param_1;
    }
    if (uVar6 != 0) {
      uVar6 = (int)((**(int **)(in_ECX + 0x30) * 2 - **(int **)(in_ECX + 0xc)) + uVar6) >> 1;
      goto LAB_00411561;
    }
  }
  uVar6 = 0;
LAB_00411561:
  uVar5 = uVar6 >> 1;
  if (uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  else if (uVar5 == 0) {
    return L'\xffff';
  }
  do {
    if (uVar6 <= 0x7fffffff - uVar5) break;
    uVar5 = uVar5 >> 1;
  } while (uVar5 != 0);
  if (uVar5 == 0) {
    return L'\xffff';
  }
  iVar3 = uVar5 + uVar6;
  _Dst = (void *)std_wstring_Allocate(iVar3);
  _Src = (void *)**(undefined4 **)(in_ECX + 0xc);
  if ((uVar6 == 0) || (memcpy(_Dst,_Src,uVar6 * 2), uVar6 == 0)) {
    *(void **)(in_ECX + 0x38) = _Dst;
    **(undefined4 **)(in_ECX + 0x10) = _Dst;
    **(undefined4 **)(in_ECX + 0x20) = _Dst;
    **(int **)(in_ECX + 0x30) = iVar3 * 2 >> 1;
    bVar2 = in_ECX[0x3c];
    **(undefined4 **)(in_ECX + 0xc) = _Dst;
    if (((byte)bVar2 & 4) == 0) {
      **(undefined4 **)(in_ECX + 0x1c) = _Dst;
      **(undefined4 **)(in_ECX + 0x2c) = 1;
    }
    else {
      **(undefined4 **)(in_ECX + 0x1c) = 0;
      **(int **)(in_ECX + 0x2c) = (int)_Dst >> 1;
    }
  }
  else {
    *(void **)(in_ECX + 0x38) = (void *)((int)_Dst + (*(int *)(in_ECX + 0x38) - (int)_Src >> 1) * 2)
    ;
    pvVar1 = (void *)((int)_Dst + (**(int **)(in_ECX + 0x20) - (int)_Src >> 1) * 2);
    **(int **)(in_ECX + 0x10) = (int)((int)_Dst + (**(int **)(in_ECX + 0x10) - (int)_Src >> 1) * 2);
    **(int **)(in_ECX + 0x20) = (int)pvVar1;
    **(int **)(in_ECX + 0x30) = (iVar3 * 2 - (int)pvVar1) + (int)_Dst >> 1;
    if (((byte)in_ECX[0x3c] & 4) == 0) {
      iVar3 = **(int **)(in_ECX + 0x20);
      pvVar1 = (void *)((int)_Dst + (**(int **)(in_ECX + 0x1c) - (int)_Src >> 1) * 2);
      **(undefined4 **)(in_ECX + 0xc) = _Dst;
      **(int **)(in_ECX + 0x1c) = (int)pvVar1;
      **(int **)(in_ECX + 0x2c) = (iVar3 - (int)pvVar1) + 2 >> 1;
    }
    else {
      **(undefined4 **)(in_ECX + 0xc) = _Dst;
      **(undefined4 **)(in_ECX + 0x1c) = 0;
      **(int **)(in_ECX + 0x2c) = (int)_Dst >> 1;
    }
  }
  if (((byte)in_ECX[0x3c] & 1) == 0) {
    *(uint *)(in_ECX + 0x3c) = *(uint *)(in_ECX + 0x3c) | 1;
    pwVar4 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::_Pninc(in_ECX);
    *pwVar4 = param_1;
    return param_1;
  }
  operator_delete(_Src);
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_4 @ 004116d0 */

uint std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_4
               (ushort param_1)

{
  uint uVar1;
  uint *puVar2;
  int in_ECX;
  
  puVar2 = *(uint **)(in_ECX + 0x1c);
  uVar1 = *puVar2;
  if (((uVar1 != 0) && (puVar2 = *(uint **)(in_ECX + 0xc), *puVar2 < uVar1)) &&
     ((param_1 == 0xffff ||
      ((param_1 == *(ushort *)(uVar1 - 2) || ((*(byte *)(in_ECX + 0x3c) & 2) == 0)))))) {
    **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) + 1;
    **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + -2;
    if (param_1 != 0xffff) {
      *(ushort *)**(undefined4 **)(in_ECX + 0x1c) = param_1;
      return (uint)param_1;
    }
    return 0;
  }
  return CONCAT22((short)((uint)puVar2 >> 0x10),0xffff);
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_10 @ 00411760 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_10
               (uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  uVar2 = **(uint **)(in_ECX + 0x20);
  if ((uVar2 != 0) && (*(uint *)(in_ECX + 0x38) < uVar2)) {
    *(uint *)(in_ECX + 0x38) = uVar2;
  }
  if (((param_5 & 1) == 0) || (iVar4 = **(int **)(in_ECX + 0x1c), iVar4 == 0)) {
    if (((param_5 & 2) == 0) || (uVar2 = **(uint **)(in_ECX + 0x20), uVar2 == 0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_00411923;
    }
    else {
      if (param_4 == 2) {
        iVar4 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
        uVar3 = iVar4 >> 1;
        bVar6 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar4 >> 0x1f) + (uint)bVar6;
      }
      else if (param_4 == 1) {
        iVar4 = uVar2 - **(int **)(in_ECX + 0xc);
        uVar3 = iVar4 >> 1;
        bVar6 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar4 >> 0x1f) + (uint)bVar6;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        iVar4 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
        iVar1 = iVar4 >> 0x1f;
        if (((int)param_3 <= iVar1) && (((int)param_3 < iVar1 || (param_2 <= (uint)(iVar4 >> 1)))))
        {
          iVar4 = ((int)(**(int **)(in_ECX + 0xc) - uVar2) >> 1) + param_2;
          **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) - iVar4;
          **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + iVar4 * 2;
          goto LAB_00411923;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
      uVar2 = iVar1 >> 1;
      bVar6 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar6;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        iVar1 = iVar4 - **(int **)(in_ECX + 0xc);
        uVar2 = iVar1 >> 1;
        bVar6 = CARRY4(param_2,uVar2);
        param_2 = param_2 + uVar2;
        param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar6;
      }
      else {
LAB_004117d9:
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else if (param_4 != 0) goto LAB_004117d9;
    if (-1 < (int)param_3) {
      iVar1 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
      iVar5 = iVar1 >> 0x1f;
      if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= (uint)(iVar1 >> 1))))) {
        iVar4 = (**(int **)(in_ECX + 0xc) - iVar4 >> 1) + param_2;
        **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) - iVar4;
        **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + iVar4 * 2;
        if ((param_5 & 2) != 0) {
          iVar4 = **(int **)(in_ECX + 0x20);
          if (iVar4 != 0) {
            iVar1 = **(int **)(in_ECX + 0x30);
            iVar5 = **(int **)(in_ECX + 0x1c);
            **(int **)(in_ECX + 0x20) = iVar5;
            **(int **)(in_ECX + 0x30) = (iVar4 + iVar1 * 2) - iVar5 >> 1;
          }
        }
        goto LAB_00411923;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_00411923:
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_11 @ 00411950 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_11
               (uint *param_1,uint param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
               undefined4 param_7,uint param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_4 + param_2;
  uVar6 = param_5 + param_3 + (uint)CARRY4(param_4,param_2);
  uVar1 = **(uint **)(in_ECX + 0x20);
  if ((uVar1 != 0) && (*(uint *)(in_ECX + 0x38) < uVar1)) {
    *(uint *)(in_ECX + 0x38) = uVar1;
  }
  uVar1 = *(uint *)_BADOFF_exref;
  uVar2 = *(uint *)(_BADOFF_exref + 4);
  if ((uVar8 != uVar1) || (uVar7 = uVar6, uVar9 = uVar8, uVar6 != uVar2)) {
    uVar7 = uVar2;
    uVar9 = uVar1;
    if (((param_8 & 1) == 0) || (**(int **)(in_ECX + 0x1c) == 0)) {
      if ((((param_8 & 2) != 0) && (**(int **)(in_ECX + 0x20) != 0)) && (-1 < (int)uVar6)) {
        iVar4 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
        iVar5 = iVar4 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
          iVar4 = (**(int **)(in_ECX + 0xc) - **(int **)(in_ECX + 0x20) >> 1) + uVar8;
          **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) - iVar4;
          **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + iVar4 * 2;
          uVar7 = uVar6;
          uVar9 = uVar8;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      iVar4 = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0xc);
      iVar5 = iVar4 >> 0x1f;
      if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
        iVar4 = (**(int **)(in_ECX + 0xc) - **(int **)(in_ECX + 0x1c) >> 1) + uVar8;
        **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) - iVar4;
        **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + iVar4 * 2;
        uVar7 = uVar6;
        uVar9 = uVar8;
        if ((param_8 & 2) != 0) {
          iVar4 = **(int **)(in_ECX + 0x20);
          if (iVar4 != 0) {
            iVar5 = **(int **)(in_ECX + 0x30);
            iVar3 = **(int **)(in_ECX + 0x1c);
            **(int **)(in_ECX + 0x20) = iVar3;
            **(int **)(in_ECX + 0x30) = (iVar4 + iVar5 * 2) - iVar3 >> 1;
          }
        }
      }
    }
  }
  *param_1 = uVar9;
  param_1[1] = uVar7;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_6 @ 00411c80 */

undefined2
std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vfunc_6(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int in_ECX;
  
  puVar1 = (undefined2 *)**(int **)(in_ECX + 0x1c);
  if (puVar1 == (undefined2 *)0x0) {
    return 0xffff;
  }
  if (puVar1 < puVar1 + **(int **)(in_ECX + 0x2c)) {
    return *puVar1;
  }
  if ((((*(byte *)(in_ECX + 0x3c) & 4) == 0) &&
      (puVar2 = (undefined2 *)**(undefined4 **)(in_ECX + 0x20), puVar2 != (undefined2 *)0x0)) &&
     ((puVar1 < puVar2 || (puVar1 < *(undefined2 **)(in_ECX + 0x38))))) {
    if (*(undefined2 **)(in_ECX + 0x38) < puVar2) {
      *(undefined2 **)(in_ECX + 0x38) = puVar2;
    }
    **(int **)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x38) - **(int **)(in_ECX + 0x1c) >> 1;
    return *(undefined2 *)**(undefined4 **)(in_ECX + 0x1c);
  }
  return 0xffff;
}




/* Global::eh_catchall_00424d20 @ 00424d20 */

undefined * Catch_All_00424d20(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_00424d3a;
}




/* Global::eh_catchall_00424e30 @ 00424e30 */

void Catch_All_00424e30(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  if (7 < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00428b7d @ 00428b7d */

void Catch_All_00428b7d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_00428c5c @ 00428c5c */

void Catch_All_00428c5c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0042bf63 @ 0042bf63 */

void Catch_All_0042bf63(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0042c04f @ 0042c04f */

void Catch_All_0042c04f(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004392af @ 004392af */

void Catch_All_004392af(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_00439398 @ 00439398 */

void Catch_All_00439398(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* [AUDIT] proposed: std::wstring::dtor_free  (confidence: high)
 * purpose: delete heap buffer of wstring in catch handler
 * vars: param_1=this
 */
/* Global::std_wstring_dtor_free @ 0043b5e0 */

void std_wstring_dtor_free(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  return;
}




/* Global::eh_catchall_004492fa @ 004492fa */

undefined * Catch_All_004492fa(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_00449314;
}




/* [AUDIT] proposed: obj::init_and_inflate  (confidence: low)
 * purpose: init object then zlib-inflate stream into it (game wrapper)
 * vars: in_ECX=this
 */
/* Global::obj_init_and_inflate @ 004494b0 */

void obj_init_and_inflate(void)

{
  int in_ECX;
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e1488;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_1c = (void *)0x0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  zlib_inflateBuffer();
  std_container_assign_range(&local_1c);
  if (local_1c != (void *)0x0) {
    operator_delete(local_1c);
  }
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: db::delete_blob  (confidence: high)
 * purpose: SQLite prepare/bind/step DELETE FROM blobs WHERE key=?
 * vars: in_ECX+4=db handle
 */
/* Global::db_delete_blob @ 00449720 */

undefined4 db_delete_blob(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  while( true ) {
    iVar1 = sqlite3_prepare_v2_526480(*(undefined4 *)(in_ECX + 4),"DELETE FROM blobs WHERE key = ?",0xffffffff,
                         &param_1,0);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = string_data(0xffffffff,0);
    sqlite3_bind_blob_526b60(param_1,1,uVar2);
    iVar1 = sqlite3_step(param_1);
    if (iVar1 == 100) break;
    iVar1 = sqlite3_finalize(param_1);
    if (iVar1 != 0x11) {
      return 0;
    }
  }
  sqlite3_finalize(param_1);
  return 1;
}




/* [AUDIT] proposed: db::update_blob_key  (confidence: high)
 * purpose: SQLite UPDATE blobs SET key=? WHERE key=?
 * vars: in_ECX+4=db handle
 */
/* Global::db_update_blob_key @ 00449920 */

undefined4 db_update_blob_key(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  while( true ) {
    iVar1 = sqlite3_prepare_v2_526480(*(undefined4 *)(in_ECX + 4),"UPDATE blobs SET key = ? WHERE key = ?",
                         0xffffffff,&param_2,0);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = string_data(0xffffffff,0);
    sqlite3_bind_blob_526b60(param_2,1,uVar2);
    uVar2 = string_data(0xffffffff,0);
    sqlite3_bind_blob_526b60(param_2,2,uVar2);
    iVar1 = sqlite3_step(param_2);
    if (iVar1 == 100) break;
    iVar1 = sqlite3_finalize(param_2);
    if (iVar1 != 0x11) {
      return 1;
    }
  }
  sqlite3_finalize(param_2);
  return 1;
}




/* Global::eh_catchall_0044a17d @ 0044a17d */

void Catch_All_0044a17d(void)

{
  int unaff_EBP;
  
  std_Tree_Freenode_str(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0044a39e @ 0044a39e */

void Catch_All_0044a39e(void)

{
  int unaff_EBP;
  
  std_Tree_Freenode_str(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0044a476 @ 0044a476 */

void Catch_All_0044a476(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
    std_wstring_dtor_free(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0044a79f @ 0044a79f */

void Catch_All_0044a79f(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0044ab90 @ 0044ab90 */

void Catch_All_0044ab90(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0044ad13 @ 0044ad13 */

void Catch_All_0044ad13(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0044aee3 @ 0044aee3 */

void Catch_All_0044aee3(void)

{
  FUN_0063de60();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: std::_Tree::_Freenode_str  (confidence: high)
 * purpose: destroy rbtree node w/ string key then free node
 * vars: param_1=node
 */
/* Global::std_Tree_Freenode_str @ 0044b7f0 */

void std_Tree_Freenode_str(void *param_1)

{
  if (0xf < *(uint *)((int)param_1 + 0x28)) {
    operator_delete(*(void **)((int)param_1 + 0x14));
  }
  *(undefined4 *)((int)param_1 + 0x28) = 0xf;
  *(undefined4 *)((int)param_1 + 0x24) = 0;
  *(undefined1 *)((int)param_1 + 0x14) = 0;
  operator_delete(param_1);
}




/* Global::eh_catchall_0044b9f0 @ 0044b9f0 */

void Catch_All_0044b9f0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0044baee @ 0044baee */

void Catch_All_0044baee(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0044bbec @ 0044bbec */

void Catch_All_0044bbec(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0044d77d @ 0044d77d */

void Catch_All_0044d77d(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: serialize_struct_0x28  (confidence: low)
 * purpose: write struct fields to stream buffer (game writer)
 * vars: param_1=src;in_ECX=writer
 */
/* Global::serialize_struct_0x28 @ 0044e120 */

void serialize_struct_0x28(int param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(int *)(piVar1[3] + *piVar1) = in_ECX[1];
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(*piVar1 + piVar1[3]) = *(undefined4 *)(param_1 + 4);
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(*piVar1 + piVar1[3]) = *(undefined4 *)(param_1 + 8);
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(piVar1[3] + *piVar1) = *(undefined4 *)(param_1 + 0xc);
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(piVar1[3] + *piVar1) = *(undefined4 *)(param_1 + 0x10);
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 1);
  *(undefined1 *)(*piVar1 + piVar1[3]) = *(undefined1 *)(param_1 + 0x14);
  piVar1[3] = piVar1[3] + 1;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 1);
  *(undefined1 *)(*piVar1 + piVar1[3]) = *(undefined1 *)(param_1 + 0x15);
  piVar1[3] = piVar1[3] + 1;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(piVar1[3] + *piVar1) = *(undefined4 *)(param_1 + 0x18);
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(piVar1[3] + *piVar1) = *(undefined4 *)(param_1 + 0x1c);
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 8);
  *(undefined8 *)(*piVar1 + piVar1[3]) = *(undefined8 *)(param_1 + 0x20);
  piVar1[3] = piVar1[3] + 8;
  return;
}




/* [AUDIT] proposed: serialize_struct_small  (confidence: low)
 * purpose: write small struct fields to stream buffer (game writer)
 * vars: param_1=src;in_ECX=writer
 */
/* Global::serialize_struct_small @ 0044e280 */

void serialize_struct_small(undefined4 *param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(int *)(piVar1[3] + *piVar1) = in_ECX[1];
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(*piVar1 + piVar1[3]) = *param_1;
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 4);
  *(undefined4 *)(piVar1[3] + *piVar1) = param_1[1];
  piVar1[3] = piVar1[3] + 4;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 1);
  *(undefined1 *)(piVar1[3] + *piVar1) = *(undefined1 *)(param_1 + 2);
  piVar1[3] = piVar1[3] + 1;
  piVar1 = (int *)*in_ECX;
  Vector_Resize((piVar1[1] - *piVar1) + 8);
  *(undefined8 *)(piVar1[3] + *piVar1) = *(undefined8 *)(param_1 + 3);
  piVar1[3] = piVar1[3] + 8;
  return;
}




/* [AUDIT] proposed: serialize_struct_creatures  (confidence: low)
 * purpose: serialize struct with creature/id vectors to buffer (game writer)
 * vars: param_1=src;in_ECX=writer
 */
/* Global::serialize_struct_creatures @ 0044e340 */

void serialize_struct_creatures(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  size_t _Size;
  void *pvVar8;
  int local_c;
  
  iVar4 = param_1;
  piVar2 = (int *)*in_ECX;
  Vector_Resize((piVar2[1] - *piVar2) + 4);
  *(int *)(*piVar2 + piVar2[3]) = in_ECX[1];
  piVar2[3] = piVar2[3] + 4;
  if (*(char *)(param_1 + 0x75) == '\0') {
    piVar2 = (int *)*in_ECX;
    Vector_Resize((piVar2[1] - *piVar2) + 4);
    *(undefined4 *)(piVar2[3] + *piVar2) = 0;
    piVar2[3] = piVar2[3] + 4;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x34);
    iVar3 = *(int *)(param_1 + 0x30);
    piVar2 = (int *)*in_ECX;
    Vector_Resize((piVar2[1] - *piVar2) + 4);
    *(int *)(*piVar2 + piVar2[3]) = (iVar6 - iVar3) / 0x148;
    piVar2[3] = piVar2[3] + 4;
    pvVar8 = *(void **)(param_1 + 0x30);
    if (pvVar8 != *(void **)(param_1 + 0x34)) {
      do {
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 0x118);
        memcpy((void *)(piVar2[3] + *piVar2),pvVar8,0x118);
        piVar2[3] = piVar2[3] + 0x118;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 0x18);
        puVar5 = (undefined8 *)(piVar2[3] + *piVar2);
        *puVar5 = *(undefined8 *)((int)pvVar8 + 0x118);
        puVar5[1] = *(undefined8 *)((int)pvVar8 + 0x120);
        puVar5[2] = *(undefined8 *)((int)pvVar8 + 0x128);
        piVar2[3] = piVar2[3] + 0x18;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 4);
        *(undefined4 *)(piVar2[3] + *piVar2) = *(undefined4 *)((int)pvVar8 + 0x130);
        piVar2[3] = piVar2[3] + 4;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 4);
        *(undefined4 *)(*piVar2 + piVar2[3]) = *(undefined4 *)((int)pvVar8 + 0x134);
        piVar2[3] = piVar2[3] + 4;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 1);
        *(undefined1 *)(*piVar2 + piVar2[3]) = *(undefined1 *)((int)pvVar8 + 0x138);
        piVar2[3] = piVar2[3] + 1;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 4);
        *(undefined4 *)(piVar2[3] + *piVar2) = *(undefined4 *)((int)pvVar8 + 0x13c);
        piVar2[3] = piVar2[3] + 4;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 4);
        *(undefined4 *)(piVar2[3] + *piVar2) = *(undefined4 *)((int)pvVar8 + 0x140);
        piVar2[3] = piVar2[3] + 4;
        piVar2 = (int *)*in_ECX;
        Vector_Resize((piVar2[1] - *piVar2) + 4);
        puVar1 = (undefined4 *)((int)pvVar8 + 0x144);
        pvVar8 = (void *)((int)pvVar8 + 0x148);
        *(undefined4 *)(*piVar2 + piVar2[3]) = *puVar1;
        piVar2[3] = piVar2[3] + 4;
      } while (pvVar8 != *(void **)(param_1 + 0x34));
    }
  }
  piVar2 = (int *)*in_ECX;
  iVar6 = (*(int *)(param_1 + 0x6c) - *(int *)(param_1 + 0x68)) / 0x14;
  Vector_Resize((piVar2[1] - *piVar2) + 4);
  *(int *)(piVar2[3] + *piVar2) = iVar6;
  piVar2[3] = piVar2[3] + 4;
  pvVar8 = *(void **)(param_1 + 0x68);
  iVar7 = *(int *)(param_1 + 0x6c) - (int)pvVar8;
  iVar3 = iVar7 >> 0x1f;
  if (iVar7 / 0x14 + iVar3 != iVar3) {
    _Size = iVar6 * 0x14;
    piVar2 = (int *)*in_ECX;
    Vector_Resize((piVar2[1] - *piVar2) + _Size);
    memcpy((void *)(*piVar2 + piVar2[3]),pvVar8,_Size);
    piVar2[3] = piVar2[3] + _Size;
  }
  piVar2 = (int *)*in_ECX;
  iVar6 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2;
  Vector_Resize((piVar2[1] - *piVar2) + 4);
  *(int *)(*piVar2 + piVar2[3]) = iVar6;
  piVar2[3] = piVar2[3] + 4;
  param_1 = 0;
  if (0 < iVar6) {
    do {
      iVar3 = *(int *)(*(int *)(iVar4 + 0x18) + param_1 * 4);
      piVar2 = (int *)*in_ECX;
      Vector_Resize((piVar2[1] - *piVar2) + 4);
      *(undefined4 *)(*piVar2 + piVar2[3]) = *(undefined4 *)(iVar3 + 0x38);
      piVar2[3] = piVar2[3] + 4;
      iVar3 = *(int *)(*(int *)(iVar4 + 0x18) + param_1 * 4);
      piVar2 = (int *)*in_ECX;
      Vector_Resize((piVar2[1] - *piVar2) + 4);
      *(undefined4 *)(*piVar2 + piVar2[3]) = *(undefined4 *)(iVar3 + 0x3c);
      piVar2[3] = piVar2[3] + 4;
      param_1 = param_1 + 1;
    } while (param_1 < iVar6);
  }
  piVar2 = (int *)*in_ECX;
  param_1 = (*(int *)(iVar4 + 0x10) - *(int *)(iVar4 + 0xc)) / 0x188;
  Vector_Resize((piVar2[1] - *piVar2) + 4);
  *(int *)(piVar2[3] + *piVar2) = param_1;
  piVar2[3] = piVar2[3] + 4;
  if (0 < param_1) {
    local_c = 0;
    do {
      piVar2 = (int *)*in_ECX;
      iVar6 = *(int *)(iVar4 + 0xc);
      Vector_Resize((piVar2[1] - *piVar2) + 1);
      *(undefined1 *)(piVar2[3] + *piVar2) = *(undefined1 *)(iVar6 + local_c + 0x30);
      piVar2[3] = piVar2[3] + 1;
      local_c = local_c + 0x188;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::ctor_0 @ 00450fb0 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::ctor_0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = vftable;
    in_ECX[1] = *param_1;
    in_ECX[4] = in_ECX;
    return;
  }
  uRam00000010 = 0;
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::ctor_0 @ 00451020 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::ctor_0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = vftable;
    in_ECX[1] = *param_1;
    in_ECX[4] = in_ECX;
    return;
  }
  uRam00000010 = 0;
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::ctor_0 @ 00451090 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::ctor_0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = vftable;
    in_ECX[1] = *param_1;
    in_ECX[4] = in_ECX;
    return;
  }
  uRam00000010 = 0;
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::ctor_0 @ 00451100 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::ctor_0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = vftable;
    in_ECX[1] = *param_1;
    in_ECX[4] = in_ECX;
    return;
  }
  uRam00000010 = 0;
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::ctor_0 @ 00451170 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::ctor_0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = vftable;
    in_ECX[1] = *param_1;
    in_ECX[4] = in_ECX;
    return;
  }
  uRam00000010 = 0;
  return;
}




/* Global::eh_catchall_00451360 @ 00451360 */

undefined * Catch_All_00451360(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_0045137a;
}




/* Global::eh_catchall_00451c57 @ 00451c57 */

void Catch_All_00451c57(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_00451e69 @ 00451e69 */

void Catch_All_00451e69(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_00451fd2 @ 00451fd2 */

void Catch_All_00451fd2(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_00452171 @ 00452171 */

void Catch_All_00452171(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_00452247 @ 00452247 */

void Catch_All_00452247(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_004523ae @ 004523ae */

void Catch_All_004523ae(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  if (0xf < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 0xf;
  puVar1[4] = 0;
  *(undefined1 *)puVar1 = 0;
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004525df @ 004525df */

void Catch_All_004525df(void)

{
  int unaff_EBP;
  
  rbtree_destroyRec_str(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004527d4 @ 004527d4 */

void Catch_All_004527d4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
}




/* Global::eh_catchall_0045299d @ 0045299d */

void Catch_All_0045299d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
}




/* Global::eh_catchall_004531e7 @ 004531e7 */

void Catch_All_004531e7(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_00453404 @ 00453404 */

void Catch_All_00453404(void)

{
  int unaff_EBP;
  
  Node_dtor_2strings(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0045361f @ 0045361f */

void Catch_All_0045361f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0045386f @ 0045386f */

void Catch_All_0045386f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0045399a @ 0045399a */

void Catch_All_0045399a(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_00453b24 @ 00453b24 */

void Catch_All_00453b24(void)

{
  int unaff_EBP;
  
  Node_dtor_2strings(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00453c54 @ 00453c54 */

void Catch_All_00453c54(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_00453da4 @ 00453da4 */

void Catch_All_00453da4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_00453ef7 @ 00453ef7 */

void Catch_All_00453ef7(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00453fa9 @ 00453fa9 */

void Catch_All_00453fa9(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454079 @ 00454079 */

void Catch_All_00454079(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454149 @ 00454149 */

void Catch_All_00454149(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454219 @ 00454219 */

void Catch_All_00454219(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004542e9 @ 004542e9 */

void Catch_All_004542e9(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase_46eb20(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004543b9 @ 004543b9 */

void Catch_All_004543b9(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454489 @ 00454489 */

void Catch_All_00454489(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454559 @ 00454559 */

void Catch_All_00454559(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454629 @ 00454629 */

void Catch_All_00454629(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004546f9 @ 004546f9 */

void Catch_All_004546f9(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_Unlink(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004547c9 @ 004547c9 */

void Catch_All_004547c9(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454899 @ 00454899 */

void Catch_All_00454899(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454969 @ 00454969 */

void Catch_All_00454969(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454a39 @ 00454a39 */

void Catch_All_00454a39(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00454b09 @ 00454b09 */

void Catch_All_00454b09(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00456aa6 @ 00456aa6 */

void Catch_All_00456aa6(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 8) {
    dtor_and_free_catch(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00456b5c @ 00456b5c */

void Catch_All_00456b5c(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
    std_basic_string_Tidy(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00456ced @ 00456ced */

void Catch_All_00456ced(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
    std_wstring_dtor_free(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00456e4a @ 00456e4a */

void Catch_All_00456e4a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x128) {
    std_Tidy_deallocate_catch(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004571be @ 004571be */

void Catch_All_004571be(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004572a2 @ 004572a2 */

void Catch_All_004572a2(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00457392 @ 00457392 */

void Catch_All_00457392(void)

{
  listNode_free_ownsString();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: std::_Tidy_deallocate@catch  (confidence: med)
 * purpose: SEH cleanup funclet: operator delete of element buffer at +0x11c
 * vars: -
 */
/* Global::std_Tidy_deallocate_catch @ 004578a0 */

void std_Tidy_deallocate_catch(int param_1)

{
  if (*(void **)(param_1 + 0x11c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x11c));
  }
  return;
}




/* [AUDIT] proposed: dtor_and_free@catch  (confidence: med)
 * purpose: SEH cleanup funclet: run member dtor (listNode_free_ownsString) then operator delete
 * vars: -
 */
/* Global::dtor_and_free_catch @ 004578e0 */

void dtor_and_free_catch(undefined4 *param_1)

{
  listNode_free_ownsString();
  operator_delete((void *)*param_1);
}




/* [AUDIT] proposed: std::basic_string::_Tidy  (confidence: high)
 * purpose: Free string heap buffer if >15 cap and reset to empty SSO state
 * vars: param_1=string
 */
/* Global::std_basic_string_Tidy @ 00457900 */

void std_basic_string_Tidy(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}




/* std::pair<unsigned___int64,unsigned___int64>::operator=<std::pair<unsigned___int64,unsigned___int64>,0> @ 00458cf0 */

/* Library Function - Single Match
    public: struct std::pair<unsigned __int64,unsigned __int64> & __thiscall std::pair<unsigned
   __int64,unsigned __int64>::operator=<struct std::pair<unsigned __int64,unsigned
   __int64>,0>(struct std::pair<unsigned __int64,unsigned __int64> &&)
   
   Library: Visual Studio 2019 Release */

pair<unsigned___int64,unsigned___int64> * __thiscall
std::pair<unsigned___int64,unsigned___int64>::
operator=<std::pair<unsigned___int64,unsigned___int64>,0>
          (pair<unsigned___int64,unsigned___int64> *this,
          pair<unsigned___int64,unsigned___int64> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return this;
}




/* Global::eh_catchall_00458db6 @ 00458db6 */

void Catch_All_00458db6(void)

{
  int unaff_EBP;
  
  rbtree_eraseRange_str(unaff_EBP + 8,*(undefined4 *)**(undefined4 **)(unaff_EBP + -0x18),
               (undefined4 *)**(undefined4 **)(unaff_EBP + -0x18));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00458e6f @ 00458e6f */

void Catch_All_00458e6f(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00458f0f @ 00458f0f */

void Catch_All_00458f0f(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00458faf @ 00458faf */

void Catch_All_00458faf(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0045904f @ 0045904f */

void Catch_All_0045904f(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004590ef @ 004590ef */

void Catch_All_004590ef(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0045918f @ 0045918f */

void Catch_All_0045918f(void)

{
  listNode_free_ownsString();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0045922f @ 0045922f */

void Catch_All_0045922f(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004592cf @ 004592cf */

void Catch_All_004592cf(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0045938f @ 0045938f */

void Catch_All_0045938f(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0045947c @ 0045947c */

void Catch_All_0045947c(void)

{
  FUN_0063de60();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::thunk_FUN_0046ea70 @ 00466be0 */

void thunk_FUN_0046ea70(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  puVar1 = (undefined4 *)*in_ECX;
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  if (puVar1 != (undefined4 *)in_ECX[1]) {
    listNode_free_ownsString();
    operator_delete((void *)*puVar1);
  }
  operator_delete((void *)*in_ECX);
}




/* Global::eh_catchall_004681c0 @ 004681c0 */

void Catch_All_004681c0(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004682fe @ 004682fe */

void Catch_All_004682fe(void)

{
  vector_destroy_stringElems();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00468419 @ 00468419 */

void Catch_All_00468419(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004685c8 @ 004685c8 */

void Catch_All_004685c8(void)

{
  object_dtor_v3();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: World::streamChunksAroundPlayer  (confidence: low)
 * purpose: GAME (mislabeled lib): stream/load region chunks in radius around player under locks
 * vars: in_ECX=world/controller
 */
/* Global::World_streamChunksAroundPlayer @ 00469590 */

void World_streamChunksAroundPlayer(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  DWORD DVar12;
  int *in_ECX;
  int *piVar13;
  byte *pbVar14;
  int iVar15;
  int *piVar16;
  byte *pbVar17;
  uint uVar18;
  code *pcVar19;
  uint uVar20;
  bool bVar21;
  DWORD local_5c;
  int local_4c;
  int local_48;
  int local_40;
  int local_28;
  int iStack_24;
  undefined8 local_18;
  
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_5c = timeGetTime();
  cVar1 = *(char *)(*in_ECX + 0x800584);
  do {
    if (cVar1 == '\0') {
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005e8));
    EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
    iVar7 = *in_ECX;
    local_28 = (int)*(undefined8 *)(iVar7 + 700);
    iStack_24 = (int)((ulonglong)*(undefined8 *)(iVar7 + 700) >> 0x20);
    iVar4 = (int)(*(float *)(iVar7 + 0x1000e4c) * 0.00390625f + (float)local_28);
    iVar5 = (int)(*(float *)(iVar7 + 0x1000e50) * 0.00390625f + (float)iStack_24);
    if (*(int *)(iVar7 + 0x800a50) == *(int *)(iVar7 + 0x800448)) {
      uVar20 = *(uint *)(iVar7 + 0x388);
      piVar16 = (int *)(iVar7 + 0x378);
      piVar13 = (int *)(iVar7 + 0x800a54);
      if (0xf < *(uint *)(iVar7 + 0x38c)) {
        piVar16 = (int *)*piVar16;
      }
      uVar18 = *(uint *)(iVar7 + 0x800a64);
      if (0xf < *(uint *)(iVar7 + 0x800a68)) {
        piVar13 = (int *)*piVar13;
      }
      uVar9 = uVar20;
      if (uVar18 < uVar20) {
        uVar9 = uVar18;
      }
      iVar6 = memcmp_traits(piVar13,piVar16,uVar9);
      if ((((iVar6 != 0) || (uVar18 < uVar20)) || (uVar18 != uVar20)) ||
         (*(char *)(iVar7 + 0x800584) == '\0')) goto LAB_0046969a;
      bVar21 = false;
    }
    else {
LAB_0046969a:
      bVar21 = true;
    }
    pcVar19 = LeaveCriticalSection_exref;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
    if (!bVar21) {
      iVar7 = (int)(iVar4 + (iVar4 >> 0x1f & 0x3fU)) >> 6;
      local_40 = iVar7 + -3;
      iVar7 = iVar7 + 3;
      if (local_40 <= iVar7) {
        iVar8 = (int)(iVar5 + (iVar5 >> 0x1f & 0x3fU)) >> 6;
        iVar6 = iVar8 + -3;
        iVar10 = iVar6;
        iVar15 = local_40;
        do {
          for (; iVar10 <= iVar8 + 3; iVar10 = iVar10 + 1) {
            EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
            iVar2 = *in_ECX;
            if (*(int *)(iVar2 + 0x800a50) == *(int *)(iVar2 + 0x800448)) {
              uVar20 = *(uint *)(iVar2 + 0x388);
              pbVar17 = (byte *)(iVar2 + 0x378);
              pbVar14 = (byte *)(iVar2 + 0x800a54);
              if (0xf < *(uint *)(iVar2 + 0x38c)) {
                pbVar17 = *(byte **)pbVar17;
              }
              uVar18 = *(uint *)(iVar2 + 0x800a64);
              if (0xf < *(uint *)(iVar2 + 0x800a68)) {
                pbVar14 = *(byte **)pbVar14;
              }
              uVar9 = uVar20;
              if (uVar18 < uVar20) {
                uVar9 = uVar18;
              }
              if (uVar9 != 0) {
                while (uVar11 = uVar9 - 4, 3 < uVar9) {
                  if (*(int *)pbVar14 != *(int *)pbVar17) goto LAB_00469776;
                  pbVar14 = pbVar14 + 4;
                  pbVar17 = pbVar17 + 4;
                  uVar9 = uVar11;
                }
                if (uVar11 == 0xfffffffc) {
LAB_004697aa:
                  uVar9 = 0;
                }
                else {
LAB_00469776:
                  bVar21 = *pbVar14 < *pbVar17;
                  if ((*pbVar14 == *pbVar17) &&
                     ((uVar11 == 0xfffffffd ||
                      ((bVar21 = pbVar14[1] < pbVar17[1], pbVar14[1] == pbVar17[1] &&
                       ((uVar11 == 0xfffffffe ||
                        ((bVar21 = pbVar14[2] < pbVar17[2], pbVar14[2] == pbVar17[2] &&
                         ((uVar11 == 0xffffffff ||
                          (bVar21 = pbVar14[3] < pbVar17[3], pbVar14[3] == pbVar17[3]))))))))))))
                  goto LAB_004697aa;
                  uVar9 = -(uint)bVar21 | 1;
                }
                if (uVar9 != 0) goto LAB_004697c7;
              }
              if ((uVar18 < uVar20) || (uVar18 != uVar20)) goto LAB_004697c7;
              bVar21 = false;
            }
            else {
LAB_004697c7:
              bVar21 = true;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
            if (bVar21) goto LAB_00469835;
            World_enterCriticalSection();
            std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_3
                      (iVar15,iVar10);
            leave_critical_section_b();
          }
          iVar15 = iVar15 + 1;
          iVar10 = iVar6;
        } while (iVar15 <= iVar7);
      }
LAB_00469835:
      if (local_40 <= iVar7) {
        iVar10 = (int)(iVar5 + (iVar5 >> 0x1f & 0x3fU)) >> 6;
        iVar6 = iVar10 + -3;
        iVar10 = iVar10 + 3;
        do {
          local_48 = iVar6;
          if (iVar10 < iVar6) {
            if (bVar21) break;
          }
          else {
            do {
              EnterCriticalSection((LPCRITICAL_SECTION)(*in_ECX + 0x8005d0));
              iVar15 = *in_ECX;
              if (*(int *)(iVar15 + 0x800a50) == *(int *)(iVar15 + 0x800448)) {
                uVar20 = *(uint *)(iVar15 + 0x388);
                pbVar17 = (byte *)(iVar15 + 0x378);
                pbVar14 = (byte *)(iVar15 + 0x800a54);
                if (0xf < *(uint *)(iVar15 + 0x38c)) {
                  pbVar17 = *(byte **)pbVar17;
                }
                uVar18 = *(uint *)(iVar15 + 0x800a64);
                if (0xf < *(uint *)(iVar15 + 0x800a68)) {
                  pbVar14 = *(byte **)pbVar14;
                }
                uVar9 = uVar20;
                if (uVar18 < uVar20) {
                  uVar9 = uVar18;
                }
                if (uVar9 != 0) {
                  while (uVar11 = uVar9 - 4, 3 < uVar9) {
                    if (*(int *)pbVar14 != *(int *)pbVar17) goto LAB_004698d6;
                    pbVar14 = pbVar14 + 4;
                    pbVar17 = pbVar17 + 4;
                    uVar9 = uVar11;
                  }
                  if (uVar11 == 0xfffffffc) {
LAB_0046990a:
                    uVar9 = 0;
                  }
                  else {
LAB_004698d6:
                    bVar21 = *pbVar14 < *pbVar17;
                    if ((*pbVar14 == *pbVar17) &&
                       ((uVar11 == 0xfffffffd ||
                        ((bVar21 = pbVar14[1] < pbVar17[1], pbVar14[1] == pbVar17[1] &&
                         ((uVar11 == 0xfffffffe ||
                          ((bVar21 = pbVar14[2] < pbVar17[2], pbVar14[2] == pbVar17[2] &&
                           ((uVar11 == 0xffffffff ||
                            (bVar21 = pbVar14[3] < pbVar17[3], pbVar14[3] == pbVar17[3]))))))))))))
                    goto LAB_0046990a;
                    uVar9 = -(uint)bVar21 | 1;
                  }
                  if (uVar9 != 0) goto LAB_00469927;
                }
                if ((uVar18 < uVar20) || (uVar18 != uVar20)) goto LAB_00469927;
                bVar21 = false;
              }
              else {
LAB_00469927:
                bVar21 = true;
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar15 + 0x8005d0));
              if (bVar21) goto LAB_00469993;
              World_enterCriticalSection();
              cube::GameController::loadLandscapeTile
                        (local_40,local_48);
              leave_critical_section_b();
              local_48 = local_48 + 1;
            } while (local_48 <= iVar10);
            bVar21 = false;
          }
          local_40 = local_40 + 1;
        } while (local_40 <= iVar7);
      }
LAB_00469993:
      local_48 = 10;
      do {
        iVar7 = -1;
        local_4c = -1;
        local_18 = 0xffffffffffffffff;
        if ((int)(iVar4 - 10U) < iVar4 + 10) {
          uVar20 = iVar4 - 10U;
          do {
            uVar18 = iVar5 - 10U;
            if ((int)(iVar5 - 10U) < iVar5 + 10) {
              do {
                World_enterCriticalSection();
                enter_critical_section();
                iVar7 = hash_or_index_compute(uVar20,uVar18);
                if (iVar7 == 0) {
LAB_00469ac7:
                  bVar21 = true;
                }
                else {
                  if ((*(int *)(iVar7 + 8) == 0) || (*(char *)(iVar7 + 0x28) != '\0')) {
                    if ((*(byte *)(iVar7 + 0x30) & 2) != 0) goto LAB_00469ac7;
                    if ((((-1 < (int)uVar20) && (-1 < (int)uVar18)) && ((int)uVar20 < 0x10000)) &&
                       ((int)uVar18 < 0x10000)) {
                      iVar6 = (int)(((int)uVar18 >> 0x1f & 0x3fU) + uVar18) >> 6;
                      iVar7 = (int)(((int)uVar20 >> 0x1f & 0x3fU) + uVar20) >> 6;
                      if (((-1 < iVar7) && (-1 < iVar6)) &&
                         ((iVar7 < 0x400 &&
                          ((iVar6 < 0x400 &&
                           (iVar7 = *(int *)(*in_ECX + 0x3a0 + (iVar7 * 0x400 + iVar6) * 4),
                           iVar7 != 0)))))) {
                        uVar9 = uVar20 & 0x8000003f;
                        if ((int)uVar9 < 0) {
                          uVar9 = (uVar9 - 1 | 0xffffffc0) + 1;
                        }
                        uVar11 = uVar18 & 0x8000003f;
                        if ((int)uVar11 < 0) {
                          uVar11 = (uVar11 - 1 | 0xffffffc0) + 1;
                        }
                        if (*(int *)(iVar7 + 0x10018 + (uVar9 * 0x40 + uVar11) * 4) != 0)
                        goto LAB_00469ac7;
                      }
                    }
                  }
                  bVar21 = false;
                }
                leave_critical_section();
                leave_critical_section_b();
                if ((bVar21) &&
                   ((iVar7 = (uVar20 - iVar4) * (uVar20 - iVar4) +
                             (uVar18 - iVar5) * (uVar18 - iVar5), local_4c < 0 || (iVar7 < local_4c)
                    ))) {
                  local_18 = CONCAT44(uVar18,uVar20);
                  local_4c = iVar7;
                }
                uVar18 = uVar18 + 1;
                iVar7 = local_4c;
              } while ((int)uVar18 < iVar5 + 10);
            }
            uVar20 = uVar20 + 1;
          } while ((int)uVar20 < iVar4 + 10);
          if (-1 < iVar7) {
            World_enterCriticalSection();
            cube::GameController::streamTileChunk
                      ((undefined4)local_18,local_18._4_4_);
            leave_critical_section_b();
          }
        }
        local_48 = local_48 + -1;
        pcVar19 = LeaveCriticalSection_exref;
      } while (local_48 != 0);
    }
    DVar12 = timeGetTime();
    if (1000 < (int)(DVar12 - local_5c)) {
      lib_fn_5fbed0(iVar4,iVar5);
      local_5c = DVar12;
    }
    (*pcVar19)(*in_ECX + 0x8005e8);
    Sleep(10);
    cVar1 = *(char *)(*in_ECX + 0x800584);
  } while( true );
}




/* std::_Func_base<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_5 @ 0046d2c0 */

void std::_Func_base<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::
     vfunc_5(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_0 @ 0046da50 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_0(undefined4 *param_1)

{
  int in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    param_1 = operator_new(0xc);
    if (param_1 == (undefined4 *)0x0) {
      std::_Xbad_alloc();
    }
  }
  *param_1 = vftable;
  param_1[1] = *(undefined4 *)(in_ECX + 4);
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_4 @ 0046da90 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_4(char param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x14))(0);
  if (param_1 != '\0') {
    operator_delete(in_ECX);
  }
  return;
}




/* [AUDIT] proposed: std::_Destroy_range@catch  (confidence: med)
 * purpose: SEH cleanup: destroy vector<string> elements (dtor_stringRange_0x18)
 * vars: -
 */
/* Global::std_Destroy_range_catch @ 0046daf0 */

void std_Destroy_range_catch(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_5;
  
  dtor_stringRange_0x18(param_1,param_2,&local_5,param_2);
  return;
}




/* [AUDIT] proposed: Node_dtor_2strings  (confidence: high)
 * purpose: Destructor: free two SSO strings (+0x28,+0x10) then delete node
 * vars: strings at +0x10,+0x28
 */
/* Global::Node_dtor_2strings @ 0046db10 */

void Node_dtor_2strings(void *param_1)

{
  if (7 < *(uint *)((int)param_1 + 0x3c)) {
    operator_delete(*(void **)((int)param_1 + 0x28));
  }
  *(undefined4 *)((int)param_1 + 0x3c) = 7;
  *(undefined4 *)((int)param_1 + 0x38) = 0;
  *(undefined2 *)((int)param_1 + 0x28) = 0;
  if (7 < *(uint *)((int)param_1 + 0x24)) {
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  *(undefined4 *)((int)param_1 + 0x24) = 7;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined2 *)((int)param_1 + 0x10) = 0;
  operator_delete(param_1);
}




/* std::_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_2 @ 0046db70 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_2(void)

{
  cube::World::updateNearbyEntities();
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_2 @ 0046db80 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_2(void)

{
  World_streamChunksAroundPlayer();
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_2 @ 0046db90 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_2(void)

{
  cube::World::updateActiveChunks();
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_2 @ 0046dba0 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_2(void)

{
  cube::WorldInfo::ctor_0();
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_2 @ 0046dbb0 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_2(void)

{
  cube::GameController::networkReceiveThread();
  return;
}




/* [AUDIT] proposed: std::list<T>::_Tidy  (confidence: high)
 * purpose: Clear list member at this+0x10: relink head, free nodes and head
 * vars: param_1=this
 */
/* Global::std_list_Tidy @ 0046dc50 */

void std_list_Tidy(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (pvVar2 != *(void **)(param_1 + 0x10)) {
    operator_delete(pvVar2);
  }
  operator_delete(*(void **)(param_1 + 0x10));
}




/* std::_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_6 @ 0046dca0 */

int std::
    _Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
    ::vfunc_6(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_0 @ 0046e050 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_0(undefined4 *param_1)

{
  int in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    param_1 = operator_new(0xc);
    if (param_1 == (undefined4 *)0x0) {
      std::_Xbad_alloc();
    }
  }
  *param_1 = vftable;
  param_1[1] = *(undefined4 *)(in_ECX + 4);
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_0 @ 0046e090 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_0(undefined4 *param_1)

{
  int in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    param_1 = operator_new(0xc);
    if (param_1 == (undefined4 *)0x0) {
      std::_Xbad_alloc();
    }
  }
  *param_1 = vftable;
  param_1[1] = *(undefined4 *)(in_ECX + 4);
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_0 @ 0046e0d0 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_0(undefined4 *param_1)

{
  int in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    param_1 = operator_new(0xc);
    if (param_1 == (undefined4 *)0x0) {
      std::_Xbad_alloc();
    }
  }
  *param_1 = vftable;
  param_1[1] = *(undefined4 *)(in_ECX + 4);
  return;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_0 @ 0046e110 */

void std::
     _Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
     ::vfunc_0(undefined4 *param_1)

{
  int in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    param_1 = operator_new(0xc);
    if (param_1 == (undefined4 *)0x0) {
      std::_Xbad_alloc();
    }
  }
  *param_1 = vftable;
  param_1[1] = *(undefined4 *)(in_ECX + 4);
  return;
}




/* Global::eh_catchall_0046e239 @ 0046e239 */

void Catch_All_0046e239(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0046e30c @ 0046e30c */

void Catch_All_0046e30c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0046e40e @ 0046e40e */

void Catch_All_0046e40e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
}




/* Global::eh_catchall_0046e50e @ 0046e50e */

void Catch_All_0046e50e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0046e5ed @ 0046e5ed */

void Catch_All_0046e5ed(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0046e6f1 @ 0046e6f1 */

void Catch_All_0046e6f1(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* std::_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_3 @ 0046ea20 */

TypeDescriptor *
std::
_Func_impl<std::_Callable_obj<<lambda_1ffef8671b5d330b7078b5ff273ee5fb>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
::vfunc_3(void)

{
  return &<lambda_1ffef8671b5d330b7078b5ff273ee5fb>::RTTI_Type_Descriptor;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_3 @ 0046ea30 */

TypeDescriptor *
std::
_Func_impl<std::_Callable_obj<<lambda_29209b183b27224642a038ec1f3692c5>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
::vfunc_3(void)

{
  return &<lambda_29209b183b27224642a038ec1f3692c5>::RTTI_Type_Descriptor;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_3 @ 0046ea40 */

TypeDescriptor *
std::
_Func_impl<std::_Callable_obj<<lambda_864084cd43f09ea2a93402c86ee87b29>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
::vfunc_3(void)

{
  return &<lambda_864084cd43f09ea2a93402c86ee87b29>::RTTI_Type_Descriptor;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_3 @ 0046ea50 */

TypeDescriptor *
std::
_Func_impl<std::_Callable_obj<<lambda_fdf816e424f0da55b18915c89c349fdd>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
::vfunc_3(void)

{
  return &<lambda_fdf816e424f0da55b18915c89c349fdd>::RTTI_Type_Descriptor;
}




/* std::_Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>::vfunc_3 @ 0046ea60 */

TypeDescriptor *
std::
_Func_impl<std::_Callable_obj<<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>,0>,std::allocator<std::_Func_class<void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>_>,void,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil,std::_Nil>
::vfunc_3(void)

{
  return &<lambda_ff38bf9ea15b41cb34bc5dae16af8ab3>::RTTI_Type_Descriptor;
}




/* [AUDIT] proposed: std::list<T>::_Unlink  (confidence: med)
 * purpose: Unlink one list node from doubly-linked list, decrement size
 * vars: param_1=node
 */
/* Global::std_list_Unlink @ 0046eac0 */

void std_list_Unlink(int *param_1)

{
  int *in_ECX;
  
  if (param_1 != (int *)*in_ECX) {
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    std_list_Tidy(param_1);
    in_ECX[1] = in_ECX[1] + -1;
  }
  return;
}




/* [AUDIT] proposed: std::list<T>::erase  (confidence: med)
 * purpose: Unlink and operator_delete one list node
 * vars: param_1=node
 */
/* Global::std_list_erase @ 0046eaf0 */

void std_list_erase(int *param_1)

{
  int *in_ECX;
  
  if (param_1 != (int *)*in_ECX) {
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    operator_delete(param_1);
  }
  return;
}




/* [AUDIT] proposed: std::list<std::string>::erase  (confidence: med)
 * purpose: Unlink node, free embedded std::string, delete node
 * vars: param_1=node
 */
/* Global::std_list_erase_46eb20 @ 0046eb20 */

void std_list_erase_46eb20(int *param_1)

{
  int *in_ECX;
  
  if (param_1 == (int *)*in_ECX) {
    return;
  }
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  if (7 < (uint)param_1[7]) {
    operator_delete((void *)param_1[2]);
  }
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  operator_delete(param_1);
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_13 @ 00477fa0 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_13
               (undefined4 param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  int iStack_210;
  undefined **local_20c [4];
  undefined *local_1fc [2];
  undefined **local_1f4 [2];
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> local_1ec [4];
  undefined4 *local_1e8;
  undefined4 local_1bc;
  uint local_1b8;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_1a4 [72];
  undefined4 local_15c;
  undefined4 *local_158;
  undefined4 local_154;
  int *local_150;
  int *local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 *local_13c;
  undefined4 local_138;
  undefined1 local_134 [24];
  undefined1 local_11c [24];
  undefined1 local_104 [24];
  undefined1 local_ec [24];
  undefined1 local_d4 [24];
  undefined1 local_bc [24];
  undefined1 local_a4 [24];
  undefined1 local_8c [24];
  undefined1 local_74 [24];
  undefined1 local_5c [24];
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_006e5abf;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_15c = 0;
  local_154 = param_1;
  local_150 = (int *)0x0;
  local_14c = (int *)0x0;
  local_148 = 0;
  local_8 = 0;
  local_144 = 0;
  local_140 = 0;
  local_144 = rbtree_allocHeaderNode_28(local_14);
  local_8._0_1_ = 1;
  local_13c = (undefined4 *)0x0;
  local_138 = 0;
  local_13c = (undefined4 *)object_alloc();
  local_8._0_1_ = 2;
  local_18 = 7;
  local_1c = 0;
  local_2c = (void *)((uint)local_2c._2_2_ << 0x10);
  u16string_assignPtrLen(L"@name",5);
  local_8._0_1_ = 3;
  local_158 = (undefined4 *)
              NameGen_initFirstNameTables(local_44,*(undefined4 *)(param_2 + 0x30),*(undefined4 *)(param_2 + 0x38))
  ;
  local_8 = CONCAT31(local_8._1_3_,4);
  puVar5 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (puVar5 != local_158) {
    if (7 < (uint)puVar5[5]) {
      operator_delete((void *)*puVar5);
    }
    puVar5[5] = 7;
    puVar5[4] = 0;
    *(undefined2 *)puVar5 = 0;
    u16string_move(local_158);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 2;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"creature",8);
  local_8._0_1_ = 5;
  FUN_00594c80(&local_2c,*(undefined4 *)(param_2 + 0x38),0,0,&local_144);
  local_8._0_1_ = 2;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(L"scenery");
  local_8._0_1_ = 6;
  FUN_005953a0(local_44,param_2,&local_144);
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  switch(*(undefined4 *)(param_2 + 0x34)) {
  case 1:
    u16string_assignCStr(L"objective:monster");
    local_8 = CONCAT31(local_8._1_3_,7);
    GameController_build_quest_text(local_44,&local_144,&local_150);
    break;
  case 2:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:rareboss");
    local_8 = CONCAT31(local_8._1_3_,0xe);
    GameController_build_quest_text(local_bc,&local_144,&local_150);
    break;
  case 3:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:villagemonster");
    local_8 = CONCAT31(local_8._1_3_,8);
    GameController_build_quest_text(&local_2c,&local_144,&local_150);
    break;
  case 4:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:villagerareboss");
    local_8 = CONCAT31(local_8._1_3_,0xf);
    GameController_build_quest_text(local_ec,&local_144,&local_150);
    break;
  case 5:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:dungeon");
    local_8 = CONCAT31(local_8._1_3_,0x10);
    GameController_build_quest_text(local_11c,&local_144,&local_150);
    break;
  default:
    goto switchD_004781cc_caseD_6;
  case 7:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:invasion");
    local_8 = CONCAT31(local_8._1_3_,9);
    GameController_build_quest_text(local_104,&local_144,&local_150);
    break;
  case 8:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:sceneryinvasion");
    local_8 = CONCAT31(local_8._1_3_,10);
    GameController_build_quest_text(local_5c,&local_144,&local_150);
    break;
  case 9:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:villageinvasion");
    local_8 = CONCAT31(local_8._1_3_,0xb);
    GameController_build_quest_text(local_d4,&local_144,&local_150);
    break;
  case 10:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:caveinvasion");
    local_8 = CONCAT31(local_8._1_3_,0xc);
    GameController_build_quest_text(local_74,&local_144,&local_150);
    break;
  case 0xb:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:riverinvasion");
    local_8 = CONCAT31(local_8._1_3_,0xd);
    GameController_build_quest_text(local_8c,&local_144,&local_150);
    break;
  case 0xc:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:gang");
    local_8 = CONCAT31(local_8._1_3_,0x11);
    GameController_build_quest_text(local_134,&local_144,&local_150);
    break;
  case 0xd:
    local_8._0_1_ = uVar3;
    u16string_assignCStr(L"objective:gangboss");
    local_8 = CONCAT31(local_8._1_3_,0x12);
    GameController_build_quest_text(local_a4,&local_144,&local_150);
  }
  local_8._0_1_ = 2;
  std_string_FreeMember();
switchD_004781cc_caseD_6:
  bVar8 = true;
  local_20c[0] = &PTR_006fcd00;
  local_1fc[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_1a4);
  local_8 = CONCAT31(local_8._1_3_,0x13);
  local_15c = 2;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_20c,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_1f4);
  local_8 = 0x14;
  *(undefined ***)((int)local_20c + (int)local_20c[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_210 + (int)local_20c[0][1]) = local_20c[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_1f4);
  local_1f4[0] = vftable;
  local_1bc = 0;
  local_1b8 = 0;
  local_8._0_1_ = 0x16;
  if ((local_150 != local_14c) && (piVar7 = *(int **)*local_150, piVar7 != (int *)*local_150)) {
    do {
      piVar1 = piVar7 + 2;
      iVar6 = u16string_compare(0,piVar7[6],&DAT_007020b8,1);
      if ((iVar6 == 0) ||
         ((((iVar6 = u16string_compare(0,piVar7[6],&DAT_007020bc,1), iVar6 == 0 ||
            (iVar6 = u16string_compare(0,piVar7[6],&DAT_007020c0,1), iVar6 == 0)) ||
           (iVar6 = u16string_compare(0,piVar7[6],&DAT_007020c4,1), iVar6 == 0)) ||
          ((cVar4 = wstring_equalsCI(piVar1,&DAT_007020c8), cVar4 != '\0' ||
           (cVar4 = wstring_equalsCI(piVar1,&DAT_007020cc), cVar4 != '\0')))))) {
LAB_004785f9:
        bVar2 = true;
      }
      else {
        cVar4 = wstring_equalsCI(piVar1,&DAT_00701ba8);
        bVar2 = false;
        if (cVar4 != '\0') goto LAB_004785f9;
      }
      if ((!bVar8) && (!bVar2)) {
        wostream_insertWide(local_1fc,&DAT_006fd844);
      }
      iVar6 = u16string_compare(0,piVar7[6],&DAT_007020bc,1);
      bVar8 = iVar6 == 0;
      wostream_insertU16string(local_1fc,piVar1);
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)*local_150);
  }
  u16_ostrstream_str_wrap(local_154);
  local_8._0_1_ = 2;
  *(undefined ***)((int)local_20c + (int)local_20c[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_210 + (int)local_20c[0][1]) = local_20c[0][1] + -0x68;
  local_1f4[0] = vftable;
  if ((local_1b8 & 1) != 0) {
    operator_delete((void *)*local_1e8);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_1f4,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_1f4,(wchar_t *)0x0,
             (wchar_t *)0x0);
  local_1b8 = local_1b8 & 0xfffffffe;
  local_1bc = 0;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_1f4);
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>(local_1ec);
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::~basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_1a4);
  local_8 = (uint)local_8._1_3_ << 8;
  Zone_rbtree_eraseRange(&local_154,*local_13c,local_13c);
  operator_delete(local_13c);
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_5 @ 00478800 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_5
               (undefined4 param_1,int param_2)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  undefined *puVar7;
  int iStack_584;
  undefined **local_580 [4];
  undefined *local_570 [2];
  undefined **local_568 [14];
  undefined4 local_530;
  undefined4 local_52c;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_518 [72];
  undefined4 *local_4d0;
  undefined4 *local_4c8;
  undefined1 local_4c4 [24];
  undefined1 local_4ac [24];
  undefined1 local_494 [24];
  undefined1 local_47c [24];
  undefined1 local_464 [24];
  undefined1 local_44c [24];
  undefined1 local_434 [24];
  undefined1 local_41c [24];
  undefined1 local_404 [24];
  undefined1 local_3ec [24];
  undefined1 local_3d4 [24];
  undefined1 local_3bc [24];
  undefined1 local_3a4 [24];
  undefined1 local_38c [24];
  undefined1 local_374 [24];
  undefined1 local_35c [24];
  undefined1 local_344 [24];
  undefined1 local_32c [24];
  undefined1 local_314 [24];
  undefined1 local_2fc [24];
  undefined1 local_2e4 [24];
  undefined1 local_2cc [24];
  undefined1 local_2b4 [24];
  undefined1 local_29c [24];
  undefined1 local_284 [24];
  undefined1 local_26c [24];
  undefined1 local_254 [24];
  undefined1 local_23c [24];
  undefined1 local_224 [24];
  undefined1 local_20c [24];
  undefined1 local_1f4 [24];
  undefined1 local_1dc [24];
  undefined1 local_1c4 [24];
  undefined1 local_1ac [24];
  undefined1 local_194 [24];
  undefined1 local_17c [24];
  undefined1 local_164 [24];
  undefined1 local_14c [24];
  undefined1 local_134 [24];
  undefined1 local_11c [24];
  undefined1 local_104 [24];
  undefined1 local_ec [24];
  undefined1 local_d4 [24];
  undefined1 local_bc [24];
  undefined1 local_a4 [24];
  undefined1 local_8c [24];
  undefined1 local_74 [24];
  undefined1 local_5c [24];
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e5fa2;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_4d0 = (undefined4 *)0x0;
  local_580[0] = &PTR_006fcd00;
  local_570[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_518);
  local_8 = 0;
  local_4d0 = (undefined4 *)0x1;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_580,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_568);
  local_8 = 1;
  *(undefined ***)((int)local_580 + (int)local_580[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_584 + (int)local_580[0][1]) = local_580[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_568);
  local_568[0] = vftable;
  local_530 = 0;
  local_52c = 0;
  local_8 = 3;
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,param_2);
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c._2_2_ << 0x10);
  u16string_assignPtrLen(L"@level",6);
  local_8._0_1_ = 4;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,5);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 6;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  fVar5 = (float)curve_diminishing01(param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar6 = (float)local_4c8 * 50.0f;
  if (0.0f <= fVar6) {
    fVar6 = (float)(int)(fVar6 * 100.0f + 0.5f) * 0.01f;
  }
  else {
    fVar5 = (float)math_round_to_hundredths(-fVar6);
    local_4c8 = (undefined4 *)(float)fVar5;
    fVar6 = -(float)local_4c8;
    if (fVar6 == 0.0f) {
      fVar6 = 0.0f;
    }
  }
  puVar7 = &DAT_007020e0;
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,fVar6);
  wostream_insertNarrow(pbVar1,puVar7);
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"@health",7);
  local_8._0_1_ = 7;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,8);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 9;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  fVar5 = (float)curve_diminishingP1(param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar6 = (float)local_4c8 * 100.0f;
  if (0.0f <= fVar6) {
    fVar6 = (float)(int)(fVar6 * 100.0f + 0.5f) * 0.01f;
  }
  else {
    fVar5 = (float)math_round_to_hundredths(-fVar6);
    local_4c8 = (undefined4 *)(float)fVar5;
    fVar6 = -(float)local_4c8;
    if (fVar6 == 0.0f) {
      fVar6 = 0.0f;
    }
  }
  puVar7 = &DAT_007020e0;
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,fVar6);
  wostream_insertNarrow(pbVar1,puVar7);
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"@ridingspeed",0xc);
  local_8._0_1_ = 10;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 0xc;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  fVar5 = (float)curve_diminishingN1(param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar6 = (float)local_4c8 * 100.0f;
  if (0.0f <= fVar6) {
    fVar6 = (float)(int)(fVar6 * 100.0f + 0.5f) * 0.01f;
  }
  else {
    fVar5 = (float)math_round_to_hundredths(-fVar6);
    local_4c8 = (undefined4 *)(float)fVar5;
    fVar6 = -(float)local_4c8;
    if (fVar6 == 0.0f) {
      fVar6 = 0.0f;
    }
  }
  puVar7 = &DAT_007020e0;
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,fVar6);
  wostream_insertNarrow(pbVar1,puVar7);
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"@climbingpower",0xe);
  local_8._0_1_ = 0xd;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 0xf;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  fVar5 = (float)curve_diminishingx3p15(param_2,&DAT_007020e0);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1);
  u16string_assignCStr(L"@flyingspeed");
  local_8._0_1_ = 0x10;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x12;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  fVar5 = (float)curve_diminishingHalf(param_2,&DAT_007020e0);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1);
  u16string_assignCStr(L"@swimmingspeed");
  local_8._0_1_ = 0x13;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,0x14);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x15;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  fVar5 = (float)curve_diminishingx3p1(param_2,&DAT_007020e0);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1);
  u16string_assignCStr(L"@boatspeed");
  local_8._0_1_ = 0x16;
  local_4d0 = (undefined4 *)u16_ostrstream_str_wrap(local_44);
  local_8 = CONCAT31(local_8._1_3_,0x17);
  local_4c8 = (undefined4 *)rbtree_eraseByStringKey(&local_2c);
  if (local_4c8 != local_4d0) {
    if (7 < (uint)local_4c8[5]) {
      operator_delete((void *)*local_4c8);
    }
    local_4c8[5] = 7;
    local_4c8[4] = 0;
    *(undefined2 *)local_4c8 = 0;
    u16string_move(local_4d0);
  }
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x18;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  iVar2 = ability_getManaCost(0x36,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@smashcooldown");
  local_8._0_1_ = 0x19;
  uVar3 = u16_ostrstream_str_wrap(local_44);
  local_8._0_1_ = 0x1a;
  rbtree_eraseByStringKey(&local_2c);
  u16string_moveClear(uVar3);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x1b;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  iVar2 = ability_getManaCost(0x56,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@cyclonecooldown");
  local_8._0_1_ = 0x1c;
  uVar3 = u16_ostrstream_str_wrap(local_44);
  local_8._0_1_ = 0x1d;
  rbtree_eraseByStringKey(&local_2c);
  u16string_moveClear(uVar3);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x1e;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  iVar2 = combat_getReloadFrames(0x56);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@cycloneduration");
  local_8._0_1_ = 0x1f;
  uVar3 = u16_ostrstream_str_wrap(local_44);
  local_8._0_1_ = 0x20;
  rbtree_eraseByStringKey(&local_2c);
  u16string_moveClear(uVar3);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x21;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  iVar2 = ability_getManaCost(0x65,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@bulwarkcooldown");
  local_8._0_1_ = 0x22;
  uVar3 = u16_ostrstream_str_wrap(local_44);
  local_8._0_1_ = 0x23;
  rbtree_eraseByStringKey(&local_2c);
  u16string_moveClear(uVar3);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x24;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  puVar7 = &DAT_007020e0;
  fVar5 = (float)ability_getPowerFactor(0x65,param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths(((float)local_4c8 * 0.3f + 0.25f) * 100.0f,puVar7);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1);
  u16string_assignCStr(L"@bulwarkamount");
  local_8._0_1_ = 0x25;
  uVar3 = u16_ostrstream_str_wrap(local_44);
  local_8._0_1_ = 0x26;
  rbtree_eraseByStringKey(&local_2c);
  u16string_moveClear(uVar3);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_34 = 0;
  local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x27;
  strstreambuf_tidy();
  puVar4 = &local_2c;
  if (7 < local_18) {
    puVar4 = local_2c;
  }
  strstreambuf_init(puVar4,local_1c,local_52c);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  wostream_insertWide(local_570,&DAT_00702230);
  u16string_assignCStr(L"@bulwarkduration");
  local_8._0_1_ = 0x28;
  uVar3 = u16_ostrstream_str_wrap(local_44);
  local_8._0_1_ = 0x29;
  rbtree_eraseByStringKey(&local_2c);
  u16string_moveClear(uVar3);
  if (7 < local_30) {
    operator_delete(local_44[0]);
  }
  local_30 = 7;
  local_4c8 = (undefined4 *)0x0;
  local_34 = 0;
  std_char_traits_assign(local_44,&local_4c8);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x2a;
  strstreambuf_initWrap(local_44);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x66,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@warfrenzycooldown");
  local_8._0_1_ = 0x2b;
  uVar3 = u16_ostrstream_str_wrap(&local_2c);
  local_8._0_1_ = 0x2c;
  rbtree_eraseByStringKey(local_44);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x2d;
  strstreambuf_initWrap(local_44);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_570,&DAT_00702230);
  u16string_assignCStr(L"@warfrenzyduration");
  local_8._0_1_ = 0x2e;
  uVar3 = u16_ostrstream_str_wrap(&local_2c);
  local_8._0_1_ = 0x2f;
  rbtree_eraseByStringKey(local_44);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x30;
  strstreambuf_initWrap(local_8c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar7 = &DAT_007020e0;
  fVar5 = (float)ability_getPowerFactor(0x66,param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths(((float)local_4c8 * 9.0f + 1.0f) * 100.0f,puVar7);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1);
  u16string_assignCStr(L"@warfrenzyamount");
  local_8._0_1_ = 0x31;
  uVar3 = u16_ostrstream_str_wrap(local_8c);
  local_8._0_1_ = 0x32;
  rbtree_eraseByStringKey(local_2e4);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x33;
  strstreambuf_initWrap(local_20c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x15,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@rangerkickcooldown");
  local_8._0_1_ = 0x34;
  uVar3 = u16_ostrstream_str_wrap(local_20c);
  local_8._0_1_ = 0x35;
  rbtree_eraseByStringKey(local_2fc);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x36;
  strstreambuf_initWrap(local_bc);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)curve_diminishing01(param_2,&DAT_006fd728);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertWide(pbVar1);
  u16string_assignCStr(L"@rangerkickknockback");
  local_8._0_1_ = 0x37;
  uVar3 = u16_ostrstream_str_wrap(local_bc);
  local_8._0_1_ = 0x38;
  rbtree_eraseByStringKey(local_3bc);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x39;
  strstreambuf_initWrap(local_1ac);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x32,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@retreatcooldown");
  local_8._0_1_ = 0x3a;
  uVar3 = u16_ostrstream_str_wrap(local_1ac);
  local_8._0_1_ = 0x3b;
  rbtree_eraseByStringKey(local_3d4);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x3c;
  strstreambuf_initWrap(local_ec);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)curve_diminishing01(param_2,&DAT_006fd728);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertWide(pbVar1);
  u16string_assignCStr(L"@retreatdistance");
  local_8._0_1_ = 0x3d;
  uVar3 = u16_ostrstream_str_wrap(local_ec);
  local_8._0_1_ = 0x3e;
  rbtree_eraseByStringKey(local_2cc);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x3f;
  strstreambuf_initWrap(local_26c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(99,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@aimcooldown");
  local_8._0_1_ = 0x40;
  uVar3 = u16_ostrstream_str_wrap(local_26c);
  local_8._0_1_ = 0x41;
  rbtree_eraseByStringKey(local_32c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x42;
  strstreambuf_initWrap(local_11c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)curve_diminishing01(param_2,&DAT_006fd728);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertWide(pbVar1);
  u16string_assignCStr(L"@aimstealth");
  local_8._0_1_ = 0x43;
  uVar3 = u16_ostrstream_str_wrap(local_11c);
  local_8._0_1_ = 0x44;
  rbtree_eraseByStringKey(local_38c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x45;
  strstreambuf_initWrap(local_1dc);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(100,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@swiftnesscooldown");
  local_8._0_1_ = 0x46;
  uVar3 = u16_ostrstream_str_wrap(local_1dc);
  local_8._0_1_ = 0x47;
  rbtree_eraseByStringKey(local_3ec);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x48;
  strstreambuf_initWrap(local_14c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)curve_diminishing01(param_2,&DAT_006fd728);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertWide(pbVar1);
  u16string_assignCStr(L"@swiftnessamount");
  local_8._0_1_ = 0x49;
  uVar3 = u16_ostrstream_str_wrap(local_14c);
  local_8._0_1_ = 0x4a;
  rbtree_eraseByStringKey(local_344);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x4b;
  strstreambuf_initWrap(local_5c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_570,&DAT_00702230);
  u16string_assignCStr(L"@swiftnessduration");
  local_8._0_1_ = 0x4c;
  uVar3 = u16_ostrstream_str_wrap(local_5c);
  local_8._0_1_ = 0x4d;
  rbtree_eraseByStringKey(local_434);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x4e;
  strstreambuf_initWrap(local_17c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x58,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@fireexplosioncooldown");
  local_8._0_1_ = 0x4f;
  uVar3 = u16_ostrstream_str_wrap(local_17c);
  local_8._0_1_ = 0x50;
  rbtree_eraseByStringKey(local_29c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x51;
  strstreambuf_initWrap(local_74);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)curve_diminishing01(param_2,&DAT_006fd728);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertWide(pbVar1);
  u16string_assignCStr(L"@fireexplosionknockback");
  local_8._0_1_ = 0x52;
  uVar3 = u16_ostrstream_str_wrap(local_74);
  local_8._0_1_ = 0x53;
  rbtree_eraseByStringKey(local_47c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x54;
  strstreambuf_initWrap(local_a4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_570,&DAT_00702474);
  u16string_assignCStr(L"@manashieldduration");
  local_8._0_1_ = 0x55;
  uVar3 = u16_ostrstream_str_wrap(local_a4);
  local_8._0_1_ = 0x56;
  rbtree_eraseByStringKey(local_41c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x57;
  strstreambuf_initWrap(local_d4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x67,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@manashieldcooldown");
  local_8._0_1_ = 0x58;
  uVar3 = u16_ostrstream_str_wrap(local_d4);
  local_8._0_1_ = 0x59;
  rbtree_eraseByStringKey(local_35c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x5a;
  strstreambuf_initWrap(local_104);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)ability_getPowerFactor(0x67,param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertWide(pbVar1);
  u16string_assignCStr(L"@manashieldpower");
  local_8._0_1_ = 0x5b;
  uVar3 = u16_ostrstream_str_wrap(local_104);
  local_8._0_1_ = 0x5c;
  rbtree_eraseByStringKey(local_374);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x5d;
  strstreambuf_initWrap(local_134);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x31,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@teleportcooldown");
  local_8._0_1_ = 0x5e;
  uVar3 = u16_ostrstream_str_wrap(local_134);
  local_8._0_1_ = 0x5f;
  rbtree_eraseByStringKey(local_44c);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x60;
  strstreambuf_initWrap(local_164);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)ability_getResourceCost(0x22,param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f * 8.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@healingstreamcost");
  local_8._0_1_ = 0x61;
  uVar3 = u16_ostrstream_str_wrap(local_164);
  local_8._0_1_ = 0x62;
  rbtree_eraseByStringKey(local_4c4);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 99;
  strstreambuf_initWrap(local_194);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x30,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@interceptcooldown");
  local_8._0_1_ = 100;
  uVar3 = u16_ostrstream_str_wrap(local_194);
  local_8._0_1_ = 0x65;
  rbtree_eraseByStringKey(local_2b4);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x66;
  strstreambuf_initWrap(local_1c4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x60,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@shurikencooldown");
  local_8._0_1_ = 0x67;
  uVar3 = u16_ostrstream_str_wrap(local_1c4);
  local_8._0_1_ = 0x68;
  rbtree_eraseByStringKey(local_314);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x69;
  strstreambuf_initWrap(local_1f4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x61,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@camouflagecooldown");
  local_8._0_1_ = 0x6a;
  uVar3 = u16_ostrstream_str_wrap(local_1f4);
  local_8._0_1_ = 0x6b;
  rbtree_eraseByStringKey(local_3a4);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x6c;
  strstreambuf_initWrap(local_224);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  fVar5 = (float)ability_getPowerFactor(0x61,0xffffffff);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths(((float)local_4c8 * 12000.0f + 8000.0f) / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@camouflageduration");
  local_8._0_1_ = 0x6d;
  uVar3 = u16_ostrstream_str_wrap(local_224);
  local_8._0_1_ = 0x6e;
  rbtree_eraseByStringKey(local_404);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x6f;
  strstreambuf_initWrap(local_254);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  iVar2 = ability_getManaCost(0x4f,param_2);
  fVar5 = (float)math_round_to_hundredths((float)iVar2 / 1000.0f);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  u16string_assignCStr(L"@sneakcooldown");
  local_8._0_1_ = 0x70;
  uVar3 = u16_ostrstream_str_wrap(local_254);
  local_8._0_1_ = 0x71;
  rbtree_eraseByStringKey(local_464);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x72;
  strstreambuf_initWrap(local_284);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar7 = &DAT_007020e0;
  fVar5 = (float)ability_getPowerFactor(0x4f,param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 0.4f * 100.0f);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1,puVar7);
  u16string_assignCStr(L"@sneakspeed");
  local_8._0_1_ = 0x73;
  uVar3 = u16_ostrstream_str_wrap(local_284);
  local_8._0_1_ = 0x74;
  rbtree_eraseByStringKey(local_4ac);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x75;
  strstreambuf_initWrap(local_23c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar7 = &DAT_007020e0;
  fVar5 = (float)ability_getPowerFactor(0x4f,param_2);
  local_4c8 = (undefined4 *)(float)fVar5;
  fVar5 = (float)math_round_to_hundredths((float)local_4c8 * 100.0f,puVar7);
  pbVar1 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_570,(float)fVar5);
  wostream_insertNarrow(pbVar1);
  u16string_assignCStr(L"@sneakstealth");
  local_8._0_1_ = 0x76;
  uVar3 = u16_ostrstream_str_wrap(local_23c);
  local_8 = CONCAT31(local_8._1_3_,0x77);
  rbtree_eraseByStringKey(local_494);
  u16string_moveClear(uVar3);
  std_string_FreeMember();
  std_string_FreeMember();
  ctor_18();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: GameController::validate_selected_zone  (confidence: low)
 * purpose: Check selected world/zone/region indices are valid (game)
 * vars: in_ECX=GameController
 */
/* Global::GameController_validate_selected_zone @ 0047f940 */

void GameController_validate_selected_zone(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(*(int *)(in_ECX + 0x8008c4) + 0x3c);
  if (*(int *)(*(int *)(iVar2 + 0x94) + *(int *)(iVar2 + 0x68) * 4) != 0) {
    piVar1 = (int *)getSelectedSlotCoords(local_20);
    if (-1 < *piVar1) {
      iVar2 = getSelectedSlotCoords(local_10);
      if (-1 < *(int *)(iVar2 + 4)) {
        iVar2 = getSelectedSlotCoords(local_18);
        piVar1 = (int *)getSelectedSlotCoords(local_28);
        if (*(int *)(*(int *)(iVar2 + 4) * 0x11c +
                    *(int *)(*(int *)(*(int *)(in_ECX + 0x8006d0) + 0x11dc) + *piVar1 * 0xc)) != 0)
        {
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_9 @ 004806c0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_9
               (int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int iStack_110;
  undefined **local_10c [4];
  undefined *local_fc [2];
  undefined **local_f4 [2];
  basic_iostream<char,std::char_traits<char>_> local_ec [48];
  undefined4 local_bc;
  undefined4 local_b8;
  code *local_a4 [18];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char local_2d;
  void *local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e6190;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = 0;
  enter_critical_section(local_14);
  local_50 = *(undefined4 *)(param_2 + 0x10);
  local_58 = *(undefined4 *)(param_2 + 0x14);
  local_4c = *(undefined4 *)(param_2 + 0x18);
  local_44 = *(undefined4 *)(param_2 + 0x1c);
  local_54 = *(undefined4 *)(param_2 + 0x20);
  local_48 = *(undefined4 *)(param_2 + 0x24);
  local_10c[0] = &PTR_006fcd00;
  local_fc[0] = &DAT_006fcd08;
  local_a4[0] = _vftable__exref;
  local_8 = 0;
  local_5c = 1;
  std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
            ((basic_iostream<char,std::char_traits<char>_> *)local_10c,
             (basic_streambuf<char,std::char_traits<char>_> *)local_f4);
  local_8 = 1;
  *(undefined ***)((int)local_10c + (int)local_10c[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_110 + (int)local_10c[0][1]) = local_10c[0][1] + -0x68;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_f4);
  local_f4[0] = vftable;
  local_bc = 0;
  local_b8 = 0;
  local_8 = 3;
  std::basic_ostream<char,std::char_traits<char>_>::operator<<
            ((basic_ostream<char,std::char_traits<char>_> *)local_fc,param_1);
  local_40 = (void *)0x0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_8._0_1_ = 4;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8005b8));
  uVar1 = ostrstream_str_wrap(local_2c);
  local_8._0_1_ = 5;
  local_2d = db_getBlobInto(uVar1,&local_40);
  local_8 = CONCAT31(local_8._1_3_,4);
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  if (local_2d != '\0') {
    obj_init_and_inflate();
    iVar2 = param_2;
    refcount_initTo1(&local_40);
    cube::Creature::deserializeState(iVar2);
    *(undefined4 *)(param_2 + 0x10) = local_50;
    *(undefined4 *)(param_2 + 0x14) = local_58;
    *(undefined4 *)(param_2 + 0x18) = local_4c;
    *(undefined4 *)(param_2 + 0x1c) = local_44;
    *(undefined4 *)(param_2 + 0x20) = local_54;
    *(undefined4 *)(param_2 + 0x24) = local_48;
    *(undefined4 *)(param_2 + 0x1350) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_2 + 0x1354) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_2 + 0x1358) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_2 + 0x135c) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_2 + 0x1360) = *(undefined4 *)(param_2 + 0x20);
    *(undefined4 *)(param_2 + 0x1364) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(param_2 + 0x1d40) = *(undefined4 *)(param_2 + 0x194);
    *(undefined4 *)(param_2 + 0x1d3c) = *(undefined4 *)(param_2 + 400);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8005b8));
  leave_critical_section();
  if (local_40 != (void *)0x0) {
    operator_delete(local_40);
  }
  *(undefined ***)((int)local_10c + (int)local_10c[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_110 + (int)local_10c[0][1]) = local_10c[0][1] + -0x68;
  local_f4[0] = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_f4);
  std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
            (local_ec);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)local_a4);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_8 @ 00480fb0 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_8
               (char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  basic_ostream<wchar_t,std::char_traits<wchar_t>_> *this;
  int in_ECX;
  undefined4 uStack_174;
  void **ppvStack_170;
  undefined4 uStack_16c;
  void *pvVar5;
  int iStack_14c;
  undefined **local_148 [4];
  undefined *local_138 [2];
  undefined **local_130 [2];
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> local_128 [48];
  undefined4 local_f8;
  undefined4 local_f4;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_e0 [72];
  undefined1 *local_98;
  undefined4 local_94;
  undefined4 local_84;
  uint local_80;
  void *local_7c;
  undefined4 local_6c;
  uint local_68;
  void *local_64 [4];
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e6344;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_98 = (undefined1 *)0x0;
  if (param_2 == *(int *)(in_ECX + 0x8006d0)) {
    u16string_assignCStr();
    local_8 = 0;
    local_3c = 0x3f800000;
    local_38 = 0x3f800000;
    local_34 = 0x3f800000;
    local_30 = 0x3f800000;
    text_drawColoredString();
    pvVar5 = local_2c[0];
    if (local_18 < 8) {
LAB_0048114f:
      local_8 = 0xffffffff;
      local_148[0] = &PTR_006fcd00;
      local_138[0] = &DAT_006fcd08;
      std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
      basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_e0);
      local_8 = 4;
      local_98 = (undefined1 *)0x1;
      std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
      basic_iostream<wchar_t,std::char_traits<wchar_t>_>
                ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_148,
                 (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_130);
      local_8 = 5;
      *(undefined ***)((int)local_148 + (int)local_148[0][1]) =
           basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
      *(undefined **)((int)&iStack_14c + (int)local_148[0][1]) = local_148[0][1] + -0x68;
      std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
      basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_130);
      local_130[0] = vftable;
      local_f8 = 0;
      local_f4 = 0;
      cVar1 = *param_1;
      local_8 = 7;
      if (cVar1 == '\f') {
        local_98 = (undefined1 *)&uStack_174;
        u16string_assignCStr(L"singular");
        local_8._0_1_ = 8;
        uVar3 = FUN_0059ff60(local_64,param_1[0xd]);
        local_8._0_1_ = 10;
        lookupNestedStringMap(local_2c,uVar3);
        local_8._0_1_ = 0xb;
        uStack_16c = 0x48125e;
        std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                  ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_138,
                   *(short *)(param_1 + 0x10));
        uStack_16c = 0x481264;
        wostream_insertNarrow();
        wostream_insertU16string();
        if (7 < local_18) {
          operator_delete(local_2c[0]);
        }
        local_18 = 7;
        local_1c = 0;
        local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
        local_8._0_1_ = 7;
        if (7 < local_50) {
          operator_delete(local_64[0]);
        }
        u16_ostrstream_str_wrap();
        local_8._0_1_ = 0xc;
        local_3c = 0x3f800000;
        local_38 = 0x3f800000;
        local_34 = 0x3f800000;
        local_30 = 0x3f800000;
      }
      else {
        if (((((cVar1 == '\r') || (cVar1 == '\x15')) || ((cVar1 == '\v' && (param_1[1] != '\x0e'))))
            || (((cVar1 == '\0' || (cVar1 == '\x19')) || (cVar1 == '\x14')))) ||
           ((cVar1 == '\x18' || (cVar1 == '\x17')))) {
          std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                    ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_138,
                     *(short *)(param_1 + 0x10));
          wostream_insertWide();
        }
        ctor_6();
        local_8._0_1_ = 0xd;
        wostream_insertU16string();
        local_8._0_1_ = 7;
        if (7 < local_18) {
          operator_delete(local_2c[0]);
        }
        cVar1 = *param_1;
        if ((((cVar1 != '\f') && (cVar1 != '\r')) &&
            ((cVar1 != '\x15' &&
             ((((cVar1 != '\v' || (param_1[1] == '\x0e')) && (cVar1 != '\0')) &&
              ((cVar1 != '\x19' && (cVar1 != '\x14')))))))) &&
           ((cVar1 != '\x18' && (cVar1 != '\x17')))) {
          iVar4 = item_rarityScaled();
          uStack_16c = 0x4813a6;
          this = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)wostream_insertWide();
          std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(this,iVar4);
        }
        u16_ostrstream_str_wrap();
        local_8._0_1_ = 0xe;
        Item_get_type_color();
      }
      text_drawColoredString();
      local_8._0_1_ = 7;
      if (7 < local_18) {
        operator_delete(local_2c[0]);
      }
      local_80 = 7;
      local_84 = 0;
      local_94 = (void *)((uint)local_94._2_2_ << 0x10);
      u16string_assignPtrLen();
      local_8 = CONCAT31(local_8._1_3_,0xf);
      local_4c = 0x3f800000;
      local_48 = 0x3f800000;
      local_44 = 0x3f800000;
      local_40 = 0x3f800000;
      text_drawColoredString();
      if (7 < local_80) {
        operator_delete(local_94);
      }
      *(undefined ***)((int)local_148 + (int)local_148[0][1]) =
           basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
      *(undefined **)((int)&iStack_14c + (int)local_148[0][1]) = local_148[0][1] + -0x68;
      local_130[0] = vftable;
      strstreambuf_tidy();
      std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
      ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_130);
      std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
      ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>(local_128);
      std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
      ~basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_e0);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    local_68 = 0xf;
    cVar1 = *(char *)(param_2 + 0x1168);
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    pcVar2 = (char *)(param_2 + 0x1168);
    while (cVar1 != '\0') {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    }
    string_assignPtrLen();
    local_8 = 1;
    uStack_16c = copy_two_words();
    ppvStack_170 = local_64;
    local_8._0_1_ = 2;
    uStack_174 = 0x4810ba;
    wstring_assign();
    local_8 = CONCAT31(local_8._1_3_,3);
    local_3c = 0x3f800000;
    local_38 = 0x3f800000;
    local_34 = 0x3f800000;
    local_30 = 0x3f800000;
    text_drawColoredString();
    if (7 < local_50) {
      operator_delete(local_64[0]);
    }
    local_50 = 7;
    local_54 = 0;
    local_64[0] = (void *)((uint)local_64[0] & 0xffff0000);
    if (7 < local_18) {
      operator_delete(local_2c[0]);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
    pvVar5 = local_7c;
    if (local_68 < 0x10) goto LAB_0048114f;
  }
  local_8 = 0xffffffff;
  operator_delete(pvVar5);
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_7 @ 004816f0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_7(void)

{
  void *_Src;
  void *_Dst;
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iStack_278;
  undefined **local_274 [4];
  undefined *local_264 [2];
  undefined **local_25c [2];
  basic_iostream<char,std::char_traits<char>_> local_254 [4];
  undefined4 *local_250;
  undefined4 *local_24c;
  undefined4 *local_23c;
  undefined4 *local_22c;
  undefined4 local_224;
  uint local_220;
  basic_ios<char,std::char_traits<char>_> local_20c [68];
  int iStack_1c8;
  undefined **local_1c4 [4];
  undefined *local_1b4 [2];
  undefined **local_1ac [2];
  basic_iostream<char,std::char_traits<char>_> local_1a4 [4];
  undefined4 *local_1a0;
  undefined4 *local_19c;
  undefined4 *local_18c;
  undefined4 *local_17c;
  undefined4 local_174;
  uint local_170;
  basic_ios<char,std::char_traits<char>_> local_15c [68];
  int iStack_118;
  undefined **local_114 [4];
  undefined *local_104 [2];
  undefined **local_fc [2];
  basic_iostream<char,std::char_traits<char>_> local_f4 [4];
  undefined4 *local_f0;
  undefined4 *local_ec;
  undefined4 *local_dc;
  undefined4 *local_cc;
  undefined4 local_c4;
  uint local_c0;
  basic_ios<char,std::char_traits<char>_> local_ac [72];
  int local_64;
  int local_60;
  void *local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  uint local_48;
  void *local_44 [5];
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e6498;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48 = 0;
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x800984) + *(int *)(in_ECX + 0x800a0c) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1,local_14);
  }
  _Dst = (void *)(*(int *)(in_ECX + 0x800984) + *(int *)(in_ECX + 0x800a0c) * 4);
  _Src = (void *)((int)_Dst + 4);
  memmove(_Dst,_Src,*(int *)(in_ECX + 0x800988) - (int)_Src & 0xfffffffc);
  *(int *)(in_ECX + 0x800988) = *(int *)(in_ECX + 0x800988) + -4;
  local_58 = (void *)0x0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_8 = 0;
  iVar5 = *(int *)(in_ECX + 0x800988) - *(int *)(in_ECX + 0x800984) >> 2;
  Vector_Resize(4);
  *(int *)((int)local_58 + local_4c) = iVar5;
  local_4c = local_4c + 4;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
  string_assignPtrLen(&DAT_00700e68,3);
  local_64 = in_ECX + 0x1001008;
  local_8._0_1_ = 1;
  db_storeBlobVec(local_2c,&local_58);
  local_8._0_1_ = 0;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  local_274[0] = &PTR_006fcd00;
  local_264[0] = &DAT_006fcd08;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_20c);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_48 = 1;
  std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
            ((basic_iostream<char,std::char_traits<char>_> *)local_274,
             (basic_streambuf<char,std::char_traits<char>_> *)local_25c);
  local_8 = 3;
  *(undefined ***)((int)local_274 + (int)local_274[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_278 + (int)local_274[0][1]) = local_274[0][1] + -0x68;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_25c);
  local_25c[0] = vftable;
  local_224 = 0;
  local_220 = 0;
  local_8._0_1_ = 5;
  std::basic_ostream<char,std::char_traits<char>_>::operator<<
            ((basic_ostream<char,std::char_traits<char>_> *)local_264,*(int *)(in_ECX + 0x800a0c));
  uVar3 = ostrstream_str_wrap(local_2c);
  local_8._0_1_ = 6;
  db_delete_blob(uVar3);
  local_8._0_1_ = 5;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 5;
  if (0xf < local_18) {
    operator_delete(local_2c[0]);
  }
  iVar5 = iVar5 + 1;
  if (*(int *)(in_ECX + 0x800a0c) < iVar5) {
    uVar7 = 1;
    iVar6 = *(int *)(in_ECX + 0x800a0c);
    do {
      local_1c4[0] = &PTR_006fcd00;
      local_1b4[0] = &DAT_006fcd08;
      std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
                (local_15c);
      local_48 = uVar7 | 2;
      local_8 = CONCAT31(local_8._1_3_,7);
      std::basic_iostream<char,std::char_traits<char>_>::
      basic_iostream<char,std::char_traits<char>_>
                ((basic_iostream<char,std::char_traits<char>_> *)local_1c4,
                 (basic_streambuf<char,std::char_traits<char>_> *)local_1ac);
      local_8 = 8;
      *(undefined ***)((int)local_1c4 + (int)local_1c4[0][1]) =
           basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(undefined **)((int)&iStack_1c8 + (int)local_1c4[0][1]) = local_1c4[0][1] + -0x68;
      std::basic_streambuf<char,std::char_traits<char>_>::
      basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)local_1ac);
      local_1ac[0] = vftable;
      local_174 = 0;
      local_170 = 0;
      local_60 = iVar6 + 1;
      local_8._0_1_ = 10;
      std::basic_ostream<char,std::char_traits<char>_>::operator<<
                ((basic_ostream<char,std::char_traits<char>_> *)local_1b4,local_60);
      local_114[0] = &PTR_006fcd00;
      local_104[0] = &DAT_006fcd08;
      std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
                (local_ac);
      uVar7 = uVar7 | 6;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      local_48 = uVar7;
      std::basic_iostream<char,std::char_traits<char>_>::
      basic_iostream<char,std::char_traits<char>_>
                ((basic_iostream<char,std::char_traits<char>_> *)local_114,
                 (basic_streambuf<char,std::char_traits<char>_> *)local_fc);
      local_8 = 0xc;
      *(undefined ***)((int)local_114 + (int)local_114[0][1]) =
           basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(undefined **)((int)&iStack_118 + (int)local_114[0][1]) = local_114[0][1] + -0x68;
      std::basic_streambuf<char,std::char_traits<char>_>::
      basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)local_fc);
      local_fc[0] = vftable;
      local_c4 = 0;
      local_c0 = 0;
      local_8._0_1_ = 0xe;
      std::basic_ostream<char,std::char_traits<char>_>::operator<<
                ((basic_ostream<char,std::char_traits<char>_> *)local_104,iVar6);
      uVar3 = ostrstream_str_wrap(local_44);
      local_8._0_1_ = 0xf;
      uVar4 = ostrstream_str_wrap(local_2c);
      local_8._0_1_ = 0x10;
      db_update_blob_key(uVar4,uVar3);
      if (0xf < local_18) {
        operator_delete(local_2c[0]);
      }
      local_18 = 0xf;
      local_1c = 0;
      local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
      if (0xf < local_30) {
        operator_delete(local_44[0]);
      }
      local_8._0_1_ = 10;
      *(undefined ***)((int)local_114 + (int)local_114[0][1]) =
           basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(undefined **)((int)&iStack_118 + (int)local_114[0][1]) = local_114[0][1] + -0x68;
      local_fc[0] = vftable;
      if ((local_c0 & 1) != 0) {
        operator_delete((void *)*local_f0);
      }
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)local_fc,(char *)0x0,(char *)0x0,
                 (char *)0x0);
      *local_ec = 0;
      *local_dc = 0;
      *local_cc = 0;
      local_c0 = local_c0 & 0xfffffffe;
      local_c4 = 0;
      std::basic_streambuf<char,std::char_traits<char>_>::
      ~basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)local_fc);
      std::basic_iostream<char,std::char_traits<char>_>::
      ~basic_iostream<char,std::char_traits<char>_>(local_f4);
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_ac);
      local_8._0_1_ = 5;
      *(undefined ***)((int)local_1c4 + (int)local_1c4[0][1]) =
           basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(undefined **)((int)&iStack_1c8 + (int)local_1c4[0][1]) = local_1c4[0][1] + -0x68;
      local_1ac[0] = vftable;
      if ((local_170 & 1) != 0) {
        operator_delete((void *)*local_1a0);
      }
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)local_1ac,(char *)0x0,(char *)0x0,
                 (char *)0x0);
      *local_19c = 0;
      *local_18c = 0;
      *local_17c = 0;
      local_170 = local_170 & 0xfffffffe;
      local_174 = 0;
      std::basic_streambuf<char,std::char_traits<char>_>::
      ~basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)local_1ac);
      std::basic_iostream<char,std::char_traits<char>_>::
      ~basic_iostream<char,std::char_traits<char>_>(local_1a4);
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_15c);
      iVar6 = local_60;
      uVar2 = (undefined1)local_8;
    } while (local_60 < iVar5);
  }
  local_8._0_1_ = uVar2;
  GameController_buildCharacterList();
  local_8 = (uint)local_8._1_3_ << 8;
  *(undefined ***)((int)local_274 + (int)local_274[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_278 + (int)local_274[0][1]) = local_274[0][1] + -0x68;
  local_25c[0] = vftable;
  if ((local_220 & 1) != 0) {
    operator_delete((void *)*local_250);
  }
  std::basic_streambuf<char,std::char_traits<char>_>::setg
            ((basic_streambuf<char,std::char_traits<char>_> *)local_25c,(char *)0x0,(char *)0x0,
             (char *)0x0);
  *local_24c = 0;
  *local_23c = 0;
  *local_22c = 0;
  local_220 = local_220 & 0xfffffffe;
  local_224 = 0;
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_25c);
  std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
            (local_254);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_20c);
  if (local_58 == (void *)0x0) {
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  operator_delete(local_58);
}




/* [AUDIT] proposed: std::list<T>::pop_back  (confidence: med)
 * purpose: Unlink and delete node before head (pop back)
 * vars: in_ECX=list
 */
/* Global::std_list_pop_back @ 00486050 */

void std_list_pop_back(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)((int *)*in_ECX)[1];
  if (piVar1 != (int *)*in_ECX) {
    *(int *)piVar1[1] = *piVar1;
    *(int *)(*piVar1 + 4) = piVar1[1];
    operator_delete(piVar1);
  }
  return;
}




/* Global::eh_catchall_00487179 @ 00487179 */

void Catch_All_00487179(void)

{
  int unaff_EBP;
  int iVar1;
  
  for (iVar1 = *(int *)(unaff_EBP + 8); iVar1 != 0; iVar1 = iVar1 + -1) {
    std_list_pop_back();
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00487363 @ 00487363 */

void Catch_All_00487363(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00487470 @ 00487470 */

void Catch_All_00487470(void)

{
  FUN_0063de60();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: GameController::load_skill_tooltip  (confidence: low)
 * purpose: Load skill description/level text from resource1.dat (game UI)
 * vars: param_1=skill id
 */
/* Global::GameController_load_skill_tooltip @ 004a5710 */

void GameController_load_skill_tooltip(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  float fVar8;
  int *local_258;
  int *local_254;
  undefined4 local_250;
  int local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 *local_240;
  undefined4 local_23c;
  int local_238;
  char local_232;
  char local_231;
  int local_230;
  undefined1 local_22c [64];
  undefined1 local_1ec [24];
  undefined1 local_1d4 [24];
  undefined1 local_1bc [24];
  undefined1 local_1a4 [24];
  undefined1 local_18c [24];
  undefined1 local_174 [24];
  undefined1 local_15c [24];
  undefined1 local_144 [24];
  undefined1 local_12c [24];
  undefined1 local_114 [24];
  undefined1 local_fc [24];
  undefined1 local_e4 [24];
  float local_cc [2];
  float local_c4 [2];
  undefined1 local_bc [8];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_a4 [8];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8c [8];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  void *local_74 [4];
  undefined4 local_64;
  uint local_60;
  void *local_5c [2];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_34;
  uint local_30;
  void *local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e7da1;
  local_10 = ExceptionList;
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_60 = 7;
  local_64 = 0;
  local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
  local_24c = in_ECX;
  local_14 = uVar3;
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8 = 0;
  iVar4 = FontCache_find_or_create_scalable(local_74);
  local_8 = 0xffffffff;
  if (7 < local_60) {
    operator_delete(local_74[0]);
  }
  local_60 = 7;
  local_64 = 0;
  local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
  if (iVar4 == 0) {
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_258 = (int *)0x0;
  local_254 = (int *)0x0;
  local_250 = 0;
  local_8 = 1;
  local_248 = 0;
  local_244 = 0;
  local_248 = rbtree_allocHeaderNode_28(uVar3);
  local_8._0_1_ = 2;
  local_240 = (undefined4 *)0x0;
  local_23c = 0;
  local_240 = (undefined4 *)object_alloc();
  local_30 = 7;
  local_34 = 0;
  local_44 = (void *)((uint)local_44._2_2_ << 0x10);
  local_8._0_1_ = 4;
  if (param_1 == 6) {
    switch(*(undefined1 *)(*(int *)(in_ECX + 0x8006d0) + 0x140)) {
    case 1:
      uVar5 = lib_fn_594bf0(local_18c,0x36);
      u16string_moveClear(uVar5);
      break;
    case 2:
      uVar5 = lib_fn_594bf0(local_1bc,0x15);
      u16string_moveClear(uVar5);
      break;
    case 3:
      if (*(int *)(*(int *)(in_ECX + 0x80090c) + 0x18c) == 1) {
        uVar5 = lib_fn_594bf0(local_1ec,0x22);
        u16string_moveClear(uVar5);
      }
      else {
        uVar5 = lib_fn_594bf0(local_1d4,0x58);
        u16string_moveClear(uVar5);
      }
      break;
    case 4:
      uVar5 = lib_fn_594bf0(local_12c,0x30);
      u16string_moveClear(uVar5);
      break;
    default:
      goto switchD_004a5897_default;
    }
  }
  else if (param_1 == 7) {
    switch(*(undefined1 *)(*(int *)(in_ECX + 0x8006d0) + 0x140)) {
    case 1:
      uVar5 = lib_fn_594bf0(local_174,0x56);
      u16string_moveClear(uVar5);
      break;
    case 2:
      uVar5 = lib_fn_594bf0(local_114,0x32);
      u16string_moveClear(uVar5);
      break;
    case 3:
      uVar5 = lib_fn_594bf0(local_fc,0x67);
      u16string_moveClear(uVar5);
      break;
    case 4:
      uVar5 = lib_fn_594bf0(local_15c,0x4f);
      u16string_moveClear(uVar5);
      break;
    default:
      goto switchD_004a5897_default;
    }
  }
  else {
    if (param_1 != 8) {
      uVar5 = lib_fn_5a5a60(local_2c,param_1);
      u16string_moveClear(uVar5);
      if (7 < local_18) {
        operator_delete(local_2c[0]);
      }
      goto switchD_004a5897_default;
    }
    switch(*(undefined1 *)(*(int *)(in_ECX + 0x8006d0) + 0x140)) {
    case 1:
      if (*(int *)(*(int *)(in_ECX + 0x80090c) + 0x18c) == 0) {
        uVar5 = lib_fn_594bf0(local_5c,0x66);
        u16string_moveClear(uVar5);
      }
      else {
        uVar5 = lib_fn_594bf0(local_a4,0x65);
        u16string_moveClear(uVar5);
      }
      break;
    case 2:
      if (*(int *)(*(int *)(in_ECX + 0x80090c) + 0x18c) == 1) {
        uVar5 = lib_fn_594bf0(local_bc,100);
        u16string_moveClear(uVar5);
      }
      else {
        uVar5 = lib_fn_594bf0(local_8c,99);
        u16string_moveClear(uVar5);
      }
      break;
    case 3:
      uVar5 = lib_fn_594bf0(local_e4,0x31);
      u16string_moveClear(uVar5);
      break;
    case 4:
      if (*(int *)(*(int *)(in_ECX + 0x80090c) + 0x18c) == 1) {
        uVar5 = lib_fn_594bf0(local_144,0x60);
        u16string_moveClear(uVar5);
      }
      else {
        uVar5 = lib_fn_594bf0(local_1a4,0x61);
        u16string_moveClear(uVar5);
      }
      break;
    default:
      goto switchD_004a5897_default;
    }
  }
  std_string_FreeMember();
switchD_004a5897_default:
  std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_5
            (param_1,param_2,&local_248);
  uVar5 = u16string_assignCStr(L"description:");
  local_8._0_1_ = 5;
  uVar5 = string_assign(local_2c,uVar5,&local_44);
  local_8._0_1_ = 6;
  GameController_build_quest_text(uVar5,&local_248,&local_258);
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  local_8._0_1_ = 4;
  if (7 < local_48) {
    operator_delete(local_5c[0]);
  }
  if (0 < param_2) {
    u16string_assignCStr(L"skill:level");
    local_8._0_1_ = 7;
    GameController_build_quest_text(local_2c,&local_248,&local_258);
    local_8._0_1_ = 4;
    if (7 < local_18) {
      operator_delete(local_2c[0]);
    }
    uVar5 = u16string_assignCStr(L"details:");
    local_8._0_1_ = 8;
    uVar5 = string_assign(local_2c,uVar5,&local_44);
    local_8._0_1_ = 9;
    GameController_build_quest_text(uVar5,&local_248,&local_258);
    if (7 < local_18) {
      operator_delete(local_2c[0]);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
    local_8._0_1_ = 4;
    if (7 < local_48) {
      operator_delete(local_5c[0]);
    }
  }
  local_8._0_1_ = 4;
  local_18 = 7;
  local_1c = 0;
  std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_5
            (param_1,param_2 + 1,&local_248);
  u16string_assignCStr(L"skill:nextlevel");
  local_8._0_1_ = 10;
  GameController_build_quest_text(local_2c,&local_248,&local_258);
  local_8._0_1_ = 4;
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  uVar5 = u16string_assignCStr(L"details:");
  local_8._0_1_ = 0xb;
  uVar5 = string_assign(local_2c,uVar5,&local_44);
  local_8._0_1_ = 0xc;
  GameController_build_quest_text(uVar5,&local_248,&local_258);
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  local_8._0_1_ = 4;
  if (7 < local_48) {
    operator_delete(local_5c[0]);
  }
  if (local_258 != local_254) {
    local_238 = 0xc;
    piVar7 = local_258;
    do {
      piVar6 = *(int **)*piVar7;
      local_231 = '\x01';
      local_230 = param_3;
      if (piVar6 != (int *)*piVar7) {
        do {
          (**(code **)(**(int **)(in_ECX + 0x800710) + 0x38))(local_22c);
          piVar1 = piVar6 + 2;
          Font_measureTextScaled(piVar1,local_22c,(float)local_238,0,0,0,0,local_c4,local_cc,0,1,0xffffffff,0)
          ;
          fVar8 = local_cc[0] - local_c4[0];
          iVar4 = u16string_compare(0,piVar6[6],&DAT_007020b8,1);
          if (((((iVar4 == 0) || (iVar4 = u16string_compare(0,piVar6[6],&DAT_007020bc,1), iVar4 == 0)) ||
               (iVar4 = u16string_compare(0,piVar6[6],&DAT_007020c0,1), iVar4 == 0)) ||
              ((iVar4 = u16string_compare(0,piVar6[6],&DAT_007020c4,1), iVar4 == 0 ||
               (iVar4 = u16string_compare(0,piVar6[6],&DAT_007020c8,1), iVar4 == 0)))) ||
             ((iVar4 = u16string_compare(0,piVar6[6],&DAT_007020cc,1), iVar4 == 0 ||
              ((cVar2 = wstring_equalsCI(piVar1,&DAT_00701ba8), cVar2 != '\0' ||
               (cVar2 = wstring_equalsCI(piVar1,&DAT_006fd42c), cVar2 != '\0')))))) {
LAB_004a5f29:
            local_232 = '\x01';
          }
          else {
            cVar2 = wstring_equalsCI(piVar1,&DAT_006fd740);
            local_232 = '\0';
            if (cVar2 != '\0') goto LAB_004a5f29;
          }
          if (local_231 == '\0') {
            if (local_232 == '\0') {
              local_230 = local_230 + local_238;
            }
            else {
              local_230 = local_230 + 3;
            }
          }
          iVar4 = u16string_compare(0,piVar6[6],&DAT_007020bc,1);
          local_231 = iVar4 == 0;
          if ((local_232 == '\0') && (param_3 + param_6 < (int)fVar8 + local_230)) {
            param_4 = param_4 + 4 + local_238;
            local_230 = param_3;
          }
          local_84 = 0;
          local_80 = 0;
          local_7c = 0;
          local_78 = 0;
          local_b4 = 0;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0x3f800000;
          local_9c = 0x3f800000;
          local_98 = 0x3f800000;
          local_94 = 0x3f800000;
          local_90 = 0x3f800000;
          Font_drawTextTransformed(piVar6 + 2,(float)local_230,(float)param_4,(float)local_238,0x40400000,0,0,0,
                       &local_9c,&local_b4,&local_84,0,1);
          local_54 = 0;
          local_50 = 0;
          local_4c = 0;
          local_48 = 0;
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          Font_drawTextTransformed(piVar6 + 2,(float)local_230,(float)param_4,(float)local_238,0,0,0,0,
                       piVar6 + 8,&local_24,&local_54,0,1);
          local_230 = local_230 + (int)fVar8;
          iVar4 = u16string_compare(0,piVar6[6],&DAT_006fd42c,1);
          if ((iVar4 == 0) || (iVar4 = u16string_compare(0,piVar6[6],&DAT_006fd744,1), iVar4 == 0)) {
            local_230 = local_230 + -9;
          }
          piVar6 = (int *)*piVar6;
          in_ECX = local_24c;
        } while (piVar6 != (int *)*piVar7);
      }
      param_4 = param_4 + 0x12;
      piVar7 = piVar7 + 2;
      local_238 = 10;
    } while (piVar7 != local_254);
  }
  if (local_30 < 8) {
    local_44 = (void *)((uint)local_44 & 0xffff0000);
    local_30 = 7;
    local_34 = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    Zone_rbtree_eraseRange(&local_24c,*local_240,local_240);
    operator_delete(local_240);
  }
  operator_delete(local_44);
}




/* [AUDIT] proposed: GameController::load_specialization_text  (confidence: low)
 * purpose: Load class specialization tooltip strings from resource1.dat
 * vars: param_1/2=class,spec
 */
/* Global::GameController_load_specialization_text @ 004a62c0 */

void GameController_load_specialization_text(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  float fVar9;
  int local_16c;
  int local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 *local_15c;
  undefined4 local_158;
  int *local_154;
  int *local_150;
  undefined4 local_14c;
  int local_148;
  char local_142;
  char local_141;
  int local_140;
  undefined1 local_13c [64];
  undefined1 local_fc [24];
  undefined1 local_e4 [24];
  undefined1 local_cc [24];
  float local_b4 [2];
  float local_ac [2];
  undefined1 local_a4 [8];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8c [8];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [8];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c [8];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e7e48;
  local_10 = ExceptionList;
  uVar4 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  local_14 = uVar4;
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8 = 0;
  local_168 = FontCache_find_or_create_scalable(local_2c);
  local_8 = 0xffffffff;
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
  if (local_168 == 0) {
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_154 = (int *)0x0;
  local_150 = (int *)0x0;
  local_14c = 0;
  local_8 = 1;
  local_164 = 0;
  local_160 = 0;
  local_164 = rbtree_allocHeaderNode_28(uVar4);
  local_8._0_1_ = 2;
  local_15c = (undefined4 *)0x0;
  local_158 = 0;
  local_15c = (undefined4 *)object_alloc();
  local_8._0_1_ = 3;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 3;
  uVar2 = uVar1;
  switch(param_1) {
  case 1:
    if (param_2 == 0) {
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:warrior:berserker");
      local_8 = CONCAT31(local_8._1_3_,4);
      GameController_build_quest_text(local_8c,&local_164,&local_154);
    }
    else {
      uVar2 = (undefined1)local_8;
      if (param_2 != 1) goto switchD_004a63de_default;
      u16string_assignCStr(L"specialization:warrior:guardian");
      local_8 = CONCAT31(local_8._1_3_,5);
      GameController_build_quest_text(local_a4,&local_164,&local_154);
    }
    break;
  case 2:
    if (param_2 == 0) {
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:ranger:sniper");
      local_8 = CONCAT31(local_8._1_3_,7);
      GameController_build_quest_text(local_5c,&local_164,&local_154);
    }
    else {
      uVar2 = (undefined1)local_8;
      if (param_2 != 1) goto switchD_004a63de_default;
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:ranger:scout");
      local_8 = CONCAT31(local_8._1_3_,6);
      GameController_build_quest_text(local_74,&local_164,&local_154);
    }
    break;
  case 3:
    if (param_2 == 0) {
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:mage:fire");
      local_8 = CONCAT31(local_8._1_3_,8);
      GameController_build_quest_text(local_e4,&local_164,&local_154);
    }
    else {
      uVar2 = (undefined1)local_8;
      if (param_2 != 1) goto switchD_004a63de_default;
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:mage:water");
      local_8 = CONCAT31(local_8._1_3_,9);
      GameController_build_quest_text(local_44,&local_164,&local_154);
    }
    break;
  case 4:
    if (param_2 == 0) {
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:rogue:assassin");
      local_8 = CONCAT31(local_8._1_3_,10);
      GameController_build_quest_text(local_cc,&local_164,&local_154);
    }
    else {
      uVar2 = (undefined1)local_8;
      if (param_2 != 1) goto switchD_004a63de_default;
      local_8._0_1_ = uVar1;
      u16string_assignCStr(L"specialization:rogue:ninja");
      local_8 = CONCAT31(local_8._1_3_,0xb);
      GameController_build_quest_text(local_fc,&local_164,&local_154);
    }
    break;
  default:
    goto switchD_004a63de_default;
  }
  local_8._0_1_ = 3;
  std_string_FreeMember();
  uVar2 = (undefined1)local_8;
switchD_004a63de_default:
  local_8._0_1_ = uVar2;
  if (local_154 != local_150) {
    local_148 = 0xc;
    piVar6 = local_150;
    piVar8 = local_154;
    do {
      piVar7 = *(int **)*piVar8;
      local_141 = '\x01';
      local_140 = param_3;
      if (piVar7 != (int *)*piVar8) {
        do {
          (**(code **)(**(int **)(local_16c + 0x800710) + 0x38))(local_13c);
          piVar6 = piVar7 + 2;
          Font_measureTextScaled(piVar6,local_13c,(float)local_148,0,0,0,0,local_ac,local_b4,0,1,0xffffffff,0)
          ;
          fVar9 = local_b4[0] - local_ac[0];
          iVar5 = u16string_compare(0,piVar7[6],&DAT_007020b8,1);
          if (((((iVar5 == 0) || (iVar5 = u16string_compare(0,piVar7[6],&DAT_007020bc,1), iVar5 == 0)) ||
               (iVar5 = u16string_compare(0,piVar7[6],&DAT_007020c0,1), iVar5 == 0)) ||
              ((iVar5 = u16string_compare(0,piVar7[6],&DAT_007020c4,1), iVar5 == 0 ||
               (iVar5 = u16string_compare(0,piVar7[6],&DAT_007020c8,1), iVar5 == 0)))) ||
             ((iVar5 = u16string_compare(0,piVar7[6],&DAT_007020cc,1), iVar5 == 0 ||
              ((cVar3 = wstring_equalsCI(piVar6,&DAT_00701ba8), cVar3 != '\0' ||
               (cVar3 = wstring_equalsCI(piVar6,&DAT_006fd42c), cVar3 != '\0')))))) {
LAB_004a679b:
            local_142 = '\x01';
          }
          else {
            cVar3 = wstring_equalsCI(piVar6,&DAT_006fd740);
            local_142 = '\0';
            if (cVar3 != '\0') goto LAB_004a679b;
          }
          if (local_141 == '\0') {
            if (local_142 == '\0') {
              local_140 = local_140 + local_148;
            }
            else {
              local_140 = local_140 + 3;
            }
          }
          iVar5 = u16string_compare(0,piVar7[6],&DAT_007020bc,1);
          local_141 = iVar5 == 0;
          if ((local_142 == '\0') && (param_3 + param_6 < (int)fVar9 + local_140)) {
            param_4 = param_4 + 4 + local_148;
            local_140 = param_3;
          }
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          local_54 = 0;
          local_50 = 0;
          local_4c = 0;
          local_48 = 0x3f800000;
          local_6c = 0x3f800000;
          local_68 = 0x3f800000;
          local_64 = 0x3f800000;
          local_60 = 0x3f800000;
          Font_drawTextTransformed(piVar7 + 2,(float)local_140,(float)param_4,(float)local_148,0x40400000,0,0,0,
                       &local_6c,&local_54,&local_3c,0,1);
          local_84 = 0;
          local_80 = 0;
          local_7c = 0;
          local_78 = 0;
          local_9c = 0;
          local_98 = 0;
          local_94 = 0;
          local_90 = 0;
          Font_drawTextTransformed(piVar7 + 2,(float)local_140,(float)param_4,(float)local_148,0,0,0,0,
                       piVar7 + 8,&local_9c,&local_84,0,1);
          local_140 = local_140 + (int)fVar9;
          iVar5 = u16string_compare(0,piVar7[6],&DAT_006fd42c,1);
          if ((iVar5 == 0) || (iVar5 = u16string_compare(0,piVar7[6],&DAT_006fd744,1), iVar5 == 0)) {
            local_140 = local_140 + -9;
          }
          piVar7 = (int *)*piVar7;
          piVar6 = local_150;
        } while (piVar7 != (int *)*piVar8);
      }
      param_4 = param_4 + 0x12;
      piVar8 = piVar8 + 2;
      local_148 = 10;
    } while (piVar8 != piVar6);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  Zone_rbtree_eraseRange(&local_16c,*local_15c,local_15c);
  operator_delete(local_15c);
}




/* Global::eh_catchall_004aba0c @ 004aba0c */

void Catch_All_004aba0c(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004abd8f @ 004abd8f */

void Catch_All_004abd8f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004abe6c @ 004abe6c */

void Catch_All_004abe6c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004abf64 @ 004abf64 */

void Catch_All_004abf64(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004c691e @ 004c691e */

void Catch_All_004c691e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_2 @ 004cb100 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_2
               (undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  int iVar1;
  basic_istream<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f60fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 != 0) {
    *(undefined ***)in_ECX = &PTR_006fcad0;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 0x10);
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            (in_ECX,this,false);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x70;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  local_8._0_1_ = 2;
  *(undefined ***)this = vftable;
  in_ECX[0x5c] = (basic_istream<char,std::char_traits<char>_>)0x0;
  in_ECX[0x55] = (basic_istream<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(int *)(in_ECX + 0x58) = DAT_0076af5c;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  if (0xf < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  iVar1 = std_filebuf_open(param_1,param_2 | 1,param_3);
  if (iVar1 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(in_ECX + *(int *)(*(int *)in_ECX + 4)),2,
               false);
  }
  ExceptionList = local_10;
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_4 @ 004cb220 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_4(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined ***)(*(int *)(*(int *)(in_ECX + -0x60) + 4) + -0x60 + in_ECX) =
       basic_ofstream<char,std::char_traits<char>_>::vftable;
  iVar1 = *(int *)(*(int *)(in_ECX + -0x60) + 4);
  *(int *)(iVar1 + -100 + in_ECX) = iVar1 + -0x60;
  *(undefined ***)(in_ECX + -0x5c) = vftable;
  if ((*(int *)(in_ECX + -0xc) != 0) && (**(int **)(in_ECX + -0x50) == in_ECX + -0x18)) {
    uVar2 = *(undefined4 *)(in_ECX + -0x20);
    **(int **)(in_ECX + -0x50) = *(int *)(in_ECX + -0x24);
    **(undefined4 **)(in_ECX + -0x40) = uVar2;
    **(undefined4 **)(in_ECX + -0x30) = 0;
  }
  if (*(char *)(in_ECX + -0x10) != '\0') {
    filebuf_close();
  }
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + -0x5c));
  std::basic_ostream<char,std::char_traits<char>_>::~basic_ostream<char,std::char_traits<char>_>
            ((basic_ostream<char,std::char_traits<char>_> *)(in_ECX + -0x58));
  return;
}




/* std::basic_ofstream<char,std::char_traits<char>_>::vfunc_0 @ 004cb2b5 */

void std::basic_ofstream<char,std::char_traits<char>_>::vfunc_0(void)

{
  std_basic_filebuf_scalar_deleting_dtor();
  return;
}




/* [AUDIT] proposed: std::basic_filebuf<char>::`scalar deleting dtor'  (confidence: med)
 * purpose: Filebuf dtor plus optional operator_delete of object
 * vars: param_1=delete flag
 */
/* Global::std_basic_filebuf_scalar_deleting_dtor @ 004cb2c0 */

ios_base * std_basic_filebuf_scalar_deleting_dtor(byte param_1)

{
  ios_base *in_ECX;
  
  std::basic_filebuf<char,std::char_traits<char>_>::ctor_4();
  *(code **)in_ECX = _vftable__exref;
  *(code **)in_ECX = _vftable__exref;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX + -0x60);
  }
  return in_ECX + -0x60;
}




/* std::basic_ofstream<char,std::char_traits<char>_>::vfunc_2 @ 004cb301 */

void std::basic_ofstream<char,std::char_traits<char>_>::vfunc_2(void)

{
  int in_ECX;
  
  std::basic_ostream<char,std::char_traits<char>_>::_Add_vtordisp2
            ((basic_ostream<char,std::char_traits<char>_> *)
             ((in_ECX - *(int *)(in_ECX + -4)) + -0x58));
  return;
}




/* Global::eh_catchall_004cb3d8 @ 004cb3d8 */

void Catch_All_004cb3d8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004cb583 @ 004cb583 */

void Catch_All_004cb583(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004ce3d9 @ 004ce3d9 */

undefined * Catch_All_004ce3d9(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_004ce3f3;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_8 @ 004ce550 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_8
               (undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  int iVar1;
  basic_ostream<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e860d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 != 0) {
    *(undefined ***)in_ECX = &PTR_007030ac;
    *(code **)(in_ECX + 0x60) = _vftable__exref;
    *(code **)(in_ECX + 0x60) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 4);
  std::basic_ostream<char,std::char_traits<char>_>::basic_ostream<char,std::char_traits<char>_>
            (in_ECX,this,false);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_ofstream<char,std::char_traits<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x60;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  local_8._0_1_ = 2;
  *(undefined ***)this = vftable;
  in_ECX[0x50] = (basic_ostream<char,std::char_traits<char>_>)0x0;
  in_ECX[0x49] = (basic_ostream<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(int *)(in_ECX + 0x4c) = DAT_0076af5c;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = std_filebuf_open(param_1,param_2 | 2,param_3);
  if (iVar1 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(in_ECX + *(int *)(*(int *)in_ECX + 4)),2,
               false);
  }
  ExceptionList = local_10;
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_22 @ 004d50a0 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_22(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar7;
  undefined4 uVar8;
  undefined4 ****ppppuVar9;
  int in_ECX;
  undefined8 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  float fVar14;
  float fVar15;
  undefined *puVar16;
  undefined1 auStack_3cc [24];
  undefined1 auStack_3b4 [24];
  undefined1 auStack_39c [24];
  undefined1 auStack_384 [24];
  undefined1 auStack_36c [24];
  undefined1 auStack_354 [24];
  undefined1 auStack_33c [24];
  undefined1 auStack_324 [24];
  undefined1 auStack_30c [24];
  undefined1 auStack_2f4 [24];
  undefined1 auStack_2dc [24];
  undefined1 auStack_2c4 [24];
  undefined1 auStack_2ac [24];
  undefined1 auStack_294 [24];
  undefined1 auStack_27c [24];
  undefined1 auStack_264 [24];
  void *local_24c [5];
  uint local_238;
  void *local_234 [4];
  undefined4 local_224;
  uint local_220;
  void *local_21c [2];
  undefined4 local_214;
  undefined4 local_210;
  undefined4 uStack_20c;
  uint local_208;
  void *local_204 [2];
  undefined4 local_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1f4;
  uint uStack_1f0;
  undefined4 ***local_1ec [2];
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  uint local_1d8;
  undefined8 local_1d4 [32];
  undefined8 local_d4;
  int local_c8;
  undefined **local_c4 [4];
  undefined *local_b4 [2];
  undefined **local_ac [14];
  undefined4 local_74;
  undefined4 local_70;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_5c [72];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8dd1;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec[0] = (undefined4 ***)((uint)local_1ec[0] & 0xffff0000);
  u16string_assignPtrLen(L"star1",5);
  local_8 = 0;
  iVar3 = Node_find_child_by_name_recursive(local_1ec);
  local_8 = 0xffffffff;
  *(undefined4 *)
   (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
  if (7 < local_1d8) {
    operator_delete(local_1ec[0]);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec[0] = (undefined4 ***)((uint)local_1ec[0] & 0xffff0000);
  u16string_assignPtrLen(L"star2",5);
  local_8 = 1;
  iVar3 = Node_find_child_by_name_recursive(local_1ec);
  local_8 = 0xffffffff;
  *(undefined4 *)
   (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
  if (7 < local_1d8) {
    operator_delete(local_1ec[0]);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec[0] = (undefined4 ***)((uint)local_1ec[0] & 0xffff0000);
  u16string_assignPtrLen(L"star3",5);
  local_8 = 2;
  iVar3 = Node_find_child_by_name_recursive(local_1ec);
  local_8 = 0xffffffff;
  *(undefined4 *)
   (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
  if (7 < local_1d8) {
    operator_delete(local_1ec[0]);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec[0] = (undefined4 ***)((uint)local_1ec[0] & 0xffff0000);
  u16string_assignPtrLen(L"star4",5);
  local_8 = 3;
  iVar3 = Node_find_child_by_name_recursive(local_1ec);
  local_8 = 0xffffffff;
  *(undefined4 *)
   (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
  if (7 < local_1d8) {
    operator_delete(local_1ec[0]);
  }
  if (*(int *)(in_ECX + 0x160) == 0) {
    if (-1 < *(int *)(in_ECX + 0x170)) {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x148) + 0x38);
      iVar5 = *(int *)(iVar3 + 0x170);
      iVar3 = *(int *)(iVar3 + 0x19c);
      fVar15 = *(float *)(iVar3 + iVar5 * 8);
      fVar1 = *(float *)(iVar3 + 4 + iVar5 * 8);
      (**(code **)(**(int **)(in_ECX + 4) + 0x40))(*(int *)(in_ECX + 0x148));
      GameController_load_specialization_text(*(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x17c) + 0x8006d0) + 0x140),
                   *(undefined4 *)(in_ECX + 0x170),(int)(fVar15 + 14.0),(int)(fVar1 + 25.0),
                   0x3f800000,0x113);
      (**(code **)(**(int **)(in_ECX + 4) + 0x44))(*(undefined4 *)(in_ECX + 0x148));
    }
    if (-1 < *(int *)(in_ECX + 0x168)) {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x148) + 0x38);
      iVar5 = *(int *)(iVar3 + 0x170);
      iVar3 = *(int *)(iVar3 + 0x19c);
      fVar15 = *(float *)(iVar3 + iVar5 * 8);
      fVar1 = *(float *)(iVar3 + 4 + iVar5 * 8);
      (**(code **)(**(int **)(in_ECX + 4) + 0x40))(*(int *)(in_ECX + 0x148));
      GameController_load_skill_tooltip(*(undefined4 *)(in_ECX + 0x168),*(undefined4 *)(in_ECX + 0x16c),
                   (int)(fVar15 + 14.0f),(int)(fVar1 + 25.0f),0x3f800000,0x113);
      (**(code **)(**(int **)(in_ECX + 4) + 0x44))(*(undefined4 *)(in_ECX + 0x148));
    }
  }
  else {
    switch(*(undefined1 *)(*(int *)(in_ECX + 0x160) + 0xc)) {
    case 1:
      u16string_assignCStr(L"star1");
      local_8 = 4;
      iVar3 = Node_find_child_by_name_recursive(auStack_2ac);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 1;
      std_string_FreeMember();
      u16string_assignCStr(L"star2");
      local_8 = 5;
      iVar3 = Node_find_child_by_name_recursive(auStack_2c4);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star3");
      local_8 = 6;
      iVar3 = Node_find_child_by_name_recursive(auStack_2f4);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star4");
      local_8 = 7;
      iVar3 = Node_find_child_by_name_recursive(auStack_264);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      break;
    case 2:
      u16string_assignCStr(L"star1");
      local_8 = 8;
      iVar3 = Node_find_child_by_name_recursive(auStack_3b4);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star2");
      local_8 = 9;
      iVar3 = Node_find_child_by_name_recursive(auStack_324);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 1;
      std_string_FreeMember();
      u16string_assignCStr(L"star3");
      local_8 = 10;
      iVar3 = Node_find_child_by_name_recursive(auStack_384);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star4");
      local_8 = 0xb;
      iVar3 = Node_find_child_by_name_recursive(auStack_27c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      break;
    case 3:
      u16string_assignCStr(L"star1");
      local_8 = 0xc;
      iVar3 = Node_find_child_by_name_recursive(auStack_294);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star2");
      local_8 = 0xd;
      iVar3 = Node_find_child_by_name_recursive(auStack_2dc);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star3");
      local_8 = 0xe;
      iVar3 = Node_find_child_by_name_recursive(auStack_30c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 1;
      std_string_FreeMember();
      u16string_assignCStr(L"star4");
      local_8 = 0xf;
      iVar3 = Node_find_child_by_name_recursive(auStack_33c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      break;
    case 4:
      u16string_assignCStr(L"star1");
      local_8 = 0x10;
      iVar3 = Node_find_child_by_name_recursive(auStack_36c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star2");
      local_8 = 0x11;
      iVar3 = Node_find_child_by_name_recursive(auStack_39c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star3");
      local_8 = 0x12;
      iVar3 = Node_find_child_by_name_recursive(auStack_3cc);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      std_string_FreeMember();
      u16string_assignCStr(L"star4");
      local_8 = 0x13;
      iVar3 = Node_find_child_by_name_recursive(auStack_354);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 1;
      std_string_FreeMember();
      break;
    default:
      u16string_assignCStr(L"star1");
      local_8 = 0x14;
      iVar3 = Node_find_child_by_name_recursive(local_1ec);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      if (7 < local_1d8) {
        operator_delete(local_1ec[0]);
      }
      local_1d8 = 7;
      local_1dc = 0;
      local_1ec[0] = (undefined4 ***)((uint)local_1ec[0] & 0xffff0000);
      u16string_assignCStr(L"star2");
      local_8 = 0x15;
      iVar3 = Node_find_child_by_name_recursive(local_204);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      if (7 < uStack_1f0) {
        operator_delete(local_204[0]);
      }
      uStack_1f0 = 7;
      local_1f4 = 0;
      local_204[0] = (void *)((uint)local_204[0] & 0xffff0000);
      u16string_assignCStr(L"star3");
      local_8 = 0x16;
      iVar3 = Node_find_child_by_name_recursive(local_21c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      if (7 < local_208) {
        operator_delete(local_21c[0]);
      }
      local_208 = 7;
      uStack_20c = 0;
      local_21c[0] = (void *)((uint)local_21c[0] & 0xffff0000);
      u16string_assignCStr(L"star4");
      local_8 = 0x17;
      iVar3 = Node_find_child_by_name_recursive(local_24c);
      local_8 = 0xffffffff;
      *(undefined4 *)
       (*(int *)(*(int *)(iVar3 + 0x3c) + 0x94) + *(int *)(*(int *)(iVar3 + 0x3c) + 0x68) * 4) = 0;
      if (7 < local_238) {
        operator_delete(local_24c[0]);
      }
    }
    iVar3 = GameController_item_icon_id(*(undefined4 *)(in_ECX + 0x160));
    if (iVar3 != 0) {
      piVar13 = *(int **)(*(int *)(in_ECX + 0x17c) + 0x134);
      (**(code **)(*piVar13 + 0xe4))(piVar13,7,1);
      piVar13 = *(int **)(*(int *)(in_ECX + 0x17c) + 0x134);
      (**(code **)(*piVar13 + 0xe4))(piVar13,0x17,2);
      local_1fc = 0;
      uStack_1f8 = 0;
      local_1f4 = 0;
      uStack_1f0 = 0;
      local_210 = 0;
      uStack_20c = 0;
      local_208 = 0;
      puVar4 = &local_d4;
      puVar10 = local_1d4;
      iVar3 = 0x10;
      do {
        *puVar10 = 0;
        *puVar4 = 0;
        puVar10[1] = 0;
        *(undefined4 *)(puVar4 + 1) = 0;
        puVar10 = puVar10 + 2;
        puVar4 = (undefined8 *)((int)puVar4 + 0xc);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      render_bindNodeTransformA();
      render_uploadBoneMatrices(local_1d4,&local_d4);
      local_1fc = 0x3f800000;
      uStack_1f8 = 0x3f800000;
      local_1f4 = 0x3f800000;
      uStack_1f0 = 0x3f800000;
      render_setUniform30(&local_1fc);
      iVar3 = *(int *)(in_ECX + 0x148);
      iVar5 = *(int *)(*(int *)(iVar3 + 0x38) + 0x170);
      iVar6 = *(int *)(*(int *)(iVar3 + 0x38) + 0x19c);
      fVar15 = *(float *)(iVar6 + 4 + iVar5 * 8);
      fVar1 = *(float *)(iVar6 + iVar5 * 8);
      fVar14 = 1.0f / (*(float *)(iVar3 + 0x54) * fVar1 + *(float *)(iVar3 + 100) * fVar15 +
                     *(float *)(iVar3 + 0x84));
      drawBillboardModelRotated((*(float *)(iVar3 + 0x58) * fVar15 + *(float *)(iVar3 + 0x48) * fVar1 +
                   *(float *)(iVar3 + 0x78)) * fVar14 + 150.0,
                   (*(float *)(iVar3 + 0x4c) * fVar1 + *(float *)(iVar3 + 0x5c) * fVar15 +
                   *(float *)(iVar3 + 0x7c)) * fVar14 + 150.0,*(int *)(in_ECX + 0x17c) + 0x800a1c,
                   0x3dcccccd,*(undefined4 *)(in_ECX + 0x160),0xbd4ccccd);
    }
    piVar13 = *(int **)(*(int *)(in_ECX + 0x17c) + 0x134);
    (**(code **)(*piVar13 + 0xe4))(piVar13,7,0);
    iVar3 = *(int *)(*(int *)(in_ECX + 0x148) + 0x38);
    iVar5 = *(int *)(iVar3 + 0x170);
    iVar3 = *(int *)(iVar3 + 0x19c);
    fVar15 = *(float *)(iVar3 + 4 + iVar5 * 8);
    fVar1 = *(float *)(iVar3 + iVar5 * 8);
    ctor_0(*(undefined4 *)(in_ECX + 0x160),(int)(fVar1 + 14.0f),(int)(fVar15 + 25.0f),0x3f800000,0x118
           ,1,1,0);
    cVar2 = GameController_validate_selected_zone();
    if (cVar2 != '\0') {
      iVar3 = item_valueByType();
      iVar5 = (iVar3 / 100) / 100;
      iVar11 = (iVar3 / 100) % 100;
      local_c4[0] = &PTR_006fcd00;
      local_b4[0] = &DAT_006fcd08;
      std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
      basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_5c);
      local_8 = 0x18;
      std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
      basic_iostream<wchar_t,std::char_traits<wchar_t>_>
                ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_c4,
                 (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_ac);
      local_8 = 0x19;
      *(undefined ***)((int)local_c4 + (int)local_c4[0][1]) =
           basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
      *(undefined **)((int)&local_c8 + (int)local_c4[0][1]) = local_c4[0][1] + -0x68;
      std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
      basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_ac);
      local_ac[0] = vftable;
      local_74 = 0;
      local_70 = 0;
      local_8._0_1_ = 0x1b;
      local_8._1_3_ = 0;
      iVar12 = (int)(fVar1 + 290.0f);
      iVar6 = (int)(fVar15 + 280.0f);
      if (iVar3 % 100 != 0) {
        u16string_assignCStr(&PTR_006fccac);
        local_8._0_1_ = 0x1c;
        strstreambuf_tidy();
        ppppuVar9 = local_1ec;
        if (7 < local_1d8) {
          ppppuVar9 = (undefined4 ****)local_1ec[0];
        }
        strstreambuf_init(ppppuVar9,local_1dc,local_70);
        local_8._0_1_ = 0x1b;
        if (7 < local_1d8) {
          operator_delete(local_1ec[0]);
        }
        puVar16 = &DAT_006ffd80;
        pbVar7 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                           ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_b4,
                            iVar3 % 100);
        wostream_insertNarrow(pbVar7,puVar16);
        u16string_assignCStr(L"resource1.dat");
        local_8._0_1_ = 0x1d;
        uVar8 = u16_ostrstream_str_wrap(local_234);
        local_1fc = 0;
        uStack_1f8 = 0;
        local_1f4 = 0;
        uStack_1f0 = 0;
        local_214 = 0;
        local_210 = 0;
        uStack_20c = 0;
        local_208 = 0x3f800000;
        local_1e4 = 0x3f800000;
        local_1e0 = 0x3f800000;
        local_1dc = 0x3f800000;
        local_1d8 = 0x3f800000;
        local_8._0_1_ = 0x1e;
        AdaptionWidget_draw_text_locked(local_24c,uVar8,0,0,(float)iVar12,(float)iVar6,0x41200000,0x40000000,&local_1e4
                     ,&local_214,&local_1fc,2,0xbf800000,1);
        if (7 < local_220) {
          operator_delete(local_234[0]);
        }
        local_220 = 7;
        local_224 = 0;
        local_234[0] = (void *)((uint)local_234[0] & 0xffff0000);
        local_8._0_1_ = 0x1b;
        if (7 < local_238) {
          operator_delete(local_24c[0]);
        }
        u16string_assignCStr(L"resource1.dat");
        local_8._0_1_ = 0x1f;
        uVar8 = u16_ostrstream_str_wrap(local_234);
        local_1e4 = 0;
        local_1e0 = 0;
        local_1dc = 0;
        local_1d8 = 0;
        local_1fc = 0;
        uStack_1f8 = 0;
        local_1f4 = 0;
        uStack_1f0 = 0;
        local_214 = 0x3f4ccccd;
        local_210 = 0x3f000000;
        uStack_20c = 0;
        local_208 = 0x3f800000;
        local_8._0_1_ = 0x20;
        AdaptionWidget_draw_text_locked(local_24c,uVar8,0,0,(float)iVar12,(float)iVar6,0x41200000,0,&local_214,
                     &local_1fc,&local_1e4,2,0xbf800000,1);
        if (7 < local_220) {
          operator_delete(local_234[0]);
        }
        local_220 = 7;
        local_224 = 0;
        local_234[0] = (void *)((uint)local_234[0] & 0xffff0000);
        local_8._0_1_ = 0x1b;
        if (7 < local_238) {
          operator_delete(local_24c[0]);
        }
        iVar12 = iVar12 + -0x28;
      }
      local_8._0_1_ = 0x1b;
      if (iVar11 != 0) {
        u16string_assignCStr(&PTR_006fccac);
        local_8._0_1_ = 0x21;
        strstreambuf_tidy();
        ppppuVar9 = local_1ec;
        if (7 < local_1d8) {
          ppppuVar9 = (undefined4 ****)local_1ec[0];
        }
        strstreambuf_init(ppppuVar9,local_1dc,local_70);
        local_8._0_1_ = 0x1b;
        if (7 < local_1d8) {
          operator_delete(local_1ec[0]);
        }
        puVar16 = &DAT_006ffd84;
        pbVar7 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                           ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_b4,iVar11);
        wostream_insertNarrow(pbVar7,puVar16);
        u16string_assignCStr(L"resource1.dat");
        local_8._0_1_ = 0x22;
        uVar8 = u16_ostrstream_str_wrap(local_234);
        local_1e4 = 0;
        local_1e0 = 0;
        local_1dc = 0;
        local_1d8 = 0;
        local_1fc = 0;
        uStack_1f8 = 0;
        local_1f4 = 0;
        uStack_1f0 = 0x3f800000;
        local_214 = 0x3f800000;
        local_210 = 0x3f800000;
        uStack_20c = 0x3f800000;
        local_208 = 0x3f800000;
        local_8._0_1_ = 0x23;
        AdaptionWidget_draw_text_locked(local_24c,uVar8,0,0,(float)iVar12,(float)iVar6,0x41200000,0x40000000,&local_214
                     ,&local_1fc,&local_1e4,2,0xbf800000,1);
        if (7 < local_220) {
          operator_delete(local_234[0]);
        }
        local_220 = 7;
        local_224 = 0;
        local_234[0] = (void *)((uint)local_234[0] & 0xffff0000);
        local_8._0_1_ = 0x1b;
        if (7 < local_238) {
          operator_delete(local_24c[0]);
        }
        u16string_assignCStr(L"resource1.dat");
        local_8._0_1_ = 0x24;
        uVar8 = u16_ostrstream_str_wrap(local_234);
        local_1e4 = 0;
        local_1e0 = 0;
        local_1dc = 0;
        local_1d8 = 0;
        local_1fc = 0;
        uStack_1f8 = 0;
        local_1f4 = 0;
        uStack_1f0 = 0;
        local_214 = 0x3f333333;
        local_210 = 0x3f333333;
        uStack_20c = 0x3f333333;
        local_208 = 0x3f800000;
        local_8._0_1_ = 0x25;
        AdaptionWidget_draw_text_locked(local_24c,uVar8,0,0,(float)iVar12,(float)iVar6,0x41200000,0,&local_214,
                     &local_1fc,&local_1e4,2,0xbf800000,1);
        if (7 < local_220) {
          operator_delete(local_234[0]);
        }
        local_220 = 7;
        local_224 = 0;
        local_234[0] = (void *)((uint)local_234[0] & 0xffff0000);
        local_8._0_1_ = 0x1b;
        if (7 < local_238) {
          operator_delete(local_24c[0]);
        }
        iVar12 = iVar12 + -0x28;
      }
      local_8._0_1_ = 0x1b;
      if (iVar5 != 0) {
        u16string_assignCStr(&PTR_006fccac);
        local_8._0_1_ = 0x26;
        strstreambuf_tidy();
        ppppuVar9 = local_1ec;
        if (7 < local_1d8) {
          ppppuVar9 = (undefined4 ****)local_1ec[0];
        }
        strstreambuf_init(ppppuVar9,local_1dc,local_70);
        local_8._0_1_ = 0x1b;
        if (7 < local_1d8) {
          operator_delete(local_1ec[0]);
        }
        puVar16 = &DAT_006ffd88;
        pbVar7 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                           ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_b4,iVar5);
        wostream_insertNarrow(pbVar7,puVar16);
        u16string_assignCStr(L"resource1.dat");
        local_8._0_1_ = 0x27;
        uVar8 = u16_ostrstream_str_wrap(local_234);
        local_1e4 = 0;
        local_1e0 = 0;
        local_1dc = 0;
        local_1d8 = 0;
        local_1fc = 0;
        uStack_1f8 = 0;
        local_1f4 = 0;
        uStack_1f0 = 0x3f800000;
        local_214 = 0x3f800000;
        local_210 = 0x3f800000;
        uStack_20c = 0x3f800000;
        local_208 = 0x3f800000;
        local_8._0_1_ = 0x28;
        AdaptionWidget_draw_text_locked(local_24c,uVar8,0,0,(float)iVar12,(float)iVar6,0x41200000,0x40000000,&local_214
                     ,&local_1fc,&local_1e4,2,0xbf800000,1);
        if (7 < local_220) {
          operator_delete(local_234[0]);
        }
        local_220 = 7;
        local_224 = 0;
        local_234[0] = (void *)((uint)local_234[0] & 0xffff0000);
        local_8._0_1_ = 0x1b;
        if (7 < local_238) {
          operator_delete(local_24c[0]);
        }
        u16string_assignCStr(L"resource1.dat");
        local_8._0_1_ = 0x29;
        uVar8 = u16_ostrstream_str_wrap(local_234);
        local_1e4 = 0;
        local_1e0 = 0;
        local_1dc = 0;
        local_1d8 = 0;
        local_1fc = 0;
        uStack_1f8 = 0;
        local_1f4 = 0;
        uStack_1f0 = 0;
        local_214 = 0x3f800000;
        local_210 = 0x3f666666;
        uStack_20c = 0;
        local_208 = 0x3f800000;
        local_8 = CONCAT31(local_8._1_3_,0x2a);
        AdaptionWidget_draw_text_locked(local_24c,uVar8,0,0,(float)iVar12,(float)iVar6,0x41200000,0,&local_214,
                     &local_1fc,&local_1e4,2,0xbf800000,1);
        if (7 < local_220) {
          operator_delete(local_234[0]);
        }
        local_220 = 7;
        local_224 = 0;
        local_234[0] = (void *)((uint)local_234[0] & 0xffff0000);
        if (7 < local_238) {
          operator_delete(local_24c[0]);
        }
      }
      local_8 = 0xffffffff;
      ctor_18();
    }
    if (*(int *)(in_ECX + 0x178) != 0) {
      u16string_assignCStr(L"Currently equipped");
      local_8 = 0x2b;
      u16string_assignCStr(L"resource1.dat");
      local_1e4 = 0;
      local_1e0 = 0;
      local_1dc = 0;
      local_1d8 = 0;
      local_1fc = 0;
      uStack_1f8 = 0;
      local_1f4 = 0;
      uStack_1f0 = 0x3f800000;
      local_214 = 0x3f800000;
      local_210 = 0x3f800000;
      uStack_20c = 0x3f800000;
      local_208 = 0x3f800000;
      local_8._0_1_ = 0x2c;
      AdaptionWidget_draw_text_locked(local_24c,local_234,0,0,fVar1 - 190.0f,fVar15 + 20.0f,0x41000000,0x40400000,
                   &local_214,&local_1fc,&local_1e4,0,0xbf800000,1);
      local_8._0_1_ = 0x2b;
      if (7 < local_238) {
        operator_delete(local_24c[0]);
      }
      u16string_assignCStr(L"resource1.dat");
      local_1e4 = 0;
      local_1e0 = 0;
      local_1dc = 0;
      local_1d8 = 0;
      local_1fc = 0;
      uStack_1f8 = 0;
      local_1f4 = 0;
      uStack_1f0 = 0;
      local_214 = 0x3f800000;
      local_210 = 0x3f800000;
      uStack_20c = 0x3f800000;
      local_208 = 0x3f800000;
      local_8._0_1_ = 0x2d;
      AdaptionWidget_draw_text_locked(local_24c,local_234,0,0,fVar1 - 190.0f,fVar15 + 20.0f,0x41000000,0,&local_214,
                   &local_1fc,&local_1e4,0,0xbf800000,1);
      local_8 = CONCAT31(local_8._1_3_,0x2b);
      if (7 < local_238) {
        operator_delete(local_24c[0]);
      }
      fVar15 = fVar15 + 10.0f;
      piVar13 = (int *)**(int **)(in_ECX + 0x174);
      if (piVar13 != *(int **)(in_ECX + 0x174)) {
        do {
          ctor_0(piVar13[2],(int)(fVar1 - 240.0f),(int)(fVar15 + 30.0f),0x3f800000,0xe6,1,1,
                 *(undefined1 *)(in_ECX + 0x164));
          fVar15 = fVar15 + 130.0f;
          piVar13 = (int *)*piVar13;
        } while (piVar13 != (int *)*(int *)(in_ECX + 0x174));
      }
      if (7 < local_220) {
        operator_delete(local_234[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* MSVCR110.DLL::free_004d6c30 @ 004d6c30 */

void __cdecl free(void *_Memory)

{
  free(_Memory);
  return;
}




/* Global::thunk_FUN_004d77d0 @ 004d6d30 */

void thunk_FUN_004d77d0(void)

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




/* Global::eh_catchall_004d9ac7 @ 004d9ac7 */

void Catch_All_004d9ac7(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004d9c2f @ 004d9c2f */

void Catch_All_004d9c2f(void)

{
  int unaff_EBP;
  
  std_map_eraseTreeRec(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004da18f @ 004da18f */

void Catch_All_004da18f(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004da2df @ 004da2df */

void Catch_All_004da2df(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004dc4cc @ 004dc4cc */

void Catch_All_004dc4cc(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004dc569 @ 004dc569 */

void Catch_All_004dc569(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_Unlink(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004dc639 @ 004dc639 */

void Catch_All_004dc639(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004dc707 @ 004dc707 */

void Catch_All_004dc707(void)

{
  int unaff_EBP;
  int iVar1;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 != *(int *)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      iVar1 = iVar1 + 0x14;
    } while (iVar1 != *(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004dc7d9 @ 004dc7d9 */

void Catch_All_004dc7d9(void)

{
  int unaff_EBP;
  int iVar1;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 != *(int *)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      iVar1 = iVar1 + 0x148;
    } while (iVar1 != *(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_20 @ 004dd810 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_20(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  basic_ostream<wchar_t,std::char_traits<wchar_t>_> *pbVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar5;
  undefined4 *puVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined *puVar18;
  undefined4 uVar19;
  int iStack_16c;
  undefined **local_168 [4];
  undefined *local_158 [2];
  undefined **local_150 [3];
  undefined4 *local_144;
  undefined4 local_118;
  uint local_114;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_100 [72];
  int local_b8;
  int local_b4;
  undefined4 *local_b0;
  float local_ac;
  byte local_a5;
  void *local_a4 [5];
  uint local_90;
  void *local_8c [4];
  undefined4 local_7c;
  uint local_78;
  void *local_74 [2];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e93c8;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b0 = (undefined4 *)0x0;
  local_168[0] = &PTR_006fcd00;
  local_158[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_100);
  local_8 = 0;
  local_b0 = (undefined4 *)0x1;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_168,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_150);
  local_8 = 1;
  *(undefined ***)((int)local_168 + (int)local_168[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_16c + (int)local_168[0][1]) = local_168[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_150);
  local_150[0] = vftable;
  local_118 = 0;
  local_114 = 0;
  local_8 = 3;
  wostream_insertWide(local_158,L"Skills");
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 4;
  uVar2 = u16_ostrstream_str_wrap(local_74);
  local_8._0_1_ = 5;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0x3f800000;
  local_3c = 0x3f800000;
  local_38 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,0x41c80000,0x41400000,0x40400000,&local_3c,&local_4c,
               &local_5c,0,0xbf800000,1);
  if (7 < local_60) {
    operator_delete(local_74[0]);
  }
  local_60 = 7;
  local_64 = 0;
  local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 6;
  uVar2 = u16_ostrstream_str_wrap(local_74);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 7;
  AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,0x41c80000,0x41400000,0,&local_5c,&local_4c,&local_3c,
               0,0xbf800000,1);
  if (7 < local_60) {
    operator_delete(local_74[0]);
  }
  local_60 = 7;
  local_64 = 0;
  local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 8;
  strstreambuf_tidy();
  puVar6 = &local_2c;
  if (7 < local_18) {
    puVar6 = local_2c;
  }
  strstreambuf_init(puVar6,local_1c,local_114);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  iVar8 = 0;
  iVar9 = 0;
  piVar3 = (int *)(in_ECX + 0x164);
  iVar7 = 5;
  do {
    iVar8 = iVar8 + piVar3[-1];
    iVar9 = iVar9 + *piVar3;
    piVar3 = piVar3 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar8 = *(int *)(in_ECX + 0x188) + iVar9 + iVar8;
  iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 400) + 0x8006d0) + 400) * 2 + -2;
  pbVar4 = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)
           wostream_insertNarrow(local_158,"Points: ",iVar8,&DAT_00701904);
  pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(pbVar4,iVar8);
  pbVar4 = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)wostream_insertNarrow(pbVar5);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(pbVar4,iVar7);
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 9;
  uVar2 = u16_ostrstream_str_wrap(local_74);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 10;
  AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,0x42340000,0x41200000,0x40000000,&local_5c,&local_4c,
               &local_3c,0,0xbf800000,1);
  if (7 < local_60) {
    operator_delete(local_74[0]);
  }
  local_60 = 7;
  local_64 = 0;
  local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_18 = 7;
  local_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0xb;
  uVar2 = u16_ostrstream_str_wrap(local_74);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0xc;
  AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,0x42340000,0x41200000,0,&local_5c,&local_4c,&local_3c,
               0,0xbf800000,1);
  if (7 < local_60) {
    operator_delete(local_74[0]);
  }
  local_60 = 7;
  local_64 = 0;
  local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_18) {
    operator_delete(local_2c);
  }
  local_a5 = 0;
  iVar7 = *(int *)(*(int *)(in_ECX + 400) + 0x8006d0);
  iVar8 = 0x1138;
  do {
    if (*(int *)(in_ECX + -0xfd8 + iVar8) != *(int *)(iVar8 + iVar7)) {
      local_a5 = 1;
      break;
    }
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x1164);
  local_ac = (float)(uint)local_a5;
  if (*(uint *)(in_ECX + 0x18c) != (uint)*(byte *)(iVar7 + 0x141)) {
    local_ac = 1.4013e-45f;
  }
  iVar7 = GameController_computeQuestScore();
  local_a5 = iVar7 <= *(int *)(*(int *)(*(int *)(in_ECX + 400) + 0x8006d0) + 0x1304);
  if (0 < iVar7) {
    local_b8 = (iVar7 / 100) / 100;
    local_b4 = (iVar7 / 100) % 100;
    fVar10 = (float)security_cookie_guard_a();
    local_b0 = (undefined4 *)(float)fVar10;
    iVar8 = (int)((float)local_b0 - 65.0f);
    if (local_a5 == '\0') {
      local_18 = 7;
      local_1c = 0;
      local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
      u16string_assignPtrLen(&PTR_006fccac,0);
      local_8._0_1_ = 0xd;
      if ((local_114 & 1) != 0) {
        operator_delete((void *)*local_144);
      }
      std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
                ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_150,(wchar_t *)0x0,
                 (wchar_t *)0x0,(wchar_t *)0x0);
      std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
                ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_150,(wchar_t *)0x0,
                 (wchar_t *)0x0);
      local_114 = local_114 & 0xfffffffe;
      puVar6 = &local_2c;
      if (7 < local_18) {
        puVar6 = local_2c;
      }
      local_118 = 0;
      strstreambuf_init(puVar6,local_1c,local_114);
      local_8._0_1_ = 3;
      if (7 < local_18) {
        operator_delete(local_2c);
      }
      wostream_insertNarrow(local_158,"Not enough money.");
      local_18 = 7;
      local_1c = 0;
      local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
      u16string_assignPtrLen(L"resource1.dat",0xd);
      local_8._0_1_ = 0xe;
      uVar2 = u16_ostrstream_str_wrap(local_74);
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0x3f800000;
      local_5c = 0x3f800000;
      local_58 = 0x3f800000;
      local_54 = 0x3f800000;
      local_50 = 0x3f800000;
      local_8._0_1_ = 0xf;
      AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,(float)iVar8,0x41200000,0x40000000,&local_5c,
                   &local_4c,&local_3c,0,0xbf800000,1);
      if (7 < local_60) {
        operator_delete(local_74[0]);
      }
      local_60 = 7;
      local_64 = 0;
      local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
      local_8._0_1_ = 3;
      if (7 < local_18) {
        operator_delete(local_2c);
      }
      local_18 = 7;
      local_1c = 0;
      local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
      u16string_assignPtrLen(L"resource1.dat",0xd);
      local_8._0_1_ = 0x10;
      uVar2 = u16_ostrstream_str_wrap(local_74);
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_5c = 0x3f800000;
      local_58 = 0x3e800000;
      local_54 = 0x3e800000;
      local_50 = 0x3f800000;
      local_8._0_1_ = 0x11;
      AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,(float)iVar8,0x41200000,0,&local_5c,&local_4c,
                   &local_3c,0,0xbf800000,1);
      if (7 < local_60) {
        operator_delete(local_74[0]);
      }
      local_60 = 7;
      local_64 = 0;
      local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
      local_8._0_1_ = 3;
      if (7 < local_18) {
        operator_delete(local_2c);
      }
    }
    else {
      cVar1 = hasNearbyAllyEntity();
      if (cVar1 == '\0') {
        local_18 = 7;
        local_1c = 0;
        local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
        u16string_assignPtrLen(&PTR_006fccac,0);
        local_8._0_1_ = 0x12;
        if ((local_114 & 1) != 0) {
          operator_delete((void *)*local_144);
        }
        std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
                  ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_150,(wchar_t *)0x0,
                   (wchar_t *)0x0,(wchar_t *)0x0);
        std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
                  ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_150,(wchar_t *)0x0,
                   (wchar_t *)0x0);
        local_114 = local_114 & 0xfffffffe;
        puVar6 = &local_2c;
        if (7 < local_18) {
          puVar6 = local_2c;
        }
        local_118 = 0;
        strstreambuf_init(puVar6,local_1c,local_114);
        local_8._0_1_ = 3;
        if (7 < local_18) {
          operator_delete(local_2c);
        }
        wostream_insertNarrow(local_158,"Requires class trainer.");
        local_18 = 7;
        local_1c = 0;
        local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
        u16string_assignPtrLen(L"resource1.dat",0xd);
        local_8._0_1_ = 0x13;
        uVar2 = u16_ostrstream_str_wrap(local_74);
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0x3f800000;
        local_5c = 0x3f800000;
        local_58 = 0x3f800000;
        local_54 = 0x3f800000;
        local_50 = 0x3f800000;
        local_8._0_1_ = 0x14;
        AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,(float)iVar8,0x41200000,0x40000000,&local_5c,
                     &local_4c,&local_3c,0,0xbf800000,1);
        if (7 < local_60) {
          operator_delete(local_74[0]);
        }
        local_60 = 7;
        local_64 = 0;
        local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
        local_8._0_1_ = 3;
        if (7 < local_18) {
          operator_delete(local_2c);
        }
        local_18 = 7;
        local_1c = 0;
        local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
        u16string_assignPtrLen(L"resource1.dat",0xd);
        local_8._0_1_ = 0x15;
        uVar2 = u16_ostrstream_str_wrap(local_74);
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_5c = 0x3f800000;
        local_58 = 0x3e800000;
        local_54 = 0x3e800000;
        local_50 = 0x3f800000;
        local_8._0_1_ = 0x16;
        AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x41700000,(float)iVar8,0x41200000,0,&local_5c,&local_4c,
                     &local_3c,0,0xbf800000,1);
        if (7 < local_60) {
          operator_delete(local_74[0]);
        }
        local_60 = 7;
        local_64 = 0;
        local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
        local_8._0_1_ = 3;
        if (7 < local_18) {
          operator_delete(local_2c);
        }
        local_a5 = '\0';
      }
    }
    iVar8 = iVar8 + 0x14;
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    u16string_assignPtrLen(&PTR_006fccac,0);
    local_8._0_1_ = 0x17;
    strstreambuf_tidy();
    puVar6 = &local_2c;
    if (7 < local_18) {
      puVar6 = local_2c;
    }
    strstreambuf_init(puVar6,local_1c,local_114);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    puVar18 = &DAT_006ffd80;
    pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_158,iVar7 % 100);
    wostream_insertNarrow(pbVar5,puVar18);
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    u16string_assignPtrLen(L"resource1.dat",0xd);
    local_8._0_1_ = 0x18;
    uVar2 = u16_ostrstream_str_wrap(local_74);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x19;
    AdaptionWidget_draw_text_locked(&local_2c,uVar2,0,0,0x435c0000,(float)iVar8,0x41200000,0x40000000,&local_5c,
                 &local_4c,&local_3c,2,0xbf800000,1);
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    local_60 = 7;
    local_64 = 0;
    local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x1a;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_5c = 0x3f4ccccd;
    local_58 = 0x3f000000;
    local_54 = 0;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x1b;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x435c0000,(float)iVar8,0x41200000,0,&local_5c,&local_4c,
                 &local_3c,2,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x1c;
    strstreambuf_tidy();
    puVar6 = &local_2c;
    if (7 < local_18) {
      puVar6 = local_2c;
    }
    strstreambuf_init(puVar6,local_1c,local_114);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    puVar18 = &DAT_006ffd84;
    pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_158,local_b4);
    wostream_insertNarrow(pbVar5,puVar18);
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x1d;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x1e;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x43340000,(float)iVar8,0x41200000,0x40000000,&local_5c,
                 &local_4c,&local_3c,2,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x1f;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_5c = 0x3f333333;
    local_58 = 0x3f333333;
    local_54 = 0x3f333333;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x20;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x43340000,(float)iVar8,0x41200000,0,&local_5c,&local_4c,
                 &local_3c,2,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x21;
    strstreambuf_tidy();
    puVar6 = &local_2c;
    if (7 < local_18) {
      puVar6 = local_2c;
    }
    strstreambuf_init(puVar6,local_1c,local_114);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    puVar18 = &DAT_006ffd88;
    pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_158,local_b8);
    wostream_insertNarrow(pbVar5,puVar18);
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x22;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x23;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x430c0000,(float)iVar8,0x41200000,0x40000000,&local_5c,
                 &local_4c,&local_3c,2,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x24;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_5c = 0x3f800000;
    local_58 = 0x3f666666;
    local_54 = 0;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x25;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x430c0000,(float)iVar8,0x41200000,0,&local_5c,&local_4c,
                 &local_3c,2,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x26;
    strstreambuf_tidy();
    puVar6 = &local_2c;
    if (7 < local_18) {
      puVar6 = local_2c;
    }
    strstreambuf_init(puVar6,local_1c,local_114);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    wostream_insertNarrow(local_158,"COST:");
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x27;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x28;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x41700000,(float)iVar8,0x41200000,0x40000000,&local_5c,
                 &local_4c,&local_3c,0,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x29;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    local_8._0_1_ = 0x2a;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,0x41700000,(float)iVar8,0x41200000,0,&local_5c,&local_4c,
                 &local_3c,0,0xbf800000,1);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
  }
  if (local_ac._0_1_ != '\0') {
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x2b;
    strstreambuf_tidy();
    puVar6 = &local_2c;
    if (7 < local_18) {
      puVar6 = local_2c;
    }
    strstreambuf_init(puVar6,local_1c,local_114);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    wostream_insertNarrow(local_158,"Learn");
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x2c;
    uVar2 = u16_ostrstream_str_wrap(&local_2c);
    uVar19 = 1;
    local_3c = 0;
    uVar17 = 0xbf800000;
    uVar16 = 1;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0x3f800000;
    local_5c = 0x3f800000;
    local_58 = 0x3f800000;
    local_54 = 0x3f800000;
    local_50 = 0x3f800000;
    puVar6 = &local_3c;
    puVar15 = &local_4c;
    puVar14 = &local_5c;
    uVar13 = 0x40400000;
    local_8._0_1_ = 0x2d;
    uVar12 = 0x41400000;
    fVar10 = (float)security_cookie_guard_a(0x41400000,0x40400000,puVar14,puVar15,puVar6,1,0xbf800000,1);
    local_ac = (float)fVar10;
    fVar11 = local_ac - 20.0f;
    fVar10 = (float)security_cookie_guard_b(fVar11);
    local_ac = (float)fVar10;
    AdaptionWidget_draw_text_locked(local_8c,uVar2,0,0,local_ac / 3.0f,fVar11,uVar12,uVar13,puVar14,puVar15,puVar6,
                 uVar16,uVar17,uVar19);
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    local_18 = 7;
    local_1c = 0;
    local_2c = (undefined4 *)((uint)local_2c & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    if (local_a5 == '\0') {
      local_5c = 0x3f000000;
      local_58 = 0x3f000000;
      local_54 = 0x3f000000;
      local_50 = 0x3f800000;
      local_b0 = &local_5c;
    }
    else {
      cVar1 = GameController_questStateChanged();
      local_38 = 0x3f800000;
      local_34 = 0x3f800000;
      local_30 = 0x3f800000;
      local_3c = 0;
      if (cVar1 == '\0') {
        local_3c = 0x3f800000;
      }
      local_4c = local_3c;
      local_48 = 0x3f800000;
      local_44 = 0x3f800000;
      local_40 = 0x3f800000;
      local_b0 = &local_4c;
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x2e;
    uVar2 = u16_ostrstream_str_wrap(local_8c);
    uVar19 = 1;
    local_6c = 0;
    uVar17 = 0xbf800000;
    uVar16 = 1;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    puVar6 = &local_6c;
    puVar15 = &local_24;
    local_8._0_1_ = 0x2f;
    uVar13 = 0;
    uVar12 = 0x41400000;
    puVar14 = local_b0;
    fVar10 = (float)security_cookie_guard_a(0x41400000,0,local_b0,puVar15,puVar6,1,0xbf800000,1);
    local_ac = (float)fVar10;
    fVar11 = local_ac - 20.0f;
    fVar10 = (float)security_cookie_guard_b(fVar11);
    local_ac = (float)fVar10;
    AdaptionWidget_draw_text_locked(local_a4,uVar2,0,0,local_ac / 3.0f,fVar11,uVar12,uVar13,puVar14,puVar15,puVar6,
                 uVar16,uVar17,uVar19);
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    local_78 = 7;
    local_7c = 0;
    local_8c[0] = (void *)((uint)local_8c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_90) {
      operator_delete(local_a4[0]);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x30;
    strstreambuf_tidy();
    puVar6 = &local_2c;
    if (7 < local_18) {
      puVar6 = local_2c;
    }
    strstreambuf_init(puVar6,local_1c,local_114);
    local_8._0_1_ = 3;
    if (7 < local_18) {
      operator_delete(local_2c);
    }
    wostream_insertNarrow(local_158,"Cancel");
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x31;
    uVar2 = u16_ostrstream_str_wrap(local_8c);
    uVar19 = 1;
    local_24 = 0;
    uVar17 = 0xbf800000;
    uVar16 = 1;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_6c = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0x3f800000;
    local_3c = 0x3f800000;
    local_38 = 0x3f800000;
    local_34 = 0x3f800000;
    local_30 = 0x3f800000;
    puVar6 = &local_24;
    puVar15 = &local_6c;
    puVar14 = &local_3c;
    uVar13 = 0x40400000;
    local_8._0_1_ = 0x32;
    uVar12 = 0x41400000;
    fVar10 = (float)security_cookie_guard_a(0x41400000,0x40400000,puVar14,puVar15,puVar6,1,0xbf800000,1);
    local_ac = (float)fVar10;
    fVar11 = local_ac - 20.0f;
    fVar10 = (float)security_cookie_guard_b(fVar11);
    local_ac = (float)fVar10;
    AdaptionWidget_draw_text_locked(local_a4,uVar2,0,0,(local_ac * 2.0f) / 3.0f,fVar11,uVar12,uVar13,puVar14,puVar15,
                 puVar6,uVar16,uVar17,uVar19);
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    local_78 = 7;
    local_7c = 0;
    local_8c[0] = (void *)((uint)local_8c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_90) {
      operator_delete(local_a4[0]);
    }
    cVar1 = GameController_terrainStateChanged();
    if (cVar1 == '\0') {
      local_6c = 0x3f800000;
      local_68 = 0x3f800000;
      local_64 = 0x3f800000;
      local_60 = 0x3f800000;
      local_b0 = &local_6c;
    }
    else {
      local_24 = 0;
      local_20 = 0x3f800000;
      local_1c = 0x3f800000;
      local_18 = 0x3f800000;
      local_b0 = &local_24;
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x33;
    uVar2 = u16_ostrstream_str_wrap(local_8c);
    uVar19 = 1;
    local_3c = 0;
    uVar17 = 0xbf800000;
    uVar16 = 1;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    puVar6 = &local_3c;
    puVar15 = &local_4c;
    local_8._0_1_ = 0x34;
    uVar13 = 0;
    uVar12 = 0x41400000;
    puVar14 = local_b0;
    fVar10 = (float)security_cookie_guard_a(0x41400000,0,local_b0,puVar15,puVar6,1,0xbf800000,1);
    local_ac = (float)fVar10;
    fVar11 = local_ac - 20.0f;
    fVar10 = (float)security_cookie_guard_b(fVar11);
    local_ac = (float)fVar10;
    AdaptionWidget_draw_text_locked(local_a4,uVar2,0,0,(local_ac * 2.0f) / 3.0f,fVar11,uVar12,uVar13,puVar14,puVar15,
                 puVar6,uVar16,uVar17,uVar19);
    if (7 < local_78) {
      operator_delete(local_8c[0]);
    }
    local_78 = 7;
    local_7c = 0;
    local_8c[0] = (void *)((uint)local_8c[0] & 0xffff0000);
    if (7 < local_90) {
      operator_delete(local_a4[0]);
    }
  }
  ctor_18();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::eh_catchall_004e0130 @ 004e0130 */

void Catch_All_004e0130(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004e022d @ 004e022d */

void Catch_All_004e022d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004e02e5 @ 004e02e5 */

void Catch_All_004e02e5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004e03a2 @ 004e03a2 */

void Catch_All_004e03a2(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_004e04df @ 004e04df */

void Catch_All_004e04df(void)

{
  int unaff_EBP;
  
  rbtree_destroyRecursive(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e0d98 @ 004e0d98 */

void Catch_All_004e0d98(void)

{
  int unaff_EBP;
  
  node_free(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e0fc4 @ 004e0fc4 */

void Catch_All_004e0fc4(void)

{
  int unaff_EBP;
  
  node_release_free(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e11b4 @ 004e11b4 */

void Catch_All_004e11b4(void)

{
  int unaff_EBP;
  
  QuestText_delete_node(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e12a8 @ 004e12a8 */

void Catch_All_004e12a8(void)

{
  int unaff_EBP;
  
  node_free(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e1460 @ 004e1460 */

void Catch_All_004e1460(void)

{
  int unaff_EBP;
  
  node_release_free(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e15c4 @ 004e15c4 */

void Catch_All_004e15c4(void)

{
  int unaff_EBP;
  
  QuestText_delete_node(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e1669 @ 004e1669 */

void Catch_All_004e1669(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase_46eb20(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e175d @ 004e175d */

void Catch_All_004e175d(void)

{
  listNode_free_ownsString();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e1806 @ 004e1806 */

void Catch_All_004e1806(void)

{
  int unaff_EBP;
  
  Zone_rbtree_eraseRange(unaff_EBP + 8,*(undefined4 *)**(undefined4 **)(unaff_EBP + -0x18),
               (undefined4 *)**(undefined4 **)(unaff_EBP + -0x18));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e18a6 @ 004e18a6 */

void Catch_All_004e18a6(void)

{
  int unaff_EBP;
  
  std_map_eraseRange_661a20(unaff_EBP + 8,*(undefined4 *)**(undefined4 **)(unaff_EBP + -0x18),
               (undefined4 *)**(undefined4 **)(unaff_EBP + -0x18));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004e194f @ 004e194f */

void Catch_All_004e194f(void)

{
  listNode_free_ownsString();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: node_free  (confidence: med)
 * purpose: operator delete a container node
 * vars: in_ECX=node
 */
/* Global::node_free @ 004e34f0 */

void node_free(void *param_1)

{
  if (7 < *(uint *)((int)param_1 + 0x28)) {
    operator_delete(*(void **)((int)param_1 + 0x14));
  }
  *(undefined4 *)((int)param_1 + 0x28) = 7;
  *(undefined4 *)((int)param_1 + 0x24) = 0;
  *(undefined2 *)((int)param_1 + 0x14) = 0;
  operator_delete(param_1);
}




/* [AUDIT] proposed: node_release_free  (confidence: med)
 * purpose: Release node payload (unwind_delete_member) then operator delete
 * vars: -
 */
/* Global::node_release_free @ 004e3530 */

void node_release_free(void *param_1)

{
  unwind_delete_member();
  operator_delete(param_1);
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_24 @ 004e5740 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_24
               (undefined4 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *in_ECX;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  undefined8 *in_stack_0000001c;
  undefined **local_12c [3];
  int iStack_120;
  undefined *local_11c;
  undefined **local_114 [2];
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> local_10c [72];
  code *local_c4 [18];
  undefined8 local_7c;
  void *local_74 [4];
  undefined4 local_64;
  uint local_60;
  undefined8 local_5c;
  void *local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined8 local_3c;
  undefined8 local_34;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9d6d;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_12c[0] = &PTR_006fcd00;
  local_11c = &DAT_006fcd08;
  local_c4[0] = _vftable__exref;
  local_8 = 1;
  local_5c = CONCAT44(1,(undefined4)local_5c);
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_12c,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_114);
  local_8 = 2;
  *(undefined ***)((int)local_12c + (int)local_12c[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)local_114 + (int)(local_12c[0][1] + -0x1c)) = local_12c[0][1] + -0x68;
  local_7c = CONCAT44((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_114,
                      (undefined4)local_7c);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_114);
  puVar3 = &param_1;
  if (7 < in_stack_00000018) {
    puVar3 = param_1;
  }
  local_8._0_1_ = 3;
  local_114[0] = vftable;
  strstreambuf_init(puVar3,in_stack_00000014,0);
  puVar2 = in_stack_0000001c;
  local_8._0_1_ = 4;
  iVar1 = *(int *)((int)&iStack_120 + (int)local_12c[0][1]);
  while( true ) {
    if (iVar1 != 0) {
      local_8._0_1_ = 4;
      *(undefined ***)((int)local_12c + (int)local_12c[0][1]) =
           basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
      *(undefined **)((int)local_114 + (int)(local_12c[0][1] + -0x1c)) = local_12c[0][1] + -0x68;
      local_114[0] = vftable;
      strstreambuf_tidy();
      std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
      ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
                ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_114);
      std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
      ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>(local_10c);
      std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
      ~basic_ios<wchar_t,std::char_traits<wchar_t>_>
                ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)local_c4);
      if (7 < in_stack_00000018) {
        operator_delete(param_1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_18 = 7;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
    local_8._0_1_ = 5;
    std_operator_wistream_wstring(local_12c,local_2c);
    local_7c = *puVar2;
    local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
    local_5c = puVar2[1];
    local_60 = 7;
    local_64 = 0;
    u16string_replaceRange(local_2c,0,0xffffffff);
    local_54[0] = (void *)((uint)local_54[0] & 0xffff0000);
    local_8._0_1_ = 6;
    local_40 = 7;
    local_44 = 0;
    u16string_replaceRange(local_74,0,0xffffffff);
    local_3c = local_7c;
    local_34 = local_5c;
    if (7 < local_60) {
      operator_delete(local_74[0]);
    }
    local_60 = 7;
    local_64 = 0;
    local_74[0] = (void *)((uint)local_74[0] & 0xffff0000);
    iVar1 = *in_ECX;
    local_8._0_1_ = 7;
    iVar4 = rbtree_allocNode_strVec(iVar1,*(undefined4 *)(iVar1 + 4),local_54);
    if (in_ECX[1] == 0x5555554) break;
    in_ECX[1] = in_ECX[1] + 1;
    *(int *)(iVar1 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    if (7 < local_40) {
      operator_delete(local_54[0]);
    }
    local_8._0_1_ = 4;
    if (7 < local_18) {
      operator_delete(local_2c[0]);
    }
    iVar1 = *(int *)((int)&iStack_120 + (int)local_12c[0][1]);
  }
  std::_Xlength_error("list<T> too long");
}




/* Global::eh_catchall_004ebb21 @ 004ebb21 */

void Catch_All_004ebb21(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_004ebf28 @ 004ebf28 */

void Catch_All_004ebf28(void)

{
  int unaff_EBP;
  
  std_Tree_destroyHead(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_004ec05d @ 004ec05d */

void Catch_All_004ec05d(void)

{
  int unaff_EBP;
  
  std_Tree_destroyHead(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::operator_new_array @ 0055dc30 */

/* Library Function - Single Match
    void * __cdecl operator new[](unsigned int,enum FILL)
   
   Library: Visual Studio 2017 Release */

void * __cdecl operator_new__(uint param_1,FILL param_2)

{
  void *_Dst;
  
  _Dst = (void *)sqlite3_Malloc(param_1);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}




/* Global::eh_catchall_00583d5b @ 00583d5b */

void Catch_All_00583d5b(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  if (0xf < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 0xf;
  puVar1[4] = 0;
  *(undefined1 *)puVar1 = 0;
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_11 @ 00587460 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_11
               (undefined4 param_1)

{
  BOOL BVar1;
  int iVar2;
  int iStack_2f0;
  undefined **local_2ec [4];
  undefined *local_2dc [2];
  undefined **local_2d4 [2];
  basic_iostream<char,std::char_traits<char>_> local_2cc [48];
  undefined4 local_29c;
  undefined4 local_298;
  code *local_284 [18];
  DWORD local_23c;
  DWORD local_238;
  ulong local_234 [2];
  void *local_22c [5];
  uint local_218;
  CHAR local_214 [256];
  CHAR local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f13e6;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_234[1] = 0;
  BVar1 = GetVolumeInformationA
                    ((LPCSTR)0x0,local_114,0xff,local_234,&local_238,&local_23c,local_214,0xff);
  local_2ec[0] = &PTR_006fcd00;
  local_2dc[0] = &DAT_006fcd08;
  local_284[0] = _vftable__exref;
  local_8 = 0;
  local_234[1] = 2;
  std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
            ((basic_iostream<char,std::char_traits<char>_> *)local_2ec,
             (basic_streambuf<char,std::char_traits<char>_> *)local_2d4);
  local_8 = 1;
  *(undefined ***)((int)local_2ec + (int)local_2ec[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_2f0 + (int)local_2ec[0][1]) = local_2ec[0][1] + -0x68;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_2d4);
  local_2d4[0] = vftable;
  local_29c = 0;
  local_298 = 0;
  local_8 = 3;
  if (BVar1 != 0) {
    std::basic_ostream<char,std::char_traits<char>_>::operator<<
              ((basic_ostream<char,std::char_traits<char>_> *)local_2dc,local_234[0]);
  }
  iVar2 = ostrstream_str_wrap(local_22c);
  if (0xf < local_218) {
    operator_delete(local_22c[0]);
  }
  if (*(int *)(iVar2 + 0x10) == 0) {
    ostream_writePadded(local_2dc,"default");
  }
  ostrstream_str_wrap(param_1);
  *(undefined ***)((int)local_2ec + (int)local_2ec[0][1]) =
       basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined **)((int)&iStack_2f0 + (int)local_2ec[0][1]) = local_2ec[0][1] + -0x68;
  local_2d4[0] = vftable;
  strstreambuf_tidy();
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_2d4);
  std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
            (local_2cc);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)local_284);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::eh_catchall_0058cf4d @ 0058cf4d */

void Catch_All_0058cf4d(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0058e27f @ 0058e27f */

void Catch_All_0058e27f(void)

{
  int unaff_EBP;
  
  lib_fn_594760(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0058e4a4 @ 0058e4a4 */

void Catch_All_0058e4a4(void)

{
  int unaff_EBP;
  
  lib_fn_5947a0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0058e628 @ 0058e628 */

void Catch_All_0058e628(void)

{
  int unaff_EBP;
  
  lib_fn_594760(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0058e7ad @ 0058e7ad */

void Catch_All_0058e7ad(void)

{
  int unaff_EBP;
  
  lib_fn_5947a0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0058e8af @ 0058e8af */

void Catch_All_0058e8af(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0058e94c @ 0058e94c */

void Catch_All_0058e94c(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x188) {
    lib_fn_58e990(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::lib_fn_58e990 @ 0058e990 */

void lib_fn_58e990(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x48) != 0) {
    std_vector_destroy_ptr_elems_stride3(*(int *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),(int)&param_1 + 3,param_1)
    ;
    operator_delete(*(void **)(iVar1 + 0x48));
  }
  return;
}




/* Global::lib_fn_594760 @ 00594760 */

void lib_fn_594760(void *param_1)

{
  if (7 < *(uint *)((int)param_1 + 0x2c)) {
    operator_delete(*(void **)((int)param_1 + 0x18));
  }
  *(undefined4 *)((int)param_1 + 0x2c) = 7;
  *(undefined4 *)((int)param_1 + 0x28) = 0;
  *(undefined2 *)((int)param_1 + 0x18) = 0;
  operator_delete(param_1);
}




/* Global::lib_fn_5947a0 @ 005947a0 */

void lib_fn_5947a0(void *param_1)

{
  if (7 < *(uint *)((int)param_1 + 0x24)) {
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  *(undefined4 *)((int)param_1 + 0x24) = 7;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined2 *)((int)param_1 + 0x10) = 0;
  operator_delete(param_1);
}




/* Global::eh_catchall_005949ae @ 005949ae */

void Catch_All_005949ae(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_00594ab7 @ 00594ab7 */

void Catch_All_00594ab7(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::lib_fn_594bf0 @ 00594bf0 */

undefined2 * lib_fn_594bf0(undefined2 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x80011c);
  cVar1 = *(char *)((int)puVar2[1] + 0xd);
  puVar4 = puVar2;
  puVar6 = (undefined4 *)puVar2[1];
  while (cVar1 == '\0') {
    if ((int)puVar6[4] < (int)param_2) {
      puVar5 = (undefined4 *)puVar6[2];
      puVar6 = puVar4;
    }
    else {
      puVar5 = (undefined4 *)*puVar6;
    }
    puVar4 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0xd);
  }
  if ((puVar4 == puVar2) || (bVar3 = (int)param_2 < (int)puVar4[4], param_2 = puVar4, bVar3)) {
    param_2 = puVar2;
  }
  if (param_2 != puVar2) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    u16string_replaceRange(param_2 + 5,0,0xffffffff);
    return param_1;
  }
  u16string_assignCStr(&PTR_006fccac);
  return param_1;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_17 @ 005a4af0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_17
               (int param_1,int param_2)

{
  basic_ostream<char,std::char_traits<char>_> *pbVar1;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_1c4;
  undefined **local_1c0 [4];
  undefined *local_1b0 [2];
  undefined **local_1a8 [2];
  basic_iostream<char,std::char_traits<char>_> local_1a0 [4];
  undefined4 *local_19c;
  undefined4 *local_198;
  undefined4 *local_188;
  undefined4 *local_178;
  undefined4 local_170;
  uint local_16c;
  basic_ios<char,std::char_traits<char>_> local_158 [68];
  int iStack_114;
  undefined **local_110 [4];
  undefined *local_100 [2];
  undefined **local_f8 [2];
  basic_iostream<char,std::char_traits<char>_> local_f0 [4];
  undefined4 *local_ec;
  undefined4 *local_e8;
  undefined4 *local_d8;
  undefined4 *local_c8;
  undefined4 local_c0;
  uint local_bc;
  code *local_a8 [18];
  int local_60;
  void *local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  void *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  void *local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f3100;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = 0;
  if (((((*(char *)(in_ECX + 0xb4) == '\0') && (*(int *)(in_ECX + 0xa4) != 0)) && (-1 < param_1)) &&
      ((-1 < param_2 && (param_1 < 0x400)))) &&
     ((param_2 < 0x400 &&
      ((iVar5 = *(int *)(in_ECX + 0xbc + (param_1 * 0x400 + param_2) * 4), iVar5 != 0 &&
       (*(char *)(iVar5 + 0x15a18) != '\0')))))) {
    local_3c = in_ECX + 0xac;
    local_60 = (int)((param_2 * 0x40 >> 0x1f & 7U) + param_2 * 0x40) >> 3;
    local_34 = (int)(param_1 * 0x40 + (param_1 * 0x40 >> 0x1f & 7U)) >> 3;
    iVar5 = iVar5 + 0x1406c;
    local_38 = 8;
    local_30 = 0;
    do {
      iVar4 = 8;
      iVar6 = local_60;
      do {
        local_110[0] = &PTR_006fcd00;
        local_100[0] = &DAT_006fcd08;
        local_a8[0] = _vftable__exref;
        local_30 = local_30 | 1;
        local_8 = 0;
        std::basic_iostream<char,std::char_traits<char>_>::
        basic_iostream<char,std::char_traits<char>_>
                  ((basic_iostream<char,std::char_traits<char>_> *)local_110,
                   (basic_streambuf<char,std::char_traits<char>_> *)local_f8);
        local_8 = 1;
        *(undefined ***)((int)local_110 + (int)local_110[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&iStack_114 + (int)local_110[0][1]) = local_110[0][1] + -0x68;
        std::basic_streambuf<char,std::char_traits<char>_>::
        basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)local_f8);
        local_f8[0] = vftable;
        local_c0 = 0;
        local_bc = 0;
        local_8 = 3;
        iVar7 = local_34;
        iVar8 = iVar6;
        pbVar1 = (basic_ostream<char,std::char_traits<char>_> *)
                 ostream_writePadded(local_100,"mission",local_34,&DAT_0071c760);
        pbVar2 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar1,iVar7);
        pbVar1 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded(pbVar2);
        std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar1,iVar8);
        local_5c = (void *)0x0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        iVar7 = iVar5 + -0x28;
        local_8._0_1_ = 4;
        refcount_initTo1(&local_5c);
        serialize_struct_0x28(iVar7);
        uVar3 = ostrstream_str_wrap(local_2c);
        local_8._0_1_ = 5;
        db_storeBlobVec(uVar3,&local_5c);
        local_8._0_1_ = 4;
        if (0xf < local_18) {
          operator_delete(local_2c[0]);
        }
        local_1c0[0] = &PTR_006fcd00;
        local_1b0[0] = &DAT_006fcd08;
        std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
                  (local_158);
        local_30 = local_30 | 2;
        local_8 = CONCAT31(local_8._1_3_,6);
        std::basic_iostream<char,std::char_traits<char>_>::
        basic_iostream<char,std::char_traits<char>_>
                  ((basic_iostream<char,std::char_traits<char>_> *)local_1c0,
                   (basic_streambuf<char,std::char_traits<char>_> *)local_1a8);
        local_8 = 7;
        *(undefined ***)((int)local_1c0 + (int)local_1c0[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&iStack_1c4 + (int)local_1c0[0][1]) = local_1c0[0][1] + -0x68;
        std::basic_streambuf<char,std::char_traits<char>_>::
        basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)local_1a8);
        local_1a8[0] = vftable;
        local_170 = 0;
        local_16c = 0;
        local_8._0_1_ = 9;
        iVar7 = local_34;
        iVar8 = iVar6;
        pbVar1 = (basic_ostream<char,std::char_traits<char>_> *)
                 ostream_writePadded(local_1b0,"monster",local_34,&DAT_0071c760);
        pbVar2 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar1,iVar7);
        pbVar1 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded(pbVar2);
        std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar1,iVar8);
        local_4c = (void *)0x0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_8._0_1_ = 10;
        iVar7 = iVar5;
        refcount_initTo1(&local_4c);
        serialize_struct_small(iVar7);
        uVar3 = ostrstream_str_wrap(local_2c);
        local_8._0_1_ = 0xb;
        db_storeBlobVec(uVar3,&local_4c);
        if (0xf < local_18) {
          operator_delete(local_2c[0]);
        }
        if (local_4c != (void *)0x0) {
          operator_delete(local_4c);
        }
        local_8 = CONCAT31(local_8._1_3_,4);
        *(undefined ***)((int)local_1c0 + (int)local_1c0[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&iStack_1c4 + (int)local_1c0[0][1]) = local_1c0[0][1] + -0x68;
        local_1a8[0] = vftable;
        if ((local_16c & 1) != 0) {
          operator_delete((void *)*local_19c);
        }
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  ((basic_streambuf<char,std::char_traits<char>_> *)local_1a8,(char *)0x0,
                   (char *)0x0,(char *)0x0);
        *local_198 = 0;
        *local_188 = 0;
        *local_178 = 0;
        local_16c = local_16c & 0xfffffffe;
        local_170 = 0;
        std::basic_streambuf<char,std::char_traits<char>_>::
        ~basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)local_1a8);
        std::basic_iostream<char,std::char_traits<char>_>::
        ~basic_iostream<char,std::char_traits<char>_>(local_1a0);
        std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                  (local_158);
        if (local_5c != (void *)0x0) {
          operator_delete(local_5c);
        }
        local_8 = 0xffffffff;
        *(undefined ***)((int)local_110 + (int)local_110[0][1]) =
             basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
        *(undefined **)((int)&iStack_114 + (int)local_110[0][1]) = local_110[0][1] + -0x68;
        local_f8[0] = vftable;
        if ((local_bc & 1) != 0) {
          operator_delete((void *)*local_ec);
        }
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  ((basic_streambuf<char,std::char_traits<char>_> *)local_f8,(char *)0x0,(char *)0x0
                   ,(char *)0x0);
        *local_e8 = 0;
        *local_d8 = 0;
        *local_c8 = 0;
        local_bc = local_bc & 0xfffffffe;
        local_c0 = 0;
        std::basic_streambuf<char,std::char_traits<char>_>::
        ~basic_streambuf<char,std::char_traits<char>_>
                  ((basic_streambuf<char,std::char_traits<char>_> *)local_f8);
        std::basic_iostream<char,std::char_traits<char>_>::
        ~basic_iostream<char,std::char_traits<char>_>(local_f0);
        std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                  ((basic_ios<char,std::char_traits<char>_> *)local_a8);
        iVar5 = iVar5 + 0x68;
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      local_34 = local_34 + 1;
      local_38 = local_38 + -1;
    } while (local_38 != 0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_13 @ 005a5050 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_13(int param_1)

{
  uint uVar1;
  basic_ostream<char,std::char_traits<char>_> *pbVar2;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int iStack_f4;
  undefined **local_f0 [4];
  undefined *local_e0 [2];
  undefined **local_d8 [14];
  undefined4 local_a0;
  undefined4 local_9c;
  code *local_88;
  undefined4 local_40;
  void *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f3180;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = 0;
  local_14 = uVar1;
  if (((*(int *)(in_ECX + 0xa4) != 0) && (param_1 != 0)) &&
     ((*(char *)(param_1 + 0x75) != '\0' || (*(int *)(param_1 + 0x68) != *(int *)(param_1 + 0x6c))))
     ) {
    local_f0[0] = &PTR_006fcd00;
    local_e0[0] = &DAT_006fcd08;
    local_88 = _vftable__exref;
    local_8 = 0;
    local_40 = 1;
    std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
              ((basic_iostream<char,std::char_traits<char>_> *)local_f0,
               (basic_streambuf<char,std::char_traits<char>_> *)local_d8);
    local_8 = 1;
    *(undefined ***)((int)local_f0 + (int)local_f0[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_f4 + (int)local_f0[0][1]) = local_f0[0][1] + -0x68;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_d8);
    local_d8[0] = vftable;
    local_a0 = 0;
    local_9c = 0;
    iVar6 = *(int *)(param_1 + 100);
    iVar5 = *(int *)(param_1 + 0x60);
    local_8 = 3;
    pbVar2 = (basic_ostream<char,std::char_traits<char>_> *)
             ostream_writePadded(local_e0,&DAT_0071c764,iVar5,&DAT_0071c760,iVar6,uVar1);
    pbVar3 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar2,iVar5);
    pbVar2 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded(pbVar3);
    std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar2,iVar6);
    local_3c = (void *)0x0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_8._0_1_ = 4;
    refcount_initTo1(&local_3c);
    serialize_struct_creatures(param_1);
    uVar4 = ostrstream_str_wrap(local_2c);
    local_8 = CONCAT31(local_8._1_3_,5);
    db_storeBlobVec(uVar4,&local_3c);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    if (local_3c != (void *)0x0) {
      operator_delete(local_3c);
    }
    ctor_18();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_15 @ 005a52e0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_15
               (uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int iStack_100;
  undefined **local_fc [4];
  undefined *local_ec [2];
  undefined **local_e4 [2];
  basic_iostream<char,std::char_traits<char>_> local_dc [4];
  undefined4 *local_d8;
  undefined4 *local_d4;
  undefined4 *local_c4;
  undefined4 *local_b4;
  undefined4 local_ac;
  uint local_a8;
  code *local_94 [18];
  int local_4c;
  int local_48;
  void *local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f3208;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_4c = param_2;
  local_34 = 0;
  *(uint *)(in_ECX + 0x800164) = param_1;
  local_30 = in_ECX;
  srand(param_1);
  iVar2 = rand();
  *(int *)(in_ECX + 0x800188) = iVar2 % 100000;
  iVar2 = 4;
  piVar5 = (int *)(in_ECX + 0x800168);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 0x14;
  piVar5 = (int *)(local_30 + 0x80018c);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x8001dc);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x8001e4);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x8001ec);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x8001f4);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 8;
  piVar5 = (int *)(local_30 + 0x8001fc);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 6;
  piVar5 = (int *)(local_30 + 0x80021c);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 6;
  piVar5 = (int *)(local_30 + 0x800234);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 10;
  piVar5 = (int *)(local_30 + 0x80024c);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 4;
  piVar5 = (int *)(local_30 + 0x800274);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x800284);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 4;
  piVar5 = (int *)(local_30 + 0x800178);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x80028c);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  iVar2 = 2;
  piVar5 = (int *)(local_30 + 0x800294);
  do {
    iVar3 = rand();
    *piVar5 = iVar3 % 100000;
    iVar2 = iVar2 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar2 != 0);
  local_34 = 0x400;
  piVar5 = (int *)(local_30 + 0xbc);
  do {
    local_48 = 0x400;
    do {
      iVar2 = local_48;
      if (*piVar5 != 0) {
        if (*(char *)(local_30 + 0xb4) == '\0') {
          iVar2 = 0x10018;
          do {
            iVar3 = 0x40;
            do {
              ctor_13(*(undefined4 *)(*piVar5 + iVar2));
              iVar2 = iVar2 + 4;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          } while (iVar2 < 0x14018);
        }
        iVar2 = local_48;
        if ((undefined4 *)*piVar5 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar5)(1);
        }
        *piVar5 = 0;
      }
      if ((void *)piVar5[0x100000] != (void *)0x0) {
        operator_delete((void *)piVar5[0x100000]);
      }
      piVar5 = piVar5 + 1;
      local_48 = iVar2 + -1;
    } while (local_48 != 0);
    local_34 = local_34 + -1;
  } while (local_34 != 0);
  handle_freeMember4();
  iVar2 = local_4c;
  *(undefined4 *)(local_30 + 0x8000f0) = 0x4b002080;
  *(undefined4 *)(local_30 + 0x8000f4) = 0x4b002080;
  *(undefined4 *)(local_30 + 0x8000f8) = 0;
  if (local_30 + 0x94 != local_4c) {
    string_assignSubstr(local_4c,0,0xffffffff);
  }
  if ((*(char *)(local_30 + 0xb4) == '\0') && (*(int *)(local_30 + 0xa4) != 0)) {
    local_fc[0] = &PTR_006fcd00;
    local_ec[0] = &DAT_006fcd08;
    local_94[0] = _vftable__exref;
    local_8 = 0;
    local_34 = 1;
    std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
              ((basic_iostream<char,std::char_traits<char>_> *)local_fc,
               (basic_streambuf<char,std::char_traits<char>_> *)local_e4);
    local_8 = 1;
    *(undefined ***)((int)local_fc + (int)local_fc[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_100 + (int)local_fc[0][1]) = local_fc[0][1] + -0x68;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_e4);
    local_e4[0] = vftable;
    local_ac = 0;
    local_a8 = 0;
    local_8 = 3;
    uVar4 = ostream_writePadded(local_ec,"Save/world_",iVar2,&DAT_00701e5c);
    uVar4 = std_ostream_insert_string(uVar4);
    ostream_writePadded(uVar4);
    uVar4 = ostrstream_str_wrap(local_2c);
    local_8._0_1_ = 4;
    db_openBlobStore(uVar4);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    local_44 = (void *)0x0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_8._0_1_ = 5;
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
    string_assignPtrLen(&DAT_00715b40,4);
    local_8 = CONCAT31(local_8._1_3_,6);
    cVar1 = db_getBlobInto(local_2c,&local_44);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    if (cVar1 != '\0') {
      iVar3 = local_40 - (int)local_44;
      iVar2 = iVar3;
      if (local_38 + 4 <= iVar3) {
        *(undefined4 *)(local_30 + 0x800160) = *(undefined4 *)((int)local_44 + local_38);
        iVar2 = local_38 + 4;
      }
      local_38 = iVar3;
      if (iVar2 + 4 <= iVar3) {
        *(undefined4 *)(local_30 + 0x80015c) = *(undefined4 *)((int)local_44 + iVar2);
        local_38 = iVar2 + 4;
      }
    }
    if (local_44 != (void *)0x0) {
      operator_delete(local_44);
    }
    local_8 = 0xffffffff;
    *(undefined ***)((int)local_fc + (int)local_fc[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_100 + (int)local_fc[0][1]) = local_fc[0][1] + -0x68;
    local_e4[0] = vftable;
    if ((local_a8 & 1) != 0) {
      operator_delete((void *)*local_d8);
    }
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              ((basic_streambuf<char,std::char_traits<char>_> *)local_e4,(char *)0x0,(char *)0x0,
               (char *)0x0);
    *local_d4 = 0;
    *local_c4 = 0;
    *local_b4 = 0;
    local_a8 = local_a8 & 0xfffffffe;
    local_ac = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::
    ~basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_e4);
    std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
              (local_dc);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
              ((basic_ios<char,std::char_traits<char>_> *)local_94);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::lib_fn_5a5a60 @ 005a5a60 */

undefined2 * lib_fn_5a5a60(undefined2 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x800114);
  cVar1 = *(char *)((int)puVar2[1] + 0xd);
  puVar4 = puVar2;
  puVar6 = (undefined4 *)puVar2[1];
  while (cVar1 == '\0') {
    if ((int)puVar6[4] < (int)param_2) {
      puVar5 = (undefined4 *)puVar6[2];
      puVar6 = puVar4;
    }
    else {
      puVar5 = (undefined4 *)*puVar6;
    }
    puVar4 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0xd);
  }
  if ((puVar4 == puVar2) || (bVar3 = (int)param_2 < (int)puVar4[4], param_2 = puVar4, bVar3)) {
    param_2 = puVar2;
  }
  if (param_2 != puVar2) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    u16string_replaceRange(param_2 + 5,0,0xffffffff);
    return param_1;
  }
  u16string_assignCStr(&PTR_006fccac);
  return param_1;
}




/* Global::eh_catchall_005a6b48 @ 005a6b48 */

void Catch_All_005a6b48(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005a6c11 @ 005a6c11 */

void Catch_All_005a6c11(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005a6d7f @ 005a6d7f */

void Catch_All_005a6d7f(void)

{
  int unaff_EBP;
  
  rbtree_destroyRec_buf(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005a6e3f @ 005a6e3f */

void Catch_All_005a6e3f(void)

{
  int unaff_EBP;
  
  rbtree_destroyRec_buf(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005a74cc @ 005a74cc */

void Catch_All_005a74cc(void)

{
  int unaff_EBP;
  
  lib_fn_5a7bd0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005a7691 @ 005a7691 */

void Catch_All_005a7691(void)

{
  int unaff_EBP;
  
  lib_fn_5a7bd0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005a7876 @ 005a7876 */

void Catch_All_005a7876(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005a7a1f @ 005a7a1f */

void Catch_All_005a7a1f(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::lib_fn_5a7bd0 @ 005a7bd0 */

void lib_fn_5a7bd0(void *param_1)

{
  if (*(void **)((int)param_1 + 0x10) != (void *)0x0) {
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  operator_delete(param_1);
}




/* Global::eh_catchall_005adf30 @ 005adf30 */

void Catch_All_005adf30(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::lib_fn_5ae9f0 @ 005ae9f0 */

void lib_fn_5ae9f0(undefined4 *param_1)

{
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  return;
}




/* Global::eh_catchall_005aeb2c @ 005aeb2c */

void Catch_All_005aeb2c(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005aef74 @ 005aef74 */

void Catch_All_005aef74(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005af04c @ 005af04c */

void Catch_All_005af04c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005c00e3 @ 005c00e3 */

void Catch_All_005c00e3(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005c082f @ 005c082f */

void Catch_All_005c082f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_005c0ab5 @ 005c0ab5 */

void Catch_All_005c0ab5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_005c0c4e @ 005c0c4e */

void Catch_All_005c0c4e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_005c0dee @ 005c0dee */

void Catch_All_005c0dee(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_005c3756 @ 005c3756 */

void Catch_All_005c3756(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
    lib_fn_5ae9f0(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_005c4114 @ 005c4114 */

void Catch_All_005c4114(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005c4211 @ 005c4211 */

void Catch_All_005c4211(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005c42ff @ 005c42ff */

void Catch_All_005c42ff(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_005fbbed @ 005fbbed */

void Catch_All_005fbbed(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_2 @ 005fbc90 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_2(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int iStack_f4;
  undefined **local_f0 [4];
  undefined *local_e0 [2];
  undefined **local_d8 [14];
  undefined4 local_a0;
  undefined4 local_9c;
  code *local_88;
  undefined4 local_40;
  void *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4aa8;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = 0;
  WorldMap_ctor(local_14);
  if (*(int *)(*(int *)(in_ECX + 0xac) + 0xa4) != 0) {
    local_f0[0] = &PTR_006fcd00;
    local_e0[0] = &DAT_006fcd08;
    local_88 = _vftable__exref;
    local_8 = 0;
    local_40 = 1;
    std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
              ((basic_iostream<char,std::char_traits<char>_> *)local_f0,
               (basic_streambuf<char,std::char_traits<char>_> *)local_d8);
    local_8 = 1;
    *(undefined ***)((int)local_f0 + (int)local_f0[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_f4 + (int)local_f0[0][1]) = local_f0[0][1] + -0x68;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_d8);
    local_d8[0] = vftable;
    local_a0 = 0;
    local_9c = 0;
    local_8 = 3;
    uVar3 = ostream_writePadded(local_e0,"Save/map_",*(int *)(in_ECX + 0xac) + 0x94,&DAT_00701e5c);
    uVar3 = std_ostream_insert_string(uVar3);
    ostream_writePadded(uVar3);
    uVar3 = ostrstream_str_wrap(local_2c);
    local_8._0_1_ = 4;
    db_openBlobStore(uVar3);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    local_3c = (void *)0x0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_8._0_1_ = 5;
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
    string_assignPtrLen("discovered",10);
    local_8 = CONCAT31(local_8._1_3_,6);
    cVar2 = db_getBlobInto(local_2c,&local_3c);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    iVar1 = local_30;
    if (cVar2 != '\0') {
      iVar1 = local_38 - (int)local_3c;
      if (local_30 + 4 <= local_38 - (int)local_3c) {
        *(undefined4 *)(in_ECX + 0x8000bc) = *(undefined4 *)((int)local_3c + local_30);
        iVar1 = local_30 + 4;
      }
    }
    local_30 = iVar1;
    if (local_3c != (void *)0x0) {
      operator_delete(local_3c);
    }
    ctor_18();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::lib_fn_5fbed0 @ 005fbed0 */

void lib_fn_5fbed0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_1c;
  int local_14;
  int local_8;
  
  local_8 = -param_1;
  local_14 = 0;
  piVar5 = (int *)(in_ECX + 0xb0);
  do {
    local_1c = 0;
    iVar2 = -param_2;
    do {
      if (*piVar5 != 0) {
        iVar6 = 0;
        piVar8 = (int *)(*piVar5 + 8);
        do {
          iVar7 = 0;
          do {
            if (((*piVar8 != 0) &&
                (uVar3 = local_8 + iVar6 >> 0x1f, 10 < (int)((local_8 + iVar6 ^ uVar3) - uVar3))) ||
               (uVar3 = iVar2 + iVar7 >> 0x1f, 10 < (int)((iVar2 + iVar7 ^ uVar3) - uVar3))) {
              lib_fn_6022d0(local_14 + iVar6,local_1c + iVar7);
            }
            iVar7 = iVar7 + 1;
            piVar8 = piVar8 + 0xd;
          } while (iVar7 < 0x40);
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0x40);
      }
      local_1c = local_1c + 0x40;
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + 0x40;
    } while (local_1c < 0x10000);
    local_8 = local_8 + 0x40;
    local_14 = local_14 + 0x40;
  } while (local_14 < 0x10000);
  local_1c = 0;
  piVar5 = (int *)(&UNK_00400080.field_0x30 + in_ECX);
  do {
    iVar2 = 0;
    do {
      if (*piVar5 != 0) {
        uVar3 = local_1c - ((int)((param_1 >> 0x1f & 0x3fU) + param_1) >> 6);
        uVar4 = (int)uVar3 >> 0x1f;
        iVar6 = (uVar3 ^ uVar4) - uVar4;
        if ((8 < iVar6) ||
           (uVar3 = iVar2 - ((int)((param_2 >> 0x1f & 0x3fU) + param_2) >> 6),
           uVar4 = (int)uVar3 >> 0x1f, 8 < (int)((uVar3 ^ uVar4) - uVar4))) {
          cube::GameController::unloadZone(local_1c,iVar2);
        }
        if ((((8 < iVar6) ||
             (uVar3 = iVar2 - ((int)((param_2 >> 0x1f & 0x3fU) + param_2) >> 6),
             uVar4 = (int)uVar3 >> 0x1f, 8 < (int)((uVar3 ^ uVar4) - uVar4))) &&
            ((-1 < local_1c && (((-1 < iVar2 && (local_1c < 0x400)) && (iVar2 < 0x400)))))) &&
           (puVar1 = (undefined4 *)*piVar5, puVar1 != (undefined4 *)0x0)) {
          std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_14
                    (local_1c,iVar2);
          EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000c0));
          EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000d8));
          *piVar5 = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000d8));
          LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000c0));
          (**(code **)*puVar1)(1);
        }
      }
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 < 0x400);
    local_1c = local_1c + 1;
  } while (local_1c < 0x400);
  return;
}




/* Global::lib_fn_6022d0 @ 006022d0 */

void lib_fn_6022d0(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  if ((((-1 < (int)param_1) && (-1 < (int)param_2)) && ((int)param_1 < 0x10000)) &&
     (((int)param_2 < 0x10000 &&
      (iVar2 = *(int *)(in_ECX + 0xb0 +
                       (((int)(((int)param_1 >> 0x1f & 0x3fU) + param_1) >> 6) * 0x400 +
                       ((int)(param_2 + ((int)param_2 >> 0x1f & 0x3fU)) >> 6)) * 4), iVar2 != 0))))
  {
    param_1 = param_1 & 0x8000003f;
    if ((int)param_1 < 0) {
      param_1 = (param_1 - 1 | 0xffffffc0) + 1;
    }
    param_2 = param_2 & 0x8000003f;
    if ((int)param_2 < 0) {
      param_2 = (param_2 - 1 | 0xffffffc0) + 1;
    }
    iVar2 = (param_1 * 0x40 + param_2) * 0x34 + iVar2;
    puVar1 = *(undefined4 **)(iVar2 + 8);
    if (puVar1 != (undefined4 *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000c0));
      EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000d8));
      *(undefined4 *)(iVar2 + 8) = 0;
      list_clearSingleNode();
      LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000d8));
      LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x8000c0));
      (**(code **)*puVar1)(1);
    }
  }
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_3 @ 00603230 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_3
               (int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  basic_ostream<char,std::char_traits<char>_> *pbVar3;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined8 *puVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  void *pvVar16;
  undefined1 *puVar17;
  int iStack_114;
  undefined **local_110 [4];
  undefined *local_100 [2];
  undefined **local_f8 [2];
  basic_iostream<char,std::char_traits<char>_> local_f0 [4];
  undefined4 *local_ec;
  undefined4 *local_e8;
  undefined4 *local_d8;
  undefined4 *local_c8;
  undefined4 local_c0;
  uint local_bc;
  basic_ios<char,std::char_traits<char>_> local_a8 [72];
  int local_60;
  void *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  uint local_48;
  int local_44;
  int local_40;
  void *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined1 local_2c [24];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4c9b;
  local_10 = ExceptionList;
  uVar2 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = 0;
  local_60 = param_1;
  local_58 = param_2;
  local_14 = uVar2;
  if ((((*(int *)(*(int *)(in_ECX + 0xac) + 0xa4) != 0) && (-1 < param_1)) && (-1 < param_2)) &&
     (((param_1 < 0x400 && (param_2 < 0x400)) &&
      (param_2 = param_1 * 0x400 + 0x2c + param_2, local_4c = (int *)(in_ECX + param_2 * 4),
      *(int *)(in_ECX + param_2 * 4) == 0)))) {
    local_54 = in_ECX;
    local_5c = operator_new(0x35a00);
    local_8 = 0;
    if (local_5c == (void *)0x0) {
      local_50 = 0;
    }
    else {
      local_50 = cube::Zone::constructTileGrid(uVar2);
    }
    iVar13 = local_50;
    local_8 = 0xffffffff;
    local_110[0] = &PTR_006fcd00;
    local_100[0] = &DAT_006fcd08;
    std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_a8);
    local_8 = 1;
    local_44 = 1;
    std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
              ((basic_iostream<char,std::char_traits<char>_> *)local_110,
               (basic_streambuf<char,std::char_traits<char>_> *)local_f8);
    local_8 = 2;
    *(undefined ***)((int)local_110 + (int)local_110[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_114 + (int)local_110[0][1]) = local_110[0][1] + -0x68;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_f8);
    local_f8[0] = vftable;
    local_c0 = 0;
    local_bc = 0;
    local_8 = 4;
    iVar9 = param_1;
    iVar14 = local_58;
    pbVar3 = (basic_ostream<char,std::char_traits<char>_> *)
             ostream_writePadded(local_100,&DAT_0071e044,param_1,&DAT_0071c760);
    pbVar4 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar3,iVar9);
    pbVar3 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded(pbVar4);
    std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar3,iVar14);
    local_3c = (void *)0x0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_8._0_1_ = 5;
    uVar5 = ostrstream_str_wrap(local_2c);
    local_8._0_1_ = 6;
    cVar1 = db_getBlobInto(uVar5,&local_3c);
    local_8 = CONCAT31(local_8._1_3_,5);
    string_dtor();
    if (cVar1 != '\0') {
      stream_readBytes(&local_5c,4);
      puVar17 = (undefined1 *)(iVar13 + 0x10);
      local_44 = 0x40;
      do {
        iVar13 = 0x40;
        do {
          iVar9 = local_38 - (int)local_3c;
          if (local_30 + 1 <= iVar9) {
            puVar17[0x20] = *(undefined1 *)((int)local_3c + local_30);
            iVar9 = local_30 + 1;
          }
          iVar14 = local_38 - (int)local_3c;
          if (iVar9 + 1 <= iVar14) {
            *puVar17 = *(undefined1 *)((int)local_3c + iVar9);
            iVar14 = iVar9 + 1;
          }
          iVar9 = local_38 - (int)local_3c;
          if (iVar14 + 1 <= iVar9) {
            puVar17[1] = *(undefined1 *)((int)local_3c + iVar14);
            iVar9 = iVar14 + 1;
          }
          iVar14 = local_38 - (int)local_3c;
          if (iVar9 + 1 <= iVar14) {
            puVar17[2] = *(undefined1 *)((int)local_3c + iVar9);
            iVar14 = iVar9 + 1;
          }
          iVar9 = local_38 - (int)local_3c;
          if (iVar14 + 1 <= iVar9) {
            puVar17[3] = *(undefined1 *)((int)local_3c + iVar14);
            iVar9 = iVar14 + 1;
          }
          iVar14 = local_38 - (int)local_3c;
          if (iVar9 + 4 <= iVar14) {
            *(undefined4 *)(puVar17 + 4) = *(undefined4 *)((int)local_3c + iVar9);
            iVar14 = iVar9 + 4;
          }
          iVar9 = local_38 - (int)local_3c;
          if (iVar14 + 4 <= iVar9) {
            *(undefined4 *)(puVar17 + 8) = *(undefined4 *)((int)local_3c + iVar14);
            iVar9 = iVar14 + 4;
          }
          local_30 = local_38 - (int)local_3c;
          if (iVar9 + 1 <= local_30) {
            puVar17[0xc] = *(undefined1 *)((int)local_3c + iVar9);
            local_30 = iVar9 + 1;
          }
          puVar17 = puVar17 + 0x34;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        local_44 = local_44 + -1;
      } while (local_44 != 0);
      puVar6 = (undefined4 *)(local_50 + 0x3401c);
      local_44 = 8;
      do {
        iVar13 = 8;
        do {
          iVar9 = local_38 - (int)local_3c;
          if (local_30 + 4 <= iVar9) {
            puVar6[-1] = *(undefined4 *)((int)local_3c + local_30);
            iVar9 = local_30 + 4;
          }
          iVar14 = local_38 - (int)local_3c;
          if (iVar9 + 4 <= iVar14) {
            *puVar6 = *(undefined4 *)((int)local_3c + iVar9);
            iVar14 = iVar9 + 4;
          }
          iVar9 = local_38 - (int)local_3c;
          if (iVar14 + 4 <= iVar9) {
            puVar6[1] = *(undefined4 *)((int)local_3c + iVar14);
            iVar9 = iVar14 + 4;
          }
          iVar14 = local_38 - (int)local_3c;
          if (iVar9 + 4 <= iVar14) {
            puVar6[2] = *(undefined4 *)((int)local_3c + iVar9);
            iVar14 = iVar9 + 4;
          }
          iVar9 = local_38 - (int)local_3c;
          if (iVar14 + 4 <= iVar9) {
            puVar6[3] = *(undefined4 *)((int)local_3c + iVar14);
            iVar9 = iVar14 + 4;
          }
          iVar14 = local_38 - (int)local_3c;
          if (iVar9 + 4 <= iVar14) {
            puVar6[-2] = *(undefined4 *)((int)local_3c + iVar9);
            iVar14 = iVar9 + 4;
          }
          iVar9 = local_38 - (int)local_3c;
          if (iVar14 + 0x10 <= iVar9) {
            *(undefined8 *)(puVar6 + -7) = *(undefined8 *)((int)local_3c + iVar14);
            *(undefined8 *)(puVar6 + -5) = *(undefined8 *)((int)local_3c + iVar14 + 8);
            iVar9 = iVar14 + 0x10;
          }
          local_30 = local_38 - (int)local_3c;
          if (iVar9 + 4 <= local_30) {
            puVar6[-3] = *(undefined4 *)((int)local_3c + iVar9);
            local_30 = iVar9 + 4;
          }
          puVar6 = puVar6 + 0x1a;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        local_44 = local_44 + -1;
      } while (local_44 != 0);
      local_44 = 0;
      param_1 = local_60;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(local_54 + 0x8000d8));
    *local_4c = local_50;
    uVar7 = local_58 * 0x40;
    uVar10 = param_1 * 0x40;
    local_48 = 0;
    uVar2 = uVar10;
    do {
      local_40 = 0;
      uVar15 = uVar7;
      do {
        if (((-1 < (int)uVar2) && (-1 < (int)uVar15)) &&
           (((int)uVar2 < 0x10000 && ((int)uVar15 < 0x10000)))) {
          iVar9 = (int)(((int)uVar15 >> 0x1f & 0x3fU) + uVar15) >> 6;
          iVar13 = (int)(((int)uVar2 >> 0x1f & 0x3fU) + uVar2) >> 6;
          if ((((-1 < iVar13) && (-1 < iVar9)) && (iVar13 < 0x400)) &&
             ((iVar9 < 0x400 &&
              (iVar13 = *(int *)(*(int *)(local_54 + 0xac) + 0xbc + (iVar13 * 0x400 + iVar9) * 4),
              iVar13 != 0)))) {
            uVar11 = uVar2 & 0x8000003f;
            if ((int)uVar11 < 0) {
              uVar11 = (uVar11 - 1 | 0xffffffc0) + 1;
            }
            uVar8 = uVar15 & 0x8000003f;
            if ((int)uVar8 < 0) {
              uVar8 = (uVar8 - 1 | 0xffffffc0) + 1;
            }
            puVar12 = (undefined8 *)((uVar11 * 0x40 + uVar8) * 0x10 + 0x18 + iVar13);
            if (puVar12 != (undefined8 *)0x0) {
              iVar13 = (local_40 + local_48) * 0x34;
              *(undefined8 *)(iVar13 + 0x10 + local_50) = *puVar12;
              *(undefined8 *)(iVar13 + 0x18 + local_50) = puVar12[1];
            }
          }
        }
        local_40 = local_40 + 1;
        uVar15 = uVar15 + 1;
      } while (local_40 < 0x40);
      local_48 = local_48 + 0x40;
      uVar2 = uVar2 + 1;
    } while ((int)local_48 < 0x1000);
    local_44 = 0x800;
    local_5c = (void *)((int)(((int)uVar7 >> 0x1f & 7U) + uVar7) >> 3);
    uVar2 = (int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3;
    local_4c = (int *)(uVar2 * 8);
    do {
      local_40 = (int)local_5c * 8;
      iVar13 = 0;
      pvVar16 = local_5c;
      local_48 = uVar2;
      do {
        if (((-1 < (int)uVar2) && (-1 < (int)pvVar16)) &&
           (((int)uVar2 < 0x2000 && ((int)pvVar16 < 0x2000)))) {
          iVar14 = (int)((local_40 >> 0x1f & 0x3fU) + local_40) >> 6;
          iVar9 = (int)(((int)local_4c >> 0x1f & 0x3fU) + (int)local_4c) >> 6;
          uVar2 = local_48;
          if ((((-1 < iVar9) && (-1 < iVar14)) && (iVar9 < 0x400)) &&
             ((iVar14 < 0x400 &&
              (iVar9 = *(int *)(*(int *)(local_54 + 0xac) + 0xbc + (iVar9 * 0x400 + iVar14) * 4),
              iVar9 != 0)))) {
            uVar7 = local_48 & 0x80000007;
            if ((int)uVar7 < 0) {
              uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
            }
            uVar10 = (uint)pvVar16 & 0x80000007;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
            }
            iVar9 = (uVar10 + uVar7 * 8) * 0x68 + 0x14018 + iVar9;
            if (iVar9 != 0) {
              FUN_005fb9f0(iVar9);
              uVar2 = local_48;
            }
          }
        }
        iVar13 = iVar13 + 1;
        local_40 = local_40 + 8;
        pvVar16 = (void *)((int)pvVar16 + 1);
      } while (iVar13 < 8);
      local_4c = local_4c + 2;
      local_44 = local_44 + 8;
      uVar2 = uVar2 + 1;
    } while (local_44 < 0x840);
    local_48 = uVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_54 + 0x8000d8));
    ctor_16(local_60,local_58);
    if (local_3c != (void *)0x0) {
      operator_delete(local_3c);
    }
    local_8 = 0xffffffff;
    *(undefined ***)((int)local_110 + (int)local_110[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_114 + (int)local_110[0][1]) = local_110[0][1] + -0x68;
    local_f8[0] = vftable;
    if ((local_bc & 1) != 0) {
      operator_delete((void *)*local_ec);
    }
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              ((basic_streambuf<char,std::char_traits<char>_> *)local_f8,(char *)0x0,(char *)0x0,
               (char *)0x0);
    *local_e8 = 0;
    *local_d8 = 0;
    *local_c8 = 0;
    local_bc = local_bc & 0xfffffffe;
    local_c0 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::
    ~basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_f8);
    std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
              (local_f0);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_a8)
    ;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_14 @ 006050b0 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_14
               (int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  char cVar3;
  basic_ostream<char,std::char_traits<char>_> *pbVar4;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  int iStack_108;
  undefined **local_104 [4];
  undefined *local_f4 [2];
  undefined **local_ec [14];
  undefined4 local_b4;
  undefined4 local_b0;
  basic_ios<char,std::char_traits<char>_> local_9c [72];
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  void *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  void *local_2c [3];
  void *local_20;
  int iStack_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4e30;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = param_1;
  local_40 = param_2;
  local_48 = 0;
  cVar3 = handle_isOpen(local_14);
  if (((cVar3 != '\0') &&
      (iVar1 = *(int *)(in_ECX + 0x4000b0 + (param_1 * 0x400 + local_40) * 4), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x2c) != 0)) {
    local_104[0] = &PTR_006fcd00;
    local_f4[0] = &DAT_006fcd08;
    std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_9c);
    local_8 = 0;
    local_48 = 1;
    std::basic_iostream<char,std::char_traits<char>_>::basic_iostream<char,std::char_traits<char>_>
              ((basic_iostream<char,std::char_traits<char>_> *)local_104,
               (basic_streambuf<char,std::char_traits<char>_> *)local_ec);
    local_8 = 1;
    *(undefined ***)((int)local_104 + (int)local_104[0][1]) =
         basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(undefined **)((int)&iStack_108 + (int)local_104[0][1]) = local_104[0][1] + -0x68;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)local_ec);
    local_ec[0] = vftable;
    local_b4 = 0;
    local_b0 = 0;
    local_8 = 3;
    iVar7 = local_44;
    iVar8 = local_40;
    pbVar4 = (basic_ostream<char,std::char_traits<char>_> *)
             ostream_writePadded(local_f4,&DAT_0071e03c,local_44,&DAT_0071c760);
    pbVar5 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar4,iVar7);
    pbVar4 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded(pbVar5);
    std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar4,iVar8);
    local_3c = (void *)0x0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_8._0_1_ = 4;
    Vector_Resize(4);
    *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(in_ECX + 0x8000f8);
    local_30 = local_30 + 4;
    Vector_Resize((local_38 - (int)local_3c) + 8);
    *(undefined8 *)((int)local_3c + local_30) = *(undefined8 *)(iVar1 + 0x20);
    local_30 = local_30 + 8;
    Vector_Resize((local_38 - (int)local_3c) + 1);
    *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar1 + 0x28);
    local_30 = local_30 + 1;
    iVar7 = *(int *)(iVar1 + 0x2c);
    local_44 = *(int *)(iVar7 + 0x4c);
    pvVar2 = *(void **)(iVar7 + 0x44);
    local_48 = *(int *)(iVar7 + 0x48);
    local_20 = pvVar2;
    iStack_1c = local_48;
    Vector_Resize((local_38 - (int)local_3c) + 0xc);
    *(ulonglong *)((int)local_3c + local_30) = CONCAT44(iStack_1c,local_20);
    *(int *)((int)local_3c + local_30 + 8) = local_44;
    local_30 = local_30 + 0xc;
    if (((0 < (int)pvVar2) && (0 < local_48)) && (0 < local_44)) {
      Vector_ConstructResize((int)pvVar2 * local_48 * local_44 * 3);
      memcpy(local_20,*(void **)(*(int *)(iVar1 + 0x2c) + 0x30),iStack_1c - (int)local_20);
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_8._0_1_ = 6;
      FUN_005fc0d0(&local_20,&local_54);
      iVar7 = local_54;
      local_40 = local_50 - local_54;
      buffer_append_bytes(&local_40,4);
      buffer_append_bytes(iVar7,local_40);
      unwind_free_object();
      local_8._0_1_ = 4;
      unwind_free_object();
    }
    Vector_Resize((local_38 - (int)local_3c) + 0x1c);
    memcpy((void *)((int)local_3c + local_30),(void *)(iVar1 + 4),0x1c);
    local_30 = local_30 + 0x1c;
    uVar6 = ostrstream_str_wrap(local_2c);
    local_8 = CONCAT31(local_8._1_3_,7);
    db_storeBlobVec(uVar6,&local_3c);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    if (local_3c != (void *)0x0) {
      operator_delete(local_3c);
    }
    ctor_18();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_16 @ 00605420 */

void std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_16
               (int param_1,int param_2)

{
  char cVar1;
  basic_ostream<char,std::char_traits<char>_> *pbVar2;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  undefined8 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iStack_100;
  undefined **local_fc [4];
  undefined *local_ec [2];
  undefined **local_e4 [2];
  basic_iostream<char,std::char_traits<char>_> local_dc [4];
  undefined4 *local_d8;
  undefined4 *local_d4;
  undefined4 *local_c4;
  undefined4 *local_b4;
  undefined4 local_ac;
  uint local_a8;
  basic_ios<char,std::char_traits<char>_> local_94 [72];
  int local_4c;
  undefined4 local_48;
  int local_44;
  int *local_40;
  void *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  void *local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4eb0;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = in_ECX + 0x8000f0;
  local_4c = param_2;
  local_48 = 0;
  cVar1 = handle_isOpen(local_14);
  if (cVar1 != '\0') {
    iVar7 = param_2 + 0x2c + param_1 * 0x400;
    piVar8 = (int *)(in_ECX + iVar7 * 4);
    local_40 = piVar8;
    if (*(int *)(in_ECX + iVar7 * 4) != 0) {
      local_fc[0] = &PTR_006fcd00;
      local_ec[0] = &DAT_006fcd08;
      std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
                (local_94);
      local_8 = 0;
      local_48 = 1;
      std::basic_iostream<char,std::char_traits<char>_>::
      basic_iostream<char,std::char_traits<char>_>
                ((basic_iostream<char,std::char_traits<char>_> *)local_fc,
                 (basic_streambuf<char,std::char_traits<char>_> *)local_e4);
      local_8 = 1;
      *(undefined ***)((int)local_fc + (int)local_fc[0][1]) =
           basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(undefined **)((int)&iStack_100 + (int)local_fc[0][1]) = local_fc[0][1] + -0x68;
      std::basic_streambuf<char,std::char_traits<char>_>::
      basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)local_e4);
      local_e4[0] = vftable;
      local_ac = 0;
      local_a8 = 0;
      local_8 = 3;
      iVar7 = local_4c;
      pbVar2 = (basic_ostream<char,std::char_traits<char>_> *)
               ostream_writePadded(local_ec,&DAT_0071e044,param_1,&DAT_0071c760);
      pbVar3 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar2,param_1);
      pbVar2 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded(pbVar3);
      std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar2,iVar7);
      local_3c = (void *)0x0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_8 = CONCAT31(local_8._1_3_,4);
      Vector_Resize(4);
      *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(in_ECX + 0x8000f8);
      local_30 = local_30 + 4;
      iVar7 = 0;
      do {
        iVar5 = 0x40;
        do {
          iVar9 = *piVar8 + iVar7;
          Vector_Resize((local_38 - (int)local_3c) + 1);
          *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar9 + 0x30);
          local_30 = local_30 + 1;
          Vector_Resize((local_38 - (int)local_3c) + 1);
          *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar9 + 0x10);
          local_30 = local_30 + 1;
          Vector_Resize((local_38 - (int)local_3c) + 1);
          *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar9 + 0x11);
          local_30 = local_30 + 1;
          Vector_Resize((local_38 - (int)local_3c) + 1);
          *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar9 + 0x12);
          local_30 = local_30 + 1;
          Vector_Resize((local_38 - (int)local_3c) + 1);
          *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar9 + 0x13);
          local_30 = local_30 + 1;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(iVar9 + 0x14);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(iVar9 + 0x18);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 1);
          *(undefined1 *)((int)local_3c + local_30) = *(undefined1 *)(iVar9 + 0x1c);
          local_30 = local_30 + 1;
          iVar7 = iVar7 + 0x34;
          iVar5 = iVar5 + -1;
          piVar8 = local_40;
        } while (iVar5 != 0);
      } while (iVar7 < 0x34000);
      iVar7 = 0x34000;
      do {
        iVar5 = 8;
        do {
          puVar6 = (undefined8 *)(*local_40 + iVar7);
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(puVar6 + 3);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)((int)puVar6 + 0x1c);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(puVar6 + 4);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)((int)puVar6 + 0x24);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(puVar6 + 5);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)((int)puVar6 + 0x14);
          local_30 = local_30 + 4;
          Vector_Resize((local_38 - (int)local_3c) + 0x10);
          *(undefined8 *)((int)local_3c + local_30) = *puVar6;
          *(undefined8 *)((int)local_3c + local_30 + 8) = puVar6[1];
          local_30 = local_30 + 0x10;
          Vector_Resize((local_38 - (int)local_3c) + 4);
          iVar7 = iVar7 + 0x68;
          *(undefined4 *)((int)local_3c + local_30) = *(undefined4 *)(puVar6 + 2);
          local_30 = local_30 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      } while (iVar7 < 0x35a00);
      uVar4 = ostrstream_str_wrap(local_2c);
      local_8 = CONCAT31(local_8._1_3_,5);
      db_storeBlobVec(uVar4,&local_3c);
      if (0xf < local_18) {
        operator_delete(local_2c[0]);
      }
      if (local_3c != (void *)0x0) {
        operator_delete(local_3c);
      }
      local_8 = 0xffffffff;
      *(undefined ***)((int)local_fc + (int)local_fc[0][1]) =
           basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(undefined **)((int)&iStack_100 + (int)local_fc[0][1]) = local_fc[0][1] + -0x68;
      local_e4[0] = vftable;
      if ((local_a8 & 1) != 0) {
        operator_delete((void *)*local_d8);
      }
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)local_e4,(char *)0x0,(char *)0x0,
                 (char *)0x0);
      *local_d4 = 0;
      *local_c4 = 0;
      *local_b4 = 0;
      local_a8 = local_a8 & 0xfffffffe;
      local_ac = 0;
      std::basic_streambuf<char,std::char_traits<char>_>::
      ~basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)local_e4);
      std::basic_iostream<char,std::char_traits<char>_>::
      ~basic_iostream<char,std::char_traits<char>_>(local_dc);
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_94);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::eh_catchall_00608b12 @ 00608b12 */

void Catch_All_00608b12(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_00608b8c @ 00608b8c */

void Catch_All_00608b8c(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00608d1f @ 00608d1f */

void Catch_All_00608d1f(void)

{
  int unaff_EBP;
  
  rbtree_destroyRec_simple(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00608e37 @ 00608e37 */

void Catch_All_00608e37(void)

{
  int unaff_EBP;
  int iVar1;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 != *(int *)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      iVar1 = iVar1 + 0x10;
    } while (iVar1 != *(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00608ef6 @ 00608ef6 */

void Catch_All_00608ef6(void)

{
  int unaff_EBP;
  
  std_Tree_eraseRange(unaff_EBP + 8,*(undefined4 *)**(undefined4 **)(unaff_EBP + -0x18),
               (undefined4 *)**(undefined4 **)(unaff_EBP + -0x18));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00609189 @ 00609189 */

void Catch_All_00609189(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_006093dc @ 006093dc */

void Catch_All_006093dc(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* ZLIB1.DLL::inflate @ 006271f8 */

void inflate(void)

{
  inflate();
  return;
}




/* ZLIB1.DLL::inflateEnd @ 006271fe */

void inflateEnd(void)

{
  inflateEnd();
  return;
}




/* ZLIB1.DLL::compress @ 00627204 */

void compress(void)

{
  compress();
  return;
}




/* ZLIB1.DLL::inflateInit_ @ 0062720a */

void inflateInit_(void)

{
  inflateInit_();
  return;
}




/* DINPUT8.DLL::DirectInput8Create @ 00627210 */

void DirectInput8Create(void)

{
  DirectInput8Create();
  return;
}




/* D3D9.DLL::Direct3DCreate9 @ 00627216 */

void Direct3DCreate9(void)

{
  Direct3DCreate9();
  return;
}




/* WS2_32.DLL::Ordinal_3 @ 0062721c */

void Ordinal_3(void)

{
  Ordinal_3();
  return;
}




/* WS2_32.DLL::Ordinal_4 @ 00627222 */

void Ordinal_4(void)

{
  Ordinal_4();
  return;
}




/* WS2_32.DLL::Ordinal_9 @ 00627228 */

void Ordinal_9(void)

{
  Ordinal_9();
  return;
}




/* WS2_32.DLL::Ordinal_11 @ 0062722e */

void Ordinal_11(void)

{
  Ordinal_11();
  return;
}




/* WS2_32.DLL::Ordinal_16 @ 00627234 */

void Ordinal_16(void)

{
  Ordinal_16();
  return;
}




/* WS2_32.DLL::Ordinal_19 @ 0062723a */

void Ordinal_19(void)

{
  Ordinal_19();
  return;
}




/* WS2_32.DLL::Ordinal_23 @ 00627240 */

void Ordinal_23(void)

{
  Ordinal_23();
  return;
}




/* WS2_32.DLL::Ordinal_52 @ 00627246 */

void Ordinal_52(void)

{
  Ordinal_52();
  return;
}




/* WS2_32.DLL::Ordinal_115 @ 0062724c */

void Ordinal_115(void)

{
  Ordinal_115();
  return;
}




/* WS2_32.DLL::Ordinal_116 @ 00627252 */

void Ordinal_116(void)

{
  Ordinal_116();
  return;
}




/* Global::eh_catchall_0062f7fe @ 0062f7fe */

void Catch_All_0062f7fe(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0062f8a6 @ 0062f8a6 */

void Catch_All_0062f8a6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_0062f98f @ 0062f98f */

void Catch_All_0062f98f(void)

{
  int unaff_EBP;
  
  tree_destroyRecursive(*(undefined4 *)(unaff_EBP + 0xc));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0062ff94 @ 0062ff94 */

void Catch_All_0062ff94(void)

{
  int unaff_EBP;
  
  tree_nodeFree(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00630207 @ 00630207 */

void Catch_All_00630207(void)

{
  int unaff_EBP;
  
  tree_nodeFree(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_006302a9 @ 006302a9 */

void Catch_All_006302a9(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      std_list_erase(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063039d @ 0063039d */

void Catch_All_0063039d(void)

{
  std_list_clear_nodes();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063044f @ 0063044f */

void Catch_All_0063044f(void)

{
  list_clearSingleNode();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* [AUDIT] proposed: tree_nodeFree  (confidence: high)
 * purpose: Frees a tree node (operator_delete); called from destructors/catch handlers
 * vars: operator_delete
 */
/* Global::tree_nodeFree @ 00630a80 */

void tree_nodeFree(void *param_1)

{
  if (0xf < *(uint *)((int)param_1 + 0x3c)) {
    operator_delete(*(void **)((int)param_1 + 0x28));
  }
  *(undefined4 *)((int)param_1 + 0x3c) = 0xf;
  *(undefined4 *)((int)param_1 + 0x38) = 0;
  *(undefined1 *)((int)param_1 + 0x28) = 0;
  if (0xf < *(uint *)((int)param_1 + 0x24)) {
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  *(undefined4 *)((int)param_1 + 0x24) = 0xf;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined1 *)((int)param_1 + 0x10) = 0;
  operator_delete(param_1);
}




/* Global::eh_catchall_00638f84 @ 00638f84 */

void Catch_All_00638f84(void)

{
  int unaff_EBP;
  
  lib_fn_5947a0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::_Uninitialized_move<> @ 00639c20 */

/* Library Function - Multiple Matches With Same Base Name
    struct `protected: int __thiscall GSI1::readHash(unsigned short,long,long)'::`2'::FileSymbolInfo
   * __cdecl std::_Uninitialized_move<struct `protected: int __thiscall GSI1::readHash(unsigned
   short,long,long)'::`2'::FileSymbolInfo *,class std::allocator<struct `protected: int __thiscall
   GSI1::readHash(unsigned short,long,long)'::`2'::FileSymbolInfo> >(struct `protected: int
   __thiscall GSI1::readHash(unsigned short,long,long)'::`2'::FileSymbolInfo * const,struct
   `protected: int __thiscall GSI1::readHash(unsigned short,long,long)'::`2'::FileSymbolInfo *
   const,struct `protected: int __thiscall GSI1::readHash(unsigned
   short,long,long)'::`2'::FileSymbolInfo *,class std::allocator<struct `protected: int __thiscall
   GSI1::readHash(unsigned short,long,long)'::`2'::FileSymbolInfo> &)
    struct GSISymbolEntry * __cdecl std::_Uninitialized_move<struct GSISymbolEntry *,class
   std::allocator<struct GSISymbolEntry> >(struct GSISymbolEntry * const,struct GSISymbolEntry *
   const,struct GSISymbolEntry *,class std::allocator<struct GSISymbolEntry> &)
   
   Library: Visual Studio 2019 Release */

void _Uninitialized_move<>(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0x10;
    puVar1 = param_3 + 0x10;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0x10; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}




/* Global::eh_catchall_0063a13f @ 0063a13f */

void Catch_All_0063a13f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0063a337 @ 0063a337 */

void Catch_All_0063a337(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0063a4be @ 0063a4be */

void Catch_All_0063a4be(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0063a5ba @ 0063a5ba */

void Catch_All_0063a5ba(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0063a7e6 @ 0063a7e6 */

void Catch_All_0063a7e6(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
    std_wstring_dtor_free(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063c08f @ 0063c08f */

void Catch_All_0063c08f(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063c13f @ 0063c13f */

void Catch_All_0063c13f(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063c1ef @ 0063c1ef */

void Catch_All_0063c1ef(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063d153 @ 0063d153 */

void Catch_All_0063d153(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063d279 @ 0063d279 */

void Catch_All_0063d279(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063d3ea @ 0063d3ea */

void Catch_All_0063d3ea(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063d509 @ 0063d509 */

void Catch_All_0063d509(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063d6d3 @ 0063d6d3 */

void Catch_All_0063d6d3(void)

{
  FUN_0063de60();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0063db73 @ 0063db73 */

void Catch_All_0063db73(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0063dc70 @ 0063dc70 */

void Catch_All_0063dc70(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::lib_fn_642700 @ 00642700 */

void lib_fn_642700(int param_1)

{
  void *_Src;
  int *piVar1;
  void *_Dst;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)(*(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) & 0xfffffffcU)) {
    do {
      piVar1 = *(int **)(*(int *)(in_ECX + 0x4c) + iVar2 * 4);
      _Dst = (void *)(*piVar1 + param_1 * 4);
      _Src = (void *)((int)_Dst + 4);
      memmove(_Dst,_Src,piVar1[1] - (int)_Src & 0xfffffffc);
      piVar1[1] = piVar1[1] + -4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2);
  }
  return;
}




/* Global::lib_fn_642770 @ 00642770 */

void lib_fn_642770(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < (int)(*(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) & 0xfffffffcU)) {
    do {
      piVar1 = *(int **)(*(int *)(in_ECX + 0x4c) + iVar4 * 4);
      puVar2 = (undefined4 *)piVar1[1];
      for (puVar3 = (undefined4 *)(param_1 * 8 + 8 + *piVar1); puVar3 != puVar2; puVar3 = puVar3 + 2
          ) {
        puVar3[-2] = *puVar3;
        puVar3[-1] = puVar3[1];
      }
      piVar1[1] = (int)(puVar2 + -2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2);
  }
  return;
}




/* Global::lib_fn_6427e0 @ 006427e0 */

void lib_fn_6427e0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < (int)(*(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) & 0xfffffffcU)) {
    do {
      piVar1 = *(int **)(*(int *)(in_ECX + 0x4c) + iVar5 * 4);
      puVar4 = (undefined4 *)(param_1 * 0x10 + 0x10 + *piVar1);
      puVar2 = (undefined4 *)piVar1[1];
      if (puVar4 != puVar2) {
        puVar3 = puVar4 + -2;
        do {
          puVar3[-2] = *puVar4;
          puVar3[-1] = puVar3[3];
          *puVar3 = puVar3[4];
          puVar4 = puVar4 + 4;
          puVar3[1] = puVar3[5];
          puVar3 = puVar3 + 4;
        } while (puVar4 != puVar2);
      }
      piVar1[1] = (int)(puVar2 + -4);
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2);
  }
  return;
}




/* Global::eh_catchall_00642a01 @ 00642a01 */

void Catch_All_00642a01(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::lib_fn_64b0d0 @ 0064b0d0 */

basic_ostream<wchar_t,std::char_traits<wchar_t>_> *
lib_fn_64b0d0(basic_ostream<wchar_t,std::char_traits<wchar_t>_> *param_1,wchar_t param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  bool bVar5;
  int local_28;
  int iStack_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f5fe0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar4 = 0;
  if (*(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) + 4))();
  }
  local_8 = 0;
  if ((*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) == 0) &&
     (*(basic_ostream<wchar_t,std::char_traits<wchar_t>_> **)
       (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c) !=
      (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::flush
              (*(basic_ostream<wchar_t,std::char_traits<wchar_t>_> **)
                (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c));
  }
  iVar1 = *(int *)(*(int *)param_1 + 4);
  if (*(int *)(param_1 + iVar1 + 0xc) == 0) {
    iStack_24 = *(int *)(param_1 + iVar1 + 0x24);
    uVar2 = *(uint *)(param_1 + iVar1 + 0x20);
    if ((iStack_24 < 1) && ((iStack_24 < 0 || (uVar2 < 2)))) {
      iStack_24 = 0;
      local_28 = 0;
    }
    else {
      local_28 = uVar2 - 1;
      iStack_24 = iStack_24 - (uint)(uVar2 == 0);
    }
    local_8 = 2;
    if ((*(uint *)(param_1 + iVar1 + 0x14) & 0x1c0) == 0x40) {
LAB_0064b1e8:
      uVar3 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,std::char_traits<wchar_t>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),param_2);
      if (uVar3 == 0xffff) {
        iVar4 = 4;
      }
      for (; ((iVar4 == 0 && (-1 < iStack_24)) && ((0 < iStack_24 || (local_28 != 0))));
          local_28 = local_28 + -1) {
        uVar3 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::sputc
                          (*(basic_streambuf<wchar_t,std::char_traits<wchar_t>_> **)
                            (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                           *(wchar_t *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x40));
        if (uVar3 == 0xffff) {
          iVar4 = 4;
        }
        iStack_24 = iStack_24 + -1 + (uint)(local_28 != 0);
      }
    }
    else {
      while (iVar4 == 0) {
        if ((iStack_24 < 0) || ((iStack_24 < 1 && (local_28 == 0)))) goto LAB_0064b1e8;
        uVar3 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::sputc
                          (*(basic_streambuf<wchar_t,std::char_traits<wchar_t>_> **)
                            (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                           *(wchar_t *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x40));
        if (uVar3 == 0xffff) {
          iVar4 = 4;
        }
        bVar5 = local_28 != 0;
        local_28 = local_28 + -1;
        iStack_24 = iStack_24 + -1 + (uint)bVar5;
      }
    }
  }
  local_8 = 1;
  iVar1 = *(int *)(*(int *)param_1 + 4);
  *(undefined4 *)(param_1 + iVar1 + 0x20) = 0;
  *(undefined4 *)(param_1 + iVar1 + 0x24) = 0;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (param_1 + *(int *)(*(int *)param_1 + 4)),iVar4,false);
  local_8 = 0xffffffff;
  bVar5 = std::uncaught_exception();
  if (!bVar5) {
    std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::_Osfx(param_1);
  }
  if (*(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) + 8))();
  }
  ExceptionList = local_10;
  return param_1;
}




/* Global::eh_catchall_0064b251 @ 0064b251 */

undefined * Catch_All_0064b251(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  return &DAT_0064b26b;
}




/* Global::lib_fn_64b2e0 @ 0064b2e0 */

undefined4 * lib_fn_64b2e0(undefined4 *param_1,short *param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  short *psVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f1619;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  local_8 = 0;
  if (*param_2 == 0) {
    iVar6 = 0;
  }
  else {
    psVar7 = param_2;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    iVar6 = (int)psVar7 - (int)(param_2 + 1) >> 1;
  }
  uVar2 = param_1[4];
  uVar4 = *(int *)(param_3 + 0x10) + iVar6;
  if (((uVar2 <= uVar4) && (param_1[5] != uVar4)) && (cVar3 = u16string_resize(uVar4,1), cVar3 != '\0'))
  {
    param_1[4] = uVar2;
    puVar5 = param_1;
    if (7 < (uint)param_1[5]) {
      puVar5 = (undefined4 *)*param_1;
    }
    *(undefined2 *)((int)puVar5 + uVar2 * 2) = 0;
  }
  if (*param_2 == 0) {
    iVar6 = 0;
  }
  else {
    psVar7 = param_2;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    iVar6 = (int)psVar7 - (int)(param_2 + 1) >> 1;
  }
  std_u16string_append(param_2,iVar6);
  std_u16string_replace(param_3,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}




/* Global::eh_catchall_0064b441 @ 0064b441 */

void Catch_All_0064b441(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_0064bb48 @ 0064bb48 */

void Catch_All_0064bb48(void)

{
  int unaff_EBP;
  
  std_Tree_Freenode_str(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0064bc78 @ 0064bc78 */

void Catch_All_0064bc78(void)

{
  int unaff_EBP;
  
  std_Tree_Freenode_str(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0064bdc4 @ 0064bdc4 */

void Catch_All_0064bdc4(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_9 @ 0064ced0 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_9
               (undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  int iVar1;
  basic_istream<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f60fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 != 0) {
    *(undefined ***)in_ECX = &PTR_006fcad0;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 0x10);
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            (in_ECX,this,false);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x70;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  local_8._0_1_ = 2;
  *(undefined ***)this = vftable;
  in_ECX[0x5c] = (basic_istream<char,std::char_traits<char>_>)0x0;
  in_ECX[0x55] = (basic_istream<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(int *)(in_ECX + 0x58) = DAT_0076af5c;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = lib_fn_653210(param_1,param_2 | 1,param_3);
  if (iVar1 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(in_ECX + *(int *)(*(int *)in_ECX + 4)),2,
               false);
  }
  ExceptionList = local_10;
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_10 @ 0064cfe0 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_10(int param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  basic_istream<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f6152;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    *(undefined ***)in_ECX = &PTR_006fcad0;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    *(code **)(in_ECX + 0x70) = _vftable__exref;
    local_8 = 0;
  }
  this = (basic_streambuf<char,std::char_traits<char>_> *)(in_ECX + 0x10);
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            (in_ECX,this,false);
  local_8 = 1;
  *(undefined ***)(in_ECX + *(int *)(*(int *)in_ECX + 4)) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(in_ECX + *(int *)(*(int *)in_ECX + 4) + -4) = *(int *)(*(int *)in_ECX + 4) + -0x70;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (this);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined ***)this = vftable;
  in_ECX[0x5c] = (basic_istream<char,std::char_traits<char>_>)0x0;
  in_ECX[0x55] = (basic_istream<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(this);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(int *)(in_ECX + 0x58) = DAT_0076af5c;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  ExceptionList = local_10;
  return;
}




/* Global::eh_catchall_0064e67d @ 0064e67d */

void Catch_All_0064e67d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
}




/* Global::lib_fn_64e850 @ 0064e850 */

void lib_fn_64e850(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  
  if (0 < (int)(*(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) & 0xfffffffcU)) {
    iVar4 = 0;
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x4c) + iVar4 * 4);
      puVar2 = (undefined4 *)puVar1[1];
      if ((param_1 < puVar2) && (puVar3 = (undefined4 *)*puVar1, puVar3 <= param_1)) {
        if (puVar2 == (undefined4 *)puVar1[2]) {
          std_vector_reserve_stride4(1);
        }
        if ((undefined4 *)puVar1[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar1[1] =
               *(undefined4 *)(*puVar1 + ((int)param_1 - (int)puVar3 >> 2) * 4);
        }
      }
      else {
        if (puVar2 == (undefined4 *)puVar1[2]) {
          std_vector_reserve_stride4(1);
        }
        if ((undefined4 *)puVar1[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar1[1] = *param_1;
        }
      }
      puVar1[1] = puVar1[1] + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2);
  }
  return;
}




/* Global::lib_fn_64e8f0 @ 0064e8f0 */

void lib_fn_64e8f0(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (0 < (int)(*(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) & 0xfffffffcU)) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x4c) + iVar4 * 4);
      puVar2 = (undefined4 *)puVar1[1];
      if ((param_1 < puVar2) && ((undefined4 *)*puVar1 <= param_1)) {
        iVar5 = (int)((int)param_1 - *puVar1) >> 3;
        if (puVar2 == (undefined4 *)puVar1[2]) {
          vectorReserveCheck8(1);
        }
        uVar3 = *puVar1;
        puVar2 = (undefined4 *)puVar1[1];
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = *(undefined4 *)(uVar3 + iVar5 * 8);
          puVar2[1] = *(undefined4 *)(uVar3 + 4 + iVar5 * 8);
        }
      }
      else {
        if (puVar2 == (undefined4 *)puVar1[2]) {
          vectorReserveCheck8(1);
        }
        puVar2 = (undefined4 *)puVar1[1];
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = *param_1;
          puVar2[1] = param_1[1];
        }
      }
      puVar1[1] = puVar1[1] + 8;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2);
  }
  return;
}




/* Global::lib_fn_64e9b0 @ 0064e9b0 */

void lib_fn_64e9b0(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_8;
  
  local_8 = 0;
  if (0 < (int)(*(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) & 0xfffffffcU)) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x4c) + local_8 * 4);
      puVar3 = (undefined4 *)puVar1[1];
      if ((param_1 < puVar3) && (puVar4 = (undefined4 *)*puVar1, puVar4 <= param_1)) {
        if (puVar3 == (undefined4 *)puVar1[2]) {
          vectorReserveCheck16(1);
        }
        puVar3 = (undefined4 *)puVar1[1];
        puVar4 = (undefined4 *)(((int)param_1 - (int)puVar4 & 0xfffffff0U) + *puVar1);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = *puVar4;
          puVar3[1] = puVar4[1];
          puVar3[2] = puVar4[2];
          uVar2 = puVar4[3];
LAB_0064ea49:
          puVar3[3] = uVar2;
        }
      }
      else {
        if (puVar3 == (undefined4 *)puVar1[2]) {
          vectorReserveCheck16(1);
        }
        puVar3 = (undefined4 *)puVar1[1];
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = *param_1;
          puVar3[1] = param_1[1];
          puVar3[2] = param_1[2];
          uVar2 = param_1[3];
          goto LAB_0064ea49;
        }
      }
      puVar1[1] = puVar1[1] + 0x10;
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2);
  }
  return;
}




/* std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_15 @ 0064f650 */

void std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::ctor_15
               (int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 ****ppppuVar1;
  undefined4 in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  int iStack_1a8;
  undefined **local_1a4 [4];
  undefined *local_194 [2];
  undefined **local_18c [2];
  basic_iostream<wchar_t,std::char_traits<wchar_t>_> local_184 [4];
  undefined4 *local_180;
  undefined4 local_154;
  uint local_150;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_13c [72];
  int local_f4;
  void *local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  undefined4 **local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  void *local_bc [5];
  uint local_a8;
  float local_a4;
  float local_a0;
  undefined4 local_9c;
  float local_98;
  float local_94;
  float fStack_90;
  undefined8 local_8c;
  undefined8 local_84;
  undefined4 local_7c;
  undefined4 uStack_78;
  int local_74;
  int iStack_70;
  float local_6c;
  float fStack_68;
  int local_64;
  int iStack_60;
  float local_5c;
  float fStack_58;
  float local_54;
  float fStack_50;
  int local_4c;
  int iStack_48;
  undefined8 local_44;
  undefined8 local_3c;
  undefined4 ***local_34 [4];
  undefined4 **local_24;
  undefined4 **local_20;
  int local_1c;
  int iStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f659c;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_d0 = (undefined4 **)0x0;
  local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffff0000);
  local_c0 = param_1;
  local_c4 = param_2;
  local_20 = (undefined4 ***)0x7;
  local_24 = (undefined4 ***)0x0;
  u16string_replaceRange(param_4,0,0xffffffff);
  local_8 = 0;
  if (param_2 < 1) {
    local_c4 = 0x10;
    local_d8 = 0x10;
    local_1a4[0] = &PTR_006fcd00;
    local_194[0] = &DAT_006fcd08;
    std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_13c);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_d0 = (undefined4 **)0x1;
    std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
    basic_iostream<wchar_t,std::char_traits<wchar_t>_>
              ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_1a4,
               (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_18c);
    local_8 = 2;
    *(undefined ***)((int)local_1a4 + (int)local_1a4[0][1]) =
         basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
    *(undefined **)((int)&iStack_1a8 + (int)local_1a4[0][1]) = local_1a4[0][1] + -0x68;
    std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
    basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
              ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_18c);
    local_18c[0] = vftable;
    local_154 = 0;
    local_150 = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar3 = 0;
    do {
      lib_fn_64b0d0(local_194,iVar3);
      iVar3 = iVar3 + 1;
    } while ((ushort)iVar3 < 0x100);
    ppppuVar1 = (undefined4 ****)u16_ostrstream_str_wrap(local_bc);
    param_1 = local_c0;
    if (local_34 != ppppuVar1) {
      if ((undefined4 ***)0x7 < local_20) {
        operator_delete(local_34[0]);
      }
      local_20 = (undefined4 **)0x7;
      local_24 = (undefined4 **)0x0;
      local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffff0000);
      if (ppppuVar1[5] < (undefined4 ***)0x8) {
        if ((int)ppppuVar1[4] + 1 != 0) {
          memmove(local_34,ppppuVar1,((int)ppppuVar1[4] + 1) * 2);
        }
      }
      else {
        local_34[0] = *ppppuVar1;
        *ppppuVar1 = (undefined4 ***)0x0;
      }
      local_24 = ppppuVar1[4];
      local_20 = ppppuVar1[5];
      ppppuVar1[5] = (undefined4 ***)0x7;
      ppppuVar1[4] = (undefined4 ***)0x0;
      *(undefined2 *)ppppuVar1 = 0;
    }
    if (7 < local_a8) {
      operator_delete(local_bc[0]);
    }
    local_8 = local_8 & 0xffffff00;
    *(undefined ***)((int)local_1a4 + (int)local_1a4[0][1]) =
         basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
    *(undefined **)((int)&iStack_1a8 + (int)local_1a4[0][1]) = local_1a4[0][1] + -0x68;
    local_18c[0] = vftable;
    if ((local_150 & 1) != 0) {
      operator_delete((void *)*local_180);
    }
    std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
              ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_18c,(wchar_t *)0x0,
               (wchar_t *)0x0,(wchar_t *)0x0);
    std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
              ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_18c,(wchar_t *)0x0,
               (wchar_t *)0x0);
    local_150 = local_150 & 0xfffffffe;
    local_154 = 0;
    std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
    ~basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
              ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_18c);
    std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
    ~basic_iostream<wchar_t,std::char_traits<wchar_t>_>(local_184);
    std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_13c);
  }
  else {
    local_d8 = param_3;
  }
  local_d0 = local_24;
  local_f0 = operator_new(0x74);
  local_8._0_1_ = 5;
  if (local_f0 == (void *)0x0) {
    local_dc = 0;
  }
  else {
    local_dc = plasma::PixelFont::ctor_0(in_ECX,param_1 + 0xc);
  }
  iVar3 = local_dc;
  local_8 = (uint)local_8._1_3_ << 8;
  lib_fn_67fa50(param_1);
  *(float *)(iVar3 + 0x4c) = (float)(((*(int *)(param_1 + 0x44) / local_c4) * 2) / 3);
  local_1c = *(int *)(param_1 + 0x44) / local_c4;
  local_f0 = (void *)(((int)(local_1c + (local_1c >> 0x1f & 0xfU)) >> 4) + -1);
  iStack_18 = *(int *)(param_1 + 0x48) / local_d8;
  local_d4 = 0;
  if (0 < (int)local_d0) {
    do {
      local_3c = CONCAT44(iStack_18,local_1c);
      iVar3 = local_1c + -1;
      iVar5 = iStack_18 + -1;
      local_e8 = 0;
      local_e0 = 0;
      local_f4 = local_1c * (local_d4 % local_c4);
      local_e4 = iStack_18 * (local_d4 / local_c4);
      iVar4 = 0;
      if (0 < local_1c) {
        do {
          iVar2 = 0;
          if (0 < iStack_18) {
            local_ec = local_f4 + iVar4;
            local_c8 = *(int *)(local_c0 + 0x44);
            local_cc = local_c8 * local_e4;
            do {
              if (((local_ec < local_c8) && (local_e4 + iVar2 < *(int *)(local_c0 + 0x48))) &&
                 (*(char *)(*(int *)(local_c0 + 0x24) + 3 + (local_cc + local_ec) * 4) != '\0')) {
                if (local_e8 < iVar4) {
                  local_e8 = iVar4;
                }
                if (local_e0 < iVar2) {
                  local_e0 = iVar2;
                }
                if (iVar4 < iVar3) {
                  iVar3 = iVar4;
                }
                if (iVar2 < iVar5) {
                  iVar5 = iVar2;
                }
              }
              iVar2 = iVar2 + 1;
              local_cc = local_cc + local_c8;
            } while (iVar2 < iStack_18);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < local_1c);
      }
      if ((local_e8 < iVar3) || (iVar4 = local_e0, iVar2 = local_e8, local_e0 < iVar5)) {
        local_7c = 0;
        uStack_78 = 0;
        local_3c = 0;
        local_3c._4_4_ = 0;
        local_3c._0_4_ = 0;
        local_64 = (*(int *)(local_c0 + 0x44) / local_c4) / 3;
        iStack_60 = (*(int *)(local_c0 + 0x48) / local_d8) / 3;
        iVar4 = iStack_60;
        iVar2 = local_64;
        iVar3 = (int)local_3c;
        iVar5 = local_3c._4_4_;
      }
      _local_4c = CONCAT44(iVar4 + 1,iVar2 + 1);
      iVar5 = iVar5 + -1;
      iVar4 = (iVar4 + 1) - iVar5;
      iVar2 = (iVar2 + 1) - (iVar3 + -1);
      local_44 = CONCAT44(iVar4,iVar2);
      local_8c = local_44;
      fVar7 = 1.0f / (float)*(int *)(local_c0 + 0x44);
      fVar6 = 1.0f / (float)*(int *)(local_c0 + 0x48);
      iVar2 = iVar2 + 1;
      local_98 = (float)iVar5;
      local_a4 = (float)iVar2;
      local_a0 = (float)(iVar4 + 1);
      _local_5c = CONCAT44(fVar6 * local_a0,fVar7 * local_a4);
      local_84 = CONCAT44(local_e4,local_f4);
      local_94 = (float)(local_f4 + iVar3 + -1);
      fStack_90 = (float)(local_e4 + iVar5);
      ppppuVar1 = local_34;
      if ((undefined4 ***)0x7 < local_20) {
        ppppuVar1 = (undefined4 ****)local_34[0];
      }
      local_9c = 0;
      _local_54 = CONCAT44(fVar6 * fStack_90,fVar7 * local_94);
      local_74 = local_f4;
      iStack_70 = local_e4;
      local_6c = local_a4;
      fStack_68 = local_a0;
      lib_fn_67f980(*(undefined2 *)((int)ppppuVar1 + local_d4 * 2),&local_9c,&local_a4,&local_54,
                   &local_5c,(float)((int)local_f0 + iVar2));
      local_d4 = local_d4 + 1;
    } while (local_d4 < (int)local_d0);
  }
  if (local_20 < (undefined4 ***)0x8) {
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  operator_delete(local_34[0]);
}




/* Global::lib_fn_64fd30 @ 0064fd30 */

undefined4 lib_fn_64fd30(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f661b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x70);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = plasma::PlasmaFont::ctor_0(in_ECX,param_1);
    ExceptionList = local_10;
    return uVar2;
  }
  ExceptionList = local_10;
  return 0;
}




/* Global::lib_fn_64fda0 @ 0064fda0 */

void lib_fn_64fda0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  float *pfVar5;
  undefined4 ****ppppuVar6;
  undefined4 in_ECX;
  int *piVar7;
  float fVar8;
  float fVar9;
  undefined1 local_6c [8];
  undefined1 local_64 [8];
  float local_5c;
  float fStack_58;
  undefined4 ***local_54 [4];
  undefined4 local_44;
  uint local_40;
  float local_3c;
  float fStack_38;
  float local_34;
  float fStack_30;
  float local_2c;
  float fStack_28;
  float local_24;
  float fStack_20;
  float local_1c;
  float fStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f65e3;
  local_10 = ExceptionList;
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  pvVar4 = operator_new(0x70);
  local_8 = 0;
  if (pvVar4 != (void *)0x0) {
    plasma::PlasmaFont::ctor_0(in_ECX,param_2);
  }
  piVar7 = (int *)**(int **)(param_1 + 0x2c);
  if (piVar7 != *(int **)(param_1 + 0x2c)) {
    do {
      local_8 = 0xffffffff;
      iVar1 = piVar7[2];
      if ((*(int *)(iVar1 + 0x1c) == 1) && (*(int *)(iVar1 + 0x34) != 0)) {
        local_54[0] = (undefined4 ***)((uint)local_54[0] & 0xffff0000);
        local_40 = 7;
        local_44 = 0;
        u16string_replaceRange(iVar1 + 0xc,0,0xffffffff);
        iVar1 = *(int *)(piVar7[2] + 0x38);
        local_8 = 1;
        pfVar5 = (float *)(**(code **)(**(int **)(piVar7[2] + 0x34) + 0x18))(local_64,uVar3);
        fVar8 = pfVar5[1];
        fVar9 = *pfVar5;
        local_3c = *(float *)(iVar1 + 0x1b0) * fVar9 + *(float *)(iVar1 + 0x1c0) * fVar8 +
                   *(float *)(iVar1 + 0x1e0);
        fStack_38 = *(float *)(iVar1 + 0x1b4) * fVar9 + *(float *)(iVar1 + 0x1c4) * fVar8 +
                    *(float *)(iVar1 + 0x1e4);
        iVar2 = *(int *)(piVar7[2] + 0x38);
        fVar8 = 1.0f / (*(float *)(iVar1 + 0x1bc) * fVar9 + *(float *)(iVar1 + 0x1cc) * fVar8 +
                      *(float *)(iVar1 + 0x1ec));
        _local_1c = CONCAT44(fStack_38 * fVar8,local_3c * fVar8);
        pfVar5 = (float *)(**(code **)(**(int **)(piVar7[2] + 0x34) + 0x1c))(local_6c);
        fVar8 = pfVar5[1];
        fVar9 = *pfVar5;
        local_5c = *(float *)(iVar2 + 0x1b0) * fVar9 + *(float *)(iVar2 + 0x1c0) * fVar8 +
                   *(float *)(iVar2 + 0x1e0);
        fStack_58 = *(float *)(iVar2 + 0x1b4) * fVar9 + *(float *)(iVar2 + 0x1c4) * fVar8 +
                    *(float *)(iVar2 + 0x1e4);
        fVar8 = 1.0f / (*(float *)(iVar2 + 0x1bc) * fVar9 + *(float *)(iVar2 + 0x1cc) * fVar8 +
                      *(float *)(iVar2 + 0x1ec));
        fVar9 = local_5c * fVar8;
        _local_2c = CONCAT44(fStack_58 * fVar8,fVar9);
        if ((~(byte)(*(uint *)(piVar7[2] + 200) >> 1) & 1) == 0) {
          Node_set_shape_slot(0);
        }
        local_34 = (float)_local_2c;
        fStack_30 = (float)((ulonglong)_local_2c >> 0x20);
        _local_34 = CONCAT44(fStack_30 - fStack_18,local_34 - local_1c);
        iVar1 = *(int *)(*(int *)(piVar7[2] + 0x38) + 0x68);
        iVar2 = *(int *)(*(int *)(piVar7[2] + 0x38) + 0x94);
        ppppuVar6 = local_54;
        if (7 < local_40) {
          ppppuVar6 = (undefined4 ****)local_54[0];
        }
        _local_24 = CONCAT44(fStack_18 - *(float *)(iVar2 + 4 + iVar1 * 8),
                             local_1c - *(float *)(iVar2 + iVar1 * 8));
        lib_fn_67f1b0(*(undefined2 *)ppppuVar6,&local_24,&local_34,piVar7[2],fVar9 - local_1c);
        local_8 = 0xffffffff;
        if (7 < local_40) {
          operator_delete(local_54[0]);
        }
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)*(int *)(param_1 + 0x2c));
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_5 @ 00650e80 */


void std::basic_filebuf<char,std::char_traits<char>_>::ctor_5
               (undefined4 *param_1,undefined4 param_2,float param_3)

{
  short sVar1;
  char *pcVar2;
  undefined8 *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  basic_ostream<char,std::char_traits<char>_> *this;
  undefined4 *******pppppppuVar10;
  char *pcVar11;
  short *psVar12;
  int *piVar13;
  int *piVar14;
  basic_streambuf<char,std::char_traits<char>_> *pbVar15;
  undefined ***pppuVar16;
  _Container_base0 *p_Var17;
  int *piVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr
  *p_Var22;
  undefined **local_2d8 [4];
  undefined **local_2c8 [16];
  undefined4 local_288;
  undefined1 local_283;
  undefined4 local_280;
  undefined1 local_27c;
  FILE *local_278;
  basic_ios<char,std::char_traits<char>_> local_268 [72];
  float local_220;
  float local_21c;
  undefined4 local_218;
  float local_214;
  int local_210;
  int local_20c;
  float local_208;
  _Container_base0 *local_204;
  _Container_base0 *local_200;
  undefined4 local_1fc;
  float local_1f8;
  int local_1f4;
  int local_1f0;
  undefined4 *local_1ec;
  _Container_base0 *local_1e8;
  _Container_base0 *local_1e4;
  undefined4 local_1e0;
  int local_1dc;
  int local_1d8;
  int *local_1d4;
  int *local_1d0;
  int *local_1cc;
  int local_1c8;
  int local_1c4;
  byte local_1bd;
  short local_1bc [2];
  int *local_1b8;
  basic_streambuf<char,std::char_traits<char>_> *local_1b4;
  int local_1b0;
  undefined1 local_1ac [8];
  void *local_1a4 [4];
  undefined4 local_194;
  uint local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  float local_154;
  undefined4 uStack_150;
  undefined4 local_14c;
  undefined4 uStack_148;
  undefined4 local_144;
  undefined4 uStack_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 uStack_130;
  undefined4 local_12c;
  undefined4 uStack_128;
  float local_124;
  undefined4 uStack_120;
  undefined4 local_11c;
  undefined4 uStack_118;
  undefined4 local_114;
  undefined4 uStack_110;
  float local_10c;
  undefined4 uStack_108;
  undefined4 local_104;
  undefined4 uStack_100;
  undefined4 local_fc;
  undefined4 uStack_f8;
  undefined8 local_f4;
  float local_ec;
  float fStack_e8;
  float local_e4;
  undefined4 uStack_e0;
  void *local_dc [4];
  undefined4 local_cc;
  uint local_c8;
  undefined4 local_c4;
  int local_b4;
  uint local_b0;
  void *local_ac [2];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  undefined4 local_94;
  int local_84;
  uint local_80;
  undefined4 *******local_7c [4];
  undefined4 local_6c;
  uint local_68;
  float local_64;
  float fStack_60;
  undefined8 local_5c;
  float local_54;
  float fStack_50;
  float local_4c;
  float fStack_48;
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f67a3;
  local_10 = ExceptionList;
  uVar5 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1f8 = param_3;
  local_1ec = param_1;
  local_1c8 = 0x2f;
  local_14 = uVar5;
  iVar6 = std_string_rfind_substr(&local_1c8,0xffffffff,1);
  local_1c8 = 0x5c;
  local_1f4 = iVar6;
  local_1c8 = std_string_rfind_substr(&local_1c8,0xffffffff,1);
  piVar13 = &local_1c8;
  if (local_1c8 <= iVar6) {
    piVar13 = &local_1f4;
  }
  wstring_ctorFromRange(local_7c,*piVar13 + 1,(param_1[4] - *piVar13) + -1);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  piVar13 = (int *)**(int **)(local_1c4 + 0xa4);
  if (piVar13 != *(int **)(local_1c4 + 0xa4)) {
    do {
      iVar6 = __RTDynamicCast(piVar13[2],0,&plasma::Font::RTTI_Type_Descriptor,
                              &plasma::PlasmaFont::RTTI_Type_Descriptor,0,uVar5);
      if (iVar6 != 0) {
        pppppppuVar10 = local_7c;
        if (7 < local_68) {
          pppppppuVar10 = local_7c[0];
        }
        iVar6 = u16string_compare(0,*(undefined4 *)(iVar6 + 0x44),pppppppuVar10,local_6c);
        if (iVar6 == 0) {
          iVar6 = lib_fn_67e4d0();
          if ((undefined4 ********)(iVar6 + 0x34) != local_7c) {
            u16string_replaceRange(local_7c,0,0xffffffff);
          }
          *(undefined4 *)(iVar6 + 0x4c) = param_2;
          *(undefined4 *)(iVar6 + 0x50) = 0;
          goto LAB_00652666;
        }
      }
      piVar13 = (int *)*piVar13;
      param_1 = local_1ec;
    } while (piVar13 != (int *)*(int *)(local_1c4 + 0xa4));
  }
  local_2d8[0] = &PTR_006fcad0;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_268);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_1c8 = 1;
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)local_2d8,
             (basic_streambuf<char,std::char_traits<char>_> *)local_2c8,false);
  local_8 = 2;
  *(undefined ***)((int)local_2d8 + (int)local_2d8[0][1]) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(undefined **)((int)local_2c8 + (int)(local_2d8[0][1] + -0x14)) = local_2d8[0][1] + -0x70;
  local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)local_2c8;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            (local_1b4);
  local_8._0_1_ = 3;
  local_2c8[0] = vftable;
  local_27c = 0;
  local_283 = 0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init
            ((basic_streambuf<char,std::char_traits<char>_> *)local_2c8);
  local_278 = (FILE *)0x0;
  local_280 = DAT_0076af5c;
  local_288 = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  puVar8 = param_1;
  if (7 < (uint)param_1[5]) {
    puVar8 = (undefined4 *)*param_1;
  }
  iVar6 = lib_fn_653210(puVar8,0x21,0x40);
  if (iVar6 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)((int)local_2d8 + (int)local_2d8[0][1]),2,
               false);
  }
  else {
    std::basic_ios<char,std::char_traits<char>_>::clear
              ((basic_ios<char,std::char_traits<char>_> *)((int)local_2d8 + (int)local_2d8[0][1]),0,
               false);
  }
  local_b0 = 7;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4._2_2_ << 0x10);
  local_8._0_1_ = 5;
  if (local_278 == (FILE *)0x0) {
    piVar13 = (int *)**(int **)(local_1c4 + 0x13c);
    if (piVar13 != *(int **)(local_1c4 + 0x13c)) {
      do {
        local_8._0_1_ = 5;
        uVar7 = wstring_ctorAppend(local_dc,piVar13 + 2,&DAT_006fd42c);
        local_8._0_1_ = 6;
        puVar8 = (undefined4 *)string_assign(local_2c,uVar7,local_7c);
        local_8 = CONCAT31(local_8._1_3_,7);
        if (7 < (uint)puVar8[5]) {
          puVar8 = (undefined4 *)*puVar8;
        }
        iVar6 = lib_fn_653210(puVar8,0x21,0x40);
        if (iVar6 == 0) {
          std::basic_ios<char,std::char_traits<char>_>::setstate
                    ((basic_ios<char,std::char_traits<char>_> *)
                     ((int)local_2d8 + (int)local_2d8[0][1]),2,false);
        }
        else {
          std::basic_ios<char,std::char_traits<char>_>::clear
                    ((basic_ios<char,std::char_traits<char>_> *)
                     ((int)local_2d8 + (int)local_2d8[0][1]),0,false);
        }
        if (7 < local_18) {
          operator_delete(local_2c[0]);
        }
        local_18 = 7;
        local_1c = 0;
        local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
        local_8._0_1_ = 5;
        if (7 < local_c8) {
          operator_delete(local_dc[0]);
        }
        if (local_278 != (FILE *)0x0) {
          if (&local_c4 != piVar13 + 2) {
            u16string_replaceRange(piVar13 + 2,0,0xffffffff);
          }
          if (local_278 != (FILE *)0x0) goto LAB_00651289;
          break;
        }
        piVar13 = (int *)*piVar13;
      } while (piVar13 != (int *)*(int *)(local_1c4 + 0x13c));
    }
    local_1b4 = operator_new(0x70);
    local_8._0_1_ = 8;
    if (local_1b4 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = plasma::PlasmaFont::ctor_0(local_1c4,local_7c);
    }
    local_8._0_1_ = 5;
    if ((undefined4 ********)(iVar6 + 0x34) != local_7c) {
      u16string_replaceRange(local_7c,0,0xffffffff);
    }
    *(undefined4 *)(iVar6 + 0x4c) = param_2;
  }
  else {
LAB_00651289:
    pppuVar16 = local_2c8;
    if (local_278 == (FILE *)0x0) {
      pppuVar16 = (undefined ***)0x0;
    }
    else {
      cVar4 = filebuf_endWrite();
      if (cVar4 == '\0') {
        pppuVar16 = (undefined ***)0x0;
      }
      iVar6 = fclose(local_278);
      if (iVar6 != 0) {
        pppuVar16 = (undefined ***)0x0;
      }
    }
    local_27c = 0;
    local_283 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)local_2c8);
    local_278 = (FILE *)0x0;
    local_280 = DAT_0076af5c;
    local_288 = 0;
    if (pppuVar16 == (undefined ***)0x0) {
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)((int)local_2d8 + (int)local_2d8[0][1]),
                 2,false);
    }
    if (local_b4 == 0) {
      if (&local_c4 != param_1) {
        u16string_replaceRange(param_1,0,0xffffffff);
      }
    }
    else {
      uVar7 = lib_fn_64b2e0(local_2c,&DAT_006fd42c,local_7c);
      local_8._0_1_ = 9;
      std_u16string_replace(uVar7,0,0xffffffff);
      local_8._0_1_ = 5;
      if (7 < local_18) {
        operator_delete(local_2c[0]);
      }
    }
    puVar8 = (undefined4 *)std_string_assignFromString(local_2c,&local_c4);
    iVar6 = local_1c4;
    if (0xf < (uint)puVar8[5]) {
      puVar8 = (undefined4 *)*puVar8;
    }
    iVar9 = FT_New_Memory_Face(*(undefined4 *)(local_1c4 + 0x70),puVar8,0,&local_1b0);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    if (iVar9 == 0) {
      pcVar2 = *(char **)(local_1b0 + 0x14);
      local_98 = 0xf;
      local_9c = 0;
      local_ac[0] = (void *)((uint)local_ac[0] & 0xffffff00);
      if (*pcVar2 == '\0') {
        iVar9 = 0;
      }
      else {
        pcVar11 = pcVar2;
        do {
          cVar4 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar4 != '\0');
        iVar9 = (int)pcVar11 - (int)(pcVar2 + 1);
      }
      string_assignPtrLen(pcVar2,iVar9);
      local_8._0_1_ = 10;
      uVar7 = std_string_ctor_cstr(local_2c,local_ac,&DAT_006fcfbc);
      local_8._0_1_ = 0xb;
      std_string_ctor_cstr(local_1a4,uVar7,*(undefined4 *)(local_1b0 + 0x18));
      if (0xf < local_18) {
        operator_delete(local_2c[0]);
      }
      local_18 = 0xf;
      local_1c = 0;
      local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
      local_8._0_1_ = 0xe;
      if (0xf < local_98) {
        operator_delete(local_ac[0]);
      }
      local_98 = 0xf;
      local_9c = 0;
      local_ac[0] = (void *)((uint)local_ac[0] & 0xffffff00);
      lib_fn_68f990(local_1b0,100,100);
      local_80 = 7;
      local_84 = 0;
      local_94 = (undefined4 *)((uint)local_94._2_2_ << 0x10);
      u16string_replaceRange(local_1f8,0,0xffffffff);
      local_8._0_1_ = 0xf;
      local_210 = local_84;
      if (local_84 == 0) {
        u16string_assignPtrLen(&DAT_0071ea70,0x60);
      }
      local_210 = local_84;
      local_1c8 = NamedObject_create_with_defaults(0,0,0,*(undefined4 *)(iVar6 + 0xbc),local_7c);
      *(uint *)(local_1c8 + 200) = *(uint *)(local_1c8 + 200) | 8;
      local_1f4 = 0;
      if (0 < local_210) {
        uStack_108 = 0xc2c80000;
        uStack_e0 = 0xc2c80000;
        uStack_150 = 0;
        uStack_120 = 0;
        local_104 = 0x3f19999a;
        uStack_100 = 0x3f19999a;
        local_fc = 0x3f19999a;
        uStack_f8 = 0x3f000000;
        local_11c = 0x3f4ccccd;
        uStack_118 = 0x3f4ccccd;
        local_114 = 0x3f4ccccd;
        uStack_110 = 0x3f000000;
        local_134 = 0x3f333333;
        uStack_130 = 0x3f333333;
        local_12c = 0x3f333333;
        uStack_128 = 0x3f000000;
        local_14c = 0x3f000000;
        uStack_148 = 0x3f000000;
        local_144 = 0x3f000000;
        uStack_140 = 0x3f000000;
        do {
          puVar8 = &local_94;
          if (7 < local_80) {
            puVar8 = local_94;
          }
          local_1bc[0] = *(short *)((int)puVar8 + local_1f4 * 2);
          local_1bc[1] = 0;
          puVar8 = &local_94;
          if (7 < local_80) {
            puVar8 = local_94;
          }
          FT_Load_Char(local_1b0,*(undefined2 *)((int)puVar8 + local_1f4 * 2),0x800a);
          local_30 = 7;
          local_34 = 0;
          local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
          if (local_1bc[0] == 0) {
            iVar9 = 0;
          }
          else {
            psVar12 = local_1bc;
            do {
              sVar1 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar1 != 0);
            iVar9 = (int)psVar12 - (int)(local_1bc + 1) >> 1;
          }
          u16string_assignPtrLen(local_1bc,iVar9);
          local_8._0_1_ = 0x10;
          local_1b4 = operator_new(0xc34);
          local_8._0_1_ = 0x11;
          if (local_1b4 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
            iVar6 = 0;
          }
          else {
            iVar6 = plasma::SmoothMeshShape::ctor_0(iVar6,local_44);
          }
          local_8._0_1_ = 0xf;
          if (7 < local_30) {
            operator_delete(local_44[0]);
          }
          local_30 = 7;
          local_34 = 0;
          local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
          local_c8 = 7;
          local_cc = 0;
          local_dc[0] = (void *)((uint)local_dc[0] & 0xffff0000);
          if (local_1bc[0] == 0) {
            iVar9 = 0;
          }
          else {
            psVar12 = local_1bc;
            do {
              sVar1 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar1 != 0);
            iVar9 = (int)psVar12 - (int)(local_1bc + 1) >> 1;
          }
          u16string_assignPtrLen(local_1bc,iVar9);
          local_8._0_1_ = 0x12;
          local_1ec = (undefined4 *)NamedObject_create_with_defaults(0,iVar6,0,local_1c8,local_dc);
          local_8 = CONCAT31(local_8._1_3_,0xf);
          if (7 < local_c8) {
            operator_delete(local_dc[0]);
          }
          local_dc[0] = (void *)((uint)local_dc[0] & 0xffff0000);
          local_c8 = 7;
          local_cc = 0;
          local_1ec[0x32] = local_1ec[0x32] | 8;
          CharacterStyleWidget_set_lod_level(0,1);
          iVar9 = 0;
          if (0 < (int)(*(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) & 0xfffffffcU)) {
            do {
              std_vector_resize(4);
              iVar9 = iVar9 + 1;
            } while (iVar9 < *(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) >> 2);
          }
          iVar9 = 0;
          if (0 < (int)(*(int *)(iVar6 + 0x15c) - *(int *)(iVar6 + 0x158) & 0xfffffffcU)) {
            do {
              std_vector_resize_42bf80(4);
              iVar9 = iVar9 + 1;
            } while (iVar9 < *(int *)(iVar6 + 0x15c) - *(int *)(iVar6 + 0x158) >> 2);
          }
          local_10c = (float)*(int *)(*(int *)(local_1b0 + 0x54) + 100) * 0.015625f;
          *(ulonglong *)**(undefined4 **)(*(int *)(iVar6 + 0xa8) + *(int *)(iVar6 + 0x7c) * 4) =
               CONCAT44(uStack_108,local_10c);
          local_e4 = (float)*(int *)(*(int *)(local_1b0 + 0x54) + 0x40) * 0.015625f;
          *(ulonglong *)(**(int **)(*(int *)(iVar6 + 0xa8) + *(int *)(iVar6 + 0x7c) * 4) + 8) =
               CONCAT44(uStack_e0,local_e4);
          local_154 = (float)*(int *)(*(int *)(local_1b0 + 0x54) + 0x40) * 0.015625f;
          *(ulonglong *)(**(int **)(*(int *)(iVar6 + 0xa8) + *(int *)(iVar6 + 0x7c) * 4) + 0x10) =
               CONCAT44(uStack_150,local_154);
          local_124 = (float)*(int *)(*(int *)(local_1b0 + 0x54) + 100) * 0.015625f;
          *(ulonglong *)(**(int **)(*(int *)(iVar6 + 0xa8) + *(int *)(iVar6 + 0x7c) * 4) + 0x18) =
               CONCAT44(uStack_120,local_124);
          puVar3 = (undefined8 *)**(int **)(*(int *)(iVar6 + 0x158) + *(int *)(iVar6 + 300) * 4);
          *puVar3 = CONCAT44(uStack_100,local_104);
          puVar3[1] = CONCAT44(uStack_f8,local_fc);
          iVar9 = **(int **)(*(int *)(iVar6 + 0x158) + *(int *)(iVar6 + 300) * 4);
          *(ulonglong *)(iVar9 + 0x10) = CONCAT44(uStack_118,local_11c);
          *(ulonglong *)(iVar9 + 0x18) = CONCAT44(uStack_110,local_114);
          iVar9 = **(int **)(*(int *)(iVar6 + 0x158) + *(int *)(iVar6 + 300) * 4);
          *(ulonglong *)(iVar9 + 0x20) = CONCAT44(uStack_130,local_134);
          *(ulonglong *)(iVar9 + 0x28) = CONCAT44(uStack_128,local_12c);
          iVar6 = **(int **)(*(int *)(iVar6 + 0x158) + *(int *)(iVar6 + 300) * 4);
          *(ulonglong *)(iVar6 + 0x30) = CONCAT44(uStack_148,local_14c);
          *(undefined4 *)(iVar6 + 0x38) = local_144;
          *(undefined4 *)(iVar6 + 0x3c) = uStack_140;
          local_1e8 = (_Container_base0 *)0x0;
          local_1e4 = (_Container_base0 *)0x0;
          local_1e0 = 0;
          std_vector_resize_12(1);
          local_8._0_1_ = 0x13;
          vectorInt_resize(4);
          **(undefined4 **)(local_1e4 + -0xc) = 0;
          *(undefined4 *)(*(int *)(local_1e4 + -0xc) + 4) = 1;
          *(undefined4 *)(*(int *)(local_1e4 + -0xc) + 8) = 2;
          *(undefined4 *)(*(int *)(local_1e4 + -0xc) + 0xc) = 3;
          CharacterStyleWidget_rebuild_mesh(&local_1e8,1);
          local_30 = 7;
          local_34 = 0;
          local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
          if (local_1bc[0] == 0) {
            iVar6 = 0;
          }
          else {
            psVar12 = local_1bc;
            do {
              sVar1 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar1 != 0);
            iVar6 = (int)psVar12 - (int)(local_1bc + 1) >> 1;
          }
          u16string_assignPtrLen(local_1bc,iVar6);
          local_8._0_1_ = 0x14;
          local_1b4 = operator_new(0xc34);
          local_8._0_1_ = 0x15;
          if (local_1b4 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
            iVar6 = 0;
          }
          else {
            iVar6 = plasma::SmoothMeshShape::ctor_0(local_1c4,local_44);
          }
          local_1dc = iVar6;
          local_8._0_1_ = 0x13;
          if (7 < local_30) {
            operator_delete(local_44[0]);
          }
          local_30 = 7;
          local_34 = 0;
          local_44[0] = (void *)((uint)local_44[0] & 0xffff0000);
          local_18 = 7;
          local_1c = 0;
          local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
          if (local_1bc[0] == 0) {
            iVar9 = 0;
          }
          else {
            psVar12 = local_1bc;
            do {
              sVar1 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar1 != 0);
            iVar9 = (int)psVar12 - (int)(local_1bc + 1) >> 1;
          }
          u16string_assignPtrLen(local_1bc,iVar9);
          local_8._0_1_ = 0x16;
          iVar9 = NamedObject_create_with_defaults(0,iVar6,0,local_1ec,local_2c);
          if (7 < local_18) {
            operator_delete(local_2c[0]);
          }
          local_18 = 7;
          local_1c = 0;
          local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
          *(uint *)(iVar9 + 200) = *(uint *)(iVar9 + 200) | 8;
          local_1d8 = 0;
          local_204 = (_Container_base0 *)0x0;
          local_200 = (_Container_base0 *)0x0;
          local_1fc = 0;
          local_1b8 = (int *)(local_1b0 + 0x54);
          local_218 = 0x40800000;
          local_1f0 = 0;
          if (0 < *(short *)(*local_1b8 + 0x6c)) {
            do {
              iVar6 = *local_1b8;
              iVar9 = (int)*(short *)(*(int *)(iVar6 + 0x78) + local_1f0 * 2);
              fVar20 = 0.0f;
              fVar19 = -(float)*(int *)(*(int *)(iVar6 + 0x70) + 4 + iVar9 * 8) * 0.015625f;
              local_208 = (float)*(int *)(*(int *)(iVar6 + 0x70) + iVar9 * 8) * 0.015625f;
              fVar21 = 0.0f;
              local_1bd = ~*(byte *)(*(int *)(iVar6 + 0x74) + iVar9) & 1;
              piVar18 = (int *)0x0;
              piVar13 = (int *)0x0;
              piVar14 = (int *)0x0;
              local_21c = 0.0f;
              local_214 = 0.0f;
              local_1d4 = (int *)0x0;
              local_1d0 = (int *)0x0;
              local_1cc = (int *)0x0;
              local_1b8 = (int *)*local_1b8;
              local_8._0_1_ = 0x18;
              local_1f8 = fVar19;
              if (local_1d8 <= *(short *)(*(int *)((int)local_1b8 + 0x78) + local_1f0 * 2)) {
                do {
                  iVar6 = local_1dc;
                  local_64 = (float)*(int *)(*(int *)((int)local_1b8 + 0x70) + local_1d8 * 8) *
                             0.015625f;
                  fStack_60 = -(float)*(int *)(*(int *)((int)local_1b8 + 0x70) + 4 + local_1d8 * 8)
                              * 0.015625;
                  local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)
                              (local_64 - local_208);
                  local_220 = fStack_60 - fVar19;
                  local_5c = CONCAT44(local_220,local_1b4);
                  if (0.001f <= local_220 * local_220 + (float)local_1b4 * (float)local_1b4) {
                    if ((*(byte *)(local_1d8 + *(int *)((int)local_1b8 + 0x74)) & 2) != 0) {
                      p_Var22 = endl_exref;
                      this = (basic_ostream<char,std::char_traits<char>_> *)
                             ostream_writePadded(cout_exref,"FT_CURVE_TAG_CUBIC");
                      std::basic_ostream<char,std::char_traits<char>_>::operator<<(this,p_Var22);
                      piVar13 = local_1d0;
                      piVar14 = local_1cc;
                      piVar18 = local_1d4;
                      fVar20 = local_21c;
                      fVar21 = local_214;
                    }
                    if (((float)local_1b4 * fVar21 - local_220 * fVar20 == 0.0f) &&
                       (local_220 * fVar21 + (float)local_1b4 * fVar20 < 0.0f)) {
                      lib_fn_642770((((int *)**(int **)(iVar6 + 0xa8))[1] -
                                    *(int *)**(int **)(iVar6 + 0xa8) >> 3) + -1);
                      lib_fn_642770(((int *)**(int **)(iVar6 + 0xa8))[1] -
                                   *(int *)**(int **)(iVar6 + 0xa8) >> 3);
                      lib_fn_6427e0(((int *)**(int **)(iVar6 + 0xa8))[1] -
                                   *(int *)**(int **)(iVar6 + 0xa8) >> 3);
                      lib_fn_6427e0(((int *)**(int **)(iVar6 + 0xa8))[1] -
                                   *(int *)**(int **)(iVar6 + 0xa8) >> 3);
                      lib_fn_642700(((int *)**(int **)(iVar6 + 0xa8))[1] -
                                   *(int *)**(int **)(iVar6 + 0xa8) >> 3);
                      if (*(int *)(iVar6 + 0x2c4) != *(int *)(iVar6 + 0x2c8)) {
                        *(int *)(iVar6 + 0x2c8) = *(int *)(iVar6 + 0x2c8) + -4;
                      }
                      piVar13 = local_1d0;
                      piVar14 = local_1cc;
                      piVar18 = local_1d4;
                      if (local_1d4 != local_1d0) {
                        piVar13 = local_1d0 + -1;
                        local_1d0 = piVar13;
                      }
                    }
                    local_f4 = local_5c;
                    if ((local_1bd != 0) &&
                       (iVar6 = local_1dc,
                       (*(byte *)(local_1d8 + *(int *)(*(int *)(local_1b0 + 0x54) + 0x74)) & 1) == 0
                       )) {
                      local_20c = ((int *)**(int **)(local_1dc + 0xa8))[1] -
                                  *(int *)**(int **)(local_1dc + 0xa8) >> 3;
                      if ((&local_20c < piVar13) && (piVar18 <= &local_20c)) {
                        local_1b8 = (int *)((int)&local_20c - (int)piVar18 >> 2);
                        if ((piVar13 == piVar14) && ((int)piVar14 - (int)piVar13 >> 2 == 0)) {
                          iVar9 = (int)piVar13 - (int)piVar18 >> 2;
                          if (iVar9 == 0x3fffffff) {
LAB_00652696:
                            std::_Xlength_error("vector<T> too long");
                          }
                          local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)(iVar9 + 1);
                          uVar5 = (int)piVar14 - (int)piVar18 >> 2;
                          if (0x3fffffff - (uVar5 >> 1) < uVar5) {
                            pbVar15 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
                          }
                          else {
                            pbVar15 = (basic_streambuf<char,std::char_traits<char>_> *)
                                      (uVar5 + (uVar5 >> 1));
                          }
                          if (pbVar15 < local_1b4) {
                            pbVar15 = local_1b4;
                          }
                          std_vector_grow_realloc_stride4(pbVar15);
                          piVar13 = local_1d0;
                          piVar18 = local_1d4;
                        }
                        piVar14 = (int *)0x0;
                        if (piVar13 != (int *)0x0) {
                          piVar18 = (int *)piVar18[(int)local_1b8];
LAB_00652013:
                          *piVar13 = (int)piVar18;
                          piVar14 = local_1d0;
                        }
                      }
                      else {
                        local_1b8 = (int *)local_20c;
                        if ((piVar13 == piVar14) && ((int)piVar14 - (int)piVar13 >> 2 == 0)) {
                          iVar9 = (int)piVar13 - (int)piVar18 >> 2;
                          if (iVar9 == 0x3fffffff) goto LAB_00652696;
                          local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)(iVar9 + 1);
                          uVar5 = (int)piVar14 - (int)piVar18 >> 2;
                          if (0x3fffffff - (uVar5 >> 1) < uVar5) {
                            pbVar15 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
                          }
                          else {
                            pbVar15 = (basic_streambuf<char,std::char_traits<char>_> *)
                                      (uVar5 + (uVar5 >> 1));
                          }
                          if (pbVar15 < local_1b4) {
                            pbVar15 = local_1b4;
                          }
                          std_vector_grow_realloc_stride4(pbVar15);
                          piVar13 = local_1d0;
                        }
                        piVar14 = (int *)0x0;
                        piVar18 = local_1b8;
                        if (piVar13 != (int *)0x0) goto LAB_00652013;
                      }
                      local_1d0 = piVar14 + 1;
                      _local_54 = CONCAT44(local_1f8 + fStack_60,local_208 + local_64);
                      _local_4c = CONCAT44((local_1f8 + fStack_60) * 0.5f,
                                           (local_208 + local_64) * 0.5f);
                      lib_fn_64e8f0(&local_4c);
                      local_16c = 0x3f800000;
                      local_168 = 0x3f800000;
                      local_164 = 0x3f800000;
                      local_160 = 0x3f800000;
                      lib_fn_64e9b0(&local_16c);
                      local_15c = 0;
                      local_158 = 0;
                      lib_fn_64e8f0(&local_15c);
                      local_17c = 0x3f800000;
                      local_178 = 0x3f800000;
                      local_174 = 0x3f800000;
                      local_170 = 0x3f800000;
                      lib_fn_64e9b0(&local_17c);
                      lib_fn_64e850(&local_218);
                      local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)0x1;
                      std_vector_push_back_4byte(&local_1b4);
                    }
                    local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)
                                (((int *)**(int **)(iVar6 + 0xa8))[1] -
                                 *(int *)**(int **)(iVar6 + 0xa8) >> 3);
                    std_vector_push_back_4byte(&local_1b4);
                    lib_fn_64e8f0(&local_64);
                    local_18c = 0x3f800000;
                    local_188 = 0x3f800000;
                    local_184 = 0x3f800000;
                    local_180 = 0x3f800000;
                    lib_fn_64e9b0(&local_18c);
                    local_13c = 0;
                    local_138 = 0;
                    lib_fn_64e8f0(&local_13c);
                    local_a4 = 0x3f800000;
                    local_a0 = 0x3f800000;
                    local_9c = 0x3f800000;
                    local_98 = 0x3f800000;
                    lib_fn_64e9b0(&local_a4);
                    lib_fn_64e850(&local_218);
                    iVar6 = local_1d8;
                    local_1b4 = (basic_streambuf<char,std::char_traits<char>_> *)
                                (2 - (uint)((*(byte *)(local_1d8 +
                                                      *(int *)(*(int *)(local_1b0 + 0x54) + 0x74)) &
                                            1) != 0));
                    std_vector_push_back_4byte(&local_1b4);
                    local_1b8 = *(int **)(local_1b0 + 0x54);
                    local_ec = local_64;
                    fStack_e8 = fStack_60;
                    local_1bd = ~*(byte *)(*(int *)((int)local_1b8 + 0x74) + iVar6) & 1;
                    local_214 = local_f4._4_4_;
                    local_21c = (float)local_f4;
                    local_1f8 = fStack_60;
                    local_208 = local_64;
                    piVar13 = local_1d0;
                    piVar14 = local_1cc;
                    piVar18 = local_1d4;
                    fVar20 = (float)local_f4;
                    fVar21 = local_f4._4_4_;
                    fVar19 = fStack_60;
                  }
                  local_1d8 = local_1d8 + 1;
                } while (local_1d8 <= *(short *)(*(int *)((int)local_1b8 + 0x78) + local_1f0 * 2));
              }
              iVar6 = local_1dc;
              std_vector_insert_one_stride0xc(&local_1d4);
              local_8._0_1_ = 0x17;
              local_1d8 = *(short *)(*(int *)(*(int *)(local_1b0 + 0x54) + 0x78) + local_1f0 * 2) +
                          1;
              if (local_1d4 != (int *)0x0) {
                std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1d4);
                operator_delete(local_1d4);
              }
              local_1b8 = (int *)(local_1b0 + 0x54);
              local_1f0 = local_1f0 + 1;
            } while (local_1f0 < *(short *)(*local_1b8 + 0x6c));
          }
          local_8._0_1_ = 0x17;
          *(uint *)(iVar6 + 0x85c) = *(uint *)(iVar6 + 0x85c) & 0xfffffff3 | 1;
          CharacterStyleWidget_rebuild_mesh(&local_204,1);
          local_1ec[0x32] = local_1ec[0x32] | 3;
          lib_fn_631520(local_1ac,0);
          local_8 = CONCAT31(local_8._1_3_,0x13);
          if (local_204 != (_Container_base0 *)0x0) {
            std::_Container_base0::_Orphan_all((_Container_base0 *)&local_204);
            p_Var17 = local_204;
            while( true ) {
              if (p_Var17 == local_200) {
                operator_delete(local_204);
              }
              if (*(int *)p_Var17 != 0) break;
              p_Var17 = p_Var17 + 0xc;
            }
            std::_Container_base0::_Orphan_all(p_Var17);
            operator_delete(*(void **)p_Var17);
          }
          local_8._0_1_ = 0xf;
          if (local_1e8 != (_Container_base0 *)0x0) {
            std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1e8);
            p_Var17 = local_1e8;
            while( true ) {
              if (p_Var17 == local_1e4) {
                operator_delete(local_1e8);
              }
              if (*(int *)p_Var17 != 0) break;
              p_Var17 = p_Var17 + 0xc;
            }
            std::_Container_base0::_Orphan_all(p_Var17);
            operator_delete(*(void **)p_Var17);
          }
          local_1f4 = local_1f4 + 1;
          iVar6 = local_1c4;
        } while (local_1f4 < local_210);
      }
      FT_Remove_GlyphSlot(local_1b0);
      uVar7 = copy_two_words(local_2c,local_1a4);
      local_8._0_1_ = 0x19;
      iVar6 = lib_fn_64fda0(local_1c8,uVar7);
      local_8._0_1_ = 0xf;
      if (7 < local_18) {
        operator_delete(local_2c[0]);
      }
      local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
      local_18 = 7;
      local_1c = 0;
      if ((undefined4 ********)(iVar6 + 0x34) != local_7c) {
        u16string_replaceRange(local_7c,0,0xffffffff);
      }
      *(undefined4 *)(iVar6 + 0x4c) = param_2;
      *(undefined4 *)(iVar6 + 0x50) = 0;
      if (7 < local_80) {
        operator_delete(local_94);
      }
      local_80 = 7;
      local_84 = 0;
      local_94 = (undefined4 *)((uint)local_94 & 0xffff0000);
      if (0xf < local_190) {
        operator_delete(local_1a4[0]);
      }
      local_190 = 0xf;
      local_194 = 0;
      local_1a4[0] = (void *)((uint)local_1a4[0] & 0xffffff00);
    }
  }
  if (7 < local_b0) {
    operator_delete(local_c4);
  }
  local_b0 = 7;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffff0000);
  ctor_1();
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_268);
LAB_00652666:
  if (7 < local_68) {
    operator_delete(local_7c[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::lib_fn_653210 @ 00653210 */

basic_streambuf<char,std::char_traits<char>_> *
lib_fn_653210(wchar_t *param_1,int param_2,int *param_3)

{
  bool bVar1;
  uint uVar2;
  _iobuf *p_Var3;
  undefined4 uVar4;
  codecvt_base *this;
  undefined4 *puVar5;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e1968;
  local_10 = ExceptionList;
  uVar2 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x50) == 0) {
    p_Var3 = std::_Fiopen(param_1,param_2,(int)param_3);
    if (p_Var3 != (_iobuf *)0x0) {
      in_ECX[0x4c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
      in_ECX[0x45] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(in_ECX);
      *(char ***)(in_ECX + 0xc) = &p_Var3->_base;
      *(char ***)(in_ECX + 0x10) = &p_Var3->_base;
      *(int **)(in_ECX + 0x2c) = &p_Var3->_cnt;
      *(int **)(in_ECX + 0x30) = &p_Var3->_cnt;
      *(_iobuf **)(in_ECX + 0x1c) = p_Var3;
      *(_iobuf **)(in_ECX + 0x20) = p_Var3;
      *(_iobuf **)(in_ECX + 0x50) = p_Var3;
      *(undefined4 *)(in_ECX + 0x48) = DAT_0076af5c;
      *(undefined4 *)(in_ECX + 0x40) = 0;
      uVar4 = std::basic_streambuf<char,std::char_traits<char>_>::getloc(in_ECX);
      local_8 = 0;
      this = (codecvt_base *)std_locale_getfacet(uVar4,uVar2);
      bVar1 = std::codecvt_base::always_noconv(this);
      if (bVar1) {
        *(undefined4 *)(in_ECX + 0x40) = 0;
      }
      else {
        *(codecvt_base **)(in_ECX + 0x40) = this;
        std::basic_streambuf<char,std::char_traits<char>_>::_Init(in_ECX);
      }
      local_8 = 0xffffffff;
      if (param_3 != (int *)0x0) {
        puVar5 = (undefined4 *)(**(code **)(*param_3 + 8))();
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)(1);
        }
      }
      ExceptionList = local_10;
      return in_ECX;
    }
  }
  ExceptionList = local_10;
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_7 @ 00657480 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_7
               (undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 ****ppppuVar6;
  int iVar7;
  int in_ECX;
  int *piVar8;
  code *pcVar9;
  undefined ***pppuVar10;
  int local_13c [4];
  undefined **local_12c [2];
  basic_istream<char,std::char_traits<char>_> local_124 [4];
  int *local_120;
  char *local_f4;
  char *local_f0;
  undefined4 local_ec;
  undefined1 local_e8;
  undefined1 local_e7;
  undefined4 local_e4;
  char local_e0;
  FILE *local_dc;
  basic_ios<char,std::char_traits<char>_> local_cc [72];
  int local_84;
  undefined8 local_80;
  int local_78;
  void *local_74 [5];
  uint local_60;
  void *local_5c [3];
  void *local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  int local_34;
  uint local_30;
  undefined4 ***local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f6c06;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_80 = CONCAT44(param_1,(undefined4)local_80);
  local_78 = 0x2f;
  iVar2 = std_string_rfind_substr(&local_78,0xffffffff,1);
  local_78 = 0x5c;
  local_84 = iVar2;
  local_78 = std_string_rfind_substr(&local_78,0xffffffff,1);
  piVar8 = &local_78;
  if (local_78 <= iVar2) {
    piVar8 = &local_84;
  }
  wstring_ctorFromRange(local_2c,*piVar8 + 1,(param_1[4] - *piVar8) + -1);
  local_30 = 7;
  local_34 = 0;
  local_44 = (void *)((uint)local_44._2_2_ << 0x10);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  ctor_10(1);
  local_8._0_1_ = 2;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  iVar2 = lib_fn_653210(param_1,0x21,0x40);
  if (iVar2 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)
               ((int)local_13c + *(int *)(local_13c[0] + 4)),2,false);
  }
  else {
    std::basic_ios<char,std::char_traits<char>_>::clear
              ((basic_ios<char,std::char_traits<char>_> *)
               ((int)local_13c + *(int *)(local_13c[0] + 4)),0,false);
  }
  pcVar9 = fclose_exref;
  if (local_dc == (FILE *)0x0) {
    piVar8 = (int *)**(int **)(in_ECX + 0x13c);
    if (piVar8 != *(int **)(in_ECX + 0x13c)) {
      do {
        uVar3 = wstring_ctorAppend(local_74,piVar8 + 2,&DAT_006fd42c);
        local_8._0_1_ = 3;
        puVar4 = (undefined4 *)string_assign(local_5c,uVar3,local_2c);
        local_8 = CONCAT31(local_8._1_3_,4);
        if (7 < (uint)puVar4[5]) {
          puVar4 = (undefined4 *)*puVar4;
        }
        iVar2 = lib_fn_653210(puVar4,0x21,0x40);
        if (iVar2 == 0) {
          std::basic_ios<char,std::char_traits<char>_>::setstate
                    ((basic_ios<char,std::char_traits<char>_> *)
                     ((int)local_13c + *(int *)(local_13c[0] + 4)),2,false);
        }
        else {
          std::basic_ios<char,std::char_traits<char>_>::clear
                    ((basic_ios<char,std::char_traits<char>_> *)
                     ((int)local_13c + *(int *)(local_13c[0] + 4)),0,false);
        }
        if (7 < local_48) {
          operator_delete(local_5c[0]);
        }
        local_48 = 7;
        local_4c = 0;
        local_5c[0] = (void *)((uint)local_5c[0] & 0xffff0000);
        local_8._0_1_ = 2;
        if (7 < local_60) {
          operator_delete(local_74[0]);
        }
        if (local_dc != (FILE *)0x0) {
          if (&local_44 != piVar8 + 2) {
            u16string_replaceRange(piVar8 + 2,0,0xffffffff);
          }
          if (local_dc != (FILE *)0x0) goto LAB_006576d8;
          break;
        }
        piVar8 = (int *)*piVar8;
      } while (piVar8 != (int *)*(int *)(in_ECX + 0x13c));
    }
    pvVar5 = operator_new(0x70);
    local_80 = CONCAT44(pvVar5,(undefined4)local_80);
    local_8._0_1_ = 5;
    if (pvVar5 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = plasma::PlasmaFont::ctor_0(in_ECX,local_2c);
    }
    local_8._0_1_ = 2;
    if ((undefined4 ****)(iVar2 + 0x34) != local_2c) {
      u16string_replaceRange(local_2c,0,0xffffffff);
    }
  }
  else {
LAB_006576d8:
    pppuVar10 = local_12c;
    if (local_dc == (FILE *)0x0) {
      pppuVar10 = (undefined ***)0x0;
    }
    else {
      cVar1 = filebuf_endWrite();
      if (cVar1 == '\0') {
        pppuVar10 = (undefined ***)0x0;
      }
      iVar2 = fclose(local_dc);
      if (iVar2 != 0) {
        pppuVar10 = (undefined ***)0x0;
      }
    }
    local_e0 = '\0';
    local_e7 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)local_12c);
    local_dc = (FILE *)0x0;
    local_e4 = DAT_0076af5c;
    local_ec = 0;
    if (pppuVar10 == (undefined ***)0x0) {
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((int)local_13c + *(int *)(local_13c[0] + 4)),2,false);
    }
    iVar2 = 0;
    piVar8 = (int *)**(int **)(*(int *)(in_ECX + 0xbc) + 0x2c);
    if (piVar8 != *(int **)(*(int *)(in_ECX + 0xbc) + 0x2c)) {
      do {
        ppppuVar6 = local_2c;
        if (7 < local_18) {
          ppppuVar6 = (undefined4 ****)local_2c[0];
        }
        iVar7 = u16string_compare(0,*(undefined4 *)(piVar8[2] + 0x1c),ppppuVar6,local_1c);
        if (iVar7 == 0) {
          iVar2 = piVar8[2];
          break;
        }
        piVar8 = (int *)*piVar8;
      } while (piVar8 != (int *)*(int *)(*(int *)(in_ECX + 0xbc) + 0x2c));
    }
    if (local_34 == 0) {
      if (&local_44 != local_80._4_4_) {
        u16string_replaceRange(local_80._4_4_,0,0xffffffff);
      }
    }
    else {
      uVar3 = lib_fn_64b2e0(local_74,&DAT_006fd42c,local_2c);
      local_8._0_1_ = 6;
      std_u16string_replace(uVar3,0,0xffffffff);
      local_8._0_1_ = 2;
      if (7 < local_60) {
        operator_delete(local_74[0]);
      }
    }
    if (iVar2 == 0) {
      iVar2 = NamedObject_create_with_defaults(0,0,0,*(undefined4 *)(in_ECX + 0xbc),local_2c);
      local_80 = 0;
      local_50 = (void *)0x0;
      local_4c = 0;
      local_48 = 0;
      vector_fill_pairElem(1,&local_80);
      local_8._0_1_ = 7;
      GameController_load_widget_file(&local_44,iVar2,7,0,&local_50);
      local_8._0_1_ = 2;
      if (local_50 != (void *)0x0) {
        operator_delete(local_50);
      }
      *(uint *)(iVar2 + 200) = *(uint *)(iVar2 + 200) | 8;
    }
    iVar2 = lib_fn_64fda0(iVar2,local_2c);
    if ((undefined4 ****)(iVar2 + 0x34) != local_2c) {
      u16string_replaceRange(local_2c,0,0xffffffff);
    }
    pcVar9 = fclose_exref;
    *(undefined4 *)(iVar2 + 0x50) = 0;
  }
  *(undefined4 *)(iVar2 + 0x4c) = param_2;
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined ***)((int)local_13c + *(int *)(local_13c[0] + 4)) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(&stack0xfffffec0 + *(int *)(local_13c[0] + 4)) = *(int *)(local_13c[0] + 4) + -0x70;
  local_12c[0] = vftable;
  if ((local_dc != (FILE *)0x0) && ((undefined1 *)*local_120 == &local_e8)) {
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              ((basic_streambuf<char,std::char_traits<char>_> *)local_12c,local_f4,local_f0,local_f0
              );
  }
  if (local_e0 != '\0') {
    if (local_dc != (FILE *)0x0) {
      filebuf_endWrite();
      (*pcVar9)(local_dc);
    }
    local_e0 = '\0';
    local_e7 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)local_12c);
    local_dc = (FILE *)0x0;
    local_e4 = DAT_0076af5c;
    local_ec = 0;
  }
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_12c);
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            (local_124);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_cc);
  if (local_30 < 8) {
    local_30 = 7;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffff0000);
    if (local_18 < 8) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    operator_delete(local_2c[0]);
  }
  operator_delete(local_44);
}




/* Global::eh_catchall_0065a0c2 @ 0065a0c2 */

void Catch_All_0065a0c2(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
}




/* Global::eh_catchall_0065a601 @ 0065a601 */

void Catch_All_0065a601(void)

{
  int unaff_EBP;
  
  lib_fn_65aeb0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0065a83f @ 0065a83f */

void Catch_All_0065a83f(void)

{
  int unaff_EBP;
  
  lib_fn_65aeb0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::lib_fn_65aeb0 @ 0065aeb0 */

void lib_fn_65aeb0(void *param_1)

{
  if (*(void **)((int)param_1 + 0x18) != (void *)0x0) {
    operator_delete(*(void **)((int)param_1 + 0x18));
  }
  operator_delete(param_1);
}




/* std::basic_filebuf<char,std::char_traits<char>_>::ctor_6 @ 0065f3d0 */

void std::basic_filebuf<char,std::char_traits<char>_>::ctor_6(undefined4 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 **ppuVar9;
  float *pfVar10;
  undefined8 *puVar11;
  ushort ****ppppuVar12;
  int in_ECX;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  float fVar16;
  int local_188 [4];
  undefined **local_178 [2];
  basic_istream<char,std::char_traits<char>_> local_170 [4];
  int *local_16c;
  char *local_140;
  char *local_13c;
  undefined4 local_138;
  undefined1 local_134;
  undefined1 local_133;
  undefined4 local_130;
  char local_12c;
  FILE *local_128;
  basic_ios<char,std::char_traits<char>_> local_118 [72];
  int local_d0;
  float local_cc;
  LPCRITICAL_SECTION local_c8;
  float local_c4;
  float local_c0;
  undefined4 *local_bc;
  undefined4 *local_b8;
  undefined4 *local_b4;
  undefined1 local_b0 [8];
  void *local_a8 [4];
  undefined4 local_98;
  uint local_94;
  float local_90;
  float fStack_8c;
  float local_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  void *local_68;
  undefined4 local_64;
  undefined4 local_60;
  ushort ***local_5c [4];
  undefined4 local_4c;
  uint local_48;
  undefined8 local_44;
  float local_3c;
  float fStack_38;
  float local_34;
  float fStack_30;
  float local_2c;
  float fStack_28;
  float local_24;
  float fStack_20;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f70d6;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 0x10c);
  local_d0 = in_ECX;
  local_c8 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  ctor_10(1);
  local_8 = 0;
  puVar7 = param_1;
  if (7 < (uint)param_1[5]) {
    puVar7 = (undefined4 *)*param_1;
  }
  iVar6 = lib_fn_653210(puVar7,0x21,0x40);
  if (iVar6 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)
               ((int)local_188 + *(int *)(local_188[0] + 4)),2,false);
  }
  else {
    std::basic_ios<char,std::char_traits<char>_>::clear
              ((basic_ios<char,std::char_traits<char>_> *)
               ((int)local_188 + *(int *)(local_188[0] + 4)),0,false);
  }
  if (local_128 == (FILE *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    iVar6 = filebuf_close();
    if (iVar6 == 0) {
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((int)local_188 + *(int *)(local_188[0] + 4)),2,false);
    }
    local_b4 = (undefined4 *)0x2f;
    puVar7 = (undefined4 *)std_string_rfind_substr(&local_b4,0xffffffff,1);
    local_b4 = (undefined4 *)0x5c;
    local_b8 = puVar7;
    local_b4 = (undefined4 *)std_string_rfind_substr(&local_b4,0xffffffff,1);
    ppuVar9 = &local_b4;
    if ((int)local_b4 <= (int)puVar7) {
      ppuVar9 = &local_b8;
    }
    wstring_ctorFromRange(local_a8,(int)*ppuVar9 + 1,(param_1[4] - (int)*ppuVar9) + -1);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar8 = NamedObject_create_with_defaults(0,0,0,0,local_a8);
    *(undefined4 *)(in_ECX + 0xf4) = uVar8;
    if ((void **)(in_ECX + 0x38) != local_a8) {
      u16string_replaceRange(local_a8,0,0xffffffff);
    }
    u16string_assignPtrLen(&PTR_006fccac,0);
    local_44 = 0;
    local_68 = (void *)0x0;
    local_64 = 0;
    local_60 = 0;
    vector_fill_pairElem(1,&local_44);
    local_8._0_1_ = 2;
    GameController_load_widget_file(param_1,*(undefined4 *)(in_ECX + 0xf4),3,0,&local_68);
    local_8._0_1_ = 1;
    if (local_68 != (void *)0x0) {
      operator_delete(local_68);
    }
    puVar1 = (uint *)(*(int *)(in_ECX + 0xf4) + 200);
    *puVar1 = *puVar1 | 8;
    *(undefined4 *)(in_ECX + 0xf8) = 0;
    *(undefined4 *)(in_ECX + 0xfc) = 0;
    *(undefined4 *)(in_ECX + 0x100) = 0;
    *(undefined4 *)(in_ECX + 0x104) = 0;
    piVar14 = (int *)**(int **)(*(int *)(in_ECX + 0xf4) + 0x2c);
    if (piVar14 != *(int **)(*(int *)(in_ECX + 0xf4) + 0x2c)) {
      do {
        local_8._0_1_ = 1;
        iVar6 = piVar14[2];
        if ((*(int *)(iVar6 + 0x1c) == 1) && (*(int *)(iVar6 + 0x34) != 0)) {
          local_5c[0] = (ushort ***)((uint)local_5c[0] & 0xffff0000);
          local_48 = 7;
          local_4c = 0;
          u16string_replaceRange(iVar6 + 0xc,0,0xffffffff);
          puVar7 = *(undefined4 **)(in_ECX + 0xd0);
          ppppuVar12 = local_5c;
          if (7 < local_48) {
            ppppuVar12 = (ushort ****)local_5c[0];
          }
          local_8._0_1_ = 3;
          local_b4 = (undefined4 *)(uint)*(ushort *)ppppuVar12;
          cVar4 = *(char *)((int)puVar7[1] + 0xd);
          puVar5 = puVar7;
          puVar15 = (undefined4 *)puVar7[1];
          while (cVar4 == '\0') {
            if ((int)puVar15[4] < (int)local_b4) {
              puVar13 = (undefined4 *)puVar15[2];
              puVar15 = puVar5;
            }
            else {
              puVar13 = (undefined4 *)*puVar15;
            }
            puVar5 = puVar15;
            puVar15 = puVar13;
            in_ECX = local_d0;
            cVar4 = *(char *)((int)puVar13 + 0xd);
          }
          if ((puVar5 == puVar7) || ((int)local_b4 < (int)puVar5[4])) {
            local_bc = puVar7;
            ppuVar9 = &local_bc;
          }
          else {
            local_b8 = puVar5;
            ppuVar9 = &local_b8;
          }
          if (*ppuVar9 == puVar7) {
            iVar6 = *(int *)(piVar14[2] + 0x38);
            pfVar10 = (float *)(**(code **)(**(int **)(piVar14[2] + 0x34) + 0x18))(local_b0);
            fVar2 = pfVar10[1];
            fVar3 = *pfVar10;
            local_90 = *(float *)(iVar6 + 0x1c0) * fVar2 + *(float *)(iVar6 + 0x1b0) * fVar3 +
                       *(float *)(iVar6 + 0x1e0);
            local_cc = 1.0f / (*(float *)(iVar6 + 0x1bc) * fVar3 + *(float *)(iVar6 + 0x1cc) * fVar2
                             + *(float *)(iVar6 + 0x1ec));
            fStack_8c = *(float *)(iVar6 + 0x1b4) * fVar3 + *(float *)(iVar6 + 0x1c4) * fVar2 +
                        *(float *)(iVar6 + 0x1e4);
            iVar6 = *(int *)(piVar14[2] + 0x38);
            local_70 = CONCAT44(fStack_8c,local_90);
            local_c4 = local_cc * local_90;
            local_cc = local_cc * fStack_8c;
            pfVar10 = (float *)(**(code **)(**(int **)(piVar14[2] + 0x34) + 0x1c))(&local_64);
            fVar2 = pfVar10[1];
            fVar3 = *pfVar10;
            fVar16 = 1.0f / (*(float *)(iVar6 + 0x1bc) * fVar3 + *(float *)(iVar6 + 0x1cc) * fVar2 +
                           *(float *)(iVar6 + 0x1ec));
            fStack_7c = *(float *)(iVar6 + 0x1b4) * fVar3 + *(float *)(iVar6 + 0x1c4) * fVar2 +
                        *(float *)(iVar6 + 0x1e4);
            local_80 = *(float *)(iVar6 + 0x1b0) * fVar3 + *(float *)(iVar6 + 0x1c0) * fVar2 +
                       *(float *)(iVar6 + 0x1e0);
            local_c0 = fVar16 * fStack_7c;
            _local_3c = CONCAT44(local_c0,fVar16 * local_80);
            lib_fn_631db0(&local_78,0);
            lib_fn_631520(&local_44,0);
            if ((~(byte)(*(uint *)(piVar14[2] + 200) >> 1) & 1) == 0) {
              Node_set_shape_slot(0);
            }
            puVar11 = operator_new(0x34);
            ppppuVar12 = local_5c;
            if (7 < local_48) {
              ppppuVar12 = (ushort ****)local_5c[0];
            }
            local_b4 = (undefined4 *)(uint)*(ushort *)ppppuVar12;
            puVar7 = (undefined4 *)rbtree_findOrInsert_intKey(&local_b4);
            local_2c = local_3c - local_c4;
            local_88 = local_c4;
            *puVar7 = puVar11;
            iVar6 = piVar14[2];
            fStack_28 = fStack_38 - local_cc;
            puVar11[2] = CONCAT44(fStack_28,local_2c);
            local_34 = local_3c - local_c4;
            fStack_30 = fStack_38 - local_cc;
            puVar11[1] = CONCAT44(fStack_30,local_34);
            fStack_84 = local_c0;
            local_1c = CONCAT44(local_c0 * -1.0f,local_c4 * -1.0f);
            *puVar11 = local_1c;
            *(int *)((int)puVar11 + 0x2c) = iVar6;
            *(undefined4 *)(puVar11 + 3) = local_78;
            *(undefined4 *)((int)puVar11 + 0x1c) = local_74;
            *(undefined4 *)(puVar11 + 4) = (undefined4)local_44;
            *(undefined4 *)((int)puVar11 + 0x24) = local_44._4_4_;
            *(undefined4 *)(puVar11 + 5) = 0;
            *(undefined1 *)(puVar11 + 6) = 1;
            *(undefined4 *)(in_ECX + 0xf8) = *(undefined4 *)puVar11;
            *(undefined4 *)(in_ECX + 0xfc) = *(undefined4 *)((int)puVar11 + 4);
            local_24 = (float)*puVar11;
            local_24 = *(float *)(puVar11 + 1) + local_24;
            fStack_20 = (float)((ulonglong)*puVar11 >> 0x20);
            fStack_20 = *(float *)((int)puVar11 + 0xc) + fStack_20;
            *(float *)(in_ECX + 0x100) = local_24;
            *(float *)(in_ECX + 0x104) = fStack_20;
          }
          local_8._0_1_ = 1;
          if (7 < local_48) {
            operator_delete(local_5c[0]);
          }
        }
        piVar14 = (int *)*piVar14;
      } while (piVar14 != (int *)*(int *)(*(int *)(in_ECX + 0xf4) + 0x2c));
    }
    local_8._0_1_ = 1;
    LeaveCriticalSection(local_c8);
    if (7 < local_94) {
      operator_delete(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = (void *)((uint)local_a8[0] & 0xffff0000);
  }
  local_8 = 0xffffffff;
  *(undefined ***)((int)local_188 + *(int *)(local_188[0] + 4)) =
       basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(&stack0xfffffe74 + *(int *)(local_188[0] + 4)) = *(int *)(local_188[0] + 4) + -0x70;
  local_178[0] = vftable;
  if ((local_128 != (FILE *)0x0) && ((undefined1 *)*local_16c == &local_134)) {
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              ((basic_streambuf<char,std::char_traits<char>_> *)local_178,local_140,local_13c,
               local_13c);
  }
  if (local_12c != '\0') {
    if (local_128 != (FILE *)0x0) {
      filebuf_endWrite();
      fclose(local_128);
    }
    local_12c = '\0';
    local_133 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)local_178);
    local_128 = (FILE *)0x0;
    local_130 = DAT_0076af5c;
    local_138 = 0;
  }
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)local_178);
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            (local_170);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_118);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Global::eh_catchall_0066145d @ 0066145d */

void Catch_All_0066145d(void)

{
  int unaff_EBP;
  
  lib_fn_5947a0(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0066311a @ 0066311a */

void Catch_All_0066311a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
    std_basic_string_Tidy(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00663953 @ 00663953 */

void Catch_All_00663953(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x5c);
  iVar1 = *(int *)(unaff_EBP + -0x50);
  pvVar2 = *(void **)(unaff_EBP + -0x6c);
  if (1 < iVar3) {
    std_Destroy_range_catch(pvVar2,(void *)((int)pvVar2 + iVar1 * 0x18));
    iVar3 = *(int *)(unaff_EBP + -0x5c);
  }
  if (0 < iVar3) {
    std_Destroy_range_catch((void *)((int)pvVar2 + iVar1 * 0x18),
                 (void *)((int)pvVar2 + (*(int *)(unaff_EBP + -0x68) + iVar1) * 0x18));
  }
  operator_delete(pvVar2);
}




/* Global::eh_catchall_00663a79 @ 00663a79 */

void Catch_All_00663a79(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x68) * 0x18;
  std_Destroy_range_catch(*(int *)(unaff_EBP + 0xc) + iVar1,*(int *)(*(int *)(unaff_EBP + -100) + 4) + iVar1);
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00665c71 @ 00665c71 */

void Catch_All_00665c71(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_00666069 @ 00666069 */

void Catch_All_00666069(void)

{
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0066826a @ 0066826a */

void Catch_All_0066826a(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_006684b8 @ 006684b8 */

void Catch_All_006684b8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
}




/* Global::eh_catchall_0066874c @ 0066874c */

void Catch_All_0066874c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
}




/* Global::eh_catchall_0066892c @ 0066892c */

void Catch_All_0066892c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_00668a1f @ 00668a1f */

void Catch_All_00668a1f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* std::bad_alloc::ctor_10 @ 0066cd60 */


void std::bad_alloc::ctor_10(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined8 *puVar8;
  char *pcVar9;
  uint local_90;
  missing_wait local_80 [12];
  char *local_74;
  int local_70;
  _StructuredTaskCollection local_6c [4];
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_4c;
  undefined4 *local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  int *piStack_38;
  undefined4 local_34;
  undefined **ppuStack_30;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7e30;
  local_10 = ExceptionList;
  local_90 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_3 != 1) {
    param_2 = (int)(param_2 - 1) / *param_3 + 1;
  }
  local_40 = param_2;
  local_14 = local_90;
  local_20 = (char *)Concurrency::details::_CurrentScheduler::_GetNumberOfVirtualProcessors();
  local_4c = Concurrency::details::
             _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>
             ::vftable;
  local_48 = (undefined4 *)0x0;
  local_44 = 0;
  uVar4 = (int)local_20 * 0x2c + 8;
  local_8 = 0;
  if (uVar4 < 0x401) {
    puVar3 = &local_90;
    local_24 = &local_90;
    if (&stack0x00000000 == (undefined1 *)0x90) goto LAB_0066ce17;
    local_90 = 0xcccc;
  }
  else {
    puVar3 = malloc(uVar4);
    local_24 = puVar3;
    if (puVar3 == (undefined4 *)0x0) goto LAB_0066ce17;
    *puVar3 = 0xdddd;
  }
  local_24 = puVar3 + 2;
  if (local_24 != (undefined4 *)0x0) {
    local_5c = 0;
    local_18 = 0;
    local_54 = 0;
    local_58 = 0x80000000;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    }
    local_60 = 0;
    local_68 = 0x1fffffff;
    local_64 = 0;
    local_70 = (int)param_2 / (int)local_20;
    local_1c = (char *)((int)param_2 % (int)local_20);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_70 == 0) {
      local_20 = local_1c;
    }
    local_20 = local_20 + -1;
    ppuVar7 = (undefined **)0x0;
    pcVar9 = (char *)0x0;
    local_48 = local_24;
    if (0 < (int)local_20) {
      puVar8 = (undefined8 *)(puVar3 + 7);
      iVar5 = 0;
      local_74 = local_20;
      do {
        iVar6 = local_70;
        if (0 < (int)local_1c) {
          local_1c = local_1c + -1;
          iVar6 = local_70 + 1;
        }
        local_18 = iVar6;
        if (puVar8 != (undefined8 *)0x14) {
          local_3c = param_1;
          piStack_38 = param_3;
          *puVar8 = CONCAT44(param_3,param_1);
          local_34 = param_4;
          ppuStack_30 = ppuVar7;
          puVar8[1] = CONCAT44(ppuVar7,param_4);
          uStack_28 = 0;
          local_2c = (int)ppuVar7 + iVar6;
          *(undefined4 *)((int)puVar8 + -0xc) = 0;
          *(undefined ***)((int)puVar8 + -0x14) =
               Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
               ::vftable;
          puVar8[2] = (ulonglong)(uint)((int)ppuVar7 + iVar6);
          *(code **)(puVar8 + -2) = lib_fn_66cd10;
        }
        iVar5 = iVar5 + 1;
        local_44 = iVar5;
        *(undefined1 *)((int)puVar8 + -4) = 0;
        Concurrency::details::_StructuredTaskCollection::_Schedule
                  (local_6c,(_UnrealizedChore *)((int)puVar8 + -0x14));
        ppuVar7 = (undefined **)((int)ppuVar7 + local_18);
        puVar8 = (undefined8 *)((int)puVar8 + 0x2c);
        local_20 = local_20 + -1;
      } while (local_20 != (char *)0x0);
      local_20 = (char *)0x0;
      pcVar9 = local_74;
      local_18 = iVar5;
    }
    uVar4 = local_40;
    puVar1 = local_24 + (int)pcVar9 * 0xb;
    if (puVar1 != (undefined4 *)0x0) {
      local_3c = param_1;
      piStack_38 = param_3;
      *(ulonglong *)(puVar1 + 5) = CONCAT44(param_3,param_1);
      local_34 = param_4;
      ppuStack_30 = ppuVar7;
      *(ulonglong *)(puVar1 + 7) = CONCAT44(ppuVar7,param_4);
      local_2c = uVar4;
      uStack_28 = 0;
      puVar1[2] = 0;
      *puVar1 = Concurrency::
                task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
                ::vftable;
      *(ulonglong *)(puVar1 + 9) = (ulonglong)uVar4;
      puVar1[1] = lib_fn_66cd10;
    }
    local_44 = local_18 + 1;
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_6c);
    local_8 = local_8 & 0xffffff00;
    if (0 < local_5c) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_6c);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_64 != 0) && (local_64 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
        }
        Concurrency::missing_wait::missing_wait(local_80);
        _CxxThrowException(local_80,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_64 != 0) && (local_64 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
    }
    local_8 = 0xffffffff;
    Concurrency::details::_Chore::ctor_14();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0066ce17:
  local_1c = "bad allocation";
  std::exception::exception((exception *)&ppuStack_30,&local_1c,1);
  ppuStack_30 = vftable;
  _CxxThrowException(&ppuStack_30,(ThrowInfo *)&DAT_0075f410);
}




/* std::bad_alloc::ctor_7 @ 0066d070 */


void std::bad_alloc::ctor_7(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined8 *puVar8;
  char *pcVar9;
  uint local_90;
  missing_wait local_80 [12];
  char *local_74;
  int local_70;
  _StructuredTaskCollection local_6c [4];
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_4c;
  undefined4 *local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  int *piStack_38;
  undefined4 local_34;
  undefined **ppuStack_30;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7e70;
  local_10 = ExceptionList;
  local_90 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_3 != 1) {
    param_2 = (int)(param_2 - 1) / *param_3 + 1;
  }
  local_40 = param_2;
  local_14 = local_90;
  local_20 = (char *)Concurrency::details::_CurrentScheduler::_GetNumberOfVirtualProcessors();
  local_4c = Concurrency::details::
             _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>
             ::vftable;
  local_48 = (undefined4 *)0x0;
  local_44 = 0;
  uVar4 = (int)local_20 * 0x2c + 8;
  local_8 = 0;
  if (uVar4 < 0x401) {
    puVar3 = &local_90;
    local_24 = &local_90;
    if (&stack0x00000000 == (undefined1 *)0x90) goto LAB_0066d127;
    local_90 = 0xcccc;
  }
  else {
    puVar3 = malloc(uVar4);
    local_24 = puVar3;
    if (puVar3 == (undefined4 *)0x0) goto LAB_0066d127;
    *puVar3 = 0xdddd;
  }
  local_24 = puVar3 + 2;
  if (local_24 != (undefined4 *)0x0) {
    local_5c = 0;
    local_18 = 0;
    local_54 = 0;
    local_58 = 0x80000000;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    }
    local_60 = 0;
    local_68 = 0x1fffffff;
    local_64 = 0;
    local_70 = (int)param_2 / (int)local_20;
    local_1c = (char *)((int)param_2 % (int)local_20);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_70 == 0) {
      local_20 = local_1c;
    }
    local_20 = local_20 + -1;
    ppuVar7 = (undefined **)0x0;
    pcVar9 = (char *)0x0;
    local_48 = local_24;
    if (0 < (int)local_20) {
      puVar8 = (undefined8 *)(puVar3 + 7);
      iVar5 = 0;
      local_74 = local_20;
      do {
        iVar6 = local_70;
        if (0 < (int)local_1c) {
          local_1c = local_1c + -1;
          iVar6 = local_70 + 1;
        }
        local_18 = iVar6;
        if (puVar8 != (undefined8 *)0x14) {
          local_3c = param_1;
          piStack_38 = param_3;
          *puVar8 = CONCAT44(param_3,param_1);
          local_34 = param_4;
          ppuStack_30 = ppuVar7;
          puVar8[1] = CONCAT44(ppuVar7,param_4);
          uStack_28 = 0;
          local_2c = (int)ppuVar7 + iVar6;
          *(undefined4 *)((int)puVar8 + -0xc) = 0;
          *(undefined ***)((int)puVar8 + -0x14) =
               Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
               ::vftable;
          puVar8[2] = (ulonglong)(uint)((int)ppuVar7 + iVar6);
          *(code **)(puVar8 + -2) = lib_fn_66cd20;
        }
        iVar5 = iVar5 + 1;
        local_44 = iVar5;
        *(undefined1 *)((int)puVar8 + -4) = 0;
        Concurrency::details::_StructuredTaskCollection::_Schedule
                  (local_6c,(_UnrealizedChore *)((int)puVar8 + -0x14));
        ppuVar7 = (undefined **)((int)ppuVar7 + local_18);
        puVar8 = (undefined8 *)((int)puVar8 + 0x2c);
        local_20 = local_20 + -1;
      } while (local_20 != (char *)0x0);
      local_20 = (char *)0x0;
      pcVar9 = local_74;
      local_18 = iVar5;
    }
    uVar4 = local_40;
    puVar1 = local_24 + (int)pcVar9 * 0xb;
    if (puVar1 != (undefined4 *)0x0) {
      local_3c = param_1;
      piStack_38 = param_3;
      *(ulonglong *)(puVar1 + 5) = CONCAT44(param_3,param_1);
      local_34 = param_4;
      ppuStack_30 = ppuVar7;
      *(ulonglong *)(puVar1 + 7) = CONCAT44(ppuVar7,param_4);
      local_2c = uVar4;
      uStack_28 = 0;
      puVar1[2] = 0;
      *puVar1 = Concurrency::
                task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
                ::vftable;
      *(ulonglong *)(puVar1 + 9) = (ulonglong)uVar4;
      puVar1[1] = lib_fn_66cd20;
    }
    local_44 = local_18 + 1;
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_6c);
    local_8 = local_8 & 0xffffff00;
    if (0 < local_5c) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_6c);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_64 != 0) && (local_64 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
        }
        Concurrency::missing_wait::missing_wait(local_80);
        _CxxThrowException(local_80,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_64 != 0) && (local_64 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
    }
    local_8 = 0xffffffff;
    Concurrency::details::_Chore::ctor_15();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0066d127:
  local_1c = "bad allocation";
  std::exception::exception((exception *)&ppuStack_30,&local_1c,1);
  ppuStack_30 = vftable;
  _CxxThrowException(&ppuStack_30,(ThrowInfo *)&DAT_0075f410);
}




/* std::bad_alloc::ctor_8 @ 0066d380 */


void std::bad_alloc::ctor_8(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined8 *puVar8;
  char *pcVar9;
  uint local_90;
  missing_wait local_80 [12];
  char *local_74;
  int local_70;
  _StructuredTaskCollection local_6c [4];
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_4c;
  undefined4 *local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  int *piStack_38;
  undefined4 local_34;
  undefined **ppuStack_30;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7eb0;
  local_10 = ExceptionList;
  local_90 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_3 != 1) {
    param_2 = (int)(param_2 - 1) / *param_3 + 1;
  }
  local_40 = param_2;
  local_14 = local_90;
  local_20 = (char *)Concurrency::details::_CurrentScheduler::_GetNumberOfVirtualProcessors();
  local_4c = Concurrency::details::
             _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>
             ::vftable;
  local_48 = (undefined4 *)0x0;
  local_44 = 0;
  uVar4 = (int)local_20 * 0x2c + 8;
  local_8 = 0;
  if (uVar4 < 0x401) {
    puVar3 = &local_90;
    local_24 = &local_90;
    if (&stack0x00000000 == (undefined1 *)0x90) goto LAB_0066d437;
    local_90 = 0xcccc;
  }
  else {
    puVar3 = malloc(uVar4);
    local_24 = puVar3;
    if (puVar3 == (undefined4 *)0x0) goto LAB_0066d437;
    *puVar3 = 0xdddd;
  }
  local_24 = puVar3 + 2;
  if (local_24 != (undefined4 *)0x0) {
    local_5c = 0;
    local_18 = 0;
    local_54 = 0;
    local_58 = 0x80000000;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    }
    local_60 = 0;
    local_68 = 0x1fffffff;
    local_64 = 0;
    local_70 = (int)param_2 / (int)local_20;
    local_1c = (char *)((int)param_2 % (int)local_20);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_70 == 0) {
      local_20 = local_1c;
    }
    local_20 = local_20 + -1;
    ppuVar7 = (undefined **)0x0;
    pcVar9 = (char *)0x0;
    local_48 = local_24;
    if (0 < (int)local_20) {
      puVar8 = (undefined8 *)(puVar3 + 7);
      iVar5 = 0;
      local_74 = local_20;
      do {
        iVar6 = local_70;
        if (0 < (int)local_1c) {
          local_1c = local_1c + -1;
          iVar6 = local_70 + 1;
        }
        local_18 = iVar6;
        if (puVar8 != (undefined8 *)0x14) {
          local_3c = param_1;
          piStack_38 = param_3;
          *puVar8 = CONCAT44(param_3,param_1);
          local_34 = param_4;
          ppuStack_30 = ppuVar7;
          puVar8[1] = CONCAT44(ppuVar7,param_4);
          uStack_28 = 0;
          local_2c = (int)ppuVar7 + iVar6;
          *(undefined4 *)((int)puVar8 + -0xc) = 0;
          *(undefined ***)((int)puVar8 + -0x14) =
               Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
               ::vftable;
          puVar8[2] = (ulonglong)(uint)((int)ppuVar7 + iVar6);
          *(code **)(puVar8 + -2) = lib_fn_66cd30;
        }
        iVar5 = iVar5 + 1;
        local_44 = iVar5;
        *(undefined1 *)((int)puVar8 + -4) = 0;
        Concurrency::details::_StructuredTaskCollection::_Schedule
                  (local_6c,(_UnrealizedChore *)((int)puVar8 + -0x14));
        ppuVar7 = (undefined **)((int)ppuVar7 + local_18);
        puVar8 = (undefined8 *)((int)puVar8 + 0x2c);
        local_20 = local_20 + -1;
      } while (local_20 != (char *)0x0);
      local_20 = (char *)0x0;
      pcVar9 = local_74;
      local_18 = iVar5;
    }
    uVar4 = local_40;
    puVar1 = local_24 + (int)pcVar9 * 0xb;
    if (puVar1 != (undefined4 *)0x0) {
      local_3c = param_1;
      piStack_38 = param_3;
      *(ulonglong *)(puVar1 + 5) = CONCAT44(param_3,param_1);
      local_34 = param_4;
      ppuStack_30 = ppuVar7;
      *(ulonglong *)(puVar1 + 7) = CONCAT44(ppuVar7,param_4);
      local_2c = uVar4;
      uStack_28 = 0;
      puVar1[2] = 0;
      *puVar1 = Concurrency::
                task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
                ::vftable;
      *(ulonglong *)(puVar1 + 9) = (ulonglong)uVar4;
      puVar1[1] = lib_fn_66cd30;
    }
    local_44 = local_18 + 1;
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_6c);
    local_8 = local_8 & 0xffffff00;
    if (0 < local_5c) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_6c);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_64 != 0) && (local_64 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
        }
        Concurrency::missing_wait::missing_wait(local_80);
        _CxxThrowException(local_80,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_64 != 0) && (local_64 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
    }
    local_8 = 0xffffffff;
    Concurrency::details::_Chore::ctor_16();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0066d437:
  local_1c = "bad allocation";
  std::exception::exception((exception *)&ppuStack_30,&local_1c,1);
  ppuStack_30 = vftable;
  _CxxThrowException(&ppuStack_30,(ThrowInfo *)&DAT_0075f410);
}




/* std::bad_alloc::ctor_9 @ 0066d690 */


void std::bad_alloc::ctor_9(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined8 *puVar8;
  char *pcVar9;
  uint local_90;
  missing_wait local_80 [12];
  char *local_74;
  int local_70;
  _StructuredTaskCollection local_6c [4];
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_4c;
  undefined4 *local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  int *piStack_38;
  undefined4 local_34;
  undefined **ppuStack_30;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7ef0;
  local_10 = ExceptionList;
  local_90 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_3 != 1) {
    param_2 = (int)(param_2 - 1) / *param_3 + 1;
  }
  local_40 = param_2;
  local_14 = local_90;
  local_20 = (char *)Concurrency::details::_CurrentScheduler::_GetNumberOfVirtualProcessors();
  local_4c = Concurrency::details::
             _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>
             ::vftable;
  local_48 = (undefined4 *)0x0;
  local_44 = 0;
  uVar4 = (int)local_20 * 0x2c + 8;
  local_8 = 0;
  if (uVar4 < 0x401) {
    puVar3 = &local_90;
    local_24 = &local_90;
    if (&stack0x00000000 == (undefined1 *)0x90) goto LAB_0066d747;
    local_90 = 0xcccc;
  }
  else {
    puVar3 = malloc(uVar4);
    local_24 = puVar3;
    if (puVar3 == (undefined4 *)0x0) goto LAB_0066d747;
    *puVar3 = 0xdddd;
  }
  local_24 = puVar3 + 2;
  if (local_24 != (undefined4 *)0x0) {
    local_5c = 0;
    local_18 = 0;
    local_54 = 0;
    local_58 = 0x80000000;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    }
    local_60 = 0;
    local_68 = 0x1fffffff;
    local_64 = 0;
    local_70 = (int)param_2 / (int)local_20;
    local_1c = (char *)((int)param_2 % (int)local_20);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_70 == 0) {
      local_20 = local_1c;
    }
    local_20 = local_20 + -1;
    ppuVar7 = (undefined **)0x0;
    pcVar9 = (char *)0x0;
    local_48 = local_24;
    if (0 < (int)local_20) {
      puVar8 = (undefined8 *)(puVar3 + 7);
      iVar5 = 0;
      local_74 = local_20;
      do {
        iVar6 = local_70;
        if (0 < (int)local_1c) {
          local_1c = local_1c + -1;
          iVar6 = local_70 + 1;
        }
        local_18 = iVar6;
        if (puVar8 != (undefined8 *)0x14) {
          local_3c = param_1;
          piStack_38 = param_3;
          *puVar8 = CONCAT44(param_3,param_1);
          local_34 = param_4;
          ppuStack_30 = ppuVar7;
          puVar8[1] = CONCAT44(ppuVar7,param_4);
          uStack_28 = 0;
          local_2c = (int)ppuVar7 + iVar6;
          *(undefined4 *)((int)puVar8 + -0xc) = 0;
          *(undefined ***)((int)puVar8 + -0x14) =
               Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
               ::vftable;
          puVar8[2] = (ulonglong)(uint)((int)ppuVar7 + iVar6);
          *(code **)(puVar8 + -2) = lib_fn_66cd40;
        }
        iVar5 = iVar5 + 1;
        local_44 = iVar5;
        *(undefined1 *)((int)puVar8 + -4) = 0;
        Concurrency::details::_StructuredTaskCollection::_Schedule
                  (local_6c,(_UnrealizedChore *)((int)puVar8 + -0x14));
        ppuVar7 = (undefined **)((int)ppuVar7 + local_18);
        puVar8 = (undefined8 *)((int)puVar8 + 0x2c);
        local_20 = local_20 + -1;
      } while (local_20 != (char *)0x0);
      local_20 = (char *)0x0;
      pcVar9 = local_74;
      local_18 = iVar5;
    }
    uVar4 = local_40;
    puVar1 = local_24 + (int)pcVar9 * 0xb;
    if (puVar1 != (undefined4 *)0x0) {
      local_3c = param_1;
      piStack_38 = param_3;
      *(ulonglong *)(puVar1 + 5) = CONCAT44(param_3,param_1);
      local_34 = param_4;
      ppuStack_30 = ppuVar7;
      *(ulonglong *)(puVar1 + 7) = CONCAT44(ppuVar7,param_4);
      local_2c = uVar4;
      uStack_28 = 0;
      puVar1[2] = 0;
      *puVar1 = Concurrency::
                task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
                ::vftable;
      *(ulonglong *)(puVar1 + 9) = (ulonglong)uVar4;
      puVar1[1] = lib_fn_66cd40;
    }
    local_44 = local_18 + 1;
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_6c);
    local_8 = local_8 & 0xffffff00;
    if (0 < local_5c) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_6c);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_64 != 0) && (local_64 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
        }
        Concurrency::missing_wait::missing_wait(local_80);
        _CxxThrowException(local_80,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_64 != 0) && (local_64 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
    }
    local_8 = 0xffffffff;
    Concurrency::details::_Chore::ctor_17();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0066d747:
  local_1c = "bad allocation";
  std::exception::exception((exception *)&ppuStack_30,&local_1c,1);
  ppuStack_30 = vftable;
  _CxxThrowException(&ppuStack_30,(ThrowInfo *)&DAT_0075f410);
}




/* std::bad_alloc::ctor_6 @ 0066d9a0 */


void std::bad_alloc::ctor_6(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined8 *puVar8;
  char *pcVar9;
  uint local_90;
  missing_wait local_80 [12];
  char *local_74;
  int local_70;
  _StructuredTaskCollection local_6c [4];
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_4c;
  undefined4 *local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  int *piStack_38;
  undefined4 local_34;
  undefined **ppuStack_30;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7f30;
  local_10 = ExceptionList;
  local_90 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_3 != 1) {
    param_2 = (int)(param_2 - 1) / *param_3 + 1;
  }
  local_40 = param_2;
  local_14 = local_90;
  local_20 = (char *)Concurrency::details::_CurrentScheduler::_GetNumberOfVirtualProcessors();
  local_4c = Concurrency::details::
             _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>
             ::vftable;
  local_48 = (undefined4 *)0x0;
  local_44 = 0;
  uVar4 = (int)local_20 * 0x2c + 8;
  local_8 = 0;
  if (uVar4 < 0x401) {
    puVar3 = &local_90;
    local_24 = &local_90;
    if (&stack0x00000000 == (undefined1 *)0x90) goto LAB_0066da57;
    local_90 = 0xcccc;
  }
  else {
    puVar3 = malloc(uVar4);
    local_24 = puVar3;
    if (puVar3 == (undefined4 *)0x0) goto LAB_0066da57;
    *puVar3 = 0xdddd;
  }
  local_24 = puVar3 + 2;
  if (local_24 != (undefined4 *)0x0) {
    local_5c = 0;
    local_18 = 0;
    local_54 = 0;
    local_58 = 0x80000000;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    }
    local_60 = 0;
    local_68 = 0x1fffffff;
    local_64 = 0;
    local_70 = (int)param_2 / (int)local_20;
    local_1c = (char *)((int)param_2 % (int)local_20);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_70 == 0) {
      local_20 = local_1c;
    }
    local_20 = local_20 + -1;
    ppuVar7 = (undefined **)0x0;
    pcVar9 = (char *)0x0;
    local_48 = local_24;
    if (0 < (int)local_20) {
      puVar8 = (undefined8 *)(puVar3 + 7);
      iVar5 = 0;
      local_74 = local_20;
      do {
        iVar6 = local_70;
        if (0 < (int)local_1c) {
          local_1c = local_1c + -1;
          iVar6 = local_70 + 1;
        }
        local_18 = iVar6;
        if (puVar8 != (undefined8 *)0x14) {
          local_3c = param_1;
          piStack_38 = param_3;
          *puVar8 = CONCAT44(param_3,param_1);
          local_34 = param_4;
          ppuStack_30 = ppuVar7;
          puVar8[1] = CONCAT44(ppuVar7,param_4);
          uStack_28 = 0;
          local_2c = (int)ppuVar7 + iVar6;
          *(undefined4 *)((int)puVar8 + -0xc) = 0;
          *(undefined ***)((int)puVar8 + -0x14) =
               Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
               ::vftable;
          puVar8[2] = (ulonglong)(uint)((int)ppuVar7 + iVar6);
          *(code **)(puVar8 + -2) = lib_fn_66cd50;
        }
        iVar5 = iVar5 + 1;
        local_44 = iVar5;
        *(undefined1 *)((int)puVar8 + -4) = 0;
        Concurrency::details::_StructuredTaskCollection::_Schedule
                  (local_6c,(_UnrealizedChore *)((int)puVar8 + -0x14));
        ppuVar7 = (undefined **)((int)ppuVar7 + local_18);
        puVar8 = (undefined8 *)((int)puVar8 + 0x2c);
        local_20 = local_20 + -1;
      } while (local_20 != (char *)0x0);
      local_20 = (char *)0x0;
      pcVar9 = local_74;
      local_18 = iVar5;
    }
    uVar4 = local_40;
    puVar1 = local_24 + (int)pcVar9 * 0xb;
    if (puVar1 != (undefined4 *)0x0) {
      local_3c = param_1;
      piStack_38 = param_3;
      *(ulonglong *)(puVar1 + 5) = CONCAT44(param_3,param_1);
      local_34 = param_4;
      ppuStack_30 = ppuVar7;
      *(ulonglong *)(puVar1 + 7) = CONCAT44(ppuVar7,param_4);
      local_2c = uVar4;
      uStack_28 = 0;
      puVar1[2] = 0;
      *puVar1 = Concurrency::
                task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
                ::vftable;
      *(ulonglong *)(puVar1 + 9) = (ulonglong)uVar4;
      puVar1[1] = lib_fn_66cd50;
    }
    local_44 = local_18 + 1;
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_6c);
    local_8 = local_8 & 0xffffff00;
    if (0 < local_5c) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_6c);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_64 != 0) && (local_64 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
        }
        Concurrency::missing_wait::missing_wait(local_80);
        _CxxThrowException(local_80,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_64 != 0) && (local_64 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_6c);
    }
    local_8 = 0xffffffff;
    Concurrency::details::_Chore::ctor_18();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0066da57:
  local_1c = "bad allocation";
  std::exception::exception((exception *)&ppuStack_30,&local_1c,1);
  ppuStack_30 = vftable;
  _CxxThrowException(&ppuStack_30,(ThrowInfo *)&DAT_0075f410);
}




/* Global::lib_fn_66e1b0 @ 0066e1b0 */

void lib_fn_66e1b0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f7f6c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = 0;
  in_ECX[1] = param_1;
  Concurrency::details::_Cancellation_beacon::_Cancellation_beacon
            ((_Cancellation_beacon *)(in_ECX + 2));
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  local_8 = 0;
  in_ECX[6] = 0;
  puVar1 = (undefined4 *)Concurrency::details::_Context::_CurrentContext();
  in_ECX[3] = *puVar1;
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_UnrealizedChore::ctor_0 @ 0066e240 */

void Concurrency::details::_UnrealizedChore::ctor_0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  in_ECX[2] = 0;
  return;
}




/* std::bad_alloc::ctor_5 @ 0066e250 */

void std::bad_alloc::ctor_5(exception *param_1)

{
  exception *in_ECX;
  
  std::exception::exception(in_ECX,param_1);
  *(undefined ***)in_ECX = vftable;
  return;
}




/* Concurrency::missing_wait::ctor_0 @ 0066e270 */

void Concurrency::missing_wait::ctor_0(exception *param_1)

{
  exception *in_ECX;
  
  std::exception::exception(in_ECX,param_1);
  *(undefined ***)in_ECX = vftable;
  return;
}




/* Concurrency::details::_Chore::ctor_14 @ 0066e290 */

void Concurrency::details::_Chore::ctor_14(void)

{
  int *_Memory;
  undefined4 *in_ECX;
  uint uVar1;
  _UnrealizedChore *this;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7f98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  *in_ECX = _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  if (in_ECX[2] != 0) {
    local_14 = 0;
    do {
      this = (_UnrealizedChore *)(in_ECX[1] + local_14);
      *(undefined ***)this =
           task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
           ::vftable;
      local_8 = 0;
      if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
        Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
      }
      uVar1 = uVar1 + 1;
      local_14 = local_14 + 0x2c;
      *(undefined ***)this = vftable;
    } while (uVar1 < (uint)in_ECX[2]);
  }
  local_8 = 0xffffffff;
  if ((in_ECX[1] != 0) && (_Memory = (int *)(in_ECX[1] + -8), *_Memory == 0xdddd)) {
    free(_Memory);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_15 @ 0066e350 */

void Concurrency::details::_Chore::ctor_15(void)

{
  int *_Memory;
  undefined4 *in_ECX;
  uint uVar1;
  _UnrealizedChore *this;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7f98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  *in_ECX = _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  if (in_ECX[2] != 0) {
    local_14 = 0;
    do {
      this = (_UnrealizedChore *)(in_ECX[1] + local_14);
      *(undefined ***)this =
           task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
           ::vftable;
      local_8 = 0;
      if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
        Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
      }
      uVar1 = uVar1 + 1;
      local_14 = local_14 + 0x2c;
      *(undefined ***)this = vftable;
    } while (uVar1 < (uint)in_ECX[2]);
  }
  local_8 = 0xffffffff;
  if ((in_ECX[1] != 0) && (_Memory = (int *)(in_ECX[1] + -8), *_Memory == 0xdddd)) {
    free(_Memory);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_16 @ 0066e410 */

void Concurrency::details::_Chore::ctor_16(void)

{
  int *_Memory;
  undefined4 *in_ECX;
  uint uVar1;
  _UnrealizedChore *this;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7f98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  *in_ECX = _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  if (in_ECX[2] != 0) {
    local_14 = 0;
    do {
      this = (_UnrealizedChore *)(in_ECX[1] + local_14);
      *(undefined ***)this =
           task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
           ::vftable;
      local_8 = 0;
      if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
        Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
      }
      uVar1 = uVar1 + 1;
      local_14 = local_14 + 0x2c;
      *(undefined ***)this = vftable;
    } while (uVar1 < (uint)in_ECX[2]);
  }
  local_8 = 0xffffffff;
  if ((in_ECX[1] != 0) && (_Memory = (int *)(in_ECX[1] + -8), *_Memory == 0xdddd)) {
    free(_Memory);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_17 @ 0066e4d0 */

void Concurrency::details::_Chore::ctor_17(void)

{
  int *_Memory;
  undefined4 *in_ECX;
  uint uVar1;
  _UnrealizedChore *this;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7f98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  *in_ECX = _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  if (in_ECX[2] != 0) {
    local_14 = 0;
    do {
      this = (_UnrealizedChore *)(in_ECX[1] + local_14);
      *(undefined ***)this =
           task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
           ::vftable;
      local_8 = 0;
      if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
        Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
      }
      uVar1 = uVar1 + 1;
      local_14 = local_14 + 0x2c;
      *(undefined ***)this = vftable;
    } while (uVar1 < (uint)in_ECX[2]);
  }
  local_8 = 0xffffffff;
  if ((in_ECX[1] != 0) && (_Memory = (int *)(in_ECX[1] + -8), *_Memory == 0xdddd)) {
    free(_Memory);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_18 @ 0066e590 */

void Concurrency::details::_Chore::ctor_18(void)

{
  int *_Memory;
  undefined4 *in_ECX;
  uint uVar1;
  _UnrealizedChore *this;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7f98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  *in_ECX = _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  if (in_ECX[2] != 0) {
    local_14 = 0;
    do {
      this = (_UnrealizedChore *)(in_ECX[1] + local_14);
      *(undefined ***)this =
           task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
           ::vftable;
      local_8 = 0;
      if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
        Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
      }
      uVar1 = uVar1 + 1;
      local_14 = local_14 + 0x2c;
      *(undefined ***)this = vftable;
    } while (uVar1 < (uint)in_ECX[2]);
  }
  local_8 = 0xffffffff;
  if ((in_ECX[1] != 0) && (_Memory = (int *)(in_ECX[1] + -8), *_Memory == 0xdddd)) {
    free(_Memory);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_19 @ 0066e650 */

void Concurrency::details::_Chore::ctor_19(void)

{
  _UnrealizedChore *p_Var1;
  _UnrealizedChore *this;
  undefined4 *in_ECX;
  _UnrealizedChore *_Memory;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_006f7fc8;
  ExceptionList = &local_10;
  *in_ECX = _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  this = (_UnrealizedChore *)in_ECX[1];
  while (this != (_UnrealizedChore *)0x0) {
    p_Var1 = *(_UnrealizedChore **)(this + 0x2c);
    *(undefined ***)this =
         task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
         ::vftable;
    local_8 = 0;
    if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
    }
    *(undefined ***)this = vftable;
    _Memory = this + -8;
    local_8 = 0xffffffff;
    this = p_Var1;
    if (*(int *)_Memory == 0xdddd) {
      free(_Memory);
    }
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_20 @ 0066e6f0 */

void Concurrency::details::_Chore::ctor_20(void)

{
  _UnrealizedChore *p_Var1;
  _UnrealizedChore *this;
  undefined4 *in_ECX;
  _UnrealizedChore *_Memory;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_006f7fc8;
  ExceptionList = &local_10;
  *in_ECX = _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  this = (_UnrealizedChore *)in_ECX[1];
  while (this != (_UnrealizedChore *)0x0) {
    p_Var1 = *(_UnrealizedChore **)(this + 0x2c);
    *(undefined ***)this =
         task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
         ::vftable;
    local_8 = 0;
    if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
    }
    *(undefined ***)this = vftable;
    _Memory = this + -8;
    local_8 = 0xffffffff;
    this = p_Var1;
    if (*(int *)_Memory == 0xdddd) {
      free(_Memory);
    }
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_21 @ 0066e790 */

void Concurrency::details::_Chore::ctor_21(void)

{
  _UnrealizedChore *p_Var1;
  _UnrealizedChore *this;
  undefined4 *in_ECX;
  _UnrealizedChore *_Memory;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_006f7fc8;
  ExceptionList = &local_10;
  *in_ECX = _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  this = (_UnrealizedChore *)in_ECX[1];
  while (this != (_UnrealizedChore *)0x0) {
    p_Var1 = *(_UnrealizedChore **)(this + 0x2c);
    *(undefined ***)this =
         task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
         ::vftable;
    local_8 = 0;
    if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
    }
    *(undefined ***)this = vftable;
    _Memory = this + -8;
    local_8 = 0xffffffff;
    this = p_Var1;
    if (*(int *)_Memory == 0xdddd) {
      free(_Memory);
    }
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_6 @ 0066e830 */

void Concurrency::details::_Chore::ctor_6(void)

{
  _UnrealizedChore *p_Var1;
  _UnrealizedChore *this;
  undefined4 *in_ECX;
  _UnrealizedChore *_Memory;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_006f7fc8;
  ExceptionList = &local_10;
  *in_ECX = _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  this = (_UnrealizedChore *)in_ECX[1];
  while (this != (_UnrealizedChore *)0x0) {
    p_Var1 = *(_UnrealizedChore **)(this + 0x2c);
    *(undefined ***)this =
         task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
         ::vftable;
    local_8 = 0;
    if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
    }
    *(undefined ***)this = vftable;
    _Memory = this + -8;
    local_8 = 0xffffffff;
    this = p_Var1;
    if (*(int *)_Memory == 0xdddd) {
      free(_Memory);
    }
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_7 @ 0066e8d0 */

void Concurrency::details::_Chore::ctor_7(void)

{
  _UnrealizedChore *p_Var1;
  _UnrealizedChore *this;
  undefined4 *in_ECX;
  _UnrealizedChore *_Memory;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_006f7fc8;
  ExceptionList = &local_10;
  *in_ECX = _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>
            ::vftable;
  this = (_UnrealizedChore *)in_ECX[1];
  while (this != (_UnrealizedChore *)0x0) {
    p_Var1 = *(_UnrealizedChore **)(this + 0x2c);
    *(undefined ***)this =
         task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
         ::vftable;
    local_8 = 0;
    if ((*(int *)(this + 8) != 0) && (this[0x10] == (_UnrealizedChore)0x0)) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection(this);
    }
    *(undefined ***)this = vftable;
    _Memory = this + -8;
    local_8 = 0xffffffff;
    this = p_Var1;
    if (*(int *)_Memory == 0xdddd) {
      free(_Memory);
    }
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_8 @ 0066e9a0 */

void Concurrency::details::_Chore::ctor_8(void)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  *(undefined ***)in_ECX = vftable;
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_10 @ 0066ea00 */

void Concurrency::details::_Chore::ctor_10(void)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  *(undefined ***)in_ECX = vftable;
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_9 @ 0066ea60 */

void Concurrency::details::_Chore::ctor_9(void)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  *(undefined ***)in_ECX = vftable;
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_11 @ 0066eac0 */

void Concurrency::details::_Chore::ctor_11(void)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  *(undefined ***)in_ECX = vftable;
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_12 @ 0066eb20 */

void Concurrency::details::_Chore::ctor_12(void)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  *(undefined ***)in_ECX = vftable;
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_13 @ 0066ebf0 */

void Concurrency::details::_Chore::ctor_13(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  return;
}




/* std::bad_alloc::ctor_4 @ 0066f660 */


void std::bad_alloc::ctor_4(void)

{
  char cVar1;
  bool bVar2;
  undefined4 *in_ECX;
  int iVar3;
  int iVar4;
  undefined **local_11c;
  code *local_118;
  undefined1 local_10c;
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  missing_wait local_dc [12];
  _SpinWait<1> local_d0 [8];
  undefined4 local_c8;
  code *local_c4;
  _UnrealizedChore *local_c0;
  _UnrealizedChore *local_bc;
  undefined **local_b8 [3];
  undefined **local_ac;
  code *local_a8;
  int local_a4;
  char local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  char *local_80;
  _StructuredTaskCollection local_7c [4];
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined **local_5c;
  _UnrealizedChore *local_58;
  int *local_54;
  int local_50;
  int *local_4c [2];
  int local_44;
  int *local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int iStack_2c;
  int local_28;
  int **ppiStack_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f8065;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX[3];
  local_18 = in_ECX[4];
  if (in_ECX[5] != 0) {
    _local_f8 = CONCAT44(0x66f6ac,local_f8);
    cVar1 = lib_fn_671340();
    if (cVar1 == '\0') goto LAB_0066fa7f;
  }
  iVar4 = local_1c;
  local_20 = *(int *)in_ECX[1] * local_1c;
  if (local_18 - local_1c == 1) {
    _local_f8 = CONCAT44(&local_20,*in_ECX);
    local_100 = CONCAT44(0x66f6dd,(undefined4)local_100);
    lib_fn_6712c0();
  }
  else {
    local_6c = 0;
    local_68 = 0x80000000;
    local_64 = 0;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    }
    local_70 = 0;
    local_78 = 0x1fffffff;
    local_74 = 0;
    local_8 = 0;
    _local_f8 = CONCAT44(0x66f746,local_f8);
    lib_fn_66e1b0();
    local_38 = *in_ECX;
    uStack_34 = in_ECX[1];
    local_30 = in_ECX[2];
    iStack_2c = local_1c;
    local_28 = local_18;
    ppiStack_24 = &local_54;
    local_8._0_1_ = 1;
    Concurrency::details::_UnrealizedChore::ctor_0();
    local_98 = CONCAT44(uStack_34,local_38);
    local_90 = CONCAT44(iStack_2c,local_30);
    local_88 = CONCAT44(ppiStack_24,local_28);
    local_ac = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_a8 = lib_fn_66cd10;
    local_8._0_1_ = 2;
    local_9c = '\0';
    _local_f8 = CONCAT44(0x66f7ce,local_f8);
    Concurrency::details::_StructuredTaskCollection::_Schedule
              (local_7c,(_UnrealizedChore *)&local_ac);
    local_5c = Concurrency::details::
               _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>
               ::vftable;
    local_58 = (_UnrealizedChore *)0x0;
    local_8._0_1_ = 3;
    if (iVar4 < local_18) {
      do {
        if ((*local_4c[0] != 0) &&
           ((local_44 != 0 ||
            (bVar2 = Concurrency::details::_Cancellation_beacon::_Confirm_cancel
                               ((_Cancellation_beacon *)local_4c), bVar2)))) break;
        if (local_54 != (int *)0x0) {
          if (1 < local_18 - local_1c) {
            local_18 = (local_18 - local_1c) / 2 + local_1c;
          }
          *local_54 = local_18;
          LOCK();
          local_54 = (int *)0x0;
          UNLOCK();
          if (1 < local_18 - local_1c) {
            if ((&stack0x00000000 == (undefined1 *)0xec) ||
               ((_UnrealizedChore *)&local_11c == (_UnrealizedChore *)0x0)) {
              local_80 = "bad allocation";
              std::exception::exception((exception *)local_b8,&local_80,1);
              local_b8[0] = vftable;
              _CxxThrowException(local_b8,(ThrowInfo *)&DAT_0075f410);
            }
            local_38 = *in_ECX;
            uStack_34 = in_ECX[1];
            local_30 = in_ECX[2];
            iStack_2c = local_1c;
            local_28 = local_18;
            ppiStack_24 = &local_54;
            local_8._0_1_ = 4;
            local_c0 = (_UnrealizedChore *)&local_11c;
            local_bc = (_UnrealizedChore *)&local_11c;
            local_58 = (_UnrealizedChore *)&local_11c;
            Concurrency::details::_UnrealizedChore::ctor_0();
            local_108 = CONCAT44(uStack_34,local_38);
            local_100 = CONCAT44(iStack_2c,local_30);
            _local_f8 = CONCAT44(ppiStack_24,local_28);
            local_11c = Concurrency::
                        task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
                        ::vftable;
            local_118 = lib_fn_66cd10;
            local_8._0_1_ = 3;
            local_10c = 0;
            Concurrency::details::_StructuredTaskCollection::_Schedule
                      (local_7c,(_UnrealizedChore *)&local_11c);
          }
        }
        local_40 = &local_1c;
        _local_f8 = CONCAT44(&local_20,*in_ECX);
        local_100 = CONCAT44(0x66f90f,(undefined4)local_100);
        lib_fn_6712c0();
        local_40 = (int *)0x0;
        if (local_3c != 0) {
          local_c8 = 0;
          local_c4 = _UnderlyingYield_exref;
          do {
            Concurrency::details::_SpinWait<1>::_SpinOnce(local_d0);
          } while (local_3c != 0);
        }
        iVar4 = iVar4 + 1;
        local_20 = local_20 + *(int *)in_ECX[1];
        local_1c = iVar4;
      } while (iVar4 < local_18);
    }
    LOCK();
    local_44 = 1;
    UNLOCK();
    _local_f8 = CONCAT44((_UnrealizedChore *)local_7c,0x66f973);
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_7c);
    local_44 = 2;
    local_8._0_1_ = 2;
    Concurrency::details::_Chore::ctor_19();
    local_ac = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_8._0_1_ = 5;
    if ((local_a4 != 0) && (local_9c == '\0')) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection((_UnrealizedChore *)&local_ac);
    }
    local_ac = Concurrency::details::_Chore::vftable;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_44 != 2) {
      if (local_50 != 0) {
        LOCK();
        **(int **)(local_50 + 8) = **(int **)(local_50 + 8) + 1;
        UNLOCK();
      }
      LOCK();
      local_44 = 1;
      UNLOCK();
    }
    Concurrency::details::_Cancellation_beacon::~_Cancellation_beacon
              ((_Cancellation_beacon *)local_4c);
    local_8 = 0xffffffff;
    if (0 < local_6c) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_7c);
      cVar1 = __uncaught_exception();
      if (cVar1 == '\0') {
        if ((local_74 != 0) && (local_74 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_7c);
        }
        Concurrency::missing_wait::missing_wait(local_dc);
        _local_f8 = CONCAT44(local_dc,0x66fa36);
        _CxxThrowException(local_dc,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_74 != 0) && (local_74 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_7c);
    }
  }
LAB_0066fa7f:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::bad_alloc::ctor_2 @ 0066fab0 */


void std::bad_alloc::ctor_2(void)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int *in_ECX;
  int iVar4;
  undefined **local_124;
  code *local_120;
  undefined1 local_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  missing_wait local_e4 [12];
  _SpinWait<1> local_d8 [8];
  undefined4 local_d0;
  code *local_cc;
  undefined **local_c8 [3];
  _UnrealizedChore *local_bc;
  _UnrealizedChore *local_b8;
  undefined **local_b4;
  code *local_b0;
  int local_ac;
  char local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  char *local_88;
  int *local_84;
  _StructuredTaskCollection local_80 [4];
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined **local_60;
  _UnrealizedChore *local_5c;
  int *local_58;
  int local_54;
  int *local_50 [2];
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int iStack_38;
  int local_34;
  int iStack_30;
  int local_2c;
  int **ppiStack_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f80d5;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX[3];
  local_18 = in_ECX[4];
  local_84 = in_ECX;
  if (in_ECX[5] != 0) {
    _local_100 = CONCAT44(0x66faff,local_100);
    cVar2 = lib_fn_671340();
    if (cVar2 == '\0') goto LAB_0066ff31;
  }
  iVar1 = local_1c;
  local_20 = *(int *)in_ECX[1] * local_1c;
  local_24 = local_1c;
  if (local_18 - local_1c == 1) {
    _local_100 = CONCAT44(0x66fb38,local_100);
    Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
              (*(int *)(*in_ECX + 4) + local_20);
    _local_100 = CONCAT44(0x66fb59,local_100);
    FUN_0066f380();
  }
  else {
    local_70 = 0;
    local_6c = 0x80000000;
    local_68 = 0;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    }
    local_74 = 0;
    local_7c = 0x1fffffff;
    local_78 = 0;
    local_8 = 0;
    _local_100 = CONCAT44(0x66fbbf,local_100);
    lib_fn_66e1b0();
    local_3c = *in_ECX;
    iStack_38 = in_ECX[1];
    local_34 = in_ECX[2];
    iStack_30 = local_1c;
    local_2c = local_18;
    ppiStack_28 = &local_58;
    local_8._0_1_ = 1;
    Concurrency::details::_UnrealizedChore::ctor_0();
    local_a0 = CONCAT44(iStack_38,local_3c);
    local_98 = CONCAT44(iStack_30,local_34);
    local_90 = CONCAT44(ppiStack_28,local_2c);
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_b0 = lib_fn_66cd20;
    local_8._0_1_ = 2;
    local_a4 = '\0';
    _local_100 = CONCAT44(0x66fc47,local_100);
    Concurrency::details::_StructuredTaskCollection::_Schedule
              (local_80,(_UnrealizedChore *)&local_b4);
    local_60 = Concurrency::details::
               _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>
               ::vftable;
    local_5c = (_UnrealizedChore *)0x0;
    local_8._0_1_ = 3;
    if (iVar1 < local_18) {
      do {
        if ((*local_50[0] != 0) &&
           ((local_48 != 0 ||
            (bVar3 = Concurrency::details::_Cancellation_beacon::_Confirm_cancel
                               ((_Cancellation_beacon *)local_50), bVar3)))) break;
        if (local_58 != (int *)0x0) {
          if (1 < local_18 - local_1c) {
            local_18 = (local_18 - local_1c) / 2 + local_1c;
          }
          *local_58 = local_18;
          LOCK();
          local_58 = (int *)0x0;
          UNLOCK();
          if (1 < local_18 - local_1c) {
            if ((&stack0x00000000 == (undefined1 *)0xf4) ||
               ((_UnrealizedChore *)&local_124 == (_UnrealizedChore *)0x0)) {
              local_88 = "bad allocation";
              std::exception::exception((exception *)local_c8,&local_88,1);
              local_c8[0] = vftable;
              _CxxThrowException(local_c8,(ThrowInfo *)&DAT_0075f410);
            }
            local_3c = *in_ECX;
            iStack_38 = in_ECX[1];
            local_34 = in_ECX[2];
            iStack_30 = local_1c;
            local_2c = local_18;
            ppiStack_28 = &local_58;
            local_8._0_1_ = 4;
            local_bc = (_UnrealizedChore *)&local_124;
            local_b8 = (_UnrealizedChore *)&local_124;
            local_5c = (_UnrealizedChore *)&local_124;
            Concurrency::details::_UnrealizedChore::ctor_0();
            local_110 = CONCAT44(iStack_38,local_3c);
            local_108 = CONCAT44(iStack_30,local_34);
            _local_100 = CONCAT44(ppiStack_28,local_2c);
            local_124 = Concurrency::
                        task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
                        ::vftable;
            local_120 = lib_fn_66cd20;
            local_8._0_1_ = 3;
            local_114 = 0;
            Concurrency::details::_StructuredTaskCollection::_Schedule
                      (local_80,(_UnrealizedChore *)&local_124);
          }
        }
        local_44 = &local_1c;
        _local_100 = CONCAT44(0x66fd8c,local_100);
        Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
                  (*(int *)(*in_ECX + 4) + local_20);
        _local_100 = CONCAT44(0x66fdad,local_100);
        FUN_0066f380();
        local_44 = (int *)0x0;
        if (local_40 != 0) {
          local_d0 = 0;
          local_cc = _UnderlyingYield_exref;
          do {
            Concurrency::details::_SpinWait<1>::_SpinOnce(local_d8);
          } while (local_40 != 0);
        }
        local_24 = local_24 + 1;
        local_20 = local_20 + *(int *)local_84[1];
        in_ECX = local_84;
        local_1c = local_24;
      } while (local_24 < local_18);
    }
    LOCK();
    local_48 = 1;
    UNLOCK();
    _local_100 = CONCAT44((_UnrealizedChore *)local_80,0x66fe1b);
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_80);
    local_48 = 2;
    local_8._0_1_ = 2;
    Concurrency::details::_Chore::ctor_20();
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_8._0_1_ = 5;
    if ((local_ac != 0) && (local_a4 == '\0')) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection((_UnrealizedChore *)&local_b4);
    }
    local_b4 = Concurrency::details::_Chore::vftable;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_48 != 2) {
      if (local_54 != 0) {
        LOCK();
        **(int **)(local_54 + 8) = **(int **)(local_54 + 8) + 1;
        UNLOCK();
      }
      LOCK();
      local_48 = 1;
      UNLOCK();
    }
    Concurrency::details::_Cancellation_beacon::~_Cancellation_beacon
              ((_Cancellation_beacon *)local_50);
    local_8 = 0xffffffff;
    if (0 < local_70) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_80);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_78 != 0) && (local_78 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
        }
        Concurrency::missing_wait::missing_wait(local_e4);
        _local_100 = CONCAT44(local_e4,0x66fee2);
        _CxxThrowException(local_e4,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_78 != 0) && (local_78 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
    }
  }
LAB_0066ff31:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::bad_alloc::ctor_3 @ 0066ff60 */


void std::bad_alloc::ctor_3(void)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int *in_ECX;
  int iVar4;
  undefined **local_124;
  code *local_120;
  undefined1 local_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  missing_wait local_e4 [12];
  _SpinWait<1> local_d8 [8];
  undefined4 local_d0;
  code *local_cc;
  undefined **local_c8 [3];
  _UnrealizedChore *local_bc;
  _UnrealizedChore *local_b8;
  undefined **local_b4;
  code *local_b0;
  int local_ac;
  char local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  char *local_88;
  int *local_84;
  _StructuredTaskCollection local_80 [4];
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined **local_60;
  _UnrealizedChore *local_5c;
  int *local_58;
  int local_54;
  int *local_50 [2];
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int iStack_38;
  int local_34;
  int iStack_30;
  int local_2c;
  int **ppiStack_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f8145;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX[3];
  local_18 = in_ECX[4];
  local_84 = in_ECX;
  if (in_ECX[5] != 0) {
    _local_100 = CONCAT44(0x66ffaf,local_100);
    cVar2 = lib_fn_671340();
    if (cVar2 == '\0') goto LAB_006703e2;
  }
  iVar1 = local_1c;
  local_20 = *(int *)in_ECX[1] * local_1c;
  local_24 = local_1c;
  if (local_18 - local_1c == 1) {
    _local_100 = CONCAT44(0x66ffe8,local_100);
    Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
              (*(int *)(*in_ECX + 4) + local_20);
    _local_100 = CONCAT44(0x67000a,local_100);
    FUN_0066eef0();
  }
  else {
    local_70 = 0;
    local_6c = 0x80000000;
    local_68 = 0;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    }
    local_74 = 0;
    local_7c = 0x1fffffff;
    local_78 = 0;
    local_8 = 0;
    _local_100 = CONCAT44(0x670070,local_100);
    lib_fn_66e1b0();
    local_3c = *in_ECX;
    iStack_38 = in_ECX[1];
    local_34 = in_ECX[2];
    iStack_30 = local_1c;
    local_2c = local_18;
    ppiStack_28 = &local_58;
    local_8._0_1_ = 1;
    Concurrency::details::_UnrealizedChore::ctor_0();
    local_a0 = CONCAT44(iStack_38,local_3c);
    local_98 = CONCAT44(iStack_30,local_34);
    local_90 = CONCAT44(ppiStack_28,local_2c);
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_b0 = lib_fn_66cd30;
    local_8._0_1_ = 2;
    local_a4 = '\0';
    _local_100 = CONCAT44(0x6700f8,local_100);
    Concurrency::details::_StructuredTaskCollection::_Schedule
              (local_80,(_UnrealizedChore *)&local_b4);
    local_60 = Concurrency::details::
               _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>
               ::vftable;
    local_5c = (_UnrealizedChore *)0x0;
    local_8._0_1_ = 3;
    if (iVar1 < local_18) {
      do {
        if ((*local_50[0] != 0) &&
           ((local_48 != 0 ||
            (bVar3 = Concurrency::details::_Cancellation_beacon::_Confirm_cancel
                               ((_Cancellation_beacon *)local_50), bVar3)))) break;
        if (local_58 != (int *)0x0) {
          if (1 < local_18 - local_1c) {
            local_18 = (local_18 - local_1c) / 2 + local_1c;
          }
          *local_58 = local_18;
          LOCK();
          local_58 = (int *)0x0;
          UNLOCK();
          if (1 < local_18 - local_1c) {
            if ((&stack0x00000000 == (undefined1 *)0xf4) ||
               ((_UnrealizedChore *)&local_124 == (_UnrealizedChore *)0x0)) {
              local_88 = "bad allocation";
              std::exception::exception((exception *)local_c8,&local_88,1);
              local_c8[0] = vftable;
              _CxxThrowException(local_c8,(ThrowInfo *)&DAT_0075f410);
            }
            local_3c = *in_ECX;
            iStack_38 = in_ECX[1];
            local_34 = in_ECX[2];
            iStack_30 = local_1c;
            local_2c = local_18;
            ppiStack_28 = &local_58;
            local_8._0_1_ = 4;
            local_bc = (_UnrealizedChore *)&local_124;
            local_b8 = (_UnrealizedChore *)&local_124;
            local_5c = (_UnrealizedChore *)&local_124;
            Concurrency::details::_UnrealizedChore::ctor_0();
            local_110 = CONCAT44(iStack_38,local_3c);
            local_108 = CONCAT44(iStack_30,local_34);
            _local_100 = CONCAT44(ppiStack_28,local_2c);
            local_124 = Concurrency::
                        task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
                        ::vftable;
            local_120 = lib_fn_66cd30;
            local_8._0_1_ = 3;
            local_114 = 0;
            Concurrency::details::_StructuredTaskCollection::_Schedule
                      (local_80,(_UnrealizedChore *)&local_124);
          }
        }
        local_44 = &local_1c;
        _local_100 = CONCAT44(0x67023d,local_100);
        Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
                  (*(int *)(*in_ECX + 4) + local_20);
        _local_100 = CONCAT44(0x67025f,local_100);
        FUN_0066eef0();
        local_44 = (int *)0x0;
        if (local_40 != 0) {
          local_d0 = 0;
          local_cc = _UnderlyingYield_exref;
          do {
            Concurrency::details::_SpinWait<1>::_SpinOnce(local_d8);
          } while (local_40 != 0);
        }
        local_24 = local_24 + 1;
        local_20 = local_20 + *(int *)local_84[1];
        in_ECX = local_84;
        local_1c = local_24;
      } while (local_24 < local_18);
    }
    LOCK();
    local_48 = 1;
    UNLOCK();
    _local_100 = CONCAT44((_UnrealizedChore *)local_80,0x6702cc);
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_80);
    local_48 = 2;
    local_8._0_1_ = 2;
    Concurrency::details::_Chore::ctor_21();
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_8._0_1_ = 5;
    if ((local_ac != 0) && (local_a4 == '\0')) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection((_UnrealizedChore *)&local_b4);
    }
    local_b4 = Concurrency::details::_Chore::vftable;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_48 != 2) {
      if (local_54 != 0) {
        LOCK();
        **(int **)(local_54 + 8) = **(int **)(local_54 + 8) + 1;
        UNLOCK();
      }
      LOCK();
      local_48 = 1;
      UNLOCK();
    }
    Concurrency::details::_Cancellation_beacon::~_Cancellation_beacon
              ((_Cancellation_beacon *)local_50);
    local_8 = 0xffffffff;
    if (0 < local_70) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_80);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_78 != 0) && (local_78 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
        }
        Concurrency::missing_wait::missing_wait(local_e4);
        _local_100 = CONCAT44(local_e4,0x670393);
        _CxxThrowException(local_e4,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_78 != 0) && (local_78 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
    }
  }
LAB_006703e2:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::bad_alloc::ctor_1 @ 00670410 */


void std::bad_alloc::ctor_1(void)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int *in_ECX;
  int iVar4;
  undefined **local_124;
  code *local_120;
  undefined1 local_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  missing_wait local_e4 [12];
  _SpinWait<1> local_d8 [8];
  undefined4 local_d0;
  code *local_cc;
  undefined **local_c8 [3];
  _UnrealizedChore *local_bc;
  _UnrealizedChore *local_b8;
  undefined **local_b4;
  code *local_b0;
  int local_ac;
  char local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  char *local_88;
  int *local_84;
  _StructuredTaskCollection local_80 [4];
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined **local_60;
  _UnrealizedChore *local_5c;
  int *local_58;
  int local_54;
  int *local_50 [2];
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int iStack_38;
  int local_34;
  int iStack_30;
  int local_2c;
  int **ppiStack_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f81b5;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX[3];
  local_18 = in_ECX[4];
  local_84 = in_ECX;
  if (in_ECX[5] != 0) {
    _local_100 = CONCAT44(0x67045f,local_100);
    cVar2 = lib_fn_671340();
    if (cVar2 == '\0') goto LAB_00670892;
  }
  iVar1 = local_1c;
  local_20 = *(int *)in_ECX[1] * local_1c;
  local_24 = local_1c;
  if (local_18 - local_1c == 1) {
    _local_100 = CONCAT44(0x670498,local_100);
    Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
              (*(int *)(*in_ECX + 4) + local_20);
    _local_100 = CONCAT44(0x6704ba,local_100);
    FUN_0066f280();
  }
  else {
    local_70 = 0;
    local_6c = 0x80000000;
    local_68 = 0;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    }
    local_74 = 0;
    local_7c = 0x1fffffff;
    local_78 = 0;
    local_8 = 0;
    _local_100 = CONCAT44(0x670520,local_100);
    lib_fn_66e1b0();
    local_3c = *in_ECX;
    iStack_38 = in_ECX[1];
    local_34 = in_ECX[2];
    iStack_30 = local_1c;
    local_2c = local_18;
    ppiStack_28 = &local_58;
    local_8._0_1_ = 1;
    Concurrency::details::_UnrealizedChore::ctor_0();
    local_a0 = CONCAT44(iStack_38,local_3c);
    local_98 = CONCAT44(iStack_30,local_34);
    local_90 = CONCAT44(ppiStack_28,local_2c);
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_b0 = lib_fn_66cd40;
    local_8._0_1_ = 2;
    local_a4 = '\0';
    _local_100 = CONCAT44(0x6705a8,local_100);
    Concurrency::details::_StructuredTaskCollection::_Schedule
              (local_80,(_UnrealizedChore *)&local_b4);
    local_60 = Concurrency::details::
               _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>
               ::vftable;
    local_5c = (_UnrealizedChore *)0x0;
    local_8._0_1_ = 3;
    if (iVar1 < local_18) {
      do {
        if ((*local_50[0] != 0) &&
           ((local_48 != 0 ||
            (bVar3 = Concurrency::details::_Cancellation_beacon::_Confirm_cancel
                               ((_Cancellation_beacon *)local_50), bVar3)))) break;
        if (local_58 != (int *)0x0) {
          if (1 < local_18 - local_1c) {
            local_18 = (local_18 - local_1c) / 2 + local_1c;
          }
          *local_58 = local_18;
          LOCK();
          local_58 = (int *)0x0;
          UNLOCK();
          if (1 < local_18 - local_1c) {
            if ((&stack0x00000000 == (undefined1 *)0xf4) ||
               ((_UnrealizedChore *)&local_124 == (_UnrealizedChore *)0x0)) {
              local_88 = "bad allocation";
              std::exception::exception((exception *)local_c8,&local_88,1);
              local_c8[0] = vftable;
              _CxxThrowException(local_c8,(ThrowInfo *)&DAT_0075f410);
            }
            local_3c = *in_ECX;
            iStack_38 = in_ECX[1];
            local_34 = in_ECX[2];
            iStack_30 = local_1c;
            local_2c = local_18;
            ppiStack_28 = &local_58;
            local_8._0_1_ = 4;
            local_bc = (_UnrealizedChore *)&local_124;
            local_b8 = (_UnrealizedChore *)&local_124;
            local_5c = (_UnrealizedChore *)&local_124;
            Concurrency::details::_UnrealizedChore::ctor_0();
            local_110 = CONCAT44(iStack_38,local_3c);
            local_108 = CONCAT44(iStack_30,local_34);
            _local_100 = CONCAT44(ppiStack_28,local_2c);
            local_124 = Concurrency::
                        task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
                        ::vftable;
            local_120 = lib_fn_66cd40;
            local_8._0_1_ = 3;
            local_114 = 0;
            Concurrency::details::_StructuredTaskCollection::_Schedule
                      (local_80,(_UnrealizedChore *)&local_124);
          }
        }
        local_44 = &local_1c;
        _local_100 = CONCAT44(0x6706ed,local_100);
        Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
                  (*(int *)(*in_ECX + 4) + local_20);
        _local_100 = CONCAT44(0x67070f,local_100);
        FUN_0066f280();
        local_44 = (int *)0x0;
        if (local_40 != 0) {
          local_d0 = 0;
          local_cc = _UnderlyingYield_exref;
          do {
            Concurrency::details::_SpinWait<1>::_SpinOnce(local_d8);
          } while (local_40 != 0);
        }
        local_24 = local_24 + 1;
        local_20 = local_20 + *(int *)local_84[1];
        in_ECX = local_84;
        local_1c = local_24;
      } while (local_24 < local_18);
    }
    LOCK();
    local_48 = 1;
    UNLOCK();
    _local_100 = CONCAT44((_UnrealizedChore *)local_80,0x67077c);
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_80);
    local_48 = 2;
    local_8._0_1_ = 2;
    Concurrency::details::_Chore::ctor_6();
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_8._0_1_ = 5;
    if ((local_ac != 0) && (local_a4 == '\0')) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection((_UnrealizedChore *)&local_b4);
    }
    local_b4 = Concurrency::details::_Chore::vftable;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_48 != 2) {
      if (local_54 != 0) {
        LOCK();
        **(int **)(local_54 + 8) = **(int **)(local_54 + 8) + 1;
        UNLOCK();
      }
      LOCK();
      local_48 = 1;
      UNLOCK();
    }
    Concurrency::details::_Cancellation_beacon::~_Cancellation_beacon
              ((_Cancellation_beacon *)local_50);
    local_8 = 0xffffffff;
    if (0 < local_70) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_80);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_78 != 0) && (local_78 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
        }
        Concurrency::missing_wait::missing_wait(local_e4);
        _local_100 = CONCAT44(local_e4,0x670843);
        _CxxThrowException(local_e4,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_78 != 0) && (local_78 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
    }
  }
LAB_00670892:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* std::bad_alloc::ctor_0 @ 006708c0 */


void std::bad_alloc::ctor_0(void)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int *in_ECX;
  int iVar4;
  undefined **local_124;
  code *local_120;
  undefined1 local_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  missing_wait local_e4 [12];
  _SpinWait<1> local_d8 [8];
  undefined4 local_d0;
  code *local_cc;
  undefined **local_c8 [3];
  _UnrealizedChore *local_bc;
  _UnrealizedChore *local_b8;
  undefined **local_b4;
  code *local_b0;
  int local_ac;
  char local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  char *local_88;
  int *local_84;
  _StructuredTaskCollection local_80 [4];
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined **local_60;
  _UnrealizedChore *local_5c;
  int *local_58;
  int local_54;
  int *local_50 [2];
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int iStack_38;
  int local_34;
  int iStack_30;
  int local_2c;
  int **ppiStack_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f8225;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX[3];
  local_18 = in_ECX[4];
  local_84 = in_ECX;
  if (in_ECX[5] != 0) {
    _local_100 = CONCAT44(0x67090f,local_100);
    cVar2 = lib_fn_671340();
    if (cVar2 == '\0') goto LAB_00670d42;
  }
  iVar1 = local_1c;
  local_20 = *(int *)in_ECX[1] * local_1c;
  local_24 = local_1c;
  if (local_18 - local_1c == 1) {
    _local_100 = CONCAT44(0x670948,local_100);
    Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
              (*(int *)(*in_ECX + 4) + local_20);
    _local_100 = CONCAT44(0x67096a,local_100);
    FUN_0066ed80();
  }
  else {
    local_70 = 0;
    local_6c = 0x80000000;
    local_68 = 0;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    }
    local_74 = 0;
    local_7c = 0x1fffffff;
    local_78 = 0;
    local_8 = 0;
    _local_100 = CONCAT44(0x6709d0,local_100);
    lib_fn_66e1b0();
    local_3c = *in_ECX;
    iStack_38 = in_ECX[1];
    local_34 = in_ECX[2];
    iStack_30 = local_1c;
    local_2c = local_18;
    ppiStack_28 = &local_58;
    local_8._0_1_ = 1;
    Concurrency::details::_UnrealizedChore::ctor_0();
    local_a0 = CONCAT44(iStack_38,local_3c);
    local_98 = CONCAT44(iStack_30,local_34);
    local_90 = CONCAT44(ppiStack_28,local_2c);
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_b0 = lib_fn_66cd50;
    local_8._0_1_ = 2;
    local_a4 = '\0';
    _local_100 = CONCAT44(0x670a58,local_100);
    Concurrency::details::_StructuredTaskCollection::_Schedule
              (local_80,(_UnrealizedChore *)&local_b4);
    local_60 = Concurrency::details::
               _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>
               ::vftable;
    local_5c = (_UnrealizedChore *)0x0;
    local_8._0_1_ = 3;
    if (iVar1 < local_18) {
      do {
        if ((*local_50[0] != 0) &&
           ((local_48 != 0 ||
            (bVar3 = Concurrency::details::_Cancellation_beacon::_Confirm_cancel
                               ((_Cancellation_beacon *)local_50), bVar3)))) break;
        if (local_58 != (int *)0x0) {
          if (1 < local_18 - local_1c) {
            local_18 = (local_18 - local_1c) / 2 + local_1c;
          }
          *local_58 = local_18;
          LOCK();
          local_58 = (int *)0x0;
          UNLOCK();
          if (1 < local_18 - local_1c) {
            if ((&stack0x00000000 == (undefined1 *)0xf4) ||
               ((_UnrealizedChore *)&local_124 == (_UnrealizedChore *)0x0)) {
              local_88 = "bad allocation";
              std::exception::exception((exception *)local_c8,&local_88,1);
              local_c8[0] = vftable;
              _CxxThrowException(local_c8,(ThrowInfo *)&DAT_0075f410);
            }
            local_3c = *in_ECX;
            iStack_38 = in_ECX[1];
            local_34 = in_ECX[2];
            iStack_30 = local_1c;
            local_2c = local_18;
            ppiStack_28 = &local_58;
            local_8._0_1_ = 4;
            local_bc = (_UnrealizedChore *)&local_124;
            local_b8 = (_UnrealizedChore *)&local_124;
            local_5c = (_UnrealizedChore *)&local_124;
            Concurrency::details::_UnrealizedChore::ctor_0();
            local_110 = CONCAT44(iStack_38,local_3c);
            local_108 = CONCAT44(iStack_30,local_34);
            _local_100 = CONCAT44(ppiStack_28,local_2c);
            local_124 = Concurrency::
                        task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
                        ::vftable;
            local_120 = lib_fn_66cd50;
            local_8._0_1_ = 3;
            local_114 = 0;
            Concurrency::details::_StructuredTaskCollection::_Schedule
                      (local_80,(_UnrealizedChore *)&local_124);
          }
        }
        local_44 = &local_1c;
        _local_100 = CONCAT44(0x670b9d,local_100);
        Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of
                  (*(int *)(*in_ECX + 4) + local_20);
        _local_100 = CONCAT44(0x670bbf,local_100);
        FUN_0066ed80();
        local_44 = (int *)0x0;
        if (local_40 != 0) {
          local_d0 = 0;
          local_cc = _UnderlyingYield_exref;
          do {
            Concurrency::details::_SpinWait<1>::_SpinOnce(local_d8);
          } while (local_40 != 0);
        }
        local_24 = local_24 + 1;
        local_20 = local_20 + *(int *)local_84[1];
        in_ECX = local_84;
        local_1c = local_24;
      } while (local_24 < local_18);
    }
    LOCK();
    local_48 = 1;
    UNLOCK();
    _local_100 = CONCAT44((_UnrealizedChore *)local_80,0x670c2c);
    Concurrency::details::_StructuredTaskCollection::_RunAndWait((_UnrealizedChore *)local_80);
    local_48 = 2;
    local_8._0_1_ = 2;
    Concurrency::details::_Chore::ctor_7();
    local_b4 = Concurrency::
               task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
               ::vftable;
    local_8._0_1_ = 5;
    if ((local_ac != 0) && (local_a4 == '\0')) {
      Concurrency::details::_UnrealizedChore::_CheckTaskCollection((_UnrealizedChore *)&local_b4);
    }
    local_b4 = Concurrency::details::_Chore::vftable;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_48 != 2) {
      if (local_54 != 0) {
        LOCK();
        **(int **)(local_54 + 8) = **(int **)(local_54 + 8) + 1;
        UNLOCK();
      }
      LOCK();
      local_48 = 1;
      UNLOCK();
    }
    Concurrency::details::_Cancellation_beacon::~_Cancellation_beacon
              ((_Cancellation_beacon *)local_50);
    local_8 = 0xffffffff;
    if (0 < local_70) {
      Concurrency::details::_StructuredTaskCollection::_Abort(local_80);
      cVar2 = __uncaught_exception();
      if (cVar2 == '\0') {
        if ((local_78 != 0) && (local_78 != 2)) {
          Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
        }
        Concurrency::missing_wait::missing_wait(local_e4);
        _local_100 = CONCAT44(local_e4,0x670cf3);
        _CxxThrowException(local_e4,(ThrowInfo *)&DAT_0075f3d8);
      }
    }
    if ((local_78 != 0) && (local_78 != 2)) {
      Concurrency::details::_StructuredTaskCollection::_CleanupToken(local_80);
    }
  }
LAB_00670d42:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* Concurrency::details::_MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670d70 */

void Concurrency::details::
     _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_14();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670da0 */

void Concurrency::details::
     _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_15();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670dd0 */

void Concurrency::details::
     _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_16();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670e00 */

void Concurrency::details::
     _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_17();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670e30 */

void Concurrency::details::
     _MallocaArrayHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_18();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670e60 */

void Concurrency::details::
     _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_19();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670e90 */

void Concurrency::details::
     _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_20();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670ec0 */

void Concurrency::details::
     _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_21();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670ef0 */

void Concurrency::details::
     _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_6();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>::vfunc_0 @ 00670f20 */

void Concurrency::details::
     _MallocaListHolder<Concurrency::task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>_>
     ::vfunc_0(byte param_1)

{
  void *in_ECX;
  
  _Chore::ctor_7();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_Chore::ctor_4 @ 00670f50 */

void Concurrency::details::_Chore::ctor_4(byte param_1)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_c31a3785b8ee29a1ce8445e019cbe6ee>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  local_8 = 0xffffffff;
  *(undefined ***)in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    Concurrency::Free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_5 @ 00670fd0 */

void Concurrency::details::_Chore::ctor_5(byte param_1)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadVertex*,std::allocator<plasma::QuadVertex*>_>,plasma::QuadVertex*>,int,<lambda_fe4ce4a6aaf0318c62c756eaccc0431b>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  local_8 = 0xffffffff;
  *(undefined ***)in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    Concurrency::Free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_0 @ 00671050 */

void Concurrency::details::_Chore::ctor_0(byte param_1)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_9843e8019373a7557d3f3e498d32c258>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  local_8 = 0xffffffff;
  *(undefined ***)in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    Concurrency::Free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_1 @ 006710d0 */

void Concurrency::details::_Chore::ctor_1(byte param_1)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadEdge,std::allocator<plasma::QuadEdge>_>,plasma::QuadEdge>,int,<lambda_e3fd6255bcf168381cb2d01c4cfc52ca>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  local_8 = 0xffffffff;
  *(undefined ***)in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    Concurrency::Free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::ctor_2 @ 00671150 */

void Concurrency::details::_Chore::ctor_2(byte param_1)

{
  _UnrealizedChore *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f7ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX =
       task_handle<Concurrency::_Parallel_chunk_helper<Concurrency::details::_Vector_iterator<Concurrency::concurrent_vector<plasma::QuadFace,std::allocator<plasma::QuadFace>_>,plasma::QuadFace>,int,<lambda_37224fa58ba67e25838a8994307bb82e>,Concurrency::auto_partitioner,1>_>
       ::vftable;
  local_8 = 0;
  if ((*(int *)(in_ECX + 8) != 0) && (in_ECX[0x10] == (_UnrealizedChore)0x0)) {
    Concurrency::details::_UnrealizedChore::_CheckTaskCollection(in_ECX);
  }
  local_8 = 0xffffffff;
  *(undefined ***)in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    Concurrency::Free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}




/* Concurrency::details::_Chore::vfunc_0 @ 006711d0 */

void Concurrency::details::_Chore::vfunc_0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::details::_Chore::ctor_3 @ 00671200 */

void Concurrency::details::_Chore::ctor_3(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = vftable;
  if ((param_1 & 1) != 0) {
    Concurrency::Free(in_ECX);
  }
  return;
}




/* std::bad_alloc::vfunc_0 @ 00671230 */

void std::bad_alloc::vfunc_0(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = vftable;
  std::exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Concurrency::missing_wait::vfunc_0 @ 00671260 */

void Concurrency::missing_wait::vfunc_0(byte param_1)

{
  exception *in_ECX;
  
  std::exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}




/* Global::lib_fn_6712c0 @ 006712c0 */

void lib_fn_6712c0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  iVar3 = *param_2;
  uVar4 = Concurrency::details::_Concurrent_vector_base_v4::_Segment_index_of(iVar2 + iVar3);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + uVar4 * 4) +
                  ((iVar2 + iVar3) - (1 << ((byte)uVar4 & 0x1f) & 0xfffffffeU)) * 4);
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  return;
}




/* Global::lib_fn_671340 @ 00671340 */

uint lib_fn_671340(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  uint in_EAX;
  code *pcVar5;
  undefined4 *in_ECX;
  _SpinWait<1> local_14 [8];
  undefined4 local_c;
  code *local_8;
  uint3 extraout_var;
  
  pcVar5 = _Yield_exref;
  if (in_ECX[4] != 0) {
    return in_EAX & 0xffffff00;
  }
  iVar1 = *param_1;
  *in_ECX = param_1;
  local_c = 0;
  local_8 = pcVar5;
  if (*param_1 == iVar1) {
    do {
      if (in_ECX[4] != 0) break;
      if ((in_ECX[5] == 0) ||
         (bVar4 = Concurrency::details::_Context::_IsSynchronouslyBlocked((_Context *)(in_ECX + 3)),
         !bVar4)) {
        Concurrency::details::_SpinWait<1>::_SpinOnce(local_14);
        pcVar5 = (code *)((uint)extraout_var << 8);
      }
      else {
        LOCK();
        in_ECX[6] = in_ECX[6] + 1;
        UNLOCK();
        piVar2 = (int *)in_ECX[5];
        if ((((piVar2 != (int *)0x0) &&
             (bVar4 = Concurrency::details::_Context::_IsSynchronouslyBlocked
                                ((_Context *)(in_ECX + 3)), bVar4)) && (*param_1 == iVar1)) &&
           (in_ECX[4] == 0)) {
          *in_ECX = 0;
          iVar3 = *piVar2;
          *param_1 = iVar3 + 1;
          param_1[1] = piVar2[1];
          piVar2[1] = iVar3 + 1;
        }
        piVar2 = in_ECX + 6;
        LOCK();
        pcVar5 = (code *)*piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
    } while (*param_1 == iVar1);
    if (*param_1 == iVar1) {
      return (uint)pcVar5 & 0xffffff00;
    }
  }
  return (uint)(param_1[1] != *param_1 && -1 < param_1[1] - *param_1);
}




/* Global::eh_catchall_00672f4f @ 00672f4f */

void Catch_All_00672f4f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0067795a @ 0067795a */

void Catch_All_0067795a(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00677b82 @ 00677b82 */

void Catch_All_00677b82(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    std_basic_string_Tidy(iVar2);
  }
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_00677e05 @ 00677e05 */

void Catch_All_00677e05(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
}




/* Global::eh_catchall_0067e0a5 @ 0067e0a5 */

void Catch_All_0067e0a5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* Global::eh_catchall_0067e1cf @ 0067e1cf */

void Catch_All_0067e1cf(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
}




/* plasma::PlasmaFont::ctor_0 @ 0067e210 */

void plasma::PlasmaFont::ctor_0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f8a58;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  NamedObject::ctor_3(param_1,param_2);
  *in_ECX = vftable;
  local_8 = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  uVar2 = rbtree_allocHead24(uVar1);
  in_ECX[0x16] = uVar2;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  ExceptionList = local_10;
  return;
}




/* Global::lib_fn_67e4d0 @ 0067e4d0 */

int lib_fn_67e4d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  int *piVar10;
  uint local_10;
  
  iVar8 = lib_fn_64fd30(in_ECX + 0xc);
  *(undefined4 *)(iVar8 + 0x68) = *(undefined4 *)(in_ECX + 0x68);
  *(undefined4 *)(iVar8 + 0x6c) = *(undefined4 *)(in_ECX + 0x6c);
  *(undefined4 *)(iVar8 + 0x60) = *(undefined4 *)(in_ECX + 0x60);
  *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(in_ECX + 100);
  piVar10 = (int *)**(int **)(in_ECX + 0x58);
  if (piVar10 != *(int **)(in_ECX + 0x58)) {
    do {
      iVar2 = piVar10[5];
      lib_fn_67f1b0((short)piVar10[4],iVar2,iVar2 + 8,*(undefined4 *)(iVar2 + 0x14),
                   *(undefined4 *)(iVar2 + 0x10));
      if (*(char *)((int)piVar10 + 0xd) == '\0') {
        piVar3 = (int *)piVar10[2];
        if (*(char *)((int)piVar3 + 0xd) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0xd);
          piVar10 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0xd);
            piVar10 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar10[1] + 0xd);
          piVar5 = (int *)piVar10[1];
          piVar3 = piVar10;
          while ((piVar10 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar10[2]))) {
            cVar1 = *(char *)(piVar10[1] + 0xd);
            piVar5 = (int *)piVar10[1];
            piVar3 = piVar10;
          }
        }
      }
    } while (piVar10 != *(int **)(in_ECX + 0x58));
  }
  piVar10 = (int *)(iVar8 + 0x24);
  if (piVar10 != (int *)(in_ECX + 0x24)) {
    pvVar4 = *(void **)(*piVar10 + 4);
    if (*(char *)((int)pvVar4 + 0xd) == '\0') {
      rbtree_destroyRec_simple(*(undefined4 *)((int)pvVar4 + 8));
      operator_delete(pvVar4);
    }
    *(int *)(*piVar10 + 4) = *piVar10;
    local_10 = local_10 & 0xffffff00;
    *(int *)*piVar10 = *piVar10;
    *(int *)(*piVar10 + 8) = *piVar10;
    iVar2 = *piVar10;
    *(undefined4 *)(iVar8 + 0x28) = 0;
    uVar9 = tree_cloneRecursive(*(undefined4 *)(*(int *)(in_ECX + 0x24) + 4),iVar2,local_10);
    *(undefined4 *)(iVar2 + 4) = uVar9;
    piVar3 = (int *)*piVar10;
    *(undefined4 *)(iVar8 + 0x28) = *(undefined4 *)(in_ECX + 0x28);
    piVar5 = (int *)piVar3[1];
    if (*(char *)((int)piVar5 + 0xd) == '\0') {
      cVar1 = *(char *)(*piVar5 + 0xd);
      piVar7 = (int *)*piVar5;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar7 + 0xd);
        piVar5 = piVar7;
        piVar7 = (int *)*piVar7;
      }
      *piVar3 = (int)piVar5;
      iVar2 = *(int *)(*piVar10 + 4);
      iVar6 = *(int *)(iVar2 + 8);
      cVar1 = *(char *)(iVar6 + 0xd);
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*(int *)(iVar6 + 8) + 0xd);
        iVar2 = iVar6;
        iVar6 = *(int *)(iVar6 + 8);
      }
      *(int *)(*piVar10 + 8) = iVar2;
    }
    else {
      *piVar3 = (int)piVar3;
      *(int *)(*piVar10 + 8) = *piVar10;
    }
  }
  *(undefined4 *)(iVar8 + 0x4c) = *(undefined4 *)(in_ECX + 0x4c);
  *(undefined4 *)(iVar8 + 0x50) = *(undefined4 *)(in_ECX + 0x50);
  return iVar8;
}




/* Global::lib_fn_67f1b0 @ 0067f1b0 */

void lib_fn_67f1b0(undefined4 param_1,float *param_2,float *param_3,float param_4,float param_5)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int in_ECX;
  float *pfVar4;
  float fVar5;
  
  pfVar2 = param_3;
  pfVar1 = param_2;
  if (*(int *)(in_ECX + 0x5c) == 0) {
    *(float *)(in_ECX + 0x60) = *param_2;
    *(float *)(in_ECX + 100) = param_2[1];
    *(float *)(in_ECX + 0x68) = *param_3;
    *(float *)(in_ECX + 0x6c) = param_3[1];
  }
  puVar3 = (undefined4 *)lib_fn_67e340(&param_1);
  pfVar4 = (float *)*puVar3;
  if ((float *)*puVar3 == (float *)0x0) {
    param_3 = operator_new(0x18);
    puVar3 = (undefined4 *)lib_fn_67e340(&param_1);
    *puVar3 = param_3;
    pfVar4 = param_3;
  }
  if (*pfVar1 < *(float *)(in_ECX + 0x60)) {
    *(float *)(in_ECX + 0x60) = *pfVar1;
  }
  if (pfVar1[1] < *(float *)(in_ECX + 100)) {
    *(float *)(in_ECX + 100) = pfVar1[1];
  }
  fVar5 = *pfVar1 + *pfVar2;
  if (*(float *)(in_ECX + 0x68) <= fVar5 && fVar5 != *(float *)(in_ECX + 0x68)) {
    *(float *)(in_ECX + 0x68) = fVar5;
  }
  fVar5 = pfVar2[1] + pfVar1[1];
  if (*(float *)(in_ECX + 0x6c) <= fVar5 && fVar5 != *(float *)(in_ECX + 0x6c)) {
    *(float *)(in_ECX + 0x6c) = fVar5;
  }
  *pfVar4 = *pfVar1;
  pfVar4[1] = pfVar1[1];
  pfVar4[2] = *pfVar2;
  pfVar4[3] = pfVar2[1];
  pfVar4[5] = param_4;
  pfVar4[4] = param_5;
  return;
}




/* Global::lib_fn_67f980 @ 0067f980 */

void lib_fn_67f980(undefined4 param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  undefined4 *puVar1;
  float *pfVar2;
  int in_ECX;
  float fVar3;
  
  puVar1 = (undefined4 *)lib_fn_67e340(&param_1);
  pfVar2 = (float *)*puVar1;
  if (pfVar2 == (float *)0x0) {
    pfVar2 = operator_new(0x24);
    puVar1 = (undefined4 *)lib_fn_67e340(&param_1);
    *puVar1 = pfVar2;
  }
  if (*param_2 < *(float *)(in_ECX + 100)) {
    *(float *)(in_ECX + 100) = *param_2;
  }
  if (param_2[1] < *(float *)(in_ECX + 0x68)) {
    *(float *)(in_ECX + 0x68) = param_2[1];
  }
  fVar3 = *param_2 + *param_3;
  if (*(float *)(in_ECX + 0x6c) <= fVar3 && fVar3 != *(float *)(in_ECX + 0x6c)) {
    *(float *)(in_ECX + 0x6c) = fVar3;
  }
  fVar3 = param_3[1] + param_2[1];
  if (*(float *)(in_ECX + 0x70) <= fVar3 && fVar3 != *(float *)(in_ECX + 0x70)) {
    *(float *)(in_ECX + 0x70) = fVar3;
  }
  *pfVar2 = *param_2;
  pfVar2[1] = param_2[1];
  pfVar2[2] = *param_3;
  pfVar2[3] = param_3[1];
  pfVar2[4] = *param_4;
  pfVar2[5] = param_4[1];
  pfVar2[6] = *param_5;
  pfVar2[7] = param_5[1];
  pfVar2[8] = param_6;
  return;
}




/* Global::lib_fn_67fa50 @ 0067fa50 */

void lib_fn_67fa50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = param_1;
  return;
}




/* Global::eh_catchall_0067fc38 @ 0067fc38 */

void Catch_All_0067fc38(void)

{
  int unaff_EBP;
  
  std_Tree_destroyHead(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_0067fd6d @ 0067fd6d */

void Catch_All_0067fd6d(void)

{
  int unaff_EBP;
  
  std_Tree_destroyHead(*(undefined4 *)(unaff_EBP + 0x14));
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* Global::eh_catchall_006812ef @ 006812ef */

void Catch_All_006812ef(void)

{
  unwind_free_object();
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}




/* KERNEL32.DLL::Sleep @ 0068d41c */

void Sleep(DWORD dwMilliseconds)

{
  Sleep(dwMilliseconds);
  return;
}




/* KERNEL32.DLL::DeleteFileA @ 0068d422 */

BOOL DeleteFileA(LPCSTR lpFileName)

{
  BOOL BVar1;
  
  BVar1 = DeleteFileA(lpFileName);
  return BVar1;
}




/* KERNEL32.DLL::LocalFree @ 0068d428 */

HLOCAL LocalFree(HLOCAL hMem)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalFree(hMem);
  return pvVar1;
}




/* KERNEL32.DLL::AreFileApisANSI @ 0068d42e */

BOOL AreFileApisANSI(void)

{
  BOOL BVar1;
  
  BVar1 = AreFileApisANSI();
  return BVar1;
}




/* KERNEL32.DLL::GetSystemTime @ 0068d434 */

void GetSystemTime(LPSYSTEMTIME lpSystemTime)

{
  GetSystemTime(lpSystemTime);
  return;
}




/* KERNEL32.DLL::GetTempPathA @ 0068d43a */

DWORD GetTempPathA(DWORD nBufferLength,LPSTR lpBuffer)

{
  DWORD DVar1;
  
  DVar1 = GetTempPathA(nBufferLength,lpBuffer);
  return DVar1;
}




/* KERNEL32.DLL::GetCurrentProcessId @ 0068d440 */

DWORD GetCurrentProcessId(void)

{
  DWORD DVar1;
  
  DVar1 = GetCurrentProcessId();
  return DVar1;
}




/* KERNEL32.DLL::DeleteFileW @ 0068d446 */

BOOL DeleteFileW(LPCWSTR lpFileName)

{
  BOOL BVar1;
  
  BVar1 = DeleteFileW(lpFileName);
  return BVar1;
}




/* KERNEL32.DLL::CloseHandle @ 0068d44c */

BOOL CloseHandle(HANDLE hObject)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle(hObject);
  return BVar1;
}




/* KERNEL32.DLL::GetVersionExA @ 0068d452 */

BOOL GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)

{
  BOOL BVar1;
  
  BVar1 = GetVersionExA(lpVersionInformation);
  return BVar1;
}




/* KERNEL32.DLL::GetFileAttributesExW @ 0068d45e */

BOOL GetFileAttributesExW
               (LPCWSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation)

{
  BOOL BVar1;
  
  BVar1 = GetFileAttributesExW(lpFileName,fInfoLevelId,lpFileInformation);
  return BVar1;
}




/* KERNEL32.DLL::GetSystemInfo @ 0068d464 */

void GetSystemInfo(LPSYSTEM_INFO lpSystemInfo)

{
  GetSystemInfo(lpSystemInfo);
  return;
}




/* KERNEL32.DLL::CreateFileMappingW @ 0068d470 */

HANDLE CreateFileMappingW(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect
                         ,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCWSTR lpName)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileMappingW(hFile,lpFileMappingAttributes,flProtect,dwMaximumSizeHigh,
                              dwMaximumSizeLow,lpName);
  return pvVar1;
}




/* KERNEL32.DLL::LoadLibraryA @ 0068d47c */

HMODULE LoadLibraryA(LPCSTR lpLibFileName)

{
  HMODULE pHVar1;
  
  pHVar1 = LoadLibraryA(lpLibFileName);
  return pHVar1;
}




/* KERNEL32.DLL::LockFileEx @ 0068d488 */

BOOL LockFileEx(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD nNumberOfBytesToLockLow,
               DWORD nNumberOfBytesToLockHigh,LPOVERLAPPED lpOverlapped)

{
  BOOL BVar1;
  
  BVar1 = LockFileEx(hFile,dwFlags,dwReserved,nNumberOfBytesToLockLow,nNumberOfBytesToLockHigh,
                     lpOverlapped);
  return BVar1;
}




/* KERNEL32.DLL::GetProcAddress @ 0068d494 */

FARPROC GetProcAddress(HMODULE hModule,LPCSTR lpProcName)

{
  FARPROC pFVar1;
  
  pFVar1 = GetProcAddress(hModule,lpProcName);
  return pFVar1;
}




/* KERNEL32.DLL::GetLastError @ 0068d49a */

DWORD GetLastError(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  return DVar1;
}




/* KERNEL32.DLL::GetTempPathW @ 0068d4a0 */

DWORD GetTempPathW(DWORD nBufferLength,LPWSTR lpBuffer)

{
  DWORD DVar1;
  
  DVar1 = GetTempPathW(nBufferLength,lpBuffer);
  return DVar1;
}




/* KERNEL32.DLL::FlushFileBuffers @ 0068d4a6 */

BOOL FlushFileBuffers(HANDLE hFile)

{
  BOOL BVar1;
  
  BVar1 = FlushFileBuffers(hFile);
  return BVar1;
}




/* KERNEL32.DLL::MultiByteToWideChar @ 0068d4ac */

int MultiByteToWideChar(UINT CodePage,DWORD dwFlags,LPCSTR lpMultiByteStr,int cbMultiByte,
                       LPWSTR lpWideCharStr,int cchWideChar)

{
  int iVar1;
  
  iVar1 = MultiByteToWideChar(CodePage,dwFlags,lpMultiByteStr,cbMultiByte,lpWideCharStr,cchWideChar)
  ;
  return iVar1;
}




/* KERNEL32.DLL::CreateFileW @ 0068d4b2 */

HANDLE CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,
                  LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,
                  DWORD dwFlagsAndAttributes,HANDLE hTemplateFile)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileW(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,
                       dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);
  return pvVar1;
}




/* KERNEL32.DLL::ReadFile @ 0068d4b8 */

BOOL ReadFile(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,
             LPOVERLAPPED lpOverlapped)

{
  BOOL BVar1;
  
  BVar1 = ReadFile(hFile,lpBuffer,nNumberOfBytesToRead,lpNumberOfBytesRead,lpOverlapped);
  return BVar1;
}




/* KERNEL32.DLL::GetFileAttributesW @ 0068d4be */

DWORD GetFileAttributesW(LPCWSTR lpFileName)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesW(lpFileName);
  return DVar1;
}




/* KERNEL32.DLL::GetFileAttributesA @ 0068d4d0 */

DWORD GetFileAttributesA(LPCSTR lpFileName)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesA(lpFileName);
  return DVar1;
}




/* KERNEL32.DLL::FormatMessageW @ 0068d4dc */

DWORD FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,
                    LPWSTR lpBuffer,DWORD nSize,va_list *Arguments)

{
  DWORD DVar1;
  
  DVar1 = FormatMessageW(dwFlags,lpSource,dwMessageId,dwLanguageId,lpBuffer,nSize,Arguments);
  return DVar1;
}




/* KERNEL32.DLL::LoadLibraryW @ 0068d4e2 */

HMODULE LoadLibraryW(LPCWSTR lpLibFileName)

{
  HMODULE pHVar1;
  
  pHVar1 = LoadLibraryW(lpLibFileName);
  return pHVar1;
}




/* KERNEL32.DLL::WideCharToMultiByte @ 0068d4e8 */

int WideCharToMultiByte(UINT CodePage,DWORD dwFlags,LPCWSTR lpWideCharStr,int cchWideChar,
                       LPSTR lpMultiByteStr,int cbMultiByte,LPCSTR lpDefaultChar,
                       LPBOOL lpUsedDefaultChar)

{
  int iVar1;
  
  iVar1 = WideCharToMultiByte(CodePage,dwFlags,lpWideCharStr,cchWideChar,lpMultiByteStr,cbMultiByte,
                              lpDefaultChar,lpUsedDefaultChar);
  return iVar1;
}




/* KERNEL32.DLL::WriteFile @ 0068d4ee */

BOOL WriteFile(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,
              LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped)

{
  BOOL BVar1;
  
  BVar1 = WriteFile(hFile,lpBuffer,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);
  return BVar1;
}




/* KERNEL32.DLL::FormatMessageA @ 0068d4f4 */

DWORD FormatMessageA(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,
                    LPSTR lpBuffer,DWORD nSize,va_list *Arguments)

{
  DWORD DVar1;
  
  DVar1 = FormatMessageA(dwFlags,lpSource,dwMessageId,dwLanguageId,lpBuffer,nSize,Arguments);
  return DVar1;
}




/* KERNEL32.DLL::GetSystemTimeAsFileTime @ 0068d4fa */

void GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime)

{
  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
  return;
}




/* KERNEL32.DLL::UnlockFileEx @ 0068d506 */

BOOL UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD nNumberOfBytesToUnlockLow,
                 DWORD nNumberOfBytesToUnlockHigh,LPOVERLAPPED lpOverlapped)

{
  BOOL BVar1;
  
  BVar1 = UnlockFileEx(hFile,dwReserved,nNumberOfBytesToUnlockLow,nNumberOfBytesToUnlockHigh,
                       lpOverlapped);
  return BVar1;
}




/* KERNEL32.DLL::GetTickCount @ 0068d50c */

DWORD GetTickCount(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  return DVar1;
}




/* KERNEL32.DLL::LockFile @ 0068d518 */

BOOL LockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,
             DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh)

{
  BOOL BVar1;
  
  BVar1 = LockFile(hFile,dwFileOffsetLow,dwFileOffsetHigh,nNumberOfBytesToLockLow,
                   nNumberOfBytesToLockHigh);
  return BVar1;
}




/* KERNEL32.DLL::UnlockFile @ 0068d51e */

BOOL UnlockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,
               DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh)

{
  BOOL BVar1;
  
  BVar1 = UnlockFile(hFile,dwFileOffsetLow,dwFileOffsetHigh,nNumberOfBytesToUnlockLow,
                     nNumberOfBytesToUnlockHigh);
  return BVar1;
}




/* KERNEL32.DLL::QueryPerformanceCounter @ 0068d52a */

BOOL QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)

{
  BOOL BVar1;
  
  BVar1 = QueryPerformanceCounter(lpPerformanceCount);
  return BVar1;
}




/* KERNEL32.DLL::FreeLibrary @ 0068d53c */

BOOL FreeLibrary(HMODULE hLibModule)

{
  BOOL BVar1;
  
  BVar1 = FreeLibrary(hLibModule);
  return BVar1;
}




/* KERNEL32.DLL::SetEndOfFile @ 0068d542 */

BOOL SetEndOfFile(HANDLE hFile)

{
  BOOL BVar1;
  
  BVar1 = SetEndOfFile(hFile);
  return BVar1;
}




/* KERNEL32.DLL::UnmapViewOfFile @ 0068d548 */

BOOL UnmapViewOfFile(LPCVOID lpBaseAddress)

{
  BOOL BVar1;
  
  BVar1 = UnmapViewOfFile(lpBaseAddress);
  return BVar1;
}




/* KERNEL32.DLL::MapViewOfFile @ 0068d54e */

LPVOID MapViewOfFile(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,
                    DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap)

{
  LPVOID pvVar1;
  
  pvVar1 = MapViewOfFile(hFileMappingObject,dwDesiredAccess,dwFileOffsetHigh,dwFileOffsetLow,
                         dwNumberOfBytesToMap);
  return pvVar1;
}




/* KERNEL32.DLL::SetFilePointer @ 0068d554 */

DWORD SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod
                    )

{
  DWORD DVar1;
  
  DVar1 = SetFilePointer(hFile,lDistanceToMove,lpDistanceToMoveHigh,dwMoveMethod);
  return DVar1;
}




/* KERNEL32.DLL::GetFileSize @ 0068d560 */

DWORD GetFileSize(HANDLE hFile,LPDWORD lpFileSizeHigh)

{
  DWORD DVar1;
  
  DVar1 = GetFileSize(hFile,lpFileSizeHigh);
  return DVar1;
}




/* KERNEL32.DLL::CreateFileA @ 0068d566 */

HANDLE CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,
                  LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,
                  DWORD dwFlagsAndAttributes,HANDLE hTemplateFile)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileA(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,
                       dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);
  return pvVar1;
}




/* KERNEL32.DLL::GetFullPathNameA @ 0068d572 */

DWORD GetFullPathNameA(LPCSTR lpFileName,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart)

{
  DWORD DVar1;
  
  DVar1 = GetFullPathNameA(lpFileName,nBufferLength,lpBuffer,lpFilePart);
  return DVar1;
}




/* KERNEL32.DLL::GetFullPathNameW @ 0068d578 */

DWORD GetFullPathNameW(LPCWSTR lpFileName,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart)

{
  DWORD DVar1;
  
  DVar1 = GetFullPathNameW(lpFileName,nBufferLength,lpBuffer,lpFilePart);
  return DVar1;
}




/* MSVCP110.DLL::std::basic_ios<char,std::char_traits<char>_>::_Add_vtordisp2 @ 0068d5e0 */

void __thiscall
std::basic_ios<char,std::char_traits<char>_>::_Add_vtordisp2
          (basic_ios<char,std::char_traits<char>_> *this)

{
  _Add_vtordisp2(this);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::_Lock @ 0068d5e6 */

void __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Lock
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  _Lock(this);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::_Unlock @ 0068d5ec */

void __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Unlock
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  _Unlock(this);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::imbue @ 0068d5f2 */

void __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::imbue
          (basic_streambuf<char,std::char_traits<char>_> *this,locale *param_1)

{
  imbue(this,param_1);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::setbuf @ 0068d5f8 */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::setbuf
          (basic_streambuf<char,std::char_traits<char>_> *this,char *param_1,__int64 param_2)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = setbuf(this,param_1,param_2);
  return pbVar1;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::showmanyc @ 0068d5fe */

__int64 __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::showmanyc
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  __int64 _Var1;
  
  _Var1 = showmanyc(this);
  return _Var1;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::sync @ 0068d604 */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::sync
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  int iVar1;
  
  iVar1 = sync(this);
  return iVar1;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::uflow @ 0068d60a */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::uflow
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  int iVar1;
  
  iVar1 = uflow(this);
  return iVar1;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::xsgetn @ 0068d610 */

__int64 __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::xsgetn
          (basic_streambuf<char,std::char_traits<char>_> *this,char *param_1,__int64 param_2)

{
  __int64 _Var1;
  
  _Var1 = xsgetn(this,param_1,param_2);
  return _Var1;
}




/* MSVCP110.DLL::std::basic_streambuf<char,std::char_traits<char>_>::xsputn @ 0068d616 */

__int64 __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::xsputn
          (basic_streambuf<char,std::char_traits<char>_> *this,char *param_1,__int64 param_2)

{
  __int64 _Var1;
  
  _Var1 = xsputn(this,param_1,param_2);
  return _Var1;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::_Lock @ 0068d61c */

void __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::_Lock
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this)

{
  _Lock(this);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::_Unlock @ 0068d622 */

void __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::_Unlock
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this)

{
  _Unlock(this);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::imbue @ 0068d628 */

void __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::imbue
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this,locale *param_1)

{
  imbue(this,param_1);
  return;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setbuf @ 0068d62e */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setbuf
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this,wchar_t *param_1,
          __int64 param_2)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar1;
  
  pbVar1 = setbuf(this,param_1,param_2);
  return pbVar1;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::showmanyc @ 0068d634 */

__int64 __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::showmanyc
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this)

{
  __int64 _Var1;
  
  _Var1 = showmanyc(this);
  return _Var1;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::sync @ 0068d63a */

int __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::sync
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this)

{
  int iVar1;
  
  iVar1 = sync(this);
  return iVar1;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::uflow @ 0068d640 */

ushort __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::uflow
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this)

{
  ushort uVar1;
  
  uVar1 = uflow(this);
  return uVar1;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::xsgetn @ 0068d646 */

__int64 __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::xsgetn
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this,wchar_t *param_1,
          __int64 param_2)

{
  __int64 _Var1;
  
  _Var1 = xsgetn(this,param_1,param_2);
  return _Var1;
}




/* MSVCP110.DLL::std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::xsputn @ 0068d64c */

__int64 __thiscall
std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::xsputn
          (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *this,wchar_t *param_1,
          __int64 param_2)

{
  __int64 _Var1;
  
  _Var1 = xsputn(this,param_1,param_2);
  return _Var1;
}




/* MSVCP110.DLL::std::basic_ios<char,std::char_traits<char>_>::_Add_vtordisp1 @ 0068d65c */

void __thiscall
std::basic_ios<char,std::char_traits<char>_>::_Add_vtordisp1
          (basic_ios<char,std::char_traits<char>_> *this)

{
  _Add_vtordisp1(this);
  return;
}




/* MSVCR110.DLL::purecall @ 0068d662 */

void __cdecl purecall(void)

{
  purecall();
  return;
}




/* MSVCR110.DLL::operator_new @ 0068d668 */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}




/* MSVCR110.DLL::operator_delete @ 0068d66e */

void __cdecl operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}




/* Global::__onexit @ 0068d6b0 */

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2012 Release */

_onexit_t __onexit(_onexit_t param_1)

{
  _onexit_t p_Var1;
  PVOID pvVar2;
  PVOID *ppvVar3;
  PVOID *ppvVar4;
  PVOID local_24;
  PVOID local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00760690;
  uStack_c = 0x68d6bc;
  local_20[0] = DecodePointer(DAT_0076e2f4);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_0076e2f4);
    local_24 = DecodePointer(DAT_0076e2f0);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_0076e2f4 = EncodePointer(local_20[0]);
    DAT_0076e2f0 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    lib_fn_68d74c();
  }
  return p_Var1;
}




/* Global::lib_fn_68d74c @ 0068d74c */

void lib_fn_68d74c(void)

{
  _unlock(8);
  return;
}




/* Global::_atexit @ 0068d755 */

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  int iVar1;
  
  iVar1 = __onexit(param_1);
  return (iVar1 != 0) - 1;
}




/* MSVCR110.DLL::memmove @ 0068d76a */

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}




/* MSVCR110.DLL::fclose @ 0068d770 */

int __cdecl fclose(FILE *_File)

{
  int iVar1;
  
  iVar1 = fclose(_File);
  return iVar1;
}




/* Global::__security_check_cookie @ 0068d788 */

/* Library Function - Single Match
    @eh_security_check_cookie_4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_0076aa78) {
    return;
  }
  ___report_gsfailure();
}




/* MSVCR110.DLL::_CxxThrowException @ 0068d798 */

void _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}




/* MSVCR110.DLL::libm_sse2_cos_precise @ 0068d7a4 */

void __cdecl libm_sse2_cos_precise(void)

{
  libm_sse2_cos_precise();
  return;
}




/* MSVCR110.DLL::memcpy @ 0068d7aa */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}




/* MSVCR110.DLL::memset @ 0068d7b0 */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}




/* type_info::vfunc_0 @ 0068d7b6 */

void type_info::vfunc_0(byte param_1)

{
  type_info *in_ECX;
  
  if ((param_1 & 2) == 0) {
    type_info::~type_info(in_ECX);
    if ((param_1 & 1) != 0) {
      operator_delete(in_ECX);
    }
  }
  else {
    _eh_vector_destructor_iterator_(in_ECX,0xc,*(int *)(in_ECX + -4),type_info::~type_info);
    if ((param_1 & 1) != 0) {
      operator_delete(in_ECX + -4);
    }
  }
  return;
}




/* Global::__ArrayUnwind @ 0068d86f */

/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffc8;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffc8);
  }
  return;
}




/* MSVCR110.DLL::operator_delete_array @ 0068d8ce */

void __cdecl operator_delete__(void *param_1)

{
  operator_delete__(param_1);
  return;
}




/* MSVCR110.DLL::libm_sse2_pow_precise @ 0068d8d4 */

void __cdecl libm_sse2_pow_precise(void)

{
  libm_sse2_pow_precise();
  return;
}




/* Global::__alloca_probe @ 0068d8e0 */

/* Library Function - Single Match
    __chkstk
   
   Library: Visual Studio */

void __alloca_probe(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)((int)&stack0x00000000 - (int)in_EAX & ~-(uint)(&stack0x00000000 < in_EAX))
  ;
  for (puVar1 = (undefined4 *)((uint)auStack_4 & 0xfffff000); puVar2 < puVar1;
      puVar1 = puVar1 + -0x400) {
  }
  *puVar2 = unaff_retaddr;
  return;
}




/* MSVCR110.DLL::libm_sse2_asin_precise @ 0068d9bc */

void __cdecl libm_sse2_asin_precise(void)

{
  libm_sse2_asin_precise();
  return;
}




/* MSVCR110.DLL::libm_sse2_sin_precise @ 0068d9c2 */

void __cdecl libm_sse2_sin_precise(void)

{
  libm_sse2_sin_precise();
  return;
}




/* MSVCR110.DLL::libm_sse2_sqrt_precise @ 0068d9c8 */

void __cdecl libm_sse2_sqrt_precise(void)

{
  libm_sse2_sqrt_precise();
  return;
}




/* MSVCR110.DLL::libm_sse2_tan_precise @ 0068d9ce */

void __cdecl libm_sse2_tan_precise(void)

{
  libm_sse2_tan_precise();
  return;
}




/* Global::__alldiv @ 0068d9e0 */

/* Library Function - Single Match
    __alldiv
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}




/* Global::__allmul @ 0068da90 */

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}




/* MSVCR110.DLL::__RTDynamicCast @ 0068db2c */

void __RTDynamicCast(void)

{
  __RTDynamicCast();
  return;
}




/* MSVCR110.DLL::libm_sse2_acos_precise @ 0068db32 */

void __cdecl libm_sse2_acos_precise(void)

{
  libm_sse2_acos_precise();
  return;
}




/* MSVCR110.DLL::fread @ 0068db38 */

size_t __cdecl fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  sVar1 = fread(_DstBuf,_ElementSize,_Count,_File);
  return sVar1;
}




/* MSVCR110.DLL::ftell @ 0068db3e */

long __cdecl ftell(FILE *_File)

{
  long lVar1;
  
  lVar1 = ftell(_File);
  return lVar1;
}




/* MSVCR110.DLL::free_0068db44 @ 0068db44 */

void __cdecl free(void *_Memory)

{
  free(_Memory);
  return;
}




/* MSVCR110.DLL::malloc @ 0068db4a */

void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = malloc(_Size);
  return pvVar1;
}




/* MSVCR110.DLL::fopen @ 0068db50 */

FILE * __cdecl fopen(char *_Filename,char *_Mode)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(_Filename,_Mode);
  return pFVar1;
}




/* MSVCR110.DLL::fseek @ 0068db56 */

int __cdecl fseek(FILE *_File,long _Offset,int _Origin)

{
  int iVar1;
  
  iVar1 = fseek(_File,_Offset,_Origin);
  return iVar1;
}




/* MSVCR110.DLL::sprintf @ 0068db5c */

int __cdecl sprintf(char *_Dest,char *_Format,...)

{
  int iVar1;
  
  iVar1 = sprintf(_Dest,_Format);
  return iVar1;
}




/* MSVCR110.DLL::longjmp @ 0068db62 */

void __cdecl longjmp(int *_Buf,int _Value)

{
  longjmp(_Buf,_Value);
  return;
}




/* MSVCR110.DLL::setjmp3 @ 0068db68 */

void __cdecl setjmp3(void)

{
  setjmp3();
  return;
}




/* Global::___raise_securityfailure @ 0068db6e */

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_0076e27c = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_0076e27c == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}




/* Global::___report_gsfailure @ 0068dbab */

/* Library Function - Single Match
    ___report_gsfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_gsfailure(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  longlong lVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  lVar9 = (ulonglong)extraout_EDX << 0x20;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    lVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_0076e058 = (undefined4)((ulonglong)lVar9 >> 0x20);
  _DAT_0076e060 = (undefined4)lVar9;
  _DAT_0076e070 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_0076e074 = &stack0x00000004;
  _DAT_0076dfb0 = 0x10001;
  _DAT_0076df60 = 0xc0000409;
  _DAT_0076df64 = 1;
  _DAT_0076df70 = 1;
  DAT_0076df74 = 2;
  _DAT_0076df6c = unaff_retaddr;
  _DAT_0076e03c = in_GS;
  _DAT_0076e040 = in_FS;
  _DAT_0076e044 = in_ES;
  _DAT_0076e048 = in_DS;
  _DAT_0076e04c = unaff_EDI;
  _DAT_0076e050 = unaff_ESI;
  _DAT_0076e054 = unaff_EBX;
  _DAT_0076e05c = uVar3;
  _DAT_0076e064 = unaff_EBP;
  DAT_0076e068 = unaff_retaddr;
  _DAT_0076e06c = in_CS;
  _DAT_0076e078 = in_SS;
  ___raise_securityfailure(&PTR_DAT_00722648);
  return;
}




/* Global::___report_rangecheckfailure @ 0068dca4 */

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}




/* Global::___report_securityfailure @ 0068dcb0 */

/* Library Function - Single Match
    ___report_securityfailure
   
   Library: Visual Studio 2012 Release */

void ___report_securityfailure(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  longlong lVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  lVar9 = (ulonglong)extraout_EDX << 0x20;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    lVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_0076e058 = (undefined4)((ulonglong)lVar9 >> 0x20);
  _DAT_0076e060 = (undefined4)lVar9;
  _DAT_0076e070 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_0076e074 = &param_1;
  _DAT_0076df60 = 0xc0000409;
  _DAT_0076df64 = 1;
  _DAT_0076df70 = 1;
  DAT_0076df74 = param_1;
  _DAT_0076df6c = unaff_retaddr;
  _DAT_0076e03c = in_GS;
  _DAT_0076e040 = in_FS;
  _DAT_0076e044 = in_ES;
  _DAT_0076e048 = in_DS;
  _DAT_0076e04c = unaff_EDI;
  _DAT_0076e050 = unaff_ESI;
  _DAT_0076e054 = unaff_EBX;
  _DAT_0076e05c = uVar3;
  _DAT_0076e064 = unaff_EBP;
  DAT_0076e068 = unaff_retaddr;
  _DAT_0076e06c = in_CS;
  _DAT_0076e078 = in_SS;
  ___raise_securityfailure(&PTR_DAT_00722648);
  return;
}




/* MSVCR110.DLL::floor @ 0068dd7e */

double __cdecl floor(double _X)

{
  double dVar1;
  
  dVar1 = floor(_X);
  return dVar1;
}




/* MSVCR110.DLL::realloc @ 0068dd84 */

void * __cdecl realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  
  pvVar1 = realloc(_Memory,_NewSize);
  return pvVar1;
}




/* MSVCR110.DLL::strncmp @ 0068dd8a */

int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  iVar1 = strncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}




/* Global::__alldvrm @ 0068dd90 */

/* Library Function - Single Match
    __alldvrm
   
   Library: Visual Studio */

undefined8 __alldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}




/* Global::__allrem @ 0068de70 */

/* Library Function - Single Match
    __allrem
   
   Library: Visual Studio */

undefined8 __allrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  bVar13 = (int)param_2 < 0;
  if (bVar13) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar12 - param_2;
  }
  uVar11 = (uint)bVar13;
  if ((int)param_4 < 0) {
    bVar13 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar13 - param_4;
  }
  uVar3 = param_1;
  uVar4 = param_3;
  uVar8 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar6 = 0;
    if ((int)(uVar11 - 1) < 0) goto LAB_0068df1d;
  }
  else {
    do {
      uVar10 = uVar9 >> 1;
      uVar4 = uVar4 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar8 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar8 = uVar7;
      uVar9 = uVar10;
    } while (uVar10 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar4;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar8 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar9 = uVar8 + uVar3;
    if (((CARRY4(uVar8,uVar3)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar4)))) {
      bVar13 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar9 = (uVar9 - param_4) - (uint)bVar13;
    }
    iVar5 = uVar4 - param_1;
    iVar6 = (uVar9 - param_2) - (uint)(uVar4 < param_1);
    if (-1 < (int)(uVar11 - 1)) goto LAB_0068df1d;
  }
  bVar13 = iVar5 != 0;
  iVar5 = -iVar5;
  iVar6 = -(uint)bVar13 - iVar6;
LAB_0068df1d:
  return CONCAT44(iVar6,iVar5);
}




/* Global::__allshl @ 0068df30 */

/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __allshl(void)

{
  uint in_EAX;
  byte in_CL;
  int in_EDX;
  
  if (0x3f < in_CL) {
    return 0;
  }
  if (in_CL < 0x20) {
    return CONCAT44(in_EDX << (in_CL & 0x1f) | in_EAX >> 0x20 - (in_CL & 0x1f),
                    in_EAX << (in_CL & 0x1f));
  }
  return (ulonglong)(in_EAX << (in_CL & 0x1f)) << 0x20;
}




/* Global::__aulldiv @ 0068df50 */

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}




/* Global::__aulldvrm @ 0068dfc0 */

/* Library Function - Single Match
    __aulldvrm
   
   Library: Visual Studio */

undefined8 __aulldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}




/* Global::__aullrem @ 0068e060 */

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}




/* MSVCR110.DLL::libm_sse2_exp_precise @ 0068e0d6 */

void __cdecl libm_sse2_exp_precise(void)

{
  libm_sse2_exp_precise();
  return;
}




/* Global::__allshr @ 0068e3a0 */

/* Library Function - Single Match
    __allshr
   
   Library: Visual Studio */

undefined8 __allshr(void)

{
  uint in_EAX;
  byte in_CL;
  int in_EDX;
  int iVar1;
  
  iVar1 = in_EDX >> 0x1f;
  if (0x3f < in_CL) {
    return CONCAT44(iVar1,iVar1);
  }
  if (in_CL < 0x20) {
    return CONCAT44(in_EDX >> (in_CL & 0x1f),
                    in_EAX >> (in_CL & 0x1f) | in_EDX << 0x20 - (in_CL & 0x1f));
  }
  return CONCAT44(iVar1,in_EDX >> (in_CL & 0x1f));
}




/* Global::__alloca_probe_16 @ 0068e3d0 */

/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}




/* Global::__alloca_probe_8 @ 0068e3e6 */

/* Library Function - Single Match
    __alloca_probe_8
   
   Library: Visual Studio */

uint __alloca_probe_8(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 7;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}




/* MSVCR110.DLL::qsort @ 0068e3fc */

void __cdecl
qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  qsort(_Base,_NumOfElements,_SizeOfElements,_PtFuncCompare);
  return;
}




/* MSVCR110.DLL::memchr @ 0068e402 */

void * __cdecl memchr(void *_Buf,int _Val,size_t _MaxCount)

{
  void *pvVar1;
  
  pvVar1 = memchr(_Buf,_Val,_MaxCount);
  return pvVar1;
}




/* MSVCR110.DLL::libm_sse2_log_precise @ 0068e408 */

void __cdecl libm_sse2_log_precise(void)

{
  libm_sse2_log_precise();
  return;
}




/* MSVCR110.DLL::std::exception::what @ 0068e40e */

char * __thiscall std::exception::what(exception *this)

{
  char *pcVar1;
  
  pcVar1 = what(this);
  return pcVar1;
}




/* MSVCR110.DLL::_lock @ 0068e414 */

void __cdecl _lock(int _File)

{
  _lock(_File);
  return;
}




/* MSVCR110.DLL::_unlock @ 0068e41a */

void __cdecl _unlock(int _File)

{
  _unlock(_File);
  return;
}




/* MSVCR110.DLL::__dllonexit @ 0068e420 */

void __dllonexit(void)

{
  __dllonexit();
  return;
}




/* Global::__SEH_prolog4 @ 0068e430 */

/* Library Function - Single Match
    __SEH_prolog4
   
   Library: Visual Studio */

void __SEH_prolog4(undefined4 param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  param_2 = -param_2;
  *(undefined4 *)((int)auStack_1c + param_2 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + param_2 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + param_2 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + param_2 + 4) = DAT_0076aa78 ^ (uint)&stack0x00000008;
  *(undefined4 *)((int)auStack_1c + param_2) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}




/* Global::__SEH_epilog4 @ 0068e475 */

/* Library Function - Single Match
    __SEH_epilog4
   
   Library: Visual Studio */

void __SEH_epilog4(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}




/* MSVCR110.DLL::type_info::~type_info @ 0068e4ac */

void __thiscall type_info::~type_info(type_info *this)

{
  ~type_info(this);
  return;
}




/* MSVCR110.DLL::terminate @ 0068e4b2 */

void __cdecl terminate(void)

{
  terminate();
  return;
}




/* MSVCR110.DLL::_crt_debugger_hook @ 0068e5f2 */

void __cdecl _crt_debugger_hook(int param_1)

{
  _crt_debugger_hook(param_1);
  return;
}




/* MSVCR110.DLL::__crtUnhandledException @ 0068e5f8 */

LONG __cdecl __crtUnhandledException(EXCEPTION_POINTERS *exceptionInfo)

{
  LONG LVar1;
  
  LVar1 = __crtUnhandledException(exceptionInfo);
  return LVar1;
}




/* MSVCR110.DLL::__crtTerminateProcess @ 0068e5fe */

void __cdecl __crtTerminateProcess(UINT uExitCode)

{
  __crtTerminateProcess(uExitCode);
  return;
}




/* MSVCR110.DLL::_amsg_exit @ 0068e65a */

void __cdecl _amsg_exit(int param_1)

{
  _amsg_exit(param_1);
  return;
}




/* Global::__FindPESection @ 0068e660 */

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2012 Release */

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14) + 0x18 + iVar1);
  if (*(ushort *)(pImageBase + iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}




/* Global::__IsNonwritableInCurrentImage @ 0068e6b0 */

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2012 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_0076aa78 ^ 0x760730;
  ExceptionList = &local_14;
  local_8 = 0;
  BVar1 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_00400000);
  if (BVar1 != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_00400000,(DWORD_PTR)(pTarget + -0x400000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      ExceptionList = local_14;
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}




/* Global::__ValidateImageBase @ 0068e770 */

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  uint uVar1;
  
  if (*(short *)pImageBase != 0x5a4d) {
    return 0;
  }
  uVar1 = 0;
  if (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550) {
    uVar1 = (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b)
    ;
  }
  return uVar1;
}




/* Global::___security_init_cookie @ 0068e7a1 */

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2012 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_18;
  _FILETIME local_10;
  uint local_8;
  
  local_10.dwLowDateTime = 0;
  local_10.dwHighDateTime = 0;
  if ((DAT_0076aa78 == 0xbb40e64e) || ((DAT_0076aa78 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_0076aa78 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_0076aa78 == 0xbb40e64e) {
      DAT_0076aa78 = 0xbb40e64f;
    }
    else if ((DAT_0076aa78 & 0xffff0000) == 0) {
      DAT_0076aa78 = DAT_0076aa78 | (DAT_0076aa78 | 0x4711) << 0x10;
    }
  }
  DAT_0076aa7c = ~DAT_0076aa78;
  return;
}




/* MSVCR110.DLL::initterm_e @ 0068e8a6 */

void __cdecl initterm_e(void)

{
  initterm_e();
  return;
}




/* MSVCR110.DLL::initterm @ 0068e8ac */

void __cdecl initterm(void)

{
  initterm();
  return;
}




/* MSVCR110.DLL::except_handler4_common @ 0068e8b2 */

void __cdecl except_handler4_common(void)

{
  except_handler4_common();
  return;
}




/* MSVCR110.DLL::__crtSetUnhandledExceptionFilter @ 0068e8b8 */

void __cdecl __crtSetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER exceptionFilter)

{
  __crtSetUnhandledExceptionFilter(exceptionFilter);
  return;
}




/* MSVCR110.DLL::_invoke_watson @ 0068e8be */

void __cdecl
_invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  _invoke_watson(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* MSVCR110.DLL::_controlfp_s @ 0068e8c4 */

errno_t __cdecl _controlfp_s(uint *_CurrentState,uint _NewValue,uint _Mask)

{
  errno_t eVar1;
  
  eVar1 = _controlfp_s(_CurrentState,_NewValue,_Mask);
  return eVar1;
}




/* IPHLPAPI.DLL::GetAdaptersInfo @ 0068e8ca */

void GetAdaptersInfo(void)

{
  GetAdaptersInfo();
  return;
}




/* Global::lib_fn_68f990 @ 0068f990 */

void lib_fn_68f990(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_0076aa78 ^ (uint)&local_18;
  uVar1 = param_3;
  if ((param_2 != 0) && (uVar1 = param_2, param_3 == 0)) {
    param_3 = param_2;
  }
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  if (param_3 == 0) {
    param_3 = 1;
  }
  if (0xfffe < uVar1) {
    uVar1 = 0xffff;
  }
  if (0xfffe < param_3) {
    param_3 = 0xffff;
  }
  local_10 = param_3 << 6;
  local_14 = uVar1 << 6;
  local_18 = 0;
  local_c = 0;
  local_8 = 0;
  FT_Request_Size_internal(param_1,&local_18);
  __security_check_cookie(local_4 ^ (uint)&local_18);
  return;
}




/* Global::thunk_FUN_006b3c40 @ 006b43e0 */

void thunk_FUN_006b3c40(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x4c) != 0) {
    lib_fn_691ee0(*(undefined4 *)(unaff_ESI + 0x48),unaff_ESI + 0x4c);
  }
  (**(code **)(unaff_ESI + 0x18))();
  return;
}




/* MSVCR110.DLL::free_006cc6b0 @ 006cc6b0 */

void __cdecl free(void *_Memory)

{
  free(_Memory);
  return;
}




/* Global::thunk_FUN_006cf090 @ 006cf0c0 */

void thunk_FUN_006cf090(undefined4 param_1,int param_2,int param_3)

{
  FT_Mem_QAlloc_Clear(param_1,param_2 * param_3,&param_2);
  return;
}




/* GLU32.DLL::gluNewTess @ 006cf7f6 */

void gluNewTess(void)

{
  gluNewTess();
  return;
}




/* GLU32.DLL::gluDeleteTess @ 006cf7fc */

void gluDeleteTess(void)

{
  gluDeleteTess();
  return;
}




/* GLU32.DLL::gluTessBeginPolygon @ 006cf802 */

void gluTessBeginPolygon(void)

{
  gluTessBeginPolygon();
  return;
}




/* GLU32.DLL::gluTessBeginContour @ 006cf808 */

void gluTessBeginContour(void)

{
  gluTessBeginContour();
  return;
}




/* GLU32.DLL::gluTessVertex @ 006cf80e */

void gluTessVertex(void)

{
  gluTessVertex();
  return;
}




/* GLU32.DLL::gluTessEndContour @ 006cf814 */

void gluTessEndContour(void)

{
  gluTessEndContour();
  return;
}




/* GLU32.DLL::gluTessEndPolygon @ 006cf81a */

void gluTessEndPolygon(void)

{
  gluTessEndPolygon();
  return;
}




/* GLU32.DLL::gluTessProperty @ 006cf820 */

void gluTessProperty(void)

{
  gluTessProperty();
  return;
}




/* GLU32.DLL::gluTessCallback @ 006cf826 */

void gluTessCallback(void)

{
  gluTessCallback();
  return;
}




/* KERNEL32.DLL::IsProcessorFeaturePresent @ 006cf8c2 */

BOOL IsProcessorFeaturePresent(DWORD ProcessorFeature)

{
  BOOL BVar1;
  
  BVar1 = IsProcessorFeaturePresent(ProcessorFeature);
  return BVar1;
}




/* MSVCR110.DLL::strncpy @ 006cf8c8 */

char * __cdecl strncpy(char *_Dest,char *_Source,size_t _Count)

{
  char *pcVar1;
  
  pcVar1 = strncpy(_Dest,_Source,_Count);
  return pcVar1;
}




/* MSVCR110.DLL::strrchr @ 006cf8ce */

char * __cdecl strrchr(char *_Str,int _Ch)

{
  char *pcVar1;
  
  pcVar1 = strrchr(_Str,_Ch);
  return pcVar1;
}




/* MSVCR110.DLL::atol @ 006cf8d4 */

long __cdecl atol(char *_Str)

{
  long lVar1;
  
  lVar1 = atol(_Str);
  return lVar1;
}




/* MSVCR110.DLL::strstr @ 006cf8da */

char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}




/* MSVCR110.DLL::libm_sse2_atan_precise @ 006e03a2 */

void __cdecl libm_sse2_atan_precise(void)

{
  libm_sse2_atan_precise();
  return;
}




/* Global::___common_srl @ 006e0b70 */

/* Library Function - Single Match
    ___common_srl
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined8 ___common_srl(uint param_1,int param_2,byte param_3)

{
  int iVar1;
  
  iVar1 = param_2 >> 0x1f;
  if (0x3f < param_3) {
    return CONCAT44(iVar1,iVar1);
  }
  if (param_3 < 0x20) {
    return CONCAT44(param_2 >> (param_3 & 0x1f),
                    param_1 >> (param_3 & 0x1f) | param_2 << 0x20 - (param_3 & 0x1f));
  }
  return CONCAT44(iVar1,param_2 >> (param_3 & 0x1f));
}




/* Global::___common_sll @ 006e0ba0 */

/* Library Function - Single Match
    ___common_sll
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

longlong ___common_sll(uint param_1,int param_2,byte param_3)

{
  if (0x3f < param_3) {
    return 0;
  }
  if (param_3 < 0x20) {
    return CONCAT44(param_2 << (param_3 & 0x1f) | param_1 >> 0x20 - (param_3 & 0x1f),
                    param_1 << (param_3 & 0x1f));
  }
  return (ulonglong)(param_1 << (param_3 & 0x1f)) << 0x20;
}




/* std::error_category::ctor_0 @ 006fb120 */

void std::error_category::ctor_0(void)

{
  PTR_vftable_00765064 = (undefined *)vftable;
  return;
}




/* std::error_category::ctor_1 @ 006fb130 */

void std::error_category::ctor_1(void)

{
  PTR_vftable_00765068 = (undefined *)vftable;
  return;
}




/* std::error_category::ctor_2 @ 006fb140 */

void std::error_category::ctor_2(void)

{
  PTR_vftable_0076506c = (undefined *)vftable;
  return;
}




