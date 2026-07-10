// Creature (server) — reconstructed declarations.
#ifndef SERVER_ENTITY_CREATURE_H
#define SERVER_ENTITY_CREATURE_H
#include "../include/cube_types.h"

undefined4 * __thiscall Creature_zeroInit(void *this,undefined4 param_1);
undefined4 * __thiscall cube::Creature::ctor_1(Creature *this,undefined4 *param_1);
undefined4 * __fastcall Creature_construct(undefined4 *param_1);
void __fastcall cube::Creature::ctor_0(undefined4 *param_1);
void __fastcall Creature_destruct(int param_1);
undefined4 * __thiscall cube::Creature::vfunc_0(Creature *this,byte param_1);
undefined4 * __thiscall Creature_mapEraseRange(void *this,undefined4 *param_1,int *param_2,int *param_3);
void __thiscall Creature_mapEraseNode_str(void *this,undefined4 *param_1,int *param_2);
undefined4 * __thiscall Creature_mapEraseRange_v2(void *this,undefined4 *param_1,int *param_2,int *param_3);
void __thiscall Creature_mapEraseNode_vec(void *this,undefined4 *param_1,int *param_2);

#endif
