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
undefined4 * __thiscall pair_set2(void *this,undefined4 param_1,undefined4 param_2);
void __thiscall deref_getFirst(void *this,undefined4 *param_1);
void __thiscall World_loadVoxelModel(void *this,char *param_1,void *param_2,char *param_3);
undefined1 * __thiscall vec3b_resize(void *this,uint param_1);
void __thiscall World_buildVoxelMesh(void *this,undefined4 param_1,undefined4 param_2,int param_3,void *param_4,char param_5 );
void noop_return(void);
undefined4 __cdecl identity_return(undefined4 param_1);
void __thiscall cube::World::ctor_1(World *this,undefined4 param_1,World param_2);
void __fastcall cube::World::ctor_0(undefined4 *param_1);
undefined4 * __thiscall cube::World::vfunc_0(World *this,byte param_1);
void __thiscall World_baseHeightField(void *this,uint param_1,float param_2,int param_3);
float10 __thiscall World_objectFalloffWeight(uint *param_1,uint *param_2,uint *param_3);
float10 __thiscall World_riverClimateGate(void *param_1,uint param_2,float param_3,int param_4);
void __thiscall World_waterDepthField(void *this,uint param_1,uint param_2);
void __thiscall World_getField0(void *this,undefined4 *param_1);

#endif
