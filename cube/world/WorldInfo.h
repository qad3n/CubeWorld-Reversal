// WorldInfo (cube) — reconstructed declarations.
#ifndef CUBE_WORLD_WORLDINFO_H
#define CUBE_WORLD_WORLDINFO_H
#include "../include/cube_types.h"

undefined4 * WorldInfo_mapLowerBound(int *param_1);
void cube::WorldInfo::ctor_1(void);
void cube::WorldInfo::ctor_0(void);
void cube::WorldInfo::vfunc_0(byte param_1);
void WorldGrid_freeCellPtr(int param_1,int param_2);
void WorldGrid_destroyCellObject(int param_1,int param_2);
void WorldGrid_destroyBlockObjectAt(uint param_1,uint param_2);
void WorldInfo_generateBiomeContent(float param_1,uint param_2);
void WorldInfo_placeStructure(int param_1,int *param_2,uint param_3,byte param_4,int param_5,int param_6, char param_7,int *param_8,int param_9);
void WorldInfo_mapInsertEntry(undefined4 param_1);
void WorldInfo_lookupCell(uint param_1);
void * WorldInfo_scatterObjectsInArea(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);
int WorldInfo_vectorElementAt(int param_1,char param_2);
uint WorldInfo_vectorAppend(void);
float WorldInfo_sampleTerrainHeight(uint param_1,float param_2);
void WorldInfo_rotateAndPlace(uint param_1,uint param_2);

#endif
