// CombatBehavior (ai) — cube. 9 functions. Bodies = Ghidra pseudo-C.
#include "CombatBehavior.h"

/* [AUDIT] proposed: struct::clearFields  (confidence: low)
 * purpose: Zeroes fields at +0,+4,+8,+0x10,+0x14 (init small struct/state block)
 * vars: -
 */
/* Global::struct_clearFields @ 0042c520 */

void struct_clearFields(void)

{
  undefined1 *self;
  
  *self = 0;
  *(undefined4 *)(self + 4) = 0;
  *(undefined4 *)(self + 8) = 0;
  *(undefined4 *)(self + 0x10) = 0;
  *(undefined4 *)(self + 0x14) = 0;
  return;
}




/* cube::CombatBehavior::ctor_0 @ 0042c550 */

void cube::CombatBehavior::ctor_0(undefined4 owner)

{
  undefined4 *self;
  
  *self = vftable;
  self[1] = 20000;
  self[2] = owner;
  self[3] = 0;
  self[4] = 0;
  return;
}




/* cube::CombatBehavior::vfunc_0 @ 0042cb20 */

/* WARNING: Removing unreachable block (ram,0x0042e1a6) */
/* WARNING: Removing unreachable block (ram,0x0042df4d) */
/* WARNING: Type propagation algorithm not settling */

void cube::CombatBehavior::vfunc_0(float creature,float param_2,int param_3,undefined4 world)

