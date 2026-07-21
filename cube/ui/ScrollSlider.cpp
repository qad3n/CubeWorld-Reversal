// ScrollSlider (ui) — cube. 2 functions. Bodies = Ghidra pseudo-C.
#include "ScrollSlider.h"

/* plasma::ScrollSlider::vfunc_21 @ 00662b80 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::ScrollSlider::vfunc_21.
 * RTTI AVScrollSlider@plasma@@. Relayout vfunc: chains cube::AdaptionWidget::vfunc_21, recomputes scroll extent via getBoundsRect/getContentSize, applyScrollLayout + clampScrollToContent, dispatches widget event 0x11. In-house UI widget.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::ScrollSlider::vfunc_21(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  float *pfVar7;
  undefined1 *puVar8;
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  float local_1c;
  float local_18 [4];
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  cube::AdaptionWidget::vfunc_21();
  iVar2 = AdaptionWidget_onContentResized();
  if ((iVar2 != 0) && ((*(byte *)(*(int *)(in_ECX + 4) + 0xf4) & 1) != 0)) {
    uVar6 = (uint)(*(int *)(in_ECX + 0x238) != 1);
    pfVar7 = local_18 + 2;
    AdaptionWidget_onContentResized(pfVar7);
    iVar2 = AdaptionWidget_getBoundsRect(pfVar7);
    iVar3 = AdaptionWidget_getBoundsRect(local_20);
    local_1c = *(float *)(iVar2 + uVar6 * 4) - *(float *)(iVar3 + uVar6 * 4);
    AdaptionWidget_getContentSize(local_18);
    iVar2 = *(int *)(in_ECX + 4);
    local_18[2] = *(float *)(iVar2 + 0xd4) - *(float *)(iVar2 + 0xdc);
    local_18[3] = *(float *)(iVar2 + 0xd8) - *(float *)(iVar2 + 0xe0);
    local_18[uVar6] = local_18[uVar6 + 2] + local_18[uVar6];
    if (local_18[uVar6] <= 0.0 && local_18[uVar6] != 0.0) {
      local_18[uVar6] = 0.0;
    }
    if (local_1c < local_18[uVar6]) {
      local_18[uVar6] = local_1c;
    }
    AdaptionWidget_applyScrollLayout(local_18,1);
    if ((*(int *)(in_ECX + 0x24c) != 0) && (iVar2 = AdaptionWidget_onContentResized(), iVar2 != 0)) {
      iVar2 = AdaptionWidget_getBoundsRect(local_18 + 2);
      puVar8 = local_20;
      AdaptionWidget_onContentResized(puVar8);
      iVar3 = AdaptionWidget_getBoundsRect(puVar8);
      fVar1 = *(float *)(iVar3 + uVar6 * 4);
      pfVar7 = (float *)(iVar2 + uVar6 * 4);
      if (*pfVar7 <= fVar1 && fVar1 != *pfVar7) {
        AdaptionWidget_getContentSize(local_18 + 2);
        local_1c = (float)AdaptionWidget_getContentSize(local_28);
        puVar8 = local_30;
        AdaptionWidget_onContentResized(puVar8);
        iVar2 = AdaptionWidget_getBoundsRect(puVar8);
        iVar3 = AdaptionWidget_getBoundsRect(local_38);
        puVar8 = local_40;
        AdaptionWidget_onContentResized(puVar8);
        iVar4 = AdaptionWidget_getBoundsRect(puVar8);
        iVar5 = AdaptionWidget_getBoundsRect(local_48);
        local_18[uVar6 + 2] =
             (*(float *)((int)local_1c + uVar6 * 4) /
             (*(float *)(iVar2 + uVar6 * 4) - *(float *)(iVar3 + uVar6 * 4))) *
             (*(float *)(iVar4 + uVar6 * 4) - *(float *)(iVar5 + uVar6 * 4));
        AdaptionWidget_applyScrollLayout(local_18 + 2,1);
      }
      AdaptionWidget_clampScrollToContent();
      (**(code **)(**(int **)(in_ECX + 0x24c) + 0xa8))();
      Widget_dispatch_event_callback(*(undefined4 *)(*(int *)(in_ECX + 0x24c) + 0x148),0x11);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* plasma::ScrollSlider::vfunc_9 @ 00662db0 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->plasma_engine. Identity (RE-inferred, high): plasma::ScrollSlider::vfunc_9.
 * RTTI AVScrollSlider@plasma@@ is a real class. Widget layout vfunc override calls base cube::AdaptionWidget::vfunc_9 (62af10, real float geometry) + Widget_layoutAspectFit (662860); both game/AdaptionWidget. Two distinct calls => not an adjustor thunk, not STL glue.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void plasma::ScrollSlider::vfunc_9(undefined4 param_1,undefined4 param_2)

{
  cube::AdaptionWidget::vfunc_9(param_1,param_2);
  Widget_layoutAspectFit();
  return;
}




