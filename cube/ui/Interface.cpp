// Interface (ui) — cube. 10 functions. Bodies = Ghidra pseudo-C.
#include "Interface.h"

/* [AUDIT] proposed: std::wstring::_Tidy  (confidence: high)
 * purpose: free heap wstring buffer if cap>7, reset to SSO
 * vars: in_ECX=this
 */
/* Global::std_wstring_Tidy @ 0040f4a0 */

void std_wstring_Tidy(char param_1,int param_2)

{
  void *_Src;
  undefined4 *in_ECX;
  
  if ((param_1 != '\0') && (7 < (uint)in_ECX[5])) {
    _Src = (void *)*in_ECX;
    if (param_2 != 0) {
      memcpy(in_ECX,_Src,param_2 * 2);
    }
    operator_delete(_Src);
  }
  in_ECX[4] = param_2;
  in_ECX[5] = 7;
  *(undefined2 *)((int)in_ECX + param_2 * 2) = 0;
  return;
}




/* cube::Interface::drawCharacterCreation @ 00425450 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::Interface::drawCharacterCreation.
 * Via GC *(this+0x160): anim timer +0x118c += (*(this+4)+0xe4 dt)*0.0075, zeroes +0x5c/+0x68/+0x124/+0x128, GameController_updateWidgetLayout(), vec3_lerp camera +0x40/+0x34; strings 'New character'/'Specialization:' via AdaptionWidget. stringstream vftable is on a local stack scratch, not this.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void cube::Interface::drawCharacterCreation(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  basic_ostream<wchar_t,std::char_traits<wchar_t>_> *this;
  undefined4 *****pppppuVar8;
  int in_ECX;
  int iVar9;
  undefined8 *puVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  void **ppvVar14;
  float *pfVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  undefined **ppuVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  void *pvVar23;
  float fVar24;
  float fVar25;
  undefined **local_8cc;
  float fStack_8c0;
  undefined *puStack_8bc;
  float local_8b8;
  undefined **local_8b4;
  float local_8b0;
  float fStack_8ac;
  undefined4 *local_8a8;
  float local_8a4;
  float local_8a0;
  float fStack_89c;
  int iStack_898;
  int iStack_894;
  int iStack_890;
  undefined4 uStack_87c;
  uint uStack_878;
  undefined1 auStack_870 [12];
  basic_ios<wchar_t,std::char_traits<wchar_t>_> abStack_864 [144];
  int iStack_7d4;
  undefined **local_7d0 [4];
  undefined *local_7c0 [2];
  undefined **local_7b8 [14];
  undefined4 local_780;
  undefined4 local_77c;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_768 [60];
  float fStack_72c;
  float fStack_728;
  float fStack_724;
  float fStack_720;
  float fStack_71c;
  float fStack_718;
  float fStack_714;
  float fStack_710;
  float fStack_70c;
  float fStack_708;
  float fStack_704;
  float fStack_700;
  float fStack_6fc;
  float fStack_6f8;
  float fStack_6f4;
  float fStack_6f0;
  float fStack_6ec;
  float fStack_6e8;
  float afStack_6e4 [4];
  undefined4 ****ppppuStack_6d4;
  float fStack_6d0;
  float fStack_6cc;
  float fStack_6c8;
  float fStack_6c4;
  float fStack_6c0;
  float fStack_6bc;
  float fStack_6b8;
  float fStack_6b4;
  float fStack_6b0;
  float fStack_6ac;
  float fStack_6a8;
  undefined4 uStack_6a0;
  undefined4 uStack_69c;
  undefined4 uStack_698;
  undefined4 uStack_67c;
  undefined4 uStack_678;
  undefined4 uStack_674;
  undefined4 uStack_670;
  undefined4 uStack_664;
  undefined4 local_660;
  undefined4 local_65c;
  undefined4 local_658;
  undefined4 local_654;
  undefined4 local_650;
  undefined4 local_64c;
  undefined4 uStack_644;
  undefined4 uStack_640;
  float local_63c;
  float local_638;
  float local_634;
  undefined4 local_624;
  undefined4 local_620;
  undefined4 local_61c;
  undefined4 uStack_618;
  undefined4 uStack_608;
  undefined4 uStack_604;
  undefined4 uStack_600;
  undefined4 uStack_5fc;
  undefined4 uStack_5f8;
  undefined4 uStack_5f4;
  undefined4 uStack_5f0;
  undefined4 uStack_5ec;
  undefined4 uStack_5e8;
  undefined4 uStack_5d4;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  undefined4 uStack_5c8;
  undefined4 uStack_5b4;
  undefined4 uStack_5b0;
  undefined4 uStack_5ac;
  undefined4 uStack_5a8;
  undefined4 uStack_598;
  undefined4 uStack_594;
  undefined4 uStack_590;
  undefined4 uStack_58c;
  undefined4 uStack_588;
  undefined4 uStack_578;
  undefined4 uStack_574;
  undefined4 uStack_570;
  undefined4 uStack_56c;
  undefined4 uStack_558;
  undefined4 uStack_554;
  undefined4 uStack_550;
  undefined4 uStack_54c;
  undefined4 uStack_538;
  undefined4 uStack_534;
  undefined4 uStack_530;
  undefined4 uStack_52c;
  undefined4 uStack_528;
  undefined4 uStack_524;
  undefined4 uStack_520;
  undefined4 uStack_51c;
  undefined4 uStack_518;
  undefined4 uStack_514;
  undefined4 uStack_510;
  undefined4 uStack_50c;
  undefined4 uStack_508;
  undefined4 uStack_4f8;
  undefined4 uStack_4f4;
  undefined4 uStack_4f0;
  undefined4 uStack_4ec;
  undefined4 uStack_4e8;
  undefined4 uStack_4d8;
  undefined4 uStack_4d4;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined4 uStack_4c4;
  undefined4 uStack_4c0;
  undefined4 uStack_4bc;
  undefined4 uStack_4b8;
  undefined4 uStack_4b4;
  undefined4 uStack_4b0;
  undefined4 uStack_4ac;
  undefined4 uStack_4a8;
  undefined4 uStack_498;
  void *pvStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  uint uStack_480;
  undefined4 ****ppppuStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  uint uStack_468;
  undefined4 uStack_464;
  undefined4 uStack_458;
  undefined4 uStack_454;
  uint uStack_450;
  undefined4 uStack_44c;
  undefined4 uStack_43c;
  uint uStack_438;
  float afStack_3f4 [6];
  undefined4 uStack_3dc;
  undefined4 uStack_3d8;
  undefined4 uStack_3d4;
  undefined4 uStack_3d0;
  undefined4 uStack_3cc;
  undefined4 uStack_3c8;
  undefined4 uStack_3c4;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 uStack_3b8;
  void *apvStack_3b4 [5];
  uint uStack_3a0;
  undefined4 uStack_39c;
  undefined4 uStack_398;
  undefined4 uStack_394;
  undefined4 uStack_390;
  undefined4 uStack_38c;
  undefined4 uStack_388;
  void *pvStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  undefined4 uStack_374;
  uint uStack_370;
  void *pvStack_350;
  undefined4 uStack_340;
  uint uStack_33c;
  void *pvStack_324;
  void *pvStack_320;
  undefined4 uStack_314;
  uint uStack_310;
  void *pvStack_30c;
  void *pvStack_308;
  undefined4 uStack_2fc;
  uint uStack_2f8;
  void *pvStack_2f4;
  void *pvStack_2f0;
  undefined4 uStack_2e4;
  uint uStack_2e0;
  uint uStack_2dc;
  void *apvStack_2b4 [5];
  uint uStack_2a0;
  double local_290;
  double local_288;
  void *apvStack_280 [5];
  uint uStack_26c;
  void *pvStack_254;
  void *apvStack_250 [4];
  uint uStack_240;
  uint uStack_23c;
  void *apvStack_238 [5];
  uint uStack_224;
  void *apvStack_220 [5];
  uint uStack_20c;
  undefined1 local_1f0 [8];
  double local_1e8;
  undefined8 auStack_12c [26];
  undefined4 uStack_58;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_006e1e08;
  local_14 = ExceptionList;
  local_1c = DAT_0076aa78 ^ (uint)&fStack_8c0;
  local_8cc = (undefined **)(DAT_0076aa78 ^ (uint)&stack0xfffff738);
  ExceptionList = &local_14;
  local_8a4 = 0.0;
  if (*(int *)(in_ECX + 0x160) == 0) {
    fVar16 = (float)Widget_measureGuarded();
    local_8a4 = (float)fVar16;
    fVar17 = local_8a4 * 0.5;
    local_7d0[0] = &PTR_006fcd00;
    local_7c0[0] = &DAT_006fcd08;
    std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,std::char_traits<wchar_t>_>(local_768);
    local_c = 0;
    local_8a4 = 1.4013e-45;
    std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
    basic_iostream<wchar_t,std::char_traits<wchar_t>_>
              ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_7d0,
               (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_7b8);
    local_c = 1;
    *(undefined ***)((int)local_7d0 + (int)local_7d0[0][1]) =
         basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
    *(undefined **)((int)&iStack_7d4 + (int)local_7d0[0][1]) = local_7d0[0][1] + -0x68;
    std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
    basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
              ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_7b8);
    local_7b8[0] = vftable;
    local_780 = 0;
    local_77c = 0;
    local_c = 3;
    wostream_insertWide(local_7c0);
    u16string_assignCStr();
    local_c._0_1_ = 4;
    uVar3 = u16_ostrstream_str_wrap();
    local_c._0_1_ = 5;
    uStack_608 = 0;
    uStack_604 = 0;
    uStack_600 = 0;
    uStack_5fc = 0;
    uStack_4d8 = 0;
    uStack_4d4 = 0;
    uStack_4d0 = 0;
    uStack_4cc = 0x3f800000;
    uStack_498 = 0x3f800000;
    pvStack_494 = (void *)0x3f800000;
    uStack_490 = 0x3f800000;
    uStack_48c = 0x3f800000;
    AdaptionWidget_draw_text_locked(apvStack_238,uVar3,0,0x40000000,(float)(int)fVar17,0x41f00000,0x41600000,0x40400000
                 ,&uStack_498,&uStack_4d8,&uStack_608,5,0x43340000);
    if ((void *)0x7 < pvStack_30c) {
      operator_delete(pvStack_320);
    }
    pvStack_30c = (void *)0x7;
    uStack_310 = 0;
    pvStack_320 = (void *)((uint)pvStack_320 & 0xffff0000);
    local_c._0_1_ = 3;
    if (7 < uStack_224) {
      operator_delete(apvStack_238[0]);
    }
    u16string_assignCStr();
    local_c._0_1_ = 6;
    uVar3 = u16_ostrstream_str_wrap();
    uStack_478 = 0;
    uStack_474 = 0;
    uStack_470 = 0;
    uStack_46c = 0;
    uStack_458 = 0;
    uStack_454 = 0;
    uStack_450 = 0;
    uStack_44c = (void *)0x0;
    uStack_528 = 0x3f800000;
    uStack_524 = 0x3f800000;
    uStack_520 = 0x3f800000;
    uStack_51c = 0x3f800000;
    local_c = CONCAT31(local_c._1_3_,7);
    AdaptionWidget_draw_text_locked(apvStack_280,uVar3,0,0x40000000,(float)(int)fVar17,0x41f00000,0x41600000,0,
                 &uStack_528,&uStack_458,&uStack_478,5,0x43340000);
    if (7 < uStack_33c) {
      operator_delete(pvStack_350);
    }
    uStack_33c = 7;
    uStack_340 = 0;
    pvStack_350 = (void *)((uint)pvStack_350 & 0xffff0000);
    if (7 < uStack_26c) {
      operator_delete(apvStack_280[0]);
    }
    goto LAB_004277eb;
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 0x128) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 300) = 0;
  *(undefined2 *)(*(int *)(in_ECX + 0x160) + 0x124) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 0x5c) = 0;
  *(float *)(*(int *)(in_ECX + 0x160) + 0x118c) =
       (float)*(int *)(*(int *)(in_ECX + 4) + 0xe4) * 0.0075 +
       *(float *)(*(int *)(in_ECX + 0x160) + 0x118c);
  *(undefined1 *)(*(int *)(in_ECX + 0x160) + 0x68) = 0;
  cVar2 = GameController_updateWidgetLayout();
  if (cVar2 == '\0') {
    iVar4 = *(int *)(*(int *)(in_ECX + 4) + 0xe4);
    ppuVar19 = (undefined **)0x0;
    iVar12 = 0;
    local_8b4 = (undefined **)0x0;
    if (7 < iVar4) {
      iVar9 = (iVar4 - 8U >> 3) + 1;
      iVar12 = iVar9 * 8;
      do {
        fVar17 = (1.0 - (float)ppuVar19) * 0.01 + (float)ppuVar19;
        fVar17 = (1.0 - fVar17) * 0.01 + fVar17;
        fVar17 = (1.0 - fVar17) * 0.01 + fVar17;
        fVar17 = (1.0 - fVar17) * 0.01 + fVar17;
        fVar17 = (1.0 - fVar17) * 0.01 + fVar17;
        fVar17 = (1.0 - fVar17) * 0.01 + fVar17;
        fVar17 = (1.0 - fVar17) * 0.01 + fVar17;
        ppuVar19 = (undefined **)((1.0 - fVar17) * 0.01 + fVar17);
        iVar9 = iVar9 + -1;
        local_8b4 = ppuVar19;
      } while (iVar9 != 0);
    }
    if (iVar12 < iVar4) {
      iVar4 = iVar4 - iVar12;
      do {
        local_8b4 = (undefined **)((float)local_8b4 + (1.0 - (float)local_8b4) * 0.01);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar12 = *(int *)(in_ECX + 0x160);
    local_8b0 = *(float *)(iVar12 + 0x137c);
    local_8a0 = (local_8b0 / 180.0) * 3.1415927;
    dVar18 = libm_sse2_sin_precise((double)local_8a0);
    local_8b8 = (float)dVar18;
    dVar18 = libm_sse2_cos_precise((double)local_8a0);
    local_290 = (double)(float)dVar18;
    local_288 = (double)local_8b8;
    local_8a0 = 0.0;
    dVar18 = libm_sse2_sin_precise(0.0);
    local_8a8 = (undefined4 *)(float)dVar18;
    dVar18 = libm_sse2_cos_precise((double)local_8a0);
    local_1f0 = (undefined1  [8])(double)(float)dVar18;
    local_1e8 = (double)(float)local_8a8;
    fVar22 = (float)(local_1e8 * local_290 - (double)local_1f0 * (double)local_8b8);
    fVar17 = 1.0;
    if ((1.0 < fVar22) || (fVar17 = -1.0, fVar22 < -1.0)) {
      fVar22 = fVar17;
    }
    dVar18 = libm_sse2_asin_precise((double)fVar22);
    *(float *)(iVar12 + 0x137c) =
         local_8b0 + (float)dVar18 * (((float)local_8b4 * 180.0) / 3.1415927);
    iVar12 = 0;
    iVar4 = *(int *)(*(int *)(in_ECX + 4) + 0xe4);
    pfVar5 = (float *)(*(int *)(in_ECX + 0x160) + 0x1188);
    if (3 < iVar4) {
      iVar9 = (iVar4 - 4U >> 2) + 1;
      iVar12 = iVar9 * 4;
      do {
        fVar17 = (0.0 - *pfVar5) * 0.01 + *pfVar5;
        fVar17 = (0.0 - fVar17) * 0.01 + fVar17;
        fVar17 = (0.0 - fVar17) * 0.01 + fVar17;
        *pfVar5 = (0.0 - fVar17) * 0.01 + fVar17;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    if (iVar12 < iVar4) {
      iVar4 = iVar4 - iVar12;
      do {
        *pfVar5 = (0.0 - *pfVar5) * 0.01 + *pfVar5;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    local_63c = 0.0;
    local_638 = 0.0;
    local_634 = 0.0;
    vec3_lerp(*(int *)(in_ECX + 0x160) + 0x40,&local_63c,
                 *(undefined4 *)(*(int *)(in_ECX + 4) + 0xe4));
    local_624 = 0;
    uVar3 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0xe4);
    local_620 = 0;
    local_61c = 0;
    puVar6 = &local_624;
  }
  else {
    local_660 = 0;
    local_65c = 0x41000000;
    local_658 = 0;
    *(float *)(*(int *)(in_ECX + 0x160) + 0x137c) =
         *(float *)(*(int *)(in_ECX + 0x160) + 0x137c) -
         (float)*(int *)(*(int *)(in_ECX + 4) + 0xe4) * 0.05;
    *(undefined4 *)(*(int *)(in_ECX + 0x160) + 0x1188) = 0x3e4ccccd;
    vec3_lerp(*(int *)(in_ECX + 0x160) + 0x40,&local_660,
                 *(undefined4 *)(*(int *)(in_ECX + 4) + 0xe4));
    local_654 = 0;
    uVar3 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0xe4);
    local_650 = 0x40400000;
    local_64c = 0;
    puVar6 = &local_654;
  }
  vec3_lerp(*(int *)(in_ECX + 0x160) + 0x34,puVar6,uVar3);
  piVar1 = *(int **)(*(int *)(in_ECX + 0x164) + 0x134);
  (**(code **)(*piVar1 + 0xe4))(piVar1,7);
  uStack_67c = 0;
  uStack_678 = 0;
  uStack_674 = 0;
  uStack_670 = 0;
  uStack_6a0 = 0;
  uStack_69c = 0;
  uStack_698 = 0;
  puVar7 = (undefined8 *)(local_1f0 + 4);
  puVar10 = auStack_12c;
  iVar12 = 0x10;
  do {
    *puVar10 = 0;
    *puVar7 = 0;
    puVar10[1] = 0;
    *(undefined4 *)(puVar7 + 1) = 0;
    puVar10 = puVar10 + 2;
    puVar7 = (undefined8 *)((int)puVar7 + 0xc);
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  render_bindNodeTransformA();
  render_uploadBoneMatrices(auStack_12c,local_1f0 + 4);
  render_setVec3Uniform5c(0x3f800000);
  render_setVec3Uniform58(0);
  uStack_4c4 = 0x3f800000;
  uStack_4c0 = 0x3f800000;
  uStack_4bc = 0x3f800000;
  uStack_4b8 = 0x3f800000;
  render_setUniform30(&uStack_4c4);
  local_654 = 0;
  local_650 = 0;
  local_64c = 0;
  render_setVec3Uniform70(&local_654);
  uStack_5f4 = 0x3ecccccd;
  uStack_5f0 = 0x3ecccccd;
  uStack_5ec = 0x3ecccccd;
  uStack_5e8 = 0x3f800000;
  dVar18 = libm_sse2_sqrt_precise(3.5);
  local_638 = 1.0 / (float)dVar18;
  local_63c = local_638 * 0.5;
  local_634 = local_638 * 1.5;
  pvStack_494 = (void *)0x3e4ccccd;
  uStack_490 = 0x3e99999a;
  uStack_48c = 0x3ecccccd;
  uStack_488 = 0x3f800000;
  uStack_5d4 = 0x3f800000;
  uStack_5d0 = 0x3f800000;
  uStack_5cc = 0x3f800000;
  uStack_5c8 = 0x3f800000;
  render_setLightDirUniform(&uStack_5d4,&pvStack_494,&local_63c,&uStack_5f4);
  render_setInvUniform60(0x4e6e6b28);
  iVar12 = *(int *)(in_ECX + 0x148);
  iVar4 = *(int *)(*(int *)(iVar12 + 0x38) + 0x170);
  iVar9 = *(int *)(*(int *)(iVar12 + 0x38) + 0x19c);
  fVar17 = *(float *)(iVar9 + 4 + iVar4 * 8);
  fVar22 = *(float *)(iVar9 + iVar4 * 8);
  fStack_6ec = 1.0 / (fVar22 * *(float *)(iVar12 + 0x54) + fVar17 * *(float *)(iVar12 + 100) +
                     *(float *)(iVar12 + 0x84));
  fStack_6e8 = fStack_6ec *
               (fVar17 * *(float *)(iVar12 + 0x5c) + fVar22 * *(float *)(iVar12 + 0x4c) +
               *(float *)(iVar12 + 0x7c));
  fStack_6ec = fStack_6ec *
               (fVar17 * *(float *)(iVar12 + 0x58) + fVar22 * *(float *)(iVar12 + 0x48) +
               *(float *)(iVar12 + 0x78));
  fStack_89c = 0.0;
  local_8a0 = 0.0;
  fStack_6fc = 0.0;
  fStack_6f8 = 0.0;
  fStack_6f4 = 17.0;
  fStack_6f0 = 1.0;
  dVar18 = libm_sse2_cos_precise(-1.6580628156661987);
  puStack_8bc = (undefined *)(float)dVar18;
  dVar18 = libm_sse2_sin_precise(-1.6580628156661987);
  fVar24 = (float)dVar18;
  fVar22 = fVar24 * 0.0;
  fVar17 = (float)puStack_8bc * 0.0;
  fStack_70c = fVar17 - fVar22;
  fStack_8ac = (float)puStack_8bc + fVar22;
  fStack_704 = (float)puStack_8bc - fVar22;
  fStack_708 = fVar17 - fVar24;
  puStack_8bc = (undefined *)(fVar22 + fVar17);
  fStack_700 = fStack_70c;
  dVar18 = libm_sse2_cos_precise(0.7853981852531433);
  local_8b4 = (undefined **)(float)dVar18;
  dVar18 = libm_sse2_sin_precise(0.7853981852531433);
  fVar22 = (float)dVar18;
  fStack_720 = (float)local_8b4 * 0.0;
  fStack_72c = fVar22 * (float)puStack_8bc + (float)local_8b4;
  fStack_710 = fVar22 * 0.0;
  iVar12 = *(int *)(in_ECX + 0x160);
  fStack_71c = (float)local_8b4 * (float)puStack_8bc - fVar22;
  fStack_728 = fVar22 * fStack_8ac + fStack_720;
  fStack_718 = (float)local_8b4 * fStack_8ac - fStack_710;
  fStack_724 = fVar22 * (fVar24 + fVar17) + fStack_720;
  fStack_720 = fVar22 * (float)puStack_8bc + fStack_720;
  fStack_714 = (float)local_8b4 * (fVar24 + fVar17) - fStack_710;
  fStack_710 = (float)local_8b4 * (float)puStack_8bc - fStack_710;
  local_8b8 = (float)-(*(int *)(iVar12 + 0x24) + (uint)(*(int *)(iVar12 + 0x20) != 0));
  puStack_8bc = (undefined *)(float)CONCAT44(local_8b8,-*(int *)(iVar12 + 0x20));
  fVar17 = (float)puStack_8bc * 1.5258789e-05;
  fStack_6fc = fStack_71c * 0.0 + fStack_72c * 0.0 + fVar17 * fStack_70c + fStack_6fc;
  fStack_6f8 = fStack_718 * 0.0 + fStack_728 * 0.0 + fVar17 * fStack_708 + fStack_6f8;
  iVar4 = *(int *)(in_ECX + 4);
  fStack_6f4 = fStack_714 * 0.0 + fStack_724 * 0.0 + fVar17 * fStack_704 + fStack_6f4;
  fStack_6f0 = fStack_710 * 0.0 + fStack_720 * 0.0 + fVar17 * fStack_700 + fStack_6f0;
  local_8b4 = (undefined **)iVar12;
  dVar18 = libm_sse2_tan_precise(0.39269909262657166);
  fVar25 = 1.0 / (float)dVar18;
  fStack_8c0 = -(fVar25 / ((float)*(int *)(iVar4 + 0x10c) / (float)*(int *)(iVar4 + 0x110)));
  afStack_3f4[0] = fStack_8c0;
  afStack_3f4[4] = 0.0;
  uStack_3d4 = 0;
  uStack_3c4 = 0;
  afStack_3f4[1] = 0.0;
  afStack_3f4[5] = fVar25;
  uStack_3d0 = 0;
  uStack_3c0 = 0;
  afStack_3f4[2] = 0.0;
  uStack_3dc = 0;
  uStack_3cc = 0x3f800347;
  uStack_3bc = 0xbdccd20b;
  afStack_3f4[3] = 0.0;
  uStack_3d8 = 0;
  uStack_3c8 = 0x3f800000;
  uStack_3b8 = 0;
  fVar24 = (((fStack_6ec + 100.0) - (float)*(int *)(iVar4 + 0x10c) * 0.5) /
           (float)*(int *)(iVar4 + 0x10c)) * 2.0;
  apvStack_3b4[0] = (void *)0x3f800000;
  apvStack_3b4[1] = (void *)0x0;
  apvStack_3b4[2] = (void *)0x0;
  apvStack_3b4[3] = (void *)0x0;
  apvStack_3b4[4] = (void *)0x0;
  uStack_3a0 = 0x3f800000;
  uStack_39c = 0;
  uStack_398 = 0;
  uStack_394 = 0;
  uStack_390 = 0;
  uStack_38c = 0x3f800000;
  uStack_388 = 0;
  fVar22 = (((fStack_6e8 + 110.0) - (float)*(int *)(iVar4 + 0x110) * 0.5) /
           (float)*(int *)(iVar4 + 0x110)) * -2.0;
  fVar20 = fVar24 * 0.0;
  iVar12 = 0x10;
  fVar17 = fVar22 * 0.0;
  fVar21 = fVar20 + fVar17;
  pvVar23 = (void *)(fVar24 + fVar17 + fStack_89c + 0.0);
  fStack_380 = fVar22 + fVar20 + fStack_89c + 0.0;
  pvStack_384 = pvVar23;
  fVar17 = (float)pvVar23 * 0.0;
  fStack_37c = fVar21 + 0.0 + 0.0;
  fStack_378 = fVar21 + fStack_89c + 1.0;
  ppvVar14 = apvStack_3b4;
  pfVar5 = afStack_6e4;
  while( true ) {
    if (iVar12 == 0) break;
    iVar12 = iVar12 + -1;
    *pfVar5 = (float)*ppvVar14;
    ppvVar14 = ppvVar14 + 1;
    pfVar5 = pfVar5 + 1;
  }
  afStack_6e4[0] = fStack_8c0 + fStack_89c + fStack_89c + fVar17;
  ppppuStack_6d4 = (undefined4 ****)(fVar25 * 0.0 + 0.0 + fStack_89c + fVar17);
  fStack_6c4 = local_8a0 + 0.0 + (float)pvVar23;
  fVar24 = afStack_6e4[1] * 0.0;
  fVar22 = fStack_6b0 * 0.0;
  fStack_6b4 = (local_8a0 - 0.0) + fVar17;
  afStack_6e4[1] = afStack_6e4[1] * fStack_8c0 + fStack_6d0 * 0.0 + fStack_6c0 * 0.0 + fVar22;
  fVar20 = fVar24 + fStack_6d0 * 0.0;
  fStack_6d0 = fVar25 * fStack_6d0 + fVar24 + fStack_6c0 * 0.0 + fVar22;
  fVar24 = fStack_6c0 * 0.10001;
  fStack_6c0 = fStack_6c0 * 1.0001 + fVar20 + fStack_6b0;
  fVar17 = fStack_6ac * 0.0;
  fStack_6b0 = (fVar20 - fVar24) + fVar22;
  fVar22 = afStack_6e4[2] * 0.0;
  fVar24 = fStack_6cc * 0.0 + fVar22;
  afStack_6e4[2] = afStack_6e4[2] * fStack_8c0 + fStack_6cc * 0.0 + fStack_6bc * 0.0 + fVar17;
  fStack_6cc = fVar25 * fStack_6cc + fVar22 + fStack_6bc * 0.0 + fVar17;
  fVar20 = fStack_6bc * 0.10001;
  fStack_6bc = fStack_6bc * 1.0001 + fVar24 + fStack_6ac;
  fVar22 = fStack_6a8 * 0.0;
  fStack_6ac = (fVar24 - fVar20) + fVar17;
  fVar17 = afStack_6e4[3] * 0.0;
  fVar24 = fStack_6c8 * 0.0 + fVar17;
  afStack_6e4[3] = afStack_6e4[3] * fStack_8c0 + fStack_6c8 * 0.0 + fStack_6b8 * 0.0 + fVar22;
  fStack_6c8 = fVar25 * fStack_6c8 + fVar17 + fStack_6b8 * 0.0 + fVar22;
  fVar17 = fStack_6b8 * 0.10001;
  fStack_6b8 = fStack_6b8 * 1.0001 + fVar24 + fStack_6a8;
  fStack_6a8 = (fVar24 - fVar17) + fVar22;
  pfVar5 = afStack_6e4;
  pfVar15 = afStack_3f4;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar15 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar15 = pfVar15 + 1;
  }
  fStack_8ac = (float)-*(int *)((int)local_8b4 + 0x18);
  local_8a8 = (undefined4 *)
              -(*(int *)((int)local_8b4 + 0x1c) + (uint)(*(int *)((int)local_8b4 + 0x18) != 0));
  iStack_894 = -*(int *)((int)local_8b4 + 0x10);
  iStack_890 = -(*(int *)((int)local_8b4 + 0x14) + (uint)(*(int *)((int)local_8b4 + 0x10) != 0));
  uStack_514 = 0x3f800000;
  uStack_510 = 0x3f800000;
  uStack_50c = 0x3f800000;
  uStack_508 = 0x3f800000;
  Creature_drawModel(*(undefined4 *)(*(int *)(iStack_898 + 0x164) + 0x800580),&fStack_72c,afStack_3f4,
               *(int *)(iStack_898 + 0x164) + 0x300,*(undefined4 *)(*(int *)(iStack_898 + 4) + 0xe4)
               ,&uStack_514,&iStack_894,&fStack_8ac,0,0);
  piVar1 = *(int **)(*(int *)(iStack_898 + 0x164) + 0x134);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,1);
  piVar1 = *(int **)(*(int *)(iStack_898 + 0x164) + 0x134);
  (**(code **)(*piVar1 + 0xe4))(piVar1,7,0);
  local_8cc = &PTR_006fcd00;
  puStack_8bc = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (abStack_864);
  uStack_58 = 8;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)&local_8cc,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&local_8b4);
  uStack_58 = 9;
  *(undefined ***)((int)&local_8cc + (int)local_8cc[1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)(&stack0xfffff730 + (int)local_8cc[1]) = local_8cc[1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&local_8b4);
  local_8b4 = vftable;
  uStack_87c = 0;
  uStack_878 = 0;
  uStack_58 = 0xb;
  pcVar13 = (char *)(*(int *)(iStack_898 + 0x160) + 0x1168);
  uStack_480 = 0xf;
  uStack_484 = 0;
  pvStack_494 = (void *)((uint)pvStack_494 & 0xffffff00);
  if (*pcVar13 == '\0') {
    iVar12 = 0;
  }
  else {
    pcVar11 = pcVar13;
    do {
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar2 != '\0');
    iVar12 = (int)pcVar11 - (*(int *)(iStack_898 + 0x160) + 0x1169);
  }
  string_assignPtrLen(pcVar13,iVar12);
  uStack_58._0_1_ = 0xc;
  uVar3 = copy_two_words(&pvStack_324,&pvStack_494);
  uStack_58._0_1_ = 0xd;
  wostream_insertU16string(&puStack_8bc,uVar3);
  if (7 < uStack_310) {
    operator_delete(pvStack_324);
  }
  uStack_310 = 7;
  uStack_314 = 0;
  pvStack_324 = (void *)((uint)pvStack_324 & 0xffff0000);
  uStack_58._0_1_ = 0xb;
  if (0xf < uStack_480) {
    operator_delete(pvStack_494);
  }
  uStack_450 = 7;
  uStack_454 = 0;
  uStack_464 = (void *)((uint)uStack_464._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  uStack_58._0_1_ = 0xe;
  uVar3 = u16_ostrstream_str_wrap(&pvStack_2f4);
  uStack_5f4 = 0;
  uStack_5f0 = 0;
  uStack_5ec = 0;
  uStack_5e8 = 0;
  uStack_4f4 = 0;
  uStack_4f0 = 0;
  uStack_4ec = 0;
  uStack_4e8 = 0x3f800000;
  uStack_5d4 = 0x3f800000;
  uStack_5d0 = 0x3f800000;
  uStack_5cc = 0x3f800000;
  uStack_5c8 = 0x3f800000;
  uStack_58._0_1_ = 0xf;
  AdaptionWidget_draw_text_locked(&uStack_464,uVar3,0,0x40000000,0x43480000,0x41f00000,0x41600000,0x40400000,
               &uStack_5d4,&uStack_4f4,&uStack_5f4,0x10,0x43340000,1);
  if (7 < uStack_2e0) {
    operator_delete(pvStack_2f4);
  }
  uStack_2e0 = 7;
  uStack_2e4 = 0;
  pvStack_2f4 = (void *)((uint)pvStack_2f4 & 0xffff0000);
  uStack_58._0_1_ = 0xb;
  if (7 < uStack_450) {
    operator_delete(uStack_464);
  }
  uStack_438 = 7;
  uStack_43c = 0;
  uStack_44c = (void *)((uint)uStack_44c._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  uStack_58._0_1_ = 0x10;
  uVar3 = u16_ostrstream_str_wrap(&pvStack_30c);
  uStack_534 = 0;
  uStack_530 = 0;
  uStack_52c = 0;
  uStack_528 = 0;
  uStack_5b4 = 0;
  uStack_5b0 = 0;
  uStack_5ac = 0;
  uStack_5a8 = 0;
  uStack_4b4 = 0x3e800000;
  uStack_4b0 = 0x3f800000;
  uStack_4ac = 0x3f800000;
  uStack_4a8 = 0x3f800000;
  uStack_58._0_1_ = 0x11;
  AdaptionWidget_draw_text_locked(&uStack_44c,uVar3,0,0x40000000,0x43480000,0x41f00000,0x41600000,0,&uStack_4b4,
               &uStack_5b4,&uStack_534,0x10,0x43340000,1);
  if (7 < uStack_2f8) {
    operator_delete(pvStack_30c);
  }
  uStack_2f8 = 7;
  uStack_2fc = 0;
  pvStack_30c = (void *)((uint)pvStack_30c & 0xffff0000);
  uStack_58._0_1_ = 0xb;
  if (7 < uStack_438) {
    operator_delete(uStack_44c);
  }
  fStack_6c0 = 9.80909e-45;
  fStack_6c4 = 0.0;
  ppppuStack_6d4 = (undefined4 ****)((uint)ppppuStack_6d4 & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  uStack_58._0_1_ = 0x12;
  if ((uStack_878 & 1) != 0) {
    operator_delete((void *)*local_8a8);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&local_8b4,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)&local_8b4,(wchar_t *)0x0,
             (wchar_t *)0x0);
  uStack_878 = uStack_878 & 0xfffffffe;
  pppppuVar8 = &ppppuStack_6d4;
  if (7 < (uint)fStack_6c0) {
    pppppuVar8 = (undefined4 *****)ppppuStack_6d4;
  }
  uStack_87c = 0;
  strstreambuf_init(pppppuVar8,fStack_6c4,uStack_878);
  uStack_58 = CONCAT31(uStack_58._1_3_,0xb);
  if (7 < (uint)fStack_6c0) {
    operator_delete(ppppuStack_6d4);
  }
  iVar12 = *(int *)(*(int *)(iStack_898 + 0x160) + 400);
  this = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)wostream_insertWide(&puStack_8bc,L"LVL ");
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(this,iVar12);
  wostream_insertNarrow(&puStack_8bc,&DAT_006fcfbc);
  switch(*(undefined4 *)(*(int *)(iStack_898 + 0x160) + 100)) {
  case 0:
  case 1:
    pcVar13 = "Elf";
    break;
  case 2:
  case 3:
    pcVar13 = "Human";
    break;
  case 4:
  case 5:
    pcVar13 = "Goblin";
    break;
  default:
    goto LAB_00427036;
  case 7:
  case 8:
    pcVar13 = "Lizardman";
    break;
  case 9:
  case 10:
    pcVar13 = "Dwarf";
    break;
  case 0xb:
  case 0xc:
    pcVar13 = "Orc";
    break;
  case 0xf:
  case 0x10:
    pcVar13 = "Undead";
  }
  wostream_insertNarrow(&puStack_8bc,pcVar13);
LAB_00427036:
  wostream_insertNarrow(&puStack_8bc,&DAT_006fcfbc);
  switch(*(undefined1 *)(*(int *)(iStack_898 + 0x160) + 0x140)) {
  case 1:
    pcVar13 = "Warrior";
    break;
  case 2:
    pcVar13 = "Ranger";
    break;
  case 3:
    pcVar13 = "Mage";
    break;
  case 4:
    pcVar13 = "Rogue";
    break;
  default:
    goto LAB_00427089;
  }
  wostream_insertNarrow(&puStack_8bc,pcVar13);
LAB_00427089:
  u16string_assignCStr(L"resource1.dat");
  uStack_58._0_1_ = 0x13;
  uVar3 = u16_ostrstream_str_wrap(&pvStack_384);
  uStack_594 = 0;
  uStack_590 = 0;
  uStack_58c = 0;
  uStack_588 = 0;
  uStack_514 = 0;
  uStack_510 = 0;
  uStack_50c = 0;
  uStack_508 = 0x3f800000;
  uStack_664 = 0x3f800000;
  local_660 = 0x3f800000;
  local_65c = 0x3f800000;
  local_658 = 0x3f800000;
  uStack_58._0_1_ = 0x14;
  AdaptionWidget_draw_text_locked(&pvStack_254,uVar3,0,0x40000000,0x43480000,0x425c0000,0x41400000,0x40400000,
               &uStack_664,&uStack_514,&uStack_594,0,0xbf800000,1);
  if (7 < uStack_370) {
    operator_delete(pvStack_384);
  }
  uStack_370 = 7;
  uStack_374 = 0;
  pvStack_384 = (void *)((uint)pvStack_384 & 0xffff0000);
  uStack_58._0_1_ = 0xb;
  if (7 < uStack_240) {
    operator_delete(pvStack_254);
  }
  u16string_assignCStr(L"resource1.dat");
  uStack_58._0_1_ = 0x15;
  uVar3 = u16_ostrstream_str_wrap(apvStack_3b4);
  uStack_644 = 0;
  uStack_640 = 0;
  local_63c = 0.0;
  local_638 = 0.0;
  local_624 = 0;
  local_620 = 0;
  local_61c = 0;
  uStack_618 = 0;
  uStack_604 = 0x3f800000;
  uStack_600 = 0x3f800000;
  uStack_5fc = 0x3f800000;
  uStack_5f8 = 0x3f800000;
  uStack_58._0_1_ = 0x16;
  AdaptionWidget_draw_text_locked(apvStack_2b4,uVar3,0,0x40000000,0x43480000,0x425c0000,0x41400000,0,&uStack_604,
               &local_624,&uStack_644,0,0xbf800000,1);
  if (7 < uStack_3a0) {
    operator_delete(apvStack_3b4[0]);
  }
  uStack_3a0 = 7;
  apvStack_3b4[4] = (void *)0x0;
  apvStack_3b4[0] = (void *)((uint)apvStack_3b4[0] & 0xffff0000);
  uStack_58._0_1_ = 0xb;
  if (7 < uStack_2a0) {
    operator_delete(apvStack_2b4[0]);
  }
  u16string_assignCStr(&PTR_006fccac);
  uStack_58._0_1_ = 0x17;
  strstreambuf_tidy();
  pppppuVar8 = &ppppuStack_47c;
  if (7 < uStack_468) {
    pppppuVar8 = (undefined4 *****)ppppuStack_47c;
  }
  strstreambuf_init(pppppuVar8,uStack_46c,uStack_878);
  uStack_58 = CONCAT31(uStack_58._1_3_,0xb);
  if (7 < uStack_468) {
    operator_delete(ppppuStack_47c);
  }
  wostream_insertWide(&puStack_8bc,L"Specialization: ");
  iVar12 = *(int *)(iStack_898 + 0x160);
  switch(*(undefined1 *)(iVar12 + 0x140)) {
  case 1:
    if (*(char *)(iVar12 + 0x141) == '\0') {
      wostream_insertNarrow(auStack_870);
    }
    cVar2 = *(char *)(*(int *)(iStack_898 + 0x160) + 0x141);
    break;
  case 2:
    if (*(char *)(iVar12 + 0x141) == '\0') {
      wostream_insertNarrow(auStack_870);
    }
    cVar2 = *(char *)(*(int *)(iStack_898 + 0x160) + 0x141);
    break;
  case 3:
    if (*(char *)(iVar12 + 0x141) == '\0') {
      wostream_insertNarrow(auStack_870);
    }
    cVar2 = *(char *)(*(int *)(iStack_898 + 0x160) + 0x141);
    break;
  case 4:
    if (*(char *)(iVar12 + 0x141) == '\0') {
      wostream_insertNarrow(auStack_870);
    }
    cVar2 = *(char *)(*(int *)(iStack_898 + 0x160) + 0x141);
    break;
  default:
    goto LAB_004274f9;
  }
  if (cVar2 == '\x01') {
    wostream_insertNarrow(auStack_870);
  }
LAB_004274f9:
  u16string_assignCStr();
  local_c._0_1_ = 0x18;
  uVar3 = u16_ostrstream_str_wrap();
  uStack_598 = 0;
  uStack_594 = 0;
  uStack_590 = 0;
  uStack_58c = 0;
  uStack_578 = 0;
  uStack_574 = 0;
  uStack_570 = 0;
  uStack_56c = 0x3f800000;
  uStack_558 = 0x3f800000;
  uStack_554 = 0x3f800000;
  uStack_550 = 0x3f800000;
  uStack_54c = 0x3f800000;
  local_c._0_1_ = 0x19;
  AdaptionWidget_draw_text_locked(apvStack_250,uVar3,0,0x40000000,0x43480000,0x42960000,0x41200000,0x40400000,
               &uStack_558,&uStack_578,&uStack_598,0,0xbf800000);
  if ((void *)0x7 < pvStack_2f4) {
    operator_delete(pvStack_308);
  }
  pvStack_2f4 = (void *)0x7;
  uStack_2f8 = 0;
  pvStack_308 = (void *)((uint)pvStack_308 & 0xffff0000);
  local_c._0_1_ = 0xb;
  if (7 < uStack_23c) {
    operator_delete(apvStack_250[0]);
  }
  u16string_assignCStr();
  local_c._0_1_ = 0x1a;
  uVar3 = u16_ostrstream_str_wrap();
  uStack_538 = 0;
  uStack_534 = 0;
  uStack_530 = 0;
  uStack_52c = 0;
  uStack_518 = 0;
  uStack_514 = 0;
  uStack_510 = 0;
  uStack_50c = 0;
  uStack_4f8 = 0x3f000000;
  uStack_4f4 = 0x3f000000;
  uStack_4f0 = 0x3f800000;
  uStack_4ec = 0x3f800000;
  local_c = CONCAT31(local_c._1_3_,0x1b);
  AdaptionWidget_draw_text_locked(apvStack_220,uVar3,0,0x40000000,0x43480000,0x42960000,0x41200000,0,&uStack_4f8,
               &uStack_518,&uStack_538,0,0xbf800000);
  if (7 < uStack_2dc) {
    operator_delete(pvStack_2f0);
  }
  uStack_2dc = 7;
  uStack_2e0 = 0;
  pvStack_2f0 = (void *)((uint)pvStack_2f0 & 0xffff0000);
  if (7 < uStack_20c) {
    operator_delete(apvStack_220[0]);
  }
LAB_004277eb:
  ctor_18();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&fStack_8c0);
  return;
}




/* cube::Interface::drawCharacterStatsPanel @ 00434e30 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::Interface::drawCharacterStatsPanel.
 * Body reads *(this+0x160)+0x8006d0=Creature: name@+0x1168, level@+0x190 ('LVL '), switch class byte@+0x140 -> Warrior/Ranger/Mage/Rogue +spec@+0x141; strings Power/ARMOR/RESI/CRIT/Weapon Rating via AdaptionWidget_draw_text_locked. The basic_stringstream vftable is written to a LOCAL stack scratch, not this.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void cube::Interface::drawCharacterStatsPanel(void)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  basic_ostream<wchar_t,std::char_traits<wchar_t>_> *pbVar4;
  undefined4 ****ppppuVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar10;
  pair<unsigned___int64,unsigned___int64> *ppVar11;
  int in_ECX;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  void **ppvVar18;
  undefined1 *puVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined *puVar27;
  int iStack_370;
  undefined **local_36c [4];
  undefined *local_35c [2];
  undefined **local_354 [14];
  undefined4 local_31c;
  undefined4 local_318;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_304 [75];
  undefined1 local_2b9;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  int *local_2a8;
  undefined1 local_2a4 [24];
  undefined1 local_28c [24];
  undefined1 local_274 [24];
  undefined1 local_25c [24];
  undefined1 local_244 [24];
  undefined1 local_22c [24];
  undefined1 local_214 [24];
  undefined1 local_1fc [24];
  undefined1 local_1e4 [24];
  undefined1 local_1cc [24];
  undefined1 local_1b4 [24];
  undefined1 local_19c [24];
  undefined1 local_184 [24];
  undefined1 local_16c [24];
  undefined1 local_154 [24];
  undefined1 local_13c [24];
  undefined1 local_124 [24];
  undefined1 local_10c [24];
  undefined1 local_f4 [24];
  undefined1 local_dc [24];
  undefined1 local_c4 [24];
  pair<unsigned___int64,unsigned___int64> local_ac [16];
  undefined1 local_9c [24];
  void *local_84 [4];
  undefined4 local_74;
  uint local_70;
  undefined4 ***local_6c [4];
  undefined4 local_5c;
  uint local_58;
  int local_54;
  int local_50;
  undefined4 ***local_4c [2];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e2902;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2ac = 0.0f;
  local_54 = 10;
  local_50 = 0x14;
  local_36c[0] = &PTR_006fcd00;
  local_35c[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_304);
  local_8 = 0;
  local_2ac = 1.4013e-45f;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_36c,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_354);
  local_8 = 1;
  *(undefined ***)((int)local_36c + (int)local_36c[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_370 + (int)local_36c[0][1]) = local_36c[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_354);
  local_354[0] = vftable;
  local_31c = 0;
  local_318 = 0;
  local_8 = 3;
  iVar12 = *(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0);
  pcVar14 = (char *)(iVar12 + 0x1168);
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (undefined4 ***)((uint)local_4c[0] & 0xffffff00);
  if (*pcVar14 == '\0') {
    iVar12 = 0;
  }
  else {
    pcVar13 = pcVar14;
    do {
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    iVar12 = (int)pcVar13 - (iVar12 + 0x1169);
  }
  string_assignPtrLen(pcVar14,iVar12);
  local_8._0_1_ = 4;
  uVar3 = copy_two_words(local_6c,local_4c);
  local_8._0_1_ = 5;
  wostream_insertU16string(local_35c,uVar3);
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_58 = 7;
  local_5c = 0;
  uVar1 = (uint)local_6c[0] >> 0x10;
  local_6c[0] = (undefined4 ***)(uVar1 << 0x10);
  local_8._0_1_ = 3;
  if (0xf < local_38) {
    operator_delete(local_4c[0]);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = (undefined4 ***)(uVar1 << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 6;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_2b8 = 0.0f;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_44 = 0x3f800000;
  local_40 = 0x3f800000;
  local_3c = 0x3f800000;
  local_38 = 0x3f800000;
  local_8._0_1_ = 7;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41400000,0x40400000,
               &local_44,&local_24,&local_34,0x10,0x43340000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 8;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 9;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41400000,0,&local_34,
               &local_24,&local_44,0x10,0x43340000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_50 = local_50 + 0x10;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (undefined4 ***)((uint)local_4c[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 10;
  strstreambuf_tidy();
  ppppuVar5 = local_4c;
  if (7 < local_38) {
    ppppuVar5 = (undefined4 ****)local_4c[0];
  }
  strstreambuf_init(ppppuVar5,local_3c,local_318);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  iVar12 = *(int *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0) + 400);
  pbVar4 = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)wostream_insertWide(local_35c,L"LVL ");
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(pbVar4,iVar12);
  switch(*(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0) + 0x140)) {
  case 1:
    wostream_insertNarrow(local_35c," Warrior");
    cVar2 = *(char *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0) + 0x141);
    if (cVar2 == '\0') {
      pcVar14 = " | Berserker";
    }
    else {
      if (cVar2 != '\x01') goto LAB_004353f8;
      pcVar14 = " | Guardian";
    }
    break;
  case 2:
    wostream_insertNarrow(local_35c," Ranger");
    cVar2 = *(char *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0) + 0x141);
    if (cVar2 == '\0') {
      pcVar14 = " | Sniper";
    }
    else {
      if (cVar2 != '\x01') goto LAB_004353f8;
      pcVar14 = " | Scout";
    }
    break;
  case 3:
    wostream_insertNarrow(local_35c," Mage");
    cVar2 = *(char *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0) + 0x141);
    if (cVar2 == '\0') {
      pcVar14 = " | Fire";
    }
    else {
      if (cVar2 != '\x01') goto LAB_004353f8;
      pcVar14 = " | Water";
    }
    break;
  case 4:
    wostream_insertNarrow(local_35c," Rogue");
    cVar2 = *(char *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x8006d0) + 0x141);
    if (cVar2 == '\0') {
      pcVar14 = " | Assassin";
    }
    else {
      if (cVar2 != '\x01') goto LAB_004353f8;
      pcVar14 = " | Ninja";
    }
    break;
  default:
    goto LAB_004353f8;
  }
  wostream_insertNarrow(local_35c,pcVar14);
LAB_004353f8:
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0xb;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0xc;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41400000,0x40400000,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0xd;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3f800000;
  local_30 = 0x3f000000;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0xe;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41400000,0,&local_34,
               &local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_50 = local_50 + 0x14;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (undefined4 ***)((uint)local_4c[0] & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 0xf;
  strstreambuf_tidy();
  ppppuVar5 = local_4c;
  if (7 < local_38) {
    ppppuVar5 = (undefined4 ****)local_4c[0];
  }
  strstreambuf_init(ppppuVar5,local_3c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  wostream_insertWide(local_35c,L"Power");
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0x10;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x11;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0x40400000,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x12;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x13;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0,&local_34,
               &local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x14;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  iVar12 = stat_diminishing_returns_pct();
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,iVar12);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x15;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x16;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,
               0x40400000,&local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x17;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3e99999a;
  local_30 = 0x3f19999a;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x18;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,0,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_50 = local_50 + 0x14;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x19;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  wostream_insertWide(local_35c,&DAT_006fd6fc);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x1a;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x1b;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0x40400000,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x1c;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x1d;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0,&local_34,
               &local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x1e;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  fVar15 = (float)stat_calcAttackDamage();
  fVar15 = (float)math_round_to_tenth((float)fVar15);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,(float)fVar15);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x1f;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x20;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,
               0x40400000,&local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x21;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3e99999a;
  local_30 = 0x3f19999a;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x22;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,0,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_50 = local_50 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x23;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  wostream_insertWide(local_35c,L"ARMOR");
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x24;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x25;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0x40400000,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x26;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x27;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0,&local_34,
               &local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x28;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  fVar15 = (float)stat_calcArmor();
  fVar15 = (float)math_round_to_tenth((float)fVar15);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,(float)fVar15);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x29;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x2a;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,
               0x40400000,&local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x2b;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3e99999a;
  local_30 = 0x3f19999a;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x2c;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,0,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_50 = local_50 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x2d;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  wostream_insertWide(local_35c,L"RESI");
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x2e;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x2f;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0x40400000,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x30;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x31;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)local_54,(float)local_50,0x41200000,0,&local_34,
               &local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x32;
  strstreambuf_tidy();
  ppppuVar5 = local_6c;
  if (7 < local_58) {
    ppppuVar5 = (undefined4 ****)local_6c[0];
  }
  strstreambuf_init(ppppuVar5,local_5c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  fVar15 = (float)stat_calcSpirit();
  fVar15 = (float)math_round_to_tenth((float)fVar15);
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,(float)fVar15);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x33;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x34;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,
               0x40400000,&local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x35;
  uVar3 = u16_ostrstream_str_wrap(local_84);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0x3e99999a;
  local_30 = 0x3f19999a;
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_8._0_1_ = 0x36;
  AdaptionWidget_draw_text_locked(local_6c,uVar3,0,0x40000000,(float)(local_54 + 0x96),(float)local_50,0x41200000,0,
               &local_34,&local_24,&local_44,0,0xbf800000,1);
  if (7 < local_70) {
    operator_delete(local_84[0]);
  }
  local_70 = 7;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_50 = local_50 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x37;
  strstreambuf_tidy();
  ppppuVar5 = local_4c;
  if (7 < local_38) {
    ppppuVar5 = (undefined4 ****)local_4c[0];
  }
  strstreambuf_init(ppppuVar5,local_3c,local_318);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    iVar12 = local_38 + 1;
    ppppuVar5 = (undefined4 ****)local_4c[0];
    identity_getter_thunk(&local_2b9);
    std_wstring_operator_delete_wrapper(ppppuVar5,iVar12);
  }
  local_38 = 7;
  u16string_setEos(0);
  wostream_insertWide(local_35c,L"CRIT");
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x38;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  local_8._0_1_ = 0x39;
  piVar6 = (int *)arrayElem_stride4(1);
  local_2a8 = (int *)arrayElem_stride4(0);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  ppvVar18 = local_84;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(ppvVar18,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9,uVar8,uVar7,
               uVar24,uVar25,uVar26);
  AdaptionWidget_draw_text_locked(ppvVar18,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x3a;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x3b;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  ppppuVar5 = local_6c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(ppppuVar5,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  AdaptionWidget_draw_text_locked(ppppuVar5,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x3c;
  strstreambuf_initWrap(local_244);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  GameController_get_field_0x8006d0(&DAT_006fd728);
  fVar15 = (float)Creature_compute_scale_factor();
  local_2ac = (float)fVar15;
  fVar15 = (float)math_round_to_tenth(local_2ac * 100.0f);
  pbVar10 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                      ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,(float)fVar15)
  ;
  wostream_insertWide(pbVar10);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x3d;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x3e;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_274;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9,uVar8,uVar7,
               uVar24,uVar25,uVar26);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x3f;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x40;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3e99999a,0x3f19999a,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_184;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0,uVar9,uVar8,uVar7,uVar24,uVar25
               ,uVar26);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  *piVar6 = *piVar6 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x41;
  strstreambuf_initWrap(local_1b4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_35c,L"TEMPO");
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x42;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x43;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_154;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x44;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  local_8._0_1_ = 0x45;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_1cc;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0,uVar9);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x46;
  strstreambuf_initWrap(local_1e4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  GameController_get_field_0x8006d0(&DAT_006fd728);
  fVar15 = (float)combat_getEffectiveHaste();
  local_2ac = (float)fVar15;
  fVar15 = (float)math_round_to_tenth(local_2ac * 100.0f);
  pbVar10 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                      ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,(float)fVar15)
  ;
  wostream_insertWide(pbVar10);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x47;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x48;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_22c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x49;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  local_8._0_1_ = 0x4a;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3e99999a,0x3f19999a,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_214;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  *piVar6 = *piVar6 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x4b;
  strstreambuf_initWrap(local_25c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_35c,&DAT_006fd738);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x4c;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  local_8._0_1_ = 0x4d;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_28c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x4e;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x4f;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_2a4;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x50;
  strstreambuf_initWrap(local_16c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  GameController_get_field_0x8006d0(&DAT_006fd728);
  fVar15 = (float)Equipment_sum_slot_values();
  local_2ac = (float)fVar15 * 10.0f;
  iVar12 = GameController_get_field_0x8006d0();
  fVar15 = (float)powf_f(0x40000000,(float)(*(int *)(iVar12 + 400) + -1) * 0.25f);
  local_2b0 = (float)fVar15;
  fVar15 = (float)math_round_to_tenth(local_2ac / local_2b0 + 100.0f);
  pbVar10 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                      ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,(float)fVar15)
  ;
  wostream_insertWide(pbVar10);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x51;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x52;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_19c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x53;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  local_8._0_1_ = 0x54;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3e99999a,0x3f19999a,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_1fc;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0,uVar9,uVar8,uVar7,uVar24,uVar25
               ,uVar26);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x55;
  strstreambuf_initWrap(local_13c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  GameController_get_field_0x8006d0(&DAT_006fd740);
  fVar15 = (float)Equipment_sum_slot_values();
  fVar15 = (float)math_round_to_tenth((float)fVar15);
  fVar16 = (float)fVar15;
  pbVar4 = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)
           wostream_insertWide(local_35c,&DAT_006fd744);
  pbVar10 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(pbVar4,fVar16);
  wostream_insertWide(pbVar10);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x56;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x57;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 200);
  puVar19 = local_10c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9,uVar8,uVar7,
               uVar24,uVar25,uVar26);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x58;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  local_8._0_1_ = 0x59;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3e99999a,0x3f19999a,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 200);
  puVar19 = local_124;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  *piVar6 = *piVar6 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x5a;
  strstreambuf_initWrap(local_c4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_35c,L"Weapon Rating");
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x5b;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  local_8._0_1_ = 0x5c;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_f4;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x5d;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x5e;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_dc;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8 = CONCAT31(local_8._1_3_,3);
  std_string_FreeMember();
  local_2ac = 0.0f;
  iVar12 = GameController_get_field_0x8006d0();
  if (*(char *)(iVar12 + 0x990) == '\x03') {
    iVar12 = GameController_get_field_0x8006d0();
    iVar12 = GameController_get_field_0x8006d0(*(undefined1 *)(iVar12 + 0x99c));
    fVar15 = (float)math_pow2Mul((float)(int)*(short *)(iVar12 + 0x9a0));
    local_2b0 = (float)fVar15;
    iVar12 = GameController_get_field_0x8006d0(0);
    fVar15 = (float)math_pow2Mul((float)*(int *)(iVar12 + 400));
    local_2ac = local_2b0 / (float)fVar15 + 0.0f;
  }
  iVar12 = GameController_get_field_0x8006d0();
  if (*(char *)(iVar12 + 0xaa8) == '\x03') {
    iVar12 = GameController_get_field_0x8006d0();
    iVar12 = GameController_get_field_0x8006d0(*(undefined1 *)(iVar12 + 0xab4));
    fVar15 = (float)math_pow2Mul((float)(int)*(short *)(iVar12 + 0xab8));
    local_2b0 = (float)fVar15;
    iVar12 = GameController_get_field_0x8006d0(0);
    fVar15 = (float)math_pow2Mul((float)*(int *)(iVar12 + 400));
    local_2b4 = (float)fVar15;
    local_2ac = local_2b0 / local_2b4 + local_2ac;
  }
  GameController_get_field_0x8006d0();
  cVar2 = weapon_isSpecialRune();
  if (cVar2 == '\0') {
    local_2ac = local_2ac * 0.5f;
  }
  setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  if (0.8f <= local_2ac) {
    if (1.1f <= local_2ac) {
      if (1.2f <= local_2ac) {
        if (1.5f <= local_2ac) {
          if (1.8f <= local_2ac) {
            uVar3 = 0;
            goto LAB_00438527;
          }
          uVar3 = 0x3f800000;
          uVar8 = 0;
          uVar7 = 0x3f000000;
        }
        else {
          uVar3 = 0x3f800000;
          uVar8 = 0x3e800000;
          uVar7 = 0x3e800000;
        }
      }
      else {
        uVar3 = 0;
        uVar8 = 0x3f800000;
        uVar7 = 0;
      }
    }
    else {
      uVar3 = 0x3f800000;
LAB_00438527:
      uVar8 = 0x3f800000;
      uVar7 = 0x3f800000;
    }
  }
  else {
    uVar3 = 0x3f333333;
    uVar8 = 0x3f333333;
    uVar7 = 0x3f333333;
  }
  ppVar11 = (pair<unsigned___int64,unsigned___int64> *)setVec4(uVar7,uVar8,uVar3,0x3f800000);
  pair<unsigned___int64,unsigned___int64>::operator=<std::pair<unsigned___int64,unsigned___int64>,0>
            (local_ac,ppVar11);
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x5f;
  strstreambuf_initWrap(local_dc);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar27 = &DAT_006fd728;
  pbVar10 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                      ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,
                       (int)(local_2ac * 100.0f + 0.5f));
  wostream_insertWide(pbVar10,puVar27);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x60;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x61;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  uVar21 = 0x40000000;
  uVar20 = 0;
  puVar19 = local_f4;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9,uVar8,uVar7,
               uVar24,uVar25,uVar26);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x62;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar25 = 1;
  uVar24 = 0xbf800000;
  uVar23 = 0;
  local_8._0_1_ = 99;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  fVar16 = (float)*piVar6;
  ppVar11 = local_ac;
  uVar22 = 0;
  uVar21 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_c4;
  uVar20 = 0x40000000;
  uVar9 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0,ppVar11,uVar8,uVar7,uVar23,
               uVar24,uVar25);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar9,uVar20,fVar17,fVar16,uVar21,uVar22,ppVar11,uVar8,uVar7,uVar23,
               uVar24,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  *piVar6 = *piVar6 + 0x10;
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 100;
  strstreambuf_initWrap(local_124);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  wostream_insertWide(local_35c,L"Armor Rating");
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x65;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x66;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_10c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x67;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x68;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0;
  uVar22 = 0x41200000;
  fVar17 = (float)*local_2a8;
  puVar19 = local_13c;
  uVar21 = 0x40000000;
  uVar20 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8 = CONCAT31(local_8._1_3_,3);
  std_string_FreeMember();
  iVar12 = GameController_get_field_0x8006d0();
  if (*(char *)(iVar12 + 0x878) == '\a') {
    iVar12 = GameController_get_field_0x8006d0();
    iVar12 = GameController_get_field_0x8006d0(*(undefined1 *)(iVar12 + 0x884));
    fVar15 = (float)math_pow2Mul((float)(int)*(short *)(iVar12 + 0x888));
    local_2b4 = (float)fVar15;
    iVar12 = GameController_get_field_0x8006d0(0);
    fVar15 = (float)math_pow2Mul((float)*(int *)(iVar12 + 400));
    local_2b0 = (float)fVar15;
    local_2b8 = local_2b4 / local_2b0 + 0.0f;
  }
  iVar12 = GameController_get_field_0x8006d0();
  if (*(char *)(iVar12 + 0x530) == '\x04') {
    iVar12 = GameController_get_field_0x8006d0();
    iVar12 = GameController_get_field_0x8006d0(*(undefined1 *)(iVar12 + 0x53c));
    fVar15 = (float)math_pow2Mul((float)(int)*(short *)(iVar12 + 0x540));
    local_2b4 = (float)fVar15 * 2.0f;
    iVar12 = GameController_get_field_0x8006d0(0);
    fVar15 = (float)math_pow2Mul((float)*(int *)(iVar12 + 400));
    local_2b0 = (float)fVar15;
    local_2b8 = local_2b4 / local_2b0 + local_2b8;
  }
  iVar12 = GameController_get_field_0x8006d0();
  if (*(char *)(iVar12 + 0x760) == '\x05') {
    iVar12 = GameController_get_field_0x8006d0();
    iVar12 = GameController_get_field_0x8006d0(*(undefined1 *)(iVar12 + 0x76c));
    fVar15 = (float)math_pow2Mul((float)(int)*(short *)(iVar12 + 0x770));
    local_2b4 = (float)fVar15;
    iVar12 = GameController_get_field_0x8006d0(0);
    fVar15 = (float)math_pow2Mul((float)*(int *)(iVar12 + 400));
    local_2b0 = (float)fVar15;
    local_2b8 = local_2b4 / local_2b0 + local_2b8;
  }
  iVar12 = GameController_get_field_0x8006d0();
  if (*(char *)(iVar12 + 0x648) == '\x06') {
    iVar12 = GameController_get_field_0x8006d0();
    iVar12 = GameController_get_field_0x8006d0(*(undefined1 *)(iVar12 + 0x654));
    fVar15 = (float)math_pow2Mul((float)(int)*(short *)(iVar12 + 0x658));
    local_2b4 = (float)fVar15;
    iVar12 = GameController_get_field_0x8006d0(0);
    fVar15 = (float)math_pow2Mul((float)*(int *)(iVar12 + 400));
    local_2b0 = (float)fVar15;
    local_2b8 = local_2b4 / local_2b0 + local_2b8;
  }
  local_2b8 = local_2b8 / 5.0f;
  if (local_2b8 < 0.8f) {
    uVar8 = 0x3f333333;
    uVar7 = 0x3f333333;
    uVar3 = 0x3f333333;
    goto LAB_00438e0d;
  }
  if (1.1f <= local_2b8) {
    if (local_2b8 < 1.2f) {
      uVar8 = 0;
      uVar7 = 0x3f800000;
      uVar3 = 0;
      goto LAB_00438e0d;
    }
    if (local_2b8 < 1.5f) {
      uVar8 = 0x3f800000;
      uVar7 = 0x3e800000;
      uVar3 = 0x3e800000;
      goto LAB_00438e0d;
    }
    if (local_2b8 < 1.8f) {
      uVar8 = 0x3f800000;
      uVar7 = 0;
      uVar3 = 0x3f000000;
      goto LAB_00438e0d;
    }
    uVar8 = 0;
  }
  else {
    uVar8 = 0x3f800000;
  }
  uVar7 = 0x3f800000;
  uVar3 = 0x3f800000;
LAB_00438e0d:
  ppVar11 = (pair<unsigned___int64,unsigned___int64> *)setVec4(uVar3,uVar7,uVar8,0x3f800000);
  pair<unsigned___int64,unsigned___int64>::operator=<std::pair<unsigned___int64,unsigned___int64>,0>
            (local_ac,ppVar11);
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x69;
  strstreambuf_initWrap(local_dc);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar27 = &DAT_006fd728;
  pbVar10 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                      ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_35c,
                       (int)(local_2b8 * 100.0f + 0.5f));
  wostream_insertWide(pbVar10,puVar27);
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x6a;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar26 = 1;
  uVar25 = 0xbf800000;
  uVar24 = 0;
  local_8._0_1_ = 0x6b;
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0x3f800000);
  uVar9 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  fVar16 = (float)*piVar6;
  uVar23 = 0x40400000;
  uVar22 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  uVar21 = 0x40000000;
  uVar20 = 0;
  puVar19 = local_f4;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0x40400000,uVar9,uVar8,uVar7,
               uVar24,uVar25,uVar26);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar20,uVar21,fVar17,fVar16,uVar22,uVar23,uVar9,uVar8,uVar7,uVar24,
               uVar25,uVar26);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x6c;
  uVar3 = u16_ostrstream_str_wrap(local_9c);
  uVar25 = 1;
  uVar24 = 0xbf800000;
  uVar23 = 0;
  local_8 = CONCAT31(local_8._1_3_,0x6d);
  uVar7 = setVec4(0,0,0,0);
  uVar8 = setVec4(0,0,0,0);
  fVar16 = (float)*piVar6;
  ppVar11 = local_ac;
  uVar22 = 0;
  uVar21 = 0x41200000;
  fVar17 = (float)(*local_2a8 + 0x96);
  puVar19 = local_c4;
  uVar20 = 0x40000000;
  uVar9 = 0;
  getField_0x34(puVar19,uVar3,0,0x40000000,fVar17,fVar16,0x41200000,0,ppVar11,uVar8,uVar7,uVar23,
               uVar24,uVar25);
  AdaptionWidget_draw_text_locked(puVar19,uVar3,uVar9,uVar20,fVar17,fVar16,uVar21,uVar22,ppVar11,uVar8,uVar7,uVar23,
               uVar24,uVar25);
  std_string_FreeMember();
  std_string_FreeMember();
  ctor_18();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: stat::calcArmor  (confidence: med)
 * purpose: Computes armor/defense: base ×2^rand terms plus per-slot element bonuses (0x530/0x648/0x760/0x878)
 * vars: base +0x184; slot type bytes
 */
