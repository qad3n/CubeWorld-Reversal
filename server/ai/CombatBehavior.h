// CombatBehavior (server) — reconstructed declarations.
#ifndef SERVER_AI_COMBATBEHAVIOR_H
#define SERVER_AI_COMBATBEHAVIOR_H
#include "../include/cube_types.h"

undefined1 * __fastcall CombatState_zeroInit(undefined1 *param_1);
undefined4 * __thiscall cube::CombatBehavior::ctor_0(CombatBehavior *this,undefined4 param_1);
undefined1 * __thiscall Struct_copy0x118(void *this,undefined1 *param_1);
undefined4 * __thiscall Vec3i64_copyAndScale(void *this,undefined4 *param_1,uint param_2,int param_3);
uint * __thiscall Vec3i64_scaleFixed(void *this,uint param_1,int param_2);
void __thiscall cube::CombatBehavior::vfunc_0 (CombatBehavior *this,void *param_1,void *param_2,int param_3,int param_4);
undefined4 * __fastcall cube::CombatBehavior::vfunc_1(int param_1);
int __thiscall Combat_getAbilityCooldown(void *this,uint param_1);
int __fastcall Combat_getWindupAndRecovery(int param_1);
bool __thiscall Combat_canCastAbility(void *this,int param_1);
void __thiscall Combat_mapLowerBound(void *this,int *param_1,int *param_2);
int __thiscall Combat_getAbilityCastTime(void *this,uint param_1);
uint __fastcall Combat_isBlockingState(int param_1);
int __fastcall Combat_isRangedOrSpecialOpcode(int param_1);
uint __fastcall Combat_isSpiritChanneling(int param_1);
uint __fastcall Combat_isMeleeSwingOpcode(int param_1);
float10 __thiscall Combat_getAbilityResourceCost(int param_1,undefined4 param_2,int param_3);
undefined8 __fastcall Combat_findTopThreatTarget(int param_1);
undefined4 __fastcall Combat_updateAttackState(int param_1);
undefined4 __fastcall Combat_updateAbilityAndProc(int param_1);
void __thiscall Combat_getProjectileSpawnPos(void *this,uint *param_1);
int __thiscall Combat_getAbilityRecovery(void *this,uint param_1);
float10 __fastcall Combat_computeAttackSpeed(int param_1);
float10 __fastcall Combat_sumEquipAttackBonus(int param_1);
float10 __fastcall Combat_equipSpeedBonus(char *param_1);
void CombatBehavior_pushTargetPos(void *param_1,char *param_2,int param_3);
int CombatBehavior_areHostile(int param_1,int param_2);
void CombatBehavior_alertNearbyAllies(int param_1,int param_2,int param_3);
void __thiscall CombatBehavior_pushAlertMsg(void *this,undefined8 *param_1);

#endif
