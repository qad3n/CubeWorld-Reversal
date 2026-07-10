// RandomInteractionBehavior (server) — reconstructed declarations.
#ifndef SERVER_AI_RANDOMINTERACTIONBEHAVIOR_H
#define SERVER_AI_RANDOMINTERACTIONBEHAVIOR_H
#include "../include/cube_types.h"

int RandomBehavior_listEmplaceCopy(undefined4 *param_1,undefined4 *param_2,undefined1 *param_3);
void * __thiscall RandomBehavior_copy(void *this,undefined1 *param_1);
undefined2 * __fastcall RandomBehavior_init(undefined2 *param_1);
undefined4 * __fastcall cube::RandomInteractionBehavior::ctor_0(undefined4 *param_1);
void __thiscall cube::RandomInteractionBehavior::vfunc_0 (RandomInteractionBehavior *this,void *param_1,void *param_2,int param_3);
undefined4 * cube::RandomInteractionBehavior::vfunc_1(void);
void __thiscall World_vec3i_pushBack(void *this,undefined4 *param_1);
int __thiscall RandomInteractionBehavior_findObjectAtPos(void *this,int param_1,int param_2,int param_3);

#endif
