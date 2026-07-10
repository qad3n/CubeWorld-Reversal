// ChatWidget (cube) — reconstructed declarations.
#ifndef CUBE_UI_CHATWIDGET_H
#define CUBE_UI_CHATWIDGET_H
#include "../include/cube_types.h"

void cube::ChatWidget::ctor_0(undefined4 param_1,undefined4 param_2);
void ChatWidget_clearText(void);
void cube::ChatWidget::vfunc_0(byte param_1);
undefined4 cube::ChatWidget::vfunc_3(undefined4 param_1);
void list_clear(void);
void cube::ChatWidget::vfunc_1(void);
undefined1 cube::ChatWidget::vfunc_4(void);
void ChatWidget_measureChatText(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,float param_8, float *param_9,float *param_10,uint param_11,undefined4 param_12);
void TextRender_configureSize(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,char param_6);
void TextRender_setTransform(float param_1,float param_2,float *param_3);
void TextRender_computeScaledSize(float *param_1,float param_2,float param_3,float param_4,float param_5, float *param_6,float *param_7,float *param_8,float *param_9);
void TextRender_layoutAndWrap(undefined4 *param_1,float param_2);
void ChatWidget_setBindTransform(int param_1,int *param_2,int *param_3);

#endif