/* Global::stat_calcArmor @ 0043cff0 */

float stat_calcArmor(void)

{
  int self;
  float fVar1;
  double dVar2;
  double dVar3;
  float weaponBase;
  undefined4 totalDamage;
  undefined4 damage;
  
  dVar2 = libm_sse2_pow_precise
                    (2.0,(double)((1.0 - 1.0 / (((float)*(int *)(self + 400) - 1.0) * 0.05 + 1.0))
                                 * 3.0));
  dVar3 = libm_sse2_pow_precise(2.0,(double)((float)*(byte *)(self + 0x1a8) * 0.25));
  weaponBase = (float)dVar3 * (float)dVar2;
  damage = *(float *)(self + 0x184) * weaponBase;
  if (*(char *)(self + 0x60) == '\0') {
    dVar3 = libm_sse2_pow_precise(2.0,1.0);
    damage = (float)dVar3 * (float)dVar2 * *(float *)(self + 0x184);
  }
  if ((*(byte *)(self + 0x7e) & 0x20) != 0) {
    damage = damage + weaponBase;
  }
  if (*(char *)(self + 0x530) == '\x04') {
    fVar1 = (float)item_computeBlockValue();
    damage = (float)fVar1 + damage;
  }
  if (*(char *)(self + 0x648) == '\x06') {
    fVar1 = (float)item_computeBlockValue();
    damage = (float)fVar1 + damage;
  }
  if (*(char *)(self + 0x760) == '\x05') {
    fVar1 = (float)item_computeBlockValue();
    damage = (float)fVar1 + damage;
  }
  totalDamage = damage;
  if (*(char *)(self + 0x878) == '\a') {
    fVar1 = (float)item_computeBlockValue();
    totalDamage = (float)fVar1 + damage;
  }
  return (float)totalDamage;
}




