// AdaptionWidget (cube) — reconstructed declarations.
#ifndef CUBE_UI_ADAPTIONWIDGET_H
#define CUBE_UI_ADAPTIONWIDGET_H
#include "../include/cube_types.h"

void cube::AdaptionWidget::ctor_0 (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4, undefined4 param_5);
void cube::AdaptionWidget::vfunc_1_0040f8f0(void);
undefined1 cube::AdaptionWidget::vfunc_4(void);
void cube::AdaptionWidget::vfunc_10(void);
void cube::AdaptionWidget::vfunc_6(void);
void cube::AdaptionWidget::vfunc_0_00428a30(byte param_1);
void Matrix4_Invert(void);
undefined4 * plasma::NamedObject::ctor_5(int param_1,int param_2);
void AdaptionWidget_clampScrollToContent(void);
undefined4 cube::AdaptionWidget::vfunc_40(undefined4 param_1);
void cube::AdaptionWidget::vfunc_0_00627e40(float *param_1,float *param_2,int param_3);
void cube::AdaptionWidget::vfunc_41(char param_1);
void AdaptionWidget_layoutRecursive(int param_1);
void AdaptionWidget_applyScrollLayout(float *param_1,char param_2);
void cube::AdaptionWidget::vfunc_35(void);
void cube::AdaptionWidget::vfunc_36(void);
void cube::AdaptionWidget::vfunc_39(void);
void cube::AdaptionWidget::vfunc_7(void);
void cube::AdaptionWidget::vfunc_11(void);
void cube::AdaptionWidget::vfunc_12(void);
void cube::AdaptionWidget::vfunc_21(void);
void cube::AdaptionWidget::vfunc_9(float *param_1,float *param_2);
void cube::AdaptionWidget::vfunc_8(void);
float * AdaptionWidget_getScrollFlag(float *param_1);
void AdaptionWidget_getContentSize(float *param_1);
void AdaptionWidget_setCaption(void);
void Widget_measureChildrenRecursive(int param_1,undefined4 param_2,float *param_3,undefined4 param_4);
void AdaptionWidget_measureContent(float *param_1,undefined4 param_2);
void AdaptionWidget_computeBoundsUnion(float *param_1);
void AdaptionWidget_accumulateChildBounds(float *param_1);
void AdaptionWidget_computeLayoutBounds(float *param_1);
void cube::AdaptionWidget::vfunc_1_0062e180(float *param_1,float *param_2,int param_3);
int get_widget_state(int param_1);
void Node_clear_dirty_flag_2e(void);
void AdaptionWidget_relayout(undefined4 param_1);
void AdaptionWidget_layout_recursive(undefined4 param_1,undefined4 param_2,char param_3);
int AdaptionWidget_compute_max_content_width(undefined4 param_1);
void AdaptionWidget_compute_local_transform(void);
void AdaptionWidget_recompute_transforms_recursive(void);
undefined4 * Registry_push_node_locked_0x7c(undefined4 *param_1);
void Widget_set_flags_word(undefined4 param_1);
void Widget_dispatch_event_callback(int param_1,undefined4 param_2);
void AdaptionWidget_clear_hover(void);
undefined4 AnimMap_findValueByKey(int param_1);
void Widget_layoutAspectFit(void);
void Widget_applyAlignmentOffset(float param_1);
void Widget_destroyTailSlot(int param_1);
char Widget_updateAnimations(undefined4 param_1);
void cube::AdaptionWidget::vfunc_24(void);
void cube::AdaptionWidget::vfunc_2(undefined4 *param_1);
undefined1 cube::AdaptionWidget::vfunc_5(void);

#endif