{
  uint *puVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  uint uVar5;
  void *pvVar7;
  int *piVar8;
  char aiState;
  uint uVar10;
  int cooldown;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  float *pfVar17;
  float in_ECX;
  int iVar18;
  bool bVar19;
  float10 fVar20;
  float fVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  int *itemEntry;
  int *piVar26;
  float fVar27;
  longlong lVar28;
  undefined8 uVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined4 uVar32;
  undefined1 auStack_31c [4];
  int *local_318;
  float local_314;
  float param2Saved;
  int local_30c;
  int *local_308;
  char local_301;
  int *local_300;
  float deltaTime;
  char local_2f5;
  uint *local_2f4;
  int *distance;
  int *local_2ec;
  float local_2e8;
  float fStack_2e4;
  float local_2e0;
  int iStack_2dc;
  int iStack_2d8;
  undefined4 uStack_2d4;
  float fStack_2d0;
  undefined4 local_2cc;
  int iStack_2c8;
  int iStack_2c4;
  undefined4 uStack_2c0;
  int *local_2bc;
  int iStack_2b8;
  int iStack_2b4;
  undefined4 uStack_2b0;
  void *pvStack_2ac;
  int iStack_2a8;
  undefined4 uStack_2a4;
  ulonglong uStack_2a0;
  ulonglong uStack_298;
  undefined8 uStack_290;
  undefined4 uStack_284;
  int local_280;
  int local_27c [3];
  int aiStack_270 [6];
  int aiStack_258 [12];
  undefined8 local_228;
  float fStack_21c;
  float fStack_218;
  int *piStack_214;
  float local_210;
  float local_20c;
  int *local_208;
  float fStack_204;
  float fStack_200;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float fStack_1ec;
  float fStack_1e8;
  int iStack_1e0;
  int iStack_1dc;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  int local_1c8;
  int iStack_1c4;
  int local_1c0;
  int iStack_1bc;
  int local_1b8;
  int iStack_1b4;
  int local_1b0;
  int iStack_1ac;
  int local_1a8;
  int iStack_1a4;
  int local_1a0;
  int iStack_19c;
  undefined4 uStack_194;
  undefined4 uStack_190;
  float fStack_18c;
  undefined8 local_188;
  undefined1 local_17c [12];
  undefined1 auStack_170 [24];
  undefined1 auStack_158 [24];
  undefined1 auStack_140 [24];
  undefined1 auStack_128 [24];
  undefined1 auStack_110 [24];
  undefined1 auStack_f8 [24];
  undefined1 auStack_e0 [24];
  undefined1 auStack_c8 [24];
  undefined1 auStack_b0 [24];
  undefined1 auStack_98 [24];
  undefined1 auStack_80 [24];
  undefined1 auStack_68 [24];
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [28];
  uint stackCookie;
  void *savedExceptionList;
  undefined1 *sehHandler;
  undefined4 trylevel;
  uint uVar6;
  
  trylevel = 0xffffffff;
  sehHandler = &LAB_006e21cc;
  savedExceptionList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)auStack_31c;
  uVar10 = DAT_0076aa78 ^ (uint)&stack0xfffffcd8;
  ExceptionList = &savedExceptionList;
  local_2cc = world;
  local_2f4 = (uint *)((int)creature + 0x10);
  *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) & 0xfffb;
  aiState = *(char *)((int)creature + 0x68);
  local_2e8 = creature;
  param2Saved = param_2;
  if ((((aiState != 'S') && (aiState != 'R')) && (aiState != 'T')) &&
     ((aiState != 'O' && (10000 < *(int *)((int)creature + 0x6c))))) {
    *(undefined1 *)((int)creature + 0x68) = 0;
  }
  deltaTime = in_ECX;
  local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228);
  if ((*(int *)((int)creature + 0x128) != 0) ||
     ((*(char *)((int)creature + 0x68) == 'P' &&
      (local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228),
      *(int *)((int)creature + 0x6c) < 3000)))) goto LAB_0042eec0;
  distance = *(int **)((int)creature + 0x16c);
  fVar20 = (float10)stat_calcAttackDamage(uVar10);
  local_308 = (int *)(float)fVar20;
  if (((float)distance < (float)local_308 * 0.25) &&
     (cooldown = combat_getAttackTiming(), cooldown < *(int *)((int)creature + 0x6c))) {
    for (puVar13 = *(undefined4 **)((int)creature + 0x11dc);
        puVar13 != *(undefined4 **)((int)creature + 0x11e0); puVar13 = puVar13 + 3) {
      for (itemEntry = (int *)*puVar13; itemEntry != (int *)puVar13[1]; itemEntry = itemEntry + 0x47) {
        if (((*itemEntry != 0) && ((char)itemEntry[1] == '\x01')) &&
           (*(char *)((int)itemEntry + 5) == '\x01')) {
          *(undefined1 *)((int)creature + 0x68) = 0x50;
          *(undefined4 *)((int)creature + 0x6c) = 0;
          Item_copyStruct(itemEntry + 1);
          *itemEntry = *itemEntry + -1;
          if (*itemEntry < 1) {
            *itemEntry = 0;
            *(undefined1 *)(itemEntry + 1) = 0;
            *(undefined1 *)((int)itemEntry + 5) = 0;
          }
          cooldown = rand();
          local_308 = (int *)(((float)cooldown * 4.0) / 32767.0 - 2.0);
          cooldown = rand();
          *(int **)((int)creature + 0x40) = local_308;
          *(undefined4 *)((int)creature + 0x48) = 0;
          *(float *)((int)creature + 0x44) = ((float)cooldown * 4.0) / 32767.0 - 2.0;
          goto LAB_0042eec0;
        }
      }
    }
  }
  local_228 = combat_findTopThreat();
  local_318 = (int *)((int)param_2 + 4);
  rbtree_lowerBound_pairKey(aiStack_270 + 5,&local_228);
  cooldown = *(int *)((int)param_2 + 4);
  if (aiStack_270[5] == cooldown) {
    local_30c = 0;
  }
  else {
    local_30c = *(int *)(aiStack_270[5] + 0x18);
  }
  iVar18 = local_30c;
  if (*(char *)((int)creature + 0x60) == '\x05') {
    rbtree_lowerBound_pairKey(&local_280,(int)creature + 0x198);
    iVar18 = local_30c;
    if ((local_280 == cooldown) || (iVar14 = *(int *)(local_280 + 0x18), iVar14 == 0))
    goto LAB_0042ce36;
    iVar18 = 0;
    local_30c = 0;
    if (*(char *)(iVar14 + 0x68) == 'j') goto LAB_0042eec0;
    itemEntry = *(int **)(iVar14 + 0x13ac);
    local_2bc = (int *)*itemEntry;
    local_2ec = (int *)0x0;
    creature = local_2e8;
    if (local_2bc != itemEntry) {
      do {
        distance = (int *)local_2bc[6];
        if ((float)local_2ec < (float)distance) {
          local_308 = local_2bc + 4;
          rbtree_lowerBound_pairKey(local_27c,local_308);
          if ((local_27c[0] != cooldown) && (*(int *)(local_27c[0] + 0x18) != 0)) {
            rbtree_lowerBound_pairKey(local_27c + 2,local_308);
            if (local_27c[2] == cooldown) {
              iVar18 = 0;
            }
            else {
              iVar18 = *(int *)(local_27c[2] + 0x18);
            }
            local_2ec = distance;
          }
        }
        rbtree_iterator_increment();
        creature = local_2e8;
      } while (local_2bc != itemEntry);
      goto LAB_0042ce36;
    }
LAB_0042ce7c:
    cooldown = local_30c;
    distance = *(int **)((int)creature + 0x16c);
    fVar20 = (float10)stat_calcAttackDamage();
    local_308 = (int *)(float)fVar20;
    if (((float)distance < (float)local_308 * 0.5) && (*(char *)((int)creature + 0x60) == '\x03')) {
      *(undefined1 *)((int)creature + 0x68) = 0x50;
      *(undefined4 *)((int)creature + 0x6c) = 0;
      *(undefined2 *)((int)creature + 0x1e8) = 0x401;
      *(undefined2 *)((int)creature + 0x1f8) = *(undefined2 *)((int)creature + 400);
      *(undefined4 *)((int)creature + 0x40) = 0;
      *(undefined4 *)((int)creature + 0x44) = 0;
      *(undefined4 *)((int)creature + 0x48) = 0;
      goto LAB_0042eec0;
    }
  }
  else {
LAB_0042ce36:
    local_30c = iVar18;
    cooldown = local_30c;
    if (local_30c == 0) goto LAB_0042ce7c;
  }
  itemEntry = (int *)((int)deltaTime + 4);
  *itemEntry = *itemEntry - param_3;
  uVar12 = *(undefined4 *)((int)deltaTime + 4);
  if (*itemEntry < 0) {
    uVar12 = 0;
  }
  *(undefined4 *)((int)deltaTime + 4) = uVar12;
  local_2f5 = '\0';
  for (puVar13 = (undefined4 *)**(undefined4 **)((int)creature + 0x1178);
      puVar13 != *(undefined4 **)((int)creature + 0x1178); puVar13 = (undefined4 *)*puVar13) {
    if (*(char *)(puVar13 + 2) == '\b') {
      local_2f5 = '\x01';
      break;
    }
  }
  if (cooldown == 0) {
    if (((*(char *)((int)creature + 0x60) != '\x05') ||
        (*(int *)((int)creature + 0x198) == 0 && *(int *)((int)creature + 0x19c) == 0)) &&
       (*(int *)((int)deltaTime + 0x10) < 1)) {
      piVar26 = (int *)(*(float *)((int)deltaTime + 8) * *(float *)((int)deltaTime + 8));
      itemEntry = *(int **)*local_318;
      piVar16 = local_318;
      local_300 = piVar26;
      if (itemEntry != (int *)*local_318) {
        do {
          fVar27 = local_2e8;
          fVar23 = (float)itemEntry[6];
          local_314 = fVar23;
          if (((fVar23 != 0.0) && (fVar23 != creature)) &&
             ((0.0 < *(float *)((int)fVar23 + 0x16c) && (*(char *)((int)fVar23 + 0x60) != '\x05'))))
          {
            distance = *(int **)((int)fVar23 + 0x24);
            local_1b0 = *(uint *)((int)fVar23 + 0x10) - *local_2f4;
            iStack_1ac = (*(int *)((int)fVar23 + 0x14) - local_2f4[1]) -
                         (uint)(*(uint *)((int)fVar23 + 0x10) < *local_2f4);
            local_1a8 = *(uint *)((int)fVar23 + 0x18) - *(uint *)((int)local_2e8 + 0x18);
            iStack_1a4 = (*(int *)((int)fVar23 + 0x1c) - *(int *)((int)local_2e8 + 0x1c)) -
                         (uint)(*(uint *)((int)fVar23 + 0x18) < *(uint *)((int)local_2e8 + 0x18));
            local_1a0 = *(uint *)((int)fVar23 + 0x20) - *(uint *)((int)local_2e8 + 0x20);
            iStack_19c = (int)distance +
                         (-(uint)(*(uint *)((int)fVar23 + 0x20) < *(uint *)((int)local_2e8 + 0x20))
                         - *(int *)((int)local_2e8 + 0x24));
            local_1f8 = (float)CONCAT44(iStack_1ac,local_1b0) * 1.5258789e-05;
            local_308 = (int *)(float)CONCAT44(iStack_19c,local_1a0);
            local_1f4 = (float)CONCAT44(iStack_1a4,local_1a8) * 1.5258789e-05;
            local_1f0 = (float)local_308 * 1.5258789e-05;
            local_2ec = (int *)(local_1f4 * local_1f4 + local_1f8 * local_1f8 +
                               local_1f0 * local_1f0);
            if (0.0 < *(float *)((int)fVar23 + 0x1190)) {
              dVar22 = 1.5;
              libm_sse2_pow_precise();
              fVar23 = 1.0 - (float)dVar22 * *(float *)((int)fVar23 + 0x1190);
              if (fVar23 < 0.1) {
                fVar23 = 0.1;
              }
              local_2ec = (int *)((float)local_2ec / (fVar23 * fVar23));
              piVar26 = local_300;
            }
            piVar16 = local_318;
            cooldown = local_30c;
            creature = fVar27;
            if ((local_2f5 == '\0') && ((float)local_2ec < (float)piVar26)) {
              aiState = CombatBehavior_isHostileTo(fVar27,itemEntry[6]);
              if ((aiState != '\0') ||
                 ((((piVar16 = local_318, cooldown = local_30c, piVar26 = local_300,
                    *(char *)((int)fVar27 + 0x60) == '\x05' &&
                    (*(int *)((int)fVar27 + 0x198) == 0 && *(int *)((int)fVar27 + 0x19c) == 0)) &&
                   (iVar18 = itemEntry[6], *(char *)(iVar18 + 0x68) == 'R')) &&
                  ((*(char *)(iVar18 + 0x1020) == '\x14' &&
                   ((uint)*(byte *)(iVar18 + 0x1021) == *(uint *)((int)fVar27 + 100))))))) {
                aiState = Entity_stepToward((int)fVar27 + 0x10,itemEntry[6] + 0x10,1,0x43480000);
                piVar16 = local_318;
                cooldown = local_30c;
                piVar26 = local_300;
                if (aiState != '\0') {
                  aiState = ability_isChanneled();
                  piVar16 = local_318;
                  if ((aiState == '\0') ||
                     (((iVar18 = itemEntry[6], cooldown = local_30c, piVar26 = local_300,
                       *(char *)(iVar18 + 0x68) == 'R' && (*(char *)(iVar18 + 0x1020) == '\x14')) &&
                      ((uint)*(byte *)(iVar18 + 0x1021) == *(uint *)((int)fVar27 + 100))))) {
                    local_30c = itemEntry[6];
                    local_300 = local_2ec;
                    cooldown = local_30c;
                    piVar26 = local_2ec;
                  }
                }
              }
            }
          }
          if (*(char *)((int)itemEntry + 0xd) == '\0') {
            piVar4 = (int *)itemEntry[2];
            if (*(char *)((int)piVar4 + 0xd) == '\0') {
              aiState = *(char *)(*piVar4 + 0xd);
              itemEntry = piVar4;
              piVar4 = (int *)*piVar4;
              while (aiState == '\0') {
                aiState = *(char *)(*piVar4 + 0xd);
                itemEntry = piVar4;
                piVar4 = (int *)*piVar4;
              }
            }
            else {
              aiState = *(char *)(itemEntry[1] + 0xd);
              piVar8 = (int *)itemEntry[1];
              piVar4 = itemEntry;
              while ((itemEntry = piVar8, aiState == '\0' && (piVar4 == (int *)itemEntry[2]))) {
                aiState = *(char *)(itemEntry[1] + 0xd);
                piVar8 = (int *)itemEntry[1];
                piVar4 = itemEntry;
              }
            }
          }
        } while (itemEntry != (int *)*piVar16);
        if (cooldown != 0) {
          puVar13 = (undefined4 *)rbtree_findOrInsert_pairKey(cooldown + 8);
          *puVar13 = 0x3f800000;
          CombatController_acquireNearbyTargets(cooldown,creature,local_2cc);
          goto LAB_0042d237;
        }
      }
    }
LAB_0042d268:
    bVar19 = false;
  }
  else {
LAB_0042d237:
    if (*(char *)((int)creature + 0x68) != '\0') {
      iVar18 = combat_getStaminaCost(0xffffffff);
      iVar14 = combat_getAttackWindup(0xffffffff);
      iVar15 = combat_getReloadFrames(0xffffffff);
      if (*(int *)((int)creature + 0x6c) <= iVar15 + iVar18 / 2 + iVar14) goto LAB_0042d268;
    }
    bVar19 = true;
  }
  fVar23 = local_2e8;
  iVar18 = local_30c;
  if (bVar19) {
    *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) | 0x40;
  }
  else {
    *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) & 0xffbf;
  }
  itemEntry = (int *)((int)deltaTime + 0x10);
  *itemEntry = *itemEntry - param_3;
  uVar12 = *(undefined4 *)((int)deltaTime + 0x10);
  if (*itemEntry < 0) {
    uVar12 = 0;
  }
  *(undefined4 *)((int)deltaTime + 0x10) = uVar12;
  if (cooldown == 0) {
    *(undefined4 *)((int)deltaTime + 0xc) = 0;
    goto LAB_0042eec0;
  }
  local_300 = (int *)(cooldown + 0x10);
  local_1c8 = *(uint *)(cooldown + 0x10) - *local_2f4;
  iStack_1c4 = (*(int *)(cooldown + 0x14) - local_2f4[1]) -
               (uint)(*(uint *)(cooldown + 0x10) < *local_2f4);
  local_1c0 = *(uint *)(cooldown + 0x18) - *(uint *)((int)local_2e8 + 0x18);
  iStack_1bc = (*(int *)(cooldown + 0x1c) - *(int *)((int)local_2e8 + 0x1c)) -
               (uint)(*(uint *)(cooldown + 0x18) < *(uint *)((int)local_2e8 + 0x18));
  local_1b8 = *(uint *)(cooldown + 0x20) - *(uint *)((int)local_2e8 + 0x20);
  iStack_1b4 = (*(int *)(cooldown + 0x24) - *(int *)((int)local_2e8 + 0x24)) -
               (uint)(*(uint *)(cooldown + 0x20) < *(uint *)((int)local_2e8 + 0x20));
  local_210 = (float)CONCAT44(iStack_1c4,local_1c8) * 1.5258789e-05;
  local_314 = (float)CONCAT44(iStack_1b4,local_1b8);
  local_20c = (float)CONCAT44(iStack_1bc,local_1c0) * 1.5258789e-05;
  local_2ec = (int *)(local_314 * 1.5258789e-05);
  local_318 = (int *)(*(float *)((int)local_2e8 + 0x80) * 2.0 + *(float *)(local_30c + 0x80));
  local_208 = local_2ec;
  local_301 = Entity_stepToward((int)local_2e8 + 0x10,local_30c + 0x10,1,0x43480000);
  aiState = creature_hasFireAffinity();
  if ((aiState != '\0') && (local_301 != '\0')) {
    aiState = *(char *)((int)fVar23 + 0x68);
    if ((aiState == 'W') || ((aiState == 'V' || (aiState == 'Y')))) {
      cooldown = combat_getAttackWindup(0xffffffff);
      if (*(int *)((int)fVar23 + 0x6c) < cooldown) goto LAB_0042d427;
    }
    local_318 = (int *)0x42480000;
  }