/* [AUDIT] proposed: Creature::compute_scale_factor  (confidence: low)
 * purpose: compute float scale from status-effect list (game)
 * vars: self=creature
 */
/* Global::Creature_compute_scale_factor @ 0043e9e0 */

float Creature_compute_scale_factor(void)

{
  undefined4 *puVar1;
  int in_ECX;
  float fVar2;
  
  puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 0x1178);
  do {
    if (puVar1 == *(undefined4 **)(in_ECX + 0x1178)) {
LAB_0043e9ff:
      fVar2 = (float)stat_calcManaRegen();
      return (float)((float)fVar2 + *(float *)(in_ECX + 0x1190) * 0.15f);
    }
    if (*(char *)(puVar1 + 2) == '\v') {
      if (puVar1 != (undefined4 *)0xfffffff8) {
        return (float)1;
      }
      goto LAB_0043e9ff;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}




/* [AUDIT] proposed: stat::calcManaRegen  (confidence: med)
 * purpose: Computes mana/spirit regen: base 2^ terms /0.1 plus per-slot rune bonuses (0x530..0xcd8)
 * vars: slot type bytes; 004c6ba0
 */
/* Global::stat_calcManaRegen @ 0043ea40 */

float stat_calcManaRegen(void)

{
  int self;
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined4 result;
  undefined4 value;
  
  dVar2 = libm_sse2_pow_precise
                    (2.0,(double)((1.0 - 1.0 / (((float)*(int *)(self + 400) - 1.0) * 0.05 + 1.0))
                                 * 3.0));
  dVar3 = libm_sse2_pow_precise(2.0,0.0);
  dVar4 = libm_sse2_pow_precise(2.0,3.0);
  value = (((float)dVar2 * (float)dVar3) / (float)dVar4) * 0.1;
  if (*(char *)(self + 0x990) == '\x03') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0xaa8) == '\x03') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x530) == '\x04') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x648) == '\x06') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x760) == '\x05') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x878) == '\a') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x418) == '\b') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0xbc0) == '\t') {
    fVar1 = (float)item_computeStat_regen();
    value = (float)fVar1 + value;
  }
  result = value;
  if (*(char *)(self + 0xcd8) == '\t') {
    fVar1 = (float)item_computeStat_regen();
    result = (float)fVar1 + value;
  }
  return (float)result;
}




