// CombatBehavior (cube) — reconstructed declarations.
#ifndef CUBE_AI_COMBATBEHAVIOR_H
#define CUBE_AI_COMBATBEHAVIOR_H
#include "../include/cube_types.h"

void struct_clearFields(void);
void cube::CombatBehavior::ctor_0(undefined4 param_1);
void cube::CombatBehavior::vfunc_0(float param_1,float param_2,int param_3,undefined4 param_4);
undefined4 * cube::CombatBehavior::vfunc_1(void);
undefined8 combat_findTopThreat(void);
undefined4 CombatBehavior_chooseAttack(void);
void CombatBehavior_pushHitEntry(int param_1,undefined8 *param_2,int param_3);
undefined1 CombatBehavior_isHostileTo(int param_1,int param_2);
void CombatController_acquireNearbyTargets(int param_1,int param_2,int param_3);

#endif