LAB_0042d427:
  cooldown = *(int *)((int)fVar23 + 100);
  if ((((cooldown == 0x2f) || (cooldown == 0x6f)) || (cooldown == 0x71)) || (cooldown == 0x70)) {
    local_318 = (int *)0x41a00000;
  }
  aiState = *(char *)((int)fVar23 + 0x68);
  if (((aiState == '_') || (aiState == '\x1c')) || (aiState == 'l')) {
    local_318 = (int *)0x42480000;
  }
  if (aiState == 'H') {
    local_318 = (int *)(*(float *)((int)fVar23 + 0x80) + *(float *)(iVar18 + 0x80));
  }
  distance = (int *)0x0;
  if ((*(int *)((int)deltaTime + 4) == 0) &&
     (cooldown = *(int *)((int)fVar23 + 0x13e8), cooldown != *(int *)((int)fVar23 + 0x13ec))) {
    iVar14 = *(int *)((int)fVar23 + 0x13ec);
    uVar10 = rand();
    distance = *(int **)(*(int *)((int)fVar23 + 0x13e8) +
                         (uVar10 % (uint)(iVar14 - cooldown >> 2)) * 4);
    if ((distance == (int *)0x5d) ||
       (((distance == (int *)0x5b || (distance == (int *)0x44)) || (distance == (int *)0x45)))) {
      local_318 = (int *)0x41a00000;
    }
    if ((distance == (int *)0x56) || (distance == (int *)0x59)) {
      local_318 = (int *)(*(float *)((int)fVar23 + 0x80) * 2.0 + *(float *)(iVar18 + 0x80));
    }
  }
  if (local_301 == '\0') {
    local_318 = (int *)0x3f800000;
  }
  local_308 = (int *)((float)local_318 * (float)local_318);
  fVar27 = local_20c * local_20c + local_210 * local_210;
  local_314 = (float)local_2ec * (float)local_2ec + fVar27;
  if (((float)local_308 < local_314) || (local_301 == '\0')) {
    *(int *)((int)deltaTime + 0xc) = *(int *)((int)deltaTime + 0xc) + param_3;
    if (*(int *)((int)deltaTime + 0xc) < 0x4e21) {
      if ((*(char *)((int)fVar23 + 0x68) == '_') || (*(char *)((int)fVar23 + 0x68) == '\x1c')) {
        *(undefined1 *)((int)fVar23 + 0x68) = 0;
      }
      if ((*(byte *)((int)fVar23 + 0x5c) & 2) == 0) {
        local_2ec = (int *)0x0;
      }
      fVar27 = (float)local_2ec * (float)local_2ec + fVar27;
      itemEntry = local_2ec;
      fVar24 = local_20c;
      fVar21 = local_210;
      if (0.0 < fVar27) {
        dVar22 = (double)fVar27;
        libm_sse2_sqrt_precise();
        fVar24 = 1.0 / (float)dVar22;
        fVar21 = fVar24 * local_210;
        itemEntry = (int *)(fVar24 * (float)local_2ec);
        fVar24 = fVar24 * local_20c;
      }
      fVar27 = 80.0;
      if (fVar24 * fVar24 + fVar21 * fVar21 + (float)itemEntry * (float)itemEntry <
          (float)local_308 * 4.0) {
        fVar27 = 40.0;
      }
      *(float *)((int)fVar23 + 0x40) = fVar21 * fVar27;
      *(float *)((int)fVar23 + 0x44) = fVar24 * fVar27;
      *(float *)((int)fVar23 + 0x48) = (float)itemEntry * fVar27;
      if (local_301 != '\0') {
        aiState = vec_normalize_or_distance(fVar23,(undefined4 *)((int)fVar23 + 0x10),iVar18 + 0x10,local_318);
        if ((aiState != '\0') && ((*(byte *)((int)fVar23 + 0x5c) & 0x20) == 0)) {
          GameController_clearContainers();
          goto LAB_0042eec0;
        }
      }
      pfVar17 = (float *)rbtree_findOrInsert_pairKey(iVar18 + 8);
      *pfVar17 = *pfVar17 * 0.9;
      if ((*(int *)((int)fVar23 + 0x1464) == 0) && ((*(byte *)(iVar18 + 0x5c) & 7) != 0)) {
        *(undefined4 *)((int)fVar23 + 0x1440) = *(undefined4 *)(iVar18 + 0x10);
        *(undefined4 *)((int)fVar23 + 0x1444) = *(undefined4 *)(iVar18 + 0x14);
        *(undefined4 *)((int)fVar23 + 0x1448) = *(undefined4 *)(iVar18 + 0x18);
        *(undefined4 *)((int)fVar23 + 0x144c) = *(undefined4 *)(iVar18 + 0x1c);
        *(undefined4 *)((int)fVar23 + 0x1450) = *(undefined4 *)(iVar18 + 0x20);
        *(undefined4 *)((int)fVar23 + 0x1454) = *(undefined4 *)(iVar18 + 0x24);
        local_2e0 = (*(float *)(iVar18 + 0x88) * 0.5 - 0.1) * 65536.0;
        uVar29 = float_to_uint64_round();
        puVar1 = (uint *)((int)fVar23 + 0x1450);
        uVar10 = *puVar1;
        *puVar1 = *puVar1 - (uint)uVar29;
        *(int *)((int)fVar23 + 0x1454) =
             (*(int *)((int)fVar23 + 0x1454) - (int)((ulonglong)uVar29 >> 0x20)) -
             (uint)(uVar10 < (uint)uVar29);
        *(undefined4 *)((int)fVar23 + 0x1428) = *(undefined4 *)((int)fVar23 + 0x10);
        *(undefined4 *)((int)fVar23 + 0x142c) = *(undefined4 *)((int)fVar23 + 0x14);
        *(undefined4 *)((int)fVar23 + 0x1430) = *(undefined4 *)((int)fVar23 + 0x18);
        *(undefined4 *)((int)fVar23 + 0x1434) = *(undefined4 *)((int)fVar23 + 0x1c);
        *(undefined4 *)((int)fVar23 + 0x1438) = *(undefined4 *)((int)fVar23 + 0x20);
        *(undefined4 *)((int)fVar23 + 0x143c) = *(undefined4 *)((int)fVar23 + 0x24);
        local_2e0 = (*(float *)((int)fVar23 + 0x88) * 0.5 - 0.1) * 65536.0;
        uVar29 = float_to_uint64_round();
        puVar1 = (uint *)((int)fVar23 + 0x1438);
        uVar10 = *puVar1;
        *puVar1 = *puVar1 - (uint)uVar29;
        *(int *)((int)fVar23 + 0x143c) =
             (*(int *)((int)fVar23 + 0x143c) - (int)((ulonglong)uVar29 >> 0x20)) -
             (uint)(uVar10 < (uint)uVar29);
        *(float *)((int)fVar23 + 0x1458) =
             *(float *)((int)fVar23 + 0x80) + *(float *)(iVar18 + 0x80);
        Creature_expandNeighbors(fVar23);
      }
      if (*(int *)((int)fVar23 + 0x1410) != 0) {
        cooldown = 0;
        itemEntry = (int *)((int)fVar23 + 0x1428);
        do {
          if ((*itemEntry != itemEntry[6]) || (itemEntry[1] != itemEntry[7])) {
            cooldown = 0;
            goto LAB_0042ee21;
          }
          cooldown = cooldown + 1;
          itemEntry = itemEntry + 2;
        } while (cooldown < 3);
      }
    }
    else {
      distance = (int *)((int)fVar23 + 0x13a4);
      pvVar7 = *(void **)(*(int *)((int)fVar23 + 0x13a4) + 4);
      if (*(char *)((int)pvVar7 + 0xd) == '\0') {
        rbtree_destroyRec_simple(*(undefined4 *)((int)pvVar7 + 8));
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar7);
      }
      *(int *)(*distance + 4) = *distance;
      *(int *)*distance = *distance;
      *(int *)(*distance + 8) = *distance;
      *(undefined4 *)((int)fVar23 + 0x13a8) = 0;
      GameController_clearContainers();
      *(undefined4 *)((int)deltaTime + 0x10) = 3000;
      *(undefined4 *)((int)deltaTime + 0xc) = 0;
    }
    goto LAB_0042eec0;
  }
  *(undefined4 *)((int)deltaTime + 0xc) = 0;
  GameController_clearContainers();
  fVar27 = local_2e8;
  *(undefined4 *)((int)fVar23 + 0x13e0) = 0;
  *(undefined4 *)((int)fVar23 + 0x40) = 0;
  *(undefined4 *)((int)fVar23 + 0x44) = 0;
  *(undefined4 *)((int)fVar23 + 0x48) = 0;
  if ((((((local_2f5 == '\0') && (*(char *)(iVar18 + 0x68) == 'R')) &&
        (*(char *)(iVar18 + 0x1020) == '\x14')) &&
       ((uint)*(byte *)(iVar18 + 0x1021) == *(uint *)((int)fVar23 + 100))) &&
      ((*(char *)((int)fVar23 + 0x60) != '\x05' ||
       (*(int *)((int)fVar23 + 0x198) == 0 && *(int *)((int)fVar23 + 0x19c) == 0)))) &&
     (local_314 <= (float)local_308)) {
    *(undefined4 *)((int)fVar23 + 0x11d0) = *(undefined4 *)(iVar18 + 8);
    *(undefined4 *)((int)fVar23 + 0x11d4) = *(undefined4 *)(iVar18 + 0xc);
    cooldown = combat_getAttackTiming();
    if (cooldown < *(int *)((int)fVar23 + 0x6c)) {
      if (*(char *)((int)fVar23 + 0x68) != 'n') {
        *(undefined4 *)((int)fVar23 + 0x70) = 0;
      }
      if (*(int *)((int)fVar23 + 0x70) < 5) {
        *(undefined1 *)((int)fVar23 + 0x68) = 0x6e;
        *(undefined4 *)((int)fVar23 + 0x6c) = 0;
      }
      else {
        local_301 = '\0';
        struct_clearFields();
        itemEntry = *(int **)((int)fVar23 + 0x1178);
        piVar16 = (int *)*itemEntry;
        aiState = local_301;
        if (piVar16 != itemEntry) {
          do {
            if ((char)piVar16[2] == '\a') {
              uStack_2a0 = *(ulonglong *)(piVar16 + 2);
              uStack_298 = *(ulonglong *)(piVar16 + 4);
              uStack_290 = *(undefined8 *)(piVar16 + 6);
              aiState = '\x01';
            }
            piVar16 = (int *)*piVar16;
          } while (piVar16 != itemEntry);
          iVar18 = local_30c;
          if (aiState != '\0') {
            uStack_298 = uStack_298 & 0xffffffff00000000;
            uStack_2a0 = uStack_2a0 & 0xffffffff;
            CombatBehavior_pushHitEntry(fVar23,&uStack_2a0,local_2cc);
          }
        }
        uStack_290 = *(undefined8 *)(iVar18 + 8);
        uStack_2a0 = CONCAT71(uStack_2a0._1_7_,8);
        uStack_298 = CONCAT44(uStack_298._4_4_,20000);
        uStack_2a0 = uStack_2a0 & 0xffffffff;
        CombatBehavior_pushHitEntry(fVar23,&uStack_2a0,local_2cc);
      }
    }
    goto LAB_0042eec0;
  }
  iStack_1e0 = *(uint *)(iVar18 + 0x10) - *local_2f4;
  iStack_1dc = (*(int *)(iVar18 + 0x14) - local_2f4[1]) -
               (uint)(*(uint *)(iVar18 + 0x10) < *local_2f4);
  iStack_1d8 = *(uint *)(iVar18 + 0x18) - *(uint *)((int)local_2e8 + 0x18);
  iStack_1d4 = (*(int *)(iVar18 + 0x1c) - *(int *)((int)local_2e8 + 0x1c)) -
               (uint)(*(uint *)(iVar18 + 0x18) < *(uint *)((int)local_2e8 + 0x18));
  iStack_1d0 = *(uint *)(iVar18 + 0x20) - *(uint *)((int)local_2e8 + 0x20);
  iStack_1cc = (*(int *)(iVar18 + 0x24) - *(int *)((int)local_2e8 + 0x24)) -
               (uint)(*(uint *)(iVar18 + 0x20) < *(uint *)((int)local_2e8 + 0x20));
  cooldown = (int)local_2e8 + 0x10;
  fStack_21c = (float)CONCAT44(iStack_1dc,iStack_1e0) * 1.5258789e-05;
  local_314 = (float)CONCAT44(iStack_1cc,iStack_1d0);
  fStack_218 = (float)CONCAT44(iStack_1d4,iStack_1d8) * 1.5258789e-05;
  *(ushort *)((int)local_2e8 + 0x124) = *(ushort *)((int)local_2e8 + 0x124) | 4;
  local_318 = (int *)(local_314 * 1.5258789e-05);
  param2Saved = fStack_218 * fStack_218 + fStack_21c * fStack_21c +
              (float)local_318 * (float)local_318;
  piStack_214 = local_318;
  if (distance != (int *)0x0) {
    *(undefined4 *)((int)deltaTime + 4) = 20000;
    *(char *)((int)local_2e8 + 0x68) = (char)distance;
    *(undefined4 *)((int)local_2e8 + 0x6c) = 0;
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    goto LAB_0042eb01;
  }
  iVar18 = *(int *)((int)local_2e8 + 100);
  if (iVar18 == 0x74) {
    cooldown = combat_getAttackTiming();
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
      pvStack_2ac = (void *)0x0;
      iStack_2a8 = 0;
      uStack_2a4 = 0;
      trylevel = 0;
      aiStack_258[5] = 0x45;
      std_vector_push_back_4byte(aiStack_258 + 5);
      aiStack_258[7] = 0x4a;
      std_vector_push_back_4byte(aiStack_258 + 7);
      aiStack_258[9] = 0x49;
      std_vector_push_back_4byte(aiStack_258 + 9);
      uVar10 = rand();
      *(undefined1 *)((int)fVar27 + 0x68) =
           *(undefined1 *)
            ((int)pvStack_2ac + (uVar10 % (uint)(iStack_2a8 - (int)pvStack_2ac >> 2)) * 4);
      *(undefined4 *)((int)fVar27 + 0x6c) = 0;
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
      if (pvStack_2ac != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvStack_2ac);
      }
    }
    goto LAB_0042eb01;
  }
  if (iVar18 == 0x76) {
    cooldown = combat_getAttackTiming();
    if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
      iStack_2c8 = 0;
      iStack_2c4 = 0;
      uStack_2c0 = 0;
      trylevel = 1;
      aiStack_258[0xb] = 7;
      std_vector_push_back_4byte(aiStack_258 + 0xb);
      aiStack_258[3] = 6;
      std_vector_push_back_4byte(aiStack_258 + 3);
      aiStack_258[2] = 0x14;
      std_vector_push_back_4byte(aiStack_258 + 2);
      if (*(short *)((int)fVar27 + 0x8c) == 0x86a) {
        local_27c[1] = 0x5f;
        itemEntry = local_27c + 1;
      }
      else {
        aiStack_258[10] = 0x56;
        itemEntry = aiStack_258 + 10;
      }
      std_vector_push_back_4byte(itemEntry);
      cooldown = iStack_2c8;
      iVar18 = iStack_2c4 - iStack_2c8;
      uVar10 = rand();
      fVar27 = local_2e8;
      trylevel = 0xffffffff;
      *(undefined1 *)((int)local_2e8 + 0x68) =
           *(undefined1 *)(cooldown + (uVar10 % (uint)(iVar18 >> 2)) * 4);
      *(undefined4 *)((int)local_2e8 + 0x6c) = 0;
      unwind_free_object();
    }
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    if (*(char *)((int)fVar27 + 0x68) == '_') {
      uVar12 = projectile_getMuzzlePosition(auStack_b0);
      uVar12 = vec3i64_copySub(auStack_158,uVar12);
      vec3i64_toFloat(uVar12);
      local_318 = piStack_214;
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
    }
    goto LAB_0042eb01;
  }
  if (((iVar18 == 0x2f) || (iVar18 == 0x6f)) || ((iVar18 == 0x71 || (iVar18 == 0x70)))) {
    cooldown = combat_getAttackTiming();
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
      iStack_2b8 = 0;
      iStack_2b4 = 0;
      uStack_2b0 = 0;
      trylevel = 2;
      aiStack_270[1] = 0x6c;
      std_vector_push_back_4byte(aiStack_270 + 1);
      aiStack_270[3] = 0x36;
      std_vector_push_back_4byte(aiStack_270 + 3);
      local_2e0 = 1.06499e-43;
      std_vector_push_back_4byte(&local_2e0);
      uVar10 = rand();
      aiState = *(char *)(iStack_2b8 + (uVar10 % (uint)(iStack_2b4 - iStack_2b8 >> 2)) * 4);
      *(char *)((int)fVar27 + 0x68) = aiState;
      *(undefined4 *)((int)fVar27 + 0x6c) = 0;
      if (aiState == '6') {
        uVar12 = 0x20000;
        uVar32 = 0;
        puVar30 = auStack_68;
        vec3i64_copySub(auStack_38,(int)fVar27 + 0x10);
        uVar12 = vec6_copyAndScale(puVar30,uVar12,uVar32);
        vec3i64_toFloat(uVar12);
        *(undefined4 *)((int)fVar27 + 0x3c) = 0x41700000;
      }
LAB_0042eaea:
      unwind_free_object();
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
    }
    goto LAB_0042eb01;
  }
  if (iVar18 == 0x77) {
    cooldown = combat_getAttackTiming();
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
      iStack_2dc = 0;
      iStack_2d8 = 0;
      uStack_2d4 = 0;
      sVar2 = *(short *)((int)fVar27 + 0x8c);
      trylevel = 3;
      if (((sVar2 == 0x863) || (sVar2 == 0x864)) || (sVar2 == 0x865)) {
        aiStack_258[4] = 0x45;
        itemEntry = aiStack_258 + 4;
      }
      else {
        aiStack_270[0] = 0x44;
        itemEntry = aiStack_270;
      }
      std_vector_push_back_4byte(itemEntry);
      if ((*(short *)((int)fVar27 + 0x96) == 0x867) || (*(short *)((int)fVar27 + 0x96) == 0x868)) {
        aiStack_270[2] = 0x46;
        std_vector_push_back_4byte(aiStack_270 + 2);
      }
      if ((*(short *)((int)fVar27 + 0x90) == 0x85f) || (*(short *)((int)fVar27 + 0x90) == 0x860)) {
        aiStack_270[4] = 0x4b;
        itemEntry = aiStack_270 + 4;
      }
      else {
        aiStack_258[8] = 0x4a;
        itemEntry = aiStack_258 + 8;
      }
      std_vector_push_back_4byte(itemEntry);
      if ((*(short *)((int)fVar27 + 0x94) == 0x85c) || (*(short *)((int)fVar27 + 0x94) == 0x85d)) {
        aiStack_258[6] = 0x4d;
        std_vector_push_back_4byte(aiStack_258 + 6);
        aiStack_258[0] = 0x4e;
        std_vector_push_back_4byte(aiStack_258);
      }
      sVar2 = *(short *)((int)fVar27 + 0x94);
      if ((((sVar2 == 0x857) || (sVar2 == 0x858)) || (sVar2 == 0x859)) ||
         ((sVar2 == 0x85a || (sVar2 == 0x85b)))) {
        aiStack_258[1] = 0x4c;
        std_vector_push_back_4byte(aiStack_258 + 1);
      }
      if (((*(char *)((int)fVar27 + 0x68) != 'G') && (*(char *)((int)fVar27 + 0x68) != 'H')) &&
         (*(short *)((int)fVar27 + 0x94) == 0x855)) {
        uVar10 = rand();
        uVar10 = uVar10 & 0x80000001;
        bVar19 = uVar10 == 0;
        if ((int)uVar10 < 0) {
          bVar19 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar19) {
          uStack_284 = 0x47;
          std_vector_push_back_4byte(&uStack_284);
        }
      }
      if (((*(char *)((int)fVar27 + 0x68) != 'G') && (*(char *)((int)fVar27 + 0x68) != 'H')) &&
         (*(short *)((int)fVar27 + 0x94) == 0x856)) {
        uVar10 = rand();
        uVar10 = uVar10 & 0x80000001;
        bVar19 = uVar10 == 0;
        if ((int)uVar10 < 0) {
          bVar19 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar19) {
          fStack_2d0 = 1.00893e-43;
          std_vector_push_back_4byte(&fStack_2d0);
        }
      }
      if (*(char *)((int)fVar27 + 0x68) != 'I') {
        fStack_2e4 = 1.02295e-43;
        std_vector_push_back_4byte(&fStack_2e4);
      }
      cooldown = iStack_2d8;
      if (iStack_2dc != iStack_2d8) {
        uVar10 = rand();
        *(undefined1 *)((int)fVar27 + 0x68) =
             *(undefined1 *)(iStack_2dc + (uVar10 % (uint)(cooldown - iStack_2dc >> 2)) * 4);
        *(undefined4 *)((int)fVar27 + 0x6c) = 0;
      }
      goto LAB_0042eaea;
    }
    goto LAB_0042eb01;
  }
  aiState = creature_hasWaterAffinity();
  fVar23 = fStack_218;
  fVar24 = fStack_21c;
  if (aiState != '\0') {
    if (3600.0 <= param2Saved) goto LAB_0042eb01;
    if (*(float *)((int)fVar27 + 0x170) <= 0.5) {
LAB_0042ddbc:
      combat_advanceAttackTimer();
    }
    else {
      uVar10 = rand();
      uVar10 = uVar10 & 0x80000001;
      bVar19 = uVar10 == 0;
      if ((int)uVar10 < 0) {
        bVar19 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar19) goto LAB_0042ddbc;
      CombatBehavior_chooseAttack();
    }
    aiState = *(char *)((int)fVar27 + 0x68);
    if (((aiState == '\x1e') || (aiState == '\x1f')) || ((aiState == ' ' || (aiState == '!')))) {
      iVar18 = combat_getAttackWindup(0xffffffff);
      if (iVar18 < *(int *)((int)fVar27 + 0x6c) - param_3) {
        uVar12 = vec3i64_copySub(auStack_110,cooldown);
        vec3i64_toFloat(uVar12);
        local_318 = piStack_214;
      }
      else {
        vec6_copy(local_30c + 0x1350);
      }
    }
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    if ((*(char *)((int)fVar27 + 0x68) == '\x1c') && (25.0 < param2Saved)) {
      fStack_2e4 = (float)*(int *)((int)fVar27 + 0x6c) * 0.005;
      dVar22 = (double)fStack_2e4;
      libm_sse2_cos_precise();
      fStack_2d0 = (float)dVar22 * 1.5 + fStack_21c;
      dVar22 = (double)fStack_2e4;
      libm_sse2_sin_precise();
      fVar23 = (float)dVar22 * 1.5 + fStack_218;
      fVar24 = fStack_2d0;
    }
    goto LAB_0042eb01;
  }
  if (*(int *)((int)fVar27 + 100) == 0x65) {
    if (64.0 <= param2Saved) {
      if (param2Saved < 3600.0) {
        iVar18 = combat_getAttackTiming();
        fVar23 = fStack_218;
        fVar24 = fStack_21c;
        if (iVar18 < *(int *)((int)fVar27 + 0x6c)) {
          *(undefined4 *)((int)fVar27 + 0x6c) = 0;
          *(undefined1 *)((int)fVar27 + 0x68) = 0x25;
          fStack_18c = *(float *)(local_30c + 0x88) * 0.4;
          uStack_194 = 0;
          uStack_190 = 0;
          vec3i64_setFromGen(&uStack_194);
          puVar30 = auStack_170;
          puVar31 = auStack_80;
          vec3i64_copySub(auStack_140,cooldown);
          uVar12 = vec3i64_copyAdd(puVar31,puVar30);
          vec3i64_toFloat(uVar12);
          fVar23 = fStack_218;
          fVar24 = fStack_21c;
        }
      }
    }
    else {
      uVar12 = vec3i64_copySub(auStack_50,cooldown);
      vec3i64_toFloat(uVar12);
      *(ushort *)((int)fVar27 + 0x124) = *(ushort *)((int)fVar27 + 0x124) | 4;
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
      if (2000 < *(int *)((int)fVar27 + 0x6c)) {
        uVar10 = rand();
        uVar10 = uVar10 & 0x80000001;
        bVar19 = uVar10 == 0;
        if ((int)uVar10 < 0) {
          bVar19 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar19) {
          uVar10 = *(uint *)((int)fVar27 + 0x20);
          uVar5 = *(uint *)(local_30c + 0x20);
          uVar6 = *(uint *)(local_30c + 0x20);
          cooldown = *(int *)((int)fVar27 + 0x24);
          iVar18 = *(int *)(local_30c + 0x24);
          lVar28 = float_to_uint64_round();
          if (CONCAT44((cooldown - iVar18) - (uint)(uVar10 < uVar5),uVar10 - uVar6) <= lVar28) {
            *(undefined4 *)((int)fVar27 + 0x3c) = 0x41f00000;
            fVar23 = fStack_218;
            fVar24 = fStack_21c;
            goto LAB_0042eb01;
          }
        }
        *(undefined4 *)((int)fVar27 + 0x6c) = 0;
        *(undefined1 *)((int)fVar27 + 0x68) = 0x33;
        uVar12 = vec3i64_copySub(auStack_e0,(int)fVar27 + 0x10);
        vec3i64_toFloat(uVar12);
        fVar23 = fStack_218;
        fVar24 = fStack_21c;
        if (0.0 < *(float *)((int)fVar27 + 0x34) * *(float *)((int)fVar27 + 0x34) +
                  *(float *)((int)fVar27 + 0x38) * *(float *)((int)fVar27 + 0x38) +
                  *(float *)((int)fVar27 + 0x3c) * *(float *)((int)fVar27 + 0x3c)) {
          fStack_2e4 = *(float *)((int)fVar27 + 0x34);
          dVar22 = (double)(fStack_2e4 * fStack_2e4 +
                            *(float *)((int)fVar27 + 0x38) * *(float *)((int)fVar27 + 0x38) +
                           *(float *)((int)fVar27 + 0x3c) * *(float *)((int)fVar27 + 0x3c));
          libm_sse2_sqrt_precise();
LAB_0042e000:
          fVar23 = 1.0 / (float)dVar22;
          *(float *)((int)fVar27 + 0x34) = fStack_2e4 * fVar23;
          *(float *)((int)fVar27 + 0x38) = *(float *)((int)fVar27 + 0x38) * fVar23;
          *(float *)((int)fVar27 + 0x3c) = *(float *)((int)fVar27 + 0x3c) * fVar23;
          *(float *)((int)fVar27 + 0x34) = *(float *)((int)fVar27 + 0x34) * 10.0;
          *(float *)((int)fVar27 + 0x38) = *(float *)((int)fVar27 + 0x38) * 10.0;
          *(float *)((int)fVar27 + 0x3c) = *(float *)((int)fVar27 + 0x3c) * 10.0;
          fVar23 = fStack_218;
          fVar24 = fStack_21c;
        }
      }
    }
    goto LAB_0042eb01;
  }
  uVar3 = *(ushort *)((int)fVar27 + 0x7e);
  if (((uVar3 & 2) != 0) && ((uVar3 & 0x10) != 0)) {
    *(ushort *)((int)fVar27 + 0x124) = *(ushort *)((int)fVar27 + 0x124) & 0xfffb;
    if (param2Saved < 64.0) {
      uVar12 = vec3i64_copySub(auStack_128,cooldown);
      vec3i64_toFloat(uVar12);
      *(ushort *)((int)fVar27 + 0x124) = *(ushort *)((int)fVar27 + 0x124) | 4;
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
      if (2000 < *(int *)((int)fVar27 + 0x6c)) {
        uVar10 = rand();
        uVar10 = uVar10 & 0x80000001;
        bVar19 = uVar10 == 0;
        if ((int)uVar10 < 0) {
          bVar19 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar19) {
          uVar10 = *(uint *)((int)fVar27 + 0x20);
          uVar5 = *(uint *)(local_30c + 0x20);
          uVar6 = *(uint *)(local_30c + 0x20);
          cooldown = *(int *)((int)fVar27 + 0x24);
          iVar18 = *(int *)(local_30c + 0x24);
          lVar28 = float_to_uint64_round();
          if (CONCAT44((cooldown - iVar18) - (uint)(uVar10 < uVar5),uVar10 - uVar6) <= lVar28) {
            *(undefined4 *)((int)fVar27 + 0x3c) = 0x40a00000;
            fVar23 = fStack_218;
            fVar24 = fStack_21c;
            goto LAB_0042eb01;
          }
        }
        *(undefined4 *)((int)fVar27 + 0x6c) = 0;
        *(undefined1 *)((int)fVar27 + 0x68) = 0x33;
        uVar12 = vec3i64_copySub(auStack_f8,(int)fVar27 + 0x10);
        vec3i64_toFloat(uVar12);
        fVar23 = fStack_218;
        fVar24 = fStack_21c;
        if (0.0 < *(float *)((int)fVar27 + 0x34) * *(float *)((int)fVar27 + 0x34) +
                  *(float *)((int)fVar27 + 0x38) * *(float *)((int)fVar27 + 0x38) +
                  *(float *)((int)fVar27 + 0x3c) * *(float *)((int)fVar27 + 0x3c)) {
          fStack_2e4 = *(float *)((int)fVar27 + 0x34);
          dVar22 = (double)(fStack_2e4 * fStack_2e4 +
                            *(float *)((int)fVar27 + 0x38) * *(float *)((int)fVar27 + 0x38) +
                           *(float *)((int)fVar27 + 0x3c) * *(float *)((int)fVar27 + 0x3c));
          libm_sse2_sqrt_precise();
          goto LAB_0042e000;
        }
      }
    }
    goto LAB_0042eb01;
  }
  if ((((*(int *)((int)fVar27 + 100) != 0x68) &&
       (aiState = *(char *)((int)fVar27 + 0xaa9), aiState != '\x06')) && (aiState != '\a')) &&
     (aiState != '\b')) {
    if ((uVar3 & 0x10) == 0) {
      if ((uVar3 & 8) == 0) {
        fVar21 = (*(float *)((int)fVar27 + 0x80) + *(float *)(local_30c + 0x80)) * 3.0;
        if (param2Saved < fVar21 * fVar21) {
          aiState = *(char *)((int)fVar27 + 0x68);
          if (((aiState != ';') && (aiState != '?')) &&
             ((aiState != '\b' && (*(int *)((int)fVar27 + 0x128) == 0)))) {
            iVar18 = rand();
            if (iVar18 % 10 == 0) {
              aiState = creature_isBossType();
              if ((aiState == '\0') &&
                 (*(float *)((int)fVar27 + 0x80) <= 2.0 && *(float *)((int)fVar27 + 0x80) != 2.0)) {
                iVar18 = combat_getAttackTiming();
                if ((iVar18 <= *(int *)((int)fVar27 + 0x6c)) &&
                   ((*(byte *)((int)fVar27 + 0x5c) & 3) != 0)) {
                  uVar12 = vec3i64_copySub(auStack_c8,cooldown);
                  vec3i64_toFloat(uVar12);
                  fVar21 = fStack_1e8 * fStack_1e8 + fStack_1ec * fStack_1ec + 0.0;
                  fVar23 = fStack_218;
                  fVar24 = fStack_21c;
                  if (0.0 < fVar21) {
                    dVar22 = (double)fVar21;
                    libm_sse2_sqrt_precise();
                    param2Saved = 1.0 / (float)dVar22;
                    deltaTime = fStack_1ec * param2Saved;
                    local_2f4 = (uint *)(fStack_1e8 * param2Saved);
                    param2Saved = param2Saved * 0.0;
                    uVar10 = rand();
                    uVar10 = uVar10 & 0x80000003;
                    if ((int)uVar10 < 0) {
                      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
                    }
                    switch(uVar10) {
                    case 0:
                      goto LAB_0042e44d;
                    case 1:
                      goto LAB_0042e885;
                    case 2:
                      goto LAB_0042e47d;
                    case 3:
                      goto LAB_0042e4d2;
                    }
                    goto LAB_0042e525;
                  }
                  goto LAB_0042eb01;
                }
              }
            }
          }
          if ((((*(float *)((int)fVar27 + 0x170) < 0.8) &&
               (aiState = *(char *)((int)fVar27 + 0x68), aiState != ';')) && (aiState != '?')) &&
             (aiState != '\b')) goto LAB_0042e2d3;
          fVar23 = fStack_218;
          fVar24 = fStack_21c;
          if (*(int *)((int)fVar27 + 0x128) == 0) {
            cooldown = combat_getAttackTiming();
            fVar23 = fStack_218;
            fVar24 = fStack_21c;
            if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
              if (*(char *)((int)fVar27 + 0xaa9) == '\x05') {
                *(undefined1 *)((int)fVar27 + 0x68) = 5;
                *(undefined4 *)((int)fVar27 + 0x6c) = 0;
              }
              else if ((*(char *)((int)fVar27 + 0xaa8) == '\0') ||
                      (*(char *)((int)fVar27 + 0x990) != '\0')) {
                aiState = *(char *)((int)fVar27 + 0x991);
                if (aiState == '\r') {
                  if (*(char *)((int)fVar27 + 0x68) == '\b') {
                    if (*(float *)((int)fVar27 + 0x170) <= *(float *)((int)fVar27 + 0x144)) {
                      *(undefined1 *)((int)fVar27 + 0x68) = 0x68;
                      *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                      goto LAB_0042eb01;
                    }
                  }
                  else {
                    *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                  }
                  *(undefined1 *)((int)fVar27 + 0x68) = 8;
                }
                else if (aiState == '\x03') {
                  *(undefined1 *)((int)fVar27 + 0x68) = 0x11;
                  *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                }
                else if (aiState == '\x04') {
                  *(undefined1 *)((int)fVar27 + 0x68) = 0x14;
                  *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                }
                else if (*(char *)((int)fVar27 + 0xaa8) == '\0') {
                  aiState = ability_isUsable(0x36);
                  if (aiState == '\0') {
                    CombatBehavior_chooseAttack();
                    fVar23 = fStack_218;
                    fVar24 = fStack_21c;
                  }
                  else {
LAB_0042e615:
                    *(float *)((int)fVar27 + 0x3c) = *(float *)((int)fVar27 + 0x3c) + 20.0;
                    *(undefined1 *)((int)fVar27 + 0x68) = 0x36;
                    *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                    fVar23 = fStack_218;
                    fVar24 = fStack_21c;
                  }
                }
                else if ((*(char *)((int)fVar27 + 0x68) != '?') ||
                        (*(float *)((int)fVar27 + 0x144) < *(float *)((int)fVar27 + 0x170))) {
                  aiState = ability_isUsable(0x36);
                  if (aiState != '\0') goto LAB_0042e615;
                  if (*(char *)((int)fVar27 + 0x68) != '?') {
                    *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                  }
                  *(undefined1 *)((int)fVar27 + 0x68) = 0x3f;
                  fVar23 = fStack_218;
                  fVar24 = fStack_21c;
                }
                else {
                  *(undefined1 *)((int)fVar27 + 0x68) = 0xb;
                  uVar12 = combat_getAttackWindup(0xffffffff);
                  *(undefined4 *)((int)fVar27 + 0x6c) = uVar12;
                  fVar23 = fStack_218;
                  fVar24 = fStack_21c;
                }
              }
              else if ((*(char *)((int)fVar27 + 0x68) != ';') ||
                      (*(float *)((int)fVar27 + 0x144) < *(float *)((int)fVar27 + 0x170))) {
                aiState = ability_isUsable(0x36);
                if (aiState != '\0') goto LAB_0042e615;
                if (*(char *)((int)fVar27 + 0x68) != ';') {
                  *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                }
                *(undefined1 *)((int)fVar27 + 0x68) = 0x3b;
                fVar23 = fStack_218;
                fVar24 = fStack_21c;
              }
              else if (*(char *)((int)fVar27 + 0x141) == '\x01') {
                *(undefined1 *)((int)fVar27 + 0x68) = 0x3d;
                *(undefined4 *)((int)fVar27 + 0x6c) = 0;
              }
              else {
                *(undefined1 *)((int)fVar27 + 0x68) = 0x3c;
                uVar12 = combat_getAttackWindup(0xffffffff);
                *(undefined4 *)((int)fVar27 + 0x6c) = uVar12;
                fVar23 = fStack_218;
                fVar24 = fStack_21c;
              }
            }
          }
        }
      }
      else {
LAB_0042e2d3:
        combat_advanceAttackTimer();
        fVar23 = fStack_218;
        fVar24 = fStack_21c;
      }
    }
    else {
      cooldown = combat_getAttackTiming();
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
      if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
        if (*(int *)((int)fVar27 + 100) == 0x19) {
          aiState = ability_isUsable(0x48);
          if (aiState != '\0') {
            *(undefined1 *)((int)fVar27 + 0x68) = 0x48;
            *(undefined4 *)((int)fVar27 + 0x6c) = 0;
            fVar23 = fStack_218;
            fVar24 = fStack_21c;
            goto LAB_0042eb01;
          }
        }
        *(undefined1 *)((int)fVar27 + 0x68) = 0x4b;
        *(undefined4 *)((int)fVar27 + 0x6c) = 0;
        fVar23 = fStack_218;
        fVar24 = fStack_21c;
      }
    }
    goto LAB_0042eb01;
  }
  if (3600.0 <= param2Saved) goto LAB_0042eb01;
  aiState = *(char *)((int)fVar27 + 0x68);
  if ((((aiState == '\x18') || (aiState == '\x19')) || (aiState == '\x1b')) ||
     (*(int *)((int)fVar27 + 0x128) != 0)) {
LAB_0042e8bf:
    if ((((*(float *)((int)fVar27 + 0x170) < 0.8) &&
         (aiState = *(char *)((int)fVar27 + 0x68), aiState != '\x18')) && (aiState != '\x19')) &&
       (aiState != '\x1b')) goto LAB_0042e2d3;
    fVar23 = fStack_218;
    fVar24 = fStack_21c;
    if (*(int *)((int)fVar27 + 0x128) == 0) {
      cooldown = combat_getAttackTiming();
      fVar23 = fStack_218;
      fVar24 = fStack_21c;
      if (cooldown < *(int *)((int)fVar27 + 0x6c)) {
        aiState = *(char *)((int)fVar27 + 0xaa8);
        if (aiState == '\0') {
LAB_0042e9b1:
          if (*(int *)((int)fVar27 + 100) == 0x68) {
LAB_0042e9bb:
            if (*(char *)((int)fVar27 + 0x68) == '\x19') {
              if (*(float *)((int)fVar27 + 0x170) <= *(float *)((int)fVar27 + 0x144)) {
                *(undefined1 *)((int)fVar27 + 0x68) = 0x37;
                *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                goto LAB_0042eb01;
              }
            }
            else {
              *(undefined4 *)((int)fVar27 + 0x6c) = 0;
            }
            *(undefined1 *)((int)fVar27 + 0x68) = 0x19;
          }
        }
        else {
          if (*(char *)((int)fVar27 + 0xaa9) != '\a') {
            if (aiState == '\0') goto LAB_0042e9b1;
            if (*(char *)((int)fVar27 + 0xaa9) == '\b') {
              if (*(char *)((int)fVar27 + 0x68) == '\x1b') {
                if (*(float *)((int)fVar27 + 0x170) <= *(float *)((int)fVar27 + 0x144)) {
                  *(undefined1 *)((int)fVar27 + 0x68) = 0x1a;
                  *(undefined4 *)((int)fVar27 + 0x6c) = 0;
                  goto LAB_0042eb01;
                }
              }
              else {
                *(undefined4 *)((int)fVar27 + 0x6c) = 0;
              }
              *(undefined1 *)((int)fVar27 + 0x68) = 0x1b;
              goto LAB_0042eb01;
            }
            if ((aiState == '\0') || (*(char *)((int)fVar27 + 0xaa9) != '\x06')) goto LAB_0042e9b1;
            goto LAB_0042e9bb;
          }
          if (*(char *)((int)fVar27 + 0x68) == '\x18') {
            if (*(float *)((int)fVar27 + 0x170) <= *(float *)((int)fVar27 + 0x144)) {
              *(undefined1 *)((int)fVar27 + 0x68) = 0x16;
              *(undefined4 *)((int)fVar27 + 0x6c) = 0;
              goto LAB_0042eb01;
            }
          }
          else {
            *(undefined4 *)((int)fVar27 + 0x6c) = 0;
          }
          *(undefined1 *)((int)fVar27 + 0x68) = 0x18;
        }
      }
    }
    goto LAB_0042eb01;
  }
  iVar18 = rand();
  if (iVar18 % 10 != 0) goto LAB_0042e8bf;
  aiState = creature_isBossType();
  if ((aiState != '\0') ||
     (2.0 < *(float *)((int)fVar27 + 0x80) || *(float *)((int)fVar27 + 0x80) == 2.0))
  goto LAB_0042e8bf;
  iVar18 = combat_getAttackTiming();
  if ((*(int *)((int)fVar27 + 0x6c) < iVar18) || ((*(byte *)((int)fVar27 + 0x5c) & 3) == 0))
  goto LAB_0042e8bf;
  uVar12 = vec3i64_copySub(auStack_98,cooldown);
  vec3i64_toFloat(uVar12);
  fVar21 = fStack_200 * fStack_200 + fStack_204 * fStack_204 + 0.0;
  fVar23 = fStack_218;
  fVar24 = fStack_21c;
  if (fVar21 <= 0.0) goto LAB_0042eb01;
  dVar22 = (double)fVar21;
  libm_sse2_sqrt_precise();
  param2Saved = 1.0 / (float)dVar22;
  deltaTime = fStack_204 * param2Saved;
  local_2f4 = (uint *)(fStack_200 * param2Saved);
  param2Saved = param2Saved * 0.0;
  uVar10 = rand();
  uVar10 = uVar10 & 0x80000003;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
  }
  switch(uVar10) {
  case 0:
LAB_0042e44d:
    fVar23 = deltaTime * 20.0;
    fVar24 = (float)local_2f4 * 20.0;
    *(float *)((int)fVar27 + 0x3c) = param2Saved * 20.0;
    goto LAB_0042e51b;
  case 1:
LAB_0042e885:
    *(float *)((int)fVar27 + 0x34) = deltaTime * -20.0;
    *(float *)((int)fVar27 + 0x38) = (float)local_2f4 * -20.0;
    *(float *)((int)fVar27 + 0x3c) = param2Saved * -20.0;
    break;
  case 2:
LAB_0042e47d:
    *(float *)((int)fVar27 + 0x34) = ((float)local_2f4 - param2Saved * 0.0) * 20.0;
    *(float *)((int)fVar27 + 0x38) = (param2Saved * 0.0 - deltaTime) * 20.0;
    *(float *)((int)fVar27 + 0x3c) = (deltaTime * 0.0 - (float)local_2f4 * 0.0) * 20.0;
    break;
  case 3:
LAB_0042e4d2:
    fVar23 = ((float)local_2f4 - param2Saved * 0.0) * -20.0;
    fVar24 = (param2Saved * 0.0 - deltaTime) * -20.0;
    *(float *)((int)fVar27 + 0x3c) = (deltaTime * 0.0 - (float)local_2f4 * 0.0) * -20.0;
LAB_0042e51b:
    *(float *)((int)fVar27 + 0x38) = fVar24;
    *(float *)((int)fVar27 + 0x34) = fVar23;
  }