/* [AUDIT] proposed: Equipment::sum_slot_values  (confidence: low)
 * purpose: sum float contributions across equipment slots by type tag (game)
 * vars: self=this
 */
/* Global::Equipment_sum_slot_values @ 00446150 */

float Equipment_sum_slot_values(void)

{
  int in_ECX;
  float fVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0.0f;
  if (*(char *)(in_ECX + 0x990) == '\x03') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + 0.0f;
  }
  if (*(char *)(in_ECX + 0xaa8) == '\x03') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  if (*(char *)(in_ECX + 0x530) == '\x04') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  if (*(char *)(in_ECX + 0x648) == '\x06') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  if (*(char *)(in_ECX + 0x760) == '\x05') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  if (*(char *)(in_ECX + 0x878) == '\a') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  if (*(char *)(in_ECX + 0x418) == '\b') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  if (*(char *)(in_ECX + 0xbc0) == '\t') {
    fVar1 = (float)Item_compute_value();
    local_8 = (float)fVar1 + local_8;
  }
  local_c = local_8;
  if (*(char *)(in_ECX + 0xcd8) == '\t') {
    fVar1 = (float)Item_compute_value();
    local_c = (float)fVar1 + local_8;
  }
  return (float)local_c;
}




/* [AUDIT] proposed: stat::calcSpirit  (confidence: med)
 * purpose: Computes spirit/magic stat: base 2^ terms + per-slot rune bonuses (004c7af0)
 * vars: base +0x188; slots
 */
