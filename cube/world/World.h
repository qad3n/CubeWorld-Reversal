// World (cube) — reconstructed declarations.
#ifndef CUBE_WORLD_WORLD_H
#define CUBE_WORLD_WORLD_H
#include "../include/cube_types.h"

void std_Sort(int param_1,int param_2,int param_3,undefined4 param_4);
void std_Sort_heap(undefined4 *param_1,int param_2,undefined4 param_3);
void std_Unguarded_partition(undefined4 *param_1,int *param_2,int *param_3,undefined4 param_4);
void std_list_list_const_458df0(undefined4 *param_1);
void std_list_list_const_458f30(undefined4 *param_1);
void std_list_list_const_458fd0(undefined4 *param_1);
void cube::World::updateNearbyEntities(void);
void cube::World::updateActiveChunks(void);
void std_vector_reserve(uint param_1);
undefined4 GameController_check_tile_walkable(int param_1,int param_2);
int * std_list_Erase_node(int *param_1,int *param_2);
void cube::World::updateObjectLabels(void);
void EntityState_serializeToBuffer(int *param_1,int param_2,int param_3,undefined4 param_4);
void format_object_singular_name(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4, undefined4 param_5);
void Pair_CopyFromRefs(undefined4 *param_1,undefined4 *param_2);
undefined4 Identity_ReturnArg(undefined4 param_1);
void cube::World::ctor_1(undefined4 param_1,undefined1 param_2);
void cube::World::ctor_0(void);
void World_MapInsertChunk(int *param_1);
void World_MapInsertKeyed(int param_1);
void cube::World::vfunc_0(byte param_1);
undefined4 Terrain_sampleBlockAt_fwd(undefined4 param_1,undefined1 *param_2);
undefined2 * WorldMap_lookupTileValue2(undefined2 *param_1,int param_2,int param_3);
void NameGen_generateRegionName(undefined2 *param_1,uint param_2,int param_3);
int FUN_006023b0(uint param_1,uint param_2);

#endif