LAB_0042e525:
  *(float *)((int)fVar27 + 0x3c) = *(float *)((int)fVar27 + 0x3c) + 5.0;
  *(undefined4 *)((int)fVar27 + 0x128) = 600;
  fVar23 = fStack_218;
  fVar24 = fStack_21c;
LAB_0042eb01:
  *(float *)((int)fVar27 + 0x160) = fVar24;
  *(float *)((int)fVar27 + 0x164) = fVar23;
  *(int **)((int)fVar27 + 0x168) = local_318;
LAB_0042eec0:
  ExceptionList = savedExceptionList;
  __security_check_cookie(stackCookie ^ (uint)auStack_31c);
  return;
  while( true ) {
    if (*(int *)((int)fVar23 + 0x1464) != 0) {
      iVar18 = *(int *)(*(int *)((int)fVar23 + 0x1460) + 4);
      itemEntry = (int *)vec3i64_toIntFloor(local_17c,(int)fVar23 + 0x1440);
      uVar29 = *(undefined8 *)(iVar18 + 8);
      iVar15 = *(int *)(iVar18 + 0x10) - itemEntry[2];
      local_188._4_4_ = (int)((ulonglong)uVar29 >> 0x20);
      iVar18 = local_188._4_4_ - itemEntry[1];
      local_188._0_4_ = (int)uVar29;
      iVar14 = (int)local_188 - *itemEntry;
      local_188 = uVar29;
      if ((float)(iVar15 * iVar15 + iVar18 * iVar18 + iVar14 * iVar14) <=
          *(float *)((int)fVar23 + 0x80) * *(float *)((int)fVar23 + 0x80)) break;
    }
    Creature_runPathfindingLoop(fVar23);
    Pathfinding_reconstructPath(fVar23);
    cooldown = cooldown + 1;
    if (9 < cooldown) break;
LAB_0042ee21:
    if (0x32 < *(int *)((int)fVar23 + 0x1464)) break;
  }
  goto LAB_0042eec0;
}




