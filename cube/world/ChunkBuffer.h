// ChunkBuffer (cube) — reconstructed declarations.
#ifndef CUBE_WORLD_CHUNKBUFFER_H
#define CUBE_WORLD_CHUNKBUFFER_H
#include "../include/cube_types.h"

void vec3i64_scaleFixed(undefined4 param_1,undefined4 param_2);
void cube::ChunkBuffer::vfunc_0(byte param_1);
void ChunkBuffer_pushQuadFaces(undefined4 param_1,int param_2);
void cube::ChunkBuffer::ctor_0(undefined4 *param_1,int param_2);
float * ChunkBuffer_sampleVoxelColorAO(float *param_1,int param_2,int param_3,int param_4,float *param_5,int *param_6, char param_7);
void VoxelChunk_propagateSunlight(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6);
undefined * VoxelColumn_at(int param_1);
int ChunkBuffer_loadAndNotify(undefined4 param_1,undefined4 param_2,undefined4 param_3);

#endif
