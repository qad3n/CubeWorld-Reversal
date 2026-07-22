// Button (ui) — cube. 1 functions. Bodies = Ghidra pseudo-C.
#include "Button.h"

/* plasma::Button::vfunc_7 @ 006655d0 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::Button::vfunc_7.
 * RTTI AVButton@plasma@@=plasma::Button (base AVAdaptionWidget@cube@@). Body calls base cube::AdaptionWidget::vfunc_7, rebuilds child list@+0x220, relayouts after onContentResized, filters children +0x38==1 & +0x22c==2. Callers=derived PopUp/ScrollButton vfunc_7. Engine UI, not CRT/STL.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::Button::vfunc_7(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  int *local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f76e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  cube::AdaptionWidget::vfunc_7(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  puVar2 = *(undefined4 **)(in_ECX + 0x220);
  piVar1 = (int *)(in_ECX + 0x220);
  pvVar3 = (void *)*puVar2;
  *puVar2 = puVar2;
  *(int *)(*piVar1 + 4) = *piVar1;
  *(undefined4 *)(in_ECX + 0x224) = 0;
  if (pvVar3 != (void *)*piVar1) {
    operator_delete(pvVar3);
  }
  iVar4 = AdaptionWidget_onContentResized();
  if ((*(uint *)(*(int *)(in_ECX + 0x148) + 200) >> 4 & 1) != 0) {
    if (iVar4 == 0) goto LAB_0066580d;
    iVar4 = AdaptionWidget_onContentResized();
  }
  if (iVar4 != 0) {
    tree_clear(&local_24);
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    piVar7 = (int *)*local_24;
    piVar6 = local_24;
    if (piVar7 != local_24) {
      do {
        if ((*(uint *)(*(int *)(in_ECX + 0x148) + 200) >> 4 & 1) != 0) {
          tree_clear(&local_2c);
          local_8._0_1_ = 1;
          piVar7 = (int *)*local_2c;
          piVar6 = local_2c;
          if (piVar7 != local_2c) {
            do {
              local_18 = piVar7[2];
              if ((local_18 == 0) || (*(int *)(local_18 + 0x38) != 1)) {
                local_18 = 0;
              }
              if (((local_18 != 0) && (local_18 != local_14)) && (*(int *)(local_18 + 0x22c) == 2))
              {
                local_1c = *piVar1;
                iVar4 = IntMap_SetScalar(local_1c,*(undefined4 *)(local_1c + 4),&local_18);
                if (*(int *)(in_ECX + 0x224) == 0x15555554) {
LAB_00665836:
                  std::_Xlength_error("list<T> too long");
                }
                *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
                *(int *)(local_1c + 4) = iVar4;
                **(int **)(iVar4 + 4) = iVar4;
                piVar6 = local_2c;
              }
              piVar7 = (int *)*piVar7;
            } while (piVar7 != piVar6);
          }
          piVar1 = (int *)*piVar6;
          *piVar6 = (int)piVar6;
          local_8 = (uint)local_8._1_3_ << 8;
          local_2c[1] = (int)local_2c;
          local_28 = 0;
          if (piVar1 == local_2c) {
            operator_delete(local_2c);
          }
          operator_delete(piVar1);
        }
        local_1c = piVar7[2];
        if ((local_1c == 0) || (*(int *)(local_1c + 0x38) != 1)) {
          local_1c = 0;
        }
        if (((local_1c != 0) && (local_1c != in_ECX)) && (*(int *)(local_1c + 0x22c) == 2)) {
          local_18 = *piVar1;
          iVar4 = IntMap_SetScalar(local_18,*(undefined4 *)(local_18 + 4),&local_1c);
          if (*(int *)(in_ECX + 0x224) == 0x15555554) goto LAB_00665836;
          *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
          *(int *)(local_18 + 4) = iVar4;
          **(int **)(iVar4 + 4) = iVar4;
          piVar6 = local_24;
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != piVar6);
    }
    piVar1 = (int *)*piVar6;
    *piVar6 = (int)piVar6;
    local_8 = 0xffffffff;
    local_24[1] = (int)local_24;
    local_20 = 0;
    if (piVar1 == local_24) {
      operator_delete(local_24);
    }
    operator_delete(piVar1);
  }
LAB_0066580d:
  if (*(char *)(local_14 + 0x15c) != '\0') {
    if (*(int *)(local_14 + 0x22c) == 0) {
      iVar4 = local_14 + 0x178;
    }
    else {
      AdaptionWidget_apply_to_attributes(local_14 + 0x1c0,0);
      uVar5 = AdaptionWidget_compute_max_content_width(local_14 + 0x1c0);
      AdaptionWidget_relayout(uVar5);
      AdaptionWidget_apply_attributes_v2();
      iVar4 = local_14 + 0x1d8;
    }
    AdaptionWidget_apply_to_attributes(iVar4,0);
    uVar5 = AdaptionWidget_compute_max_content_width(iVar4);
    AdaptionWidget_relayout(uVar5);
    AdaptionWidget_apply_attributes_v2();
    AdaptionWidget_apply_to_attributes(local_14 + 0x178,0);
    uVar5 = AdaptionWidget_compute_max_content_width(local_14 + 0x178);
    AdaptionWidget_relayout(uVar5);
    AdaptionWidget_apply_attributes_v2();
    AdaptionWidget_apply_to_attributes(local_14 + 0x1a8,0);
    uVar5 = AdaptionWidget_compute_max_content_width(local_14 + 0x1a8);
    AdaptionWidget_relayout(uVar5);
    AdaptionWidget_apply_attributes_v2();
    if (*(char *)(local_14 + 0x229) != '\0') {
      AdaptionWidget_apply_to_attributes(local_14 + 0x160,0);
      uVar5 = AdaptionWidget_compute_max_content_width(local_14 + 0x160);
      AdaptionWidget_relayout(uVar5);
      AdaptionWidget_apply_attributes_v2();
      AdaptionWidget_apply_to_attributes(local_14 + 0x1d8,0);
      uVar5 = AdaptionWidget_compute_max_content_width(local_14 + 0x1d8);
      AdaptionWidget_relayout(uVar5);
      AdaptionWidget_apply_attributes_v2();
      AdaptionWidget_apply_to_attributes(local_14 + 0x208,0);
      uVar5 = AdaptionWidget_compute_max_content_width(local_14 + 0x208);
      AdaptionWidget_relayout(uVar5);
      AdaptionWidget_apply_attributes_v2();
    }
  }
  ExceptionList = local_10;
  return;
}