/* cube::CombatBehavior::vfunc_1 @ 0042efc0 */

undefined4 * cube::CombatBehavior::vfunc_1(void)

{
  undefined4 *clone;
  int self;
  
  clone = operator_new(0x14);
  if (clone != (undefined4 *)0x0) {
    *clone = vftable;
    clone[1] = *(undefined4 *)(self + 4);
    clone[2] = *(undefined4 *)(self + 8);
    clone[3] = 0;
    clone[4] = 0;
    return clone;
  }
  return (undefined4 *)0x0;
}




/* [AUDIT] proposed: combat::findTopThreat  (confidence: med)
 * purpose: Traverses threat RB-tree (+0x13a4) returning (id,val) pair with highest weight (+6)
 * vars: tree +0x13a4; weight +6
 */
/* Global::combat_findTopThreat @ 00444bf0 */

undefined8 combat_findTopThreat(void)

{
  char cVar1;
  int *treeRoot;
  int *child;
  int *parent;
  int *node;
  int self;
  int bestLo;
  float bestScore;
  int bestHi;
  
  treeRoot = *(int **)(self + 0x13a4);
  node = (int *)*treeRoot;
  bestScore = 0.0;
  if (node != treeRoot) {
    bestHi = 0;
    bestLo = 0;
    do {
      if ((node[4] != 0 || node[5] != 0) && (bestScore <= (float)node[6])) {
        bestLo = node[4];
        bestHi = node[5];
        bestScore = (float)node[6];
      }
      if (*(char *)((int)node + 0xd) == '\0') {
        child = (int *)node[2];
        if (*(char *)((int)child + 0xd) == '\0') {
          cVar1 = *(char *)(*child + 0xd);
          node = child;
          child = (int *)*child;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*child + 0xd);
            node = child;
            child = (int *)*child;
          }
        }
        else {
          cVar1 = *(char *)(node[1] + 0xd);
          parent = (int *)node[1];
          child = node;
          while ((node = parent, cVar1 == '\0' && (child == (int *)node[2]))) {
            cVar1 = *(char *)(node[1] + 0xd);
            parent = (int *)node[1];
            child = node;
          }
        }
      }
    } while (node != treeRoot);
    return CONCAT44(bestHi,bestLo);
  }
  return 0;
}




