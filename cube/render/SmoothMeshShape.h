// SmoothMeshShape (cube) — reconstructed declarations.
#ifndef CUBE_RENDER_SMOOTHMESHSHAPE_H
#define CUBE_RENDER_SMOOTHMESHSHAPE_H
#include "../include/cube_types.h"

float * math_mat3_transform_point2d(float *param_1,float *param_2);
void vectorReserve8(uint param_1);
void vectorReserve16(uint param_1);
void FUN_0062de10(undefined1 param_1);
void FUN_0063a980(int *param_1,int *param_2,uint param_3,int param_4,char param_5,float param_6, int param_7);
void FUN_0063ad70(int *param_1,int *param_2,uint param_3,int param_4,char param_5,float param_6, int param_7);
void FUN_0063b360(int *param_1,int *param_2,uint param_3,int param_4,char param_5,float param_6, int param_7);
void FUN_0063bba0(int *param_1,uint param_2,int param_3,char param_4,float param_5);
void plasma::SmoothMeshShape::destroyLevelBuffers(void);
int FUN_0063d6f0(uint param_1);
void FUN_0063d9c0(undefined4 *param_1,uint param_2,uint param_3);
int FUN_0063deb0(void);
void plasma::SmoothMeshShape::clear(void);
uint FUN_00641b60(void);
uint FUN_006423f0(void);
uint FUN_00642400(void);
void FUN_00642570(void);
void FUN_00642590(undefined4 *param_1);
float10 FUN_006426d0(float param_1,float param_2,float param_3);
uint FUN_00642a90(void);
void FUN_00642ad0(int param_1,int param_2,int param_3);
void plasma::SmoothMeshShape::rebuild(char param_1);
void FUN_00648d60(void);
void Object_release_if_nonnull(undefined4 *param_1);
void FUN_0066b9c0(void);
void plasma::SmoothMeshShape::vfunc_19(void);
void FUN_0066c050(void);
void plasma::SmoothMeshShape::clearLevelBuffers(void);
void FUN_00671f80(float param_1);
void FUN_00673090(float *param_1);
void FUN_00674160(void);
void FUN_00675690(void);

#endif