/* Global::stat_calcSpirit @ 004467a0 */

float stat_calcSpirit(void)

{
  int self;
  float fVar1;
  double dVar2;
  double dVar3;
  float base;
  undefined4 totalValue;
  undefined4 value;
  
  dVar2 = libm_sse2_pow_precise
                    (2.0,(double)((1.0 - 1.0 / (((float)*(int *)(self + 400) - 1.0) * 0.05 + 1.0))
                                 * 3.0));
  dVar3 = libm_sse2_pow_precise(2.0,(double)((float)*(byte *)(self + 0x1a8) * 0.25));
  base = (float)dVar3 * (float)dVar2;
  value = *(float *)(self + 0x188) * base;
  if (*(char *)(self + 0x60) == '\0') {
    dVar3 = libm_sse2_pow_precise(2.0,1.0);
    value = (float)dVar3 * (float)dVar2 * *(float *)(self + 0x188);
  }
  if ((*(byte *)(self + 0x7e) & 0x20) != 0) {
    value = value + base;
  }
  if (*(char *)(self + 0x530) == '\x04') {
    fVar1 = (float)item_computeStat_variant2();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x648) == '\x06') {
    fVar1 = (float)item_computeStat_variant2();
    value = (float)fVar1 + value;
  }
  if (*(char *)(self + 0x760) == '\x05') {
    fVar1 = (float)item_computeStat_variant2();
    value = (float)fVar1 + value;
  }
  totalValue = value;
  if (*(char *)(self + 0x878) == '\a') {
    fVar1 = (float)item_computeStat_variant2();
    totalValue = (float)fVar1 + value;
  }
  return (float)totalValue;
}