/* [AUDIT] proposed: CombatBehavior::chooseAttack  (confidence: med)
 * purpose: Core combat AI: computes windup/variant, checks resources/target, picks next attack id and sub-costs
 * vars: +0x68 weapon; +0x128 casting
 */
/* Global::CombatBehavior_chooseAttack @ 004456a0 */

undefined4 CombatBehavior_chooseAttack(void)

{
  int *buffList;
  bool isSpecial;
  char attackType;
  int recoverTime;
  int windup;
  int *buff;
  int self;
  float10 fVar7;
  float10 extraout_ST0;
  float base;
  float rate;
  
  recoverTime = combat_getAttackTiming();
  if (*(int *)(self + 0x70) == 0) goto LAB_00445830;
  switch(*(undefined1 *)(self + 0x68)) {
  case 0:
  case 0x32:
  case 0x60:
    windup = 100;
    goto LAB_0044582e;
  default:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 500.0;
    break;
  case 3:
  case 4:
  case 5:
  case 0x3e:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 300.0;
    break;
  case 7:
  case 0xe:
  case 0x12:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 200.0;
    break;
  case 10:
    windup = 600;
    goto LAB_0044582e;
  case 0xb:
  case 0x3c:
  case 0x3d:
  case 0x68:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 100.0;
    break;
  case 0xf:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 400.0;
    break;
  case 0x16:
  case 0x1a:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x5e:
  case 0x5f:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 100.0;
    break;
  case 0x17:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 10.0;
    break;
  case 0x30:
    windup = 0;
    goto LAB_0044582e;
  case 0x36:
    windup = 400;
    goto LAB_0044582e;
  case 0x39:
  case 0x3a:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 300.0;
    break;
  case 0x41:
  case 0x42:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 200.0;
    break;
  case 0x43:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 100.0;
    break;
  case 0x44:
  case 0x45:
  case 0x5d:
    fVar7 = (float10)combat_getEffectiveHaste();
    rate = (float)fVar7;
    base = 800.0;
    break;
  case 0x47:
  case 0x48:
    windup = 200;
    goto LAB_0044582e;
  }
  windup = (int)(base / (rate * *(float *)(self + 0x17c)));
LAB_0044582e:
  recoverTime = recoverTime - windup;
LAB_00445830:
  windup = combat_selectAttackVariant();
  if (((*(char *)(self + 0x140) == '\x04') && (*(char *)(self + 0x141) == '\x01')) &&
     ((windup == 0x11 || ((windup == 5 || (windup == 0x14)))))) {
    isSpecial = true;
  }
  else {
    isSpecial = false;
  }
  if ((*(int *)(self + 0x6c) < recoverTime) ||
     (((*(int *)(self + 0x128) != 0 && (!isSpecial)) ||
      (ability_getResourceCost(windup,0xffffffff),
      *(float *)(self + 0x170) <= (float)extraout_ST0 &&
      (float)extraout_ST0 != *(float *)(self + 0x170))))) {
    return 0;
  }
  attackType = combat_selectAttackVariant();
  *(char *)(self + 0x68) = attackType;
  *(undefined4 *)(self + 0x6c) = 0;
  if (((attackType == '%') || (attackType == '.')) ||
     ((attackType == '_' || ((attackType == '\x1f' || (attackType == '!')))))) {
    buffList = *(int **)(self + 0x1178);
    buff = (int *)*buffList;
    if (buff != buffList) {
LAB_004458d7:
      if ((char)buff[2] != '\t') goto code_r0x004458dd;
      if (buff != (int *)0xfffffff8) {
        switch(attackType) {
        case '\0':
        case '\b':
        case '\v':
        case '\x1c':
        case '2':
        case '7':
        case '<':
        case '=':
        case '>':
        case '`':
        case 'b':
        case 'h':
          recoverTime = 0;
          goto LAB_00445d49;
        case '\x01':
        case '\t':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 300.0;
          break;
        case '\x02':
        case '\x03':
        case '\x04':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 100.0;
          break;
        case '\x05':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 100.0;
          break;
        case '\x06':
        case '\a':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(50.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '\n':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 100.0;
          break;
        case '\f':
        case '\x10':
        case 'C':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 200.0;
          break;
        case '\r':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 200.0;
          break;
        case '\x0e':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 100.0;
          break;
        case '\x0f':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 200.0;
          break;
        case '\x11':
        case '\x12':
        case '\x13':
        case '\x14':
        case '\x15':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 100.0;
          break;
        case '\x16':
          fVar7 = (float10)combat_getEffectiveHaste();
          goto LAB_00445d31;
        case '\x17':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(50.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '\x18':
        case '\x19':
        case '\x1b':
        case '$':
        case ';':
        case '?':
        case '@':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(50.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '\x1a':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 300.0;
          break;
        default:
          fVar7 = (float10)combat_getEffectiveHaste();
LAB_00445d31:
          rate = (float)fVar7;
          base = 400.0;
          break;
        case '\x1e':
        case ' ':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 800.0;
          break;
        case '\x1f':
        case '!':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(1600.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '\"':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(1600.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '%':
        case '+':
        case 'Y':
          if (*(char *)(self + 0xaa9) == '\f') {
            fVar7 = (float10)combat_getEffectiveHaste();
            recoverTime = (int)(600.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          }
          else {
            fVar7 = (float10)combat_getEffectiveHaste();
            recoverTime = (int)(1200.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          }
          goto LAB_00445d49;
        case '&':
        case ',':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 500.0;
          break;
        case '\'':
        case '(':
        case ')':
        case '*':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 200.0;
          break;
        case '-':
        case '.':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(1200.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '0':
        case 'e':
          recoverTime = 100;
          goto LAB_00445d49;
        case '6':
          recoverTime = 400;
          goto LAB_00445d49;
        case '9':
        case ':':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 800.0;
          break;
        case 'A':
        case 'B':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 300.0;
          break;
        case 'D':
        case 'E':
        case 'F':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 300.0;
          break;
        case 'G':
        case 'H':
          recoverTime = 200;
          goto LAB_00445d49;
        case 'W':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(5000.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case '[':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(1000.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case ']':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 800.0;
          break;
        case '^':
          fVar7 = (float10)combat_getEffectiveHaste();
          rate = (float)fVar7;
          base = 500.0;
          break;
        case '_':
          fVar7 = (float10)combat_getEffectiveHaste();
          recoverTime = (int)(1000.0 / ((float)fVar7 * *(float *)(self + 0x17c)));
          goto LAB_00445d49;
        case 'i':
          recoverTime = 5000;
          goto LAB_00445d49;
        }
        recoverTime = (int)(base / (rate * *(float *)(self + 0x17c)));
LAB_00445d49:
        *(int *)(self + 0x6c) = recoverTime;
      }
    }
  }
LAB_00445d4c:
  if (!isSpecial) {
    *(undefined4 *)(self + 0x128) = 0;
  }
  return 1;
code_r0x004458dd:
  buff = (int *)*buff;
  if (buff == buffList) goto LAB_00445d4c;
  goto LAB_004458d7;
}




/* [AUDIT] proposed: CombatBehavior::pushHitEntry  (confidence: med)
 * purpose: Builds a positional record from param_2/param_1 and appends node to a std::list at param_3 (count +0x5c)
 * vars: param_3+0x5c=list size; 0x5555554=list max; 0x58=list head
 */
/* Global::CombatBehavior_pushHitEntry @ 005957c0 */

void CombatBehavior_pushHitEntry(int projectile,undefined8 *pos,int entity)

{
  int list;
  int node;
  undefined4 hitInfo;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 posCopy;
  undefined8 local_14;
  undefined8 local_c;
  
  statusList_upsert(pos);
  posCopy = *pos;
  hitInfo = *(undefined4 *)(projectile + 8);
  local_28 = *(undefined4 *)(projectile + 0xc);
  local_14 = pos[1];
  local_c = pos[2];
  list = *(int *)(entity + 0x58);
  local_24 = hitInfo;
  local_20 = local_28;
  node = map_insertVal_5x64payload(list,*(undefined4 *)(list + 4),&hitInfo);
  if (*(int *)(entity + 0x5c) == 0x5555554) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("list<T> too long");
  }
  *(int *)(entity + 0x5c) = *(int *)(entity + 0x5c) + 1;
  *(int *)(list + 4) = node;
  **(int **)(node + 4) = node;
  return;
}




/* [AUDIT] proposed: CombatBehavior::isHostileTo  (confidence: high)
 * purpose: Returns whether two creatures may fight based on faction byte +0x60 and flags +0x124 (0x20 bit)
 * vars: +0x60=faction/type (5=friendly,6=passive,1=player); +0x124&0x20=aggro flag
 */
/* Global::CombatBehavior_isHostileTo @ 00596ca0 */

undefined1 CombatBehavior_isHostileTo(int entityA,int entityB)

{
  char typeA;
  char factionB;
  
  typeA = *(char *)(entityA + 0x60);
  if ((((typeA == '\x05') && (*(char *)(entityB + 0x60) == '\0')) || (typeA == '\x06')) ||
     (*(char *)(entityB + 0x60) == '\x06')) {
    return 0;
  }
  if (typeA == '\x01') {
    if (*(char *)(entityB + 0x60) != '\x01') {
      return 1;
    }
    typeA = ability_isChanneled();
    factionB = ability_isChanneled();
    if (factionB != typeA) {
      return 1;
    }
  }
  if (*(char *)(entityB + 0x60) == '\x01') {
    if (*(char *)(entityA + 0x60) != '\x01') {
      return 1;
    }
    typeA = ability_isChanneled();
    factionB = ability_isChanneled();
    if (typeA != factionB) {
      return 1;
    }
  }
  if (((*(byte *)(entityA + 0x124) & 0x20) == 0) && ((*(byte *)(entityB + 0x124) & 0x20) == 0)) {
    return 0;
  }
  return 1;
}




/* [AUDIT] proposed: CombatController::acquireNearbyTargets  (confidence: med)
 * purpose: Insert self into list then iterate entities; distance<8 (64.0=8^2) test, mark aggro/interest (0.5=0x3f000000)
 * vars: list node color at +0xd; pos at +0x10/0x18/0x20 fixed-pt (1/65536); _Xlength=list grow
 */
/* Global::CombatController_acquireNearbyTargets @ 005a0970 */

void CombatController_acquireNearbyTargets(int attacker,int target,int behavior)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int *node;
  undefined4 *puVar9;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int attacker_ptr;
  int *entity_list;
  int local_34;
  float local_30;
  float dx;
  float dy;
  float dz;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  attacker_ptr = attacker;
  local_4c = *(undefined4 *)(attacker + 8);
  puVar9 = (undefined4 *)(attacker + 8);
  local_48 = *(undefined4 *)(attacker + 0xc);
  local_54 = *(undefined4 *)(target + 8);
  local_50 = *(undefined4 *)(target + 0xc);
  puVar4 = (undefined4 *)rbtree_findOrInsert_pairKey(puVar9);
  local_44 = *puVar4;
  entity_list = (int *)(behavior + 0x50);
  iVar7 = *entity_list;
  iVar5 = map_insertVal_3x64payload(iVar7,*(undefined4 *)(iVar7 + 4),&local_54);
  if (entity_list[1] != 0x7fffffe) {
    entity_list[1] = entity_list[1] + 1;
    *(int *)(iVar7 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    node = (int *)**(int **)(local_34 + 4);
    iVar7 = local_34;
    if (node != *(int **)(local_34 + 4)) {
      do {
        iVar5 = node[6];
        if ((((iVar5 != 0) && (iVar5 != attacker_ptr)) && (iVar5 != target)) &&
           (cVar3 = CombatBehavior_isHostileTo(iVar5,attacker_ptr), iVar7 = local_34, cVar3 != '\0')) {
          iVar5 = node[6];
          local_20._0_4_ = (uint)*(undefined8 *)(iVar5 + 0x10);
          local_20._4_4_ = (int)((ulonglong)*(undefined8 *)(iVar5 + 0x10) >> 0x20);
          local_20 = CONCAT44((local_20._4_4_ - *(int *)(target + 0x14)) -
                              (uint)((uint)local_20 < *(uint *)(target + 0x10)),
                              (uint)local_20 - *(uint *)(target + 0x10));
          local_18._0_4_ = (uint)*(undefined8 *)(iVar5 + 0x18);
          local_18._4_4_ = (int)((ulonglong)*(undefined8 *)(iVar5 + 0x18) >> 0x20);
          local_18 = CONCAT44((local_18._4_4_ - *(int *)(target + 0x1c)) -
                              (uint)((uint)local_18 < *(uint *)(target + 0x18)),
                              (uint)local_18 - *(uint *)(target + 0x18));
          local_10._0_4_ = (uint)*(undefined8 *)(iVar5 + 0x20);
          local_10._4_4_ = (int)((ulonglong)*(undefined8 *)(iVar5 + 0x20) >> 0x20);
          local_10 = CONCAT44((local_10._4_4_ - *(int *)(target + 0x24)) -
                              (uint)((uint)local_10 < *(uint *)(target + 0x20)),
                              (uint)local_10 - *(uint *)(target + 0x20));
          dx = (float)local_20 * 1.5258789e-05;
          local_30 = (float)local_10;
          dy = (float)local_18 * 1.5258789e-05;
          dz = local_30 * 1.5258789e-05;
          if ((dy * dy + dx * dx + dz * dz < 64.0) &&
             (pfVar6 = (float *)rbtree_findOrInsert_pairKey(puVar9), iVar7 = local_34, *pfVar6 == 0.0)) {
            puVar4 = (undefined4 *)rbtree_findOrInsert_pairKey(puVar9);
            *puVar4 = 0x3f000000;
            local_64 = *puVar9;
            local_60 = *(undefined4 *)(attacker + 0xc);
            local_6c = *(undefined4 *)(node[6] + 8);
            local_68 = *(undefined4 *)(node[6] + 0xc);
            puVar4 = (undefined4 *)rbtree_findOrInsert_pairKey(puVar9);
            local_5c = *puVar4;
            list_pushBack_via451d00(&local_6c);
            iVar7 = local_34;
          }
        }
        if (*(char *)((int)node + 0xd) == '\0') {
          piVar1 = (int *)node[2];
          if (*(char *)((int)piVar1 + 0xd) == '\0') {
            cVar3 = *(char *)(*piVar1 + 0xd);
            node = piVar1;
            piVar1 = (int *)*piVar1;
            while (cVar3 == '\0') {
              cVar3 = *(char *)(*piVar1 + 0xd);
              node = piVar1;
              piVar1 = (int *)*piVar1;
            }
          }
          else {
            cVar3 = *(char *)(node[1] + 0xd);
            piVar2 = (int *)node[1];
            piVar1 = node;
            while ((node = piVar2, cVar3 == '\0' && (piVar1 == (int *)node[2]))) {
              cVar3 = *(char *)(node[1] + 0xd);
              piVar2 = (int *)node[1];
              piVar1 = node;
            }
          }
        }
      } while (node != *(int **)(iVar7 + 4));
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("list<T> too long");
}




