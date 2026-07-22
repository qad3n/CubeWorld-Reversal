// World (server) — reconstructed declarations.
#ifndef SERVER_WORLD_WORLD_H
#define SERVER_WORLD_WORLD_H
#include "../include/cube_types.h"

undefined4 * __thiscall Vec3_copy(void *this,undefined4 *param_1);
undefined4 * __thiscall Vec3_set(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3);
undefined1 * __thiscall String_ctorFromCStr(void *this,int *param_1);
void __fastcall String_destroy(undefined4 *param_1);
int __thiscall getElemPtr4(void *this,int param_1);
int __fastcall getField_plus0x10(int *param_1);
float10 __cdecl formula_inverse(float param_1);
undefined4 * __thiscall RefCountedNode_init(void *this,undefined4 param_1);
void __thiscall readCombatActionFromStream(void *this,int param_1);
void __thiscall readHitFromStream(void *this,undefined4 *param_1);
undefined4 * __thiscall pair_set2(void *this,undefined4 param_1,undefined4 param_2);
void __thiscall deref_getFirst(void *this,undefined4 *param_1);
void __thiscall World_findNearestEntityInRegion(void *this,int param_1,int param_2);
void __thiscall World_loadVoxelModel(void *this,char *param_1,void *param_2,char *param_3);
undefined1 * __thiscall vec3b_resize(void *this,uint param_1);
void __thiscall World_buildVoxelMesh(void *this,undefined4 param_1,undefined4 param_2,int param_3,void *param_4,char param_5 );
void noop_return(void);
undefined4 __cdecl identity_return(undefined4 param_1);
void __thiscall cube::World::ctor_1(World *this,undefined4 param_1,World param_2);
void __fastcall cube::World::ctor_0(undefined4 *param_1);
undefined4 * __thiscall cube::World::vfunc_0(World *this,byte param_1);
float10 __thiscall World_roadField(void *param_1,uint param_2,uint param_3);
float10 __cdecl valueNoise2D(undefined4 param_1,undefined4 param_2,double param_3);
int World_featureTier(int param_1,int param_2);
void * __thiscall FUN_004d8f70(void *this,void *param_1);
void __thiscall FUN_004e25e0(void *this,uint param_1);
void __cdecl FUN_004f5cc0(float *param_1,float *param_2,int param_3,undefined4 param_4);
void __cdecl FUN_004f5f40(float *param_1,float *param_2,int param_3,undefined4 param_4);
void __cdecl FUN_004f61c0(undefined4 *param_1,int param_2);
void __cdecl FUN_004f6330(undefined4 *param_1,int param_2);
void __cdecl FUN_004f64a0(undefined4 *param_1,float *param_2,float *param_3);
void __cdecl FUN_004f6a60(undefined4 *param_1,float *param_2,float *param_3);
void __thiscall FUN_004f7ef0(void *this,uint param_1);
void __thiscall World_temperatureBlend(void *this,float param_1,uint param_2);
void __thiscall World_humidityBlend(void *this,int param_1,int param_2);
void __thiscall World_baseHeightField(void *this,uint param_1,float param_2,int param_3);
int * __thiscall World_generateRegionSite(void *this,int param_1,int param_2);
void __thiscall World_generateRegionFeatures (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this,int param_1, int param_2);
void __thiscall World_featureCountRange(void *this,undefined4 *param_1,undefined4 *param_2);
void World_siteDistanceSq(void);
float * World_terrainOffset2D(float *param_1,int param_2,int param_3);
void __thiscall FUN_005286a0(void *this,undefined4 *param_1);
float10 __thiscall World_objectFalloffWeight(uint *param_1,uint *param_2,uint *param_3);
float10 __thiscall World_riverClimateGate(void *param_1,uint param_2,float param_3,int param_4);
void __thiscall World_waterDepthField(void *this,uint param_1,uint param_2);
float10 __thiscall World_falloffSquared(uint *param_1,uint *param_2,uint *param_3);
void __thiscall World_getField0(void *this,undefined4 *param_1);
ulonglong __fastcall FUN_0054a910(undefined4 param_1,undefined4 param_2);

#endif