/* cube::Interface::drawMerchantDialog @ 0044ea30 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::Interface::drawMerchantDialog.
 * GameController_getHoveredTilePtr + GameController_item_icon_id + drawBillboardModelRotated for the item; price calc FUN_004c76e0 (GameController); strings 'Identification'/'Identify'/'COST:'/'Goodbye!' via AdaptionWidget (62b510). Merchant/identify shop render, not a stringbuf ctor.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void cube::Interface::drawMerchantDialog(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar9;
  undefined4 *puVar10;
  undefined4 *in_ECX;
  undefined8 *puVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined *puVar22;
  int iStack_33c;
  undefined **local_338 [4];
  undefined *local_328 [2];
  undefined **local_320 [3];
  undefined4 *local_314;
  undefined4 local_2e8;
  uint local_2e4;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_2d0 [72];
  float local_288;
  int local_284;
  float local_280;
  undefined4 *local_27c;
  float *local_278;
  void *local_274 [5];
  uint local_260;
  undefined4 local_25c;
  undefined4 local_258;
  float local_254;
  float local_250;
  undefined4 local_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  void *local_23c [4];
  undefined4 local_22c;
  uint local_228;
  void *local_224 [2];
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  uint local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 uStack_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  uint local_1d8;
  undefined8 local_1d4 [32];
  undefined8 local_d4 [24];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e30dc;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_278 = (float *)0x0;
  local_27c = in_ECX;
  iVar6 = GameController_getHoveredTilePtr(local_14);
  local_284 = iVar6;
  if (iVar6 != 0) {
    iVar7 = *(int *)((int)in_ECX + 0x148);
    iVar2 = *(int *)(*(int *)(iVar7 + 0x38) + 0x170);
    iVar3 = *(int *)(*(int *)(iVar7 + 0x38) + 0x19c);
    fVar13 = *(float *)(iVar3 + 4 + iVar2 * 8);
    fVar1 = *(float *)(iVar3 + iVar2 * 8);
    local_280 = 1.0f / (*(float *)(iVar7 + 0x54) * fVar1 + *(float *)(iVar7 + 100) * fVar13 +
                      *(float *)(iVar7 + 0x84));
    local_250 = (*(float *)(iVar7 + 0x48) * fVar1 + *(float *)(iVar7 + 0x58) * fVar13 +
                *(float *)(iVar7 + 0x78)) * local_280;
    local_280 = (*(float *)(iVar7 + 0x4c) * fVar1 + *(float *)(iVar7 + 0x5c) * fVar13 +
                *(float *)(iVar7 + 0x7c)) * local_280;
    iVar7 = GameController_item_icon_id(iVar6);
    if (iVar7 != 0) {
      piVar4 = *(int **)(*(int *)((int)in_ECX + 0x16c) + 0x134);
      (**(code **)(*piVar4 + 0xe4))(piVar4,7,1);
      local_24c = 0;
      uStack_248 = 0;
      local_244 = 0;
      uStack_240 = 0;
      local_1f8 = 0;
      uStack_1f4 = 0;
      local_1f0 = 0;
      puVar8 = local_d4;
      puVar11 = local_1d4;
      iVar6 = 0x10;
      do {
        *puVar11 = 0;
        *puVar8 = 0;
        puVar11[1] = 0;
        *(undefined4 *)(puVar8 + 1) = 0;
        puVar11 = puVar11 + 2;
        puVar8 = (undefined8 *)((int)puVar8 + 0xc);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      render_bindNodeTransformA();
      render_uploadBoneMatrices(local_1d4,local_d4);
      local_1fc = 0x3f800000;
      local_1f8 = 0x3f800000;
      uStack_1f4 = 0x3f800000;
      local_1f0 = 0x3f800000;
      render_setUniform30(&local_1fc);
      local_288 = (float)(*(int *)((int)in_ECX + 0x16c) + 0x800a1c);
      iVar6 = AdaptionWidget_getContentSize(&local_244);
      local_278 = (float *)AdaptionWidget_getContentSize(&uStack_1f4);
      uVar20 = 0;
      uVar17 = 0x3d75c28f;
      iVar7 = local_284;
      fVar12 = (float)Widget_measure(local_288,0x3d75c28f,local_284,0);
      fVar13 = (float)fVar12 * 0.5f + *(float *)(iVar6 + 4) + local_280;
      iVar6 = (int)local_288;
      local_288 = (float)fVar12;
      fVar12 = (float)Widget_measureGuarded(fVar13);
      local_280 = (float)fVar12;
      drawBillboardModelRotated(local_280 * 0.5f + local_250 + *local_278,fVar13,iVar6,uVar17,iVar7,uVar20);
      in_ECX = local_27c;
      iVar6 = local_284;
    }
    piVar4 = *(int **)(*(int *)((int)in_ECX + 0x16c) + 0x134);
    (**(code **)(*piVar4 + 0xe4))(piVar4,7,0);
    ctor_0(iVar6,0xf,0xb4,0x3f800000,300,1,0,0);
  }
  local_338[0] = &PTR_006fcd00;
  local_328[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_2d0);
  local_8 = 0;
  local_278 = (float *)0x1;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_338,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_320);
  local_8 = 1;
  *(undefined ***)((int)local_338 + (int)local_338[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_33c + (int)local_338[0][1]) = local_338[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_320);
  local_320[0] = vftable;
  local_2e8 = 0;
  local_2e4 = 0;
  local_8 = 3;
  wostream_insertWide(local_328,L"Identification");
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 4;
  uVar17 = u16_ostrstream_str_wrap(local_224);
  local_8._0_1_ = 5;
  local_1fc = 0;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_24c = 0;
  uStack_248 = 0;
  local_244 = 0;
  uStack_240 = 0x3f800000;
  local_25c = 0x3f800000;
  local_258 = 0x3f800000;
  local_254 = 1.0f;
  local_250 = 1.0f;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x41700000,0x41c80000,0x41400000,0x40400000,&local_25c,
               &local_24c,&local_1fc,0,0xbf800000,1);
  if (7 < local_210) {
    operator_delete(local_224[0]);
  }
  local_210 = 7;
  local_214 = 0;
  local_224[0] = (void *)((uint)local_224[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 6;
  uVar17 = u16_ostrstream_str_wrap(local_224);
  local_1fc = 0;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_24c = 0;
  uStack_248 = 0;
  local_244 = 0;
  uStack_240 = 0;
  local_25c = 0x3f800000;
  local_258 = 0x3f800000;
  local_254 = 1.0f;
  local_250 = 1.0f;
  local_8._0_1_ = 7;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x41700000,0x41c80000,0x41400000,0,&local_25c,&local_24c,
               &local_1fc,0,0xbf800000,1);
  if (7 < local_210) {
    operator_delete(local_224[0]);
  }
  local_210 = 7;
  local_214 = 0;
  local_224[0] = (void *)((uint)local_224[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 8;
  if ((local_2e4 & 1) != 0) {
    operator_delete((void *)*local_314);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_320,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_320,(wchar_t *)0x0,
             (wchar_t *)0x0);
  local_2e4 = local_2e4 & 0xfffffffe;
  puVar10 = &local_1ec;
  if (7 < local_1d8) {
    puVar10 = local_1ec;
  }
  local_2e8 = 0;
  strstreambuf_init(puVar10,local_1dc,local_2e4);
  local_8._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  wostream_insertNarrow(local_328,"Identify");
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 9;
  uVar17 = u16_ostrstream_str_wrap(local_224);
  uVar21 = 1;
  local_1fc = 0;
  uVar19 = 0xbf800000;
  uVar18 = 1;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_24c = 0;
  uStack_248 = 0;
  local_244 = 0;
  uStack_240 = 0x3f800000;
  local_25c = 0x3f800000;
  local_258 = 0x3f800000;
  local_254 = 1.0f;
  local_250 = 1.0f;
  puVar10 = &local_1fc;
  puVar16 = &local_24c;
  puVar15 = &local_25c;
  uVar14 = 0x40400000;
  local_8._0_1_ = 10;
  uVar20 = 0x41400000;
  fVar12 = (float)security_cookie_guard_a(0x41400000,0x40400000,puVar15,puVar16,puVar10,1,0xbf800000,1);
  local_278 = (float *)(float)fVar12;
  fVar13 = (float)local_278 - 20.0f;
  fVar12 = (float)security_cookie_guard_b(fVar13);
  local_278 = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,(float)local_278 / 3.0f,fVar13,uVar20,uVar14,puVar15,puVar16,
               puVar10,uVar18,uVar19,uVar21);
  if (7 < local_210) {
    operator_delete(local_224[0]);
  }
  local_210 = 7;
  local_214 = 0;
  local_224[0] = (void *)((uint)local_224[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  if (local_284 == 0) {
    local_1fc = 0x3f333333;
    local_1f8 = 0x3f333333;
    uStack_1f4 = 0x3f333333;
    local_1f0 = 0x3f800000;
    local_27c = &local_1fc;
  }
  else {
    cVar5 = GameController_isNearTargetTile();
    uStack_248 = 0x3f800000;
    local_244 = 0x3f800000;
    uStack_240 = 0x3f800000;
    local_24c = 0;
    if (cVar5 == '\0') {
      local_24c = 0x3f800000;
    }
    local_25c = local_24c;
    local_258 = 0x3f800000;
    local_254 = 1.0f;
    local_250 = 1.0f;
    local_27c = &local_25c;
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0xb;
  uVar17 = u16_ostrstream_str_wrap(local_23c);
  uVar21 = 1;
  local_20c = 0;
  uVar19 = 0xbf800000;
  uVar18 = 1;
  local_208 = 0;
  local_204 = 0;
  local_200 = 0;
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  puVar10 = &local_20c;
  puVar16 = &local_21c;
  local_8._0_1_ = 0xc;
  uVar14 = 0;
  uVar20 = 0x41400000;
  puVar15 = local_27c;
  fVar12 = (float)security_cookie_guard_a(0x41400000,0,local_27c,puVar16,puVar10,1,0xbf800000,1);
  local_278 = (float *)(float)fVar12;
  fVar13 = (float)local_278 - 20.0f;
  fVar12 = (float)security_cookie_guard_b(fVar13);
  local_278 = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,(float)local_278 / 3.0f,fVar13,uVar20,uVar14,puVar15,puVar16,
               puVar10,uVar18,uVar19,uVar21);
  if (7 < local_228) {
    operator_delete(local_23c[0]);
  }
  local_228 = 7;
  local_22c = 0;
  local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 0xd;
  if ((local_2e4 & 1) != 0) {
    operator_delete((void *)*local_314);
  }
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setg
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_320,(wchar_t *)0x0,
             (wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::setp
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_320,(wchar_t *)0x0,
             (wchar_t *)0x0);
  local_2e4 = local_2e4 & 0xfffffffe;
  puVar10 = &local_1ec;
  if (7 < local_1d8) {
    puVar10 = local_1ec;
  }
  local_2e8 = 0;
  strstreambuf_init(puVar10,local_1dc,local_2e4);
  local_8._0_1_ = 3;
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  wostream_insertNarrow(local_328,"Goodbye!");
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0xe;
  uVar17 = u16_ostrstream_str_wrap(local_23c);
  uVar21 = 1;
  local_21c = 0;
  uVar19 = 0xbf800000;
  uVar18 = 1;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_20c = 0;
  local_208 = 0;
  local_204 = 0;
  local_200 = 0x3f800000;
  local_1fc = 0x3f800000;
  local_1f8 = 0x3f800000;
  uStack_1f4 = 0x3f800000;
  local_1f0 = 0x3f800000;
  puVar10 = &local_21c;
  puVar16 = &local_20c;
  puVar15 = &local_1fc;
  uVar14 = 0x40400000;
  local_8._0_1_ = 0xf;
  uVar20 = 0x41400000;
  fVar12 = (float)security_cookie_guard_a(0x41400000,0x40400000,puVar15,puVar16,puVar10,1,0xbf800000,1);
  local_278 = (float *)(float)fVar12;
  fVar13 = (float)local_278 - 20.0f;
  fVar12 = (float)security_cookie_guard_b(fVar13);
  local_278 = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,((float)local_278 * 2.0f) / 3.0f,fVar13,uVar20,uVar14,puVar15,
               puVar16,puVar10,uVar18,uVar19,uVar21);
  if (7 < local_228) {
    operator_delete(local_23c[0]);
  }
  local_228 = 7;
  local_22c = 0;
  local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  Widget_computeBoundsFloat(&local_254);
  fVar12 = (float)security_cookie_guard_a();
  local_278 = (float *)(float)fVar12;
  if ((float)local_278 - 30.0f < local_250) {
    fVar12 = (float)security_cookie_guard_a();
    local_278 = (float *)(float)fVar12;
    if (local_250 < (float)local_278) {
      fVar12 = (float)security_cookie_guard_b();
      local_278 = (float *)(float)fVar12;
      if ((float)local_278 * 0.5f < local_254) {
        fVar12 = (float)security_cookie_guard_b();
        local_278 = (float *)(float)fVar12;
        if (local_254 < (float)local_278) {
          local_21c = 0;
          local_218 = 0x3f800000;
          local_214 = 0x3f800000;
          local_210 = 0x3f800000;
          local_27c = &local_21c;
          goto LAB_0044f99d;
        }
      }
    }
  }
  local_20c = 0x3f800000;
  local_208 = 0x3f800000;
  local_204 = 0x3f800000;
  local_200 = 0x3f800000;
  local_27c = &local_20c;
LAB_0044f99d:
  local_1d8 = 7;
  local_1dc = 0;
  local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 0x10;
  uVar17 = u16_ostrstream_str_wrap(local_23c);
  uVar21 = 1;
  local_1fc = 0;
  uVar19 = 0xbf800000;
  uVar18 = 1;
  local_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  local_24c = 0;
  uStack_248 = 0;
  local_244 = 0;
  uStack_240 = 0;
  puVar10 = &local_1fc;
  puVar16 = &local_24c;
  local_8._0_1_ = 0x11;
  uVar14 = 0;
  uVar20 = 0x41400000;
  puVar15 = local_27c;
  fVar12 = (float)security_cookie_guard_a(0x41400000,0,local_27c,puVar16,puVar10,1,0xbf800000,1);
  local_278 = (float *)(float)fVar12;
  fVar13 = (float)local_278 - 20.0f;
  fVar12 = (float)security_cookie_guard_b(fVar13);
  local_278 = (float *)(float)fVar12;
  AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,((float)local_278 * 2.0f) / 3.0f,fVar13,uVar20,uVar14,puVar15,
               puVar16,puVar10,uVar18,uVar19,uVar21);
  if (7 < local_228) {
    operator_delete(local_23c[0]);
  }
  local_228 = 7;
  local_22c = 0;
  local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_1d8) {
    operator_delete(local_1ec);
  }
  if (local_284 != 0) {
    iVar7 = GameController_getHoveredTilePtr();
    iVar6 = 0;
    if (iVar7 != 0) {
      iVar6 = item_valueByType();
      if (iVar6 / 2 < 1) {
        iVar6 = 1;
      }
      else {
        iVar6 = item_valueByType();
        iVar6 = iVar6 / 2;
      }
    }
    local_280 = (float)((iVar6 / 100) / 100);
    local_250 = (float)((iVar6 / 100) % 100);
    fVar12 = (float)security_cookie_guard_a();
    local_278 = (float *)(float)fVar12;
    iVar7 = (int)((float)local_278 - 50.0f);
    local_1d8 = 7;
    local_1dc = 0;
    local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
    u16string_assignPtrLen(&PTR_006fccac,0);
    local_8._0_1_ = 0x12;
    strstreambuf_tidy();
    puVar10 = &local_1ec;
    if (7 < local_1d8) {
      puVar10 = local_1ec;
    }
    strstreambuf_init(puVar10,local_1dc,local_2e4);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    puVar22 = &DAT_006ffd80;
    pbVar9 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_328,iVar6 % 100);
    wostream_insertNarrow(pbVar9,puVar22);
    local_1d8 = 7;
    local_1dc = 0;
    local_1ec = (undefined4 *)((uint)local_1ec & 0xffff0000);
    u16string_assignPtrLen(L"resource1.dat",0xd);
    local_8._0_1_ = 0x13;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0x3f800000;
    local_1fc = 0x3f800000;
    local_1f8 = 0x3f800000;
    uStack_1f4 = 0x3f800000;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x14;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x435c0000,(float)iVar7,0x41200000,0x40000000,&local_1fc,
                 &local_20c,&local_21c,2,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x15;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_1fc = 0x3f4ccccd;
    local_1f8 = 0x3f000000;
    uStack_1f4 = 0;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x16;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x435c0000,(float)iVar7,0x41200000,0,&local_1fc,&local_20c,
                 &local_21c,2,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x17;
    strstreambuf_tidy();
    puVar10 = &local_1ec;
    if (7 < local_1d8) {
      puVar10 = local_1ec;
    }
    strstreambuf_init(puVar10,local_1dc,local_2e4);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    puVar22 = &DAT_006ffd84;
    pbVar9 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_328,
                        (int)local_250);
    wostream_insertNarrow(pbVar9,puVar22);
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x18;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0x3f800000;
    local_1fc = 0x3f800000;
    local_1f8 = 0x3f800000;
    uStack_1f4 = 0x3f800000;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x19;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x43340000,(float)iVar7,0x41200000,0x40000000,&local_1fc,
                 &local_20c,&local_21c,2,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x1a;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_1fc = 0x3f333333;
    local_1f8 = 0x3f333333;
    uStack_1f4 = 0x3f333333;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x1b;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x43340000,(float)iVar7,0x41200000,0,&local_1fc,&local_20c,
                 &local_21c,2,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x1c;
    strstreambuf_tidy();
    puVar10 = &local_1ec;
    if (7 < local_1d8) {
      puVar10 = local_1ec;
    }
    strstreambuf_init(puVar10,local_1dc,local_2e4);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    puVar22 = &DAT_006ffd88;
    pbVar9 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_328,
                        (int)local_280);
    wostream_insertNarrow(pbVar9,puVar22);
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x1d;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0x3f800000;
    local_1fc = 0x3f800000;
    local_1f8 = 0x3f800000;
    uStack_1f4 = 0x3f800000;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x1e;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x430c0000,(float)iVar7,0x41200000,0x40000000,&local_1fc,
                 &local_20c,&local_21c,2,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x1f;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_1fc = 0x3f800000;
    local_1f8 = 0x3f666666;
    uStack_1f4 = 0;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x20;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x430c0000,(float)iVar7,0x41200000,0,&local_1fc,&local_20c,
                 &local_21c,2,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(&PTR_006fccac);
    local_8._0_1_ = 0x21;
    strstreambuf_tidy();
    puVar10 = &local_1ec;
    if (7 < local_1d8) {
      puVar10 = local_1ec;
    }
    strstreambuf_init(puVar10,local_1dc,local_2e4);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    wostream_insertNarrow(local_328,"COST:");
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x22;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0x3f800000;
    local_1fc = 0x3f800000;
    local_1f8 = 0x3f800000;
    uStack_1f4 = 0x3f800000;
    local_1f0 = 0x3f800000;
    local_8._0_1_ = 0x23;
    AdaptionWidget_draw_text_locked(&local_1ec,uVar17,0,0,0x41700000,(float)iVar7,0x41200000,0x40000000,&local_1fc,
                 &local_20c,&local_21c,0,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    local_8._0_1_ = 3;
    if (7 < local_1d8) {
      operator_delete(local_1ec);
    }
    u16string_assignCStr(L"resource1.dat");
    local_8._0_1_ = 0x24;
    uVar17 = u16_ostrstream_str_wrap(local_23c);
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_1e4 = 0x3f800000;
    local_1e0 = 0x3f800000;
    local_1dc = 0x3f800000;
    local_1d8 = 0x3f800000;
    local_8 = CONCAT31(local_8._1_3_,0x25);
    AdaptionWidget_draw_text_locked(local_274,uVar17,0,0,0x41700000,(float)iVar7,0x41200000,0,&local_1e4,&local_20c,
                 &local_21c,0,0xbf800000,1);
    if (7 < local_228) {
      operator_delete(local_23c[0]);
    }
    local_228 = 7;
    local_22c = 0;
    local_23c[0] = (void *)((uint)local_23c[0] & 0xffff0000);
    if (7 < local_260) {
      operator_delete(local_274[0]);
    }
  }
  local_228 = 7;
  local_22c = 0;
  ctor_18();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* cube::Interface::drawOptionsMenu @ 004d0230 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::Interface::drawOptionsMenu.
 * if(*(this+0x1d4)==0) L"Windowed" else L"Fullscreen"; reads GC via this+0x160; string xrefs Mode/Resolution/Anti-aliasing/Render Distance/Sound FX+Music Volume/Camera Speed/Camera Smoothness/Invert Y Axis/FPS Limit/Language, all drawn via AdaptionWidget_draw_text_locked. Options menu render, not a stringbuf ctor.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void cube::Interface::drawOptionsMenu(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar5;
  basic_ostream<wchar_t,std::char_traits<wchar_t>_> *this;
  undefined4 *puVar6;
  int in_ECX;
  float fVar7;
  float fVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined *puVar20;
  undefined4 uVar21;
  wchar_t *pwVar22;
  undefined4 uVar23;
  int iVar24;
  undefined4 uVar25;
  undefined1 *puVar26;
  int iStack_2ac;
  undefined **local_2a8 [4];
  undefined *local_298 [2];
  undefined **local_290 [14];
  undefined4 local_258;
  undefined4 local_254;
  basic_ios<wchar_t,std::char_traits<wchar_t>_> local_240 [72];
  float local_1f8;
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
  undefined4 local_74;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8b8a;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1f8 = 0.0f;
  local_2a8[0] = &PTR_006fcd00;
  local_298[0] = &DAT_006fcd08;
  std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::basic_ios<wchar_t,std::char_traits<wchar_t>_>
            (local_240);
  local_8 = 0;
  local_1f8 = 1.4013e-45f;
  std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,std::char_traits<wchar_t>_> *)local_2a8,
             (basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_290);
  local_8 = 1;
  *(undefined ***)((int)local_2a8 + (int)local_2a8[0][1]) =
       basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  *(undefined **)((int)&iStack_2ac + (int)local_2a8[0][1]) = local_2a8[0][1] + -0x68;
  std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,std::char_traits<wchar_t>_> *)local_290);
  local_290[0] = vftable;
  local_258 = 0;
  local_254 = 0;
  local_8 = 3;
  if (*(int *)(in_ECX + 0x1d4) == 0) {
    pwVar22 = L"Windowed";
  }
  else {
    pwVar22 = L"Fullscreen";
  }
  wostream_insertWide(local_298,pwVar22);
  local_60 = 7;
  local_64 = 0;
  local_74 = (void *)((uint)local_74._2_2_ << 0x10);
  u16string_assignPtrLen(L"Mode",4);
  local_8._0_1_ = 4;
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c._2_2_ << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_24 = 0x3f800000;
  local_20 = 0x3f800000;
  local_1c = 0x3f800000;
  local_18 = 0x3f800000;
  local_8._0_1_ = 5;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x41d80000,0x41400000,0x40400000,&local_24,
               &local_34,&local_5c,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  local_60 = 7;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffff0000);
  u16string_assignPtrLen(L"Mode",4);
  local_8._0_1_ = 6;
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 7;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x41d80000,0x41400000,0,&local_5c,&local_34,
               &local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  uVar2 = (uint)local_4c >> 0x10;
  local_4c = (undefined4 *)(uVar2 << 0x10);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)(uVar2 << 0x10);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 8;
  uVar4 = u16_ostrstream_str_wrap(&local_74);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0x40400000;
  uVar11 = 0x41400000;
  local_8._0_1_ = 9;
  uVar10 = 0x41d80000;
  fVar7 = (float)security_cookie_guard_b(0x41d80000,0x41400000,0x40400000,puVar15,puVar16,puVar6,1,0xbf800000
                                ,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_4c,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_60) {
    operator_delete(local_74);
  }
  local_60 = 7;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_8._0_1_ = 10;
  uVar4 = u16_ostrstream_str_wrap(&local_74);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0xb;
  uVar10 = 0x41d80000;
  fVar7 = (float)security_cookie_guard_b(0x41d80000,0x41400000,0,puVar15,puVar16,puVar6,1,0xbf800000,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_4c,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_60) {
    operator_delete(local_74);
  }
  local_60 = 7;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  u16string_assignPtrLen(&PTR_006fccac,0);
  local_8._0_1_ = 0xc;
  strstreambuf_tidy();
  puVar6 = &local_4c;
  if (7 < local_38) {
    puVar6 = local_4c;
  }
  strstreambuf_init(puVar6,local_3c,local_254);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  iVar1 = *(int *)(in_ECX + 0x160);
  if (iVar1 != *(int *)(in_ECX + 0x164)) {
    iVar24 = *(int *)(iVar1 + 4 + *(int *)(in_ECX + 0x204) * 8);
    puVar20 = &DAT_00703420;
    pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                        *(int *)(iVar1 + *(int *)(in_ECX + 0x204) * 8));
    this = (basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)wostream_insertWide(pbVar5,puVar20);
    std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<(this,iVar24);
  }
  local_60 = 7;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffff0000);
  u16string_assignPtrLen(L"Resolution",10);
  local_8._0_1_ = 0xd;
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  u16string_assignPtrLen(L"resource1.dat",0xd);
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0xe;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x42640000,0x41400000,0x40400000,&local_5c,
               &local_34,&local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  local_60 = 7;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffff0000);
  u16string_assignPtrLen(L"Resolution",10);
  local_8._0_1_ = 0xf;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x10;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x42640000,0x41400000,0,&local_5c,&local_34,
               &local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x11;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0x40400000;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x12;
  uVar10 = 0x42640000;
  fVar7 = (float)security_cookie_guard_b(0x42640000,0x41400000,0x40400000,puVar15,puVar16,puVar6,1,0xbf800000
                                ,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x13;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x14;
  uVar10 = 0x42640000;
  fVar7 = (float)security_cookie_guard_b(0x42640000,0x41400000,0,puVar15,puVar16,puVar6,1,0xbf800000,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x15;
  strstreambuf_tidy();
  puVar6 = &local_4c;
  if (7 < local_38) {
    puVar6 = local_4c;
  }
  strstreambuf_init(puVar6,local_3c,local_254);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  if (*(int *)(in_ECX + 0x1e0) < 1) {
    pwVar22 = L"Disabled";
    pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)local_298;
  }
  else {
    pwVar22 = L"x";
    pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                        *(int *)(in_ECX + 0x1e0) * 2);
  }
  wostream_insertWide(pbVar5,pwVar22);
  u16string_assignCStr(L"Anti-aliasing");
  local_8._0_1_ = 0x16;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x17;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x42ae0000,0x41400000,0x40400000,&local_5c,
               &local_34,&local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"Anti-aliasing");
  local_8._0_1_ = 0x18;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x19;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x42ae0000,0x41400000,0,&local_5c,&local_34,
               &local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x1a;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0x40400000;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x1b;
  uVar10 = 0x42ae0000;
  fVar7 = (float)security_cookie_guard_b(0x42ae0000,0x41400000,0x40400000,puVar15,puVar16,puVar6,1,0xbf800000
                                ,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x1c;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x1d;
  uVar10 = 0x42ae0000;
  fVar7 = (float)security_cookie_guard_b(0x42ae0000,0x41400000,0,puVar15,puVar16,puVar6,1,0xbf800000,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x1e;
  strstreambuf_tidy();
  puVar6 = &local_4c;
  if (7 < local_38) {
    puVar6 = local_4c;
  }
  strstreambuf_init(puVar6,local_3c,local_254);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  puVar20 = &DAT_006fd728;
  pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                      *(int *)(in_ECX + 0x1e4));
  wostream_insertWide(pbVar5,puVar20);
  u16string_assignCStr(L"Render Distance");
  local_8._0_1_ = 0x1f;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x20;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x42ea0000,0x41400000,0x40400000,&local_5c,
               &local_34,&local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"Render Distance");
  local_8._0_1_ = 0x21;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x22;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x42ea0000,0x41400000,0,&local_5c,&local_34,
               &local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x23;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0x40400000;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x24;
  uVar10 = 0x42ea0000;
  fVar7 = (float)security_cookie_guard_b(0x42ea0000,0x41400000,0x40400000,puVar15,puVar16,puVar6,1,0xbf800000
                                ,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x25;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x26;
  uVar10 = 0x42ea0000;
  fVar7 = (float)security_cookie_guard_b(0x42ea0000,0x41400000,0,puVar15,puVar16,puVar6,1,0xbf800000,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x27;
  strstreambuf_tidy();
  puVar6 = &local_4c;
  if (7 < local_38) {
    puVar6 = local_4c;
  }
  strstreambuf_init(puVar6,local_3c,local_254);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  puVar20 = &DAT_006fd728;
  pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                      *(int *)(in_ECX + 0x1e8));
  wostream_insertWide(pbVar5,puVar20);
  u16string_assignCStr(L"Sound FX Volume");
  local_8._0_1_ = 0x28;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x29;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x43130000,0x41400000,0x40400000,&local_5c,
               &local_34,&local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"Sound FX Volume");
  local_8._0_1_ = 0x2a;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x2b;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x43130000,0x41400000,0,&local_5c,&local_34,
               &local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x2c;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0x40400000;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x2d;
  uVar10 = 0x43130000;
  fVar7 = (float)security_cookie_guard_b(0x43130000,0x41400000,0x40400000,puVar15,puVar16,puVar6,1,0xbf800000
                                ,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x2e;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x2f;
  uVar10 = 0x43130000;
  fVar7 = (float)security_cookie_guard_b(0x43130000,0x41400000,0,puVar15,puVar16,puVar6,1,0xbf800000,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x30;
  strstreambuf_tidy();
  puVar6 = &local_4c;
  if (7 < local_38) {
    puVar6 = local_4c;
  }
  strstreambuf_init(puVar6,local_3c,local_254);
  local_8._0_1_ = 3;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  puVar20 = &DAT_006fd728;
  pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                      *(int *)(in_ECX + 0x1ec));
  wostream_insertWide(pbVar5,puVar20);
  u16string_assignCStr(L"Music Volume");
  local_8._0_1_ = 0x31;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x32;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x43310000,0x41400000,0x40400000,&local_5c,
               &local_34,&local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"Music Volume");
  local_8._0_1_ = 0x33;
  u16string_assignCStr(L"resource1.dat");
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_8._0_1_ = 0x34;
  AdaptionWidget_draw_text_locked(&local_4c,&local_74,0,0,0x41700000,0x43310000,0x41400000,0,&local_5c,&local_34,
               &local_24,0,0xbf800000,1);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x35;
  uVar4 = u16_ostrstream_str_wrap(&local_4c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0x40400000;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x36;
  uVar10 = 0x43310000;
  fVar7 = (float)security_cookie_guard_b(0x43310000,0x41400000,0x40400000,puVar15,puVar16,puVar6,1,0xbf800000
                                ,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_74,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
  local_8._0_1_ = 3;
  if (7 < local_60) {
    operator_delete(local_74);
  }
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x37;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar23 = 1;
  local_24 = 0;
  uVar19 = 0xbf800000;
  uVar17 = 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_5c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  puVar6 = &local_24;
  puVar16 = &local_34;
  puVar15 = &local_5c;
  uVar13 = 0;
  uVar11 = 0x41400000;
  local_8._0_1_ = 0x38;
  uVar10 = 0x43310000;
  fVar7 = (float)security_cookie_guard_b(0x43310000,0x41400000,0,puVar15,puVar16,puVar6,1,0xbf800000,1);
  local_1f8 = (float)fVar7;
  AdaptionWidget_draw_text_locked(&local_4c,uVar4,0,0,(local_1f8 - 250.0f) * 0.5f + 240.0f,uVar10,uVar11,uVar13,puVar15,
               puVar16,puVar6,uVar17,uVar19,uVar23);
  std_wstring_Tidy(1,0);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x39;
  strstreambuf_initWrap(&local_74);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar20 = &DAT_006fd728;
  pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                      *(int *)(in_ECX + 0x1f0));
  wostream_insertWide(pbVar5,puVar20);
  u16string_assignCStr(L"Camera Speed");
  local_8._0_1_ = 0x3a;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x3b;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0x3f800000);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_164;
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x434f0000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar6 = &local_4c;
  getField_0x34(puVar6,puVar26,0,0,0x41700000,0x434f0000,0x41400000,0x40400000,uVar11,uVar10,uVar4,
               uVar18,uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar6,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"Camera Speed");
  local_8._0_1_ = 0x3c;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x3d;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_1dc;
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x434f0000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_164;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x3e;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x3f;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0x3f800000);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x434f0000;
  fVar7 = (float)security_cookie_guard_b(0x434f0000,0x41400000,0x40400000,uVar13,uVar11,uVar10);
  local_1f8 = (float)fVar7;
  puVar26 = local_1c4;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x40;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x41;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x434f0000;
  fVar7 = (float)security_cookie_guard_b(0x434f0000,0x41400000,0,uVar13,uVar11,uVar10,uVar18,uVar21,uVar25);
  local_1f8 = (float)fVar7;
  puVar26 = local_1f4;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x42;
  strstreambuf_initWrap(local_11c);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar20 = &DAT_006fd728;
  pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                     ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                      *(int *)(in_ECX + 500));
  wostream_insertWide(pbVar5,puVar20);
  u16string_assignCStr(L"Camera Smoothness");
  local_8._0_1_ = 0x43;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x44;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0x3f800000);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_bc;
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x436d0000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_11c;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x436d0000,0x41400000,0x40400000,uVar11,uVar10,uVar4,
               uVar18,uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"Camera Smoothness");
  local_8._0_1_ = 0x45;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x46;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_134;
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x436d0000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_bc;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x436d0000,0x41400000,0,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x47;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  local_8._0_1_ = 0x48;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0x3f800000);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x436d0000;
  fVar7 = (float)security_cookie_guard_b();
  local_1f8 = (float)fVar7;
  puVar26 = local_194;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x49;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x4a;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x436d0000;
  fVar7 = (float)security_cookie_guard_b();
  local_1f8 = (float)fVar7;
  puVar26 = local_104;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x4b;
  strstreambuf_initWrap(local_d4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  puVar20 = &DAT_0070350c;
  if (*(int *)(in_ECX + 0x1f8) == 0) {
    puVar20 = &DAT_00703510;
  }
  wostream_insertNarrow(local_298,puVar20);
  u16string_assignCStr(L"Invert Y Axis");
  local_8._0_1_ = 0x4c;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x4d;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0x3f800000);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_ec;
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x43858000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_d4;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x43858000,0x41400000,0x40400000,uVar11,uVar10,uVar4,
               uVar18,uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"Invert Y Axis");
  local_8._0_1_ = 0x4e;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x4f;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_14c;
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x43858000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_ec;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x43858000,0x41400000,0,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x50;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x51;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0x3f800000);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x43858000;
  fVar7 = (float)security_cookie_guard_b(0x43858000,0x41400000,0x40400000,uVar13,uVar11,uVar10,uVar18,uVar21,
                                uVar25);
  local_1f8 = (float)fVar7;
  puVar26 = local_17c;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x52;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x53;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x43858000;
  fVar7 = (float)security_cookie_guard_b(0x43858000,0x41400000,0,uVar13,uVar11,uVar10,uVar18,uVar21,uVar25);
  local_1f8 = (float)fVar7;
  puVar26 = local_1ac;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x54;
  strstreambuf_initWrap(local_a4);
  local_8 = CONCAT31(local_8._1_3_,3);
  std_string_FreeMember();
  if (*(int *)(in_ECX + 0x200) < 1) {
    puVar26 = &DAT_00703530;
    pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)local_298;
  }
  else {
    puVar26 = &DAT_00703538;
    pbVar5 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
                       ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,
                        (int)(1000 / (longlong)*(int *)(in_ECX + 0x200)));
  }
  wostream_insertNarrow(pbVar5,puVar26);
  u16string_assignCStr(L"FPS Limit");
  local_8._0_1_ = 0x55;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x56;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0x3f800000);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_1ac;
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x43948000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_a4;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x43948000,0x41400000,0x40400000,uVar11,uVar10,uVar4,
               uVar18,uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"FPS Limit");
  local_8._0_1_ = 0x57;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  local_8._0_1_ = 0x58;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_17c;
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x43948000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_a4;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x43948000,0x41400000,0,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x59;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x5a;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0x3f800000);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x43948000;
  fVar7 = (float)security_cookie_guard_b(0x43948000,0x41400000,0x40400000,uVar13,uVar11,uVar10,uVar18,uVar21,
                                uVar25);
  local_1f8 = (float)fVar7;
  puVar26 = local_14c;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x5b;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x5c;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x43948000;
  fVar7 = (float)security_cookie_guard_b();
  local_1f8 = (float)fVar7;
  puVar26 = local_ec;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34();
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(&PTR_006fccac);
  local_8._0_1_ = 0x5d;
  strstreambuf_initWrap(local_d4);
  local_8._0_1_ = 3;
  std_string_FreeMember();
  std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::operator<<
            ((basic_ostream<wchar_t,std::char_traits<wchar_t>_> *)local_298,*(int *)(in_ECX + 0x1fc)
            );
  u16string_assignCStr(L"Language");
  local_8._0_1_ = 0x5e;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x5f;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0x3f800000);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_104;
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x43a38000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_a4;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x43a38000,0x41400000,0x40400000,uVar11,uVar10,uVar4,
               uVar18,uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"Language");
  local_8._0_1_ = 0x60;
  u16string_assignCStr(L"resource1.dat");
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 0;
  local_8._0_1_ = 0x61;
  uVar4 = setVec4(0,0,0,0);
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  puVar26 = local_194;
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x43a38000;
  uVar19 = 0x41700000;
  uVar17 = 0;
  uVar13 = 0;
  puVar9 = local_a4;
  getField_0x34(puVar9,puVar26,0,0,0x41700000,0x43a38000,0x41400000,0,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  AdaptionWidget_draw_text_locked(puVar9,puVar26,uVar13,uVar17,uVar19,uVar23,uVar12,uVar14,uVar11,uVar10,uVar4,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 0x62;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  local_8._0_1_ = 99;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0x3f800000);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0x40400000;
  uVar12 = 0x41400000;
  uVar23 = 0x43a38000;
  fVar7 = (float)security_cookie_guard_b(0x43a38000,0x41400000,0x40400000,uVar13,uVar11,uVar10,uVar18,uVar21,
                                uVar25);
  local_1f8 = (float)fVar7;
  puVar26 = local_134;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8._0_1_ = 3;
  std_string_FreeMember();
  u16string_assignCStr(L"resource1.dat");
  local_8._0_1_ = 100;
  uVar4 = u16_ostrstream_str_wrap(local_8c);
  uVar25 = 1;
  uVar21 = 0xbf800000;
  uVar18 = 1;
  local_8._0_1_ = 0x65;
  uVar10 = setVec4(0,0,0,0);
  uVar11 = setVec4(0,0,0,0);
  uVar13 = setVec4(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  uVar14 = 0;
  uVar12 = 0x41400000;
  uVar23 = 0x43a38000;
  fVar7 = (float)security_cookie_guard_b(0x43a38000,0x41400000,0,uVar13,uVar11,uVar10,uVar18,uVar21,uVar25);
  local_1f8 = (float)fVar7;
  puVar26 = local_bc;
  fVar8 = (local_1f8 - 250.0f) * 0.5f + 240.0f;
  uVar19 = 0;
  uVar17 = 0;
  getField_0x34(puVar26,uVar4,0,0,fVar8);
  AdaptionWidget_draw_text_locked(puVar26,uVar4,uVar17,uVar19,fVar8,uVar23,uVar12,uVar14,uVar13,uVar11,uVar10,uVar18,
               uVar21,uVar25);
  std_string_FreeMember();
  local_8 = CONCAT31(local_8._1_3_,3);
  std_string_FreeMember();
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  getField_0x40();
  cVar3 = GameController_updateWidgetLayout();
  if (cVar3 == '\0') {
    uVar4 = 0x3f800000;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = setVec4(uVar4,0x3f800000,0x3f800000,0x3f800000);
  getField_0x3c(uVar4);
  storeVec4At(uVar4);
  ctor_18();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




